begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1982, 1986, 1993, 1994  *	The Regents of the University of California.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)dkbad.h	8.2 (Berkeley) 7/10/94  * $Id: dkbad.h,v 1.9 1997/02/22 09:45:07 peter Exp $  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_SYS_DKBAD_H_
end_ifndef

begin_define
define|#
directive|define
name|_SYS_DKBAD_H_
end_define

begin_comment
comment|/*  * Definitions needed to perform bad sector revectoring ala DEC STD 144.  *  * The bad sector information is located in the first 5 even numbered  * sectors of the last track of the disk pack.  There are five identical  * copies of the information, described by the dkbad structure.  *  * Replacement sectors are allocated starting with the first sector before  * the bad sector information and working backwards towards the beginning of  * the disk.  A maximum of 126 bad sectors are supported.  The position of  * the bad sector in the bad sector table determines which replacement sector  * it corresponds to.  *  * The bad sector information and replacement sectors are conventionally  * only accessible through the 'c' file system partition of the disk.  If  * that partition is used for a file system, the user is responsible for  * making sure that it does not overlap the bad sector information or any  * replacement sectors.  */
end_comment

begin_define
define|#
directive|define
name|DKBAD_MAGIC
value|0x4321
end_define

begin_comment
comment|/* normal value for bt_flag */
end_comment

begin_define
define|#
directive|define
name|DKBAD_MAXBAD
value|126
end_define

begin_comment
comment|/* maximum bad sectors supported */
end_comment

begin_define
define|#
directive|define
name|DKBAD_NOCYL
value|0xffff
end_define

begin_comment
comment|/* cylinder to mark end of disk table */
end_comment

begin_define
define|#
directive|define
name|DKBAD_NOTRKSEC
value|0xffff
end_define

begin_comment
comment|/* track/sector to mark end */
end_comment

begin_struct
struct|struct
name|dkbad
block|{
name|int32_t
name|bt_csn
decl_stmt|;
comment|/* cartridge serial number */
name|u_int16_t
name|bt_mbz
decl_stmt|;
comment|/* unused; should be 0 */
name|u_int16_t
name|bt_flag
decl_stmt|;
comment|/* -1 => alignment cartridge */
struct|struct
name|bt_bad
block|{
name|u_int16_t
name|bt_cyl
decl_stmt|;
comment|/* cylinder number of bad sector */
name|u_int16_t
name|bt_trksec
decl_stmt|;
comment|/* track and sector number */
block|}
name|bt_bad
index|[
name|DKBAD_MAXBAD
index|]
struct|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|ECC
value|0
end_define

begin_define
define|#
directive|define
name|SSE
value|1
end_define

begin_define
define|#
directive|define
name|BSE
value|2
end_define

begin_define
define|#
directive|define
name|CONT
value|3
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|KERNEL
end_ifdef

begin_define
define|#
directive|define
name|DKBAD_NOSECT
value|(-1)
end_define

begin_comment
comment|/* sector to mark end of core table */
end_comment

begin_struct
struct|struct
name|dkbad_intern
block|{
name|daddr_t
name|bi_maxspare
decl_stmt|;
comment|/* last spare sector */
name|u_int
name|bi_nbad
decl_stmt|;
comment|/* actual dimension of bi_badsect[] */
name|long
name|bi_bad
index|[
name|DKBAD_MAXBAD
operator|+
literal|1
index|]
decl_stmt|;
comment|/* actually usually less */
block|}
struct|;
end_struct

begin_struct_decl
struct_decl|struct
name|buf
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|disklabel
struct_decl|;
end_struct_decl

begin_decl_stmt
name|struct
name|dkbad_intern
modifier|*
name|internbad144
name|__P
argument_list|(
operator|(
expr|struct
name|dkbad
operator|*
name|btp
operator|,
expr|struct
name|disklabel
operator|*
name|lp
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|readbad144
name|__P
argument_list|(
operator|(
name|dev_t
name|dev
operator|,
name|void
argument_list|(
operator|*
name|strat
argument_list|)
argument_list|(
expr|struct
name|buf
operator|*
name|bp
argument_list|)
operator|,
expr|struct
name|disklabel
operator|*
name|lp
operator|,
expr|struct
name|dkbad
operator|*
name|btp
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|daddr_t
name|transbad144
name|__P
argument_list|(
operator|(
expr|struct
name|dkbad_intern
operator|*
name|bip
operator|,
name|daddr_t
name|blkno
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_SYS_DKBAD_H_ */
end_comment

end_unit

