begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* dw2gencfi.h - Support for generating Dwarf2 CFI information.    Copyright 2003 Free Software Foundation, Inc.    Contributed by Michal Ludvig<mludvig@suse.cz>     This file is part of GAS, the GNU Assembler.     GAS is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2, or (at your option)    any later version.     GAS is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.     You should have received a copy of the GNU General Public License    along with GAS; see the file COPYING.  If not, write to the Free    Software Foundation, 59 Temple Place - Suite 330, Boston, MA    02111-1307, USA.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|DW2GENCFI_H
end_ifndef

begin_define
define|#
directive|define
name|DW2GENCFI_H
end_define

begin_include
include|#
directive|include
file|"elf/dwarf2.h"
end_include

begin_struct_decl
struct_decl|struct
name|symbol
struct_decl|;
end_struct_decl

begin_decl_stmt
specifier|extern
specifier|const
name|pseudo_typeS
name|cfi_pseudo_table
index|[]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* cfi_finish() is called at the end of file. It will complain if    the last CFI wasn't properly closed by .cfi_endproc.  */
end_comment

begin_function_decl
specifier|extern
name|void
name|cfi_finish
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Entry points for backends to add unwind information.  */
end_comment

begin_function_decl
specifier|extern
name|void
name|cfi_new_fde
parameter_list|(
name|struct
name|symbol
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|cfi_end_fde
parameter_list|(
name|struct
name|symbol
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|cfi_set_return_column
parameter_list|(
name|unsigned
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|cfi_add_advance_loc
parameter_list|(
name|struct
name|symbol
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|cfi_add_CFA_offset
parameter_list|(
name|unsigned
parameter_list|,
name|offsetT
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|cfi_add_CFA_def_cfa
parameter_list|(
name|unsigned
parameter_list|,
name|offsetT
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|cfi_add_CFA_register
parameter_list|(
name|unsigned
parameter_list|,
name|unsigned
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|cfi_add_CFA_def_cfa_register
parameter_list|(
name|unsigned
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|cfi_add_CFA_def_cfa_offset
parameter_list|(
name|offsetT
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|cfi_add_CFA_restore
parameter_list|(
name|unsigned
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|cfi_add_CFA_undefined
parameter_list|(
name|unsigned
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|cfi_add_CFA_same_value
parameter_list|(
name|unsigned
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|cfi_add_CFA_remember_state
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|cfi_add_CFA_restore_state
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* DW2GENCFI_H */
end_comment

end_unit

