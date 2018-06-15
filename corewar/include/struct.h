/*
** EPITECH PROJECT, 2017
** struct.h
** File description:
** Arthur
*/

#ifndef STRUCT_H_
#define STRUCT_H_

typedef struct instructions instructions;
typedef struct arg_champ arg_champ;

typedef struct circular_memory
{
	char	*memory;
	char	*memory_head;
	char	*memory_end;
	char	**champ_name;
	int	size;
	int	nbr_live;
	int	last_live;
} circular_memory;

struct arg_champ
{
	int		nbr_champ;
	int		hyp_a;
	int		hyp_n;
	char		*cor;
	arg_champ	*next;
};

struct instructions
{
	char			*mnemonique;
	char			*name;
	unsigned char		adr;
	int			nb_cycles;
	int			arg1;
	int			arg2;
	int			arg3;
	int			types;
	instructions		*next;
};

typedef struct champions
{
	instructions	*list;
	int		*registers;
	char		*name;
	char		*PC;
	char		*tmp;
	char		*end;
	int		carry;
	int		cycle;
	int		inst;
	int		types;
	int		alive;
	int		nb_live;
} champions;

typedef struct arguments
{
	int	cor;
} arguments;

union endian
{
	char	byte[4];
	int	val;
};

#endif
