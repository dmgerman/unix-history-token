begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Generate attribute information (insn-attr.h) from machine description.    Copyright (C) 1991, 1994, 1996, 1998, 1999, 2000, 2003, 2004    Free Software Foundation, Inc.    Contributed by Richard Kenner (kenner@vlsi1.ultra.nyu.edu)  This file is part of GCC.  GCC is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2, or (at your option) any later version.  GCC is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with GCC; see the file COPYING.  If not, write to the Free Software Foundation, 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301, USA.  */
end_comment

begin_include
include|#
directive|include
file|"bconfig.h"
end_include

begin_include
include|#
directive|include
file|"system.h"
end_include

begin_include
include|#
directive|include
file|"coretypes.h"
end_include

begin_include
include|#
directive|include
file|"tm.h"
end_include

begin_include
include|#
directive|include
file|"rtl.h"
end_include

begin_include
include|#
directive|include
file|"errors.h"
end_include

begin_include
include|#
directive|include
file|"gensupport.h"
end_include

begin_function_decl
specifier|static
name|void
name|write_upcase
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|void
name|gen_attr
parameter_list|(
name|rtx
parameter_list|)
function_decl|;
end_function_decl

begin_function
specifier|static
name|void
name|write_upcase
parameter_list|(
specifier|const
name|char
modifier|*
name|str
parameter_list|)
block|{
for|for
control|(
init|;
operator|*
name|str
condition|;
name|str
operator|++
control|)
name|putchar
argument_list|(
name|TOUPPER
argument_list|(
operator|*
name|str
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
specifier|static
name|void
name|gen_attr
parameter_list|(
name|rtx
name|attr
parameter_list|)
block|{
specifier|const
name|char
modifier|*
name|p
decl_stmt|,
modifier|*
name|tag
decl_stmt|;
name|int
name|is_const
init|=
name|GET_CODE
argument_list|(
name|XEXP
argument_list|(
name|attr
argument_list|,
literal|2
argument_list|)
argument_list|)
operator|==
name|CONST
decl_stmt|;
name|printf
argument_list|(
literal|"#define HAVE_ATTR_%s\n"
argument_list|,
name|XSTR
argument_list|(
name|attr
argument_list|,
literal|0
argument_list|)
argument_list|)
expr_stmt|;
comment|/* If numeric attribute, don't need to write an enum.  */
name|p
operator|=
name|XSTR
argument_list|(
name|attr
argument_list|,
literal|1
argument_list|)
expr_stmt|;
if|if
condition|(
operator|*
name|p
operator|==
literal|'\0'
condition|)
name|printf
argument_list|(
literal|"extern int get_attr_%s (%s);\n"
argument_list|,
name|XSTR
argument_list|(
name|attr
argument_list|,
literal|0
argument_list|)
argument_list|,
operator|(
name|is_const
condition|?
literal|"void"
else|:
literal|"rtx"
operator|)
argument_list|)
expr_stmt|;
else|else
block|{
name|printf
argument_list|(
literal|"enum attr_%s {"
argument_list|,
name|XSTR
argument_list|(
name|attr
argument_list|,
literal|0
argument_list|)
argument_list|)
expr_stmt|;
while|while
condition|(
operator|(
name|tag
operator|=
name|scan_comma_elt
argument_list|(
operator|&
name|p
argument_list|)
operator|)
operator|!=
literal|0
condition|)
block|{
name|write_upcase
argument_list|(
name|XSTR
argument_list|(
name|attr
argument_list|,
literal|0
argument_list|)
argument_list|)
expr_stmt|;
name|putchar
argument_list|(
literal|'_'
argument_list|)
expr_stmt|;
while|while
condition|(
name|tag
operator|!=
name|p
condition|)
name|putchar
argument_list|(
name|TOUPPER
argument_list|(
operator|*
name|tag
operator|++
argument_list|)
argument_list|)
expr_stmt|;
if|if
condition|(
operator|*
name|p
operator|==
literal|','
condition|)
name|fputs
argument_list|(
literal|", "
argument_list|,
name|stdout
argument_list|)
expr_stmt|;
block|}
name|fputs
argument_list|(
literal|"};\n"
argument_list|,
name|stdout
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"extern enum attr_%s get_attr_%s (%s);\n\n"
argument_list|,
name|XSTR
argument_list|(
name|attr
argument_list|,
literal|0
argument_list|)
argument_list|,
name|XSTR
argument_list|(
name|attr
argument_list|,
literal|0
argument_list|)
argument_list|,
operator|(
name|is_const
condition|?
literal|"void"
else|:
literal|"rtx"
operator|)
argument_list|)
expr_stmt|;
block|}
comment|/* If `length' attribute, write additional function definitions and define      variables used by `insn_current_length'.  */
if|if
condition|(
operator|!
name|strcmp
argument_list|(
name|XSTR
argument_list|(
name|attr
argument_list|,
literal|0
argument_list|)
argument_list|,
literal|"length"
argument_list|)
condition|)
block|{
name|puts
argument_list|(
literal|"\ extern void shorten_branches (rtx);\n\ extern int insn_default_length (rtx);\n\ extern int insn_min_length (rtx);\n\ extern int insn_variable_length_p (rtx);\n\ extern int insn_current_length (rtx);\n\n\ #include \"insn-addr.h\"\n"
argument_list|)
expr_stmt|;
block|}
block|}
end_function

begin_function
name|int
name|main
parameter_list|(
name|int
name|argc
parameter_list|,
name|char
modifier|*
modifier|*
name|argv
parameter_list|)
block|{
name|rtx
name|desc
decl_stmt|;
name|int
name|have_delay
init|=
literal|0
decl_stmt|;
name|int
name|have_annul_true
init|=
literal|0
decl_stmt|;
name|int
name|have_annul_false
init|=
literal|0
decl_stmt|;
name|int
name|num_insn_reservations
init|=
literal|0
decl_stmt|;
name|int
name|i
decl_stmt|;
name|progname
operator|=
literal|"genattr"
expr_stmt|;
if|if
condition|(
name|init_md_reader_args
argument_list|(
name|argc
argument_list|,
name|argv
argument_list|)
operator|!=
name|SUCCESS_EXIT_CODE
condition|)
return|return
operator|(
name|FATAL_EXIT_CODE
operator|)
return|;
name|puts
argument_list|(
literal|"/* Generated automatically by the program `genattr'"
argument_list|)
expr_stmt|;
name|puts
argument_list|(
literal|"   from the machine description file `md'.  */\n"
argument_list|)
expr_stmt|;
name|puts
argument_list|(
literal|"#ifndef GCC_INSN_ATTR_H"
argument_list|)
expr_stmt|;
name|puts
argument_list|(
literal|"#define GCC_INSN_ATTR_H\n"
argument_list|)
expr_stmt|;
comment|/* For compatibility, define the attribute `alternative', which is just      a reference to the variable `which_alternative'.  */
name|puts
argument_list|(
literal|"#define HAVE_ATTR_alternative"
argument_list|)
expr_stmt|;
name|puts
argument_list|(
literal|"#define get_attr_alternative(insn) which_alternative"
argument_list|)
expr_stmt|;
comment|/* Read the machine description.  */
while|while
condition|(
literal|1
condition|)
block|{
name|int
name|line_no
decl_stmt|,
name|insn_code_number
decl_stmt|;
name|desc
operator|=
name|read_md_rtx
argument_list|(
operator|&
name|line_no
argument_list|,
operator|&
name|insn_code_number
argument_list|)
expr_stmt|;
if|if
condition|(
name|desc
operator|==
name|NULL
condition|)
break|break;
if|if
condition|(
name|GET_CODE
argument_list|(
name|desc
argument_list|)
operator|==
name|DEFINE_ATTR
condition|)
name|gen_attr
argument_list|(
name|desc
argument_list|)
expr_stmt|;
elseif|else
if|if
condition|(
name|GET_CODE
argument_list|(
name|desc
argument_list|)
operator|==
name|DEFINE_DELAY
condition|)
block|{
if|if
condition|(
operator|!
name|have_delay
condition|)
block|{
name|printf
argument_list|(
literal|"#define DELAY_SLOTS\n"
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"extern int num_delay_slots (rtx);\n"
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"extern int eligible_for_delay (rtx, int, rtx, int);\n\n"
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"extern int const_num_delay_slots (rtx);\n\n"
argument_list|)
expr_stmt|;
name|have_delay
operator|=
literal|1
expr_stmt|;
block|}
for|for
control|(
name|i
operator|=
literal|0
init|;
name|i
operator|<
name|XVECLEN
argument_list|(
name|desc
argument_list|,
literal|1
argument_list|)
condition|;
name|i
operator|+=
literal|3
control|)
block|{
if|if
condition|(
name|XVECEXP
argument_list|(
name|desc
argument_list|,
literal|1
argument_list|,
name|i
operator|+
literal|1
argument_list|)
operator|&&
operator|!
name|have_annul_true
condition|)
block|{
name|printf
argument_list|(
literal|"#define ANNUL_IFTRUE_SLOTS\n"
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"extern int eligible_for_annul_true (rtx, int, rtx, int);\n"
argument_list|)
expr_stmt|;
name|have_annul_true
operator|=
literal|1
expr_stmt|;
block|}
if|if
condition|(
name|XVECEXP
argument_list|(
name|desc
argument_list|,
literal|1
argument_list|,
name|i
operator|+
literal|2
argument_list|)
operator|&&
operator|!
name|have_annul_false
condition|)
block|{
name|printf
argument_list|(
literal|"#define ANNUL_IFFALSE_SLOTS\n"
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"extern int eligible_for_annul_false (rtx, int, rtx, int);\n"
argument_list|)
expr_stmt|;
name|have_annul_false
operator|=
literal|1
expr_stmt|;
block|}
block|}
block|}
elseif|else
if|if
condition|(
name|GET_CODE
argument_list|(
name|desc
argument_list|)
operator|==
name|DEFINE_INSN_RESERVATION
condition|)
name|num_insn_reservations
operator|++
expr_stmt|;
block|}
if|if
condition|(
name|num_insn_reservations
operator|>
literal|0
condition|)
block|{
comment|/* Output interface for pipeline hazards recognition based on 	 DFA (deterministic finite state automata.  */
name|printf
argument_list|(
literal|"\n#define INSN_SCHEDULING\n"
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"\n/* DFA based pipeline interface.  */"
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"\n#ifndef AUTOMATON_ALTS\n"
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"#define AUTOMATON_ALTS 0\n"
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"#endif\n\n"
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"\n#ifndef AUTOMATON_STATE_ALTS\n"
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"#define AUTOMATON_STATE_ALTS 0\n"
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"#endif\n\n"
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"#ifndef CPU_UNITS_QUERY\n"
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"#define CPU_UNITS_QUERY 0\n"
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"#endif\n\n"
argument_list|)
expr_stmt|;
comment|/* Interface itself: */
name|printf
argument_list|(
literal|"/* Internal insn code number used by automata.  */\n"
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"extern int internal_dfa_insn_code (rtx);\n\n"
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"/* Insn latency time defined in define_insn_reservation. */\n"
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"extern int insn_default_latency (rtx);\n\n"
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"/* Return nonzero if there is a bypass for given insn\n"
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"   which is a data producer.  */\n"
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"extern int bypass_p (rtx);\n\n"
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"/* Insn latency time on data consumed by the 2nd insn.\n"
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"   Use the function if bypass_p returns nonzero for\n"
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"   the 1st insn. */\n"
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"extern int insn_latency (rtx, rtx);\n\n"
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"\n#if AUTOMATON_ALTS\n"
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"/* The following function returns number of alternative\n"
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"   reservations of given insn.  It may be used for better\n"
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"   insns scheduling heuristics. */\n"
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"extern int insn_alts (rtx);\n\n"
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"#endif\n\n"
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"/* Maximal possible number of insns waiting results being\n"
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"   produced by insns whose execution is not finished. */\n"
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"extern const int max_insn_queue_index;\n\n"
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"/* Pointer to data describing current state of DFA.  */\n"
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"typedef void *state_t;\n\n"
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"/* Size of the data in bytes.  */\n"
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"extern int state_size (void);\n\n"
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"/* Initiate given DFA state, i.e. Set up the state\n"
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"   as all functional units were not reserved.  */\n"
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"extern void state_reset (state_t);\n"
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"/* The following function returns negative value if given\n"
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"   insn can be issued in processor state described by given\n"
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"   DFA state.  In this case, the DFA state is changed to\n"
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"   reflect the current and future reservations by given\n"
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"   insn.  Otherwise the function returns minimal time\n"
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"   delay to issue the insn.  This delay may be zero\n"
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"   for superscalar or VLIW processors.  If the second\n"
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"   parameter is NULL the function changes given DFA state\n"
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"   as new processor cycle started.  */\n"
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"extern int state_transition (state_t, rtx);\n"
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"\n#if AUTOMATON_STATE_ALTS\n"
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"/* The following function returns number of possible\n"
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"   alternative reservations of given insn in given\n"
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"   DFA state.  It may be used for better insns scheduling\n"
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"   heuristics.  By default the function is defined if\n"
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"   macro AUTOMATON_STATE_ALTS is defined because its\n"
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"   implementation may require much memory.  */\n"
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"extern int state_alts (state_t, rtx);\n"
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"#endif\n\n"
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"extern int min_issue_delay (state_t, rtx);\n"
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"/* The following function returns nonzero if no one insn\n"
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"   can be issued in current DFA state. */\n"
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"extern int state_dead_lock_p (state_t);\n"
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"/* The function returns minimal delay of issue of the 2nd\n"
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"   insn after issuing the 1st insn in given DFA state.\n"
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"   The 1st insn should be issued in given state (i.e.\n"
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"    state_transition should return negative value for\n"
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"    the insn and the state).  Data dependencies between\n"
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"    the insns are ignored by the function.  */\n"
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"extern int min_insn_conflict_delay (state_t, rtx, rtx);\n"
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"/* The following function outputs reservations for given\n"
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"   insn as they are described in the corresponding\n"
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"   define_insn_reservation.  */\n"
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"extern void print_reservation (FILE *, rtx);\n"
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"\n#if CPU_UNITS_QUERY\n"
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"/* The following function returns code of functional unit\n"
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"   with given name (see define_cpu_unit). */\n"
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"extern int get_cpu_unit_code (const char *);\n"
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"/* The following function returns nonzero if functional\n"
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"   unit with given code is currently reserved in given\n"
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"   DFA state.  */\n"
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"extern int cpu_unit_reservation_p (state_t, int);\n"
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"#endif\n\n"
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"/* Clean insn code cache.  It should be called if there\n"
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"   is a chance that condition value in a\n"
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"   define_insn_reservation will be changed after\n"
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"   last call of dfa_start.  */\n"
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"extern void dfa_clean_insn_cache (void);\n\n"
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"extern void dfa_clear_single_insn_cache (rtx);\n\n"
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"/* Initiate and finish work with DFA.  They should be\n"
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"   called as the first and the last interface\n"
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"   functions.  */\n"
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"extern void dfa_start (void);\n"
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"extern void dfa_finish (void);\n"
argument_list|)
expr_stmt|;
block|}
else|else
block|{
comment|/* Otherwise we do no scheduling, but we need these typedefs 	 in order to avoid uglifying other code with more ifdefs.  */
name|printf
argument_list|(
literal|"typedef void *state_t;\n\n"
argument_list|)
expr_stmt|;
block|}
comment|/* Output flag masks for use by reorg.       Flags are used to hold branch direction and prediction information      for use by eligible_for_...  */
name|printf
argument_list|(
literal|"\n#define ATTR_FLAG_forward\t0x1\n"
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"#define ATTR_FLAG_backward\t0x2\n"
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"#define ATTR_FLAG_likely\t0x4\n"
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"#define ATTR_FLAG_very_likely\t0x8\n"
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"#define ATTR_FLAG_unlikely\t0x10\n"
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"#define ATTR_FLAG_very_unlikely\t0x20\n"
argument_list|)
expr_stmt|;
name|puts
argument_list|(
literal|"\n#endif /* GCC_INSN_ATTR_H */"
argument_list|)
expr_stmt|;
if|if
condition|(
name|ferror
argument_list|(
name|stdout
argument_list|)
operator|||
name|fflush
argument_list|(
name|stdout
argument_list|)
operator|||
name|fclose
argument_list|(
name|stdout
argument_list|)
condition|)
return|return
name|FATAL_EXIT_CODE
return|;
return|return
name|SUCCESS_EXIT_CODE
return|;
block|}
end_function

end_unit

