begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_analyze_cc1 -analyzer-checker=core,security.insecureAPI.vfork,unix.Vfork -verify %s
end_comment

begin_comment
comment|// RUN: %clang_analyze_cc1 -analyzer-checker=core,security.insecureAPI.vfork,unix.Vfork -verify -x c++ %s
end_comment

begin_include
include|#
directive|include
file|"Inputs/system-header-simulator.h"
end_include

begin_function_decl
name|void
name|foo
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|// Ensure that child process is properly checked.
end_comment

begin_function
name|int
name|f1
parameter_list|(
name|int
name|x
parameter_list|)
block|{
name|pid_t
name|pid
init|=
name|vfork
argument_list|()
decl_stmt|;
comment|// expected-warning{{Call to function 'vfork' is insecure}}
if|if
condition|(
name|pid
operator|!=
literal|0
condition|)
return|return
literal|0
return|;
switch|switch
condition|(
name|x
condition|)
block|{
case|case
literal|0
case|:
comment|// Ensure that modifying pid is ok.
name|pid
operator|=
literal|1
expr_stmt|;
comment|// no-warning
comment|// Ensure that calling whitelisted routines is ok.
name|execl
argument_list|(
literal|""
argument_list|,
literal|""
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// no-warning
name|_exit
argument_list|(
literal|1
argument_list|)
expr_stmt|;
comment|// no-warning
break|break;
case|case
literal|1
case|:
comment|// Ensure that writing variables is prohibited.
name|x
operator|=
literal|0
expr_stmt|;
comment|// expected-warning{{This assignment is prohibited after a successful vfork}}
break|break;
case|case
literal|2
case|:
comment|// Ensure that calling functions is prohibited.
name|foo
argument_list|()
expr_stmt|;
comment|// expected-warning{{This function call is prohibited after a successful vfork}}
break|break;
default|default:
comment|// Ensure that returning from function is prohibited.
return|return
literal|0
return|;
comment|// expected-warning{{Return is prohibited after a successful vfork; call _exit() instead}}
block|}
while|while
condition|(
literal|1
condition|)
empty_stmt|;
block|}
end_function

begin_comment
comment|// Same as previous but without explicit pid variable.
end_comment

begin_function
name|int
name|f2
parameter_list|(
name|int
name|x
parameter_list|)
block|{
name|pid_t
name|pid
init|=
name|vfork
argument_list|()
decl_stmt|;
comment|// expected-warning{{Call to function 'vfork' is insecure}}
switch|switch
condition|(
name|x
condition|)
block|{
case|case
literal|0
case|:
comment|// Ensure that writing pid is ok.
name|pid
operator|=
literal|1
expr_stmt|;
comment|// no-warning
comment|// Ensure that calling whitelisted routines is ok.
name|execl
argument_list|(
literal|""
argument_list|,
literal|""
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// no-warning
name|_exit
argument_list|(
literal|1
argument_list|)
expr_stmt|;
comment|// no-warning
break|break;
case|case
literal|1
case|:
comment|// Ensure that writing variables is prohibited.
name|x
operator|=
literal|0
expr_stmt|;
comment|// expected-warning{{This assignment is prohibited after a successful vfork}}
break|break;
case|case
literal|2
case|:
comment|// Ensure that calling functions is prohibited.
name|foo
argument_list|()
expr_stmt|;
comment|// expected-warning{{This function call is prohibited after a successful vfork}}
break|break;
default|default:
comment|// Ensure that returning from function is prohibited.
return|return
literal|0
return|;
comment|// expected-warning{{Return is prohibited after a successful vfork; call _exit() instead}}
block|}
while|while
condition|(
literal|1
condition|)
empty_stmt|;
block|}
end_function

begin_comment
comment|// Ensure that parent process isn't restricted.
end_comment

begin_function
name|int
name|f3
parameter_list|(
name|int
name|x
parameter_list|)
block|{
if|if
condition|(
name|vfork
argument_list|()
operator|==
literal|0
condition|)
comment|// expected-warning{{Call to function 'vfork' is insecure}}
name|_exit
argument_list|(
literal|1
argument_list|)
expr_stmt|;
name|x
operator|=
literal|0
expr_stmt|;
comment|// no-warning
name|foo
argument_list|()
expr_stmt|;
comment|// no-warning
return|return
literal|0
return|;
block|}
end_function

begin_comment
comment|// no-warning
end_comment

begin_comment
comment|// Unbound pids are special so test them separately.
end_comment

begin_function
name|void
name|f4
parameter_list|(
name|int
name|x
parameter_list|)
block|{
switch|switch
condition|(
name|x
condition|)
block|{
case|case
literal|0
case|:
name|vfork
argument_list|()
expr_stmt|;
comment|// expected-warning{{Call to function 'vfork' is insecure}}
name|x
operator|=
literal|0
expr_stmt|;
comment|// expected-warning{{This assignment is prohibited after a successful vfork}}
break|break;
case|case
literal|1
case|:
block|{
name|char
name|args
index|[
literal|2
index|]
decl_stmt|;
switch|switch
condition|(
name|vfork
argument_list|()
condition|)
block|{
comment|// expected-warning{{Call to function 'vfork' is insecure}}
case|case
literal|0
case|:
name|args
index|[
literal|0
index|]
operator|=
literal|0
expr_stmt|;
comment|// expected-warning{{This assignment is prohibited after a successful vfork}}
name|exit
argument_list|(
literal|1
argument_list|)
expr_stmt|;
block|}
break|break;
block|}
case|case
literal|2
case|:
block|{
name|pid_t
name|pid
decl_stmt|;
if|if
condition|(
operator|(
name|pid
operator|=
name|vfork
argument_list|()
operator|)
operator|==
literal|0
condition|)
comment|// expected-warning{{Call to function 'vfork' is insecure}}
while|while
condition|(
literal|1
condition|)
empty_stmt|;
comment|// no-warning
break|break;
block|}
block|}
while|while
condition|(
literal|1
condition|)
empty_stmt|;
block|}
end_function

begin_comment
comment|//no-warning
end_comment

begin_function
name|void
name|f5
parameter_list|()
block|{
comment|// See "libxtables: move some code to avoid cautions in vfork man page"
comment|// (http://lists.netfilter.org/pipermail/netfilter-buglog/2014-October/003280.html).
if|if
condition|(
name|vfork
argument_list|()
operator|==
literal|0
condition|)
block|{
comment|// expected-warning{{Call to function 'vfork' is insecure}}
name|execl
argument_list|(
literal|"prog"
argument_list|,
literal|"arg1"
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// no-warning
name|exit
argument_list|(
literal|1
argument_list|)
expr_stmt|;
comment|// expected-warning{{This function call is prohibited after a successful vfork}}
block|}
block|}
end_function

end_unit

