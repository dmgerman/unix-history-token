begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1992 Keith Muller.  * Copyright (c) 1992, 1993  *	The Regents of the University of California.  All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * Keith Muller of the University of California, San Diego.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	$Id: pax.c,v 1.5.2.2 1997/09/14 13:07:29 jkh Exp $  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|lint
end_ifndef

begin_decl_stmt
specifier|static
name|char
specifier|const
name|copyright
index|[]
init|=
literal|"@(#) Copyright (c) 1992, 1993\n\ 	The Regents of the University of California.  All rights reserved.\n"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* not lint */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|lint
end_ifndef

begin_decl_stmt
specifier|static
name|char
specifier|const
name|sccsid
index|[]
init|=
literal|"@(#)pax.c	8.2 (Berkeley) 4/18/94"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* not lint */
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

begin_include
include|#
directive|include
file|<sys/time.h>
end_include

begin_include
include|#
directive|include
file|<sys/resource.h>
end_include

begin_include
include|#
directive|include
file|<errno.h>
end_include

begin_include
include|#
directive|include
file|<locale.h>
end_include

begin_include
include|#
directive|include
file|<signal.h>
end_include

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_include
include|#
directive|include
file|<stdlib.h>
end_include

begin_include
include|#
directive|include
file|<unistd.h>
end_include

begin_include
include|#
directive|include
file|"pax.h"
end_include

begin_include
include|#
directive|include
file|"extern.h"
end_include

begin_decl_stmt
specifier|static
name|int
name|gen_init
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * PAX main routines, general globals and some simple start up routines  */
end_comment

begin_comment
comment|/*  * Variables that can be accessed by any routine within pax  */
end_comment

begin_decl_stmt
name|int
name|act
init|=
name|DEFOP
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* read/write/append/copy */
end_comment

begin_decl_stmt
name|FSUB
modifier|*
name|frmt
init|=
name|NULL
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* archive format type */
end_comment

begin_decl_stmt
name|int
name|cflag
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* match all EXCEPT pattern/file */
end_comment

begin_decl_stmt
name|int
name|dflag
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* directory member match only  */
end_comment

begin_decl_stmt
name|int
name|iflag
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* interactive file/archive rename */
end_comment

begin_decl_stmt
name|int
name|kflag
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* do not overwrite existing files */
end_comment

begin_decl_stmt
name|int
name|lflag
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* use hard links when possible */
end_comment

begin_decl_stmt
name|int
name|nflag
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* select first archive member match */
end_comment

begin_decl_stmt
name|int
name|tflag
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* restore access time after read */
end_comment

begin_decl_stmt
name|int
name|uflag
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* ignore older modification time files */
end_comment

begin_decl_stmt
name|int
name|vflag
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* produce verbose output */
end_comment

begin_decl_stmt
name|int
name|Dflag
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* same as uflag except inode change time */
end_comment

begin_decl_stmt
name|int
name|Hflag
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* follow command line symlinks (write only) */
end_comment

begin_decl_stmt
name|int
name|Lflag
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* follow symlinks when writing */
end_comment

begin_decl_stmt
name|int
name|Xflag
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* archive files with same device id only */
end_comment

begin_decl_stmt
name|int
name|Yflag
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* same as Dflg except after name mode */
end_comment

begin_decl_stmt
name|int
name|Zflag
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* same as uflg except after name mode */
end_comment

begin_decl_stmt
name|int
name|vfpart
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* is partial verbose output in progress */
end_comment

begin_decl_stmt
name|int
name|patime
init|=
literal|1
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* preserve file access time */
end_comment

begin_decl_stmt
name|int
name|pmtime
init|=
literal|1
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* preserve file modification times */
end_comment

begin_decl_stmt
name|int
name|pmode
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* preserve file mode bits */
end_comment

begin_decl_stmt
name|int
name|pids
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* preserve file uid/gid */
end_comment

begin_decl_stmt
name|int
name|exit_val
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* exit value */
end_comment

begin_decl_stmt
name|int
name|docrc
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* check/create file crc */
end_comment

begin_decl_stmt
name|char
modifier|*
name|dirptr
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* destination dir in a copy */
end_comment

begin_decl_stmt
name|char
modifier|*
name|ltmfrmt
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* -v locale time format (if any) */
end_comment

begin_decl_stmt
name|char
modifier|*
name|argv0
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* root of argv[0] */
end_comment

begin_decl_stmt
name|sigset_t
name|s_mask
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* signal mask for cleanup critical sect */
end_comment

begin_comment
comment|/*  *	PAX - Portable Archive Interchange  *  * 	A utility to read, write, and write lists of the members of archive  *	files and copy directory hierarchies. A variety of archive formats  *	are supported (some are described in POSIX 1003.1 10.1):  *  *		ustar - 10.1.1 extended tar interchange format  *		cpio  - 10.1.2 extended cpio interchange format  *		tar - old BSD 4.3 tar format  *		binary cpio - old cpio with binary header format  *		sysVR4 cpio -  with and without CRC  *  * This version is a superset of IEEE Std 1003.2b-d3  *  * Summary of Extensions to the IEEE Standard:  *  * 1	READ ENHANCEMENTS  * 1.1	Operations which read archives will continue to operate even when  *	processing archives which may be damaged, truncated, or fail to meet  *	format specs in several different ways. Damaged sections of archives  *	are detected and avoided if possible. Attempts will be made to resync  *	archive read operations even with badly damaged media.  * 1.2	Blocksize requirements are not strictly enforced on archive read.  *	Tapes which have variable sized records can be read without errors.  * 1.3	The user can specify via the non-standard option flag -E if error  *	resync operation should stop on a media error, try a specified number  *	of times to correct, or try to correct forever.  * 1.4	Sparse files (lseek holes) stored on the archive (but stored with blocks  *	of all zeros will be restored with holes appropriate for the target  *	filesystem  * 1.5	The user is notified whenever something is found during archive  *	read operations which violates spec (but the read will continue).  * 1.6	Multiple archive volumes can be read and may span over different  *	archive devices  * 1.7	Rigidly restores all file attributes exactly as they are stored on the  *	archive.  * 1.8	Modification change time ranges can be specified via multiple -T  *	options. These allow a user to select files whose modification time  *	lies within a specific time range.  * 1.9	Files can be selected based on owner (user name or uid) via one or more  *	-U options.  * 1.10	Files can be selected based on group (group name or gid) via one o  *	more -G options.  * 1.11	File modification time can be checked against exisiting file after  *	name modification (-Z)  *  * 2	WRITE ENHANCEMENTS  * 2.1	Write operation will stop instead of allowing a user to create a flawed  *	flawed archive (due to any problem).  * 2.2	Archives writtens by pax are forced to strictly conform to both the  *	archive and pax the spceific format specifications.  * 2.3	Blocking size and format is rigidly enforced on writes.  * 2.4	Formats which may exhibit header overflow problems (they have fields  *	too small for large file systems, such as inode number storage), use  *	routines designed to repair this problem. These techniques still  *	conform to both pax and format specifications, but no longer truncate  *	these fields. This removes any restrictions on using these archive  *	formats on large file systems.  * 2.5	Multiple archive volumes can be written and may span over different  *	archive devices  * 2.6	A archive volume record limit allows the user to specify the number  *	of bytes stored on an archive volume. When reached the user is  *	prompted for the next archive volume. This is specified with the  *	non-standard -B flag. THe limit is rounded up to the next blocksize.  * 2.7	All archive padding during write use zero filled sections. This makes  *	it much easier to pull data out of flawed archive during read  *	operations.  * 2.8	Access time reset with the -t applies to all file nodes (including  *	directories).  * 2.9	Symbolic links can be followed with -L (optional in the spec).  * 2.10	Modification or inode change time ranges can be specified via  *	multiple -T options. These allow a user to select files whose  *	modification or inode change time lies within a specific time range.  * 2.11	Files can be selected based on owner (user name or uid) via one or more  *	-U options.  * 2.12	Files can be selected based on group (group name or gid) via one o  *	more -G options.  * 2.13	Symlinks which appear on the command line can be followed (without  *	following other symlinks; -H flag)  *  * 3	COPY ENHANCEMENTS  * 3.1	Sparse files (lseek holes) can be copied without expanding the holes  *	into zero filled blocks. The file copy is created with holes which are  *	appropriate for the target filesystem  * 3.2	Access time as well as modification time on copied file trees can be  *	preserved with the appropriate -p options.  * 3.3	Access time reset with the -t applies to all file nodes (including  *	directories).  * 3.4	Symbolic links can be followed with -L (optional in the spec).  * 3.5	Modification or inode change time ranges can be specified via  *	multiple -T options. These allow a user to select files whose  *	modification or inode change time lies within a specific time range.  * 3.6	Files can be selected based on owner (user name or uid) via one or more  *	-U options.  * 3.7	Files can be selected based on group (group name or gid) via one o  *	more -G options.  * 3.8	Symlinks which appear on the command line can be followed (without  *	following other symlinks; -H flag)  * 3.9  File inode change time can be checked against exisiting file before  *	name modification (-D)  * 3.10 File inode change time can be checked against exisiting file after  *	name modification (-Y)  * 3.11	File modification time can be checked against exisiting file after  *	name modification (-Z)  *  * 4	GENERAL ENHANCEMENTS  * 4.1	Internal structure is designed to isolate format dependent and  *	independent functions. Formats are selected via a format driver table.  *	This encourages the addition of new archive formats by only having to  *	write those routines which id, read and write the archive header.  */
end_comment

begin_comment
comment|/*  * main()  *	parse options, set up and operate as specified by the user.  *	any operational flaw will set exit_val to non-zero  * Return: 0 if ok, 1 otherwise  */
end_comment

begin_if
if|#
directive|if
name|__STDC__
end_if

begin_function
name|int
name|main
parameter_list|(
name|int
name|argc
parameter_list|,
name|char
modifier|*
modifier|*
name|argv
parameter_list|)
else|#
directive|else
function|int main
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
endif|#
directive|endif
block|{
operator|(
name|void
operator|)
name|setlocale
argument_list|(
name|LC_ALL
argument_list|,
literal|""
argument_list|)
expr_stmt|;
comment|/* 	 * parse options, determine operational mode, general init 	 */
name|options
argument_list|(
name|argc
argument_list|,
name|argv
argument_list|)
expr_stmt|;
if|if
condition|(
operator|(
name|gen_init
argument_list|()
operator|<
literal|0
operator|)
operator|||
operator|(
name|tty_init
argument_list|()
operator|<
literal|0
operator|)
condition|)
return|return
operator|(
name|exit_val
operator|)
return|;
comment|/* 	 * select a primary operation mode 	 */
switch|switch
condition|(
name|act
condition|)
block|{
case|case
name|EXTRACT
case|:
name|extract
argument_list|()
expr_stmt|;
break|break;
case|case
name|ARCHIVE
case|:
name|archive
argument_list|()
expr_stmt|;
break|break;
case|case
name|APPND
case|:
name|append
argument_list|()
expr_stmt|;
break|break;
case|case
name|COPY
case|:
name|copy
argument_list|()
expr_stmt|;
break|break;
default|default:
case|case
name|LIST
case|:
name|list
argument_list|()
expr_stmt|;
break|break;
block|}
return|return
operator|(
name|exit_val
operator|)
return|;
block|}
end_function

begin_comment
comment|/*  * sig_cleanup()  *	when interrupted we try to do whatever delayed processing we can.  *	This is not critical, but we really ought to limit our damage when we  *	are aborted by the user.  * Return:  *	never....  */
end_comment

begin_if
if|#
directive|if
name|__STDC__
end_if

begin_function
name|void
name|sig_cleanup
parameter_list|(
name|int
name|which_sig
parameter_list|)
else|#
directive|else
function|void sig_cleanup
parameter_list|(
name|which_sig
parameter_list|)
name|int
name|which_sig
decl_stmt|;
endif|#
directive|endif
block|{
comment|/* 	 * restore modes and times for any dirs we may have created 	 * or any dirs we may have read. Set vflag and vfpart so the user 	 * will clearly see the message on a line by itself. 	 */
name|vflag
operator|=
name|vfpart
operator|=
literal|1
expr_stmt|;
if|if
condition|(
name|which_sig
operator|==
name|SIGXCPU
condition|)
name|pax_warn
argument_list|(
literal|0
argument_list|,
literal|"Cpu time limit reached, cleaning up."
argument_list|)
expr_stmt|;
else|else
name|pax_warn
argument_list|(
literal|0
argument_list|,
literal|"Signal caught, cleaning up."
argument_list|)
expr_stmt|;
name|ar_close
argument_list|()
expr_stmt|;
name|proc_dir
argument_list|()
expr_stmt|;
if|if
condition|(
name|tflag
condition|)
name|atdir_end
argument_list|()
expr_stmt|;
name|exit
argument_list|(
literal|1
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|/*  * gen_init()  *	general setup routines. Not all are required, but they really help  *	when dealing with a medium to large sized archives.  */
end_comment

begin_if
if|#
directive|if
name|__STDC__
end_if

begin_decl_stmt
specifier|static
name|int
name|gen_init
argument_list|(
name|void
argument_list|)
else|#
directive|else
decl|static
name|int
name|gen_init
argument_list|()
endif|#
directive|endif
block|{
name|struct
name|rlimit
name|reslimit
decl_stmt|;
name|struct
name|sigaction
name|n_hand
decl_stmt|;
name|struct
name|sigaction
name|o_hand
decl_stmt|;
comment|/* 	 * Really needed to handle large archives. We can run out of memory for 	 * internal tables really fast when we have a whole lot of files... 	 */
if|if
condition|(
name|getrlimit
argument_list|(
name|RLIMIT_DATA
argument_list|,
operator|&
name|reslimit
argument_list|)
operator|==
literal|0
condition|)
block|{
name|reslimit
operator|.
name|rlim_cur
operator|=
name|reslimit
operator|.
name|rlim_max
expr_stmt|;
operator|(
name|void
operator|)
name|setrlimit
argument_list|(
name|RLIMIT_DATA
argument_list|,
operator|&
name|reslimit
argument_list|)
expr_stmt|;
block|}
comment|/* 	 * should file size limits be waived? if the os limits us, this is 	 * needed if we want to write a large archive 	 */
if|if
condition|(
name|getrlimit
argument_list|(
name|RLIMIT_FSIZE
argument_list|,
operator|&
name|reslimit
argument_list|)
operator|==
literal|0
condition|)
block|{
name|reslimit
operator|.
name|rlim_cur
operator|=
name|reslimit
operator|.
name|rlim_max
expr_stmt|;
operator|(
name|void
operator|)
name|setrlimit
argument_list|(
name|RLIMIT_FSIZE
argument_list|,
operator|&
name|reslimit
argument_list|)
expr_stmt|;
block|}
comment|/* 	 * increase the size the stack can grow to 	 */
if|if
condition|(
name|getrlimit
argument_list|(
name|RLIMIT_STACK
argument_list|,
operator|&
name|reslimit
argument_list|)
operator|==
literal|0
condition|)
block|{
name|reslimit
operator|.
name|rlim_cur
operator|=
name|reslimit
operator|.
name|rlim_max
expr_stmt|;
operator|(
name|void
operator|)
name|setrlimit
argument_list|(
name|RLIMIT_STACK
argument_list|,
operator|&
name|reslimit
argument_list|)
expr_stmt|;
block|}
comment|/* 	 * not really needed, but doesn't hurt 	 */
if|if
condition|(
name|getrlimit
argument_list|(
name|RLIMIT_RSS
argument_list|,
operator|&
name|reslimit
argument_list|)
operator|==
literal|0
condition|)
block|{
name|reslimit
operator|.
name|rlim_cur
operator|=
name|reslimit
operator|.
name|rlim_max
expr_stmt|;
operator|(
name|void
operator|)
name|setrlimit
argument_list|(
name|RLIMIT_RSS
argument_list|,
operator|&
name|reslimit
argument_list|)
expr_stmt|;
block|}
comment|/* 	 * Handle posix locale 	 * 	 * set user defines time printing format for -v option 	 */
name|ltmfrmt
operator|=
name|getenv
argument_list|(
literal|"LC_TIME"
argument_list|)
expr_stmt|;
comment|/* 	 * signal handling to reset stored directory times and modes. Since 	 * we deal with broken pipes via failed writes we ignore it. We also 	 * deal with any file size limit thorugh failed writes. Cpu time 	 * limits are caught and a cleanup is forced. 	 */
if|if
condition|(
operator|(
name|sigemptyset
argument_list|(
operator|&
name|s_mask
argument_list|)
operator|<
literal|0
operator|)
operator|||
operator|(
name|sigaddset
argument_list|(
operator|&
name|s_mask
argument_list|,
name|SIGTERM
argument_list|)
operator|<
literal|0
operator|)
operator|||
operator|(
name|sigaddset
argument_list|(
operator|&
name|s_mask
argument_list|,
name|SIGINT
argument_list|)
operator|<
literal|0
operator|)
operator|||
operator|(
name|sigaddset
argument_list|(
operator|&
name|s_mask
argument_list|,
name|SIGHUP
argument_list|)
operator|<
literal|0
operator|)
operator|||
operator|(
name|sigaddset
argument_list|(
operator|&
name|s_mask
argument_list|,
name|SIGPIPE
argument_list|)
operator|<
literal|0
operator|)
operator|||
operator|(
name|sigaddset
argument_list|(
operator|&
name|s_mask
argument_list|,
name|SIGQUIT
argument_list|)
operator|<
literal|0
operator|)
operator|||
operator|(
name|sigaddset
argument_list|(
operator|&
name|s_mask
argument_list|,
name|SIGXCPU
argument_list|)
operator|<
literal|0
operator|)
operator|||
operator|(
name|sigaddset
argument_list|(
operator|&
name|s_mask
argument_list|,
name|SIGXFSZ
argument_list|)
operator|<
literal|0
operator|)
condition|)
block|{
name|pax_warn
argument_list|(
literal|1
argument_list|,
literal|"Unable to set up signal mask"
argument_list|)
expr_stmt|;
return|return
operator|(
operator|-
literal|1
operator|)
return|;
block|}
name|n_hand
operator|.
name|sa_mask
operator|=
name|s_mask
expr_stmt|;
name|n_hand
operator|.
name|sa_flags
operator|=
literal|0
expr_stmt|;
name|n_hand
operator|.
name|sa_handler
operator|=
name|sig_cleanup
expr_stmt|;
if|if
condition|(
operator|(
name|sigaction
argument_list|(
name|SIGHUP
argument_list|,
operator|&
name|n_hand
argument_list|,
operator|&
name|o_hand
argument_list|)
operator|<
literal|0
operator|)
operator|&&
operator|(
name|o_hand
operator|.
name|sa_handler
operator|==
name|SIG_IGN
operator|)
operator|&&
operator|(
name|sigaction
argument_list|(
name|SIGHUP
argument_list|,
operator|&
name|o_hand
argument_list|,
operator|&
name|o_hand
argument_list|)
operator|<
literal|0
operator|)
condition|)
goto|goto
name|out
goto|;
if|if
condition|(
operator|(
name|sigaction
argument_list|(
name|SIGTERM
argument_list|,
operator|&
name|n_hand
argument_list|,
operator|&
name|o_hand
argument_list|)
operator|<
literal|0
operator|)
operator|&&
operator|(
name|o_hand
operator|.
name|sa_handler
operator|==
name|SIG_IGN
operator|)
operator|&&
operator|(
name|sigaction
argument_list|(
name|SIGTERM
argument_list|,
operator|&
name|o_hand
argument_list|,
operator|&
name|o_hand
argument_list|)
operator|<
literal|0
operator|)
condition|)
goto|goto
name|out
goto|;
if|if
condition|(
operator|(
name|sigaction
argument_list|(
name|SIGINT
argument_list|,
operator|&
name|n_hand
argument_list|,
operator|&
name|o_hand
argument_list|)
operator|<
literal|0
operator|)
operator|&&
operator|(
name|o_hand
operator|.
name|sa_handler
operator|==
name|SIG_IGN
operator|)
operator|&&
operator|(
name|sigaction
argument_list|(
name|SIGINT
argument_list|,
operator|&
name|o_hand
argument_list|,
operator|&
name|o_hand
argument_list|)
operator|<
literal|0
operator|)
condition|)
goto|goto
name|out
goto|;
if|if
condition|(
operator|(
name|sigaction
argument_list|(
name|SIGQUIT
argument_list|,
operator|&
name|n_hand
argument_list|,
operator|&
name|o_hand
argument_list|)
operator|<
literal|0
operator|)
operator|&&
operator|(
name|o_hand
operator|.
name|sa_handler
operator|==
name|SIG_IGN
operator|)
operator|&&
operator|(
name|sigaction
argument_list|(
name|SIGQUIT
argument_list|,
operator|&
name|o_hand
argument_list|,
operator|&
name|o_hand
argument_list|)
operator|<
literal|0
operator|)
condition|)
goto|goto
name|out
goto|;
if|if
condition|(
operator|(
name|sigaction
argument_list|(
name|SIGXCPU
argument_list|,
operator|&
name|n_hand
argument_list|,
operator|&
name|o_hand
argument_list|)
operator|<
literal|0
operator|)
operator|&&
operator|(
name|o_hand
operator|.
name|sa_handler
operator|==
name|SIG_IGN
operator|)
operator|&&
operator|(
name|sigaction
argument_list|(
name|SIGXCPU
argument_list|,
operator|&
name|o_hand
argument_list|,
operator|&
name|o_hand
argument_list|)
operator|<
literal|0
operator|)
condition|)
goto|goto
name|out
goto|;
name|n_hand
operator|.
name|sa_handler
operator|=
name|SIG_IGN
expr_stmt|;
if|if
condition|(
operator|(
name|sigaction
argument_list|(
name|SIGPIPE
argument_list|,
operator|&
name|n_hand
argument_list|,
operator|&
name|o_hand
argument_list|)
operator|<
literal|0
operator|)
operator|||
operator|(
name|sigaction
argument_list|(
name|SIGXFSZ
argument_list|,
operator|&
name|n_hand
argument_list|,
operator|&
name|o_hand
argument_list|)
operator|<
literal|0
operator|)
condition|)
goto|goto
name|out
goto|;
return|return
operator|(
literal|0
operator|)
return|;
name|out
label|:
name|sys_warn
argument_list|(
literal|1
argument_list|,
name|errno
argument_list|,
literal|"Unable to set up signal handler"
argument_list|)
expr_stmt|;
return|return
operator|(
operator|-
literal|1
operator|)
return|;
block|}
end_decl_stmt

end_unit

