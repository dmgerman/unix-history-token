begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2012 Olivier Houchard<cognet@FreeBSD.org>  * Copyright (c) 2012 Baptiste Daroussin<bapt@FreeBSD.org>  * All rights reserved.  *   * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *   * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|ELF_TABLES_H_
end_ifndef

begin_define
define|#
directive|define
name|ELF_TABLES_H_
end_define

begin_struct
struct|struct
name|_elf_corres
block|{
name|int
name|elf_nb
decl_stmt|;
specifier|const
name|char
modifier|*
name|string
decl_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
specifier|static
name|struct
name|_elf_corres
name|mach_corres
index|[]
init|=
block|{
block|{
name|EM_386
block|,
literal|"x86"
block|}
block|,
block|{
name|EM_AMD64
block|,
literal|"x86"
block|}
block|,
block|{
name|EM_ARM
block|,
literal|"arm"
block|}
block|,
block|{
name|EM_MIPS
block|,
literal|"mips"
block|}
block|,
block|{
name|EM_PPC
block|,
literal|"powerpc"
block|}
block|,
block|{
name|EM_PPC64
block|,
literal|"powerpc"
block|}
block|,
block|{
name|EM_SPARCV9
block|,
literal|"sparc64"
block|}
block|,
block|{
operator|-
literal|1
block|,
name|NULL
block|}
block|, }
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|struct
name|_elf_corres
name|wordsize_corres
index|[]
init|=
block|{
block|{
name|ELFCLASS32
block|,
literal|"32"
block|}
block|,
block|{
name|ELFCLASS64
block|,
literal|"64"
block|}
block|,
block|{
operator|-
literal|1
block|,
name|NULL
block|}
block|, }
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|struct
name|_elf_corres
name|endian_corres
index|[]
init|=
block|{
block|{
name|ELFDATA2MSB
block|,
literal|"eb"
block|}
block|,
block|{
name|ELFDATA2LSB
block|,
literal|"el"
block|}
block|,
block|{
operator|-
literal|1
block|,
name|NULL
block|}
block|}
decl_stmt|;
end_decl_stmt

begin_ifndef
ifndef|#
directive|ifndef
name|EF_MIPS_ABI
end_ifndef

begin_define
define|#
directive|define
name|EF_MIPS_ABI
value|0x0000f000
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|E_MIPS_ABI_O32
value|0x00001000
end_define

begin_define
define|#
directive|define
name|E_MIPS_ABI_N32
value|0x00000020
end_define

begin_define
define|#
directive|define
name|NT_VERSION
value|1
end_define

begin_define
define|#
directive|define
name|NT_ARCH
value|2
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ELF_TABLES_H_ */
end_comment

end_unit

