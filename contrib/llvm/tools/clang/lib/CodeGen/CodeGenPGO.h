begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===--- CodeGenPGO.h - PGO Instrumentation for LLVM CodeGen ----*- C++ -*-===//
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
comment|// Instrumentation-based profile-guided optimization
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
name|LLVM_CLANG_LIB_CODEGEN_CODEGENPGO_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_CLANG_LIB_CODEGEN_CODEGENPGO_H
end_define

begin_include
include|#
directive|include
file|"CGBuilder.h"
end_include

begin_include
include|#
directive|include
file|"CodeGenModule.h"
end_include

begin_include
include|#
directive|include
file|"CodeGenTypes.h"
end_include

begin_include
include|#
directive|include
file|"clang/Frontend/CodeGenOptions.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/StringMap.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/MemoryBuffer.h"
end_include

begin_include
include|#
directive|include
file|<memory>
end_include

begin_decl_stmt
name|namespace
name|clang
block|{
name|namespace
name|CodeGen
block|{
comment|/// Per-function PGO state.
name|class
name|CodeGenPGO
block|{
name|private
label|:
name|CodeGenModule
modifier|&
name|CGM
decl_stmt|;
name|std
operator|::
name|string
name|FuncName
expr_stmt|;
name|llvm
operator|::
name|GlobalVariable
operator|*
name|FuncNameVar
expr_stmt|;
name|unsigned
name|NumRegionCounters
decl_stmt|;
name|uint64_t
name|FunctionHash
decl_stmt|;
name|std
operator|::
name|unique_ptr
operator|<
name|llvm
operator|::
name|DenseMap
operator|<
specifier|const
name|Stmt
operator|*
operator|,
name|unsigned
operator|>>
name|RegionCounterMap
expr_stmt|;
name|std
operator|::
name|unique_ptr
operator|<
name|llvm
operator|::
name|DenseMap
operator|<
specifier|const
name|Stmt
operator|*
operator|,
name|uint64_t
operator|>>
name|StmtCountMap
expr_stmt|;
name|std
operator|::
name|vector
operator|<
name|uint64_t
operator|>
name|RegionCounts
expr_stmt|;
name|uint64_t
name|CurrentRegionCount
decl_stmt|;
comment|/// \brief A flag that is set to true when this function doesn't need
comment|/// to have coverage mapping data.
name|bool
name|SkipCoverageMapping
decl_stmt|;
name|public
label|:
name|CodeGenPGO
argument_list|(
name|CodeGenModule
operator|&
name|CGM
argument_list|)
operator|:
name|CGM
argument_list|(
name|CGM
argument_list|)
operator|,
name|NumRegionCounters
argument_list|(
literal|0
argument_list|)
operator|,
name|FunctionHash
argument_list|(
literal|0
argument_list|)
operator|,
name|CurrentRegionCount
argument_list|(
literal|0
argument_list|)
operator|,
name|SkipCoverageMapping
argument_list|(
argument|false
argument_list|)
block|{}
comment|/// Whether or not we have PGO region data for the current function. This is
comment|/// false both when we have no data at all and when our data has been
comment|/// discarded.
name|bool
name|haveRegionCounts
argument_list|()
specifier|const
block|{
return|return
operator|!
name|RegionCounts
operator|.
name|empty
argument_list|()
return|;
block|}
comment|/// Return the counter value of the current region.
name|uint64_t
name|getCurrentRegionCount
argument_list|()
specifier|const
block|{
return|return
name|CurrentRegionCount
return|;
block|}
comment|/// Set the counter value for the current region. This is used to keep track
comment|/// of changes to the most recent counter from control flow and non-local
comment|/// exits.
name|void
name|setCurrentRegionCount
parameter_list|(
name|uint64_t
name|Count
parameter_list|)
block|{
name|CurrentRegionCount
operator|=
name|Count
expr_stmt|;
block|}
comment|/// Check if an execution count is known for a given statement. If so, return
comment|/// true and put the value in Count; else return false.
name|Optional
operator|<
name|uint64_t
operator|>
name|getStmtCount
argument_list|(
argument|const Stmt *S
argument_list|)
block|{
if|if
condition|(
operator|!
name|StmtCountMap
condition|)
return|return
name|None
return|;
name|auto
name|I
operator|=
name|StmtCountMap
operator|->
name|find
argument_list|(
name|S
argument_list|)
expr_stmt|;
if|if
condition|(
name|I
operator|==
name|StmtCountMap
operator|->
name|end
argument_list|()
condition|)
return|return
name|None
return|;
return|return
name|I
operator|->
name|second
return|;
block|}
comment|/// If the execution count for the current statement is known, record that
comment|/// as the current count.
name|void
name|setCurrentStmt
parameter_list|(
specifier|const
name|Stmt
modifier|*
name|S
parameter_list|)
block|{
if|if
condition|(
name|auto
name|Count
init|=
name|getStmtCount
argument_list|(
name|S
argument_list|)
condition|)
name|setCurrentRegionCount
argument_list|(
operator|*
name|Count
argument_list|)
expr_stmt|;
block|}
comment|/// Assign counters to regions and configure them for PGO of a given
comment|/// function. Does nothing if instrumentation is not enabled and either
comment|/// generates global variables or associates PGO data with each of the
comment|/// counters depending on whether we are generating or using instrumentation.
name|void
name|assignRegionCounters
argument_list|(
name|GlobalDecl
name|GD
argument_list|,
name|llvm
operator|::
name|Function
operator|*
name|Fn
argument_list|)
decl_stmt|;
comment|/// Emit a coverage mapping range with a counter zero
comment|/// for an unused declaration.
name|void
name|emitEmptyCounterMapping
argument_list|(
specifier|const
name|Decl
operator|*
name|D
argument_list|,
name|StringRef
name|FuncName
argument_list|,
name|llvm
operator|::
name|GlobalValue
operator|::
name|LinkageTypes
name|Linkage
argument_list|)
decl_stmt|;
name|private
label|:
name|void
name|setFuncName
argument_list|(
name|llvm
operator|::
name|Function
operator|*
name|Fn
argument_list|)
decl_stmt|;
name|void
name|setFuncName
argument_list|(
name|StringRef
name|Name
argument_list|,
name|llvm
operator|::
name|GlobalValue
operator|::
name|LinkageTypes
name|Linkage
argument_list|)
decl_stmt|;
name|void
name|mapRegionCounters
parameter_list|(
specifier|const
name|Decl
modifier|*
name|D
parameter_list|)
function_decl|;
name|void
name|computeRegionCounts
parameter_list|(
specifier|const
name|Decl
modifier|*
name|D
parameter_list|)
function_decl|;
name|void
name|applyFunctionAttributes
argument_list|(
name|llvm
operator|::
name|IndexedInstrProfReader
operator|*
name|PGOReader
argument_list|,
name|llvm
operator|::
name|Function
operator|*
name|Fn
argument_list|)
decl_stmt|;
name|void
name|loadRegionCounts
argument_list|(
name|llvm
operator|::
name|IndexedInstrProfReader
operator|*
name|PGOReader
argument_list|,
name|bool
name|IsInMainFile
argument_list|)
decl_stmt|;
name|void
name|emitCounterRegionMapping
parameter_list|(
specifier|const
name|Decl
modifier|*
name|D
parameter_list|)
function_decl|;
name|public
label|:
name|void
name|emitCounterIncrement
parameter_list|(
name|CGBuilderTy
modifier|&
name|Builder
parameter_list|,
specifier|const
name|Stmt
modifier|*
name|S
parameter_list|)
function_decl|;
comment|/// Return the region count for the counter at the given index.
name|uint64_t
name|getRegionCount
parameter_list|(
specifier|const
name|Stmt
modifier|*
name|S
parameter_list|)
block|{
if|if
condition|(
operator|!
name|RegionCounterMap
condition|)
return|return
literal|0
return|;
if|if
condition|(
operator|!
name|haveRegionCounts
argument_list|()
condition|)
return|return
literal|0
return|;
return|return
name|RegionCounts
index|[
operator|(
operator|*
name|RegionCounterMap
operator|)
index|[
name|S
index|]
index|]
return|;
block|}
block|}
empty_stmt|;
block|}
end_decl_stmt

begin_comment
comment|// end namespace CodeGen
end_comment

begin_comment
unit|}
comment|// end namespace clang
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

