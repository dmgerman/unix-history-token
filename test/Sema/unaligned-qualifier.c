begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 %s -verify -fsyntax-only -fms-extensions
end_comment

begin_decl_stmt
name|int
name|__unaligned
modifier|*
name|p1
decl_stmt|;
end_decl_stmt

begin_comment
comment|// expected-note {{previous definition is here}}
end_comment

begin_decl_stmt
name|int
modifier|*
name|p1
decl_stmt|;
end_decl_stmt

begin_comment
comment|// expected-error {{redefinition of 'p1' with a different type: 'int *' vs '__unaligned int *'}}
end_comment

end_unit

