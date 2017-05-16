begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- ValueObjectSyntheticFilter.h ----------------------------*- C++ -*-===//
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
name|liblldb_ValueObjectSyntheticFilter_h_
end_ifndef

begin_define
define|#
directive|define
name|liblldb_ValueObjectSyntheticFilter_h_
end_define

begin_include
include|#
directive|include
file|"lldb/Core/ThreadSafeSTLMap.h"
end_include

begin_include
include|#
directive|include
file|"lldb/Core/ThreadSafeSTLVector.h"
end_include

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
file|"lldb/Utility/ConstString.h"
end_include

begin_comment
comment|// for ConstString
end_comment

begin_include
include|#
directive|include
file|"lldb/lldb-defines.h"
end_include

begin_comment
comment|// for ThreadSafeSTLMap::operator=
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
comment|// for ValueObjectSP, Synthetic...
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
file|<cstdint>
end_include

begin_comment
comment|// for uint32_t, uint64_t
end_comment

begin_include
include|#
directive|include
file|<memory>
end_include

begin_include
include|#
directive|include
file|<stddef.h>
end_include

begin_comment
comment|// for size_t
end_comment

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
name|class
name|SyntheticChildrenFrontEnd
decl_stmt|;
block|}
end_decl_stmt

begin_decl_stmt
name|namespace
name|lldb_private
block|{
comment|//----------------------------------------------------------------------
comment|// A ValueObject that obtains its children from some source other than
comment|// real information
comment|// This is currently used to implement Python-based children and filters
comment|// but you can bind it to any source of synthetic information and have
comment|// it behave accordingly
comment|//----------------------------------------------------------------------
name|class
name|ValueObjectSynthetic
range|:
name|public
name|ValueObject
block|{
name|public
operator|:
operator|~
name|ValueObjectSynthetic
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
name|bool
name|MightHaveChildren
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
name|lldb
operator|::
name|ValueObjectSP
name|GetChildAtIndex
argument_list|(
argument|size_t idx
argument_list|,
argument|bool can_create
argument_list|)
name|override
block|;
name|lldb
operator|::
name|ValueObjectSP
name|GetChildMemberWithName
argument_list|(
argument|const ConstString&name
argument_list|,
argument|bool can_create
argument_list|)
name|override
block|;
name|size_t
name|GetIndexOfChildWithName
argument_list|(
argument|const ConstString&name
argument_list|)
name|override
block|;
name|lldb
operator|::
name|ValueObjectSP
name|GetDynamicValue
argument_list|(
argument|lldb::DynamicValueType valueType
argument_list|)
name|override
block|;
name|bool
name|IsInScope
argument_list|()
name|override
block|;
name|bool
name|HasSyntheticValue
argument_list|()
name|override
block|{
return|return
name|false
return|;
block|}
name|bool
name|IsSynthetic
argument_list|()
name|override
block|{
return|return
name|true
return|;
block|}
name|void
name|CalculateSyntheticValue
argument_list|(
argument|bool use_synthetic
argument_list|)
name|override
block|{}
name|bool
name|IsDynamic
argument_list|()
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
name|IsDynamic
argument_list|()
operator|:
name|false
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
operator|(
operator|(
name|m_parent
operator|!=
name|nullptr
operator|)
condition|?
name|m_parent
operator|->
name|GetStaticValue
argument_list|()
else|:
name|GetSP
argument_list|()
operator|)
return|;
block|}
name|virtual
name|lldb
operator|::
name|DynamicValueType
name|GetDynamicValueType
argument_list|()
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
name|GetDynamicValueType
argument_list|()
else|:
name|lldb
operator|::
name|eNoDynamicValues
operator|)
return|;
block|}
name|ValueObject
operator|*
name|GetParent
argument_list|()
name|override
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
name|lldb
operator|::
name|ValueObjectSP
name|GetNonSyntheticValue
argument_list|()
name|override
block|;
name|bool
name|CanProvideValue
argument_list|()
name|override
block|;
name|bool
name|DoesProvideSyntheticValue
argument_list|()
name|override
block|{
return|return
operator|(
name|UpdateValueIfNeeded
argument_list|()
expr|,
name|m_provides_value
operator|==
name|eLazyBoolYes
operator|)
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
name|bool
name|SetValueFromCString
argument_list|(
argument|const char *value_str
argument_list|,
argument|Status&error
argument_list|)
name|override
block|;
name|void
name|SetFormat
argument_list|(
argument|lldb::Format format
argument_list|)
name|override
block|;
name|lldb
operator|::
name|LanguageType
name|GetPreferredDisplayLanguage
argument_list|()
name|override
block|;
name|void
name|SetPreferredDisplayLanguage
argument_list|(
name|lldb
operator|::
name|LanguageType
argument_list|)
block|;
name|bool
name|IsSyntheticChildrenGenerated
argument_list|()
name|override
block|;
name|void
name|SetSyntheticChildrenGenerated
argument_list|(
argument|bool b
argument_list|)
name|override
block|;
name|bool
name|GetDeclaration
argument_list|(
argument|Declaration&decl
argument_list|)
name|override
block|;
name|uint64_t
name|GetLanguageFlags
argument_list|()
name|override
block|;
name|void
name|SetLanguageFlags
argument_list|(
argument|uint64_t flags
argument_list|)
name|override
block|;
name|protected
operator|:
name|bool
name|UpdateValue
argument_list|()
name|override
block|;
name|LazyBool
name|CanUpdateWithInvalidExecutionContext
argument_list|()
name|override
block|{
return|return
name|eLazyBoolYes
return|;
block|}
name|CompilerType
name|GetCompilerTypeImpl
argument_list|()
name|override
block|;
name|virtual
name|void
name|CreateSynthFilter
argument_list|()
block|;
comment|// we need to hold on to the SyntheticChildren because someone might delete
comment|// the type binding while we are alive
name|lldb
operator|::
name|SyntheticChildrenSP
name|m_synth_sp
block|;
name|std
operator|::
name|unique_ptr
operator|<
name|SyntheticChildrenFrontEnd
operator|>
name|m_synth_filter_ap
block|;
typedef|typedef
name|ThreadSafeSTLMap
operator|<
name|uint32_t
operator|,
name|ValueObject
operator|*
operator|>
name|ByIndexMap
expr_stmt|;
typedef|typedef
name|ThreadSafeSTLMap
operator|<
specifier|const
name|char
operator|*
operator|,
name|uint32_t
operator|>
name|NameToIndexMap
expr_stmt|;
typedef|typedef
name|ThreadSafeSTLVector
operator|<
name|lldb
operator|::
name|ValueObjectSP
operator|>
name|SyntheticChildrenCache
expr_stmt|;
typedef|typedef
name|ByIndexMap
operator|::
name|iterator
name|ByIndexIterator
expr_stmt|;
typedef|typedef
name|NameToIndexMap
operator|::
name|iterator
name|NameToIndexIterator
expr_stmt|;
name|ByIndexMap
name|m_children_byindex
decl_stmt|;
name|NameToIndexMap
name|m_name_toindex
decl_stmt|;
name|uint32_t
name|m_synthetic_children_count
decl_stmt|;
comment|// FIXME use the ValueObject's
comment|// ChildrenManager instead of a special
comment|// purpose solution
name|SyntheticChildrenCache
name|m_synthetic_children_cache
decl_stmt|;
name|ConstString
name|m_parent_type_name
decl_stmt|;
name|LazyBool
name|m_might_have_children
decl_stmt|;
name|LazyBool
name|m_provides_value
decl_stmt|;
name|private
label|:
name|friend
name|class
name|ValueObject
decl_stmt|;
name|ValueObjectSynthetic
argument_list|(
argument|ValueObject&parent
argument_list|,
argument|lldb::SyntheticChildrenSP filter
argument_list|)
empty_stmt|;
name|void
name|CopyValueData
parameter_list|(
name|ValueObject
modifier|*
name|source
parameter_list|)
function_decl|;
name|DISALLOW_COPY_AND_ASSIGN
argument_list|(
name|ValueObjectSynthetic
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
comment|// liblldb_ValueObjectSyntheticFilter_h_
end_comment

end_unit

