begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- MICmdCommands.h -----------------------------------------*- C++ -*-===//
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

begin_pragma
pragma|#
directive|pragma
name|once
end_pragma

begin_decl_stmt
name|namespace
name|MICmnCommands
block|{
comment|//++ ============================================================================
comment|// Details: MI Command are instantiated and registered automatically with the
comment|//          Command Factory
comment|//--
name|bool
name|RegisterAll
parameter_list|()
function_decl|;
block|}
end_decl_stmt

end_unit

