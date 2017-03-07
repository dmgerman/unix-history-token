begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/** @file   Include file of PciSegmentPciRootBridgeIo Library.    Copyright (c) 2007 - 2009, Intel Corporation. All rights reserved.<BR>   This program and the accompanying materials are   licensed and made available under the terms and conditions of   the BSD License which accompanies this distribution.  The full   text of the license may be found at   http://opensource.org/licenses/bsd-license.php.      THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN "AS IS" BASIS,   WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.  **/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__DXE_PCI_SEGMENT_LIB__
end_ifndef

begin_define
define|#
directive|define
name|__DXE_PCI_SEGMENT_LIB__
end_define

begin_include
include|#
directive|include
file|<PiDxe.h>
end_include

begin_include
include|#
directive|include
file|<Protocol/PciRootBridgeIo.h>
end_include

begin_include
include|#
directive|include
file|<Library/PciSegmentLib.h>
end_include

begin_include
include|#
directive|include
file|<Library/BaseLib.h>
end_include

begin_include
include|#
directive|include
file|<Library/MemoryAllocationLib.h>
end_include

begin_include
include|#
directive|include
file|<Library/UefiBootServicesTableLib.h>
end_include

begin_include
include|#
directive|include
file|<Library/DebugLib.h>
end_include

begin_include
include|#
directive|include
file|<IndustryStandard/Acpi.h>
end_include

begin_typedef
typedef|typedef
struct|struct
block|{
name|EFI_PCI_ROOT_BRIDGE_IO_PROTOCOL
modifier|*
name|PciRootBridgeIo
decl_stmt|;
name|UINT32
name|SegmentNumber
decl_stmt|;
name|UINT64
name|MinBusNumber
decl_stmt|;
name|UINT64
name|MaxBusNumber
decl_stmt|;
block|}
name|PCI_ROOT_BRIDGE_DATA
typedef|;
end_typedef

begin_comment
comment|/**   Assert the validity of a PCI Segment address.   A valid PCI Segment address should not contain 1's in bits 28..31 and 48..63    @param  A The address to validate.   @param  M Additional bits to assert to be zero.  **/
end_comment

begin_define
define|#
directive|define
name|ASSERT_INVALID_PCI_SEGMENT_ADDRESS
parameter_list|(
name|A
parameter_list|,
name|M
parameter_list|)
define|\
value|ASSERT (((A)& (0xffff0000f0000000ULL | (M))) == 0)
end_define

begin_comment
comment|/**   Translate PCI Lib address into format of PCI Root Bridge I/O Protocol    @param  A  The address that encodes the PCI Bus, Device, Function and              Register.  **/
end_comment

begin_define
define|#
directive|define
name|PCI_TO_PCI_ROOT_BRIDGE_IO_ADDRESS
parameter_list|(
name|A
parameter_list|)
define|\
value|((((UINT32)(A)<< 4)& 0xff000000) | (((UINT32)(A)>> 4)& 0x00000700) | (((UINT32)(A)<< 1)& 0x001f0000) | (LShiftU64((A)& 0xfff, 32)))
end_define

begin_endif
endif|#
directive|endif
end_endif

end_unit

