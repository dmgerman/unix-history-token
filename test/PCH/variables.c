begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// Test this without pch.
end_comment

begin_comment
comment|// RUN: %clang_cc1 -include %S/variables.h -fsyntax-only -verify %s
end_comment

begin_comment
comment|// Test with pch.
end_comment

begin_comment
comment|// RUN: %clang_cc1 -emit-pch -o %t %S/variables.h
end_comment

begin_comment
comment|// RUN: %clang_cc1 -include-pch %t -fsyntax-only -verify %s
end_comment

begin_decl_stmt
name|int
modifier|*
name|ip2
init|=
operator|&
name|x
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|float
modifier|*
name|fp
init|=
operator|&
name|ip
decl_stmt|;
end_decl_stmt

begin_comment
comment|// expected-warning{{incompatible pointer types}}
end_comment

begin_comment
comment|// FIXME:variables.h expected-note{{previous}}
end_comment

begin_decl_stmt
name|double
name|z
decl_stmt|;
end_decl_stmt

begin_comment
comment|// expected-error{{redefinition}}
end_comment

begin_comment
comment|// FIXME:variables.h expected-note{{previous}}
end_comment

begin_decl_stmt
name|int
name|z2
init|=
literal|18
decl_stmt|;
end_decl_stmt

begin_comment
comment|// expected-error{{redefinition}}
end_comment

begin_decl_stmt
name|double
name|VeryHappy
decl_stmt|;
end_decl_stmt

begin_comment
comment|// expected-error{{redefinition}}
end_comment

begin_comment
comment|// FIXME:variables.h expected-note{{previous definition is here}}
end_comment

begin_decl_stmt
name|int
name|Q
init|=
name|A_MACRO_IN_THE_PCH
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|R
init|=
name|FUNCLIKE_MACRO
argument_list|(
name|A_MACRO_
argument_list|,
name|IN_THE_PCH
argument_list|)
decl_stmt|;
end_decl_stmt

begin_function_decl
name|int
name|UNIQUE
parameter_list|(
name|a
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|// a2
end_comment

begin_decl_stmt
name|int
modifier|*
name|Arr
index|[]
init|=
block|{
operator|&
name|a0
block|,
operator|&
name|a1
block|,
operator|&
name|a2
block|}
decl_stmt|;
end_decl_stmt

end_unit

