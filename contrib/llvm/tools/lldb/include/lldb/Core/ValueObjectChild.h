begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- ValueObjectChild.h --------------------------------------*- C++ -*-===//
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
name|liblldb_ValueObjectChild_h_
end_ifndef

begin_define
define|#
directive|define
name|liblldb_ValueObjectChild_h_
end_define

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
comment|// for ValueType
end_comment

begin_include
include|#
directive|include
file|"lldb/lldb-private-enumerations.h"
end_include

begin_comment
comment|// for LazyBool, AddressType
end_comment

begin_include
include|#
directive|include
file|"lldb/lldb-types.h"
end_include

begin_comment
comment|// for offset_t
end_comment

begin_include
include|#
directive|include
file|"llvm/ADT/Optional.h"
end_include

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
comment|//----------------------------------------------------------------------
comment|// A child of another ValueObject.
comment|//----------------------------------------------------------------------
name|class
name|ValueObjectChild
range|:
name|public
name|ValueObject
block|{
name|public
operator|:
operator|~
name|ValueObjectChild
argument_list|()
name|override
block|;
name|uint64_t
name|GetByteSize
argument_list|()
name|override
block|{
return|return
name|m_byte_size
return|;
block|}
name|lldb
operator|::
name|offset_t
name|GetByteOffset
argument_list|()
name|override
block|{
return|return
name|m_byte_offset
return|;
block|}
name|uint32_t
name|GetBitfieldBitSize
argument_list|()
name|override
block|{
return|return
name|m_bitfield_bit_size
return|;
block|}
name|uint32_t
name|GetBitfieldBitOffset
argument_list|()
name|override
block|{
return|return
name|m_bitfield_bit_offset
return|;
block|}
name|lldb
operator|::
name|ValueType
name|GetValueType
argument_list|()
specifier|const
name|override
block|;
name|size_t
name|CalculateNumChildren
argument_list|(
argument|uint32_t max
argument_list|)
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
name|IsInScope
argument_list|()
name|override
block|;
name|bool
name|IsBaseClass
argument_list|()
name|override
block|{
return|return
name|m_is_base_class
return|;
block|}
name|bool
name|IsDereferenceOfParent
argument_list|()
name|override
block|{
return|return
name|m_is_deref_of_parent
return|;
block|}
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
block|;
name|CompilerType
name|GetCompilerTypeImpl
argument_list|()
name|override
block|{
return|return
name|m_compiler_type
return|;
block|}
name|CompilerType
name|m_compiler_type
block|;
name|ConstString
name|m_type_name
block|;
name|uint64_t
name|m_byte_size
block|;
name|int32_t
name|m_byte_offset
block|;
name|uint8_t
name|m_bitfield_bit_size
block|;
name|uint8_t
name|m_bitfield_bit_offset
block|;
name|bool
name|m_is_base_class
block|;
name|bool
name|m_is_deref_of_parent
block|;
name|llvm
operator|::
name|Optional
operator|<
name|LazyBool
operator|>
name|m_can_update_with_invalid_exe_ctx
block|;
comment|//
comment|//  void
comment|//  ReadValueFromMemory (ValueObject* parent, lldb::addr_t address);
name|protected
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
name|ValueObjectChild
argument_list|(
argument|ValueObject&parent
argument_list|,
argument|const CompilerType&compiler_type
argument_list|,
argument|const ConstString&name
argument_list|,
argument|uint64_t byte_size
argument_list|,
argument|int32_t byte_offset
argument_list|,
argument|uint32_t bitfield_bit_size
argument_list|,
argument|uint32_t bitfield_bit_offset
argument_list|,
argument|bool is_base_class
argument_list|,
argument|bool is_deref_of_parent
argument_list|,
argument|AddressType child_ptr_or_ref_addr_type
argument_list|,
argument|uint64_t language_flags
argument_list|)
block|;
name|DISALLOW_COPY_AND_ASSIGN
argument_list|(
name|ValueObjectChild
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
comment|// liblldb_ValueObjectChild_h_
end_comment

end_unit

