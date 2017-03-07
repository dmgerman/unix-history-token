begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/** @file   This PPI provides the super I/O register access functionality.    Copyright (c) 2015, Intel Corporation. All rights reserved.<BR>   This program and the accompanying materials                             are licensed and made available under the terms and conditions of the BSD License            which accompanies this distribution.  The full text of the license may be found at           http://opensource.org/licenses/bsd-license.php                                                THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN "AS IS" BASIS,                        WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.                 @par Revision Reference:   This PPI is from PI Version 1.2.1.  **/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__EFI_SUPER_IO_PPI_H__
end_ifndef

begin_define
define|#
directive|define
name|__EFI_SUPER_IO_PPI_H__
end_define

begin_include
include|#
directive|include
file|<Protocol/SuperIo.h>
end_include

begin_define
define|#
directive|define
name|EFI_SIO_PPI_GUID
define|\
value|{ \     0x23a464ad, 0xcb83, 0x48b8, {0x94, 0xab, 0x1a, 0x6f, 0xef, 0xcf, 0xe5, 0x22} \   }
end_define

begin_typedef
typedef|typedef
name|struct
name|_EFI_SIO_PPI
name|EFI_SIO_PPI
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|_EFI_SIO_PPI
modifier|*
name|PEFI_SIO_PPI
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|UINT16
name|EFI_SIO_REGISTER
typedef|;
end_typedef

begin_define
define|#
directive|define
name|EFI_SIO_REG
parameter_list|(
name|ldn
parameter_list|,
name|reg
parameter_list|)
value|(EFI_SIO_REGISTER) (((ldn)<< 8) | reg)
end_define

begin_define
define|#
directive|define
name|EFI_SIO_LDN_GLOBAL
value|0xFF
end_define

begin_comment
comment|/**   Read a Super I/O register.     The register is specified as an 8-bit logical device number and an 8-bit   register value. The logical device numbers for specific SIO devices can be   determined using the Info member of the PPI structure.    @param PeiServices  A pointer to a pointer to the PEI Services.   @param This         A pointer to this instance of the EFI_SIO_PPI.   @param ExitCfgMode  A boolean specifying whether the driver should turn on                       configuration mode (FALSE) or turn off configuration mode                       (TRUE) after completing the read operation. The driver must                       track the current state of the configuration mode (if any)                       and turn on configuration mode (if necessary) prior to                       register access.   @param Register     A value specifying the logical device number (bits 15:8)                        and the register to read (bits 7:0). The logical device                        number of EFI_SIO_LDN_GLOBAL indicates that global                       registers will be used.   @param IoData       A pointer to the returned register value.    @retval EFI_SUCCESS            Success.   @retval EFI_TIMEOUT            The register could not be read in the a reasonable                                  amount of time. The exact time is device-specific.   @retval EFI_INVALID_PARAMETERS Register was out of range for this device.   @retval EFI_INVALID_PARAMETERS IoData was NULL   @retval EFI_DEVICE_ERROR       There was a device fault or the device was not present. **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_PEI_SIO_REGISTER_READ
function_decl|)
parameter_list|(
name|IN
name|EFI_PEI_SERVICES
modifier|*
modifier|*
name|PeiServices
parameter_list|,
name|IN
name|CONST
name|EFI_SIO_PPI
modifier|*
name|This
parameter_list|,
name|IN
name|BOOLEAN
name|ExitCfgMode
parameter_list|,
name|IN
name|EFI_SIO_REGISTER
name|Register
parameter_list|,
name|OUT
name|UINT8
modifier|*
name|IoData
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/**   Write a Super I/O register.    The register is specified as an 8-bit logical device number and an 8-bit register   value. The logical device numbers for specific SIO devices can be determined   using the Info member of the PPI structure.    @param PeiServices  A pointer to a pointer to the PEI Services.   @param This         A pointer to this instance of the EFI_SIO_PPI.   @param ExitCfgMode  A boolean specifying whether the driver should turn on                       configuration mode (FALSE) or turn off configuration mode                       (TRUE) after completing the read operation. The driver must                       track the current state of the configuration mode (if any)                       and turn on configuration mode (if necessary) prior to                       register access.   @param Register     A value specifying the logical device number (bits 15:8)                        and the register to read (bits 7:0). The logical device                        number of EFI_SIO_LDN_GLOBAL indicates that global                       registers will be used.   @param IoData       A pointer to the returned register value.    @retval EFI_SUCCESS            Success.   @retval EFI_TIMEOUT            The register could not be read in the a reasonable                                  amount of time. The exact time is device-specific.   @retval EFI_INVALID_PARAMETERS Register was out of range for this device.   @retval EFI_INVALID_PARAMETERS IoData was NULL   @retval EFI_DEVICE_ERROR       There was a device fault or the device was not present. **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_PEI_SIO_REGISTER_WRITE
function_decl|)
parameter_list|(
name|IN
name|EFI_PEI_SERVICES
modifier|*
modifier|*
name|PeiServices
parameter_list|,
name|IN
name|CONST
name|EFI_SIO_PPI
modifier|*
name|This
parameter_list|,
name|IN
name|BOOLEAN
name|ExitCfgMode
parameter_list|,
name|IN
name|EFI_SIO_REGISTER
name|Register
parameter_list|,
name|IN
name|UINT8
name|IoData
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/**   Provides an interface for a table based programming of the Super I/O registers.    The Modify() function provides an interface for table based programming of the   Super I/O registers. This function can be used to perform programming of   multiple Super I/O registers with a single function call. For each table entry,   the Register is read, its content is bitwise ANDed with AndMask, and then ORed   with OrMask before being written back to the Register. The Super I/O driver   must track the current state of the Super I/O and enable the configuration mode   of Super I/O if necessary prior to table processing. Once the table is processed,   the Super I/O device must be returned to the original state.    @param PeiServices      A pointer to a pointer to the PEI Services.   @param This             A pointer to this instance of the EFI_SIO_PPI.   @param Command          A pointer to an array of NumberOfCommands EFI_SIO_REGISTER_MODIFY                           structures. Each structure specifies a single Super I/O register                           modify operation.   @param NumberOfCommands The number of elements in the Command array.    @retval EFI_SUCCESS             The operation completed successfully.   @retval EFI_INVALID_PARAMETERS  Command is NULL. **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_PEI_SIO_REGISTER_MODIFY
function_decl|)
parameter_list|(
name|IN
name|EFI_PEI_SERVICES
modifier|*
modifier|*
name|PeiServices
parameter_list|,
name|IN
name|CONST
name|EFI_SIO_PPI
modifier|*
name|This
parameter_list|,
name|IN
name|CONST
name|EFI_SIO_REGISTER_MODIFY
modifier|*
name|Command
parameter_list|,
name|IN
name|UINTN
name|NumberOfCommands
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// Specifies the end of the information list.
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|EFI_ACPI_PNP_HID_END
value|EFI_PNP_ID (0x0000)
end_define

begin_typedef
typedef|typedef
name|UINT32
name|EFI_ACPI_HID
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|UINT32
name|EFI_ACPI_UID
typedef|;
end_typedef

begin_pragma
pragma|#
directive|pragma
name|pack
name|(
name|1
name|)
end_pragma

begin_typedef
typedef|typedef
struct|struct
name|_EFI_SIO_INFO
block|{
name|EFI_ACPI_HID
name|Hid
decl_stmt|;
name|EFI_ACPI_UID
name|Uid
decl_stmt|;
name|UINT8
name|Ldn
decl_stmt|;
block|}
name|EFI_SIO_INFO
operator|,
typedef|*
name|PEFI_SIO_INFO
typedef|;
end_typedef

begin_pragma
pragma|#
directive|pragma
name|pack
name|(
name|)
end_pragma

begin_comment
comment|///
end_comment

begin_comment
comment|/// This PPI provides low-level access to Super I/O registers using Read() and
end_comment

begin_comment
comment|/// Write(). It also uniquely identifies this Super I/O controller using a GUID
end_comment

begin_comment
comment|/// and provides mappings between ACPI style PNP IDs and the logical device numbers.
end_comment

begin_comment
comment|/// There is one instance of this PPI per Super I/O device.
end_comment

begin_comment
comment|///
end_comment

begin_struct
struct|struct
name|_EFI_SIO_PPI
block|{
comment|///
comment|/// This function reads a register's value from the Super I/O controller.
comment|///
name|EFI_PEI_SIO_REGISTER_READ
name|Read
decl_stmt|;
comment|///
comment|/// This function writes a value to a register in the Super I/O controller.
comment|///
name|EFI_PEI_SIO_REGISTER_WRITE
name|Write
decl_stmt|;
comment|///
comment|/// This function modifies zero or more registers in the Super I/O controller
comment|/// using a table.
comment|///
name|EFI_PEI_SIO_REGISTER_MODIFY
name|Modify
decl_stmt|;
comment|///
comment|/// This GUID uniquely identifies the Super I/O controller.
comment|///
name|EFI_GUID
name|SioGuid
decl_stmt|;
comment|///
comment|/// This pointer is to an array which maps EISA identifiers to logical devices numbers.
comment|///
name|PEFI_SIO_INFO
name|Info
decl_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
specifier|extern
name|EFI_GUID
name|gEfiSioPpiGuid
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

