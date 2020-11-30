#ifndef __IPROCESS_H__
#define __IPROCESS_H__

#include "common.h"

class IProcess{
    public:
        virtual ~IProcess() 					= default;
        [[nodiscard]] virtual bool run()		= 0;
        [[nodiscard]] virtual bool print()		= 0;
        virtual std::string getResult() const 	= 0;
};

#endif // __IPROCESS_H__