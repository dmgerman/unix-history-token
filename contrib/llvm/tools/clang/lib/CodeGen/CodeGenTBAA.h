begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===--- CodeGenTBAA.h - TBAA information for LLVM CodeGen ------*- C++ -*-===//
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
comment|// This is the code that manages TBAA information and defines the TBAA policy
end_comment

begin_comment
comment|// for the optimizer to use.
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
name|CLANG_CODEGEN_CODEGENTBAA_H
end_ifndef

begin_define
define|#
directive|define
name|CLANG_CODEGEN_CODEGENTBAA_H
end_define

begin_include
include|#
directive|include
file|"llvm/LLVMContext.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/DenseMap.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|LLVMContext
decl_stmt|;
name|class
name|MDNode
decl_stmt|;
block|}
end_decl_stmt

begin_decl_stmt
name|namespace
name|clang
block|{
name|class
name|ASTContext
decl_stmt|;
name|class
name|LangOptions
decl_stmt|;
name|class
name|MangleContext
decl_stmt|;
name|class
name|QualType
decl_stmt|;
name|class
name|Type
decl_stmt|;
name|namespace
name|CodeGen
block|{
name|class
name|CGRecordLayout
decl_stmt|;
comment|/// CodeGenTBAA - This class organizes the cross-module state that is used
comment|/// while lowering AST types to LLVM types.
name|class
name|CodeGenTBAA
block|{
name|ASTContext
modifier|&
name|Context
decl_stmt|;
name|llvm
operator|::
name|LLVMContext
operator|&
name|VMContext
expr_stmt|;
specifier|const
name|LangOptions
modifier|&
name|Features
decl_stmt|;
name|MangleContext
modifier|&
name|MContext
decl_stmt|;
comment|/// MetadataCache - This maps clang::Types to llvm::MDNodes describing them.
name|llvm
operator|::
name|DenseMap
operator|<
specifier|const
name|Type
operator|*
operator|,
name|llvm
operator|::
name|MDNode
operator|*
operator|>
name|MetadataCache
expr_stmt|;
name|llvm
operator|::
name|MDNode
operator|*
name|Root
expr_stmt|;
name|llvm
operator|::
name|MDNode
operator|*
name|Char
expr_stmt|;
comment|/// getRoot - This is the mdnode for the root of the metadata type graph
comment|/// for this translation unit.
name|llvm
operator|::
name|MDNode
operator|*
name|getRoot
argument_list|()
expr_stmt|;
comment|/// getChar - This is the mdnode for "char", which is special, and any types
comment|/// considered to be equivalent to it.
name|llvm
operator|::
name|MDNode
operator|*
name|getChar
argument_list|()
expr_stmt|;
name|llvm
operator|::
name|MDNode
operator|*
name|getTBAAInfoForNamedType
argument_list|(
argument|llvm::StringRef NameStr
argument_list|,
argument|llvm::MDNode *Parent
argument_list|,
argument|bool Readonly = false
argument_list|)
expr_stmt|;
name|public
label|:
name|CodeGenTBAA
argument_list|(
name|ASTContext
operator|&
name|Ctx
argument_list|,
name|llvm
operator|::
name|LLVMContext
operator|&
name|VMContext
argument_list|,
specifier|const
name|LangOptions
operator|&
name|Features
argument_list|,
name|MangleContext
operator|&
name|MContext
argument_list|)
expr_stmt|;
operator|~
name|CodeGenTBAA
argument_list|()
expr_stmt|;
comment|/// getTBAAInfo - Get the TBAA MDNode to be used for a dereference
comment|/// of the given type.
name|llvm
operator|::
name|MDNode
operator|*
name|getTBAAInfo
argument_list|(
argument|QualType QTy
argument_list|)
expr_stmt|;
block|}
empty_stmt|;
block|}
comment|// end namespace CodeGen
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

