begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- StackID.h -----------------------------------------------*- C++ -*-===//
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
name|liblldb_StackID_h_
end_ifndef

begin_define
define|#
directive|define
name|liblldb_StackID_h_
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
file|"lldb/lldb-private.h"
end_include

begin_include
include|#
directive|include
file|"lldb/Core/AddressRange.h"
end_include

begin_decl_stmt
name|namespace
name|lldb_private
block|{
name|class
name|StackID
block|{
name|public
label|:
comment|//------------------------------------------------------------------
comment|// Constructors and Destructors
comment|//------------------------------------------------------------------
name|StackID
argument_list|()
operator|:
name|m_pc
argument_list|(
name|LLDB_INVALID_ADDRESS
argument_list|)
operator|,
name|m_cfa
argument_list|(
name|LLDB_INVALID_ADDRESS
argument_list|)
operator|,
name|m_symbol_scope
argument_list|(
argument|NULL
argument_list|)
block|{     }
name|explicit
name|StackID
argument_list|(
argument|lldb::addr_t pc
argument_list|,
argument|lldb::addr_t cfa
argument_list|,
argument|SymbolContextScope *symbol_scope
argument_list|)
operator|:
name|m_pc
argument_list|(
name|pc
argument_list|)
operator|,
name|m_cfa
argument_list|(
name|cfa
argument_list|)
operator|,
name|m_symbol_scope
argument_list|(
argument|symbol_scope
argument_list|)
block|{     }
name|StackID
argument_list|(
specifier|const
name|StackID
operator|&
name|rhs
argument_list|)
operator|:
name|m_pc
argument_list|(
name|rhs
operator|.
name|m_pc
argument_list|)
operator|,
name|m_cfa
argument_list|(
name|rhs
operator|.
name|m_cfa
argument_list|)
operator|,
name|m_symbol_scope
argument_list|(
argument|rhs.m_symbol_scope
argument_list|)
block|{     }
operator|~
name|StackID
argument_list|()
block|{     }
name|lldb
operator|::
name|addr_t
name|GetPC
argument_list|()
specifier|const
block|{
return|return
name|m_pc
return|;
block|}
name|lldb
operator|::
name|addr_t
name|GetCallFrameAddress
argument_list|()
specifier|const
block|{
return|return
name|m_cfa
return|;
block|}
name|SymbolContextScope
operator|*
name|GetSymbolContextScope
argument_list|()
specifier|const
block|{
return|return
name|m_symbol_scope
return|;
block|}
name|void
name|SetSymbolContextScope
parameter_list|(
name|SymbolContextScope
modifier|*
name|symbol_scope
parameter_list|)
block|{
name|m_symbol_scope
operator|=
name|symbol_scope
expr_stmt|;
block|}
name|void
name|Clear
parameter_list|()
block|{
name|m_pc
operator|=
name|LLDB_INVALID_ADDRESS
expr_stmt|;
name|m_cfa
operator|=
name|LLDB_INVALID_ADDRESS
expr_stmt|;
name|m_symbol_scope
operator|=
name|NULL
expr_stmt|;
block|}
name|bool
name|IsValid
argument_list|()
specifier|const
block|{
return|return
name|m_pc
operator|!=
name|LLDB_INVALID_ADDRESS
operator|||
name|m_cfa
operator|!=
name|LLDB_INVALID_ADDRESS
return|;
block|}
name|void
name|Dump
parameter_list|(
name|Stream
modifier|*
name|s
parameter_list|)
function_decl|;
comment|//------------------------------------------------------------------
comment|// Operators
comment|//------------------------------------------------------------------
specifier|const
name|StackID
modifier|&
name|operator
init|=
operator|(
specifier|const
name|StackID
operator|&
name|rhs
operator|)
block|{
if|if
condition|(
name|this
operator|!=
operator|&
name|rhs
condition|)
block|{
name|m_pc
operator|=
name|rhs
operator|.
name|m_pc
expr_stmt|;
name|m_cfa
operator|=
name|rhs
operator|.
name|m_cfa
expr_stmt|;
name|m_symbol_scope
operator|=
name|rhs
operator|.
name|m_symbol_scope
expr_stmt|;
block|}
return|return
operator|*
name|this
return|;
block|}
name|protected
label|:
name|friend
name|class
name|StackFrame
decl_stmt|;
name|void
name|SetPC
argument_list|(
name|lldb
operator|::
name|addr_t
name|pc
argument_list|)
block|{
name|m_pc
operator|=
name|pc
expr_stmt|;
block|}
name|void
name|SetCFA
argument_list|(
name|lldb
operator|::
name|addr_t
name|cfa
argument_list|)
block|{
name|m_cfa
operator|=
name|cfa
expr_stmt|;
block|}
comment|//------------------------------------------------------------------
comment|// Classes that inherit from StackID can see and modify these
comment|//------------------------------------------------------------------
name|lldb
operator|::
name|addr_t
name|m_pc
expr_stmt|;
comment|// The pc value for the function/symbol for this frame. This will
comment|// only get used if the symbol scope is NULL (the code where we are
comment|// stopped is not represented by any function or symbol in any
comment|// shared library).
name|lldb
operator|::
name|addr_t
name|m_cfa
expr_stmt|;
comment|// The call frame address (stack pointer) value
comment|// at the beginning of the function that uniquely
comment|// identifies this frame (along with m_symbol_scope below)
name|SymbolContextScope
modifier|*
name|m_symbol_scope
decl_stmt|;
comment|// If NULL, there is no block or symbol for this frame.
comment|// If not NULL, this will either be the scope for the
comment|// lexical block for the frame, or the scope
comment|// for the symbol. Symbol context scopes are
comment|// always be unique pointers since the are part
comment|// of the Block and Symbol objects and can easily
comment|// be used to tell if a stack ID is the same as
comment|// another.
block|}
empty_stmt|;
name|bool
name|operator
operator|==
operator|(
specifier|const
name|StackID
operator|&
name|lhs
operator|,
specifier|const
name|StackID
operator|&
name|rhs
operator|)
expr_stmt|;
name|bool
name|operator
operator|!=
operator|(
specifier|const
name|StackID
operator|&
name|lhs
operator|,
specifier|const
name|StackID
operator|&
name|rhs
operator|)
expr_stmt|;
comment|// frame_id_1< frame_id_2 means "frame_id_1 is YOUNGER than frame_id_2"
name|bool
name|operator
operator|<
operator|(
specifier|const
name|StackID
operator|&
name|lhs
operator|,
specifier|const
name|StackID
operator|&
name|rhs
operator|)
expr_stmt|;
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
comment|// liblldb_StackID_h_
end_comment

end_unit

