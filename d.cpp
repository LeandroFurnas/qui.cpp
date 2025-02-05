#include <iostream>

using namespace std;

string frase;
char letra;

int main() {
    cout << "Bem-vindo ao jogo da forca só que sem forca." << endl;
    cout << "Digite uma frase para o próximo jogador adivinhar." << endl;
    getline(cin, frase);

    system("cls");

    string frase_oculta = frase;

    // Oculta a frase com '_', mantendo os espaços intactos
    for (char &l : frase_oculta) {
        if (l != ' ') {
            l = '_';
        }
    }

    // Exibe a frase oculta
    cout << frase_oculta << "\n\n";

    while (true) {
        cout << "Tente adivinhar a frase!" << endl;
        cout << "Boa sorte!" << endl;
        cin >> letra;

        bool acertou = false;

        // Verifica se a letra inserida está na frase
        for (size_t i = 0; i < frase.size(); i++) {
            if (frase[i] == letra) {
                frase_oculta[i] = letra;
                acertou = true;
            }
        }

        if (!acertou) {
            cout << "A letra '" << letra << "' não está na frase. Tente novamente!\n";
        }

        system("cls");  // Limpa a tela após a tentativa

        // Exibe a frase oculta atualizada
        cout << frase_oculta << "\n\n";

        // Se a frase oculta for igual à frase original, o jogador venceu
        if (frase_oculta == frase) {
            system("cls");
            cout << "\nParabéns! Você adivinhou a frase: " << frase << endl;
            break;
        }
    }

    return 0;
}
