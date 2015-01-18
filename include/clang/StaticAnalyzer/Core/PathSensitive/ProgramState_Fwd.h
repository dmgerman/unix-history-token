begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//== ProgramState_Fwd.h - Incomplete declarations of ProgramState -*- C++ -*--=/
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
comment|// This file is distributed under the University of Illinois Open Source
end_comment

begin_comment
comment|// License. See LICENSE.TXT for details.
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
name|LLVM_CLANG_STATICANALYZER_CORE_PATHSENSITIVE_PROGRAMSTATE_FWD_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_CLANG_STATICANALYZER_CORE_PATHSENSITIVE_PROGRAMSTATE_FWD_H
end_define

begin_include
include|#
directive|include
file|"clang/Basic/LLVM.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/IntrusiveRefCntPtr.h"
end_include

begin_decl_stmt
name|namespace
name|clang
block|{
name|namespace
name|ento
block|{
name|class
name|ProgramState
decl_stmt|;
name|class
name|ProgramStateManager
decl_stmt|;
name|void
name|ProgramStateRetain
parameter_list|(
specifier|const
name|ProgramState
modifier|*
name|state
parameter_list|)
function_decl|;
name|void
name|ProgramStateRelease
parameter_list|(
specifier|const
name|ProgramState
modifier|*
name|state
parameter_list|)
function_decl|;
block|}
block|}
end_decl_stmt

begin_decl_stmt
name|namespace
name|llvm
block|{
name|template
operator|<
operator|>
expr|struct
name|IntrusiveRefCntPtrInfo
operator|<
specifier|const
name|clang
operator|::
name|ento
operator|::
name|ProgramState
operator|>
block|{
specifier|static
name|void
name|retain
argument_list|(
argument|const clang::ento::ProgramState *state
argument_list|)
block|{
name|clang
operator|::
name|ento
operator|::
name|ProgramStateRetain
argument_list|(
name|state
argument_list|)
block|;     }
specifier|static
name|void
name|release
argument_list|(
argument|const clang::ento::ProgramState *state
argument_list|)
block|{
name|clang
operator|::
name|ento
operator|::
name|ProgramStateRelease
argument_list|(
name|state
argument_list|)
block|;     }
block|}
expr_stmt|;
block|}
end_decl_stmt

begin_decl_stmt
name|namespace
name|clang
block|{
name|namespace
name|ento
block|{
typedef|typedef
name|IntrusiveRefCntPtr
operator|<
specifier|const
name|ProgramState
operator|>
name|ProgramStateRef
expr_stmt|;
block|}
block|}
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

