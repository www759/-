//MaxHeap Creat(int MaxSize);创建一个最大堆
//Bool IsFull(MaxHeap H);判断最大堆是否已满
//Insert(MaxHeap H,ElementType X);
//Bool IsEmpty(MaxHeap H);
//ElementType DeleteMax(MaxHeap H);
#include<cstdlib>
#include<cstdio>
const int MAXDATA = 10000;
typedef int ElementType;
typedef struct MaxHeapNode* MaxHeap;
struct MaxHeapNode {
	ElementType* data;
	int size;
	int maxsize;
};
MaxHeap Creat(int MaxSize) {
	MaxHeap H = (MaxHeap)malloc(sizeof(struct MaxHeapNode));
	H->maxsize = MaxSize;
	H->data = (ElementType*)malloc((MaxSize + 1) * sizeof(ElementType));
	H->size = 0;
	H->data[0] = MAXDATA;
	return H;
}
bool IsFull(MaxHeap H) {
	if (H->size == H->maxsize)	return true;
	else return false;
}
bool IsEmpty(MaxHeap H) {
	if (H->size == 0)	return true;
	else return false;
}
//最大堆的插入
//将新元素置于最后位置，再从下向上调整
//若满则返回，否则将元素置于最后位置，从下向上与其父亲节点比较，如果父亲节点的值比X小，则将父亲变为儿子
//直至父亲节点的大于儿子，将这个儿子的值记为X
void Insert(MaxHeap H, ElementType X) {
	if (IsFull(H)) {
		printf("H已满，不可插入");
		return;
	}
	/*H->data[++H->size] = X;
	int parent,child;
	for (parent=H->size/2; parent >= 1; parent /= 2) {
		child = parent * 2;
		if (H->data[parent] < X) {
			H->data[child] = H->data[parent];
		}
		else break;
	}
	H->data[parent] = X;*/
	int i = ++H->size;
	for (; H->data[i/2] < X; i/=2) {
		H->data[i] = H->data[i / 2];
	}
	H->data[i] = X;
}
//最大堆的删除
//将最大堆的最大元素即根节点取出，用最后一个元素替换，最后从上向下调整,如果遇到比最后一个节点小的，就停止
ElementType DeleteMax(MaxHeap H) {
	if (IsEmpty(H)) {
		return H->data[0];
	}
	ElementType result = H->data[1];
	int parent, child;
	ElementType temp = H->data[H->size--];
	for (parent = 1; child <= H->size; parent=child/2) {
		child = parent * 2;
		if (child < H->size&&H->data[child] < H->data[child + 1]) {
			child = child + 1;
		}
		if (H->data[child] > temp) {
			H->data[parent] = H->data[child];
		}
		else {
			break;//注意
		}
	}
	H->data[parent] = temp;//注意
	return result;
}
//将一组数据构建为最大堆
//1. 现将数据按输入顺序存入最大堆数组中
//2. 从size/2位置开始到根节点，对每一个节点进行向下调整
//向下调整的代码再删除操作中已经出现
//本函数假设已经做完第一步
MaxHeap CreatMaxHeap(MaxHeap H) {
	if (IsEmpty(H))	return H;
	int parent, child;
	ElementType temp;
	for (int i = H->size / 2; i >= 1; i-- ) {
		temp = H->data[i];
		for (parent = H->data[i]; parent*2<= H->size; parent = child) {
			child = parent * 2;
			if (H->data[child] < H->data[child + 1]) {
				child = child + 1;
			}
			if (temp > H->data[child]) {
				H->data[parent] = H->data[child];
			}
			else {
				break;
			}
		}
		H->data[parent] = temp;
	}
	return H;
}







