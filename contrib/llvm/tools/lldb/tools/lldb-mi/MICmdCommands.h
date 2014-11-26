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

begin_comment
comment|//++
end_comment

begin_comment
comment|// File:		MICmdCommands.h
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// Overview:	CMICmdCommands instantiated.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// Environment:	Compilers:	Visual C++ 12.
end_comment

begin_comment
comment|//							gcc (Ubuntu/Linaro 4.8.1-10ubuntu9) 4.8.1
end_comment

begin_comment
comment|//				Libraries:	See MIReadmetxt.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// Copyright:	None.
end_comment

begin_comment
comment|//--
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
comment|// Details:	MI Command are instantiated and registered automatically with the
comment|//			Command Factory
comment|// Gotchas:	None.
comment|// Authors:	Illya Rudkin 18/02/2014.
comment|// Changes:	None.
comment|//--
name|bool
name|RegisterAll
parameter_list|(
name|void
parameter_list|)
function_decl|;
block|}
end_decl_stmt

end_unit

