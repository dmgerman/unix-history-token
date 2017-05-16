begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- OptionValueArray.h --------------------------------------*- C++ -*-===//
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
name|liblldb_OptionValueArray_h_
end_ifndef

begin_define
define|#
directive|define
name|liblldb_OptionValueArray_h_
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
file|<vector>
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
name|OptionValueArray
range|:
name|public
name|OptionValue
block|{
name|public
operator|:
name|OptionValueArray
argument_list|(
argument|uint32_t type_mask = UINT32_MAX
argument_list|,
argument|bool raw_value_dump = false
argument_list|)
operator|:
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
name|OptionValueArray
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
name|eTypeArray
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
comment|//---------------------------------------------------------------------
comment|// Subclass specific functions
comment|//---------------------------------------------------------------------
name|size_t
name|GetSize
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
name|operator
index|[]
operator|(
name|size_t
name|idx
operator|)
specifier|const
block|{
name|lldb
operator|::
name|OptionValueSP
name|value_sp
block|;
if|if
condition|(
name|idx
operator|<
name|m_values
operator|.
name|size
argument_list|()
condition|)
name|value_sp
operator|=
name|m_values
index|[
name|idx
index|]
expr_stmt|;
return|return
name|value_sp
return|;
block|}
name|lldb
operator|::
name|OptionValueSP
name|GetValueAtIndex
argument_list|(
argument|size_t idx
argument_list|)
specifier|const
block|{
name|lldb
operator|::
name|OptionValueSP
name|value_sp
block|;
if|if
condition|(
name|idx
operator|<
name|m_values
operator|.
name|size
argument_list|()
condition|)
name|value_sp
operator|=
name|m_values
index|[
name|idx
index|]
expr_stmt|;
return|return
name|value_sp
return|;
block|}
end_decl_stmt

begin_decl_stmt
name|bool
name|AppendValue
argument_list|(
specifier|const
name|lldb
operator|::
name|OptionValueSP
operator|&
name|value_sp
argument_list|)
block|{
comment|// Make sure the value_sp object is allowed to contain
comment|// values of the type passed in...
if|if
condition|(
name|value_sp
operator|&&
operator|(
name|m_type_mask
operator|&
name|value_sp
operator|->
name|GetTypeAsMask
argument_list|()
operator|)
condition|)
block|{
name|m_values
operator|.
name|push_back
argument_list|(
name|value_sp
argument_list|)
expr_stmt|;
return|return
name|true
return|;
block|}
return|return
name|false
return|;
block|}
end_decl_stmt

begin_decl_stmt
name|bool
name|InsertValue
argument_list|(
name|size_t
name|idx
argument_list|,
specifier|const
name|lldb
operator|::
name|OptionValueSP
operator|&
name|value_sp
argument_list|)
block|{
comment|// Make sure the value_sp object is allowed to contain
comment|// values of the type passed in...
if|if
condition|(
name|value_sp
operator|&&
operator|(
name|m_type_mask
operator|&
name|value_sp
operator|->
name|GetTypeAsMask
argument_list|()
operator|)
condition|)
block|{
if|if
condition|(
name|idx
operator|<
name|m_values
operator|.
name|size
argument_list|()
condition|)
name|m_values
operator|.
name|insert
argument_list|(
name|m_values
operator|.
name|begin
argument_list|()
operator|+
name|idx
argument_list|,
name|value_sp
argument_list|)
expr_stmt|;
else|else
name|m_values
operator|.
name|push_back
argument_list|(
name|value_sp
argument_list|)
expr_stmt|;
return|return
name|true
return|;
block|}
return|return
name|false
return|;
block|}
end_decl_stmt

begin_decl_stmt
name|bool
name|ReplaceValue
argument_list|(
name|size_t
name|idx
argument_list|,
specifier|const
name|lldb
operator|::
name|OptionValueSP
operator|&
name|value_sp
argument_list|)
block|{
comment|// Make sure the value_sp object is allowed to contain
comment|// values of the type passed in...
if|if
condition|(
name|value_sp
operator|&&
operator|(
name|m_type_mask
operator|&
name|value_sp
operator|->
name|GetTypeAsMask
argument_list|()
operator|)
condition|)
block|{
if|if
condition|(
name|idx
operator|<
name|m_values
operator|.
name|size
argument_list|()
condition|)
block|{
name|m_values
index|[
name|idx
index|]
operator|=
name|value_sp
expr_stmt|;
return|return
name|true
return|;
block|}
block|}
return|return
name|false
return|;
block|}
end_decl_stmt

begin_function
name|bool
name|DeleteValue
parameter_list|(
name|size_t
name|idx
parameter_list|)
block|{
if|if
condition|(
name|idx
operator|<
name|m_values
operator|.
name|size
argument_list|()
condition|)
block|{
name|m_values
operator|.
name|erase
argument_list|(
name|m_values
operator|.
name|begin
argument_list|()
operator|+
name|idx
argument_list|)
expr_stmt|;
return|return
name|true
return|;
block|}
return|return
name|false
return|;
block|}
end_function

begin_decl_stmt
name|size_t
name|GetArgs
argument_list|(
name|Args
operator|&
name|args
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_function_decl
name|Status
name|SetArgs
parameter_list|(
specifier|const
name|Args
modifier|&
name|args
parameter_list|,
name|VarSetOperationType
name|op
parameter_list|)
function_decl|;
end_function_decl

begin_label
name|protected
label|:
end_label

begin_typedef
typedef|typedef
name|std
operator|::
name|vector
operator|<
name|lldb
operator|::
name|OptionValueSP
operator|>
name|collection
expr_stmt|;
end_typedef

begin_decl_stmt
name|uint32_t
name|m_type_mask
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|collection
name|m_values
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|bool
name|m_raw_value_dump
decl_stmt|;
end_decl_stmt

begin_comment
unit|};  }
comment|// namespace lldb_private
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// liblldb_OptionValueArray_h_
end_comment

end_unit

