begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/** @file   This file declares PciCfg2 PPI.    This ppi Provides platform or chipset-specific access to    the PCI configuration space for a specific PCI segment.    Copyright (c) 2006 - 2011, Intel Corporation. All rights reserved.<BR>   This program and the accompanying materials   are licensed and made available under the terms and conditions of the BSD License   which accompanies this distribution.  The full text of the license may be found at   http://opensource.org/licenses/bsd-license.php    THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN "AS IS" BASIS,   WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.    @par Revision Reference:   This PPI is introduced in PI Version 1.0.  **/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__PEI_PCI_CFG2_H__
end_ifndef

begin_define
define|#
directive|define
name|__PEI_PCI_CFG2_H__
end_define

begin_include
include|#
directive|include
file|<Library/BaseLib.h>
end_include

begin_define
define|#
directive|define
name|EFI_PEI_PCI_CFG2_PPI_GUID
define|\
value|{ 0x57a449a, 0x1fdc, 0x4c06, { 0xbf, 0xc9, 0xf5, 0x3f, 0x6a, 0x99, 0xbb, 0x92 } }
end_define

begin_typedef
typedef|typedef
name|struct
name|_EFI_PEI_PCI_CFG2_PPI
name|EFI_PEI_PCI_CFG2_PPI
typedef|;
end_typedef

begin_define
define|#
directive|define
name|EFI_PEI_PCI_CFG_ADDRESS
parameter_list|(
name|bus
parameter_list|,
name|dev
parameter_list|,
name|func
parameter_list|,
name|reg
parameter_list|)
define|\
value|(UINT64) ( \   (((UINTN) bus)<< 24) | \   (((UINTN) dev)<< 16) | \   (((UINTN) func)<< 8) | \   (((UINTN) (reg))< 256 ? ((UINTN) (reg)) : (UINT64) (LShiftU64 ((UINT64) (reg), 32))))
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// EFI_PEI_PCI_CFG_PPI_WIDTH
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
enum|enum
block|{
comment|///
comment|///  8-bit access
comment|///
name|EfiPeiPciCfgWidthUint8
init|=
literal|0
block|,
comment|///
comment|/// 16-bit access
comment|///
name|EfiPeiPciCfgWidthUint16
init|=
literal|1
block|,
comment|///
comment|/// 32-bit access
comment|///
name|EfiPeiPciCfgWidthUint32
init|=
literal|2
block|,
comment|///
comment|/// 64-bit access
comment|///
name|EfiPeiPciCfgWidthUint64
init|=
literal|3
block|,
name|EfiPeiPciCfgWidthMaximum
block|}
name|EFI_PEI_PCI_CFG_PPI_WIDTH
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// EFI_PEI_PCI_CFG_PPI_PCI_ADDRESS
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
comment|///
comment|/// 8-bit register offset within the PCI configuration space for a given device's function
comment|/// space.
comment|///
name|UINT8
name|Register
decl_stmt|;
comment|///
comment|/// Only the 3 least-significant bits are used to encode one of 8 possible functions within a
comment|/// given device.
comment|///
name|UINT8
name|Function
decl_stmt|;
comment|///
comment|/// Only the 5 least-significant bits are used to encode one of 32 possible devices.
comment|///
name|UINT8
name|Device
decl_stmt|;
comment|///
comment|/// 8-bit value to encode between 0 and 255 buses.
comment|///
name|UINT8
name|Bus
decl_stmt|;
comment|///
comment|/// Register number in PCI configuration space. If this field is zero, then Register is used
comment|/// for the register number. If this field is non-zero, then Register is ignored and this field
comment|/// is used for the register number.
comment|///
name|UINT32
name|ExtendedRegister
decl_stmt|;
block|}
name|EFI_PEI_PCI_CFG_PPI_PCI_ADDRESS
typedef|;
end_typedef

begin_comment
comment|/**   Reads from or write to a given location in the PCI configuration space.    @param  PeiServices     An indirect pointer to the PEI Services Table published by the PEI Foundation.    @param  This            Pointer to local data for the interface.    @param  Width           The width of the access. Enumerated in bytes.                           See EFI_PEI_PCI_CFG_PPI_WIDTH above.    @param  Address         The physical address of the access. The format of                           the address is described by EFI_PEI_PCI_CFG_PPI_PCI_ADDRESS.    @param  Buffer          A pointer to the buffer of data..     @retval EFI_SUCCESS           The function completed successfully.    @retval EFI_DEVICE_ERROR      There was a problem with the transaction.    @retval EFI_DEVICE_NOT_READY  The device is not capable of supporting the operation at this                                 time.  **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_PEI_PCI_CFG2_PPI_IO
function_decl|)
parameter_list|(
name|IN
name|CONST
name|EFI_PEI_SERVICES
modifier|*
modifier|*
name|PeiServices
parameter_list|,
name|IN
name|CONST
name|EFI_PEI_PCI_CFG2_PPI
modifier|*
name|This
parameter_list|,
name|IN
name|EFI_PEI_PCI_CFG_PPI_WIDTH
name|Width
parameter_list|,
name|IN
name|UINT64
name|Address
parameter_list|,
name|IN
name|OUT
name|VOID
modifier|*
name|Buffer
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/**   Performs a read-modify-write operation on the contents    from a given location in the PCI configuration space.    @param  PeiServices     An indirect pointer to the PEI Services Table                           published by the PEI Foundation.    @param  This            Pointer to local data for the interface.    @param  Width           The width of the access. Enumerated in bytes. Type                           EFI_PEI_PCI_CFG_PPI_WIDTH is defined in Read().    @param  Address         The physical address of the access.    @param  SetBits         Points to value to bitwise-OR with the read configuration value.                            The size of the value is determined by Width.    @param  ClearBits       Points to the value to negate and bitwise-AND with the read configuration value.                           The size of the value is determined by Width.     @retval EFI_SUCCESS           The function completed successfully.    @retval EFI_DEVICE_ERROR      There was a problem with the transaction.    @retval EFI_DEVICE_NOT_READY  The device is not capable of supporting                                 the operation at this time.  **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_PEI_PCI_CFG2_PPI_RW
function_decl|)
parameter_list|(
name|IN
name|CONST
name|EFI_PEI_SERVICES
modifier|*
modifier|*
name|PeiServices
parameter_list|,
name|IN
name|CONST
name|EFI_PEI_PCI_CFG2_PPI
modifier|*
name|This
parameter_list|,
name|IN
name|EFI_PEI_PCI_CFG_PPI_WIDTH
name|Width
parameter_list|,
name|IN
name|UINT64
name|Address
parameter_list|,
name|IN
name|VOID
modifier|*
name|SetBits
parameter_list|,
name|IN
name|VOID
modifier|*
name|ClearBits
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// The EFI_PEI_PCI_CFG_PPI interfaces are used to abstract accesses to PCI
end_comment

begin_comment
comment|/// controllers behind a PCI root bridge controller.
end_comment

begin_comment
comment|///
end_comment

begin_struct
struct|struct
name|_EFI_PEI_PCI_CFG2_PPI
block|{
name|EFI_PEI_PCI_CFG2_PPI_IO
name|Read
decl_stmt|;
name|EFI_PEI_PCI_CFG2_PPI_IO
name|Write
decl_stmt|;
name|EFI_PEI_PCI_CFG2_PPI_RW
name|Modify
decl_stmt|;
comment|///
comment|/// The PCI bus segment which the specified functions will access.
comment|///
name|UINT16
name|Segment
decl_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
specifier|extern
name|EFI_GUID
name|gEfiPciCfg2PpiGuid
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

