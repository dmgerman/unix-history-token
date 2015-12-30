begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- MICmdCmdVar.h -------------------------------------------*- C++ -*-===//
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
comment|// Overview:    CMICmdCmdVarCreate              interface.
end_comment

begin_comment
comment|//              CMICmdCmdVarUpdate              interface.
end_comment

begin_comment
comment|//              CMICmdCmdVarDelete              interface.
end_comment

begin_comment
comment|//              CMICmdCmdVarAssign              interface.
end_comment

begin_comment
comment|//              CMICmdCmdVarSetFormat           interface.
end_comment

begin_comment
comment|//              CMICmdCmdVarListChildren        interface.
end_comment

begin_comment
comment|//              CMICmdCmdVarEvaluateExpression  interface.
end_comment

begin_comment
comment|//              CMICmdCmdVarInfoPathExpression  interface.
end_comment

begin_comment
comment|//              CMICmdCmdVarShowAttributes      interface.
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
file|"MICmnMIValueTuple.h"
end_include

begin_include
include|#
directive|include
file|"MICmnMIValueList.h"
end_include

begin_include
include|#
directive|include
file|"MICmnLLDBDebugSessionInfo.h"
end_include

begin_include
include|#
directive|include
file|"MICmnLLDBDebugSessionInfoVarObj.h"
end_include

begin_comment
comment|// Declarations:
end_comment

begin_decl_stmt
name|class
name|CMICmnLLDBDebugSessionInfoVarObj
decl_stmt|;
end_decl_stmt

begin_comment
comment|//++ ============================================================================
end_comment

begin_comment
comment|// Details: MI command class. MI commands derived from the command base class.
end_comment

begin_comment
comment|//          *this class implements MI command "var-create".
end_comment

begin_comment
comment|//--
end_comment

begin_decl_stmt
name|class
name|CMICmdCmdVarCreate
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
name|CMICmdCmdVarCreate
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
comment|// Overridden:
name|public
operator|:
comment|// From CMICmnBase
comment|/* dtor */
operator|~
name|CMICmdCmdVarCreate
argument_list|()
name|override
block|;
comment|// Methods:
name|private
operator|:
name|void
name|CompleteSBValue
argument_list|(
name|lldb
operator|::
name|SBValue
operator|&
name|vrwValue
argument_list|)
block|;
comment|// Attribute:
name|private
operator|:
name|CMIUtilString
name|m_strVarName
block|;
name|MIuint
name|m_nChildren
block|;
name|MIuint64
name|m_nThreadId
block|;
name|CMIUtilString
name|m_strType
block|;
name|bool
name|m_bValid
block|;
comment|// True = Variable is valid, false = not valid
name|CMIUtilString
name|m_strExpression
block|;
name|CMIUtilString
name|m_strValue
block|;
specifier|const
name|CMIUtilString
name|m_constStrArgName
block|;
specifier|const
name|CMIUtilString
name|m_constStrArgFrameAddr
block|;
specifier|const
name|CMIUtilString
name|m_constStrArgExpression
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
comment|//          *this class implements MI command "var-update".
end_comment

begin_comment
comment|//--
end_comment

begin_decl_stmt
name|class
name|CMICmdCmdVarUpdate
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
name|CMICmdCmdVarUpdate
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
comment|// Overridden:
name|public
operator|:
comment|// From CMICmnBase
comment|/* dtor */
operator|~
name|CMICmdCmdVarUpdate
argument_list|()
name|override
block|;
comment|// Methods:
name|private
operator|:
name|bool
name|ExamineSBValueForChange
argument_list|(
name|lldb
operator|::
name|SBValue
operator|&
name|vrwValue
argument_list|,
name|bool
operator|&
name|vrwbChanged
argument_list|)
block|;
name|void
name|MIFormResponse
argument_list|(
specifier|const
name|CMIUtilString
operator|&
name|vrStrVarName
argument_list|,
specifier|const
name|char
operator|*
specifier|const
name|vpValue
argument_list|,
specifier|const
name|CMIUtilString
operator|&
name|vrStrScope
argument_list|)
block|;
comment|// Attribute:
name|private
operator|:
specifier|const
name|CMIUtilString
name|m_constStrArgPrintValues
block|;
specifier|const
name|CMIUtilString
name|m_constStrArgName
block|;
name|bool
name|m_bValueChanged
block|;
comment|// True = yes value changed, false = no change
name|CMICmnMIValueList
name|m_miValueList
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
comment|//          *this class implements MI command "var-delete".
end_comment

begin_comment
comment|//--
end_comment

begin_decl_stmt
name|class
name|CMICmdCmdVarDelete
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
name|CMICmdCmdVarDelete
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
name|CMICmdCmdVarDelete
argument_list|()
name|override
block|;
comment|// Attribute:
name|private
operator|:
specifier|const
name|CMIUtilString
name|m_constStrArgName
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
comment|//          *this class implements MI command "var-assign".
end_comment

begin_comment
comment|//--
end_comment

begin_decl_stmt
name|class
name|CMICmdCmdVarAssign
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
name|CMICmdCmdVarAssign
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
name|CMICmdCmdVarAssign
argument_list|()
name|override
block|;
comment|// Attributes:
name|private
operator|:
name|bool
name|m_bOk
block|;
comment|// True = success, false = failure
name|CMIUtilString
name|m_varObjName
block|;
specifier|const
name|CMIUtilString
name|m_constStrArgName
block|;
specifier|const
name|CMIUtilString
name|m_constStrArgExpression
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
comment|//          *this class implements MI command "var-set-format".
end_comment

begin_comment
comment|//--
end_comment

begin_decl_stmt
name|class
name|CMICmdCmdVarSetFormat
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
name|CMICmdCmdVarSetFormat
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
name|CMICmdCmdVarSetFormat
argument_list|()
name|override
block|;
comment|// Attributes:
name|private
operator|:
name|CMIUtilString
name|m_varObjName
block|;
specifier|const
name|CMIUtilString
name|m_constStrArgName
block|;
specifier|const
name|CMIUtilString
name|m_constStrArgFormatSpec
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
comment|//          *this class implements MI command "var-list-children".
end_comment

begin_comment
comment|//--
end_comment

begin_decl_stmt
name|class
name|CMICmdCmdVarListChildren
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
name|CMICmdCmdVarListChildren
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
name|CMICmdCmdVarListChildren
argument_list|()
name|override
block|;
comment|// Attributes:
name|private
operator|:
specifier|const
name|CMIUtilString
name|m_constStrArgPrintValues
block|;
specifier|const
name|CMIUtilString
name|m_constStrArgName
block|;
specifier|const
name|CMIUtilString
name|m_constStrArgFrom
block|;
specifier|const
name|CMIUtilString
name|m_constStrArgTo
block|;
name|bool
name|m_bValueValid
block|;
comment|// True = yes SBValue object is valid, false = not valid
name|MIuint
name|m_nChildren
block|;
name|CMICmnMIValueList
name|m_miValueList
block|;
name|bool
name|m_bHasMore
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
comment|//          *this class implements MI command "var-evaluate-expression".
end_comment

begin_comment
comment|//--
end_comment

begin_decl_stmt
name|class
name|CMICmdCmdVarEvaluateExpression
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
name|CMICmdCmdVarEvaluateExpression
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
name|CMICmdCmdVarEvaluateExpression
argument_list|()
name|override
block|;
comment|// Attributes:
name|private
operator|:
name|bool
name|m_bValueValid
block|;
comment|// True = yes SBValue object is valid, false = not valid
name|CMIUtilString
name|m_varObjName
block|;
specifier|const
name|CMIUtilString
name|m_constStrArgFormatSpec
block|;
comment|// Not handled by *this command
specifier|const
name|CMIUtilString
name|m_constStrArgName
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
comment|//          *this class implements MI command "var-info-path-expression".
end_comment

begin_comment
comment|//--
end_comment

begin_decl_stmt
name|class
name|CMICmdCmdVarInfoPathExpression
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
name|CMICmdCmdVarInfoPathExpression
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
name|CMICmdCmdVarInfoPathExpression
argument_list|()
name|override
block|;
comment|// Attributes:
name|private
operator|:
name|bool
name|m_bValueValid
block|;
comment|// True = yes SBValue object is valid, false = not valid
name|CMIUtilString
name|m_strPathExpression
block|;
specifier|const
name|CMIUtilString
name|m_constStrArgName
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
comment|//          *this class implements MI command "var-show-attributes".
end_comment

begin_comment
comment|//--
end_comment

begin_decl_stmt
name|class
name|CMICmdCmdVarShowAttributes
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
name|CMICmdCmdVarShowAttributes
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
name|CMICmdCmdVarShowAttributes
argument_list|()
name|override
block|;
comment|// Attributes:
name|private
operator|:
specifier|const
name|CMIUtilString
name|m_constStrArgName
block|; }
decl_stmt|;
end_decl_stmt

end_unit

