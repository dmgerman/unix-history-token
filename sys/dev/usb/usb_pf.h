begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1990, 1991, 1993  *	The Regents of the University of California.  All rights reserved.  *  * This code is derived from the Stanford/CMU enet packet filter,  * (net/enet.c) distributed as part of 4.3BSD, and code contributed  * to Berkeley by Steven McCanne and Van Jacobson both of Lawrence  * Berkeley Laboratory.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_DEV_USB_PF_H
end_ifndef

begin_define
define|#
directive|define
name|_DEV_USB_PF_H
end_define

begin_struct
struct|struct
name|usbpf_pkthdr
block|{
name|uint32_t
name|up_busunit
decl_stmt|;
comment|/* Host controller unit number */
name|uint8_t
name|up_address
decl_stmt|;
comment|/* USB device address */
name|uint8_t
name|up_endpoint
decl_stmt|;
comment|/* USB endpoint */
name|uint8_t
name|up_type
decl_stmt|;
comment|/* points SUBMIT / DONE */
name|uint8_t
name|up_xfertype
decl_stmt|;
comment|/* Transfer type */
name|uint32_t
name|up_flags
decl_stmt|;
comment|/* Transfer flags */
define|#
directive|define
name|USBPF_FLAG_FORCE_SHORT_XFER
value|(1<< 0)
define|#
directive|define
name|USBPF_FLAG_SHORT_XFER_OK
value|(1<< 1)
define|#
directive|define
name|USBPF_FLAG_SHORT_FRAMES_OK
value|(1<< 2)
define|#
directive|define
name|USBPF_FLAG_PIPE_BOF
value|(1<< 3)
define|#
directive|define
name|USBPF_FLAG_PROXY_BUFFER
value|(1<< 4)
define|#
directive|define
name|USBPF_FLAG_EXT_BUFFER
value|(1<< 5)
define|#
directive|define
name|USBPF_FLAG_MANUAL_STATUS
value|(1<< 6)
define|#
directive|define
name|USBPF_FLAG_NO_PIPE_OK
value|(1<< 7)
define|#
directive|define
name|USBPF_FLAG_STALL_PIPE
value|(1<< 8)
name|uint32_t
name|up_status
decl_stmt|;
comment|/* Transfer status */
define|#
directive|define
name|USBPF_STATUS_OPEN
value|(1<< 0)
define|#
directive|define
name|USBPF_STATUS_TRANSFERRING
value|(1<< 1)
define|#
directive|define
name|USBPF_STATUS_DID_DMA_DELAY
value|(1<< 2)
define|#
directive|define
name|USBPF_STATUS_DID_CLOSE
value|(1<< 3)
define|#
directive|define
name|USBPF_STATUS_DRAINING
value|(1<< 4)
define|#
directive|define
name|USBPF_STATUS_STARTED
value|(1<< 5)
define|#
directive|define
name|USBPF_STATUS_BW_RECLAIMED
value|(1<< 6)
define|#
directive|define
name|USBPF_STATUS_CONTROL_XFR
value|(1<< 7)
define|#
directive|define
name|USBPF_STATUS_CONTROL_HDR
value|(1<< 8)
define|#
directive|define
name|USBPF_STATUS_CONTROL_ACT
value|(1<< 9)
define|#
directive|define
name|USBPF_STATUS_CONTROL_STALL
value|(1<< 10)
define|#
directive|define
name|USBPF_STATUS_SHORT_FRAMES_OK
value|(1<< 11)
define|#
directive|define
name|USBPF_STATUS_SHORT_XFER_OK
value|(1<< 12)
if|#
directive|if
name|USB_HAVE_BUSDMA
define|#
directive|define
name|USBPF_STATUS_BDMA_ENABLE
value|(1<< 13)
define|#
directive|define
name|USBPF_STATUS_BDMA_NO_POST_SYNC
value|(1<< 14)
define|#
directive|define
name|USBPF_STATUS_BDMA_SETUP
value|(1<< 15)
endif|#
directive|endif
define|#
directive|define
name|USBPF_STATUS_ISOCHRONOUS_XFR
value|(1<< 16)
define|#
directive|define
name|USBPF_STATUS_CURR_DMA_SET
value|(1<< 17)
define|#
directive|define
name|USBPF_STATUS_CAN_CANCEL_IMMED
value|(1<< 18)
define|#
directive|define
name|USBPF_STATUS_DOING_CALLBACK
value|(1<< 19)
name|uint32_t
name|up_length
decl_stmt|;
comment|/* Total data length (submit/actual) */
name|uint32_t
name|up_frames
decl_stmt|;
comment|/* USB frame number (submit/actual) */
name|uint32_t
name|up_error
decl_stmt|;
comment|/* usb_error_t */
name|uint32_t
name|up_interval
decl_stmt|;
comment|/* for interrupt and isoc */
comment|/* sizeof(struct usbpf_pkthdr) == 128 bytes */
name|uint8_t
name|up_reserved
index|[
literal|96
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|USBPF_HDR_LEN
value|128
end_define

begin_define
define|#
directive|define
name|USBPF_XFERTAP_SUBMIT
value|0
end_define

begin_define
define|#
directive|define
name|USBPF_XFERTAP_DONE
value|1
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_function_decl
name|void
name|usbpf_attach
parameter_list|(
name|struct
name|usb_bus
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|usbpf_detach
parameter_list|(
name|struct
name|usb_bus
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|usbpf_xfertap
parameter_list|(
name|struct
name|usb_xfer
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

end_unit

