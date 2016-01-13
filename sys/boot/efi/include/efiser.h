begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $FreeBSD$ */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_EFI_SER_H
end_ifndef

begin_define
define|#
directive|define
name|_EFI_SER_H
end_define

begin_comment
comment|/*++  Copyright (c)  1999 - 2002 Intel Corporation. All rights reserved This software and associated documentation (if any) is furnished under a license and may only be used or copied in accordance with the terms of the license. Except as permitted by such license, no part of this software or documentation may be reproduced, stored in a retrieval system, or transmitted in any form or by any means without the express written consent of Intel Corporation.  Module Name:      efiser.h  Abstract:      EFI serial protocol  Revision History  --*/
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// Serial protocol
end_comment

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|SERIAL_IO_PROTOCOL
define|\
value|{ 0xBB25CF6F, 0xF1D4, 0x11D2, {0x9A, 0x0C, 0x00, 0x90, 0x27, 0x3F, 0xC1, 0xFD} }
end_define

begin_expr_stmt
name|INTERFACE_DECL
argument_list|(
name|_SERIAL_IO_INTERFACE
argument_list|)
expr_stmt|;
end_expr_stmt

begin_typedef
typedef|typedef
enum|enum
block|{
name|DefaultParity
block|,
name|NoParity
block|,
name|EvenParity
block|,
name|OddParity
block|,
name|MarkParity
block|,
name|SpaceParity
block|}
name|EFI_PARITY_TYPE
typedef|;
end_typedef

begin_typedef
typedef|typedef
enum|enum
block|{
name|DefaultStopBits
block|,
name|OneStopBit
block|,
comment|// 1 stop bit
name|OneFiveStopBits
block|,
comment|// 1.5 stop bits
name|TwoStopBits
comment|// 2 stop bits
block|}
name|EFI_STOP_BITS_TYPE
typedef|;
end_typedef

begin_define
define|#
directive|define
name|EFI_SERIAL_CLEAR_TO_SEND
value|0x0010
end_define

begin_comment
comment|// RO
end_comment

begin_define
define|#
directive|define
name|EFI_SERIAL_DATA_SET_READY
value|0x0020
end_define

begin_comment
comment|// RO
end_comment

begin_define
define|#
directive|define
name|EFI_SERIAL_RING_INDICATE
value|0x0040
end_define

begin_comment
comment|// RO
end_comment

begin_define
define|#
directive|define
name|EFI_SERIAL_CARRIER_DETECT
value|0x0080
end_define

begin_comment
comment|// RO
end_comment

begin_define
define|#
directive|define
name|EFI_SERIAL_REQUEST_TO_SEND
value|0x0002
end_define

begin_comment
comment|// WO
end_comment

begin_define
define|#
directive|define
name|EFI_SERIAL_DATA_TERMINAL_READY
value|0x0001
end_define

begin_comment
comment|// WO
end_comment

begin_define
define|#
directive|define
name|EFI_SERIAL_INPUT_BUFFER_EMPTY
value|0x0100
end_define

begin_comment
comment|// RO
end_comment

begin_define
define|#
directive|define
name|EFI_SERIAL_OUTPUT_BUFFER_EMPTY
value|0x0200
end_define

begin_comment
comment|// RO
end_comment

begin_define
define|#
directive|define
name|EFI_SERIAL_HARDWARE_LOOPBACK_ENABLE
value|0x1000
end_define

begin_comment
comment|// RW
end_comment

begin_define
define|#
directive|define
name|EFI_SERIAL_SOFTWARE_LOOPBACK_ENABLE
value|0x2000
end_define

begin_comment
comment|// RW
end_comment

begin_define
define|#
directive|define
name|EFI_SERIAL_HARDWARE_FLOW_CONTROL_ENABLE
value|0x4000
end_define

begin_comment
comment|// RW
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_SERIAL_RESET
function_decl|)
parameter_list|(
name|IN
name|struct
name|_SERIAL_IO_INTERFACE
modifier|*
name|This
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_SERIAL_SET_ATTRIBUTES
function_decl|)
parameter_list|(
name|IN
name|struct
name|_SERIAL_IO_INTERFACE
modifier|*
name|This
parameter_list|,
name|IN
name|UINT64
name|BaudRate
parameter_list|,
name|IN
name|UINT32
name|ReceiveFifoDepth
parameter_list|,
name|IN
name|UINT32
name|Timeout
parameter_list|,
name|IN
name|EFI_PARITY_TYPE
name|Parity
parameter_list|,
name|IN
name|UINT8
name|DataBits
parameter_list|,
name|IN
name|EFI_STOP_BITS_TYPE
name|StopBits
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_SERIAL_SET_CONTROL_BITS
function_decl|)
parameter_list|(
name|IN
name|struct
name|_SERIAL_IO_INTERFACE
modifier|*
name|This
parameter_list|,
name|IN
name|UINT32
name|Control
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_SERIAL_GET_CONTROL_BITS
function_decl|)
parameter_list|(
name|IN
name|struct
name|_SERIAL_IO_INTERFACE
modifier|*
name|This
parameter_list|,
name|OUT
name|UINT32
modifier|*
name|Control
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_SERIAL_WRITE
function_decl|)
parameter_list|(
name|IN
name|struct
name|_SERIAL_IO_INTERFACE
modifier|*
name|This
parameter_list|,
name|IN
name|OUT
name|UINTN
modifier|*
name|BufferSize
parameter_list|,
name|IN
name|VOID
modifier|*
name|Buffer
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_SERIAL_READ
function_decl|)
parameter_list|(
name|IN
name|struct
name|_SERIAL_IO_INTERFACE
modifier|*
name|This
parameter_list|,
name|IN
name|OUT
name|UINTN
modifier|*
name|BufferSize
parameter_list|,
name|OUT
name|VOID
modifier|*
name|Buffer
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|UINT32
name|ControlMask
decl_stmt|;
comment|// current Attributes
name|UINT32
name|Timeout
decl_stmt|;
name|UINT64
name|BaudRate
decl_stmt|;
name|UINT32
name|ReceiveFifoDepth
decl_stmt|;
name|UINT32
name|DataBits
decl_stmt|;
name|UINT32
name|Parity
decl_stmt|;
name|UINT32
name|StopBits
decl_stmt|;
block|}
name|SERIAL_IO_MODE
typedef|;
end_typedef

begin_define
define|#
directive|define
name|SERIAL_IO_INTERFACE_REVISION
value|0x00010000
end_define

begin_typedef
typedef|typedef
struct|struct
name|_SERIAL_IO_INTERFACE
block|{
name|UINT32
name|Revision
decl_stmt|;
name|EFI_SERIAL_RESET
name|Reset
decl_stmt|;
name|EFI_SERIAL_SET_ATTRIBUTES
name|SetAttributes
decl_stmt|;
name|EFI_SERIAL_SET_CONTROL_BITS
name|SetControl
decl_stmt|;
name|EFI_SERIAL_GET_CONTROL_BITS
name|GetControl
decl_stmt|;
name|EFI_SERIAL_WRITE
name|Write
decl_stmt|;
name|EFI_SERIAL_READ
name|Read
decl_stmt|;
name|SERIAL_IO_MODE
modifier|*
name|Mode
decl_stmt|;
block|}
name|SERIAL_IO_INTERFACE
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

end_unit

