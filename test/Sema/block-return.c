begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -fsyntax-only %s -verify -fblocks
end_comment

begin_typedef
typedef|typedef
name|void
function_decl|(
modifier|^
name|CL
function_decl|)
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_typedef

begin_function
name|CL
name|foo
parameter_list|()
block|{
name|short
name|y
decl_stmt|;
name|short
function_decl|(
modifier|^
name|add1
function_decl|)
parameter_list|(
name|void
parameter_list|)
init|=
lambda|^
block|{
return|return
name|y
operator|+
literal|1
return|;
block|}
end_function

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
comment|// expected-error {{incompatible block pointer types initializing 'int (^)(void)', expected 'short (^)(void)'}}
end_comment

begin_decl_stmt
name|CL
name|X
init|=
lambda|^
block|{
if|if
condition|(
literal|2
condition|)
return|return;
return|return
literal|1
return|;
comment|// expected-error {{void block should not return a value}}
block|}
decl_stmt|;
end_decl_stmt

begin_function_decl
name|int
function_decl|(
modifier|^
name|Y
function_decl|)
parameter_list|(
name|void
parameter_list|)
init|=
lambda|^
block|{
end_function_decl

begin_if
if|if
condition|(
literal|3
condition|)
return|return
literal|1
return|;
else|else
return|return;
end_if

begin_comment
comment|// expected-error {{non-void block should return a value}}
end_comment

begin_function_decl
unit|};
name|char
modifier|*
function_decl|(
modifier|^
name|Z
function_decl|)
parameter_list|(
name|void
parameter_list|)
init|=
lambda|^
block|{
end_function_decl

begin_if
if|if
condition|(
literal|3
condition|)
return|return
literal|""
return|;
else|else
return|return
operator|(
name|char
operator|*
operator|)
literal|0
return|;
end_if

begin_function_decl
unit|};
name|double
function_decl|(
modifier|^
name|A
function_decl|)
parameter_list|(
name|void
parameter_list|)
init|=
lambda|^
block|{
end_function_decl

begin_comment
comment|// expected-error {{incompatible block pointer types initializing 'float (^)(void)', expected 'double (^)(void)'}}
end_comment

begin_if
if|if
condition|(
literal|1
condition|)
return|return
operator|(
name|float
operator|)
literal|1.0
return|;
elseif|else
if|if
condition|(
literal|2
condition|)
return|return
operator|(
name|double
operator|)
literal|2.0
return|;
end_if

begin_return
return|return
literal|1
return|;
end_return

begin_function_decl
unit|};
name|char
modifier|*
function_decl|(
modifier|^
name|B
function_decl|)
parameter_list|(
name|void
parameter_list|)
init|=
lambda|^
block|{
end_function_decl

begin_if
if|if
condition|(
literal|3
condition|)
return|return
literal|""
return|;
else|else
return|return
literal|2
return|;
end_if

begin_comment
comment|// expected-warning {{incompatible integer to pointer conversion returning 'int', expected 'char *'}}
end_comment

begin_return
unit|};
return|return
lambda|^
block|{
return|return
literal|1
return|;
block|}
return|;
end_return

begin_comment
comment|// expected-error {{incompatible block pointer types returning 'int (^)(void)', expected 'CL'}}
end_comment

begin_function_decl
unit|}  typedef
name|int
function_decl|(
modifier|^
name|CL2
function_decl|)
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function
name|CL2
name|foo2
parameter_list|()
block|{
return|return
lambda|^
block|{
return|return
literal|1
return|;
block|}
return|;
block|}
end_function

begin_typedef
typedef|typedef
name|unsigned
name|int
modifier|*
name|uintptr_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|char
name|Boolean
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|int
name|CFBasicHash
typedef|;
end_typedef

begin_define
define|#
directive|define
name|INVOKE_CALLBACK2
parameter_list|(
name|P
parameter_list|,
name|A
parameter_list|,
name|B
parameter_list|)
value|(P)(A, B)
end_define

begin_typedef
typedef|typedef
struct|struct
block|{
name|Boolean
function_decl|(
modifier|^
name|isEqual
function_decl|)
parameter_list|(
specifier|const
name|CFBasicHash
modifier|*
parameter_list|,
name|uintptr_t
name|stack_value_or_key1
parameter_list|,
name|uintptr_t
name|stack_value_or_key2
parameter_list|,
name|Boolean
name|is_key
parameter_list|)
function_decl|;
block|}
name|CFBasicHashCallbacks
typedef|;
end_typedef

begin_function
name|int
name|foo3
parameter_list|()
block|{
name|CFBasicHashCallbacks
name|cb
decl_stmt|;
name|Boolean
function_decl|(
modifier|*
name|value_equal
function_decl|)
parameter_list|(
name|uintptr_t
parameter_list|,
name|uintptr_t
parameter_list|)
init|=
literal|0
function_decl|;
name|cb
operator|.
name|isEqual
operator|=
lambda|^
parameter_list|(
specifier|const
name|CFBasicHash
modifier|*
name|table
parameter_list|,
name|uintptr_t
name|stack_value_or_key1
parameter_list|,
name|uintptr_t
name|stack_value_or_key2
parameter_list|,
name|Boolean
name|is_key
parameter_list|)
block|{
return|return
operator|(
name|Boolean
operator|)
operator|(
name|uintptr_t
operator|)
name|INVOKE_CALLBACK2
argument_list|(
name|value_equal
argument_list|,
operator|(
name|uintptr_t
operator|)
name|stack_value_or_key1
argument_list|,
operator|(
name|uintptr_t
operator|)
name|stack_value_or_key2
argument_list|)
return|;
block|}
expr_stmt|;
block|}
end_function

begin_function
specifier|static
name|int
name|funk
parameter_list|(
name|char
modifier|*
name|s
parameter_list|)
block|{
if|if
condition|(
lambda|^
block|{}
operator|==
operator|(
operator|(
name|void
operator|*
operator|)
literal|0
operator|)
condition|)
return|return
literal|1
return|;
else|else
return|return
literal|0
return|;
block|}
end_function

begin_function
name|void
name|foo4
parameter_list|()
block|{
name|int
function_decl|(
modifier|^
name|xx
function_decl|)
parameter_list|(
specifier|const
name|char
modifier|*
name|s
parameter_list|)
init|=
lambda|^
parameter_list|(
name|char
modifier|*
name|s
parameter_list|)
block|{
return|return
literal|1
return|;
block|}
end_function

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
comment|// expected-error {{incompatible block pointer types initializing 'int (^)(char *)', expected 'int (^)(char const *)'}}
end_comment

begin_function_decl
name|int
function_decl|(
modifier|*
name|yy
function_decl|)
parameter_list|(
specifier|const
name|char
modifier|*
name|s
parameter_list|)
init|=
name|funk
function_decl|;
end_function_decl

begin_comment
comment|// expected-warning {{incompatible pointer types initializing 'int (char *)', expected 'int (*)(char const *)'}}
end_comment

begin_function_decl
name|int
function_decl|(
modifier|^
name|nested
function_decl|)
parameter_list|(
name|char
modifier|*
name|s
parameter_list|)
init|=
lambda|^
parameter_list|(
name|char
modifier|*
name|str
parameter_list|)
block|{
name|void
argument_list|(
operator|^
name|nest
argument_list|)
operator|(
name|void
operator|)
operator|=
lambda|^
parameter_list|(
name|void
parameter_list|)
block|{
name|printf
argument_list|(
literal|"%s\n"
argument_list|,
name|str
argument_list|)
function_decl|;
end_function_decl

begin_expr_stmt
unit|};
name|next
argument_list|()
expr_stmt|;
end_expr_stmt

begin_return
return|return
literal|1
return|;
end_return

begin_comment
unit|};
comment|// expected-warning{{implicitly declaring C library function 'printf' with type 'int (char const *, ...)'}} \
end_comment

begin_comment
comment|// expected-note{{please include the header<stdio.h> or explicitly provide a declaration for 'printf'}}
end_comment

begin_function_decl
unit|}  typedef
name|void
function_decl|(
modifier|^
name|bptr
function_decl|)
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function
name|bptr
name|foo5
parameter_list|(
name|int
name|j
parameter_list|)
block|{
specifier|__block
name|int
name|i
decl_stmt|;
if|if
condition|(
name|j
condition|)
return|return
lambda|^
block|{
lambda|^
block|{
name|i
operator|=
literal|0
expr_stmt|;
block|}
argument_list|()
expr_stmt|;
block|}
return|;
comment|// expected-error {{returning block that lives on the local stack}}
return|return
lambda|^
block|{
name|i
operator|=
literal|0
expr_stmt|;
block|}
return|;
comment|// expected-error {{returning block that lives on the local stack}}
return|return
operator|(
lambda|^
block|{
name|i
operator|=
literal|0
expr_stmt|;
block|}
operator|)
return|;
comment|// expected-error {{returning block that lives on the local stack}}
return|return
operator|(
name|void
operator|*
operator|)
operator|(
lambda|^
block|{
name|i
operator|=
literal|0
expr_stmt|;
block|}
operator|)
return|;
comment|// expected-error {{returning block that lives on the local stack}}
block|}
end_function

begin_function_decl
name|int
function_decl|(
modifier|*
name|funcptr3
index|[
literal|5
index|]
function_decl|)
parameter_list|(
name|long
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
name|int
name|sz8
init|=
sizeof|sizeof
argument_list|(
lambda|^
name|int
parameter_list|(
lambda|*[5]
argument_list|)
operator|(
name|long
operator|)
block|{
return|return
name|funcptr3
return|;
block|}
end_decl_stmt

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

begin_comment
comment|// expected-error {{block declared as returning an array}}
end_comment

begin_function
name|void
name|foo6
parameter_list|()
block|{
name|int
function_decl|(
modifier|^
name|b
function_decl|)
parameter_list|(
name|int
parameter_list|)
function_decl|__attribute__
parameter_list|(
function_decl|(noreturn
block|)
end_function

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

begin_expr_stmt
name|b
operator|=
operator|^
operator|(
name|int
name|i
operator|)
name|__attribute__
argument_list|(
argument|(noreturn)
argument_list|)
block|{
return|return
literal|1
return|;
block|}
end_expr_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
comment|// expected-error {{block declared 'noreturn' should not return}}
end_comment

begin_expr_stmt
name|b
argument_list|(
literal|1
argument_list|)
expr_stmt|;
end_expr_stmt

begin_function_decl
name|int
function_decl|(
modifier|^
name|c
function_decl|)
parameter_list|(
name|void
parameter_list|)
function_decl|__attribute__
parameter_list|(
function_decl|(noreturn
end_function_decl

begin_expr_stmt
unit|))
operator|=
lambda|^
name|__attribute__
parameter_list|(
lambda|(noreturn
end_expr_stmt

begin_block
unit|))
block|{
return|return
literal|100
return|;
block|}
end_block

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
comment|// expected-error {{block declared 'noreturn' should not return}}
end_comment

begin_macro
unit|}   void
name|foo7
argument_list|()
end_macro

begin_block
block|{
specifier|const
name|int
function_decl|(
modifier|^
name|BB
function_decl|)
parameter_list|(
name|void
parameter_list|)
init|=
lambda|^
block|{
specifier|const
name|int
name|i
operator|=
literal|1
function_decl|;
return|return
name|i
return|;
block|}
end_block

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
comment|// OK
end_comment

begin_function_decl
specifier|const
name|int
function_decl|(
modifier|^
name|CC
function_decl|)
parameter_list|(
name|void
parameter_list|)
init|=
lambda|^
specifier|const
name|int
block|{
specifier|const
name|int
name|i
operator|=
literal|1
function_decl|;
end_function_decl

begin_return
return|return
name|i
return|;
end_return

begin_comment
unit|};
comment|// OK
end_comment

begin_decl_stmt
name|int
name|i
decl_stmt|;
end_decl_stmt

begin_function_decl
name|int
function_decl|(
modifier|^
name|FF
function_decl|)
parameter_list|(
name|void
parameter_list|)
init|=
lambda|^
block|{
end_function_decl

begin_return
return|return
name|i
return|;
end_return

begin_comment
unit|};
comment|// OK
end_comment

begin_function_decl
name|int
function_decl|(
modifier|^
name|EE
function_decl|)
parameter_list|(
name|void
parameter_list|)
init|=
lambda|^
block|{
end_function_decl

begin_return
return|return
name|i
operator|+
literal|1
return|;
end_return

begin_comment
unit|};
comment|// OK
end_comment

begin_decl_stmt
specifier|__block
name|int
name|j
decl_stmt|;
end_decl_stmt

begin_function_decl
name|int
function_decl|(
modifier|^
name|JJ
function_decl|)
parameter_list|(
name|void
parameter_list|)
init|=
lambda|^
block|{
end_function_decl

begin_return
return|return
name|j
return|;
end_return

begin_comment
unit|};
comment|// OK
end_comment

begin_function_decl
name|int
function_decl|(
modifier|^
name|KK
function_decl|)
parameter_list|(
name|void
parameter_list|)
init|=
lambda|^
block|{
end_function_decl

begin_return
return|return
name|j
operator|+
literal|1
return|;
end_return

begin_comment
unit|};
comment|// OK
end_comment

begin_decl_stmt
specifier|__block
specifier|const
name|int
name|k
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|const
name|int
name|cint
init|=
literal|100
decl_stmt|;
end_decl_stmt

begin_function_decl
name|int
function_decl|(
modifier|^
name|MM
function_decl|)
parameter_list|(
name|void
parameter_list|)
init|=
lambda|^
block|{
end_function_decl

begin_return
return|return
name|k
return|;
end_return

begin_comment
unit|};
comment|// expected-error {{incompatible block pointer types initializing 'int const (^)(void)', expected 'int (^)(void)'}}
end_comment

begin_function_decl
name|int
function_decl|(
modifier|^
name|NN
function_decl|)
parameter_list|(
name|void
parameter_list|)
init|=
lambda|^
block|{
end_function_decl

begin_return
return|return
name|cint
return|;
end_return

begin_comment
unit|};
comment|// expected-error {{incompatible block pointer types initializing 'int const (^)(void)', expected 'int (^)(void)'}}
end_comment

unit|}
end_unit

