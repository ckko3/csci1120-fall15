class KnightsTour {
public:
    KnightsTour(int x, int y);
    void print() const;
    bool hasMoreMoves() const;
    bool isSolved() const;
    bool move(int x, int y);
    void lookAhead(int &r, int &c) const;

    const static int N = 6;
private:
    bool board[N][N];
    int posX, posY;
};
