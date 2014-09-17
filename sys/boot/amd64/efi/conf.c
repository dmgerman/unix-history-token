begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2006 Marcel Moolenaar  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  *  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  */
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
file|<bootstrap.h>
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

begin_decl_stmt
specifier|extern
name|struct
name|file_format
name|amd64_elf
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|file_format
name|amd64_elf_obj
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
name|amd64_elf
block|,
operator|&
name|amd64_elf_obj
block|,
name|NULL
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|console
name|efi_console
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
name|efi_console
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

end_unit

