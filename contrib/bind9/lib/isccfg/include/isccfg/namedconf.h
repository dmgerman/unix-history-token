begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (C) 2004  Internet Systems Consortium, Inc. ("ISC")  * Copyright (C) 2002  Internet Software Consortium.  *  * Permission to use, copy, modify, and distribute this software for any  * purpose with or without fee is hereby granted, provided that the above  * copyright notice and this permission notice appear in all copies.  *  * THE SOFTWARE IS PROVIDED "AS IS" AND ISC DISCLAIMS ALL WARRANTIES WITH  * REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY  * AND FITNESS.  IN NO EVENT SHALL ISC BE LIABLE FOR ANY SPECIAL, DIRECT,  * INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM  * LOSS OF USE, DATA OR PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE  * OR OTHER TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR  * PERFORMANCE OF THIS SOFTWARE.  */
end_comment

begin_comment
comment|/* $Id: namedconf.h,v 1.2.202.3 2004/03/08 09:05:07 marka Exp $ */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|ISCCFG_NAMEDCONF_H
end_ifndef

begin_define
define|#
directive|define
name|ISCCFG_NAMEDCONF_H
value|1
end_define

begin_comment
comment|/*  * This module defines the named.conf, rndc.conf, and rndc.key grammars.  */
end_comment

begin_include
include|#
directive|include
file|<isccfg/cfg.h>
end_include

begin_comment
comment|/*  * Configuration object types.  */
end_comment

begin_decl_stmt
name|LIBISCCFG_EXTERNAL_DATA
specifier|extern
name|cfg_type_t
name|cfg_type_namedconf
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* A complete named.conf file. */
end_comment

begin_decl_stmt
name|LIBISCCFG_EXTERNAL_DATA
specifier|extern
name|cfg_type_t
name|cfg_type_rndcconf
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* A complete rndc.conf file. */
end_comment

begin_decl_stmt
name|LIBISCCFG_EXTERNAL_DATA
specifier|extern
name|cfg_type_t
name|cfg_type_rndckey
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* A complete rndc.key file. */
end_comment

begin_decl_stmt
name|LIBISCCFG_EXTERNAL_DATA
specifier|extern
name|cfg_type_t
name|cfg_type_keyref
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* A key reference, used as an ACL element */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ISCCFG_CFG_H */
end_comment

end_unit

