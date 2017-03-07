begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/** @file   Support for USB 2.0 standard.    Copyright (c) 2006 - 2014, Intel Corporation. All rights reserved.<BR>   This program and the accompanying materials   are licensed and made available under the terms and conditions of the BSD License   which accompanies this distribution.  The full text of the license may be found at   http://opensource.org/licenses/bsd-license.php    THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN "AS IS" BASIS,   WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.  **/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__USB_H__
end_ifndef

begin_define
define|#
directive|define
name|__USB_H__
end_define

begin_comment
comment|//
end_comment

begin_comment
comment|// Subset of Class and Subclass definitions from USB Specs
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// Usb mass storage class code
end_comment

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|USB_MASS_STORE_CLASS
value|0x08
end_define

begin_comment
comment|//
end_comment

begin_comment
comment|// Usb mass storage subclass code, specify the command set used.
end_comment

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|USB_MASS_STORE_RBC
value|0x01
end_define

begin_comment
comment|///< Reduced Block Commands
end_comment

begin_define
define|#
directive|define
name|USB_MASS_STORE_8020I
value|0x02
end_define

begin_comment
comment|///< SFF-8020i, typically a CD/DVD device
end_comment

begin_define
define|#
directive|define
name|USB_MASS_STORE_QIC
value|0x03
end_define

begin_comment
comment|///< Typically a tape device
end_comment

begin_define
define|#
directive|define
name|USB_MASS_STORE_UFI
value|0x04
end_define

begin_comment
comment|///< Typically a floppy disk driver device
end_comment

begin_define
define|#
directive|define
name|USB_MASS_STORE_8070I
value|0x05
end_define

begin_comment
comment|///< SFF-8070i, typically a floppy disk driver device.
end_comment

begin_define
define|#
directive|define
name|USB_MASS_STORE_SCSI
value|0x06
end_define

begin_comment
comment|///< SCSI transparent command set
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// Usb mass storage protocol code, specify the transport protocol
end_comment

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|USB_MASS_STORE_CBI0
value|0x00
end_define

begin_comment
comment|///< CBI protocol with command completion interrupt
end_comment

begin_define
define|#
directive|define
name|USB_MASS_STORE_CBI1
value|0x01
end_define

begin_comment
comment|///< CBI protocol without command completion interrupt
end_comment

begin_define
define|#
directive|define
name|USB_MASS_STORE_BOT
value|0x50
end_define

begin_comment
comment|///< Bulk-Only Transport
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// Standard device request and request type
end_comment

begin_comment
comment|// USB 2.0 spec, Section 9.4
end_comment

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|USB_DEV_GET_STATUS
value|0x00
end_define

begin_define
define|#
directive|define
name|USB_DEV_GET_STATUS_REQ_TYPE_D
value|0x80
end_define

begin_comment
comment|// Receiver : Device
end_comment

begin_define
define|#
directive|define
name|USB_DEV_GET_STATUS_REQ_TYPE_I
value|0x81
end_define

begin_comment
comment|// Receiver : Interface
end_comment

begin_define
define|#
directive|define
name|USB_DEV_GET_STATUS_REQ_TYPE_E
value|0x82
end_define

begin_comment
comment|// Receiver : Endpoint
end_comment

begin_define
define|#
directive|define
name|USB_DEV_CLEAR_FEATURE
value|0x01
end_define

begin_define
define|#
directive|define
name|USB_DEV_CLEAR_FEATURE_REQ_TYPE_D
value|0x00
end_define

begin_comment
comment|// Receiver : Device
end_comment

begin_define
define|#
directive|define
name|USB_DEV_CLEAR_FEATURE_REQ_TYPE_I
value|0x01
end_define

begin_comment
comment|// Receiver : Interface
end_comment

begin_define
define|#
directive|define
name|USB_DEV_CLEAR_FEATURE_REQ_TYPE_E
value|0x02
end_define

begin_comment
comment|// Receiver : Endpoint
end_comment

begin_define
define|#
directive|define
name|USB_DEV_SET_FEATURE
value|0x03
end_define

begin_define
define|#
directive|define
name|USB_DEV_SET_FEATURE_REQ_TYPE_D
value|0x00
end_define

begin_comment
comment|// Receiver : Device
end_comment

begin_define
define|#
directive|define
name|USB_DEV_SET_FEATURE_REQ_TYPE_I
value|0x01
end_define

begin_comment
comment|// Receiver : Interface
end_comment

begin_define
define|#
directive|define
name|USB_DEV_SET_FEATURE_REQ_TYPE_E
value|0x02
end_define

begin_comment
comment|// Receiver : Endpoint
end_comment

begin_define
define|#
directive|define
name|USB_DEV_SET_ADDRESS
value|0x05
end_define

begin_define
define|#
directive|define
name|USB_DEV_SET_ADDRESS_REQ_TYPE
value|0x00
end_define

begin_define
define|#
directive|define
name|USB_DEV_GET_DESCRIPTOR
value|0x06
end_define

begin_define
define|#
directive|define
name|USB_DEV_GET_DESCRIPTOR_REQ_TYPE
value|0x80
end_define

begin_define
define|#
directive|define
name|USB_DEV_SET_DESCRIPTOR
value|0x07
end_define

begin_define
define|#
directive|define
name|USB_DEV_SET_DESCRIPTOR_REQ_TYPE
value|0x00
end_define

begin_define
define|#
directive|define
name|USB_DEV_GET_CONFIGURATION
value|0x08
end_define

begin_define
define|#
directive|define
name|USB_DEV_GET_CONFIGURATION_REQ_TYPE
value|0x80
end_define

begin_define
define|#
directive|define
name|USB_DEV_SET_CONFIGURATION
value|0x09
end_define

begin_define
define|#
directive|define
name|USB_DEV_SET_CONFIGURATION_REQ_TYPE
value|0x00
end_define

begin_define
define|#
directive|define
name|USB_DEV_GET_INTERFACE
value|0x0A
end_define

begin_define
define|#
directive|define
name|USB_DEV_GET_INTERFACE_REQ_TYPE
value|0x81
end_define

begin_define
define|#
directive|define
name|USB_DEV_SET_INTERFACE
value|0x0B
end_define

begin_define
define|#
directive|define
name|USB_DEV_SET_INTERFACE_REQ_TYPE
value|0x01
end_define

begin_define
define|#
directive|define
name|USB_DEV_SYNCH_FRAME
value|0x0C
end_define

begin_define
define|#
directive|define
name|USB_DEV_SYNCH_FRAME_REQ_TYPE
value|0x82
end_define

begin_comment
comment|//
end_comment

begin_comment
comment|// USB standard descriptors and reqeust
end_comment

begin_comment
comment|//
end_comment

begin_pragma
pragma|#
directive|pragma
name|pack
name|(
name|1
name|)
end_pragma

begin_comment
comment|///
end_comment

begin_comment
comment|/// Format of Setup Data for USB Device Requests
end_comment

begin_comment
comment|/// USB 2.0 spec, Section 9.3
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|UINT8
name|RequestType
decl_stmt|;
name|UINT8
name|Request
decl_stmt|;
name|UINT16
name|Value
decl_stmt|;
name|UINT16
name|Index
decl_stmt|;
name|UINT16
name|Length
decl_stmt|;
block|}
name|USB_DEVICE_REQUEST
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// Standard Device Descriptor
end_comment

begin_comment
comment|/// USB 2.0 spec, Section 9.6.1
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|UINT8
name|Length
decl_stmt|;
name|UINT8
name|DescriptorType
decl_stmt|;
name|UINT16
name|BcdUSB
decl_stmt|;
name|UINT8
name|DeviceClass
decl_stmt|;
name|UINT8
name|DeviceSubClass
decl_stmt|;
name|UINT8
name|DeviceProtocol
decl_stmt|;
name|UINT8
name|MaxPacketSize0
decl_stmt|;
name|UINT16
name|IdVendor
decl_stmt|;
name|UINT16
name|IdProduct
decl_stmt|;
name|UINT16
name|BcdDevice
decl_stmt|;
name|UINT8
name|StrManufacturer
decl_stmt|;
name|UINT8
name|StrProduct
decl_stmt|;
name|UINT8
name|StrSerialNumber
decl_stmt|;
name|UINT8
name|NumConfigurations
decl_stmt|;
block|}
name|USB_DEVICE_DESCRIPTOR
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// Standard Configuration Descriptor
end_comment

begin_comment
comment|/// USB 2.0 spec, Section 9.6.3
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|UINT8
name|Length
decl_stmt|;
name|UINT8
name|DescriptorType
decl_stmt|;
name|UINT16
name|TotalLength
decl_stmt|;
name|UINT8
name|NumInterfaces
decl_stmt|;
name|UINT8
name|ConfigurationValue
decl_stmt|;
name|UINT8
name|Configuration
decl_stmt|;
name|UINT8
name|Attributes
decl_stmt|;
name|UINT8
name|MaxPower
decl_stmt|;
block|}
name|USB_CONFIG_DESCRIPTOR
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// Standard Interface Descriptor
end_comment

begin_comment
comment|/// USB 2.0 spec, Section 9.6.5
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|UINT8
name|Length
decl_stmt|;
name|UINT8
name|DescriptorType
decl_stmt|;
name|UINT8
name|InterfaceNumber
decl_stmt|;
name|UINT8
name|AlternateSetting
decl_stmt|;
name|UINT8
name|NumEndpoints
decl_stmt|;
name|UINT8
name|InterfaceClass
decl_stmt|;
name|UINT8
name|InterfaceSubClass
decl_stmt|;
name|UINT8
name|InterfaceProtocol
decl_stmt|;
name|UINT8
name|Interface
decl_stmt|;
block|}
name|USB_INTERFACE_DESCRIPTOR
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// Standard Endpoint Descriptor
end_comment

begin_comment
comment|/// USB 2.0 spec, Section 9.6.6
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|UINT8
name|Length
decl_stmt|;
name|UINT8
name|DescriptorType
decl_stmt|;
name|UINT8
name|EndpointAddress
decl_stmt|;
name|UINT8
name|Attributes
decl_stmt|;
name|UINT16
name|MaxPacketSize
decl_stmt|;
name|UINT8
name|Interval
decl_stmt|;
block|}
name|USB_ENDPOINT_DESCRIPTOR
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// UNICODE String Descriptor
end_comment

begin_comment
comment|/// USB 2.0 spec, Section 9.6.7
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|UINT8
name|Length
decl_stmt|;
name|UINT8
name|DescriptorType
decl_stmt|;
name|CHAR16
name|String
index|[
literal|1
index|]
decl_stmt|;
block|}
name|EFI_USB_STRING_DESCRIPTOR
typedef|;
end_typedef

begin_pragma
pragma|#
directive|pragma
name|pack
name|(
name|)
end_pragma

begin_typedef
typedef|typedef
enum|enum
block|{
comment|//
comment|// USB request type
comment|//
name|USB_REQ_TYPE_STANDARD
init|=
operator|(
literal|0x00
operator|<<
literal|5
operator|)
block|,
name|USB_REQ_TYPE_CLASS
init|=
operator|(
literal|0x01
operator|<<
literal|5
operator|)
block|,
name|USB_REQ_TYPE_VENDOR
init|=
operator|(
literal|0x02
operator|<<
literal|5
operator|)
block|,
comment|//
comment|// Standard control transfer request type, or the value
comment|// to fill in EFI_USB_DEVICE_REQUEST.Request
comment|//
name|USB_REQ_GET_STATUS
init|=
literal|0x00
block|,
name|USB_REQ_CLEAR_FEATURE
init|=
literal|0x01
block|,
name|USB_REQ_SET_FEATURE
init|=
literal|0x03
block|,
name|USB_REQ_SET_ADDRESS
init|=
literal|0x05
block|,
name|USB_REQ_GET_DESCRIPTOR
init|=
literal|0x06
block|,
name|USB_REQ_SET_DESCRIPTOR
init|=
literal|0x07
block|,
name|USB_REQ_GET_CONFIG
init|=
literal|0x08
block|,
name|USB_REQ_SET_CONFIG
init|=
literal|0x09
block|,
name|USB_REQ_GET_INTERFACE
init|=
literal|0x0A
block|,
name|USB_REQ_SET_INTERFACE
init|=
literal|0x0B
block|,
name|USB_REQ_SYNCH_FRAME
init|=
literal|0x0C
block|,
comment|//
comment|// Usb control transfer target
comment|//
name|USB_TARGET_DEVICE
init|=
literal|0
block|,
name|USB_TARGET_INTERFACE
init|=
literal|0x01
block|,
name|USB_TARGET_ENDPOINT
init|=
literal|0x02
block|,
name|USB_TARGET_OTHER
init|=
literal|0x03
block|,
comment|//
comment|// USB Descriptor types
comment|//
name|USB_DESC_TYPE_DEVICE
init|=
literal|0x01
block|,
name|USB_DESC_TYPE_CONFIG
init|=
literal|0x02
block|,
name|USB_DESC_TYPE_STRING
init|=
literal|0x03
block|,
name|USB_DESC_TYPE_INTERFACE
init|=
literal|0x04
block|,
name|USB_DESC_TYPE_ENDPOINT
init|=
literal|0x05
block|,
name|USB_DESC_TYPE_HID
init|=
literal|0x21
block|,
name|USB_DESC_TYPE_REPORT
init|=
literal|0x22
block|,
comment|//
comment|// Features to be cleared by CLEAR_FEATURE requests
comment|//
name|USB_FEATURE_ENDPOINT_HALT
init|=
literal|0
block|,
comment|//
comment|// USB endpoint types: 00: control, 01: isochronous, 10: bulk, 11: interrupt
comment|//
name|USB_ENDPOINT_CONTROL
init|=
literal|0x00
block|,
name|USB_ENDPOINT_ISO
init|=
literal|0x01
block|,
name|USB_ENDPOINT_BULK
init|=
literal|0x02
block|,
name|USB_ENDPOINT_INTERRUPT
init|=
literal|0x03
block|,
name|USB_ENDPOINT_TYPE_MASK
init|=
literal|0x03
block|,
name|USB_ENDPOINT_DIR_IN
init|=
literal|0x80
block|,
comment|//
comment|//Use 200 ms to increase the error handling response time
comment|//
name|EFI_USB_INTERRUPT_DELAY
init|=
literal|2000000
block|}
name|USB_TYPES_DEFINITION
typedef|;
end_typedef

begin_comment
comment|//
end_comment

begin_comment
comment|// HID constants definition, see Device Class Definition
end_comment

begin_comment
comment|// for Human Interface Devices (HID) rev1.11
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// HID standard GET_DESCRIPTOR request.
end_comment

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|USB_HID_GET_DESCRIPTOR_REQ_TYPE
value|0x81
end_define

begin_comment
comment|//
end_comment

begin_comment
comment|// HID specific requests.
end_comment

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|USB_HID_CLASS_GET_REQ_TYPE
value|0xa1
end_define

begin_define
define|#
directive|define
name|USB_HID_CLASS_SET_REQ_TYPE
value|0x21
end_define

begin_comment
comment|//
end_comment

begin_comment
comment|// HID report item format
end_comment

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|HID_ITEM_FORMAT_SHORT
value|0
end_define

begin_define
define|#
directive|define
name|HID_ITEM_FORMAT_LONG
value|1
end_define

begin_comment
comment|//
end_comment

begin_comment
comment|// Special tag indicating long items
end_comment

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|HID_ITEM_TAG_LONG
value|15
end_define

begin_comment
comment|//
end_comment

begin_comment
comment|// HID report descriptor item type (prefix bit 2,3)
end_comment

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|HID_ITEM_TYPE_MAIN
value|0
end_define

begin_define
define|#
directive|define
name|HID_ITEM_TYPE_GLOBAL
value|1
end_define

begin_define
define|#
directive|define
name|HID_ITEM_TYPE_LOCAL
value|2
end_define

begin_define
define|#
directive|define
name|HID_ITEM_TYPE_RESERVED
value|3
end_define

begin_comment
comment|//
end_comment

begin_comment
comment|// HID report descriptor main item tags
end_comment

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|HID_MAIN_ITEM_TAG_INPUT
value|8
end_define

begin_define
define|#
directive|define
name|HID_MAIN_ITEM_TAG_OUTPUT
value|9
end_define

begin_define
define|#
directive|define
name|HID_MAIN_ITEM_TAG_FEATURE
value|11
end_define

begin_define
define|#
directive|define
name|HID_MAIN_ITEM_TAG_BEGIN_COLLECTION
value|10
end_define

begin_define
define|#
directive|define
name|HID_MAIN_ITEM_TAG_END_COLLECTION
value|12
end_define

begin_comment
comment|//
end_comment

begin_comment
comment|// HID report descriptor main item contents
end_comment

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|HID_MAIN_ITEM_CONSTANT
value|0x001
end_define

begin_define
define|#
directive|define
name|HID_MAIN_ITEM_VARIABLE
value|0x002
end_define

begin_define
define|#
directive|define
name|HID_MAIN_ITEM_RELATIVE
value|0x004
end_define

begin_define
define|#
directive|define
name|HID_MAIN_ITEM_WRAP
value|0x008
end_define

begin_define
define|#
directive|define
name|HID_MAIN_ITEM_NONLINEAR
value|0x010
end_define

begin_define
define|#
directive|define
name|HID_MAIN_ITEM_NO_PREFERRED
value|0x020
end_define

begin_define
define|#
directive|define
name|HID_MAIN_ITEM_NULL_STATE
value|0x040
end_define

begin_define
define|#
directive|define
name|HID_MAIN_ITEM_VOLATILE
value|0x080
end_define

begin_define
define|#
directive|define
name|HID_MAIN_ITEM_BUFFERED_BYTE
value|0x100
end_define

begin_comment
comment|//
end_comment

begin_comment
comment|// HID report descriptor collection item types
end_comment

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|HID_COLLECTION_PHYSICAL
value|0
end_define

begin_define
define|#
directive|define
name|HID_COLLECTION_APPLICATION
value|1
end_define

begin_define
define|#
directive|define
name|HID_COLLECTION_LOGICAL
value|2
end_define

begin_comment
comment|//
end_comment

begin_comment
comment|// HID report descriptor global item tags
end_comment

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|HID_GLOBAL_ITEM_TAG_USAGE_PAGE
value|0
end_define

begin_define
define|#
directive|define
name|HID_GLOBAL_ITEM_TAG_LOGICAL_MINIMUM
value|1
end_define

begin_define
define|#
directive|define
name|HID_GLOBAL_ITEM_TAG_LOGICAL_MAXIMUM
value|2
end_define

begin_define
define|#
directive|define
name|HID_GLOBAL_ITEM_TAG_PHYSICAL_MINIMUM
value|3
end_define

begin_define
define|#
directive|define
name|HID_GLOBAL_ITEM_TAG_PHYSICAL_MAXIMUM
value|4
end_define

begin_define
define|#
directive|define
name|HID_GLOBAL_ITEM_TAG_UNIT_EXPONENT
value|5
end_define

begin_define
define|#
directive|define
name|HID_GLOBAL_ITEM_TAG_UNIT
value|6
end_define

begin_define
define|#
directive|define
name|HID_GLOBAL_ITEM_TAG_REPORT_SIZE
value|7
end_define

begin_define
define|#
directive|define
name|HID_GLOBAL_ITEM_TAG_REPORT_ID
value|8
end_define

begin_define
define|#
directive|define
name|HID_GLOBAL_ITEM_TAG_REPORT_COUNT
value|9
end_define

begin_define
define|#
directive|define
name|HID_GLOBAL_ITEM_TAG_PUSH
value|10
end_define

begin_define
define|#
directive|define
name|HID_GLOBAL_ITEM_TAG_POP
value|11
end_define

begin_comment
comment|//
end_comment

begin_comment
comment|// HID report descriptor local item tags
end_comment

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|HID_LOCAL_ITEM_TAG_USAGE
value|0
end_define

begin_define
define|#
directive|define
name|HID_LOCAL_ITEM_TAG_USAGE_MINIMUM
value|1
end_define

begin_define
define|#
directive|define
name|HID_LOCAL_ITEM_TAG_USAGE_MAXIMUM
value|2
end_define

begin_define
define|#
directive|define
name|HID_LOCAL_ITEM_TAG_DESIGNATOR_INDEX
value|3
end_define

begin_define
define|#
directive|define
name|HID_LOCAL_ITEM_TAG_DESIGNATOR_MINIMUM
value|4
end_define

begin_define
define|#
directive|define
name|HID_LOCAL_ITEM_TAG_DESIGNATOR_MAXIMUM
value|5
end_define

begin_define
define|#
directive|define
name|HID_LOCAL_ITEM_TAG_STRING_INDEX
value|7
end_define

begin_define
define|#
directive|define
name|HID_LOCAL_ITEM_TAG_STRING_MINIMUM
value|8
end_define

begin_define
define|#
directive|define
name|HID_LOCAL_ITEM_TAG_STRING_MAXIMUM
value|9
end_define

begin_define
define|#
directive|define
name|HID_LOCAL_ITEM_TAG_DELIMITER
value|10
end_define

begin_comment
comment|//
end_comment

begin_comment
comment|// HID report types
end_comment

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|HID_INPUT_REPORT
value|1
end_define

begin_define
define|#
directive|define
name|HID_OUTPUT_REPORT
value|2
end_define

begin_define
define|#
directive|define
name|HID_FEATURE_REPORT
value|3
end_define

begin_comment
comment|//
end_comment

begin_comment
comment|// HID class protocol request
end_comment

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|EFI_USB_GET_REPORT_REQUEST
value|0x01
end_define

begin_define
define|#
directive|define
name|EFI_USB_GET_IDLE_REQUEST
value|0x02
end_define

begin_define
define|#
directive|define
name|EFI_USB_GET_PROTOCOL_REQUEST
value|0x03
end_define

begin_define
define|#
directive|define
name|EFI_USB_SET_REPORT_REQUEST
value|0x09
end_define

begin_define
define|#
directive|define
name|EFI_USB_SET_IDLE_REQUEST
value|0x0a
end_define

begin_define
define|#
directive|define
name|EFI_USB_SET_PROTOCOL_REQUEST
value|0x0b
end_define

begin_pragma
pragma|#
directive|pragma
name|pack
name|(
name|1
name|)
end_pragma

begin_comment
comment|///
end_comment

begin_comment
comment|/// Descriptor header for Report/Physical Descriptors
end_comment

begin_comment
comment|/// HID 1.1, section 6.2.1
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
struct|struct
name|hid_class_descriptor
block|{
name|UINT8
name|DescriptorType
decl_stmt|;
name|UINT16
name|DescriptorLength
decl_stmt|;
block|}
name|EFI_USB_HID_CLASS_DESCRIPTOR
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// The HID descriptor identifies the length and type
end_comment

begin_comment
comment|/// of subordinate descriptors for a device.
end_comment

begin_comment
comment|/// HID 1.1, section 6.2.1
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
struct|struct
name|hid_descriptor
block|{
name|UINT8
name|Length
decl_stmt|;
name|UINT8
name|DescriptorType
decl_stmt|;
name|UINT16
name|BcdHID
decl_stmt|;
name|UINT8
name|CountryCode
decl_stmt|;
name|UINT8
name|NumDescriptors
decl_stmt|;
name|EFI_USB_HID_CLASS_DESCRIPTOR
name|HidClassDesc
index|[
literal|1
index|]
decl_stmt|;
block|}
name|EFI_USB_HID_DESCRIPTOR
typedef|;
end_typedef

begin_pragma
pragma|#
directive|pragma
name|pack
name|(
name|)
end_pragma

begin_endif
endif|#
directive|endif
end_endif

end_unit

