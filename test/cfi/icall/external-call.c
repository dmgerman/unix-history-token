begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cfi -lm -o %t1 %s
end_comment

begin_comment
comment|// RUN: %t1 c 1 2>&1 | FileCheck --check-prefix=CFI %s
end_comment

begin_comment
comment|// RUN: %t1 s 2 2>&1 | FileCheck --check-prefix=CFI %s
end_comment

begin_comment
comment|// This test uses jump tables containing PC-relative references to external
end_comment

begin_comment
comment|// symbols, which the Mach-O object writer does not currently support.
end_comment

begin_comment
comment|// XFAIL: darwin
end_comment

begin_include
include|#
directive|include
file|<stdlib.h>
end_include

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_include
include|#
directive|include
file|<math.h>
end_include

begin_function
name|int
name|main
parameter_list|(
name|int
name|argc
parameter_list|,
name|char
modifier|*
modifier|*
name|argv
parameter_list|)
block|{
comment|// CFI: 1
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"1\n"
argument_list|)
expr_stmt|;
name|double
function_decl|(
modifier|*
name|fn
function_decl|)
parameter_list|(
name|double
parameter_list|)
function_decl|;
if|if
condition|(
name|argv
index|[
literal|1
index|]
index|[
literal|0
index|]
operator|==
literal|'s'
condition|)
name|fn
operator|=
name|sin
expr_stmt|;
else|else
name|fn
operator|=
name|cos
expr_stmt|;
name|fn
argument_list|(
name|atof
argument_list|(
name|argv
index|[
literal|2
index|]
argument_list|)
argument_list|)
expr_stmt|;
comment|// CFI: 2
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"2\n"
argument_list|)
expr_stmt|;
block|}
end_function

end_unit

