begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1992 Keith Muller.  * Copyright (c) 1992, 1993  *	The Regents of the University of California.  All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * Keith Muller of the University of California, San Diego.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|lint
end_ifndef

begin_if
if|#
directive|if
literal|0
end_if

begin_endif
unit|static char sccsid[] = "@(#)ar_io.c	8.2 (Berkeley) 4/18/94";
endif|#
directive|endif
end_endif

begin_decl_stmt
specifier|static
specifier|const
name|char
name|rcsid
index|[]
init|=
literal|"$FreeBSD$"
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
file|<sys/ioctl.h>
end_include

begin_include
include|#
directive|include
file|<sys/mtio.h>
end_include

begin_include
include|#
directive|include
file|<sys/stat.h>
end_include

begin_include
include|#
directive|include
file|<sys/wait.h>
end_include

begin_include
include|#
directive|include
file|<err.h>
end_include

begin_include
include|#
directive|include
file|<errno.h>
end_include

begin_include
include|#
directive|include
file|<fcntl.h>
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
file|<string.h>
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
file|"options.h"
end_include

begin_include
include|#
directive|include
file|"extern.h"
end_include

begin_comment
comment|/*  * Routines which deal directly with the archive I/O device/file.  */
end_comment

begin_define
define|#
directive|define
name|DMOD
value|0666
end_define

begin_comment
comment|/* default mode of created archives */
end_comment

begin_define
define|#
directive|define
name|EXT_MODE
value|O_RDONLY
end_define

begin_comment
comment|/* open mode for list/extract */
end_comment

begin_define
define|#
directive|define
name|AR_MODE
value|(O_WRONLY | O_CREAT | O_TRUNC)
end_define

begin_comment
comment|/* mode for archive */
end_comment

begin_define
define|#
directive|define
name|APP_MODE
value|O_RDWR
end_define

begin_comment
comment|/* mode for append */
end_comment

begin_define
define|#
directive|define
name|STDO
value|"<STDOUT>"
end_define

begin_comment
comment|/* pseudo name for stdout */
end_comment

begin_define
define|#
directive|define
name|STDN
value|"<STDIN>"
end_define

begin_comment
comment|/* pseudo name for stdin */
end_comment

begin_decl_stmt
specifier|static
name|int
name|arfd
init|=
operator|-
literal|1
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* archive file descriptor */
end_comment

begin_decl_stmt
specifier|static
name|int
name|artyp
init|=
name|ISREG
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* archive type: file/FIFO/tape */
end_comment

begin_decl_stmt
specifier|static
name|int
name|arvol
init|=
literal|1
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* archive volume number */
end_comment

begin_decl_stmt
specifier|static
name|int
name|lstrval
init|=
operator|-
literal|1
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* return value from last i/o */
end_comment

begin_decl_stmt
specifier|static
name|int
name|io_ok
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* i/o worked on volume after resync */
end_comment

begin_decl_stmt
specifier|static
name|int
name|did_io
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* did i/o ever occur on volume? */
end_comment

begin_decl_stmt
specifier|static
name|int
name|done
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* set via tty termination */
end_comment

begin_decl_stmt
specifier|static
name|struct
name|stat
name|arsb
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* stat of archive device at open */
end_comment

begin_decl_stmt
specifier|static
name|int
name|invld_rec
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* tape has out of spec record size */
end_comment

begin_decl_stmt
specifier|static
name|int
name|wr_trail
init|=
literal|1
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* trailer was rewritten in append */
end_comment

begin_decl_stmt
specifier|static
name|int
name|can_unlnk
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* do we unlink null archives?  */
end_comment

begin_decl_stmt
name|char
modifier|*
name|arcname
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* printable name of archive */
end_comment

begin_decl_stmt
specifier|const
name|char
modifier|*
name|gzip_program
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* name of gzip program */
end_comment

begin_decl_stmt
specifier|static
name|pid_t
name|zpid
init|=
operator|-
literal|1
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* pid of child process */
end_comment

begin_function_decl
specifier|static
name|int
name|get_phys
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
specifier|extern
name|sigset_t
name|s_mask
decl_stmt|;
end_decl_stmt

begin_function_decl
specifier|static
name|void
name|ar_start_gzip
parameter_list|(
name|int
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * ar_open()  *	Opens the next archive volume. Determines the type of the device and  *	sets up block sizes as required by the archive device and the format.  *	Note: we may be called with name == NULL on the first open only.  * Return:  *	-1 on failure, 0 otherwise  */
end_comment

begin_function
name|int
name|ar_open
parameter_list|(
name|char
modifier|*
name|name
parameter_list|)
block|{
name|struct
name|mtget
name|mb
decl_stmt|;
if|if
condition|(
name|arfd
operator|!=
operator|-
literal|1
condition|)
operator|(
name|void
operator|)
name|close
argument_list|(
name|arfd
argument_list|)
expr_stmt|;
name|arfd
operator|=
operator|-
literal|1
expr_stmt|;
name|can_unlnk
operator|=
name|did_io
operator|=
name|io_ok
operator|=
name|invld_rec
operator|=
literal|0
expr_stmt|;
name|artyp
operator|=
name|ISREG
expr_stmt|;
name|flcnt
operator|=
literal|0
expr_stmt|;
comment|/* 	 * open based on overall operation mode 	 */
switch|switch
condition|(
name|act
condition|)
block|{
case|case
name|LIST
case|:
case|case
name|EXTRACT
case|:
if|if
condition|(
name|name
operator|==
name|NULL
condition|)
block|{
name|arfd
operator|=
name|STDIN_FILENO
expr_stmt|;
name|arcname
operator|=
name|STDN
expr_stmt|;
block|}
elseif|else
if|if
condition|(
operator|(
name|arfd
operator|=
name|open
argument_list|(
name|name
argument_list|,
name|EXT_MODE
argument_list|,
name|DMOD
argument_list|)
operator|)
operator|<
literal|0
condition|)
name|syswarn
argument_list|(
literal|0
argument_list|,
name|errno
argument_list|,
literal|"Failed open to read on %s"
argument_list|,
name|name
argument_list|)
expr_stmt|;
if|if
condition|(
name|arfd
operator|!=
operator|-
literal|1
operator|&&
name|gzip_program
operator|!=
name|NULL
condition|)
name|ar_start_gzip
argument_list|(
name|arfd
argument_list|,
name|gzip_program
argument_list|,
literal|0
argument_list|)
expr_stmt|;
break|break;
case|case
name|ARCHIVE
case|:
if|if
condition|(
name|name
operator|==
name|NULL
condition|)
block|{
name|arfd
operator|=
name|STDOUT_FILENO
expr_stmt|;
name|arcname
operator|=
name|STDO
expr_stmt|;
block|}
elseif|else
if|if
condition|(
operator|(
name|arfd
operator|=
name|open
argument_list|(
name|name
argument_list|,
name|AR_MODE
argument_list|,
name|DMOD
argument_list|)
operator|)
operator|<
literal|0
condition|)
name|syswarn
argument_list|(
literal|0
argument_list|,
name|errno
argument_list|,
literal|"Failed open to write on %s"
argument_list|,
name|name
argument_list|)
expr_stmt|;
else|else
name|can_unlnk
operator|=
literal|1
expr_stmt|;
if|if
condition|(
name|arfd
operator|!=
operator|-
literal|1
operator|&&
name|gzip_program
operator|!=
name|NULL
condition|)
name|ar_start_gzip
argument_list|(
name|arfd
argument_list|,
name|gzip_program
argument_list|,
literal|1
argument_list|)
expr_stmt|;
break|break;
case|case
name|APPND
case|:
if|if
condition|(
name|name
operator|==
name|NULL
condition|)
block|{
name|arfd
operator|=
name|STDOUT_FILENO
expr_stmt|;
name|arcname
operator|=
name|STDO
expr_stmt|;
block|}
elseif|else
if|if
condition|(
operator|(
name|arfd
operator|=
name|open
argument_list|(
name|name
argument_list|,
name|APP_MODE
argument_list|,
name|DMOD
argument_list|)
operator|)
operator|<
literal|0
condition|)
name|syswarn
argument_list|(
literal|0
argument_list|,
name|errno
argument_list|,
literal|"Failed open to read/write on %s"
argument_list|,
name|name
argument_list|)
expr_stmt|;
break|break;
case|case
name|COPY
case|:
comment|/* 		 * arfd not used in COPY mode 		 */
name|arcname
operator|=
literal|"<NONE>"
expr_stmt|;
name|lstrval
operator|=
literal|1
expr_stmt|;
return|return
operator|(
literal|0
operator|)
return|;
block|}
if|if
condition|(
name|arfd
operator|<
literal|0
condition|)
return|return
operator|(
operator|-
literal|1
operator|)
return|;
if|if
condition|(
name|chdname
operator|!=
name|NULL
condition|)
if|if
condition|(
name|chdir
argument_list|(
name|chdname
argument_list|)
operator|!=
literal|0
condition|)
name|syswarn
argument_list|(
literal|1
argument_list|,
name|errno
argument_list|,
literal|"Failed chdir to %s"
argument_list|,
name|chdname
argument_list|)
expr_stmt|;
comment|/* 	 * set up is based on device type 	 */
if|if
condition|(
name|fstat
argument_list|(
name|arfd
argument_list|,
operator|&
name|arsb
argument_list|)
operator|<
literal|0
condition|)
block|{
name|syswarn
argument_list|(
literal|0
argument_list|,
name|errno
argument_list|,
literal|"Failed stat on %s"
argument_list|,
name|arcname
argument_list|)
expr_stmt|;
operator|(
name|void
operator|)
name|close
argument_list|(
name|arfd
argument_list|)
expr_stmt|;
name|arfd
operator|=
operator|-
literal|1
expr_stmt|;
name|can_unlnk
operator|=
literal|0
expr_stmt|;
return|return
operator|(
operator|-
literal|1
operator|)
return|;
block|}
if|if
condition|(
name|S_ISDIR
argument_list|(
name|arsb
operator|.
name|st_mode
argument_list|)
condition|)
block|{
name|paxwarn
argument_list|(
literal|0
argument_list|,
literal|"Cannot write an archive on top of a directory %s"
argument_list|,
name|arcname
argument_list|)
expr_stmt|;
operator|(
name|void
operator|)
name|close
argument_list|(
name|arfd
argument_list|)
expr_stmt|;
name|arfd
operator|=
operator|-
literal|1
expr_stmt|;
name|can_unlnk
operator|=
literal|0
expr_stmt|;
return|return
operator|(
operator|-
literal|1
operator|)
return|;
block|}
if|if
condition|(
name|S_ISCHR
argument_list|(
name|arsb
operator|.
name|st_mode
argument_list|)
condition|)
name|artyp
operator|=
name|ioctl
argument_list|(
name|arfd
argument_list|,
name|MTIOCGET
argument_list|,
operator|&
name|mb
argument_list|)
condition|?
name|ISCHR
else|:
name|ISTAPE
expr_stmt|;
elseif|else
if|if
condition|(
name|S_ISBLK
argument_list|(
name|arsb
operator|.
name|st_mode
argument_list|)
condition|)
name|artyp
operator|=
name|ISBLK
expr_stmt|;
elseif|else
if|if
condition|(
operator|(
name|lseek
argument_list|(
name|arfd
argument_list|,
operator|(
name|off_t
operator|)
literal|0L
argument_list|,
name|SEEK_CUR
argument_list|)
operator|==
operator|-
literal|1
operator|)
operator|&&
operator|(
name|errno
operator|==
name|ESPIPE
operator|)
condition|)
name|artyp
operator|=
name|ISPIPE
expr_stmt|;
else|else
name|artyp
operator|=
name|ISREG
expr_stmt|;
comment|/* 	 * make sure we beyond any doubt that we only can unlink regular files 	 * we created 	 */
if|if
condition|(
name|artyp
operator|!=
name|ISREG
condition|)
name|can_unlnk
operator|=
literal|0
expr_stmt|;
comment|/* 	 * if we are writing, we are done 	 */
if|if
condition|(
name|act
operator|==
name|ARCHIVE
condition|)
block|{
name|blksz
operator|=
name|rdblksz
operator|=
name|wrblksz
expr_stmt|;
name|lstrval
operator|=
literal|1
expr_stmt|;
return|return
operator|(
literal|0
operator|)
return|;
block|}
comment|/* 	 * set default blksz on read. APPNDs writes rdblksz on the last volume 	 * On all new archive volumes, we shift to wrblksz (if the user 	 * specified one, otherwize we will continue to use rdblksz). We 	 * must to set blocksize based on what kind of device the archive is 	 * stored. 	 */
switch|switch
condition|(
name|artyp
condition|)
block|{
case|case
name|ISTAPE
case|:
comment|/* 		 * Tape drives come in at least two flavors. Those that support 		 * variable sized records and those that have fixed sized 		 * records. They must be treated differently. For tape drives 		 * that support variable sized records, we must make large 		 * reads to make sure we get the entire record, otherwise we 		 * will just get the first part of the record (up to size we 		 * asked). Tapes with fixed sized records may or may not return 		 * multiple records in a single read. We really do not care 		 * what the physical record size is UNLESS we are going to 		 * append. (We will need the physical block size to rewrite 		 * the trailer). Only when we are appending do we go to the 		 * effort to figure out the true PHYSICAL record size. 		 */
name|blksz
operator|=
name|rdblksz
operator|=
name|MAXBLK
expr_stmt|;
break|break;
case|case
name|ISPIPE
case|:
case|case
name|ISBLK
case|:
case|case
name|ISCHR
case|:
comment|/* 		 * Blocksize is not a major issue with these devices (but must 		 * be kept a multiple of 512). If the user specified a write 		 * block size, we use that to read. Under append, we must 		 * always keep blksz == rdblksz. Otherwise we go ahead and use 		 * the device optimal blocksize as (and if) returned by stat 		 * and if it is within pax specs. 		 */
if|if
condition|(
operator|(
name|act
operator|==
name|APPND
operator|)
operator|&&
name|wrblksz
condition|)
block|{
name|blksz
operator|=
name|rdblksz
operator|=
name|wrblksz
expr_stmt|;
break|break;
block|}
if|if
condition|(
operator|(
name|arsb
operator|.
name|st_blksize
operator|>
literal|0
operator|)
operator|&&
operator|(
name|arsb
operator|.
name|st_blksize
operator|<
name|MAXBLK
operator|)
operator|&&
operator|(
operator|(
name|arsb
operator|.
name|st_blksize
operator|%
name|BLKMULT
operator|)
operator|==
literal|0
operator|)
condition|)
name|rdblksz
operator|=
name|arsb
operator|.
name|st_blksize
expr_stmt|;
else|else
name|rdblksz
operator|=
name|DEVBLK
expr_stmt|;
comment|/* 		 * For performance go for large reads when we can without harm 		 */
if|if
condition|(
operator|(
name|act
operator|==
name|APPND
operator|)
operator|||
operator|(
name|artyp
operator|==
name|ISCHR
operator|)
condition|)
name|blksz
operator|=
name|rdblksz
expr_stmt|;
else|else
name|blksz
operator|=
name|MAXBLK
expr_stmt|;
break|break;
case|case
name|ISREG
case|:
comment|/* 		 * if the user specified wrblksz works, use it. Under appends 		 * we must always keep blksz == rdblksz 		 */
if|if
condition|(
operator|(
name|act
operator|==
name|APPND
operator|)
operator|&&
name|wrblksz
operator|&&
operator|(
operator|(
name|arsb
operator|.
name|st_size
operator|%
name|wrblksz
operator|)
operator|==
literal|0
operator|)
condition|)
block|{
name|blksz
operator|=
name|rdblksz
operator|=
name|wrblksz
expr_stmt|;
break|break;
block|}
comment|/* 		 * See if we can find the blocking factor from the file size 		 */
for|for
control|(
name|rdblksz
operator|=
name|MAXBLK
init|;
name|rdblksz
operator|>
literal|0
condition|;
name|rdblksz
operator|-=
name|BLKMULT
control|)
if|if
condition|(
operator|(
name|arsb
operator|.
name|st_size
operator|%
name|rdblksz
operator|)
operator|==
literal|0
condition|)
break|break;
comment|/* 		 * When we cannot find a match, we may have a flawed archive. 		 */
if|if
condition|(
name|rdblksz
operator|<=
literal|0
condition|)
name|rdblksz
operator|=
name|FILEBLK
expr_stmt|;
comment|/* 		 * for performance go for large reads when we can 		 */
if|if
condition|(
name|act
operator|==
name|APPND
condition|)
name|blksz
operator|=
name|rdblksz
expr_stmt|;
else|else
name|blksz
operator|=
name|MAXBLK
expr_stmt|;
break|break;
default|default:
comment|/* 		 * should never happen, worse case, slow... 		 */
name|blksz
operator|=
name|rdblksz
operator|=
name|BLKMULT
expr_stmt|;
break|break;
block|}
name|lstrval
operator|=
literal|1
expr_stmt|;
return|return
operator|(
literal|0
operator|)
return|;
block|}
end_function

begin_comment
comment|/*  * ar_close()  *	closes archive device, increments volume number, and prints i/o summary  */
end_comment

begin_function
name|void
name|ar_close
parameter_list|(
name|void
parameter_list|)
block|{
if|if
condition|(
name|arfd
operator|<
literal|0
condition|)
block|{
name|did_io
operator|=
name|io_ok
operator|=
name|flcnt
operator|=
literal|0
expr_stmt|;
return|return;
block|}
comment|/* 	 * Close archive file. This may take a LONG while on tapes (we may be 	 * forced to wait for the rewind to complete) so tell the user what is 	 * going on (this avoids the user hitting control-c thinking pax is 	 * broken). 	 */
if|if
condition|(
name|vflag
operator|&&
operator|(
name|artyp
operator|==
name|ISTAPE
operator|)
condition|)
block|{
if|if
condition|(
name|vfpart
condition|)
operator|(
name|void
operator|)
name|putc
argument_list|(
literal|'\n'
argument_list|,
name|listf
argument_list|)
expr_stmt|;
operator|(
name|void
operator|)
name|fprintf
argument_list|(
name|listf
argument_list|,
literal|"%s: Waiting for tape drive close to complete..."
argument_list|,
name|argv0
argument_list|)
expr_stmt|;
operator|(
name|void
operator|)
name|fflush
argument_list|(
name|listf
argument_list|)
expr_stmt|;
block|}
comment|/* 	 * if nothing was written to the archive (and we created it), we remove 	 * it 	 */
if|if
condition|(
name|can_unlnk
operator|&&
operator|(
name|fstat
argument_list|(
name|arfd
argument_list|,
operator|&
name|arsb
argument_list|)
operator|==
literal|0
operator|)
operator|&&
operator|(
name|S_ISREG
argument_list|(
name|arsb
operator|.
name|st_mode
argument_list|)
operator|)
operator|&&
operator|(
name|arsb
operator|.
name|st_size
operator|==
literal|0
operator|)
condition|)
block|{
operator|(
name|void
operator|)
name|unlink
argument_list|(
name|arcname
argument_list|)
expr_stmt|;
name|can_unlnk
operator|=
literal|0
expr_stmt|;
block|}
comment|/* 	 * for a quick extract/list, pax frequently exits before the child 	 * process is done 	 */
if|if
condition|(
operator|(
name|act
operator|==
name|LIST
operator|||
name|act
operator|==
name|EXTRACT
operator|)
operator|&&
name|nflag
operator|&&
name|zpid
operator|>
literal|0
condition|)
block|{
name|int
name|status
decl_stmt|;
name|kill
argument_list|(
name|zpid
argument_list|,
name|SIGINT
argument_list|)
expr_stmt|;
name|waitpid
argument_list|(
name|zpid
argument_list|,
operator|&
name|status
argument_list|,
literal|0
argument_list|)
expr_stmt|;
block|}
operator|(
name|void
operator|)
name|close
argument_list|(
name|arfd
argument_list|)
expr_stmt|;
if|if
condition|(
name|vflag
operator|&&
operator|(
name|artyp
operator|==
name|ISTAPE
operator|)
condition|)
block|{
operator|(
name|void
operator|)
name|fputs
argument_list|(
literal|"done.\n"
argument_list|,
name|listf
argument_list|)
expr_stmt|;
name|vfpart
operator|=
literal|0
expr_stmt|;
operator|(
name|void
operator|)
name|fflush
argument_list|(
name|listf
argument_list|)
expr_stmt|;
block|}
name|arfd
operator|=
operator|-
literal|1
expr_stmt|;
if|if
condition|(
operator|!
name|io_ok
operator|&&
operator|!
name|did_io
condition|)
block|{
name|flcnt
operator|=
literal|0
expr_stmt|;
return|return;
block|}
name|did_io
operator|=
name|io_ok
operator|=
literal|0
expr_stmt|;
comment|/* 	 * The volume number is only increased when the last device has data 	 * and we have already determined the archive format. 	 */
if|if
condition|(
name|frmt
operator|!=
name|NULL
condition|)
operator|++
name|arvol
expr_stmt|;
if|if
condition|(
operator|!
name|vflag
condition|)
block|{
name|flcnt
operator|=
literal|0
expr_stmt|;
return|return;
block|}
comment|/* 	 * Print out a summary of I/O for this archive volume. 	 */
if|if
condition|(
name|vfpart
condition|)
block|{
operator|(
name|void
operator|)
name|putc
argument_list|(
literal|'\n'
argument_list|,
name|listf
argument_list|)
expr_stmt|;
name|vfpart
operator|=
literal|0
expr_stmt|;
block|}
comment|/* 	 * If we have not determined the format yet, we just say how many bytes 	 * we have skipped over looking for a header to id. there is no way we 	 * could have written anything yet. 	 */
if|if
condition|(
name|frmt
operator|==
name|NULL
condition|)
block|{
ifdef|#
directive|ifdef
name|NET2_STAT
operator|(
name|void
operator|)
name|fprintf
argument_list|(
argument|listf
argument_list|,
literal|"%s: unknown format, %lu bytes skipped.\n"
argument_list|,
else|#
directive|else
argument|(void)fprintf(listf,
literal|"%s: unknown format, %qu bytes skipped.\n"
argument|,
endif|#
directive|endif
argument|argv0, rdcnt); 		(void)fflush(listf); 		flcnt =
literal|0
argument|; 		return; 	}  	if (strcmp(NM_CPIO, argv0) ==
literal|0
argument|) 		(void)fprintf(listf,
literal|"%qu blocks\n"
argument|, (rdcnt ? rdcnt : wrcnt) /
literal|5120
argument|); 	else if (strcmp(NM_TAR, argv0) !=
literal|0
argument|) 		(void)fprintf(listf,
ifdef|#
directive|ifdef
name|NET2_STAT
literal|"%s: %s vol %d, %lu files, %lu bytes read, %lu bytes written.\n"
argument|,
else|#
directive|else
literal|"%s: %s vol %d, %lu files, %qu bytes read, %qu bytes written.\n"
argument|,
endif|#
directive|endif
argument|argv0, frmt->name, arvol-
literal|1
argument|, flcnt, rdcnt, wrcnt); 	(void)fflush(listf); 	flcnt =
literal|0
argument|; }
comment|/*  * ar_drain()  *	drain any archive format independent padding from an archive read  *	from a socket or a pipe. This is to prevent the process on the  *	other side of the pipe from getting a SIGPIPE (pax will stop  *	reading an archive once a format dependent trailer is detected).  */
argument|void ar_drain(void) { 	int res; 	char drbuf[MAXBLK];
comment|/* 	 * we only drain from a pipe/socket. Other devices can be closed 	 * without reading up to end of file. We sure hope that pipe is closed 	 * on the other side so we will get an EOF. 	 */
argument|if ((artyp != ISPIPE) || (lstrval<=
literal|0
argument|)) 		return;
comment|/* 	 * keep reading until pipe is drained 	 */
argument|while ((res = read(arfd, drbuf, sizeof(drbuf)))>
literal|0
argument|) 		; 	lstrval = res; }
comment|/*  * ar_set_wr()  *	Set up device right before switching from read to write in an append.  *	device dependent code (if required) to do this should be added here.  *	For all archive devices we are already positioned at the place we want  *	to start writing when this routine is called.  * Return:  *	0 if all ready to write, -1 otherwise  */
argument|int ar_set_wr(void) { 	off_t cpos;
comment|/* 	 * we must make sure the trailer is rewritten on append, ar_next() 	 * will stop us if the archive containing the trailer was not written 	 */
argument|wr_trail =
literal|0
argument|;
comment|/* 	 * Add any device dependent code as required here 	 */
argument|if (artyp != ISREG) 		return(
literal|0
argument|);
comment|/* 	 * Ok we have an archive in a regular file. If we were rewriting a 	 * file, we must get rid of all the stuff after the current offset 	 * (it was not written by pax). 	 */
argument|if (((cpos = lseek(arfd, (off_t)
literal|0L
argument|, SEEK_CUR))<
literal|0
argument|) || 	    (ftruncate(arfd, cpos)<
literal|0
argument|)) { 		syswarn(
literal|1
argument|, errno,
literal|"Unable to truncate archive file"
argument|); 		return(-
literal|1
argument|); 	} 	return(
literal|0
argument|); }
comment|/*  * ar_app_ok()  *	check if the last volume in the archive allows appends. We cannot check  *	this until we are ready to write since there is no spec that says all  *	volumes in a single archive have to be of the same type...  * Return:  *	0 if we can append, -1 otherwise.  */
argument|int ar_app_ok(void) { 	if (artyp == ISPIPE) { 		paxwarn(
literal|1
argument|,
literal|"Cannot append to an archive obtained from a pipe."
argument|); 		return(-
literal|1
argument|); 	}  	if (!invld_rec) 		return(
literal|0
argument|); 	paxwarn(
literal|1
argument|,
literal|"Cannot append, device record size %d does not support %s spec"
argument|, 		rdblksz, argv0); 	return(-
literal|1
argument|); }
comment|/*  * ar_read()  *	read up to a specified number of bytes from the archive into the  *	supplied buffer. When dealing with tapes we may not always be able to  *	read what we want.  * Return:  *	Number of bytes in buffer. 0 for end of file, -1 for a read error.  */
argument|int ar_read(char *buf, int cnt) { 	int res =
literal|0
argument|;
comment|/* 	 * if last i/o was in error, no more reads until reset or new volume 	 */
argument|if (lstrval<=
literal|0
argument|) 		return(lstrval);
comment|/* 	 * how we read must be based on device type 	 */
argument|switch (artyp) { 	case ISTAPE: 		if ((res = read(arfd, buf, cnt))>
literal|0
argument|) {
comment|/* 			 * CAUTION: tape systems may not always return the same 			 * sized records so we leave blksz == MAXBLK. The 			 * physical record size that a tape drive supports is 			 * very hard to determine in a uniform and portable 			 * manner. 			 */
argument|io_ok =
literal|1
argument|; 			if (res != rdblksz) {
comment|/* 				 * Record size changed. If this is happens on 				 * any record after the first, we probably have 				 * a tape drive which has a fixed record size 				 * we are getting multiple records in a single 				 * read). Watch out for record blocking that 				 * violates pax spec (must be a multiple of 				 * BLKMULT). 				 */
argument|rdblksz = res; 				if (rdblksz % BLKMULT) 					invld_rec =
literal|1
argument|; 			} 			return(res); 		} 		break; 	case ISREG: 	case ISBLK: 	case ISCHR: 	case ISPIPE: 	default:
comment|/* 		 * Files are so easy to deal with. These other things cannot 		 * be trusted at all. So when we are dealing with character 		 * devices and pipes we just take what they have ready for us 		 * and return. Trying to do anything else with them runs the 		 * risk of failure. 		 */
argument|if ((res = read(arfd, buf, cnt))>
literal|0
argument|) { 			io_ok =
literal|1
argument|; 			return(res); 		} 		break; 	}
comment|/* 	 * We are in trouble at this point, something is broken... 	 */
argument|lstrval = res; 	if (res<
literal|0
argument|) 		syswarn(
literal|1
argument|, errno,
literal|"Failed read on archive volume %d"
argument|, arvol); 	else 		paxwarn(
literal|0
argument|,
literal|"End of archive volume %d reached"
argument|, arvol); 	return(res); }
comment|/*  * ar_write()  *	Write a specified number of bytes in supplied buffer to the archive  *	device so it appears as a single "block". Deals with errors and tries  *	to recover when faced with short writes.  * Return:  *	Number of bytes written. 0 indicates end of volume reached and with no  *	flaws (as best that can be detected). A -1 indicates an unrecoverable  *	error in the archive occured.  */
argument|int ar_write(char *buf, int bsz) { 	int res; 	off_t cpos;
comment|/* 	 * do not allow pax to create a "bad" archive. Once a write fails on 	 * an archive volume prevent further writes to it. 	 */
argument|if (lstrval<=
literal|0
argument|) 		return(lstrval);  	if ((res = write(arfd, buf, bsz)) == bsz) { 		wr_trail =
literal|1
argument|; 		io_ok =
literal|1
argument|; 		return(bsz); 	}
comment|/* 	 * write broke, see what we can do with it. We try to send any partial 	 * writes that may violate pax spec to the next archive volume. 	 */
argument|if (res<
literal|0
argument|) 		lstrval = res; 	else 		lstrval =
literal|0
argument|;  	switch (artyp) { 	case ISREG: 		if ((res>
literal|0
argument|)&& (res % BLKMULT)) {
comment|/* 		 	 * try to fix up partial writes which are not BLKMULT 			 * in size by forcing the runt record to next archive 			 * volume 		 	 */
argument|if ((cpos = lseek(arfd, (off_t)
literal|0L
argument|, SEEK_CUR))<
literal|0
argument|) 				break; 			cpos -= (off_t)res; 			if (ftruncate(arfd, cpos)<
literal|0
argument|) 				break; 			res = lstrval =
literal|0
argument|; 			break; 		} 		if (res>=
literal|0
argument|) 			break;
comment|/* 		 * if file is out of space, handle it like a return of 0 		 */
argument|if ((errno == ENOSPC) || (errno == EFBIG) || (errno == EDQUOT)) 			res = lstrval =
literal|0
argument|; 		break; 	case ISTAPE: 	case ISCHR: 	case ISBLK: 		if (res>=
literal|0
argument|) 			break; 		if (errno == EACCES) { 			paxwarn(
literal|0
argument|,
literal|"Write failed, archive is write protected."
argument|); 			res = lstrval =
literal|0
argument|; 			return(
literal|0
argument|); 		}
comment|/* 		 * see if we reached the end of media, if so force a change to 		 * the next volume 		 */
argument|if ((errno == ENOSPC) || (errno == EIO) || (errno == ENXIO)) 			res = lstrval =
literal|0
argument|; 		break; 	case ISPIPE: 	default:
comment|/* 		 * we cannot fix errors to these devices 		 */
argument|break; 	}
comment|/* 	 * Better tell the user the bad news... 	 * if this is a block aligned archive format, we may have a bad archive 	 * if the format wants the header to start at a BLKMULT boundary. While 	 * we can deal with the mis-aligned data, it violates spec and other 	 * archive readers will likely fail. if the format is not block 	 * aligned, the user may be lucky (and the archive is ok). 	 */
argument|if (res>=
literal|0
argument|) { 		if (res>
literal|0
argument|) 			wr_trail =
literal|1
argument|; 		io_ok =
literal|1
argument|; 	}
comment|/* 	 * If we were trying to rewrite the trailer and it didn't work, we 	 * must quit right away. 	 */
argument|if (!wr_trail&& (res<=
literal|0
argument|)) { 		paxwarn(
literal|1
argument|,
literal|"Unable to append, trailer re-write failed. Quitting."
argument|); 		return(res); 	}  	if (res ==
literal|0
argument|) 		paxwarn(
literal|0
argument|,
literal|"End of archive volume %d reached"
argument|, arvol); 	else if (res<
literal|0
argument|) 		syswarn(
literal|1
argument|, errno,
literal|"Failed write to archive volume: %d"
argument|, arvol); 	else if (!frmt->blkalgn || ((res % frmt->blkalgn) ==
literal|0
argument|)) 		paxwarn(
literal|0
argument|,
literal|"WARNING: partial archive write. Archive MAY BE FLAWED"
argument|); 	else 		paxwarn(
literal|1
argument|,
literal|"WARNING: partial archive write. Archive IS FLAWED"
argument|); 	return(res); }
comment|/*  * ar_rdsync()  *	Try to move past a bad spot on a flawed archive as needed to continue  *	I/O. Clears error flags to allow I/O to continue.  * Return:  *	0 when ok to try i/o again, -1 otherwise.  */
argument|int ar_rdsync(void) { 	long fsbz; 	off_t cpos; 	off_t mpos; 	struct mtop mb;
comment|/* 	 * Fail resync attempts at user request (done) or this is going to be 	 * an update/append to a existing archive. if last i/o hit media end, 	 * we need to go to the next volume not try a resync 	 */
argument|if ((done>
literal|0
argument|) || (lstrval ==
literal|0
argument|)) 		return(-
literal|1
argument|);  	if ((act == APPND) || (act == ARCHIVE)) { 		paxwarn(
literal|1
argument|,
literal|"Cannot allow updates to an archive with flaws."
argument|); 		return(-
literal|1
argument|); 	} 	if (io_ok) 		did_io =
literal|1
argument|;  	switch(artyp) { 	case ISTAPE:
comment|/* 		 * if the last i/o was a successful data transfer, we assume 		 * the fault is just a bad record on the tape that we are now 		 * past. If we did not get any data since the last resync try 		 * to move the tape forward one PHYSICAL record past any 		 * damaged tape section. Some tape drives are stubborn and need 		 * to be pushed. 		 */
argument|if (io_ok) { 			io_ok =
literal|0
argument|; 			lstrval =
literal|1
argument|; 			break; 		} 		mb.mt_op = MTFSR; 		mb.mt_count =
literal|1
argument|; 		if (ioctl(arfd, MTIOCTOP,&mb)<
literal|0
argument|) 			break; 		lstrval =
literal|1
argument|; 		break; 	case ISREG: 	case ISCHR: 	case ISBLK:
comment|/* 		 * try to step over the bad part of the device. 		 */
argument|io_ok =
literal|0
argument|; 		if (((fsbz = arsb.st_blksize)<=
literal|0
argument|) || (artyp != ISREG)) 			fsbz = BLKMULT; 		if ((cpos = lseek(arfd, (off_t)
literal|0L
argument|, SEEK_CUR))<
literal|0
argument|) 			break; 		mpos = fsbz - (cpos % (off_t)fsbz); 		if (lseek(arfd, mpos, SEEK_CUR)<
literal|0
argument|) 			break; 		lstrval =
literal|1
argument|; 		break; 	case ISPIPE: 	default:
comment|/* 		 * cannot recover on these archive device types 		 */
argument|io_ok =
literal|0
argument|; 		break; 	} 	if (lstrval<=
literal|0
argument|) { 		paxwarn(
literal|1
argument|,
literal|"Unable to recover from an archive read failure."
argument|); 		return(-
literal|1
argument|); 	} 	paxwarn(
literal|0
argument|,
literal|"Attempting to recover from an archive read failure."
argument|); 	return(
literal|0
argument|); }
comment|/*  * ar_fow()  *	Move the I/O position within the archive foward the specified number of  *	bytes as supported by the device. If we cannot move the requested  *	number of bytes, return the actual number of bytes moved in skipped.  * Return:  *	0 if moved the requested distance, -1 on complete failure, 1 on  *	partial move (the amount moved is in skipped)  */
argument|int ar_fow(off_t sksz, off_t *skipped) { 	off_t cpos; 	off_t mpos;  	*skipped =
literal|0
argument|; 	if (sksz<=
literal|0
argument|) 		return(
literal|0
argument|);
comment|/* 	 * we cannot move foward at EOF or error 	 */
argument|if (lstrval<=
literal|0
argument|) 		return(lstrval);
comment|/* 	 * Safer to read forward on devices where it is hard to find the end of 	 * the media without reading to it. With tapes we cannot be sure of the 	 * number of physical blocks to skip (we do not know physical block 	 * size at this point), so we must only read foward on tapes! 	 */
argument|if (artyp != ISREG) 		return(
literal|0
argument|);
comment|/* 	 * figure out where we are in the archive 	 */
argument|if ((cpos = lseek(arfd, (off_t)
literal|0L
argument|, SEEK_CUR))>=
literal|0
argument|) {
comment|/* 	 	 * we can be asked to move farther than there are bytes in this 		 * volume, if so, just go to file end and let normal buf_fill() 		 * deal with the end of file (it will go to next volume by 		 * itself) 	 	 */
argument|if ((mpos = cpos + sksz)> arsb.st_size) { 			*skipped = arsb.st_size - cpos; 			mpos = arsb.st_size; 		} else 			*skipped = sksz; 		if (lseek(arfd, mpos, SEEK_SET)>=
literal|0
argument|) 			return(
literal|0
argument|); 	} 	syswarn(
literal|1
argument|, errno,
literal|"Forward positioning operation on archive failed"
argument|); 	lstrval = -
literal|1
argument|; 	return(-
literal|1
argument|); }
comment|/*  * ar_rev()  *	move the i/o position within the archive backwards the specified byte  *	count as supported by the device. With tapes drives we RESET rdblksz to  *	the PHYSICAL blocksize.  *	NOTE: We should only be called to move backwards so we can rewrite the  *	last records (the trailer) of an archive (APPEND).  * Return:  *	0 if moved the requested distance, -1 on complete failure  */
argument|int ar_rev(off_t sksz) { 	off_t cpos; 	struct mtop mb; 	int phyblk;
comment|/* 	 * make sure we do not have try to reverse on a flawed archive 	 */
argument|if (lstrval<
literal|0
argument|) 		return(lstrval);  	switch(artyp) { 	case ISPIPE: 		if (sksz<=
literal|0
argument|) 			break;
comment|/* 		 * cannot go backwards on these critters 		 */
argument|paxwarn(
literal|1
argument|,
literal|"Reverse positioning on pipes is not supported."
argument|); 		lstrval = -
literal|1
argument|; 		return(-
literal|1
argument|); 	case ISREG: 	case ISBLK: 	case ISCHR: 	default: 		if (sksz<=
literal|0
argument|) 			break;
comment|/* 		 * For things other than files, backwards movement has a very 		 * high probability of failure as we really do not know the 		 * true attributes of the device we are talking to (the device 		 * may not even have the ability to lseek() in any direction). 		 * First we figure out where we are in the archive. 		 */
argument|if ((cpos = lseek(arfd, (off_t)
literal|0L
argument|, SEEK_CUR))<
literal|0
argument|) { 			syswarn(
literal|1
argument|, errno,
literal|"Unable to obtain current archive byte offset"
argument|); 			lstrval = -
literal|1
argument|; 			return(-
literal|1
argument|); 		}
comment|/* 		 * we may try to go backwards past the start when the archive 		 * is only a single record. If this hapens and we are on a 		 * multi volume archive, we need to go to the end of the 		 * previous volume and continue our movement backwards from 		 * there. 		 */
argument|if ((cpos -= sksz)< (off_t)
literal|0L
argument|) { 			if (arvol>
literal|1
argument|) {
comment|/* 				 * this should never happen 				 */
argument|paxwarn(
literal|1
argument|,
literal|"Reverse position on previous volume."
argument|); 				lstrval = -
literal|1
argument|; 				return(-
literal|1
argument|); 			} 			cpos = (off_t)
literal|0L
argument|; 		} 		if (lseek(arfd, cpos, SEEK_SET)<
literal|0
argument|) { 			syswarn(
literal|1
argument|, errno,
literal|"Unable to seek archive backwards"
argument|); 			lstrval = -
literal|1
argument|; 			return(-
literal|1
argument|); 		} 		break; 	case ISTAPE:
comment|/* 	 	 * Calculate and move the proper number of PHYSICAL tape 		 * blocks. If the sksz is not an even multiple of the physical 		 * tape size, we cannot do the move (this should never happen). 		 * (We also cannot handler trailers spread over two vols). 		 * get_phys() also makes sure we are in front of the filemark. 	 	 */
argument|if ((phyblk = get_phys())<=
literal|0
argument|) { 			lstrval = -
literal|1
argument|; 			return(-
literal|1
argument|); 		}
comment|/* 		 * make sure future tape reads only go by physical tape block 		 * size (set rdblksz to the real size). 		 */
argument|rdblksz = phyblk;
comment|/* 		 * if no movement is required, just return (we must be after 		 * get_phys() so the physical blocksize is properly set) 		 */
argument|if (sksz<=
literal|0
argument|) 			break;
comment|/* 		 * ok we have to move. Make sure the tape drive can do it. 		 */
argument|if (sksz % phyblk) { 			paxwarn(
literal|1
argument|,
literal|"Tape drive unable to backspace requested amount"
argument|); 			lstrval = -
literal|1
argument|; 			return(-
literal|1
argument|); 		}
comment|/* 		 * move backwards the requested number of bytes 		 */
argument|mb.mt_op = MTBSR; 		mb.mt_count = sksz/phyblk; 		if (ioctl(arfd, MTIOCTOP,&mb)<
literal|0
argument|) { 			syswarn(
literal|1
argument|,errno,
literal|"Unable to backspace tape %d blocks."
argument|, 			    mb.mt_count); 			lstrval = -
literal|1
argument|; 			return(-
literal|1
argument|); 		} 		break; 	} 	lstrval =
literal|1
argument|; 	return(
literal|0
argument|); }
comment|/*  * get_phys()  *	Determine the physical block size on a tape drive. We need the physical  *	block size so we know how many bytes we skip over when we move with  *	mtio commands. We also make sure we are BEFORE THE TAPE FILEMARK when  *	return.  *	This is one really SLOW routine...  * Return:  *	physical block size if ok (ok> 0), -1 otherwise  */
argument|static int get_phys(void) { 	int padsz =
literal|0
argument|; 	int res; 	int phyblk; 	struct mtop mb; 	char scbuf[MAXBLK];
comment|/* 	 * move to the file mark, and then back up one record and read it. 	 * this should tell us the physical record size the tape is using. 	 */
argument|if (lstrval ==
literal|1
argument|) {
comment|/* 		 * we know we are at file mark when we get back a 0 from 		 * read() 		 */
argument|while ((res = read(arfd, scbuf, sizeof(scbuf)))>
literal|0
argument|) 			padsz += res; 		if (res<
literal|0
argument|) { 			syswarn(
literal|1
argument|, errno,
literal|"Unable to locate tape filemark."
argument|); 			return(-
literal|1
argument|); 		} 	}
comment|/* 	 * move backwards over the file mark so we are at the end of the 	 * last record. 	 */
argument|mb.mt_op = MTBSF; 	mb.mt_count =
literal|1
argument|; 	if (ioctl(arfd, MTIOCTOP,&mb)<
literal|0
argument|) { 		syswarn(
literal|1
argument|, errno,
literal|"Unable to backspace over tape filemark."
argument|); 		return(-
literal|1
argument|); 	}
comment|/* 	 * move backwards so we are in front of the last record and read it to 	 * get physical tape blocksize. 	 */
argument|mb.mt_op = MTBSR; 	mb.mt_count =
literal|1
argument|; 	if (ioctl(arfd, MTIOCTOP,&mb)<
literal|0
argument|) { 		syswarn(
literal|1
argument|, errno,
literal|"Unable to backspace over last tape block."
argument|); 		return(-
literal|1
argument|); 	} 	if ((phyblk = read(arfd, scbuf, sizeof(scbuf)))<=
literal|0
argument|) { 		syswarn(
literal|1
argument|, errno,
literal|"Cannot determine archive tape blocksize."
argument|); 		return(-
literal|1
argument|); 	}
comment|/* 	 * read foward to the file mark, then back up in front of the filemark 	 * (this is a bit paranoid, but should be safe to do). 	 */
argument|while ((res = read(arfd, scbuf, sizeof(scbuf)))>
literal|0
argument|) 		; 	if (res<
literal|0
argument|) { 		syswarn(
literal|1
argument|, errno,
literal|"Unable to locate tape filemark."
argument|); 		return(-
literal|1
argument|); 	} 	mb.mt_op = MTBSF; 	mb.mt_count =
literal|1
argument|; 	if (ioctl(arfd, MTIOCTOP,&mb)<
literal|0
argument|) { 		syswarn(
literal|1
argument|, errno,
literal|"Unable to backspace over tape filemark."
argument|); 		return(-
literal|1
argument|); 	}
comment|/* 	 * set lstrval so we know that the filemark has not been seen 	 */
argument|lstrval =
literal|1
argument|;
comment|/* 	 * return if there was no padding 	 */
argument|if (padsz ==
literal|0
argument|) 		return(phyblk);
comment|/* 	 * make sure we can move backwards over the padding. (this should 	 * never fail). 	 */
argument|if (padsz % phyblk) { 		paxwarn(
literal|1
argument|,
literal|"Tape drive unable to backspace requested amount"
argument|); 		return(-
literal|1
argument|); 	}
comment|/* 	 * move backwards over the padding so the head is where it was when 	 * we were first called (if required). 	 */
argument|mb.mt_op = MTBSR; 	mb.mt_count = padsz/phyblk; 	if (ioctl(arfd, MTIOCTOP,&mb)<
literal|0
argument|) { 		syswarn(
literal|1
argument|,errno,
literal|"Unable to backspace tape over %d pad blocks"
argument|, 		    mb.mt_count); 		return(-
literal|1
argument|); 	} 	return(phyblk); }
comment|/*  * ar_next()  *	prompts the user for the next volume in this archive. For some devices  *	we may allow the media to be changed. Otherwise a new archive is  *	prompted for. By pax spec, if there is no controlling tty or an eof is  *	read on tty input, we must quit pax.  * Return:  *	0 when ready to continue, -1 when all done  */
argument|int ar_next(void) { 	char buf[PAXPATHLEN+
literal|2
argument|]; 	static int freeit =
literal|0
argument|; 	sigset_t o_mask;
comment|/* 	 * WE MUST CLOSE THE DEVICE. A lot of devices must see last close, (so 	 * things like writing EOF etc will be done) (Watch out ar_close() can 	 * also be called via a signal handler, so we must prevent a race. 	 */
argument|if (sigprocmask(SIG_BLOCK,&s_mask,&o_mask)<
literal|0
argument|) 		syswarn(
literal|0
argument|, errno,
literal|"Unable to set signal mask"
argument|); 	ar_close(); 	if (sigprocmask(SIG_SETMASK,&o_mask, NULL)<
literal|0
argument|) 		syswarn(
literal|0
argument|, errno,
literal|"Unable to restore signal mask"
argument|);  	if (done || !wr_trail || strcmp(NM_TAR, argv0) ==
literal|0
argument|) 		return(-
literal|1
argument|);  	tty_prnt(
literal|"\nATTENTION! %s archive volume change required.\n"
argument|, argv0);
comment|/* 	 * if i/o is on stdin or stdout, we cannot reopen it (we do not know 	 * the name), the user will be forced to type it in. 	 */
argument|if (strcmp(arcname, STDO)&& strcmp(arcname, STDN)&& (artyp != ISREG)&& (artyp != ISPIPE)) { 		if (artyp == ISTAPE) { 			tty_prnt(
literal|"%s ready for archive tape volume: %d\n"
argument|, 				arcname, arvol); 			tty_prnt(
literal|"Load the NEXT TAPE on the tape drive"
argument|); 		} else { 			tty_prnt(
literal|"%s ready for archive volume: %d\n"
argument|, 				arcname, arvol); 			tty_prnt(
literal|"Load the NEXT STORAGE MEDIA (if required)"
argument|); 		}  		if ((act == ARCHIVE) || (act == APPND)) 			tty_prnt(
literal|" and make sure it is WRITE ENABLED.\n"
argument|); 		else 			tty_prnt(
literal|"\n"
argument|);  		for(;;) { 			tty_prnt(
literal|"Type \"y\" to continue, \".\" to quit %s,"
argument|, 				argv0); 			tty_prnt(
literal|" or \"s\" to switch to new device.\nIf you"
argument|); 			tty_prnt(
literal|" cannot change storage media, type \"s\"\n"
argument|); 			tty_prnt(
literal|"Is the device ready and online?> "
argument|);  			if ((tty_read(buf,sizeof(buf))<
literal|0
argument|) || !strcmp(buf,
literal|"."
argument|)){ 				done =
literal|1
argument|; 				lstrval = -
literal|1
argument|; 				tty_prnt(
literal|"Quitting %s!\n"
argument|, argv0); 				vfpart =
literal|0
argument|; 				return(-
literal|1
argument|); 			}  			if ((buf[
literal|0
argument|] ==
literal|'\0'
argument|) || (buf[
literal|1
argument|] !=
literal|'\0'
argument|)) { 				tty_prnt(
literal|"%s unknown command, try again\n"
argument|,buf); 				continue; 			}  			switch (buf[
literal|0
argument|]) { 			case
literal|'y'
argument|: 			case
literal|'Y'
argument|:
comment|/* 				 * we are to continue with the same device 				 */
argument|if (ar_open(arcname)>=
literal|0
argument|) 					return(
literal|0
argument|); 				tty_prnt(
literal|"Cannot re-open %s, try again\n"
argument|, 					arcname); 				continue; 			case
literal|'s'
argument|: 			case
literal|'S'
argument|:
comment|/* 				 * user wants to open a different device 				 */
argument|tty_prnt(
literal|"Switching to a different archive\n"
argument|); 				break; 			default: 				tty_prnt(
literal|"%s unknown command, try again\n"
argument|,buf); 				continue; 			} 			break; 		} 	} else 		tty_prnt(
literal|"Ready for archive volume: %d\n"
argument|, arvol);
comment|/* 	 * have to go to a different archive 	 */
argument|for (;;) { 		tty_prnt(
literal|"Input archive name or \".\" to quit %s.\n"
argument|, argv0); 		tty_prnt(
literal|"Archive name> "
argument|);  		if ((tty_read(buf, sizeof(buf))<
literal|0
argument|) || !strcmp(buf,
literal|"."
argument|)) { 			done =
literal|1
argument|; 			lstrval = -
literal|1
argument|; 			tty_prnt(
literal|"Quitting %s!\n"
argument|, argv0); 			vfpart =
literal|0
argument|; 			return(-
literal|1
argument|); 		} 		if (buf[
literal|0
argument|] ==
literal|'\0'
argument|) { 			tty_prnt(
literal|"Empty file name, try again\n"
argument|); 			continue; 		} 		if (!strcmp(buf,
literal|".."
argument|)) { 			tty_prnt(
literal|"Illegal file name: .. try again\n"
argument|); 			continue; 		} 		if (strlen(buf)> PAXPATHLEN) { 			tty_prnt(
literal|"File name too long, try again\n"
argument|); 			continue; 		}
comment|/* 		 * try to open new archive 		 */
argument|if (ar_open(buf)>=
literal|0
argument|) { 			if (freeit) { 				(void)free(arcname); 				freeit =
literal|0
argument|; 			} 			if ((arcname = strdup(buf)) == NULL) { 				done =
literal|1
argument|; 				lstrval = -
literal|1
argument|; 				paxwarn(
literal|0
argument|,
literal|"Cannot save archive name."
argument|); 				return(-
literal|1
argument|); 			} 			freeit =
literal|1
argument|; 			break; 		} 		tty_prnt(
literal|"Cannot open %s, try again\n"
argument|, buf); 		continue; 	} 	return(
literal|0
argument|); }
comment|/*  * ar_start_gzip()  * starts the gzip compression/decompression process as a child, using magic  * to keep the fd the same in the calling function (parent).  */
argument|void ar_start_gzip(int fd, const char *gzip_program, int wr) { 	int fds[
literal|2
argument|]; 	char *gzip_flags;  	if (pipe(fds)<
literal|0
argument|) 		err(
literal|1
argument|,
literal|"could not pipe"
argument|); 	zpid = fork(); 	if (zpid<
literal|0
argument|) 		err(
literal|1
argument|,
literal|"could not fork"
argument|);
comment|/* parent */
argument|if (zpid) { 		if (wr) 			dup2(fds[
literal|1
argument|], fd); 		else 			dup2(fds[
literal|0
argument|], fd); 		close(fds[
literal|0
argument|]); 		close(fds[
literal|1
argument|]); 	} else { 		if (wr) { 			dup2(fds[
literal|0
argument|], STDIN_FILENO); 			dup2(fd, STDOUT_FILENO); 			gzip_flags =
literal|"-c"
argument|; 		} else { 			dup2(fds[
literal|1
argument|], STDOUT_FILENO); 			dup2(fd, STDIN_FILENO); 			gzip_flags =
literal|"-dc"
argument|; 		} 		close(fds[
literal|0
argument|]); 		close(fds[
literal|1
argument|]); 		if (execlp(gzip_program, gzip_program, gzip_flags, 		    (char *)NULL)<
literal|0
argument|) 			err(
literal|1
argument|,
literal|"could not exec"
argument|);
comment|/* NOTREACHED */
argument|} }
end_function

end_unit

