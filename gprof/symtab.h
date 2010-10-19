begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* symtab.h     Copyright 2000, 2001, 2002, 2004 Free Software Foundation, Inc.  This file is part of GNU Binutils.  This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version.  This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with this program; if not, write to the Free Software Foundation, Inc., 51 Franklin Street - Fifth Floor, Boston, MA 02110-1301, USA.  */
end_comment

begin_escape
end_escape

begin_ifndef
ifndef|#
directive|ifndef
name|symtab_h
end_ifndef

begin_define
define|#
directive|define
name|symtab_h
end_define

begin_comment
comment|/* For a profile to be intelligible to a human user, it is necessary    to map code-addresses into source-code information.  Source-code    information can be any combination of: (i) function-name, (ii)    source file-name, and (iii) source line number.     The symbol table is used to map addresses into source-code    information.  */
end_comment

begin_define
define|#
directive|define
name|NBBS
value|10
end_define

begin_comment
comment|/* Symbol-entry.  For each external in the specified file we gather    its address, the number of calls and compute its share of cpu time.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|sym
block|{
comment|/* Common information:         In the symbol-table, fields ADDR and FUNC_NAME are guaranteed        to contain valid information.  FILE may be 0, if unknown and        LINE_NUM maybe 0 if unknown.  */
name|bfd_vma
name|addr
decl_stmt|;
comment|/* Address of entry point.  */
name|bfd_vma
name|end_addr
decl_stmt|;
comment|/* End-address.  */
specifier|const
name|char
modifier|*
name|name
decl_stmt|;
comment|/* Name of function this sym is from.  */
name|Source_File
modifier|*
name|file
decl_stmt|;
comment|/* Source file symbol comes from.  */
name|int
name|line_num
decl_stmt|;
comment|/* Source line number.  */
name|unsigned
name|int
comment|/* Boolean fields:  */
name|is_func
range|:
literal|1
decl_stmt|,
comment|/*  Is this a function entry point?  */
name|is_static
range|:
literal|1
decl_stmt|,
comment|/*  Is this a local (static) symbol?  */
name|is_bb_head
range|:
literal|1
decl_stmt|,
comment|/*  Is this the head of a basic-blk?  */
name|mapped
range|:
literal|1
decl_stmt|,
comment|/*  This symbol was mapped to another name.  */
name|has_been_placed
range|:
literal|1
decl_stmt|;
comment|/*  Have we placed this symbol?  */
name|unsigned
name|long
name|ncalls
decl_stmt|;
comment|/* How many times executed  */
name|int
name|nuses
decl_stmt|;
comment|/* How many times this symbol appears in 				   a particular context.  */
name|bfd_vma
name|bb_addr
index|[
name|NBBS
index|]
decl_stmt|;
comment|/* Address of basic-block start.  */
name|unsigned
name|long
name|bb_calls
index|[
name|NBBS
index|]
decl_stmt|;
comment|/* How many times basic-block was called.  */
name|struct
name|sym
modifier|*
name|next
decl_stmt|;
comment|/* For building chains of syms.  */
name|struct
name|sym
modifier|*
name|prev
decl_stmt|;
comment|/* For building chains of syms.  */
comment|/* Profile specific information:  */
comment|/* Histogram specific information:  */
struct|struct
block|{
name|double
name|time
decl_stmt|;
comment|/* (Weighted) ticks in this routine.  */
name|bfd_vma
name|scaled_addr
decl_stmt|;
comment|/* Scaled entry point.  */
block|}
name|hist
struct|;
comment|/* Call-graph specific information:  */
struct|struct
block|{
name|unsigned
name|long
name|self_calls
decl_stmt|;
comment|/* How many calls to self.  */
name|double
name|child_time
decl_stmt|;
comment|/* Cumulative ticks in children.  */
name|int
name|index
decl_stmt|;
comment|/* Index in the graph list.  */
name|int
name|top_order
decl_stmt|;
comment|/* Graph call chain top-sort order.  */
name|bfd_boolean
name|print_flag
decl_stmt|;
comment|/* Should this be printed?  */
struct|struct
block|{
name|double
name|fract
decl_stmt|;
comment|/* What % of time propagates.  */
name|double
name|self
decl_stmt|;
comment|/* How much self time propagates.  */
name|double
name|child
decl_stmt|;
comment|/* How much child time propagates.  */
block|}
name|prop
struct|;
struct|struct
block|{
name|int
name|num
decl_stmt|;
comment|/* Internal number of cycle on.  */
name|struct
name|sym
modifier|*
name|head
decl_stmt|;
comment|/* Head of cycle.  */
name|struct
name|sym
modifier|*
name|next
decl_stmt|;
comment|/* Next member of cycle.  */
block|}
name|cyc
struct|;
name|struct
name|arc
modifier|*
name|parents
decl_stmt|;
comment|/* List of caller arcs.  */
name|struct
name|arc
modifier|*
name|children
decl_stmt|;
comment|/* List of callee arcs.  */
block|}
name|cg
struct|;
block|}
name|Sym
typedef|;
end_typedef

begin_comment
comment|/* Symbol-tables are always assumed to be sorted    in increasing order of addresses.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|unsigned
name|int
name|len
decl_stmt|;
comment|/* # of symbols in this table.  */
name|Sym
modifier|*
name|base
decl_stmt|;
comment|/* First element in symbol table.  */
name|Sym
modifier|*
name|limit
decl_stmt|;
comment|/* Limit = base + len.  */
block|}
name|Sym_Table
typedef|;
end_typedef

begin_decl_stmt
specifier|extern
name|Sym_Table
name|symtab
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* The symbol table.  */
end_comment

begin_function_decl
specifier|extern
name|void
name|sym_init
parameter_list|(
name|Sym
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|symtab_finalize
parameter_list|(
name|Sym_Table
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_ifdef
ifdef|#
directive|ifdef
name|DEBUG
end_ifdef

begin_function_decl
specifier|extern
name|Sym
modifier|*
name|dbg_sym_lookup
parameter_list|(
name|Sym_Table
modifier|*
parameter_list|,
name|bfd_vma
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_function_decl
specifier|extern
name|Sym
modifier|*
name|sym_lookup
parameter_list|(
name|Sym_Table
modifier|*
parameter_list|,
name|bfd_vma
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|find_call
parameter_list|(
name|Sym
modifier|*
parameter_list|,
name|bfd_vma
parameter_list|,
name|bfd_vma
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* symtab_h */
end_comment

end_unit

