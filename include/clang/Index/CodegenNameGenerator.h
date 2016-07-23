begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- CodegenNameGenerator.h - Codegen name generation -------------------===//
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
comment|// Determines the name that the symbol will get for code generation.
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
name|LLVM_CLANG_INDEX_CODEGENNAMEGENERATOR_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_CLANG_INDEX_CODEGENNAMEGENERATOR_H
end_define

begin_include
include|#
directive|include
file|"clang/Basic/LLVM.h"
end_include

begin_include
include|#
directive|include
file|<memory>
end_include

begin_include
include|#
directive|include
file|<string>
end_include

begin_include
include|#
directive|include
file|<vector>
end_include

begin_decl_stmt
name|namespace
name|clang
block|{
name|class
name|ASTContext
decl_stmt|;
name|class
name|Decl
decl_stmt|;
name|namespace
name|index
block|{
name|class
name|CodegenNameGenerator
block|{
name|public
label|:
name|explicit
name|CodegenNameGenerator
parameter_list|(
name|ASTContext
modifier|&
name|Ctx
parameter_list|)
function_decl|;
operator|~
name|CodegenNameGenerator
argument_list|()
expr_stmt|;
comment|/// \returns true on failure to produce a name for the given decl, false on
comment|/// success.
name|bool
name|writeName
parameter_list|(
specifier|const
name|Decl
modifier|*
name|D
parameter_list|,
name|raw_ostream
modifier|&
name|OS
parameter_list|)
function_decl|;
comment|/// Version of \c writeName function that returns a string.
name|std
operator|::
name|string
name|getName
argument_list|(
specifier|const
name|Decl
operator|*
name|D
argument_list|)
expr_stmt|;
comment|/// This can return multiple mangled names when applicable, e.g. for C++
comment|/// constructors/destructors.
name|std
operator|::
name|vector
operator|<
name|std
operator|::
name|string
operator|>
name|getAllManglings
argument_list|(
specifier|const
name|Decl
operator|*
name|D
argument_list|)
expr_stmt|;
name|private
label|:
struct_decl|struct
name|Implementation
struct_decl|;
name|std
operator|::
name|unique_ptr
operator|<
name|Implementation
operator|>
name|Impl
expr_stmt|;
block|}
empty_stmt|;
block|}
comment|// namespace index
block|}
end_decl_stmt

begin_comment
comment|// namespace clang
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// LLVM_CLANG_INDEX_CODEGENNAMEGENERATOR_H
end_comment

end_unit

