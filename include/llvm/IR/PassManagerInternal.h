begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- PassManager internal APIs and implementation details -----*- C++ -*-===//
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
comment|/// This header provides internal APIs and implementation details used by the
end_comment

begin_comment
comment|/// pass management interfaces exposed in PassManager.h. To understand more
end_comment

begin_comment
comment|/// context of why these particular interfaces are needed, see that header
end_comment

begin_comment
comment|/// file. None of these APIs should be used elsewhere.
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
name|LLVM_IR_PASSMANAGERINTERNAL_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_IR_PASSMANAGERINTERNAL_H
end_define

begin_include
include|#
directive|include
file|"llvm/ADT/STLExtras.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/StringRef.h"
end_include

begin_include
include|#
directive|include
file|<memory>
end_include

begin_include
include|#
directive|include
file|<utility>
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|template
operator|<
name|typename
name|IRUnitT
operator|>
name|class
name|AllAnalysesOn
expr_stmt|;
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
name|class
name|Invalidator
decl_stmt|;
name|class
name|PreservedAnalyses
decl_stmt|;
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
operator|,
name|typename
operator|...
name|ExtraArgTs
operator|>
expr|struct
name|PassConcept
block|{
comment|// Boiler plate necessary for the container of derived classes.
name|virtual
operator|~
name|PassConcept
argument_list|()
operator|=
expr|default
block|;
comment|/// \brief The polymorphic API which runs the pass over a given IR entity.
comment|///
comment|/// Note that actual pass object can omit the analysis manager argument if
comment|/// desired. Also that the analysis manager may be null if there is no
comment|/// analysis manager in the pass pipeline.
name|virtual
name|PreservedAnalyses
name|run
argument_list|(
name|IRUnitT
operator|&
name|IR
argument_list|,
name|AnalysisManagerT
operator|&
name|AM
argument_list|,
name|ExtraArgTs
operator|...
name|ExtraArgs
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
comment|/// \brief A template wrapper used to implement the polymorphic API.
comment|///
comment|/// Can be instantiated for any object which provides a \c run method accepting
comment|/// an \c IRUnitT& and an \c AnalysisManager<IRUnit>&. It requires the pass to
comment|/// be a copyable object.
name|template
operator|<
name|typename
name|IRUnitT
operator|,
name|typename
name|PassT
operator|,
name|typename
name|PreservedAnalysesT
operator|,
name|typename
name|AnalysisManagerT
operator|,
name|typename
operator|...
name|ExtraArgTs
operator|>
expr|struct
name|PassModel
operator|:
name|PassConcept
operator|<
name|IRUnitT
operator|,
name|AnalysisManagerT
operator|,
name|ExtraArgTs
operator|...
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
name|PreservedAnalysesT
name|run
argument_list|(
argument|IRUnitT&IR
argument_list|,
argument|AnalysisManagerT&AM
argument_list|,
argument|ExtraArgTs... ExtraArgs
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
argument_list|,
name|ExtraArgs
operator|...
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
operator|,
name|typename
name|PreservedAnalysesT
operator|,
name|typename
name|InvalidatorT
operator|>
expr|struct
name|AnalysisResultConcept
block|{
name|virtual
operator|~
name|AnalysisResultConcept
argument_list|()
operator|=
expr|default
block|;
comment|/// \brief Method to try and mark a result as invalid.
comment|///
comment|/// When the outer analysis manager detects a change in some underlying
comment|/// unit of the IR, it will call this method on all of the results cached.
comment|///
comment|/// \p PA is a set of preserved analyses which can be used to avoid
comment|/// invalidation because the pass which changed the underlying IR took care
comment|/// to update or preserve the analysis result in some way.
comment|///
comment|/// \p Inv is typically a \c AnalysisManager::Invalidator object that can be
comment|/// used by a particular analysis result to discover if other analyses
comment|/// results are also invalidated in the event that this result depends on
comment|/// them. See the documentation in the \c AnalysisManager for more details.
comment|///
comment|/// \returns true if the result is indeed invalid (the default).
name|virtual
name|bool
name|invalidate
argument_list|(
name|IRUnitT
operator|&
name|IR
argument_list|,
specifier|const
name|PreservedAnalysesT
operator|&
name|PA
argument_list|,
name|InvalidatorT
operator|&
name|Inv
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
name|EnabledType
typedef|;
block|struct
name|DisabledType
block|{
name|char
name|a
block|,
name|b
block|;   }
expr_stmt|;
comment|// Purely to help out MSVC which fails to disable the below specialization,
comment|// explicitly enable using the result type's invalidate routine if we can
comment|// successfully call that routine.
name|template
operator|<
name|typename
name|T
operator|>
expr|struct
name|Nonce
block|{
typedef|typedef
name|EnabledType
name|Type
typedef|;
block|}
empty_stmt|;
name|template
operator|<
name|typename
name|T
operator|>
specifier|static
name|typename
name|Nonce
operator|<
name|decltype
argument_list|(
name|std
operator|::
name|declval
operator|<
name|T
operator|>
operator|(
operator|)
operator|.
name|invalidate
argument_list|(
name|std
operator|::
name|declval
operator|<
name|IRUnitT
operator|&
operator|>
operator|(
operator|)
argument_list|,
name|std
operator|::
name|declval
operator|<
name|PreservedAnalyses
operator|>
operator|(
operator|)
argument_list|)
argument_list|)
operator|>
operator|::
name|Type
name|check
argument_list|(
name|rank
operator|<
literal|2
operator|>
argument_list|)
expr_stmt|;
comment|// First we define an overload that can only be taken if there is no
comment|// invalidate member. We do this by taking the address of an invalidate
comment|// member in an adjacent base class of a derived class. This would be
comment|// ambiguous if there were an invalidate member in the result type.
name|template
operator|<
name|typename
name|T
operator|,
name|typename
name|U
operator|>
specifier|static
name|DisabledType
name|NonceFunction
argument_list|(
argument|T U::*
argument_list|)
expr_stmt|;
struct|struct
name|CheckerBase
block|{
name|int
name|invalidate
decl_stmt|;
block|}
struct|;
name|template
operator|<
name|typename
name|T
operator|>
expr|struct
name|Checker
operator|:
name|CheckerBase
operator|,
name|T
block|{}
expr_stmt|;
name|template
operator|<
name|typename
name|T
operator|>
specifier|static
name|decltype
argument_list|(
argument|NonceFunction(&Checker<T>::invalidate)
argument_list|)
name|check
argument_list|(
name|rank
operator|<
literal|1
operator|>
argument_list|)
expr_stmt|;
comment|// Now we have the fallback that will only be reached when there is an
comment|// invalidate member, and enables the trait.
name|template
operator|<
name|typename
name|T
operator|>
specifier|static
name|EnabledType
name|check
argument_list|(
name|rank
operator|<
literal|0
operator|>
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
name|check
operator|<
name|ResultT
operator|>
operator|(
name|rank
operator|<
literal|2
operator|>
operator|(
operator|)
operator|)
argument_list|)
operator|==
expr|sizeof
operator|(
name|EnabledType
operator|)
block|}
enum|;
block|}
empty_stmt|;
comment|/// \brief Wrapper to model the analysis result concept.
comment|///
comment|/// By default, this will implement the invalidate method with a trivial
comment|/// implementation so that the actual analysis result doesn't need to provide
comment|/// an invalidation handler. It is only selected when the invalidation handler
comment|/// is not part of the ResultT's interface.
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
name|typename
name|PreservedAnalysesT
operator|,
name|typename
name|InvalidatorT
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
comment|/// \brief Specialization of \c AnalysisResultModel which provides the default
comment|/// invalidate functionality.
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
name|typename
name|PreservedAnalysesT
operator|,
name|typename
name|InvalidatorT
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
name|PreservedAnalysesT
operator|,
name|InvalidatorT
operator|,
name|false
operator|>
operator|:
name|AnalysisResultConcept
operator|<
name|IRUnitT
operator|,
name|PreservedAnalysesT
operator|,
name|InvalidatorT
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
argument|IRUnitT&
argument_list|,
argument|const PreservedAnalysesT&PA
argument_list|,
argument|InvalidatorT&
argument_list|)
name|override
block|{
name|auto
name|PAC
operator|=
name|PA
operator|.
name|template
name|getChecker
operator|<
name|PassT
operator|>
operator|(
operator|)
block|;
return|return
operator|!
name|PAC
operator|.
name|preserved
argument_list|()
operator|&&
operator|!
name|PAC
operator|.
name|template
name|preservedSet
operator|<
name|AllAnalysesOn
operator|<
name|IRUnitT
operator|>>
operator|(
operator|)
return|;
block|}
name|ResultT
name|Result
block|; }
expr_stmt|;
comment|/// \brief Specialization of \c AnalysisResultModel which delegates invalidate
comment|/// handling to \c ResultT.
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
name|typename
name|PreservedAnalysesT
operator|,
name|typename
name|InvalidatorT
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
name|PreservedAnalysesT
operator|,
name|InvalidatorT
operator|,
name|true
operator|>
operator|:
name|AnalysisResultConcept
operator|<
name|IRUnitT
operator|,
name|PreservedAnalysesT
operator|,
name|InvalidatorT
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
argument|IRUnitT&IR
argument_list|,
argument|const PreservedAnalysesT&PA
argument_list|,
argument|InvalidatorT&Inv
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
argument_list|,
name|Inv
argument_list|)
return|;
block|}
name|ResultT
name|Result
block|; }
expr_stmt|;
comment|/// \brief Abstract concept of an analysis pass.
comment|///
comment|/// This concept is parameterized over the IR unit that it can run over and
comment|/// produce an analysis result.
name|template
operator|<
name|typename
name|IRUnitT
operator|,
name|typename
name|PreservedAnalysesT
operator|,
name|typename
name|InvalidatorT
operator|,
name|typename
operator|...
name|ExtraArgTs
operator|>
expr|struct
name|AnalysisPassConcept
block|{
name|virtual
operator|~
name|AnalysisPassConcept
argument_list|()
operator|=
expr|default
block|;
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
block|,
name|PreservedAnalysesT
block|,
name|InvalidatorT
operator|>>
name|run
argument_list|(
name|IRUnitT
operator|&
name|IR
argument_list|,
name|AnalysisManager
operator|<
name|IRUnitT
argument_list|,
name|ExtraArgTs
operator|...
operator|>
operator|&
name|AM
argument_list|,
name|ExtraArgTs
operator|...
name|ExtraArgs
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
comment|/// \brief Wrapper to model the analysis pass concept.
comment|///
comment|/// Can wrap any type which implements a suitable \c run method. The method
comment|/// must accept an \c IRUnitT& and an \c AnalysisManager<IRUnitT>& as arguments
comment|/// and produce an object which can be wrapped in a \c AnalysisResultModel.
name|template
operator|<
name|typename
name|IRUnitT
operator|,
name|typename
name|PassT
operator|,
name|typename
name|PreservedAnalysesT
operator|,
name|typename
name|InvalidatorT
operator|,
name|typename
operator|...
name|ExtraArgTs
operator|>
expr|struct
name|AnalysisPassModel
operator|:
name|AnalysisPassConcept
operator|<
name|IRUnitT
operator|,
name|PreservedAnalysesT
operator|,
name|InvalidatorT
operator|,
name|ExtraArgTs
operator|...
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
comment|// FIXME: Replace PassT::Result with type traits when we use C++11.
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
operator|,
name|PreservedAnalysesT
operator|,
name|InvalidatorT
operator|>
name|ResultModelT
expr_stmt|;
comment|/// \brief The model delegates to the \c PassT::run method.
comment|///
comment|/// The return is wrapped in an \c AnalysisResultModel.
name|std
operator|::
name|unique_ptr
operator|<
name|AnalysisResultConcept
operator|<
name|IRUnitT
operator|,
name|PreservedAnalysesT
operator|,
name|InvalidatorT
operator|>>
name|run
argument_list|(
argument|IRUnitT&IR
argument_list|,
argument|AnalysisManager<IRUnitT
argument_list|,
argument|ExtraArgTs...>&AM
argument_list|,
argument|ExtraArgTs... ExtraArgs
argument_list|)
name|override
block|{
return|return
name|llvm
operator|::
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
argument_list|,
name|ExtraArgs
operator|...
argument_list|)
operator|)
return|;
block|}
comment|/// \brief The model delegates to a static \c PassT::name method.
comment|///
comment|/// The returned string ref must point to constant immutable data!
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
expr_stmt|;
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
unit|}
comment|// end namespace detail
end_comment

begin_comment
unit|}
comment|// end namespace llvm
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// LLVM_IR_PASSMANAGERINTERNAL_H
end_comment

end_unit

