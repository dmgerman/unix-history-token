begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Machine mode definitions for GNU C-Compiler; included by rtl.h and tree.h.    Copyright (C) 1991, 1993, 1994, 1996, 1998 Free Software Foundation, Inc.  This file is part of GNU CC.  GNU CC is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2, or (at your option) any later version.  GNU CC is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with GNU CC; see the file COPYING.  If not, write to the Free Software Foundation, 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
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
comment|/* Strictly speaking, this isn't the proper place to include these definitions,    but this file is included by every GCC file. */
end_comment

begin_comment
comment|/* Provide a default way to print an address in hex via printf.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|HOST_PTR_PRINTF
end_ifndef

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_PRINTF_PTR
end_ifdef

begin_define
define|#
directive|define
name|HOST_PTR_PRINTF
value|"%p"
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|HOST_PTR_PRINTF
define|\
value|(sizeof (int) == sizeof (char *) ? "%x" \      : sizeof (long) == sizeof (char *) ? "%lx" : "%llx")
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! HOST_PTR_PRINTF */
end_comment

begin_comment
comment|/* Make an enum class that gives all the machine modes.  */
end_comment

begin_define
define|#
directive|define
name|DEF_MACHMODE
parameter_list|(
name|SYM
parameter_list|,
name|NAME
parameter_list|,
name|TYPE
parameter_list|,
name|SIZE
parameter_list|,
name|UNIT
parameter_list|,
name|WIDER
parameter_list|)
value|SYM,
end_define

begin_enum
enum|enum
name|machine_mode
block|{
include|#
directive|include
file|"machmode.def"
ifdef|#
directive|ifdef
name|EXTRA_CC_MODES
name|EXTRA_CC_MODES
block|,
endif|#
directive|endif
name|MAX_MACHINE_MODE
block|}
enum|;
end_enum

begin_undef
undef|#
directive|undef
name|DEF_MACHMODE
end_undef

begin_ifndef
ifndef|#
directive|ifndef
name|NUM_MACHINE_MODES
end_ifndef

begin_define
define|#
directive|define
name|NUM_MACHINE_MODES
value|(int) MAX_MACHINE_MODE
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Get the name of mode MODE as a string.  */
end_comment

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|mode_name
index|[]
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|GET_MODE_NAME
parameter_list|(
name|MODE
parameter_list|)
value|(mode_name[(int) (MODE)])
end_define

begin_enum
enum|enum
name|mode_class
block|{
name|MODE_RANDOM
block|,
name|MODE_INT
block|,
name|MODE_FLOAT
block|,
name|MODE_PARTIAL_INT
block|,
name|MODE_CC
block|,
name|MODE_COMPLEX_INT
block|,
name|MODE_COMPLEX_FLOAT
block|,
name|MAX_MODE_CLASS
block|}
enum|;
end_enum

begin_comment
comment|/* Get the general kind of object that mode MODE represents    (integer, floating, complex, etc.)  */
end_comment

begin_decl_stmt
specifier|extern
name|enum
name|mode_class
name|mode_class
index|[]
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|GET_MODE_CLASS
parameter_list|(
name|MODE
parameter_list|)
value|(mode_class[(int) (MODE)])
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
value|(GET_MODE_CLASS (MODE) == MODE_INT		\    || GET_MODE_CLASS (MODE) == MODE_PARTIAL_INT \    || GET_MODE_CLASS (MODE) == MODE_COMPLEX_INT)
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
value|(GET_MODE_CLASS (MODE) == MODE_FLOAT	\    || GET_MODE_CLASS (MODE) == MODE_COMPLEX_FLOAT)
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
comment|/* Get the size in bytes of an object of mode MODE.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|mode_size
index|[]
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|GET_MODE_SIZE
parameter_list|(
name|MODE
parameter_list|)
value|(mode_size[(int) (MODE)])
end_define

begin_comment
comment|/* Get the size in bytes of the basic parts of an object of mode MODE.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|mode_unit_size
index|[]
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|GET_MODE_UNIT_SIZE
parameter_list|(
name|MODE
parameter_list|)
value|(mode_unit_size[(int) (MODE)])
end_define

begin_comment
comment|/* Get the number of units in the object.  */
end_comment

begin_define
define|#
directive|define
name|GET_MODE_NUNITS
parameter_list|(
name|MODE
parameter_list|)
define|\
value|((GET_MODE_UNIT_SIZE ((MODE)) == 0) ? 0 \    : (GET_MODE_SIZE ((MODE)) / GET_MODE_UNIT_SIZE ((MODE))))
end_define

begin_comment
comment|/* Get the size in bits of an object of mode MODE.  */
end_comment

begin_define
define|#
directive|define
name|GET_MODE_BITSIZE
parameter_list|(
name|MODE
parameter_list|)
value|(BITS_PER_UNIT * mode_size[(int) (MODE)])
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|HOST_WIDE_INT
end_ifdef

begin_comment
comment|/* Get a bitmask containing 1 for all bits in a word    that fit within mode MODE.  */
end_comment

begin_decl_stmt
specifier|extern
name|unsigned
name|HOST_WIDE_INT
name|mode_mask_array
index|[]
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|GET_MODE_MASK
parameter_list|(
name|MODE
parameter_list|)
value|mode_mask_array[(int) (MODE)]
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* HOST_WIDE_INT */
end_comment

begin_comment
comment|/* Get the next wider natural mode (eg, QI -> HI -> SI -> DI -> TI).  */
end_comment

begin_decl_stmt
specifier|extern
name|unsigned
name|char
name|mode_wider_mode
index|[]
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|GET_MODE_WIDER_MODE
parameter_list|(
name|MODE
parameter_list|)
value|((enum machine_mode)mode_wider_mode[(int) (MODE)])
end_define

begin_comment
comment|/* Return the mode for data of a given size SIZE and mode class CLASS.    If LIMIT is nonzero, then don't use modes bigger than MAX_FIXED_MODE_SIZE.    The value is BLKmode if no other mode is found.  */
end_comment

begin_decl_stmt
specifier|extern
name|enum
name|machine_mode
name|mode_for_size
name|PROTO
argument_list|(
operator|(
name|unsigned
name|int
operator|,
expr|enum
name|mode_class
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Similar, but find the smallest mode for a given width.  */
end_comment

begin_decl_stmt
specifier|extern
name|enum
name|machine_mode
name|smallest_mode_for_size
name|PROTO
argument_list|(
operator|(
name|unsigned
name|int
operator|,
expr|enum
name|mode_class
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Return an integer mode of the exact same size as the input mode,    or BLKmode on failure.  */
end_comment

begin_decl_stmt
specifier|extern
name|enum
name|machine_mode
name|int_mode_for_mode
name|PROTO
argument_list|(
operator|(
expr|enum
name|machine_mode
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Find the best mode to use to access a bit field.  */
end_comment

begin_decl_stmt
specifier|extern
name|enum
name|machine_mode
name|get_best_mode
name|PROTO
argument_list|(
operator|(
name|int
operator|,
name|int
operator|,
name|int
operator|,
expr|enum
name|machine_mode
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Determine alignment, 1<=result<=BIGGEST_ALIGNMENT.  */
end_comment

begin_define
define|#
directive|define
name|GET_MODE_ALIGNMENT
parameter_list|(
name|MODE
parameter_list|)
define|\
value|MIN (BIGGEST_ALIGNMENT, 	   \        MAX (1, (GET_MODE_UNIT_SIZE (MODE) * BITS_PER_UNIT)))
end_define

begin_comment
comment|/* For each class, get the narrowest mode in that class.  */
end_comment

begin_decl_stmt
specifier|extern
name|enum
name|machine_mode
name|class_narrowest_mode
index|[]
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|GET_CLASS_NARROWEST_MODE
parameter_list|(
name|CLASS
parameter_list|)
value|class_narrowest_mode[(int) (CLASS)]
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

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* not HAVE_MACHINE_MODES */
end_comment

end_unit

