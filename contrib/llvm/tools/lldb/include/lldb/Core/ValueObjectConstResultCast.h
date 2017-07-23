begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- ValueObjectConstResultCast.h ----------------------------*- C++ -*-===//
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
name|liblldb_ValueObjectConstResultCast_h_
end_ifndef

begin_define
define|#
directive|define
name|liblldb_ValueObjectConstResultCast_h_
end_define

begin_include
include|#
directive|include
file|"lldb/Core/ValueObjectCast.h"
end_include

begin_include
include|#
directive|include
file|"lldb/Core/ValueObjectConstResultImpl.h"
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
comment|// for DISALLOW_COPY_AND_...
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
name|ValueObject
decl_stmt|;
block|}
end_decl_stmt

begin_decl_stmt
name|namespace
name|lldb_private
block|{
name|class
name|ValueObjectConstResultCast
range|:
name|public
name|ValueObjectCast
block|{
name|public
operator|:
name|ValueObjectConstResultCast
argument_list|(
argument|ValueObject&parent
argument_list|,
argument|const ConstString&name
argument_list|,
argument|const CompilerType&cast_type
argument_list|,
argument|lldb::addr_t live_address = LLDB_INVALID_ADDRESS
argument_list|)
block|;
operator|~
name|ValueObjectConstResultCast
argument_list|()
name|override
block|;
name|lldb
operator|::
name|ValueObjectSP
name|Dereference
argument_list|(
argument|Status&error
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
name|virtual
name|CompilerType
name|GetCompilerType
argument_list|()
block|{
return|return
name|ValueObjectCast
operator|::
name|GetCompilerType
argument_list|()
return|;
block|}
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
name|override
block|;
name|lldb
operator|::
name|ValueObjectSP
name|AddressOf
argument_list|(
argument|Status&error
argument_list|)
name|override
block|;
name|size_t
name|GetPointeeData
argument_list|(
argument|DataExtractor&data
argument_list|,
argument|uint32_t item_idx =
literal|0
argument_list|,
argument|uint32_t item_count =
literal|1
argument_list|)
name|override
block|;
name|lldb
operator|::
name|ValueObjectSP
name|Cast
argument_list|(
argument|const CompilerType&compiler_type
argument_list|)
name|override
block|;
name|protected
operator|:
name|ValueObjectConstResultImpl
name|m_impl
block|;
name|private
operator|:
name|friend
name|class
name|ValueObject
block|;
name|friend
name|class
name|ValueObjectConstResult
block|;
name|friend
name|class
name|ValueObjectConstResultImpl
block|;
name|DISALLOW_COPY_AND_ASSIGN
argument_list|(
name|ValueObjectConstResultCast
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
comment|// liblldb_ValueObjectConstResultCast_h_
end_comment

end_unit

