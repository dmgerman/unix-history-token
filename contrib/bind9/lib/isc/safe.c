begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (C) 2013  Internet Systems Consortium, Inc. ("ISC")  *  * Permission to use, copy, modify, and/or distribute this software for any  * purpose with or without fee is hereby granted, provided that the above  * copyright notice and this permission notice appear in all copies.  *  * THE SOFTWARE IS PROVIDED "AS IS" AND ISC DISCLAIMS ALL WARRANTIES WITH  * REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY  * AND FITNESS.  IN NO EVENT SHALL ISC BE LIABLE FOR ANY SPECIAL, DIRECT,  * INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM  * LOSS OF USE, DATA OR PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE  * OR OTHER TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR  * PERFORMANCE OF THIS SOFTWARE.  */
end_comment

begin_comment
comment|/* $Id$ */
end_comment

begin_comment
comment|/*! \file */
end_comment

begin_include
include|#
directive|include
file|<config.h>
end_include

begin_include
include|#
directive|include
file|<isc/safe.h>
end_include

begin_include
include|#
directive|include
file|<isc/util.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|_MSC_VER
end_ifdef

begin_pragma
pragma|#
directive|pragma
name|optimize
name|(
literal|""
name|,
name|off
name|)
end_pragma

begin_endif
endif|#
directive|endif
end_endif

begin_function
name|isc_boolean_t
name|isc_safe_memcmp
parameter_list|(
specifier|const
name|void
modifier|*
name|s1
parameter_list|,
specifier|const
name|void
modifier|*
name|s2
parameter_list|,
name|size_t
name|n
parameter_list|)
block|{
name|isc_uint8_t
name|acc
init|=
literal|0
decl_stmt|;
if|if
condition|(
name|n
operator|!=
literal|0U
condition|)
block|{
specifier|const
name|isc_uint8_t
modifier|*
name|p1
init|=
name|s1
decl_stmt|,
modifier|*
name|p2
init|=
name|s2
decl_stmt|;
do|do
block|{
name|acc
operator||=
operator|*
name|p1
operator|++
operator|^
operator|*
name|p2
operator|++
expr_stmt|;
block|}
do|while
condition|(
operator|--
name|n
operator|!=
literal|0U
condition|)
do|;
block|}
return|return
operator|(
name|ISC_TF
argument_list|(
name|acc
operator|==
literal|0
argument_list|)
operator|)
return|;
block|}
end_function

end_unit

