begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- MICmdCmdBreak.h -----------------------------------------*- C++ -*-===//
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
comment|// File:        MICmdCmdBreak.h
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// Overview:    CMICmdCmdBreakInsert            interface.
end_comment

begin_comment
comment|//              CMICmdCmdBreakDelete            interface.
end_comment

begin_comment
comment|//              CMICmdCmdBreakDisable           interface.
end_comment

begin_comment
comment|//              CMICmdCmdBreakEnable            interface.
end_comment

begin_comment
comment|//              CMICmdCmdBreakAfter             interface.
end_comment

begin_comment
comment|//              CMICmdCmdBreakCondition         interface.
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
file|<lldb/API/SBBreakpoint.h>
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
comment|//++ ============================================================================
end_comment

begin_comment
comment|// Details: MI command class. MI commands derived from the command base class.
end_comment

begin_comment
comment|//          *this class implements MI command "break-insert".
end_comment

begin_comment
comment|//          This command does not follow the MI documentation exactly.
end_comment

begin_comment
comment|// Gotchas: None.
end_comment

begin_comment
comment|// Authors: Illya Rudkin 11/03/2014.
end_comment

begin_comment
comment|// Changes: None.
end_comment

begin_comment
comment|//--
end_comment

begin_decl_stmt
name|class
name|CMICmdCmdBreakInsert
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
name|CMICmdCmdBreakInsert
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
name|CMICmdCmdBreakInsert
argument_list|(
name|void
argument_list|)
block|;
comment|// Enumerations:
name|private
operator|:
comment|//++ ===================================================================
comment|// Details: The type of break point give in the MI command text.
comment|//--
expr|enum
name|BreakPoint_e
block|{
name|eBreakPoint_Invalid
operator|=
literal|0
block|,
name|eBreakPoint_ByFileLine
block|,
name|eBreakPoint_ByFileFn
block|,
name|eBreakPoint_ByName
block|,
name|eBreakPoint_ByAddress
block|,
name|eBreakPoint_count
block|,
name|eBreakPoint_NotDefineYet
block|}
block|;
comment|// Attributes:
name|private
operator|:
name|bool
name|m_bBrkPtIsTemp
block|;
name|bool
name|m_bHaveArgOptionThreadGrp
block|;
name|CMIUtilString
name|m_brkName
block|;
name|CMIUtilString
name|m_strArgOptionThreadGrp
block|;
name|lldb
operator|::
name|SBBreakpoint
name|m_brkPt
block|;
name|bool
name|m_bBrkPtIsPending
block|;
name|MIuint
name|m_nBrkPtIgnoreCount
block|;
name|bool
name|m_bBrkPtEnabled
block|;
name|bool
name|m_bBrkPtCondition
block|;
name|CMIUtilString
name|m_brkPtCondition
block|;
name|bool
name|m_bBrkPtThreadId
block|;
name|MIuint
name|m_nBrkPtThreadId
block|;
specifier|const
name|CMIUtilString
name|m_constStrArgNamedTempBrkPt
block|;
specifier|const
name|CMIUtilString
name|m_constStrArgNamedHWBrkPt
block|;
comment|// Not handled by *this command
specifier|const
name|CMIUtilString
name|m_constStrArgNamedPendinfBrkPt
block|;
specifier|const
name|CMIUtilString
name|m_constStrArgNamedDisableBrkPt
block|;
specifier|const
name|CMIUtilString
name|m_constStrArgNamedTracePt
block|;
comment|// Not handled by *this command
specifier|const
name|CMIUtilString
name|m_constStrArgNamedConditionalBrkPt
block|;
specifier|const
name|CMIUtilString
name|m_constStrArgNamedInoreCnt
block|;
specifier|const
name|CMIUtilString
name|m_constStrArgNamedRestrictBrkPtToThreadId
block|;
specifier|const
name|CMIUtilString
name|m_constStrArgNamedLocation
block|;
specifier|const
name|CMIUtilString
name|m_constStrArgNamedThreadGroup
block|;
comment|// Not specified in MI spec but Eclipse gives this option sometimes
block|}
decl_stmt|;
end_decl_stmt

begin_comment
comment|//++ ============================================================================
end_comment

begin_comment
comment|// Details: MI command class. MI commands derived from the command base class.
end_comment

begin_comment
comment|//          *this class implements MI command "break-delete".
end_comment

begin_comment
comment|// Gotchas: None.
end_comment

begin_comment
comment|// Authors: Illya Rudkin 11/03/2014.
end_comment

begin_comment
comment|// Changes: None.
end_comment

begin_comment
comment|//--
end_comment

begin_decl_stmt
name|class
name|CMICmdCmdBreakDelete
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
name|CMICmdCmdBreakDelete
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
name|CMICmdCmdBreakDelete
argument_list|(
name|void
argument_list|)
block|;
comment|// Attributes:
name|private
operator|:
specifier|const
name|CMIUtilString
name|m_constStrArgNamedBrkPt
block|;
specifier|const
name|CMIUtilString
name|m_constStrArgNamedThreadGrp
block|;
comment|// Not specified in MI spec but Eclipse gives this option
block|}
decl_stmt|;
end_decl_stmt

begin_comment
comment|//++ ============================================================================
end_comment

begin_comment
comment|// Details: MI command class. MI commands derived from the command base class.
end_comment

begin_comment
comment|//          *this class implements MI command "break-disable".
end_comment

begin_comment
comment|// Gotchas: None.
end_comment

begin_comment
comment|// Authors: Illya Rudkin 19/05/2014.
end_comment

begin_comment
comment|// Changes: None.
end_comment

begin_comment
comment|//--
end_comment

begin_decl_stmt
name|class
name|CMICmdCmdBreakDisable
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
name|CMICmdCmdBreakDisable
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
name|CMICmdCmdBreakDisable
argument_list|(
name|void
argument_list|)
block|;
comment|// Attributes:
name|private
operator|:
specifier|const
name|CMIUtilString
name|m_constStrArgNamedThreadGrp
block|;
comment|// Not specified in MI spec but Eclipse gives this option
specifier|const
name|CMIUtilString
name|m_constStrArgNamedBrkPt
block|;
name|bool
name|m_bBrkPtDisabledOk
block|;
name|MIuint
name|m_nBrkPtId
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
comment|//          *this class implements MI command "break-enable".
end_comment

begin_comment
comment|// Gotchas: None.
end_comment

begin_comment
comment|// Authors: Illya Rudkin 19/05/2014.
end_comment

begin_comment
comment|// Changes: None.
end_comment

begin_comment
comment|//--
end_comment

begin_decl_stmt
name|class
name|CMICmdCmdBreakEnable
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
name|CMICmdCmdBreakEnable
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
name|CMICmdCmdBreakEnable
argument_list|(
name|void
argument_list|)
block|;
comment|// Attributes:
name|private
operator|:
specifier|const
name|CMIUtilString
name|m_constStrArgNamedThreadGrp
block|;
comment|// Not specified in MI spec but Eclipse gives this option
specifier|const
name|CMIUtilString
name|m_constStrArgNamedBrkPt
block|;
name|bool
name|m_bBrkPtEnabledOk
block|;
name|MIuint
name|m_nBrkPtId
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
comment|//          *this class implements MI command "break-after".
end_comment

begin_comment
comment|// Gotchas: None.
end_comment

begin_comment
comment|// Authors: Illya Rudkin 29/05/2014.
end_comment

begin_comment
comment|// Changes: None.
end_comment

begin_comment
comment|//--
end_comment

begin_decl_stmt
name|class
name|CMICmdCmdBreakAfter
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
name|CMICmdCmdBreakAfter
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
name|CMICmdCmdBreakAfter
argument_list|(
name|void
argument_list|)
block|;
comment|// Attributes:
name|private
operator|:
specifier|const
name|CMIUtilString
name|m_constStrArgNamedThreadGrp
block|;
comment|// Not specified in MI spec but Eclipse gives this option
specifier|const
name|CMIUtilString
name|m_constStrArgNamedNumber
block|;
specifier|const
name|CMIUtilString
name|m_constStrArgNamedCount
block|;
name|MIuint
name|m_nBrkPtId
block|;
name|MIuint
name|m_nBrkPtCount
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
comment|//          *this class implements MI command "break-condition".
end_comment

begin_comment
comment|// Gotchas: None.
end_comment

begin_comment
comment|// Authors: Illya Rudkin 29/05/2014.
end_comment

begin_comment
comment|// Changes: None.
end_comment

begin_comment
comment|//--
end_comment

begin_decl_stmt
name|class
name|CMICmdCmdBreakCondition
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
name|CMICmdCmdBreakCondition
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
name|CMICmdCmdBreakCondition
argument_list|(
name|void
argument_list|)
block|;
comment|// Methods:
name|private
operator|:
name|CMIUtilString
name|GetRestOfExpressionNotSurroundedInQuotes
argument_list|(
name|void
argument_list|)
block|;
comment|// Attributes:
name|private
operator|:
specifier|const
name|CMIUtilString
name|m_constStrArgNamedThreadGrp
block|;
comment|// Not specified in MI spec but Eclipse gives this option
specifier|const
name|CMIUtilString
name|m_constStrArgNamedNumber
block|;
specifier|const
name|CMIUtilString
name|m_constStrArgNamedExpr
block|;
specifier|const
name|CMIUtilString
name|m_constStrArgNamedExprNoQuotes
block|;
comment|// Not specified in MI spec, we need to handle expressions not surrounded by quotes
name|MIuint
name|m_nBrkPtId
block|;
name|CMIUtilString
name|m_strBrkPtExpr
block|; }
decl_stmt|;
end_decl_stmt

end_unit

