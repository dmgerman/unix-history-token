begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-------------------------- unwind_ext.h ------------------------------===//
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//                     The LLVM Compiler Infrastructure
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// This file is dual licensed under the MIT and the University of Illinois Open
end_comment

begin_comment
comment|// Source Licenses. See LICENSE.TXT for details.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//  Extensions to unwind API.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//===----------------------------------------------------------------------===//
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__UNWIND_EXT__
end_ifndef

begin_define
define|#
directive|define
name|__UNWIND_EXT__
end_define

begin_include
include|#
directive|include
file|"unwind.h"
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|__cplusplus
end_ifdef

begin_extern
extern|extern
literal|"C"
block|{
endif|#
directive|endif
comment|// These platform specific functions to get and set the top context are
comment|// implemented elsewhere.
specifier|extern
name|struct
name|_Unwind_FunctionContext
modifier|*
name|__Unwind_SjLj_GetTopOfFunctionStack
parameter_list|()
function_decl|;
specifier|extern
name|void
name|__Unwind_SjLj_SetTopOfFunctionStack
parameter_list|(
name|struct
name|_Unwind_FunctionContext
modifier|*
name|fc
parameter_list|)
function_decl|;
ifdef|#
directive|ifdef
name|__cplusplus
block|}
end_extern

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// __UNWIND_EXT__
end_comment

end_unit

