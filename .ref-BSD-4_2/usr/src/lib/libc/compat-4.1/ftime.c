begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	ftime.c	4.1	83/05/31	*/
end_comment

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|<sys/time.h>
end_include

begin_comment
comment|/*  * Backwards compatible ftime.  */
end_comment

begin_comment
comment|/* from old timeb.h */
end_comment

begin_struct
struct|struct
name|timeb
block|{
name|time_t
name|time
decl_stmt|;
name|u_short
name|millitm
decl_stmt|;
name|short
name|timezone
decl_stmt|;
name|short
name|dstflag
decl_stmt|;
block|}
struct|;
end_struct

begin_expr_stmt
name|ftime
argument_list|(
name|tp
argument_list|)
specifier|register
expr|struct
name|timeb
operator|*
name|tp
expr_stmt|;
end_expr_stmt

begin_block
block|{
name|struct
name|timeval
name|t
decl_stmt|;
name|struct
name|timezone
name|tz
decl_stmt|;
if|if
condition|(
name|gettimeofday
argument_list|(
operator|&
name|t
argument_list|,
operator|&
name|tz
argument_list|)
operator|<
literal|0
condition|)
return|return
operator|(
operator|-
literal|1
operator|)
return|;
name|tp
operator|->
name|time
operator|=
name|t
operator|.
name|tv_sec
expr_stmt|;
name|tp
operator|->
name|millitm
operator|=
name|t
operator|.
name|tv_usec
operator|/
literal|1000
expr_stmt|;
name|tp
operator|->
name|timezone
operator|=
name|tz
operator|.
name|tz_minuteswest
expr_stmt|;
name|tp
operator|->
name|dstflag
operator|=
name|tz
operator|.
name|tz_dsttime
expr_stmt|;
block|}
end_block

end_unit

