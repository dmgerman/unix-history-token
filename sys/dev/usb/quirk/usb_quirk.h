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

begin_enum
enum|enum
block|{
comment|/* 	 * Keep in sync with usb_quirk_str in usb_quirk.c, and with 	 * share/man/man4/usb_quirk.4 	 */
name|UQ_NONE
block|,
comment|/* not a valid quirk */
name|UQ_MATCH_VENDOR_ONLY
block|,
comment|/* match quirk on vendor only */
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
name|UQ_KBD_BOOTPROTO
block|,
comment|/* device should set the boot protocol */
name|UQ_UMS_IGNORE
block|,
comment|/* device should be ignored by ums class */
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
comment|/* assume cm over data feature */
comment|/* 	 * USB Mass Storage Quirks. See "storage/umass.c" for a 	 * detailed description. 	 */
name|UQ_MSC_NO_TEST_UNIT_READY
block|,
comment|/* send start/stop instead of TUR */
name|UQ_MSC_NO_RS_CLEAR_UA
block|,
comment|/* does not reset Unit Att. */
name|UQ_MSC_NO_START_STOP
block|,
comment|/* does not support start/stop */
name|UQ_MSC_NO_GETMAXLUN
block|,
comment|/* does not support get max LUN */
name|UQ_MSC_NO_INQUIRY
block|,
comment|/* fake generic inq response */
name|UQ_MSC_NO_INQUIRY_EVPD
block|,
comment|/* does not support inq EVPD */
name|UQ_MSC_NO_PREVENT_ALLOW
block|,
comment|/* does not support medium removal */
name|UQ_MSC_NO_SYNC_CACHE
block|,
comment|/* does not support sync cache */
name|UQ_MSC_SHUTTLE_INIT
block|,
comment|/* requires Shuttle init sequence */
name|UQ_MSC_ALT_IFACE_1
block|,
comment|/* switch to alternate interface 1 */
name|UQ_MSC_FLOPPY_SPEED
block|,
comment|/* does floppy speeds (20kb/s) */
name|UQ_MSC_IGNORE_RESIDUE
block|,
comment|/* gets residue wrong */
name|UQ_MSC_WRONG_CSWSIG
block|,
comment|/* uses wrong CSW signature */
name|UQ_MSC_RBC_PAD_TO_12
block|,
comment|/* pad RBC requests to 12 bytes */
name|UQ_MSC_READ_CAP_OFFBY1
block|,
comment|/* reports sector count, not max sec. */
name|UQ_MSC_FORCE_SHORT_INQ
block|,
comment|/* does not support full inq. */
name|UQ_MSC_FORCE_WIRE_BBB
block|,
comment|/* force BBB wire protocol */
name|UQ_MSC_FORCE_WIRE_CBI
block|,
comment|/* force CBI wire protocol */
name|UQ_MSC_FORCE_WIRE_CBI_I
block|,
comment|/* force CBI with int. wire protocol */
name|UQ_MSC_FORCE_PROTO_SCSI
block|,
comment|/* force SCSI command protocol */
name|UQ_MSC_FORCE_PROTO_ATAPI
block|,
comment|/* force ATAPI command protocol */
name|UQ_MSC_FORCE_PROTO_UFI
block|,
comment|/* force UFI command protocol */
name|UQ_MSC_FORCE_PROTO_RBC
block|,
comment|/* force RBC command protocol */
comment|/* Ejection of mass storage (driver disk) */
name|UQ_MSC_EJECT_HUAWEI
block|,
comment|/* ejects after Huawei USB command */
name|UQ_MSC_EJECT_SIERRA
block|,
comment|/* ejects after Sierra USB command */
name|UQ_MSC_EJECT_SCSIEJECT
block|,
comment|/* ejects after SCSI eject command */
name|UQ_MSC_EJECT_REZERO
block|,
comment|/* ejects after SCSI rezero command */
name|UQ_MSC_EJECT_ZTESTOR
block|,
comment|/* ejects after ZTE SCSI command */
name|UQ_MSC_EJECT_CMOTECH
block|,
comment|/* ejects after C-motech SCSI cmd */
name|UQ_MSC_EJECT_WAIT
block|,
comment|/* wait for the device to eject */
name|UQ_MSC_EJECT_SAEL_M460
block|,
comment|/* ejects after Sael USB commands */
name|UQ_MSC_EJECT_HUAWEISCSI
block|,
comment|/* ejects after Huawei SCSI command */
name|UQ_MSC_EJECT_HUAWEISCSI2
block|,
comment|/* ejects after Huawei SCSI 2 command */
name|UQ_MSC_EJECT_TCT
block|,
comment|/* ejects after TCT SCSI command */
name|UQ_BAD_MIDI
block|,
comment|/* device claims MIDI class, but isn't */
name|UQ_AU_VENDOR_CLASS
block|,
comment|/* audio device uses vendor and not audio class */
name|UQ_SINGLE_CMD_MIDI
block|,
comment|/* at most one command per USB packet */
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

