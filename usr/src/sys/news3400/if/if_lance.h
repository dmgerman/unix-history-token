begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1992, 1993  *	The Regents of the University of California.  All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * Sony Corp. and Kazumasa Utashiro of Software Research Associates, Inc.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * from: $Hdr: if_lance.h,v 4.300 91/06/09 06:25:59 root Rel41 $ SONY  *  *	@(#)if_lance.h	8.1 (Berkeley) 6/11/93  */
end_comment

begin_undef
undef|#
directive|undef
name|VOLATILE
end_undef

begin_ifdef
ifdef|#
directive|ifdef
name|mips
end_ifdef

begin_define
define|#
directive|define
name|VOLATILE
value|volatile
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|VOLATILE
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_typedef
typedef|typedef
name|VOLATILE
name|struct
name|lance
name|Lance_reg
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|VOLATILE
name|struct
name|recv_msg_desc
name|recv_msg_desc
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|VOLATILE
name|struct
name|xmit_msg_desc
name|xmit_msg_desc
typedef|;
end_typedef

begin_comment
comment|/*  * Structure of statistics record  */
end_comment

begin_struct
struct|struct
name|en_stats
block|{
name|u_char
name|ens_addr
index|[
literal|8
index|]
decl_stmt|;
comment|/* Ethernet Address */
name|int
name|ens_frames
decl_stmt|;
comment|/* Number of Frames Received */
name|int
name|ens_xmit
decl_stmt|;
comment|/* Number of Frames Transmitted */
name|int
name|ens_xcollis
decl_stmt|;
comment|/* Number of Excess Collisions */
name|int
name|ens_frag
decl_stmt|;
comment|/* Number of Fragments Received */
name|int
name|ens_lost
decl_stmt|;
comment|/* Number of Times Frames Lost */
name|int
name|ens_crc
decl_stmt|;
comment|/* Number of CRC Errors */
name|int
name|ens_align
decl_stmt|;
comment|/* Number of Alignment Errors */
name|int
name|ens_collis
decl_stmt|;
comment|/* Number of Collisions */
name|int
name|ens_owcollis
decl_stmt|;
comment|/* Number of Out-of-window Collisions */
block|}
struct|;
end_struct

begin_comment
comment|/*  *	LANCE control block  */
end_comment

begin_typedef
typedef|typedef
name|VOLATILE
struct|struct
name|lance_chan
block|{
name|Lance_reg
modifier|*
name|lance_addr
decl_stmt|;
comment|/* LANCE port address		*/
name|caddr_t
name|lance_memory
decl_stmt|;
comment|/* LANCE memory address		*/
name|caddr_t
name|lance_rom
decl_stmt|;
comment|/* Ethernet address ROM		*/
name|struct
name|init_block
modifier|*
name|lance_ib
decl_stmt|;
comment|/* initialization block address	*/
name|int
name|lance_flags
decl_stmt|;
comment|/* LANCE active flag		*/
name|recv_msg_desc
modifier|*
name|lance_rmd
decl_stmt|;
comment|/* recv. message desc. address	*/
name|xmit_msg_desc
modifier|*
name|lance_tmd
decl_stmt|;
comment|/* xmit. message desc. address	*/
name|recv_msg_desc
modifier|*
name|lance_last_rmd
decl_stmt|;
comment|/* last rmd		*/
name|xmit_msg_desc
modifier|*
name|lance_last_tmd
decl_stmt|;
comment|/* last tmd		*/
name|struct
name|en_stats
name|lance_stats
decl_stmt|;
comment|/* LANCE statistics		*/
block|}
name|Lance_chan
typedef|;
end_typedef

begin_undef
undef|#
directive|undef
name|VOLATILE
end_undef

begin_define
define|#
directive|define
name|LANCE_ACTIVE
value|1
end_define

begin_define
define|#
directive|define
name|LANCE_PROM
value|2
end_define

begin_define
define|#
directive|define
name|LANCE_IDON
value|8
end_define

end_unit

