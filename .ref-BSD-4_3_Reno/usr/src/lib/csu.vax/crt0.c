begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1980 Regents of the University of California.  * All rights reserved.  The Berkeley software License Agreement  * specifies the terms and conditions for redistribution.  */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|LIBC_SCCS
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|lint
argument_list|)
end_if

begin_decl_stmt
specifier|static
name|char
name|sccsid
index|[]
init|=
literal|"@(#)crt0.c	5.4 (Berkeley) 1/18/88"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
endif|LIBC_SCCS and not lint
end_endif

begin_comment
comment|/*  *	C start up routine.  *	Robert Henry, UCB, 20 Oct 81  *  *	We make the following (true) assumptions:  *	1) when the kernel calls start, it does a jump to location 2,  *	and thus avoids the register save mask.  We are NOT called  *	with a calls!  see sys1.c:setregs().  *	2) The only register variable that we can trust is sp,  *	which points to the base of the kernel calling frame.  *	Do NOT believe the documentation in exec(2) regarding the  *	values of fp and ap.  *	3) We can allocate as many register variables as we want,  *	and don't have to save them for anybody.  *	4) Because of the ways that asm's work, we can't have  *	any automatic variables allocated on the stack, because  *	we must catch the value of sp before any automatics are  *	allocated.  */
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

begin_asm
asm|asm("#define _start start");
end_asm

begin_asm
asm|asm("#define _eprol eprol");
end_asm

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
decl_stmt|;
end_decl_stmt

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
comment|/* 	 *	ALL REGISTER VARIABLES!!! 	 */
specifier|register
name|int
name|r11
decl_stmt|;
comment|/* needed for init */
specifier|register
name|struct
name|kframe
modifier|*
name|kfp
decl_stmt|;
comment|/* r10 */
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
ifdef|#
directive|ifdef
name|lint
name|kfp
operator|=
literal|0
expr_stmt|;
name|initcode
operator|=
name|initcode
operator|=
literal|0
expr_stmt|;
else|#
directive|else
else|not lint
asm|asm("	movl	sp,r10");
comment|/* catch it quick */
endif|#
directive|endif
endif|not lint
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
name|paranoid
comment|/* 	 * The standard I/O library assumes that file descriptors 0, 1, and 2 	 * are open. If one of these descriptors is closed prior to the start  	 * of the process, I/O gets very confused. To avoid this problem, we 	 * insure that the first three file descriptors are open before calling 	 * main(). Normally this is undefined, as it adds two unnecessary 	 * system calls. 	 */
do|do
block|{
name|fd
operator|=
name|open
argument_list|(
literal|"/dev/null"
argument_list|,
literal|2
argument_list|)
expr_stmt|;
block|}
do|while
condition|(
name|fd
operator|>=
literal|0
operator|&&
name|fd
operator|<
literal|3
condition|)
do|;
name|close
argument_list|(
name|fd
argument_list|)
expr_stmt|;
endif|#
directive|endif
endif|paranoid
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

begin_asm
asm|asm("#undef _start");
end_asm

begin_asm
asm|asm("#undef _eprol");
end_asm

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

begin_comment
comment|/* r11 */
end_comment

begin_block
block|{
name|monitor
argument_list|(
literal|0
argument_list|)
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

begin_asm
asm|asm("	.globl	mcount");
end_asm

begin_asm
asm|asm("mcount:	rsb");
end_asm

begin_endif
endif|#
directive|endif
endif|CRT0
end_endif

end_unit

