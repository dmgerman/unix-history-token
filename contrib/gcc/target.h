begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Data structure definitions for a generic GCC target.    Copyright (C) 2001 Free Software Foundation, Inc.  This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2, or (at your option) any later version.  This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with this program; if not, write to the Free Software Foundation, 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.   In other words, you are welcome to use, share and improve this program.  You are forbidden to forbid anyone else to use, share and improve  what you give them.   Help stamp out software-hoarding!  */
end_comment

begin_comment
comment|/* This file contains a data structure that describes a GCC target.    At present it is incomplete, but in future it should grow to    contain most or all target machine and target O/S specific    information.     This structure has its initializer declared in target-def.h in the    form of large macro TARGET_INITIALIZER that expands to many smaller    macros.     The smaller macros each initialize one component of the structure,    and each has a default.  Each target should have a file that    includes target.h and target-def.h, and overrides any inappropriate    defaults by undefining the relevant macro and defining a suitable    replacement.  That file should then contain the definition of    "targetm" like so:     struct gcc_target targetm = TARGET_INITIALIZER;     Doing things this way allows us to bring together everything that    defines a GCC target.  By supplying a default that is appropriate    to most targets, we can easily add new items without needing to    edit dozens of target configuration files.  It should also allow us    to gradually reduce the amount of conditional compilation that is    scattered throughout GCC.  */
end_comment

begin_struct
struct|struct
name|gcc_target
block|{
comment|/* Functions that output assembler for the target.  */
struct|struct
name|asm_out
block|{
comment|/* Opening and closing parentheses for asm expression grouping.  */
specifier|const
name|char
modifier|*
name|open_paren
decl_stmt|,
modifier|*
name|close_paren
decl_stmt|;
comment|/* Assembler instructions for creating various kinds of integer object.  */
specifier|const
name|char
modifier|*
name|byte_op
decl_stmt|;
struct|struct
name|asm_int_op
block|{
specifier|const
name|char
modifier|*
name|hi
decl_stmt|;
specifier|const
name|char
modifier|*
name|si
decl_stmt|;
specifier|const
name|char
modifier|*
name|di
decl_stmt|;
specifier|const
name|char
modifier|*
name|ti
decl_stmt|;
block|}
name|aligned_op
struct|,
name|unaligned_op
struct|;
comment|/* Try to output the assembler code for an integer object whose        value is given by X.  SIZE is the size of the object in bytes and        ALIGNED_P indicates whether it is aligned.  Return true if        successful.  Only handles cases for which BYTE_OP, ALIGNED_OP        and UNALIGNED_OP are NULL.  */
name|bool
argument_list|(
argument|* integer
argument_list|)
name|PARAMS
argument_list|(
operator|(
name|rtx
name|x
operator|,
name|unsigned
name|int
name|size
operator|,
name|int
name|aligned_p
operator|)
argument_list|)
expr_stmt|;
comment|/* Output the assembler code for entry to a function.  */
name|void
argument_list|(
argument|* function_prologue
argument_list|)
name|PARAMS
argument_list|(
operator|(
name|FILE
operator|*
operator|,
name|HOST_WIDE_INT
operator|)
argument_list|)
expr_stmt|;
comment|/* Output the assembler code for end of prologue.  */
name|void
argument_list|(
argument|* function_end_prologue
argument_list|)
name|PARAMS
argument_list|(
operator|(
name|FILE
operator|*
operator|)
argument_list|)
expr_stmt|;
comment|/* Output the assembler code for start of epilogue.  */
name|void
argument_list|(
argument|* function_begin_epilogue
argument_list|)
name|PARAMS
argument_list|(
operator|(
name|FILE
operator|*
operator|)
argument_list|)
expr_stmt|;
comment|/* Output the assembler code for function exit.  */
name|void
argument_list|(
argument|* function_epilogue
argument_list|)
name|PARAMS
argument_list|(
operator|(
name|FILE
operator|*
operator|,
name|HOST_WIDE_INT
operator|)
argument_list|)
expr_stmt|;
comment|/* Switch to an arbitrary section NAME with attributes as        specified by FLAGS.  */
name|void
argument_list|(
argument|* named_section
argument_list|)
name|PARAMS
argument_list|(
operator|(
specifier|const
name|char
operator|*
operator|,
name|unsigned
name|int
operator|)
argument_list|)
expr_stmt|;
comment|/* Switch to the section that holds the exception table.  */
name|void
argument_list|(
argument|* exception_section
argument_list|)
name|PARAMS
argument_list|(
operator|(
name|void
operator|)
argument_list|)
expr_stmt|;
comment|/* Switch to the section that holds the exception frames.  */
name|void
argument_list|(
argument|* eh_frame_section
argument_list|)
name|PARAMS
argument_list|(
operator|(
name|void
operator|)
argument_list|)
expr_stmt|;
comment|/* Output a constructor for a symbol with a given priority.  */
name|void
argument_list|(
argument|* constructor
argument_list|)
name|PARAMS
argument_list|(
operator|(
name|rtx
operator|,
name|int
operator|)
argument_list|)
expr_stmt|;
comment|/* Output a destructor for a symbol with a given priority.  */
name|void
argument_list|(
argument|* destructor
argument_list|)
name|PARAMS
argument_list|(
operator|(
name|rtx
operator|,
name|int
operator|)
argument_list|)
expr_stmt|;
block|}
name|asm_out
struct|;
comment|/* Functions relating to instruction scheduling.  */
struct|struct
name|sched
block|{
comment|/* Given the current cost, COST, of an insn, INSN, calculate and        return a new cost based on its relationship to DEP_INSN through        the dependence LINK.  The default is to make no adjustment.  */
name|int
argument_list|(
argument|* adjust_cost
argument_list|)
name|PARAMS
argument_list|(
operator|(
name|rtx
name|insn
operator|,
name|rtx
name|link
operator|,
name|rtx
name|def_insn
operator|,
name|int
name|cost
operator|)
argument_list|)
expr_stmt|;
comment|/* Adjust the priority of an insn as you see fit.  Returns the new        priority.  */
name|int
argument_list|(
argument|* adjust_priority
argument_list|)
name|PARAMS
argument_list|(
operator|(
name|rtx
operator|,
name|int
operator|)
argument_list|)
expr_stmt|;
comment|/* Function which returns the maximum number of insns that can be        scheduled in the same machine cycle.  This must be constant        over an entire compilation.  The default is 1.  */
name|int
argument_list|(
argument|* issue_rate
argument_list|)
name|PARAMS
argument_list|(
operator|(
name|void
operator|)
argument_list|)
expr_stmt|;
comment|/* Calculate how much this insn affects how many more insns we        can emit this cycle.  Default is they all cost the same.  */
name|int
argument_list|(
argument|* variable_issue
argument_list|)
name|PARAMS
argument_list|(
operator|(
name|FILE
operator|*
operator|,
name|int
operator|,
name|rtx
operator|,
name|int
operator|)
argument_list|)
expr_stmt|;
comment|/* Initialize machine-dependent scheduling code.  */
name|void
argument_list|(
argument|* md_init
argument_list|)
name|PARAMS
argument_list|(
operator|(
name|FILE
operator|*
operator|,
name|int
operator|,
name|int
operator|)
argument_list|)
expr_stmt|;
comment|/* Finalize machine-dependent scheduling code.  */
name|void
argument_list|(
argument|* md_finish
argument_list|)
name|PARAMS
argument_list|(
operator|(
name|FILE
operator|*
operator|,
name|int
operator|)
argument_list|)
expr_stmt|;
comment|/* Reorder insns in a machine-dependent fashion, in two different        places.  Default does nothing.  */
name|int
argument_list|(
argument|* reorder
argument_list|)
name|PARAMS
argument_list|(
operator|(
name|FILE
operator|*
operator|,
name|int
operator|,
name|rtx
operator|*
operator|,
name|int
operator|*
operator|,
name|int
operator|)
argument_list|)
expr_stmt|;
name|int
argument_list|(
argument|* reorder2
argument_list|)
name|PARAMS
argument_list|(
operator|(
name|FILE
operator|*
operator|,
name|int
operator|,
name|rtx
operator|*
operator|,
name|int
operator|*
operator|,
name|int
operator|)
argument_list|)
expr_stmt|;
comment|/* cycle_display is a pointer to a function which can emit        data into the assembly stream about the current cycle.        Arguments are CLOCK, the data to emit, and LAST, the last        insn in the new chain we're building.  Returns a new LAST.        The default is to do nothing.  */
name|rtx
argument_list|(
argument|* cycle_display
argument_list|)
name|PARAMS
argument_list|(
operator|(
name|int
name|clock
operator|,
name|rtx
name|last
operator|)
argument_list|)
expr_stmt|;
block|}
name|sched
struct|;
comment|/* Given two decls, merge their attributes and return the result.  */
name|tree
argument_list|(
argument|* merge_decl_attributes
argument_list|)
name|PARAMS
argument_list|(
operator|(
name|tree
operator|,
name|tree
operator|)
argument_list|)
expr_stmt|;
comment|/* Given two types, merge their attributes and return the result.  */
name|tree
argument_list|(
argument|* merge_type_attributes
argument_list|)
name|PARAMS
argument_list|(
operator|(
name|tree
operator|,
name|tree
operator|)
argument_list|)
expr_stmt|;
comment|/* Table of machine attributes and functions to handle them.  */
specifier|const
name|struct
name|attribute_spec
modifier|*
name|attribute_table
decl_stmt|;
comment|/* Return zero if the attributes on TYPE1 and TYPE2 are incompatible,      one if they are compatible and two if they are nearly compatible      (which causes a warning to be generated).  */
name|int
argument_list|(
argument|* comp_type_attributes
argument_list|)
name|PARAMS
argument_list|(
operator|(
name|tree
name|type1
operator|,
name|tree
name|type2
operator|)
argument_list|)
expr_stmt|;
comment|/* Assign default attributes to the newly defined TYPE.  */
name|void
argument_list|(
argument|* set_default_type_attributes
argument_list|)
name|PARAMS
argument_list|(
operator|(
name|tree
name|type
operator|)
argument_list|)
expr_stmt|;
comment|/* Insert attributes on the newly created DECL.  */
name|void
argument_list|(
argument|* insert_attributes
argument_list|)
name|PARAMS
argument_list|(
operator|(
name|tree
name|decl
operator|,
name|tree
operator|*
name|attributes
operator|)
argument_list|)
expr_stmt|;
comment|/* Return true if FNDECL (which has at least one machine attribute)      can be inlined despite its machine attributes, false otherwise.  */
name|bool
argument_list|(
argument|* function_attribute_inlinable_p
argument_list|)
name|PARAMS
argument_list|(
operator|(
name|tree
name|fndecl
operator|)
argument_list|)
expr_stmt|;
comment|/* Set up target-specific built-in functions.  */
name|void
argument_list|(
argument|* init_builtins
argument_list|)
name|PARAMS
argument_list|(
operator|(
name|void
operator|)
argument_list|)
expr_stmt|;
comment|/* Expand a target-specific builtin.  */
name|rtx
argument_list|(
argument|* expand_builtin
argument_list|)
name|PARAMS
argument_list|(
operator|(
name|tree
name|exp
operator|,
name|rtx
name|target
operator|,
name|rtx
name|subtarget
operator|,
expr|enum
name|machine_mode
name|mode
operator|,
name|int
name|ignore
operator|)
argument_list|)
expr_stmt|;
comment|/* Given a decl, a section name, and whether the decl initializer      has relocs, choose attributes for the section.  */
comment|/* ??? Should be merged with SELECT_SECTION and UNIQUE_SECTION.  */
name|unsigned
name|int
argument_list|(
operator|*
name|section_type_flags
argument_list|)
name|PARAMS
argument_list|(
operator|(
name|tree
operator|,
specifier|const
name|char
operator|*
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
comment|/* True if arbitrary sections are supported.  */
name|bool
name|have_named_sections
decl_stmt|;
comment|/* True if "native" constructors and destructors are supported,      false if we're using collect2 for the job.  */
name|bool
name|have_ctors_dtors
decl_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
specifier|extern
name|struct
name|gcc_target
name|targetm
decl_stmt|;
end_decl_stmt

end_unit

