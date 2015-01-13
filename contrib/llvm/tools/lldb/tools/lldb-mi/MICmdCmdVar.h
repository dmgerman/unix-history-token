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
comment|//++
end_comment

begin_comment
comment|// File:		MICmdCmdVar.h
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// Overview:	CMICmdCmdVarCreate				interface.
end_comment

begin_comment
comment|//				CMICmdCmdVarUpdate				interface.
end_comment

begin_comment
comment|//				CMICmdCmdVarDelete				interface.
end_comment

begin_comment
comment|//				CMICmdCmdVarAssign				interface.
end_comment

begin_comment
comment|//				CMICmdCmdVarSetFormat			interface.
end_comment

begin_comment
comment|//				CMICmdCmdVarListChildren		interface.
end_comment

begin_comment
comment|//				CMICmdCmdVarEvaluateExpression	interface.
end_comment

begin_comment
comment|//				CMICmdCmdVarInfoPathExpression	interface.
end_comment

begin_comment
comment|//				CMICmdCmdVarShowAttributes		interface.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//				To implement new MI commands derive a new command class from the command base
end_comment

begin_comment
comment|//				class. To enable the new command for interpretation add the new command class
end_comment

begin_comment
comment|//				to the command factory. The files of relevance are:
end_comment

begin_comment
comment|//					MICmdCommands.cpp
end_comment

begin_comment
comment|//					MICmdBase.h / .cpp
end_comment

begin_comment
comment|//					MICmdCmd.h / .cpp
end_comment

begin_comment
comment|//				For an introduction to adding a new command see CMICmdCmdSupportInfoMiCmdQuery
end_comment

begin_comment
comment|//				command class as an example.
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
comment|// Details:	MI command class. MI commands derived from the command base class.
end_comment

begin_comment
comment|//			*this class implements MI command "var-create".
end_comment

begin_comment
comment|// Gotchas:	None.
end_comment

begin_comment
comment|// Authors:	Illya Rudkin 24/03/2014.
end_comment

begin_comment
comment|// Changes:	None.
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
argument_list|(
name|void
argument_list|)
block|;
comment|// Methods:
name|public
operator|:
comment|/* ctor */
name|CMICmdCmdVarCreate
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
name|CMICmdCmdVarCreate
argument_list|(
name|void
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
name|MIuint
name|m_nMore
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
name|m_constStrArgThread
block|;
comment|// Not specified in MI spec but Eclipse gives this option
specifier|const
name|CMIUtilString
name|m_constStrArgThreadGroup
block|;
comment|// Not specified in MI spec but Eclipse gives this option
specifier|const
name|CMIUtilString
name|m_constStrArgFrame
block|;
comment|// Not specified in MI spec but Eclipse gives this option
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
block|;	 }
decl_stmt|;
end_decl_stmt

begin_comment
comment|//++ ============================================================================
end_comment

begin_comment
comment|// Details:	MI command class. MI commands derived from the command base class.
end_comment

begin_comment
comment|//			*this class implements MI command "var-update".
end_comment

begin_comment
comment|// Gotchas:	None.
end_comment

begin_comment
comment|// Authors:	Illya Rudkin 25/03/2014.
end_comment

begin_comment
comment|// Changes:	None.
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
argument_list|(
name|void
argument_list|)
block|;
comment|// Methods:
name|public
operator|:
comment|/* ctor */
name|CMICmdCmdVarUpdate
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
comment|// Overridden:
name|public
operator|:
comment|// From CMICmnBase
comment|/* dtor */
name|virtual
operator|~
name|CMICmdCmdVarUpdate
argument_list|(
name|void
argument_list|)
block|;
comment|// Methods:
name|private
operator|:
name|bool
name|ExamineSBValueForChange
argument_list|(
argument|const CMICmnLLDBDebugSessionInfoVarObj& vrVarObj
argument_list|,
argument|const bool vbIgnoreVarType
argument_list|,
argument|bool& vrwbChanged
argument_list|)
block|;
name|bool
name|MIFormResponse
argument_list|(
specifier|const
name|CMIUtilString
operator|&
name|vrStrVarName
argument_list|,
specifier|const
name|CMIUtilString
operator|&
name|vrStrValue
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
name|CMIUtilString
name|m_strValueName
block|;
specifier|const
name|CMIUtilString
name|m_constStrArgPrintValues
block|;
comment|// Not handled by *this command
specifier|const
name|CMIUtilString
name|m_constStrArgName
block|;
name|bool
name|m_bValueChangedArrayType
block|;
comment|// True = yes value changed, false = no change
name|bool
name|m_bValueChangedCompositeType
block|;
comment|// True = yes value changed, false = no change
name|bool
name|m_bValueChangedNormalType
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
comment|// Details:	MI command class. MI commands derived from the command base class.
end_comment

begin_comment
comment|//			*this class implements MI command "var-delete".
end_comment

begin_comment
comment|// Gotchas:	None.
end_comment

begin_comment
comment|// Authors:	Illya Rudkin 25/03/2014.
end_comment

begin_comment
comment|// Changes:	None.
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
argument_list|(
name|void
argument_list|)
block|;
comment|// Methods:
name|public
operator|:
comment|/* ctor */
name|CMICmdCmdVarDelete
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
name|CMICmdCmdVarDelete
argument_list|(
name|void
argument_list|)
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
comment|// Details:	MI command class. MI commands derived from the command base class.
end_comment

begin_comment
comment|//			*this class implements MI command "var-assign".
end_comment

begin_comment
comment|// Gotchas:	None.
end_comment

begin_comment
comment|// Authors:	Illya Rudkin 25/03/2014.
end_comment

begin_comment
comment|// Changes:	None.
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
argument_list|(
name|void
argument_list|)
block|;
comment|// Methods:
name|public
operator|:
comment|/* ctor */
name|CMICmdCmdVarAssign
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
name|CMICmdCmdVarAssign
argument_list|(
name|void
argument_list|)
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
block|;	 }
decl_stmt|;
end_decl_stmt

begin_comment
comment|//++ ============================================================================
end_comment

begin_comment
comment|// Details:	MI command class. MI commands derived from the command base class.
end_comment

begin_comment
comment|//			*this class implements MI command "var-set-format".
end_comment

begin_comment
comment|// Gotchas:	None.
end_comment

begin_comment
comment|// Authors:	Illya Rudkin 26/03/2014.
end_comment

begin_comment
comment|// Changes:	None.
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
argument_list|(
name|void
argument_list|)
block|;
comment|// Methods:
name|public
operator|:
comment|/* ctor */
name|CMICmdCmdVarSetFormat
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
name|CMICmdCmdVarSetFormat
argument_list|(
name|void
argument_list|)
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
block|;	 }
decl_stmt|;
end_decl_stmt

begin_comment
comment|//++ ============================================================================
end_comment

begin_comment
comment|// Details:	MI command class. MI commands derived from the command base class.
end_comment

begin_comment
comment|//			*this class implements MI command "var-list-children".
end_comment

begin_comment
comment|// Gotchas:	None.
end_comment

begin_comment
comment|// Authors:	Illya Rudkin 26/03/2014.
end_comment

begin_comment
comment|// Changes:	None.
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
argument_list|(
name|void
argument_list|)
block|;
comment|// Methods:
name|public
operator|:
comment|/* ctor */
name|CMICmdCmdVarListChildren
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
name|CMICmdCmdVarListChildren
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
name|CMICmnMIValueResult
operator|>
name|VecMIValueResult_t
expr_stmt|;
comment|// Attributes:
name|private
operator|:
name|bool
name|m_bValueValid
decl_stmt|;
end_decl_stmt

begin_comment
comment|// True = yes SBValue object is valid, false = not valid
end_comment

begin_decl_stmt
name|VecMIValueResult_t
name|m_vecMiValueResult
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|MIuint
name|m_nChildren
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|const
name|CMIUtilString
name|m_constStrArgPrintValues
decl_stmt|;
end_decl_stmt

begin_comment
comment|// Not handled by *this command
end_comment

begin_decl_stmt
specifier|const
name|CMIUtilString
name|m_constStrArgName
decl_stmt|;
end_decl_stmt

begin_comment
unit|};
comment|//++ ============================================================================
end_comment

begin_comment
comment|// Details:	MI command class. MI commands derived from the command base class.
end_comment

begin_comment
comment|//			*this class implements MI command "var-evaluate-expression".
end_comment

begin_comment
comment|// Gotchas:	None.
end_comment

begin_comment
comment|// Authors:	Illya Rudkin 26/03/2014.
end_comment

begin_comment
comment|// Changes:	None.
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
argument_list|(
name|void
argument_list|)
block|;
comment|// Methods:
name|public
operator|:
comment|/* ctor */
name|CMICmdCmdVarEvaluateExpression
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
name|CMICmdCmdVarEvaluateExpression
argument_list|(
name|void
argument_list|)
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
comment|// Details:	MI command class. MI commands derived from the command base class.
end_comment

begin_comment
comment|//			*this class implements MI command "var-info-path-expression".
end_comment

begin_comment
comment|// Gotchas:	None.
end_comment

begin_comment
comment|// Authors:	Illya Rudkin 26/03/2014.
end_comment

begin_comment
comment|// Changes:	None.
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
argument_list|(
name|void
argument_list|)
block|;
comment|// Methods:
name|public
operator|:
comment|/* ctor */
name|CMICmdCmdVarInfoPathExpression
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
name|CMICmdCmdVarInfoPathExpression
argument_list|(
name|void
argument_list|)
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
comment|// Details:	MI command class. MI commands derived from the command base class.
end_comment

begin_comment
comment|//			*this class implements MI command "var-show-attributes".
end_comment

begin_comment
comment|// Gotchas:	None.
end_comment

begin_comment
comment|// Authors:	Illya Rudkin 19/05/2014.
end_comment

begin_comment
comment|// Changes:	None.
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
argument_list|(
name|void
argument_list|)
block|;
comment|// Methods:
name|public
operator|:
comment|/* ctor */
name|CMICmdCmdVarShowAttributes
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
name|CMICmdCmdVarShowAttributes
argument_list|(
name|void
argument_list|)
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

