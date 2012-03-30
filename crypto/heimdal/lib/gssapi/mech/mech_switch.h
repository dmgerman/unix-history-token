begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2005 Doug Rabson  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	$FreeBSD: src/lib/libgssapi/mech_switch.h,v 1.1 2005/12/29 14:40:20 dfr Exp $  *	$Id$  */
end_comment

begin_include
include|#
directive|include
file|<gssapi_mech.h>
end_include

begin_struct
struct|struct
name|_gss_mech_switch
block|{
name|HEIM_SLIST_ENTRY
argument_list|(
argument|_gss_mech_switch
argument_list|)
name|gm_link
expr_stmt|;
name|gss_OID_desc
name|gm_mech_oid
decl_stmt|;
name|gss_OID_set
name|gm_name_types
decl_stmt|;
name|void
modifier|*
name|gm_so
decl_stmt|;
name|gssapi_mech_interface_desc
name|gm_mech
decl_stmt|;
block|}
struct|;
end_struct

begin_expr_stmt
name|HEIM_SLIST_HEAD
argument_list|(
name|_gss_mech_switch_list
argument_list|,
name|_gss_mech_switch
argument_list|)
expr_stmt|;
end_expr_stmt

begin_decl_stmt
specifier|extern
name|struct
name|_gss_mech_switch_list
name|_gss_mechs
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|gss_OID_set
name|_gss_mech_oids
decl_stmt|;
end_decl_stmt

begin_function_decl
name|void
name|_gss_load_mech
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

end_unit

