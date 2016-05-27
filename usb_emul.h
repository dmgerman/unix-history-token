begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2014 Leon Dang<ldang@nahannisys.com>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_USB_EMUL_H_
end_ifndef

begin_define
define|#
directive|define
name|_USB_EMUL_H_
end_define

begin_include
include|#
directive|include
file|<stdlib.h>
end_include

begin_include
include|#
directive|include
file|<sys/linker_set.h>
end_include

begin_include
include|#
directive|include
file|<pthread.h>
end_include

begin_define
define|#
directive|define
name|USB_MAX_XFER_BLOCKS
value|8
end_define

begin_define
define|#
directive|define
name|USB_XFER_OUT
value|0
end_define

begin_define
define|#
directive|define
name|USB_XFER_IN
value|1
end_define

begin_struct_decl
struct_decl|struct
name|usb_hci
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|usb_device_request
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|usb_data_xfer
struct_decl|;
end_struct_decl

begin_comment
comment|/* Device emulation handlers */
end_comment

begin_struct
struct|struct
name|usb_devemu
block|{
name|char
modifier|*
name|ue_emu
decl_stmt|;
comment|/* name of device emulation */
name|int
name|ue_usbver
decl_stmt|;
comment|/* usb version: 2 or 3 */
name|int
name|ue_usbspeed
decl_stmt|;
comment|/* usb device speed */
comment|/* instance creation */
name|void
modifier|*
function_decl|(
modifier|*
name|ue_init
function_decl|)
parameter_list|(
name|struct
name|usb_hci
modifier|*
name|hci
parameter_list|,
name|char
modifier|*
name|opt
parameter_list|)
function_decl|;
comment|/* handlers */
name|int
function_decl|(
modifier|*
name|ue_request
function_decl|)
parameter_list|(
name|void
modifier|*
name|sc
parameter_list|,
name|struct
name|usb_data_xfer
modifier|*
name|xfer
parameter_list|)
function_decl|;
name|int
function_decl|(
modifier|*
name|ue_data
function_decl|)
parameter_list|(
name|void
modifier|*
name|sc
parameter_list|,
name|struct
name|usb_data_xfer
modifier|*
name|xfer
parameter_list|,
name|int
name|dir
parameter_list|,
name|int
name|epctx
parameter_list|)
function_decl|;
name|int
function_decl|(
modifier|*
name|ue_reset
function_decl|)
parameter_list|(
name|void
modifier|*
name|sc
parameter_list|)
function_decl|;
name|int
function_decl|(
modifier|*
name|ue_remove
function_decl|)
parameter_list|(
name|void
modifier|*
name|sc
parameter_list|)
function_decl|;
name|int
function_decl|(
modifier|*
name|ue_stop
function_decl|)
parameter_list|(
name|void
modifier|*
name|sc
parameter_list|)
function_decl|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|USB_EMUL_SET
parameter_list|(
name|x
parameter_list|)
value|DATA_SET(usb_emu_set, x);
end_define

begin_comment
comment|/*  * USB device events to notify HCI when state changes  */
end_comment

begin_enum
enum|enum
name|hci_usbev
block|{
name|USBDEV_ATTACH
block|,
name|USBDEV_RESET
block|,
name|USBDEV_STOP
block|,
name|USBDEV_REMOVE
block|, }
enum|;
end_enum

begin_comment
comment|/* usb controller, ie xhci, ehci */
end_comment

begin_struct
struct|struct
name|usb_hci
block|{
name|int
function_decl|(
modifier|*
name|hci_intr
function_decl|)
parameter_list|(
name|struct
name|usb_hci
modifier|*
name|hci
parameter_list|,
name|int
name|epctx
parameter_list|)
function_decl|;
name|int
function_decl|(
modifier|*
name|hci_event
function_decl|)
parameter_list|(
name|struct
name|usb_hci
modifier|*
name|hci
parameter_list|,
name|enum
name|hci_usbev
name|evid
parameter_list|,
name|void
modifier|*
name|param
parameter_list|)
function_decl|;
name|void
modifier|*
name|hci_sc
decl_stmt|;
comment|/* private softc for hci */
comment|/* controller managed fields */
name|int
name|hci_address
decl_stmt|;
name|int
name|hci_port
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * Each xfer block is mapped to the hci transfer block.  * On input into the device handler, blen is set to the lenght of buf.  * The device handler is to update blen to reflect on the residual size  * of the buffer, i.e. len(buf) - len(consumed).  */
end_comment

begin_struct
struct|struct
name|usb_data_xfer_block
block|{
name|void
modifier|*
name|buf
decl_stmt|;
comment|/* IN or OUT pointer */
name|int
name|blen
decl_stmt|;
comment|/* in:len(buf), out:len(remaining) */
name|int
name|bdone
decl_stmt|;
comment|/* bytes transferred */
name|uint32_t
name|processed
decl_stmt|;
comment|/* device processed this + errcode */
name|void
modifier|*
name|hci_data
decl_stmt|;
comment|/* HCI private reference */
name|int
name|ccs
decl_stmt|;
name|uint32_t
name|streamid
decl_stmt|;
name|uint64_t
name|trbnext
decl_stmt|;
comment|/* next TRB guest address */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|usb_data_xfer
block|{
name|struct
name|usb_data_xfer_block
name|data
index|[
name|USB_MAX_XFER_BLOCKS
index|]
decl_stmt|;
name|struct
name|usb_device_request
modifier|*
name|ureq
decl_stmt|;
comment|/* setup ctl request */
name|int
name|ndata
decl_stmt|;
comment|/* # of data items */
name|int
name|head
decl_stmt|;
name|int
name|tail
decl_stmt|;
name|pthread_mutex_t
name|mtx
decl_stmt|;
block|}
struct|;
end_struct

begin_enum
enum|enum
name|USB_ERRCODE
block|{
name|USB_ACK
block|,
name|USB_NAK
block|,
name|USB_STALL
block|,
name|USB_NYET
block|,
name|USB_ERR
block|,
name|USB_SHORT
block|}
enum|;
end_enum

begin_define
define|#
directive|define
name|USB_DATA_GET_ERRCODE
parameter_list|(
name|x
parameter_list|)
value|(x)->processed>> 8
end_define

begin_define
define|#
directive|define
name|USB_DATA_SET_ERRCODE
parameter_list|(
name|x
parameter_list|,
name|e
parameter_list|)
value|do {				\ 			(x)->processed = ((x)->processed& 0xFF) | (e<< 8); \ 		} while (0)
end_define

begin_define
define|#
directive|define
name|USB_DATA_OK
parameter_list|(
name|x
parameter_list|,
name|i
parameter_list|)
value|((x)->data[(i)].buf != NULL)
end_define

begin_define
define|#
directive|define
name|USB_DATA_XFER_INIT
parameter_list|(
name|x
parameter_list|)
value|do {					\ 			memset((x), 0, sizeof(*(x)));			\ 			pthread_mutex_init(&((x)->mtx), NULL);		\ 		} while (0)
end_define

begin_define
define|#
directive|define
name|USB_DATA_XFER_RESET
parameter_list|(
name|x
parameter_list|)
value|do {					\ 			memset((x)->data, 0, sizeof((x)->data));	\ 			(x)->ndata = 0;					\ 			(x)->head = (x)->tail = 0;			\ 		} while (0)
end_define

begin_define
define|#
directive|define
name|USB_DATA_XFER_LOCK
parameter_list|(
name|x
parameter_list|)
value|do {					\ 			pthread_mutex_lock(&((x)->mtx));		\ 		} while (0)
end_define

begin_define
define|#
directive|define
name|USB_DATA_XFER_UNLOCK
parameter_list|(
name|x
parameter_list|)
value|do {					\ 			pthread_mutex_unlock(&((x)->mtx));		\ 		} while (0)
end_define

begin_function_decl
name|struct
name|usb_devemu
modifier|*
name|usb_emu_finddev
parameter_list|(
name|char
modifier|*
name|name
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|usb_data_xfer_block
modifier|*
name|usb_data_xfer_append
parameter_list|(
name|struct
name|usb_data_xfer
modifier|*
name|xfer
parameter_list|,
name|void
modifier|*
name|buf
parameter_list|,
name|int
name|blen
parameter_list|,
name|void
modifier|*
name|hci_data
parameter_list|,
name|int
name|ccs
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _USB_EMUL_H_ */
end_comment

end_unit

