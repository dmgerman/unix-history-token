begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1983, 1993  *	The Regents of the University of California.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)tftp.h	8.1 (Berkeley) 6/2/93  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_ARPA_TFTP_H_
end_ifndef

begin_define
define|#
directive|define
name|_ARPA_TFTP_H_
end_define

begin_comment
comment|/*  * Trivial File Transfer Protocol (IEN-133)  */
end_comment

begin_define
define|#
directive|define
name|SEGSIZE
value|512
end_define

begin_comment
comment|/* data segment size */
end_comment

begin_comment
comment|/*  * Packet types.  */
end_comment

begin_define
define|#
directive|define
name|RRQ
value|01
end_define

begin_comment
comment|/* read request */
end_comment

begin_define
define|#
directive|define
name|WRQ
value|02
end_define

begin_comment
comment|/* write request */
end_comment

begin_define
define|#
directive|define
name|DATA
value|03
end_define

begin_comment
comment|/* data packet */
end_comment

begin_define
define|#
directive|define
name|ACK
value|04
end_define

begin_comment
comment|/* acknowledgement */
end_comment

begin_define
define|#
directive|define
name|ERROR
value|05
end_define

begin_comment
comment|/* error code */
end_comment

begin_struct
struct|struct
name|tftphdr
block|{
name|unsigned
name|short
name|th_opcode
decl_stmt|;
comment|/* packet type */
union|union
block|{
name|unsigned
name|short
name|tu_block
decl_stmt|;
comment|/* block # */
name|unsigned
name|short
name|tu_code
decl_stmt|;
comment|/* error code */
name|char
name|tu_stuff
index|[
literal|1
index|]
decl_stmt|;
comment|/* request packet stuff */
block|}
name|th_u
union|;
name|char
name|th_data
index|[
literal|1
index|]
decl_stmt|;
comment|/* data or error string */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|th_block
value|th_u.tu_block
end_define

begin_define
define|#
directive|define
name|th_code
value|th_u.tu_code
end_define

begin_define
define|#
directive|define
name|th_stuff
value|th_u.tu_stuff
end_define

begin_define
define|#
directive|define
name|th_msg
value|th_data
end_define

begin_comment
comment|/*  * Error codes.  */
end_comment

begin_define
define|#
directive|define
name|EUNDEF
value|0
end_define

begin_comment
comment|/* not defined */
end_comment

begin_define
define|#
directive|define
name|ENOTFOUND
value|1
end_define

begin_comment
comment|/* file not found */
end_comment

begin_define
define|#
directive|define
name|EACCESS
value|2
end_define

begin_comment
comment|/* access violation */
end_comment

begin_define
define|#
directive|define
name|ENOSPACE
value|3
end_define

begin_comment
comment|/* disk full or allocation exceeded */
end_comment

begin_define
define|#
directive|define
name|EBADOP
value|4
end_define

begin_comment
comment|/* illegal TFTP operation */
end_comment

begin_define
define|#
directive|define
name|EBADID
value|5
end_define

begin_comment
comment|/* unknown transfer ID */
end_comment

begin_define
define|#
directive|define
name|EEXISTS
value|6
end_define

begin_comment
comment|/* file already exists */
end_comment

begin_define
define|#
directive|define
name|ENOUSER
value|7
end_define

begin_comment
comment|/* no such user */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_TFTP_H_ */
end_comment

end_unit

