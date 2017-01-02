begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- lld/Core/Node.h - Input file class -----------------------*- C++ -*-===//
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//                             The LLVM Linker
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
comment|///
end_comment

begin_comment
comment|/// \file
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// The classes in this file represents inputs to the linker.
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
name|LLD_CORE_NODE_H
end_ifndef

begin_define
define|#
directive|define
name|LLD_CORE_NODE_H
end_define

begin_include
include|#
directive|include
file|"lld/Core/File.h"
end_include

begin_include
include|#
directive|include
file|<algorithm>
end_include

begin_include
include|#
directive|include
file|<memory>
end_include

begin_decl_stmt
name|namespace
name|lld
block|{
comment|// A Node represents a FileNode or other type of Node. In the latter case,
comment|// the node contains meta information about the input file list.
comment|// Currently only GroupEnd node is defined as a meta node.
name|class
name|Node
block|{
name|public
label|:
name|enum
name|class
name|Kind
block|{
name|File
operator|,
name|GroupEnd
block|}
empty_stmt|;
name|explicit
name|Node
argument_list|(
argument|Kind type
argument_list|)
block|:
name|_kind
argument_list|(
argument|type
argument_list|)
block|{}
name|virtual
operator|~
name|Node
argument_list|()
operator|=
expr|default
expr_stmt|;
name|virtual
name|Kind
name|kind
argument_list|()
specifier|const
block|{
return|return
name|_kind
return|;
block|}
name|private
label|:
name|Kind
name|_kind
decl_stmt|;
block|}
empty_stmt|;
comment|// This is a marker for --end-group. getSize() returns the number of
comment|// files between the corresponding --start-group and this marker.
name|class
name|GroupEnd
range|:
name|public
name|Node
block|{
name|public
operator|:
name|explicit
name|GroupEnd
argument_list|(
argument|int size
argument_list|)
operator|:
name|Node
argument_list|(
name|Kind
operator|::
name|GroupEnd
argument_list|)
block|,
name|_size
argument_list|(
argument|size
argument_list|)
block|{}
name|int
name|getSize
argument_list|()
specifier|const
block|{
return|return
name|_size
return|;
block|}
specifier|static
name|bool
name|classof
argument_list|(
argument|const Node *a
argument_list|)
block|{
return|return
name|a
operator|->
name|kind
argument_list|()
operator|==
name|Kind
operator|::
name|GroupEnd
return|;
block|}
name|private
operator|:
name|int
name|_size
block|; }
decl_stmt|;
comment|// A container of File.
name|class
name|FileNode
range|:
name|public
name|Node
block|{
name|public
operator|:
name|explicit
name|FileNode
argument_list|(
name|std
operator|::
name|unique_ptr
operator|<
name|File
operator|>
name|f
argument_list|)
operator|:
name|Node
argument_list|(
name|Node
operator|::
name|Kind
operator|::
name|File
argument_list|)
block|,
name|_file
argument_list|(
argument|std::move(f)
argument_list|)
block|{}
specifier|static
name|bool
name|classof
argument_list|(
argument|const Node *a
argument_list|)
block|{
return|return
name|a
operator|->
name|kind
argument_list|()
operator|==
name|Node
operator|::
name|Kind
operator|::
name|File
return|;
block|}
name|File
operator|*
name|getFile
argument_list|()
block|{
return|return
name|_file
operator|.
name|get
argument_list|()
return|;
block|}
name|protected
operator|:
name|std
operator|::
name|unique_ptr
operator|<
name|File
operator|>
name|_file
block|; }
decl_stmt|;
block|}
end_decl_stmt

begin_comment
comment|// end namespace lld
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// LLD_CORE_NODE_H
end_comment

end_unit

