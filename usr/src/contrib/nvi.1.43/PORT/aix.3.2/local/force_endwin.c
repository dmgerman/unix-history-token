begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|<sys/queue.h>
end_include

begin_include
include|#
directive|include
file|<sys/time.h>
end_include

begin_include
include|#
directive|include
file|<bitstring.h>
end_include

begin_include
include|#
directive|include
file|<curses.h>
end_include

begin_include
include|#
directive|include
file|<signal.h>
end_include

begin_include
include|#
directive|include
file|"compat.h"
end_include

begin_include
include|#
directive|include
file|<db.h>
end_include

begin_include
include|#
directive|include
file|<regex.h>
end_include

begin_include
include|#
directive|include
file|"vi.h"
end_include

begin_function
name|int
name|force_endwin
parameter_list|()
block|{
name|int
name|rval
decl_stmt|;
undef|#
directive|undef
name|endwin
name|rval
operator|=
name|endwin
argument_list|()
expr_stmt|;
comment|/* 	 * Some (many...) System V derived implementations of curses will 	 * not reset the terminal modes correctly if you do any tgetent(3) 	 * style calls.   We can often get around this by using the System 	 * V tiget(3) style calls, but in some implementations they're not 	 * available.  So, we have to reset the terminal modes explicitly 	 * when endin is called. 	 */
call|(
name|void
call|)
argument_list|(
name|tcsetattr
argument_list|(
name|STDIN_FILENO
argument_list|,
name|TCSASOFT
operator||
name|TCSADRAIN
argument_list|,
operator|&
name|__global_list
operator|->
name|original_termios
argument_list|)
argument_list|)
expr_stmt|;
return|return
operator|(
name|rval
operator|)
return|;
block|}
end_function

end_unit

