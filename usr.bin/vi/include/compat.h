begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1991, 1993  *	The Regents of the University of California.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)compat.h	8.10 (Berkeley) 1/11/94  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_COMPAT_H_
end_ifndef

begin_define
define|#
directive|define
name|_COMPAT_H_
end_define

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|<machine/limits.h>
end_include

begin_include
include|#
directive|include
file|<termios.h>
end_include

begin_include
include|#
directive|include
file|<errno.h>
end_include

begin_comment
comment|/*  * If your system doesn't typedef u_long, u_short, or u_char, change  * the 0 to a 1.  */
end_comment

begin_if
if|#
directive|if
literal|0
end_if

begin_comment
unit|typedef unsigned char	u_char;
comment|/* 4.[34]BSD names. */
end_comment

begin_endif
unit|typedef unsigned int	u_int; typedef unsigned long	u_long; typedef unsigned short	u_short;
endif|#
directive|endif
end_endif

begin_comment
comment|/* If your system doesn't typedef size_t, change the 0 to a 1. */
end_comment

begin_if
if|#
directive|if
literal|0
end_if

begin_comment
unit|typedef unsigned int	size_t;
comment|/* 4.[34]BSD names. */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * If your system doesn't have the POSIX type for a signal mask,  * change the 0 to a 1.  */
end_comment

begin_if
if|#
directive|if
literal|0
end_if

begin_comment
comment|/* POSIX 1003.1 signal mask type. */
end_comment

begin_endif
unit|typedef unsigned int	sigset_t;
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * If your system's vsprintf returns a char *, not an int,  * change the 0 to a 1.  */
end_comment

begin_if
if|#
directive|if
literal|0
end_if

begin_define
define|#
directive|define
name|VSPRINTF_CHARSTAR
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * If you don't have POSIX 1003.1 signals, the signal code surrounding the   * temporary file creation is intended to block all of the possible signals  * long enough to create the file and unlink it.  All of this stuff is  * intended to use old-style BSD calls to fake POSIX 1003.1 calls.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|NO_POSIX_SIGNALS
end_ifdef

begin_define
define|#
directive|define
name|sigemptyset
parameter_list|(
name|set
parameter_list|)
value|(*(set) = 0)
end_define

begin_define
define|#
directive|define
name|sigfillset
parameter_list|(
name|set
parameter_list|)
value|(*(set) = ~(sigset_t)0, 0)
end_define

begin_define
define|#
directive|define
name|sigaddset
parameter_list|(
name|set
parameter_list|,
name|signo
parameter_list|)
value|(*(set) |= sigmask(signo), 0)
end_define

begin_define
define|#
directive|define
name|sigdelset
parameter_list|(
name|set
parameter_list|,
name|signo
parameter_list|)
value|(*(set)&= ~sigmask(signo), 0)
end_define

begin_define
define|#
directive|define
name|sigismember
parameter_list|(
name|set
parameter_list|,
name|signo
parameter_list|)
value|((*(set)& sigmask(signo)) != 0)
end_define

begin_define
define|#
directive|define
name|SIG_BLOCK
value|1
end_define

begin_define
define|#
directive|define
name|SIG_UNBLOCK
value|2
end_define

begin_define
define|#
directive|define
name|SIG_SETMASK
value|3
end_define

begin_decl_stmt
specifier|static
name|int
name|__sigtemp
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* For the use of sigprocmask */
end_comment

begin_comment
comment|/* Repeated test of oset != NULL is to avoid "*0". */
end_comment

begin_define
define|#
directive|define
name|sigprocmask
parameter_list|(
name|how
parameter_list|,
name|set
parameter_list|,
name|oset
parameter_list|)
define|\
value|((__sigtemp =							\ 	(((how) == SIG_BLOCK) ?						\ 		sigblock(0) | *(set) :					\ 	(((how) == SIG_UNBLOCK) ?					\ 		sigblock(0)& ~(*(set)) :				\ 	((how) == SIG_SETMASK ?						\ 		*(set) : sigblock(0))))),				\ 	((oset) ? (*(oset ? oset : set) = sigsetmask(__sigtemp)) :	\ 		sigsetmask(__sigtemp)), 0)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * If realloc(3) of a NULL pointer on your system isn't the same as  * a malloc(3) call, change the 0 to a 1, and add realloc.o to the  * MISC line in your Makefile.  */
end_comment

begin_if
if|#
directive|if
literal|0
end_if

begin_define
define|#
directive|define
name|realloc
value|__fix_realloc
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * If your system doesn't have an include file with the appropriate  * byte order set, make sure you specify the correct one.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|BYTE_ORDER
end_ifndef

begin_define
define|#
directive|define
name|LITTLE_ENDIAN
value|1234
end_define

begin_comment
comment|/* LSB first: i386, vax */
end_comment

begin_define
define|#
directive|define
name|BIG_ENDIAN
value|4321
end_define

begin_comment
comment|/* MSB first: 68000, ibm, net */
end_comment

begin_define
define|#
directive|define
name|BYTE_ORDER
value|LITTLE_ENDIAN
end_define

begin_comment
comment|/* Set for your system. */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|SYSV
argument_list|)
operator|||
name|defined
argument_list|(
name|SYSTEM5
argument_list|)
end_if

begin_define
define|#
directive|define
name|index
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|strchr(a, b)
end_define

begin_define
define|#
directive|define
name|rindex
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|strrchr(a, b)
end_define

begin_define
define|#
directive|define
name|bzero
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|memset(a, 0, b)
end_define

begin_define
define|#
directive|define
name|bcmp
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|,
name|n
parameter_list|)
value|memcmp(a, b, n)
end_define

begin_define
define|#
directive|define
name|bcopy
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|,
name|n
parameter_list|)
value|memmove(b, a, n)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|BSD
argument_list|)
operator|||
name|defined
argument_list|(
name|BSD4_3
argument_list|)
end_if

begin_define
define|#
directive|define
name|strchr
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|index(a, b)
end_define

begin_define
define|#
directive|define
name|strrchr
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|rindex(a, b)
end_define

begin_define
define|#
directive|define
name|memcmp
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|,
name|n
parameter_list|)
value|bcmp(a, b, n)
end_define

begin_define
define|#
directive|define
name|memmove
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|,
name|n
parameter_list|)
value|bcopy(b, a, n)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * 32-bit machine.  The db routines are theoretically independent of  * the size of u_shorts and u_longs, but I don't know that anyone has  * ever actually tried it.  At a minimum, change the following #define's  * if you are trying to compile on a different type of system.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|USHRT_MAX
end_ifndef

begin_define
define|#
directive|define
name|USHRT_MAX
value|0xFFFF
end_define

begin_define
define|#
directive|define
name|ULONG_MAX
value|0xFFFFFFFF
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|O_ACCMODE
end_ifndef

begin_comment
comment|/* POSIX 1003.1 access mode mask. */
end_comment

begin_define
define|#
directive|define
name|O_ACCMODE
value|(O_RDONLY|O_WRONLY|O_RDWR)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|_POSIX2_RE_DUP_MAX
end_ifndef

begin_comment
comment|/* POSIX 1003.2 RE limit. */
end_comment

begin_define
define|#
directive|define
name|_POSIX2_RE_DUP_MAX
value|255
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * If you can't provide lock values in the open(2) call.  Note, this  * allows races to happen.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|O_EXLOCK
end_ifndef

begin_comment
comment|/* 4.4BSD extension. */
end_comment

begin_define
define|#
directive|define
name|O_EXLOCK
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|O_SHLOCK
end_ifndef

begin_comment
comment|/* 4.4BSD extension. */
end_comment

begin_define
define|#
directive|define
name|O_SHLOCK
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|EFTYPE
end_ifndef

begin_define
define|#
directive|define
name|EFTYPE
value|EINVAL
end_define

begin_comment
comment|/* POSIX 1003.1 format errno. */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|WCOREDUMP
end_ifndef

begin_comment
comment|/* 4.4BSD extension */
end_comment

begin_define
define|#
directive|define
name|WCOREDUMP
parameter_list|(
name|a
parameter_list|)
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|STDERR_FILENO
end_ifndef

begin_define
define|#
directive|define
name|STDIN_FILENO
value|0
end_define

begin_comment
comment|/* ANSI C #defines */
end_comment

begin_define
define|#
directive|define
name|STDOUT_FILENO
value|1
end_define

begin_define
define|#
directive|define
name|STDERR_FILENO
value|2
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|SEEK_END
end_ifndef

begin_define
define|#
directive|define
name|SEEK_SET
value|0
end_define

begin_comment
comment|/* POSIX 1003.1 seek values */
end_comment

begin_define
define|#
directive|define
name|SEEK_CUR
value|1
end_define

begin_define
define|#
directive|define
name|SEEK_END
value|2
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|_POSIX_VDISABLE
end_ifndef

begin_comment
comment|/* POSIX 1003.1 disabling char. */
end_comment

begin_define
define|#
directive|define
name|_POSIX_VDISABLE
value|0
end_define

begin_comment
comment|/* Some systems used 0. */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|S_ISLNK
end_ifndef

begin_comment
comment|/* BSD POSIX 1003.1 extensions */
end_comment

begin_define
define|#
directive|define
name|S_ISLNK
parameter_list|(
name|m
parameter_list|)
value|((m& 0170000) == 0120000)
end_define

begin_define
define|#
directive|define
name|S_ISSOCK
parameter_list|(
name|m
parameter_list|)
value|((m& 0170000) == 0140000)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|TCSASOFT
end_ifndef

begin_comment
comment|/* 4.4BSD extension. */
end_comment

begin_define
define|#
directive|define
name|TCSASOFT
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|_POSIX2_RE_DUP_MAX
end_ifndef

begin_comment
comment|/* POSIX 1003.2 values. */
end_comment

begin_define
define|#
directive|define
name|_POSIX2_RE_DUP_MAX
value|255
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|NULL
end_ifndef

begin_comment
comment|/* ANSI C #defines NULL everywhere. */
end_comment

begin_define
define|#
directive|define
name|NULL
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|MAX
end_ifndef

begin_comment
comment|/* Usually found in<sys/param.h>. */
end_comment

begin_define
define|#
directive|define
name|MAX
parameter_list|(
name|_a
parameter_list|,
name|_b
parameter_list|)
value|((_a)<(_b)?(_b):(_a))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|MIN
end_ifndef

begin_comment
comment|/* Usually found in<sys/param.h>. */
end_comment

begin_define
define|#
directive|define
name|MIN
parameter_list|(
name|_a
parameter_list|,
name|_b
parameter_list|)
value|((_a)<(_b)?(_a):(_b))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Default file permissions. */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|DEFFILEMODE
end_ifndef

begin_comment
comment|/* 4.4BSD extension. */
end_comment

begin_define
define|#
directive|define
name|DEFFILEMODE
value|(S_IRUSR|S_IWUSR|S_IRGRP|S_IWGRP|S_IROTH|S_IWOTH)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|S_ISDIR
end_ifndef

begin_comment
comment|/* POSIX 1003.1 file type tests. */
end_comment

begin_define
define|#
directive|define
name|S_ISDIR
parameter_list|(
name|m
parameter_list|)
value|((m& 0170000) == 0040000)
end_define

begin_comment
comment|/* directory */
end_comment

begin_define
define|#
directive|define
name|S_ISCHR
parameter_list|(
name|m
parameter_list|)
value|((m& 0170000) == 0020000)
end_define

begin_comment
comment|/* char special */
end_comment

begin_define
define|#
directive|define
name|S_ISBLK
parameter_list|(
name|m
parameter_list|)
value|((m& 0170000) == 0060000)
end_define

begin_comment
comment|/* block special */
end_comment

begin_define
define|#
directive|define
name|S_ISREG
parameter_list|(
name|m
parameter_list|)
value|((m& 0170000) == 0100000)
end_define

begin_comment
comment|/* regular file */
end_comment

begin_define
define|#
directive|define
name|S_ISFIFO
parameter_list|(
name|m
parameter_list|)
value|((m& 0170000) == 0010000)
end_define

begin_comment
comment|/* fifo */
end_comment

begin_define
define|#
directive|define
name|S_ISLNK
parameter_list|(
name|m
parameter_list|)
value|((m& 0170000) == 0120000)
end_define

begin_comment
comment|/* symbolic link */
end_comment

begin_define
define|#
directive|define
name|S_ISSOCK
parameter_list|(
name|m
parameter_list|)
value|((m& 0170000) == 0140000)
end_define

begin_comment
comment|/* socket */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* The type of a va_list. */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_BSD_VA_LIST_
end_ifndef

begin_comment
comment|/* 4.4BSD #define. */
end_comment

begin_define
define|#
directive|define
name|_BSD_VA_LIST_
value|char *
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_COMPAT_H_ */
end_comment

end_unit

