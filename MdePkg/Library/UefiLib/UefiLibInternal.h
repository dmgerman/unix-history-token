begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/** @file   Internal include file for UefiLib.    Copyright (c) 2007 - 2017, Intel Corporation. All rights reserved.<BR>    This program and the accompanying materials    are licensed and made available under the terms and conditions of the BSD License    which accompanies this distribution. The full text of the license may be found at    http://opensource.org/licenses/bsd-license.php.    THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN "AS IS" BASIS,    WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED. **/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__UEFI_LIB_INTERNAL_H_
end_ifndef

begin_define
define|#
directive|define
name|__UEFI_LIB_INTERNAL_H_
end_define

begin_include
include|#
directive|include
file|<Uefi.h>
end_include

begin_include
include|#
directive|include
file|<Protocol/DriverBinding.h>
end_include

begin_include
include|#
directive|include
file|<Protocol/ComponentName.h>
end_include

begin_include
include|#
directive|include
file|<Protocol/ComponentName2.h>
end_include

begin_include
include|#
directive|include
file|<Protocol/DriverConfiguration.h>
end_include

begin_include
include|#
directive|include
file|<Protocol/DriverConfiguration2.h>
end_include

begin_include
include|#
directive|include
file|<Protocol/DriverDiagnostics.h>
end_include

begin_include
include|#
directive|include
file|<Protocol/DriverDiagnostics2.h>
end_include

begin_include
include|#
directive|include
file|<Protocol/LoadedImage.h>
end_include

begin_include
include|#
directive|include
file|<Protocol/GraphicsOutput.h>
end_include

begin_include
include|#
directive|include
file|<Protocol/UgaDraw.h>
end_include

begin_include
include|#
directive|include
file|<Protocol/HiiFont.h>
end_include

begin_include
include|#
directive|include
file|<Guid/EventGroup.h>
end_include

begin_include
include|#
directive|include
file|<Guid/EventLegacyBios.h>
end_include

begin_include
include|#
directive|include
file|<Guid/GlobalVariable.h>
end_include

begin_include
include|#
directive|include
file|<Library/UefiLib.h>
end_include

begin_include
include|#
directive|include
file|<Library/UefiBootServicesTableLib.h>
end_include

begin_include
include|#
directive|include
file|<Library/UefiRuntimeServicesTableLib.h>
end_include

begin_include
include|#
directive|include
file|<Library/BaseLib.h>
end_include

begin_include
include|#
directive|include
file|<Library/BaseMemoryLib.h>
end_include

begin_include
include|#
directive|include
file|<Library/DebugLib.h>
end_include

begin_include
include|#
directive|include
file|<Library/MemoryAllocationLib.h>
end_include

begin_include
include|#
directive|include
file|<Library/PcdLib.h>
end_include

begin_include
include|#
directive|include
file|<Library/PrintLib.h>
end_include

begin_include
include|#
directive|include
file|<Library/DevicePathLib.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

end_unit

