begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * tzone.c - get the timezone  *  * This is shared by bootpd and bootpef  *  * $FreeBSD$  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|SVR4
end_ifdef

begin_comment
comment|/* XXX - Is this really SunOS specific? -gwr */
end_comment

begin_comment
comment|/* This is in<time.h> but only visible if (__STDC__ == 1). */
end_comment

begin_decl_stmt
specifier|extern
name|long
name|timezone
decl_stmt|;
end_decl_stmt

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* SVR4 */
end_comment

begin_comment
comment|/* BSD or SunOS */
end_comment

begin_include
include|#
directive|include
file|<time.h>
end_include

begin_include
include|#
directive|include
file|<syslog.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* SVR4 */
end_comment

begin_include
include|#
directive|include
file|"bptypes.h"
end_include

begin_include
include|#
directive|include
file|"report.h"
end_include

begin_include
include|#
directive|include
file|"tzone.h"
end_include

begin_comment
comment|/* This is what other modules use. */
end_comment

begin_decl_stmt
name|int32
name|secondswest
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * Get our timezone offset so we can give it to clients if the  * configuration file doesn't specify one.  */
end_comment

begin_function
name|void
name|tzone_init
parameter_list|()
block|{
ifdef|#
directive|ifdef
name|SVR4
comment|/* XXX - Is this really SunOS specific? -gwr */
name|secondswest
operator|=
name|timezone
expr_stmt|;
else|#
directive|else
comment|/* SVR4 */
name|struct
name|tm
modifier|*
name|tm
decl_stmt|;
name|time_t
name|now
decl_stmt|;
operator|(
name|void
operator|)
name|time
argument_list|(
operator|&
name|now
argument_list|)
expr_stmt|;
if|if
condition|(
operator|(
name|tm
operator|=
name|localtime
argument_list|(
operator|&
name|now
argument_list|)
operator|)
operator|==
name|NULL
condition|)
block|{
name|secondswest
operator|=
literal|0
expr_stmt|;
comment|/* Assume GMT for lack of anything better */
name|report
argument_list|(
name|LOG_ERR
argument_list|,
literal|"localtime() failed"
argument_list|)
expr_stmt|;
block|}
else|else
block|{
name|secondswest
operator|=
operator|-
name|tm
operator|->
name|tm_gmtoff
expr_stmt|;
block|}
endif|#
directive|endif
comment|/* SVR4 */
block|}
end_function

end_unit

