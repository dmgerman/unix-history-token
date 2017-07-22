begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- OptionValueFormatEntity.h --------------------------------*- C++-*-===//
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
name|liblldb_OptionValueFormatEntity_h_
end_ifndef

begin_define
define|#
directive|define
name|liblldb_OptionValueFormatEntity_h_
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
file|"lldb/Core/FormatEntity.h"
end_include

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
name|OptionValueFormatEntity
range|:
name|public
name|OptionValue
block|{
name|public
operator|:
name|OptionValueFormatEntity
argument_list|(
specifier|const
name|char
operator|*
name|default_format
argument_list|)
block|;
operator|~
name|OptionValueFormatEntity
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
name|eTypeFormatEntity
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
block|;
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
name|FormatEntity
operator|::
name|Entry
operator|&
name|GetCurrentValue
argument_list|()
block|{
return|return
name|m_current_entry
return|;
block|}
specifier|const
name|FormatEntity
operator|::
name|Entry
operator|&
name|GetCurrentValue
argument_list|()
specifier|const
block|{
return|return
name|m_current_entry
return|;
block|}
name|void
name|SetCurrentValue
argument_list|(
argument|const FormatEntity::Entry&value
argument_list|)
block|{
name|m_current_entry
operator|=
name|value
block|;   }
name|FormatEntity
operator|::
name|Entry
operator|&
name|GetDefaultValue
argument_list|()
block|{
return|return
name|m_default_entry
return|;
block|}
specifier|const
name|FormatEntity
operator|::
name|Entry
operator|&
name|GetDefaultValue
argument_list|()
specifier|const
block|{
return|return
name|m_default_entry
return|;
block|}
name|protected
operator|:
name|std
operator|::
name|string
name|m_current_format
block|;
name|std
operator|::
name|string
name|m_default_format
block|;
name|FormatEntity
operator|::
name|Entry
name|m_current_entry
block|;
name|FormatEntity
operator|::
name|Entry
name|m_default_entry
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
comment|// liblldb_OptionValueFormatEntity_h_
end_comment

end_unit

