begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright 1999 Internet Business Solutions Ltd., Switzerland  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_struct
struct|struct
name|radius
block|{
name|struct
name|fdescriptor
name|desc
decl_stmt|;
comment|/* We're a sort of (selectable) fdescriptor */
struct|struct
block|{
name|int
name|fd
decl_stmt|;
comment|/* We're selecting on this */
name|struct
name|rad_handle
modifier|*
name|rad
decl_stmt|;
comment|/* Using this to talk to our lib */
name|struct
name|pppTimer
name|timer
decl_stmt|;
comment|/* for this long */
name|struct
name|authinfo
modifier|*
name|auth
decl_stmt|;
comment|/* Tell this about success/failure */
block|}
name|cx
struct|;
name|unsigned
name|valid
range|:
literal|1
decl_stmt|;
comment|/* Is this structure valid ? */
name|unsigned
name|vj
range|:
literal|1
decl_stmt|;
comment|/* FRAMED Compression */
name|struct
name|in_addr
name|ip
decl_stmt|;
comment|/* FRAMED IP */
name|struct
name|in_addr
name|mask
decl_stmt|;
comment|/* FRAMED Netmask */
name|unsigned
name|long
name|mtu
decl_stmt|;
comment|/* FRAMED MTU */
name|struct
name|sticky_route
modifier|*
name|routes
decl_stmt|;
comment|/* FRAMED Routes */
struct|struct
block|{
name|char
name|file
index|[
name|PATH_MAX
index|]
decl_stmt|;
comment|/* Radius config file */
block|}
name|cfg
struct|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|radacct
block|{
name|struct
name|radius
modifier|*
name|rad_parent
decl_stmt|;
comment|/* "Parent" struct radius stored in bundle */
name|char
name|user_name
index|[
name|AUTHLEN
index|]
decl_stmt|;
comment|/* Session User-Name */
name|char
name|session_id
index|[
literal|256
index|]
decl_stmt|;
comment|/* Unique session ID */
name|char
name|multi_session_id
index|[
literal|51
index|]
decl_stmt|;
comment|/* Unique MP session ID */
name|int
name|authentic
decl_stmt|;
comment|/* How the session has been authenticated */
name|struct
name|in_addr
name|ip
decl_stmt|;
name|struct
name|in_addr
name|mask
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|descriptor2radius
parameter_list|(
name|d
parameter_list|)
define|\
value|((d)->type == RADIUS_DESCRIPTOR ? (struct radius *)(d) : NULL)
end_define

begin_struct_decl
struct_decl|struct
name|bundle
struct_decl|;
end_struct_decl

begin_function_decl
specifier|extern
name|void
name|radius_Init
parameter_list|(
name|struct
name|radius
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|radius_Destroy
parameter_list|(
name|struct
name|radius
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|radius_Show
parameter_list|(
name|struct
name|radius
modifier|*
parameter_list|,
name|struct
name|prompt
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|radius_Authenticate
parameter_list|(
name|struct
name|radius
modifier|*
parameter_list|,
name|struct
name|authinfo
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
name|int
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|radius_Account
parameter_list|(
name|struct
name|radius
modifier|*
parameter_list|,
name|struct
name|radacct
modifier|*
parameter_list|,
name|struct
name|datalink
modifier|*
parameter_list|,
name|int
parameter_list|,
name|struct
name|in_addr
modifier|*
parameter_list|,
name|struct
name|in_addr
modifier|*
parameter_list|,
name|struct
name|pppThroughput
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* An (int) parameter to radius_Account, from radlib.h */
end_comment

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|RAD_START
argument_list|)
end_if

begin_define
define|#
directive|define
name|RAD_START
value|1
end_define

begin_define
define|#
directive|define
name|RAD_STOP
value|2
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Get address from NAS pool */
end_comment

begin_define
define|#
directive|define
name|RADIUS_INADDR_POOL
value|htonl(0xfffffffe)
end_define

begin_comment
comment|/* 255.255.255.254 */
end_comment

end_unit

