#ifndef NAMECHANGEPARAMETERS_H
#define NAMECHANGEPARAMETERS_H


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

public:
    NameChangeParameters();
    void setReplaceInSubfolders(bool value) noexcept {replaceInSubfolders = value;}
    void setReplaceUnderscores(bool value) noexcept {replaceUnderscores = value;}
    void setReplaceDashes(bool value) noexcept {replaceDashes = value;}
    void setDontReplaceDashesSurrondedBySpaces(bool value) noexcept {dontReplaceDashesSurrondedBySpaces = value;}
    void setReplaceDots(bool value) noexcept {replaceDots = value;}
    void setReplaceExtensionDot(bool value) noexcept {replaceExtensionDot = value;}
    void setReplacePluses(bool value) noexcept {replacePluses = value;}
    void setRemoveMultiplySpaces(bool value) {removeMultiplySpaces = value;}
    void setRemoveSpacesAtBegin(bool value) {removeSpacesAtBegin = value;}
    void setRemoveSpacesAtEnd(bool value) {removeSpacesAtEnd = value;}
    void setChangeLetters(Letters value) noexcept {changeLetters = value;}
    void setChangeExtension(Extensions value) noexcept {changeExtension = value;}
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
};

#endif // NAMECHANGEPARAMETERS_H
