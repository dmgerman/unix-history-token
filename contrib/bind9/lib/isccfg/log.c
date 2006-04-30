begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (C) 2004  Internet Systems Consortium, Inc. ("ISC")  * Copyright (C) 2001  Internet Software Consortium.  *  * Permission to use, copy, modify, and distribute this software for any  * purpose with or without fee is hereby granted, provided that the above  * copyright notice and this permission notice appear in all copies.  *  * THE SOFTWARE IS PROVIDED "AS IS" AND ISC DISCLAIMS ALL WARRANTIES WITH  * REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY  * AND FITNESS.  IN NO EVENT SHALL ISC BE LIABLE FOR ANY SPECIAL, DIRECT,  * INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM  * LOSS OF USE, DATA OR PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE  * OR OTHER TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR  * PERFORMANCE OF THIS SOFTWARE.  */
end_comment

begin_comment
comment|/* $Id: log.c,v 1.2.2.1.10.3 2004/03/08 09:05:06 marka Exp $ */
end_comment

begin_include
include|#
directive|include
file|<config.h>
end_include

begin_include
include|#
directive|include
file|<isc/util.h>
end_include

begin_include
include|#
directive|include
file|<isccfg/log.h>
end_include

begin_comment
comment|/*  * When adding a new category, be sure to add the appropriate  * #define to<isccfg/log.h>.  */
end_comment

begin_decl_stmt
name|LIBISCCFG_EXTERNAL_DATA
name|isc_logcategory_t
name|cfg_categories
index|[]
init|=
block|{
block|{
literal|"config"
block|,
literal|0
block|}
block|,
block|{
name|NULL
block|,
literal|0
block|}
block|}
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * When adding a new module, be sure to add the appropriate  * #define to<isccfg/log.h>.  */
end_comment

begin_decl_stmt
name|LIBISCCFG_EXTERNAL_DATA
name|isc_logmodule_t
name|cfg_modules
index|[]
init|=
block|{
block|{
literal|"isccfg/parser"
block|,
literal|0
block|}
block|,
block|{
name|NULL
block|,
literal|0
block|}
block|}
decl_stmt|;
end_decl_stmt

begin_function
name|void
name|cfg_log_init
parameter_list|(
name|isc_log_t
modifier|*
name|lctx
parameter_list|)
block|{
name|REQUIRE
argument_list|(
name|lctx
operator|!=
name|NULL
argument_list|)
expr_stmt|;
name|isc_log_registercategories
argument_list|(
name|lctx
argument_list|,
name|cfg_categories
argument_list|)
expr_stmt|;
name|isc_log_registermodules
argument_list|(
name|lctx
argument_list|,
name|cfg_modules
argument_list|)
expr_stmt|;
block|}
end_function

end_unit

