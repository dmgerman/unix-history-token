begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- OptionValueSInt64.h --------------------------------------*- C++
end_comment

begin_comment
comment|//-*-===//
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
name|liblldb_OptionValueSInt64_h_
end_ifndef

begin_define
define|#
directive|define
name|liblldb_OptionValueSInt64_h_
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
name|OptionValueSInt64
range|:
name|public
name|OptionValue
block|{
name|public
operator|:
name|OptionValueSInt64
argument_list|()
operator|:
name|OptionValue
argument_list|()
block|,
name|m_current_value
argument_list|(
literal|0
argument_list|)
block|,
name|m_default_value
argument_list|(
literal|0
argument_list|)
block|,
name|m_min_value
argument_list|(
name|INT64_MIN
argument_list|)
block|,
name|m_max_value
argument_list|(
argument|INT64_MAX
argument_list|)
block|{}
name|OptionValueSInt64
argument_list|(
argument|int64_t value
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
name|value
argument_list|)
block|,
name|m_min_value
argument_list|(
name|INT64_MIN
argument_list|)
block|,
name|m_max_value
argument_list|(
argument|INT64_MAX
argument_list|)
block|{}
name|OptionValueSInt64
argument_list|(
argument|int64_t current_value
argument_list|,
argument|int64_t default_value
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
name|default_value
argument_list|)
block|,
name|m_min_value
argument_list|(
name|INT64_MIN
argument_list|)
block|,
name|m_max_value
argument_list|(
argument|INT64_MAX
argument_list|)
block|{}
name|OptionValueSInt64
argument_list|(
specifier|const
name|OptionValueSInt64
operator|&
name|rhs
argument_list|)
operator|:
name|OptionValue
argument_list|(
name|rhs
argument_list|)
block|,
name|m_current_value
argument_list|(
name|rhs
operator|.
name|m_current_value
argument_list|)
block|,
name|m_default_value
argument_list|(
name|rhs
operator|.
name|m_default_value
argument_list|)
block|,
name|m_min_value
argument_list|(
name|rhs
operator|.
name|m_min_value
argument_list|)
block|,
name|m_max_value
argument_list|(
argument|rhs.m_max_value
argument_list|)
block|{}
operator|~
name|OptionValueSInt64
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
name|eTypeSInt64
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
name|lldb
operator|::
name|OptionValueSP
name|DeepCopy
argument_list|()
specifier|const
name|override
block|;
comment|//---------------------------------------------------------------------
comment|// Subclass specific functions
comment|//---------------------------------------------------------------------
specifier|const
name|int64_t
operator|&
name|operator
operator|=
operator|(
name|int64_t
name|value
operator|)
block|{
name|m_current_value
operator|=
name|value
block|;
return|return
name|m_current_value
return|;
block|}
name|int64_t
name|GetCurrentValue
argument_list|()
specifier|const
block|{
return|return
name|m_current_value
return|;
block|}
name|int64_t
name|GetDefaultValue
argument_list|()
specifier|const
block|{
return|return
name|m_default_value
return|;
block|}
name|bool
name|SetCurrentValue
argument_list|(
argument|int64_t value
argument_list|)
block|{
if|if
condition|(
name|value
operator|>=
name|m_min_value
operator|&&
name|value
operator|<=
name|m_max_value
condition|)
block|{
name|m_current_value
operator|=
name|value
expr_stmt|;
return|return
name|true
return|;
block|}
return|return
name|false
return|;
block|}
name|bool
name|SetDefaultValue
argument_list|(
argument|int64_t value
argument_list|)
block|{
if|if
condition|(
name|value
operator|>=
name|m_min_value
operator|&&
name|value
operator|<=
name|m_max_value
condition|)
block|{
name|m_default_value
operator|=
name|value
expr_stmt|;
return|return
name|true
return|;
block|}
return|return
name|false
return|;
block|}
name|void
name|SetMinimumValue
argument_list|(
argument|int64_t v
argument_list|)
block|{
name|m_min_value
operator|=
name|v
block|; }
name|int64_t
name|GetMinimumValue
argument_list|()
specifier|const
block|{
return|return
name|m_min_value
return|;
block|}
name|void
name|SetMaximumValue
argument_list|(
argument|int64_t v
argument_list|)
block|{
name|m_max_value
operator|=
name|v
block|; }
name|int64_t
name|GetMaximumValue
argument_list|()
specifier|const
block|{
return|return
name|m_max_value
return|;
block|}
name|protected
operator|:
name|int64_t
name|m_current_value
block|;
name|int64_t
name|m_default_value
block|;
name|int64_t
name|m_min_value
block|;
name|int64_t
name|m_max_value
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
comment|// liblldb_OptionValueSInt64_h_
end_comment

end_unit

