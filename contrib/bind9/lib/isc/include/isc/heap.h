begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (C) 2004  Internet Systems Consortium, Inc. ("ISC")  * Copyright (C) 1997-2001  Internet Software Consortium.  *  * Permission to use, copy, modify, and distribute this software for any  * purpose with or without fee is hereby granted, provided that the above  * copyright notice and this permission notice appear in all copies.  *  * THE SOFTWARE IS PROVIDED "AS IS" AND ISC DISCLAIMS ALL WARRANTIES WITH  * REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY  * AND FITNESS.  IN NO EVENT SHALL ISC BE LIABLE FOR ANY SPECIAL, DIRECT,  * INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM  * LOSS OF USE, DATA OR PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE  * OR OTHER TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR  * PERFORMANCE OF THIS SOFTWARE.  */
end_comment

begin_comment
comment|/* $Id: heap.h,v 1.16.206.1 2004/03/06 08:14:41 marka Exp $ */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|ISC_HEAP_H
end_ifndef

begin_define
define|#
directive|define
name|ISC_HEAP_H
value|1
end_define

begin_include
include|#
directive|include
file|<isc/lang.h>
end_include

begin_include
include|#
directive|include
file|<isc/types.h>
end_include

begin_macro
name|ISC_LANG_BEGINDECLS
end_macro

begin_comment
comment|/*  * The comparision function returns ISC_TRUE if the first argument has  * higher priority than the second argument, and ISC_FALSE otherwise.  */
end_comment

begin_typedef
typedef|typedef
name|isc_boolean_t
function_decl|(
modifier|*
name|isc_heapcompare_t
function_decl|)
parameter_list|(
name|void
modifier|*
parameter_list|,
name|void
modifier|*
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|void
function_decl|(
modifier|*
name|isc_heapindex_t
function_decl|)
parameter_list|(
name|void
modifier|*
parameter_list|,
name|unsigned
name|int
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|void
function_decl|(
modifier|*
name|isc_heapaction_t
function_decl|)
parameter_list|(
name|void
modifier|*
parameter_list|,
name|void
modifier|*
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|isc_heap
name|isc_heap_t
typedef|;
end_typedef

begin_function_decl
name|isc_result_t
name|isc_heap_create
parameter_list|(
name|isc_mem_t
modifier|*
parameter_list|,
name|isc_heapcompare_t
parameter_list|,
name|isc_heapindex_t
parameter_list|,
name|unsigned
name|int
parameter_list|,
name|isc_heap_t
modifier|*
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|isc_heap_destroy
parameter_list|(
name|isc_heap_t
modifier|*
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|isc_result_t
name|isc_heap_insert
parameter_list|(
name|isc_heap_t
modifier|*
parameter_list|,
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|isc_heap_delete
parameter_list|(
name|isc_heap_t
modifier|*
parameter_list|,
name|unsigned
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|isc_heap_increased
parameter_list|(
name|isc_heap_t
modifier|*
parameter_list|,
name|unsigned
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|isc_heap_decreased
parameter_list|(
name|isc_heap_t
modifier|*
parameter_list|,
name|unsigned
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
modifier|*
name|isc_heap_element
parameter_list|(
name|isc_heap_t
modifier|*
parameter_list|,
name|unsigned
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|isc_heap_foreach
parameter_list|(
name|isc_heap_t
modifier|*
parameter_list|,
name|isc_heapaction_t
parameter_list|,
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_macro
name|ISC_LANG_ENDDECLS
end_macro

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ISC_HEAP_H */
end_comment

end_unit

