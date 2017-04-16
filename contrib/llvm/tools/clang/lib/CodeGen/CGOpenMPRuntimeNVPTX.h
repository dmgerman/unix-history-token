begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===----- CGOpenMPRuntimeNVPTX.h - Interface to OpenMP NVPTX Runtimes ----===//
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
comment|// This provides a class for OpenMP runtime code generation specialized to NVPTX
end_comment

begin_comment
comment|// targets.
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
name|LLVM_CLANG_LIB_CODEGEN_CGOPENMPRUNTIMENVPTX_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_CLANG_LIB_CODEGEN_CGOPENMPRUNTIMENVPTX_H
end_define

begin_include
include|#
directive|include
file|"CGOpenMPRuntime.h"
end_include

begin_include
include|#
directive|include
file|"CodeGenFunction.h"
end_include

begin_include
include|#
directive|include
file|"clang/AST/StmtOpenMP.h"
end_include

begin_include
include|#
directive|include
file|"llvm/IR/CallSite.h"
end_include

begin_decl_stmt
name|namespace
name|clang
block|{
name|namespace
name|CodeGen
block|{
name|class
name|CGOpenMPRuntimeNVPTX
range|:
name|public
name|CGOpenMPRuntime
block|{
name|private
operator|:
comment|// Parallel outlined function work for workers to execute.
name|llvm
operator|::
name|SmallVector
operator|<
name|llvm
operator|::
name|Function
operator|*
block|,
literal|16
operator|>
name|Work
block|;    struct
name|EntryFunctionState
block|{
name|llvm
operator|::
name|BasicBlock
operator|*
name|ExitBB
operator|=
name|nullptr
block|;   }
block|;
name|class
name|WorkerFunctionState
block|{
name|public
operator|:
name|llvm
operator|::
name|Function
operator|*
name|WorkerFn
block|;
specifier|const
name|CGFunctionInfo
operator|*
name|CGFI
block|;
name|WorkerFunctionState
argument_list|(
name|CodeGenModule
operator|&
name|CGM
argument_list|)
block|;
name|private
operator|:
name|void
name|createWorkerFunction
argument_list|(
name|CodeGenModule
operator|&
name|CGM
argument_list|)
block|;   }
block|;
name|bool
name|isInSpmdExecutionMode
argument_list|()
specifier|const
block|;
comment|/// \brief Emit the worker function for the current target region.
name|void
name|emitWorkerFunction
argument_list|(
name|WorkerFunctionState
operator|&
name|WST
argument_list|)
block|;
comment|/// \brief Helper for worker function. Emit body of worker loop.
name|void
name|emitWorkerLoop
argument_list|(
name|CodeGenFunction
operator|&
name|CGF
argument_list|,
name|WorkerFunctionState
operator|&
name|WST
argument_list|)
block|;
comment|/// \brief Helper for generic target entry function. Guide the master and
comment|/// worker threads to their respective locations.
name|void
name|emitGenericEntryHeader
argument_list|(
name|CodeGenFunction
operator|&
name|CGF
argument_list|,
name|EntryFunctionState
operator|&
name|EST
argument_list|,
name|WorkerFunctionState
operator|&
name|WST
argument_list|)
block|;
comment|/// \brief Signal termination of OMP execution for generic target entry
comment|/// function.
name|void
name|emitGenericEntryFooter
argument_list|(
name|CodeGenFunction
operator|&
name|CGF
argument_list|,
name|EntryFunctionState
operator|&
name|EST
argument_list|)
block|;
comment|/// \brief Helper for Spmd mode target directive's entry function.
name|void
name|emitSpmdEntryHeader
argument_list|(
name|CodeGenFunction
operator|&
name|CGF
argument_list|,
name|EntryFunctionState
operator|&
name|EST
argument_list|,
specifier|const
name|OMPExecutableDirective
operator|&
name|D
argument_list|)
block|;
comment|/// \brief Signal termination of Spmd mode execution.
name|void
name|emitSpmdEntryFooter
argument_list|(
name|CodeGenFunction
operator|&
name|CGF
argument_list|,
name|EntryFunctionState
operator|&
name|EST
argument_list|)
block|;
comment|//
comment|// Base class overrides.
comment|//
comment|/// \brief Creates offloading entry for the provided entry ID \a ID,
comment|/// address \a Addr, size \a Size, and flags \a Flags.
name|void
name|createOffloadEntry
argument_list|(
argument|llvm::Constant *ID
argument_list|,
argument|llvm::Constant *Addr
argument_list|,
argument|uint64_t Size
argument_list|,
argument|int32_t Flags =
literal|0
argument_list|)
name|override
block|;
comment|/// \brief Emit outlined function specialized for the Fork-Join
comment|/// programming model for applicable target directives on the NVPTX device.
comment|/// \param D Directive to emit.
comment|/// \param ParentName Name of the function that encloses the target region.
comment|/// \param OutlinedFn Outlined function value to be defined by this call.
comment|/// \param OutlinedFnID Outlined function ID value to be defined by this call.
comment|/// \param IsOffloadEntry True if the outlined function is an offload entry.
comment|/// An outlined function may not be an entry if, e.g. the if clause always
comment|/// evaluates to false.
name|void
name|emitGenericKernel
argument_list|(
argument|const OMPExecutableDirective&D
argument_list|,
argument|StringRef ParentName
argument_list|,
argument|llvm::Function *&OutlinedFn
argument_list|,
argument|llvm::Constant *&OutlinedFnID
argument_list|,
argument|bool IsOffloadEntry
argument_list|,
argument|const RegionCodeGenTy&CodeGen
argument_list|)
block|;
comment|/// \brief Emit outlined function specialized for the Single Program
comment|/// Multiple Data programming model for applicable target directives on the
comment|/// NVPTX device.
comment|/// \param D Directive to emit.
comment|/// \param ParentName Name of the function that encloses the target region.
comment|/// \param OutlinedFn Outlined function value to be defined by this call.
comment|/// \param OutlinedFnID Outlined function ID value to be defined by this call.
comment|/// \param IsOffloadEntry True if the outlined function is an offload entry.
comment|/// \param CodeGen Object containing the target statements.
comment|/// An outlined function may not be an entry if, e.g. the if clause always
comment|/// evaluates to false.
name|void
name|emitSpmdKernel
argument_list|(
argument|const OMPExecutableDirective&D
argument_list|,
argument|StringRef ParentName
argument_list|,
argument|llvm::Function *&OutlinedFn
argument_list|,
argument|llvm::Constant *&OutlinedFnID
argument_list|,
argument|bool IsOffloadEntry
argument_list|,
argument|const RegionCodeGenTy&CodeGen
argument_list|)
block|;
comment|/// \brief Emit outlined function for 'target' directive on the NVPTX
comment|/// device.
comment|/// \param D Directive to emit.
comment|/// \param ParentName Name of the function that encloses the target region.
comment|/// \param OutlinedFn Outlined function value to be defined by this call.
comment|/// \param OutlinedFnID Outlined function ID value to be defined by this call.
comment|/// \param IsOffloadEntry True if the outlined function is an offload entry.
comment|/// An outlined function may not be an entry if, e.g. the if clause always
comment|/// evaluates to false.
name|void
name|emitTargetOutlinedFunction
argument_list|(
argument|const OMPExecutableDirective&D
argument_list|,
argument|StringRef ParentName
argument_list|,
argument|llvm::Function *&OutlinedFn
argument_list|,
argument|llvm::Constant *&OutlinedFnID
argument_list|,
argument|bool IsOffloadEntry
argument_list|,
argument|const RegionCodeGenTy&CodeGen
argument_list|)
name|override
block|;
comment|/// \brief Emits code for parallel or serial call of the \a OutlinedFn with
comment|/// variables captured in a record which address is stored in \a
comment|/// CapturedStruct.
comment|/// This call is for the Generic Execution Mode.
comment|/// \param OutlinedFn Outlined function to be run in parallel threads. Type of
comment|/// this function is void(*)(kmp_int32 *, kmp_int32, struct context_vars*).
comment|/// \param CapturedVars A pointer to the record with the references to
comment|/// variables used in \a OutlinedFn function.
comment|/// \param IfCond Condition in the associated 'if' clause, if it was
comment|/// specified, nullptr otherwise.
name|void
name|emitGenericParallelCall
argument_list|(
argument|CodeGenFunction&CGF
argument_list|,
argument|SourceLocation Loc
argument_list|,
argument|llvm::Value *OutlinedFn
argument_list|,
argument|ArrayRef<llvm::Value *> CapturedVars
argument_list|,
argument|const Expr *IfCond
argument_list|)
block|;
comment|/// \brief Emits code for parallel or serial call of the \a OutlinedFn with
comment|/// variables captured in a record which address is stored in \a
comment|/// CapturedStruct.
comment|/// This call is for a parallel directive within an SPMD target directive.
comment|/// \param OutlinedFn Outlined function to be run in parallel threads. Type of
comment|/// this function is void(*)(kmp_int32 *, kmp_int32, struct context_vars*).
comment|/// \param CapturedVars A pointer to the record with the references to
comment|/// variables used in \a OutlinedFn function.
comment|/// \param IfCond Condition in the associated 'if' clause, if it was
comment|/// specified, nullptr otherwise.
comment|///
name|void
name|emitSpmdParallelCall
argument_list|(
argument|CodeGenFunction&CGF
argument_list|,
argument|SourceLocation Loc
argument_list|,
argument|llvm::Value *OutlinedFn
argument_list|,
argument|ArrayRef<llvm::Value *> CapturedVars
argument_list|,
argument|const Expr *IfCond
argument_list|)
block|;
name|protected
operator|:
comment|/// \brief Get the function name of an outlined region.
comment|//  The name can be customized depending on the target.
comment|//
name|StringRef
name|getOutlinedHelperName
argument_list|()
specifier|const
name|override
block|{
return|return
literal|"__omp_outlined__"
return|;
block|}
name|public
operator|:
name|explicit
name|CGOpenMPRuntimeNVPTX
argument_list|(
name|CodeGenModule
operator|&
name|CGM
argument_list|)
block|;
comment|/// \brief Emit call to void __kmpc_push_proc_bind(ident_t *loc, kmp_int32
comment|/// global_tid, int proc_bind) to generate code for 'proc_bind' clause.
name|virtual
name|void
name|emitProcBindClause
argument_list|(
argument|CodeGenFunction&CGF
argument_list|,
argument|OpenMPProcBindClauseKind ProcBind
argument_list|,
argument|SourceLocation Loc
argument_list|)
name|override
block|;
comment|/// \brief Emits call to void __kmpc_push_num_threads(ident_t *loc, kmp_int32
comment|/// global_tid, kmp_int32 num_threads) to generate code for 'num_threads'
comment|/// clause.
comment|/// \param NumThreads An integer value of threads.
name|virtual
name|void
name|emitNumThreadsClause
argument_list|(
argument|CodeGenFunction&CGF
argument_list|,
argument|llvm::Value *NumThreads
argument_list|,
argument|SourceLocation Loc
argument_list|)
name|override
block|;
comment|/// \brief This function ought to emit, in the general case, a call to
comment|// the openmp runtime kmpc_push_num_teams. In NVPTX backend it is not needed
comment|// as these numbers are obtained through the PTX grid and block configuration.
comment|/// \param NumTeams An integer expression of teams.
comment|/// \param ThreadLimit An integer expression of threads.
name|void
name|emitNumTeamsClause
argument_list|(
argument|CodeGenFunction&CGF
argument_list|,
argument|const Expr *NumTeams
argument_list|,
argument|const Expr *ThreadLimit
argument_list|,
argument|SourceLocation Loc
argument_list|)
name|override
block|;
comment|/// \brief Emits inlined function for the specified OpenMP parallel
comment|//  directive.
comment|/// \a D. This outlined function has type void(*)(kmp_int32 *ThreadID,
comment|/// kmp_int32 BoundID, struct context_vars*).
comment|/// \param D OpenMP directive.
comment|/// \param ThreadIDVar Variable for thread id in the current OpenMP region.
comment|/// \param InnermostKind Kind of innermost directive (for simple directives it
comment|/// is a directive itself, for combined - its innermost directive).
comment|/// \param CodeGen Code generation sequence for the \a D directive.
name|llvm
operator|::
name|Value
operator|*
name|emitParallelOutlinedFunction
argument_list|(
argument|const OMPExecutableDirective&D
argument_list|,
argument|const VarDecl *ThreadIDVar
argument_list|,
argument|OpenMPDirectiveKind InnermostKind
argument_list|,
argument|const RegionCodeGenTy&CodeGen
argument_list|)
name|override
block|;
comment|/// \brief Emits inlined function for the specified OpenMP teams
comment|//  directive.
comment|/// \a D. This outlined function has type void(*)(kmp_int32 *ThreadID,
comment|/// kmp_int32 BoundID, struct context_vars*).
comment|/// \param D OpenMP directive.
comment|/// \param ThreadIDVar Variable for thread id in the current OpenMP region.
comment|/// \param InnermostKind Kind of innermost directive (for simple directives it
comment|/// is a directive itself, for combined - its innermost directive).
comment|/// \param CodeGen Code generation sequence for the \a D directive.
name|llvm
operator|::
name|Value
operator|*
name|emitTeamsOutlinedFunction
argument_list|(
argument|const OMPExecutableDirective&D
argument_list|,
argument|const VarDecl *ThreadIDVar
argument_list|,
argument|OpenMPDirectiveKind InnermostKind
argument_list|,
argument|const RegionCodeGenTy&CodeGen
argument_list|)
name|override
block|;
comment|/// \brief Emits code for teams call of the \a OutlinedFn with
comment|/// variables captured in a record which address is stored in \a
comment|/// CapturedStruct.
comment|/// \param OutlinedFn Outlined function to be run by team masters. Type of
comment|/// this function is void(*)(kmp_int32 *, kmp_int32, struct context_vars*).
comment|/// \param CapturedVars A pointer to the record with the references to
comment|/// variables used in \a OutlinedFn function.
comment|///
name|void
name|emitTeamsCall
argument_list|(
argument|CodeGenFunction&CGF
argument_list|,
argument|const OMPExecutableDirective&D
argument_list|,
argument|SourceLocation Loc
argument_list|,
argument|llvm::Value *OutlinedFn
argument_list|,
argument|ArrayRef<llvm::Value *> CapturedVars
argument_list|)
name|override
block|;
comment|/// \brief Emits code for parallel or serial call of the \a OutlinedFn with
comment|/// variables captured in a record which address is stored in \a
comment|/// CapturedStruct.
comment|/// \param OutlinedFn Outlined function to be run in parallel threads. Type of
comment|/// this function is void(*)(kmp_int32 *, kmp_int32, struct context_vars*).
comment|/// \param CapturedVars A pointer to the record with the references to
comment|/// variables used in \a OutlinedFn function.
comment|/// \param IfCond Condition in the associated 'if' clause, if it was
comment|/// specified, nullptr otherwise.
name|void
name|emitParallelCall
argument_list|(
argument|CodeGenFunction&CGF
argument_list|,
argument|SourceLocation Loc
argument_list|,
argument|llvm::Value *OutlinedFn
argument_list|,
argument|ArrayRef<llvm::Value *> CapturedVars
argument_list|,
argument|const Expr *IfCond
argument_list|)
name|override
block|;
comment|/// Emit a code for reduction clause.
comment|///
comment|/// \param Privates List of private copies for original reduction arguments.
comment|/// \param LHSExprs List of LHS in \a ReductionOps reduction operations.
comment|/// \param RHSExprs List of RHS in \a ReductionOps reduction operations.
comment|/// \param ReductionOps List of reduction operations in form 'LHS binop RHS'
comment|/// or 'operator binop(LHS, RHS)'.
comment|/// \param Options List of options for reduction codegen:
comment|///     WithNowait true if parent directive has also nowait clause, false
comment|///     otherwise.
comment|///     SimpleReduction Emit reduction operation only. Used for omp simd
comment|///     directive on the host.
comment|///     ReductionKind The kind of reduction to perform.
name|virtual
name|void
name|emitReduction
argument_list|(
argument|CodeGenFunction&CGF
argument_list|,
argument|SourceLocation Loc
argument_list|,
argument|ArrayRef<const Expr *> Privates
argument_list|,
argument|ArrayRef<const Expr *> LHSExprs
argument_list|,
argument|ArrayRef<const Expr *> RHSExprs
argument_list|,
argument|ArrayRef<const Expr *> ReductionOps
argument_list|,
argument|ReductionOptionsTy Options
argument_list|)
name|override
block|;
comment|/// Returns specified OpenMP runtime function for the current OpenMP
comment|/// implementation.  Specialized for the NVPTX device.
comment|/// \param Function OpenMP runtime function.
comment|/// \return Specified function.
name|llvm
operator|::
name|Constant
operator|*
name|createNVPTXRuntimeFunction
argument_list|(
argument|unsigned Function
argument_list|)
block|;
comment|/// Target codegen is specialized based on two programming models: the
comment|/// 'generic' fork-join model of OpenMP, and a more GPU efficient 'spmd'
comment|/// model for constructs like 'target parallel' that support it.
block|enum
name|ExecutionMode
block|{
comment|/// Single Program Multiple Data.
name|Spmd
block|,
comment|/// Generic codegen to support fork-join model.
name|Generic
block|,
name|Unknown
block|,   }
block|;
name|private
operator|:
comment|// Track the execution mode when codegening directives within a target
comment|// region. The appropriate mode (generic/spmd) is set on entry to the
comment|// target region and used by containing directives such as 'parallel'
comment|// to emit optimized code.
name|ExecutionMode
name|CurrentExecutionMode
block|; }
decl_stmt|;
block|}
comment|// CodeGen namespace.
block|}
end_decl_stmt

begin_comment
comment|// clang namespace.
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// LLVM_CLANG_LIB_CODEGEN_CGOPENMPRUNTIMENVPTX_H
end_comment

end_unit

