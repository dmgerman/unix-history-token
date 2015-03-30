begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (C) 2004, 2007  Internet Systems Consortium, Inc. ("ISC")  * Copyright (C) 1998-2001  Internet Software Consortium.  *  * Permission to use, copy, modify, and/or distribute this software for any  * purpose with or without fee is hereby granted, provided that the above  * copyright notice and this permission notice appear in all copies.  *  * THE SOFTWARE IS PROVIDED "AS IS" AND ISC DISCLAIMS ALL WARRANTIES WITH  * REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY  * AND FITNESS.  IN NO EVENT SHALL ISC BE LIABLE FOR ANY SPECIAL, DIRECT,  * INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM  * LOSS OF USE, DATA OR PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE  * OR OTHER TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR  * PERFORMANCE OF THIS SOFTWARE.  */
end_comment

begin_comment
comment|/* $Id: condition.h,v 1.17 2007/06/18 23:47:49 tbox Exp $ */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|ISC_CONDITION_H
end_ifndef

begin_define
define|#
directive|define
name|ISC_CONDITION_H
value|1
end_define

begin_include
include|#
directive|include
file|<windows.h>
end_include

begin_include
include|#
directive|include
file|<isc/lang.h>
end_include

begin_include
include|#
directive|include
file|<isc/mutex.h>
end_include

begin_include
include|#
directive|include
file|<isc/thread.h>
end_include

begin_include
include|#
directive|include
file|<isc/types.h>
end_include

begin_typedef
typedef|typedef
name|struct
name|isc_condition_thread
name|isc_condition_thread_t
typedef|;
end_typedef

begin_struct
struct|struct
name|isc_condition_thread
block|{
name|unsigned
name|long
name|th
decl_stmt|;
name|HANDLE
name|handle
index|[
literal|2
index|]
decl_stmt|;
name|ISC_LINK
argument_list|(
argument|isc_condition_thread_t
argument_list|)
name|link
expr_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
struct|struct
name|isc_condition
block|{
name|HANDLE
name|events
index|[
literal|2
index|]
decl_stmt|;
name|unsigned
name|int
name|waiters
decl_stmt|;
name|ISC_LIST
argument_list|(
argument|isc_condition_thread_t
argument_list|)
name|threadlist
expr_stmt|;
block|}
name|isc_condition_t
typedef|;
end_typedef

begin_function_decl
name|ISC_LANG_BEGINDECLS
name|isc_result_t
name|isc_condition_init
parameter_list|(
name|isc_condition_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|isc_result_t
name|isc_condition_wait
parameter_list|(
name|isc_condition_t
modifier|*
parameter_list|,
name|isc_mutex_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|isc_result_t
name|isc_condition_signal
parameter_list|(
name|isc_condition_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|isc_result_t
name|isc_condition_broadcast
parameter_list|(
name|isc_condition_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|isc_result_t
name|isc_condition_destroy
parameter_list|(
name|isc_condition_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|isc_result_t
name|isc_condition_waituntil
parameter_list|(
name|isc_condition_t
modifier|*
parameter_list|,
name|isc_mutex_t
modifier|*
parameter_list|,
name|isc_time_t
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
comment|/* ISC_CONDITION_H */
end_comment

end_unit

