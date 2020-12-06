#ifndef __RESEMBLING_H__
#define __RESEMBLING_H__

#include "IState.h"

class Resembling: public IState {
    public:
        void        onChar (char key)   override;
        void        onEnd  ()           override;
        void        clear  ()           override;
        ~Resembling() = default;

        void setContext(Context* context){
            m_context = context;
        }
};

#endif // __RESEMBLING_H__