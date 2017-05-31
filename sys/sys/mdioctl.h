begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1988 University of Utah.  * Copyright (c) 1990, 1993  *	The Regents of the University of California.  All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * the Systems Programming Group of the University of Utah Computer  * Science Department.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * from: Utah $Hdr: fdioctl.h 1.1 90/07/09$  *  *	@(#)vnioctl.h	8.1 (Berkeley) 6/10/93  *  * From: src/sys/sys/vnioctl.h,v 1.4  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_SYS_MDIOCTL_H_
end_ifndef

begin_define
define|#
directive|define
name|_SYS_MDIOCTL_H_
end_define

begin_enum
enum|enum
name|md_types
block|{
name|MD_MALLOC
block|,
name|MD_PRELOAD
block|,
name|MD_VNODE
block|,
name|MD_SWAP
block|,
name|MD_NULL
block|}
enum|;
end_enum

begin_comment
comment|/*  * Ioctl definitions for memory disk pseudo-device.  */
end_comment

begin_define
define|#
directive|define
name|MDNPAD
value|97
end_define

begin_struct
struct|struct
name|md_ioctl
block|{
name|unsigned
name|md_version
decl_stmt|;
comment|/* Structure layout version */
name|unsigned
name|md_unit
decl_stmt|;
comment|/* unit number */
name|enum
name|md_types
name|md_type
decl_stmt|;
comment|/* type of disk */
name|char
modifier|*
name|md_file
decl_stmt|;
comment|/* pathname of file to mount */
name|off_t
name|md_mediasize
decl_stmt|;
comment|/* size of disk in bytes */
name|unsigned
name|md_sectorsize
decl_stmt|;
comment|/* sectorsize */
name|unsigned
name|md_options
decl_stmt|;
comment|/* options */
name|u_int64_t
name|md_base
decl_stmt|;
comment|/* base address */
name|int
name|md_fwheads
decl_stmt|;
comment|/* firmware heads */
name|int
name|md_fwsectors
decl_stmt|;
comment|/* firmware sectors */
name|int
name|md_pad
index|[
name|MDNPAD
index|]
decl_stmt|;
comment|/* padding for future ideas */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|MD_NAME
value|"md"
end_define

begin_define
define|#
directive|define
name|MDCTL_NAME
value|"mdctl"
end_define

begin_define
define|#
directive|define
name|MDIOVERSION
value|0
end_define

begin_comment
comment|/*  * Before you can use a unit, it must be configured with MDIOCSET.  * The configuration persists across opens and closes of the device;  * an MDIOCCLR must be used to reset a configuration.  An attempt to  * MDIOCSET an already active unit will return EBUSY.  */
end_comment

begin_define
define|#
directive|define
name|MDIOCATTACH
value|_IOWR('m', 0, struct md_ioctl)
end_define

begin_comment
comment|/* attach disk */
end_comment

begin_define
define|#
directive|define
name|MDIOCDETACH
value|_IOWR('m', 1, struct md_ioctl)
end_define

begin_comment
comment|/* detach disk */
end_comment

begin_define
define|#
directive|define
name|MDIOCQUERY
value|_IOWR('m', 2, struct md_ioctl)
end_define

begin_comment
comment|/* query status */
end_comment

begin_define
define|#
directive|define
name|MDIOCLIST
value|_IOWR('m', 3, struct md_ioctl)
end_define

begin_comment
comment|/* query status */
end_comment

begin_define
define|#
directive|define
name|MDIOCRESIZE
value|_IOWR('m', 4, struct md_ioctl)
end_define

begin_comment
comment|/* resize disk */
end_comment

begin_define
define|#
directive|define
name|MD_CLUSTER
value|0x01
end_define

begin_comment
comment|/* Don't cluster */
end_comment

begin_define
define|#
directive|define
name|MD_RESERVE
value|0x02
end_define

begin_comment
comment|/* Pre-reserve swap */
end_comment

begin_define
define|#
directive|define
name|MD_AUTOUNIT
value|0x04
end_define

begin_comment
comment|/* Assign next free unit */
end_comment

begin_define
define|#
directive|define
name|MD_READONLY
value|0x08
end_define

begin_comment
comment|/* Readonly mode */
end_comment

begin_define
define|#
directive|define
name|MD_COMPRESS
value|0x10
end_define

begin_comment
comment|/* Compression mode */
end_comment

begin_define
define|#
directive|define
name|MD_FORCE
value|0x20
end_define

begin_comment
comment|/* Don't try to prevent foot-shooting */
end_comment

begin_define
define|#
directive|define
name|MD_ASYNC
value|0x40
end_define

begin_comment
comment|/* Asynchronous mode */
end_comment

begin_define
define|#
directive|define
name|MD_VERIFY
value|0x80
end_define

begin_comment
comment|/* Open file with O_VERIFY (vnode only) */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _SYS_MDIOCTL_H_*/
end_comment

end_unit

