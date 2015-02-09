begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- MICmdCmdMiscellanous.h ----------------------------------*- C++ -*-===//
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
comment|// File:        MICmdCmdMiscellanous.h
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// Overview:    CMICmdCmdGdbExit                interface.
end_comment

begin_comment
comment|//              CMICmdCmdListThreadGroups       interface.
end_comment

begin_comment
comment|//              CMICmdCmdInterpreterExec        interface.
end_comment

begin_comment
comment|//              CMICmdCmdInferiorTtySet         interface.
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

begin_comment
comment|//
end_comment

begin_comment
comment|// Environment: Compilers:  Visual C++ 12.
end_comment

begin_comment
comment|//                          gcc (Ubuntu/Linaro 4.8.1-10ubuntu9) 4.8.1
end_comment

begin_comment
comment|//              Libraries:  See MIReadmetxt.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// Copyright:   None.
end_comment

begin_comment
comment|//--
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

begin_include
include|#
directive|include
file|"MICmnMIValueTuple.h"
end_include

begin_include
include|#
directive|include
file|"MICmnMIValueList.h"
end_include

begin_comment
comment|//++ ============================================================================
end_comment

begin_comment
comment|// Details: MI command class. MI commands derived from the command base class.
end_comment

begin_comment
comment|//          *this class implements MI command "gdb-exit".
end_comment

begin_comment
comment|// Gotchas: None.
end_comment

begin_comment
comment|// Authors: Illya Rudkin 04/03/2014.
end_comment

begin_comment
comment|// Changes: None.
end_comment

begin_comment
comment|//--
end_comment

begin_decl_stmt
name|class
name|CMICmdCmdGdbExit
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
name|CMICmdCmdGdbExit
argument_list|(
name|void
argument_list|)
block|;
comment|// Overridden:
name|public
operator|:
comment|// From CMICmdInvoker::ICmd
name|virtual
name|bool
name|Execute
argument_list|(
name|void
argument_list|)
block|;
name|virtual
name|bool
name|Acknowledge
argument_list|(
name|void
argument_list|)
block|;
comment|// From CMICmnBase
comment|/* dtor */
name|virtual
operator|~
name|CMICmdCmdGdbExit
argument_list|(
name|void
argument_list|)
block|; }
decl_stmt|;
end_decl_stmt

begin_comment
comment|//++ ============================================================================
end_comment

begin_comment
comment|// Details: MI command class. MI commands derived from the command base class.
end_comment

begin_comment
comment|//          *this class implements MI command "list-thread-groups".
end_comment

begin_comment
comment|//          This command does not follow the MI documentation exactly.
end_comment

begin_comment
comment|//          http://sourceware.org/gdb/onlinedocs/gdb/GDB_002fMI-Miscellaneous-Commands.html#GDB_002fMI-Miscellaneous-Commands
end_comment

begin_comment
comment|// Gotchas: None.
end_comment

begin_comment
comment|// Authors: Illya Rudkin 06/03/2014.
end_comment

begin_comment
comment|// Changes: None.
end_comment

begin_comment
comment|//--
end_comment

begin_decl_stmt
name|class
name|CMICmdCmdListThreadGroups
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
name|CMICmdCmdListThreadGroups
argument_list|(
name|void
argument_list|)
block|;
comment|// Overridden:
name|public
operator|:
comment|// From CMICmdInvoker::ICmd
name|virtual
name|bool
name|Execute
argument_list|(
name|void
argument_list|)
block|;
name|virtual
name|bool
name|Acknowledge
argument_list|(
name|void
argument_list|)
block|;
name|virtual
name|bool
name|ParseArgs
argument_list|(
name|void
argument_list|)
block|;
comment|// From CMICmnBase
comment|/* dtor */
name|virtual
operator|~
name|CMICmdCmdListThreadGroups
argument_list|(
name|void
argument_list|)
block|;
comment|// Typedefs:
name|private
operator|:
typedef|typedef
name|std
operator|::
name|vector
operator|<
name|CMICmnMIValueTuple
operator|>
name|VecMIValueTuple_t
expr_stmt|;
comment|// Attributes:
name|private
operator|:
name|bool
name|m_bIsI1
decl_stmt|;
end_decl_stmt

begin_comment
comment|// True = Yes command argument equal "i1", false = no match
end_comment

begin_decl_stmt
name|bool
name|m_bHaveArgOption
decl_stmt|;
end_decl_stmt

begin_comment
comment|// True = Yes "--available" present, false = not found
end_comment

begin_decl_stmt
name|bool
name|m_bHaveArgRecurse
decl_stmt|;
end_decl_stmt

begin_comment
comment|// True = Yes command argument "--recurse", false = no found
end_comment

begin_decl_stmt
name|VecMIValueTuple_t
name|m_vecMIValueTuple
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|const
name|CMIUtilString
name|m_constStrArgNamedAvailable
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|const
name|CMIUtilString
name|m_constStrArgNamedRecurse
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|const
name|CMIUtilString
name|m_constStrArgNamedGroup
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|const
name|CMIUtilString
name|m_constStrArgNamedThreadGroup
decl_stmt|;
end_decl_stmt

begin_comment
unit|};
comment|//++ ============================================================================
end_comment

begin_comment
comment|// Details: MI command class. MI commands derived from the command base class.
end_comment

begin_comment
comment|//          *this class implements MI command "interpreter-exec".
end_comment

begin_comment
comment|// Gotchas: None.
end_comment

begin_comment
comment|// Authors: Illya Rudkin 16/05/2014.
end_comment

begin_comment
comment|// Changes: None.
end_comment

begin_comment
comment|//--
end_comment

begin_decl_stmt
name|class
name|CMICmdCmdInterpreterExec
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
name|CMICmdCmdInterpreterExec
argument_list|(
name|void
argument_list|)
block|;
comment|// Overridden:
name|public
operator|:
comment|// From CMICmdInvoker::ICmd
name|virtual
name|bool
name|Execute
argument_list|(
name|void
argument_list|)
block|;
name|virtual
name|bool
name|Acknowledge
argument_list|(
name|void
argument_list|)
block|;
name|virtual
name|bool
name|ParseArgs
argument_list|(
name|void
argument_list|)
block|;
comment|// From CMICmnBase
comment|/* dtor */
name|virtual
operator|~
name|CMICmdCmdInterpreterExec
argument_list|(
name|void
argument_list|)
block|;
comment|// Attributes:
name|private
operator|:
specifier|const
name|CMIUtilString
name|m_constStrArgNamedInterpreter
block|;
specifier|const
name|CMIUtilString
name|m_constStrArgNamedCommand
block|;
name|lldb
operator|::
name|SBCommandReturnObject
name|m_lldbResult
block|; }
decl_stmt|;
end_decl_stmt

begin_comment
comment|//++ ============================================================================
end_comment

begin_comment
comment|// Details: MI command class. MI commands derived from the command base class.
end_comment

begin_comment
comment|//          *this class implements MI command "inferior-tty-set".
end_comment

begin_comment
comment|// Gotchas: None.
end_comment

begin_comment
comment|// Authors: Illya Rudkin 22/07/2014.
end_comment

begin_comment
comment|// Changes: None.
end_comment

begin_comment
comment|//--
end_comment

begin_decl_stmt
name|class
name|CMICmdCmdInferiorTtySet
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
name|CMICmdCmdInferiorTtySet
argument_list|(
name|void
argument_list|)
block|;
comment|// Overridden:
name|public
operator|:
comment|// From CMICmdInvoker::ICmd
name|virtual
name|bool
name|Execute
argument_list|(
name|void
argument_list|)
block|;
name|virtual
name|bool
name|Acknowledge
argument_list|(
name|void
argument_list|)
block|;
comment|// From CMICmnBase
comment|/* dtor */
name|virtual
operator|~
name|CMICmdCmdInferiorTtySet
argument_list|(
name|void
argument_list|)
block|; }
decl_stmt|;
end_decl_stmt

end_unit

