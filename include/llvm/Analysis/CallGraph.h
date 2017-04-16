begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- CallGraph.h - Build a Module's call graph ----------------*- C++ -*-===//
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
comment|/// This file provides interfaces used to build and manipulate a call graph,
end_comment

begin_comment
comment|/// which is a very useful tool for interprocedural optimization.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// Every function in a module is represented as a node in the call graph.  The
end_comment

begin_comment
comment|/// callgraph node keeps track of which functions are called by the function
end_comment

begin_comment
comment|/// corresponding to the node.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// A call graph may contain nodes where the function that they correspond to
end_comment

begin_comment
comment|/// is null.  These 'external' nodes are used to represent control flow that is
end_comment

begin_comment
comment|/// not represented (or analyzable) in the module.  In particular, this
end_comment

begin_comment
comment|/// analysis builds one external node such that:
end_comment

begin_comment
comment|///   1. All functions in the module without internal linkage will have edges
end_comment

begin_comment
comment|///      from this external node, indicating that they could be called by
end_comment

begin_comment
comment|///      functions outside of the module.
end_comment

begin_comment
comment|///   2. All functions whose address is used for something more than a direct
end_comment

begin_comment
comment|///      call, for example being stored into a memory location will also have
end_comment

begin_comment
comment|///      an edge from this external node.  Since they may be called by an
end_comment

begin_comment
comment|///      unknown caller later, they must be tracked as such.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// There is a second external node added for calls that leave this module.
end_comment

begin_comment
comment|/// Functions have a call edge to the external node iff:
end_comment

begin_comment
comment|///   1. The function is external, reflecting the fact that they could call
end_comment

begin_comment
comment|///      anything without internal linkage or that has its address taken.
end_comment

begin_comment
comment|///   2. The function contains an indirect function call.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// As an extension in the future, there may be multiple nodes with a null
end_comment

begin_comment
comment|/// function.  These will be used when we can prove (through pointer analysis)
end_comment

begin_comment
comment|/// that an indirect call site can call only a specific set of functions.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// Because of these properties, the CallGraph captures a conservative superset
end_comment

begin_comment
comment|/// of all of the caller-callee relationships, which is useful for
end_comment

begin_comment
comment|/// transformations.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// The CallGraph class also attempts to figure out what the root of the
end_comment

begin_comment
comment|/// CallGraph is, which it currently does by looking for a function named
end_comment

begin_comment
comment|/// 'main'. If no function named 'main' is found, the external node is used as
end_comment

begin_comment
comment|/// the entry node, reflecting the fact that any function without internal
end_comment

begin_comment
comment|/// linkage could be called into (which is common for libraries).
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
name|LLVM_ANALYSIS_CALLGRAPH_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_ANALYSIS_CALLGRAPH_H
end_define

begin_include
include|#
directive|include
file|"llvm/ADT/GraphTraits.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/STLExtras.h"
end_include

begin_include
include|#
directive|include
file|"llvm/IR/CallSite.h"
end_include

begin_include
include|#
directive|include
file|"llvm/IR/Function.h"
end_include

begin_include
include|#
directive|include
file|"llvm/IR/Intrinsics.h"
end_include

begin_include
include|#
directive|include
file|"llvm/IR/PassManager.h"
end_include

begin_include
include|#
directive|include
file|"llvm/IR/ValueHandle.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Pass.h"
end_include

begin_include
include|#
directive|include
file|<map>
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|Function
decl_stmt|;
name|class
name|Module
decl_stmt|;
name|class
name|CallGraphNode
decl_stmt|;
comment|/// \brief The basic data container for the call graph of a \c Module of IR.
comment|///
comment|/// This class exposes both the interface to the call graph for a module of IR.
comment|///
comment|/// The core call graph itself can also be updated to reflect changes to the IR.
name|class
name|CallGraph
block|{
name|Module
modifier|&
name|M
decl_stmt|;
typedef|typedef
name|std
operator|::
name|map
operator|<
specifier|const
name|Function
operator|*
operator|,
name|std
operator|::
name|unique_ptr
operator|<
name|CallGraphNode
operator|>>
name|FunctionMapTy
expr_stmt|;
comment|/// \brief A map from \c Function* to \c CallGraphNode*.
name|FunctionMapTy
name|FunctionMap
decl_stmt|;
comment|/// \brief Root is root of the call graph, or the external node if a 'main'
comment|/// function couldn't be found.
name|CallGraphNode
modifier|*
name|Root
decl_stmt|;
comment|/// \brief This node has edges to all external functions and those internal
comment|/// functions that have their address taken.
name|CallGraphNode
modifier|*
name|ExternalCallingNode
decl_stmt|;
comment|/// \brief This node has edges to it from all functions making indirect calls
comment|/// or calling an external function.
name|std
operator|::
name|unique_ptr
operator|<
name|CallGraphNode
operator|>
name|CallsExternalNode
expr_stmt|;
comment|/// \brief Replace the function represented by this node by another.
comment|///
comment|/// This does not rescan the body of the function, so it is suitable when
comment|/// splicing the body of one function to another while also updating all
comment|/// callers from the old function to the new.
name|void
name|spliceFunction
parameter_list|(
specifier|const
name|Function
modifier|*
name|From
parameter_list|,
specifier|const
name|Function
modifier|*
name|To
parameter_list|)
function_decl|;
comment|/// \brief Add a function to the call graph, and link the node to all of the
comment|/// functions that it calls.
name|void
name|addToCallGraph
parameter_list|(
name|Function
modifier|*
name|F
parameter_list|)
function_decl|;
name|public
label|:
name|explicit
name|CallGraph
parameter_list|(
name|Module
modifier|&
name|M
parameter_list|)
function_decl|;
name|CallGraph
argument_list|(
name|CallGraph
operator|&&
name|Arg
argument_list|)
expr_stmt|;
operator|~
name|CallGraph
argument_list|()
expr_stmt|;
name|void
name|print
argument_list|(
name|raw_ostream
operator|&
name|OS
argument_list|)
decl|const
decl_stmt|;
name|void
name|dump
argument_list|()
specifier|const
expr_stmt|;
typedef|typedef
name|FunctionMapTy
operator|::
name|iterator
name|iterator
expr_stmt|;
typedef|typedef
name|FunctionMapTy
operator|::
name|const_iterator
name|const_iterator
expr_stmt|;
comment|/// \brief Returns the module the call graph corresponds to.
name|Module
operator|&
name|getModule
argument_list|()
specifier|const
block|{
return|return
name|M
return|;
block|}
specifier|inline
name|iterator
name|begin
parameter_list|()
block|{
return|return
name|FunctionMap
operator|.
name|begin
argument_list|()
return|;
block|}
specifier|inline
name|iterator
name|end
parameter_list|()
block|{
return|return
name|FunctionMap
operator|.
name|end
argument_list|()
return|;
block|}
specifier|inline
name|const_iterator
name|begin
argument_list|()
specifier|const
block|{
return|return
name|FunctionMap
operator|.
name|begin
argument_list|()
return|;
block|}
specifier|inline
name|const_iterator
name|end
argument_list|()
specifier|const
block|{
return|return
name|FunctionMap
operator|.
name|end
argument_list|()
return|;
block|}
comment|/// \brief Returns the call graph node for the provided function.
specifier|inline
specifier|const
name|CallGraphNode
modifier|*
name|operator
index|[]
argument_list|(
specifier|const
name|Function
operator|*
name|F
argument_list|)
decl|const
block|{
name|const_iterator
name|I
init|=
name|FunctionMap
operator|.
name|find
argument_list|(
name|F
argument_list|)
decl_stmt|;
name|assert
argument_list|(
name|I
operator|!=
name|FunctionMap
operator|.
name|end
argument_list|()
operator|&&
literal|"Function not in callgraph!"
argument_list|)
expr_stmt|;
return|return
name|I
operator|->
name|second
operator|.
name|get
argument_list|()
return|;
block|}
comment|/// \brief Returns the call graph node for the provided function.
specifier|inline
name|CallGraphNode
modifier|*
name|operator
function|[]
parameter_list|(
specifier|const
name|Function
modifier|*
name|F
parameter_list|)
block|{
name|const_iterator
name|I
init|=
name|FunctionMap
operator|.
name|find
argument_list|(
name|F
argument_list|)
decl_stmt|;
name|assert
argument_list|(
name|I
operator|!=
name|FunctionMap
operator|.
name|end
argument_list|()
operator|&&
literal|"Function not in callgraph!"
argument_list|)
expr_stmt|;
return|return
name|I
operator|->
name|second
operator|.
name|get
argument_list|()
return|;
block|}
comment|/// \brief Returns the \c CallGraphNode which is used to represent
comment|/// undetermined calls into the callgraph.
name|CallGraphNode
operator|*
name|getExternalCallingNode
argument_list|()
specifier|const
block|{
return|return
name|ExternalCallingNode
return|;
block|}
name|CallGraphNode
operator|*
name|getCallsExternalNode
argument_list|()
specifier|const
block|{
return|return
name|CallsExternalNode
operator|.
name|get
argument_list|()
return|;
block|}
comment|//===---------------------------------------------------------------------
comment|// Functions to keep a call graph up to date with a function that has been
comment|// modified.
comment|//
comment|/// \brief Unlink the function from this module, returning it.
comment|///
comment|/// Because this removes the function from the module, the call graph node is
comment|/// destroyed.  This is only valid if the function does not call any other
comment|/// functions (ie, there are no edges in it's CGN).  The easiest way to do
comment|/// this is to dropAllReferences before calling this.
name|Function
modifier|*
name|removeFunctionFromModule
parameter_list|(
name|CallGraphNode
modifier|*
name|CGN
parameter_list|)
function_decl|;
comment|/// \brief Similar to operator[], but this will insert a new CallGraphNode for
comment|/// \c F if one does not already exist.
name|CallGraphNode
modifier|*
name|getOrInsertFunction
parameter_list|(
specifier|const
name|Function
modifier|*
name|F
parameter_list|)
function_decl|;
block|}
empty_stmt|;
comment|/// \brief A node in the call graph for a module.
comment|///
comment|/// Typically represents a function in the call graph. There are also special
comment|/// "null" nodes used to represent theoretical entries in the call graph.
name|class
name|CallGraphNode
block|{
name|public
label|:
comment|/// \brief A pair of the calling instruction (a call or invoke)
comment|/// and the call graph node being called.
typedef|typedef
name|std
operator|::
name|pair
operator|<
name|WeakVH
operator|,
name|CallGraphNode
operator|*
operator|>
name|CallRecord
expr_stmt|;
name|public
label|:
typedef|typedef
name|std
operator|::
name|vector
operator|<
name|CallRecord
operator|>
name|CalledFunctionsVector
expr_stmt|;
comment|/// \brief Creates a node for the specified function.
specifier|inline
name|CallGraphNode
argument_list|(
name|Function
operator|*
name|F
argument_list|)
operator|:
name|F
argument_list|(
name|F
argument_list|)
operator|,
name|NumReferences
argument_list|(
literal|0
argument_list|)
block|{}
operator|~
name|CallGraphNode
argument_list|()
block|{
name|assert
argument_list|(
name|NumReferences
operator|==
literal|0
operator|&&
literal|"Node deleted while references remain"
argument_list|)
block|;   }
typedef|typedef
name|std
operator|::
name|vector
operator|<
name|CallRecord
operator|>
operator|::
name|iterator
name|iterator
expr_stmt|;
typedef|typedef
name|std
operator|::
name|vector
operator|<
name|CallRecord
operator|>
operator|::
name|const_iterator
name|const_iterator
expr_stmt|;
comment|/// \brief Returns the function that this call graph node represents.
name|Function
operator|*
name|getFunction
argument_list|()
specifier|const
block|{
return|return
name|F
return|;
block|}
specifier|inline
name|iterator
name|begin
parameter_list|()
block|{
return|return
name|CalledFunctions
operator|.
name|begin
argument_list|()
return|;
block|}
specifier|inline
name|iterator
name|end
parameter_list|()
block|{
return|return
name|CalledFunctions
operator|.
name|end
argument_list|()
return|;
block|}
specifier|inline
name|const_iterator
name|begin
argument_list|()
specifier|const
block|{
return|return
name|CalledFunctions
operator|.
name|begin
argument_list|()
return|;
block|}
specifier|inline
name|const_iterator
name|end
argument_list|()
specifier|const
block|{
return|return
name|CalledFunctions
operator|.
name|end
argument_list|()
return|;
block|}
specifier|inline
name|bool
name|empty
argument_list|()
specifier|const
block|{
return|return
name|CalledFunctions
operator|.
name|empty
argument_list|()
return|;
block|}
specifier|inline
name|unsigned
name|size
argument_list|()
specifier|const
block|{
return|return
operator|(
name|unsigned
operator|)
name|CalledFunctions
operator|.
name|size
argument_list|()
return|;
block|}
comment|/// \brief Returns the number of other CallGraphNodes in this CallGraph that
comment|/// reference this node in their callee list.
name|unsigned
name|getNumReferences
argument_list|()
specifier|const
block|{
return|return
name|NumReferences
return|;
block|}
comment|/// \brief Returns the i'th called function.
name|CallGraphNode
modifier|*
name|operator
index|[]
argument_list|(
name|unsigned
name|i
argument_list|)
decl|const
block|{
name|assert
argument_list|(
name|i
operator|<
name|CalledFunctions
operator|.
name|size
argument_list|()
operator|&&
literal|"Invalid index"
argument_list|)
expr_stmt|;
return|return
name|CalledFunctions
index|[
name|i
index|]
operator|.
name|second
return|;
block|}
comment|/// \brief Print out this call graph node.
name|void
name|dump
argument_list|()
specifier|const
expr_stmt|;
name|void
name|print
argument_list|(
name|raw_ostream
operator|&
name|OS
argument_list|)
decl|const
decl_stmt|;
comment|//===---------------------------------------------------------------------
comment|// Methods to keep a call graph up to date with a function that has been
comment|// modified
comment|//
comment|/// \brief Removes all edges from this CallGraphNode to any functions it
comment|/// calls.
name|void
name|removeAllCalledFunctions
parameter_list|()
block|{
while|while
condition|(
operator|!
name|CalledFunctions
operator|.
name|empty
argument_list|()
condition|)
block|{
name|CalledFunctions
operator|.
name|back
argument_list|()
operator|.
name|second
operator|->
name|DropRef
argument_list|()
expr_stmt|;
name|CalledFunctions
operator|.
name|pop_back
argument_list|()
expr_stmt|;
block|}
block|}
comment|/// \brief Moves all the callee information from N to this node.
name|void
name|stealCalledFunctionsFrom
parameter_list|(
name|CallGraphNode
modifier|*
name|N
parameter_list|)
block|{
name|assert
argument_list|(
name|CalledFunctions
operator|.
name|empty
argument_list|()
operator|&&
literal|"Cannot steal callsite information if I already have some"
argument_list|)
expr_stmt|;
name|std
operator|::
name|swap
argument_list|(
name|CalledFunctions
argument_list|,
name|N
operator|->
name|CalledFunctions
argument_list|)
expr_stmt|;
block|}
comment|/// \brief Adds a function to the list of functions called by this one.
name|void
name|addCalledFunction
parameter_list|(
name|CallSite
name|CS
parameter_list|,
name|CallGraphNode
modifier|*
name|M
parameter_list|)
block|{
name|assert
argument_list|(
operator|!
name|CS
operator|.
name|getInstruction
argument_list|()
operator|||
operator|!
name|CS
operator|.
name|getCalledFunction
argument_list|()
operator|||
operator|!
name|CS
operator|.
name|getCalledFunction
argument_list|()
operator|->
name|isIntrinsic
argument_list|()
operator|||
operator|!
name|Intrinsic
operator|::
name|isLeaf
argument_list|(
name|CS
operator|.
name|getCalledFunction
argument_list|()
operator|->
name|getIntrinsicID
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|CalledFunctions
operator|.
name|emplace_back
argument_list|(
name|CS
operator|.
name|getInstruction
argument_list|()
argument_list|,
name|M
argument_list|)
expr_stmt|;
name|M
operator|->
name|AddRef
argument_list|()
expr_stmt|;
block|}
name|void
name|removeCallEdge
parameter_list|(
name|iterator
name|I
parameter_list|)
block|{
name|I
operator|->
name|second
operator|->
name|DropRef
argument_list|()
expr_stmt|;
operator|*
name|I
operator|=
name|CalledFunctions
operator|.
name|back
argument_list|()
expr_stmt|;
name|CalledFunctions
operator|.
name|pop_back
argument_list|()
expr_stmt|;
block|}
comment|/// \brief Removes the edge in the node for the specified call site.
comment|///
comment|/// Note that this method takes linear time, so it should be used sparingly.
name|void
name|removeCallEdgeFor
parameter_list|(
name|CallSite
name|CS
parameter_list|)
function_decl|;
comment|/// \brief Removes all call edges from this node to the specified callee
comment|/// function.
comment|///
comment|/// This takes more time to execute than removeCallEdgeTo, so it should not
comment|/// be used unless necessary.
name|void
name|removeAnyCallEdgeTo
parameter_list|(
name|CallGraphNode
modifier|*
name|Callee
parameter_list|)
function_decl|;
comment|/// \brief Removes one edge associated with a null callsite from this node to
comment|/// the specified callee function.
name|void
name|removeOneAbstractEdgeTo
parameter_list|(
name|CallGraphNode
modifier|*
name|Callee
parameter_list|)
function_decl|;
comment|/// \brief Replaces the edge in the node for the specified call site with a
comment|/// new one.
comment|///
comment|/// Note that this method takes linear time, so it should be used sparingly.
name|void
name|replaceCallEdge
parameter_list|(
name|CallSite
name|CS
parameter_list|,
name|CallSite
name|NewCS
parameter_list|,
name|CallGraphNode
modifier|*
name|NewNode
parameter_list|)
function_decl|;
name|private
label|:
name|friend
name|class
name|CallGraph
decl_stmt|;
name|Function
modifier|*
name|F
decl_stmt|;
name|std
operator|::
name|vector
operator|<
name|CallRecord
operator|>
name|CalledFunctions
expr_stmt|;
comment|/// \brief The number of times that this CallGraphNode occurs in the
comment|/// CalledFunctions array of this or other CallGraphNodes.
name|unsigned
name|NumReferences
decl_stmt|;
name|CallGraphNode
argument_list|(
specifier|const
name|CallGraphNode
operator|&
argument_list|)
operator|=
name|delete
expr_stmt|;
name|void
name|operator
init|=
operator|(
specifier|const
name|CallGraphNode
operator|&
operator|)
operator|=
name|delete
decl_stmt|;
name|void
name|DropRef
parameter_list|()
block|{
operator|--
name|NumReferences
expr_stmt|;
block|}
name|void
name|AddRef
parameter_list|()
block|{
operator|++
name|NumReferences
expr_stmt|;
block|}
comment|/// \brief A special function that should only be used by the CallGraph class.
name|void
name|allReferencesDropped
parameter_list|()
block|{
name|NumReferences
operator|=
literal|0
expr_stmt|;
block|}
block|}
empty_stmt|;
comment|/// \brief An analysis pass to compute the \c CallGraph for a \c Module.
comment|///
comment|/// This class implements the concept of an analysis pass used by the \c
comment|/// ModuleAnalysisManager to run an analysis over a module and cache the
comment|/// resulting data.
name|class
name|CallGraphAnalysis
range|:
name|public
name|AnalysisInfoMixin
operator|<
name|CallGraphAnalysis
operator|>
block|{
name|friend
name|AnalysisInfoMixin
operator|<
name|CallGraphAnalysis
operator|>
block|;
specifier|static
name|AnalysisKey
name|Key
block|;
name|public
operator|:
comment|/// \brief A formulaic typedef to inform clients of the result type.
typedef|typedef
name|CallGraph
name|Result
typedef|;
comment|/// \brief Compute the \c CallGraph for the module \c M.
comment|///
comment|/// The real work here is done in the \c CallGraph constructor.
name|CallGraph
name|run
argument_list|(
argument|Module&M
argument_list|,
argument|ModuleAnalysisManager&
argument_list|)
block|{
return|return
name|CallGraph
argument_list|(
name|M
argument_list|)
return|;
block|}
block|}
empty_stmt|;
comment|/// \brief Printer pass for the \c CallGraphAnalysis results.
name|class
name|CallGraphPrinterPass
range|:
name|public
name|PassInfoMixin
operator|<
name|CallGraphPrinterPass
operator|>
block|{
name|raw_ostream
operator|&
name|OS
block|;
name|public
operator|:
name|explicit
name|CallGraphPrinterPass
argument_list|(
name|raw_ostream
operator|&
name|OS
argument_list|)
operator|:
name|OS
argument_list|(
argument|OS
argument_list|)
block|{}
name|PreservedAnalyses
name|run
argument_list|(
name|Module
operator|&
name|M
argument_list|,
name|ModuleAnalysisManager
operator|&
name|AM
argument_list|)
block|; }
decl_stmt|;
comment|/// \brief The \c ModulePass which wraps up a \c CallGraph and the logic to
comment|/// build it.
comment|///
comment|/// This class exposes both the interface to the call graph container and the
comment|/// module pass which runs over a module of IR and produces the call graph. The
comment|/// call graph interface is entirelly a wrapper around a \c CallGraph object
comment|/// which is stored internally for each module.
name|class
name|CallGraphWrapperPass
range|:
name|public
name|ModulePass
block|{
name|std
operator|::
name|unique_ptr
operator|<
name|CallGraph
operator|>
name|G
block|;
name|public
operator|:
specifier|static
name|char
name|ID
block|;
comment|// Class identification, replacement for typeinfo
name|CallGraphWrapperPass
argument_list|()
block|;
operator|~
name|CallGraphWrapperPass
argument_list|()
name|override
block|;
comment|/// \brief The internal \c CallGraph around which the rest of this interface
comment|/// is wrapped.
specifier|const
name|CallGraph
operator|&
name|getCallGraph
argument_list|()
specifier|const
block|{
return|return
operator|*
name|G
return|;
block|}
name|CallGraph
operator|&
name|getCallGraph
argument_list|()
block|{
return|return
operator|*
name|G
return|;
block|}
typedef|typedef
name|CallGraph
operator|::
name|iterator
name|iterator
expr_stmt|;
typedef|typedef
name|CallGraph
operator|::
name|const_iterator
name|const_iterator
expr_stmt|;
comment|/// \brief Returns the module the call graph corresponds to.
name|Module
operator|&
name|getModule
argument_list|()
specifier|const
block|{
return|return
name|G
operator|->
name|getModule
argument_list|()
return|;
block|}
specifier|inline
name|iterator
name|begin
parameter_list|()
block|{
return|return
name|G
operator|->
name|begin
argument_list|()
return|;
block|}
specifier|inline
name|iterator
name|end
parameter_list|()
block|{
return|return
name|G
operator|->
name|end
argument_list|()
return|;
block|}
specifier|inline
name|const_iterator
name|begin
argument_list|()
specifier|const
block|{
return|return
name|G
operator|->
name|begin
argument_list|()
return|;
block|}
specifier|inline
name|const_iterator
name|end
argument_list|()
specifier|const
block|{
return|return
name|G
operator|->
name|end
argument_list|()
return|;
block|}
comment|/// \brief Returns the call graph node for the provided function.
specifier|inline
specifier|const
name|CallGraphNode
modifier|*
name|operator
index|[]
argument_list|(
specifier|const
name|Function
operator|*
name|F
argument_list|)
decl|const
block|{
return|return
operator|(
operator|*
name|G
operator|)
index|[
name|F
index|]
return|;
block|}
comment|/// \brief Returns the call graph node for the provided function.
specifier|inline
name|CallGraphNode
modifier|*
name|operator
function|[]
parameter_list|(
specifier|const
name|Function
modifier|*
name|F
parameter_list|)
block|{
return|return
operator|(
operator|*
name|G
operator|)
index|[
name|F
index|]
return|;
block|}
comment|/// \brief Returns the \c CallGraphNode which is used to represent
comment|/// undetermined calls into the callgraph.
name|CallGraphNode
operator|*
name|getExternalCallingNode
argument_list|()
specifier|const
block|{
return|return
name|G
operator|->
name|getExternalCallingNode
argument_list|()
return|;
block|}
name|CallGraphNode
operator|*
name|getCallsExternalNode
argument_list|()
specifier|const
block|{
return|return
name|G
operator|->
name|getCallsExternalNode
argument_list|()
return|;
block|}
comment|//===---------------------------------------------------------------------
comment|// Functions to keep a call graph up to date with a function that has been
comment|// modified.
comment|//
comment|/// \brief Unlink the function from this module, returning it.
comment|///
comment|/// Because this removes the function from the module, the call graph node is
comment|/// destroyed.  This is only valid if the function does not call any other
comment|/// functions (ie, there are no edges in it's CGN).  The easiest way to do
comment|/// this is to dropAllReferences before calling this.
name|Function
modifier|*
name|removeFunctionFromModule
parameter_list|(
name|CallGraphNode
modifier|*
name|CGN
parameter_list|)
block|{
return|return
name|G
operator|->
name|removeFunctionFromModule
argument_list|(
name|CGN
argument_list|)
return|;
block|}
comment|/// \brief Similar to operator[], but this will insert a new CallGraphNode for
comment|/// \c F if one does not already exist.
name|CallGraphNode
modifier|*
name|getOrInsertFunction
parameter_list|(
specifier|const
name|Function
modifier|*
name|F
parameter_list|)
block|{
return|return
name|G
operator|->
name|getOrInsertFunction
argument_list|(
name|F
argument_list|)
return|;
block|}
comment|//===---------------------------------------------------------------------
comment|// Implementation of the ModulePass interface needed here.
comment|//
name|void
name|getAnalysisUsage
argument_list|(
name|AnalysisUsage
operator|&
name|AU
argument_list|)
decl|const
name|override
decl_stmt|;
name|bool
name|runOnModule
argument_list|(
name|Module
operator|&
name|M
argument_list|)
name|override
decl_stmt|;
name|void
name|releaseMemory
argument_list|()
name|override
expr_stmt|;
name|void
name|print
argument_list|(
name|raw_ostream
operator|&
name|o
argument_list|,
specifier|const
name|Module
operator|*
argument_list|)
decl|const
name|override
decl_stmt|;
name|void
name|dump
argument_list|()
specifier|const
expr_stmt|;
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
comment|//===----------------------------------------------------------------------===//
end_comment

begin_comment
comment|// GraphTraits specializations for call graphs so that they can be treated as
end_comment

begin_comment
comment|// graphs by the generic graph algorithms.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// Provide graph traits for tranversing call graphs using standard graph
end_comment

begin_comment
comment|// traversals.
end_comment

begin_expr_stmt
name|template
operator|<
operator|>
expr|struct
name|GraphTraits
operator|<
name|CallGraphNode
operator|*
operator|>
block|{
typedef|typedef
name|CallGraphNode
modifier|*
name|NodeRef
typedef|;
end_expr_stmt

begin_typedef
typedef|typedef
name|CallGraphNode
operator|::
name|CallRecord
name|CGNPairTy
expr_stmt|;
end_typedef

begin_function
specifier|static
name|NodeRef
name|getEntryNode
parameter_list|(
name|CallGraphNode
modifier|*
name|CGN
parameter_list|)
block|{
return|return
name|CGN
return|;
block|}
end_function

begin_function
specifier|static
name|CallGraphNode
modifier|*
name|CGNGetValue
parameter_list|(
name|CGNPairTy
name|P
parameter_list|)
block|{
return|return
name|P
operator|.
name|second
return|;
block|}
end_function

begin_typedef
typedef|typedef
name|mapped_iterator
operator|<
name|CallGraphNode
operator|::
name|iterator
operator|,
name|decltype
argument_list|(
operator|&
name|CGNGetValue
argument_list|)
operator|>
name|ChildIteratorType
expr_stmt|;
end_typedef

begin_function
specifier|static
name|ChildIteratorType
name|child_begin
parameter_list|(
name|NodeRef
name|N
parameter_list|)
block|{
return|return
name|ChildIteratorType
argument_list|(
name|N
operator|->
name|begin
argument_list|()
argument_list|,
operator|&
name|CGNGetValue
argument_list|)
return|;
block|}
end_function

begin_function
specifier|static
name|ChildIteratorType
name|child_end
parameter_list|(
name|NodeRef
name|N
parameter_list|)
block|{
return|return
name|ChildIteratorType
argument_list|(
name|N
operator|->
name|end
argument_list|()
argument_list|,
operator|&
name|CGNGetValue
argument_list|)
return|;
block|}
end_function

begin_expr_stmt
unit|};
name|template
operator|<
operator|>
expr|struct
name|GraphTraits
operator|<
specifier|const
name|CallGraphNode
operator|*
operator|>
block|{
typedef|typedef
specifier|const
name|CallGraphNode
modifier|*
name|NodeRef
typedef|;
end_expr_stmt

begin_typedef
typedef|typedef
name|CallGraphNode
operator|::
name|CallRecord
name|CGNPairTy
expr_stmt|;
end_typedef

begin_function
specifier|static
name|NodeRef
name|getEntryNode
parameter_list|(
specifier|const
name|CallGraphNode
modifier|*
name|CGN
parameter_list|)
block|{
return|return
name|CGN
return|;
block|}
end_function

begin_function
specifier|static
specifier|const
name|CallGraphNode
modifier|*
name|CGNGetValue
parameter_list|(
name|CGNPairTy
name|P
parameter_list|)
block|{
return|return
name|P
operator|.
name|second
return|;
block|}
end_function

begin_typedef
typedef|typedef
name|mapped_iterator
operator|<
name|CallGraphNode
operator|::
name|const_iterator
operator|,
name|decltype
argument_list|(
operator|&
name|CGNGetValue
argument_list|)
operator|>
name|ChildIteratorType
expr_stmt|;
end_typedef

begin_function
specifier|static
name|ChildIteratorType
name|child_begin
parameter_list|(
name|NodeRef
name|N
parameter_list|)
block|{
return|return
name|ChildIteratorType
argument_list|(
name|N
operator|->
name|begin
argument_list|()
argument_list|,
operator|&
name|CGNGetValue
argument_list|)
return|;
block|}
end_function

begin_function
specifier|static
name|ChildIteratorType
name|child_end
parameter_list|(
name|NodeRef
name|N
parameter_list|)
block|{
return|return
name|ChildIteratorType
argument_list|(
name|N
operator|->
name|end
argument_list|()
argument_list|,
operator|&
name|CGNGetValue
argument_list|)
return|;
block|}
end_function

begin_expr_stmt
unit|};
name|template
operator|<
operator|>
expr|struct
name|GraphTraits
operator|<
name|CallGraph
operator|*
operator|>
operator|:
name|public
name|GraphTraits
operator|<
name|CallGraphNode
operator|*
operator|>
block|{
specifier|static
name|NodeRef
name|getEntryNode
argument_list|(
argument|CallGraph *CGN
argument_list|)
block|{
return|return
name|CGN
operator|->
name|getExternalCallingNode
argument_list|()
return|;
comment|// Start at the external node!
block|}
end_expr_stmt

begin_typedef
typedef|typedef
name|std
operator|::
name|pair
operator|<
specifier|const
name|Function
operator|*
specifier|const
operator|,
name|std
operator|::
name|unique_ptr
operator|<
name|CallGraphNode
operator|>>
name|PairTy
expr_stmt|;
end_typedef

begin_function
specifier|static
name|CallGraphNode
modifier|*
name|CGGetValuePtr
parameter_list|(
specifier|const
name|PairTy
modifier|&
name|P
parameter_list|)
block|{
return|return
name|P
operator|.
name|second
operator|.
name|get
argument_list|()
return|;
block|}
end_function

begin_comment
comment|// nodes_iterator/begin/end - Allow iteration over all nodes in the graph
end_comment

begin_typedef
typedef|typedef
name|mapped_iterator
operator|<
name|CallGraph
operator|::
name|iterator
operator|,
name|decltype
argument_list|(
operator|&
name|CGGetValuePtr
argument_list|)
operator|>
name|nodes_iterator
expr_stmt|;
end_typedef

begin_function
specifier|static
name|nodes_iterator
name|nodes_begin
parameter_list|(
name|CallGraph
modifier|*
name|CG
parameter_list|)
block|{
return|return
name|nodes_iterator
argument_list|(
name|CG
operator|->
name|begin
argument_list|()
argument_list|,
operator|&
name|CGGetValuePtr
argument_list|)
return|;
block|}
end_function

begin_function
specifier|static
name|nodes_iterator
name|nodes_end
parameter_list|(
name|CallGraph
modifier|*
name|CG
parameter_list|)
block|{
return|return
name|nodes_iterator
argument_list|(
name|CG
operator|->
name|end
argument_list|()
argument_list|,
operator|&
name|CGGetValuePtr
argument_list|)
return|;
block|}
end_function

begin_expr_stmt
unit|};
name|template
operator|<
operator|>
expr|struct
name|GraphTraits
operator|<
specifier|const
name|CallGraph
operator|*
operator|>
operator|:
name|public
name|GraphTraits
operator|<
specifier|const
name|CallGraphNode
operator|*
operator|>
block|{
specifier|static
name|NodeRef
name|getEntryNode
argument_list|(
argument|const CallGraph *CGN
argument_list|)
block|{
return|return
name|CGN
operator|->
name|getExternalCallingNode
argument_list|()
return|;
comment|// Start at the external node!
block|}
end_expr_stmt

begin_typedef
typedef|typedef
name|std
operator|::
name|pair
operator|<
specifier|const
name|Function
operator|*
specifier|const
operator|,
name|std
operator|::
name|unique_ptr
operator|<
name|CallGraphNode
operator|>>
name|PairTy
expr_stmt|;
end_typedef

begin_function
specifier|static
specifier|const
name|CallGraphNode
modifier|*
name|CGGetValuePtr
parameter_list|(
specifier|const
name|PairTy
modifier|&
name|P
parameter_list|)
block|{
return|return
name|P
operator|.
name|second
operator|.
name|get
argument_list|()
return|;
block|}
end_function

begin_comment
comment|// nodes_iterator/begin/end - Allow iteration over all nodes in the graph
end_comment

begin_typedef
typedef|typedef
name|mapped_iterator
operator|<
name|CallGraph
operator|::
name|const_iterator
operator|,
name|decltype
argument_list|(
operator|&
name|CGGetValuePtr
argument_list|)
operator|>
name|nodes_iterator
expr_stmt|;
end_typedef

begin_function
specifier|static
name|nodes_iterator
name|nodes_begin
parameter_list|(
specifier|const
name|CallGraph
modifier|*
name|CG
parameter_list|)
block|{
return|return
name|nodes_iterator
argument_list|(
name|CG
operator|->
name|begin
argument_list|()
argument_list|,
operator|&
name|CGGetValuePtr
argument_list|)
return|;
block|}
end_function

begin_function
specifier|static
name|nodes_iterator
name|nodes_end
parameter_list|(
specifier|const
name|CallGraph
modifier|*
name|CG
parameter_list|)
block|{
return|return
name|nodes_iterator
argument_list|(
name|CG
operator|->
name|end
argument_list|()
argument_list|,
operator|&
name|CGGetValuePtr
argument_list|)
return|;
block|}
end_function

begin_comment
unit|};  }
comment|// End llvm namespace
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

