begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1998 Michael Smith<msmith@freebsd.org>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_include
include|#
directive|include
file|<stand.h>
end_include

begin_include
include|#
directive|include
file|<bootstrap.h>
end_include

begin_include
include|#
directive|include
file|"libi386/libi386.h"
end_include

begin_comment
comment|/*  * We could use linker sets for some or all of these, but  * then we would have to control what ended up linked into  * the bootstrap.  So it's easier to conditionalise things  * here.  *  * XXX rename these arrays to be consistent and less namespace-hostile  *  * XXX as libi386 and biosboot merge, some of these can become linker sets.  */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|LOADER_NFS_SUPPORT
argument_list|)
operator|&&
name|defined
argument_list|(
name|LOADER_TFTP_SUPPORT
argument_list|)
end_if

begin_error
error|#
directive|error
literal|"Cannot have both tftp and nfs support yet."
end_error

begin_endif
endif|#
directive|endif
end_endif

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
name|biosdisk
block|,
if|#
directive|if
name|defined
argument_list|(
name|LOADER_NFS_SUPPORT
argument_list|)
operator|||
name|defined
argument_list|(
name|LOADER_TFTP_SUPPORT
argument_list|)
operator|&
name|pxedisk
block|,
endif|#
directive|endif
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
name|ufs_fsops
block|,
operator|&
name|ext2fs_fsops
block|,
operator|&
name|dosfs_fsops
block|,
operator|&
name|zipfs_fsops
block|,
ifdef|#
directive|ifdef
name|LOADER_NFS_SUPPORT
operator|&
name|nfs_fsops
block|,
endif|#
directive|endif
ifdef|#
directive|ifdef
name|LOADER_TFTP_SUPPORT
operator|&
name|tftp_fsops
block|,
endif|#
directive|endif
name|NULL
block|}
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Exported for i386 only */
end_comment

begin_comment
comment|/*   * Sort formats so that those that can detect based on arguments  * rather than reading the file go first.  */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|module_format
name|i386_aout
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|module_format
name|i386_elf
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|module_format
modifier|*
name|module_formats
index|[]
init|=
block|{
operator|&
name|i386_elf
block|,
operator|&
name|i386_aout
block|,
name|NULL
block|}
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*   * Consoles   *  * We don't prototype these in libi386.h because they require  * data structures from bootstrap.h as well.  */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|console
name|vidconsole
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|console
name|comconsole
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|console
name|nullconsole
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
name|vidconsole
block|,
operator|&
name|comconsole
block|,
operator|&
name|nullconsole
block|,
name|NULL
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|pnphandler
name|isapnphandler
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|pnphandler
name|biospnphandler
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|pnphandler
name|biospcihandler
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|pnphandler
modifier|*
name|pnphandlers
index|[]
init|=
block|{
operator|&
name|biospnphandler
block|,
comment|/* should go first, as it may set isapnp_readport */
operator|&
name|isapnphandler
block|,
operator|&
name|biospcihandler
block|,
name|NULL
block|}
decl_stmt|;
end_decl_stmt

end_unit

