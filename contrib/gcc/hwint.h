begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* HOST_WIDE_INT definitions for the GNU compiler.    Copyright (C) 1998 Free Software Foundation, Inc.     This file is part of GCC.     Provide definitions for macros which depend on HOST_BITS_PER_INT    and HOST_BITS_PER_LONG.  */
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

begin_else
else|#
directive|else
end_else

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE__INT64
end_ifdef

begin_define
define|#
directive|define
name|HOST_BITS_PER_LONGLONG
value|(CHAR_BIT * SIZEOF___INT64)
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* If we're here and we're GCC, assume this is stage 2+ of a bootstrap    and 'long long' has the width of the *target*'s long long.  */
end_comment

begin_if
if|#
directive|if
name|GCC_VERSION
operator|>
literal|3000
end_if

begin_define
define|#
directive|define
name|HOST_BITS_PER_LONGLONG
value|LONG_LONG_TYPE_SIZE
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* gcc */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* no long long */
end_comment

begin_comment
comment|/* Find the largest host integer type and set its size and type.  */
end_comment

begin_comment
comment|/* Use long long on the host if the target has a wider long type than    the host.  */
end_comment

begin_if
if|#
directive|if
operator|!
name|defined
name|HOST_BITS_PER_WIDE_INT
expr|\
operator|&&
name|defined
name|HOST_BITS_PER_LONGLONG
expr|\
operator|&&
operator|(
name|HOST_BITS_PER_LONGLONG
operator|>
name|HOST_BITS_PER_LONG
operator|)
expr|\
operator|&&
operator|(
name|defined
argument_list|(
name|LONG_LONG_MAX
argument_list|)
operator|||
name|defined
argument_list|(
name|LONGLONG_MAX
argument_list|)
expr|\
operator|||
name|defined
argument_list|(
name|LLONG_MAX
argument_list|)
operator|||
name|defined
argument_list|(
name|__GNUC__
argument_list|)
operator|)
end_if

begin_ifdef
ifdef|#
directive|ifdef
name|MAX_LONG_TYPE_SIZE
end_ifdef

begin_if
if|#
directive|if
name|MAX_LONG_TYPE_SIZE
operator|>
name|HOST_BITS_PER_LONG
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

begin_endif
endif|#
directive|endif
end_endif

begin_else
else|#
directive|else
end_else

begin_if
if|#
directive|if
name|LONG_TYPE_SIZE
operator|>
name|HOST_BITS_PER_LONG
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

begin_ifndef
ifndef|#
directive|ifndef
name|HOST_BITS_PER_WIDE_INT
end_ifndef

begin_if
if|#
directive|if
name|HOST_BITS_PER_LONG
operator|>
name|HOST_BITS_PER_INT
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

begin_define
define|#
directive|define
name|HOST_BITS_PER_WIDE_INT
value|HOST_BITS_PER_INT
end_define

begin_define
define|#
directive|define
name|HOST_WIDE_INT
value|int
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
comment|/* ! HOST_BITS_PER_WIDE_INT */
end_comment

begin_comment
comment|/* Provide defaults for the way to print a HOST_WIDE_INT    in various manners.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|HOST_WIDE_INT_PRINT_DEC
end_ifndef

begin_if
if|#
directive|if
name|HOST_BITS_PER_WIDE_INT
operator|==
name|HOST_BITS_PER_INT
end_if

begin_define
define|#
directive|define
name|HOST_WIDE_INT_PRINT_DEC
value|"%d"
end_define

begin_else
else|#
directive|else
end_else

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
name|HOST_WIDE_INT_PRINT_DEC
value|"%ld"
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|HOST_WIDE_INT_PRINT_DEC
value|"%lld"
end_define

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
comment|/* ! HOST_WIDE_INT_PRINT_DEC */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|HOST_WIDE_INT_PRINT_UNSIGNED
end_ifndef

begin_if
if|#
directive|if
name|HOST_BITS_PER_WIDE_INT
operator|==
name|HOST_BITS_PER_INT
end_if

begin_define
define|#
directive|define
name|HOST_WIDE_INT_PRINT_UNSIGNED
value|"%u"
end_define

begin_else
else|#
directive|else
end_else

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
name|HOST_WIDE_INT_PRINT_UNSIGNED
value|"%lu"
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|HOST_WIDE_INT_PRINT_UNSIGNED
value|"%llu"
end_define

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
comment|/* ! HOST_WIDE_INT_PRINT_UNSIGNED */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|HOST_WIDE_INT_PRINT_HEX
end_ifndef

begin_if
if|#
directive|if
name|HOST_BITS_PER_WIDE_INT
operator|==
name|HOST_BITS_PER_INT
end_if

begin_define
define|#
directive|define
name|HOST_WIDE_INT_PRINT_HEX
value|"0x%x"
end_define

begin_else
else|#
directive|else
end_else

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
name|HOST_WIDE_INT_PRINT_HEX
value|"0x%lx"
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|HOST_WIDE_INT_PRINT_HEX
value|"0x%llx"
end_define

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
comment|/* ! HOST_WIDE_INT_PRINT_HEX */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|HOST_WIDE_INT_PRINT_DOUBLE_HEX
end_ifndef

begin_if
if|#
directive|if
name|HOST_BITS_PER_WIDE_INT
operator|==
literal|64
end_if

begin_if
if|#
directive|if
name|HOST_BITS_PER_WIDE_INT
operator|==
name|HOST_BITS_PER_INT
end_if

begin_define
define|#
directive|define
name|HOST_WIDE_INT_PRINT_DOUBLE_HEX
value|"0x%x%016x"
end_define

begin_else
else|#
directive|else
end_else

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

begin_else
else|#
directive|else
end_else

begin_if
if|#
directive|if
name|HOST_BITS_PER_WIDE_INT
operator|==
name|HOST_BITS_PER_INT
end_if

begin_define
define|#
directive|define
name|HOST_WIDE_INT_PRINT_DOUBLE_HEX
value|"0x%x%08x"
end_define

begin_else
else|#
directive|else
end_else

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
name|HOST_WIDE_INT_PRINT_DOUBLE_HEX
value|"0x%lx%08lx"
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|HOST_WIDE_INT_PRINT_DOUBLE_HEX
value|"0x%llx%08llx"
end_define

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

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! HOST_WIDE_INT_PRINT_DOUBLE_HEX */
end_comment

begin_comment
comment|/* Find HOST_WIDEST_INT and set its bit size, type and print macros.    It will be the largest integer mode supported by the host which may    (or may not) be larger than HOST_WIDE_INT.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|HOST_WIDEST_INT
end_ifndef

begin_if
if|#
directive|if
name|defined
name|HOST_BITS_PER_LONGLONG
expr|\
operator|&&
name|HOST_BITS_PER_LONGLONG
operator|>
name|HOST_BITS_PER_LONG
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

begin_define
define|#
directive|define
name|HOST_WIDEST_INT_PRINT_DEC
value|"%lld"
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

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|HOST_BITS_PER_WIDEST_INT
value|HOST_BITS_PER_LONG
end_define

begin_define
define|#
directive|define
name|HOST_WIDEST_INT
value|long
end_define

begin_define
define|#
directive|define
name|HOST_WIDEST_INT_PRINT_DEC
value|"%ld"
end_define

begin_define
define|#
directive|define
name|HOST_WIDEST_INT_PRINT_UNSIGNED
value|"%lu"
end_define

begin_define
define|#
directive|define
name|HOST_WIDEST_INT_PRINT_HEX
value|"0x%lx"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* long long wider than long */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! HOST_WIDEST_INT */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! GCC_HWINT_H */
end_comment

end_unit

