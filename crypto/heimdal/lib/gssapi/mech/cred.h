begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2005 Doug Rabson  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	$FreeBSD: src/lib/libgssapi/cred.h,v 1.1 2005/12/29 14:40:20 dfr Exp $  *	$Id$  */
end_comment

begin_struct
struct|struct
name|_gss_mechanism_cred
block|{
name|HEIM_SLIST_ENTRY
argument_list|(
argument|_gss_mechanism_cred
argument_list|)
name|gmc_link
expr_stmt|;
name|gssapi_mech_interface
name|gmc_mech
decl_stmt|;
comment|/* mechanism ops for MC */
name|gss_OID
name|gmc_mech_oid
decl_stmt|;
comment|/* mechanism oid for MC */
name|gss_cred_id_t
name|gmc_cred
decl_stmt|;
comment|/* underlying MC */
block|}
struct|;
end_struct

begin_expr_stmt
name|HEIM_SLIST_HEAD
argument_list|(
name|_gss_mechanism_cred_list
argument_list|,
name|_gss_mechanism_cred
argument_list|)
expr_stmt|;
end_expr_stmt

begin_struct
struct|struct
name|_gss_cred
block|{
name|struct
name|_gss_mechanism_cred_list
name|gc_mc
decl_stmt|;
block|}
struct|;
end_struct

begin_function_decl
name|struct
name|_gss_mechanism_cred
modifier|*
name|_gss_copy_cred
parameter_list|(
name|struct
name|_gss_mechanism_cred
modifier|*
name|mc
parameter_list|)
function_decl|;
end_function_decl

begin_struct_decl
struct_decl|struct
name|_gss_mechanism_name
struct_decl|;
end_struct_decl

begin_function_decl
name|OM_uint32
name|_gss_acquire_mech_cred
parameter_list|(
name|OM_uint32
modifier|*
name|minor_status
parameter_list|,
name|gssapi_mech_interface
name|m
parameter_list|,
specifier|const
name|struct
name|_gss_mechanism_name
modifier|*
name|mn
parameter_list|,
name|gss_const_OID
name|credential_type
parameter_list|,
specifier|const
name|void
modifier|*
name|credential_data
parameter_list|,
name|OM_uint32
name|time_req
parameter_list|,
name|gss_const_OID
name|desired_mech
parameter_list|,
name|gss_cred_usage_t
name|cred_usage
parameter_list|,
name|struct
name|_gss_mechanism_cred
modifier|*
modifier|*
name|output_cred_handle
parameter_list|)
function_decl|;
end_function_decl

end_unit

