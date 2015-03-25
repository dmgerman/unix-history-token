begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- MICmdInvoker.h ------------------------------------------*- C++ -*-===//
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
comment|// File:        MICmdInvoker.h
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// Overview:    CMICmdInvoker interface.
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
comment|// Third party headers
end_comment

begin_include
include|#
directive|include
file|<map>
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
file|"MICmdData.h"
end_include

begin_include
include|#
directive|include
file|"MICmdMgrSetCmdDeleteCallback.h"
end_include

begin_include
include|#
directive|include
file|"MIUtilSingletonBase.h"
end_include

begin_comment
comment|// Declarations:
end_comment

begin_decl_stmt
name|class
name|CMICmdBase
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|class
name|CMICmnStreamStdout
decl_stmt|;
end_decl_stmt

begin_comment
comment|//++ ============================================================================
end_comment

begin_comment
comment|// Details: MI Command Invoker. The Invoker works on the command pattern design.
end_comment

begin_comment
comment|//          There two main jobs; action command Execute() function, followed by
end_comment

begin_comment
comment|//          the command's Acknowledge() function. When a command has finished its
end_comment

begin_comment
comment|//          execute function it returns to the invoker. The invoker then calls the
end_comment

begin_comment
comment|//          command's Acknowledge() function to do more work, form and give
end_comment

begin_comment
comment|//          back a MI result. In the meantime the Command Monitor is monitoring
end_comment

begin_comment
comment|//          the each command doing their Execute() function work so they do not
end_comment

begin_comment
comment|//          exceed a time limit which if it exceeds informs the command(s) to
end_comment

begin_comment
comment|//          stop work.
end_comment

begin_comment
comment|//          The work by the Invoker is carried out in the main thread.
end_comment

begin_comment
comment|//          The Invoker takes ownersip of any commands created which means it
end_comment

begin_comment
comment|//          is the only object to delete them when a command is finished working.
end_comment

begin_comment
comment|//          A singleton class.
end_comment

begin_comment
comment|// Gotchas: None.
end_comment

begin_comment
comment|// Authors: Illya Rudkin 19/02/2014.
end_comment

begin_comment
comment|// Changes: None.
end_comment

begin_comment
comment|//--
end_comment

begin_decl_stmt
name|class
name|CMICmdInvoker
range|:
name|public
name|CMICmnBase
decl_stmt|,
name|public
name|CMICmdMgrSetCmdDeleteCallback
decl|::
name|ICallback
decl_stmt|,
name|public
name|MI
decl|::
name|ISingleton
decl|<
name|CMICmdInvoker
decl|>
block|{
name|friend
name|class
name|MI
operator|::
name|ISingleton
operator|<
name|CMICmdInvoker
operator|>
expr_stmt|;
comment|// Class:
name|public
label|:
comment|//++
comment|// Description: Invoker's interface for commands to implement.
comment|//--
name|class
name|ICmd
block|{
name|public
label|:
name|virtual
name|bool
name|Acknowledge
parameter_list|(
name|void
parameter_list|)
init|=
literal|0
function_decl|;
name|virtual
name|bool
name|Execute
parameter_list|(
name|void
parameter_list|)
init|=
literal|0
function_decl|;
name|virtual
name|bool
name|ParseArgs
parameter_list|(
name|void
parameter_list|)
init|=
literal|0
function_decl|;
name|virtual
name|bool
name|SetCmdData
parameter_list|(
specifier|const
name|SMICmdData
modifier|&
name|vCmdData
parameter_list|)
init|=
literal|0
function_decl|;
name|virtual
specifier|const
name|SMICmdData
modifier|&
name|GetCmdData
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
name|GetErrorDescription
argument_list|(
name|void
argument_list|)
decl|const
init|=
literal|0
decl_stmt|;
name|virtual
name|void
name|CmdFinishedTellInvoker
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
name|GetMIResultRecord
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
name|GetMIResultRecordExtra
argument_list|(
name|void
argument_list|)
decl|const
init|=
literal|0
decl_stmt|;
name|virtual
name|bool
name|HasMIResultRecordExtra
argument_list|(
name|void
argument_list|)
decl|const
init|=
literal|0
decl_stmt|;
comment|/* dtor */
name|virtual
operator|~
name|ICmd
argument_list|(
argument|void
argument_list|)
block|{}
expr_stmt|;
block|}
empty_stmt|;
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
name|CmdExecute
parameter_list|(
name|CMICmdBase
modifier|&
name|vCmd
parameter_list|)
function_decl|;
name|bool
name|CmdExecuteFinished
parameter_list|(
name|CMICmdBase
modifier|&
name|vCmd
parameter_list|)
function_decl|;
comment|// Typedefs:
name|private
label|:
typedef|typedef
name|std
operator|::
name|map
operator|<
name|MIuint
operator|,
name|CMICmdBase
operator|*
operator|>
name|MapCmdIdToCmd_t
expr_stmt|;
typedef|typedef
name|std
operator|::
name|pair
operator|<
name|MIuint
operator|,
name|CMICmdBase
operator|*
operator|>
name|MapPairCmdIdToCmd_t
expr_stmt|;
comment|// Methods:
name|private
label|:
comment|/* ctor */
name|CMICmdInvoker
argument_list|(
name|void
argument_list|)
expr_stmt|;
comment|/* ctor */
name|CMICmdInvoker
argument_list|(
specifier|const
name|CMICmdInvoker
operator|&
argument_list|)
expr_stmt|;
name|void
name|operator
init|=
operator|(
specifier|const
name|CMICmdInvoker
operator|&
operator|)
decl_stmt|;
name|void
name|CmdDeleteAll
parameter_list|(
name|void
parameter_list|)
function_decl|;
name|bool
name|CmdDelete
parameter_list|(
specifier|const
name|MIuint
name|vCmdId
parameter_list|,
specifier|const
name|bool
name|vbYesDeleteCmd
init|=
name|false
parameter_list|)
function_decl|;
name|bool
name|CmdAdd
parameter_list|(
specifier|const
name|CMICmdBase
modifier|&
name|vCmd
parameter_list|)
function_decl|;
name|bool
name|CmdStdout
argument_list|(
specifier|const
name|SMICmdData
operator|&
name|vCmdData
argument_list|)
decl|const
decl_stmt|;
name|void
name|CmdCauseAppExit
argument_list|(
specifier|const
name|CMICmdBase
operator|&
name|vCmd
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
name|CMICmdInvoker
argument_list|(
name|void
argument_list|)
expr_stmt|;
comment|// From CMICmdMgrSetCmdDeleteCallback::ICallback
name|virtual
name|void
name|Delete
parameter_list|(
name|SMICmdData
modifier|&
name|vCmd
parameter_list|)
function_decl|;
comment|// Attributes:
name|private
label|:
name|MapCmdIdToCmd_t
name|m_mapCmdIdToCmd
decl_stmt|;
name|CMICmnStreamStdout
modifier|&
name|m_rStreamOut
decl_stmt|;
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

end_unit

