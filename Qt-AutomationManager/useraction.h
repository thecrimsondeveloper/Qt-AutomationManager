#ifndef USERACTION_H
#define USERACTION_H

template<typename T>
struct UserActionData;

template<typename T>
class UserAction
{
public:
    UserAction();
    void Invoke(UserActionData<T> data);

protected:
    virtual void OnInvoke(UserActionData<T> data);

};

template<typename T>
struct UserActionData
{
    UserActionData();
    UserActionData(UserAction<T>* action, int id);
    UserAction<T>* Action;
    int ID;
};

#endif // USERACTION_H
