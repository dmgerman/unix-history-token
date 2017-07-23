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
name|liblldb_OptionValueChar_h_
end_ifndef

begin_define
define|#
directive|define
name|liblldb_OptionValueChar_h_
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
name|OptionValueChar
range|:
name|public
name|OptionValue
block|{
name|public
operator|:
name|OptionValueChar
argument_list|(
argument|char value
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
block|{}
name|OptionValueChar
argument_list|(
argument|char current_value
argument_list|,
argument|char default_value
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
block|{}
operator|~
name|OptionValueChar
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
name|eTypeChar
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
name|Status
name|SetValueFromString
argument_list|(
argument|llvm::StringRef value
argument_list|,
argument|VarSetOperationType op = eVarSetOperationAssign
argument_list|)
name|override
block|;
name|Status
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
return|return
name|true
return|;
block|}
comment|//---------------------------------------------------------------------
comment|// Subclass specific functions
comment|//---------------------------------------------------------------------
specifier|const
name|char
operator|&
name|operator
operator|=
operator|(
name|char
name|c
operator|)
block|{
name|m_current_value
operator|=
name|c
block|;
return|return
name|m_current_value
return|;
block|}
name|char
name|GetCurrentValue
argument_list|()
specifier|const
block|{
return|return
name|m_current_value
return|;
block|}
name|char
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
argument|char value
argument_list|)
block|{
name|m_current_value
operator|=
name|value
block|; }
name|void
name|SetDefaultValue
argument_list|(
argument|char value
argument_list|)
block|{
name|m_default_value
operator|=
name|value
block|; }
name|lldb
operator|::
name|OptionValueSP
name|DeepCopy
argument_list|()
specifier|const
name|override
block|;
name|protected
operator|:
name|char
name|m_current_value
block|;
name|char
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
comment|// liblldb_OptionValueChar_h_
end_comment

end_unit

