begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===---- CoverageMappingGen.h - Coverage mapping generation ----*- C++ -*-===//
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
comment|// Instrumentation-based code coverage mapping generator
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
name|LLVM_CLANG_LIB_CODEGEN_COVERAGEMAPPINGGEN_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_CLANG_LIB_CODEGEN_COVERAGEMAPPINGGEN_H
end_define

begin_include
include|#
directive|include
file|"clang/Basic/LLVM.h"
end_include

begin_include
include|#
directive|include
file|"clang/Basic/SourceLocation.h"
end_include

begin_include
include|#
directive|include
file|"clang/Frontend/CodeGenOptions.h"
end_include

begin_include
include|#
directive|include
file|"clang/Lex/PPCallbacks.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/DenseMap.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/StringMap.h"
end_include

begin_include
include|#
directive|include
file|"llvm/IR/GlobalValue.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/raw_ostream.h"
end_include

begin_decl_stmt
name|namespace
name|clang
block|{
name|class
name|LangOptions
decl_stmt|;
name|class
name|SourceManager
decl_stmt|;
name|class
name|FileEntry
decl_stmt|;
name|class
name|Preprocessor
decl_stmt|;
name|class
name|Decl
decl_stmt|;
name|class
name|Stmt
decl_stmt|;
comment|/// \brief Stores additional source code information like skipped ranges which
comment|/// is required by the coverage mapping generator and is obtained from
comment|/// the preprocessor.
name|class
name|CoverageSourceInfo
range|:
name|public
name|PPCallbacks
block|{
name|std
operator|::
name|vector
operator|<
name|SourceRange
operator|>
name|SkippedRanges
block|;
name|public
operator|:
name|ArrayRef
operator|<
name|SourceRange
operator|>
name|getSkippedRanges
argument_list|()
specifier|const
block|{
return|return
name|SkippedRanges
return|;
block|}
name|void
name|SourceRangeSkipped
argument_list|(
argument|SourceRange Range
argument_list|)
name|override
block|; }
decl_stmt|;
name|namespace
name|CodeGen
block|{
name|class
name|CodeGenModule
decl_stmt|;
comment|/// \brief Organizes the cross-function state that is used while generating
comment|/// code coverage mapping data.
name|class
name|CoverageMappingModuleGen
block|{
name|CodeGenModule
modifier|&
name|CGM
decl_stmt|;
name|CoverageSourceInfo
modifier|&
name|SourceInfo
decl_stmt|;
name|llvm
operator|::
name|SmallDenseMap
operator|<
specifier|const
name|FileEntry
operator|*
operator|,
name|unsigned
operator|,
literal|8
operator|>
name|FileEntries
expr_stmt|;
name|std
operator|::
name|vector
operator|<
name|llvm
operator|::
name|Constant
operator|*
operator|>
name|FunctionRecords
expr_stmt|;
name|llvm
operator|::
name|StructType
operator|*
name|FunctionRecordTy
expr_stmt|;
name|std
operator|::
name|string
name|CoverageMappings
expr_stmt|;
name|public
label|:
name|CoverageMappingModuleGen
argument_list|(
name|CodeGenModule
operator|&
name|CGM
argument_list|,
name|CoverageSourceInfo
operator|&
name|SourceInfo
argument_list|)
operator|:
name|CGM
argument_list|(
name|CGM
argument_list|)
operator|,
name|SourceInfo
argument_list|(
name|SourceInfo
argument_list|)
operator|,
name|FunctionRecordTy
argument_list|(
argument|nullptr
argument_list|)
block|{}
name|CoverageSourceInfo
operator|&
name|getSourceInfo
argument_list|()
specifier|const
block|{
return|return
name|SourceInfo
return|;
block|}
comment|/// \brief Add a function's coverage mapping record to the collection of the
comment|/// function mapping records.
name|void
name|addFunctionMappingRecord
argument_list|(
name|llvm
operator|::
name|GlobalVariable
operator|*
name|FunctionName
argument_list|,
name|StringRef
name|FunctionNameValue
argument_list|,
name|uint64_t
name|FunctionHash
argument_list|,
specifier|const
name|std
operator|::
name|string
operator|&
name|CoverageMapping
argument_list|)
decl_stmt|;
comment|/// \brief Emit the coverage mapping data for a translation unit.
name|void
name|emit
parameter_list|()
function_decl|;
comment|/// \brief Return the coverage mapping translation unit file id
comment|/// for the given file.
name|unsigned
name|getFileID
parameter_list|(
specifier|const
name|FileEntry
modifier|*
name|File
parameter_list|)
function_decl|;
block|}
empty_stmt|;
comment|/// \brief Organizes the per-function state that is used while generating
comment|/// code coverage mapping data.
name|class
name|CoverageMappingGen
block|{
name|CoverageMappingModuleGen
modifier|&
name|CVM
decl_stmt|;
name|SourceManager
modifier|&
name|SM
decl_stmt|;
specifier|const
name|LangOptions
modifier|&
name|LangOpts
decl_stmt|;
name|llvm
operator|::
name|DenseMap
operator|<
specifier|const
name|Stmt
operator|*
operator|,
name|unsigned
operator|>
operator|*
name|CounterMap
expr_stmt|;
name|public
label|:
name|CoverageMappingGen
argument_list|(
name|CoverageMappingModuleGen
operator|&
name|CVM
argument_list|,
name|SourceManager
operator|&
name|SM
argument_list|,
specifier|const
name|LangOptions
operator|&
name|LangOpts
argument_list|)
operator|:
name|CVM
argument_list|(
name|CVM
argument_list|)
operator|,
name|SM
argument_list|(
name|SM
argument_list|)
operator|,
name|LangOpts
argument_list|(
name|LangOpts
argument_list|)
operator|,
name|CounterMap
argument_list|(
argument|nullptr
argument_list|)
block|{}
name|CoverageMappingGen
argument_list|(
name|CoverageMappingModuleGen
operator|&
name|CVM
argument_list|,
name|SourceManager
operator|&
name|SM
argument_list|,
specifier|const
name|LangOptions
operator|&
name|LangOpts
argument_list|,
name|llvm
operator|::
name|DenseMap
operator|<
specifier|const
name|Stmt
operator|*
argument_list|,
name|unsigned
operator|>
operator|*
name|CounterMap
argument_list|)
operator|:
name|CVM
argument_list|(
name|CVM
argument_list|)
operator|,
name|SM
argument_list|(
name|SM
argument_list|)
operator|,
name|LangOpts
argument_list|(
name|LangOpts
argument_list|)
operator|,
name|CounterMap
argument_list|(
argument|CounterMap
argument_list|)
block|{}
comment|/// \brief Emit the coverage mapping data which maps the regions of
comment|/// code to counters that will be used to find the execution
comment|/// counts for those regions.
name|void
name|emitCounterMapping
argument_list|(
specifier|const
name|Decl
operator|*
name|D
argument_list|,
name|llvm
operator|::
name|raw_ostream
operator|&
name|OS
argument_list|)
expr_stmt|;
comment|/// \brief Emit the coverage mapping data for an unused function.
comment|/// It creates mapping regions with the counter of zero.
name|void
name|emitEmptyMapping
argument_list|(
specifier|const
name|Decl
operator|*
name|D
argument_list|,
name|llvm
operator|::
name|raw_ostream
operator|&
name|OS
argument_list|)
decl_stmt|;
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

