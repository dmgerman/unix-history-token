begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- OptionGroupVariable.h -----------------------------------*- C++ -*-===//
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
name|liblldb_OptionGroupVariable_h_
end_ifndef

begin_define
define|#
directive|define
name|liblldb_OptionGroupVariable_h_
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
file|"lldb/Interpreter/OptionValueString.h"
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
comment|// OptionGroupVariable
comment|//-------------------------------------------------------------------------
name|class
name|OptionGroupVariable
range|:
name|public
name|OptionGroup
block|{
name|public
operator|:
name|OptionGroupVariable
argument_list|(
argument|bool show_frame_options
argument_list|)
block|;
operator|~
name|OptionGroupVariable
argument_list|()
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
name|Status
name|SetOptionValue
argument_list|(
argument|uint32_t option_idx
argument_list|,
argument|llvm::StringRef option_value
argument_list|,
argument|ExecutionContext *execution_context
argument_list|)
name|override
block|;
name|Status
name|SetOptionValue
argument_list|(
name|uint32_t
argument_list|,
specifier|const
name|char
operator|*
argument_list|,
name|ExecutionContext
operator|*
argument_list|)
operator|=
name|delete
block|;
name|void
name|OptionParsingStarting
argument_list|(
argument|ExecutionContext *execution_context
argument_list|)
name|override
block|;
name|bool
name|include_frame_options
operator|:
literal|1
block|,
name|show_args
operator|:
literal|1
block|,
comment|// Frame option only (include_frame_options == true)
name|show_locals
operator|:
literal|1
block|,
comment|// Frame option only (include_frame_options == true)
name|show_globals
operator|:
literal|1
block|,
comment|// Frame option only (include_frame_options == true)
name|use_regex
operator|:
literal|1
block|,
name|show_scope
operator|:
literal|1
block|,
name|show_decl
operator|:
literal|1
block|;
name|OptionValueString
name|summary
block|;
comment|// the name of a named summary
name|OptionValueString
name|summary_string
block|;
comment|// a summary string
name|private
operator|:
name|DISALLOW_COPY_AND_ASSIGN
argument_list|(
name|OptionGroupVariable
argument_list|)
block|; }
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
comment|// liblldb_OptionGroupVariable_h_
end_comment

end_unit

