begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (C) 2004  Internet Systems Consortium, Inc. ("ISC")  * Copyright (C) 1999-2001  Internet Software Consortium.  *  * Permission to use, copy, modify, and distribute this software for any  * purpose with or without fee is hereby granted, provided that the above  * copyright notice and this permission notice appear in all copies.  *  * THE SOFTWARE IS PROVIDED "AS IS" AND ISC DISCLAIMS ALL WARRANTIES WITH  * REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY  * AND FITNESS.  IN NO EVENT SHALL ISC BE LIABLE FOR ANY SPECIAL, DIRECT,  * INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM  * LOSS OF USE, DATA OR PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE  * OR OTHER TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR  * PERFORMANCE OF THIS SOFTWARE.  */
end_comment

begin_comment
comment|/*  * Principal Author: Brian Wellington  * $Id: dst_result.c,v 1.1.4.1 2004/12/09 04:07:17 marka Exp $  */
end_comment

begin_include
include|#
directive|include
file|<config.h>
end_include

begin_include
include|#
directive|include
file|<isc/once.h>
end_include

begin_include
include|#
directive|include
file|<isc/util.h>
end_include

begin_include
include|#
directive|include
file|<dst/result.h>
end_include

begin_include
include|#
directive|include
file|<dst/lib.h>
end_include

begin_decl_stmt
specifier|static
specifier|const
name|char
modifier|*
name|text
index|[
name|DST_R_NRESULTS
index|]
init|=
block|{
literal|"algorithm is unsupported"
block|,
comment|/*  0 */
literal|"openssl failure"
block|,
comment|/*  1 */
literal|"built with no crypto support"
block|,
comment|/*  2 */
literal|"illegal operation for a null key"
block|,
comment|/*  3 */
literal|"public key is invalid"
block|,
comment|/*  4 */
literal|"private key is invalid"
block|,
comment|/*  5 */
literal|"UNUSED6"
block|,
comment|/*  6 */
literal|"error occurred writing key to disk"
block|,
comment|/*  7 */
literal|"invalid algorithm specific parameter"
block|,
comment|/*  8 */
literal|"UNUSED9"
block|,
comment|/*  9 */
literal|"UNUSED10"
block|,
comment|/* 10 */
literal|"sign failure"
block|,
comment|/* 11 */
literal|"UNUSED12"
block|,
comment|/* 12 */
literal|"UNUSED13"
block|,
comment|/* 13 */
literal|"verify failure"
block|,
comment|/* 14 */
literal|"not a public key"
block|,
comment|/* 15 */
literal|"not a private key"
block|,
comment|/* 16 */
literal|"not a key that can compute a secret"
block|,
comment|/* 17 */
literal|"failure computing a shared secret"
block|,
comment|/* 18 */
literal|"no randomness available"
block|,
comment|/* 19 */
literal|"bad key type"
comment|/* 20 */
block|}
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|DST_RESULT_RESULTSET
value|2
end_define

begin_decl_stmt
specifier|static
name|isc_once_t
name|once
init|=
name|ISC_ONCE_INIT
decl_stmt|;
end_decl_stmt

begin_function
specifier|static
name|void
name|initialize_action
parameter_list|(
name|void
parameter_list|)
block|{
name|isc_result_t
name|result
decl_stmt|;
name|result
operator|=
name|isc_result_register
argument_list|(
name|ISC_RESULTCLASS_DST
argument_list|,
name|DST_R_NRESULTS
argument_list|,
name|text
argument_list|,
name|dst_msgcat
argument_list|,
name|DST_RESULT_RESULTSET
argument_list|)
expr_stmt|;
if|if
condition|(
name|result
operator|!=
name|ISC_R_SUCCESS
condition|)
name|UNEXPECTED_ERROR
argument_list|(
name|__FILE__
argument_list|,
name|__LINE__
argument_list|,
literal|"isc_result_register() failed: %u"
argument_list|,
name|result
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
specifier|static
name|void
name|initialize
parameter_list|(
name|void
parameter_list|)
block|{
name|dst_lib_initmsgcat
argument_list|()
expr_stmt|;
name|RUNTIME_CHECK
argument_list|(
name|isc_once_do
argument_list|(
operator|&
name|once
argument_list|,
name|initialize_action
argument_list|)
operator|==
name|ISC_R_SUCCESS
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
specifier|const
name|char
modifier|*
name|dst_result_totext
parameter_list|(
name|isc_result_t
name|result
parameter_list|)
block|{
name|initialize
argument_list|()
expr_stmt|;
return|return
operator|(
name|isc_result_totext
argument_list|(
name|result
argument_list|)
operator|)
return|;
block|}
end_function

begin_function
name|void
name|dst_result_register
parameter_list|(
name|void
parameter_list|)
block|{
name|initialize
argument_list|()
expr_stmt|;
block|}
end_function

end_unit

