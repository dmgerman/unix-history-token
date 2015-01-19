begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- MIUtilSingletonHelper.h ---------------------------------*- C++ -*-===//
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
comment|// File:		MIUtilSingletonHelper.h
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// Overview:	Contains template functions to aid the initialisation and
end_comment

begin_comment
comment|//				shutdown of MI modules. MI modules (or components) can
end_comment

begin_comment
comment|//				use other MI modules to help them achieve their one task
end_comment

begin_comment
comment|//				(Modules only do one task).
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

begin_decl_stmt
name|namespace
name|MI
block|{
comment|// In house headers:
include|#
directive|include
file|"MIUtilString.h"
include|#
directive|include
file|"MICmnResources.h"
comment|//++ ============================================================================
comment|// Details:	Short cut helper function to simplify repeated initialisation of
comment|//			MI components (singletons) required by a client module.
comment|// Type:	Template method.
comment|// Args:	vErrorResrcId	- (R)  The string resource ID error message identifier to place in errMsg.
comment|//			vwrbOk			- (RW) On input True = Try to initalise MI driver module.
comment|//								   On output True = MI driver module initialise successfully.
comment|//			vwrErrMsg		- (W)  MI driver module initialise error description on failure.
comment|// Return:	MIstatus::success - Functional succeeded.
comment|//			MIstatus::failure - Functional failed.
comment|// Authors:	Aidan Dodds 17/03/2014.
comment|// Changes:	None.
comment|//--
name|template
operator|<
name|typename
name|T
operator|>
name|bool
name|ModuleInit
argument_list|(
argument|const MIint vErrorResrcId
argument_list|,
argument|bool& vwrbOk
argument_list|,
argument|CMIUtilString& vwrErrMsg
argument_list|)
block|{
if|if
condition|(
name|vwrbOk
operator|&&
operator|!
name|T
operator|::
name|Instance
argument_list|()
operator|.
name|Initialize
argument_list|()
condition|)
block|{
name|vwrbOk
operator|=
name|MIstatus
operator|::
name|failure
expr_stmt|;
name|vwrErrMsg
operator|=
name|CMIUtilString
operator|::
name|Format
argument_list|(
name|MIRSRC
argument_list|(
name|vErrorResrcId
argument_list|)
argument_list|,
name|T
operator|::
name|Instance
argument_list|()
operator|.
name|GetErrorDescription
argument_list|()
operator|.
name|c_str
argument_list|()
argument_list|)
expr_stmt|;
block|}
return|return
name|vwrbOk
return|;
block|}
comment|//++ ============================================================================
comment|// Details:	Short cut helper function to simplify repeated shutodown of
comment|//			MI components (singletons) required by a client module.
comment|// Type:	Template method.
comment|// Args:	vErrorResrcId	- (R)  The string resource ID error message identifier
comment|//								   to place in errMsg.
comment|//			vwrbOk			- (W)  If not already false make false on module
comment|//								   shutdown failure.
comment|//			vwrErrMsg		- (RW) Append to existing error description string MI
comment|//								   driver module initialise error description on
comment|//								   failure.
comment|// Return:	True - Module shutdown succeeded.
comment|//			False - Module shutdown failed.
comment|// Authors:	Aidan Dodds 17/03/2014.
comment|// Changes:	None.
comment|//--
name|template
operator|<
name|typename
name|T
operator|>
name|bool
name|ModuleShutdown
argument_list|(
argument|const MIint vErrorResrcId
argument_list|,
argument|bool& vwrbOk
argument_list|,
argument|CMIUtilString& vwrErrMsg
argument_list|)
block|{
name|bool
name|bOk
operator|=
name|MIstatus
operator|::
name|success
block|;
if|if
condition|(
operator|!
name|T
operator|::
name|Instance
argument_list|()
operator|.
name|Shutdown
argument_list|()
condition|)
block|{
specifier|const
name|bool
name|bMoreThanOneError
argument_list|(
operator|!
name|vwrErrMsg
operator|.
name|empty
argument_list|()
argument_list|)
decl_stmt|;
name|bOk
operator|=
name|MIstatus
operator|::
name|failure
expr_stmt|;
if|if
condition|(
name|bMoreThanOneError
condition|)
name|vwrErrMsg
operator|+=
literal|", "
expr_stmt|;
name|vwrErrMsg
operator|+=
name|CMIUtilString
operator|::
name|Format
argument_list|(
name|MIRSRC
argument_list|(
name|vErrorResrcId
argument_list|)
argument_list|,
name|T
operator|::
name|Instance
argument_list|()
operator|.
name|GetErrorDescription
argument_list|()
operator|.
name|c_str
argument_list|()
argument_list|)
expr_stmt|;
block|}
name|vwrbOk
operator|=
name|bOk
condition|?
name|vwrbOk
else|:
name|MIstatus
operator|::
name|failure
expr_stmt|;
return|return
name|bOk
return|;
block|}
end_decl_stmt

begin_comment
unit|}
comment|// namespace MI
end_comment

end_unit

