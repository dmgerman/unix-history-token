begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1992, 1993  *	The Regents of the University of California.  All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * Sony Corp. and Kazumasa Utashiro of Software Research Associates, Inc.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * from: $Hdr: scsic.h,v 4.300 91/06/09 06:22:24 root Rel41 $ SONY  *  *	@(#)scsic.h	8.1 (Berkeley) 6/11/93  */
end_comment

begin_comment
comment|/*  * Copyright (c) 1987- by SONY Corporation.  */
end_comment

begin_comment
comment|/*  *	scsic.h	ver 1.1		  *  *		Header file for scsi.c.  */
end_comment

begin_define
define|#
directive|define
name|SCSI_NOTWAIT
value|0x2
end_define

begin_comment
comment|/* don't wait cmd completion */
end_comment

begin_define
define|#
directive|define
name|splhi
value|spl7
end_define

begin_comment
comment|/* IPL 7  Be careful to use this.*/
end_comment

begin_comment
comment|/*  * Delay units are in microseconds.  *  *	1ms = 1000  on news800  *	so 1ms = 1500 on 25MHz  */
end_comment

begin_define
define|#
directive|define
name|HDELAY
parameter_list|(
name|n
parameter_list|)
define|\
value|{					\ 		register int N = (n)*1500 ;	\ 		while(--N> 0);			\ 	}
end_define

begin_struct
struct|struct
name|scsi_stat
block|{
name|int
name|wbc
decl_stmt|;
comment|/* # of channel that is waiting for scsi bus free */
name|int
name|wrc
decl_stmt|;
comment|/* # of channel that is waiting for reselection */
name|struct
name|sc_chan_stat
modifier|*
name|ip
decl_stmt|;
comment|/* In progress channel. Same as ISTAT.IP */
name|int
name|ipc
decl_stmt|;
comment|/* number of in progress channel. */
name|int
name|dma_stat
decl_stmt|;
comment|/* OFF = DMAC is not used */
define|#
directive|define
name|SC_DMAC_RD
value|1
define|#
directive|define
name|SC_DMAC_WR
value|2
block|}
struct|;
end_struct

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

begin_struct
struct|struct
name|sc_chan_stat
block|{
name|struct
name|scsi
modifier|*
name|sc
decl_stmt|;
comment|/* scsi struct address */
name|u_char
name|comflg
decl_stmt|;
comment|/* flag for save comand pointer */
name|u_int
name|stcnt
decl_stmt|;
comment|/* save transfer count */
name|u_char
modifier|*
name|spoint
decl_stmt|;
comment|/* save transfer point */
name|u_int
name|stag
decl_stmt|;
comment|/* save tag register */
name|u_int
name|soffset
decl_stmt|;
comment|/* save offset register */
name|u_char
name|intr_flg
decl_stmt|;
comment|/* interrupt flag. SCSI_INTEN/INTDIS */
name|int
name|chan_num
decl_stmt|;
comment|/* channel NO. */
name|VOLATILE
name|struct
name|sc_chan_stat
modifier|*
name|wb_next
decl_stmt|;
comment|/* wait bus channel queue */
block|}
struct|;
end_struct

begin_undef
undef|#
directive|undef
name|VOLATILE
end_undef

begin_decl_stmt
specifier|extern
name|struct
name|scintsw
name|scintsw
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|scsi_stat
name|scsi_stat
decl_stmt|;
end_decl_stmt

end_unit

