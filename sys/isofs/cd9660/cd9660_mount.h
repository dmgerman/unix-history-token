begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1995  *	The Regents of the University of California.  All rights reserved.  *  * This code is derived from software contributed to Berkeley  * by Pace Willisson (pace@blitz.com).  The Rock Ridge Extension  * Support code is derived from software contributed to Berkeley  * by Atsushi Murai (amurai@spec.co.jp).  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)cd9660_mount.h	8.1 (Berkeley) 5/24/95  * $FreeBSD$  */
end_comment

begin_comment
comment|/*  * Arguments to mount ISO 9660 filesystems.  */
end_comment

begin_struct
struct|struct
name|iso_args
block|{
name|char
modifier|*
name|fspec
decl_stmt|;
comment|/* block special device to mount */
name|struct
name|export_args
name|export
decl_stmt|;
comment|/* network export info */
name|int
name|flags
decl_stmt|;
comment|/* mounting flags, see below */
name|int
name|ssector
decl_stmt|;
comment|/* starting sector, 0 for 1st session */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|ISOFSMNT_NORRIP
value|0x00000001
end_define

begin_comment
comment|/* disable Rock Ridge Ext.*/
end_comment

begin_define
define|#
directive|define
name|ISOFSMNT_GENS
value|0x00000002
end_define

begin_comment
comment|/* enable generation numbers */
end_comment

begin_define
define|#
directive|define
name|ISOFSMNT_EXTATT
value|0x00000004
end_define

begin_comment
comment|/* enable extended attributes */
end_comment

begin_define
define|#
directive|define
name|ISOFSMNT_NOJOLIET
value|0x00000008
end_define

begin_comment
comment|/* disable Joliet Ext.*/
end_comment

begin_define
define|#
directive|define
name|ISOFSMNT_BROKENJOLIET
value|0x00000010
end_define

begin_comment
comment|/* allow broken Joliet disks */
end_comment

end_unit

