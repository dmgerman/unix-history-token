begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * ppp_defs.h - PPP definitions.  *  * Copyright (c) 1994 The Australian National University.  * All rights reserved.  *  * Permission to use, copy, modify, and distribute this software and its  * documentation is hereby granted, provided that the above copyright  * notice appears in all copies.  This software is provided without any  * warranty, express or implied. The Australian National University  * makes no representations about the suitability of this software for  * any purpose.  *  * IN NO EVENT SHALL THE AUSTRALIAN NATIONAL UNIVERSITY BE LIABLE TO ANY  * PARTY FOR DIRECT, INDIRECT, SPECIAL, INCIDENTAL, OR CONSEQUENTIAL DAMAGES  * ARISING OUT OF THE USE OF THIS SOFTWARE AND ITS DOCUMENTATION, EVEN IF  * THE AUSTRALIAN NATIONAL UNIVERSITY HAVE BEEN ADVISED OF THE POSSIBILITY  * OF SUCH DAMAGE.  *  * THE AUSTRALIAN NATIONAL UNIVERSITY SPECIFICALLY DISCLAIMS ANY WARRANTIES,  * INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY  * AND FITNESS FOR A PARTICULAR PURPOSE.  THE SOFTWARE PROVIDED HEREUNDER IS  * ON AN "AS IS" BASIS, AND THE AUSTRALIAN NATIONAL UNIVERSITY HAS NO  * OBLIGATION TO PROVIDE MAINTENANCE, SUPPORT, UPDATES, ENHANCEMENTS,  * OR MODIFICATIONS.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_PPP_DEFS_H_
end_ifndef

begin_define
define|#
directive|define
name|_PPP_DEFS_H_
end_define

begin_comment
comment|/*  * The basic PPP frame.  */
end_comment

begin_define
define|#
directive|define
name|PPP_HDRLEN
value|4
end_define

begin_comment
comment|/* octets for standard ppp header */
end_comment

begin_define
define|#
directive|define
name|PPP_FCSLEN
value|2
end_define

begin_comment
comment|/* octets for FCS */
end_comment

begin_define
define|#
directive|define
name|PPP_MRU
value|1500
end_define

begin_comment
comment|/* default MRU = max length of info field */
end_comment

begin_define
define|#
directive|define
name|PPP_ADDRESS
parameter_list|(
name|p
parameter_list|)
value|(((u_char *)(p))[0])
end_define

begin_define
define|#
directive|define
name|PPP_CONTROL
parameter_list|(
name|p
parameter_list|)
value|(((u_char *)(p))[1])
end_define

begin_define
define|#
directive|define
name|PPP_PROTOCOL
parameter_list|(
name|p
parameter_list|)
value|((((u_char *)(p))[2]<< 8) + ((u_char *)(p))[3])
end_define

begin_comment
comment|/*  * Significant octet values.  */
end_comment

begin_define
define|#
directive|define
name|PPP_ALLSTATIONS
value|0xff
end_define

begin_comment
comment|/* All-Stations broadcast address */
end_comment

begin_define
define|#
directive|define
name|PPP_UI
value|0x03
end_define

begin_comment
comment|/* Unnumbered Information */
end_comment

begin_define
define|#
directive|define
name|PPP_FLAG
value|0x7e
end_define

begin_comment
comment|/* Flag Sequence */
end_comment

begin_define
define|#
directive|define
name|PPP_ESCAPE
value|0x7d
end_define

begin_comment
comment|/* Asynchronous Control Escape */
end_comment

begin_define
define|#
directive|define
name|PPP_TRANS
value|0x20
end_define

begin_comment
comment|/* Asynchronous transparency modifier */
end_comment

begin_comment
comment|/*  * Protocol field values.  */
end_comment

begin_define
define|#
directive|define
name|PPP_IP
value|0x21
end_define

begin_comment
comment|/* Internet Protocol */
end_comment

begin_define
define|#
directive|define
name|PPP_XNS
value|0x25
end_define

begin_comment
comment|/* Xerox NS */
end_comment

begin_define
define|#
directive|define
name|PPP_AT
value|0x29
end_define

begin_comment
comment|/* AppleTalk Protocol */
end_comment

begin_define
define|#
directive|define
name|PPP_IPX
value|0x2b
end_define

begin_comment
comment|/* IPX Datagram (RFC1552) */
end_comment

begin_define
define|#
directive|define
name|PPP_VJC_COMP
value|0x2d
end_define

begin_comment
comment|/* VJ compressed TCP */
end_comment

begin_define
define|#
directive|define
name|PPP_VJC_UNCOMP
value|0x2f
end_define

begin_comment
comment|/* VJ uncompressed TCP */
end_comment

begin_define
define|#
directive|define
name|PPP_COMP
value|0xfd
end_define

begin_comment
comment|/* compressed packet */
end_comment

begin_define
define|#
directive|define
name|PPP_IPCP
value|0x8021
end_define

begin_comment
comment|/* IP Control Protocol */
end_comment

begin_define
define|#
directive|define
name|PPP_ATCP
value|0x8029
end_define

begin_comment
comment|/* AppleTalk Control Protocol */
end_comment

begin_define
define|#
directive|define
name|PPP_IPXCP
value|0x802b
end_define

begin_comment
comment|/* IPX Control Protocol (RFC1552) */
end_comment

begin_define
define|#
directive|define
name|PPP_CCP
value|0x80fd
end_define

begin_comment
comment|/* Compression Control Protocol */
end_comment

begin_define
define|#
directive|define
name|PPP_LCP
value|0xc021
end_define

begin_comment
comment|/* Link Control Protocol */
end_comment

begin_define
define|#
directive|define
name|PPP_PAP
value|0xc023
end_define

begin_comment
comment|/* Password Authentication Protocol */
end_comment

begin_define
define|#
directive|define
name|PPP_LQR
value|0xc025
end_define

begin_comment
comment|/* Link Quality Report protocol */
end_comment

begin_define
define|#
directive|define
name|PPP_CHAP
value|0xc223
end_define

begin_comment
comment|/* Cryptographic Handshake Auth. Protocol */
end_comment

begin_define
define|#
directive|define
name|PPP_CBCP
value|0xc029
end_define

begin_comment
comment|/* Callback Control Protocol */
end_comment

begin_define
define|#
directive|define
name|PPP_IPV6
value|0x57
end_define

begin_comment
comment|/* Internet Protocol version 6*/
end_comment

begin_define
define|#
directive|define
name|PPP_IPV6CP
value|0x8057
end_define

begin_comment
comment|/* IPv6 Control Protocol */
end_comment

begin_comment
comment|/*  * Values for FCS calculations.  */
end_comment

begin_define
define|#
directive|define
name|PPP_INITFCS
value|0xffff
end_define

begin_comment
comment|/* Initial FCS value */
end_comment

begin_define
define|#
directive|define
name|PPP_GOODFCS
value|0xf0b8
end_define

begin_comment
comment|/* Good final FCS value */
end_comment

begin_define
define|#
directive|define
name|PPP_FCS
parameter_list|(
name|fcs
parameter_list|,
name|c
parameter_list|)
value|(((fcs)>> 8) ^ fcstab[((fcs) ^ (c))& 0xff])
end_define

begin_comment
comment|/*  * Extended asyncmap - allows any character to be escaped.  */
end_comment

begin_typedef
typedef|typedef
name|u_int32_t
name|ext_accm
index|[
literal|8
index|]
typedef|;
end_typedef

begin_comment
comment|/*  * What to do with network protocol (NP) packets.  */
end_comment

begin_enum
enum|enum
name|NPmode
block|{
name|NPMODE_PASS
block|,
comment|/* pass the packet through */
name|NPMODE_DROP
block|,
comment|/* silently drop the packet */
name|NPMODE_ERROR
block|,
comment|/* return an error */
name|NPMODE_QUEUE
comment|/* save it up for later. */
block|}
enum|;
end_enum

begin_comment
comment|/*  * Statistics.  */
end_comment

begin_struct
struct|struct
name|pppstat
block|{
name|unsigned
name|int
name|ppp_ibytes
decl_stmt|;
comment|/* bytes received */
name|unsigned
name|int
name|ppp_ipackets
decl_stmt|;
comment|/* packets received */
name|unsigned
name|int
name|ppp_ierrors
decl_stmt|;
comment|/* receive errors */
name|unsigned
name|int
name|ppp_obytes
decl_stmt|;
comment|/* bytes sent */
name|unsigned
name|int
name|ppp_opackets
decl_stmt|;
comment|/* packets sent */
name|unsigned
name|int
name|ppp_oerrors
decl_stmt|;
comment|/* transmit errors */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|vjstat
block|{
name|unsigned
name|int
name|vjs_packets
decl_stmt|;
comment|/* outbound packets */
name|unsigned
name|int
name|vjs_compressed
decl_stmt|;
comment|/* outbound compressed packets */
name|unsigned
name|int
name|vjs_searches
decl_stmt|;
comment|/* searches for connection state */
name|unsigned
name|int
name|vjs_misses
decl_stmt|;
comment|/* times couldn't find conn. state */
name|unsigned
name|int
name|vjs_uncompressedin
decl_stmt|;
comment|/* inbound uncompressed packets */
name|unsigned
name|int
name|vjs_compressedin
decl_stmt|;
comment|/* inbound compressed packets */
name|unsigned
name|int
name|vjs_errorin
decl_stmt|;
comment|/* inbound unknown type packets */
name|unsigned
name|int
name|vjs_tossed
decl_stmt|;
comment|/* inbound packets tossed because of error */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|ppp_stats
block|{
name|struct
name|pppstat
name|p
decl_stmt|;
comment|/* basic PPP statistics */
name|struct
name|vjstat
name|vj
decl_stmt|;
comment|/* VJ header compression statistics */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|compstat
block|{
name|unsigned
name|int
name|unc_bytes
decl_stmt|;
comment|/* total uncompressed bytes */
name|unsigned
name|int
name|unc_packets
decl_stmt|;
comment|/* total uncompressed packets */
name|unsigned
name|int
name|comp_bytes
decl_stmt|;
comment|/* compressed bytes */
name|unsigned
name|int
name|comp_packets
decl_stmt|;
comment|/* compressed packets */
name|unsigned
name|int
name|inc_bytes
decl_stmt|;
comment|/* incompressible bytes */
name|unsigned
name|int
name|inc_packets
decl_stmt|;
comment|/* incompressible packets */
name|unsigned
name|int
name|ratio
decl_stmt|;
comment|/* recent compression ratio<< 8 */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|ppp_comp_stats
block|{
name|struct
name|compstat
name|c
decl_stmt|;
comment|/* packet compression statistics */
name|struct
name|compstat
name|d
decl_stmt|;
comment|/* packet decompression statistics */
block|}
struct|;
end_struct

begin_comment
comment|/*  * The following structure records the time in seconds since  * the last NP packet was sent or received.  */
end_comment

begin_struct
struct|struct
name|ppp_idle
block|{
name|time_t
name|xmit_idle
decl_stmt|;
comment|/* time since last NP packet sent */
name|time_t
name|recv_idle
decl_stmt|;
comment|/* time since last NP packet received */
block|}
struct|;
end_struct

begin_ifndef
ifndef|#
directive|ifndef
name|__P
end_ifndef

begin_ifdef
ifdef|#
directive|ifdef
name|__STDC__
end_ifdef

begin_define
define|#
directive|define
name|__P
parameter_list|(
name|x
parameter_list|)
value|x
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|__P
parameter_list|(
name|x
parameter_list|)
value|()
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _PPP_DEFS_H_ */
end_comment

end_unit

