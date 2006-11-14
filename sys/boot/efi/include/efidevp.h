begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $FreeBSD$ */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_DEVPATH_H
end_ifndef

begin_define
define|#
directive|define
name|_DEVPATH_H
end_define

begin_comment
comment|/*++  Copyright (c) 1998  Intel Corporation  Module Name:      devpath.h  Abstract:      Defines for parsing the EFI Device Path structures    Revision History  --*/
end_comment

begin_comment
comment|/*  * Device Path structures - Section C  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_EFI_DEVICE_PATH
block|{
name|UINT8
name|Type
decl_stmt|;
name|UINT8
name|SubType
decl_stmt|;
name|UINT8
name|Length
index|[
literal|2
index|]
decl_stmt|;
block|}
name|EFI_DEVICE_PATH
typedef|;
end_typedef

begin_define
define|#
directive|define
name|EFI_DP_TYPE_MASK
value|0x7F
end_define

begin_define
define|#
directive|define
name|EFI_DP_TYPE_UNPACKED
value|0x80
end_define

begin_define
define|#
directive|define
name|END_DEVICE_PATH_TYPE
value|0x7f
end_define

begin_define
define|#
directive|define
name|END_ENTIRE_DEVICE_PATH_SUBTYPE
value|0xff
end_define

begin_define
define|#
directive|define
name|END_INSTANCE_DEVICE_PATH_SUBTYPE
value|0x01
end_define

begin_define
define|#
directive|define
name|END_DEVICE_PATH_LENGTH
value|(sizeof(EFI_DEVICE_PATH))
end_define

begin_define
define|#
directive|define
name|DP_IS_END_TYPE
parameter_list|(
name|a
parameter_list|)
end_define

begin_define
define|#
directive|define
name|DP_IS_END_SUBTYPE
parameter_list|(
name|a
parameter_list|)
value|( ((a)->SubType == END_ENTIRE_DEVICE_PATH_SUBTYPE )
end_define

begin_define
define|#
directive|define
name|DevicePathType
parameter_list|(
name|a
parameter_list|)
value|( ((a)->Type)& EFI_DP_TYPE_MASK )
end_define

begin_define
define|#
directive|define
name|DevicePathSubType
parameter_list|(
name|a
parameter_list|)
value|( (a)->SubType )
end_define

begin_define
define|#
directive|define
name|DevicePathNodeLength
parameter_list|(
name|a
parameter_list|)
value|( ((a)->Length[0]) | ((a)->Length[1]<< 8) )
end_define

begin_define
define|#
directive|define
name|NextDevicePathNode
parameter_list|(
name|a
parameter_list|)
value|( (EFI_DEVICE_PATH *) ( ((UINT8 *) (a)) + DevicePathNodeLength(a)))
end_define

begin_define
define|#
directive|define
name|IsDevicePathEndType
parameter_list|(
name|a
parameter_list|)
value|( DevicePathType(a) == END_DEVICE_PATH_TYPE )
end_define

begin_define
define|#
directive|define
name|IsDevicePathEndSubType
parameter_list|(
name|a
parameter_list|)
value|( (a)->SubType == END_ENTIRE_DEVICE_PATH_SUBTYPE )
end_define

begin_define
define|#
directive|define
name|IsDevicePathEnd
parameter_list|(
name|a
parameter_list|)
value|( IsDevicePathEndType(a)&& IsDevicePathEndSubType(a) )
end_define

begin_define
define|#
directive|define
name|IsDevicePathUnpacked
parameter_list|(
name|a
parameter_list|)
value|( (a)->Type& EFI_DP_TYPE_UNPACKED )
end_define

begin_define
define|#
directive|define
name|SetDevicePathNodeLength
parameter_list|(
name|a
parameter_list|,
name|l
parameter_list|)
value|{                  \             (a)->Length[0] = (UINT8) (l);               \             (a)->Length[1] = (UINT8) ((l)>> 8);        \             }
end_define

begin_define
define|#
directive|define
name|SetDevicePathEndNode
parameter_list|(
name|a
parameter_list|)
value|{                      \             (a)->Type = END_DEVICE_PATH_TYPE;           \             (a)->SubType = END_ENTIRE_DEVICE_PATH_SUBTYPE;     \             (a)->Length[0] = sizeof(EFI_DEVICE_PATH);   \             (a)->Length[1] = 0;                         \             }
end_define

begin_comment
comment|/*  *  */
end_comment

begin_define
define|#
directive|define
name|HARDWARE_DEVICE_PATH
value|0x01
end_define

begin_define
define|#
directive|define
name|HW_PCI_DP
value|0x01
end_define

begin_typedef
typedef|typedef
struct|struct
name|_PCI_DEVICE_PATH
block|{
name|EFI_DEVICE_PATH
name|Header
decl_stmt|;
name|UINT8
name|Function
decl_stmt|;
name|UINT8
name|Device
decl_stmt|;
block|}
name|PCI_DEVICE_PATH
typedef|;
end_typedef

begin_define
define|#
directive|define
name|HW_PCCARD_DP
value|0x02
end_define

begin_typedef
typedef|typedef
struct|struct
name|_PCCARD_DEVICE_PATH
block|{
name|EFI_DEVICE_PATH
name|Header
decl_stmt|;
name|UINT8
name|SocketNumber
decl_stmt|;
block|}
name|PCCARD_DEVICE_PATH
typedef|;
end_typedef

begin_define
define|#
directive|define
name|HW_MEMMAP_DP
value|0x03
end_define

begin_typedef
typedef|typedef
struct|struct
name|_MEMMAP_DEVICE_PATH
block|{
name|EFI_DEVICE_PATH
name|Header
decl_stmt|;
name|UINT32
name|MemoryType
decl_stmt|;
name|EFI_PHYSICAL_ADDRESS
name|StartingAddress
decl_stmt|;
name|EFI_PHYSICAL_ADDRESS
name|EndingAddress
decl_stmt|;
block|}
name|MEMMAP_DEVICE_PATH
typedef|;
end_typedef

begin_define
define|#
directive|define
name|HW_VENDOR_DP
value|0x04
end_define

begin_typedef
typedef|typedef
struct|struct
name|_VENDOR_DEVICE_PATH
block|{
name|EFI_DEVICE_PATH
name|Header
decl_stmt|;
name|EFI_GUID
name|Guid
decl_stmt|;
block|}
name|VENDOR_DEVICE_PATH
typedef|;
end_typedef

begin_define
define|#
directive|define
name|UNKNOWN_DEVICE_GUID
define|\
value|{ 0xcf31fac5, 0xc24e, 0x11d2,  0x85, 0xf3, 0x0, 0xa0, 0xc9, 0x3e, 0xc9, 0x3b  }
end_define

begin_typedef
typedef|typedef
struct|struct
name|_UKNOWN_DEVICE_VENDOR_DP
block|{
name|VENDOR_DEVICE_PATH
name|DevicePath
decl_stmt|;
name|UINT8
name|LegacyDriveLetter
decl_stmt|;
block|}
name|UNKNOWN_DEVICE_VENDOR_DEVICE_PATH
typedef|;
end_typedef

begin_define
define|#
directive|define
name|HW_CONTROLLER_DP
value|0x05
end_define

begin_typedef
typedef|typedef
struct|struct
name|_CONTROLLER_DEVICE_PATH
block|{
name|EFI_DEVICE_PATH
name|Header
decl_stmt|;
name|UINT32
name|Controller
decl_stmt|;
block|}
name|CONTROLLER_DEVICE_PATH
typedef|;
end_typedef

begin_comment
comment|/*  *  */
end_comment

begin_define
define|#
directive|define
name|ACPI_DEVICE_PATH
value|0x02
end_define

begin_define
define|#
directive|define
name|ACPI_DP
value|0x01
end_define

begin_typedef
typedef|typedef
struct|struct
name|_ACPI_HID_DEVICE_PATH
block|{
name|EFI_DEVICE_PATH
name|Header
decl_stmt|;
name|UINT32
name|HID
decl_stmt|;
name|UINT32
name|UID
decl_stmt|;
block|}
name|ACPI_HID_DEVICE_PATH
typedef|;
end_typedef

begin_comment
comment|/*  * EISA ID Macro  * EISA ID Definition 32-bits  *  bits[15:0] - three character compressed ASCII EISA ID.  *  bits[31:16] - binary number  *   Compressed ASCII is 5 bits per character 0b00001 = 'A' 0b11010 = 'Z'  */
end_comment

begin_define
define|#
directive|define
name|PNP_EISA_ID_CONST
value|0x41d0
end_define

begin_define
define|#
directive|define
name|EISA_ID
parameter_list|(
name|_Name
parameter_list|,
name|_Num
parameter_list|)
value|((UINT32) ((_Name) | (_Num)<< 16))
end_define

begin_define
define|#
directive|define
name|EISA_PNP_ID
parameter_list|(
name|_PNPId
parameter_list|)
value|(EISA_ID(PNP_EISA_ID_CONST, (_PNPId)))
end_define

begin_define
define|#
directive|define
name|PNP_EISA_ID_MASK
value|0xffff
end_define

begin_define
define|#
directive|define
name|EISA_ID_TO_NUM
parameter_list|(
name|_Id
parameter_list|)
value|((_Id)>> 16)
end_define

begin_comment
comment|/*  *  */
end_comment

begin_define
define|#
directive|define
name|MESSAGING_DEVICE_PATH
value|0x03
end_define

begin_define
define|#
directive|define
name|MSG_ATAPI_DP
value|0x01
end_define

begin_typedef
typedef|typedef
struct|struct
name|_ATAPI_DEVICE_PATH
block|{
name|EFI_DEVICE_PATH
name|Header
decl_stmt|;
name|UINT8
name|PrimarySecondary
decl_stmt|;
name|UINT8
name|SlaveMaster
decl_stmt|;
name|UINT16
name|Lun
decl_stmt|;
block|}
name|ATAPI_DEVICE_PATH
typedef|;
end_typedef

begin_define
define|#
directive|define
name|MSG_SCSI_DP
value|0x02
end_define

begin_typedef
typedef|typedef
struct|struct
name|_SCSI_DEVICE_PATH
block|{
name|EFI_DEVICE_PATH
name|Header
decl_stmt|;
name|UINT16
name|Pun
decl_stmt|;
name|UINT16
name|Lun
decl_stmt|;
block|}
name|SCSI_DEVICE_PATH
typedef|;
end_typedef

begin_define
define|#
directive|define
name|MSG_FIBRECHANNEL_DP
value|0x03
end_define

begin_typedef
typedef|typedef
struct|struct
name|_FIBRECHANNEL_DEVICE_PATH
block|{
name|EFI_DEVICE_PATH
name|Header
decl_stmt|;
name|UINT32
name|Reserved
decl_stmt|;
name|UINT64
name|WWN
decl_stmt|;
name|UINT64
name|Lun
decl_stmt|;
block|}
name|FIBRECHANNEL_DEVICE_PATH
typedef|;
end_typedef

begin_define
define|#
directive|define
name|MSG_1394_DP
value|0x04
end_define

begin_typedef
typedef|typedef
struct|struct
name|_F1394_DEVICE_PATH
block|{
name|EFI_DEVICE_PATH
name|Header
decl_stmt|;
name|UINT32
name|Reserved
decl_stmt|;
name|UINT64
name|Guid
decl_stmt|;
block|}
name|F1394_DEVICE_PATH
typedef|;
end_typedef

begin_define
define|#
directive|define
name|MSG_USB_DP
value|0x05
end_define

begin_typedef
typedef|typedef
struct|struct
name|_USB_DEVICE_PATH
block|{
name|EFI_DEVICE_PATH
name|Header
decl_stmt|;
name|UINT8
name|Port
decl_stmt|;
name|UINT8
name|Endpoint
decl_stmt|;
block|}
name|USB_DEVICE_PATH
typedef|;
end_typedef

begin_define
define|#
directive|define
name|MSG_USB_CLASS_DP
value|0x0F
end_define

begin_typedef
typedef|typedef
struct|struct
name|_USB_CLASS_DEVICE_PATH
block|{
name|EFI_DEVICE_PATH
name|Header
decl_stmt|;
name|UINT16
name|VendorId
decl_stmt|;
name|UINT16
name|ProductId
decl_stmt|;
name|UINT8
name|DeviceClass
decl_stmt|;
name|UINT8
name|DeviceSubclass
decl_stmt|;
name|UINT8
name|DeviceProtocol
decl_stmt|;
block|}
name|USB_CLASS_DEVICE_PATH
typedef|;
end_typedef

begin_define
define|#
directive|define
name|MSG_I2O_DP
value|0x06
end_define

begin_typedef
typedef|typedef
struct|struct
name|_I2O_DEVICE_PATH
block|{
name|EFI_DEVICE_PATH
name|Header
decl_stmt|;
name|UINT32
name|Tid
decl_stmt|;
block|}
name|I2O_DEVICE_PATH
typedef|;
end_typedef

begin_define
define|#
directive|define
name|MSG_MAC_ADDR_DP
value|0x0b
end_define

begin_typedef
typedef|typedef
struct|struct
name|_MAC_ADDR_DEVICE_PATH
block|{
name|EFI_DEVICE_PATH
name|Header
decl_stmt|;
name|EFI_MAC_ADDRESS
name|MacAddress
decl_stmt|;
name|UINT8
name|IfType
decl_stmt|;
block|}
name|MAC_ADDR_DEVICE_PATH
typedef|;
end_typedef

begin_define
define|#
directive|define
name|MSG_IPv4_DP
value|0x0c
end_define

begin_typedef
typedef|typedef
struct|struct
name|_IPv4_DEVICE_PATH
block|{
name|EFI_DEVICE_PATH
name|Header
decl_stmt|;
name|EFI_IPv4_ADDRESS
name|LocalIpAddress
decl_stmt|;
name|EFI_IPv4_ADDRESS
name|RemoteIpAddress
decl_stmt|;
name|UINT16
name|LocalPort
decl_stmt|;
name|UINT16
name|RemotePort
decl_stmt|;
name|UINT16
name|Protocol
decl_stmt|;
name|BOOLEAN
name|StaticIpAddress
decl_stmt|;
block|}
name|IPv4_DEVICE_PATH
typedef|;
end_typedef

begin_define
define|#
directive|define
name|MSG_IPv6_DP
value|0x0d
end_define

begin_typedef
typedef|typedef
struct|struct
name|_IPv6_DEVICE_PATH
block|{
name|EFI_DEVICE_PATH
name|Header
decl_stmt|;
name|EFI_IPv6_ADDRESS
name|LocalIpAddress
decl_stmt|;
name|EFI_IPv6_ADDRESS
name|RemoteIpAddress
decl_stmt|;
name|UINT16
name|LocalPort
decl_stmt|;
name|UINT16
name|RemotePort
decl_stmt|;
name|UINT16
name|Protocol
decl_stmt|;
name|BOOLEAN
name|StaticIpAddress
decl_stmt|;
block|}
name|IPv6_DEVICE_PATH
typedef|;
end_typedef

begin_define
define|#
directive|define
name|MSG_INFINIBAND_DP
value|0x09
end_define

begin_typedef
typedef|typedef
struct|struct
name|_INFINIBAND_DEVICE_PATH
block|{
name|EFI_DEVICE_PATH
name|Header
decl_stmt|;
name|UINT32
name|Reserved
decl_stmt|;
name|UINT64
name|NodeGuid
decl_stmt|;
name|UINT64
name|IocGuid
decl_stmt|;
name|UINT64
name|DeviceId
decl_stmt|;
block|}
name|INFINIBAND_DEVICE_PATH
typedef|;
end_typedef

begin_define
define|#
directive|define
name|MSG_UART_DP
value|0x0e
end_define

begin_typedef
typedef|typedef
struct|struct
name|_UART_DEVICE_PATH
block|{
name|EFI_DEVICE_PATH
name|Header
decl_stmt|;
name|UINT32
name|Reserved
decl_stmt|;
name|UINT64
name|BaudRate
decl_stmt|;
name|UINT8
name|DataBits
decl_stmt|;
name|UINT8
name|Parity
decl_stmt|;
name|UINT8
name|StopBits
decl_stmt|;
block|}
name|UART_DEVICE_PATH
typedef|;
end_typedef

begin_define
define|#
directive|define
name|MSG_VENDOR_DP
value|0x0A
end_define

begin_comment
comment|/* Use VENDOR_DEVICE_PATH struct */
end_comment

begin_define
define|#
directive|define
name|DEVICE_PATH_MESSAGING_PC_ANSI
define|\
value|{ 0xe0c14753, 0xf9be, 0x11d2,  0x9a, 0x0c, 0x00, 0x90, 0x27, 0x3f, 0xc1, 0x4d  }
end_define

begin_define
define|#
directive|define
name|DEVICE_PATH_MESSAGING_VT_100
define|\
value|{ 0xdfa66065, 0xb419, 0x11d3,  0x9a, 0x2d, 0x00, 0x90, 0x27, 0x3f, 0xc1, 0x4d  }
end_define

begin_define
define|#
directive|define
name|MEDIA_DEVICE_PATH
value|0x04
end_define

begin_define
define|#
directive|define
name|MEDIA_HARDDRIVE_DP
value|0x01
end_define

begin_typedef
typedef|typedef
struct|struct
name|_HARDDRIVE_DEVICE_PATH
block|{
name|EFI_DEVICE_PATH
name|Header
decl_stmt|;
name|UINT32
name|PartitionNumber
decl_stmt|;
name|UINT64
name|PartitionStart
decl_stmt|;
name|UINT64
name|PartitionSize
decl_stmt|;
name|UINT8
name|Signature
index|[
literal|16
index|]
decl_stmt|;
name|UINT8
name|MBRType
decl_stmt|;
name|UINT8
name|SignatureType
decl_stmt|;
block|}
name|HARDDRIVE_DEVICE_PATH
typedef|;
end_typedef

begin_define
define|#
directive|define
name|MBR_TYPE_PCAT
value|0x01
end_define

begin_define
define|#
directive|define
name|MBR_TYPE_EFI_PARTITION_TABLE_HEADER
value|0x02
end_define

begin_define
define|#
directive|define
name|SIGNATURE_TYPE_MBR
value|0x01
end_define

begin_define
define|#
directive|define
name|SIGNATURE_TYPE_GUID
value|0x02
end_define

begin_define
define|#
directive|define
name|MEDIA_CDROM_DP
value|0x02
end_define

begin_typedef
typedef|typedef
struct|struct
name|_CDROM_DEVICE_PATH
block|{
name|EFI_DEVICE_PATH
name|Header
decl_stmt|;
name|UINT32
name|BootEntry
decl_stmt|;
name|UINT64
name|PartitionStart
decl_stmt|;
name|UINT64
name|PartitionSize
decl_stmt|;
block|}
name|CDROM_DEVICE_PATH
typedef|;
end_typedef

begin_define
define|#
directive|define
name|MEDIA_VENDOR_DP
value|0x03
end_define

begin_comment
comment|/* Use VENDOR_DEVICE_PATH struct */
end_comment

begin_define
define|#
directive|define
name|MEDIA_FILEPATH_DP
value|0x04
end_define

begin_typedef
typedef|typedef
struct|struct
name|_FILEPATH_DEVICE_PATH
block|{
name|EFI_DEVICE_PATH
name|Header
decl_stmt|;
name|CHAR16
name|PathName
index|[
literal|1
index|]
decl_stmt|;
block|}
name|FILEPATH_DEVICE_PATH
typedef|;
end_typedef

begin_define
define|#
directive|define
name|SIZE_OF_FILEPATH_DEVICE_PATH
value|EFI_FIELD_OFFSET(FILEPATH_DEVICE_PATH,PathName)
end_define

begin_define
define|#
directive|define
name|MEDIA_PROTOCOL_DP
value|0x05
end_define

begin_typedef
typedef|typedef
struct|struct
name|_MEDIA_PROTOCOL_DEVICE_PATH
block|{
name|EFI_DEVICE_PATH
name|Header
decl_stmt|;
name|EFI_GUID
name|Protocol
decl_stmt|;
block|}
name|MEDIA_PROTOCOL_DEVICE_PATH
typedef|;
end_typedef

begin_define
define|#
directive|define
name|BBS_DEVICE_PATH
value|0x05
end_define

begin_define
define|#
directive|define
name|BBS_BBS_DP
value|0x01
end_define

begin_typedef
typedef|typedef
struct|struct
name|_BBS_BBS_DEVICE_PATH
block|{
name|EFI_DEVICE_PATH
name|Header
decl_stmt|;
name|UINT16
name|DeviceType
decl_stmt|;
name|UINT16
name|StatusFlag
decl_stmt|;
name|CHAR8
name|String
index|[
literal|1
index|]
decl_stmt|;
block|}
name|BBS_BBS_DEVICE_PATH
typedef|;
end_typedef

begin_comment
comment|/* DeviceType definitions - from BBS specification */
end_comment

begin_define
define|#
directive|define
name|BBS_TYPE_FLOPPY
value|0x01
end_define

begin_define
define|#
directive|define
name|BBS_TYPE_HARDDRIVE
value|0x02
end_define

begin_define
define|#
directive|define
name|BBS_TYPE_CDROM
value|0x03
end_define

begin_define
define|#
directive|define
name|BBS_TYPE_PCMCIA
value|0x04
end_define

begin_define
define|#
directive|define
name|BBS_TYPE_USB
value|0x05
end_define

begin_define
define|#
directive|define
name|BBS_TYPE_EMBEDDED_NETWORK
value|0x06
end_define

begin_define
define|#
directive|define
name|BBS_TYPE_DEV
value|0x80
end_define

begin_define
define|#
directive|define
name|BBS_TYPE_UNKNOWN
value|0xFF
end_define

begin_typedef
typedef|typedef
union|union
block|{
name|EFI_DEVICE_PATH
name|DevPath
decl_stmt|;
name|PCI_DEVICE_PATH
name|Pci
decl_stmt|;
name|PCCARD_DEVICE_PATH
name|PcCard
decl_stmt|;
name|MEMMAP_DEVICE_PATH
name|MemMap
decl_stmt|;
name|VENDOR_DEVICE_PATH
name|Vendor
decl_stmt|;
name|UNKNOWN_DEVICE_VENDOR_DEVICE_PATH
name|UnknownVendor
decl_stmt|;
name|CONTROLLER_DEVICE_PATH
name|Controller
decl_stmt|;
name|ACPI_HID_DEVICE_PATH
name|Acpi
decl_stmt|;
name|ATAPI_DEVICE_PATH
name|Atapi
decl_stmt|;
name|SCSI_DEVICE_PATH
name|Scsi
decl_stmt|;
name|FIBRECHANNEL_DEVICE_PATH
name|FibreChannel
decl_stmt|;
name|F1394_DEVICE_PATH
name|F1394
decl_stmt|;
name|USB_DEVICE_PATH
name|Usb
decl_stmt|;
name|USB_CLASS_DEVICE_PATH
name|UsbClass
decl_stmt|;
name|I2O_DEVICE_PATH
name|I2O
decl_stmt|;
name|MAC_ADDR_DEVICE_PATH
name|MacAddr
decl_stmt|;
name|IPv4_DEVICE_PATH
name|Ipv4
decl_stmt|;
name|IPv6_DEVICE_PATH
name|Ipv6
decl_stmt|;
name|INFINIBAND_DEVICE_PATH
name|InfiniBand
decl_stmt|;
name|UART_DEVICE_PATH
name|Uart
decl_stmt|;
name|HARDDRIVE_DEVICE_PATH
name|HardDrive
decl_stmt|;
name|CDROM_DEVICE_PATH
name|CD
decl_stmt|;
name|FILEPATH_DEVICE_PATH
name|FilePath
decl_stmt|;
name|MEDIA_PROTOCOL_DEVICE_PATH
name|MediaProtocol
decl_stmt|;
name|BBS_BBS_DEVICE_PATH
name|Bbs
decl_stmt|;
block|}
name|EFI_DEV_PATH
typedef|;
end_typedef

begin_typedef
typedef|typedef
union|union
block|{
name|EFI_DEVICE_PATH
modifier|*
name|DevPath
decl_stmt|;
name|PCI_DEVICE_PATH
modifier|*
name|Pci
decl_stmt|;
name|PCCARD_DEVICE_PATH
modifier|*
name|PcCard
decl_stmt|;
name|MEMMAP_DEVICE_PATH
modifier|*
name|MemMap
decl_stmt|;
name|VENDOR_DEVICE_PATH
modifier|*
name|Vendor
decl_stmt|;
name|UNKNOWN_DEVICE_VENDOR_DEVICE_PATH
modifier|*
name|UnknownVendor
decl_stmt|;
name|CONTROLLER_DEVICE_PATH
modifier|*
name|Controller
decl_stmt|;
name|ACPI_HID_DEVICE_PATH
modifier|*
name|Acpi
decl_stmt|;
name|ATAPI_DEVICE_PATH
modifier|*
name|Atapi
decl_stmt|;
name|SCSI_DEVICE_PATH
modifier|*
name|Scsi
decl_stmt|;
name|FIBRECHANNEL_DEVICE_PATH
modifier|*
name|FibreChannel
decl_stmt|;
name|F1394_DEVICE_PATH
modifier|*
name|F1394
decl_stmt|;
name|USB_DEVICE_PATH
modifier|*
name|Usb
decl_stmt|;
name|USB_CLASS_DEVICE_PATH
modifier|*
name|UsbClass
decl_stmt|;
name|I2O_DEVICE_PATH
modifier|*
name|I2O
decl_stmt|;
name|MAC_ADDR_DEVICE_PATH
modifier|*
name|MacAddr
decl_stmt|;
name|IPv4_DEVICE_PATH
modifier|*
name|Ipv4
decl_stmt|;
name|IPv6_DEVICE_PATH
modifier|*
name|Ipv6
decl_stmt|;
name|INFINIBAND_DEVICE_PATH
modifier|*
name|InfiniBand
decl_stmt|;
name|UART_DEVICE_PATH
modifier|*
name|Uart
decl_stmt|;
name|HARDDRIVE_DEVICE_PATH
modifier|*
name|HardDrive
decl_stmt|;
name|FILEPATH_DEVICE_PATH
modifier|*
name|FilePath
decl_stmt|;
name|MEDIA_PROTOCOL_DEVICE_PATH
modifier|*
name|MediaProtocol
decl_stmt|;
name|CDROM_DEVICE_PATH
modifier|*
name|CD
decl_stmt|;
name|BBS_BBS_DEVICE_PATH
modifier|*
name|Bbs
decl_stmt|;
block|}
name|EFI_DEV_PATH_PTR
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

end_unit

