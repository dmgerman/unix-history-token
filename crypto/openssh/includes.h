begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$OpenBSD: includes.h,v 1.17 2002/01/26 16:44:22 stevesk Exp $	*/
end_comment

begin_comment
comment|/*	$FreeBSD$	*/
end_comment

begin_comment
comment|/*  * Author: Tatu Ylonen<ylo@cs.hut.fi>  * Copyright (c) 1995 Tatu Ylonen<ylo@cs.hut.fi>, Espoo, Finland  *                    All rights reserved  * This file includes most of the needed system headers.  *  * As far as I am concerned, the code I have written for this software  * can be used freely for any purpose.  Any derived versions of this  * software must be clearly marked as such, and if the derived work is  * incompatible with the protocol description in the RFC file, it must be  * called by a name other than "ssh" or "Secure Shell".  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|INCLUDES_H
end_ifndef

begin_define
define|#
directive|define
name|INCLUDES_H
end_define

begin_define
define|#
directive|define
name|RCSID
parameter_list|(
name|msg
parameter_list|)
define|\
value|__RCSID(msg)
end_define

begin_include
include|#
directive|include
file|"config.h"
end_include

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_include
include|#
directive|include
file|<ctype.h>
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

begin_comment
comment|/* For O_NONBLOCK */
end_comment

begin_include
include|#
directive|include
file|<signal.h>
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
file|<stdarg.h>
end_include

begin_include
include|#
directive|include
file|<pwd.h>
end_include

begin_include
include|#
directive|include
file|<grp.h>
end_include

begin_include
include|#
directive|include
file|<time.h>
end_include

begin_include
include|#
directive|include
file|<dirent.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_LIMITS_H
end_ifdef

begin_include
include|#
directive|include
file|<limits.h>
end_include

begin_comment
comment|/* For PATH_MAX */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_GETOPT_H
end_ifdef

begin_include
include|#
directive|include
file|<getopt.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_BSTRING_H
end_ifdef

begin_include
include|#
directive|include
file|<bstring.h>
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
name|HAVE_GLOB_H
argument_list|)
operator|&&
name|defined
argument_list|(
name|GLOB_HAS_ALTDIRFUNC
argument_list|)
operator|&&
expr|\
name|defined
argument_list|(
name|GLOB_HAS_GL_MATCHC
argument_list|)
end_if

begin_include
include|#
directive|include
file|<glob.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_NETGROUP_H
end_ifdef

begin_include
include|#
directive|include
file|<netgroup.h>
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
name|HAVE_NETDB_H
argument_list|)
end_if

begin_include
include|#
directive|include
file|<netdb.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_ENDIAN_H
end_ifdef

begin_include
include|#
directive|include
file|<endian.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_TTYENT_H
end_ifdef

begin_include
include|#
directive|include
file|<ttyent.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_UTIME_H
end_ifdef

begin_include
include|#
directive|include
file|<utime.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_MAILLOCK_H
end_ifdef

begin_include
include|#
directive|include
file|<maillock.h>
end_include

begin_comment
comment|/* For _PATH_MAILDIR */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_NEXT
end_ifdef

begin_include
include|#
directive|include
file|<libc.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<unistd.h>
end_include

begin_comment
comment|/* For STDIN_FILENO, etc */
end_comment

begin_include
include|#
directive|include
file|<termios.h>
end_include

begin_comment
comment|/* Struct winsize */
end_comment

begin_comment
comment|/*  *-*-nto-qnx needs these headers for strcasecmp and LASTLOG_FILE respectively  */
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

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_LOGIN_H
end_ifdef

begin_include
include|#
directive|include
file|<login.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_UTMP_H
end_ifdef

begin_include
include|#
directive|include
file|<utmp.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_UTMPX_H
end_ifdef

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_TV_IN_UTMPX
end_ifdef

begin_include
include|#
directive|include
file|<sys/time.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<utmpx.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_LASTLOG_H
end_ifdef

begin_include
include|#
directive|include
file|<lastlog.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_PATHS_H
end_ifdef

begin_include
include|#
directive|include
file|<paths.h>
end_include

begin_comment
comment|/* For _PATH_XXX */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|<sys/socket.h>
end_include

begin_include
include|#
directive|include
file|<sys/ioctl.h>
end_include

begin_include
include|#
directive|include
file|<sys/wait.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_SYS_TIME_H
end_ifdef

begin_include
include|#
directive|include
file|<sys/time.h>
end_include

begin_comment
comment|/* For timersub */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<sys/resource.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_SYS_SELECT_H
end_ifdef

begin_include
include|#
directive|include
file|<sys/select.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_SYS_BSDTTY_H
end_ifdef

begin_include
include|#
directive|include
file|<sys/bsdtty.h>
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

begin_comment
comment|/* For MAXPATHLEN and roundup() */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_SYS_UN_H
end_ifdef

begin_include
include|#
directive|include
file|<sys/un.h>
end_include

begin_comment
comment|/* For sockaddr_un */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_STDINT_H
end_ifdef

begin_include
include|#
directive|include
file|<stdint.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_SYS_BITYPES_H
end_ifdef

begin_include
include|#
directive|include
file|<sys/bitypes.h>
end_include

begin_comment
comment|/* For u_intXX_t */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_SYS_CDEFS_H
end_ifdef

begin_include
include|#
directive|include
file|<sys/cdefs.h>
end_include

begin_comment
comment|/* For __P() */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_SYS_STAT_H
end_ifdef

begin_include
include|#
directive|include
file|<sys/stat.h>
end_include

begin_comment
comment|/* For S_* constants and macros */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_SYS_SYSMACROS_H
end_ifdef

begin_include
include|#
directive|include
file|<sys/sysmacros.h>
end_include

begin_comment
comment|/* For MIN, MAX, etc */
end_comment

begin_endif
endif|#
directive|endif
end_endif

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

begin_comment
comment|/* for MAP_ANONYMOUS */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<netinet/in_systm.h>
end_include

begin_comment
comment|/* For typedefs */
end_comment

begin_include
include|#
directive|include
file|<netinet/in.h>
end_include

begin_comment
comment|/* For IPv6 macros */
end_comment

begin_include
include|#
directive|include
file|<netinet/ip.h>
end_include

begin_comment
comment|/* For IPTOS macros */
end_comment

begin_include
include|#
directive|include
file|<netinet/tcp.h>
end_include

begin_include
include|#
directive|include
file|<arpa/inet.h>
end_include

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

begin_comment
comment|/* For INADDR_LOOPBACK */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|USE_PAM
end_ifdef

begin_include
include|#
directive|include
file|<security/pam_appl.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_READPASSPHRASE_H
end_ifdef

begin_include
include|#
directive|include
file|<readpassphrase.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_IA_H
end_ifdef

begin_include
include|#
directive|include
file|<ia.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_TMPDIR_H
end_ifdef

begin_include
include|#
directive|include
file|<tmpdir.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<openssl/opensslv.h>
end_include

begin_comment
comment|/* For OPENSSL_VERSION_NUMBER */
end_comment

begin_include
include|#
directive|include
file|"defines.h"
end_include

begin_include
include|#
directive|include
file|"version.h"
end_include

begin_include
include|#
directive|include
file|"openbsd-compat/openbsd-compat.h"
end_include

begin_include
include|#
directive|include
file|"openbsd-compat/bsd-cygwin_util.h"
end_include

begin_include
include|#
directive|include
file|"openbsd-compat/bsd-nextstep.h"
end_include

begin_include
include|#
directive|include
file|"entropy.h"
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* INCLUDES_H */
end_comment

end_unit

