begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- llvm/Transforms/IPO/FunctionImport.h - ThinLTO importing -*- C++ -*-===//
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//                      The LLVM Compiler Infrastructure
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
name|LLVM_FUNCTIONIMPORT_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_FUNCTIONIMPORT_H
end_define

begin_include
include|#
directive|include
file|"llvm/ADT/StringMap.h"
end_include

begin_include
include|#
directive|include
file|<functional>
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|LLVMContext
decl_stmt|;
name|class
name|Module
decl_stmt|;
name|class
name|FunctionInfoIndex
decl_stmt|;
comment|/// The function importer is automatically importing function from other modules
comment|/// based on the provided summary informations.
name|class
name|FunctionImporter
block|{
comment|/// The summaries index used to trigger importing.
specifier|const
name|FunctionInfoIndex
modifier|&
name|Index
decl_stmt|;
comment|/// Factory function to load a Module for a given identifier
name|std
operator|::
name|function
operator|<
name|std
operator|::
name|unique_ptr
operator|<
name|Module
operator|>
operator|(
name|StringRef
name|Identifier
operator|)
operator|>
name|ModuleLoader
expr_stmt|;
name|public
label|:
comment|/// Create a Function Importer.
name|FunctionImporter
argument_list|(
specifier|const
name|FunctionInfoIndex
operator|&
name|Index
argument_list|,
name|std
operator|::
name|function
operator|<
name|std
operator|::
name|unique_ptr
operator|<
name|Module
operator|>
operator|(
name|StringRef
name|Identifier
operator|)
operator|>
name|ModuleLoader
argument_list|)
operator|:
name|Index
argument_list|(
name|Index
argument_list|)
operator|,
name|ModuleLoader
argument_list|(
argument|ModuleLoader
argument_list|)
block|{}
comment|/// Import functions in Module \p M based on the summary informations.
name|bool
name|importFunctions
argument_list|(
name|Module
operator|&
name|M
argument_list|)
expr_stmt|;
block|}
empty_stmt|;
block|}
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// LLVM_FUNCTIONIMPORT_H
end_comment

end_unit

