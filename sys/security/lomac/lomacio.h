begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2001 Networks Associates Technology, Inc.  * All rights reserved.  *  * This software was developed for the FreeBSD Project by NAI Labs, the  * Security Research Division of Network Associates, Inc. under  * DARPA/SPAWAR contract N66001-01-C-8035 ("CBOSS"), as part of the DARPA  * CHATS research program.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. The name of the author may not be used to endorse or promote  *    products derived from this software without specific prior written  *    permission.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $Id$  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|LOMACIO_H
end_ifndef

begin_define
define|#
directive|define
name|LOMACIO_H
end_define

begin_include
include|#
directive|include
file|<sys/ioccom.h>
end_include

begin_include
include|#
directive|include
file|<sys/param.h>
end_include

begin_struct
struct|struct
name|lomac_fioctl
block|{
name|char
name|path
index|[
name|MAXPATHLEN
index|]
decl_stmt|;
name|int
name|level
decl_stmt|;
comment|/* LOMAC security level */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|lomac_fioctl2
block|{
name|char
name|path
index|[
name|MAXPATHLEN
index|]
decl_stmt|;
name|int
name|level
decl_stmt|;
comment|/* LOMAC security level */
name|int
name|flags
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|LIOGETPLEVEL
value|_IOWR('L', 0, int)
end_define

begin_comment
comment|/* get process level */
end_comment

begin_define
define|#
directive|define
name|LIOGETFLEVEL
value|_IOWR('L', 1, struct lomac_fioctl)
end_define

begin_comment
comment|/* get file level */
end_comment

begin_define
define|#
directive|define
name|LIOGETFLATTR
value|_IOWR('L', 3, struct lomac_fioctl2)
end_define

begin_comment
comment|/* get file level */
end_comment

begin_define
define|#
directive|define
name|LIOPMAKELOWLEVEL
value|_IO('L', 2)
end_define

begin_comment
comment|/* lower proc's level */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* LOMACIO_H */
end_comment

end_unit

