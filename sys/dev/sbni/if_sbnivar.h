begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1997-2001 Granch, Ltd. All rights reserved.  * Author: Denis I.Timofeev<timofeev@granch.ru>  *  * Redistributon and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice unmodified, this list of conditions, and the following  *    disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_comment
comment|/*  * SBNI12 definitions  */
end_comment

begin_comment
comment|/*  * CONFIGURATION PARAMETER:  *  *	Uncomment this if you want to use model SBNI12D-11/ISA with same IRQ  *	for both first and second channels.  */
end_comment

begin_define
define|#
directive|define
name|SBNI_DUAL_COMPOUND
value|1
end_define

begin_define
define|#
directive|define
name|SBNI_DEBUG
value|0
end_define

begin_if
if|#
directive|if
name|SBNI_DEBUG
end_if

begin_define
define|#
directive|define
name|DP
parameter_list|(
name|A
parameter_list|)
value|A
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|DP
parameter_list|(
name|A
parameter_list|)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_struct
struct|struct
name|sbni_in_stats
block|{
name|u_int32_t
name|all_rx_number
decl_stmt|;
name|u_int32_t
name|bad_rx_number
decl_stmt|;
name|u_int32_t
name|timeout_number
decl_stmt|;
name|u_int32_t
name|all_tx_number
decl_stmt|;
name|u_int32_t
name|resend_tx_number
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|sbni_flags
block|{
name|u_int
name|mac_addr
range|:
literal|24
decl_stmt|;
name|u_int
name|rxl
range|:
literal|4
decl_stmt|;
name|u_int
name|rate
range|:
literal|2
decl_stmt|;
name|u_int
name|fixed_rxl
range|:
literal|1
decl_stmt|;
name|u_int
name|fixed_rate
range|:
literal|1
decl_stmt|;
block|}
struct|;
end_struct

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_comment
comment|/* to avoid compile this decls with sbniconfig */
end_comment

begin_struct
struct|struct
name|sbni_softc
block|{
name|struct
name|arpcom
name|arpcom
decl_stmt|;
comment|/* ethernet common */
name|int
name|base_addr
decl_stmt|;
name|int
name|irq
decl_stmt|;
name|int
name|io_rid
decl_stmt|;
name|int
name|irq_rid
decl_stmt|;
name|struct
name|resource
modifier|*
name|io_res
decl_stmt|;
name|struct
name|resource
modifier|*
name|irq_res
decl_stmt|;
name|void
modifier|*
name|irq_handle
decl_stmt|;
name|struct
name|mbuf
modifier|*
name|rx_buf_p
decl_stmt|;
comment|/* receive buffer ptr */
name|struct
name|mbuf
modifier|*
name|tx_buf_p
decl_stmt|;
comment|/* transmit buffer ptr */
name|u_int
name|pktlen
decl_stmt|;
comment|/* length of transmitting pkt */
name|u_int
name|framelen
decl_stmt|;
comment|/* current frame length */
name|u_int
name|maxframe
decl_stmt|;
comment|/* maximum valid frame length */
name|u_int
name|state
decl_stmt|;
name|u_int
name|inppos
decl_stmt|;
comment|/* positions in rx/tx buffers */
name|u_int
name|outpos
decl_stmt|;
comment|/* positions in rx/tx buffers */
comment|/* transmitting frame number - from frames qty to 1 */
name|u_int
name|tx_frameno
decl_stmt|;
comment|/* expected number of next receiving frame */
name|u_int
name|wait_frameno
decl_stmt|;
comment|/* count of failed attempts to frame send - 32 attempts do before 	   error - while receiver tunes on opposite side of wire */
name|u_int
name|trans_errors
decl_stmt|;
comment|/* idle time; send pong when limit exceeded */
name|u_int
name|timer_ticks
decl_stmt|;
comment|/* fields used for receive level autoselection */
name|int
name|delta_rxl
decl_stmt|;
name|u_int
name|cur_rxl_index
decl_stmt|;
name|u_int
name|timeout_rxl
decl_stmt|;
name|u_int32_t
name|cur_rxl_rcvd
decl_stmt|;
name|u_int32_t
name|prev_rxl_rcvd
decl_stmt|;
name|struct
name|sbni_csr1
name|csr1
decl_stmt|;
comment|/* current value of CSR1 */
name|struct
name|sbni_in_stats
name|in_stats
decl_stmt|;
comment|/* internal statistics */
name|struct
name|callout_handle
name|wch
decl_stmt|;
name|struct
name|sbni_softc
modifier|*
name|slave_sc
decl_stmt|;
ifdef|#
directive|ifdef
name|SBNI_DUAL_COMPOUND
name|struct
name|sbni_softc
modifier|*
name|link
decl_stmt|;
endif|#
directive|endif
block|}
struct|;
end_struct

begin_function_decl
name|void
name|sbni_intr
parameter_list|(
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|sbni_probe
parameter_list|(
name|struct
name|sbni_softc
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|sbni_attach
parameter_list|(
name|struct
name|sbni_softc
modifier|*
parameter_list|,
name|int
parameter_list|,
name|struct
name|sbni_flags
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
specifier|extern
name|u_int32_t
name|next_sbni_unit
decl_stmt|;
end_decl_stmt

begin_ifdef
ifdef|#
directive|ifdef
name|SBNI_DUAL_COMPOUND
end_ifdef

begin_decl_stmt
specifier|extern
name|struct
name|sbni_softc
modifier|*
name|headlist
decl_stmt|;
end_decl_stmt

begin_function_decl
name|struct
name|sbni_softc
modifier|*
name|connect_to_master
parameter_list|(
name|struct
name|sbni_softc
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _KERNEL */
end_comment

begin_comment
comment|/*  * SBNI socket ioctl params  */
end_comment

begin_define
define|#
directive|define
name|SIOCGHWFLAGS
value|_IOWR('i', 62, struct ifreq)
end_define

begin_comment
comment|/* get flags */
end_comment

begin_define
define|#
directive|define
name|SIOCSHWFLAGS
value|_IOWR('i', 61, struct ifreq)
end_define

begin_comment
comment|/* set flags */
end_comment

begin_define
define|#
directive|define
name|SIOCGINSTATS
value|_IOWR('i', 60, struct ifreq)
end_define

begin_comment
comment|/* get internal stats */
end_comment

begin_define
define|#
directive|define
name|SIOCRINSTATS
value|_IOWR('i', 63, struct ifreq)
end_define

begin_comment
comment|/* reset internal stats */
end_comment

begin_comment
comment|/*  * CRC-32 stuff  */
end_comment

begin_define
define|#
directive|define
name|CRC32
parameter_list|(
name|c
parameter_list|,
name|crc
parameter_list|)
value|(crc32tab[((size_t)(crc) ^ (c))& 0xff] ^ (((crc)>> 8)& 0x00ffffff))
end_define

begin_comment
comment|/* CRC generator EDB88320 */
end_comment

begin_comment
comment|/* CRC remainder 2144DF1C */
end_comment

begin_comment
comment|/* CRC initial value 0 */
end_comment

begin_define
define|#
directive|define
name|CRC32_REMAINDER
value|0x2144df1c
end_define

begin_define
define|#
directive|define
name|CRC32_INITIAL
value|0x00000000
end_define

end_unit

