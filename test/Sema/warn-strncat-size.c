begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -Wstrncat-size -verify -fsyntax-only %s
end_comment

begin_comment
comment|// RUN: %clang_cc1 -DUSE_BUILTINS -Wstrncat-size -verify -fsyntax-only %s
end_comment

begin_comment
comment|// RUN: %clang_cc1 -fsyntax-only -Wstrncat-size -fixit -x c %s
end_comment

begin_comment
comment|// RUN: %clang_cc1 -DUSE_BUILTINS -fsyntax-only -Wstrncat-size -fixit -x c %s
end_comment

begin_typedef
typedef|typedef
name|__SIZE_TYPE__
name|size_t
typedef|;
end_typedef

begin_function_decl
name|size_t
name|strlen
parameter_list|(
specifier|const
name|char
modifier|*
name|s
parameter_list|)
function_decl|;
end_function_decl

begin_ifdef
ifdef|#
directive|ifdef
name|USE_BUILTINS
end_ifdef

begin_define
define|#
directive|define
name|BUILTIN
parameter_list|(
name|f
parameter_list|)
value|__builtin_ ## f
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|BUILTIN
parameter_list|(
name|f
parameter_list|)
value|f
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|strncat
value|BUILTIN(strncat)
end_define

begin_function_decl
name|char
modifier|*
name|strncat
parameter_list|(
name|char
modifier|*
specifier|restrict
name|s1
parameter_list|,
specifier|const
name|char
modifier|*
specifier|restrict
name|s2
parameter_list|,
name|size_t
name|n
parameter_list|)
function_decl|;
end_function_decl

begin_struct
struct|struct
block|{
name|char
name|f1
index|[
literal|100
index|]
decl_stmt|;
name|char
name|f2
index|[
literal|100
index|]
index|[
literal|3
index|]
decl_stmt|;
block|}
name|s4
struct|,
modifier|*
modifier|*
name|s5
struct|;
end_struct

begin_decl_stmt
name|char
name|s1
index|[
literal|100
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
name|s2
index|[
literal|200
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|x
decl_stmt|;
end_decl_stmt

begin_function
name|void
name|test
parameter_list|(
name|char
modifier|*
name|src
parameter_list|)
block|{
name|char
name|dest
index|[
literal|10
index|]
decl_stmt|;
name|strncat
argument_list|(
name|dest
argument_list|,
literal|"AAAAAAAAAAAAAAAAAAAAAAAAAAAAA"
argument_list|,
sizeof|sizeof
argument_list|(
name|dest
argument_list|)
operator|-
name|strlen
argument_list|(
name|dest
argument_list|)
operator|-
literal|1
argument_list|)
expr_stmt|;
comment|// no-warning
name|strncat
argument_list|(
name|dest
argument_list|,
literal|"AAAAAAAAAAAAAAAAAAAAAAAAAAAAA"
argument_list|,
sizeof|sizeof
argument_list|(
name|dest
argument_list|)
operator|-
literal|1
argument_list|)
expr_stmt|;
comment|// no-warning - the code might assume that dest is empty
name|strncat
argument_list|(
name|dest
argument_list|,
name|src
argument_list|,
sizeof|sizeof
argument_list|(
name|src
argument_list|)
argument_list|)
expr_stmt|;
comment|// expected-warning {{size argument in 'strncat' call appears to be size of the source}} expected-note {{change the argument to be the free space in the destination buffer minus the terminating null byte}}
name|strncat
argument_list|(
name|dest
argument_list|,
name|src
argument_list|,
sizeof|sizeof
argument_list|(
name|src
argument_list|)
operator|-
literal|1
argument_list|)
expr_stmt|;
comment|// expected-warning {{size argument in 'strncat' call appears to be size of the source}} expected-note {{change the argument to be the free space in the destination buffer minus the terminating null byte}}
name|strncat
argument_list|(
name|dest
argument_list|,
literal|"AAAAAAAAAAAAAAAAAAAAAAAAAAA"
argument_list|,
sizeof|sizeof
argument_list|(
name|dest
argument_list|)
argument_list|)
expr_stmt|;
comment|// expected-warning{{the value of the size argument in 'strncat' is too large, might lead to a buffer overflow}} expected-note {{change the argument to be the free space in the destination buffer minus the terminating null byte}}
name|strncat
argument_list|(
name|dest
argument_list|,
literal|"AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA"
argument_list|,
sizeof|sizeof
argument_list|(
name|dest
argument_list|)
operator|-
name|strlen
argument_list|(
name|dest
argument_list|)
argument_list|)
expr_stmt|;
comment|// expected-warning{{the value of the size argument in 'strncat' is too large, might lead to a buffer overflow}} expected-note {{change the argument to be the free space in the destination buffer minus the terminating null byte}}
name|strncat
argument_list|(
operator|(
operator|*
name|s5
operator|)
operator|->
name|f2
index|[
name|x
index|]
argument_list|,
name|s2
argument_list|,
sizeof|sizeof
argument_list|(
name|s2
argument_list|)
argument_list|)
expr_stmt|;
comment|// expected-warning {{size argument in 'strncat' call appears to be size of the source}} expected-note {{change the argument to be the free space in the destination buffer minus the terminating null byte}}
name|strncat
argument_list|(
name|s1
operator|+
literal|3
argument_list|,
name|s2
argument_list|,
sizeof|sizeof
argument_list|(
name|s2
argument_list|)
argument_list|)
expr_stmt|;
comment|// expected-warning {{size argument in 'strncat' call appears to be size of the source}}
name|strncat
argument_list|(
name|s4
operator|.
name|f1
argument_list|,
name|s2
argument_list|,
sizeof|sizeof
argument_list|(
name|s2
argument_list|)
argument_list|)
expr_stmt|;
comment|// expected-warning {{size argument in 'strncat' call appears to be size of the source}} expected-note {{change the argument to be the free space in the destination buffer minus the terminating null byte}}
block|}
end_function

begin_comment
comment|// Don't issue FIXIT for flexible arrays.
end_comment

begin_struct
struct|struct
name|S
block|{
name|int
name|y
decl_stmt|;
name|char
name|x
index|[]
decl_stmt|;
block|}
struct|;
end_struct

begin_function
name|void
name|flexible_arrays
parameter_list|(
name|struct
name|S
modifier|*
name|s
parameter_list|)
block|{
name|char
name|str
index|[]
init|=
literal|"hi"
decl_stmt|;
name|strncat
argument_list|(
name|s
operator|->
name|x
argument_list|,
name|str
argument_list|,
sizeof|sizeof
argument_list|(
name|str
argument_list|)
argument_list|)
expr_stmt|;
comment|// expected-warning {{size argument in 'strncat' call appears to be size of the source}}
block|}
end_function

begin_comment
comment|// Don't issue FIXIT for destinations of size 1.
end_comment

begin_function
name|void
name|size_1
parameter_list|()
block|{
name|char
name|z
index|[
literal|1
index|]
decl_stmt|;
name|char
name|str
index|[]
init|=
literal|"hi"
decl_stmt|;
name|strncat
argument_list|(
name|z
argument_list|,
name|str
argument_list|,
sizeof|sizeof
argument_list|(
name|z
argument_list|)
argument_list|)
expr_stmt|;
comment|// expected-warning{{the value of the size argument in 'strncat' is too large, might lead to a buffer overflow}}
block|}
end_function

begin_comment
comment|// Support VLAs.
end_comment

begin_function
name|void
name|vlas
parameter_list|(
name|int
name|size
parameter_list|)
block|{
name|char
name|z
index|[
name|size
index|]
decl_stmt|;
name|char
name|str
index|[]
init|=
literal|"hi"
decl_stmt|;
name|strncat
argument_list|(
name|z
argument_list|,
name|str
argument_list|,
sizeof|sizeof
argument_list|(
name|str
argument_list|)
argument_list|)
expr_stmt|;
comment|// expected-warning {{size argument in 'strncat' call appears to be size of the source}} expected-note {{change the argument to be the free space in the destination buffer minus the terminating null byte}}
block|}
end_function

end_unit

