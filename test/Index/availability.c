begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// Run lines below; this test is line- and column-sensitive.
end_comment

begin_function_decl
name|void
name|foo
parameter_list|(
name|void
parameter_list|)
function_decl|__attribute__
parameter_list|(
function_decl|(availability
parameter_list|(
name|macosx
parameter_list|,
name|introduced
init|=
literal|10.4
parameter_list|,
name|deprecated
init|=
literal|10.5
parameter_list|,
name|obsoleted
init|=
literal|10.7
parameter_list|)
operator|,
function_decl|availability
parameter_list|(
name|ios
parameter_list|,
name|introduced
init|=
literal|3.2
parameter_list|,
name|deprecated
init|=
literal|4.1
parameter_list|)
end_function_decl

begin_empty_stmt
unit|))
empty_stmt|;
end_empty_stmt

begin_comment
comment|// RUN: c-index-test -test-load-source all %s> %t
end_comment

begin_comment
comment|// RUN: FileCheck -check-prefix=CHECK-1 %s< %t
end_comment

begin_comment
comment|// RUN: FileCheck -check-prefix=CHECK-2 %s< %t
end_comment

begin_comment
comment|// CHECK-1: (ios, introduced=3.2, deprecated=4.1)
end_comment

begin_comment
comment|// CHECK-2: (macosx, introduced=10.4, deprecated=10.5, obsoleted=10.7)
end_comment

end_unit

