begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1995 - 2000 Kungliga Tekniska Högskolan  * (Royal Institute of Technology, Stockholm, Sweden).  * All rights reserved.  *   * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  *   * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  *   * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *   * 3. Neither the name of the Institute nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *   * THIS SOFTWARE IS PROVIDED BY THE INSTITUTE AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE INSTITUTE OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
end_comment

begin_comment
comment|/* $Id: afssysdefs.h,v 1.24 2000/11/17 01:07:47 assar Exp $ */
end_comment

begin_comment
comment|/*  * This section is for machines using single entry point AFS syscalls!  * and/or  * This section is for machines using multiple entry point AFS syscalls!  *  * SunOS 4 is an example of single entry point and sgi of multiple  * entry point syscalls.  */
end_comment

begin_if
if|#
directive|if
name|SunOS
operator|==
literal|40
end_if

begin_define
define|#
directive|define
name|AFS_SYSCALL
value|31
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|SunOS
operator|>=
literal|50
operator|&&
name|SunOS
operator|<
literal|57
end_if

begin_define
define|#
directive|define
name|AFS_SYSCALL
value|105
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|SunOS
operator|==
literal|57
end_if

begin_define
define|#
directive|define
name|AFS_SYSCALL
value|73
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|SunOS
operator|>=
literal|58
end_if

begin_define
define|#
directive|define
name|AFS_SYSCALL
value|65
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
name|__hpux
argument_list|)
end_if

begin_define
define|#
directive|define
name|AFS_SYSCALL
value|50
end_define

begin_define
define|#
directive|define
name|AFS_SYSCALL2
value|49
end_define

begin_define
define|#
directive|define
name|AFS_SYSCALL3
value|48
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
name|_AIX
argument_list|)
end_if

begin_comment
comment|/* _AIX is too weird */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__sgi
argument_list|)
end_if

begin_define
define|#
directive|define
name|AFS_PIOCTL
value|(64+1000)
end_define

begin_define
define|#
directive|define
name|AFS_SETPAG
value|(65+1000)
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
name|__osf__
argument_list|)
end_if

begin_define
define|#
directive|define
name|AFS_SYSCALL
value|232
end_define

begin_define
define|#
directive|define
name|AFS_SYSCALL2
value|258
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
name|__ultrix
argument_list|)
end_if

begin_define
define|#
directive|define
name|AFS_SYSCALL
value|31
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
name|__FreeBSD__
argument_list|)
operator|||
name|defined
argument_list|(
name|__NetBSD__
argument_list|)
operator|||
name|defined
argument_list|(
name|__OpenBSD__
argument_list|)
end_if

begin_define
define|#
directive|define
name|AFS_SYSCALL
value|210
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|__APPLE__
end_ifdef

begin_comment
comment|/* MacOS X */
end_comment

begin_define
define|#
directive|define
name|AFS_SYSCALL
value|230
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|SYS_afs_syscall
end_ifdef

begin_define
define|#
directive|define
name|AFS_SYSCALL3
value|SYS_afs_syscall
end_define

begin_endif
endif|#
directive|endif
end_endif

end_unit

