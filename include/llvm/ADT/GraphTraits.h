begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- llvm/ADT/GraphTraits.h - Graph traits template -----------*- C++ -*-===//
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
comment|// This file defines the little GraphTraits<X> template class that should be
end_comment

begin_comment
comment|// specialized by classes that want to be iteratable by generic graph iterators.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// This file also defines the marker class Inverse that is used to iterate over
end_comment

begin_comment
comment|// graphs in a graph defined, inverse ordering...
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
name|LLVM_ADT_GRAPHTRAITS_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_ADT_GRAPHTRAITS_H
end_define

begin_include
include|#
directive|include
file|"llvm/ADT/iterator_range.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
comment|// GraphTraits - This class should be specialized by different graph types...
comment|// which is why the default version is empty.
comment|//
name|template
operator|<
name|class
name|GraphType
operator|>
expr|struct
name|GraphTraits
block|{
comment|// Elements to provide:
comment|// typedef NodeRef           - Type of Node token in the graph, which should
comment|//                             be cheap to copy.
comment|// typedef ChildIteratorType - Type used to iterate over children in graph,
comment|//                             dereference to a NodeRef.
comment|// static NodeRef getEntryNode(const GraphType&)
comment|//    Return the entry node of the graph
comment|// static ChildIteratorType child_begin(NodeRef)
comment|// static ChildIteratorType child_end  (NodeRef)
comment|//    Return iterators that point to the beginning and ending of the child
comment|//    node list for the specified node.
comment|// typedef  ...iterator nodes_iterator; - dereference to a NodeRef
comment|// static nodes_iterator nodes_begin(GraphType *G)
comment|// static nodes_iterator nodes_end  (GraphType *G)
comment|//    nodes_iterator/begin/end - Allow iteration over all nodes in the graph
comment|// static unsigned       size       (GraphType *G)
comment|//    Return total number of nodes in the graph
comment|// If anyone tries to use this class without having an appropriate
comment|// specialization, make an error.  If you get this error, it's because you
comment|// need to include the appropriate specialization of GraphTraits<> for your
comment|// graph, or you need to define it for a new graph type. Either that or
comment|// your argument to XXX_begin(...) is unknown or needs to have the proper .h
comment|// file #include'd.
name|using
name|NodeRef
operator|=
name|typename
name|GraphType
operator|::
name|UnknownGraphTypeError
block|; }
expr_stmt|;
comment|// Inverse - This class is used as a little marker class to tell the graph
comment|// iterator to iterate over the graph in a graph defined "Inverse" ordering.
comment|// Not all graphs define an inverse ordering, and if they do, it depends on
comment|// the graph exactly what that is.  Here's an example of usage with the
comment|// df_iterator:
comment|//
comment|// idf_iterator<Method*> I = idf_begin(M), E = idf_end(M);
comment|// for (; I != E; ++I) { ... }
comment|//
comment|// Which is equivalent to:
comment|// df_iterator<Inverse<Method*>> I = idf_begin(M), E = idf_end(M);
comment|// for (; I != E; ++I) { ... }
comment|//
name|template
operator|<
name|class
name|GraphType
operator|>
expr|struct
name|Inverse
block|{
specifier|const
name|GraphType
operator|&
name|Graph
block|;
specifier|inline
name|Inverse
argument_list|(
specifier|const
name|GraphType
operator|&
name|G
argument_list|)
operator|:
name|Graph
argument_list|(
argument|G
argument_list|)
block|{}
block|}
expr_stmt|;
comment|// Provide a partial specialization of GraphTraits so that the inverse of an
comment|// inverse falls back to the original graph.
name|template
operator|<
name|class
name|T
operator|>
expr|struct
name|GraphTraits
operator|<
name|Inverse
operator|<
name|Inverse
operator|<
name|T
operator|>>>
operator|:
name|GraphTraits
operator|<
name|T
operator|>
block|{}
expr_stmt|;
comment|// Provide iterator ranges for the graph traits nodes and children
name|template
operator|<
name|class
name|GraphType
operator|>
name|iterator_range
operator|<
name|typename
name|GraphTraits
operator|<
name|GraphType
operator|>
operator|::
name|nodes_iterator
operator|>
name|nodes
argument_list|(
argument|const GraphType&G
argument_list|)
block|{
return|return
name|make_range
argument_list|(
name|GraphTraits
operator|<
name|GraphType
operator|>
operator|::
name|nodes_begin
argument_list|(
name|G
argument_list|)
argument_list|,
name|GraphTraits
operator|<
name|GraphType
operator|>
operator|::
name|nodes_end
argument_list|(
name|G
argument_list|)
argument_list|)
return|;
block|}
name|template
operator|<
name|class
name|GraphType
operator|>
name|iterator_range
operator|<
name|typename
name|GraphTraits
operator|<
name|Inverse
operator|<
name|GraphType
operator|>>
operator|::
name|nodes_iterator
operator|>
name|inverse_nodes
argument_list|(
argument|const GraphType&G
argument_list|)
block|{
return|return
name|make_range
argument_list|(
name|GraphTraits
operator|<
name|Inverse
operator|<
name|GraphType
operator|>>
operator|::
name|nodes_begin
argument_list|(
name|G
argument_list|)
argument_list|,
name|GraphTraits
operator|<
name|Inverse
operator|<
name|GraphType
operator|>>
operator|::
name|nodes_end
argument_list|(
name|G
argument_list|)
argument_list|)
return|;
block|}
name|template
operator|<
name|class
name|GraphType
operator|>
name|iterator_range
operator|<
name|typename
name|GraphTraits
operator|<
name|GraphType
operator|>
operator|::
name|ChildIteratorType
operator|>
name|children
argument_list|(
argument|const typename GraphTraits<GraphType>::NodeRef&G
argument_list|)
block|{
return|return
name|make_range
argument_list|(
name|GraphTraits
operator|<
name|GraphType
operator|>
operator|::
name|child_begin
argument_list|(
name|G
argument_list|)
argument_list|,
name|GraphTraits
operator|<
name|GraphType
operator|>
operator|::
name|child_end
argument_list|(
name|G
argument_list|)
argument_list|)
return|;
block|}
name|template
operator|<
name|class
name|GraphType
operator|>
name|iterator_range
operator|<
name|typename
name|GraphTraits
operator|<
name|Inverse
operator|<
name|GraphType
operator|>>
operator|::
name|ChildIteratorType
operator|>
name|inverse_children
argument_list|(
argument|const typename GraphTraits<GraphType>::NodeRef&G
argument_list|)
block|{
return|return
name|make_range
argument_list|(
name|GraphTraits
operator|<
name|Inverse
operator|<
name|GraphType
operator|>>
operator|::
name|child_begin
argument_list|(
name|G
argument_list|)
argument_list|,
name|GraphTraits
operator|<
name|Inverse
operator|<
name|GraphType
operator|>>
operator|::
name|child_end
argument_list|(
name|G
argument_list|)
argument_list|)
return|;
block|}
block|}
end_decl_stmt

begin_comment
comment|// end namespace llvm
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// LLVM_ADT_GRAPHTRAITS_H
end_comment

end_unit

