begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_include
include|#
directive|include
file|"ntp-config.h"
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|REFCLOCK
end_ifdef

begin_comment
comment|/*  *  A dummy clock reading routine that reads the current system time.  *  from the local host.  Its possible that this could be actually used  *  if the system was in fact a very accurate time keeper (a true real-time  *  system with good crystal clock or better).  */
end_comment

begin_include
include|#
directive|include
file|"ntp.h"
end_include

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

begin_decl_stmt
specifier|extern
name|LLog
modifier|*
name|pgm_log
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* ARGSUSED */
end_comment

begin_function
name|int
name|init_clock_local
parameter_list|(
name|file
parameter_list|)
name|char
modifier|*
name|file
decl_stmt|;
block|{
name|struct
name|intf
modifier|*
name|ap
decl_stmt|;
name|int
name|acount
decl_stmt|;
name|ap
operator|=
name|getintf
argument_list|(
operator|&
name|acount
argument_list|)
expr_stmt|;
name|ap
operator|->
name|name
operator|=
literal|"LOCAL"
expr_stmt|;
name|ap
operator|->
name|addr
operator|.
name|type
operator|=
literal|0
expr_stmt|;
name|ap
operator|->
name|inum
operator|=
name|acount
expr_stmt|;
return|return
name|acount
return|;
comment|/* invalid if we ever use it */
block|}
end_function

begin_comment
comment|/* ARGSUSED */
end_comment

begin_macro
name|read_clock_local
argument_list|(
argument|cfd
argument_list|,
argument|tvp
argument_list|,
argument|mtvp
argument_list|)
end_macro

begin_decl_stmt
name|int
name|cfd
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|timeval
modifier|*
modifier|*
name|tvp
decl_stmt|,
modifier|*
modifier|*
name|mtvp
decl_stmt|;
end_decl_stmt

begin_block
block|{
specifier|static
name|struct
name|timeval
name|realtime
decl_stmt|,
name|mytime
decl_stmt|;
name|TRACE
argument_list|(
literal|2
argument_list|,
operator|(
literal|"read_local_clock"
operator|)
argument_list|)
expr_stmt|;
operator|(
name|void
operator|)
name|gettimeofday
argument_list|(
operator|&
name|realtime
argument_list|,
operator|(
expr|struct
name|timezone
operator|*
operator|)
literal|0
argument_list|)
expr_stmt|;
name|mytime
operator|=
name|realtime
expr_stmt|;
operator|*
name|tvp
operator|=
operator|&
name|realtime
expr_stmt|;
operator|*
name|mtvp
operator|=
operator|&
name|mytime
expr_stmt|;
return|return
operator|(
literal|0
operator|)
return|;
block|}
end_block

begin_endif
endif|#
directive|endif
end_endif

end_unit

