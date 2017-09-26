begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- RegisterNumber.h ----------------------------------------*- C++ -*-===//
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
name|LLDB_TARGET_REGISTERNUMBER_H
end_ifndef

begin_define
define|#
directive|define
name|LLDB_TARGET_REGISTERNUMBER_H
end_define

begin_include
include|#
directive|include
file|"lldb/lldb-private.h"
end_include

begin_include
include|#
directive|include
file|<map>
end_include

begin_comment
comment|//--------------------------------------------------------------------
end_comment

begin_comment
comment|/// A class to represent register numbers, and able to convert between
end_comment

begin_comment
comment|/// different register numbering schemes that may be used in a single
end_comment

begin_comment
comment|/// debug session.
end_comment

begin_comment
comment|//--------------------------------------------------------------------
end_comment

begin_decl_stmt
name|class
name|RegisterNumber
block|{
name|public
label|:
name|RegisterNumber
argument_list|(
argument|lldb_private::Thread&thread
argument_list|,
argument|lldb::RegisterKind kind
argument_list|,
argument|uint32_t num
argument_list|)
empty_stmt|;
comment|// This constructor plus the init() method below allow for the placeholder
comment|// creation of an invalid object initially, possibly to be filled in.  It
comment|// would be more consistent to have three Set* methods to set the three
comment|// data that the object needs.
name|RegisterNumber
argument_list|()
expr_stmt|;
name|void
name|init
argument_list|(
name|lldb_private
operator|::
name|Thread
operator|&
name|thread
argument_list|,
name|lldb
operator|::
name|RegisterKind
name|kind
argument_list|,
name|uint32_t
name|num
argument_list|)
decl_stmt|;
specifier|const
name|RegisterNumber
modifier|&
name|operator
init|=
operator|(
specifier|const
name|RegisterNumber
operator|&
name|rhs
operator|)
decl_stmt|;
name|bool
name|operator
operator|==
operator|(
name|RegisterNumber
operator|&
name|rhs
operator|)
expr_stmt|;
name|bool
name|operator
operator|!=
operator|(
name|RegisterNumber
operator|&
name|rhs
operator|)
expr_stmt|;
name|bool
name|IsValid
argument_list|()
specifier|const
expr_stmt|;
name|uint32_t
name|GetAsKind
argument_list|(
name|lldb
operator|::
name|RegisterKind
name|kind
argument_list|)
decl_stmt|;
name|uint32_t
name|GetRegisterNumber
argument_list|()
specifier|const
expr_stmt|;
name|lldb
operator|::
name|RegisterKind
name|GetRegisterKind
argument_list|()
specifier|const
expr_stmt|;
specifier|const
name|char
modifier|*
name|GetName
parameter_list|()
function_decl|;
name|private
label|:
typedef|typedef
name|std
operator|::
name|map
operator|<
name|lldb
operator|::
name|RegisterKind
operator|,
name|uint32_t
operator|>
name|Collection
expr_stmt|;
name|lldb
operator|::
name|RegisterContextSP
name|m_reg_ctx_sp
expr_stmt|;
name|uint32_t
name|m_regnum
decl_stmt|;
name|lldb
operator|::
name|RegisterKind
name|m_kind
expr_stmt|;
name|Collection
name|m_kind_regnum_map
decl_stmt|;
specifier|const
name|char
modifier|*
name|m_name
decl_stmt|;
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// liblldb_RegisterNumber_h
end_comment

end_unit

