begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* tws.h - header file for libtws date/time library */
end_comment

begin_comment
comment|/* Definition of the tws data structure. */
end_comment

begin_struct
struct|struct
name|tws
block|{
name|int
name|tw_sec
decl_stmt|;
name|int
name|tw_min
decl_stmt|;
name|int
name|tw_hour
decl_stmt|;
name|int
name|tw_mday
decl_stmt|;
name|int
name|tw_mon
decl_stmt|;
name|int
name|tw_year
decl_stmt|;
name|int
name|tw_wday
decl_stmt|;
name|int
name|tw_yday
decl_stmt|;
name|int
name|tw_zone
decl_stmt|;
name|long
name|tw_clock
decl_stmt|;
name|int
name|tw_flags
decl_stmt|;
define|#
directive|define
name|TW_NULL
value|0x0000
define|#
directive|define
name|TW_SDAY
value|0x0007
comment|/* how day-of-week was determined */
define|#
directive|define
name|TW_SNIL
value|0x0000
comment|/*   not given */
define|#
directive|define
name|TW_SEXP
value|0x0001
comment|/*   explicitly given */
define|#
directive|define
name|TW_SIMP
value|0x0002
comment|/*   implicitly given */
define|#
directive|define
name|TW_DST
value|0x0010
comment|/* daylight savings time */
define|#
directive|define
name|TW_ZONE
value|0x0020
comment|/* use numeric timezones only */
define|#
directive|define
name|TW_JUNK
value|0x0040
comment|/* date string contained junk */
block|}
struct|;
end_struct

begin_comment
comment|/* Declarations of routines. */
end_comment

begin_function_decl
name|void
name|twscopy
parameter_list|( )
function_decl|;
end_function_decl

begin_comment
comment|/* twscopy(&totws,&fromtws ) copies a tws */
end_comment

begin_function_decl
name|int
name|twsort
parameter_list|( )
function_decl|;
end_function_decl

begin_comment
comment|/* twsort(&tws1,&tws2 ) compares two tws's: 1 means tws1 is 	   later; -1 means tws1 is earlier; 0 means they are equal */
end_comment

begin_function_decl
name|long
name|twclock
parameter_list|( )
function_decl|;
end_function_decl

begin_comment
comment|/* twclock(&tws ) turns a tws into a time(3)-style clock value */
end_comment

begin_function_decl
name|long
name|twjuliandate
parameter_list|( )
function_decl|;
end_function_decl

begin_comment
comment|/* twjuliandate(&tws ) returns the Julian day number of a tws */
end_comment

begin_function_decl
name|long
name|twsubtract
parameter_list|( )
function_decl|;
end_function_decl

begin_comment
comment|/* twsubtract(&tws1,&tws2 ) returns seconds of difference */
end_comment

begin_comment
comment|/* These routines are functionally similar to the ctime(3) routines    in the standard Unix library. */
end_comment

begin_function_decl
name|char
modifier|*
name|dctime
parameter_list|( )
function_decl|;
end_function_decl

begin_comment
comment|/* dctime(&tws ) returns a string for the date/time passed in */
end_comment

begin_function_decl
name|struct
name|tws
modifier|*
name|dlocaltime
parameter_list|( )
function_decl|;
end_function_decl

begin_comment
comment|/* dlocaltime(&clock ) turns a time(3) clock value into a tws */
end_comment

begin_function_decl
name|struct
name|tws
modifier|*
name|dgmtime
parameter_list|( )
function_decl|;
end_function_decl

begin_comment
comment|/* dgmtime(&clock ) turns a time(3) clock value into a tws */
end_comment

begin_function_decl
name|char
modifier|*
name|dasctime
parameter_list|( )
function_decl|;
end_function_decl

begin_comment
comment|/* dasctime(&tws, flags ) turns a tws into a string */
end_comment

begin_function_decl
name|char
modifier|*
name|dtimezone
parameter_list|( )
function_decl|;
end_function_decl

begin_comment
comment|/* dtimezone( offset, flags ) returns the name of the time zone */
end_comment

begin_function_decl
name|char
modifier|*
name|dtimenow
parameter_list|( )
function_decl|;
end_function_decl

begin_comment
comment|/* dtimenow( ) returns a string for the current date/time */
end_comment

begin_function_decl
name|struct
name|tws
modifier|*
name|dparsetime
parameter_list|( )
function_decl|;
end_function_decl

begin_comment
comment|/* dparsetime(&str ) turns a string into a tws */
end_comment

begin_function_decl
name|struct
name|tws
modifier|*
name|dtwstime
parameter_list|( )
function_decl|;
end_function_decl

begin_comment
comment|/* dtwstime( ) returns a tws for the current date/time */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|ATZ
end_ifdef

begin_define
define|#
directive|define
name|dtime
parameter_list|(
name|cl
parameter_list|)
value|dasctime( dlocaltime( cl ), TW_NULL )
end_define

begin_else
else|#
directive|else
else|ATZ
end_else

begin_define
define|#
directive|define
name|dtime
parameter_list|(
name|cl
parameter_list|)
value|dasctime( dlocaltime( cl ), TW_ZONE )
end_define

begin_endif
endif|#
directive|endif
endif|ATZ
end_endif

begin_define
define|#
directive|define
name|dtwszone
parameter_list|(
name|tw
parameter_list|)
value|dtimezone( tw -> tw_zone, tw -> tw_flags )
end_define

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|tw_dotw
index|[]
decl_stmt|,
modifier|*
name|tw_ldotw
index|[]
decl_stmt|,
modifier|*
name|tw_moty
index|[]
decl_stmt|;
end_decl_stmt

end_unit

