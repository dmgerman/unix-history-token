begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- MICmdCmdTrace.h -----------------------------------------*- C++ -*-===//
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
comment|// Overview:    CMICmdCmdTraceStatus            interface.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//              To implement new MI commands derive a new command class from the command base
end_comment

begin_comment
comment|//              class. To enable the new command for interpretation add the new command class
end_comment

begin_comment
comment|//              to the command factory. The files of relevance are:
end_comment

begin_comment
comment|//                  MICmdCommands.cpp
end_comment

begin_comment
comment|//                  MICmdBase.h / .cpp
end_comment

begin_comment
comment|//                  MICmdCmd.h / .cpp
end_comment

begin_comment
comment|//              For an introduction to adding a new command see CMICmdCmdSupportInfoMiCmdQuery
end_comment

begin_comment
comment|//              command class as an example.
end_comment

begin_pragma
pragma|#
directive|pragma
name|once
end_pragma

begin_comment
comment|// In-house headers:
end_comment

begin_include
include|#
directive|include
file|"MICmdBase.h"
end_include

begin_comment
comment|//++ ============================================================================
end_comment

begin_comment
comment|// Details: MI command class. MI commands derived from the command base class.
end_comment

begin_comment
comment|//          *this class implements MI command "trace-status".
end_comment

begin_comment
comment|// Gotchas: None.
end_comment

begin_comment
comment|// Authors: Illya Rudkin 07/03/2014.
end_comment

begin_comment
comment|// Changes: None.
end_comment

begin_comment
comment|//--
end_comment

begin_decl_stmt
name|class
name|CMICmdCmdTraceStatus
range|:
name|public
name|CMICmdBase
block|{
comment|// Statics:
name|public
operator|:
comment|// Required by the CMICmdFactory when registering *this command
specifier|static
name|CMICmdBase
operator|*
name|CreateSelf
argument_list|(
name|void
argument_list|)
block|;
comment|// Methods:
name|public
operator|:
comment|/* ctor */
name|CMICmdCmdTraceStatus
argument_list|(
name|void
argument_list|)
block|;
comment|// Overridden:
name|public
operator|:
comment|// From CMICmdInvoker::ICmd
name|bool
name|Execute
argument_list|(
argument|void
argument_list|)
name|override
block|;
name|bool
name|Acknowledge
argument_list|(
argument|void
argument_list|)
name|override
block|;
comment|// From CMICmnBase
comment|/* dtor */
operator|~
name|CMICmdCmdTraceStatus
argument_list|(
argument|void
argument_list|)
name|override
block|; }
decl_stmt|;
end_decl_stmt

end_unit

