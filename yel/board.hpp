#pragma once

#include "defs.hpp"
#include <vector>

namespace board {

constexpr Sqr NUM_OF_SQR = 120;
constexpr Sqr NUM_OF_PIECE = 13;

struct Board
{
	Sqr position[NUM_OF_SQR];
	std::vector<Sqr> pieces[NUM_OF_PIECE];
	uint8_t side {defs::BOTH};
	Sqr enPassant {0};
	uint8_t castle {0};
	int fiftyMove {0};
	int ply {0};
	int hply {0};
	int hash {0};
	std::vector<Move> moveHistory {};
	std::vector<defs::MoveVal> moves {};
	std::vector<int> histHash {};
	defs::MoveVal pv[32];
};

class Game
{
public:
	Game() = default;
	void init();
	void initMvvLva();
	void printBoard();
	void generateMove(bool isCaptureOnly);
	void genPawnMove(Sqr s, bool isCaptureOnly);
	void genCastlingMove(Piece pieceIndex);
	bool attacked(Sqr sqrAttacked, int side);
	void genPieceMove(Sqr from, Sqr to, Piece piece, bool isCapture);
	bool makeMove(Move move);
	void takeback();
	void setPositionKey();
	bool repeat();
	void clearPv(board::Game& game);
	void assetBoard();
	Board& getBoard() { return board; }
	Sqr startEnpassant = 0;
private:
	Board board;
	int MvvLvaScores[13][13];
};

}