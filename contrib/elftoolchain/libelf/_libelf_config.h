begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2008-2011 Joseph Koshy  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $Id: _libelf_config.h 3400 2016-02-12 18:38:49Z emaste $  */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__APPLE__
argument_list|)
operator|||
name|defined
argument_list|(
name|__DragonFly__
argument_list|)
end_if

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__amd64__
argument_list|)
end_if

begin_define
define|#
directive|define
name|LIBELF_ARCH
value|EM_X86_64
end_define

begin_define
define|#
directive|define
name|LIBELF_BYTEORDER
value|ELFDATA2LSB
end_define

begin_define
define|#
directive|define
name|LIBELF_CLASS
value|ELFCLASS64
end_define

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|__i386__
argument_list|)
end_elif

begin_define
define|#
directive|define
name|LIBELF_ARCH
value|EM_386
end_define

begin_define
define|#
directive|define
name|LIBELF_BYTEORDER
value|ELFDATA2LSB
end_define

begin_define
define|#
directive|define
name|LIBELF_CLASS
value|ELFCLASS32
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __DragonFly__ */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|__FreeBSD__
end_ifdef

begin_comment
comment|/*  * Define LIBELF_{ARCH,BYTEORDER,CLASS} based on the machine architecture.  * See also:<machine/elf.h>.  */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__amd64__
argument_list|)
end_if

begin_define
define|#
directive|define
name|LIBELF_ARCH
value|EM_X86_64
end_define

begin_define
define|#
directive|define
name|LIBELF_BYTEORDER
value|ELFDATA2LSB
end_define

begin_define
define|#
directive|define
name|LIBELF_CLASS
value|ELFCLASS64
end_define

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|__aarch64__
argument_list|)
end_elif

begin_define
define|#
directive|define
name|LIBELF_ARCH
value|EM_AARCH64
end_define

begin_define
define|#
directive|define
name|LIBELF_BYTEORDER
value|ELFDATA2LSB
end_define

begin_define
define|#
directive|define
name|LIBELF_CLASS
value|ELFCLASS64
end_define

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|__arm__
argument_list|)
end_elif

begin_define
define|#
directive|define
name|LIBELF_ARCH
value|EM_ARM
end_define

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__ARMEB__
argument_list|)
end_if

begin_comment
comment|/* Big-endian ARM. */
end_comment

begin_define
define|#
directive|define
name|LIBELF_BYTEORDER
value|ELFDATA2MSB
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|LIBELF_BYTEORDER
value|ELFDATA2LSB
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|LIBELF_CLASS
value|ELFCLASS32
end_define

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|__i386__
argument_list|)
end_elif

begin_define
define|#
directive|define
name|LIBELF_ARCH
value|EM_386
end_define

begin_define
define|#
directive|define
name|LIBELF_BYTEORDER
value|ELFDATA2LSB
end_define

begin_define
define|#
directive|define
name|LIBELF_CLASS
value|ELFCLASS32
end_define

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|__ia64__
argument_list|)
end_elif

begin_define
define|#
directive|define
name|LIBELF_ARCH
value|EM_IA_64
end_define

begin_define
define|#
directive|define
name|LIBELF_BYTEORDER
value|ELFDATA2LSB
end_define

begin_define
define|#
directive|define
name|LIBELF_CLASS
value|ELFCLASS64
end_define

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|__mips__
argument_list|)
end_elif

begin_define
define|#
directive|define
name|LIBELF_ARCH
value|EM_MIPS
end_define

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__MIPSEB__
argument_list|)
end_if

begin_define
define|#
directive|define
name|LIBELF_BYTEORDER
value|ELFDATA2MSB
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|LIBELF_BYTEORDER
value|ELFDATA2LSB
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|LIBELF_CLASS
value|ELFCLASS32
end_define

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|__powerpc__
argument_list|)
end_elif

begin_define
define|#
directive|define
name|LIBELF_ARCH
value|EM_PPC
end_define

begin_define
define|#
directive|define
name|LIBELF_BYTEORDER
value|ELFDATA2MSB
end_define

begin_define
define|#
directive|define
name|LIBELF_CLASS
value|ELFCLASS32
end_define

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|__riscv
argument_list|)
operator|&&
operator|(
name|__riscv_xlen
operator|==
literal|64
operator|)
end_elif

begin_define
define|#
directive|define
name|LIBELF_ARCH
value|EM_RISCV
end_define

begin_define
define|#
directive|define
name|LIBELF_BYTEORDER
value|ELFDATA2LSB
end_define

begin_define
define|#
directive|define
name|LIBELF_CLASS
value|ELFCLASS64
end_define

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|__sparc__
argument_list|)
end_elif

begin_define
define|#
directive|define
name|LIBELF_ARCH
value|EM_SPARCV9
end_define

begin_define
define|#
directive|define
name|LIBELF_BYTEORDER
value|ELFDATA2MSB
end_define

begin_define
define|#
directive|define
name|LIBELF_CLASS
value|ELFCLASS64
end_define

begin_else
else|#
directive|else
end_else

begin_error
error|#
directive|error
error|Unknown FreeBSD architecture.
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __FreeBSD__ */
end_comment

begin_comment
comment|/*  * Definitions for Minix3.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|__minix
end_ifdef

begin_define
define|#
directive|define
name|LIBELF_ARCH
value|EM_386
end_define

begin_define
define|#
directive|define
name|LIBELF_BYTEORDER
value|ELFDATA2LSB
end_define

begin_define
define|#
directive|define
name|LIBELF_CLASS
value|ELFCLASS32
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __minix */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|__NetBSD__
end_ifdef

begin_include
include|#
directive|include
file|<machine/elf_machdep.h>
end_include

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|ARCH_ELFSIZE
argument_list|)
end_if

begin_error
error|#
directive|error
error|ARCH_ELFSIZE is not defined.
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|ARCH_ELFSIZE
operator|==
literal|32
end_if

begin_define
define|#
directive|define
name|LIBELF_ARCH
value|ELF32_MACHDEP_ID
end_define

begin_define
define|#
directive|define
name|LIBELF_BYTEORDER
value|ELF32_MACHDEP_ENDIANNESS
end_define

begin_define
define|#
directive|define
name|LIBELF_CLASS
value|ELFCLASS32
end_define

begin_define
define|#
directive|define
name|Elf_Note
value|Elf32_Nhdr
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|LIBELF_ARCH
value|ELF64_MACHDEP_ID
end_define

begin_define
define|#
directive|define
name|LIBELF_BYTEORDER
value|ELF64_MACHDEP_ENDIANNESS
end_define

begin_define
define|#
directive|define
name|LIBELF_CLASS
value|ELFCLASS64
end_define

begin_define
define|#
directive|define
name|Elf_Note
value|Elf64_Nhdr
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __NetBSD__ */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__OpenBSD__
argument_list|)
end_if

begin_include
include|#
directive|include
file|<machine/exec.h>
end_include

begin_define
define|#
directive|define
name|LIBELF_ARCH
value|ELF_TARG_MACH
end_define

begin_define
define|#
directive|define
name|LIBELF_BYTEORDER
value|ELF_TARG_DATA
end_define

begin_define
define|#
directive|define
name|LIBELF_CLASS
value|ELF_TARG_CLASS
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * GNU& Linux compatibility.  *  * `__linux__' is defined in an environment runs the Linux kernel and glibc.  * `__GNU__' is defined in an environment runs a GNU kernel (Hurd) and glibc.  * `__GLIBC__' is defined for an environment that runs glibc over a non-GNU  *     kernel such as GNU/kFreeBSD.  */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__linux__
argument_list|)
operator|||
name|defined
argument_list|(
name|__GNU__
argument_list|)
operator|||
name|defined
argument_list|(
name|__GLIBC__
argument_list|)
end_if

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__linux__
argument_list|)
end_if

begin_include
include|#
directive|include
file|"native-elf-format.h"
end_include

begin_define
define|#
directive|define
name|LIBELF_CLASS
value|ELFTC_CLASS
end_define

begin_define
define|#
directive|define
name|LIBELF_ARCH
value|ELFTC_ARCH
end_define

begin_define
define|#
directive|define
name|LIBELF_BYTEORDER
value|ELFTC_BYTEORDER
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* defined(__linux__) */
end_comment

begin_if
if|#
directive|if
name|LIBELF_CLASS
operator|==
name|ELFCLASS32
end_if

begin_define
define|#
directive|define
name|Elf_Note
value|Elf32_Nhdr
end_define

begin_elif
elif|#
directive|elif
name|LIBELF_CLASS
operator|==
name|ELFCLASS64
end_elif

begin_define
define|#
directive|define
name|Elf_Note
value|Elf64_Nhdr
end_define

begin_else
else|#
directive|else
end_else

begin_error
error|#
directive|error
error|LIBELF_CLASS needs to be one of ELFCLASS32 or ELFCLASS64
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* defined(__linux__) || defined(__GNU__) || defined(__GLIBC__) */
end_comment

end_unit

