begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1995, 1996, 1997 Kungliga Tekniska Högskolan  * (Royal Institute of Technology, Stockholm, Sweden).  * All rights reserved.  *   * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  *   * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  *   * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *   * 3. Neither the name of the Institute nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *   * THIS SOFTWARE IS PROVIDED BY THE INSTITUTE AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE INSTITUTE OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
end_comment

begin_comment
comment|/* KClient.h - KClient glue to krb4.dll  * Author: Jörgen Karlsson - d93-jka@nada.kth.se  * Date: June 1996  */
end_comment

begin_comment
comment|/* $Id: KClient.h,v 1.8 1999/12/02 16:58:40 joda Exp $ */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|KCLIENT_H
end_ifndef

begin_define
define|#
directive|define
name|KCLIENT_H
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|MacOS
end_ifdef

begin_include
include|#
directive|include
file|<Types.h>
end_include

begin_typedef
typedef|typedef
name|OSerr
name|Kerr
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* MacOS */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|WIN32
end_ifdef

begin_comment
comment|/* Visual C++ 4.0 (Windows95/NT) */
end_comment

begin_typedef
typedef|typedef
name|int
name|Kerr
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* WIN32 */
end_comment

begin_enum
enum|enum
block|{
name|KClientLoggedIn
block|,
name|KClientNotLoggedIn
block|}
enum|;
end_enum

begin_struct
struct|struct
name|_KClientKey
block|{
name|unsigned
name|char
name|keyBytes
index|[
literal|8
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|_KClientKey
name|KClientKey
typedef|;
end_typedef

begin_struct
struct|struct
name|_KClientSessionInfo
block|{
name|unsigned
name|long
name|lAddr
decl_stmt|;
name|unsigned
name|short
name|lPort
decl_stmt|;
name|unsigned
name|long
name|fAddr
decl_stmt|;
name|unsigned
name|short
name|fPort
decl_stmt|;
name|char
name|user
index|[
literal|32
index|]
decl_stmt|;
name|char
name|inst
index|[
literal|32
index|]
decl_stmt|;
name|char
name|realm
index|[
literal|32
index|]
decl_stmt|;
name|char
name|key
index|[
literal|8
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|_KClientSessionInfo
name|KClientSessionInfo
typedef|;
end_typedef

begin_ifdef
ifdef|#
directive|ifdef
name|__cplusplus
end_ifdef

begin_extern
extern|extern
literal|"C"
block|{
endif|#
directive|endif
name|Kerr
name|KClientMessage
parameter_list|(
name|char
modifier|*
name|text
parameter_list|,
name|Kerr
name|error
parameter_list|)
function_decl|;
comment|/* KClientInitSession */
name|Kerr
name|KClientInitSession
parameter_list|(
name|KClientSessionInfo
modifier|*
name|session
parameter_list|,
name|unsigned
name|long
name|lAddr
parameter_list|,
name|unsigned
name|short
name|lPort
parameter_list|,
name|unsigned
name|long
name|fAddr
parameter_list|,
name|unsigned
name|short
name|fPort
parameter_list|)
function_decl|;
comment|/* KClientGetTicketForService */
name|Kerr
name|KClientGetTicketForService
parameter_list|(
name|KClientSessionInfo
modifier|*
name|session
parameter_list|,
name|char
modifier|*
name|service
parameter_list|,
name|void
modifier|*
name|buf
parameter_list|,
name|unsigned
name|long
modifier|*
name|buflen
parameter_list|)
function_decl|;
comment|/* KClientLogin	*/
name|Kerr
name|KClientLogin
parameter_list|(
name|KClientSessionInfo
modifier|*
name|session
parameter_list|,
name|KClientKey
modifier|*
name|privateKey
parameter_list|)
function_decl|;
comment|/* KClientPasswordLogin */
name|Kerr
name|KClientPasswordLogin
parameter_list|(
name|KClientSessionInfo
modifier|*
name|session
parameter_list|,
name|char
modifier|*
name|password
parameter_list|,
name|KClientKey
modifier|*
name|privateKey
parameter_list|)
function_decl|;
comment|/* KClientKeyLogin */
name|Kerr
name|KClientKeyLogin
parameter_list|(
name|KClientSessionInfo
modifier|*
name|session
parameter_list|,
name|KClientKey
modifier|*
name|privateKey
parameter_list|)
function_decl|;
comment|/* KClientLogout */
name|Kerr
name|KClientLogout
parameter_list|(
name|void
parameter_list|)
function_decl|;
comment|/* KClientStatus */
name|short
name|KClientStatus
parameter_list|(
name|KClientSessionInfo
modifier|*
name|session
parameter_list|)
function_decl|;
comment|/* KClientGetUserName */
name|Kerr
name|KClientGetUserName
parameter_list|(
name|char
modifier|*
name|user
parameter_list|)
function_decl|;
comment|/* KClientSetUserName */
name|Kerr
name|KClientSetUserName
parameter_list|(
name|char
modifier|*
name|user
parameter_list|)
function_decl|;
comment|/* KClientCacheInitialTicket */
name|Kerr
name|KClientCacheInitialTicket
parameter_list|(
name|KClientSessionInfo
modifier|*
name|session
parameter_list|,
name|char
modifier|*
name|service
parameter_list|)
function_decl|;
comment|/* KClientGetSessionKey */
name|Kerr
name|KClientGetSessionKey
parameter_list|(
name|KClientSessionInfo
modifier|*
name|session
parameter_list|,
name|KClientKey
modifier|*
name|sessionKey
parameter_list|)
function_decl|;
comment|/* KClientMakeSendAuth */
name|Kerr
name|KClientMakeSendAuth
parameter_list|(
name|KClientSessionInfo
modifier|*
name|session
parameter_list|,
name|char
modifier|*
name|service
parameter_list|,
name|void
modifier|*
name|buf
parameter_list|,
name|unsigned
name|long
modifier|*
name|buflen
parameter_list|,
name|long
name|checksum
parameter_list|,
name|char
modifier|*
name|applicationVersion
parameter_list|)
function_decl|;
comment|/* KClientVerifySendAuth */
name|Kerr
name|KClientVerifySendAuth
parameter_list|(
name|KClientSessionInfo
modifier|*
name|session
parameter_list|,
name|void
modifier|*
name|buf
parameter_list|,
name|unsigned
name|long
modifier|*
name|buflen
parameter_list|)
function_decl|;
comment|/* KClientEncrypt */
name|Kerr
name|KClientEncrypt
parameter_list|(
name|KClientSessionInfo
modifier|*
name|session
parameter_list|,
name|void
modifier|*
name|buf
parameter_list|,
name|unsigned
name|long
name|buflen
parameter_list|,
name|void
modifier|*
name|encryptBuf
parameter_list|,
name|unsigned
name|long
modifier|*
name|encryptLength
parameter_list|)
function_decl|;
comment|/* KClientDecrypt */
name|Kerr
name|KClientDecrypt
parameter_list|(
name|KClientSessionInfo
modifier|*
name|session
parameter_list|,
name|void
modifier|*
name|buf
parameter_list|,
name|unsigned
name|long
name|buflen
parameter_list|,
name|unsigned
name|long
modifier|*
name|decryptOffset
parameter_list|,
name|unsigned
name|long
modifier|*
name|decryptLength
parameter_list|)
function_decl|;
comment|/* KClientErrorText */
name|char
modifier|*
name|KClientErrorText
parameter_list|(
name|Kerr
name|err
parameter_list|,
name|char
modifier|*
name|text
parameter_list|)
function_decl|;
ifdef|#
directive|ifdef
name|__cplusplus
block|}
end_extern

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* KCLIENT_H */
end_comment

end_unit

