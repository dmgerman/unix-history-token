begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- main.c --------------------------------------------------*- C++ -*-===//
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//                     The LLVM Compiler Infrastructure
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// This file is distributed under the University of Illinois Open Source
end_comment

begin_comment
comment|// License. See LICENSE.TXT for details.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//===----------------------------------------------------------------------===//
end_comment

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_comment
comment|// This simple program is to test the lldb Python API related to frames.
end_comment

begin_function_decl
name|int
name|a
parameter_list|(
name|int
parameter_list|,
name|char
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|b
parameter_list|(
name|int
parameter_list|,
name|char
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|c
parameter_list|(
name|int
parameter_list|,
name|char
parameter_list|)
function_decl|;
end_function_decl

begin_function
name|int
name|a
parameter_list|(
name|int
name|val
parameter_list|,
name|char
name|ch
parameter_list|)
block|{
name|int
name|my_val
init|=
name|val
decl_stmt|;
name|char
name|my_ch
init|=
name|ch
decl_stmt|;
name|printf
argument_list|(
literal|"a(val=%d, ch='%c')\n"
argument_list|,
name|val
argument_list|,
name|ch
argument_list|)
expr_stmt|;
if|if
condition|(
name|val
operator|<=
literal|1
condition|)
return|return
name|b
argument_list|(
name|val
operator|+
literal|1
argument_list|,
name|ch
operator|+
literal|1
argument_list|)
return|;
elseif|else
if|if
condition|(
name|val
operator|>=
literal|3
condition|)
return|return
name|c
argument_list|(
name|val
operator|+
literal|1
argument_list|,
name|ch
operator|+
literal|1
argument_list|)
return|;
return|return
name|val
return|;
block|}
end_function

begin_function
name|int
name|b
parameter_list|(
name|int
name|val
parameter_list|,
name|char
name|ch
parameter_list|)
block|{
name|int
name|my_val
init|=
name|val
decl_stmt|;
name|char
name|my_ch
init|=
name|ch
decl_stmt|;
name|printf
argument_list|(
literal|"b(val=%d, ch='%c')\n"
argument_list|,
name|val
argument_list|,
name|ch
argument_list|)
expr_stmt|;
return|return
name|c
argument_list|(
name|val
operator|+
literal|1
argument_list|,
name|ch
operator|+
literal|1
argument_list|)
return|;
block|}
end_function

begin_function
name|int
name|c
parameter_list|(
name|int
name|val
parameter_list|,
name|char
name|ch
parameter_list|)
block|{
name|int
name|my_val
init|=
name|val
decl_stmt|;
name|char
name|my_ch
init|=
name|ch
decl_stmt|;
name|printf
argument_list|(
literal|"c(val=%d, ch='%c')\n"
argument_list|,
name|val
argument_list|,
name|ch
argument_list|)
expr_stmt|;
return|return
name|val
operator|+
literal|3
operator|+
name|ch
return|;
block|}
end_function

begin_function
name|int
name|main
parameter_list|(
name|int
name|argc
parameter_list|,
name|char
specifier|const
modifier|*
name|argv
index|[]
parameter_list|)
block|{
name|int
name|A1
init|=
name|a
argument_list|(
literal|1
argument_list|,
literal|'A'
argument_list|)
decl_stmt|;
comment|// a(1, 'A') -> b(2, 'B') -> c(3, 'C')
name|printf
argument_list|(
literal|"a(1, 'A') returns %d\n"
argument_list|,
name|A1
argument_list|)
expr_stmt|;
name|int
name|B2
init|=
name|b
argument_list|(
literal|2
argument_list|,
literal|'B'
argument_list|)
decl_stmt|;
comment|// b(2, 'B') -> c(3, 'C')
name|printf
argument_list|(
literal|"b(2, 'B') returns %d\n"
argument_list|,
name|B2
argument_list|)
expr_stmt|;
name|int
name|A3
init|=
name|a
argument_list|(
literal|3
argument_list|,
literal|'A'
argument_list|)
decl_stmt|;
comment|// a(3, 'A') -> c(4, 'B')
name|printf
argument_list|(
literal|"a(3, 'A') returns %d\n"
argument_list|,
name|A3
argument_list|)
expr_stmt|;
return|return
literal|0
return|;
block|}
end_function

end_unit

