begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1996-2000  * University of Southern California/Information Sciences Institute.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. Neither the name of the project nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE PROJECT AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE PROJECT OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_NETINET_PIM_H_
end_ifndef

begin_define
define|#
directive|define
name|_NETINET_PIM_H_
end_define

begin_comment
comment|/*  * Protocol Independent Multicast (PIM) definitions.  * RFC 2362, June 1998.  *  * Written by Ahmed Helmy, USC/SGI, July 1996.  * Modified by George Edmond Eddy (Rusty), ISI, February 1998.  * Modified by Pavlin Radoslavov, USC/ISI, May 1998, October 2000.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_PIM_VT
end_ifndef

begin_ifndef
ifndef|#
directive|ifndef
name|BYTE_ORDER
end_ifndef

begin_error
error|#
directive|error
error|BYTE_ORDER is not defined!
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
operator|(
name|BYTE_ORDER
operator|!=
name|BIG_ENDIAN
operator|)
operator|&&
operator|(
name|BYTE_ORDER
operator|!=
name|LITTLE_ENDIAN
operator|)
end_if

begin_error
error|#
directive|error
error|BYTE_ORDER must be defined to either BIG_ENDIAN or LITTLE_ENDIAN
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! _PIM_VT */
end_comment

begin_comment
comment|/*  * PIM packet header  */
end_comment

begin_struct
struct|struct
name|pim
block|{
ifdef|#
directive|ifdef
name|_PIM_VT
name|uint8_t
name|pim_vt
decl_stmt|;
comment|/* PIM version and message type	*/
else|#
directive|else
comment|/* ! _PIM_VT   */
if|#
directive|if
name|BYTE_ORDER
operator|==
name|BIG_ENDIAN
name|u_int
name|pim_vers
range|:
literal|4
decl_stmt|,
comment|/* PIM protocol version		*/
name|pim_type
range|:
literal|4
decl_stmt|;
comment|/* PIM message type		*/
endif|#
directive|endif
if|#
directive|if
name|BYTE_ORDER
operator|==
name|LITTLE_ENDIAN
name|u_int
name|pim_type
range|:
literal|4
decl_stmt|,
comment|/* PIM message type		*/
name|pim_vers
range|:
literal|4
decl_stmt|;
comment|/* PIM protocol version		*/
endif|#
directive|endif
endif|#
directive|endif
comment|/* ! _PIM_VT  */
name|uint8_t
name|pim_reserved
decl_stmt|;
comment|/* Reserved			*/
name|uint16_t
name|pim_cksum
decl_stmt|;
comment|/* IP-style checksum		*/
block|}
struct|;
end_struct

begin_comment
comment|/* KAME-related name backward compatibility */
end_comment

begin_define
define|#
directive|define
name|pim_ver
value|pim_vers
end_define

begin_define
define|#
directive|define
name|pim_rsv
value|pim_reserved
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|_PIM_VT
end_ifdef

begin_define
define|#
directive|define
name|PIM_MAKE_VT
parameter_list|(
name|v
parameter_list|,
name|t
parameter_list|)
value|(0xff& (((v)<< 4) | (0x0f& (t))))
end_define

begin_define
define|#
directive|define
name|PIM_VT_V
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 4)& 0x0f)
end_define

begin_define
define|#
directive|define
name|PIM_VT_T
parameter_list|(
name|x
parameter_list|)
value|((x)& 0x0f)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _PIM_VT */
end_comment

begin_define
define|#
directive|define
name|PIM_VERSION
value|2
end_define

begin_define
define|#
directive|define
name|PIM_MINLEN
value|8
end_define

begin_comment
comment|/* PIM message min. length	*/
end_comment

begin_define
define|#
directive|define
name|PIM_REG_MINLEN
value|(PIM_MINLEN+20)
end_define

begin_comment
comment|/* PIM Register hdr + inner IPv4 hdr */
end_comment

begin_define
define|#
directive|define
name|PIM6_REG_MINLEN
value|(PIM_MINLEN+40)
end_define

begin_comment
comment|/* PIM Register hdr + inner IPv6 hdr */
end_comment

begin_comment
comment|/*  * PIM message types  */
end_comment

begin_define
define|#
directive|define
name|PIM_HELLO
value|0x0
end_define

begin_comment
comment|/* PIM-SM and PIM-DM		*/
end_comment

begin_define
define|#
directive|define
name|PIM_REGISTER
value|0x1
end_define

begin_comment
comment|/* PIM-SM only			*/
end_comment

begin_define
define|#
directive|define
name|PIM_REGISTER_STOP
value|0x2
end_define

begin_comment
comment|/* PIM-SM only			*/
end_comment

begin_define
define|#
directive|define
name|PIM_JOIN_PRUNE
value|0x3
end_define

begin_comment
comment|/* PIM-SM and PIM-DM		*/
end_comment

begin_define
define|#
directive|define
name|PIM_BOOTSTRAP
value|0x4
end_define

begin_comment
comment|/* PIM-SM only			*/
end_comment

begin_define
define|#
directive|define
name|PIM_ASSERT
value|0x5
end_define

begin_comment
comment|/* PIM-SM and PIM-DM		*/
end_comment

begin_define
define|#
directive|define
name|PIM_GRAFT
value|0x6
end_define

begin_comment
comment|/* PIM-DM only			*/
end_comment

begin_define
define|#
directive|define
name|PIM_GRAFT_ACK
value|0x7
end_define

begin_comment
comment|/* PIM-DM only			*/
end_comment

begin_define
define|#
directive|define
name|PIM_CAND_RP_ADV
value|0x8
end_define

begin_comment
comment|/* PIM-SM only			*/
end_comment

begin_define
define|#
directive|define
name|PIM_ALL_DF_ELECTION
value|0xa
end_define

begin_comment
comment|/* Bidir-PIM-SM only		*/
end_comment

begin_comment
comment|/*  * PIM-Register message flags  */
end_comment

begin_define
define|#
directive|define
name|PIM_BORDER_REGISTER
value|0x80000000U
end_define

begin_comment
comment|/* The Border bit (host-order)	*/
end_comment

begin_define
define|#
directive|define
name|PIM_NULL_REGISTER
value|0x40000000U
end_define

begin_comment
comment|/* The Null-Register bit (host-order)*/
end_comment

begin_comment
comment|/*  * All-PIM-Routers IPv4 and IPv6 multicast addresses  */
end_comment

begin_define
define|#
directive|define
name|INADDR_ALLPIM_ROUTERS_GROUP
value|(uint32_t)0xe000000dU
end_define

begin_comment
comment|/* 224.0.0.13 */
end_comment

begin_define
define|#
directive|define
name|IN6ADDR_LINKLOCAL_ALLPIM_ROUTERS
value|"ff02::d"
end_define

begin_define
define|#
directive|define
name|IN6ADDR_LINKLOCAL_ALLPIM_ROUTERS_INIT
define|\
value|{{{ 0xff, 0x02, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,		\ 	    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0d }}}
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _NETINET_PIM_H_ */
end_comment

end_unit

