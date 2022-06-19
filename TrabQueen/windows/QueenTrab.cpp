

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <vector>

using namespace sf;
using namespace std;

#include <stdio.h>

#define WHITE 'w'
#define BLACK 'b'
#define QUEEN_WHITE 'W'
#define QUEEN_BLACK 'B'
#define VAZIO ' '

string arqWhitePeao = "images/white_checker.png";
string arqBlackPeao = "images/black_checker.png";
string arqWhiteQueen = "images/white_checker_King.png";
string arqBlackQueen = "images/black_checker_King.png";
string mainMenu = "images/checker_main_menu.jpg";
string whiteWin = "images/white_win.png";
string blackWin = "images/black_win.png";
string draw = "images/draw.png";

enum Type
{
    Peao,
    Q,
};
enum Player
{
    W,
    B,
    V
};

enum Opponent
{
    comp,
    frnd,
};

class Peca
{
protected:
    char pec;
    static int qntWhite;
    static int qntBlack;
    Player Pl;
    Type Ty;
    string arquivo;
    Peca()
    {
        pec = VAZIO;
        Pl = V;
    }
    Peca(Type P, Player T)
    {
        if (T == W && P == Peao)
        {
            pec = WHITE;
            arquivo = arqWhitePeao;
        }
        if (T == B && P == Peao)
        {
            pec = BLACK;
            arquivo = arqBlackPeao;
        }
        if (T == W && P == Q)
        {
            pec = QUEEN_WHITE;
            arquivo = arqWhiteQueen;
        }
        if (T == B && P == Q)
        {
            pec = QUEEN_BLACK;
            arquivo = arqBlackQueen;
        }

        Pl = T;
        Ty = P;

        if (T == B)
            qntBlack++;
        else
            qntWhite++;
    }
    Peca(const Peca &p)
    {
        if (p.pec == B)
            qntBlack++;
        else
            qntWhite++;
        pec = p.pec;
        Pl = p.Pl;
    }

public:
    char getChar() { return pec; }
    Type getType() { return Ty; }
    Player getPlayer() { return Pl; }
    static void setQnt(Player Play)
    {
        if (Play == B)
            qntBlack--;
        else if (Play == W)
            qntWhite--;
    }
    static int getQntWhite() { return qntWhite; }
    static int getQntBlack() { return qntBlack; }
    string getTipo() { return arquivo; }
};

int Peca::qntBlack = 0;
int Peca::qntWhite = 0;

class Vazio : public Peca
{
public:
    Vazio() : Peca() {}
};

class Comum : public Peca
{
public:
    Comum(Player T) : Peca(Peao, T)
    {
        Pl = T;
        if (T == B)
            qntBlack++;
        else
            qntWhite++;
    }
    Comum(const Comum &p)
    {
        if (p.pec == B)
            qntBlack++;
        else
            qntWhite++;
        pec = p.pec;
        Pl = p.Pl;
    }
    ~Comum()
    {
        if (Pl == B)
            qntBlack--;
        else
            qntWhite--;
    }
};

class Queen : public Peca
{
public:
    Queen(Player T) : Peca(Q, T)
    {
        Pl = T;
        if (T == B)
            qntBlack++;
        else
            qntWhite++;
    }
    Queen(const Queen &p)
    {
        if (p.pec == B)
            qntBlack++;
        else
            qntWhite++;
        pec = p.pec;
        Pl = p.Pl;
    }
    ~Queen()
    {
        if (Pl == B)
            qntBlack--;
        else
            qntWhite--;
    }
};

class Tabuleiro:public Peca
{
    Peca **tabuleiro;
    int count; //------ variavel para contar o numero de jogadas sem capturas
    
    vector<pair<int, int>> pecasW;
    vector<pair<int, int>> pecasB;

public:
    Tabuleiro()
    {
        count = 0;
        tabuleiro = new Peca *[8];
        for (int i = 0; 8 > i; i++)
        {
            tabuleiro[i] = new Vazio[8];
        }
        for (int i = 0; i < 8; i++)
        {
            for (int j = 0; j < 8; j++)
            {
                if (i < 3 && (i % 2 != j % 2))
                {
                    tabuleiro[i][j] = Comum(W);
                    pair<int, int> p;
                    p.first = i;
                    p.second = j;
                    pecasW.push_back(p);
                }
                else if (i >= 5 && (i % 2 != j % 2))
                {
                    tabuleiro[i][j] = Comum(B);
                    pair<int, int> p;
                    p.first = i;
                    p.second = j;
                    pecasB.push_back(p);
                }
                else
                {
                    tabuleiro[i][j] = Vazio();
                }
            }
        }
    }
    //Criar metodo para adicionar 1 no contador de jogadas sem captura
    void playWithNoCapture(){
        count++;
    }
    //Criar metodo para adicionar zerar contador de jogadas na captura
    void playWithCapture(){
        count=0;
    }
    int getQuantidadeB() { return tabuleiro[0][0].getQntBlack(); }
    int getQuantidadeW() { return tabuleiro[0][0].getQntWhite(); }
    int getCount(){return count;}
    void addToVector(int lin, int col, Player pl)
    {
        pair<int, int> p;
        p.first = lin;
        p.second = col;
        if (pl == W)
        {
            pecasW.push_back(p);
        }
        else if (pl == B)
        {
            pecasB.push_back(p);
        }
    }
    void setVazio(int lin, int col)
    {
        tabuleiro[lin][col].setQnt(tabuleiro[lin][col].getPlayer());
        if (tabuleiro[lin][col].getChar() == VAZIO)
        {
            return;
        }
        tabuleiro[lin][col] = Vazio();
        for (int i = 0; pecasW.size() > i; i++)
        {
            pair<int, int> p;
            p.first = lin;
            p.second = col;
            if (pecasW[i] == p)
            {
                pecasW.erase(pecasW.begin() + i);
                return;
            }
        }
        for (int i = 0; pecasB.size() > i; i++)
        {
            pair<int, int> p;
            p.first = lin;
            p.second = col;
            if (pecasB[i] == p)
            {
                pecasB.erase(pecasB.begin() + i);
                return;
            }
        }
    }
    void imprimir()
    {
        cout << "\n";
        for (int i = 0; 8 > i; i++)
        {
            for (int j = 0; 8 > j; j++)
            {
                cout << tabuleiro[i][j].getChar() << " | ";
            }
            cout << "\n";
            for (int k = 0; 30 > k; k++)
            {
                cout << "-";
            }
            cout << "\n";
        }
        cout << "\n";
    }
    int isValid(int lin, int col, int Tlin, int Tcol, Player Player)
    {
        int capture = 1;
        if (lin >= 8 || col >= 8 || lin < 0 || col < 0 || Tlin >= 8 || Tcol >= 8 || Tlin < 0 || Tcol < 0)
            return false;

        if (Player != tabuleiro[lin][col].getPlayer())
            return false; // posicao inicial invalida

        if (tabuleiro[Tlin][Tcol].getPlayer() != V)
            return false; // se ja existe uma peça na posicao de destino

        if (tabuleiro[lin][col].getChar() == WHITE || tabuleiro[lin][col].getChar() == BLACK)
        { // Comportamento do peao
            if (Player == W)
            {
                if (Tlin - lin == 1 && abs(Tcol - col) == 1)
                    return capture; // andar apenas uma casa
                else if (Tlin - lin == 2 && abs(Tcol - col) == 2)
                { // tentar comer
                    if (Tcol > col)
                        col += 1;
                    else
                        col -= 1;
                    capture = 2;
                    
                    if (tabuleiro[lin + 1][col].getPlayer() != B)
                        return false; // se não for uma peça inimiga
                }
                else
                    return false;
            }
            else
            {
                if (Tlin - lin == -1 && abs(Tcol - col) == 1)
                    return capture; // andar apenas uma casa
                else if (Tlin - lin == -2 && abs(Tcol - col) == 2)
                { // tentar comer
                    if (Tcol > col)
                        col += 1;
                    else
                        col -= 1;
                    capture = 2;
                    if (tabuleiro[lin - 1][col].getPlayer() != W)
                        return false; // se não for uma peça inimiga
                }
                else
                    return false;
            }
        }
        else
        {                                                //É uma dama
            int addLin = (Tlin - lin) / abs(Tlin - lin); // direcões
            int addCol = (Tcol - col) / abs(Tcol - col);
            int auxLin = lin;
            int auxCol = col;
            int bloqueio = 0;

            if (abs(Tlin - lin) != abs(Tcol - col))
                return false;
            while ((lin != Tlin || col != Tcol))
            {
                lin += addLin;
                col += addCol;

                if (tabuleiro[lin][col].getPlayer() != V)
                    bloqueio += 1;
            }
            if (bloqueio > 1)
            { // Mais de uma peça no caminho
                return false;
            }
            else
            {
                if (bloqueio == 1)
                { // Peca no caminho
                    if (tabuleiro[Tlin][Tcol].getPlayer() != V || !(((tabuleiro[Tlin - addLin][Tcol - addCol].getPlayer() != Player)) && ((tabuleiro[Tlin - addLin][Tcol - addCol].getPlayer() != V))))
                    {
                        return false;
                    }
                    capture = 2;
                }
                return capture;
            }
        }

        return capture;
    }

    bool Jogada(int lin, int col, int Tlin, int Tcol, Player Pl, Opponent Op)
    {
        if (!isValid(lin, col, Tlin, Tcol, Pl))
        {
            cout << "Jogada Invalida\n";
            return false;
        }
        if (tabuleiro[lin][col].getChar() == QUEEN_WHITE || tabuleiro[lin][col].getChar() == QUEEN_BLACK)
        {                                                // Dama
            int addLin = (Tlin - lin) / abs(Tlin - lin); // direcões
            int addCol = (Tcol - col) / abs(Tcol - col);
            int auxLin = lin, auxCol = col;
            setVazio(auxLin, auxCol);
            setVazio(Tlin - addLin, Tcol - addCol);
            tabuleiro[Tlin][Tcol] = Queen(Pl);
            addToVector(Tlin, Tcol, Pl);

            return true;
        }
        else
        { // Normal
            setVazio(lin, col);

            if (abs(Tlin - lin) == 2 && abs(Tcol - col) == 2)
            { // Capturar peca
                if (Tcol > col)
                    col += 1;
                else
                    col -= 1;
                if (Pl == W)
                    lin += 1;
                else
                    lin -= 1;

                setVazio(lin, col);

                if (Tlin == 7 || Tlin == 0)
                {
                    tabuleiro[Tlin][Tcol] = Queen(Pl);
                    addToVector(Tlin, Tcol, Pl);
                }
                else
                {
                    tabuleiro[Tlin][Tcol] = Comum(Pl);
                    addToVector(Tlin, Tcol, Pl);
                }

                return true;
            }
            else
            {
                if (Tlin == 0 || Tlin == 7)
                {
                    tabuleiro[Tlin][Tcol] = Queen(Pl);
                    addToVector(Tlin, Tcol, Pl);
                }
                else
                {
                    tabuleiro[Tlin][Tcol] = Comum(Pl);
                    addToVector(Tlin, Tcol, Pl);
                }
                return true;
            }
        }
    }

    bool canMove(Player Pl){

        vector<pair<int,int> > pecas;
        if(Pl == W) pecas = pecasW;
        else pecas = pecasB;

        for (int i = 0; i < pecas.size(); i++)
            {   
                int lin, col;
                lin = pecas[i].first;
                col = pecas[i].second;
                for (int i = 0; i < 8; i++)
                {
                    for (int j = 0; j < 8; j++)
                    {
                        if ((i + j) % 2 == 1)
                        {
                            if (isValid(lin, col, i, j, Pl))
                            {
                                return true;
                            }
                        }
                    }
                }
            }
            if(Pl == W) qntWhite = 0;
            else qntBlack = 0;
            return false;
    }

    void ComputerPlay(Player Pl)
    {
        Player Comp;
        // int last[4]; Para ser sempre a ultima jogada valida
        vector<pair<pair<int, int>, pair<int, int>>> jogadas; // para ser aleatorio
        int addLin;
        if (Pl == W)
        {
            Comp = B;
            addLin = -1;
        }
        else
        {
            Comp = W, addLin = 1;
        }
        if (Comp == W)
        {
            for (int i = 0; pecasW.size() > i; i++)
            {
                int lin, col;
                lin = pecasW[i].first;
                col = pecasW[i].second;
                for (int i = 0; i < 8; i++)
                {
                    for (int j = 0; j < 8; j++)
                    {
                        if ((i + j) % 2 == 1)
                        {
                            if (isValid(lin, col, i, j, Comp) == 2)
                            {

                                Jogada(lin, col, i, j, Comp, comp);
                                playWithCapture();
                                imprimir();
                                return;
                            }
                            if (isValid(lin, col, i, j, Comp) == 1)
                            {
                                pair<pair<int, int>, pair<int, int>> last;
                                pair<int, int> inicio;
                                pair<int, int> fim;
                                inicio.first = lin;
                                inicio.second = col;
                                fim.first = i;
                                fim.second = j;
                                last.first = inicio;
                                last.second = fim;
                                jogadas.push_back(last);
                            }
                        }
                    }
                }
            }
        }
        else
        {
            for (int i = 0; pecasB.size() > i; i++)
            {
                int lin, col;
                lin = pecasB[i].first;
                col = pecasB[i].second;
                for (int i = 0; i < 8; i++)
                {
                    for (int j = 0; j < 8; j++)
                    {
                        if ((i + j) % 2 == 1)
                        {
                            if (isValid(lin, col, i, j, Comp) == 2)
                            {

                                Jogada(lin, col, i, j, Comp, comp);
                                playWithCapture();
                                imprimir();
                                return;
                            }
                            if (isValid(lin, col, i, j, Comp) == 1)
                            {
                                pair<pair<int, int>, pair<int, int>> last;
                                pair<int, int> inicio;
                                pair<int, int> fim;
                                inicio.first = lin;
                                inicio.second = col;
                                fim.first = i;
                                fim.second = j;
                                last.first = inicio;
                                last.second = fim;
                                jogadas.push_back(last);
                            }
                        }
                    }
                }
            }
        }
        // Jogada(last[0],last[1],last[2],last[3],Comp,comp);
        srand(time(0));
        if(jogadas.size() == 0){
            if(Comp == W) qntWhite = 0;
            else qntBlack = 0;
            termino();
            return;
        }
        random_shuffle(jogadas.begin(), jogadas.end());
        auto it = jogadas.begin();
        pair<pair<int, int>, pair<int, int>> aleatoria = (*it);
        Jogada(aleatoria.first.first, aleatoria.first.second, aleatoria.second.first, aleatoria.second.second, Comp, comp);
        playWithNoCapture();
        imprimir();
        return;
    }


    bool termino()
    {
        int countB = getQuantidadeB();
        int countW = getQuantidadeW();

        if (countB == 0)
        {
            cout << "White WIN"<<endl;
            return true;
        }
        if (countW == 0)
        {
            cout << "Black WIN"<<endl;
            return true;
        }
        if(count == 20){
            cout<<"Tie"<<endl;
            return true;
        }
        return false;
    }

    Peca &getElement(int i, int j)
    {
        return tabuleiro[i][j];
    }

    string getText(int i, int j)
    {
        return (tabuleiro[i][j].getTipo());
    }

    ~Tabuleiro()
    {
        for (int i = 0; 8 > i; i++)
        {
            delete[] tabuleiro[i];
        }
        delete[] tabuleiro;
    }
};
bool isGameBegin = false;
bool isGameOver = false;

int main()
{

    Tabuleiro p;
    Opponent Op = frnd;
    Player Pl = W;
    vector<CircleShape> validPositions;

    /////tamanho da janela
    RenderWindow window(VideoMode(500, 500), "Main Menu");
    
    // definindo as imagens de fundo
    Sprite background;
    Texture backGroundTexture, texturaTeste, backGroundTextureMenu;
    Image image;
    //menu principal
    if (!backGroundTextureMenu.loadFromFile(mainMenu))
    {
        cout << "Erro ao carregar o Menu" << endl;
        return 2;
    }
    //tabuleiro
    if (!backGroundTexture.loadFromFile("images/checker_board.jpg"))
    {
        cout << "Erro ao carregar o tabuleiro" << endl;
        return 2;
    }
    backGroundTexture.setSmooth(true);
    backGroundTextureMenu.setSmooth(true);
    background.setTexture(backGroundTextureMenu);

    CircleShape casaPossivel(10),teste(20);
    casaPossivel.setFillColor(Color(216, 216, 191, 200));

    // definindo som do movimento
    SoundBuffer buffer;
    if(!buffer.loadFromFile("resources/moving.wav")){
        cout<<"Erro ao carregar o som de movimento da peça"<<endl;
        return 2;
    }

    Sound sound;
    sound.setBuffer(buffer);

    
    while (window.isOpen())
    {
        Event event;
        while (window.pollEvent(event))
        {   
            if (event.type == Event::Closed) //Se a janela for fechada
                window.close();
            if(isGameOver) break;
            else if (event.type == Event::MouseButtonPressed)// se algum botão do mouse for clicado
            {
                if (event.mouseButton.button == Mouse::Left)// se for o esquerdo
                {
                    if (!isGameBegin) // Se o jogo ainda não tiver começado
                    {
                        if ((Mouse::getPosition(window).x >= 250)) // Escolhe o computador
                        {
                            Op = frnd;
                            cout << "FRND\n";
                        }
                        else // escolhe um friend
                        {
                            Op = comp;
                            cout << "PC\n";
                        }
                        window.setTitle("Damas");
                        isGameBegin = true;
                        break;
                    }
                    if (!isGameBegin) // para manter renderizando a tela de escolha
                        break;

                    // Avalia se a posição do cursor do mouse esta em uma casa valida
                    if ((Mouse::getPosition(window).x >= 50) && (Mouse::getPosition(window).x <= 450) && (Mouse::getPosition(window).y >= 50) && (Mouse::getPosition(window).y <= 450))
                    {
                        int x = (Mouse::getPosition(window).x - 50) / 52;
                        int y = (Mouse::getPosition(window).y - 50) / 50;
                        int destX, destY;

                        window.display();
                        while (Mouse::isButtonPressed(Mouse::Left)) // aguarda o mouse deixar de esta pressionado
                        {
                        }
                        /// verificar as casas validas para se jogar ///
                        for (int i = 0; i < 8; i++)
                        {
                            for (int j = 0; j < 8; j++)
                            {
                                if ((i + j) % 2 == 1)
                                {
                                    if (p.isValid(y, x, i, j, Pl))
                                    {
                                        CircleShape temp(10);
                                        casaPossivel.setPosition(Vector2f(52 * (1 + j) + 10, 50 * (1 + i) + 10));
                                        window.draw(casaPossivel);
                                    }
                                }
                            }
                        }
                        window.display();

                        while (1)
                        {
                            if (Mouse::isButtonPressed(Mouse::Left)) // seleção da casa de destino
                            {
                                destX = (Mouse::getPosition(window).x - 50) / 52;
                                destY = (Mouse::getPosition(window).y - 50) / 50;
                                break;
                            }
                        }

                        if(p.isValid(y, x, destY, destX, Pl)==2){p.playWithCapture();} // se poder e capturar alguma peça  
                        if(p.isValid(y, x, destY, destX, Pl)==1){p.playWithNoCapture();} // se não há captura, mas a jogada é valida

                        if (p.Jogada(y, x, destY, destX, Pl, Op)) // realiza jogada
                        {   sound.play();
                            p.imprimir();
                            if (p.termino())
                            {
                                
                                if(p.getCount()==20){
                                    image.loadFromFile(draw);
                                }
                                else if (p.getQuantidadeB())
                                {
                                    image.loadFromFile(blackWin);
                                }
                                else if (p.getQuantidadeW())
                                {
                                    image.loadFromFile(whiteWin);
                                }
                                
                                backGroundTexture.loadFromImage(image);
                                background.setTexture(backGroundTexture, true);
                                isGameOver = true;
                            }
                            if(isGameOver) break;
                            //tipo de oponente
                            if (Op == frnd)
                            {
                                if (Pl == W)
                                    Pl = B;
                                else
                                    Pl = W;
                            }
                            else
                            {   
                                p.ComputerPlay(Pl);
                            }

                            if (p.termino() || !p.canMove(Pl)) // Caso o jogo tenha acabado
                            {                            // p.imprimir();
                                if(p.getCount()==20){
                                    image.loadFromFile(draw);
                                }
                                else if (p.getQuantidadeB())
                                {
                                    image.loadFromFile(blackWin);
                                }
                                else if (p.getQuantidadeW())
                                {
                                    image.loadFromFile(whiteWin);
                                }
                                backGroundTexture.loadFromImage(image);
                                background.setTexture(backGroundTexture, true);
                                isGameOver = true;
                            }
                            break;
                        }
                        break;
                    }
                }
            }
            if (!isGameBegin)
                break;
        }

        //renderizar o momento atual da partida
        window.clear();
        if(isGameOver){
            window.draw(background);
        }
        else if (isGameBegin)// Se o jogo tiver começado
        {   background.setTexture(backGroundTexture);
            window.draw(background);
            for (int i = 0; i < 8; i++)
            {
                for (int j = 0; j < 8; j++)
                {
                    if ((p.getElement(i, j)).getPlayer() != V)
                    {
                        if (!texturaTeste.loadFromFile(p.getText(i, j)))
                        {
                            cout << "Erro ao renderizar pecas do tabuleiro" << endl;
                            return 1;
                        }
                        texturaTeste.setSmooth(true);
                        teste.setTexture(&texturaTeste);
                        teste.setPosition(Vector2f(50 + 52 * j, 50 + 50 * i));
                        teste.setOutlineColor(Color(254, 254, 254, 100));
                        teste.setOutlineThickness(0);
                        if ((p.getElement(i, j)).getPlayer() == Pl)
                            teste.setOutlineThickness(2);
                        window.draw(teste);
                    }
                }
            }
        }
        else // caso o jogo ainda não tenha começado
            window.draw(background);

        window.display();
    }

    return 0;
}
