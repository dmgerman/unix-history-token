begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * usbif.h  *  * USB I/O interface for Xen guest OSes.  *  * Copyright (C) 2009, FUJITSU LABORATORIES LTD.  * Author: Noboru Iwamatsu<n_iwamatsu@jp.fujitsu.com>  *  * Permission is hereby granted, free of charge, to any person obtaining a copy  * of this software and associated documentation files (the "Software"), to  * deal in the Software without restriction, including without limitation the  * rights to use, copy, modify, merge, publish, distribute, sublicense, and/or  * sell copies of the Software, and to permit persons to whom the Software is  * furnished to do so, subject to the following conditions:  *  * The above copyright notice and this permission notice shall be included in  * all copies or substantial portions of the Software.  *  * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR  * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,  * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE  * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER  * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING  * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER  * DEALINGS IN THE SOFTWARE.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__XEN_PUBLIC_IO_USBIF_H__
end_ifndef

begin_define
define|#
directive|define
name|__XEN_PUBLIC_IO_USBIF_H__
end_define

begin_include
include|#
directive|include
file|"ring.h"
end_include

begin_include
include|#
directive|include
file|"../grant_table.h"
end_include

begin_enum
enum|enum
name|usb_spec_version
block|{
name|USB_VER_UNKNOWN
init|=
literal|0
block|,
name|USB_VER_USB11
block|,
name|USB_VER_USB20
block|,
name|USB_VER_USB30
block|,
comment|/* not supported yet */
block|}
enum|;
end_enum

begin_comment
comment|/*  *  USB pipe in usbif_request  *  *  bits 0-5 are specific bits for virtual USB driver.  *  bits 7-31 are standard urb pipe.  *  *  - port number(NEW):	bits 0-4  *  				(USB_MAXCHILDREN is 31)  *  *  - operation flag(NEW):	bit 5  *  				(0 = submit urb,  *  				 1 = unlink urb)  *  *  - direction:		bit 7  *  				(0 = Host-to-Device [Out]  *                           1 = Device-to-Host [In])  *  *  - device address:	bits 8-14  *  *  - endpoint:		bits 15-18  *  *  - pipe type:		bits 30-31  *  				(00 = isochronous, 01 = interrupt,  *                           10 = control, 11 = bulk)  */
end_comment

begin_define
define|#
directive|define
name|usbif_pipeportnum
parameter_list|(
name|pipe
parameter_list|)
value|((pipe)& 0x1f)
end_define

begin_define
define|#
directive|define
name|usbif_setportnum_pipe
parameter_list|(
name|pipe
parameter_list|,
name|portnum
parameter_list|)
define|\
value|((pipe)|(portnum))
end_define

begin_define
define|#
directive|define
name|usbif_pipeunlink
parameter_list|(
name|pipe
parameter_list|)
value|((pipe)& 0x20)
end_define

begin_define
define|#
directive|define
name|usbif_pipesubmit
parameter_list|(
name|pipe
parameter_list|)
value|(!usbif_pipeunlink(pipe))
end_define

begin_define
define|#
directive|define
name|usbif_setunlink_pipe
parameter_list|(
name|pipe
parameter_list|)
value|((pipe)|(0x20))
end_define

begin_define
define|#
directive|define
name|USBIF_BACK_MAX_PENDING_REQS
value|(128)
end_define

begin_define
define|#
directive|define
name|USBIF_MAX_SEGMENTS_PER_REQUEST
value|(16)
end_define

begin_comment
comment|/*  * RING for transferring urbs.  */
end_comment

begin_struct
struct|struct
name|usbif_request_segment
block|{
name|grant_ref_t
name|gref
decl_stmt|;
name|uint16_t
name|offset
decl_stmt|;
name|uint16_t
name|length
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|usbif_urb_request
block|{
name|uint16_t
name|id
decl_stmt|;
comment|/* request id */
name|uint16_t
name|nr_buffer_segs
decl_stmt|;
comment|/* number of urb->transfer_buffer segments */
comment|/* basic urb parameter */
name|uint32_t
name|pipe
decl_stmt|;
name|uint16_t
name|transfer_flags
decl_stmt|;
name|uint16_t
name|buffer_length
decl_stmt|;
union|union
block|{
name|uint8_t
name|ctrl
index|[
literal|8
index|]
decl_stmt|;
comment|/* setup_packet (Ctrl) */
struct|struct
block|{
name|uint16_t
name|interval
decl_stmt|;
comment|/* maximum (1024*8) in usb core */
name|uint16_t
name|start_frame
decl_stmt|;
comment|/* start frame */
name|uint16_t
name|number_of_packets
decl_stmt|;
comment|/* number of ISO packet */
name|uint16_t
name|nr_frame_desc_segs
decl_stmt|;
comment|/* number of iso_frame_desc segments */
block|}
name|isoc
struct|;
struct|struct
block|{
name|uint16_t
name|interval
decl_stmt|;
comment|/* maximum (1024*8) in usb core */
name|uint16_t
name|pad
index|[
literal|3
index|]
decl_stmt|;
block|}
name|intr
struct|;
struct|struct
block|{
name|uint16_t
name|unlink_id
decl_stmt|;
comment|/* unlink request id */
name|uint16_t
name|pad
index|[
literal|3
index|]
decl_stmt|;
block|}
name|unlink
struct|;
block|}
name|u
union|;
comment|/* urb data segments */
name|struct
name|usbif_request_segment
name|seg
index|[
name|USBIF_MAX_SEGMENTS_PER_REQUEST
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|usbif_urb_request
name|usbif_urb_request_t
typedef|;
end_typedef

begin_struct
struct|struct
name|usbif_urb_response
block|{
name|uint16_t
name|id
decl_stmt|;
comment|/* request id */
name|uint16_t
name|start_frame
decl_stmt|;
comment|/* start frame (ISO) */
name|int32_t
name|status
decl_stmt|;
comment|/* status (non-ISO) */
name|int32_t
name|actual_length
decl_stmt|;
comment|/* actual transfer length */
name|int32_t
name|error_count
decl_stmt|;
comment|/* number of ISO errors */
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|usbif_urb_response
name|usbif_urb_response_t
typedef|;
end_typedef

begin_expr_stmt
name|DEFINE_RING_TYPES
argument_list|(
name|usbif_urb
argument_list|,
expr|struct
name|usbif_urb_request
argument_list|,
expr|struct
name|usbif_urb_response
argument_list|)
expr_stmt|;
end_expr_stmt

begin_define
define|#
directive|define
name|USB_URB_RING_SIZE
value|__CONST_RING_SIZE(usbif_urb, PAGE_SIZE)
end_define

begin_comment
comment|/*  * RING for notifying connect/disconnect events to frontend  */
end_comment

begin_struct
struct|struct
name|usbif_conn_request
block|{
name|uint16_t
name|id
decl_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|usbif_conn_request
name|usbif_conn_request_t
typedef|;
end_typedef

begin_struct
struct|struct
name|usbif_conn_response
block|{
name|uint16_t
name|id
decl_stmt|;
comment|/* request id */
name|uint8_t
name|portnum
decl_stmt|;
comment|/* port number */
name|uint8_t
name|speed
decl_stmt|;
comment|/* usb_device_speed */
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|usbif_conn_response
name|usbif_conn_response_t
typedef|;
end_typedef

begin_expr_stmt
name|DEFINE_RING_TYPES
argument_list|(
name|usbif_conn
argument_list|,
expr|struct
name|usbif_conn_request
argument_list|,
expr|struct
name|usbif_conn_response
argument_list|)
expr_stmt|;
end_expr_stmt

begin_define
define|#
directive|define
name|USB_CONN_RING_SIZE
value|__CONST_RING_SIZE(usbif_conn, PAGE_SIZE)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __XEN_PUBLIC_IO_USBIF_H__ */
end_comment

end_unit

