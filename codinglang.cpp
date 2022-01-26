#include "codinglang.h"

//CodingLang::CodingLang(): name { "" }, icon{} {}

CodingLang::CodingLang(const QString &name, const QIcon &icon):
    name { name }, icon { icon } {}

const QString &CodingLang::getName() const
{
    return name;
}

const QIcon &CodingLang::getIcon() const
{
    return icon;
}
