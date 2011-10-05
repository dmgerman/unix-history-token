begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2010, PADL Software Pty Ltd.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  *  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  *  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * 3. Neither the name of PADL Software nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY PADL SOFTWARE AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL PADL SOFTWARE OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
end_comment

begin_typedef
typedef|typedef
name|OM_uint32
name|GSSAPI_CALLCONV
name|_gss_inquire_saslname_for_mech_t
parameter_list|(
name|OM_uint32
modifier|*
parameter_list|,
comment|/* minor_status */
specifier|const
name|gss_OID
parameter_list|,
comment|/* desired_mech */
name|gss_buffer_t
parameter_list|,
comment|/* sasl_mech_name */
name|gss_buffer_t
parameter_list|,
comment|/* mech_name */
name|gss_buffer_t
comment|/* mech_description */
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|OM_uint32
name|GSSAPI_CALLCONV
name|_gss_inquire_mech_for_saslname_t
parameter_list|(
name|OM_uint32
modifier|*
parameter_list|,
comment|/* minor_status */
specifier|const
name|gss_buffer_t
parameter_list|,
comment|/* sasl_mech_name */
name|gss_OID
modifier|*
comment|/* mech_type */
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|OM_uint32
name|GSSAPI_CALLCONV
name|_gss_inquire_attrs_for_mech_t
parameter_list|(
name|OM_uint32
modifier|*
parameter_list|,
comment|/* minor_status */
name|gss_const_OID
parameter_list|,
comment|/* mech */
name|gss_OID_set
modifier|*
parameter_list|,
comment|/* mech_attrs */
name|gss_OID_set
modifier|*
comment|/* known_mech_attrs */
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|OM_uint32
name|GSSAPI_CALLCONV
name|_gss_acquire_cred_with_password_t
parameter_list|(
name|OM_uint32
modifier|*
parameter_list|,
comment|/* minor_status */
specifier|const
name|gss_name_t
parameter_list|,
comment|/* desired_name */
specifier|const
name|gss_buffer_t
parameter_list|,
comment|/* password */
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
name|_gss_add_cred_with_password_t
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
specifier|const
name|gss_buffer_t
parameter_list|,
comment|/* password */
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

begin_comment
comment|/*  * API-as-SPI compatibility for compatibility with MIT mechanisms;  * native Heimdal mechanisms should not use these.  */
end_comment

begin_struct
struct|struct
name|gss_mech_compat_desc_struct
block|{
name|_gss_inquire_saslname_for_mech_t
modifier|*
name|gmc_inquire_saslname_for_mech
decl_stmt|;
name|_gss_inquire_mech_for_saslname_t
modifier|*
name|gmc_inquire_mech_for_saslname
decl_stmt|;
name|_gss_inquire_attrs_for_mech_t
modifier|*
name|gmc_inquire_attrs_for_mech
decl_stmt|;
name|_gss_acquire_cred_with_password_t
modifier|*
name|gmc_acquire_cred_with_password
decl_stmt|;
if|#
directive|if
literal|0
block|_gss_add_cred_with_password_t       *gmc_add_cred_with_password;
endif|#
directive|endif
block|}
struct|;
end_struct

end_unit

