begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $FreeBSD$ */
end_comment

begin_comment
comment|/*-  * Copyright (c) 2008 Hans Petter Selasky. All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_USB_QUIRK_H_
end_ifndef

begin_define
define|#
directive|define
name|_USB_QUIRK_H_
end_define

begin_comment
comment|/* NOTE: UQ_NONE is not a valid quirk */
end_comment

begin_enum
enum|enum
block|{
comment|/* keep in sync with usb_quirk_str table */
name|UQ_NONE
block|,
name|UQ_MATCH_VENDOR_ONLY
block|,
comment|/* Various quirks */
name|UQ_AUDIO_SWAP_LR
block|,
comment|/* left and right sound channels are swapped */
name|UQ_AU_INP_ASYNC
block|,
comment|/* input is async despite claim of adaptive */
name|UQ_AU_NO_FRAC
block|,
comment|/* don't adjust for fractional samples */
name|UQ_AU_NO_XU
block|,
comment|/* audio device has broken extension unit */
name|UQ_BAD_ADC
block|,
comment|/* bad audio spec version number */
name|UQ_BAD_AUDIO
block|,
comment|/* device claims audio class, but isn't */
name|UQ_BROKEN_BIDIR
block|,
comment|/* printer has broken bidir mode */
name|UQ_BUS_POWERED
block|,
comment|/* device is bus powered, despite claim */
name|UQ_HID_IGNORE
block|,
comment|/* device should be ignored by hid class */
name|UQ_KBD_IGNORE
block|,
comment|/* device should be ignored by kbd class */
name|UQ_MS_BAD_CLASS
block|,
comment|/* doesn't identify properly */
name|UQ_MS_LEADING_BYTE
block|,
comment|/* mouse sends an unknown leading byte */
name|UQ_MS_REVZ
block|,
comment|/* mouse has Z-axis reversed */
name|UQ_NO_STRINGS
block|,
comment|/* string descriptors are broken */
name|UQ_OPEN_CLEARSTALL
block|,
comment|/* device needs clear endpoint stall */
name|UQ_POWER_CLAIM
block|,
comment|/* hub lies about power status */
name|UQ_SPUR_BUT_UP
block|,
comment|/* spurious mouse button up events */
name|UQ_SWAP_UNICODE
block|,
comment|/* has some Unicode strings swapped */
name|UQ_CFG_INDEX_1
block|,
comment|/* select configuration index 1 by default */
name|UQ_CFG_INDEX_2
block|,
comment|/* select configuration index 2 by default */
name|UQ_CFG_INDEX_3
block|,
comment|/* select configuration index 3 by default */
name|UQ_CFG_INDEX_4
block|,
comment|/* select configuration index 4 by default */
name|UQ_CFG_INDEX_0
block|,
comment|/* select configuration index 0 by default */
name|UQ_ASSUME_CM_OVER_DATA
block|,
comment|/* modem device breaks on cm over data */
comment|/* USB Mass Storage Quirks. See "storage/umass.c" for a detailed description. */
name|UQ_MSC_NO_TEST_UNIT_READY
block|,
name|UQ_MSC_NO_RS_CLEAR_UA
block|,
name|UQ_MSC_NO_START_STOP
block|,
name|UQ_MSC_NO_GETMAXLUN
block|,
name|UQ_MSC_NO_INQUIRY
block|,
name|UQ_MSC_NO_INQUIRY_EVPD
block|,
name|UQ_MSC_NO_SYNC_CACHE
block|,
name|UQ_MSC_SHUTTLE_INIT
block|,
name|UQ_MSC_ALT_IFACE_1
block|,
name|UQ_MSC_FLOPPY_SPEED
block|,
name|UQ_MSC_IGNORE_RESIDUE
block|,
name|UQ_MSC_WRONG_CSWSIG
block|,
name|UQ_MSC_RBC_PAD_TO_12
block|,
name|UQ_MSC_READ_CAP_OFFBY1
block|,
name|UQ_MSC_FORCE_SHORT_INQ
block|,
name|UQ_MSC_FORCE_WIRE_BBB
block|,
name|UQ_MSC_FORCE_WIRE_CBI
block|,
name|UQ_MSC_FORCE_WIRE_CBI_I
block|,
name|UQ_MSC_FORCE_PROTO_SCSI
block|,
name|UQ_MSC_FORCE_PROTO_ATAPI
block|,
name|UQ_MSC_FORCE_PROTO_UFI
block|,
name|UQ_MSC_FORCE_PROTO_RBC
block|,
name|USB_QUIRK_MAX
block|}
enum|;
end_enum

begin_function_decl
name|uint8_t
name|usb_test_quirk
parameter_list|(
specifier|const
name|struct
name|usb_attach_arg
modifier|*
name|uaa
parameter_list|,
name|uint16_t
name|quirk
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _USB_QUIRK_H_ */
end_comment

end_unit

