begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) University of British Columbia, 1984  * Copyright (c) 1990, 1992, 1993  *	The Regents of the University of California.  All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * the Laboratory for Computation Vision and the Computer Science Department  * of the University of British Columbia.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)pk.h	8.1 (Berkeley) 6/10/93  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_NETCCITT_PK_H_
end_ifndef

begin_define
define|#
directive|define
name|_NETCITT_PK_H_
end_define

begin_comment
comment|/*  *  *  X.25 Packet Level Definitions:  *  */
end_comment

begin_comment
comment|/* Packet type identifier field defintions. */
end_comment

begin_define
define|#
directive|define
name|X25_CALL
value|11
end_define

begin_define
define|#
directive|define
name|X25_CALL_ACCEPTED
value|15
end_define

begin_define
define|#
directive|define
name|X25_CLEAR
value|19
end_define

begin_define
define|#
directive|define
name|X25_CLEAR_CONFIRM
value|23
end_define

begin_define
define|#
directive|define
name|X25_DATA
value|0
end_define

begin_define
define|#
directive|define
name|X25_INTERRUPT
value|35
end_define

begin_define
define|#
directive|define
name|X25_INTERRUPT_CONFIRM
value|39
end_define

begin_define
define|#
directive|define
name|X25_RR
value|1
end_define

begin_define
define|#
directive|define
name|X25_RNR
value|5
end_define

begin_define
define|#
directive|define
name|X25_REJECT
value|9
end_define

begin_define
define|#
directive|define
name|X25_RESET
value|27
end_define

begin_define
define|#
directive|define
name|X25_RESET_CONFIRM
value|31
end_define

begin_define
define|#
directive|define
name|X25_DIAGNOSTIC
value|241
end_define

begin_define
define|#
directive|define
name|X25_RESTART
value|251
end_define

begin_define
define|#
directive|define
name|X25_RESTART_CONFIRM
value|255
end_define

begin_comment
comment|/* Restart cause field definitions. */
end_comment

begin_define
define|#
directive|define
name|X25_RESTART_DTE_ORIGINATED
value|0
end_define

begin_define
define|#
directive|define
name|X25_RESTART_LOCAL_PROCEDURE_ERROR
value|1
end_define

begin_define
define|#
directive|define
name|X25_RESTART_NETWORK_CONGESTION
value|3
end_define

begin_define
define|#
directive|define
name|X25_RESTART_NETWORK_OPERATIONAL
value|7
end_define

begin_define
define|#
directive|define
name|X25_RESTART_DTE_ORIGINATED2
value|128
end_define

begin_comment
comment|/* Miscellaneous definitions. */
end_comment

begin_define
define|#
directive|define
name|DATA_PACKET_DESIGNATOR
value|0x01
end_define

begin_define
define|#
directive|define
name|RR_OR_RNR_PACKET_DESIGNATOR
value|0x02
end_define

begin_define
define|#
directive|define
name|RR_PACKET_DESIGNATOR
value|0x04
end_define

begin_define
define|#
directive|define
name|DEFAULT_WINDOW_SIZE
value|2
end_define

begin_define
define|#
directive|define
name|MODULUS
value|8
end_define

begin_define
define|#
directive|define
name|ADDRLN
value|1
end_define

begin_define
define|#
directive|define
name|MAXADDRLN
value|15
end_define

begin_define
define|#
directive|define
name|FACILITIESLN
value|1
end_define

begin_define
define|#
directive|define
name|MAXFACILITIESLN
value|10
end_define

begin_define
define|#
directive|define
name|MAXUSERDATA
value|16
end_define

begin_define
define|#
directive|define
name|MAXCALLINFOLN
value|1+15+1+10+16
end_define

begin_define
define|#
directive|define
name|PACKET_OK
value|0
end_define

begin_define
define|#
directive|define
name|IGNORE_PACKET
value|1
end_define

begin_define
define|#
directive|define
name|ERROR_PACKET
value|2
end_define

begin_typedef
typedef|typedef
name|char
name|bool
typedef|;
end_typedef

begin_define
define|#
directive|define
name|FALSE
value|0
end_define

begin_define
define|#
directive|define
name|TRUE
value|1
end_define

begin_comment
comment|/*  *  X.25 Packet format definitions  *  This will eventually have to be rewritten without reference  *  to bit fields, to be ansi C compliant and allignment safe.  */
end_comment

begin_typedef
typedef|typedef
name|u_char
name|octet
typedef|;
end_typedef

begin_struct
struct|struct
name|x25_calladdr
block|{
name|octet
name|addrlens
decl_stmt|;
name|octet
name|address_field
index|[
name|MAXADDRLN
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|x25_packet
block|{
name|octet
name|bits
decl_stmt|;
name|octet
name|logical_channel_number
decl_stmt|;
name|octet
name|packet_type
decl_stmt|;
name|octet
name|packet_data
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|packet_cause
value|packet_data
end_define

begin_struct
struct|struct
name|data_packet
block|{
name|octet
name|bits
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|FACILITIES_REVERSE_CHARGE
value|0x1
end_define

begin_define
define|#
directive|define
name|FACILITIES_THROUGHPUT
value|0x2
end_define

begin_define
define|#
directive|define
name|FACILITIES_PACKETSIZE
value|0x42
end_define

begin_define
define|#
directive|define
name|FACILITIES_WINDOWSIZE
value|0x43
end_define

begin_define
define|#
directive|define
name|PKHEADERLN
value|3
end_define

begin_define
define|#
directive|define
name|DP
parameter_list|(
name|xp
parameter_list|)
value|(((struct data_packet *)&(xp) -> packet_type) -> bits)
end_define

begin_define
define|#
directive|define
name|PS
parameter_list|(
name|xp
parameter_list|)
value|X25GBITS(DP(xp), p_s)
end_define

begin_define
define|#
directive|define
name|PR
parameter_list|(
name|xp
parameter_list|)
value|X25GBITS(DP(xp), p_r)
end_define

begin_define
define|#
directive|define
name|MBIT
parameter_list|(
name|xp
parameter_list|)
value|X25GBITS(DP(xp), m_bit)
end_define

begin_define
define|#
directive|define
name|SPR
parameter_list|(
name|xp
parameter_list|,
name|v
parameter_list|)
value|X25SBITS(DP(xp), p_r, (v))
end_define

begin_define
define|#
directive|define
name|SPS
parameter_list|(
name|xp
parameter_list|,
name|v
parameter_list|)
value|X25SBITS(DP(xp), p_s, (v))
end_define

begin_define
define|#
directive|define
name|SMBIT
parameter_list|(
name|xp
parameter_list|,
name|v
parameter_list|)
value|X25SBITS(DP(xp), m_bit, (v))
end_define

begin_define
define|#
directive|define
name|LCN
parameter_list|(
name|xp
parameter_list|)
value|(xp -> logical_channel_number + \ 	(X25GBITS(xp -> bits, lc_group_number) ? (X25GBITS(xp -> bits, lc_group_number)<< 8) : 0))
end_define

begin_define
define|#
directive|define
name|SET_LCN
parameter_list|(
name|xp
parameter_list|,
name|lcn
parameter_list|)
value|((xp -> logical_channel_number = lcn), \ 	(X25SBITS(xp -> bits, lc_group_number, lcn> 255 ? lcn>> 8 : 0)))
end_define

begin_function_decl
name|struct
name|mbuf
modifier|*
name|pk_template
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* Define X.25 packet level states. */
end_comment

begin_comment
comment|/* Call setup and clearing substates.  */
end_comment

begin_define
define|#
directive|define
name|LISTEN
value|0
end_define

begin_define
define|#
directive|define
name|READY
value|1
end_define

begin_define
define|#
directive|define
name|RECEIVED_CALL
value|2
end_define

begin_define
define|#
directive|define
name|SENT_CALL
value|3
end_define

begin_define
define|#
directive|define
name|DATA_TRANSFER
value|4
end_define

begin_define
define|#
directive|define
name|RECEIVED_CLEAR
value|5
end_define

begin_define
define|#
directive|define
name|SENT_CLEAR
value|6
end_define

begin_comment
comment|/* DTE states. */
end_comment

begin_define
define|#
directive|define
name|DTE_WAITING
value|7
end_define

begin_define
define|#
directive|define
name|DTE_RECEIVED_RESTART
value|8
end_define

begin_define
define|#
directive|define
name|DTE_SENT_RESTART
value|9
end_define

begin_define
define|#
directive|define
name|DTE_READY
value|0
end_define

begin_comment
comment|/* Cleaning out ... */
end_comment

begin_define
define|#
directive|define
name|LCN_ZOMBIE
value|10
end_define

begin_define
define|#
directive|define
name|MAXSTATES
value|11
end_define

begin_comment
comment|/*  *  The following definitions are used in a switch statement after  *  determining the packet type.  These values are returned by the  *  pk_decode procedure.  */
end_comment

begin_define
define|#
directive|define
name|CALL
value|0 * MAXSTATES
end_define

begin_define
define|#
directive|define
name|CALL_ACCEPTED
value|1 * MAXSTATES
end_define

begin_define
define|#
directive|define
name|CLEAR
value|2 * MAXSTATES
end_define

begin_define
define|#
directive|define
name|CLEAR_CONF
value|3 * MAXSTATES
end_define

begin_define
define|#
directive|define
name|DATA
value|4 * MAXSTATES
end_define

begin_define
define|#
directive|define
name|INTERRUPT
value|5 * MAXSTATES
end_define

begin_define
define|#
directive|define
name|INTERRUPT_CONF
value|6 * MAXSTATES
end_define

begin_define
define|#
directive|define
name|RR
value|7 * MAXSTATES
end_define

begin_define
define|#
directive|define
name|RNR
value|8 * MAXSTATES
end_define

begin_define
define|#
directive|define
name|RESET
value|9 * MAXSTATES
end_define

begin_define
define|#
directive|define
name|RESET_CONF
value|10 * MAXSTATES
end_define

begin_define
define|#
directive|define
name|RESTART
value|11 * MAXSTATES
end_define

begin_define
define|#
directive|define
name|RESTART_CONF
value|12 * MAXSTATES
end_define

begin_define
define|#
directive|define
name|REJECT
value|13 * MAXSTATES
end_define

begin_define
define|#
directive|define
name|DIAG_TYPE
value|14 * MAXSTATES
end_define

begin_define
define|#
directive|define
name|INVALID_PACKET
value|15 * MAXSTATES
end_define

begin_define
define|#
directive|define
name|DELETE_PACKET
value|INVALID_PACKET
end_define

begin_comment
comment|/*  * The following definitions are used by the restart procedures  * for noting wether the PLE is supposed to behave as DTE or DCE  * (essentially necessary for operation over LLC2)  */
end_comment

begin_define
define|#
directive|define
name|DTE_DXERESOLVING
value|0x0001
end_define

begin_define
define|#
directive|define
name|DTE_PLAYDTE
value|0x0002
end_define

begin_define
define|#
directive|define
name|DTE_PLAYDCE
value|0x0004
end_define

begin_define
define|#
directive|define
name|DTE_CONNECTPENDING
value|0x0010
end_define

begin_define
define|#
directive|define
name|DTE_PRETENDDTE
value|0x0020
end_define

begin_define
define|#
directive|define
name|MAXRESTARTCOLLISIONS
value|10
end_define

begin_endif
endif|#
directive|endif
end_endif

end_unit

