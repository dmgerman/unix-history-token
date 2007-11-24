begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (C) 2004  Internet Systems Consortium, Inc. ("ISC")  * Copyright (C) 1998-2002  Internet Software Consortium.  *  * Permission to use, copy, modify, and distribute this software for any  * purpose with or without fee is hereby granted, provided that the above  * copyright notice and this permission notice appear in all copies.  *  * THE SOFTWARE IS PROVIDED "AS IS" AND ISC DISCLAIMS ALL WARRANTIES WITH  * REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY  * AND FITNESS.  IN NO EVENT SHALL ISC BE LIABLE FOR ANY SPECIAL, DIRECT,  * INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM  * LOSS OF USE, DATA OR PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE  * OR OTHER TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR  * PERFORMANCE OF THIS SOFTWARE.  */
end_comment

begin_comment
comment|/* $Id: region.h,v 1.16.12.3 2004/03/08 09:04:53 marka Exp $ */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|ISC_REGION_H
end_ifndef

begin_define
define|#
directive|define
name|ISC_REGION_H
value|1
end_define

begin_include
include|#
directive|include
file|<isc/types.h>
end_include

begin_struct
struct|struct
name|isc_region
block|{
name|unsigned
name|char
modifier|*
name|base
decl_stmt|;
name|unsigned
name|int
name|length
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|isc_textregion
block|{
name|char
modifier|*
name|base
decl_stmt|;
name|unsigned
name|int
name|length
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* XXXDCL questionable ... bears discussion.  we have been putting off  * discussing the region api.  */
end_comment

begin_struct
struct|struct
name|isc_constregion
block|{
specifier|const
name|void
modifier|*
name|base
decl_stmt|;
name|unsigned
name|int
name|length
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|isc_consttextregion
block|{
specifier|const
name|char
modifier|*
name|base
decl_stmt|;
name|unsigned
name|int
name|length
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * The region structure is not opaque, and is usually directly manipulated.  * Some macros are defined below for convenience.  */
end_comment

begin_define
define|#
directive|define
name|isc_region_consume
parameter_list|(
name|r
parameter_list|,
name|l
parameter_list|)
define|\
value|do { \ 		isc_region_t *_r = (r); \ 		unsigned int _l = (l); \ 		INSIST(_r->length>= _l); \ 		_r->base += _l; \ 		_r->length -= _l; \ 	} while (0)
end_define

begin_define
define|#
directive|define
name|isc_textregion_consume
parameter_list|(
name|r
parameter_list|,
name|l
parameter_list|)
define|\
value|do { \ 		isc_textregion_t *_r = (r); \ 		unsigned int _l = (l); \ 		INSIST(_r->length>= _l); \ 		_r->base += _l; \ 		_r->length -= _l; \ 	} while (0)
end_define

begin_define
define|#
directive|define
name|isc_constregion_consume
parameter_list|(
name|r
parameter_list|,
name|l
parameter_list|)
define|\
value|do { \ 		isc_constregion_t *_r = (r); \ 		unsigned int _l = (l); \ 		INSIST(_r->length>= _l); \ 		_r->base += _l; \ 		_r->length -= _l; \ 	} while (0)
end_define

begin_function_decl
name|int
name|isc_region_compare
parameter_list|(
name|isc_region_t
modifier|*
name|r1
parameter_list|,
name|isc_region_t
modifier|*
name|r2
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Compares the contents of two regions   *  * Requires:   *	'r1' is a valid region  *	'r2' is a valid region  *  * Returns:  *< 0 if r1 is lexicographically less than r2  *	 = 0 if r1 is lexicographically identical to r2  *> 0 if r1 is lexicographically greater than r2  */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ISC_REGION_H */
end_comment

end_unit

