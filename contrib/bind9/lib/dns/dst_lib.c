begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (C) 2004  Internet Systems Consortium, Inc. ("ISC")  * Copyright (C) 1999-2001  Internet Software Consortium.  *  * Permission to use, copy, modify, and distribute this software for any  * purpose with or without fee is hereby granted, provided that the above  * copyright notice and this permission notice appear in all copies.  *  * THE SOFTWARE IS PROVIDED "AS IS" AND ISC DISCLAIMS ALL WARRANTIES WITH  * REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY  * AND FITNESS.  IN NO EVENT SHALL ISC BE LIABLE FOR ANY SPECIAL, DIRECT,  * INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM  * LOSS OF USE, DATA OR PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE  * OR OTHER TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR  * PERFORMANCE OF THIS SOFTWARE.  */
end_comment

begin_comment
comment|/*  * Principal Author: Brian Wellington  * $Id: dst_lib.c,v 1.1.4.1 2004/12/09 04:07:16 marka Exp $  */
end_comment

begin_include
include|#
directive|include
file|<config.h>
end_include

begin_include
include|#
directive|include
file|<stddef.h>
end_include

begin_include
include|#
directive|include
file|<isc/once.h>
end_include

begin_include
include|#
directive|include
file|<isc/msgcat.h>
end_include

begin_include
include|#
directive|include
file|<isc/util.h>
end_include

begin_include
include|#
directive|include
file|<dst/lib.h>
end_include

begin_comment
comment|/***  *** Globals  ***/
end_comment

begin_decl_stmt
name|LIBDNS_EXTERNAL_DATA
name|isc_msgcat_t
modifier|*
name|dst_msgcat
init|=
name|NULL
decl_stmt|;
end_decl_stmt

begin_comment
comment|/***  *** Private  ***/
end_comment

begin_decl_stmt
specifier|static
name|isc_once_t
name|msgcat_once
init|=
name|ISC_ONCE_INIT
decl_stmt|;
end_decl_stmt

begin_comment
comment|/***  *** Functions  ***/
end_comment

begin_function
specifier|static
name|void
name|open_msgcat
parameter_list|(
name|void
parameter_list|)
block|{
name|isc_msgcat_open
argument_list|(
literal|"libdst.cat"
argument_list|,
operator|&
name|dst_msgcat
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
name|void
name|dst_lib_initmsgcat
parameter_list|(
name|void
parameter_list|)
block|{
comment|/* 	 * Initialize the DST library's message catalog, dst_msgcat, if it 	 * has not already been initialized. 	 */
name|RUNTIME_CHECK
argument_list|(
name|isc_once_do
argument_list|(
operator|&
name|msgcat_once
argument_list|,
name|open_msgcat
argument_list|)
operator|==
name|ISC_R_SUCCESS
argument_list|)
expr_stmt|;
block|}
end_function

end_unit

