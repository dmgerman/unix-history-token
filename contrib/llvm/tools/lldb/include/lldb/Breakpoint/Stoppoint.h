begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- Stoppoint.h ---------------------------------------------*- C++ -*-===//
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
name|liblldb_Stoppoint_h_
end_ifndef

begin_define
define|#
directive|define
name|liblldb_Stoppoint_h_
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
file|"lldb/Utility/UserID.h"
end_include

begin_include
include|#
directive|include
file|"lldb/lldb-private.h"
end_include

begin_decl_stmt
name|namespace
name|lldb_private
block|{
name|class
name|Stoppoint
block|{
name|public
label|:
comment|//------------------------------------------------------------------
comment|// Constructors and Destructors
comment|//------------------------------------------------------------------
name|Stoppoint
argument_list|()
expr_stmt|;
name|virtual
operator|~
name|Stoppoint
argument_list|()
expr_stmt|;
comment|//------------------------------------------------------------------
comment|// Methods
comment|//------------------------------------------------------------------
name|virtual
name|void
name|Dump
parameter_list|(
name|Stream
modifier|*
parameter_list|)
init|=
literal|0
function_decl|;
name|virtual
name|bool
name|IsEnabled
parameter_list|()
init|=
literal|0
function_decl|;
name|virtual
name|void
name|SetEnabled
parameter_list|(
name|bool
name|enable
parameter_list|)
init|=
literal|0
function_decl|;
name|lldb
operator|::
name|break_id_t
name|GetID
argument_list|()
specifier|const
expr_stmt|;
name|void
name|SetID
argument_list|(
name|lldb
operator|::
name|break_id_t
name|bid
argument_list|)
decl_stmt|;
name|protected
label|:
name|lldb
operator|::
name|break_id_t
name|m_bid
expr_stmt|;
name|private
label|:
comment|//------------------------------------------------------------------
comment|// For Stoppoint only
comment|//------------------------------------------------------------------
name|DISALLOW_COPY_AND_ASSIGN
argument_list|(
name|Stoppoint
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
comment|// liblldb_Stoppoint_h_
end_comment

end_unit

