begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1997, 1998, 1999, 2000  *	Bill Paul<wpaul@ee.columbia.edu>.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by Bill Paul.  * 4. Neither the name of the author nor the names of any co-contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY Bill Paul AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL Bill Paul OR THE VOICES IN HIS HEAD  * BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR  * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF  * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS  * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN  * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)  * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF  * THE POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_USB_ETHERSUBR_H_
end_ifndef

begin_define
define|#
directive|define
name|_USB_ETHERSUBR_H_
end_define

begin_include
include|#
directive|include
file|<sys/bus.h>
end_include

begin_include
include|#
directive|include
file|<sys/module.h>
end_include

begin_include
include|#
directive|include
file|<dev/usb/usbdi.h>
end_include

begin_define
define|#
directive|define
name|UE_TX_LIST_CNT
value|1
end_define

begin_define
define|#
directive|define
name|UE_RX_LIST_CNT
value|1
end_define

begin_define
define|#
directive|define
name|UE_BUFSZ
value|1536
end_define

begin_struct
struct|struct
name|usb_qdat
block|{
name|struct
name|ifnet
modifier|*
name|ifp
decl_stmt|;
name|void
function_decl|(
modifier|*
name|if_rxstart
function_decl|)
parameter_list|(
name|struct
name|ifnet
modifier|*
parameter_list|)
function_decl|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|ue_chain
block|{
name|void
modifier|*
name|ue_sc
decl_stmt|;
name|usbd_xfer_handle
name|ue_xfer
decl_stmt|;
name|char
modifier|*
name|ue_buf
decl_stmt|;
name|struct
name|mbuf
modifier|*
name|ue_mbuf
decl_stmt|;
name|int
name|ue_idx
decl_stmt|;
name|usbd_status
name|ue_status
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|ue_cdata
block|{
name|struct
name|ue_chain
name|ue_tx_chain
index|[
name|UE_TX_LIST_CNT
index|]
decl_stmt|;
name|struct
name|ue_chain
name|ue_rx_chain
index|[
name|UE_RX_LIST_CNT
index|]
decl_stmt|;
name|void
modifier|*
name|ue_ibuf
decl_stmt|;
name|int
name|ue_tx_prod
decl_stmt|;
name|int
name|ue_tx_cons
decl_stmt|;
name|int
name|ue_tx_cnt
decl_stmt|;
name|int
name|ue_rx_prod
decl_stmt|;
block|}
struct|;
end_struct

begin_function_decl
name|void
name|usb_register_netisr
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|usb_ether_input
parameter_list|(
name|struct
name|mbuf
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|usb_tx_done
parameter_list|(
name|struct
name|mbuf
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|mbuf
modifier|*
name|usb_ether_newbuf
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|usb_ether_rx_list_init
parameter_list|(
name|void
modifier|*
parameter_list|,
name|struct
name|ue_cdata
modifier|*
parameter_list|,
name|usbd_device_handle
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|usb_ether_tx_list_init
parameter_list|(
name|void
modifier|*
parameter_list|,
name|struct
name|ue_cdata
modifier|*
parameter_list|,
name|usbd_device_handle
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|usb_ether_rx_list_free
parameter_list|(
name|struct
name|ue_cdata
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|usb_ether_tx_list_free
parameter_list|(
name|struct
name|ue_cdata
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _USB_ETHERSUBR_H_ */
end_comment

end_unit

