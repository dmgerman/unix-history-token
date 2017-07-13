begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 %s -verify -fsyntax-only
end_comment

begin_comment
comment|// RUN: %clang_cc1 %s -std=c89 -verify -fsyntax-only
end_comment

begin_comment
comment|// RUN: %clang_cc1 %s -std=c99 -verify -fsyntax-only
end_comment

begin_function_decl
name|int
name|f
parameter_list|()
function_decl|__attribute__
parameter_list|(
function_decl|(deprecated
end_function_decl

begin_empty_stmt
unit|))
empty_stmt|;
end_empty_stmt

begin_comment
comment|// expected-note 2 {{'f' has been explicitly marked deprecated here}}
end_comment

begin_function_decl
name|void
name|g
parameter_list|()
function_decl|__attribute__
parameter_list|(
function_decl|(deprecated
end_function_decl

begin_empty_stmt
unit|))
empty_stmt|;
end_empty_stmt

begin_comment
comment|// expected-note {{'g' has been explicitly marked deprecated here}}
end_comment

begin_function_decl
name|void
name|g
parameter_list|()
function_decl|;
end_function_decl

begin_decl_stmt
specifier|extern
name|int
name|var
name|__attribute__
argument_list|(
operator|(
name|deprecated
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|// expected-note 2 {{'var' has been explicitly marked deprecated here}}
end_comment

begin_function
name|int
name|a
parameter_list|()
block|{
name|int
function_decl|(
modifier|*
name|ptr
function_decl|)
parameter_list|()
init|=
name|f
function_decl|;
comment|// expected-warning {{'f' is deprecated}}
name|f
argument_list|()
expr_stmt|;
comment|// expected-warning {{'f' is deprecated}}
comment|// test if attributes propagate to functions
name|g
argument_list|()
expr_stmt|;
comment|// expected-warning {{'g' is deprecated}}
return|return
name|var
return|;
comment|// expected-warning {{'var' is deprecated}}
block|}
end_function

begin_comment
comment|// test if attributes propagate to variables
end_comment

begin_decl_stmt
specifier|extern
name|int
name|var
decl_stmt|;
end_decl_stmt

begin_function
name|int
name|w
parameter_list|()
block|{
return|return
name|var
return|;
comment|// expected-warning {{'var' is deprecated}}
block|}
end_function

begin_function_decl
name|int
name|old_fn
parameter_list|()
function_decl|__attribute__
parameter_list|(
function_decl|(deprecated
end_function_decl

begin_empty_stmt
unit|))
empty_stmt|;
end_empty_stmt

begin_comment
comment|// expected-note {{'old_fn' has been explicitly marked deprecated here}}
end_comment

begin_function_decl
name|int
name|old_fn
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
function_decl|(
modifier|*
name|fn_ptr
function_decl|)
parameter_list|()
init|=
name|old_fn
function_decl|;
end_function_decl

begin_comment
comment|// expected-warning {{'old_fn' is deprecated}}
end_comment

begin_function
name|int
name|old_fn
parameter_list|()
block|{
return|return
name|old_fn
argument_list|()
operator|+
literal|1
return|;
comment|// no warning, deprecated functions can use deprecated symbols.
block|}
end_function

begin_struct
struct|struct
name|foo
block|{
name|int
name|x
name|__attribute__
argument_list|(
operator|(
name|deprecated
operator|)
argument_list|)
decl_stmt|;
comment|// expected-note 3 {{'x' has been explicitly marked deprecated here}}
block|}
struct|;
end_struct

begin_function
name|void
name|test1
parameter_list|(
name|struct
name|foo
modifier|*
name|F
parameter_list|)
block|{
operator|++
name|F
operator|->
name|x
expr_stmt|;
comment|// expected-warning {{'x' is deprecated}}
name|struct
name|foo
name|f1
init|=
block|{
operator|.
name|x
operator|=
literal|17
block|}
decl_stmt|;
comment|// expected-warning {{'x' is deprecated}}
name|struct
name|foo
name|f2
init|=
block|{
literal|17
block|}
decl_stmt|;
comment|// expected-warning {{'x' is deprecated}}
block|}
end_function

begin_typedef
typedef|typedef
name|struct
name|foo
name|foo_dep
name|__attribute__
typedef|((
name|deprecated
typedef|));
end_typedef

begin_comment
comment|// expected-note 12 {{'foo_dep' has been explicitly marked deprecated here}}
end_comment

begin_decl_stmt
name|foo_dep
modifier|*
name|test2
decl_stmt|;
end_decl_stmt

begin_comment
comment|// expected-warning {{'foo_dep' is deprecated}}
end_comment

begin_decl_stmt
name|struct
name|__attribute__
argument_list|(
operator|(
name|deprecated
operator|,
comment|// expected-note 2 {{'bar_dep' has been explicitly marked deprecated here}}
name|invalid_attribute
operator|)
argument_list|)
name|bar_dep
decl_stmt|;
end_decl_stmt

begin_comment
comment|// expected-warning {{unknown attribute 'invalid_attribute' ignored}}
end_comment

begin_decl_stmt
name|struct
name|bar_dep
modifier|*
name|test3
decl_stmt|;
end_decl_stmt

begin_comment
comment|// expected-warning {{'bar_dep' is deprecated}}
end_comment

begin_comment
comment|// These should not warn because the actually declaration itself is deprecated.
end_comment

begin_comment
comment|// rdar://6756623
end_comment

begin_decl_stmt
name|foo_dep
modifier|*
name|test4
name|__attribute__
argument_list|(
operator|(
name|deprecated
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|bar_dep
modifier|*
name|test5
name|__attribute__
argument_list|(
operator|(
name|deprecated
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_typedef
typedef|typedef
name|foo_dep
name|test6
parameter_list|(
name|struct
name|bar_dep
modifier|*
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|// expected-warning {{'foo_dep' is deprecated}} \
end_comment

begin_comment
comment|// expected-warning {{'bar_dep' is deprecated}}
end_comment

begin_typedef
typedef|typedef
name|foo_dep
name|test7
parameter_list|(
name|struct
name|bar_dep
modifier|*
parameter_list|)
function_decl|__attribute__
parameter_list|(
function_decl|(deprecated
typedef|));
end_typedef

begin_function
name|int
name|test8
parameter_list|(
name|char
modifier|*
name|p
parameter_list|)
block|{
name|p
operator|+=
sizeof|sizeof
argument_list|(
name|foo_dep
argument_list|)
expr_stmt|;
comment|// expected-warning {{'foo_dep' is deprecated}}
name|foo_dep
modifier|*
name|ptr
decl_stmt|;
comment|// expected-warning {{'foo_dep' is deprecated}}
name|ptr
operator|=
operator|(
name|foo_dep
operator|*
operator|)
name|p
expr_stmt|;
comment|// expected-warning {{'foo_dep' is deprecated}}
name|int
name|func
argument_list|(
name|foo_dep
operator|*
name|foo
argument_list|)
decl_stmt|;
comment|// expected-warning {{'foo_dep' is deprecated}}
return|return
name|func
argument_list|(
name|ptr
argument_list|)
return|;
block|}
end_function

begin_function_decl
name|foo_dep
modifier|*
name|test9
parameter_list|(
name|void
parameter_list|)
function_decl|__attribute__
parameter_list|(
function_decl|(deprecated
end_function_decl

begin_empty_stmt
unit|))
empty_stmt|;
end_empty_stmt

begin_function
name|foo_dep
modifier|*
name|test9
parameter_list|(
name|void
parameter_list|)
block|{
name|void
modifier|*
name|myalloc
argument_list|(
name|unsigned
name|long
argument_list|)
decl_stmt|;
name|foo_dep
modifier|*
name|ptr
init|=
operator|(
name|foo_dep
operator|*
operator|)
name|myalloc
argument_list|(
sizeof|sizeof
argument_list|(
name|foo_dep
argument_list|)
argument_list|)
decl_stmt|;
return|return
name|ptr
return|;
block|}
end_function

begin_function_decl
name|void
name|test10
parameter_list|(
name|void
parameter_list|)
function_decl|__attribute__
parameter_list|(
function_decl|(deprecated
end_function_decl

begin_empty_stmt
unit|))
empty_stmt|;
end_empty_stmt

begin_function
name|void
name|test10
parameter_list|(
name|void
parameter_list|)
block|{
if|if
condition|(
sizeof|sizeof
argument_list|(
name|foo_dep
argument_list|)
operator|==
sizeof|sizeof
argument_list|(
name|void
operator|*
argument_list|)
condition|)
block|{   }
name|foo_dep
modifier|*
name|localfunc
argument_list|(
name|void
argument_list|)
decl_stmt|;
name|foo_dep
name|localvar
decl_stmt|;
block|}
end_function

begin_decl_stmt
name|char
name|test11
index|[
sizeof|sizeof
argument_list|(
name|foo_dep
argument_list|)
index|]
name|__attribute__
argument_list|(
operator|(
name|deprecated
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
name|test12
index|[
sizeof|sizeof
argument_list|(
name|foo_dep
argument_list|)
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|// expected-warning {{'foo_dep' is deprecated}}
end_comment

begin_function_decl
name|int
name|test13
parameter_list|(
name|foo_dep
modifier|*
name|foo
parameter_list|)
function_decl|__attribute__
parameter_list|(
function_decl|(deprecated
end_function_decl

begin_empty_stmt
unit|))
empty_stmt|;
end_empty_stmt

begin_function_decl
name|int
name|test14
parameter_list|(
name|foo_dep
modifier|*
name|foo
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|// expected-warning {{'foo_dep' is deprecated}}
end_comment

begin_decl_stmt
name|unsigned
name|long
name|test15
init|=
sizeof|sizeof
argument_list|(
name|foo_dep
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|// expected-warning {{'foo_dep' is deprecated}}
end_comment

begin_decl_stmt
name|unsigned
name|long
name|test16
name|__attribute__
argument_list|(
operator|(
name|deprecated
operator|)
argument_list|)
init|=
sizeof|sizeof
argument_list|(
name|foo_dep
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|foo_dep
name|test17
decl_stmt|,
comment|// expected-warning {{'foo_dep' is deprecated}}
name|test18
name|__attribute__
argument_list|(
operator|(
name|deprecated
operator|)
argument_list|)
decl_stmt|,
name|test19
decl_stmt|;
end_decl_stmt

begin_comment
comment|// rdar://problem/8518751
end_comment

begin_decl_stmt
name|enum
name|__attribute__
argument_list|(
operator|(
name|deprecated
operator|)
argument_list|)
name|Test20
block|{
comment|// expected-note 2 {{'Test20' has been explicitly marked deprecated here}}
name|test20_a
name|__attribute__
argument_list|(
operator|(
name|deprecated
operator|)
argument_list|)
decl_stmt|,
comment|// expected-note {{'test20_a' has been explicitly marked deprecated here}}
name|test20_b
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_function
name|void
name|test20
parameter_list|()
block|{
name|enum
name|Test20
name|f
decl_stmt|;
comment|// expected-warning {{'Test20' is deprecated}}
name|f
operator|=
name|test20_a
expr_stmt|;
comment|// expected-warning {{'test20_a' is deprecated}}
name|f
operator|=
name|test20_b
expr_stmt|;
comment|// expected-warning {{'test20_b' is deprecated}}
block|}
end_function

begin_decl_stmt
name|char
name|test21
index|[
name|__has_feature
argument_list|(
name|attribute_deprecated_with_message
argument_list|)
condition|?
literal|1
else|:
operator|-
literal|1
index|]
decl_stmt|;
end_decl_stmt

begin_struct
struct|struct
name|test22
block|{
name|foo_dep
name|a
name|__attribute
argument_list|(
operator|(
name|deprecated
operator|)
argument_list|)
decl_stmt|;
name|foo_dep
name|b
decl_stmt|;
comment|// expected-warning {{'foo_dep' is deprecated}}
name|foo_dep
name|c
decl_stmt|,
name|d
name|__attribute
argument_list|(
operator|(
name|deprecated
operator|)
argument_list|)
decl_stmt|;
comment|// expected-warning {{'foo_dep' is deprecated}}
name|__attribute
argument_list|(
argument|(deprecated)
argument_list|)
name|foo_dep
name|e
decl_stmt|,
name|f
decl_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|int
name|test23_ty
name|__attribute
typedef|((
name|deprecated
typedef|));
end_typedef

begin_comment
comment|// Redefining a typedef is a C11 feature.
end_comment

begin_if
if|#
directive|if
name|__STDC_VERSION__
operator|<=
literal|199901L
end_if

begin_comment
comment|// expected-note@-3 {{'test23_ty' has been explicitly marked deprecated here}}
end_comment

begin_else
else|#
directive|else
end_else

begin_comment
comment|// expected-note@-5 {{'test23_ty' has been explicitly marked deprecated here}}
end_comment

begin_typedef
typedef|typedef
name|int
name|test23_ty
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
name|test23_ty
name|test23_v
decl_stmt|;
end_decl_stmt

begin_comment
comment|// expected-warning {{'test23_ty' is deprecated}}
end_comment

end_unit

