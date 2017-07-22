begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- CommandObjectDisassemble.h ------------------------------*- C++ -*-===//
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
name|liblldb_CommandObjectDisassemble_h_
end_ifndef

begin_define
define|#
directive|define
name|liblldb_CommandObjectDisassemble_h_
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
file|"lldb/Core/ArchSpec.h"
end_include

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

begin_decl_stmt
name|namespace
name|lldb_private
block|{
comment|//-------------------------------------------------------------------------
comment|// CommandObjectDisassemble
comment|//-------------------------------------------------------------------------
name|class
name|CommandObjectDisassemble
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
argument_list|()
block|;
operator|~
name|CommandOptions
argument_list|()
name|override
block|;
name|Status
name|SetOptionValue
argument_list|(
argument|uint32_t option_idx
argument_list|,
argument|llvm::StringRef option_arg
argument_list|,
argument|ExecutionContext *execution_context
argument_list|)
name|override
block|;
name|void
name|OptionParsingStarting
argument_list|(
argument|ExecutionContext *execution_context
argument_list|)
name|override
block|;
name|llvm
operator|::
name|ArrayRef
operator|<
name|OptionDefinition
operator|>
name|GetDefinitions
argument_list|()
name|override
block|;
specifier|const
name|char
operator|*
name|GetPluginName
argument_list|()
block|{
return|return
operator|(
name|plugin_name
operator|.
name|empty
argument_list|()
operator|?
name|nullptr
operator|:
name|plugin_name
operator|.
name|c_str
argument_list|()
operator|)
return|;
block|}
specifier|const
name|char
operator|*
name|GetFlavorString
argument_list|()
block|{
if|if
condition|(
name|flavor_string
operator|.
name|empty
argument_list|()
operator|||
name|flavor_string
operator|==
literal|"default"
condition|)
return|return
name|nullptr
return|;
return|return
name|flavor_string
operator|.
name|c_str
argument_list|()
return|;
block|}
name|Status
name|OptionParsingFinished
argument_list|(
argument|ExecutionContext *execution_context
argument_list|)
name|override
block|;
name|bool
name|show_mixed
block|;
comment|// Show mixed source/assembly
name|bool
name|show_bytes
block|;
name|uint32_t
name|num_lines_context
block|;
name|uint32_t
name|num_instructions
block|;
name|bool
name|raw
block|;
name|std
operator|::
name|string
name|func_name
block|;
name|bool
name|current_function
block|;
name|lldb
operator|::
name|addr_t
name|start_addr
block|;
name|lldb
operator|::
name|addr_t
name|end_addr
block|;
name|bool
name|at_pc
block|;
name|bool
name|frame_line
block|;
name|std
operator|::
name|string
name|plugin_name
block|;
name|std
operator|::
name|string
name|flavor_string
block|;
name|ArchSpec
name|arch
block|;
name|bool
name|some_location_specified
block|;
comment|// If no location was specified, we'll select
comment|// "at_pc".  This should be set
comment|// in SetOptionValue if anything the selects a location is set.
name|lldb
operator|::
name|addr_t
name|symbol_containing_addr
block|;
specifier|static
name|OptionDefinition
name|g_option_table
index|[]
block|;   }
decl_stmt|;
name|CommandObjectDisassemble
argument_list|(
name|CommandInterpreter
operator|&
name|interpreter
argument_list|)
expr_stmt|;
operator|~
name|CommandObjectDisassemble
argument_list|()
name|override
expr_stmt|;
name|Options
modifier|*
name|GetOptions
parameter_list|()
function|override
block|{
return|return
operator|&
name|m_options
return|;
block|}
name|protected
label|:
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
name|override
decl_stmt|;
name|CommandOptions
name|m_options
decl_stmt|;
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
unit|}
comment|// namespace lldb_private
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// liblldb_CommandObjectDisassemble_h_
end_comment

end_unit

