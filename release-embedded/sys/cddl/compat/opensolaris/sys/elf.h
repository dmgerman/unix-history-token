begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * CDDL HEADER START  *  * The contents of this file are subject to the terms of the  * Common Development and Distribution License (the "License").  * You may not use this file except in compliance with the License.  *  * You can obtain a copy of the license at usr/src/OPENSOLARIS.LICENSE  * or http://www.opensolaris.org/os/licensing.  * See the License for the specific language governing permissions  * and limitations under the License.  *  * When distributing Covered Code, include this CDDL HEADER in each  * file and include the License file at usr/src/OPENSOLARIS.LICENSE.  * If applicable, add the following below this CDDL HEADER, with the  * fields enclosed by brackets "[]" replaced with your own identifying  * information: Portions Copyright [yyyy] [name of copyright owner]  *  * CDDL HEADER END  *  * $FreeBSD$  *  * ELF compatibility definitions for OpenSolaris source.  *  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_SYS__ELF_SOLARIS_H_
end_ifndef

begin_define
define|#
directive|define
name|_SYS__ELF_SOLARIS_H_
end_define

begin_empty
empty|#include_next<sys/elf.h>
end_empty

begin_define
define|#
directive|define
name|__sElfN
parameter_list|(
name|x
parameter_list|)
value|typedef __CONCAT(__CONCAT(__CONCAT(Elf,__ELF_WORD_SIZE),_),x) x
end_define

begin_expr_stmt
name|__sElfN
argument_list|(
name|Addr
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|__sElfN
argument_list|(
name|Cap
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|__sElfN
argument_list|(
name|Dyn
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|__sElfN
argument_list|(
name|Ehdr
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|__sElfN
argument_list|(
name|Move
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|__sElfN
argument_list|(
name|Off
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|__sElfN
argument_list|(
name|Phdr
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|__sElfN
argument_list|(
name|Rel
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|__sElfN
argument_list|(
name|Rela
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|__sElfN
argument_list|(
name|Shdr
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|__sElfN
argument_list|(
name|Sym
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|__sElfN
argument_list|(
name|Syminfo
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|__sElfN
argument_list|(
name|Verdaux
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|__sElfN
argument_list|(
name|Verdef
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|__sElfN
argument_list|(
name|Vernaux
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|__sElfN
argument_list|(
name|Verneed
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|__sElfN
argument_list|(
name|Versym
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|__sElfN
argument_list|(
name|Half
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|__sElfN
argument_list|(
name|Sword
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|__sElfN
argument_list|(
name|Word
argument_list|)
expr_stmt|;
end_expr_stmt

begin_if
if|#
directive|if
name|__ELF_WORD_SIZE
operator|==
literal|32
end_if

begin_typedef
typedef|typedef
name|Elf32_Word
name|Xword
typedef|;
end_typedef

begin_comment
comment|/* Xword/Sxword are 32-bits in Elf32 */
end_comment

begin_typedef
typedef|typedef
name|Elf32_Sword
name|Sxword
typedef|;
end_typedef

begin_else
else|#
directive|else
end_else

begin_typedef
typedef|typedef
name|Elf64_Xword
name|Xword
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|Elf64_Sxword
name|Sxword
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|ELF_M_INFO
value|__ELFN(M_INFO)
end_define

begin_define
define|#
directive|define
name|ELF_M_SIZE
value|__ELFN(M_SIZE)
end_define

begin_define
define|#
directive|define
name|ELF_M_SYM
value|__ELFN(M_SYM)
end_define

begin_comment
comment|/*  * Elf `printf' type-cast macros.  These force arguments to be a fixed size  * so that Elf32 and Elf64 can share common format strings.  */
end_comment

begin_define
define|#
directive|define
name|EC_ADDR
parameter_list|(
name|a
parameter_list|)
value|((Elf64_Addr)(a))
end_define

begin_comment
comment|/* "ull" */
end_comment

begin_define
define|#
directive|define
name|EC_OFF
parameter_list|(
name|a
parameter_list|)
value|((Elf64_Off)(a))
end_define

begin_comment
comment|/* "ull"  */
end_comment

begin_define
define|#
directive|define
name|EC_HALF
parameter_list|(
name|a
parameter_list|)
value|((Elf64_Half)(a))
end_define

begin_comment
comment|/* "d"   */
end_comment

begin_define
define|#
directive|define
name|EC_WORD
parameter_list|(
name|a
parameter_list|)
value|((Elf64_Word)(a))
end_define

begin_comment
comment|/* "u"   */
end_comment

begin_define
define|#
directive|define
name|EC_SWORD
parameter_list|(
name|a
parameter_list|)
value|((Elf64_Sword)(a))
end_define

begin_comment
comment|/* "d"   */
end_comment

begin_define
define|#
directive|define
name|EC_XWORD
parameter_list|(
name|a
parameter_list|)
value|((Elf64_Xword)(a))
end_define

begin_comment
comment|/* "ull" */
end_comment

begin_define
define|#
directive|define
name|EC_SXWORD
parameter_list|(
name|a
parameter_list|)
value|((Elf64_Sxword)(a))
end_define

begin_comment
comment|/* "ll"  */
end_comment

begin_define
define|#
directive|define
name|EC_LWORD
parameter_list|(
name|a
parameter_list|)
value|((Elf64_Lword)(a))
end_define

begin_comment
comment|/* "ull" */
end_comment

begin_define
define|#
directive|define
name|elf_checksum
value|__elfN(checksum)
end_define

begin_define
define|#
directive|define
name|elf_fsize
value|__elfN(fsize)
end_define

begin_define
define|#
directive|define
name|elf_getehdr
value|__elfN(getehdr)
end_define

begin_define
define|#
directive|define
name|elf_getphdr
value|__elfN(getphdr)
end_define

begin_define
define|#
directive|define
name|elf_newehdr
value|__elfN(newehdr)
end_define

begin_define
define|#
directive|define
name|elf_newphdr
value|__elfN(newphdr)
end_define

begin_define
define|#
directive|define
name|elf_getshdr
value|__elfN(getshdr)
end_define

begin_define
define|#
directive|define
name|elf_xlatetof
value|__elfN(xlatetof)
end_define

begin_define
define|#
directive|define
name|elf_xlatetom
value|__elfN(xlatetom)
end_define

begin_define
define|#
directive|define
name|Elf_cap_entry
value|__ElfN(cap_entry)
end_define

begin_define
define|#
directive|define
name|Elf_cap_title
value|__ElfN(cap_title)
end_define

begin_define
define|#
directive|define
name|Elf_demangle_name
value|__ElfN(demangle_name)
end_define

begin_define
define|#
directive|define
name|Elf_dyn_entry
value|__ElfN(dyn_entry)
end_define

begin_define
define|#
directive|define
name|Elf_dyn_title
value|__ElfN(dyn_title)
end_define

begin_define
define|#
directive|define
name|Elf_ehdr
value|__ElfN(ehdr)
end_define

begin_define
define|#
directive|define
name|Elf_got_entry
value|__ElfN(got_entry)
end_define

begin_define
define|#
directive|define
name|Elf_got_title
value|__ElfN(got_title)
end_define

begin_define
define|#
directive|define
name|Elf_reloc_apply_reg
value|__ElfN(reloc_apply_reg)
end_define

begin_define
define|#
directive|define
name|Elf_reloc_apply_val
value|__ElfN(reloc_apply_val)
end_define

begin_define
define|#
directive|define
name|Elf_reloc_entry_1
value|__ElfN(reloc_entry_1)
end_define

begin_define
define|#
directive|define
name|Elf_reloc_entry_2
value|__ElfN(reloc_entry_2)
end_define

begin_define
define|#
directive|define
name|Elf_reloc_title
value|__ElfN(reloc_title)
end_define

begin_define
define|#
directive|define
name|Elf_phdr
value|__ElfN(phdr)
end_define

begin_define
define|#
directive|define
name|Elf_shdr
value|__ElfN(shdr)
end_define

begin_define
define|#
directive|define
name|Elf_syms_table_entry
value|__ElfN(syms_table_entry)
end_define

begin_define
define|#
directive|define
name|Elf_syms_table_title
value|__ElfN(syms_table_title)
end_define

begin_define
define|#
directive|define
name|Elf_ver_def_title
value|__ElfN(ver_def_title)
end_define

begin_define
define|#
directive|define
name|Elf_ver_line_1
value|__ElfN(ver_line_1)
end_define

begin_define
define|#
directive|define
name|Elf_ver_line_2
value|__ElfN(ver_line_2)
end_define

begin_define
define|#
directive|define
name|Elf_ver_line_3
value|__ElfN(ver_line_3)
end_define

begin_define
define|#
directive|define
name|Elf_ver_line_4
value|__ElfN(ver_line_4)
end_define

begin_define
define|#
directive|define
name|Elf_ver_line_5
value|__ElfN(ver_line_5)
end_define

begin_define
define|#
directive|define
name|Elf_ver_need_title
value|__ElfN(ver_need_title)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_SYS__ELF_SOLARIS_H_ */
end_comment

end_unit

