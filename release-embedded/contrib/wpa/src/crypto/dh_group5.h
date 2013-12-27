begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Diffie-Hellman group 5 operations  * Copyright (c) 2009, 2012, Jouni Malinen<j@w1.fi>  *  * This software may be distributed under the terms of the BSD license.  * See README for more details.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|DH_GROUP5_H
end_ifndef

begin_define
define|#
directive|define
name|DH_GROUP5_H
end_define

begin_function_decl
name|void
modifier|*
name|dh5_init
parameter_list|(
name|struct
name|wpabuf
modifier|*
modifier|*
name|priv
parameter_list|,
name|struct
name|wpabuf
modifier|*
modifier|*
name|publ
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
modifier|*
name|dh5_init_fixed
parameter_list|(
specifier|const
name|struct
name|wpabuf
modifier|*
name|priv
parameter_list|,
specifier|const
name|struct
name|wpabuf
modifier|*
name|publ
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|wpabuf
modifier|*
name|dh5_derive_shared
parameter_list|(
name|void
modifier|*
name|ctx
parameter_list|,
specifier|const
name|struct
name|wpabuf
modifier|*
name|peer_public
parameter_list|,
specifier|const
name|struct
name|wpabuf
modifier|*
name|own_private
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|dh5_free
parameter_list|(
name|void
modifier|*
name|ctx
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* DH_GROUP5_H */
end_comment

end_unit

