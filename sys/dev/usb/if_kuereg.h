begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1997, 1998, 1999, 2000  *	Bill Paul<wpaul@ee.columbia.edu>.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by Bill Paul.  * 4. Neither the name of the author nor the names of any co-contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY Bill Paul AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL Bill Paul OR THE VOICES IN HIS HEAD  * BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR  * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF  * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS  * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN  * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)  * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF  * THE POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_comment
comment|/*  * Definitions for the KLSI KL5KUSB101B USB to ethernet controller.  * The KLSI part is controlled via vendor control requests, the structure  * of which depend a bit on the firmware running on the internal  * microcontroller. The one exception is the 'send scan data' command,  * which is used to load the firmware.  */
end_comment

begin_define
define|#
directive|define
name|KUE_CMD_GET_ETHER_DESCRIPTOR
value|0x00
end_define

begin_define
define|#
directive|define
name|KUE_CMD_SET_MCAST_FILTERS
value|0x01
end_define

begin_define
define|#
directive|define
name|KUE_CMD_SET_PKT_FILTER
value|0x02
end_define

begin_define
define|#
directive|define
name|KUE_CMD_GET_ETHERSTATS
value|0x03
end_define

begin_define
define|#
directive|define
name|KUE_CMD_GET_GPIO
value|0x04
end_define

begin_define
define|#
directive|define
name|KUE_CMD_SET_GPIO
value|0x05
end_define

begin_define
define|#
directive|define
name|KUE_CMD_SET_MAC
value|0x06
end_define

begin_define
define|#
directive|define
name|KUE_CMD_GET_MAC
value|0x07
end_define

begin_define
define|#
directive|define
name|KUE_CMD_SET_URB_SIZE
value|0x08
end_define

begin_define
define|#
directive|define
name|KUE_CMD_SET_SOFS
value|0x09
end_define

begin_define
define|#
directive|define
name|KUE_CMD_SET_EVEN_PKTS
value|0x0A
end_define

begin_define
define|#
directive|define
name|KUE_CMD_SEND_SCAN
value|0xFF
end_define

begin_struct
struct|struct
name|kue_ether_desc
block|{
name|u_int8_t
name|kue_len
decl_stmt|;
name|u_int8_t
name|kue_rsvd0
decl_stmt|;
name|u_int8_t
name|kue_rsvd1
decl_stmt|;
name|u_int8_t
name|kue_macaddr
index|[
name|ETHER_ADDR_LEN
index|]
decl_stmt|;
name|u_int8_t
name|kue_etherstats
index|[
literal|4
index|]
decl_stmt|;
name|u_int8_t
name|kue_maxseg
index|[
literal|2
index|]
decl_stmt|;
name|u_int8_t
name|kue_mcastfilt
index|[
literal|2
index|]
decl_stmt|;
name|u_int8_t
name|kue_rsvd2
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|KUE_ETHERSTATS
parameter_list|(
name|x
parameter_list|)
define|\
value|(*(u_int32_t *)&(x)->kue_desc.kue_etherstats)
end_define

begin_define
define|#
directive|define
name|KUE_MAXSEG
parameter_list|(
name|x
parameter_list|)
define|\
value|(*(u_int16_t *)&(x)->kue_desc.kue_maxseg)
end_define

begin_define
define|#
directive|define
name|KUE_MCFILTCNT
parameter_list|(
name|x
parameter_list|)
define|\
value|((*(u_int16_t *)&(x)->kue_desc.kue_mcastfilt)& 0x7FFF)
end_define

begin_define
define|#
directive|define
name|KUE_MCFILT
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
define|\
value|(char *)&(sc->kue_mcfilters[y * ETHER_ADDR_LEN])
end_define

begin_define
define|#
directive|define
name|KUE_STAT_TX_OK
value|0x00000001
end_define

begin_define
define|#
directive|define
name|KUE_STAT_RX_OK
value|0x00000002
end_define

begin_define
define|#
directive|define
name|KUE_STAT_TX_ERR
value|0x00000004
end_define

begin_define
define|#
directive|define
name|KUE_STAT_RX_ERR
value|0x00000008
end_define

begin_define
define|#
directive|define
name|KUE_STAT_RX_NOBUF
value|0x00000010
end_define

begin_define
define|#
directive|define
name|KUE_STAT_TX_UCAST_BYTES
value|0x00000020
end_define

begin_define
define|#
directive|define
name|KUE_STAT_TX_UCAST_FRAMES
value|0x00000040
end_define

begin_define
define|#
directive|define
name|KUE_STAT_TX_MCAST_BYTES
value|0x00000080
end_define

begin_define
define|#
directive|define
name|KUE_STAT_TX_MCAST_FRAMES
value|0x00000100
end_define

begin_define
define|#
directive|define
name|KUE_STAT_TX_BCAST_BYTES
value|0x00000200
end_define

begin_define
define|#
directive|define
name|KUE_STAT_TX_BCAST_FRAMES
value|0x00000400
end_define

begin_define
define|#
directive|define
name|KUE_STAT_RX_UCAST_BYTES
value|0x00000800
end_define

begin_define
define|#
directive|define
name|KUE_STAT_RX_UCAST_FRAMES
value|0x00001000
end_define

begin_define
define|#
directive|define
name|KUE_STAT_RX_MCAST_BYTES
value|0x00002000
end_define

begin_define
define|#
directive|define
name|KUE_STAT_RX_MCAST_FRAMES
value|0x00004000
end_define

begin_define
define|#
directive|define
name|KUE_STAT_RX_BCAST_BYTES
value|0x00008000
end_define

begin_define
define|#
directive|define
name|KUE_STAT_RX_BCAST_FRAMES
value|0x00010000
end_define

begin_define
define|#
directive|define
name|KUE_STAT_RX_CRCERR
value|0x00020000
end_define

begin_define
define|#
directive|define
name|KUE_STAT_TX_QUEUE_LENGTH
value|0x00040000
end_define

begin_define
define|#
directive|define
name|KUE_STAT_RX_ALIGNERR
value|0x00080000
end_define

begin_define
define|#
directive|define
name|KUE_STAT_TX_SINGLECOLL
value|0x00100000
end_define

begin_define
define|#
directive|define
name|KUE_STAT_TX_MULTICOLL
value|0x00200000
end_define

begin_define
define|#
directive|define
name|KUE_STAT_TX_DEFERRED
value|0x00400000
end_define

begin_define
define|#
directive|define
name|KUE_STAT_TX_MAXCOLLS
value|0x00800000
end_define

begin_define
define|#
directive|define
name|KUE_STAT_RX_OVERRUN
value|0x01000000
end_define

begin_define
define|#
directive|define
name|KUE_STAT_TX_UNDERRUN
value|0x02000000
end_define

begin_define
define|#
directive|define
name|KUE_STAT_TX_SQE_ERR
value|0x04000000
end_define

begin_define
define|#
directive|define
name|KUE_STAT_TX_CARRLOSS
value|0x08000000
end_define

begin_define
define|#
directive|define
name|KUE_STAT_RX_LATECOLL
value|0x10000000
end_define

begin_define
define|#
directive|define
name|KUE_RXFILT_PROMISC
value|0x0001
end_define

begin_define
define|#
directive|define
name|KUE_RXFILT_ALLMULTI
value|0x0002
end_define

begin_define
define|#
directive|define
name|KUE_RXFILT_UNICAST
value|0x0004
end_define

begin_define
define|#
directive|define
name|KUE_RXFILT_BROADCAST
value|0x0008
end_define

begin_define
define|#
directive|define
name|KUE_RXFILT_MULTICAST
value|0x0010
end_define

begin_define
define|#
directive|define
name|KUE_TIMEOUT
value|1000
end_define

begin_define
define|#
directive|define
name|ETHER_ALIGN
value|2
end_define

begin_define
define|#
directive|define
name|KUE_BUFSZ
value|1536
end_define

begin_define
define|#
directive|define
name|KUE_MIN_FRAMELEN
value|60
end_define

begin_define
define|#
directive|define
name|KUE_RX_LIST_CNT
value|1
end_define

begin_define
define|#
directive|define
name|KUE_TX_LIST_CNT
value|1
end_define

begin_define
define|#
directive|define
name|KUE_CTL_READ
value|0x01
end_define

begin_define
define|#
directive|define
name|KUE_CTL_WRITE
value|0x02
end_define

begin_define
define|#
directive|define
name|KUE_CONFIG_NO
value|1
end_define

begin_comment
comment|/*  * The interrupt endpoint is currently unused  * by the KLSI part.  */
end_comment

begin_define
define|#
directive|define
name|KUE_ENDPT_RX
value|0x0
end_define

begin_define
define|#
directive|define
name|KUE_ENDPT_TX
value|0x1
end_define

begin_define
define|#
directive|define
name|KUE_ENDPT_INTR
value|0x2
end_define

begin_define
define|#
directive|define
name|KUE_ENDPT_MAX
value|0x3
end_define

begin_struct
struct|struct
name|kue_type
block|{
name|u_int16_t
name|kue_vid
decl_stmt|;
name|u_int16_t
name|kue_did
decl_stmt|;
block|}
struct|;
end_struct

begin_struct_decl
struct_decl|struct
name|kue_softc
struct_decl|;
end_struct_decl

begin_struct
struct|struct
name|kue_chain
block|{
name|struct
name|kue_softc
modifier|*
name|kue_sc
decl_stmt|;
name|usbd_xfer_handle
name|kue_xfer
decl_stmt|;
name|char
modifier|*
name|kue_buf
decl_stmt|;
name|struct
name|mbuf
modifier|*
name|kue_mbuf
decl_stmt|;
name|int
name|kue_idx
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|kue_cdata
block|{
name|struct
name|kue_chain
name|kue_tx_chain
index|[
name|KUE_TX_LIST_CNT
index|]
decl_stmt|;
name|struct
name|kue_chain
name|kue_rx_chain
index|[
name|KUE_RX_LIST_CNT
index|]
decl_stmt|;
name|int
name|kue_tx_prod
decl_stmt|;
name|int
name|kue_tx_cons
decl_stmt|;
name|int
name|kue_tx_cnt
decl_stmt|;
name|int
name|kue_rx_prod
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|KUE_INC
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
value|(x) = (x + 1) % y
end_define

begin_struct
struct|struct
name|kue_softc
block|{
name|struct
name|arpcom
name|arpcom
decl_stmt|;
name|usbd_device_handle
name|kue_udev
decl_stmt|;
name|usbd_interface_handle
name|kue_iface
decl_stmt|;
name|struct
name|kue_ether_desc
name|kue_desc
decl_stmt|;
name|int
name|kue_ed
index|[
name|KUE_ENDPT_MAX
index|]
decl_stmt|;
name|usbd_pipe_handle
name|kue_ep
index|[
name|KUE_ENDPT_MAX
index|]
decl_stmt|;
name|int
name|kue_unit
decl_stmt|;
name|int
name|kue_if_flags
decl_stmt|;
name|u_int16_t
name|kue_rxfilt
decl_stmt|;
name|u_int8_t
modifier|*
name|kue_mcfilters
decl_stmt|;
name|struct
name|kue_cdata
name|kue_cdata
decl_stmt|;
name|struct
name|mtx
name|kue_mtx
decl_stmt|;
name|char
name|kue_dying
decl_stmt|;
name|struct
name|timeval
name|kue_rx_notice
decl_stmt|;
block|}
struct|;
end_struct

begin_if
if|#
directive|if
literal|0
end_if

begin_define
define|#
directive|define
name|KUE_LOCK
parameter_list|(
name|_sc
parameter_list|)
value|mtx_lock(&(_sc)->kue_mtx)
end_define

begin_define
define|#
directive|define
name|KUE_UNLOCK
parameter_list|(
name|_sc
parameter_list|)
value|mtx_unlock(&(_sc)->kue_mtx)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|KUE_LOCK
parameter_list|(
name|_sc
parameter_list|)
end_define

begin_define
define|#
directive|define
name|KUE_UNLOCK
parameter_list|(
name|_sc
parameter_list|)
end_define

begin_endif
endif|#
directive|endif
end_endif

end_unit

