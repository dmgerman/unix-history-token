begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- OptionValueRegex.h --------------------------------------*- C++ -*-===//
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
name|liblldb_OptionValueRegex_h_
end_ifndef

begin_define
define|#
directive|define
name|liblldb_OptionValueRegex_h_
end_define

begin_comment
comment|// C Includes
end_comment

begin_comment
comment|// C++ Includes
end_comment

begin_include
include|#
directive|include
file|<string>
end_include

begin_comment
comment|// Other libraries and framework includes
end_comment

begin_comment
comment|// Project includes
end_comment

begin_include
include|#
directive|include
file|"lldb/Core/RegularExpression.h"
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
name|OptionValueRegex
range|:
name|public
name|OptionValue
block|{
name|public
operator|:
name|OptionValueRegex
argument_list|(
specifier|const
name|char
operator|*
name|value
operator|=
name|NULL
argument_list|)
operator|:
name|OptionValue
argument_list|()
block|,
name|m_regex
argument_list|(
argument|value
argument_list|)
block|{     }
name|virtual
operator|~
name|OptionValueRegex
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
name|eTypeRegex
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
name|m_regex
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
comment|//---------------------------------------------------------------------
comment|// Subclass specific functions
comment|//---------------------------------------------------------------------
specifier|const
name|RegularExpression
operator|*
name|GetCurrentValue
argument_list|()
specifier|const
block|{
if|if
condition|(
name|m_regex
operator|.
name|IsValid
argument_list|()
condition|)
return|return
operator|&
name|m_regex
return|;
return|return
name|NULL
return|;
block|}
name|void
name|SetCurrentValue
parameter_list|(
specifier|const
name|char
modifier|*
name|value
parameter_list|)
block|{
if|if
condition|(
name|value
operator|&&
name|value
index|[
literal|0
index|]
condition|)
name|m_regex
operator|.
name|Compile
argument_list|(
name|value
argument_list|)
expr_stmt|;
else|else
name|m_regex
operator|.
name|Clear
argument_list|()
expr_stmt|;
block|}
name|bool
name|IsValid
argument_list|()
specifier|const
block|{
return|return
name|m_regex
operator|.
name|IsValid
argument_list|()
return|;
block|}
name|protected
label|:
name|RegularExpression
name|m_regex
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
comment|// liblldb_OptionValueRegex_h_
end_comment

end_unit

