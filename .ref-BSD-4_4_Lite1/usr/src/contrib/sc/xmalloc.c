begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * A safer saner malloc, for careless programmers  * $Revision: 6.8 $  */
end_comment

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_include
include|#
directive|include
file|<curses.h>
end_include

begin_include
include|#
directive|include
file|"sc.h"
end_include

begin_function_decl
specifier|extern
name|char
modifier|*
name|malloc
parameter_list|()
function_decl|;
end_function_decl

begin_ifdef
ifdef|#
directive|ifdef
name|SYSV3
end_ifdef

begin_function_decl
specifier|extern
name|void
name|free
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|exit
parameter_list|()
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_function
name|char
modifier|*
name|xmalloc
parameter_list|(
name|n
parameter_list|)
name|unsigned
name|n
decl_stmt|;
block|{
specifier|register
name|char
modifier|*
name|ptr
decl_stmt|;
if|if
condition|(
operator|(
name|ptr
operator|=
name|malloc
argument_list|(
name|n
operator|+
sizeof|sizeof
argument_list|(
name|double
argument_list|)
argument_list|)
operator|)
operator|==
name|NULL
condition|)
name|fatal
argument_list|(
literal|"xmalloc: no memory"
argument_list|)
expr_stmt|;
operator|*
operator|(
operator|(
name|int
operator|*
operator|)
name|ptr
operator|)
operator|=
literal|12345
expr_stmt|;
comment|/* magic number */
return|return
operator|(
name|ptr
operator|+
sizeof|sizeof
argument_list|(
name|double
argument_list|)
operator|)
return|;
block|}
end_function

begin_macro
name|xfree
argument_list|(
argument|p
argument_list|)
end_macro

begin_decl_stmt
name|char
modifier|*
name|p
decl_stmt|;
end_decl_stmt

begin_block
block|{
if|if
condition|(
name|p
operator|==
name|NULL
condition|)
name|fatal
argument_list|(
literal|"xfree: NULL"
argument_list|)
expr_stmt|;
name|p
operator|-=
sizeof|sizeof
argument_list|(
name|double
argument_list|)
expr_stmt|;
if|if
condition|(
operator|*
operator|(
operator|(
name|int
operator|*
operator|)
name|p
operator|)
operator|!=
literal|12345
condition|)
name|fatal
argument_list|(
literal|"xfree: storage not malloc'ed"
argument_list|)
expr_stmt|;
name|free
argument_list|(
name|p
argument_list|)
expr_stmt|;
block|}
end_block

begin_macro
name|fatal
argument_list|(
argument|str
argument_list|)
end_macro

begin_decl_stmt
name|char
modifier|*
name|str
decl_stmt|;
end_decl_stmt

begin_block
block|{
name|deraw
argument_list|()
expr_stmt|;
operator|(
name|void
operator|)
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"%s\n"
argument_list|,
name|str
argument_list|)
expr_stmt|;
name|exit
argument_list|(
literal|1
argument_list|)
expr_stmt|;
block|}
end_block

end_unit

