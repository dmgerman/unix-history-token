begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- MICmdCmdData.h ------------------------------------------*- C++ -*-===//
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
comment|// Overview:    CMICmdCmdDataEvaluateExpression     interface.
end_comment

begin_comment
comment|//              CMICmdCmdDataDisassemble            interface.
end_comment

begin_comment
comment|//              CMICmdCmdDataReadMemoryBytes        interface.
end_comment

begin_comment
comment|//              CMICmdCmdDataReadMemory             interface.
end_comment

begin_comment
comment|//              CMICmdCmdDataListRegisterNames      interface.
end_comment

begin_comment
comment|//              CMICmdCmdDataListRegisterValues     interface.
end_comment

begin_comment
comment|//              CMICmdCmdDataListRegisterChanged    interface.
end_comment

begin_comment
comment|//              CMICmdCmdDataWriteMemoryBytes       interface.
end_comment

begin_comment
comment|//              CMICmdCmdDataWriteMemory            interface.
end_comment

begin_comment
comment|//              CMICmdCmdDataInfoLine               interface.
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

begin_comment
comment|//
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

begin_include
include|#
directive|include
file|"lldb/API/SBError.h"
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
file|"MICmnLLDBDebugSessionInfoVarObj.h"
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
comment|//++
end_comment

begin_comment
comment|//============================================================================
end_comment

begin_comment
comment|// Details: MI command class. MI commands derived from the command base class.
end_comment

begin_comment
comment|//          *this class implements MI command "data-evaluate-expression".
end_comment

begin_comment
comment|//--
end_comment

begin_decl_stmt
name|class
name|CMICmdCmdDataEvaluateExpression
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
name|CMICmdCmdDataEvaluateExpression
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
name|CMICmdCmdDataEvaluateExpression
argument_list|()
name|override
block|;
comment|// Methods:
name|private
operator|:
name|bool
name|HaveInvalidCharacterInExpression
argument_list|(
specifier|const
name|CMIUtilString
operator|&
name|vrExpr
argument_list|,
name|char
operator|&
name|vrwInvalidChar
argument_list|)
block|;
comment|// Attributes:
name|private
operator|:
name|bool
name|m_bExpressionValid
block|;
comment|// True = yes is valid, false = not valid
name|bool
name|m_bEvaluatedExpression
block|;
comment|// True = yes is expression evaluated, false =
comment|// failed
name|lldb
operator|::
name|SBError
name|m_Error
block|;
comment|// Status object, which is examined when
comment|// m_bEvaluatedExpression is false
name|CMIUtilString
name|m_strValue
block|;
name|CMICmnMIValueTuple
name|m_miValueTuple
block|;
name|bool
name|m_bFoundInvalidChar
block|;
comment|// True = yes found unexpected character in the
comment|// expression, false = all ok
name|char
name|m_cExpressionInvalidChar
block|;
specifier|const
name|CMIUtilString
name|m_constStrArgExpr
block|; }
decl_stmt|;
end_decl_stmt

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
comment|//          *this class implements MI command "data-disassemble".
end_comment

begin_comment
comment|//--
end_comment

begin_decl_stmt
name|class
name|CMICmdCmdDataDisassemble
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
name|CMICmdCmdDataDisassemble
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
name|CMICmdCmdDataDisassemble
argument_list|()
name|override
block|;
comment|// Attributes:
name|private
operator|:
specifier|const
name|CMIUtilString
name|m_constStrArgAddrStart
block|;
comment|// MI spec non mandatory, *this command mandatory
specifier|const
name|CMIUtilString
name|m_constStrArgAddrEnd
block|;
comment|// MI spec non mandatory, *this command mandatory
specifier|const
name|CMIUtilString
name|m_constStrArgMode
block|;
name|CMICmnMIValueList
name|m_miValueList
block|; }
decl_stmt|;
end_decl_stmt

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
comment|//          *this class implements MI command "data-read-memory-bytes".
end_comment

begin_comment
comment|//--
end_comment

begin_decl_stmt
name|class
name|CMICmdCmdDataReadMemoryBytes
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
name|CMICmdCmdDataReadMemoryBytes
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
name|CMICmdCmdDataReadMemoryBytes
argument_list|()
name|override
block|;
comment|// Attributes:
name|private
operator|:
specifier|const
name|CMIUtilString
name|m_constStrArgByteOffset
block|;
specifier|const
name|CMIUtilString
name|m_constStrArgAddrExpr
block|;
specifier|const
name|CMIUtilString
name|m_constStrArgNumBytes
block|;
name|unsigned
name|char
operator|*
name|m_pBufferMemory
block|;
name|MIuint64
name|m_nAddrStart
block|;
name|MIuint64
name|m_nAddrNumBytesToRead
block|; }
decl_stmt|;
end_decl_stmt

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
comment|//          *this class implements MI command "data-read-memory".
end_comment

begin_comment
comment|//--
end_comment

begin_decl_stmt
name|class
name|CMICmdCmdDataReadMemory
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
name|CMICmdCmdDataReadMemory
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
comment|// From CMICmnBase
comment|/* dtor */
operator|~
name|CMICmdCmdDataReadMemory
argument_list|()
name|override
block|; }
decl_stmt|;
end_decl_stmt

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
comment|//          *this class implements MI command "data-list-register-names".
end_comment

begin_comment
comment|//--
end_comment

begin_decl_stmt
name|class
name|CMICmdCmdDataListRegisterNames
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
name|CMICmdCmdDataListRegisterNames
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
name|CMICmdCmdDataListRegisterNames
argument_list|()
name|override
block|;
comment|// Methods:
name|private
operator|:
name|lldb
operator|::
name|SBValue
name|GetRegister
argument_list|(
argument|const MIuint vRegisterIndex
argument_list|)
specifier|const
block|;
comment|// Attributes:
name|private
operator|:
specifier|const
name|CMIUtilString
name|m_constStrArgRegNo
block|;
comment|// Not handled by *this command
name|CMICmnMIValueList
name|m_miValueList
block|; }
decl_stmt|;
end_decl_stmt

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
comment|//          *this class implements MI command "data-list-register-values".
end_comment

begin_comment
comment|//--
end_comment

begin_decl_stmt
name|class
name|CMICmdCmdDataListRegisterValues
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
name|CMICmdCmdDataListRegisterValues
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
name|CMICmdCmdDataListRegisterValues
argument_list|()
name|override
block|;
comment|// Methods:
name|private
operator|:
name|lldb
operator|::
name|SBValue
name|GetRegister
argument_list|(
argument|const MIuint vRegisterIndex
argument_list|)
specifier|const
block|;
name|void
name|AddToOutput
argument_list|(
argument|const MIuint vnIndex
argument_list|,
argument|const lldb::SBValue&vrValue
argument_list|,
argument|CMICmnLLDBDebugSessionInfoVarObj::varFormat_e veVarFormat
argument_list|)
block|;
comment|// Attributes:
name|private
operator|:
specifier|const
name|CMIUtilString
name|m_constStrArgSkip
block|;
comment|// Not handled by *this command
specifier|const
name|CMIUtilString
name|m_constStrArgFormat
block|;
specifier|const
name|CMIUtilString
name|m_constStrArgRegNo
block|;
name|CMICmnMIValueList
name|m_miValueList
block|; }
decl_stmt|;
end_decl_stmt

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
comment|//          *this class implements MI command "data-list-changed-registers".
end_comment

begin_comment
comment|//--
end_comment

begin_decl_stmt
name|class
name|CMICmdCmdDataListRegisterChanged
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
name|CMICmdCmdDataListRegisterChanged
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
comment|// From CMICmnBase
comment|/* dtor */
operator|~
name|CMICmdCmdDataListRegisterChanged
argument_list|()
name|override
block|; }
decl_stmt|;
end_decl_stmt

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
comment|//          *this class implements MI command "data-read-memory-bytes".
end_comment

begin_comment
comment|//--
end_comment

begin_decl_stmt
name|class
name|CMICmdCmdDataWriteMemoryBytes
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
name|CMICmdCmdDataWriteMemoryBytes
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
name|CMICmdCmdDataWriteMemoryBytes
argument_list|()
name|override
block|;
comment|// Attributes:
name|private
operator|:
specifier|const
name|CMIUtilString
name|m_constStrArgAddr
block|;
specifier|const
name|CMIUtilString
name|m_constStrArgContents
block|;
specifier|const
name|CMIUtilString
name|m_constStrArgCount
block|;
name|CMIUtilString
name|m_strContents
block|; }
decl_stmt|;
end_decl_stmt

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
comment|//          *this class implements MI command "data-read-memory".
end_comment

begin_comment
comment|//          Not specified in MI spec but Eclipse gives *this command.
end_comment

begin_comment
comment|//--
end_comment

begin_decl_stmt
name|class
name|CMICmdCmdDataWriteMemory
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
name|CMICmdCmdDataWriteMemory
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
name|CMICmdCmdDataWriteMemory
argument_list|()
name|override
block|;
comment|// Attributes:
name|private
operator|:
specifier|const
name|CMIUtilString
name|m_constStrArgOffset
block|;
comment|// Not specified in MI spec but
comment|// Eclipse gives this option.
specifier|const
name|CMIUtilString
name|m_constStrArgAddr
block|;
comment|// Not specified in MI spec but Eclipse
comment|// gives this option.
specifier|const
name|CMIUtilString
name|m_constStrArgD
block|;
comment|// Not specified in MI spec but Eclipse gives this option.
specifier|const
name|CMIUtilString
name|m_constStrArgNumber
block|;
comment|// Not specified in MI spec but
comment|// Eclipse gives this option.
specifier|const
name|CMIUtilString
name|m_constStrArgContents
block|;
comment|// Not specified in MI spec but
comment|// Eclipse gives this option.
name|MIuint64
name|m_nAddr
block|;
name|CMIUtilString
name|m_strContents
block|;
name|MIuint64
name|m_nCount
block|;
name|unsigned
name|char
operator|*
name|m_pBufferMemory
block|; }
decl_stmt|;
end_decl_stmt

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
comment|//          *this class implements MI command "data-info-line".
end_comment

begin_comment
comment|//          See MIExtensions.txt for details.
end_comment

begin_comment
comment|//--
end_comment

begin_decl_stmt
name|class
name|CMICmdCmdDataInfoLine
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
name|CMICmdCmdDataInfoLine
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
name|CMICmdCmdDataInfoLine
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
name|m_constStrArgLocation
block|; }
decl_stmt|;
end_decl_stmt

end_unit

