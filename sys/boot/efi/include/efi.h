begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $FreeBSD$ */
end_comment

begin_comment
comment|/*++  Copyright (c) 1998  Intel Corporation  Module Name:      efi.h  Abstract:      Public EFI header files    Revision History  --*/
end_comment

begin_comment
comment|/*  * Build flags on input  *  EFI32  *  EFI_DEBUG               - Enable debugging code  *  EFI_NT_EMULATOR         - Building for running under NT  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_EFI_INCLUDE_
end_ifndef

begin_define
define|#
directive|define
name|_EFI_INCLUDE_
end_define

begin_define
define|#
directive|define
name|EFI_FIRMWARE_VENDOR
value|L"INTEL"
end_define

begin_define
define|#
directive|define
name|EFI_FIRMWARE_MAJOR_REVISION
value|12
end_define

begin_define
define|#
directive|define
name|EFI_FIRMWARE_MINOR_REVISION
value|33
end_define

begin_define
define|#
directive|define
name|EFI_FIRMWARE_REVISION
value|((EFI_FIRMWARE_MAJOR_REVISION<<16) | (EFI_FIRMWARE_MINOR_REVISION))
end_define

begin_include
include|#
directive|include
file|"efibind.h"
end_include

begin_include
include|#
directive|include
file|"efidef.h"
end_include

begin_include
include|#
directive|include
file|"efidevp.h"
end_include

begin_include
include|#
directive|include
file|"efiprot.h"
end_include

begin_include
include|#
directive|include
file|"eficon.h"
end_include

begin_include
include|#
directive|include
file|"efiser.h"
end_include

begin_include
include|#
directive|include
file|"efi_nii.h"
end_include

begin_include
include|#
directive|include
file|"efipxebc.h"
end_include

begin_include
include|#
directive|include
file|"efinet.h"
end_include

begin_include
include|#
directive|include
file|"efiapi.h"
end_include

begin_include
include|#
directive|include
file|"efifs.h"
end_include

begin_include
include|#
directive|include
file|"efifpswa.h"
end_include

begin_include
include|#
directive|include
file|"efierr.h"
end_include

begin_endif
endif|#
directive|endif
end_endif

end_unit

