begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_include
include|#
directive|include
file|<sgtty.h>
end_include

begin_include
include|#
directive|include
file|<signal.h>
end_include

begin_define
define|#
directive|define
name|STRLEN
value|100
end_define

begin_decl_stmt
specifier|static
name|char
name|str
index|[
name|STRLEN
operator|+
literal|1
index|]
init|=
literal|"%?emacs"
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* extra char for the null */
end_comment

begin_macro
name|switch_to_proc
argument_list|()
end_macro

begin_block
block|{
name|char
modifier|*
name|ptr
init|=
name|str
decl_stmt|;
while|while
condition|(
operator|*
name|ptr
condition|)
name|ioctl
argument_list|(
literal|0
argument_list|,
name|TIOCSTI
argument_list|,
name|ptr
operator|++
argument_list|)
expr_stmt|;
name|ioctl
argument_list|(
literal|0
argument_list|,
name|TIOCSTI
argument_list|,
literal|"\n"
argument_list|)
expr_stmt|;
name|kill
argument_list|(
name|getpid
argument_list|()
argument_list|,
name|SIGTSTP
argument_list|)
expr_stmt|;
block|}
end_block

begin_macro
name|set_proc_str
argument_list|(
argument|ptr
argument_list|)
end_macro

begin_decl_stmt
name|char
modifier|*
name|ptr
decl_stmt|;
end_decl_stmt

begin_block
block|{
if|if
condition|(
name|strlen
argument_list|(
name|ptr
argument_list|)
operator|<=
name|STRLEN
condition|)
name|strcpy
argument_list|(
name|str
argument_list|,
name|ptr
argument_list|)
expr_stmt|;
else|else
name|printf
argument_list|(
literal|"string too long for set-proc-str: %s\n"
argument_list|,
name|ptr
argument_list|)
expr_stmt|;
block|}
end_block

end_unit

