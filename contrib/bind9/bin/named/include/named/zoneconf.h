begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (C) 2004, 2006  Internet Systems Consortium, Inc. ("ISC")  * Copyright (C) 1999-2002  Internet Software Consortium.  *  * Permission to use, copy, modify, and distribute this software for any  * purpose with or without fee is hereby granted, provided that the above  * copyright notice and this permission notice appear in all copies.  *  * THE SOFTWARE IS PROVIDED "AS IS" AND ISC DISCLAIMS ALL WARRANTIES WITH  * REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY  * AND FITNESS.  IN NO EVENT SHALL ISC BE LIABLE FOR ANY SPECIAL, DIRECT,  * INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM  * LOSS OF USE, DATA OR PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE  * OR OTHER TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR  * PERFORMANCE OF THIS SOFTWARE.  */
end_comment

begin_comment
comment|/* $Id: zoneconf.h,v 1.16.2.2.8.3 2006/03/02 00:37:20 marka Exp $ */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|NS_ZONECONF_H
end_ifndef

begin_define
define|#
directive|define
name|NS_ZONECONF_H
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
file|<isc/types.h>
end_include

begin_include
include|#
directive|include
file|<isccfg/cfg.h>
end_include

begin_include
include|#
directive|include
file|<named/aclconf.h>
end_include

begin_function_decl
name|ISC_LANG_BEGINDECLS
name|isc_result_t
name|ns_zone_configure
parameter_list|(
specifier|const
name|cfg_obj_t
modifier|*
name|config
parameter_list|,
specifier|const
name|cfg_obj_t
modifier|*
name|vconfig
parameter_list|,
specifier|const
name|cfg_obj_t
modifier|*
name|zconfig
parameter_list|,
name|ns_aclconfctx_t
modifier|*
name|ac
parameter_list|,
name|dns_zone_t
modifier|*
name|zone
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Configure or reconfigure a zone according to the named.conf  * data in 'cctx' and 'czone'.  *  * The zone origin is not configured, it is assumed to have been set  * at zone creation time.  *  * Require:  *	'lctx' to be initialized or NULL.  *	'cctx' to be initialized or NULL.  *	'ac' to point to an initialized ns_aclconfctx_t.  *	'czone' to be initialized.  *	'zone' to be initialized.  */
end_comment

begin_function_decl
name|isc_boolean_t
name|ns_zone_reusable
parameter_list|(
name|dns_zone_t
modifier|*
name|zone
parameter_list|,
specifier|const
name|cfg_obj_t
modifier|*
name|zconfig
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * If 'zone' can be safely reconfigured according to the configuration  * data in 'zconfig', return ISC_TRUE.  If the configuration data is so  * different from the current zone state that the zone needs to be destroyed  * and recreated, return ISC_FALSE.  */
end_comment

begin_macro
name|ISC_LANG_ENDDECLS
end_macro

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* NS_ZONECONF_H */
end_comment

end_unit

