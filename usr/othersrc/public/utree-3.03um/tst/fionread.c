begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  *      FIONREAD.C  *      Test the FIONREAD ioctl system call  *      klin, Mon Feb 24 20:29:50 1992  *  *      Defs:   Define BSD for BSD systems.  *      Test:   Enter some chars (don't forget<RETURN> !)  *              and see the result from ioctl(FIONREAD).  *              If some characters were entered, there should be  *              displayed a message with the number of entered chars  *              and the entered string!  */
end_comment

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_ifndef
ifndef|#
directive|ifndef
name|BSD
end_ifndef

begin_include
include|#
directive|include
file|<sys/termio.h>
end_include

begin_comment
comment|/* FIONREAD may be defined here */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<sys/ioctl.h>
end_include

begin_comment
comment|/*          or here (like BSD)  */
end_comment

begin_include
include|#
directive|include
file|<sys/filio.h>
end_include

begin_comment
comment|/*  *      Main routine  */
end_comment

begin_function
name|main
parameter_list|()
block|{
name|char
name|buf
index|[
literal|256
index|]
decl_stmt|;
name|int
name|rv
decl_stmt|,
name|nc
decl_stmt|;
comment|/* Terminate with BREAK ! */
while|while
condition|(
literal|1
condition|)
block|{
name|printf
argument_list|(
literal|"\nWAITING FOR INPUT ...\n"
argument_list|)
expr_stmt|;
name|fflush
argument_list|(
name|stdout
argument_list|)
expr_stmt|;
comment|/* Wait 5 seconds for entering input */
name|sleep
argument_list|(
literal|5
argument_list|)
expr_stmt|;
name|rv
operator|=
name|ioctl
argument_list|(
literal|0
argument_list|,
name|FIONREAD
argument_list|,
operator|&
name|nc
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"\nIOCTL(FIONREAD) rv=%d nc=%d "
argument_list|,
name|rv
argument_list|,
name|nc
argument_list|)
expr_stmt|;
comment|/* OK: chars read! */
if|if
condition|(
name|nc
operator|>
literal|0
condition|)
block|{
comment|/* Fill and display read characters */
name|gets
argument_list|(
name|buf
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"buf=[%s]\n"
argument_list|,
name|buf
argument_list|)
expr_stmt|;
block|}
else|else
comment|/* Should not happen on input if ioctl(FIONREAD) works! */
name|printf
argument_list|(
literal|"NO INPUT\n"
argument_list|)
expr_stmt|;
block|}
block|}
end_function

begin_comment
comment|/* main() */
end_comment

end_unit

