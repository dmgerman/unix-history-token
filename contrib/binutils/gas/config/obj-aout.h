begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* obj-aout.h, a.out object file format for gas, the assembler.    Copyright 1989, 1990, 1991, 1992, 1993, 1994, 1995, 1996, 1998, 2000,    2002, 2003, 2005 Free Software Foundation, Inc.     This file is part of GAS, the GNU Assembler.     GAS is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as    published by the Free Software Foundation; either version 2,    or (at your option) any later version.     GAS is distributed in the hope that it will be useful, but    WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See    the GNU General Public License for more details.     You should have received a copy of the GNU General Public License    along with GAS; see the file COPYING.  If not, write to the Free    Software Foundation, 51 Franklin Street - Fifth Floor, Boston, MA    02110-1301, USA.  */
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
file|"bfd/libaout.h"
end_include

begin_define
define|#
directive|define
name|OUTPUT_FLAVOR
value|bfd_target_aout_flavour
end_define

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
comment|/* Symbol table entry data type.  */
end_comment

begin_typedef
typedef|typedef
name|struct
name|nlist
name|obj_symbol_type
typedef|;
end_typedef

begin_comment
comment|/* Symbol table entry.  */
end_comment

begin_comment
comment|/* Symbol table macros and constants */
end_comment

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
name|obj_frob_file_before_fix
parameter_list|()
value|obj_aout_frob_file_before_fix ()
end_define

begin_function_decl
specifier|extern
name|void
name|obj_aout_frob_symbol
parameter_list|(
name|symbolS
modifier|*
parameter_list|,
name|int
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|obj_aout_frob_file_before_fix
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|obj_sec_sym_ok_for_reloc
parameter_list|(
name|SEC
parameter_list|)
value|1
end_define

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

