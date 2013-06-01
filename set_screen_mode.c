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

extern void cv_vdpout(const unsigned char reg, const unsigned char data);  // Write data to VDP control register reg.

extern unsigned char cv_vdpreg[2];

void cv_set_screen_mode(enum cv_screenmode mode)
{
  cv_vdpout(0x0, cv_vdpreg[0] = (mode & 0x02) | (cv_vdpreg[0] & ~0x02));
  cv_vdpout(0x1, cv_vdpreg[1] = (mode & 0x18) | (cv_vdpreg[1] & ~0x18));
}
