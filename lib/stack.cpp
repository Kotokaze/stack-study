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
Stack::Stack(const bool flag, const int heep_size)
{
  this->ptr = 0;
  this->strict = flag;
  this->tail = heep_size - 1;
  this->data0 = new int[this->tail];
  this->data1 = new int[this->tail];

  for (int i = 0; i <= this->tail; i++)
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
 * @brief data0 のポインタを取得
 *
 * @return int ポインタ
 */
int
Stack::getPtr()
{
  return this->ptr;
}

/**
 * @brief data01 に push
 *
 * @param[in] int 追加するアイテム
 */
void
Stack::push(int item)
{
  int crr = getPtr();
  printf("Pusshing %d to (Ptr: %d)\n", item, crr);

  if ((this->tail < crr) && (this->strict))
  {
    printf(">> WORNING: Heep overflow protection\n");
    return;
  }

  this->data0[crr] = item;
  ++this->ptr;
}

/**
 * @brief 最上位の値を取り出す
 *
 * @return TOPの値
 */
int
Stack::pop()
{
  int crr = getPtr();
  int tmp = crr - 1;

  if ((tmp < 0) && (this->strict))
  {
    printf(">> WORNING: Heep underflow protection\n");
    return NULL;
  }

  --this->ptr;
  int val = this->data0[crr];
  this->data0[crr] = 0;
  return val;
}

/**
 * @brief 配列の状況を確認
 */
void
Stack::getData()
{
  int index0 = sizeof(this->data0) - 1;
  int index1 = sizeof(this->data1) - 1;

  printf("\n[Data0(%p)]\t", &this->data0[0]);
  for (int i = 0; i <= index0; i++)
    printf("%d\t", this->data0[i]);

  printf("\n[Data1(%p)]\t", &this->data1[0]);
  for (int i = 0; i <= index1; i++)
    printf("%d\t", this->data1[i]);

  printf("\n\n");
}
