begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- ExpressionTypeSystemHelper.h ---------------------------------*- C++ -*-===//
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
name|ExpressionTypeSystemHelper_h
end_ifndef

begin_define
define|#
directive|define
name|ExpressionTypeSystemHelper_h
end_define

begin_include
include|#
directive|include
file|"llvm/Support/Casting.h"
end_include

begin_decl_stmt
name|namespace
name|lldb_private
block|{
comment|//----------------------------------------------------------------------
comment|/// @class ExpressionTypeSystemHelper ExpressionTypeSystemHelper.h "lldb/Expression/ExpressionTypeSystemHelper.h"
comment|/// @brief A helper object that the Expression can pass to its ExpressionParser to provide generic information that
comment|/// any type of expression will need to supply.  It's only job is to support dyn_cast so that the expression parser
comment|/// can cast it back to the requisite specific type.
comment|///
comment|//----------------------------------------------------------------------
name|class
name|ExpressionTypeSystemHelper
block|{
name|public
label|:
enum|enum
name|LLVMCastKind
block|{
name|eKindClangHelper
block|,
name|eKindSwiftHelper
block|,
name|eKindGoHelper
block|,
name|kNumKinds
block|}
enum|;
name|LLVMCastKind
name|getKind
argument_list|()
specifier|const
block|{
return|return
name|m_kind
return|;
block|}
name|ExpressionTypeSystemHelper
argument_list|(
argument|LLVMCastKind kind
argument_list|)
block|:
name|m_kind
argument_list|(
argument|kind
argument_list|)
block|{     }
operator|~
name|ExpressionTypeSystemHelper
argument_list|()
block|{}
name|protected
operator|:
name|LLVMCastKind
name|m_kind
expr_stmt|;
block|}
empty_stmt|;
block|}
end_decl_stmt

begin_comment
comment|// namespace lldb_private
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ExpressionTypeSystemHelper_h */
end_comment

end_unit

