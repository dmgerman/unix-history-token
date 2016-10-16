begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1987, 1988, 1993  *	The Regents of the University of California.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)disklabel.h	8.2 (Berkeley) 7/10/94  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_SYS_DISK_MBR_H_
end_ifndef

begin_define
define|#
directive|define
name|_SYS_DISK_MBR_H_
end_define

begin_define
define|#
directive|define
name|DOSBBSECTOR
value|0
end_define

begin_comment
comment|/* DOS boot block relative sector number */
end_comment

begin_define
define|#
directive|define
name|DOSDSNOFF
value|440
end_define

begin_comment
comment|/* WinNT/2K/XP Drive Serial Number offset */
end_comment

begin_define
define|#
directive|define
name|DOSPARTOFF
value|446
end_define

begin_define
define|#
directive|define
name|DOSPARTSIZE
value|16
end_define

begin_define
define|#
directive|define
name|NDOSPART
value|4
end_define

begin_define
define|#
directive|define
name|NEXTDOSPART
value|32
end_define

begin_define
define|#
directive|define
name|DOSMAGICOFFSET
value|510
end_define

begin_define
define|#
directive|define
name|DOSMAGIC
value|0xAA55
end_define

begin_define
define|#
directive|define
name|DOSPTYP_EXT
value|0x05
end_define

begin_comment
comment|/* DOS extended partition */
end_comment

begin_define
define|#
directive|define
name|DOSPTYP_FAT16
value|0x06
end_define

begin_comment
comment|/* FAT16 partition */
end_comment

begin_define
define|#
directive|define
name|DOSPTYP_NTFS
value|0x07
end_define

begin_comment
comment|/* NTFS partition */
end_comment

begin_define
define|#
directive|define
name|DOSPTYP_FAT32
value|0x0b
end_define

begin_comment
comment|/* FAT32 partition */
end_comment

begin_define
define|#
directive|define
name|DOSPTYP_EXTLBA
value|0x0f
end_define

begin_comment
comment|/* DOS extended partition */
end_comment

begin_define
define|#
directive|define
name|DOSPTYP_PPCBOOT
value|0x41
end_define

begin_comment
comment|/* PReP/CHRP boot partition */
end_comment

begin_define
define|#
directive|define
name|DOSPTYP_LDM
value|0x42
end_define

begin_comment
comment|/* Win2k dynamic extended partition */
end_comment

begin_define
define|#
directive|define
name|DOSPTYP_LINSWP
value|0x82
end_define

begin_comment
comment|/* Linux swap partition */
end_comment

begin_define
define|#
directive|define
name|DOSPTYP_LINUX
value|0x83
end_define

begin_comment
comment|/* Linux partition */
end_comment

begin_define
define|#
directive|define
name|DOSPTYP_LINLVM
value|0x8e
end_define

begin_comment
comment|/* Linux LVM partition */
end_comment

begin_define
define|#
directive|define
name|DOSPTYP_386BSD
value|0xa5
end_define

begin_comment
comment|/* 386BSD partition type */
end_comment

begin_define
define|#
directive|define
name|DOSPTYP_APPLE_UFS
value|0xa8
end_define

begin_comment
comment|/* Apple Mac OS X boot */
end_comment

begin_define
define|#
directive|define
name|DOSPTYP_APPLE_BOOT
value|0xab
end_define

begin_comment
comment|/* Apple Mac OS X UFS */
end_comment

begin_define
define|#
directive|define
name|DOSPTYP_HFS
value|0xaf
end_define

begin_comment
comment|/* HFS/HFS+ partition type */
end_comment

begin_define
define|#
directive|define
name|DOSPTYP_PMBR
value|0xee
end_define

begin_comment
comment|/* GPT Protective MBR */
end_comment

begin_define
define|#
directive|define
name|DOSPTYP_EFI
value|0xef
end_define

begin_comment
comment|/* EFI FAT parition */
end_comment

begin_define
define|#
directive|define
name|DOSPTYP_VMFS
value|0xfb
end_define

begin_comment
comment|/* VMware VMFS partition */
end_comment

begin_define
define|#
directive|define
name|DOSPTYP_VMKDIAG
value|0xfc
end_define

begin_comment
comment|/* VMware vmkDiagnostic partition */
end_comment

begin_define
define|#
directive|define
name|DOSPTYP_LINRAID
value|0xfd
end_define

begin_comment
comment|/* Linux raid partition */
end_comment

begin_struct
struct|struct
name|dos_partition
block|{
name|unsigned
name|char
name|dp_flag
decl_stmt|;
comment|/* bootstrap flags */
name|unsigned
name|char
name|dp_shd
decl_stmt|;
comment|/* starting head */
name|unsigned
name|char
name|dp_ssect
decl_stmt|;
comment|/* starting sector */
name|unsigned
name|char
name|dp_scyl
decl_stmt|;
comment|/* starting cylinder */
name|unsigned
name|char
name|dp_typ
decl_stmt|;
comment|/* partition type */
name|unsigned
name|char
name|dp_ehd
decl_stmt|;
comment|/* end head */
name|unsigned
name|char
name|dp_esect
decl_stmt|;
comment|/* end sector */
name|unsigned
name|char
name|dp_ecyl
decl_stmt|;
comment|/* end cylinder */
name|uint32_t
name|dp_start
decl_stmt|;
comment|/* absolute starting sector number */
name|uint32_t
name|dp_size
decl_stmt|;
comment|/* partition size in sectors */
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
name|dos_partition
argument_list|)
operator|==
name|DOSPARTSIZE
argument_list|)
expr_stmt|;
end_expr_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|DPSECT
parameter_list|(
name|s
parameter_list|)
value|((s)& 0x3f)
end_define

begin_comment
comment|/* isolate relevant bits of sector */
end_comment

begin_define
define|#
directive|define
name|DPCYL
parameter_list|(
name|c
parameter_list|,
name|s
parameter_list|)
value|((c) + (((s)& 0xc0)<<2))
end_define

begin_comment
comment|/* and those that are cylinder */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_SYS_DISK_MBR_H_ */
end_comment

end_unit

