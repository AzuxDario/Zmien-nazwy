#ifndef PARAMETRYZMIANYNAZW_H
#define PARAMETRYZMIANYNAZW_H


class ParametryZmianyNazw
{
private:
    bool czyZamienicWPodfolderach;
    bool czyZamienicPodkreslenia;
    bool czyZamienicPauzy;
    bool czyZamienicKropki;
    bool czyZamienicKropkeRozszerzenia;
    bool czyPierwszaDuza;
    bool czyRozszerzenieMale;
public:
    ParametryZmianyNazw();
    void ustawCzyZamienicWPodfolderach(bool wartosc);
    void ustawCzyZamienicPodkreslenia(bool wartosc);
    void ustawCzyZamienicPauzy(bool wartosc);
    void ustawCzyZamienicKropki(bool wartosc);
    void ustawCzyZamienicKropkeRozszerzenia(bool wartosc);
    void ustawCzyPierwszaDuza(bool wartosc);
    void ustawCzyRozszerzenieMale(bool wartosc);
    bool zwrocCzyZamienicWPodfolderach();
    bool zwrocCzyZamienicPodkreslenia();
    bool zwrocCzyZamienicPauzy();
    bool zwrocCzyZamienicKropki();
    bool zwrocCzyZamienicKropkeRozszerzenia();
    bool zwrocCzyPierwszaDuza();
    bool zwrocCzyRozszerzenieMale();
};

#endif // PARAMETRYZMIANYNAZW_H
