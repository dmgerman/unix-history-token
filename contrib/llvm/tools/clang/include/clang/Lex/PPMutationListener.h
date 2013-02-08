begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===--- PPMutationListener.h - Preprocessor Mutation Interface -*- C++ -*-===//
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

begin_comment
comment|//
end_comment

begin_comment
comment|//  This file defines the PPMutationListener interface.
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
name|LLVM_CLANG_LEX_PPTMUTATIONLISTENER_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_CLANG_LEX_PPTMUTATIONLISTENER_H
end_define

begin_include
include|#
directive|include
file|"clang/Basic/SourceLocation.h"
end_include

begin_decl_stmt
name|namespace
name|clang
block|{
name|class
name|MacroInfo
decl_stmt|;
comment|/// \brief A record that describes an update to a macro that was
comment|/// originally loaded to an AST file and has been modified within the
comment|/// current translation unit.
struct|struct
name|MacroUpdate
block|{
comment|/// \brief The source location at which this macro was #undef'd.
name|SourceLocation
name|UndefLoc
decl_stmt|;
block|}
struct|;
comment|/// \brief An abstract interface that should be implemented by
comment|/// listeners that want to be notified when a preprocessor entity gets
comment|/// modified after its initial creation.
name|class
name|PPMutationListener
block|{
name|public
label|:
name|virtual
operator|~
name|PPMutationListener
argument_list|()
expr_stmt|;
comment|/// \brief A macro has been #undef'd.
name|virtual
name|void
name|UndefinedMacro
parameter_list|(
name|MacroInfo
modifier|*
name|MI
parameter_list|)
block|{ }
block|}
empty_stmt|;
block|}
end_decl_stmt

begin_comment
comment|// end namespace clang
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

