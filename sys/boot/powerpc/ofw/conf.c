begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1999 Michael Smith<msmith@freebsd.org>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	$FreeBSD$  */
end_comment

begin_include
include|#
directive|include
file|<stand.h>
end_include

begin_include
include|#
directive|include
file|"libofw.h"
end_include

begin_if
if|#
directive|if
name|defined
argument_list|(
name|LOADER_NET_SUPPORT
argument_list|)
end_if

begin_include
include|#
directive|include
file|"dev_net.h"
end_include

begin_endif
endif|#
directive|endif
end_endif

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
if|#
directive|if
name|defined
argument_list|(
name|LOADER_DISK_SUPPORT
argument_list|)
operator|||
name|defined
argument_list|(
name|LOADER_CDROM_SUPPORT
argument_list|)
operator|&
name|ofwdisk
block|,
endif|#
directive|endif
if|#
directive|if
name|defined
argument_list|(
name|LOADER_NET_SUPPORT
argument_list|)
operator|&
name|ofwnet
block|,
operator|&
name|ofwnet
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
ifdef|#
directive|ifdef
name|LOADER_UFS_SUPPORT
operator|&
name|ufs_fsops
block|,
endif|#
directive|endif
ifdef|#
directive|ifdef
name|LOADER_CDROM_SUPPORT
operator|&
name|cd9660_fsops
block|,
endif|#
directive|endif
ifdef|#
directive|ifdef
name|LOADER_EXT2FS_SUPPORT
operator|&
name|ext2fs_fsops
block|,
endif|#
directive|endif
ifdef|#
directive|ifdef
name|LOADER_NET_SUPPORT
operator|&
name|nfs_fsops
block|,
endif|#
directive|endif
operator|&
name|zipfs_fsops
block|,
name|NULL
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|netif_driver
name|of_net
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
ifdef|#
directive|ifdef
name|LOADER_NET_SUPPORT
operator|&
name|of_net
block|,
endif|#
directive|endif
name|NULL
block|, }
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Exported for PowerPC only */
end_comment

begin_comment
comment|/*   * Sort formats so that those that can detect based on arguments  * rather than reading the file go first.  */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|file_format
name|powerpc_elf
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
comment|/*&powerpc_elf,*/
name|NULL
block|}
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*   * Consoles   *  * We don't prototype these in libalpha.h because they require  * data structures from bootstrap.h as well.  */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|console
name|ofwconsole
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
name|ofwconsole
block|,
name|NULL
block|}
decl_stmt|;
end_decl_stmt

end_unit

