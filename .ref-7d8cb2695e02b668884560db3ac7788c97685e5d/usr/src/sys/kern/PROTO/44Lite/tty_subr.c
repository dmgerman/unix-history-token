begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1982, 1986, 1991 The Regents of the University of California.  * All rights reserved.  *  * %sccs.include.redist.c%  *  *	from: @(#)tty_subr.c	7.7 (Berkeley) 5/9/91  */
end_comment

begin_include
include|#
directive|include
file|"param.h"
end_include

begin_include
include|#
directive|include
file|"systm.h"
end_include

begin_include
include|#
directive|include
file|"buf.h"
end_include

begin_include
include|#
directive|include
file|"ioctl.h"
end_include

begin_include
include|#
directive|include
file|"tty.h"
end_include

begin_include
include|#
directive|include
file|"clist.h"
end_include

begin_comment
comment|/*  * Initialize clists.  */
end_comment

begin_macro
name|cinit
argument_list|()
end_macro

begin_block
block|{
comment|/* 	 * Body deleted. 	 */
block|}
end_block

begin_comment
comment|/*  * Get a character from a clist.  */
end_comment

begin_macro
name|getc
argument_list|(
argument|clp
argument_list|)
end_macro

begin_decl_stmt
name|struct
name|clist
modifier|*
name|clp
decl_stmt|;
end_decl_stmt

begin_block
block|{
name|char
name|c
decl_stmt|;
comment|/* 	 * Body deleted. 	 */
return|return
operator|(
name|c
operator|)
return|;
block|}
end_block

begin_comment
comment|/*  * Copy clist to buffer.  * Return number of bytes moved.  */
end_comment

begin_macro
name|q_to_b
argument_list|(
argument|clp
argument_list|,
argument|cp
argument_list|,
argument|count
argument_list|)
end_macro

begin_decl_stmt
name|struct
name|clist
modifier|*
name|clp
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|cp
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|count
decl_stmt|;
end_decl_stmt

begin_block
block|{
name|int
name|s
decl_stmt|,
name|moved
init|=
literal|0
decl_stmt|;
if|if
condition|(
name|count
operator|<=
literal|0
condition|)
return|return
operator|(
literal|0
operator|)
return|;
name|s
operator|=
name|spltty
argument_list|()
expr_stmt|;
comment|/* 	 * Body deleted. 	 */
name|splx
argument_list|(
name|s
argument_list|)
expr_stmt|;
return|return
operator|(
name|moved
operator|)
return|;
block|}
end_block

begin_comment
comment|/*  * Return count of contiguous characters in clist.  * Stop counting if flag&character is non-null.  */
end_comment

begin_macro
name|ndqb
argument_list|(
argument|clp
argument_list|,
argument|flag
argument_list|)
end_macro

begin_decl_stmt
name|struct
name|clist
modifier|*
name|clp
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|flag
decl_stmt|;
end_decl_stmt

begin_block
block|{
name|int
name|count
init|=
literal|0
decl_stmt|;
name|int
name|s
decl_stmt|;
name|s
operator|=
name|spltty
argument_list|()
expr_stmt|;
comment|/* 	 * Body deleted. 	 */
name|splx
argument_list|(
name|s
argument_list|)
expr_stmt|;
return|return
operator|(
name|count
operator|)
return|;
block|}
end_block

begin_comment
comment|/*  * Flush count bytes from clist.  */
end_comment

begin_macro
name|ndflush
argument_list|(
argument|clp
argument_list|,
argument|count
argument_list|)
end_macro

begin_decl_stmt
name|struct
name|clist
modifier|*
name|clp
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|count
decl_stmt|;
end_decl_stmt

begin_block
block|{
name|int
name|s
decl_stmt|;
name|s
operator|=
name|spltty
argument_list|()
expr_stmt|;
comment|/* 	 * Body deleted. 	 */
name|splx
argument_list|(
name|s
argument_list|)
expr_stmt|;
block|}
end_block

begin_comment
comment|/*  * Put a character into the output queue.  */
end_comment

begin_macro
name|putc
argument_list|(
argument|c
argument_list|,
argument|clp
argument_list|)
end_macro

begin_decl_stmt
name|char
name|c
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|clist
modifier|*
name|clp
decl_stmt|;
end_decl_stmt

begin_block
block|{
name|int
name|s
decl_stmt|,
name|error
init|=
literal|0
decl_stmt|;
name|s
operator|=
name|spltty
argument_list|()
expr_stmt|;
comment|/* 	 * Body deleted. 	 */
if|if
condition|(
name|error
condition|)
block|{
name|splx
argument_list|(
name|s
argument_list|)
expr_stmt|;
return|return
operator|(
operator|-
literal|1
operator|)
return|;
block|}
name|splx
argument_list|(
name|s
argument_list|)
expr_stmt|;
return|return
operator|(
literal|0
operator|)
return|;
block|}
end_block

begin_comment
comment|/*  * Copy buffer to clist.  * Return number of bytes not transfered.  */
end_comment

begin_macro
name|b_to_q
argument_list|(
argument|cp
argument_list|,
argument|count
argument_list|,
argument|clp
argument_list|)
end_macro

begin_decl_stmt
name|char
modifier|*
name|cp
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|count
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|clist
modifier|*
name|clp
decl_stmt|;
end_decl_stmt

begin_block
block|{
name|int
name|s
decl_stmt|,
name|resid
decl_stmt|;
if|if
condition|(
name|count
operator|<=
literal|0
condition|)
return|return
operator|(
literal|0
operator|)
return|;
name|resid
operator|=
name|count
expr_stmt|;
name|s
operator|=
name|spltty
argument_list|()
expr_stmt|;
comment|/* 	 * Body deleted. 	 */
name|splx
argument_list|(
name|s
argument_list|)
expr_stmt|;
return|return
operator|(
name|resid
operator|)
return|;
block|}
end_block

begin_comment
comment|/*  * Given a non-NULL pointer into the clist return the pointer  * to the next character in the list or return NULL if no more chars.  *  * Callers must not allow getc's to happen between nextc's so that the  * pointer becomes invalid.  Note that interrupts are NOT masked.  */
end_comment

begin_function
name|char
modifier|*
name|nextc
parameter_list|(
name|clp
parameter_list|,
name|cp
parameter_list|,
name|count
parameter_list|)
name|struct
name|clist
modifier|*
name|clp
decl_stmt|;
name|char
modifier|*
name|cp
decl_stmt|;
name|int
modifier|*
name|count
decl_stmt|;
block|{
name|int
name|empty
init|=
literal|0
decl_stmt|;
comment|/* 	 * Body deleted. 	 */
if|if
condition|(
operator|!
name|empty
condition|)
return|return
operator|(
name|cp
operator|)
return|;
return|return
operator|(
literal|0
operator|)
return|;
block|}
end_function

begin_comment
comment|/*  * Remove the last character in the clist and return it.  */
end_comment

begin_macro
name|unputc
argument_list|(
argument|clp
argument_list|)
end_macro

begin_decl_stmt
name|struct
name|clist
modifier|*
name|clp
decl_stmt|;
end_decl_stmt

begin_block
block|{
name|char
name|c
decl_stmt|;
name|int
name|s
decl_stmt|;
name|s
operator|=
name|spltty
argument_list|()
expr_stmt|;
comment|/* 	 * Body deleted. 	 */
name|splx
argument_list|(
name|s
argument_list|)
expr_stmt|;
return|return
operator|(
name|c
operator|)
return|;
block|}
end_block

begin_comment
comment|/*  * Put the chars in the from queue on the end of the to queue.  */
end_comment

begin_macro
name|catq
argument_list|(
argument|from
argument_list|,
argument|to
argument_list|)
end_macro

begin_decl_stmt
name|struct
name|clist
modifier|*
name|from
decl_stmt|,
modifier|*
name|to
decl_stmt|;
end_decl_stmt

begin_block
block|{
name|char
name|c
decl_stmt|;
while|while
condition|(
operator|(
name|c
operator|=
name|getc
argument_list|(
name|from
argument_list|)
operator|)
operator|>=
literal|0
condition|)
name|putc
argument_list|(
name|c
argument_list|,
name|to
argument_list|)
expr_stmt|;
block|}
end_block

end_unit

