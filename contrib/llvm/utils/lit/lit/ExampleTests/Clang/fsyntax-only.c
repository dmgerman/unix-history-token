begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: clang -fsyntax-only -Xclang -verify %s
end_comment

begin_function
name|int
name|f0
parameter_list|(
name|void
parameter_list|)
block|{}
end_function

begin_comment
comment|// expected-warning {{control reaches end of non-void function}}
end_comment

end_unit

