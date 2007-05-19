begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Declarations for interface to insn recognizer and insn-output.c.    Copyright (C) 1987, 1996, 1997, 1998, 1999, 2000, 2001, 2003, 2004, 2005    Free Software Foundation, Inc.  This file is part of GCC.  GCC is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2, or (at your option) any later version.  GCC is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with GCC; see the file COPYING.  If not, write to the Free Software Foundation, 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301, USA.  */
end_comment

begin_comment
comment|/* Random number that should be large enough for all purposes.  */
end_comment

begin_define
define|#
directive|define
name|MAX_RECOG_ALTERNATIVES
value|30
end_define

begin_comment
comment|/* Types of operands.  */
end_comment

begin_enum
enum|enum
name|op_type
block|{
name|OP_IN
block|,
name|OP_OUT
block|,
name|OP_INOUT
block|}
enum|;
end_enum

begin_struct
struct|struct
name|operand_alternative
block|{
comment|/* Pointer to the beginning of the constraint string for this alternative,      for easier access by alternative number.  */
specifier|const
name|char
modifier|*
name|constraint
decl_stmt|;
comment|/* The register class valid for this alternative (possibly NO_REGS).  */
name|enum
name|reg_class
name|cl
decl_stmt|;
comment|/* "Badness" of this alternative, computed from number of '?' and '!'      characters in the constraint string.  */
name|unsigned
name|int
name|reject
decl_stmt|;
comment|/* -1 if no matching constraint was found, or an operand number.  */
name|int
name|matches
decl_stmt|;
comment|/* The same information, but reversed: -1 if this operand is not      matched by any other, or the operand number of the operand that      matches this one.  */
name|int
name|matched
decl_stmt|;
comment|/* Nonzero if '&' was found in the constraint string.  */
name|unsigned
name|int
name|earlyclobber
range|:
literal|1
decl_stmt|;
comment|/* Nonzero if 'm' was found in the constraint string.  */
name|unsigned
name|int
name|memory_ok
range|:
literal|1
decl_stmt|;
comment|/* Nonzero if 'o' was found in the constraint string.  */
name|unsigned
name|int
name|offmem_ok
range|:
literal|1
decl_stmt|;
comment|/* Nonzero if 'V' was found in the constraint string.  */
name|unsigned
name|int
name|nonoffmem_ok
range|:
literal|1
decl_stmt|;
comment|/* Nonzero if '<' was found in the constraint string.  */
name|unsigned
name|int
name|decmem_ok
range|:
literal|1
decl_stmt|;
comment|/* Nonzero if '>' was found in the constraint string.  */
name|unsigned
name|int
name|incmem_ok
range|:
literal|1
decl_stmt|;
comment|/* Nonzero if 'p' was found in the constraint string.  */
name|unsigned
name|int
name|is_address
range|:
literal|1
decl_stmt|;
comment|/* Nonzero if 'X' was found in the constraint string, or if the constraint      string for this alternative was empty.  */
name|unsigned
name|int
name|anything_ok
range|:
literal|1
decl_stmt|;
block|}
struct|;
end_struct

begin_function_decl
specifier|extern
name|void
name|init_recog
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|init_recog_no_volatile
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|check_asm_operands
parameter_list|(
name|rtx
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|asm_operand_ok
parameter_list|(
name|rtx
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|validate_change
parameter_list|(
name|rtx
parameter_list|,
name|rtx
modifier|*
parameter_list|,
name|rtx
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|insn_invalid_p
parameter_list|(
name|rtx
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|verify_changes
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|confirm_change_group
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|apply_change_group
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|num_validated_changes
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|cancel_changes
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|constrain_operands
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|constrain_operands_cached
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|memory_address_p
parameter_list|(
name|enum
name|machine_mode
parameter_list|,
name|rtx
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|strict_memory_address_p
parameter_list|(
name|enum
name|machine_mode
parameter_list|,
name|rtx
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|validate_replace_rtx
parameter_list|(
name|rtx
parameter_list|,
name|rtx
parameter_list|,
name|rtx
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|validate_replace_rtx_group
parameter_list|(
name|rtx
parameter_list|,
name|rtx
parameter_list|,
name|rtx
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|validate_replace_src_group
parameter_list|(
name|rtx
parameter_list|,
name|rtx
parameter_list|,
name|rtx
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|bool
name|validate_simplify_insn
parameter_list|(
name|rtx
name|insn
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|num_changes_pending
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_cc0
end_ifdef

begin_function_decl
specifier|extern
name|int
name|next_insn_tests_no_inequality
parameter_list|(
name|rtx
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
name|reg_fits_class_p
parameter_list|(
name|rtx
parameter_list|,
name|enum
name|reg_class
parameter_list|,
name|int
parameter_list|,
name|enum
name|machine_mode
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|rtx
modifier|*
name|find_single_use
parameter_list|(
name|rtx
parameter_list|,
name|rtx
parameter_list|,
name|rtx
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|offsettable_memref_p
parameter_list|(
name|rtx
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|offsettable_nonstrict_memref_p
parameter_list|(
name|rtx
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|offsettable_address_p
parameter_list|(
name|int
parameter_list|,
name|enum
name|machine_mode
parameter_list|,
name|rtx
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|mode_dependent_address_p
parameter_list|(
name|rtx
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|recog
parameter_list|(
name|rtx
parameter_list|,
name|rtx
parameter_list|,
name|int
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_ifndef
ifndef|#
directive|ifndef
name|GENERATOR_FILE
end_ifndef

begin_function_decl
specifier|static
specifier|inline
name|int
name|recog_memoized
parameter_list|(
name|rtx
name|insn
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_function_decl
specifier|extern
name|void
name|add_clobbers
parameter_list|(
name|rtx
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|added_clobbers_hard_reg_p
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|insn_extract
parameter_list|(
name|rtx
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|extract_insn
parameter_list|(
name|rtx
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|extract_constrain_insn_cached
parameter_list|(
name|rtx
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|extract_insn_cached
parameter_list|(
name|rtx
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|preprocess_constraints
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|rtx
name|peep2_next_insn
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|peep2_regno_dead_p
parameter_list|(
name|int
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|peep2_reg_dead_p
parameter_list|(
name|int
parameter_list|,
name|rtx
parameter_list|)
function_decl|;
end_function_decl

begin_ifdef
ifdef|#
directive|ifdef
name|CLEAR_HARD_REG_SET
end_ifdef

begin_function_decl
specifier|extern
name|rtx
name|peep2_find_free_register
parameter_list|(
name|int
parameter_list|,
name|int
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
name|enum
name|machine_mode
parameter_list|,
name|HARD_REG_SET
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
name|rtx
name|peephole2_insns
parameter_list|(
name|rtx
parameter_list|,
name|rtx
parameter_list|,
name|int
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|store_data_bypass_p
parameter_list|(
name|rtx
parameter_list|,
name|rtx
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|if_test_bypass_p
parameter_list|(
name|rtx
parameter_list|,
name|rtx
parameter_list|)
function_decl|;
end_function_decl

begin_ifndef
ifndef|#
directive|ifndef
name|GENERATOR_FILE
end_ifndef

begin_comment
comment|/* Try recognizing the instruction INSN,    and return the code number that results.    Remember the code so that repeated calls do not    need to spend the time for actual rerecognition.     This function is the normal interface to instruction recognition.    The automatically-generated function `recog' is normally called    through this one.  */
end_comment

begin_function
specifier|static
specifier|inline
name|int
name|recog_memoized
parameter_list|(
name|rtx
name|insn
parameter_list|)
block|{
if|if
condition|(
name|INSN_CODE
argument_list|(
name|insn
argument_list|)
operator|<
literal|0
condition|)
name|INSN_CODE
argument_list|(
name|insn
argument_list|)
operator|=
name|recog
argument_list|(
name|PATTERN
argument_list|(
name|insn
argument_list|)
argument_list|,
name|insn
argument_list|,
literal|0
argument_list|)
expr_stmt|;
return|return
name|INSN_CODE
argument_list|(
name|insn
argument_list|)
return|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Nonzero means volatile operands are recognized.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|volatile_ok
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Set by constrain_operands to the number of the alternative that    matched.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|which_alternative
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* The following vectors hold the results from insn_extract.  */
end_comment

begin_struct
struct|struct
name|recog_data
block|{
comment|/* It is very tempting to make the 5 operand related arrays into a      structure and index on that.  However, to be source compatible      with all of the existing md file insn constraints and output      templates, we need `operand' as a flat array.  Without that      member, making an array for the rest seems pointless.  */
comment|/* Gives value of operand N.  */
name|rtx
name|operand
index|[
name|MAX_RECOG_OPERANDS
index|]
decl_stmt|;
comment|/* Gives location where operand N was found.  */
name|rtx
modifier|*
name|operand_loc
index|[
name|MAX_RECOG_OPERANDS
index|]
decl_stmt|;
comment|/* Gives the constraint string for operand N.  */
specifier|const
name|char
modifier|*
name|constraints
index|[
name|MAX_RECOG_OPERANDS
index|]
decl_stmt|;
comment|/* Gives the mode of operand N.  */
name|enum
name|machine_mode
name|operand_mode
index|[
name|MAX_RECOG_OPERANDS
index|]
decl_stmt|;
comment|/* Gives the type (in, out, inout) for operand N.  */
name|enum
name|op_type
name|operand_type
index|[
name|MAX_RECOG_OPERANDS
index|]
decl_stmt|;
comment|/* Gives location where the Nth duplicate-appearance of an operand      was found.  This is something that matched MATCH_DUP.  */
name|rtx
modifier|*
name|dup_loc
index|[
name|MAX_DUP_OPERANDS
index|]
decl_stmt|;
comment|/* Gives the operand number that was duplicated in the Nth      duplicate-appearance of an operand.  */
name|char
name|dup_num
index|[
name|MAX_DUP_OPERANDS
index|]
decl_stmt|;
comment|/* ??? Note that these are `char' instead of `unsigned char' to (try to)      avoid certain lossage from K&R C, wherein `unsigned char' default      promotes to `unsigned int' instead of `int' as in ISO C.  As of 1999,      the most common places to bootstrap from K&R C are SunOS and HPUX,      both of which have signed characters by default.  The only other      supported natives that have both K&R C and unsigned characters are      ROMP and Irix 3, and neither have been seen for a while, but do      continue to consider unsignedness when performing arithmetic inside      a comparison.  */
comment|/* The number of operands of the insn.  */
name|char
name|n_operands
decl_stmt|;
comment|/* The number of MATCH_DUPs in the insn.  */
name|char
name|n_dups
decl_stmt|;
comment|/* The number of alternatives in the constraints for the insn.  */
name|char
name|n_alternatives
decl_stmt|;
comment|/* In case we are caching, hold insn data was generated for.  */
name|rtx
name|insn
decl_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
specifier|extern
name|struct
name|recog_data
name|recog_data
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Contains a vector of operand_alternative structures for every operand.    Set up by preprocess_constraints.  */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|operand_alternative
name|recog_op_alt
index|[
name|MAX_RECOG_OPERANDS
index|]
index|[
name|MAX_RECOG_ALTERNATIVES
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* A table defined in insn-output.c that give information about    each insn-code value.  */
end_comment

begin_typedef
typedef|typedef
name|int
function_decl|(
modifier|*
name|insn_operand_predicate_fn
function_decl|)
parameter_list|(
name|rtx
parameter_list|,
name|enum
name|machine_mode
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
specifier|const
name|char
modifier|*
function_decl|(
modifier|*
name|insn_output_fn
function_decl|)
parameter_list|(
name|rtx
modifier|*
parameter_list|,
name|rtx
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|rtx
function_decl|(
modifier|*
name|insn_gen_fn
function_decl|)
parameter_list|(
name|rtx
parameter_list|,
modifier|...
parameter_list|)
function_decl|;
end_typedef

begin_struct
struct|struct
name|insn_operand_data
block|{
specifier|const
name|insn_operand_predicate_fn
name|predicate
decl_stmt|;
specifier|const
name|char
modifier|*
specifier|const
name|constraint
decl_stmt|;
name|ENUM_BITFIELD
argument_list|(
argument|machine_mode
argument_list|)
specifier|const
name|mode
operator|:
literal|16
expr_stmt|;
specifier|const
name|char
name|strict_low
decl_stmt|;
specifier|const
name|char
name|eliminable
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* Legal values for insn_data.output_format.  Indicate what type of data    is stored in insn_data.output.  */
end_comment

begin_define
define|#
directive|define
name|INSN_OUTPUT_FORMAT_NONE
value|0
end_define

begin_comment
comment|/* abort */
end_comment

begin_define
define|#
directive|define
name|INSN_OUTPUT_FORMAT_SINGLE
value|1
end_define

begin_comment
comment|/* const char * */
end_comment

begin_define
define|#
directive|define
name|INSN_OUTPUT_FORMAT_MULTI
value|2
end_define

begin_comment
comment|/* const char * const * */
end_comment

begin_define
define|#
directive|define
name|INSN_OUTPUT_FORMAT_FUNCTION
value|3
end_define

begin_comment
comment|/* const char * (*)(...) */
end_comment

begin_struct
struct|struct
name|insn_data
block|{
specifier|const
name|char
modifier|*
specifier|const
name|name
decl_stmt|;
if|#
directive|if
name|HAVE_DESIGNATED_INITIALIZERS
union|union
block|{
specifier|const
name|char
modifier|*
name|single
decl_stmt|;
specifier|const
name|char
modifier|*
specifier|const
modifier|*
name|multi
decl_stmt|;
name|insn_output_fn
name|function
decl_stmt|;
block|}
name|output
union|;
else|#
directive|else
struct|struct
block|{
specifier|const
name|char
modifier|*
name|single
decl_stmt|;
specifier|const
name|char
modifier|*
specifier|const
modifier|*
name|multi
decl_stmt|;
name|insn_output_fn
name|function
decl_stmt|;
block|}
name|output
struct|;
endif|#
directive|endif
specifier|const
name|insn_gen_fn
name|genfun
decl_stmt|;
specifier|const
name|struct
name|insn_operand_data
modifier|*
specifier|const
name|operand
decl_stmt|;
specifier|const
name|char
name|n_operands
decl_stmt|;
specifier|const
name|char
name|n_dups
decl_stmt|;
specifier|const
name|char
name|n_alternatives
decl_stmt|;
specifier|const
name|char
name|output_format
decl_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
specifier|extern
specifier|const
name|struct
name|insn_data
name|insn_data
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|peep2_current_count
decl_stmt|;
end_decl_stmt

end_unit

