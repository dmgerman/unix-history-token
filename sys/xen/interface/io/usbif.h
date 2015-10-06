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

begin_comment
comment|/*  * Feature and Parameter Negotiation  * =================================  * The two halves of a Xen pvUSB driver utilize nodes within the XenStore to  * communicate capabilities and to negotiate operating parameters. This  * section enumerates these nodes which reside in the respective front and  * backend portions of the XenStore, following the XenBus convention.  *  * Any specified default value is in effect if the corresponding XenBus node  * is not present in the XenStore.  *  * XenStore nodes in sections marked "PRIVATE" are solely for use by the  * driver side whose XenBus tree contains them.  *  *****************************************************************************  *                            Backend XenBus Nodes  *****************************************************************************  *  *------------------ Backend Device Identification (PRIVATE) ------------------  *  * num-ports  *      Values:         unsigned [1...31]  *  *      Number of ports for this (virtual) USB host connector.  *  * usb-ver  *      Values:         unsigned [1...2]  *  *      USB version of this host connector: 1 = USB 1.1, 2 = USB 2.0.  *  * port/[1...31]  *      Values:         string  *  *      Physical USB device connected to the given port, e.g. "3-1.5".  *  *****************************************************************************  *                            Frontend XenBus Nodes  *****************************************************************************  *  *----------------------- Request Transport Parameters -----------------------  *  * event-channel  *      Values:         unsigned  *  *      The identifier of the Xen event channel used to signal activity  *      in the ring buffer.  *  * urb-ring-ref  *      Values:         unsigned  *  *      The Xen grant reference granting permission for the backend to map  *      the sole page in a single page sized ring buffer. This is the ring  *      buffer for urb requests.  *  * conn-ring-ref  *      Values:         unsigned  *  *      The Xen grant reference granting permission for the backend to map  *      the sole page in a single page sized ring buffer. This is the ring  *      buffer for connection/disconnection requests.  *  * protocol  *      Values:         string (XEN_IO_PROTO_ABI_*)  *      Default Value:  XEN_IO_PROTO_ABI_NATIVE  *  *      The machine ABI rules governing the format of all ring request and  *      response structures.  *  */
end_comment

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
comment|/*  *  USB pipe in usbif_request  *  *  - port number:	bits 0-4  *				(USB_MAXCHILDREN is 31)  *  *  - operation flag:	bit 5  *				(0 = submit urb,  *				 1 = unlink urb)  *  *  - direction:		bit 7  *				(0 = Host-to-Device [Out]  *				 1 = Device-to-Host [In])  *  *  - device address:	bits 8-14  *  *  - endpoint:		bits 15-18  *  *  - pipe type:	bits 30-31  *				(00 = isochronous, 01 = interrupt,  *				 10 = control, 11 = bulk)  */
end_comment

begin_define
define|#
directive|define
name|USBIF_PIPE_PORT_MASK
value|0x0000001f
end_define

begin_define
define|#
directive|define
name|USBIF_PIPE_UNLINK
value|0x00000020
end_define

begin_define
define|#
directive|define
name|USBIF_PIPE_DIR
value|0x00000080
end_define

begin_define
define|#
directive|define
name|USBIF_PIPE_DEV_MASK
value|0x0000007f
end_define

begin_define
define|#
directive|define
name|USBIF_PIPE_DEV_SHIFT
value|8
end_define

begin_define
define|#
directive|define
name|USBIF_PIPE_EP_MASK
value|0x0000000f
end_define

begin_define
define|#
directive|define
name|USBIF_PIPE_EP_SHIFT
value|15
end_define

begin_define
define|#
directive|define
name|USBIF_PIPE_TYPE_MASK
value|0x00000003
end_define

begin_define
define|#
directive|define
name|USBIF_PIPE_TYPE_SHIFT
value|30
end_define

begin_define
define|#
directive|define
name|USBIF_PIPE_TYPE_ISOC
value|0
end_define

begin_define
define|#
directive|define
name|USBIF_PIPE_TYPE_INT
value|1
end_define

begin_define
define|#
directive|define
name|USBIF_PIPE_TYPE_CTRL
value|2
end_define

begin_define
define|#
directive|define
name|USBIF_PIPE_TYPE_BULK
value|3
end_define

begin_define
define|#
directive|define
name|usbif_pipeportnum
parameter_list|(
name|pipe
parameter_list|)
value|((pipe)& USBIF_PIPE_PORT_MASK)
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
value|((pipe) | (portnum))
end_define

begin_define
define|#
directive|define
name|usbif_pipeunlink
parameter_list|(
name|pipe
parameter_list|)
value|((pipe)& USBIF_PIPE_UNLINK)
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
value|((pipe) | USBIF_PIPE_UNLINK)
end_define

begin_define
define|#
directive|define
name|usbif_pipein
parameter_list|(
name|pipe
parameter_list|)
value|((pipe)& USBIF_PIPE_DIR)
end_define

begin_define
define|#
directive|define
name|usbif_pipeout
parameter_list|(
name|pipe
parameter_list|)
value|(!usbif_pipein(pipe))
end_define

begin_define
define|#
directive|define
name|usbif_pipedevice
parameter_list|(
name|pipe
parameter_list|)
define|\
value|(((pipe)>> USBIF_PIPE_DEV_SHIFT)& USBIF_PIPE_DEV_MASK)
end_define

begin_define
define|#
directive|define
name|usbif_pipeendpoint
parameter_list|(
name|pipe
parameter_list|)
define|\
value|(((pipe)>> USBIF_PIPE_EP_SHIFT)& USBIF_PIPE_EP_MASK)
end_define

begin_define
define|#
directive|define
name|usbif_pipetype
parameter_list|(
name|pipe
parameter_list|)
define|\
value|(((pipe)>> USBIF_PIPE_TYPE_SHIFT)& USBIF_PIPE_TYPE_MASK)
end_define

begin_define
define|#
directive|define
name|usbif_pipeisoc
parameter_list|(
name|pipe
parameter_list|)
value|(usbif_pipetype(pipe) == USBIF_PIPE_TYPE_ISOC)
end_define

begin_define
define|#
directive|define
name|usbif_pipeint
parameter_list|(
name|pipe
parameter_list|)
value|(usbif_pipetype(pipe) == USBIF_PIPE_TYPE_INT)
end_define

begin_define
define|#
directive|define
name|usbif_pipectrl
parameter_list|(
name|pipe
parameter_list|)
value|(usbif_pipetype(pipe) == USBIF_PIPE_TYPE_CTRL)
end_define

begin_define
define|#
directive|define
name|usbif_pipebulk
parameter_list|(
name|pipe
parameter_list|)
value|(usbif_pipetype(pipe) == USBIF_PIPE_TYPE_BULK)
end_define

begin_define
define|#
directive|define
name|USBIF_MAX_SEGMENTS_PER_REQUEST
value|(16)
end_define

begin_define
define|#
directive|define
name|USBIF_MAX_PORTNR
value|31
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
define|#
directive|define
name|USBIF_SPEED_NONE
value|0
define|#
directive|define
name|USBIF_SPEED_LOW
value|1
define|#
directive|define
name|USBIF_SPEED_FULL
value|2
define|#
directive|define
name|USBIF_SPEED_HIGH
value|3
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

