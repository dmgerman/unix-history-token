begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- LogFilterRegex.h ----------------------------------------*- C++ -*-===//
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
name|LogFilterRegex_h
end_ifndef

begin_define
define|#
directive|define
name|LogFilterRegex_h
end_define

begin_comment
comment|// C includes
end_comment

begin_include
include|#
directive|include
file|<regex.h>
end_include

begin_comment
comment|// C++ includes
end_comment

begin_include
include|#
directive|include
file|<string>
end_include

begin_include
include|#
directive|include
file|"DarwinLogInterfaces.h"
end_include

begin_include
include|#
directive|include
file|"DarwinLogTypes.h"
end_include

begin_include
include|#
directive|include
file|"LogFilter.h"
end_include

begin_decl_stmt
name|class
name|LogFilterRegex
range|:
name|public
name|LogFilter
block|{
name|public
operator|:
name|LogFilterRegex
argument_list|(
argument|bool match_accepts
argument_list|,
argument|FilterTarget filter_target
argument_list|,
argument|const std::string&regex
argument_list|)
block|;
name|virtual
operator|~
name|LogFilterRegex
argument_list|()
block|;
name|bool
name|IsValid
argument_list|()
specifier|const
block|{
return|return
name|m_is_valid
return|;
block|}
specifier|const
name|char
operator|*
name|GetErrorAsCString
argument_list|()
specifier|const
block|{
return|return
name|m_error_text
operator|.
name|c_str
argument_list|()
return|;
block|}
name|bool
name|DoesMatch
argument_list|(
argument|const LogMessage&message
argument_list|)
specifier|const
name|override
block|;
name|private
operator|:
specifier|const
name|FilterTarget
name|m_filter_target
block|;
specifier|const
name|std
operator|::
name|string
name|m_regex_text
block|;
name|regex_t
name|m_regex
block|;
name|bool
name|m_is_valid
block|;
name|std
operator|::
name|string
name|m_error_text
block|; }
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* LogFilterSubsystemRegex_hpp */
end_comment

end_unit

