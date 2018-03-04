#include "fields.h"

Fields::Fields()
{
    isAutoValue = false;
}

bool Fields::getIsAutoValue() const
{
    return isAutoValue;
}

void Fields::setIsAutoValue(bool value)
{
    isAutoValue = value;
}
void Fields::Statuskey_Tybe(QString _keyTybe)
{
    
    if (_keyTybe=="PRI") {
        key_Tybe=PRIMARY;
    } else if (_keyTybe=="UNI") {
        key_Tybe=UNIQUE;
    } else if (_keyTybe=="MUL") {
        key_Tybe=INDEX;
    } else {
        key_Tybe=keyNULL;
    }



}
Fields::~Fields()
{
}
//Fields& Fields::operator =(Fields &F)			// operator= sets values of v to this Vector3D. example: v1 = v2 means that values of v2 are set onto v1
//{
//    Name = F.Name;
//    val  = F.val;
//    return *this;
//}
