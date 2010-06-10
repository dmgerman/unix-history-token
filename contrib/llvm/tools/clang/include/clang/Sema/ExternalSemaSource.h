begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===--- ExternalSemaSource.h - External Sema Interface ---------*- C++ -*-===//
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
comment|//  This file defines the ExternalSemaSource interface.
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
name|LLVM_CLANG_SEMA_EXTERNAL_SEMA_SOURCE_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_CLANG_SEMA_EXTERNAL_SEMA_SOURCE_H
end_define

begin_include
include|#
directive|include
file|"clang/AST/DeclObjC.h"
end_include

begin_include
include|#
directive|include
file|"clang/AST/ExternalASTSource.h"
end_include

begin_decl_stmt
name|namespace
name|clang
block|{
name|class
name|Sema
decl_stmt|;
comment|/// \brief An abstract interface that should be implemented by
comment|/// external AST sources that also provide information for semantic
comment|/// analysis.
name|class
name|ExternalSemaSource
range|:
name|public
name|ExternalASTSource
block|{
name|public
operator|:
name|ExternalSemaSource
argument_list|()
block|{
name|ExternalASTSource
operator|::
name|SemaSource
operator|=
name|true
block|;   }
comment|/// \brief Initialize the semantic source with the Sema instance
comment|/// being used to perform semantic analysis on the abstract syntax
comment|/// tree.
name|virtual
name|void
name|InitializeSema
argument_list|(
argument|Sema&S
argument_list|)
block|{}
comment|/// \brief Inform the semantic consumer that Sema is no longer available.
name|virtual
name|void
name|ForgetSema
argument_list|()
block|{}
comment|/// \brief Load the contents of the global method pool for a given
comment|/// selector.
comment|///
comment|/// \returns a pair of Objective-C methods lists containing the
comment|/// instance and factory methods, respectively, with this selector.
name|virtual
name|std
operator|::
name|pair
operator|<
name|ObjCMethodList
block|,
name|ObjCMethodList
operator|>
name|ReadMethodPool
argument_list|(
argument|Selector Sel
argument_list|)
block|{
return|return
name|std
operator|::
name|pair
operator|<
name|ObjCMethodList
operator|,
name|ObjCMethodList
operator|>
operator|(
operator|)
return|;
block|}
comment|// isa/cast/dyn_cast support
specifier|static
name|bool
name|classof
argument_list|(
argument|const ExternalASTSource *Source
argument_list|)
block|{
return|return
name|Source
operator|->
name|SemaSource
return|;
block|}
specifier|static
name|bool
name|classof
argument_list|(
argument|const ExternalSemaSource *
argument_list|)
block|{
return|return
name|true
return|;
block|}
expr|}
block|;  }
end_decl_stmt

begin_comment
comment|// end namespace clang
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

