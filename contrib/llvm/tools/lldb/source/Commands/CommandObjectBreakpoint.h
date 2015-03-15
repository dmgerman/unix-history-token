begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- CommandObjectBreakpoint.h -------------------------------*- C++ -*-===//
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
name|liblldb_CommandObjectBreakpoint_h_
end_ifndef

begin_define
define|#
directive|define
name|liblldb_CommandObjectBreakpoint_h_
end_define

begin_comment
comment|// C Includes
end_comment

begin_comment
comment|// C++ Includes
end_comment

begin_include
include|#
directive|include
file|<utility>
end_include

begin_include
include|#
directive|include
file|<vector>
end_include

begin_comment
comment|// Other libraries and framework includes
end_comment

begin_comment
comment|// Project includes
end_comment

begin_include
include|#
directive|include
file|"lldb/Core/Address.h"
end_include

begin_include
include|#
directive|include
file|"lldb/Interpreter/CommandObjectMultiword.h"
end_include

begin_include
include|#
directive|include
file|"lldb/Interpreter/Options.h"
end_include

begin_include
include|#
directive|include
file|"lldb/Core/STLUtils.h"
end_include

begin_decl_stmt
name|namespace
name|lldb_private
block|{
comment|//-------------------------------------------------------------------------
comment|// CommandObjectMultiwordBreakpoint
comment|//-------------------------------------------------------------------------
name|class
name|CommandObjectMultiwordBreakpoint
range|:
name|public
name|CommandObjectMultiword
block|{
name|public
operator|:
name|CommandObjectMultiwordBreakpoint
argument_list|(
name|CommandInterpreter
operator|&
name|interpreter
argument_list|)
block|;
name|virtual
operator|~
name|CommandObjectMultiwordBreakpoint
argument_list|()
block|;
specifier|static
name|void
name|VerifyBreakpointOrLocationIDs
argument_list|(
argument|Args&args
argument_list|,
argument|Target *target
argument_list|,
argument|CommandReturnObject&result
argument_list|,
argument|BreakpointIDList *valid_ids
argument_list|)
block|{
name|VerifyIDs
argument_list|(
name|args
argument_list|,
name|target
argument_list|,
name|true
argument_list|,
name|result
argument_list|,
name|valid_ids
argument_list|)
block|;     }
specifier|static
name|void
name|VerifyBreakpointIDs
argument_list|(
argument|Args&args
argument_list|,
argument|Target *target
argument_list|,
argument|CommandReturnObject&result
argument_list|,
argument|BreakpointIDList *valid_ids
argument_list|)
block|{
name|VerifyIDs
argument_list|(
name|args
argument_list|,
name|target
argument_list|,
name|false
argument_list|,
name|result
argument_list|,
name|valid_ids
argument_list|)
block|;     }
name|private
operator|:
specifier|static
name|void
name|VerifyIDs
argument_list|(
argument|Args&args
argument_list|,
argument|Target *target
argument_list|,
argument|bool allow_locations
argument_list|,
argument|CommandReturnObject&result
argument_list|,
argument|BreakpointIDList *valid_ids
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
comment|// liblldb_CommandObjectBreakpoint_h_
end_comment

end_unit

