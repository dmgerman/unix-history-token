begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1992, 1993  *	The Regents of the University of California.  All rights reserved.  *  * This software was developed by the Computer Systems Engineering group  * at Lawrence Berkeley Laboratory under DARPA contract BG 91-66 and  * contributed to Berkeley.  *  * %sccs.include.redist.c%  */
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
literal|"@(#)crt0.c	8.1 (Berkeley) %G%"
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
comment|/*  *	C start up routine.  */
end_comment

begin_include
include|#
directive|include
file|<stddef.h>
end_include

begin_include
include|#
directive|include
file|<stdlib.h>
end_include

begin_include
include|#
directive|include
file|<string.h>
end_include

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
name|char
name|empty
index|[
literal|1
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|__progname
init|=
name|empty
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|unsigned
name|char
name|etext
index|[]
decl_stmt|;
end_decl_stmt

begin_extern
extern|extern volatile void start(
end_extern

begin_asm
unit|)
asm|asm("start0");
end_asm

begin_decl_stmt
specifier|extern
name|unsigned
name|char
name|eprol
index|[]
name|asm
argument_list|(
literal|"eprol"
argument_list|)
decl_stmt|;
end_decl_stmt

begin_function_decl
specifier|extern
name|void
name|_mcleanup
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function
specifier|volatile
name|void
name|start
parameter_list|(
name|void
parameter_list|)
block|{
struct|struct
name|kframe
block|{
name|int
name|regarea
index|[
literal|16
index|]
decl_stmt|;
comment|/* space for %i and %o variables */
name|int
name|kargc
decl_stmt|;
comment|/* argument count */
name|char
modifier|*
name|kargv
index|[
literal|1
index|]
decl_stmt|;
comment|/* actual size depends on kargc */
block|}
struct|;
specifier|register
name|struct
name|kframe
modifier|*
name|sp
name|asm
argument_list|(
literal|"%sp"
argument_list|)
decl_stmt|;
specifier|register
name|int
name|argc
decl_stmt|;
specifier|register
name|char
modifier|*
modifier|*
name|argv
decl_stmt|,
modifier|*
modifier|*
name|envp
decl_stmt|;
specifier|extern
name|int
name|errno
decl_stmt|;
asm|asm(".globl start");
asm|asm("start:");
name|argc
operator|=
name|sp
operator|->
name|kargc
expr_stmt|;
name|argv
operator|=
operator|&
name|sp
operator|->
name|kargv
index|[
literal|0
index|]
expr_stmt|;
name|environ
operator|=
name|envp
operator|=
operator|&
name|argv
index|[
name|argc
operator|+
literal|1
index|]
expr_stmt|;
name|sp
operator|=
operator|(
expr|struct
name|kframe
operator|*
operator|)
operator|(
operator|(
name|int
operator|)
name|sp
operator|-
literal|16
operator|)
expr_stmt|;
asm|asm("eprol:");
ifdef|#
directive|ifdef
name|paranoid
comment|/* 	 * The standard I/O library assumes that file descriptors 0, 1, and 2 	 * are open. If one of these descriptors is closed prior to the start  	 * of the process, I/O gets very confused. To avoid this problem, we 	 * insure that the first three file descriptors are open before calling 	 * main(). Normally this is undefined, as it adds two unnecessary 	 * system calls. 	 */
block|{
specifier|register
name|int
name|fd
decl_stmt|;
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
block|}
endif|#
directive|endif
ifdef|#
directive|ifdef
name|MCRT0
name|monstartup
argument_list|(
name|eprol
argument_list|,
name|etext
argument_list|)
expr_stmt|;
name|atexit
argument_list|(
name|_mcleanup
argument_list|)
expr_stmt|;
name|errno
operator|=
literal|0
expr_stmt|;
endif|#
directive|endif
if|if
condition|(
name|argv
index|[
literal|0
index|]
condition|)
if|if
condition|(
operator|(
name|__progname
operator|=
name|strrchr
argument_list|(
name|argv
index|[
literal|0
index|]
argument_list|,
literal|'/'
argument_list|)
operator|)
operator|==
name|NULL
condition|)
name|__progname
operator|=
name|argv
index|[
literal|0
index|]
expr_stmt|;
else|else
operator|++
name|__progname
expr_stmt|;
name|exit
argument_list|(
name|main
argument_list|(
name|argc
argument_list|,
name|argv
argument_list|,
name|envp
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_function

begin_ifdef
ifdef|#
directive|ifdef
name|CRT0
end_ifdef

begin_comment
comment|/*  * null mcount and moncontrol,  * just in case some routine is compiled for profiling  */
end_comment

begin_asm
asm|asm(".globl mcount");
end_asm

begin_asm
asm|asm(".globl _moncontrol");
end_asm

begin_asm
asm|asm("mcount: _moncontrol: retl; nop");
end_asm

begin_endif
endif|#
directive|endif
end_endif

end_unit

