begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*   *   * script - makes copy of terminal conversation. usage:   * script [ -n ] [ -s ] [ -q ] [ -a ] [ -S shell ] [ file ]   * conversation saved in file. default is DFNAME   *   */
end_comment

begin_define
define|#
directive|define
name|DFNAME
value|"typescript"
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|HOUXP
end_ifdef

begin_define
define|#
directive|define
name|STDSHELL
value|"/bin/sh"
end_define

begin_define
define|#
directive|define
name|NEWSHELL
value|"/p4/3723mrh/bin/csh"
end_define

begin_decl_stmt
name|char
modifier|*
name|shell
init|=
name|NEWSHELL
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|HOUXT
end_ifdef

begin_define
define|#
directive|define
name|STDSHELL
value|"/bin/sh"
end_define

begin_define
define|#
directive|define
name|NEWSHELL
value|"/t1/bruce/ucb/bin/csh"
end_define

begin_decl_stmt
name|char
modifier|*
name|shell
init|=
name|NEWSHELL
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|CORY
end_ifdef

begin_define
define|#
directive|define
name|STDSHELL
value|"/bin/sh"
end_define

begin_define
define|#
directive|define
name|NEWSHELL
value|"/bin/csh"
end_define

begin_decl_stmt
name|char
modifier|*
name|shell
init|=
name|NEWSHELL
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|CC
end_ifdef

begin_define
define|#
directive|define
name|STDSHELL
value|"/bin/sh"
end_define

begin_define
define|#
directive|define
name|NEWSHELL
value|"/bin/csh"
end_define

begin_decl_stmt
name|char
modifier|*
name|shell
init|=
name|NEWSHELL
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|STDSHELL
end_ifndef

begin_define
define|#
directive|define
name|V7ENV
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|V7ENV
end_ifdef

begin_comment
comment|/* used for version 7 with environments - gets your environment shell */
end_comment

begin_define
define|#
directive|define
name|STDSHELL
value|"/bin/sh"
end_define

begin_define
define|#
directive|define
name|NEWSHELL
value|"/bin/csh"
end_define

begin_decl_stmt
name|char
modifier|*
name|shell
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* initialized in the code */
end_comment

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

begin_define
define|#
directive|define
name|MODE
value|st_mode
end_define

begin_define
define|#
directive|define
name|STAT
value|stat
end_define

begin_function_decl
name|char
modifier|*
name|getenv
parameter_list|()
function_decl|;
end_function_decl

begin_else
else|#
directive|else
end_else

begin_comment
comment|/*  * The following is the structure of the block returned by  * the stat and fstat system calls.  */
end_comment

begin_struct
struct|struct
name|inode
block|{
name|char
name|i_minor
decl_stmt|;
comment|/* +0: minor device of i-node */
name|char
name|i_major
decl_stmt|;
comment|/* +1: major device */
name|int
name|i_number
decl_stmt|;
comment|/* +2 */
name|int
name|i_flags
decl_stmt|;
comment|/* +4: see below */
name|char
name|i_nlinks
decl_stmt|;
comment|/* +6: number of links to file */
name|char
name|i_uid
decl_stmt|;
comment|/* +7: user ID of owner */
name|char
name|i_gid
decl_stmt|;
comment|/* +8: group ID of owner */
name|char
name|i_size0
decl_stmt|;
comment|/* +9: high byte of 24-bit size */
name|int
name|i_size1
decl_stmt|;
comment|/* +10: low word of 24-bit size */
name|int
name|i_addr
index|[
literal|8
index|]
decl_stmt|;
comment|/* +12: block numbers or device number */
name|int
name|i_actime
index|[
literal|2
index|]
decl_stmt|;
comment|/* +28: time of last access */
name|int
name|i_modtime
index|[
literal|2
index|]
decl_stmt|;
comment|/* +32: time of last modification */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|IALLOC
value|0100000
end_define

begin_define
define|#
directive|define
name|IFMT
value|060000
end_define

begin_define
define|#
directive|define
name|IFDIR
value|040000
end_define

begin_define
define|#
directive|define
name|IFCHR
value|020000
end_define

begin_define
define|#
directive|define
name|IFBLK
value|060000
end_define

begin_define
define|#
directive|define
name|MODE
value|i_flags
end_define

begin_define
define|#
directive|define
name|STAT
value|inode
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
name|char
modifier|*
name|tty
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* name of users tty so can turn off writes */
end_comment

begin_function_decl
name|char
modifier|*
name|ttyname
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* std subroutine */
end_comment

begin_decl_stmt
name|int
name|mode
init|=
literal|0622
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* old permission bits for users tty */
end_comment

begin_decl_stmt
name|int
name|outpipe
index|[
literal|2
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* pipe from shell to output */
end_comment

begin_decl_stmt
name|int
name|fd
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* file descriptor of typescript file */
end_comment

begin_decl_stmt
name|int
name|inpipe
index|[
literal|2
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* pipe from input to shell */
end_comment

begin_decl_stmt
name|long
name|tvec
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* current time */
end_comment

begin_decl_stmt
name|char
name|buffer
index|[
literal|256
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* for block I/O's */
end_comment

begin_decl_stmt
name|int
name|n
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* number of chars read */
end_comment

begin_decl_stmt
name|int
name|status
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* dummy for wait sys call */
end_comment

begin_decl_stmt
name|char
modifier|*
name|fname
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* name of typescript file */
end_comment

begin_decl_stmt
name|int
name|forkval
decl_stmt|,
name|ttn
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* temps for error checking */
end_comment

begin_decl_stmt
name|int
name|qflg
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* true if -q (quiet) flag */
end_comment

begin_decl_stmt
name|int
name|aflg
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* true if -q (append) flag */
end_comment

begin_decl_stmt
name|struct
name|STAT
name|sbuf
decl_stmt|;
end_decl_stmt

begin_function_decl
name|int
name|flsh
parameter_list|()
function_decl|;
end_function_decl

begin_function
name|main
parameter_list|(
name|argc
parameter_list|,
name|argv
parameter_list|)
name|int
name|argc
decl_stmt|;
name|char
modifier|*
modifier|*
name|argv
decl_stmt|;
block|{
if|if
condition|(
operator|(
name|tty
operator|=
name|ttyname
argument_list|(
literal|2
argument_list|)
operator|)
operator|<
literal|0
condition|)
block|{
name|printf
argument_list|(
literal|"Nested script not allowed.\n"
argument_list|)
expr_stmt|;
name|fail
argument_list|()
expr_stmt|;
block|}
ifdef|#
directive|ifdef
name|V7ENV
name|shell
operator|=
name|getenv
argument_list|(
literal|"SHELL"
argument_list|)
expr_stmt|;
endif|#
directive|endif
while|while
condition|(
name|argc
operator|>
literal|1
operator|&&
name|argv
index|[
literal|1
index|]
index|[
literal|0
index|]
operator|==
literal|'-'
condition|)
block|{
switch|switch
condition|(
name|argv
index|[
literal|1
index|]
index|[
literal|1
index|]
condition|)
block|{
case|case
literal|'n'
case|:
name|shell
operator|=
name|NEWSHELL
expr_stmt|;
break|break;
case|case
literal|'s'
case|:
name|shell
operator|=
name|STDSHELL
expr_stmt|;
break|break;
case|case
literal|'S'
case|:
name|shell
operator|=
name|argv
index|[
literal|2
index|]
expr_stmt|;
name|argc
operator|--
expr_stmt|;
name|argv
operator|++
expr_stmt|;
break|break;
case|case
literal|'q'
case|:
name|qflg
operator|++
expr_stmt|;
break|break;
case|case
literal|'a'
case|:
name|aflg
operator|++
expr_stmt|;
break|break;
default|default:
name|printf
argument_list|(
literal|"Bad flag %s - ignored\n"
argument_list|,
name|argv
index|[
literal|1
index|]
argument_list|)
expr_stmt|;
block|}
name|argc
operator|--
expr_stmt|;
name|argv
operator|++
expr_stmt|;
block|}
if|if
condition|(
name|argc
operator|>
literal|1
condition|)
block|{
name|fname
operator|=
name|argv
index|[
literal|1
index|]
expr_stmt|;
if|if
condition|(
operator|!
name|aflg
operator|&&
name|stat
argument_list|(
name|fname
argument_list|,
operator|&
name|sbuf
argument_list|)
operator|>=
literal|0
condition|)
block|{
name|printf
argument_list|(
literal|"File %s already exists.\n"
argument_list|,
name|fname
argument_list|)
expr_stmt|;
name|done
argument_list|()
expr_stmt|;
block|}
block|}
else|else
name|fname
operator|=
name|DFNAME
expr_stmt|;
if|if
condition|(
operator|!
name|aflg
condition|)
block|{
name|fd
operator|=
name|creat
argument_list|(
name|fname
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|/* so can't cat/lpr typescript from inside */
block|}
else|else
block|{
comment|/* try to append to existing file first */
name|fd
operator|=
name|open
argument_list|(
name|fname
argument_list|,
literal|1
argument_list|)
expr_stmt|;
if|if
condition|(
name|fd
operator|>=
literal|0
condition|)
name|lseek
argument_list|(
name|fd
argument_list|,
literal|0l
argument_list|,
literal|2
argument_list|)
expr_stmt|;
else|else
name|fd
operator|=
name|creat
argument_list|(
name|fname
argument_list|,
literal|0
argument_list|)
expr_stmt|;
block|}
if|if
condition|(
name|fd
operator|<
literal|0
condition|)
block|{
name|printf
argument_list|(
literal|"Can't create %s\n"
argument_list|,
name|fname
argument_list|)
expr_stmt|;
if|if
condition|(
name|unlink
argument_list|(
name|fname
argument_list|)
operator|==
literal|0
condition|)
block|{
name|printf
argument_list|(
literal|"because of previous typescript bomb - try again\n"
argument_list|)
expr_stmt|;
block|}
name|fail
argument_list|()
expr_stmt|;
block|}
name|chmod
argument_list|(
name|fname
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|/* in case it already exists */
name|fixtty
argument_list|()
expr_stmt|;
if|if
condition|(
operator|!
name|qflg
condition|)
block|{
name|printf
argument_list|(
literal|"Script started, file is %s\n"
argument_list|,
name|fname
argument_list|)
expr_stmt|;
name|check
argument_list|(
name|write
argument_list|(
name|fd
argument_list|,
literal|"Script started on "
argument_list|,
literal|18
argument_list|)
argument_list|)
expr_stmt|;
name|time
argument_list|(
operator|&
name|tvec
argument_list|)
expr_stmt|;
name|check
argument_list|(
name|write
argument_list|(
name|fd
argument_list|,
name|ctime
argument_list|(
operator|&
name|tvec
argument_list|)
argument_list|,
literal|25
argument_list|)
argument_list|)
expr_stmt|;
block|}
name|pipe
argument_list|(
name|inpipe
argument_list|)
expr_stmt|;
name|pipe
argument_list|(
name|outpipe
argument_list|)
expr_stmt|;
name|forkval
operator|=
name|fork
argument_list|()
expr_stmt|;
if|if
condition|(
name|forkval
operator|<
literal|0
condition|)
block|{
name|printf
argument_list|(
literal|"Fork failed - try again.\n"
argument_list|)
expr_stmt|;
name|fail
argument_list|()
expr_stmt|;
block|}
if|if
condition|(
name|forkval
operator|==
literal|0
condition|)
name|doshell
argument_list|()
expr_stmt|;
name|forkval
operator|=
name|fork
argument_list|()
expr_stmt|;
if|if
condition|(
name|forkval
operator|<
literal|0
condition|)
block|{
name|printf
argument_list|(
literal|"Fork failed. Try again.\n"
argument_list|)
expr_stmt|;
name|fail
argument_list|()
expr_stmt|;
block|}
if|if
condition|(
name|forkval
operator|==
literal|0
condition|)
name|dooutput
argument_list|()
expr_stmt|;
else|else
name|doinput
argument_list|()
expr_stmt|;
block|}
end_function

begin_macro
name|doinput
argument_list|()
end_macro

begin_block
block|{
name|int
name|done
parameter_list|()
function_decl|;
comment|/* input process - copy tty to pipe and file */
name|signal
argument_list|(
literal|2
argument_list|,
literal|1
argument_list|)
expr_stmt|;
comment|/* ignore interrupts from delete */
name|signal
argument_list|(
literal|3
argument_list|,
name|done
argument_list|)
expr_stmt|;
comment|/* fix files when users quits. */
name|close
argument_list|(
name|inpipe
index|[
literal|0
index|]
argument_list|)
expr_stmt|;
name|close
argument_list|(
name|outpipe
index|[
literal|0
index|]
argument_list|)
expr_stmt|;
name|close
argument_list|(
name|outpipe
index|[
literal|1
index|]
argument_list|)
expr_stmt|;
comment|/* main input loop - copy until end of file (ctrl D) */
while|while
condition|(
name|n
operator|=
name|read
argument_list|(
literal|0
argument_list|,
name|buffer
argument_list|,
literal|256
argument_list|)
condition|)
block|{
name|check
argument_list|(
name|write
argument_list|(
name|fd
argument_list|,
name|buffer
argument_list|,
name|n
argument_list|)
argument_list|)
expr_stmt|;
name|write
argument_list|(
name|inpipe
index|[
literal|1
index|]
argument_list|,
name|buffer
argument_list|,
name|n
argument_list|)
expr_stmt|;
block|}
comment|/* end of script - close files and exit */
name|close
argument_list|(
name|inpipe
index|[
literal|1
index|]
argument_list|)
expr_stmt|;
name|close
argument_list|(
name|fd
argument_list|)
expr_stmt|;
name|wait
argument_list|(
operator|&
name|status
argument_list|)
expr_stmt|;
comment|/* wait for shell to terminate */
name|wait
argument_list|(
operator|&
name|status
argument_list|)
expr_stmt|;
comment|/* wait for output to terminate */
name|done
argument_list|()
expr_stmt|;
block|}
end_block

begin_macro
name|dooutput
argument_list|()
end_macro

begin_block
block|{
comment|/* do output process - copy to tty& file */
name|signal
argument_list|(
literal|2
argument_list|,
name|flsh
argument_list|)
expr_stmt|;
comment|/* trap to flsh on interrupts */
name|signal
argument_list|(
literal|3
argument_list|,
literal|1
argument_list|)
expr_stmt|;
comment|/* ignore quits */
name|close
argument_list|(
literal|0
argument_list|)
expr_stmt|;
name|close
argument_list|(
name|inpipe
index|[
literal|0
index|]
argument_list|)
expr_stmt|;
name|close
argument_list|(
name|inpipe
index|[
literal|1
index|]
argument_list|)
expr_stmt|;
name|close
argument_list|(
name|outpipe
index|[
literal|1
index|]
argument_list|)
expr_stmt|;
comment|/* main output proc loop */
while|while
condition|(
name|n
operator|=
name|read
argument_list|(
name|outpipe
index|[
literal|0
index|]
argument_list|,
name|buffer
argument_list|,
literal|256
argument_list|)
condition|)
block|{
if|if
condition|(
name|n
operator|>
literal|0
condition|)
block|{
comment|/* -1 means trap to flsh just happened */
name|write
argument_list|(
literal|1
argument_list|,
name|buffer
argument_list|,
name|n
argument_list|)
expr_stmt|;
name|check
argument_list|(
name|write
argument_list|(
name|fd
argument_list|,
name|buffer
argument_list|,
name|n
argument_list|)
argument_list|)
expr_stmt|;
block|}
block|}
comment|/* output sees eof - close files and exit */
if|if
condition|(
operator|!
name|qflg
condition|)
block|{
name|printf
argument_list|(
literal|"Script done, file is %s\n"
argument_list|,
name|fname
argument_list|)
expr_stmt|;
name|check
argument_list|(
name|write
argument_list|(
name|fd
argument_list|,
literal|"\nscript done on "
argument_list|,
literal|16
argument_list|)
argument_list|)
expr_stmt|;
name|time
argument_list|(
operator|&
name|tvec
argument_list|)
expr_stmt|;
name|check
argument_list|(
name|write
argument_list|(
name|fd
argument_list|,
name|ctime
argument_list|(
operator|&
name|tvec
argument_list|)
argument_list|,
literal|25
argument_list|)
argument_list|)
expr_stmt|;
block|}
name|close
argument_list|(
name|fd
argument_list|)
expr_stmt|;
name|exit
argument_list|()
expr_stmt|;
block|}
end_block

begin_macro
name|doshell
argument_list|()
end_macro

begin_block
block|{
comment|/* exec shell, after divirting std input& output */
name|close
argument_list|(
literal|0
argument_list|)
expr_stmt|;
name|dup
argument_list|(
name|inpipe
index|[
literal|0
index|]
argument_list|)
expr_stmt|;
name|close
argument_list|(
literal|1
argument_list|)
expr_stmt|;
name|dup
argument_list|(
name|outpipe
index|[
literal|1
index|]
argument_list|)
expr_stmt|;
name|close
argument_list|(
literal|2
argument_list|)
expr_stmt|;
name|dup
argument_list|(
name|outpipe
index|[
literal|1
index|]
argument_list|)
expr_stmt|;
comment|/* close useless files */
name|close
argument_list|(
name|inpipe
index|[
literal|0
index|]
argument_list|)
expr_stmt|;
name|close
argument_list|(
name|inpipe
index|[
literal|1
index|]
argument_list|)
expr_stmt|;
name|close
argument_list|(
name|outpipe
index|[
literal|0
index|]
argument_list|)
expr_stmt|;
name|close
argument_list|(
name|outpipe
index|[
literal|1
index|]
argument_list|)
expr_stmt|;
comment|/*	signal(2,1);	/* shell should ignore interrupts */
name|execl
argument_list|(
name|shell
argument_list|,
literal|"sh"
argument_list|,
literal|"-i"
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|execl
argument_list|(
name|STDSHELL
argument_list|,
literal|"sh"
argument_list|,
literal|"-i"
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|execl
argument_list|(
name|NEWSHELL
argument_list|,
literal|"sh"
argument_list|,
literal|"-i"
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"Can't execute shell\n"
argument_list|)
expr_stmt|;
name|fail
argument_list|()
expr_stmt|;
block|}
end_block

begin_macro
name|fixtty
argument_list|()
end_macro

begin_block
block|{
name|fstat
argument_list|(
literal|2
argument_list|,
operator|&
name|sbuf
argument_list|)
expr_stmt|;
name|mode
operator|=
name|sbuf
operator|.
name|MODE
operator|&
literal|0777
expr_stmt|;
name|chmod
argument_list|(
name|tty
argument_list|,
literal|0600
argument_list|)
expr_stmt|;
block|}
end_block

begin_macro
name|flsh
argument_list|()
end_macro

begin_block
block|{
comment|/* come here on rubout to flush output - this doesn't work */
name|signal
argument_list|(
literal|2
argument_list|,
name|flsh
argument_list|)
expr_stmt|;
comment|/* lseek(outpipe[0],0l,2);	/* seeks on pipes don't work !"$"$!! */
block|}
end_block

begin_macro
name|fail
argument_list|()
end_macro

begin_block
block|{
name|unlink
argument_list|(
name|fname
argument_list|)
expr_stmt|;
name|kill
argument_list|(
literal|0
argument_list|,
literal|15
argument_list|)
expr_stmt|;
comment|/* shut off other script processes */
name|done
argument_list|()
expr_stmt|;
block|}
end_block

begin_macro
name|done
argument_list|()
end_macro

begin_block
block|{
name|chmod
argument_list|(
name|tty
argument_list|,
name|mode
argument_list|)
expr_stmt|;
name|chmod
argument_list|(
name|fname
argument_list|,
literal|0664
argument_list|)
expr_stmt|;
name|exit
argument_list|()
expr_stmt|;
block|}
end_block

begin_ifndef
ifndef|#
directive|ifndef
name|V7ENV
end_ifndef

begin_ifndef
ifndef|#
directive|ifndef
name|CC
end_ifndef

begin_function
name|char
modifier|*
name|ttyname
parameter_list|(
name|i
parameter_list|)
name|int
name|i
decl_stmt|;
block|{
name|char
modifier|*
name|string
decl_stmt|;
name|string
operator|=
literal|"/dev/ttyx"
expr_stmt|;
name|string
index|[
literal|8
index|]
operator|=
name|ttyn
argument_list|(
name|fd
argument_list|)
expr_stmt|;
if|if
condition|(
name|string
index|[
literal|8
index|]
operator|==
literal|'x'
condition|)
return|return
operator|(
operator|(
name|char
operator|*
operator|)
operator|(
operator|-
literal|1
operator|)
operator|)
return|;
else|else
return|return
operator|(
name|string
operator|)
return|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_macro
name|check
argument_list|(
argument|n
argument_list|)
end_macro

begin_decl_stmt
name|int
name|n
decl_stmt|;
end_decl_stmt

begin_block
block|{
comment|/* checks the result of a write call, if neg 	   assume ran out of disk space& die */
if|if
condition|(
name|n
operator|<
literal|0
condition|)
block|{
name|write
argument_list|(
literal|1
argument_list|,
literal|"Disk quota exceeded - script quits\n"
argument_list|,
literal|35
argument_list|)
expr_stmt|;
name|kill
argument_list|(
literal|0
argument_list|,
literal|15
argument_list|)
expr_stmt|;
name|done
argument_list|()
expr_stmt|;
block|}
block|}
end_block

end_unit

