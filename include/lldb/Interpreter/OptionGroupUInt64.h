begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- OptionGroupUInt64.h -------------------------------------*- C++ -*-===//
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
name|liblldb_OptionGroupUInt64_h_
end_ifndef

begin_define
define|#
directive|define
name|liblldb_OptionGroupUInt64_h_
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
file|"lldb/Interpreter/OptionValueUInt64.h"
end_include

begin_decl_stmt
name|namespace
name|lldb_private
block|{
comment|//-------------------------------------------------------------------------
comment|// OptionGroupUInt64
comment|//-------------------------------------------------------------------------
name|class
name|OptionGroupUInt64
range|:
name|public
name|OptionGroup
block|{
name|public
operator|:
name|OptionGroupUInt64
argument_list|(
argument|uint32_t usage_mask
argument_list|,
argument|bool required
argument_list|,
argument|const char *long_option
argument_list|,
argument|int short_option
argument_list|,
argument|uint32_t completion_type
argument_list|,
argument|lldb::CommandArgumentType argument_type
argument_list|,
argument|const char *usage_text
argument_list|,
argument|uint64_t default_value
argument_list|)
block|;
operator|~
name|OptionGroupUInt64
argument_list|()
name|override
block|;
name|uint32_t
name|GetNumDefinitions
argument_list|()
name|override
block|{
return|return
literal|1
return|;
block|}
specifier|const
name|OptionDefinition
operator|*
name|GetDefinitions
argument_list|()
name|override
block|{
return|return
operator|&
name|m_option_definition
return|;
block|}
name|Error
name|SetOptionValue
argument_list|(
argument|CommandInterpreter&interpreter
argument_list|,
argument|uint32_t option_idx
argument_list|,
argument|const char *option_value
argument_list|)
name|override
block|;
name|void
name|OptionParsingStarting
argument_list|(
argument|CommandInterpreter&interpreter
argument_list|)
name|override
block|;
name|OptionValueUInt64
operator|&
name|GetOptionValue
argument_list|()
block|{
return|return
name|m_value
return|;
block|}
specifier|const
name|OptionValueUInt64
operator|&
name|GetOptionValue
argument_list|()
specifier|const
block|{
return|return
name|m_value
return|;
block|}
name|protected
operator|:
name|OptionValueUInt64
name|m_value
block|;
name|OptionDefinition
name|m_option_definition
block|;     }
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
comment|// liblldb_OptionGroupUInt64_h_
end_comment

end_unit

