begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Interface routines for dungeon.  * These routines are for functions expected by the game  * that are not available in the Unix/f77 library.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|SYSV
end_ifdef

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

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
file|<time.h>
end_include

begin_else
else|#
directive|else
end_else

begin_include
include|#
directive|include
file|<sys/timeb.h>
end_include

begin_include
include|#
directive|include
file|<sys/time.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* routine to get time in hours minutes and seconds */
end_comment

begin_function_decl
name|long
name|time
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|tm
modifier|*
name|localtime
parameter_list|()
function_decl|;
end_function_decl

begin_decl_stmt
name|struct
name|tm
modifier|*
name|tmptr
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|long
name|timebuf
decl_stmt|;
end_decl_stmt

begin_macro
name|itime_
argument_list|(
argument|hrptr
argument_list|,
argument|minptr
argument_list|,
argument|secptr
argument_list|)
end_macro

begin_decl_stmt
name|int
modifier|*
name|hrptr
decl_stmt|,
modifier|*
name|minptr
decl_stmt|,
modifier|*
name|secptr
decl_stmt|;
end_decl_stmt

begin_block
block|{
name|time
argument_list|(
operator|&
name|timebuf
argument_list|)
expr_stmt|;
name|tmptr
operator|=
name|localtime
argument_list|(
operator|&
name|timebuf
argument_list|)
expr_stmt|;
operator|*
name|hrptr
operator|=
name|tmptr
operator|->
name|tm_hour
expr_stmt|;
operator|*
name|minptr
operator|=
name|tmptr
operator|->
name|tm_min
expr_stmt|;
operator|*
name|secptr
operator|=
name|tmptr
operator|->
name|tm_sec
expr_stmt|;
return|return;
block|}
end_block

begin_ifdef
ifdef|#
directive|ifdef
name|SYSV
end_ifdef

begin_comment
comment|/* idate - return day (1-31), month (1-12) and year (AD) */
end_comment

begin_comment
comment|/*	by Dave Newkirk, ihnp4!ihlpm!dcn */
end_comment

begin_macro
name|idate_
argument_list|(
argument|date
argument_list|)
end_macro

begin_decl_stmt
name|long
name|date
index|[]
decl_stmt|;
end_decl_stmt

begin_block
block|{
name|struct
name|tm
modifier|*
name|t
decl_stmt|,
modifier|*
name|localtime
argument_list|()
decl_stmt|;
name|long
name|time
argument_list|()
decl_stmt|,
modifier|*
name|tloc
decl_stmt|,
name|loc
decl_stmt|;
name|tloc
operator|=
operator|&
name|loc
expr_stmt|;
comment|/* get pointer to time in seconds */
name|time
argument_list|(
name|tloc
argument_list|)
expr_stmt|;
name|t
operator|=
name|localtime
argument_list|(
name|tloc
argument_list|)
expr_stmt|;
comment|/* get time structure filled in */
name|date
index|[
literal|0
index|]
operator|=
name|t
operator|->
name|tm_mday
expr_stmt|;
name|date
index|[
literal|1
index|]
operator|=
name|t
operator|->
name|tm_mon
operator|+
literal|1
expr_stmt|;
name|date
index|[
literal|2
index|]
operator|=
name|t
operator|->
name|tm_year
operator|+
literal|1900
expr_stmt|;
block|}
end_block

begin_comment
comment|/* end idate */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* random number initializer */
end_comment

begin_macro
name|inirnd_
argument_list|(
argument|seedptr
argument_list|)
end_macro

begin_decl_stmt
name|int
modifier|*
name|seedptr
decl_stmt|;
end_decl_stmt

begin_block
block|{
name|int
name|seed
decl_stmt|;
name|seed
operator|=
operator|*
name|seedptr
expr_stmt|;
name|srand
argument_list|(
name|seed
argument_list|)
expr_stmt|;
return|return;
block|}
end_block

begin_comment
comment|/*  random number generator */
end_comment

begin_macro
name|rnd_
argument_list|(
argument|maxval
argument_list|)
end_macro

begin_decl_stmt
name|int
modifier|*
name|maxval
decl_stmt|;
end_decl_stmt

begin_block
block|{
comment|/* note: returned random number ranges from 0 to maxval */
name|int
name|rndval
decl_stmt|;
name|rndval
operator|=
name|rand
argument_list|()
expr_stmt|;
name|rndval
operator|=
name|rndval
operator|%
operator|*
name|maxval
expr_stmt|;
return|return
operator|(
name|rndval
operator|)
return|;
block|}
end_block

begin_ifdef
ifdef|#
directive|ifdef
name|SYSV
end_ifdef

begin_comment
comment|/* thanks to Dave Newkirk, ihnp4!ihlpm!dcn for the following routines */
end_comment

begin_comment
comment|/* getuid - fortran callable getuid */
end_comment

begin_function
name|int
name|getuid_
parameter_list|()
block|{
return|return
operator|(
name|int
operator|)
name|getuid
argument_list|()
return|;
block|}
end_function

begin_comment
comment|/* unbuf - make output completely unbuffered */
end_comment

begin_macro
name|unbuf_
argument_list|()
end_macro

begin_block
block|{
name|void
name|setbuf
parameter_list|()
function_decl|;
name|setbuf
argument_list|(
name|stdout
argument_list|,
name|NULL
argument_list|)
expr_stmt|;
block|}
end_block

begin_endif
endif|#
directive|endif
end_endif

end_unit

