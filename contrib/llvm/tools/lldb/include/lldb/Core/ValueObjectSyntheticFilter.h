begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- ValueObjectSyntheticFilter.h -------------------------------*- C++ -*-===//
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
file|"lldb/Core/ValueObject.h"
end_include

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
name|virtual
operator|~
name|ValueObjectSynthetic
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
name|ConstString
name|GetDisplayTypeName
argument_list|()
block|;
name|virtual
name|bool
name|MightHaveChildren
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
name|lldb
operator|::
name|ValueObjectSP
name|GetChildAtIndex
argument_list|(
argument|size_t idx
argument_list|,
argument|bool can_create
argument_list|)
block|;
name|virtual
name|lldb
operator|::
name|ValueObjectSP
name|GetChildMemberWithName
argument_list|(
argument|const ConstString&name
argument_list|,
argument|bool can_create
argument_list|)
block|;
name|virtual
name|size_t
name|GetIndexOfChildWithName
argument_list|(
specifier|const
name|ConstString
operator|&
name|name
argument_list|)
block|;
name|virtual
name|lldb
operator|::
name|ValueObjectSP
name|GetDynamicValue
argument_list|(
argument|lldb::DynamicValueType valueType
argument_list|)
block|;
name|virtual
name|bool
name|IsInScope
argument_list|()
block|;
name|virtual
name|bool
name|HasSyntheticValue
argument_list|()
block|{
return|return
name|false
return|;
block|}
name|virtual
name|bool
name|IsSynthetic
argument_list|()
block|{
return|return
name|true
return|;
block|}
name|virtual
name|void
name|CalculateSyntheticValue
argument_list|(
argument|bool use_synthetic
argument_list|)
block|{     }
name|virtual
name|bool
name|IsDynamic
argument_list|()
block|{
if|if
condition|(
name|m_parent
condition|)
return|return
name|m_parent
operator|->
name|IsDynamic
argument_list|()
return|;
else|else
return|return
name|false
return|;
block|}
name|virtual
name|lldb
operator|::
name|ValueObjectSP
name|GetStaticValue
argument_list|()
block|{
if|if
condition|(
name|m_parent
condition|)
return|return
name|m_parent
operator|->
name|GetStaticValue
argument_list|()
return|;
else|else
return|return
name|GetSP
argument_list|()
return|;
block|}
name|virtual
name|lldb
operator|::
name|DynamicValueType
name|GetDynamicValueType
argument_list|()
block|{
if|if
condition|(
name|m_parent
condition|)
return|return
name|m_parent
operator|->
name|GetDynamicValueType
argument_list|()
return|;
else|else
return|return
name|lldb
operator|::
name|eNoDynamicValues
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
name|GetNonSyntheticValue
argument_list|()
block|;
name|virtual
name|bool
name|ResolveValue
argument_list|(
argument|Scalar&scalar
argument_list|)
block|{
if|if
condition|(
name|m_parent
condition|)
return|return
name|m_parent
operator|->
name|ResolveValue
argument_list|(
name|scalar
argument_list|)
return|;
return|return
name|false
return|;
block|}
name|protected
label|:
name|virtual
name|bool
name|UpdateValue
parameter_list|()
function_decl|;
name|virtual
name|ClangASTType
name|GetClangTypeImpl
parameter_list|()
function_decl|;
name|virtual
name|void
name|CreateSynthFilter
parameter_list|()
function_decl|;
comment|// we need to hold on to the SyntheticChildren because someone might delete the type binding while we are alive
name|lldb
operator|::
name|SyntheticChildrenSP
name|m_synth_sp
expr_stmt|;
name|std
operator|::
name|unique_ptr
operator|<
name|SyntheticChildrenFrontEnd
operator|>
name|m_synth_filter_ap
expr_stmt|;
typedef|typedef
name|std
operator|::
name|map
operator|<
name|uint32_t
operator|,
name|ValueObject
operator|*
operator|>
name|ByIndexMap
expr_stmt|;
typedef|typedef
name|std
operator|::
name|map
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
comment|// FIXME use the ValueObject's ChildrenManager instead of a special purpose solution
name|ConstString
name|m_parent_type_name
decl_stmt|;
name|LazyBool
name|m_might_have_children
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
name|CopyParentData
parameter_list|()
function_decl|;
comment|//------------------------------------------------------------------
comment|// For ValueObject only
comment|//------------------------------------------------------------------
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

