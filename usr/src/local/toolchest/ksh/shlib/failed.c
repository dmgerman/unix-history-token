begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*   *      Copyright (c) 1984, 1985, 1986 AT&T  *      All Rights Reserved   *      THIS IS UNPUBLISHED PROPRIETARY SOURCE   *      CODE OF AT&T.  *      The copyright notice above does not   *      evidence any actual or intended  *      publication of such source code.   */
end_comment

begin_comment
comment|/* @(#)failed.c	1.1 */
end_comment

begin_comment
comment|/*  *   FAILED.C  *  *   Programmer:  D. A. Lambeth  *  *        Owner:  D. A. Lambeth  *  *         Date:  April 17, 1980  *  *  *  *   FAILED (S1, S2)  *  *        Program Failure.  Print an error diagnostic containing  *        the strings S1 and S2, and longjmp to an error-handling  *        routine.  *  *  *  *   See Also:  SETJMP(3C)  */
end_comment

begin_comment
comment|/*  *   FAILED (S1, S2)  *  *        char *S1;  *  *        char *S2;  *  *   Print an error message of the format  *  *        S1 : S2  *  *   at the stderr file.  *  *   Longjmp to the location errshell, which must have been  *   established previously by a call to setjmp.  *  *   Note that the return value from setjmp will always be  *   '1'.  */
end_comment

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_include
include|#
directive|include
file|<setjmp.h>
end_include

begin_decl_stmt
specifier|extern
name|jmp_buf
name|errshell
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
name|colon
index|[]
decl_stmt|,
name|newline
index|[]
decl_stmt|;
end_decl_stmt

begin_function
name|void
name|failed
parameter_list|(
name|s1
parameter_list|,
name|s2
parameter_list|)
name|char
modifier|*
name|s1
decl_stmt|,
decl|*
name|s2
decl_stmt|;
end_function

begin_block
block|{
name|write
argument_list|(
literal|2
argument_list|,
name|s1
argument_list|,
name|strlen
argument_list|(
name|s1
argument_list|)
argument_list|)
expr_stmt|;
if|if
condition|(
name|s2
condition|)
block|{
name|write
argument_list|(
literal|2
argument_list|,
name|colon
argument_list|,
name|strlen
argument_list|(
name|colon
argument_list|)
argument_list|)
expr_stmt|;
name|write
argument_list|(
literal|2
argument_list|,
name|s2
argument_list|,
name|strlen
argument_list|(
name|s2
argument_list|)
argument_list|)
expr_stmt|;
block|}
name|write
argument_list|(
literal|2
argument_list|,
name|newline
argument_list|,
name|strlen
argument_list|(
name|newline
argument_list|)
argument_list|)
expr_stmt|;
name|longjmp
argument_list|(
name|errshell
argument_list|,
literal|1
argument_list|)
expr_stmt|;
block|}
end_block

end_unit

