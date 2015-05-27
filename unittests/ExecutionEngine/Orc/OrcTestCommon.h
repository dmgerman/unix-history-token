begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===------ OrcTestCommon.h - Utilities for Orc Unit Tests ------*- C++ -*-===//
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
comment|// Common utilities for the Orc unit tests.
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
name|LLVM_UNITTESTS_EXECUTIONENGINE_ORC_ORCTESTCOMMON_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_UNITTESTS_EXECUTIONENGINE_ORC_ORCTESTCOMMON_H
end_define

begin_include
include|#
directive|include
file|"llvm/IR/Function.h"
end_include

begin_include
include|#
directive|include
file|"llvm/IR/IRBuilder.h"
end_include

begin_include
include|#
directive|include
file|"llvm/IR/LLVMContext.h"
end_include

begin_include
include|#
directive|include
file|"llvm/IR/Module.h"
end_include

begin_include
include|#
directive|include
file|"llvm/IR/TypeBuilder.h"
end_include

begin_include
include|#
directive|include
file|<memory>
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|ModuleBuilder
block|{
name|public
label|:
name|ModuleBuilder
argument_list|(
argument|LLVMContext&Context
argument_list|,
argument|StringRef Triple
argument_list|,
argument|StringRef Name
argument_list|)
empty_stmt|;
name|template
operator|<
name|typename
name|FuncType
operator|>
name|Function
operator|*
name|createFunctionDecl
argument_list|(
argument|Module *M
argument_list|,
argument|StringRef Name
argument_list|)
block|{
return|return
name|Function
operator|::
name|Create
argument_list|(
name|TypeBuilder
operator|<
name|FuncType
argument_list|,
name|false
operator|>
operator|::
name|get
argument_list|(
name|M
operator|->
name|getContext
argument_list|()
argument_list|)
argument_list|,
name|GlobalValue
operator|::
name|ExternalLinkage
argument_list|,
name|Name
argument_list|,
name|M
argument_list|)
return|;
block|}
name|Module
modifier|*
name|getModule
parameter_list|()
block|{
return|return
name|M
operator|.
name|get
argument_list|()
return|;
block|}
specifier|const
name|Module
operator|*
name|getModule
argument_list|()
specifier|const
block|{
return|return
name|M
operator|.
name|get
argument_list|()
return|;
block|}
name|std
operator|::
name|unique_ptr
operator|<
name|Module
operator|>
name|takeModule
argument_list|()
block|{
return|return
name|std
operator|::
name|move
argument_list|(
name|M
argument_list|)
return|;
block|}
name|private
label|:
name|std
operator|::
name|unique_ptr
operator|<
name|Module
operator|>
name|M
expr_stmt|;
name|IRBuilder
operator|<
operator|>
name|Builder
expr_stmt|;
block|}
empty_stmt|;
comment|// Dummy struct type.
struct|struct
name|DummyStruct
block|{
name|int
name|X
index|[
literal|256
index|]
decl_stmt|;
block|}
struct|;
comment|// TypeBuilder specialization for DummyStruct.
name|template
operator|<
name|bool
name|XCompile
operator|>
name|class
name|TypeBuilder
operator|<
name|DummyStruct
operator|,
name|XCompile
operator|>
block|{
name|public
operator|:
specifier|static
name|StructType
operator|*
name|get
argument_list|(
argument|LLVMContext&Context
argument_list|)
block|{
return|return
name|StructType
operator|::
name|get
argument_list|(
name|TypeBuilder
operator|<
name|types
operator|::
name|i
operator|<
literal|32
operator|>
index|[
literal|256
index|]
argument_list|,
name|XCompile
operator|>
operator|::
name|get
argument_list|(
name|Context
argument_list|)
argument_list|,
name|nullptr
argument_list|)
return|;
block|}
expr|}
block|;   }
end_decl_stmt

begin_comment
comment|// namespace llvm
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

