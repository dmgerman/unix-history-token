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
name|_gss_mechanism_cred
block|{
name|SLIST_ENTRY
argument_list|(
argument|_gss_mechanism_cred
argument_list|)
name|gmc_link
expr_stmt|;
name|struct
name|_gss_mech_switch
modifier|*
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
name|SLIST_HEAD
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

end_unit

