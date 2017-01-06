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
file|"llvm/ADT/TinyPtrVector.h"
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
comment|/// A special type used by analysis passes to provide an address that
comment|/// identifies that particular analysis pass type.
comment|///
comment|/// Analysis passes should have a static data member of this type and derive
comment|/// from the \c AnalysisInfoMixin to get a static ID method used to identify
comment|/// the analysis in the pass management infrastructure.
struct|struct
name|alignas
argument_list|(
literal|8
argument_list|)
name|AnalysisKey
block|{}
struct|;
comment|/// A special type used to provide an address that identifies a set of related
comment|/// analyses.  These sets are primarily used below to mark sets of analyses as
comment|/// preserved.
comment|///
comment|/// For example, a transformation can indicate that it preserves the CFG of a
comment|/// function by preserving the appropriate AnalysisSetKey.  An analysis that
comment|/// depends only on the CFG can then check if that AnalysisSetKey is preserved;
comment|/// if it is, the analysis knows that it itself is preserved.
struct|struct
name|alignas
argument_list|(
literal|8
argument_list|)
name|AnalysisSetKey
block|{}
struct|;
comment|/// A set of analyses that are preserved following a run of a transformation
comment|/// pass.
comment|///
comment|/// Transformation passes build and return these objects to communicate which
comment|/// analyses are still valid after the transformation. For most passes this is
comment|/// fairly simple: if they don't change anything all analyses are preserved,
comment|/// otherwise only a short list of analyses that have been explicitly updated
comment|/// are preserved.
comment|///
comment|/// This class also lets transformation passes mark abstract *sets* of analyses
comment|/// as preserved. A transformation that (say) does not alter the CFG can
comment|/// indicate such by marking a particular AnalysisSetKey as preserved, and
comment|/// then analyses can query whether that AnalysisSetKey is preserved.
comment|///
comment|/// Finally, this class can represent an "abandoned" analysis, which is
comment|/// not preserved even if it would be covered by some abstract set of analyses.
comment|///
comment|/// Given a `PreservedAnalyses` object, an analysis will typically want to
comment|/// figure out whether it is preserved. In the example below, MyAnalysisType is
comment|/// preserved if it's not abandoned, and (a) it's explicitly marked as
comment|/// preserved, (b), the set AllAnalysesOn<MyIRUnit> is preserved, or (c) both
comment|/// AnalysisSetA and AnalysisSetB are preserved.
comment|///
comment|/// ```
comment|///   auto PAC = PA.getChecker<MyAnalysisType>();
comment|///   if (PAC.preserved() || PAC.preservedSet<AllAnalysesOn<MyIRUnit>>() ||
comment|///       (PAC.preservedSet<AnalysisSetA>()&&
comment|///        PAC.preservedSet<AnalysisSetB>())) {
comment|///     // The analysis has been successfully preserved ...
comment|///   }
comment|/// ```
name|class
name|PreservedAnalyses
block|{
name|public
label|:
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
name|PreservedIDs
operator|.
name|insert
argument_list|(
operator|&
name|AllAnalysesKey
argument_list|)
expr_stmt|;
return|return
name|PA
return|;
block|}
comment|/// Mark an analysis as preserved.
name|template
operator|<
name|typename
name|AnalysisT
operator|>
name|void
name|preserve
argument_list|()
block|{
name|preserve
argument_list|(
name|AnalysisT
operator|::
name|ID
argument_list|()
argument_list|)
block|; }
comment|/// \brief Given an analysis's ID, mark the analysis as preserved, adding it
comment|/// to the set.
name|void
name|preserve
argument_list|(
argument|AnalysisKey *ID
argument_list|)
block|{
comment|// Clear this ID from the explicit not-preserved set if present.
name|NotPreservedAnalysisIDs
operator|.
name|erase
argument_list|(
name|ID
argument_list|)
block|;
comment|// If we're not already preserving all analyses (other than those in
comment|// NotPreservedAnalysisIDs).
if|if
condition|(
operator|!
name|areAllPreserved
argument_list|()
condition|)
name|PreservedIDs
operator|.
name|insert
argument_list|(
name|ID
argument_list|)
expr_stmt|;
block|}
comment|/// Mark an analysis set as preserved.
name|template
operator|<
name|typename
name|AnalysisSetT
operator|>
name|void
name|preserveSet
argument_list|()
block|{
name|preserveSet
argument_list|(
name|AnalysisSetT
operator|::
name|ID
argument_list|()
argument_list|)
block|;   }
comment|/// Mark an analysis set as preserved using its ID.
name|void
name|preserveSet
argument_list|(
argument|AnalysisSetKey *ID
argument_list|)
block|{
comment|// If we're not already in the saturated 'all' state, add this set.
if|if
condition|(
operator|!
name|areAllPreserved
argument_list|()
condition|)
name|PreservedIDs
operator|.
name|insert
argument_list|(
name|ID
argument_list|)
expr_stmt|;
block|}
comment|/// Mark an analysis as abandoned.
comment|///
comment|/// An abandoned analysis is not preserved, even if it is nominally covered
comment|/// by some other set or was previously explicitly marked as preserved.
comment|///
comment|/// Note that you can only abandon a specific analysis, not a *set* of
comment|/// analyses.
name|template
operator|<
name|typename
name|AnalysisT
operator|>
name|void
name|abandon
argument_list|()
block|{
name|abandon
argument_list|(
name|AnalysisT
operator|::
name|ID
argument_list|()
argument_list|)
block|; }
comment|/// Mark an analysis as abandoned using its ID.
comment|///
comment|/// An abandoned analysis is not preserved, even if it is nominally covered
comment|/// by some other set or was previously explicitly marked as preserved.
comment|///
comment|/// Note that you can only abandon a specific analysis, not a *set* of
comment|/// analyses.
name|void
name|abandon
argument_list|(
argument|AnalysisKey *ID
argument_list|)
block|{
name|PreservedIDs
operator|.
name|erase
argument_list|(
name|ID
argument_list|)
block|;
name|NotPreservedAnalysisIDs
operator|.
name|insert
argument_list|(
name|ID
argument_list|)
block|;   }
comment|/// \brief Intersect this set with another in place.
comment|///
comment|/// This is a mutating operation on this preserved set, removing all
comment|/// preserved passes which are not also preserved in the argument.
name|void
name|intersect
argument_list|(
argument|const PreservedAnalyses&Arg
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
operator|*
name|this
operator|=
name|Arg
expr_stmt|;
return|return;
block|}
comment|// The intersection requires the *union* of the explicitly not-preserved
comment|// IDs and the *intersection* of the preserved IDs.
for|for
control|(
name|auto
name|ID
range|:
name|Arg
operator|.
name|NotPreservedAnalysisIDs
control|)
block|{
name|PreservedIDs
operator|.
name|erase
argument_list|(
name|ID
argument_list|)
expr_stmt|;
name|NotPreservedAnalysisIDs
operator|.
name|insert
argument_list|(
name|ID
argument_list|)
expr_stmt|;
block|}
for|for
control|(
name|auto
name|ID
range|:
name|PreservedIDs
control|)
if|if
condition|(
operator|!
name|Arg
operator|.
name|PreservedIDs
operator|.
name|count
argument_list|(
name|ID
argument_list|)
condition|)
name|PreservedIDs
operator|.
name|erase
argument_list|(
name|ID
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
operator|*
name|this
operator|=
name|std
operator|::
name|move
argument_list|(
name|Arg
argument_list|)
expr_stmt|;
return|return;
block|}
comment|// The intersection requires the *union* of the explicitly not-preserved
comment|// IDs and the *intersection* of the preserved IDs.
for|for
control|(
name|auto
name|ID
range|:
name|Arg
operator|.
name|NotPreservedAnalysisIDs
control|)
block|{
name|PreservedIDs
operator|.
name|erase
argument_list|(
name|ID
argument_list|)
expr_stmt|;
name|NotPreservedAnalysisIDs
operator|.
name|insert
argument_list|(
name|ID
argument_list|)
expr_stmt|;
block|}
for|for
control|(
name|auto
name|ID
range|:
name|PreservedIDs
control|)
if|if
condition|(
operator|!
name|Arg
operator|.
name|PreservedIDs
operator|.
name|count
argument_list|(
name|ID
argument_list|)
condition|)
name|PreservedIDs
operator|.
name|erase
argument_list|(
name|ID
argument_list|)
expr_stmt|;
block|}
comment|/// A checker object that makes it easy to query for whether an analysis or
comment|/// some set covering it is preserved.
name|class
name|PreservedAnalysisChecker
block|{
name|friend
name|class
name|PreservedAnalyses
decl_stmt|;
specifier|const
name|PreservedAnalyses
modifier|&
name|PA
decl_stmt|;
name|AnalysisKey
modifier|*
specifier|const
name|ID
decl_stmt|;
specifier|const
name|bool
name|IsAbandoned
decl_stmt|;
comment|/// A PreservedAnalysisChecker is tied to a particular Analysis because
comment|/// `preserved()` and `preservedSet()` both return false if the Analysis
comment|/// was abandoned.
name|PreservedAnalysisChecker
argument_list|(
specifier|const
name|PreservedAnalyses
operator|&
name|PA
argument_list|,
name|AnalysisKey
operator|*
name|ID
argument_list|)
operator|:
name|PA
argument_list|(
name|PA
argument_list|)
operator|,
name|ID
argument_list|(
name|ID
argument_list|)
operator|,
name|IsAbandoned
argument_list|(
argument|PA.NotPreservedAnalysisIDs.count(ID)
argument_list|)
block|{}
name|public
operator|:
comment|/// Returns true if the checker's analysis was not abandoned and either
comment|///  - the analysis is explicitly preserved or
comment|///  - all analyses are preserved.
name|bool
name|preserved
argument_list|()
block|{
return|return
operator|!
name|IsAbandoned
operator|&&
operator|(
name|PA
operator|.
name|PreservedIDs
operator|.
name|count
argument_list|(
operator|&
name|AllAnalysesKey
argument_list|)
operator|||
name|PA
operator|.
name|PreservedIDs
operator|.
name|count
argument_list|(
name|ID
argument_list|)
operator|)
return|;
block|}
comment|/// Returns true if the checker's analysis was not abandoned and either
comment|///  - \p AnalysisSetT is explicitly preserved or
comment|///  - all analyses are preserved.
name|template
operator|<
name|typename
name|AnalysisSetT
operator|>
name|bool
name|preservedSet
argument_list|()
block|{
name|AnalysisSetKey
operator|*
name|SetID
operator|=
name|AnalysisSetT
operator|::
name|ID
argument_list|()
block|;
return|return
operator|!
name|IsAbandoned
operator|&&
operator|(
name|PA
operator|.
name|PreservedIDs
operator|.
name|count
argument_list|(
operator|&
name|AllAnalysesKey
argument_list|)
operator|||
name|PA
operator|.
name|PreservedIDs
operator|.
name|count
argument_list|(
name|SetID
argument_list|)
operator|)
return|;
block|}
block|}
empty_stmt|;
comment|/// Build a checker for this `PreservedAnalyses` and the specified analysis
comment|/// type.
comment|///
comment|/// You can use the returned object to query whether an analysis was
comment|/// preserved. See the example in the comment on `PreservedAnalysis`.
name|template
operator|<
name|typename
name|AnalysisT
operator|>
name|PreservedAnalysisChecker
name|getChecker
argument_list|()
specifier|const
block|{
return|return
name|PreservedAnalysisChecker
argument_list|(
operator|*
name|this
argument_list|,
name|AnalysisT
operator|::
name|ID
argument_list|()
argument_list|)
return|;
block|}
comment|/// Build a checker for this `PreservedAnalyses` and the specified analysis
comment|/// ID.
comment|///
comment|/// You can use the returned object to query whether an analysis was
comment|/// preserved. See the example in the comment on `PreservedAnalysis`.
name|PreservedAnalysisChecker
name|getChecker
argument_list|(
name|AnalysisKey
operator|*
name|ID
argument_list|)
decl|const
block|{
return|return
name|PreservedAnalysisChecker
argument_list|(
operator|*
name|this
argument_list|,
name|ID
argument_list|)
return|;
block|}
comment|/// Test whether all analyses are preserved (and none are abandoned).
comment|///
comment|/// This is used primarily to optimize for the common case of a transformation
comment|/// which makes no changes to the IR.
name|bool
name|areAllPreserved
argument_list|()
specifier|const
block|{
return|return
name|NotPreservedAnalysisIDs
operator|.
name|empty
argument_list|()
operator|&&
name|PreservedIDs
operator|.
name|count
argument_list|(
operator|&
name|AllAnalysesKey
argument_list|)
return|;
block|}
comment|/// Directly test whether a set of analyses is preserved.
comment|///
comment|/// This is only true when no analyses have been explicitly abandoned.
name|template
operator|<
name|typename
name|AnalysisSetT
operator|>
name|bool
name|allAnalysesInSetPreserved
argument_list|()
specifier|const
block|{
return|return
name|allAnalysesInSetPreserved
argument_list|(
name|AnalysisSetT
operator|::
name|ID
argument_list|()
argument_list|)
return|;
block|}
comment|/// Directly test whether a set of analyses is preserved.
comment|///
comment|/// This is only true when no analyses have been explicitly abandoned.
name|bool
name|allAnalysesInSetPreserved
argument_list|(
name|AnalysisSetKey
operator|*
name|SetID
argument_list|)
decl|const
block|{
return|return
name|NotPreservedAnalysisIDs
operator|.
name|empty
argument_list|()
operator|&&
operator|(
name|PreservedIDs
operator|.
name|count
argument_list|(
operator|&
name|AllAnalysesKey
argument_list|)
operator|||
name|PreservedIDs
operator|.
name|count
argument_list|(
name|SetID
argument_list|)
operator|)
return|;
block|}
name|private
label|:
comment|/// A special key used to indicate all analyses.
specifier|static
name|AnalysisSetKey
name|AllAnalysesKey
decl_stmt|;
comment|/// The IDs of analyses and analysis sets that are preserved.
name|SmallPtrSet
operator|<
name|void
operator|*
operator|,
literal|2
operator|>
name|PreservedIDs
expr_stmt|;
comment|/// The IDs of explicitly not-preserved analyses.
comment|///
comment|/// If an analysis in this set is covered by a set in `PreservedIDs`, we
comment|/// consider it not-preserved. That is, `NotPreservedAnalysisIDs` always
comment|/// "wins" over analysis sets in `PreservedIDs`.
comment|///
comment|/// Also, a given ID should never occur both here and in `PreservedIDs`.
name|SmallPtrSet
operator|<
name|AnalysisKey
operator|*
operator|,
literal|2
operator|>
name|NotPreservedAnalysisIDs
expr_stmt|;
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
comment|// Forward declare the analysis manager template.
end_comment

begin_expr_stmt
name|template
operator|<
name|typename
name|IRUnitT
operator|,
name|typename
operator|...
name|ExtraArgTs
operator|>
name|class
name|AnalysisManager
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// A CRTP mix-in to automatically provide informational APIs needed for
end_comment

begin_comment
comment|/// passes.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This provides some boilerplate for types that are passes.
end_comment

begin_expr_stmt
name|template
operator|<
name|typename
name|DerivedT
operator|>
expr|struct
name|PassInfoMixin
block|{
comment|/// Gets the name of the pass we are mixed into.
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
end_expr_stmt

begin_comment
unit|};
comment|/// A CRTP mix-in that provides informational APIs needed for analysis passes.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This provides some boilerplate for types that are analysis passes. It
end_comment

begin_comment
comment|/// automatically mixes in \c PassInfoMixin.
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
comment|/// Returns an opaque, unique ID for this analysis type.
comment|///
comment|/// This ID is a pointer type that is guaranteed to be 8-byte aligned and thus
comment|/// suitable for use in sets, maps, and other data structures that use the low
comment|/// bits of pointers.
comment|///
comment|/// Note that this requires the derived type provide a static \c AnalysisKey
comment|/// member called \c Key.
comment|///
comment|/// FIXME: The only reason the mixin type itself can't declare the Key value
comment|/// is that some compilers cannot correctly unique a templated static variable
comment|/// so it has the same addresses in each instantiation. The only currently
comment|/// known platform with this limitation is Windows DLL builds, specifically
comment|/// building each part of LLVM as a DLL. If we ever remove that build
comment|/// configuration, this mixin can provide the static key as well.
specifier|static
name|AnalysisKey
operator|*
name|ID
argument_list|()
block|{
return|return
operator|&
name|DerivedT
operator|::
name|Key
return|;
block|}
end_expr_stmt

begin_comment
unit|};
comment|/// This templated class represents "all analyses that operate over \<a
end_comment

begin_comment
comment|/// particular IR unit\>" (e.g. a Function or a Module) in instances of
end_comment

begin_comment
comment|/// PreservedAnalysis.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This lets a transformation say e.g. "I preserved all function analyses".
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// Note that you must provide an explicit instantiation declaration and
end_comment

begin_comment
comment|/// definition for this template in order to get the correct behavior on
end_comment

begin_comment
comment|/// Windows. Otherwise, the address of SetKey will not be stable.
end_comment

begin_expr_stmt
name|template
operator|<
name|typename
name|IRUnitT
operator|>
name|class
name|AllAnalysesOn
block|{
name|public
operator|:
specifier|static
name|AnalysisSetKey
operator|*
name|ID
argument_list|()
block|{
return|return
operator|&
name|SetKey
return|;
block|}
name|private
operator|:
specifier|static
name|AnalysisSetKey
name|SetKey
expr_stmt|;
end_expr_stmt

begin_expr_stmt
unit|};
name|template
operator|<
name|typename
name|IRUnitT
operator|>
name|AnalysisSetKey
name|AllAnalysesOn
operator|<
name|IRUnitT
operator|>
operator|::
name|SetKey
expr_stmt|;
end_expr_stmt

begin_extern
extern|extern template class AllAnalysesOn<Module>;
end_extern

begin_extern
extern|extern template class AllAnalysesOn<Function>;
end_extern

begin_comment
comment|/// \brief Manages a sequence of passes over a particular unit of IR.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// A pass manager contains a sequence of passes to run over a particular unit
end_comment

begin_comment
comment|/// of IR (e.g. Functions, Modules). It is itself a valid pass over that unit of
end_comment

begin_comment
comment|/// IR, and when run over some given IR will run each of its contained passes in
end_comment

begin_comment
comment|/// sequence. Pass managers are the primary and most basic building block of a
end_comment

begin_comment
comment|/// pass pipeline.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// When you run a pass manager, you provide an \c AnalysisManager<IRUnitT>
end_comment

begin_comment
comment|/// argument. The pass manager will propagate that analysis manager to each
end_comment

begin_comment
comment|/// pass it runs, and will call the analysis manager's invalidation routine with
end_comment

begin_comment
comment|/// the PreservedAnalyses of each pass it runs.
end_comment

begin_expr_stmt
name|template
operator|<
name|typename
name|IRUnitT
operator|,
name|typename
name|AnalysisManagerT
operator|=
name|AnalysisManager
operator|<
name|IRUnitT
operator|>
operator|,
name|typename
operator|...
name|ExtraArgTs
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
operator|,
name|AnalysisManagerT
operator|,
name|ExtraArgTs
operator|...
operator|>>
block|{
name|public
operator|:
comment|/// \brief Construct a pass manager.
comment|///
comment|/// If \p DebugLogging is true, we'll log our progress to llvm::dbgs().
name|explicit
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
comment|// FIXME: These are equivalent to the default move constructor/move
comment|// assignment. However, using = default triggers linker errors due to the
comment|// explicit instantiations below. Find away to use the default and remove the
comment|// duplicated code here.
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
comment|/// \brief Run all of the passes in this manager over the given unit of IR.
comment|/// ExtraArgs are passed to each pass.
name|PreservedAnalyses
name|run
argument_list|(
argument|IRUnitT&IR
argument_list|,
argument|AnalysisManagerT&AM
argument_list|,
argument|ExtraArgTs... ExtraArgs
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
argument_list|,
name|ExtraArgs
operator|...
argument_list|)
decl_stmt|;
comment|// Update the analysis manager as each pass runs and potentially
comment|// invalidates analyses.
name|AM
operator|.
name|invalidate
argument_list|(
name|IR
argument_list|,
name|PassPA
argument_list|)
expr_stmt|;
comment|// Finally, intersect the preserved analyses to compute the aggregate
comment|// preserved set for this pass manager.
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

begin_comment
comment|// Invaliadtion was handled after each pass in the above loop for the
end_comment

begin_comment
comment|// current unit of IR. Therefore, the remaining analysis results in the
end_comment

begin_comment
comment|// AnalysisManager are preserved. We mark this with a set so that we don't
end_comment

begin_comment
comment|// need to inspect each one individually.
end_comment

begin_expr_stmt
name|PA
operator|.
name|preserveSet
operator|<
name|AllAnalysesOn
operator|<
name|IRUnitT
operator|>>
operator|(
operator|)
expr_stmt|;
end_expr_stmt

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
operator|,
name|PreservedAnalyses
operator|,
name|AnalysisManagerT
operator|,
name|ExtraArgTs
operator|...
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
operator|,
name|AnalysisManagerT
operator|,
name|ExtraArgTs
operator|...
operator|>
name|PassConceptT
expr_stmt|;
end_typedef

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

begin_comment
comment|/// \brief A container for analyses that lazily runs them and caches their
end_comment

begin_comment
comment|/// results.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This class can manage analyses for any IR unit where the address of the IR
end_comment

begin_comment
comment|/// unit sufficies as its identity.
end_comment

begin_expr_stmt
name|template
operator|<
name|typename
name|IRUnitT
operator|,
name|typename
operator|...
name|ExtraArgTs
operator|>
name|class
name|AnalysisManager
block|{
name|public
operator|:
name|class
name|Invalidator
block|;
name|private
operator|:
comment|// Now that we've defined our invalidator, we can define the concept types.
typedef|typedef
name|detail
operator|::
name|AnalysisResultConcept
operator|<
name|IRUnitT
operator|,
name|PreservedAnalyses
operator|,
name|Invalidator
operator|>
name|ResultConceptT
expr_stmt|;
end_expr_stmt

begin_typedef
typedef|typedef
name|detail
operator|::
name|AnalysisPassConcept
operator|<
name|IRUnitT
operator|,
name|PreservedAnalyses
operator|,
name|Invalidator
operator|,
name|ExtraArgTs
operator|...
operator|>
name|PassConceptT
expr_stmt|;
end_typedef

begin_comment
comment|/// \brief List of analysis pass IDs and associated concept pointers.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// Requires iterators to be valid across appending new entries and arbitrary
end_comment

begin_comment
comment|/// erases. Provides the analysis ID to enable finding iterators to a given
end_comment

begin_comment
comment|/// entry in maps below, and provides the storage for the actual result
end_comment

begin_comment
comment|/// concept.
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
name|AnalysisKey
operator|*
operator|,
name|std
operator|::
name|unique_ptr
operator|<
name|ResultConceptT
operator|>>>
name|AnalysisResultListT
expr_stmt|;
end_typedef

begin_comment
comment|/// \brief Map type from IRUnitT pointer to our custom list type.
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
comment|/// \brief Map type from a pair of analysis ID and IRUnitT pointer to an
end_comment

begin_comment
comment|/// iterator into a particular result list (which is where the actual analysis
end_comment

begin_comment
comment|/// result is stored).
end_comment

begin_typedef
typedef|typedef
name|DenseMap
operator|<
name|std
operator|::
name|pair
operator|<
name|AnalysisKey
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

begin_label
name|public
label|:
end_label

begin_comment
comment|/// API to communicate dependencies between analyses during invalidation.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// When an analysis result embeds handles to other analysis results, it
end_comment

begin_comment
comment|/// needs to be invalidated both when its own information isn't preserved and
end_comment

begin_comment
comment|/// when any of its embedded analysis results end up invalidated. We pass an
end_comment

begin_comment
comment|/// \c Invalidator object as an argument to \c invalidate() in order to let
end_comment

begin_comment
comment|/// the analysis results themselves define the dependency graph on the fly.
end_comment

begin_comment
comment|/// This lets us avoid building building an explicit representation of the
end_comment

begin_comment
comment|/// dependencies between analysis results.
end_comment

begin_decl_stmt
name|class
name|Invalidator
block|{
name|public
label|:
comment|/// Trigger the invalidation of some other analysis pass if not already
comment|/// handled and return whether it was in fact invalidated.
comment|///
comment|/// This is expected to be called from within a given analysis result's \c
comment|/// invalidate method to trigger a depth-first walk of all inter-analysis
comment|/// dependencies. The same \p IR unit and \p PA passed to that result's \c
comment|/// invalidate method should in turn be provided to this routine.
comment|///
comment|/// The first time this is called for a given analysis pass, it will call
comment|/// the corresponding result's \c invalidate method.  Subsequent calls will
comment|/// use a cache of the results of that initial call.  It is an error to form
comment|/// cyclic dependencies between analysis results.
comment|///
comment|/// This returns true if the given analysis's result is invalid. Any
comment|/// dependecies on it will become invalid as a result.
name|template
operator|<
name|typename
name|PassT
operator|>
name|bool
name|invalidate
argument_list|(
argument|IRUnitT&IR
argument_list|,
argument|const PreservedAnalyses&PA
argument_list|)
block|{
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
operator|,
name|PreservedAnalyses
operator|,
name|Invalidator
operator|>
name|ResultModelT
expr_stmt|;
return|return
name|invalidateImpl
operator|<
name|ResultModelT
operator|>
operator|(
name|PassT
operator|::
name|ID
argument_list|()
operator|,
name|IR
operator|,
name|PA
operator|)
return|;
block|}
end_decl_stmt

begin_comment
comment|/// A type-erased variant of the above invalidate method with the same core
end_comment

begin_comment
comment|/// API other than passing an analysis ID rather than an analysis type
end_comment

begin_comment
comment|/// parameter.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This is sadly less efficient than the above routine, which leverages
end_comment

begin_comment
comment|/// the type parameter to avoid the type erasure overhead.
end_comment

begin_function
name|bool
name|invalidate
parameter_list|(
name|AnalysisKey
modifier|*
name|ID
parameter_list|,
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
return|return
name|invalidateImpl
operator|<
operator|>
operator|(
name|ID
operator|,
name|IR
operator|,
name|PA
operator|)
return|;
block|}
end_function

begin_label
name|private
label|:
end_label

begin_decl_stmt
name|friend
name|class
name|AnalysisManager
decl_stmt|;
end_decl_stmt

begin_expr_stmt
name|template
operator|<
name|typename
name|ResultT
operator|=
name|ResultConceptT
operator|>
name|bool
name|invalidateImpl
argument_list|(
argument|AnalysisKey *ID
argument_list|,
argument|IRUnitT&IR
argument_list|,
argument|const PreservedAnalyses&PA
argument_list|)
block|{
comment|// If we've already visited this pass, return true if it was invalidated
comment|// and false otherwise.
name|auto
name|IMapI
operator|=
name|IsResultInvalidated
operator|.
name|find
argument_list|(
name|ID
argument_list|)
block|;
if|if
condition|(
name|IMapI
operator|!=
name|IsResultInvalidated
operator|.
name|end
argument_list|()
condition|)
return|return
name|IMapI
operator|->
name|second
return|;
comment|// Otherwise look up the result object.
name|auto
name|RI
operator|=
name|Results
operator|.
name|find
argument_list|(
block|{
name|ID
block|,
operator|&
name|IR
block|}
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|assert
argument_list|(
name|RI
operator|!=
name|Results
operator|.
name|end
argument_list|()
operator|&&
literal|"Trying to invalidate a dependent result that isn't in the "
literal|"manager's cache is always an error, likely due to a stale result "
literal|"handle!"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|auto
operator|&
name|Result
operator|=
name|static_cast
operator|<
name|ResultT
operator|&
operator|>
operator|(
operator|*
name|RI
operator|->
name|second
operator|->
name|second
operator|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|// Insert into the map whether the result should be invalidated and return
end_comment

begin_comment
comment|// that. Note that we cannot reuse IMapI and must do a fresh insert here,
end_comment

begin_comment
comment|// as calling invalidate could (recursively) insert things into the map,
end_comment

begin_comment
comment|// making any iterator or reference invalid.
end_comment

begin_decl_stmt
name|bool
name|Inserted
decl_stmt|;
end_decl_stmt

begin_expr_stmt
name|std
operator|::
name|tie
argument_list|(
name|IMapI
argument_list|,
name|Inserted
argument_list|)
operator|=
name|IsResultInvalidated
operator|.
name|insert
argument_list|(
block|{
name|ID
block|,
name|Result
operator|.
name|invalidate
argument_list|(
argument|IR
argument_list|,
argument|PA
argument_list|,
argument|*this
argument_list|)
block|}
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
operator|(
name|void
operator|)
name|Inserted
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|assert
argument_list|(
name|Inserted
operator|&&
literal|"Should not have already inserted this ID, likely "
literal|"indicates a dependency cycle!"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_return
return|return
name|IMapI
operator|->
name|second
return|;
end_return

begin_expr_stmt
unit|}      Invalidator
operator|(
name|SmallDenseMap
operator|<
name|AnalysisKey
operator|*
operator|,
name|bool
operator|,
literal|8
operator|>
operator|&
name|IsResultInvalidated
operator|,
specifier|const
name|AnalysisResultMapT
operator|&
name|Results
operator|)
operator|:
name|IsResultInvalidated
argument_list|(
name|IsResultInvalidated
argument_list|)
operator|,
name|Results
argument_list|(
argument|Results
argument_list|)
block|{}
name|SmallDenseMap
operator|<
name|AnalysisKey
operator|*
operator|,
name|bool
operator|,
literal|8
operator|>
operator|&
name|IsResultInvalidated
expr_stmt|;
end_expr_stmt

begin_decl_stmt
specifier|const
name|AnalysisResultMapT
modifier|&
name|Results
decl_stmt|;
end_decl_stmt

begin_comment
unit|};
comment|/// \brief Construct an empty analysis manager.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// If \p DebugLogging is true, we'll log our progress to llvm::dbgs().
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

begin_expr_stmt
name|AnalysisManager
argument_list|(
name|AnalysisManager
operator|&&
argument_list|)
operator|=
expr|default
expr_stmt|;
end_expr_stmt

begin_decl_stmt
name|AnalysisManager
modifier|&
name|operator
init|=
operator|(
name|AnalysisManager
operator|&&
operator|)
operator|=
expr|default
decl_stmt|;
end_decl_stmt

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
comment|/// \brief Clear any cached analysis results for a single unit of IR.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This doesn't invalidate, but instead simply deletes, the relevant results.
end_comment

begin_comment
comment|/// It is useful when the IR is being removed and we want to clear out all the
end_comment

begin_comment
comment|/// memory pinned for it.
end_comment

begin_function
name|void
name|clear
parameter_list|(
name|IRUnitT
modifier|&
name|IR
parameter_list|)
block|{
if|if
condition|(
name|DebugLogging
condition|)
name|dbgs
argument_list|()
operator|<<
literal|"Clearing all analysis results for: "
operator|<<
name|IR
operator|.
name|getName
argument_list|()
operator|<<
literal|"\n"
expr_stmt|;
name|auto
name|ResultsListI
init|=
name|AnalysisResultLists
operator|.
name|find
argument_list|(
operator|&
name|IR
argument_list|)
decl_stmt|;
if|if
condition|(
name|ResultsListI
operator|==
name|AnalysisResultLists
operator|.
name|end
argument_list|()
condition|)
return|return;
comment|// Delete the map entries that point into the results list.
for|for
control|(
name|auto
operator|&
name|IDAndResult
operator|:
name|ResultsListI
operator|->
name|second
control|)
name|AnalysisResults
operator|.
name|erase
argument_list|(
block|{
name|IDAndResult
operator|.
name|first
block|,
operator|&
name|IR
block|}
argument_list|)
expr_stmt|;
comment|// And actually destroy and erase the results associated with this IR.
name|AnalysisResultLists
operator|.
name|erase
argument_list|(
name|ResultsListI
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|/// \brief Clear all analysis results cached by this AnalysisManager.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// Like \c clear(IRUnitT&), this doesn't invalidate the results; it simply
end_comment

begin_comment
comment|/// deletes them.  This lets you clean up the AnalysisManager when the set of
end_comment

begin_comment
comment|/// IR units itself has potentially changed, and thus we can't even look up a
end_comment

begin_comment
comment|/// a result and invalidate/clear it directly.
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

begin_comment
comment|/// \brief Get the result of an analysis pass for a given IR unit.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// Runs the analysis if a cached result is not available.
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
operator|&
name|getResult
argument_list|(
argument|IRUnitT&IR
argument_list|,
argument|ExtraArgTs... ExtraArgs
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
name|getResultImpl
argument_list|(
name|PassT
operator|::
name|ID
argument_list|()
argument_list|,
name|IR
argument_list|,
name|ExtraArgs
operator|...
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
operator|,
name|PreservedAnalyses
operator|,
name|Invalidator
operator|>
name|ResultModelT
expr_stmt|;
end_expr_stmt

begin_return
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
end_return

begin_comment
unit|}
comment|/// \brief Get the cached result of an analysis pass for a given IR unit.
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
unit|template
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
operator|,
name|PreservedAnalyses
operator|,
name|Invalidator
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
comment|/// The parameter is a callable whose result is an analysis pass. This allows
end_comment

begin_comment
comment|/// passing in a lambda to construct the analysis.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// The analysis type to register is the type returned by calling the \c
end_comment

begin_comment
comment|/// PassBuilder argument. If that type has already been registered, then the
end_comment

begin_comment
comment|/// argument will not be called and this function will return false.
end_comment

begin_comment
comment|/// Otherwise, we register the analysis returned by calling \c PassBuilder(),
end_comment

begin_comment
comment|/// and this function returns true.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// (Note: Although the return value of this function indicates whether or not
end_comment

begin_comment
comment|/// an analysis was previously registered, there intentionally isn't a way to
end_comment

begin_comment
comment|/// query this directly.  Instead, you should just register all the analyses
end_comment

begin_comment
comment|/// you might want and let this class run them lazily.  This idiom lets us
end_comment

begin_comment
comment|/// minimize the number of times we have to look up analyses in our
end_comment

begin_comment
comment|/// hashtable.)
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
argument|PassBuilderT&&PassBuilder
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
operator|,
name|PreservedAnalyses
operator|,
name|Invalidator
operator|,
name|ExtraArgTs
operator|...
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
comment|/// Note that the analysis result can disregard invalidation, if it determines
end_comment

begin_comment
comment|/// it is in fact still valid.
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
comment|/// \brief Invalidate cached analyses for an IR unit.
comment|///
comment|/// Walk through all of the analyses pertaining to this unit of IR and
comment|/// invalidate them, unless they are preserved by the PreservedAnalyses set.
name|void
name|invalidate
argument_list|(
argument|IRUnitT&IR
argument_list|,
argument|const PreservedAnalyses&PA
argument_list|)
block|{
comment|// We're done if all analyses on this IR unit are preserved.
if|if
condition|(
name|PA
operator|.
name|allAnalysesInSetPreserved
operator|<
name|AllAnalysesOn
operator|<
name|IRUnitT
operator|>>
operator|(
operator|)
condition|)
return|return;
end_expr_stmt

begin_if
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
end_if

begin_comment
comment|// Track whether each analysis's result is invalidated in
end_comment

begin_comment
comment|// IsResultInvalidated.
end_comment

begin_expr_stmt
name|SmallDenseMap
operator|<
name|AnalysisKey
operator|*
operator|,
name|bool
operator|,
literal|8
operator|>
name|IsResultInvalidated
expr_stmt|;
end_expr_stmt

begin_function_decl
name|Invalidator
name|Inv
parameter_list|(
name|IsResultInvalidated
parameter_list|,
name|AnalysisResults
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
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
end_decl_stmt

begin_for
for|for
control|(
name|auto
operator|&
name|AnalysisResultPair
operator|:
name|ResultsList
control|)
block|{
comment|// This is basically the same thing as Invalidator::invalidate, but we
comment|// can't call it here because we're operating on the type-erased result.
comment|// Moreover if we instead called invalidate() directly, it would do an
comment|// unnecessary look up in ResultsList.
name|AnalysisKey
modifier|*
name|ID
init|=
name|AnalysisResultPair
operator|.
name|first
decl_stmt|;
name|auto
operator|&
name|Result
operator|=
operator|*
name|AnalysisResultPair
operator|.
name|second
expr_stmt|;
name|auto
name|IMapI
init|=
name|IsResultInvalidated
operator|.
name|find
argument_list|(
name|ID
argument_list|)
decl_stmt|;
if|if
condition|(
name|IMapI
operator|!=
name|IsResultInvalidated
operator|.
name|end
argument_list|()
condition|)
comment|// This result was already handled via the Invalidator.
continue|continue;
comment|// Try to invalidate the result, giving it the Invalidator so it can
comment|// recursively query for any dependencies it has and record the result.
comment|// Note that we cannot reuse 'IMapI' here or pre-insert the ID, as
comment|// Result.invalidate may insert things into the map, invalidating our
comment|// iterator.
name|bool
name|Inserted
init|=
name|IsResultInvalidated
operator|.
name|insert
argument_list|(
block|{
name|ID
block|,
name|Result
operator|.
name|invalidate
argument_list|(
argument|IR
argument_list|,
argument|PA
argument_list|,
argument|Inv
argument_list|)
block|}
argument_list|)
operator|.
name|second
decl_stmt|;
operator|(
name|void
operator|)
name|Inserted
expr_stmt|;
name|assert
argument_list|(
name|Inserted
operator|&&
literal|"Should never have already inserted this ID, likely "
literal|"indicates a cycle!"
argument_list|)
expr_stmt|;
block|}
end_for

begin_comment
comment|// Now erase the results that were marked above as invalidated.
end_comment

begin_if
if|if
condition|(
operator|!
name|IsResultInvalidated
operator|.
name|empty
argument_list|()
condition|)
block|{
for|for
control|(
name|auto
name|I
init|=
name|ResultsList
operator|.
name|begin
argument_list|()
init|,
name|E
init|=
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
name|AnalysisKey
modifier|*
name|ID
init|=
name|I
operator|->
name|first
decl_stmt|;
if|if
condition|(
operator|!
name|IsResultInvalidated
operator|.
name|lookup
argument_list|(
name|ID
argument_list|)
condition|)
block|{
operator|++
name|I
expr_stmt|;
continue|continue;
block|}
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
name|lookUpPass
argument_list|(
name|ID
argument_list|)
operator|.
name|name
argument_list|()
operator|<<
literal|"\n"
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
name|AnalysisResults
operator|.
name|erase
argument_list|(
block|{
name|ID
block|,
operator|&
name|IR
block|}
argument_list|)
expr_stmt|;
block|}
block|}
end_if

begin_if
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
end_if

begin_comment
unit|}  private:
comment|/// \brief Look up a registered analysis pass.
end_comment

begin_function
name|PassConceptT
modifier|&
name|lookUpPass
parameter_list|(
name|AnalysisKey
modifier|*
name|ID
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
name|ID
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
comment|/// \brief Look up a registered analysis pass.
end_comment

begin_decl_stmt
specifier|const
name|PassConceptT
modifier|&
name|lookUpPass
argument_list|(
name|AnalysisKey
operator|*
name|ID
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
name|ID
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

begin_comment
comment|/// \brief Get an analysis result, running the pass if necessary.
end_comment

begin_function
name|ResultConceptT
modifier|&
name|getResultImpl
parameter_list|(
name|AnalysisKey
modifier|*
name|ID
parameter_list|,
name|IRUnitT
modifier|&
name|IR
parameter_list|,
name|ExtraArgTs
modifier|...
name|ExtraArgs
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
argument|std::make_pair(ID,&IR)
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
name|lookUpPass
argument_list|(
name|ID
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
name|ID
argument_list|,
name|P
operator|.
name|run
argument_list|(
name|IR
argument_list|,
operator|*
name|this
argument_list|,
name|ExtraArgs
operator|...
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
block|{
name|ID
block|,
operator|&
name|IR
block|}
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
name|AnalysisKey
operator|*
name|ID
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
block|{
name|ID
block|,
operator|&
name|IR
block|}
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
name|AnalysisKey
modifier|*
name|ID
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
block|{
name|ID
block|,
operator|&
name|IR
block|}
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
name|lookUpPass
argument_list|(
name|ID
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
comment|/// \brief Map type from module analysis pass ID to pass concept pointer.
end_comment

begin_typedef
typedef|typedef
name|DenseMap
operator|<
name|AnalysisKey
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
comment|/// \brief Indicates whether we log to \c llvm::dbgs().
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
operator|,
name|typename
operator|...
name|ExtraArgTs
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
name|InnerAM
argument_list|)
operator|:
name|InnerAM
argument_list|(
argument|&InnerAM
argument_list|)
block|{}
name|Result
argument_list|(
name|Result
operator|&&
name|Arg
argument_list|)
operator|:
name|InnerAM
argument_list|(
argument|std::move(Arg.InnerAM)
argument_list|)
block|{
comment|// We have to null out the analysis manager in the moved-from state
comment|// because we are taking ownership of the responsibilty to clear the
comment|// analysis state.
name|Arg
operator|.
name|InnerAM
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
name|InnerAM
operator|=
name|RHS
operator|.
name|InnerAM
block|;
comment|// We have to null out the analysis manager in the moved-from state
comment|// because we are taking ownership of the responsibilty to clear the
comment|// analysis state.
name|RHS
operator|.
name|InnerAM
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
comment|// InnerAM is cleared in a moved from state where there is nothing to do.
if|if
condition|(
operator|!
name|InnerAM
condition|)
return|return;
comment|// Clear out the analysis manager if we're being destroyed -- it means we
comment|// didn't even see an invalidate call when we got invalidated.
name|InnerAM
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
name|InnerAM
return|;
block|}
end_expr_stmt

begin_comment
comment|/// \brief Handler for invalidation of the outer IR unit.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// If this analysis itself is preserved, then we assume that the set of \c
end_comment

begin_comment
comment|/// IR units that the inner analysis manager controls hasn't changed and
end_comment

begin_comment
comment|/// thus we don't need to invalidate *all* cached data associated with any
end_comment

begin_comment
comment|/// \c IRUnitT* in the \c AnalysisManagerT.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// Regardless of whether this analysis is marked as preserved, all of the
end_comment

begin_comment
comment|/// analyses in the \c AnalysisManagerT are potentially invalidated (for
end_comment

begin_comment
comment|/// the relevant inner set of their IR units) based on the set of preserved
end_comment

begin_comment
comment|/// analyses.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// Because this needs to understand the mapping from one IR unit to an
end_comment

begin_comment
comment|/// inner IR unit, this method isn't defined in the primary template.
end_comment

begin_comment
comment|/// Instead, each specialization of this template will need to provide an
end_comment

begin_comment
comment|/// explicit specialization of this method to handle that particular pair
end_comment

begin_comment
comment|/// of IR unit and inner AnalysisManagerT.
end_comment

begin_decl_stmt
name|bool
name|invalidate
argument_list|(
name|IRUnitT
operator|&
name|IR
argument_list|,
specifier|const
name|PreservedAnalyses
operator|&
name|PA
argument_list|,
name|typename
name|AnalysisManager
operator|<
name|IRUnitT
argument_list|,
name|ExtraArgTs
operator|...
operator|>
operator|::
name|Invalidator
operator|&
name|Inv
argument_list|)
decl_stmt|;
end_decl_stmt

begin_label
name|private
label|:
end_label

begin_decl_stmt
name|AnalysisManagerT
modifier|*
name|InnerAM
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
name|InnerAM
argument_list|)
operator|:
name|InnerAM
argument_list|(
argument|&InnerAM
argument_list|)
block|{}
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
argument_list|(
argument|IRUnitT&IR
argument_list|,
argument|AnalysisManager<IRUnitT
argument_list|,
argument|ExtraArgTs...>&AM
argument_list|,
argument|ExtraArgTs...
argument_list|)
block|{
return|return
name|Result
argument_list|(
operator|*
name|InnerAM
argument_list|)
return|;
block|}
end_expr_stmt

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
name|AnalysisKey
name|Key
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|AnalysisManagerT
modifier|*
name|InnerAM
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
operator|,
name|typename
operator|...
name|ExtraArgTs
operator|>
name|AnalysisKey
name|InnerAnalysisManagerProxy
operator|<
name|AnalysisManagerT
operator|,
name|IRUnitT
operator|,
name|ExtraArgTs
operator|...
operator|>
operator|::
name|Key
expr_stmt|;
end_expr_stmt

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
comment|/// Specialization of the invalidate method for the \c
end_comment

begin_comment
comment|/// FunctionAnalysisManagerModuleProxy's result.
end_comment

begin_expr_stmt
name|template
operator|<
operator|>
name|bool
name|FunctionAnalysisManagerModuleProxy
operator|::
name|Result
operator|::
name|invalidate
argument_list|(
name|Module
operator|&
name|M
argument_list|,
specifier|const
name|PreservedAnalyses
operator|&
name|PA
argument_list|,
name|ModuleAnalysisManager
operator|::
name|Invalidator
operator|&
name|Inv
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|// Ensure the \c FunctionAnalysisManagerModuleProxy is provided as an extern
end_comment

begin_comment
comment|// template.
end_comment

begin_extern
extern|extern template class InnerAnalysisManagerProxy<FunctionAnalysisManager
operator|,
extern|Module>;
end_extern

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
comment|/// The invalidation provided by this proxy involves tracking when an
end_comment

begin_comment
comment|/// invalidation event in the outer analysis manager needs to trigger an
end_comment

begin_comment
comment|/// invalidation of a particular analysis on this IR unit.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// Because outer analyses aren't invalidated while these IR units are being
end_comment

begin_comment
comment|/// precessed, we have to register and handle these as deferred invalidation
end_comment

begin_comment
comment|/// events.
end_comment

begin_expr_stmt
name|template
operator|<
name|typename
name|AnalysisManagerT
operator|,
name|typename
name|IRUnitT
operator|,
name|typename
operator|...
name|ExtraArgTs
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
argument_list|,
argument|const PreservedAnalyses&
argument_list|,
argument|typename AnalysisManager<IRUnitT
argument_list|,
argument|ExtraArgTs...>::Invalidator&
argument_list|)
block|{
return|return
name|false
return|;
block|}
comment|/// Register a deferred invalidation event for when the outer analysis
comment|/// manager processes its invalidations.
name|template
operator|<
name|typename
name|OuterAnalysisT
operator|,
name|typename
name|InvalidatedAnalysisT
operator|>
name|void
name|registerOuterAnalysisInvalidation
argument_list|()
block|{
name|AnalysisKey
operator|*
name|OuterID
operator|=
name|OuterAnalysisT
operator|::
name|ID
argument_list|()
block|;
name|AnalysisKey
operator|*
name|InvalidatedID
operator|=
name|InvalidatedAnalysisT
operator|::
name|ID
argument_list|()
block|;
name|auto
operator|&
name|InvalidatedIDList
operator|=
name|OuterAnalysisInvalidationMap
index|[
name|OuterID
index|]
block|;
comment|// Note, this is a linear scan. If we end up with large numbers of
comment|// analyses that all trigger invalidation on the same outer analysis,
comment|// this entire system should be changed to some other deterministic
comment|// data structure such as a `SetVector` of a pair of pointers.
name|auto
name|InvalidatedIt
operator|=
name|std
operator|::
name|find
argument_list|(
name|InvalidatedIDList
operator|.
name|begin
argument_list|()
argument_list|,
name|InvalidatedIDList
operator|.
name|end
argument_list|()
argument_list|,
name|InvalidatedID
argument_list|)
block|;
if|if
condition|(
name|InvalidatedIt
operator|==
name|InvalidatedIDList
operator|.
name|end
argument_list|()
condition|)
name|InvalidatedIDList
operator|.
name|push_back
argument_list|(
name|InvalidatedID
argument_list|)
expr_stmt|;
block|}
end_expr_stmt

begin_comment
comment|/// Access the map from outer analyses to deferred invalidation requiring
end_comment

begin_comment
comment|/// analyses.
end_comment

begin_expr_stmt
specifier|const
name|SmallDenseMap
operator|<
name|AnalysisKey
operator|*
operator|,
name|TinyPtrVector
operator|<
name|AnalysisKey
operator|*
operator|>
operator|,
literal|2
operator|>
operator|&
name|getOuterInvalidations
argument_list|()
specifier|const
block|{
return|return
name|OuterAnalysisInvalidationMap
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

begin_comment
comment|/// A map from an outer analysis ID to the set of this IR-unit's analyses
end_comment

begin_comment
comment|/// which need to be invalidated.
end_comment

begin_expr_stmt
name|SmallDenseMap
operator|<
name|AnalysisKey
operator|*
operator|,
name|TinyPtrVector
operator|<
name|AnalysisKey
operator|*
operator|>
operator|,
literal|2
operator|>
name|OuterAnalysisInvalidationMap
expr_stmt|;
end_expr_stmt

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
comment|/// \brief Run the analysis pass and create our proxy result object.
comment|/// Nothing to see here, it just forwards the \c AM reference into the
comment|/// result.
name|Result
name|run
argument_list|(
argument|IRUnitT&
argument_list|,
argument|AnalysisManager<IRUnitT
argument_list|,
argument|ExtraArgTs...>&
argument_list|,
argument|ExtraArgTs...
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
end_expr_stmt

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
name|AnalysisKey
name|Key
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
operator|,
name|typename
operator|...
name|ExtraArgTs
operator|>
name|AnalysisKey
name|OuterAnalysisManagerProxy
operator|<
name|AnalysisManagerT
operator|,
name|IRUnitT
operator|,
name|ExtraArgTs
operator|...
operator|>
operator|::
name|Key
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
comment|// directly handle the function analysis manager's invalidation here.
name|FAM
operator|.
name|invalidate
argument_list|(
name|F
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
comment|// By definition we preserve the proxy. We also preserve all analyses on
comment|// Function units. This precludes *any* invalidation of function analyses
comment|// by the proxy, but that's OK because we've taken care to invalidate
comment|// analyses in the function analysis manager incrementally above.
name|PA
operator|.
name|preserveSet
operator|<
name|AllAnalysesOn
operator|<
name|Function
operator|>>
operator|(
operator|)
block|;
name|PA
operator|.
name|preserve
operator|<
name|FunctionAnalysisManagerModuleProxy
operator|>
operator|(
operator|)
block|;
return|return
name|PA
return|;
block|}
end_expr_stmt

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
comment|/// If there are extra arguments at the pass's run level there may also be
end_comment

begin_comment
comment|/// extra arguments to the analysis manager's \c getResult routine. We can't
end_comment

begin_comment
comment|/// guess how to effectively map the arguments from one to the other, and so
end_comment

begin_comment
comment|/// this specialization just ignores them.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// Specific patterns of run-method extra arguments and analysis manager extra
end_comment

begin_comment
comment|/// arguments will have to be defined as appropriate specializations.
end_comment

begin_expr_stmt
name|template
operator|<
name|typename
name|AnalysisT
operator|,
name|typename
name|IRUnitT
operator|,
name|typename
name|AnalysisManagerT
operator|=
name|AnalysisManager
operator|<
name|IRUnitT
operator|>
operator|,
name|typename
operator|...
name|ExtraArgTs
operator|>
expr|struct
name|RequireAnalysisPass
operator|:
name|PassInfoMixin
operator|<
name|RequireAnalysisPass
operator|<
name|AnalysisT
operator|,
name|IRUnitT
operator|,
name|AnalysisManagerT
operator|,
name|ExtraArgTs
operator|...
operator|>>
block|{
comment|/// \brief Run this pass over some unit of IR.
comment|///
comment|/// This pass can be run over any unit of IR and use any analysis manager
comment|/// provided they satisfy the basic API requirements. When this pass is
comment|/// created, these methods can be instantiated to satisfy whatever the
comment|/// context requires.
name|PreservedAnalyses
name|run
argument_list|(
argument|IRUnitT&Arg
argument_list|,
argument|AnalysisManagerT&AM
argument_list|,
argument|ExtraArgTs&&... Args
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
operator|,
name|std
operator|::
name|forward
operator|<
name|ExtraArgTs
operator|>
operator|(
name|Args
operator|)
operator|...
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
block|,
name|typename
name|AnalysisManagerT
block|,
name|typename
operator|...
name|ExtraArgTs
operator|>
name|PreservedAnalyses
name|run
argument_list|(
argument|IRUnitT&Arg
argument_list|,
argument|AnalysisManagerT&AM
argument_list|,
argument|ExtraArgTs&&...
argument_list|)
block|{
name|auto
name|PA
operator|=
name|PreservedAnalyses
operator|::
name|all
argument_list|()
block|;
name|PA
operator|.
name|abandon
operator|<
name|AnalysisT
operator|>
operator|(
operator|)
block|;
return|return
name|PA
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
block|,
name|typename
name|AnalysisManagerT
block|,
name|typename
operator|...
name|ExtraArgTs
operator|>
name|PreservedAnalyses
name|run
argument_list|(
argument|IRUnitT&
argument_list|,
argument|AnalysisManagerT&
argument_list|,
argument|ExtraArgTs&&...
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
block|;
comment|/// A utility pass template that simply runs another pass multiple times.
comment|///
comment|/// This can be useful when debugging or testing passes. It also serves as an
comment|/// example of how to extend the pass manager in ways beyond composition.
name|template
operator|<
name|typename
name|PassT
operator|>
name|class
name|RepeatedPass
operator|:
name|public
name|PassInfoMixin
operator|<
name|RepeatedPass
operator|<
name|PassT
operator|>>
block|{
name|public
operator|:
name|RepeatedPass
argument_list|(
argument|int Count
argument_list|,
argument|PassT P
argument_list|)
operator|:
name|Count
argument_list|(
name|Count
argument_list|)
block|,
name|P
argument_list|(
argument|std::move(P)
argument_list|)
block|{}
name|template
operator|<
name|typename
name|IRUnitT
block|,
name|typename
name|AnalysisManagerT
block|,
name|typename
operator|...
name|Ts
operator|>
name|PreservedAnalyses
name|run
argument_list|(
argument|IRUnitT&Arg
argument_list|,
argument|AnalysisManagerT&AM
argument_list|,
argument|Ts&&... Args
argument_list|)
block|{
name|auto
name|PA
operator|=
name|PreservedAnalyses
operator|::
name|all
argument_list|()
block|;
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|<
name|Count
condition|;
operator|++
name|i
control|)
name|PA
operator|.
name|intersect
argument_list|(
name|P
operator|.
name|run
argument_list|(
name|Arg
argument_list|,
name|AM
argument_list|,
name|std
operator|::
name|forward
operator|<
name|Ts
operator|>
operator|(
name|Args
operator|)
operator|...
argument_list|)
argument_list|)
expr_stmt|;
return|return
name|PA
return|;
block|}
name|private
operator|:
name|int
name|Count
block|;
name|PassT
name|P
block|; }
decl_stmt|;
end_decl_stmt

begin_expr_stmt
name|template
operator|<
name|typename
name|PassT
operator|>
name|RepeatedPass
operator|<
name|PassT
operator|>
name|createRepeatedPass
argument_list|(
argument|int Count
argument_list|,
argument|PassT P
argument_list|)
block|{
return|return
name|RepeatedPass
operator|<
name|PassT
operator|>
operator|(
name|Count
operator|,
name|std
operator|::
name|move
argument_list|(
name|P
argument_list|)
operator|)
return|;
block|}
end_expr_stmt

begin_endif
unit|}
endif|#
directive|endif
end_endif

end_unit

