begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $Id: openbsd-compat.h,v 1.33 2005/12/31 05:33:37 djm Exp $ */
end_comment

begin_comment
comment|/*  * Copyright (c) 1999-2003 Damien Miller.  All rights reserved.  * Copyright (c) 2003 Ben Lindstrom. All rights reserved.  * Copyright (c) 2002 Tim Rice.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_OPENBSD_COMPAT_H
end_ifndef

begin_define
define|#
directive|define
name|_OPENBSD_COMPAT_H
end_define

begin_include
include|#
directive|include
file|"includes.h"
end_include

begin_comment
comment|/* OpenBSD function replacements */
end_comment

begin_include
include|#
directive|include
file|"base64.h"
end_include

begin_include
include|#
directive|include
file|"sigact.h"
end_include

begin_include
include|#
directive|include
file|"glob.h"
end_include

begin_include
include|#
directive|include
file|"readpassphrase.h"
end_include

begin_include
include|#
directive|include
file|"vis.h"
end_include

begin_include
include|#
directive|include
file|"getrrsetbyname.h"
end_include

begin_ifndef
ifndef|#
directive|ifndef
name|HAVE_BASENAME
end_ifndef

begin_function_decl
name|char
modifier|*
name|basename
parameter_list|(
specifier|const
name|char
modifier|*
name|path
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
name|HAVE_BINDRESVPORT_SA
end_ifndef

begin_function_decl
name|int
name|bindresvport_sa
parameter_list|(
name|int
name|sd
parameter_list|,
name|struct
name|sockaddr
modifier|*
name|sa
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
name|HAVE_CLOSEFROM
end_ifndef

begin_function_decl
name|void
name|closefrom
parameter_list|(
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
name|HAVE_GETCWD
end_ifndef

begin_function_decl
name|char
modifier|*
name|getcwd
parameter_list|(
name|char
modifier|*
name|pt
parameter_list|,
name|size_t
name|size
parameter_list|)
function_decl|;
end_function_decl

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
name|HAVE_REALPATH
argument_list|)
operator|||
name|defined
argument_list|(
name|BROKEN_REALPATH
argument_list|)
end_if

begin_function_decl
name|char
modifier|*
name|realpath
parameter_list|(
specifier|const
name|char
modifier|*
name|path
parameter_list|,
name|char
modifier|*
name|resolved
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
name|HAVE_RRESVPORT_AF
end_ifndef

begin_function_decl
name|int
name|rresvport_af
parameter_list|(
name|int
modifier|*
name|alport
parameter_list|,
name|sa_family_t
name|af
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
name|HAVE_STRLCPY
end_ifndef

begin_comment
comment|/* #include<sys/types.h> XXX Still needed? */
end_comment

begin_function_decl
name|size_t
name|strlcpy
parameter_list|(
name|char
modifier|*
name|dst
parameter_list|,
specifier|const
name|char
modifier|*
name|src
parameter_list|,
name|size_t
name|siz
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
name|HAVE_STRLCAT
end_ifndef

begin_comment
comment|/* #include<sys/types.h> XXX Still needed? */
end_comment

begin_function_decl
name|size_t
name|strlcat
parameter_list|(
name|char
modifier|*
name|dst
parameter_list|,
specifier|const
name|char
modifier|*
name|src
parameter_list|,
name|size_t
name|siz
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
name|HAVE_SETENV
end_ifndef

begin_function_decl
name|int
name|setenv
parameter_list|(
specifier|register
specifier|const
name|char
modifier|*
name|name
parameter_list|,
specifier|register
specifier|const
name|char
modifier|*
name|value
parameter_list|,
name|int
name|rewrite
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
name|HAVE_STRMODE
end_ifndef

begin_function_decl
name|void
name|strmode
parameter_list|(
name|int
name|mode
parameter_list|,
name|char
modifier|*
name|p
parameter_list|)
function_decl|;
end_function_decl

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
name|HAVE_MKDTEMP
argument_list|)
operator|||
name|defined
argument_list|(
name|HAVE_STRICT_MKSTEMP
argument_list|)
end_if

begin_function_decl
name|int
name|mkstemps
parameter_list|(
name|char
modifier|*
name|path
parameter_list|,
name|int
name|slen
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|mkstemp
parameter_list|(
name|char
modifier|*
name|path
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
name|path
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
name|HAVE_DAEMON
end_ifndef

begin_function_decl
name|int
name|daemon
parameter_list|(
name|int
name|nochdir
parameter_list|,
name|int
name|noclose
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
name|HAVE_DIRNAME
end_ifndef

begin_function_decl
name|char
modifier|*
name|dirname
parameter_list|(
specifier|const
name|char
modifier|*
name|path
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|BROKEN_INET_NTOA
argument_list|)
operator|||
operator|!
name|defined
argument_list|(
name|HAVE_INET_NTOA
argument_list|)
end_if

begin_function_decl
name|char
modifier|*
name|inet_ntoa
parameter_list|(
name|struct
name|in_addr
name|in
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
name|HAVE_INET_NTOP
end_ifndef

begin_function_decl
specifier|const
name|char
modifier|*
name|inet_ntop
parameter_list|(
name|int
name|af
parameter_list|,
specifier|const
name|void
modifier|*
name|src
parameter_list|,
name|char
modifier|*
name|dst
parameter_list|,
name|size_t
name|size
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
name|HAVE_INET_ATON
end_ifndef

begin_function_decl
name|int
name|inet_aton
parameter_list|(
specifier|const
name|char
modifier|*
name|cp
parameter_list|,
name|struct
name|in_addr
modifier|*
name|addr
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
name|HAVE_STRSEP
end_ifndef

begin_function_decl
name|char
modifier|*
name|strsep
parameter_list|(
name|char
modifier|*
modifier|*
name|stringp
parameter_list|,
specifier|const
name|char
modifier|*
name|delim
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
name|HAVE_SETPROCTITLE
end_ifndef

begin_function_decl
name|void
name|setproctitle
parameter_list|(
specifier|const
name|char
modifier|*
name|fmt
parameter_list|,
modifier|...
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|compat_init_setproctitle
parameter_list|(
name|int
name|argc
parameter_list|,
name|char
modifier|*
name|argv
index|[]
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
name|HAVE_GETGROUPLIST
end_ifndef

begin_comment
comment|/* #include<grp.h> XXXX Still needed ? */
end_comment

begin_function_decl
name|int
name|getgrouplist
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
name|gid_t
parameter_list|,
name|gid_t
modifier|*
parameter_list|,
name|int
modifier|*
parameter_list|)
function_decl|;
end_function_decl

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
name|HAVE_GETOPT
argument_list|)
operator|||
operator|!
name|defined
argument_list|(
name|HAVE_GETOPT_OPTRESET
argument_list|)
end_if

begin_function_decl
name|int
name|BSDgetopt
parameter_list|(
name|int
name|argc
parameter_list|,
name|char
modifier|*
specifier|const
modifier|*
name|argv
parameter_list|,
specifier|const
name|char
modifier|*
name|opts
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Home grown routines */
end_comment

begin_include
include|#
directive|include
file|"bsd-misc.h"
end_include

begin_include
include|#
directive|include
file|"bsd-waitpid.h"
end_include

begin_comment
comment|/*#include<sys/types.h> XXX Still needed? * For uid_t, gid_t * */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|HAVE_GETPEEREID
end_ifndef

begin_function_decl
name|int
name|getpeereid
parameter_list|(
name|int
parameter_list|,
name|uid_t
modifier|*
parameter_list|,
name|gid_t
modifier|*
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
name|HAVE_ARC4RANDOM
end_ifndef

begin_function_decl
name|unsigned
name|int
name|arc4random
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|arc4random_stir
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
comment|/* !HAVE_ARC4RANDOM */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|HAVE_ASPRINTF
end_ifndef

begin_function_decl
name|int
name|asprintf
parameter_list|(
name|char
modifier|*
modifier|*
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

begin_ifndef
ifndef|#
directive|ifndef
name|HAVE_OPENPTY
end_ifndef

begin_function_decl
name|int
name|openpty
parameter_list|(
name|int
modifier|*
parameter_list|,
name|int
modifier|*
parameter_list|,
name|char
modifier|*
parameter_list|,
name|struct
name|termios
modifier|*
parameter_list|,
name|struct
name|winsize
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* HAVE_OPENPTY */
end_comment

begin_comment
comment|/* #include<sys/types.h> XXX needed? For size_t */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|HAVE_SNPRINTF
end_ifndef

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

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|HAVE_STRTOLL
end_ifndef

begin_function_decl
name|long
name|long
name|strtoll
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
name|char
modifier|*
modifier|*
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
name|HAVE_STRTONUM
end_ifndef

begin_function_decl
name|long
name|long
name|strtonum
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
name|long
name|long
parameter_list|,
name|long
name|long
parameter_list|,
specifier|const
name|char
modifier|*
modifier|*
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
name|HAVE_VASPRINTF
end_ifndef

begin_function_decl
name|int
name|vasprintf
parameter_list|(
name|char
modifier|*
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
name|va_list
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
name|HAVE_VSNPRINTF
end_ifndef

begin_function_decl
name|int
name|vsnprintf
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
name|va_list
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_function_decl
name|void
modifier|*
name|xmmap
parameter_list|(
name|size_t
name|size
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|xcrypt
parameter_list|(
specifier|const
name|char
modifier|*
name|password
parameter_list|,
specifier|const
name|char
modifier|*
name|salt
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|shadow_pw
parameter_list|(
name|struct
name|passwd
modifier|*
name|pw
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* rfc2553 socket API replacements */
end_comment

begin_include
include|#
directive|include
file|"fake-rfc2553.h"
end_include

begin_comment
comment|/* Routines for a single OS platform */
end_comment

begin_include
include|#
directive|include
file|"bsd-cray.h"
end_include

begin_include
include|#
directive|include
file|"bsd-cygwin_util.h"
end_include

begin_include
include|#
directive|include
file|"port-irix.h"
end_include

begin_include
include|#
directive|include
file|"port-aix.h"
end_include

begin_include
include|#
directive|include
file|"port-uw.h"
end_include

begin_include
include|#
directive|include
file|"port-tun.h"
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _OPENBSD_COMPAT_H */
end_comment

end_unit

