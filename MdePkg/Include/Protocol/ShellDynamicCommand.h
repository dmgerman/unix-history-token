begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/** @file   EFI Shell Dynamic Command registration protocol    (C) Copyright 2012-2014 Hewlett-Packard Development Company, L.P.<BR>   Copyright (c) 2016, Intel Corporation. All rights reserved.<BR>   This program and the accompanying materials   are licensed and made available under the terms and conditions of the BSD License   which accompanies this distribution.  The full text of the license may be found at   http://opensource.org/licenses/bsd-license.php    THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN "AS IS" BASIS,   WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.  **/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__EFI_SHELL_DYNAMIC_COMMAND_PROTOCOL_H__
end_ifndef

begin_define
define|#
directive|define
name|__EFI_SHELL_DYNAMIC_COMMAND_PROTOCOL_H__
end_define

begin_include
include|#
directive|include
file|<Protocol/Shell.h>
end_include

begin_include
include|#
directive|include
file|<Protocol/ShellParameters.h>
end_include

begin_comment
comment|// {3C7200E9-005F-4EA4-87DE-A3DFAC8A27C3}
end_comment

begin_define
define|#
directive|define
name|EFI_SHELL_DYNAMIC_COMMAND_PROTOCOL_GUID
define|\
value|{ \   0x3c7200e9, 0x005f, 0x4ea4, { 0x87, 0xde, 0xa3, 0xdf, 0xac, 0x8a, 0x27, 0xc3 } \   }
end_define

begin_comment
comment|//
end_comment

begin_comment
comment|// Define for forward reference.
end_comment

begin_comment
comment|//
end_comment

begin_typedef
typedef|typedef
name|struct
name|_EFI_SHELL_DYNAMIC_COMMAND_PROTOCOL
name|EFI_SHELL_DYNAMIC_COMMAND_PROTOCOL
typedef|;
end_typedef

begin_comment
comment|/**   This is the shell command handler function pointer callback type.  This   function handles the command when it is invoked in the shell.    @param[in] This                   The instance of the EFI_SHELL_DYNAMIC_COMMAND_PROTOCOL.   @param[in] SystemTable            The pointer to the system table.   @param[in] ShellParameters        The parameters associated with the command.   @param[in] Shell                  The instance of the shell protocol used in the context                                     of processing this command.    @return EFI_SUCCESS               the operation was sucessful   @return other                     the operation failed. **/
end_comment

begin_typedef
typedef|typedef
name|SHELL_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|SHELL_COMMAND_HANDLER
function_decl|)
parameter_list|(
name|IN
name|EFI_SHELL_DYNAMIC_COMMAND_PROTOCOL
modifier|*
name|This
parameter_list|,
name|IN
name|EFI_SYSTEM_TABLE
modifier|*
name|SystemTable
parameter_list|,
name|IN
name|EFI_SHELL_PARAMETERS_PROTOCOL
modifier|*
name|ShellParameters
parameter_list|,
name|IN
name|EFI_SHELL_PROTOCOL
modifier|*
name|Shell
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/**   This is the command help handler function pointer callback type.  This   function is responsible for displaying help information for the associated   command.    @param[in] This                   The instance of the EFI_SHELL_DYNAMIC_COMMAND_PROTOCOL.   @param[in] Language               The pointer to the language string to use.    @return string                    Pool allocated help string, must be freed by caller **/
end_comment

begin_typedef
typedef|typedef
name|CHAR16
modifier|*
function_decl|(
name|EFIAPI
modifier|*
name|SHELL_COMMAND_GETHELP
function_decl|)
parameter_list|(
name|IN
name|EFI_SHELL_DYNAMIC_COMMAND_PROTOCOL
modifier|*
name|This
parameter_list|,
name|IN
name|CONST
name|CHAR8
modifier|*
name|Language
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/// EFI_SHELL_DYNAMIC_COMMAND_PROTOCOL protocol structure.
end_comment

begin_struct
struct|struct
name|_EFI_SHELL_DYNAMIC_COMMAND_PROTOCOL
block|{
name|CONST
name|CHAR16
modifier|*
name|CommandName
decl_stmt|;
name|SHELL_COMMAND_HANDLER
name|Handler
decl_stmt|;
name|SHELL_COMMAND_GETHELP
name|GetHelp
decl_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
specifier|extern
name|EFI_GUID
name|gEfiShellDynamicCommandProtocolGuid
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

