begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * External password backend - internal definitions  * Copyright (c) 2012, Jouni Malinen<j@w1.fi>  *  * This software may be distributed under the terms of the BSD license.  * See README for more details.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|EXT_PASSWORD_I_H
end_ifndef

begin_define
define|#
directive|define
name|EXT_PASSWORD_I_H
end_define

begin_include
include|#
directive|include
file|"ext_password.h"
end_include

begin_struct
struct|struct
name|ext_password_backend
block|{
specifier|const
name|char
modifier|*
name|name
decl_stmt|;
name|void
modifier|*
function_decl|(
modifier|*
name|init
function_decl|)
parameter_list|(
specifier|const
name|char
modifier|*
name|params
parameter_list|)
function_decl|;
name|void
function_decl|(
modifier|*
name|deinit
function_decl|)
parameter_list|(
name|void
modifier|*
name|ctx
parameter_list|)
function_decl|;
name|struct
name|wpabuf
modifier|*
function_decl|(
modifier|*
name|get
function_decl|)
parameter_list|(
name|void
modifier|*
name|ctx
parameter_list|,
specifier|const
name|char
modifier|*
name|name
parameter_list|)
function_decl|;
block|}
struct|;
end_struct

begin_function_decl
name|struct
name|wpabuf
modifier|*
name|ext_password_alloc
parameter_list|(
name|size_t
name|len
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* EXT_PASSWORD_I_H */
end_comment

end_unit

