begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- MICmdCmdStack.h -----------------------------------------*- C++ -*-===//
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
comment|// Overview:    CMICmdCmdStackInfoDepth         interface.
end_comment

begin_comment
comment|//              CMICmdCmdStackInfoFrame         interface.
end_comment

begin_comment
comment|//              CMICmdCmdStackListFrames        interface.
end_comment

begin_comment
comment|//              CMICmdCmdStackListArguments     interface.
end_comment

begin_comment
comment|//              CMICmdCmdStackListLocals        interface.
end_comment

begin_comment
comment|//              CMICmdCmdStackSelectFrame       interface.
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

begin_include
include|#
directive|include
file|"MICmnMIValueList.h"
end_include

begin_include
include|#
directive|include
file|"MICmnMIValueTuple.h"
end_include

begin_comment
comment|//++ ============================================================================
end_comment

begin_comment
comment|// Details: MI command class. MI commands derived from the command base class.
end_comment

begin_comment
comment|//          *this class implements MI command "stack-info-depth".
end_comment

begin_comment
comment|//--
end_comment

begin_decl_stmt
name|class
name|CMICmdCmdStackInfoDepth
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
name|CMICmdCmdStackInfoDepth
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
name|CMICmdCmdStackInfoDepth
argument_list|()
name|override
block|;
comment|// Attributes:
name|private
operator|:
name|MIuint
name|m_nThreadFrames
block|;
specifier|const
name|CMIUtilString
name|m_constStrArgMaxDepth
block|;
comment|// Not handled by *this command
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
comment|//          *this class implements MI command "stack-info-frame".
end_comment

begin_comment
comment|//--
end_comment

begin_decl_stmt
name|class
name|CMICmdCmdStackInfoFrame
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
name|CMICmdCmdStackInfoFrame
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
name|CMICmdCmdStackInfoFrame
argument_list|()
name|override
block|;
comment|// Attributes:
name|private
operator|:
name|CMICmnMIValueTuple
name|m_miValueTuple
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
comment|//          *this class implements MI command "stack-list-frames".
end_comment

begin_comment
comment|//--
end_comment

begin_decl_stmt
name|class
name|CMICmdCmdStackListFrames
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
name|CMICmdCmdStackListFrames
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
name|CMICmdCmdStackListFrames
argument_list|()
name|override
block|;
comment|// Typedefs:
name|private
operator|:
typedef|typedef
name|std
operator|::
name|vector
operator|<
name|CMICmnMIValueResult
operator|>
name|VecMIValueResult_t
expr_stmt|;
comment|// Attributes:
name|private
operator|:
name|MIuint
name|m_nThreadFrames
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|VecMIValueResult_t
name|m_vecMIValueResult
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|const
name|CMIUtilString
name|m_constStrArgFrameLow
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|const
name|CMIUtilString
name|m_constStrArgFrameHigh
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
comment|//          *this class implements MI command "stack-list-arguments".
end_comment

begin_comment
comment|//--
end_comment

begin_decl_stmt
name|class
name|CMICmdCmdStackListArguments
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
name|CMICmdCmdStackListArguments
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
name|CMICmdCmdStackListArguments
argument_list|()
name|override
block|;
comment|// Attributes:
name|private
operator|:
name|bool
name|m_bThreadInvalid
block|;
comment|// True = yes invalid thread, false = thread object valid
name|CMICmnMIValueList
name|m_miValueList
block|;
specifier|const
name|CMIUtilString
name|m_constStrArgPrintValues
block|;
specifier|const
name|CMIUtilString
name|m_constStrArgFrameLow
block|;
specifier|const
name|CMIUtilString
name|m_constStrArgFrameHigh
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
comment|//          *this class implements MI command "stack-list-locals".
end_comment

begin_comment
comment|//--
end_comment

begin_decl_stmt
name|class
name|CMICmdCmdStackListLocals
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
name|CMICmdCmdStackListLocals
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
name|CMICmdCmdStackListLocals
argument_list|()
name|override
block|;
comment|// Attributes:
name|private
operator|:
name|bool
name|m_bThreadInvalid
block|;
comment|// True = yes invalid thread, false = thread object valid
name|CMICmnMIValueList
name|m_miValueList
block|;
specifier|const
name|CMIUtilString
name|m_constStrArgPrintValues
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
comment|//          *this class implements MI command "stack-list-variables".
end_comment

begin_comment
comment|//--
end_comment

begin_decl_stmt
name|class
name|CMICmdCmdStackListVariables
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
name|CMICmdCmdStackListVariables
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
name|CMICmdCmdStackListVariables
argument_list|()
name|override
block|;
comment|// Attributes
name|private
operator|:
name|bool
name|m_bThreadInvalid
block|;
comment|// True = yes invalid thread, false = thread object valid
name|CMICmnMIValueList
name|m_miValueList
block|;
specifier|const
name|CMIUtilString
name|m_constStrArgPrintValues
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
comment|//          *this class implements MI command "stack-select-frame".
end_comment

begin_comment
comment|//--
end_comment

begin_decl_stmt
name|class
name|CMICmdCmdStackSelectFrame
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
name|CMICmdCmdStackSelectFrame
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
name|CMICmdCmdStackSelectFrame
argument_list|()
name|override
block|;
comment|// Attributes:
name|private
operator|:
name|bool
name|m_bFrameInvalid
block|;
comment|// True = yes invalid frame, false = ok
specifier|const
name|CMIUtilString
name|m_constStrArgFrameId
block|; }
decl_stmt|;
end_decl_stmt

end_unit

