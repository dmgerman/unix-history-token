begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  *  Interpress utilities  *  *  Written for Xerox Corporation by William LeFebvre  *  24-May-1984  *  * Copyright (c) 1984, 1985 Xerox Corp.  *  * HISTORY  * 15-Jan-86  lee at Xerox, WRC  *	Removed the rest of the Vax dependencies.  *  *	10-sep-85  lee moore	Removed some dependencies on the Vax.  *				Plenty more to be removed  *	29-apr-85  ed flint	add conditional compilation for vax-11 c (vms)  */
end_comment

begin_comment
comment|/*  *  Subroutines to help build interpress files:  *  *  literal interface level - these routines produce interpress output at  *			      the token level.  */
end_comment

begin_comment
comment|/*  *  NOTE:  Some of these "subroutines" are one-liners, so they are written  *	   as macros for better efficiency.  */
end_comment

begin_define
define|#
directive|define
name|Rational_max
value|1073741824
end_define

begin_define
define|#
directive|define
name|ip_Buffsize
value|1024
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|vax11c
end_ifndef

begin_include
include|#
directive|include
file|<sys/param.h>
end_include

begin_include
include|#
directive|include
file|<math.h>
end_include

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|"iptokens.h"
end_include

begin_include
include|#
directive|include
file|"literal.h"
end_include

begin_comment
comment|/* macro definitions for some routines */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|NULL
end_ifndef

begin_define
define|#
directive|define
name|NULL
value|(char *)0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|vax11c
end_ifdef

begin_define
define|#
directive|define
name|NOFILE
value|20
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|No
value|0
end_define

begin_define
define|#
directive|define
name|Yes
value|1
end_define

begin_decl_stmt
specifier|static
name|int
name|ip_fd
init|=
operator|-
literal|1
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* current Interpress file */
end_comment

begin_decl_stmt
specifier|static
name|char
name|ip_filebuff
index|[
name|ip_Buffsize
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* file buffer */
end_comment

begin_decl_stmt
specifier|static
name|char
modifier|*
name|ip_buffptr
init|=
name|NULL
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* points in to ip_filebuff */
end_comment

begin_decl_stmt
specifier|static
name|int
name|ip_bytecnt
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* number of bytes in ip_filebuff */
end_comment

begin_decl_stmt
specifier|static
name|char
name|ip_files
index|[
name|NOFILE
index|]
init|=
block|{
literal|0
block|}
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* marks which files are ip files */
end_comment

begin_comment
comment|/*  *  Definitions for the primitives suggested in the Interpress standard  *  (XSIS 048302).  The following primitives are defined with macros in  *  "literal.h":  *  *	AppendComment  *	AppendIdentifier  *	AppendInsertFile  *	AppendString  *  *  Currently, AppendString will only handle byte values -- it will not  *  try to insert any escape characters.  The rationale for this is that  *  ASCII (which is what this system uses) doesn't have character codes that  *  high.  */
end_comment

begin_macro
name|AppendOp
argument_list|(
argument|opcode
argument_list|)
end_macro

begin_decl_stmt
name|int
name|opcode
decl_stmt|;
end_decl_stmt

begin_block
block|{
if|if
condition|(
name|opcode
operator|>
name|SHORT_OP_LIMIT
condition|)
block|{
comment|/* has to be coded as a long op */
name|append_word
argument_list|(
call|(
name|unsigned
name|short
call|)
argument_list|(
operator|(
name|LONG_OP
operator|<<
literal|8
operator|)
operator||
name|opcode
argument_list|)
argument_list|)
expr_stmt|;
block|}
else|else
block|{
comment|/* small enough to be a short op */
name|append_byte
argument_list|(
call|(
name|unsigned
name|char
call|)
argument_list|(
name|SHORT_OP
operator||
name|opcode
argument_list|)
argument_list|)
expr_stmt|;
block|}
block|}
end_block

begin_macro
name|AppendNumber
argument_list|(
argument|number
argument_list|)
end_macro

begin_decl_stmt
name|double
name|number
decl_stmt|;
end_decl_stmt

begin_block
block|{
name|long
name|d
decl_stmt|;
name|double
name|r
decl_stmt|;
if|if
condition|(
name|number
operator|==
call|(
name|double
call|)
argument_list|(
name|d
operator|=
operator|(
name|long
operator|)
name|number
argument_list|)
condition|)
block|{
name|AppendInteger
argument_list|(
name|d
argument_list|)
expr_stmt|;
block|}
else|else
block|{
name|d
operator|=
literal|1
expr_stmt|;
while|while
condition|(
operator|(
name|fabs
argument_list|(
name|r
operator|=
name|number
operator|*
name|d
argument_list|)
operator|<
name|Rational_max
operator|)
operator|&&
operator|(
name|d
operator|<
name|Rational_max
operator|)
operator|&&
operator|(
name|r
operator|!=
call|(
name|float
call|)
argument_list|(
call|(
name|int
call|)
argument_list|(
name|r
argument_list|)
argument_list|)
operator|)
condition|)
block|{
name|d
operator|<<=
literal|1
expr_stmt|;
block|}
name|AppendRational
argument_list|(
operator|(
name|long
operator|)
name|r
argument_list|,
name|d
argument_list|)
expr_stmt|;
block|}
block|}
end_block

begin_comment
comment|/*  * note that although the routine is called AppendInteger, it is really  * AppendLong.  This is because alot of code wants to use 32 bit numbers.  * If you want to pass it a 16bit int, that will work too.  */
end_comment

begin_macro
name|AppendInteger
argument_list|(
argument|number
argument_list|)
end_macro

begin_decl_stmt
name|long
name|number
decl_stmt|;
end_decl_stmt

begin_block
block|{
if|if
condition|(
name|number
operator|<
name|INTEGER_MIN
operator|||
name|number
operator|>
name|INTEGER_MAX
condition|)
block|{
name|append_integer_sequence
argument_list|(
name|number
argument_list|)
expr_stmt|;
block|}
else|else
block|{
name|append_short_number
argument_list|(
operator|(
name|short
operator|)
name|number
argument_list|)
expr_stmt|;
block|}
block|}
end_block

begin_macro
name|AppendRational
argument_list|(
argument|value
argument_list|,
argument|divisor
argument_list|)
end_macro

begin_decl_stmt
name|long
name|value
decl_stmt|,
name|divisor
decl_stmt|;
end_decl_stmt

begin_block
block|{
name|int
name|len_value
decl_stmt|,
name|len_divisor
decl_stmt|,
name|len
decl_stmt|;
name|len_value
operator|=
name|bytes_in_int
argument_list|(
name|value
argument_list|)
expr_stmt|;
name|len_divisor
operator|=
name|bytes_in_int
argument_list|(
name|divisor
argument_list|)
expr_stmt|;
name|len
operator|=
name|len_value
operator|>
name|len_divisor
condition|?
name|len_value
else|:
name|len_divisor
expr_stmt|;
name|append_Sequence
argument_list|(
name|sequenceRational
argument_list|,
name|len
operator|<<
literal|1
argument_list|,
operator|(
name|unsigned
name|char
operator|*
operator|)
name|NULL
argument_list|)
expr_stmt|;
name|append_n_byte_int
argument_list|(
name|value
argument_list|,
name|len
argument_list|)
expr_stmt|;
name|append_n_byte_int
argument_list|(
name|divisor
argument_list|,
name|len
argument_list|)
expr_stmt|;
block|}
end_block

begin_ifdef
ifdef|#
directive|ifdef
name|notdef
end_ifdef

begin_macro
name|AppendIntegerVector
argument_list|(
argument|vector
argument_list|,
argument|num
argument_list|)
end_macro

begin_decl_stmt
name|int
modifier|*
name|vector
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* ??? */
end_comment

begin_decl_stmt
name|int
name|number
decl_stmt|;
end_decl_stmt

begin_block
block|{      }
end_block

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  *  The remainder of this file contains lower level primitives:  */
end_comment

begin_comment
comment|/*  *  append_Sequence(type, length, buff)  *  *  Append a sequence descriptor and its data bytes.  The descriptor is of  *  type "type" and length "length".  "Buff" points to the buffer containing  *  the data.  If "length" is negative, then bytes from "buffer" are written  *  back to front (this makes writing integers easy).  */
end_comment

begin_macro
name|append_Sequence
argument_list|(
argument|type
argument_list|,
argument|length
argument_list|,
argument|buff
argument_list|)
end_macro

begin_decl_stmt
name|int
name|type
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|length
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|unsigned
name|char
modifier|*
name|buff
decl_stmt|;
end_decl_stmt

begin_block
block|{
ifdef|#
directive|ifdef
name|notnow
comment|/* some day, we should make this check, but not today */
if|if
condition|(
operator|(
name|length
operator|&
literal|0x7f000000
operator|)
operator|!=
literal|0
condition|)
block|{
comment|/* too big to fit in a long ... */
block|}
endif|#
directive|endif
comment|/* check for swapped byte correction */
if|if
condition|(
name|length
operator|<
literal|0
condition|)
block|{
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"negative sequence!\n"
argument_list|)
expr_stmt|;
name|abort
argument_list|()
expr_stmt|;
block|}
if|if
condition|(
operator|(
name|length
operator|&
literal|0x7fffff00
operator|)
operator|!=
literal|0
condition|)
block|{
comment|/* too big to fit in a short sequence */
name|append_byte
argument_list|(
call|(
name|unsigned
name|char
call|)
argument_list|(
name|LONG_SEQUENCE
operator||
name|type
argument_list|)
argument_list|)
expr_stmt|;
name|append_n_byte_int
argument_list|(
operator|(
name|long
operator|)
name|length
argument_list|,
literal|3
argument_list|)
expr_stmt|;
block|}
else|else
block|{
name|append_byte
argument_list|(
call|(
name|unsigned
name|char
call|)
argument_list|(
name|SHORT_SEQUENCE
operator||
name|type
argument_list|)
argument_list|)
expr_stmt|;
name|append_byte
argument_list|(
operator|(
name|unsigned
name|char
operator|)
name|length
argument_list|)
expr_stmt|;
block|}
comment|/* tack on data, if any */
if|if
condition|(
name|buff
operator|!=
name|NULL
condition|)
name|append_bytes
argument_list|(
name|length
argument_list|,
name|buff
argument_list|)
expr_stmt|;
block|}
end_block

begin_comment
comment|/*  * append_integer_sequence(number)  *	A special version of append_sequence that handles integers.  Integers  *	must be treated differently because the natural representation of an  *	integer for a particular machine maybe byte swapped relative to the  *	Xerox standard.  */
end_comment

begin_macro
name|append_integer_sequence
argument_list|(
argument|number
argument_list|)
end_macro

begin_decl_stmt
name|long
name|number
decl_stmt|;
end_decl_stmt

begin_block
block|{
name|int
name|length
init|=
name|bytes_in_int
argument_list|(
name|number
argument_list|)
decl_stmt|;
name|append_byte
argument_list|(
call|(
name|unsigned
name|char
call|)
argument_list|(
name|SHORT_SEQUENCE
operator||
name|sequenceInteger
argument_list|)
argument_list|)
expr_stmt|;
name|append_byte
argument_list|(
operator|(
name|unsigned
name|char
operator|)
name|length
argument_list|)
expr_stmt|;
name|append_n_byte_int
argument_list|(
name|number
argument_list|,
name|length
argument_list|)
expr_stmt|;
block|}
end_block

begin_comment
comment|/*  * append_n_byte_int(number, length)  *	Append N bytes of an integer to the interpress master.  */
end_comment

begin_macro
name|append_n_byte_int
argument_list|(
argument|number
argument_list|,
argument|length
argument_list|)
end_macro

begin_decl_stmt
name|long
name|number
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|length
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* measured in bytes */
end_comment

begin_block
block|{
name|int
name|shift
decl_stmt|;
ifdef|#
directive|ifdef
name|notdef
switch|switch
condition|(
name|length
condition|)
block|{
case|case
literal|4
case|:
name|append_byte
argument_list|(
call|(
name|unsigned
name|char
call|)
argument_list|(
name|number
operator|>>
literal|24
argument_list|)
argument_list|)
expr_stmt|;
case|case
literal|3
case|:
name|append_byte
argument_list|(
call|(
name|unsigned
name|char
call|)
argument_list|(
name|number
operator|>>
literal|16
argument_list|)
argument_list|)
expr_stmt|;
case|case
literal|2
case|:
name|append_byte
argument_list|(
call|(
name|unsigned
name|char
call|)
argument_list|(
name|number
operator|>>
literal|8
argument_list|)
argument_list|)
expr_stmt|;
case|case
literal|1
case|:
name|append_byte
argument_list|(
operator|(
name|unsigned
name|char
operator|)
name|number
argument_list|)
expr_stmt|;
break|break;
default|default:
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"append_n_byte_int: asked to append %d bytes\n"
argument_list|,
name|length
argument_list|)
expr_stmt|;
block|}
else|#
directive|else
if|if
condition|(
name|length
operator|>
sizeof|sizeof
argument_list|(
name|long
argument_list|)
condition|)
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"append_n_byte_int: asked to append %d bytes\n"
argument_list|,
name|length
argument_list|)
expr_stmt|;
for|for
control|(
name|shift
operator|=
operator|(
name|length
operator|-
literal|1
operator|)
operator|*
literal|8
init|;
name|shift
operator|>=
literal|0
condition|;
name|shift
operator|-=
literal|8
control|)
name|append_byte
argument_list|(
call|(
name|unsigned
name|char
call|)
argument_list|(
name|number
operator|>>
name|shift
argument_list|)
argument_list|)
expr_stmt|;
endif|#
directive|endif
block|}
end_block

begin_comment
comment|/*  *  append_word(value) - write the two byte (word) value "value"  */
end_comment

begin_macro
name|append_word
argument_list|(
argument|value
argument_list|)
end_macro

begin_decl_stmt
name|unsigned
name|short
name|value
decl_stmt|;
end_decl_stmt

begin_block
block|{
ifdef|#
directive|ifdef
name|notdef
name|append_n_byte_int
argument_list|(
name|value
argument_list|,
literal|2
argument_list|)
expr_stmt|;
else|#
directive|else
name|append_byte
argument_list|(
call|(
name|unsigned
name|char
call|)
argument_list|(
name|value
operator|>>
literal|8
argument_list|)
argument_list|)
expr_stmt|;
name|append_byte
argument_list|(
operator|(
name|unsigned
name|char
operator|)
name|value
argument_list|)
expr_stmt|;
endif|#
directive|endif
block|}
end_block

begin_comment
comment|/*  *  append_byte(value) - write out a byte  */
end_comment

begin_macro
name|append_byte
argument_list|(
argument|value
argument_list|)
end_macro

begin_decl_stmt
name|unsigned
name|char
name|value
decl_stmt|;
end_decl_stmt

begin_block
block|{
operator|*
name|ip_buffptr
operator|++
operator|=
name|value
expr_stmt|;
if|if
condition|(
operator|++
name|ip_bytecnt
operator|==
name|ip_Buffsize
condition|)
block|{
name|write
argument_list|(
name|ip_fd
argument_list|,
name|ip_filebuff
argument_list|,
name|ip_Buffsize
argument_list|)
expr_stmt|;
name|ip_bytecnt
operator|=
literal|0
expr_stmt|;
name|ip_buffptr
operator|=
name|ip_filebuff
expr_stmt|;
block|}
block|}
end_block

begin_comment
comment|/*  *  append_bytes(length, buff) - write the buffer of bytes pointed to by  *				 "buff" with length "length".  */
end_comment

begin_macro
name|append_bytes
argument_list|(
argument|length
argument_list|,
argument|buff
argument_list|)
end_macro

begin_decl_stmt
name|int
name|length
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|unsigned
name|char
modifier|*
name|buff
decl_stmt|;
end_decl_stmt

begin_block
block|{
while|while
condition|(
name|length
operator|--
operator|>
literal|0
condition|)
block|{
name|append_byte
argument_list|(
operator|*
name|buff
operator|++
argument_list|)
expr_stmt|;
block|}
block|}
end_block

begin_comment
comment|/* this routine assumes 4 bytes in an int and two's complement notation */
end_comment

begin_comment
comment|/* this routine should be replaced! -lee */
end_comment

begin_comment
comment|/* this routine sometime over estimates the size of an integer. why? */
end_comment

begin_macro
name|bytes_in_int
argument_list|(
argument|value
argument_list|)
end_macro

begin_decl_stmt
name|long
name|value
decl_stmt|;
end_decl_stmt

begin_block
block|{
name|int
name|i
decl_stmt|;
name|long
name|mask
decl_stmt|;
if|if
condition|(
name|value
operator|<
literal|0
condition|)
block|{
comment|/* takes the same space as its one's complemented value */
name|value
operator|=
operator|~
name|value
expr_stmt|;
block|}
if|if
condition|(
name|value
operator|==
literal|0
condition|)
block|{
comment|/* avoids infinite looping */
return|return
operator|(
literal|1
operator|)
return|;
block|}
for|for
control|(
name|i
operator|=
literal|4
operator|,
name|mask
operator|=
literal|0xff800000
init|;
operator|(
name|value
operator|&
name|mask
operator|)
operator|==
literal|0
condition|;
name|i
operator|--
operator|,
name|mask
operator|>>=
literal|8
control|)
empty_stmt|;
return|return
operator|(
name|i
operator|)
return|;
block|}
end_block

begin_comment
comment|/*  *  ip_select(fd) - select file descriptor "fd" as the Interpress file for  *		    later use by the i/o routines supplied in this library.  */
end_comment

begin_macro
name|ip_select
argument_list|(
argument|fd
argument_list|)
end_macro

begin_decl_stmt
name|int
name|fd
decl_stmt|;
end_decl_stmt

begin_block
block|{
if|if
condition|(
name|ip_fd
operator|!=
operator|-
literal|1
condition|)
block|{
name|ip_flush
argument_list|()
expr_stmt|;
block|}
comment|/* set our idea of current file descriptor and initialize the buffer */
name|ip_fd
operator|=
name|fd
expr_stmt|;
name|ip_buffptr
operator|=
name|ip_filebuff
expr_stmt|;
name|ip_bytecnt
operator|=
literal|0
expr_stmt|;
comment|/* check for initialization */
if|if
condition|(
operator|!
name|ip_files
index|[
name|fd
index|]
condition|)
block|{
comment|/* not an Intepress file -- initialize it */
name|append_bytes
argument_list|(
name|strlen
argument_list|(
name|IP_Header
argument_list|)
argument_list|,
operator|(
name|unsigned
name|char
operator|*
operator|)
name|IP_Header
argument_list|)
expr_stmt|;
name|ip_files
index|[
name|fd
index|]
operator|=
name|Yes
expr_stmt|;
block|}
block|}
end_block

begin_comment
comment|/*  *  ip_raw_select(fd) - same as ip_select, but no header is placed at the  *			front of the file.  */
end_comment

begin_macro
name|ip_raw_select
argument_list|(
argument|fd
argument_list|)
end_macro

begin_decl_stmt
name|int
name|fd
decl_stmt|;
end_decl_stmt

begin_block
block|{
comment|/* trick ip_select into thinking that it is already initialized */
name|ip_files
index|[
name|fd
index|]
operator|=
name|Yes
expr_stmt|;
comment|/* do a normal select */
name|ip_select
argument_list|(
name|fd
argument_list|)
expr_stmt|;
block|}
end_block

begin_macro
name|ip_close
argument_list|()
end_macro

begin_block
block|{
if|if
condition|(
name|ip_fd
operator|!=
operator|-
literal|1
condition|)
block|{
name|ip_flush
argument_list|()
expr_stmt|;
name|ip_files
index|[
name|ip_fd
index|]
operator|=
name|No
expr_stmt|;
name|close
argument_list|(
name|ip_fd
argument_list|)
expr_stmt|;
name|ip_fd
operator|=
operator|-
literal|1
expr_stmt|;
block|}
block|}
end_block

begin_macro
name|ip_flush
argument_list|()
end_macro

begin_block
block|{
comment|/* flush the buffer */
if|if
condition|(
name|ip_Buffsize
operator|-
name|ip_bytecnt
operator|>
literal|0
condition|)
block|{
name|write
argument_list|(
name|ip_fd
argument_list|,
name|ip_filebuff
argument_list|,
name|ip_bytecnt
argument_list|)
expr_stmt|;
block|}
block|}
end_block

end_unit

