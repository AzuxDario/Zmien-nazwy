#include <QString>
#include <QtTest>

class Usun_podkreslenia_Test : public QObject
{
    Q_OBJECT

public:
    Usun_podkreslenia_Test();

private Q_SLOTS:
    void testCase1();
};

Usun_podkreslenia_Test::Usun_podkreslenia_Test()
{
}

void Usun_podkreslenia_Test::testCase1()
{
    QVERIFY2(true, "Failure");
}

QTEST_APPLESS_MAIN(Usun_podkreslenia_Test)

#include "tst_usun_podkreslenia_test.moc"
