begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $OpenBSD: ohash_qlookup.c,v 1.2 2004/06/22 20:00:17 espie Exp $ */
end_comment

begin_comment
comment|/* ex:ts=8 sw=4:   */
end_comment

begin_comment
comment|/* Copyright (c) 1999, 2004 Marc Espie<espie@openbsd.org>  *  * Permission to use, copy, modify, and distribute this software for any  * purpose with or without fee is hereby granted, provided that the above  * copyright notice and this permission notice appear in all copies.  *  * THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES  * WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF  * MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR  * ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES  * WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN  * ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF  * OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.  */
end_comment

begin_include
include|#
directive|include
file|<sys/cdefs.h>
end_include

begin_expr_stmt
name|__FBSDID
argument_list|(
literal|"$FreeBSD$"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_include
include|#
directive|include
file|"ohash_int.h"
end_include

begin_function
name|unsigned
name|int
name|ohash_qlookup
parameter_list|(
name|struct
name|ohash
modifier|*
name|h
parameter_list|,
specifier|const
name|char
modifier|*
name|s
parameter_list|)
block|{
specifier|const
name|char
modifier|*
name|e
init|=
name|NULL
decl_stmt|;
return|return
name|ohash_qlookupi
argument_list|(
name|h
argument_list|,
name|s
argument_list|,
operator|&
name|e
argument_list|)
return|;
block|}
end_function

end_unit

