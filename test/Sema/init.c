begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: clang-cc %s -verify -fsyntax-only
end_comment

begin_include
include|#
directive|include
file|<stddef.h>
end_include

begin_include
include|#
directive|include
file|<stdint.h>
end_include

begin_typedef
typedef|typedef
name|void
function_decl|(
modifier|*
name|fp
function_decl|)
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_typedef

begin_function_decl
name|void
name|foo
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|// PR clang/3377
end_comment

begin_decl_stmt
name|fp
name|a
index|[
operator|(
name|short
name|int
operator|)
literal|1
index|]
init|=
block|{
name|foo
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|myArray
index|[
literal|5
index|]
init|=
block|{
literal|1
block|,
literal|2
block|,
literal|3
block|,
literal|4
block|,
literal|5
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
modifier|*
name|myPointer2
init|=
name|myArray
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
modifier|*
name|myPointer
init|=
operator|&
operator|(
name|myArray
index|[
literal|2
index|]
operator|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|x
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
modifier|*
name|g
init|=
operator|&
name|x
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
modifier|*
name|h
init|=
operator|&
name|x
decl_stmt|;
end_decl_stmt

begin_function
name|int
name|test
parameter_list|()
block|{
name|int
name|a
index|[
literal|10
index|]
decl_stmt|;
name|int
name|b
index|[
literal|10
index|]
init|=
name|a
decl_stmt|;
comment|// expected-error {{initialization with '{...}' expected}}
name|int
operator|+
expr_stmt|;
comment|// expected-error {{expected identifier or '('}}
block|}
end_function

begin_comment
comment|// PR2050
end_comment

begin_struct
struct|struct
name|cdiff_cmd
block|{
specifier|const
name|char
modifier|*
name|name
decl_stmt|;
name|unsigned
name|short
name|argc
decl_stmt|;
name|int
function_decl|(
modifier|*
name|handler
function_decl|)
parameter_list|()
function_decl|;
block|}
struct|;
end_struct

begin_function_decl
name|int
name|cdiff_cmd_open
parameter_list|()
function_decl|;
end_function_decl

begin_decl_stmt
name|struct
name|cdiff_cmd
name|commands
index|[]
init|=
block|{
block|{
literal|"OPEN"
block|,
literal|1
block|,
operator|&
name|cdiff_cmd_open
block|}
block|}
decl_stmt|;
end_decl_stmt

begin_comment
comment|// PR2348
end_comment

begin_struct
specifier|static
struct|struct
block|{
name|int
name|z
decl_stmt|;
block|}
name|s
index|[
literal|2
index|]
struct|;
end_struct

begin_decl_stmt
name|int
modifier|*
name|t
init|=
operator|&
operator|(
operator|*
name|s
operator|)
operator|.
name|z
decl_stmt|;
end_decl_stmt

begin_comment
comment|// PR2349
end_comment

begin_function
name|short
modifier|*
name|a2
parameter_list|(
name|void
parameter_list|)
block|{
name|short
name|int
name|b
decl_stmt|;
specifier|static
name|short
modifier|*
name|bp
init|=
operator|&
name|b
decl_stmt|;
comment|// expected-error {{initializer element is not a compile-time constant}}
return|return
name|bp
return|;
block|}
end_function

begin_function
name|int
name|pbool
parameter_list|(
name|void
parameter_list|)
block|{
typedef|typedef
specifier|const
name|_Bool
name|cbool
typedef|;
name|_Bool
name|pbool1
init|=
operator|(
name|void
operator|*
operator|)
literal|0
decl_stmt|;
name|cbool
name|pbool2
init|=
operator|&
name|pbool
decl_stmt|;
return|return
name|pbool2
return|;
block|}
end_function

begin_comment
comment|// rdar://5870981
end_comment

begin_union
union|union
block|{
name|float
name|f
decl_stmt|;
name|unsigned
name|u
decl_stmt|;
block|}
name|u
init|=
block|{
literal|1.0f
block|}
union|;
end_union

begin_comment
comment|// rdar://6156694
end_comment

begin_function
name|int
name|f3
parameter_list|(
name|int
name|x
parameter_list|)
block|{
return|return
name|x
return|;
block|}
end_function

begin_typedef
typedef|typedef
name|void
function_decl|(
modifier|*
name|vfunc
function_decl|)
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_typedef

begin_decl_stmt
name|void
modifier|*
name|bar
init|=
operator|(
name|vfunc
operator|)
name|f3
decl_stmt|;
end_decl_stmt

begin_comment
comment|// PR2747
end_comment

begin_struct
struct|struct
name|sym_reg
block|{
name|char
name|nc_gpreg
decl_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
name|int
name|sym_fw1a_scr
index|[]
init|=
block|{
operator|(
call|(
name|int
call|)
argument_list|(
operator|&
operator|(
operator|(
expr|struct
name|sym_reg
operator|*
operator|)
literal|0
operator|)
operator|->
name|nc_gpreg
argument_list|)
operator|)
operator|&
literal|0
block|,
literal|8
operator|*
operator|(
call|(
name|int
call|)
argument_list|(
operator|&
operator|(
operator|(
expr|struct
name|sym_reg
operator|*
operator|)
literal|0
operator|)
operator|->
name|nc_gpreg
argument_list|)
operator|)
block|}
decl_stmt|;
end_decl_stmt

begin_comment
comment|// PR3001
end_comment

begin_decl_stmt
name|struct
name|s1
name|s2
init|=
block|{
operator|.
name|a
operator|=
sizeof|sizeof
argument_list|(
expr|struct
name|s3
argument_list|)
block|,
comment|// expected-error {{invalid application of 'sizeof'}} \
comment|// expected-note{{forward declaration of 'struct s3'}}
operator|.
name|b
operator|=
name|bogus
comment|// expected-error {{use of undeclared identifier 'bogus'}}
block|}
comment|// PR3382
name|char
name|t
index|[]
operator|=
operator|(
literal|"Hello"
operator|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|//<rdar://problem/6094855>
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{ }
name|empty
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|empty
name|e
decl_stmt|;
name|int
name|i2
decl_stmt|;
block|}
name|st
typedef|;
end_typedef

begin_decl_stmt
name|st
name|st1
init|=
block|{
operator|.
name|i2
operator|=
literal|1
block|}
decl_stmt|;
end_decl_stmt

begin_comment
comment|//<rdar://problem/6096826>
end_comment

begin_struct
struct|struct
block|{
name|int
name|a
decl_stmt|;
name|int
name|z
index|[
literal|2
index|]
decl_stmt|;
block|}
name|y
init|=
block|{
operator|.
name|z
operator|=
block|{}
block|}
struct|;
end_struct

begin_decl_stmt
name|int
name|bbb
index|[
literal|10
index|]
decl_stmt|;
end_decl_stmt

begin_struct
struct|struct
name|foo2
block|{
name|uintptr_t
name|a
decl_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
name|struct
name|foo2
name|bar2
index|[]
init|=
block|{
block|{
operator|(
name|intptr_t
operator|)
name|bbb
block|}
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|foo2
name|bar3
init|=
block|{
literal|1
block|,
literal|2
block|}
decl_stmt|;
end_decl_stmt

begin_comment
comment|// expected-warning{{excess elements in struct initializer}}
end_comment

begin_decl_stmt
name|int
modifier|*
name|ptest1
init|=
name|__builtin_choose_expr
argument_list|(
literal|1
argument_list|,
operator|(
name|int
operator|*
operator|)
literal|0
argument_list|,
operator|(
name|int
operator|*
operator|)
literal|0
argument_list|)
decl_stmt|;
end_decl_stmt

begin_typedef
typedef|typedef
name|int32_t
name|ivector4
name|__attribute
typedef|((
name|vector_size
typedef|(16)));
end_typedef

begin_decl_stmt
name|ivector4
name|vtest1
init|=
literal|1
condition|?
operator|(
name|ivector4
operator|)
block|{
literal|1
block|}
else|:
operator|(
name|ivector4
operator|)
block|{
literal|1
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|ivector4
name|vtest2
init|=
name|__builtin_choose_expr
argument_list|(
literal|1
argument_list|,
operator|(
name|ivector4
operator|)
block|{
literal|1
block|}
argument_list|,
operator|(
name|ivector4
operator|)
block|{
literal|1
block|}
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|ivector4
name|vtest3
init|=
name|__real__
argument_list|(
argument|ivector4
argument_list|)
block|{
literal|1
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|ivector4
name|vtest4
init|=
name|__imag__
argument_list|(
argument|ivector4
argument_list|)
block|{
literal|1
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|uintptr_t
name|ptrasintadd1
init|=
operator|(
name|uintptr_t
operator|)
operator|&
name|a
operator|-
literal|4
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|uintptr_t
name|ptrasintadd2
init|=
operator|(
name|uintptr_t
operator|)
operator|&
name|a
operator|+
literal|4
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|uintptr_t
name|ptrasintadd3
init|=
literal|4
operator|+
operator|(
name|uintptr_t
operator|)
operator|&
name|a
decl_stmt|;
end_decl_stmt

begin_comment
comment|// PR4285
end_comment

begin_decl_stmt
specifier|const
name|wchar_t
name|widestr
index|[]
init|=
literal|L"asdf"
decl_stmt|;
end_decl_stmt

end_unit

