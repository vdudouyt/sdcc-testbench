typedef long time_t;

struct tm {
	int tm_sec;
	int tm_min;
	int tm_hour;
	int tm_mday;
	int tm_mon;
	int tm_year;
	int tm_wday;
	int tm_yday;
	int tm_isdst;
};

#define EPOCH_YEAR 1970
#define SECS_PER_DAY  86400UL
#define SECS_PER_HOUR  3600UL
#define SECS_PER_MIN     60UL
#define DAYS_PER_YEAR   365UL

const int _tot[] = {
		0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334 };

extern int is_leap( int year );

time_t mktime(struct tm *tp)
{
    unsigned long days;
    int           i,j,year;

    if ( tp->tm_year  < EPOCH_YEAR - 1900 ) 
	return -1L;

    days = ( tp->tm_year - ( EPOCH_YEAR - 1900 ) ) * DAYS_PER_YEAR;

    /* Now chase up the leap years */
    for ( i = EPOCH_YEAR; i < ( tp->tm_year + 1900 ); i++ ) {
	if ( is_leap(i) )
		++days;
    }

    days += _tot[tp->tm_mon];
    if ( is_leap(tp->tm_year) )
	    ++days;

    days += (tp->tm_mday - 1);

    /* So days has the number of days since the epoch */
    days *= SECS_PER_DAY;
    

    days += ( tp->tm_hour * SECS_PER_HOUR ) + ( tp->tm_min * SECS_PER_MIN ) + tp->tm_sec;

    return days;
}

