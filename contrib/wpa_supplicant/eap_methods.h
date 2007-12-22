begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * EAP peer: Method registration  * Copyright (c) 2004-2006, Jouni Malinen<j@w1.fi>  *  * This program is free software; you can redistribute it and/or modify  * it under the terms of the GNU General Public License version 2 as  * published by the Free Software Foundation.  *  * Alternatively, this software may be distributed under the terms of BSD  * license.  *  * See README and COPYING for more details.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|EAP_METHODS_H
end_ifndef

begin_define
define|#
directive|define
name|EAP_METHODS_H
end_define

begin_include
include|#
directive|include
file|"eap_defs.h"
end_include

begin_function_decl
specifier|const
name|struct
name|eap_method
modifier|*
name|eap_sm_get_eap_methods
parameter_list|(
name|int
name|vendor
parameter_list|,
name|EapType
name|method
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|const
name|struct
name|eap_method
modifier|*
name|eap_peer_get_methods
parameter_list|(
name|size_t
modifier|*
name|count
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|eap_method
modifier|*
name|eap_peer_method_alloc
parameter_list|(
name|int
name|version
parameter_list|,
name|int
name|vendor
parameter_list|,
name|EapType
name|method
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
name|eap_peer_method_free
parameter_list|(
name|struct
name|eap_method
modifier|*
name|method
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|eap_peer_method_register
parameter_list|(
name|struct
name|eap_method
modifier|*
name|method
parameter_list|)
function_decl|;
end_function_decl

begin_ifdef
ifdef|#
directive|ifdef
name|IEEE8021X_EAPOL
end_ifdef

begin_function_decl
name|EapType
name|eap_get_type
parameter_list|(
specifier|const
name|char
modifier|*
name|name
parameter_list|,
name|int
modifier|*
name|vendor
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|const
name|char
modifier|*
name|eap_get_name
parameter_list|(
name|int
name|vendor
parameter_list|,
name|EapType
name|type
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|size_t
name|eap_get_names
parameter_list|(
name|char
modifier|*
name|buf
parameter_list|,
name|size_t
name|buflen
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
modifier|*
name|eap_get_names_as_string_array
parameter_list|(
name|size_t
modifier|*
name|num
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|eap_peer_register_methods
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|eap_peer_unregister_methods
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* IEEE8021X_EAPOL */
end_comment

begin_function
specifier|static
specifier|inline
name|EapType
name|eap_get_type
parameter_list|(
specifier|const
name|char
modifier|*
name|name
parameter_list|,
name|int
modifier|*
name|vendor
parameter_list|)
block|{
operator|*
name|vendor
operator|=
name|EAP_VENDOR_IETF
expr_stmt|;
return|return
name|EAP_TYPE_NONE
return|;
block|}
end_function

begin_function
specifier|static
specifier|inline
specifier|const
name|char
modifier|*
name|eap_get_name
parameter_list|(
name|int
name|vendor
parameter_list|,
name|EapType
name|type
parameter_list|)
block|{
return|return
name|NULL
return|;
block|}
end_function

begin_function
specifier|static
specifier|inline
name|size_t
name|eap_get_names
parameter_list|(
name|char
modifier|*
name|buf
parameter_list|,
name|size_t
name|buflen
parameter_list|)
block|{
return|return
literal|0
return|;
block|}
end_function

begin_function
specifier|static
specifier|inline
name|int
name|eap_peer_register_methods
parameter_list|(
name|void
parameter_list|)
block|{
return|return
literal|0
return|;
block|}
end_function

begin_function
specifier|static
specifier|inline
name|void
name|eap_peer_unregister_methods
parameter_list|(
name|void
parameter_list|)
block|{ }
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* IEEE8021X_EAPOL */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|CONFIG_DYNAMIC_EAP_METHODS
end_ifdef

begin_function_decl
name|int
name|eap_peer_method_load
parameter_list|(
specifier|const
name|char
modifier|*
name|so
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|eap_peer_method_unload
parameter_list|(
name|struct
name|eap_method
modifier|*
name|method
parameter_list|)
function_decl|;
end_function_decl

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* CONFIG_DYNAMIC_EAP_METHODS */
end_comment

begin_function
specifier|static
specifier|inline
name|int
name|eap_peer_method_load
parameter_list|(
specifier|const
name|char
modifier|*
name|so
parameter_list|)
block|{
return|return
literal|0
return|;
block|}
end_function

begin_function
specifier|static
specifier|inline
name|int
name|eap_peer_method_unload
parameter_list|(
name|struct
name|eap_method
modifier|*
name|method
parameter_list|)
block|{
return|return
literal|0
return|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* CONFIG_DYNAMIC_EAP_METHODS */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* EAP_METHODS_H */
end_comment

end_unit

