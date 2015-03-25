begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//=== MangleNumberingContext.h - Context for mangling numbers ---*- C++ -*-===//
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
comment|//  This file defines the LambdaBlockMangleContext interface, which keeps track
end_comment

begin_comment
comment|//  of the Itanium C++ ABI mangling numbers for lambda expressions and block
end_comment

begin_comment
comment|//  literals.
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
name|LLVM_CLANG_AST_MANGLENUMBERINGCONTEXT_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_CLANG_AST_MANGLENUMBERINGCONTEXT_H
end_define

begin_include
include|#
directive|include
file|"clang/Basic/LLVM.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/DenseMap.h"
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
name|class
name|BlockDecl
decl_stmt|;
name|class
name|CXXMethodDecl
decl_stmt|;
name|class
name|IdentifierInfo
decl_stmt|;
name|class
name|TagDecl
decl_stmt|;
name|class
name|Type
decl_stmt|;
name|class
name|VarDecl
decl_stmt|;
comment|/// \brief Keeps track of the mangled names of lambda expressions and block
comment|/// literals within a particular context.
name|class
name|MangleNumberingContext
range|:
name|public
name|RefCountedBase
operator|<
name|MangleNumberingContext
operator|>
block|{
name|public
operator|:
name|virtual
operator|~
name|MangleNumberingContext
argument_list|()
block|{}
comment|/// \brief Retrieve the mangling number of a new lambda expression with the
comment|/// given call operator within this context.
name|virtual
name|unsigned
name|getManglingNumber
argument_list|(
specifier|const
name|CXXMethodDecl
operator|*
name|CallOperator
argument_list|)
operator|=
literal|0
block|;
comment|/// \brief Retrieve the mangling number of a new block literal within this
comment|/// context.
name|virtual
name|unsigned
name|getManglingNumber
argument_list|(
specifier|const
name|BlockDecl
operator|*
name|BD
argument_list|)
operator|=
literal|0
block|;
comment|/// Static locals are numbered by source order.
name|virtual
name|unsigned
name|getStaticLocalNumber
argument_list|(
specifier|const
name|VarDecl
operator|*
name|VD
argument_list|)
operator|=
literal|0
block|;
comment|/// \brief Retrieve the mangling number of a static local variable within
comment|/// this context.
name|virtual
name|unsigned
name|getManglingNumber
argument_list|(
argument|const VarDecl *VD
argument_list|,
argument|unsigned MSLocalManglingNumber
argument_list|)
operator|=
literal|0
block|;
comment|/// \brief Retrieve the mangling number of a static local variable within
comment|/// this context.
name|virtual
name|unsigned
name|getManglingNumber
argument_list|(
argument|const TagDecl *TD
argument_list|,
argument|unsigned MSLocalManglingNumber
argument_list|)
operator|=
literal|0
block|; }
decl_stmt|;
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

