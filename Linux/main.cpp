//Wojciech Gunia © 2024 - Święty Mikołaj - projekt zaliczeniowy - PSiW
#include <iostream>
#include <cstdlib>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <chrono>
#include <list>

using namespace std;

//Inicjalizacja zmiennych i stałych globalnych.
const int LICZBA_RENIFEROW = 9;
const int LICZBA_SKRZATOW = 10;
const int WYMAGANE_RENIFERY = 9;
const int WYMAGANE_SKRZATY = 3;

mutex mtx;
condition_variable santaCV, reindeerCV, gnomeCV, waitCV;

int numReindeer = 0;
int numGnomes = 0;
bool santaIsSleeping = true;
int guest = 0;

std::list<int> Reindeers{ 0, 1, 2, 3, 4, 5, 6, 7, 8 };
std::list<int> Gnomes{ 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };

//Wątek Świętego Mikołaja.
void watekMikolaja() {
    unique_lock<mutex> lock(mtx);
    cout << "Mikołaj śpi." << endl;
    while (true) {
        // Mikołaj śpi, dopóki nie przybędzie 9 reniferów lub 3 skrzaty.
        santaCV.wait(lock, [] { return (numReindeer == WYMAGANE_RENIFERY || numGnomes >= WYMAGANE_SKRZATY); });
        
        if (numReindeer == WYMAGANE_RENIFERY) {
            // Mikołaj przygotowuje sanie i dostarcza zabawki.
            guest = numReindeer;
            numReindeer = 0;
            cout << "Mikołaj przygotowuje sanie i dostarcza zabawki dla grzecznych dzieci." << endl;
            reindeerCV.notify_all();
        }
        else if (numGnomes >= WYMAGANE_SKRZATY) {
            // Mikołaj konsultuje się ze skrzatami.
            guest = numGnomes;
            numGnomes = 0;
            cout << "Mikołaj konsultuje się ze skrzatami." << endl;
            gnomeCV.notify_all();
        }

        santaCV.wait(lock, [] { return guest==0; });
        // Mikołaj wraca spać, gdy obsłuży grupę elfów lub reniferów.
        santaIsSleeping = true;
        waitCV.notify_one();
        cout << "Mikołaj wraca spać." << endl;
    }
}

//Wątek Renifera.
void watekRenifera(int id) {
    unique_lock<mutex> lock(mtx);

    // Renifer przybywa i budzi Mikołaja gdy jest 9.
    cout << "Renifer " << id + 1 << " przybył do Mikołaja." << endl;
    numReindeer++;
    if (numReindeer == WYMAGANE_RENIFERY && santaIsSleeping) {
        santaCV.notify_one();
        santaIsSleeping = false;
    }
    else if(numReindeer == WYMAGANE_RENIFERY && !santaIsSleeping)
    {
    	waitCV.wait(lock, [] { return santaIsSleeping; });
    	santaCV.notify_one();
        santaIsSleeping = false;
    }

    reindeerCV.wait(lock);
    // Renifer odchodzi na spoczynek ( ostatni informuje Mikołaja ).
    cout << "Renifer " << id + 1 << " odchodzi na spoczynek." << endl;
    guest--;
    if(guest==0)
        santaCV.notify_one();
    Reindeers.push_back(id);
    return;

}

//Wątek Skrzata
void watekSkrzata(int id) {
    unique_lock<mutex> lock(mtx);

    // Skrzat przybywa i budzi Mikołaja, jeśli to konieczne ( jeśli jest 3 skrzatem ).
    cout << "Skrzat " << id + 1 << " przybył do Mikołaja." << endl;
    numGnomes++;
    if (numGnomes >= WYMAGANE_SKRZATY && santaIsSleeping) {
        santaCV.notify_one();
        santaIsSleeping = false;
    }
    else if(numGnomes >= WYMAGANE_SKRZATY && !santaIsSleeping)
    {
    	waitCV.wait(lock, [] { return santaIsSleeping; });
    	santaCV.notify_one();
        santaIsSleeping = false;
    }

    gnomeCV.wait(lock);
    // Skrzat opuszcza mikołaja po konsultacji ( ostatni informuje Mikołaja ).
    cout << "Skrzat " << id + 1 << " odchodzi." << endl;
    
    guest--;
    if (guest == 0)
        santaCV.notify_one();
    Gnomes.push_back(id);
    return;
}

int main() {

    //Inicjalizacja wątku Mikołaja.
    thread mikolaj(watekMikolaja);
    
    //Główna pętla programu ( tworząca wątek renifera lub skrzata co 1s ).
    while (true)
    {
        this_thread::sleep_for(chrono::milliseconds(1000));
        if (rand() % 2 == 1)
        {
            if (Reindeers.size()>0)
            {
                thread(watekRenifera, *Reindeers.begin()).detach();
                Reindeers.pop_front();
            }
                
        }
        else
        {
            if (Gnomes.size() > 0)
            {
                thread(watekSkrzata, *Gnomes.begin()).detach();
                Gnomes.pop_front();
            }
                
        }
    }

    mikolaj.join();

    return 0;
}
