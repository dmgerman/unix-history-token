begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1992, 1993  *	The Regents of the University of California.  All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * Sony Corp. and Kazumasa Utashiro of Software Research Associates, Inc.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * from: $Hdr: if_news.h,v 4.300 91/06/09 06:26:02 root Rel41 $ SONY  *  *	@(#)if_news.h	8.1 (Berkeley) 6/11/93  */
end_comment

begin_comment
comment|/*  * Structure and routine definitions  * for NEWS network interfaces.  */
end_comment

begin_comment
comment|/*  * Each interface has one of these structures giving information  * about NEWS resources held by the interface.  */
end_comment

begin_struct
struct|struct
name|ifnews
block|{
name|int
name|ifn_hlen
decl_stmt|;
comment|/* local net header length */
name|caddr_t
name|ifn_raddr
decl_stmt|;
comment|/* receive buffer address */
name|caddr_t
name|ifn_waddr
decl_stmt|;
comment|/* transmit buffer address */
name|struct
name|mbuf
modifier|*
name|ifn_mbuf
decl_stmt|;
comment|/* packet being transmitted */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|mbuf_segment
block|{
name|u_int
name|ms_physaddr
decl_stmt|;
name|u_int
name|ms_size
decl_stmt|;
block|}
struct|;
end_struct

begin_ifdef
ifdef|#
directive|ifdef
name|KERNEL
end_ifdef

begin_function_decl
name|struct
name|mbuf
modifier|*
name|if_rnewsget
parameter_list|()
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|LARGE_DATA
value|512
end_define

end_unit

