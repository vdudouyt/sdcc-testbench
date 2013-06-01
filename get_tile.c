unsigned char rootseed;
unsigned char root;

extern unsigned char *expand_tile(const unsigned char t, unsigned char level, unsigned char seed);

extern unsigned char clampcoord(unsigned short int coord, unsigned char level);

unsigned char *get_tile(unsigned short int x, unsigned short int y, unsigned char level)
{
	unsigned char l = 0;
	unsigned char *t = &root;
	unsigned char seed = rootseed;
	unsigned char i;
	for(;;)
	{
		if(l == level)
			return(t);

		t = expand_tile(*t, l, seed);

		l++;
		i = clampcoord(y, l) * 8 + clampcoord(x, l);
	
		t += i;
		seed += i;
	}
}

