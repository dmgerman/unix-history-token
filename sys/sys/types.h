begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1982, 1986, 1991 The Regents of the University of California.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	from: @(#)types.h	7.17 (Berkeley) 5/6/91  *	$Id: types.h,v 1.10 1994/04/05 22:09:33 wollman Exp $  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_TYPES_H_
end_ifndef

begin_define
define|#
directive|define
name|_TYPES_H_
end_define

begin_typedef
typedef|typedef
name|unsigned
name|char
name|u_char
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|unsigned
name|short
name|u_short
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|unsigned
name|int
name|u_int
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|unsigned
name|long
name|u_long
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|unsigned
name|short
name|ushort
typedef|;
end_typedef

begin_comment
comment|/* Sys V compatibility */
end_comment

begin_typedef
typedef|typedef
name|char
modifier|*
name|caddr_t
typedef|;
end_typedef

begin_comment
comment|/* core address */
end_comment

begin_typedef
typedef|typedef
name|long
name|daddr_t
typedef|;
end_typedef

begin_comment
comment|/* disk address */
end_comment

begin_typedef
typedef|typedef
name|short
name|dev_t
typedef|;
end_typedef

begin_comment
comment|/* device number */
end_comment

begin_typedef
typedef|typedef
name|u_long
name|ino_t
typedef|;
end_typedef

begin_comment
comment|/* inode number */
end_comment

begin_typedef
typedef|typedef
name|long
name|off_t
typedef|;
end_typedef

begin_comment
comment|/* file offset (should be a quad) */
end_comment

begin_typedef
typedef|typedef
name|u_short
name|nlink_t
typedef|;
end_typedef

begin_comment
comment|/* link count */
end_comment

begin_typedef
typedef|typedef
name|long
name|swblk_t
typedef|;
end_typedef

begin_comment
comment|/* swap offset */
end_comment

begin_typedef
typedef|typedef
name|long
name|segsz_t
typedef|;
end_typedef

begin_comment
comment|/* segment size */
end_comment

begin_typedef
typedef|typedef
name|u_short
name|uid_t
typedef|;
end_typedef

begin_comment
comment|/* user id */
end_comment

begin_typedef
typedef|typedef
name|u_short
name|gid_t
typedef|;
end_typedef

begin_comment
comment|/* group id */
end_comment

begin_typedef
typedef|typedef
name|short
name|pid_t
typedef|;
end_typedef

begin_comment
comment|/* process id */
end_comment

begin_typedef
typedef|typedef
name|u_short
name|mode_t
typedef|;
end_typedef

begin_comment
comment|/* permissions */
end_comment

begin_typedef
typedef|typedef
name|u_long
name|fixpt_t
typedef|;
end_typedef

begin_comment
comment|/* fixed point number */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_POSIX_SOURCE
end_ifndef

begin_ifdef
ifdef|#
directive|ifdef
name|__STRICT_ANSI__
end_ifdef

begin_typedef
typedef|typedef
name|quad_t
name|__attribute
argument_list|(
operator|(
name|mode
argument_list|(
name|DI
argument_list|)
operator|)
argument_list|)
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|unsigned
name|u_quad_t
name|__attribute
typedef|((
name|mode
typedef|(
name|DI
typedef|) ));
end_typedef

begin_else
else|#
directive|else
end_else

begin_typedef
typedef|typedef
name|long
name|long
name|quad_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|unsigned
name|long
name|long
name|u_quad_t
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_typedef
typedef|typedef
name|quad_t
modifier|*
name|qaddr_t
typedef|;
end_typedef

begin_comment
comment|/* GCC_1 quad definitions */
end_comment

begin_comment
comment|/* typedef	struct	_uquad	{ u_long val[2]; } u_quad;  * typedef	struct	_quad	{   long val[2]; } quad;  * typedef	long *	qaddr_t;   */
end_comment

begin_define
define|#
directive|define
name|major
parameter_list|(
name|x
parameter_list|)
value|((int)(((u_int)(x)>> 8)&0xff))
end_define

begin_comment
comment|/* major number */
end_comment

begin_define
define|#
directive|define
name|minor
parameter_list|(
name|x
parameter_list|)
value|((int)((x)&0xff))
end_define

begin_comment
comment|/* minor number */
end_comment

begin_define
define|#
directive|define
name|makedev
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
value|((dev_t)(((x)<<8) | (y)))
end_define

begin_comment
comment|/* create dev_t */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<machine/ansi.h>
end_include

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|_ANSI_SOURCE
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|_POSIX_SOURCE
argument_list|)
end_if

begin_include
include|#
directive|include
file|<machine/types.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|_CLOCK_T_
end_ifdef

begin_typedef
typedef|typedef
name|_CLOCK_T_
name|clock_t
typedef|;
end_typedef

begin_undef
undef|#
directive|undef
name|_CLOCK_T_
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|_SIZE_T_
end_ifdef

begin_typedef
typedef|typedef
name|_SIZE_T_
name|size_t
typedef|;
end_typedef

begin_undef
undef|#
directive|undef
name|_SIZE_T_
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|_TIME_T_
end_ifdef

begin_typedef
typedef|typedef
name|_TIME_T_
name|time_t
typedef|;
end_typedef

begin_undef
undef|#
directive|undef
name|_TIME_T_
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|_POSIX_SOURCE
end_ifndef

begin_define
define|#
directive|define
name|NBBY
value|8
end_define

begin_comment
comment|/* number of bits in a byte */
end_comment

begin_comment
comment|/*  * Select uses bit masks of file descriptors in longs.  These macros  * manipulate such bit fields (the filesystem macros use chars).  * FD_SETSIZE may be defined by the user, but the default here should  * be enough for most uses.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|FD_SETSIZE
end_ifndef

begin_define
define|#
directive|define
name|FD_SETSIZE
value|256
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_typedef
typedef|typedef
name|long
name|fd_mask
typedef|;
end_typedef

begin_define
define|#
directive|define
name|NFDBITS
value|(sizeof(fd_mask) * NBBY)
end_define

begin_comment
comment|/* bits per mask */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|howmany
end_ifndef

begin_define
define|#
directive|define
name|howmany
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
value|(((x)+((y)-1))/(y))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_typedef
typedef|typedef
struct|struct
name|fd_set
block|{
name|fd_mask
name|fds_bits
index|[
name|howmany
argument_list|(
name|FD_SETSIZE
argument_list|,
name|NFDBITS
argument_list|)
index|]
decl_stmt|;
block|}
name|fd_set
typedef|;
end_typedef

begin_define
define|#
directive|define
name|FD_SET
parameter_list|(
name|n
parameter_list|,
name|p
parameter_list|)
value|((p)->fds_bits[(n)/NFDBITS] |= (1<< ((n) % NFDBITS)))
end_define

begin_define
define|#
directive|define
name|FD_CLR
parameter_list|(
name|n
parameter_list|,
name|p
parameter_list|)
value|((p)->fds_bits[(n)/NFDBITS]&= ~(1<< ((n) % NFDBITS)))
end_define

begin_define
define|#
directive|define
name|FD_ISSET
parameter_list|(
name|n
parameter_list|,
name|p
parameter_list|)
value|((p)->fds_bits[(n)/NFDBITS]& (1<< ((n) % NFDBITS)))
end_define

begin_define
define|#
directive|define
name|FD_ZERO
parameter_list|(
name|p
parameter_list|)
value|bzero((char *)(p), sizeof(*(p)))
end_define

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__STDC__
argument_list|)
end_if

begin_comment
comment|/*  * Forward structure declarations for function prototypes.  * We include the common structures that cross subsystem boundaries here;  * others are mostly used in the same place that the structure is defined.  */
end_comment

begin_struct_decl
struct_decl|struct
name|proc
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|pgrp
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|ucred
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|rusage
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|file
struct_decl|;
end_struct_decl

begin_ifdef
ifdef|#
directive|ifdef
name|KERNEL
end_ifdef

begin_struct_decl
struct_decl|struct
name|buf
struct_decl|;
end_struct_decl

begin_endif
endif|#
directive|endif
end_endif

begin_struct_decl
struct_decl|struct
name|tty
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|uio
struct_decl|;
end_struct_decl

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_POSIX_SOURCE */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_TYPES_H_ */
end_comment

end_unit

