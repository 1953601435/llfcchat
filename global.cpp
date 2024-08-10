#include"global.h"
std::function<void(QWidget*)> repolish=[](QWidget* w ){
    w->style()->unpolish(w);
    w->style()->polish(w);//删然后刷新，用新的style属性

};
