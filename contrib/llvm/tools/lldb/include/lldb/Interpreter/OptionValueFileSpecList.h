begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- OptionValueFileSpecList.h -------------------------------*- C++ -*-===//
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
name|liblldb_OptionValueFileSpecList_h_
end_ifndef

begin_define
define|#
directive|define
name|liblldb_OptionValueFileSpecList_h_
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
file|"lldb/Core/FileSpecList.h"
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
name|OptionValueFileSpecList
range|:
name|public
name|OptionValue
block|{
name|public
operator|:
name|OptionValueFileSpecList
argument_list|()
operator|:
name|OptionValue
argument_list|()
block|,
name|m_current_value
argument_list|()
block|{     }
name|OptionValueFileSpecList
argument_list|(
specifier|const
name|FileSpecList
operator|&
name|current_value
argument_list|)
operator|:
name|OptionValue
argument_list|()
block|,
name|m_current_value
argument_list|(
argument|current_value
argument_list|)
block|{     }
name|virtual
operator|~
name|OptionValueFileSpecList
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
name|eTypeFileSpecList
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
operator|.
name|Clear
argument_list|()
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
name|lldb
operator|::
name|OptionValueSP
name|DeepCopy
argument_list|()
specifier|const
block|;
name|virtual
name|bool
name|IsAggregateValue
argument_list|()
specifier|const
block|{
return|return
name|true
return|;
block|}
comment|//---------------------------------------------------------------------
comment|// Subclass specific functions
comment|//---------------------------------------------------------------------
name|FileSpecList
operator|&
name|GetCurrentValue
argument_list|()
block|{
return|return
name|m_current_value
return|;
block|}
specifier|const
name|FileSpecList
operator|&
name|GetCurrentValue
argument_list|()
specifier|const
block|{
return|return
name|m_current_value
return|;
block|}
name|void
name|SetCurrentValue
argument_list|(
argument|const FileSpecList&value
argument_list|)
block|{
name|m_current_value
operator|=
name|value
block|;     }
name|protected
operator|:
name|FileSpecList
name|m_current_value
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
comment|// liblldb_OptionValueFileSpecList_h_
end_comment

end_unit

