begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -fsyntax-only %s -verify
end_comment

begin_comment
comment|// expected-no-diagnostics
end_comment

begin_enum
enum|enum
name|A
block|{
name|A1
block|,
name|A2
block|,
name|A3
block|}
enum|;
end_enum

begin_typedef
typedef|typedef
name|enum
name|A
name|A
typedef|;
end_typedef

begin_function
name|void
name|test
parameter_list|()
block|{
name|A
name|a
decl_stmt|;
name|a
operator|++
expr_stmt|;
name|a
operator|--
expr_stmt|;
operator|++
name|a
expr_stmt|;
operator|--
name|a
expr_stmt|;
name|a
operator|=
name|a
operator|+
literal|1
expr_stmt|;
name|a
operator|=
name|a
operator|-
literal|1
expr_stmt|;
block|}
end_function

end_unit

