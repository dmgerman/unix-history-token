begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_ifndef
ifndef|#
directive|ifndef
name|_LIMITS_H___
end_ifndef

begin_ifndef
ifndef|#
directive|ifndef
name|_MACH_MACHLIMITS_H_
end_ifndef

begin_comment
comment|/* _MACH_MACHLIMITS_H_ is used on OSF/1.  */
end_comment

begin_define
define|#
directive|define
name|_LIMITS_H___
end_define

begin_define
define|#
directive|define
name|_MACH_MACHLIMITS_H_
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
value|8
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
value|(-128)
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
value|127
end_define

begin_comment
comment|/* Maximum value an `unsigned char' can hold.  (Minimum is 0).  */
end_comment

begin_undef
undef|#
directive|undef
name|UCHAR_MAX
end_undef

begin_define
define|#
directive|define
name|UCHAR_MAX
value|255
end_define

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

begin_define
define|#
directive|define
name|CHAR_MIN
value|0
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
value|255
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
value|(-128)
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
value|127
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

begin_comment
comment|/* For the sake of 16 bit hosts, we may not use -32768 */
end_comment

begin_define
define|#
directive|define
name|SHRT_MIN
value|(-32767-1)
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
value|32767
end_define

begin_comment
comment|/* Maximum value an `unsigned short int' can hold.  (Minimum is 0).  */
end_comment

begin_undef
undef|#
directive|undef
name|USHRT_MAX
end_undef

begin_define
define|#
directive|define
name|USHRT_MAX
value|65535
end_define

begin_comment
comment|/* Minimum and maximum values a `signed int' can hold.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__INT_MAX__
end_ifndef

begin_define
define|#
directive|define
name|__INT_MAX__
value|2147483647
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_undef
undef|#
directive|undef
name|INT_MIN
end_undef

begin_define
define|#
directive|define
name|INT_MIN
value|(-INT_MAX-1)
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
value|(INT_MAX * 2U + 1)
end_define

begin_comment
comment|/* Minimum and maximum values a `signed long int' can hold.    (Same as `int').  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__LONG_MAX__
end_ifndef

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__alpha__
argument_list|)
operator|||
operator|(
name|defined
argument_list|(
name|_ARCH_PPC
argument_list|)
operator|&&
name|defined
argument_list|(
name|__64BIT__
argument_list|)
operator|)
operator|||
name|defined
argument_list|(
name|__sparc_v9__
argument_list|)
operator|||
name|defined
argument_list|(
name|__sparcv9
argument_list|)
end_if

begin_define
define|#
directive|define
name|__LONG_MAX__
value|9223372036854775807L
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|__LONG_MAX__
value|2147483647L
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __alpha__ || sparc64 */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_undef
undef|#
directive|undef
name|LONG_MIN
end_undef

begin_define
define|#
directive|define
name|LONG_MIN
value|(-LONG_MAX-1)
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
value|(LONG_MAX * 2UL + 1)
end_define

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

begin_ifndef
ifndef|#
directive|ifndef
name|__LONG_LONG_MAX__
end_ifndef

begin_define
define|#
directive|define
name|__LONG_LONG_MAX__
value|9223372036854775807LL
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_undef
undef|#
directive|undef
name|LONG_LONG_MIN
end_undef

begin_define
define|#
directive|define
name|LONG_LONG_MIN
value|(-LONG_LONG_MAX-1)
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
value|(LONG_LONG_MAX * 2ULL + 1)
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
comment|/* _MACH_MACHLIMITS_H_ */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _LIMITS_H___ */
end_comment

end_unit

