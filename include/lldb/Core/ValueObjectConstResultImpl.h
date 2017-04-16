begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- ValueObjectConstResultImpl.h ----------------------------*- C++ -*-===//
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
name|liblldb_ValueObjectConstResultImpl_h_
end_ifndef

begin_define
define|#
directive|define
name|liblldb_ValueObjectConstResultImpl_h_
end_define

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
comment|// for LLDB_INVALID_ADDRESS
end_comment

begin_include
include|#
directive|include
file|"lldb/lldb-forward.h"
end_include

begin_comment
comment|// for ValueObjectSP
end_comment

begin_include
include|#
directive|include
file|"lldb/lldb-private-enumerations.h"
end_include

begin_comment
comment|// for AddressType, AddressType...
end_comment

begin_include
include|#
directive|include
file|"lldb/lldb-types.h"
end_include

begin_comment
comment|// for addr_t
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
comment|// for uint32_t, int32_t
end_comment

begin_decl_stmt
name|namespace
name|lldb_private
block|{
name|class
name|CompilerType
decl_stmt|;
block|}
end_decl_stmt

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
name|Error
decl_stmt|;
block|}
end_decl_stmt

begin_decl_stmt
name|namespace
name|lldb_private
block|{
name|class
name|ValueObject
decl_stmt|;
block|}
end_decl_stmt

begin_decl_stmt
name|namespace
name|lldb_private
block|{
comment|//----------------------------------------------------------------------
comment|// A class wrapping common implementation details for operations in
comment|// ValueObjectConstResult (& Child ) that may need to jump from the host
comment|// memory space into the target's memory space
comment|//----------------------------------------------------------------------
name|class
name|ValueObjectConstResultImpl
block|{
name|public
label|:
name|ValueObjectConstResultImpl
argument_list|(
argument|ValueObject *valobj
argument_list|,
argument|lldb::addr_t live_address = LLDB_INVALID_ADDRESS
argument_list|)
empty_stmt|;
name|virtual
operator|~
name|ValueObjectConstResultImpl
argument_list|()
operator|=
expr|default
expr_stmt|;
name|lldb
operator|::
name|ValueObjectSP
name|Dereference
argument_list|(
name|Error
operator|&
name|error
argument_list|)
expr_stmt|;
name|ValueObject
modifier|*
name|CreateChildAtIndex
parameter_list|(
name|size_t
name|idx
parameter_list|,
name|bool
name|synthetic_array_member
parameter_list|,
name|int32_t
name|synthetic_index
parameter_list|)
function_decl|;
name|lldb
operator|::
name|ValueObjectSP
name|GetSyntheticChildAtOffset
argument_list|(
argument|uint32_t offset
argument_list|,
argument|const CompilerType&type
argument_list|,
argument|bool can_create
argument_list|,
argument|ConstString name_const_str = ConstString()
argument_list|)
expr_stmt|;
name|lldb
operator|::
name|ValueObjectSP
name|AddressOf
argument_list|(
name|Error
operator|&
name|error
argument_list|)
expr_stmt|;
name|lldb
operator|::
name|addr_t
name|GetLiveAddress
argument_list|()
block|{
return|return
name|m_live_address
return|;
block|}
name|lldb
operator|::
name|ValueObjectSP
name|Cast
argument_list|(
specifier|const
name|CompilerType
operator|&
name|compiler_type
argument_list|)
expr_stmt|;
name|void
name|SetLiveAddress
argument_list|(
name|lldb
operator|::
name|addr_t
name|addr
operator|=
name|LLDB_INVALID_ADDRESS
argument_list|,
name|AddressType
name|address_type
operator|=
name|eAddressTypeLoad
argument_list|)
block|{
name|m_live_address
operator|=
name|addr
expr_stmt|;
name|m_live_address_type
operator|=
name|address_type
expr_stmt|;
block|}
name|virtual
name|lldb
operator|::
name|addr_t
name|GetAddressOf
argument_list|(
argument|bool scalar_is_load_address = true
argument_list|,
argument|AddressType *address_type = nullptr
argument_list|)
expr_stmt|;
name|virtual
name|size_t
name|GetPointeeData
parameter_list|(
name|DataExtractor
modifier|&
name|data
parameter_list|,
name|uint32_t
name|item_idx
init|=
literal|0
parameter_list|,
name|uint32_t
name|item_count
init|=
literal|1
parameter_list|)
function_decl|;
name|private
label|:
name|ValueObject
modifier|*
name|m_impl_backend
decl_stmt|;
name|lldb
operator|::
name|addr_t
name|m_live_address
expr_stmt|;
name|AddressType
name|m_live_address_type
decl_stmt|;
name|lldb
operator|::
name|ValueObjectSP
name|m_load_addr_backend
expr_stmt|;
name|lldb
operator|::
name|ValueObjectSP
name|m_address_of_backend
expr_stmt|;
name|DISALLOW_COPY_AND_ASSIGN
argument_list|(
name|ValueObjectConstResultImpl
argument_list|)
expr_stmt|;
block|}
empty_stmt|;
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
comment|// liblldb_ValueObjectConstResultImpl_h_
end_comment

end_unit

