begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- DeadArgumentElimination.h - Eliminate Dead Args ----------*- C++ -*-===//
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
comment|// This pass deletes dead arguments from internal functions.  Dead argument
end_comment

begin_comment
comment|// elimination removes arguments which are directly dead, as well as arguments
end_comment

begin_comment
comment|// only passed into function calls as dead arguments of other functions.  This
end_comment

begin_comment
comment|// pass also deletes dead return values in a similar way.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// This pass is often useful as a cleanup pass to run after aggressive
end_comment

begin_comment
comment|// interprocedural passes, which add possibly-dead arguments or return values.
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
name|LLVM_TRANSFORMS_IPO_DEADARGUMENTELIMINATION_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_TRANSFORMS_IPO_DEADARGUMENTELIMINATION_H
end_define

begin_include
include|#
directive|include
file|"llvm/IR/Module.h"
end_include

begin_include
include|#
directive|include
file|"llvm/IR/PassManager.h"
end_include

begin_include
include|#
directive|include
file|<map>
end_include

begin_include
include|#
directive|include
file|<set>
end_include

begin_include
include|#
directive|include
file|<string>
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
comment|/// Eliminate dead arguments (and return values) from functions.
name|class
name|DeadArgumentEliminationPass
range|:
name|public
name|PassInfoMixin
operator|<
name|DeadArgumentEliminationPass
operator|>
block|{
name|public
operator|:
comment|/// Struct that represents (part of) either a return value or a function
comment|/// argument.  Used so that arguments and return values can be used
comment|/// interchangeably.
expr|struct
name|RetOrArg
block|{
name|RetOrArg
argument_list|(
argument|const Function *F
argument_list|,
argument|unsigned Idx
argument_list|,
argument|bool IsArg
argument_list|)
operator|:
name|F
argument_list|(
name|F
argument_list|)
block|,
name|Idx
argument_list|(
name|Idx
argument_list|)
block|,
name|IsArg
argument_list|(
argument|IsArg
argument_list|)
block|{}
specifier|const
name|Function
operator|*
name|F
block|;
name|unsigned
name|Idx
block|;
name|bool
name|IsArg
block|;
comment|/// Make RetOrArg comparable, so we can put it into a map.
name|bool
name|operator
operator|<
operator|(
specifier|const
name|RetOrArg
operator|&
name|O
operator|)
specifier|const
block|{
return|return
name|std
operator|::
name|tie
argument_list|(
name|F
argument_list|,
name|Idx
argument_list|,
name|IsArg
argument_list|)
operator|<
name|std
operator|::
name|tie
argument_list|(
name|O
operator|.
name|F
argument_list|,
name|O
operator|.
name|Idx
argument_list|,
name|O
operator|.
name|IsArg
argument_list|)
return|;
block|}
comment|/// Make RetOrArg comparable, so we can easily iterate the multimap.
name|bool
name|operator
operator|==
operator|(
specifier|const
name|RetOrArg
operator|&
name|O
operator|)
specifier|const
block|{
return|return
name|F
operator|==
name|O
operator|.
name|F
operator|&&
name|Idx
operator|==
name|O
operator|.
name|Idx
operator|&&
name|IsArg
operator|==
name|O
operator|.
name|IsArg
return|;
block|}
name|std
operator|::
name|string
name|getDescription
argument_list|()
specifier|const
block|{
return|return
operator|(
name|Twine
argument_list|(
name|IsArg
operator|?
literal|"Argument #"
operator|:
literal|"Return value #"
argument_list|)
operator|+
name|Twine
argument_list|(
name|Idx
argument_list|)
operator|+
literal|" of function "
operator|+
name|F
operator|->
name|getName
argument_list|()
operator|)
operator|.
name|str
argument_list|()
return|;
block|}
expr|}
block|;
comment|/// Liveness enum - During our initial pass over the program, we determine
comment|/// that things are either alive or maybe alive. We don't mark anything
comment|/// explicitly dead (even if we know they are), since anything not alive
comment|/// with no registered uses (in Uses) will never be marked alive and will
comment|/// thus become dead in the end.
block|enum
name|Liveness
block|{
name|Live
block|,
name|MaybeLive
block|}
block|;
comment|/// Convenience wrapper
name|RetOrArg
name|CreateRet
argument_list|(
argument|const Function *F
argument_list|,
argument|unsigned Idx
argument_list|)
block|{
return|return
name|RetOrArg
argument_list|(
name|F
argument_list|,
name|Idx
argument_list|,
name|false
argument_list|)
return|;
block|}
comment|/// Convenience wrapper
name|RetOrArg
name|CreateArg
argument_list|(
argument|const Function *F
argument_list|,
argument|unsigned Idx
argument_list|)
block|{
return|return
name|RetOrArg
argument_list|(
name|F
argument_list|,
name|Idx
argument_list|,
name|true
argument_list|)
return|;
block|}
typedef|typedef
name|std
operator|::
name|multimap
operator|<
name|RetOrArg
operator|,
name|RetOrArg
operator|>
name|UseMap
expr_stmt|;
comment|/// This maps a return value or argument to any MaybeLive return values or
comment|/// arguments it uses. This allows the MaybeLive values to be marked live
comment|/// when any of its users is marked live.
comment|/// For example (indices are left out for clarity):
comment|///  - Uses[ret F] = ret G
comment|///    This means that F calls G, and F returns the value returned by G.
comment|///  - Uses[arg F] = ret G
comment|///    This means that some function calls G and passes its result as an
comment|///    argument to F.
comment|///  - Uses[ret F] = arg F
comment|///    This means that F returns one of its own arguments.
comment|///  - Uses[arg F] = arg G
comment|///    This means that G calls F and passes one of its own (G's) arguments
comment|///    directly to F.
name|UseMap
name|Uses
block|;
typedef|typedef
name|std
operator|::
name|set
operator|<
name|RetOrArg
operator|>
name|LiveSet
expr_stmt|;
typedef|typedef
name|std
operator|::
name|set
operator|<
specifier|const
name|Function
operator|*
operator|>
name|LiveFuncSet
expr_stmt|;
comment|/// This set contains all values that have been determined to be live.
name|LiveSet
name|LiveValues
decl_stmt|;
comment|/// This set contains all values that are cannot be changed in any way.
name|LiveFuncSet
name|LiveFunctions
decl_stmt|;
typedef|typedef
name|SmallVector
operator|<
name|RetOrArg
operator|,
literal|5
operator|>
name|UseVector
expr_stmt|;
comment|/// This allows this pass to do double-duty as the dead arg hacking pass
comment|/// (used only by bugpoint).
name|bool
name|ShouldHackArguments
init|=
name|false
decl_stmt|;
name|public
label|:
name|DeadArgumentEliminationPass
argument_list|(
argument|bool ShouldHackArguments_ = false
argument_list|)
block|:
name|ShouldHackArguments
argument_list|(
argument|ShouldHackArguments_
argument_list|)
block|{}
name|PreservedAnalyses
name|run
parameter_list|(
name|Module
modifier|&
name|M
parameter_list|,
name|ModuleAnalysisManager
modifier|&
parameter_list|)
function_decl|;
name|private
label|:
name|Liveness
name|MarkIfNotLive
parameter_list|(
name|RetOrArg
name|Use
parameter_list|,
name|UseVector
modifier|&
name|MaybeLiveUses
parameter_list|)
function_decl|;
name|Liveness
name|SurveyUse
parameter_list|(
specifier|const
name|Use
modifier|*
name|U
parameter_list|,
name|UseVector
modifier|&
name|MaybeLiveUses
parameter_list|,
name|unsigned
name|RetValNum
init|=
operator|-
literal|1U
parameter_list|)
function_decl|;
name|Liveness
name|SurveyUses
parameter_list|(
specifier|const
name|Value
modifier|*
name|V
parameter_list|,
name|UseVector
modifier|&
name|MaybeLiveUses
parameter_list|)
function_decl|;
name|void
name|SurveyFunction
parameter_list|(
specifier|const
name|Function
modifier|&
name|F
parameter_list|)
function_decl|;
name|void
name|MarkValue
parameter_list|(
specifier|const
name|RetOrArg
modifier|&
name|RA
parameter_list|,
name|Liveness
name|L
parameter_list|,
specifier|const
name|UseVector
modifier|&
name|MaybeLiveUses
parameter_list|)
function_decl|;
name|void
name|MarkLive
parameter_list|(
specifier|const
name|RetOrArg
modifier|&
name|RA
parameter_list|)
function_decl|;
name|void
name|MarkLive
parameter_list|(
specifier|const
name|Function
modifier|&
name|F
parameter_list|)
function_decl|;
name|void
name|PropagateLiveness
parameter_list|(
specifier|const
name|RetOrArg
modifier|&
name|RA
parameter_list|)
function_decl|;
name|bool
name|RemoveDeadStuffFromFunction
parameter_list|(
name|Function
modifier|*
name|F
parameter_list|)
function_decl|;
name|bool
name|DeleteDeadVarargs
parameter_list|(
name|Function
modifier|&
name|Fn
parameter_list|)
function_decl|;
name|bool
name|RemoveDeadArgumentsFromCallers
parameter_list|(
name|Function
modifier|&
name|Fn
parameter_list|)
function_decl|;
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_endif
unit|}
endif|#
directive|endif
end_endif

begin_comment
comment|// LLVM_TRANSFORMS_IPO_DEADARGUMENTELIMINATION_H
end_comment

end_unit

