begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2003-2005 Craig Boston  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *      This product includes software developed by Bill Paul.  * 4. Neither the name of the author nor the names of any co-contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY Bill Paul AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL Bill Paul, THE VOICES IN HIS HEAD OR  * THE CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,  * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,  * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS;  * OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,  * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR  * OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF  * ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_USB_IF_CDCEREG_H_
end_ifndef

begin_define
define|#
directive|define
name|_USB_IF_CDCEREG_H_
end_define

begin_struct
struct|struct
name|cdce_type
block|{
name|struct
name|usb_devno
name|cdce_dev
decl_stmt|;
name|u_int16_t
name|cdce_flags
decl_stmt|;
define|#
directive|define
name|CDCE_ZAURUS
value|1
define|#
directive|define
name|CDCE_NO_UNION
value|2
block|}
struct|;
end_struct

begin_struct
struct|struct
name|cdce_softc
block|{
name|struct
name|ifnet
modifier|*
name|cdce_ifp
decl_stmt|;
define|#
directive|define
name|GET_IFP
parameter_list|(
name|sc
parameter_list|)
value|((sc)->cdce_ifp)
name|struct
name|ifmedia
name|cdce_ifmedia
decl_stmt|;
name|usbd_device_handle
name|cdce_udev
decl_stmt|;
name|usbd_interface_handle
name|cdce_data_iface
decl_stmt|;
name|int
name|cdce_bulkin_no
decl_stmt|;
name|usbd_pipe_handle
name|cdce_bulkin_pipe
decl_stmt|;
name|int
name|cdce_bulkout_no
decl_stmt|;
name|usbd_pipe_handle
name|cdce_bulkout_pipe
decl_stmt|;
name|char
name|cdce_dying
decl_stmt|;
name|device_t
name|cdce_dev
decl_stmt|;
name|int
name|cdce_unit
decl_stmt|;
name|struct
name|ue_cdata
name|cdce_cdata
decl_stmt|;
name|struct
name|timeval
name|cdce_rx_notice
decl_stmt|;
name|int
name|cdce_rxeof_errors
decl_stmt|;
name|u_int16_t
name|cdce_flags
decl_stmt|;
name|struct
name|mtx
name|cdce_mtx
decl_stmt|;
name|struct
name|usb_qdat
name|q
decl_stmt|;
name|char
name|devinfo
index|[
literal|1024
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* We are still under Giant */
end_comment

begin_if
if|#
directive|if
literal|0
end_if

begin_define
define|#
directive|define
name|CDCE_LOCK
parameter_list|(
name|_sc
parameter_list|)
value|mtx_lock(&(_sc)->cdce_mtx)
end_define

begin_define
define|#
directive|define
name|CDCE_UNLOCK
parameter_list|(
name|_sc
parameter_list|)
value|mtx_unlock(&(_sc)->cdce_mtx)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|CDCE_LOCK
parameter_list|(
name|_sc
parameter_list|)
end_define

begin_define
define|#
directive|define
name|CDCE_UNLOCK
parameter_list|(
name|_sc
parameter_list|)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _USB_IF_CDCEREG_H_ */
end_comment

end_unit

