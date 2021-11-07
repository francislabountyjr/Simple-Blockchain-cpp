#pragma once

#include <cstdint>
#include <sstream>
#include <iostream>

using namespace std;

class Block
{
public:
	Block(uint32_t nIndexIn, const string& sDataIn);

	string sPrevHash;

	string& GetHash();

	void MineBlock(uint32_t nDifficulty);

	void PrintBlock();

private:
	uint32_t _nIndex;
	int64_t _nNonce;
	string _sData;
	string _sHash;
	time_t _tTime;

	string _CalculateHash() const;
};