begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $OpenBSD: key.h,v 1.42 2014/06/24 01:13:21 djm Exp $ */
end_comment

begin_comment
comment|/*  * Copyright (c) 2000, 2001 Markus Friedl.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|KEY_H
end_ifndef

begin_define
define|#
directive|define
name|KEY_H
end_define

begin_include
include|#
directive|include
file|"sshkey.h"
end_include

begin_typedef
typedef|typedef
name|struct
name|sshkey
name|Key
typedef|;
end_typedef

begin_define
define|#
directive|define
name|types
value|sshkey_types
end_define

begin_define
define|#
directive|define
name|fp_type
value|sshkey_fp_type
end_define

begin_define
define|#
directive|define
name|fp_rep
value|sshkey_fp_rep
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|SSH_KEY_NO_DEFINE
end_ifndef

begin_define
define|#
directive|define
name|key_new
value|sshkey_new
end_define

begin_define
define|#
directive|define
name|key_free
value|sshkey_free
end_define

begin_define
define|#
directive|define
name|key_equal_public
value|sshkey_equal_public
end_define

begin_define
define|#
directive|define
name|key_equal
value|sshkey_equal
end_define

begin_define
define|#
directive|define
name|key_fingerprint
value|sshkey_fingerprint
end_define

begin_define
define|#
directive|define
name|key_type
value|sshkey_type
end_define

begin_define
define|#
directive|define
name|key_cert_type
value|sshkey_cert_type
end_define

begin_define
define|#
directive|define
name|key_ssh_name
value|sshkey_ssh_name
end_define

begin_define
define|#
directive|define
name|key_ssh_name_plain
value|sshkey_ssh_name_plain
end_define

begin_define
define|#
directive|define
name|key_type_from_name
value|sshkey_type_from_name
end_define

begin_define
define|#
directive|define
name|key_ecdsa_nid_from_name
value|sshkey_ecdsa_nid_from_name
end_define

begin_define
define|#
directive|define
name|key_type_is_cert
value|sshkey_type_is_cert
end_define

begin_define
define|#
directive|define
name|key_size
value|sshkey_size
end_define

begin_define
define|#
directive|define
name|key_ecdsa_bits_to_nid
value|sshkey_ecdsa_bits_to_nid
end_define

begin_define
define|#
directive|define
name|key_ecdsa_key_to_nid
value|sshkey_ecdsa_key_to_nid
end_define

begin_define
define|#
directive|define
name|key_names_valid2
value|sshkey_names_valid2
end_define

begin_define
define|#
directive|define
name|key_is_cert
value|sshkey_is_cert
end_define

begin_define
define|#
directive|define
name|key_type_plain
value|sshkey_type_plain
end_define

begin_define
define|#
directive|define
name|key_cert_is_legacy
value|sshkey_cert_is_legacy
end_define

begin_define
define|#
directive|define
name|key_curve_name_to_nid
value|sshkey_curve_name_to_nid
end_define

begin_define
define|#
directive|define
name|key_curve_nid_to_bits
value|sshkey_curve_nid_to_bits
end_define

begin_define
define|#
directive|define
name|key_curve_nid_to_name
value|sshkey_curve_nid_to_name
end_define

begin_define
define|#
directive|define
name|key_ec_nid_to_hash_alg
value|sshkey_ec_nid_to_hash_alg
end_define

begin_define
define|#
directive|define
name|key_dump_ec_point
value|sshkey_dump_ec_point
end_define

begin_define
define|#
directive|define
name|key_dump_ec_key
value|sshkey_dump_ec_key
end_define

begin_define
define|#
directive|define
name|key_fingerprint
value|sshkey_fingerprint
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_function_decl
name|void
name|key_add_private
parameter_list|(
name|Key
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|Key
modifier|*
name|key_new_private
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|key_free
parameter_list|(
name|Key
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|Key
modifier|*
name|key_demote
parameter_list|(
specifier|const
name|Key
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|u_char
modifier|*
name|key_fingerprint_raw
parameter_list|(
specifier|const
name|Key
modifier|*
parameter_list|,
name|enum
name|fp_type
parameter_list|,
name|u_int
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|key_write
parameter_list|(
specifier|const
name|Key
modifier|*
parameter_list|,
name|FILE
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|key_read
parameter_list|(
name|Key
modifier|*
parameter_list|,
name|char
modifier|*
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|Key
modifier|*
name|key_generate
parameter_list|(
name|int
parameter_list|,
name|u_int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|Key
modifier|*
name|key_from_private
parameter_list|(
specifier|const
name|Key
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|key_to_certified
parameter_list|(
name|Key
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|key_drop_cert
parameter_list|(
name|Key
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|key_certify
parameter_list|(
name|Key
modifier|*
parameter_list|,
name|Key
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|key_cert_copy
parameter_list|(
specifier|const
name|Key
modifier|*
parameter_list|,
name|Key
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|key_cert_check_authority
parameter_list|(
specifier|const
name|Key
modifier|*
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|key_alg_list
parameter_list|(
name|int
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_if
if|#
directive|if
name|defined
argument_list|(
name|WITH_OPENSSL
argument_list|)
operator|&&
name|defined
argument_list|(
name|OPENSSL_HAS_ECC
argument_list|)
end_if

begin_function_decl
name|int
name|key_ec_validate_public
parameter_list|(
specifier|const
name|EC_GROUP
modifier|*
parameter_list|,
specifier|const
name|EC_POINT
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|key_ec_validate_private
parameter_list|(
specifier|const
name|EC_KEY
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* defined(WITH_OPENSSL)&& defined(OPENSSL_HAS_ECC) */
end_comment

begin_function_decl
name|Key
modifier|*
name|key_from_blob
parameter_list|(
specifier|const
name|u_char
modifier|*
parameter_list|,
name|u_int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|key_to_blob
parameter_list|(
specifier|const
name|Key
modifier|*
parameter_list|,
name|u_char
modifier|*
modifier|*
parameter_list|,
name|u_int
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|key_sign
parameter_list|(
specifier|const
name|Key
modifier|*
parameter_list|,
name|u_char
modifier|*
modifier|*
parameter_list|,
name|u_int
modifier|*
parameter_list|,
specifier|const
name|u_char
modifier|*
parameter_list|,
name|u_int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|key_verify
parameter_list|(
specifier|const
name|Key
modifier|*
parameter_list|,
specifier|const
name|u_char
modifier|*
parameter_list|,
name|u_int
parameter_list|,
specifier|const
name|u_char
modifier|*
parameter_list|,
name|u_int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|key_private_serialize
parameter_list|(
specifier|const
name|Key
modifier|*
parameter_list|,
name|struct
name|sshbuf
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|Key
modifier|*
name|key_private_deserialize
parameter_list|(
name|struct
name|sshbuf
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* authfile.c */
end_comment

begin_function_decl
name|int
name|key_save_private
parameter_list|(
name|Key
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
name|int
name|key_load_file
parameter_list|(
name|int
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
name|struct
name|sshbuf
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|Key
modifier|*
name|key_load_cert
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|Key
modifier|*
name|key_load_public
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
name|char
modifier|*
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|Key
modifier|*
name|key_load_private
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
name|char
modifier|*
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|Key
modifier|*
name|key_load_private_cert
parameter_list|(
name|int
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
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|Key
modifier|*
name|key_load_private_type
parameter_list|(
name|int
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
name|char
modifier|*
modifier|*
parameter_list|,
name|int
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|Key
modifier|*
name|key_load_private_pem
parameter_list|(
name|int
parameter_list|,
name|int
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
name|char
modifier|*
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|key_perm_ok
parameter_list|(
name|int
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|key_in_file
parameter_list|(
name|Key
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

end_unit

