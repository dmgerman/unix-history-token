begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1998 Mark Newton  * Copyright (c) 1994 Christos Zoulas  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. The name of the author may not be used to endorse or promote products  *    derived from this software without specific prior written permission  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_SVR4_DIRENT_H_
end_ifndef

begin_define
define|#
directive|define
name|_SVR4_DIRENT_H_
end_define

begin_define
define|#
directive|define
name|SVR4_MAXNAMLEN
value|512
end_define

begin_struct
struct|struct
name|svr4_dirent
block|{
name|svr4_ino_t
name|d_ino
decl_stmt|;
name|svr4_off_t
name|d_off
decl_stmt|;
name|u_short
name|d_reclen
decl_stmt|;
name|char
name|d_name
index|[
name|SVR4_MAXNAMLEN
operator|+
literal|1
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|svr4_dirent64
block|{
name|svr4_ino64_t
name|d_ino
decl_stmt|;
name|svr4_off64_t
name|d_off
decl_stmt|;
name|u_short
name|d_reclen
decl_stmt|;
name|char
name|d_name
index|[
name|SVR4_MAXNAMLEN
operator|+
literal|1
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|SVR4_NAMEOFF
parameter_list|(
name|dp
parameter_list|)
value|((char *)&(dp)->d_name - (char *)dp)
end_define

begin_define
define|#
directive|define
name|SVR4_RECLEN
parameter_list|(
name|de
parameter_list|,
name|namlen
parameter_list|)
value|ALIGN((SVR4_NAMEOFF(de) + (namlen) + 1))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_SVR4_DIRENT_H_ */
end_comment

end_unit

