begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Declarations for rtx-reader support for gen* routines.    Copyright (C) 2000, 2002, 2003 Free Software Foundation, Inc.  This file is part of GCC.  GCC is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2, or (at your option) any later version.  GCC is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with GCC; see the file COPYING.  If not, write to the Free Software Foundation, 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|GCC_GENSUPPORT_H
end_ifndef

begin_define
define|#
directive|define
name|GCC_GENSUPPORT_H
end_define

begin_struct_decl
struct_decl|struct
name|obstack
struct_decl|;
end_struct_decl

begin_decl_stmt
specifier|extern
name|struct
name|obstack
modifier|*
name|rtl_obstack
decl_stmt|;
end_decl_stmt

begin_function_decl
specifier|extern
name|int
name|init_md_reader_args
parameter_list|(
name|int
parameter_list|,
name|char
modifier|*
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|init_md_reader
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|rtx
name|read_md_rtx
parameter_list|(
name|int
modifier|*
parameter_list|,
name|int
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
specifier|extern
name|void
name|message_with_line
argument_list|(
name|int
argument_list|,
specifier|const
name|char
operator|*
argument_list|,
operator|...
argument_list|)
name|ATTRIBUTE_PRINTF_2
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Set this to 0 to disable automatic elision of insn patterns which    can never be used in this configuration.  See genconditions.c.    Must be set before calling init_md_reader.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|insn_elision
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* If this is 1, the insn elision table doesn't even exist yet;    maybe_eval_c_test will always return -1.  This is distinct from    insn_elision because genflags and gencodes need to see all the    patterns, but treat elided patterns differently.  */
end_comment

begin_decl_stmt
specifier|extern
specifier|const
name|int
name|insn_elision_unavailable
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* If the C test passed as the argument can be evaluated at compile    time, return its truth value; else return -1.  The test must have    appeared somewhere in the machine description when genconditions    was run.  */
end_comment

begin_function_decl
specifier|extern
name|int
name|maybe_eval_c_test
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* This table should not be accessed directly; use maybe_eval_c_test.  */
end_comment

begin_struct
struct|struct
name|c_test
block|{
specifier|const
name|char
modifier|*
name|expr
decl_stmt|;
name|int
name|value
decl_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
specifier|extern
specifier|const
name|struct
name|c_test
name|insn_conditions
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
specifier|const
name|size_t
name|n_insn_conditions
decl_stmt|;
end_decl_stmt

begin_ifdef
ifdef|#
directive|ifdef
name|__HASHTAB_H__
end_ifdef

begin_function_decl
specifier|extern
name|hashval_t
name|hash_c_test
parameter_list|(
specifier|const
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|cmp_c_test
parameter_list|(
specifier|const
name|void
modifier|*
parameter_list|,
specifier|const
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_function_decl
specifier|extern
name|int
name|n_comma_elts
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
name|scan_comma_elt
parameter_list|(
specifier|const
name|char
modifier|*
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* GCC_GENSUPPORT_H */
end_comment

end_unit

