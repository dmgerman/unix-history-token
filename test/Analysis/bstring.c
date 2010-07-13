begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -analyze -analyzer-experimental-internal-checks -analyzer-check-objc-mem -analyzer-store=region -analyzer-experimental-checks -verify %s
end_comment

begin_comment
comment|// RUN: %clang_cc1 -analyze -DUSE_BUILTINS -analyzer-experimental-internal-checks -analyzer-check-objc-mem -analyzer-store=region -analyzer-experimental-checks -verify %s
end_comment

begin_comment
comment|// RUN: %clang_cc1 -analyze -DVARIANT -analyzer-experimental-internal-checks -analyzer-check-objc-mem -analyzer-store=region -analyzer-experimental-checks -verify %s
end_comment

begin_comment
comment|// RUN: %clang_cc1 -analyze -DUSE_BUILTINS -DVARIANT -analyzer-experimental-internal-checks -analyzer-check-objc-mem -analyzer-store=region -analyzer-experimental-checks -verify %s
end_comment

begin_comment
comment|//===----------------------------------------------------------------------===
end_comment

begin_comment
comment|// Declarations
end_comment

begin_comment
comment|//===----------------------------------------------------------------------===
end_comment

begin_comment
comment|// Some functions are so similar to each other that they follow the same code
end_comment

begin_comment
comment|// path, such as memcpy and __memcpy_chk, or memcmp and bcmp. If VARIANT is
end_comment

begin_comment
comment|// defined, make sure to use the variants instead to make sure they are still
end_comment

begin_comment
comment|// checked by the analyzer.
end_comment

begin_comment
comment|// Some functions are implemented as builtins. These should be #defined as
end_comment

begin_comment
comment|// BUILTIN(f), which will prepend "__builtin_" if USE_BUILTINS is defined.
end_comment

begin_comment
comment|// Functions that have variants and are also availabe as builtins should be
end_comment

begin_comment
comment|// declared carefully! See memcpy() for an example.
end_comment

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

begin_comment
comment|/* USE_BUILTINS */
end_comment

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

begin_comment
comment|/* USE_BUILTINS */
end_comment

begin_typedef
typedef|typedef
name|typeof
argument_list|(
argument|sizeof(int)
argument_list|)
name|size_t
expr_stmt|;
end_typedef

begin_comment
comment|//===----------------------------------------------------------------------===
end_comment

begin_comment
comment|// memcpy()
end_comment

begin_comment
comment|//===----------------------------------------------------------------------===
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|VARIANT
end_ifdef

begin_define
define|#
directive|define
name|__memcpy_chk
value|BUILTIN(__memcpy_chk)
end_define

begin_function_decl
name|void
modifier|*
name|__memcpy_chk
parameter_list|(
name|void
modifier|*
specifier|restrict
name|s1
parameter_list|,
specifier|const
name|void
modifier|*
specifier|restrict
name|s2
parameter_list|,
name|size_t
name|n
parameter_list|,
name|size_t
name|destlen
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|memcpy
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|,
name|c
parameter_list|)
value|__memcpy_chk(a,b,c,(size_t)-1)
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* VARIANT */
end_comment

begin_define
define|#
directive|define
name|memcpy
value|BUILTIN(memcpy)
end_define

begin_function_decl
name|void
modifier|*
name|memcpy
parameter_list|(
name|void
modifier|*
specifier|restrict
name|s1
parameter_list|,
specifier|const
name|void
modifier|*
specifier|restrict
name|s2
parameter_list|,
name|size_t
name|n
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* VARIANT */
end_comment

begin_function
name|void
name|memcpy0
parameter_list|()
block|{
name|char
name|src
index|[]
init|=
block|{
literal|1
block|,
literal|2
block|,
literal|3
block|,
literal|4
block|}
decl_stmt|;
name|char
name|dst
index|[
literal|4
index|]
decl_stmt|;
name|memcpy
argument_list|(
name|dst
argument_list|,
name|src
argument_list|,
literal|4
argument_list|)
expr_stmt|;
comment|// no-warning
if|if
condition|(
name|memcpy
argument_list|(
name|dst
argument_list|,
name|src
argument_list|,
literal|4
argument_list|)
operator|!=
name|dst
condition|)
block|{
operator|(
name|void
operator|)
operator|*
operator|(
name|char
operator|*
operator|)
literal|0
expr_stmt|;
comment|// no-warning -- should be unreachable
block|}
block|}
end_function

begin_function
name|void
name|memcpy1
parameter_list|()
block|{
name|char
name|src
index|[]
init|=
block|{
literal|1
block|,
literal|2
block|,
literal|3
block|,
literal|4
block|}
decl_stmt|;
name|char
name|dst
index|[
literal|10
index|]
decl_stmt|;
name|memcpy
argument_list|(
name|dst
argument_list|,
name|src
argument_list|,
literal|5
argument_list|)
expr_stmt|;
comment|// expected-warning{{out-of-bound}}
block|}
end_function

begin_function
name|void
name|memcpy2
parameter_list|()
block|{
name|char
name|src
index|[]
init|=
block|{
literal|1
block|,
literal|2
block|,
literal|3
block|,
literal|4
block|}
decl_stmt|;
name|char
name|dst
index|[
literal|1
index|]
decl_stmt|;
name|memcpy
argument_list|(
name|dst
argument_list|,
name|src
argument_list|,
literal|4
argument_list|)
expr_stmt|;
comment|// expected-warning{{out-of-bound}}
block|}
end_function

begin_function
name|void
name|memcpy3
parameter_list|()
block|{
name|char
name|src
index|[]
init|=
block|{
literal|1
block|,
literal|2
block|,
literal|3
block|,
literal|4
block|}
decl_stmt|;
name|char
name|dst
index|[
literal|3
index|]
decl_stmt|;
name|memcpy
argument_list|(
name|dst
operator|+
literal|1
argument_list|,
name|src
operator|+
literal|2
argument_list|,
literal|2
argument_list|)
expr_stmt|;
comment|// no-warning
block|}
end_function

begin_function
name|void
name|memcpy4
parameter_list|()
block|{
name|char
name|src
index|[]
init|=
block|{
literal|1
block|,
literal|2
block|,
literal|3
block|,
literal|4
block|}
decl_stmt|;
name|char
name|dst
index|[
literal|10
index|]
decl_stmt|;
name|memcpy
argument_list|(
name|dst
operator|+
literal|2
argument_list|,
name|src
operator|+
literal|2
argument_list|,
literal|3
argument_list|)
expr_stmt|;
comment|// expected-warning{{out-of-bound}}
block|}
end_function

begin_function
name|void
name|memcpy5
parameter_list|()
block|{
name|char
name|src
index|[]
init|=
block|{
literal|1
block|,
literal|2
block|,
literal|3
block|,
literal|4
block|}
decl_stmt|;
name|char
name|dst
index|[
literal|3
index|]
decl_stmt|;
name|memcpy
argument_list|(
name|dst
operator|+
literal|2
argument_list|,
name|src
operator|+
literal|2
argument_list|,
literal|2
argument_list|)
expr_stmt|;
comment|// expected-warning{{out-of-bound}}
block|}
end_function

begin_function
name|void
name|memcpy6
parameter_list|()
block|{
name|int
name|a
index|[
literal|4
index|]
init|=
block|{
literal|0
block|}
decl_stmt|;
name|memcpy
argument_list|(
name|a
argument_list|,
name|a
argument_list|,
literal|8
argument_list|)
expr_stmt|;
comment|// expected-warning{{overlapping}}
block|}
end_function

begin_function
name|void
name|memcpy7
parameter_list|()
block|{
name|int
name|a
index|[
literal|4
index|]
init|=
block|{
literal|0
block|}
decl_stmt|;
name|memcpy
argument_list|(
name|a
operator|+
literal|2
argument_list|,
name|a
operator|+
literal|1
argument_list|,
literal|8
argument_list|)
expr_stmt|;
comment|// expected-warning{{overlapping}}
block|}
end_function

begin_function
name|void
name|memcpy8
parameter_list|()
block|{
name|int
name|a
index|[
literal|4
index|]
init|=
block|{
literal|0
block|}
decl_stmt|;
name|memcpy
argument_list|(
name|a
operator|+
literal|1
argument_list|,
name|a
operator|+
literal|2
argument_list|,
literal|8
argument_list|)
expr_stmt|;
comment|// expected-warning{{overlapping}}
block|}
end_function

begin_function
name|void
name|memcpy9
parameter_list|()
block|{
name|int
name|a
index|[
literal|4
index|]
init|=
block|{
literal|0
block|}
decl_stmt|;
name|memcpy
argument_list|(
name|a
operator|+
literal|2
argument_list|,
name|a
operator|+
literal|1
argument_list|,
literal|4
argument_list|)
expr_stmt|;
comment|// no-warning
name|memcpy
argument_list|(
name|a
operator|+
literal|1
argument_list|,
name|a
operator|+
literal|2
argument_list|,
literal|4
argument_list|)
expr_stmt|;
comment|// no-warning
block|}
end_function

begin_function
name|void
name|memcpy10
parameter_list|()
block|{
name|char
name|a
index|[
literal|4
index|]
init|=
block|{
literal|0
block|}
decl_stmt|;
name|memcpy
argument_list|(
literal|0
argument_list|,
name|a
argument_list|,
literal|4
argument_list|)
expr_stmt|;
comment|// expected-warning{{Null pointer argument in call to byte string function}}
block|}
end_function

begin_function
name|void
name|memcpy11
parameter_list|()
block|{
name|char
name|a
index|[
literal|4
index|]
init|=
block|{
literal|0
block|}
decl_stmt|;
name|memcpy
argument_list|(
name|a
argument_list|,
literal|0
argument_list|,
literal|4
argument_list|)
expr_stmt|;
comment|// expected-warning{{Null pointer argument in call to byte string function}}
block|}
end_function

begin_function
name|void
name|memcpy12
parameter_list|()
block|{
name|char
name|a
index|[
literal|4
index|]
init|=
block|{
literal|0
block|}
decl_stmt|;
name|memcpy
argument_list|(
literal|0
argument_list|,
name|a
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// no-warning
name|memcpy
argument_list|(
name|a
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// no-warning
block|}
end_function

begin_comment
comment|//===----------------------------------------------------------------------===
end_comment

begin_comment
comment|// memmove()
end_comment

begin_comment
comment|//===----------------------------------------------------------------------===
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|VARIANT
end_ifdef

begin_define
define|#
directive|define
name|__memmove_chk
value|BUILTIN(__memmove_chk)
end_define

begin_function_decl
name|void
modifier|*
name|__memmove_chk
parameter_list|(
name|void
modifier|*
name|s1
parameter_list|,
specifier|const
name|void
modifier|*
name|s2
parameter_list|,
name|size_t
name|n
parameter_list|,
name|size_t
name|destlen
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|memmove
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|,
name|c
parameter_list|)
value|__memmove_chk(a,b,c,(size_t)-1)
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* VARIANT */
end_comment

begin_define
define|#
directive|define
name|memmove
value|BUILTIN(memmove)
end_define

begin_function_decl
name|void
modifier|*
name|memmove
parameter_list|(
name|void
modifier|*
name|s1
parameter_list|,
specifier|const
name|void
modifier|*
name|s2
parameter_list|,
name|size_t
name|n
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* VARIANT */
end_comment

begin_function
name|void
name|memmove0
parameter_list|()
block|{
name|char
name|src
index|[]
init|=
block|{
literal|1
block|,
literal|2
block|,
literal|3
block|,
literal|4
block|}
decl_stmt|;
name|char
name|dst
index|[
literal|4
index|]
decl_stmt|;
name|memmove
argument_list|(
name|dst
argument_list|,
name|src
argument_list|,
literal|4
argument_list|)
expr_stmt|;
comment|// no-warning
if|if
condition|(
name|memmove
argument_list|(
name|dst
argument_list|,
name|src
argument_list|,
literal|4
argument_list|)
operator|!=
name|dst
condition|)
block|{
operator|(
name|void
operator|)
operator|*
operator|(
name|char
operator|*
operator|)
literal|0
expr_stmt|;
comment|// no-warning -- should be unreachable
block|}
block|}
end_function

begin_function
name|void
name|memmove1
parameter_list|()
block|{
name|char
name|src
index|[]
init|=
block|{
literal|1
block|,
literal|2
block|,
literal|3
block|,
literal|4
block|}
decl_stmt|;
name|char
name|dst
index|[
literal|10
index|]
decl_stmt|;
name|memmove
argument_list|(
name|dst
argument_list|,
name|src
argument_list|,
literal|5
argument_list|)
expr_stmt|;
comment|// expected-warning{{out-of-bound}}
block|}
end_function

begin_function
name|void
name|memmove2
parameter_list|()
block|{
name|char
name|src
index|[]
init|=
block|{
literal|1
block|,
literal|2
block|,
literal|3
block|,
literal|4
block|}
decl_stmt|;
name|char
name|dst
index|[
literal|1
index|]
decl_stmt|;
name|memmove
argument_list|(
name|dst
argument_list|,
name|src
argument_list|,
literal|4
argument_list|)
expr_stmt|;
comment|// expected-warning{{out-of-bound}}
block|}
end_function

begin_comment
comment|//===----------------------------------------------------------------------===
end_comment

begin_comment
comment|// memcmp()
end_comment

begin_comment
comment|//===----------------------------------------------------------------------===
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|VARIANT
end_ifdef

begin_define
define|#
directive|define
name|bcmp
value|BUILTIN(bcmp)
end_define

begin_comment
comment|// __builtin_bcmp is not defined with const in Builtins.def.
end_comment

begin_function_decl
name|int
name|bcmp
parameter_list|(
comment|/*const*/
name|void
modifier|*
name|s1
parameter_list|,
comment|/*const*/
name|void
modifier|*
name|s2
parameter_list|,
name|size_t
name|n
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|memcmp
value|bcmp
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* VARIANT */
end_comment

begin_define
define|#
directive|define
name|memcmp
value|BUILTIN(memcmp)
end_define

begin_function_decl
name|int
name|memcmp
parameter_list|(
specifier|const
name|void
modifier|*
name|s1
parameter_list|,
specifier|const
name|void
modifier|*
name|s2
parameter_list|,
name|size_t
name|n
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* VARIANT */
end_comment

begin_function
name|void
name|memcmp0
parameter_list|()
block|{
name|char
name|a
index|[]
init|=
block|{
literal|1
block|,
literal|2
block|,
literal|3
block|,
literal|4
block|}
decl_stmt|;
name|char
name|b
index|[
literal|4
index|]
init|=
block|{
literal|0
block|}
decl_stmt|;
name|memcmp
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|4
argument_list|)
expr_stmt|;
comment|// no-warning
block|}
end_function

begin_function
name|void
name|memcmp1
parameter_list|()
block|{
name|char
name|a
index|[]
init|=
block|{
literal|1
block|,
literal|2
block|,
literal|3
block|,
literal|4
block|}
decl_stmt|;
name|char
name|b
index|[
literal|10
index|]
init|=
block|{
literal|0
block|}
decl_stmt|;
name|memcmp
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|5
argument_list|)
expr_stmt|;
comment|// expected-warning{{out-of-bound}}
block|}
end_function

begin_function
name|void
name|memcmp2
parameter_list|()
block|{
name|char
name|a
index|[]
init|=
block|{
literal|1
block|,
literal|2
block|,
literal|3
block|,
literal|4
block|}
decl_stmt|;
name|char
name|b
index|[
literal|1
index|]
init|=
block|{
literal|0
block|}
decl_stmt|;
name|memcmp
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|4
argument_list|)
expr_stmt|;
comment|// expected-warning{{out-of-bound}}
block|}
end_function

begin_function
name|void
name|memcmp3
parameter_list|()
block|{
name|char
name|a
index|[]
init|=
block|{
literal|1
block|,
literal|2
block|,
literal|3
block|,
literal|4
block|}
decl_stmt|;
if|if
condition|(
name|memcmp
argument_list|(
name|a
argument_list|,
name|a
argument_list|,
literal|4
argument_list|)
condition|)
operator|(
name|void
operator|)
operator|*
operator|(
name|char
operator|*
operator|)
literal|0
expr_stmt|;
comment|// no-warning
block|}
end_function

begin_function
name|void
name|memcmp4
parameter_list|(
name|char
modifier|*
name|input
parameter_list|)
block|{
name|char
name|a
index|[]
init|=
block|{
literal|1
block|,
literal|2
block|,
literal|3
block|,
literal|4
block|}
decl_stmt|;
if|if
condition|(
name|memcmp
argument_list|(
name|a
argument_list|,
name|input
argument_list|,
literal|4
argument_list|)
condition|)
operator|(
name|void
operator|)
operator|*
operator|(
name|char
operator|*
operator|)
literal|0
expr_stmt|;
comment|// expected-warning{{null}}
block|}
end_function

begin_function
name|void
name|memcmp5
parameter_list|(
name|char
modifier|*
name|input
parameter_list|)
block|{
name|char
name|a
index|[]
init|=
block|{
literal|1
block|,
literal|2
block|,
literal|3
block|,
literal|4
block|}
decl_stmt|;
if|if
condition|(
name|memcmp
argument_list|(
name|a
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
condition|)
comment|// no-warning
operator|(
name|void
operator|)
operator|*
operator|(
name|char
operator|*
operator|)
literal|0
expr_stmt|;
comment|// no-warning
if|if
condition|(
name|memcmp
argument_list|(
literal|0
argument_list|,
name|a
argument_list|,
literal|0
argument_list|)
condition|)
comment|// no-warning
operator|(
name|void
operator|)
operator|*
operator|(
name|char
operator|*
operator|)
literal|0
expr_stmt|;
comment|// no-warning
if|if
condition|(
name|memcmp
argument_list|(
name|a
argument_list|,
name|input
argument_list|,
literal|0
argument_list|)
condition|)
comment|// no-warning
operator|(
name|void
operator|)
operator|*
operator|(
name|char
operator|*
operator|)
literal|0
expr_stmt|;
comment|// no-warning
block|}
end_function

begin_function
name|void
name|memcmp6
parameter_list|(
name|char
modifier|*
name|a
parameter_list|,
name|char
modifier|*
name|b
parameter_list|,
name|size_t
name|n
parameter_list|)
block|{
name|int
name|result
init|=
name|memcmp
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|n
argument_list|)
decl_stmt|;
if|if
condition|(
name|result
operator|!=
literal|0
condition|)
return|return;
if|if
condition|(
name|n
operator|==
literal|0
condition|)
operator|(
name|void
operator|)
operator|*
operator|(
name|char
operator|*
operator|)
literal|0
expr_stmt|;
comment|// expected-warning{{null}}
block|}
end_function

begin_comment
comment|//===----------------------------------------------------------------------===
end_comment

begin_comment
comment|// bcopy()
end_comment

begin_comment
comment|//===----------------------------------------------------------------------===
end_comment

begin_define
define|#
directive|define
name|bcopy
value|BUILTIN(bcopy)
end_define

begin_comment
comment|// __builtin_bcopy is not defined with const in Builtins.def.
end_comment

begin_function_decl
name|void
name|bcopy
parameter_list|(
comment|/*const*/
name|void
modifier|*
name|s1
parameter_list|,
name|void
modifier|*
name|s2
parameter_list|,
name|size_t
name|n
parameter_list|)
function_decl|;
end_function_decl

begin_function
name|void
name|bcopy0
parameter_list|()
block|{
name|char
name|src
index|[]
init|=
block|{
literal|1
block|,
literal|2
block|,
literal|3
block|,
literal|4
block|}
decl_stmt|;
name|char
name|dst
index|[
literal|4
index|]
decl_stmt|;
name|bcopy
argument_list|(
name|src
argument_list|,
name|dst
argument_list|,
literal|4
argument_list|)
expr_stmt|;
comment|// no-warning
block|}
end_function

begin_function
name|void
name|bcopy1
parameter_list|()
block|{
name|char
name|src
index|[]
init|=
block|{
literal|1
block|,
literal|2
block|,
literal|3
block|,
literal|4
block|}
decl_stmt|;
name|char
name|dst
index|[
literal|10
index|]
decl_stmt|;
name|bcopy
argument_list|(
name|src
argument_list|,
name|dst
argument_list|,
literal|5
argument_list|)
expr_stmt|;
comment|// expected-warning{{out-of-bound}}
block|}
end_function

begin_function
name|void
name|bcopy2
parameter_list|()
block|{
name|char
name|src
index|[]
init|=
block|{
literal|1
block|,
literal|2
block|,
literal|3
block|,
literal|4
block|}
decl_stmt|;
name|char
name|dst
index|[
literal|1
index|]
decl_stmt|;
name|bcopy
argument_list|(
name|src
argument_list|,
name|dst
argument_list|,
literal|4
argument_list|)
expr_stmt|;
comment|// expected-warning{{out-of-bound}}
block|}
end_function

end_unit

