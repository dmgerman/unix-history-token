begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1998 Mark Newton  * Copyright (c) 1994 Christos Zoulas  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. The name of the author may not be used to endorse or promote products  *    derived from this software without specific prior written permission  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *   * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_SVR4_STROPTS_H_
end_ifndef

begin_define
define|#
directive|define
name|_SVR4_STROPTS_H_
end_define

begin_struct
struct|struct
name|svr4_strbuf
block|{
name|int
name|maxlen
decl_stmt|;
name|int
name|len
decl_stmt|;
name|char
modifier|*
name|buf
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|SVR4_STR
value|('S'<< 8)
end_define

begin_define
define|#
directive|define
name|SVR4_I_NREAD
value|(SVR4_STR| 1)
end_define

begin_define
define|#
directive|define
name|SVR4_I_PUSH
value|(SVR4_STR| 2)
end_define

begin_define
define|#
directive|define
name|SVR4_I_POP
value|(SVR4_STR| 3)
end_define

begin_define
define|#
directive|define
name|SVR4_I_LOOK
value|(SVR4_STR| 4)
end_define

begin_define
define|#
directive|define
name|SVR4_I_FLUSH
value|(SVR4_STR| 5)
end_define

begin_define
define|#
directive|define
name|SVR4_I_SRDOPT
value|(SVR4_STR| 6)
end_define

begin_define
define|#
directive|define
name|SVR4_I_GRDOPT
value|(SVR4_STR| 7)
end_define

begin_define
define|#
directive|define
name|SVR4_I_STR
value|(SVR4_STR| 8)
end_define

begin_define
define|#
directive|define
name|SVR4_I_SETSIG
value|(SVR4_STR| 9)
end_define

begin_define
define|#
directive|define
name|SVR4_I_GETSIG
value|(SVR4_STR|10)
end_define

begin_define
define|#
directive|define
name|SVR4_I_FIND
value|(SVR4_STR|11)
end_define

begin_define
define|#
directive|define
name|SVR4_I_LINK
value|(SVR4_STR|12)
end_define

begin_define
define|#
directive|define
name|SVR4_I_UNLINK
value|(SVR4_STR|13)
end_define

begin_define
define|#
directive|define
name|SVR4_I_ERECVFD
value|(SVR4_STR|14)
end_define

begin_define
define|#
directive|define
name|SVR4_I_PEEK
value|(SVR4_STR|15)
end_define

begin_define
define|#
directive|define
name|SVR4_I_FDINSERT
value|(SVR4_STR|16)
end_define

begin_define
define|#
directive|define
name|SVR4_I_SENDFD
value|(SVR4_STR|17)
end_define

begin_define
define|#
directive|define
name|SVR4_I_RECVFD
value|(SVR4_STR|18)
end_define

begin_define
define|#
directive|define
name|SVR4_I_SWROPT
value|(SVR4_STR|19)
end_define

begin_define
define|#
directive|define
name|SVR4_I_GWROPT
value|(SVR4_STR|20)
end_define

begin_define
define|#
directive|define
name|SVR4_I_LIST
value|(SVR4_STR|21)
end_define

begin_define
define|#
directive|define
name|SVR4_I_PLINK
value|(SVR4_STR|22)
end_define

begin_define
define|#
directive|define
name|SVR4_I_PUNLINK
value|(SVR4_STR|23)
end_define

begin_define
define|#
directive|define
name|SVR4_I_SETEV
value|(SVR4_STR|24)
end_define

begin_define
define|#
directive|define
name|SVR4_I_GETEV
value|(SVR4_STR|25)
end_define

begin_define
define|#
directive|define
name|SVR4_I_STREV
value|(SVR4_STR|26)
end_define

begin_define
define|#
directive|define
name|SVR4_I_UNSTREV
value|(SVR4_STR|27)
end_define

begin_define
define|#
directive|define
name|SVR4_I_FLUSHBAND
value|(SVR4_STR|28)
end_define

begin_define
define|#
directive|define
name|SVR4_I_CKBAND
value|(SVR4_STR|29)
end_define

begin_define
define|#
directive|define
name|SVR4_I_GETBAND
value|(SVR4_STR|30)
end_define

begin_define
define|#
directive|define
name|SVR4_I_ATMARK
value|(SVR4_STR|31)
end_define

begin_define
define|#
directive|define
name|SVR4_I_SETCLTIME
value|(SVR4_STR|32)
end_define

begin_define
define|#
directive|define
name|SVR4_I_GETCLTIME
value|(SVR4_STR|33)
end_define

begin_define
define|#
directive|define
name|SVR4_I_CANPUT
value|(SVR4_STR|34)
end_define

begin_comment
comment|/*  * The following two ioctls are OS specific and  * undocumented.  */
end_comment

begin_define
define|#
directive|define
name|SVR4__I_BIND_RSVD
value|(SVR4_STR|242)
end_define

begin_define
define|#
directive|define
name|SVR4__I_RELE_RSVD
value|(SVR4_STR|243)
end_define

begin_comment
comment|/*  * Service type definitions  */
end_comment

begin_define
define|#
directive|define
name|SVR4_T_COTS
value|1
end_define

begin_comment
comment|/* Connection-orieted */
end_comment

begin_define
define|#
directive|define
name|SVR4_T_COTS_ORD
value|2
end_define

begin_comment
comment|/* Local connection-oriented */
end_comment

begin_define
define|#
directive|define
name|SVR4_T_CLTS
value|3
end_define

begin_comment
comment|/* Connectionless */
end_comment

begin_comment
comment|/* Struct passed for SVR4_I_STR */
end_comment

begin_struct
struct|struct
name|svr4_strioctl
block|{
name|u_long
name|cmd
decl_stmt|;
name|int
name|timeout
decl_stmt|;
name|int
name|len
decl_stmt|;
name|char
modifier|*
name|buf
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * Bits for I_{G,S}ETSIG  */
end_comment

begin_define
define|#
directive|define
name|SVR4_S_INPUT
value|0x0001
end_define

begin_comment
comment|/* any message on read queue no HIPRI */
end_comment

begin_define
define|#
directive|define
name|SVR4_S_HIPRI
value|0x0002
end_define

begin_comment
comment|/* high prio message on read queue */
end_comment

begin_define
define|#
directive|define
name|SVR4_S_OUTPUT
value|0x0004
end_define

begin_comment
comment|/* write queue has free space */
end_comment

begin_define
define|#
directive|define
name|SVR4_S_MSG
value|0x0008
end_define

begin_comment
comment|/* signal message in read queue head */
end_comment

begin_define
define|#
directive|define
name|SVR4_S_ERROR
value|0x0010
end_define

begin_comment
comment|/* error message in read queue head */
end_comment

begin_define
define|#
directive|define
name|SVR4_S_HANGUP
value|0x0020
end_define

begin_comment
comment|/* hangup message in read queue head */
end_comment

begin_define
define|#
directive|define
name|SVR4_S_RDNORM
value|0x0040
end_define

begin_comment
comment|/* normal message on read queue */
end_comment

begin_define
define|#
directive|define
name|SVR4_S_WRNORM
value|S_OUTPUT
end_define

begin_comment
comment|/* write queue has free space */
end_comment

begin_define
define|#
directive|define
name|SVR4_S_RDBAND
value|0x0080
end_define

begin_comment
comment|/* out of band message on read queue */
end_comment

begin_define
define|#
directive|define
name|SVR4_S_WRBAND
value|0x0100
end_define

begin_comment
comment|/* write queue has free space for oob */
end_comment

begin_define
define|#
directive|define
name|SVR4_S_BANDURG
value|0x0200
end_define

begin_comment
comment|/* generate SIGURG instead of SIGPOLL */
end_comment

begin_define
define|#
directive|define
name|SVR4_S_ALLMASK
value|0x03ff
end_define

begin_comment
comment|/* all events mask */
end_comment

begin_comment
comment|/*  * Our internal state for the stream  * For now we keep almost nothing... In the future we can keep more  * streams state.  */
end_comment

begin_struct
struct|struct
name|svr4_strm
block|{
name|int
name|s_family
decl_stmt|;
comment|/* socket family */
name|int
name|s_cmd
decl_stmt|;
comment|/* last getmsg reply or putmsg request	*/
name|int
name|s_afd
decl_stmt|;
comment|/* last accepted fd; [for fd_insert]	*/
name|int
name|s_eventmask
decl_stmt|;
comment|/* state info from I_SETSIG et al */
block|}
struct|;
end_struct

begin_comment
comment|/*  * The following structures are determined empirically.  */
end_comment

begin_struct
struct|struct
name|svr4_strmcmd
block|{
name|long
name|cmd
decl_stmt|;
comment|/* command ? 		*/
name|long
name|len
decl_stmt|;
comment|/* Address len 		*/
name|long
name|offs
decl_stmt|;
comment|/* Address offset	*/
name|long
name|pad
index|[
literal|61
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|svr4_infocmd
block|{
name|long
name|cmd
decl_stmt|;
name|long
name|tsdu
decl_stmt|;
name|long
name|etsdu
decl_stmt|;
name|long
name|cdata
decl_stmt|;
name|long
name|ddata
decl_stmt|;
name|long
name|addr
decl_stmt|;
name|long
name|opt
decl_stmt|;
name|long
name|tidu
decl_stmt|;
name|long
name|serv
decl_stmt|;
name|long
name|current
decl_stmt|;
name|long
name|provider
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|svr4_strfdinsert
block|{
name|struct
name|svr4_strbuf
name|ctl
decl_stmt|;
name|struct
name|svr4_strbuf
name|data
decl_stmt|;
name|long
name|flags
decl_stmt|;
name|int
name|fd
decl_stmt|;
name|int
name|offset
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|svr4_netaddr_in
block|{
name|u_short
name|family
decl_stmt|;
name|u_short
name|port
decl_stmt|;
name|u_long
name|addr
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|svr4_netaddr_un
block|{
name|u_short
name|family
decl_stmt|;
name|char
name|path
index|[
literal|1
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|SVR4_ADDROF
parameter_list|(
name|sc
parameter_list|)
value|(void *) (((char *) (sc)) + (sc)->offs)
end_define

begin_define
define|#
directive|define
name|SVR4_C_ADDROF
parameter_list|(
name|sc
parameter_list|)
value|(const void *) (((const char *) (sc)) + (sc)->offs)
end_define

begin_decl_stmt
name|struct
name|svr4_strm
modifier|*
name|svr4_stream_get
name|__P
argument_list|(
operator|(
expr|struct
name|file
operator|*
name|fp
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_SVR4_STROPTS */
end_comment

end_unit

