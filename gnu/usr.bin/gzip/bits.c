begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* bits.c -- output variable-length bit strings  * Copyright (C) 1992-1993 Jean-loup Gailly  * This is free software; you can redistribute it and/or modify it under the  * terms of the GNU General Public License, see the file COPYING.  */
end_comment

begin_comment
comment|/*  *  PURPOSE  *  *      Output variable-length bit strings. Compression can be done  *      to a file or to memory. (The latter is not supported in this version.)  *  *  DISCUSSION  *  *      The PKZIP "deflate" file format interprets compressed file data  *      as a sequence of bits.  Multi-bit strings in the file may cross  *      byte boundaries without restriction.  *  *      The first bit of each byte is the low-order bit.  *  *      The routines in this file allow a variable-length bit value to  *      be output right-to-left (useful for literal values). For  *      left-to-right output (useful for code strings from the tree routines),  *      the bits must have been reversed first with bi_reverse().  *  *      For in-memory compression, the compressed bit stream goes directly  *      into the requested output buffer. The input data is read in blocks  *      by the mem_read() function. The buffer is limited to 64K on 16 bit  *      machines.  *  *  INTERFACE  *  *      void bi_init (FILE *zipfile)  *          Initialize the bit string routines.  *  *      void send_bits (int value, int length)  *          Write out a bit string, taking the source bits right to  *          left.  *  *      int bi_reverse (int value, int length)  *          Reverse the bits of a bit string, taking the source bits left to  *          right and emitting them right to left.  *  *      void bi_windup (void)  *          Write out any remaining bits in an incomplete byte.  *  *      void copy_block(char *buf, unsigned len, int header)  *          Copy a stored block to the zip file, storing first the length and  *          its one's complement if requested.  *  */
end_comment

begin_include
include|#
directive|include
file|"tailor.h"
end_include

begin_include
include|#
directive|include
file|"gzip.h"
end_include

begin_include
include|#
directive|include
file|"crypt.h"
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|DEBUG
end_ifdef

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|RCSID
end_ifdef

begin_decl_stmt
specifier|static
name|char
name|rcsid
index|[]
init|=
literal|"$FreeBSD$"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ===========================================================================  * Local data used by the "bit string" routines.  */
end_comment

begin_decl_stmt
name|local
name|file_t
name|zfile
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* output gzip file */
end_comment

begin_decl_stmt
name|local
name|unsigned
name|short
name|bi_buf
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Output buffer. bits are inserted starting at the bottom (least significant  * bits).  */
end_comment

begin_define
define|#
directive|define
name|Buf_size
value|(8 * 2*sizeof(char))
end_define

begin_comment
comment|/* Number of bits used within bi_buf. (bi_buf might be implemented on  * more than 16 bits on some systems.)  */
end_comment

begin_decl_stmt
name|local
name|int
name|bi_valid
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Number of valid bits in bi_buf.  All bits above the last valid bit  * are always zero.  */
end_comment

begin_macro
name|int
argument_list|(
argument|*read_buf
argument_list|)
end_macro

begin_expr_stmt
name|OF
argument_list|(
operator|(
name|char
operator|*
name|buf
operator|,
name|unsigned
name|size
operator|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* Current input function. Set to mem_read for in-memory compression */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|DEBUG
end_ifdef

begin_decl_stmt
name|ulg
name|bits_sent
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* bit length of the compressed data */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ===========================================================================  * Initialize the bit string routines.  */
end_comment

begin_function
name|void
name|bi_init
parameter_list|(
name|zipfile
parameter_list|)
name|file_t
name|zipfile
decl_stmt|;
comment|/* output zip file, NO_FILE for in-memory compression */
block|{
name|zfile
operator|=
name|zipfile
expr_stmt|;
name|bi_buf
operator|=
literal|0
expr_stmt|;
name|bi_valid
operator|=
literal|0
expr_stmt|;
ifdef|#
directive|ifdef
name|DEBUG
name|bits_sent
operator|=
literal|0L
expr_stmt|;
endif|#
directive|endif
comment|/* Set the defaults for file compression. They are set by memcompress      * for in-memory compression.      */
if|if
condition|(
name|zfile
operator|!=
name|NO_FILE
condition|)
block|{
name|read_buf
operator|=
name|file_read
expr_stmt|;
block|}
block|}
end_function

begin_comment
comment|/* ===========================================================================  * Send a value on a given number of bits.  * IN assertion: length<= 16 and value fits in length bits.  */
end_comment

begin_function
name|void
name|send_bits
parameter_list|(
name|value
parameter_list|,
name|length
parameter_list|)
name|int
name|value
decl_stmt|;
comment|/* value to send */
name|int
name|length
decl_stmt|;
comment|/* number of bits */
block|{
ifdef|#
directive|ifdef
name|DEBUG
name|Tracev
argument_list|(
operator|(
name|stderr
operator|,
literal|" l %2d v %4x "
operator|,
name|length
operator|,
name|value
operator|)
argument_list|)
expr_stmt|;
name|Assert
argument_list|(
name|length
operator|>
literal|0
operator|&&
name|length
operator|<=
literal|15
argument_list|,
literal|"invalid length"
argument_list|)
expr_stmt|;
name|bits_sent
operator|+=
operator|(
name|ulg
operator|)
name|length
expr_stmt|;
endif|#
directive|endif
comment|/* If not enough room in bi_buf, use (valid) bits from bi_buf and      * (16 - bi_valid) bits from value, leaving (width - (16-bi_valid))      * unused bits in value.      */
if|if
condition|(
name|bi_valid
operator|>
operator|(
name|int
operator|)
name|Buf_size
operator|-
name|length
condition|)
block|{
name|bi_buf
operator||=
operator|(
name|value
operator|<<
name|bi_valid
operator|)
expr_stmt|;
name|put_short
argument_list|(
name|bi_buf
argument_list|)
expr_stmt|;
name|bi_buf
operator|=
operator|(
name|ush
operator|)
name|value
operator|>>
operator|(
name|Buf_size
operator|-
name|bi_valid
operator|)
expr_stmt|;
name|bi_valid
operator|+=
name|length
operator|-
name|Buf_size
expr_stmt|;
block|}
else|else
block|{
name|bi_buf
operator||=
name|value
operator|<<
name|bi_valid
expr_stmt|;
name|bi_valid
operator|+=
name|length
expr_stmt|;
block|}
block|}
end_function

begin_comment
comment|/* ===========================================================================  * Reverse the first len bits of a code, using straightforward code (a faster  * method would use a table)  * IN assertion: 1<= len<= 15  */
end_comment

begin_function
name|unsigned
name|bi_reverse
parameter_list|(
name|code
parameter_list|,
name|len
parameter_list|)
name|unsigned
name|code
decl_stmt|;
comment|/* the value to invert */
name|int
name|len
decl_stmt|;
comment|/* its bit length */
block|{
specifier|register
name|unsigned
name|res
init|=
literal|0
decl_stmt|;
do|do
block|{
name|res
operator||=
name|code
operator|&
literal|1
expr_stmt|;
name|code
operator|>>=
literal|1
operator|,
name|res
operator|<<=
literal|1
expr_stmt|;
block|}
do|while
condition|(
operator|--
name|len
operator|>
literal|0
condition|)
do|;
return|return
name|res
operator|>>
literal|1
return|;
block|}
end_function

begin_comment
comment|/* ===========================================================================  * Write out any remaining bits in an incomplete byte.  */
end_comment

begin_function
name|void
name|bi_windup
parameter_list|()
block|{
if|if
condition|(
name|bi_valid
operator|>
literal|8
condition|)
block|{
name|put_short
argument_list|(
name|bi_buf
argument_list|)
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|bi_valid
operator|>
literal|0
condition|)
block|{
name|put_byte
argument_list|(
name|bi_buf
argument_list|)
expr_stmt|;
block|}
name|bi_buf
operator|=
literal|0
expr_stmt|;
name|bi_valid
operator|=
literal|0
expr_stmt|;
ifdef|#
directive|ifdef
name|DEBUG
name|bits_sent
operator|=
operator|(
name|bits_sent
operator|+
literal|7
operator|)
operator|&
operator|~
literal|7
expr_stmt|;
endif|#
directive|endif
block|}
end_function

begin_comment
comment|/* ===========================================================================  * Copy a stored block to the zip file, storing first the length and its  * one's complement if requested.  */
end_comment

begin_function
name|void
name|copy_block
parameter_list|(
name|buf
parameter_list|,
name|len
parameter_list|,
name|header
parameter_list|)
name|char
modifier|*
name|buf
decl_stmt|;
comment|/* the input data */
name|unsigned
name|len
decl_stmt|;
comment|/* its length */
name|int
name|header
decl_stmt|;
comment|/* true if block header must be written */
block|{
name|bi_windup
argument_list|()
expr_stmt|;
comment|/* align on byte boundary */
if|if
condition|(
name|header
condition|)
block|{
name|put_short
argument_list|(
operator|(
name|ush
operator|)
name|len
argument_list|)
expr_stmt|;
name|put_short
argument_list|(
operator|(
name|ush
operator|)
operator|~
name|len
argument_list|)
expr_stmt|;
ifdef|#
directive|ifdef
name|DEBUG
name|bits_sent
operator|+=
literal|2
operator|*
literal|16
expr_stmt|;
endif|#
directive|endif
block|}
ifdef|#
directive|ifdef
name|DEBUG
name|bits_sent
operator|+=
operator|(
name|ulg
operator|)
name|len
operator|<<
literal|3
expr_stmt|;
endif|#
directive|endif
while|while
condition|(
name|len
operator|--
condition|)
block|{
ifdef|#
directive|ifdef
name|CRYPT
name|int
name|t
decl_stmt|;
if|if
condition|(
name|key
condition|)
name|zencode
argument_list|(
operator|*
name|buf
argument_list|,
name|t
argument_list|)
expr_stmt|;
endif|#
directive|endif
name|put_byte
argument_list|(
operator|*
name|buf
operator|++
argument_list|)
expr_stmt|;
block|}
block|}
end_function

end_unit

