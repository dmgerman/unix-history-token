begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1996-1997 John D. Polstra.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_MACHINE_ELF_H_
end_ifndef

begin_define
define|#
directive|define
name|_MACHINE_ELF_H_
value|1
end_define

begin_comment
comment|/*  * ELF definitions for the i386 architecture.  */
end_comment

begin_include
include|#
directive|include
file|<sys/elf32.h>
end_include

begin_comment
comment|/* Definitions common to all 32 bit architectures. */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__ELF_WORD_SIZE
argument_list|)
operator|&&
name|__ELF_WORD_SIZE
operator|==
literal|64
end_if

begin_include
include|#
directive|include
file|<sys/elf64.h>
end_include

begin_comment
comment|/* Definitions common to all 64 bit architectures. */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|__ELF_WORD_SIZE
end_ifndef

begin_define
define|#
directive|define
name|__ELF_WORD_SIZE
value|32
end_define

begin_comment
comment|/* Used by<sys/elf_generic.h> */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<sys/elf_generic.h>
end_include

begin_define
define|#
directive|define
name|ELF_ARCH
value|EM_386
end_define

begin_define
define|#
directive|define
name|ELF_MACHINE_OK
parameter_list|(
name|x
parameter_list|)
value|((x) == EM_386 || (x) == EM_486)
end_define

begin_comment
comment|/*  * Auxiliary vector entries for passing information to the interpreter.  *  * The i386 supplement to the SVR4 ABI specification names this "auxv_t",  * but POSIX lays claim to all symbols ending with "_t".  */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
comment|/* Auxiliary vector entry on initial stack */
name|int
name|a_type
decl_stmt|;
comment|/* Entry type. */
union|union
block|{
name|long
name|a_val
decl_stmt|;
comment|/* Integer value. */
name|void
modifier|*
name|a_ptr
decl_stmt|;
comment|/* Address. */
name|void
function_decl|(
modifier|*
name|a_fcn
function_decl|)
parameter_list|(
name|void
parameter_list|)
function_decl|;
comment|/* Function pointer (not used). */
block|}
name|a_un
union|;
block|}
name|Elf32_Auxinfo
typedef|;
end_typedef

begin_if
if|#
directive|if
name|__ELF_WORD_SIZE
operator|==
literal|64
end_if

begin_comment
comment|/* Fake for amd64 loader support */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|int
name|fake
decl_stmt|;
block|}
name|Elf64_Auxinfo
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_expr_stmt
name|__ElfType
argument_list|(
name|Auxinfo
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* Values for a_type. */
end_comment

begin_define
define|#
directive|define
name|AT_NULL
value|0
end_define

begin_comment
comment|/* Terminates the vector. */
end_comment

begin_define
define|#
directive|define
name|AT_IGNORE
value|1
end_define

begin_comment
comment|/* Ignored entry. */
end_comment

begin_define
define|#
directive|define
name|AT_EXECFD
value|2
end_define

begin_comment
comment|/* File descriptor of program to load. */
end_comment

begin_define
define|#
directive|define
name|AT_PHDR
value|3
end_define

begin_comment
comment|/* Program header of program already loaded. */
end_comment

begin_define
define|#
directive|define
name|AT_PHENT
value|4
end_define

begin_comment
comment|/* Size of each program header entry. */
end_comment

begin_define
define|#
directive|define
name|AT_PHNUM
value|5
end_define

begin_comment
comment|/* Number of program header entries. */
end_comment

begin_define
define|#
directive|define
name|AT_PAGESZ
value|6
end_define

begin_comment
comment|/* Page size in bytes. */
end_comment

begin_define
define|#
directive|define
name|AT_BASE
value|7
end_define

begin_comment
comment|/* Interpreter's base address. */
end_comment

begin_define
define|#
directive|define
name|AT_FLAGS
value|8
end_define

begin_comment
comment|/* Flags (unused for i386). */
end_comment

begin_define
define|#
directive|define
name|AT_ENTRY
value|9
end_define

begin_comment
comment|/* Where interpreter should transfer control. */
end_comment

begin_define
define|#
directive|define
name|AT_NOTELF
value|10
end_define

begin_comment
comment|/* Program is not ELF ?? */
end_comment

begin_define
define|#
directive|define
name|AT_UID
value|11
end_define

begin_comment
comment|/* Real uid. */
end_comment

begin_define
define|#
directive|define
name|AT_EUID
value|12
end_define

begin_comment
comment|/* Effective uid. */
end_comment

begin_define
define|#
directive|define
name|AT_GID
value|13
end_define

begin_comment
comment|/* Real gid. */
end_comment

begin_define
define|#
directive|define
name|AT_EGID
value|14
end_define

begin_comment
comment|/* Effective gid. */
end_comment

begin_define
define|#
directive|define
name|AT_EXECPATH
value|15
end_define

begin_comment
comment|/* Path to the executable. */
end_comment

begin_define
define|#
directive|define
name|AT_COUNT
value|16
end_define

begin_comment
comment|/* Count of defined aux entry types. */
end_comment

begin_comment
comment|/*  * Relocation types.  */
end_comment

begin_define
define|#
directive|define
name|R_386_COUNT
value|38
end_define

begin_comment
comment|/* Count of defined relocation types. */
end_comment

begin_comment
comment|/* Define "machine" characteristics */
end_comment

begin_define
define|#
directive|define
name|ELF_TARG_CLASS
value|ELFCLASS32
end_define

begin_define
define|#
directive|define
name|ELF_TARG_DATA
value|ELFDATA2LSB
end_define

begin_define
define|#
directive|define
name|ELF_TARG_MACH
value|EM_386
end_define

begin_define
define|#
directive|define
name|ELF_TARG_VER
value|1
end_define

begin_define
define|#
directive|define
name|ET_DYN_LOAD_ADDR
value|0x01001000
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_MACHINE_ELF_H_ */
end_comment

end_unit

