#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>

using namespace std;

void Swap(int &x,int &y)
{
    int temp;
    temp=x;
    x=y;
    y=temp;
}
void  BubbleSort(int n,int *num)//ð��
{
    int i,j;
    for(i=0; i<=n-1; i++)
    {
        for(j=n-1; j>=i+1; j--)
        {
            if(num[j]<num[j-1])
            {
                Swap(num[j],num[j-1]);
            }
        }
    }

}
int FindPivot(int *num,int i,int j)//��׼Ԫ�ص�ѡȡ
{
    int firstkey=num[i];
    int k;
    for(k=i+1; k<=j; k++)
    {
        if(num[k]>firstkey)
            return k;
        else if(num[k]<firstkey)
            return i;

    }
    return -1;
}
int Partition(int *num,int i,int j,int pivot)//����������
{
    int l,r;

    do
    {
        for(l=i; num[l]<pivot; l++);
        for(r=j; num[r]>=pivot; r--);
        if(l<r)
            Swap(num[l],num[r]);
    }
    while(l<=r);
    return l;
}
void  QuickSort(int *num,int i,int j)//����
{
    int pivot;
    int k;
    int pivotindex;
    pivotindex=FindPivot(num,i,j);
    if(pivotindex!=-1)
    {
        pivot=num[pivotindex];
        k=Partition(num,i,j,pivot);
        QuickSort(num,i,k-1);
        QuickSort(num,k,j);
    }
}
void SelectSort(int n,int *num)//ѡ������
{
    int lowkey;//��ǰ��С�ؼ���
    int i,j,lowindex;//��ǰ��С�ؼ����±�
    for(i=0; i<n; i++)
    {
        lowindex=i;
        lowkey=num[i];
        for(j=i+1; j<n; j++) //��������ѡ����С�Ĺؼ��֣���num[i]����
        {
            if(num[j]<lowkey)//�õ�ǰ��С�ؼ�����ÿ���ؼ��ֱȽ�
            {
                lowkey=num[j];
                lowindex=j;
            }
        }
        if(i!=lowindex)
            Swap(num[i],num[lowindex]);
    }
}
void PushDown(int *num,int first,int last)
{
    int r=first;
    while(r<=last/2)
    {

        if((r==last/2)&&(last%2==0))
        {
            if(num[r]>num[2*r])
                Swap(num[r],num[2*r]);
            r=last;
        }
        else if((num[r]>num[2*r])&&(num[2*r]<=num[2*r+1]))
        {
            Swap(num[r],num[2*r]);
            r=2*r;
        }
        else if((num[r]>num[2*r+1])&&(num[2*r]>num[2*r+1]))
        {
            Swap(num[r],num[2*r+1]);
            r=2*r+1;
        }
        else
            r=last;
    }
}
void HeapSort(int n,int *num)
{
    int i;
    for(i=n/2; i>=1; i--) //��ʼ���ѣ������ҷ�Ҷ�ڵ㿪ʼ
        PushDown(num,i,n);//����ѣ�����iΪ��������±��ҶΪn
    for(i=n; i>=2; i--)
    {
        Swap(num[1],num[i]);//�Ѷ��뵱ǰ���е��±�����Ҷ�ڵ㽻��
        PushDown(num,1,i-1);//����Ѱ���1Ϊ�������Ҷ�±�Ϊi-1����ȫ��Ԫ������ɶ�
    }
}
void menu()
{
    printf("1.ð�������������������˳������\n");
    printf("2.ð�������������������������\n");
    printf("3.ð��������������������������\n");
    printf("4.ѡ������Ͷ���������˳������\n");
    printf("5.ѡ������Ͷ���������������\n");
    printf("6.ѡ������Ͷ����������������\n");
}
int main()
{
    int n,i,choice;
    printf("�����������С��\n");
    scanf("%d",&n);
    int *num=(int *)malloc(sizeof(int)*n);
    int *test1=(int *)malloc(sizeof(int)*n);
    int *test2=(int *)malloc(sizeof(int)*(n+1));
    int *test3=(int *)malloc(sizeof(int)*n);
    int *num1=(int *)malloc(sizeof(int)*n);
    int *test4=(int *)malloc(sizeof(int)*n);
    int *test5=(int *)malloc(sizeof(int)*(n+1));
    int *test6=(int *)malloc(sizeof(int)*n);
    int *num2=(int *)malloc(sizeof(int)*n);
    int *test7=(int *)malloc(sizeof(int)*n);
    int *test8=(int *)malloc(sizeof(int)*(n+1));
    int *test9=(int *)malloc(sizeof(int)*n);
    srand((unsigned)time(NULL));
    for(i=0; i<n; i++)
    {
        num1[i]=i;
        test4[i]=i;
        test6[i]=i;
        test5[i+1]=i;
    }
//    printf("˳���������£�\n");
//    for(i=0; i<n; i++)
//    {
//        printf("%d\t",num1[i]);
//    }
    printf("\n");
    for(i=0; i<n; i++)
    {
        num2[i]=n-i-1;
        test7[i]=num2[i];
        test9[i]=num2[i];
        test8[i+1]=num2[i];
    }
//    printf("�����������£�\n");
//    for(i=0; i<n; i++)
//    {
//        printf("%d\t",num2[i]);
//    }
    printf("\n");
    for(i=0; i<n; i++)
    {
        num[i]=rand()%n+10;
        test1[i]=num[i];
        test3[i]=num[i];
        test2[i+1]=num[i];
    }
//    printf("δ��������������£�\n");
//    for(i=0; i<n; i++)
//    {
//        printf("%d\t",num[i]);
//    }
    printf("\n");
    DWORD start_time1;
    DWORD start_time2;
    DWORD end_time1;
    DWORD end_time2;
    while(1)
    {
        start_time1=0;
        start_time2=0;
        end_time1=0;
        end_time2=0;
        menu();
        scanf("%d",&choice);
        switch(choice)
        {
        case 1:
            start_time1=GetTickCount();
            BubbleSort(n,test4);
            end_time1=GetTickCount();
//            for(i=0; i<n; i++)
//            {
//                printf("%d\t",test4[i]);
//            }
            printf("\n");
            start_time2=GetTickCount();
            QuickSort(num1,0,n-1);
            end_time2=GetTickCount();
//            for(i=0; i<n; i++)
//            {
//                printf("%d\t",num1[i]);
//            }
            printf("\nð�����򾭹���ʱ��Ϊ��%d\n",(end_time1-start_time1));
            printf("�������򾭹���ʱ��Ϊ��%d\n",(end_time2-start_time2));
            break;
        case 2:
            start_time1=GetTickCount();
            BubbleSort(n,test7);
            end_time1=GetTickCount();
//            for(i=0; i<n; i++)
//            {
//                printf("%d\t",test7[i]);
//            }
            printf("\n");
            start_time2=GetTickCount();
            QuickSort(num2,0,n-1);
            end_time2=GetTickCount();
//            for(i=0; i<n; i++)
//            {
//                printf("%d\t",num2[i]);
//            }
            printf("\nð�����򾭹���ʱ��Ϊ��%d\n",(end_time1-start_time1));
            printf("�������򾭹���ʱ��Ϊ��%d\n",(end_time2-start_time2));
            break;
        case 3:
            start_time1=GetTickCount();
            BubbleSort(n,test1);
            end_time1=GetTickCount();
//            for(i=0; i<n; i++)
//            {
//                printf("%d\t",test1[i]);
//            }
            printf("\n");
            start_time2=GetTickCount();
            QuickSort(num,0,n-1);
            end_time2=GetTickCount();
//            for(i=0; i<n; i++)
//            {
//                printf("%d\t",num[i]);
//            }
            printf("\nð�����򾭹���ʱ��Ϊ��%d\n",(end_time1-start_time1));
            printf("�������򾭹���ʱ��Ϊ��%d\n",(end_time2-start_time2));
            break;
        case 4:
            start_time1=GetTickCount();
            HeapSort(n,test5);
            end_time1=GetTickCount();
//            for(i=1; i<=n; i++)
//            {
//                printf("%d\t",test5[n-i+1]);
//            }
            printf("\n");
            start_time2=GetTickCount();
            SelectSort(n,test6);
            end_time2=GetTickCount();
//            for(i=0; i<n; i++)
//            {
//                printf("%d\t",test6[i]);
//            }
            printf("\n");
            printf("\n�����򾭹���ʱ��Ϊ��%d\n",(end_time1-start_time1));
            printf("ѡ�����򾭹���ʱ��Ϊ��%d\n",(end_time2-start_time2));
            break;
        case 5:
            start_time1=GetTickCount();
            HeapSort(n,test8);
            end_time1=GetTickCount();
//            for(i=1; i<=n; i++)
//            {
//                printf("%d\t",test8[n-i+1]);
//            }
            printf("\n");
            start_time2=GetTickCount();
            SelectSort(n,test9);
            end_time2=GetTickCount();
//            for(i=0; i<n; i++)
//            {
//                printf("%d\t",test9[i]);
//            }
            printf("\n�����򾭹���ʱ��Ϊ��%d\n",(end_time1-start_time1));
            printf("ѡ�����򾭹���ʱ��Ϊ��%d\n",(end_time2-start_time2));
            break;
        case 6:
            start_time1=GetTickCount();
            HeapSort(n,test2);
            end_time1=GetTickCount();
//            for(i=1; i<=n; i++)
//            {
//                printf("%d\t",test2[n-i+1]);
//            }
            printf("\n");
            start_time2=GetTickCount();
            SelectSort(n,test3);
            end_time2=GetTickCount();
//            for(i=0; i<n; i++)
//            {
//                printf("%d\t",test3[i]);
//            }
            printf("\n�����򾭹���ʱ��Ϊ��%d\n",(end_time1-start_time1));
            printf("ѡ�����򾭹���ʱ��Ϊ��%d\n",(end_time2-start_time2));
            break;
        default:
            printf("�����������������");
        }
    }


    free(num);
    free(num1);
    free(num2);
    free(test1);
    free(test2);
    free(test3);
    free(test4);
    free(test5);
    free(test6);
    free(test7);
    free(test8);
    free(test9);
    return 0;
}
