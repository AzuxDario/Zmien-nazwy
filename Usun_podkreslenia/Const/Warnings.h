#ifndef WARNINGS_H
#define WARNINGS_H

#include <QString>

class Warnings
{
public:
    const QString folderNotFound {"Brak katalogu.\nKatalog mógł zostać usunięty, zmieniono jego nazwę, został przeniesiony\nlub nastąpiła inna czynność uniemożliwiająca znalezienie katalogu"};
    constexpr static char a[] {"a"};
public:
    Warnings();
};

#endif // WARNINGS_H
