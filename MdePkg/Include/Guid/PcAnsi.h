begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/** @file   Terminal Device Path Vendor Guid.    Copyright (c) 2006 - 2009, Intel Corporation. All rights reserved.<BR>   This program and the accompanying materials                             are licensed and made available under the terms and conditions of the BSD License            which accompanies this distribution.  The full text of the license may be found at           http://opensource.org/licenses/bsd-license.php                                                THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN "AS IS" BASIS,                        WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.                 @par Revision Reference:   GUIDs defined in UEFI 2.0 spec.  **/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__PC_ANSI_H__
end_ifndef

begin_define
define|#
directive|define
name|__PC_ANSI_H__
end_define

begin_define
define|#
directive|define
name|EFI_PC_ANSI_GUID
define|\
value|{ \     0xe0c14753, 0xf9be, 0x11d2, {0x9a, 0x0c, 0x00, 0x90, 0x27, 0x3f, 0xc1, 0x4d } \   }
end_define

begin_define
define|#
directive|define
name|EFI_VT_100_GUID
define|\
value|{ \     0xdfa66065, 0xb419, 0x11d3, {0x9a, 0x2d, 0x00, 0x90, 0x27, 0x3f, 0xc1, 0x4d } \   }
end_define

begin_define
define|#
directive|define
name|EFI_VT_100_PLUS_GUID
define|\
value|{ \     0x7baec70b, 0x57e0, 0x4c76, {0x8e, 0x87, 0x2f, 0x9e, 0x28, 0x08, 0x83, 0x43 } \   }
end_define

begin_define
define|#
directive|define
name|EFI_VT_UTF8_GUID
define|\
value|{ \     0xad15a0d6, 0x8bec, 0x4acf, {0xa0, 0x73, 0xd0, 0x1d, 0xe7, 0x7e, 0x2d, 0x88 } \   }
end_define

begin_define
define|#
directive|define
name|DEVICE_PATH_MESSAGING_UART_FLOW_CONTROL
define|\
value|{ \     0x37499a9d, 0x542f, 0x4c89, {0xa0, 0x26, 0x35, 0xda, 0x14, 0x20, 0x94, 0xe4 } \   }
end_define

begin_define
define|#
directive|define
name|EFI_SAS_DEVICE_PATH_GUID
define|\
value|{ \     0xd487ddb4, 0x008b, 0x11d9, {0xaf, 0xdc, 0x00, 0x10, 0x83, 0xff, 0xca, 0x4d } \   }
end_define

begin_decl_stmt
specifier|extern
name|EFI_GUID
name|gEfiPcAnsiGuid
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|EFI_GUID
name|gEfiVT100Guid
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|EFI_GUID
name|gEfiVT100PlusGuid
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|EFI_GUID
name|gEfiVTUTF8Guid
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|EFI_GUID
name|gEfiUartDevicePathGuid
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|EFI_GUID
name|gEfiSasDevicePathGuid
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

