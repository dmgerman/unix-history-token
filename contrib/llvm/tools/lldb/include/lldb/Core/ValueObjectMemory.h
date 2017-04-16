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

begin_include
include|#
directive|include
file|"lldb/Core/Address.h"
end_include

begin_comment
comment|// for Address
end_comment

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
file|"lldb/lldb-forward.h"
end_include

begin_comment
comment|// for TypeSP, ValueObjectSP, ModuleSP
end_comment

begin_include
include|#
directive|include
file|"llvm/ADT/StringRef.h"
end_include

begin_comment
comment|// for StringRef
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
name|ExecutionContextScope
decl_stmt|;
block|}
end_decl_stmt

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
operator|~
name|ValueObjectMemory
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
argument|llvm::StringRef name
argument_list|,
argument|const Address&address
argument_list|,
argument|lldb::TypeSP&type_sp
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
argument|llvm::StringRef name
argument_list|,
argument|const Address&address
argument_list|,
argument|const CompilerType&ast_type
argument_list|)
block|;
name|uint64_t
name|GetByteSize
argument_list|()
name|override
block|;
name|ConstString
name|GetTypeName
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
name|lldb
operator|::
name|ModuleSP
name|GetModule
argument_list|()
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
name|Address
name|m_address
block|;
comment|///< The variable that this value object is based upon
name|lldb
operator|::
name|TypeSP
name|m_type_sp
block|;
name|CompilerType
name|m_compiler_type
block|;
name|private
operator|:
name|ValueObjectMemory
argument_list|(
argument|ExecutionContextScope *exe_scope
argument_list|,
argument|llvm::StringRef name
argument_list|,
argument|const Address&address
argument_list|,
argument|lldb::TypeSP&type_sp
argument_list|)
block|;
name|ValueObjectMemory
argument_list|(
argument|ExecutionContextScope *exe_scope
argument_list|,
argument|llvm::StringRef name
argument_list|,
argument|const Address&address
argument_list|,
argument|const CompilerType&ast_type
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

