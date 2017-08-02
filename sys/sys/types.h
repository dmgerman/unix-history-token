begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1982, 1986, 1991, 1993, 1994  *	The Regents of the University of California.  All rights reserved.  * (c) UNIX System Laboratories, Inc.  * All or some portions of this file are derived from material licensed  * to the University of California by American Telephone and Telegraph  * Co. or Unix System Laboratories, Inc. and are reproduced herein with  * the permission of UNIX System Laboratories, Inc.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)types.h	8.6 (Berkeley) 2/19/95  * $FreeBSD$  */
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
file|<machine/endian.h>
end_include

begin_include
include|#
directive|include
file|<sys/_types.h>
end_include

begin_include
include|#
directive|include
file|<sys/_pthreadtypes.h>
end_include

begin_if
if|#
directive|if
name|__BSD_VISIBLE
end_if

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

begin_ifndef
ifndef|#
directive|ifndef
name|_KERNEL
end_ifndef

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

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * XXX POSIX sized integrals that should appear only in<sys/stdint.h>.  */
end_comment

begin_include
include|#
directive|include
file|<sys/_stdint.h>
end_include

begin_typedef
typedef|typedef
name|__uint8_t
name|u_int8_t
typedef|;
end_typedef

begin_comment
comment|/* unsigned integrals (deprecated) */
end_comment

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
name|__uint64_t
name|u_quad_t
typedef|;
end_typedef

begin_comment
comment|/* quads (deprecated) */
end_comment

begin_typedef
typedef|typedef
name|__int64_t
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
specifier|const
name|char
modifier|*
name|c_caddr_t
typedef|;
end_typedef

begin_comment
comment|/* core address, pointer to const */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_BLKSIZE_T_DECLARED
end_ifndef

begin_typedef
typedef|typedef
name|__blksize_t
name|blksize_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|_BLKSIZE_T_DECLARED
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_typedef
typedef|typedef
name|__cpuwhich_t
name|cpuwhich_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|__cpulevel_t
name|cpulevel_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|__cpusetid_t
name|cpusetid_t
typedef|;
end_typedef

begin_ifndef
ifndef|#
directive|ifndef
name|_BLKCNT_T_DECLARED
end_ifndef

begin_typedef
typedef|typedef
name|__blkcnt_t
name|blkcnt_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|_BLKCNT_T_DECLARED
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|_CLOCK_T_DECLARED
end_ifndef

begin_typedef
typedef|typedef
name|__clock_t
name|clock_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|_CLOCK_T_DECLARED
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|_CLOCKID_T_DECLARED
end_ifndef

begin_typedef
typedef|typedef
name|__clockid_t
name|clockid_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|_CLOCKID_T_DECLARED
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_typedef
typedef|typedef
name|__critical_t
name|critical_t
typedef|;
end_typedef

begin_comment
comment|/* Critical section value */
end_comment

begin_typedef
typedef|typedef
name|__int64_t
name|daddr_t
typedef|;
end_typedef

begin_comment
comment|/* disk address */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_DEV_T_DECLARED
end_ifndef

begin_typedef
typedef|typedef
name|__dev_t
name|dev_t
typedef|;
end_typedef

begin_comment
comment|/* device number or struct cdev */
end_comment

begin_define
define|#
directive|define
name|_DEV_T_DECLARED
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|_FFLAGS_T_DECLARED
end_ifndef

begin_typedef
typedef|typedef
name|__fflags_t
name|fflags_t
typedef|;
end_typedef

begin_comment
comment|/* file flags */
end_comment

begin_define
define|#
directive|define
name|_FFLAGS_T_DECLARED
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_typedef
typedef|typedef
name|__fixpt_t
name|fixpt_t
typedef|;
end_typedef

begin_comment
comment|/* fixed point number */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_FSBLKCNT_T_DECLARED
end_ifndef

begin_comment
comment|/* for statvfs() */
end_comment

begin_typedef
typedef|typedef
name|__fsblkcnt_t
name|fsblkcnt_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|__fsfilcnt_t
name|fsfilcnt_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|_FSBLKCNT_T_DECLARED
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|_GID_T_DECLARED
end_ifndef

begin_typedef
typedef|typedef
name|__gid_t
name|gid_t
typedef|;
end_typedef

begin_comment
comment|/* group id */
end_comment

begin_define
define|#
directive|define
name|_GID_T_DECLARED
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|_IN_ADDR_T_DECLARED
end_ifndef

begin_typedef
typedef|typedef
name|__uint32_t
name|in_addr_t
typedef|;
end_typedef

begin_comment
comment|/* base type for internet address */
end_comment

begin_define
define|#
directive|define
name|_IN_ADDR_T_DECLARED
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|_IN_PORT_T_DECLARED
end_ifndef

begin_typedef
typedef|typedef
name|__uint16_t
name|in_port_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|_IN_PORT_T_DECLARED
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|_ID_T_DECLARED
end_ifndef

begin_typedef
typedef|typedef
name|__id_t
name|id_t
typedef|;
end_typedef

begin_comment
comment|/* can hold a uid_t or pid_t */
end_comment

begin_define
define|#
directive|define
name|_ID_T_DECLARED
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|_INO_T_DECLARED
end_ifndef

begin_typedef
typedef|typedef
name|__ino_t
name|ino_t
typedef|;
end_typedef

begin_comment
comment|/* inode number */
end_comment

begin_define
define|#
directive|define
name|_INO_T_DECLARED
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|_KEY_T_DECLARED
end_ifndef

begin_typedef
typedef|typedef
name|__key_t
name|key_t
typedef|;
end_typedef

begin_comment
comment|/* IPC key (for Sys V IPC) */
end_comment

begin_define
define|#
directive|define
name|_KEY_T_DECLARED
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|_LWPID_T_DECLARED
end_ifndef

begin_typedef
typedef|typedef
name|__lwpid_t
name|lwpid_t
typedef|;
end_typedef

begin_comment
comment|/* Thread ID (a.k.a. LWP) */
end_comment

begin_define
define|#
directive|define
name|_LWPID_T_DECLARED
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|_MODE_T_DECLARED
end_ifndef

begin_typedef
typedef|typedef
name|__mode_t
name|mode_t
typedef|;
end_typedef

begin_comment
comment|/* permissions */
end_comment

begin_define
define|#
directive|define
name|_MODE_T_DECLARED
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|_ACCMODE_T_DECLARED
end_ifndef

begin_typedef
typedef|typedef
name|__accmode_t
name|accmode_t
typedef|;
end_typedef

begin_comment
comment|/* access permissions */
end_comment

begin_define
define|#
directive|define
name|_ACCMODE_T_DECLARED
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|_NLINK_T_DECLARED
end_ifndef

begin_typedef
typedef|typedef
name|__nlink_t
name|nlink_t
typedef|;
end_typedef

begin_comment
comment|/* link count */
end_comment

begin_define
define|#
directive|define
name|_NLINK_T_DECLARED
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|_OFF_T_DECLARED
end_ifndef

begin_typedef
typedef|typedef
name|__off_t
name|off_t
typedef|;
end_typedef

begin_comment
comment|/* file offset */
end_comment

begin_define
define|#
directive|define
name|_OFF_T_DECLARED
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|_OFF64_T_DECLARED
end_ifndef

begin_typedef
typedef|typedef
name|__off64_t
name|off64_t
typedef|;
end_typedef

begin_comment
comment|/* file offset (alias) */
end_comment

begin_define
define|#
directive|define
name|_OFF64_T_DECLARED
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|_PID_T_DECLARED
end_ifndef

begin_typedef
typedef|typedef
name|__pid_t
name|pid_t
typedef|;
end_typedef

begin_comment
comment|/* process id */
end_comment

begin_define
define|#
directive|define
name|_PID_T_DECLARED
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_typedef
typedef|typedef
name|__register_t
name|register_t
typedef|;
end_typedef

begin_ifndef
ifndef|#
directive|ifndef
name|_RLIM_T_DECLARED
end_ifndef

begin_typedef
typedef|typedef
name|__rlim_t
name|rlim_t
typedef|;
end_typedef

begin_comment
comment|/* resource limit */
end_comment

begin_define
define|#
directive|define
name|_RLIM_T_DECLARED
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_typedef
typedef|typedef
name|__int64_t
name|sbintime_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|__segsz_t
name|segsz_t
typedef|;
end_typedef

begin_comment
comment|/* segment size (in pages) */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_SIZE_T_DECLARED
end_ifndef

begin_typedef
typedef|typedef
name|__size_t
name|size_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|_SIZE_T_DECLARED
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|_SSIZE_T_DECLARED
end_ifndef

begin_typedef
typedef|typedef
name|__ssize_t
name|ssize_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|_SSIZE_T_DECLARED
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|_SUSECONDS_T_DECLARED
end_ifndef

begin_typedef
typedef|typedef
name|__suseconds_t
name|suseconds_t
typedef|;
end_typedef

begin_comment
comment|/* microseconds (signed) */
end_comment

begin_define
define|#
directive|define
name|_SUSECONDS_T_DECLARED
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|_TIME_T_DECLARED
end_ifndef

begin_typedef
typedef|typedef
name|__time_t
name|time_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|_TIME_T_DECLARED
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|_TIMER_T_DECLARED
end_ifndef

begin_typedef
typedef|typedef
name|__timer_t
name|timer_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|_TIMER_T_DECLARED
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|_MQD_T_DECLARED
end_ifndef

begin_typedef
typedef|typedef
name|__mqd_t
name|mqd_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|_MQD_T_DECLARED
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_typedef
typedef|typedef
name|__u_register_t
name|u_register_t
typedef|;
end_typedef

begin_ifndef
ifndef|#
directive|ifndef
name|_UID_T_DECLARED
end_ifndef

begin_typedef
typedef|typedef
name|__uid_t
name|uid_t
typedef|;
end_typedef

begin_comment
comment|/* user id */
end_comment

begin_define
define|#
directive|define
name|_UID_T_DECLARED
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|_USECONDS_T_DECLARED
end_ifndef

begin_typedef
typedef|typedef
name|__useconds_t
name|useconds_t
typedef|;
end_typedef

begin_comment
comment|/* microseconds (unsigned) */
end_comment

begin_define
define|#
directive|define
name|_USECONDS_T_DECLARED
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|_CAP_IOCTL_T_DECLARED
end_ifndef

begin_define
define|#
directive|define
name|_CAP_IOCTL_T_DECLARED
end_define

begin_typedef
typedef|typedef
name|unsigned
name|long
name|cap_ioctl_t
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|_CAP_RIGHTS_T_DECLARED
end_ifndef

begin_define
define|#
directive|define
name|_CAP_RIGHTS_T_DECLARED
end_define

begin_struct_decl
struct_decl|struct
name|cap_rights
struct_decl|;
end_struct_decl

begin_typedef
typedef|typedef
name|struct
name|cap_rights
name|cap_rights_t
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_typedef
typedef|typedef
name|__vm_offset_t
name|vm_offset_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|__int64_t
name|vm_ooffset_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|__vm_paddr_t
name|vm_paddr_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|__uint64_t
name|vm_pindex_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|__vm_size_t
name|vm_size_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|__rman_res_t
name|rman_res_t
typedef|;
end_typedef

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
name|struct
name|device
modifier|*
name|device_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|__intfptr_t
name|intfptr_t
typedef|;
end_typedef

begin_comment
comment|/*  * XXX this is fixed width for historical reasons.  It should have had type  * __int_fast32_t.  Fixed-width types should not be used unless binary  * compatibility is essential.  Least-width types should be used even less  * since they provide smaller benefits.  *  * XXX should be MD.  *  * XXX this is bogus in -current, but still used for spl*().  */
end_comment

begin_typedef
typedef|typedef
name|__uint32_t
name|intrmask_t
typedef|;
end_typedef

begin_comment
comment|/* Interrupt mask (spl, xxx_imask...) */
end_comment

begin_typedef
typedef|typedef
name|__uintfptr_t
name|uintfptr_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|__uint64_t
name|uoff_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|char
name|vm_memattr_t
typedef|;
end_typedef

begin_comment
comment|/* memory attribute codes */
end_comment

begin_typedef
typedef|typedef
name|struct
name|vm_page
modifier|*
name|vm_page_t
typedef|;
end_typedef

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|__bool_true_false_are_defined
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|__cplusplus
argument_list|)
end_if

begin_define
define|#
directive|define
name|__bool_true_false_are_defined
value|1
end_define

begin_define
define|#
directive|define
name|false
value|0
end_define

begin_define
define|#
directive|define
name|true
value|1
end_define

begin_if
if|#
directive|if
name|__STDC_VERSION__
operator|<
literal|199901L
operator|&&
name|__GNUC__
operator|<
literal|3
operator|&&
operator|!
name|defined
argument_list|(
name|__INTEL_COMPILER
argument_list|)
end_if

begin_typedef
typedef|typedef
name|int
name|_Bool
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_typedef
typedef|typedef
name|_Bool
name|bool
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !__bool_true_false_are_defined&& !__cplusplus */
end_comment

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

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_KERNEL */
end_comment

begin_comment
comment|/*  * The following are all things that really shouldn't exist in this header,  * since its purpose is to provide typedefs, not miscellaneous doodads.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|__POPCNT__
end_ifdef

begin_define
define|#
directive|define
name|__bitcount64
parameter_list|(
name|x
parameter_list|)
value|__builtin_popcountll((__uint64_t)(x))
end_define

begin_define
define|#
directive|define
name|__bitcount32
parameter_list|(
name|x
parameter_list|)
value|__builtin_popcount((__uint32_t)(x))
end_define

begin_define
define|#
directive|define
name|__bitcount16
parameter_list|(
name|x
parameter_list|)
value|__builtin_popcount((__uint16_t)(x))
end_define

begin_define
define|#
directive|define
name|__bitcountl
parameter_list|(
name|x
parameter_list|)
value|__builtin_popcountl((unsigned long)(x))
end_define

begin_define
define|#
directive|define
name|__bitcount
parameter_list|(
name|x
parameter_list|)
value|__builtin_popcount((unsigned int)(x))
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/*  * Population count algorithm using SWAR approach  * - "SIMD Within A Register".  */
end_comment

begin_function
specifier|static
name|__inline
name|__uint16_t
name|__bitcount16
parameter_list|(
name|__uint16_t
name|_x
parameter_list|)
block|{
name|_x
operator|=
operator|(
name|_x
operator|&
literal|0x5555
operator|)
operator|+
operator|(
operator|(
name|_x
operator|&
literal|0xaaaa
operator|)
operator|>>
literal|1
operator|)
expr_stmt|;
name|_x
operator|=
operator|(
name|_x
operator|&
literal|0x3333
operator|)
operator|+
operator|(
operator|(
name|_x
operator|&
literal|0xcccc
operator|)
operator|>>
literal|2
operator|)
expr_stmt|;
name|_x
operator|=
operator|(
name|_x
operator|+
operator|(
name|_x
operator|>>
literal|4
operator|)
operator|)
operator|&
literal|0x0f0f
expr_stmt|;
name|_x
operator|=
operator|(
name|_x
operator|+
operator|(
name|_x
operator|>>
literal|8
operator|)
operator|)
operator|&
literal|0x00ff
expr_stmt|;
return|return
operator|(
name|_x
operator|)
return|;
block|}
end_function

begin_function
specifier|static
name|__inline
name|__uint32_t
name|__bitcount32
parameter_list|(
name|__uint32_t
name|_x
parameter_list|)
block|{
name|_x
operator|=
operator|(
name|_x
operator|&
literal|0x55555555
operator|)
operator|+
operator|(
operator|(
name|_x
operator|&
literal|0xaaaaaaaa
operator|)
operator|>>
literal|1
operator|)
expr_stmt|;
name|_x
operator|=
operator|(
name|_x
operator|&
literal|0x33333333
operator|)
operator|+
operator|(
operator|(
name|_x
operator|&
literal|0xcccccccc
operator|)
operator|>>
literal|2
operator|)
expr_stmt|;
name|_x
operator|=
operator|(
name|_x
operator|+
operator|(
name|_x
operator|>>
literal|4
operator|)
operator|)
operator|&
literal|0x0f0f0f0f
expr_stmt|;
name|_x
operator|=
operator|(
name|_x
operator|+
operator|(
name|_x
operator|>>
literal|8
operator|)
operator|)
expr_stmt|;
name|_x
operator|=
operator|(
name|_x
operator|+
operator|(
name|_x
operator|>>
literal|16
operator|)
operator|)
operator|&
literal|0x000000ff
expr_stmt|;
return|return
operator|(
name|_x
operator|)
return|;
block|}
end_function

begin_ifdef
ifdef|#
directive|ifdef
name|__LP64__
end_ifdef

begin_function
specifier|static
name|__inline
name|__uint64_t
name|__bitcount64
parameter_list|(
name|__uint64_t
name|_x
parameter_list|)
block|{
name|_x
operator|=
operator|(
name|_x
operator|&
literal|0x5555555555555555
operator|)
operator|+
operator|(
operator|(
name|_x
operator|&
literal|0xaaaaaaaaaaaaaaaa
operator|)
operator|>>
literal|1
operator|)
expr_stmt|;
name|_x
operator|=
operator|(
name|_x
operator|&
literal|0x3333333333333333
operator|)
operator|+
operator|(
operator|(
name|_x
operator|&
literal|0xcccccccccccccccc
operator|)
operator|>>
literal|2
operator|)
expr_stmt|;
name|_x
operator|=
operator|(
name|_x
operator|+
operator|(
name|_x
operator|>>
literal|4
operator|)
operator|)
operator|&
literal|0x0f0f0f0f0f0f0f0f
expr_stmt|;
name|_x
operator|=
operator|(
name|_x
operator|+
operator|(
name|_x
operator|>>
literal|8
operator|)
operator|)
expr_stmt|;
name|_x
operator|=
operator|(
name|_x
operator|+
operator|(
name|_x
operator|>>
literal|16
operator|)
operator|)
expr_stmt|;
name|_x
operator|=
operator|(
name|_x
operator|+
operator|(
name|_x
operator|>>
literal|32
operator|)
operator|)
operator|&
literal|0x000000ff
expr_stmt|;
return|return
operator|(
name|_x
operator|)
return|;
block|}
end_function

begin_define
define|#
directive|define
name|__bitcountl
parameter_list|(
name|x
parameter_list|)
value|__bitcount64((unsigned long)(x))
end_define

begin_else
else|#
directive|else
end_else

begin_function
specifier|static
name|__inline
name|__uint64_t
name|__bitcount64
parameter_list|(
name|__uint64_t
name|_x
parameter_list|)
block|{
return|return
operator|(
name|__bitcount32
argument_list|(
name|_x
operator|>>
literal|32
argument_list|)
operator|+
name|__bitcount32
argument_list|(
name|_x
argument_list|)
operator|)
return|;
block|}
end_function

begin_define
define|#
directive|define
name|__bitcountl
parameter_list|(
name|x
parameter_list|)
value|__bitcount32((unsigned long)(x))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|__bitcount
parameter_list|(
name|x
parameter_list|)
value|__bitcount32((unsigned int)(x))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|__BSD_VISIBLE
end_if

begin_include
include|#
directive|include
file|<sys/select.h>
end_include

begin_define
define|#
directive|define
name|major
parameter_list|(
name|x
parameter_list|)
value|((int)((dev_t)(x)>> 32))
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
value|((int)((x)& 0xffffffff))
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
value|(((dev_t)(x)<< 32) | (unsigned)(y))
end_define

begin_comment
comment|/* create dev_t */
end_comment

begin_comment
comment|/*  * These declarations belong elsewhere, but are repeated here and in  *<stdio.h> to give broken programs a better chance of working with  * 64-bit off_t's.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_KERNEL
end_ifndef

begin_function_decl
name|__BEGIN_DECLS
ifndef|#
directive|ifndef
name|_FTRUNCATE_DECLARED
define|#
directive|define
name|_FTRUNCATE_DECLARED
name|int
name|ftruncate
parameter_list|(
name|int
parameter_list|,
name|off_t
parameter_list|)
function_decl|;
end_function_decl

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

begin_function_decl
name|off_t
name|lseek
parameter_list|(
name|int
parameter_list|,
name|off_t
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

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

begin_function_decl
name|void
modifier|*
name|mmap
parameter_list|(
name|void
modifier|*
parameter_list|,
name|size_t
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|,
name|off_t
parameter_list|)
function_decl|;
end_function_decl

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

begin_function_decl
name|int
name|truncate
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
name|off_t
parameter_list|)
function_decl|;
end_function_decl

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
comment|/* __BSD_VISIBLE */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_SYS_TYPES_H_ */
end_comment

end_unit

