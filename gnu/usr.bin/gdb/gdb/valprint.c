begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Print values for GDB, the GNU debugger.    Copyright 1986, 1988, 1989, 1991 Free Software Foundation, Inc.  This file is part of GDB.  This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version.  This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with this program; if not, write to the Free Software Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.  */
end_comment

begin_include
include|#
directive|include
file|"defs.h"
end_include

begin_include
include|#
directive|include
file|<string.h>
end_include

begin_include
include|#
directive|include
file|"symtab.h"
end_include

begin_include
include|#
directive|include
file|"gdbtypes.h"
end_include

begin_include
include|#
directive|include
file|"value.h"
end_include

begin_include
include|#
directive|include
file|"gdbcore.h"
end_include

begin_include
include|#
directive|include
file|"gdbcmd.h"
end_include

begin_include
include|#
directive|include
file|"target.h"
end_include

begin_include
include|#
directive|include
file|"obstack.h"
end_include

begin_include
include|#
directive|include
file|"language.h"
end_include

begin_include
include|#
directive|include
file|"demangle.h"
end_include

begin_include
include|#
directive|include
file|<errno.h>
end_include

begin_comment
comment|/* Prototypes for local functions */
end_comment

begin_decl_stmt
specifier|static
name|void
name|print_hex_chars
name|PARAMS
argument_list|(
operator|(
name|FILE
operator|*
operator|,
name|unsigned
name|char
operator|*
operator|,
name|unsigned
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|void
name|show_print
name|PARAMS
argument_list|(
operator|(
name|char
operator|*
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|void
name|set_print
name|PARAMS
argument_list|(
operator|(
name|char
operator|*
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|void
name|set_radix
name|PARAMS
argument_list|(
operator|(
name|char
operator|*
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|void
name|show_radix
name|PARAMS
argument_list|(
operator|(
name|char
operator|*
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|void
name|set_input_radix
name|PARAMS
argument_list|(
operator|(
name|char
operator|*
operator|,
name|int
operator|,
expr|struct
name|cmd_list_element
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|void
name|set_input_radix_1
name|PARAMS
argument_list|(
operator|(
name|int
operator|,
name|unsigned
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|void
name|set_output_radix
name|PARAMS
argument_list|(
operator|(
name|char
operator|*
operator|,
name|int
operator|,
expr|struct
name|cmd_list_element
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|void
name|set_output_radix_1
name|PARAMS
argument_list|(
operator|(
name|int
operator|,
name|unsigned
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|void
name|value_print_array_elements
name|PARAMS
argument_list|(
operator|(
name|value
operator|,
name|FILE
operator|*
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
comment|/* Maximum number of chars to print for a string pointer value or vector    contents, or UINT_MAX for no limit.  Note that "set print elements 0"    stores UINT_MAX in print_max, which displays in a show command as    "unlimited". */
end_comment

begin_decl_stmt
name|unsigned
name|int
name|print_max
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|PRINT_MAX_DEFAULT
value|200
end_define

begin_comment
comment|/* Start print_max off at this value. */
end_comment

begin_comment
comment|/* Default input and output radixes, and output format letter.  */
end_comment

begin_decl_stmt
name|unsigned
name|input_radix
init|=
literal|10
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|unsigned
name|output_radix
init|=
literal|10
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|output_format
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Print repeat counts if there are more than this many repetitions of an    element in an array.  Referenced by the low level language dependent    print routines. */
end_comment

begin_decl_stmt
name|unsigned
name|int
name|repeat_count_threshold
init|=
literal|10
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|prettyprint_structs
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Controls pretty printing of structures */
end_comment

begin_decl_stmt
name|int
name|prettyprint_arrays
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Controls pretty printing of arrays.  */
end_comment

begin_comment
comment|/* If nonzero, causes unions inside structures or other unions to be    printed. */
end_comment

begin_decl_stmt
name|int
name|unionprint
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Controls printing of nested unions.  */
end_comment

begin_comment
comment|/* If nonzero, causes machine addresses to be printed in certain contexts. */
end_comment

begin_decl_stmt
name|int
name|addressprint
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Controls printing of machine addresses */
end_comment

begin_escape
end_escape

begin_comment
comment|/* Print data of type TYPE located at VALADDR (within GDB), which came from    the inferior at address ADDRESS, onto stdio stream STREAM according to    FORMAT (a letter, or 0 for natural format using TYPE).     If DEREF_REF is nonzero, then dereference references, otherwise just print    them like pointers.     The PRETTY parameter controls prettyprinting.     If the data are a string pointer, returns the number of string characters    printed.     FIXME:  The data at VALADDR is in target byte order.  If gdb is ever    enhanced to be able to debug more than the single target it was compiled    for (specific CPU type and thus specific target byte ordering), then    either the print routines are going to have to take this into account,    or the data is going to have to be passed into here already converted    to the host byte ordering, whichever is more convenient. */
end_comment

begin_function
name|int
name|val_print
parameter_list|(
name|type
parameter_list|,
name|valaddr
parameter_list|,
name|address
parameter_list|,
name|stream
parameter_list|,
name|format
parameter_list|,
name|deref_ref
parameter_list|,
name|recurse
parameter_list|,
name|pretty
parameter_list|)
name|struct
name|type
modifier|*
name|type
decl_stmt|;
name|char
modifier|*
name|valaddr
decl_stmt|;
name|CORE_ADDR
name|address
decl_stmt|;
name|FILE
modifier|*
name|stream
decl_stmt|;
name|int
name|format
decl_stmt|;
name|int
name|deref_ref
decl_stmt|;
name|int
name|recurse
decl_stmt|;
name|enum
name|val_prettyprint
name|pretty
decl_stmt|;
block|{
if|if
condition|(
name|pretty
operator|==
name|Val_pretty_default
condition|)
block|{
name|pretty
operator|=
name|prettyprint_structs
condition|?
name|Val_prettyprint
else|:
name|Val_no_prettyprint
expr_stmt|;
block|}
name|QUIT
expr_stmt|;
comment|/* Ensure that the type is complete and not just a stub.  If the type is      only a stub and we can't find and substitute its complete type, then      print appropriate string and return.  Typical types that my be stubs      are structs, unions, and C++ methods. */
name|check_stub_type
argument_list|(
name|type
argument_list|)
expr_stmt|;
if|if
condition|(
name|TYPE_FLAGS
argument_list|(
name|type
argument_list|)
operator|&
name|TYPE_FLAG_STUB
condition|)
block|{
name|fprintf_filtered
argument_list|(
name|stream
argument_list|,
literal|"<incomplete type>"
argument_list|)
expr_stmt|;
name|fflush
argument_list|(
name|stream
argument_list|)
expr_stmt|;
return|return
operator|(
literal|0
operator|)
return|;
block|}
return|return
operator|(
name|LA_VAL_PRINT
argument_list|(
name|type
argument_list|,
name|valaddr
argument_list|,
name|address
argument_list|,
name|stream
argument_list|,
name|format
argument_list|,
name|deref_ref
argument_list|,
name|recurse
argument_list|,
name|pretty
argument_list|)
operator|)
return|;
block|}
end_function

begin_comment
comment|/* Print the value VAL in C-ish syntax on stream STREAM.    FORMAT is a format-letter, or 0 for print in natural format of data type.    If the object printed is a string pointer, returns    the number of string bytes printed.  */
end_comment

begin_function
name|int
name|value_print
parameter_list|(
name|val
parameter_list|,
name|stream
parameter_list|,
name|format
parameter_list|,
name|pretty
parameter_list|)
name|value
name|val
decl_stmt|;
name|FILE
modifier|*
name|stream
decl_stmt|;
name|int
name|format
decl_stmt|;
name|enum
name|val_prettyprint
name|pretty
decl_stmt|;
block|{
specifier|register
name|unsigned
name|int
name|n
decl_stmt|,
name|typelen
decl_stmt|;
if|if
condition|(
name|val
operator|==
literal|0
condition|)
block|{
name|printf_filtered
argument_list|(
literal|"<address of value unknown>"
argument_list|)
expr_stmt|;
return|return
literal|0
return|;
block|}
if|if
condition|(
name|VALUE_OPTIMIZED_OUT
argument_list|(
name|val
argument_list|)
condition|)
block|{
name|printf_filtered
argument_list|(
literal|"<value optimized out>"
argument_list|)
expr_stmt|;
return|return
literal|0
return|;
block|}
comment|/* A "repeated" value really contains several values in a row.      They are made by the @ operator.      Print such values as if they were arrays.  */
if|if
condition|(
name|VALUE_REPEATED
argument_list|(
name|val
argument_list|)
condition|)
block|{
name|n
operator|=
name|VALUE_REPETITIONS
argument_list|(
name|val
argument_list|)
expr_stmt|;
name|typelen
operator|=
name|TYPE_LENGTH
argument_list|(
name|VALUE_TYPE
argument_list|(
name|val
argument_list|)
argument_list|)
expr_stmt|;
name|fprintf_filtered
argument_list|(
name|stream
argument_list|,
literal|"{"
argument_list|)
expr_stmt|;
comment|/* Print arrays of characters using string syntax.  */
if|if
condition|(
name|typelen
operator|==
literal|1
operator|&&
name|TYPE_CODE
argument_list|(
name|VALUE_TYPE
argument_list|(
name|val
argument_list|)
argument_list|)
operator|==
name|TYPE_CODE_INT
operator|&&
name|format
operator|==
literal|0
condition|)
name|LA_PRINT_STRING
argument_list|(
name|stream
argument_list|,
name|VALUE_CONTENTS
argument_list|(
name|val
argument_list|)
argument_list|,
name|n
argument_list|,
literal|0
argument_list|)
expr_stmt|;
else|else
block|{
name|value_print_array_elements
argument_list|(
name|val
argument_list|,
name|stream
argument_list|,
name|format
argument_list|,
name|pretty
argument_list|)
expr_stmt|;
block|}
name|fprintf_filtered
argument_list|(
name|stream
argument_list|,
literal|"}"
argument_list|)
expr_stmt|;
return|return
operator|(
name|n
operator|*
name|typelen
operator|)
return|;
block|}
else|else
block|{
name|struct
name|type
modifier|*
name|type
init|=
name|VALUE_TYPE
argument_list|(
name|val
argument_list|)
decl_stmt|;
comment|/* If it is a pointer, indicate what it points to.  	 Print type also if it is a reference.           C++: if it is a member pointer, we will take care 	 of that when we print it.  */
if|if
condition|(
name|TYPE_CODE
argument_list|(
name|type
argument_list|)
operator|==
name|TYPE_CODE_PTR
operator|||
name|TYPE_CODE
argument_list|(
name|type
argument_list|)
operator|==
name|TYPE_CODE_REF
condition|)
block|{
comment|/* Hack:  remove (char *) for char strings.  Their 	     type is indicated by the quoted string anyway. */
if|if
condition|(
name|TYPE_CODE
argument_list|(
name|type
argument_list|)
operator|==
name|TYPE_CODE_PTR
operator|&&
name|TYPE_LENGTH
argument_list|(
name|TYPE_TARGET_TYPE
argument_list|(
name|type
argument_list|)
argument_list|)
operator|==
sizeof|sizeof
argument_list|(
name|char
argument_list|)
operator|&&
name|TYPE_CODE
argument_list|(
name|TYPE_TARGET_TYPE
argument_list|(
name|type
argument_list|)
argument_list|)
operator|==
name|TYPE_CODE_INT
operator|&&
operator|!
name|TYPE_UNSIGNED
argument_list|(
name|TYPE_TARGET_TYPE
argument_list|(
name|type
argument_list|)
argument_list|)
condition|)
block|{
comment|/* Print nothing */
block|}
else|else
block|{
name|fprintf_filtered
argument_list|(
name|stream
argument_list|,
literal|"("
argument_list|)
expr_stmt|;
name|type_print
argument_list|(
name|type
argument_list|,
literal|""
argument_list|,
name|stream
argument_list|,
operator|-
literal|1
argument_list|)
expr_stmt|;
name|fprintf_filtered
argument_list|(
name|stream
argument_list|,
literal|") "
argument_list|)
expr_stmt|;
block|}
block|}
return|return
operator|(
name|val_print
argument_list|(
name|type
argument_list|,
name|VALUE_CONTENTS
argument_list|(
name|val
argument_list|)
argument_list|,
name|VALUE_ADDRESS
argument_list|(
name|val
argument_list|)
argument_list|,
name|stream
argument_list|,
name|format
argument_list|,
literal|1
argument_list|,
literal|0
argument_list|,
name|pretty
argument_list|)
operator|)
return|;
block|}
block|}
end_function

begin_comment
comment|/*  Called by various<lang>_val_print routines to print TYPE_CODE_INT's */
end_comment

begin_function
name|void
name|val_print_type_code_int
parameter_list|(
name|type
parameter_list|,
name|valaddr
parameter_list|,
name|stream
parameter_list|)
name|struct
name|type
modifier|*
name|type
decl_stmt|;
name|char
modifier|*
name|valaddr
decl_stmt|;
name|FILE
modifier|*
name|stream
decl_stmt|;
block|{
name|char
modifier|*
name|p
decl_stmt|;
comment|/* Pointer to first (i.e. lowest address) nonzero character.  */
name|char
modifier|*
name|first_addr
decl_stmt|;
name|unsigned
name|int
name|len
decl_stmt|;
if|if
condition|(
name|TYPE_LENGTH
argument_list|(
name|type
argument_list|)
operator|>
sizeof|sizeof
argument_list|(
name|LONGEST
argument_list|)
condition|)
block|{
if|if
condition|(
name|TYPE_UNSIGNED
argument_list|(
name|type
argument_list|)
condition|)
block|{
comment|/* First figure out whether the number in fact has zeros 	     in all its bytes more significant than least significant 	     sizeof (LONGEST) ones.  */
name|len
operator|=
name|TYPE_LENGTH
argument_list|(
name|type
argument_list|)
expr_stmt|;
if|#
directive|if
name|TARGET_BYTE_ORDER
operator|==
name|BIG_ENDIAN
for|for
control|(
name|p
operator|=
name|valaddr
init|;
name|len
operator|>
sizeof|sizeof
argument_list|(
name|LONGEST
argument_list|)
operator|&&
name|p
operator|<
name|valaddr
operator|+
name|TYPE_LENGTH
argument_list|(
name|type
argument_list|)
condition|;
name|p
operator|++
control|)
else|#
directive|else
comment|/* Little endian.  */
name|first_addr
operator|=
name|valaddr
expr_stmt|;
for|for
control|(
name|p
operator|=
name|valaddr
operator|+
name|TYPE_LENGTH
argument_list|(
name|type
argument_list|)
operator|-
literal|1
init|;
name|len
operator|>
sizeof|sizeof
argument_list|(
name|LONGEST
argument_list|)
operator|&&
name|p
operator|>=
name|valaddr
condition|;
name|p
operator|--
control|)
endif|#
directive|endif
comment|/* Little endian.  */
block|{
if|if
condition|(
operator|*
name|p
operator|==
literal|0
condition|)
block|{
name|len
operator|--
expr_stmt|;
block|}
else|else
block|{
break|break;
block|}
block|}
if|#
directive|if
name|TARGET_BYTE_ORDER
operator|==
name|BIG_ENDIAN
name|first_addr
operator|=
name|p
expr_stmt|;
endif|#
directive|endif
if|if
condition|(
name|len
operator|<=
sizeof|sizeof
argument_list|(
name|LONGEST
argument_list|)
condition|)
block|{
comment|/* We can print it in decimal.  */
name|print_longest
argument_list|(
name|stream
argument_list|,
literal|'u'
argument_list|,
literal|0
argument_list|,
name|unpack_long
argument_list|(
name|BUILTIN_TYPE_LONGEST
argument_list|,
name|first_addr
argument_list|)
argument_list|)
expr_stmt|;
block|}
else|else
block|{
comment|/* It is big, so print it in hex.  */
name|print_hex_chars
argument_list|(
name|stream
argument_list|,
operator|(
name|unsigned
name|char
operator|*
operator|)
name|first_addr
argument_list|,
name|len
argument_list|)
expr_stmt|;
block|}
block|}
else|else
block|{
comment|/* Signed.  One could assume two's complement (a reasonable 	     assumption, I think) and do better than this.  */
name|print_hex_chars
argument_list|(
name|stream
argument_list|,
operator|(
name|unsigned
name|char
operator|*
operator|)
name|valaddr
argument_list|,
name|TYPE_LENGTH
argument_list|(
name|type
argument_list|)
argument_list|)
expr_stmt|;
block|}
block|}
else|else
block|{
ifdef|#
directive|ifdef
name|PRINT_TYPELESS_INTEGER
name|PRINT_TYPELESS_INTEGER
argument_list|(
name|stream
argument_list|,
name|type
argument_list|,
name|unpack_long
argument_list|(
name|type
argument_list|,
name|valaddr
argument_list|)
argument_list|)
expr_stmt|;
else|#
directive|else
name|print_longest
argument_list|(
name|stream
argument_list|,
name|TYPE_UNSIGNED
argument_list|(
name|type
argument_list|)
condition|?
literal|'u'
else|:
literal|'d'
argument_list|,
literal|0
argument_list|,
name|unpack_long
argument_list|(
name|type
argument_list|,
name|valaddr
argument_list|)
argument_list|)
expr_stmt|;
endif|#
directive|endif
block|}
block|}
end_function

begin_comment
comment|/* Print a number according to FORMAT which is one of d,u,x,o,b,h,w,g.    The raison d'etre of this function is to consolidate printing of LONG_LONG's    into this one function.  Some platforms have long longs but don't have a    printf() that supports "ll" in the format string.  We handle these by seeing    if the number is actually a long, and if not we just bail out and print the    number in hex.  The format chars b,h,w,g are from    print_scalar_formatted().  USE_LOCAL says whether or not to call the    local formatting routine to get the format.  */
end_comment

begin_function
name|void
name|print_longest
parameter_list|(
name|stream
parameter_list|,
name|format
parameter_list|,
name|use_local
parameter_list|,
name|val_long
parameter_list|)
name|FILE
modifier|*
name|stream
decl_stmt|;
name|int
name|format
decl_stmt|;
name|int
name|use_local
decl_stmt|;
name|LONGEST
name|val_long
decl_stmt|;
block|{
if|#
directive|if
name|defined
argument_list|(
name|CC_HAS_LONG_LONG
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|PRINTF_HAS_LONG_LONG
argument_list|)
name|long
name|vtop
decl_stmt|,
name|vbot
decl_stmt|;
name|vtop
operator|=
name|val_long
operator|>>
operator|(
sizeof|sizeof
argument_list|(
name|long
argument_list|)
operator|*
name|HOST_CHAR_BIT
operator|)
expr_stmt|;
name|vbot
operator|=
operator|(
name|long
operator|)
name|val_long
expr_stmt|;
if|if
condition|(
operator|(
name|format
operator|==
literal|'d'
operator|&&
operator|(
name|val_long
operator|<
name|INT_MIN
operator|||
name|val_long
operator|>
name|INT_MAX
operator|)
operator|)
operator|||
operator|(
operator|(
name|format
operator|==
literal|'u'
operator|||
name|format
operator|==
literal|'x'
operator|)
operator|&&
name|val_long
operator|>
name|UINT_MAX
operator|)
condition|)
block|{
name|fprintf_filtered
argument_list|(
name|stream
argument_list|,
literal|"0x%lx%08lx"
argument_list|,
name|vtop
argument_list|,
name|vbot
argument_list|)
expr_stmt|;
return|return;
block|}
endif|#
directive|endif
ifdef|#
directive|ifdef
name|PRINTF_HAS_LONG_LONG
switch|switch
condition|(
name|format
condition|)
block|{
case|case
literal|'d'
case|:
name|fprintf_filtered
argument_list|(
name|stream
argument_list|,
name|use_local
condition|?
name|local_decimal_format_custom
argument_list|(
literal|"ll"
argument_list|)
else|:
literal|"%lld"
argument_list|,
name|val_long
argument_list|)
expr_stmt|;
break|break;
case|case
literal|'u'
case|:
name|fprintf_filtered
argument_list|(
name|stream
argument_list|,
literal|"%llu"
argument_list|,
name|val_long
argument_list|)
expr_stmt|;
break|break;
case|case
literal|'x'
case|:
name|fprintf_filtered
argument_list|(
name|stream
argument_list|,
name|use_local
condition|?
name|local_hex_format_custom
argument_list|(
literal|"ll"
argument_list|)
else|:
literal|"%llx"
argument_list|,
name|val_long
argument_list|)
expr_stmt|;
break|break;
case|case
literal|'o'
case|:
name|fprintf_filtered
argument_list|(
argument|stream
argument_list|,
argument|use_local ? local_octal_format_custom (
literal|"ll"
argument|) 				  :
literal|"%llo"
argument_list|,
argument|break;     case
literal|'b'
argument|:       fprintf_filtered (stream, local_hex_format_custom (
literal|"02ll"
argument|), val_long);       break;     case
literal|'h'
argument|:       fprintf_filtered (stream, local_hex_format_custom (
literal|"04ll"
argument|), val_long);       break;     case
literal|'w'
argument|:       fprintf_filtered (stream, local_hex_format_custom (
literal|"08ll"
argument|), val_long);       break;     case
literal|'g'
argument|:       fprintf_filtered (stream, local_hex_format_custom (
literal|"016ll"
argument|), val_long);       break;     default:       abort ();     }
else|#
directive|else
comment|/* !PRINTF_HAS_LONG_LONG */
comment|/* In the following it is important to coerce (val_long) to a long. It does      nothing if !LONG_LONG, but it will chop off the top half (which we know      we can ignore) if the host supports long longs.  */
argument|switch (format)     {     case
literal|'d'
argument|:       fprintf_filtered (stream, 			use_local ? local_decimal_format_custom (
literal|"l"
argument|) 				  :
literal|"%ld"
argument|, 			(long) val_long);       break;     case
literal|'u'
argument|:       fprintf_filtered (stream,
literal|"%lu"
argument|, (unsigned long) val_long);       break;     case
literal|'x'
argument|:       fprintf_filtered (stream, 			use_local ? local_hex_format_custom (
literal|"l"
argument|) 				  :
literal|"%lx"
argument|, 			(long) val_long);       break;     case
literal|'o'
argument|:       fprintf_filtered (stream, 			use_local ? local_octal_format_custom (
literal|"l"
argument|) 				  :
literal|"%lo"
argument|, 			(long) val_long);       break;     case
literal|'b'
argument|:       fprintf_filtered (stream, local_hex_format_custom (
literal|"02l"
argument|), 			(long) val_long);       break;     case
literal|'h'
argument|:       fprintf_filtered (stream, local_hex_format_custom (
literal|"04l"
argument|), 			(long) val_long);       break;     case
literal|'w'
argument|:       fprintf_filtered (stream, local_hex_format_custom (
literal|"08l"
argument|), 			(long) val_long);       break;     case
literal|'g'
argument|:       fprintf_filtered (stream, local_hex_format_custom (
literal|"016l"
argument|), 			(long) val_long);       break;     default:       abort ();     }
endif|#
directive|endif
comment|/* !PRINTF_HAS_LONG_LONG */
argument|}
comment|/* Print a floating point value of type TYPE, pointed to in GDB by VALADDR,    on STREAM.  */
argument|void print_floating (valaddr, type, stream)      char *valaddr;      struct type *type;      FILE *stream; {   double doub;   int inv;   unsigned len = TYPE_LENGTH (type);
if|#
directive|if
name|defined
argument_list|(
name|IEEE_FLOAT
argument_list|)
comment|/* Check for NaN's.  Note that this code does not depend on us being      on an IEEE conforming system.  It only depends on the target      machine using IEEE representation.  This means (a)      cross-debugging works right, and (2) IEEE_FLOAT can (and should)      be defined for systems like the 68881, which uses IEEE      representation, but is not IEEE conforming.  */
argument|{     long low
argument_list|,
argument|high;
comment|/* Is the sign bit 0?  */
argument|int nonnegative;
comment|/* Is it is a NaN (i.e. the exponent is all ones and        the fraction is nonzero)?  */
argument|int is_nan;      if (len == sizeof (float))       {
comment|/* It's single precision. */
argument|memcpy ((char *)&low, valaddr, sizeof (low));
comment|/* target -> host.  */
argument|SWAP_TARGET_AND_HOST (&low, sizeof (float)); 	nonnegative = low>=
literal|0
argument|; 	is_nan = ((((low>>
literal|23
argument|)&
literal|0xFF
argument|) ==
literal|0xFF
argument|)&&
literal|0
argument|!= (low&
literal|0x7FFFFF
argument|)); 	low&=
literal|0x7fffff
argument|; 	high =
literal|0
argument|;       }     else       {
comment|/* It's double precision.  Get the high and low words.  */
if|#
directive|if
name|TARGET_BYTE_ORDER
operator|==
name|BIG_ENDIAN
argument|memcpy (&low, valaddr+
literal|4
argument|,  sizeof (low)); 	memcpy (&high, valaddr+
literal|0
argument|, sizeof (high));
else|#
directive|else
argument|memcpy (&low, valaddr+
literal|0
argument|,  sizeof (low)); 	memcpy (&high, valaddr+
literal|4
argument|, sizeof (high));
endif|#
directive|endif
argument|SWAP_TARGET_AND_HOST (&low, sizeof (low)); 	SWAP_TARGET_AND_HOST (&high, sizeof (high)); 	nonnegative = high>=
literal|0
argument|; 	is_nan = (((high>>
literal|20
argument|)&
literal|0x7ff
argument|) ==
literal|0x7ff
argument|&& ! ((((high&
literal|0xfffff
argument|) ==
literal|0
argument|))&& (low ==
literal|0
argument|))); 	high&=
literal|0xfffff
argument|;       }      if (is_nan)       {
comment|/* The meaning of the sign and fraction is not defined by IEEE. 	   But the user might know what they mean.  For example, they 	   (in an implementation-defined manner) distinguish between 	   signaling and quiet NaN's.  */
argument|if (high) 	  fprintf_filtered (stream,
literal|"-NaN(0x%lx%.8lx)"
argument|+ nonnegative, 			    high, low); 	else 	  fprintf_filtered (stream,
literal|"-NaN(0x%lx)"
argument|+ nonnegative, low); 	return;       }   }
endif|#
directive|endif
comment|/* IEEE_FLOAT.  */
argument|doub = unpack_double (type, valaddr,&inv);   if (inv)     fprintf_filtered (stream,
literal|"<invalid float value>"
argument|);   else     fprintf_filtered (stream, len<= sizeof(float) ?
literal|"%.9g"
argument|:
literal|"%.17g"
argument|, doub); }
comment|/* VALADDR points to an integer of LEN bytes.  Print it in hex on stream.  */
argument|static void print_hex_chars (stream, valaddr, len)      FILE *stream;      unsigned char *valaddr;      unsigned len; {   unsigned char *p;
comment|/* FIXME: We should be not printing leading zeroes in most cases.  */
argument|fprintf_filtered (stream, local_hex_format_prefix ());
if|#
directive|if
name|TARGET_BYTE_ORDER
operator|==
name|BIG_ENDIAN
argument|for (p = valaddr;        p< valaddr + len;        p++)
else|#
directive|else
comment|/* Little endian.  */
argument|for (p = valaddr + len -
literal|1
argument|;        p>= valaddr;        p--)
endif|#
directive|endif
argument|{       fprintf_filtered (stream,
literal|"%02x"
argument|, *p);     }   fprintf_filtered (stream, local_hex_format_suffix ()); }
comment|/*  Called by various<lang>_val_print routines to print elements of an     array in the form "<elem1>,<elem2>,<elem3>, ...".      (FIXME?)  Assumes array element separator is a comma, which is correct     for all languages currently handled.     (FIXME?)  Some languages have a notation for repeated array elements,     perhaps we should try to use that notation when appropriate.     */
argument|void val_print_array_elements (type, valaddr, address, stream, format, deref_ref, 			  recurse, pretty, i)      struct type *type;      char *valaddr;      CORE_ADDR address;      FILE *stream;      int format;      int deref_ref;      int recurse;      enum val_prettyprint pretty;      unsigned int i; {   unsigned int things_printed =
literal|0
argument|;   unsigned len;   struct type *elttype;   unsigned eltlen;
comment|/* Position of the array element we are examining to see      whether it is repeated.  */
argument|unsigned int rep1;
comment|/* Number of repetitions we have detected so far.  */
argument|unsigned int reps;          elttype = TYPE_TARGET_TYPE (type);   eltlen = TYPE_LENGTH (elttype);   len = TYPE_LENGTH (type) / eltlen; 	         for (; i< len&& things_printed< print_max; i++)     {       if (i !=
literal|0
argument|) 	{ 	  if (prettyprint_arrays) 	    { 	      fprintf_filtered (stream,
literal|",\n"
argument|); 	      print_spaces_filtered (
literal|2
argument|+
literal|2
argument|* recurse, stream); 	    } 	  else 	    { 	      fprintf_filtered (stream,
literal|", "
argument|); 	    } 	}       wrap_here (n_spaces (
literal|2
argument|+
literal|2
argument|* recurse));              rep1 = i +
literal|1
argument|;       reps =
literal|1
argument|;       while ((rep1< len)&&  	     !memcmp (valaddr + i * eltlen, valaddr + rep1 * eltlen, eltlen)) 	{ 	  ++reps; 	  ++rep1; 	}              if (reps> repeat_count_threshold) 	{ 	  val_print (elttype, valaddr + i * eltlen,
literal|0
argument|, stream, format, 		     deref_ref, recurse +
literal|1
argument|, pretty); 	  fprintf_filtered (stream,
literal|"<repeats %u times>"
argument|, reps); 	  i = rep1 -
literal|1
argument|; 	  things_printed += repeat_count_threshold; 	}       else 	{ 	  val_print (elttype, valaddr + i * eltlen,
literal|0
argument|, stream, format, 		     deref_ref, recurse +
literal|1
argument|, pretty); 	  things_printed++; 	}     }   if (i< len)     {       fprintf_filtered (stream,
literal|"..."
argument|);     } }  static void value_print_array_elements (val, stream, format, pretty)      value val;      FILE *stream;      int format;      enum val_prettyprint pretty; {   unsigned int things_printed =
literal|0
argument|;   register unsigned int i
argument_list|,
argument|n
argument_list|,
argument|typelen;
comment|/* Position of the array elem we are examining to see if it is repeated.  */
argument|unsigned int rep1;
comment|/* Number of repetitions we have detected so far.  */
argument|unsigned int reps;        n = VALUE_REPETITIONS (val);   typelen = TYPE_LENGTH (VALUE_TYPE (val));   for (i =
literal|0
argument|; i< n&& things_printed< print_max; i++)     {       if (i !=
literal|0
argument|) 	{ 	  fprintf_filtered (stream,
literal|", "
argument|); 	}       wrap_here (
literal|""
argument|);              rep1 = i +
literal|1
argument|;       reps =
literal|1
argument|;       while (rep1< n&& !memcmp (VALUE_CONTENTS (val) + typelen * i, 				  VALUE_CONTENTS (val) + typelen * rep1, 				  typelen)) 	{ 	  ++reps; 	  ++rep1; 	}              if (reps> repeat_count_threshold) 	{ 	  val_print (VALUE_TYPE (val), VALUE_CONTENTS (val) + typelen * i, 		     VALUE_ADDRESS (val) + typelen * i, stream, format,
literal|1
argument|,
literal|0
argument|, pretty); 	  fprintf (stream,
literal|"<repeats %u times>"
argument|, reps); 	  i = rep1 -
literal|1
argument|; 	  things_printed += repeat_count_threshold; 	}       else 	{ 	  val_print (VALUE_TYPE (val), VALUE_CONTENTS (val) + typelen * i, 		     VALUE_ADDRESS (val) + typelen * i, stream, format,
literal|1
argument|,
literal|0
argument|, pretty); 	  things_printed++; 	}     }   if (i< n)     {       fprintf_filtered (stream,
literal|"..."
argument|);     } }
comment|/*  Print a string from the inferior, starting at ADDR and printing up to LEN     characters, to STREAM.  If LEN is zero, printing stops at the first null     byte, otherwise printing proceeds (including null bytes) until either     print_max or LEN characters have been printed, whichever is smaller. */
argument|int val_print_string (addr, len, stream)     CORE_ADDR addr;     unsigned int len;     FILE *stream; {   int force_ellipsis =
literal|0
argument|;
comment|/* Force ellipsis to be printed if nonzero. */
argument|int errcode;
comment|/* Errno returned from bad reads. */
argument|unsigned int fetchlimit;
comment|/* Maximum number of bytes to fetch. */
argument|unsigned int nfetch;
comment|/* Bytes to fetch / bytes fetched. */
argument|unsigned int chunksize;
comment|/* Size of each fetch, in bytes. */
argument|int bufsize;
comment|/* Size of current fetch buffer. */
argument|char *buffer = NULL;
comment|/* Dynamically growable fetch buffer. */
argument|char *bufptr;
comment|/* Pointer to next available byte in buffer. */
argument|char *limit;
comment|/* First location past end of fetch buffer. */
argument|struct cleanup *old_chain = NULL;
comment|/* Top of the old cleanup chain. */
argument|char peekchar;
comment|/* Place into which we can read one char. */
comment|/* First we need to figure out the limit on the number of characters we are      going to attempt to fetch and print.  This is actually pretty simple.  If      LEN is nonzero, then the limit is the minimum of LEN and print_max.  If      LEN is zero, then the limit is print_max.  This is true regardless of      whether print_max is zero, UINT_MAX (unlimited), or something in between,      because finding the null byte (or available memory) is what actually      limits the fetch. */
argument|fetchlimit = (len ==
literal|0
argument|? print_max : min (len, print_max));
comment|/* Now decide how large of chunks to try to read in one operation.  This      is also pretty simple.  If LEN is nonzero, then we want fetchlimit bytes,      so we might as well read them all in one operation.  If LEN is zero, we      are looking for a null terminator to end the fetching, so we might as      well read in blocks that are large enough to be efficient, but not so      large as to be slow if fetchlimit happens to be large.  So we choose the      minimum of DEFAULT_PRINT_MAX and fetchlimit. */
argument|chunksize = (len ==
literal|0
argument|? min (PRINT_MAX_DEFAULT, fetchlimit) : fetchlimit);
comment|/* Loop until we either have all the characters to print, or we encounter      some error, such as bumping into the end of the address space. */
argument|bufsize =
literal|0
argument|;   do {     QUIT;
comment|/* Figure out how much to fetch this time, and grow the buffer to fit. */
argument|nfetch = min (chunksize, fetchlimit - bufsize);     bufsize += nfetch;     if (buffer == NULL)       { 	buffer = (char *) xmalloc (bufsize); 	bufptr = buffer;       }     else       { 	discard_cleanups (old_chain); 	buffer = (char *) xrealloc (buffer, bufsize); 	bufptr = buffer + bufsize - nfetch;       }     old_chain = make_cleanup (free, buffer);
comment|/* Read as much as we can. */
argument|nfetch = target_read_memory_partial (addr, bufptr, nfetch,&errcode);     if (len !=
literal|0
argument|)       { 	addr += nfetch; 	bufptr += nfetch;       }     else       {
comment|/* Scan this chunk for the null byte that terminates the string 	   to print.  If found, we don't need to fetch any more.  Note 	   that bufptr is explicitly left pointing at the next character 	   after the null byte, or at the next character after the end of 	   the buffer. */
argument|limit = bufptr + nfetch; 	do { 	  addr++; 	  bufptr++; 	} while (bufptr< limit&& *(bufptr -
literal|1
argument|) !=
literal|'\0'
argument|);       }   } while (errcode ==
literal|0
comment|/* no error */
argument|&& bufptr< buffer + fetchlimit
comment|/* no overrun */
argument|&& !(len ==
literal|0
argument|&& *(bufptr -
literal|1
argument|) ==
literal|'\0'
argument|));
comment|/* no null term */
comment|/* We now have either successfully filled the buffer to fetchlimit, or      terminated early due to an error or finding a null byte when LEN is      zero. */
argument|if (len ==
literal|0
argument|&& *(bufptr -
literal|1
argument|) !=
literal|'\0'
argument|)     {
comment|/* We didn't find a null terminator we were looking for.  Attempt 	 to peek at the next character.  If not successful, or it is not 	 a null byte, then force ellipsis to be printed. */
argument|if (target_read_memory (addr,&peekchar,
literal|1
argument|) !=
literal|0
argument||| peekchar !=
literal|'\0'
argument|) 	{ 	  force_ellipsis =
literal|1
argument|; 	}     }   else if ((len !=
literal|0
argument|&& errcode !=
literal|0
argument|) || (len> bufptr - buffer))     {
comment|/* Getting an error when we have a requested length, or fetching less 	 than the number of characters actually requested, always make us 	 print ellipsis. */
argument|force_ellipsis =
literal|1
argument|;     }    QUIT;      if (addressprint)     {       fputs_filtered (
literal|" "
argument|, stream);     }   LA_PRINT_STRING (stream, buffer, bufptr - buffer, force_ellipsis);      if (errcode !=
literal|0
argument|&& force_ellipsis)     {       if (errcode == EIO) 	{ 	  fprintf_filtered (stream,
literal|"<Address 0x%lx out of bounds>"
argument|, 			    (unsigned long) addr); 	}       else 	{ 	  error (
literal|"Error reading memory address 0x%lx: %s."
argument|, 		 (unsigned long) addr, 		 safe_strerror (errcode)); 	}     }   fflush (stream);   do_cleanups (old_chain);   return (bufptr - buffer); }
comment|/* Validate an input or output radix setting, and make sure the user    knows what they really did here.  Radix setting is confusing, e.g.    setting the input radix to "10" never changes it!  */
comment|/* ARGSUSED */
argument|static void set_input_radix (args, from_tty, c)      char *args;      int from_tty;      struct cmd_list_element *c; {   set_input_radix_1 (from_tty, *(unsigned *)c->var); }
comment|/* ARGSUSED */
argument|static void set_input_radix_1 (from_tty, radix)      int from_tty;      unsigned radix; {
comment|/* We don't currently disallow any input radix except 0 or 1, which don't      make any mathematical sense.  In theory, we can deal with any input      radix greater than 1, even if we don't have unique digits for every      value from 0 to radix-1, but in practice we lose on large radix values.      We should either fix the lossage or restrict the radix range more.      (FIXME). */
argument|if (radix<
literal|2
argument|)     {       error (
literal|"Nonsense input radix ``decimal %u''; input radix unchanged."
argument|, 	     radix);     }   input_radix = radix;   if (from_tty)     {       printf_filtered (
literal|"Input radix now set to decimal %u, hex %x, octal %o.\n"
argument|, 		       radix, radix, radix);     } }
comment|/* ARGSUSED */
argument|static void set_output_radix (args, from_tty, c)      char *args;      int from_tty;      struct cmd_list_element *c; {   set_output_radix_1 (from_tty, *(unsigned *)c->var); }  static void set_output_radix_1 (from_tty, radix)      int from_tty;      unsigned radix; {
comment|/* Validate the radix and disallow ones that we aren't prepared to      handle correctly, leaving the radix unchanged. */
argument|switch (radix)     {     case
literal|16
argument|:       output_format =
literal|'x'
argument|;
comment|/* hex */
argument|break;     case
literal|10
argument|:       output_format =
literal|0
argument|;
comment|/* decimal */
argument|break;     case
literal|8
argument|:       output_format =
literal|'o'
argument|;
comment|/* octal */
argument|break;     default:       error (
literal|"Unsupported output radix ``decimal %u''; output radix unchanged."
argument|, 	     radix);     }   output_radix = radix;   if (from_tty)     {       printf_filtered (
literal|"Output radix now set to decimal %u, hex %x, octal %o.\n"
argument|, 		       radix, radix, radix);     } }
comment|/* Set both the input and output radix at once.  Try to set the output radix    first, since it has the most restrictive range.  An radix that is valid as    an output radix is also valid as an input radix.     It may be useful to have an unusual input radix.  If the user wishes to    set an input radix that is not valid as an output radix, he needs to use    the 'set input-radix' command. */
argument|static void set_radix (arg, from_tty)      char *arg;      int from_tty; {   unsigned radix;    radix = (arg == NULL) ?
literal|10
argument|: parse_and_eval_address (arg);   set_output_radix_1 (
literal|0
argument|, radix);   set_input_radix_1 (
literal|0
argument|, radix);   if (from_tty)     {       printf_filtered (
literal|"Input and output radices now set to decimal %u, hex %x, octal %o.\n"
argument|, 		       radix, radix, radix);     } }
comment|/* Show both the input and output radices. */
comment|/*ARGSUSED*/
argument|static void show_radix (arg, from_tty)      char *arg;      int from_tty; {   if (from_tty)     {       if (input_radix == output_radix) 	{ 	  printf_filtered (
literal|"Input and output radices set to decimal %u, hex %x, octal %o.\n"
argument|, 			   input_radix, input_radix, input_radix); 	}       else 	{ 	  printf_filtered (
literal|"Input radix set to decimal %u, hex %x, octal %o.\n"
argument|, 			   input_radix, input_radix, input_radix); 	  printf_filtered (
literal|"Output radix set to decimal %u, hex %x, octal %o.\n"
argument|, 			   output_radix, output_radix, output_radix); 	}     } }
comment|/*ARGSUSED*/
argument|static void set_print (arg, from_tty)      char *arg;      int from_tty; {   printf (
literal|"\"set print\" must be followed by the name of a print subcommand.\n"
argument|);   help_list (setprintlist,
literal|"set print "
argument|, -
literal|1
argument|, stdout); }
comment|/*ARGSUSED*/
argument|static void show_print (args, from_tty)      char *args;      int from_tty; {   cmd_show_list (showprintlist, from_tty,
literal|""
argument|); }
argument|void _initialize_valprint () {   struct cmd_list_element *c;    add_prefix_cmd (
literal|"print"
argument|, no_class, set_print,
literal|"Generic command for setting how things print."
argument|,&setprintlist,
literal|"set print "
argument|,
literal|0
argument|,&setlist);   add_alias_cmd (
literal|"p"
argument|,
literal|"print"
argument|, no_class,
literal|1
argument|,&setlist);
comment|/* prefer set print to set prompt */
argument|add_alias_cmd (
literal|"pr"
argument|,
literal|"print"
argument|, no_class,
literal|1
argument|,&setlist);    add_prefix_cmd (
literal|"print"
argument|, no_class, show_print,
literal|"Generic command for showing print settings."
argument|,&showprintlist,
literal|"show print "
argument|,
literal|0
argument|,&showlist);   add_alias_cmd (
literal|"p"
argument|,
literal|"print"
argument|, no_class,
literal|1
argument|,&showlist);    add_alias_cmd (
literal|"pr"
argument|,
literal|"print"
argument|, no_class,
literal|1
argument|,&showlist);     add_show_from_set     (add_set_cmd (
literal|"elements"
argument|, no_class, var_uinteger, (char *)&print_max,
literal|"Set limit on string chars or array elements to print.\n\ \"set print elements 0\" causes there to be no limit."
argument|,&setprintlist),&showprintlist);    add_show_from_set     (add_set_cmd (
literal|"repeats"
argument|, no_class, var_uinteger, 		  (char *)&repeat_count_threshold,
literal|"Set threshold for repeated print elements.\n\ \"set print repeats 0\" causes all elements to be individually printed."
argument|,&setprintlist),&showprintlist);    add_show_from_set     (add_set_cmd (
literal|"pretty"
argument|, class_support, var_boolean, 		  (char *)&prettyprint_structs,
literal|"Set prettyprinting of structures."
argument|,&setprintlist),&showprintlist);    add_show_from_set     (add_set_cmd (
literal|"union"
argument|, class_support, var_boolean, (char *)&unionprint,
literal|"Set printing of unions interior to structures."
argument|,&setprintlist),&showprintlist);      add_show_from_set     (add_set_cmd (
literal|"array"
argument|, class_support, var_boolean, 		  (char *)&prettyprint_arrays,
literal|"Set prettyprinting of arrays."
argument|,&setprintlist),&showprintlist);    add_show_from_set     (add_set_cmd (
literal|"address"
argument|, class_support, var_boolean, (char *)&addressprint,
literal|"Set printing of addresses."
argument|,&setprintlist),&showprintlist);    c = add_set_cmd (
literal|"input-radix"
argument|, class_support, var_uinteger, 		   (char *)&input_radix,
literal|"Set default input radix for entering numbers."
argument|,&setlist);   add_show_from_set (c,&showlist);   c->function.sfunc = set_input_radix;    c = add_set_cmd (
literal|"output-radix"
argument|, class_support, var_uinteger, 		   (char *)&output_radix,
literal|"Set default output radix for printing of values."
argument|,&setlist);   add_show_from_set (c,&showlist);   c->function.sfunc = set_output_radix;
comment|/* The "set radix" and "show radix" commands are special in that they are      like normal set and show commands but allow two normally independent      variables to be either set or shown with a single command.  So the      usual add_set_cmd() and add_show_from_set() commands aren't really      appropriate. */
argument|add_cmd (
literal|"radix"
argument|, class_support, set_radix,
literal|"Set default input and output number radices.\n\ Use 'set input-radix' or 'set output-radix' to independently set each.\n\ Without an argument, sets both radices back to the default value of 10."
argument|,&setlist);   add_cmd (
literal|"radix"
argument|, class_support, show_radix,
literal|"Show the default input and output number radices.\n\ Use 'show input-radix' or 'show output-radix' to independently show each."
argument|,&showlist);
comment|/* Give people the defaults which they are used to.  */
argument|prettyprint_structs =
literal|0
argument|;   prettyprint_arrays =
literal|0
argument|;   unionprint =
literal|1
argument|;   addressprint =
literal|1
argument|;   print_max = PRINT_MAX_DEFAULT; }
end_function

end_unit

