begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1993 Herb Peyerl (hpeyerl@novatel.ca) All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions are  * met: 1. Redistributions of source code must retain the above copyright  * notice, this list of conditions and the following disclaimer. 2. The name  * of the author may not be used to endorse or promote products derived from  * this software without specific prior written permission  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR IMPLIED  * WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF  * MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO  * EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,  * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED  * TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR  * PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF  * LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING  * NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS  * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_struct
struct|struct
name|ep_board
block|{
name|u_short
name|prod_id
decl_stmt|;
comment|/* product ID */
name|int
name|cmd_off
decl_stmt|;
comment|/* command offset (bit shift) */
name|int
name|mii_trans
decl_stmt|;
comment|/* activate MII transiever */
name|u_short
name|res_cfg
decl_stmt|;
comment|/* resource configuration */
block|}
struct|;
end_struct

begin_comment
comment|/*  * Ethernet software status per interface.  */
end_comment

begin_struct
struct|struct
name|ep_softc
block|{
name|struct
name|arpcom
name|arpcom
decl_stmt|;
comment|/* Ethernet common part	*/
name|struct
name|ifmedia
name|ifmedia
decl_stmt|;
comment|/* media info		*/
name|device_t
name|dev
decl_stmt|;
name|struct
name|resource
modifier|*
name|iobase
decl_stmt|;
name|struct
name|resource
modifier|*
name|irq
decl_stmt|;
name|bus_space_handle_t
name|ep_bhandle
decl_stmt|;
name|bus_space_tag_t
name|ep_btag
decl_stmt|;
name|void
modifier|*
name|ep_intrhand
decl_stmt|;
name|int
name|ep_io_addr
decl_stmt|;
comment|/* i/o bus address	*/
name|u_short
name|ep_connectors
decl_stmt|;
comment|/* Connectors on this card. */
name|u_char
name|ep_connector
decl_stmt|;
comment|/* Configured connector.*/
name|struct
name|mbuf
modifier|*
name|top
decl_stmt|;
name|struct
name|mbuf
modifier|*
name|mcur
decl_stmt|;
name|short
name|cur_len
decl_stmt|;
name|int
name|stat
decl_stmt|;
comment|/* some flags */
define|#
directive|define
name|F_RX_FIRST
value|0x001
define|#
directive|define
name|F_PROMISC
value|0x008
define|#
directive|define
name|F_ACCESS_32_BITS
value|0x100
name|int
name|gone
decl_stmt|;
comment|/* adapter is not present (for PCCARD) */
name|struct
name|ep_board
name|epb
decl_stmt|;
name|int
name|unit
decl_stmt|;
ifdef|#
directive|ifdef
name|EP_LOCAL_STATS
name|short
name|tx_underrun
decl_stmt|;
name|short
name|rx_no_first
decl_stmt|;
name|short
name|rx_no_mbuf
decl_stmt|;
name|short
name|rx_overrunf
decl_stmt|;
name|short
name|rx_overrunl
decl_stmt|;
endif|#
directive|endif
block|}
struct|;
end_struct

begin_function_decl
name|int
name|ep_alloc
parameter_list|(
name|device_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ep_free
parameter_list|(
name|device_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ep_get_media
parameter_list|(
name|struct
name|ep_softc
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ep_attach
parameter_list|(
name|struct
name|ep_softc
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ep_intr
parameter_list|(
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|u_int16_t
name|get_e
parameter_list|(
name|struct
name|ep_softc
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ep_get_macaddr
parameter_list|(
name|struct
name|ep_softc
modifier|*
parameter_list|,
name|u_char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

end_unit

