begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1991 The Regents of the University of California.  * All rights reserved.  *  * %sccs.include.redist.c%  */
end_comment

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
literal|"@(#)crt0.c	5.3 (Berkeley) %G%"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* not lint */
end_comment

begin_comment
comment|/*  *	C start up routine.  *	Robert Henry, UCB, 20 Oct 81  *  *	We make the following (true) assumptions:  *	1) When the kernel calls start, it does a jump to location 2,  *	and thus avoids the register save mask.  We are NOT called  *	with a calls!  *	2) The only register variable that we can trust is sp,  *	which points to the base of the kernel calling frame.  */
end_comment

begin_decl_stmt
name|char
modifier|*
modifier|*
name|environ
init|=
operator|(
name|char
operator|*
operator|*
operator|)
literal|0
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|int
name|fd
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|unsigned
name|char
name|etext
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|unsigned
name|char
name|eprol
name|asm
argument_list|(
literal|"eprol"
argument_list|)
decl_stmt|;
end_decl_stmt

begin_extern
extern|extern			start(
end_extern

begin_asm
unit|)
asm|asm("start");
end_asm

begin_comment
comment|/*  * Some kluges: store sp at entry in environ, and  * install 16 bits of 0 at location 0 (a zero register save mask).  * These two hacks remove limits on the use of local  * and register variables in start().  * The reason for using 'moval (sp),...' is that 'movl sp,...' generates  * a privileged instruction trap (argh).  * XXX 'addl3 $start,$2,r0; jmp (r0)' should be replaced with  * XXX 'jbr start+2' when we convert over to gas.  */
end_comment

begin_asm
asm|asm(".text; .word 0; moval (sp),_environ; addl3 $start,$2,r0; jmp (r0)");
end_asm

begin_macro
name|start
argument_list|()
end_macro

begin_block
block|{
struct|struct
name|kframe
block|{
name|int
name|kargc
decl_stmt|;
name|char
modifier|*
name|kargv
index|[
literal|1
index|]
decl_stmt|;
comment|/* size depends on kargc */
name|char
name|kargstr
index|[
literal|1
index|]
decl_stmt|;
comment|/* size varies */
name|char
name|kenvstr
index|[
literal|1
index|]
decl_stmt|;
comment|/* size varies */
block|}
struct|;
specifier|register
name|struct
name|kframe
modifier|*
name|kfp
decl_stmt|;
specifier|register
name|char
modifier|*
modifier|*
name|targv
decl_stmt|;
specifier|register
name|char
modifier|*
modifier|*
name|argv
decl_stmt|;
specifier|extern
name|int
name|errno
decl_stmt|;
name|kfp
operator|=
operator|(
expr|struct
name|kframe
operator|*
operator|)
name|environ
expr_stmt|;
for|for
control|(
name|argv
operator|=
name|targv
operator|=
operator|&
name|kfp
operator|->
name|kargv
index|[
literal|0
index|]
init|;
operator|*
name|targv
operator|++
condition|;
comment|/* void */
control|)
comment|/* void */
empty_stmt|;
if|if
condition|(
name|targv
operator|>=
operator|(
name|char
operator|*
operator|*
operator|)
operator|(
operator|*
name|argv
operator|)
condition|)
operator|--
name|targv
expr_stmt|;
name|environ
operator|=
name|targv
expr_stmt|;
asm|asm("eprol:");
ifdef|#
directive|ifdef
name|MCRT0
name|monstartup
argument_list|(
operator|&
name|eprol
argument_list|,
operator|&
name|etext
argument_list|)
expr_stmt|;
endif|#
directive|endif
endif|MCRT0
name|errno
operator|=
literal|0
expr_stmt|;
name|exit
argument_list|(
name|main
argument_list|(
name|kfp
operator|->
name|kargc
argument_list|,
name|argv
argument_list|,
name|environ
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_block

begin_ifdef
ifdef|#
directive|ifdef
name|MCRT0
end_ifdef

begin_comment
comment|/*ARGSUSED*/
end_comment

begin_expr_stmt
name|exit
argument_list|(
name|code
argument_list|)
specifier|register
name|int
name|code
expr_stmt|;
end_expr_stmt

begin_block
block|{
name|_mcleanup
argument_list|()
expr_stmt|;
name|_cleanup
argument_list|()
expr_stmt|;
name|_exit
argument_list|(
name|code
argument_list|)
expr_stmt|;
block|}
end_block

begin_endif
endif|#
directive|endif
endif|MCRT0
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|CRT0
end_ifdef

begin_comment
comment|/*  * null mcount and moncontrol,  * just in case some routine is compiled for profiling  */
end_comment

begin_macro
name|moncontrol
argument_list|(
argument|val
argument_list|)
end_macro

begin_decl_stmt
name|int
name|val
decl_stmt|;
end_decl_stmt

begin_block
block|{  }
end_block

begin_macro
name|mcount
argument_list|()
end_macro

begin_block
block|{  }
end_block

begin_endif
endif|#
directive|endif
endif|CRT0
end_endif

end_unit

