#ifndef __PMARKS_H__
#define __PMARKS_H__

#include "IState.h"

class PEndMarks: public IState {
    public:
        void        onChar (char key)   override;
        void        onEnd  ()           override;
        void        clear  ()           override;
        ~PEndMarks() = default;

        void setContext(Context* context){
            m_context = context;
        }
};

#endif // __PMARKS_H__