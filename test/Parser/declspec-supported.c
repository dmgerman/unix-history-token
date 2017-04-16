begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -triple i386-pc-unknown -fsyntax-only -fms-extensions -verify %s
end_comment

begin_comment
comment|// RUN: %clang_cc1 -triple i386-pc-unknown -fsyntax-only -fdeclspec -verify %s
end_comment

begin_comment
comment|// expected-no-diagnostics
end_comment

begin_macro
name|__declspec
argument_list|(
argument|naked
argument_list|)
end_macro

begin_function
name|void
name|f
parameter_list|(
name|void
parameter_list|)
block|{}
end_function

begin_struct
struct|struct
name|S
block|{
name|__declspec
argument_list|(
argument|property(get=Getter, put=Setter)
argument_list|)
name|int
name|X
decl_stmt|;
name|int
name|Y
decl_stmt|;
block|}
struct|;
end_struct

end_unit

