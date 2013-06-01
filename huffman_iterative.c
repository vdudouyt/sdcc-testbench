struct cvu_huffman_node
{
        unsigned char left;   /* Position of left node in tree or character. */
        unsigned char right;  /* Position of right node in tree or character. */
};

struct cvu_huffman_state
{
	unsigned char (*input)(void);
	const struct cvu_huffman_node *nodes;	/* Array of nodes */
	unsigned char root;	/* Position of root node among nodes */
	unsigned char ls, bs, rs;
	unsigned char bit;	/* Position of currently processed bit */
	unsigned char buffer;	/* Currently processed input byte */
};

unsigned char cvu_get_huffman(struct cvu_huffman_state *state)
{
	unsigned char current;
	unsigned char ret;

	current = state->root;

	for(;;)
	{
		state->buffer >>= 1;
		if(state->bit == 8)
		{
			state->buffer = (state->input)();
			state->bit = 0;
		}
		state->bit++;

		if(!(state->buffer & 0x01))	/* Left */
		{
			if(current >= state->ls && current < state->rs)
			{
				ret = state->nodes[current].left;
				break;
			}

			current = state->nodes[current].left;
		}
		else	/* Right */
		{
			if(current >= state->bs)
			{
				ret = state->nodes[current].right;
				break;
			}

			current = state->nodes[current].right;
		}
	}
	
	return(ret);
}

