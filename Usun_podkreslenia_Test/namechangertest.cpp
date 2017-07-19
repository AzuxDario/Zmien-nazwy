#include <QString>
#include <QtTest>
//#include "../Usun_podkreslenia/namechanger.h"
class NameChangerTest : public QObject
{
    Q_OBJECT

public:
    NameChangerTest();

private Q_SLOTS:
    void replaceUnderscoresTest();
};

NameChangerTest::NameChangerTest()
{
}

void NameChangerTest::replaceUnderscoresTest()
{
    //NameChanger nameChanger;
    //QString expected = "Nazwa pliku.cpp";
    //received = nameChanger.replaceUnderscores("Nazwa_pliku.cpp");
    //QVERIFY2(excepted, received);
}

//QTEST_APPLESS_MAIN(NameChangerTest)

#include "namechangertest.moc"
