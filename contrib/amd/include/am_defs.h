begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1997-1999 Erez Zadok  * Copyright (c) 1990 Jan-Simon Pendry  * Copyright (c) 1990 Imperial College of Science, Technology& Medicine  * Copyright (c) 1990 The Regents of the University of California.  * All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * Jan-Simon Pendry at Imperial College, London.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgment:  *      This product includes software developed by the University of  *      California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *      %W% (Berkeley) %G%  *  * $Id: am_defs.h,v 1.11 1999/09/18 08:38:05 ezk Exp $  * $FreeBSD$  *  */
end_comment

begin_comment
comment|/*  * Definitions that are not specific to the am-utils package, but  * are rather generic, and can be used elsewhere.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_AM_DEFS_H
end_ifndef

begin_define
define|#
directive|define
name|_AM_DEFS_H
end_define

begin_comment
comment|/*  * Actions to take if ANSI C.  */
end_comment

begin_if
if|#
directive|if
name|STDC_HEADERS
end_if

begin_include
include|#
directive|include
file|<string.h>
end_include

begin_comment
comment|/* for function prototypes */
end_comment

begin_define
define|#
directive|define
name|P
parameter_list|(
name|x
parameter_list|)
value|x
end_define

begin_define
define|#
directive|define
name|P_void
value|void
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* not STDC_HEADERS */
end_comment

begin_comment
comment|/* empty function prototypes */
end_comment

begin_define
define|#
directive|define
name|P
parameter_list|(
name|x
parameter_list|)
value|()
end_define

begin_define
define|#
directive|define
name|P_void
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|HAVE_STRCHR
end_ifndef

begin_define
define|#
directive|define
name|strchr
value|index
end_define

begin_define
define|#
directive|define
name|strrchr
value|rindex
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* not HAVE_STRCHR */
end_comment

begin_decl_stmt
name|char
modifier|*
name|strchr
argument_list|()
decl_stmt|,
modifier|*
name|strrchr
argument_list|()
decl_stmt|,
modifier|*
name|strdup
argument_list|()
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* not STDC_HEADERS */
end_comment

begin_comment
comment|/*  * Handle gcc __attribute__ if available.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__attribute__
end_ifndef

begin_comment
comment|/* This feature is available in gcc versions 2.5 and later.  */
end_comment

begin_if
if|#
directive|if
name|__GNUC__
operator|<
literal|2
operator|||
operator|(
name|__GNUC__
operator|==
literal|2
operator|&&
name|__GNUC_MINOR__
operator|<
literal|5
operator|)
operator|||
name|__STRICT_ANSI__
end_if

begin_define
define|#
directive|define
name|__attribute__
parameter_list|(
name|Spec
parameter_list|)
end_define

begin_comment
comment|/* empty */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __GNUC__< 2 ... */
end_comment

begin_comment
comment|/*  * The __-protected variants of `format' and `printf' attributes  * are accepted by gcc versions 2.6.4 (effectively 2.7) and later.  */
end_comment

begin_if
if|#
directive|if
name|__GNUC__
operator|<
literal|2
operator|||
operator|(
name|__GNUC__
operator|==
literal|2
operator|&&
name|__GNUC_MINOR__
operator|<
literal|7
operator|)
end_if

begin_define
define|#
directive|define
name|__format__
value|format
end_define

begin_define
define|#
directive|define
name|__printf__
value|printf
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __GNUC__< 2 ... */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* not __attribute__ */
end_comment

begin_comment
comment|/*  * How to handle signals of any type  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_SYS_WAIT_H
end_ifdef

begin_include
include|#
directive|include
file|<sys/wait.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* HAVE_SYS_WAIT_H */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|WEXITSTATUS
end_ifndef

begin_define
define|#
directive|define
name|WEXITSTATUS
parameter_list|(
name|stat_val
parameter_list|)
value|((unsigned)(stat_val)>> 8)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* not WEXITSTATUS */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|WIFEXITED
end_ifndef

begin_define
define|#
directive|define
name|WIFEXITED
parameter_list|(
name|stat_val
parameter_list|)
value|(((stat_val)& 255) == 0)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* not WIFEXITED */
end_comment

begin_comment
comment|/*  * Actions to take regarding<time.h> and<sys/time.h>.  */
end_comment

begin_if
if|#
directive|if
name|TIME_WITH_SYS_TIME
end_if

begin_include
include|#
directive|include
file|<sys/time.h>
end_include

begin_include
include|#
directive|include
file|<time.h>
end_include

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* not TIME_WITH_SYS_TIME */
end_comment

begin_if
if|#
directive|if
name|HAVE_SYS_TIME_H
end_if

begin_include
include|#
directive|include
file|<sys/time.h>
end_include

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* not HAVE_SYS_TIME_H */
end_comment

begin_include
include|#
directive|include
file|<time.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* not HAVE_SYS_TIME_H */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* not TIME_WITH_SYS_TIME */
end_comment

begin_comment
comment|/*  * Actions to take if<machine/endian.h> exists.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_MACHINE_ENDIAN_H
end_ifdef

begin_include
include|#
directive|include
file|<machine/endian.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* HAVE_MACHINE_ENDIAN_H */
end_comment

begin_comment
comment|/*  * Big-endian or little-endian?  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|WORDS_BIGENDIAN
end_ifdef

begin_define
define|#
directive|define
name|ARCH_ENDIAN
value|"big"
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* not WORDS_BIGENDIAN */
end_comment

begin_define
define|#
directive|define
name|ARCH_ENDIAN
value|"little"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* not WORDS_BIGENDIAN */
end_comment

begin_comment
comment|/*  * Actions to take if HAVE_SYS_TYPES_H is defined.  */
end_comment

begin_if
if|#
directive|if
name|HAVE_SYS_TYPES_H
end_if

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* HAVE_SYS_TYPES_H */
end_comment

begin_comment
comment|/*  * Actions to take if HAVE_UNISTD_H is defined.  */
end_comment

begin_if
if|#
directive|if
name|HAVE_UNISTD_H
end_if

begin_include
include|#
directive|include
file|<unistd.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* HAVE_UNISTD_H */
end_comment

begin_comment
comment|/* after<unistd.h>, check if this is a POSIX.1 system */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|_POSIX_VERSION
end_ifdef

begin_comment
comment|/* Code for POSIX.1 systems. */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _POSIX_VERSION */
end_comment

begin_comment
comment|/*  * Variable length argument lists.  * Must use only one of the two!  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_STDARG_H
end_ifdef

begin_include
include|#
directive|include
file|<stdarg.h>
end_include

begin_comment
comment|/*  * On Solaris 2.6,<sys/varargs.h> is included in<sys/fs/autofs.h>  * So this ensures that only one is included.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_SYS_VARARGS_H
end_ifndef

begin_define
define|#
directive|define
name|_SYS_VARARGS_H
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* not _SYS_VARARGS_H */
end_comment

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* not HAVE_STDARG_H */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_VARARGS_H
end_ifdef

begin_include
include|#
directive|include
file|<varargs.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* HAVE_VARARGS_H */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* not HAVE_STDARG_H */
end_comment

begin_comment
comment|/*  * Pick the right header file and macros for directory processing functions.  */
end_comment

begin_if
if|#
directive|if
name|HAVE_DIRENT_H
end_if

begin_include
include|#
directive|include
file|<dirent.h>
end_include

begin_define
define|#
directive|define
name|NAMLEN
parameter_list|(
name|dirent
parameter_list|)
value|strlen((dirent)->d_name)
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* not HAVE_DIRENT_H */
end_comment

begin_define
define|#
directive|define
name|dirent
value|direct
end_define

begin_define
define|#
directive|define
name|NAMLEN
parameter_list|(
name|dirent
parameter_list|)
value|(dirent)->d_namlen
end_define

begin_if
if|#
directive|if
name|HAVE_SYS_NDIR_H
end_if

begin_include
include|#
directive|include
file|<sys/ndir.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* HAVE_SYS_NDIR_H */
end_comment

begin_if
if|#
directive|if
name|HAVE_SYS_DIR_H
end_if

begin_include
include|#
directive|include
file|<sys/dir.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* HAVE_SYS_DIR_H */
end_comment

begin_if
if|#
directive|if
name|HAVE_NDIR_H
end_if

begin_include
include|#
directive|include
file|<ndir.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* HAVE_NDIR_H */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* not HAVE_DIRENT_H */
end_comment

begin_comment
comment|/*  * Actions to take if HAVE_FCNTL_H is defined.  */
end_comment

begin_if
if|#
directive|if
name|HAVE_FCNTL_H
end_if

begin_include
include|#
directive|include
file|<fcntl.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* HAVE_FCNTL_H */
end_comment

begin_comment
comment|/*  * Actions to take if HAVE_MEMORY_H is defined.  */
end_comment

begin_if
if|#
directive|if
name|HAVE_MEMORY_H
end_if

begin_include
include|#
directive|include
file|<memory.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* HAVE_MEMORY_H */
end_comment

begin_comment
comment|/*  * Actions to take if HAVE_SYS_FILE_H is defined.  */
end_comment

begin_if
if|#
directive|if
name|HAVE_SYS_FILE_H
end_if

begin_include
include|#
directive|include
file|<sys/file.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* HAVE_SYS_FILE_H */
end_comment

begin_comment
comment|/*  * Actions to take if HAVE_SYS_IOCTL_H is defined.  */
end_comment

begin_if
if|#
directive|if
name|HAVE_SYS_IOCTL_H
end_if

begin_include
include|#
directive|include
file|<sys/ioctl.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* HAVE_SYS_IOCTL_H */
end_comment

begin_comment
comment|/*  * Actions to take if HAVE_SYSLOG_H or HAVE_SYS_SYSLOG_H is defined.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_SYSLOG_H
end_ifdef

begin_include
include|#
directive|include
file|<syslog.h>
end_include

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* not HAVE_SYSLOG_H */
end_comment

begin_if
if|#
directive|if
name|HAVE_SYS_SYSLOG_H
end_if

begin_include
include|#
directive|include
file|<sys/syslog.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* HAVE_SYS_SYSLOG_H */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* HAVE_SYSLOG_H */
end_comment

begin_comment
comment|/*  * Actions to take if<sys/param.h> exists.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_SYS_PARAM_H
end_ifdef

begin_include
include|#
directive|include
file|<sys/param.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* HAVE_SYS_PARAM_H */
end_comment

begin_comment
comment|/*  * Actions to take if<sys/socket.h> exists.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_SYS_SOCKET_H
end_ifdef

begin_include
include|#
directive|include
file|<sys/socket.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* HAVE_SYS_SOCKET_H */
end_comment

begin_comment
comment|/*  * Actions to take if<rpc/rpc.h> exists.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_RPC_RPC_H
end_ifdef

begin_comment
comment|/*  * Turn on PORTMAP, so that additional header files would get included  * and the important definition for UDPMSGSIZE is included too.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|PORTMAP
end_ifndef

begin_define
define|#
directive|define
name|PORTMAP
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* not PORTMAP */
end_comment

begin_include
include|#
directive|include
file|<rpc/rpc.h>
end_include

begin_ifndef
ifndef|#
directive|ifndef
name|XDRPROC_T_TYPE
end_ifndef

begin_typedef
typedef|typedef
name|bool_t
argument_list|(
argument|*xdrproc_t
argument_list|)
name|__P
argument_list|(
operator|(
name|XDR
operator|*
operator|,
name|__ptr_t
operator|,
operator|...
operator|)
argument_list|)
expr_stmt|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* not XDRPROC_T_TYPE */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* HAVE_RPC_RPC_H */
end_comment

begin_comment
comment|/*  * Actions to take if<rpc/types.h> exists.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_RPC_TYPES_H
end_ifdef

begin_include
include|#
directive|include
file|<rpc/types.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* HAVE_RPC_TYPES_H */
end_comment

begin_comment
comment|/*  * Actions to take if<rpc/xdr.h> exists.  */
end_comment

begin_comment
comment|/* Prevent multiple inclusion on Ultrix 4 */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|HAVE_RPC_XDR_H
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|__XDR_HEADER__
argument_list|)
end_if

begin_include
include|#
directive|include
file|<rpc/xdr.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* defined(HAVE_RPC_XDR_H)&& !defined(__XDR_HEADER__) */
end_comment

begin_comment
comment|/*  * Actions to take if<malloc.h> exists.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_MALLOC_H
end_ifdef

begin_include
include|#
directive|include
file|<malloc.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* HAVE_MALLOC_H */
end_comment

begin_comment
comment|/*  * Actions to take if<mntent.h> exists.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_MNTENT_H
end_ifdef

begin_comment
comment|/* some systems need<stdio.h> before<mntent.h> is included */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_STDIO_H
end_ifdef

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* HAVE_STDIO_H */
end_comment

begin_include
include|#
directive|include
file|<mntent.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* HAVE_MNTENT_H */
end_comment

begin_comment
comment|/*  * Actions to take if<sys/errno.h> exists.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_SYS_ERRNO_H
end_ifdef

begin_include
include|#
directive|include
file|<sys/errno.h>
end_include

begin_decl_stmt
specifier|extern
name|int
name|errno
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* HAVE_SYS_ERRNO_H */
end_comment

begin_comment
comment|/*  * Actions to take if<sys/fsid.h> exists.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_SYS_FSID_H
end_ifdef

begin_include
include|#
directive|include
file|<sys/fsid.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* HAVE_SYS_FSID_H */
end_comment

begin_comment
comment|/*  * Actions to take if<sys/utsname.h> exists.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_SYS_UTSNAME_H
end_ifdef

begin_include
include|#
directive|include
file|<sys/utsname.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* HAVE_SYS_UTSNAME_H */
end_comment

begin_comment
comment|/*  * Actions to take if<sys/mntent.h> exists.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_SYS_MNTENT_H
end_ifdef

begin_include
include|#
directive|include
file|<sys/mntent.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* HAVE_SYS_MNTENT_H */
end_comment

begin_comment
comment|/*  * Actions to take if<ndbm.h> or<db1/ndbm.h> exist.  * Should be included before<rpcsvc/yp_prot.h> because on some systems  * like Linux, it also defines "struct datum".  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_NDBM_H
end_ifdef

begin_include
include|#
directive|include
file|<ndbm.h>
end_include

begin_ifndef
ifndef|#
directive|ifndef
name|DATUM
end_ifndef

begin_comment
comment|/* ensure that struct datum is not included again from<rpcsvc/yp_prot.h> */
end_comment

begin_define
define|#
directive|define
name|DATUM
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* not DATUM */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* HAVE_NDBM_H */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_DB1_NDBM_H
end_ifdef

begin_include
include|#
directive|include
file|<db1/ndbm.h>
end_include

begin_ifndef
ifndef|#
directive|ifndef
name|DATUM
end_ifndef

begin_comment
comment|/* ensure that struct datum is not included again from<rpcsvc/yp_prot.h> */
end_comment

begin_define
define|#
directive|define
name|DATUM
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* not DATUM */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* HAVE_DB1_NDBM_H */
end_comment

begin_comment
comment|/*  * Actions to take if<net/errno.h> exists.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_NET_ERRNO_H
end_ifdef

begin_include
include|#
directive|include
file|<net/errno.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* HAVE_NET_ERRNO_H */
end_comment

begin_comment
comment|/*  * Actions to take if<net/route.h> exists.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_NET_ROUTE_H
end_ifdef

begin_include
include|#
directive|include
file|<net/route.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* HAVE_NET_ROUTE_H */
end_comment

begin_comment
comment|/*  * Actions to take if<sys/mbuf.h> exists.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_SYS_MBUF_H
end_ifdef

begin_include
include|#
directive|include
file|<sys/mbuf.h>
end_include

begin_comment
comment|/*  * OSF4 (DU-4.0) defines m_next and m_data also in<sys/mount.h> so I must  # undefine them here to avoid conflicts.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|m_next
end_ifdef

begin_undef
undef|#
directive|undef
name|m_next
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* m_next */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|m_data
end_ifdef

begin_undef
undef|#
directive|undef
name|m_data
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* m_data */
end_comment

begin_comment
comment|/*  * AIX 3 defines MFREE and m_flags also in<sys/mount.h>.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|m_flags
end_ifdef

begin_undef
undef|#
directive|undef
name|m_flags
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* m_flags */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|MFREE
end_ifdef

begin_undef
undef|#
directive|undef
name|MFREE
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* MFREE */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* HAVE_SYS_MBUF_H */
end_comment

begin_comment
comment|/*  * Actions to take if<net/if.h> exists.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_NET_IF_H
end_ifdef

begin_include
include|#
directive|include
file|<net/if.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* HAVE_NET_IF_H */
end_comment

begin_comment
comment|/*  * Actions to take if<netdb.h> exists.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_NETDB_H
end_ifdef

begin_include
include|#
directive|include
file|<netdb.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* HAVE_NETDB_H */
end_comment

begin_comment
comment|/*  * Actions to take if<netdir.h> exists.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_NETDIR_H
end_ifdef

begin_include
include|#
directive|include
file|<netdir.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* HAVE_NETDIR_H */
end_comment

begin_comment
comment|/*  * Actions to take if<net/if_var.h> exists.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_NET_IF_VAR_H
end_ifdef

begin_include
include|#
directive|include
file|<net/if_var.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* HAVE_NET_IF_VAR_H */
end_comment

begin_comment
comment|/*  * Actions to take if<netinet/if_ether.h> exists.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_NETINET_IF_ETHER_H
end_ifdef

begin_include
include|#
directive|include
file|<netinet/if_ether.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* HAVE_NETINET_IF_ETHER_H */
end_comment

begin_comment
comment|/*  * Actions to take if<netinet/in.h> exists.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_NETINET_IN_H
end_ifdef

begin_include
include|#
directive|include
file|<netinet/in.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* HAVE_NETINET_IN_H */
end_comment

begin_comment
comment|/*  * Actions to take if<rpcsvc/yp_prot.h> exists.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_RPCSVC_YP_PROT_H
end_ifdef

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_BAD_HEADERS
end_ifdef

begin_comment
comment|/* avoid circular dependency in aix 4.3 with<rpcsvc/ypclnt.h> */
end_comment

begin_struct_decl
struct_decl|struct
name|ypall_callback
struct_decl|;
end_struct_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* HAVE_BAD_HEADERS */
end_comment

begin_include
include|#
directive|include
file|<rpcsvc/yp_prot.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* HAVE_RPCSVC_YP_PROT_H */
end_comment

begin_comment
comment|/*  * Actions to take if<rpcsvc/ypclnt.h> exists.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_RPCSVC_YPCLNT_H
end_ifdef

begin_include
include|#
directive|include
file|<rpcsvc/ypclnt.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* HAVE_RPCSVC_YPCLNT_H */
end_comment

begin_comment
comment|/*  * Actions to take if<sys/ucred.h> exists.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_SYS_UCRED_H
end_ifdef

begin_include
include|#
directive|include
file|<sys/ucred.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* HAVE_SYS_UCRED_H */
end_comment

begin_comment
comment|/*  * Actions to take if<sys/mount.h> exists.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_SYS_MOUNT_H
end_ifdef

begin_comment
comment|/*  * Some operating systems must define these variables to get  * NFS and other definitions included.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|NFSCLIENT
end_ifndef

begin_define
define|#
directive|define
name|NFSCLIENT
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* not NFSCLIENT */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|NFS
end_ifndef

begin_define
define|#
directive|define
name|NFS
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* not NFS */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|PCFS
end_ifndef

begin_define
define|#
directive|define
name|PCFS
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* not PCFS */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|LOFS
end_ifndef

begin_define
define|#
directive|define
name|LOFS
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* not LOFS */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|RFS
end_ifndef

begin_define
define|#
directive|define
name|RFS
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* not RFS */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|MSDOSFS
end_ifndef

begin_define
define|#
directive|define
name|MSDOSFS
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* not MSDOSFS */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|MFS
end_ifndef

begin_define
define|#
directive|define
name|MFS
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* not MFS */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|CD9660
end_ifndef

begin_define
define|#
directive|define
name|CD9660
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* not CD9660 */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|NFS
end_ifndef

begin_define
define|#
directive|define
name|NFS
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* not NFS */
end_comment

begin_include
include|#
directive|include
file|<sys/mount.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* HAVE_SYS_MOUNT_H */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_SYS_VMOUNT_H
end_ifdef

begin_include
include|#
directive|include
file|<sys/vmount.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* HAVE_SYS_VMOUNT_H */
end_comment

begin_comment
comment|/*  * Actions to take if<linux/fs.h> exists.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_LINUX_FS_H
end_ifdef

begin_comment
comment|/*  * There are various conflicts in definitions between RedHat Linux, newer  * 2.2 kernels, and<netinet/in.h> and<linux/fs.h>.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_SOCKETBITS_H
end_ifdef

begin_comment
comment|/* conflicts with<socketbits.h> */
end_comment

begin_define
define|#
directive|define
name|_LINUX_SOCKET_H
end_define

begin_undef
undef|#
directive|undef
name|BLKFLSBUF
end_undef

begin_undef
undef|#
directive|undef
name|BLKGETSIZE
end_undef

begin_undef
undef|#
directive|undef
name|BLKRAGET
end_undef

begin_undef
undef|#
directive|undef
name|BLKRASET
end_undef

begin_undef
undef|#
directive|undef
name|BLKROGET
end_undef

begin_undef
undef|#
directive|undef
name|BLKROSET
end_undef

begin_undef
undef|#
directive|undef
name|BLKRRPART
end_undef

begin_undef
undef|#
directive|undef
name|MS_MGC_VAL
end_undef

begin_undef
undef|#
directive|undef
name|MS_RMT_MASK
end_undef

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__GLIBC__
argument_list|)
operator|&&
name|__GLIBC__
operator|>=
literal|2
end_if

begin_comment
comment|/* conflicts with<waitflags.h> */
end_comment

begin_undef
undef|#
directive|undef
name|WNOHANG
end_undef

begin_undef
undef|#
directive|undef
name|WUNTRACED
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* defined(__GLIBC__)&& __GLIBC__>= 2 */
end_comment

begin_comment
comment|/* conflicts with<statfsbuf.h> */
end_comment

begin_define
define|#
directive|define
name|_SYS_STATFS_H
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* HAVE_SOCKETBITS_H */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|_SYS_WAIT_H
end_ifdef

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__GLIBC__
argument_list|)
operator|&&
name|__GLIBC__
operator|>=
literal|2
end_if

begin_comment
comment|/* conflicts with<bits/waitflags.h> (RedHat/Linux 6.0 and kernels 2.2 */
end_comment

begin_undef
undef|#
directive|undef
name|WNOHANG
end_undef

begin_undef
undef|#
directive|undef
name|WUNTRACED
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* defined(__GLIBC__)&& __GLIBC__>= 2 */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _SYS_WAIT_H */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_LINUX_POSIX_TYPES_H
end_ifdef

begin_include
include|#
directive|include
file|<linux/posix_types.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* HAVE_LINUX_POSIX_TYPES_H */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_LINUX_BYTEORDER_GENERIC_H
end_ifndef

begin_define
define|#
directive|define
name|_LINUX_BYTEORDER_GENERIC_H
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _LINUX_BYTEORDER_GENERIC_H */
end_comment

begin_comment
comment|/* conflicts with<sys/mount.h> in 2.[12] kernels */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|_SYS_MOUNT_H
end_ifdef

begin_undef
undef|#
directive|undef
name|BLKFLSBUF
end_undef

begin_undef
undef|#
directive|undef
name|BLKGETSIZE
end_undef

begin_undef
undef|#
directive|undef
name|BLKRAGET
end_undef

begin_undef
undef|#
directive|undef
name|BLKRASET
end_undef

begin_undef
undef|#
directive|undef
name|BLKROGET
end_undef

begin_undef
undef|#
directive|undef
name|BLKROSET
end_undef

begin_undef
undef|#
directive|undef
name|BLKRRPART
end_undef

begin_undef
undef|#
directive|undef
name|BLOCK_SIZE
end_undef

begin_undef
undef|#
directive|undef
name|MS_MANDLOCK
end_undef

begin_undef
undef|#
directive|undef
name|MS_MGC_VAL
end_undef

begin_undef
undef|#
directive|undef
name|MS_NOATIME
end_undef

begin_undef
undef|#
directive|undef
name|MS_NODEV
end_undef

begin_undef
undef|#
directive|undef
name|MS_NODIRATIME
end_undef

begin_undef
undef|#
directive|undef
name|MS_NOEXEC
end_undef

begin_undef
undef|#
directive|undef
name|MS_NOSUID
end_undef

begin_undef
undef|#
directive|undef
name|MS_RDONLY
end_undef

begin_undef
undef|#
directive|undef
name|MS_REMOUNT
end_undef

begin_undef
undef|#
directive|undef
name|MS_RMT_MASK
end_undef

begin_undef
undef|#
directive|undef
name|MS_SYNCHRONOUS
end_undef

begin_undef
undef|#
directive|undef
name|S_APPEND
end_undef

begin_undef
undef|#
directive|undef
name|S_IMMUTABLE
end_undef

begin_comment
comment|/* conflicts with<statfsbuf.h> */
end_comment

begin_define
define|#
directive|define
name|_SYS_STATFS_H
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _SYS_MOUNT_H */
end_comment

begin_include
include|#
directive|include
file|<linux/fs.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* HAVE_LINUX_FS_H */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_CDFS_CDFS_MOUNT_H
end_ifdef

begin_include
include|#
directive|include
file|<cdfs/cdfs_mount.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* HAVE_CDFS_CDFS_MOUNT_H */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_CDFS_CDFSMOUNT_H
end_ifdef

begin_include
include|#
directive|include
file|<cdfs/cdfsmount.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* HAVE_CDFS_CDFSMOUNT_H */
end_comment

begin_comment
comment|/*  * Actions to take if<linux/auto_fs.h> exists.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_LINUX_AUTO_FS_H
end_ifdef

begin_include
include|#
directive|include
file|<linux/auto_fs.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* HAVE_LINUX_AUTO_FS_H */
end_comment

begin_comment
comment|/*  * Actions to take if<sys/fs/autofs.h> exists.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_SYS_FS_AUTOFS_H
end_ifdef

begin_include
include|#
directive|include
file|<sys/fs/autofs.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* HAVE_SYS_FS_AUTOFS_H */
end_comment

begin_comment
comment|/*  * Actions to take if<sys/fs/autofs_prot.h> exists.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_SYS_FS_AUTOFS_PROT_H
end_ifdef

begin_include
include|#
directive|include
file|<sys/fs/autofs_prot.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* HAVE_SYS_FS_AUTOFS_PROT_H */
end_comment

begin_comment
comment|/*  * NFS PROTOCOL HEADER FILES:  */
end_comment

begin_comment
comment|/*  * Actions to take if<nfs/export.h> exists.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_NFS_EXPORT_H
end_ifdef

begin_include
include|#
directive|include
file|<nfs/export.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* HAVE_NFS_EXPORT_H */
end_comment

begin_comment
comment|/****************************************************************************  ** IMPORTANT!!!							   **  ** We always include am-util's amu_nfs_prot.h.				   **  ** That is actually defined in "conf/nfs_prot/nfs_prot_${host_os_name}.h" **  ****************************************************************************/
end_comment

begin_include
include|#
directive|include
file|<amu_nfs_prot.h>
end_include

begin_comment
comment|/*  * DO NOT INCLUDE THESE FILES:  * They conflicts with other NFS headers and are generally not needed.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|DO_NOT_INCLUDE
end_ifdef

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_NFS_NFS_CLNT_H
end_ifdef

begin_include
include|#
directive|include
file|<nfs/nfs_clnt.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* HAVE_NFS_NFS_CLNT_H */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_LINUX_NFS_H
end_ifdef

begin_include
include|#
directive|include
file|<linux/nfs.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* HAVE_LINUX_NFS_H */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* DO NOT INCLUDE */
end_comment

begin_comment
comment|/*  * Actions to take if one of the nfs headers exists.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_NFS_NFS_GFS_H
end_ifdef

begin_include
include|#
directive|include
file|<nfs/nfs_gfs.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* HAVE_NFS_NFS_GFS_H */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_NFS_MOUNT_H
end_ifdef

begin_include
include|#
directive|include
file|<nfs/mount.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* HAVE_NFS_MOUNT_H */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_NFS_NFS_MOUNT_H_off
end_ifdef

begin_comment
comment|/* broken on nexttep3 (includes non-existing headers) */
end_comment

begin_include
include|#
directive|include
file|<nfs/nfs_mount.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* HAVE_NFS_NFS_MOUNT_H */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_NFS_PATHCONF_H
end_ifdef

begin_include
include|#
directive|include
file|<nfs/pathconf.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* HAVE_NFS_PATHCONF_H */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_SYS_FS_NFS_MOUNT_H
end_ifdef

begin_include
include|#
directive|include
file|<sys/fs/nfs/mount.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* HAVE_SYS_FS_NFS_MOUNT_H */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_SYS_FS_NFS_NFS_CLNT_H
end_ifdef

begin_include
include|#
directive|include
file|<sys/fs/nfs/nfs_clnt.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* HAVE_SYS_FS_NFS_NFS_CLNT_H */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_SYS_FS_NFS_CLNT_H
end_ifdef

begin_include
include|#
directive|include
file|<sys/fs/nfs_clnt.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* HAVE_SYS_FS_NFS_CLNT_H */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_LINUX_NFS_MOUNT_H
end_ifdef

begin_include
include|#
directive|include
file|<linux/nfs_mount.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* HAVE_LINUX_NFS_MOUNT_H */
end_comment

begin_comment
comment|/*  * Actions to take if<pwd.h> exists.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_PWD_H
end_ifdef

begin_include
include|#
directive|include
file|<pwd.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* HAVE_PWD_H */
end_comment

begin_comment
comment|/*  * Actions to take if<hesiod.h> exists.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_HESIOD_H
end_ifdef

begin_include
include|#
directive|include
file|<hesiod.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* HAVE_HESIOD_H */
end_comment

begin_comment
comment|/*  * Actions to take if<lber.h> exists.  * This header file is required before<ldap.h> can be included.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_LBER_H
end_ifdef

begin_include
include|#
directive|include
file|<lber.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* HAVE_LBER_H */
end_comment

begin_comment
comment|/*  * Actions to take if<ldap.h> exists.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_LDAP_H
end_ifdef

begin_include
include|#
directive|include
file|<ldap.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* HAVE_LDAP_H */
end_comment

begin_comment
comment|/*  * Actions to take if<arpa/nameser.h> exists.  * Should be included before<resolv.h>.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_ARPA_NAMESER_H
end_ifdef

begin_ifdef
ifdef|#
directive|ifdef
name|NOERROR
end_ifdef

begin_undef
undef|#
directive|undef
name|NOERROR
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* NOERROR */
end_comment

begin_comment
comment|/*  * Conflicts with<sys/tpicommon.h> which is included from<sys/tiuser.h>  * on Solaris 2.6 systems.  So undefine it first.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|T_UNSPEC
end_ifdef

begin_undef
undef|#
directive|undef
name|T_UNSPEC
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* T_UNSPEC */
end_comment

begin_include
include|#
directive|include
file|<arpa/nameser.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* HAVE_ARPA_NAMESER_H */
end_comment

begin_comment
comment|/*  * Actions to take if<arpa/inet.h> exists.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_ARPA_INET_H
end_ifdef

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_BAD_HEADERS
end_ifdef

begin_comment
comment|/* aix 4.3: avoid including<net/if_dl.h> */
end_comment

begin_struct_decl
struct_decl|struct
name|sockaddr_dl
struct_decl|;
end_struct_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* HAVE_BAD_HEADERS */
end_comment

begin_include
include|#
directive|include
file|<arpa/inet.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* HAVE_ARPA_INET_H */
end_comment

begin_comment
comment|/*  * Actions to take if<resolv.h> exists.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_RESOLV_H
end_ifdef

begin_include
include|#
directive|include
file|<resolv.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* HAVE_RESOLV_H */
end_comment

begin_comment
comment|/*  * Actions to take if<sys/uio.h> exists.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_SYS_UIO_H
end_ifdef

begin_include
include|#
directive|include
file|<sys/uio.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* HAVE_SYS_UIO_H */
end_comment

begin_comment
comment|/*  * Actions to take if<sys/fs/cachefs_fs.h> exists.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_SYS_FS_CACHEFS_FS_H
end_ifdef

begin_include
include|#
directive|include
file|<sys/fs/cachefs_fs.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* HAVE_SYS_FS_CACHEFS_FS_H */
end_comment

begin_comment
comment|/*  * Actions to take if<sys/fs/pc_fs.h> exists.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_SYS_FS_PC_FS_H
end_ifdef

begin_include
include|#
directive|include
file|<sys/fs/pc_fs.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* HAVE_SYS_FS_PC_FS_H */
end_comment

begin_comment
comment|/*  * Actions to take if<msdosfs/msdosfsmount.h> exists.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_MSDOSFS_MSDOSFSMOUNT_H
end_ifdef

begin_include
include|#
directive|include
file|<msdosfs/msdosfsmount.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* HAVE_MSDOSFS_MSDOSFSMOUNT_H */
end_comment

begin_comment
comment|/*  * Actions to take if<sys/fs/tmp.h> exists.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_SYS_FS_TMP_H
end_ifdef

begin_include
include|#
directive|include
file|<sys/fs/tmp.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* HAVE_SYS_FS_TMP_H */
end_comment

begin_comment
comment|/*  * Actions to take if<sys/fs/ufs_mount.h> exists.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_SYS_FS_UFS_MOUNT_H
end_ifdef

begin_include
include|#
directive|include
file|<sys/fs/ufs_mount.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* HAVE_SYS_FS_UFS_MOUNT_H */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_UFS_UFS_UFSMOUNT_H_off
end_ifdef

begin_error
error|#
directive|error
error|do not include this file here because on netbsd/openbsd it
end_error

begin_error
error|#
directive|error
error|causes errors with other header files.  Instead, add it to the
end_error

begin_error
error|#
directive|error
error|specific conf/nfs_prot_*.h file.
end_error

begin_include
include|#
directive|include
file|<ufs/ufs/ufsmount.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* HAVE_UFS_UFS_UFSMOUNT_H */
end_comment

begin_comment
comment|/*  * Actions to take if<sys/fs/efs_clnt.h> exists.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_SYS_FS_EFS_CLNT_H
end_ifdef

begin_include
include|#
directive|include
file|<sys/fs/efs_clnt.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* HAVE_SYS_FS_EFS_CLNT_H */
end_comment

begin_comment
comment|/*  * Actions to take if<sys/fs/xfs_clnt.h> exists.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_SYS_FS_XFS_CLNT_H
end_ifdef

begin_include
include|#
directive|include
file|<sys/fs/xfs_clnt.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* HAVE_SYS_FS_XFS_CLNT_H */
end_comment

begin_comment
comment|/*  * Actions to take if<assert.h> exists.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_ASSERT_H
end_ifdef

begin_include
include|#
directive|include
file|<assert.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* HAVE_ASSERT_H */
end_comment

begin_comment
comment|/*  * Actions to take if<cfs.h> exists.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_CFS_H
end_ifdef

begin_include
include|#
directive|include
file|<cfs.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* HAVE_CFS_H */
end_comment

begin_comment
comment|/*  * Actions to take if<cluster.h> exists.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_CLUSTER_H
end_ifdef

begin_include
include|#
directive|include
file|<cluster.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* HAVE_CLUSTER_H */
end_comment

begin_comment
comment|/*  * Actions to take if<ctype.h> exists.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_CTYPE_H
end_ifdef

begin_include
include|#
directive|include
file|<ctype.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* HAVE_CTYPE_H */
end_comment

begin_comment
comment|/*  * Actions to take if<errno.h> exists.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_ERRNO_H
end_ifdef

begin_include
include|#
directive|include
file|<errno.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* HAVE_ERRNO_H */
end_comment

begin_comment
comment|/*  * Actions to take if<grp.h> exists.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_GRP_H
end_ifdef

begin_include
include|#
directive|include
file|<grp.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* HAVE_GRP_H */
end_comment

begin_comment
comment|/*  * Actions to take if<hsfs/hsfs.h> exists.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_HSFS_HSFS_H
end_ifdef

begin_include
include|#
directive|include
file|<hsfs/hsfs.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* HAVE_HSFS_HSFS_H */
end_comment

begin_comment
comment|/*  * Actions to take if<cdfs/cdfsmount.h> exists.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_CDFS_CDFSMOUNT_H
end_ifdef

begin_include
include|#
directive|include
file|<cdfs/cdfsmount.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* HAVE_CDFS_CDFSMOUNT_H */
end_comment

begin_comment
comment|/*  * Actions to take if<isofs/cd9660/cd9660_mount.h> exists.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_ISOFS_CD9660_CD9660_MOUNT_H
end_ifdef

begin_include
include|#
directive|include
file|<isofs/cd9660/cd9660_mount.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* HAVE_ISOFS_CD9660_CD9660_MOUNT_H */
end_comment

begin_comment
comment|/*  * Actions to take if<mount.h> exists.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_MOUNT_H
end_ifdef

begin_include
include|#
directive|include
file|<mount.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* HAVE_MOUNT_H */
end_comment

begin_comment
comment|/*  * Actions to take if<nsswitch.h> exists.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_NSSWITCH_H
end_ifdef

begin_include
include|#
directive|include
file|<nsswitch.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* HAVE_NSSWITCH_H */
end_comment

begin_comment
comment|/*  * Actions to take if<rpc/auth_des.h> exists.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_RPC_AUTH_DES_H
end_ifdef

begin_include
include|#
directive|include
file|<rpc/auth_des.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* HAVE_RPC_AUTH_DES_H */
end_comment

begin_comment
comment|/*  * Actions to take if<rpc/pmap_clnt.h> exists.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_RPC_PMAP_CLNT_H
end_ifdef

begin_include
include|#
directive|include
file|<rpc/pmap_clnt.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* HAVE_RPC_PMAP_CLNT_H */
end_comment

begin_comment
comment|/*  * Actions to take if<rpc/pmap_prot.h> exists.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_RPC_PMAP_PROT_H
end_ifdef

begin_include
include|#
directive|include
file|<rpc/pmap_prot.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* HAVE_RPC_PMAP_PROT_H */
end_comment

begin_comment
comment|/*  * Actions to take if<rpcsvc/mount.h> exists.  * AIX does not protect against this file doubly included,  * so I have to do my own protection here.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|COMMENT_OUT
end_ifdef

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_RPCSVC_MOUNT_H
end_ifdef

begin_ifndef
ifndef|#
directive|ifndef
name|_RPCSVC_MOUNT_H
end_ifndef

begin_include
include|#
directive|include
file|<rpcsvc/mount.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* not _RPCSVC_MOUNT_H */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* HAVE_RPCSVC_MOUNT_H */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|"mount.h"
end_include

begin_comment
comment|/*  * Actions to take if<rpcsvc/nis.h> exists.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_RPCSVC_NIS_H
end_ifdef

begin_include
include|#
directive|include
file|<rpcsvc/nis.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* HAVE_RPCSVC_NIS_H */
end_comment

begin_comment
comment|/*  * Actions to take if<setjmp.h> exists.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_SETJMP_H
end_ifdef

begin_include
include|#
directive|include
file|<setjmp.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* HAVE_SETJMP_H */
end_comment

begin_comment
comment|/*  * Actions to take if<signal.h> exists.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_SIGNAL_H
end_ifdef

begin_include
include|#
directive|include
file|<signal.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* HAVE_SIGNAL_H */
end_comment

begin_comment
comment|/*  * Actions to take if<string.h> exists.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_STRING_H
end_ifdef

begin_include
include|#
directive|include
file|<string.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* HAVE_STRING_H */
end_comment

begin_comment
comment|/*  * Actions to take if<strings.h> exists.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_STRINGS_H
end_ifdef

begin_include
include|#
directive|include
file|<strings.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* HAVE_STRINGS_H */
end_comment

begin_comment
comment|/*  * Actions to take if<sys/config.h> exists.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_SYS_CONFIG_H
end_ifdef

begin_include
include|#
directive|include
file|<sys/config.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* HAVE_SYS_CONFIG_H */
end_comment

begin_comment
comment|/*  * Actions to take if<sys/dg_mount.h> exists.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_SYS_DG_MOUNT_H
end_ifdef

begin_include
include|#
directive|include
file|<sys/dg_mount.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* HAVE_SYS_DG_MOUNT_H */
end_comment

begin_comment
comment|/*  * Actions to take if<sys/fs_types.h> exists.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_SYS_FS_TYPES_H
end_ifdef

begin_comment
comment|/*  * Define KERNEL here to avoid multiple definitions of gt_names[] on  * Ultrix 4.3.  */
end_comment

begin_define
define|#
directive|define
name|KERNEL
end_define

begin_include
include|#
directive|include
file|<sys/fs_types.h>
end_include

begin_undef
undef|#
directive|undef
name|KERNEL
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* HAVE_SYS_FS_TYPES_H */
end_comment

begin_comment
comment|/*  * Actions to take if<sys/fstyp.h> exists.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_SYS_FSTYP_H
end_ifdef

begin_include
include|#
directive|include
file|<sys/fstyp.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* HAVE_SYS_FSTYP_H */
end_comment

begin_comment
comment|/*  * Actions to take if<sys/lock.h> exists.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_SYS_LOCK_H
end_ifdef

begin_include
include|#
directive|include
file|<sys/lock.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* HAVE_SYS_LOCK_H */
end_comment

begin_comment
comment|/*  * Actions to take if<sys/machine.h> exists.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_SYS_MACHINE_H
end_ifdef

begin_include
include|#
directive|include
file|<sys/machine.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* HAVE_SYS_MACHINE_H */
end_comment

begin_comment
comment|/*  * Actions to take if<sys/mntctl.h> exists.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_SYS_MNTCTL_H
end_ifdef

begin_include
include|#
directive|include
file|<sys/mntctl.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* HAVE_SYS_MNTCTL_H */
end_comment

begin_comment
comment|/*  * Actions to take if<sys/mnttab.h> exists.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_SYS_MNTTAB_H
end_ifdef

begin_include
include|#
directive|include
file|<sys/mnttab.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* HAVE_SYS_MNTTAB_H */
end_comment

begin_comment
comment|/*  * Actions to take if<mnttab.h> exists.  * Do not include it if MNTTAB is already defined because it probably  * came from<sys/mnttab.h> and we do not want conflicting definitions.  */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|HAVE_MNTTAB_H
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|MNTTAB
argument_list|)
end_if

begin_include
include|#
directive|include
file|<mnttab.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* defined(HAVE_MNTTAB_H)&& !defined(MNTTAB) */
end_comment

begin_comment
comment|/*  * Actions to take if<netconfig.h> exists.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_NETCONFIG_H
end_ifdef

begin_include
include|#
directive|include
file|<netconfig.h>
end_include

begin_comment
comment|/* Some systems (Solaris 2.5.1) don't declare this external */
end_comment

begin_function_decl
specifier|extern
name|char
modifier|*
name|nc_sperror
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* HAVE_NETCONFIG_H */
end_comment

begin_comment
comment|/*  * Actions to take if<sys/netconfig.h> exists.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_SYS_NETCONFIG_H
end_ifdef

begin_include
include|#
directive|include
file|<sys/netconfig.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* HAVE_SYS_NETCONFIG_H */
end_comment

begin_comment
comment|/*  * Actions to take if<sys/pathconf.h> exists.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_SYS_PATHCONF_H
end_ifdef

begin_include
include|#
directive|include
file|<sys/pathconf.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* HAVE_SYS_PATHCONF_H */
end_comment

begin_comment
comment|/*  * Actions to take if<sys/resource.h> exists.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_SYS_RESOURCE_H
end_ifdef

begin_include
include|#
directive|include
file|<sys/resource.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* HAVE_SYS_RESOURCE_H */
end_comment

begin_comment
comment|/*  * Actions to take if<sys/sema.h> exists.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_SYS_SEMA_H
end_ifdef

begin_include
include|#
directive|include
file|<sys/sema.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* HAVE_SYS_SEMA_H */
end_comment

begin_comment
comment|/*  * Actions to take if<sys/signal.h> exists.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_SYS_SIGNAL_H
end_ifdef

begin_include
include|#
directive|include
file|<sys/signal.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* HAVE_SYS_SIGNAL_H */
end_comment

begin_comment
comment|/*  * Actions to take if<sys/sockio.h> exists.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_SYS_SOCKIO_H
end_ifdef

begin_include
include|#
directive|include
file|<sys/sockio.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* HAVE_SYS_SOCKIO_H */
end_comment

begin_comment
comment|/*  * Actions to take if<sys/syscall.h> exists.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_SYS_SYSCALL_H
end_ifdef

begin_include
include|#
directive|include
file|<sys/syscall.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* HAVE_SYS_SYSCALL_H */
end_comment

begin_comment
comment|/*  * Actions to take if<sys/syslimits.h> exists.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_SYS_SYSLIMITS_H
end_ifdef

begin_include
include|#
directive|include
file|<sys/syslimits.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* HAVE_SYS_SYSLIMITS_H */
end_comment

begin_comment
comment|/*  * Actions to take if<tiuser.h> exists.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_TIUSER_H
end_ifdef

begin_comment
comment|/*  * Some systems like AIX have multiple definitions for T_NULL and others  * that are defined first in<arpa/nameser.h>.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_ARPA_NAMESER_H
end_ifdef

begin_ifdef
ifdef|#
directive|ifdef
name|T_NULL
end_ifdef

begin_undef
undef|#
directive|undef
name|T_NULL
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* T_NULL */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|T_UNSPEC
end_ifdef

begin_undef
undef|#
directive|undef
name|T_UNSPEC
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* T_UNSPEC */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|T_IDLE
end_ifdef

begin_undef
undef|#
directive|undef
name|T_IDLE
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* T_IDLE */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* HAVE_ARPA_NAMESER_H */
end_comment

begin_include
include|#
directive|include
file|<tiuser.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* HAVE_TIUSER_H */
end_comment

begin_comment
comment|/*  * Actions to take if<sys/tiuser.h> exists.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_SYS_TIUSER_H
end_ifdef

begin_include
include|#
directive|include
file|<sys/tiuser.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* HAVE_SYS_TIUSER_H */
end_comment

begin_comment
comment|/*  * Actions to take if<sys/statfs.h> exists.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_SYS_STATFS_H
end_ifdef

begin_include
include|#
directive|include
file|<sys/statfs.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* HAVE_SYS_STATFS_H */
end_comment

begin_comment
comment|/*  * Actions to take if<sys/vfs.h> exists.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_SYS_VFS_H
end_ifdef

begin_include
include|#
directive|include
file|<sys/vfs.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* HAVE_SYS_VFS_H */
end_comment

begin_comment
comment|/*  * Actions to take if<sys/vmount.h> exists.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_SYS_VMOUNT_H
end_ifdef

begin_include
include|#
directive|include
file|<sys/vmount.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* HAVE_SYS_VMOUNT_H */
end_comment

begin_comment
comment|/*  * Actions to take if<ufs/ufs_mount.h> exists.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_UFS_UFS_MOUNT_H
end_ifdef

begin_include
include|#
directive|include
file|<ufs/ufs/ufsmount.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* HAVE_UFS_UFS_MOUNT_H */
end_comment

begin_comment
comment|/*  * Are S_ISDIR, S_ISREG, et al broken?  If not, include<sys/stat.h>.  * Turned off the not using sys/stat.h based on if the macros are  * "broken", because they incorrectly get reported as broken on  * ncr2.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|STAT_MACROS_BROKEN_notused
end_ifndef

begin_comment
comment|/*  * RedHat Linux 4.2 (alpha) has a problem in the headers that causes  * duplicate definitions, and also some other nasty bugs.  Upgrade to Redhat  * 5.0!  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_SYS_STAT_H
end_ifdef

begin_comment
comment|/* avoid duplicates or conflicts with<linux/stat.h> (RedHat alpha linux) */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|S_IFREG
argument_list|)
operator|&&
name|defined
argument_list|(
name|HAVE_STATBUF_H
argument_list|)
end_if

begin_include
include|#
directive|include
file|<statbuf.h>
end_include

begin_undef
undef|#
directive|undef
name|S_IFBLK
end_undef

begin_undef
undef|#
directive|undef
name|S_IFCHR
end_undef

begin_undef
undef|#
directive|undef
name|S_IFDIR
end_undef

begin_undef
undef|#
directive|undef
name|S_IFIFO
end_undef

begin_undef
undef|#
directive|undef
name|S_IFLNK
end_undef

begin_undef
undef|#
directive|undef
name|S_IFMT
end_undef

begin_undef
undef|#
directive|undef
name|S_IFREG
end_undef

begin_undef
undef|#
directive|undef
name|S_IFSOCK
end_undef

begin_undef
undef|#
directive|undef
name|S_IRGRP
end_undef

begin_undef
undef|#
directive|undef
name|S_IROTH
end_undef

begin_undef
undef|#
directive|undef
name|S_IRUSR
end_undef

begin_undef
undef|#
directive|undef
name|S_IRWXG
end_undef

begin_undef
undef|#
directive|undef
name|S_IRWXO
end_undef

begin_undef
undef|#
directive|undef
name|S_IRWXU
end_undef

begin_undef
undef|#
directive|undef
name|S_ISBLK
end_undef

begin_undef
undef|#
directive|undef
name|S_ISCHR
end_undef

begin_undef
undef|#
directive|undef
name|S_ISDIR
end_undef

begin_undef
undef|#
directive|undef
name|S_ISFIFO
end_undef

begin_undef
undef|#
directive|undef
name|S_ISGID
end_undef

begin_undef
undef|#
directive|undef
name|S_ISLNK
end_undef

begin_undef
undef|#
directive|undef
name|S_ISREG
end_undef

begin_undef
undef|#
directive|undef
name|S_ISSOCK
end_undef

begin_undef
undef|#
directive|undef
name|S_ISUID
end_undef

begin_undef
undef|#
directive|undef
name|S_ISVTX
end_undef

begin_undef
undef|#
directive|undef
name|S_IWGRP
end_undef

begin_undef
undef|#
directive|undef
name|S_IWOTH
end_undef

begin_undef
undef|#
directive|undef
name|S_IWUSR
end_undef

begin_undef
undef|#
directive|undef
name|S_IXGRP
end_undef

begin_undef
undef|#
directive|undef
name|S_IXOTH
end_undef

begin_undef
undef|#
directive|undef
name|S_IXUSR
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* defined(S_IFREG)&& defined(HAVE_STATBUF_H) */
end_comment

begin_include
include|#
directive|include
file|<sys/stat.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* HAVE_SYS_STAT_H */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* not STAT_MACROS_BROKEN_notused */
end_comment

begin_comment
comment|/*  * Actions to take if<stdio.h> exists.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_STDIO_H
end_ifdef

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* HAVE_STDIO_H */
end_comment

begin_comment
comment|/*  * Actions to take if<stdlib.h> exists.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_STDLIB_H
end_ifdef

begin_include
include|#
directive|include
file|<stdlib.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* HAVE_STDLIB_H */
end_comment

begin_comment
comment|/*  * Actions to take if<regex.h> exists.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_REGEX_H
end_ifdef

begin_include
include|#
directive|include
file|<regex.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* HAVE_REGEX_H */
end_comment

begin_comment
comment|/****************************************************************************/
end_comment

begin_comment
comment|/*  * Specific macros we're looking for.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|HAVE_MEMSET
end_ifndef

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_BZERO
end_ifdef

begin_define
define|#
directive|define
name|memset
parameter_list|(
name|ptr
parameter_list|,
name|val
parameter_list|,
name|len
parameter_list|)
value|bzero((ptr), (len))
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* not HAVE_BZERO */
end_comment

begin_error
error|#
directive|error
error|Cannot find either memset or bzero!
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* not HAVE_BZERO */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* not HAVE_MEMSET */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|HAVE_MEMMOVE
end_ifndef

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_BCOPY
end_ifdef

begin_define
define|#
directive|define
name|memmove
parameter_list|(
name|to
parameter_list|,
name|from
parameter_list|,
name|len
parameter_list|)
value|bcopy((from), (to), (len))
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* not HAVE_BCOPY */
end_comment

begin_error
error|#
directive|error
error|Cannot find either memmove or bcopy!
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* not HAVE_BCOPY */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* not HAVE_MEMMOVE */
end_comment

begin_comment
comment|/*  * memcmp() is more problematic:  * Systems that don't have it, but have bcmp(), will use bcmp() instead.  * Those that have it, but it is bad (SunOS 4 doesn't handle  * 8 bit comparisons correctly), will get to use am_memcmp().  * Otherwise if you have memcmp() and it is good, use it.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_MEMCMP
end_ifdef

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_BAD_MEMCMP
end_ifdef

begin_define
define|#
directive|define
name|memcmp
value|am_memcmp
end_define

begin_function_decl
specifier|extern
name|int
name|am_memcmp
parameter_list|(
specifier|const
name|voidp
name|s1
parameter_list|,
specifier|const
name|voidp
name|s2
parameter_list|,
name|size_t
name|len
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* HAVE_BAD_MEMCMP */
end_comment

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* not HAVE_MEMCMP */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_BCMP
end_ifdef

begin_define
define|#
directive|define
name|memcmp
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|,
name|len
parameter_list|)
value|bcmp((a), (b), (len))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* HAVE_BCMP */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* not HAVE_MEMCMP */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|HAVE_SETEUID
end_ifndef

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_SETRESUID
end_ifdef

begin_define
define|#
directive|define
name|seteuid
parameter_list|(
name|x
parameter_list|)
value|setresuid(-1,(x),-1)
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* not HAVE_SETRESUID */
end_comment

begin_error
error|#
directive|error
error|Cannot find either seteuid or setresuid!
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* not HAVE_SETRESUID */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* not HAVE_SETEUID */
end_comment

begin_comment
comment|/*  * Define type of mntent_t.  * Defaults to struct mntent, else struct mnttab.  If neither is found, and  * the operating system does keep not mount tables in the kernel, then flag  * it as an error.  If neither is found and the OS keeps mount tables in the  * kernel, then define our own version of mntent; it will be needed for amd  * to keep its own internal version of the mount tables.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_STRUCT_MNTENT
end_ifdef

begin_typedef
typedef|typedef
name|struct
name|mntent
name|mntent_t
typedef|;
end_typedef

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* not HAVE_STRUCT_MNTENT */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_STRUCT_MNTTAB
end_ifdef

begin_typedef
typedef|typedef
name|struct
name|mnttab
name|mntent_t
typedef|;
end_typedef

begin_comment
comment|/* map struct mnttab field names to struct mntent field names */
end_comment

begin_define
define|#
directive|define
name|mnt_fsname
value|mnt_special
end_define

begin_define
define|#
directive|define
name|mnt_dir
value|mnt_mountp
end_define

begin_define
define|#
directive|define
name|mnt_opts
value|mnt_mntopts
end_define

begin_define
define|#
directive|define
name|mnt_type
value|mnt_fstype
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* not HAVE_STRUCT_MNTTAB */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|MOUNT_TABLE_ON_FILE
end_ifdef

begin_error
error|#
directive|error
error|Could not find definition for struct mntent or struct mnttab!
end_error

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* not MOUNT_TABLE_ON_FILE */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_am_mntent
block|{
name|char
modifier|*
name|mnt_fsname
decl_stmt|;
comment|/* name of mounted file system */
name|char
modifier|*
name|mnt_dir
decl_stmt|;
comment|/* file system path prefix */
name|char
modifier|*
name|mnt_type
decl_stmt|;
comment|/* MNTTAB_TYPE_* */
name|char
modifier|*
name|mnt_opts
decl_stmt|;
comment|/* MNTTAB_OPT_* */
name|int
name|mnt_freq
decl_stmt|;
comment|/* dump frequency, in days */
name|int
name|mnt_passno
decl_stmt|;
comment|/* pass number on parallel fsck */
block|}
name|mntent_t
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* not MOUNT_TABLE_ON_FILE */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* not HAVE_STRUCT_MNTTAB */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* not HAVE_STRUCT_MNTENT */
end_comment

begin_comment
comment|/*  * Complete external definitions missing from some systems.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|HAVE_EXTERN_SYS_ERRLIST
end_ifndef

begin_decl_stmt
specifier|extern
specifier|const
name|char
modifier|*
specifier|const
name|sys_errlist
index|[]
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* not HAVE_EXTERN_SYS_ERRLIST */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|HAVE_EXTERN_OPTARG
end_ifndef

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

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* not HAVE_EXTERN_OPTARG */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|HAVE_CLNT_SPCREATEERROR
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|HAVE_EXTERN_CLNT_SPCREATEERROR
argument_list|)
end_if

begin_function_decl
specifier|extern
name|char
modifier|*
name|clnt_spcreateerror
parameter_list|(
specifier|const
name|char
modifier|*
name|s
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* defined(HAVE_CLNT_SPCREATEERROR)&& !defined(HAVE_EXTERN_CLNT_SPCREATEERROR) */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|HAVE_CLNT_SPERRNO
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|HAVE_EXTERN_CLNT_SPERRNO
argument_list|)
end_if

begin_function_decl
specifier|extern
name|char
modifier|*
name|clnt_sperrno
parameter_list|(
specifier|const
name|enum
name|clnt_stat
name|num
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* defined(HAVE_CLNT_SPERRNO)&& !defined(HAVE_EXTERN_CLNT_SPERRNO) */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|HAVE_EXTERN_FREE
end_ifndef

begin_function_decl
specifier|extern
name|void
name|free
parameter_list|(
name|voidp
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* not HAVE_EXTERN_FREE */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|HAVE_GET_MYADDRESS
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|HAVE_EXTERN_GET_MYADDRESS
argument_list|)
end_if

begin_function_decl
specifier|extern
name|void
name|get_myaddress
parameter_list|(
name|struct
name|sockaddr_in
modifier|*
name|addr
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* defined(HAVE_GET_MYADDRESS)&& !defined(HAVE_EXTERN_GET_MYADDRESS) */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|HAVE_GETDOMAINNAME
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|HAVE_EXTERN_GETDOMAINNAME
argument_list|)
end_if

begin_if
if|#
directive|if
name|defined
argument_list|(
name|HAVE_MAP_NIS
argument_list|)
operator|||
name|defined
argument_list|(
name|HAVE_MAP_NISPLUS
argument_list|)
end_if

begin_function_decl
specifier|extern
name|int
name|getdomainname
parameter_list|(
name|char
modifier|*
name|name
parameter_list|,
name|int
name|namelen
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* defined(HAVE_MAP_NIS) || defined(HAVE_MAP_NISPLUS) */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* defined(HAVE_GETDOMAINNAME)&& !defined(HAVE_EXTERN_GETDOMAINNAME) */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|HAVE_GETDTABLESIZE
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|HAVE_EXTERN_GETDTABLESIZE
argument_list|)
end_if

begin_function_decl
specifier|extern
name|int
name|getdtablesize
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* defined(HAVE_GETDTABLESIZE)&& !defined(HAVE_EXTERN_GETDTABLESIZE) */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|HAVE_GETHOSTNAME
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|HAVE_EXTERN_GETHOSTNAME
argument_list|)
end_if

begin_function_decl
specifier|extern
name|int
name|gethostname
parameter_list|(
name|char
modifier|*
name|name
parameter_list|,
name|int
name|namelen
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* defined(HAVE_GETHOSTNAME)&& !defined(HAVE_EXTERN_GETHOSTNAME) */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|HAVE_EXTERN_GETLOGIN
end_ifndef

begin_function_decl
specifier|extern
name|char
modifier|*
name|getlogin
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* not HAVE_EXTERN_GETLOGIN */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|HAVE_GETPAGESIZE
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|HAVE_EXTERN_GETPAGESIZE
argument_list|)
end_if

begin_function_decl
specifier|extern
name|int
name|getpagesize
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* defined(HAVE_GETPAGESIZE)&& !defined(HAVE_EXTERN_GETPAGESIZE) */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|HAVE_EXTERN_GETWD
end_ifndef

begin_function_decl
specifier|extern
name|char
modifier|*
name|getwd
parameter_list|(
name|char
modifier|*
name|s
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* not HAVE_EXTERN_GETWD */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|HAVE_EXTERN_INNETGR
end_ifndef

begin_function_decl
specifier|extern
name|int
name|innetgr
parameter_list|(
name|char
modifier|*
parameter_list|,
name|char
modifier|*
parameter_list|,
name|char
modifier|*
parameter_list|,
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
comment|/* not HAVE_EXTERN_INNETGR */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|HAVE_MKSTEMP
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|HAVE_EXTERN_MKSTEMP
argument_list|)
end_if

begin_function_decl
specifier|extern
name|int
name|mkstemp
parameter_list|(
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
comment|/* defined(HAVE_MKSTEMP)&& !defined(HAVE_EXTERN_MKSTEMP) */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|HAVE_EXTERN_SBRK
end_ifndef

begin_function_decl
specifier|extern
name|caddr_t
name|sbrk
parameter_list|(
name|int
name|incr
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* not HAVE_EXTERN_SBRK */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|HAVE_SETEUID
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|HAVE_EXTERN_SETEUID
argument_list|)
end_if

begin_function_decl
specifier|extern
name|int
name|seteuid
parameter_list|(
name|uid_t
name|euid
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* not defined(HAVE_SETEUID)&& !defined(HAVE_EXTERN_SETEUID) */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|HAVE_SETITIMER
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|HAVE_EXTERN_SETITIMER
argument_list|)
end_if

begin_function_decl
specifier|extern
name|int
name|setitimer
parameter_list|(
name|int
parameter_list|,
name|struct
name|itimerval
modifier|*
parameter_list|,
name|struct
name|itimerval
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* defined(HAVE_SETITIMER)&& !defined(HAVE_EXTERN_SETITIMER) */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|HAVE_EXTERN_STRCASECMP
end_ifndef

begin_comment
comment|/*  * define this extern even if function does not exist, for it will  * be filled in by libamu/strcasecmp.c  */
end_comment

begin_function_decl
specifier|extern
name|int
name|strcasecmp
parameter_list|(
specifier|const
name|char
modifier|*
name|s1
parameter_list|,
specifier|const
name|char
modifier|*
name|s2
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* not HAVE_EXTERN_STRCASECMP */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|HAVE_EXTERN_STRDUP
end_ifndef

begin_comment
comment|/*  * define this extern even if function does not exist, for it will  * be filled in by libamu/strdup.c  */
end_comment

begin_function_decl
specifier|extern
name|char
modifier|*
name|strdup
parameter_list|(
specifier|const
name|char
modifier|*
name|s
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* not HAVE_EXTERN_STRDUP */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|HAVE_STRSTR
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|HAVE_EXTERN_STRSTR
argument_list|)
end_if

begin_function_decl
specifier|extern
name|char
modifier|*
name|strstr
parameter_list|(
specifier|const
name|char
modifier|*
name|s1
parameter_list|,
specifier|const
name|char
modifier|*
name|s2
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* defined(HAVE_STRSTR)&& !defined(HAVE_EXTERN_STRSTR) */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|HAVE_USLEEP
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|HAVE_EXTERN_USLEEP
argument_list|)
end_if

begin_function_decl
specifier|extern
name|int
name|usleep
parameter_list|(
name|u_int
name|useconds
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* defined(HAVE_USLEEP)&& !defined(HAVE_EXTERN_USLEEP) */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|HAVE_EXTERN_UALARM
end_ifndef

begin_function_decl
specifier|extern
name|u_int
name|ualarm
parameter_list|(
name|u_int
name|usecs
parameter_list|,
name|u_int
name|interval
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* not HAVE_EXTERN_UALARM */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|HAVE_WAIT3
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|HAVE_EXTERN_WAIT3
argument_list|)
end_if

begin_function_decl
specifier|extern
name|int
name|wait3
parameter_list|(
name|int
modifier|*
name|statusp
parameter_list|,
name|int
name|options
parameter_list|,
name|struct
name|rusage
modifier|*
name|rusage
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* defined(HAVE_WAIT3)&& !defined(HAVE_EXTERN_WAIT3) */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|HAVE_VSNPRINTF
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|HAVE_EXTERN_VSNPRINTF
argument_list|)
end_if

begin_function_decl
specifier|extern
name|int
name|vsnprintf
parameter_list|(
name|char
modifier|*
parameter_list|,
name|int
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
modifier|...
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* defined(HAVE_VSNPRINTF)&& !defined(HAVE_EXTERN_VSNPRINTF) */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|HAVE_EXTERN_XDR_OPAQUE_AUTH
end_ifndef

begin_function_decl
specifier|extern
name|bool_t
name|xdr_opaque_auth
parameter_list|(
name|XDR
modifier|*
name|xdrs
parameter_list|,
name|struct
name|opaque_auth
modifier|*
name|auth
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* not HAVE_EXTERN_XDR_OPAQUE_AUTH */
end_comment

begin_comment
comment|/****************************************************************************/
end_comment

begin_comment
comment|/*  * amd-specific header files.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|THIS_HEADER_FILE_IS_INCLUDED_ABOVE
end_ifdef

begin_include
include|#
directive|include
file|<amu_nfs_prot.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* THIS_HEADER_FILE_IS_INCLUDED_ABOVE */
end_comment

begin_include
include|#
directive|include
file|<am_utils.h>
end_include

begin_include
include|#
directive|include
file|<amq_defs.h>
end_include

begin_include
include|#
directive|include
file|<aux_conf.h>
end_include

begin_comment
comment|/* compatibility with old amd, while autoconfiscating it */
end_comment

begin_include
include|#
directive|include
file|<am_compat.h>
end_include

begin_comment
comment|/****************************************************************************/
end_comment

begin_comment
comment|/*  * External definitions that depend on other macros available (or not)  * and those are probably declared in any of the above headers.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|HAVE_HASMNTOPT
end_ifndef

begin_function_decl
specifier|extern
name|char
modifier|*
name|hasmntopt
parameter_list|(
name|mntent_t
modifier|*
name|mnt
parameter_list|,
name|char
modifier|*
name|opt
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* not HAVE_HASMNTOPT */
end_comment

begin_comment
comment|/*  * include definitions of all possible xdr functions that are otherwise  * not defined elsewhere.  */
end_comment

begin_include
include|#
directive|include
file|<am_xdr_func.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* not _AM_DEFS_H */
end_comment

end_unit

