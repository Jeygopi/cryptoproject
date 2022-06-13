#include "Block.h"
#include "sha256.h"
#include <time.h>
#include <sstream>

// The section after the : is an initialisation list, initialises the variables _nIndex and
// _sData to specific values before the body of the constructor executes
Block::Block(uint32_t nIndexIn, const string &sDataIn) : _nIndex(nIndexIn), _sData(sDataIn) {
    _nNonce = -1;
    _tTime = time(nullptr);
}
 
string Block::GetHash() {
    return _sHash;
}

void Block::MineBlock(uint32_t nDifficulty) {
    char cstr[nDifficulty + 1];
    for (uint32_t i=0; i < nDifficulty; ++i) {
        cstr[i] = '0';
    }

    cstr[nDifficulty] = '\0'; // \0 is the special character for a string terminator

    string str(cstr);

    do {
        _nNonce++;
        _sHash = _CalculateHash();
    } while (_sHash.substr(0,nDifficulty) != str);
}

// inline function improves efficiency, cuts down on seperate method calls 
inline string Block::_CalculateHash() const {

    // stringstream is useful to concatenate different datatypes into a string object
    // through the use of the method .str()
    std::stringstream ss;

    // this appends the values from nIndex etc. to the stringstream object
    ss << _nIndex << _tTime << _sData << _nNonce << sPrevHash; 

    return sha256(ss.str());
}