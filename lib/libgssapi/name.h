begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * SPDX-License-Identifier: BSD-2-Clause-FreeBSD  *  * Copyright (c) 2005 Doug Rabson  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	$FreeBSD$  */
end_comment

begin_include
include|#
directive|include
file|<sys/queue.h>
end_include

begin_struct
struct|struct
name|_gss_mechanism_name
block|{
name|SLIST_ENTRY
argument_list|(
argument|_gss_mechanism_name
argument_list|)
name|gmn_link
expr_stmt|;
name|struct
name|_gss_mech_switch
modifier|*
name|gmn_mech
decl_stmt|;
comment|/* mechanism ops for MN */
name|gss_OID
name|gmn_mech_oid
decl_stmt|;
comment|/* mechanism oid for MN */
name|gss_name_t
name|gmn_name
decl_stmt|;
comment|/* underlying MN */
block|}
struct|;
end_struct

begin_expr_stmt
name|SLIST_HEAD
argument_list|(
name|_gss_mechanism_name_list
argument_list|,
name|_gss_mechanism_name
argument_list|)
expr_stmt|;
end_expr_stmt

begin_struct
struct|struct
name|_gss_name
block|{
name|gss_OID_desc
name|gn_type
decl_stmt|;
comment|/* type of name */
name|gss_buffer_desc
name|gn_value
decl_stmt|;
comment|/* value (as imported) */
name|struct
name|_gss_mechanism_name_list
name|gn_mn
decl_stmt|;
comment|/* list of MNs */
block|}
struct|;
end_struct

begin_function_decl
specifier|extern
name|OM_uint32
name|_gss_find_mn
parameter_list|(
name|OM_uint32
modifier|*
parameter_list|,
name|struct
name|_gss_name
modifier|*
parameter_list|,
name|gss_OID
parameter_list|,
name|struct
name|_gss_mechanism_name
modifier|*
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|struct
name|_gss_name
modifier|*
name|_gss_make_name
parameter_list|(
name|struct
name|_gss_mech_switch
modifier|*
name|m
parameter_list|,
name|gss_name_t
name|new_mn
parameter_list|)
function_decl|;
end_function_decl

end_unit

