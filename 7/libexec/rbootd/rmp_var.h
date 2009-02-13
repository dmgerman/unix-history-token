begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1988, 1992 The University of Utah and the Center  *	for Software Science (CSS).  * Copyright (c) 1992, 1993  *	The Regents of the University of California.  All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * the Center for Software Science of the University of Utah Computer  * Science Department.  CSS requests users of this software to return  * to css-dist@cs.utah.edu any improvements that they make and grant  * CSS redistribution rights.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	from: @(#)rmp_var.h	8.1 (Berkeley) 6/4/93  *  * from: Utah Hdr: rmp_var.h 3.1 92/07/06  * Author: Jeff Forys, University of Utah CSS  */
end_comment

begin_comment
comment|/*  *  Possible values for "rmp_type" fields.  */
end_comment

begin_define
define|#
directive|define
name|RMP_BOOT_REQ
value|1
end_define

begin_comment
comment|/* boot request packet */
end_comment

begin_define
define|#
directive|define
name|RMP_BOOT_REPL
value|129
end_define

begin_comment
comment|/* boot reply packet */
end_comment

begin_define
define|#
directive|define
name|RMP_READ_REQ
value|2
end_define

begin_comment
comment|/* read request packet */
end_comment

begin_define
define|#
directive|define
name|RMP_READ_REPL
value|130
end_define

begin_comment
comment|/* read reply packet */
end_comment

begin_define
define|#
directive|define
name|RMP_BOOT_DONE
value|3
end_define

begin_comment
comment|/* boot complete packet */
end_comment

begin_comment
comment|/*  *  Useful constants.  */
end_comment

begin_define
define|#
directive|define
name|RMP_VERSION
value|2
end_define

begin_comment
comment|/* protocol version */
end_comment

begin_define
define|#
directive|define
name|RMP_TIMEOUT
value|600
end_define

begin_comment
comment|/* timeout connection after ten minutes */
end_comment

begin_define
define|#
directive|define
name|RMP_PROBESID
value|0xffff
end_define

begin_comment
comment|/* session ID for probes */
end_comment

begin_define
define|#
directive|define
name|RMP_HOSTLEN
value|13
end_define

begin_comment
comment|/* max length of server's name */
end_comment

begin_define
define|#
directive|define
name|RMP_MACHLEN
value|20
end_define

begin_comment
comment|/* length of machine type field */
end_comment

begin_comment
comment|/*  *  RMP error codes  */
end_comment

begin_define
define|#
directive|define
name|RMP_E_OKAY
value|0
end_define

begin_define
define|#
directive|define
name|RMP_E_EOF
value|2
end_define

begin_comment
comment|/* read reply: returned end of file */
end_comment

begin_define
define|#
directive|define
name|RMP_E_ABORT
value|3
end_define

begin_comment
comment|/* abort operation */
end_comment

begin_define
define|#
directive|define
name|RMP_E_BUSY
value|4
end_define

begin_comment
comment|/* boot reply: server busy */
end_comment

begin_define
define|#
directive|define
name|RMP_E_TIMEOUT
value|5
end_define

begin_comment
comment|/* lengthen time out (not implemented) */
end_comment

begin_define
define|#
directive|define
name|RMP_E_NOFILE
value|16
end_define

begin_comment
comment|/* boot reply: file does not exist */
end_comment

begin_define
define|#
directive|define
name|RMP_E_OPENFILE
value|17
end_define

begin_comment
comment|/* boot reply: file open failed */
end_comment

begin_define
define|#
directive|define
name|RMP_E_NODFLT
value|18
end_define

begin_comment
comment|/* boot reply: default file does not exist */
end_comment

begin_define
define|#
directive|define
name|RMP_E_OPENDFLT
value|19
end_define

begin_comment
comment|/* boot reply: default file open failed */
end_comment

begin_define
define|#
directive|define
name|RMP_E_BADSID
value|25
end_define

begin_comment
comment|/* read reply: bad session ID */
end_comment

begin_define
define|#
directive|define
name|RMP_E_BADPACKET
value|27
end_define

begin_comment
comment|/* Bad packet detected */
end_comment

begin_comment
comment|/*  *  RMPDATALEN is the maximum number of data octets that can be stuffed  *  into an RMP packet.  This excludes the 802.2 LLC w/HP extensions.  */
end_comment

begin_define
define|#
directive|define
name|RMPDATALEN
value|(RMP_MAX_PACKET - (sizeof(struct hp_hdr) + \ 			                   sizeof(struct hp_llc)))
end_define

begin_comment
comment|/*  *  Define sizes of packets we send.  Boot and Read replies are variable  *  in length depending on the length of `s'.  *  *  Also, define how much space `restofpkt' can take up for outgoing  *  Boot and Read replies.  Boot Request packets are effectively  *  limited to 255 bytes due to the preceding 1-byte length field.  */
end_comment

begin_define
define|#
directive|define
name|RMPBOOTSIZE
parameter_list|(
name|s
parameter_list|)
value|(sizeof(struct hp_hdr) + sizeof(struct hp_llc) + \ 			 sizeof(struct rmp_boot_repl) + s - sizeof(restofpkt))
end_define

begin_define
define|#
directive|define
name|RMPREADSIZE
parameter_list|(
name|s
parameter_list|)
value|(sizeof(struct hp_hdr) + sizeof(struct hp_llc) + \ 			 sizeof(struct rmp_read_repl) + s - sizeof(restofpkt) \ 			 - sizeof(u_int8_t))
end_define

begin_define
define|#
directive|define
name|RMPDONESIZE
value|(sizeof(struct hp_hdr) + sizeof(struct hp_llc) + \ 			 sizeof(struct rmp_boot_done))
end_define

begin_define
define|#
directive|define
name|RMPBOOTDATA
value|255
end_define

begin_define
define|#
directive|define
name|RMPREADDATA
value|(RMPDATALEN - \ 			 (2*sizeof(u_int8_t)+sizeof(u_int16_t)+sizeof(u_word)))
end_define

begin_comment
comment|/*  * This protocol defines some field sizes as "rest of ethernet packet".  * There is no easy way to specify this in C, so we use a one character  * field to denote it, and index past it to the end of the packet.  */
end_comment

begin_typedef
typedef|typedef
name|char
name|restofpkt
typedef|;
end_typedef

begin_comment
comment|/*  * Due to the RMP packet layout, we'll run into alignment problems  * on machines that can't access (or don't, by default, align) words  * on half-word boundaries.  If you know that your machine does not suffer  * from this problem, add it to the vax/tahoe/m68k #define below.  *  * The following macros are used to deal with this problem:  *	WORDZE(w)	Return True if u_word `w' is zero, False otherwise.  *	ZEROWORD(w)	Set u_word `w' to zero.  *	COPYWORD(w1,w2)	Copy u_word `w1' to `w2'.  *	GETWORD(w,i)	Copy u_word `w' into int `i'.  *	PUTWORD(i,w)	Copy int `i' into u_word `w'.  *  * N.B. Endianness is handled by use of ntohl/htonl  */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__vax__
argument_list|)
operator|||
name|defined
argument_list|(
name|__tahoe__
argument_list|)
operator|||
name|defined
argument_list|(
name|__m68k__
argument_list|)
end_if

begin_typedef
typedef|typedef
name|u_int32_t
name|u_word
typedef|;
end_typedef

begin_define
define|#
directive|define
name|WORDZE
parameter_list|(
name|w
parameter_list|)
value|((w) == 0)
end_define

begin_define
define|#
directive|define
name|ZEROWORD
parameter_list|(
name|w
parameter_list|)
value|(w) = 0
end_define

begin_define
define|#
directive|define
name|COPYWORD
parameter_list|(
name|w1
parameter_list|,
name|w2
parameter_list|)
value|(w2) = (w1)
end_define

begin_define
define|#
directive|define
name|GETWORD
parameter_list|(
name|w
parameter_list|,
name|i
parameter_list|)
value|(i) = ntohl(w)
end_define

begin_define
define|#
directive|define
name|PUTWORD
parameter_list|(
name|i
parameter_list|,
name|w
parameter_list|)
value|(w) = htonl(i)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|_WORD_HIGHPART
value|0
end_define

begin_define
define|#
directive|define
name|_WORD_LOWPART
value|1
end_define

begin_typedef
typedef|typedef
struct|struct
name|_uword
block|{
name|u_int16_t
name|val
index|[
literal|2
index|]
decl_stmt|;
block|}
name|u_word
typedef|;
end_typedef

begin_define
define|#
directive|define
name|WORDZE
parameter_list|(
name|w
parameter_list|)
define|\
value|((w.val[_WORD_HIGHPART] == 0)&& (w.val[_WORD_LOWPART] == 0))
end_define

begin_define
define|#
directive|define
name|ZEROWORD
parameter_list|(
name|w
parameter_list|)
define|\
value|(w).val[_WORD_HIGHPART] = (w).val[_WORD_LOWPART] = 0
end_define

begin_define
define|#
directive|define
name|COPYWORD
parameter_list|(
name|w1
parameter_list|,
name|w2
parameter_list|)
define|\
value|{ (w2).val[_WORD_HIGHPART] = (w1).val[_WORD_HIGHPART]; \ 	  (w2).val[_WORD_LOWPART] = (w1).val[_WORD_LOWPART]; \ 	}
end_define

begin_define
define|#
directive|define
name|GETWORD
parameter_list|(
name|w
parameter_list|,
name|i
parameter_list|)
define|\
value|(i) = (((u_int32_t)ntohs((w).val[_WORD_HIGHPART]))<< 16) | ntohs((w).val[_WORD_LOWPART])
end_define

begin_define
define|#
directive|define
name|PUTWORD
parameter_list|(
name|i
parameter_list|,
name|w
parameter_list|)
define|\
value|{ (w).val[_WORD_HIGHPART] = htons((u_int16_t) ((i>> 16)& 0xffff)); \ 	  (w).val[_WORD_LOWPART] = htons((u_int16_t) (i& 0xffff)); \ 	}
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * Packet structures.  */
end_comment

begin_struct
struct|struct
name|rmp_raw
block|{
comment|/* generic RMP packet */
name|u_int8_t
name|rmp_type
decl_stmt|;
comment|/* packet type */
name|u_int8_t
name|rmp_rawdata
index|[
name|RMPDATALEN
operator|-
literal|1
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|rmp_boot_req
block|{
comment|/* boot request */
name|u_int8_t
name|rmp_type
decl_stmt|;
comment|/* packet type (RMP_BOOT_REQ) */
name|u_int8_t
name|rmp_retcode
decl_stmt|;
comment|/* return code (0) */
name|u_word
name|rmp_seqno
decl_stmt|;
comment|/* sequence number (real time clock) */
name|u_int16_t
name|rmp_session
decl_stmt|;
comment|/* session id (normally 0) */
name|u_int16_t
name|rmp_version
decl_stmt|;
comment|/* protocol version (RMP_VERSION) */
name|char
name|rmp_machtype
index|[
name|RMP_MACHLEN
index|]
decl_stmt|;
comment|/* machine type */
name|u_int8_t
name|rmp_flnmsize
decl_stmt|;
comment|/* length of rmp_flnm */
name|restofpkt
name|rmp_flnm
decl_stmt|;
comment|/* name of file to be read */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|rmp_boot_repl
block|{
comment|/* boot reply */
name|u_int8_t
name|rmp_type
decl_stmt|;
comment|/* packet type (RMP_BOOT_REPL) */
name|u_int8_t
name|rmp_retcode
decl_stmt|;
comment|/* return code (normally 0) */
name|u_word
name|rmp_seqno
decl_stmt|;
comment|/* sequence number (from boot req) */
name|u_int16_t
name|rmp_session
decl_stmt|;
comment|/* session id (generated) */
name|u_int16_t
name|rmp_version
decl_stmt|;
comment|/* protocol version (RMP_VERSION) */
name|u_int8_t
name|rmp_flnmsize
decl_stmt|;
comment|/* length of rmp_flnm */
name|restofpkt
name|rmp_flnm
decl_stmt|;
comment|/* name of file (from boot req) */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|rmp_read_req
block|{
comment|/* read request */
name|u_int8_t
name|rmp_type
decl_stmt|;
comment|/* packet type (RMP_READ_REQ) */
name|u_int8_t
name|rmp_retcode
decl_stmt|;
comment|/* return code (0) */
name|u_word
name|rmp_offset
decl_stmt|;
comment|/* file relative byte offset */
name|u_int16_t
name|rmp_session
decl_stmt|;
comment|/* session id (from boot repl) */
name|u_int16_t
name|rmp_size
decl_stmt|;
comment|/* max no of bytes to send */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|rmp_read_repl
block|{
comment|/* read reply */
name|u_int8_t
name|rmp_type
decl_stmt|;
comment|/* packet type (RMP_READ_REPL) */
name|u_int8_t
name|rmp_retcode
decl_stmt|;
comment|/* return code (normally 0) */
name|u_word
name|rmp_offset
decl_stmt|;
comment|/* byte offset (from read req) */
name|u_int16_t
name|rmp_session
decl_stmt|;
comment|/* session id (from read req) */
name|restofpkt
name|rmp_data
decl_stmt|;
comment|/* data (max size from read req) */
name|u_int8_t
name|rmp_unused
decl_stmt|;
comment|/* padding to 16-bit boundary */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|rmp_boot_done
block|{
comment|/* boot complete */
name|u_int8_t
name|rmp_type
decl_stmt|;
comment|/* packet type (RMP_BOOT_DONE) */
name|u_int8_t
name|rmp_retcode
decl_stmt|;
comment|/* return code (0) */
name|u_word
name|rmp_unused
decl_stmt|;
comment|/* not used (0) */
name|u_int16_t
name|rmp_session
decl_stmt|;
comment|/* session id (from read repl) */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|rmp_packet
block|{
name|struct
name|hp_hdr
name|hp_hdr
decl_stmt|;
name|struct
name|hp_llc
name|hp_llc
decl_stmt|;
union|union
block|{
name|struct
name|rmp_boot_req
name|rmp_brq
decl_stmt|;
comment|/* boot request */
name|struct
name|rmp_boot_repl
name|rmp_brpl
decl_stmt|;
comment|/* boot reply */
name|struct
name|rmp_read_req
name|rmp_rrq
decl_stmt|;
comment|/* read request */
name|struct
name|rmp_read_repl
name|rmp_rrpl
decl_stmt|;
comment|/* read reply */
name|struct
name|rmp_boot_done
name|rmp_done
decl_stmt|;
comment|/* boot complete */
name|struct
name|rmp_raw
name|rmp_raw
decl_stmt|;
comment|/* raw data */
block|}
name|rmp_proto
union|;
block|}
struct|;
end_struct

begin_comment
comment|/*  *  Make life easier...  */
end_comment

begin_define
define|#
directive|define
name|r_type
value|rmp_proto.rmp_raw.rmp_type
end_define

begin_define
define|#
directive|define
name|r_data
value|rmp_proto.rmp_raw.rmp_rawdata
end_define

begin_define
define|#
directive|define
name|r_brq
value|rmp_proto.rmp_brq
end_define

begin_define
define|#
directive|define
name|r_brpl
value|rmp_proto.rmp_brpl
end_define

begin_define
define|#
directive|define
name|r_rrq
value|rmp_proto.rmp_rrq
end_define

begin_define
define|#
directive|define
name|r_rrpl
value|rmp_proto.rmp_rrpl
end_define

begin_define
define|#
directive|define
name|r_done
value|rmp_proto.rmp_done
end_define

end_unit

