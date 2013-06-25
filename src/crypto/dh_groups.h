begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Diffie-Hellman groups  * Copyright (c) 2007, Jouni Malinen<j@w1.fi>  *  * This software may be distributed under the terms of the BSD license.  * See README for more details.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|DH_GROUPS_H
end_ifndef

begin_define
define|#
directive|define
name|DH_GROUPS_H
end_define

begin_struct
struct|struct
name|dh_group
block|{
name|int
name|id
decl_stmt|;
specifier|const
name|u8
modifier|*
name|generator
decl_stmt|;
name|size_t
name|generator_len
decl_stmt|;
specifier|const
name|u8
modifier|*
name|prime
decl_stmt|;
name|size_t
name|prime_len
decl_stmt|;
block|}
struct|;
end_struct

begin_function_decl
specifier|const
name|struct
name|dh_group
modifier|*
name|dh_groups_get
parameter_list|(
name|int
name|id
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|wpabuf
modifier|*
name|dh_init
parameter_list|(
specifier|const
name|struct
name|dh_group
modifier|*
name|dh
parameter_list|,
name|struct
name|wpabuf
modifier|*
modifier|*
name|priv
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|wpabuf
modifier|*
name|dh_derive_shared
parameter_list|(
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
parameter_list|,
specifier|const
name|struct
name|dh_group
modifier|*
name|dh
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* DH_GROUPS_H */
end_comment

end_unit

