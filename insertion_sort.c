struct cvu_sprite
{
	unsigned char y;
	unsigned char x;
	unsigned char name;
	unsigned char tag;
};

extern int cvu_get_sprite_y(const struct cvu_sprite *sprite);

typedef unsigned char spm_sprite;
#define SPM_MAX_SPRITES 18
#define spm_get_sprite(i) (spm_sprites + (i))

struct cvu_sprite spm_sprites[SPM_MAX_SPRITES];
spm_sprite spm_sprites_list[SPM_MAX_SPRITES];

void spm_sort(void)
{
	unsigned char i, j;
	spm_sprite temp;
	int y;

	for(i = 1; i < SPM_MAX_SPRITES; i++)
	{
		j = i;
		temp = spm_sprites_list[j];
		y = cvu_get_sprite_y(spm_get_sprite(temp));
		while(j && y < cvu_get_sprite_y(spm_get_sprite(spm_sprites_list[j - 1])))
		{
			spm_sprites_list[j] = spm_sprites_list[j - 1];
			j--;		
		}
		spm_sprites_list[j] = temp;
	}
}

