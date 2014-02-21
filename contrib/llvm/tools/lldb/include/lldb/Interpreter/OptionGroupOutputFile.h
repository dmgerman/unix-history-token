begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- OptionGroupOutputFile.h -------------------------------*- C++ -*-===//
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
name|liblldb_OptionGroupOutputFile_h_
end_ifndef

begin_define
define|#
directive|define
name|liblldb_OptionGroupOutputFile_h_
end_define

begin_comment
comment|// C Includes
end_comment

begin_comment
comment|// C++ Includes
end_comment

begin_comment
comment|// Other libraries and framework includes
end_comment

begin_comment
comment|// Project includes
end_comment

begin_include
include|#
directive|include
file|"lldb/Interpreter/Options.h"
end_include

begin_include
include|#
directive|include
file|"lldb/Interpreter/OptionValueBoolean.h"
end_include

begin_include
include|#
directive|include
file|"lldb/Interpreter/OptionValueFileSpec.h"
end_include

begin_decl_stmt
name|namespace
name|lldb_private
block|{
comment|//-------------------------------------------------------------------------
comment|// OptionGroupOutputFile
comment|//-------------------------------------------------------------------------
name|class
name|OptionGroupOutputFile
range|:
name|public
name|OptionGroup
block|{
name|public
operator|:
name|OptionGroupOutputFile
argument_list|()
block|;
name|virtual
operator|~
name|OptionGroupOutputFile
argument_list|()
block|;
name|virtual
name|uint32_t
name|GetNumDefinitions
argument_list|()
block|;
name|virtual
specifier|const
name|OptionDefinition
operator|*
name|GetDefinitions
argument_list|()
block|;
name|virtual
name|Error
name|SetOptionValue
argument_list|(
argument|CommandInterpreter&interpreter
argument_list|,
argument|uint32_t option_idx
argument_list|,
argument|const char *option_value
argument_list|)
block|;
name|virtual
name|void
name|OptionParsingStarting
argument_list|(
name|CommandInterpreter
operator|&
name|interpreter
argument_list|)
block|;
specifier|const
name|OptionValueFileSpec
operator|&
name|GetFile
argument_list|()
block|{
return|return
name|m_file
return|;
block|}
specifier|const
name|OptionValueBoolean
operator|&
name|GetAppend
argument_list|()
block|{
return|return
name|m_append
return|;
block|}
name|bool
name|AnyOptionWasSet
argument_list|()
specifier|const
block|{
return|return
name|m_file
operator|.
name|OptionWasSet
argument_list|()
operator|||
name|m_append
operator|.
name|OptionWasSet
argument_list|()
return|;
block|}
name|protected
operator|:
name|OptionValueFileSpec
name|m_file
block|;
name|OptionValueBoolean
name|m_append
block|;      }
decl_stmt|;
block|}
end_decl_stmt

begin_comment
comment|// namespace lldb_private
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// liblldb_OptionGroupOutputFile_h_
end_comment

end_unit

