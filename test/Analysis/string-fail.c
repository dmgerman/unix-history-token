begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_analyze_cc1 -analyzer-checker=core,unix.cstring,debug.ExprInspection -analyzer-store=region -verify %s
end_comment

begin_comment
comment|// RUN: %clang_analyze_cc1 -DUSE_BUILTINS -analyzer-checker=core,unix.cstring,debug.ExprInspection -analyzer-store=region -verify %s
end_comment

begin_comment
comment|// XFAIL: *
end_comment

begin_comment
comment|// This file is for tests that may eventually go into string.c, or may be
end_comment

begin_comment
comment|// deleted outright. At one point these tests passed, but only because we
end_comment

begin_comment
comment|// weren't correctly modelling the behavior of the relevant string functions.
end_comment

begin_comment
comment|// The tests aren't incorrect, but require the analyzer to be smarter about
end_comment

begin_comment
comment|// conjured values than it currently is.
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
comment|// Functions that have variants and are also available as builtins should be
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

begin_define
define|#
directive|define
name|NULL
value|0
end_define

begin_typedef
typedef|typedef
name|typeof
argument_list|(
argument|sizeof(int)
argument_list|)
name|size_t
expr_stmt|;
end_typedef

begin_function_decl
name|void
name|clang_analyzer_eval
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|//===----------------------------------------------------------------------===
end_comment

begin_comment
comment|// strnlen()
end_comment

begin_comment
comment|//===----------------------------------------------------------------------===
end_comment

begin_define
define|#
directive|define
name|strnlen
value|BUILTIN(strnlen)
end_define

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
function_decl|;
end_function_decl

begin_function
name|void
name|strnlen_liveness
parameter_list|(
specifier|const
name|char
modifier|*
name|x
parameter_list|)
block|{
if|if
condition|(
name|strnlen
argument_list|(
name|x
argument_list|,
literal|10
argument_list|)
operator|<
literal|5
condition|)
return|return;
name|clang_analyzer_eval
argument_list|(
name|strnlen
argument_list|(
name|x
argument_list|,
literal|10
argument_list|)
operator|<
literal|5
argument_list|)
expr_stmt|;
comment|// expected-warning{{FALSE}}
block|}
end_function

begin_function
name|void
name|strnlen_subregion
parameter_list|()
block|{
struct|struct
name|two_stringsn
block|{
name|char
name|a
index|[
literal|2
index|]
decl_stmt|,
name|b
index|[
literal|2
index|]
decl_stmt|;
block|}
struct|;
specifier|extern
name|void
name|use_two_stringsn
argument_list|(
expr|struct
name|two_stringsn
operator|*
argument_list|)
decl_stmt|;
name|struct
name|two_stringsn
name|z
decl_stmt|;
name|use_two_stringsn
argument_list|(
operator|&
name|z
argument_list|)
expr_stmt|;
name|size_t
name|a
init|=
name|strnlen
argument_list|(
name|z
operator|.
name|a
argument_list|,
literal|10
argument_list|)
decl_stmt|;
name|z
operator|.
name|b
index|[
literal|0
index|]
operator|=
literal|5
expr_stmt|;
name|size_t
name|b
init|=
name|strnlen
argument_list|(
name|z
operator|.
name|a
argument_list|,
literal|10
argument_list|)
decl_stmt|;
if|if
condition|(
name|a
operator|==
literal|0
condition|)
name|clang_analyzer_eval
argument_list|(
name|b
operator|==
literal|0
argument_list|)
expr_stmt|;
comment|// expected-warning{{TRUE}}
name|use_two_stringsn
argument_list|(
operator|&
name|z
argument_list|)
expr_stmt|;
name|size_t
name|c
init|=
name|strnlen
argument_list|(
name|z
operator|.
name|a
argument_list|,
literal|10
argument_list|)
decl_stmt|;
if|if
condition|(
name|a
operator|==
literal|0
condition|)
name|clang_analyzer_eval
argument_list|(
name|c
operator|==
literal|0
argument_list|)
expr_stmt|;
comment|// expected-warning{{UNKNOWN}}
block|}
end_function

begin_function_decl
specifier|extern
name|void
name|use_stringn
parameter_list|(
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function
name|void
name|strnlen_argument
parameter_list|(
name|char
modifier|*
name|x
parameter_list|)
block|{
name|size_t
name|a
init|=
name|strnlen
argument_list|(
name|x
argument_list|,
literal|10
argument_list|)
decl_stmt|;
name|size_t
name|b
init|=
name|strnlen
argument_list|(
name|x
argument_list|,
literal|10
argument_list|)
decl_stmt|;
if|if
condition|(
name|a
operator|==
literal|0
condition|)
name|clang_analyzer_eval
argument_list|(
name|b
operator|==
literal|0
argument_list|)
expr_stmt|;
comment|// expected-warning{{TRUE}}
name|use_stringn
argument_list|(
name|x
argument_list|)
expr_stmt|;
name|size_t
name|c
init|=
name|strnlen
argument_list|(
name|x
argument_list|,
literal|10
argument_list|)
decl_stmt|;
if|if
condition|(
name|a
operator|==
literal|0
condition|)
name|clang_analyzer_eval
argument_list|(
name|c
operator|==
literal|0
argument_list|)
expr_stmt|;
comment|// expected-warning{{UNKNOWN}}
block|}
end_function

begin_decl_stmt
specifier|extern
name|char
name|global_strn
index|[]
decl_stmt|;
end_decl_stmt

begin_function
name|void
name|strnlen_global
parameter_list|()
block|{
name|size_t
name|a
init|=
name|strnlen
argument_list|(
name|global_strn
argument_list|,
literal|10
argument_list|)
decl_stmt|;
name|size_t
name|b
init|=
name|strnlen
argument_list|(
name|global_strn
argument_list|,
literal|10
argument_list|)
decl_stmt|;
if|if
condition|(
name|a
operator|==
literal|0
condition|)
name|clang_analyzer_eval
argument_list|(
name|b
operator|==
literal|0
argument_list|)
expr_stmt|;
comment|// expected-warning{{TRUE}}
comment|// Call a function with unknown effects, which should invalidate globals.
name|use_stringn
argument_list|(
literal|0
argument_list|)
expr_stmt|;
name|size_t
name|c
init|=
name|strnlen
argument_list|(
name|global_strn
argument_list|,
literal|10
argument_list|)
decl_stmt|;
if|if
condition|(
name|a
operator|==
literal|0
condition|)
name|clang_analyzer_eval
argument_list|(
name|c
operator|==
literal|0
argument_list|)
expr_stmt|;
comment|// expected-warning{{UNKNOWN}}
block|}
end_function

begin_function
name|void
name|strnlen_indirect
parameter_list|(
name|char
modifier|*
name|x
parameter_list|)
block|{
name|size_t
name|a
init|=
name|strnlen
argument_list|(
name|x
argument_list|,
literal|10
argument_list|)
decl_stmt|;
name|char
modifier|*
name|p
init|=
name|x
decl_stmt|;
name|char
modifier|*
modifier|*
name|p2
init|=
operator|&
name|p
decl_stmt|;
name|size_t
name|b
init|=
name|strnlen
argument_list|(
name|x
argument_list|,
literal|10
argument_list|)
decl_stmt|;
if|if
condition|(
name|a
operator|==
literal|0
condition|)
name|clang_analyzer_eval
argument_list|(
name|b
operator|==
literal|0
argument_list|)
expr_stmt|;
comment|// expected-warning{{TRUE}}
specifier|extern
name|void
name|use_stringn_ptr
argument_list|(
name|char
operator|*
specifier|const
operator|*
argument_list|)
decl_stmt|;
name|use_stringn_ptr
argument_list|(
name|p2
argument_list|)
expr_stmt|;
name|size_t
name|c
init|=
name|strnlen
argument_list|(
name|x
argument_list|,
literal|10
argument_list|)
decl_stmt|;
if|if
condition|(
name|a
operator|==
literal|0
condition|)
name|clang_analyzer_eval
argument_list|(
name|c
operator|==
literal|0
argument_list|)
expr_stmt|;
comment|// expected-warning{{UNKNOWN}}
block|}
end_function

end_unit

