#define SPM_MAX_SPRITES 19

typedef unsigned char spm_sprite;

spm_sprite spm_sprites_list[SPM_MAX_SPRITES];

void spm_destroy_sprite(const spm_sprite sprite);

void spm_init(void)
{
	spm_sprite i;
	for(i = 0; i < SPM_MAX_SPRITES; i++)
	{
		spm_destroy_sprite(i);
		spm_sprites_list[i] = i;
	}
}

