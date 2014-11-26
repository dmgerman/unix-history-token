begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- MIDriverMgr.h -------------------------------------------*- C++ -*-===//
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
comment|// File:		MIDriverMgr.h
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// Overview:	CMIImplCmn interface.
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
comment|//				Libraries:	See MIReadme.txt.
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
file|<lldb/API/SBDebugger.h>
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
file|"MIUtilString.h"
end_include

begin_include
include|#
directive|include
file|"MICmnLog.h"
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
comment|// Details:	MI Driver Manager. Register lldb::SBBroadcaster derived Driver type
end_comment

begin_comment
comment|//			objects with *this manager. The manager does not own driver objects
end_comment

begin_comment
comment|//			registered with it and so will not delete when this manager is
end_comment

begin_comment
comment|//			shutdown. The Driver flagged as "use this one" will be set as current
end_comment

begin_comment
comment|//			driver and will be the one that is used. Other drivers are not
end_comment

begin_comment
comment|//			operated. A Driver can call another Driver should it not handle a
end_comment

begin_comment
comment|//			command.
end_comment

begin_comment
comment|//			It also initializes other resources as part it's setup such as the
end_comment

begin_comment
comment|//			Logger and Resources objects (explicit indicate *this object requires
end_comment

begin_comment
comment|//			those objects (modules/components) to support it's own functionality).
end_comment

begin_comment
comment|//			The Driver manager is the first object instantiated as part of the
end_comment

begin_comment
comment|//			MI code base. It is also the first thing to interpret the command
end_comment

begin_comment
comment|//			line arguments passed to the executeable. Bases on options it
end_comment

begin_comment
comment|//			understands the manage will set up the appropriate driver or give
end_comment

begin_comment
comment|//			help information. Other options are passed on to the driver chosen
end_comment

begin_comment
comment|//			to do work.
end_comment

begin_comment
comment|//			Each driver instance (the CMIDriver, LLDB::Driver) has its own
end_comment

begin_comment
comment|//			LLDB::SBDebugger.
end_comment

begin_comment
comment|//			Singleton class.
end_comment

begin_comment
comment|// Gotchas:	None.
end_comment

begin_comment
comment|// Authors:	Illya Rudkin 28/02/2014.
end_comment

begin_comment
comment|// Changes:	None.
end_comment

begin_comment
comment|//--
end_comment

begin_decl_stmt
name|class
name|CMIDriverMgr
range|:
name|public
name|CMICmnBase
decl_stmt|,
name|public
name|MI
decl|::
name|ISingleton
decl|<
name|CMIDriverMgr
decl|>
block|{
name|friend
name|MI
operator|::
name|ISingleton
operator|<
name|CMIDriverMgr
operator|>
expr_stmt|;
comment|// Class:
name|public
label|:
comment|//++
comment|// Description: Driver deriver objects need this interface to work with
comment|//				*this manager.
comment|//--
name|class
name|IDriver
block|{
name|public
label|:
name|virtual
name|bool
name|DoInitialize
parameter_list|(
name|void
parameter_list|)
init|=
literal|0
function_decl|;
name|virtual
name|bool
name|DoShutdown
parameter_list|(
name|void
parameter_list|)
init|=
literal|0
function_decl|;
name|virtual
name|bool
name|DoMainLoop
parameter_list|(
name|void
parameter_list|)
init|=
literal|0
function_decl|;
name|virtual
name|void
name|DoResizeWindow
parameter_list|(
specifier|const
name|uint32_t
name|vWindowSizeWsCol
parameter_list|)
init|=
literal|0
function_decl|;
name|virtual
name|lldb
operator|::
name|SBError
name|DoParseArgs
argument_list|(
argument|const int argc
argument_list|,
argument|const char * argv[]
argument_list|,
argument|FILE * vpStdOut
argument_list|,
argument|bool& vwbExiting
argument_list|)
operator|=
literal|0
expr_stmt|;
name|virtual
name|CMIUtilString
name|GetError
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
name|GetName
argument_list|(
name|void
argument_list|)
decl|const
init|=
literal|0
decl_stmt|;
name|virtual
name|lldb
operator|::
name|SBDebugger
operator|&
name|GetTheDebugger
argument_list|(
name|void
argument_list|)
operator|=
literal|0
expr_stmt|;
name|virtual
name|bool
name|GetDriverIsGDBMICompatibleDriver
argument_list|(
name|void
argument_list|)
decl|const
init|=
literal|0
decl_stmt|;
name|virtual
name|bool
name|SetId
parameter_list|(
specifier|const
name|CMIUtilString
modifier|&
name|vId
parameter_list|)
init|=
literal|0
function_decl|;
name|virtual
specifier|const
name|CMIUtilString
modifier|&
name|GetId
argument_list|(
name|void
argument_list|)
decl|const
init|=
literal|0
decl_stmt|;
comment|// Not part of the interface, ignore
comment|/* dtor */
name|virtual
operator|~
name|IDriver
argument_list|(
argument|void
argument_list|)
block|{}
block|}
empty_stmt|;
comment|// Methods:
name|public
label|:
comment|// MI system
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
comment|//
name|CMIUtilString
name|GetAppVersion
argument_list|(
name|void
argument_list|)
decl|const
decl_stmt|;
name|bool
name|RegisterDriver
parameter_list|(
specifier|const
name|IDriver
modifier|&
name|vrADriver
parameter_list|,
specifier|const
name|CMIUtilString
modifier|&
name|vrDriverID
parameter_list|)
function_decl|;
name|bool
name|UnregisterDriver
parameter_list|(
specifier|const
name|IDriver
modifier|&
name|vrADriver
parameter_list|)
function_decl|;
name|bool
name|SetUseThisDriverToDoWork
parameter_list|(
specifier|const
name|IDriver
modifier|&
name|vrADriver
parameter_list|)
function_decl|;
comment|// Specify working main driver
name|IDriver
modifier|*
name|GetUseThisDriverToDoWork
argument_list|(
name|void
argument_list|)
decl|const
decl_stmt|;
name|bool
name|ParseArgs
parameter_list|(
specifier|const
name|int
name|argc
parameter_list|,
specifier|const
name|char
modifier|*
name|argv
index|[]
parameter_list|,
name|bool
modifier|&
name|vwbExiting
parameter_list|)
function_decl|;
name|IDriver
modifier|*
name|GetDriver
argument_list|(
specifier|const
name|CMIUtilString
operator|&
name|vrDriverId
argument_list|)
decl|const
decl_stmt|;
comment|//
comment|// MI Proxy fn to current specified working driver
name|bool
name|DriverMainLoop
parameter_list|(
name|void
parameter_list|)
function_decl|;
name|void
name|DriverResizeWindow
parameter_list|(
specifier|const
name|uint32_t
name|vWindowSizeWsCol
parameter_list|)
function_decl|;
name|bool
name|DriverParseArgs
parameter_list|(
specifier|const
name|int
name|argc
parameter_list|,
specifier|const
name|char
modifier|*
name|argv
index|[]
parameter_list|,
name|FILE
modifier|*
name|vpStdOut
parameter_list|,
name|bool
modifier|&
name|vwbExiting
parameter_list|)
function_decl|;
name|CMIUtilString
name|DriverGetError
argument_list|(
name|void
argument_list|)
decl|const
decl_stmt|;
name|CMIUtilString
name|DriverGetName
argument_list|(
name|void
argument_list|)
decl|const
decl_stmt|;
name|lldb
operator|::
name|SBDebugger
operator|*
name|DriverGetTheDebugger
argument_list|(
name|void
argument_list|)
expr_stmt|;
comment|// Typedef:
name|private
label|:
typedef|typedef
name|std
operator|::
name|map
operator|<
name|CMIUtilString
operator|,
name|IDriver
operator|*
operator|>
name|MapDriverIdToDriver_t
expr_stmt|;
typedef|typedef
name|std
operator|::
name|pair
operator|<
name|CMIUtilString
operator|,
name|IDriver
operator|*
operator|>
name|MapPairDriverIdToDriver_t
expr_stmt|;
comment|// Methods:
name|private
label|:
comment|/* ctor */
name|CMIDriverMgr
argument_list|(
name|void
argument_list|)
expr_stmt|;
comment|/* ctor */
name|CMIDriverMgr
argument_list|(
specifier|const
name|CMIDriverMgr
operator|&
argument_list|)
expr_stmt|;
name|void
name|operator
init|=
operator|(
specifier|const
name|CMIDriverMgr
operator|&
operator|)
decl_stmt|;
comment|//
name|bool
name|HaveDriverAlready
argument_list|(
specifier|const
name|IDriver
operator|&
name|vrMedium
argument_list|)
decl|const
decl_stmt|;
name|bool
name|UnregisterDriverAll
parameter_list|(
name|void
parameter_list|)
function_decl|;
name|IDriver
modifier|*
name|GetFirstMIDriver
argument_list|(
name|void
argument_list|)
decl|const
decl_stmt|;
name|IDriver
modifier|*
name|GetFirstNonMIDriver
argument_list|(
name|void
argument_list|)
decl|const
decl_stmt|;
name|CMIUtilString
name|GetHelpOnCmdLineArgOptions
argument_list|(
name|void
argument_list|)
decl|const
decl_stmt|;
comment|// Overridden:
name|private
label|:
comment|// From CMICmnBase
comment|/* dtor */
name|virtual
operator|~
name|CMIDriverMgr
argument_list|(
name|void
argument_list|)
expr_stmt|;
comment|// Attributes:
name|private
label|:
name|MapDriverIdToDriver_t
name|m_mapDriverIdToDriver
decl_stmt|;
name|IDriver
modifier|*
name|m_pDriverCurrent
decl_stmt|;
comment|// This driver is used by this manager to do work. It is the main driver.
name|bool
name|m_bInMi2Mode
decl_stmt|;
comment|// True = --interpreter entered on the cmd line, false = operate LLDB driver (non GDB)
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

end_unit

