#include "useraction.h"


//setup user action to allow for abstract overriding of common automation actions
UserAction::UserAction()
{
    public:
        Invoke();

    virtual:
                  OnInvoke();
}
