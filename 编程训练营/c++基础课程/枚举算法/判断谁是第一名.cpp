/*
	Name: �ж�˭�ǵ�һ��
	Copyright: 
	Author: 
	Date: 19-08-18 11:25
	Description: �мף��ң����������˲μӾ�������һ�˵õ�һ��������˭�õ�һ��ʱ��
��˵�����Ҳ��ǵ�һ�� �����ǵ�һ�� ������˵�����Ҳ��ǵ�һ����
���ǵ�һ��������˵�����ײ��ǵ�һ�������ǵ�һ��������˵�����Ҳ��ǵ�һ������
  ���Ǹ�����˵�Ĳ���ȫ�ԣ�����ȫ����̷ֱ���A��B��C��D����ף��ң����������ˣ� ��A1��B1��C1��D1����ף��ң�������������˵�Ļ���
  �ж�˭�ǵ�һ����
*/

#include<iostream>
#include<cstdio>

using namespace std;

int main()
{

    int A,B,C,D,i=0;
    int A1,B1,C1,D1;
    
    for(A=1;A<=4;A++)
      for(B=1;B<=4;B++)
        for(C=1;C<=4;C++)
          for(D=1;D<=4;D++)
            {
                A1=(B!=1&&(D==1))||((B==1)&&D!=1);
                B1=(B!=1&&(C==1))||((B==1)&&C!=1);
                C1=(A!=1&&(B==1))||((A==1)&&B!=1);
                D1=(D==1)||(D!=1);
                
                if(A!=B&&A!=C&&A!=D && B!=C&&B!=D && C!=D && A1&&B1&&C1&&D1)
                {
                    printf("A=%d,B=%d,C=%d,D=%d\n",A,B,C,D);
                    if(A==1)
                         printf("The number is A\n");
                    else if(B==1)
                         printf("The number is B\n");
                    else if(C==1)
                         printf("The number is C\n");
                    else
                         printf("The number is D\n");
                }    

            }
     
      return 0;               
}                  
