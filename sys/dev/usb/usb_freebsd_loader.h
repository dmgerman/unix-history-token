begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $FreeBSD$ */
end_comment

begin_comment
comment|/*-  * Copyright (c) 2013 Hans Petter Selasky. All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
end_comment

begin_comment
comment|/*  * Including this file is mandatory for all USB related c-files in the loader.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_USB_FREEBSD_LOADER_H_
end_ifndef

begin_define
define|#
directive|define
name|_USB_FREEBSD_LOADER_H_
end_define

begin_comment
comment|/* Default USB configuration */
end_comment

begin_define
define|#
directive|define
name|USB_HAVE_UGEN
value|0
end_define

begin_define
define|#
directive|define
name|USB_HAVE_DEVCTL
value|0
end_define

begin_define
define|#
directive|define
name|USB_HAVE_BUSDMA
value|1
end_define

begin_define
define|#
directive|define
name|USB_HAVE_COMPAT_LINUX
value|0
end_define

begin_define
define|#
directive|define
name|USB_HAVE_USER_IO
value|0
end_define

begin_define
define|#
directive|define
name|USB_HAVE_MBUF
value|0
end_define

begin_define
define|#
directive|define
name|USB_HAVE_TT_SUPPORT
value|1
end_define

begin_define
define|#
directive|define
name|USB_HAVE_POWERD
value|1
end_define

begin_define
define|#
directive|define
name|USB_HAVE_MSCTEST
value|1
end_define

begin_define
define|#
directive|define
name|USB_HAVE_MSCTEST_DETACH
value|0
end_define

begin_define
define|#
directive|define
name|USB_HAVE_PF
value|0
end_define

begin_define
define|#
directive|define
name|USB_HAVE_ROOT_MOUNT_HOLD
value|0
end_define

begin_define
define|#
directive|define
name|USB_HAVE_ID_SECTION
value|0
end_define

begin_define
define|#
directive|define
name|USB_HAVE_PER_BUS_PROCESS
value|0
end_define

begin_define
define|#
directive|define
name|USB_HAVE_FIXED_ENDPOINT
value|0
end_define

begin_define
define|#
directive|define
name|USB_HAVE_FIXED_IFACE
value|0
end_define

begin_define
define|#
directive|define
name|USB_HAVE_FIXED_CONFIG
value|0
end_define

begin_define
define|#
directive|define
name|USB_HAVE_FIXED_PORT
value|0
end_define

begin_define
define|#
directive|define
name|USB_HAVE_DISABLE_ENUM
value|0
end_define

begin_define
define|#
directive|define
name|USB_CALLOUT_ZERO_TICKS
value|1
end_define

begin_define
define|#
directive|define
name|USB_TD_GET_PROC
parameter_list|(
name|td
parameter_list|)
value|(td)->td_proc
end_define

begin_define
define|#
directive|define
name|USB_PROC_GET_GID
parameter_list|(
name|td
parameter_list|)
value|(td)->p_pgid
end_define

begin_if
if|#
directive|if
operator|(
operator|!
name|defined
argument_list|(
name|USB_HOST_ALIGN
argument_list|)
operator|)
operator|||
operator|(
name|USB_HOST_ALIGN
operator|<=
literal|0
operator|)
end_if

begin_comment
comment|/* Use default value. */
end_comment

begin_undef
undef|#
directive|undef
name|USB_HOST_ALIGN
end_undef

begin_define
define|#
directive|define
name|USB_HOST_ALIGN
value|8
end_define

begin_comment
comment|/* bytes, must be power of two */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Sanity check for USB_HOST_ALIGN: Verify power of two. */
end_comment

begin_if
if|#
directive|if
operator|(
operator|(
operator|-
name|USB_HOST_ALIGN
operator|)
operator|&
name|USB_HOST_ALIGN
operator|)
operator|!=
name|USB_HOST_ALIGN
end_if

begin_error
error|#
directive|error
literal|"USB_HOST_ALIGN is not power of two."
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|USB_FS_ISOC_UFRAME_MAX
value|4
end_define

begin_comment
comment|/* exclusive unit */
end_comment

begin_define
define|#
directive|define
name|USB_BUS_MAX
value|256
end_define

begin_comment
comment|/* units */
end_comment

begin_define
define|#
directive|define
name|USB_MAX_DEVICES
value|128
end_define

begin_comment
comment|/* units */
end_comment

begin_define
define|#
directive|define
name|USB_CONFIG_MAX
value|65535
end_define

begin_comment
comment|/* bytes */
end_comment

begin_define
define|#
directive|define
name|USB_IFACE_MAX
value|32
end_define

begin_comment
comment|/* units */
end_comment

begin_define
define|#
directive|define
name|USB_FIFO_MAX
value|128
end_define

begin_comment
comment|/* units */
end_comment

begin_define
define|#
directive|define
name|USB_MAX_EP_UNITS
value|32
end_define

begin_comment
comment|/* units */
end_comment

begin_define
define|#
directive|define
name|USB_MAX_EP_STREAMS
value|8
end_define

begin_comment
comment|/* units */
end_comment

begin_define
define|#
directive|define
name|USB_MAX_PORTS
value|255
end_define

begin_comment
comment|/* units */
end_comment

begin_define
define|#
directive|define
name|USB_MAX_FS_ISOC_FRAMES_PER_XFER
value|(120)
end_define

begin_comment
comment|/* units */
end_comment

begin_define
define|#
directive|define
name|USB_MAX_HS_ISOC_FRAMES_PER_XFER
value|(8*120)
end_define

begin_comment
comment|/* units */
end_comment

begin_define
define|#
directive|define
name|USB_HUB_MAX_DEPTH
value|5
end_define

begin_define
define|#
directive|define
name|USB_EP0_BUFSIZE
value|1024
end_define

begin_comment
comment|/* bytes */
end_comment

begin_define
define|#
directive|define
name|USB_CS_RESET_LIMIT
value|20
end_define

begin_comment
comment|/* failures = 20 * 50 ms = 1sec */
end_comment

begin_define
define|#
directive|define
name|USB_MAX_AUTO_QUIRK
value|4
end_define

begin_comment
comment|/* maximum number of dynamic quirks */
end_comment

begin_typedef
typedef|typedef
name|uint32_t
name|usb_timeout_t
typedef|;
end_typedef

begin_comment
comment|/* milliseconds */
end_comment

begin_typedef
typedef|typedef
name|uint32_t
name|usb_frlength_t
typedef|;
end_typedef

begin_comment
comment|/* bytes */
end_comment

begin_typedef
typedef|typedef
name|uint32_t
name|usb_frcount_t
typedef|;
end_typedef

begin_comment
comment|/* units */
end_comment

begin_typedef
typedef|typedef
name|uint32_t
name|usb_size_t
typedef|;
end_typedef

begin_comment
comment|/* bytes */
end_comment

begin_typedef
typedef|typedef
name|uint32_t
name|usb_ticks_t
typedef|;
end_typedef

begin_comment
comment|/* system defined */
end_comment

begin_typedef
typedef|typedef
name|uint16_t
name|usb_power_mask_t
typedef|;
end_typedef

begin_comment
comment|/* see "USB_HW_POWER_XXX" */
end_comment

begin_typedef
typedef|typedef
name|uint16_t
name|usb_stream_t
typedef|;
end_typedef

begin_comment
comment|/* stream ID */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _USB_FREEBSD_LOADER_H_ */
end_comment

end_unit

