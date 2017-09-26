begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- OptionValueUInt64.h --------------------------------------*- C++
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
name|liblldb_OptionValueUInt64_h_
end_ifndef

begin_define
define|#
directive|define
name|liblldb_OptionValueUInt64_h_
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
name|OptionValueUInt64
range|:
name|public
name|OptionValue
block|{
name|public
operator|:
name|OptionValueUInt64
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
block|{}
name|OptionValueUInt64
argument_list|(
argument|uint64_t value
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
name|OptionValueUInt64
argument_list|(
argument|uint64_t current_value
argument_list|,
argument|uint64_t default_value
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
name|OptionValueUInt64
argument_list|()
name|override
block|{}
comment|//---------------------------------------------------------------------
comment|// Decode a uint64_t from "value_cstr" return a OptionValueUInt64 object
comment|// inside of a lldb::OptionValueSP object if all goes well. If the
comment|// string isn't a uint64_t value or any other error occurs, return an
comment|// empty lldb::OptionValueSP and fill error in with the correct stuff.
comment|//---------------------------------------------------------------------
specifier|static
name|lldb
operator|::
name|OptionValueSP
name|Create
argument_list|(
specifier|const
name|char
operator|*
argument_list|,
name|Status
operator|&
argument_list|)
operator|=
name|delete
block|;
specifier|static
name|lldb
operator|::
name|OptionValueSP
name|Create
argument_list|(
argument|llvm::StringRef value_str
argument_list|,
argument|Status&error
argument_list|)
block|;
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
name|eTypeUInt64
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
name|uint64_t
operator|&
name|operator
operator|=
operator|(
name|uint64_t
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
name|operator
name|uint64_t
argument_list|()
specifier|const
block|{
return|return
name|m_current_value
return|;
block|}
name|uint64_t
name|GetCurrentValue
argument_list|()
specifier|const
block|{
return|return
name|m_current_value
return|;
block|}
name|uint64_t
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
argument|uint64_t value
argument_list|)
block|{
name|m_current_value
operator|=
name|value
block|; }
name|void
name|SetDefaultValue
argument_list|(
argument|uint64_t value
argument_list|)
block|{
name|m_default_value
operator|=
name|value
block|; }
name|protected
operator|:
name|uint64_t
name|m_current_value
block|;
name|uint64_t
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
comment|// liblldb_OptionValueUInt64_h_
end_comment

end_unit

