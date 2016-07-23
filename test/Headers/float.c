begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -fsyntax-only -verify -std=c89 -ffreestanding %s
end_comment

begin_comment
comment|// RUN: %clang_cc1 -fsyntax-only -verify -std=c99 -ffreestanding %s
end_comment

begin_comment
comment|// RUN: %clang_cc1 -fsyntax-only -verify -std=c11 -ffreestanding %s
end_comment

begin_comment
comment|// expected-no-diagnostics
end_comment

begin_comment
comment|/* Basic floating point conformance checks against:     - N1570 draft of C11 Std.     - N1256 draft of C99 Std.     - http://port70.net/~nsz/c/c89/c89-draft.html draft of C89/C90 Std. */
end_comment

begin_comment
comment|/*     C11,    5.2.4.2.2p11,   pp. 30     C99,    5.2.4.2.2p9,    pp. 25     C89,    2.2.4.2  */
end_comment

begin_include
include|#
directive|include
file|<float.h>
end_include

begin_ifndef
ifndef|#
directive|ifndef
name|FLT_RADIX
end_ifndef

begin_error
error|#
directive|error
literal|"Mandatory macro FLT_RADIX is missing."
end_error

begin_elif
elif|#
directive|elif
name|FLT_RADIX
operator|<
literal|2
end_elif

begin_error
error|#
directive|error
literal|"Mandatory macro FLT_RADIX is invalid."
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|FLT_MANT_DIG
end_ifndef

begin_error
error|#
directive|error
literal|"Mandatory macro FLT_MANT_DIG is missing."
end_error

begin_elif
elif|#
directive|elif
name|FLT_MANT_DIG
operator|<
literal|2
end_elif

begin_error
error|#
directive|error
literal|"Mandatory macro FLT_MANT_DIG is invalid."
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|DBL_MANT_DIG
end_ifndef

begin_error
error|#
directive|error
literal|"Mandatory macro DBL_MANT_DIG is missing."
end_error

begin_elif
elif|#
directive|elif
name|DBL_MANT_DIG
operator|<
literal|2
end_elif

begin_error
error|#
directive|error
literal|"Mandatory macro DBL_MANT_DIG is invalid."
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|LDBL_MANT_DIG
end_ifndef

begin_error
error|#
directive|error
literal|"Mandatory macro LDBL_MANT_DIG is missing."
end_error

begin_elif
elif|#
directive|elif
name|LDBL_MANT_DIG
operator|<
literal|2
end_elif

begin_error
error|#
directive|error
literal|"Mandatory macro LDBL_MANT_DIG is invalid."
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
operator|(
operator|(
name|FLT_MANT_DIG
operator|>
name|DBL_MANT_DIG
operator|)
operator|||
operator|(
name|DBL_MANT_DIG
operator|>
name|LDBL_MANT_DIG
operator|)
operator|)
end_if

begin_error
error|#
directive|error
literal|"Mandatory macros {FLT,DBL,LDBL}_MANT_DIG are invalid."
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|__STDC_VERSION__
operator|>=
literal|201112L
operator|||
operator|!
name|defined
argument_list|(
name|__STRICT_ANSI__
argument_list|)
end_if

begin_ifndef
ifndef|#
directive|ifndef
name|FLT_DECIMAL_DIG
end_ifndef

begin_error
error|#
directive|error
literal|"Mandatory macro FLT_DECIMAL_DIG is missing."
end_error

begin_elif
elif|#
directive|elif
name|FLT_DECIMAL_DIG
operator|<
literal|6
end_elif

begin_error
error|#
directive|error
literal|"Mandatory macro FLT_DECIMAL_DIG is invalid."
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|DBL_DECIMAL_DIG
end_ifndef

begin_error
error|#
directive|error
literal|"Mandatory macro DBL_DECIMAL_DIG is missing."
end_error

begin_elif
elif|#
directive|elif
name|DBL_DECIMAL_DIG
operator|<
literal|10
end_elif

begin_error
error|#
directive|error
literal|"Mandatory macro DBL_DECIMAL_DIG is invalid."
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|LDBL_DECIMAL_DIG
end_ifndef

begin_error
error|#
directive|error
literal|"Mandatory macro LDBL_DECIMAL_DIG is missing."
end_error

begin_elif
elif|#
directive|elif
name|LDBL_DECIMAL_DIG
operator|<
literal|10
end_elif

begin_error
error|#
directive|error
literal|"Mandatory macro LDBL_DECIMAL_DIG is invalid."
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
operator|(
operator|(
name|FLT_DECIMAL_DIG
operator|>
name|DBL_DECIMAL_DIG
operator|)
operator|||
operator|(
name|DBL_DECIMAL_DIG
operator|>
name|LDBL_DECIMAL_DIG
operator|)
operator|)
end_if

begin_error
error|#
directive|error
literal|"Mandatory macros {FLT,DBL,LDBL}_DECIMAL_DIG are invalid."
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_else
else|#
directive|else
end_else

begin_ifdef
ifdef|#
directive|ifdef
name|FLT_DECIMAL_DIG
end_ifdef

begin_error
error|#
directive|error
literal|"Macro FLT_DECIMAL_DIG should not be defined."
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|DBL_DECIMAL_DIG
end_ifdef

begin_error
error|#
directive|error
literal|"Macro DBL_DECIMAL_DIG should not be defined."
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|LDBL_DECIMAL_DIG
end_ifdef

begin_error
error|#
directive|error
literal|"Macro LDBL_DECIMAL_DIG should not be defined."
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|__STDC_VERSION__
operator|>=
literal|199901L
operator|||
operator|!
name|defined
argument_list|(
name|__STRICT_ANSI__
argument_list|)
end_if

begin_ifndef
ifndef|#
directive|ifndef
name|DECIMAL_DIG
end_ifndef

begin_error
error|#
directive|error
literal|"Mandatory macro DECIMAL_DIG is missing."
end_error

begin_elif
elif|#
directive|elif
name|DECIMAL_DIG
operator|<
literal|10
end_elif

begin_error
error|#
directive|error
literal|"Mandatory macro DECIMAL_DIG is invalid."
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_else
else|#
directive|else
end_else

begin_ifdef
ifdef|#
directive|ifdef
name|DECIMAL_DIG
end_ifdef

begin_error
error|#
directive|error
literal|"Macro DECIMAL_DIG should not be defined."
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|FLT_DIG
end_ifndef

begin_error
error|#
directive|error
literal|"Mandatory macro FLT_DIG is missing."
end_error

begin_elif
elif|#
directive|elif
name|FLT_DIG
operator|<
literal|6
end_elif

begin_error
error|#
directive|error
literal|"Mandatory macro FLT_DIG is invalid."
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|DBL_DIG
end_ifndef

begin_error
error|#
directive|error
literal|"Mandatory macro DBL_DIG is missing."
end_error

begin_elif
elif|#
directive|elif
name|DBL_DIG
operator|<
literal|10
end_elif

begin_error
error|#
directive|error
literal|"Mandatory macro DBL_DIG is invalid."
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|LDBL_DIG
end_ifndef

begin_error
error|#
directive|error
literal|"Mandatory macro LDBL_DIG is missing."
end_error

begin_elif
elif|#
directive|elif
name|LDBL_DIG
operator|<
literal|10
end_elif

begin_error
error|#
directive|error
literal|"Mandatory macro LDBL_DIG is invalid."
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
operator|(
operator|(
name|FLT_DIG
operator|>
name|DBL_DIG
operator|)
operator|||
operator|(
name|DBL_DIG
operator|>
name|LDBL_DIG
operator|)
operator|)
end_if

begin_error
error|#
directive|error
literal|"Mandatory macros {FLT,DBL,LDBL}_DIG, are invalid."
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|FLT_MIN_EXP
end_ifndef

begin_error
error|#
directive|error
literal|"Mandatory macro FLT_MIN_EXP is missing."
end_error

begin_elif
elif|#
directive|elif
name|FLT_MIN_EXP
operator|>
operator|-
literal|1
end_elif

begin_error
error|#
directive|error
literal|"Mandatory macro FLT_MIN_EXP is invalid."
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|DBL_MIN_EXP
end_ifndef

begin_error
error|#
directive|error
literal|"Mandatory macro DBL_MIN_EXP is missing."
end_error

begin_elif
elif|#
directive|elif
name|DBL_MIN_EXP
operator|>
operator|-
literal|1
end_elif

begin_error
error|#
directive|error
literal|"Mandatory macro DBL_MIN_EXP is invalid."
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|LDBL_MIN_EXP
end_ifndef

begin_error
error|#
directive|error
literal|"Mandatory macro LDBL_MIN_EXP is missing."
end_error

begin_elif
elif|#
directive|elif
name|LDBL_MIN_EXP
operator|>
operator|-
literal|1
end_elif

begin_error
error|#
directive|error
literal|"Mandatory macro LDBL_MIN_EXP is invalid."
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|FLT_MIN_10_EXP
end_ifndef

begin_error
error|#
directive|error
literal|"Mandatory macro FLT_MIN_10_EXP is missing."
end_error

begin_elif
elif|#
directive|elif
name|FLT_MIN_10_EXP
operator|>
operator|-
literal|37
end_elif

begin_error
error|#
directive|error
literal|"Mandatory macro FLT_MIN_10_EXP is invalid."
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|DBL_MIN_10_EXP
end_ifndef

begin_error
error|#
directive|error
literal|"Mandatory macro DBL_MIN_10_EXP is missing."
end_error

begin_elif
elif|#
directive|elif
name|DBL_MIN_10_EXP
operator|>
operator|-
literal|37
end_elif

begin_error
error|#
directive|error
literal|"Mandatory macro DBL_MIN_10_EXP is invalid."
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|LDBL_MIN_10_EXP
end_ifndef

begin_error
error|#
directive|error
literal|"Mandatory macro LDBL_MIN_10_EXP is missing."
end_error

begin_elif
elif|#
directive|elif
name|LDBL_MIN_10_EXP
operator|>
operator|-
literal|37
end_elif

begin_error
error|#
directive|error
literal|"Mandatory macro LDBL_MIN_10_EXP is invalid."
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|FLT_MAX_EXP
end_ifndef

begin_error
error|#
directive|error
literal|"Mandatory macro FLT_MAX_EXP is missing."
end_error

begin_elif
elif|#
directive|elif
name|FLT_MAX_EXP
operator|<
literal|1
end_elif

begin_error
error|#
directive|error
literal|"Mandatory macro FLT_MAX_EXP is invalid."
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|DBL_MAX_EXP
end_ifndef

begin_error
error|#
directive|error
literal|"Mandatory macro DBL_MAX_EXP is missing."
end_error

begin_elif
elif|#
directive|elif
name|DBL_MAX_EXP
operator|<
literal|1
end_elif

begin_error
error|#
directive|error
literal|"Mandatory macro DBL_MAX_EXP is invalid."
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|LDBL_MAX_EXP
end_ifndef

begin_error
error|#
directive|error
literal|"Mandatory macro LDBL_MAX_EXP is missing."
end_error

begin_elif
elif|#
directive|elif
name|LDBL_MAX_EXP
operator|<
literal|1
end_elif

begin_error
error|#
directive|error
literal|"Mandatory macro LDBL_MAX_EXP is invalid."
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
operator|(
operator|(
name|FLT_MAX_EXP
operator|>
name|DBL_MAX_EXP
operator|)
operator|||
operator|(
name|DBL_MAX_EXP
operator|>
name|LDBL_MAX_EXP
operator|)
operator|)
end_if

begin_error
error|#
directive|error
literal|"Mandatory macros {FLT,DBL,LDBL}_MAX_EXP are invalid."
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|FLT_MAX_10_EXP
end_ifndef

begin_error
error|#
directive|error
literal|"Mandatory macro FLT_MAX_10_EXP is missing."
end_error

begin_elif
elif|#
directive|elif
name|FLT_MAX_10_EXP
operator|<
literal|37
end_elif

begin_error
error|#
directive|error
literal|"Mandatory macro FLT_MAX_10_EXP is invalid."
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|DBL_MAX_10_EXP
end_ifndef

begin_error
error|#
directive|error
literal|"Mandatory macro DBL_MAX_10_EXP is missing."
end_error

begin_elif
elif|#
directive|elif
name|DBL_MAX_10_EXP
operator|<
literal|37
end_elif

begin_error
error|#
directive|error
literal|"Mandatory macro DBL_MAX_10_EXP is invalid."
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|LDBL_MAX_10_EXP
end_ifndef

begin_error
error|#
directive|error
literal|"Mandatory macro LDBL_MAX_10_EXP is missing."
end_error

begin_elif
elif|#
directive|elif
name|LDBL_MAX_10_EXP
operator|<
literal|37
end_elif

begin_error
error|#
directive|error
literal|"Mandatory macro LDBL_MAX_10_EXP is invalid."
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
operator|(
operator|(
name|FLT_MAX_10_EXP
operator|>
name|DBL_MAX_10_EXP
operator|)
operator|||
operator|(
name|DBL_MAX_10_EXP
operator|>
name|LDBL_MAX_10_EXP
operator|)
operator|)
end_if

begin_error
error|#
directive|error
literal|"Mandatory macros {FLT,DBL,LDBL}_MAX_10_EXP are invalid."
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Internal consistency checks */
end_comment

begin_assert
assert|_Static_assert
argument_list|(
name|FLT_RADIX
operator|==
name|__FLT_RADIX__
argument_list|,
literal|""
argument_list|)
assert|;
end_assert

begin_assert
assert|_Static_assert
argument_list|(
name|FLT_MANT_DIG
operator|==
name|__FLT_MANT_DIG__
argument_list|,
literal|""
argument_list|)
assert|;
end_assert

begin_assert
assert|_Static_assert
argument_list|(
name|DBL_MANT_DIG
operator|==
name|__DBL_MANT_DIG__
argument_list|,
literal|""
argument_list|)
assert|;
end_assert

begin_assert
assert|_Static_assert
argument_list|(
name|LDBL_MANT_DIG
operator|==
name|__LDBL_MANT_DIG__
argument_list|,
literal|""
argument_list|)
assert|;
end_assert

begin_if
if|#
directive|if
name|__STDC_VERSION__
operator|>=
literal|201112L
operator|||
operator|!
name|defined
argument_list|(
name|__STRICT_ANSI__
argument_list|)
end_if

begin_assert
assert|_Static_assert
argument_list|(
name|FLT_DECIMAL_DIG
operator|==
name|__FLT_DECIMAL_DIG__
argument_list|,
literal|""
argument_list|)
assert|;
end_assert

begin_assert
assert|_Static_assert
argument_list|(
name|DBL_DECIMAL_DIG
operator|==
name|__DBL_DECIMAL_DIG__
argument_list|,
literal|""
argument_list|)
assert|;
end_assert

begin_assert
assert|_Static_assert
argument_list|(
name|LDBL_DECIMAL_DIG
operator|==
name|__LDBL_DECIMAL_DIG__
argument_list|,
literal|""
argument_list|)
assert|;
end_assert

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|__STDC_VERSION__
operator|>=
literal|199901L
operator|||
operator|!
name|defined
argument_list|(
name|__STRICT_ANSI__
argument_list|)
end_if

begin_assert
assert|_Static_assert
argument_list|(
name|DECIMAL_DIG
operator|==
name|__DECIMAL_DIG__
argument_list|,
literal|""
argument_list|)
assert|;
end_assert

begin_endif
endif|#
directive|endif
end_endif

begin_assert
assert|_Static_assert
argument_list|(
name|FLT_DIG
operator|==
name|__FLT_DIG__
argument_list|,
literal|""
argument_list|)
assert|;
end_assert

begin_assert
assert|_Static_assert
argument_list|(
name|DBL_DIG
operator|==
name|__DBL_DIG__
argument_list|,
literal|""
argument_list|)
assert|;
end_assert

begin_assert
assert|_Static_assert
argument_list|(
name|LDBL_DIG
operator|==
name|__LDBL_DIG__
argument_list|,
literal|""
argument_list|)
assert|;
end_assert

begin_assert
assert|_Static_assert
argument_list|(
name|FLT_MIN_EXP
operator|==
name|__FLT_MIN_EXP__
argument_list|,
literal|""
argument_list|)
assert|;
end_assert

begin_assert
assert|_Static_assert
argument_list|(
name|DBL_MIN_EXP
operator|==
name|__DBL_MIN_EXP__
argument_list|,
literal|""
argument_list|)
assert|;
end_assert

begin_assert
assert|_Static_assert
argument_list|(
name|LDBL_MIN_EXP
operator|==
name|__LDBL_MIN_EXP__
argument_list|,
literal|""
argument_list|)
assert|;
end_assert

begin_assert
assert|_Static_assert
argument_list|(
name|FLT_MIN_10_EXP
operator|==
name|__FLT_MIN_10_EXP__
argument_list|,
literal|""
argument_list|)
assert|;
end_assert

begin_assert
assert|_Static_assert
argument_list|(
name|DBL_MIN_10_EXP
operator|==
name|__DBL_MIN_10_EXP__
argument_list|,
literal|""
argument_list|)
assert|;
end_assert

begin_assert
assert|_Static_assert
argument_list|(
name|LDBL_MIN_10_EXP
operator|==
name|__LDBL_MIN_10_EXP__
argument_list|,
literal|""
argument_list|)
assert|;
end_assert

begin_assert
assert|_Static_assert
argument_list|(
name|FLT_MAX_EXP
operator|==
name|__FLT_MAX_EXP__
argument_list|,
literal|""
argument_list|)
assert|;
end_assert

begin_assert
assert|_Static_assert
argument_list|(
name|DBL_MAX_EXP
operator|==
name|__DBL_MAX_EXP__
argument_list|,
literal|""
argument_list|)
assert|;
end_assert

begin_assert
assert|_Static_assert
argument_list|(
name|LDBL_MAX_EXP
operator|==
name|__LDBL_MAX_EXP__
argument_list|,
literal|""
argument_list|)
assert|;
end_assert

begin_assert
assert|_Static_assert
argument_list|(
name|FLT_MAX_10_EXP
operator|==
name|__FLT_MAX_10_EXP__
argument_list|,
literal|""
argument_list|)
assert|;
end_assert

begin_assert
assert|_Static_assert
argument_list|(
name|DBL_MAX_10_EXP
operator|==
name|__DBL_MAX_10_EXP__
argument_list|,
literal|""
argument_list|)
assert|;
end_assert

begin_assert
assert|_Static_assert
argument_list|(
name|LDBL_MAX_10_EXP
operator|==
name|__LDBL_MAX_10_EXP__
argument_list|,
literal|""
argument_list|)
assert|;
end_assert

end_unit

