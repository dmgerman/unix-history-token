begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Fortran language support definitions for GDB, the GNU debugger.    Copyright 1992, 1993, 1994 Free Software Foundation, Inc.    Contributed by Motorola.  Adapted from the C definitions by Farooq Butt    (fmbutt@engage.sps.mot.com).  This file is part of GDB.  This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version.  This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with this program; if not, write to the Free Software Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|f_parse
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
name|f_error
name|PARAMS
argument_list|(
operator|(
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Defined in f-exp.y */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|f_print_type
name|PARAMS
argument_list|(
operator|(
expr|struct
name|type
operator|*
operator|,
name|char
operator|*
operator|,
name|GDB_FILE
operator|*
operator|,
name|int
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|f_val_print
name|PARAMS
argument_list|(
operator|(
expr|struct
name|type
operator|*
operator|,
name|char
operator|*
operator|,
name|int
operator|,
name|CORE_ADDR
operator|,
name|GDB_FILE
operator|*
operator|,
name|int
operator|,
name|int
operator|,
name|int
operator|,
expr|enum
name|val_prettyprint
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Language-specific data structures */
end_comment

begin_struct
struct|struct
name|common_entry
block|{
name|struct
name|symbol
modifier|*
name|symbol
decl_stmt|;
comment|/* The symbol node corresponding 					       to this component */
name|struct
name|common_entry
modifier|*
name|next
decl_stmt|;
comment|/* The next component */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|saved_f77_common
block|{
name|char
modifier|*
name|name
decl_stmt|;
comment|/* Name of COMMON */
name|char
modifier|*
name|owning_function
decl_stmt|;
comment|/* Name of parent function */
name|int
name|secnum
decl_stmt|;
comment|/* Section # of .bss */
name|CORE_ADDR
name|offset
decl_stmt|;
comment|/* Offset from .bss for  						this block */
name|struct
name|common_entry
modifier|*
name|entries
decl_stmt|;
comment|/* List of block's components */
name|struct
name|common_entry
modifier|*
name|end_of_entries
decl_stmt|;
comment|/* ptr. to end of components */
name|struct
name|saved_f77_common
modifier|*
name|next
decl_stmt|;
comment|/* Next saved COMMON block */
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|saved_f77_common
name|SAVED_F77_COMMON
typedef|,
modifier|*
name|SAVED_F77_COMMON_PTR
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|common_entry
name|COMMON_ENTRY
typedef|,
modifier|*
name|COMMON_ENTRY_PTR
typedef|;
end_typedef

begin_decl_stmt
specifier|extern
name|SAVED_F77_COMMON_PTR
name|head_common_list
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Ptr to 1st saved COMMON  */
end_comment

begin_decl_stmt
specifier|extern
name|SAVED_F77_COMMON_PTR
name|tail_common_list
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Ptr to last saved COMMON  */
end_comment

begin_decl_stmt
specifier|extern
name|SAVED_F77_COMMON_PTR
name|current_common
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Ptr to current COMMON */
end_comment

begin_decl_stmt
specifier|extern
name|SAVED_F77_COMMON_PTR
name|find_common_for_function
name|PARAMS
argument_list|(
operator|(
name|char
operator|*
operator|,
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|UNINITIALIZED_SECNUM
value|-1
end_define

begin_define
define|#
directive|define
name|COMMON_NEEDS_PATCHING
parameter_list|(
name|blk
parameter_list|)
value|((blk)->secnum == UNINITIALIZED_SECNUM)
end_define

begin_define
define|#
directive|define
name|BLANK_COMMON_NAME_ORIGINAL
value|"#BLNK_COM"
end_define

begin_comment
comment|/* XLF assigned  */
end_comment

begin_define
define|#
directive|define
name|BLANK_COMMON_NAME_MF77
value|"__BLNK__"
end_define

begin_comment
comment|/* MF77 assigned  */
end_comment

begin_define
define|#
directive|define
name|BLANK_COMMON_NAME_LOCAL
value|"__BLANK"
end_define

begin_comment
comment|/* Local GDB */
end_comment

begin_define
define|#
directive|define
name|BOUND_FETCH_OK
value|1
end_define

begin_define
define|#
directive|define
name|BOUND_FETCH_ERROR
value|-999
end_define

begin_comment
comment|/* When reasonable array bounds cannot be fetched, such as when  you ask to 'mt print symbols' and there is no stack frame and  therefore no way of knowing the bounds of stack-based arrays,  we have to assign default bounds, these are as good as any... */
end_comment

begin_define
define|#
directive|define
name|DEFAULT_UPPER_BOUND
value|999999
end_define

begin_define
define|#
directive|define
name|DEFAULT_LOWER_BOUND
value|-999999
end_define

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|real_main_name
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Name of main function */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|real_main_c_value
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* C_value field of main function */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|f77_get_dynamic_upperbound
name|PARAMS
argument_list|(
operator|(
expr|struct
name|type
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
name|int
name|f77_get_dynamic_lowerbound
name|PARAMS
argument_list|(
operator|(
expr|struct
name|type
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
name|f77_get_dynamic_array_length
name|PARAMS
argument_list|(
operator|(
expr|struct
name|type
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|calc_f77_array_dims
name|PARAMS
argument_list|(
operator|(
expr|struct
name|type
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|DEFAULT_DOTMAIN_NAME_IN_MF77
value|".MAIN_"
end_define

begin_define
define|#
directive|define
name|DEFAULT_MAIN_NAME_IN_MF77
value|"MAIN_"
end_define

begin_define
define|#
directive|define
name|DEFAULT_DOTMAIN_NAME_IN_XLF_BUGGY
value|".main "
end_define

begin_define
define|#
directive|define
name|DEFAULT_DOTMAIN_NAME_IN_XLF
value|".main"
end_define

end_unit

