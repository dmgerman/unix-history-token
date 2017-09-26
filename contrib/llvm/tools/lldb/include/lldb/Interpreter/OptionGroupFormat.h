begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- OptionGroupFormat.h -------------------------------------*- C++ -*-===//
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
name|liblldb_OptionGroupFormat_h_
end_ifndef

begin_define
define|#
directive|define
name|liblldb_OptionGroupFormat_h_
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
file|"lldb/Interpreter/OptionValueFormat.h"
end_include

begin_include
include|#
directive|include
file|"lldb/Interpreter/OptionValueSInt64.h"
end_include

begin_include
include|#
directive|include
file|"lldb/Interpreter/OptionValueUInt64.h"
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
comment|// OptionGroupFormat
comment|//-------------------------------------------------------------------------
name|class
name|OptionGroupFormat
range|:
name|public
name|OptionGroup
block|{
name|public
operator|:
specifier|static
specifier|const
name|uint32_t
name|OPTION_GROUP_FORMAT
operator|=
name|LLDB_OPT_SET_1
block|;
specifier|static
specifier|const
name|uint32_t
name|OPTION_GROUP_GDB_FMT
operator|=
name|LLDB_OPT_SET_2
block|;
specifier|static
specifier|const
name|uint32_t
name|OPTION_GROUP_SIZE
operator|=
name|LLDB_OPT_SET_3
block|;
specifier|static
specifier|const
name|uint32_t
name|OPTION_GROUP_COUNT
operator|=
name|LLDB_OPT_SET_4
block|;
name|OptionGroupFormat
argument_list|(
argument|lldb::Format default_format
argument_list|,
argument|uint64_t default_byte_size =           UINT64_MAX
argument_list|,
comment|// Pass UINT64_MAX to disable the "--size" option
argument|uint64_t default_count =           UINT64_MAX
argument_list|)
block|;
comment|// Pass UINT64_MAX to disable the "--count" option
operator|~
name|OptionGroupFormat
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
name|lldb
operator|::
name|Format
name|GetFormat
argument_list|()
specifier|const
block|{
return|return
name|m_format
operator|.
name|GetCurrentValue
argument_list|()
return|;
block|}
name|OptionValueFormat
operator|&
name|GetFormatValue
argument_list|()
block|{
return|return
name|m_format
return|;
block|}
specifier|const
name|OptionValueFormat
operator|&
name|GetFormatValue
argument_list|()
specifier|const
block|{
return|return
name|m_format
return|;
block|}
name|OptionValueUInt64
operator|&
name|GetByteSizeValue
argument_list|()
block|{
return|return
name|m_byte_size
return|;
block|}
specifier|const
name|OptionValueUInt64
operator|&
name|GetByteSizeValue
argument_list|()
specifier|const
block|{
return|return
name|m_byte_size
return|;
block|}
name|OptionValueUInt64
operator|&
name|GetCountValue
argument_list|()
block|{
return|return
name|m_count
return|;
block|}
specifier|const
name|OptionValueUInt64
operator|&
name|GetCountValue
argument_list|()
specifier|const
block|{
return|return
name|m_count
return|;
block|}
name|bool
name|HasGDBFormat
argument_list|()
specifier|const
block|{
return|return
name|m_has_gdb_format
return|;
block|}
name|bool
name|AnyOptionWasSet
argument_list|()
specifier|const
block|{
return|return
name|m_format
operator|.
name|OptionWasSet
argument_list|()
operator|||
name|m_byte_size
operator|.
name|OptionWasSet
argument_list|()
operator|||
name|m_count
operator|.
name|OptionWasSet
argument_list|()
return|;
block|}
name|protected
operator|:
name|bool
name|ParserGDBFormatLetter
argument_list|(
argument|ExecutionContext *execution_context
argument_list|,
argument|char format_letter
argument_list|,
argument|lldb::Format&format
argument_list|,
argument|uint32_t&byte_size
argument_list|)
block|;
name|OptionValueFormat
name|m_format
block|;
name|OptionValueUInt64
name|m_byte_size
block|;
name|OptionValueUInt64
name|m_count
block|;
name|char
name|m_prev_gdb_format
block|;
name|char
name|m_prev_gdb_size
block|;
name|bool
name|m_has_gdb_format
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
comment|// liblldb_OptionGroupFormat_h_
end_comment

end_unit

