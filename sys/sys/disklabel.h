begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * SPDX-License-Identifier: BSD-3-Clause  *  * Copyright (c) 1987, 1988, 1993  *	The Regents of the University of California.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)disklabel.h	8.2 (Berkeley) 7/10/94  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_SYS_DISKLABEL_H_
end_ifndef

begin_define
define|#
directive|define
name|_SYS_DISKLABEL_H_
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|_KERNEL
end_ifndef

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<sys/ioccom.h>
end_include

begin_include
include|#
directive|include
file|<sys/disk/bsd.h>
end_include

begin_comment
comment|/* Disk description table, see disktab(5) */
end_comment

begin_define
define|#
directive|define
name|_PATH_DISKTAB
value|"/etc/disktab"
end_define

begin_comment
comment|/*  * The label is in block 0 or 1, possibly offset from the beginning  * to leave room for a bootstrap, etc.  * XXX these should be defined per controller (or drive) elsewhere, not here!  * XXX in actuality it can't even be per controller or drive. It should be  * constant/fixed across storage hardware and CPU architectures. Disks can  * travel from one machine to another and a label created on one machine  * should be detectable and understood by the other.  */
end_comment

begin_define
define|#
directive|define
name|LABELSECTOR
value|1
end_define

begin_comment
comment|/* sector containing label */
end_comment

begin_define
define|#
directive|define
name|LABELOFFSET
value|0
end_define

begin_comment
comment|/* offset of label in sector */
end_comment

begin_define
define|#
directive|define
name|DISKMAGIC
value|BSD_MAGIC
end_define

begin_comment
comment|/* The disk magic number */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|MAXPARTITIONS
end_ifndef

begin_define
define|#
directive|define
name|MAXPARTITIONS
value|BSD_NPARTS_MIN
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Size of bootblock area in sector-size neutral bytes */
end_comment

begin_define
define|#
directive|define
name|BBSIZE
value|BSD_BOOTBLOCK_SIZE
end_define

begin_define
define|#
directive|define
name|LABEL_PART
value|BSD_PART_RAW
end_define

begin_define
define|#
directive|define
name|RAW_PART
value|BSD_PART_RAW
end_define

begin_define
define|#
directive|define
name|SWAP_PART
value|BSD_PART_SWAP
end_define

begin_define
define|#
directive|define
name|NDDATA
value|BSD_NDRIVEDATA
end_define

begin_define
define|#
directive|define
name|NSPARE
value|BSD_NSPARE
end_define

begin_function_decl
specifier|static
name|__inline
name|u_int16_t
name|dkcksum
parameter_list|(
name|struct
name|disklabel
modifier|*
name|lp
parameter_list|)
function_decl|;
end_function_decl

begin_function
specifier|static
name|__inline
name|u_int16_t
name|dkcksum
parameter_list|(
name|struct
name|disklabel
modifier|*
name|lp
parameter_list|)
block|{
name|u_int16_t
modifier|*
name|start
decl_stmt|,
modifier|*
name|end
decl_stmt|;
name|u_int16_t
name|sum
init|=
literal|0
decl_stmt|;
name|start
operator|=
operator|(
name|u_int16_t
operator|*
operator|)
name|lp
expr_stmt|;
name|end
operator|=
operator|(
name|u_int16_t
operator|*
operator|)
operator|&
name|lp
operator|->
name|d_partitions
index|[
name|lp
operator|->
name|d_npartitions
index|]
expr_stmt|;
while|while
condition|(
name|start
operator|<
name|end
condition|)
name|sum
operator|^=
operator|*
name|start
operator|++
expr_stmt|;
return|return
operator|(
name|sum
operator|)
return|;
block|}
end_function

begin_ifdef
ifdef|#
directive|ifdef
name|DKTYPENAMES
end_ifdef

begin_decl_stmt
specifier|static
specifier|const
name|char
modifier|*
name|dktypenames
index|[]
init|=
block|{
literal|"unknown"
block|,
literal|"SMD"
block|,
literal|"MSCP"
block|,
literal|"old DEC"
block|,
literal|"SCSI"
block|,
literal|"ESDI"
block|,
literal|"ST506"
block|,
literal|"HP-IB"
block|,
literal|"HP-FL"
block|,
literal|"type 9"
block|,
literal|"floppy"
block|,
literal|"CCD"
block|,
literal|"Vinum"
block|,
literal|"DOC2K"
block|,
literal|"Raid"
block|,
literal|"?"
block|,
literal|"jfs"
block|,
name|NULL
block|}
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|DKMAXTYPES
value|(sizeof(dktypenames) / sizeof(dktypenames[0]) - 1)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|FSTYPENAMES
end_ifdef

begin_decl_stmt
specifier|static
specifier|const
name|char
modifier|*
name|fstypenames
index|[]
init|=
block|{
literal|"unused"
block|,
literal|"swap"
block|,
literal|"Version 6"
block|,
literal|"Version 7"
block|,
literal|"System V"
block|,
literal|"4.1BSD"
block|,
literal|"Eighth Edition"
block|,
literal|"4.2BSD"
block|,
literal|"MSDOS"
block|,
literal|"4.4LFS"
block|,
literal|"unknown"
block|,
literal|"HPFS"
block|,
literal|"ISO9660"
block|,
literal|"boot"
block|,
literal|"vinum"
block|,
literal|"raid"
block|,
literal|"Filecore"
block|,
literal|"EXT2FS"
block|,
literal|"NTFS"
block|,
literal|"?"
block|,
literal|"ccd"
block|,
literal|"jfs"
block|,
literal|"HAMMER"
block|,
literal|"HAMMER2"
block|,
literal|"UDF"
block|,
literal|"?"
block|,
literal|"EFS"
block|,
literal|"ZFS"
block|,
literal|"?"
block|,
literal|"?"
block|,
literal|"nandfs"
block|,
name|NULL
block|}
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|FSMAXTYPES
value|(sizeof(fstypenames) / sizeof(fstypenames[0]) - 1)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * NB:<sys/disk.h> defines ioctls from 'd'/128 and up.  */
end_comment

begin_comment
comment|/*  * Functions for proper encoding/decoding of struct disklabel into/from  * bytestring.  */
end_comment

begin_function_decl
name|void
name|bsd_partition_le_dec
parameter_list|(
name|u_char
modifier|*
name|ptr
parameter_list|,
name|struct
name|partition
modifier|*
name|d
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|bsd_disklabel_le_dec
parameter_list|(
name|u_char
modifier|*
name|ptr
parameter_list|,
name|struct
name|disklabel
modifier|*
name|d
parameter_list|,
name|int
name|maxpart
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|bsd_partition_le_enc
parameter_list|(
name|u_char
modifier|*
name|ptr
parameter_list|,
name|struct
name|partition
modifier|*
name|d
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|bsd_disklabel_le_enc
parameter_list|(
name|u_char
modifier|*
name|ptr
parameter_list|,
name|struct
name|disklabel
modifier|*
name|d
parameter_list|)
function_decl|;
end_function_decl

begin_ifndef
ifndef|#
directive|ifndef
name|_KERNEL
end_ifndef

begin_function_decl
name|__BEGIN_DECLS
name|struct
name|disklabel
modifier|*
name|getdiskbyname
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_macro
name|__END_DECLS
end_macro

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_SYS_DISKLABEL_H_ */
end_comment

end_unit

