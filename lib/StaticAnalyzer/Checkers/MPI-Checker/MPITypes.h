begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- MPITypes.h - Functionality to model MPI concepts --------*- C++ -*-===//
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
comment|/// This file provides definitions to model concepts of MPI. The mpi::Request
end_comment

begin_comment
comment|/// class defines a wrapper class, in order to make MPI requests trackable for
end_comment

begin_comment
comment|/// path-sensitive analysis.
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
name|LLVM_CLANG_LIB_STATICANALYZER_CHECKERS_MPICHECKER_MPITYPES_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_CLANG_LIB_STATICANALYZER_CHECKERS_MPICHECKER_MPITYPES_H
end_define

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
file|"llvm/ADT/SmallSet.h"
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
name|Request
block|{
name|public
label|:
enum|enum
name|State
enum|:
name|unsigned
name|char
block|{
name|Nonblocking
block|,
name|Wait
block|}
enum|;
name|Request
argument_list|(
argument|State S
argument_list|)
block|:
name|CurrentState
block|{
name|S
block|}
block|{}
name|void
name|Profile
argument_list|(
name|llvm
operator|::
name|FoldingSetNodeID
operator|&
name|Id
argument_list|)
decl|const
block|{
name|Id
operator|.
name|AddInteger
argument_list|(
name|CurrentState
argument_list|)
expr_stmt|;
block|}
name|bool
name|operator
operator|==
operator|(
specifier|const
name|Request
operator|&
name|ToCompare
operator|)
specifier|const
block|{
return|return
name|CurrentState
operator|==
name|ToCompare
operator|.
name|CurrentState
return|;
block|}
specifier|const
name|State
name|CurrentState
decl_stmt|;
block|}
empty_stmt|;
comment|// The RequestMap stores MPI requests which are identified by their memory
comment|// region. Requests are used in MPI to complete nonblocking operations with wait
comment|// operations. A custom map implementation is used, in order to make it
comment|// available in an arbitrary amount of translation units.
struct|struct
name|RequestMap
block|{}
struct|;
typedef|typedef
name|llvm
operator|::
name|ImmutableMap
operator|<
specifier|const
name|clang
operator|::
name|ento
operator|::
name|MemRegion
operator|*
operator|,
name|clang
operator|::
name|ento
operator|::
name|mpi
operator|::
name|Request
operator|>
name|RequestMapImpl
expr_stmt|;
block|}
comment|// end of namespace: mpi
name|template
operator|<
operator|>
expr|struct
name|ProgramStateTrait
operator|<
name|mpi
operator|::
name|RequestMap
operator|>
operator|:
name|public
name|ProgramStatePartialTrait
operator|<
name|mpi
operator|::
name|RequestMapImpl
operator|>
block|{
specifier|static
name|void
operator|*
name|GDMIndex
argument_list|()
block|{
specifier|static
name|int
name|index
operator|=
literal|0
block|;
return|return
operator|&
name|index
return|;
block|}
expr|}
block|;  }
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

