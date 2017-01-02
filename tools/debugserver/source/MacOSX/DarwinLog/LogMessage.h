begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- LogMessage.h --------------------------------------------*- C++ -*-===//
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
name|LogMessage_h
end_ifndef

begin_define
define|#
directive|define
name|LogMessage_h
end_define

begin_include
include|#
directive|include
file|<string>
end_include

begin_decl_stmt
name|class
name|LogMessage
block|{
name|public
label|:
name|virtual
operator|~
name|LogMessage
argument_list|()
expr_stmt|;
name|virtual
name|bool
name|HasActivity
argument_list|()
specifier|const
operator|=
literal|0
expr_stmt|;
name|virtual
specifier|const
name|char
operator|*
name|GetActivity
argument_list|()
specifier|const
operator|=
literal|0
expr_stmt|;
name|virtual
name|std
operator|::
name|string
name|GetActivityChain
argument_list|()
specifier|const
operator|=
literal|0
expr_stmt|;
name|virtual
name|bool
name|HasCategory
argument_list|()
specifier|const
operator|=
literal|0
expr_stmt|;
name|virtual
specifier|const
name|char
operator|*
name|GetCategory
argument_list|()
specifier|const
operator|=
literal|0
expr_stmt|;
name|virtual
name|bool
name|HasSubsystem
argument_list|()
specifier|const
operator|=
literal|0
expr_stmt|;
name|virtual
specifier|const
name|char
operator|*
name|GetSubsystem
argument_list|()
specifier|const
operator|=
literal|0
expr_stmt|;
comment|// This can be expensive, so once we ask for it, we'll cache the result.
name|virtual
specifier|const
name|char
operator|*
name|GetMessage
argument_list|()
specifier|const
operator|=
literal|0
expr_stmt|;
name|protected
label|:
name|LogMessage
argument_list|()
expr_stmt|;
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
comment|/* LogMessage_h */
end_comment

end_unit

