begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1995, 1996, 1997 Kungliga Tekniska Högskolan  * (Royal Institute of Technology, Stockholm, Sweden).  * All rights reserved.  *   * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  *   * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  *   * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *   * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *      This product includes software developed by the Kungliga Tekniska  *      Högskolan and its contributors.  *   * 4. Neither the name of the Institute nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *   * THIS SOFTWARE IS PROVIDED BY THE INSTITUTE AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE INSTITUTE OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
end_comment

begin_comment
comment|/* $Id: kafs_locl.h,v 1.3 1997/05/04 23:04:44 assar Exp $ */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__KAFS_LOCL_H__
end_ifndef

begin_define
define|#
directive|define
name|__KAFS_LOCL_H__
end_define

begin_include
include|#
directive|include
file|<config.h>
end_include

begin_include
include|#
directive|include
file|<protos.h>
end_include

begin_include
include|#
directive|include
file|<stdio.h>
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
file|<signal.h>
end_include

begin_include
include|#
directive|include
file|<setjmp.h>
end_include

begin_include
include|#
directive|include
file|<errno.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_SYS_TYPES_H
end_ifdef

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_UNISTD_H
end_ifdef

begin_include
include|#
directive|include
file|<unistd.h>
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
name|HAVE_SYS_IOCTL_H
argument_list|)
operator|&&
name|SunOS
operator|!=
literal|4
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

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_SYS_FILIO_H
end_ifdef

begin_include
include|#
directive|include
file|<sys/filio.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

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

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_ARPA_NAMESER_H
end_ifdef

begin_include
include|#
directive|include
file|<arpa/nameser.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

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

begin_include
include|#
directive|include
file|<roken.h>
end_include

begin_include
include|#
directive|include
file|<krb.h>
end_include

begin_include
include|#
directive|include
file|<kafs.h>
end_include

begin_include
include|#
directive|include
file|<resolve.h>
end_include

begin_include
include|#
directive|include
file|"afssysdefs.h"
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __KAFS_LOCL_H__ */
end_comment

end_unit

