begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/** @file   Provides the basic interfaces to abstract platform information regarding an    IDE controller.      Copyright (c) 2006 - 2014, Intel Corporation. All rights reserved.<BR>   This program and the accompanying materials   are licensed and made available under the terms and conditions of the BSD License   which accompanies this distribution.  The full text of the license may be found at   http://opensource.org/licenses/bsd-license.php    THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN "AS IS" BASIS,   WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.    @par Revision Reference:   This Protocol is defined in UEFI Platform Initialization Specification 1.2    Volume 5: Standards    **/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__DISK_INFO_H__
end_ifndef

begin_define
define|#
directive|define
name|__DISK_INFO_H__
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// Global ID for EFI_DISK_INFO_PROTOCOL
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|EFI_DISK_INFO_PROTOCOL_GUID
define|\
value|{ \     0xd432a67f, 0x14dc, 0x484b, {0xb3, 0xbb, 0x3f, 0x2, 0x91, 0x84, 0x93, 0x27 } \   }
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// Forward declaration for EFI_DISK_INFO_PROTOCOL
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
name|struct
name|_EFI_DISK_INFO_PROTOCOL
name|EFI_DISK_INFO_PROTOCOL
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// Global ID for an IDE interface.  Used to fill in EFI_DISK_INFO_PROTOCOL.Interface
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|EFI_DISK_INFO_IDE_INTERFACE_GUID
define|\
value|{ \     0x5e948fe3, 0x26d3, 0x42b5, {0xaf, 0x17, 0x61, 0x2, 0x87, 0x18, 0x8d, 0xec } \   }
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// Global ID for a SCSI interface.  Used to fill in EFI_DISK_INFO_PROTOCOL.Interface
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|EFI_DISK_INFO_SCSI_INTERFACE_GUID
define|\
value|{ \     0x8f74baa, 0xea36, 0x41d9, {0x95, 0x21, 0x21, 0xa7, 0xf, 0x87, 0x80, 0xbc } \   }
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// Global ID for a USB interface.  Used to fill in EFI_DISK_INFO_PROTOCOL.Interface
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|EFI_DISK_INFO_USB_INTERFACE_GUID
define|\
value|{ \     0xcb871572, 0xc11a, 0x47b5, {0xb4, 0x92, 0x67, 0x5e, 0xaf, 0xa7, 0x77, 0x27 } \   }
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// Global ID for an AHCI interface.  Used to fill in EFI_DISK_INFO_PROTOCOL.Interface
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|EFI_DISK_INFO_AHCI_INTERFACE_GUID
define|\
value|{ \     0x9e498932, 0x4abc, 0x45af, {0xa3, 0x4d, 0x2, 0x47, 0x78, 0x7b, 0xe7, 0xc6 } \   }
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// Global ID for a NVME interface.  Used to fill in EFI_DISK_INFO_PROTOCOL.Interface
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|EFI_DISK_INFO_NVME_INTERFACE_GUID
define|\
value|{ \     0x3ab14680, 0x5d3f, 0x4a4d, {0xbc, 0xdc, 0xcc, 0x38, 0x0, 0x18, 0xc7, 0xf7 } \   }
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// Global ID for a UFS interface.  Used to fill in EFI_DISK_INFO_PROTOCOL.Interface
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|EFI_DISK_INFO_UFS_INTERFACE_GUID
define|\
value|{ \     0x4b3029cc, 0x6b98, 0x47fb, { 0xbc, 0x96, 0x76, 0xdc, 0xb8, 0x4, 0x41, 0xf0 } \   }
end_define

begin_comment
comment|/**   Provides inquiry information for the controller type.      This function is used by the IDE bus driver to get inquiry data.  Data format   of Identify data is defined by the Interface GUID.    @param[in]     This              Pointer to the EFI_DISK_INFO_PROTOCOL instance.   @param[in,out] InquiryData       Pointer to a buffer for the inquiry data.   @param[in,out] InquiryDataSize   Pointer to the value for the inquiry data size.    @retval EFI_SUCCESS            The command was accepted without any errors.   @retval EFI_NOT_FOUND          Device does not support this data class    @retval EFI_DEVICE_ERROR       Error reading InquiryData from device    @retval EFI_BUFFER_TOO_SMALL   InquiryDataSize not big enough   **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_DISK_INFO_INQUIRY
function_decl|)
parameter_list|(
name|IN
name|EFI_DISK_INFO_PROTOCOL
modifier|*
name|This
parameter_list|,
name|IN
name|OUT
name|VOID
modifier|*
name|InquiryData
parameter_list|,
name|IN
name|OUT
name|UINT32
modifier|*
name|InquiryDataSize
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/**   Provides identify information for the controller type.    This function is used by the IDE bus driver to get identify data.  Data format   of Identify data is defined by the Interface GUID.    @param[in]     This               Pointer to the EFI_DISK_INFO_PROTOCOL                                      instance.   @param[in,out] IdentifyData       Pointer to a buffer for the identify data.   @param[in,out] IdentifyDataSize   Pointer to the value for the identify data                                     size.    @retval EFI_SUCCESS            The command was accepted without any errors.   @retval EFI_NOT_FOUND          Device does not support this data class    @retval EFI_DEVICE_ERROR       Error reading IdentifyData from device    @retval EFI_BUFFER_TOO_SMALL   IdentifyDataSize not big enough   **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_DISK_INFO_IDENTIFY
function_decl|)
parameter_list|(
name|IN
name|EFI_DISK_INFO_PROTOCOL
modifier|*
name|This
parameter_list|,
name|IN
name|OUT
name|VOID
modifier|*
name|IdentifyData
parameter_list|,
name|IN
name|OUT
name|UINT32
modifier|*
name|IdentifyDataSize
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/**   Provides sense data information for the controller type.      This function is used by the IDE bus driver to get sense data.    Data format of Sense data is defined by the Interface GUID.    @param[in]     This              Pointer to the EFI_DISK_INFO_PROTOCOL instance.   @param[in,out] SenseData         Pointer to the SenseData.   @param[in,out] SenseDataSize     Size of SenseData in bytes.   @param[out]    SenseDataNumber   Pointer to the value for the sense data size.    @retval EFI_SUCCESS            The command was accepted without any errors.   @retval EFI_NOT_FOUND          Device does not support this data class.   @retval EFI_DEVICE_ERROR       Error reading SenseData from device.   @retval EFI_BUFFER_TOO_SMALL   SenseDataSize not big enough.  **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_DISK_INFO_SENSE_DATA
function_decl|)
parameter_list|(
name|IN
name|EFI_DISK_INFO_PROTOCOL
modifier|*
name|This
parameter_list|,
name|IN
name|OUT
name|VOID
modifier|*
name|SenseData
parameter_list|,
name|IN
name|OUT
name|UINT32
modifier|*
name|SenseDataSize
parameter_list|,
name|OUT
name|UINT8
modifier|*
name|SenseDataNumber
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/**   This function is used by the IDE bus driver to get controller information.    @param[in]  This         Pointer to the EFI_DISK_INFO_PROTOCOL instance.    @param[out] IdeChannel   Pointer to the Ide Channel number.  Primary or secondary.   @param[out] IdeDevice    Pointer to the Ide Device number.  Master or slave.    @retval EFI_SUCCESS       IdeChannel and IdeDevice are valid.   @retval EFI_UNSUPPORTED   This is not an IDE device.  **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_DISK_INFO_WHICH_IDE
function_decl|)
parameter_list|(
name|IN
name|EFI_DISK_INFO_PROTOCOL
modifier|*
name|This
parameter_list|,
name|OUT
name|UINT32
modifier|*
name|IdeChannel
parameter_list|,
name|OUT
name|UINT32
modifier|*
name|IdeDevice
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// The EFI_DISK_INFO_PROTOCOL provides controller specific information.
end_comment

begin_comment
comment|///
end_comment

begin_struct
struct|struct
name|_EFI_DISK_INFO_PROTOCOL
block|{
comment|///
comment|/// A GUID that defines the format of buffers for the other member functions
comment|/// of this protocol.
comment|///
name|EFI_GUID
name|Interface
decl_stmt|;
comment|///
comment|/// Return the results of the Inquiry command to a drive in InquiryData. Data
comment|/// format of Inquiry data is defined by the Interface GUID.
comment|///
name|EFI_DISK_INFO_INQUIRY
name|Inquiry
decl_stmt|;
comment|///
comment|/// Return the results of the Identify command to a drive in IdentifyData. Data
comment|/// format of Identify data is defined by the Interface GUID.
comment|///
name|EFI_DISK_INFO_IDENTIFY
name|Identify
decl_stmt|;
comment|///
comment|/// Return the results of the Request Sense command to a drive in SenseData. Data
comment|/// format of Sense data is defined by the Interface GUID.
comment|///
name|EFI_DISK_INFO_SENSE_DATA
name|SenseData
decl_stmt|;
comment|///
comment|/// Specific controller.
comment|///
name|EFI_DISK_INFO_WHICH_IDE
name|WhichIde
decl_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
specifier|extern
name|EFI_GUID
name|gEfiDiskInfoProtocolGuid
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|EFI_GUID
name|gEfiDiskInfoIdeInterfaceGuid
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|EFI_GUID
name|gEfiDiskInfoScsiInterfaceGuid
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|EFI_GUID
name|gEfiDiskInfoUsbInterfaceGuid
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|EFI_GUID
name|gEfiDiskInfoAhciInterfaceGuid
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|EFI_GUID
name|gEfiDiskInfoNvmeInterfaceGuid
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|EFI_GUID
name|gEfiDiskInfoUfsInterfaceGuid
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

