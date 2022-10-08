#include <stdio.h>  //stdio 라이브러리
#include <string.h> //string 라이브러리
#include <stdlib.h> //stdlib 라이브러리

typedef struct student{ //student 구조체
    char name[21];  //공백없이 최대 길이 20
    int kor, eng, math;    //국영수 성적
    double avg;      //세 과목의 평균 점수
}st;

void read_data(st *ptr, int n);
void sort_score(st *ptr, int n);
st *select_out(st *ptr1, st *ptr2, int n);

int main()
{  
    st s1[49], s2[49], *res, *p;
    int n, i;
    scanf("%d", &n);
    getchar();

    read_data(s1, n);
    read_data(s2, n);

    sort_score(s1, n);
    sort_score(s2, n);

    res = select_out(s1, s2, n);

    for(p=res; p<res+n; p++){
        printf("%s %d %d %d %.1lf\n", p->name, p->kor, p->eng, p->math, p->avg);
    }

    
    return 0;
}
void read_data(st *ptr, int n){
    st *p;
    for(p=ptr; p<ptr+n; p++){
        scanf("%s", p->name);
        scanf("%d %d %d", &p->kor, &p->eng, &p->math);
        getchar();
        p->avg = (p->kor + p->eng + p->math) / 3.0;
    }
}
void sort_score(st *ptr, int n){
    st *p, tmp;
    int i;
    for(i=0; i<n-1; i++){
        for(p=ptr; p<ptr+n-1; p++){
            if(p->avg < (p+1)->avg){
                tmp = *p;
                *p = *(p+1);
                *(p+1) = tmp;
            }
            else if (p->avg == (p+1)->avg){
                if(p->kor < (p+1)->kor){
                    tmp = *p;
                    *p = *(p+1);
                    *(p+1) = tmp;
                }
                else if(p->eng < (p+1)->eng){
                    tmp = *p;
                    *p = *(p+1);
                    *(p+1) = tmp;
                }
            }
        }
    }
}
st *select_out(st *ptr1, st *ptr2, int n){
    double n1 = (ptr1 + n/2)->avg;
    double n2 = (ptr2 + n/2)->avg;

    if(n1 >= n2) return ptr1;
    else    return ptr2;
}
