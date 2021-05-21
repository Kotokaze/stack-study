#include <stack.h>

int main()
{
	// セーフモードを無効にしてインスタンス生成
	Stack stk = Stack(false);

	// 書き込む要素数
	int num = 12;

	for (int i = 0; i < num; i++)
		stk.push(i + 1);

	stk.getData();

	for (int i = 0; i <= num; i++)
		printf("Popping %d (Ptr: %d)\n", stk.pop(), stk.getPtr());

	stk.getData();
}
