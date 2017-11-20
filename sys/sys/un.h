begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * SPDX-License-Identifier: BSD-3-Clause  *  * Copyright (c) 1982, 1986, 1993  *	The Regents of the University of California.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)un.h	8.3 (Berkeley) 2/19/95  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_SYS_UN_H_
end_ifndef

begin_define
define|#
directive|define
name|_SYS_UN_H_
end_define

begin_include
include|#
directive|include
file|<sys/cdefs.h>
end_include

begin_include
include|#
directive|include
file|<sys/_types.h>
end_include

begin_ifndef
ifndef|#
directive|ifndef
name|_SA_FAMILY_T_DECLARED
end_ifndef

begin_typedef
typedef|typedef
name|__sa_family_t
name|sa_family_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|_SA_FAMILY_T_DECLARED
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * Definitions for UNIX IPC domain.  */
end_comment

begin_struct
struct|struct
name|sockaddr_un
block|{
name|unsigned
name|char
name|sun_len
decl_stmt|;
comment|/* sockaddr len including null */
name|sa_family_t
name|sun_family
decl_stmt|;
comment|/* AF_UNIX */
name|char
name|sun_path
index|[
literal|104
index|]
decl_stmt|;
comment|/* path name (gag) */
block|}
struct|;
end_struct

begin_if
if|#
directive|if
name|__BSD_VISIBLE
end_if

begin_comment
comment|/* Socket options. */
end_comment

begin_define
define|#
directive|define
name|LOCAL_PEERCRED
value|1
end_define

begin_comment
comment|/* retrieve peer credentials */
end_comment

begin_define
define|#
directive|define
name|LOCAL_CREDS
value|2
end_define

begin_comment
comment|/* pass credentials to receiver */
end_comment

begin_define
define|#
directive|define
name|LOCAL_CONNWAIT
value|4
end_define

begin_comment
comment|/* connects block until accepted */
end_comment

begin_comment
comment|/* Start of reserved space for third-party socket options. */
end_comment

begin_define
define|#
directive|define
name|LOCAL_VENDOR
value|SO_VENDOR
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|_KERNEL
end_ifndef

begin_comment
comment|/* actual length of an initialized sockaddr_un */
end_comment

begin_define
define|#
directive|define
name|SUN_LEN
parameter_list|(
name|su
parameter_list|)
define|\
value|(sizeof(*(su)) - sizeof((su)->sun_path) + strlen((su)->sun_path))
end_define

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
comment|/* !_SYS_UN_H_ */
end_comment

end_unit

