begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$NetBSD: usbcdc.h,v 1.9 2004/10/23 13:24:24 augustss Exp $	*/
end_comment

begin_comment
comment|/*	$FreeBSD$	*/
end_comment

begin_comment
comment|/*-  * Copyright (c) 1998 The NetBSD Foundation, Inc.  * All rights reserved.  *  * This code is derived from software contributed to The NetBSD Foundation  * by Lennart Augustsson (lennart@augustsson.net) at  * Carlstedt Research& Technology.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *        This product includes software developed by the NetBSD  *        Foundation, Inc. and its contributors.  * 4. Neither the name of The NetBSD Foundation nor the names of its  *    contributors may be used to endorse or promote products derived  *    from this software without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE NETBSD FOUNDATION, INC. AND CONTRIBUTORS  * ``AS IS'' AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED  * TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR  * PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL THE FOUNDATION OR CONTRIBUTORS  * BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR  * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF  * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS  * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN  * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)  * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE  * POSSIBILITY OF SUCH DAMAGE.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_USB_CDC_H_
end_ifndef

begin_define
define|#
directive|define
name|_USB_CDC_H_
end_define

begin_define
define|#
directive|define
name|UDESCSUB_CDC_HEADER
value|0
end_define

begin_define
define|#
directive|define
name|UDESCSUB_CDC_CM
value|1
end_define

begin_comment
comment|/* Call Management */
end_comment

begin_define
define|#
directive|define
name|UDESCSUB_CDC_ACM
value|2
end_define

begin_comment
comment|/* Abstract Control Model */
end_comment

begin_define
define|#
directive|define
name|UDESCSUB_CDC_DLM
value|3
end_define

begin_comment
comment|/* Direct Line Management */
end_comment

begin_define
define|#
directive|define
name|UDESCSUB_CDC_TRF
value|4
end_define

begin_comment
comment|/* Telephone Ringer */
end_comment

begin_define
define|#
directive|define
name|UDESCSUB_CDC_TCLSR
value|5
end_define

begin_comment
comment|/* Telephone Call */
end_comment

begin_define
define|#
directive|define
name|UDESCSUB_CDC_UNION
value|6
end_define

begin_define
define|#
directive|define
name|UDESCSUB_CDC_CS
value|7
end_define

begin_comment
comment|/* Country Selection */
end_comment

begin_define
define|#
directive|define
name|UDESCSUB_CDC_TOM
value|8
end_define

begin_comment
comment|/* Telephone Operational Modes */
end_comment

begin_define
define|#
directive|define
name|UDESCSUB_CDC_USBT
value|9
end_define

begin_comment
comment|/* USB Terminal */
end_comment

begin_define
define|#
directive|define
name|UDESCSUB_CDC_NCT
value|10
end_define

begin_define
define|#
directive|define
name|UDESCSUB_CDC_PUF
value|11
end_define

begin_define
define|#
directive|define
name|UDESCSUB_CDC_EUF
value|12
end_define

begin_define
define|#
directive|define
name|UDESCSUB_CDC_MCMF
value|13
end_define

begin_define
define|#
directive|define
name|UDESCSUB_CDC_CCMF
value|14
end_define

begin_define
define|#
directive|define
name|UDESCSUB_CDC_ENF
value|15
end_define

begin_define
define|#
directive|define
name|UDESCSUB_CDC_ANF
value|16
end_define

begin_struct
struct|struct
name|usb_cdc_header_descriptor
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
name|__packed
struct|;
end_struct

begin_struct
struct|struct
name|usb_cdc_cm_descriptor
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
name|USB_CDC_CM_OVER_DATA
value|0x02
name|uByte
name|bDataInterface
decl_stmt|;
block|}
name|__packed
struct|;
end_struct

begin_struct
struct|struct
name|usb_cdc_acm_descriptor
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
name|__packed
struct|;
end_struct

begin_struct
struct|struct
name|usb_cdc_union_descriptor
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
name|__packed
struct|;
end_struct

begin_struct
struct|struct
name|usb_cdc_ethernet_descriptor
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
name|iMacAddress
decl_stmt|;
name|uDWord
name|bmEthernetStatistics
decl_stmt|;
name|uWord
name|wMaxSegmentSize
decl_stmt|;
name|uWord
name|wNumberMCFilters
decl_stmt|;
name|uByte
name|bNumberPowerFilters
decl_stmt|;
block|}
name|__packed
struct|;
end_struct

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

begin_define
define|#
directive|define
name|UCDC_SET_CONTROL_LINE_STATE
value|0x22
end_define

begin_define
define|#
directive|define
name|UCDC_LINE_DTR
value|0x0001
end_define

begin_define
define|#
directive|define
name|UCDC_LINE_RTS
value|0x0002
end_define

begin_define
define|#
directive|define
name|UCDC_SEND_BREAK
value|0x23
end_define

begin_define
define|#
directive|define
name|UCDC_BREAK_ON
value|0xffff
end_define

begin_define
define|#
directive|define
name|UCDC_BREAK_OFF
value|0x0000
end_define

begin_struct
struct|struct
name|usb_cdc_abstract_state
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
name|__packed
struct|;
end_struct

begin_define
define|#
directive|define
name|UCDC_ABSTRACT_STATE_LENGTH
value|2
end_define

begin_struct
struct|struct
name|usb_cdc_line_state
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
name|__packed
struct|;
end_struct

begin_define
define|#
directive|define
name|UCDC_LINE_STATE_LENGTH
value|7
end_define

begin_struct
struct|struct
name|usb_cdc_notification
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
name|__packed
struct|;
end_struct

begin_define
define|#
directive|define
name|UCDC_NOTIFICATION_LENGTH
value|8
end_define

begin_comment
comment|/*  * Bits set in the SERIAL STATE notifcation (first byte of data)  */
end_comment

begin_define
define|#
directive|define
name|UCDC_N_SERIAL_OVERRUN
value|0x40
end_define

begin_define
define|#
directive|define
name|UCDC_N_SERIAL_PARITY
value|0x20
end_define

begin_define
define|#
directive|define
name|UCDC_N_SERIAL_FRAMING
value|0x10
end_define

begin_define
define|#
directive|define
name|UCDC_N_SERIAL_RI
value|0x08
end_define

begin_define
define|#
directive|define
name|UCDC_N_SERIAL_BREAK
value|0x04
end_define

begin_define
define|#
directive|define
name|UCDC_N_SERIAL_DSR
value|0x02
end_define

begin_define
define|#
directive|define
name|UCDC_N_SERIAL_DCD
value|0x01
end_define

begin_comment
comment|/* Serial state bit masks */
end_comment

begin_define
define|#
directive|define
name|UCDC_MDM_RXCARRIER
value|0x01
end_define

begin_define
define|#
directive|define
name|UCDC_MDM_TXCARRIER
value|0x02
end_define

begin_define
define|#
directive|define
name|UCDC_MDM_BREAK
value|0x04
end_define

begin_define
define|#
directive|define
name|UCDC_MDM_RING
value|0x08
end_define

begin_define
define|#
directive|define
name|UCDC_MDM_FRAMING_ERR
value|0x10
end_define

begin_define
define|#
directive|define
name|UCDC_MDM_PARITY_ERR
value|0x20
end_define

begin_define
define|#
directive|define
name|UCDC_MDM_OVERRUN_ERR
value|0x40
end_define

begin_comment
comment|/*  * Network Control Model, NCM16 + NCM32, protocol definitions  */
end_comment

begin_struct
struct|struct
name|usb_ncm16_hdr
block|{
name|uDWord
name|dwSignature
decl_stmt|;
name|uWord
name|wHeaderLength
decl_stmt|;
name|uWord
name|wSequence
decl_stmt|;
name|uWord
name|wBlockLength
decl_stmt|;
name|uWord
name|wDptIndex
decl_stmt|;
block|}
name|__packed
struct|;
end_struct

begin_struct
struct|struct
name|usb_ncm16_dp
block|{
name|uWord
name|wFrameIndex
decl_stmt|;
name|uWord
name|wFrameLength
decl_stmt|;
block|}
name|__packed
struct|;
end_struct

begin_struct
struct|struct
name|usb_ncm16_dpt
block|{
name|uDWord
name|dwSignature
decl_stmt|;
name|uWord
name|wLength
decl_stmt|;
name|uWord
name|wNextNdpIndex
decl_stmt|;
name|struct
name|usb_ncm16_dp
name|dp
index|[
literal|0
index|]
decl_stmt|;
block|}
name|__packed
struct|;
end_struct

begin_struct
struct|struct
name|usb_ncm32_hdr
block|{
name|uDWord
name|dwSignature
decl_stmt|;
name|uWord
name|wHeaderLength
decl_stmt|;
name|uWord
name|wSequence
decl_stmt|;
name|uDWord
name|dwBlockLength
decl_stmt|;
name|uDWord
name|dwDptIndex
decl_stmt|;
block|}
name|__packed
struct|;
end_struct

begin_struct
struct|struct
name|usb_ncm32_dp
block|{
name|uDWord
name|dwFrameIndex
decl_stmt|;
name|uDWord
name|dwFrameLength
decl_stmt|;
block|}
name|__packed
struct|;
end_struct

begin_struct
struct|struct
name|usb_ncm32_dpt
block|{
name|uDWord
name|dwSignature
decl_stmt|;
name|uWord
name|wLength
decl_stmt|;
name|uWord
name|wReserved6
decl_stmt|;
name|uDWord
name|dwNextNdpIndex
decl_stmt|;
name|uDWord
name|dwReserved12
decl_stmt|;
name|struct
name|usb_ncm32_dp
name|dp
index|[
literal|0
index|]
decl_stmt|;
block|}
name|__packed
struct|;
end_struct

begin_comment
comment|/* Communications interface class specific descriptors */
end_comment

begin_define
define|#
directive|define
name|UCDC_NCM_FUNC_DESC_SUBTYPE
value|0x1A
end_define

begin_struct
struct|struct
name|usb_ncm_func_descriptor
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
name|bcdNcmVersion
index|[
literal|2
index|]
decl_stmt|;
name|uByte
name|bmNetworkCapabilities
decl_stmt|;
define|#
directive|define
name|UCDC_NCM_CAP_FILTER
value|0x01
define|#
directive|define
name|UCDC_NCM_CAP_MAC_ADDR
value|0x02
define|#
directive|define
name|UCDC_NCM_CAP_ENCAP
value|0x04
define|#
directive|define
name|UCDC_NCM_CAP_MAX_DATA
value|0x08
define|#
directive|define
name|UCDC_NCM_CAP_CRCMODE
value|0x10
block|}
name|__packed
struct|;
end_struct

begin_comment
comment|/* Communications interface specific class request codes */
end_comment

begin_define
define|#
directive|define
name|UCDC_NCM_SET_ETHERNET_MULTICAST_FILTERS
value|0x40
end_define

begin_define
define|#
directive|define
name|UCDC_NCM_SET_ETHERNET_POWER_MGMT_PATTERN_FILTER
value|0x41
end_define

begin_define
define|#
directive|define
name|UCDC_NCM_GET_ETHERNET_POWER_MGMT_PATTERN_FILTER
value|0x42
end_define

begin_define
define|#
directive|define
name|UCDC_NCM_SET_ETHERNET_PACKET_FILTER
value|0x43
end_define

begin_define
define|#
directive|define
name|UCDC_NCM_GET_ETHERNET_STATISTIC
value|0x44
end_define

begin_define
define|#
directive|define
name|UCDC_NCM_GET_NTB_PARAMETERS
value|0x80
end_define

begin_define
define|#
directive|define
name|UCDC_NCM_GET_NET_ADDRESS
value|0x81
end_define

begin_define
define|#
directive|define
name|UCDC_NCM_SET_NET_ADDRESS
value|0x82
end_define

begin_define
define|#
directive|define
name|UCDC_NCM_GET_NTB_FORMAT
value|0x83
end_define

begin_define
define|#
directive|define
name|UCDC_NCM_SET_NTB_FORMAT
value|0x84
end_define

begin_define
define|#
directive|define
name|UCDC_NCM_GET_NTB_INPUT_SIZE
value|0x85
end_define

begin_define
define|#
directive|define
name|UCDC_NCM_SET_NTB_INPUT_SIZE
value|0x86
end_define

begin_define
define|#
directive|define
name|UCDC_NCM_GET_MAX_DATAGRAM_SIZE
value|0x87
end_define

begin_define
define|#
directive|define
name|UCDC_NCM_SET_MAX_DATAGRAM_SIZE
value|0x88
end_define

begin_define
define|#
directive|define
name|UCDC_NCM_GET_CRC_MODE
value|0x89
end_define

begin_define
define|#
directive|define
name|UCDC_NCM_SET_CRC_MODE
value|0x8A
end_define

begin_struct
struct|struct
name|usb_ncm_parameters
block|{
name|uWord
name|wLength
decl_stmt|;
name|uWord
name|bmNtbFormatsSupported
decl_stmt|;
define|#
directive|define
name|UCDC_NCM_FORMAT_NTB16
value|0x0001
define|#
directive|define
name|UCDC_NCM_FORMAT_NTB32
value|0x0002
name|uDWord
name|dwNtbInMaxSize
decl_stmt|;
name|uWord
name|wNdpInDivisor
decl_stmt|;
name|uWord
name|wNdpInPayloadRemainder
decl_stmt|;
name|uWord
name|wNdpInAlignment
decl_stmt|;
name|uWord
name|wReserved14
decl_stmt|;
name|uDWord
name|dwNtbOutMaxSize
decl_stmt|;
name|uWord
name|wNdpOutDivisor
decl_stmt|;
name|uWord
name|wNdpOutPayloadRemainder
decl_stmt|;
name|uWord
name|wNdpOutAlignment
decl_stmt|;
name|uWord
name|wReserved26
decl_stmt|;
block|}
name|__packed
struct|;
end_struct

begin_comment
comment|/* Communications interface specific class notification codes */
end_comment

begin_define
define|#
directive|define
name|UCDC_NCM_NOTIF_NETWORK_CONNECTION
value|0x00
end_define

begin_define
define|#
directive|define
name|UCDC_NCM_NOTIF_RESPONSE_AVAILABLE
value|0x01
end_define

begin_define
define|#
directive|define
name|UCDC_NCM_NOTIF_CONNECTION_SPEED_CHANGE
value|0x2A
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _USB_CDC_H_ */
end_comment

end_unit

