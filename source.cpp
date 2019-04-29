//MaxHeap Creat(int MaxSize);����һ������
//Bool IsFull(MaxHeap H);�ж������Ƿ�����
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
//���ѵĲ���
//����Ԫ���������λ�ã��ٴ������ϵ���
//�����򷵻أ�����Ԫ���������λ�ã������������丸�׽ڵ�Ƚϣ�������׽ڵ��ֵ��XС���򽫸��ױ�Ϊ����
//ֱ�����׽ڵ�Ĵ��ڶ��ӣ���������ӵ�ֵ��ΪX
void Insert(MaxHeap H, ElementType X) {
	if (IsFull(H)) {
		printf("H���������ɲ���");
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
//���ѵ�ɾ��
//�����ѵ����Ԫ�ؼ����ڵ�ȡ���������һ��Ԫ���滻�����������µ���,������������һ���ڵ�С�ģ���ֹͣ
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
			break;//ע��
		}
	}
	H->data[parent] = temp;//ע��
	return result;
}








