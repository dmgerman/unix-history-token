begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * External password backend  * Copyright (c) 2012, Jouni Malinen<j@w1.fi>  *  * This software may be distributed under the terms of the BSD license.  * See README for more details.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|EXT_PASSWORD_H
end_ifndef

begin_define
define|#
directive|define
name|EXT_PASSWORD_H
end_define

begin_struct_decl
struct_decl|struct
name|ext_password_data
struct_decl|;
end_struct_decl

begin_ifdef
ifdef|#
directive|ifdef
name|CONFIG_EXT_PASSWORD
end_ifdef

begin_function_decl
name|struct
name|ext_password_data
modifier|*
name|ext_password_init
parameter_list|(
specifier|const
name|char
modifier|*
name|backend
parameter_list|,
specifier|const
name|char
modifier|*
name|params
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ext_password_deinit
parameter_list|(
name|struct
name|ext_password_data
modifier|*
name|data
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|wpabuf
modifier|*
name|ext_password_get
parameter_list|(
name|struct
name|ext_password_data
modifier|*
name|data
parameter_list|,
specifier|const
name|char
modifier|*
name|name
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ext_password_free
parameter_list|(
name|struct
name|wpabuf
modifier|*
name|pw
parameter_list|)
function_decl|;
end_function_decl

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* CONFIG_EXT_PASSWORD */
end_comment

begin_define
define|#
directive|define
name|ext_password_init
parameter_list|(
name|b
parameter_list|,
name|p
parameter_list|)
value|((void *) 1)
end_define

begin_define
define|#
directive|define
name|ext_password_deinit
parameter_list|(
name|d
parameter_list|)
value|do { } while (0)
end_define

begin_define
define|#
directive|define
name|ext_password_get
parameter_list|(
name|d
parameter_list|,
name|n
parameter_list|)
value|(NULL)
end_define

begin_define
define|#
directive|define
name|ext_password_free
parameter_list|(
name|p
parameter_list|)
value|do { } while (0)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* CONFIG_EXT_PASSWORD */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* EXT_PASSWORD_H */
end_comment

end_unit

