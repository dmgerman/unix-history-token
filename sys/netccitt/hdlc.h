begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) University of British Columbia, 1984  * Copyright (c) 1991, 1993  *	The Regents of the University of California.  All rights reserved.  *  * This code is derived from software contributed to Berkeley by the  * Laboratory for Computation Vision and the Computer Science Department  * of the University of British Columbia.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)hdlc.h	8.1 (Berkeley) 6/10/93  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_NETCCITT_HDLC_H_
end_ifndef

begin_define
define|#
directive|define
name|_NETCCITT_HDLC_H_
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|ORDER4
end_ifndef

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

begin_typedef
typedef|typedef
name|u_char
name|octet
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|char
name|bool
typedef|;
end_typedef

begin_comment
comment|/*  *  HDLC Packet format definitions  *  This will eventually have to be rewritten without reference  *  to bit fields, to be compliant with ANSI C and alignment safe.  */
end_comment

begin_if
if|#
directive|if
name|BYTE_ORDER
operator|==
name|BIG_ENDIAN
end_if

begin_define
define|#
directive|define
name|ORDER4
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|,
name|c
parameter_list|,
name|d
parameter_list|)
value|a , b , c , d
end_define

begin_define
define|#
directive|define
name|ORDER5
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|,
name|c
parameter_list|,
name|d
parameter_list|,
name|e
parameter_list|)
value|a , b , c , d , e
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|BYTE_ORDER
operator|==
name|LITTLE_ENDIAN
end_if

begin_define
define|#
directive|define
name|ORDER4
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|,
name|c
parameter_list|,
name|d
parameter_list|)
value|d , c , b , a
end_define

begin_define
define|#
directive|define
name|ORDER5
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|,
name|c
parameter_list|,
name|d
parameter_list|,
name|e
parameter_list|)
value|e , d , c , b , a
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
name|MAX_INFO_LEN
value|4096+3+4
end_define

begin_define
define|#
directive|define
name|ADDRESS_A
value|3
end_define

begin_comment
comment|/* B'00000011' */
end_comment

begin_define
define|#
directive|define
name|ADDRESS_B
value|1
end_define

begin_comment
comment|/* B'00000001' */
end_comment

begin_struct
struct|struct
name|Hdlc_iframe
block|{
name|octet
name|address
decl_stmt|;
name|octet
name|ORDER4
argument_list|(
name|nr
operator|:
literal|3
argument_list|,
name|pf
operator|:
literal|1
argument_list|,
name|ns
operator|:
literal|3
argument_list|,
name|hdlc_0
operator|:
literal|1
argument_list|)
decl_stmt|;
name|octet
name|i_field
index|[
name|MAX_INFO_LEN
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|Hdlc_sframe
block|{
name|octet
name|address
decl_stmt|;
name|octet
name|ORDER4
argument_list|(
name|nr
operator|:
literal|3
argument_list|,
name|pf
operator|:
literal|1
argument_list|,
name|s2
operator|:
literal|2
argument_list|,
name|hdlc_01
operator|:
literal|2
argument_list|)
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|Hdlc_uframe
block|{
name|octet
name|address
decl_stmt|;
name|octet
name|ORDER4
argument_list|(
name|m3
operator|:
literal|3
argument_list|,
name|pf
operator|:
literal|1
argument_list|,
name|m2
operator|:
literal|2
argument_list|,
name|hdlc_11
operator|:
literal|2
argument_list|)
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|Frmr_frame
block|{
name|octet
name|address
decl_stmt|;
name|octet
name|control
decl_stmt|;
name|octet
name|frmr_control
decl_stmt|;
name|octet
name|ORDER4
argument_list|(
name|frmr_nr
operator|:
literal|3
argument_list|,
name|frmr_f1_0
operator|:
literal|1
argument_list|,
name|frmr_ns
operator|:
literal|3
argument_list|,
name|frmr_f2_0
operator|:
literal|1
argument_list|)
decl_stmt|;
name|octet
name|ORDER5
argument_list|(
name|frmr_0000
operator|:
literal|4
argument_list|,
name|frmr_z
operator|:
literal|1
argument_list|,
name|frmr_y
operator|:
literal|1
argument_list|,
name|frmr_x
operator|:
literal|1
argument_list|,
name|frmr_w
operator|:
literal|1
argument_list|)
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|HDHEADERLN
value|2
end_define

begin_define
define|#
directive|define
name|MINFRLN
value|2
end_define

begin_comment
comment|/* Minimum frame length. */
end_comment

begin_struct
struct|struct
name|Hdlc_frame
block|{
name|octet
name|address
decl_stmt|;
name|octet
name|control
decl_stmt|;
name|octet
name|info
index|[
literal|3
index|]
decl_stmt|;
comment|/* min for FRMR */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|SABM_CONTROL
value|057
end_define

begin_comment
comment|/* B'00101111' */
end_comment

begin_define
define|#
directive|define
name|UA_CONTROL
value|0143
end_define

begin_comment
comment|/* B'01100011' */
end_comment

begin_define
define|#
directive|define
name|DISC_CONTROL
value|0103
end_define

begin_comment
comment|/* B'01000011' */
end_comment

begin_define
define|#
directive|define
name|DM_CONTROL
value|017
end_define

begin_comment
comment|/* B'00001111' */
end_comment

begin_define
define|#
directive|define
name|FRMR_CONTROL
value|0207
end_define

begin_comment
comment|/* B'10000111' */
end_comment

begin_define
define|#
directive|define
name|RR_CONTROL
value|01
end_define

begin_comment
comment|/* B'00000001' */
end_comment

begin_define
define|#
directive|define
name|RNR_CONTROL
value|05
end_define

begin_comment
comment|/* B'00000101' */
end_comment

begin_define
define|#
directive|define
name|REJ_CONTROL
value|011
end_define

begin_comment
comment|/* B'00001001' */
end_comment

begin_define
define|#
directive|define
name|POLLOFF
value|0
end_define

begin_define
define|#
directive|define
name|POLLON
value|1
end_define

begin_comment
comment|/* Define Link State constants. */
end_comment

begin_define
define|#
directive|define
name|INIT
value|0
end_define

begin_define
define|#
directive|define
name|DM_SENT
value|1
end_define

begin_define
define|#
directive|define
name|SABM_SENT
value|2
end_define

begin_define
define|#
directive|define
name|ABM
value|3
end_define

begin_define
define|#
directive|define
name|WAIT_SABM
value|4
end_define

begin_define
define|#
directive|define
name|WAIT_UA
value|5
end_define

begin_define
define|#
directive|define
name|DISC_SENT
value|6
end_define

begin_define
define|#
directive|define
name|DISCONNECTED
value|7
end_define

begin_define
define|#
directive|define
name|MAXSTATE
value|8
end_define

begin_comment
comment|/* The following constants are used in a switch statement to process    frames read from the communications line. */
end_comment

begin_define
define|#
directive|define
name|SABM
value|0 * MAXSTATE
end_define

begin_define
define|#
directive|define
name|DM
value|1 * MAXSTATE
end_define

begin_define
define|#
directive|define
name|DISC
value|2 * MAXSTATE
end_define

begin_define
define|#
directive|define
name|UA
value|3 * MAXSTATE
end_define

begin_define
define|#
directive|define
name|FRMR
value|4 * MAXSTATE
end_define

begin_define
define|#
directive|define
name|RR
value|5 * MAXSTATE
end_define

begin_define
define|#
directive|define
name|RNR
value|6 * MAXSTATE
end_define

begin_define
define|#
directive|define
name|REJ
value|7 * MAXSTATE
end_define

begin_define
define|#
directive|define
name|IFRAME
value|8 * MAXSTATE
end_define

begin_define
define|#
directive|define
name|ILLEGAL
value|9 * MAXSTATE
end_define

begin_define
define|#
directive|define
name|T1
value|(3 * PR_SLOWHZ)
end_define

begin_comment
comment|/*  IFRAME TIMEOUT - 3 seconds */
end_comment

begin_define
define|#
directive|define
name|T3
value|(T1 / 2)
end_define

begin_comment
comment|/*  RR generate timeout - 1.5 seconds */
end_comment

begin_define
define|#
directive|define
name|N2
value|10
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
name|MAX_WINDOW_SIZE
value|7
end_define

begin_define
define|#
directive|define
name|Z
value|0
end_define

begin_define
define|#
directive|define
name|Y
value|1
end_define

begin_define
define|#
directive|define
name|X
value|2
end_define

begin_define
define|#
directive|define
name|W
value|3
end_define

begin_define
define|#
directive|define
name|A
value|4
end_define

begin_define
define|#
directive|define
name|TX
value|0
end_define

begin_define
define|#
directive|define
name|RX
value|1
end_define

begin_function_decl
name|bool
name|range_check
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|bool
name|valid_nr
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|mbuf
modifier|*
name|hd_remove
parameter_list|()
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

end_unit

