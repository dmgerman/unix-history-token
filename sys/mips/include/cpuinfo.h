begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1987, 1988, 1993  *	The Regents of the University of California.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)disklabel.h	8.2 (Berkeley) 7/10/94  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_SYS_DISK_PC98_H_
end_ifndef

begin_define
define|#
directive|define
name|_SYS_DISK_PC98_H_
end_define

begin_define
define|#
directive|define
name|PC98_BBSECTOR
value|1
end_define

begin_comment
comment|/* DOS boot block relative sector number */
end_comment

begin_define
define|#
directive|define
name|PC98_PARTOFF
value|0
end_define

begin_define
define|#
directive|define
name|PC98_PARTSIZE
value|32
end_define

begin_define
define|#
directive|define
name|PC98_NPARTS
value|16
end_define

begin_define
define|#
directive|define
name|PC98_MAGICOFS
value|510
end_define

begin_define
define|#
directive|define
name|PC98_MAGIC
value|0xAA55
end_define

begin_define
define|#
directive|define
name|PC98_MID_BOOTABLE
value|0x80
end_define

begin_define
define|#
directive|define
name|PC98_MID_MASK
value|0x7f
end_define

begin_define
define|#
directive|define
name|PC98_MID_386BSD
value|0x14
end_define

begin_define
define|#
directive|define
name|PC98_SID_ACTIVE
value|0x80
end_define

begin_define
define|#
directive|define
name|PC98_SID_MASK
value|0x7f
end_define

begin_define
define|#
directive|define
name|PC98_SID_386BSD
value|0x44
end_define

begin_define
define|#
directive|define
name|__DOSMID_386BSD
value|(PC98_MID_386BSD | PC98_MID_BOOTABLE)
end_define

begin_define
define|#
directive|define
name|__DOSSID_386BSD
value|(PC98_SID_386BSD | PC98_SID_ACTIVE)
end_define

begin_define
define|#
directive|define
name|PC98_PTYP_386BSD
value|(__DOSSID_386BSD<< 8 | __DOSMID_386BSD)
end_define

begin_struct
struct|struct
name|pc98_partition
block|{
name|unsigned
name|char
name|dp_mid
decl_stmt|;
name|unsigned
name|char
name|dp_sid
decl_stmt|;
name|unsigned
name|char
name|dp_dum1
decl_stmt|;
name|unsigned
name|char
name|dp_dum2
decl_stmt|;
name|unsigned
name|char
name|dp_ipl_sct
decl_stmt|;
name|unsigned
name|char
name|dp_ipl_head
decl_stmt|;
name|unsigned
name|short
name|dp_ipl_cyl
decl_stmt|;
name|unsigned
name|char
name|dp_ssect
decl_stmt|;
comment|/* starting sector */
name|unsigned
name|char
name|dp_shd
decl_stmt|;
comment|/* starting head */
name|unsigned
name|short
name|dp_scyl
decl_stmt|;
comment|/* starting cylinder */
name|unsigned
name|char
name|dp_esect
decl_stmt|;
comment|/* end sector */
name|unsigned
name|char
name|dp_ehd
decl_stmt|;
comment|/* end head */
name|unsigned
name|short
name|dp_ecyl
decl_stmt|;
comment|/* end cylinder */
name|unsigned
name|char
name|dp_name
index|[
literal|16
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_ifdef
ifdef|#
directive|ifdef
name|CTASSERT
end_ifdef

begin_expr_stmt
name|CTASSERT
argument_list|(
sizeof|sizeof
argument_list|(
expr|struct
name|pc98_partition
argument_list|)
operator|==
name|PC98_PARTSIZE
argument_list|)
expr_stmt|;
end_expr_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_SYS_DISK_PC98_H_ */
end_comment

end_unit

