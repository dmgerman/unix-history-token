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
file|"llvm/ADT/StringRef.h"
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
name|AnalysisManager
expr_stmt|;
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
name|IRUnitT
operator|&
name|IR
argument_list|,
name|AnalysisManager
operator|<
name|IRUnitT
operator|>
operator|*
name|AM
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
comment|/// accepting an \c AnalysisManager<IRUnitT>.
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
operator|&
argument_list|,
name|AnalysisManager
operator|<
name|IRUnitT
operator|>
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
comment|/// \c run method also accepts an \c AnalysisManager<IRUnitT>*, we pass it
comment|/// along.
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
operator|=
name|PreservedAnalyses
operator|,
name|bool
name|AcceptsAnalysisManager
operator|=
name|PassRunAcceptsAnalysisManager
operator|<
name|IRUnitT
operator|,
name|PassT
operator|,
name|PreservedAnalysesT
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
name|PassT
operator|,
name|typename
name|PreservedAnalysesT
operator|>
expr|struct
name|PassModel
operator|<
name|IRUnitT
operator|,
name|PassT
operator|,
name|PreservedAnalysesT
operator|,
name|true
operator|>
operator|:
name|PassConcept
operator|<
name|IRUnitT
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
argument|AnalysisManager<IRUnitT> *AM
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
name|PassT
operator|,
name|typename
name|PreservedAnalysesT
operator|>
expr|struct
name|PassModel
operator|<
name|IRUnitT
operator|,
name|PassT
operator|,
name|PreservedAnalysesT
operator|,
name|false
operator|>
operator|:
name|PassConcept
operator|<
name|IRUnitT
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
argument|AnalysisManager<IRUnitT> *AM
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
name|IRUnitT
operator|&
name|IR
argument_list|,
specifier|const
name|PreservedAnalyses
operator|&
name|PA
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
operator|&
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
name|typename
name|PreservedAnalysesT
operator|=
name|PreservedAnalyses
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
operator|,
name|typename
name|PreservedAnalysesT
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
argument|IRUnitT&
argument_list|,
argument|const PreservedAnalysesT&PA
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
operator|,
name|typename
name|PreservedAnalysesT
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
argument|IRUnitT&IR
argument_list|,
argument|const PreservedAnalysesT&PA
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
name|IRUnitT
operator|&
name|IR
argument_list|,
name|AnalysisManager
operator|<
name|IRUnitT
operator|>
operator|*
name|AM
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
name|PassT
operator|,
name|bool
name|AcceptsAnalysisManager
operator|=
name|PassRunAcceptsAnalysisManager
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
name|PassT
operator|>
expr|struct
name|AnalysisPassModel
operator|<
name|IRUnitT
operator|,
name|PassT
operator|,
name|true
operator|>
operator|:
name|AnalysisPassConcept
operator|<
name|IRUnitT
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
argument|IRUnitT&IR
argument_list|,
argument|AnalysisManager<IRUnitT> *AM
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

begin_comment
comment|/// \brief The model delegates to a static \c PassT::name method.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// The returned string ref must point to constant immutable data!
end_comment

begin_function
name|StringRef
name|name
parameter_list|()
function|override
block|{
return|return
name|PassT
operator|::
name|name
argument_list|()
return|;
block|}
end_function

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
name|PassT
operator|>
expr|struct
name|AnalysisPassModel
operator|<
name|IRUnitT
operator|,
name|PassT
operator|,
name|false
operator|>
operator|:
name|AnalysisPassConcept
operator|<
name|IRUnitT
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
argument|IRUnitT&IR
argument_list|,
argument|AnalysisManager<IRUnitT> *
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

begin_comment
comment|/// \brief The model delegates to a static \c PassT::name method.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// The returned string ref must point to constant immutable data!
end_comment

begin_function
name|StringRef
name|name
parameter_list|()
function|override
block|{
return|return
name|PassT
operator|::
name|name
argument_list|()
return|;
block|}
end_function

begin_decl_stmt
name|PassT
name|Pass
decl_stmt|;
end_decl_stmt

begin_comment
unit|};  }
comment|// End namespace detail
end_comment

begin_endif
unit|}
endif|#
directive|endif
end_endif

end_unit

