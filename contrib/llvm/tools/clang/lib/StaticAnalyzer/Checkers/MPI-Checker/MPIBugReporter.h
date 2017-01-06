begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- MPIBugReporter.h - bug reporter -----------------------*- C++ -*-===//
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
comment|/// This file defines prefabricated reports which are emitted in
end_comment

begin_comment
comment|/// case of MPI related bugs, detected by path-sensitive analysis.
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
name|LLVM_CLANG_LIB_STATICANALYZER_CHECKERS_MPICHECKER_MPIBUGREPORTER_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_CLANG_LIB_STATICANALYZER_CHECKERS_MPICHECKER_MPIBUGREPORTER_H
end_define

begin_include
include|#
directive|include
file|"MPITypes.h"
end_include

begin_include
include|#
directive|include
file|"clang/StaticAnalyzer/Core/BugReporter/BugType.h"
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
name|MPIBugReporter
block|{
name|public
label|:
name|MPIBugReporter
argument_list|(
argument|const CheckerBase&CB
argument_list|)
block|{
name|UnmatchedWaitBugType
operator|.
name|reset
argument_list|(
argument|new BugType(&CB,
literal|"Unmatched wait"
argument|, MPIError)
argument_list|)
expr_stmt|;
name|DoubleNonblockingBugType
operator|.
name|reset
argument_list|(
argument|new BugType(&CB,
literal|"Double nonblocking"
argument|, MPIError)
argument_list|)
expr_stmt|;
name|MissingWaitBugType
operator|.
name|reset
argument_list|(
argument|new BugType(&CB,
literal|"Missing wait"
argument|, MPIError)
argument_list|)
expr_stmt|;
block|}
comment|/// Report duplicate request use by nonblocking calls without intermediate
comment|/// wait.
comment|///
comment|/// \param MPICallEvent MPI call that caused the double nonblocking
comment|/// \param Req request that was used by two nonblocking calls in sequence
comment|/// \param RequestRegion memory region of the request
comment|/// \param ExplNode node in the graph the bug appeared at
comment|/// \param BReporter bug reporter for current context
name|void
name|reportDoubleNonblocking
argument_list|(
specifier|const
name|CallEvent
operator|&
name|MPICallEvent
argument_list|,
specifier|const
name|Request
operator|&
name|Req
argument_list|,
specifier|const
name|MemRegion
operator|*
specifier|const
name|RequestRegion
argument_list|,
specifier|const
name|ExplodedNode
operator|*
specifier|const
name|ExplNode
argument_list|,
name|BugReporter
operator|&
name|BReporter
argument_list|)
decl|const
decl_stmt|;
comment|/// Report a missing wait for a nonblocking call.
comment|///
comment|/// \param Req request that is not matched by a wait
comment|/// \param RequestRegion memory region of the request
comment|/// \param ExplNode node in the graph the bug appeared at
comment|/// \param BReporter bug reporter for current context
name|void
name|reportMissingWait
argument_list|(
specifier|const
name|Request
operator|&
name|Req
argument_list|,
specifier|const
name|MemRegion
operator|*
specifier|const
name|RequestRegion
argument_list|,
specifier|const
name|ExplodedNode
operator|*
specifier|const
name|ExplNode
argument_list|,
name|BugReporter
operator|&
name|BReporter
argument_list|)
decl|const
decl_stmt|;
comment|/// Report a wait on a request that has not been used at all before.
comment|///
comment|/// \param CE wait call that uses the request
comment|/// \param RequestRegion memory region of the request
comment|/// \param ExplNode node in the graph the bug appeared at
comment|/// \param BReporter bug reporter for current context
name|void
name|reportUnmatchedWait
argument_list|(
specifier|const
name|CallEvent
operator|&
name|CE
argument_list|,
specifier|const
name|MemRegion
operator|*
specifier|const
name|RequestRegion
argument_list|,
specifier|const
name|ExplodedNode
operator|*
specifier|const
name|ExplNode
argument_list|,
name|BugReporter
operator|&
name|BReporter
argument_list|)
decl|const
decl_stmt|;
name|private
label|:
specifier|const
name|std
operator|::
name|string
name|MPIError
operator|=
literal|"MPI Error"
expr_stmt|;
comment|// path-sensitive bug types
name|std
operator|::
name|unique_ptr
operator|<
name|BugType
operator|>
name|UnmatchedWaitBugType
expr_stmt|;
name|std
operator|::
name|unique_ptr
operator|<
name|BugType
operator|>
name|MissingWaitBugType
expr_stmt|;
name|std
operator|::
name|unique_ptr
operator|<
name|BugType
operator|>
name|DoubleNonblockingBugType
expr_stmt|;
comment|/// Bug visitor class to find the node where the request region was previously
comment|/// used in order to include it into the BugReport path.
name|class
name|RequestNodeVisitor
range|:
name|public
name|BugReporterVisitorImpl
operator|<
name|RequestNodeVisitor
operator|>
block|{
name|public
operator|:
name|RequestNodeVisitor
argument_list|(
specifier|const
name|MemRegion
operator|*
specifier|const
name|MemoryRegion
argument_list|,
specifier|const
name|std
operator|::
name|string
operator|&
name|ErrText
argument_list|)
operator|:
name|RequestRegion
argument_list|(
name|MemoryRegion
argument_list|)
block|,
name|ErrorText
argument_list|(
argument|ErrText
argument_list|)
block|{}
name|void
name|Profile
argument_list|(
argument|llvm::FoldingSetNodeID&ID
argument_list|)
specifier|const
name|override
block|{
specifier|static
name|int
name|X
operator|=
literal|0
block|;
name|ID
operator|.
name|AddPointer
argument_list|(
operator|&
name|X
argument_list|)
block|;
name|ID
operator|.
name|AddPointer
argument_list|(
name|RequestRegion
argument_list|)
block|;     }
name|std
operator|::
name|shared_ptr
operator|<
name|PathDiagnosticPiece
operator|>
name|VisitNode
argument_list|(
argument|const ExplodedNode *N
argument_list|,
argument|const ExplodedNode *PrevN
argument_list|,
argument|BugReporterContext&BRC
argument_list|,
argument|BugReport&BR
argument_list|)
name|override
block|;
name|private
operator|:
specifier|const
name|MemRegion
operator|*
specifier|const
name|RequestRegion
block|;
name|bool
name|IsNodeFound
operator|=
name|false
block|;
name|std
operator|::
name|string
name|ErrorText
block|;   }
decl_stmt|;
block|}
empty_stmt|;
block|}
comment|// end of namespace: mpi
block|}
comment|// end of namespace: ento
block|}
end_decl_stmt

begin_comment
comment|// end of namespace: clang
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

