begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$NetBSD: usbcdc.h,v 1.3 1999/01/03 01:09:18 augustss Exp $	*/
end_comment

begin_comment
comment|/*	$FreeBSD$	*/
end_comment

begin_comment
comment|/*  * Copyright (c) 1998 The NetBSD Foundation, Inc.  * All rights reserved.  *  * This code is derived from software contributed to The NetBSD Foundation  * by Lennart Augustsson (augustss@carlstedt.se) at  * Carlstedt Research& Technology.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *        This product includes software developed by the NetBSD  *        Foundation, Inc. and its contributors.  * 4. Neither the name of The NetBSD Foundation nor the names of its  *    contributors may be used to endorse or promote products derived  *    from this software without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE NETBSD FOUNDATION, INC. AND CONTRIBUTORS  * ``AS IS'' AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED  * TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR  * PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL THE FOUNDATION OR CONTRIBUTORS  * BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR  * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF  * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS  * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN  * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)  * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE  * POSSIBILITY OF SUCH DAMAGE.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_USBCDC_H_
end_ifndef

begin_define
define|#
directive|define
name|_USBCDC_H_
end_define

begin_define
define|#
directive|define
name|UDESCSUB_CDC_HEADER
value|0x00
end_define

begin_comment
comment|/* Header */
end_comment

begin_define
define|#
directive|define
name|UDESCSUB_CDC_CM
value|0x01
end_define

begin_comment
comment|/* Call Management */
end_comment

begin_define
define|#
directive|define
name|UDESCSUB_CDC_ACM
value|0x02
end_define

begin_comment
comment|/* Abstract Control Model */
end_comment

begin_define
define|#
directive|define
name|UDESCSUB_CDC_DLM
value|0x03
end_define

begin_comment
comment|/* Direct Line Management */
end_comment

begin_define
define|#
directive|define
name|UDESCSUB_CDC_TRF
value|0x04
end_define

begin_comment
comment|/* Telephone Ringer */
end_comment

begin_define
define|#
directive|define
name|UDESCSUB_CDC_TCLSR
value|0x05
end_define

begin_comment
comment|/* Tel. Call and Line State Rep. Cap. */
end_comment

begin_define
define|#
directive|define
name|UDESCSUB_CDC_UNION
value|0x06
end_define

begin_comment
comment|/* Union */
end_comment

begin_define
define|#
directive|define
name|UDESCSUB_CDC_CS
value|0x07
end_define

begin_comment
comment|/* Country Selection */
end_comment

begin_define
define|#
directive|define
name|UDESCSUB_CDC_TOM
value|0x08
end_define

begin_comment
comment|/* Telephone Operational Modes */
end_comment

begin_define
define|#
directive|define
name|UDESCSUB_CDC_USBT
value|0x09
end_define

begin_comment
comment|/* USB Terminal */
end_comment

begin_define
define|#
directive|define
name|UDESCSUB_CDC_NCT
value|0x0a
end_define

begin_comment
comment|/* Network Channel Terminal */
end_comment

begin_define
define|#
directive|define
name|UDESCSUB_CDC_PU
value|0x0b
end_define

begin_comment
comment|/* Protocol Unit */
end_comment

begin_define
define|#
directive|define
name|UDESCSUB_CDC_EU
value|0x0c
end_define

begin_comment
comment|/* Extention Unit */
end_comment

begin_define
define|#
directive|define
name|UDESCSUB_CDC_MCM
value|0x0d
end_define

begin_comment
comment|/* Multi-Channel Management */
end_comment

begin_define
define|#
directive|define
name|UDESCSUB_CDC_CCM
value|0x0e
end_define

begin_comment
comment|/* CAPI Control Management */
end_comment

begin_define
define|#
directive|define
name|UDESCSUB_CDC_EN
value|0x0f
end_define

begin_comment
comment|/* Ethernet Networking */
end_comment

begin_define
define|#
directive|define
name|UDESCSUB_CDC_AN
value|0x10
end_define

begin_comment
comment|/* ATM Networking */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|uByte
name|bLength
decl_stmt|;
name|uByte
name|bDescriptorType
decl_stmt|;
name|uByte
name|bDescriptorSubtype
decl_stmt|;
block|}
name|usb_cdc_generic_descriptor_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|uByte
name|bLength
decl_stmt|;
name|uByte
name|bDescriptorType
decl_stmt|;
name|uByte
name|bDescriptorSubtype
decl_stmt|;
name|uWord
name|bcdCDC
decl_stmt|;
block|}
name|usb_cdc_header_descriptor_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|uByte
name|bLength
decl_stmt|;
name|uByte
name|bDescriptorType
decl_stmt|;
name|uByte
name|bDescriptorSubtype
decl_stmt|;
name|uByte
name|bmCapabilities
decl_stmt|;
define|#
directive|define
name|USB_CDC_CM_DOES_CM
value|0x01
define|#
directive|define
name|USB_CDC_CM_CM_OVER_DATA
value|0x02
name|uByte
name|bDataInterface
decl_stmt|;
block|}
name|usb_cdc_cm_descriptor_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|uByte
name|bLength
decl_stmt|;
name|uByte
name|bDescriptorType
decl_stmt|;
name|uByte
name|bDescriptorSubtype
decl_stmt|;
name|uByte
name|bmCapabilities
decl_stmt|;
define|#
directive|define
name|USB_CDC_ACM_HAS_FEATURE
value|0x01
define|#
directive|define
name|USB_CDC_ACM_HAS_LINE
value|0x02
define|#
directive|define
name|USB_CDC_ACM_HAS_BREAK
value|0x04
define|#
directive|define
name|USB_CDC_ACM_HAS_NETWORK_CONN
value|0x08
block|}
name|usb_cdc_acm_descriptor_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|uByte
name|bLength
decl_stmt|;
name|uByte
name|bDescriptorType
decl_stmt|;
name|uByte
name|bDescriptorSubtype
decl_stmt|;
name|uByte
name|bMasterInterface
decl_stmt|;
name|uByte
name|bSlaveInterface
index|[
literal|1
index|]
decl_stmt|;
block|}
name|usb_cdc_union_descriptor_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|UCDC_SEND_ENCAPSULATED_COMMAND
value|0x00
end_define

begin_define
define|#
directive|define
name|UCDC_GET_ENCAPSULATED_RESPONSE
value|0x01
end_define

begin_define
define|#
directive|define
name|UCDC_SET_COMM_FEATURE
value|0x02
end_define

begin_define
define|#
directive|define
name|UCDC_GET_COMM_FEATURE
value|0x03
end_define

begin_define
define|#
directive|define
name|UCDC_ABSTRACT_STATE
value|0x01
end_define

begin_define
define|#
directive|define
name|UCDC_COUNTRY_SETTING
value|0x02
end_define

begin_define
define|#
directive|define
name|UCDC_CLEAR_COMM_FEATURE
value|0x04
end_define

begin_define
define|#
directive|define
name|UCDC_SET_LINE_CODING
value|0x20
end_define

begin_define
define|#
directive|define
name|UCDC_GET_LINE_CODING
value|0x21
end_define

begin_typedef
typedef|typedef
struct|struct
block|{
name|uWord
name|wState
decl_stmt|;
define|#
directive|define
name|UCDC_IDLE_SETTING
value|0x0001
define|#
directive|define
name|UCDC_DATA_MULTIPLEXED
value|0x0002
block|}
name|usb_cdc_abstract_state_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|uDWord
name|dwDTERate
decl_stmt|;
name|uByte
name|bCharFormat
decl_stmt|;
define|#
directive|define
name|UCDC_STOP_BIT_1
value|0
define|#
directive|define
name|UCDC_STOP_BIT_1_5
value|1
define|#
directive|define
name|UCDC_STOP_BIT_2
value|2
name|uByte
name|bParityType
decl_stmt|;
define|#
directive|define
name|UCDC_PARITY_NONE
value|0
define|#
directive|define
name|UCDC_PARITY_ODD
value|1
define|#
directive|define
name|UCDC_PARITY_EVEN
value|2
define|#
directive|define
name|UCDC_PARITY_MARK
value|3
define|#
directive|define
name|UCDC_PARITY_SPACE
value|4
name|uByte
name|bDataBits
decl_stmt|;
block|}
name|usb_cdc_line_state_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|uByte
name|bmRequestType
decl_stmt|;
define|#
directive|define
name|UCDC_NOTIFICATION
value|0xa1
name|uByte
name|bNotification
decl_stmt|;
define|#
directive|define
name|UCDC_N_NETWORK_CONNECTION
value|0x00
define|#
directive|define
name|UCDC_N_RESPONSE_AVAILABLE
value|0x01
define|#
directive|define
name|UCDC_N_AUX_JACK_HOOK_STATE
value|0x08
define|#
directive|define
name|UCDC_N_RING_DETECT
value|0x09
define|#
directive|define
name|UCDC_N_SERIAL_STATE
value|0x20
define|#
directive|define
name|UCDC_N_CALL_STATE_CHANGED
value|0x28
define|#
directive|define
name|UCDC_N_LINE_STATE_CHANGED
value|0x29
define|#
directive|define
name|UCDC_N_CONNECTION_SPEED_CHANGE
value|0x2a
name|uWord
name|wValue
decl_stmt|;
name|uWord
name|wIndex
decl_stmt|;
name|uWord
name|wLength
decl_stmt|;
name|uByte
name|data
index|[
literal|16
index|]
decl_stmt|;
block|}
name|usb_cdc_notification_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|UCDC_NOTIFICATION_LENGTH
value|8
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _USBCDC_H_ */
end_comment

end_unit

