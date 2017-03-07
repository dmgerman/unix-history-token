begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/** @file   EFI Shell protocol as defined in the UEFI Shell 2.0 specification.    Copyright (c) 2006 - 2016, Intel Corporation. All rights reserved.<BR>   This program and the accompanying materials   are licensed and made available under the terms and conditions of the BSD License   which accompanies this distribution.  The full text of the license may be found at   http://opensource.org/licenses/bsd-license.php    THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN "AS IS" BASIS,   WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.  **/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__EFI_SHELL_PARAMETERS_PROTOCOL_H__
end_ifndef

begin_define
define|#
directive|define
name|__EFI_SHELL_PARAMETERS_PROTOCOL_H__
end_define

begin_include
include|#
directive|include
file|<Protocol/Shell.h>
end_include

begin_define
define|#
directive|define
name|EFI_SHELL_PARAMETERS_PROTOCOL_GUID
define|\
value|{ \   0x752f3136, 0x4e16, 0x4fdc, { 0xa2, 0x2a, 0xe5, 0xf4, 0x68, 0x12, 0xf4, 0xca } \   }
end_define

begin_typedef
typedef|typedef
struct|struct
name|_EFI_SHELL_PARAMETERS_PROTOCOL
block|{
comment|///
comment|/// Points to an Argc-element array of points to NULL-terminated strings containing
comment|/// the command-line parameters. The first entry in the array is always the full file
comment|/// path of the executable. Any quotation marks that were used to preserve
comment|/// whitespace have been removed.
comment|///
name|CHAR16
modifier|*
modifier|*
name|Argv
decl_stmt|;
comment|///
comment|/// The number of elements in the Argv array.
comment|///
name|UINTN
name|Argc
decl_stmt|;
comment|///
comment|/// The file handle for the standard input for this executable. This may be different
comment|/// from the ConInHandle in EFI_SYSTEM_TABLE.
comment|///
name|SHELL_FILE_HANDLE
name|StdIn
decl_stmt|;
comment|///
comment|/// The file handle for the standard output for this executable. This may be different
comment|/// from the ConOutHandle in EFI_SYSTEM_TABLE.
comment|///
name|SHELL_FILE_HANDLE
name|StdOut
decl_stmt|;
comment|///
comment|/// The file handle for the standard error output for this executable. This may be
comment|/// different from the StdErrHandle in EFI_SYSTEM_TABLE.
comment|///
name|SHELL_FILE_HANDLE
name|StdErr
decl_stmt|;
block|}
name|EFI_SHELL_PARAMETERS_PROTOCOL
typedef|;
end_typedef

begin_decl_stmt
specifier|extern
name|EFI_GUID
name|gEfiShellParametersProtocolGuid
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

