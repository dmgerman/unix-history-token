begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- MICmnLLDBDebugSessionInfo.h -----------------------------*- C++ -*-===//
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
comment|// File:		MICmnLLDBDebugSessionInfo.h
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// Overview:	CMICmnLLDBDebugSessionInfo interface.
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
comment|// Third party headers:
end_comment

begin_include
include|#
directive|include
file|<map>
end_include

begin_include
include|#
directive|include
file|<vector>
end_include

begin_include
include|#
directive|include
file|<lldb/API/SBDebugger.h>
end_include

begin_include
include|#
directive|include
file|<lldb/API/SBListener.h>
end_include

begin_include
include|#
directive|include
file|<lldb/API/SBProcess.h>
end_include

begin_include
include|#
directive|include
file|<lldb/API/SBTarget.h>
end_include

begin_comment
comment|// In-house headers:
end_comment

begin_include
include|#
directive|include
file|"MICmnBase.h"
end_include

begin_include
include|#
directive|include
file|"MIUtilSingletonBase.h"
end_include

begin_include
include|#
directive|include
file|"MICmnLLDBDebugSessionInfoVarObj.h"
end_include

begin_include
include|#
directive|include
file|"MICmnMIValueTuple.h"
end_include

begin_include
include|#
directive|include
file|"MIUtilMapIdToVariant.h"
end_include

begin_comment
comment|// Declarations:
end_comment

begin_decl_stmt
name|class
name|CMICmnLLDBDebugger
decl_stmt|;
end_decl_stmt

begin_struct_decl
struct_decl|struct
name|SMICmdData
struct_decl|;
end_struct_decl

begin_decl_stmt
name|class
name|CMICmnMIValueTuple
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|class
name|CMICmnMIValueList
decl_stmt|;
end_decl_stmt

begin_comment
comment|//++ ============================================================================
end_comment

begin_comment
comment|// Details:	MI debug session object that holds debugging information between
end_comment

begin_comment
comment|//			instances of MI commands executing their work and producing MI
end_comment

begin_comment
comment|//			result records. Information/data is set by one or many commands then
end_comment

begin_comment
comment|//			retrieved by the same or other sebsequent commands.
end_comment

begin_comment
comment|//			It primarily to hold LLDB type objects.
end_comment

begin_comment
comment|//			A singleton class.
end_comment

begin_comment
comment|// Gotchas:	None.
end_comment

begin_comment
comment|// Authors:	Illya Rudkin 04/03/2014.
end_comment

begin_comment
comment|// Changes:	None.
end_comment

begin_comment
comment|//--
end_comment

begin_decl_stmt
name|class
name|CMICmnLLDBDebugSessionInfo
range|:
name|public
name|CMICmnBase
decl_stmt|,
name|public
name|MI
decl|::
name|ISingleton
decl|<
name|CMICmnLLDBDebugSessionInfo
decl|>
block|{
name|friend
name|class
name|MI
operator|::
name|ISingleton
operator|<
name|CMICmnLLDBDebugSessionInfo
operator|>
expr_stmt|;
comment|// Structs:
name|public
label|:
comment|//++ ============================================================================
comment|// Details:	Break point information object. Used to easily pass information about
comment|//			a break around and record break point information to be recalled by
comment|//			other commands or LLDB event handling functions.
comment|//--
struct|struct
name|SBrkPtInfo
block|{
name|SBrkPtInfo
argument_list|(
name|void
argument_list|)
operator|:
name|m_id
argument_list|(
literal|0
argument_list|)
operator|,
name|m_bDisp
argument_list|(
name|false
argument_list|)
operator|,
name|m_bEnabled
argument_list|(
name|false
argument_list|)
operator|,
name|m_pc
argument_list|(
literal|0
argument_list|)
operator|,
name|m_nLine
argument_list|(
literal|0
argument_list|)
operator|,
name|m_bHaveArgOptionThreadGrp
argument_list|(
name|false
argument_list|)
operator|,
name|m_nTimes
argument_list|(
literal|0
argument_list|)
operator|,
name|m_bPending
argument_list|(
name|false
argument_list|)
operator|,
name|m_nIgnore
argument_list|(
literal|0
argument_list|)
operator|,
name|m_bCondition
argument_list|(
name|false
argument_list|)
operator|,
name|m_bBrkPtThreadId
argument_list|(
name|false
argument_list|)
operator|,
name|m_nBrkPtThreadId
argument_list|(
literal|0
argument_list|)
block|{ 		}
name|MIuint
name|m_id
expr_stmt|;
comment|// LLDB break point ID.
name|CMIUtilString
name|m_strType
decl_stmt|;
comment|// Break point type.
name|bool
name|m_bDisp
decl_stmt|;
comment|// True = "del", false = "keep".
name|bool
name|m_bEnabled
decl_stmt|;
comment|// True = enabled, false = disabled break point.
name|MIuint
name|m_pc
decl_stmt|;
comment|// Address number.
name|CMIUtilString
name|m_fnName
decl_stmt|;
comment|// Function name.
name|CMIUtilString
name|m_fileName
decl_stmt|;
comment|// File name text.
name|CMIUtilString
name|m_path
decl_stmt|;
comment|// Full file name and path text.
name|MIuint
name|m_nLine
decl_stmt|;
comment|// File line number.
name|bool
name|m_bHaveArgOptionThreadGrp
decl_stmt|;
comment|// True = include MI field, false = do not include "thread-groups".
name|CMIUtilString
name|m_strOptThrdGrp
decl_stmt|;
comment|// Thread group number.
name|MIuint
name|m_nTimes
decl_stmt|;
comment|// The count of the breakpoint existence.
name|CMIUtilString
name|m_strOrigLoc
decl_stmt|;
comment|// The name of the break point.
name|bool
name|m_bPending
decl_stmt|;
comment|// True = the breakpoint has not been established yet, false = location found
name|MIuint
name|m_nIgnore
decl_stmt|;
comment|// The number of time the breakpoint is run over before it is stopped on a hit
name|bool
name|m_bCondition
decl_stmt|;
comment|// True = break point is conditional, use condition expression, false = no condition
name|CMIUtilString
name|m_strCondition
decl_stmt|;
comment|// Break point condition expression
name|bool
name|m_bBrkPtThreadId
decl_stmt|;
comment|// True = break point is specified to work with a specific thread, false = no specified thread given
name|MIuint
name|m_nBrkPtThreadId
decl_stmt|;
comment|// Restrict the breakpoint to the specified thread-id
block|}
struct|;
comment|// Typedefs:
name|public
label|:
typedef|typedef
name|std
operator|::
name|vector
operator|<
name|uint32_t
operator|>
name|VecActiveThreadId_t
expr_stmt|;
comment|// Methods:
name|public
label|:
name|bool
name|Initialize
parameter_list|(
name|void
parameter_list|)
function_decl|;
name|bool
name|Shutdown
parameter_list|(
name|void
parameter_list|)
function_decl|;
comment|// Variant type data which can be assigned and retrieved across all command instances
name|template
operator|<
name|typename
name|T
operator|>
name|bool
name|SharedDataAdd
argument_list|(
specifier|const
name|CMIUtilString
operator|&
name|vKey
argument_list|,
specifier|const
name|T
operator|&
name|vData
argument_list|)
expr_stmt|;
name|template
operator|<
name|typename
name|T
operator|>
name|bool
name|SharedDataRetrieve
argument_list|(
specifier|const
name|CMIUtilString
operator|&
name|vKey
argument_list|,
name|T
operator|&
name|vwData
argument_list|)
expr_stmt|;
name|bool
name|SharedDataDestroy
parameter_list|(
name|void
parameter_list|)
function_decl|;
comment|//	Common command required functionality
name|bool
name|AccessPath
parameter_list|(
specifier|const
name|CMIUtilString
modifier|&
name|vPath
parameter_list|,
name|bool
modifier|&
name|vwbYesAccessible
parameter_list|)
function_decl|;
name|bool
name|GetFrameInfo
argument_list|(
specifier|const
name|lldb
operator|::
name|SBFrame
operator|&
name|vrFrame
argument_list|,
name|lldb
operator|::
name|addr_t
operator|&
name|vwPc
argument_list|,
name|CMIUtilString
operator|&
name|vwFnName
argument_list|,
name|CMIUtilString
operator|&
name|vwFileName
argument_list|,
name|CMIUtilString
operator|&
name|vwPath
argument_list|,
name|MIuint
operator|&
name|vwnLine
argument_list|)
decl_stmt|;
name|bool
name|GetThreadFrames
parameter_list|(
specifier|const
name|SMICmdData
modifier|&
name|vCmdData
parameter_list|,
specifier|const
name|MIuint
name|vThreadIdx
parameter_list|,
name|CMIUtilString
modifier|&
name|vwrThreadFrames
parameter_list|)
function_decl|;
name|bool
name|GetThreadFrames2
parameter_list|(
specifier|const
name|SMICmdData
modifier|&
name|vCmdData
parameter_list|,
specifier|const
name|MIuint
name|vThreadIdx
parameter_list|,
name|CMIUtilString
modifier|&
name|vwrThreadFrames
parameter_list|)
function_decl|;
name|bool
name|ResolvePath
parameter_list|(
specifier|const
name|SMICmdData
modifier|&
name|vCmdData
parameter_list|,
specifier|const
name|CMIUtilString
modifier|&
name|vPath
parameter_list|,
name|CMIUtilString
modifier|&
name|vwrResolvedPath
parameter_list|)
function_decl|;
name|bool
name|ResolvePath
parameter_list|(
specifier|const
name|CMIUtilString
modifier|&
name|vstrUnknown
parameter_list|,
name|CMIUtilString
modifier|&
name|vwrResolvedPath
parameter_list|)
function_decl|;
name|bool
name|MIResponseFormFrameInfo
argument_list|(
specifier|const
name|lldb
operator|::
name|SBThread
operator|&
name|vrThread
argument_list|,
specifier|const
name|MIuint
name|vnLevel
argument_list|,
name|CMICmnMIValueTuple
operator|&
name|vwrMiValueTuple
argument_list|)
decl_stmt|;
name|bool
name|MIResponseFormFrameInfo
argument_list|(
specifier|const
name|lldb
operator|::
name|addr_t
name|vPc
argument_list|,
specifier|const
name|CMIUtilString
operator|&
name|vFnName
argument_list|,
specifier|const
name|CMIUtilString
operator|&
name|vFileName
argument_list|,
specifier|const
name|CMIUtilString
operator|&
name|vPath
argument_list|,
specifier|const
name|MIuint
name|vnLine
argument_list|,
name|CMICmnMIValueTuple
operator|&
name|vwrMiValueTuple
argument_list|)
decl_stmt|;
name|bool
name|MIResponseFormFrameInfo2
argument_list|(
specifier|const
name|lldb
operator|::
name|addr_t
name|vPc
argument_list|,
specifier|const
name|CMIUtilString
operator|&
name|vArgInfo
argument_list|,
specifier|const
name|CMIUtilString
operator|&
name|vFnName
argument_list|,
specifier|const
name|CMIUtilString
operator|&
name|vFileName
argument_list|,
specifier|const
name|CMIUtilString
operator|&
name|vPath
argument_list|,
specifier|const
name|MIuint
name|vnLine
argument_list|,
name|CMICmnMIValueTuple
operator|&
name|vwrMiValueTuple
argument_list|)
decl_stmt|;
name|bool
name|MIResponseFormThreadInfo
argument_list|(
specifier|const
name|SMICmdData
operator|&
name|vCmdData
argument_list|,
specifier|const
name|lldb
operator|::
name|SBThread
operator|&
name|vrThread
argument_list|,
name|CMICmnMIValueTuple
operator|&
name|vwrMIValueTuple
argument_list|)
decl_stmt|;
name|bool
name|MIResponseFormThreadInfo2
argument_list|(
specifier|const
name|SMICmdData
operator|&
name|vCmdData
argument_list|,
specifier|const
name|lldb
operator|::
name|SBThread
operator|&
name|vrThread
argument_list|,
name|CMICmnMIValueTuple
operator|&
name|vwrMIValueTuple
argument_list|)
decl_stmt|;
name|bool
name|MIResponseFormThreadInfo3
argument_list|(
specifier|const
name|SMICmdData
operator|&
name|vCmdData
argument_list|,
specifier|const
name|lldb
operator|::
name|SBThread
operator|&
name|vrThread
argument_list|,
name|CMICmnMIValueTuple
operator|&
name|vwrMIValueTuple
argument_list|)
decl_stmt|;
name|bool
name|MIResponseFormVariableInfo
argument_list|(
specifier|const
name|lldb
operator|::
name|SBFrame
operator|&
name|vrFrame
argument_list|,
specifier|const
name|MIuint
name|vMaskVarTypes
argument_list|,
name|CMICmnMIValueList
operator|&
name|vwrMiValueList
argument_list|)
decl_stmt|;
name|bool
name|MIResponseFormVariableInfo2
argument_list|(
specifier|const
name|lldb
operator|::
name|SBFrame
operator|&
name|vrFrame
argument_list|,
specifier|const
name|MIuint
name|vMaskVarTypes
argument_list|,
name|CMICmnMIValueList
operator|&
name|vwrMiValueList
argument_list|)
decl_stmt|;
name|bool
name|MIResponseFormVariableInfo3
argument_list|(
specifier|const
name|lldb
operator|::
name|SBFrame
operator|&
name|vrFrame
argument_list|,
specifier|const
name|MIuint
name|vMaskVarTypes
argument_list|,
name|CMICmnMIValueList
operator|&
name|vwrMiValueList
argument_list|)
decl_stmt|;
name|bool
name|MIResponseFormBrkPtFrameInfo
parameter_list|(
specifier|const
name|SBrkPtInfo
modifier|&
name|vrBrkPtInfo
parameter_list|,
name|CMICmnMIValueTuple
modifier|&
name|vwrMiValueTuple
parameter_list|)
function_decl|;
name|bool
name|MIResponseFormBrkPtInfo
parameter_list|(
specifier|const
name|SBrkPtInfo
modifier|&
name|vrBrkPtInfo
parameter_list|,
name|CMICmnMIValueTuple
modifier|&
name|vwrMiValueTuple
parameter_list|)
function_decl|;
name|bool
name|GetBrkPtInfo
argument_list|(
specifier|const
name|lldb
operator|::
name|SBBreakpoint
operator|&
name|vBrkPt
argument_list|,
name|SBrkPtInfo
operator|&
name|vrwBrkPtInfo
argument_list|)
decl|const
decl_stmt|;
name|bool
name|RecordBrkPtInfo
parameter_list|(
specifier|const
name|MIuint
name|vnBrkPtId
parameter_list|,
specifier|const
name|SBrkPtInfo
modifier|&
name|vrBrkPtInfo
parameter_list|)
function_decl|;
name|bool
name|RecordBrkPtInfoGet
argument_list|(
specifier|const
name|MIuint
name|vnBrkPtId
argument_list|,
name|SBrkPtInfo
operator|&
name|vrwBrkPtInfo
argument_list|)
decl|const
decl_stmt|;
name|bool
name|RecordBrkPtInfoDelete
parameter_list|(
specifier|const
name|MIuint
name|vnBrkPtId
parameter_list|)
function_decl|;
comment|// Attributes:
name|public
label|:
comment|// The following are available to all command instances
name|lldb
operator|::
name|SBDebugger
operator|&
name|m_rLldbDebugger
expr_stmt|;
name|lldb
operator|::
name|SBListener
operator|&
name|m_rLlldbListener
expr_stmt|;
name|lldb
operator|::
name|SBTarget
name|m_lldbTarget
expr_stmt|;
name|lldb
operator|::
name|SBProcess
name|m_lldbProcess
expr_stmt|;
specifier|const
name|MIuint
name|m_nBrkPointCntMax
decl_stmt|;
name|VecActiveThreadId_t
name|m_vecActiveThreadId
decl_stmt|;
name|lldb
operator|::
name|tid_t
name|m_currentSelectedThread
expr_stmt|;
comment|// These are keys that can be used to access the shared data map
comment|// Note: This list is expected to grow and will be moved and abstracted in the future.
specifier|const
name|CMIUtilString
name|m_constStrSharedDataKeyWkDir
decl_stmt|;
specifier|const
name|CMIUtilString
name|m_constStrSharedDataSolibPath
decl_stmt|;
comment|// Typedefs:
name|private
label|:
typedef|typedef
name|std
operator|::
name|vector
operator|<
name|CMICmnLLDBDebugSessionInfoVarObj
operator|>
name|VecVarObj_t
expr_stmt|;
typedef|typedef
name|std
operator|::
name|map
operator|<
name|MIuint
operator|,
name|SBrkPtInfo
operator|>
name|MapBrkPtIdToBrkPtInfo_t
expr_stmt|;
typedef|typedef
name|std
operator|::
name|pair
operator|<
name|MIuint
operator|,
name|SBrkPtInfo
operator|>
name|MapPairBrkPtIdToBrkPtInfo_t
expr_stmt|;
comment|// Methods:
name|private
label|:
comment|/* ctor */
name|CMICmnLLDBDebugSessionInfo
argument_list|(
name|void
argument_list|)
expr_stmt|;
comment|/* ctor */
name|CMICmnLLDBDebugSessionInfo
argument_list|(
specifier|const
name|CMICmnLLDBDebugSessionInfo
operator|&
argument_list|)
expr_stmt|;
name|void
name|operator
init|=
operator|(
specifier|const
name|CMICmnLLDBDebugSessionInfo
operator|&
operator|)
decl_stmt|;
comment|//
name|bool
name|GetVariableInfo
argument_list|(
specifier|const
name|MIuint
name|vnMaxDepth
argument_list|,
specifier|const
name|lldb
operator|::
name|SBValue
operator|&
name|vrValue
argument_list|,
specifier|const
name|bool
name|vbIsChildValue
argument_list|,
name|CMICmnMIValueList
operator|&
name|vwrMiValueList
argument_list|,
name|MIuint
operator|&
name|vrwnDepth
argument_list|)
decl_stmt|;
name|bool
name|GetVariableInfo2
argument_list|(
specifier|const
name|MIuint
name|vnMaxDepth
argument_list|,
specifier|const
name|lldb
operator|::
name|SBValue
operator|&
name|vrValue
argument_list|,
specifier|const
name|bool
name|vbIsChildValue
argument_list|,
name|CMICmnMIValueList
operator|&
name|vwrMiValueList
argument_list|,
name|MIuint
operator|&
name|vrwnDepth
argument_list|)
decl_stmt|;
comment|// Overridden:
name|private
label|:
comment|// From CMICmnBase
comment|/* dtor */
name|virtual
operator|~
name|CMICmnLLDBDebugSessionInfo
argument_list|(
name|void
argument_list|)
expr_stmt|;
comment|// Attributes:
name|private
label|:
name|CMIUtilMapIdToVariant
name|m_mapIdToSessionData
decl_stmt|;
comment|// Hold and retrieve key to value data available across all commands
name|VecVarObj_t
name|m_vecVarObj
decl_stmt|;
comment|// Vector of session variable objects
name|MapBrkPtIdToBrkPtInfo_t
name|m_mapBrkPtIdToBrkPtInfo
decl_stmt|;
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
comment|//++ ------------------------------------------------------------------------------------
end_comment

begin_comment
comment|// Details:	Command instances can create and share data between other instances of commands.
end_comment

begin_comment
comment|//			This function adds new data to the shared data. Using the same ID more than
end_comment

begin_comment
comment|//			once replaces any previous matching data keys.
end_comment

begin_comment
comment|// Type:	Template method.
end_comment

begin_comment
comment|// Args:	T		- The type of the object to be stored.
end_comment

begin_comment
comment|//			vKey	- (R) A non empty unique data key to retrieve the data by.
end_comment

begin_comment
comment|//			vData	- (R) Data to be added to the share.
end_comment

begin_comment
comment|// Return:	MIstatus::success - Functional succeeded.
end_comment

begin_comment
comment|//			MIstatus::failure - Functional failed.
end_comment

begin_comment
comment|// Throws:	None.
end_comment

begin_comment
comment|//--
end_comment

begin_expr_stmt
name|template
operator|<
name|typename
name|T
operator|>
name|bool
name|CMICmnLLDBDebugSessionInfo
operator|::
name|SharedDataAdd
argument_list|(
argument|const CMIUtilString& vKey
argument_list|,
argument|const T& vData
argument_list|)
block|{
if|if
condition|(
operator|!
name|m_mapIdToSessionData
operator|.
name|Add
operator|<
name|T
operator|>
operator|(
name|vKey
operator|,
name|vData
operator|)
condition|)
block|{
name|SetErrorDescription
argument_list|(
name|m_mapIdToSessionData
operator|.
name|GetErrorDescription
argument_list|()
argument_list|)
expr_stmt|;
return|return
name|MIstatus
operator|::
name|failure
return|;
block|}
end_expr_stmt

begin_return
return|return
name|MIstatus
operator|::
name|success
return|;
end_return

begin_comment
unit|}
comment|//++ ------------------------------------------------------------------------------------
end_comment

begin_comment
comment|// Details:	Command instances can create and share data between other instances of commands.
end_comment

begin_comment
comment|//			This function retrieves data from the shared data container.
end_comment

begin_comment
comment|// Type:	Method.
end_comment

begin_comment
comment|// Args:	T		- The type of the object being retrieved.
end_comment

begin_comment
comment|//			vKey	- (R) A non empty unique data key to retrieve the data by.
end_comment

begin_comment
comment|//			vData	- (W) The data.
end_comment

begin_comment
comment|// Return:	bool - True = data found, false = data not found or an error occurred trying to fetch.
end_comment

begin_comment
comment|// Throws:	None.
end_comment

begin_comment
comment|//--
end_comment

begin_expr_stmt
unit|template
operator|<
name|typename
name|T
operator|>
name|bool
name|CMICmnLLDBDebugSessionInfo
operator|::
name|SharedDataRetrieve
argument_list|(
argument|const CMIUtilString& vKey
argument_list|,
argument|T& vwData
argument_list|)
block|{
name|bool
name|bDataFound
operator|=
name|false
block|;
if|if
condition|(
operator|!
name|m_mapIdToSessionData
operator|.
name|Get
operator|<
name|T
operator|>
operator|(
name|vKey
operator|,
name|vwData
operator|,
name|bDataFound
operator|)
condition|)
block|{
name|SetErrorDescription
argument_list|(
name|m_mapIdToSessionData
operator|.
name|GetErrorDescription
argument_list|()
argument_list|)
expr_stmt|;
return|return
name|MIstatus
operator|::
name|failure
return|;
block|}
end_expr_stmt

begin_return
return|return
name|bDataFound
return|;
end_return

unit|}
end_unit

