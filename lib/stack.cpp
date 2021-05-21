/**
 * @file stack.h
 *
 * @brief ヒープ・オーバーランの再現用
 * @author Kotokaze
 * @date 2021/05/21
 */
#include <stack.h>

/**
 * @brief コンストラクタ
 *
 * @param[in] bool 安全モード有効 (デフォルト値: true)
 * @param[in] int ヒープ領域のサイズ (デフォルト値: 8)
 */
Stack::Stack(const bool flag, const int heep)
{
	this->ptr = 0;
	this->strict = flag;
	this->heep_size = heep;
	this->data0 = new int[this->heep_size];
	this->data1 = new int[this->heep_size];

	for (int i = 0; i <= this->heep_size; i++)
		this->data1[i] = 3;
}


/**
 * @brief デストラクタ
 */
Stack::~Stack()
{
	delete[] (this->data0);
	delete[] (this->data1);
}

/**
 * @brief data0 のポインタの位置を取得
 *
 * @return int ポインタの位置
 */
int Stack::getPtr()
{
	return this->ptr;
}


/**
 * @brief data01 に push
 *
 * @param[in] int 追加するアイテム
 */
void Stack::push(int item)
{
	int tmp = this->getPtr();
	printf("Pusshing %d (Ptr: %d)\n", item, tmp);

	if ((this->heep_size <= tmp) && (this->strict))
	{
		printf(">> WORNING: Heep overflow protection (Ptr: %d)\n", tmp);
		return;
	}

	this->data0[tmp] = item;
	++this->ptr;
}


/**
 * @brief 最上位の値を取り出す
 *
 * @return TOPの値
 */
int Stack::pop()
{
	int tmp = this->getPtr();

	if ((tmp <= 0) && (this->strict))
	{
		printf(">> WORNING: Heep underflow protection (Ptr: %d)\n", tmp);
		return NULL;
	}

	--this->ptr;
	tmp = this->getPtr();
	int val = this->data0[tmp];
	this->data0[tmp] = NULL;
	return val;
}

/**
 * @brief 配列の状況を確認
 */
void Stack::getData()
{
	int index0 = sizeof(this->data0) - 1;
	int index1 = sizeof(this->data1) - 1;

	printf("\n[Data0(%p)] ", &this->data0[0]);
	for (int i = 0; i <= index0; i++)
		printf("%d\t", this->data0[i]);

	printf("\n[Data1(%p)] ", &this->data1[0]);
	for (int i = 0; i <= index1; i++)
		printf("%d\t", this->data1[i]);

	printf("\n\n");
}
