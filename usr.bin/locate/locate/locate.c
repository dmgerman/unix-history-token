begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1995 Wolfram Schneider<wosch@FreeBSD.org>. Berlin.  * Copyright (c) 1989, 1993  *      The Regents of the University of California.  All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * James A. Woods.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *      This product includes software developed by the University of  *      California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|lint
end_ifndef

begin_decl_stmt
specifier|static
specifier|const
name|char
name|copyright
index|[]
init|=
literal|"@(#) Copyright (c) 1995-1996 Wolfram Schneider, Berlin.\n\ @(#) Copyright (c) 1989, 1993\n\         The Regents of the University of California.  All rights reserved.\n"
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

begin_if
if|#
directive|if
literal|0
end_if

begin_endif
unit|static char sccsid[] = "@(#)locate.c    8.1 (Berkeley) 6/6/93";
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

begin_comment
comment|/*  * Ref: Usenix ;login:, Vol 8, No 1, February/March, 1983, p. 8.  *  * Locate scans a file list for the full pathname of a file given only part  * of the name.  The list has been processed with with "front-compression"  * and bigram coding.  Front compression reduces space by a factor of 4-5,  * bigram coding by a further 20-25%.  *  * The codes are:  *  *      0-28    likeliest differential counts + offset to make nonnegative  *      30      switch code for out-of-range count to follow in next word  *      31      an 8 bit char followed  *      128-255 bigram codes (128 most common, as determined by 'updatedb')  *      32-127  single character (printable) ascii residue (ie, literal)  *  * A novel two-tiered string search technique is employed:  *  * First, a metacharacter-free subpattern and partial pathname is matched  * BACKWARDS to avoid full expansion of the pathname list.  The time savings  * is 40-50% over forward matching, which cannot efficiently handle  * overlapped search patterns and compressed path residue.  *  * Then, the actual shell glob-style regular expression (if in this form) is  * matched against the candidate pathnames using the slower routines provided  * in the standard 'find'.  */
end_comment

begin_include
include|#
directive|include
file|<sys/param.h>
end_include

begin_include
include|#
directive|include
file|<ctype.h>
end_include

begin_include
include|#
directive|include
file|<err.h>
end_include

begin_include
include|#
directive|include
file|<fnmatch.h>
end_include

begin_include
include|#
directive|include
file|<locale.h>
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
file|<string.h>
end_include

begin_include
include|#
directive|include
file|<unistd.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|MMAP
end_ifdef

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
file|<sys/mman.h>
end_include

begin_include
include|#
directive|include
file|<fcntl.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|sun
end_ifdef

begin_include
include|#
directive|include
file|<netinet/in.h>
end_include

begin_comment
comment|/* SunOS byteorder(3) htohl(3) */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__P
end_ifndef

begin_define
define|#
directive|define
name|__P
parameter_list|(
name|x
parameter_list|)
value|x
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|"locate.h"
end_include

begin_include
include|#
directive|include
file|"pathnames.h"
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|DEBUG
end_ifdef

begin_include
include|#
directive|include
file|<sys/time.h>
end_include

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|<sys/resource.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
name|char
modifier|*
name|path_fcodes
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* locate database */
end_comment

begin_decl_stmt
name|int
name|f_mmap
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* use mmap */
end_comment

begin_decl_stmt
name|int
name|f_icase
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* ignore case */
end_comment

begin_decl_stmt
name|int
name|f_stdin
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* read database from stdin */
end_comment

begin_decl_stmt
name|int
name|f_statistic
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* print statistic */
end_comment

begin_decl_stmt
name|int
name|f_silent
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* suppress output, show only count of matches */
end_comment

begin_decl_stmt
name|int
name|f_limit
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* limit number of output lines, 0 == infinite */
end_comment

begin_decl_stmt
name|u_int
name|counter
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* counter for matches [-c] */
end_comment

begin_decl_stmt
name|void
name|usage
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|statistic
name|__P
argument_list|(
operator|(
name|FILE
operator|*
operator|,
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|fastfind
name|__P
argument_list|(
operator|(
name|FILE
operator|*
operator|,
name|char
operator|*
operator|,
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|fastfind_icase
name|__P
argument_list|(
operator|(
name|FILE
operator|*
operator|,
name|char
operator|*
operator|,
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|fastfind_mmap
name|__P
argument_list|(
operator|(
name|char
operator|*
operator|,
name|caddr_t
operator|,
name|int
operator|,
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|fastfind_mmap_icase
name|__P
argument_list|(
operator|(
name|char
operator|*
operator|,
name|caddr_t
operator|,
name|int
operator|,
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|search_mmap
name|__P
argument_list|(
operator|(
name|char
operator|*
operator|,
name|char
operator|*
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|search_fopen
name|__P
argument_list|(
operator|(
name|char
operator|*
operator|,
name|char
operator|*
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|unsigned
name|long
name|cputime
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
modifier|*
name|colon
name|__P
argument_list|(
operator|(
name|char
operator|*
operator|*
operator|,
name|char
operator|*
operator|,
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|print_matches
name|__P
argument_list|(
operator|(
name|u_int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|getwm
name|__P
argument_list|(
operator|(
name|caddr_t
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|getwf
name|__P
argument_list|(
operator|(
name|FILE
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|u_char
modifier|*
name|tolower_word
name|__P
argument_list|(
operator|(
name|u_char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|check_bigram_char
name|__P
argument_list|(
operator|(
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|patprep
name|__P
argument_list|(
operator|(
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|optarg
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|optind
decl_stmt|;
end_decl_stmt

begin_function
name|int
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
specifier|register
name|int
name|ch
decl_stmt|;
name|char
modifier|*
modifier|*
name|dbv
init|=
name|NULL
decl_stmt|;
ifdef|#
directive|ifdef
name|MMAP
name|f_mmap
operator|=
literal|1
expr_stmt|;
comment|/* mmap is default */
endif|#
directive|endif
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
while|while
condition|(
operator|(
name|ch
operator|=
name|getopt
argument_list|(
name|argc
argument_list|,
name|argv
argument_list|,
literal|"Scd:il:ms"
argument_list|)
operator|)
operator|!=
operator|-
literal|1
condition|)
switch|switch
condition|(
name|ch
condition|)
block|{
case|case
literal|'S'
case|:
comment|/* statistic lines */
name|f_statistic
operator|=
literal|1
expr_stmt|;
break|break;
case|case
literal|'l'
case|:
comment|/* limit number of output lines, 0 == infinite */
name|f_limit
operator|=
name|atoi
argument_list|(
name|optarg
argument_list|)
expr_stmt|;
break|break;
case|case
literal|'d'
case|:
comment|/* database */
name|dbv
operator|=
name|colon
argument_list|(
name|dbv
argument_list|,
name|optarg
argument_list|,
name|_PATH_FCODES
argument_list|)
expr_stmt|;
break|break;
case|case
literal|'i'
case|:
comment|/* ignore case */
name|f_icase
operator|=
literal|1
expr_stmt|;
break|break;
case|case
literal|'m'
case|:
comment|/* mmap */
ifdef|#
directive|ifdef
name|MMAP
name|f_mmap
operator|=
literal|1
expr_stmt|;
else|#
directive|else
name|warnx
argument_list|(
literal|"mmap(2) not implemented"
argument_list|)
expr_stmt|;
endif|#
directive|endif
break|break;
case|case
literal|'s'
case|:
comment|/* stdio lib */
name|f_mmap
operator|=
literal|0
expr_stmt|;
break|break;
case|case
literal|'c'
case|:
comment|/* suppress output, show only count of matches */
name|f_silent
operator|=
literal|1
expr_stmt|;
break|break;
default|default:
name|usage
argument_list|()
expr_stmt|;
block|}
name|argv
operator|+=
name|optind
expr_stmt|;
name|argc
operator|-=
name|optind
expr_stmt|;
comment|/* to few arguments */
if|if
condition|(
name|argc
operator|<
literal|1
operator|&&
operator|!
operator|(
name|f_statistic
operator|)
condition|)
name|usage
argument_list|()
expr_stmt|;
comment|/* no (valid) database as argument */
if|if
condition|(
name|dbv
operator|==
name|NULL
operator|||
operator|*
name|dbv
operator|==
name|NULL
condition|)
block|{
comment|/* try to read database from enviroment */
if|if
condition|(
operator|(
name|path_fcodes
operator|=
name|getenv
argument_list|(
literal|"LOCATE_PATH"
argument_list|)
operator|)
operator|==
name|NULL
operator|||
operator|*
name|path_fcodes
operator|==
literal|'\0'
condition|)
comment|/* use default database */
name|dbv
operator|=
name|colon
argument_list|(
name|dbv
argument_list|,
name|_PATH_FCODES
argument_list|,
name|_PATH_FCODES
argument_list|)
expr_stmt|;
else|else
comment|/* $LOCATE_PATH */
name|dbv
operator|=
name|colon
argument_list|(
name|dbv
argument_list|,
name|path_fcodes
argument_list|,
name|_PATH_FCODES
argument_list|)
expr_stmt|;
block|}
if|if
condition|(
name|f_icase
operator|&&
name|UCHAR_MAX
operator|<
literal|4096
condition|)
comment|/* init tolower lookup table */
for|for
control|(
name|ch
operator|=
literal|0
init|;
name|ch
operator|<
name|UCHAR_MAX
operator|+
literal|1
condition|;
name|ch
operator|++
control|)
name|myctype
index|[
name|ch
index|]
operator|=
name|tolower
argument_list|(
name|ch
argument_list|)
expr_stmt|;
comment|/* foreach database ... */
while|while
condition|(
operator|(
name|path_fcodes
operator|=
operator|*
name|dbv
operator|)
operator|!=
name|NULL
condition|)
block|{
name|dbv
operator|++
expr_stmt|;
if|if
condition|(
operator|!
name|strcmp
argument_list|(
name|path_fcodes
argument_list|,
literal|"-"
argument_list|)
condition|)
name|f_stdin
operator|=
literal|1
expr_stmt|;
else|else
name|f_stdin
operator|=
literal|0
expr_stmt|;
ifndef|#
directive|ifndef
name|MMAP
name|f_mmap
operator|=
literal|0
expr_stmt|;
comment|/* be paranoid */
endif|#
directive|endif
if|if
condition|(
operator|!
name|f_mmap
operator|||
name|f_stdin
operator|||
name|f_statistic
condition|)
name|search_fopen
argument_list|(
name|path_fcodes
argument_list|,
name|argv
argument_list|)
expr_stmt|;
else|else
name|search_mmap
argument_list|(
name|path_fcodes
argument_list|,
name|argv
argument_list|)
expr_stmt|;
block|}
if|if
condition|(
name|f_silent
condition|)
name|print_matches
argument_list|(
name|counter
argument_list|)
expr_stmt|;
name|exit
argument_list|(
literal|0
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
name|void
name|search_fopen
parameter_list|(
name|db
parameter_list|,
name|s
parameter_list|)
name|char
modifier|*
name|db
decl_stmt|;
comment|/* database */
name|char
modifier|*
modifier|*
name|s
decl_stmt|;
comment|/* search strings */
block|{
name|FILE
modifier|*
name|fp
decl_stmt|;
ifdef|#
directive|ifdef
name|DEBUG
name|long
name|t0
decl_stmt|;
endif|#
directive|endif
comment|/* can only read stdin once */
if|if
condition|(
name|f_stdin
condition|)
block|{
name|fp
operator|=
name|stdin
expr_stmt|;
if|if
condition|(
operator|*
operator|(
name|s
operator|+
literal|1
operator|)
operator|!=
name|NULL
condition|)
block|{
name|warnx
argument_list|(
literal|"read database from stdin, use only `%s' as pattern"
argument_list|,
operator|*
name|s
argument_list|)
expr_stmt|;
operator|*
operator|(
name|s
operator|+
literal|1
operator|)
operator|=
name|NULL
expr_stmt|;
block|}
block|}
elseif|else
if|if
condition|(
operator|(
name|fp
operator|=
name|fopen
argument_list|(
name|path_fcodes
argument_list|,
literal|"r"
argument_list|)
operator|)
operator|==
name|NULL
condition|)
name|err
argument_list|(
literal|1
argument_list|,
literal|"`%s'"
argument_list|,
name|path_fcodes
argument_list|)
expr_stmt|;
comment|/* count only chars or lines */
if|if
condition|(
name|f_statistic
condition|)
block|{
name|statistic
argument_list|(
name|fp
argument_list|,
name|path_fcodes
argument_list|)
expr_stmt|;
operator|(
name|void
operator|)
name|fclose
argument_list|(
name|fp
argument_list|)
expr_stmt|;
return|return;
block|}
comment|/* foreach search string ... */
while|while
condition|(
operator|*
name|s
operator|!=
name|NULL
condition|)
block|{
ifdef|#
directive|ifdef
name|DEBUG
name|t0
operator|=
name|cputime
argument_list|()
expr_stmt|;
endif|#
directive|endif
if|if
condition|(
operator|!
name|f_stdin
operator|&&
name|fseek
argument_list|(
name|fp
argument_list|,
operator|(
name|long
operator|)
literal|0
argument_list|,
name|SEEK_SET
argument_list|)
operator|==
operator|-
literal|1
condition|)
name|err
argument_list|(
literal|1
argument_list|,
literal|"fseek to begin of ``%s''\n"
argument_list|,
name|path_fcodes
argument_list|)
expr_stmt|;
if|if
condition|(
name|f_icase
condition|)
name|fastfind_icase
argument_list|(
name|fp
argument_list|,
operator|*
name|s
argument_list|,
name|path_fcodes
argument_list|)
expr_stmt|;
else|else
name|fastfind
argument_list|(
name|fp
argument_list|,
operator|*
name|s
argument_list|,
name|path_fcodes
argument_list|)
expr_stmt|;
ifdef|#
directive|ifdef
name|DEBUG
name|warnx
argument_list|(
literal|"fastfind %ld ms"
argument_list|,
name|cputime
argument_list|()
operator|-
name|t0
argument_list|)
expr_stmt|;
endif|#
directive|endif
name|s
operator|++
expr_stmt|;
block|}
operator|(
name|void
operator|)
name|fclose
argument_list|(
name|fp
argument_list|)
expr_stmt|;
block|}
end_function

begin_ifdef
ifdef|#
directive|ifdef
name|MMAP
end_ifdef

begin_function
name|void
name|search_mmap
parameter_list|(
name|db
parameter_list|,
name|s
parameter_list|)
name|char
modifier|*
name|db
decl_stmt|;
comment|/* database */
name|char
modifier|*
modifier|*
name|s
decl_stmt|;
comment|/* search strings */
block|{
name|struct
name|stat
name|sb
decl_stmt|;
name|int
name|fd
decl_stmt|;
name|caddr_t
name|p
decl_stmt|;
name|off_t
name|len
decl_stmt|;
ifdef|#
directive|ifdef
name|DEBUG
name|long
name|t0
decl_stmt|;
endif|#
directive|endif
if|if
condition|(
operator|(
name|fd
operator|=
name|open
argument_list|(
name|path_fcodes
argument_list|,
name|O_RDONLY
argument_list|)
operator|)
operator|==
operator|-
literal|1
operator|||
name|fstat
argument_list|(
name|fd
argument_list|,
operator|&
name|sb
argument_list|)
operator|==
operator|-
literal|1
condition|)
name|err
argument_list|(
literal|1
argument_list|,
literal|"`%s'"
argument_list|,
name|path_fcodes
argument_list|)
expr_stmt|;
name|len
operator|=
name|sb
operator|.
name|st_size
expr_stmt|;
if|if
condition|(
operator|(
name|p
operator|=
name|mmap
argument_list|(
operator|(
name|caddr_t
operator|)
literal|0
argument_list|,
operator|(
name|size_t
operator|)
name|len
argument_list|,
name|PROT_READ
argument_list|,
name|MAP_SHARED
argument_list|,
name|fd
argument_list|,
operator|(
name|off_t
operator|)
literal|0
argument_list|)
operator|)
operator|==
name|MAP_FAILED
condition|)
name|err
argument_list|(
literal|1
argument_list|,
literal|"mmap ``%s''"
argument_list|,
name|path_fcodes
argument_list|)
expr_stmt|;
comment|/* foreach search string ... */
while|while
condition|(
operator|*
name|s
operator|!=
name|NULL
condition|)
block|{
ifdef|#
directive|ifdef
name|DEBUG
name|t0
operator|=
name|cputime
argument_list|()
expr_stmt|;
endif|#
directive|endif
if|if
condition|(
name|f_icase
condition|)
name|fastfind_mmap_icase
argument_list|(
operator|*
name|s
argument_list|,
name|p
argument_list|,
operator|(
name|int
operator|)
name|len
argument_list|,
name|path_fcodes
argument_list|)
expr_stmt|;
else|else
name|fastfind_mmap
argument_list|(
operator|*
name|s
argument_list|,
name|p
argument_list|,
operator|(
name|int
operator|)
name|len
argument_list|,
name|path_fcodes
argument_list|)
expr_stmt|;
ifdef|#
directive|ifdef
name|DEBUG
name|warnx
argument_list|(
literal|"fastfind %ld ms"
argument_list|,
name|cputime
argument_list|()
operator|-
name|t0
argument_list|)
expr_stmt|;
endif|#
directive|endif
name|s
operator|++
expr_stmt|;
block|}
if|if
condition|(
name|munmap
argument_list|(
name|p
argument_list|,
operator|(
name|size_t
operator|)
name|len
argument_list|)
operator|==
operator|-
literal|1
condition|)
name|warn
argument_list|(
literal|"munmap %s\n"
argument_list|,
name|path_fcodes
argument_list|)
expr_stmt|;
operator|(
name|void
operator|)
name|close
argument_list|(
name|fd
argument_list|)
expr_stmt|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* MMAP */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|DEBUG
end_ifdef

begin_function
name|unsigned
name|long
name|cputime
parameter_list|()
block|{
name|struct
name|rusage
name|rus
decl_stmt|;
name|getrusage
argument_list|(
literal|0
argument_list|,
operator|&
name|rus
argument_list|)
expr_stmt|;
return|return
operator|(
name|rus
operator|.
name|ru_utime
operator|.
name|tv_sec
operator|*
literal|1000
operator|+
name|rus
operator|.
name|ru_utime
operator|.
name|tv_usec
operator|/
literal|1000
operator|)
return|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* DEBUG */
end_comment

begin_function
name|void
name|usage
parameter_list|()
block|{
operator|(
name|void
operator|)
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"usage: locate [-Scims] [-l limit] [-d database] pattern ...\n\n"
argument_list|)
expr_stmt|;
operator|(
name|void
operator|)
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"default database: `%s' or $LOCATE_PATH\n"
argument_list|,
name|_PATH_FCODES
argument_list|)
expr_stmt|;
name|exit
argument_list|(
literal|1
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|/* load fastfind functions */
end_comment

begin_comment
comment|/* statistic */
end_comment

begin_comment
comment|/* fastfind_mmap, fastfind_mmap_icase */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|MMAP
end_ifdef

begin_undef
undef|#
directive|undef
name|FF_MMAP
end_undef

begin_undef
undef|#
directive|undef
name|FF_ICASE
end_undef

begin_define
define|#
directive|define
name|FF_MMAP
end_define

begin_include
include|#
directive|include
file|"fastfind.c"
end_include

begin_define
define|#
directive|define
name|FF_ICASE
end_define

begin_include
include|#
directive|include
file|"fastfind.c"
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* MMAP */
end_comment

begin_comment
comment|/* fopen */
end_comment

begin_comment
comment|/* fastfind, fastfind_icase */
end_comment

begin_undef
undef|#
directive|undef
name|FF_MMAP
end_undef

begin_undef
undef|#
directive|undef
name|FF_ICASE
end_undef

begin_include
include|#
directive|include
file|"fastfind.c"
end_include

begin_define
define|#
directive|define
name|FF_ICASE
end_define

begin_include
include|#
directive|include
file|"fastfind.c"
end_include

end_unit

