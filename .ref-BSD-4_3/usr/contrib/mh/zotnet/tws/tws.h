begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* tws.h */
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
block|}
struct|;
end_struct

begin_function_decl
name|void
name|twscopy
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|twsort
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|long
name|twclock
parameter_list|()
function_decl|;
end_function_decl

begin_decl_stmt
name|char
modifier|*
name|dasctime
argument_list|()
decl_stmt|,
modifier|*
name|dtimezone
argument_list|()
decl_stmt|,
modifier|*
name|dctime
argument_list|()
decl_stmt|,
modifier|*
name|dtimenow
argument_list|()
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|tws
modifier|*
name|dgmtime
argument_list|()
decl_stmt|,
modifier|*
name|dlocaltime
argument_list|()
decl_stmt|,
modifier|*
name|dparsetime
argument_list|()
decl_stmt|,
modifier|*
name|dtwstime
argument_list|()
decl_stmt|;
end_decl_stmt

begin_ifndef
ifndef|#
directive|ifndef
name|ATZ
end_ifndef

begin_define
define|#
directive|define
name|dtime
parameter_list|(
name|cl
parameter_list|)
value|dasctime (dlocaltime (cl), TW_ZONE)
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
value|dasctime (dlocaltime (cl), TW_NULL)
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
value|dtimezone (tw -> tw_zone, tw -> tw_flags)
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

