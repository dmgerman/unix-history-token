begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// REQUIRES: powerpc-registered-target
end_comment

begin_comment
comment|// RUN: %clang_cc1 -target-feature +altivec -target-feature +power9-vector \
end_comment

begin_comment
comment|// RUN:   -triple powerpc64-unknown-unknown -fsyntax-only   \
end_comment

begin_comment
comment|// RUN: -Wall -Werror -verify %s
end_comment

begin_comment
comment|// RUN: %clang_cc1 -target-feature +altivec -target-feature +power9-vector  \
end_comment

begin_comment
comment|// RUN: -triple powerpc64le-unknown-unknown -fsyntax-only    \
end_comment

begin_comment
comment|// RUN: -Wall -Werror -verify %s
end_comment

begin_include
include|#
directive|include
file|<altivec.h>
end_include

begin_decl_stmt
specifier|extern
name|vector
name|signed
name|int
name|vsi
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|vector
name|unsigned
name|char
name|vuc
decl_stmt|;
end_decl_stmt

begin_function
name|void
name|testInsertWord
parameter_list|(
name|void
parameter_list|)
block|{
name|int
name|index
init|=
literal|5
decl_stmt|;
name|vector
name|unsigned
name|char
name|v1
init|=
name|vec_insert4b
argument_list|(
name|vsi
argument_list|,
name|vuc
argument_list|,
name|index
argument_list|)
decl_stmt|;
comment|// expected-error {{argument to '__builtin_vsx_insertword' must be a constant integer}}
name|vector
name|unsigned
name|long
name|long
name|v2
init|=
name|vec_extract4b
argument_list|(
name|vuc
argument_list|,
name|index
argument_list|)
decl_stmt|;
comment|// expected-error {{argument to '__builtin_vsx_extractuword' must be a constant integer}}
block|}
end_function

begin_function
name|void
name|testXXPERMDI
parameter_list|(
name|int
name|index
parameter_list|)
block|{
name|vec_xxpermdi
argument_list|(
name|vsi
argument_list|)
expr_stmt|;
comment|//expected-error {{too few arguments to function call, expected at least 3, have 1}}
name|vec_xxpermdi
argument_list|(
name|vsi
argument_list|,
name|vsi
argument_list|,
literal|2
argument_list|,
literal|4
argument_list|)
expr_stmt|;
comment|//expected-error {{too many arguments to function call, expected at most 3, have 4}}
name|vec_xxpermdi
argument_list|(
name|vsi
argument_list|,
name|vsi
argument_list|,
name|index
argument_list|)
expr_stmt|;
comment|//expected-error {{argument 3 to '__builtin_vsx_xxpermdi' must be a 2-bit unsigned literal (i.e. 0, 1, 2 or 3)}}
name|vec_xxpermdi
argument_list|(
literal|1
argument_list|,
literal|2
argument_list|,
literal|3
argument_list|)
expr_stmt|;
comment|//expected-error {{first two arguments to '__builtin_vsx_xxpermdi' must be vectors}}
name|vec_xxpermdi
argument_list|(
name|vsi
argument_list|,
name|vuc
argument_list|,
literal|2
argument_list|)
expr_stmt|;
comment|//expected-error {{first two arguments to '__builtin_vsx_xxpermdi' must have the same type}}
block|}
end_function

begin_function
name|void
name|testXXSLDWI
parameter_list|(
name|int
name|index
parameter_list|)
block|{
name|vec_xxsldwi
argument_list|(
name|vsi
argument_list|)
expr_stmt|;
comment|//expected-error {{too few arguments to function call, expected at least 3, have 1}}
name|vec_xxsldwi
argument_list|(
name|vsi
argument_list|,
name|vsi
argument_list|,
literal|2
argument_list|,
literal|4
argument_list|)
expr_stmt|;
comment|//expected-error {{too many arguments to function call, expected at most 3, have 4}}
name|vec_xxsldwi
argument_list|(
name|vsi
argument_list|,
name|vsi
argument_list|,
name|index
argument_list|)
expr_stmt|;
comment|//expected-error {{argument 3 to '__builtin_vsx_xxsldwi' must be a 2-bit unsigned literal (i.e. 0, 1, 2 or 3)}}
name|vec_xxsldwi
argument_list|(
literal|1
argument_list|,
literal|2
argument_list|,
literal|3
argument_list|)
expr_stmt|;
comment|//expected-error {{first two arguments to '__builtin_vsx_xxsldwi' must be vectors}}
name|vec_xxsldwi
argument_list|(
name|vsi
argument_list|,
name|vuc
argument_list|,
literal|2
argument_list|)
expr_stmt|;
comment|//expected-error {{first two arguments to '__builtin_vsx_xxsldwi' must have the same type}}
block|}
end_function

end_unit

