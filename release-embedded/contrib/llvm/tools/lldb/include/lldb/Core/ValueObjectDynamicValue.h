begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- ValueObjectDynamicValue.h -----------------------------------*- C++ -*-===//
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
name|liblldb_ValueObjectDynamicValue_h_
end_ifndef

begin_define
define|#
directive|define
name|liblldb_ValueObjectDynamicValue_h_
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
file|"lldb/Core/ValueObject.h"
end_include

begin_include
include|#
directive|include
file|"lldb/Symbol/Type.h"
end_include

begin_decl_stmt
name|namespace
name|lldb_private
block|{
comment|//----------------------------------------------------------------------
comment|// A ValueObject that represents memory at a given address, viewed as some
comment|// set lldb type.
comment|//----------------------------------------------------------------------
name|class
name|ValueObjectDynamicValue
range|:
name|public
name|ValueObject
block|{
name|public
operator|:
name|virtual
operator|~
name|ValueObjectDynamicValue
argument_list|()
block|;
name|virtual
name|uint64_t
name|GetByteSize
argument_list|()
block|;
name|virtual
name|ConstString
name|GetTypeName
argument_list|()
block|;
name|virtual
name|ConstString
name|GetQualifiedTypeName
argument_list|()
block|;
name|virtual
name|size_t
name|CalculateNumChildren
argument_list|()
block|;
name|virtual
name|lldb
operator|::
name|ValueType
name|GetValueType
argument_list|()
specifier|const
block|;
name|virtual
name|bool
name|IsInScope
argument_list|()
block|;
name|virtual
name|bool
name|IsDynamic
argument_list|()
block|{
return|return
name|true
return|;
block|}
name|virtual
name|ValueObject
operator|*
name|GetParent
argument_list|()
block|{
if|if
condition|(
name|m_parent
condition|)
return|return
name|m_parent
operator|->
name|GetParent
argument_list|()
return|;
else|else
return|return
name|NULL
return|;
block|}
name|virtual
specifier|const
name|ValueObject
operator|*
name|GetParent
argument_list|()
specifier|const
block|{
if|if
condition|(
name|m_parent
condition|)
return|return
name|m_parent
operator|->
name|GetParent
argument_list|()
return|;
else|else
return|return
name|NULL
return|;
block|}
name|virtual
name|lldb
operator|::
name|ValueObjectSP
name|GetStaticValue
argument_list|()
block|{
return|return
name|m_parent
operator|->
name|GetSP
argument_list|()
return|;
block|}
name|void
name|SetOwningSP
argument_list|(
argument|lldb::ValueObjectSP&owning_sp
argument_list|)
block|{
if|if
condition|(
name|m_owning_valobj_sp
operator|==
name|owning_sp
condition|)
return|return;
name|assert
argument_list|(
name|m_owning_valobj_sp
operator|.
name|get
argument_list|()
operator|==
name|NULL
argument_list|)
block|;
name|m_owning_valobj_sp
operator|=
name|owning_sp
block|;     }
name|virtual
name|bool
name|SetValueFromCString
argument_list|(
specifier|const
name|char
operator|*
name|value_str
argument_list|,
name|Error
operator|&
name|error
argument_list|)
decl_stmt|;
name|virtual
name|bool
name|SetData
parameter_list|(
name|DataExtractor
modifier|&
name|data
parameter_list|,
name|Error
modifier|&
name|error
parameter_list|)
function_decl|;
name|virtual
name|TypeImpl
name|GetTypeImpl
parameter_list|()
function_decl|;
name|protected
label|:
name|virtual
name|bool
name|UpdateValue
parameter_list|()
function_decl|;
name|virtual
name|lldb
operator|::
name|DynamicValueType
name|GetDynamicValueTypeImpl
argument_list|()
block|{
return|return
name|m_use_dynamic
return|;
block|}
name|virtual
name|bool
name|HasDynamicValueTypeInfo
parameter_list|()
block|{
return|return
name|true
return|;
block|}
name|virtual
name|ClangASTType
name|GetClangTypeImpl
parameter_list|()
function_decl|;
name|Address
name|m_address
decl_stmt|;
comment|///< The variable that this value object is based upon
name|TypeAndOrName
name|m_dynamic_type_info
decl_stmt|;
comment|// We can have a type_sp or just a name
name|lldb
operator|::
name|ValueObjectSP
name|m_owning_valobj_sp
expr_stmt|;
name|lldb
operator|::
name|DynamicValueType
name|m_use_dynamic
expr_stmt|;
name|TypeImpl
name|m_type_impl
decl_stmt|;
name|private
label|:
name|friend
name|class
name|ValueObject
decl_stmt|;
name|friend
name|class
name|ValueObjectConstResult
decl_stmt|;
name|ValueObjectDynamicValue
argument_list|(
argument|ValueObject&parent
argument_list|,
argument|lldb::DynamicValueType use_dynamic
argument_list|)
empty_stmt|;
comment|//------------------------------------------------------------------
comment|// For ValueObject only
comment|//------------------------------------------------------------------
name|DISALLOW_COPY_AND_ASSIGN
argument_list|(
name|ValueObjectDynamicValue
argument_list|)
expr_stmt|;
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
comment|// liblldb_ValueObjectDynamicValue_h_
end_comment

end_unit

