begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  -*- Mode: C -*-   *  *  compat.h is free software.  *  This file is part of AutoGen and AutoOpts.  *  *  AutoGen Copyright (C) 1992-2014 by Bruce Korb - all rights reserved  *  *  AutoOpts is available under any one of two licenses.  The license  *  in use must be one of these two and the choice is under the control  *  of the user of the license.  *  *   The GNU Lesser General Public License, version 3 or later  *      See the files "COPYING.lgplv3" and "COPYING.gplv3"  *  *   The Modified Berkeley Software Distribution License  *      See the file "COPYING.mbsd"  *  *  These files have the following sha256 sums:  *  *  8584710e9b04216a394078dc156b781d0b47e1729104d666658aecef8ee32e95  COPYING.gplv3  *  4379e7444a0e2ce2b12dd6f5a52a27a4d02d39d247901d3285c88cf0d37f477b  COPYING.lgplv3  *  13aa749a5b0a454917a944ed8fffc530b784f5ead522b1aacaf4ec8aa55a6239  COPYING.mbsd  */
end_comment

begin_comment
comment|/**  * \file compat.h  *  fake the preprocessor into handlng stuff portability  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|COMPAT_H_GUARD
end_ifndef

begin_define
define|#
directive|define
name|COMPAT_H_GUARD
value|1
end_define

begin_if
if|#
directive|if
name|defined
argument_list|(
name|HAVE_CONFIG_H
argument_list|)
end_if

begin_include
include|#
directive|include
file|<config.h>
end_include

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|_WIN32
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|__CYGWIN__
argument_list|)
end_elif

begin_include
include|#
directive|include
file|"windows-config.h"
end_include

begin_else
else|#
directive|else
end_else

begin_error
error|#
directive|error
literal|"compat.h"
error|requires "config.h"
end_error

begin_function_decl
name|choke
name|me
operator|.
endif|#
directive|endif
ifndef|#
directive|ifndef
name|HAVE_STRSIGNAL
ifndef|#
directive|ifndef
name|HAVE_RAW_DECL_STRSIGNAL
name|char
modifier|*
name|strsignal
parameter_list|(
name|int
name|signo
parameter_list|)
function_decl|;
end_function_decl

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
name|_GNU_SOURCE
value|1
end_define

begin_comment
comment|/* for strsignal in GNU's libc */
end_comment

begin_define
define|#
directive|define
name|__USE_GNU
value|1
end_define

begin_comment
comment|/* exact same thing as above   */
end_comment

begin_define
define|#
directive|define
name|__EXTENSIONS__
value|1
end_define

begin_comment
comment|/* and another way to call for it */
end_comment

begin_comment
comment|/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *  *  *  SYSTEM HEADERS:  */
end_comment

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_SYS_MMAN_H
end_ifdef

begin_include
include|#
directive|include
file|<sys/mman.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<sys/param.h>
end_include

begin_if
if|#
directive|if
name|HAVE_SYS_PROCSET_H
end_if

begin_include
include|#
directive|include
file|<sys/procset.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<sys/stat.h>
end_include

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

begin_if
if|#
directive|if
name|defined
argument_list|(
name|HAVE_SOLARIS_SYSINFO
argument_list|)
end_if

begin_include
include|#
directive|include
file|<sys/systeminfo.h>
end_include

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|HAVE_UNAME_SYSCALL
argument_list|)
end_elif

begin_include
include|#
directive|include
file|<sys/utsname.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|DAEMON_ENABLED
end_ifdef

begin_if
if|#
directive|if
name|HAVE_SYS_STROPTS_H
end_if

begin_include
include|#
directive|include
file|<sys/stropts.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|HAVE_SYS_SOCKET_H
end_if

begin_include
include|#
directive|include
file|<sys/socket.h>
end_include

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
name|HAVE_SYS_POLL_H
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|HAVE_SYS_SELECT_H
argument_list|)
end_if

begin_error
error|#
directive|error
error|This system cannot support daemon processing
end_error

begin_expr_stmt
name|Choke
name|Me
operator|.
endif|#
directive|endif
if|#
directive|if
name|HAVE_SYS_POLL_H
include|#
directive|include
file|<sys/poll.h>
endif|#
directive|endif
if|#
directive|if
name|HAVE_SYS_SELECT_H
include|#
directive|include
file|<sys/select.h>
endif|#
directive|endif
if|#
directive|if
name|HAVE_NETINET_IN_H
include|#
directive|include
file|<netinet/in.h>
endif|#
directive|endif
if|#
directive|if
name|HAVE_SYS_UN_H
include|#
directive|include
file|<sys/un.h>
endif|#
directive|endif
endif|#
directive|endif
comment|/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *  *  *  USER HEADERS:  */
include|#
directive|include
file|<stdio.h>
include|#
directive|include
file|<assert.h>
include|#
directive|include
file|<ctype.h>
comment|/*  *  Directory opening stuff:  */
if|#
directive|if
name|defined
argument_list|(
name|_POSIX_SOURCE
argument_list|)
comment|/* Posix does not require that the d_ino field be present, and some    systems do not provide it. */
define|#
directive|define
name|REAL_DIR_ENTRY
parameter_list|(
name|dp
parameter_list|)
value|1
else|#
directive|else
comment|/* !_POSIX_SOURCE */
define|#
directive|define
name|REAL_DIR_ENTRY
parameter_list|(
name|dp
parameter_list|)
value|(dp->d_ino != 0)
endif|#
directive|endif
comment|/* !_POSIX_SOURCE */
if|#
directive|if
name|defined
argument_list|(
name|HAVE_DIRENT_H
argument_list|)
include|#
directive|include
file|<dirent.h>
define|#
directive|define
name|D_NAMLEN
parameter_list|(
name|dirent
parameter_list|)
value|strlen((dirent)->d_name)
else|#
directive|else
comment|/* !HAVE_DIRENT_H */
define|#
directive|define
name|dirent
value|direct
define|#
directive|define
name|D_NAMLEN
parameter_list|(
name|dirent
parameter_list|)
value|(dirent)->d_namlen
if|#
directive|if
name|defined
argument_list|(
name|HAVE_SYS_NDIR_H
argument_list|)
include|#
directive|include
file|<sys/ndir.h>
endif|#
directive|endif
comment|/* HAVE_SYS_NDIR_H */
if|#
directive|if
name|defined
argument_list|(
name|HAVE_SYS_DIR_H
argument_list|)
include|#
directive|include
file|<sys/dir.h>
endif|#
directive|endif
comment|/* HAVE_SYS_DIR_H */
if|#
directive|if
name|defined
argument_list|(
name|HAVE_NDIR_H
argument_list|)
include|#
directive|include
file|<ndir.h>
endif|#
directive|endif
comment|/* HAVE_NDIR_H */
endif|#
directive|endif
comment|/* !HAVE_DIRENT_H */
include|#
directive|include
file|<errno.h>
ifdef|#
directive|ifdef
name|HAVE_FCNTL_H
include|#
directive|include
file|<fcntl.h>
endif|#
directive|endif
ifndef|#
directive|ifndef
name|O_NONBLOCK
define|#
directive|define
name|O_NONBLOCK
value|FNDELAY
endif|#
directive|endif
if|#
directive|if
name|defined
argument_list|(
name|HAVE_LIBGEN
argument_list|)
operator|&&
name|defined
argument_list|(
name|HAVE_LIBGEN_H
argument_list|)
include|#
directive|include
file|<libgen.h>
endif|#
directive|endif
if|#
directive|if
name|defined
argument_list|(
name|HAVE_LIMITS_H
argument_list|)
comment|/* this is also in options.h */
include|#
directive|include
file|<limits.h>
elif|#
directive|elif
name|defined
argument_list|(
name|HAVE_SYS_LIMITS_H
argument_list|)
include|#
directive|include
file|<sys/limits.h>
endif|#
directive|endif
comment|/* HAVE_LIMITS/SYS_LIMITS_H */
include|#
directive|include
file|<memory.h>
include|#
directive|include
file|<setjmp.h>
include|#
directive|include
file|<signal.h>
if|#
directive|if
name|defined
argument_list|(
name|HAVE_STDINT_H
argument_list|)
include|#
directive|include
file|<stdint.h>
elif|#
directive|elif
name|defined
argument_list|(
name|HAVE_INTTYPES_H
argument_list|)
include|#
directive|include
file|<inttypes.h>
endif|#
directive|endif
include|#
directive|include
file|<stdlib.h>
include|#
directive|include
file|<string.h>
include|#
directive|include
file|<time.h>
ifdef|#
directive|ifdef
name|HAVE_UTIME_H
include|#
directive|include
file|<utime.h>
endif|#
directive|endif
ifdef|#
directive|ifdef
name|HAVE_UNISTD_H
include|#
directive|include
file|<unistd.h>
endif|#
directive|endif
ifdef|#
directive|ifdef
name|HAVE_STDBOOL_H
include|#
directive|include
file|<stdbool.h>
else|#
directive|else
expr|typedef enum
block|{
name|false
operator|=
literal|0
block|,
name|true
operator|=
literal|1
block|}
name|_Bool
expr_stmt|;
end_expr_stmt

begin_define
define|#
directive|define
name|bool
value|_Bool
end_define

begin_comment
comment|/* The other macros must be usable in preprocessor directives.  */
end_comment

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

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *  *  *  FIXUPS and CONVIENCE STUFF:  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|__cplusplus
end_ifdef

begin_define
define|#
directive|define
name|EXTERN
value|extern "C"
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|EXTERN
value|extern
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* some systems #def errno! and others do not declare it!! */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|errno
end_ifndef

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
comment|/* Some machines forget this! */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|EXIT_FAILURE
end_ifndef

begin_define
define|#
directive|define
name|EXIT_SUCCESS
value|0
end_define

begin_define
define|#
directive|define
name|EXIT_FAILURE
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|NUL
end_ifndef

begin_define
define|#
directive|define
name|NUL
value|'\0'
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

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|MAXPATHLEN
argument_list|)
operator|&&
name|defined
argument_list|(
name|HAVE_SYS_PARAM_H
argument_list|)
end_if

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
comment|/* !MAXPATHLEN&& HAVE_SYS_PARAM_H */
end_comment

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|MAXPATHLEN
argument_list|)
operator|&&
name|defined
argument_list|(
name|PATH_MAX
argument_list|)
end_if

begin_define
define|#
directive|define
name|MAXPATHLEN
value|PATH_MAX
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !MAXPATHLEN&& PATH_MAX */
end_comment

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|MAXPATHLEN
argument_list|)
operator|&&
name|defined
argument_list|(
name|_MAX_PATH
argument_list|)
end_if

begin_define
define|#
directive|define
name|PATH_MAX
value|_MAX_PATH
end_define

begin_define
define|#
directive|define
name|MAXPATHLEN
value|_MAX_PATH
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
name|MAXPATHLEN
argument_list|)
end_if

begin_define
define|#
directive|define
name|MAXPATHLEN
value|4096
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* MAXPATHLEN */
end_comment

begin_define
define|#
directive|define
name|AG_PATH_MAX
value|((size_t)MAXPATHLEN)
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|LONG_MAX
end_ifndef

begin_define
define|#
directive|define
name|LONG_MAX
value|~(1L<< (8*sizeof(long) -1))
end_define

begin_define
define|#
directive|define
name|INT_MAX
value|~(1<< (8*sizeof(int) -1))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|ULONG_MAX
end_ifndef

begin_define
define|#
directive|define
name|ULONG_MAX
value|~(OUL)
end_define

begin_define
define|#
directive|define
name|UINT_MAX
value|~(OU)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|SHORT_MAX
end_ifndef

begin_define
define|#
directive|define
name|SHORT_MAX
value|~(1<< (8*sizeof(short) - 1))
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|USHORT_MAX
value|~(OUS)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|HAVE_INT8_T
end_ifndef

begin_typedef
typedef|typedef
name|signed
name|char
name|int8_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|HAVE_INT8_T
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|HAVE_UINT8_T
end_ifndef

begin_typedef
typedef|typedef
name|unsigned
name|char
name|uint8_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|HAVE_UINT8_T
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|HAVE_INT16_T
end_ifndef

begin_typedef
typedef|typedef
name|signed
name|short
name|int16_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|HAVE_INT16_T
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|HAVE_UINT16_T
end_ifndef

begin_typedef
typedef|typedef
name|unsigned
name|short
name|uint16_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|HAVE_UINT16_T
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|HAVE_INT32_T
end_ifndef

begin_if
if|#
directive|if
name|SIZEOF_INT
operator|==
literal|4
end_if

begin_typedef
typedef|typedef
name|signed
name|int
name|int32_t
typedef|;
end_typedef

begin_elif
elif|#
directive|elif
name|SIZEOF_LONG
operator|==
literal|4
end_elif

begin_typedef
typedef|typedef
name|signed
name|long
name|int32_t
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|HAVE_INT32_T
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|HAVE_UINT32_T
end_ifndef

begin_if
if|#
directive|if
name|SIZEOF_INT
operator|==
literal|4
end_if

begin_typedef
typedef|typedef
name|unsigned
name|int
name|uint32_t
typedef|;
end_typedef

begin_elif
elif|#
directive|elif
name|SIZEOF_LONG
operator|==
literal|4
end_elif

begin_typedef
typedef|typedef
name|unsigned
name|long
name|uint32_t
typedef|;
end_typedef

begin_else
else|#
directive|else
end_else

begin_error
error|#
directive|error
error|Cannot create a uint32_t type.
end_error

begin_expr_stmt
name|Choke
name|Me
operator|.
endif|#
directive|endif
define|#
directive|define
name|HAVE_UINT32_T
value|1
endif|#
directive|endif
ifndef|#
directive|ifndef
name|HAVE_INTPTR_T
if|#
directive|if
name|SIZEOF_CHARP
operator|==
name|SIZEOF_LONG
expr|typedef
name|signed
name|long
name|intptr_t
expr_stmt|;
end_expr_stmt

begin_else
else|#
directive|else
end_else

begin_typedef
typedef|typedef
name|signed
name|int
name|intptr_t
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|HAVE_INTPTR_T
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|HAVE_UINTPTR_T
end_ifndef

begin_if
if|#
directive|if
name|SIZEOF_CHARP
operator|==
name|SIZEOF_LONG
end_if

begin_typedef
typedef|typedef
name|unsigned
name|long
name|intptr_t
typedef|;
end_typedef

begin_else
else|#
directive|else
end_else

begin_typedef
typedef|typedef
name|unsigned
name|int
name|intptr_t
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|HAVE_INTPTR_T
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|HAVE_UINT_T
end_ifndef

begin_typedef
typedef|typedef
name|unsigned
name|int
name|uint_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|HAVE_UINT_T
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

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
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|HAVE_WINT_T
end_ifndef

begin_typedef
typedef|typedef
name|unsigned
name|int
name|wint_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|HAVE_WINT_T
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|HAVE_PID_T
end_ifndef

begin_typedef
typedef|typedef
name|signed
name|int
name|pid_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|HAVE_PID_T
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* redefine these for BSD style string libraries */
end_comment

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

begin_ifdef
ifdef|#
directive|ifdef
name|USE_FOPEN_BINARY
end_ifdef

begin_ifndef
ifndef|#
directive|ifndef
name|FOPEN_BINARY_FLAG
end_ifndef

begin_define
define|#
directive|define
name|FOPEN_BINARY_FLAG
value|"b"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|FOPEN_TEXT_FLAG
end_ifndef

begin_define
define|#
directive|define
name|FOPEN_TEXT_FLAG
value|"t"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_else
else|#
directive|else
end_else

begin_ifndef
ifndef|#
directive|ifndef
name|FOPEN_BINARY_FLAG
end_ifndef

begin_define
define|#
directive|define
name|FOPEN_BINARY_FLAG
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|FOPEN_TEXT_FLAG
end_ifndef

begin_define
define|#
directive|define
name|FOPEN_TEXT_FLAG
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
name|STR
end_ifndef

begin_define
define|#
directive|define
name|_STR
parameter_list|(
name|s
parameter_list|)
value|#s
end_define

begin_define
define|#
directive|define
name|STR
parameter_list|(
name|s
parameter_list|)
value|_STR(s)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ##### Pointer sized word ##### */
end_comment

begin_comment
comment|/* FIXME:  the MAX stuff in here is broken! */
end_comment

begin_if
if|#
directive|if
name|SIZEOF_CHARP
operator|>
name|SIZEOF_INT
end_if

begin_typedef
typedef|typedef
name|long
name|t_word
typedef|;
end_typedef

begin_define
define|#
directive|define
name|WORD_MAX
value|LONG_MAX
end_define

begin_define
define|#
directive|define
name|WORD_MIN
value|LONG_MIN
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* SIZEOF_CHARP<= SIZEOF_INT */
end_comment

begin_typedef
typedef|typedef
name|int
name|t_word
typedef|;
end_typedef

begin_define
define|#
directive|define
name|WORD_MAX
value|INT_MAX
end_define

begin_define
define|#
directive|define
name|WORD_MIN
value|INT_MIN
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
comment|/* COMPAT_H_GUARD */
end_comment

begin_comment
comment|/*  * Local Variables:  * mode: C  * c-file-style: "stroustrup"  * indent-tabs-mode: nil  * End:  * end of compat/compat.h */
end_comment

end_unit

