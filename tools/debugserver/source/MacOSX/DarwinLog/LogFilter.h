begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- LogFilter.h ---------------------------------------------*- C++ -*-===//
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
name|LogFilter_h
end_ifndef

begin_define
define|#
directive|define
name|LogFilter_h
end_define

begin_include
include|#
directive|include
file|"DarwinLogInterfaces.h"
end_include

begin_decl_stmt
name|class
name|LogFilter
block|{
name|public
label|:
name|virtual
operator|~
name|LogFilter
argument_list|()
expr_stmt|;
name|virtual
name|bool
name|DoesMatch
argument_list|(
specifier|const
name|LogMessage
operator|&
name|message
argument_list|)
decl|const
init|=
literal|0
decl_stmt|;
name|bool
name|MatchesAreAccepted
argument_list|()
specifier|const
block|{
return|return
name|m_matches_accept
return|;
block|}
name|protected
label|:
name|LogFilter
argument_list|(
argument|bool matches_accept
argument_list|)
block|:
name|m_matches_accept
argument_list|(
argument|matches_accept
argument_list|)
block|{}
name|private
label|:
name|bool
name|m_matches_accept
decl_stmt|;
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
comment|/* LogFilter_h */
end_comment

end_unit

