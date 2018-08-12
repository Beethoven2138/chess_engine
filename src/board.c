#include <board.h>

int *init_game(void)
{
	int *ret = (int*)malloc(sizeof(int) * 12 * 12);

	memset(ret, INVALID, 24 * sizeof(int));
	for (int i = 0; i < 8; ++i)
	{
		ret[24 + i * 12] = ret[25 + i * 12] = ret[34 + i * 12] = ret[35 + i * 12] = INVALID;
		if (i > 1 && i < 6)
			memset(ret + 26 + i * 12, EMPTY, 8 * sizeof(int));
	}
	memset(ret + 10 * 12, INVALID, 24 * sizeof(int));

	ret[26]=ROOK | BLACK;ret[27]=KNIGHT | BLACK;ret[28]=BISHOP | BLACK;ret[29]=KING | BLACK;ret[30]=QUEEN | BLACK;ret[31]=BISHOP | BLACK;ret[32]=KNIGHT | BLACK;ret[33]=ROOK | BLACK;ret[38]=PAWN | BLACK;ret[39]=PAWN | BLACK;ret[40]=PAWN | BLACK;ret[41]=PAWN | BLACK;ret[42]=PAWN | BLACK;ret[43]=PAWN | BLACK;ret[44]=PAWN | BLACK;ret[45]=PAWN | BLACK;ret[98]=PAWN;ret[99]=PAWN;ret[100]=PAWN;ret[101]=PAWN;ret[102]=PAWN;ret[103]=PAWN;ret[104]=PAWN;ret[105]=PAWN;ret[109]=ROOK;ret[110]=KNIGHT;ret[111]=BISHOP;ret[112]=KING;ret[113]=QUEEN;ret[114]=BISHOP;ret[115]=KNIGHT;ret[116]=ROOK;

	return ret;
}

static MOVE *diagonal_moves(int *board, CORD square, char color /*black = 1*/, char king)
{
	MOVE *ret = NULL;
	MOVE *node = NULL;
	for (int i = 1; (king)?2:(i < 12 - square.y); ++i)
	{
		int piece = board[26 + (square.y+i)*12 + square.x+i];
		if (piece != INVALID && (DIFFERENT_COLOR(piece, color) || piece == EMPTY))
		{
			if (node == NULL)
			{
				node = (MOVE*)malloc(sizeof(MOVE));
				ret = node;
			}
			else
			{
				node->next = (MOVE*)malloc(sizeof(MOVE));
				node = node->next;
			}
			node->start.x = square.x;node->start.y = square.y;
			node->end.x = square.x+i;node->end.y = square.y+i;
			node->next = NULL;
		}
	        piece = board[26 + (square.y-i)*12 + square.x+i];
		if (piece != INVALID && (DIFFERENT_COLOR(piece, color) || piece == EMPTY))
		{
			if (node == NULL)
			{
				node = (MOVE*)malloc(sizeof(MOVE));
				ret = node;
			}
			else
			{
				node->next = (MOVE*)malloc(sizeof(MOVE));
				node = node->next;
			}
			node->start.x = square.x;node->start.y = square.y;
			node->end.x = square.x+i;node->end.y = square.y+i;
			node->next = NULL;
		}
		piece = board[26 + (square.y+i)*12 + square.x-i];
		if (piece != INVALID && (DIFFERENT_COLOR(piece, color) || piece == EMPTY))
		{
			if (node == NULL)
			{
				node = (MOVE*)malloc(sizeof(MOVE));
				ret = node;
			}
			else
			{
				node->next = (MOVE*)malloc(sizeof(MOVE));
				node = node->next;
			}
			node->start.x = square.x;node->start.y = square.y;
			node->end.x = square.x+i;node->end.y = square.y+i;
			node->next = NULL;
		}
		piece = board[26 + (square.y-i)*12 + square.x-i];
		if (piece != INVALID && (DIFFERENT_COLOR(piece, color) || piece == EMPTY))
		{
			if (node == NULL)
			{
				node = (MOVE*)malloc(sizeof(MOVE));
				ret = node;
			}
			else
			{
				node->next = (MOVE*)malloc(sizeof(MOVE));
				node = node->next;
			}
			node->start.x = square.x;node->start.y = square.y;
			node->end.x = square.x+i;node->end.y = square.y+i;
			node->next = NULL;
		}
	}
	return ret;
}

static MOVE *straight_moves(int *board, CORD square, char color /*black = 1*/, char king)
{
	MOVE *ret = NULL;
	MOVE *node = NULL;
	for (int i = 1; (king)?2:(i < 12 - square.y); ++i)
	{
		int piece = board[26 + square.y*12 + square.x+i];
		if (piece != INVALID && (DIFFERENT_COLOR(piece, color) || piece == EMPTY))
		{
			if (node == NULL)
			{
				node = (MOVE*)malloc(sizeof(MOVE));
				ret = node;
			}
			else
			{
				node->next = (MOVE*)malloc(sizeof(MOVE));
				node = node->next;
			}
			node->start.x = square.x;node->start.y = square.y;
			node->end.x = square.x+i;node->end.y = square.y+i;
			node->next = NULL;
		}
	        piece = board[26 + square.y*12 + square.x-i];
		if (piece != INVALID && (DIFFERENT_COLOR(piece, color) || piece == EMPTY))
		{
			if (node == NULL)
			{
				node = (MOVE*)malloc(sizeof(MOVE));
				ret = node;
			}
			else
			{
				node->next = (MOVE*)malloc(sizeof(MOVE));
				node = node->next;
			}
			node->start.x = square.x;node->start.y = square.y;
			node->end.x = square.x+i;node->end.y = square.y+i;
			node->next = NULL;
		}
		piece = board[26 + (square.y+i)*12 + square.x];
		if (piece != INVALID && (DIFFERENT_COLOR(piece, color) || piece == EMPTY))
		{
			if (node == NULL)
			{
				node = (MOVE*)malloc(sizeof(MOVE));
				ret = node;
			}
			else
			{
				node->next = (MOVE*)malloc(sizeof(MOVE));
				node = node->next;
			}
			node->start.x = square.x;node->start.y = square.y;
			node->end.x = square.x+i;node->end.y = square.y+i;
			node->next = NULL;
		}
		piece = board[26 + (square.y-i)*12 + square.x];
		if (piece != INVALID && (DIFFERENT_COLOR(piece, color) || piece == EMPTY))
		{
			if (node == NULL)
			{
				node = (MOVE*)malloc(sizeof(MOVE));
				ret = node;
			}
			else
			{
				node->next = (MOVE*)malloc(sizeof(MOVE));
				node = node->next;
			}
			node->start.x = square.x;node->start.y = square.y;
			node->end.x = square.x+i;node->end.y = square.y+i;
			node->next = NULL;
		}
	}
	return ret;
}

static MOVE *l_moves(int *board, CORD square, char color /*black = 1*/)
{
	MOVE *ret = NULL;
	MOVE *node = NULL;

	int piece = board[26 + (square.y+2)*12 + square.x+1];
	if (piece != INVALID && (DIFFERENT_COLOR(piece, color) || piece == EMPTY))
	{
		if (node == NULL)
		{
			node = (MOVE*)malloc(sizeof(MOVE));
			ret = node;
		}
		else
		{
			node->next = (MOVE*)malloc(sizeof(MOVE));
			node = node->next;
		}
		node->start.x = square.x;node->start.y = square.y;
		node->end.x = square.x+1;node->end.y = square.y+2;
		node->next = NULL;
	}
	piece = board[26 + (square.y+2)*12 + square.x-1];
	if (piece != INVALID && (DIFFERENT_COLOR(piece, color) || piece == EMPTY))
	{
		if (node == NULL)
		{
			node = (MOVE*)malloc(sizeof(MOVE));
			ret = node;
		}
		else
		{
			node->next = (MOVE*)malloc(sizeof(MOVE));
			node = node->next;
		}
		node->start.x = square.x;node->start.y = square.y;
		node->end.x = square.x-1;node->end.y = square.y+2;
		node->next = NULL;
	}
	piece = board[26 + (square.y-2)*12 + square.x+1];
	if (piece != INVALID && (DIFFERENT_COLOR(piece, color) || piece == EMPTY))
	{
		if (node == NULL)
		{
			node = (MOVE*)malloc(sizeof(MOVE));
			ret = node;
		}
		else
		{
			node->next = (MOVE*)malloc(sizeof(MOVE));
			node = node->next;
		}
		node->start.x = square.x;node->start.y = square.y;
		node->end.x = square.x+1;node->end.y = square.y-2;
		node->next = NULL;
	}
	piece = board[26 + (square.y-2)*12 + square.x-1];
	if (piece != INVALID && (DIFFERENT_COLOR(piece, color) || piece == EMPTY))
	{
		if (node == NULL)
		{
			node = (MOVE*)malloc(sizeof(MOVE));
			ret = node;
		}
		else
		{
			node->next = (MOVE*)malloc(sizeof(MOVE));
			node = node->next;
		}
		node->start.x = square.x;node->start.y = square.y;
		node->end.x = square.x-1;node->end.y = square.y-2;
		node->next = NULL;
	}
	piece = board[26 + (square.y-1)*12 + square.x-2];
	if (piece != INVALID && (DIFFERENT_COLOR(piece, color) || piece == EMPTY))
	{
		if (node == NULL)
		{
			node = (MOVE*)malloc(sizeof(MOVE));
			ret = node;
		}
		else
		{
			node->next = (MOVE*)malloc(sizeof(MOVE));
			node = node->next;
		}
		node->start.x = square.x;node->start.y = square.y;
		node->end.x = square.x-2;node->end.y = square.y-1;
		node->next = NULL;
	}
	piece = board[26 + (square.y-1)*12 + square.x+2];
	if (piece != INVALID && (DIFFERENT_COLOR(piece, color) || piece == EMPTY))
	{
		if (node == NULL)
		{
			node = (MOVE*)malloc(sizeof(MOVE));
			ret = node;
		}
		else
		{
			node->next = (MOVE*)malloc(sizeof(MOVE));
			node = node->next;
		}
		node->start.x = square.x;node->start.y = square.y;
		node->end.x = square.x+2;node->end.y = square.y-1;
		node->next = NULL;
	}
	piece = board[26 + (square.y+1)*12 + square.x-2];
	if (piece != INVALID && (DIFFERENT_COLOR(piece, color) || piece == EMPTY))
	{
		if (node == NULL)
		{
			node = (MOVE*)malloc(sizeof(MOVE));
			ret = node;
		}
		else
		{
			node->next = (MOVE*)malloc(sizeof(MOVE));
			node = node->next;
		}
		node->start.x = square.x;node->start.y = square.y;
		node->end.x = square.x-2;node->end.y = square.y+1;
		node->next = NULL;
	}
	piece = board[26 + (square.y+1)*12 + square.x+2];
	if (piece != INVALID && (DIFFERENT_COLOR(piece, color) || piece == EMPTY))
	{
		if (node == NULL)
		{
			node = (MOVE*)malloc(sizeof(MOVE));
			ret = node;
		}
		else
		{
			node->next = (MOVE*)malloc(sizeof(MOVE));
			node = node->next;
		}
		node->start.x = square.x;node->start.y = square.y;
		node->end.x = square.x+2;node->end.y = square.y+1;
		node->next = NULL;
	}
	return ret;
}

static MOVE *bishop_moves(int *board, CORD square)
{
	MOVE *ret = NULL;
	int piece = board[26 + square.y * 12 + square.x];
	if (piece == BISHOP)
		ret = diagonal_moves(board, square, IS_BLACK(piece), 0);
	return ret;
}

static MOVE *knight_moves(int *board, CORD square)
{
	MOVE *ret = NULL;
	int piece = board[26 + square.y * 12 + square.x];
	if (piece == KNIGHT)
		ret = l_moves(board, square, IS_BLACK(piece));
	return ret;
}

static MOVE *queen_moves(int *board, CORD square)
{
	MOVE *ret = NULL;
	int piece = board[26 + square.y * 12 + square.x];
	if (piece == QUEEN)
	{
		char color = IS_BLACK(piece);
		ret = diagonal_moves(board, square, color, 0);
		MOVE *tmp = ret;
		while (tmp->next != NULL)
			tmp = tmp->next;
		tmp->next = straight_moves(board, square, color, 0);
	}
	return ret;
}

static MOVE *king_moves(int *board, CORD square)
{
	MOVE *ret = NULL;
	int piece = board[26 + square.y * 12 + square.x];
	if (piece == KING)
	{
		char color = IS_BLACK(piece);
		ret = diagonal_moves(board, square, color, 1);
		MOVE *tmp = ret;
		while (tmp->next != NULL)
			tmp = tmp->next;
		tmp->next = straight_moves(board, square, color, 1);
	}
	return ret;
}

static MOVE *rook_moves(int *board, CORD square)
{
	MOVE *ret = NULL;
	int piece = board[26 + square.y * 12 + square.x];
	if (piece == ROOK)
	{
		char color = IS_BLACK(piece);
		ret = straight_moves(board, square, color, 0);
	}
	return ret;
}

static MOVE *pawn_moves(int *board, CORD square)
{
	MOVE *ret = NULL;
	int piece = board[26 + square.y * 12 + square.x];
	if (piece == PAWN)
	{
		MOVE *node = NULL;
		char color = IS_BLACK(piece);
		int tmp_piece;
		if (color == WHITE)
		{
			tmp_piece = board[26 + (square.y-1) * 12 + square.x];
			if (tmp_piece == EMPTY)
			{
				if (node == NULL)
				{
					node = (MOVE*)malloc(sizeof(MOVE));
					ret = node;
				}
				else
				{
					node->next = (MOVE*)malloc(sizeof(MOVE));
					node = node->next;
				}
				node->start.x = square.x;node->start.y = square.y;
				node->end.x = square.x;node->end.y = square.y-1;
				node->next = NULL;
				tmp_piece = board[26 + (square.y-2) * 12 + square.x];
				if (tmp_piece == EMPTY)
				{
					if (node == NULL)
					{
						node = (MOVE*)malloc(sizeof(MOVE));
						ret = node;
					}
					else
					{
						node->next = (MOVE*)malloc(sizeof(MOVE));
						node = node->next;
					}
					node->start.x = square.x;node->start.y = square.y;
					node->end.x = square.x;node->end.y = square.y-2;
					node->next = NULL;
				}
			}
			tmp_piece = board[26 + (square.y-1) * 12 + square.x-1];
			if (tmp_piece != EMPTY && tmp_piece != INVALID && DIFFERENT_COLOR(tmp_piece, color))
			{
				if (node == NULL)
				{
					node = (MOVE*)malloc(sizeof(MOVE));
					ret = node;
				}
				else
				{
					node->next = (MOVE*)malloc(sizeof(MOVE));
					node = node->next;
				}
				node->start.x = square.x;node->start.y = square.y;
				node->end.x = square.x-1;node->end.y = square.y-1;
				node->next = NULL;
			}
			tmp_piece = board[26 + (square.y-1) * 12 + square.x+1];
			if (tmp_piece != EMPTY && tmp_piece != INVALID && DIFFERENT_COLOR(tmp_piece, color))
			{
				if (node == NULL)
				{
					node = (MOVE*)malloc(sizeof(MOVE));
					ret = node;
				}
				else
				{
					node->next = (MOVE*)malloc(sizeof(MOVE));
					node = node->next;
				}
				node->start.x = square.x;node->start.y = square.y;
				node->end.x = square.x+1;node->end.y = square.y-1;
				node->next = NULL;
			}
		}
		else
		{
			tmp_piece = board[26 + (square.y+1) * 12 + square.x];
			if (tmp_piece == EMPTY)
			{
				if (node == NULL)
				{
					node = (MOVE*)malloc(sizeof(MOVE));
					ret = node;
				}
				else
				{
					node->next = (MOVE*)malloc(sizeof(MOVE));
					node = node->next;
				}
				node->start.x = square.x;node->start.y = square.y;
				node->end.x = square.x;node->end.y = square.y+1;
				node->next = NULL;
				tmp_piece = board[26 + (square.y+2) * 12 + square.x];
				if (tmp_piece == EMPTY)
				{
					if (node == NULL)
					{
						node = (MOVE*)malloc(sizeof(MOVE));
						ret = node;
					}
					else
					{
						node->next = (MOVE*)malloc(sizeof(MOVE));
						node = node->next;
					}
					node->start.x = square.x;node->start.y = square.y;
					node->end.x = square.x;node->end.y = square.y+2;
					node->next = NULL;
				}
			}
			tmp_piece = board[26 + (square.y+1) * 12 + square.x-1];
			if (tmp_piece != EMPTY && tmp_piece != INVALID && DIFFERENT_COLOR(tmp_piece, color))
			{
				if (node == NULL)
				{
					node = (MOVE*)malloc(sizeof(MOVE));
					ret = node;
				}
				else
				{
					node->next = (MOVE*)malloc(sizeof(MOVE));
					node = node->next;
				}
				node->start.x = square.x;node->start.y = square.y;
				node->end.x = square.x-1;node->end.y = square.y+1;
				node->next = NULL;
			}
			tmp_piece = board[26 + (square.y+1) * 12 + square.x+1];
			if (tmp_piece != EMPTY && tmp_piece != INVALID && DIFFERENT_COLOR(tmp_piece, color))
			{
				if (node == NULL)
				{
					node = (MOVE*)malloc(sizeof(MOVE));
					ret = node;
				}
				else
				{
					node->next = (MOVE*)malloc(sizeof(MOVE));
					node = node->next;
				}
				node->start.x = square.x;node->start.y = square.y;
				node->end.x = square.x+1;node->end.y = square.y+1;
				node->next = NULL;
			}
		}
	}
	return ret;
}

MOVE *find_legal_moves(int *board, char color)
{
	MOVE *ret = NULL;
	MOVE *node = NULL;
        for (int y = 0; y < 8; ++y)
	{
		for (int x = 0; x < 8; ++x)
		{
			int tmp_piece = board[26 + x + y*12];
			if (IS_BLACK(tmp_piece) == color)
			{
				CORD tmp_c;tmp_c.x=x+2;tmp_c.y=y+2;
				MOVE *tmp_node = NULL;
				switch (tmp_piece & 0xF)
				{
				case PAWN:
					tmp_node = pawn_moves(board, tmp_c);
					break;
				case ROOK:
					tmp_node = rook_moves(board, tmp_c);
					break;
				case KING:
					tmp_node = king_moves(board, tmp_c);
					break;
				case QUEEN:
					tmp_node = queen_moves(board, tmp_c);
					break;
				case BISHOP:
					tmp_node = bishop_moves(board, tmp_c);
					break;
				case KNIGHT:
					tmp_node = knight_moves(board, tmp_c);
					break;
				default:
					break;
				}
				if (tmp_node != NULL)
				{
					if (node == NULL)
					        ret = node = tmp_node;
					else
					{
						while (node->next != NULL)
							node = node->next;
						node->next = tmp_node;
					}
				}
			}
		}
	}
	return ret;
}

void make_move(int *board, MOVE move);
int get_value(int *board, char side_to_move);

void print_board(int *board, char perspective);
