begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- MIDriverBase.h ------------------------------------------*- C++ -*-===//
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
comment|// File:        MIDriverBase.h
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// Overview:    CMIDriverBase interface.
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
file|<lldb/API/SBDebugger.h>
end_include

begin_include
include|#
directive|include
file|<lldb/API/SBBroadcaster.h>
end_include

begin_comment
comment|// In-house headers:
end_comment

begin_include
include|#
directive|include
file|"MIUtilString.h"
end_include

begin_comment
comment|// Declarations:
end_comment

begin_decl_stmt
name|namespace
name|lldb
block|{
name|class
name|SBBroadcaster
decl_stmt|;
block|}
end_decl_stmt

begin_comment
comment|//++ ============================================================================
end_comment

begin_comment
comment|// Details: MI driver base implementation class. This class has been created so
end_comment

begin_comment
comment|//          not have to edit the lldb::SBBroadcaster class code. Functionality
end_comment

begin_comment
comment|//          and attributes need to be common to the LLDB Driver class and the
end_comment

begin_comment
comment|//          MI Driver class (derived from lldb::SBBroadcaster) so they can call
end_comment

begin_comment
comment|//          upon each other for functionality fall through and allow the
end_comment

begin_comment
comment|//          CDriverMgr to manage either (any) driver to be operated on.
end_comment

begin_comment
comment|//          Each driver instance (the CMIDriver, LLDB::Driver) has its own
end_comment

begin_comment
comment|//          LLDB::SBDebugger object.
end_comment

begin_comment
comment|// Gotchas: None.
end_comment

begin_comment
comment|// Authors: Illya Rudkin 30/01/2014.
end_comment

begin_comment
comment|// Changes: None.
end_comment

begin_comment
comment|//--
end_comment

begin_decl_stmt
name|class
name|CMIDriverBase
block|{
comment|// Methods:
name|public
label|:
comment|/* ctor */
name|CMIDriverBase
argument_list|(
name|void
argument_list|)
expr_stmt|;
name|CMIDriverBase
modifier|*
name|GetDriverToFallThruTo
argument_list|(
name|void
argument_list|)
decl|const
decl_stmt|;
name|CMIDriverBase
modifier|*
name|GetDriversParent
argument_list|(
name|void
argument_list|)
decl|const
decl_stmt|;
comment|// Overrideable:
name|public
label|:
comment|/* dtor */
name|virtual
operator|~
name|CMIDriverBase
argument_list|(
name|void
argument_list|)
expr_stmt|;
name|virtual
name|bool
name|DoFallThruToAnotherDriver
parameter_list|(
specifier|const
name|CMIUtilString
modifier|&
name|vCmd
parameter_list|,
name|CMIUtilString
modifier|&
name|vwErrMsg
parameter_list|)
function_decl|;
name|virtual
name|bool
name|SetDriverToFallThruTo
parameter_list|(
specifier|const
name|CMIDriverBase
modifier|&
name|vrOtherDriver
parameter_list|)
function_decl|;
name|virtual
name|bool
name|SetDriverParent
parameter_list|(
specifier|const
name|CMIDriverBase
modifier|&
name|vrOtherDriver
parameter_list|)
function_decl|;
name|virtual
specifier|const
name|CMIUtilString
modifier|&
name|GetDriverName
argument_list|(
name|void
argument_list|)
decl|const
init|=
literal|0
decl_stmt|;
name|virtual
specifier|const
name|CMIUtilString
modifier|&
name|GetDriverId
argument_list|(
name|void
argument_list|)
decl|const
init|=
literal|0
decl_stmt|;
name|virtual
name|void
name|SetExitApplicationFlag
parameter_list|(
specifier|const
name|bool
name|vbForceExit
parameter_list|)
function_decl|;
comment|// MI provide information for the pass through (child) assigned driver
name|virtual
name|FILE
modifier|*
name|GetStdin
argument_list|(
name|void
argument_list|)
decl|const
decl_stmt|;
name|virtual
name|FILE
modifier|*
name|GetStdout
argument_list|(
name|void
argument_list|)
decl|const
decl_stmt|;
name|virtual
name|FILE
modifier|*
name|GetStderr
argument_list|(
name|void
argument_list|)
decl|const
decl_stmt|;
comment|// Attributes:
name|protected
label|:
name|CMIDriverBase
modifier|*
name|m_pDriverFallThru
decl_stmt|;
comment|// Child driver to use should *this driver not be able to handle client input
name|CMIDriverBase
modifier|*
name|m_pDriverParent
decl_stmt|;
comment|// The parent driver who passes work to *this driver to do work
name|CMIUtilString
name|m_strDriverId
decl_stmt|;
name|bool
name|m_bExitApp
decl_stmt|;
comment|// True = Yes, exit application, false = continue execution
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

end_unit

