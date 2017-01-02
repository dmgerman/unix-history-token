begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- ThreadInfo.h -----------------------------------------------*- C++
end_comment

begin_comment
comment|//-*-===//
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
name|__ThreadInfo_h__
end_ifndef

begin_define
define|#
directive|define
name|__ThreadInfo_h__
end_define

begin_decl_stmt
name|namespace
name|ThreadInfo
block|{
name|class
name|QoS
block|{
name|public
label|:
name|QoS
argument_list|()
operator|:
name|constant_name
argument_list|()
operator|,
name|printable_name
argument_list|()
operator|,
name|enum_value
argument_list|(
argument|UINT32_MAX
argument_list|)
block|{}
name|bool
name|IsValid
argument_list|()
block|{
return|return
name|enum_value
operator|!=
name|UINT32_MAX
return|;
block|}
name|std
operator|::
name|string
name|constant_name
expr_stmt|;
name|std
operator|::
name|string
name|printable_name
expr_stmt|;
name|uint32_t
name|enum_value
decl_stmt|;
block|}
empty_stmt|;
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// __ThreadInfo_h__
end_comment

end_unit

