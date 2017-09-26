begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- ValueObjectDynamicValue.h -------------------------------*- C++ -*-===//
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

begin_include
include|#
directive|include
file|"lldb/Core/Address.h"
end_include

begin_comment
comment|// for Address
end_comment

begin_include
include|#
directive|include
file|"lldb/Core/ValueObject.h"
end_include

begin_include
include|#
directive|include
file|"lldb/Symbol/CompilerType.h"
end_include

begin_comment
comment|// for CompilerType
end_comment

begin_include
include|#
directive|include
file|"lldb/Symbol/Type.h"
end_include

begin_include
include|#
directive|include
file|"lldb/Utility/ConstString.h"
end_include

begin_comment
comment|// for ConstString
end_comment

begin_include
include|#
directive|include
file|"lldb/Utility/SharingPtr.h"
end_include

begin_comment
comment|// for operator==
end_comment

begin_include
include|#
directive|include
file|"lldb/lldb-defines.h"
end_include

begin_comment
comment|// for DISALLOW_COPY_AND_ASSIGN
end_comment

begin_include
include|#
directive|include
file|"lldb/lldb-enumerations.h"
end_include

begin_comment
comment|// for DynamicValueType, Langua...
end_comment

begin_include
include|#
directive|include
file|"lldb/lldb-forward.h"
end_include

begin_comment
comment|// for ValueObjectSP, VariableSP
end_comment

begin_include
include|#
directive|include
file|"lldb/lldb-private-enumerations.h"
end_include

begin_comment
comment|// for LazyBool, LazyBool::eLaz...
end_comment

begin_include
include|#
directive|include
file|<assert.h>
end_include

begin_comment
comment|// for assert
end_comment

begin_include
include|#
directive|include
file|<stddef.h>
end_include

begin_comment
comment|// for size_t
end_comment

begin_include
include|#
directive|include
file|<stdint.h>
end_include

begin_comment
comment|// for uint64_t, uint32_t
end_comment

begin_decl_stmt
name|namespace
name|lldb_private
block|{
name|class
name|DataExtractor
decl_stmt|;
block|}
end_decl_stmt

begin_decl_stmt
name|namespace
name|lldb_private
block|{
name|class
name|Declaration
decl_stmt|;
block|}
end_decl_stmt

begin_decl_stmt
name|namespace
name|lldb_private
block|{
name|class
name|Status
decl_stmt|;
block|}
end_decl_stmt

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
operator|~
name|ValueObjectDynamicValue
argument_list|()
name|override
block|;
name|uint64_t
name|GetByteSize
argument_list|()
name|override
block|;
name|ConstString
name|GetTypeName
argument_list|()
name|override
block|;
name|ConstString
name|GetQualifiedTypeName
argument_list|()
name|override
block|;
name|ConstString
name|GetDisplayTypeName
argument_list|()
name|override
block|;
name|size_t
name|CalculateNumChildren
argument_list|(
argument|uint32_t max
argument_list|)
name|override
block|;
name|lldb
operator|::
name|ValueType
name|GetValueType
argument_list|()
specifier|const
name|override
block|;
name|bool
name|IsInScope
argument_list|()
name|override
block|;
name|bool
name|IsDynamic
argument_list|()
name|override
block|{
return|return
name|true
return|;
block|}
name|bool
name|IsBaseClass
argument_list|()
name|override
block|{
if|if
condition|(
name|m_parent
condition|)
return|return
name|m_parent
operator|->
name|IsBaseClass
argument_list|()
return|;
return|return
name|false
return|;
block|}
name|bool
name|GetIsConstant
argument_list|()
specifier|const
name|override
block|{
return|return
name|false
return|;
block|}
name|ValueObject
modifier|*
name|GetParent
parameter_list|()
function|override
block|{
return|return
operator|(
operator|(
name|m_parent
operator|!=
name|nullptr
operator|)
condition|?
name|m_parent
operator|->
name|GetParent
argument_list|()
else|:
name|nullptr
operator|)
return|;
block|}
specifier|const
name|ValueObject
operator|*
name|GetParent
argument_list|()
specifier|const
name|override
block|{
return|return
operator|(
operator|(
name|m_parent
operator|!=
name|nullptr
operator|)
operator|?
name|m_parent
operator|->
name|GetParent
argument_list|()
operator|:
name|nullptr
operator|)
return|;
block|}
name|lldb
operator|::
name|ValueObjectSP
name|GetStaticValue
argument_list|()
name|override
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
name|lldb
operator|::
name|ValueObjectSP
operator|&
name|owning_sp
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
name|nullptr
argument_list|)
expr_stmt|;
name|m_owning_valobj_sp
operator|=
name|owning_sp
expr_stmt|;
block|}
name|bool
name|SetValueFromCString
argument_list|(
specifier|const
name|char
operator|*
name|value_str
argument_list|,
name|Status
operator|&
name|error
argument_list|)
name|override
decl_stmt|;
name|bool
name|SetData
argument_list|(
name|DataExtractor
operator|&
name|data
argument_list|,
name|Status
operator|&
name|error
argument_list|)
name|override
decl_stmt|;
name|TypeImpl
name|GetTypeImpl
argument_list|()
name|override
expr_stmt|;
name|lldb
operator|::
name|VariableSP
name|GetVariable
argument_list|()
name|override
block|{
return|return
name|m_parent
operator|?
name|m_parent
operator|->
name|GetVariable
argument_list|()
operator|:
name|nullptr
return|;
block|}
name|lldb
operator|::
name|LanguageType
name|GetPreferredDisplayLanguage
argument_list|()
name|override
expr_stmt|;
name|void
name|SetPreferredDisplayLanguage
argument_list|(
name|lldb
operator|::
name|LanguageType
argument_list|)
decl_stmt|;
name|bool
name|IsSyntheticChildrenGenerated
argument_list|()
name|override
expr_stmt|;
name|void
name|SetSyntheticChildrenGenerated
argument_list|(
name|bool
name|b
argument_list|)
name|override
decl_stmt|;
name|bool
name|GetDeclaration
argument_list|(
name|Declaration
operator|&
name|decl
argument_list|)
name|override
decl_stmt|;
name|uint64_t
name|GetLanguageFlags
argument_list|()
name|override
expr_stmt|;
name|void
name|SetLanguageFlags
argument_list|(
name|uint64_t
name|flags
argument_list|)
name|override
decl_stmt|;
name|protected
label|:
name|bool
name|UpdateValue
argument_list|()
name|override
expr_stmt|;
name|LazyBool
name|CanUpdateWithInvalidExecutionContext
parameter_list|()
function|override
block|{
return|return
name|eLazyBoolYes
return|;
block|}
name|lldb
operator|::
name|DynamicValueType
name|GetDynamicValueTypeImpl
argument_list|()
name|override
block|{
return|return
name|m_use_dynamic
return|;
block|}
name|bool
name|HasDynamicValueTypeInfo
parameter_list|()
function|override
block|{
return|return
name|true
return|;
block|}
name|CompilerType
name|GetCompilerTypeImpl
argument_list|()
name|override
expr_stmt|;
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

