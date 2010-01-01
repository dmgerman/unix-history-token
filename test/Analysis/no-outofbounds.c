begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -checker-cfref -analyze -analyzer-experimental-internal-checks -analyzer-store=basic -verify %s
end_comment

begin_comment
comment|// RUN: %clang_cc1 -checker-cfref -analyze -analyzer-experimental-internal-checks -analyzer-store=region -verify %s
end_comment

begin_comment
comment|// XFAIL: *
end_comment

begin_comment
comment|//===----------------------------------------------------------------------===//
end_comment

begin_comment
comment|// This file tests cases where we should not flag out-of-bounds warnings.
end_comment

begin_comment
comment|//===----------------------------------------------------------------------===//
end_comment

begin_function
name|void
name|f
parameter_list|()
block|{
name|long
name|x
init|=
literal|0
decl_stmt|;
name|char
modifier|*
name|y
init|=
operator|(
name|char
operator|*
operator|)
operator|&
name|x
decl_stmt|;
name|char
name|c
init|=
name|y
index|[
literal|0
index|]
operator|+
name|y
index|[
literal|1
index|]
operator|+
name|y
index|[
literal|2
index|]
decl_stmt|;
comment|// no-warning
block|}
end_function

end_unit

