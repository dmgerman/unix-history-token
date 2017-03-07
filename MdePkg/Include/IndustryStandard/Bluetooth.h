begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/** @file   This file contains the Bluetooth definitions that are consumed by drivers.   These definitions are from Bluetooth Core Specification Version 4.0 June, 2010    Copyright (c) 2015, Intel Corporation. All rights reserved.<BR>   This program and the accompanying materials   are licensed and made available under the terms and conditions of the BSD License   which accompanies this distribution.  The full text of the license may be found at   http://opensource.org/licenses/bsd-license.php    THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN "AS IS" BASIS,   WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.  **/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_BLUETOOTH_H_
end_ifndef

begin_define
define|#
directive|define
name|_BLUETOOTH_H_
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
comment|/// BLUETOOTH_ADDRESS
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
comment|///
comment|/// 48bit Bluetooth device address.
comment|///
name|UINT8
name|Address
index|[
literal|6
index|]
decl_stmt|;
block|}
name|BLUETOOTH_ADDRESS
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// BLUETOOTH_CLASS_OF_DEVICE. See Bluetooth specification for detail.
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|UINT8
name|FormatType
range|:
literal|2
decl_stmt|;
name|UINT8
name|MinorDeviceClass
range|:
literal|6
decl_stmt|;
name|UINT16
name|MajorDeviceClass
range|:
literal|5
decl_stmt|;
name|UINT16
name|MajorServiceClass
range|:
literal|11
decl_stmt|;
block|}
name|BLUETOOTH_CLASS_OF_DEVICE
typedef|;
end_typedef

begin_pragma
pragma|#
directive|pragma
name|pack
name|(
name|)
end_pragma

begin_define
define|#
directive|define
name|BLUETOOTH_HCI_COMMAND_LOCAL_READABLE_NAME_MAX_SIZE
value|248
end_define

begin_define
define|#
directive|define
name|BLUETOOTH_HCI_LINK_KEY_SIZE
value|16
end_define

begin_endif
endif|#
directive|endif
end_endif

end_unit

