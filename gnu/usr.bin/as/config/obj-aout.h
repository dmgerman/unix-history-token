begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* obj-aout.h, a.out object file format for gas, the assembler.    Copyright (C) 1989, 1990, 1991, 1992 Free Software Foundation, Inc.     This file is part of GAS, the GNU Assembler.     GAS is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as    published by the Free Software Foundation; either version 2,    or (at your option) any later version.     GAS is distributed in the hope that it will be useful, but    WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See    the GNU General Public License for more details.     You should have received a copy of the GNU General Public    License along with GAS; see the file COPYING.  If not, write    to the Free Software Foundation, 675 Mass Ave, Cambridge, MA 02139, USA.   $FreeBSD$  */
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

begin_include
include|#
directive|include
file|"aout.h"
end_include

begin_comment
comment|/* Needed to define struct nlist. Sigh. */
end_comment

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

begin_ifndef
ifndef|#
directive|ifndef
name|AOUT_VERSION
end_ifndef

begin_define
define|#
directive|define
name|AOUT_VERSION
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|AOUT_FLAGS
end_ifndef

begin_define
define|#
directive|define
name|AOUT_FLAGS
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

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
name|N_REGISTER
value|0x12
end_define

begin_comment
comment|/* Fake register type */
end_comment

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

begin_comment
comment|/* First character of operand in `.type' directives */
end_comment

begin_define
define|#
directive|define
name|TYPE_OPERAND_FMT
value|'@'
end_define

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
value|((S_GET_TYPE(s) != N_UNDF) || (S_GET_OTHER(s) != 0) || (S_GET_DESC(s) != 0))
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
value|(S_GET_NAME(s) == (char *)0)
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
value|(((s)->sy_symbol.n_value))
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
value|(H_GET_HEADER_SIZE(h) \ 				 + H_GET_TEXT_SIZE(h) \ 				 + H_GET_DATA_SIZE(h) \ 				 + H_GET_SYMBOL_TABLE_SIZE(h) \ 				 + H_GET_TEXT_RELOCATION_SIZE(h) \ 				 + H_GET_DATA_RELOCATION_SIZE(h) \ 				 + H_GET_STRING_SIZE(h))
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|H_GET_HEADER_SIZE
end_ifndef

begin_define
define|#
directive|define
name|H_GET_HEADER_SIZE
parameter_list|(
name|h
parameter_list|)
value|(sizeof(struct exec))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* not H_GET_HEADER_SIZE */
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

begin_if
if|#
directive|if
name|defined
argument_list|(
name|FREEBSD_AOUT
argument_list|)
operator|||
name|defined
argument_list|(
name|NETBSD_AOUT
argument_list|)
end_if

begin_if
if|#
directive|if
name|defined
argument_list|(
name|FREEBSD_AOUT
argument_list|)
end_if

begin_comment
comment|/* duplicate part of<sys/imgact_aout.h> */
end_comment

begin_define
define|#
directive|define
name|H_GET_FLAGS
parameter_list|(
name|h
parameter_list|)
define|\
value|( (((h)->header.a_info)&0xffff)				\ 		? ((h)->header.a_info>> 26)& 0x3f )		\ 		: 0						\ 	)
end_define

begin_define
define|#
directive|define
name|H_GET_MACHTYPE
parameter_list|(
name|h
parameter_list|)
define|\
value|( (((h)->header.a_info)&0xffff)				\ 		? ((h)->header.a_info>>16 )& 0x3ff)		\ 		: 0						\ 	)
end_define

begin_define
define|#
directive|define
name|H_GET_MAGIC_NUMBER
parameter_list|(
name|h
parameter_list|)
define|\
value|( (((h)->header.a_info)&0xffff)				\ 		? ((h)->header.a_info& 0xffff)			\ 		: (ntohl(((h)->header.a_info))&0xffff)		\ 	)
end_define

begin_define
define|#
directive|define
name|H_SET_INFO
parameter_list|(
name|h
parameter_list|,
name|mag
parameter_list|,
name|mid
parameter_list|,
name|f
parameter_list|,
name|v
parameter_list|)
define|\
value|( (h)->header.a_info =					\ 	   (((f)&0x3f)<<26) | (((mid)&0x03ff)<<16) | (((mag)&0xffff)) )
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* FREEBSD_AOUT */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|NETBSD_AOUT
argument_list|)
end_if

begin_comment
comment|/* SH*T, duplicate part of<a.out.h> */
end_comment

begin_define
define|#
directive|define
name|H_GET_FLAGS
parameter_list|(
name|h
parameter_list|)
define|\
value|( (((h)->header.a_info)&0xffff0000)			\ 		? ((ntohl(((h)->header.a_info))>>26)&0x3f)	\ 		: 0						\ 	)
end_define

begin_define
define|#
directive|define
name|H_GET_MACHTYPE
parameter_list|(
name|h
parameter_list|)
define|\
value|( (((h)->header.a_info)&0xffff0000)			\ 		? ((ntohl(((h)->header.a_info))>>16)&0x3ff)	\ 		: 0						\ 	)
end_define

begin_define
define|#
directive|define
name|H_GET_MAGIC_NUMBER
parameter_list|(
name|h
parameter_list|)
define|\
value|( (((h)->header.a_info)&0xffff0000)			\ 		? (ntohl(((h)->header.a_info))&0xffff)		\ 		: ((h)->header.a_info& 0xffff)			\ 	)
end_define

begin_define
define|#
directive|define
name|H_SET_INFO
parameter_list|(
name|h
parameter_list|,
name|mag
parameter_list|,
name|mid
parameter_list|,
name|f
parameter_list|,
name|v
parameter_list|)
define|\
value|( (h)->header.a_info =					\ 	   htonl( (((f)&0x3f)<<26) | (((mid)&0x03ff)<<16) | (((mag)&0xffff)) ) )
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* NETBSD_AOUT */
end_comment

begin_define
define|#
directive|define
name|EX_DYNAMIC
value|0x20
end_define

begin_define
define|#
directive|define
name|EX_PIC
value|0x10
end_define

begin_undef
undef|#
directive|undef
name|AOUT_FLAGS
end_undef

begin_define
define|#
directive|define
name|AOUT_FLAGS
value|(picmode ? EX_PIC : 0)
end_define

begin_define
define|#
directive|define
name|H_GET_DYNAMIC
parameter_list|(
name|h
parameter_list|)
value|(H_GET_FLAGS(h)& EX_DYNAMIC)
end_define

begin_define
define|#
directive|define
name|H_GET_VERSION
parameter_list|(
name|h
parameter_list|)
value|(0)
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
define|\
value|H_SET_INFO(h, H_GET_MAGIC_NUMBER(h), H_GET_MACHTYPE(h),	\ 		   (v)?(H_GET_FLAGS(h)|0x20):(H_GET_FLAGS(h)&(~0x20)), 0)
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
define|\
value|H_SET_INFO(h, H_GET_MAGIC_NUMBER(h), (v), H_GET_FLAGS(h), 0)
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
define|\
value|H_SET_INFO(h, (v), H_GET_MACHTYPE(h), H_GET_FLAGS(h), 0)
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* !(FREEBSD_AOUT || NETBSD_AOUT) */
end_comment

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
value|((h)->header.a_info = \ 						(((v)<< 31) \ 						| (H_GET_VERSION(h)<< 24) \ 						| (H_GET_MACHTYPE(h)<< 16) \ 						| (H_GET_MAGIC_NUMBER(h))))
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
value|((h)->header.a_info = \ 						((H_GET_DYNAMIC(h)<< 31) \ 						| ((v)<< 24) \ 						| (H_GET_MACHTYPE(h)<< 16) \ 						| (H_GET_MAGIC_NUMBER(h))))
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
value|((h)->header.a_info = \ 						((H_GET_DYNAMIC(h)<< 31) \ 						| (H_GET_VERSION(h)<< 24) \ 						| ((v)<< 16) \ 						| (H_GET_MAGIC_NUMBER(h))))
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
value|((h)->header.a_info = \ 						((H_GET_DYNAMIC(h)<< 31) \ 						| (H_GET_VERSION(h)<< 24) \ 						| (H_GET_MACHTYPE(h)<< 16) \ 						| ((v))))
end_define

begin_define
define|#
directive|define
name|H_SET_INFO
parameter_list|(
name|h
parameter_list|,
name|mag
parameter_list|,
name|mid
parameter_list|,
name|f
parameter_list|,
name|v
parameter_list|)
value|((h)->header.a_info = \ 						((((f)==0x20)<< 31) \ 						| ((v)<< 24) \ 						| ((mid)<< 16) \ 						| ((mag))) )
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* FREEBSD_AOUT || NETBSD_AOUT */
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
value|((h)->header.a_syms = (v) * \ 					 sizeof(struct nlist))
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
value|(seg_name[(int)(seg)])
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
comment|/* line numbering stuff. */
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

begin_if
if|#
directive|if
name|__STDC__
operator|==
literal|1
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

begin_comment
comment|/*  * Local Variables:  * comment-column: 0  * fill-column: 131  * End:  */
end_comment

begin_comment
comment|/* end of obj-aout.h */
end_comment

end_unit

