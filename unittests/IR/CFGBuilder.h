begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- CFGBuilder.h - CFG building and updating utility ----------*- C++ -*-==//
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
comment|/// \file
end_comment

begin_comment
comment|/// CFGBuilders provides utilities fo building and updating CFG for testing
end_comment

begin_comment
comment|/// purposes.
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
name|LLVM_UNITTESTS_CFG_BUILDER_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_UNITTESTS_CFG_BUILDER_H
end_define

begin_include
include|#
directive|include
file|"llvm/ADT/DenseMap.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/Optional.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/StringMap.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/StringRef.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/Debug.h"
end_include

begin_include
include|#
directive|include
file|<memory>
end_include

begin_include
include|#
directive|include
file|<set>
end_include

begin_include
include|#
directive|include
file|<tuple>
end_include

begin_include
include|#
directive|include
file|<vector>
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
name|Function
decl_stmt|;
name|class
name|BasicBlock
decl_stmt|;
name|class
name|raw_ostream
decl_stmt|;
struct|struct
name|CFGHolder
block|{
name|std
operator|::
name|unique_ptr
operator|<
name|LLVMContext
operator|>
name|Context
expr_stmt|;
name|std
operator|::
name|unique_ptr
operator|<
name|Module
operator|>
name|M
expr_stmt|;
name|Function
modifier|*
name|F
decl_stmt|;
name|CFGHolder
argument_list|(
argument|StringRef ModuleName =
literal|"m"
argument_list|,
argument|StringRef FunctionName =
literal|"foo"
argument_list|)
empty_stmt|;
operator|~
name|CFGHolder
argument_list|()
expr_stmt|;
comment|// Defined in the .cpp file so we can use forward declarations.
block|}
struct|;
comment|/// \brief
comment|/// CFGBuilder builds IR with specific CFG, based on the supplied list of arcs.
comment|/// It's able to apply the provided updates and automatically modify the IR.
comment|///
comment|/// Internally it makes every basic block end with either SwitchInst or with
comment|/// UnreachableInst. When all arc to a BB are deleted, the BB remains in the
comment|/// function and doesn't get deleted.
comment|///
name|class
name|CFGBuilder
block|{
name|public
label|:
struct|struct
name|Arc
block|{
name|StringRef
name|From
decl_stmt|;
name|StringRef
name|To
decl_stmt|;
name|friend
name|bool
name|operator
operator|<
operator|(
specifier|const
name|Arc
operator|&
name|LHS
operator|,
specifier|const
name|Arc
operator|&
name|RHS
operator|)
block|{
return|return
name|std
operator|::
name|tie
argument_list|(
name|LHS
operator|.
name|From
argument_list|,
name|LHS
operator|.
name|To
argument_list|)
operator|<
name|std
operator|::
name|tie
argument_list|(
name|RHS
operator|.
name|From
argument_list|,
name|RHS
operator|.
name|To
argument_list|)
return|;
block|}
block|}
struct|;
name|enum
name|class
name|ActionKind
block|{
name|Insert
operator|,
name|Delete
block|}
empty_stmt|;
struct|struct
name|Update
block|{
name|ActionKind
name|Action
decl_stmt|;
name|Arc
name|Edge
decl_stmt|;
block|}
struct|;
name|CFGBuilder
argument_list|(
name|Function
operator|*
name|F
argument_list|,
specifier|const
name|std
operator|::
name|vector
operator|<
name|Arc
operator|>
operator|&
name|InitialArcs
argument_list|,
name|std
operator|::
name|vector
operator|<
name|Update
operator|>
name|Updates
argument_list|)
expr_stmt|;
name|BasicBlock
modifier|*
name|getOrAddBlock
parameter_list|(
name|StringRef
name|BlockName
parameter_list|)
function_decl|;
name|Optional
operator|<
name|Update
operator|>
name|getNextUpdate
argument_list|()
specifier|const
expr_stmt|;
name|Optional
operator|<
name|Update
operator|>
name|applyUpdate
argument_list|()
expr_stmt|;
name|void
name|dump
argument_list|(
name|raw_ostream
operator|&
name|OS
operator|=
name|dbgs
argument_list|()
argument_list|)
decl|const
decl_stmt|;
name|private
label|:
name|void
name|buildCFG
argument_list|(
specifier|const
name|std
operator|::
name|vector
operator|<
name|Arc
operator|>
operator|&
name|Arcs
argument_list|)
decl_stmt|;
name|bool
name|connect
parameter_list|(
specifier|const
name|Arc
modifier|&
name|A
parameter_list|)
function_decl|;
name|bool
name|disconnect
parameter_list|(
specifier|const
name|Arc
modifier|&
name|A
parameter_list|)
function_decl|;
name|Function
modifier|*
name|F
decl_stmt|;
name|unsigned
name|UpdateIdx
init|=
literal|0
decl_stmt|;
name|StringMap
operator|<
name|BasicBlock
operator|*
operator|>
name|NameToBlock
expr_stmt|;
name|std
operator|::
name|set
operator|<
name|Arc
operator|>
name|Arcs
expr_stmt|;
name|std
operator|::
name|vector
operator|<
name|Update
operator|>
name|Updates
expr_stmt|;
block|}
empty_stmt|;
block|}
end_decl_stmt

begin_comment
comment|// namespace llvm
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

