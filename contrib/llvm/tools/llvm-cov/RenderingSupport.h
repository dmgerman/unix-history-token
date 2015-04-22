begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- RenderingSupport.h - output stream rendering support functions  ----===//
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
name|LLVM_COV_RENDERINGSUPPORT_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_COV_RENDERINGSUPPORT_H
end_define

begin_include
include|#
directive|include
file|"llvm/Support/raw_ostream.h"
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
comment|/// \brief A helper class that resets the output stream's color if needed
comment|/// when destroyed.
name|class
name|ColoredRawOstream
block|{
name|ColoredRawOstream
argument_list|(
argument|const ColoredRawOstream&OS
argument_list|)
name|LLVM_DELETED_FUNCTION
expr_stmt|;
name|public
label|:
name|raw_ostream
modifier|&
name|OS
decl_stmt|;
name|bool
name|IsColorUsed
decl_stmt|;
name|ColoredRawOstream
argument_list|(
argument|raw_ostream&OS
argument_list|,
argument|bool IsColorUsed
argument_list|)
block|:
name|OS
argument_list|(
name|OS
argument_list|)
operator|,
name|IsColorUsed
argument_list|(
argument|IsColorUsed
argument_list|)
block|{}
name|ColoredRawOstream
argument_list|(
name|ColoredRawOstream
operator|&&
name|Other
argument_list|)
operator|:
name|OS
argument_list|(
name|Other
operator|.
name|OS
argument_list|)
operator|,
name|IsColorUsed
argument_list|(
argument|Other.IsColorUsed
argument_list|)
block|{
comment|// Reset the other IsColorUsed so that the other object won't reset the
comment|// color when destroyed.
name|Other
operator|.
name|IsColorUsed
operator|=
name|false
block|;   }
operator|~
name|ColoredRawOstream
argument_list|()
block|{
if|if
condition|(
name|IsColorUsed
condition|)
name|OS
operator|.
name|resetColor
argument_list|()
expr_stmt|;
block|}
block|}
empty_stmt|;
name|template
operator|<
name|typename
name|T
operator|>
specifier|inline
name|raw_ostream
operator|&
name|operator
operator|<<
operator|(
specifier|const
name|ColoredRawOstream
operator|&
name|OS
operator|,
name|T
operator|&&
name|Value
operator|)
block|{
return|return
name|OS
operator|.
name|OS
operator|<<
name|std
operator|::
name|forward
operator|<
name|T
operator|>
operator|(
name|Value
operator|)
return|;
block|}
comment|/// \brief Change the color of the output stream if the `IsColorUsed` flag
comment|/// is true. Returns an object that resets the color when destroyed.
specifier|inline
name|ColoredRawOstream
name|colored_ostream
argument_list|(
name|raw_ostream
operator|&
name|OS
argument_list|,
name|raw_ostream
operator|::
name|Colors
name|Color
argument_list|,
name|bool
name|IsColorUsed
operator|=
name|true
argument_list|,
name|bool
name|Bold
operator|=
name|false
argument_list|,
name|bool
name|BG
operator|=
name|false
argument_list|)
block|{
if|if
condition|(
name|IsColorUsed
condition|)
name|OS
operator|.
name|changeColor
argument_list|(
name|Color
argument_list|,
name|Bold
argument_list|,
name|BG
argument_list|)
expr_stmt|;
return|return
name|ColoredRawOstream
argument_list|(
name|OS
argument_list|,
name|IsColorUsed
argument_list|)
return|;
block|}
block|}
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// LLVM_COV_RENDERINGSUPPORT_H
end_comment

end_unit

