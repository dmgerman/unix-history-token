begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  *      SIGWINCH.C  *      Test signal SIGWINCH and TIOCGWINSZ ioctl system call  *      klin, Mon Feb 24 20:35:53 1992  *  *      Defs:   Define BSD for BSD systems.  *      Test:   Start sigwinch under X in a xterm window and resize  *              the window sometimes. After resizing there should be  *              sent a signal SIGWINCH from the kernel which is catched  *              by the sigwinch signal handler. The ioctl(TIOCGWINSZ)  *              systemcalls should return the new size of the window.  */
end_comment

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_include
include|#
directive|include
file|<signal.h>
end_include

begin_include
include|#
directive|include
file|<sys/types.h>
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
comment|/* struct winsize may be defined here */
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
comment|/*                or here (like BSD)  */
end_comment

begin_comment
comment|/*  *      Signal handler for signal SIGWINCH  */
end_comment

begin_macro
name|sigwinch
argument_list|(
argument|sig
argument_list|)
end_macro

begin_decl_stmt
name|int
name|sig
decl_stmt|;
end_decl_stmt

begin_block
block|{
name|struct
name|winsize
name|ws
decl_stmt|;
name|int
name|rv
decl_stmt|;
name|signal
argument_list|(
name|SIGWINCH
argument_list|,
name|sigwinch
argument_list|)
expr_stmt|;
if|if
condition|(
name|sig
condition|)
name|printf
argument_list|(
literal|"SIGWINCH-HANDLER: sig=%d\n"
argument_list|,
name|sig
argument_list|)
expr_stmt|;
name|rv
operator|=
name|ioctl
argument_list|(
literal|0
argument_list|,
name|TIOCGWINSZ
argument_list|,
operator|&
name|ws
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"IOCTL: rv=%d rows=%d cols=%d\n"
argument_list|,
name|rv
argument_list|,
name|ws
operator|.
name|ws_row
argument_list|,
name|ws
operator|.
name|ws_col
argument_list|)
expr_stmt|;
block|}
end_block

begin_comment
comment|/* sigwinch() */
end_comment

begin_comment
comment|/*  *      Main routine  */
end_comment

begin_function
name|main
parameter_list|()
block|{
name|sigwinch
argument_list|(
literal|0
argument_list|)
expr_stmt|;
while|while
condition|(
literal|1
condition|)
empty_stmt|;
block|}
end_function

begin_comment
comment|/* main() */
end_comment

end_unit

