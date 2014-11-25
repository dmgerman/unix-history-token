begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- MICmnThreadMgrStd.h -------------------------------------*- C++ -*-===//
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
comment|// File:		MICmnThreadMgrStd.h
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// Overview:	CMICmnThreadMgr interface.
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
file|<vector>
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
file|"MIUtilThreadBaseStd.h"
end_include

begin_include
include|#
directive|include
file|"MICmnResources.h"
end_include

begin_include
include|#
directive|include
file|"MIUtilSingletonBase.h"
end_include

begin_comment
comment|//++ ============================================================================
end_comment

begin_comment
comment|// Details:	MI's worker thread (active thread) manager.
end_comment

begin_comment
comment|//			The manager creates threads and behalf of clients. Client are
end_comment

begin_comment
comment|//			responsible for their threads and can delete them when necessary.
end_comment

begin_comment
comment|//			This manager will stop and delete all threads on *this manager's
end_comment

begin_comment
comment|//			shutdown.
end_comment

begin_comment
comment|//			Singleton class.
end_comment

begin_comment
comment|// Gotchas:	None.
end_comment

begin_comment
comment|// Authors:	Aidan Dodds 12/03/2014.
end_comment

begin_comment
comment|// Changes:	None.
end_comment

begin_comment
comment|//--
end_comment

begin_decl_stmt
name|class
name|CMICmnThreadMgrStd
range|:
name|public
name|CMICmnBase
decl_stmt|,
name|public
name|MI
decl|::
name|ISingleton
decl|<
name|CMICmnThreadMgrStd
decl|>
block|{
name|friend
name|MI
operator|::
name|ISingleton
operator|<
name|CMICmnThreadMgrStd
operator|>
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
name|bool
name|ThreadAllTerminate
parameter_list|(
name|void
parameter_list|)
function_decl|;
comment|// Ask all threads to stop (caution)
name|template
operator|<
name|typename
name|T
operator|>
comment|// Ask the thread manager to start and stop threads on our behalf
name|bool
name|ThreadStart
argument_list|(
name|T
operator|&
name|vrwObject
argument_list|)
expr_stmt|;
comment|// Typedef:
name|private
label|:
typedef|typedef
name|std
operator|::
name|vector
operator|<
name|CMIUtilThreadActiveObjBase
operator|*
operator|>
name|ThreadList_t
expr_stmt|;
comment|// Methods:
name|private
label|:
comment|/* ctor */
name|CMICmnThreadMgrStd
argument_list|(
name|void
argument_list|)
expr_stmt|;
comment|/* ctor */
name|CMICmnThreadMgrStd
argument_list|(
specifier|const
name|CMICmnThreadMgrStd
operator|&
argument_list|)
expr_stmt|;
name|void
name|operator
init|=
operator|(
specifier|const
name|CMICmnThreadMgrStd
operator|&
operator|)
decl_stmt|;
comment|//
name|bool
name|AddThread
parameter_list|(
specifier|const
name|CMIUtilThreadActiveObjBase
modifier|&
name|vrObj
parameter_list|)
function_decl|;
comment|// Add a thread for monitoring by the threadmanager
comment|// Overridden:
name|private
label|:
comment|// From CMICmnBase
comment|/* dtor */
name|virtual
operator|~
name|CMICmnThreadMgrStd
argument_list|(
name|void
argument_list|)
expr_stmt|;
comment|// Attributes:
name|private
label|:
name|CMIUtilThreadMutex
name|m_mutex
decl_stmt|;
name|ThreadList_t
name|m_threadList
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
comment|// Details:	Given a thread object start its (worker) thread to do work. The object is
end_comment

begin_comment
comment|//			added to the *this manager for housekeeping and deletion of all thread objects.
end_comment

begin_comment
comment|// Type:	Template method.
end_comment

begin_comment
comment|// Args:	vrwThreadObj	- (RW) A CMIUtilThreadActiveObjBase derived object.
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
name|CMICmnThreadMgrStd
operator|::
name|ThreadStart
argument_list|(
argument|T& vrwThreadObj
argument_list|)
block|{
name|bool
name|bOk
operator|=
name|MIstatus
operator|::
name|success
block|;
comment|// Grab a reference to the base object type
name|CMIUtilThreadActiveObjBase
operator|&
name|rObj
operator|=
name|static_cast
operator|<
name|CMIUtilThreadActiveObjBase
operator|&
operator|>
operator|(
name|vrwThreadObj
operator|)
block|;
comment|// Add to the thread managers internal database
name|bOk
operator|&=
name|AddThread
argument_list|(
name|rObj
argument_list|)
block|;
if|if
condition|(
operator|!
name|bOk
condition|)
block|{
specifier|const
name|CMIUtilString
name|errMsg
argument_list|(
name|CMIUtilString
operator|::
name|Format
argument_list|(
name|MIRSRC
argument_list|(
name|IDS_THREADMGR_ERR_THREAD_FAIL_CREATE
argument_list|)
argument_list|,
name|vrwThreadObj
operator|.
name|ThreadGetName
argument_list|()
operator|.
name|c_str
argument_list|()
argument_list|)
argument_list|)
decl_stmt|;
name|SetErrorDescription
argument_list|(
name|errMsg
argument_list|)
expr_stmt|;
return|return
name|MIstatus
operator|::
name|failure
return|;
block|}
comment|// Grab a reference on behalf of the caller
name|bOk
operator|&=
name|vrwThreadObj
operator|.
name|Acquire
argument_list|()
expr_stmt|;
end_expr_stmt

begin_if
if|if
condition|(
operator|!
name|bOk
condition|)
block|{
specifier|const
name|CMIUtilString
name|errMsg
argument_list|(
name|CMIUtilString
operator|::
name|Format
argument_list|(
name|MIRSRC
argument_list|(
name|IDS_THREADMGR_ERR_THREAD_FAIL_CREATE
argument_list|)
argument_list|,
name|vrwThreadObj
operator|.
name|ThreadGetName
argument_list|()
operator|.
name|c_str
argument_list|()
argument_list|)
argument_list|)
decl_stmt|;
name|SetErrorDescription
argument_list|(
name|errMsg
argument_list|)
expr_stmt|;
return|return
name|MIstatus
operator|::
name|failure
return|;
block|}
end_if

begin_comment
comment|// Thread is already started
end_comment

begin_comment
comment|// This call must come after the reference count increment
end_comment

begin_if
if|if
condition|(
name|vrwThreadObj
operator|.
name|ThreadIsActive
argument_list|()
condition|)
block|{
comment|// Early exit on thread already running condition
return|return
name|MIstatus
operator|::
name|success
return|;
block|}
end_if

begin_comment
comment|// Start the thread running
end_comment

begin_expr_stmt
name|bOk
operator|&=
name|vrwThreadObj
operator|.
name|ThreadExecute
argument_list|()
expr_stmt|;
end_expr_stmt

begin_if
if|if
condition|(
operator|!
name|bOk
condition|)
block|{
specifier|const
name|CMIUtilString
name|errMsg
argument_list|(
name|CMIUtilString
operator|::
name|Format
argument_list|(
name|MIRSRC
argument_list|(
name|IDS_THREADMGR_ERR_THREAD_FAIL_CREATE
argument_list|)
argument_list|,
name|vrwThreadObj
operator|.
name|ThreadGetName
argument_list|()
operator|.
name|c_str
argument_list|()
argument_list|)
argument_list|)
decl_stmt|;
name|SetErrorDescription
argument_list|(
name|errMsg
argument_list|)
expr_stmt|;
return|return
name|MIstatus
operator|::
name|failure
return|;
block|}
end_if

begin_return
return|return
name|MIstatus
operator|::
name|success
return|;
end_return

unit|}
end_unit

