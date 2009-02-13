begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2007 John Birrell (jb@freebsd.org)  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__LIBDWARF_H_
end_ifndef

begin_define
define|#
directive|define
name|__LIBDWARF_H_
end_define

begin_include
include|#
directive|include
file|<sys/param.h>
end_include

begin_include
include|#
directive|include
file|<sys/queue.h>
end_include

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_include
include|#
directive|include
file|<gelf.h>
end_include

begin_include
include|#
directive|include
file|"dwarf.h"
end_include

begin_include
include|#
directive|include
file|"libdwarf.h"
end_include

begin_define
define|#
directive|define
name|DWARF_debug_abbrev
value|0
end_define

begin_define
define|#
directive|define
name|DWARF_debug_aranges
value|1
end_define

begin_define
define|#
directive|define
name|DWARF_debug_frame
value|2
end_define

begin_define
define|#
directive|define
name|DWARF_debug_info
value|3
end_define

begin_define
define|#
directive|define
name|DWARF_debug_line
value|4
end_define

begin_define
define|#
directive|define
name|DWARF_debug_pubnames
value|5
end_define

begin_define
define|#
directive|define
name|DWARF_eh_frame
value|6
end_define

begin_define
define|#
directive|define
name|DWARF_debug_macinfo
value|7
end_define

begin_define
define|#
directive|define
name|DWARF_debug_str
value|8
end_define

begin_define
define|#
directive|define
name|DWARF_debug_loc
value|9
end_define

begin_define
define|#
directive|define
name|DWARF_debug_pubtypes
value|10
end_define

begin_define
define|#
directive|define
name|DWARF_debug_ranges
value|11
end_define

begin_define
define|#
directive|define
name|DWARF_debug_static_func
value|12
end_define

begin_define
define|#
directive|define
name|DWARF_debug_static_vars
value|13
end_define

begin_define
define|#
directive|define
name|DWARF_debug_types
value|14
end_define

begin_define
define|#
directive|define
name|DWARF_debug_weaknames
value|15
end_define

begin_define
define|#
directive|define
name|DWARF_symtab
value|16
end_define

begin_define
define|#
directive|define
name|DWARF_strtab
value|17
end_define

begin_define
define|#
directive|define
name|DWARF_DEBUG_SNAMES
value|18
end_define

begin_define
define|#
directive|define
name|DWARF_DIE_HASH_SIZE
value|8191
end_define

begin_define
define|#
directive|define
name|DWARF_SET_ERROR
parameter_list|(
name|_e
parameter_list|,
name|_err
parameter_list|)
value|do { 		\ 	_e->err_error = _err;				\ 	_e->elf_error = 0;				\ 	_e->err_func  = __func__;			\ 	_e->err_line  = __LINE__;			\ 	_e->err_msg[0] = '\0';				\ 	} while (0)
end_define

begin_define
define|#
directive|define
name|DWARF_SET_ELF_ERROR
parameter_list|(
name|_e
parameter_list|,
name|_err
parameter_list|)
value|do { 		\ 	_e->err_error = DWARF_E_ELF;			\ 	_e->elf_error = _err;				\ 	_e->err_func  = __func__;			\ 	_e->err_line  = __LINE__;			\ 	_e->err_msg[0] = '\0';				\ 	} while (0)
end_define

begin_struct
struct|struct
name|_Dwarf_AttrValue
block|{
name|uint64_t
name|av_attrib
decl_stmt|;
comment|/* DW_AT_ */
name|uint64_t
name|av_form
decl_stmt|;
comment|/* DW_FORM_ */
union|union
block|{
name|uint64_t
name|u64
decl_stmt|;
name|int64_t
name|s64
decl_stmt|;
specifier|const
name|char
modifier|*
name|s
decl_stmt|;
name|uint8_t
modifier|*
name|u8p
decl_stmt|;
block|}
name|u
index|[
literal|2
index|]
union|;
comment|/* Value. */
name|STAILQ_ENTRY
argument_list|(
argument|_Dwarf_AttrValue
argument_list|)
name|av_next
expr_stmt|;
comment|/* Next attribute value. */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|_Dwarf_Die
block|{
name|int
name|die_level
decl_stmt|;
comment|/* Parent-child level. */
name|uint64_t
name|die_offset
decl_stmt|;
comment|/* DIE offset in section. */
name|uint64_t
name|die_abnum
decl_stmt|;
comment|/* Abbrev number. */
name|Dwarf_Abbrev
name|die_a
decl_stmt|;
comment|/* Abbrev pointer. */
name|Dwarf_CU
name|die_cu
decl_stmt|;
comment|/* Compilation unit pointer. */
specifier|const
name|char
modifier|*
name|die_name
decl_stmt|;
comment|/* Ptr to the name string. */
name|STAILQ_HEAD
argument_list|(
argument_list|,
argument|_Dwarf_AttrValue
argument_list|)
name|die_attrval
expr_stmt|;
comment|/* List of attribute values. */
name|STAILQ_ENTRY
argument_list|(
argument|_Dwarf_Die
argument_list|)
name|die_next
expr_stmt|;
comment|/* Next die in list. */
name|STAILQ_ENTRY
argument_list|(
argument|_Dwarf_Die
argument_list|)
name|die_hash
expr_stmt|;
comment|/* Next die in hash table. */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|_Dwarf_Attribute
block|{
name|uint64_t
name|at_attrib
decl_stmt|;
comment|/* DW_AT_ */
name|uint64_t
name|at_form
decl_stmt|;
comment|/* DW_FORM_ */
name|STAILQ_ENTRY
argument_list|(
argument|_Dwarf_Attribute
argument_list|)
name|at_next
expr_stmt|;
comment|/* Next attribute. */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|_Dwarf_Abbrev
block|{
name|uint64_t
name|a_entry
decl_stmt|;
comment|/* Abbrev entry. */
name|uint64_t
name|a_tag
decl_stmt|;
comment|/* Tag: DW_TAG_ */
name|uint8_t
name|a_children
decl_stmt|;
comment|/* DW_CHILDREN_no or DW_CHILDREN_yes */
name|STAILQ_HEAD
argument_list|(
argument_list|,
argument|_Dwarf_Attribute
argument_list|)
name|a_attrib
expr_stmt|;
comment|/* List of attributes. */
name|STAILQ_ENTRY
argument_list|(
argument|_Dwarf_Abbrev
argument_list|)
name|a_next
expr_stmt|;
comment|/* Next abbrev. */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|_Dwarf_CU
block|{
name|uint64_t
name|cu_offset
decl_stmt|;
comment|/* Offset to the this compilation unit. */
name|uint32_t
name|cu_length
decl_stmt|;
comment|/* Length of CU data. */
name|uint32_t
name|cu_header_length
decl_stmt|;
comment|/* Length of the CU header. */
name|uint16_t
name|cu_version
decl_stmt|;
comment|/* DWARF version. */
name|uint64_t
name|cu_abbrev_offset
decl_stmt|;
comment|/* Offset into .debug_abbrev. */
name|uint8_t
name|cu_pointer_size
decl_stmt|;
comment|/* Number of bytes in pointer. */
name|uint64_t
name|cu_next_offset
decl_stmt|;
comment|/* Offset to the next compilation unit. */
name|STAILQ_HEAD
argument_list|(
argument_list|,
argument|_Dwarf_Abbrev
argument_list|)
name|cu_abbrev
expr_stmt|;
comment|/* List of abbrevs. */
name|STAILQ_HEAD
argument_list|(
argument_list|,
argument|_Dwarf_Die
argument_list|)
name|cu_die
expr_stmt|;
comment|/* List of dies. */
name|STAILQ_HEAD
argument_list|(
argument_list|,
argument|_Dwarf_Die
argument_list|)
name|cu_die_hash
index|[
name|DWARF_DIE_HASH_SIZE
index|]
expr_stmt|;
comment|/* Hash of dies. */
name|STAILQ_ENTRY
argument_list|(
argument|_Dwarf_CU
argument_list|)
name|cu_next
expr_stmt|;
comment|/* Next compilation unit. */
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
struct|struct
name|_Dwarf_section
block|{
name|Elf_Scn
modifier|*
name|s_scn
decl_stmt|;
comment|/* Section pointer. */
name|GElf_Shdr
name|s_shdr
decl_stmt|;
comment|/* Copy of the section header. */
name|char
modifier|*
name|s_sname
decl_stmt|;
comment|/* Ptr to the section name. */
name|uint32_t
name|s_shnum
decl_stmt|;
comment|/* Section number. */
name|Elf_Data
modifier|*
name|s_data
decl_stmt|;
comment|/* Section data. */
block|}
name|Dwarf_section
typedef|;
end_typedef

begin_struct
struct|struct
name|_Dwarf_Debug
block|{
name|Elf
modifier|*
name|dbg_elf
decl_stmt|;
comment|/* Ptr to the ELF handle. */
name|GElf_Ehdr
name|dbg_ehdr
decl_stmt|;
comment|/* Copy of the ELF header. */
name|int
name|dbg_elf_close
decl_stmt|;
comment|/* True if elf_end() required. */
name|int
name|dbg_mode
decl_stmt|;
comment|/* Access mode. */
name|size_t
name|dbg_stnum
decl_stmt|;
comment|/* Section header string table section number. */
name|int
name|dbg_offsize
decl_stmt|;
comment|/* DWARF offset size. */
name|Dwarf_section
name|dbg_s
index|[
name|DWARF_DEBUG_SNAMES
index|]
decl_stmt|;
comment|/* Array of section information. */
name|STAILQ_HEAD
argument_list|(
argument_list|,
argument|_Dwarf_CU
argument_list|)
name|dbg_cu
expr_stmt|;
comment|/* List of compilation units. */
name|Dwarf_CU
name|dbg_cu_current
decl_stmt|;
comment|/* Ptr to the current compilation unit. */
block|}
struct|;
end_struct

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !__LIBDWARF_H_ */
end_comment

end_unit

