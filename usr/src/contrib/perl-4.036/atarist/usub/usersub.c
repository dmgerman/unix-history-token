begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $RCSfile: usersub.c,v $$Revision: 4.0.1.1 $$Date: 92/06/08 11:54:52 $  *  * $Log:	usersub.c,v $  * Revision 4.0.1.1  92/06/08  11:54:52  lwall  * Initial revision  *   * Revision 4.0.1.1  91/11/05  19:07:24  lwall  * patch11: there are now subroutines for calling back from C into Perl  *   * Revision 4.0  91/03/20  01:56:34  lwall  * 4.0 baseline.  *   * Revision 3.0.1.1  90/08/09  04:06:10  lwall  * patch19: Initial revision  *   */
end_comment

begin_include
include|#
directive|include
file|"EXTERN.h"
end_include

begin_include
include|#
directive|include
file|"perl.h"
end_include

begin_function
name|int
name|userinit
parameter_list|()
block|{
name|install_null
argument_list|()
expr_stmt|;
comment|/* install device /dev/null or NUL: */
name|init_curses
argument_list|()
expr_stmt|;
return|return
literal|0
return|;
block|}
end_function

end_unit

