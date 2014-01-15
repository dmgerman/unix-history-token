begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2007 John Birrell (jb@freebsd.org)  * Copyright (c) 2009-2011 Kai Wang  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $Id: _libdwarf.h 2075 2011-10-27 03:47:28Z jkoshy $  */
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
file|<assert.h>
end_include

begin_include
include|#
directive|include
file|<limits.h>
end_include

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_include
include|#
directive|include
file|<stdlib.h>
end_include

begin_include
include|#
directive|include
file|<string.h>
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

begin_include
include|#
directive|include
file|"uthash.h"
end_include

begin_include
include|#
directive|include
file|"_elftc.h"
end_include

begin_define
define|#
directive|define
name|DWARF_DIE_HASH_SIZE
value|8191
end_define

begin_struct
struct|struct
name|_libdwarf_globals
block|{
name|Dwarf_Handler
name|errhand
decl_stmt|;
name|Dwarf_Ptr
name|errarg
decl_stmt|;
name|int
name|applyrela
decl_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
specifier|extern
name|struct
name|_libdwarf_globals
name|_libdwarf
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|_DWARF_SET_ERROR
parameter_list|(
name|_d
parameter_list|,
name|_e
parameter_list|,
name|_err
parameter_list|,
name|_elf_err
parameter_list|)
define|\
value|_dwarf_set_error(_d, _e, _err, _elf_err, __func__, __LINE__)
end_define

begin_define
define|#
directive|define
name|DWARF_SET_ERROR
parameter_list|(
name|_d
parameter_list|,
name|_e
parameter_list|,
name|_err
parameter_list|)
define|\
value|_DWARF_SET_ERROR(_d, _e, _err, 0)
end_define

begin_define
define|#
directive|define
name|DWARF_SET_ELF_ERROR
parameter_list|(
name|_d
parameter_list|,
name|_e
parameter_list|)
define|\
value|_DWARF_SET_ERROR(_d, _e, DW_DLE_ELF, elf_errno())
end_define

begin_comment
comment|/*  * Convenient macros for producer bytes stream generation.  */
end_comment

begin_define
define|#
directive|define
name|WRITE_VALUE
parameter_list|(
name|value
parameter_list|,
name|bytes
parameter_list|)
define|\
value|dbg->write_alloc(&ds->ds_data,&ds->ds_cap,&ds->ds_size,	\ 	    (value), (bytes), error)
end_define

begin_define
define|#
directive|define
name|WRITE_ULEB128
parameter_list|(
name|value
parameter_list|)
define|\
value|_dwarf_write_uleb128_alloc(&ds->ds_data,&ds->ds_cap,		\&ds->ds_size, (value), error)
end_define

begin_define
define|#
directive|define
name|WRITE_SLEB128
parameter_list|(
name|value
parameter_list|)
define|\
value|_dwarf_write_sleb128_alloc(&ds->ds_data,&ds->ds_cap,		\&ds->ds_size, (value), error)
end_define

begin_define
define|#
directive|define
name|WRITE_STRING
parameter_list|(
name|string
parameter_list|)
define|\
value|_dwarf_write_string_alloc(&ds->ds_data,&ds->ds_cap,		\&ds->ds_size, (string), error)
end_define

begin_define
define|#
directive|define
name|WRITE_BLOCK
parameter_list|(
name|blk
parameter_list|,
name|size
parameter_list|)
define|\
value|_dwarf_write_block_alloc(&ds->ds_data,&ds->ds_cap,		\&ds->ds_size, (blk), (size), error)
end_define

begin_define
define|#
directive|define
name|WRITE_PADDING
parameter_list|(
name|byte
parameter_list|,
name|cnt
parameter_list|)
define|\
value|_dwarf_write_padding_alloc(&ds->ds_data,&ds->ds_cap,		\&ds->ds_size, (byte), (cnt), error)
end_define

begin_define
define|#
directive|define
name|RCHECK
parameter_list|(
name|expr
parameter_list|)
define|\
value|do {								\ 		ret = expr;						\ 		if (ret != DW_DLE_NONE)					\ 			goto gen_fail;					\ 	} while(0)
end_define

begin_struct
struct|struct
name|_Dwarf_AttrDef
block|{
name|uint64_t
name|ad_attrib
decl_stmt|;
comment|/* DW_AT_XXX */
name|uint64_t
name|ad_form
decl_stmt|;
comment|/* DW_FORM_XXX */
name|uint64_t
name|ad_offset
decl_stmt|;
comment|/* Offset in abbrev section. */
name|STAILQ_ENTRY
argument_list|(
argument|_Dwarf_AttrDef
argument_list|)
name|ad_next
expr_stmt|;
comment|/* Next attribute define. */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|_Dwarf_Attribute
block|{
name|Dwarf_Die
name|at_die
decl_stmt|;
comment|/* Ptr to containing DIE. */
name|Dwarf_Die
name|at_refdie
decl_stmt|;
comment|/* Ptr to reference DIE. */
name|uint64_t
name|at_offset
decl_stmt|;
comment|/* Offset in info section. */
name|uint64_t
name|at_attrib
decl_stmt|;
comment|/* DW_AT_XXX */
name|uint64_t
name|at_form
decl_stmt|;
comment|/* DW_FORM_XXX */
name|int
name|at_indirect
decl_stmt|;
comment|/* Has indirect form. */
union|union
block|{
name|uint64_t
name|u64
decl_stmt|;
comment|/* Unsigned value. */
name|int64_t
name|s64
decl_stmt|;
comment|/* Signed value. */
name|char
modifier|*
name|s
decl_stmt|;
comment|/* String. */
name|uint8_t
modifier|*
name|u8p
decl_stmt|;
comment|/* Block data. */
block|}
name|u
index|[
literal|2
index|]
union|;
comment|/* Value. */
name|Dwarf_Block
name|at_block
decl_stmt|;
comment|/* Block. */
name|Dwarf_Locdesc
modifier|*
name|at_ld
decl_stmt|;
comment|/* at value is locdesc. */
name|Dwarf_P_Expr
name|at_expr
decl_stmt|;
comment|/* at value is expr. */
name|uint64_t
name|at_relsym
decl_stmt|;
comment|/* Relocation symbol index. */
specifier|const
name|char
modifier|*
name|at_relsec
decl_stmt|;
comment|/* Rel. to dwarf section. */
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
name|ab_entry
decl_stmt|;
comment|/* Abbrev entry. */
name|uint64_t
name|ab_tag
decl_stmt|;
comment|/* Tag: DW_TAG_ */
name|uint8_t
name|ab_children
decl_stmt|;
comment|/* DW_CHILDREN_no or DW_CHILDREN_yes */
name|uint64_t
name|ab_offset
decl_stmt|;
comment|/* Offset in abbrev section. */
name|uint64_t
name|ab_length
decl_stmt|;
comment|/* Length of this abbrev entry. */
name|uint64_t
name|ab_atnum
decl_stmt|;
comment|/* Number of attribute defines. */
name|UT_hash_handle
name|ab_hh
decl_stmt|;
comment|/* Uthash handle. */
name|STAILQ_HEAD
argument_list|(
argument_list|,
argument|_Dwarf_AttrDef
argument_list|)
name|ab_attrdef
expr_stmt|;
comment|/* List of attribute defs. */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|_Dwarf_Die
block|{
name|Dwarf_Die
name|die_parent
decl_stmt|;
comment|/* Parent DIE. */
name|Dwarf_Die
name|die_child
decl_stmt|;
comment|/* First child DIE. */
name|Dwarf_Die
name|die_left
decl_stmt|;
comment|/* Left sibling DIE. */
name|Dwarf_Die
name|die_right
decl_stmt|;
comment|/* Right sibling DIE. */
name|uint64_t
name|die_offset
decl_stmt|;
comment|/* DIE offset in section. */
name|uint64_t
name|die_next_off
decl_stmt|;
comment|/* Next DIE offset in section. */
name|uint64_t
name|die_abnum
decl_stmt|;
comment|/* Abbrev number. */
name|Dwarf_Abbrev
name|die_ab
decl_stmt|;
comment|/* Abbrev pointer. */
name|Dwarf_Tag
name|die_tag
decl_stmt|;
comment|/* DW_TAG_ */
name|Dwarf_Debug
name|die_dbg
decl_stmt|;
comment|/* Dwarf_Debug pointer. */
name|Dwarf_CU
name|die_cu
decl_stmt|;
comment|/* Compilation unit pointer. */
name|char
modifier|*
name|die_name
decl_stmt|;
comment|/* Ptr to the name string. */
name|Dwarf_Attribute
modifier|*
name|die_attrarray
decl_stmt|;
comment|/* Array of attributes. */
name|STAILQ_HEAD
argument_list|(
argument_list|,
argument|_Dwarf_Attribute
argument_list|)
name|die_attr
expr_stmt|;
comment|/* List of attributes. */
name|STAILQ_ENTRY
argument_list|(
argument|_Dwarf_Die
argument_list|)
name|die_pro_next
expr_stmt|;
comment|/* Next die in pro-die list. */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|_Dwarf_Loclist
block|{
name|Dwarf_Locdesc
modifier|*
modifier|*
name|ll_ldlist
decl_stmt|;
comment|/* Array of Locdesc pointer. */
name|int
name|ll_ldlen
decl_stmt|;
comment|/* Number of Locdesc. */
name|Dwarf_Unsigned
name|ll_offset
decl_stmt|;
comment|/* Offset in .debug_loc section. */
name|Dwarf_Unsigned
name|ll_length
decl_stmt|;
comment|/* Length (in bytes) of the loclist. */
name|TAILQ_ENTRY
argument_list|(
argument|_Dwarf_Loclist
argument_list|)
name|ll_next
expr_stmt|;
comment|/* Next loclist in list. */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|_Dwarf_P_Expr_Entry
block|{
name|Dwarf_Loc
name|ee_loc
decl_stmt|;
comment|/* Location expression. */
name|Dwarf_Unsigned
name|ee_sym
decl_stmt|;
comment|/* Optional related reloc sym index. */
name|STAILQ_ENTRY
argument_list|(
argument|_Dwarf_P_Expr_Entry
argument_list|)
name|ee_next
expr_stmt|;
comment|/* Next entry in list. */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|_Dwarf_P_Expr
block|{
name|Dwarf_Debug
name|pe_dbg
decl_stmt|;
comment|/* Dwarf_Debug pointer. */
name|uint8_t
modifier|*
name|pe_block
decl_stmt|;
comment|/* Expression block data. */
name|int
name|pe_invalid
decl_stmt|;
comment|/* Block data is up-to-date or not. */
name|Dwarf_Unsigned
name|pe_length
decl_stmt|;
comment|/* Length of the block. */
name|STAILQ_HEAD
argument_list|(
argument_list|,
argument|_Dwarf_P_Expr_Entry
argument_list|)
name|pe_eelist
expr_stmt|;
comment|/* List of entries. */
name|STAILQ_ENTRY
argument_list|(
argument|_Dwarf_P_Expr
argument_list|)
name|pe_next
expr_stmt|;
comment|/* Next expr in list. */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|_Dwarf_Line
block|{
name|Dwarf_LineInfo
name|ln_li
decl_stmt|;
comment|/* Ptr to line info. */
name|Dwarf_Addr
name|ln_addr
decl_stmt|;
comment|/* Line address. */
name|Dwarf_Unsigned
name|ln_symndx
decl_stmt|;
comment|/* Symbol index for relocation. */
name|Dwarf_Unsigned
name|ln_fileno
decl_stmt|;
comment|/* File number. */
name|Dwarf_Unsigned
name|ln_lineno
decl_stmt|;
comment|/* Line number. */
name|Dwarf_Signed
name|ln_column
decl_stmt|;
comment|/* Column number. */
name|Dwarf_Bool
name|ln_bblock
decl_stmt|;
comment|/* Basic block flag. */
name|Dwarf_Bool
name|ln_stmt
decl_stmt|;
comment|/* Begin statement flag. */
name|Dwarf_Bool
name|ln_endseq
decl_stmt|;
comment|/* End sequence flag. */
name|STAILQ_ENTRY
argument_list|(
argument|_Dwarf_Line
argument_list|)
name|ln_next
expr_stmt|;
comment|/* Next line in list. */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|_Dwarf_LineFile
block|{
name|char
modifier|*
name|lf_fname
decl_stmt|;
comment|/* Filename. */
name|char
modifier|*
name|lf_fullpath
decl_stmt|;
comment|/* Full pathname of the file. */
name|Dwarf_Unsigned
name|lf_dirndx
decl_stmt|;
comment|/* Dir index. */
name|Dwarf_Unsigned
name|lf_mtime
decl_stmt|;
comment|/* Modification time. */
name|Dwarf_Unsigned
name|lf_size
decl_stmt|;
comment|/* File size. */
name|STAILQ_ENTRY
argument_list|(
argument|_Dwarf_LineFile
argument_list|)
name|lf_next
expr_stmt|;
comment|/* Next file in list. */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|_Dwarf_LineInfo
block|{
name|Dwarf_Unsigned
name|li_length
decl_stmt|;
comment|/* Length of line info data. */
name|Dwarf_Half
name|li_version
decl_stmt|;
comment|/* Version of line info. */
name|Dwarf_Unsigned
name|li_hdrlen
decl_stmt|;
comment|/* Length of line info header. */
name|Dwarf_Small
name|li_minlen
decl_stmt|;
comment|/* Minimum instrutction length. */
name|Dwarf_Small
name|li_defstmt
decl_stmt|;
comment|/* Default value of is_stmt. */
name|int8_t
name|li_lbase
decl_stmt|;
comment|/* Line base for special opcode. */
name|Dwarf_Small
name|li_lrange
decl_stmt|;
comment|/* Line range for special opcode. */
name|Dwarf_Small
name|li_opbase
decl_stmt|;
comment|/* Fisrt std opcode number. */
name|Dwarf_Small
modifier|*
name|li_oplen
decl_stmt|;
comment|/* Array of std opcode len. */
name|char
modifier|*
modifier|*
name|li_incdirs
decl_stmt|;
comment|/* Array of include dirs. */
name|Dwarf_Unsigned
name|li_inclen
decl_stmt|;
comment|/* Length of inc dir array. */
name|char
modifier|*
modifier|*
name|li_lfnarray
decl_stmt|;
comment|/* Array of file names. */
name|Dwarf_Unsigned
name|li_lflen
decl_stmt|;
comment|/* Length of filename array. */
name|STAILQ_HEAD
argument_list|(
argument_list|,
argument|_Dwarf_LineFile
argument_list|)
name|li_lflist
expr_stmt|;
comment|/* List of files. */
name|Dwarf_Line
modifier|*
name|li_lnarray
decl_stmt|;
comment|/* Array of lines. */
name|Dwarf_Unsigned
name|li_lnlen
decl_stmt|;
comment|/* Length of the line array. */
name|STAILQ_HEAD
argument_list|(
argument_list|,
argument|_Dwarf_Line
argument_list|)
name|li_lnlist
expr_stmt|;
comment|/* List of lines. */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|_Dwarf_NamePair
block|{
name|Dwarf_NameTbl
name|np_nt
decl_stmt|;
comment|/* Ptr to containing name table. */
name|Dwarf_Die
name|np_die
decl_stmt|;
comment|/* Ptr to Ref. Die. */
name|Dwarf_Unsigned
name|np_offset
decl_stmt|;
comment|/* Offset in CU. */
name|char
modifier|*
name|np_name
decl_stmt|;
comment|/* Object/Type name. */
name|STAILQ_ENTRY
argument_list|(
argument|_Dwarf_NamePair
argument_list|)
name|np_next
expr_stmt|;
comment|/* Next pair in the list. */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|_Dwarf_NameTbl
block|{
name|Dwarf_Unsigned
name|nt_length
decl_stmt|;
comment|/* Name lookup table length. */
name|Dwarf_Half
name|nt_version
decl_stmt|;
comment|/* Name lookup table version. */
name|Dwarf_CU
name|nt_cu
decl_stmt|;
comment|/* Ptr to Ref. CU. */
name|Dwarf_Off
name|nt_cu_offset
decl_stmt|;
comment|/* Ref. CU offset in .debug_info */
name|Dwarf_Unsigned
name|nt_cu_length
decl_stmt|;
comment|/* Ref. CU length. */
name|STAILQ_HEAD
argument_list|(
argument_list|,
argument|_Dwarf_NamePair
argument_list|)
name|nt_nplist
expr_stmt|;
comment|/* List of offset+name pairs. */
name|STAILQ_ENTRY
argument_list|(
argument|_Dwarf_NameTbl
argument_list|)
name|nt_next
expr_stmt|;
comment|/* Next name table in the list. */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|_Dwarf_NameSec
block|{
name|STAILQ_HEAD
argument_list|(
argument_list|,
argument|_Dwarf_NameTbl
argument_list|)
name|ns_ntlist
expr_stmt|;
comment|/* List of name tables. */
name|Dwarf_NamePair
modifier|*
name|ns_array
decl_stmt|;
comment|/* Array of pairs of all tables. */
name|Dwarf_Unsigned
name|ns_len
decl_stmt|;
comment|/* Length of the pair array. */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|_Dwarf_Fde
block|{
name|Dwarf_Debug
name|fde_dbg
decl_stmt|;
comment|/* Ptr to containing dbg. */
name|Dwarf_Cie
name|fde_cie
decl_stmt|;
comment|/* Ptr to associated CIE. */
name|Dwarf_FrameSec
name|fde_fs
decl_stmt|;
comment|/* Ptr to containing .debug_frame. */
name|Dwarf_Ptr
name|fde_addr
decl_stmt|;
comment|/* Ptr to start of the FDE. */
name|Dwarf_Unsigned
name|fde_offset
decl_stmt|;
comment|/* Offset of the FDE. */
name|Dwarf_Unsigned
name|fde_length
decl_stmt|;
comment|/* Length of the FDE. */
name|Dwarf_Unsigned
name|fde_cieoff
decl_stmt|;
comment|/* Offset of associated CIE. */
name|Dwarf_Unsigned
name|fde_initloc
decl_stmt|;
comment|/* Initial location. */
name|Dwarf_Unsigned
name|fde_adrange
decl_stmt|;
comment|/* Address range. */
name|Dwarf_Unsigned
name|fde_auglen
decl_stmt|;
comment|/* Augmentation length. */
name|uint8_t
modifier|*
name|fde_augdata
decl_stmt|;
comment|/* Augmentation data. */
name|uint8_t
modifier|*
name|fde_inst
decl_stmt|;
comment|/* Instructions. */
name|Dwarf_Unsigned
name|fde_instlen
decl_stmt|;
comment|/* Length of instructions. */
name|Dwarf_Unsigned
name|fde_instcap
decl_stmt|;
comment|/* Capacity of inst buffer. */
name|Dwarf_Unsigned
name|fde_symndx
decl_stmt|;
comment|/* Symbol index for relocation. */
name|Dwarf_Unsigned
name|fde_esymndx
decl_stmt|;
comment|/* End symbol index for relocation. */
name|Dwarf_Addr
name|fde_eoff
decl_stmt|;
comment|/* Offset from the end symbol. */
name|STAILQ_ENTRY
argument_list|(
argument|_Dwarf_Fde
argument_list|)
name|fde_next
expr_stmt|;
comment|/* Next FDE in list. */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|_Dwarf_Cie
block|{
name|Dwarf_Debug
name|cie_dbg
decl_stmt|;
comment|/* Ptr to containing dbg. */
name|Dwarf_Unsigned
name|cie_index
decl_stmt|;
comment|/* Index of the CIE. */
name|Dwarf_Unsigned
name|cie_offset
decl_stmt|;
comment|/* Offset of the CIE. */
name|Dwarf_Unsigned
name|cie_length
decl_stmt|;
comment|/* Length of the CIE. */
name|Dwarf_Half
name|cie_version
decl_stmt|;
comment|/* CIE version. */
name|uint8_t
modifier|*
name|cie_augment
decl_stmt|;
comment|/* CIE augmentation (UTF-8). */
name|Dwarf_Unsigned
name|cie_ehdata
decl_stmt|;
comment|/* Optional EH Data. */
name|Dwarf_Unsigned
name|cie_caf
decl_stmt|;
comment|/* Code alignment factor. */
name|Dwarf_Signed
name|cie_daf
decl_stmt|;
comment|/* Data alignment factor. */
name|Dwarf_Unsigned
name|cie_ra
decl_stmt|;
comment|/* Return address register. */
name|Dwarf_Unsigned
name|cie_auglen
decl_stmt|;
comment|/* Augmentation length. */
name|uint8_t
modifier|*
name|cie_augdata
decl_stmt|;
comment|/* Augmentation data; */
name|uint8_t
name|cie_fde_encode
decl_stmt|;
comment|/* FDE PC start/range encode. */
name|Dwarf_Ptr
name|cie_initinst
decl_stmt|;
comment|/* Initial instructions. */
name|Dwarf_Unsigned
name|cie_instlen
decl_stmt|;
comment|/* Length of init instructions. */
name|STAILQ_ENTRY
argument_list|(
argument|_Dwarf_Cie
argument_list|)
name|cie_next
expr_stmt|;
comment|/* Next CIE in list. */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|_Dwarf_FrameSec
block|{
name|STAILQ_HEAD
argument_list|(
argument_list|,
argument|_Dwarf_Cie
argument_list|)
name|fs_cielist
expr_stmt|;
comment|/* List of CIE. */
name|STAILQ_HEAD
argument_list|(
argument_list|,
argument|_Dwarf_Fde
argument_list|)
name|fs_fdelist
expr_stmt|;
comment|/* List of FDE. */
name|Dwarf_Cie
modifier|*
name|fs_ciearray
decl_stmt|;
comment|/* Array of CIE. */
name|Dwarf_Unsigned
name|fs_cielen
decl_stmt|;
comment|/* Length of CIE array. */
name|Dwarf_Fde
modifier|*
name|fs_fdearray
decl_stmt|;
comment|/* Array of FDE.*/
name|Dwarf_Unsigned
name|fs_fdelen
decl_stmt|;
comment|/* Length of FDE array. */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|_Dwarf_Arange
block|{
name|Dwarf_ArangeSet
name|ar_as
decl_stmt|;
comment|/* Ptr to the set it belongs to. */
name|Dwarf_Unsigned
name|ar_address
decl_stmt|;
comment|/* Start PC. */
name|Dwarf_Unsigned
name|ar_range
decl_stmt|;
comment|/* PC range. */
name|Dwarf_Unsigned
name|ar_symndx
decl_stmt|;
comment|/* First symbol index for reloc. */
name|Dwarf_Unsigned
name|ar_esymndx
decl_stmt|;
comment|/* Second symbol index for reloc. */
name|Dwarf_Addr
name|ar_eoff
decl_stmt|;
comment|/* Offset from second symbol. */
name|STAILQ_ENTRY
argument_list|(
argument|_Dwarf_Arange
argument_list|)
name|ar_next
expr_stmt|;
comment|/* Next arange in list. */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|_Dwarf_ArangeSet
block|{
name|Dwarf_Unsigned
name|as_length
decl_stmt|;
comment|/* Length of the arange set. */
name|Dwarf_Half
name|as_version
decl_stmt|;
comment|/* Version of the arange set. */
name|Dwarf_Off
name|as_cu_offset
decl_stmt|;
comment|/* Offset of associated CU. */
name|Dwarf_CU
name|as_cu
decl_stmt|;
comment|/* Ptr to associated CU. */
name|Dwarf_Small
name|as_addrsz
decl_stmt|;
comment|/* Target address size. */
name|Dwarf_Small
name|as_segsz
decl_stmt|;
comment|/* Target segment size. */
name|STAILQ_HEAD
argument_list|(
argument_list|,
argument|_Dwarf_Arange
argument_list|)
name|as_arlist
expr_stmt|;
comment|/* List of ae entries. */
name|STAILQ_ENTRY
argument_list|(
argument|_Dwarf_ArangeSet
argument_list|)
name|as_next
expr_stmt|;
comment|/* Next set in list. */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|_Dwarf_MacroSet
block|{
name|Dwarf_Macro_Details
modifier|*
name|ms_mdlist
decl_stmt|;
comment|/* Array of macinfo entries. */
name|Dwarf_Unsigned
name|ms_cnt
decl_stmt|;
comment|/* Length of the array. */
name|STAILQ_ENTRY
argument_list|(
argument|_Dwarf_MacroSet
argument_list|)
name|ms_next
expr_stmt|;
comment|/* Next set in list. */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|_Dwarf_Rangelist
block|{
name|Dwarf_CU
name|rl_cu
decl_stmt|;
comment|/* Ptr to associated CU. */
name|Dwarf_Unsigned
name|rl_offset
decl_stmt|;
comment|/* Offset of the rangelist. */
name|Dwarf_Ranges
modifier|*
name|rl_rgarray
decl_stmt|;
comment|/* Array of ranges. */
name|Dwarf_Unsigned
name|rl_rglen
decl_stmt|;
comment|/* Length of the ranges array. */
name|STAILQ_ENTRY
argument_list|(
argument|_Dwarf_Rangelist
argument_list|)
name|rl_next
expr_stmt|;
comment|/* Next rangelist in list. */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|_Dwarf_CU
block|{
name|Dwarf_Debug
name|cu_dbg
decl_stmt|;
comment|/* Ptr to containing dbg. */
name|Dwarf_Off
name|cu_offset
decl_stmt|;
comment|/* Offset to the this CU. */
name|uint32_t
name|cu_length
decl_stmt|;
comment|/* Length of CU data. */
name|uint16_t
name|cu_length_size
decl_stmt|;
comment|/* Size in bytes of the length field. */
name|uint16_t
name|cu_version
decl_stmt|;
comment|/* DWARF version. */
name|uint64_t
name|cu_abbrev_offset
decl_stmt|;
comment|/* Offset into .debug_abbrev. */
name|uint64_t
name|cu_abbrev_offset_cur
decl_stmt|;
comment|/* Current abbrev offset. */
name|int
name|cu_abbrev_loaded
decl_stmt|;
comment|/* Abbrev table parsed. */
name|uint64_t
name|cu_abbrev_cnt
decl_stmt|;
comment|/* Abbrev entry count. */
name|uint64_t
name|cu_lineno_offset
decl_stmt|;
comment|/* Offset into .debug_lineno. */
name|uint8_t
name|cu_pointer_size
decl_stmt|;
comment|/* Number of bytes in pointer. */
name|uint8_t
name|cu_dwarf_size
decl_stmt|;
comment|/* CU section dwarf size. */
name|Dwarf_Off
name|cu_next_offset
decl_stmt|;
comment|/* Offset to the next CU. */
name|uint64_t
name|cu_1st_offset
decl_stmt|;
comment|/* First DIE offset. */
name|int
name|cu_pass2
decl_stmt|;
comment|/* Two pass DIE traverse. */
name|Dwarf_LineInfo
name|cu_lineinfo
decl_stmt|;
comment|/* Ptr to Dwarf_LineInfo. */
name|Dwarf_Abbrev
name|cu_abbrev_hash
decl_stmt|;
comment|/* Abbrev hash table. */
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
name|_Dwarf_Section
block|{
specifier|const
name|char
modifier|*
name|ds_name
decl_stmt|;
comment|/* Section name. */
name|Dwarf_Small
modifier|*
name|ds_data
decl_stmt|;
comment|/* Section data. */
name|Dwarf_Unsigned
name|ds_addr
decl_stmt|;
comment|/* Section virtual addr. */
name|Dwarf_Unsigned
name|ds_size
decl_stmt|;
comment|/* Section size. */
block|}
name|Dwarf_Section
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_Dwarf_P_Section
block|{
name|char
modifier|*
name|ds_name
decl_stmt|;
comment|/* Section name. */
name|Dwarf_Small
modifier|*
name|ds_data
decl_stmt|;
comment|/* Section data. */
name|Dwarf_Unsigned
name|ds_size
decl_stmt|;
comment|/* Section size. */
name|Dwarf_Unsigned
name|ds_cap
decl_stmt|;
comment|/* Section capacity. */
name|Dwarf_Unsigned
name|ds_ndx
decl_stmt|;
comment|/* ELF section index. */
name|Dwarf_Unsigned
name|ds_symndx
decl_stmt|;
comment|/* Section symbol index. (for reloc) */
name|STAILQ_ENTRY
argument_list|(
argument|_Dwarf_P_Section
argument_list|)
name|ds_next
expr_stmt|;
comment|/* Next section in the list. */
block|}
typedef|*
name|Dwarf_P_Section
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_Dwarf_Rel_Entry
block|{
name|unsigned
name|char
name|dre_type
decl_stmt|;
comment|/* Reloc type. */
name|unsigned
name|char
name|dre_length
decl_stmt|;
comment|/* Reloc storage unit length. */
name|Dwarf_Unsigned
name|dre_offset
decl_stmt|;
comment|/* Reloc storage unit offset. */
name|Dwarf_Unsigned
name|dre_addend
decl_stmt|;
comment|/* Reloc addend. */
name|Dwarf_Unsigned
name|dre_symndx
decl_stmt|;
comment|/* Reloc symbol index. */
specifier|const
name|char
modifier|*
name|dre_secname
decl_stmt|;
comment|/* Refer to some debug section. */
name|STAILQ_ENTRY
argument_list|(
argument|_Dwarf_Rel_Entry
argument_list|)
name|dre_next
expr_stmt|;
comment|/* Next reloc entry. */
block|}
typedef|*
name|Dwarf_Rel_Entry
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_Dwarf_Rel_Section
block|{
name|struct
name|_Dwarf_P_Section
modifier|*
name|drs_ds
decl_stmt|;
comment|/* Ptr to actual reloc ELF section. */
name|struct
name|_Dwarf_P_Section
modifier|*
name|drs_ref
decl_stmt|;
comment|/* Which debug section it refers. */
name|struct
name|Dwarf_Relocation_Data_s
modifier|*
name|drs_drd
decl_stmt|;
comment|/* Reloc data array. */
name|STAILQ_HEAD
argument_list|(
argument_list|,
argument|_Dwarf_Rel_Entry
argument_list|)
name|drs_dre
expr_stmt|;
comment|/* Reloc entry list. */
name|Dwarf_Unsigned
name|drs_drecnt
decl_stmt|;
comment|/* Count of entries. */
name|Dwarf_Unsigned
name|drs_size
decl_stmt|;
comment|/* Size of ELF section in bytes. */
name|int
name|drs_addend
decl_stmt|;
comment|/* Elf_Rel or Elf_Rela */
name|STAILQ_ENTRY
argument_list|(
argument|_Dwarf_Rel_Section
argument_list|)
name|drs_next
expr_stmt|;
comment|/* Next reloc section. */
block|}
typedef|*
name|Dwarf_Rel_Section
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|Elf_Data
modifier|*
name|ed_data
decl_stmt|;
name|void
modifier|*
name|ed_alloc
decl_stmt|;
block|}
name|Dwarf_Elf_Data
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|Elf
modifier|*
name|eo_elf
decl_stmt|;
name|GElf_Ehdr
name|eo_ehdr
decl_stmt|;
name|GElf_Shdr
modifier|*
name|eo_shdr
decl_stmt|;
name|Dwarf_Elf_Data
modifier|*
name|eo_data
decl_stmt|;
name|Dwarf_Unsigned
name|eo_seccnt
decl_stmt|;
name|size_t
name|eo_strndx
decl_stmt|;
name|Dwarf_Obj_Access_Methods
name|eo_methods
decl_stmt|;
block|}
name|Dwarf_Elf_Object
typedef|;
end_typedef

begin_struct
struct|struct
name|_Dwarf_Debug
block|{
name|Dwarf_Obj_Access_Interface
modifier|*
name|dbg_iface
decl_stmt|;
name|Dwarf_Section
modifier|*
name|dbg_section
decl_stmt|;
comment|/* Dwarf section list. */
name|Dwarf_Section
modifier|*
name|dbg_info_sec
decl_stmt|;
comment|/* Pointer to info section. */
name|Dwarf_Off
name|dbg_info_off
decl_stmt|;
comment|/* Current info section offset. */
name|Dwarf_Unsigned
name|dbg_seccnt
decl_stmt|;
comment|/* Total number of dwarf sections. */
name|int
name|dbg_mode
decl_stmt|;
comment|/* Access mode. */
name|int
name|dbg_pointer_size
decl_stmt|;
comment|/* Object address size. */
name|int
name|dbg_offset_size
decl_stmt|;
comment|/* DWARF offset size. */
name|int
name|dbg_info_loaded
decl_stmt|;
comment|/* Flag indicating all CU loaded. */
name|Dwarf_Half
name|dbg_machine
decl_stmt|;
comment|/* ELF machine architecture. */
name|Dwarf_Handler
name|dbg_errhand
decl_stmt|;
comment|/* Error handler. */
name|Dwarf_Ptr
name|dbg_errarg
decl_stmt|;
comment|/* Argument to the error handler. */
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
comment|/* Ptr to the current CU. */
name|TAILQ_HEAD
argument_list|(
argument_list|,
argument|_Dwarf_Loclist
argument_list|)
name|dbg_loclist
expr_stmt|;
comment|/* List of location list. */
name|Dwarf_NameSec
name|dbg_globals
decl_stmt|;
comment|/* Ptr to pubnames lookup section. */
name|Dwarf_NameSec
name|dbg_pubtypes
decl_stmt|;
comment|/* Ptr to pubtypes lookup section. */
name|Dwarf_NameSec
name|dbg_weaks
decl_stmt|;
comment|/* Ptr to weaknames lookup section. */
name|Dwarf_NameSec
name|dbg_funcs
decl_stmt|;
comment|/* Ptr to static funcs lookup sect. */
name|Dwarf_NameSec
name|dbg_vars
decl_stmt|;
comment|/* Ptr to static vars lookup sect. */
name|Dwarf_NameSec
name|dbg_types
decl_stmt|;
comment|/* Ptr to types lookup section. */
name|Dwarf_FrameSec
name|dbg_frame
decl_stmt|;
comment|/* Ptr to .debug_frame section. */
name|Dwarf_FrameSec
name|dbg_eh_frame
decl_stmt|;
comment|/* Ptr to .eh_frame section. */
name|STAILQ_HEAD
argument_list|(
argument_list|,
argument|_Dwarf_ArangeSet
argument_list|)
name|dbg_aslist
expr_stmt|;
comment|/* List of arange set. */
name|Dwarf_Arange
modifier|*
name|dbg_arange_array
decl_stmt|;
comment|/* Array of arange. */
name|Dwarf_Unsigned
name|dbg_arange_cnt
decl_stmt|;
comment|/* Length of the arange array. */
name|char
modifier|*
name|dbg_strtab
decl_stmt|;
comment|/* Dwarf string table. */
name|Dwarf_Unsigned
name|dbg_strtab_cap
decl_stmt|;
comment|/* Dwarf string table capacity. */
name|Dwarf_Unsigned
name|dbg_strtab_size
decl_stmt|;
comment|/* Dwarf string table size. */
name|STAILQ_HEAD
argument_list|(
argument_list|,
argument|_Dwarf_MacroSet
argument_list|)
name|dbg_mslist
expr_stmt|;
comment|/* List of macro set. */
name|STAILQ_HEAD
argument_list|(
argument_list|,
argument|_Dwarf_Rangelist
argument_list|)
name|dbg_rllist
expr_stmt|;
comment|/* List of rangelist. */
name|uint64_t
function_decl|(
modifier|*
name|read
function_decl|)
parameter_list|(
name|uint8_t
modifier|*
parameter_list|,
name|uint64_t
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
name|void
function_decl|(
modifier|*
name|write
function_decl|)
parameter_list|(
name|uint8_t
modifier|*
parameter_list|,
name|uint64_t
modifier|*
parameter_list|,
name|uint64_t
parameter_list|,
name|int
parameter_list|)
function_decl|;
name|int
function_decl|(
modifier|*
name|write_alloc
function_decl|)
parameter_list|(
name|uint8_t
modifier|*
modifier|*
parameter_list|,
name|uint64_t
modifier|*
parameter_list|,
name|uint64_t
modifier|*
parameter_list|,
name|uint64_t
parameter_list|,
name|int
parameter_list|,
name|Dwarf_Error
modifier|*
parameter_list|)
function_decl|;
name|uint64_t
function_decl|(
modifier|*
name|decode
function_decl|)
parameter_list|(
name|uint8_t
modifier|*
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
name|Dwarf_Half
name|dbg_frame_rule_table_size
decl_stmt|;
name|Dwarf_Half
name|dbg_frame_rule_initial_value
decl_stmt|;
name|Dwarf_Half
name|dbg_frame_cfa_value
decl_stmt|;
name|Dwarf_Half
name|dbg_frame_same_value
decl_stmt|;
name|Dwarf_Half
name|dbg_frame_undefined_value
decl_stmt|;
name|Dwarf_Regtable3
modifier|*
name|dbg_internal_reg_table
decl_stmt|;
comment|/* 	 * Fields used by libdwarf producer. 	 */
name|Dwarf_Unsigned
name|dbgp_flags
decl_stmt|;
name|Dwarf_Unsigned
name|dbgp_isa
decl_stmt|;
name|Dwarf_Callback_Func
name|dbgp_func
decl_stmt|;
name|Dwarf_Callback_Func_b
name|dbgp_func_b
decl_stmt|;
name|Dwarf_Die
name|dbgp_root_die
decl_stmt|;
name|STAILQ_HEAD
argument_list|(
argument_list|,
argument|_Dwarf_Die
argument_list|)
name|dbgp_dielist
expr_stmt|;
name|STAILQ_HEAD
argument_list|(
argument_list|,
argument|_Dwarf_P_Expr
argument_list|)
name|dbgp_pelist
expr_stmt|;
name|Dwarf_LineInfo
name|dbgp_lineinfo
decl_stmt|;
name|Dwarf_ArangeSet
name|dbgp_as
decl_stmt|;
name|Dwarf_Macro_Details
modifier|*
name|dbgp_mdlist
decl_stmt|;
name|Dwarf_Unsigned
name|dbgp_mdcnt
decl_stmt|;
name|STAILQ_HEAD
argument_list|(
argument_list|,
argument|_Dwarf_Cie
argument_list|)
name|dbgp_cielist
expr_stmt|;
name|STAILQ_HEAD
argument_list|(
argument_list|,
argument|_Dwarf_Fde
argument_list|)
name|dbgp_fdelist
expr_stmt|;
name|Dwarf_Unsigned
name|dbgp_cielen
decl_stmt|;
name|Dwarf_Unsigned
name|dbgp_fdelen
decl_stmt|;
name|Dwarf_NameTbl
name|dbgp_pubs
decl_stmt|;
name|Dwarf_NameTbl
name|dbgp_weaks
decl_stmt|;
name|Dwarf_NameTbl
name|dbgp_funcs
decl_stmt|;
name|Dwarf_NameTbl
name|dbgp_types
decl_stmt|;
name|Dwarf_NameTbl
name|dbgp_vars
decl_stmt|;
name|STAILQ_HEAD
argument_list|(
argument_list|,
argument|_Dwarf_P_Section
argument_list|)
name|dbgp_seclist
expr_stmt|;
name|Dwarf_Unsigned
name|dbgp_seccnt
decl_stmt|;
name|Dwarf_P_Section
name|dbgp_secpos
decl_stmt|;
name|Dwarf_P_Section
name|dbgp_info
decl_stmt|;
name|STAILQ_HEAD
argument_list|(
argument_list|,
argument|_Dwarf_Rel_Section
argument_list|)
name|dbgp_drslist
expr_stmt|;
name|Dwarf_Unsigned
name|dbgp_drscnt
decl_stmt|;
name|Dwarf_Rel_Section
name|dbgp_drspos
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * Internal function prototypes.  */
end_comment

begin_function_decl
name|int
name|_dwarf_abbrev_add
parameter_list|(
name|Dwarf_CU
parameter_list|,
name|uint64_t
parameter_list|,
name|uint64_t
parameter_list|,
name|uint8_t
parameter_list|,
name|uint64_t
parameter_list|,
name|Dwarf_Abbrev
modifier|*
parameter_list|,
name|Dwarf_Error
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|_dwarf_abbrev_cleanup
parameter_list|(
name|Dwarf_CU
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|_dwarf_abbrev_find
parameter_list|(
name|Dwarf_CU
parameter_list|,
name|uint64_t
parameter_list|,
name|Dwarf_Abbrev
modifier|*
parameter_list|,
name|Dwarf_Error
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|_dwarf_abbrev_gen
parameter_list|(
name|Dwarf_P_Debug
parameter_list|,
name|Dwarf_Error
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|_dwarf_abbrev_parse
parameter_list|(
name|Dwarf_Debug
parameter_list|,
name|Dwarf_CU
parameter_list|,
name|Dwarf_Unsigned
modifier|*
parameter_list|,
name|Dwarf_Abbrev
modifier|*
parameter_list|,
name|Dwarf_Error
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|_dwarf_add_AT_dataref
parameter_list|(
name|Dwarf_P_Debug
parameter_list|,
name|Dwarf_P_Die
parameter_list|,
name|Dwarf_Half
parameter_list|,
name|Dwarf_Unsigned
parameter_list|,
name|Dwarf_Unsigned
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
name|Dwarf_P_Attribute
modifier|*
parameter_list|,
name|Dwarf_Error
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|_dwarf_add_string_attr
parameter_list|(
name|Dwarf_P_Die
parameter_list|,
name|Dwarf_P_Attribute
modifier|*
parameter_list|,
name|Dwarf_Half
parameter_list|,
name|char
modifier|*
parameter_list|,
name|Dwarf_Error
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|_dwarf_alloc
parameter_list|(
name|Dwarf_Debug
modifier|*
parameter_list|,
name|int
parameter_list|,
name|Dwarf_Error
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|_dwarf_arange_cleanup
parameter_list|(
name|Dwarf_Debug
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|_dwarf_arange_gen
parameter_list|(
name|Dwarf_P_Debug
parameter_list|,
name|Dwarf_Error
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|_dwarf_arange_init
parameter_list|(
name|Dwarf_Debug
parameter_list|,
name|Dwarf_Error
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|_dwarf_arange_pro_cleanup
parameter_list|(
name|Dwarf_P_Debug
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|_dwarf_attr_alloc
parameter_list|(
name|Dwarf_Die
parameter_list|,
name|Dwarf_Attribute
modifier|*
parameter_list|,
name|Dwarf_Error
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|Dwarf_Attribute
name|_dwarf_attr_find
parameter_list|(
name|Dwarf_Die
parameter_list|,
name|Dwarf_Half
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|_dwarf_attr_gen
parameter_list|(
name|Dwarf_P_Debug
parameter_list|,
name|Dwarf_P_Section
parameter_list|,
name|Dwarf_Rel_Section
parameter_list|,
name|Dwarf_CU
parameter_list|,
name|Dwarf_Die
parameter_list|,
name|int
parameter_list|,
name|Dwarf_Error
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|_dwarf_attr_init
parameter_list|(
name|Dwarf_Debug
parameter_list|,
name|Dwarf_Section
modifier|*
parameter_list|,
name|uint64_t
modifier|*
parameter_list|,
name|int
parameter_list|,
name|Dwarf_CU
parameter_list|,
name|Dwarf_Die
parameter_list|,
name|Dwarf_AttrDef
parameter_list|,
name|uint64_t
parameter_list|,
name|int
parameter_list|,
name|Dwarf_Error
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|_dwarf_attrdef_add
parameter_list|(
name|Dwarf_Debug
parameter_list|,
name|Dwarf_Abbrev
parameter_list|,
name|uint64_t
parameter_list|,
name|uint64_t
parameter_list|,
name|uint64_t
parameter_list|,
name|Dwarf_AttrDef
modifier|*
parameter_list|,
name|Dwarf_Error
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|uint64_t
name|_dwarf_decode_lsb
parameter_list|(
name|uint8_t
modifier|*
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|uint64_t
name|_dwarf_decode_msb
parameter_list|(
name|uint8_t
modifier|*
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int64_t
name|_dwarf_decode_sleb128
parameter_list|(
name|uint8_t
modifier|*
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|uint64_t
name|_dwarf_decode_uleb128
parameter_list|(
name|uint8_t
modifier|*
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|_dwarf_deinit
parameter_list|(
name|Dwarf_Debug
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|_dwarf_die_alloc
parameter_list|(
name|Dwarf_Debug
parameter_list|,
name|Dwarf_Die
modifier|*
parameter_list|,
name|Dwarf_Error
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|_dwarf_die_count_links
parameter_list|(
name|Dwarf_P_Die
parameter_list|,
name|Dwarf_P_Die
parameter_list|,
name|Dwarf_P_Die
parameter_list|,
name|Dwarf_P_Die
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|Dwarf_Die
name|_dwarf_die_find
parameter_list|(
name|Dwarf_Die
parameter_list|,
name|Dwarf_Unsigned
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|_dwarf_die_gen
parameter_list|(
name|Dwarf_P_Debug
parameter_list|,
name|Dwarf_CU
parameter_list|,
name|Dwarf_Rel_Section
parameter_list|,
name|Dwarf_Error
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|_dwarf_die_link
parameter_list|(
name|Dwarf_P_Die
parameter_list|,
name|Dwarf_P_Die
parameter_list|,
name|Dwarf_P_Die
parameter_list|,
name|Dwarf_P_Die
parameter_list|,
name|Dwarf_P_Die
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|_dwarf_die_parse
parameter_list|(
name|Dwarf_Debug
parameter_list|,
name|Dwarf_Section
modifier|*
parameter_list|,
name|Dwarf_CU
parameter_list|,
name|int
parameter_list|,
name|uint64_t
parameter_list|,
name|uint64_t
parameter_list|,
name|Dwarf_Die
modifier|*
parameter_list|,
name|int
parameter_list|,
name|Dwarf_Error
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|_dwarf_die_pro_cleanup
parameter_list|(
name|Dwarf_P_Debug
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|_dwarf_elf_deinit
parameter_list|(
name|Dwarf_Debug
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|_dwarf_elf_init
parameter_list|(
name|Dwarf_Debug
parameter_list|,
name|Elf
modifier|*
parameter_list|,
name|Dwarf_Error
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|_dwarf_elf_load_section
parameter_list|(
name|void
modifier|*
parameter_list|,
name|Dwarf_Half
parameter_list|,
name|Dwarf_Small
modifier|*
modifier|*
parameter_list|,
name|int
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|Dwarf_Endianness
name|_dwarf_elf_get_byte_order
parameter_list|(
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|Dwarf_Small
name|_dwarf_elf_get_length_size
parameter_list|(
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|Dwarf_Small
name|_dwarf_elf_get_pointer_size
parameter_list|(
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|Dwarf_Unsigned
name|_dwarf_elf_get_section_count
parameter_list|(
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|_dwarf_elf_get_section_info
parameter_list|(
name|void
modifier|*
parameter_list|,
name|Dwarf_Half
parameter_list|,
name|Dwarf_Obj_Access_Section
modifier|*
parameter_list|,
name|int
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|_dwarf_expr_cleanup
parameter_list|(
name|Dwarf_P_Debug
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|_dwarf_expr_into_block
parameter_list|(
name|Dwarf_P_Expr
parameter_list|,
name|Dwarf_Error
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|Dwarf_Section
modifier|*
name|_dwarf_find_section
parameter_list|(
name|Dwarf_Debug
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|_dwarf_frame_cleanup
parameter_list|(
name|Dwarf_Debug
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|_dwarf_frame_fde_add_inst
parameter_list|(
name|Dwarf_P_Fde
parameter_list|,
name|Dwarf_Small
parameter_list|,
name|Dwarf_Unsigned
parameter_list|,
name|Dwarf_Unsigned
parameter_list|,
name|Dwarf_Error
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|_dwarf_frame_gen
parameter_list|(
name|Dwarf_P_Debug
parameter_list|,
name|Dwarf_Error
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|_dwarf_frame_get_fop
parameter_list|(
name|Dwarf_Debug
parameter_list|,
name|uint8_t
modifier|*
parameter_list|,
name|Dwarf_Unsigned
parameter_list|,
name|Dwarf_Frame_Op
modifier|*
modifier|*
parameter_list|,
name|Dwarf_Signed
modifier|*
parameter_list|,
name|Dwarf_Error
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|_dwarf_frame_get_internal_table
parameter_list|(
name|Dwarf_Fde
parameter_list|,
name|Dwarf_Addr
parameter_list|,
name|Dwarf_Regtable3
modifier|*
modifier|*
parameter_list|,
name|Dwarf_Addr
modifier|*
parameter_list|,
name|Dwarf_Error
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|_dwarf_frame_interal_table_init
parameter_list|(
name|Dwarf_Debug
parameter_list|,
name|Dwarf_Error
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|_dwarf_frame_params_init
parameter_list|(
name|Dwarf_Debug
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|_dwarf_frame_pro_cleanup
parameter_list|(
name|Dwarf_P_Debug
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|_dwarf_frame_regtable_copy
parameter_list|(
name|Dwarf_Debug
parameter_list|,
name|Dwarf_Regtable3
modifier|*
modifier|*
parameter_list|,
name|Dwarf_Regtable3
modifier|*
parameter_list|,
name|Dwarf_Error
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|_dwarf_frame_section_load
parameter_list|(
name|Dwarf_Debug
parameter_list|,
name|Dwarf_Error
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|_dwarf_frame_section_load_eh
parameter_list|(
name|Dwarf_Debug
parameter_list|,
name|Dwarf_Error
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|_dwarf_generate_sections
parameter_list|(
name|Dwarf_P_Debug
parameter_list|,
name|Dwarf_Error
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|Dwarf_Unsigned
name|_dwarf_get_reloc_type
parameter_list|(
name|Dwarf_P_Debug
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|_dwarf_get_reloc_size
parameter_list|(
name|Dwarf_Debug
parameter_list|,
name|Dwarf_Unsigned
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|_dwarf_info_cleanup
parameter_list|(
name|Dwarf_Debug
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|_dwarf_info_first_cu
parameter_list|(
name|Dwarf_Debug
parameter_list|,
name|Dwarf_Error
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|_dwarf_info_gen
parameter_list|(
name|Dwarf_P_Debug
parameter_list|,
name|Dwarf_Error
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|_dwarf_info_load
parameter_list|(
name|Dwarf_Debug
parameter_list|,
name|int
parameter_list|,
name|Dwarf_Error
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|_dwarf_info_next_cu
parameter_list|(
name|Dwarf_Debug
parameter_list|,
name|Dwarf_Error
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|_dwarf_info_pro_cleanup
parameter_list|(
name|Dwarf_P_Debug
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|_dwarf_init
parameter_list|(
name|Dwarf_Debug
parameter_list|,
name|Dwarf_Unsigned
parameter_list|,
name|Dwarf_Handler
parameter_list|,
name|Dwarf_Ptr
parameter_list|,
name|Dwarf_Error
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|_dwarf_lineno_gen
parameter_list|(
name|Dwarf_P_Debug
parameter_list|,
name|Dwarf_Error
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|_dwarf_lineno_init
parameter_list|(
name|Dwarf_Die
parameter_list|,
name|uint64_t
parameter_list|,
name|Dwarf_Error
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|_dwarf_lineno_cleanup
parameter_list|(
name|Dwarf_LineInfo
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|_dwarf_lineno_pro_cleanup
parameter_list|(
name|Dwarf_P_Debug
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|_dwarf_loc_fill_locdesc
parameter_list|(
name|Dwarf_Debug
parameter_list|,
name|Dwarf_Locdesc
modifier|*
parameter_list|,
name|uint8_t
modifier|*
parameter_list|,
name|uint64_t
parameter_list|,
name|uint8_t
parameter_list|,
name|Dwarf_Error
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|_dwarf_loc_fill_locexpr
parameter_list|(
name|Dwarf_Debug
parameter_list|,
name|Dwarf_Locdesc
modifier|*
modifier|*
parameter_list|,
name|uint8_t
modifier|*
parameter_list|,
name|uint64_t
parameter_list|,
name|uint8_t
parameter_list|,
name|Dwarf_Error
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|_dwarf_loc_add
parameter_list|(
name|Dwarf_Die
parameter_list|,
name|Dwarf_Attribute
parameter_list|,
name|Dwarf_Error
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|_dwarf_loc_expr_add_atom
parameter_list|(
name|Dwarf_Debug
parameter_list|,
name|uint8_t
modifier|*
parameter_list|,
name|uint8_t
modifier|*
parameter_list|,
name|Dwarf_Small
parameter_list|,
name|Dwarf_Unsigned
parameter_list|,
name|Dwarf_Unsigned
parameter_list|,
name|int
modifier|*
parameter_list|,
name|Dwarf_Error
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|_dwarf_loclist_find
parameter_list|(
name|Dwarf_Debug
parameter_list|,
name|Dwarf_CU
parameter_list|,
name|uint64_t
parameter_list|,
name|Dwarf_Loclist
modifier|*
parameter_list|,
name|Dwarf_Error
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|_dwarf_loclist_cleanup
parameter_list|(
name|Dwarf_Debug
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|_dwarf_loclist_free
parameter_list|(
name|Dwarf_Loclist
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|_dwarf_loclist_add
parameter_list|(
name|Dwarf_Debug
parameter_list|,
name|Dwarf_CU
parameter_list|,
name|uint64_t
parameter_list|,
name|Dwarf_Loclist
modifier|*
parameter_list|,
name|Dwarf_Error
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|_dwarf_macinfo_cleanup
parameter_list|(
name|Dwarf_Debug
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|_dwarf_macinfo_gen
parameter_list|(
name|Dwarf_P_Debug
parameter_list|,
name|Dwarf_Error
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|_dwarf_macinfo_init
parameter_list|(
name|Dwarf_Debug
parameter_list|,
name|Dwarf_Error
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|_dwarf_macinfo_pro_cleanup
parameter_list|(
name|Dwarf_P_Debug
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|_dwarf_nametbl_init
parameter_list|(
name|Dwarf_Debug
parameter_list|,
name|Dwarf_NameSec
modifier|*
parameter_list|,
name|Dwarf_Section
modifier|*
parameter_list|,
name|Dwarf_Error
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|_dwarf_nametbl_cleanup
parameter_list|(
name|Dwarf_NameSec
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|_dwarf_nametbl_gen
parameter_list|(
name|Dwarf_P_Debug
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
name|Dwarf_NameTbl
parameter_list|,
name|Dwarf_Error
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|_dwarf_nametbl_pro_cleanup
parameter_list|(
name|Dwarf_NameTbl
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|_dwarf_pro_callback
parameter_list|(
name|Dwarf_P_Debug
parameter_list|,
name|char
modifier|*
parameter_list|,
name|int
parameter_list|,
name|Dwarf_Unsigned
parameter_list|,
name|Dwarf_Unsigned
parameter_list|,
name|Dwarf_Unsigned
parameter_list|,
name|Dwarf_Unsigned
parameter_list|,
name|Dwarf_Unsigned
modifier|*
parameter_list|,
name|int
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|Dwarf_P_Section
name|_dwarf_pro_find_section
parameter_list|(
name|Dwarf_P_Debug
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|_dwarf_ranges_add
parameter_list|(
name|Dwarf_Debug
parameter_list|,
name|Dwarf_CU
parameter_list|,
name|uint64_t
parameter_list|,
name|Dwarf_Rangelist
modifier|*
parameter_list|,
name|Dwarf_Error
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|_dwarf_ranges_cleanup
parameter_list|(
name|Dwarf_Debug
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|_dwarf_ranges_find
parameter_list|(
name|Dwarf_Debug
parameter_list|,
name|uint64_t
parameter_list|,
name|Dwarf_Rangelist
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|uint64_t
name|_dwarf_read_lsb
parameter_list|(
name|uint8_t
modifier|*
parameter_list|,
name|uint64_t
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|uint64_t
name|_dwarf_read_msb
parameter_list|(
name|uint8_t
modifier|*
parameter_list|,
name|uint64_t
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int64_t
name|_dwarf_read_sleb128
parameter_list|(
name|uint8_t
modifier|*
parameter_list|,
name|uint64_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|uint64_t
name|_dwarf_read_uleb128
parameter_list|(
name|uint8_t
modifier|*
parameter_list|,
name|uint64_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|_dwarf_read_string
parameter_list|(
name|void
modifier|*
parameter_list|,
name|Dwarf_Unsigned
parameter_list|,
name|uint64_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|uint8_t
modifier|*
name|_dwarf_read_block
parameter_list|(
name|void
modifier|*
parameter_list|,
name|uint64_t
modifier|*
parameter_list|,
name|uint64_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|_dwarf_reloc_section_finalize
parameter_list|(
name|Dwarf_P_Debug
parameter_list|,
name|Dwarf_Rel_Section
parameter_list|,
name|Dwarf_Error
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|_dwarf_reloc_entry_add
parameter_list|(
name|Dwarf_P_Debug
parameter_list|,
name|Dwarf_Rel_Section
parameter_list|,
name|Dwarf_P_Section
parameter_list|,
name|unsigned
name|char
parameter_list|,
name|unsigned
name|char
parameter_list|,
name|Dwarf_Unsigned
parameter_list|,
name|Dwarf_Unsigned
parameter_list|,
name|Dwarf_Unsigned
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
name|Dwarf_Error
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|_dwarf_reloc_entry_add_pair
parameter_list|(
name|Dwarf_P_Debug
parameter_list|,
name|Dwarf_Rel_Section
parameter_list|,
name|Dwarf_P_Section
parameter_list|,
name|unsigned
name|char
parameter_list|,
name|Dwarf_Unsigned
parameter_list|,
name|Dwarf_Unsigned
parameter_list|,
name|Dwarf_Unsigned
parameter_list|,
name|Dwarf_Unsigned
parameter_list|,
name|Dwarf_Unsigned
parameter_list|,
name|Dwarf_Error
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|_dwarf_reloc_cleanup
parameter_list|(
name|Dwarf_P_Debug
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|_dwarf_reloc_gen
parameter_list|(
name|Dwarf_P_Debug
parameter_list|,
name|Dwarf_Error
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|_dwarf_reloc_section_gen
parameter_list|(
name|Dwarf_P_Debug
parameter_list|,
name|Dwarf_Rel_Section
parameter_list|,
name|Dwarf_Error
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|_dwarf_reloc_section_init
parameter_list|(
name|Dwarf_P_Debug
parameter_list|,
name|Dwarf_Rel_Section
modifier|*
parameter_list|,
name|Dwarf_P_Section
parameter_list|,
name|Dwarf_Error
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|_dwarf_reloc_section_free
parameter_list|(
name|Dwarf_P_Debug
parameter_list|,
name|Dwarf_Rel_Section
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|_dwarf_section_cleanup
parameter_list|(
name|Dwarf_P_Debug
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|_dwarf_section_callback
parameter_list|(
name|Dwarf_P_Debug
parameter_list|,
name|Dwarf_P_Section
parameter_list|,
name|Dwarf_Unsigned
parameter_list|,
name|Dwarf_Unsigned
parameter_list|,
name|Dwarf_Unsigned
parameter_list|,
name|Dwarf_Unsigned
parameter_list|,
name|Dwarf_Error
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|_dwarf_section_free
parameter_list|(
name|Dwarf_P_Debug
parameter_list|,
name|Dwarf_P_Section
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|_dwarf_section_init
parameter_list|(
name|Dwarf_P_Debug
parameter_list|,
name|Dwarf_P_Section
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
name|int
parameter_list|,
name|Dwarf_Error
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|_dwarf_set_error
parameter_list|(
name|Dwarf_Debug
parameter_list|,
name|Dwarf_Error
modifier|*
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|_dwarf_strtab_add
parameter_list|(
name|Dwarf_Debug
parameter_list|,
name|char
modifier|*
parameter_list|,
name|uint64_t
modifier|*
parameter_list|,
name|Dwarf_Error
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|_dwarf_strtab_cleanup
parameter_list|(
name|Dwarf_Debug
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|_dwarf_strtab_gen
parameter_list|(
name|Dwarf_P_Debug
parameter_list|,
name|Dwarf_Error
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|_dwarf_strtab_get_table
parameter_list|(
name|Dwarf_Debug
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|_dwarf_strtab_init
parameter_list|(
name|Dwarf_Debug
parameter_list|,
name|Dwarf_Error
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|_dwarf_write_block
parameter_list|(
name|void
modifier|*
parameter_list|,
name|uint64_t
modifier|*
parameter_list|,
name|uint8_t
modifier|*
parameter_list|,
name|uint64_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|_dwarf_write_block_alloc
parameter_list|(
name|uint8_t
modifier|*
modifier|*
parameter_list|,
name|uint64_t
modifier|*
parameter_list|,
name|uint64_t
modifier|*
parameter_list|,
name|uint8_t
modifier|*
parameter_list|,
name|uint64_t
parameter_list|,
name|Dwarf_Error
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|_dwarf_write_lsb
parameter_list|(
name|uint8_t
modifier|*
parameter_list|,
name|uint64_t
modifier|*
parameter_list|,
name|uint64_t
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|_dwarf_write_lsb_alloc
parameter_list|(
name|uint8_t
modifier|*
modifier|*
parameter_list|,
name|uint64_t
modifier|*
parameter_list|,
name|uint64_t
modifier|*
parameter_list|,
name|uint64_t
parameter_list|,
name|int
parameter_list|,
name|Dwarf_Error
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|_dwarf_write_msb
parameter_list|(
name|uint8_t
modifier|*
parameter_list|,
name|uint64_t
modifier|*
parameter_list|,
name|uint64_t
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|_dwarf_write_msb_alloc
parameter_list|(
name|uint8_t
modifier|*
modifier|*
parameter_list|,
name|uint64_t
modifier|*
parameter_list|,
name|uint64_t
modifier|*
parameter_list|,
name|uint64_t
parameter_list|,
name|int
parameter_list|,
name|Dwarf_Error
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|_dwarf_write_padding
parameter_list|(
name|void
modifier|*
parameter_list|,
name|uint64_t
modifier|*
parameter_list|,
name|uint8_t
parameter_list|,
name|uint64_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|_dwarf_write_padding_alloc
parameter_list|(
name|uint8_t
modifier|*
modifier|*
parameter_list|,
name|uint64_t
modifier|*
parameter_list|,
name|uint64_t
modifier|*
parameter_list|,
name|uint8_t
parameter_list|,
name|uint64_t
parameter_list|,
name|Dwarf_Error
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|_dwarf_write_string
parameter_list|(
name|void
modifier|*
parameter_list|,
name|uint64_t
modifier|*
parameter_list|,
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|_dwarf_write_string_alloc
parameter_list|(
name|uint8_t
modifier|*
modifier|*
parameter_list|,
name|uint64_t
modifier|*
parameter_list|,
name|uint64_t
modifier|*
parameter_list|,
name|char
modifier|*
parameter_list|,
name|Dwarf_Error
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|_dwarf_write_sleb128
parameter_list|(
name|uint8_t
modifier|*
parameter_list|,
name|uint8_t
modifier|*
parameter_list|,
name|int64_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|_dwarf_write_sleb128_alloc
parameter_list|(
name|uint8_t
modifier|*
modifier|*
parameter_list|,
name|uint64_t
modifier|*
parameter_list|,
name|uint64_t
modifier|*
parameter_list|,
name|int64_t
parameter_list|,
name|Dwarf_Error
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|_dwarf_write_uleb128
parameter_list|(
name|uint8_t
modifier|*
parameter_list|,
name|uint8_t
modifier|*
parameter_list|,
name|uint64_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|_dwarf_write_uleb128_alloc
parameter_list|(
name|uint8_t
modifier|*
modifier|*
parameter_list|,
name|uint64_t
modifier|*
parameter_list|,
name|uint64_t
modifier|*
parameter_list|,
name|uint64_t
parameter_list|,
name|Dwarf_Error
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !__LIBDWARF_H_ */
end_comment

end_unit

