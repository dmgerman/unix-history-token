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
comment|//
end_comment

begin_comment
comment|// This interface is used to build and manipulate a call graph, which is a very
end_comment

begin_comment
comment|// useful tool for interprocedural optimization.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// Every function in a module is represented as a node in the call graph.  The
end_comment

begin_comment
comment|// callgraph node keeps track of which functions the are called by the function
end_comment

begin_comment
comment|// corresponding to the node.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// A call graph may contain nodes where the function that they correspond to is
end_comment

begin_comment
comment|// null.  These 'external' nodes are used to represent control flow that is not
end_comment

begin_comment
comment|// represented (or analyzable) in the module.  In particular, this analysis
end_comment

begin_comment
comment|// builds one external node such that:
end_comment

begin_comment
comment|//   1. All functions in the module without internal linkage will have edges
end_comment

begin_comment
comment|//      from this external node, indicating that they could be called by
end_comment

begin_comment
comment|//      functions outside of the module.
end_comment

begin_comment
comment|//   2. All functions whose address is used for something more than a direct
end_comment

begin_comment
comment|//      call, for example being stored into a memory location will also have an
end_comment

begin_comment
comment|//      edge from this external node.  Since they may be called by an unknown
end_comment

begin_comment
comment|//      caller later, they must be tracked as such.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// There is a second external node added for calls that leave this module.
end_comment

begin_comment
comment|// Functions have a call edge to the external node iff:
end_comment

begin_comment
comment|//   1. The function is external, reflecting the fact that they could call
end_comment

begin_comment
comment|//      anything without internal linkage or that has its address taken.
end_comment

begin_comment
comment|//   2. The function contains an indirect function call.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// As an extension in the future, there may be multiple nodes with a null
end_comment

begin_comment
comment|// function.  These will be used when we can prove (through pointer analysis)
end_comment

begin_comment
comment|// that an indirect call site can call only a specific set of functions.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// Because of these properties, the CallGraph captures a conservative superset
end_comment

begin_comment
comment|// of all of the caller-callee relationships, which is useful for
end_comment

begin_comment
comment|// transformations.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// The CallGraph class also attempts to figure out what the root of the
end_comment

begin_comment
comment|// CallGraph is, which it currently does by looking for a function named 'main'.
end_comment

begin_comment
comment|// If no function named 'main' is found, the external node is used as the entry
end_comment

begin_comment
comment|// node, reflecting the fact that any function without internal linkage could
end_comment

begin_comment
comment|// be called into (which is common for libraries).
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
file|"llvm/Pass.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/CallSite.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/ValueHandle.h"
end_include

begin_include
include|#
directive|include
file|"llvm/System/IncludeFile.h"
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
comment|//===----------------------------------------------------------------------===//
comment|// CallGraph class definition
comment|//
name|class
name|CallGraph
block|{
name|protected
label|:
name|Module
modifier|*
name|Mod
decl_stmt|;
comment|// The module this call graph represents
typedef|typedef
name|std
operator|::
name|map
operator|<
specifier|const
name|Function
operator|*
operator|,
name|CallGraphNode
operator|*
operator|>
name|FunctionMapTy
expr_stmt|;
name|FunctionMapTy
name|FunctionMap
decl_stmt|;
comment|// Map from a function to its node
name|public
label|:
specifier|static
name|char
name|ID
decl_stmt|;
comment|// Class identification, replacement for typeinfo
comment|//===---------------------------------------------------------------------
comment|// Accessors.
comment|//
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
comment|/// getModule - Return the module the call graph corresponds to.
comment|///
name|Module
operator|&
name|getModule
argument_list|()
specifier|const
block|{
return|return
operator|*
name|Mod
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
comment|// Subscripting operators, return the call graph node for the provided
comment|// function
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
return|;
block|}
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
return|;
block|}
comment|/// Returns the CallGraphNode which is used to represent undetermined calls
comment|/// into the callgraph.  Override this if you want behavioral inheritance.
name|virtual
name|CallGraphNode
operator|*
name|getExternalCallingNode
argument_list|()
specifier|const
block|{
return|return
literal|0
return|;
block|}
name|virtual
name|CallGraphNode
operator|*
name|getCallsExternalNode
argument_list|()
specifier|const
block|{
return|return
literal|0
return|;
block|}
comment|/// Return the root/main method in the module, or some other root node, such
comment|/// as the externalcallingnode.  Overload these if you behavioral
comment|/// inheritance.
name|virtual
name|CallGraphNode
modifier|*
name|getRoot
parameter_list|()
block|{
return|return
literal|0
return|;
block|}
name|virtual
specifier|const
name|CallGraphNode
operator|*
name|getRoot
argument_list|()
specifier|const
block|{
return|return
literal|0
return|;
block|}
comment|//===---------------------------------------------------------------------
comment|// Functions to keep a call graph up to date with a function that has been
comment|// modified.
comment|//
comment|/// removeFunctionFromModule - Unlink the function from this module, returning
comment|/// it.  Because this removes the function from the module, the call graph
comment|/// node is destroyed.  This is only valid if the function does not call any
comment|/// other functions (ie, there are no edges in it's CGN).  The easiest way to
comment|/// do this is to dropAllReferences before calling this.
comment|///
name|Function
modifier|*
name|removeFunctionFromModule
parameter_list|(
name|CallGraphNode
modifier|*
name|CGN
parameter_list|)
function_decl|;
name|Function
modifier|*
name|removeFunctionFromModule
parameter_list|(
name|Function
modifier|*
name|F
parameter_list|)
block|{
return|return
name|removeFunctionFromModule
argument_list|(
operator|(
operator|*
name|this
operator|)
index|[
name|F
index|]
argument_list|)
return|;
block|}
comment|/// getOrInsertFunction - This method is identical to calling operator[], but
comment|/// it will insert a new CallGraphNode for the specified function if one does
comment|/// not already exist.
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
comment|//===---------------------------------------------------------------------
comment|// Pass infrastructure interface glue code.
comment|//
name|protected
label|:
name|CallGraph
argument_list|()
block|{}
name|public
label|:
name|virtual
operator|~
name|CallGraph
argument_list|()
block|{
name|destroy
argument_list|()
block|; }
comment|/// initialize - Call this method before calling other methods,
comment|/// re/initializes the state of the CallGraph.
comment|///
name|void
name|initialize
argument_list|(
name|Module
operator|&
name|M
argument_list|)
expr_stmt|;
name|void
name|print
argument_list|(
name|raw_ostream
operator|&
name|o
argument_list|,
name|Module
operator|*
argument_list|)
decl|const
decl_stmt|;
name|void
name|dump
argument_list|()
specifier|const
expr_stmt|;
name|protected
label|:
comment|// destroy - Release memory for the call graph
name|virtual
name|void
name|destroy
parameter_list|()
function_decl|;
block|}
empty_stmt|;
comment|//===----------------------------------------------------------------------===//
comment|// CallGraphNode class definition.
comment|//
name|class
name|CallGraphNode
block|{
name|AssertingVH
operator|<
name|Function
operator|>
name|F
expr_stmt|;
comment|// CallRecord - This is a pair of the calling instruction (a call or invoke)
comment|// and the callgraph node being called.
name|public
label|:
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
name|private
label|:
name|std
operator|::
name|vector
operator|<
name|CallRecord
operator|>
name|CalledFunctions
expr_stmt|;
comment|/// NumReferences - This is the number of times that this CallGraphNode occurs
comment|/// in the CalledFunctions array of this or other CallGraphNodes.
name|unsigned
name|NumReferences
decl_stmt|;
name|CallGraphNode
argument_list|(
specifier|const
name|CallGraphNode
operator|&
argument_list|)
expr_stmt|;
comment|// DO NOT IMPLEMENT
name|void
name|operator
init|=
operator|(
specifier|const
name|CallGraphNode
operator|&
operator|)
decl_stmt|;
comment|// DO NOT IMPLEMENT
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
comment|// CallGraphNode ctor - Create a node for the specified function.
specifier|inline
name|CallGraphNode
argument_list|(
name|Function
operator|*
name|f
argument_list|)
operator|:
name|F
argument_list|(
name|f
argument_list|)
operator|,
name|NumReferences
argument_list|(
literal|0
argument_list|)
block|{}
comment|//===---------------------------------------------------------------------
comment|// Accessor methods.
comment|//
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
comment|// getFunction - Return the function that this call graph node represents.
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
comment|/// getNumReferences - Return the number of other CallGraphNodes in this
comment|/// CallGraph that reference this node in their callee list.
name|unsigned
name|getNumReferences
argument_list|()
specifier|const
block|{
return|return
name|NumReferences
return|;
block|}
comment|// Subscripting operator - Return the i'th called function.
comment|//
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
comment|/// dump - Print out this call graph node.
comment|///
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
comment|/// removeAllCalledFunctions - As the name implies, this removes all edges
comment|/// from this CallGraphNode to any functions it calls.
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
comment|/// stealCalledFunctionsFrom - Move all the callee information from N to this
comment|/// node.
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
comment|/// addCalledFunction - Add a function to the list of functions called by this
comment|/// one.
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
name|CalledFunctions
operator|.
name|push_back
argument_list|(
name|std
operator|::
name|make_pair
argument_list|(
name|CS
operator|.
name|getInstruction
argument_list|()
argument_list|,
name|M
argument_list|)
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
comment|/// removeCallEdgeFor - This method removes the edge in the node for the
comment|/// specified call site.  Note that this method takes linear time, so it
comment|/// should be used sparingly.
name|void
name|removeCallEdgeFor
parameter_list|(
name|CallSite
name|CS
parameter_list|)
function_decl|;
comment|/// removeAnyCallEdgeTo - This method removes all call edges from this node
comment|/// to the specified callee function.  This takes more time to execute than
comment|/// removeCallEdgeTo, so it should not be used unless necessary.
name|void
name|removeAnyCallEdgeTo
parameter_list|(
name|CallGraphNode
modifier|*
name|Callee
parameter_list|)
function_decl|;
comment|/// removeOneAbstractEdgeTo - Remove one edge associated with a null callsite
comment|/// from this node to the specified callee function.
name|void
name|removeOneAbstractEdgeTo
parameter_list|(
name|CallGraphNode
modifier|*
name|Callee
parameter_list|)
function_decl|;
comment|/// replaceCallEdge - This method replaces the edge in the node for the
comment|/// specified call site with a new one.  Note that this method takes linear
comment|/// time, so it should be used sparingly.
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
block|}
empty_stmt|;
comment|//===----------------------------------------------------------------------===//
comment|// GraphTraits specializations for call graphs so that they can be treated as
comment|// graphs by the generic graph algorithms.
comment|//
comment|// Provide graph traits for tranversing call graphs using standard graph
comment|// traversals.
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
name|NodeType
typedef|;
typedef|typedef
name|CallGraphNode
operator|::
name|CallRecord
name|CGNPairTy
expr_stmt|;
typedef|typedef
name|std
operator|::
name|pointer_to_unary_function
operator|<
name|CGNPairTy
operator|,
name|CallGraphNode
operator|*
operator|>
name|CGNDerefFun
expr_stmt|;
specifier|static
name|NodeType
modifier|*
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
typedef|typedef
name|mapped_iterator
operator|<
name|NodeType
operator|::
name|iterator
operator|,
name|CGNDerefFun
operator|>
name|ChildIteratorType
expr_stmt|;
specifier|static
specifier|inline
name|ChildIteratorType
name|child_begin
parameter_list|(
name|NodeType
modifier|*
name|N
parameter_list|)
block|{
return|return
name|map_iterator
argument_list|(
name|N
operator|->
name|begin
argument_list|()
argument_list|,
name|CGNDerefFun
argument_list|(
name|CGNDeref
argument_list|)
argument_list|)
return|;
block|}
specifier|static
specifier|inline
name|ChildIteratorType
name|child_end
parameter_list|(
name|NodeType
modifier|*
name|N
parameter_list|)
block|{
return|return
name|map_iterator
argument_list|(
name|N
operator|->
name|end
argument_list|()
argument_list|,
name|CGNDerefFun
argument_list|(
name|CGNDeref
argument_list|)
argument_list|)
return|;
block|}
specifier|static
name|CallGraphNode
modifier|*
name|CGNDeref
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
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_expr_stmt
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
name|NodeType
typedef|;
end_expr_stmt

begin_typedef
typedef|typedef
name|NodeType
operator|::
name|const_iterator
name|ChildIteratorType
expr_stmt|;
end_typedef

begin_function
specifier|static
name|NodeType
modifier|*
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
specifier|inline
name|ChildIteratorType
name|child_begin
parameter_list|(
name|NodeType
modifier|*
name|N
parameter_list|)
block|{
return|return
name|N
operator|->
name|begin
argument_list|()
return|;
block|}
end_function

begin_function
specifier|static
specifier|inline
name|ChildIteratorType
name|child_end
parameter_list|(
name|NodeType
modifier|*
name|N
parameter_list|)
block|{
return|return
name|N
operator|->
name|end
argument_list|()
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
name|NodeType
operator|*
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
operator|,
name|CallGraphNode
operator|*
operator|>
name|PairTy
expr_stmt|;
end_typedef

begin_typedef
typedef|typedef
name|std
operator|::
name|pointer_to_unary_function
operator|<
name|PairTy
operator|,
name|CallGraphNode
operator|&
operator|>
name|DerefFun
expr_stmt|;
end_typedef

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
name|DerefFun
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
name|map_iterator
argument_list|(
name|CG
operator|->
name|begin
argument_list|()
argument_list|,
name|DerefFun
argument_list|(
name|CGdereference
argument_list|)
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
name|map_iterator
argument_list|(
name|CG
operator|->
name|end
argument_list|()
argument_list|,
name|DerefFun
argument_list|(
name|CGdereference
argument_list|)
argument_list|)
return|;
block|}
end_function

begin_function
specifier|static
name|CallGraphNode
modifier|&
name|CGdereference
parameter_list|(
name|PairTy
name|P
parameter_list|)
block|{
return|return
operator|*
name|P
operator|.
name|second
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
name|NodeType
operator|*
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
block|}
end_expr_stmt

begin_comment
comment|// nodes_iterator/begin/end - Allow iteration over all nodes in the graph
end_comment

begin_typedef
typedef|typedef
name|CallGraph
operator|::
name|const_iterator
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
name|CG
operator|->
name|begin
argument_list|()
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
name|CG
operator|->
name|end
argument_list|()
return|;
block|}
end_function

begin_comment
unit|};  }
comment|// End llvm namespace
end_comment

begin_comment
comment|// Make sure that any clients of this file link in CallGraph.cpp
end_comment

begin_expr_stmt
unit|FORCE_DEFINING_FILE_TO_BE_LINKED
operator|(
name|CallGraph
operator|)
end_expr_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

