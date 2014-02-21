begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- CommandObjectArgs.h -------------------------------------*- C++ -*-===//
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
name|liblldb_CommandObjectArgs_h_
end_ifndef

begin_define
define|#
directive|define
name|liblldb_CommandObjectArgs_h_
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
file|"lldb/Interpreter/CommandObject.h"
end_include

begin_include
include|#
directive|include
file|"lldb/Interpreter/Options.h"
end_include

begin_include
include|#
directive|include
file|"lldb/Core/Language.h"
end_include

begin_decl_stmt
name|namespace
name|lldb_private
block|{
name|class
name|CommandObjectArgs
range|:
name|public
name|CommandObjectParsed
block|{
name|public
operator|:
name|class
name|CommandOptions
operator|:
name|public
name|Options
block|{
name|public
operator|:
name|CommandOptions
argument_list|(
name|CommandInterpreter
operator|&
name|interpreter
argument_list|)
block|;
name|virtual
operator|~
name|CommandOptions
argument_list|()
block|;
name|virtual
name|Error
name|SetOptionValue
argument_list|(
argument|uint32_t option_idx
argument_list|,
argument|const char *option_arg
argument_list|)
block|;
name|void
name|OptionParsingStarting
argument_list|()
block|;
specifier|const
name|OptionDefinition
operator|*
name|GetDefinitions
argument_list|()
block|;
comment|// Options table: Required for subclasses of Options.
specifier|static
name|OptionDefinition
name|g_option_table
index|[]
block|;         }
block|;
name|CommandObjectArgs
argument_list|(
name|CommandInterpreter
operator|&
name|interpreter
argument_list|)
block|;
name|virtual
operator|~
name|CommandObjectArgs
argument_list|()
block|;
name|virtual
name|Options
operator|*
name|GetOptions
argument_list|()
block|;
name|protected
operator|:
name|CommandOptions
name|m_options
block|;
name|virtual
name|bool
name|DoExecute
argument_list|(
name|Args
operator|&
name|command
argument_list|,
name|CommandReturnObject
operator|&
name|result
argument_list|)
block|;              }
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
comment|// liblldb_CommandObjectArgs_h_
end_comment

end_unit

