begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$Id: acss.h,v 1.2 2004/02/06 04:22:43 dtucker Exp $ */
end_comment

begin_comment
comment|/*  * Copyright (c) 2004 The OpenBSD project  *  * Permission to use, copy, modify, and distribute this software for any  * purpose with or without fee is hereby granted, provided that the above  * copyright notice and this permission notice appear in all copies.  *  * THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES  * WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF  * MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR  * ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES  * WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN  * ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF  * OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_ACSS_H_
end_ifndef

begin_define
define|#
directive|define
name|_ACSS_H_
end_define

begin_comment
comment|/* 40bit key */
end_comment

begin_define
define|#
directive|define
name|ACSS_KEYSIZE
value|5
end_define

begin_comment
comment|/* modes of acss */
end_comment

begin_define
define|#
directive|define
name|ACSS_AUTHENTICATE
value|0
end_define

begin_define
define|#
directive|define
name|ACSS_SESSIONKEY
value|1
end_define

begin_define
define|#
directive|define
name|ACSS_TITLEKEY
value|2
end_define

begin_define
define|#
directive|define
name|ACSS_DATA
value|3
end_define

begin_typedef
typedef|typedef
struct|struct
name|acss_key_st
block|{
name|unsigned
name|int
name|lfsr17
decl_stmt|;
comment|/* current state of lfsrs */
name|unsigned
name|int
name|lfsr25
decl_stmt|;
name|unsigned
name|int
name|lfsrsum
decl_stmt|;
name|unsigned
name|char
name|seed
index|[
name|ACSS_KEYSIZE
index|]
decl_stmt|;
name|unsigned
name|char
name|data
index|[
name|ACSS_KEYSIZE
index|]
decl_stmt|;
name|unsigned
name|char
name|subkey
index|[
name|ACSS_KEYSIZE
index|]
decl_stmt|;
name|int
name|encrypt
decl_stmt|;
comment|/* XXX make these bit flags? */
name|int
name|mode
decl_stmt|;
name|int
name|seeded
decl_stmt|;
name|int
name|subkey_avilable
decl_stmt|;
block|}
name|ACSS_KEY
typedef|;
end_typedef

begin_function_decl
name|void
name|acss_setkey
parameter_list|(
name|ACSS_KEY
modifier|*
parameter_list|,
specifier|const
name|unsigned
name|char
modifier|*
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|acss_setsubkey
parameter_list|(
name|ACSS_KEY
modifier|*
parameter_list|,
specifier|const
name|unsigned
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|acss
parameter_list|(
name|ACSS_KEY
modifier|*
parameter_list|,
name|unsigned
name|long
parameter_list|,
specifier|const
name|unsigned
name|char
modifier|*
parameter_list|,
name|unsigned
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ifndef _ACSS_H_ */
end_comment

end_unit

