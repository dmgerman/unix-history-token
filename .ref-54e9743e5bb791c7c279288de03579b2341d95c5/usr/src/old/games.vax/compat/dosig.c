begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_ifndef
ifndef|#
directive|ifndef
name|lint
end_ifndef

begin_decl_stmt
specifier|static
name|char
name|sccsid
index|[]
init|=
literal|"@(#)dosig.c	4.3  84/05/05"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* From Lou Salkind: compat/RCS/dosig.c,v 1.2 84/01/31 13:34:17 */
end_comment

begin_comment
comment|/*  * Handle signal trapping from version 6 or  * version 7 compatability mode programs.  *	Art Wetzel	November 1979  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|TRACE
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
file|<signal.h>
end_include

begin_include
include|#
directive|include
file|"defs.h"
end_include

begin_decl_stmt
name|int
name|sigtrapped
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|unsigned
name|int
name|sigvals
index|[
name|NSIG
operator|+
literal|1
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* actual catch point for all signals */
end_comment

begin_macro
name|sigcatch
argument_list|(
argument|signum
argument_list|,
argument|faultcode
argument_list|,
argument|scp
argument_list|)
end_macro

begin_decl_stmt
name|int
name|signum
decl_stmt|,
name|faultcode
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|sigcontext
modifier|*
name|scp
decl_stmt|;
end_decl_stmt

begin_block
block|{
name|unsigned
name|short
modifier|*
name|pcptr
decl_stmt|;
extern|extern getregs(
block|)
end_block

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_if
if|if
condition|(
name|incompat
condition|)
block|{
comment|/* hurry up and get the registers before they are destroyed */
name|getregs
argument_list|()
expr_stmt|;
block|}
else|else
block|{
comment|/* we were in native mode simulating a sys call */
comment|/* set it up with the old values */
name|dosig
argument_list|(
name|signum
argument_list|,
name|pc
argument_list|)
expr_stmt|;
comment|/* go back where we were doing the sys call */
return|return
operator|(
literal|0
operator|)
return|;
block|}
end_if

begin_comment
comment|/* figure out the pc */
end_comment

begin_expr_stmt
name|pcptr
operator|=
operator|(
name|unsigned
name|short
operator|*
operator|)
operator|&
name|scp
operator|->
name|sc_pc
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|pc
operator|=
operator|(
name|unsigned
name|short
operator|*
operator|)
operator|*
name|pcptr
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* get the psl with condition codes */
end_comment

begin_expr_stmt
name|psl
operator|=
literal|0x83c00000
operator||
operator|(
name|scp
operator|->
name|sc_ps
operator|&
literal|017
operator|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* actually do the thing */
end_comment

begin_if
if|if
condition|(
name|sigvals
index|[
name|signum
index|]
operator|!=
operator|(
name|unsigned
name|int
operator|)
name|SIG_DFL
operator|&&
operator|(
name|sigvals
index|[
name|signum
index|]
operator|&
operator|(
name|unsigned
name|int
operator|)
name|SIG_IGN
operator|)
operator|==
literal|0
condition|)
name|dosig
argument_list|(
name|signum
argument_list|,
name|pc
argument_list|)
expr_stmt|;
end_if

begin_comment
comment|/* go back to compatability mode and the signal routine there */
end_comment

begin_expr_stmt
name|sigsetmask
argument_list|(
name|scp
operator|->
name|sc_mask
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|incompat
operator|++
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|compat
argument_list|()
expr_stmt|;
end_expr_stmt

begin_comment
unit|}
comment|/* routine to set up pdp11 space for return from a signal */
end_comment

begin_expr_stmt
unit|dosig
operator|(
name|signum
operator|,
name|from
operator|)
name|int
name|signum
operator|,
name|from
expr_stmt|;
end_expr_stmt

begin_block
block|{
name|unsigned
name|short
modifier|*
name|sp
decl_stmt|;
ifdef|#
directive|ifdef
name|TRACE
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"Caught sig %d from 0%o -> 0%o\n"
argument_list|,
name|signum
argument_list|,
operator|(
name|pc
operator|-
literal|1
operator|)
argument_list|,
operator|*
operator|(
name|pc
operator|-
literal|1
operator|)
argument_list|)
expr_stmt|;
endif|#
directive|endif
name|sigtrapped
operator|=
literal|1
expr_stmt|;
comment|/* where is the stack */
name|sp
operator|=
operator|(
name|unsigned
name|short
operator|*
operator|)
name|regs
index|[
literal|6
index|]
expr_stmt|;
comment|/* stack up psw condition codes so rti works */
operator|*
operator|(
operator|--
name|sp
operator|)
operator|=
name|psl
operator|&
literal|017
expr_stmt|;
comment|/* stack pc */
operator|*
operator|(
operator|--
name|sp
operator|)
operator|=
operator|(
name|unsigned
name|short
operator|)
operator|(
name|int
operator|)
name|pc
expr_stmt|;
comment|/* reset stack pointer */
name|regs
index|[
literal|6
index|]
operator|=
operator|(
name|unsigned
name|short
operator|)
operator|(
name|int
operator|)
name|sp
expr_stmt|;
comment|/* reset pc to signal catching routine */
name|pc
operator|=
operator|(
name|unsigned
name|short
operator|*
operator|)
name|sigvals
index|[
name|signum
index|]
expr_stmt|;
comment|/*	signal(signum, SIG_DFL); */
block|}
end_block

end_unit

