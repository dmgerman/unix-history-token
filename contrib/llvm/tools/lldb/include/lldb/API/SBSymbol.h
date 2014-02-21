begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- SBSymbol.h ----------------------------------------------*- C++ -*-===//
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
name|LLDB_SBSymbol_h_
end_ifndef

begin_define
define|#
directive|define
name|LLDB_SBSymbol_h_
end_define

begin_include
include|#
directive|include
file|"lldb/API/SBDefines.h"
end_include

begin_include
include|#
directive|include
file|"lldb/API/SBAddress.h"
end_include

begin_include
include|#
directive|include
file|"lldb/API/SBInstructionList.h"
end_include

begin_include
include|#
directive|include
file|"lldb/API/SBTarget.h"
end_include

begin_decl_stmt
name|namespace
name|lldb
block|{
name|class
name|SBSymbol
block|{
name|public
label|:
name|SBSymbol
argument_list|()
expr_stmt|;
operator|~
name|SBSymbol
argument_list|()
expr_stmt|;
name|SBSymbol
argument_list|(
specifier|const
name|lldb
operator|::
name|SBSymbol
operator|&
name|rhs
argument_list|)
expr_stmt|;
specifier|const
name|lldb
operator|::
name|SBSymbol
operator|&
name|operator
operator|=
operator|(
specifier|const
name|lldb
operator|::
name|SBSymbol
operator|&
name|rhs
operator|)
expr_stmt|;
name|bool
name|IsValid
argument_list|()
specifier|const
expr_stmt|;
specifier|const
name|char
operator|*
name|GetName
argument_list|()
specifier|const
expr_stmt|;
specifier|const
name|char
operator|*
name|GetMangledName
argument_list|()
specifier|const
expr_stmt|;
name|lldb
operator|::
name|SBInstructionList
name|GetInstructions
argument_list|(
argument|lldb::SBTarget target
argument_list|)
expr_stmt|;
name|lldb
operator|::
name|SBInstructionList
name|GetInstructions
argument_list|(
argument|lldb::SBTarget target
argument_list|,
argument|const char *flavor_string
argument_list|)
expr_stmt|;
name|SBAddress
name|GetStartAddress
parameter_list|()
function_decl|;
name|SBAddress
name|GetEndAddress
parameter_list|()
function_decl|;
name|uint32_t
name|GetPrologueByteSize
parameter_list|()
function_decl|;
name|SymbolType
name|GetType
parameter_list|()
function_decl|;
name|bool
name|operator
operator|==
operator|(
specifier|const
name|lldb
operator|::
name|SBSymbol
operator|&
name|rhs
operator|)
specifier|const
expr_stmt|;
name|bool
name|operator
operator|!=
operator|(
specifier|const
name|lldb
operator|::
name|SBSymbol
operator|&
name|rhs
operator|)
specifier|const
expr_stmt|;
name|bool
name|GetDescription
argument_list|(
name|lldb
operator|::
name|SBStream
operator|&
name|description
argument_list|)
decl_stmt|;
comment|//----------------------------------------------------------------------
comment|// Returns true if the symbol is externally visible in the module that
comment|// it is defined in
comment|//----------------------------------------------------------------------
name|bool
name|IsExternal
parameter_list|()
function_decl|;
comment|//----------------------------------------------------------------------
comment|// Returns true if the symbol was synthetically generated from something
comment|// other than the actual symbol table itself in the object file.
comment|//----------------------------------------------------------------------
name|bool
name|IsSynthetic
parameter_list|()
function_decl|;
name|protected
label|:
name|lldb_private
operator|::
name|Symbol
operator|*
name|get
argument_list|()
expr_stmt|;
name|void
name|reset
argument_list|(
name|lldb_private
operator|::
name|Symbol
operator|*
argument_list|)
decl_stmt|;
name|private
label|:
name|friend
name|class
name|SBAddress
decl_stmt|;
name|friend
name|class
name|SBFrame
decl_stmt|;
name|friend
name|class
name|SBModule
decl_stmt|;
name|friend
name|class
name|SBSymbolContext
decl_stmt|;
name|SBSymbol
argument_list|(
name|lldb_private
operator|::
name|Symbol
operator|*
name|lldb_object_ptr
argument_list|)
expr_stmt|;
name|void
name|SetSymbol
argument_list|(
name|lldb_private
operator|::
name|Symbol
operator|*
name|lldb_object_ptr
argument_list|)
decl_stmt|;
name|lldb_private
operator|::
name|Symbol
operator|*
name|m_opaque_ptr
expr_stmt|;
block|}
empty_stmt|;
block|}
end_decl_stmt

begin_comment
comment|// namespace lldb
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// LLDB_SBSymbol_h_
end_comment

end_unit

