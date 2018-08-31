/*
  Name: STLԴ������---vector
  Copyright: 
  Author: 
  Date: 15-03-17 14:18
  Description: 
*/
#include<iostream>  
#include<memory.h>  
  
using namespace std;  
  
// alloc��SGI STL�Ŀռ�������  
template <class T, class Alloc = alloc>  
class vector  
{  
public:  
    // vector��Ƕ�����Ͷ���,typedefs�����ṩiterator_traits<I>֧��  
    typedef T value_type;  
    typedef value_type* pointer;  
    typedef value_type* iterator;  
    typedef value_type& reference;  
    typedef size_t size_type;  
    typedef ptrdiff_t difference_type;  
protected:  
    // ����ṩSTL��׼��allocator�ӿ�  
    typedef simple_alloc <value_type, Alloc> data_allocator;  
  
    iterator start;               // ��ʾĿǰʹ�ÿռ��ͷ  
    iterator finish;              // ��ʾĿǰʹ�ÿռ��β  
    iterator end_of_storage;      // ��ʾʵ�ʷ����ڴ�ռ��β  
  
    void insert_aux(iterator position, const T& x);  
  
    // �ͷŷ�����ڴ�ռ�  
    void deallocate()  
    {  
        // ����ʹ�õ���data_allocator�����ڴ�ռ�ķ���,  
        // ������Ҫͬ��ʹ��data_allocator::deallocate()�����ͷ�  
        // ���ֱ���ͷ�, ����data_allocator�ڲ�ʹ���ڴ�صİ汾  
        // �ͻᷢ������  
        if (start)  
            data_allocator::deallocate(start, end_of_storage - start);  
    }  
  
    void fill_initialize(size_type n, const T& value)  
    {  
        start = allocate_and_fill(n, value);  
        finish = start + n;                         // ���õ�ǰʹ���ڴ�ռ�Ľ�����  
        // ����׶�, ��ʵ����������ڴ�,  
        // ����Ҫ�����ڴ�ռ�������, �Ѿ�ʹ�õ��ڴ�ռ��������ͬ  
        end_of_storage = finish;  
    }  
  
public:  
    // ��ȡ���ֵ�����  
    iterator begin() { return start; }  
    iterator end() { return finish; }  
  
    // ���ص�ǰ�������  
    size_type size() const { return size_type(end() - begin()); }  
    size_type max_size() const { return size_type(-1) / sizeof(T); }  
    // �������·����ڴ�ǰ����ܴ洢�Ķ������  
    size_type capacity() const { return size_type(end_of_storage - begin()); }  
    bool empty() const { return begin() == end(); }  
    reference operator[](size_type n) { return *(begin() + n); }  
  
    // ��ʵ����Ĭ�Ϲ������vector�������ڴ�ռ�  
    vector() : start(0), finish(0), end_of_storage(0) {}  
  
  
    vector(size_type n, const T& value) { fill_initialize(n, value); }  
    vector(int n, const T& value) { fill_initialize(n, value); }  
    vector(long n, const T& value) { fill_initialize(n, value); }  
  
    // ��Ҫ�����ṩĬ�Ϲ��캯��  
    explicit vector(size_type n) { fill_initialize(n, T()); }  
  
    vector(const vector<T, Alloc>& x)  
    {  
        start = allocate_and_copy(x.end() - x.begin(), x.begin(), x.end());  
        finish = start + (x.end() - x.begin());  
        end_of_storage = finish;  
    }  
  
    ~vector()  
    {  
        // ��������  
        destroy(start, finish);  
        // �ͷ��ڴ�  
        deallocate();  
    }  
  
    vector<T, Alloc>& operator=(const vector<T, Alloc>& x);  
  
    // �ṩ���ʺ���  
    reference front() { return *begin(); }  
    reference back() { return *(end() - 1); }  
  
    ////////////////////////////////////////////////////////////////////////////////  
    // ������β׷��һ��Ԫ��, ���ܵ����ڴ����·���  
    ////////////////////////////////////////////////////////////////////////////////  
    //                          push_back(const T& x)  
    //                                   |  
    //                                   |---------------- ��������?  
    //                                   |  
    //               ----------------------------  
    //           No  |                          |  Yes  
    //               |                          |  
    //               ��                          ��  
    //      construct(finish, x);       insert_aux(end(), x);  
    //      ++finish;                           |  
    //                                          |------ �ڴ治��, ���·���  
    //                                          |       ��СΪԭ����2��  
    //      new_finish = data_allocator::allocate(len);       <stl_alloc.h>  
    //      uninitialized_copy(start, position, new_start);   <stl_uninitialized.h>  
    //      construct(new_finish, x);                         <stl_construct.h>  
    //      ++new_finish;  
    //      uninitialized_copy(position, finish, new_finish); <stl_uninitialized.h>  
    ////////////////////////////////////////////////////////////////////////////////  
  
    void push_back(const T& x)  
    {  
        // �ڴ�����������ֱ��׷��Ԫ��, ������Ҫ���·����ڴ�ռ�  
        if (finish != end_of_storage)  
        {  
            construct(finish, x);  
            ++finish;  
        }  
        else  
            insert_aux(end(), x);  
    }  
  
  
    ////////////////////////////////////////////////////////////////////////////////  
    // ��ָ��λ�ò���Ԫ��  
    ////////////////////////////////////////////////////////////////////////////////  
    //                   insert(iterator position, const T& x)  
    //                                   |  
    //                                   |------------ �����Ƿ��㹻 && �Ƿ���end()?  
    //                                   |  
    //               -------------------------------------------  
    //            No |                                         | Yes  
    //               |                                         |  
    //               ��                                         ��  
    //    insert_aux(position, x);                  construct(finish, x);  
    //               |                              ++finish;  
    //               |-------- �����Ƿ���?  
    //               |  
    //        --------------------------------------------------  
    //    Yes |                                                | No  
    //        |                                                |  
    //        ��                                                |  
    // construct(finish, *(finish - 1));                       |  
    // ++finish;                                               |  
    // T x_copy = x;                                           |  
    // copy_backward(position, finish - 2, finish - 1);        |  
    // *position = x_copy;                                     |  
    //                                                         ��  
    // data_allocator::allocate(len);                       <stl_alloc.h>  
    // uninitialized_copy(start, position, new_start);      <stl_uninitialized.h>  
    // construct(new_finish, x);                            <stl_construct.h>  
    // ++new_finish;  
    // uninitialized_copy(position, finish, new_finish);    <stl_uninitialized.h>  
    // destroy(begin(), end());                             <stl_construct.h>  
    // deallocate();  
    ////////////////////////////////////////////////////////////////////////////////  
  
    iterator insert(iterator position, const T& x)  
    {  
        size_type n = position - begin();  
        if (finish != end_of_storage && position != end())  
        {  
            construct(finish, x);  
            ++finish;  
        }  
        else  
            insert_aux(position, x);  
        return begin() + n;  
    }  
  
    iterator insert(iterator position) { return insert(position, T()); }  
  
    void pop_back()  
    {  
        --finish;  
        destroy(finish);  
    }  
  
    iterator erase(iterator position)  
    {  
        if (position + 1 != end())  
            copy(position + 1, finish, position);  
        --finish;  
        destroy(finish);  
        return position;  
    }  
  
  
    iterator erase(iterator first, iterator last)  
    {  
        iterator i = copy(last, finish, first);  
        // ��������Ҫ������Ԫ��  
        destroy(i, finish);  
        finish = finish - (last - first);  
        return first;  
    }  
  
    // ����size, ���ǲ��������·����ڴ�ռ�  
    void resize(size_type new_size, const T& x)  
    {  
        if (new_size < size())  
            erase(begin() + new_size, end());  
        else  
            insert(end(), new_size - size(), x);  
    }  
    void resize(size_type new_size) { resize(new_size, T()); }  
  
    void clear() { erase(begin(), end()); }  
  
protected:  
    // ����ռ�, ���Ҹ��ƶ��󵽷���Ŀռ䴦  
    iterator allocate_and_fill(size_type n, const T& x)  
    {  
        iterator result = data_allocator::allocate(n);  
        uninitialized_fill_n(result, n, x);  
        return result;  
    }  
  
    // �ṩ�������  
    ////////////////////////////////////////////////////////////////////////////////  
    //                 insert_aux(iterator position, const T& x)  
    //                                   |  
    //                                   |---------------- �����Ƿ��㹻?  
    //                                   ��  
    //              -----------------------------------------  
    //        Yes   |                                       | No  
    //              |                                       |  
    //              ��                                       |  
    // ��opsition��ʼ, ��������ƶ�һ��λ��                     |  
    // construct(finish, *(finish - 1));                    |  
    // ++finish;                                            |  
    // T x_copy = x;                                        |  
    // copy_backward(position, finish - 2, finish - 1);     |  
    // *position = x_copy;                                  |  
    //                                                      ��  
    //                            data_allocator::allocate(len);  
    //                            uninitialized_copy(start, position, new_start);  
    //                            construct(new_finish, x);  
    //                            ++new_finish;  
    //                            uninitialized_copy(position, finish, new_finish);  
    //                            destroy(begin(), end());  
    //                            deallocate();  
    ////////////////////////////////////////////////////////////////////////////////  
  
    template <class T, class Alloc>  
    void insert_aux(iterator position, const T& x)  
    {  
        if (finish != end_of_storage)    // ���б��ÿռ�  
        {  
            // �ڱ��ÿռ���ʼ������һ��Ԫ�أ�����vector���һ��Ԫ��ֵΪ���ֵ  
            construct(finish, *(finish - 1));  
            ++finish;  
            T x_copy = x;  
            copy_backward(position, finish - 2, finish - 1);  
            *position = x_copy;  
        }  
        else   // ���ޱ��ÿռ�  
        {  
            const size_type old_size = size();  
            const size_type len = old_size != 0 ? 2 * old_size : 1;  
            // ��������Ԫ�أ������СΪ0��������1����Ԫ�ش�С��  
            // �����С��Ϊ0��������ԭ����С������  
            // ǰ�����������ԭ���ݣ�����׼����������������  
  
            iterator new_start = data_allocator::allocate(len);  // ʵ������  
            iterator new_finish = new_start;  
            // ���ڴ���������  
            try  
            {  
                // ��ԭvector�İ������ǰ�����ݿ�������vector  
                new_finish = uninitialized_copy(start, position, new_start);  
                // Ϊ��Ԫ���趨��ֵ x  
                construct(new_finish, x);  
                // ����ˮλ  
                ++new_finish;  
                // ��������Ժ��ԭ����Ҳ��������  
                new_finish = uninitialized_copy(position, finish, new_finish);  
            }  
            catch(...)  
            {  
                // �ع�����  
                destroy(new_start, new_finish);  
                data_allocator::deallocate(new_start, len);  
                throw;  
            }  
            // �������ͷ�ԭvector  
            destroy(begin(), end());  
            deallocate();  
  
            // ������������ָ����vector  
            start = new_start;  
            finish = new_finish;  
            end_of_storage = new_start + len;  
        }  
    }  
  
    ////////////////////////////////////////////////////////////////////////////////  
    // ��ָ��λ�ò���n��Ԫ��  
    ////////////////////////////////////////////////////////////////////////////////  
    //             insert(iterator position, size_type n, const T& x)  
    //                                   |  
    //                                   |---------------- ����Ԫ�ظ����Ƿ�Ϊ0?  
    //                                   ��  
    //              -----------------------------------------  
    //        No    |                                       | Yes  
    //              |                                       |  
    //              |                                       ��  
    //              |                                    return;  
    //              |----------- �ڴ��Ƿ��㹻?  
    //              |  
    //      -------------------------------------------------  
    //  Yes |                                               | No  
    //      |                                               |  
    //      |------ (finish - position) > n?                |  
    //      |       �ֱ����ָ��                              |  
    //      ��                                               |  
    //    ----------------------------                      |  
    // No |                          | Yes                  |  
    //    |                          |                      |  
    //    ��                          ��                      |  
    // �������, ����ָ��           �������, ����ָ��           |  
    //                                                      ��  
    //            data_allocator::allocate(len);  
    //            new_finish = uninitialized_copy(start, position, new_start);  
    //            new_finish = uninitialized_fill_n(new_finish, n, x);  
    //            new_finish = uninitialized_copy(position, finish, new_finish);  
    //            destroy(start, finish);  
    //            deallocate();  
    ////////////////////////////////////////////////////////////////////////////////  
  
    template <class T, class Alloc>  
    void insert(iterator position, size_type n, const T& x)  
    {  
        // ���nΪ0�򲻽����κβ���  
        if (n != 0)  
        {  
            if (size_type(end_of_storage - finish) >= n)  
            {      // ʣ�µı��ÿռ���ڵ��ڡ�����Ԫ�صĸ�����  
                T x_copy = x;  
                // ���¼�������֮�������Ԫ�ظ���  
                const size_type elems_after = finish - position;  
                iterator old_finish = finish;  
                if (elems_after > n)  
                {  
                    // �����֮�������Ԫ�ظ��� ���� ����Ԫ�ظ���  
                    uninitialized_copy(finish - n, finish, finish);  
                    finish += n;    // ��vector β�˱�Ǻ���  
                    copy_backward(position, old_finish - n, old_finish);  
                    fill(position, position + n, x_copy); // �Ӳ���㿪ʼ������ֵ  
                }  
                else  
                {  
                    // �����֮�������Ԫ�ظ��� С�ڵ��� ����Ԫ�ظ���  
                    uninitialized_fill_n(finish, n - elems_after, x_copy);  
                    finish += n - elems_after;  
                    uninitialized_copy(position, old_finish, finish);  
                    finish += elems_after;  
                    fill(position, old_finish, x_copy);  
                }  
            }  
            else  
            {   // ʣ�µı��ÿռ�С�ڡ�����Ԫ�ظ��������Ǿͱ������ö�����ڴ棩  
                // ���Ⱦ����³��ȣ��ͳ��ȵ����� �� ��ɳ���+����Ԫ�ظ���  
                const size_type old_size = size();  
                const size_type len = old_size + max(old_size, n);  
                // ���������µ�vector�ռ�  
                iterator new_start = data_allocator::allocate(len);  
                iterator new_finish = new_start;  
                __STL_TRY  
                {  
                    // �������Ƚ��ɵ�vector�Ĳ����֮ǰ��Ԫ�ظ��Ƶ��¿ռ�  
                    new_finish = uninitialized_copy(start, position, new_start);  
                    // �����ٽ�����Ԫ�أ���ֵ��Ϊn�������¿ռ�  
                    new_finish = uninitialized_fill_n(new_finish, n, x);  
                    // �����ٽ���vector�Ĳ����֮���Ԫ�ظ��Ƶ��¿ռ�  
                    new_finish = uninitialized_copy(position, finish, new_finish);  
                }  
#         ifdef  __STL_USE_EXCEPTIONS  
                catch(...)  
                {  
                    destroy(new_start, new_finish);  
                    data_allocator::deallocate(new_start, len);  
                    throw;  
                }  
#         endif /* __STL_USE_EXCEPTIONS */  
                destroy(start, finish);  
                deallocate();  
                start = new_start;  
                finish = new_finish;  
                end_of_storage = new_start + len;  
            }  
        }  
    }  
};  
