begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* obj-aout.h, a.out object file format for gas, the assembler.    Copyright 1989, 1990, 1991, 1992, 1993, 1994, 1995, 1996, 1998, 2000    Free Software Foundation, Inc.     This file is part of GAS, the GNU Assembler.     GAS is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as    published by the Free Software Foundation; either version 2,    or (at your option) any later version.     GAS is distributed in the hope that it will be useful, but    WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See    the GNU General Public License for more details.     You should have received a copy of the GNU General Public License    along with GAS; see the file COPYING.  If not, write to the Free    Software Foundation, 59 Temple Place - Suite 330, Boston, MA    02111-1307, USA.  */
end_comment

begin_comment
comment|/* Tag to validate a.out object file format processing */
end_comment

begin_define
define|#
directive|define
name|OBJ_AOUT
value|1
end_define

begin_include
include|#
directive|include
file|"targ-cpu.h"
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|BFD_ASSEMBLER
end_ifdef

begin_include
include|#
directive|include
file|"bfd/libaout.h"
end_include

begin_define
define|#
directive|define
name|OUTPUT_FLAVOR
value|bfd_target_aout_flavour
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* ! BFD_ASSEMBLER */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|VMS
end_ifndef

begin_include
include|#
directive|include
file|"aout_gnu.h"
end_include

begin_comment
comment|/* Needed to define struct nlist. Sigh.  */
end_comment

begin_else
else|#
directive|else
end_else

begin_include
include|#
directive|include
file|"a_out.h"
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|AOUT_MACHTYPE
end_ifndef

begin_define
define|#
directive|define
name|AOUT_MACHTYPE
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* AOUT_MACHTYPE */
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

begin_ifndef
ifndef|#
directive|ifndef
name|DEFAULT_MAGIC_NUMBER_FOR_OBJECT_FILE
end_ifndef

begin_define
define|#
directive|define
name|DEFAULT_MAGIC_NUMBER_FOR_OBJECT_FILE
value|(OMAGIC)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* DEFAULT_MAGIC_NUMBER_FOR_OBJECT_FILE */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! BFD_ASSEMBLER */
end_comment

begin_decl_stmt
specifier|extern
specifier|const
name|pseudo_typeS
name|aout_pseudo_table
index|[]
decl_stmt|;
end_decl_stmt

begin_ifndef
ifndef|#
directive|ifndef
name|obj_pop_insert
end_ifndef

begin_define
define|#
directive|define
name|obj_pop_insert
parameter_list|()
value|pop_insert (aout_pseudo_table)
end_define

begin_endif
endif|#
directive|endif
end_endif

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

begin_ifdef
ifdef|#
directive|ifdef
name|BFD_ASSEMBLER
end_ifdef

begin_define
define|#
directive|define
name|S_SET_OTHER
parameter_list|(
name|S
parameter_list|,
name|V
parameter_list|)
define|\
value|(aout_symbol (symbol_get_bfdsym (S))->other = (V))
end_define

begin_define
define|#
directive|define
name|S_SET_TYPE
parameter_list|(
name|S
parameter_list|,
name|T
parameter_list|)
define|\
value|(aout_symbol (symbol_get_bfdsym (S))->type = (T))
end_define

begin_define
define|#
directive|define
name|S_SET_DESC
parameter_list|(
name|S
parameter_list|,
name|D
parameter_list|)
define|\
value|(aout_symbol (symbol_get_bfdsym (S))->desc = (D))
end_define

begin_define
define|#
directive|define
name|S_GET_OTHER
parameter_list|(
name|S
parameter_list|)
define|\
value|(aout_symbol (symbol_get_bfdsym (S))->other)
end_define

begin_define
define|#
directive|define
name|S_GET_TYPE
parameter_list|(
name|S
parameter_list|)
define|\
value|(aout_symbol (symbol_get_bfdsym (S))->type)
end_define

begin_define
define|#
directive|define
name|S_GET_DESC
parameter_list|(
name|S
parameter_list|)
define|\
value|(aout_symbol (symbol_get_bfdsym (S))->desc)
end_define

begin_decl_stmt
name|asection
modifier|*
name|text_section
decl_stmt|,
modifier|*
name|data_section
decl_stmt|,
modifier|*
name|bss_section
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|obj_frob_symbol
parameter_list|(
name|S
parameter_list|,
name|PUNT
parameter_list|)
value|obj_aout_frob_symbol (S,&PUNT)
end_define

begin_define
define|#
directive|define
name|obj_frob_file
parameter_list|()
value|obj_aout_frob_file ()
end_define

begin_decl_stmt
specifier|extern
name|void
name|obj_aout_frob_symbol
name|PARAMS
argument_list|(
operator|(
name|symbolS
operator|*
operator|,
name|int
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|obj_aout_frob_file
name|PARAMS
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|obj_sec_sym_ok_for_reloc
parameter_list|(
name|SEC
parameter_list|)
value|(1)
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* We use the sy_obj field to record whether a symbol is weak.  */
end_comment

begin_define
define|#
directive|define
name|OBJ_SYMFIELD_TYPE
value|char
end_define

begin_comment
comment|/*  *  Macros to extract information from a symbol table entry.  *  This syntaxic indirection allows independence regarding a.out or coff.  *  The argument (s) of all these macros is a pointer to a symbol table entry.  */
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
define|\
value|(S_GET_TYPE (s) != N_UNDF || S_GET_DESC (s) != 0)
end_define

begin_define
define|#
directive|define
name|S_IS_COMMON
parameter_list|(
name|s
parameter_list|)
define|\
value|(S_GET_TYPE (s) == N_UNDF&& S_GET_VALUE (s) != 0)
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

begin_define
define|#
directive|define
name|S_IS_LOCAL
parameter_list|(
name|s
parameter_list|)
define|\
value|((S_GET_NAME (s) 					\&& !S_IS_DEBUG (s) 					\&& (strchr (S_GET_NAME (s), '\001') != NULL		\         || strchr (S_GET_NAME (s), '\002') != NULL	\         || (S_LOCAL_NAME(s)&& !flag_keep_locals)))	\    || (flag_strip_local_absolute			\&& ! S_IS_EXTERNAL(s)				\&& S_GET_SEGMENT (s) == absolute_section))
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
value|((s)->sy_symbol.n_un.n_name)
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
value|((s)->sy_symbol.n_un.n_strx)
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
comment|/* Whether the symbol is weak.  */
end_comment

begin_define
define|#
directive|define
name|S_GET_WEAK
parameter_list|(
name|s
parameter_list|)
value|((s)->sy_obj)
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
value|((s)->sy_symbol.n_un.n_name = (v))
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
value|((s)->sy_symbol.n_un.n_strx = (v))
end_define

begin_comment
comment|/* Set the n_type field */
end_comment

begin_define
define|#
directive|define
name|S_SET_TYPE
parameter_list|(
name|s
parameter_list|,
name|t
parameter_list|)
value|((s)->sy_symbol.n_type = (t))
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
comment|/* Mark the symbol as weak.  This causes n_type to be adjusted when    the symbol is written out.  */
end_comment

begin_define
define|#
directive|define
name|S_SET_WEAK
parameter_list|(
name|s
parameter_list|)
value|((s)->sy_obj = 1)
end_define

begin_comment
comment|/* File header macro and type definition */
end_comment

begin_define
define|#
directive|define
name|H_GET_FILE_SIZE
parameter_list|(
name|h
parameter_list|)
value|(H_GET_HEADER_SIZE(h) \ 				 + H_GET_TEXT_SIZE(h) \ 				 + H_GET_DATA_SIZE(h) \ 				 + H_GET_SYMBOL_TABLE_SIZE(h) \ 				 + H_GET_TEXT_RELOCATION_SIZE(h) \ 				 + H_GET_DATA_RELOCATION_SIZE(h) \ 				 + H_GET_STRING_SIZE(h))
end_define

begin_define
define|#
directive|define
name|H_GET_HEADER_SIZE
parameter_list|(
name|h
parameter_list|)
value|(EXEC_BYTES_SIZE)
end_define

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
name|H_GET_TEXT_RELOCATION_SIZE
parameter_list|(
name|h
parameter_list|)
value|((h)->header.a_trsize)
end_define

begin_define
define|#
directive|define
name|H_GET_DATA_RELOCATION_SIZE
parameter_list|(
name|h
parameter_list|)
value|((h)->header.a_drsize)
end_define

begin_define
define|#
directive|define
name|H_GET_SYMBOL_TABLE_SIZE
parameter_list|(
name|h
parameter_list|)
value|((h)->header.a_syms)
end_define

begin_define
define|#
directive|define
name|H_GET_ENTRY_POINT
parameter_list|(
name|h
parameter_list|)
value|((h)->header.a_entry)
end_define

begin_define
define|#
directive|define
name|H_GET_STRING_SIZE
parameter_list|(
name|h
parameter_list|)
value|((h)->string_table_size)
end_define

begin_define
define|#
directive|define
name|H_GET_LINENO_SIZE
parameter_list|(
name|h
parameter_list|)
value|(0)
end_define

begin_define
define|#
directive|define
name|H_GET_DYNAMIC
parameter_list|(
name|h
parameter_list|)
value|((h)->header.a_info>> 31)
end_define

begin_define
define|#
directive|define
name|H_GET_VERSION
parameter_list|(
name|h
parameter_list|)
value|(((h)->header.a_info>> 24)& 0x7f)
end_define

begin_define
define|#
directive|define
name|H_GET_MACHTYPE
parameter_list|(
name|h
parameter_list|)
value|(((h)->header.a_info>> 16)& 0xff)
end_define

begin_define
define|#
directive|define
name|H_GET_MAGIC_NUMBER
parameter_list|(
name|h
parameter_list|)
value|((h)->header.a_info& 0xffff)
end_define

begin_define
define|#
directive|define
name|H_SET_DYNAMIC
parameter_list|(
name|h
parameter_list|,
name|v
parameter_list|)
value|((h)->header.a_info = (((v)<< 31) \ 							       | (H_GET_VERSION(h)<< 24) \ 							       | (H_GET_MACHTYPE(h)<< 16) \ 							       | (H_GET_MAGIC_NUMBER(h))))
end_define

begin_define
define|#
directive|define
name|H_SET_VERSION
parameter_list|(
name|h
parameter_list|,
name|v
parameter_list|)
value|((h)->header.a_info = ((H_GET_DYNAMIC(h)<< 31) \ 							       | ((v)<< 24) \ 							       | (H_GET_MACHTYPE(h)<< 16) \ 							       | (H_GET_MAGIC_NUMBER(h))))
end_define

begin_define
define|#
directive|define
name|H_SET_MACHTYPE
parameter_list|(
name|h
parameter_list|,
name|v
parameter_list|)
value|((h)->header.a_info = ((H_GET_DYNAMIC(h)<< 31) \ 							       | (H_GET_VERSION(h)<< 24) \ 							       | ((v)<< 16) \ 							       | (H_GET_MAGIC_NUMBER(h))))
end_define

begin_define
define|#
directive|define
name|H_SET_MAGIC_NUMBER
parameter_list|(
name|h
parameter_list|,
name|v
parameter_list|)
value|((h)->header.a_info = ((H_GET_DYNAMIC(h)<< 31) \ 							       | (H_GET_VERSION(h)<< 24) \ 							       | (H_GET_MACHTYPE(h)<< 16) \ 							       | ((v))))
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
name|H_SET_RELOCATION_SIZE
parameter_list|(
name|h
parameter_list|,
name|t
parameter_list|,
name|d
parameter_list|)
value|(H_SET_TEXT_RELOCATION_SIZE((h),(t)),\ 					 H_SET_DATA_RELOCATION_SIZE((h),(d)))
end_define

begin_define
define|#
directive|define
name|H_SET_TEXT_RELOCATION_SIZE
parameter_list|(
name|h
parameter_list|,
name|v
parameter_list|)
value|((h)->header.a_trsize = (v))
end_define

begin_define
define|#
directive|define
name|H_SET_DATA_RELOCATION_SIZE
parameter_list|(
name|h
parameter_list|,
name|v
parameter_list|)
value|((h)->header.a_drsize = (v))
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
value|((h)->header.a_syms = (v) * 12)
end_define

begin_define
define|#
directive|define
name|H_SET_ENTRY_POINT
parameter_list|(
name|h
parameter_list|,
name|v
parameter_list|)
value|((h)->header.a_entry = (v))
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

begin_struct_decl
struct_decl|struct
name|fix
struct_decl|;
end_struct_decl

begin_decl_stmt
name|void
name|tc_aout_fix_to_chars
name|PARAMS
argument_list|(
operator|(
name|char
operator|*
name|where
operator|,
expr|struct
name|fix
operator|*
name|fixP
operator|,
name|relax_addressT
name|segment_address
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|obj_read_begin_hook
parameter_list|()
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

begin_define
define|#
directive|define
name|EMIT_SECTION_SYMBOLS
value|0
end_define

begin_define
define|#
directive|define
name|AOUT_STABS
end_define

end_unit

