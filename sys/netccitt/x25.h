begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) University of British Columbia, 1984  * Copyright (c) 1990, 1992, 1993  *	The Regents of the University of California.  All rights reserved.  * 		 University of Erlangen-Nuremberg, Germany, 1992  *  * This code is derived from software contributed to Berkeley by the  * Laboratory for Computation Vision and the Computer Science Department  * of the the University of British Columbia and the Computer Science  * Department (IV) of the University of Erlangen-Nuremberg, Germany.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)x25.h	8.1 (Berkeley) 6/10/93  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_NETCCITT_X25_H_
end_ifndef

begin_define
define|#
directive|define
name|_NETCCITT_X25_H_
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|KERNEL
end_ifdef

begin_define
define|#
directive|define
name|PRC_IFUP
value|3
end_define

begin_define
define|#
directive|define
name|PRC_LINKUP
value|4
end_define

begin_define
define|#
directive|define
name|PRC_LINKDOWN
value|5
end_define

begin_define
define|#
directive|define
name|PRC_LINKRESET
value|6
end_define

begin_define
define|#
directive|define
name|PRC_LINKDONTCOPY
value|7
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|PRC_DISCONNECT_REQUEST
end_ifndef

begin_define
define|#
directive|define
name|PRC_DISCONNECT_REQUEST
value|10
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|CCITTPROTO_HDLC
value|1
end_define

begin_define
define|#
directive|define
name|CCITTPROTO_X25
value|2
end_define

begin_comment
comment|/* packet level protocol */
end_comment

begin_define
define|#
directive|define
name|IEEEPROTO_802LLC
value|3
end_define

begin_comment
comment|/* doesn't belong here */
end_comment

begin_define
define|#
directive|define
name|HDLCPROTO_LAP
value|1
end_define

begin_define
define|#
directive|define
name|HDLCPROTO_LAPB
value|2
end_define

begin_define
define|#
directive|define
name|HDLCPROTO_UNSET
value|3
end_define

begin_define
define|#
directive|define
name|HDLCPROTO_LAPD
value|4
end_define

begin_comment
comment|/* socket options */
end_comment

begin_define
define|#
directive|define
name|PK_ACCTFILE
value|1
end_define

begin_comment
comment|/* use level = CCITTPROTO_X25 */
end_comment

begin_define
define|#
directive|define
name|PK_FACILITIES
value|2
end_define

begin_comment
comment|/* use level = CCITTPROTO_X25 */
end_comment

begin_define
define|#
directive|define
name|PK_RTATTACH
value|3
end_define

begin_comment
comment|/* use level = CCITTPROTO_X25 */
end_comment

begin_define
define|#
directive|define
name|PK_PRLISTEN
value|4
end_define

begin_comment
comment|/* use level = CCITTPROTO_X25 */
end_comment

begin_define
define|#
directive|define
name|MAX_FACILITIES
value|109
end_define

begin_comment
comment|/* maximum size for facilities */
end_comment

begin_comment
comment|/*  *  X.25 Socket address structure.  It contains the  X.121 or variation of  *  X.121, facilities information, higher level protocol value (first four  *  bytes of the User Data field), and the last  12 characters of the User  *  Data field.  */
end_comment

begin_struct
struct|struct
name|x25_sockaddr
block|{
comment|/* obsolete - use sockaddr_x25 */
name|short
name|xaddr_len
decl_stmt|;
comment|/* Length of xaddr_addr.		*/
name|u_char
name|xaddr_addr
index|[
literal|15
index|]
decl_stmt|;
comment|/* Network dependent or X.121 address.	*/
name|u_char
name|xaddr_facilities
decl_stmt|;
comment|/* Facilities information.		*/
define|#
directive|define
name|XS_REVERSE_CHARGE
value|0x01
define|#
directive|define
name|XS_HIPRIO
value|0x02
name|u_char
name|xaddr_proto
index|[
literal|4
index|]
decl_stmt|;
comment|/* Protocol ID (4 bytes of user data).	*/
name|u_char
name|xaddr_userdata
index|[
literal|12
index|]
decl_stmt|;
comment|/* Remaining User data field.		*/
block|}
struct|;
end_struct

begin_comment
comment|/*  *  X.25 Socket address structure.  It contains the network id, X.121  *  address, facilities information, higher level protocol value (first four  *  bytes of the User Data field), and up to 12 characters of User Data.  */
end_comment

begin_struct
struct|struct
name|sockaddr_x25
block|{
name|u_char
name|x25_len
decl_stmt|;
name|u_char
name|x25_family
decl_stmt|;
comment|/* must be AF_CCITT */
name|short
name|x25_net
decl_stmt|;
comment|/* network id code (usually a dnic) */
name|char
name|x25_addr
index|[
literal|16
index|]
decl_stmt|;
comment|/* X.121 address (null terminated) */
struct|struct
name|x25opts
block|{
name|char
name|op_flags
decl_stmt|;
comment|/* miscellaneous options */
comment|/* pk_var.h defines other lcd_flags */
define|#
directive|define
name|X25_REVERSE_CHARGE
value|0x01
comment|/* remote DTE pays for call */
define|#
directive|define
name|X25_DBIT
value|0x02
comment|/* not yet supported */
define|#
directive|define
name|X25_MQBIT
value|0x04
comment|/* prepend M&Q bit status byte to packet data */
define|#
directive|define
name|X25_OLDSOCKADDR
value|0x08
comment|/* uses old sockaddr structure */
define|#
directive|define
name|X25_DG_CIRCUIT
value|0x10
comment|/* lcd_flag: used for datagrams */
define|#
directive|define
name|X25_DG_ROUTING
value|0x20
comment|/* lcd_flag: peer addr not yet known */
define|#
directive|define
name|X25_MBS_HOLD
value|0x40
comment|/* lcd_flag: collect m-bit sequences */
name|char
name|op_psize
decl_stmt|;
comment|/* requested packet size */
define|#
directive|define
name|X25_PS128
value|7
define|#
directive|define
name|X25_PS256
value|8
define|#
directive|define
name|X25_PS512
value|9
name|char
name|op_wsize
decl_stmt|;
comment|/* window size (1 .. 7) */
name|char
name|op_speed
decl_stmt|;
comment|/* throughput class */
block|}
name|x25_opts
struct|;
name|short
name|x25_udlen
decl_stmt|;
comment|/* user data field length */
name|char
name|x25_udata
index|[
literal|16
index|]
decl_stmt|;
comment|/* user data field */
block|}
struct|;
end_struct

begin_comment
comment|/*  * network configuration info  * this structure must be 16 bytes long  */
end_comment

begin_struct
struct|struct
name|x25config
block|{
name|struct
name|sockaddr_x25
name|xc_addr
decl_stmt|;
comment|/* link level parameters */
name|u_short
name|xc_lproto
range|:
literal|4
decl_stmt|,
comment|/* link level protocol eg. CCITTPROTO_HDLC */
name|xc_lptype
range|:
literal|4
decl_stmt|,
comment|/* protocol type eg. HDLCPROTO_LAPB */
name|xc_ltrace
range|:
literal|1
decl_stmt|,
comment|/* link level tracing flag */
name|xc_lwsize
range|:
literal|7
decl_stmt|;
comment|/* link level window size */
name|u_short
name|xc_lxidxchg
range|:
literal|1
decl_stmt|,
comment|/* link level XID exchange flag - NOT YET */
comment|/* packet level parameters */
name|xc_rsvd1
range|:
literal|2
decl_stmt|,
name|xc_pwsize
range|:
literal|3
decl_stmt|,
comment|/* default window size */
name|xc_psize
range|:
literal|4
decl_stmt|,
comment|/* default packet size 7=128, 8=256, ... */
name|xc_type
range|:
literal|3
decl_stmt|,
comment|/* network type */
define|#
directive|define
name|X25_1976
value|0
define|#
directive|define
name|X25_1980
value|1
define|#
directive|define
name|X25_1984
value|2
define|#
directive|define
name|X25_DDN
value|3
define|#
directive|define
name|X25_BASIC
value|4
name|xc_ptrace
range|:
literal|1
decl_stmt|,
comment|/* packet level tracing flag */
name|xc_nodnic
range|:
literal|1
decl_stmt|,
comment|/* remove our dnic when calling on net */
name|xc_prepnd0
range|:
literal|1
decl_stmt|;
comment|/* prepend 0 when making offnet calls */
name|u_short
name|xc_maxlcn
decl_stmt|;
comment|/* max logical channels */
name|u_short
name|xc_dg_idletimo
decl_stmt|;
comment|/* timeout for idle datagram circuits. */
block|}
struct|;
end_struct

begin_ifdef
ifdef|#
directive|ifdef
name|IFNAMSIZ
end_ifdef

begin_struct
struct|struct
name|ifreq_x25
block|{
name|char
name|ifr_name
index|[
name|IFNAMSIZ
index|]
decl_stmt|;
comment|/* if name, e.g. "en0" */
name|struct
name|x25config
name|ifr_xc
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|SIOCSIFCONF_X25
value|_IOW('i', 12, struct ifreq_x25)
end_define

begin_comment
comment|/* set ifnet config */
end_comment

begin_define
define|#
directive|define
name|SIOCGIFCONF_X25
value|_IOWR('i',13, struct ifreq_x25)
end_define

begin_comment
comment|/* get ifnet config */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

end_unit

