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

struct cvu_rle_state
{
	unsigned char (*input)(void);
	unsigned char escape;
	unsigned char left;
	unsigned char buffer;
};

unsigned char cvu_get_rle(struct cvu_rle_state *state);

struct cvu_compression_state
{
	struct cvu_huffman_state huffman;
	struct cvu_rle_state rle;
	const unsigned char *data;
};

extern struct cvu_compression_state *_common_state;

void *cvu_memcpy_compression(void *dest, struct cvu_compression_state *state, unsigned short int n)
{
	unsigned short int i = 0;
	_common_state = state;
	for(; n > 0; n--)
		((unsigned char *)(dest))[i++] = cvu_get_rle(&_common_state->rle);
}

