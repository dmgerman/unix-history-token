begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* NOCW */
end_comment

begin_comment
comment|/* dggccbug.c */
end_comment

begin_comment
comment|/* bug found by Eric Young (eay@cryptsoft.com) - May 1995 */
end_comment

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_comment
comment|/* There is a bug in  * gcc version 2.5.8 (88open OCS/BCS, DG-2.5.8.3, Oct 14 1994)  * as shipped with DGUX 5.4R3.10 that can be bypassed by defining  * DG_GCC_BUG in my code.  * The bug manifests itself by the vaule of a pointer that is  * used only by reference, not having it's value change when it is used  * to check for exiting the loop.  Probably caused by there being 2  * copies of the valiable, one in a register and one being an address  * that is passed. */
end_comment

begin_comment
comment|/* compare the out put from  * gcc dggccbug.c; ./a.out  * and  * gcc -O dggccbug.c; ./a.out  * compile with -DFIXBUG to remove the bug when optimising.  */
end_comment

begin_function
name|void
name|inc
parameter_list|(
name|a
parameter_list|)
name|int
modifier|*
name|a
decl_stmt|;
block|{
operator|(
operator|*
name|a
operator|)
operator|++
expr_stmt|;
block|}
end_function

begin_function
name|main
parameter_list|()
block|{
name|int
name|p
init|=
literal|0
decl_stmt|;
ifdef|#
directive|ifdef
name|FIXBUG
name|int
name|dummy
decl_stmt|;
endif|#
directive|endif
while|while
condition|(
name|p
operator|<
literal|3
condition|)
block|{
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"%08X\n"
argument_list|,
name|p
argument_list|)
expr_stmt|;
name|inc
argument_list|(
operator|&
name|p
argument_list|)
expr_stmt|;
ifdef|#
directive|ifdef
name|FIXBUG
name|dummy
operator|+=
name|p
expr_stmt|;
endif|#
directive|endif
block|}
block|}
end_function

end_unit

