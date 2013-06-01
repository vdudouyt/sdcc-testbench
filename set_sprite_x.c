struct cvu_sprite
{
	unsigned char y;
	unsigned char x;
	unsigned char name;
	unsigned char tag;
};

void cvu_set_sprite_x(struct cvu_sprite *sprite, int x)
{
	if(x < -32)
		x = -32;
	if(x > 255)
		x = 255;
	if(x >= 0)
	{
		sprite->x = x;
		sprite->tag &= 0xf;
	}
	else
	{
		sprite->x = x + 32;
		sprite->tag |= 0x80;
	}
}

