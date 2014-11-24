begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: rm -rf %t
end_comment

begin_comment
comment|// RUN: %clang_cc1 -x objective-c -fmodules -fmodules-cache-path=%t -I %S/Inputs/exclude-header %s -verify
end_comment

begin_decl_stmt
unit|@
name|import
name|x
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|a
name|var_a
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|b
name|var_b1
decl_stmt|;
end_decl_stmt

begin_comment
comment|// expected-error {{unknown type name 'b'}}
end_comment

begin_decl_stmt
unit|@
name|import
name|y
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|b
name|var_b2
decl_stmt|;
end_decl_stmt

end_unit

