begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1982, 1986, 1990, 1993  *	The Regents of the University of California.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)socketvar.h	8.3 (Berkeley) 2/19/95  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_SYS_SOCKBUF_H_
end_ifndef

begin_define
define|#
directive|define
name|_SYS_SOCKBUF_H_
end_define

begin_include
include|#
directive|include
file|<sys/selinfo.h>
end_include

begin_comment
comment|/* for struct selinfo */
end_comment

begin_include
include|#
directive|include
file|<sys/_lock.h>
end_include

begin_include
include|#
directive|include
file|<sys/_mutex.h>
end_include

begin_include
include|#
directive|include
file|<sys/_sx.h>
end_include

begin_define
define|#
directive|define
name|SB_MAX
value|(2*1024*1024)
end_define

begin_comment
comment|/* default for max chars in sockbuf */
end_comment

begin_comment
comment|/*  * Constants for sb_flags field of struct sockbuf.  */
end_comment

begin_define
define|#
directive|define
name|SB_WAIT
value|0x04
end_define

begin_comment
comment|/* someone is waiting for data/space */
end_comment

begin_define
define|#
directive|define
name|SB_SEL
value|0x08
end_define

begin_comment
comment|/* someone is selecting */
end_comment

begin_define
define|#
directive|define
name|SB_ASYNC
value|0x10
end_define

begin_comment
comment|/* ASYNC I/O, need signals */
end_comment

begin_define
define|#
directive|define
name|SB_UPCALL
value|0x20
end_define

begin_comment
comment|/* someone wants an upcall */
end_comment

begin_define
define|#
directive|define
name|SB_NOINTR
value|0x40
end_define

begin_comment
comment|/* operations not interruptible */
end_comment

begin_define
define|#
directive|define
name|SB_AIO
value|0x80
end_define

begin_comment
comment|/* AIO operations queued */
end_comment

begin_define
define|#
directive|define
name|SB_KNOTE
value|0x100
end_define

begin_comment
comment|/* kernel note attached */
end_comment

begin_define
define|#
directive|define
name|SB_NOCOALESCE
value|0x200
end_define

begin_comment
comment|/* don't coalesce new data into existing mbufs */
end_comment

begin_define
define|#
directive|define
name|SB_IN_TOE
value|0x400
end_define

begin_comment
comment|/* socket buffer is in the middle of an operation */
end_comment

begin_define
define|#
directive|define
name|SB_AUTOSIZE
value|0x800
end_define

begin_comment
comment|/* automatically size socket buffer */
end_comment

begin_define
define|#
directive|define
name|SB_STOP
value|0x1000
end_define

begin_comment
comment|/* backpressure indicator */
end_comment

begin_define
define|#
directive|define
name|SBS_CANTSENDMORE
value|0x0010
end_define

begin_comment
comment|/* can't send more data to peer */
end_comment

begin_define
define|#
directive|define
name|SBS_CANTRCVMORE
value|0x0020
end_define

begin_comment
comment|/* can't receive more data from peer */
end_comment

begin_define
define|#
directive|define
name|SBS_RCVATMARK
value|0x0040
end_define

begin_comment
comment|/* at mark on input */
end_comment

begin_struct_decl
struct_decl|struct
name|mbuf
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|sockaddr
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|socket
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|thread
struct_decl|;
end_struct_decl

begin_struct
struct|struct
name|xsockbuf
block|{
name|u_int
name|sb_cc
decl_stmt|;
name|u_int
name|sb_hiwat
decl_stmt|;
name|u_int
name|sb_mbcnt
decl_stmt|;
name|u_int
name|sb_mcnt
decl_stmt|;
name|u_int
name|sb_ccnt
decl_stmt|;
name|u_int
name|sb_mbmax
decl_stmt|;
name|int
name|sb_lowat
decl_stmt|;
name|int
name|sb_timeo
decl_stmt|;
name|short
name|sb_flags
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * Variables for socket buffering.  */
end_comment

begin_struct
struct|struct
name|sockbuf
block|{
name|struct
name|selinfo
name|sb_sel
decl_stmt|;
comment|/* process selecting read/write */
name|struct
name|mtx
name|sb_mtx
decl_stmt|;
comment|/* sockbuf lock */
name|struct
name|sx
name|sb_sx
decl_stmt|;
comment|/* prevent I/O interlacing */
name|short
name|sb_state
decl_stmt|;
comment|/* (c/d) socket state on sockbuf */
define|#
directive|define
name|sb_startzero
value|sb_mb
name|struct
name|mbuf
modifier|*
name|sb_mb
decl_stmt|;
comment|/* (c/d) the mbuf chain */
name|struct
name|mbuf
modifier|*
name|sb_mbtail
decl_stmt|;
comment|/* (c/d) the last mbuf in the chain */
name|struct
name|mbuf
modifier|*
name|sb_lastrecord
decl_stmt|;
comment|/* (c/d) first mbuf of last 					 * record in socket buffer */
name|struct
name|mbuf
modifier|*
name|sb_sndptr
decl_stmt|;
comment|/* (c/d) pointer into mbuf chain */
name|u_int
name|sb_sndptroff
decl_stmt|;
comment|/* (c/d) byte offset of ptr into chain */
name|u_int
name|sb_cc
decl_stmt|;
comment|/* (c/d) actual chars in buffer */
name|u_int
name|sb_hiwat
decl_stmt|;
comment|/* (c/d) max actual char count */
name|u_int
name|sb_mbcnt
decl_stmt|;
comment|/* (c/d) chars of mbufs used */
name|u_int
name|sb_mcnt
decl_stmt|;
comment|/* (c/d) number of mbufs in buffer */
name|u_int
name|sb_ccnt
decl_stmt|;
comment|/* (c/d) number of clusters in buffer */
name|u_int
name|sb_mbmax
decl_stmt|;
comment|/* (c/d) max chars of mbufs to use */
name|u_int
name|sb_ctl
decl_stmt|;
comment|/* (c/d) non-data chars in buffer */
name|int
name|sb_lowat
decl_stmt|;
comment|/* (c/d) low water mark */
name|sbintime_t
name|sb_timeo
decl_stmt|;
comment|/* (c/d) timeout for read/write */
name|short
name|sb_flags
decl_stmt|;
comment|/* (c/d) flags, see below */
name|int
function_decl|(
modifier|*
name|sb_upcall
function_decl|)
parameter_list|(
name|struct
name|socket
modifier|*
parameter_list|,
name|void
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
comment|/* (c/d) */
name|void
modifier|*
name|sb_upcallarg
decl_stmt|;
comment|/* (c/d) */
block|}
struct|;
end_struct

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_comment
comment|/*  * Per-socket buffer mutex used to protect most fields in the socket  * buffer.  */
end_comment

begin_define
define|#
directive|define
name|SOCKBUF_MTX
parameter_list|(
name|_sb
parameter_list|)
value|(&(_sb)->sb_mtx)
end_define

begin_define
define|#
directive|define
name|SOCKBUF_LOCK_INIT
parameter_list|(
name|_sb
parameter_list|,
name|_name
parameter_list|)
define|\
value|mtx_init(SOCKBUF_MTX(_sb), _name, NULL, MTX_DEF)
end_define

begin_define
define|#
directive|define
name|SOCKBUF_LOCK_DESTROY
parameter_list|(
name|_sb
parameter_list|)
value|mtx_destroy(SOCKBUF_MTX(_sb))
end_define

begin_define
define|#
directive|define
name|SOCKBUF_LOCK
parameter_list|(
name|_sb
parameter_list|)
value|mtx_lock(SOCKBUF_MTX(_sb))
end_define

begin_define
define|#
directive|define
name|SOCKBUF_OWNED
parameter_list|(
name|_sb
parameter_list|)
value|mtx_owned(SOCKBUF_MTX(_sb))
end_define

begin_define
define|#
directive|define
name|SOCKBUF_UNLOCK
parameter_list|(
name|_sb
parameter_list|)
value|mtx_unlock(SOCKBUF_MTX(_sb))
end_define

begin_define
define|#
directive|define
name|SOCKBUF_LOCK_ASSERT
parameter_list|(
name|_sb
parameter_list|)
value|mtx_assert(SOCKBUF_MTX(_sb), MA_OWNED)
end_define

begin_define
define|#
directive|define
name|SOCKBUF_UNLOCK_ASSERT
parameter_list|(
name|_sb
parameter_list|)
value|mtx_assert(SOCKBUF_MTX(_sb), MA_NOTOWNED)
end_define

begin_function_decl
name|void
name|sbappend
parameter_list|(
name|struct
name|sockbuf
modifier|*
name|sb
parameter_list|,
name|struct
name|mbuf
modifier|*
name|m
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|sbappend_locked
parameter_list|(
name|struct
name|sockbuf
modifier|*
name|sb
parameter_list|,
name|struct
name|mbuf
modifier|*
name|m
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|sbappendstream
parameter_list|(
name|struct
name|sockbuf
modifier|*
name|sb
parameter_list|,
name|struct
name|mbuf
modifier|*
name|m
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|sbappendstream_locked
parameter_list|(
name|struct
name|sockbuf
modifier|*
name|sb
parameter_list|,
name|struct
name|mbuf
modifier|*
name|m
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|sbappendaddr
parameter_list|(
name|struct
name|sockbuf
modifier|*
name|sb
parameter_list|,
specifier|const
name|struct
name|sockaddr
modifier|*
name|asa
parameter_list|,
name|struct
name|mbuf
modifier|*
name|m0
parameter_list|,
name|struct
name|mbuf
modifier|*
name|control
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|sbappendaddr_locked
parameter_list|(
name|struct
name|sockbuf
modifier|*
name|sb
parameter_list|,
specifier|const
name|struct
name|sockaddr
modifier|*
name|asa
parameter_list|,
name|struct
name|mbuf
modifier|*
name|m0
parameter_list|,
name|struct
name|mbuf
modifier|*
name|control
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|sbappendaddr_nospacecheck_locked
parameter_list|(
name|struct
name|sockbuf
modifier|*
name|sb
parameter_list|,
specifier|const
name|struct
name|sockaddr
modifier|*
name|asa
parameter_list|,
name|struct
name|mbuf
modifier|*
name|m0
parameter_list|,
name|struct
name|mbuf
modifier|*
name|control
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|sbappendcontrol
parameter_list|(
name|struct
name|sockbuf
modifier|*
name|sb
parameter_list|,
name|struct
name|mbuf
modifier|*
name|m0
parameter_list|,
name|struct
name|mbuf
modifier|*
name|control
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|sbappendcontrol_locked
parameter_list|(
name|struct
name|sockbuf
modifier|*
name|sb
parameter_list|,
name|struct
name|mbuf
modifier|*
name|m0
parameter_list|,
name|struct
name|mbuf
modifier|*
name|control
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|sbappendrecord
parameter_list|(
name|struct
name|sockbuf
modifier|*
name|sb
parameter_list|,
name|struct
name|mbuf
modifier|*
name|m0
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|sbappendrecord_locked
parameter_list|(
name|struct
name|sockbuf
modifier|*
name|sb
parameter_list|,
name|struct
name|mbuf
modifier|*
name|m0
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|sbcheck
parameter_list|(
name|struct
name|sockbuf
modifier|*
name|sb
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|sbcompress
parameter_list|(
name|struct
name|sockbuf
modifier|*
name|sb
parameter_list|,
name|struct
name|mbuf
modifier|*
name|m
parameter_list|,
name|struct
name|mbuf
modifier|*
name|n
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|mbuf
modifier|*
name|sbcreatecontrol
parameter_list|(
name|caddr_t
name|p
parameter_list|,
name|int
name|size
parameter_list|,
name|int
name|type
parameter_list|,
name|int
name|level
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|sbdestroy
parameter_list|(
name|struct
name|sockbuf
modifier|*
name|sb
parameter_list|,
name|struct
name|socket
modifier|*
name|so
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|sbdrop
parameter_list|(
name|struct
name|sockbuf
modifier|*
name|sb
parameter_list|,
name|int
name|len
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|sbdrop_locked
parameter_list|(
name|struct
name|sockbuf
modifier|*
name|sb
parameter_list|,
name|int
name|len
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|mbuf
modifier|*
name|sbcut_locked
parameter_list|(
name|struct
name|sockbuf
modifier|*
name|sb
parameter_list|,
name|int
name|len
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|sbdroprecord
parameter_list|(
name|struct
name|sockbuf
modifier|*
name|sb
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|sbdroprecord_locked
parameter_list|(
name|struct
name|sockbuf
modifier|*
name|sb
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|sbflush
parameter_list|(
name|struct
name|sockbuf
modifier|*
name|sb
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|sbflush_locked
parameter_list|(
name|struct
name|sockbuf
modifier|*
name|sb
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|sbrelease
parameter_list|(
name|struct
name|sockbuf
modifier|*
name|sb
parameter_list|,
name|struct
name|socket
modifier|*
name|so
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|sbrelease_internal
parameter_list|(
name|struct
name|sockbuf
modifier|*
name|sb
parameter_list|,
name|struct
name|socket
modifier|*
name|so
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|sbrelease_locked
parameter_list|(
name|struct
name|sockbuf
modifier|*
name|sb
parameter_list|,
name|struct
name|socket
modifier|*
name|so
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|sbreserve
parameter_list|(
name|struct
name|sockbuf
modifier|*
name|sb
parameter_list|,
name|u_long
name|cc
parameter_list|,
name|struct
name|socket
modifier|*
name|so
parameter_list|,
name|struct
name|thread
modifier|*
name|td
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|sbreserve_locked
parameter_list|(
name|struct
name|sockbuf
modifier|*
name|sb
parameter_list|,
name|u_long
name|cc
parameter_list|,
name|struct
name|socket
modifier|*
name|so
parameter_list|,
name|struct
name|thread
modifier|*
name|td
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|mbuf
modifier|*
name|sbsndptr
parameter_list|(
name|struct
name|sockbuf
modifier|*
name|sb
parameter_list|,
name|u_int
name|off
parameter_list|,
name|u_int
name|len
parameter_list|,
name|u_int
modifier|*
name|moff
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|mbuf
modifier|*
name|sbsndmbuf
parameter_list|(
name|struct
name|sockbuf
modifier|*
name|sb
parameter_list|,
name|u_int
name|off
parameter_list|,
name|u_int
modifier|*
name|moff
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|sbtoxsockbuf
parameter_list|(
name|struct
name|sockbuf
modifier|*
name|sb
parameter_list|,
name|struct
name|xsockbuf
modifier|*
name|xsb
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|sbwait
parameter_list|(
name|struct
name|sockbuf
modifier|*
name|sb
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|sblock
parameter_list|(
name|struct
name|sockbuf
modifier|*
name|sb
parameter_list|,
name|int
name|flags
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|sbunlock
parameter_list|(
name|struct
name|sockbuf
modifier|*
name|sb
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * How much space is there in a socket buffer (so->so_snd or so->so_rcv)?  * This is problematical if the fields are unsigned, as the space might  * still be negative (cc> hiwat or mbcnt> mbmax).  Should detect  * overflow and return 0.  Should use "lmin" but it doesn't exist now.  */
end_comment

begin_function
specifier|static
name|__inline
name|long
name|sbspace
parameter_list|(
name|struct
name|sockbuf
modifier|*
name|sb
parameter_list|)
block|{
name|long
name|bleft
decl_stmt|;
name|long
name|mleft
decl_stmt|;
if|if
condition|(
name|sb
operator|->
name|sb_flags
operator|&
name|SB_STOP
condition|)
return|return
operator|(
literal|0
operator|)
return|;
name|bleft
operator|=
name|sb
operator|->
name|sb_hiwat
operator|-
name|sb
operator|->
name|sb_cc
expr_stmt|;
name|mleft
operator|=
name|sb
operator|->
name|sb_mbmax
operator|-
name|sb
operator|->
name|sb_mbcnt
expr_stmt|;
return|return
operator|(
operator|(
name|bleft
operator|<
name|mleft
operator|)
condition|?
name|bleft
else|:
name|mleft
operator|)
return|;
block|}
end_function

begin_comment
comment|/* adjust counters in sb reflecting allocation of m */
end_comment

begin_define
define|#
directive|define
name|sballoc
parameter_list|(
name|sb
parameter_list|,
name|m
parameter_list|)
value|{ \ 	(sb)->sb_cc += (m)->m_len; \ 	if ((m)->m_type != MT_DATA&& (m)->m_type != MT_OOBDATA) \ 		(sb)->sb_ctl += (m)->m_len; \ 	(sb)->sb_mbcnt += MSIZE; \ 	(sb)->sb_mcnt += 1; \ 	if ((m)->m_flags& M_EXT) { \ 		(sb)->sb_mbcnt += (m)->m_ext.ext_size; \ 		(sb)->sb_ccnt += 1; \ 	} \ }
end_define

begin_comment
comment|/* adjust counters in sb reflecting freeing of m */
end_comment

begin_define
define|#
directive|define
name|sbfree
parameter_list|(
name|sb
parameter_list|,
name|m
parameter_list|)
value|{ \ 	(sb)->sb_cc -= (m)->m_len; \ 	if ((m)->m_type != MT_DATA&& (m)->m_type != MT_OOBDATA) \ 		(sb)->sb_ctl -= (m)->m_len; \ 	(sb)->sb_mbcnt -= MSIZE; \ 	(sb)->sb_mcnt -= 1; \ 	if ((m)->m_flags& M_EXT) { \ 		(sb)->sb_mbcnt -= (m)->m_ext.ext_size; \ 		(sb)->sb_ccnt -= 1; \ 	} \ 	if ((sb)->sb_sndptr == (m)) { \ 		(sb)->sb_sndptr = NULL; \ 		(sb)->sb_sndptroff = 0; \ 	} \ 	if ((sb)->sb_sndptroff != 0) \ 		(sb)->sb_sndptroff -= (m)->m_len; \ }
end_define

begin_define
define|#
directive|define
name|SB_EMPTY_FIXUP
parameter_list|(
name|sb
parameter_list|)
value|do {						\ 	if ((sb)->sb_mb == NULL) {					\ 		(sb)->sb_mbtail = NULL;					\ 		(sb)->sb_lastrecord = NULL;				\ 	}								\ } while (
comment|/*CONSTCOND*/
value|0)
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|SOCKBUF_DEBUG
end_ifdef

begin_function_decl
name|void
name|sblastrecordchk
parameter_list|(
name|struct
name|sockbuf
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|SBLASTRECORDCHK
parameter_list|(
name|sb
parameter_list|)
value|sblastrecordchk((sb), __FILE__, __LINE__)
end_define

begin_function_decl
name|void
name|sblastmbufchk
parameter_list|(
name|struct
name|sockbuf
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|SBLASTMBUFCHK
parameter_list|(
name|sb
parameter_list|)
value|sblastmbufchk((sb), __FILE__, __LINE__)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|SBLASTRECORDCHK
parameter_list|(
name|sb
parameter_list|)
end_define

begin_comment
comment|/* nothing */
end_comment

begin_define
define|#
directive|define
name|SBLASTMBUFCHK
parameter_list|(
name|sb
parameter_list|)
end_define

begin_comment
comment|/* nothing */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* SOCKBUF_DEBUG */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _KERNEL */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _SYS_SOCKBUF_H_ */
end_comment

end_unit

