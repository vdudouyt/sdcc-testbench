enum cv_screenmode {
  CV_SCREENMODE_STANDARD = 0x00,               // Standard screen modes
  CV_SCREENMODE_TEXT = 0x10,
  CV_SCREENMODE_MULTICOLOR = 0x08,
  CV_SCREENMODE_BITMAP = 0x02,
  CV_SCREENMODE_BITMAP_TEXT = 0x12,           // Usefull undocumented screen modes
  CV_SCREENMODE_BITMAP_MULTICOLOR = 0x0a,
  CV_SCREENMODE_TEXT_MULTICOLOR = 0x18,       // Useless undocumented screen modes
  CV_SCREENMODE_BITMAP_TEXT_MULTICOLOR = 0x1a
};

extern void cv_set_write_vram_address(unsigned short int address);

extern void cv_memtovmemcpy_fast(const void *src, unsigned short int n);
extern void cv_memtovmemcpy_slow(const void *src, unsigned short int n);

extern unsigned char cv_get_screen_active(void);
extern enum cv_screenmode cv_get_screen_mode(void);

void cvu_memtovmemcpy(unsigned short int dest, const void * src, unsigned short int n)
{
  cv_set_write_vram_address(dest);
  if(cv_get_screen_active() &&
    ((cv_get_screen_mode() == CV_SCREENMODE_STANDARD) ||
    (cv_get_screen_mode() == CV_SCREENMODE_BITMAP)))
    cv_memtovmemcpy_slow(src, n);
  else
    cv_memtovmemcpy_fast(src, n);
}

