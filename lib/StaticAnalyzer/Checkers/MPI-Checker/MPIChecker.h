begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- MPIChecker.h - Verify MPI API usage- --------------------*- C++ -*-===//
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
comment|///
end_comment

begin_comment
comment|/// \file
end_comment

begin_comment
comment|/// This file defines the main class of MPI-Checker which serves as an entry
end_comment

begin_comment
comment|/// point. It is created once for each translation unit analysed.
end_comment

begin_comment
comment|/// The checker defines path-sensitive checks, to verify correct usage of the
end_comment

begin_comment
comment|/// MPI API.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|//===----------------------------------------------------------------------===//
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|LLVM_CLANG_LIB_STATICANALYZER_CHECKERS_MPICHECKER_MPICHECKER_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_CLANG_LIB_STATICANALYZER_CHECKERS_MPICHECKER_MPICHECKER_H
end_define

begin_include
include|#
directive|include
file|"MPIBugReporter.h"
end_include

begin_include
include|#
directive|include
file|"MPITypes.h"
end_include

begin_include
include|#
directive|include
file|"clang/StaticAnalyzer/Checkers/MPIFunctionClassifier.h"
end_include

begin_include
include|#
directive|include
file|"clang/StaticAnalyzer/Core/PathSensitive/CallEvent.h"
end_include

begin_include
include|#
directive|include
file|"clang/StaticAnalyzer/Core/PathSensitive/CheckerContext.h"
end_include

begin_decl_stmt
name|namespace
name|clang
block|{
name|namespace
name|ento
block|{
name|namespace
name|mpi
block|{
name|class
name|MPIChecker
range|:
name|public
name|Checker
operator|<
name|check
operator|::
name|PreCall
decl_stmt|,
name|check
decl|::
name|DeadSymbols
decl|>
block|{
name|public
label|:
name|MPIChecker
argument_list|()
operator|:
name|BReporter
argument_list|(
argument|*this
argument_list|)
block|{}
comment|// path-sensitive callbacks
name|void
name|checkPreCall
argument_list|(
argument|const CallEvent&CE
argument_list|,
argument|CheckerContext&Ctx
argument_list|)
specifier|const
block|{
name|dynamicInit
argument_list|(
name|Ctx
argument_list|)
block|;
name|checkUnmatchedWaits
argument_list|(
name|CE
argument_list|,
name|Ctx
argument_list|)
block|;
name|checkDoubleNonblocking
argument_list|(
name|CE
argument_list|,
name|Ctx
argument_list|)
block|;   }
name|void
name|checkDeadSymbols
argument_list|(
argument|SymbolReaper&SymReaper
argument_list|,
argument|CheckerContext&Ctx
argument_list|)
specifier|const
block|{
name|dynamicInit
argument_list|(
name|Ctx
argument_list|)
block|;
name|checkMissingWaits
argument_list|(
name|SymReaper
argument_list|,
name|Ctx
argument_list|)
block|;   }
name|void
name|dynamicInit
argument_list|(
argument|CheckerContext&Ctx
argument_list|)
specifier|const
block|{
if|if
condition|(
name|FuncClassifier
condition|)
return|return;
name|const_cast
operator|<
name|std
operator|::
name|unique_ptr
operator|<
name|MPIFunctionClassifier
operator|>
operator|&
operator|>
operator|(
name|FuncClassifier
operator|)
operator|.
name|reset
operator|(
name|new
name|MPIFunctionClassifier
block|{
name|Ctx
operator|.
name|getASTContext
argument_list|()
block|}
operator|)
expr_stmt|;
block|}
comment|/// Checks if a request is used by nonblocking calls multiple times
comment|/// in sequence without intermediate wait. The check contains a guard,
comment|/// in order to only inspect nonblocking functions.
comment|///
comment|/// \param PreCallEvent MPI call to verify
name|void
name|checkDoubleNonblocking
argument_list|(
specifier|const
name|clang
operator|::
name|ento
operator|::
name|CallEvent
operator|&
name|PreCallEvent
argument_list|,
name|clang
operator|::
name|ento
operator|::
name|CheckerContext
operator|&
name|Ctx
argument_list|)
decl|const
decl_stmt|;
comment|/// Checks if the request used by the wait function was not used at all
comment|/// before. The check contains a guard, in order to only inspect wait
comment|/// functions.
comment|///
comment|/// \param PreCallEvent MPI call to verify
name|void
name|checkUnmatchedWaits
argument_list|(
specifier|const
name|clang
operator|::
name|ento
operator|::
name|CallEvent
operator|&
name|PreCallEvent
argument_list|,
name|clang
operator|::
name|ento
operator|::
name|CheckerContext
operator|&
name|Ctx
argument_list|)
decl|const
decl_stmt|;
comment|/// Check if a nonblocking call is not matched by a wait.
comment|/// If a memory region is not alive and the last function using the
comment|/// request was a nonblocking call, this is rated as a missing wait.
name|void
name|checkMissingWaits
argument_list|(
name|clang
operator|::
name|ento
operator|::
name|SymbolReaper
operator|&
name|SymReaper
argument_list|,
name|clang
operator|::
name|ento
operator|::
name|CheckerContext
operator|&
name|Ctx
argument_list|)
decl|const
decl_stmt|;
name|private
label|:
comment|/// Collects all memory regions of a request(array) used by a wait
comment|/// function. If the wait function uses a single request, this is a single
comment|/// region. For wait functions using multiple requests, multiple regions
comment|/// representing elements in the array are collected.
comment|///
comment|/// \param ReqRegions vector the regions get pushed into
comment|/// \param MR top most region to iterate
comment|/// \param CE MPI wait call using the request(s)
name|void
name|allRegionsUsedByWait
argument_list|(
name|llvm
operator|::
name|SmallVector
operator|<
specifier|const
name|clang
operator|::
name|ento
operator|::
name|MemRegion
operator|*
argument_list|,
literal|2
operator|>
operator|&
name|ReqRegions
argument_list|,
specifier|const
name|clang
operator|::
name|ento
operator|::
name|MemRegion
operator|*
specifier|const
name|MR
argument_list|,
specifier|const
name|clang
operator|::
name|ento
operator|::
name|CallEvent
operator|&
name|CE
argument_list|,
name|clang
operator|::
name|ento
operator|::
name|CheckerContext
operator|&
name|Ctx
argument_list|)
decl|const
decl_stmt|;
comment|/// Returns the memory region used by a wait function.
comment|/// Distinguishes between MPI_Wait and MPI_Waitall.
comment|///
comment|/// \param CE MPI wait call
specifier|const
name|clang
operator|::
name|ento
operator|::
name|MemRegion
operator|*
name|topRegionUsedByWait
argument_list|(
argument|const clang::ento::CallEvent&CE
argument_list|)
specifier|const
expr_stmt|;
specifier|const
name|std
operator|::
name|unique_ptr
operator|<
name|MPIFunctionClassifier
operator|>
name|FuncClassifier
expr_stmt|;
name|MPIBugReporter
name|BReporter
decl_stmt|;
block|}
empty_stmt|;
block|}
comment|// end of namespace: mpi
block|}
end_decl_stmt

begin_comment
comment|// end of namespace: ento
end_comment

begin_comment
unit|}
comment|// end of namespace: clang
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

