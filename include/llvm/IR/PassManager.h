begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- PassManager.h - Pass management infrastructure -----------*- C++ -*-===//
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
comment|///
end_comment

begin_comment
comment|/// This header defines various interfaces for pass management in LLVM. There
end_comment

begin_comment
comment|/// is no "pass" interface in LLVM per se. Instead, an instance of any class
end_comment

begin_comment
comment|/// which supports a method to 'run' it over a unit of IR can be used as
end_comment

begin_comment
comment|/// a pass. A pass manager is generally a tool to collect a sequence of passes
end_comment

begin_comment
comment|/// which run over a particular IR construct, and run each of them in sequence
end_comment

begin_comment
comment|/// over each such construct in the containing IR construct. As there is no
end_comment

begin_comment
comment|/// containing IR construct for a Module, a manager for passes over modules
end_comment

begin_comment
comment|/// forms the base case which runs its managed passes in sequence over the
end_comment

begin_comment
comment|/// single module provided.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// The core IR library provides managers for running passes over
end_comment

begin_comment
comment|/// modules and functions.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// * FunctionPassManager can run over a Module, runs each pass over
end_comment

begin_comment
comment|///   a Function.
end_comment

begin_comment
comment|/// * ModulePassManager must be directly run, runs each pass over the Module.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// Note that the implementations of the pass managers use concept-based
end_comment

begin_comment
comment|/// polymorphism as outlined in the "Value Semantics and Concept-based
end_comment

begin_comment
comment|/// Polymorphism" talk (or its abbreviated sibling "Inheritance Is The Base
end_comment

begin_comment
comment|/// Class of Evil") by Sean Parent:
end_comment

begin_comment
comment|/// * http://github.com/sean-parent/sean-parent.github.com/wiki/Papers-and-Presentations
end_comment

begin_comment
comment|/// * http://www.youtube.com/watch?v=_BpMYeUFXv8
end_comment

begin_comment
comment|/// * http://channel9.msdn.com/Events/GoingNative/2013/Inheritance-Is-The-Base-Class-of-Evil
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
name|LLVM_IR_PASS_MANAGER_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_IR_PASS_MANAGER_H
end_define

begin_include
include|#
directive|include
file|"llvm/ADT/DenseMap.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/STLExtras.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/SmallPtrSet.h"
end_include

begin_include
include|#
directive|include
file|"llvm/IR/Function.h"
end_include

begin_include
include|#
directive|include
file|"llvm/IR/Module.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/type_traits.h"
end_include

begin_include
include|#
directive|include
file|<list>
end_include

begin_include
include|#
directive|include
file|<memory>
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
name|Module
decl_stmt|;
name|class
name|Function
decl_stmt|;
comment|/// \brief An abstract set of preserved analyses following a transformation pass
comment|/// run.
comment|///
comment|/// When a transformation pass is run, it can return a set of analyses whose
comment|/// results were preserved by that transformation. The default set is "none",
comment|/// and preserving analyses must be done explicitly.
comment|///
comment|/// There is also an explicit all state which can be used (for example) when
comment|/// the IR is not mutated at all.
name|class
name|PreservedAnalyses
block|{
name|public
label|:
comment|// We have to explicitly define all the special member functions because MSVC
comment|// refuses to generate them.
name|PreservedAnalyses
argument_list|()
block|{}
name|PreservedAnalyses
argument_list|(
specifier|const
name|PreservedAnalyses
operator|&
name|Arg
argument_list|)
operator|:
name|PreservedPassIDs
argument_list|(
argument|Arg.PreservedPassIDs
argument_list|)
block|{}
name|PreservedAnalyses
argument_list|(
name|PreservedAnalyses
operator|&&
name|Arg
argument_list|)
operator|:
name|PreservedPassIDs
argument_list|(
argument|std::move(Arg.PreservedPassIDs)
argument_list|)
block|{}
name|friend
name|void
name|swap
argument_list|(
argument|PreservedAnalyses&LHS
argument_list|,
argument|PreservedAnalyses&RHS
argument_list|)
block|{
name|using
name|std
operator|::
name|swap
block|;
name|swap
argument_list|(
name|LHS
operator|.
name|PreservedPassIDs
argument_list|,
name|RHS
operator|.
name|PreservedPassIDs
argument_list|)
block|;   }
name|PreservedAnalyses
operator|&
name|operator
operator|=
operator|(
name|PreservedAnalyses
name|RHS
operator|)
block|{
name|swap
argument_list|(
operator|*
name|this
argument_list|,
name|RHS
argument_list|)
block|;
return|return
operator|*
name|this
return|;
block|}
comment|/// \brief Convenience factory function for the empty preserved set.
specifier|static
name|PreservedAnalyses
name|none
parameter_list|()
block|{
return|return
name|PreservedAnalyses
argument_list|()
return|;
block|}
comment|/// \brief Construct a special preserved set that preserves all passes.
specifier|static
name|PreservedAnalyses
name|all
parameter_list|()
block|{
name|PreservedAnalyses
name|PA
decl_stmt|;
name|PA
operator|.
name|PreservedPassIDs
operator|.
name|insert
argument_list|(
operator|(
name|void
operator|*
operator|)
name|AllPassesID
argument_list|)
expr_stmt|;
return|return
name|PA
return|;
block|}
comment|/// \brief Mark a particular pass as preserved, adding it to the set.
name|template
operator|<
name|typename
name|PassT
operator|>
name|void
name|preserve
argument_list|()
block|{
if|if
condition|(
operator|!
name|areAllPreserved
argument_list|()
condition|)
name|PreservedPassIDs
operator|.
name|insert
argument_list|(
name|PassT
operator|::
name|ID
argument_list|()
argument_list|)
expr_stmt|;
block|}
comment|/// \brief Intersect this set with another in place.
comment|///
comment|/// This is a mutating operation on this preserved set, removing all
comment|/// preserved passes which are not also preserved in the argument.
name|void
name|intersect
parameter_list|(
specifier|const
name|PreservedAnalyses
modifier|&
name|Arg
parameter_list|)
block|{
if|if
condition|(
name|Arg
operator|.
name|areAllPreserved
argument_list|()
condition|)
return|return;
if|if
condition|(
name|areAllPreserved
argument_list|()
condition|)
block|{
name|PreservedPassIDs
operator|=
name|Arg
operator|.
name|PreservedPassIDs
expr_stmt|;
return|return;
block|}
for|for
control|(
name|SmallPtrSet
operator|<
name|void
operator|*
operator|,
literal|2
operator|>
operator|::
name|const_iterator
name|I
operator|=
name|PreservedPassIDs
operator|.
name|begin
argument_list|()
operator|,
name|E
operator|=
name|PreservedPassIDs
operator|.
name|end
argument_list|()
init|;
name|I
operator|!=
name|E
condition|;
operator|++
name|I
control|)
if|if
condition|(
operator|!
name|Arg
operator|.
name|PreservedPassIDs
operator|.
name|count
argument_list|(
operator|*
name|I
argument_list|)
condition|)
name|PreservedPassIDs
operator|.
name|erase
argument_list|(
operator|*
name|I
argument_list|)
expr_stmt|;
block|}
comment|/// \brief Intersect this set with a temporary other set in place.
comment|///
comment|/// This is a mutating operation on this preserved set, removing all
comment|/// preserved passes which are not also preserved in the argument.
name|void
name|intersect
argument_list|(
name|PreservedAnalyses
operator|&&
name|Arg
argument_list|)
block|{
if|if
condition|(
name|Arg
operator|.
name|areAllPreserved
argument_list|()
condition|)
return|return;
if|if
condition|(
name|areAllPreserved
argument_list|()
condition|)
block|{
name|PreservedPassIDs
operator|=
name|std
operator|::
name|move
argument_list|(
name|Arg
operator|.
name|PreservedPassIDs
argument_list|)
expr_stmt|;
return|return;
block|}
for|for
control|(
name|SmallPtrSet
operator|<
name|void
operator|*
operator|,
literal|2
operator|>
operator|::
name|const_iterator
name|I
operator|=
name|PreservedPassIDs
operator|.
name|begin
argument_list|()
operator|,
name|E
operator|=
name|PreservedPassIDs
operator|.
name|end
argument_list|()
init|;
name|I
operator|!=
name|E
condition|;
operator|++
name|I
control|)
if|if
condition|(
operator|!
name|Arg
operator|.
name|PreservedPassIDs
operator|.
name|count
argument_list|(
operator|*
name|I
argument_list|)
condition|)
name|PreservedPassIDs
operator|.
name|erase
argument_list|(
operator|*
name|I
argument_list|)
expr_stmt|;
block|}
comment|/// \brief Query whether a pass is marked as preserved by this set.
name|template
operator|<
name|typename
name|PassT
operator|>
name|bool
name|preserved
argument_list|()
specifier|const
block|{
return|return
name|preserved
argument_list|(
name|PassT
operator|::
name|ID
argument_list|()
argument_list|)
return|;
block|}
comment|/// \brief Query whether an abstract pass ID is marked as preserved by this
comment|/// set.
name|bool
name|preserved
argument_list|(
name|void
operator|*
name|PassID
argument_list|)
decl|const
block|{
return|return
name|PreservedPassIDs
operator|.
name|count
argument_list|(
operator|(
name|void
operator|*
operator|)
name|AllPassesID
argument_list|)
operator|||
name|PreservedPassIDs
operator|.
name|count
argument_list|(
name|PassID
argument_list|)
return|;
block|}
name|private
label|:
comment|// Note that this must not be -1 or -2 as those are already used by the
comment|// SmallPtrSet.
specifier|static
specifier|const
name|uintptr_t
name|AllPassesID
init|=
call|(
name|intptr_t
call|)
argument_list|(
operator|-
literal|3
argument_list|)
decl_stmt|;
name|bool
name|areAllPreserved
argument_list|()
specifier|const
block|{
return|return
name|PreservedPassIDs
operator|.
name|count
argument_list|(
operator|(
name|void
operator|*
operator|)
name|AllPassesID
argument_list|)
return|;
block|}
name|SmallPtrSet
operator|<
name|void
operator|*
operator|,
literal|2
operator|>
name|PreservedPassIDs
expr_stmt|;
block|}
empty_stmt|;
comment|/// \brief Implementation details of the pass manager interfaces.
name|namespace
name|detail
block|{
comment|/// \brief Template for the abstract base class used to dispatch
comment|/// polymorphically over pass objects.
name|template
operator|<
name|typename
name|IRUnitT
operator|,
name|typename
name|AnalysisManagerT
operator|>
expr|struct
name|PassConcept
block|{
comment|// Boiler plate necessary for the container of derived classes.
name|virtual
operator|~
name|PassConcept
argument_list|()
block|{}
comment|/// \brief The polymorphic API which runs the pass over a given IR entity.
comment|///
comment|/// Note that actual pass object can omit the analysis manager argument if
comment|/// desired. Also that the analysis manager may be null if there is no
comment|/// analysis manager in the pass pipeline.
name|virtual
name|PreservedAnalyses
name|run
argument_list|(
argument|IRUnitT IR
argument_list|,
argument|AnalysisManagerT *AM
argument_list|)
operator|=
literal|0
block|;
comment|/// \brief Polymorphic method to access the name of a pass.
name|virtual
name|StringRef
name|name
argument_list|()
operator|=
literal|0
block|; }
expr_stmt|;
comment|/// \brief SFINAE metafunction for computing whether \c PassT has a run method
comment|/// accepting an \c AnalysisManagerT.
name|template
operator|<
name|typename
name|IRUnitT
operator|,
name|typename
name|AnalysisManagerT
operator|,
name|typename
name|PassT
operator|,
name|typename
name|ResultT
operator|>
name|class
name|PassRunAcceptsAnalysisManager
block|{
typedef|typedef
name|char
name|SmallType
typedef|;
block|struct
name|BigType
block|{
name|char
name|a
block|,
name|b
block|;   }
expr_stmt|;
name|template
operator|<
name|typename
name|T
operator|,
name|ResultT
argument_list|(
name|T
operator|::
operator|*
argument_list|)
argument_list|(
name|IRUnitT
argument_list|,
name|AnalysisManagerT
operator|*
argument_list|)
operator|>
expr|struct
name|Checker
expr_stmt|;
name|template
operator|<
name|typename
name|T
operator|>
specifier|static
name|SmallType
name|f
argument_list|(
name|Checker
operator|<
name|T
argument_list|,
operator|&
name|T
operator|::
name|run
operator|>
operator|*
argument_list|)
expr_stmt|;
name|template
operator|<
name|typename
name|T
operator|>
specifier|static
name|BigType
name|f
argument_list|(
operator|...
argument_list|)
expr_stmt|;
name|public
label|:
enum|enum
block|{
name|Value
init|=
sizeof|sizeof
argument_list|(
name|f
operator|<
name|PassT
operator|>
operator|(
name|nullptr
operator|)
argument_list|)
operator|==
expr|sizeof
operator|(
name|SmallType
operator|)
block|}
enum|;
block|}
empty_stmt|;
comment|/// \brief A template wrapper used to implement the polymorphic API.
comment|///
comment|/// Can be instantiated for any object which provides a \c run method accepting
comment|/// an \c IRUnitT. It requires the pass to be a copyable object. When the
comment|/// \c run method also accepts an \c AnalysisManagerT*, we pass it along.
name|template
operator|<
name|typename
name|IRUnitT
operator|,
name|typename
name|AnalysisManagerT
operator|,
name|typename
name|PassT
operator|,
name|bool
name|AcceptsAnalysisManager
operator|=
name|PassRunAcceptsAnalysisManager
operator|<
name|IRUnitT
operator|,
name|AnalysisManagerT
operator|,
name|PassT
operator|,
name|PreservedAnalyses
operator|>
operator|::
name|Value
operator|>
expr|struct
name|PassModel
expr_stmt|;
comment|/// \brief Specialization of \c PassModel for passes that accept an analyis
comment|/// manager.
name|template
operator|<
name|typename
name|IRUnitT
operator|,
name|typename
name|AnalysisManagerT
operator|,
name|typename
name|PassT
operator|>
expr|struct
name|PassModel
operator|<
name|IRUnitT
operator|,
name|AnalysisManagerT
operator|,
name|PassT
operator|,
name|true
operator|>
operator|:
name|PassConcept
operator|<
name|IRUnitT
operator|,
name|AnalysisManagerT
operator|>
block|{
name|explicit
name|PassModel
argument_list|(
argument|PassT Pass
argument_list|)
operator|:
name|Pass
argument_list|(
argument|std::move(Pass)
argument_list|)
block|{}
comment|// We have to explicitly define all the special member functions because MSVC
comment|// refuses to generate them.
name|PassModel
argument_list|(
specifier|const
name|PassModel
operator|&
name|Arg
argument_list|)
operator|:
name|Pass
argument_list|(
argument|Arg.Pass
argument_list|)
block|{}
name|PassModel
argument_list|(
name|PassModel
operator|&&
name|Arg
argument_list|)
operator|:
name|Pass
argument_list|(
argument|std::move(Arg.Pass)
argument_list|)
block|{}
name|friend
name|void
name|swap
argument_list|(
argument|PassModel&LHS
argument_list|,
argument|PassModel&RHS
argument_list|)
block|{
name|using
name|std
operator|::
name|swap
block|;
name|swap
argument_list|(
name|LHS
operator|.
name|Pass
argument_list|,
name|RHS
operator|.
name|Pass
argument_list|)
block|;   }
name|PassModel
operator|&
name|operator
operator|=
operator|(
name|PassModel
name|RHS
operator|)
block|{
name|swap
argument_list|(
operator|*
name|this
argument_list|,
name|RHS
argument_list|)
block|;
return|return
operator|*
name|this
return|;
block|}
name|PreservedAnalyses
name|run
argument_list|(
argument|IRUnitT IR
argument_list|,
argument|AnalysisManagerT *AM
argument_list|)
name|override
block|{
return|return
name|Pass
operator|.
name|run
argument_list|(
name|IR
argument_list|,
name|AM
argument_list|)
return|;
block|}
name|StringRef
name|name
argument_list|()
name|override
block|{
return|return
name|PassT
operator|::
name|name
argument_list|()
return|;
block|}
name|PassT
name|Pass
block|; }
expr_stmt|;
comment|/// \brief Specialization of \c PassModel for passes that accept an analyis
comment|/// manager.
name|template
operator|<
name|typename
name|IRUnitT
operator|,
name|typename
name|AnalysisManagerT
operator|,
name|typename
name|PassT
operator|>
expr|struct
name|PassModel
operator|<
name|IRUnitT
operator|,
name|AnalysisManagerT
operator|,
name|PassT
operator|,
name|false
operator|>
operator|:
name|PassConcept
operator|<
name|IRUnitT
operator|,
name|AnalysisManagerT
operator|>
block|{
name|explicit
name|PassModel
argument_list|(
argument|PassT Pass
argument_list|)
operator|:
name|Pass
argument_list|(
argument|std::move(Pass)
argument_list|)
block|{}
comment|// We have to explicitly define all the special member functions because MSVC
comment|// refuses to generate them.
name|PassModel
argument_list|(
specifier|const
name|PassModel
operator|&
name|Arg
argument_list|)
operator|:
name|Pass
argument_list|(
argument|Arg.Pass
argument_list|)
block|{}
name|PassModel
argument_list|(
name|PassModel
operator|&&
name|Arg
argument_list|)
operator|:
name|Pass
argument_list|(
argument|std::move(Arg.Pass)
argument_list|)
block|{}
name|friend
name|void
name|swap
argument_list|(
argument|PassModel&LHS
argument_list|,
argument|PassModel&RHS
argument_list|)
block|{
name|using
name|std
operator|::
name|swap
block|;
name|swap
argument_list|(
name|LHS
operator|.
name|Pass
argument_list|,
name|RHS
operator|.
name|Pass
argument_list|)
block|;   }
name|PassModel
operator|&
name|operator
operator|=
operator|(
name|PassModel
name|RHS
operator|)
block|{
name|swap
argument_list|(
operator|*
name|this
argument_list|,
name|RHS
argument_list|)
block|;
return|return
operator|*
name|this
return|;
block|}
name|PreservedAnalyses
name|run
argument_list|(
argument|IRUnitT IR
argument_list|,
argument|AnalysisManagerT *AM
argument_list|)
name|override
block|{
return|return
name|Pass
operator|.
name|run
argument_list|(
name|IR
argument_list|)
return|;
block|}
name|StringRef
name|name
argument_list|()
name|override
block|{
return|return
name|PassT
operator|::
name|name
argument_list|()
return|;
block|}
name|PassT
name|Pass
block|; }
expr_stmt|;
comment|/// \brief Abstract concept of an analysis result.
comment|///
comment|/// This concept is parameterized over the IR unit that this result pertains
comment|/// to.
name|template
operator|<
name|typename
name|IRUnitT
operator|>
expr|struct
name|AnalysisResultConcept
block|{
name|virtual
operator|~
name|AnalysisResultConcept
argument_list|()
block|{}
comment|/// \brief Method to try and mark a result as invalid.
comment|///
comment|/// When the outer analysis manager detects a change in some underlying
comment|/// unit of the IR, it will call this method on all of the results cached.
comment|///
comment|/// This method also receives a set of preserved analyses which can be used
comment|/// to avoid invalidation because the pass which changed the underlying IR
comment|/// took care to update or preserve the analysis result in some way.
comment|///
comment|/// \returns true if the result is indeed invalid (the default).
name|virtual
name|bool
name|invalidate
argument_list|(
argument|IRUnitT IR
argument_list|,
argument|const PreservedAnalyses&PA
argument_list|)
operator|=
literal|0
block|; }
expr_stmt|;
comment|/// \brief SFINAE metafunction for computing whether \c ResultT provides an
comment|/// \c invalidate member function.
name|template
operator|<
name|typename
name|IRUnitT
operator|,
name|typename
name|ResultT
operator|>
name|class
name|ResultHasInvalidateMethod
block|{
typedef|typedef
name|char
name|SmallType
typedef|;
block|struct
name|BigType
block|{
name|char
name|a
block|,
name|b
block|;   }
expr_stmt|;
name|template
operator|<
name|typename
name|T
operator|,
name|bool
argument_list|(
name|T
operator|::
operator|*
argument_list|)
argument_list|(
name|IRUnitT
argument_list|,
specifier|const
name|PreservedAnalyses
operator|&
argument_list|)
operator|>
expr|struct
name|Checker
expr_stmt|;
name|template
operator|<
name|typename
name|T
operator|>
specifier|static
name|SmallType
name|f
argument_list|(
name|Checker
operator|<
name|T
argument_list|,
operator|&
name|T
operator|::
name|invalidate
operator|>
operator|*
argument_list|)
expr_stmt|;
name|template
operator|<
name|typename
name|T
operator|>
specifier|static
name|BigType
name|f
argument_list|(
operator|...
argument_list|)
expr_stmt|;
name|public
label|:
enum|enum
block|{
name|Value
init|=
sizeof|sizeof
argument_list|(
name|f
operator|<
name|ResultT
operator|>
operator|(
name|nullptr
operator|)
argument_list|)
operator|==
expr|sizeof
operator|(
name|SmallType
operator|)
block|}
enum|;
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
comment|/// \brief Wrapper to model the analysis result concept.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// By default, this will implement the invalidate method with a trivial
end_comment

begin_comment
comment|/// implementation so that the actual analysis result doesn't need to provide
end_comment

begin_comment
comment|/// an invalidation handler. It is only selected when the invalidation handler
end_comment

begin_comment
comment|/// is not part of the ResultT's interface.
end_comment

begin_expr_stmt
name|template
operator|<
name|typename
name|IRUnitT
operator|,
name|typename
name|PassT
operator|,
name|typename
name|ResultT
operator|,
name|bool
name|HasInvalidateHandler
operator|=
name|ResultHasInvalidateMethod
operator|<
name|IRUnitT
operator|,
name|ResultT
operator|>
operator|::
name|Value
operator|>
expr|struct
name|AnalysisResultModel
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// \brief Specialization of \c AnalysisResultModel which provides the default
end_comment

begin_comment
comment|/// invalidate functionality.
end_comment

begin_expr_stmt
name|template
operator|<
name|typename
name|IRUnitT
operator|,
name|typename
name|PassT
operator|,
name|typename
name|ResultT
operator|>
expr|struct
name|AnalysisResultModel
operator|<
name|IRUnitT
operator|,
name|PassT
operator|,
name|ResultT
operator|,
name|false
operator|>
operator|:
name|AnalysisResultConcept
operator|<
name|IRUnitT
operator|>
block|{
name|explicit
name|AnalysisResultModel
argument_list|(
argument|ResultT Result
argument_list|)
operator|:
name|Result
argument_list|(
argument|std::move(Result)
argument_list|)
block|{}
comment|// We have to explicitly define all the special member functions because MSVC
comment|// refuses to generate them.
name|AnalysisResultModel
argument_list|(
specifier|const
name|AnalysisResultModel
operator|&
name|Arg
argument_list|)
operator|:
name|Result
argument_list|(
argument|Arg.Result
argument_list|)
block|{}
name|AnalysisResultModel
argument_list|(
name|AnalysisResultModel
operator|&&
name|Arg
argument_list|)
operator|:
name|Result
argument_list|(
argument|std::move(Arg.Result)
argument_list|)
block|{}
name|friend
name|void
name|swap
argument_list|(
argument|AnalysisResultModel&LHS
argument_list|,
argument|AnalysisResultModel&RHS
argument_list|)
block|{
name|using
name|std
operator|::
name|swap
block|;
name|swap
argument_list|(
name|LHS
operator|.
name|Result
argument_list|,
name|RHS
operator|.
name|Result
argument_list|)
block|;   }
name|AnalysisResultModel
operator|&
name|operator
operator|=
operator|(
name|AnalysisResultModel
name|RHS
operator|)
block|{
name|swap
argument_list|(
operator|*
name|this
argument_list|,
name|RHS
argument_list|)
block|;
return|return
operator|*
name|this
return|;
block|}
comment|/// \brief The model bases invalidation solely on being in the preserved set.
comment|//
comment|// FIXME: We should actually use two different concepts for analysis results
comment|// rather than two different models, and avoid the indirect function call for
comment|// ones that use the trivial behavior.
name|bool
name|invalidate
argument_list|(
argument|IRUnitT
argument_list|,
argument|const PreservedAnalyses&PA
argument_list|)
name|override
block|{
return|return
operator|!
name|PA
operator|.
name|preserved
argument_list|(
name|PassT
operator|::
name|ID
argument_list|()
argument_list|)
return|;
block|}
end_expr_stmt

begin_decl_stmt
name|ResultT
name|Result
decl_stmt|;
end_decl_stmt

begin_comment
unit|};
comment|/// \brief Specialization of \c AnalysisResultModel which delegates invalidate
end_comment

begin_comment
comment|/// handling to \c ResultT.
end_comment

begin_expr_stmt
name|template
operator|<
name|typename
name|IRUnitT
operator|,
name|typename
name|PassT
operator|,
name|typename
name|ResultT
operator|>
expr|struct
name|AnalysisResultModel
operator|<
name|IRUnitT
operator|,
name|PassT
operator|,
name|ResultT
operator|,
name|true
operator|>
operator|:
name|AnalysisResultConcept
operator|<
name|IRUnitT
operator|>
block|{
name|explicit
name|AnalysisResultModel
argument_list|(
argument|ResultT Result
argument_list|)
operator|:
name|Result
argument_list|(
argument|std::move(Result)
argument_list|)
block|{}
comment|// We have to explicitly define all the special member functions because MSVC
comment|// refuses to generate them.
name|AnalysisResultModel
argument_list|(
specifier|const
name|AnalysisResultModel
operator|&
name|Arg
argument_list|)
operator|:
name|Result
argument_list|(
argument|Arg.Result
argument_list|)
block|{}
name|AnalysisResultModel
argument_list|(
name|AnalysisResultModel
operator|&&
name|Arg
argument_list|)
operator|:
name|Result
argument_list|(
argument|std::move(Arg.Result)
argument_list|)
block|{}
name|friend
name|void
name|swap
argument_list|(
argument|AnalysisResultModel&LHS
argument_list|,
argument|AnalysisResultModel&RHS
argument_list|)
block|{
name|using
name|std
operator|::
name|swap
block|;
name|swap
argument_list|(
name|LHS
operator|.
name|Result
argument_list|,
name|RHS
operator|.
name|Result
argument_list|)
block|;   }
name|AnalysisResultModel
operator|&
name|operator
operator|=
operator|(
name|AnalysisResultModel
name|RHS
operator|)
block|{
name|swap
argument_list|(
operator|*
name|this
argument_list|,
name|RHS
argument_list|)
block|;
return|return
operator|*
name|this
return|;
block|}
comment|/// \brief The model delegates to the \c ResultT method.
name|bool
name|invalidate
argument_list|(
argument|IRUnitT IR
argument_list|,
argument|const PreservedAnalyses&PA
argument_list|)
name|override
block|{
return|return
name|Result
operator|.
name|invalidate
argument_list|(
name|IR
argument_list|,
name|PA
argument_list|)
return|;
block|}
end_expr_stmt

begin_decl_stmt
name|ResultT
name|Result
decl_stmt|;
end_decl_stmt

begin_comment
unit|};
comment|/// \brief Abstract concept of an analysis pass.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This concept is parameterized over the IR unit that it can run over and
end_comment

begin_comment
comment|/// produce an analysis result.
end_comment

begin_expr_stmt
name|template
operator|<
name|typename
name|IRUnitT
operator|,
name|typename
name|AnalysisManagerT
operator|>
expr|struct
name|AnalysisPassConcept
block|{
name|virtual
operator|~
name|AnalysisPassConcept
argument_list|()
block|{}
comment|/// \brief Method to run this analysis over a unit of IR.
comment|/// \returns A unique_ptr to the analysis result object to be queried by
comment|/// users.
name|virtual
name|std
operator|::
name|unique_ptr
operator|<
name|AnalysisResultConcept
operator|<
name|IRUnitT
operator|>>
name|run
argument_list|(
argument|IRUnitT IR
argument_list|,
argument|AnalysisManagerT *AM
argument_list|)
operator|=
literal|0
block|; }
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// \brief Wrapper to model the analysis pass concept.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// Can wrap any type which implements a suitable \c run method. The method
end_comment

begin_comment
comment|/// must accept the IRUnitT as an argument and produce an object which can be
end_comment

begin_comment
comment|/// wrapped in a \c AnalysisResultModel.
end_comment

begin_expr_stmt
name|template
operator|<
name|typename
name|IRUnitT
operator|,
name|typename
name|AnalysisManagerT
operator|,
name|typename
name|PassT
operator|,
name|bool
name|AcceptsAnalysisManager
operator|=
name|PassRunAcceptsAnalysisManager
operator|<
name|IRUnitT
operator|,
name|AnalysisManagerT
operator|,
name|PassT
operator|,
name|typename
name|PassT
operator|::
name|Result
operator|>
operator|::
name|Value
operator|>
expr|struct
name|AnalysisPassModel
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// \brief Specialization of \c AnalysisPassModel which passes an
end_comment

begin_comment
comment|/// \c AnalysisManager to PassT's run method.
end_comment

begin_expr_stmt
name|template
operator|<
name|typename
name|IRUnitT
operator|,
name|typename
name|AnalysisManagerT
operator|,
name|typename
name|PassT
operator|>
expr|struct
name|AnalysisPassModel
operator|<
name|IRUnitT
operator|,
name|AnalysisManagerT
operator|,
name|PassT
operator|,
name|true
operator|>
operator|:
name|AnalysisPassConcept
operator|<
name|IRUnitT
operator|,
name|AnalysisManagerT
operator|>
block|{
name|explicit
name|AnalysisPassModel
argument_list|(
argument|PassT Pass
argument_list|)
operator|:
name|Pass
argument_list|(
argument|std::move(Pass)
argument_list|)
block|{}
comment|// We have to explicitly define all the special member functions because MSVC
comment|// refuses to generate them.
name|AnalysisPassModel
argument_list|(
specifier|const
name|AnalysisPassModel
operator|&
name|Arg
argument_list|)
operator|:
name|Pass
argument_list|(
argument|Arg.Pass
argument_list|)
block|{}
name|AnalysisPassModel
argument_list|(
name|AnalysisPassModel
operator|&&
name|Arg
argument_list|)
operator|:
name|Pass
argument_list|(
argument|std::move(Arg.Pass)
argument_list|)
block|{}
name|friend
name|void
name|swap
argument_list|(
argument|AnalysisPassModel&LHS
argument_list|,
argument|AnalysisPassModel&RHS
argument_list|)
block|{
name|using
name|std
operator|::
name|swap
block|;
name|swap
argument_list|(
name|LHS
operator|.
name|Pass
argument_list|,
name|RHS
operator|.
name|Pass
argument_list|)
block|;   }
name|AnalysisPassModel
operator|&
name|operator
operator|=
operator|(
name|AnalysisPassModel
name|RHS
operator|)
block|{
name|swap
argument_list|(
operator|*
name|this
argument_list|,
name|RHS
argument_list|)
block|;
return|return
operator|*
name|this
return|;
block|}
end_expr_stmt

begin_comment
comment|// FIXME: Replace PassT::Result with type traits when we use C++11.
end_comment

begin_typedef
typedef|typedef
name|AnalysisResultModel
operator|<
name|IRUnitT
operator|,
name|PassT
operator|,
name|typename
name|PassT
operator|::
name|Result
operator|>
name|ResultModelT
expr_stmt|;
end_typedef

begin_comment
comment|/// \brief The model delegates to the \c PassT::run method.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// The return is wrapped in an \c AnalysisResultModel.
end_comment

begin_expr_stmt
name|std
operator|::
name|unique_ptr
operator|<
name|AnalysisResultConcept
operator|<
name|IRUnitT
operator|>>
name|run
argument_list|(
argument|IRUnitT IR
argument_list|,
argument|AnalysisManagerT *AM
argument_list|)
name|override
block|{
return|return
name|make_unique
operator|<
name|ResultModelT
operator|>
operator|(
name|Pass
operator|.
name|run
argument_list|(
name|IR
argument_list|,
name|AM
argument_list|)
operator|)
return|;
block|}
end_expr_stmt

begin_decl_stmt
name|PassT
name|Pass
decl_stmt|;
end_decl_stmt

begin_comment
unit|};
comment|/// \brief Specialization of \c AnalysisPassModel which does not pass an
end_comment

begin_comment
comment|/// \c AnalysisManager to PassT's run method.
end_comment

begin_expr_stmt
name|template
operator|<
name|typename
name|IRUnitT
operator|,
name|typename
name|AnalysisManagerT
operator|,
name|typename
name|PassT
operator|>
expr|struct
name|AnalysisPassModel
operator|<
name|IRUnitT
operator|,
name|AnalysisManagerT
operator|,
name|PassT
operator|,
name|false
operator|>
operator|:
name|AnalysisPassConcept
operator|<
name|IRUnitT
operator|,
name|AnalysisManagerT
operator|>
block|{
name|explicit
name|AnalysisPassModel
argument_list|(
argument|PassT Pass
argument_list|)
operator|:
name|Pass
argument_list|(
argument|std::move(Pass)
argument_list|)
block|{}
comment|// We have to explicitly define all the special member functions because MSVC
comment|// refuses to generate them.
name|AnalysisPassModel
argument_list|(
specifier|const
name|AnalysisPassModel
operator|&
name|Arg
argument_list|)
operator|:
name|Pass
argument_list|(
argument|Arg.Pass
argument_list|)
block|{}
name|AnalysisPassModel
argument_list|(
name|AnalysisPassModel
operator|&&
name|Arg
argument_list|)
operator|:
name|Pass
argument_list|(
argument|std::move(Arg.Pass)
argument_list|)
block|{}
name|friend
name|void
name|swap
argument_list|(
argument|AnalysisPassModel&LHS
argument_list|,
argument|AnalysisPassModel&RHS
argument_list|)
block|{
name|using
name|std
operator|::
name|swap
block|;
name|swap
argument_list|(
name|LHS
operator|.
name|Pass
argument_list|,
name|RHS
operator|.
name|Pass
argument_list|)
block|;   }
name|AnalysisPassModel
operator|&
name|operator
operator|=
operator|(
name|AnalysisPassModel
name|RHS
operator|)
block|{
name|swap
argument_list|(
operator|*
name|this
argument_list|,
name|RHS
argument_list|)
block|;
return|return
operator|*
name|this
return|;
block|}
end_expr_stmt

begin_comment
comment|// FIXME: Replace PassT::Result with type traits when we use C++11.
end_comment

begin_typedef
typedef|typedef
name|AnalysisResultModel
operator|<
name|IRUnitT
operator|,
name|PassT
operator|,
name|typename
name|PassT
operator|::
name|Result
operator|>
name|ResultModelT
expr_stmt|;
end_typedef

begin_comment
comment|/// \brief The model delegates to the \c PassT::run method.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// The return is wrapped in an \c AnalysisResultModel.
end_comment

begin_expr_stmt
name|std
operator|::
name|unique_ptr
operator|<
name|AnalysisResultConcept
operator|<
name|IRUnitT
operator|>>
name|run
argument_list|(
argument|IRUnitT IR
argument_list|,
argument|AnalysisManagerT *
argument_list|)
name|override
block|{
return|return
name|make_unique
operator|<
name|ResultModelT
operator|>
operator|(
name|Pass
operator|.
name|run
argument_list|(
name|IR
argument_list|)
operator|)
return|;
block|}
end_expr_stmt

begin_decl_stmt
name|PassT
name|Pass
decl_stmt|;
end_decl_stmt

begin_comment
unit|};  }
comment|// End namespace detail
end_comment

begin_expr_stmt
unit|class
name|ModuleAnalysisManager
expr_stmt|;
end_expr_stmt

begin_decl_stmt
name|class
name|ModulePassManager
block|{
name|public
label|:
comment|// We have to explicitly define all the special member functions because MSVC
comment|// refuses to generate them.
name|ModulePassManager
argument_list|()
block|{}
name|ModulePassManager
argument_list|(
name|ModulePassManager
operator|&&
name|Arg
argument_list|)
operator|:
name|Passes
argument_list|(
argument|std::move(Arg.Passes)
argument_list|)
block|{}
name|ModulePassManager
operator|&
name|operator
operator|=
operator|(
name|ModulePassManager
operator|&&
name|RHS
operator|)
block|{
name|Passes
operator|=
name|std
operator|::
name|move
argument_list|(
name|RHS
operator|.
name|Passes
argument_list|)
block|;
return|return
operator|*
name|this
return|;
block|}
comment|/// \brief Run all of the module passes in this module pass manager over
comment|/// a module.
comment|///
comment|/// This method should only be called for a single module as there is the
comment|/// expectation that the lifetime of a pass is bounded to that of a module.
name|PreservedAnalyses
name|run
parameter_list|(
name|Module
modifier|*
name|M
parameter_list|,
name|ModuleAnalysisManager
modifier|*
name|AM
init|=
name|nullptr
parameter_list|)
function_decl|;
name|template
operator|<
name|typename
name|ModulePassT
operator|>
name|void
name|addPass
argument_list|(
argument|ModulePassT Pass
argument_list|)
block|{
name|Passes
operator|.
name|emplace_back
argument_list|(
argument|new ModulePassModel<ModulePassT>(std::move(Pass))
argument_list|)
block|;   }
specifier|static
name|StringRef
name|name
argument_list|()
block|{
return|return
literal|"ModulePassManager"
return|;
block|}
name|private
label|:
comment|// Pull in the concept type and model template specialized for modules.
typedef|typedef
name|detail
operator|::
name|PassConcept
operator|<
name|Module
operator|*
operator|,
name|ModuleAnalysisManager
operator|>
name|ModulePassConcept
expr_stmt|;
name|template
operator|<
name|typename
name|PassT
operator|>
expr|struct
name|ModulePassModel
operator|:
name|detail
operator|::
name|PassModel
operator|<
name|Module
operator|*
operator|,
name|ModuleAnalysisManager
operator|,
name|PassT
operator|>
block|{
name|ModulePassModel
argument_list|(
argument|PassT Pass
argument_list|)
operator|:
name|detail
operator|::
name|PassModel
operator|<
name|Module
operator|*
block|,
name|ModuleAnalysisManager
block|,
name|PassT
operator|>
operator|(
name|std
operator|::
name|move
argument_list|(
name|Pass
argument_list|)
operator|)
block|{}
block|}
expr_stmt|;
name|ModulePassManager
argument_list|(
argument|const ModulePassManager&
argument_list|)
name|LLVM_DELETED_FUNCTION
expr_stmt|;
name|ModulePassManager
modifier|&
name|operator
init|=
operator|(
specifier|const
name|ModulePassManager
operator|&
operator|)
name|LLVM_DELETED_FUNCTION
decl_stmt|;
name|std
operator|::
name|vector
operator|<
name|std
operator|::
name|unique_ptr
operator|<
name|ModulePassConcept
operator|>>
name|Passes
expr_stmt|;
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_decl_stmt
name|class
name|FunctionAnalysisManager
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|class
name|FunctionPassManager
block|{
name|public
label|:
comment|// We have to explicitly define all the special member functions because MSVC
comment|// refuses to generate them.
name|FunctionPassManager
argument_list|()
block|{}
name|FunctionPassManager
argument_list|(
name|FunctionPassManager
operator|&&
name|Arg
argument_list|)
operator|:
name|Passes
argument_list|(
argument|std::move(Arg.Passes)
argument_list|)
block|{}
name|FunctionPassManager
operator|&
name|operator
operator|=
operator|(
name|FunctionPassManager
operator|&&
name|RHS
operator|)
block|{
name|Passes
operator|=
name|std
operator|::
name|move
argument_list|(
name|RHS
operator|.
name|Passes
argument_list|)
block|;
return|return
operator|*
name|this
return|;
block|}
name|template
operator|<
name|typename
name|FunctionPassT
operator|>
name|void
name|addPass
argument_list|(
argument|FunctionPassT Pass
argument_list|)
block|{
name|Passes
operator|.
name|emplace_back
argument_list|(
argument|new FunctionPassModel<FunctionPassT>(std::move(Pass))
argument_list|)
block|;   }
name|PreservedAnalyses
name|run
argument_list|(
name|Function
operator|*
name|F
argument_list|,
name|FunctionAnalysisManager
operator|*
name|AM
operator|=
name|nullptr
argument_list|)
expr_stmt|;
specifier|static
name|StringRef
name|name
parameter_list|()
block|{
return|return
literal|"FunctionPassManager"
return|;
block|}
name|private
label|:
comment|// Pull in the concept type and model template specialized for functions.
typedef|typedef
name|detail
operator|::
name|PassConcept
operator|<
name|Function
operator|*
operator|,
name|FunctionAnalysisManager
operator|>
name|FunctionPassConcept
expr_stmt|;
name|template
operator|<
name|typename
name|PassT
operator|>
expr|struct
name|FunctionPassModel
operator|:
name|detail
operator|::
name|PassModel
operator|<
name|Function
operator|*
operator|,
name|FunctionAnalysisManager
operator|,
name|PassT
operator|>
block|{
name|FunctionPassModel
argument_list|(
argument|PassT Pass
argument_list|)
operator|:
name|detail
operator|::
name|PassModel
operator|<
name|Function
operator|*
block|,
name|FunctionAnalysisManager
block|,
name|PassT
operator|>
operator|(
name|std
operator|::
name|move
argument_list|(
name|Pass
argument_list|)
operator|)
block|{}
block|}
expr_stmt|;
name|FunctionPassManager
argument_list|(
argument|const FunctionPassManager&
argument_list|)
name|LLVM_DELETED_FUNCTION
expr_stmt|;
name|FunctionPassManager
modifier|&
name|operator
init|=
operator|(
specifier|const
name|FunctionPassManager
operator|&
operator|)
name|LLVM_DELETED_FUNCTION
decl_stmt|;
name|std
operator|::
name|vector
operator|<
name|std
operator|::
name|unique_ptr
operator|<
name|FunctionPassConcept
operator|>>
name|Passes
expr_stmt|;
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_decl_stmt
name|namespace
name|detail
block|{
comment|/// \brief A CRTP base used to implement analysis managers.
comment|///
comment|/// This class template serves as the boiler plate of an analysis manager. Any
comment|/// analysis manager can be implemented on top of this base class. Any
comment|/// implementation will be required to provide specific hooks:
comment|///
comment|/// - getResultImpl
comment|/// - getCachedResultImpl
comment|/// - invalidateImpl
comment|///
comment|/// The details of the call pattern are within.
name|template
operator|<
name|typename
name|DerivedT
operator|,
name|typename
name|IRUnitT
operator|>
name|class
name|AnalysisManagerBase
block|{
name|DerivedT
operator|*
name|derived_this
argument_list|()
block|{
return|return
name|static_cast
operator|<
name|DerivedT
operator|*
operator|>
operator|(
name|this
operator|)
return|;
block|}
specifier|const
name|DerivedT
operator|*
name|derived_this
argument_list|()
specifier|const
block|{
return|return
name|static_cast
operator|<
specifier|const
name|DerivedT
operator|*
operator|>
operator|(
name|this
operator|)
return|;
block|}
name|AnalysisManagerBase
argument_list|(
argument|const AnalysisManagerBase&
argument_list|)
name|LLVM_DELETED_FUNCTION
block|;
name|AnalysisManagerBase
operator|&
name|operator
operator|=
operator|(
specifier|const
name|AnalysisManagerBase
operator|&
operator|)
name|LLVM_DELETED_FUNCTION
block|;
name|protected
operator|:
typedef|typedef
name|detail
operator|::
name|AnalysisResultConcept
operator|<
name|IRUnitT
operator|>
name|ResultConceptT
expr_stmt|;
typedef|typedef
name|detail
operator|::
name|AnalysisPassConcept
operator|<
name|IRUnitT
operator|,
name|DerivedT
operator|>
name|PassConceptT
expr_stmt|;
comment|// FIXME: Provide template aliases for the models when we're using C++11 in
comment|// a mode supporting them.
comment|// We have to explicitly define all the special member functions because MSVC
comment|// refuses to generate them.
name|AnalysisManagerBase
argument_list|()
block|{}
name|AnalysisManagerBase
argument_list|(
name|AnalysisManagerBase
operator|&&
name|Arg
argument_list|)
operator|:
name|AnalysisPasses
argument_list|(
argument|std::move(Arg.AnalysisPasses)
argument_list|)
block|{}
name|AnalysisManagerBase
operator|&
name|operator
operator|=
operator|(
name|AnalysisManagerBase
operator|&&
name|RHS
operator|)
block|{
name|AnalysisPasses
operator|=
name|std
operator|::
name|move
argument_list|(
name|RHS
operator|.
name|AnalysisPasses
argument_list|)
block|;
return|return
operator|*
name|this
return|;
block|}
name|public
label|:
comment|/// \brief Get the result of an analysis pass for this module.
comment|///
comment|/// If there is not a valid cached result in the manager already, this will
comment|/// re-run the analysis to produce a valid result.
name|template
operator|<
name|typename
name|PassT
operator|>
name|typename
name|PassT
operator|::
name|Result
operator|&
name|getResult
argument_list|(
argument|IRUnitT IR
argument_list|)
block|{
name|assert
argument_list|(
name|AnalysisPasses
operator|.
name|count
argument_list|(
name|PassT
operator|::
name|ID
argument_list|()
argument_list|)
operator|&&
literal|"This analysis pass was not registered prior to being queried"
argument_list|)
block|;
name|ResultConceptT
operator|&
name|ResultConcept
operator|=
name|derived_this
argument_list|()
operator|->
name|getResultImpl
argument_list|(
name|PassT
operator|::
name|ID
argument_list|()
argument_list|,
name|IR
argument_list|)
block|;
typedef|typedef
name|detail
operator|::
name|AnalysisResultModel
operator|<
name|IRUnitT
operator|,
name|PassT
operator|,
name|typename
name|PassT
operator|::
name|Result
operator|>
name|ResultModelT
expr_stmt|;
return|return
name|static_cast
operator|<
name|ResultModelT
operator|&
operator|>
operator|(
name|ResultConcept
operator|)
operator|.
name|Result
return|;
block|}
end_decl_stmt

begin_comment
comment|/// \brief Get the cached result of an analysis pass for this module.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This method never runs the analysis.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \returns null if there is no cached result.
end_comment

begin_expr_stmt
name|template
operator|<
name|typename
name|PassT
operator|>
name|typename
name|PassT
operator|::
name|Result
operator|*
name|getCachedResult
argument_list|(
argument|IRUnitT IR
argument_list|)
specifier|const
block|{
name|assert
argument_list|(
name|AnalysisPasses
operator|.
name|count
argument_list|(
name|PassT
operator|::
name|ID
argument_list|()
argument_list|)
operator|&&
literal|"This analysis pass was not registered prior to being queried"
argument_list|)
block|;
name|ResultConceptT
operator|*
name|ResultConcept
operator|=
name|derived_this
argument_list|()
operator|->
name|getCachedResultImpl
argument_list|(
name|PassT
operator|::
name|ID
argument_list|()
argument_list|,
name|IR
argument_list|)
block|;
if|if
condition|(
operator|!
name|ResultConcept
condition|)
return|return
name|nullptr
return|;
end_expr_stmt

begin_typedef
typedef|typedef
name|detail
operator|::
name|AnalysisResultModel
operator|<
name|IRUnitT
operator|,
name|PassT
operator|,
name|typename
name|PassT
operator|::
name|Result
operator|>
name|ResultModelT
expr_stmt|;
end_typedef

begin_return
return|return
operator|&
name|static_cast
operator|<
name|ResultModelT
operator|*
operator|>
operator|(
name|ResultConcept
operator|)
operator|->
name|Result
return|;
end_return

begin_comment
unit|}
comment|/// \brief Register an analysis pass with the manager.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This provides an initialized and set-up analysis pass to the analysis
end_comment

begin_comment
comment|/// manager. Whomever is setting up analysis passes must use this to populate
end_comment

begin_comment
comment|/// the manager with all of the analysis passes available.
end_comment

begin_expr_stmt
unit|template
operator|<
name|typename
name|PassT
operator|>
name|void
name|registerPass
argument_list|(
argument|PassT Pass
argument_list|)
block|{
name|assert
argument_list|(
operator|!
name|AnalysisPasses
operator|.
name|count
argument_list|(
name|PassT
operator|::
name|ID
argument_list|()
argument_list|)
operator|&&
literal|"Registered the same analysis pass twice!"
argument_list|)
block|;
typedef|typedef
name|detail
operator|::
name|AnalysisPassModel
operator|<
name|IRUnitT
operator|,
name|DerivedT
operator|,
name|PassT
operator|>
name|PassModelT
expr_stmt|;
name|AnalysisPasses
index|[
name|PassT
operator|::
name|ID
argument_list|()
index|]
operator|.
name|reset
argument_list|(
argument|new PassModelT(std::move(Pass))
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
unit|}
comment|/// \brief Invalidate a specific analysis pass for an IR module.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// Note that the analysis result can disregard invalidation.
end_comment

begin_expr_stmt
unit|template
operator|<
name|typename
name|PassT
operator|>
name|void
name|invalidate
argument_list|(
argument|Module *M
argument_list|)
block|{
name|assert
argument_list|(
name|AnalysisPasses
operator|.
name|count
argument_list|(
name|PassT
operator|::
name|ID
argument_list|()
argument_list|)
operator|&&
literal|"This analysis pass was not registered prior to being invalidated"
argument_list|)
block|;
name|derived_this
argument_list|()
operator|->
name|invalidateImpl
argument_list|(
name|PassT
operator|::
name|ID
argument_list|()
argument_list|,
name|M
argument_list|)
block|;   }
comment|/// \brief Invalidate analyses cached for an IR unit.
comment|///
comment|/// Walk through all of the analyses pertaining to this unit of IR and
comment|/// invalidate them unless they are preserved by the PreservedAnalyses set.
name|void
name|invalidate
argument_list|(
argument|IRUnitT IR
argument_list|,
argument|const PreservedAnalyses&PA
argument_list|)
block|{
name|derived_this
argument_list|()
operator|->
name|invalidateImpl
argument_list|(
name|IR
argument_list|,
name|PA
argument_list|)
block|;   }
name|protected
operator|:
comment|/// \brief Lookup a registered analysis pass.
name|PassConceptT
operator|&
name|lookupPass
argument_list|(
argument|void *PassID
argument_list|)
block|{
name|typename
name|AnalysisPassMapT
operator|::
name|iterator
name|PI
operator|=
name|AnalysisPasses
operator|.
name|find
argument_list|(
name|PassID
argument_list|)
block|;
name|assert
argument_list|(
name|PI
operator|!=
name|AnalysisPasses
operator|.
name|end
argument_list|()
operator|&&
literal|"Analysis passes must be registered prior to being queried!"
argument_list|)
block|;
return|return
operator|*
name|PI
operator|->
name|second
return|;
block|}
end_expr_stmt

begin_comment
comment|/// \brief Lookup a registered analysis pass.
end_comment

begin_decl_stmt
specifier|const
name|PassConceptT
modifier|&
name|lookupPass
argument_list|(
name|void
operator|*
name|PassID
argument_list|)
decl|const
block|{
name|typename
name|AnalysisPassMapT
operator|::
name|const_iterator
name|PI
operator|=
name|AnalysisPasses
operator|.
name|find
argument_list|(
name|PassID
argument_list|)
expr_stmt|;
name|assert
argument_list|(
name|PI
operator|!=
name|AnalysisPasses
operator|.
name|end
argument_list|()
operator|&&
literal|"Analysis passes must be registered prior to being queried!"
argument_list|)
expr_stmt|;
return|return
operator|*
name|PI
operator|->
name|second
return|;
block|}
end_decl_stmt

begin_label
name|private
label|:
end_label

begin_comment
comment|/// \brief Map type from module analysis pass ID to pass concept pointer.
end_comment

begin_typedef
typedef|typedef
name|DenseMap
operator|<
name|void
operator|*
operator|,
name|std
operator|::
name|unique_ptr
operator|<
name|PassConceptT
operator|>>
name|AnalysisPassMapT
expr_stmt|;
end_typedef

begin_comment
comment|/// \brief Collection of module analysis passes, indexed by ID.
end_comment

begin_decl_stmt
name|AnalysisPassMapT
name|AnalysisPasses
decl_stmt|;
end_decl_stmt

begin_comment
unit|};  }
comment|// End namespace detail
end_comment

begin_comment
comment|/// \brief A module analysis pass manager with lazy running and caching of
end_comment

begin_comment
comment|/// results.
end_comment

begin_label
unit|class
name|ModuleAnalysisManager
label|:
end_label

begin_expr_stmt
name|public
name|detail
operator|::
name|AnalysisManagerBase
operator|<
name|ModuleAnalysisManager
operator|,
name|Module
operator|*
operator|>
block|{
name|friend
name|class
name|detail
operator|::
name|AnalysisManagerBase
operator|<
name|ModuleAnalysisManager
block|,
name|Module
operator|*
operator|>
block|;
typedef|typedef
name|detail
operator|::
name|AnalysisManagerBase
operator|<
name|ModuleAnalysisManager
operator|,
name|Module
operator|*
operator|>
name|BaseT
expr_stmt|;
end_expr_stmt

begin_typedef
typedef|typedef
name|BaseT
operator|::
name|ResultConceptT
name|ResultConceptT
expr_stmt|;
end_typedef

begin_typedef
typedef|typedef
name|BaseT
operator|::
name|PassConceptT
name|PassConceptT
expr_stmt|;
end_typedef

begin_label
name|public
label|:
end_label

begin_comment
comment|// We have to explicitly define all the special member functions because MSVC
end_comment

begin_comment
comment|// refuses to generate them.
end_comment

begin_macro
name|ModuleAnalysisManager
argument_list|()
end_macro

begin_block
block|{}
end_block

begin_expr_stmt
name|ModuleAnalysisManager
argument_list|(
name|ModuleAnalysisManager
operator|&&
name|Arg
argument_list|)
operator|:
name|BaseT
argument_list|(
name|std
operator|::
name|move
argument_list|(
name|static_cast
operator|<
name|BaseT
operator|&
operator|>
operator|(
name|Arg
operator|)
argument_list|)
argument_list|)
operator|,
name|ModuleAnalysisResults
argument_list|(
argument|std::move(Arg.ModuleAnalysisResults)
argument_list|)
block|{}
name|ModuleAnalysisManager
operator|&
name|operator
operator|=
operator|(
name|ModuleAnalysisManager
operator|&&
name|RHS
operator|)
block|{
name|BaseT
operator|::
name|operator
operator|=
operator|(
name|std
operator|::
name|move
argument_list|(
name|static_cast
operator|<
name|BaseT
operator|&
operator|>
operator|(
name|RHS
operator|)
argument_list|)
operator|)
block|;
name|ModuleAnalysisResults
operator|=
name|std
operator|::
name|move
argument_list|(
name|RHS
operator|.
name|ModuleAnalysisResults
argument_list|)
block|;
return|return
operator|*
name|this
return|;
block|}
end_expr_stmt

begin_label
name|private
label|:
end_label

begin_macro
name|ModuleAnalysisManager
argument_list|(
argument|const ModuleAnalysisManager&
argument_list|)
end_macro

begin_expr_stmt
name|LLVM_DELETED_FUNCTION
expr_stmt|;
end_expr_stmt

begin_decl_stmt
name|ModuleAnalysisManager
modifier|&
name|operator
init|=
operator|(
specifier|const
name|ModuleAnalysisManager
operator|&
operator|)
name|LLVM_DELETED_FUNCTION
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// \brief Get a module pass result, running the pass if necessary.
end_comment

begin_function_decl
name|ResultConceptT
modifier|&
name|getResultImpl
parameter_list|(
name|void
modifier|*
name|PassID
parameter_list|,
name|Module
modifier|*
name|M
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// \brief Get a cached module pass result or return null.
end_comment

begin_decl_stmt
name|ResultConceptT
modifier|*
name|getCachedResultImpl
argument_list|(
name|void
operator|*
name|PassID
argument_list|,
name|Module
operator|*
name|M
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// \brief Invalidate a module pass result.
end_comment

begin_function_decl
name|void
name|invalidateImpl
parameter_list|(
name|void
modifier|*
name|PassID
parameter_list|,
name|Module
modifier|*
name|M
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// \brief Invalidate results across a module.
end_comment

begin_function_decl
name|void
name|invalidateImpl
parameter_list|(
name|Module
modifier|*
name|M
parameter_list|,
specifier|const
name|PreservedAnalyses
modifier|&
name|PA
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// \brief Map type from module analysis pass ID to pass result concept
end_comment

begin_comment
comment|/// pointer.
end_comment

begin_typedef
typedef|typedef
name|DenseMap
operator|<
name|void
operator|*
operator|,
name|std
operator|::
name|unique_ptr
operator|<
name|detail
operator|::
name|AnalysisResultConcept
operator|<
name|Module
operator|*
operator|>>>
name|ModuleAnalysisResultMapT
expr_stmt|;
end_typedef

begin_comment
comment|/// \brief Cache of computed module analysis results for this module.
end_comment

begin_decl_stmt
name|ModuleAnalysisResultMapT
name|ModuleAnalysisResults
decl_stmt|;
end_decl_stmt

begin_comment
unit|};
comment|/// \brief A function analysis manager to coordinate and cache analyses run over
end_comment

begin_comment
comment|/// a module.
end_comment

begin_decl_stmt
name|class
name|FunctionAnalysisManager
range|:
name|public
name|detail
operator|::
name|AnalysisManagerBase
operator|<
name|FunctionAnalysisManager
decl_stmt|,
name|Function
modifier|*
decl|>
block|{
name|friend
name|class
name|detail
operator|::
name|AnalysisManagerBase
operator|<
name|FunctionAnalysisManager
operator|,
name|Function
operator|*
operator|>
expr_stmt|;
typedef|typedef
name|detail
operator|::
name|AnalysisManagerBase
operator|<
name|FunctionAnalysisManager
operator|,
name|Function
operator|*
operator|>
name|BaseT
expr_stmt|;
typedef|typedef
name|BaseT
operator|::
name|ResultConceptT
name|ResultConceptT
expr_stmt|;
typedef|typedef
name|BaseT
operator|::
name|PassConceptT
name|PassConceptT
expr_stmt|;
name|public
label|:
comment|// Most public APIs are inherited from the CRTP base class.
comment|// We have to explicitly define all the special member functions because MSVC
comment|// refuses to generate them.
name|FunctionAnalysisManager
argument_list|()
block|{}
name|FunctionAnalysisManager
argument_list|(
name|FunctionAnalysisManager
operator|&&
name|Arg
argument_list|)
operator|:
name|BaseT
argument_list|(
name|std
operator|::
name|move
argument_list|(
name|static_cast
operator|<
name|BaseT
operator|&
operator|>
operator|(
name|Arg
operator|)
argument_list|)
argument_list|)
operator|,
name|FunctionAnalysisResults
argument_list|(
argument|std::move(Arg.FunctionAnalysisResults)
argument_list|)
block|{}
name|FunctionAnalysisManager
operator|&
name|operator
operator|=
operator|(
name|FunctionAnalysisManager
operator|&&
name|RHS
operator|)
block|{
name|BaseT
operator|::
name|operator
operator|=
operator|(
name|std
operator|::
name|move
argument_list|(
name|static_cast
operator|<
name|BaseT
operator|&
operator|>
operator|(
name|RHS
operator|)
argument_list|)
operator|)
block|;
name|FunctionAnalysisResults
operator|=
name|std
operator|::
name|move
argument_list|(
name|RHS
operator|.
name|FunctionAnalysisResults
argument_list|)
block|;
return|return
operator|*
name|this
return|;
block|}
comment|/// \brief Returns true if the analysis manager has an empty results cache.
name|bool
name|empty
argument_list|()
specifier|const
expr_stmt|;
comment|/// \brief Clear the function analysis result cache.
comment|///
comment|/// This routine allows cleaning up when the set of functions itself has
comment|/// potentially changed, and thus we can't even look up a a result and
comment|/// invalidate it directly. Notably, this does *not* call invalidate
comment|/// functions as there is nothing to be done for them.
name|void
name|clear
parameter_list|()
function_decl|;
name|private
label|:
name|FunctionAnalysisManager
argument_list|(
argument|const FunctionAnalysisManager&
argument_list|)
name|LLVM_DELETED_FUNCTION
expr_stmt|;
name|FunctionAnalysisManager
modifier|&
name|operator
init|=
operator|(
specifier|const
name|FunctionAnalysisManager
operator|&
operator|)
name|LLVM_DELETED_FUNCTION
decl_stmt|;
comment|/// \brief Get a function pass result, running the pass if necessary.
name|ResultConceptT
modifier|&
name|getResultImpl
parameter_list|(
name|void
modifier|*
name|PassID
parameter_list|,
name|Function
modifier|*
name|F
parameter_list|)
function_decl|;
comment|/// \brief Get a cached function pass result or return null.
name|ResultConceptT
modifier|*
name|getCachedResultImpl
argument_list|(
name|void
operator|*
name|PassID
argument_list|,
name|Function
operator|*
name|F
argument_list|)
decl|const
decl_stmt|;
comment|/// \brief Invalidate a function pass result.
name|void
name|invalidateImpl
parameter_list|(
name|void
modifier|*
name|PassID
parameter_list|,
name|Function
modifier|*
name|F
parameter_list|)
function_decl|;
comment|/// \brief Invalidate the results for a function..
name|void
name|invalidateImpl
parameter_list|(
name|Function
modifier|*
name|F
parameter_list|,
specifier|const
name|PreservedAnalyses
modifier|&
name|PA
parameter_list|)
function_decl|;
comment|/// \brief List of function analysis pass IDs and associated concept pointers.
comment|///
comment|/// Requires iterators to be valid across appending new entries and arbitrary
comment|/// erases. Provides both the pass ID and concept pointer such that it is
comment|/// half of a bijection and provides storage for the actual result concept.
typedef|typedef
name|std
operator|::
name|list
operator|<
name|std
operator|::
name|pair
operator|<
name|void
operator|*
operator|,
name|std
operator|::
name|unique_ptr
operator|<
name|detail
operator|::
name|AnalysisResultConcept
operator|<
name|Function
operator|*
operator|>>>
operator|>
name|FunctionAnalysisResultListT
expr_stmt|;
comment|/// \brief Map type from function pointer to our custom list type.
typedef|typedef
name|DenseMap
operator|<
name|Function
operator|*
operator|,
name|FunctionAnalysisResultListT
operator|>
name|FunctionAnalysisResultListMapT
expr_stmt|;
comment|/// \brief Map from function to a list of function analysis results.
comment|///
comment|/// Provides linear time removal of all analysis results for a function and
comment|/// the ultimate storage for a particular cached analysis result.
name|FunctionAnalysisResultListMapT
name|FunctionAnalysisResultLists
decl_stmt|;
comment|/// \brief Map type from a pair of analysis ID and function pointer to an
comment|/// iterator into a particular result list.
typedef|typedef
name|DenseMap
operator|<
name|std
operator|::
name|pair
operator|<
name|void
operator|*
operator|,
name|Function
operator|*
operator|>
operator|,
name|FunctionAnalysisResultListT
operator|::
name|iterator
operator|>
name|FunctionAnalysisResultMapT
expr_stmt|;
comment|/// \brief Map from an analysis ID and function to a particular cached
comment|/// analysis result.
name|FunctionAnalysisResultMapT
name|FunctionAnalysisResults
decl_stmt|;
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
comment|/// \brief A module analysis which acts as a proxy for a function analysis
end_comment

begin_comment
comment|/// manager.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This primarily proxies invalidation information from the module analysis
end_comment

begin_comment
comment|/// manager and module pass manager to a function analysis manager. You should
end_comment

begin_comment
comment|/// never use a function analysis manager from within (transitively) a module
end_comment

begin_comment
comment|/// pass manager unless your parent module pass has received a proxy result
end_comment

begin_comment
comment|/// object for it.
end_comment

begin_decl_stmt
name|class
name|FunctionAnalysisManagerModuleProxy
block|{
name|public
label|:
name|class
name|Result
decl_stmt|;
specifier|static
name|void
modifier|*
name|ID
parameter_list|()
block|{
return|return
operator|(
name|void
operator|*
operator|)
operator|&
name|PassID
return|;
block|}
name|explicit
name|FunctionAnalysisManagerModuleProxy
argument_list|(
name|FunctionAnalysisManager
operator|&
name|FAM
argument_list|)
operator|:
name|FAM
argument_list|(
argument|&FAM
argument_list|)
block|{}
comment|// We have to explicitly define all the special member functions because MSVC
comment|// refuses to generate them.
name|FunctionAnalysisManagerModuleProxy
argument_list|(
specifier|const
name|FunctionAnalysisManagerModuleProxy
operator|&
name|Arg
argument_list|)
operator|:
name|FAM
argument_list|(
argument|Arg.FAM
argument_list|)
block|{}
name|FunctionAnalysisManagerModuleProxy
argument_list|(
name|FunctionAnalysisManagerModuleProxy
operator|&&
name|Arg
argument_list|)
operator|:
name|FAM
argument_list|(
argument|std::move(Arg.FAM)
argument_list|)
block|{}
name|FunctionAnalysisManagerModuleProxy
operator|&
name|operator
operator|=
operator|(
name|FunctionAnalysisManagerModuleProxy
name|RHS
operator|)
block|{
name|std
operator|::
name|swap
argument_list|(
name|FAM
argument_list|,
name|RHS
operator|.
name|FAM
argument_list|)
block|;
return|return
operator|*
name|this
return|;
block|}
comment|/// \brief Run the analysis pass and create our proxy result object.
comment|///
comment|/// This doesn't do any interesting work, it is primarily used to insert our
comment|/// proxy result object into the module analysis cache so that we can proxy
comment|/// invalidation to the function analysis manager.
comment|///
comment|/// In debug builds, it will also assert that the analysis manager is empty
comment|/// as no queries should arrive at the function analysis manager prior to
comment|/// this analysis being requested.
name|Result
name|run
parameter_list|(
name|Module
modifier|*
name|M
parameter_list|)
function_decl|;
name|private
label|:
specifier|static
name|char
name|PassID
decl_stmt|;
name|FunctionAnalysisManager
modifier|*
name|FAM
decl_stmt|;
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
comment|/// \brief The result proxy object for the
end_comment

begin_comment
comment|/// \c FunctionAnalysisManagerModuleProxy.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// See its documentation for more information.
end_comment

begin_expr_stmt
name|class
name|FunctionAnalysisManagerModuleProxy
operator|::
name|Result
block|{
name|public
operator|:
name|explicit
name|Result
argument_list|(
name|FunctionAnalysisManager
operator|&
name|FAM
argument_list|)
operator|:
name|FAM
argument_list|(
argument|&FAM
argument_list|)
block|{}
comment|// We have to explicitly define all the special member functions because MSVC
comment|// refuses to generate them.
name|Result
argument_list|(
specifier|const
name|Result
operator|&
name|Arg
argument_list|)
operator|:
name|FAM
argument_list|(
argument|Arg.FAM
argument_list|)
block|{}
name|Result
argument_list|(
name|Result
operator|&&
name|Arg
argument_list|)
operator|:
name|FAM
argument_list|(
argument|std::move(Arg.FAM)
argument_list|)
block|{}
name|Result
operator|&
name|operator
operator|=
operator|(
name|Result
name|RHS
operator|)
block|{
name|std
operator|::
name|swap
argument_list|(
name|FAM
argument_list|,
name|RHS
operator|.
name|FAM
argument_list|)
block|;
return|return
operator|*
name|this
return|;
block|}
operator|~
name|Result
argument_list|()
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// \brief Accessor for the \c FunctionAnalysisManager.
end_comment

begin_function
name|FunctionAnalysisManager
modifier|&
name|getManager
parameter_list|()
block|{
return|return
operator|*
name|FAM
return|;
block|}
end_function

begin_comment
comment|/// \brief Handler for invalidation of the module.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// If this analysis itself is preserved, then we assume that the set of \c
end_comment

begin_comment
comment|/// Function objects in the \c Module hasn't changed and thus we don't need
end_comment

begin_comment
comment|/// to invalidate *all* cached data associated with a \c Function* in the \c
end_comment

begin_comment
comment|/// FunctionAnalysisManager.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// Regardless of whether this analysis is marked as preserved, all of the
end_comment

begin_comment
comment|/// analyses in the \c FunctionAnalysisManager are potentially invalidated
end_comment

begin_comment
comment|/// based on the set of preserved analyses.
end_comment

begin_function_decl
name|bool
name|invalidate
parameter_list|(
name|Module
modifier|*
name|M
parameter_list|,
specifier|const
name|PreservedAnalyses
modifier|&
name|PA
parameter_list|)
function_decl|;
end_function_decl

begin_label
name|private
label|:
end_label

begin_decl_stmt
name|FunctionAnalysisManager
modifier|*
name|FAM
decl_stmt|;
end_decl_stmt

begin_comment
unit|};
comment|/// \brief A function analysis which acts as a proxy for a module analysis
end_comment

begin_comment
comment|/// manager.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This primarily provides an accessor to a parent module analysis manager to
end_comment

begin_comment
comment|/// function passes. Only the const interface of the module analysis manager is
end_comment

begin_comment
comment|/// provided to indicate that once inside of a function analysis pass you
end_comment

begin_comment
comment|/// cannot request a module analysis to actually run. Instead, the user must
end_comment

begin_comment
comment|/// rely on the \c getCachedResult API.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This proxy *doesn't* manage the invalidation in any way. That is handled by
end_comment

begin_comment
comment|/// the recursive return path of each layer of the pass manager and the
end_comment

begin_comment
comment|/// returned PreservedAnalysis set.
end_comment

begin_decl_stmt
name|class
name|ModuleAnalysisManagerFunctionProxy
block|{
name|public
label|:
comment|/// \brief Result proxy object for \c ModuleAnalysisManagerFunctionProxy.
name|class
name|Result
block|{
name|public
label|:
name|explicit
name|Result
argument_list|(
specifier|const
name|ModuleAnalysisManager
operator|&
name|MAM
argument_list|)
operator|:
name|MAM
argument_list|(
argument|&MAM
argument_list|)
block|{}
comment|// We have to explicitly define all the special member functions because
comment|// MSVC refuses to generate them.
name|Result
argument_list|(
specifier|const
name|Result
operator|&
name|Arg
argument_list|)
operator|:
name|MAM
argument_list|(
argument|Arg.MAM
argument_list|)
block|{}
name|Result
argument_list|(
name|Result
operator|&&
name|Arg
argument_list|)
operator|:
name|MAM
argument_list|(
argument|std::move(Arg.MAM)
argument_list|)
block|{}
name|Result
operator|&
name|operator
operator|=
operator|(
name|Result
name|RHS
operator|)
block|{
name|std
operator|::
name|swap
argument_list|(
name|MAM
argument_list|,
name|RHS
operator|.
name|MAM
argument_list|)
block|;
return|return
operator|*
name|this
return|;
block|}
specifier|const
name|ModuleAnalysisManager
operator|&
name|getManager
argument_list|()
specifier|const
block|{
return|return
operator|*
name|MAM
return|;
block|}
comment|/// \brief Handle invalidation by ignoring it, this pass is immutable.
name|bool
name|invalidate
parameter_list|(
name|Function
modifier|*
parameter_list|)
block|{
return|return
name|false
return|;
block|}
name|private
label|:
specifier|const
name|ModuleAnalysisManager
modifier|*
name|MAM
decl_stmt|;
block|}
empty_stmt|;
specifier|static
name|void
modifier|*
name|ID
parameter_list|()
block|{
return|return
operator|(
name|void
operator|*
operator|)
operator|&
name|PassID
return|;
block|}
name|ModuleAnalysisManagerFunctionProxy
argument_list|(
specifier|const
name|ModuleAnalysisManager
operator|&
name|MAM
argument_list|)
operator|:
name|MAM
argument_list|(
argument|&MAM
argument_list|)
block|{}
comment|// We have to explicitly define all the special member functions because MSVC
comment|// refuses to generate them.
name|ModuleAnalysisManagerFunctionProxy
argument_list|(
specifier|const
name|ModuleAnalysisManagerFunctionProxy
operator|&
name|Arg
argument_list|)
operator|:
name|MAM
argument_list|(
argument|Arg.MAM
argument_list|)
block|{}
name|ModuleAnalysisManagerFunctionProxy
argument_list|(
name|ModuleAnalysisManagerFunctionProxy
operator|&&
name|Arg
argument_list|)
operator|:
name|MAM
argument_list|(
argument|std::move(Arg.MAM)
argument_list|)
block|{}
name|ModuleAnalysisManagerFunctionProxy
operator|&
name|operator
operator|=
operator|(
name|ModuleAnalysisManagerFunctionProxy
name|RHS
operator|)
block|{
name|std
operator|::
name|swap
argument_list|(
name|MAM
argument_list|,
name|RHS
operator|.
name|MAM
argument_list|)
block|;
return|return
operator|*
name|this
return|;
block|}
comment|/// \brief Run the analysis pass and create our proxy result object.
comment|/// Nothing to see here, it just forwards the \c MAM reference into the
comment|/// result.
name|Result
name|run
parameter_list|(
name|Function
modifier|*
parameter_list|)
block|{
return|return
name|Result
argument_list|(
operator|*
name|MAM
argument_list|)
return|;
block|}
name|private
label|:
specifier|static
name|char
name|PassID
decl_stmt|;
specifier|const
name|ModuleAnalysisManager
modifier|*
name|MAM
decl_stmt|;
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
comment|/// \brief Trivial adaptor that maps from a module to its functions.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// Designed to allow composition of a FunctionPass(Manager) and
end_comment

begin_comment
comment|/// a ModulePassManager. Note that if this pass is constructed with a pointer
end_comment

begin_comment
comment|/// to a \c ModuleAnalysisManager it will run the
end_comment

begin_comment
comment|/// \c FunctionAnalysisManagerModuleProxy analysis prior to running the function
end_comment

begin_comment
comment|/// pass over the module to enable a \c FunctionAnalysisManager to be used
end_comment

begin_comment
comment|/// within this run safely.
end_comment

begin_expr_stmt
name|template
operator|<
name|typename
name|FunctionPassT
operator|>
name|class
name|ModuleToFunctionPassAdaptor
block|{
name|public
operator|:
name|explicit
name|ModuleToFunctionPassAdaptor
argument_list|(
argument|FunctionPassT Pass
argument_list|)
operator|:
name|Pass
argument_list|(
argument|std::move(Pass)
argument_list|)
block|{}
comment|// We have to explicitly define all the special member functions because MSVC
comment|// refuses to generate them.
name|ModuleToFunctionPassAdaptor
argument_list|(
specifier|const
name|ModuleToFunctionPassAdaptor
operator|&
name|Arg
argument_list|)
operator|:
name|Pass
argument_list|(
argument|Arg.Pass
argument_list|)
block|{}
name|ModuleToFunctionPassAdaptor
argument_list|(
name|ModuleToFunctionPassAdaptor
operator|&&
name|Arg
argument_list|)
operator|:
name|Pass
argument_list|(
argument|std::move(Arg.Pass)
argument_list|)
block|{}
name|friend
name|void
name|swap
argument_list|(
argument|ModuleToFunctionPassAdaptor&LHS
argument_list|,
argument|ModuleToFunctionPassAdaptor&RHS
argument_list|)
block|{
name|using
name|std
operator|::
name|swap
block|;
name|swap
argument_list|(
name|LHS
operator|.
name|Pass
argument_list|,
name|RHS
operator|.
name|Pass
argument_list|)
block|;   }
name|ModuleToFunctionPassAdaptor
operator|&
name|operator
operator|=
operator|(
name|ModuleToFunctionPassAdaptor
name|RHS
operator|)
block|{
name|swap
argument_list|(
operator|*
name|this
argument_list|,
name|RHS
argument_list|)
block|;
return|return
operator|*
name|this
return|;
block|}
comment|/// \brief Runs the function pass across every function in the module.
name|PreservedAnalyses
name|run
argument_list|(
argument|Module *M
argument_list|,
argument|ModuleAnalysisManager *AM
argument_list|)
block|{
name|FunctionAnalysisManager
operator|*
name|FAM
operator|=
name|nullptr
block|;
if|if
condition|(
name|AM
condition|)
comment|// Setup the function analysis manager from its proxy.
name|FAM
operator|=
operator|&
name|AM
operator|->
name|getResult
operator|<
name|FunctionAnalysisManagerModuleProxy
operator|>
operator|(
name|M
operator|)
operator|.
name|getManager
argument_list|()
expr_stmt|;
name|PreservedAnalyses
name|PA
operator|=
name|PreservedAnalyses
operator|::
name|all
argument_list|()
expr_stmt|;
end_expr_stmt

begin_for
for|for
control|(
name|Module
operator|::
name|iterator
name|I
operator|=
name|M
operator|->
name|begin
argument_list|()
operator|,
name|E
operator|=
name|M
operator|->
name|end
argument_list|()
init|;
name|I
operator|!=
name|E
condition|;
operator|++
name|I
control|)
block|{
name|PreservedAnalyses
name|PassPA
init|=
name|Pass
operator|.
name|run
argument_list|(
name|I
argument_list|,
name|FAM
argument_list|)
decl_stmt|;
comment|// We know that the function pass couldn't have invalidated any other
comment|// function's analyses (that's the contract of a function pass), so
comment|// directly handle the function analysis manager's invalidation here.
if|if
condition|(
name|FAM
condition|)
name|FAM
operator|->
name|invalidate
argument_list|(
name|I
argument_list|,
name|PassPA
argument_list|)
expr_stmt|;
comment|// Then intersect the preserved set so that invalidation of module
comment|// analyses will eventually occur when the module pass completes.
name|PA
operator|.
name|intersect
argument_list|(
name|std
operator|::
name|move
argument_list|(
name|PassPA
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_for

begin_comment
comment|// By definition we preserve the proxy. This precludes *any* invalidation
end_comment

begin_comment
comment|// of function analyses by the proxy, but that's OK because we've taken
end_comment

begin_comment
comment|// care to invalidate analyses in the function analysis manager
end_comment

begin_comment
comment|// incrementally above.
end_comment

begin_expr_stmt
name|PA
operator|.
name|preserve
operator|<
name|FunctionAnalysisManagerModuleProxy
operator|>
operator|(
operator|)
expr_stmt|;
end_expr_stmt

begin_return
return|return
name|PA
return|;
end_return

begin_function
unit|}    static
name|StringRef
name|name
parameter_list|()
block|{
return|return
literal|"ModuleToFunctionPassAdaptor"
return|;
block|}
end_function

begin_label
name|private
label|:
end_label

begin_decl_stmt
name|FunctionPassT
name|Pass
decl_stmt|;
end_decl_stmt

begin_comment
unit|};
comment|/// \brief A function to deduce a function pass type and wrap it in the
end_comment

begin_comment
comment|/// templated adaptor.
end_comment

begin_expr_stmt
name|template
operator|<
name|typename
name|FunctionPassT
operator|>
name|ModuleToFunctionPassAdaptor
operator|<
name|FunctionPassT
operator|>
name|createModuleToFunctionPassAdaptor
argument_list|(
argument|FunctionPassT Pass
argument_list|)
block|{
return|return
name|std
operator|::
name|move
argument_list|(
name|ModuleToFunctionPassAdaptor
operator|<
name|FunctionPassT
operator|>
operator|(
name|std
operator|::
name|move
argument_list|(
name|Pass
argument_list|)
operator|)
argument_list|)
return|;
block|}
end_expr_stmt

begin_endif
unit|}
endif|#
directive|endif
end_endif

end_unit

