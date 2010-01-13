begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1999-2003 Damien Miller.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_DEFINES_H
end_ifndef

begin_define
define|#
directive|define
name|_DEFINES_H
end_define

begin_comment
comment|/* $Id: defines.h,v 1.156 2009/08/28 01:21:07 dtucker Exp $ */
end_comment

begin_comment
comment|/* Constants */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|HAVE_DECL_SHUT_RD
argument_list|)
operator|&&
name|HAVE_DECL_SHUT_RD
operator|==
literal|0
end_if

begin_enum
enum|enum
block|{
name|SHUT_RD
init|=
literal|0
block|,
comment|/* No more receptions.  */
name|SHUT_WR
block|,
comment|/* No more transmissions.  */
name|SHUT_RDWR
comment|/* No more receptions or transmissions.  */
block|}
enum|;
end_enum

begin_define
define|#
directive|define
name|SHUT_RD
value|SHUT_RD
end_define

begin_define
define|#
directive|define
name|SHUT_WR
value|SHUT_WR
end_define

begin_define
define|#
directive|define
name|SHUT_RDWR
value|SHUT_RDWR
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|IPTOS_LOWDELAY
end_ifndef

begin_define
define|#
directive|define
name|IPTOS_LOWDELAY
value|0x10
end_define

begin_define
define|#
directive|define
name|IPTOS_THROUGHPUT
value|0x08
end_define

begin_define
define|#
directive|define
name|IPTOS_RELIABILITY
value|0x04
end_define

begin_define
define|#
directive|define
name|IPTOS_LOWCOST
value|0x02
end_define

begin_define
define|#
directive|define
name|IPTOS_MINCOST
value|IPTOS_LOWCOST
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* IPTOS_LOWDELAY */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|MAXPATHLEN
end_ifndef

begin_ifdef
ifdef|#
directive|ifdef
name|PATH_MAX
end_ifdef

begin_define
define|#
directive|define
name|MAXPATHLEN
value|PATH_MAX
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* PATH_MAX */
end_comment

begin_define
define|#
directive|define
name|MAXPATHLEN
value|64
end_define

begin_comment
comment|/* realpath uses a fixed buffer of size MAXPATHLEN, so force use of ours */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|BROKEN_REALPATH
end_ifndef

begin_define
define|#
directive|define
name|BROKEN_REALPATH
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* BROKEN_REALPATH */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* PATH_MAX */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* MAXPATHLEN */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|PATH_MAX
end_ifndef

begin_ifdef
ifdef|#
directive|ifdef
name|_POSIX_PATH_MAX
end_ifdef

begin_define
define|#
directive|define
name|PATH_MAX
value|_POSIX_PATH_MAX
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|HAVE_DECL_MAXSYMLINKS
argument_list|)
operator|&&
name|HAVE_DECL_MAXSYMLINKS
operator|==
literal|0
end_if

begin_define
define|#
directive|define
name|MAXSYMLINKS
value|5
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|STDIN_FILENO
end_ifndef

begin_define
define|#
directive|define
name|STDIN_FILENO
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|STDOUT_FILENO
end_ifndef

begin_define
define|#
directive|define
name|STDOUT_FILENO
value|1
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
name|NGROUPS_MAX
end_ifndef

begin_comment
comment|/* Disable groupaccess if NGROUP_MAX is not set */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|NGROUPS
end_ifdef

begin_define
define|#
directive|define
name|NGROUPS_MAX
value|NGROUPS
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|NGROUPS_MAX
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|HAVE_DECL_O_NONBLOCK
argument_list|)
operator|&&
name|HAVE_DECL_O_NONBLOCK
operator|==
literal|0
end_if

begin_define
define|#
directive|define
name|O_NONBLOCK
value|00004
end_define

begin_comment
comment|/* Non Blocking Open */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|S_ISDIR
end_ifndef

begin_define
define|#
directive|define
name|S_ISDIR
parameter_list|(
name|mode
parameter_list|)
value|(((mode)& (_S_IFMT)) == (_S_IFDIR))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* S_ISDIR */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|S_ISREG
end_ifndef

begin_define
define|#
directive|define
name|S_ISREG
parameter_list|(
name|mode
parameter_list|)
value|(((mode)& (_S_IFMT)) == (_S_IFREG))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* S_ISREG */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|S_ISLNK
end_ifndef

begin_define
define|#
directive|define
name|S_ISLNK
parameter_list|(
name|mode
parameter_list|)
value|(((mode)& S_IFMT) == S_IFLNK)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* S_ISLNK */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|S_IXUSR
end_ifndef

begin_define
define|#
directive|define
name|S_IXUSR
value|0000100
end_define

begin_comment
comment|/* execute/search permission, */
end_comment

begin_define
define|#
directive|define
name|S_IXGRP
value|0000010
end_define

begin_comment
comment|/* execute/search permission, */
end_comment

begin_define
define|#
directive|define
name|S_IXOTH
value|0000001
end_define

begin_comment
comment|/* execute/search permission, */
end_comment

begin_define
define|#
directive|define
name|_S_IWUSR
value|0000200
end_define

begin_comment
comment|/* write permission, */
end_comment

begin_define
define|#
directive|define
name|S_IWUSR
value|_S_IWUSR
end_define

begin_comment
comment|/* write permission, owner */
end_comment

begin_define
define|#
directive|define
name|S_IWGRP
value|0000020
end_define

begin_comment
comment|/* write permission, group */
end_comment

begin_define
define|#
directive|define
name|S_IWOTH
value|0000002
end_define

begin_comment
comment|/* write permission, other */
end_comment

begin_define
define|#
directive|define
name|S_IRUSR
value|0000400
end_define

begin_comment
comment|/* read permission, owner */
end_comment

begin_define
define|#
directive|define
name|S_IRGRP
value|0000040
end_define

begin_comment
comment|/* read permission, group */
end_comment

begin_define
define|#
directive|define
name|S_IROTH
value|0000004
end_define

begin_comment
comment|/* read permission, other */
end_comment

begin_define
define|#
directive|define
name|S_IRWXU
value|0000700
end_define

begin_comment
comment|/* read, write, execute */
end_comment

begin_define
define|#
directive|define
name|S_IRWXG
value|0000070
end_define

begin_comment
comment|/* read, write, execute */
end_comment

begin_define
define|#
directive|define
name|S_IRWXO
value|0000007
end_define

begin_comment
comment|/* read, write, execute */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* S_IXUSR */
end_comment

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|MAP_ANON
argument_list|)
operator|&&
name|defined
argument_list|(
name|MAP_ANONYMOUS
argument_list|)
end_if

begin_define
define|#
directive|define
name|MAP_ANON
value|MAP_ANONYMOUS
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|MAP_FAILED
end_ifndef

begin_define
define|#
directive|define
name|MAP_FAILED
value|((void *)-1)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* *-*-nto-qnx doesn't define this constant in the system headers */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|MISSING_NFDBITS
end_ifdef

begin_define
define|#
directive|define
name|NFDBITS
value|(8 * sizeof(unsigned long))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* SCO Open Server 3 has INADDR_LOOPBACK defined in rpc/rpc.h but including rpc/rpc.h breaks Solaris 6 */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|INADDR_LOOPBACK
end_ifndef

begin_define
define|#
directive|define
name|INADDR_LOOPBACK
value|((u_long)0x7f000001)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Types */
end_comment

begin_comment
comment|/* If sys/types.h does not supply intXX_t, supply them ourselves */
end_comment

begin_comment
comment|/* (or die trying) */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|HAVE_U_INT
end_ifndef

begin_typedef
typedef|typedef
name|unsigned
name|int
name|u_int
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|HAVE_INTXX_T
end_ifndef

begin_if
if|#
directive|if
operator|(
name|SIZEOF_CHAR
operator|==
literal|1
operator|)
end_if

begin_typedef
typedef|typedef
name|char
name|int8_t
typedef|;
end_typedef

begin_else
else|#
directive|else
end_else

begin_error
error|#
directive|error
literal|"8 bit int type not found."
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
operator|(
name|SIZEOF_SHORT_INT
operator|==
literal|2
operator|)
end_if

begin_typedef
typedef|typedef
name|short
name|int
name|int16_t
typedef|;
end_typedef

begin_else
else|#
directive|else
end_else

begin_ifdef
ifdef|#
directive|ifdef
name|_UNICOS
end_ifdef

begin_if
if|#
directive|if
operator|(
name|SIZEOF_SHORT_INT
operator|==
literal|4
operator|)
end_if

begin_typedef
typedef|typedef
name|short
name|int16_t
typedef|;
end_typedef

begin_else
else|#
directive|else
end_else

begin_typedef
typedef|typedef
name|long
name|int16_t
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_else
else|#
directive|else
end_else

begin_error
error|#
directive|error
literal|"16 bit int type not found."
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _UNICOS */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
operator|(
name|SIZEOF_INT
operator|==
literal|4
operator|)
end_if

begin_typedef
typedef|typedef
name|int
name|int32_t
typedef|;
end_typedef

begin_else
else|#
directive|else
end_else

begin_ifdef
ifdef|#
directive|ifdef
name|_UNICOS
end_ifdef

begin_typedef
typedef|typedef
name|long
name|int32_t
typedef|;
end_typedef

begin_else
else|#
directive|else
end_else

begin_error
error|#
directive|error
literal|"32 bit int type not found."
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _UNICOS */
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
comment|/* If sys/types.h does not supply u_intXX_t, supply them ourselves */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|HAVE_U_INTXX_T
end_ifndef

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_UINTXX_T
end_ifdef

begin_typedef
typedef|typedef
name|uint8_t
name|u_int8_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|uint16_t
name|u_int16_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|uint32_t
name|u_int32_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|HAVE_U_INTXX_T
value|1
end_define

begin_else
else|#
directive|else
end_else

begin_if
if|#
directive|if
operator|(
name|SIZEOF_CHAR
operator|==
literal|1
operator|)
end_if

begin_typedef
typedef|typedef
name|unsigned
name|char
name|u_int8_t
typedef|;
end_typedef

begin_else
else|#
directive|else
end_else

begin_error
error|#
directive|error
literal|"8 bit int type not found."
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
operator|(
name|SIZEOF_SHORT_INT
operator|==
literal|2
operator|)
end_if

begin_typedef
typedef|typedef
name|unsigned
name|short
name|int
name|u_int16_t
typedef|;
end_typedef

begin_else
else|#
directive|else
end_else

begin_ifdef
ifdef|#
directive|ifdef
name|_UNICOS
end_ifdef

begin_if
if|#
directive|if
operator|(
name|SIZEOF_SHORT_INT
operator|==
literal|4
operator|)
end_if

begin_typedef
typedef|typedef
name|unsigned
name|short
name|u_int16_t
typedef|;
end_typedef

begin_else
else|#
directive|else
end_else

begin_typedef
typedef|typedef
name|unsigned
name|long
name|u_int16_t
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_else
else|#
directive|else
end_else

begin_error
error|#
directive|error
literal|"16 bit int type not found."
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
operator|(
name|SIZEOF_INT
operator|==
literal|4
operator|)
end_if

begin_typedef
typedef|typedef
name|unsigned
name|int
name|u_int32_t
typedef|;
end_typedef

begin_else
else|#
directive|else
end_else

begin_ifdef
ifdef|#
directive|ifdef
name|_UNICOS
end_ifdef

begin_typedef
typedef|typedef
name|unsigned
name|long
name|u_int32_t
typedef|;
end_typedef

begin_else
else|#
directive|else
end_else

begin_error
error|#
directive|error
literal|"32 bit int type not found."
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|__BIT_TYPES_DEFINED__
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* 64-bit types */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|HAVE_INT64_T
end_ifndef

begin_if
if|#
directive|if
operator|(
name|SIZEOF_LONG_INT
operator|==
literal|8
operator|)
end_if

begin_typedef
typedef|typedef
name|long
name|int
name|int64_t
typedef|;
end_typedef

begin_else
else|#
directive|else
end_else

begin_if
if|#
directive|if
operator|(
name|SIZEOF_LONG_LONG_INT
operator|==
literal|8
operator|)
end_if

begin_typedef
typedef|typedef
name|long
name|long
name|int
name|int64_t
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|HAVE_U_INT64_T
end_ifndef

begin_if
if|#
directive|if
operator|(
name|SIZEOF_LONG_INT
operator|==
literal|8
operator|)
end_if

begin_typedef
typedef|typedef
name|unsigned
name|long
name|int
name|u_int64_t
typedef|;
end_typedef

begin_else
else|#
directive|else
end_else

begin_if
if|#
directive|if
operator|(
name|SIZEOF_LONG_LONG_INT
operator|==
literal|8
operator|)
end_if

begin_typedef
typedef|typedef
name|unsigned
name|long
name|long
name|int
name|u_int64_t
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|HAVE_U_CHAR
end_ifndef

begin_typedef
typedef|typedef
name|unsigned
name|char
name|u_char
typedef|;
end_typedef

begin_define
define|#
directive|define
name|HAVE_U_CHAR
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* HAVE_U_CHAR */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|SIZE_T_MAX
end_ifndef

begin_define
define|#
directive|define
name|SIZE_T_MAX
value|ULONG_MAX
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* SIZE_T_MAX */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|HAVE_SIZE_T
end_ifndef

begin_typedef
typedef|typedef
name|unsigned
name|int
name|size_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|HAVE_SIZE_T
end_define

begin_define
define|#
directive|define
name|SIZE_T_MAX
value|UINT_MAX
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* HAVE_SIZE_T */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|HAVE_SSIZE_T
end_ifndef

begin_typedef
typedef|typedef
name|int
name|ssize_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|HAVE_SSIZE_T
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* HAVE_SSIZE_T */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|HAVE_CLOCK_T
end_ifndef

begin_typedef
typedef|typedef
name|long
name|clock_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|HAVE_CLOCK_T
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* HAVE_CLOCK_T */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|HAVE_SA_FAMILY_T
end_ifndef

begin_typedef
typedef|typedef
name|int
name|sa_family_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|HAVE_SA_FAMILY_T
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* HAVE_SA_FAMILY_T */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|HAVE_PID_T
end_ifndef

begin_typedef
typedef|typedef
name|int
name|pid_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|HAVE_PID_T
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* HAVE_PID_T */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|HAVE_SIG_ATOMIC_T
end_ifndef

begin_typedef
typedef|typedef
name|int
name|sig_atomic_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|HAVE_SIG_ATOMIC_T
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* HAVE_SIG_ATOMIC_T */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|HAVE_MODE_T
end_ifndef

begin_typedef
typedef|typedef
name|int
name|mode_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|HAVE_MODE_T
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* HAVE_MODE_T */
end_comment

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|HAVE_SS_FAMILY_IN_SS
argument_list|)
operator|&&
name|defined
argument_list|(
name|HAVE___SS_FAMILY_IN_SS
argument_list|)
end_if

begin_define
define|#
directive|define
name|ss_family
value|__ss_family
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !defined(HAVE_SS_FAMILY_IN_SS)&& defined(HAVE_SA_FAMILY_IN_SS) */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|HAVE_SYS_UN_H
end_ifndef

begin_struct
struct|struct
name|sockaddr_un
block|{
name|short
name|sun_family
decl_stmt|;
comment|/* AF_UNIX */
name|char
name|sun_path
index|[
literal|108
index|]
decl_stmt|;
comment|/* path name (gag) */
block|}
struct|;
end_struct

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* HAVE_SYS_UN_H */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|HAVE_IN_ADDR_T
end_ifndef

begin_typedef
typedef|typedef
name|u_int32_t
name|in_addr_t
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|HAVE_IN_PORT_T
end_ifndef

begin_typedef
typedef|typedef
name|u_int16_t
name|in_port_t
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|BROKEN_SYS_TERMIO_H
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|_STRUCT_WINSIZE
argument_list|)
end_if

begin_define
define|#
directive|define
name|_STRUCT_WINSIZE
end_define

begin_struct
struct|struct
name|winsize
block|{
name|unsigned
name|short
name|ws_row
decl_stmt|;
comment|/* rows, in characters */
name|unsigned
name|short
name|ws_col
decl_stmt|;
comment|/* columns, in character */
name|unsigned
name|short
name|ws_xpixel
decl_stmt|;
comment|/* horizontal size, pixels */
name|unsigned
name|short
name|ws_ypixel
decl_stmt|;
comment|/* vertical size, pixels */
block|}
struct|;
end_struct

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* *-*-nto-qnx does not define this type in the system headers */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|MISSING_FD_MASK
end_ifdef

begin_typedef
typedef|typedef
name|unsigned
name|long
name|int
name|fd_mask
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Paths */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_PATH_BSHELL
end_ifndef

begin_define
define|#
directive|define
name|_PATH_BSHELL
value|"/bin/sh"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|USER_PATH
end_ifdef

begin_ifdef
ifdef|#
directive|ifdef
name|_PATH_STDPATH
end_ifdef

begin_undef
undef|#
directive|undef
name|_PATH_STDPATH
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|_PATH_STDPATH
value|USER_PATH
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|_PATH_STDPATH
end_ifndef

begin_define
define|#
directive|define
name|_PATH_STDPATH
value|"/usr/bin:/bin:/usr/sbin:/sbin"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|SUPERUSER_PATH
end_ifndef

begin_define
define|#
directive|define
name|SUPERUSER_PATH
value|_PATH_STDPATH
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|_PATH_DEVNULL
end_ifndef

begin_define
define|#
directive|define
name|_PATH_DEVNULL
value|"/dev/null"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|MAIL_DIRECTORY
end_ifndef

begin_define
define|#
directive|define
name|MAIL_DIRECTORY
value|"/var/spool/mail"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|MAILDIR
end_ifndef

begin_define
define|#
directive|define
name|MAILDIR
value|MAIL_DIRECTORY
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|_PATH_MAILDIR
argument_list|)
operator|&&
name|defined
argument_list|(
name|MAILDIR
argument_list|)
end_if

begin_define
define|#
directive|define
name|_PATH_MAILDIR
value|MAILDIR
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !defined(_PATH_MAILDIR)&& defined(MAILDIR) */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_PATH_NOLOGIN
end_ifndef

begin_define
define|#
directive|define
name|_PATH_NOLOGIN
value|"/etc/nologin"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Define this to be the path of the xauth program. */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|XAUTH_PATH
end_ifdef

begin_define
define|#
directive|define
name|_PATH_XAUTH
value|XAUTH_PATH
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* XAUTH_PATH */
end_comment

begin_comment
comment|/* derived from XF4/xc/lib/dps/Xlibnet.h */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|X_UNIX_PATH
end_ifndef

begin_ifdef
ifdef|#
directive|ifdef
name|__hpux
end_ifdef

begin_define
define|#
directive|define
name|X_UNIX_PATH
value|"/var/spool/sockets/X11/%u"
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|X_UNIX_PATH
value|"/tmp/.X11-unix/X%u"
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
comment|/* X_UNIX_PATH */
end_comment

begin_define
define|#
directive|define
name|_PATH_UNIX_X
value|X_UNIX_PATH
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|_PATH_TTY
end_ifndef

begin_define
define|#
directive|define
name|_PATH_TTY
value|"/dev/tty"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Macros */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|HAVE_LOGIN_GETCAPBOOL
argument_list|)
operator|&&
name|defined
argument_list|(
name|HAVE_LOGIN_CAP_H
argument_list|)
end_if

begin_define
define|#
directive|define
name|HAVE_LOGIN_CAP
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

begin_define
define|#
directive|define
name|MAX
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|(((a)>(b))?(a):(b))
end_define

begin_define
define|#
directive|define
name|MIN
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|(((a)<(b))?(a):(b))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|roundup
end_ifndef

begin_define
define|#
directive|define
name|roundup
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
value|((((x)+((y)-1))/(y))*(y))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|timersub
end_ifndef

begin_define
define|#
directive|define
name|timersub
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|,
name|result
parameter_list|)
define|\
value|do {								\       (result)->tv_sec = (a)->tv_sec - (b)->tv_sec;		\       (result)->tv_usec = (a)->tv_usec - (b)->tv_usec;		\       if ((result)->tv_usec< 0) {				\ 	 --(result)->tv_sec;					\ 	 (result)->tv_usec += 1000000;				\       }								\    } while (0)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|TIMEVAL_TO_TIMESPEC
end_ifndef

begin_define
define|#
directive|define
name|TIMEVAL_TO_TIMESPEC
parameter_list|(
name|tv
parameter_list|,
name|ts
parameter_list|)
value|{					\ 	(ts)->tv_sec = (tv)->tv_sec;					\ 	(ts)->tv_nsec = (tv)->tv_usec * 1000;				\ }
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|TIMESPEC_TO_TIMEVAL
end_ifndef

begin_define
define|#
directive|define
name|TIMESPEC_TO_TIMEVAL
parameter_list|(
name|tv
parameter_list|,
name|ts
parameter_list|)
value|{					\ 	(tv)->tv_sec = (ts)->tv_sec;					\ 	(tv)->tv_usec = (ts)->tv_nsec / 1000;				\ }
end_define

begin_endif
endif|#
directive|endif
end_endif

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

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|IN6_IS_ADDR_V4MAPPED
argument_list|)
end_if

begin_define
define|#
directive|define
name|IN6_IS_ADDR_V4MAPPED
parameter_list|(
name|a
parameter_list|)
define|\
value|((((u_int32_t *) (a))[0] == 0)&& (((u_int32_t *) (a))[1] == 0)&& \ 	 (((u_int32_t *) (a))[2] == htonl (0xffff)))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !defined(IN6_IS_ADDR_V4MAPPED) */
end_comment

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|__GNUC__
argument_list|)
operator|||
operator|(
name|__GNUC__
operator|<
literal|2
operator|)
end_if

begin_define
define|#
directive|define
name|__attribute__
parameter_list|(
name|x
parameter_list|)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !defined(__GNUC__) || (__GNUC__< 2) */
end_comment

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|HAVE_ATTRIBUTE__SENTINEL__
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|__sentinel__
argument_list|)
end_if

begin_define
define|#
directive|define
name|__sentinel__
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|HAVE_ATTRIBUTE__BOUNDED__
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|__bounded__
argument_list|)
end_if

begin_define
define|#
directive|define
name|__bounded__
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|,
name|z
parameter_list|)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|HAVE_ATTRIBUTE__NONNULL__
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|__nonnull__
argument_list|)
end_if

begin_define
define|#
directive|define
name|__nonnull__
parameter_list|(
name|x
parameter_list|)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* *-*-nto-qnx doesn't define this macro in the system headers */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|MISSING_HOWMANY
end_ifdef

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

begin_ifndef
ifndef|#
directive|ifndef
name|OSSH_ALIGNBYTES
end_ifndef

begin_define
define|#
directive|define
name|OSSH_ALIGNBYTES
value|(sizeof(int) - 1)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|__CMSG_ALIGN
end_ifndef

begin_define
define|#
directive|define
name|__CMSG_ALIGN
parameter_list|(
name|p
parameter_list|)
value|(((u_int)(p) + OSSH_ALIGNBYTES)&~ OSSH_ALIGNBYTES)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Length of the contents of a control message of length len */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|CMSG_LEN
end_ifndef

begin_define
define|#
directive|define
name|CMSG_LEN
parameter_list|(
name|len
parameter_list|)
value|(__CMSG_ALIGN(sizeof(struct cmsghdr)) + (len))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Length of the space taken up by a padded control message of length len */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|CMSG_SPACE
end_ifndef

begin_define
define|#
directive|define
name|CMSG_SPACE
parameter_list|(
name|len
parameter_list|)
value|(__CMSG_ALIGN(sizeof(struct cmsghdr)) + __CMSG_ALIGN(len))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* given pointer to struct cmsghdr, return pointer to data */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|CMSG_DATA
end_ifndef

begin_define
define|#
directive|define
name|CMSG_DATA
parameter_list|(
name|cmsg
parameter_list|)
value|((u_char *)(cmsg) + __CMSG_ALIGN(sizeof(struct cmsghdr)))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* CMSG_DATA */
end_comment

begin_comment
comment|/*  * RFC 2292 requires to check msg_controllen, in case that the kernel returns  * an empty list for some reasons.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|CMSG_FIRSTHDR
end_ifndef

begin_define
define|#
directive|define
name|CMSG_FIRSTHDR
parameter_list|(
name|mhdr
parameter_list|)
define|\
value|((mhdr)->msg_controllen>= sizeof(struct cmsghdr) ? \ 	 (struct cmsghdr *)(mhdr)->msg_control : \ 	 (struct cmsghdr *)NULL)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* CMSG_FIRSTHDR */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|HAVE_DECL_OFFSETOF
argument_list|)
operator|&&
name|HAVE_DECL_OFFSETOF
operator|==
literal|0
end_if

begin_define
define|#
directive|define
name|offsetof
parameter_list|(
name|type
parameter_list|,
name|member
parameter_list|)
value|((size_t)&((type *)0)->member)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Set up BSD-style BYTE_ORDER definition if it isn't there already */
end_comment

begin_comment
comment|/* XXX: doesn't try to cope with strange byte orders (PDP_ENDIAN) */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|BYTE_ORDER
end_ifndef

begin_ifndef
ifndef|#
directive|ifndef
name|LITTLE_ENDIAN
end_ifndef

begin_define
define|#
directive|define
name|LITTLE_ENDIAN
value|1234
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* LITTLE_ENDIAN */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|BIG_ENDIAN
end_ifndef

begin_define
define|#
directive|define
name|BIG_ENDIAN
value|4321
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* BIG_ENDIAN */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|WORDS_BIGENDIAN
end_ifdef

begin_define
define|#
directive|define
name|BYTE_ORDER
value|BIG_ENDIAN
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* WORDS_BIGENDIAN */
end_comment

begin_define
define|#
directive|define
name|BYTE_ORDER
value|LITTLE_ENDIAN
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* WORDS_BIGENDIAN */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* BYTE_ORDER */
end_comment

begin_comment
comment|/* Function replacement / compatibility hacks */
end_comment

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|HAVE_GETADDRINFO
argument_list|)
operator|&&
operator|(
name|defined
argument_list|(
name|HAVE_OGETADDRINFO
argument_list|)
operator|||
name|defined
argument_list|(
name|HAVE_NGETADDRINFO
argument_list|)
operator|)
end_if

begin_define
define|#
directive|define
name|HAVE_GETADDRINFO
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|HAVE_GETOPT_OPTRESET
end_ifndef

begin_undef
undef|#
directive|undef
name|getopt
end_undef

begin_undef
undef|#
directive|undef
name|opterr
end_undef

begin_undef
undef|#
directive|undef
name|optind
end_undef

begin_undef
undef|#
directive|undef
name|optopt
end_undef

begin_undef
undef|#
directive|undef
name|optreset
end_undef

begin_undef
undef|#
directive|undef
name|optarg
end_undef

begin_define
define|#
directive|define
name|getopt
parameter_list|(
name|ac
parameter_list|,
name|av
parameter_list|,
name|o
parameter_list|)
value|BSDgetopt(ac, av, o)
end_define

begin_define
define|#
directive|define
name|opterr
value|BSDopterr
end_define

begin_define
define|#
directive|define
name|optind
value|BSDoptind
end_define

begin_define
define|#
directive|define
name|optopt
value|BSDoptopt
end_define

begin_define
define|#
directive|define
name|optreset
value|BSDoptreset
end_define

begin_define
define|#
directive|define
name|optarg
value|BSDoptarg
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
name|BROKEN_GETADDRINFO
argument_list|)
operator|&&
name|defined
argument_list|(
name|HAVE_GETADDRINFO
argument_list|)
end_if

begin_undef
undef|#
directive|undef
name|HAVE_GETADDRINFO
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|BROKEN_GETADDRINFO
argument_list|)
operator|&&
name|defined
argument_list|(
name|HAVE_FREEADDRINFO
argument_list|)
end_if

begin_undef
undef|#
directive|undef
name|HAVE_FREEADDRINFO
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|BROKEN_GETADDRINFO
argument_list|)
operator|&&
name|defined
argument_list|(
name|HAVE_GAI_STRERROR
argument_list|)
end_if

begin_undef
undef|#
directive|undef
name|HAVE_GAI_STRERROR
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|BROKEN_UPDWTMPX
argument_list|)
operator|&&
name|defined
argument_list|(
name|HAVE_UPDWTMPX
argument_list|)
end_if

begin_undef
undef|#
directive|undef
name|HAVE_UPDWTMPX
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|BROKEN_SHADOW_EXPIRE
argument_list|)
operator|&&
name|defined
argument_list|(
name|HAS_SHADOW_EXPIRE
argument_list|)
end_if

begin_undef
undef|#
directive|undef
name|HAS_SHADOW_EXPIRE
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|HAVE_OPENLOG_R
argument_list|)
operator|&&
name|defined
argument_list|(
name|SYSLOG_DATA_INIT
argument_list|)
operator|&&
expr|\
name|defined
argument_list|(
name|SYSLOG_R_SAFE_IN_SIGHAND
argument_list|)
end_if

begin_define
define|#
directive|define
name|DO_LOG_SAFE_IN_SIGHAND
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|HAVE_MEMMOVE
argument_list|)
operator|&&
name|defined
argument_list|(
name|HAVE_BCOPY
argument_list|)
end_if

begin_define
define|#
directive|define
name|memmove
parameter_list|(
name|s1
parameter_list|,
name|s2
parameter_list|,
name|n
parameter_list|)
value|bcopy((s2), (s1), (n))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !defined(HAVE_MEMMOVE)&& defined(HAVE_BCOPY) */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|HAVE_VHANGUP
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|HAVE_DEV_PTMX
argument_list|)
end_if

begin_define
define|#
directive|define
name|USE_VHANGUP
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* defined(HAVE_VHANGUP)&& !defined(HAVE_DEV_PTMX) */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|GETPGRP_VOID
end_ifndef

begin_include
include|#
directive|include
file|<unistd.h>
end_include

begin_define
define|#
directive|define
name|getpgrp
parameter_list|()
value|getpgrp(0)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|USE_BSM_AUDIT
end_ifdef

begin_define
define|#
directive|define
name|SSH_AUDIT_EVENTS
end_define

begin_define
define|#
directive|define
name|CUSTOM_SSH_AUDIT_EVENTS
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|HAVE___func__
argument_list|)
operator|&&
name|defined
argument_list|(
name|HAVE___FUNCTION__
argument_list|)
end_if

begin_define
define|#
directive|define
name|__func__
value|__FUNCTION__
end_define

begin_elif
elif|#
directive|elif
operator|!
name|defined
argument_list|(
name|HAVE___func__
argument_list|)
end_elif

begin_define
define|#
directive|define
name|__func__
value|""
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
name|KRB5
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|HEIMDAL
argument_list|)
end_if

begin_define
define|#
directive|define
name|krb5_get_err_text
parameter_list|(
name|context
parameter_list|,
name|code
parameter_list|)
value|error_message(code)
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
name|SKEYCHALLENGE_4ARG
argument_list|)
end_if

begin_define
define|#
directive|define
name|_compat_skeychallenge
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|,
name|c
parameter_list|,
name|d
parameter_list|)
value|skeychallenge(a,b,c,d)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|_compat_skeychallenge
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|,
name|c
parameter_list|,
name|d
parameter_list|)
value|skeychallenge(a,b,c)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Maximum number of file descriptors available */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_SYSCONF
end_ifdef

begin_define
define|#
directive|define
name|SSH_SYSFDMAX
value|sysconf(_SC_OPEN_MAX)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|SSH_SYSFDMAX
value|10000
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|FSID_HAS_VAL
end_ifdef

begin_comment
comment|/* encode f_fsid into a 64 bit value  */
end_comment

begin_define
define|#
directive|define
name|FSID_TO_ULONG
parameter_list|(
name|f
parameter_list|)
define|\
value|((((u_int64_t)(f).val[0]& 0xffffffffUL)<< 32) | \ 	    ((f).val[1]& 0xffffffffUL))
end_define

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|FSID_HAS___VAL
argument_list|)
end_elif

begin_define
define|#
directive|define
name|FSID_TO_ULONG
parameter_list|(
name|f
parameter_list|)
define|\
value|((((u_int64_t)(f).__val[0]& 0xffffffffUL)<< 32) | \ 	    ((f).__val[1]& 0xffffffffUL))
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|FSID_TO_ULONG
parameter_list|(
name|f
parameter_list|)
value|((f))
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
name|__Lynx__
argument_list|)
end_if

begin_comment
comment|/*   * LynxOS defines these in param.h which we do not want to include since   * it will also pull in a bunch of kernel definitions.   */
end_comment

begin_define
define|#
directive|define
name|ALIGNBYTES
value|(sizeof(int) - 1)
end_define

begin_define
define|#
directive|define
name|ALIGN
parameter_list|(
name|p
parameter_list|)
value|(((unsigned)p + ALIGNBYTES)& ~ALIGNBYTES)
end_define

begin_comment
comment|/* Missing prototypes on LynxOS */
end_comment

begin_function_decl
name|int
name|snprintf
parameter_list|(
name|char
modifier|*
parameter_list|,
name|size_t
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
modifier|...
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|mkstemp
parameter_list|(
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|crypt
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|seteuid
parameter_list|(
name|uid_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|setegid
parameter_list|(
name|gid_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|mkdtemp
parameter_list|(
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|rresvport_af
parameter_list|(
name|int
modifier|*
parameter_list|,
name|sa_family_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|innetgr
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * Define this to use pipes instead of socketpairs for communicating with the  * client program.  Socketpairs do not seem to work on all systems.  *  * configure.ac sets this for a few OS's which are known to have problems  * but you may need to set it yourself  */
end_comment

begin_comment
comment|/* #define USE_PIPES 1 */
end_comment

begin_comment
comment|/**  ** login recorder definitions  **/
end_comment

begin_comment
comment|/* FIXME: put default paths back in */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|UTMP_FILE
end_ifndef

begin_ifdef
ifdef|#
directive|ifdef
name|_PATH_UTMP
end_ifdef

begin_define
define|#
directive|define
name|UTMP_FILE
value|_PATH_UTMP
end_define

begin_else
else|#
directive|else
end_else

begin_ifdef
ifdef|#
directive|ifdef
name|CONF_UTMP_FILE
end_ifdef

begin_define
define|#
directive|define
name|UTMP_FILE
value|CONF_UTMP_FILE
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|WTMP_FILE
end_ifndef

begin_ifdef
ifdef|#
directive|ifdef
name|_PATH_WTMP
end_ifdef

begin_define
define|#
directive|define
name|WTMP_FILE
value|_PATH_WTMP
end_define

begin_else
else|#
directive|else
end_else

begin_ifdef
ifdef|#
directive|ifdef
name|CONF_WTMP_FILE
end_ifdef

begin_define
define|#
directive|define
name|WTMP_FILE
value|CONF_WTMP_FILE
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* pick up the user's location for lastlog if given */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|LASTLOG_FILE
end_ifndef

begin_ifdef
ifdef|#
directive|ifdef
name|_PATH_LASTLOG
end_ifdef

begin_define
define|#
directive|define
name|LASTLOG_FILE
value|_PATH_LASTLOG
end_define

begin_else
else|#
directive|else
end_else

begin_ifdef
ifdef|#
directive|ifdef
name|CONF_LASTLOG_FILE
end_ifdef

begin_define
define|#
directive|define
name|LASTLOG_FILE
value|CONF_LASTLOG_FILE
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|HAVE_SHADOW_H
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|DISABLE_SHADOW
argument_list|)
end_if

begin_define
define|#
directive|define
name|USE_SHADOW
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* The login() library function in libutil is first choice */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|HAVE_LOGIN
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|DISABLE_LOGIN
argument_list|)
end_if

begin_define
define|#
directive|define
name|USE_LOGIN
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* Simply select your favourite login types. */
end_comment

begin_comment
comment|/* Can't do if-else because some systems use several...<sigh> */
end_comment

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|DISABLE_UTMPX
argument_list|)
end_if

begin_define
define|#
directive|define
name|USE_UTMPX
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
name|UTMP_FILE
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|DISABLE_UTMP
argument_list|)
end_if

begin_define
define|#
directive|define
name|USE_UTMP
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
name|WTMPX_FILE
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|DISABLE_WTMPX
argument_list|)
end_if

begin_define
define|#
directive|define
name|USE_WTMPX
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
name|WTMP_FILE
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|DISABLE_WTMP
argument_list|)
end_if

begin_define
define|#
directive|define
name|USE_WTMP
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|UT_LINESIZE
end_ifndef

begin_define
define|#
directive|define
name|UT_LINESIZE
value|8
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* I hope that the presence of LASTLOG_FILE is enough to detect this */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|LASTLOG_FILE
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|DISABLE_LASTLOG
argument_list|)
end_if

begin_define
define|#
directive|define
name|USE_LASTLOG
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_OSF_SIA
end_ifdef

begin_ifdef
ifdef|#
directive|ifdef
name|USE_SHADOW
end_ifdef

begin_undef
undef|#
directive|undef
name|USE_SHADOW
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|CUSTOM_SYS_AUTH_PASSWD
value|1
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
name|HAVE_LIBIAF
argument_list|)
operator|&&
name|defined
argument_list|(
name|HAVE_SET_ID
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|HAVE_SECUREWARE
argument_list|)
end_if

begin_define
define|#
directive|define
name|CUSTOM_SYS_AUTH_PASSWD
value|1
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
name|HAVE_LIBIAF
argument_list|)
operator|&&
name|defined
argument_list|(
name|HAVE_SET_ID
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|BROKEN_LIBIAF
argument_list|)
end_if

begin_define
define|#
directive|define
name|USE_LIBIAF
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* HP-UX 11.11 */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|BTMP_FILE
end_ifdef

begin_define
define|#
directive|define
name|_PATH_BTMP
value|BTMP_FILE
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
name|USE_BTMP
argument_list|)
operator|&&
name|defined
argument_list|(
name|_PATH_BTMP
argument_list|)
end_if

begin_define
define|#
directive|define
name|CUSTOM_FAILED_LOGIN
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/** end of login recorder definitions */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|BROKEN_GETGROUPS
end_ifdef

begin_define
define|#
directive|define
name|getgroups
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|((a)==0&& (b)==NULL ? NGROUPS_MAX : getgroups((a),(b)))
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
name|HAVE_MMAP
argument_list|)
operator|&&
name|defined
argument_list|(
name|BROKEN_MMAP
argument_list|)
end_if

begin_undef
undef|#
directive|undef
name|HAVE_MMAP
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|IOV_MAX
end_ifndef

begin_if
if|#
directive|if
name|defined
argument_list|(
name|_XOPEN_IOV_MAX
argument_list|)
end_if

begin_define
define|#
directive|define
name|IOV_MAX
value|_XOPEN_IOV_MAX
end_define

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|DEF_IOV_MAX
argument_list|)
end_elif

begin_define
define|#
directive|define
name|IOV_MAX
value|DEF_IOV_MAX
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|IOV_MAX
value|16
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|EWOULDBLOCK
end_ifndef

begin_define
define|#
directive|define
name|EWOULDBLOCK
value|EAGAIN
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|INET6_ADDRSTRLEN
end_ifndef

begin_comment
comment|/* for non IPv6 machines */
end_comment

begin_define
define|#
directive|define
name|INET6_ADDRSTRLEN
value|46
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|SSH_IOBUFSZ
end_ifndef

begin_define
define|#
directive|define
name|SSH_IOBUFSZ
value|8192
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
comment|/* _DEFINES_H */
end_comment

end_unit

