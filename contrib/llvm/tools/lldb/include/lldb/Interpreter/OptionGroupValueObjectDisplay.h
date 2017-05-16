begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- OptionGroupValueObjectDisplay.h -------------------------*- C++ -*-===//
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
name|liblldb_OptionGroupValueObjectDisplay_h_
end_ifndef

begin_define
define|#
directive|define
name|liblldb_OptionGroupValueObjectDisplay_h_
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
file|"lldb/Core/ValueObject.h"
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
comment|// OptionGroupValueObjectDisplay
comment|//-------------------------------------------------------------------------
name|class
name|OptionGroupValueObjectDisplay
range|:
name|public
name|OptionGroup
block|{
name|public
operator|:
name|OptionGroupValueObjectDisplay
argument_list|()
block|;
operator|~
name|OptionGroupValueObjectDisplay
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
name|AnyOptionWasSet
argument_list|()
specifier|const
block|{
return|return
name|show_types
operator|||
name|no_summary_depth
operator|!=
literal|0
operator|||
name|show_location
operator|||
name|flat_output
operator|||
name|use_objc
operator|||
name|max_depth
operator|!=
name|UINT32_MAX
operator|||
name|ptr_depth
operator|!=
literal|0
operator|||
operator|!
name|use_synth
operator|||
name|be_raw
operator|||
name|ignore_cap
operator|||
name|run_validator
return|;
block|}
name|DumpValueObjectOptions
name|GetAsDumpOptions
argument_list|(
argument|LanguageRuntimeDescriptionDisplayVerbosity lang_descr_verbosity =           eLanguageRuntimeDescriptionDisplayVerbosityFull
argument_list|,
argument|lldb::Format format = lldb::eFormatDefault
argument_list|,
argument|lldb::TypeSummaryImplSP summary_sp = lldb::TypeSummaryImplSP()
argument_list|)
block|;
name|bool
name|show_types
operator|:
literal|1
block|,
name|show_location
operator|:
literal|1
block|,
name|flat_output
operator|:
literal|1
block|,
name|use_objc
operator|:
literal|1
block|,
name|use_synth
operator|:
literal|1
block|,
name|be_raw
operator|:
literal|1
block|,
name|ignore_cap
operator|:
literal|1
block|,
name|run_validator
operator|:
literal|1
block|;
name|uint32_t
name|no_summary_depth
block|;
name|uint32_t
name|max_depth
block|;
name|uint32_t
name|ptr_depth
block|;
name|uint32_t
name|elem_count
block|;
name|lldb
operator|::
name|DynamicValueType
name|use_dynamic
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
comment|// liblldb_OptionGroupValueObjectDisplay_h_
end_comment

end_unit

