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
specifier|const
name|char
operator|*
name|GetPluginName
argument_list|()
block|{
if|if
condition|(
name|plugin_name
operator|.
name|empty
argument_list|()
condition|)
return|return
name|NULL
return|;
return|return
name|plugin_name
operator|.
name|c_str
argument_list|()
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
name|NULL
return|;
return|return
name|flavor_string
operator|.
name|c_str
argument_list|()
return|;
block|}
name|virtual
name|Error
name|OptionParsingFinished
parameter_list|()
function_decl|;
name|bool
name|show_mixed
decl_stmt|;
comment|// Show mixed source/assembly
name|bool
name|show_bytes
decl_stmt|;
name|uint32_t
name|num_lines_context
decl_stmt|;
name|uint32_t
name|num_instructions
decl_stmt|;
name|bool
name|raw
decl_stmt|;
name|std
operator|::
name|string
name|func_name
expr_stmt|;
name|bool
name|current_function
decl_stmt|;
name|lldb
operator|::
name|addr_t
name|start_addr
expr_stmt|;
name|lldb
operator|::
name|addr_t
name|end_addr
expr_stmt|;
name|bool
name|at_pc
decl_stmt|;
name|bool
name|frame_line
decl_stmt|;
name|std
operator|::
name|string
name|plugin_name
expr_stmt|;
name|std
operator|::
name|string
name|flavor_string
expr_stmt|;
name|ArchSpec
name|arch
decl_stmt|;
name|bool
name|some_location_specified
decl_stmt|;
comment|// If no location was specified, we'll select "at_pc".  This should be set
comment|// in SetOptionValue if anything the selects a location is set.
name|lldb
operator|::
name|addr_t
name|symbol_containing_addr
expr_stmt|;
specifier|static
name|OptionDefinition
name|g_option_table
index|[]
decl_stmt|;
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_expr_stmt
name|CommandObjectDisassemble
argument_list|(
name|CommandInterpreter
operator|&
name|interpreter
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|virtual
operator|~
name|CommandObjectDisassemble
argument_list|()
expr_stmt|;
end_expr_stmt

begin_function
name|virtual
name|Options
modifier|*
name|GetOptions
parameter_list|()
block|{
return|return
operator|&
name|m_options
return|;
block|}
end_function

begin_label
name|protected
label|:
end_label

begin_function_decl
name|virtual
name|bool
name|DoExecute
parameter_list|(
name|Args
modifier|&
name|command
parameter_list|,
name|CommandReturnObject
modifier|&
name|result
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
name|CommandOptions
name|m_options
decl_stmt|;
end_decl_stmt

begin_comment
unit|};  }
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

