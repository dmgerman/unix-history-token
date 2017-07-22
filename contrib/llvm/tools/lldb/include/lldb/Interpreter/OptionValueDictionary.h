begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- OptionValueDictionary.h ---------------------------------*- C++ -*-===//
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
name|liblldb_OptionValueDictionary_h_
end_ifndef

begin_define
define|#
directive|define
name|liblldb_OptionValueDictionary_h_
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
file|<map>
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
file|"lldb/Interpreter/OptionValue.h"
end_include

begin_decl_stmt
name|namespace
name|lldb_private
block|{
name|class
name|OptionValueDictionary
range|:
name|public
name|OptionValue
block|{
name|public
operator|:
name|OptionValueDictionary
argument_list|(
argument|uint32_t type_mask = UINT32_MAX
argument_list|,
argument|bool raw_value_dump = true
argument_list|)
operator|:
name|OptionValue
argument_list|()
block|,
name|m_type_mask
argument_list|(
name|type_mask
argument_list|)
block|,
name|m_values
argument_list|()
block|,
name|m_raw_value_dump
argument_list|(
argument|raw_value_dump
argument_list|)
block|{}
operator|~
name|OptionValueDictionary
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
name|eTypeDictionary
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
name|bool
name|Clear
argument_list|()
name|override
block|{
name|m_values
operator|.
name|clear
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
name|lldb
operator|::
name|OptionValueSP
name|DeepCopy
argument_list|()
specifier|const
name|override
block|;
name|bool
name|IsAggregateValue
argument_list|()
specifier|const
name|override
block|{
return|return
name|true
return|;
block|}
name|bool
name|IsHomogenous
argument_list|()
specifier|const
block|{
return|return
name|ConvertTypeMaskToType
argument_list|(
name|m_type_mask
argument_list|)
operator|!=
name|eTypeInvalid
return|;
block|}
comment|//---------------------------------------------------------------------
comment|// Subclass specific functions
comment|//---------------------------------------------------------------------
name|size_t
name|GetNumValues
argument_list|()
specifier|const
block|{
return|return
name|m_values
operator|.
name|size
argument_list|()
return|;
block|}
name|lldb
operator|::
name|OptionValueSP
name|GetValueForKey
argument_list|(
argument|const ConstString&key
argument_list|)
specifier|const
block|;
name|lldb
operator|::
name|OptionValueSP
name|GetSubValue
argument_list|(
argument|const ExecutionContext *exe_ctx
argument_list|,
argument|llvm::StringRef name
argument_list|,
argument|bool will_modify
argument_list|,
argument|Status&error
argument_list|)
specifier|const
name|override
block|;
name|Status
name|SetSubValue
argument_list|(
argument|const ExecutionContext *exe_ctx
argument_list|,
argument|VarSetOperationType op
argument_list|,
argument|llvm::StringRef name
argument_list|,
argument|llvm::StringRef value
argument_list|)
name|override
block|;
name|bool
name|SetValueForKey
argument_list|(
argument|const ConstString&key
argument_list|,
argument|const lldb::OptionValueSP&value_sp
argument_list|,
argument|bool can_replace = true
argument_list|)
block|;
name|bool
name|DeleteValueForKey
argument_list|(
specifier|const
name|ConstString
operator|&
name|key
argument_list|)
block|;
name|size_t
name|GetArgs
argument_list|(
argument|Args&args
argument_list|)
specifier|const
block|;
name|Status
name|SetArgs
argument_list|(
argument|const Args&args
argument_list|,
argument|VarSetOperationType op
argument_list|)
block|;
name|protected
operator|:
typedef|typedef
name|std
operator|::
name|map
operator|<
name|ConstString
operator|,
name|lldb
operator|::
name|OptionValueSP
operator|>
name|collection
expr_stmt|;
name|uint32_t
name|m_type_mask
decl_stmt|;
name|collection
name|m_values
decl_stmt|;
name|bool
name|m_raw_value_dump
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
comment|// liblldb_OptionValueDictionary_h_
end_comment

end_unit

