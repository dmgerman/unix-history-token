begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2001 Cubical Solutions Ltd. All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * capi/capi_msgs.h	The CAPI i4b message and handler declarations.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_I4B_CAPI_MSGS_H_
end_ifndef

begin_define
define|#
directive|define
name|_I4B_CAPI_MSGS_H_
end_define

begin_comment
comment|/* CAPI commands */
end_comment

begin_define
define|#
directive|define
name|CAPI_ALERT
value|0x01
end_define

begin_define
define|#
directive|define
name|CAPI_CONNECT
value|0x02
end_define

begin_define
define|#
directive|define
name|CAPI_CONNECT_ACTIVE
value|0x03
end_define

begin_define
define|#
directive|define
name|CAPI_CONNECT_B3
value|0x82
end_define

begin_define
define|#
directive|define
name|CAPI_CONNECT_B3_ACTIVE
value|0x83
end_define

begin_define
define|#
directive|define
name|CAPI_CONNECT_B3_T90_ACTIVE
value|0x88
end_define

begin_define
define|#
directive|define
name|CAPI_DATA_B3
value|0x86
end_define

begin_define
define|#
directive|define
name|CAPI_DISCONNECT_B3
value|0x84
end_define

begin_define
define|#
directive|define
name|CAPI_DISCONNECT
value|0x04
end_define

begin_define
define|#
directive|define
name|CAPI_FACILITY
value|0x80
end_define

begin_define
define|#
directive|define
name|CAPI_INFO
value|0x08
end_define

begin_define
define|#
directive|define
name|CAPI_LISTEN
value|0x05
end_define

begin_define
define|#
directive|define
name|CAPI_MANUFACTURER
value|0xff
end_define

begin_define
define|#
directive|define
name|CAPI_RESET_B3
value|0x87
end_define

begin_define
define|#
directive|define
name|CAPI_SELECT_B_PROTOCOL
value|0x41
end_define

begin_comment
comment|/* CAPI subcommands */
end_comment

begin_define
define|#
directive|define
name|CAPI_REQ
value|0x80
end_define

begin_define
define|#
directive|define
name|CAPI_CONF
value|0x81
end_define

begin_define
define|#
directive|define
name|CAPI_IND
value|0x82
end_define

begin_define
define|#
directive|define
name|CAPI_RESP
value|0x83
end_define

begin_comment
comment|/* CAPI combined commands */
end_comment

begin_define
define|#
directive|define
name|CAPICMD
parameter_list|(
name|cmd
parameter_list|,
name|subcmd
parameter_list|)
value|(((subcmd)<<8)|(cmd))
end_define

begin_define
define|#
directive|define
name|CAPI_DISCONNECT_REQ
value|CAPICMD(CAPI_DISCONNECT,CAPI_REQ)
end_define

begin_define
define|#
directive|define
name|CAPI_DISCONNECT_CONF
value|CAPICMD(CAPI_DISCONNECT,CAPI_CONF)
end_define

begin_define
define|#
directive|define
name|CAPI_DISCONNECT_IND
value|CAPICMD(CAPI_DISCONNECT,CAPI_IND)
end_define

begin_define
define|#
directive|define
name|CAPI_DISCONNECT_RESP
value|CAPICMD(CAPI_DISCONNECT,CAPI_RESP)
end_define

begin_define
define|#
directive|define
name|CAPI_ALERT_REQ
value|CAPICMD(CAPI_ALERT,CAPI_REQ)
end_define

begin_define
define|#
directive|define
name|CAPI_ALERT_CONF
value|CAPICMD(CAPI_ALERT,CAPI_CONF)
end_define

begin_define
define|#
directive|define
name|CAPI_CONNECT_REQ
value|CAPICMD(CAPI_CONNECT,CAPI_REQ)
end_define

begin_define
define|#
directive|define
name|CAPI_CONNECT_CONF
value|CAPICMD(CAPI_CONNECT,CAPI_CONF)
end_define

begin_define
define|#
directive|define
name|CAPI_CONNECT_IND
value|CAPICMD(CAPI_CONNECT,CAPI_IND)
end_define

begin_define
define|#
directive|define
name|CAPI_CONNECT_RESP
value|CAPICMD(CAPI_CONNECT,CAPI_RESP)
end_define

begin_define
define|#
directive|define
name|CAPI_CONNECT_ACTIVE_REQ
value|CAPICMD(CAPI_CONNECT_ACTIVE,CAPI_REQ)
end_define

begin_define
define|#
directive|define
name|CAPI_CONNECT_ACTIVE_CONF
value|CAPICMD(CAPI_CONNECT_ACTIVE,CAPI_CONF)
end_define

begin_define
define|#
directive|define
name|CAPI_CONNECT_ACTIVE_IND
value|CAPICMD(CAPI_CONNECT_ACTIVE,CAPI_IND)
end_define

begin_define
define|#
directive|define
name|CAPI_CONNECT_ACTIVE_RESP
value|CAPICMD(CAPI_CONNECT_ACTIVE,CAPI_RESP)
end_define

begin_define
define|#
directive|define
name|CAPI_SELECT_B_PROTOCOL_REQ
value|CAPICMD(CAPI_SELECT_B_PROTOCOL,CAPI_REQ)
end_define

begin_define
define|#
directive|define
name|CAPI_SELECT_B_PROTOCOL_CONF
value|CAPICMD(CAPI_SELECT_B_PROTOCOL,CAPI_CONF)
end_define

begin_define
define|#
directive|define
name|CAPI_CONNECT_B3_REQ
value|CAPICMD(CAPI_CONNECT_B3,CAPI_REQ)
end_define

begin_define
define|#
directive|define
name|CAPI_CONNECT_B3_CONF
value|CAPICMD(CAPI_CONNECT_B3,CAPI_CONF)
end_define

begin_define
define|#
directive|define
name|CAPI_CONNECT_B3_IND
value|CAPICMD(CAPI_CONNECT_B3,CAPI_IND)
end_define

begin_define
define|#
directive|define
name|CAPI_CONNECT_B3_RESP
value|CAPICMD(CAPI_CONNECT_B3,CAPI_RESP)
end_define

begin_define
define|#
directive|define
name|CAPI_CONNECT_B3_ACTIVE_REQ
value|CAPICMD(CAPI_CONNECT_B3_ACTIVE,CAPI_REQ)
end_define

begin_define
define|#
directive|define
name|CAPI_CONNECT_B3_ACTIVE_CONF
value|CAPICMD(CAPI_CONNECT_B3_ACTIVE,CAPI_CONF)
end_define

begin_define
define|#
directive|define
name|CAPI_CONNECT_B3_ACTIVE_IND
value|CAPICMD(CAPI_CONNECT_B3_ACTIVE,CAPI_IND)
end_define

begin_define
define|#
directive|define
name|CAPI_CONNECT_B3_ACTIVE_RESP
value|CAPICMD(CAPI_CONNECT_B3_ACTIVE,CAPI_RESP)
end_define

begin_define
define|#
directive|define
name|CAPI_CONNECT_B3_T90_ACTIVE_IND
value|CAPICMD(CAPI_CONNECT_B3_T90_ACTIVE,CAPI_IND)
end_define

begin_define
define|#
directive|define
name|CAPI_CONNECT_B3_T90_ACTIVE_RESP
value|CAPICMD(CAPI_CONNECT_B3_T90_ACTIVE,CAPI_RESP)
end_define

begin_define
define|#
directive|define
name|CAPI_DATA_B3_REQ
value|CAPICMD(CAPI_DATA_B3,CAPI_REQ)
end_define

begin_define
define|#
directive|define
name|CAPI_DATA_B3_CONF
value|CAPICMD(CAPI_DATA_B3,CAPI_CONF)
end_define

begin_define
define|#
directive|define
name|CAPI_DATA_B3_IND
value|CAPICMD(CAPI_DATA_B3,CAPI_IND)
end_define

begin_define
define|#
directive|define
name|CAPI_DATA_B3_RESP
value|CAPICMD(CAPI_DATA_B3,CAPI_RESP)
end_define

begin_define
define|#
directive|define
name|CAPI_DISCONNECT_B3_REQ
value|CAPICMD(CAPI_DISCONNECT_B3,CAPI_REQ)
end_define

begin_define
define|#
directive|define
name|CAPI_DISCONNECT_B3_CONF
value|CAPICMD(CAPI_DISCONNECT_B3,CAPI_CONF)
end_define

begin_define
define|#
directive|define
name|CAPI_DISCONNECT_B3_IND
value|CAPICMD(CAPI_DISCONNECT_B3,CAPI_IND)
end_define

begin_define
define|#
directive|define
name|CAPI_DISCONNECT_B3_RESP
value|CAPICMD(CAPI_DISCONNECT_B3,CAPI_RESP)
end_define

begin_define
define|#
directive|define
name|CAPI_RESET_B3_REQ
value|CAPICMD(CAPI_RESET_B3,CAPI_REQ)
end_define

begin_define
define|#
directive|define
name|CAPI_RESET_B3_CONF
value|CAPICMD(CAPI_RESET_B3,CAPI_CONF)
end_define

begin_define
define|#
directive|define
name|CAPI_RESET_B3_IND
value|CAPICMD(CAPI_RESET_B3,CAPI_IND)
end_define

begin_define
define|#
directive|define
name|CAPI_RESET_B3_RESP
value|CAPICMD(CAPI_RESET_B3,CAPI_RESP)
end_define

begin_define
define|#
directive|define
name|CAPI_LISTEN_REQ
value|CAPICMD(CAPI_LISTEN,CAPI_REQ)
end_define

begin_define
define|#
directive|define
name|CAPI_LISTEN_CONF
value|CAPICMD(CAPI_LISTEN,CAPI_CONF)
end_define

begin_define
define|#
directive|define
name|CAPI_MANUFACTURER_REQ
value|CAPICMD(CAPI_MANUFACTURER,CAPI_REQ)
end_define

begin_define
define|#
directive|define
name|CAPI_MANUFACTURER_CONF
value|CAPICMD(CAPI_MANUFACTURER,CAPI_CONF)
end_define

begin_define
define|#
directive|define
name|CAPI_MANUFACTURER_IND
value|CAPICMD(CAPI_MANUFACTURER,CAPI_IND)
end_define

begin_define
define|#
directive|define
name|CAPI_MANUFACTURER_RESP
value|CAPICMD(CAPI_MANUFACTURER,CAPI_RESP)
end_define

begin_define
define|#
directive|define
name|CAPI_FACILITY_REQ
value|CAPICMD(CAPI_FACILITY,CAPI_REQ)
end_define

begin_define
define|#
directive|define
name|CAPI_FACILITY_CONF
value|CAPICMD(CAPI_FACILITY,CAPI_CONF)
end_define

begin_define
define|#
directive|define
name|CAPI_FACILITY_IND
value|CAPICMD(CAPI_FACILITY,CAPI_IND)
end_define

begin_define
define|#
directive|define
name|CAPI_FACILITY_RESP
value|CAPICMD(CAPI_FACILITY,CAPI_RESP)
end_define

begin_define
define|#
directive|define
name|CAPI_INFO_REQ
value|CAPICMD(CAPI_INFO,CAPI_REQ)
end_define

begin_define
define|#
directive|define
name|CAPI_INFO_CONF
value|CAPICMD(CAPI_INFO,CAPI_CONF)
end_define

begin_define
define|#
directive|define
name|CAPI_INFO_IND
value|CAPICMD(CAPI_INFO,CAPI_IND)
end_define

begin_define
define|#
directive|define
name|CAPI_INFO_RESP
value|CAPICMD(CAPI_INFO,CAPI_RESP)
end_define

begin_comment
comment|/* CAPI message access helpers */
end_comment

begin_comment
comment|/*  * CAPI message header:  * word   Length  * word   ApplId  * byte   Command  * byte   Subcommand  * word   MsgId  *  * Note that in the following, Controller/PLCI/NCCI is coded as follows:  * bits 0..6 = controller, bit 7 = ext/int, bits 8..15 = PLCI, and  * bits 16..31 = NCCI value.  *  * ALERT_REQ, 01 80:  * dword  PLCI  * struct Additional Info  *  * ALERT_CONF, 01 81:  * dword  PLCI  * word   Info (0 = OK, other = cause)  *  * CONNECT_REQ, 02 80:  * dword  controller  * word   CIP  * struct Called party number  * struct Calling party number  * struct Called party subaddress  * struct Calling party subaddress  * struct Bearer Capability  * struct Low Layer Compatibility  * struct High Layer Compatibility  * struct Additional Info  *  * CONNECT_CONF, 02 81:  * dword  PLCI  * word   Info (0 = OK, other = cause)  *  * CONNECT_IND, 02 82:  * dword  PLCI  * word   CIP  * struct Called party number  * struct Calling party number  * struct Called party subaddress  * struct Calling party subaddress  * struct Bearer Capability  * struct Low Layer Compatibility  * struct High Layer Compatibility  * struct Additional Info  * struct Second Calling party number  *  * CONNECT_RESP, 02 83:  * dword  PLCI  * word   Reject (0 = accept, 1 = ignore, 2 = reject/normal clearing)  * struct B protocol  * struct Connected number  * struct Connected subaddress  * struct Low Layer Compatibility  * struct Additional Info  *  * CONNECT_ACTIVE_IND, 03 82:  * dword  PLCI  * struct Connected number  * struct Connected subaddress  * struct Low Layer Compatibility  *  * CONNECT_ACTIVE_RESP, 03 83:  * dword  PLCI  *  * CONNECT_B3_REQ, 82 80:  * dword  PLCI  * struct NCPI  *  * CONNECT_B3_CONF, 82 81:  * dword  NCCI  * word   Info (0 = connected, other = cause)  *  * CONNECT_B3_IND, 82 82:  * dword  NCCI  * struct NCPI  *  * CONNECT_B3_RESP, 82 83:  * dword  NCCI  * word   Reject (0 = accept, 2 = reject/normal clearing)  * struct NCPI  *  * CONNECT_B3_ACTIVE_IND, 83 82:  * dword  NCCI  * struct NCPI  *  * CONNECT_B3_ACTIVE_RESP, 83  83:  * dword  NCCI  *  * DATA_B3_REQ, 86 80:  * dword  NCCI  * dword  Data pointer  * word   Data length  * word   Data handle (packet id)  * word   Flags (02 = more)  *  * DATA_B3_CONF, 86 81:  * dword  NCCI  * word   Data handle (packet id)  * word   Info (0 = OK, other = cause)  *  * DATA_B3_IND, 86 82:  * dword  NCCI  * dword  Data pointer  * word   Data length  * word   Data handle (packet id)  * word   Flags (02 = more)  *  * DATA_B3_RESP, 86 83:  * dword  NCCI  * word   Data handle (packet id)  *  * DISCONNECT_B3_REQ, 84 80:  * dword  NCCI  * struct NCPI  *  * DISCONNECT_B3_CONF, 84 81:  * dword  NCCI  * word   Info (0 = OK, other = cause)  *  * DISCONNECT_B3_IND, 84 82:  * dword  NCCI  * word   Reason  * struct NCPI  *  * DISCONNECT_B3_RESP, 84 83:  * dword  NCCI  *  * DISCONNECT_REQ, 04 80:  * dword  PLCI  * struct Additional Info  *  * DISCONNECT_CONF, 04 81:  * dword  PLCI  * word   Info (0 = OK, other = cause)  *  * DISCONNECT_IND, 04 82:  * dword  PLCI  * word   Reason  *  * DISCONNECT_RESP, 04 83:  * dword  PLCI  *  * LISTEN_REQ, 05 80:  * dword  Controller  * dword  Info mask (bits 0..9 used)  * dword  CIP Mask (bit 0 = any match)  * dword  CIP Mask 2 (bit 0 = any match)  * struct Calling party number  * struct Calling party subaddress  *  * LISTEN_CONF, 05 81:  * dword  Controller  * word   Info (0 = OK, other = cause)  *  * INFO_REQ, 08 80:  * dword  Controller/PLCI  * struct Called party number  * struct Additional Info  *  * INFO_CONF, 08 81:  * dword  Controller/PLCI  * word   Info (0 = OK, other = cause)  *  * INFO_IND, 08 82:  * dword  Controller/PLCI  * word   Info number  * struct Info element  *  * INFO_RESP, 08 83:  * dword  Controller/PLCI  */
end_comment

begin_define
define|#
directive|define
name|CAPIMSG_LEN
parameter_list|(
name|msg
parameter_list|)
value|(msg[0]|(msg[1]<<8))
end_define

begin_define
define|#
directive|define
name|CAPIMSG_DATALEN
parameter_list|(
name|msg
parameter_list|)
value|(msg[16]|(msg[17]<<8))
end_define

begin_function
specifier|static
name|__inline
name|u_int8_t
modifier|*
name|capimsg_getu8
parameter_list|(
name|u_int8_t
modifier|*
name|msg
parameter_list|,
name|u_int8_t
modifier|*
name|val
parameter_list|)
block|{
operator|*
name|val
operator|=
operator|*
name|msg
expr_stmt|;
return|return
operator|(
name|msg
operator|+
literal|1
operator|)
return|;
block|}
end_function

begin_function
specifier|static
name|__inline
name|u_int8_t
modifier|*
name|capimsg_getu16
parameter_list|(
name|u_int8_t
modifier|*
name|msg
parameter_list|,
name|u_int16_t
modifier|*
name|val
parameter_list|)
block|{
operator|*
name|val
operator|=
operator|(
name|msg
index|[
literal|0
index|]
operator||
operator|(
name|msg
index|[
literal|1
index|]
operator|<<
literal|8
operator|)
operator|)
expr_stmt|;
return|return
operator|(
name|msg
operator|+
literal|2
operator|)
return|;
block|}
end_function

begin_function
specifier|static
name|__inline
name|u_int8_t
modifier|*
name|capimsg_getu32
parameter_list|(
name|u_int8_t
modifier|*
name|msg
parameter_list|,
name|u_int32_t
modifier|*
name|val
parameter_list|)
block|{
operator|*
name|val
operator|=
operator|(
name|msg
index|[
literal|0
index|]
operator||
operator|(
name|msg
index|[
literal|1
index|]
operator|<<
literal|8
operator|)
operator||
operator|(
name|msg
index|[
literal|2
index|]
operator|<<
literal|16
operator|)
operator||
operator|(
name|msg
index|[
literal|3
index|]
operator|<<
literal|24
operator|)
operator|)
expr_stmt|;
return|return
operator|(
name|msg
operator|+
literal|4
operator|)
return|;
block|}
end_function

begin_function
specifier|static
name|__inline
name|u_int8_t
modifier|*
name|capimsg_setu8
parameter_list|(
name|u_int8_t
modifier|*
name|msg
parameter_list|,
name|u_int8_t
name|val
parameter_list|)
block|{
name|msg
index|[
literal|0
index|]
operator|=
name|val
expr_stmt|;
return|return
operator|(
name|msg
operator|+
literal|1
operator|)
return|;
block|}
end_function

begin_function
specifier|static
name|__inline
name|u_int8_t
modifier|*
name|capimsg_setu16
parameter_list|(
name|u_int8_t
modifier|*
name|msg
parameter_list|,
name|u_int16_t
name|val
parameter_list|)
block|{
name|msg
index|[
literal|0
index|]
operator|=
operator|(
name|val
operator|&
literal|0xff
operator|)
expr_stmt|;
name|msg
index|[
literal|1
index|]
operator|=
operator|(
name|val
operator|>>
literal|8
operator|)
operator|&
literal|0xff
expr_stmt|;
return|return
operator|(
name|msg
operator|+
literal|2
operator|)
return|;
block|}
end_function

begin_function
specifier|static
name|__inline
name|u_int8_t
modifier|*
name|capimsg_setu32
parameter_list|(
name|u_int8_t
modifier|*
name|msg
parameter_list|,
name|u_int32_t
name|val
parameter_list|)
block|{
name|msg
index|[
literal|0
index|]
operator|=
operator|(
name|val
operator|&
literal|0xff
operator|)
expr_stmt|;
name|msg
index|[
literal|1
index|]
operator|=
operator|(
name|val
operator|>>
literal|8
operator|)
operator|&
literal|0xff
expr_stmt|;
name|msg
index|[
literal|2
index|]
operator|=
operator|(
name|val
operator|>>
literal|16
operator|)
operator|&
literal|0xff
expr_stmt|;
name|msg
index|[
literal|3
index|]
operator|=
operator|(
name|val
operator|>>
literal|24
operator|)
operator|&
literal|0xff
expr_stmt|;
return|return
operator|(
name|msg
operator|+
literal|4
operator|)
return|;
block|}
end_function

begin_comment
comment|/* //  CAPI message handlers called by higher layers */
end_comment

begin_function_decl
specifier|extern
name|void
name|capi_listen_req
parameter_list|(
name|capi_softc_t
modifier|*
name|sc
parameter_list|,
name|u_int32_t
name|CIP
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|capi_alert_req
parameter_list|(
name|capi_softc_t
modifier|*
name|sc
parameter_list|,
name|call_desc_t
modifier|*
name|cd
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|capi_connect_req
parameter_list|(
name|capi_softc_t
modifier|*
name|sc
parameter_list|,
name|call_desc_t
modifier|*
name|cd
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|capi_connect_b3_req
parameter_list|(
name|capi_softc_t
modifier|*
name|sc
parameter_list|,
name|call_desc_t
modifier|*
name|cd
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|capi_connect_resp
parameter_list|(
name|capi_softc_t
modifier|*
name|sc
parameter_list|,
name|call_desc_t
modifier|*
name|cd
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|capi_data_b3_req
parameter_list|(
name|capi_softc_t
modifier|*
name|sc
parameter_list|,
name|int
name|chan
parameter_list|,
name|struct
name|mbuf
modifier|*
name|m
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|capi_disconnect_req
parameter_list|(
name|capi_softc_t
modifier|*
name|sc
parameter_list|,
name|call_desc_t
modifier|*
name|cd
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* //  CAPI message handlers called by the receive routine */
end_comment

begin_function_decl
specifier|extern
name|void
name|capi_listen_conf
parameter_list|(
name|capi_softc_t
modifier|*
name|sc
parameter_list|,
name|struct
name|mbuf
modifier|*
name|m
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|capi_info_ind
parameter_list|(
name|capi_softc_t
modifier|*
name|sc
parameter_list|,
name|struct
name|mbuf
modifier|*
name|m
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|capi_alert_conf
parameter_list|(
name|capi_softc_t
modifier|*
name|sc
parameter_list|,
name|struct
name|mbuf
modifier|*
name|m
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|capi_connect_conf
parameter_list|(
name|capi_softc_t
modifier|*
name|sc
parameter_list|,
name|struct
name|mbuf
modifier|*
name|m
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|capi_connect_active_ind
parameter_list|(
name|capi_softc_t
modifier|*
name|sc
parameter_list|,
name|struct
name|mbuf
modifier|*
name|m
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|capi_connect_b3_conf
parameter_list|(
name|capi_softc_t
modifier|*
name|sc
parameter_list|,
name|struct
name|mbuf
modifier|*
name|m
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|capi_connect_b3_active_ind
parameter_list|(
name|capi_softc_t
modifier|*
name|sc
parameter_list|,
name|struct
name|mbuf
modifier|*
name|m
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|capi_connect_ind
parameter_list|(
name|capi_softc_t
modifier|*
name|sc
parameter_list|,
name|struct
name|mbuf
modifier|*
name|m
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|capi_connect_b3_ind
parameter_list|(
name|capi_softc_t
modifier|*
name|sc
parameter_list|,
name|struct
name|mbuf
modifier|*
name|m
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|capi_data_b3_conf
parameter_list|(
name|capi_softc_t
modifier|*
name|sc
parameter_list|,
name|struct
name|mbuf
modifier|*
name|m
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|capi_data_b3_ind
parameter_list|(
name|capi_softc_t
modifier|*
name|sc
parameter_list|,
name|struct
name|mbuf
modifier|*
name|m
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|capi_disconnect_conf
parameter_list|(
name|capi_softc_t
modifier|*
name|sc
parameter_list|,
name|struct
name|mbuf
modifier|*
name|m
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|capi_disconnect_b3_ind
parameter_list|(
name|capi_softc_t
modifier|*
name|sc
parameter_list|,
name|struct
name|mbuf
modifier|*
name|m
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|capi_disconnect_ind
parameter_list|(
name|capi_softc_t
modifier|*
name|sc
parameter_list|,
name|struct
name|mbuf
modifier|*
name|m
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _I4B_CAPI_MSGS_H_ */
end_comment

end_unit

