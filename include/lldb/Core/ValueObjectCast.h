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
name|liblldb_ValueObjectCast_h_
end_ifndef

begin_define
define|#
directive|define
name|liblldb_ValueObjectCast_h_
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
file|"lldb/lldb-forward.h"
end_include

begin_comment
comment|// for ValueObjectSP
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
comment|// for uint32_t, uint64_t
end_comment

begin_decl_stmt
name|namespace
name|lldb_private
block|{
name|class
name|ConstString
decl_stmt|;
block|}
end_decl_stmt

begin_decl_stmt
name|namespace
name|lldb_private
block|{
comment|//---------------------------------------------------------------------------------
comment|// A ValueObject that represents a given value represented as a different type.
comment|//---------------------------------------------------------------------------------
name|class
name|ValueObjectCast
range|:
name|public
name|ValueObject
block|{
name|public
operator|:
operator|~
name|ValueObjectCast
argument_list|()
name|override
block|;
specifier|static
name|lldb
operator|::
name|ValueObjectSP
name|Create
argument_list|(
name|ValueObject
operator|&
name|parent
argument_list|,
specifier|const
name|ConstString
operator|&
name|name
argument_list|,
specifier|const
name|CompilerType
operator|&
name|cast_type
argument_list|)
block|;
name|uint64_t
name|GetByteSize
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
name|protected
operator|:
name|ValueObjectCast
argument_list|(
name|ValueObject
operator|&
name|parent
argument_list|,
specifier|const
name|ConstString
operator|&
name|name
argument_list|,
specifier|const
name|CompilerType
operator|&
name|cast_type
argument_list|)
block|;
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
name|CompilerType
name|m_cast_type
block|;
name|private
operator|:
name|DISALLOW_COPY_AND_ASSIGN
argument_list|(
name|ValueObjectCast
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
comment|// liblldb_ValueObjectCast_h_
end_comment

end_unit

