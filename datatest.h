#ifndef DATATEST_H
#define DATATEST_H
#include <QString>
#define YESm true
#define NOm false
class dataTest;
template<typename T> class QList;
typedef QList<dataTest> dataTestList;

class dataTest
{
public:
    QString ID;
    QString TypeHBD;
    QString statment;
    bool Answer;
    dataTest();
};

#endif // DATATEST_H
