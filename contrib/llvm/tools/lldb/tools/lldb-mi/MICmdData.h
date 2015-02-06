begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- MICmdData.h ---------------------------------------------*- C++ -*-===//
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
comment|// File:        MICmdData.h
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// Overview:    SMICmdData interface.
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
comment|// In-house headers:
end_comment

begin_include
include|#
directive|include
file|"MICmnResources.h"
end_include

begin_comment
comment|//++ ============================================================================
end_comment

begin_comment
comment|// Details: MI command metadata. Holds the command's name, MI number and options
end_comment

begin_comment
comment|//          as found on stdin. Holds the command's MI output (written to stdout).
end_comment

begin_comment
comment|// Gotchas: None.
end_comment

begin_comment
comment|// Authors: Illya Rudkin 18/02/2014.
end_comment

begin_comment
comment|// Changes: None.
end_comment

begin_comment
comment|//--
end_comment

begin_struct
struct|struct
name|SMICmdData
block|{
name|SMICmdData
argument_list|(
name|void
argument_list|)
operator|:
name|id
argument_list|(
literal|0
argument_list|)
operator|,
name|bCmdValid
argument_list|(
name|false
argument_list|)
operator|,
name|bCmdExecutedSuccessfully
argument_list|(
name|false
argument_list|)
operator|,
name|bMIOldStyle
argument_list|(
name|false
argument_list|)
operator|,
name|bHasResultRecordExtra
argument_list|(
argument|false
argument_list|)
block|{}
expr_stmt|;
name|MIuint
name|id
decl_stmt|;
comment|// A command's unique ID i.e. GUID
name|CMIUtilString
name|strMiCmdToken
decl_stmt|;
comment|// The command's MI token (a number)
name|CMIUtilString
name|strMiCmd
decl_stmt|;
comment|// The command's name
name|CMIUtilString
name|strMiCmdOption
decl_stmt|;
comment|// The command's arguments or options
name|CMIUtilString
name|strMiCmdAll
decl_stmt|;
comment|// The text as received from the client
name|CMIUtilString
name|strMiCmdResultRecord
decl_stmt|;
comment|// Each command forms 1 response to its input
name|CMIUtilString
name|strMiCmdResultRecordExtra
decl_stmt|;
comment|// Hack command produce more response text to help the client because of using LLDB
name|bool
name|bCmdValid
decl_stmt|;
comment|// True = Valid MI format command, false = invalid
name|bool
name|bCmdExecutedSuccessfully
decl_stmt|;
comment|// True = Command finished successfully, false = Did not start/did not complete
name|CMIUtilString
name|strErrorDescription
decl_stmt|;
comment|// Command failed this is why
name|bool
name|bMIOldStyle
decl_stmt|;
comment|// True = format "3thread", false = format "3-thread"
name|bool
name|bHasResultRecordExtra
decl_stmt|;
comment|// True = Yes command produced additional MI output to its 1 line response, false = no extra MI output formed
name|void
name|Clear
parameter_list|(
name|void
parameter_list|)
block|{
name|id
operator|=
literal|0
expr_stmt|;
name|strMiCmdToken
operator|.
name|clear
argument_list|()
expr_stmt|;
name|strMiCmd
operator|=
name|MIRSRC
argument_list|(
name|IDS_CMD_ERR_CMD_RUN_BUT_NO_ACTION
argument_list|)
expr_stmt|;
name|strMiCmdOption
operator|.
name|clear
argument_list|()
expr_stmt|;
name|strMiCmdAll
operator|.
name|clear
argument_list|()
expr_stmt|;
name|strMiCmdResultRecord
operator|.
name|clear
argument_list|()
expr_stmt|;
name|strMiCmdResultRecordExtra
operator|.
name|clear
argument_list|()
expr_stmt|;
name|bCmdValid
operator|=
name|false
expr_stmt|;
name|bCmdExecutedSuccessfully
operator|=
name|false
expr_stmt|;
name|strErrorDescription
operator|.
name|clear
argument_list|()
expr_stmt|;
name|bMIOldStyle
operator|=
name|false
expr_stmt|;
name|bHasResultRecordExtra
operator|=
name|false
expr_stmt|;
block|}
block|}
struct|;
end_struct

end_unit

