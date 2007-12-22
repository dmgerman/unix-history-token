begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Exported functions from emit-rtl.c    Copyright (C) 2004 Free Software Foundation, Inc.  This file is part of GCC.  GCC is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2, or (at your option) any later version.  GCC is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with GCC; see the file COPYING.  If not, write to the Free Software Foundation, 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301, USA.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|GCC_EMIT_RTL_H
end_ifndef

begin_define
define|#
directive|define
name|GCC_EMIT_RTL_H
end_define

begin_comment
comment|/* Set the alias set of MEM to SET.  */
end_comment

begin_function_decl
specifier|extern
name|void
name|set_mem_alias_set
parameter_list|(
name|rtx
parameter_list|,
name|HOST_WIDE_INT
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Set the alignment of MEM to ALIGN bits.  */
end_comment

begin_function_decl
specifier|extern
name|void
name|set_mem_align
parameter_list|(
name|rtx
parameter_list|,
name|unsigned
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Set the expr for MEM to EXPR.  */
end_comment

begin_function_decl
specifier|extern
name|void
name|set_mem_expr
parameter_list|(
name|rtx
parameter_list|,
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Set the offset for MEM to OFFSET.  */
end_comment

begin_function_decl
specifier|extern
name|void
name|set_mem_offset
parameter_list|(
name|rtx
parameter_list|,
name|rtx
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Set the size for MEM to SIZE.  */
end_comment

begin_function_decl
specifier|extern
name|void
name|set_mem_size
parameter_list|(
name|rtx
parameter_list|,
name|rtx
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Return a memory reference like MEMREF, but with its address changed to    ADDR.  The caller is asserting that the actual piece of memory pointed    to is the same, just the form of the address is being changed, such as    by putting something into a register.  */
end_comment

begin_function_decl
specifier|extern
name|rtx
name|replace_equiv_address
parameter_list|(
name|rtx
parameter_list|,
name|rtx
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Likewise, but the reference is not required to be valid.  */
end_comment

begin_function_decl
specifier|extern
name|rtx
name|replace_equiv_address_nv
parameter_list|(
name|rtx
parameter_list|,
name|rtx
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* GCC_EMIT_RTL_H */
end_comment

end_unit

