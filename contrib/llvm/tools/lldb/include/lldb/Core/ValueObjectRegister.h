begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- ValueObjectRegister.h -----------------------------------*- C++ -*-===//
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
name|liblldb_ValueObjectRegister_h_
end_ifndef

begin_define
define|#
directive|define
name|liblldb_ValueObjectRegister_h_
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
file|"lldb/lldb-private.h"
end_include

begin_include
include|#
directive|include
file|"lldb/Core/RegisterValue.h"
end_include

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
comment|// A ValueObject that contains a root variable that may or may not
comment|// have children.
comment|//----------------------------------------------------------------------
name|class
name|ValueObjectRegisterContext
range|:
name|public
name|ValueObject
block|{
name|public
operator|:
name|virtual
operator|~
name|ValueObjectRegisterContext
argument_list|()
block|;
name|virtual
name|uint64_t
name|GetByteSize
argument_list|()
block|;
name|virtual
name|lldb
operator|::
name|ValueType
name|GetValueType
argument_list|()
specifier|const
block|{
return|return
name|lldb
operator|::
name|eValueTypeRegisterSet
return|;
block|}
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
name|size_t
name|CalculateNumChildren
argument_list|()
block|;
name|virtual
name|ValueObject
operator|*
name|CreateChildAtIndex
argument_list|(
argument|size_t idx
argument_list|,
argument|bool synthetic_array_member
argument_list|,
argument|int32_t synthetic_index
argument_list|)
block|;
name|protected
operator|:
name|virtual
name|bool
name|UpdateValue
argument_list|()
block|;
name|virtual
name|ClangASTType
name|GetClangTypeImpl
argument_list|()
block|;
name|lldb
operator|::
name|RegisterContextSP
name|m_reg_ctx_sp
block|;
name|private
operator|:
name|ValueObjectRegisterContext
argument_list|(
name|ValueObject
operator|&
name|parent
argument_list|,
name|lldb
operator|::
name|RegisterContextSP
operator|&
name|reg_ctx_sp
argument_list|)
block|;
comment|//------------------------------------------------------------------
comment|// For ValueObject only
comment|//------------------------------------------------------------------
name|DISALLOW_COPY_AND_ASSIGN
argument_list|(
name|ValueObjectRegisterContext
argument_list|)
block|; }
decl_stmt|;
name|class
name|ValueObjectRegisterSet
range|:
name|public
name|ValueObject
block|{
name|public
operator|:
specifier|static
name|lldb
operator|::
name|ValueObjectSP
name|Create
argument_list|(
argument|ExecutionContextScope *exe_scope
argument_list|,
argument|lldb::RegisterContextSP&reg_ctx_sp
argument_list|,
argument|uint32_t set_idx
argument_list|)
block|;
name|virtual
operator|~
name|ValueObjectRegisterSet
argument_list|()
block|;
name|virtual
name|uint64_t
name|GetByteSize
argument_list|()
block|;
name|virtual
name|lldb
operator|::
name|ValueType
name|GetValueType
argument_list|()
specifier|const
block|{
return|return
name|lldb
operator|::
name|eValueTypeRegisterSet
return|;
block|}
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
name|ValueObject
operator|*
name|CreateChildAtIndex
argument_list|(
argument|size_t idx
argument_list|,
argument|bool synthetic_array_member
argument_list|,
argument|int32_t synthetic_index
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
name|protected
operator|:
name|virtual
name|bool
name|UpdateValue
argument_list|()
block|;
name|virtual
name|ClangASTType
name|GetClangTypeImpl
argument_list|()
block|;
name|lldb
operator|::
name|RegisterContextSP
name|m_reg_ctx_sp
block|;
specifier|const
name|RegisterSet
operator|*
name|m_reg_set
block|;
name|uint32_t
name|m_reg_set_idx
block|;
name|private
operator|:
name|friend
name|class
name|ValueObjectRegisterContext
block|;
name|ValueObjectRegisterSet
argument_list|(
argument|ExecutionContextScope *exe_scope
argument_list|,
argument|lldb::RegisterContextSP&reg_ctx_sp
argument_list|,
argument|uint32_t set_idx
argument_list|)
block|;
comment|//------------------------------------------------------------------
comment|// For ValueObject only
comment|//------------------------------------------------------------------
name|DISALLOW_COPY_AND_ASSIGN
argument_list|(
name|ValueObjectRegisterSet
argument_list|)
block|; }
decl_stmt|;
name|class
name|ValueObjectRegister
range|:
name|public
name|ValueObject
block|{
name|public
operator|:
specifier|static
name|lldb
operator|::
name|ValueObjectSP
name|Create
argument_list|(
argument|ExecutionContextScope *exe_scope
argument_list|,
argument|lldb::RegisterContextSP&reg_ctx_sp
argument_list|,
argument|uint32_t reg_num
argument_list|)
block|;
name|virtual
operator|~
name|ValueObjectRegister
argument_list|()
block|;
name|virtual
name|uint64_t
name|GetByteSize
argument_list|()
block|;
name|virtual
name|lldb
operator|::
name|ValueType
name|GetValueType
argument_list|()
specifier|const
block|{
return|return
name|lldb
operator|::
name|eValueTypeRegister
return|;
block|}
name|virtual
name|ConstString
name|GetTypeName
argument_list|()
block|;
name|virtual
name|size_t
name|CalculateNumChildren
argument_list|()
block|;
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
block|;
name|virtual
name|bool
name|SetData
argument_list|(
name|DataExtractor
operator|&
name|data
argument_list|,
name|Error
operator|&
name|error
argument_list|)
block|;
name|virtual
name|bool
name|ResolveValue
argument_list|(
name|Scalar
operator|&
name|scalar
argument_list|)
block|;
name|virtual
name|void
name|GetExpressionPath
argument_list|(
argument|Stream&s
argument_list|,
argument|bool qualify_cxx_base_classes
argument_list|,
argument|GetExpressionPathFormat epformat = eGetExpressionPathFormatDereferencePointers
argument_list|)
block|;
name|protected
operator|:
name|virtual
name|bool
name|UpdateValue
argument_list|()
block|;
name|virtual
name|ClangASTType
name|GetClangTypeImpl
argument_list|()
block|;
name|lldb
operator|::
name|RegisterContextSP
name|m_reg_ctx_sp
block|;
name|RegisterInfo
name|m_reg_info
block|;
name|RegisterValue
name|m_reg_value
block|;
name|ConstString
name|m_type_name
block|;
name|ClangASTType
name|m_clang_type
block|;
name|private
operator|:
name|void
name|ConstructObject
argument_list|(
argument|uint32_t reg_num
argument_list|)
block|;
name|friend
name|class
name|ValueObjectRegisterSet
block|;
name|ValueObjectRegister
argument_list|(
argument|ValueObject&parent
argument_list|,
argument|lldb::RegisterContextSP&reg_ctx_sp
argument_list|,
argument|uint32_t reg_num
argument_list|)
block|;
name|ValueObjectRegister
argument_list|(
argument|ExecutionContextScope *exe_scope
argument_list|,
argument|lldb::RegisterContextSP&reg_ctx_sp
argument_list|,
argument|uint32_t reg_num
argument_list|)
block|;
comment|//------------------------------------------------------------------
comment|// For ValueObject only
comment|//------------------------------------------------------------------
name|DISALLOW_COPY_AND_ASSIGN
argument_list|(
name|ValueObjectRegister
argument_list|)
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
comment|// liblldb_ValueObjectRegister_h_
end_comment

end_unit

