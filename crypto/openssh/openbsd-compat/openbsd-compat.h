begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $Id: openbsd-compat.h,v 1.17 2002/09/12 00:33:02 djm Exp $ */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_OPENBSD_H
end_ifndef

begin_define
define|#
directive|define
name|_OPENBSD_H
end_define

begin_include
include|#
directive|include
file|"config.h"
end_include

begin_comment
comment|/* OpenBSD function replacements */
end_comment

begin_include
include|#
directive|include
file|"bindresvport.h"
end_include

begin_include
include|#
directive|include
file|"getcwd.h"
end_include

begin_include
include|#
directive|include
file|"realpath.h"
end_include

begin_include
include|#
directive|include
file|"rresvport.h"
end_include

begin_include
include|#
directive|include
file|"strlcpy.h"
end_include

begin_include
include|#
directive|include
file|"strlcat.h"
end_include

begin_include
include|#
directive|include
file|"strmode.h"
end_include

begin_include
include|#
directive|include
file|"mktemp.h"
end_include

begin_include
include|#
directive|include
file|"daemon.h"
end_include

begin_include
include|#
directive|include
file|"dirname.h"
end_include

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
file|"inet_ntoa.h"
end_include

begin_include
include|#
directive|include
file|"inet_ntop.h"
end_include

begin_include
include|#
directive|include
file|"strsep.h"
end_include

begin_include
include|#
directive|include
file|"setproctitle.h"
end_include

begin_include
include|#
directive|include
file|"getgrouplist.h"
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
file|"getopt.h"
end_include

begin_comment
comment|/* Home grown routines */
end_comment

begin_include
include|#
directive|include
file|"bsd-arc4random.h"
end_include

begin_include
include|#
directive|include
file|"bsd-getpeereid.h"
end_include

begin_include
include|#
directive|include
file|"bsd-misc.h"
end_include

begin_include
include|#
directive|include
file|"bsd-snprintf.h"
end_include

begin_include
include|#
directive|include
file|"bsd-waitpid.h"
end_include

begin_comment
comment|/* rfc2553 socket API replacements */
end_comment

begin_include
include|#
directive|include
file|"fake-getaddrinfo.h"
end_include

begin_include
include|#
directive|include
file|"fake-getnameinfo.h"
end_include

begin_include
include|#
directive|include
file|"fake-socket.h"
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
file|"port-irix.h"
end_include

begin_include
include|#
directive|include
file|"port-aix.h"
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _OPENBSD_H */
end_comment

end_unit

