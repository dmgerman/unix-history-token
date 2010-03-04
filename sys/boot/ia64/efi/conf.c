begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1997  *	Matthias Drochner.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed for the NetBSD Project  *	by Matthias Drochner.  * 4. The name of the author may not be used to endorse or promote products  *    derived from this software without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  *	$NetBSD: conf.c,v 1.2 1997/03/22 09:03:29 thorpej Exp $	   */
end_comment

begin_include
include|#
directive|include
file|<sys/cdefs.h>
end_include

begin_expr_stmt
name|__FBSDID
argument_list|(
literal|"$FreeBSD$"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_include
include|#
directive|include
file|<stand.h>
end_include

begin_include
include|#
directive|include
file|<efi.h>
end_include

begin_include
include|#
directive|include
file|<efilib.h>
end_include

begin_comment
comment|/*  * We could use linker sets for some or all of these, but  * then we would have to control what ended up linked into  * the bootstrap.  So it's easier to conditionalise things  * here.  *  * XXX rename these arrays to be consistent and less namespace-hostile  */
end_comment

begin_comment
comment|/* Exported for libstand */
end_comment

begin_decl_stmt
name|struct
name|devsw
modifier|*
name|devsw
index|[]
init|=
block|{
operator|&
name|efipart_dev
block|,
operator|&
name|efinet_dev
block|,
name|NULL
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|fs_ops
modifier|*
name|file_system
index|[]
init|=
block|{
operator|&
name|dosfs_fsops
block|,
operator|&
name|ufs_fsops
block|,
operator|&
name|cd9660_fsops
block|,
operator|&
name|nfs_fsops
block|,
operator|&
name|gzipfs_fsops
block|,
name|NULL
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|netif_driver
modifier|*
name|netif_drivers
index|[]
init|=
block|{
operator|&
name|efinetif
block|,
name|NULL
block|}
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*   * Sort formats so that those that can detect based on arguments  * rather than reading the file go first.  */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|file_format
name|ia64_elf
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|file_format
modifier|*
name|file_formats
index|[]
init|=
block|{
operator|&
name|ia64_elf
block|,
name|NULL
block|}
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*   * Consoles   *  * We don't prototype these in efiboot.h because they require  * data structures from bootstrap.h as well.  */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|console
name|efi_console
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|console
modifier|*
name|consoles
index|[]
init|=
block|{
operator|&
name|efi_console
block|,
name|NULL
block|}
decl_stmt|;
end_decl_stmt

end_unit

