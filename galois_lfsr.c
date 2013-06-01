unsigned char spm_test(void)
{
	static unsigned char reg = 1;
	reg = ((reg & 1) ? (reg >> 1)^0xe1 : (reg >> 1));
	return(reg);
}

