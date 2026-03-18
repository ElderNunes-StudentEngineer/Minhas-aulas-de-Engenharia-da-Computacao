#include <iostream>
#include <vector>
#include <cstdlib> // Para rand()
#include <ctime>   // Para time()

using namespace std;

class Lutador
{
private:
    string nome;
    string nacionalidade;
    int idade;
    float altura;
    float peso;
    string categoria;
    int vitorias;
    int derrotas;
    int empates;

public:
    Lutador(string nome, string nacionalidade, int idade, float altura, float peso, string categoria, int vitorias, int derrotas, int empates)
    {
        this->nome = nome;
        this->nacionalidade = nacionalidade;
        this->idade = idade;
        this->altura = altura;
        this->peso = peso;
        this->categoria = categoria;
        this->vitorias = vitorias;
        this->derrotas = derrotas;
        this->empates = empates;
        cout << "Objeto criado com sucesso!" << endl;
    }

    ~Lutador()
    {
        cout << "Objeto destruído com sucesso!" << endl;
    }

    string getNome() { return nome; }
    string getNacionalidade() { return nacionalidade; }
    int getIdade() { return idade; }
    float getAltura() { return altura; }
    float getPeso() { return peso; }
    string getCategoria() { return categoria; }
    int getVitorias() { return vitorias; }
    int getDerrotas() { return derrotas; }
    int getEmpates() { return empates; }

    void apresentarLutador()
    {
        cout << "\n------------------------------";
        cout << "\nApresentando lutador..." << endl;
        cout << "Nome: " << nome << endl;
        cout << "Nacionalidade: " << nacionalidade << endl;
        cout << "Idade: " << idade << " anos" << endl;
        cout << "Altura: " << altura << " metros" << endl;
        cout << "Peso: " << peso << " kg" << endl;
        cout << "Categoria: " << categoria << endl;
        cout << "Vitórias: " << vitorias << endl;
        cout << "Derrotas: " << derrotas << endl;
        cout << "Empates: " << empates << endl;
        cout << "------------------------------";
    }

    void ganharLuta()
    {
        vitorias++;
        cout << "\nVitória adicionada para " << nome << ". Total de vitórias: " << vitorias << endl;
    }

    void perderLuta()
    {
        derrotas++;
        cout << "\nDerrota adicionada para " << nome << ". Total de derrotas: " << derrotas << endl;
    }

    void empatarLuta()
    {
        empates++;
        cout << "\nEmpate adicionado para " << nome << ". Total de empates: " << empates << endl;
    }
};

class Luta
{
private:
    Lutador *desafiado;
    Lutador *desafiante;
    int rounds;
    bool aprovada;

public:
    void setDesafiado(Lutador *desafiado)
    {
        this->desafiado = desafiado;
    }

    void setDesafiante(Lutador *desafiante)
    {
        this->desafiante = desafiante;
    }

    void setRounds(int rounds)
    {
        this->rounds = rounds;
    }

    void setAprovada(bool aprovada)
    {
        this->aprovada = aprovada;
    }

    Luta(Lutador *desafiado, Lutador *desafiante, int rounds, bool aprovada)
    {
        setDesafiado(desafiado);
        setDesafiante(desafiante);
        setRounds(rounds);
        setAprovada(aprovada);
    }

    Lutador *getDesafiado()
    {
        return desafiado;
    }

    Lutador *getDesafiante()
    {
        return desafiante;
    }

    int getRounds()
    {
        return rounds;
    }

    bool getAprovada()
    {
        return aprovada;
    }

    void marcarLuta(Lutador *l1, Lutador *l2)
    {
        if (l1->getCategoria() == l2->getCategoria() && l1 != l2)
        {
            desafiado = l1;
            desafiante = l2;
            aprovada = true;
        }
        else
        {
            aprovada = false;
        }
    }

    void lutar()
    {
        if (aprovada)
        {
            cout << "\n=== LUTA ENTRE " << desafiado->getNome() << " E " << desafiante->getNome() << " ===\n";

            int resultado = rand() % 3; // 0 = empate, 1 = desafiado vence, 2 = desafiante vence

            if (resultado == 0)
            {
                cout << "Empate!\n";
                desafiado->empatarLuta();
                desafiante->empatarLuta();
            }
            else if (resultado == 1)
            {
                cout << desafiado->getNome() << " venceu a luta!\n";
                desafiado->ganharLuta();
                desafiante->perderLuta();
            }
            else
            {
                cout << desafiante->getNome() << " venceu a luta!\n";
                desafiante->ganharLuta();
                desafiado->perderLuta();
            }
        }
        else
        {
            cout << "\nLuta não aprovada.\n";
        }
    }

    ~Luta()
    {
        cout << "Luta destruída com sucesso!" << endl;
    }
};

class Pessoa
{
protected:
    string nome;
    int idade;

public:
    Pessoa(string nome, int idade)
    {
        this->nome = nome;
        this->idade = idade;
    };

    string getNome()
    {
        return this->nome;
    }

    int getIdade()
    {
        return this->idade;
    }

    virtual void pagarEntrada() = 0;
};

int main()
{
    vector<Lutador> lutadores;

    lutadores.push_back(Lutador("Danny Abbadi", "Unknown", 30, 1.80, 70.3, "Lightweight", 2, 2, 0));
    lutadores.push_back(Lutador("Nariman Abbasov", "Unknown", 30, 1.80, 70.3, "Lightweight", 0, 1, 0));
    lutadores.push_back(Lutador("Tank Abbott", "Unknown", 30, 1.80, 120.0, "Heavyweight", 8, 10, 0));
    lutadores.push_back(Lutador("Hamdy Abdelwahab", "Unknown", 30, 1.80, 120.0, "Heavyweight", 6, 0, 0));
    lutadores.push_back(Lutador("Shamil Abdurakhimov", "Unknown", 30, 1.80, 120.0, "Heavyweight", 20, 8, 0));
    lutadores.push_back(Lutador("Daichi Abe", "Unknown", 30, 1.80, 77.1, "Welterweight", 6, 1, 0));
    lutadores.push_back(Lutador("Papy Abedi", "Unknown", 30, 1.80, 83.9, "Middleweight", 9, 3, 0));
    lutadores.push_back(Lutador("Klidson Abreu", "Unknown", 30, 1.80, 93.0, "Light Heavyweight", 15, 4, 0));
    lutadores.push_back(Lutador("Juan Adams", "Unknown", 30, 1.80, 120.0, "Heavyweight", 5, 3, 0));
    lutadores.push_back(Lutador("Scott Adams", "Unknown", 30, 1.80, 120.0, "Heavyweight", 6, 0, 0));
    lutadores.push_back(Lutador("Anthony Adams", "Unknown", 30, 1.80, 83.9, "Middleweight", 8, 2, 0));
    lutadores.push_back(Lutador("Zarrukh Adashev", "Unknown", 30, 1.80, 56.7, "Flyweight", 4, 4, 0));

    lutadores.push_back(Lutador("Christian Aguilera", "Unknown", 30, 1.80, 61.2, "Bantamweight", 14, 8, 0));
    lutadores.push_back(Lutador("Nick Aguirre", "Unknown", 30, 1.80, 61.2, "Bantamweight", 7, 2, 0));
    lutadores.push_back(Lutador("Alatengheili", "Unknown", 30, 1.80, 61.2, "Bantamweight", 17, 9, 2));
    lutadores.push_back(Lutador("Amir Albazi", "Unknown", 30, 1.80, 56.7, "Flyweight", 17, 2, 0));
    lutadores.push_back(Lutador("Omari Akhmedov", "Unknown", 30, 1.80, 83.9, "Middleweight", 21, 6, 1));
    lutadores.push_back(Lutador("Yoshihiro Akiyama", "Unknown", 30, 1.80, 77.1, "Welterweight", 15, 8, 0));
    lutadores.push_back(Lutador("Junior Albini", "Unknown", 30, 1.80, 120.0, "Heavyweight", 14, 6, 0));
    lutadores.push_back(Lutador("Wes Albritton", "Unknown", 30, 1.80, 70.3, "Lightweight", 0, 1, 0));
    lutadores.push_back(Lutador("Rostem Akman", "Unknown", 30, 1.80, 77.1, "Welterweight", 6, 2, 0));
    lutadores.push_back(Lutador("Mostapha Al Turk", "Unknown", 30, 1.80, 120.0, "Heavyweight", 6, 6, 0));

    lutadores.push_back(Lutador("Kevin Aguilar", "Unknown", 30, 1.80, 65.8, "Featherweight", 17, 5, 0));
    lutadores.push_back(Lutador("Jesus Aguilar", "Unknown", 30, 1.80, 56.7, "Flyweight", 11, 3, 0));
    lutadores.push_back(Lutador("Israel Adesanya", "Unknown", 30, 1.80, 83.9, "Middleweight", 24, 5, 0));
    lutadores.push_back(Lutador("Ricardo Abreu", "Unknown", 30, 1.80, 83.9, "Middleweight", 5, 1, 0));
    lutadores.push_back(Lutador("Mansur Abdul-Malik", "Unknown", 30, 1.80, 83.9, "Middleweight", 8, 0, 0));
    lutadores.push_back(Lutador("John Adjar", "Unknown", 30, 1.80, 77.1, "Welterweight", 0, 1, 0));

    for (size_t i = 0; i < lutadores.size(); i++)
    {
        cout << "Lutador " << i + 1 << ":\n";
        lutadores[i].apresentarLutador();
        cout << "------------------------\n";
    }

    srand(time(0)); // Inicia aleatoriedade

    Luta luta(nullptr, nullptr, 3, false);
    luta.marcarLuta(&lutadores[0], &lutadores[1]); // Dois lutadores de mesma categoria
    luta.lutar();

    return 0;
}