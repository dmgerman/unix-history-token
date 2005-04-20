begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_ifndef
ifndef|#
directive|ifndef
name|_LIMITS_H___
end_ifndef

begin_define
define|#
directive|define
name|_LIMITS_H___
end_define

begin_comment
comment|/* Number of bits in a `char'.  */
end_comment

begin_undef
undef|#
directive|undef
name|CHAR_BIT
end_undef

begin_define
define|#
directive|define
name|CHAR_BIT
value|__CHAR_BIT__
end_define

begin_comment
comment|/* Maximum length of a multibyte character.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|MB_LEN_MAX
end_ifndef

begin_define
define|#
directive|define
name|MB_LEN_MAX
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Minimum and maximum values a `signed char' can hold.  */
end_comment

begin_undef
undef|#
directive|undef
name|SCHAR_MIN
end_undef

begin_define
define|#
directive|define
name|SCHAR_MIN
value|(-SCHAR_MAX - 1)
end_define

begin_undef
undef|#
directive|undef
name|SCHAR_MAX
end_undef

begin_define
define|#
directive|define
name|SCHAR_MAX
value|__SCHAR_MAX__
end_define

begin_comment
comment|/* Maximum value an `unsigned char' can hold.  (Minimum is 0).  */
end_comment

begin_undef
undef|#
directive|undef
name|UCHAR_MAX
end_undef

begin_if
if|#
directive|if
name|__SCHAR_MAX__
operator|==
name|__INT_MAX__
end_if

begin_define
define|#
directive|define
name|UCHAR_MAX
value|(SCHAR_MAX * 2U + 1U)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|UCHAR_MAX
value|(SCHAR_MAX * 2 + 1)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Minimum and maximum values a `char' can hold.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|__CHAR_UNSIGNED__
end_ifdef

begin_undef
undef|#
directive|undef
name|CHAR_MIN
end_undef

begin_if
if|#
directive|if
name|__SCHAR_MAX__
operator|==
name|__INT_MAX__
end_if

begin_define
define|#
directive|define
name|CHAR_MIN
value|0U
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|CHAR_MIN
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_undef
undef|#
directive|undef
name|CHAR_MAX
end_undef

begin_define
define|#
directive|define
name|CHAR_MAX
value|UCHAR_MAX
end_define

begin_else
else|#
directive|else
end_else

begin_undef
undef|#
directive|undef
name|CHAR_MIN
end_undef

begin_define
define|#
directive|define
name|CHAR_MIN
value|SCHAR_MIN
end_define

begin_undef
undef|#
directive|undef
name|CHAR_MAX
end_undef

begin_define
define|#
directive|define
name|CHAR_MAX
value|SCHAR_MAX
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Minimum and maximum values a `signed short int' can hold.  */
end_comment

begin_undef
undef|#
directive|undef
name|SHRT_MIN
end_undef

begin_define
define|#
directive|define
name|SHRT_MIN
value|(-SHRT_MAX - 1)
end_define

begin_undef
undef|#
directive|undef
name|SHRT_MAX
end_undef

begin_define
define|#
directive|define
name|SHRT_MAX
value|__SHRT_MAX__
end_define

begin_comment
comment|/* Maximum value an `unsigned short int' can hold.  (Minimum is 0).  */
end_comment

begin_undef
undef|#
directive|undef
name|USHRT_MAX
end_undef

begin_if
if|#
directive|if
name|__SHRT_MAX__
operator|==
name|__INT_MAX__
end_if

begin_define
define|#
directive|define
name|USHRT_MAX
value|(SHRT_MAX * 2U + 1U)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|USHRT_MAX
value|(SHRT_MAX * 2 + 1)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Minimum and maximum values a `signed int' can hold.  */
end_comment

begin_undef
undef|#
directive|undef
name|INT_MIN
end_undef

begin_define
define|#
directive|define
name|INT_MIN
value|(-INT_MAX - 1)
end_define

begin_undef
undef|#
directive|undef
name|INT_MAX
end_undef

begin_define
define|#
directive|define
name|INT_MAX
value|__INT_MAX__
end_define

begin_comment
comment|/* Maximum value an `unsigned int' can hold.  (Minimum is 0).  */
end_comment

begin_undef
undef|#
directive|undef
name|UINT_MAX
end_undef

begin_define
define|#
directive|define
name|UINT_MAX
value|(INT_MAX * 2U + 1U)
end_define

begin_comment
comment|/* Minimum and maximum values a `signed long int' can hold.    (Same as `int').  */
end_comment

begin_undef
undef|#
directive|undef
name|LONG_MIN
end_undef

begin_define
define|#
directive|define
name|LONG_MIN
value|(-LONG_MAX - 1L)
end_define

begin_undef
undef|#
directive|undef
name|LONG_MAX
end_undef

begin_define
define|#
directive|define
name|LONG_MAX
value|__LONG_MAX__
end_define

begin_comment
comment|/* Maximum value an `unsigned long int' can hold.  (Minimum is 0).  */
end_comment

begin_undef
undef|#
directive|undef
name|ULONG_MAX
end_undef

begin_define
define|#
directive|define
name|ULONG_MAX
value|(LONG_MAX * 2UL + 1UL)
end_define

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__STDC_VERSION__
argument_list|)
operator|&&
name|__STDC_VERSION__
operator|>=
literal|199901L
end_if

begin_comment
comment|/* Minimum and maximum values a `signed long long int' can hold.  */
end_comment

begin_undef
undef|#
directive|undef
name|LLONG_MIN
end_undef

begin_define
define|#
directive|define
name|LLONG_MIN
value|(-LLONG_MAX - 1LL)
end_define

begin_undef
undef|#
directive|undef
name|LLONG_MAX
end_undef

begin_define
define|#
directive|define
name|LLONG_MAX
value|__LONG_LONG_MAX__
end_define

begin_comment
comment|/* Maximum value an `unsigned long long int' can hold.  (Minimum is 0).  */
end_comment

begin_undef
undef|#
directive|undef
name|ULLONG_MAX
end_undef

begin_define
define|#
directive|define
name|ULLONG_MAX
value|(LLONG_MAX * 2ULL + 1ULL)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__GNU_LIBRARY__
argument_list|)
condition|?
name|defined
argument_list|(
name|__USE_GNU
argument_list|)
expr|:
operator|!
name|defined
argument_list|(
name|__STRICT_ANSI__
argument_list|)
end_if

begin_comment
comment|/* Minimum and maximum values a `signed long long int' can hold.  */
end_comment

begin_undef
undef|#
directive|undef
name|LONG_LONG_MIN
end_undef

begin_define
define|#
directive|define
name|LONG_LONG_MIN
value|(-LONG_LONG_MAX - 1LL)
end_define

begin_undef
undef|#
directive|undef
name|LONG_LONG_MAX
end_undef

begin_define
define|#
directive|define
name|LONG_LONG_MAX
value|__LONG_LONG_MAX__
end_define

begin_comment
comment|/* Maximum value an `unsigned long long int' can hold.  (Minimum is 0).  */
end_comment

begin_undef
undef|#
directive|undef
name|ULONG_LONG_MAX
end_undef

begin_define
define|#
directive|define
name|ULONG_LONG_MAX
value|(LONG_LONG_MAX * 2ULL + 1ULL)
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
comment|/* _LIMITS_H___ */
end_comment

end_unit

