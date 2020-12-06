#ifndef __MISCELLANEA_H__
#define __MISCELLANEA_H__

#include "IState.h"

class Miscellenea: public IState {
    public:
        void        onChar (char key)   override;
        void        onEnd  ()           override;
        void        clear  ()           override;
        ~Miscellenea() = default;

        void setContext(Context* context) {
            m_context = context;
        }
};

#endif // __MISCELLANEA_H__