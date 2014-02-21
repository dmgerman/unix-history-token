begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- ValueObjectDynamicValue.h -----------------------------------*- C++ -*-===//
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
name|ClangASTType
operator|&
name|cast_type
argument_list|)
block|;
name|virtual
operator|~
name|ValueObjectCast
argument_list|()
block|;
name|virtual
name|uint64_t
name|GetByteSize
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
name|bool
name|IsInScope
argument_list|()
block|;
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
name|ClangASTType
name|m_cast_type
block|;
name|private
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
name|ClangASTType
operator|&
name|cast_type
argument_list|)
block|;
comment|//------------------------------------------------------------------
comment|// For ValueObject only
comment|//------------------------------------------------------------------
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

