extern void cv_set_read_vram_address(unsigned short int);
extern unsigned char cv_vinb(void);

unsigned char cvu_vinb(const unsigned short int dest)
{
	cv_set_read_vram_address(dest);
	return(cv_vinb());
}

