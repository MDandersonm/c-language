
/*

1. 최선의 경우 (Best Case)
퀵정렬의 최선의 경우는 피벗이 항상 데이터를 균등하게 두 부분으로 나눌 때 발생합니다. 이 경우, 퀵정렬은 각 단계에서 리스트를 두 동일한 크기의 부분 리스트로 분할하므로, 이진 트리처럼 분할됩니다. 이렇게 분할하는 데는 각 레벨에서
𝑂(𝑛)
O(n)의 시간이 소요되며, 트리의 깊이는
𝑂(log⁡𝑛)
O(logn)입니다. 따라서 최선의 경우의 시간 복잡도는:
𝑂(𝑛log⁡𝑛)


2. 평균적인 경우 (Average Case)
평균적인 경우에도 퀵정렬은
𝑂(𝑛log𝑛)
O(nlogn)의 시간 복잡도를 가집니다. 
피벗이 데이터를 완벽하게 균등하게 나누지 않더라도, 
대체로 균등하게 나누는 경향이 있기 때문입니다. 
이는 평균적으로도 효율적인 성능을 나타내는 이유입니다.

3. 최악의 경우 (Worst Case)
퀵정렬의 최악의 경우는 피벗이 매번 최소값이나 최대값으로 선택될 때 발생합니다. 
이 경우, 퀵정렬은 한쪽은 0개, 다른 한쪽은 n−1개의 원소로 분할하게 되므로, 이진 분할이 아닌 선형 분할이 되어버립니다. 
이렇게 되면, 각 레벨마다𝑂(𝑛)
O(n)의 작업이 필요하고, 레벨은 n개까지 증가할 수 있습니다.
따라서 최악의 경우의 시간 복잡도는:

𝑂(𝑛^2)

*/
#include <stdio.h>

int size, i = 0;


//부분집합 안에서 피봇의 위치를 찾아 확정하는 연산
int partition(int list[], int begin, int end) {//0 7
    if (begin == 0 && end == 0) {
        return;
    }
    int p;
    p = (begin + end) / 2;
    //printf("pivot index: %d \n", p);
    //printf("list[p]: %d \n", list[p]);
    int l = begin;
    int r = end;
    while (l < r) {
        //printf("와일문진입\n");
        while (l < r && list[l] < list[p]) {//피벗까지만 이동함
            l++;
        }
        while (l < r && list[p] <= list[r]) { //피벗을 지나 왼쪽으로 이동가능
            r--;
        }
        //printf("l: %d\n", l);
        //printf("list[l]: %d\n",list[l]);
        //printf("r: %d\n", r);
        //printf("list[r]: %d\n", list[r]);
        if (l == r) {//l과 r이 만났을때 r과 피벗과 교환           //= 로 썼을때 에러가 안나는구나.
            //printf("l과 r이 만남\n");
            int pivotValue = list[p];
            list[p] = list[r];
            list[r] = pivotValue;
            break;
        }
        else {//l와 r가 만나지 않았을때 둘이 자리교환
            int temp = list[l];
            list[l] = list[r];
            list[r] = temp;
        }
    }
    //printf("새로운 피봇인덱스 : %d \n\n", r);
    return r;//새로이 피벗이 된 인덱스

}

void quickSort(int list[], int begin, int end) {
    int p;
    if (begin < end) {
        p = partition(list, begin, end);
        quickSort(list, begin, p - 1);
        quickSort(list, p + 1, end);
    }

}

int main0260() {

    size = 8;

    int list[8] = { 69,10,30,2,16,8,31,22 };
    printf("\n퀵정렬할 배열:  ");
    for (int i = 0; i < size; i++) {
        printf("%d ", list[i]);
    }
    printf("\n");

    quickSort(list, 0, size - 1);

    printf("\n퀵정렬 후  배열:  ");
    for (int i = 0; i < size; i++) {
        printf("%d ", list[i]);
    }
    printf("\n");



    return 0;
}
