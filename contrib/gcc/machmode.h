begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Machine mode definitions for GCC; included by rtl.h and tree.h.    Copyright (C) 1991, 1993, 1994, 1996, 1998, 1999, 2000, 2001, 2003    Free Software Foundation, Inc.  This file is part of GCC.  GCC is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2, or (at your option) any later version.  GCC is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with GCC; see the file COPYING.  If not, write to the Free Software Foundation, 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|HAVE_MACHINE_MODES
end_ifndef

begin_define
define|#
directive|define
name|HAVE_MACHINE_MODES
end_define

begin_comment
comment|/* Make an enum class that gives all the machine modes.  */
end_comment

begin_include
include|#
directive|include
file|"insn-modes.h"
end_include

begin_comment
comment|/* Get the name of mode MODE as a string.  */
end_comment

begin_decl_stmt
specifier|extern
specifier|const
name|char
modifier|*
specifier|const
name|mode_name
index|[
name|NUM_MACHINE_MODES
index|]
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|GET_MODE_NAME
parameter_list|(
name|MODE
parameter_list|)
value|mode_name[MODE]
end_define

begin_comment
comment|/* Mode classes.  */
end_comment

begin_include
include|#
directive|include
file|"mode-classes.def"
end_include

begin_define
define|#
directive|define
name|DEF_MODE_CLASS
parameter_list|(
name|M
parameter_list|)
value|M
end_define

begin_enum
enum|enum
name|mode_class
block|{
name|MODE_CLASSES
block|,
name|MAX_MODE_CLASS
block|}
enum|;
end_enum

begin_undef
undef|#
directive|undef
name|DEF_MODE_CLASS
end_undef

begin_undef
undef|#
directive|undef
name|MODE_CLASSES
end_undef

begin_comment
comment|/* Get the general kind of object that mode MODE represents    (integer, floating, complex, etc.)  */
end_comment

begin_decl_stmt
specifier|extern
specifier|const
name|unsigned
name|char
name|mode_class
index|[
name|NUM_MACHINE_MODES
index|]
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|GET_MODE_CLASS
parameter_list|(
name|MODE
parameter_list|)
value|mode_class[MODE]
end_define

begin_comment
comment|/* Nonzero if MODE is an integral mode.  */
end_comment

begin_define
define|#
directive|define
name|INTEGRAL_MODE_P
parameter_list|(
name|MODE
parameter_list|)
define|\
value|(GET_MODE_CLASS (MODE) == MODE_INT		\    || GET_MODE_CLASS (MODE) == MODE_PARTIAL_INT \    || GET_MODE_CLASS (MODE) == MODE_COMPLEX_INT \    || GET_MODE_CLASS (MODE) == MODE_VECTOR_INT)
end_define

begin_comment
comment|/* Nonzero if MODE is a floating-point mode.  */
end_comment

begin_define
define|#
directive|define
name|FLOAT_MODE_P
parameter_list|(
name|MODE
parameter_list|)
define|\
value|(GET_MODE_CLASS (MODE) == MODE_FLOAT	\    || GET_MODE_CLASS (MODE) == MODE_COMPLEX_FLOAT \    || GET_MODE_CLASS (MODE) == MODE_VECTOR_FLOAT)
end_define

begin_comment
comment|/* Nonzero if MODE is a complex mode.  */
end_comment

begin_define
define|#
directive|define
name|COMPLEX_MODE_P
parameter_list|(
name|MODE
parameter_list|)
define|\
value|(GET_MODE_CLASS (MODE) == MODE_COMPLEX_INT	\    || GET_MODE_CLASS (MODE) == MODE_COMPLEX_FLOAT)
end_define

begin_comment
comment|/* Nonzero if MODE is a vector mode.  */
end_comment

begin_define
define|#
directive|define
name|VECTOR_MODE_P
parameter_list|(
name|MODE
parameter_list|)
define|\
value|(GET_MODE_CLASS (MODE) == MODE_VECTOR_INT	\    || GET_MODE_CLASS (MODE) == MODE_VECTOR_FLOAT)
end_define

begin_comment
comment|/* Nonzero if MODE is a scalar integral mode.  */
end_comment

begin_define
define|#
directive|define
name|SCALAR_INT_MODE_P
parameter_list|(
name|MODE
parameter_list|)
define|\
value|(GET_MODE_CLASS (MODE) == MODE_INT		\    || GET_MODE_CLASS (MODE) == MODE_PARTIAL_INT)
end_define

begin_comment
comment|/* Nonzero if MODE is a scalar floating point mode.  */
end_comment

begin_define
define|#
directive|define
name|SCALAR_FLOAT_MODE_P
parameter_list|(
name|MODE
parameter_list|)
define|\
value|(GET_MODE_CLASS (MODE) == MODE_FLOAT)
end_define

begin_comment
comment|/* Get the size in bytes and bits of an object of mode MODE.  */
end_comment

begin_decl_stmt
specifier|extern
name|CONST_MODE_SIZE
name|unsigned
name|char
name|mode_size
index|[
name|NUM_MACHINE_MODES
index|]
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|GET_MODE_SIZE
parameter_list|(
name|MODE
parameter_list|)
value|((unsigned short) mode_size[MODE])
end_define

begin_define
define|#
directive|define
name|GET_MODE_BITSIZE
parameter_list|(
name|MODE
parameter_list|)
value|((unsigned short) (GET_MODE_SIZE (MODE) * BITS_PER_UNIT))
end_define

begin_comment
comment|/* Get the number of value bits of an object of mode MODE.  */
end_comment

begin_decl_stmt
specifier|extern
specifier|const
name|unsigned
name|short
name|mode_precision
index|[
name|NUM_MACHINE_MODES
index|]
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|GET_MODE_PRECISION
parameter_list|(
name|MODE
parameter_list|)
value|mode_precision[MODE]
end_define

begin_comment
comment|/* Get a bitmask containing 1 for all bits in a word    that fit within mode MODE.  */
end_comment

begin_decl_stmt
specifier|extern
specifier|const
name|unsigned
name|HOST_WIDE_INT
name|mode_mask_array
index|[
name|NUM_MACHINE_MODES
index|]
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|GET_MODE_MASK
parameter_list|(
name|MODE
parameter_list|)
value|mode_mask_array[MODE]
end_define

begin_comment
comment|/* Return the mode of the inner elements in a vector.  */
end_comment

begin_decl_stmt
specifier|extern
specifier|const
name|unsigned
name|char
name|mode_inner
index|[
name|NUM_MACHINE_MODES
index|]
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|GET_MODE_INNER
parameter_list|(
name|MODE
parameter_list|)
value|mode_inner[MODE]
end_define

begin_comment
comment|/* Get the size in bytes of the basic parts of an object of mode MODE.  */
end_comment

begin_define
define|#
directive|define
name|GET_MODE_UNIT_SIZE
parameter_list|(
name|MODE
parameter_list|)
define|\
value|(GET_MODE_INNER (MODE) == VOIDmode		\    ? GET_MODE_SIZE (MODE)			\    : GET_MODE_SIZE (GET_MODE_INNER (MODE)))
end_define

begin_comment
comment|/* Get the number of units in the object.  */
end_comment

begin_decl_stmt
specifier|extern
specifier|const
name|unsigned
name|char
name|mode_nunits
index|[
name|NUM_MACHINE_MODES
index|]
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|GET_MODE_NUNITS
parameter_list|(
name|MODE
parameter_list|)
value|mode_nunits[MODE]
end_define

begin_comment
comment|/* Get the next wider natural mode (eg, QI -> HI -> SI -> DI -> TI).  */
end_comment

begin_decl_stmt
specifier|extern
specifier|const
name|unsigned
name|char
name|mode_wider
index|[
name|NUM_MACHINE_MODES
index|]
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|GET_MODE_WIDER_MODE
parameter_list|(
name|MODE
parameter_list|)
value|mode_wider[MODE]
end_define

begin_comment
comment|/* Return the mode for data of a given size SIZE and mode class CLASS.    If LIMIT is nonzero, then don't use modes bigger than MAX_FIXED_MODE_SIZE.    The value is BLKmode if no other mode is found.  */
end_comment

begin_function_decl
specifier|extern
name|enum
name|machine_mode
name|mode_for_size
parameter_list|(
name|unsigned
name|int
parameter_list|,
name|enum
name|mode_class
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Similar, but find the smallest mode for a given width.  */
end_comment

begin_function_decl
specifier|extern
name|enum
name|machine_mode
name|smallest_mode_for_size
parameter_list|(
name|unsigned
name|int
parameter_list|,
name|enum
name|mode_class
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Return an integer mode of the exact same size as the input mode,    or BLKmode on failure.  */
end_comment

begin_function_decl
specifier|extern
name|enum
name|machine_mode
name|int_mode_for_mode
parameter_list|(
name|enum
name|machine_mode
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Find the best mode to use to access a bit field.  */
end_comment

begin_function_decl
specifier|extern
name|enum
name|machine_mode
name|get_best_mode
parameter_list|(
name|int
parameter_list|,
name|int
parameter_list|,
name|unsigned
name|int
parameter_list|,
name|enum
name|machine_mode
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Determine alignment, 1<=result<=BIGGEST_ALIGNMENT.  */
end_comment

begin_decl_stmt
specifier|extern
name|CONST_MODE_BASE_ALIGN
name|unsigned
name|char
name|mode_base_align
index|[
name|NUM_MACHINE_MODES
index|]
decl_stmt|;
end_decl_stmt

begin_function_decl
specifier|extern
name|unsigned
name|get_mode_alignment
parameter_list|(
name|enum
name|machine_mode
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|GET_MODE_ALIGNMENT
parameter_list|(
name|MODE
parameter_list|)
value|get_mode_alignment (MODE)
end_define

begin_comment
comment|/* For each class, get the narrowest mode in that class.  */
end_comment

begin_decl_stmt
specifier|extern
specifier|const
name|unsigned
name|char
name|class_narrowest_mode
index|[
name|MAX_MODE_CLASS
index|]
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|GET_CLASS_NARROWEST_MODE
parameter_list|(
name|CLASS
parameter_list|)
value|class_narrowest_mode[CLASS]
end_define

begin_comment
comment|/* Define the integer modes whose sizes are BITS_PER_UNIT and BITS_PER_WORD    and the mode whose class is Pmode and whose size is POINTER_SIZE.  */
end_comment

begin_decl_stmt
specifier|extern
name|enum
name|machine_mode
name|byte_mode
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|enum
name|machine_mode
name|word_mode
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|enum
name|machine_mode
name|ptr_mode
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Target-dependent machine mode initialization - in insn-modes.c.  */
end_comment

begin_function_decl
specifier|extern
name|void
name|init_adjust_machine_modes
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* not HAVE_MACHINE_MODES */
end_comment

end_unit

