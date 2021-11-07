#include "Block.hpp"
#include "Sha256.hpp"

Block::Block(uint32_t nIndexIn, const string& sDataIn)
{
    _nNonce = -1;
    _nIndex = nIndexIn;
    _tTime = time(nullptr);
    _sData = sDataIn;
    _sHash = _CalculateHash();
}

string& Block::GetHash()
{
    return _sHash;
}

void Block::MineBlock(uint32_t nDifficulty)
{
    string str(nDifficulty, '0');

    do
    {
        _nNonce++;
        _sHash = _CalculateHash();

        cout << "Current Hash: " << _sHash << "\r";
    } while (_sHash.substr(0, nDifficulty) != str);

    cout << "Block mined: " << _sHash << "\t Nonce: " << _nNonce << endl;
    cout << "Previous Hash: " << sPrevHash << endl;
}

void Block::PrintBlock()
{
    cout << "-----------" << "Block " << _nIndex << "-----------" << "\n";
    cout << "Nonce: " << _nNonce << "\n";
    cout << "Hash: " << _sHash << "\n";
    cout << "Previous Hash: " << sPrevHash << "\n";
    cout << "Data: " << _sData << "\n";
    cout << "Time: " << _tTime << "\n";
}

inline string Block::_CalculateHash() const
{
    stringstream ss;
    ss << _nIndex << _tTime << _sData << _nNonce << sPrevHash;

    return sha256(ss.str());
}
