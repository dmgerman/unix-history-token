begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1988 Regents of the University of California.  * All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * Arthur Olson.  *  * Redistribution and use in source and binary forms are permitted  * provided that the above copyright notice and this paragraph are  * duplicated in all such forms and that any documentation,  * advertising materials, and other materials related to such  * distribution and use acknowledge that the software was developed  * by the University of California, Berkeley.  The name of the  * University may not be used to endorse or promote products derived  * from this software without specific prior written permission.  * THIS SOFTWARE IS PROVIDED ``AS IS'' AND WITHOUT ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, WITHOUT LIMITATION, THE IMPLIED  * WARRANTIES OF MERCHANTIBILITY AND FITNESS FOR A PARTICULAR PURPOSE.  *  *	@(#)tzfile.h	5.7 (Berkeley) %G%  */
end_comment

begin_comment
comment|/* ** Information about time zone files. */
end_comment

begin_comment
comment|/* Time zone object file directory */
end_comment

begin_define
define|#
directive|define
name|TZDIR
value|"/usr/share/zoneinfo"
end_define

begin_define
define|#
directive|define
name|TZDEFAULT
value|"/etc/localtime"
end_define

begin_define
define|#
directive|define
name|TZDEFRULES
value|"posixrules"
end_define

begin_comment
comment|/* ** Each file begins with. . . */
end_comment

begin_struct
struct|struct
name|tzhead
block|{
name|char
name|tzh_reserved
index|[
literal|24
index|]
decl_stmt|;
comment|/* reserved for future use */
name|char
name|tzh_ttisstdcnt
index|[
literal|4
index|]
decl_stmt|;
comment|/* coded number of trans. time flags */
name|char
name|tzh_leapcnt
index|[
literal|4
index|]
decl_stmt|;
comment|/* coded number of leap seconds */
name|char
name|tzh_timecnt
index|[
literal|4
index|]
decl_stmt|;
comment|/* coded number of transition times */
name|char
name|tzh_typecnt
index|[
literal|4
index|]
decl_stmt|;
comment|/* coded number of local time types */
name|char
name|tzh_charcnt
index|[
literal|4
index|]
decl_stmt|;
comment|/* coded number of abbr. chars */
block|}
struct|;
end_struct

begin_comment
comment|/* ** . . .followed by. . . ** **	tzh_timecnt (char [4])s		coded transition times a la time(2) **	tzh_timecnt (unsigned char)s	types of local time starting at above **	tzh_typecnt repetitions of **		one (char [4])		coded GMT offset in seconds **		one (unsigned char)	used to set tm_isdst **		one (unsigned char)	that's an abbreviation list index **	tzh_charcnt (char)s		'\0'-terminated zone abbreviations **	tzh_leapcnt repetitions of **		one (char [4])		coded leap second transition times **		one (char [4])		total correction after above **	tzh_ttisstdcnt (char)s		indexed by type; if TRUE, transition **					time is standard time, if FALSE, **					transition time is wall clock time **					if absent, transition times are **					assumed to be wall clock time */
end_comment

begin_comment
comment|/* ** In the current implementation, "tzset()" refuses to deal with files that ** exceed any of the limits below. */
end_comment

begin_comment
comment|/* ** The TZ_MAX_TIMES value below is enough to handle a bit more than a ** year's worth of solar time (corrected daily to the nearest second) or ** 138 years of Pacific Presidential Election time ** (where there are three time zone transitions every fourth year). */
end_comment

begin_define
define|#
directive|define
name|TZ_MAX_TIMES
value|370
end_define

begin_define
define|#
directive|define
name|NOSOLAR
end_define

begin_comment
comment|/* 4BSD doesn't currently handle solar time */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|NOSOLAR
end_ifndef

begin_define
define|#
directive|define
name|TZ_MAX_TYPES
value|256
end_define

begin_comment
comment|/* Limited by what (unsigned char)'s can hold */
end_comment

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|TZ_MAX_TYPES
value|10
end_define

begin_comment
comment|/* Maximum number of local time types */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|TZ_MAX_CHARS
value|50
end_define

begin_comment
comment|/* Maximum number of abbreviation characters */
end_comment

begin_define
define|#
directive|define
name|TZ_MAX_LEAPS
value|50
end_define

begin_comment
comment|/* Maximum number of leap second corrections */
end_comment

begin_define
define|#
directive|define
name|SECSPERMIN
value|60
end_define

begin_define
define|#
directive|define
name|MINSPERHOUR
value|60
end_define

begin_define
define|#
directive|define
name|HOURSPERDAY
value|24
end_define

begin_define
define|#
directive|define
name|DAYSPERWEEK
value|7
end_define

begin_define
define|#
directive|define
name|DAYSPERNYEAR
value|365
end_define

begin_define
define|#
directive|define
name|DAYSPERLYEAR
value|366
end_define

begin_define
define|#
directive|define
name|SECSPERHOUR
value|(SECSPERMIN * MINSPERHOUR)
end_define

begin_define
define|#
directive|define
name|SECSPERDAY
value|((long) SECSPERHOUR * HOURSPERDAY)
end_define

begin_define
define|#
directive|define
name|MONSPERYEAR
value|12
end_define

begin_define
define|#
directive|define
name|TM_SUNDAY
value|0
end_define

begin_define
define|#
directive|define
name|TM_MONDAY
value|1
end_define

begin_define
define|#
directive|define
name|TM_TUESDAY
value|2
end_define

begin_define
define|#
directive|define
name|TM_WEDNESDAY
value|3
end_define

begin_define
define|#
directive|define
name|TM_THURSDAY
value|4
end_define

begin_define
define|#
directive|define
name|TM_FRIDAY
value|5
end_define

begin_define
define|#
directive|define
name|TM_SATURDAY
value|6
end_define

begin_define
define|#
directive|define
name|TM_JANUARY
value|0
end_define

begin_define
define|#
directive|define
name|TM_FEBRUARY
value|1
end_define

begin_define
define|#
directive|define
name|TM_MARCH
value|2
end_define

begin_define
define|#
directive|define
name|TM_APRIL
value|3
end_define

begin_define
define|#
directive|define
name|TM_MAY
value|4
end_define

begin_define
define|#
directive|define
name|TM_JUNE
value|5
end_define

begin_define
define|#
directive|define
name|TM_JULY
value|6
end_define

begin_define
define|#
directive|define
name|TM_AUGUST
value|7
end_define

begin_define
define|#
directive|define
name|TM_SEPTEMBER
value|8
end_define

begin_define
define|#
directive|define
name|TM_OCTOBER
value|9
end_define

begin_define
define|#
directive|define
name|TM_NOVEMBER
value|10
end_define

begin_define
define|#
directive|define
name|TM_DECEMBER
value|11
end_define

begin_define
define|#
directive|define
name|TM_YEAR_BASE
value|1900
end_define

begin_define
define|#
directive|define
name|EPOCH_YEAR
value|1970
end_define

begin_define
define|#
directive|define
name|EPOCH_WDAY
value|TM_THURSDAY
end_define

begin_comment
comment|/* ** Accurate only for the past couple of centuries; ** that will probably do. */
end_comment

begin_define
define|#
directive|define
name|isleap
parameter_list|(
name|y
parameter_list|)
value|(((y) % 4) == 0&& ((y) % 100) != 0 || ((y) % 400) == 0)
end_define

end_unit

