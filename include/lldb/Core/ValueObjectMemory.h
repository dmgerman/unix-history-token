begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- ValueObjectMemory.h -----------------------------------*- C++ -*-===//
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
name|liblldb_ValueObjectMemory_h_
end_ifndef

begin_define
define|#
directive|define
name|liblldb_ValueObjectMemory_h_
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
file|"lldb/Symbol/ClangASTType.h"
end_include

begin_decl_stmt
name|namespace
name|lldb_private
block|{
comment|//----------------------------------------------------------------------
comment|// A ValueObject that represents memory at a given address, viewed as some
comment|// set lldb type.
comment|//----------------------------------------------------------------------
name|class
name|ValueObjectMemory
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
name|ExecutionContextScope
operator|*
name|exe_scope
argument_list|,
specifier|const
name|char
operator|*
name|name
argument_list|,
specifier|const
name|Address
operator|&
name|address
argument_list|,
name|lldb
operator|::
name|TypeSP
operator|&
name|type_sp
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
specifier|const
name|char
operator|*
name|name
argument_list|,
specifier|const
name|Address
operator|&
name|address
argument_list|,
specifier|const
name|ClangASTType
operator|&
name|ast_type
argument_list|)
block|;
name|virtual
operator|~
name|ValueObjectMemory
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
name|GetDisplayTypeName
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
name|lldb
operator|::
name|ModuleSP
name|GetModule
argument_list|()
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
name|Address
name|m_address
block|;
comment|///< The variable that this value object is based upon
name|lldb
operator|::
name|TypeSP
name|m_type_sp
block|;
name|ClangASTType
name|m_clang_type
block|;
name|private
operator|:
name|ValueObjectMemory
argument_list|(
name|ExecutionContextScope
operator|*
name|exe_scope
argument_list|,
specifier|const
name|char
operator|*
name|name
argument_list|,
specifier|const
name|Address
operator|&
name|address
argument_list|,
name|lldb
operator|::
name|TypeSP
operator|&
name|type_sp
argument_list|)
block|;
name|ValueObjectMemory
argument_list|(
name|ExecutionContextScope
operator|*
name|exe_scope
argument_list|,
specifier|const
name|char
operator|*
name|name
argument_list|,
specifier|const
name|Address
operator|&
name|address
argument_list|,
specifier|const
name|ClangASTType
operator|&
name|ast_type
argument_list|)
block|;
comment|//------------------------------------------------------------------
comment|// For ValueObject only
comment|//------------------------------------------------------------------
name|DISALLOW_COPY_AND_ASSIGN
argument_list|(
name|ValueObjectMemory
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
comment|// liblldb_ValueObjectMemory_h_
end_comment

end_unit

