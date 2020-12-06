#ifndef __ENDSCOPE_H__
#define __ENDSCOPE_H__

#include "IState.h"

class EndScope: public IState {
    public:
        void        onChar (char key)   override;
        void        onEnd  ()           override;
        void        clear  ()           override;
        ~EndScope() = default;

        void setContext(Context* context){
            m_context = context;
        }
};

#endif // __ENDSCOPE_H__