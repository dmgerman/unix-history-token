begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Definitions for values of C expressions, for GDB.    Copyright (C) 1986, 1987, 1989 Free Software Foundation, Inc.  This file is part of GDB.  GDB is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 1, or (at your option) any later version.  GDB is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with GDB; see the file COPYING.  If not, write to the Free Software Foundation, 675 Mass Ave, Cambridge, MA 02139, USA.  */
end_comment

begin_comment
comment|/*  * The structure which defines the type of a value.  It should never  * be possible for a program lval value to survive over a call to the inferior  * (ie to be put into the history list or an internal variable).  */
end_comment

begin_enum
enum|enum
name|lval_type
block|{
comment|/* Not an lval.  */
name|not_lval
block|,
comment|/* In memory.  Could be a saved register.  */
name|lval_memory
block|,
comment|/* In a register.  */
name|lval_register
block|,
comment|/* In a gdb internal variable.  */
name|lval_internalvar
block|,
comment|/* Part of a gdb internal variable (structure field).  */
name|lval_internalvar_component
block|,
comment|/* In a register series in a frame not the current one, which may have been      partially saved or saved in different places (otherwise would be      lval_register or lval_memory).  */
name|lval_reg_frame_relative
block|, }
enum|;
end_enum

begin_struct
struct|struct
name|value
block|{
comment|/* Type of value; either not an lval, or one of the various        different possible kinds of lval.  */
name|enum
name|lval_type
name|lval
decl_stmt|;
comment|/* Location of value (if lval).  */
union|union
block|{
comment|/* Address in inferior or byte of registers structure.  */
name|CORE_ADDR
name|address
decl_stmt|;
comment|/* Pointer to interrnal variable.  */
name|struct
name|internalvar
modifier|*
name|internalvar
decl_stmt|;
comment|/* Number of register.  Only used with 	   lval_reg_frame_relative.  */
name|int
name|regnum
decl_stmt|;
block|}
name|location
union|;
comment|/* Describes offset of a value within lval a structure in bytes.  */
name|int
name|offset
decl_stmt|;
comment|/* Only used for bitfields; number of bits contained in them.  */
name|int
name|bitsize
decl_stmt|;
comment|/* Only used for bitfields; position of start of field.  */
name|int
name|bitpos
decl_stmt|;
comment|/* Frame value is relative to.  In practice, this address is only        used if the value is stored in several registers in other than        the current frame, and these registers have not all been saved        at the same place in memory.  This will be described in the        lval enum above as "lval_reg_frame_relative".  */
name|CORE_ADDR
name|frame_addr
decl_stmt|;
comment|/* Type of the value.  */
name|struct
name|type
modifier|*
name|type
decl_stmt|;
comment|/* Values are stored in a chain, so that they can be deleted        easily over calls to the inferior.  Values assigned to internal        variables or put into the value history are taken off this        list.  */
name|struct
name|value
modifier|*
name|next
decl_stmt|;
comment|/* If an lval is forced to repeat, a new value is created with        these fields set.  The new value is not an lval.  */
name|short
name|repeated
decl_stmt|;
name|short
name|repetitions
decl_stmt|;
comment|/* Register number if the value is from a register.  Is not kept        if you take a field of a structure that is stored in a        register.  Shouldn't it be?  */
name|short
name|regno
decl_stmt|;
comment|/* Actual contents of the value.  For use of this value; setting        it uses the stuff above.  */
name|long
name|contents
index|[
literal|1
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|value
modifier|*
name|value
typedef|;
end_typedef

begin_define
define|#
directive|define
name|VALUE_TYPE
parameter_list|(
name|val
parameter_list|)
value|(val)->type
end_define

begin_define
define|#
directive|define
name|VALUE_CONTENTS
parameter_list|(
name|val
parameter_list|)
value|((char *) (val)->contents)
end_define

begin_define
define|#
directive|define
name|VALUE_LVAL
parameter_list|(
name|val
parameter_list|)
value|(val)->lval
end_define

begin_define
define|#
directive|define
name|VALUE_ADDRESS
parameter_list|(
name|val
parameter_list|)
value|(val)->location.address
end_define

begin_define
define|#
directive|define
name|VALUE_INTERNALVAR
parameter_list|(
name|val
parameter_list|)
value|(val)->location.internalvar
end_define

begin_define
define|#
directive|define
name|VALUE_FRAME_REGNUM
parameter_list|(
name|val
parameter_list|)
value|((val)->location.regnum)
end_define

begin_define
define|#
directive|define
name|VALUE_FRAME
parameter_list|(
name|val
parameter_list|)
value|((val)->frame_addr)
end_define

begin_define
define|#
directive|define
name|VALUE_OFFSET
parameter_list|(
name|val
parameter_list|)
value|(val)->offset
end_define

begin_define
define|#
directive|define
name|VALUE_BITSIZE
parameter_list|(
name|val
parameter_list|)
value|(val)->bitsize
end_define

begin_define
define|#
directive|define
name|VALUE_BITPOS
parameter_list|(
name|val
parameter_list|)
value|(val)->bitpos
end_define

begin_define
define|#
directive|define
name|VALUE_NEXT
parameter_list|(
name|val
parameter_list|)
value|(val)->next
end_define

begin_define
define|#
directive|define
name|VALUE_REPEATED
parameter_list|(
name|val
parameter_list|)
value|(val)->repeated
end_define

begin_define
define|#
directive|define
name|VALUE_REPETITIONS
parameter_list|(
name|val
parameter_list|)
value|(val)->repetitions
end_define

begin_define
define|#
directive|define
name|VALUE_REGNO
parameter_list|(
name|val
parameter_list|)
value|(val)->regno
end_define

begin_comment
comment|/* If ARG is an array, convert it to a pointer.    If ARG is an enum, convert it to an integer.     References are dereferenced.  */
end_comment

begin_define
define|#
directive|define
name|COERCE_ARRAY
parameter_list|(
name|arg
parameter_list|)
define|\
value|{ if (TYPE_CODE ( VALUE_TYPE (arg)) == TYPE_CODE_REF)			\     arg = value_ind (arg);						\   if (VALUE_REPEATED (arg)						\       || TYPE_CODE (VALUE_TYPE (arg)) == TYPE_CODE_ARRAY)		\     arg = value_coerce_array (arg);					\   if (TYPE_CODE (VALUE_TYPE (arg)) == TYPE_CODE_ENUM)			\     arg = value_cast (builtin_type_unsigned_int, arg);			\ }
end_define

begin_comment
comment|/* If ARG is an enum, convert it to an integer.  */
end_comment

begin_define
define|#
directive|define
name|COERCE_ENUM
parameter_list|(
name|arg
parameter_list|)
define|\
value|{ if (TYPE_CODE ( VALUE_TYPE (arg)) == TYPE_CODE_REF)			\     arg = value_ind (arg);						\   if (TYPE_CODE (VALUE_TYPE (arg)) == TYPE_CODE_ENUM)			\     arg = value_cast (builtin_type_unsigned_int, arg);			\ }
end_define

begin_comment
comment|/* Internal variables (variables for convenience of use of debugger)    are recorded as a chain of these structures.  */
end_comment

begin_struct
struct|struct
name|internalvar
block|{
name|struct
name|internalvar
modifier|*
name|next
decl_stmt|;
name|char
modifier|*
name|name
decl_stmt|;
name|value
name|value
decl_stmt|;
block|}
struct|;
end_struct

begin_escape
end_escape

begin_function_decl
name|LONGEST
name|value_as_long
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|double
name|value_as_double
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|LONGEST
name|unpack_long
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|double
name|unpack_double
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|long
name|unpack_field_as_long
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|value
name|value_from_long
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|value
name|value_from_double
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|value
name|value_at
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|value
name|value_from_register
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|value
name|value_of_variable
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|value
name|value_of_register
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|value
name|read_var_value
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|value
name|locate_var_value
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|value
name|allocate_value
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|value
name|allocate_repeat_value
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|value
name|value_string
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|value
name|value_binop
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|value
name|value_add
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|value
name|value_sub
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|value
name|value_coerce_array
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|value
name|value_ind
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|value
name|value_addr
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|value
name|value_assign
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|value
name|value_neg
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|value
name|value_lognot
parameter_list|()
function_decl|;
end_function_decl

begin_decl_stmt
name|value
name|value_struct_elt
argument_list|()
decl_stmt|,
name|value_struct_elt_for_address
argument_list|()
decl_stmt|;
end_decl_stmt

begin_function_decl
name|value
name|value_field
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|value
name|value_cast
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|value
name|value_zero
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|value
name|value_repeat
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|value
name|value_subscript
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|value
name|call_function
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|value
name|value_being_returned
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|using_struct_return
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|value
name|evaluate_expression
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|value
name|evaluate_type
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|value
name|parse_and_eval
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|value
name|parse_to_comma_and_eval
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|value
name|access_value_history
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|value
name|value_of_internalvar
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|internalvar
modifier|*
name|lookup_internalvar
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|value_equal
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|value_less
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|value_zerop
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* C++ */
end_comment

begin_function_decl
name|value
name|value_of_this
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|value
name|value_static_field
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|value
name|value_x_binop
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|value
name|value_x_unop
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|binop_user_defined_p
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|unop_user_defined_p
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|read_register_bytes
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|modify_field
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|type_print
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|type_print_1
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* Possibilities for prettyprint parameters to routines which print    things.  */
end_comment

begin_enum
enum|enum
name|val_prettyprint
block|{
name|Val_no_prettyprint
init|=
literal|0
block|,
name|Val_prettyprint
block|,
comment|/* Use the default setting which the user has specified.  */
name|Val_pretty_default
block|}
enum|;
end_enum

end_unit

