begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- ValueObjectConstResult.h --------------------------------*- C++ -*-===//
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
name|liblldb_ValueObjectConstResult_h_
end_ifndef

begin_define
define|#
directive|define
name|liblldb_ValueObjectConstResult_h_
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
file|"lldb/Core/ValueObjectConstResultImpl.h"
end_include

begin_decl_stmt
name|namespace
name|lldb_private
block|{
comment|//----------------------------------------------------------------------
comment|// A frozen ValueObject copied into host memory
comment|//----------------------------------------------------------------------
name|class
name|ValueObjectConstResult
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
argument|lldb::ByteOrder byte_order
argument_list|,
argument|uint32_t addr_byte_size
argument_list|,
argument|lldb::addr_t address = LLDB_INVALID_ADDRESS
argument_list|)
block|;
specifier|static
name|lldb
operator|::
name|ValueObjectSP
name|Create
argument_list|(
argument|ExecutionContextScope *exe_scope
argument_list|,
argument|const ClangASTType&clang_type
argument_list|,
argument|const ConstString&name
argument_list|,
argument|const DataExtractor&data
argument_list|,
argument|lldb::addr_t address = LLDB_INVALID_ADDRESS
argument_list|)
block|;
specifier|static
name|lldb
operator|::
name|ValueObjectSP
name|Create
argument_list|(
argument|ExecutionContextScope *exe_scope
argument_list|,
argument|const ClangASTType&clang_type
argument_list|,
argument|const ConstString&name
argument_list|,
argument|const lldb::DataBufferSP&result_data_sp
argument_list|,
argument|lldb::ByteOrder byte_order
argument_list|,
argument|uint32_t addr_size
argument_list|,
argument|lldb::addr_t address = LLDB_INVALID_ADDRESS
argument_list|)
block|;
specifier|static
name|lldb
operator|::
name|ValueObjectSP
name|Create
argument_list|(
argument|ExecutionContextScope *exe_scope
argument_list|,
argument|const ClangASTType&clang_type
argument_list|,
argument|const ConstString&name
argument_list|,
argument|lldb::addr_t address
argument_list|,
argument|AddressType address_type
argument_list|,
argument|uint32_t addr_byte_size
argument_list|)
block|;
specifier|static
name|lldb
operator|::
name|ValueObjectSP
name|Create
argument_list|(
name|ExecutionContextScope
operator|*
name|exe_scope
argument_list|,
name|Value
operator|&
name|value
argument_list|,
specifier|const
name|ConstString
operator|&
name|name
argument_list|)
block|;
comment|// When an expression fails to evaluate, we return an error
specifier|static
name|lldb
operator|::
name|ValueObjectSP
name|Create
argument_list|(
name|ExecutionContextScope
operator|*
name|exe_scope
argument_list|,
specifier|const
name|Error
operator|&
name|error
argument_list|)
block|;
name|virtual
operator|~
name|ValueObjectConstResult
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
block|;
name|virtual
name|size_t
name|CalculateNumChildren
argument_list|()
block|;
name|virtual
name|ConstString
name|GetTypeName
argument_list|()
block|;
name|virtual
name|bool
name|IsInScope
argument_list|()
block|;
name|void
name|SetByteSize
argument_list|(
argument|size_t size
argument_list|)
block|;
name|virtual
name|lldb
operator|::
name|ValueObjectSP
name|Dereference
argument_list|(
name|Error
operator|&
name|error
argument_list|)
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
name|GetSyntheticChildAtOffset
argument_list|(
argument|uint32_t offset
argument_list|,
argument|const ClangASTType& type
argument_list|,
argument|bool can_create
argument_list|)
block|;
name|virtual
name|lldb
operator|::
name|ValueObjectSP
name|AddressOf
argument_list|(
name|Error
operator|&
name|error
argument_list|)
block|;
name|virtual
name|lldb
operator|::
name|addr_t
name|GetAddressOf
argument_list|(
argument|bool scalar_is_load_address = true
argument_list|,
argument|AddressType *address_type = NULL
argument_list|)
block|;
name|virtual
name|size_t
name|GetPointeeData
argument_list|(
argument|DataExtractor& data
argument_list|,
argument|uint32_t item_idx =
literal|0
argument_list|,
argument|uint32_t item_count =
literal|1
argument_list|)
block|;
name|virtual
name|lldb
operator|::
name|addr_t
name|GetLiveAddress
argument_list|()
block|{
return|return
name|m_impl
operator|.
name|GetLiveAddress
argument_list|()
return|;
block|}
name|virtual
name|void
name|SetLiveAddress
argument_list|(
argument|lldb::addr_t addr = LLDB_INVALID_ADDRESS
argument_list|,
argument|AddressType address_type = eAddressTypeLoad
argument_list|)
block|{
name|m_impl
operator|.
name|SetLiveAddress
argument_list|(
name|addr
argument_list|,
name|address_type
argument_list|)
block|;     }
name|virtual
name|lldb
operator|::
name|ValueObjectSP
name|GetDynamicValue
argument_list|(
argument|lldb::DynamicValueType valueType
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
name|ConstString
name|m_type_name
block|;
name|uint64_t
name|m_byte_size
block|;
name|ValueObjectConstResultImpl
name|m_impl
block|;
name|private
operator|:
name|friend
name|class
name|ValueObjectConstResultImpl
block|;
name|ValueObjectConstResult
argument_list|(
argument|ExecutionContextScope *exe_scope
argument_list|,
argument|lldb::ByteOrder byte_order
argument_list|,
argument|uint32_t addr_byte_size
argument_list|,
argument|lldb::addr_t address
argument_list|)
block|;
name|ValueObjectConstResult
argument_list|(
argument|ExecutionContextScope *exe_scope
argument_list|,
argument|const ClangASTType&clang_type
argument_list|,
argument|const ConstString&name
argument_list|,
argument|const DataExtractor&data
argument_list|,
argument|lldb::addr_t address
argument_list|)
block|;
name|ValueObjectConstResult
argument_list|(
argument|ExecutionContextScope *exe_scope
argument_list|,
argument|const ClangASTType&clang_type
argument_list|,
argument|const ConstString&name
argument_list|,
argument|const lldb::DataBufferSP&result_data_sp
argument_list|,
argument|lldb::ByteOrder byte_order
argument_list|,
argument|uint32_t addr_size
argument_list|,
argument|lldb::addr_t address
argument_list|)
block|;
name|ValueObjectConstResult
argument_list|(
argument|ExecutionContextScope *exe_scope
argument_list|,
argument|const ClangASTType&clang_type
argument_list|,
argument|const ConstString&name
argument_list|,
argument|lldb::addr_t address
argument_list|,
argument|AddressType address_type
argument_list|,
argument|uint32_t addr_byte_size
argument_list|)
block|;
name|ValueObjectConstResult
argument_list|(
name|ExecutionContextScope
operator|*
name|exe_scope
argument_list|,
specifier|const
name|Value
operator|&
name|value
argument_list|,
specifier|const
name|ConstString
operator|&
name|name
argument_list|)
block|;
name|ValueObjectConstResult
argument_list|(
name|ExecutionContextScope
operator|*
name|exe_scope
argument_list|,
specifier|const
name|Error
operator|&
name|error
argument_list|)
block|;
name|DISALLOW_COPY_AND_ASSIGN
argument_list|(
name|ValueObjectConstResult
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
comment|// liblldb_ValueObjectConstResult_h_
end_comment

end_unit

