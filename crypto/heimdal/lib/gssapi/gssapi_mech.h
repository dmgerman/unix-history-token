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
name|GSSAPI_CALLCONV
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
name|GSSAPI_CALLCONV
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
name|GSSAPI_CALLCONV
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
name|GSSAPI_CALLCONV
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
name|GSSAPI_CALLCONV
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
name|GSSAPI_CALLCONV
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
name|GSSAPI_CALLCONV
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
name|GSSAPI_CALLCONV
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
name|GSSAPI_CALLCONV
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
name|GSSAPI_CALLCONV
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
name|GSSAPI_CALLCONV
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
name|GSSAPI_CALLCONV
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
name|GSSAPI_CALLCONV
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
name|GSSAPI_CALLCONV
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
name|GSSAPI_CALLCONV
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
name|GSSAPI_CALLCONV
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
name|GSSAPI_CALLCONV
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
name|GSSAPI_CALLCONV
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
name|GSSAPI_CALLCONV
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
name|GSSAPI_CALLCONV
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
name|GSSAPI_CALLCONV
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
name|GSSAPI_CALLCONV
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
name|GSSAPI_CALLCONV
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
name|GSSAPI_CALLCONV
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
name|GSSAPI_CALLCONV
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
name|GSSAPI_CALLCONV
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
name|GSSAPI_CALLCONV
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
name|GSSAPI_CALLCONV
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
name|GSSAPI_CALLCONV
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
name|GSSAPI_CALLCONV
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
name|GSSAPI_CALLCONV
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
name|GSSAPI_CALLCONV
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
name|GSSAPI_CALLCONV
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
name|GSSAPI_CALLCONV
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

begin_typedef
typedef|typedef
name|OM_uint32
name|GSSAPI_CALLCONV
name|_gss_wrap_iov_t
parameter_list|(
name|OM_uint32
modifier|*
name|minor_status
parameter_list|,
name|gss_ctx_id_t
name|context_handle
parameter_list|,
name|int
name|conf_req_flag
parameter_list|,
name|gss_qop_t
name|qop_req
parameter_list|,
name|int
modifier|*
name|conf_state
parameter_list|,
name|gss_iov_buffer_desc
modifier|*
name|iov
parameter_list|,
name|int
name|iov_count
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|OM_uint32
name|GSSAPI_CALLCONV
name|_gss_unwrap_iov_t
parameter_list|(
name|OM_uint32
modifier|*
name|minor_status
parameter_list|,
name|gss_ctx_id_t
name|context_handle
parameter_list|,
name|int
modifier|*
name|conf_state
parameter_list|,
name|gss_qop_t
modifier|*
name|qop_state
parameter_list|,
name|gss_iov_buffer_desc
modifier|*
name|iov
parameter_list|,
name|int
name|iov_count
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|OM_uint32
name|GSSAPI_CALLCONV
name|_gss_wrap_iov_length_t
parameter_list|(
name|OM_uint32
modifier|*
name|minor_status
parameter_list|,
name|gss_ctx_id_t
name|context_handle
parameter_list|,
name|int
name|conf_req_flag
parameter_list|,
name|gss_qop_t
name|qop_req
parameter_list|,
name|int
modifier|*
name|conf_state
parameter_list|,
name|gss_iov_buffer_desc
modifier|*
name|iov
parameter_list|,
name|int
name|iov_count
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|OM_uint32
name|GSSAPI_CALLCONV
name|_gss_store_cred_t
parameter_list|(
name|OM_uint32
modifier|*
name|minor_status
parameter_list|,
name|gss_cred_id_t
name|input_cred_handle
parameter_list|,
name|gss_cred_usage_t
name|cred_usage
parameter_list|,
specifier|const
name|gss_OID
name|desired_mech
parameter_list|,
name|OM_uint32
name|overwrite_cred
parameter_list|,
name|OM_uint32
name|default_cred
parameter_list|,
name|gss_OID_set
modifier|*
name|elements_stored
parameter_list|,
name|gss_cred_usage_t
modifier|*
name|cred_usage_stored
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|OM_uint32
name|GSSAPI_CALLCONV
name|_gss_export_cred_t
parameter_list|(
name|OM_uint32
modifier|*
name|minor_status
parameter_list|,
name|gss_cred_id_t
name|cred_handle
parameter_list|,
name|gss_buffer_t
name|cred_token
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|OM_uint32
name|GSSAPI_CALLCONV
name|_gss_import_cred_t
parameter_list|(
name|OM_uint32
modifier|*
name|minor_status
parameter_list|,
name|gss_buffer_t
name|cred_token
parameter_list|,
name|gss_cred_id_t
modifier|*
name|cred_handle
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|OM_uint32
name|GSSAPI_CALLCONV
name|_gss_acquire_cred_ext_t
parameter_list|(
name|OM_uint32
modifier|*
comment|/*minor_status */
parameter_list|,
specifier|const
name|gss_name_t
comment|/* desired_name */
parameter_list|,
name|gss_const_OID
comment|/* credential_type */
parameter_list|,
specifier|const
name|void
modifier|*
comment|/* credential_data */
parameter_list|,
name|OM_uint32
comment|/* time_req */
parameter_list|,
name|gss_const_OID
comment|/* desired_mech */
parameter_list|,
name|gss_cred_usage_t
comment|/* cred_usage */
parameter_list|,
name|gss_cred_id_t
modifier|*
comment|/* output_cred_handle */
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|void
name|GSSAPI_CALLCONV
name|_gss_iter_creds_t
parameter_list|(
name|OM_uint32
comment|/* flags */
parameter_list|,
name|void
modifier|*
comment|/* userctx */
parameter_list|,
name|void
function_decl|(
modifier|*
comment|/*cred_iter */
function_decl|)
parameter_list|(
name|void
modifier|*
parameter_list|,
name|gss_OID
parameter_list|,
name|gss_cred_id_t
parameter_list|)
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|OM_uint32
name|GSSAPI_CALLCONV
name|_gss_destroy_cred_t
parameter_list|(
name|OM_uint32
modifier|*
comment|/* minor_status */
parameter_list|,
name|gss_cred_id_t
modifier|*
comment|/* cred */
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|OM_uint32
name|GSSAPI_CALLCONV
name|_gss_cred_hold_t
parameter_list|(
name|OM_uint32
modifier|*
comment|/* minor_status */
parameter_list|,
name|gss_cred_id_t
comment|/* cred */
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|OM_uint32
name|GSSAPI_CALLCONV
name|_gss_cred_unhold_t
parameter_list|(
name|OM_uint32
modifier|*
comment|/* minor_status */
parameter_list|,
name|gss_cred_id_t
comment|/* cred */
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|OM_uint32
name|GSSAPI_CALLCONV
name|_gss_cred_label_set_t
parameter_list|(
name|OM_uint32
modifier|*
comment|/* minor_status */
parameter_list|,
name|gss_cred_id_t
comment|/* cred */
parameter_list|,
specifier|const
name|char
modifier|*
comment|/* label */
parameter_list|,
name|gss_buffer_t
comment|/* value */
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|OM_uint32
name|GSSAPI_CALLCONV
name|_gss_cred_label_get_t
parameter_list|(
name|OM_uint32
modifier|*
comment|/* minor_status */
parameter_list|,
name|gss_cred_id_t
comment|/* cred */
parameter_list|,
specifier|const
name|char
modifier|*
comment|/* label */
parameter_list|,
name|gss_buffer_t
comment|/* value */
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|OM_uint32
name|GSSAPI_CALLCONV
name|_gss_display_name_ext_t
parameter_list|(
name|OM_uint32
modifier|*
parameter_list|,
comment|/* minor_status */
name|gss_name_t
parameter_list|,
comment|/* name */
name|gss_OID
parameter_list|,
comment|/* display_as_name_type */
name|gss_buffer_t
comment|/* display_name */
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|OM_uint32
name|GSSAPI_CALLCONV
name|_gss_inquire_name_t
parameter_list|(
name|OM_uint32
modifier|*
parameter_list|,
comment|/* minor_status */
name|gss_name_t
parameter_list|,
comment|/* name */
name|int
modifier|*
parameter_list|,
comment|/* name_is_MN */
name|gss_OID
modifier|*
parameter_list|,
comment|/* MN_mech */
name|gss_buffer_set_t
modifier|*
comment|/* attrs */
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|OM_uint32
name|GSSAPI_CALLCONV
name|_gss_get_name_attribute_t
parameter_list|(
name|OM_uint32
modifier|*
parameter_list|,
comment|/* minor_status */
name|gss_name_t
parameter_list|,
comment|/* name */
name|gss_buffer_t
parameter_list|,
comment|/* attr */
name|int
modifier|*
parameter_list|,
comment|/* authenticated */
name|int
modifier|*
parameter_list|,
comment|/* complete */
name|gss_buffer_t
parameter_list|,
comment|/* value */
name|gss_buffer_t
parameter_list|,
comment|/* display_value */
name|int
modifier|*
comment|/* more */
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|OM_uint32
name|GSSAPI_CALLCONV
name|_gss_set_name_attribute_t
parameter_list|(
name|OM_uint32
modifier|*
parameter_list|,
comment|/* minor_status */
name|gss_name_t
parameter_list|,
comment|/* name */
name|int
parameter_list|,
comment|/* complete */
name|gss_buffer_t
parameter_list|,
comment|/* attr */
name|gss_buffer_t
comment|/* value */
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|OM_uint32
name|GSSAPI_CALLCONV
name|_gss_delete_name_attribute_t
parameter_list|(
name|OM_uint32
modifier|*
parameter_list|,
comment|/* minor_status */
name|gss_name_t
parameter_list|,
comment|/* name */
name|gss_buffer_t
comment|/* attr */
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|OM_uint32
name|GSSAPI_CALLCONV
name|_gss_export_name_composite_t
parameter_list|(
name|OM_uint32
modifier|*
parameter_list|,
comment|/* minor_status */
name|gss_name_t
parameter_list|,
comment|/* name */
name|gss_buffer_t
comment|/* exp_composite_name */
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/*  *  */
end_comment

begin_typedef
typedef|typedef
name|struct
name|gss_mo_desc_struct
name|gss_mo_desc
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|OM_uint32
name|GSSAPI_CALLCONV
name|_gss_mo_init
parameter_list|(
name|OM_uint32
modifier|*
parameter_list|,
name|gss_OID
parameter_list|,
name|gss_mo_desc
modifier|*
modifier|*
parameter_list|,
name|size_t
modifier|*
parameter_list|)
function_decl|;
end_typedef

begin_struct
struct|struct
name|gss_mo_desc_struct
block|{
name|gss_OID
name|option
decl_stmt|;
name|OM_uint32
name|flags
decl_stmt|;
define|#
directive|define
name|GSS_MO_MA
value|1
define|#
directive|define
name|GSS_MO_MA_CRITICAL
value|2
specifier|const
name|char
modifier|*
name|name
decl_stmt|;
name|void
modifier|*
name|ctx
decl_stmt|;
name|int
function_decl|(
modifier|*
name|get
function_decl|)
parameter_list|(
name|gss_const_OID
parameter_list|,
name|gss_mo_desc
modifier|*
parameter_list|,
name|gss_buffer_t
parameter_list|)
function_decl|;
name|int
function_decl|(
modifier|*
name|set
function_decl|)
parameter_list|(
name|gss_const_OID
parameter_list|,
name|gss_mo_desc
modifier|*
parameter_list|,
name|int
parameter_list|,
name|gss_buffer_t
parameter_list|)
function_decl|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|OM_uint32
name|GSSAPI_CALLCONV
name|_gss_pname_to_uid_t
parameter_list|(
name|OM_uint32
modifier|*
parameter_list|,
comment|/* minor_status */
specifier|const
name|gss_name_t
parameter_list|,
comment|/* name */
specifier|const
name|gss_OID
parameter_list|,
comment|/* mech_type */
name|uid_t
modifier|*
comment|/* uidOut */
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|OM_uint32
name|GSSAPI_CALLCONV
name|_gss_authorize_localname_t
parameter_list|(
name|OM_uint32
modifier|*
parameter_list|,
comment|/* minor_status */
specifier|const
name|gss_name_t
parameter_list|,
comment|/* name */
name|gss_const_buffer_t
parameter_list|,
comment|/* user */
name|gss_const_OID
comment|/* user_name_type */
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/* mechglue internal */
end_comment

begin_struct_decl
struct_decl|struct
name|gss_mech_compat_desc_struct
struct_decl|;
end_struct_decl

begin_define
define|#
directive|define
name|GMI_VERSION
value|5
end_define

begin_comment
comment|/* gm_flags */
end_comment

begin_define
define|#
directive|define
name|GM_USE_MG_CRED
value|1
end_define

begin_comment
comment|/* uses mech glue credentials */
end_comment

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
name|unsigned
name|gm_flags
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
name|_gss_wrap_iov_t
modifier|*
name|gm_wrap_iov
decl_stmt|;
name|_gss_unwrap_iov_t
modifier|*
name|gm_unwrap_iov
decl_stmt|;
name|_gss_wrap_iov_length_t
modifier|*
name|gm_wrap_iov_length
decl_stmt|;
name|_gss_store_cred_t
modifier|*
name|gm_store_cred
decl_stmt|;
name|_gss_export_cred_t
modifier|*
name|gm_export_cred
decl_stmt|;
name|_gss_import_cred_t
modifier|*
name|gm_import_cred
decl_stmt|;
name|_gss_acquire_cred_ext_t
modifier|*
name|gm_acquire_cred_ext
decl_stmt|;
name|_gss_iter_creds_t
modifier|*
name|gm_iter_creds
decl_stmt|;
name|_gss_destroy_cred_t
modifier|*
name|gm_destroy_cred
decl_stmt|;
name|_gss_cred_hold_t
modifier|*
name|gm_cred_hold
decl_stmt|;
name|_gss_cred_unhold_t
modifier|*
name|gm_cred_unhold
decl_stmt|;
name|_gss_cred_label_get_t
modifier|*
name|gm_cred_label_get
decl_stmt|;
name|_gss_cred_label_set_t
modifier|*
name|gm_cred_label_set
decl_stmt|;
name|gss_mo_desc
modifier|*
name|gm_mo
decl_stmt|;
name|size_t
name|gm_mo_num
decl_stmt|;
name|_gss_pname_to_uid_t
modifier|*
name|gm_pname_to_uid
decl_stmt|;
name|_gss_authorize_localname_t
modifier|*
name|gm_authorize_localname
decl_stmt|;
name|_gss_display_name_ext_t
modifier|*
name|gm_display_name_ext
decl_stmt|;
name|_gss_inquire_name_t
modifier|*
name|gm_inquire_name
decl_stmt|;
name|_gss_get_name_attribute_t
modifier|*
name|gm_get_name_attribute
decl_stmt|;
name|_gss_set_name_attribute_t
modifier|*
name|gm_set_name_attribute
decl_stmt|;
name|_gss_delete_name_attribute_t
modifier|*
name|gm_delete_name_attribute
decl_stmt|;
name|_gss_export_name_composite_t
modifier|*
name|gm_export_name_composite
decl_stmt|;
name|struct
name|gss_mech_compat_desc_struct
modifier|*
name|gm_compat
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
name|gss_const_OID
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

begin_function_decl
name|void
name|gss_mg_collect_error
parameter_list|(
name|gss_OID
parameter_list|,
name|OM_uint32
parameter_list|,
name|OM_uint32
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|_gss_mo_get_option_1
parameter_list|(
name|gss_const_OID
parameter_list|,
name|gss_mo_desc
modifier|*
parameter_list|,
name|gss_buffer_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|_gss_mo_get_option_0
parameter_list|(
name|gss_const_OID
parameter_list|,
name|gss_mo_desc
modifier|*
parameter_list|,
name|gss_buffer_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|_gss_mo_get_ctx_as_string
parameter_list|(
name|gss_const_OID
parameter_list|,
name|gss_mo_desc
modifier|*
parameter_list|,
name|gss_buffer_t
parameter_list|)
function_decl|;
end_function_decl

begin_struct
struct|struct
name|_gss_oid_name_table
block|{
name|gss_OID
name|oid
decl_stmt|;
specifier|const
name|char
modifier|*
name|name
decl_stmt|;
specifier|const
name|char
modifier|*
name|short_desc
decl_stmt|;
specifier|const
name|char
modifier|*
name|long_desc
decl_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
specifier|extern
name|struct
name|_gss_oid_name_table
name|_gss_ont_mech
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|_gss_oid_name_table
name|_gss_ont_ma
index|[]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * Extended credentials acqusition API, not to be exported until  * it or something equivalent has been standardised.  */
end_comment

begin_decl_stmt
specifier|extern
name|gss_OID_desc
name|GSSAPI_LIB_VARIABLE
name|__gss_c_cred_password_oid_desc
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|GSS_C_CRED_PASSWORD
value|(&__gss_c_cred_password_oid_desc)
end_define

begin_decl_stmt
specifier|extern
name|gss_OID_desc
name|GSSAPI_LIB_VARIABLE
name|__gss_c_cred_certificate_oid_desc
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|GSS_C_CRED_CERTIFICATE
value|(&__gss_c_cred_certificate_oid_desc)
end_define

begin_function_decl
name|OM_uint32
name|_gss_acquire_cred_ext
parameter_list|(
name|OM_uint32
modifier|*
comment|/*minor_status*/
parameter_list|,
specifier|const
name|gss_name_t
comment|/*desired_name*/
parameter_list|,
name|gss_const_OID
comment|/*credential_type*/
parameter_list|,
specifier|const
name|void
modifier|*
comment|/*credential_data*/
parameter_list|,
name|OM_uint32
comment|/*time_req*/
parameter_list|,
name|gss_const_OID
comment|/*desired_mech*/
parameter_list|,
name|gss_cred_usage_t
comment|/*cred_usage*/
parameter_list|,
name|gss_cred_id_t
modifier|*
comment|/*output_cred_handle*/
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

