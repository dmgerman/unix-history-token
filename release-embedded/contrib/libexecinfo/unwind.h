begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$NetBSD: unwind.h,v 1.1 2012/05/26 22:02:29 christos Exp $	*/
end_comment

begin_comment
comment|/*-  * Copyright (c) 2012 The NetBSD Foundation, Inc.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE NETBSD FOUNDATION, INC. AND CONTRIBUTORS  * ``AS IS'' AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED  * TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR  * PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL THE FOUNDATION OR CONTRIBUTORS  * BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR  * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF  * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS  * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN  * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)  * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE  * POSSIBILITY OF SUCH DAMAGE.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_UNWIND_H_
end_ifndef

begin_define
define|#
directive|define
name|_UNWIND_H_
end_define

begin_macro
name|__BEGIN_DECLS
end_macro

begin_struct_decl
struct_decl|struct
name|_Unwind_Context
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|_Unwind_Exception
struct_decl|;
end_struct_decl

begin_typedef
typedef|typedef
name|int
name|_Unwind_Reason_Code
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|void
modifier|*
name|_Unwind_Ptr
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|long
name|_Unwind_Word
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|_Unwind_Reason_Code
function_decl|(
modifier|*
name|_Unwind_Trace_Fn
function_decl|)
parameter_list|(
name|struct
name|_Unwind_Context
modifier|*
parameter_list|,
name|void
modifier|*
parameter_list|)
function_decl|;
end_typedef

begin_ifdef
ifdef|#
directive|ifdef
name|notyet
end_ifdef

begin_typedef
typedef|typedef
name|_Unwind_Reason_Code
function_decl|(
modifier|*
name|_Unwind_Stop_Fn
function_decl|)
parameter_list|(
name|struct
name|_Unwind_Context
modifier|*
parameter_list|,
name|void
modifier|*
parameter_list|)
function_decl|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_function_decl
name|_Unwind_Reason_Code
name|_Unwind_Backtrace
parameter_list|(
name|_Unwind_Trace_Fn
parameter_list|,
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|_Unwind_DeleteException
parameter_list|(
name|struct
name|_Unwind_Exception
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
modifier|*
name|_Unwind_FindEnclosingFunction
parameter_list|(
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_ifdef
ifdef|#
directive|ifdef
name|notyet
end_ifdef

begin_function_decl
name|_Unwind_Reason_Code
name|_Unwind_ForcedUnwind
parameter_list|(
name|struct
name|_Unwind_Exception
modifier|*
parameter_list|,
name|_Unwind_Stop_fn
parameter_list|,
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_function_decl
name|_Unwind_Word
name|_Unwind_GetCFA
parameter_list|(
name|struct
name|_Unwind_Context
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|_Unwind_Ptr
name|_Unwind_GetDataRelBase
parameter_list|(
name|struct
name|_Unwind_Context
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|_Unwind_Word
name|_Unwind_GetGR
parameter_list|(
name|struct
name|_Unwind_Context
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|_Unwind_Ptr
name|_Unwind_GetIP
parameter_list|(
name|struct
name|_Unwind_Context
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|_Unwind_Ptr
name|_Unwind_GetIPInfo
parameter_list|(
name|struct
name|_Unwind_Context
modifier|*
parameter_list|,
name|int
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
modifier|*
name|_Unwind_GetLanguageSpecificData
parameter_list|(
name|struct
name|_Unwind_Context
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|_Unwind_Ptr
name|_Unwind_GetRegionStart
parameter_list|(
name|struct
name|_Unwind_Context
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|_Unwind_Ptr
name|_Unwind_GetTextRelBase
parameter_list|(
name|struct
name|_Unwind_Context
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|_Unwind_Reason_Code
name|_Unwind_RaiseException
parameter_list|(
name|struct
name|_Unwind_Exception
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|_Unwind_Resume
parameter_list|(
name|struct
name|_Unwind_Exception
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|_Unwind_Reason_Code
name|_Unwind_Resume_or_Rethrow
parameter_list|(
name|struct
name|_Unwind_Exception
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|_Unwind_SetGR
parameter_list|(
name|struct
name|_Unwind_Context
modifier|*
parameter_list|,
name|int
parameter_list|,
name|_Unwind_Ptr
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|_Unwind_SetIP
parameter_list|(
name|struct
name|_Unwind_Context
modifier|*
parameter_list|,
name|_Unwind_Ptr
parameter_list|)
function_decl|;
end_function_decl

begin_macro
name|__END_DECLS
end_macro

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _UNWIND_H_ */
end_comment

end_unit

