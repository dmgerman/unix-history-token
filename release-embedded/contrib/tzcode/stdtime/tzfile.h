begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_ifndef
ifndef|#
directive|ifndef
name|TZFILE_H
end_ifndef

begin_define
define|#
directive|define
name|TZFILE_H
end_define

begin_comment
comment|/* ** This file is in the public domain, so clarified as of ** 1996-06-05 by Arthur David Olson. ** ** $FreeBSD$ */
end_comment

begin_comment
comment|/* ** This header is for use ONLY with the time conversion code. ** There is no guarantee that it will remain unchanged, ** or that it will remain at all. ** Do NOT copy it to any system include directory. ** Thank you! */
end_comment

begin_comment
comment|/* ** ID */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|lint
end_ifndef

begin_ifndef
ifndef|#
directive|ifndef
name|NOID
end_ifndef

begin_comment
comment|/* static char	tzfilehid[] = "@(#)tzfile.h	8.1"; */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !defined NOID */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !defined lint */
end_comment

begin_comment
comment|/* ** Information about time zone files. */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|TZDIR
end_ifndef

begin_define
define|#
directive|define
name|TZDIR
value|"/usr/share/zoneinfo"
end_define

begin_comment
comment|/* Time zone object file directory */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !defined TZDIR */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|TZDEFAULT
end_ifndef

begin_define
define|#
directive|define
name|TZDEFAULT
value|"/etc/localtime"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !defined TZDEFAULT */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|TZDEFRULES
end_ifndef

begin_define
define|#
directive|define
name|TZDEFRULES
value|"posixrules"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !defined TZDEFRULES */
end_comment

begin_comment
comment|/* ** Each file begins with. . . */
end_comment

begin_define
define|#
directive|define
name|TZ_MAGIC
value|"TZif"
end_define

begin_struct
struct|struct
name|tzhead
block|{
name|char
name|tzh_magic
index|[
literal|4
index|]
decl_stmt|;
comment|/* TZ_MAGIC */
name|char
name|tzh_version
index|[
literal|1
index|]
decl_stmt|;
comment|/* '\0' or '2' as of 2005 */
name|char
name|tzh_reserved
index|[
literal|15
index|]
decl_stmt|;
comment|/* reserved--must be zero */
name|char
name|tzh_ttisgmtcnt
index|[
literal|4
index|]
decl_stmt|;
comment|/* coded number of trans. time flags */
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
comment|/* ** . . .followed by. . . ** **	tzh_timecnt (char [4])s		coded transition times a la time(2) **	tzh_timecnt (unsigned char)s	types of local time starting at above **	tzh_typecnt repetitions of **		one (char [4])		coded UTC offset in seconds **		one (unsigned char)	used to set tm_isdst **		one (unsigned char)	that's an abbreviation list index **	tzh_charcnt (char)s		'\0'-terminated zone abbreviations **	tzh_leapcnt repetitions of **		one (char [4])		coded leap second transition times **		one (char [4])		total correction after above **	tzh_ttisstdcnt (char)s		indexed by type; if TRUE, transition **					time is standard time, if FALSE, **					transition time is wall clock time **					if absent, transition times are **					assumed to be wall clock time **	tzh_ttisgmtcnt (char)s		indexed by type; if TRUE, transition **					time is UTC, if FALSE, **					transition time is local time **					if absent, transition times are **					assumed to be local time */
end_comment

begin_comment
comment|/* ** If tzh_version is '2' or greater, the above is followed by a second instance ** of tzhead and a second instance of the data in which each coded transition ** time uses 8 rather than 4 chars, ** then a POSIX-TZ-environment-variable-style string for use in handling ** instants after the last transition time stored in the file ** (with nothing between the newlines if there is no POSIX representation for ** such instants). */
end_comment

begin_comment
comment|/* ** In the current implementation, "tzset()" refuses to deal with files that ** exceed any of the limits below. */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|TZ_MAX_TIMES
end_ifndef

begin_define
define|#
directive|define
name|TZ_MAX_TIMES
value|1200
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !defined TZ_MAX_TIMES */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|TZ_MAX_TYPES
end_ifndef

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

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !defined NOSOLAR */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|NOSOLAR
end_ifdef

begin_comment
comment|/* ** Must be at least 14 for Europe/Riga as of Jan 12 1995, ** as noted by Earl Chew. */
end_comment

begin_define
define|#
directive|define
name|TZ_MAX_TYPES
value|20
end_define

begin_comment
comment|/* Maximum number of local time types */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !defined NOSOLAR */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !defined TZ_MAX_TYPES */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|TZ_MAX_CHARS
end_ifndef

begin_define
define|#
directive|define
name|TZ_MAX_CHARS
value|50
end_define

begin_comment
comment|/* Maximum number of abbreviation characters */
end_comment

begin_comment
comment|/* (limited by what unsigned chars can hold) */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !defined TZ_MAX_CHARS */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|TZ_MAX_LEAPS
end_ifndef

begin_define
define|#
directive|define
name|TZ_MAX_LEAPS
value|50
end_define

begin_comment
comment|/* Maximum number of leap second corrections */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !defined TZ_MAX_LEAPS */
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

begin_define
define|#
directive|define
name|isleap
parameter_list|(
name|y
parameter_list|)
value|(((y) % 4) == 0&& (((y) % 100) != 0 || ((y) % 400) == 0))
end_define

begin_comment
comment|/* ** Since everything in isleap is modulo 400 (or a factor of 400), we know that **	isleap(y) == isleap(y % 400) ** and so **	isleap(a + b) == isleap((a + b) % 400) ** or **	isleap(a + b) == isleap(a % 400 + b % 400) ** This is true even if % means modulo rather than Fortran remainder ** (which is allowed by C89 but not C99). ** We use this to avoid addition overflow problems. */
end_comment

begin_define
define|#
directive|define
name|isleap_sum
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|isleap((a) % 400 + (b) % 400)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !defined TZFILE_H */
end_comment

end_unit

