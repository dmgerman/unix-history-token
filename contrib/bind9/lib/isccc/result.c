begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Portions Copyright (C) 2004  Internet Systems Consortium, Inc. ("ISC")  * Portions Copyright (C) 2001, 2003  Internet Software Consortium.  * Portions Copyright (C) 2001  Nominum, Inc.  *  * Permission to use, copy, modify, and distribute this software for any  * purpose with or without fee is hereby granted, provided that the above  * copyright notice and this permission notice appear in all copies.  *  * THE SOFTWARE IS PROVIDED "AS IS" AND ISC AND NOMINUM DISCLAIMS ALL  * WARRANTIES WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS.  IN NO EVENT SHALL ISC BE LIABLE FOR ANY  * SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES  * WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN  * ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF  * OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.  */
end_comment

begin_comment
comment|/* $Id: result.c,v 1.3.2.2.2.1 2004/03/06 08:15:19 marka Exp $ */
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
file|<isccc/result.h>
end_include

begin_include
include|#
directive|include
file|<isccc/lib.h>
end_include

begin_decl_stmt
specifier|static
specifier|const
name|char
modifier|*
name|text
index|[
name|ISCCC_R_NRESULTS
index|]
init|=
block|{
literal|"unknown version"
block|,
comment|/* 1 */
literal|"syntax error"
block|,
comment|/* 2 */
literal|"bad auth"
block|,
comment|/* 3 */
literal|"expired"
block|,
comment|/* 4 */
literal|"clock skew"
block|,
comment|/* 5 */
literal|"duplicate"
comment|/* 6 */
block|}
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|ISCCC_RESULT_RESULTSET
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
name|ISC_RESULTCLASS_ISCCC
argument_list|,
name|ISCCC_R_NRESULTS
argument_list|,
name|text
argument_list|,
name|isccc_msgcat
argument_list|,
name|ISCCC_RESULT_RESULTSET
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
name|isccc_lib_initmsgcat
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
name|isccc_result_totext
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
name|isccc_result_register
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

