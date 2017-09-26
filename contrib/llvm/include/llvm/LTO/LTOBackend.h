begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-LTOBackend.h - LLVM Link Time Optimizer Backend ---------------------===//
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
comment|// This file implements the "backend" phase of LTO, i.e. it performs
end_comment

begin_comment
comment|// optimization and code generation on a loaded module. It is generally used
end_comment

begin_comment
comment|// internally by the LTO class but can also be used independently, for example
end_comment

begin_comment
comment|// to implement a standalone ThinLTO backend.
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
name|LLVM_LTO_LTOBACKEND_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_LTO_LTOBACKEND_H
end_define

begin_include
include|#
directive|include
file|"llvm/ADT/MapVector.h"
end_include

begin_include
include|#
directive|include
file|"llvm/IR/DiagnosticInfo.h"
end_include

begin_include
include|#
directive|include
file|"llvm/IR/ModuleSummaryIndex.h"
end_include

begin_include
include|#
directive|include
file|"llvm/LTO/LTO.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/MemoryBuffer.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Target/TargetOptions.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Transforms/IPO/FunctionImport.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|BitcodeModule
decl_stmt|;
name|class
name|Error
decl_stmt|;
name|class
name|Module
decl_stmt|;
name|class
name|Target
decl_stmt|;
name|namespace
name|lto
block|{
comment|/// Runs a regular LTO backend. The regular LTO backend can also act as the
comment|/// regular LTO phase of ThinLTO, which may need to access the combined index.
name|Error
name|backend
argument_list|(
name|Config
operator|&
name|C
argument_list|,
name|AddStreamFn
name|AddStream
argument_list|,
name|unsigned
name|ParallelCodeGenParallelismLevel
argument_list|,
name|std
operator|::
name|unique_ptr
operator|<
name|Module
operator|>
name|M
argument_list|,
name|ModuleSummaryIndex
operator|&
name|CombinedIndex
argument_list|)
decl_stmt|;
comment|/// Runs a ThinLTO backend.
name|Error
name|thinBackend
argument_list|(
name|Config
operator|&
name|C
argument_list|,
name|unsigned
name|Task
argument_list|,
name|AddStreamFn
name|AddStream
argument_list|,
name|Module
operator|&
name|M
argument_list|,
specifier|const
name|ModuleSummaryIndex
operator|&
name|CombinedIndex
argument_list|,
specifier|const
name|FunctionImporter
operator|::
name|ImportMapTy
operator|&
name|ImportList
argument_list|,
specifier|const
name|GVSummaryMapTy
operator|&
name|DefinedGlobals
argument_list|,
name|MapVector
operator|<
name|StringRef
argument_list|,
name|BitcodeModule
operator|>
operator|&
name|ModuleMap
argument_list|)
decl_stmt|;
block|}
block|}
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

