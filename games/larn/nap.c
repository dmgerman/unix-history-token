begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* nap.c		 Larn is copyrighted 1986 by Noah Morgan. */
end_comment

begin_comment
comment|/* $FreeBSD$ */
end_comment

begin_include
include|#
directive|include
file|<signal.h>
end_include

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|SYSV
end_ifdef

begin_include
include|#
directive|include
file|<sys/times.h>
end_include

begin_else
else|#
directive|else
end_else

begin_ifdef
ifdef|#
directive|ifdef
name|BSD
end_ifdef

begin_include
include|#
directive|include
file|<sys/timeb.h>
end_include

begin_endif
endif|#
directive|endif
endif|BSD
end_endif

begin_endif
endif|#
directive|endif
endif|SYSV
end_endif

begin_comment
comment|/*  *	routine to take a nap for n milliseconds  */
end_comment

begin_macro
name|nap
argument_list|(
argument|x
argument_list|)
end_macro

begin_decl_stmt
name|int
name|x
decl_stmt|;
end_decl_stmt

begin_block
block|{
if|if
condition|(
name|x
operator|<=
literal|0
condition|)
return|return;
comment|/* eliminate chance for infinite loop */
name|lflush
argument_list|()
expr_stmt|;
if|#
directive|if
literal|0
block|if (x> 999) sleep(x/1000); else napms(x);
else|#
directive|else
name|usleep
argument_list|(
name|x
operator|*
literal|1000
argument_list|)
expr_stmt|;
endif|#
directive|endif
block|}
end_block

begin_ifdef
ifdef|#
directive|ifdef
name|NONAP
end_ifdef

begin_macro
name|napms
argument_list|(
argument|x
argument_list|)
end_macro

begin_comment
comment|/* do nothing */
end_comment

begin_decl_stmt
name|int
name|x
decl_stmt|;
end_decl_stmt

begin_block
block|{ 	}
end_block

begin_else
else|#
directive|else
else|NONAP
end_else

begin_ifdef
ifdef|#
directive|ifdef
name|SYSV
end_ifdef

begin_comment
comment|/*	napms - sleep for time milliseconds - uses times() */
end_comment

begin_comment
comment|/* this assumes that times returns a relative time in 60ths of a second */
end_comment

begin_comment
comment|/* this will do horrible things if your times() returns seconds! */
end_comment

begin_macro
name|napms
argument_list|(
argument|time
argument_list|)
end_macro

begin_decl_stmt
name|int
name|time
decl_stmt|;
end_decl_stmt

begin_block
block|{
name|long
name|matchclock
decl_stmt|,
name|times
argument_list|()
decl_stmt|;
name|struct
name|tms
name|stats
decl_stmt|;
if|if
condition|(
name|time
operator|<=
literal|0
condition|)
name|time
operator|=
literal|1
expr_stmt|;
comment|/* eliminate chance for infinite loop */
if|if
condition|(
operator|(
name|matchclock
operator|=
name|times
argument_list|(
operator|&
name|stats
argument_list|)
operator|)
operator|==
operator|-
literal|1
operator|||
name|matchclock
operator|==
literal|0
condition|)
return|return;
comment|/* error, or BSD style times() */
name|matchclock
operator|+=
operator|(
name|time
operator|/
literal|17
operator|)
expr_stmt|;
comment|/*17 ms/tic is 1000 ms/sec / 60 tics/sec */
while|while
condition|(
name|matchclock
operator|<
name|times
argument_list|(
operator|&
name|stats
argument_list|)
condition|)
empty_stmt|;
block|}
end_block

begin_else
else|#
directive|else
else|not SYSV
end_else

begin_ifdef
ifdef|#
directive|ifdef
name|BSD
end_ifdef

begin_ifdef
ifdef|#
directive|ifdef
name|SIGVTALRM
end_ifdef

begin_comment
comment|/* This must be BSD 4.2!  */
end_comment

begin_include
include|#
directive|include
file|<sys/time.h>
end_include

begin_define
define|#
directive|define
name|bit
parameter_list|(
name|_a
parameter_list|)
value|(1<<((_a)-1))
end_define

begin_expr_stmt
specifier|static
name|nullf
argument_list|()
block|{     }
comment|/*	napms - sleep for time milliseconds - uses setitimer() */
name|napms
argument_list|(
argument|time
argument_list|)
name|int
name|time
expr_stmt|;
end_expr_stmt

begin_block
block|{
name|struct
name|itimerval
name|timeout
decl_stmt|;
name|int
function_decl|(
modifier|*
name|oldhandler
function_decl|)
parameter_list|()
function_decl|;
name|int
name|oldsig
decl_stmt|;
if|if
condition|(
name|time
operator|<=
literal|0
condition|)
return|return;
name|timerclear
argument_list|(
operator|&
name|timeout
operator|.
name|it_interval
argument_list|)
expr_stmt|;
name|timeout
operator|.
name|it_value
operator|.
name|tv_sec
operator|=
name|time
operator|/
literal|1000
expr_stmt|;
name|timeout
operator|.
name|it_value
operator|.
name|tv_usec
operator|=
operator|(
name|time
operator|%
literal|1000
operator|)
operator|*
literal|1000
expr_stmt|;
name|oldsig
operator|=
name|sigblock
argument_list|(
name|bit
argument_list|(
name|SIGALRM
argument_list|)
argument_list|)
expr_stmt|;
name|setitimer
argument_list|(
name|ITIMER_REAL
argument_list|,
operator|&
name|timeout
argument_list|,
operator|(
expr|struct
name|itimerval
operator|*
operator|)
literal|0
argument_list|)
expr_stmt|;
name|oldhandler
operator|=
name|signal
argument_list|(
name|SIGALRM
argument_list|,
name|nullf
argument_list|)
expr_stmt|;
name|sigpause
argument_list|(
name|oldsig
argument_list|)
expr_stmt|;
name|signal
argument_list|(
name|SIGALRM
argument_list|,
name|oldhandler
argument_list|)
expr_stmt|;
name|sigsetmask
argument_list|(
name|oldsig
argument_list|)
expr_stmt|;
block|}
end_block

begin_else
else|#
directive|else
end_else

begin_comment
comment|/*	napms - sleep for time milliseconds - uses ftime() */
end_comment

begin_expr_stmt
specifier|static
name|napms
argument_list|(
argument|time
argument_list|)
name|int
name|time
expr_stmt|;
end_expr_stmt

begin_block
block|{
comment|/* assumed to be BSD UNIX */
name|struct
name|timeb
name|_gtime
decl_stmt|;
name|time_t
name|matchtime
decl_stmt|;
name|unsigned
name|short
name|matchmilli
decl_stmt|;
name|struct
name|timeb
modifier|*
name|tp
init|=
operator|&
name|_gtime
decl_stmt|;
if|if
condition|(
name|time
operator|<=
literal|0
condition|)
return|return;
name|ftime
argument_list|(
name|tp
argument_list|)
expr_stmt|;
name|matchmilli
operator|=
name|tp
operator|->
name|millitm
operator|+
name|time
expr_stmt|;
name|matchtime
operator|=
name|tp
operator|->
name|time
expr_stmt|;
while|while
condition|(
name|matchmilli
operator|>=
literal|1000
condition|)
block|{
operator|++
name|matchtime
expr_stmt|;
name|matchmilli
operator|-=
literal|1000
expr_stmt|;
block|}
while|while
condition|(
literal|1
condition|)
block|{
name|ftime
argument_list|(
name|tp
argument_list|)
expr_stmt|;
if|if
condition|(
operator|(
name|tp
operator|->
name|time
operator|>
name|matchtime
operator|)
operator|||
operator|(
operator|(
name|tp
operator|->
name|time
operator|==
name|matchtime
operator|)
operator|&&
operator|(
name|tp
operator|->
name|millitm
operator|>=
name|matchmilli
operator|)
operator|)
condition|)
break|break;
block|}
block|}
end_block

begin_endif
endif|#
directive|endif
end_endif

begin_else
else|#
directive|else
else|not BSD
end_else

begin_expr_stmt
specifier|static
name|napms
argument_list|(
argument|time
argument_list|)
name|int
name|time
expr_stmt|;
end_expr_stmt

begin_block
block|{}
end_block

begin_comment
comment|/* do nothing, forget it */
end_comment

begin_endif
endif|#
directive|endif
endif|BSD
end_endif

begin_endif
endif|#
directive|endif
endif|SYSV
end_endif

begin_endif
endif|#
directive|endif
endif|NONAP
end_endif

end_unit

