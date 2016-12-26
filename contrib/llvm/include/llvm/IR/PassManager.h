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
name|LLVM_IR_PASSMANAGER_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_IR_PASSMANAGER_H
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
file|"llvm/IR/PassManagerInternal.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/Debug.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/TypeName.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/raw_ostream.h"
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
name|preserve
argument_list|(
name|PassT
operator|::
name|ID
argument_list|()
argument_list|)
block|; }
comment|/// \brief Mark an abstract PassID as preserved, adding it to the set.
name|void
name|preserve
argument_list|(
argument|void *PassID
argument_list|)
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
name|PassID
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
name|void
modifier|*
name|P
range|:
name|PreservedPassIDs
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
name|P
argument_list|)
condition|)
name|PreservedPassIDs
operator|.
name|erase
argument_list|(
name|P
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
name|void
modifier|*
name|P
range|:
name|PreservedPassIDs
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
name|P
argument_list|)
condition|)
name|PreservedPassIDs
operator|.
name|erase
argument_list|(
name|P
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
comment|/// \brief Query whether all of the analyses in the set are preserved.
name|bool
name|preserved
parameter_list|(
name|PreservedAnalyses
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
return|return
name|areAllPreserved
argument_list|()
return|;
for|for
control|(
name|void
modifier|*
name|P
range|:
name|Arg
operator|.
name|PreservedPassIDs
control|)
if|if
condition|(
operator|!
name|preserved
argument_list|(
name|P
argument_list|)
condition|)
return|return
name|false
return|;
return|return
name|true
return|;
block|}
comment|/// \brief Test whether all passes are preserved.
comment|///
comment|/// This is used primarily to optimize for the case of no changes which will
comment|/// common in many scenarios.
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
comment|// Forward declare the analysis manager template.
name|template
operator|<
name|typename
name|IRUnitT
operator|>
name|class
name|AnalysisManager
expr_stmt|;
comment|/// A CRTP mix-in to automatically provide informational APIs needed for
comment|/// passes.
comment|///
comment|/// This provides some boiler plate for types that are passes.
name|template
operator|<
name|typename
name|DerivedT
operator|>
expr|struct
name|PassInfoMixin
block|{
comment|/// Returns the name of the derived pass type.
specifier|static
name|StringRef
name|name
argument_list|()
block|{
name|StringRef
name|Name
operator|=
name|getTypeName
operator|<
name|DerivedT
operator|>
operator|(
operator|)
block|;
if|if
condition|(
name|Name
operator|.
name|startswith
argument_list|(
literal|"llvm::"
argument_list|)
condition|)
name|Name
operator|=
name|Name
operator|.
name|drop_front
argument_list|(
name|strlen
argument_list|(
literal|"llvm::"
argument_list|)
argument_list|)
expr_stmt|;
return|return
name|Name
return|;
block|}
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
comment|/// A CRTP mix-in to automatically provide informational APIs needed for
end_comment

begin_comment
comment|/// analysis passes.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This provides some boiler plate for types that are analysis passes. It
end_comment

begin_comment
comment|/// automatically mixes in \c PassInfoMixin and adds informational APIs
end_comment

begin_comment
comment|/// specifically used for analyses.
end_comment

begin_expr_stmt
name|template
operator|<
name|typename
name|DerivedT
operator|>
expr|struct
name|AnalysisInfoMixin
operator|:
name|PassInfoMixin
operator|<
name|DerivedT
operator|>
block|{
comment|/// Returns an opaque, unique ID for this pass type.
comment|///
comment|/// Note that this requires the derived type provide a static member whose
comment|/// address can be converted to a void pointer.
comment|///
comment|/// FIXME: The only reason the derived type needs to provide this rather than
comment|/// this mixin providing it is due to broken implementations which cannot
comment|/// correctly unique a templated static so that they have the same addresses
comment|/// for each instantiation and are definitively emitted once for each
comment|/// instantiation. The only currently known platform with this limitation are
comment|/// Windows DLL builds, specifically building each part of LLVM as a DLL. If
comment|/// we ever remove that build configuration, this mixin can provide the
comment|/// static PassID as well.
specifier|static
name|void
operator|*
name|ID
argument_list|()
block|{
return|return
operator|(
name|void
operator|*
operator|)
operator|&
name|DerivedT
operator|::
name|PassID
return|;
block|}
end_expr_stmt

begin_comment
unit|};
comment|/// \brief Manages a sequence of passes over units of IR.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// A pass manager contains a sequence of passes to run over units of IR. It is
end_comment

begin_comment
comment|/// itself a valid pass over that unit of IR, and when over some given IR will
end_comment

begin_comment
comment|/// run each pass in sequence. This is the primary and most basic building
end_comment

begin_comment
comment|/// block of a pass pipeline.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// If it is run with an \c AnalysisManager<IRUnitT> argument, it will propagate
end_comment

begin_comment
comment|/// that analysis manager to each pass it runs, as well as calling the analysis
end_comment

begin_comment
comment|/// manager's invalidation routine with the PreservedAnalyses of each pass it
end_comment

begin_comment
comment|/// runs.
end_comment

begin_expr_stmt
name|template
operator|<
name|typename
name|IRUnitT
operator|>
name|class
name|PassManager
operator|:
name|public
name|PassInfoMixin
operator|<
name|PassManager
operator|<
name|IRUnitT
operator|>>
block|{
name|public
operator|:
comment|/// \brief Construct a pass manager.
comment|///
comment|/// It can be passed a flag to get debug logging as the passes are run.
name|PassManager
argument_list|(
argument|bool DebugLogging = false
argument_list|)
operator|:
name|DebugLogging
argument_list|(
argument|DebugLogging
argument_list|)
block|{}
comment|// We have to explicitly define all the special member functions because MSVC
comment|// refuses to generate them.
name|PassManager
argument_list|(
name|PassManager
operator|&&
name|Arg
argument_list|)
operator|:
name|Passes
argument_list|(
name|std
operator|::
name|move
argument_list|(
name|Arg
operator|.
name|Passes
argument_list|)
argument_list|)
block|,
name|DebugLogging
argument_list|(
argument|std::move(Arg.DebugLogging)
argument_list|)
block|{}
name|PassManager
operator|&
name|operator
operator|=
operator|(
name|PassManager
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
name|DebugLogging
operator|=
name|std
operator|::
name|move
argument_list|(
name|RHS
operator|.
name|DebugLogging
argument_list|)
block|;
return|return
operator|*
name|this
return|;
block|}
comment|/// \brief Run all of the passes in this manager over the IR.
name|PreservedAnalyses
name|run
argument_list|(
argument|IRUnitT&IR
argument_list|,
argument|AnalysisManager<IRUnitT>&AM
argument_list|)
block|{
name|PreservedAnalyses
name|PA
operator|=
name|PreservedAnalyses
operator|::
name|all
argument_list|()
block|;
if|if
condition|(
name|DebugLogging
condition|)
name|dbgs
argument_list|()
operator|<<
literal|"Starting "
operator|<<
name|getTypeName
operator|<
name|IRUnitT
operator|>
operator|(
operator|)
operator|<<
literal|" pass manager run.\n"
expr_stmt|;
end_expr_stmt

begin_for
for|for
control|(
name|unsigned
name|Idx
init|=
literal|0
init|,
name|Size
init|=
name|Passes
operator|.
name|size
argument_list|()
init|;
name|Idx
operator|!=
name|Size
condition|;
operator|++
name|Idx
control|)
block|{
if|if
condition|(
name|DebugLogging
condition|)
name|dbgs
argument_list|()
operator|<<
literal|"Running pass: "
operator|<<
name|Passes
index|[
name|Idx
index|]
operator|->
name|name
argument_list|()
operator|<<
literal|" on "
operator|<<
name|IR
operator|.
name|getName
argument_list|()
operator|<<
literal|"\n"
expr_stmt|;
name|PreservedAnalyses
name|PassPA
init|=
name|Passes
index|[
name|Idx
index|]
operator|->
name|run
argument_list|(
name|IR
argument_list|,
name|AM
argument_list|)
decl_stmt|;
comment|// Update the analysis manager as each pass runs and potentially
comment|// invalidates analyses. We also update the preserved set of analyses
comment|// based on what analyses we have already handled the invalidation for
comment|// here and don't need to invalidate when finished.
name|PassPA
operator|=
name|AM
operator|.
name|invalidate
argument_list|(
name|IR
argument_list|,
name|std
operator|::
name|move
argument_list|(
name|PassPA
argument_list|)
argument_list|)
expr_stmt|;
comment|// Finally, we intersect the final preserved analyses to compute the
comment|// aggregate preserved set for this pass manager.
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
comment|// FIXME: Historically, the pass managers all called the LLVM context's
comment|// yield function here. We don't have a generic way to acquire the
comment|// context and it isn't yet clear what the right pattern is for yielding
comment|// in the new pass manager so it is currently omitted.
comment|//IR.getContext().yield();
block|}
end_for

begin_if
if|if
condition|(
name|DebugLogging
condition|)
name|dbgs
argument_list|()
operator|<<
literal|"Finished "
operator|<<
name|getTypeName
operator|<
name|IRUnitT
operator|>
operator|(
operator|)
operator|<<
literal|" pass manager run.\n"
expr_stmt|;
end_if

begin_return
return|return
name|PA
return|;
end_return

begin_expr_stmt
unit|}    template
operator|<
name|typename
name|PassT
operator|>
name|void
name|addPass
argument_list|(
argument|PassT Pass
argument_list|)
block|{
typedef|typedef
name|detail
operator|::
name|PassModel
operator|<
name|IRUnitT
operator|,
name|PassT
operator|>
name|PassModelT
expr_stmt|;
name|Passes
operator|.
name|emplace_back
argument_list|(
argument|new PassModelT(std::move(Pass))
argument_list|)
expr_stmt|;
end_expr_stmt

begin_typedef
unit|}  private:
typedef|typedef
name|detail
operator|::
name|PassConcept
operator|<
name|IRUnitT
operator|>
name|PassConceptT
expr_stmt|;
end_typedef

begin_expr_stmt
name|PassManager
argument_list|(
specifier|const
name|PassManager
operator|&
argument_list|)
operator|=
name|delete
expr_stmt|;
end_expr_stmt

begin_decl_stmt
name|PassManager
modifier|&
name|operator
init|=
operator|(
specifier|const
name|PassManager
operator|&
operator|)
operator|=
name|delete
decl_stmt|;
end_decl_stmt

begin_expr_stmt
name|std
operator|::
name|vector
operator|<
name|std
operator|::
name|unique_ptr
operator|<
name|PassConceptT
operator|>>
name|Passes
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// \brief Flag indicating whether we should do debug logging.
end_comment

begin_decl_stmt
name|bool
name|DebugLogging
decl_stmt|;
end_decl_stmt

begin_extern
unit|};
extern|extern template class PassManager<Module>;
end_extern

begin_comment
comment|/// \brief Convenience typedef for a pass manager over modules.
end_comment

begin_typedef
typedef|typedef
name|PassManager
operator|<
name|Module
operator|>
name|ModulePassManager
expr_stmt|;
end_typedef

begin_extern
extern|extern template class PassManager<Function>;
end_extern

begin_comment
comment|/// \brief Convenience typedef for a pass manager over functions.
end_comment

begin_typedef
typedef|typedef
name|PassManager
operator|<
name|Function
operator|>
name|FunctionPassManager
expr_stmt|;
end_typedef

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
comment|///
comment|/// Note that there is also a generic analysis manager template which implements
comment|/// the above required functions along with common datastructures used for
comment|/// managing analyses. This base class is factored so that if you need to
comment|/// customize the handling of a specific IR unit, you can do so without
comment|/// replicating *all* of the boilerplate.
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
specifier|const
name|AnalysisManagerBase
operator|&
argument_list|)
operator|=
name|delete
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
operator|=
name|delete
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
argument|IRUnitT&IR
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
argument|IRUnitT&IR
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
comment|/// The argument is a callable whose result is a pass. This allows passing in
end_comment

begin_comment
comment|/// a lambda to construct the pass.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// The pass type registered is the result type of calling the argument. If
end_comment

begin_comment
comment|/// that pass has already been registered, then the argument will not be
end_comment

begin_comment
comment|/// called and this function will return false. Otherwise, the pass type
end_comment

begin_comment
comment|/// becomes registered, with the instance provided by calling the argument
end_comment

begin_comment
comment|/// once, and this function returns true.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// While this returns whether or not the pass type was already registered,
end_comment

begin_comment
comment|/// there in't an independent way to query that as that would be prone to
end_comment

begin_comment
comment|/// risky use when *querying* the analysis manager. Instead, the only
end_comment

begin_comment
comment|/// supported use case is avoiding duplicate registry of an analysis. This
end_comment

begin_comment
comment|/// interface also lends itself to minimizing the number of times we have to
end_comment

begin_comment
comment|/// do lookups for analyses or construct complex passes only to throw them
end_comment

begin_comment
comment|/// away.
end_comment

begin_expr_stmt
unit|template
operator|<
name|typename
name|PassBuilderT
operator|>
name|bool
name|registerPass
argument_list|(
argument|PassBuilderT PassBuilder
argument_list|)
block|{
typedef|typedef
name|decltype
argument_list|(
argument|PassBuilder()
argument_list|)
name|PassT
expr_stmt|;
end_expr_stmt

begin_typedef
typedef|typedef
name|detail
operator|::
name|AnalysisPassModel
operator|<
name|IRUnitT
operator|,
name|PassT
operator|>
name|PassModelT
expr_stmt|;
end_typedef

begin_expr_stmt
name|auto
operator|&
name|PassPtr
operator|=
name|AnalysisPasses
index|[
name|PassT
operator|::
name|ID
argument_list|()
index|]
expr_stmt|;
end_expr_stmt

begin_if
if|if
condition|(
name|PassPtr
condition|)
comment|// Already registered this pass type!
return|return
name|false
return|;
end_if

begin_comment
comment|// Construct a new model around the instance returned by the builder.
end_comment

begin_macro
name|PassPtr
end_macro

begin_expr_stmt
operator|.
name|reset
argument_list|(
argument|new PassModelT(PassBuilder())
argument_list|)
expr_stmt|;
end_expr_stmt

begin_return
return|return
name|true
return|;
end_return

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
argument|IRUnitT&IR
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
name|IR
argument_list|)
block|;   }
comment|/// \brief Invalidate analyses cached for an IR unit.
comment|///
comment|/// Walk through all of the analyses pertaining to this unit of IR and
comment|/// invalidate them unless they are preserved by the PreservedAnalyses set.
comment|/// We accept the PreservedAnalyses set by value and update it with each
comment|/// analyis pass which has been successfully invalidated and thus can be
comment|/// preserved going forward. The updated set is returned.
name|PreservedAnalyses
name|invalidate
argument_list|(
argument|IRUnitT&IR
argument_list|,
argument|PreservedAnalyses PA
argument_list|)
block|{
return|return
name|derived_this
argument_list|()
operator|->
name|invalidateImpl
argument_list|(
name|IR
argument_list|,
name|std
operator|::
name|move
argument_list|(
name|PA
argument_list|)
argument_list|)
return|;
block|}
end_expr_stmt

begin_label
name|protected
label|:
end_label

begin_comment
comment|/// \brief Lookup a registered analysis pass.
end_comment

begin_function
name|PassConceptT
modifier|&
name|lookupPass
parameter_list|(
name|void
modifier|*
name|PassID
parameter_list|)
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
end_function

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
comment|/// \brief A generic analysis pass manager with lazy running and caching of
end_comment

begin_comment
comment|/// results.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This analysis manager can be used for any IR unit where the address of the
end_comment

begin_comment
comment|/// IR unit sufficies as its identity. It manages the cache for a unit of IR via
end_comment

begin_comment
comment|/// the address of each unit of IR cached.
end_comment

begin_expr_stmt
unit|template
operator|<
name|typename
name|IRUnitT
operator|>
name|class
name|AnalysisManager
operator|:
name|public
name|detail
operator|::
name|AnalysisManagerBase
operator|<
name|AnalysisManager
operator|<
name|IRUnitT
operator|>
operator|,
name|IRUnitT
operator|>
block|{
name|friend
name|class
name|detail
operator|::
name|AnalysisManagerBase
operator|<
name|AnalysisManager
operator|<
name|IRUnitT
operator|>
block|,
name|IRUnitT
operator|>
block|;
typedef|typedef
name|detail
operator|::
name|AnalysisManagerBase
operator|<
name|AnalysisManager
operator|<
name|IRUnitT
operator|>
operator|,
name|IRUnitT
operator|>
name|BaseT
expr_stmt|;
end_expr_stmt

begin_typedef
typedef|typedef
name|typename
name|BaseT
operator|::
name|ResultConceptT
name|ResultConceptT
expr_stmt|;
end_typedef

begin_typedef
typedef|typedef
name|typename
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
comment|// Most public APIs are inherited from the CRTP base class.
end_comment

begin_comment
comment|/// \brief Construct an empty analysis manager.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// A flag can be passed to indicate that the manager should perform debug
end_comment

begin_comment
comment|/// logging.
end_comment

begin_macro
name|AnalysisManager
argument_list|(
argument|bool DebugLogging = false
argument_list|)
end_macro

begin_macro
unit|:
name|DebugLogging
argument_list|(
argument|DebugLogging
argument_list|)
end_macro

begin_block
block|{}
end_block

begin_comment
comment|// We have to explicitly define all the special member functions because MSVC
end_comment

begin_comment
comment|// refuses to generate them.
end_comment

begin_expr_stmt
name|AnalysisManager
argument_list|(
name|AnalysisManager
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
name|AnalysisResults
argument_list|(
name|std
operator|::
name|move
argument_list|(
name|Arg
operator|.
name|AnalysisResults
argument_list|)
argument_list|)
operator|,
name|DebugLogging
argument_list|(
argument|std::move(Arg.DebugLogging)
argument_list|)
block|{}
name|AnalysisManager
operator|&
name|operator
operator|=
operator|(
name|AnalysisManager
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
name|AnalysisResults
operator|=
name|std
operator|::
name|move
argument_list|(
name|RHS
operator|.
name|AnalysisResults
argument_list|)
block|;
name|DebugLogging
operator|=
name|std
operator|::
name|move
argument_list|(
name|RHS
operator|.
name|DebugLogging
argument_list|)
block|;
return|return
operator|*
name|this
return|;
block|}
end_expr_stmt

begin_comment
comment|/// \brief Returns true if the analysis manager has an empty results cache.
end_comment

begin_expr_stmt
name|bool
name|empty
argument_list|()
specifier|const
block|{
name|assert
argument_list|(
name|AnalysisResults
operator|.
name|empty
argument_list|()
operator|==
name|AnalysisResultLists
operator|.
name|empty
argument_list|()
operator|&&
literal|"The storage and index of analysis results disagree on how many "
literal|"there are!"
argument_list|)
block|;
return|return
name|AnalysisResults
operator|.
name|empty
argument_list|()
return|;
block|}
end_expr_stmt

begin_comment
comment|/// \brief Clear the analysis result cache.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This routine allows cleaning up when the set of IR units itself has
end_comment

begin_comment
comment|/// potentially changed, and thus we can't even look up a a result and
end_comment

begin_comment
comment|/// invalidate it directly. Notably, this does *not* call invalidate functions
end_comment

begin_comment
comment|/// as there is nothing to be done for them.
end_comment

begin_function
name|void
name|clear
parameter_list|()
block|{
name|AnalysisResults
operator|.
name|clear
argument_list|()
expr_stmt|;
name|AnalysisResultLists
operator|.
name|clear
argument_list|()
expr_stmt|;
block|}
end_function

begin_label
name|private
label|:
end_label

begin_expr_stmt
name|AnalysisManager
argument_list|(
specifier|const
name|AnalysisManager
operator|&
argument_list|)
operator|=
name|delete
expr_stmt|;
end_expr_stmt

begin_decl_stmt
name|AnalysisManager
modifier|&
name|operator
init|=
operator|(
specifier|const
name|AnalysisManager
operator|&
operator|)
operator|=
name|delete
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// \brief Get an analysis result, running the pass if necessary.
end_comment

begin_function
name|ResultConceptT
modifier|&
name|getResultImpl
parameter_list|(
name|void
modifier|*
name|PassID
parameter_list|,
name|IRUnitT
modifier|&
name|IR
parameter_list|)
block|{
name|typename
name|AnalysisResultMapT
operator|::
name|iterator
name|RI
expr_stmt|;
name|bool
name|Inserted
decl_stmt|;
name|std
operator|::
name|tie
argument_list|(
name|RI
argument_list|,
name|Inserted
argument_list|)
operator|=
name|AnalysisResults
operator|.
name|insert
argument_list|(
name|std
operator|::
name|make_pair
argument_list|(
argument|std::make_pair(PassID,&IR)
argument_list|,
argument|typename AnalysisResultListT::iterator()
argument_list|)
argument_list|)
expr_stmt|;
comment|// If we don't have a cached result for this function, look up the pass and
comment|// run it to produce a result, which we then add to the cache.
if|if
condition|(
name|Inserted
condition|)
block|{
name|auto
operator|&
name|P
operator|=
name|this
operator|->
name|lookupPass
argument_list|(
name|PassID
argument_list|)
expr_stmt|;
if|if
condition|(
name|DebugLogging
condition|)
name|dbgs
argument_list|()
operator|<<
literal|"Running analysis: "
operator|<<
name|P
operator|.
name|name
argument_list|()
operator|<<
literal|"\n"
expr_stmt|;
name|AnalysisResultListT
modifier|&
name|ResultList
init|=
name|AnalysisResultLists
index|[
operator|&
name|IR
index|]
decl_stmt|;
name|ResultList
operator|.
name|emplace_back
argument_list|(
name|PassID
argument_list|,
name|P
operator|.
name|run
argument_list|(
name|IR
argument_list|,
operator|*
name|this
argument_list|)
argument_list|)
expr_stmt|;
comment|// P.run may have inserted elements into AnalysisResults and invalidated
comment|// RI.
name|RI
operator|=
name|AnalysisResults
operator|.
name|find
argument_list|(
name|std
operator|::
name|make_pair
argument_list|(
name|PassID
argument_list|,
operator|&
name|IR
argument_list|)
argument_list|)
expr_stmt|;
name|assert
argument_list|(
name|RI
operator|!=
name|AnalysisResults
operator|.
name|end
argument_list|()
operator|&&
literal|"we just inserted it!"
argument_list|)
expr_stmt|;
name|RI
operator|->
name|second
operator|=
name|std
operator|::
name|prev
argument_list|(
name|ResultList
operator|.
name|end
argument_list|()
argument_list|)
expr_stmt|;
block|}
return|return
operator|*
name|RI
operator|->
name|second
operator|->
name|second
return|;
block|}
end_function

begin_comment
comment|/// \brief Get a cached analysis result or return null.
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
name|IRUnitT
operator|&
name|IR
argument_list|)
decl|const
block|{
name|typename
name|AnalysisResultMapT
operator|::
name|const_iterator
name|RI
operator|=
name|AnalysisResults
operator|.
name|find
argument_list|(
name|std
operator|::
name|make_pair
argument_list|(
name|PassID
argument_list|,
operator|&
name|IR
argument_list|)
argument_list|)
expr_stmt|;
return|return
name|RI
operator|==
name|AnalysisResults
operator|.
name|end
argument_list|()
condition|?
name|nullptr
else|:
operator|&
operator|*
name|RI
operator|->
name|second
operator|->
name|second
return|;
block|}
end_decl_stmt

begin_comment
comment|/// \brief Invalidate a function pass result.
end_comment

begin_function
name|void
name|invalidateImpl
parameter_list|(
name|void
modifier|*
name|PassID
parameter_list|,
name|IRUnitT
modifier|&
name|IR
parameter_list|)
block|{
name|typename
name|AnalysisResultMapT
operator|::
name|iterator
name|RI
operator|=
name|AnalysisResults
operator|.
name|find
argument_list|(
name|std
operator|::
name|make_pair
argument_list|(
name|PassID
argument_list|,
operator|&
name|IR
argument_list|)
argument_list|)
expr_stmt|;
if|if
condition|(
name|RI
operator|==
name|AnalysisResults
operator|.
name|end
argument_list|()
condition|)
return|return;
if|if
condition|(
name|DebugLogging
condition|)
name|dbgs
argument_list|()
operator|<<
literal|"Invalidating analysis: "
operator|<<
name|this
operator|->
name|lookupPass
argument_list|(
name|PassID
argument_list|)
operator|.
name|name
argument_list|()
operator|<<
literal|"\n"
expr_stmt|;
name|AnalysisResultLists
index|[
operator|&
name|IR
index|]
operator|.
name|erase
argument_list|(
name|RI
operator|->
name|second
argument_list|)
expr_stmt|;
name|AnalysisResults
operator|.
name|erase
argument_list|(
name|RI
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|/// \brief Invalidate the results for a function..
end_comment

begin_function
name|PreservedAnalyses
name|invalidateImpl
parameter_list|(
name|IRUnitT
modifier|&
name|IR
parameter_list|,
name|PreservedAnalyses
name|PA
parameter_list|)
block|{
comment|// Short circuit for a common case of all analyses being preserved.
if|if
condition|(
name|PA
operator|.
name|areAllPreserved
argument_list|()
condition|)
return|return
name|PA
return|;
if|if
condition|(
name|DebugLogging
condition|)
name|dbgs
argument_list|()
operator|<<
literal|"Invalidating all non-preserved analyses for: "
operator|<<
name|IR
operator|.
name|getName
argument_list|()
operator|<<
literal|"\n"
expr_stmt|;
comment|// Clear all the invalidated results associated specifically with this
comment|// function.
name|SmallVector
operator|<
name|void
operator|*
operator|,
literal|8
operator|>
name|InvalidatedPassIDs
expr_stmt|;
name|AnalysisResultListT
modifier|&
name|ResultsList
init|=
name|AnalysisResultLists
index|[
operator|&
name|IR
index|]
decl_stmt|;
for|for
control|(
name|typename
name|AnalysisResultListT
operator|::
name|iterator
name|I
operator|=
name|ResultsList
operator|.
name|begin
argument_list|()
operator|,
name|E
operator|=
name|ResultsList
operator|.
name|end
argument_list|()
init|;
name|I
operator|!=
name|E
condition|;
control|)
block|{
name|void
modifier|*
name|PassID
init|=
name|I
operator|->
name|first
decl_stmt|;
comment|// Pass the invalidation down to the pass itself to see if it thinks it is
comment|// necessary. The analysis pass can return false if no action on the part
comment|// of the analysis manager is required for this invalidation event.
if|if
condition|(
name|I
operator|->
name|second
operator|->
name|invalidate
argument_list|(
name|IR
argument_list|,
name|PA
argument_list|)
condition|)
block|{
if|if
condition|(
name|DebugLogging
condition|)
name|dbgs
argument_list|()
operator|<<
literal|"Invalidating analysis: "
operator|<<
name|this
operator|->
name|lookupPass
argument_list|(
name|PassID
argument_list|)
operator|.
name|name
argument_list|()
operator|<<
literal|"\n"
expr_stmt|;
name|InvalidatedPassIDs
operator|.
name|push_back
argument_list|(
name|I
operator|->
name|first
argument_list|)
expr_stmt|;
name|I
operator|=
name|ResultsList
operator|.
name|erase
argument_list|(
name|I
argument_list|)
expr_stmt|;
block|}
else|else
block|{
operator|++
name|I
expr_stmt|;
block|}
comment|// After handling each pass, we mark it as preserved. Once we've
comment|// invalidated any stale results, the rest of the system is allowed to
comment|// start preserving this analysis again.
name|PA
operator|.
name|preserve
argument_list|(
name|PassID
argument_list|)
expr_stmt|;
block|}
while|while
condition|(
operator|!
name|InvalidatedPassIDs
operator|.
name|empty
argument_list|()
condition|)
name|AnalysisResults
operator|.
name|erase
argument_list|(
name|std
operator|::
name|make_pair
argument_list|(
name|InvalidatedPassIDs
operator|.
name|pop_back_val
argument_list|()
argument_list|,
operator|&
name|IR
argument_list|)
argument_list|)
expr_stmt|;
if|if
condition|(
name|ResultsList
operator|.
name|empty
argument_list|()
condition|)
name|AnalysisResultLists
operator|.
name|erase
argument_list|(
operator|&
name|IR
argument_list|)
expr_stmt|;
return|return
name|PA
return|;
block|}
end_function

begin_comment
comment|/// \brief List of function analysis pass IDs and associated concept pointers.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// Requires iterators to be valid across appending new entries and arbitrary
end_comment

begin_comment
comment|/// erases. Provides both the pass ID and concept pointer such that it is
end_comment

begin_comment
comment|/// half of a bijection and provides storage for the actual result concept.
end_comment

begin_typedef
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
name|IRUnitT
operator|>>>
operator|>
name|AnalysisResultListT
expr_stmt|;
end_typedef

begin_comment
comment|/// \brief Map type from function pointer to our custom list type.
end_comment

begin_typedef
typedef|typedef
name|DenseMap
operator|<
name|IRUnitT
operator|*
operator|,
name|AnalysisResultListT
operator|>
name|AnalysisResultListMapT
expr_stmt|;
end_typedef

begin_comment
comment|/// \brief Map from function to a list of function analysis results.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// Provides linear time removal of all analysis results for a function and
end_comment

begin_comment
comment|/// the ultimate storage for a particular cached analysis result.
end_comment

begin_decl_stmt
name|AnalysisResultListMapT
name|AnalysisResultLists
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// \brief Map type from a pair of analysis ID and function pointer to an
end_comment

begin_comment
comment|/// iterator into a particular result list.
end_comment

begin_typedef
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
name|IRUnitT
operator|*
operator|>
operator|,
name|typename
name|AnalysisResultListT
operator|::
name|iterator
operator|>
name|AnalysisResultMapT
expr_stmt|;
end_typedef

begin_comment
comment|/// \brief Map from an analysis ID and function to a particular cached
end_comment

begin_comment
comment|/// analysis result.
end_comment

begin_decl_stmt
name|AnalysisResultMapT
name|AnalysisResults
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// \brief A flag indicating whether debug logging is enabled.
end_comment

begin_decl_stmt
name|bool
name|DebugLogging
decl_stmt|;
end_decl_stmt

begin_extern
unit|};
extern|extern template class AnalysisManager<Module>;
end_extern

begin_comment
comment|/// \brief Convenience typedef for the Module analysis manager.
end_comment

begin_typedef
typedef|typedef
name|AnalysisManager
operator|<
name|Module
operator|>
name|ModuleAnalysisManager
expr_stmt|;
end_typedef

begin_extern
extern|extern template class AnalysisManager<Function>;
end_extern

begin_comment
comment|/// \brief Convenience typedef for the Function analysis manager.
end_comment

begin_typedef
typedef|typedef
name|AnalysisManager
operator|<
name|Function
operator|>
name|FunctionAnalysisManager
expr_stmt|;
end_typedef

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

begin_comment
comment|///
end_comment

begin_comment
comment|/// Note that the proxy's result is a move-only object and represents ownership
end_comment

begin_comment
comment|/// of the validity of the analyses in the \c FunctionAnalysisManager it
end_comment

begin_comment
comment|/// provides.
end_comment

begin_expr_stmt
name|template
operator|<
name|typename
name|AnalysisManagerT
operator|,
name|typename
name|IRUnitT
operator|>
name|class
name|InnerAnalysisManagerProxy
operator|:
name|public
name|AnalysisInfoMixin
operator|<
name|InnerAnalysisManagerProxy
operator|<
name|AnalysisManagerT
operator|,
name|IRUnitT
operator|>>
block|{
name|public
operator|:
name|class
name|Result
block|{
name|public
operator|:
name|explicit
name|Result
argument_list|(
name|AnalysisManagerT
operator|&
name|AM
argument_list|)
operator|:
name|AM
argument_list|(
argument|&AM
argument_list|)
block|{}
name|Result
argument_list|(
name|Result
operator|&&
name|Arg
argument_list|)
operator|:
name|AM
argument_list|(
argument|std::move(Arg.AM)
argument_list|)
block|{
comment|// We have to null out the analysis manager in the moved-from state
comment|// because we are taking ownership of the responsibilty to clear the
comment|// analysis state.
name|Arg
operator|.
name|AM
operator|=
name|nullptr
block|;     }
name|Result
operator|&
name|operator
operator|=
operator|(
name|Result
operator|&&
name|RHS
operator|)
block|{
name|AM
operator|=
name|RHS
operator|.
name|AM
block|;
comment|// We have to null out the analysis manager in the moved-from state
comment|// because we are taking ownership of the responsibilty to clear the
comment|// analysis state.
name|RHS
operator|.
name|AM
operator|=
name|nullptr
block|;
return|return
operator|*
name|this
return|;
block|}
operator|~
name|Result
argument_list|()
block|{
comment|// AM is cleared in a moved from state where there is nothing to do.
if|if
condition|(
operator|!
name|AM
condition|)
return|return;
comment|// Clear out the analysis manager if we're being destroyed -- it means we
comment|// didn't even see an invalidate call when we got invalidated.
name|AM
operator|->
name|clear
argument_list|()
block|;     }
comment|/// \brief Accessor for the analysis manager.
name|AnalysisManagerT
operator|&
name|getManager
argument_list|()
block|{
return|return
operator|*
name|AM
return|;
block|}
end_expr_stmt

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

begin_function
name|bool
name|invalidate
parameter_list|(
name|IRUnitT
modifier|&
name|IR
parameter_list|,
specifier|const
name|PreservedAnalyses
modifier|&
name|PA
parameter_list|)
block|{
comment|// If this proxy isn't marked as preserved, then we can't even invalidate
comment|// individual function analyses, there may be an invalid set of Function
comment|// objects in the cache making it impossible to incrementally preserve
comment|// them. Just clear the entire manager.
if|if
condition|(
operator|!
name|PA
operator|.
name|preserved
argument_list|(
name|InnerAnalysisManagerProxy
operator|::
name|ID
argument_list|()
argument_list|)
condition|)
name|AM
operator|->
name|clear
argument_list|()
expr_stmt|;
comment|// Return false to indicate that this result is still a valid proxy.
return|return
name|false
return|;
block|}
end_function

begin_label
name|private
label|:
end_label

begin_decl_stmt
name|AnalysisManagerT
modifier|*
name|AM
decl_stmt|;
end_decl_stmt

begin_macro
unit|};
name|explicit
end_macro

begin_expr_stmt
name|InnerAnalysisManagerProxy
argument_list|(
name|AnalysisManagerT
operator|&
name|AM
argument_list|)
operator|:
name|AM
argument_list|(
argument|&AM
argument_list|)
block|{}
comment|// We have to explicitly define all the special member functions because MSVC
comment|// refuses to generate them.
name|InnerAnalysisManagerProxy
argument_list|(
specifier|const
name|InnerAnalysisManagerProxy
operator|&
name|Arg
argument_list|)
operator|:
name|AM
argument_list|(
argument|Arg.AM
argument_list|)
block|{}
name|InnerAnalysisManagerProxy
argument_list|(
name|InnerAnalysisManagerProxy
operator|&&
name|Arg
argument_list|)
operator|:
name|AM
argument_list|(
argument|std::move(Arg.AM)
argument_list|)
block|{}
name|InnerAnalysisManagerProxy
operator|&
name|operator
operator|=
operator|(
name|InnerAnalysisManagerProxy
name|RHS
operator|)
block|{
name|std
operator|::
name|swap
argument_list|(
name|AM
argument_list|,
name|RHS
operator|.
name|AM
argument_list|)
block|;
return|return
operator|*
name|this
return|;
block|}
end_expr_stmt

begin_comment
comment|/// \brief Run the analysis pass and create our proxy result object.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This doesn't do any interesting work, it is primarily used to insert our
end_comment

begin_comment
comment|/// proxy result object into the module analysis cache so that we can proxy
end_comment

begin_comment
comment|/// invalidation to the function analysis manager.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// In debug builds, it will also assert that the analysis manager is empty
end_comment

begin_comment
comment|/// as no queries should arrive at the function analysis manager prior to
end_comment

begin_comment
comment|/// this analysis being requested.
end_comment

begin_decl_stmt
name|Result
name|run
argument_list|(
name|IRUnitT
operator|&
name|IR
argument_list|,
name|AnalysisManager
operator|<
name|IRUnitT
operator|>
operator|&
argument_list|)
block|{
return|return
name|Result
argument_list|(
operator|*
name|AM
argument_list|)
return|;
block|}
end_decl_stmt

begin_label
name|private
label|:
end_label

begin_expr_stmt
name|friend
name|AnalysisInfoMixin
operator|<
name|InnerAnalysisManagerProxy
operator|<
name|AnalysisManagerT
operator|,
name|IRUnitT
operator|>>
expr_stmt|;
end_expr_stmt

begin_decl_stmt
specifier|static
name|char
name|PassID
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|AnalysisManagerT
modifier|*
name|AM
decl_stmt|;
end_decl_stmt

begin_expr_stmt
unit|};
name|template
operator|<
name|typename
name|AnalysisManagerT
operator|,
name|typename
name|IRUnitT
operator|>
name|char
name|InnerAnalysisManagerProxy
operator|<
name|AnalysisManagerT
operator|,
name|IRUnitT
operator|>
operator|::
name|PassID
expr_stmt|;
end_expr_stmt

begin_extern
extern|extern template class InnerAnalysisManagerProxy<FunctionAnalysisManager
operator|,
extern|Module>;
end_extern

begin_comment
comment|/// Provide the \c FunctionAnalysisManager to \c Module proxy.
end_comment

begin_typedef
typedef|typedef
name|InnerAnalysisManagerProxy
operator|<
name|FunctionAnalysisManager
operator|,
name|Module
operator|>
name|FunctionAnalysisManagerModuleProxy
expr_stmt|;
end_typedef

begin_comment
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

begin_expr_stmt
name|template
operator|<
name|typename
name|AnalysisManagerT
operator|,
name|typename
name|IRUnitT
operator|>
name|class
name|OuterAnalysisManagerProxy
operator|:
name|public
name|AnalysisInfoMixin
operator|<
name|OuterAnalysisManagerProxy
operator|<
name|AnalysisManagerT
operator|,
name|IRUnitT
operator|>>
block|{
name|public
operator|:
comment|/// \brief Result proxy object for \c OuterAnalysisManagerProxy.
name|class
name|Result
block|{
name|public
operator|:
name|explicit
name|Result
argument_list|(
specifier|const
name|AnalysisManagerT
operator|&
name|AM
argument_list|)
operator|:
name|AM
argument_list|(
argument|&AM
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
name|AM
argument_list|(
argument|Arg.AM
argument_list|)
block|{}
name|Result
argument_list|(
name|Result
operator|&&
name|Arg
argument_list|)
operator|:
name|AM
argument_list|(
argument|std::move(Arg.AM)
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
name|AM
argument_list|,
name|RHS
operator|.
name|AM
argument_list|)
block|;
return|return
operator|*
name|this
return|;
block|}
specifier|const
name|AnalysisManagerT
operator|&
name|getManager
argument_list|()
specifier|const
block|{
return|return
operator|*
name|AM
return|;
block|}
comment|/// \brief Handle invalidation by ignoring it, this pass is immutable.
name|bool
name|invalidate
argument_list|(
argument|IRUnitT&
argument_list|)
block|{
return|return
name|false
return|;
block|}
end_expr_stmt

begin_label
name|private
label|:
end_label

begin_decl_stmt
specifier|const
name|AnalysisManagerT
modifier|*
name|AM
decl_stmt|;
end_decl_stmt

begin_expr_stmt
unit|};
name|OuterAnalysisManagerProxy
argument_list|(
specifier|const
name|AnalysisManagerT
operator|&
name|AM
argument_list|)
operator|:
name|AM
argument_list|(
argument|&AM
argument_list|)
block|{}
comment|// We have to explicitly define all the special member functions because MSVC
comment|// refuses to generate them.
name|OuterAnalysisManagerProxy
argument_list|(
specifier|const
name|OuterAnalysisManagerProxy
operator|&
name|Arg
argument_list|)
operator|:
name|AM
argument_list|(
argument|Arg.AM
argument_list|)
block|{}
name|OuterAnalysisManagerProxy
argument_list|(
name|OuterAnalysisManagerProxy
operator|&&
name|Arg
argument_list|)
operator|:
name|AM
argument_list|(
argument|std::move(Arg.AM)
argument_list|)
block|{}
name|OuterAnalysisManagerProxy
operator|&
name|operator
operator|=
operator|(
name|OuterAnalysisManagerProxy
name|RHS
operator|)
block|{
name|std
operator|::
name|swap
argument_list|(
name|AM
argument_list|,
name|RHS
operator|.
name|AM
argument_list|)
block|;
return|return
operator|*
name|this
return|;
block|}
end_expr_stmt

begin_comment
comment|/// \brief Run the analysis pass and create our proxy result object.
end_comment

begin_comment
comment|/// Nothing to see here, it just forwards the \c AM reference into the
end_comment

begin_comment
comment|/// result.
end_comment

begin_decl_stmt
name|Result
name|run
argument_list|(
name|IRUnitT
operator|&
argument_list|,
name|AnalysisManager
operator|<
name|IRUnitT
operator|>
operator|&
argument_list|)
block|{
return|return
name|Result
argument_list|(
operator|*
name|AM
argument_list|)
return|;
block|}
end_decl_stmt

begin_label
name|private
label|:
end_label

begin_expr_stmt
name|friend
name|AnalysisInfoMixin
operator|<
name|OuterAnalysisManagerProxy
operator|<
name|AnalysisManagerT
operator|,
name|IRUnitT
operator|>>
expr_stmt|;
end_expr_stmt

begin_decl_stmt
specifier|static
name|char
name|PassID
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|const
name|AnalysisManagerT
modifier|*
name|AM
decl_stmt|;
end_decl_stmt

begin_expr_stmt
unit|};
name|template
operator|<
name|typename
name|AnalysisManagerT
operator|,
name|typename
name|IRUnitT
operator|>
name|char
name|OuterAnalysisManagerProxy
operator|<
name|AnalysisManagerT
operator|,
name|IRUnitT
operator|>
operator|::
name|PassID
expr_stmt|;
end_expr_stmt

begin_extern
extern|extern template class OuterAnalysisManagerProxy<ModuleAnalysisManager
operator|,
extern|Function>;
end_extern

begin_comment
comment|/// Provide the \c ModuleAnalysisManager to \c Fucntion proxy.
end_comment

begin_typedef
typedef|typedef
name|OuterAnalysisManagerProxy
operator|<
name|ModuleAnalysisManager
operator|,
name|Function
operator|>
name|ModuleAnalysisManagerFunctionProxy
expr_stmt|;
end_typedef

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

begin_comment
comment|///
end_comment

begin_comment
comment|/// Function passes run within this adaptor can rely on having exclusive access
end_comment

begin_comment
comment|/// to the function they are run over. They should not read or modify any other
end_comment

begin_comment
comment|/// functions! Other threads or systems may be manipulating other functions in
end_comment

begin_comment
comment|/// the module, and so their state should never be relied on.
end_comment

begin_comment
comment|/// FIXME: Make the above true for all of LLVM's actual passes, some still
end_comment

begin_comment
comment|/// violate this principle.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// Function passes can also read the module containing the function, but they
end_comment

begin_comment
comment|/// should not modify that module outside of the use lists of various globals.
end_comment

begin_comment
comment|/// For example, a function pass is not permitted to add functions to the
end_comment

begin_comment
comment|/// module.
end_comment

begin_comment
comment|/// FIXME: Make the above true for all of LLVM's actual passes, some still
end_comment

begin_comment
comment|/// violate this principle.
end_comment

begin_expr_stmt
name|template
operator|<
name|typename
name|FunctionPassT
operator|>
name|class
name|ModuleToFunctionPassAdaptor
operator|:
name|public
name|PassInfoMixin
operator|<
name|ModuleToFunctionPassAdaptor
operator|<
name|FunctionPassT
operator|>>
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
argument|Module&M
argument_list|,
argument|ModuleAnalysisManager&AM
argument_list|)
block|{
comment|// Setup the function analysis manager from its proxy.
name|FunctionAnalysisManager
operator|&
name|FAM
operator|=
name|AM
operator|.
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
block|;
name|PreservedAnalyses
name|PA
operator|=
name|PreservedAnalyses
operator|::
name|all
argument_list|()
block|;
for|for
control|(
name|Function
modifier|&
name|F
range|:
name|M
control|)
block|{
if|if
condition|(
name|F
operator|.
name|isDeclaration
argument_list|()
condition|)
continue|continue;
name|PreservedAnalyses
name|PassPA
init|=
name|Pass
operator|.
name|run
argument_list|(
name|F
argument_list|,
name|FAM
argument_list|)
decl_stmt|;
comment|// We know that the function pass couldn't have invalidated any other
comment|// function's analyses (that's the contract of a function pass), so
comment|// directly handle the function analysis manager's invalidation here and
comment|// update our preserved set to reflect that these have already been
comment|// handled.
name|PassPA
operator|=
name|FAM
operator|.
name|invalidate
argument_list|(
name|F
argument_list|,
name|std
operator|::
name|move
argument_list|(
name|PassPA
argument_list|)
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
comment|// By definition we preserve the proxy. This precludes *any* invalidation
comment|// of function analyses by the proxy, but that's OK because we've taken
comment|// care to invalidate analyses in the function analysis manager
comment|// incrementally above.
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

begin_decl_stmt
unit|}  private:
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
return|;
block|}
end_expr_stmt

begin_comment
comment|/// \brief A template utility pass to force an analysis result to be available.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This is a no-op pass which simply forces a specific analysis pass's result
end_comment

begin_comment
comment|/// to be available when it is run.
end_comment

begin_expr_stmt
name|template
operator|<
name|typename
name|AnalysisT
operator|>
expr|struct
name|RequireAnalysisPass
operator|:
name|PassInfoMixin
operator|<
name|RequireAnalysisPass
operator|<
name|AnalysisT
operator|>>
block|{
comment|/// \brief Run this pass over some unit of IR.
comment|///
comment|/// This pass can be run over any unit of IR and use any analysis manager
comment|/// provided they satisfy the basic API requirements. When this pass is
comment|/// created, these methods can be instantiated to satisfy whatever the
comment|/// context requires.
name|template
operator|<
name|typename
name|IRUnitT
operator|>
name|PreservedAnalyses
name|run
argument_list|(
argument|IRUnitT&Arg
argument_list|,
argument|AnalysisManager<IRUnitT>&AM
argument_list|)
block|{
operator|(
name|void
operator|)
name|AM
operator|.
name|template
name|getResult
operator|<
name|AnalysisT
operator|>
operator|(
name|Arg
operator|)
block|;
return|return
name|PreservedAnalyses
operator|::
name|all
argument_list|()
return|;
block|}
end_expr_stmt

begin_comment
unit|};
comment|/// \brief A template utility pass to force an analysis result to be
end_comment

begin_comment
comment|/// invalidated.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This is a no-op pass which simply forces a specific analysis result to be
end_comment

begin_comment
comment|/// invalidated when it is run.
end_comment

begin_expr_stmt
name|template
operator|<
name|typename
name|AnalysisT
operator|>
expr|struct
name|InvalidateAnalysisPass
operator|:
name|PassInfoMixin
operator|<
name|InvalidateAnalysisPass
operator|<
name|AnalysisT
operator|>>
block|{
comment|/// \brief Run this pass over some unit of IR.
comment|///
comment|/// This pass can be run over any unit of IR and use any analysis manager
comment|/// provided they satisfy the basic API requirements. When this pass is
comment|/// created, these methods can be instantiated to satisfy whatever the
comment|/// context requires.
name|template
operator|<
name|typename
name|IRUnitT
operator|>
name|PreservedAnalyses
name|run
argument_list|(
argument|IRUnitT&Arg
argument_list|,
argument|AnalysisManager<IRUnitT>&AM
argument_list|)
block|{
comment|// We have to directly invalidate the analysis result as we can't
comment|// enumerate all other analyses and use the preserved set to control it.
name|AM
operator|.
name|template
name|invalidate
operator|<
name|AnalysisT
operator|>
operator|(
name|Arg
operator|)
block|;
return|return
name|PreservedAnalyses
operator|::
name|all
argument_list|()
return|;
block|}
end_expr_stmt

begin_comment
unit|};
comment|/// \brief A utility pass that does nothing but preserves no analyses.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// As a consequence fo not preserving any analyses, this pass will force all
end_comment

begin_comment
comment|/// analysis passes to be re-run to produce fresh results if any are needed.
end_comment

begin_decl_stmt
name|struct
name|InvalidateAllAnalysesPass
range|:
name|PassInfoMixin
operator|<
name|InvalidateAllAnalysesPass
operator|>
block|{
comment|/// \brief Run this pass over some unit of IR.
name|template
operator|<
name|typename
name|IRUnitT
operator|>
name|PreservedAnalyses
name|run
argument_list|(
argument|IRUnitT&
argument_list|,
argument|AnalysisManager<IRUnitT>&
argument_list|)
block|{
return|return
name|PreservedAnalyses
operator|::
name|none
argument_list|()
return|;
block|}
expr|}
block|;  }
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

