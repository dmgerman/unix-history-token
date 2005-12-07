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
comment|/*  * ELF definitions for the sparc64 architecture.  */
end_comment

begin_include
include|#
directive|include
file|<sys/elf32.h>
end_include

begin_comment
comment|/* Definitions common to all 32 bit architectures. */
end_comment

begin_include
include|#
directive|include
file|<sys/elf64.h>
end_include

begin_comment
comment|/* Definitions common to all 64 bit architectures. */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__ELF_WORD_SIZE
end_ifndef

begin_define
define|#
directive|define
name|__ELF_WORD_SIZE
value|64
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
value|EM_SPARCV9
end_define

begin_define
define|#
directive|define
name|ELF_MACHINE_OK
parameter_list|(
name|x
parameter_list|)
value|((x) == ELF_ARCH)
end_define

begin_comment
comment|/*  * Auxiliary vector entries for passing information to the interpreter.  */
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
name|int
name|a_val
decl_stmt|;
comment|/* Integer value. */
block|}
name|a_un
union|;
block|}
name|Elf32_Auxinfo
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
comment|/* Auxiliary vector entry on initial stack */
name|long
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
name|Elf64_Auxinfo
typedef|;
end_typedef

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
comment|/* Flags (unused). */
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

begin_comment
comment|/*  * The following non-standard values are used for passing information  * from John Polstra's testbed program to the dynamic linker.  These  * are expected to go away soon.  *  * Unfortunately, these overlap the Linux non-standard values, so they  * must not be used in the same context.  */
end_comment

begin_define
define|#
directive|define
name|AT_BRK
value|10
end_define

begin_comment
comment|/* Starting point for sbrk and brk. */
end_comment

begin_define
define|#
directive|define
name|AT_DEBUG
value|11
end_define

begin_comment
comment|/* Debugging level. */
end_comment

begin_comment
comment|/*  * The following non-standard values are used in Linux ELF binaries.  */
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
name|AT_COUNT
value|15
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
name|R_SPARC_NONE
value|0
end_define

begin_define
define|#
directive|define
name|R_SPARC_8
value|1
end_define

begin_define
define|#
directive|define
name|R_SPARC_16
value|2
end_define

begin_define
define|#
directive|define
name|R_SPARC_32
value|3
end_define

begin_define
define|#
directive|define
name|R_SPARC_DISP8
value|4
end_define

begin_define
define|#
directive|define
name|R_SPARC_DISP16
value|5
end_define

begin_define
define|#
directive|define
name|R_SPARC_DISP32
value|6
end_define

begin_define
define|#
directive|define
name|R_SPARC_WDISP30
value|7
end_define

begin_define
define|#
directive|define
name|R_SPARC_WDISP22
value|8
end_define

begin_define
define|#
directive|define
name|R_SPARC_HI22
value|9
end_define

begin_define
define|#
directive|define
name|R_SPARC_22
value|10
end_define

begin_define
define|#
directive|define
name|R_SPARC_13
value|11
end_define

begin_define
define|#
directive|define
name|R_SPARC_LO10
value|12
end_define

begin_define
define|#
directive|define
name|R_SPARC_GOT10
value|13
end_define

begin_define
define|#
directive|define
name|R_SPARC_GOT13
value|14
end_define

begin_define
define|#
directive|define
name|R_SPARC_GOT22
value|15
end_define

begin_define
define|#
directive|define
name|R_SPARC_PC10
value|16
end_define

begin_define
define|#
directive|define
name|R_SPARC_PC22
value|17
end_define

begin_define
define|#
directive|define
name|R_SPARC_WPLT30
value|18
end_define

begin_define
define|#
directive|define
name|R_SPARC_COPY
value|19
end_define

begin_define
define|#
directive|define
name|R_SPARC_GLOB_DAT
value|20
end_define

begin_define
define|#
directive|define
name|R_SPARC_JMP_SLOT
value|21
end_define

begin_define
define|#
directive|define
name|R_SPARC_RELATIVE
value|22
end_define

begin_define
define|#
directive|define
name|R_SPARC_UA32
value|23
end_define

begin_define
define|#
directive|define
name|R_SPARC_PLT32
value|24
end_define

begin_define
define|#
directive|define
name|R_SPARC_HIPLT22
value|25
end_define

begin_define
define|#
directive|define
name|R_SPARC_LOPLT10
value|26
end_define

begin_define
define|#
directive|define
name|R_SPARC_PCPLT32
value|27
end_define

begin_define
define|#
directive|define
name|R_SPARC_PCPLT22
value|28
end_define

begin_define
define|#
directive|define
name|R_SPARC_PCPLT10
value|29
end_define

begin_define
define|#
directive|define
name|R_SPARC_10
value|30
end_define

begin_define
define|#
directive|define
name|R_SPARC_11
value|31
end_define

begin_define
define|#
directive|define
name|R_SPARC_64
value|32
end_define

begin_define
define|#
directive|define
name|R_SPARC_OLO10
value|33
end_define

begin_define
define|#
directive|define
name|R_SPARC_HH22
value|34
end_define

begin_define
define|#
directive|define
name|R_SPARC_HM10
value|35
end_define

begin_define
define|#
directive|define
name|R_SPARC_LM22
value|36
end_define

begin_define
define|#
directive|define
name|R_SPARC_PC_HH22
value|37
end_define

begin_define
define|#
directive|define
name|R_SPARC_PC_HM10
value|38
end_define

begin_define
define|#
directive|define
name|R_SPARC_PC_LM22
value|39
end_define

begin_define
define|#
directive|define
name|R_SPARC_WDISP16
value|40
end_define

begin_define
define|#
directive|define
name|R_SPARC_WDISP19
value|41
end_define

begin_define
define|#
directive|define
name|R_SPARC_GLOB_JMP
value|42
end_define

begin_define
define|#
directive|define
name|R_SPARC_7
value|43
end_define

begin_define
define|#
directive|define
name|R_SPARC_5
value|44
end_define

begin_define
define|#
directive|define
name|R_SPARC_6
value|45
end_define

begin_define
define|#
directive|define
name|R_SPARC_DISP64
value|46
end_define

begin_define
define|#
directive|define
name|R_SPARC_PLT64
value|47
end_define

begin_define
define|#
directive|define
name|R_SPARC_HIX22
value|48
end_define

begin_define
define|#
directive|define
name|R_SPARC_LOX10
value|49
end_define

begin_define
define|#
directive|define
name|R_SPARC_H44
value|50
end_define

begin_define
define|#
directive|define
name|R_SPARC_M44
value|51
end_define

begin_define
define|#
directive|define
name|R_SPARC_L44
value|52
end_define

begin_define
define|#
directive|define
name|R_SPARC_REGISTER
value|53
end_define

begin_define
define|#
directive|define
name|R_SPARC_UA64
value|54
end_define

begin_define
define|#
directive|define
name|R_SPARC_UA16
value|55
end_define

begin_define
define|#
directive|define
name|R_SPARC_TLS_GD_HI22
value|56
end_define

begin_define
define|#
directive|define
name|R_SPARC_TLS_GD_LO10
value|57
end_define

begin_define
define|#
directive|define
name|R_SPARC_TLS_GD_ADD
value|58
end_define

begin_define
define|#
directive|define
name|R_SPARC_TLS_GD_CALL
value|59
end_define

begin_define
define|#
directive|define
name|R_SPARC_TLS_LDM_HI22
value|60
end_define

begin_define
define|#
directive|define
name|R_SPARC_TLS_LDM_LO10
value|61
end_define

begin_define
define|#
directive|define
name|R_SPARC_TLS_LDM_ADD
value|62
end_define

begin_define
define|#
directive|define
name|R_SPARC_TLS_LDM_CALL
value|63
end_define

begin_define
define|#
directive|define
name|R_SPARC_TLS_LDO_HIX22
value|64
end_define

begin_define
define|#
directive|define
name|R_SPARC_TLS_LDO_LOX10
value|65
end_define

begin_define
define|#
directive|define
name|R_SPARC_TLS_LDO_ADD
value|66
end_define

begin_define
define|#
directive|define
name|R_SPARC_TLS_IE_HI22
value|67
end_define

begin_define
define|#
directive|define
name|R_SPARC_TLS_IE_LO10
value|68
end_define

begin_define
define|#
directive|define
name|R_SPARC_TLS_IE_LD
value|69
end_define

begin_define
define|#
directive|define
name|R_SPARC_TLS_IE_LDX
value|70
end_define

begin_define
define|#
directive|define
name|R_SPARC_TLS_IE_ADD
value|71
end_define

begin_define
define|#
directive|define
name|R_SPARC_TLS_LE_HIX22
value|72
end_define

begin_define
define|#
directive|define
name|R_SPARC_TLS_LE_LOX10
value|73
end_define

begin_define
define|#
directive|define
name|R_SPARC_TLS_DTPMOD32
value|74
end_define

begin_define
define|#
directive|define
name|R_SPARC_TLS_DTPMOD64
value|75
end_define

begin_define
define|#
directive|define
name|R_SPARC_TLS_DTPOFF32
value|76
end_define

begin_define
define|#
directive|define
name|R_SPARC_TLS_DTPOFF64
value|77
end_define

begin_define
define|#
directive|define
name|R_SPARC_TLS_TPOFF32
value|78
end_define

begin_define
define|#
directive|define
name|R_SPARC_TLS_TPOFF64
value|79
end_define

begin_comment
comment|/* Define "machine" characteristics */
end_comment

begin_if
if|#
directive|if
name|__ELF_WORD_SIZE
operator|==
literal|32
end_if

begin_define
define|#
directive|define
name|ELF_TARG_CLASS
value|ELFCLASS32
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|ELF_TARG_CLASS
value|ELFCLASS64
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|ELF_TARG_DATA
value|ELFDATA2MSB
end_define

begin_define
define|#
directive|define
name|ELF_TARG_MACH
value|ELF_ARCH
end_define

begin_define
define|#
directive|define
name|ELF_TARG_VER
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_MACHINE_ELF_H_ */
end_comment

end_unit

