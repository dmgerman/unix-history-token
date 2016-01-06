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

begin_function
name|void
name|set_char
parameter_list|(
name|void
parameter_list|)
block|{
name|char
name|i
init|=
literal|'a'
decl_stmt|;
name|printf
argument_list|(
literal|"before (char) i = %c\n"
argument_list|,
name|i
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"after  (char) i = %c\n"
argument_list|,
name|i
argument_list|)
expr_stmt|;
comment|// Set break point #1. //// break $source:$line
block|}
end_function

begin_function
name|void
name|set_uchar
parameter_list|(
name|void
parameter_list|)
block|{
name|unsigned
name|char
name|i
init|=
literal|'a'
decl_stmt|;
name|printf
argument_list|(
literal|"before (unsigned char) i = %c\n"
argument_list|,
name|i
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"after  (unsigned char) i = %c\n"
argument_list|,
name|i
argument_list|)
expr_stmt|;
comment|//// break $source:$line
block|}
end_function

begin_function
name|void
name|set_short
parameter_list|(
name|void
parameter_list|)
block|{
name|short
name|i
init|=
literal|33
decl_stmt|;
name|printf
argument_list|(
literal|"before (short) i = %i\n"
argument_list|,
name|i
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"after  (short) i = %i\n"
argument_list|,
name|i
argument_list|)
expr_stmt|;
comment|//// break $source:$line
block|}
end_function

begin_function
name|void
name|set_ushort
parameter_list|(
name|void
parameter_list|)
block|{
name|unsigned
name|short
name|i
init|=
literal|33
decl_stmt|;
name|printf
argument_list|(
literal|"before (unsigned short) i = %i\n"
argument_list|,
name|i
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"after  (unsigned short) i = %i\n"
argument_list|,
name|i
argument_list|)
expr_stmt|;
comment|// Set break point #2. //// break $source:$line
block|}
end_function

begin_function
name|void
name|set_int
parameter_list|(
name|void
parameter_list|)
block|{
name|int
name|i
init|=
literal|33
decl_stmt|;
name|printf
argument_list|(
literal|"before (int) i = %i\n"
argument_list|,
name|i
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"after  (int) i = %i\n"
argument_list|,
name|i
argument_list|)
expr_stmt|;
comment|//// break $source:$line
block|}
end_function

begin_function
name|void
name|set_uint
parameter_list|(
name|void
parameter_list|)
block|{
name|unsigned
name|int
name|i
init|=
literal|33
decl_stmt|;
name|printf
argument_list|(
literal|"before (unsigned int) i = %u\n"
argument_list|,
name|i
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"after  (unsigned int) i = %u\n"
argument_list|,
name|i
argument_list|)
expr_stmt|;
comment|//// break $source:$line
block|}
end_function

begin_function
name|void
name|set_long
parameter_list|(
name|void
parameter_list|)
block|{
name|long
name|i
init|=
literal|33
decl_stmt|;
name|printf
argument_list|(
literal|"before (long) i = %li\n"
argument_list|,
name|i
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"after  (long) i = %li\n"
argument_list|,
name|i
argument_list|)
expr_stmt|;
comment|// Set break point #3. //// break $source:$line
block|}
end_function

begin_function
name|void
name|set_ulong
parameter_list|(
name|void
parameter_list|)
block|{
name|unsigned
name|long
name|i
init|=
literal|33
decl_stmt|;
name|printf
argument_list|(
literal|"before (unsigned long) i = %lu\n"
argument_list|,
name|i
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"after  (unsigned long) i = %lu\n"
argument_list|,
name|i
argument_list|)
expr_stmt|;
comment|//// break $source:$line
block|}
end_function

begin_function
name|void
name|set_float
parameter_list|(
name|void
parameter_list|)
block|{
name|float
name|i
init|=
literal|2.25
decl_stmt|;
name|printf
argument_list|(
literal|"before (float) i = %g\n"
argument_list|,
name|i
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"after  (float) i = %g\n"
argument_list|,
name|i
argument_list|)
expr_stmt|;
comment|//// break $source:$line
block|}
end_function

begin_function
name|void
name|set_double
parameter_list|(
name|void
parameter_list|)
block|{
name|double
name|i
init|=
literal|2.25
decl_stmt|;
name|printf
argument_list|(
literal|"before (double) i = %g\n"
argument_list|,
name|i
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"after  (double) i = %g\n"
argument_list|,
name|i
argument_list|)
expr_stmt|;
comment|// Set break point #4. //// break $source:$line
block|}
end_function

begin_function
name|void
name|set_long_double
parameter_list|(
name|void
parameter_list|)
block|{
name|long
name|double
name|i
init|=
literal|2.25
decl_stmt|;
name|printf
argument_list|(
literal|"before (long double) i = %Lg\n"
argument_list|,
name|i
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"after  (long double) i = %Lg\n"
argument_list|,
name|i
argument_list|)
expr_stmt|;
comment|// Set break point #5. //// break $source:$line
block|}
end_function

begin_function
name|void
name|set_point
parameter_list|(
name|void
parameter_list|)
block|{
struct|struct
name|point_tag
block|{
name|int
name|x
decl_stmt|;
name|int
name|y
decl_stmt|;
block|}
struct|;
name|struct
name|point_tag
name|points_2
index|[
literal|2
index|]
init|=
block|{
block|{
literal|1
block|,
literal|2
block|}
block|,
block|{
literal|3
block|,
literal|4
block|}
block|}
decl_stmt|;
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
comment|// Continue to the breakpoint in set_char()
name|set_char
argument_list|()
expr_stmt|;
comment|//// continue; var i; val -set 99 1
name|set_uchar
argument_list|()
expr_stmt|;
comment|//// continue; var i; val -set 99 2
name|set_short
argument_list|()
expr_stmt|;
comment|//// continue; var i; val -set -42 3
name|set_ushort
argument_list|()
expr_stmt|;
comment|//// continue; var i; val -set 42 4
name|set_int
argument_list|()
expr_stmt|;
comment|//// continue; var i; val -set -42 5
name|set_uint
argument_list|()
expr_stmt|;
comment|//// continue; var i; val -set 42 6
name|set_long
argument_list|()
expr_stmt|;
comment|//// continue; var i; val -set -42 7
name|set_ulong
argument_list|()
expr_stmt|;
comment|//// continue; var i; val -set 42 8
name|set_float
argument_list|()
expr_stmt|;
comment|//// continue; var i; val -set 123.456 9
name|set_double
argument_list|()
expr_stmt|;
comment|//// continue; var i; val -set 123.456 10
name|set_long_double
argument_list|()
expr_stmt|;
comment|//// continue; var i; val -set 123.456 11
name|set_point
argument_list|()
expr_stmt|;
comment|//// continue
return|return
literal|0
return|;
block|}
end_function

end_unit

