begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* b.out object file format    Copyright (C) 1989, 1990, 1991, 1992 Free Software Foundation, Inc.     This file is part of GAS, the GNU Assembler.     GAS is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as    published by the Free Software Foundation; either version 2,    or (at your option) any later version.     GAS is distributed in the hope that it will be useful, but    WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See    the GNU General Public License for more details.     You should have received a copy of the GNU General Public    License along with GAS; see the file COPYING.  If not, write    to the Free Software Foundation, 675 Mass Ave, Cambridge, MA    02139, USA. */
end_comment

begin_comment
comment|/*  * This file is a modified version of 'a.out.h'.  It is to be used in all GNU  * tools modified to support the i80960 b.out format (or tools that operate on  * object files created by such tools).  *  * All i80960 development is done in a CROSS-DEVELOPMENT environment.  I.e.,  * object code is generated on, and executed under the direction of a symbolic  * debugger running on, a host system.  We do not want to be subject to the  * vagaries of which host it is or whether it supports COFF or a.out format, or  * anything else.  We DO want to:  *  *	o always generate the same format object files, regardless of host.  *  *	o have an 'a.out' header that we can modify for our own purposes  *	  (the 80960 is typically an embedded processor and may require  *	  enhanced linker support that the normal a.out.h header can't  *	  accommodate).  *  * As for byte-ordering, the following rules apply:  *  *	o Text and data that is actually downloaded to the target is always  *	  in i80960 (little-endian) order.  *  *	o All other numbers (in the header, symbols, relocation directives)  *	  are in host byte-order:  object files CANNOT be lifted from a  *	  little-end host and used on a big-endian (or vice versa) without  *	  modification.  *  *	o The downloader ('comm960') takes care to generate a pseudo-header  *	  with correct (i80960) byte-ordering before shipping text and data  *	  off to the NINDY monitor in the target systems.  Symbols and  *	  relocation info are never sent to the target.  */
end_comment

begin_define
define|#
directive|define
name|OBJ_BOUT
value|1
end_define

begin_include
include|#
directive|include
file|"targ-cpu.h"
end_include

begin_comment
comment|/* bout uses host byte order for headers */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|CROSS_COMPILE
end_ifdef

begin_undef
undef|#
directive|undef
name|CROSS_COMPILE
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* CROSS_COMPILE */
end_comment

begin_comment
comment|/* We want \v. */
end_comment

begin_define
define|#
directive|define
name|BACKSLASH_V
value|1
end_define

begin_define
define|#
directive|define
name|OBJ_DEFAULT_OUTPUT_FILE_NAME
value|"b.out"
end_define

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

begin_define
define|#
directive|define
name|BMAGIC
value|0415
end_define

begin_comment
comment|/* We don't accept the following (see N_BADMAG macro).  * They're just here so GNU code will compile.  */
end_comment

begin_define
define|#
directive|define
name|OMAGIC
value|0407
end_define

begin_comment
comment|/* old impure format */
end_comment

begin_define
define|#
directive|define
name|NMAGIC
value|0410
end_define

begin_comment
comment|/* read-only text */
end_comment

begin_define
define|#
directive|define
name|ZMAGIC
value|0413
end_define

begin_comment
comment|/* demand load format */
end_comment

begin_comment
comment|/* FILE HEADER  *	All 'lengths' are given as a number of bytes.  *	All 'alignments' are for relinkable files only;  an alignment of  *		'n' indicates the corresponding segment must begin at an  *		address that is a multiple of (2**n).  */
end_comment

begin_struct
struct|struct
name|exec
block|{
comment|/* Standard stuff */
name|unsigned
name|long
name|a_magic
decl_stmt|;
comment|/* Identifies this as a b.out file	*/
name|unsigned
name|long
name|a_text
decl_stmt|;
comment|/* Length of text			*/
name|unsigned
name|long
name|a_data
decl_stmt|;
comment|/* Length of data			*/
name|unsigned
name|long
name|a_bss
decl_stmt|;
comment|/* Length of runtime uninitialized data area */
name|unsigned
name|long
name|a_syms
decl_stmt|;
comment|/* Length of symbol table		*/
name|unsigned
name|long
name|a_entry
decl_stmt|;
comment|/* Runtime start address		*/
name|unsigned
name|long
name|a_trsize
decl_stmt|;
comment|/* Length of text relocation info	*/
name|unsigned
name|long
name|a_drsize
decl_stmt|;
comment|/* Length of data relocation info	*/
comment|/* Added for i960 */
name|unsigned
name|long
name|a_tload
decl_stmt|;
comment|/* Text runtime load address		*/
name|unsigned
name|long
name|a_dload
decl_stmt|;
comment|/* Data runtime load address		*/
name|unsigned
name|char
name|a_talign
decl_stmt|;
comment|/* Alignment of text segment		*/
name|unsigned
name|char
name|a_dalign
decl_stmt|;
comment|/* Alignment of data segment		*/
name|unsigned
name|char
name|a_balign
decl_stmt|;
comment|/* Alignment of bss segment		*/
name|unsigned
name|char
name|unused
decl_stmt|;
comment|/* (Just to make struct size a multiple of 4) */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|N_BADMAG
parameter_list|(
name|x
parameter_list|)
value|(((x).a_magic) != BMAGIC)
end_define

begin_define
define|#
directive|define
name|N_TXTOFF
parameter_list|(
name|x
parameter_list|)
value|( sizeof(struct exec) )
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
comment|/* A single entry in the symbol table  */
end_comment

begin_struct
struct|struct
name|nlist
block|{
union|union
block|{
name|char
modifier|*
name|n_name
decl_stmt|;
name|struct
name|nlist
modifier|*
name|n_next
decl_stmt|;
name|long
name|n_strx
decl_stmt|;
comment|/* Index into string table	*/
block|}
name|n_un
union|;
name|unsigned
name|char
name|n_type
decl_stmt|;
comment|/* See below				*/
name|char
name|n_other
decl_stmt|;
comment|/* Used in i80960 support -- see below	*/
name|short
name|n_desc
decl_stmt|;
name|unsigned
name|long
name|n_value
decl_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|nlist
name|obj_symbol_type
typedef|;
end_typedef

begin_comment
comment|/* Legal values of n_type  */
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

begin_ifndef
ifndef|#
directive|ifndef
name|CUSTOM_RELOC_FORMAT
end_ifndef

begin_struct
struct|struct
name|relocation_info
block|{
name|int
name|r_address
decl_stmt|;
comment|/* File address of item to be relocated	*/
name|unsigned
name|r_index
range|:
literal|24
decl_stmt|,
comment|/* Index of symbol on which relocation is based*/
name|r_pcrel
range|:
literal|1
decl_stmt|,
comment|/* 1 => relocate PC-relative; else absolute 		 *	On i960, pc-relative implies 24-bit 		 *	address, absolute implies 32-bit. 		 */
name|r_length
range|:
literal|2
decl_stmt|,
comment|/* Number of bytes to relocate: 		 *	0 => 1 byte 		 *	1 => 2 bytes 		 *	2 => 4 bytes -- only value used for i960 		 */
name|r_extern
range|:
literal|1
decl_stmt|,
name|r_bsr
range|:
literal|1
decl_stmt|,
comment|/* Something for the GNU NS32K assembler */
name|r_disp
range|:
literal|1
decl_stmt|,
comment|/* Something for the GNU NS32K assembler */
name|r_callj
range|:
literal|1
decl_stmt|,
comment|/* 1 if relocation target is an i960 'callj' */
name|nuthin
range|:
literal|1
decl_stmt|;
comment|/* Unused				*/
block|}
struct|;
end_struct

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* CUSTOM_RELOC_FORMAT */
end_comment

begin_comment
comment|/*  *  Macros to extract information from a symbol table entry.  *  This syntaxic indirection allows independence regarding a.out or coff.  *  The argument (s) of all these macros is a pointer to a symbol table entry.  */
end_comment

begin_comment
comment|/* Predicates */
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
value|((S_GET_TYPE(s) != N_UNDF) || (S_GET_DESC(s) != 0))
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
comment|/* A symbol name whose name begin with ^A is a gas internal pseudo symbol    nameless symbols come from .stab directives. */
end_comment

begin_define
define|#
directive|define
name|S_IS_LOCAL
parameter_list|(
name|s
parameter_list|)
value|(S_GET_NAME(s)&& \ 				 !S_IS_DEBUG(s)&& \ 				 (S_GET_NAME(s)[0] == '\001' || \ 				  (S_LOCAL_NAME(s)&& !flagseen['L'])))
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
value|(S_GET_NAME(s) == NULL)
end_define

begin_comment
comment|/* Accessors */
end_comment

begin_comment
comment|/* The value of the symbol */
end_comment

begin_define
define|#
directive|define
name|S_GET_VALUE
parameter_list|(
name|s
parameter_list|)
value|((unsigned long) ((s)->sy_symbol.n_value))
end_define

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
comment|/* Modifiers */
end_comment

begin_comment
comment|/* Set the value of the symbol */
end_comment

begin_define
define|#
directive|define
name|S_SET_VALUE
parameter_list|(
name|s
parameter_list|,
name|v
parameter_list|)
value|((s)->sy_symbol.n_value = (unsigned long) (v))
end_define

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
comment|/* File header macro and type definition */
end_comment

begin_define
define|#
directive|define
name|H_GET_FILE_SIZE
parameter_list|(
name|h
parameter_list|)
value|(sizeof(struct exec) + \ 				 H_GET_TEXT_SIZE(h) + H_GET_DATA_SIZE(h) + \ 				 H_GET_SYMBOL_TABLE_SIZE(h) + \ 				 H_GET_TEXT_RELOCATION_SIZE(h) + \ 				 H_GET_DATA_RELOCATION_SIZE(h) + \ 				 (h)->string_table_size)
end_define

begin_define
define|#
directive|define
name|H_GET_HEADER_SIZE
parameter_list|(
name|h
parameter_list|)
value|(sizeof(struct exec))
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
name|H_GET_MAGIC_NUMBER
parameter_list|(
name|h
parameter_list|)
value|((h)->header.a_info)
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

begin_ifdef
ifdef|#
directive|ifdef
name|EXEC_MACHINE_TYPE
end_ifdef

begin_define
define|#
directive|define
name|H_GET_MACHINE_TYPE
parameter_list|(
name|h
parameter_list|)
value|((h)->header.a_machtype)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* EXEC_MACHINE_TYPE */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|EXEC_VERSION
end_ifdef

begin_define
define|#
directive|define
name|H_GET_VERSION
parameter_list|(
name|h
parameter_list|)
value|((h)->header.a_version)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* EXEC_VERSION */
end_comment

begin_define
define|#
directive|define
name|H_SET_TEXT_SIZE
parameter_list|(
name|h
parameter_list|,
name|v
parameter_list|)
value|((h)->header.a_text = (v))
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
value|((h)->header.a_data = (v))
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
value|((h)->header.a_bss = (v))
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
value|((h)->header.a_syms = (v) * \ 					 sizeof(struct nlist))
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
value|((h)->header.a_magic = (v))
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

begin_ifdef
ifdef|#
directive|ifdef
name|EXEC_MACHINE_TYPE
end_ifdef

begin_define
define|#
directive|define
name|H_SET_MACHINE_TYPE
parameter_list|(
name|h
parameter_list|,
name|v
parameter_list|)
value|((h)->header.a_machtype = (v))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* EXEC_MACHINE_TYPE */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|EXEC_VERSION
end_ifdef

begin_define
define|#
directive|define
name|H_SET_VERSION
parameter_list|(
name|h
parameter_list|,
name|v
parameter_list|)
value|((h)->header.a_version = (v))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* EXEC_VERSION */
end_comment

begin_comment
comment|/*  * Current means for getting the name of a segment.  * This will change for infinite-segments support (e.g. COFF).  */
end_comment

begin_define
define|#
directive|define
name|segment_name
parameter_list|(
name|seg
parameter_list|)
value|( seg_name[(int)(seg)] )
end_define

begin_decl_stmt
specifier|extern
name|char
modifier|*
specifier|const
name|seg_name
index|[]
decl_stmt|;
end_decl_stmt

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
comment|/* names + '\0' + sizeof(int) */
block|}
name|object_headers
typedef|;
end_typedef

begin_comment
comment|/* unused hooks. */
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

begin_if
if|#
directive|if
name|__STDC__
end_if

begin_struct_decl
struct_decl|struct
name|fix
struct_decl|;
end_struct_decl

begin_function_decl
name|void
name|tc_aout_fix_to_chars
parameter_list|(
name|char
modifier|*
name|where
parameter_list|,
name|struct
name|fix
modifier|*
name|fixP
parameter_list|,
name|relax_addressT
name|segment_address
parameter_list|)
function_decl|;
end_function_decl

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* not __STDC__ */
end_comment

begin_function_decl
name|void
name|tc_aout_fix_to_chars
parameter_list|()
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* not __STDC__ */
end_comment

begin_enum
enum|enum
name|reloc_type
block|{
name|NO_RELOC
block|,
name|RELOC_32
block|, }
enum|;
end_enum

begin_comment
comment|/*  * Local Variables:  * comment-column: 0  * fill-column: 131  * End:  */
end_comment

begin_comment
comment|/* end of obj-bout.h */
end_comment

end_unit

