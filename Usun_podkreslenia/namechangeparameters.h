#ifndef NAMECHANGEPARAMETERS_H
#define NAMECHANGEPARAMETERS_H


class NameChangeParameters
{
private:
    bool replaceInSubfolders;
    bool replaceUnderscores; //Podkreślenie
    bool replaceDashes; //Pauza
    bool replaceDots;
    bool replaceExtensionDot;
    bool changeFirstLetterToBig;
    bool changeExtensionToSmall;
public:
    NameChangeParameters();
    void setReplaceInSubfolders(bool value);
    void setReplaceUnderscores(bool value);
    void setReplaceDashes(bool value);
    void setReplaceDots(bool value);
    void setReplaceExtensionDot(bool value);
    void setChangeFirstLetterToBig(bool value);
    void setChangeExtensionToSmall(bool value);
    bool getReplaceInSubfolders();
    bool getReplaceUnderscores();
    bool getReplaceDashes();
    bool getReplaceDots();
    bool getReplaceExtensionDot();
    bool getChangeFirstLetterToBig();
    bool getChangeExtensionToSmall();
};

#endif // NAMECHANGEPARAMETERS_H
