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
comment|/* sc_flags */
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
name|CCDF_INITED
value|0x10
end_define

begin_comment
comment|/* unit has been initialized */
end_comment

begin_define
define|#
directive|define
name|CCDF_WLABEL
value|0x20
end_define

begin_comment
comment|/* label area is writable */
end_comment

begin_define
define|#
directive|define
name|CCDF_LABELLING
value|0x40
end_define

begin_comment
comment|/* unit is currently being labelled */
end_comment

begin_define
define|#
directive|define
name|CCDF_WANTED
value|0x60
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
comment|/* Mask of user-settable ccd flags. */
end_comment

begin_define
define|#
directive|define
name|CCDF_USERMASK
value|(CCDF_UNIFORM|CCDF_MIRROR)
end_define

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

