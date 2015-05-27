begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -fsyntax-only -verify -fms-extensions %s -triple x86_64-apple-darwin
end_comment

begin_comment
comment|// expected-error@+1 {{argument to 'section' attribute is not valid for this target: mach-o section specifier requires a segment and section separated by a comma}}
end_comment

begin_pragma
pragma|#
directive|pragma
name|data_seg
name|(
literal|".my_const"
name|)
end_pragma

begin_decl_stmt
name|int
name|a
init|=
literal|1
decl_stmt|;
end_decl_stmt

begin_pragma
pragma|#
directive|pragma
name|data_seg
name|(
literal|"__THINGY,thingy"
name|)
end_pragma

begin_decl_stmt
name|int
name|b
init|=
literal|1
decl_stmt|;
end_decl_stmt

end_unit

