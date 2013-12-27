begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2012 Damien Miller<djm@mindrot.org>  *  * Permission to use, copy, modify, and distribute this software for any  * purpose with or without fee is hereby granted, provided that the above  * copyright notice and this permission notice appear in all copies.  *  * THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES  * WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF  * MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR  * ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES  * WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN  * ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF  * OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.  */
end_comment

begin_comment
comment|/* $OpenBSD: krl.h,v 1.2 2013/01/18 00:24:58 djm Exp $ */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_KRL_H
end_ifndef

begin_define
define|#
directive|define
name|_KRL_H
end_define

begin_comment
comment|/* Functions to manage key revocation lists */
end_comment

begin_define
define|#
directive|define
name|KRL_MAGIC
value|"SSHKRL\n\0"
end_define

begin_define
define|#
directive|define
name|KRL_FORMAT_VERSION
value|1
end_define

begin_comment
comment|/* KRL section types */
end_comment

begin_define
define|#
directive|define
name|KRL_SECTION_CERTIFICATES
value|1
end_define

begin_define
define|#
directive|define
name|KRL_SECTION_EXPLICIT_KEY
value|2
end_define

begin_define
define|#
directive|define
name|KRL_SECTION_FINGERPRINT_SHA1
value|3
end_define

begin_define
define|#
directive|define
name|KRL_SECTION_SIGNATURE
value|4
end_define

begin_comment
comment|/* KRL_SECTION_CERTIFICATES subsection types */
end_comment

begin_define
define|#
directive|define
name|KRL_SECTION_CERT_SERIAL_LIST
value|0x20
end_define

begin_define
define|#
directive|define
name|KRL_SECTION_CERT_SERIAL_RANGE
value|0x21
end_define

begin_define
define|#
directive|define
name|KRL_SECTION_CERT_SERIAL_BITMAP
value|0x22
end_define

begin_define
define|#
directive|define
name|KRL_SECTION_CERT_KEY_ID
value|0x23
end_define

begin_struct_decl
struct_decl|struct
name|ssh_krl
struct_decl|;
end_struct_decl

begin_function_decl
name|struct
name|ssh_krl
modifier|*
name|ssh_krl_init
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ssh_krl_free
parameter_list|(
name|struct
name|ssh_krl
modifier|*
name|krl
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ssh_krl_set_version
parameter_list|(
name|struct
name|ssh_krl
modifier|*
name|krl
parameter_list|,
name|u_int64_t
name|version
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ssh_krl_set_sign_key
parameter_list|(
name|struct
name|ssh_krl
modifier|*
name|krl
parameter_list|,
specifier|const
name|Key
modifier|*
name|sign_key
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ssh_krl_set_comment
parameter_list|(
name|struct
name|ssh_krl
modifier|*
name|krl
parameter_list|,
specifier|const
name|char
modifier|*
name|comment
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ssh_krl_revoke_cert_by_serial
parameter_list|(
name|struct
name|ssh_krl
modifier|*
name|krl
parameter_list|,
specifier|const
name|Key
modifier|*
name|ca_key
parameter_list|,
name|u_int64_t
name|serial
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ssh_krl_revoke_cert_by_serial_range
parameter_list|(
name|struct
name|ssh_krl
modifier|*
name|krl
parameter_list|,
specifier|const
name|Key
modifier|*
name|ca_key
parameter_list|,
name|u_int64_t
name|lo
parameter_list|,
name|u_int64_t
name|hi
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ssh_krl_revoke_cert_by_key_id
parameter_list|(
name|struct
name|ssh_krl
modifier|*
name|krl
parameter_list|,
specifier|const
name|Key
modifier|*
name|ca_key
parameter_list|,
specifier|const
name|char
modifier|*
name|key_id
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ssh_krl_revoke_key_explicit
parameter_list|(
name|struct
name|ssh_krl
modifier|*
name|krl
parameter_list|,
specifier|const
name|Key
modifier|*
name|key
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ssh_krl_revoke_key_sha1
parameter_list|(
name|struct
name|ssh_krl
modifier|*
name|krl
parameter_list|,
specifier|const
name|Key
modifier|*
name|key
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ssh_krl_revoke_key
parameter_list|(
name|struct
name|ssh_krl
modifier|*
name|krl
parameter_list|,
specifier|const
name|Key
modifier|*
name|key
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ssh_krl_to_blob
parameter_list|(
name|struct
name|ssh_krl
modifier|*
name|krl
parameter_list|,
name|Buffer
modifier|*
name|buf
parameter_list|,
specifier|const
name|Key
modifier|*
modifier|*
name|sign_keys
parameter_list|,
name|u_int
name|nsign_keys
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ssh_krl_from_blob
parameter_list|(
name|Buffer
modifier|*
name|buf
parameter_list|,
name|struct
name|ssh_krl
modifier|*
modifier|*
name|krlp
parameter_list|,
specifier|const
name|Key
modifier|*
modifier|*
name|sign_ca_keys
parameter_list|,
name|u_int
name|nsign_ca_keys
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ssh_krl_check_key
parameter_list|(
name|struct
name|ssh_krl
modifier|*
name|krl
parameter_list|,
specifier|const
name|Key
modifier|*
name|key
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ssh_krl_file_contains_key
parameter_list|(
specifier|const
name|char
modifier|*
name|path
parameter_list|,
specifier|const
name|Key
modifier|*
name|key
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _KRL_H */
end_comment

end_unit

