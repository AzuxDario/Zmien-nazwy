#ifndef NAMECHANGEPARAMETERS_H
#define NAMECHANGEPARAMETERS_H

#include <QMetaType>
#include <QStringList>

class NameChangeParameters
{
public:
    enum class Letters {FirstBig, FirstBigRestSmall, AllBig, AllSmall, FirstInWordsBig, DoNothing};
    enum class Extensions {FirstBig, AllBig, AllSmall, DoNothing};
    enum class DirType {Folder, File};

private:
    bool replaceInSubfolders;
    bool replaceUnderscores; //Podkreślenie
    bool replaceDashes; //Pauza
    bool dontReplaceDashesSurrondedBySpaces;
    bool replaceDots;
    bool replaceExtensionDot;
    bool replacePluses;
    bool removeMultiplySpaces;
    bool removeSpacesAtBegin;
    bool removeSpacesAtEnd;
    Letters changeLetters;
    Extensions changeExtension;
    QStringList extensions;

public:
    NameChangeParameters();
    void setReplaceInSubfolders(const bool value) noexcept {replaceInSubfolders = value;}
    void setReplaceUnderscores(const bool value) noexcept {replaceUnderscores = value;}
    void setReplaceDashes(const bool value) noexcept {replaceDashes = value;}
    void setDontReplaceDashesSurrondedBySpaces(const bool value) noexcept {dontReplaceDashesSurrondedBySpaces = value;}
    void setReplaceDots(const bool value) noexcept {replaceDots = value;}
    void setReplaceExtensionDot(const bool value) noexcept {replaceExtensionDot = value;}
    void setReplacePluses(const bool value) noexcept {replacePluses = value;}
    void setRemoveMultiplySpaces(const bool value) {removeMultiplySpaces = value;}
    void setRemoveSpacesAtBegin(const bool value) {removeSpacesAtBegin = value;}
    void setRemoveSpacesAtEnd(const bool value) {removeSpacesAtEnd = value;}
    void setChangeLetters(const Letters value) noexcept {changeLetters = value;}
    void setChangeExtension(const Extensions value) noexcept {changeExtension = value;}
    void setExtensions(const QStringList& value) noexcept {extensions = value;}
    bool getReplaceInSubfolders() noexcept {return replaceInSubfolders;}
    bool getReplaceUnderscores() noexcept {return replaceUnderscores;}
    bool getReplaceDashes() noexcept {return replaceDashes;}
    bool getDontReplaceDashesSurrondedBySpaces() noexcept {return dontReplaceDashesSurrondedBySpaces;}
    bool getReplaceDots() noexcept {return replaceDots;}
    bool getReplaceExtensionDot() noexcept {return replaceExtensionDot;}
    bool getReplacePluses() noexcept {return replacePluses;}
    bool getRemoveMultiplySpaces() {return removeMultiplySpaces;}
    bool getRemoveSpacesAtBegin() {return removeSpacesAtBegin;}
    bool getRemoveSpacesAtEnd() {return removeSpacesAtEnd;}    
    Letters getChangeLetters() noexcept {return changeLetters;}
    Extensions getChangeExtension() noexcept { return changeExtension;}
    QStringList& getExtensions() noexcept {return extensions;}
};

Q_DECLARE_METATYPE(NameChangeParameters);

#endif // NAMECHANGEPARAMETERS_H
