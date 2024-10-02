#include <iostream>

using namespace std;

const int SUAL_SAYI = 5;  
const int CAVAB_SAYI = 4; 


void quizEt(const char suallar[SUAL_SAYI][100], const char cavablar[SUAL_SAYI][CAVAB_SAYI][50], const char duzgunCavablar[SUAL_SAYI]) {
    char istifadeciCavablari[SUAL_SAYI];

    cout << "Quiz başlayır! Suallara W, A, S, D ilə cavab verin." << endl;
    
    for (int i = 0; i < SUAL_SAYI; ++i) {
        cout << "\nSual " << i + 1 << ": " << suallar[i] << endl;

        for (int j = 0; j < CAVAB_SAYI; ++j) {
            cout << (char)('W' + j) << ") " << cavablar[i][j] << endl;
        }
       
        char cavab;
        bool etibarlıCavab = false;


        while (!etibarlıCavab) {
            cout << "Cavabınız (W, A, S, D): ";
            cin >> cavab;
            cavab = toupper(cavab);

            if (cavab == 'W' || cavab == 'A' || cavab == 'S' || cavab == 'D') {
                etibarlıCavab = true;
            }
            else {
                cout << "Yanlış cavab! Zəhmət olmasa W, A, S, D-dən birini daxil edin.\n";
            }
        }

        istifadeciCavablari[i] = cavab;
    }

    cout << "\nQuiz sona çatdı! Nəticələriniz:\n" << endl;

    int duzgunSayi = 0;
    for (int i = 0; i < SUAL_SAYI; ++i) {
        cout << "Sual " << i + 1 << ": " << suallar[i] << endl;
        cout << "Sizin cavabınız: " << istifadeciCavablari[i] << endl;
        cout << "Düzgün cavab: " << duzgunCavablar[i] << endl;

        if (istifadeciCavablari[i] == duzgunCavablar[i]) {
            duzgunSayi++;
        }
    }

    cout << "umumi duzgun cavab sayı: " << duzgunSayi << " / " << SUAL_SAYI << endl;
}
void menyu() {
    cout << "\t\t************* 1.start quiz show *************" << endl;
    cout << "\t\t   *************  2.exit *************" << endl;
    cout << "\t\t\t\tseciminiz: ";
}

int main() {

    const char suallar[SUAL_SAYI][100] = {
        "1. Oyun proqramlasdırmasında hansı muhərrikdən cox istifadə olunur?",
        "2. C++ dilində hansı dəyişən tipi onluq ədəd saxlayır?",
        "3. Hansı alqoritma axtarış alqoritmasıdır?",
        "4. İnkişaf etmiş süni intellekt sistemi hansı istiqamətdədir?",
        "5. Hansı proqramlama dili maşın dilinə daha yaxın sayılır?"
    };

    const char cavablar[SUAL_SAYI][CAVAB_SAYI][50] = {
        { "Unity", "Unreal Engine", "Frostbite", "CryEngine" },
        { "int", "float", "char", "bool" },
        { "Bubble Sort", "Binary Search", "Merge Sort", "Selection Sort" },
        { "Deep Learning", "Blockchain", "Cloud Computing", "Quantum Computing" },
        { "Python", "Java", "Assembly", "JavaScript" }
    };

    char duzgunCavablar[SUAL_SAYI] = { 'W', 'S', 'A', 'W', 'S' };

    int secim;
    bool devamEt = true;

    while (devamEt) {
        menyu(); 
        cin >> secim;

        if (secim == 1) {
            quizEt(suallar, cavablar, duzgunCavablar); 
        }
        else if (secim == 2) {
            cout << "cixis edilir" << endl;
            devamEt = false;
        }
        else {
            cout << "Yanlıs seçim etdiniz! Zəhmət olmasa 1 və ya 2 secin." << endl;
        }
    }


}
