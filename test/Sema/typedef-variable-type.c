begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 %s -verify -fsyntax-only -pedantic
end_comment

begin_typedef
typedef|typedef
name|int
argument_list|(
operator|*
name|a
argument_list|)
index|[
operator|!
literal|.0
index|]
expr_stmt|;
end_typedef

begin_comment
comment|// expected-warning{{size of static array must be an integer constant expression}}
end_comment

end_unit

