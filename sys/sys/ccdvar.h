begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $FreeBSD$ */
end_comment

begin_comment
comment|/*	$NetBSD: ccdvar.h,v 1.7.2.1 1995/10/12 21:30:18 thorpej Exp $	*/
end_comment

begin_comment
comment|/*  * Copyright (c) 1995 Jason R. Thorpe.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed for the NetBSD Project  *	by Jason R. Thorpe.  * 4. The name of the author may not be used to endorse or promote products  *    derived from this software without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,  * BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;  * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED  * AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,  * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
end_comment

begin_comment
comment|/*  * Copyright (c) 1988 University of Utah.  * Copyright (c) 1990, 1993  *	The Regents of the University of California.  All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * the Systems Programming Group of the University of Utah Computer  * Science Department.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * from: Utah $Hdr: cdvar.h 1.1 90/07/09$  *  *	@(#)cdvar.h	8.1 (Berkeley) 6/10/93  */
end_comment

begin_comment
comment|/*  * Dynamic configuration and disklabel support by:  *	Jason R. Thorpe<thorpej@nas.nasa.gov>  *	Numerical Aerodynamic Simulation Facility  *	Mail Stop 258-6  *	NASA Ames Research Center  *	Moffett Field, CA 94035  */
end_comment

begin_comment
comment|/*  * A concatenated disk is described at initialization time by this structure.  */
end_comment

begin_struct
struct|struct
name|ccddevice
block|{
name|int
name|ccd_unit
decl_stmt|;
comment|/* logical unit of this ccd */
name|int
name|ccd_interleave
decl_stmt|;
comment|/* interleave (DEV_BSIZE blocks) */
name|int
name|ccd_flags
decl_stmt|;
comment|/* misc. information */
name|int
name|ccd_dk
decl_stmt|;
comment|/* disk number */
name|struct
name|vnode
modifier|*
modifier|*
name|ccd_vpp
decl_stmt|;
comment|/* array of component vnodes */
name|char
modifier|*
modifier|*
name|ccd_cpp
decl_stmt|;
comment|/* array of component pathnames */
name|int
name|ccd_ndev
decl_stmt|;
comment|/* number of component devices */
block|}
struct|;
end_struct

begin_comment
comment|/*  * This structure is used to configure a ccd via ioctl(2).  */
end_comment

begin_struct
struct|struct
name|ccd_ioctl
block|{
name|char
modifier|*
modifier|*
name|ccio_disks
decl_stmt|;
comment|/* pointer to component paths */
name|u_int
name|ccio_ndisks
decl_stmt|;
comment|/* number of disks to concatenate */
name|int
name|ccio_ileave
decl_stmt|;
comment|/* interleave (DEV_BSIZE blocks) */
name|int
name|ccio_flags
decl_stmt|;
comment|/* misc. information */
name|int
name|ccio_unit
decl_stmt|;
comment|/* unit number: use varies */
name|size_t
name|ccio_size
decl_stmt|;
comment|/* (returned) size of ccd */
block|}
struct|;
end_struct

begin_comment
comment|/* ccd_flags */
end_comment

begin_define
define|#
directive|define
name|CCDF_SWAP
value|0x01
end_define

begin_comment
comment|/* interleave should be dmmax */
end_comment

begin_define
define|#
directive|define
name|CCDF_UNIFORM
value|0x02
end_define

begin_comment
comment|/* use LCCD of sizes for uniform interleave */
end_comment

begin_define
define|#
directive|define
name|CCDF_MIRROR
value|0x04
end_define

begin_comment
comment|/* use mirroring */
end_comment

begin_define
define|#
directive|define
name|CCDF_PARITY
value|0x08
end_define

begin_comment
comment|/* use parity (RAID level 5) */
end_comment

begin_comment
comment|/* Mask of user-settable ccd flags. */
end_comment

begin_define
define|#
directive|define
name|CCDF_USERMASK
value|(CCDF_SWAP|CCDF_UNIFORM|CCDF_MIRROR|CCDF_PARITY)
end_define

begin_comment
comment|/*  * Component info table.  * Describes a single component of a concatenated disk.  */
end_comment

begin_struct
struct|struct
name|ccdcinfo
block|{
name|struct
name|vnode
modifier|*
name|ci_vp
decl_stmt|;
comment|/* device's vnode */
name|dev_t
name|ci_dev
decl_stmt|;
comment|/* XXX: device's dev_t */
name|size_t
name|ci_size
decl_stmt|;
comment|/* size */
name|char
modifier|*
name|ci_path
decl_stmt|;
comment|/* path to component */
name|size_t
name|ci_pathlen
decl_stmt|;
comment|/* length of component path */
block|}
struct|;
end_struct

begin_comment
comment|/*  * Interleave description table.  * Computed at boot time to speed irregular-interleave lookups.  * The idea is that we interleave in "groups".  First we interleave  * evenly over all component disks up to the size of the smallest  * component (the first group), then we interleave evenly over all  * remaining disks up to the size of the next-smallest (second group),  * and so on.  *  * Each table entry describes the interleave characteristics of one  * of these groups.  For example if a concatenated disk consisted of  * three components of 5, 3, and 7 DEV_BSIZE blocks interleaved at  * DEV_BSIZE (1), the table would have three entries:  *  *	ndisk	startblk	startoff	dev  *	3	0		0		0, 1, 2  *	2	9		3		0, 2  *	1	13		5		2  *	0	-		-		-  *  * which says that the first nine blocks (0-8) are interleaved over  * 3 disks (0, 1, 2) starting at block offset 0 on any component disk,  * the next 4 blocks (9-12) are interleaved over 2 disks (0, 2) starting  * at component block 3, and the remaining blocks (13-14) are on disk  * 2 starting at offset 5.  */
end_comment

begin_struct
struct|struct
name|ccdiinfo
block|{
name|int
name|ii_ndisk
decl_stmt|;
comment|/* # of disks range is interleaved over */
name|daddr_t
name|ii_startblk
decl_stmt|;
comment|/* starting scaled block # for range */
name|daddr_t
name|ii_startoff
decl_stmt|;
comment|/* starting component offset (block #) */
name|int
modifier|*
name|ii_index
decl_stmt|;
comment|/* ordered list of components in range */
block|}
struct|;
end_struct

begin_comment
comment|/*  * Concatenated disk pseudo-geometry information.  */
end_comment

begin_struct
struct|struct
name|ccdgeom
block|{
name|u_int32_t
name|ccg_secsize
decl_stmt|;
comment|/* # bytes per sector */
name|u_int32_t
name|ccg_nsectors
decl_stmt|;
comment|/* # data sectors per track */
name|u_int32_t
name|ccg_ntracks
decl_stmt|;
comment|/* # tracks per cylinder */
name|u_int32_t
name|ccg_ncylinders
decl_stmt|;
comment|/* # cylinders per unit */
block|}
struct|;
end_struct

begin_comment
comment|/*  * A concatenated disk is described after initialization by this structure.  */
end_comment

begin_struct
struct|struct
name|ccd_softc
block|{
name|int
name|sc_unit
decl_stmt|;
comment|/* logical unit number */
name|int
name|sc_flags
decl_stmt|;
comment|/* flags */
name|int
name|sc_cflags
decl_stmt|;
comment|/* configuration flags */
name|size_t
name|sc_size
decl_stmt|;
comment|/* size of ccd */
name|int
name|sc_ileave
decl_stmt|;
comment|/* interleave */
name|u_int
name|sc_nccdisks
decl_stmt|;
comment|/* number of components */
define|#
directive|define
name|CCD_MAXNDISKS
value|65536
name|struct
name|ccdcinfo
modifier|*
name|sc_cinfo
decl_stmt|;
comment|/* component info */
name|struct
name|ccdiinfo
modifier|*
name|sc_itable
decl_stmt|;
comment|/* interleave table */
name|struct
name|devstat
name|device_stats
decl_stmt|;
comment|/* device statistics */
name|struct
name|ccdgeom
name|sc_geom
decl_stmt|;
comment|/* pseudo geometry info */
name|struct
name|disklabel
name|sc_label
decl_stmt|;
comment|/* generic disk device info */
name|int
name|sc_openmask
decl_stmt|;
name|int
name|sc_pick
decl_stmt|;
comment|/* side of mirror picked */
name|daddr_t
name|sc_blk
index|[
literal|2
index|]
decl_stmt|;
comment|/* mirror localization */
block|}
struct|;
end_struct

begin_comment
comment|/* sc_flags */
end_comment

begin_define
define|#
directive|define
name|CCDF_INITED
value|0x01
end_define

begin_comment
comment|/* unit has been initialized */
end_comment

begin_define
define|#
directive|define
name|CCDF_WLABEL
value|0x02
end_define

begin_comment
comment|/* label area is writable */
end_comment

begin_define
define|#
directive|define
name|CCDF_LABELLING
value|0x04
end_define

begin_comment
comment|/* unit is currently being labelled */
end_comment

begin_define
define|#
directive|define
name|CCDF_WANTED
value|0x40
end_define

begin_comment
comment|/* someone is waiting to obtain a lock */
end_comment

begin_define
define|#
directive|define
name|CCDF_LOCKED
value|0x80
end_define

begin_comment
comment|/* unit is locked */
end_comment

begin_comment
comment|/*  * Before you can use a unit, it must be configured with CCDIOCSET.  * The configuration persists across opens and closes of the device;  * a CCDIOCCLR must be used to reset a configuration.  An attempt to  * CCDIOCSET an already active unit will return EBUSY.  Attempts to  * CCDIOCCLR an inactive unit will return ENXIO.  */
end_comment

begin_define
define|#
directive|define
name|CCDIOCSET
value|_IOWR('F', 16, struct ccd_ioctl)
end_define

begin_comment
comment|/* enable ccd */
end_comment

begin_define
define|#
directive|define
name|CCDIOCCLR
value|_IOW('F', 17, struct ccd_ioctl)
end_define

begin_comment
comment|/* disable ccd */
end_comment

end_unit

