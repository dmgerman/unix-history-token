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
comment|// for DISALLOW_COPY_AND_ASSIGN
end_comment

begin_include
include|#
directive|include
file|"lldb/lldb-enumerations.h"
end_include

begin_comment
comment|// for ValueType, ValueType::eValueTy...
end_comment

begin_include
include|#
directive|include
file|"lldb/lldb-forward.h"
end_include

begin_comment
comment|// for RegisterContextSP, ValueObjectSP
end_comment

begin_include
include|#
directive|include
file|"lldb/lldb-private-types.h"
end_include

begin_comment
comment|// for RegisterInfo, RegisterSet (ptr...
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
comment|// for uint32_t, uint64_t, int32_t
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
name|Status
decl_stmt|;
block|}
end_decl_stmt

begin_decl_stmt
name|namespace
name|lldb_private
block|{
name|class
name|ExecutionContextScope
decl_stmt|;
block|}
end_decl_stmt

begin_decl_stmt
name|namespace
name|lldb_private
block|{
name|class
name|Scalar
decl_stmt|;
block|}
end_decl_stmt

begin_decl_stmt
name|namespace
name|lldb_private
block|{
name|class
name|Stream
decl_stmt|;
block|}
end_decl_stmt

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
operator|~
name|ValueObjectRegisterContext
argument_list|()
name|override
block|;
name|uint64_t
name|GetByteSize
argument_list|()
name|override
block|;
name|lldb
operator|::
name|ValueType
name|GetValueType
argument_list|()
specifier|const
name|override
block|{
return|return
name|lldb
operator|::
name|eValueTypeRegisterSet
return|;
block|}
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
name|override
block|;
name|protected
operator|:
name|bool
name|UpdateValue
argument_list|()
name|override
block|;
name|CompilerType
name|GetCompilerTypeImpl
argument_list|()
name|override
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
operator|~
name|ValueObjectRegisterSet
argument_list|()
name|override
block|;
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
name|uint64_t
name|GetByteSize
argument_list|()
name|override
block|;
name|lldb
operator|::
name|ValueType
name|GetValueType
argument_list|()
specifier|const
name|override
block|{
return|return
name|lldb
operator|::
name|eValueTypeRegisterSet
return|;
block|}
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
name|size_t
name|CalculateNumChildren
argument_list|(
argument|uint32_t max
argument_list|)
name|override
block|;
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
name|protected
operator|:
name|bool
name|UpdateValue
argument_list|()
name|override
block|;
name|CompilerType
name|GetCompilerTypeImpl
argument_list|()
name|override
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
operator|~
name|ValueObjectRegister
argument_list|()
name|override
block|;
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
name|uint64_t
name|GetByteSize
argument_list|()
name|override
block|;
name|lldb
operator|::
name|ValueType
name|GetValueType
argument_list|()
specifier|const
name|override
block|{
return|return
name|lldb
operator|::
name|eValueTypeRegister
return|;
block|}
name|ConstString
name|GetTypeName
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
name|bool
name|SetValueFromCString
argument_list|(
argument|const char *value_str
argument_list|,
argument|Status&error
argument_list|)
name|override
block|;
name|bool
name|SetData
argument_list|(
argument|DataExtractor&data
argument_list|,
argument|Status&error
argument_list|)
name|override
block|;
name|bool
name|ResolveValue
argument_list|(
argument|Scalar&scalar
argument_list|)
name|override
block|;
name|void
name|GetExpressionPath
argument_list|(
argument|Stream&s
argument_list|,
argument|bool qualify_cxx_base_classes
argument_list|,
argument|GetExpressionPathFormat epformat =                         eGetExpressionPathFormatDereferencePointers
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
name|CompilerType
name|GetCompilerTypeImpl
argument_list|()
name|override
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
name|CompilerType
name|m_compiler_type
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

