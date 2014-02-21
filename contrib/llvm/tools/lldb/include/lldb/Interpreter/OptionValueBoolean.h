begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- OptionValueBoolean.h ------------------------------------*- C++ -*-===//
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
name|liblldb_OptionValueBoolean_h_
end_ifndef

begin_define
define|#
directive|define
name|liblldb_OptionValueBoolean_h_
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
file|"lldb/Interpreter/OptionValue.h"
end_include

begin_decl_stmt
name|namespace
name|lldb_private
block|{
name|class
name|OptionValueBoolean
range|:
name|public
name|OptionValue
block|{
name|public
operator|:
name|OptionValueBoolean
argument_list|(
argument|bool value
argument_list|)
operator|:
name|OptionValue
argument_list|()
block|,
name|m_current_value
argument_list|(
name|value
argument_list|)
block|,
name|m_default_value
argument_list|(
argument|value
argument_list|)
block|{     }
name|OptionValueBoolean
argument_list|(
argument|bool current_value
argument_list|,
argument|bool default_value
argument_list|)
operator|:
name|OptionValue
argument_list|()
block|,
name|m_current_value
argument_list|(
name|current_value
argument_list|)
block|,
name|m_default_value
argument_list|(
argument|default_value
argument_list|)
block|{     }
name|virtual
operator|~
name|OptionValueBoolean
argument_list|()
block|{     }
comment|//---------------------------------------------------------------------
comment|// Virtual subclass pure virtual overrides
comment|//---------------------------------------------------------------------
name|virtual
name|OptionValue
operator|::
name|Type
name|GetType
argument_list|()
specifier|const
block|{
return|return
name|eTypeBoolean
return|;
block|}
name|virtual
name|void
name|DumpValue
argument_list|(
argument|const ExecutionContext *exe_ctx
argument_list|,
argument|Stream&strm
argument_list|,
argument|uint32_t dump_mask
argument_list|)
block|;
name|virtual
name|Error
name|SetValueFromCString
argument_list|(
argument|const char *value
argument_list|,
argument|VarSetOperationType op = eVarSetOperationAssign
argument_list|)
block|;
name|virtual
name|bool
name|Clear
argument_list|()
block|{
name|m_current_value
operator|=
name|m_default_value
block|;
name|m_value_was_set
operator|=
name|false
block|;
return|return
name|true
return|;
block|}
name|virtual
name|size_t
name|AutoComplete
argument_list|(
argument|CommandInterpreter&interpreter
argument_list|,
argument|const char *s
argument_list|,
argument|int match_start_point
argument_list|,
argument|int max_return_elements
argument_list|,
argument|bool&word_complete
argument_list|,
argument|StringList&matches
argument_list|)
block|;
comment|//---------------------------------------------------------------------
comment|// Subclass specific functions
comment|//---------------------------------------------------------------------
comment|//------------------------------------------------------------------
comment|/// Convert to bool operator.
comment|///
comment|/// This allows code to check a OptionValueBoolean in conditions.
comment|///
comment|/// @code
comment|/// OptionValueBoolean bool_value(...);
comment|/// if (bool_value)
comment|/// { ...
comment|/// @endcode
comment|///
comment|/// @return
comment|///     /b True this object contains a valid namespace decl, \b
comment|///     false otherwise.
comment|//------------------------------------------------------------------
name|explicit
name|operator
name|bool
argument_list|()
specifier|const
block|{
return|return
name|m_current_value
return|;
block|}
specifier|const
name|bool
operator|&
name|operator
operator|=
operator|(
name|bool
name|b
operator|)
block|{
name|m_current_value
operator|=
name|b
block|;
return|return
name|m_current_value
return|;
block|}
name|bool
name|GetCurrentValue
argument_list|()
specifier|const
block|{
return|return
name|m_current_value
return|;
block|}
name|bool
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
argument|bool value
argument_list|)
block|{
name|m_current_value
operator|=
name|value
block|;     }
name|void
name|SetDefaultValue
argument_list|(
argument|bool value
argument_list|)
block|{
name|m_default_value
operator|=
name|value
block|;     }
name|virtual
name|lldb
operator|::
name|OptionValueSP
name|DeepCopy
argument_list|()
specifier|const
block|;
name|protected
operator|:
name|bool
name|m_current_value
block|;
name|bool
name|m_default_value
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
comment|// liblldb_OptionValueBoolean_h_
end_comment

end_unit

