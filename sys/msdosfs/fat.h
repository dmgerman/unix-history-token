begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $FreeBSD$ */
end_comment

begin_comment
comment|/*	$NetBSD: fat.h,v 1.12 1997/11/17 15:36:36 ws Exp $	*/
end_comment

begin_comment
comment|/*-  * Copyright (C) 1994, 1997 Wolfgang Solfrank.  * Copyright (C) 1994, 1997 TooLs GmbH.  * All rights reserved.  * Original code by Paul Popelka (paulp@uts.amdahl.com) (see below).  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by TooLs GmbH.  * 4. The name of TooLs GmbH may not be used to endorse or promote products  *    derived from this software without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY TOOLS GMBH ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL TOOLS GMBH BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,  * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,  * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS;  * OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,  * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR  * OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF  * ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  */
end_comment

begin_comment
comment|/*  * Written by Paul Popelka (paulp@uts.amdahl.com)  *  * You can do anything you want with this software, just don't say you wrote  * it, and don't remove this notice.  *  * This software is provided "as is".  *  * The author supplies this software to be publicly redistributed on the  * understanding that the author is not responsible for the correct  * functioning of this software in any circumstances and is not liable for  * any damages caused by this software.  *  * October 1992  */
end_comment

begin_comment
comment|/*  * Some useful cluster numbers.  */
end_comment

begin_define
define|#
directive|define
name|MSDOSFSROOT
value|0
end_define

begin_comment
comment|/* cluster 0 means the root dir */
end_comment

begin_define
define|#
directive|define
name|CLUST_FREE
value|0
end_define

begin_comment
comment|/* cluster 0 also means a free cluster */
end_comment

begin_define
define|#
directive|define
name|MSDOSFSFREE
value|CLUST_FREE
end_define

begin_define
define|#
directive|define
name|CLUST_FIRST
value|2
end_define

begin_comment
comment|/* first legal cluster number */
end_comment

begin_define
define|#
directive|define
name|CLUST_RSRVD
value|0xfffffff6
end_define

begin_comment
comment|/* reserved cluster range */
end_comment

begin_define
define|#
directive|define
name|CLUST_BAD
value|0xfffffff7
end_define

begin_comment
comment|/* a cluster with a defect */
end_comment

begin_define
define|#
directive|define
name|CLUST_EOFS
value|0xfffffff8
end_define

begin_comment
comment|/* start of eof cluster range */
end_comment

begin_define
define|#
directive|define
name|CLUST_EOFE
value|0xffffffff
end_define

begin_comment
comment|/* end of eof cluster range */
end_comment

begin_define
define|#
directive|define
name|FAT12_MASK
value|0x00000fff
end_define

begin_comment
comment|/* mask for 12 bit cluster numbers */
end_comment

begin_define
define|#
directive|define
name|FAT16_MASK
value|0x0000ffff
end_define

begin_comment
comment|/* mask for 16 bit cluster numbers */
end_comment

begin_define
define|#
directive|define
name|FAT32_MASK
value|0x0fffffff
end_define

begin_comment
comment|/* mask for FAT32 cluster numbers */
end_comment

begin_comment
comment|/*  * MSDOSFS:  * Return true if filesystem uses 12 bit fats. Microsoft Programmer's  * Reference says if the maximum cluster number in a filesystem is greater  * than 4078 ((CLUST_RSRVS - CLUST_FIRST)& FAT12_MASK) then we've got a  * 16 bit fat filesystem. While mounting, the result of this test is stored  * in pm_fatentrysize.  * GEMDOS-flavour (atari):  * If the filesystem is on floppy we've got a 12 bit fat filesystem, otherwise  * 16 bit. We check the d_type field in the disklabel struct while mounting  * and store the result in the pm_fatentrysize. Note that this kind of  * detection gets flakey when mounting a vnd-device.  */
end_comment

begin_define
define|#
directive|define
name|FAT12
parameter_list|(
name|pmp
parameter_list|)
value|(pmp->pm_fatmask == FAT12_MASK)
end_define

begin_define
define|#
directive|define
name|FAT16
parameter_list|(
name|pmp
parameter_list|)
value|(pmp->pm_fatmask == FAT16_MASK)
end_define

begin_define
define|#
directive|define
name|FAT32
parameter_list|(
name|pmp
parameter_list|)
value|(pmp->pm_fatmask == FAT32_MASK)
end_define

begin_define
define|#
directive|define
name|MSDOSFSEOF
parameter_list|(
name|pmp
parameter_list|,
name|cn
parameter_list|)
value|((((cn) | ~(pmp)->pm_fatmask)& CLUST_EOFS) == CLUST_EOFS)
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_comment
comment|/*  * These are the values for the function argument to the function  * fatentry().  */
end_comment

begin_define
define|#
directive|define
name|FAT_GET
value|0x0001
end_define

begin_comment
comment|/* get a fat entry */
end_comment

begin_define
define|#
directive|define
name|FAT_SET
value|0x0002
end_define

begin_comment
comment|/* set a fat entry */
end_comment

begin_define
define|#
directive|define
name|FAT_GET_AND_SET
value|(FAT_GET | FAT_SET)
end_define

begin_comment
comment|/*  * Flags to extendfile:  */
end_comment

begin_define
define|#
directive|define
name|DE_CLEAR
value|1
end_define

begin_comment
comment|/* Zero out the blocks allocated */
end_comment

begin_decl_stmt
name|int
name|pcbmap
name|__P
argument_list|(
operator|(
expr|struct
name|denode
operator|*
name|dep
operator|,
name|u_long
name|findcn
operator|,
name|daddr_t
operator|*
name|bnp
operator|,
name|u_long
operator|*
name|cnp
operator|,
name|int
operator|*
name|sp
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|clusterfree
name|__P
argument_list|(
operator|(
expr|struct
name|msdosfsmount
operator|*
name|pmp
operator|,
name|u_long
name|cn
operator|,
name|u_long
operator|*
name|oldcnp
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|clusteralloc
name|__P
argument_list|(
operator|(
expr|struct
name|msdosfsmount
operator|*
name|pmp
operator|,
name|u_long
name|start
operator|,
name|u_long
name|count
operator|,
name|u_long
name|fillwith
operator|,
name|u_long
operator|*
name|retcluster
operator|,
name|u_long
operator|*
name|got
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|fatentry
name|__P
argument_list|(
operator|(
name|int
name|function
operator|,
expr|struct
name|msdosfsmount
operator|*
name|pmp
operator|,
name|u_long
name|cluster
operator|,
name|u_long
operator|*
name|oldcontents
operator|,
name|u_long
name|newcontents
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|freeclusterchain
name|__P
argument_list|(
operator|(
expr|struct
name|msdosfsmount
operator|*
name|pmp
operator|,
name|u_long
name|startchain
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|extendfile
name|__P
argument_list|(
operator|(
expr|struct
name|denode
operator|*
name|dep
operator|,
name|u_long
name|count
operator|,
expr|struct
name|buf
operator|*
operator|*
name|bpp
operator|,
name|u_long
operator|*
name|ncp
operator|,
name|int
name|flags
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|fc_purge
name|__P
argument_list|(
operator|(
expr|struct
name|denode
operator|*
name|dep
operator|,
name|u_int
name|frcn
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _KERNEL */
end_comment

end_unit

