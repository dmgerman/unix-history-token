begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * EAP server method registration  * Copyright (c) 2004-2009, Jouni Malinen<j@w1.fi>  *  * This software may be distributed under the terms of the BSD license.  * See README for more details.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|EAP_SERVER_METHODS_H
end_ifndef

begin_define
define|#
directive|define
name|EAP_SERVER_METHODS_H
end_define

begin_include
include|#
directive|include
file|"eap_common/eap_defs.h"
end_include

begin_function_decl
specifier|const
name|struct
name|eap_method
modifier|*
name|eap_server_get_eap_method
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
name|struct
name|eap_method
modifier|*
name|eap_server_method_alloc
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
name|eap_server_method_free
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
name|eap_server_method_register
parameter_list|(
name|struct
name|eap_method
modifier|*
name|method
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|EapType
name|eap_server_get_type
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
name|void
name|eap_server_unregister_methods
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|const
name|char
modifier|*
name|eap_server_get_name
parameter_list|(
name|int
name|vendor
parameter_list|,
name|EapType
name|type
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* EAP server method registration calls for statically linked in methods */
end_comment

begin_function_decl
name|int
name|eap_server_identity_register
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|eap_server_md5_register
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|eap_server_tls_register
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|eap_server_unauth_tls_register
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|eap_server_mschapv2_register
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|eap_server_peap_register
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|eap_server_tlv_register
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|eap_server_gtc_register
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|eap_server_ttls_register
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|eap_server_sim_register
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|eap_server_aka_register
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|eap_server_aka_prime_register
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|eap_server_pax_register
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|eap_server_psk_register
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|eap_server_sake_register
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|eap_server_gpsk_register
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|eap_server_vendor_test_register
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|eap_server_fast_register
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|eap_server_wsc_register
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|eap_server_ikev2_register
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|eap_server_tnc_register
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|eap_server_pwd_register
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* EAP_SERVER_METHODS_H */
end_comment

end_unit

