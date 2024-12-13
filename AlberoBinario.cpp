#include <iostream>
using namespace std;

template <typename T>
class AlberoBinario {
private:
    T nodi[100];
    bool occupati[100];

    int figlioSinistro(int indice) const {
        return 2 * indice + 1;
    }

    int figlioDestro(int indice) const {
        return 2 * indice + 2;
    }

public:
    AlberoBinario() {
        for (int i = 0; i < 100; i++) {
            occupati[i] = false;
        }
    }

    bool alberoVuoto() const {
        return occupati[0] == false;
    }

    void insRadice(const T& valore) {
        if (alberoVuoto()) {
            nodi[0] = valore;
            occupati[0] = true;
        } else {
            cout << "Radice già presente\n";
        }
    }

    T radice() const {
        if (alberoVuoto()) {
            cout << "Albero vuoto\n";
            return T();
        }
        return nodi[0];
    }

    bool isFoglia(int indice) const {
        if (!occupati[indice]) {
            cout << "Nodo non esiste\n";
            return false;
        }
        return !occupati[figlioSinistro(indice)] && !occupati[figlioDestro(indice)];
    }

    void insFiglioSinistro(int indice, const T& valore) {
        int sinistro = figlioSinistro(indice);
        if (!occupati[indice] || sinistro >= 100) {
            cout << "Errore nell'inserimento del figlio sinistro\n";
            return;
        }
        if (!occupati[sinistro]) {
            nodi[sinistro] = valore;
            occupati[sinistro] = true;
        } else {
            cout << "Figlio sinistro già presente\n";
        }
    }

    void insFiglioDestro(int indice, const T& valore) {
        int destro = figlioDestro(indice);
        if (!occupati[indice] || destro >= 100) {
            cout << "Errore nell'inserimento del figlio destro\n";
            return;
        }
        if (!occupati[destro]) {
            nodi[destro] = valore;
            occupati[destro] = true;
        } else {
            cout << "Figlio destro già presente\n";
        }
    }

    void rimuovi(int indice) {
        if (!occupati[indice]) {
            cout << "Il nodo non esiste\n";
            return;
        }
        if (!isFoglia(indice)) {
            cout << "Il nodo non e' una foglia, impossibile rimuovere\n";
            return;
        }
        occupati[indice] = false;
    }

    void stampa() const {
        for (int i = 0; i < 100; i++) {
            if (occupati[i]) {
                cout << "Pos " << i << ", Valore: " << nodi[i];
                if (occupati[figlioSinistro(i)]) {
                    cout << ", FiglioSinistro: " << nodi[figlioSinistro(i)];
                } else {
                    cout << ", FiglioSinistro: NULL";
                }
                if (occupati[figlioDestro(i)]) {
                    cout << ", FiglioDestro: " << nodi[figlioDestro(i)];
                } else {
                    cout << ", FiglioDestro: NULL";
                }
                cout << "\n";
            }
        }
    }
};

int main() {
    AlberoBinario<int> albero;

    albero.insRadice(10);
    albero.insFiglioSinistro(0, 5);
    albero.insFiglioDestro(0, 15);
    albero.insFiglioSinistro(1, 3);

    cout << "Albero binario:\n";
    albero.stampa();

    cout << "Radice: " << albero.radice() << "\n";
    cout << "Nodo 1 e' una foglia? " << (albero.isFoglia(1) ? "Sì" : "No") << "\n";

    albero.rimuovi(3); 
    cout << "Dopo rimozione del nodo 3:\n";
    albero.stampa();

    albero.rimuovi(1); 
    cout << "Dopo il tentativo di rimozione del nodo 1:\n";
    albero.stampa();

    return 0;
}
