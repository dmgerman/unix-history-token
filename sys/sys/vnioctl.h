begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1988 University of Utah.  * Copyright (c) 1990, 1993  *	The Regents of the University of California.  All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * the Systems Programming Group of the University of Utah Computer  * Science Department.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * from: Utah $Hdr: fdioctl.h 1.1 90/07/09$  *  *	@(#)vnioctl.h	8.1 (Berkeley) 6/10/93  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_SYS_VNIOCTL_H_
end_ifndef

begin_define
define|#
directive|define
name|_SYS_VNIOCTL_H_
end_define

begin_comment
comment|/*  * Ioctl definitions for file (vnode) disk pseudo-device.  */
end_comment

begin_define
define|#
directive|define
name|_PATH_VNTAB
value|"/etc/vntab"
end_define

begin_comment
comment|/* default config file */
end_comment

begin_struct
struct|struct
name|vn_ioctl
block|{
name|char
modifier|*
name|vn_file
decl_stmt|;
comment|/* pathname of file to mount */
name|int
name|vn_size
decl_stmt|;
comment|/* (returned) size of disk */
block|}
struct|;
end_struct

begin_comment
comment|/*  * Before you can use a unit, it must be configured with VNIOCSET.  * The configuration persists across opens and closes of the device;  * an VNIOCCLR must be used to reset a configuration.  An attempt to  * VNIOCSET an already active unit will return EBUSY.  */
end_comment

begin_define
define|#
directive|define
name|VNIOCATTACH
value|_IOWR('F', 0, struct vn_ioctl)
end_define

begin_comment
comment|/* attach file */
end_comment

begin_define
define|#
directive|define
name|VNIOCDETACH
value|_IOWR('F', 1, struct vn_ioctl)
end_define

begin_comment
comment|/* detach disk */
end_comment

begin_define
define|#
directive|define
name|VNIOCGSET
value|_IOWR('F', 2, u_long )
end_define

begin_comment
comment|/* set global option */
end_comment

begin_define
define|#
directive|define
name|VNIOCGCLEAR
value|_IOWR('F', 3, u_long )
end_define

begin_comment
comment|/* reset --//-- */
end_comment

begin_define
define|#
directive|define
name|VNIOCUSET
value|_IOWR('F', 4, u_long )
end_define

begin_comment
comment|/* set unit option */
end_comment

begin_define
define|#
directive|define
name|VNIOCUCLEAR
value|_IOWR('F', 5, u_long )
end_define

begin_comment
comment|/* reset --//-- */
end_comment

begin_define
define|#
directive|define
name|VN_LABELS
value|0x1
end_define

begin_comment
comment|/* Use disk(/slice) labels */
end_comment

begin_define
define|#
directive|define
name|VN_FOLLOW
value|0x2
end_define

begin_comment
comment|/* Debug flow in vn driver */
end_comment

begin_define
define|#
directive|define
name|VN_DEBUG
value|0x4
end_define

begin_comment
comment|/* Debug data in vn driver */
end_comment

begin_define
define|#
directive|define
name|VN_IO
value|0x8
end_define

begin_comment
comment|/* Debug I/O in vn driver */
end_comment

begin_define
define|#
directive|define
name|VN_DONTCLUSTER
value|0x10
end_define

begin_comment
comment|/* Don't cluster */
end_comment

begin_define
define|#
directive|define
name|VN_RESERVE
value|0x20
end_define

begin_comment
comment|/* Pre-reserve swap */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _SYS_VNIOCTL_H_*/
end_comment

end_unit

