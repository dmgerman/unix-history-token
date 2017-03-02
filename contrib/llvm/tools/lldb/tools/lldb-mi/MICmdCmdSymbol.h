begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- MICmdCmdSymbol.h ----------------------------------------*- C++ -*-===//
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
comment|// Overview:    CMICmdCmdSymbolListLines     interface.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//              To implement new MI commands derive a new command class from the
end_comment

begin_comment
comment|//              command base
end_comment

begin_comment
comment|//              class. To enable the new command for interpretation add the new
end_comment

begin_comment
comment|//              command class
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
comment|//              For an introduction to adding a new command see
end_comment

begin_comment
comment|//              CMICmdCmdSupportInfoMiCmdQuery
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
comment|// Third party headers:
end_comment

begin_include
include|#
directive|include
file|"lldb/API/SBCommandReturnObject.h"
end_include

begin_comment
comment|// In-house headers:
end_comment

begin_include
include|#
directive|include
file|"MICmdBase.h"
end_include

begin_comment
comment|//++
end_comment

begin_comment
comment|//============================================================================
end_comment

begin_comment
comment|// Details: MI command class. MI commands derived from the command base class.
end_comment

begin_comment
comment|//          *this class implements MI command "symbol-list-lines".
end_comment

begin_comment
comment|//--
end_comment

begin_decl_stmt
name|class
name|CMICmdCmdSymbolListLines
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
argument_list|()
block|;
comment|// Methods:
name|public
operator|:
comment|/* ctor */
name|CMICmdCmdSymbolListLines
argument_list|()
block|;
comment|// Overridden:
name|public
operator|:
comment|// From CMICmdInvoker::ICmd
name|bool
name|Execute
argument_list|()
name|override
block|;
name|bool
name|Acknowledge
argument_list|()
name|override
block|;
name|bool
name|ParseArgs
argument_list|()
name|override
block|;
comment|// From CMICmnBase
comment|/* dtor */
operator|~
name|CMICmdCmdSymbolListLines
argument_list|()
name|override
block|;
comment|// Attributes:
name|private
operator|:
name|lldb
operator|::
name|SBCommandReturnObject
name|m_lldbResult
block|;
specifier|const
name|CMIUtilString
name|m_constStrArgNameFile
block|; }
decl_stmt|;
end_decl_stmt

end_unit

