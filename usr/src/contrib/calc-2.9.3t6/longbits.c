begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * longbits - Determine the number if bits in a long  *  * Not all (in fact very few) C pre-processors can do:  *  *	#if sizeof(long) == 8  *  * so we have to form LONG_BITS ahead of time.  */
end_comment

begin_comment
comment|/*  * Copyright (c) 1994 by Landon Curt Noll.  All Rights Reserved.  *  * Permission to use, copy, modify, and distribute this software and  * its documentation for any purpose and without fee is hereby granted,  * provided that the above copyright, this permission notice and text  * this comment, and the disclaimer below appear in all of the following:  *  *	supporting documentation  *	source copies  *	source works derived from this source  *	binaries derived from this source or from derived source  *  * LANDON CURT NOLL DISCLAIMS ALL WARRANTIES WITH REGARD TO THIS SOFTWARE,  * INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS. IN NO  * EVENT SHALL LANDON CURT NOLL BE LIABLE FOR ANY SPECIAL, INDIRECT OR  * CONSEQUENTIAL DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM LOSS OF  * USE, DATA OR PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE OR  * OTHER TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR  * PERFORMANCE OF THIS SOFTWARE.  *  * chongo was here	/\../\  */
end_comment

begin_function
name|main
parameter_list|()
block|{
name|printf
argument_list|(
literal|"#undef LONG_BITS\n"
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"#define LONG_BITS %ld\n"
argument_list|,
sizeof|sizeof
argument_list|(
name|long
argument_list|)
operator|*
literal|8
argument_list|)
expr_stmt|;
name|exit
argument_list|(
literal|0
argument_list|)
expr_stmt|;
block|}
end_function

end_unit

