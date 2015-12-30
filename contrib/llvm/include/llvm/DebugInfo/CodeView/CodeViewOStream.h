begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- CodeViewOStream.h ----------------------------------------*- C++ -*-===//
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

begin_ifndef
ifndef|#
directive|ifndef
name|LLVM_DEBUGINFO_CODEVIEW_CODEVIEWOSTREAM_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_DEBUGINFO_CODEVIEW_CODEVIEWOSTREAM_H
end_define

begin_include
include|#
directive|include
file|"llvm/DebugInfo/CodeView/CodeView.h"
end_include

begin_include
include|#
directive|include
file|"llvm/DebugInfo/CodeView/TypeIndex.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|namespace
name|codeview
block|{
name|template
operator|<
name|typename
name|Writer
operator|>
name|class
name|CodeViewOStream
block|{
name|private
operator|:
name|CodeViewOStream
argument_list|(
specifier|const
name|CodeViewOStream
operator|&
argument_list|)
operator|=
name|delete
block|;
name|CodeViewOStream
operator|&
name|operator
operator|=
operator|(
specifier|const
name|CodeViewOStream
operator|&
operator|)
operator|=
name|delete
block|;
name|public
operator|:
typedef|typedef
name|typename
name|Writer
operator|::
name|LabelType
name|LabelType
expr_stmt|;
name|public
operator|:
name|explicit
name|CodeViewOStream
argument_list|(
name|Writer
operator|&
name|W
argument_list|)
expr_stmt|;
name|private
label|:
name|uint64_t
name|size
argument_list|()
specifier|const
block|{
return|return
name|W
operator|.
name|tell
argument_list|()
return|;
block|}
name|private
label|:
name|Writer
modifier|&
name|W
decl_stmt|;
block|}
empty_stmt|;
block|}
end_decl_stmt

begin_endif
unit|}
endif|#
directive|endif
end_endif

end_unit

