begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1982, 1986, 1991, 1993, 1994  *	The Regents of the University of California.  All rights reserved.  * (c) UNIX System Laboratories, Inc.  * All or some portions of this file are derived from material licensed  * to the University of California by American Telephone and Telegraph  * Co. or Unix System Laboratories, Inc. and are reproduced herein with  * the permission of UNIX System Laboratories, Inc.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)types.h	8.6 (Berkeley) 2/19/95  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_SYS_TYPES_H_
end_ifndef

begin_define
define|#
directive|define
name|_SYS_TYPES_H_
end_define

begin_include
include|#
directive|include
file|<sys/cdefs.h>
end_include

begin_comment
comment|/* Machine type dependent parameters. */
end_comment

begin_include
include|#
directive|include
file|<sys/stdint.h>
end_include

begin_comment
comment|/* includes<machine/ansi.h> */
end_comment

begin_include
include|#
directive|include
file|<machine/endian.h>
end_include

begin_include
include|#
directive|include
file|<machine/types.h>
end_include

begin_ifndef
ifndef|#
directive|ifndef
name|_POSIX_SOURCE
end_ifndef

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
name|unsigned
name|int
name|uint
typedef|;
end_typedef

begin_comment
comment|/* Sys V compatibility */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_typedef
typedef|typedef
name|__uint8_t
name|u_int8_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|__uint16_t
name|u_int16_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|__uint32_t
name|u_int32_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|__uint64_t
name|u_int64_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|u_int64_t
name|u_quad_t
typedef|;
end_typedef

begin_comment
comment|/* quads */
end_comment

begin_typedef
typedef|typedef
name|int64_t
name|quad_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|quad_t
modifier|*
name|qaddr_t
typedef|;
end_typedef

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
name|__const
name|char
modifier|*
name|c_caddr_t
typedef|;
end_typedef

begin_comment
comment|/* core address, pointer to const */
end_comment

begin_typedef
typedef|typedef
name|__volatile
name|char
modifier|*
name|v_caddr_t
typedef|;
end_typedef

begin_comment
comment|/* core address, pointer to volatile */
end_comment

begin_typedef
typedef|typedef
name|int32_t
name|daddr_t
typedef|;
end_typedef

begin_comment
comment|/* disk address */
end_comment

begin_typedef
typedef|typedef
name|u_int32_t
name|u_daddr_t
typedef|;
end_typedef

begin_comment
comment|/* unsigned disk address */
end_comment

begin_typedef
typedef|typedef
name|u_int32_t
name|fixpt_t
typedef|;
end_typedef

begin_comment
comment|/* fixed point number */
end_comment

begin_typedef
typedef|typedef
name|u_int32_t
name|gid_t
typedef|;
end_typedef

begin_comment
comment|/* group id */
end_comment

begin_typedef
typedef|typedef
name|u_int32_t
name|ino_t
typedef|;
end_typedef

begin_comment
comment|/* inode number */
end_comment

begin_typedef
typedef|typedef
name|long
name|key_t
typedef|;
end_typedef

begin_comment
comment|/* IPC key (for Sys V IPC) */
end_comment

begin_typedef
typedef|typedef
name|u_int16_t
name|mode_t
typedef|;
end_typedef

begin_comment
comment|/* permissions */
end_comment

begin_typedef
typedef|typedef
name|u_int16_t
name|nlink_t
typedef|;
end_typedef

begin_comment
comment|/* link count */
end_comment

begin_typedef
typedef|typedef
name|_BSD_OFF_T_
name|off_t
typedef|;
end_typedef

begin_comment
comment|/* file offset */
end_comment

begin_typedef
typedef|typedef
name|_BSD_PID_T_
name|pid_t
typedef|;
end_typedef

begin_comment
comment|/* process id */
end_comment

begin_typedef
typedef|typedef
name|quad_t
name|rlim_t
typedef|;
end_typedef

begin_comment
comment|/* resource limit */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|__alpha__
end_ifdef

begin_comment
comment|/* XXX should be in<machine/types.h> */
end_comment

begin_typedef
typedef|typedef
name|int64_t
name|segsz_t
typedef|;
end_typedef

begin_comment
comment|/* segment size */
end_comment

begin_else
else|#
directive|else
end_else

begin_typedef
typedef|typedef
name|int32_t
name|segsz_t
typedef|;
end_typedef

begin_comment
comment|/* segment size */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_typedef
typedef|typedef
name|int32_t
name|swblk_t
typedef|;
end_typedef

begin_comment
comment|/* swap offset */
end_comment

begin_typedef
typedef|typedef
name|int32_t
name|ufs_daddr_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|int32_t
name|ufs_time_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|u_int32_t
name|uid_t
typedef|;
end_typedef

begin_comment
comment|/* user id */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_typedef
typedef|typedef
name|int
name|boolean_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|u_int64_t
name|uoff_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|vm_page
modifier|*
name|vm_page_t
typedef|;
end_typedef

begin_struct_decl
struct_decl|struct
name|specinfo
struct_decl|;
end_struct_decl

begin_typedef
typedef|typedef
name|u_int32_t
name|udev_t
typedef|;
end_typedef

begin_comment
comment|/* device number */
end_comment

begin_typedef
typedef|typedef
name|struct
name|specinfo
modifier|*
name|dev_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|offsetof
parameter_list|(
name|type
parameter_list|,
name|field
parameter_list|)
value|__offsetof(type, field)
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* !_KERNEL */
end_comment

begin_typedef
typedef|typedef
name|u_int32_t
name|dev_t
typedef|;
end_typedef

begin_comment
comment|/* device number */
end_comment

begin_define
define|#
directive|define
name|udev_t
value|dev_t
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|_POSIX_SOURCE
end_ifndef

begin_comment
comment|/*  * minor() gives a cookie instead of an index since we don't want to  * change the meanings of bits 0-15 or waste time and space shifting  * bits 16-31 for devices that don't use them.  */
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
value|((int)((x)&0xffff00ff))
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
value|((dev_t)(((x)<< 8) | (y)))
end_define

begin_comment
comment|/* create dev_t */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _POSIX_SOURCE */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_KERNEL */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|_BSD_CLOCK_T_
end_ifdef

begin_typedef
typedef|typedef
name|_BSD_CLOCK_T_
name|clock_t
typedef|;
end_typedef

begin_undef
undef|#
directive|undef
name|_BSD_CLOCK_T_
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|_BSD_CLOCKID_T_
end_ifdef

begin_typedef
typedef|typedef
name|_BSD_CLOCKID_T_
name|clockid_t
typedef|;
end_typedef

begin_undef
undef|#
directive|undef
name|_BSD_CLOCKID_T_
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|_BSD_FFLAGS_T_
end_ifdef

begin_typedef
typedef|typedef
name|_BSD_FFLAGS_T_
name|fflags_t
typedef|;
end_typedef

begin_comment
comment|/* file flags */
end_comment

begin_undef
undef|#
directive|undef
name|_BSD_FFLAGS_T_
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|_BSD_SIZE_T_
end_ifdef

begin_typedef
typedef|typedef
name|_BSD_SIZE_T_
name|size_t
typedef|;
end_typedef

begin_undef
undef|#
directive|undef
name|_BSD_SIZE_T_
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|_BSD_SSIZE_T_
end_ifdef

begin_typedef
typedef|typedef
name|_BSD_SSIZE_T_
name|ssize_t
typedef|;
end_typedef

begin_undef
undef|#
directive|undef
name|_BSD_SSIZE_T_
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|_BSD_TIME_T_
end_ifdef

begin_typedef
typedef|typedef
name|_BSD_TIME_T_
name|time_t
typedef|;
end_typedef

begin_undef
undef|#
directive|undef
name|_BSD_TIME_T_
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|_BSD_TIMER_T_
end_ifdef

begin_typedef
typedef|typedef
name|_BSD_TIMER_T_
name|timer_t
typedef|;
end_typedef

begin_undef
undef|#
directive|undef
name|_BSD_TIMER_T_
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
value|1024U
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_typedef
typedef|typedef
name|unsigned
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
value|(((x) + ((y) - 1U)) / (y))
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
name|_fdset_mask
parameter_list|(
name|n
parameter_list|)
value|((fd_mask)1<< ((n) % NFDBITS))
end_define

begin_define
define|#
directive|define
name|FD_SET
parameter_list|(
name|n
parameter_list|,
name|p
parameter_list|)
value|((p)->fds_bits[(n)/NFDBITS] |= _fdset_mask(n))
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
value|((p)->fds_bits[(n)/NFDBITS]&= ~_fdset_mask(n))
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
value|((p)->fds_bits[(n)/NFDBITS]& _fdset_mask(n))
end_define

begin_define
define|#
directive|define
name|FD_COPY
parameter_list|(
name|f
parameter_list|,
name|t
parameter_list|)
value|bcopy(f, t, sizeof(*(f)))
end_define

begin_define
define|#
directive|define
name|FD_ZERO
parameter_list|(
name|p
parameter_list|)
value|bzero(p, sizeof(*(p)))
end_define

begin_comment
comment|/*  * These declarations belong elsewhere, but are repeated here and in  *<stdio.h> to give broken programs a better chance of working with  * 64-bit off_t's.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_KERNEL
end_ifndef

begin_decl_stmt
name|__BEGIN_DECLS
ifndef|#
directive|ifndef
name|_FTRUNCATE_DECLARED
define|#
directive|define
name|_FTRUNCATE_DECLARED
name|int
name|ftruncate
name|__P
argument_list|(
operator|(
name|int
operator|,
name|off_t
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|_LSEEK_DECLARED
end_ifndef

begin_define
define|#
directive|define
name|_LSEEK_DECLARED
end_define

begin_decl_stmt
name|off_t
name|lseek
name|__P
argument_list|(
operator|(
name|int
operator|,
name|off_t
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|_MMAP_DECLARED
end_ifndef

begin_define
define|#
directive|define
name|_MMAP_DECLARED
end_define

begin_decl_stmt
name|void
modifier|*
name|mmap
name|__P
argument_list|(
operator|(
name|void
operator|*
operator|,
name|size_t
operator|,
name|int
operator|,
name|int
operator|,
name|int
operator|,
name|off_t
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|_TRUNCATE_DECLARED
end_ifndef

begin_define
define|#
directive|define
name|_TRUNCATE_DECLARED
end_define

begin_decl_stmt
name|int
name|truncate
name|__P
argument_list|(
operator|(
specifier|const
name|char
operator|*
operator|,
name|off_t
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_macro
name|__END_DECLS
end_macro

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_KERNEL */
end_comment

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
comment|/* !_SYS_TYPES_H_ */
end_comment

end_unit

