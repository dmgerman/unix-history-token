begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* HOST_WIDE_INT definitions for the GNU compiler.    Copyright (C) 1998 Free Software Foundation, Inc.     This file is part of GNU CC.     Provide definitions for macros which depend on HOST_BITS_PER_INT    and HOST_BITS_PER_LONG. */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__HWINT_H__
end_ifndef

begin_define
define|#
directive|define
name|__HWINT_H__
end_define

begin_comment
comment|/* Only do all of this if both of these macros are defined, otherwise    they'll evaluate to zero, which is not what you want. */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|HOST_BITS_PER_LONG
argument_list|)
operator|&&
name|defined
argument_list|(
name|HOST_BITS_PER_INT
argument_list|)
end_if

begin_comment
comment|/* Find the largest host integer type and set its size and type.  */
end_comment

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

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* HOST_BITS_PER_LONG&& HOST_BITS_PER_INT */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __HWINT_H__ */
end_comment

end_unit

