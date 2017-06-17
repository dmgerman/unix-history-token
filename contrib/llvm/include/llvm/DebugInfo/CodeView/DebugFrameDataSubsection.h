begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- DebugFrameDataSubsection.h ------------------------------*- C++ -*-===//
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
name|LLVM_DEBUGINFO_CODEVIEW_DEBUGFRAMEDATASUBSECTION_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_DEBUGINFO_CODEVIEW_DEBUGFRAMEDATASUBSECTION_H
end_define

begin_include
include|#
directive|include
file|"llvm/DebugInfo/CodeView/CodeView.h"
end_include

begin_include
include|#
directive|include
file|"llvm/DebugInfo/CodeView/DebugSubsection.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/BinaryStreamReader.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/Error.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|namespace
name|codeview
block|{
name|class
name|DebugFrameDataSubsectionRef
name|final
range|:
name|public
name|DebugSubsectionRef
block|{
name|public
operator|:
name|DebugFrameDataSubsectionRef
argument_list|()
operator|:
name|DebugSubsectionRef
argument_list|(
argument|DebugSubsectionKind::FrameData
argument_list|)
block|{}
specifier|static
name|bool
name|classof
argument_list|(
argument|const DebugSubsection *S
argument_list|)
block|{
return|return
name|S
operator|->
name|kind
argument_list|()
operator|==
name|DebugSubsectionKind
operator|::
name|FrameData
return|;
block|}
name|Error
name|initialize
argument_list|(
argument|BinaryStreamReader Reader
argument_list|)
block|;
name|FixedStreamArray
operator|<
name|FrameData
operator|>
operator|::
name|Iterator
name|begin
argument_list|()
specifier|const
block|{
return|return
name|Frames
operator|.
name|begin
argument_list|()
return|;
block|}
name|FixedStreamArray
operator|<
name|FrameData
operator|>
operator|::
name|Iterator
name|end
argument_list|()
specifier|const
block|{
return|return
name|Frames
operator|.
name|end
argument_list|()
return|;
block|}
specifier|const
name|void
operator|*
name|getRelocPtr
argument_list|()
specifier|const
block|{
return|return
name|RelocPtr
return|;
block|}
name|private
operator|:
specifier|const
name|uint32_t
operator|*
name|RelocPtr
operator|=
name|nullptr
block|;
name|FixedStreamArray
operator|<
name|FrameData
operator|>
name|Frames
block|; }
decl_stmt|;
name|class
name|DebugFrameDataSubsection
name|final
range|:
name|public
name|DebugSubsection
block|{
name|public
operator|:
name|DebugFrameDataSubsection
argument_list|()
operator|:
name|DebugSubsection
argument_list|(
argument|DebugSubsectionKind::FrameData
argument_list|)
block|{}
specifier|static
name|bool
name|classof
argument_list|(
argument|const DebugSubsection *S
argument_list|)
block|{
return|return
name|S
operator|->
name|kind
argument_list|()
operator|==
name|DebugSubsectionKind
operator|::
name|FrameData
return|;
block|}
name|uint32_t
name|calculateSerializedSize
argument_list|()
specifier|const
name|override
block|;
name|Error
name|commit
argument_list|(
argument|BinaryStreamWriter&Writer
argument_list|)
specifier|const
name|override
block|;
name|void
name|addFrameData
argument_list|(
specifier|const
name|FrameData
operator|&
name|Frame
argument_list|)
block|;
name|void
name|setFrames
argument_list|(
name|ArrayRef
operator|<
name|FrameData
operator|>
name|Frames
argument_list|)
block|;
name|private
operator|:
name|std
operator|::
name|vector
operator|<
name|FrameData
operator|>
name|Frames
block|; }
decl_stmt|;
block|}
block|}
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

