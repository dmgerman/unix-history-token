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

begin_function
name|int
name|foo
parameter_list|(
name|int
name|x
parameter_list|,
name|int
name|y
parameter_list|)
block|{
name|int
name|z
init|=
literal|3
operator|+
name|x
decl_stmt|;
return|return
name|z
operator|+
name|y
return|;
comment|//% self.expect("frame variable -s", substrs=['ARG: (int) x = -3','ARG: (int) y = 0'])
comment|//% self.expect("frame variable -s x", substrs=['ARG: (int) x = -3'])
comment|//% self.expect("frame variable -s y", substrs=['ARG: (int) y = 0'])
comment|//% self.expect("frame variable -s z", substrs=['LOCAL: (int) z = 0'])
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
return|return
name|foo
argument_list|(
operator|-
literal|3
argument_list|,
literal|0
argument_list|)
return|;
comment|//% self.expect("frame variable -s argc argv", substrs=['ARG: (int) argc ='])
block|}
end_function

end_unit

