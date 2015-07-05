begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 %s -verify
end_comment

begin_comment
comment|// RUN: %clang_cc1 %s -DCODEGEN -emit-llvm -o - | FileCheck %s
end_comment

begin_define
define|#
directive|define
name|O_CREAT
value|0x100
end_define

begin_typedef
typedef|typedef
name|int
name|mode_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|unsigned
name|long
name|size_t
typedef|;
end_typedef

begin_function_decl
name|int
name|open
parameter_list|(
specifier|const
name|char
modifier|*
name|pathname
parameter_list|,
name|int
name|flags
parameter_list|)
function_decl|__attribute__
parameter_list|(
function_decl|(enable_if
parameter_list|(
function_decl|!
parameter_list|(
name|flags
modifier|&
name|O_CREAT
parameter_list|)
operator|,
function_decl|"must specify mode when using O_CREAT"
end_function_decl

begin_expr_stmt
unit|)))
name|__attribute__
argument_list|(
operator|(
name|overloadable
operator|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|// expected-note{{candidate disabled: must specify mode when using O_CREAT}}
end_comment

begin_function_decl
name|int
name|open
parameter_list|(
specifier|const
name|char
modifier|*
name|pathname
parameter_list|,
name|int
name|flags
parameter_list|,
name|mode_t
name|mode
parameter_list|)
function_decl|__attribute__
parameter_list|(
function_decl|(overloadable
end_function_decl

begin_empty_stmt
unit|))
empty_stmt|;
end_empty_stmt

begin_comment
comment|// expected-note{{candidate function not viable: requires 3 arguments, but 2 were provided}}
end_comment

begin_function
name|void
name|test1
parameter_list|()
block|{
ifndef|#
directive|ifndef
name|CODEGEN
name|open
argument_list|(
literal|"path"
argument_list|,
name|O_CREAT
argument_list|)
expr_stmt|;
comment|// expected-error{{no matching function for call to 'open'}}
endif|#
directive|endif
name|open
argument_list|(
literal|"path"
argument_list|,
name|O_CREAT
argument_list|,
literal|0660
argument_list|)
expr_stmt|;
name|open
argument_list|(
literal|"path"
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|open
argument_list|(
literal|"path"
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
block|}
end_function

begin_function_decl
name|size_t
name|__strnlen_chk
parameter_list|(
specifier|const
name|char
modifier|*
name|s
parameter_list|,
name|size_t
name|requested_amount
parameter_list|,
name|size_t
name|s_len
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
name|size_t
name|strnlen
argument_list|(
specifier|const
name|char
operator|*
name|s
argument_list|,
name|size_t
name|maxlen
argument_list|)
comment|// expected-note{{candidate function}}
name|__attribute__
argument_list|(
operator|(
name|overloadable
operator|)
argument_list|)
name|__asm__
argument_list|(
literal|"strnlen_real1"
argument_list|)
decl_stmt|;
end_decl_stmt

begin_macro
name|__attribute__
argument_list|(
argument|(always_inline)
argument_list|)
end_macro

begin_function
specifier|inline
name|size_t
name|strnlen
parameter_list|(
specifier|const
name|char
modifier|*
name|s
parameter_list|,
name|size_t
name|maxlen
parameter_list|)
comment|// expected-note{{candidate function}}
function|__attribute__
parameter_list|(
function|(overloadable
end_function

begin_macro
unit|))
name|__attribute__
argument_list|(
argument|(enable_if(__builtin_object_size(s,
literal|0
argument|) != -
literal|1
argument|,
literal|"chosen when target buffer size is known"
argument|))
argument_list|)
end_macro

begin_block
block|{
return|return
name|__strnlen_chk
argument_list|(
name|s
argument_list|,
name|maxlen
argument_list|,
name|__builtin_object_size
argument_list|(
name|s
argument_list|,
literal|0
argument_list|)
argument_list|)
return|;
block|}
end_block

begin_decl_stmt
name|size_t
name|strnlen
argument_list|(
specifier|const
name|char
operator|*
name|s
argument_list|,
name|size_t
name|maxlen
argument_list|)
comment|// expected-note{{candidate disabled: chosen when 'maxlen' is known to be less than or equal to the buffer size}}
name|__attribute__
argument_list|(
operator|(
name|overloadable
operator|)
argument_list|)
name|__attribute__
argument_list|(
operator|(
name|enable_if
argument_list|(
name|__builtin_object_size
argument_list|(
name|s
argument_list|,
literal|0
argument_list|)
operator|!=
operator|-
literal|1
argument_list|,
literal|"chosen when target buffer size is known"
argument_list|)
operator|)
argument_list|)
name|__attribute__
argument_list|(
operator|(
name|enable_if
argument_list|(
name|maxlen
operator|<=
name|__builtin_object_size
argument_list|(
name|s
argument_list|,
literal|0
argument_list|)
argument_list|,
literal|"chosen when 'maxlen' is known to be less than or equal to the buffer size"
argument_list|)
operator|)
argument_list|)
name|__asm__
argument_list|(
literal|"strnlen_real2"
argument_list|)
decl_stmt|;
end_decl_stmt

begin_function_decl
name|size_t
name|strnlen
parameter_list|(
specifier|const
name|char
modifier|*
name|s
parameter_list|,
name|size_t
name|maxlen
parameter_list|)
comment|// expected-note{{candidate function has been explicitly made unavailable}}
function_decl|__attribute__
parameter_list|(
function_decl|(overloadable
end_function_decl

begin_macro
unit|))
name|__attribute__
argument_list|(
argument|(enable_if(__builtin_object_size(s,
literal|0
argument|) != -
literal|1
argument|,
literal|"chosen when target buffer size is known"
argument|))
argument_list|)
end_macro

begin_macro
name|__attribute__
argument_list|(
argument|(enable_if(maxlen> __builtin_object_size(s,
literal|0
argument|),
literal|"chosen when 'maxlen' is larger than the buffer size"
argument|))
argument_list|)
end_macro

begin_expr_stmt
name|__attribute__
argument_list|(
operator|(
name|unavailable
argument_list|(
literal|"'maxlen' is larger than the buffer size"
argument_list|)
operator|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_function
name|void
name|test2
parameter_list|(
specifier|const
name|char
modifier|*
name|s
parameter_list|,
name|int
name|i
parameter_list|)
block|{
comment|// CHECK: define {{.*}}void @test2
specifier|const
name|char
name|c
index|[
literal|123
index|]
decl_stmt|;
name|strnlen
argument_list|(
name|s
argument_list|,
name|i
argument_list|)
expr_stmt|;
comment|// CHECK: call {{.*}}strnlen_real1
name|strnlen
argument_list|(
name|s
argument_list|,
literal|999
argument_list|)
expr_stmt|;
comment|// CHECK: call {{.*}}strnlen_real1
name|strnlen
argument_list|(
name|c
argument_list|,
literal|1
argument_list|)
expr_stmt|;
comment|// CHECK: call {{.*}}strnlen_real2
name|strnlen
argument_list|(
name|c
argument_list|,
name|i
argument_list|)
expr_stmt|;
comment|// CHECK: call {{.*}}strnlen_chk
ifndef|#
directive|ifndef
name|CODEGEN
name|strnlen
argument_list|(
name|c
argument_list|,
literal|999
argument_list|)
expr_stmt|;
comment|// expected-error{{call to unavailable function 'strnlen': 'maxlen' is larger than the buffer size}}
endif|#
directive|endif
block|}
end_function

begin_function_decl
name|int
name|isdigit
parameter_list|(
name|int
name|c
parameter_list|)
function_decl|__attribute__
parameter_list|(
function_decl|(overloadable
end_function_decl

begin_empty_stmt
unit|))
empty_stmt|;
end_empty_stmt

begin_comment
comment|// expected-note{{candidate function}}
end_comment

begin_function_decl
name|int
name|isdigit
parameter_list|(
name|int
name|c
parameter_list|)
function_decl|__attribute__
parameter_list|(
function_decl|(overloadable
end_function_decl

begin_comment
unit|))
comment|// expected-note{{candidate function has been explicitly made unavailable}}
end_comment

begin_macro
name|__attribute__
argument_list|(
argument|(enable_if(c<= -
literal|1
argument||| c>
literal|255
argument|,
literal|"'c' must have the value of an unsigned char or EOF"
argument|))
argument_list|)
end_macro

begin_expr_stmt
name|__attribute__
argument_list|(
operator|(
name|unavailable
argument_list|(
literal|"'c' must have the value of an unsigned char or EOF"
argument_list|)
operator|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_function
name|void
name|test3
parameter_list|(
name|int
name|c
parameter_list|)
block|{
name|isdigit
argument_list|(
name|c
argument_list|)
expr_stmt|;
name|isdigit
argument_list|(
literal|10
argument_list|)
expr_stmt|;
ifndef|#
directive|ifndef
name|CODEGEN
name|isdigit
argument_list|(
operator|-
literal|10
argument_list|)
expr_stmt|;
comment|// expected-error{{call to unavailable function 'isdigit': 'c' must have the value of an unsigned char or EOF}}
endif|#
directive|endif
block|}
end_function

begin_ifndef
ifndef|#
directive|ifndef
name|CODEGEN
end_ifndef

begin_macro
name|__attribute__
argument_list|(
argument|(enable_if(n ==
literal|0
argument|,
literal|"chosen when 'n' is zero"
argument|))
argument_list|)
end_macro

begin_function_decl
name|void
name|f1
parameter_list|(
name|int
name|n
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|// expected-error{{use of undeclared identifier 'n'}}
end_comment

begin_decl_stmt
name|int
name|n
name|__attribute__
argument_list|(
operator|(
name|enable_if
argument_list|(
literal|1
argument_list|,
literal|"always chosen"
argument_list|)
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|// expected-warning{{'enable_if' attribute only applies to functions}}
end_comment

begin_function_decl
name|void
name|f
parameter_list|(
name|int
name|n
parameter_list|)
function_decl|__attribute__
parameter_list|(
function_decl|(enable_if
parameter_list|(
function_decl|"chosen when 'n' is zero"
operator|,
function_decl|n == 0
end_function_decl

begin_empty_stmt
unit|)))
empty_stmt|;
end_empty_stmt

begin_comment
comment|// expected-error{{'enable_if' attribute requires a string}}
end_comment

begin_function_decl
name|void
name|f
parameter_list|(
name|int
name|n
parameter_list|)
function_decl|__attribute__
parameter_list|(
function_decl|(enable_if
parameter_list|()
end_function_decl

begin_empty_stmt
unit|))
empty_stmt|;
end_empty_stmt

begin_comment
comment|// expected-error{{'enable_if' attribute requires exactly 2 arguments}}
end_comment

begin_function_decl
name|void
name|f
parameter_list|(
name|int
name|n
parameter_list|)
function_decl|__attribute__
parameter_list|(
function_decl|(enable_if
parameter_list|(
name|unresolvedid
parameter_list|,
function_decl|"chosen when 'unresolvedid' is non-zero"
end_function_decl

begin_empty_stmt
unit|)))
empty_stmt|;
end_empty_stmt

begin_comment
comment|// expected-error{{use of undeclared identifier 'unresolvedid'}}
end_comment

begin_decl_stmt
name|int
name|global
decl_stmt|;
end_decl_stmt

begin_function_decl
name|void
name|f
parameter_list|(
name|int
name|n
parameter_list|)
function_decl|__attribute__
parameter_list|(
function_decl|(enable_if
parameter_list|(
function_decl|global == 0
operator|,
function_decl|"chosen when 'global' is zero"
end_function_decl

begin_empty_stmt
unit|)))
empty_stmt|;
end_empty_stmt

begin_comment
comment|// expected-error{{'enable_if' attribute expression never produces a constant expression}}  // expected-note{{subexpression not valid in a constant expression}}
end_comment

begin_decl_stmt
specifier|const
name|int
name|cst
init|=
literal|7
decl_stmt|;
end_decl_stmt

begin_function_decl
name|void
name|return_cst
parameter_list|(
name|void
parameter_list|)
function_decl|__attribute__
parameter_list|(
function_decl|(overloadable
end_function_decl

begin_expr_stmt
unit|))
name|__attribute__
argument_list|(
operator|(
name|enable_if
argument_list|(
name|cst
operator|==
literal|7
argument_list|,
literal|"chosen when 'cst' is 7"
argument_list|)
operator|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_function
name|void
name|test_return_cst
parameter_list|()
block|{
name|return_cst
argument_list|()
expr_stmt|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

end_unit

