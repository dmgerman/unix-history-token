begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Common subexpression elimination for GNU compiler.    Copyright (C) 1987, 1988, 1989, 1992, 1993, 1994, 1995, 1996, 1997, 1998,    1999 Free Software Foundation, Inc.  This file is part of GCC.  GCC is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2, or (at your option) any later version.  GCC is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with GCC; see the file COPYING.  If not, write to the Free Software Foundation, 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
end_comment

begin_comment
comment|/* Describe a value.  */
end_comment

begin_typedef
typedef|typedef
name|struct
name|cselib_val_struct
name|GTY
argument_list|(
operator|(
operator|)
argument_list|)
block|{
comment|/* The hash value.  */
name|unsigned
name|int
name|value
block|;
union|union
name|cselib_val_u
block|{
comment|/* A VALUE rtx that points back to this structure.  */
name|rtx
name|GTY
argument_list|(
operator|(
name|tag
argument_list|(
literal|"1"
argument_list|)
operator|)
argument_list|)
name|val_rtx
block|;
comment|/* Used to keep a list of free cselib_val structures.  */
name|struct
name|cselib_val_struct
modifier|*
name|GTY
argument_list|(
operator|(
name|skip
argument_list|(
literal|""
argument_list|)
operator|)
argument_list|)
name|next_free
block|;   }
name|GTY
argument_list|(
operator|(
name|desc
argument_list|(
literal|"1"
argument_list|)
operator|)
argument_list|)
name|u
union|;
comment|/* All rtl expressions that hold this value at the current time during a      scan.  */
name|struct
name|elt_loc_list
modifier|*
name|locs
block|;
comment|/* If this value is used as an address, points to a list of values that      use it as an address in a MEM.  */
name|struct
name|elt_list
modifier|*
name|addr_list
block|; }
end_typedef

begin_expr_stmt
name|cselib_val
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* A list of rtl expressions that hold the same value.  */
end_comment

begin_decl_stmt
name|struct
name|elt_loc_list
name|GTY
argument_list|(
operator|(
operator|)
argument_list|)
block|{
comment|/* Next element in the list.  */
name|struct
name|elt_loc_list
modifier|*
name|next
decl_stmt|;
comment|/* An rtl expression that holds the value.  */
name|rtx
name|loc
decl_stmt|;
comment|/* The insn that made the equivalence.  */
name|rtx
name|setting_insn
decl_stmt|;
comment|/* True when setting insn is inside libcall.  */
name|bool
name|in_libcall
decl_stmt|;
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
comment|/* A list of cselib_val structures.  */
end_comment

begin_decl_stmt
name|struct
name|elt_list
name|GTY
argument_list|(
operator|(
operator|)
argument_list|)
block|{
name|struct
name|elt_list
modifier|*
name|next
decl_stmt|;
name|cselib_val
modifier|*
name|elt
decl_stmt|;
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_decl_stmt
specifier|extern
name|cselib_val
modifier|*
name|cselib_lookup
name|PARAMS
argument_list|(
operator|(
name|rtx
operator|,
expr|enum
name|machine_mode
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|cselib_update_varray_sizes
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
name|cselib_init
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
name|cselib_finish
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
name|cselib_process_insn
name|PARAMS
argument_list|(
operator|(
name|rtx
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|rtx_equal_for_cselib_p
name|PARAMS
argument_list|(
operator|(
name|rtx
operator|,
name|rtx
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|references_value_p
name|PARAMS
argument_list|(
operator|(
name|rtx
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|rtx
name|cselib_subst_to_values
name|PARAMS
argument_list|(
operator|(
name|rtx
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

end_unit

