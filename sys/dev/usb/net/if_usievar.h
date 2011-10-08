begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $FreeBSD$ */
end_comment

begin_comment
comment|/*-  * Copyright (c) 2011 Anybots Inc  * written by Akinori Furukoshi<moonlightakkiy@yahoo.ca>  *  - ucom part is based on u3g.c  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_IF_USEVAR_H_
end_ifndef

begin_define
define|#
directive|define
name|_IF_USEVAR_H_
end_define

begin_define
define|#
directive|define
name|USIE_DCD
value|0x0001
end_define

begin_define
define|#
directive|define
name|USIE_DSR
value|0x0002
end_define

begin_define
define|#
directive|define
name|USIE_DTR
value|0x0004
end_define

begin_define
define|#
directive|define
name|USIE_RI
value|0x0008
end_define

begin_define
define|#
directive|define
name|USIE_CTS
value|0x0100
end_define

begin_define
define|#
directive|define
name|USIE_RTS
value|0x0200
end_define

begin_define
define|#
directive|define
name|USIE_HIP_FRM_CHR
value|0x7e
end_define

begin_define
define|#
directive|define
name|USIE_HIP_ESC_CHR
value|0x7d
end_define

begin_define
define|#
directive|define
name|USIE_HIP_IF
value|0
end_define

begin_define
define|#
directive|define
name|USIE_HIPCNS_MIN
value|16
end_define

begin_comment
comment|/* HIP + CnS + 2 framing char */
end_comment

begin_define
define|#
directive|define
name|USIE_HIPCNS_MAX
value|261
end_define

begin_comment
comment|/* HIP + max CnS 255 + 2 framing char */
end_comment

begin_define
define|#
directive|define
name|USIE_CNFG_INDEX
value|0
end_define

begin_define
define|#
directive|define
name|USIE_IFACE_INDEX
value|0
end_define

begin_define
define|#
directive|define
name|USIE_IFACE_MAX
value|12
end_define

begin_define
define|#
directive|define
name|USIE_BUFSIZE
value|2048
end_define

begin_define
define|#
directive|define
name|USIE_MTU_MAX
value|1500
end_define

begin_define
define|#
directive|define
name|USIE_RXSZ_MAX
value|4096
end_define

begin_comment
comment|/* USB control pipe request */
end_comment

begin_define
define|#
directive|define
name|USIE_POWER
value|0x00
end_define

begin_define
define|#
directive|define
name|USIE_FW_ATTR
value|0x06
end_define

begin_define
define|#
directive|define
name|USIE_NMEA
value|0x07
end_define

begin_define
define|#
directive|define
name|USIE_LINK_STATE
value|0x22
end_define

begin_comment
comment|/* firmware attr flags */
end_comment

begin_define
define|#
directive|define
name|USIE_PM_AUTO
value|(1<< 1)
end_define

begin_define
define|#
directive|define
name|USIE_FW_DHCP
value|(1<< 3)
end_define

begin_comment
comment|/* DHCP capable */
end_comment

begin_comment
comment|/* line state flags */
end_comment

begin_define
define|#
directive|define
name|USIE_LS_DTR
value|(1<< 0)
end_define

begin_define
define|#
directive|define
name|USIE_LS_RTS
value|(1<< 1)
end_define

begin_comment
comment|/* Host Interface Porotocol Header */
end_comment

begin_struct
struct|struct
name|usie_hip
block|{
name|uint16_t
name|len
decl_stmt|;
define|#
directive|define
name|USIE_HIP_LEN_MASK
value|0x3fff
define|#
directive|define
name|USIE_HIP_IP_LEN_MASK
value|0x07ff
name|uint8_t
name|id
decl_stmt|;
define|#
directive|define
name|USIE_HIP_PAD
value|(1<< 7)
define|#
directive|define
name|USIE_HIP_MASK
value|0x7f
define|#
directive|define
name|USIE_HIP_SYNC2M
value|0x20
comment|/* host -> modem */
define|#
directive|define
name|USIE_HIP_DOWN
value|0x26
define|#
directive|define
name|USIE_HIP_CNS2M
value|0x2b
comment|/* h -> m */
define|#
directive|define
name|USIE_HIP_CTX
value|0x3f
define|#
directive|define
name|USIE_HIP_SYNC2H
value|0x60
comment|/* h<- m */
define|#
directive|define
name|USIE_HIP_RESTR
value|0x62
define|#
directive|define
name|USIE_HIP_RCGI
value|0x64
define|#
directive|define
name|USIE_HIP_CNS2H
value|0x6b
comment|/* h<- m */
define|#
directive|define
name|USIE_HIP_UMTS
value|0x78
define|#
directive|define
name|USIE_HIP_IP
value|0x7f
name|uint8_t
name|param
decl_stmt|;
block|}
name|__packed
name|__aligned
argument_list|(
literal|4
argument_list|)
struct|;
end_struct

begin_comment
comment|/* Control and Status Header */
end_comment

begin_struct
struct|struct
name|usie_cns
block|{
name|uint16_t
name|obj
decl_stmt|;
comment|/* object type */
define|#
directive|define
name|USIE_CNS_OB_RSSI
value|0x1001
comment|/* read RSSI */
define|#
directive|define
name|USIE_CNS_OB_HW_DISABLE
value|0x1011
comment|/* disable h/w */
define|#
directive|define
name|USIE_CNS_OB_PW_SW
value|0x1071
comment|/* power on/off */
define|#
directive|define
name|USIE_CNS_OB_PROF_WRITE
value|0x7003
comment|/* write profile */
define|#
directive|define
name|USIE_CNS_OB_LINK_UPDATE
value|0x7004
comment|/* dis/connect */
define|#
directive|define
name|USIE_CNS_OB_PDP_READ
value|0x7006
comment|/* read out IP addr */
name|uint8_t
name|op
decl_stmt|;
comment|/* operation type */
define|#
directive|define
name|USIE_CNS_OP_ERR
value|(1<< 7)
comment|/* | == error */
define|#
directive|define
name|USIE_CNS_OP_REQ
value|0x01
comment|/* host -> modem */
define|#
directive|define
name|USIE_CNS_OP_RSP
value|0x02
comment|/* h<- m */
define|#
directive|define
name|USIE_CNS_OP_SET
value|0x03
comment|/* h -> m */
define|#
directive|define
name|USIE_CNS_OP_ACK
value|0x04
comment|/* h<- m */
define|#
directive|define
name|USIE_CNS_OP_NOTIF_ON
value|0x05
comment|/* h -> m */
define|#
directive|define
name|USIE_CNS_OP_RSP_ON
value|0x06
comment|/* h<- m */
define|#
directive|define
name|USIE_CNS_OP_NOTIF
value|0x07
comment|/* h<- m */
define|#
directive|define
name|USIE_CNS_OP_NOTIF_OFF
value|0x08
comment|/* h -> m */
define|#
directive|define
name|USIE_CNS_OP_RSP_OFF
value|0x09
comment|/* h<- m */
define|#
directive|define
name|USIE_CNS_OP_REQ_CHG
value|0x0a
comment|/* h -> m */
define|#
directive|define
name|USIE_CNS_OP_RSP_CHG
value|0x0b
comment|/* h<- m */
name|uint8_t
name|rsv0
decl_stmt|;
comment|/* reserved, always '0' */
name|uint32_t
name|id
decl_stmt|;
comment|/* caller ID */
comment|/*  * .id is to identify calling functions  * h/w responses with the same .id used in request. Only '0' is reserved  * for notification (asynchronous message generated by h/w without any  * request). All other values are user defineable.  */
define|#
directive|define
name|USIE_CNS_ID_NOTIF
value|0x00000000
comment|/* reserved */
define|#
directive|define
name|USIE_CNS_ID_INIT
value|0x00000001
define|#
directive|define
name|USIE_CNS_ID_STOP
value|0x00000002
define|#
directive|define
name|USIE_CNS_ID_DNS
value|0x00000003
define|#
directive|define
name|USIE_CNS_ID_RSSI
value|0x00000004
name|uint8_t
name|rsv1
decl_stmt|;
comment|/* reserved, always '0' */
name|uint8_t
name|len
decl_stmt|;
comment|/* length of param */
block|}
name|__packed
struct|;
end_struct

begin_comment
comment|/*  * CnS param attached to struct usie_cns  * usie_cns.len is total size of this param  * max 255  */
end_comment

begin_define
define|#
directive|define
name|USIE_CNS_PM_UP
value|0x01
end_define

begin_define
define|#
directive|define
name|USIE_CNS_PM_DOWN
value|0x00
end_define

begin_comment
comment|/* Link Sense Indication data structure */
end_comment

begin_struct
struct|struct
name|usie_lsi
block|{
name|uint8_t
name|proto
decl_stmt|;
define|#
directive|define
name|USIE_LSI_UMTS
value|0x01
name|uint8_t
name|pad0
decl_stmt|;
name|uint16_t
name|len
decl_stmt|;
name|uint8_t
name|area
decl_stmt|;
define|#
directive|define
name|USIE_LSI_AREA_NO
value|0x00
define|#
directive|define
name|USIE_LSI_AREA_NODATA
value|0x01
name|uint8_t
name|pad1
index|[
literal|41
index|]
decl_stmt|;
name|uint8_t
name|state
decl_stmt|;
define|#
directive|define
name|USIE_LSI_STATE_IDLE
value|0x00
name|uint8_t
name|pad2
index|[
literal|33
index|]
decl_stmt|;
name|uint8_t
name|type
decl_stmt|;
define|#
directive|define
name|USIE_LSI_IP4
value|0x00
name|uint8_t
name|pdp_addr_len
decl_stmt|;
comment|/* PDP addr */
name|uint8_t
name|pdp_addr
index|[
literal|16
index|]
decl_stmt|;
name|uint8_t
name|pad3
index|[
literal|23
index|]
decl_stmt|;
name|uint8_t
name|dns1_addr_len
decl_stmt|;
comment|/* DNS addr */
name|uint8_t
name|dns1_addr
index|[
literal|16
index|]
decl_stmt|;
name|uint8_t
name|dns2_addr_len
decl_stmt|;
name|uint8_t
name|dns2_addr
index|[
literal|16
index|]
decl_stmt|;
name|uint8_t
name|wins1_addr_len
decl_stmt|;
comment|/* Wins addr */
name|uint8_t
name|wins1_addr
index|[
literal|16
index|]
decl_stmt|;
name|uint8_t
name|wins2_addr_len
decl_stmt|;
name|uint8_t
name|wins2_addr
index|[
literal|16
index|]
decl_stmt|;
name|uint8_t
name|pad4
index|[
literal|4
index|]
decl_stmt|;
name|uint8_t
name|gw_addr_len
decl_stmt|;
comment|/* GW addr */
name|uint8_t
name|gw_addr
index|[
literal|16
index|]
decl_stmt|;
name|uint8_t
name|rsv
index|[
literal|8
index|]
decl_stmt|;
block|}
name|__packed
struct|;
end_struct

begin_struct
struct|struct
name|usie_net_info
block|{
name|uint8_t
name|addr_len
decl_stmt|;
name|uint8_t
name|pdp_addr
index|[
literal|16
index|]
decl_stmt|;
name|uint8_t
name|dns1_addr
index|[
literal|16
index|]
decl_stmt|;
name|uint8_t
name|dns2_addr
index|[
literal|16
index|]
decl_stmt|;
name|uint8_t
name|gw_addr
index|[
literal|16
index|]
decl_stmt|;
block|}
name|__packed
struct|;
end_struct

begin_comment
comment|/* Tx/Rx IP packet descriptor */
end_comment

begin_struct
struct|struct
name|usie_desc
block|{
name|struct
name|usie_hip
name|hip
decl_stmt|;
name|uint16_t
name|desc_type
decl_stmt|;
define|#
directive|define
name|USIE_TYPE_MASK
value|0x03ff
define|#
directive|define
name|USIE_IP_TX
value|0x0002
define|#
directive|define
name|USIE_IP_RX
value|0x0202
name|struct
name|ether_header
name|ethhdr
decl_stmt|;
block|}
name|__packed
struct|;
end_struct

begin_enum
enum|enum
block|{
name|USIE_UC_STATUS
block|,
name|USIE_UC_RX
block|,
name|USIE_UC_TX
block|,
name|USIE_UC_N_XFER
block|}
enum|;
end_enum

begin_enum
enum|enum
block|{
name|USIE_IF_STATUS
block|,
name|USIE_IF_RX
block|,
name|USIE_IF_TX
block|,
name|USIE_IF_N_XFER
block|}
enum|;
end_enum

begin_struct
struct|struct
name|usie_softc
block|{
name|struct
name|ucom_super_softc
name|sc_super_ucom
decl_stmt|;
define|#
directive|define
name|USIE_UCOM_MAX
value|6
name|struct
name|ucom_softc
name|sc_ucom
index|[
name|USIE_UCOM_MAX
index|]
decl_stmt|;
name|uint8_t
name|sc_uc_ifnum
index|[
name|USIE_UCOM_MAX
index|]
decl_stmt|;
name|struct
name|mtx
name|sc_mtx
decl_stmt|;
name|struct
name|task
name|sc_if_status_task
decl_stmt|;
name|struct
name|task
name|sc_if_sync_task
decl_stmt|;
name|struct
name|usb_callout
name|sc_if_sync_ch
decl_stmt|;
name|struct
name|usie_net_info
name|sc_net
decl_stmt|;
name|struct
name|usie_desc
name|sc_txd
decl_stmt|;
name|struct
name|usb_xfer
modifier|*
name|sc_uc_xfer
index|[
name|USIE_UCOM_MAX
index|]
index|[
name|USIE_UC_N_XFER
index|]
decl_stmt|;
name|struct
name|usb_xfer
modifier|*
name|sc_if_xfer
index|[
name|USIE_IF_N_XFER
index|]
decl_stmt|;
name|struct
name|ifnet
modifier|*
name|sc_ifp
decl_stmt|;
name|struct
name|usb_device
modifier|*
name|sc_udev
decl_stmt|;
name|device_t
name|sc_dev
decl_stmt|;
name|struct
name|mbuf
modifier|*
name|sc_rxm
decl_stmt|;
name|uint16_t
name|sc_if_ifnum
decl_stmt|;
name|int16_t
name|sc_rssi
decl_stmt|;
name|uint8_t
name|sc_msr
decl_stmt|;
name|uint8_t
name|sc_lsr
decl_stmt|;
name|uint8_t
name|sc_nucom
decl_stmt|;
name|uint8_t
name|sc_resp_temp
index|[
name|USIE_BUFSIZE
index|]
name|__aligned
argument_list|(
literal|4
argument_list|)
decl_stmt|;
name|uint8_t
name|sc_status_temp
index|[
name|USIE_BUFSIZE
index|]
name|__aligned
argument_list|(
literal|4
argument_list|)
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* Some code assumptions */
end_comment

begin_decl_stmt
specifier|extern
name|uint8_t
name|usie_assert
index|[
operator|(
operator|(
sizeof|sizeof
argument_list|(
expr|struct
name|usie_hip
argument_list|)
operator|+
sizeof|sizeof
argument_list|(
expr|struct
name|usie_lsi
argument_list|)
operator|+
literal|1
operator|)
operator|<=
name|USIE_BUFSIZE
operator|)
condition|?
literal|1
else|:
operator|-
literal|1
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|uint8_t
name|ucdc_assert
index|[
operator|(
sizeof|sizeof
argument_list|(
expr|struct
name|usb_cdc_notification
argument_list|)
operator|>=
literal|16
operator|)
condition|?
literal|1
else|:
operator|-
literal|1
index|]
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _IF_USEVAR_H_ */
end_comment

end_unit

