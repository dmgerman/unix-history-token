begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * EAP-IKEv2 definitions  * Copyright (c) 2007, Jouni Malinen<j@w1.fi>  *  * This program is free software; you can redistribute it and/or modify  * it under the terms of the GNU General Public License version 2 as  * published by the Free Software Foundation.  *  * Alternatively, this software may be distributed under the terms of BSD  * license.  *  * See README and COPYING for more details.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|EAP_IKEV2_COMMON_H
end_ifndef

begin_define
define|#
directive|define
name|EAP_IKEV2_COMMON_H
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|CCNS_PL
end_ifdef

begin_comment
comment|/* incorrect bit order */
end_comment

begin_define
define|#
directive|define
name|IKEV2_FLAGS_LENGTH_INCLUDED
value|0x01
end_define

begin_define
define|#
directive|define
name|IKEV2_FLAGS_MORE_FRAGMENTS
value|0x02
end_define

begin_define
define|#
directive|define
name|IKEV2_FLAGS_ICV_INCLUDED
value|0x04
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* CCNS_PL */
end_comment

begin_define
define|#
directive|define
name|IKEV2_FLAGS_LENGTH_INCLUDED
value|0x80
end_define

begin_define
define|#
directive|define
name|IKEV2_FLAGS_MORE_FRAGMENTS
value|0x40
end_define

begin_define
define|#
directive|define
name|IKEV2_FLAGS_ICV_INCLUDED
value|0x20
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* CCNS_PL */
end_comment

begin_define
define|#
directive|define
name|IKEV2_FRAGMENT_SIZE
value|1400
end_define

begin_struct_decl
struct_decl|struct
name|ikev2_keys
struct_decl|;
end_struct_decl

begin_function_decl
name|int
name|eap_ikev2_derive_keymat
parameter_list|(
name|int
name|prf
parameter_list|,
name|struct
name|ikev2_keys
modifier|*
name|keys
parameter_list|,
specifier|const
name|u8
modifier|*
name|i_nonce
parameter_list|,
name|size_t
name|i_nonce_len
parameter_list|,
specifier|const
name|u8
modifier|*
name|r_nonce
parameter_list|,
name|size_t
name|r_nonce_len
parameter_list|,
name|u8
modifier|*
name|keymat
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|wpabuf
modifier|*
name|eap_ikev2_build_frag_ack
parameter_list|(
name|u8
name|id
parameter_list|,
name|u8
name|code
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|eap_ikev2_validate_icv
parameter_list|(
name|int
name|integ_alg
parameter_list|,
name|struct
name|ikev2_keys
modifier|*
name|keys
parameter_list|,
name|int
name|initiator
parameter_list|,
specifier|const
name|struct
name|wpabuf
modifier|*
name|msg
parameter_list|,
specifier|const
name|u8
modifier|*
name|pos
parameter_list|,
specifier|const
name|u8
modifier|*
name|end
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* EAP_IKEV2_COMMON_H */
end_comment

end_unit

