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

begin_include
include|#
directive|include
file|"llvm/ADT/DenseMap.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/polymorphic_ptr.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/type_traits.h"
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
file|<list>
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
comment|/// \brief Implementation details of the pass manager interfaces.
name|namespace
name|detail
block|{
comment|/// \brief Template for the abstract base class used to dispatch
comment|/// polymorphically over pass objects.
name|template
operator|<
name|typename
name|T
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
name|virtual
name|PassConcept
operator|*
name|clone
argument_list|()
operator|=
literal|0
block|;
comment|/// \brief The polymorphic API which runs the pass over a given IR entity.
name|virtual
name|bool
name|run
argument_list|(
argument|T Arg
argument_list|)
operator|=
literal|0
block|; }
expr_stmt|;
comment|/// \brief A template wrapper used to implement the polymorphic API.
comment|///
comment|/// Can be instantiated for any object which provides a \c run method
comment|/// accepting a \c T. It requires the pass to be a copyable
comment|/// object.
name|template
operator|<
name|typename
name|T
operator|,
name|typename
name|PassT
operator|>
expr|struct
name|PassModel
operator|:
name|PassConcept
operator|<
name|T
operator|>
block|{
name|PassModel
argument_list|(
argument|PassT Pass
argument_list|)
operator|:
name|Pass
argument_list|(
argument|llvm_move(Pass)
argument_list|)
block|{}
name|virtual
name|PassModel
operator|*
name|clone
argument_list|()
block|{
return|return
name|new
name|PassModel
argument_list|(
name|Pass
argument_list|)
return|;
block|}
name|virtual
name|bool
name|run
argument_list|(
argument|T Arg
argument_list|)
block|{
return|return
name|Pass
operator|.
name|run
argument_list|(
name|Arg
argument_list|)
return|;
block|}
name|PassT
name|Pass
block|; }
expr_stmt|;
block|}
name|class
name|AnalysisManager
decl_stmt|;
name|class
name|ModulePassManager
block|{
name|public
label|:
name|ModulePassManager
argument_list|(
name|Module
operator|*
name|M
argument_list|,
name|AnalysisManager
operator|*
name|AM
operator|=
literal|0
argument_list|)
operator|:
name|M
argument_list|(
name|M
argument_list|)
operator|,
name|AM
argument_list|(
argument|AM
argument_list|)
block|{}
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
name|push_back
argument_list|(
argument|new ModulePassModel<ModulePassT>(llvm_move(Pass))
argument_list|)
block|;   }
name|void
name|run
argument_list|()
expr_stmt|;
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
name|PassT
operator|>
operator|(
name|Pass
operator|)
block|{}
block|}
expr_stmt|;
name|Module
modifier|*
name|M
decl_stmt|;
name|AnalysisManager
modifier|*
name|AM
decl_stmt|;
name|std
operator|::
name|vector
operator|<
name|polymorphic_ptr
operator|<
name|ModulePassConcept
operator|>
expr|>
name|Passes
expr_stmt|;
block|}
empty_stmt|;
name|class
name|FunctionPassManager
block|{
name|public
label|:
name|FunctionPassManager
argument_list|(
name|AnalysisManager
operator|*
name|AM
operator|=
literal|0
argument_list|)
operator|:
name|AM
argument_list|(
argument|AM
argument_list|)
block|{}
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
name|push_back
argument_list|(
argument|new FunctionPassModel<FunctionPassT>(llvm_move(Pass))
argument_list|)
block|;   }
name|bool
name|run
argument_list|(
name|Module
operator|*
name|M
argument_list|)
expr_stmt|;
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
name|PassT
operator|>
operator|(
name|Pass
operator|)
block|{}
block|}
expr_stmt|;
name|AnalysisManager
modifier|*
name|AM
decl_stmt|;
name|std
operator|::
name|vector
operator|<
name|polymorphic_ptr
operator|<
name|FunctionPassConcept
operator|>
expr|>
name|Passes
expr_stmt|;
block|}
empty_stmt|;
comment|/// \brief An analysis manager to coordinate and cache analyses run over
comment|/// a module.
comment|///
comment|/// The analysis manager is typically used by passes in a pass pipeline
comment|/// (consisting potentially of several individual pass managers) over a module
comment|/// of IR. It provides registration of available analyses, declaring
comment|/// requirements on support for specific analyses, running of an specific
comment|/// analysis over a specific unit of IR to compute an analysis result, and
comment|/// caching of the analysis results to reuse them across multiple passes.
comment|///
comment|/// It is the responsibility of callers to use the invalidation API to
comment|/// invalidate analysis results when the IR they correspond to changes. The
comment|/// \c ModulePassManager and \c FunctionPassManager do this automatically.
name|class
name|AnalysisManager
block|{
name|public
label|:
name|AnalysisManager
argument_list|(
name|Module
operator|*
name|M
argument_list|)
operator|:
name|M
argument_list|(
argument|M
argument_list|)
block|{}
comment|/// \brief Get the result of an analysis pass for this module.
comment|///
comment|/// If there is not a valid cached result in the manager already, this will
comment|/// re-run the analysis to produce a valid result.
comment|///
comment|/// The module passed in must be the same module as the analysis manager was
comment|/// constructed around.
name|template
operator|<
name|typename
name|PassT
operator|>
specifier|const
name|typename
name|PassT
operator|::
name|Result
operator|&
name|getResult
argument_list|(
argument|Module *M
argument_list|)
block|{
name|assert
argument_list|(
name|ModuleAnalysisPasses
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
specifier|const
name|AnalysisResultConcept
operator|<
name|Module
operator|>
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
name|M
argument_list|)
block|;
typedef|typedef
name|AnalysisResultModel
operator|<
name|Module
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
specifier|const
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
comment|/// \brief Get the result of an analysis pass for a function.
comment|///
comment|/// If there is not a valid cached result in the manager already, this will
comment|/// re-run the analysis to produce a valid result.
name|template
operator|<
name|typename
name|PassT
operator|>
specifier|const
name|typename
name|PassT
operator|::
name|Result
operator|&
name|getResult
argument_list|(
argument|Function *F
argument_list|)
block|{
name|assert
argument_list|(
name|FunctionAnalysisPasses
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
specifier|const
name|AnalysisResultConcept
operator|<
name|Function
operator|>
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
name|F
argument_list|)
block|;
typedef|typedef
name|AnalysisResultModel
operator|<
name|Function
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
specifier|const
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
comment|/// \brief Register an analysis pass with the manager.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This provides an initialized and set-up analysis pass to the
end_comment

begin_comment
comment|/// analysis
end_comment

begin_comment
comment|/// manager. Whomever is setting up analysis passes must use this to
end_comment

begin_comment
comment|/// populate
end_comment

begin_comment
comment|/// the manager with all of the analysis passes available.
end_comment

begin_expr_stmt
name|template
operator|<
name|typename
name|PassT
operator|>
name|void
name|registerAnalysisPass
argument_list|(
argument|PassT Pass
argument_list|)
block|{
name|registerAnalysisPassImpl
operator|<
name|PassT
operator|>
operator|(
name|llvm_move
argument_list|(
name|Pass
argument_list|)
operator|)
block|;   }
comment|/// \brief Invalidate a specific analysis pass for an IR module.
comment|///
comment|/// Note that the analysis result can disregard invalidation.
name|template
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
comment|/// \brief Invalidate a specific analysis pass for an IR function.
comment|///
comment|/// Note that the analysis result can disregard invalidation.
name|template
operator|<
name|typename
name|PassT
operator|>
name|void
name|invalidate
argument_list|(
argument|Function *F
argument_list|)
block|{
name|invalidateImpl
argument_list|(
name|PassT
operator|::
name|ID
argument_list|()
argument_list|,
name|F
argument_list|)
block|;   }
comment|/// \brief Invalidate analyses cached for an IR Module.
comment|///
comment|/// Note that specific analysis results can disregard invalidation by
comment|/// overriding their invalidate method.
comment|///
comment|/// The module must be the module this analysis manager was constructed
comment|/// around.
name|void
name|invalidateAll
argument_list|(
name|Module
operator|*
name|M
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// \brief Invalidate analyses cached for an IR Function.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// Note that specific analysis results can disregard invalidation by
end_comment

begin_comment
comment|/// overriding the invalidate method.
end_comment

begin_function_decl
name|void
name|invalidateAll
parameter_list|(
name|Function
modifier|*
name|F
parameter_list|)
function_decl|;
end_function_decl

begin_label
name|private
label|:
end_label

begin_comment
comment|/// \brief Abstract concept of an analysis result.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This concept is parameterized over the IR unit that this result pertains
end_comment

begin_comment
comment|/// to.
end_comment

begin_expr_stmt
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
name|virtual
name|AnalysisResultConcept
operator|*
name|clone
argument_list|()
operator|=
literal|0
block|;
comment|/// \brief Method to try and mark a result as invalid.
comment|///
comment|/// When the outer \c AnalysisManager detects a change in some underlying
comment|/// unit of the IR, it will call this method on all of the results cached.
comment|///
comment|/// \returns true if the result should indeed be invalidated (the default).
name|virtual
name|bool
name|invalidate
argument_list|(
name|IRUnitT
operator|*
name|IR
argument_list|)
operator|=
literal|0
block|;   }
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// \brief Wrapper to model the analysis result concept.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// Can wrap any type which implements a suitable invalidate member and model
end_comment

begin_comment
comment|/// the AnalysisResultConcept for the AnalysisManager.
end_comment

begin_expr_stmt
name|template
operator|<
name|typename
name|IRUnitT
operator|,
name|typename
name|ResultT
operator|>
expr|struct
name|AnalysisResultModel
operator|:
name|AnalysisResultConcept
operator|<
name|IRUnitT
operator|>
block|{
name|AnalysisResultModel
argument_list|(
argument|ResultT Result
argument_list|)
operator|:
name|Result
argument_list|(
argument|llvm_move(Result)
argument_list|)
block|{}
name|virtual
name|AnalysisResultModel
operator|*
name|clone
argument_list|()
block|{
return|return
name|new
name|AnalysisResultModel
argument_list|(
name|Result
argument_list|)
return|;
block|}
comment|/// \brief The model delegates to the \c ResultT method.
name|virtual
name|bool
name|invalidate
argument_list|(
argument|IRUnitT *IR
argument_list|)
block|{
return|return
name|Result
operator|.
name|invalidate
argument_list|(
name|IR
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
name|virtual
name|AnalysisPassConcept
operator|*
name|clone
argument_list|()
operator|=
literal|0
block|;
comment|/// \brief Method to run this analysis over a unit of IR.
comment|/// \returns The analysis result object to be queried by users, the caller
comment|/// takes ownership.
name|virtual
name|AnalysisResultConcept
operator|<
name|IRUnitT
operator|>
operator|*
name|run
argument_list|(
name|IRUnitT
operator|*
name|IR
argument_list|)
operator|=
literal|0
block|;   }
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
name|PassT
operator|>
expr|struct
name|AnalysisPassModel
operator|:
name|AnalysisPassConcept
operator|<
name|typename
name|PassT
operator|::
name|IRUnitT
operator|>
block|{
name|AnalysisPassModel
argument_list|(
argument|PassT Pass
argument_list|)
operator|:
name|Pass
argument_list|(
argument|llvm_move(Pass)
argument_list|)
block|{}
name|virtual
name|AnalysisPassModel
operator|*
name|clone
argument_list|()
block|{
return|return
name|new
name|AnalysisPassModel
argument_list|(
name|Pass
argument_list|)
return|;
block|}
end_expr_stmt

begin_comment
comment|// FIXME: Replace PassT::IRUnitT with type traits when we use C++11.
end_comment

begin_typedef
typedef|typedef
name|typename
name|PassT
operator|::
name|IRUnitT
name|IRUnitT
expr_stmt|;
end_typedef

begin_comment
comment|// FIXME: Replace PassT::Result with type traits when we use C++11.
end_comment

begin_typedef
typedef|typedef
name|AnalysisResultModel
operator|<
name|IRUnitT
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

begin_function
name|virtual
name|ResultModelT
modifier|*
name|run
parameter_list|(
name|IRUnitT
modifier|*
name|IR
parameter_list|)
block|{
return|return
name|new
name|ResultModelT
argument_list|(
name|Pass
operator|.
name|run
argument_list|(
name|IR
argument_list|)
argument_list|)
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
comment|/// \brief Get a module pass result, running the pass if necessary.
end_comment

begin_expr_stmt
specifier|const
name|AnalysisResultConcept
operator|<
name|Module
operator|>
operator|&
name|getResultImpl
argument_list|(
name|void
operator|*
name|PassID
argument_list|,
name|Module
operator|*
name|M
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// \brief Get a function pass result, running the pass if necessary.
end_comment

begin_expr_stmt
specifier|const
name|AnalysisResultConcept
operator|<
name|Function
operator|>
operator|&
name|getResultImpl
argument_list|(
name|void
operator|*
name|PassID
argument_list|,
name|Function
operator|*
name|F
argument_list|)
expr_stmt|;
end_expr_stmt

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
comment|/// \brief Invalidate a function pass result.
end_comment

begin_function_decl
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
end_function_decl

begin_comment
comment|/// \brief Module pass specific implementation of registration.
end_comment

begin_expr_stmt
name|template
operator|<
name|typename
name|PassT
operator|>
name|typename
name|enable_if
operator|<
name|is_same
operator|<
name|typename
name|PassT
operator|::
name|IRUnitT
operator|,
name|Module
operator|>
expr|>
operator|::
name|type
name|registerAnalysisPassImpl
argument_list|(
argument|PassT Pass
argument_list|)
block|{
name|assert
argument_list|(
operator|!
name|ModuleAnalysisPasses
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
name|ModuleAnalysisPasses
index|[
name|PassT
operator|::
name|ID
argument_list|()
index|]
operator|=
name|new
name|AnalysisPassModel
operator|<
name|PassT
operator|>
operator|(
name|llvm_move
argument_list|(
name|Pass
argument_list|)
operator|)
block|;   }
comment|/// \brief Function pass specific implementation of registration.
name|template
operator|<
name|typename
name|PassT
operator|>
name|typename
name|enable_if
operator|<
name|is_same
operator|<
name|typename
name|PassT
operator|::
name|IRUnitT
operator|,
name|Function
operator|>
expr|>
operator|::
name|type
name|registerAnalysisPassImpl
argument_list|(
argument|PassT Pass
argument_list|)
block|{
name|assert
argument_list|(
operator|!
name|FunctionAnalysisPasses
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
name|FunctionAnalysisPasses
index|[
name|PassT
operator|::
name|ID
argument_list|()
index|]
operator|=
name|new
name|AnalysisPassModel
operator|<
name|PassT
operator|>
operator|(
name|llvm_move
argument_list|(
name|Pass
argument_list|)
operator|)
block|;   }
end_expr_stmt

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
name|polymorphic_ptr
operator|<
name|AnalysisPassConcept
operator|<
name|Module
operator|>
expr|>
operator|>
name|ModuleAnalysisPassMapT
expr_stmt|;
end_typedef

begin_comment
comment|/// \brief Collection of module analysis passes, indexed by ID.
end_comment

begin_decl_stmt
name|ModuleAnalysisPassMapT
name|ModuleAnalysisPasses
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// \brief Map type from module analysis pass ID to pass result concept pointer.
end_comment

begin_typedef
typedef|typedef
name|DenseMap
operator|<
name|void
operator|*
operator|,
name|polymorphic_ptr
operator|<
name|AnalysisResultConcept
operator|<
name|Module
operator|>
expr|>
operator|>
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
comment|/// \brief Map type from function analysis pass ID to pass concept pointer.
end_comment

begin_typedef
typedef|typedef
name|DenseMap
operator|<
name|void
operator|*
operator|,
name|polymorphic_ptr
operator|<
name|AnalysisPassConcept
operator|<
name|Function
operator|>
expr|>
operator|>
name|FunctionAnalysisPassMapT
expr_stmt|;
end_typedef

begin_comment
comment|/// \brief Collection of function analysis passes, indexed by ID.
end_comment

begin_decl_stmt
name|FunctionAnalysisPassMapT
name|FunctionAnalysisPasses
decl_stmt|;
end_decl_stmt

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
name|polymorphic_ptr
operator|<
name|AnalysisResultConcept
operator|<
name|Function
operator|>
expr|>
operator|>
expr|>
name|FunctionAnalysisResultListT
expr_stmt|;
end_typedef

begin_comment
comment|/// \brief Map type from function pointer to our custom list type.
end_comment

begin_typedef
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
name|FunctionAnalysisResultListMapT
name|FunctionAnalysisResultLists
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
end_typedef

begin_comment
comment|/// \brief Map from an analysis ID and function to a particular cached
end_comment

begin_comment
comment|/// analysis result.
end_comment

begin_decl_stmt
name|FunctionAnalysisResultMapT
name|FunctionAnalysisResults
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// \brief Module handle for the \c AnalysisManager.
end_comment

begin_decl_stmt
name|Module
modifier|*
name|M
decl_stmt|;
end_decl_stmt

unit|};  }
end_unit

