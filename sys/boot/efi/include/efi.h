begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $FreeBSD$ */
end_comment

begin_comment
comment|/*++  Copyright (c)  1999 - 2002 Intel Corporation. All rights reserved This software and associated documentation (if any) is furnished under a license and may only be used or copied in accordance with the terms of the license. Except as permitted by such license, no part of this software or documentation may be reproduced, stored in a retrieval system, or transmitted in any form or by any means without the express written consent of Intel Corporation.  Module Name:      efi.h  Abstract:      Public EFI header files    Revision History  --*/
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// Build flags on input
end_comment

begin_comment
comment|//  EFI32
end_comment

begin_comment
comment|//  EFI_DEBUG               - Enable debugging code
end_comment

begin_comment
comment|//  EFI_NT_EMULATOR         - Building for running under NT
end_comment

begin_comment
comment|//
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
value|14
end_define

begin_define
define|#
directive|define
name|EFI_FIRMWARE_MINOR_REVISION
value|62
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
file|"efierr.h"
end_include

begin_include
include|#
directive|include
file|"efigop.h"
end_include

begin_define
define|#
directive|define
name|EFI_STRINGIZE
parameter_list|(
name|a
parameter_list|)
value|#a
end_define

begin_define
define|#
directive|define
name|EFI_PROTOCOL_DEFINITION
parameter_list|(
name|a
parameter_list|)
value|EFI_STRINGIZE(Protocol/a/a.h)
end_define

begin_define
define|#
directive|define
name|EFI_GUID_DEFINITION
parameter_list|(
name|a
parameter_list|)
value|EFI_STRINGIZE(Guid/a/a##.h)
end_define

begin_define
define|#
directive|define
name|EFI_GUID_STRING
parameter_list|(
name|guidpointer
parameter_list|,
name|shortstring
parameter_list|,
name|longstring
parameter_list|)
end_define

begin_endif
endif|#
directive|endif
end_endif

end_unit

