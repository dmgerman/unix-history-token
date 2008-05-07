begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2005 Doug Rabson  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	$FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|GSSAPI_MECH_H
end_ifndef

begin_define
define|#
directive|define
name|GSSAPI_MECH_H
value|1
end_define

begin_include
include|#
directive|include
file|<gssapi.h>
end_include

begin_typedef
typedef|typedef
name|OM_uint32
name|_gss_acquire_cred_t
parameter_list|(
name|OM_uint32
modifier|*
parameter_list|,
comment|/* minor_status */
specifier|const
name|gss_name_t
parameter_list|,
comment|/* desired_name */
name|OM_uint32
parameter_list|,
comment|/* time_req */
specifier|const
name|gss_OID_set
parameter_list|,
comment|/* desired_mechs */
name|gss_cred_usage_t
parameter_list|,
comment|/* cred_usage */
name|gss_cred_id_t
modifier|*
parameter_list|,
comment|/* output_cred_handle */
name|gss_OID_set
modifier|*
parameter_list|,
comment|/* actual_mechs */
name|OM_uint32
modifier|*
comment|/* time_rec */
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|OM_uint32
name|_gss_release_cred_t
parameter_list|(
name|OM_uint32
modifier|*
parameter_list|,
comment|/* minor_status */
name|gss_cred_id_t
modifier|*
comment|/* cred_handle */
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|OM_uint32
name|_gss_init_sec_context_t
parameter_list|(
name|OM_uint32
modifier|*
parameter_list|,
comment|/* minor_status */
specifier|const
name|gss_cred_id_t
parameter_list|,
comment|/* initiator_cred_handle */
name|gss_ctx_id_t
modifier|*
parameter_list|,
comment|/* context_handle */
specifier|const
name|gss_name_t
parameter_list|,
comment|/* target_name */
specifier|const
name|gss_OID
parameter_list|,
comment|/* mech_type */
name|OM_uint32
parameter_list|,
comment|/* req_flags */
name|OM_uint32
parameter_list|,
comment|/* time_req */
specifier|const
name|gss_channel_bindings_t
parameter_list|,
comment|/* input_chan_bindings */
specifier|const
name|gss_buffer_t
parameter_list|,
comment|/* input_token */
name|gss_OID
modifier|*
parameter_list|,
comment|/* actual_mech_type */
name|gss_buffer_t
parameter_list|,
comment|/* output_token */
name|OM_uint32
modifier|*
parameter_list|,
comment|/* ret_flags */
name|OM_uint32
modifier|*
comment|/* time_rec */
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|OM_uint32
name|_gss_accept_sec_context_t
parameter_list|(
name|OM_uint32
modifier|*
parameter_list|,
comment|/* minor_status */
name|gss_ctx_id_t
modifier|*
parameter_list|,
comment|/* context_handle */
specifier|const
name|gss_cred_id_t
parameter_list|,
comment|/* acceptor_cred_handle */
specifier|const
name|gss_buffer_t
parameter_list|,
comment|/* input_token_buffer */
specifier|const
name|gss_channel_bindings_t
parameter_list|,
comment|/* input_chan_bindings */
name|gss_name_t
modifier|*
parameter_list|,
comment|/* src_name */
name|gss_OID
modifier|*
parameter_list|,
comment|/* mech_type */
name|gss_buffer_t
parameter_list|,
comment|/* output_token */
name|OM_uint32
modifier|*
parameter_list|,
comment|/* ret_flags */
name|OM_uint32
modifier|*
parameter_list|,
comment|/* time_rec */
name|gss_cred_id_t
modifier|*
comment|/* delegated_cred_handle */
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|OM_uint32
name|_gss_process_context_token_t
parameter_list|(
name|OM_uint32
modifier|*
parameter_list|,
comment|/* minor_status */
specifier|const
name|gss_ctx_id_t
parameter_list|,
comment|/* context_handle */
specifier|const
name|gss_buffer_t
comment|/* token_buffer */
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|OM_uint32
name|_gss_delete_sec_context_t
parameter_list|(
name|OM_uint32
modifier|*
parameter_list|,
comment|/* minor_status */
name|gss_ctx_id_t
modifier|*
parameter_list|,
comment|/* context_handle */
name|gss_buffer_t
comment|/* output_token */
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|OM_uint32
name|_gss_context_time_t
parameter_list|(
name|OM_uint32
modifier|*
parameter_list|,
comment|/* minor_status */
specifier|const
name|gss_ctx_id_t
parameter_list|,
comment|/* context_handle */
name|OM_uint32
modifier|*
comment|/* time_rec */
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|OM_uint32
name|_gss_get_mic_t
parameter_list|(
name|OM_uint32
modifier|*
parameter_list|,
comment|/* minor_status */
specifier|const
name|gss_ctx_id_t
parameter_list|,
comment|/* context_handle */
name|gss_qop_t
parameter_list|,
comment|/* qop_req */
specifier|const
name|gss_buffer_t
parameter_list|,
comment|/* message_buffer */
name|gss_buffer_t
comment|/* message_token */
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|OM_uint32
name|_gss_verify_mic_t
parameter_list|(
name|OM_uint32
modifier|*
parameter_list|,
comment|/* minor_status */
specifier|const
name|gss_ctx_id_t
parameter_list|,
comment|/* context_handle */
specifier|const
name|gss_buffer_t
parameter_list|,
comment|/* message_buffer */
specifier|const
name|gss_buffer_t
parameter_list|,
comment|/* token_buffer */
name|gss_qop_t
modifier|*
comment|/* qop_state */
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|OM_uint32
name|_gss_wrap_t
parameter_list|(
name|OM_uint32
modifier|*
parameter_list|,
comment|/* minor_status */
specifier|const
name|gss_ctx_id_t
parameter_list|,
comment|/* context_handle */
name|int
parameter_list|,
comment|/* conf_req_flag */
name|gss_qop_t
parameter_list|,
comment|/* qop_req */
specifier|const
name|gss_buffer_t
parameter_list|,
comment|/* input_message_buffer */
name|int
modifier|*
parameter_list|,
comment|/* conf_state */
name|gss_buffer_t
comment|/* output_message_buffer */
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|OM_uint32
name|_gss_unwrap_t
parameter_list|(
name|OM_uint32
modifier|*
parameter_list|,
comment|/* minor_status */
specifier|const
name|gss_ctx_id_t
parameter_list|,
comment|/* context_handle */
specifier|const
name|gss_buffer_t
parameter_list|,
comment|/* input_message_buffer */
name|gss_buffer_t
parameter_list|,
comment|/* output_message_buffer */
name|int
modifier|*
parameter_list|,
comment|/* conf_state */
name|gss_qop_t
modifier|*
comment|/* qop_state */
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|OM_uint32
name|_gss_display_status_t
parameter_list|(
name|OM_uint32
modifier|*
parameter_list|,
comment|/* minor_status */
name|OM_uint32
parameter_list|,
comment|/* status_value */
name|int
parameter_list|,
comment|/* status_type */
specifier|const
name|gss_OID
parameter_list|,
comment|/* mech_type */
name|OM_uint32
modifier|*
parameter_list|,
comment|/* message_context */
name|gss_buffer_t
comment|/* status_string */
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|OM_uint32
name|_gss_indicate_mechs_t
parameter_list|(
name|OM_uint32
modifier|*
parameter_list|,
comment|/* minor_status */
name|gss_OID_set
modifier|*
comment|/* mech_set */
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|OM_uint32
name|_gss_compare_name_t
parameter_list|(
name|OM_uint32
modifier|*
parameter_list|,
comment|/* minor_status */
specifier|const
name|gss_name_t
parameter_list|,
comment|/* name1 */
specifier|const
name|gss_name_t
parameter_list|,
comment|/* name2 */
name|int
modifier|*
comment|/* name_equal */
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|OM_uint32
name|_gss_display_name_t
parameter_list|(
name|OM_uint32
modifier|*
parameter_list|,
comment|/* minor_status */
specifier|const
name|gss_name_t
parameter_list|,
comment|/* input_name */
name|gss_buffer_t
parameter_list|,
comment|/* output_name_buffer */
name|gss_OID
modifier|*
comment|/* output_name_type */
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|OM_uint32
name|_gss_import_name_t
parameter_list|(
name|OM_uint32
modifier|*
parameter_list|,
comment|/* minor_status */
specifier|const
name|gss_buffer_t
parameter_list|,
comment|/* input_name_buffer */
specifier|const
name|gss_OID
parameter_list|,
comment|/* input_name_type */
name|gss_name_t
modifier|*
comment|/* output_name */
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|OM_uint32
name|_gss_export_name_t
parameter_list|(
name|OM_uint32
modifier|*
parameter_list|,
comment|/* minor_status */
specifier|const
name|gss_name_t
parameter_list|,
comment|/* input_name */
name|gss_buffer_t
comment|/* exported_name */
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|OM_uint32
name|_gss_release_name_t
parameter_list|(
name|OM_uint32
modifier|*
parameter_list|,
comment|/* minor_status */
name|gss_name_t
modifier|*
comment|/* input_name */
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|OM_uint32
name|_gss_inquire_cred_t
parameter_list|(
name|OM_uint32
modifier|*
parameter_list|,
comment|/* minor_status */
specifier|const
name|gss_cred_id_t
parameter_list|,
comment|/* cred_handle */
name|gss_name_t
modifier|*
parameter_list|,
comment|/* name */
name|OM_uint32
modifier|*
parameter_list|,
comment|/* lifetime */
name|gss_cred_usage_t
modifier|*
parameter_list|,
comment|/* cred_usage */
name|gss_OID_set
modifier|*
comment|/* mechanisms */
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|OM_uint32
name|_gss_inquire_context_t
parameter_list|(
name|OM_uint32
modifier|*
parameter_list|,
comment|/* minor_status */
specifier|const
name|gss_ctx_id_t
parameter_list|,
comment|/* context_handle */
name|gss_name_t
modifier|*
parameter_list|,
comment|/* src_name */
name|gss_name_t
modifier|*
parameter_list|,
comment|/* targ_name */
name|OM_uint32
modifier|*
parameter_list|,
comment|/* lifetime_rec */
name|gss_OID
modifier|*
parameter_list|,
comment|/* mech_type */
name|OM_uint32
modifier|*
parameter_list|,
comment|/* ctx_flags */
name|int
modifier|*
parameter_list|,
comment|/* locally_initiated */
name|int
modifier|*
comment|/* open */
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|OM_uint32
name|_gss_wrap_size_limit_t
parameter_list|(
name|OM_uint32
modifier|*
parameter_list|,
comment|/* minor_status */
specifier|const
name|gss_ctx_id_t
parameter_list|,
comment|/* context_handle */
name|int
parameter_list|,
comment|/* conf_req_flag */
name|gss_qop_t
parameter_list|,
comment|/* qop_req */
name|OM_uint32
parameter_list|,
comment|/* req_output_size */
name|OM_uint32
modifier|*
comment|/* max_input_size */
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|OM_uint32
name|_gss_add_cred_t
parameter_list|(
name|OM_uint32
modifier|*
parameter_list|,
comment|/* minor_status */
specifier|const
name|gss_cred_id_t
parameter_list|,
comment|/* input_cred_handle */
specifier|const
name|gss_name_t
parameter_list|,
comment|/* desired_name */
specifier|const
name|gss_OID
parameter_list|,
comment|/* desired_mech */
name|gss_cred_usage_t
parameter_list|,
comment|/* cred_usage */
name|OM_uint32
parameter_list|,
comment|/* initiator_time_req */
name|OM_uint32
parameter_list|,
comment|/* acceptor_time_req */
name|gss_cred_id_t
modifier|*
parameter_list|,
comment|/* output_cred_handle */
name|gss_OID_set
modifier|*
parameter_list|,
comment|/* actual_mechs */
name|OM_uint32
modifier|*
parameter_list|,
comment|/* initiator_time_rec */
name|OM_uint32
modifier|*
comment|/* acceptor_time_rec */
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|OM_uint32
name|_gss_inquire_cred_by_mech_t
parameter_list|(
name|OM_uint32
modifier|*
parameter_list|,
comment|/* minor_status */
specifier|const
name|gss_cred_id_t
parameter_list|,
comment|/* cred_handle */
specifier|const
name|gss_OID
parameter_list|,
comment|/* mech_type */
name|gss_name_t
modifier|*
parameter_list|,
comment|/* name */
name|OM_uint32
modifier|*
parameter_list|,
comment|/* initiator_lifetime */
name|OM_uint32
modifier|*
parameter_list|,
comment|/* acceptor_lifetime */
name|gss_cred_usage_t
modifier|*
comment|/* cred_usage */
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|OM_uint32
name|_gss_export_sec_context_t
parameter_list|(
name|OM_uint32
modifier|*
parameter_list|,
comment|/* minor_status */
name|gss_ctx_id_t
modifier|*
parameter_list|,
comment|/* context_handle */
name|gss_buffer_t
comment|/* interprocess_token */
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|OM_uint32
name|_gss_import_sec_context_t
parameter_list|(
name|OM_uint32
modifier|*
parameter_list|,
comment|/* minor_status */
specifier|const
name|gss_buffer_t
parameter_list|,
comment|/* interprocess_token */
name|gss_ctx_id_t
modifier|*
comment|/* context_handle */
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|OM_uint32
name|_gss_inquire_names_for_mech_t
parameter_list|(
name|OM_uint32
modifier|*
parameter_list|,
comment|/* minor_status */
specifier|const
name|gss_OID
parameter_list|,
comment|/* mechanism */
name|gss_OID_set
modifier|*
comment|/* name_types */
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|OM_uint32
name|_gss_inquire_mechs_for_name_t
parameter_list|(
name|OM_uint32
modifier|*
parameter_list|,
comment|/* minor_status */
specifier|const
name|gss_name_t
parameter_list|,
comment|/* input_name */
name|gss_OID_set
modifier|*
comment|/* mech_types */
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|OM_uint32
name|_gss_canonicalize_name_t
parameter_list|(
name|OM_uint32
modifier|*
parameter_list|,
comment|/* minor_status */
specifier|const
name|gss_name_t
parameter_list|,
comment|/* input_name */
specifier|const
name|gss_OID
parameter_list|,
comment|/* mech_type */
name|gss_name_t
modifier|*
comment|/* output_name */
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|OM_uint32
name|_gss_duplicate_name_t
parameter_list|(
name|OM_uint32
modifier|*
parameter_list|,
comment|/* minor_status */
specifier|const
name|gss_name_t
parameter_list|,
comment|/* src_name */
name|gss_name_t
modifier|*
comment|/* dest_name */
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|OM_uint32
name|_gss_inquire_sec_context_by_oid
parameter_list|(
name|OM_uint32
modifier|*
name|minor_status
parameter_list|,
specifier|const
name|gss_ctx_id_t
name|context_handle
parameter_list|,
specifier|const
name|gss_OID
name|desired_object
parameter_list|,
name|gss_buffer_set_t
modifier|*
name|data_set
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|OM_uint32
name|_gss_inquire_cred_by_oid
parameter_list|(
name|OM_uint32
modifier|*
name|minor_status
parameter_list|,
specifier|const
name|gss_cred_id_t
name|cred
parameter_list|,
specifier|const
name|gss_OID
name|desired_object
parameter_list|,
name|gss_buffer_set_t
modifier|*
name|data_set
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|OM_uint32
name|_gss_set_sec_context_option
parameter_list|(
name|OM_uint32
modifier|*
name|minor_status
parameter_list|,
name|gss_ctx_id_t
modifier|*
name|cred_handle
parameter_list|,
specifier|const
name|gss_OID
name|desired_object
parameter_list|,
specifier|const
name|gss_buffer_t
name|value
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|OM_uint32
name|_gss_set_cred_option
parameter_list|(
name|OM_uint32
modifier|*
name|minor_status
parameter_list|,
name|gss_cred_id_t
modifier|*
name|cred_handle
parameter_list|,
specifier|const
name|gss_OID
name|desired_object
parameter_list|,
specifier|const
name|gss_buffer_t
name|value
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|OM_uint32
name|_gss_pseudo_random
parameter_list|(
name|OM_uint32
modifier|*
name|minor_status
parameter_list|,
name|gss_ctx_id_t
name|context
parameter_list|,
name|int
name|prf_key
parameter_list|,
specifier|const
name|gss_buffer_t
name|prf_in
parameter_list|,
name|ssize_t
name|desired_output_len
parameter_list|,
name|gss_buffer_t
name|prf_out
parameter_list|)
function_decl|;
end_typedef

begin_define
define|#
directive|define
name|GMI_VERSION
value|1
end_define

begin_typedef
typedef|typedef
struct|struct
name|gssapi_mech_interface_desc
block|{
name|unsigned
name|gm_version
decl_stmt|;
specifier|const
name|char
modifier|*
name|gm_name
decl_stmt|;
name|gss_OID_desc
name|gm_mech_oid
decl_stmt|;
name|_gss_acquire_cred_t
modifier|*
name|gm_acquire_cred
decl_stmt|;
name|_gss_release_cred_t
modifier|*
name|gm_release_cred
decl_stmt|;
name|_gss_init_sec_context_t
modifier|*
name|gm_init_sec_context
decl_stmt|;
name|_gss_accept_sec_context_t
modifier|*
name|gm_accept_sec_context
decl_stmt|;
name|_gss_process_context_token_t
modifier|*
name|gm_process_context_token
decl_stmt|;
name|_gss_delete_sec_context_t
modifier|*
name|gm_delete_sec_context
decl_stmt|;
name|_gss_context_time_t
modifier|*
name|gm_context_time
decl_stmt|;
name|_gss_get_mic_t
modifier|*
name|gm_get_mic
decl_stmt|;
name|_gss_verify_mic_t
modifier|*
name|gm_verify_mic
decl_stmt|;
name|_gss_wrap_t
modifier|*
name|gm_wrap
decl_stmt|;
name|_gss_unwrap_t
modifier|*
name|gm_unwrap
decl_stmt|;
name|_gss_display_status_t
modifier|*
name|gm_display_status
decl_stmt|;
name|_gss_indicate_mechs_t
modifier|*
name|gm_indicate_mechs
decl_stmt|;
name|_gss_compare_name_t
modifier|*
name|gm_compare_name
decl_stmt|;
name|_gss_display_name_t
modifier|*
name|gm_display_name
decl_stmt|;
name|_gss_import_name_t
modifier|*
name|gm_import_name
decl_stmt|;
name|_gss_export_name_t
modifier|*
name|gm_export_name
decl_stmt|;
name|_gss_release_name_t
modifier|*
name|gm_release_name
decl_stmt|;
name|_gss_inquire_cred_t
modifier|*
name|gm_inquire_cred
decl_stmt|;
name|_gss_inquire_context_t
modifier|*
name|gm_inquire_context
decl_stmt|;
name|_gss_wrap_size_limit_t
modifier|*
name|gm_wrap_size_limit
decl_stmt|;
name|_gss_add_cred_t
modifier|*
name|gm_add_cred
decl_stmt|;
name|_gss_inquire_cred_by_mech_t
modifier|*
name|gm_inquire_cred_by_mech
decl_stmt|;
name|_gss_export_sec_context_t
modifier|*
name|gm_export_sec_context
decl_stmt|;
name|_gss_import_sec_context_t
modifier|*
name|gm_import_sec_context
decl_stmt|;
name|_gss_inquire_names_for_mech_t
modifier|*
name|gm_inquire_names_for_mech
decl_stmt|;
name|_gss_inquire_mechs_for_name_t
modifier|*
name|gm_inquire_mechs_for_name
decl_stmt|;
name|_gss_canonicalize_name_t
modifier|*
name|gm_canonicalize_name
decl_stmt|;
name|_gss_duplicate_name_t
modifier|*
name|gm_duplicate_name
decl_stmt|;
name|_gss_inquire_sec_context_by_oid
modifier|*
name|gm_inquire_sec_context_by_oid
decl_stmt|;
name|_gss_inquire_cred_by_oid
modifier|*
name|gm_inquire_cred_by_oid
decl_stmt|;
name|_gss_set_sec_context_option
modifier|*
name|gm_set_sec_context_option
decl_stmt|;
name|_gss_set_cred_option
modifier|*
name|gm_set_cred_option
decl_stmt|;
name|_gss_pseudo_random
modifier|*
name|gm_pseudo_random
decl_stmt|;
block|}
name|gssapi_mech_interface_desc
operator|,
typedef|*
name|gssapi_mech_interface
typedef|;
end_typedef

begin_function_decl
name|gssapi_mech_interface
name|__gss_get_mechanism
parameter_list|(
name|gss_OID
comment|/* oid */
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|gssapi_mech_interface
name|__gss_spnego_initialize
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|gssapi_mech_interface
name|__gss_krb5_initialize
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|gssapi_mech_interface
name|__gss_ntlm_initialize
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
comment|/* GSSAPI_MECH_H */
end_comment

end_unit

