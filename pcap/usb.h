begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2006 Paolo Abeni (Italy)  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  *  * 1. Redistributions of source code must retain the above copyright  * notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  * notice, this list of conditions and the following disclaimer in the  * documentation and/or other materials provided with the distribution.  * 3. The name of the author may not be used to endorse or promote   * products derived from this software without specific prior written   * permission.  *  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS  * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT  * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR  * A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT  * OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,  * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT  * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE  * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  * Basic USB data struct  * By Paolo Abeni<paolo.abeni@email.it>  *  * @(#) $Header: /tcpdump/master/libpcap/pcap/usb.h,v 1.6 2007/09/22 02:06:08 guy Exp $  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_PCAP_USB_STRUCTS_H__
end_ifndef

begin_define
define|#
directive|define
name|_PCAP_USB_STRUCTS_H__
end_define

begin_comment
comment|/*   * possible transfer mode  */
end_comment

begin_define
define|#
directive|define
name|URB_TRANSFER_IN
value|0x80
end_define

begin_define
define|#
directive|define
name|URB_ISOCHRONOUS
value|0x0
end_define

begin_define
define|#
directive|define
name|URB_INTERRUPT
value|0x1
end_define

begin_define
define|#
directive|define
name|URB_CONTROL
value|0x2
end_define

begin_define
define|#
directive|define
name|URB_BULK
value|0x3
end_define

begin_comment
comment|/*  * possible event type  */
end_comment

begin_define
define|#
directive|define
name|URB_SUBMIT
value|'S'
end_define

begin_define
define|#
directive|define
name|URB_COMPLETE
value|'C'
end_define

begin_define
define|#
directive|define
name|URB_ERROR
value|'E'
end_define

begin_comment
comment|/*  * USB setup header as defined in USB specification.  * Appears at the front of each packet in DLT_USB captures.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_usb_setup
block|{
name|u_int8_t
name|bmRequestType
decl_stmt|;
name|u_int8_t
name|bRequest
decl_stmt|;
name|u_int16_t
name|wValue
decl_stmt|;
name|u_int16_t
name|wIndex
decl_stmt|;
name|u_int16_t
name|wLength
decl_stmt|;
block|}
name|pcap_usb_setup
typedef|;
end_typedef

begin_comment
comment|/*  * Header prepended by linux kernel to each event.  * Appears at the front of each packet in DLT_USB_LINUX captures.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_usb_header
block|{
name|u_int64_t
name|id
decl_stmt|;
name|u_int8_t
name|event_type
decl_stmt|;
name|u_int8_t
name|transfer_type
decl_stmt|;
name|u_int8_t
name|endpoint_number
decl_stmt|;
name|u_int8_t
name|device_address
decl_stmt|;
name|u_int16_t
name|bus_id
decl_stmt|;
name|char
name|setup_flag
decl_stmt|;
comment|/*if !=0 the urb setup header is not present*/
name|char
name|data_flag
decl_stmt|;
comment|/*if !=0 no urb data is present*/
name|int64_t
name|ts_sec
decl_stmt|;
name|int32_t
name|ts_usec
decl_stmt|;
name|int32_t
name|status
decl_stmt|;
name|u_int32_t
name|urb_len
decl_stmt|;
name|u_int32_t
name|data_len
decl_stmt|;
comment|/* amount of urb data really present in this event*/
name|pcap_usb_setup
name|setup
decl_stmt|;
block|}
name|pcap_usb_header
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

end_unit

