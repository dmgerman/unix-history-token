begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* macro.h - header file for macro support for gas    Copyright 1994, 1995, 1996, 1997, 1998, 2000, 2002    Free Software Foundation, Inc.     Written by Steve and Judy Chamberlain of Cygnus Support,       sac@cygnus.com     This file is part of GAS, the GNU Assembler.     GAS is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2, or (at your option)    any later version.     GAS is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.     You should have received a copy of the GNU General Public License    along with GAS; see the file COPYING.  If not, write to the Free    Software Foundation, 59 Temple Place - Suite 330, Boston, MA    02111-1307, USA.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|MACRO_H
end_ifndef

begin_define
define|#
directive|define
name|MACRO_H
end_define

begin_include
include|#
directive|include
file|"ansidecl.h"
end_include

begin_include
include|#
directive|include
file|"sb.h"
end_include

begin_comment
comment|/* Structures used to store macros.     Each macro knows its name and included text.  It gets built with a    list of formal arguments, and also keeps a hash table which points    into the list to speed up formal search.  Each formal knows its    name and its default value.  Each time the macro is expanded, the    formals get the actual values attached to them.  */
end_comment

begin_comment
comment|/* Describe the formal arguments to a macro.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|formal_struct
block|{
name|struct
name|formal_struct
modifier|*
name|next
decl_stmt|;
comment|/* Next formal in list.  */
name|sb
name|name
decl_stmt|;
comment|/* Name of the formal.  */
name|sb
name|def
decl_stmt|;
comment|/* The default value.  */
name|sb
name|actual
decl_stmt|;
comment|/* The actual argument (changed on each expansion).  */
name|int
name|index
decl_stmt|;
comment|/* The index of the formal 0..formal_count - 1.  */
block|}
name|formal_entry
typedef|;
end_typedef

begin_comment
comment|/* Other values found in the index field of a formal_entry.  */
end_comment

begin_define
define|#
directive|define
name|QUAL_INDEX
value|(-1)
end_define

begin_define
define|#
directive|define
name|NARG_INDEX
value|(-2)
end_define

begin_define
define|#
directive|define
name|LOCAL_INDEX
value|(-3)
end_define

begin_comment
comment|/* Describe the macro.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|macro_struct
block|{
name|sb
name|sub
decl_stmt|;
comment|/* Substitution text.  */
name|int
name|formal_count
decl_stmt|;
comment|/* Number of formal args.  */
name|formal_entry
modifier|*
name|formals
decl_stmt|;
comment|/* Pointer to list of formal_structs.  */
name|struct
name|hash_control
modifier|*
name|formal_hash
decl_stmt|;
comment|/* Hash table of formals.  */
block|}
name|macro_entry
typedef|;
end_typedef

begin_comment
comment|/* Whether any macros have been defined.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|macro_defined
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* The macro nesting level.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|macro_nest
decl_stmt|;
end_decl_stmt

begin_function_decl
specifier|extern
name|int
name|buffer_and_nest
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
name|sb
modifier|*
parameter_list|,
name|int
function_decl|(
modifier|*
function_decl|)
parameter_list|(
name|sb
modifier|*
parameter_list|)
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|macro_init
parameter_list|(
name|int
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|,
name|int
function_decl|(
modifier|*
function_decl|)
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
name|int
parameter_list|,
name|sb
modifier|*
parameter_list|,
name|int
modifier|*
parameter_list|)
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|macro_mri_mode
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
specifier|const
name|char
modifier|*
name|define_macro
parameter_list|(
name|int
parameter_list|,
name|sb
modifier|*
parameter_list|,
name|sb
modifier|*
parameter_list|,
name|int
function_decl|(
modifier|*
function_decl|)
parameter_list|(
name|sb
modifier|*
parameter_list|)
parameter_list|,
specifier|const
name|char
modifier|*
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|check_macro
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
name|sb
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
modifier|*
parameter_list|,
name|macro_entry
modifier|*
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|delete_macro
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
specifier|const
name|char
modifier|*
name|expand_irp
parameter_list|(
name|int
parameter_list|,
name|int
parameter_list|,
name|sb
modifier|*
parameter_list|,
name|sb
modifier|*
parameter_list|,
name|int
function_decl|(
modifier|*
function_decl|)
parameter_list|(
name|sb
modifier|*
parameter_list|)
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

end_unit

