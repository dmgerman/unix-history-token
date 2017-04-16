begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -triple=powerpc64-unknown-linux-gnu -target-feature +altivec -target-feature +vsx -fsyntax-only -verify %s
end_comment

begin_comment
comment|// RUN: %clang_cc1 -triple=powerpc64le-unknown-linux-gnu -target-feature +altivec -target-feature +vsx -fsyntax-only -verify %s
end_comment

begin_comment
comment|// Legitimate for VSX.
end_comment

begin_decl_stmt
name|__vector
name|double
name|vv_d1
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|vector
name|double
name|v_d2
decl_stmt|;
end_decl_stmt

begin_comment
comment|// These should have errors.
end_comment

begin_decl_stmt
name|__vector
name|long
name|double
name|vv_ld3
decl_stmt|;
end_decl_stmt

begin_comment
comment|// expected-error {{cannot use 'long double' with '__vector'}}
end_comment

begin_decl_stmt
name|vector
name|long
name|double
name|v_ld4
decl_stmt|;
end_decl_stmt

begin_comment
comment|// expected-error {{cannot use 'long double' with '__vector'}}
end_comment

end_unit

