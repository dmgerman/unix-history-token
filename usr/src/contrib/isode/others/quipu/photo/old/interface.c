begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* interface.c - bit manipulation utility routines */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|lint
end_ifndef

begin_decl_stmt
specifier|static
name|char
modifier|*
name|rcsid
init|=
literal|"$Header: /f/osi/others/quipu/photo/RCS/interface.c,v 7.0 89/11/23 22:01:44 mrose Rel $"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*   * $Header: /f/osi/others/quipu/photo/RCS/interface.c,v 7.0 89/11/23 22:01:44 mrose Rel $  *  *  * $Log:	interface.c,v $  * Revision 7.0  89/11/23  22:01:44  mrose  * Release 6.0  *   */
end_comment

begin_comment
comment|/*  *				  NOTICE  *  *    Acquisition, use, and distribution of this module and related  *    materials are subject to the restrictions of a license agreement.  *    Consult the Preface in the User's Manual for the full terms of  *    this agreement.  *  */
end_comment

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_include
include|#
directive|include
file|"quipu/photo.h"
end_include

begin_comment
comment|/* This file contains utility routines used by both the                 */
end_comment

begin_comment
comment|/* encoding and decoding programs.                                      */
end_comment

begin_comment
comment|/* The routines are concerned with getting and setting bits of          */
end_comment

begin_comment
comment|/* a bit string.                                                        */
end_comment

begin_comment
comment|/* All these routine work in basically the same way. /* a mask is used to get at each individual bit within /* a byte.  Each time the next bit is required, the /* mask is shifted right, when the mask is zero, the byte is either /* written to the file, or the next byte read in depending upon the /* routine. */
end_comment

begin_decl_stmt
name|int
name|PIC_LINESIZE
decl_stmt|,
name|STOP
decl_stmt|,
name|NUMLINES
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* ROUTINE:     Get_bit                                                 */
end_comment

begin_comment
comment|/*                                                                      */
end_comment

begin_comment
comment|/* SYNOPSIS:    Gets the next bit from the input.                       */
end_comment

begin_comment
comment|/*              Returns 0 if it is a zero.                              */
end_comment

begin_comment
comment|/*              Returns 1 if it is a one                                */
end_comment

begin_function
name|char
name|get_bit
parameter_list|(
name|lineptr
parameter_list|)
name|bit_string
modifier|*
name|lineptr
decl_stmt|;
comment|/* the line to get the bit from */
block|{
name|unsigned
name|char
name|result
decl_stmt|;
comment|/* Anding the mask and the data gives a 0 if the bit masked is 0, 1 otherwis e */
name|result
operator|=
name|lineptr
operator|->
name|mask
operator|&
name|lineptr
operator|->
name|pos
expr_stmt|;
name|lineptr
operator|->
name|mask
operator|>>=
literal|1
expr_stmt|;
if|if
condition|(
name|lineptr
operator|->
name|mask
operator|==
literal|0
condition|)
block|{
name|lineptr
operator|->
name|pos
operator|=
operator|*
name|lineptr
operator|->
name|dbuf
operator|++
expr_stmt|;
name|lineptr
operator|->
name|mask
operator|=
name|BIT_MASK
expr_stmt|;
block|}
if|if
condition|(
name|result
operator|!=
literal|0
condition|)
comment|/* may not be 1, may be 0001000 for example */
name|result
operator|=
literal|1
expr_stmt|;
return|return
operator|(
operator|(
name|char
operator|)
name|result
operator|)
return|;
block|}
end_function

begin_comment
comment|/* ROUTINE:   Set_bit                                                   */
end_comment

begin_comment
comment|/*                                                                      */
end_comment

begin_comment
comment|/* SYNOPSIS:  Sets the next bit of the bit string pointed to by         */
end_comment

begin_comment
comment|/*            lineptr to a one.                                         */
end_comment

begin_macro
name|set_bit
argument_list|(
argument|lineptr
argument_list|)
end_macro

begin_decl_stmt
name|bit_string
modifier|*
name|lineptr
decl_stmt|;
end_decl_stmt

begin_block
block|{
comment|/* This sets the masked bit */
name|lineptr
operator|->
name|pos
operator||=
name|lineptr
operator|->
name|mask
expr_stmt|;
name|lineptr
operator|->
name|mask
operator|>>=
literal|1
expr_stmt|;
if|if
condition|(
name|lineptr
operator|->
name|mask
operator|==
literal|0
condition|)
block|{
operator|*
name|lineptr
operator|->
name|dbuf
operator|++
operator|=
name|lineptr
operator|->
name|pos
expr_stmt|;
name|lineptr
operator|->
name|mask
operator|=
name|BIT_MASK
expr_stmt|;
block|}
block|}
end_block

begin_comment
comment|/* ROUTINE:   Clr_bit                                                   */
end_comment

begin_comment
comment|/*                                                                      */
end_comment

begin_comment
comment|/* SYNOPSIS:  clears the next bit of the bit string pointed to by       */
end_comment

begin_comment
comment|/*            lineptr.  i.e set it to zero.                             */
end_comment

begin_macro
name|clr_bit
argument_list|(
argument|lineptr
argument_list|)
end_macro

begin_decl_stmt
name|bit_string
modifier|*
name|lineptr
decl_stmt|;
end_decl_stmt

begin_block
block|{
comment|/* clear the masked bit */
name|lineptr
operator|->
name|pos
operator|&=
operator|~
operator|(
name|lineptr
operator|->
name|mask
operator|)
expr_stmt|;
name|lineptr
operator|->
name|mask
operator|>>=
literal|1
expr_stmt|;
comment|/* right shift the mask */
if|if
condition|(
name|lineptr
operator|->
name|mask
operator|==
literal|0
condition|)
block|{
comment|/* may need to move on to the next byte */
operator|*
name|lineptr
operator|->
name|dbuf
operator|++
operator|=
name|lineptr
operator|->
name|pos
expr_stmt|;
name|lineptr
operator|->
name|mask
operator|=
name|BIT_MASK
expr_stmt|;
block|}
block|}
end_block

end_unit

