begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * tzset.c  *  * Quick and dirty emulation of tzset(), tzname[], and daylight  * for old BSD systems without it.  *  * Thanks to Rick Adams, rick@uunet.uu.net, for the basics.  *  * BUGS:  *	Totally ignores the value of the TZ environment variable.  */
end_comment

begin_if
if|#
directive|if
literal|0
end_if

begin_include
include|#
directive|include
file|<sys/time.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
specifier|static
name|char
name|tz1
index|[
literal|1024
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|char
name|tz2
index|[
literal|1024
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* external variables */
end_comment

begin_decl_stmt
name|char
modifier|*
name|tzname
index|[
literal|2
index|]
init|=
block|{
name|tz1
block|,
name|tz2
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|daylight
decl_stmt|;
end_decl_stmt

begin_function_decl
specifier|extern
name|char
modifier|*
name|timezone
parameter_list|()
function_decl|;
end_function_decl

begin_function
name|void
name|tzset
parameter_list|()
block|{
name|struct
name|timeval
name|tp
decl_stmt|;
name|struct
name|timezone
name|tz
decl_stmt|;
operator|(
name|void
operator|)
name|gettimeofday
argument_list|(
operator|&
name|tp
argument_list|,
operator|&
name|tz
argument_list|)
expr_stmt|;
operator|(
name|void
operator|)
name|strcpy
argument_list|(
name|tz1
argument_list|,
name|timezone
argument_list|(
name|tz
operator|.
name|tz_minuteswest
argument_list|,
literal|0
argument_list|)
argument_list|)
expr_stmt|;
operator|(
name|void
operator|)
name|strcpy
argument_list|(
name|tz2
argument_list|,
name|timezone
argument_list|(
name|tz
operator|.
name|tz_minuteswest
argument_list|,
literal|1
argument_list|)
argument_list|)
expr_stmt|;
name|daylight
operator|=
name|tz
operator|.
name|tz_dsttime
expr_stmt|;
block|}
end_function

end_unit

