begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2001 Cubical Solutions Ltd. All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * capi/capi.h		The CAPI device interface.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_I4B_CAPI_H_
end_ifndef

begin_define
define|#
directive|define
name|_I4B_CAPI_H_
end_define

begin_comment
comment|/* //  CAPI driver context: B channels and controller softcs. */
end_comment

begin_define
define|#
directive|define
name|INVALID
value|-1
end_define

begin_enum
enum|enum
name|capi_b_state
block|{
name|B_FREE
block|,
comment|/* channel free, ncci invalid */
name|B_CONNECT_CONF
block|,
comment|/* wait for CONNECT_CONF */
name|B_CONNECT_IND
block|,
comment|/* IND got, wait for appl RESP */
name|B_CONNECT_ACTIVE_IND
block|,
comment|/* wait for CONNECT_ACTIVE_IND */
name|B_CONNECT_B3_CONF
block|,
comment|/* wait for CONNECT_B3_CONF */
name|B_CONNECT_B3_IND
block|,
comment|/* wait for CONNECT_B3_IND */
name|B_CONNECT_B3_ACTIVE_IND
block|,
comment|/* wait for CONNECT_B3_ACTIVE_IND */
name|B_CONNECTED
block|,
comment|/* channel connected& in use */
name|B_DISCONNECT_CONF
block|,
comment|/* wait for DISCONNECT_CONF */
name|B_DISCONNECT_B3_CONF
block|,
comment|/* wait for DISCONNECT_B3_CONF */
name|B_DISCONNECT_IND
block|,
comment|/* wait for DISCONNECT_IND */
block|}
enum|;
end_enum

begin_typedef
typedef|typedef
struct|struct
name|capi_bchan
block|{
comment|/* Channel state */
name|int
name|ncci
decl_stmt|;
define|#
directive|define
name|CAPI_CTRL_MASK
value|0x000000ff
define|#
directive|define
name|CAPI_PLCI_MASK
value|0x0000ffff
define|#
directive|define
name|CAPI_NCCI_MASK
value|0xffff0000
name|u_int16_t
name|msgid
decl_stmt|;
name|int
name|busy
decl_stmt|;
name|enum
name|capi_b_state
name|state
decl_stmt|;
name|struct
name|ifqueue
name|tx_queue
decl_stmt|;
name|struct
name|ifqueue
name|rx_queue
decl_stmt|;
name|int
name|rxcount
decl_stmt|;
name|int
name|txcount
decl_stmt|;
comment|/* The rest is needed for i4b integration */
name|int
name|bprot
decl_stmt|;
name|int
name|cdid
decl_stmt|;
name|struct
name|mbuf
modifier|*
name|in_mbuf
decl_stmt|;
name|isdn_link_t
name|capi_isdn_linktab
decl_stmt|;
name|drvr_link_t
modifier|*
name|capi_drvr_linktab
decl_stmt|;
block|}
name|capi_bchan_t
typedef|;
end_typedef

begin_enum
enum|enum
name|capi_c_state
block|{
name|C_DOWN
block|,
comment|/* controller uninitialized */
name|C_READY
block|,
comment|/* controller initialized but not listening */
name|C_UP
block|,
comment|/* controller listening */
block|}
enum|;
end_enum

begin_typedef
typedef|typedef
struct|struct
name|capi_softc
block|{
name|int
name|sc_unit
decl_stmt|;
comment|/* index in capi_sc[]                      */
name|int
name|ctrl_unit
decl_stmt|;
comment|/* index in isdn_ctrl_tab[]                */
name|int
name|card_type
decl_stmt|;
comment|/* CARD_TYPEC_xxx, filled by ll driver     */
name|int
name|sc_nbch
decl_stmt|;
comment|/* number of b channels on this controller */
name|int
name|sc_enabled
decl_stmt|;
comment|/* is daemon connected TRUE/FALSE          */
name|int
name|sc_msgid
decl_stmt|;
comment|/* next CAPI message id                    */
name|char
name|sc_profile
index|[
literal|64
index|]
decl_stmt|;
comment|/* CAPI profile data                       */
name|enum
name|capi_c_state
name|sc_state
decl_stmt|;
name|capi_bchan_t
name|sc_bchan
index|[
name|MAX_BCHAN
index|]
decl_stmt|;
comment|/* Link layer driver context holder and methods */
name|void
modifier|*
name|ctx
decl_stmt|;
name|int
function_decl|(
modifier|*
name|load
function_decl|)
parameter_list|(
name|struct
name|capi_softc
modifier|*
parameter_list|,
name|int
parameter_list|,
name|u_int8_t
modifier|*
parameter_list|)
function_decl|;
name|int
function_decl|(
modifier|*
name|reg_appl
function_decl|)
parameter_list|(
name|struct
name|capi_softc
modifier|*
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|)
function_decl|;
name|int
function_decl|(
modifier|*
name|rel_appl
function_decl|)
parameter_list|(
name|struct
name|capi_softc
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
name|int
function_decl|(
modifier|*
name|send
function_decl|)
parameter_list|(
name|struct
name|capi_softc
modifier|*
parameter_list|,
name|struct
name|mbuf
modifier|*
parameter_list|)
function_decl|;
block|}
name|capi_softc_t
typedef|;
end_typedef

begin_decl_stmt
specifier|extern
name|capi_softc_t
modifier|*
name|capi_sc
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|ncapi
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* //  CAPI upcalls for the link layer. */
end_comment

begin_define
define|#
directive|define
name|I4BCAPI_APPLID
value|1
end_define

begin_function_decl
specifier|extern
name|int
name|capi_ll_attach
parameter_list|(
name|capi_softc_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|capi_ll_control
parameter_list|(
name|capi_softc_t
modifier|*
parameter_list|,
name|int
name|op
parameter_list|,
name|int
name|arg
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|CAPI_CTRL_READY
value|0
end_define

begin_comment
comment|/* ctrl ready, value=TRUE/FALSE */
end_comment

begin_define
define|#
directive|define
name|CAPI_CTRL_PROFILE
value|1
end_define

begin_comment
comment|/* set CAPI profile             */
end_comment

begin_define
define|#
directive|define
name|CAPI_CTRL_NEW_NCCI
value|2
end_define

begin_comment
comment|/* new ncci value, assign bchan */
end_comment

begin_define
define|#
directive|define
name|CAPI_CTRL_FREE_NCCI
value|3
end_define

begin_comment
comment|/* free ncci value, clear bchan */
end_comment

begin_function_decl
specifier|extern
name|int
name|capi_ll_receive
parameter_list|(
name|capi_softc_t
modifier|*
parameter_list|,
name|struct
name|mbuf
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|capi_start_tx
parameter_list|(
name|capi_softc_t
modifier|*
parameter_list|,
name|int
name|bchan
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _I4B_CAPI_H_ */
end_comment

end_unit

