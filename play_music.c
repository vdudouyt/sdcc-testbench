unsigned char cv_get_vint_frequency(void);

enum cv_soundchannel {
  CV_SOUNDCHANNEL_0 = 0x0,
  CV_SOUNDCHANNEL_1 = 0x2,
  CV_SOUNDCHANNEL_2 = 0x4,
  CV_SOUNDCHANNEL_NOISE = 0x6
};

extern void cv_set_attenuation(enum cv_soundchannel channel, unsigned char dezibel);
extern void cv_set_frequency(enum cv_soundchannel channel, unsigned short int frequency_divider);

struct cvu_music
{
	enum cv_soundchannel channel;
	const unsigned char *volume;
	const unsigned short int *tuning;
	unsigned char sixteenth_notes_per_second;
	const unsigned short int *notes;
	
	unsigned short int note_vint_remaining;
	unsigned short int pause_vint_remaining;
};

unsigned char cvu_play_music(struct cvu_music *music)
{
	if(music->note_vint_remaining)
	{
		music->note_vint_remaining--;
	}
	else if(music->pause_vint_remaining)
	{
		cv_set_attenuation(music->channel, 0);
		music->pause_vint_remaining--;
	}
	else
	{
		unsigned char pause = 0;
		const unsigned short note = *(music->notes);

		cv_set_attenuation(music->channel, 0);

		if(note== 0xffff)
			return(0);

		/* Length calculations:*/
		{
			unsigned char length, rel_length;

			length = (note >> 4) & 0xf;
			if(!length)
				length = 0x10;
			music->note_vint_remaining = length;
			music->note_vint_remaining *= cv_get_vint_frequency();
			music->note_vint_remaining /= music->sixteenth_notes_per_second;

			rel_length = (note >> 2) & 0x3;
			switch(rel_length)
			{
			case 0:	/* Legato */
				break;
			case 1:	/* Staccato */
				music->pause_vint_remaining = music->note_vint_remaining;
				music->note_vint_remaining = music->note_vint_remaining >> 2;
				music->pause_vint_remaining -= music->note_vint_remaining;
				break;
			case 2:
				music->note_vint_remaining = music->note_vint_remaining >> 1;
				music->pause_vint_remaining = music->note_vint_remaining;
				break;
			default:	/* Standard */
				music->pause_vint_remaining = music->note_vint_remaining >> 2;
				music->note_vint_remaining -= music->pause_vint_remaining;
				break;
			}
		}
		
		/* Frequency calculations: */
		{
			unsigned char octave, halftone;
			unsigned short int frequency_divider;
			
			halftone = (note >> 8) & 0xf;
			pause = (halftone == 0xf);
			if(!pause)
			{
				frequency_divider = music->tuning[halftone];

				octave = (note >> 12);
				cv_set_frequency(music->channel, frequency_divider >> octave);
			}
		}

		/* Loudness calculations: */
		{
			cv_set_attenuation(music->channel, pause ? 0 : (music->volume[note & 0x3]));
		}
		music->notes++;
	}
	return(1);
}
