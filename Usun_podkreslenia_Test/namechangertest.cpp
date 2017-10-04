#include <QString>
#include <QFileDialog>
#include <QFile>
#include <QMessageBox>
#include <QStringList>
#include <QRegExp>
#include <QtTest>
#include "../Usun_podkreslenia/namechanger.h"
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
    NameChanger nameChanger;
    QString expected = "Nazwa pliku.cpp";
    QString received = nameChanger.replaceUnderscores("Nazwa_pliku.cpp");
    QCOMPARE(expected, received);
}

QTEST_APPLESS_MAIN(NameChangerTest)

#include "namechangertest.moc"
