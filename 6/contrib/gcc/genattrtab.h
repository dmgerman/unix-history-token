begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* External definitions of source files of genattrtab.    Copyright (C)  2001, 2003 Free Software Foundation, Inc.  This file is part of GCC.  GCC is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2, or (at your option) any later version.  GCC is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with GCC; see the file COPYING.  If not, write to the Free Software Foundation, 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
end_comment

begin_comment
comment|/* Name of function (attribute) to translate insn into number of insn    alternatives reservation.  */
end_comment

begin_define
define|#
directive|define
name|INSN_ALTS_FUNC_NAME
value|"insn_alts"
end_define

begin_comment
comment|/* Defined in genattrtab.c: */
end_comment

begin_function_decl
specifier|extern
name|rtx
name|check_attr_test
parameter_list|(
name|rtx
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|rtx
name|make_numeric_value
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|make_internal_attr
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
name|rtx
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|attr_printf
argument_list|(
name|unsigned
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

begin_decl_stmt
specifier|extern
name|int
name|num_dfa_decls
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Defined in genautomata.c: */
end_comment

begin_function_decl
specifier|extern
name|void
name|gen_cpu_unit
parameter_list|(
name|rtx
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|gen_query_cpu_unit
parameter_list|(
name|rtx
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|gen_bypass
parameter_list|(
name|rtx
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|gen_excl_set
parameter_list|(
name|rtx
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|gen_presence_set
parameter_list|(
name|rtx
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|gen_final_presence_set
parameter_list|(
name|rtx
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|gen_absence_set
parameter_list|(
name|rtx
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|gen_final_absence_set
parameter_list|(
name|rtx
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|gen_automaton
parameter_list|(
name|rtx
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|gen_automata_option
parameter_list|(
name|rtx
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|gen_reserv
parameter_list|(
name|rtx
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|gen_insn_reserv
parameter_list|(
name|rtx
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|initiate_automaton_gen
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
name|void
name|expand_automata
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|write_automata
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Flags for make_internal_attr's `special' parameter.  */
end_comment

begin_define
define|#
directive|define
name|ATTR_NONE
value|0
end_define

begin_define
define|#
directive|define
name|ATTR_SPECIAL
value|(1<< 0)
end_define

begin_define
define|#
directive|define
name|ATTR_NEGATIVE_OK
value|(1<< 1)
end_define

begin_define
define|#
directive|define
name|ATTR_UNSIGNED
value|(1<< 2)
end_define

begin_define
define|#
directive|define
name|ATTR_FUNC_UNITS
value|(1<< 3)
end_define

begin_define
define|#
directive|define
name|ATTR_BLOCKAGE
value|(1<< 4)
end_define

begin_define
define|#
directive|define
name|ATTR_STATIC
value|(1<< 5)
end_define

end_unit

