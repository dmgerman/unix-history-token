begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* HOST_WIDE_INT definitions for the GNU compiler.    Copyright (C) 1998, 2002 Free Software Foundation, Inc.     This file is part of GCC.     Provide definitions for macros which depend on HOST_BITS_PER_INT    and HOST_BITS_PER_LONG.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|GCC_HWINT_H
end_ifndef

begin_define
define|#
directive|define
name|GCC_HWINT_H
end_define

begin_comment
comment|/* This describes the machine the compiler is hosted on.  */
end_comment

begin_define
define|#
directive|define
name|HOST_BITS_PER_CHAR
value|CHAR_BIT
end_define

begin_define
define|#
directive|define
name|HOST_BITS_PER_SHORT
value|(CHAR_BIT * SIZEOF_SHORT)
end_define

begin_define
define|#
directive|define
name|HOST_BITS_PER_INT
value|(CHAR_BIT * SIZEOF_INT)
end_define

begin_define
define|#
directive|define
name|HOST_BITS_PER_LONG
value|(CHAR_BIT * SIZEOF_LONG)
end_define

begin_comment
comment|/* If HAVE_LONG_LONG and SIZEOF_LONG_LONG aren't defined, but    GCC_VERSION>= 3000, assume this is the second or later stage of a    bootstrap, we do have long long, and it's 64 bits.  (This is    required by C99; we do have some ports that violate that assumption    but they're all cross-compile-only.)  Just in case, force a    constraint violation if that assumption is incorrect.  */
end_comment

begin_if
if|#
directive|if
operator|!
name|defined
name|HAVE_LONG_LONG
end_if

begin_if
if|#
directive|if
name|GCC_VERSION
operator|>=
literal|3000
end_if

begin_define
define|#
directive|define
name|HAVE_LONG_LONG
value|1
end_define

begin_define
define|#
directive|define
name|SIZEOF_LONG_LONG
value|8
end_define

begin_extern
extern|extern char sizeof_long_long_must_be_8[sizeof(long long
end_extern

begin_expr_stmt
unit|)
operator|==
literal|8
condition|?
literal|1
else|:
operator|-
literal|1
expr|]
expr_stmt|;
end_expr_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_LONG_LONG
end_ifdef

begin_define
define|#
directive|define
name|HOST_BITS_PER_LONGLONG
value|(CHAR_BIT * SIZEOF_LONG_LONG)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE___INT64
end_ifdef

begin_define
define|#
directive|define
name|HOST_BITS_PER___INT64
value|(CHAR_BIT * SIZEOF___INT64)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Set HOST_WIDE_INT.  This should be the widest efficient host    integer type.  It can be 32 or 64 bits, except that if we are    targeting a machine with 64-bit size_t then it has to be 64 bits.     With a sane ABI, 'long' is the largest efficient host integer type.    Thus, we use that unless we have to use 'long long' or '__int64'    because we're targeting a 64-bit machine from a 32-bit host.  */
end_comment

begin_if
if|#
directive|if
name|HOST_BITS_PER_LONG
operator|>=
literal|64
operator|||
operator|!
name|defined
name|NEED_64BIT_HOST_WIDE_INT
end_if

begin_define
define|#
directive|define
name|HOST_BITS_PER_WIDE_INT
value|HOST_BITS_PER_LONG
end_define

begin_define
define|#
directive|define
name|HOST_WIDE_INT
value|long
end_define

begin_else
else|#
directive|else
end_else

begin_if
if|#
directive|if
name|HOST_BITS_PER_LONGLONG
operator|>=
literal|64
end_if

begin_define
define|#
directive|define
name|HOST_BITS_PER_WIDE_INT
value|HOST_BITS_PER_LONGLONG
end_define

begin_define
define|#
directive|define
name|HOST_WIDE_INT
value|long long
end_define

begin_else
else|#
directive|else
end_else

begin_if
if|#
directive|if
name|HOST_BITS_PER___INT64
operator|>=
literal|64
end_if

begin_define
define|#
directive|define
name|HOST_BITS_PER_WIDE_INT
value|HOST_BITS_PER___INT64
end_define

begin_define
define|#
directive|define
name|HOST_WIDE_INT
value|__int64
end_define

begin_else
else|#
directive|else
end_else

begin_error
error|#
directive|error
literal|"Unable to find a suitable type for HOST_WIDE_INT"
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Various printf format strings for HOST_WIDE_INT.  */
end_comment

begin_if
if|#
directive|if
name|HOST_BITS_PER_WIDE_INT
operator|==
name|HOST_BITS_PER_LONG
end_if

begin_define
define|#
directive|define
name|HOST_WIDE_INT_PRINT
value|"l"
end_define

begin_define
define|#
directive|define
name|HOST_WIDE_INT_PRINT_C
value|"L"
end_define

begin_comment
comment|/* 'long' might be 32 or 64 bits, and the number of leading zeroes      must be tweaked accordingly.  */
end_comment

begin_if
if|#
directive|if
name|HOST_BITS_PER_WIDE_INT
operator|==
literal|64
end_if

begin_define
define|#
directive|define
name|HOST_WIDE_INT_PRINT_DOUBLE_HEX
value|"0x%lx%016lx"
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|HOST_WIDE_INT_PRINT_DOUBLE_HEX
value|"0x%lx%08lx"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|HOST_WIDE_INT_PRINT
value|"ll"
end_define

begin_define
define|#
directive|define
name|HOST_WIDE_INT_PRINT_C
value|"LL"
end_define

begin_comment
comment|/* We can assume that 'long long' is at least 64 bits.  */
end_comment

begin_define
define|#
directive|define
name|HOST_WIDE_INT_PRINT_DOUBLE_HEX
value|"0x%llx%016llx"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* HOST_BITS_PER_WIDE_INT == HOST_BITS_PER_LONG */
end_comment

begin_define
define|#
directive|define
name|HOST_WIDE_INT_PRINT_DEC
value|"%" HOST_WIDE_INT_PRINT "d"
end_define

begin_define
define|#
directive|define
name|HOST_WIDE_INT_PRINT_DEC_C
value|HOST_WIDE_INT_PRINT_DEC HOST_WIDE_INT_PRINT_C
end_define

begin_define
define|#
directive|define
name|HOST_WIDE_INT_PRINT_UNSIGNED
value|"%" HOST_WIDE_INT_PRINT "u"
end_define

begin_define
define|#
directive|define
name|HOST_WIDE_INT_PRINT_HEX
value|"0x%" HOST_WIDE_INT_PRINT "x"
end_define

begin_comment
comment|/* Set HOST_WIDEST_INT.  This is a 64-bit type unless the compiler    in use has no 64-bit type at all; in that case it's 32 bits.  */
end_comment

begin_if
if|#
directive|if
name|HOST_BITS_PER_WIDE_INT
operator|>=
literal|64
expr|\
operator|||
operator|(
name|HOST_BITS_PER_LONGLONG
operator|<
literal|64
operator|&&
name|HOST_BITS_PER___INT64
operator|<
literal|64
operator|)
end_if

begin_define
define|#
directive|define
name|HOST_WIDEST_INT
value|HOST_WIDE_INT
end_define

begin_define
define|#
directive|define
name|HOST_BITS_PER_WIDEST_INT
value|HOST_BITS_PER_WIDE_INT
end_define

begin_define
define|#
directive|define
name|HOST_WIDEST_INT_PRINT_DEC
value|HOST_WIDE_INT_PRINT_DEC
end_define

begin_define
define|#
directive|define
name|HOST_WIDEST_INT_PRINT_DEC_C
value|HOST_WIDE_INT_PRINT_DEC_C
end_define

begin_define
define|#
directive|define
name|HOST_WIDEST_INT_PRINT_UNSIGNED
value|HOST_WIDE_INT_PRINT_UNSIGNED
end_define

begin_define
define|#
directive|define
name|HOST_WIDEST_INT_PRINT_HEX
value|HOST_WIDE_INT_PRINT_HEX
end_define

begin_define
define|#
directive|define
name|HOST_WIDEST_INT_PRINT_DOUBLE_HEX
value|HOST_WIDE_INT_PRINT_DOUBLE_HEX
end_define

begin_else
else|#
directive|else
end_else

begin_if
if|#
directive|if
name|HOST_BITS_PER_LONGLONG
operator|>=
literal|64
end_if

begin_define
define|#
directive|define
name|HOST_BITS_PER_WIDEST_INT
value|HOST_BITS_PER_LONGLONG
end_define

begin_define
define|#
directive|define
name|HOST_WIDEST_INT
value|long long
end_define

begin_else
else|#
directive|else
end_else

begin_if
if|#
directive|if
name|HOST_BITS_PER___INT64
operator|>=
literal|64
end_if

begin_define
define|#
directive|define
name|HOST_BITS_PER_WIDEST_INT
value|HOST_BITS_PER___INT64
end_define

begin_define
define|#
directive|define
name|HOST_WIDEST_INT
value|__int64
end_define

begin_else
else|#
directive|else
end_else

begin_error
error|#
directive|error
literal|"This line should be impossible to reach"
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|HOST_WIDEST_INT_PRINT_DEC
value|"%lld"
end_define

begin_define
define|#
directive|define
name|HOST_WIDEST_INT_PRINT_DEC_C
value|"%lldLL"
end_define

begin_define
define|#
directive|define
name|HOST_WIDEST_INT_PRINT_UNSIGNED
value|"%llu"
end_define

begin_define
define|#
directive|define
name|HOST_WIDEST_INT_PRINT_HEX
value|"0x%llx"
end_define

begin_define
define|#
directive|define
name|HOST_WIDEST_INT_PRINT_DOUBLE_HEX
value|"0x%llx%016llx"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! GCC_HWINT_H */
end_comment

end_unit

