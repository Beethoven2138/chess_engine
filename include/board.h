#ifndef __BOARD_H
#define __BOARD_H

#include <string.h>
#include <stdlib.h>
#include <stdio.h>

enum pieces
{
	EMPTY = 1,
	PAWN,
	ROOK,
	KING,
	QUEEN,
	BISHOP,
	KNIGHT,
};

#define INVALID 0

//THESE MUST NOT BE CHANGED!!!
#define WHITE 0
#define BLACK 1 << 31
#define IS_BLACK(a) ((a & BLACK) >> 31)
#define IS_WHITE(a) (!((a & BLACK) >> 31))
#define SAME_COLOR(a/*piece with color offset by 31*/, b) (((a >> 31) ^ b) == 0)
#define DIFFERENT_COLOR(a/*piece with color offset by 31*/, b) (((a >> 31) ^ b) == 1)

//absolute
typedef struct _cord
{
	short x, y;
} CORD;

typedef struct _move
{
	CORD start, end;
	struct _move *next;
} MOVE;

//board's gonna be 12 * 12, white at 0,0 from downwards perspective

static MOVE *diagonal_moves(int *board, CORD square, char color /*black = 1*/, char king);
static MOVE *straight_moves(int *board, CORD square, char color /*black = 1*/, char king);
static MOVE *l_moves(int *board, CORD square, char color /*black = 1*/);

static MOVE *bishop_moves(int *board, CORD square);
static MOVE *knight_moves(int *board, CORD square);
static MOVE *queen_moves(int *board, CORD square);
static MOVE *king_moves(int *board, CORD square);
static MOVE *rook_moves(int *board, CORD square);
static MOVE *pawn_moves(int *board, CORD square);

int *init_game(void);
MOVE *find_legal_moves(int *board, char color);
void make_move(int *board, MOVE move);
int get_value(int *board, char side_to_move);

void print_board(int *board, char perspective);

#endif
