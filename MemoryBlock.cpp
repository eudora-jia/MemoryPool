#include "MemoryBlock.h"

MemoryBlock::MemoryBlock(const int  initblock, const int unitSize)
	:prev(nullptr),
	next(nullptr),
	mSize(initblock* (unitSize+2)),
	free(initblock - 1),
	first(1)
{
//    memset(mPad, 0, mSize - 20);
    /// 有两个字节的内存没有使用
    memset(mPad, 0, mSize+2);
	char* padData = mPad;
	for (int i = 1; i< initblock;i++)
	{
		*reinterpret_cast<USHORT*>(padData) = i;
		padData += (unitSize+2);
	}
}

void* MemoryBlock::operator new(size_t, const int initBlock, const int unitSize)
{
	return ::operator new(sizeof(MemoryBlock) + initBlock* (unitSize+2));
}
void MemoryBlock::operator delete(void* p)
{
	::operator delete(p);
}
