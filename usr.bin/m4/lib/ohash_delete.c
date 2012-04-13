begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $OpenBSD: ohash_delete.c,v 1.2 2004/06/22 20:00:16 espie Exp $ */
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

begin_comment
comment|/* hash_delete only frees the hash structure. Use hash_first/hash_next  * to free entries as well.  */
end_comment

begin_function
name|void
name|ohash_delete
parameter_list|(
name|struct
name|ohash
modifier|*
name|h
parameter_list|)
block|{
call|(
name|h
operator|->
name|info
operator|.
name|hfree
call|)
argument_list|(
name|h
operator|->
name|t
argument_list|,
sizeof|sizeof
argument_list|(
expr|struct
name|_ohash_record
argument_list|)
operator|*
name|h
operator|->
name|size
argument_list|,
name|h
operator|->
name|info
operator|.
name|data
argument_list|)
expr_stmt|;
ifndef|#
directive|ifndef
name|NDEBUG
name|h
operator|->
name|t
operator|=
name|NULL
expr_stmt|;
endif|#
directive|endif
block|}
end_function

end_unit

