begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* VMS object file format    Copyright 1989, 1990, 1991, 1992, 1993, 1994, 1995, 1996, 1997, 2000,    2002, 2003 Free Software Foundation, Inc.  This file is part of GAS, the GNU Assembler.  GAS is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2, or (at your option) any later version.  GAS is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with GAS; see the file COPYING.  If not, write to the Free Software Foundation, 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
end_comment

begin_comment
comment|/* Tag to validate a.out object file format processing */
end_comment

begin_define
define|#
directive|define
name|OBJ_VMS
value|1
end_define

begin_include
include|#
directive|include
file|"targ-cpu.h"
end_include

begin_define
define|#
directive|define
name|LONGWORD_ALIGNMENT
value|2
end_define

begin_comment
comment|/* This macro controls subsection alignment within a section.  *  * Under VAX/VMS, the linker (and PSECT specifications)  * take care of correctly aligning the segments.  * Doing the alignment here (on initialized data) can  * mess up the calculation of global data PSECT sizes.  */
end_comment

begin_define
define|#
directive|define
name|SUB_SEGMENT_ALIGN
parameter_list|(
name|SEG
parameter_list|,
name|FRCHAIN
parameter_list|)
define|\
value|(((SEG) == data_section) ? 0 : LONGWORD_ALIGNMENT)
end_define

begin_comment
comment|/* This flag is used to remember whether we are in the const or the    data section.  By and large they are identical, but we set a no-write    bit for psects in the const section.  */
end_comment

begin_decl_stmt
specifier|extern
name|unsigned
name|char
name|const_flag
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* This is overloaded onto const_flag, for convenience.  It's used to flag    dummy labels like "gcc2_compiled."  which occur before the first .text    or .data section directive.  */
end_comment

begin_define
define|#
directive|define
name|IN_DEFAULT_SECTION
value|0x80
end_define

begin_comment
comment|/* These are defined in obj-vms.c.  */
end_comment

begin_decl_stmt
specifier|extern
specifier|const
name|short
name|seg_N_TYPE
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
specifier|const
name|segT
name|N_TYPE_seg
index|[]
decl_stmt|;
end_decl_stmt

begin_undef
undef|#
directive|undef
name|NO_RELOC
end_undef

begin_enum
enum|enum
name|reloc_type
block|{
name|NO_RELOC
block|,
name|RELOC_32
block|}
enum|;
end_enum

begin_define
define|#
directive|define
name|N_BADMAG
parameter_list|(
name|x
parameter_list|)
value|(0)
end_define

begin_define
define|#
directive|define
name|N_TXTOFF
parameter_list|(
name|x
parameter_list|)
value|( sizeof (struct exec) )
end_define

begin_define
define|#
directive|define
name|N_DATOFF
parameter_list|(
name|x
parameter_list|)
value|( N_TXTOFF(x) + (x).a_text )
end_define

begin_define
define|#
directive|define
name|N_TROFF
parameter_list|(
name|x
parameter_list|)
value|( N_DATOFF(x) + (x).a_data )
end_define

begin_define
define|#
directive|define
name|N_DROFF
parameter_list|(
name|x
parameter_list|)
value|( N_TROFF(x) + (x).a_trsize )
end_define

begin_define
define|#
directive|define
name|N_SYMOFF
parameter_list|(
name|x
parameter_list|)
value|( N_DROFF(x) + (x).a_drsize )
end_define

begin_define
define|#
directive|define
name|N_STROFF
parameter_list|(
name|x
parameter_list|)
value|( N_SYMOFF(x) + (x).a_syms )
end_define

begin_comment
comment|/* We use this copy of the exec header for VMS.  We do not actually use it, but    what we actually do is let gas fill in the relevant slots, and when we get    around to writing an obj file, we just pick out what we need.  */
end_comment

begin_struct
struct|struct
name|exec
block|{
name|unsigned
name|long
name|a_text
decl_stmt|;
comment|/* length of text, in bytes */
name|unsigned
name|long
name|a_data
decl_stmt|;
comment|/* length of data, in bytes */
name|unsigned
name|long
name|a_bss
decl_stmt|;
comment|/* length of uninitialized data area for file, in bytes */
name|unsigned
name|long
name|a_trsize
decl_stmt|;
comment|/* length of relocation info for text, in bytes */
name|unsigned
name|long
name|a_drsize
decl_stmt|;
comment|/* length of relocation info for data, in bytes */
name|unsigned
name|long
name|a_entry
decl_stmt|;
comment|/* start address */
name|unsigned
name|long
name|a_syms
decl_stmt|;
comment|/* length of symbol table data in file, in bytes */
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
struct|struct
block|{
name|struct
name|exec
name|header
decl_stmt|;
comment|/* a.out header */
name|long
name|string_table_size
decl_stmt|;
comment|/* names + '\0' + sizeof (int) */
block|}
name|object_headers
typedef|;
end_typedef

begin_comment
comment|/* A single entry in the symbol table  * (this started as a clone of bout.h's nlist, but much was unneeded).  */
end_comment

begin_struct
struct|struct
name|nlist
block|{
name|char
modifier|*
name|n_name
decl_stmt|;
name|unsigned
name|char
name|n_type
decl_stmt|;
comment|/* See below				*/
name|unsigned
name|char
name|n_other
decl_stmt|;
comment|/* used for const_flag and "default section" */
name|unsigned
label|:
literal|16
expr_stmt|;
comment|/* padding for alignment */
name|int
name|n_desc
decl_stmt|;
comment|/* source line number for N_SLINE stabs */
block|}
struct|;
end_struct

begin_comment
comment|/* Legal values of n_type (see aout/stab.def for the majority of the codes).  */
end_comment

begin_define
define|#
directive|define
name|N_UNDF
value|0
end_define

begin_comment
comment|/* Undefined symbol	*/
end_comment

begin_define
define|#
directive|define
name|N_ABS
value|2
end_define

begin_comment
comment|/* Absolute symbol	*/
end_comment

begin_define
define|#
directive|define
name|N_TEXT
value|4
end_define

begin_comment
comment|/* Text symbol		*/
end_comment

begin_define
define|#
directive|define
name|N_DATA
value|6
end_define

begin_comment
comment|/* Data symbol		*/
end_comment

begin_define
define|#
directive|define
name|N_BSS
value|8
end_define

begin_comment
comment|/* BSS symbol		*/
end_comment

begin_define
define|#
directive|define
name|N_FN
value|31
end_define

begin_comment
comment|/* Filename symbol	*/
end_comment

begin_define
define|#
directive|define
name|N_EXT
value|1
end_define

begin_comment
comment|/* External symbol (OR'd in with one of above)	*/
end_comment

begin_define
define|#
directive|define
name|N_TYPE
value|036
end_define

begin_comment
comment|/* Mask for all the type bits			*/
end_comment

begin_define
define|#
directive|define
name|N_STAB
value|0340
end_define

begin_comment
comment|/* Mask for all bits used for SDB entries 	*/
end_comment

begin_include
include|#
directive|include
file|"aout/stab_gnu.h"
end_include

begin_comment
comment|/* SYMBOL TABLE */
end_comment

begin_comment
comment|/* Symbol table entry data type */
end_comment

begin_typedef
typedef|typedef
name|struct
name|nlist
name|obj_symbol_type
typedef|;
end_typedef

begin_comment
comment|/* Symbol table entry */
end_comment

begin_comment
comment|/* Symbol table macros and constants */
end_comment

begin_define
define|#
directive|define
name|OBJ_SYMFIELD_TYPE
value|struct VMS_Symbol *
end_define

begin_comment
comment|/*  *  Macros to extract information from a symbol table entry.  *  This syntactic indirection allows independence regarding a.out or coff.  *  The argument (s) of all these macros is a pointer to a symbol table entry.  */
end_comment

begin_comment
comment|/* True if the symbol is external */
end_comment

begin_define
define|#
directive|define
name|S_IS_EXTERNAL
parameter_list|(
name|s
parameter_list|)
value|((s)->sy_symbol.n_type& N_EXT)
end_define

begin_comment
comment|/* True if symbol has been defined, ie is in N_{TEXT,DATA,BSS,ABS} or N_EXT */
end_comment

begin_define
define|#
directive|define
name|S_IS_DEFINED
parameter_list|(
name|s
parameter_list|)
value|(S_GET_TYPE(s) != N_UNDF)
end_define

begin_define
define|#
directive|define
name|S_IS_COMMON
parameter_list|(
name|s
parameter_list|)
value|(S_GET_TYPE(s) == N_UNDF&& S_GET_VALUE(s) != 0)
end_define

begin_comment
comment|/* Return true for symbols that should not be reduced to section    symbols or eliminated from expressions, because they may be    overridden by the linker.  */
end_comment

begin_define
define|#
directive|define
name|S_FORCE_RELOC
parameter_list|(
name|s
parameter_list|,
name|strict
parameter_list|)
define|\
value|(!SEG_NORMAL (S_GET_SEGMENT (s)))
end_define

begin_define
define|#
directive|define
name|S_IS_REGISTER
parameter_list|(
name|s
parameter_list|)
value|((s)->sy_symbol.n_type == N_REGISTER)
end_define

begin_comment
comment|/* True if a debug special symbol entry */
end_comment

begin_define
define|#
directive|define
name|S_IS_DEBUG
parameter_list|(
name|s
parameter_list|)
value|((s)->sy_symbol.n_type& N_STAB)
end_define

begin_comment
comment|/* True if a symbol is local symbol name */
end_comment

begin_comment
comment|/* A symbol name whose name begin with ^A is a gas internal pseudo symbol    nameless symbols come from .stab directives.  */
end_comment

begin_define
define|#
directive|define
name|S_IS_LOCAL
parameter_list|(
name|s
parameter_list|)
value|(S_GET_NAME(s)&& \ 				 !S_IS_DEBUG(s)&& \ 				 (strchr(S_GET_NAME(s), '\001') != 0 || \ 				  strchr(S_GET_NAME(s), '\002') != 0 || \ 				  (S_LOCAL_NAME(s)&& !flag_keep_locals)))
end_define

begin_comment
comment|/* True if a symbol is not defined in this file */
end_comment

begin_define
define|#
directive|define
name|S_IS_EXTERN
parameter_list|(
name|s
parameter_list|)
value|((s)->sy_symbol.n_type& N_EXT)
end_define

begin_comment
comment|/* True if the symbol has been generated because of a .stabd directive */
end_comment

begin_define
define|#
directive|define
name|S_IS_STABD
parameter_list|(
name|s
parameter_list|)
value|(S_GET_NAME(s) == (char *)0)
end_define

begin_comment
comment|/* Accessors */
end_comment

begin_comment
comment|/* The name of the symbol */
end_comment

begin_define
define|#
directive|define
name|S_GET_NAME
parameter_list|(
name|s
parameter_list|)
value|((s)->sy_symbol.n_name)
end_define

begin_comment
comment|/* The pointer to the string table */
end_comment

begin_define
define|#
directive|define
name|S_GET_OFFSET
parameter_list|(
name|s
parameter_list|)
value|((s)->sy_name_offset)
end_define

begin_comment
comment|/* The raw type of the symbol */
end_comment

begin_define
define|#
directive|define
name|S_GET_RAW_TYPE
parameter_list|(
name|s
parameter_list|)
value|((s)->sy_symbol.n_type)
end_define

begin_comment
comment|/* The type of the symbol */
end_comment

begin_define
define|#
directive|define
name|S_GET_TYPE
parameter_list|(
name|s
parameter_list|)
value|((s)->sy_symbol.n_type& N_TYPE)
end_define

begin_comment
comment|/* The numeric value of the segment */
end_comment

begin_define
define|#
directive|define
name|S_GET_SEGMENT
parameter_list|(
name|s
parameter_list|)
value|(N_TYPE_seg[S_GET_TYPE(s)])
end_define

begin_comment
comment|/* The n_other expression value */
end_comment

begin_define
define|#
directive|define
name|S_GET_OTHER
parameter_list|(
name|s
parameter_list|)
value|((s)->sy_symbol.n_other)
end_define

begin_comment
comment|/* The n_desc expression value */
end_comment

begin_define
define|#
directive|define
name|S_GET_DESC
parameter_list|(
name|s
parameter_list|)
value|((s)->sy_symbol.n_desc)
end_define

begin_comment
comment|/* Modifiers */
end_comment

begin_comment
comment|/* Assume that a symbol cannot be simultaneously in more than on segment */
end_comment

begin_comment
comment|/* set segment */
end_comment

begin_define
define|#
directive|define
name|S_SET_SEGMENT
parameter_list|(
name|s
parameter_list|,
name|seg
parameter_list|)
value|((s)->sy_symbol.n_type&= ~N_TYPE,(s)->sy_symbol.n_type|=SEGMENT_TO_SYMBOL_TYPE(seg))
end_define

begin_comment
comment|/* The symbol is external */
end_comment

begin_define
define|#
directive|define
name|S_SET_EXTERNAL
parameter_list|(
name|s
parameter_list|)
value|((s)->sy_symbol.n_type |= N_EXT)
end_define

begin_comment
comment|/* The symbol is not external */
end_comment

begin_define
define|#
directive|define
name|S_CLEAR_EXTERNAL
parameter_list|(
name|s
parameter_list|)
value|((s)->sy_symbol.n_type&= ~N_EXT)
end_define

begin_comment
comment|/* Set the name of the symbol */
end_comment

begin_define
define|#
directive|define
name|S_SET_NAME
parameter_list|(
name|s
parameter_list|,
name|v
parameter_list|)
value|((s)->sy_symbol.n_name = (v))
end_define

begin_comment
comment|/* Set the offset in the string table */
end_comment

begin_define
define|#
directive|define
name|S_SET_OFFSET
parameter_list|(
name|s
parameter_list|,
name|v
parameter_list|)
value|((s)->sy_name_offset = (v))
end_define

begin_comment
comment|/* Set the n_other expression value */
end_comment

begin_define
define|#
directive|define
name|S_SET_OTHER
parameter_list|(
name|s
parameter_list|,
name|v
parameter_list|)
value|((s)->sy_symbol.n_other = (v))
end_define

begin_comment
comment|/* Set the n_desc expression value */
end_comment

begin_define
define|#
directive|define
name|S_SET_DESC
parameter_list|(
name|s
parameter_list|,
name|v
parameter_list|)
value|((s)->sy_symbol.n_desc = (v))
end_define

begin_comment
comment|/* Set the n_type expression value */
end_comment

begin_define
define|#
directive|define
name|S_SET_TYPE
parameter_list|(
name|s
parameter_list|,
name|v
parameter_list|)
value|((s)->sy_symbol.n_type = (v))
end_define

begin_comment
comment|/* File header macro and type definition */
end_comment

begin_define
define|#
directive|define
name|H_GET_TEXT_SIZE
parameter_list|(
name|h
parameter_list|)
value|((h)->header.a_text)
end_define

begin_define
define|#
directive|define
name|H_GET_DATA_SIZE
parameter_list|(
name|h
parameter_list|)
value|((h)->header.a_data)
end_define

begin_define
define|#
directive|define
name|H_GET_BSS_SIZE
parameter_list|(
name|h
parameter_list|)
value|((h)->header.a_bss)
end_define

begin_define
define|#
directive|define
name|H_SET_TEXT_SIZE
parameter_list|(
name|h
parameter_list|,
name|v
parameter_list|)
value|((h)->header.a_text = md_section_align(SEG_TEXT, (v)))
end_define

begin_define
define|#
directive|define
name|H_SET_DATA_SIZE
parameter_list|(
name|h
parameter_list|,
name|v
parameter_list|)
value|((h)->header.a_data = md_section_align(SEG_DATA, (v)))
end_define

begin_define
define|#
directive|define
name|H_SET_BSS_SIZE
parameter_list|(
name|h
parameter_list|,
name|v
parameter_list|)
value|((h)->header.a_bss = md_section_align(SEG_BSS, (v)))
end_define

begin_define
define|#
directive|define
name|H_SET_STRING_SIZE
parameter_list|(
name|h
parameter_list|,
name|v
parameter_list|)
value|((h)->string_table_size = (v))
end_define

begin_define
define|#
directive|define
name|H_SET_SYMBOL_TABLE_SIZE
parameter_list|(
name|h
parameter_list|,
name|v
parameter_list|)
value|((h)->header.a_syms = (v) * \ 					 sizeof (struct nlist))
end_define

begin_comment
comment|/* line numbering stuff.  */
end_comment

begin_define
define|#
directive|define
name|OBJ_EMIT_LINENO
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|,
name|c
parameter_list|)
value|{;}
end_define

begin_define
define|#
directive|define
name|obj_symbol_new_hook
parameter_list|(
name|s
parameter_list|)
value|{;}
end_define

begin_comment
comment|/* Force structure tags into scope so that their use in prototypes    will never be their first occurrence.  */
end_comment

begin_struct_decl
struct_decl|struct
name|fix
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|frag
struct_decl|;
end_struct_decl

begin_comment
comment|/* obj-vms routines visible to the rest of gas.  */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|tc_aout_fix_to_chars
name|PARAMS
argument_list|(
operator|(
name|char
operator|*
operator|,
expr|struct
name|fix
operator|*
operator|,
name|relax_addressT
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|vms_resolve_symbol_redef
name|PARAMS
argument_list|(
operator|(
name|symbolS
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|RESOLVE_SYMBOL_REDEFINITION
parameter_list|(
name|X
parameter_list|)
value|vms_resolve_symbol_redef(X)
end_define

begin_comment
comment|/* Compiler-generated label "__vax_g_doubles" is used to augment .stabs.  */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|vms_check_for_special_label
name|PARAMS
argument_list|(
operator|(
name|symbolS
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|obj_frob_label
parameter_list|(
name|X
parameter_list|)
value|vms_check_for_special_label(X)
end_define

begin_decl_stmt
specifier|extern
name|void
name|vms_check_for_main
name|PARAMS
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|vms_write_object_file
name|PARAMS
argument_list|(
operator|(
name|unsigned
operator|,
name|unsigned
operator|,
name|unsigned
operator|,
expr|struct
name|frag
operator|*
operator|,
expr|struct
name|frag
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* VMS executables are nothing like a.out, but the VMS port of gcc uses    a.out format stabs which obj-vms.c then translates.  */
end_comment

begin_define
define|#
directive|define
name|AOUT_STABS
end_define

begin_escape
end_escape

begin_ifdef
ifdef|#
directive|ifdef
name|WANT_VMS_OBJ_DEFS
end_ifdef

begin_comment
comment|/* The rest of this file contains definitions for constants used within    the actual VMS object file.  We do not use a $ in the symbols (as per    usual VMS convention) since System V gags on it.  */
end_comment

begin_define
define|#
directive|define
name|OBJ_S_C_HDR
value|0
end_define

begin_define
define|#
directive|define
name|OBJ_S_C_HDR_MHD
value|0
end_define

begin_define
define|#
directive|define
name|OBJ_S_C_HDR_LNM
value|1
end_define

begin_define
define|#
directive|define
name|OBJ_S_C_HDR_SRC
value|2
end_define

begin_define
define|#
directive|define
name|OBJ_S_C_HDR_TTL
value|3
end_define

begin_define
define|#
directive|define
name|OBJ_S_C_HDR_CPR
value|4
end_define

begin_define
define|#
directive|define
name|OBJ_S_C_HDR_MTC
value|5
end_define

begin_define
define|#
directive|define
name|OBJ_S_C_HDR_GTX
value|6
end_define

begin_define
define|#
directive|define
name|OBJ_S_C_GSD
value|1
end_define

begin_define
define|#
directive|define
name|OBJ_S_C_GSD_PSC
value|0
end_define

begin_define
define|#
directive|define
name|OBJ_S_C_GSD_SYM
value|1
end_define

begin_define
define|#
directive|define
name|OBJ_S_C_GSD_EPM
value|2
end_define

begin_define
define|#
directive|define
name|OBJ_S_C_GSD_PRO
value|3
end_define

begin_define
define|#
directive|define
name|OBJ_S_C_GSD_SYMW
value|4
end_define

begin_define
define|#
directive|define
name|OBJ_S_C_GSD_EPMW
value|5
end_define

begin_define
define|#
directive|define
name|OBJ_S_C_GSD_PROW
value|6
end_define

begin_define
define|#
directive|define
name|OBJ_S_C_GSD_IDC
value|7
end_define

begin_define
define|#
directive|define
name|OBJ_S_C_GSD_ENV
value|8
end_define

begin_define
define|#
directive|define
name|OBJ_S_C_GSD_LSY
value|9
end_define

begin_define
define|#
directive|define
name|OBJ_S_C_GSD_LEPM
value|10
end_define

begin_define
define|#
directive|define
name|OBJ_S_C_GSD_LPRO
value|11
end_define

begin_define
define|#
directive|define
name|OBJ_S_C_GSD_SPSC
value|12
end_define

begin_define
define|#
directive|define
name|OBJ_S_C_TIR
value|2
end_define

begin_define
define|#
directive|define
name|OBJ_S_C_EOM
value|3
end_define

begin_define
define|#
directive|define
name|OBJ_S_C_DBG
value|4
end_define

begin_define
define|#
directive|define
name|OBJ_S_C_TBT
value|5
end_define

begin_define
define|#
directive|define
name|OBJ_S_C_LNK
value|6
end_define

begin_define
define|#
directive|define
name|OBJ_S_C_EOMW
value|7
end_define

begin_define
define|#
directive|define
name|OBJ_S_C_MAXRECTYP
value|7
end_define

begin_define
define|#
directive|define
name|OBJ_S_K_SUBTYP
value|1
end_define

begin_define
define|#
directive|define
name|OBJ_S_C_SUBTYP
value|1
end_define

begin_define
define|#
directive|define
name|OBJ_S_C_MAXRECSIZ
value|2048
end_define

begin_define
define|#
directive|define
name|OBJ_S_C_STRLVL
value|0
end_define

begin_define
define|#
directive|define
name|OBJ_S_C_SYMSIZ
value|31
end_define

begin_define
define|#
directive|define
name|OBJ_S_C_STOREPLIM
value|-1
end_define

begin_define
define|#
directive|define
name|OBJ_S_C_PSCALILIM
value|9
end_define

begin_escape
end_escape

begin_define
define|#
directive|define
name|MHD_S_C_MHD
value|0
end_define

begin_define
define|#
directive|define
name|MHD_S_C_LNM
value|1
end_define

begin_define
define|#
directive|define
name|MHD_S_C_SRC
value|2
end_define

begin_define
define|#
directive|define
name|MHD_S_C_TTL
value|3
end_define

begin_define
define|#
directive|define
name|MHD_S_C_CPR
value|4
end_define

begin_define
define|#
directive|define
name|MHD_S_C_MTC
value|5
end_define

begin_define
define|#
directive|define
name|MHD_S_C_GTX
value|6
end_define

begin_define
define|#
directive|define
name|MHD_S_C_MAXHDRTYP
value|6
end_define

begin_escape
end_escape

begin_define
define|#
directive|define
name|GSD_S_K_ENTRIES
value|1
end_define

begin_define
define|#
directive|define
name|GSD_S_C_ENTRIES
value|1
end_define

begin_define
define|#
directive|define
name|GSD_S_C_PSC
value|0
end_define

begin_define
define|#
directive|define
name|GSD_S_C_SYM
value|1
end_define

begin_define
define|#
directive|define
name|GSD_S_C_EPM
value|2
end_define

begin_define
define|#
directive|define
name|GSD_S_C_PRO
value|3
end_define

begin_define
define|#
directive|define
name|GSD_S_C_SYMW
value|4
end_define

begin_define
define|#
directive|define
name|GSD_S_C_EPMW
value|5
end_define

begin_define
define|#
directive|define
name|GSD_S_C_PROW
value|6
end_define

begin_define
define|#
directive|define
name|GSD_S_C_IDC
value|7
end_define

begin_define
define|#
directive|define
name|GSD_S_C_ENV
value|8
end_define

begin_define
define|#
directive|define
name|GSD_S_C_LSY
value|9
end_define

begin_define
define|#
directive|define
name|GSD_S_C_LEPM
value|10
end_define

begin_define
define|#
directive|define
name|GSD_S_C_LPRO
value|11
end_define

begin_define
define|#
directive|define
name|GSD_S_C_SPSC
value|12
end_define

begin_define
define|#
directive|define
name|GSD_S_C_SYMV
value|13
end_define

begin_define
define|#
directive|define
name|GSD_S_C_EPMV
value|14
end_define

begin_define
define|#
directive|define
name|GSD_S_C_PROV
value|15
end_define

begin_define
define|#
directive|define
name|GSD_S_C_MAXRECTYP
value|15
end_define

begin_escape
end_escape

begin_define
define|#
directive|define
name|GSY_S_M_WEAK
value|1
end_define

begin_define
define|#
directive|define
name|GSY_S_M_DEF
value|2
end_define

begin_define
define|#
directive|define
name|GSY_S_M_UNI
value|4
end_define

begin_define
define|#
directive|define
name|GSY_S_M_REL
value|8
end_define

begin_define
define|#
directive|define
name|LSY_S_M_DEF
value|2
end_define

begin_define
define|#
directive|define
name|LSY_S_M_REL
value|8
end_define

begin_define
define|#
directive|define
name|ENV_S_M_DEF
value|1
end_define

begin_define
define|#
directive|define
name|ENV_S_M_NESTED
value|2
end_define

begin_escape
end_escape

begin_define
define|#
directive|define
name|GPS_S_M_PIC
value|1
end_define

begin_define
define|#
directive|define
name|GPS_S_M_LIB
value|2
end_define

begin_define
define|#
directive|define
name|GPS_S_M_OVR
value|4
end_define

begin_define
define|#
directive|define
name|GPS_S_M_REL
value|8
end_define

begin_define
define|#
directive|define
name|GPS_S_M_GBL
value|16
end_define

begin_define
define|#
directive|define
name|GPS_S_M_SHR
value|32
end_define

begin_define
define|#
directive|define
name|GPS_S_M_EXE
value|64
end_define

begin_define
define|#
directive|define
name|GPS_S_M_RD
value|128
end_define

begin_define
define|#
directive|define
name|GPS_S_M_WRT
value|256
end_define

begin_define
define|#
directive|define
name|GPS_S_M_VEC
value|512
end_define

begin_define
define|#
directive|define
name|GPS_S_K_NAME
value|9
end_define

begin_define
define|#
directive|define
name|GPS_S_C_NAME
value|9
end_define

begin_escape
end_escape

begin_define
define|#
directive|define
name|TIR_S_C_STA_GBL
value|0
end_define

begin_define
define|#
directive|define
name|TIR_S_C_STA_SB
value|1
end_define

begin_define
define|#
directive|define
name|TIR_S_C_STA_SW
value|2
end_define

begin_define
define|#
directive|define
name|TIR_S_C_STA_LW
value|3
end_define

begin_define
define|#
directive|define
name|TIR_S_C_STA_PB
value|4
end_define

begin_define
define|#
directive|define
name|TIR_S_C_STA_PW
value|5
end_define

begin_define
define|#
directive|define
name|TIR_S_C_STA_PL
value|6
end_define

begin_define
define|#
directive|define
name|TIR_S_C_STA_UB
value|7
end_define

begin_define
define|#
directive|define
name|TIR_S_C_STA_UW
value|8
end_define

begin_define
define|#
directive|define
name|TIR_S_C_STA_BFI
value|9
end_define

begin_define
define|#
directive|define
name|TIR_S_C_STA_WFI
value|10
end_define

begin_define
define|#
directive|define
name|TIR_S_C_STA_LFI
value|11
end_define

begin_define
define|#
directive|define
name|TIR_S_C_STA_EPM
value|12
end_define

begin_define
define|#
directive|define
name|TIR_S_C_STA_CKARG
value|13
end_define

begin_define
define|#
directive|define
name|TIR_S_C_STA_WPB
value|14
end_define

begin_define
define|#
directive|define
name|TIR_S_C_STA_WPW
value|15
end_define

begin_define
define|#
directive|define
name|TIR_S_C_STA_WPL
value|16
end_define

begin_define
define|#
directive|define
name|TIR_S_C_STA_LSY
value|17
end_define

begin_define
define|#
directive|define
name|TIR_S_C_STA_LIT
value|18
end_define

begin_define
define|#
directive|define
name|TIR_S_C_STA_LEPM
value|19
end_define

begin_define
define|#
directive|define
name|TIR_S_C_MAXSTACOD
value|19
end_define

begin_define
define|#
directive|define
name|TIR_S_C_MINSTOCOD
value|20
end_define

begin_define
define|#
directive|define
name|TIR_S_C_STO_SB
value|20
end_define

begin_define
define|#
directive|define
name|TIR_S_C_STO_SW
value|21
end_define

begin_define
define|#
directive|define
name|TIR_S_C_STO_L
value|22
end_define

begin_define
define|#
directive|define
name|TIR_S_C_STO_BD
value|23
end_define

begin_define
define|#
directive|define
name|TIR_S_C_STO_WD
value|24
end_define

begin_define
define|#
directive|define
name|TIR_S_C_STO_LD
value|25
end_define

begin_define
define|#
directive|define
name|TIR_S_C_STO_LI
value|26
end_define

begin_define
define|#
directive|define
name|TIR_S_C_STO_PIDR
value|27
end_define

begin_define
define|#
directive|define
name|TIR_S_C_STO_PICR
value|28
end_define

begin_define
define|#
directive|define
name|TIR_S_C_STO_RSB
value|29
end_define

begin_define
define|#
directive|define
name|TIR_S_C_STO_RSW
value|30
end_define

begin_define
define|#
directive|define
name|TIR_S_C_STO_RL
value|31
end_define

begin_define
define|#
directive|define
name|TIR_S_C_STO_VPS
value|32
end_define

begin_define
define|#
directive|define
name|TIR_S_C_STO_USB
value|33
end_define

begin_define
define|#
directive|define
name|TIR_S_C_STO_USW
value|34
end_define

begin_define
define|#
directive|define
name|TIR_S_C_STO_RUB
value|35
end_define

begin_define
define|#
directive|define
name|TIR_S_C_STO_RUW
value|36
end_define

begin_define
define|#
directive|define
name|TIR_S_C_STO_B
value|37
end_define

begin_define
define|#
directive|define
name|TIR_S_C_STO_W
value|38
end_define

begin_define
define|#
directive|define
name|TIR_S_C_STO_RB
value|39
end_define

begin_define
define|#
directive|define
name|TIR_S_C_STO_RW
value|40
end_define

begin_define
define|#
directive|define
name|TIR_S_C_STO_RIVB
value|41
end_define

begin_define
define|#
directive|define
name|TIR_S_C_STO_PIRR
value|42
end_define

begin_define
define|#
directive|define
name|TIR_S_C_MAXSTOCOD
value|42
end_define

begin_define
define|#
directive|define
name|TIR_S_C_MINOPRCOD
value|50
end_define

begin_define
define|#
directive|define
name|TIR_S_C_OPR_NOP
value|50
end_define

begin_define
define|#
directive|define
name|TIR_S_C_OPR_ADD
value|51
end_define

begin_define
define|#
directive|define
name|TIR_S_C_OPR_SUB
value|52
end_define

begin_define
define|#
directive|define
name|TIR_S_C_OPR_MUL
value|53
end_define

begin_define
define|#
directive|define
name|TIR_S_C_OPR_DIV
value|54
end_define

begin_define
define|#
directive|define
name|TIR_S_C_OPR_AND
value|55
end_define

begin_define
define|#
directive|define
name|TIR_S_C_OPR_IOR
value|56
end_define

begin_define
define|#
directive|define
name|TIR_S_C_OPR_EOR
value|57
end_define

begin_define
define|#
directive|define
name|TIR_S_C_OPR_NEG
value|58
end_define

begin_define
define|#
directive|define
name|TIR_S_C_OPR_COM
value|59
end_define

begin_define
define|#
directive|define
name|TIR_S_C_OPR_INSV
value|60
end_define

begin_define
define|#
directive|define
name|TIR_S_C_OPR_ASH
value|61
end_define

begin_define
define|#
directive|define
name|TIR_S_C_OPR_USH
value|62
end_define

begin_define
define|#
directive|define
name|TIR_S_C_OPR_ROT
value|63
end_define

begin_define
define|#
directive|define
name|TIR_S_C_OPR_SEL
value|64
end_define

begin_define
define|#
directive|define
name|TIR_S_C_OPR_REDEF
value|65
end_define

begin_define
define|#
directive|define
name|TIR_S_C_OPR_DFLIT
value|66
end_define

begin_define
define|#
directive|define
name|TIR_S_C_MAXOPRCOD
value|66
end_define

begin_define
define|#
directive|define
name|TIR_S_C_MINCTLCOD
value|80
end_define

begin_define
define|#
directive|define
name|TIR_S_C_CTL_SETRB
value|80
end_define

begin_define
define|#
directive|define
name|TIR_S_C_CTL_AUGRB
value|81
end_define

begin_define
define|#
directive|define
name|TIR_S_C_CTL_DFLOC
value|82
end_define

begin_define
define|#
directive|define
name|TIR_S_C_CTL_STLOC
value|83
end_define

begin_define
define|#
directive|define
name|TIR_S_C_CTL_STKDL
value|84
end_define

begin_define
define|#
directive|define
name|TIR_S_C_MAXCTLCOD
value|84
end_define

begin_escape
end_escape

begin_comment
comment|/*  *	Debugger symbol definitions:  These are done by hand, as no  *					machine-readable version seems  *					to be available.  */
end_comment

begin_define
define|#
directive|define
name|DST_S_C_C
value|7
end_define

begin_comment
comment|/* Language == "C"	*/
end_comment

begin_define
define|#
directive|define
name|DST_S_C_CXX
value|15
end_define

begin_comment
comment|/* Language == "C++"	*/
end_comment

begin_define
define|#
directive|define
name|DST_S_C_VERSION
value|153
end_define

begin_define
define|#
directive|define
name|DST_S_C_SOURCE
value|155
end_define

begin_comment
comment|/* Source file		*/
end_comment

begin_define
define|#
directive|define
name|DST_S_C_PROLOG
value|162
end_define

begin_define
define|#
directive|define
name|DST_S_C_BLKBEG
value|176
end_define

begin_comment
comment|/* Beginning of block	*/
end_comment

begin_define
define|#
directive|define
name|DST_S_C_BLKEND
value|177
end_define

begin_comment
comment|/* End of block	*/
end_comment

begin_define
define|#
directive|define
name|DST_S_C_ENTRY
value|181
end_define

begin_define
define|#
directive|define
name|DST_S_C_PSECT
value|184
end_define

begin_define
define|#
directive|define
name|DST_S_C_LINE_NUM
value|185
end_define

begin_comment
comment|/* Line Number		*/
end_comment

begin_define
define|#
directive|define
name|DST_S_C_LBLORLIT
value|186
end_define

begin_define
define|#
directive|define
name|DST_S_C_LABEL
value|187
end_define

begin_define
define|#
directive|define
name|DST_S_C_MODBEG
value|188
end_define

begin_comment
comment|/* Beginning of module	*/
end_comment

begin_define
define|#
directive|define
name|DST_S_C_MODEND
value|189
end_define

begin_comment
comment|/* End of module	*/
end_comment

begin_define
define|#
directive|define
name|DST_S_C_RTNBEG
value|190
end_define

begin_comment
comment|/* Beginning of routine	*/
end_comment

begin_define
define|#
directive|define
name|DST_S_C_RTNEND
value|191
end_define

begin_comment
comment|/* End of routine	*/
end_comment

begin_define
define|#
directive|define
name|DST_S_C_DELTA_PC_W
value|1
end_define

begin_comment
comment|/* Incr PC	*/
end_comment

begin_define
define|#
directive|define
name|DST_S_C_INCR_LINUM
value|2
end_define

begin_comment
comment|/* Incr Line #	*/
end_comment

begin_define
define|#
directive|define
name|DST_S_C_INCR_LINUM_W
value|3
end_define

begin_comment
comment|/* Incr Line #	*/
end_comment

begin_define
define|#
directive|define
name|DST_S_C_SET_LINUM_INCR
value|4
end_define

begin_define
define|#
directive|define
name|DST_S_C_SET_LINUM_INCR_W
value|5
end_define

begin_define
define|#
directive|define
name|DST_S_C_RESET_LINUM_INCR
value|6
end_define

begin_define
define|#
directive|define
name|DST_S_C_BEG_STMT_MODE
value|7
end_define

begin_define
define|#
directive|define
name|DST_S_C_END_STMT_MODE
value|8
end_define

begin_define
define|#
directive|define
name|DST_S_C_SET_LINE_NUM
value|9
end_define

begin_comment
comment|/* Set Line #	*/
end_comment

begin_define
define|#
directive|define
name|DST_S_C_SET_PC
value|10
end_define

begin_define
define|#
directive|define
name|DST_S_C_SET_PC_W
value|11
end_define

begin_define
define|#
directive|define
name|DST_S_C_SET_PC_L
value|12
end_define

begin_define
define|#
directive|define
name|DST_S_C_SET_STMTNUM
value|13
end_define

begin_define
define|#
directive|define
name|DST_S_C_TERM
value|14
end_define

begin_comment
comment|/* End of lines	*/
end_comment

begin_define
define|#
directive|define
name|DST_S_C_TERM_W
value|15
end_define

begin_comment
comment|/* End of lines	*/
end_comment

begin_define
define|#
directive|define
name|DST_S_C_SET_ABS_PC
value|16
end_define

begin_comment
comment|/* Set PC	*/
end_comment

begin_define
define|#
directive|define
name|DST_S_C_DELTA_PC_L
value|17
end_define

begin_comment
comment|/* Incr PC	*/
end_comment

begin_define
define|#
directive|define
name|DST_S_C_INCR_LINUM_L
value|18
end_define

begin_comment
comment|/* Incr Line #	*/
end_comment

begin_define
define|#
directive|define
name|DST_S_C_SET_LINUM_B
value|19
end_define

begin_comment
comment|/* Set Line #	*/
end_comment

begin_define
define|#
directive|define
name|DST_S_C_SET_LINUM_L
value|20
end_define

begin_comment
comment|/* Set Line #	*/
end_comment

begin_define
define|#
directive|define
name|DST_S_C_TERM_L
value|21
end_define

begin_comment
comment|/* End of lines	*/
end_comment

begin_comment
comment|/* these are used with DST_S_C_SOURCE */
end_comment

begin_define
define|#
directive|define
name|DST_S_C_SRC_DECLFILE
value|1
end_define

begin_comment
comment|/* Declare source file */
end_comment

begin_define
define|#
directive|define
name|DST_S_C_SRC_SETFILE
value|2
end_define

begin_comment
comment|/* Set source file */
end_comment

begin_define
define|#
directive|define
name|DST_S_C_SRC_SETREC_L
value|3
end_define

begin_comment
comment|/* Set record, longword value */
end_comment

begin_define
define|#
directive|define
name|DST_S_C_SRC_SETREC_W
value|4
end_define

begin_comment
comment|/* Set record, word value */
end_comment

begin_define
define|#
directive|define
name|DST_S_C_SRC_DEFLINES_W
value|10
end_define

begin_comment
comment|/* # of line, word counter */
end_comment

begin_define
define|#
directive|define
name|DST_S_C_SRC_DEFLINES_B
value|11
end_define

begin_comment
comment|/* # of line, byte counter */
end_comment

begin_define
define|#
directive|define
name|DST_S_C_SRC_FORMFEED
value|16
end_define

begin_comment
comment|/* ^L counts as a record */
end_comment

begin_comment
comment|/* the following are the codes for the various data types.  Anything not on  * the list is included under 'advanced_type'  */
end_comment

begin_define
define|#
directive|define
name|DBG_S_C_UCHAR
value|0x02
end_define

begin_define
define|#
directive|define
name|DBG_S_C_USINT
value|0x03
end_define

begin_define
define|#
directive|define
name|DBG_S_C_ULINT
value|0x04
end_define

begin_define
define|#
directive|define
name|DBG_S_C_UQUAD
value|0x05
end_define

begin_define
define|#
directive|define
name|DBG_S_C_SCHAR
value|0x06
end_define

begin_define
define|#
directive|define
name|DBG_S_C_SSINT
value|0x07
end_define

begin_define
define|#
directive|define
name|DBG_S_C_SLINT
value|0x08
end_define

begin_define
define|#
directive|define
name|DBG_S_C_SQUAD
value|0x09
end_define

begin_define
define|#
directive|define
name|DBG_S_C_REAL4
value|0x0a
end_define

begin_define
define|#
directive|define
name|DBG_S_C_REAL8
value|0x0b
end_define

begin_comment
comment|/* D_float double */
end_comment

begin_define
define|#
directive|define
name|DBG_S_C_COMPLX4
value|0x0c
end_define

begin_comment
comment|/* 2xF_float complex float */
end_comment

begin_define
define|#
directive|define
name|DBG_S_C_COMPLX8
value|0x0d
end_define

begin_comment
comment|/* 2xD_float complex double */
end_comment

begin_define
define|#
directive|define
name|DBG_S_C_REAL8_G
value|0x1b
end_define

begin_comment
comment|/* G_float double */
end_comment

begin_define
define|#
directive|define
name|DBG_S_C_COMPLX8_G
value|0x1d
end_define

begin_comment
comment|/* 2xG_float complex double */
end_comment

begin_define
define|#
directive|define
name|DBG_S_C_FUNCTION_ADDR
value|0x17
end_define

begin_define
define|#
directive|define
name|DBG_S_C_ADVANCED_TYPE
value|0xa3
end_define

begin_comment
comment|/*  Some of these are just for future reference.  [pr]  */
end_comment

begin_define
define|#
directive|define
name|DBG_S_C_UBITA
value|0x01
end_define

begin_comment
comment|/* unsigned, aligned bit field */
end_comment

begin_define
define|#
directive|define
name|DBG_S_C_UBITU
value|0x22
end_define

begin_comment
comment|/* unsigned, unaligned bit field */
end_comment

begin_define
define|#
directive|define
name|DBG_S_C_SBITA
value|0x29
end_define

begin_comment
comment|/* signed, aligned bit field */
end_comment

begin_define
define|#
directive|define
name|DBG_S_C_SBITU
value|0x2a
end_define

begin_comment
comment|/* signed, unaligned bit field */
end_comment

begin_define
define|#
directive|define
name|DBG_S_C_CSTRING
value|0x2e
end_define

begin_comment
comment|/* asciz ('\0' terminated) string */
end_comment

begin_define
define|#
directive|define
name|DBG_S_C_WCHAR
value|0x38
end_define

begin_comment
comment|/* wchar_t */
end_comment

begin_comment
comment|/*  These are descriptor class codes.  */
end_comment

begin_define
define|#
directive|define
name|DSC_K_CLASS_S
value|0x01
end_define

begin_comment
comment|/* static (fixed length) */
end_comment

begin_define
define|#
directive|define
name|DSC_K_CLASS_D
value|0x02
end_define

begin_comment
comment|/* dynamic string (not via malloc!) */
end_comment

begin_define
define|#
directive|define
name|DSC_K_CLASS_A
value|0x04
end_define

begin_comment
comment|/* array */
end_comment

begin_define
define|#
directive|define
name|DSC_K_CLASS_UBS
value|0x0d
end_define

begin_comment
comment|/* unaligned bit string */
end_comment

begin_comment
comment|/*  These are the codes that are used to generate the definitions of struct  *  union and enum records  */
end_comment

begin_define
define|#
directive|define
name|DBG_S_C_ENUM_ITEM
value|0xa4
end_define

begin_define
define|#
directive|define
name|DBG_S_C_ENUM_START
value|0xa5
end_define

begin_define
define|#
directive|define
name|DBG_S_C_ENUM_END
value|0xa6
end_define

begin_define
define|#
directive|define
name|DBG_S_C_STRUCT_ITEM
value|DST_K_VFLAGS_BITOFFS
end_define

begin_comment
comment|/* 0xff */
end_comment

begin_define
define|#
directive|define
name|DBG_S_C_STRUCT_START
value|0xab
end_define

begin_define
define|#
directive|define
name|DBG_S_C_STRUCT_END
value|0xac
end_define

begin_define
define|#
directive|define
name|DST_K_TYPSPEC
value|0xaf
end_define

begin_comment
comment|/* type specification */
end_comment

begin_comment
comment|/* These codes are used in the generation of the symbol definition records  */
end_comment

begin_define
define|#
directive|define
name|DST_K_VFLAGS_NOVAL
value|0x80
end_define

begin_comment
comment|/* struct definition only */
end_comment

begin_define
define|#
directive|define
name|DST_K_VFLAGS_DSC
value|0xfa
end_define

begin_comment
comment|/* descriptor used */
end_comment

begin_define
define|#
directive|define
name|DST_K_VFLAGS_TVS
value|0xfb
end_define

begin_comment
comment|/* trailing value specified */
end_comment

begin_define
define|#
directive|define
name|DST_K_VS_FOLLOWS
value|0xfd
end_define

begin_comment
comment|/* value spec follows */
end_comment

begin_define
define|#
directive|define
name|DST_K_VFLAGS_BITOFFS
value|0xff
end_define

begin_comment
comment|/* value contains bit offset */
end_comment

begin_define
define|#
directive|define
name|DST_K_VALKIND_LITERAL
value|0
end_define

begin_define
define|#
directive|define
name|DST_K_VALKIND_ADDR
value|1
end_define

begin_define
define|#
directive|define
name|DST_K_VALKIND_DESC
value|2
end_define

begin_define
define|#
directive|define
name|DST_K_VALKIND_REG
value|3
end_define

begin_define
define|#
directive|define
name|DST_K_REG_VAX_AP
value|0x0c
end_define

begin_comment
comment|/* R12 */
end_comment

begin_define
define|#
directive|define
name|DST_K_REG_VAX_FP
value|0x0d
end_define

begin_comment
comment|/* R13 */
end_comment

begin_define
define|#
directive|define
name|DST_K_REG_VAX_SP
value|0x0e
end_define

begin_comment
comment|/* R14 */
end_comment

begin_define
define|#
directive|define
name|DST_V_VALKIND
value|0
end_define

begin_comment
comment|/* offset of valkind field */
end_comment

begin_define
define|#
directive|define
name|DST_V_INDIRECT
value|2
end_define

begin_comment
comment|/* offset to indirect bit */
end_comment

begin_define
define|#
directive|define
name|DST_V_DISP
value|3
end_define

begin_comment
comment|/* offset to displacement bit */
end_comment

begin_define
define|#
directive|define
name|DST_V_REGNUM
value|4
end_define

begin_comment
comment|/* offset to register number */
end_comment

begin_define
define|#
directive|define
name|DST_M_INDIRECT
value|(1<<DST_V_INDIRECT)
end_define

begin_define
define|#
directive|define
name|DST_M_DISP
value|(1<<DST_V_DISP)
end_define

begin_define
define|#
directive|define
name|DBG_C_FUNCTION_PARAM
comment|/* 0xc9 */
define|\
value|(DST_K_VALKIND_ADDR|DST_M_DISP|(DST_K_REG_VAX_AP<<DST_V_REGNUM))
end_define

begin_define
define|#
directive|define
name|DBG_C_LOCAL_SYM
comment|/* 0xd9 */
define|\
value|(DST_K_VALKIND_ADDR|DST_M_DISP|(DST_K_REG_VAX_FP<<DST_V_REGNUM))
end_define

begin_comment
comment|/* Kinds of value specifications  */
end_comment

begin_define
define|#
directive|define
name|DST_K_VS_ALLOC_SPLIT
value|3
end_define

begin_comment
comment|/* split lifetime */
end_comment

begin_comment
comment|/* Kinds of type specifications  */
end_comment

begin_define
define|#
directive|define
name|DST_K_TS_ATOM
value|0x01
end_define

begin_comment
comment|/* atomic type specification */
end_comment

begin_define
define|#
directive|define
name|DST_K_TS_DSC
value|0x02
end_define

begin_comment
comment|/* descriptor type spec */
end_comment

begin_define
define|#
directive|define
name|DST_K_TS_IND
value|0x03
end_define

begin_comment
comment|/* indirect type specification */
end_comment

begin_define
define|#
directive|define
name|DST_K_TS_TPTR
value|0x04
end_define

begin_comment
comment|/* typed pointer type spec */
end_comment

begin_define
define|#
directive|define
name|DST_K_TS_PTR
value|0x05
end_define

begin_comment
comment|/* pointer type spec */
end_comment

begin_define
define|#
directive|define
name|DST_K_TS_ARRAY
value|0x07
end_define

begin_comment
comment|/* array type spec */
end_comment

begin_define
define|#
directive|define
name|DST_K_TS_NOV_LENG
value|0x0e
end_define

begin_comment
comment|/* novel length type spec */
end_comment

begin_comment
comment|/*  These are the codes that are used in the suffix records to determine the  *  actual data type  */
end_comment

begin_define
define|#
directive|define
name|DBG_S_C_BASIC
value|DST_K_TS_ATOM
end_define

begin_define
define|#
directive|define
name|DBG_S_C_BASIC_ARRAY
value|DST_K_TS_DSC
end_define

begin_define
define|#
directive|define
name|DBG_S_C_STRUCT
value|DST_K_TS_IND
end_define

begin_define
define|#
directive|define
name|DBG_S_C_POINTER
value|DST_K_TS_TPTR
end_define

begin_define
define|#
directive|define
name|DBG_S_C_VOID
value|DST_K_TS_PTR
end_define

begin_define
define|#
directive|define
name|DBG_S_C_COMPLEX_ARRAY
value|DST_K_TS_ARRAY
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* WANT_VMS_OBJ_DEFS */
end_comment

end_unit

