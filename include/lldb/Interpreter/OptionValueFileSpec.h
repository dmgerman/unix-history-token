begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- OptionValueFileSpec.h -----------------------------------*- C++ -*-===//
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
name|liblldb_OptionValueFileSpec_h_
end_ifndef

begin_define
define|#
directive|define
name|liblldb_OptionValueFileSpec_h_
end_define

begin_include
include|#
directive|include
file|"lldb/Interpreter/OptionValue.h"
end_include

begin_include
include|#
directive|include
file|"lldb/Utility/FileSpec.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/Chrono.h"
end_include

begin_decl_stmt
name|namespace
name|lldb_private
block|{
name|class
name|OptionValueFileSpec
range|:
name|public
name|OptionValue
block|{
name|public
operator|:
name|OptionValueFileSpec
argument_list|(
argument|bool resolve = true
argument_list|)
block|;
name|OptionValueFileSpec
argument_list|(
argument|const FileSpec&value
argument_list|,
argument|bool resolve = true
argument_list|)
block|;
name|OptionValueFileSpec
argument_list|(
argument|const FileSpec&current_value
argument_list|,
argument|const FileSpec&default_value
argument_list|,
argument|bool resolve = true
argument_list|)
block|;
operator|~
name|OptionValueFileSpec
argument_list|()
name|override
block|{}
comment|//---------------------------------------------------------------------
comment|// Virtual subclass pure virtual overrides
comment|//---------------------------------------------------------------------
name|OptionValue
operator|::
name|Type
name|GetType
argument_list|()
specifier|const
name|override
block|{
return|return
name|eTypeFileSpec
return|;
block|}
name|void
name|DumpValue
argument_list|(
argument|const ExecutionContext *exe_ctx
argument_list|,
argument|Stream&strm
argument_list|,
argument|uint32_t dump_mask
argument_list|)
name|override
block|;
name|Error
name|SetValueFromString
argument_list|(
argument|llvm::StringRef value
argument_list|,
argument|VarSetOperationType op = eVarSetOperationAssign
argument_list|)
name|override
block|;
name|Error
name|SetValueFromString
argument_list|(
specifier|const
name|char
operator|*
argument_list|,
name|VarSetOperationType
operator|=
name|eVarSetOperationAssign
argument_list|)
operator|=
name|delete
block|;
name|bool
name|Clear
argument_list|()
name|override
block|{
name|m_current_value
operator|=
name|m_default_value
block|;
name|m_value_was_set
operator|=
name|false
block|;
name|m_data_sp
operator|.
name|reset
argument_list|()
block|;
name|m_data_mod_time
operator|=
name|llvm
operator|::
name|sys
operator|::
name|TimePoint
operator|<
operator|>
operator|(
operator|)
block|;
return|return
name|true
return|;
block|}
name|lldb
operator|::
name|OptionValueSP
name|DeepCopy
argument_list|()
specifier|const
name|override
block|;
name|size_t
name|AutoComplete
argument_list|(
argument|CommandInterpreter&interpreter
argument_list|,
argument|llvm::StringRef s
argument_list|,
argument|int match_start_point
argument_list|,
argument|int max_return_elements
argument_list|,
argument|bool&word_complete
argument_list|,
argument|StringList&matches
argument_list|)
name|override
block|;
comment|//---------------------------------------------------------------------
comment|// Subclass specific functions
comment|//---------------------------------------------------------------------
name|FileSpec
operator|&
name|GetCurrentValue
argument_list|()
block|{
return|return
name|m_current_value
return|;
block|}
specifier|const
name|FileSpec
operator|&
name|GetCurrentValue
argument_list|()
specifier|const
block|{
return|return
name|m_current_value
return|;
block|}
specifier|const
name|FileSpec
operator|&
name|GetDefaultValue
argument_list|()
specifier|const
block|{
return|return
name|m_default_value
return|;
block|}
name|void
name|SetCurrentValue
argument_list|(
argument|const FileSpec&value
argument_list|,
argument|bool set_value_was_set
argument_list|)
block|{
name|m_current_value
operator|=
name|value
block|;
if|if
condition|(
name|set_value_was_set
condition|)
name|m_value_was_set
operator|=
name|true
expr_stmt|;
name|m_data_sp
operator|.
name|reset
argument_list|()
block|;   }
name|void
name|SetDefaultValue
argument_list|(
argument|const FileSpec&value
argument_list|)
block|{
name|m_default_value
operator|=
name|value
block|; }
specifier|const
name|lldb
operator|::
name|DataBufferSP
operator|&
name|GetFileContents
argument_list|(
argument|bool null_terminate
argument_list|)
decl_stmt|;
name|void
name|SetCompletionMask
parameter_list|(
name|uint32_t
name|mask
parameter_list|)
block|{
name|m_completion_mask
operator|=
name|mask
expr_stmt|;
block|}
name|protected
label|:
name|FileSpec
name|m_current_value
decl_stmt|;
name|FileSpec
name|m_default_value
decl_stmt|;
name|lldb
operator|::
name|DataBufferSP
name|m_data_sp
expr_stmt|;
name|llvm
operator|::
name|sys
operator|::
name|TimePoint
operator|<
operator|>
name|m_data_mod_time
expr_stmt|;
name|uint32_t
name|m_completion_mask
decl_stmt|;
name|bool
name|m_resolve
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
comment|// liblldb_OptionValueFileSpec_h_
end_comment

end_unit

