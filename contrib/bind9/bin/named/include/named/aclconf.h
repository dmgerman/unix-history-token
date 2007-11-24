begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (C) 2004, 2006  Internet Systems Consortium, Inc. ("ISC")  * Copyright (C) 1999-2001  Internet Software Consortium.  *  * Permission to use, copy, modify, and distribute this software for any  * purpose with or without fee is hereby granted, provided that the above  * copyright notice and this permission notice appear in all copies.  *  * THE SOFTWARE IS PROVIDED "AS IS" AND ISC DISCLAIMS ALL WARRANTIES WITH  * REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY  * AND FITNESS.  IN NO EVENT SHALL ISC BE LIABLE FOR ANY SPECIAL, DIRECT,  * INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM  * LOSS OF USE, DATA OR PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE  * OR OTHER TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR  * PERFORMANCE OF THIS SOFTWARE.  */
end_comment

begin_comment
comment|/* $Id: aclconf.h,v 1.12.208.3 2006/03/02 00:37:20 marka Exp $ */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|NS_ACLCONF_H
end_ifndef

begin_define
define|#
directive|define
name|NS_ACLCONF_H
value|1
end_define

begin_include
include|#
directive|include
file|<isc/lang.h>
end_include

begin_include
include|#
directive|include
file|<isccfg/cfg.h>
end_include

begin_include
include|#
directive|include
file|<dns/types.h>
end_include

begin_typedef
typedef|typedef
struct|struct
name|ns_aclconfctx
block|{
name|ISC_LIST
argument_list|(
argument|dns_acl_t
argument_list|)
name|named_acl_cache
expr_stmt|;
block|}
name|ns_aclconfctx_t
typedef|;
end_typedef

begin_comment
comment|/***  *** Functions  ***/
end_comment

begin_function_decl
name|ISC_LANG_BEGINDECLS
name|void
name|ns_aclconfctx_init
parameter_list|(
name|ns_aclconfctx_t
modifier|*
name|ctx
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Initialize an ACL configuration context.  */
end_comment

begin_function_decl
name|void
name|ns_aclconfctx_destroy
parameter_list|(
name|ns_aclconfctx_t
modifier|*
name|ctx
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Destroy an ACL configuration context.  */
end_comment

begin_function_decl
name|isc_result_t
name|ns_acl_fromconfig
parameter_list|(
specifier|const
name|cfg_obj_t
modifier|*
name|caml
parameter_list|,
specifier|const
name|cfg_obj_t
modifier|*
name|cctx
parameter_list|,
name|ns_aclconfctx_t
modifier|*
name|ctx
parameter_list|,
name|isc_mem_t
modifier|*
name|mctx
parameter_list|,
name|dns_acl_t
modifier|*
modifier|*
name|target
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Construct a new dns_acl_t from configuration data in 'caml' and  * 'cctx'.  Memory is allocated through 'mctx'.  *  * Any named ACLs referred to within 'caml' will be be converted  * inte nested dns_acl_t objects.  Multiple references to the same  * named ACLs will be converted into shared references to a single  * nested dns_acl_t object when the referring objects were created  * passing the same ACL configuration context 'ctx'.  *  * On success, attach '*target' to the new dns_acl_t object.  */
end_comment

begin_macro
name|ISC_LANG_ENDDECLS
end_macro

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* NS_ACLCONF_H */
end_comment

end_unit

