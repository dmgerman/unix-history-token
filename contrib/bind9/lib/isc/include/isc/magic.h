begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (C) 2004  Internet Systems Consortium, Inc. ("ISC")  * Copyright (C) 1999-2001  Internet Software Consortium.  *  * Permission to use, copy, modify, and distribute this software for any  * purpose with or without fee is hereby granted, provided that the above  * copyright notice and this permission notice appear in all copies.  *  * THE SOFTWARE IS PROVIDED "AS IS" AND ISC DISCLAIMS ALL WARRANTIES WITH  * REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY  * AND FITNESS.  IN NO EVENT SHALL ISC BE LIABLE FOR ANY SPECIAL, DIRECT,  * INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM  * LOSS OF USE, DATA OR PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE  * OR OTHER TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR  * PERFORMANCE OF THIS SOFTWARE.  */
end_comment

begin_comment
comment|/* $Id: magic.h,v 1.11.206.1 2004/03/06 08:14:43 marka Exp $ */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|ISC_MAGIC_H
end_ifndef

begin_define
define|#
directive|define
name|ISC_MAGIC_H
value|1
end_define

begin_typedef
typedef|typedef
struct|struct
block|{
name|unsigned
name|int
name|magic
decl_stmt|;
block|}
name|isc__magic_t
typedef|;
end_typedef

begin_comment
comment|/*  * To use this macro the magic number MUST be the first thing in the  * structure, and MUST be of type "unsigned int".  *  * The intent of this is to allow magic numbers to be checked even though  * the object is otherwise opaque.  */
end_comment

begin_define
define|#
directive|define
name|ISC_MAGIC_VALID
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|(((a) != NULL)&& \ 				 (((const isc__magic_t *)(a))->magic == (b)))
end_define

begin_define
define|#
directive|define
name|ISC_MAGIC
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|,
name|c
parameter_list|,
name|d
parameter_list|)
value|((a)<< 24 | (b)<< 16 | (c)<< 8 | (d))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ISC_MAGIC_H */
end_comment

end_unit

