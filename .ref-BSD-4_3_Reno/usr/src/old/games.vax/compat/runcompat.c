begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_decl_stmt
specifier|static
name|char
name|sccsid
index|[]
init|=
literal|"@(#)runcompat.c	4.2 83/07/31"
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  *	Compatability mode support  *	written by Art Wetzel during August 1979  *	at the Interdisciplinary Dept of Information Science  *	Room 711, LIS Bldg  *	University of Pittsburgh  *	Pittsburgh, Pa 15260  *  *	No claims are made on the completeness of the support of any  *	of the systems simulated under this package  */
end_comment

begin_include
include|#
directive|include
file|<stdio.h>
end_include

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

begin_include
include|#
directive|include
file|<sys/stat.h>
end_include

begin_include
include|#
directive|include
file|<errno.h>
end_include

begin_include
include|#
directive|include
file|"defs.h"
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|UNIX
end_ifdef

begin_include
include|#
directive|include
file|"unixhdr.h"
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|RT11
end_ifdef

begin_include
include|#
directive|include
file|"rt11.h"
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
name|struct
name|stat
name|stat32v
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|u_short
name|regs
index|[
literal|8
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|u_long
name|psl
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|u_short
modifier|*
name|pc
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|incompat
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|progname
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|nameend
decl_stmt|;
end_decl_stmt

begin_function
name|main
parameter_list|(
name|argc
parameter_list|,
name|argv
parameter_list|,
name|envp
parameter_list|)
name|int
name|argc
decl_stmt|;
name|char
modifier|*
modifier|*
name|argv
decl_stmt|,
decl|*
modifier|*
name|envp
decl_stmt|;
end_function

begin_block
block|{
if|if
condition|(
name|argc
operator|<
literal|2
condition|)
block|{
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"Usage: %s [-rootdir] file args...\n"
argument_list|,
name|argv
index|[
literal|0
index|]
argument_list|)
expr_stmt|;
name|exit
argument_list|(
literal|1
argument_list|)
expr_stmt|;
block|}
comment|/* remember where the program name etc should go for using ps */
name|progname
operator|=
name|argv
index|[
literal|0
index|]
expr_stmt|;
name|nameend
operator|=
name|envp
index|[
literal|0
index|]
operator|-
literal|1
expr_stmt|;
name|argv
operator|++
expr_stmt|;
comment|/* set up alternate root directory if flagged for */
if|if
condition|(
operator|*
name|argv
index|[
literal|0
index|]
operator|==
literal|'-'
condition|)
block|{
if|if
condition|(
name|chroot
argument_list|(
name|argv
index|[
literal|0
index|]
operator|+
literal|1
argument_list|)
condition|)
block|{
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"Can't change root to %s\n"
argument_list|,
name|argv
index|[
literal|0
index|]
operator|+
literal|1
argument_list|)
expr_stmt|;
name|exit
argument_list|(
operator|-
literal|1
argument_list|)
expr_stmt|;
block|}
name|argv
operator|++
expr_stmt|;
block|}
comment|/* check out file stats of file to run */
if|if
condition|(
name|stat
argument_list|(
name|argv
index|[
literal|0
index|]
argument_list|,
operator|&
name|stat32v
argument_list|)
condition|)
block|{
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"%s does not exist\n"
argument_list|,
name|argv
index|[
literal|0
index|]
argument_list|)
expr_stmt|;
name|exit
argument_list|(
literal|1
argument_list|)
expr_stmt|;
block|}
comment|/* a version of SETUID and SETGID file executions */
comment|/* the binary of this program should be SETUID root for this to work */
comment|/* requires nonstandard seteuid and setegid sys calls */
if|if
condition|(
operator|!
operator|(
name|stat32v
operator|.
name|st_mode
operator|&
name|S_ISGID
operator|)
operator|||
name|setegid
argument_list|(
name|stat32v
operator|.
name|st_gid
argument_list|)
condition|)
comment|/* if not SETGID file or error, drop back to real group */
name|setgid
argument_list|(
name|getgid
argument_list|()
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
operator|(
name|stat32v
operator|.
name|st_mode
operator|&
name|S_ISUID
operator|)
operator|||
name|seteuid
argument_list|(
name|stat32v
operator|.
name|st_uid
argument_list|)
condition|)
comment|/* if not SETUID file or error, drop back to real uid */
name|setuid
argument_list|(
name|getuid
argument_list|()
argument_list|)
expr_stmt|;
ifdef|#
directive|ifdef
name|V6UNIX
comment|/* no umasks in version 6 */
name|umask
argument_list|(
literal|0
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|/* go try to execute , passing along args and environment */
name|execute
argument_list|(
name|argv
index|[
literal|0
index|]
argument_list|,
name|argv
argument_list|,
name|envp
argument_list|)
expr_stmt|;
comment|/* only get here if execute fails */
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"Execution failure on %s\n"
argument_list|,
name|argv
index|[
literal|0
index|]
argument_list|)
expr_stmt|;
name|exit
argument_list|(
literal|1
argument_list|)
expr_stmt|;
block|}
end_block

begin_macro
name|execute
argument_list|(
argument|file
argument_list|,
argument|argv
argument_list|,
argument|envp
argument_list|)
end_macro

begin_decl_stmt
name|char
modifier|*
name|file
decl_stmt|,
modifier|*
modifier|*
name|argv
decl_stmt|,
modifier|*
modifier|*
name|envp
decl_stmt|;
end_decl_stmt

begin_block
block|{
name|int
name|fd
decl_stmt|,
name|n
decl_stmt|,
name|tloadpt
decl_stmt|,
name|dloadpt
decl_stmt|,
name|tloadsize
decl_stmt|,
name|dloadsize
decl_stmt|,
name|stacksize
decl_stmt|;
specifier|register
name|short
modifier|*
name|p
decl_stmt|;
extern|extern illtrap(
block|)
end_block

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
modifier|*
name|environ
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* file to run should be readable */
end_comment

begin_if
if|if
condition|(
operator|(
name|fd
operator|=
name|open
argument_list|(
name|file
argument_list|,
literal|0
argument_list|)
operator|)
operator|==
operator|-
literal|1
condition|)
block|{
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"Can't open %s for read access\n"
argument_list|,
name|file
argument_list|)
expr_stmt|;
return|return
operator|(
operator|-
literal|1
operator|)
return|;
block|}
end_if

begin_ifdef
ifdef|#
directive|ifdef
name|UNIX
end_ifdef

begin_if
if|if
condition|(
operator|(
name|n
operator|=
name|read
argument_list|(
name|fd
argument_list|,
operator|&
name|header
argument_list|,
sizeof|sizeof
name|header
argument_list|)
operator|)
operator|!=
sizeof|sizeof
name|header
condition|)
return|return
operator|(
name|ENOEXEC
operator|)
return|;
end_if

begin_comment
comment|/* check to see if really unix file */
end_comment

begin_if
if|if
condition|(
name|header
operator|.
name|magic
operator|!=
name|MAGIC1
operator|&&
name|header
operator|.
name|magic
operator|!=
name|MAGIC2
operator|&&
name|header
operator|.
name|magic
operator|!=
name|MAGIC3
operator|&&
name|header
operator|.
name|magic
operator|!=
name|MAGIC4
condition|)
block|{
return|return
operator|(
name|ENOEXEC
operator|)
return|;
block|}
end_if

begin_comment
comment|/* if a UNIX file run it */
end_comment

begin_if
if|if
condition|(
name|header
operator|.
name|textsize
operator|==
literal|0
condition|)
block|{
name|close
argument_list|(
name|fd
argument_list|)
expr_stmt|;
comment|/* if no explicit env, pass along environ */
if|if
condition|(
operator|!
name|envp
operator|||
operator|*
name|envp
operator|==
literal|0
condition|)
return|return
operator|(
name|execve
argument_list|(
name|file
argument_list|,
name|argv
argument_list|,
name|environ
argument_list|)
operator|)
return|;
return|return
operator|(
name|execve
argument_list|(
name|file
argument_list|,
name|argv
argument_list|,
name|envp
argument_list|)
operator|)
return|;
block|}
end_if

begin_comment
comment|/* checks out OK as PDP-11 UNIX file */
end_comment

begin_if
if|if
condition|(
name|header
operator|.
name|magic
operator|==
name|MAGIC3
condition|)
block|{
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"%s compiled for separate I/D space\n"
argument_list|,
name|argv
index|[
literal|0
index|]
argument_list|)
expr_stmt|;
return|return
operator|(
operator|-
literal|1
operator|)
return|;
block|}
end_if

begin_comment
comment|/* unix text loads at 0 */
end_comment

begin_expr_stmt
name|tloadpt
operator|=
literal|0
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* set starting pc value */
end_comment

begin_expr_stmt
name|pc
operator|=
operator|(
name|unsigned
name|short
operator|*
operator|)
name|header
operator|.
name|entry
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* figure out where to load initialized data */
end_comment

begin_expr_stmt
name|dloadpt
operator|=
name|tloadsize
operator|=
name|header
operator|.
name|textsize
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* check if alignment of data segment to 8k byte boundary */
end_comment

begin_if
if|if
condition|(
name|header
operator|.
name|magic
operator|==
name|MAGIC2
condition|)
name|dloadpt
operator|=
operator|(
name|dloadpt
operator|+
literal|8191
operator|)
operator|&
operator|(
operator|~
literal|8191
operator|)
expr_stmt|;
end_if

begin_comment
comment|/* how much data */
end_comment

begin_expr_stmt
name|dloadsize
operator|=
name|header
operator|.
name|datasize
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|stacksize
operator|=
name|header
operator|.
name|bsssize
expr_stmt|;
end_expr_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|RT11
end_ifdef

begin_if
if|if
condition|(
operator|(
name|n
operator|=
name|read
argument_list|(
name|fd
argument_list|,
name|shortspace
argument_list|,
name|RTHDRSIZ
argument_list|)
operator|)
operator|!=
name|RTHDRSIZ
condition|)
block|{
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"Error reading 1st block\n"
argument_list|)
expr_stmt|;
return|return
operator|(
operator|-
literal|1
operator|)
return|;
block|}
end_if

begin_comment
comment|/* rt11 files are 0 aligned including the header */
end_comment

begin_expr_stmt
name|tloadpt
operator|=
name|RTHDRSIZ
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* set starting pc value */
end_comment

begin_expr_stmt
name|pc
operator|=
operator|(
name|unsigned
name|short
operator|*
operator|)
name|shortspace
index|[
name|RTPC
index|]
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* initialize stack location */
end_comment

begin_expr_stmt
name|regs
index|[
literal|6
index|]
operator|=
name|shortspace
index|[
name|RTSP
index|]
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* figure how much to load */
end_comment

begin_expr_stmt
name|dloadpt
operator|=
name|tloadsize
operator|=
name|shortspace
index|[
name|RTHGH
index|]
operator|-
name|RTHDRSIZ
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* no separate data as in unix */
end_comment

begin_expr_stmt
name|dloadsize
operator|=
literal|0
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|stacksize
operator|=
literal|0
expr_stmt|;
end_expr_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* see if it all fits into available memory space */
end_comment

begin_if
if|if
condition|(
operator|(
name|dloadpt
operator|+
name|dloadsize
operator|+
name|stacksize
operator|)
operator|>
operator|(
name|int
operator|)
name|memsiz
condition|)
block|{
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"File too big to run\n"
argument_list|)
expr_stmt|;
return|return
operator|(
operator|-
literal|1
operator|)
return|;
block|}
end_if

begin_comment
comment|/* read text segment */
end_comment

begin_if
if|if
condition|(
operator|(
name|n
operator|=
name|read
argument_list|(
name|fd
argument_list|,
name|tloadpt
argument_list|,
name|tloadsize
argument_list|)
operator|)
operator|<
name|tloadsize
condition|)
block|{
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"Text read failure\n"
argument_list|)
expr_stmt|;
return|return
operator|(
operator|-
literal|1
operator|)
return|;
block|}
end_if

begin_comment
comment|/* read data segment */
end_comment

begin_if
if|if
condition|(
operator|(
name|n
operator|=
name|read
argument_list|(
name|fd
argument_list|,
name|dloadpt
argument_list|,
name|dloadsize
argument_list|)
operator|)
operator|<
name|dloadsize
condition|)
block|{
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"Data read failure\n"
argument_list|)
expr_stmt|;
return|return
operator|(
operator|-
literal|1
operator|)
return|;
block|}
end_if

begin_comment
comment|/* clear out the rest of memory */
end_comment

begin_expr_stmt
name|p
operator|=
operator|(
name|short
operator|*
operator|)
operator|(
name|dloadpt
operator|+
name|dloadsize
operator|)
expr_stmt|;
end_expr_stmt

begin_while
while|while
condition|(
name|p
operator|<
operator|(
name|short
operator|*
operator|)
name|memsiz
condition|)
operator|*
name|p
operator|++
operator|=
literal|0
expr_stmt|;
end_while

begin_comment
comment|/* close file before starting it */
end_comment

begin_expr_stmt
name|close
argument_list|(
name|fd
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* set up illegal instruction trapping */
end_comment

begin_expr_stmt
name|signal
argument_list|(
name|SIGILL
argument_list|,
name|illtrap
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* lets give it a try */
end_comment

begin_expr_stmt
name|start
argument_list|(
name|argv
argument_list|,
name|envp
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
unit|}  illtrap
operator|(
name|signum
operator|,
name|faultcode
operator|,
name|scp
operator|)
name|int
name|signum
operator|,
name|faultcode
expr_stmt|;
end_expr_stmt

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
name|int
name|instr
decl_stmt|;
specifier|register
name|int
name|i
decl_stmt|;
extern|extern getregs(
block|)
end_block

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
comment|/* record the fact that we are not in compatability mode now */
end_comment

begin_expr_stmt
name|incompat
operator|=
literal|0
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* get the register values before they get clobbered */
end_comment

begin_expr_stmt
name|getregs
argument_list|()
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* figure out what the pc was */
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
comment|/* get the instruction */
end_comment

begin_expr_stmt
name|instr
operator|=
operator|*
name|pc
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* incriment the pc over this instruction */
end_comment

begin_expr_stmt
name|pc
operator|++
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* set register 7 as pc synonym */
end_comment

begin_expr_stmt
name|regs
index|[
literal|7
index|]
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
end_expr_stmt

begin_comment
comment|/* set up psl with condition codes */
end_comment

begin_comment
comment|/* a UNIX-32V monitor patch is required to not clear condition codes */
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

begin_expr_stmt
name|sigsetmask
argument_list|(
name|scp
operator|->
name|sc_mask
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* pick out the appropriate action for this illegal instruction */
end_comment

begin_switch
switch|switch
condition|(
name|instr
operator|>>
literal|8
condition|)
block|{
case|case
name|TRAPS
case|:
name|dotrap
argument_list|(
name|instr
operator|&
literal|0377
argument_list|)
expr_stmt|;
break|break;
case|case
name|EMTS
case|:
if|if
condition|(
name|sigvals
index|[
name|SIGEMT
index|]
operator|&&
operator|(
operator|(
name|sigvals
index|[
name|SIGEMT
index|]
operator|%
literal|2
operator|)
operator|!=
literal|1
operator|)
condition|)
block|{
name|dosig
argument_list|(
name|SIGEMT
argument_list|,
name|pc
argument_list|)
expr_stmt|;
break|break;
block|}
name|doemt
argument_list|(
name|instr
operator|&
literal|0377
argument_list|)
expr_stmt|;
break|break;
default|default:
if|if
condition|(
name|instr
operator|>=
literal|075000
operator|&&
name|instr
operator|<
literal|075040
condition|)
block|{
comment|/* fis instructions */
if|if
condition|(
name|dofloat
argument_list|(
name|instr
argument_list|)
operator|==
literal|0
condition|)
break|break;
block|}
if|if
condition|(
name|instr
operator|>=
literal|0170000
condition|)
block|{
comment|/* floating point unit instructions */
if|if
condition|(
name|dofloat
argument_list|(
name|instr
argument_list|)
operator|==
literal|0
condition|)
break|break;
block|}
comment|/* genuine illegal instruction */
comment|/* if signal trap set go to user's trap location */
if|if
condition|(
name|sigvals
index|[
name|SIGILL
index|]
operator|&&
operator|(
operator|(
name|sigvals
index|[
name|SIGILL
index|]
operator|%
literal|2
operator|)
operator|!=
literal|1
operator|)
condition|)
block|{
name|dosig
argument_list|(
name|SIGILL
argument_list|,
name|pc
argument_list|)
expr_stmt|;
break|break;
block|}
comment|/* ignore uncaught setd instructions */
if|if
condition|(
name|instr
operator|==
name|SETD
condition|)
break|break;
comment|/* otherwise put out a message and quit */
name|printf
argument_list|(
literal|"Illegal instruction, psl 0x%08x, pc 0%04o\n"
argument_list|,
name|psl
argument_list|,
name|pc
operator|-
literal|1
argument_list|)
expr_stmt|;
for|for
control|(
name|i
operator|=
literal|0
init|;
name|i
operator|<
literal|7
condition|;
name|i
operator|++
control|)
name|printf
argument_list|(
literal|"0x%04x  "
argument_list|,
name|regs
index|[
name|i
index|]
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"0x%04x -> 0%o\n"
argument_list|,
name|pc
operator|-
literal|1
argument_list|,
name|instr
argument_list|)
expr_stmt|;
comment|/* set up to dump on illegal instruction */
name|signal
argument_list|(
name|SIGILL
argument_list|,
name|SIG_DFL
argument_list|)
expr_stmt|;
comment|/* set pc back to bad instruction */
name|pc
operator|--
expr_stmt|;
comment|/* go do it again for dump */
name|compat
argument_list|()
expr_stmt|;
block|}
end_switch

begin_comment
comment|/* go back to compatability mode */
end_comment

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

unit|}
end_unit

