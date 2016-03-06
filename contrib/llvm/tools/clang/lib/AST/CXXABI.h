begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===----- CXXABI.h - Interface to C++ ABIs ---------------------*- C++ -*-===//
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
comment|// This provides an abstract class for C++ AST support. Concrete
end_comment

begin_comment
comment|// subclasses of this implement AST support for specific C++ ABIs.
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
name|LLVM_CLANG_LIB_AST_CXXABI_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_CLANG_LIB_AST_CXXABI_H
end_define

begin_include
include|#
directive|include
file|"clang/AST/Type.h"
end_include

begin_decl_stmt
name|namespace
name|clang
block|{
name|class
name|ASTContext
decl_stmt|;
name|class
name|CXXConstructorDecl
decl_stmt|;
name|class
name|DeclaratorDecl
decl_stmt|;
name|class
name|Expr
decl_stmt|;
name|class
name|MemberPointerType
decl_stmt|;
name|class
name|MangleNumberingContext
decl_stmt|;
comment|/// Implements C++ ABI-specific semantic analysis functions.
name|class
name|CXXABI
block|{
name|public
label|:
name|virtual
operator|~
name|CXXABI
argument_list|()
expr_stmt|;
comment|/// Returns the width and alignment of a member pointer in bits.
name|virtual
name|std
operator|::
name|pair
operator|<
name|uint64_t
operator|,
name|unsigned
operator|>
name|getMemberPointerWidthAndAlign
argument_list|(
argument|const MemberPointerType *MPT
argument_list|)
specifier|const
operator|=
literal|0
expr_stmt|;
comment|/// Returns the default calling convention for C++ methods.
name|virtual
name|CallingConv
name|getDefaultMethodCallConv
argument_list|(
name|bool
name|isVariadic
argument_list|)
decl|const
init|=
literal|0
decl_stmt|;
comment|/// Returns whether the given class is nearly empty, with just virtual
comment|/// pointers and no data except possibly virtual bases.
name|virtual
name|bool
name|isNearlyEmpty
argument_list|(
specifier|const
name|CXXRecordDecl
operator|*
name|RD
argument_list|)
decl|const
init|=
literal|0
decl_stmt|;
comment|/// Returns a new mangling number context for this C++ ABI.
name|virtual
name|MangleNumberingContext
operator|*
name|createMangleNumberingContext
argument_list|()
specifier|const
operator|=
literal|0
expr_stmt|;
comment|/// Adds a mapping from class to copy constructor for this C++ ABI.
name|virtual
name|void
name|addCopyConstructorForExceptionObject
parameter_list|(
name|CXXRecordDecl
modifier|*
parameter_list|,
name|CXXConstructorDecl
modifier|*
parameter_list|)
init|=
literal|0
function_decl|;
comment|/// Retrieves the mapping from class to copy constructor for this C++ ABI.
name|virtual
specifier|const
name|CXXConstructorDecl
modifier|*
name|getCopyConstructorForExceptionObject
parameter_list|(
name|CXXRecordDecl
modifier|*
parameter_list|)
init|=
literal|0
function_decl|;
name|virtual
name|void
name|addDefaultArgExprForConstructor
parameter_list|(
specifier|const
name|CXXConstructorDecl
modifier|*
name|CD
parameter_list|,
name|unsigned
name|ParmIdx
parameter_list|,
name|Expr
modifier|*
name|DAE
parameter_list|)
init|=
literal|0
function_decl|;
name|virtual
name|Expr
modifier|*
name|getDefaultArgExprForConstructor
parameter_list|(
specifier|const
name|CXXConstructorDecl
modifier|*
name|CD
parameter_list|,
name|unsigned
name|ParmIdx
parameter_list|)
init|=
literal|0
function_decl|;
name|virtual
name|void
name|addTypedefNameForUnnamedTagDecl
parameter_list|(
name|TagDecl
modifier|*
name|TD
parameter_list|,
name|TypedefNameDecl
modifier|*
name|DD
parameter_list|)
init|=
literal|0
function_decl|;
name|virtual
name|TypedefNameDecl
modifier|*
name|getTypedefNameForUnnamedTagDecl
parameter_list|(
specifier|const
name|TagDecl
modifier|*
name|TD
parameter_list|)
init|=
literal|0
function_decl|;
name|virtual
name|void
name|addDeclaratorForUnnamedTagDecl
parameter_list|(
name|TagDecl
modifier|*
name|TD
parameter_list|,
name|DeclaratorDecl
modifier|*
name|DD
parameter_list|)
init|=
literal|0
function_decl|;
name|virtual
name|DeclaratorDecl
modifier|*
name|getDeclaratorForUnnamedTagDecl
parameter_list|(
specifier|const
name|TagDecl
modifier|*
name|TD
parameter_list|)
init|=
literal|0
function_decl|;
block|}
empty_stmt|;
comment|/// Creates an instance of a C++ ABI class.
name|CXXABI
modifier|*
name|CreateItaniumCXXABI
parameter_list|(
name|ASTContext
modifier|&
name|Ctx
parameter_list|)
function_decl|;
name|CXXABI
modifier|*
name|CreateMicrosoftCXXABI
parameter_list|(
name|ASTContext
modifier|&
name|Ctx
parameter_list|)
function_decl|;
block|}
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

