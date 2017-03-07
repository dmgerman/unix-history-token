begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/** @file      Common header file shared by all source files.    This file includes package header files, library classes and protocol, PPI& GUID definitions.    Copyright (c) 2006 - 2008, Intel Corporation. All rights reserved.<BR>    This program and the accompanying materials    are licensed and made available under the terms and conditions of the BSD License    which accompanies this distribution. The full text of the license may be found at    http://opensource.org/licenses/bsd-license.php.    THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN "AS IS" BASIS,    WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED. **/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_UEFI_USB_LIB_INTERNAL_H_
end_ifndef

begin_define
define|#
directive|define
name|_UEFI_USB_LIB_INTERNAL_H_
end_define

begin_include
include|#
directive|include
file|<Uefi.h>
end_include

begin_include
include|#
directive|include
file|<Library/UefiUsbLib.h>
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
file|<Library/PcdLib.h>
end_include

begin_include
include|#
directive|include
file|<IndustryStandard/Usb.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

end_unit

