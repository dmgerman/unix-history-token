begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*    handy.h  *  *    Copyright (c) 1991-2001, Larry Wall  *  *    You may distribute under the terms of either the GNU General Public  *    License or the Artistic License, as specified in the README file.  *  */
end_comment

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|__STDC__
argument_list|)
end_if

begin_ifdef
ifdef|#
directive|ifdef
name|NULL
end_ifdef

begin_undef
undef|#
directive|undef
name|NULL
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|I286
end_ifndef

begin_define
define|#
directive|define
name|NULL
value|0
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|NULL
value|0L
end_define

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
name|Null
parameter_list|(
name|type
parameter_list|)
value|((type)NULL)
end_define

begin_comment
comment|/* =for apidoc AmU||Nullch Null character pointer.  =for apidoc AmU||Nullsv Null SV pointer.  =cut */
end_comment

begin_define
define|#
directive|define
name|Nullch
value|Null(char*)
end_define

begin_define
define|#
directive|define
name|Nullfp
value|Null(PerlIO*)
end_define

begin_define
define|#
directive|define
name|Nullsv
value|Null(SV*)
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|TRUE
end_ifdef

begin_undef
undef|#
directive|undef
name|TRUE
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|FALSE
end_ifdef

begin_undef
undef|#
directive|undef
name|FALSE
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|TRUE
value|(1)
end_define

begin_define
define|#
directive|define
name|FALSE
value|(0)
end_define

begin_comment
comment|/* XXX Configure ought to have a test for a boolean type, if I can    just figure out all the headers such a test needs.    Andy Dougherty	August 1996 */
end_comment

begin_comment
comment|/* bool is built-in for g++-2.6.3 and later, which might be used    for extensions.<_G_config.h> defines _G_HAVE_BOOL, but we can't    be sure _G_config.h will be included before this file.  _G_config.h    also defines _G_HAVE_BOOL for both gcc and g++, but only g++    actually has bool.  Hence, _G_HAVE_BOOL is pretty useless for us.    g++ can be identified by __GNUG__.    Andy Dougherty	February 2000 */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|__GNUG__
end_ifdef

begin_comment
comment|/* GNU g++ has bool built-in */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|HAS_BOOL
end_ifndef

begin_define
define|#
directive|define
name|HAS_BOOL
value|1
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
comment|/* The NeXT dynamic loader headers will not build with the bool macro    So declare them now to clear confusion. */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|NeXT
argument_list|)
operator|||
name|defined
argument_list|(
name|__NeXT__
argument_list|)
end_if

begin_undef
undef|#
directive|undef
name|FALSE
end_undef

begin_undef
undef|#
directive|undef
name|TRUE
end_undef

begin_typedef
typedef|typedef
enum|enum
name|bool
block|{
name|FALSE
init|=
literal|0
block|,
name|TRUE
init|=
literal|1
block|}
name|bool
typedef|;
end_typedef

begin_define
define|#
directive|define
name|ENUM_BOOL
value|1
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|HAS_BOOL
end_ifndef

begin_define
define|#
directive|define
name|HAS_BOOL
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !HAS_BOOL */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* NeXT || __NeXT__ */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|HAS_BOOL
end_ifndef

begin_if
if|#
directive|if
name|defined
argument_list|(
name|UTS
argument_list|)
operator|||
name|defined
argument_list|(
name|VMS
argument_list|)
end_if

begin_define
define|#
directive|define
name|bool
value|int
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|bool
value|char
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|HAS_BOOL
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* XXX A note on the perl source internal type system.  The    original intent was that I32 be *exactly* 32 bits.     Currently, we only guarantee that I32 is *at least* 32 bits.    Specifically, if int is 64 bits, then so is I32.  (This is the case    for the Cray.)  This has the advantage of meshing nicely with    standard library calls (where we pass an I32 and the library is    expecting an int), but the disadvantage that an I32 is not 32 bits.    Andy Dougherty	August 1996     There is no guarantee that there is *any* integral type with    exactly 32 bits.  It is perfectly legal for a system to have    sizeof(short) == sizeof(int) == sizeof(long) == 8.     Similarly, there is no guarantee that I16 and U16 have exactly 16    bits.     For dealing with issues that may arise from various 32/64-bit    systems, we will ask Configure to check out     	SHORTSIZE == sizeof(short)    	INTSIZE == sizeof(int)    	LONGSIZE == sizeof(long) 	LONGLONGSIZE == sizeof(long long) (if HAS_LONG_LONG)    	PTRSIZE == sizeof(void *) 	DOUBLESIZE == sizeof(double) 	LONG_DOUBLESIZE == sizeof(long double) (if HAS_LONG_DOUBLE).  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|I_INTTYPES
end_ifdef

begin_comment
comment|/* e.g. Linux has int64_t without<inttypes.h> */
end_comment

begin_include
include|#
directive|include
file|<inttypes.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_typedef
typedef|typedef
name|I8TYPE
name|I8
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|U8TYPE
name|U8
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|I16TYPE
name|I16
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|U16TYPE
name|U16
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|I32TYPE
name|I32
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|U32TYPE
name|U32
typedef|;
end_typedef

begin_ifdef
ifdef|#
directive|ifdef
name|PERL_CORE
end_ifdef

begin_ifdef
ifdef|#
directive|ifdef
name|HAS_QUAD
end_ifdef

begin_typedef
typedef|typedef
name|I64TYPE
name|I64
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|U64TYPE
name|U64
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* PERL_CORE */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|HAS_QUAD
argument_list|)
operator|&&
name|defined
argument_list|(
name|USE_64_BIT_INT
argument_list|)
end_if

begin_ifndef
ifndef|#
directive|ifndef
name|UINT64_C
end_ifndef

begin_comment
comment|/* usually from<inttypes.h> */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|HAS_LONG_LONG
argument_list|)
operator|&&
name|QUADKIND
operator|==
name|QUAD_IS_LONG_LONG
end_if

begin_define
define|#
directive|define
name|INT64_C
parameter_list|(
name|c
parameter_list|)
value|CAT2(c,LL)
end_define

begin_define
define|#
directive|define
name|UINT64_C
parameter_list|(
name|c
parameter_list|)
value|CAT2(c,ULL)
end_define

begin_else
else|#
directive|else
end_else

begin_if
if|#
directive|if
name|LONGSIZE
operator|==
literal|8
operator|&&
name|QUADKIND
operator|==
name|QUAD_IS_LONG
end_if

begin_define
define|#
directive|define
name|INT64_C
parameter_list|(
name|c
parameter_list|)
value|CAT2(c,L)
end_define

begin_define
define|#
directive|define
name|UINT64_C
parameter_list|(
name|c
parameter_list|)
value|CAT2(c,UL)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|INT64_C
parameter_list|(
name|c
parameter_list|)
value|((I64TYPE)(c))
end_define

begin_define
define|#
directive|define
name|UINT64_C
parameter_list|(
name|c
parameter_list|)
value|((U64TYPE)(c))
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
comment|/* Mention I8SIZE, U8SIZE, I16SIZE, U16SIZE, I32SIZE, U32SIZE,    I64SIZE, and U64SIZE here so that metaconfig pulls them in. */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|UINT8_MAX
argument_list|)
operator|&&
name|defined
argument_list|(
name|INT16_MAX
argument_list|)
operator|&&
name|defined
argument_list|(
name|INT32_MAX
argument_list|)
end_if

begin_comment
comment|/* I8_MAX and I8_MIN constants are not defined, as I8 is an ambiguous type.    Please search CHAR_MAX in perl.h for further details. */
end_comment

begin_define
define|#
directive|define
name|U8_MAX
value|UINT8_MAX
end_define

begin_define
define|#
directive|define
name|U8_MIN
value|UINT8_MIN
end_define

begin_define
define|#
directive|define
name|I16_MAX
value|INT16_MAX
end_define

begin_define
define|#
directive|define
name|I16_MIN
value|INT16_MIN
end_define

begin_define
define|#
directive|define
name|U16_MAX
value|UINT16_MAX
end_define

begin_define
define|#
directive|define
name|U16_MIN
value|UINT16_MIN
end_define

begin_define
define|#
directive|define
name|I32_MAX
value|INT32_MAX
end_define

begin_define
define|#
directive|define
name|I32_MIN
value|INT32_MIN
end_define

begin_define
define|#
directive|define
name|U32_MAX
value|UINT32_MAX
end_define

begin_define
define|#
directive|define
name|U32_MIN
value|UINT32_MIN
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* I8_MAX and I8_MIN constants are not defined, as I8 is an ambiguous type.    Please search CHAR_MAX in perl.h for further details. */
end_comment

begin_define
define|#
directive|define
name|U8_MAX
value|PERL_UCHAR_MAX
end_define

begin_define
define|#
directive|define
name|U8_MIN
value|PERL_UCHAR_MIN
end_define

begin_define
define|#
directive|define
name|I16_MAX
value|PERL_SHORT_MAX
end_define

begin_define
define|#
directive|define
name|I16_MIN
value|PERL_SHORT_MIN
end_define

begin_define
define|#
directive|define
name|U16_MAX
value|PERL_USHORT_MAX
end_define

begin_define
define|#
directive|define
name|U16_MIN
value|PERL_USHORT_MIN
end_define

begin_if
if|#
directive|if
name|LONGSIZE
operator|>
literal|4
end_if

begin_define
define|#
directive|define
name|I32_MAX
value|PERL_INT_MAX
end_define

begin_define
define|#
directive|define
name|I32_MIN
value|PERL_INT_MIN
end_define

begin_define
define|#
directive|define
name|U32_MAX
value|PERL_UINT_MAX
end_define

begin_define
define|#
directive|define
name|U32_MIN
value|PERL_UINT_MIN
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|I32_MAX
value|PERL_LONG_MAX
end_define

begin_define
define|#
directive|define
name|I32_MIN
value|PERL_LONG_MIN
end_define

begin_define
define|#
directive|define
name|U32_MAX
value|PERL_ULONG_MAX
end_define

begin_define
define|#
directive|define
name|U32_MIN
value|PERL_ULONG_MIN
end_define

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
name|BIT_DIGITS
parameter_list|(
name|N
parameter_list|)
value|(((N)*146)/485 + 1)
end_define

begin_comment
comment|/* log2(10) =~ 146/485 */
end_comment

begin_define
define|#
directive|define
name|TYPE_DIGITS
parameter_list|(
name|T
parameter_list|)
value|BIT_DIGITS(sizeof(T) * 8)
end_define

begin_define
define|#
directive|define
name|TYPE_CHARS
parameter_list|(
name|T
parameter_list|)
value|(TYPE_DIGITS(T) + 2)
end_define

begin_comment
comment|/* sign, NUL */
end_comment

begin_define
define|#
directive|define
name|Ctl
parameter_list|(
name|ch
parameter_list|)
value|((ch)& 037)
end_define

begin_comment
comment|/* =for apidoc Am|bool|strNE|char* s1|char* s2 Test two strings to see if they are different.  Returns true or false.  =for apidoc Am|bool|strEQ|char* s1|char* s2 Test two strings to see if they are equal.  Returns true or false.  =for apidoc Am|bool|strLT|char* s1|char* s2 Test two strings to see if the first, C<s1>, is less than the second, C<s2>.  Returns true or false.  =for apidoc Am|bool|strLE|char* s1|char* s2 Test two strings to see if the first, C<s1>, is less than or equal to the second, C<s2>.  Returns true or false.  =for apidoc Am|bool|strGT|char* s1|char* s2 Test two strings to see if the first, C<s1>, is greater than the second, C<s2>.  Returns true or false.  =for apidoc Am|bool|strGE|char* s1|char* s2 Test two strings to see if the first, C<s1>, is greater than or equal to the second, C<s2>.  Returns true or false.  =for apidoc Am|bool|strnNE|char* s1|char* s2|STRLEN len Test two strings to see if they are different.  The C<len> parameter indicates the number of bytes to compare.  Returns true or false. (A wrapper for C<strncmp>).  =for apidoc Am|bool|strnEQ|char* s1|char* s2|STRLEN len Test two strings to see if they are equal.  The C<len> parameter indicates the number of bytes to compare.  Returns true or false. (A wrapper for C<strncmp>).  =cut */
end_comment

begin_define
define|#
directive|define
name|strNE
parameter_list|(
name|s1
parameter_list|,
name|s2
parameter_list|)
value|(strcmp(s1,s2))
end_define

begin_define
define|#
directive|define
name|strEQ
parameter_list|(
name|s1
parameter_list|,
name|s2
parameter_list|)
value|(!strcmp(s1,s2))
end_define

begin_define
define|#
directive|define
name|strLT
parameter_list|(
name|s1
parameter_list|,
name|s2
parameter_list|)
value|(strcmp(s1,s2)< 0)
end_define

begin_define
define|#
directive|define
name|strLE
parameter_list|(
name|s1
parameter_list|,
name|s2
parameter_list|)
value|(strcmp(s1,s2)<= 0)
end_define

begin_define
define|#
directive|define
name|strGT
parameter_list|(
name|s1
parameter_list|,
name|s2
parameter_list|)
value|(strcmp(s1,s2)> 0)
end_define

begin_define
define|#
directive|define
name|strGE
parameter_list|(
name|s1
parameter_list|,
name|s2
parameter_list|)
value|(strcmp(s1,s2)>= 0)
end_define

begin_define
define|#
directive|define
name|strnNE
parameter_list|(
name|s1
parameter_list|,
name|s2
parameter_list|,
name|l
parameter_list|)
value|(strncmp(s1,s2,l))
end_define

begin_define
define|#
directive|define
name|strnEQ
parameter_list|(
name|s1
parameter_list|,
name|s2
parameter_list|,
name|l
parameter_list|)
value|(!strncmp(s1,s2,l))
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|HAS_MEMCMP
end_ifdef

begin_define
define|#
directive|define
name|memNE
parameter_list|(
name|s1
parameter_list|,
name|s2
parameter_list|,
name|l
parameter_list|)
value|(memcmp(s1,s2,l))
end_define

begin_define
define|#
directive|define
name|memEQ
parameter_list|(
name|s1
parameter_list|,
name|s2
parameter_list|,
name|l
parameter_list|)
value|(!memcmp(s1,s2,l))
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|memNE
parameter_list|(
name|s1
parameter_list|,
name|s2
parameter_list|,
name|l
parameter_list|)
value|(bcmp(s1,s2,l))
end_define

begin_define
define|#
directive|define
name|memEQ
parameter_list|(
name|s1
parameter_list|,
name|s2
parameter_list|,
name|l
parameter_list|)
value|(!bcmp(s1,s2,l))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * Character classes.  *  * Unfortunately, the introduction of locales means that we  * can't trust isupper(), etc. to tell the truth.  And when  * it comes to /\w+/ with tainting enabled, we *must* be able  * to trust our character classes.  *  * Therefore, the default tests in the text of Perl will be  * independent of locale.  Any code that wants to depend on  * the current locale will use the tests that begin with "lc".  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|HAS_SETLOCALE
end_ifdef

begin_comment
comment|/* XXX Is there a better test for this? */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|CTYPE256
end_ifndef

begin_define
define|#
directive|define
name|CTYPE256
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
comment|/* =for apidoc Am|bool|isALNUM|char ch Returns a boolean indicating whether the C C<char> is an ASCII alphanumeric character (including underscore) or digit.  =for apidoc Am|bool|isALPHA|char ch Returns a boolean indicating whether the C C<char> is an ASCII alphabetic character.  =for apidoc Am|bool|isSPACE|char ch Returns a boolean indicating whether the C C<char> is whitespace.  =for apidoc Am|bool|isDIGIT|char ch Returns a boolean indicating whether the C C<char> is an ASCII digit.  =for apidoc Am|bool|isUPPER|char ch Returns a boolean indicating whether the C C<char> is an uppercase character.  =for apidoc Am|bool|isLOWER|char ch Returns a boolean indicating whether the C C<char> is a lowercase character.  =for apidoc Am|char|toUPPER|char ch Converts the specified character to uppercase.  =for apidoc Am|char|toLOWER|char ch Converts the specified character to lowercase.  =cut */
end_comment

begin_define
define|#
directive|define
name|isALNUM
parameter_list|(
name|c
parameter_list|)
value|(isALPHA(c) || isDIGIT(c) || (c) == '_')
end_define

begin_define
define|#
directive|define
name|isIDFIRST
parameter_list|(
name|c
parameter_list|)
value|(isALPHA(c) || (c) == '_')
end_define

begin_define
define|#
directive|define
name|isALPHA
parameter_list|(
name|c
parameter_list|)
value|(isUPPER(c) || isLOWER(c))
end_define

begin_define
define|#
directive|define
name|isSPACE
parameter_list|(
name|c
parameter_list|)
define|\
value|((c) == ' ' || (c) == '\t' || (c) == '\n' || (c) =='\r' || (c) == '\f')
end_define

begin_define
define|#
directive|define
name|isPSXSPC
parameter_list|(
name|c
parameter_list|)
value|(isSPACE(c) || (c) == '\v')
end_define

begin_define
define|#
directive|define
name|isBLANK
parameter_list|(
name|c
parameter_list|)
value|((c) == ' ' || (c) == '\t')
end_define

begin_define
define|#
directive|define
name|isDIGIT
parameter_list|(
name|c
parameter_list|)
value|((c)>= '0'&& (c)<= '9')
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|EBCDIC
end_ifdef

begin_comment
comment|/* In EBCDIC we do not do locales: therefore() isupper() is fine. */
end_comment

begin_define
define|#
directive|define
name|isUPPER
parameter_list|(
name|c
parameter_list|)
value|isupper(c)
end_define

begin_define
define|#
directive|define
name|isLOWER
parameter_list|(
name|c
parameter_list|)
value|islower(c)
end_define

begin_define
define|#
directive|define
name|isALNUMC
parameter_list|(
name|c
parameter_list|)
value|isalnum(c)
end_define

begin_define
define|#
directive|define
name|isASCII
parameter_list|(
name|c
parameter_list|)
value|isascii(c)
end_define

begin_define
define|#
directive|define
name|isCNTRL
parameter_list|(
name|c
parameter_list|)
value|iscntrl(c)
end_define

begin_define
define|#
directive|define
name|isGRAPH
parameter_list|(
name|c
parameter_list|)
value|isgraph(c)
end_define

begin_define
define|#
directive|define
name|isPRINT
parameter_list|(
name|c
parameter_list|)
value|isprint(c)
end_define

begin_define
define|#
directive|define
name|isPUNCT
parameter_list|(
name|c
parameter_list|)
value|ispunct(c)
end_define

begin_define
define|#
directive|define
name|isXDIGIT
parameter_list|(
name|c
parameter_list|)
value|isxdigit(c)
end_define

begin_define
define|#
directive|define
name|toUPPER
parameter_list|(
name|c
parameter_list|)
value|toupper(c)
end_define

begin_define
define|#
directive|define
name|toLOWER
parameter_list|(
name|c
parameter_list|)
value|tolower(c)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|isUPPER
parameter_list|(
name|c
parameter_list|)
value|((c)>= 'A'&& (c)<= 'Z')
end_define

begin_define
define|#
directive|define
name|isLOWER
parameter_list|(
name|c
parameter_list|)
value|((c)>= 'a'&& (c)<= 'z')
end_define

begin_define
define|#
directive|define
name|isALNUMC
parameter_list|(
name|c
parameter_list|)
value|(isALPHA(c) || isDIGIT(c))
end_define

begin_define
define|#
directive|define
name|isASCII
parameter_list|(
name|c
parameter_list|)
value|((c)<= 127)
end_define

begin_define
define|#
directive|define
name|isCNTRL
parameter_list|(
name|c
parameter_list|)
value|((c)< ' ')
end_define

begin_define
define|#
directive|define
name|isGRAPH
parameter_list|(
name|c
parameter_list|)
value|(isALNUM(c) || isPUNCT(c))
end_define

begin_define
define|#
directive|define
name|isPRINT
parameter_list|(
name|c
parameter_list|)
value|(((c)> 32&& (c)< 127) || isSPACE(c))
end_define

begin_define
define|#
directive|define
name|isPUNCT
parameter_list|(
name|c
parameter_list|)
value|(((c)>= 33&& (c)<= 47) || ((c)>= 58&& (c)<= 64)  || ((c)>= 91&& (c)<= 96) || ((c)>= 123&& (c)<= 126))
end_define

begin_define
define|#
directive|define
name|isXDIGIT
parameter_list|(
name|c
parameter_list|)
value|(isdigit(c) || ((c)>= 'a'&& (c)<= 'f') || ((c)>= 'A'&& (c)<= 'F'))
end_define

begin_define
define|#
directive|define
name|toUPPER
parameter_list|(
name|c
parameter_list|)
value|(isLOWER(c) ? (c) - ('a' - 'A') : (c))
end_define

begin_define
define|#
directive|define
name|toLOWER
parameter_list|(
name|c
parameter_list|)
value|(isUPPER(c) ? (c) + ('a' - 'A') : (c))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|USE_NEXT_CTYPE
end_ifdef

begin_define
define|#
directive|define
name|isALNUM_LC
parameter_list|(
name|c
parameter_list|)
define|\
value|(NXIsAlNum((unsigned int)(c)) || (char)(c) == '_')
end_define

begin_define
define|#
directive|define
name|isIDFIRST_LC
parameter_list|(
name|c
parameter_list|)
define|\
value|(NXIsAlpha((unsigned int)(c)) || (char)(c) == '_')
end_define

begin_define
define|#
directive|define
name|isALPHA_LC
parameter_list|(
name|c
parameter_list|)
value|NXIsAlpha((unsigned int)(c))
end_define

begin_define
define|#
directive|define
name|isSPACE_LC
parameter_list|(
name|c
parameter_list|)
value|NXIsSpace((unsigned int)(c))
end_define

begin_define
define|#
directive|define
name|isDIGIT_LC
parameter_list|(
name|c
parameter_list|)
value|NXIsDigit((unsigned int)(c))
end_define

begin_define
define|#
directive|define
name|isUPPER_LC
parameter_list|(
name|c
parameter_list|)
value|NXIsUpper((unsigned int)(c))
end_define

begin_define
define|#
directive|define
name|isLOWER_LC
parameter_list|(
name|c
parameter_list|)
value|NXIsLower((unsigned int)(c))
end_define

begin_define
define|#
directive|define
name|isALNUMC_LC
parameter_list|(
name|c
parameter_list|)
value|NXIsAlNum((unsigned int)(c))
end_define

begin_define
define|#
directive|define
name|isCNTRL_LC
parameter_list|(
name|c
parameter_list|)
value|NXIsCntrl((unsigned int)(c))
end_define

begin_define
define|#
directive|define
name|isGRAPH_LC
parameter_list|(
name|c
parameter_list|)
value|NXIsGraph((unsigned int)(c))
end_define

begin_define
define|#
directive|define
name|isPRINT_LC
parameter_list|(
name|c
parameter_list|)
value|NXIsPrint((unsigned int)(c))
end_define

begin_define
define|#
directive|define
name|isPUNCT_LC
parameter_list|(
name|c
parameter_list|)
value|NXIsPunct((unsigned int)(c))
end_define

begin_define
define|#
directive|define
name|toUPPER_LC
parameter_list|(
name|c
parameter_list|)
value|NXToUpper((unsigned int)(c))
end_define

begin_define
define|#
directive|define
name|toLOWER_LC
parameter_list|(
name|c
parameter_list|)
value|NXToLower((unsigned int)(c))
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* !USE_NEXT_CTYPE */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|CTYPE256
argument_list|)
operator|||
operator|(
operator|!
name|defined
argument_list|(
name|isascii
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|HAS_ISASCII
argument_list|)
operator|)
end_if

begin_define
define|#
directive|define
name|isALNUM_LC
parameter_list|(
name|c
parameter_list|)
value|(isalnum((unsigned char)(c)) || (char)(c) == '_')
end_define

begin_define
define|#
directive|define
name|isIDFIRST_LC
parameter_list|(
name|c
parameter_list|)
value|(isalpha((unsigned char)(c)) || (char)(c) == '_')
end_define

begin_define
define|#
directive|define
name|isALPHA_LC
parameter_list|(
name|c
parameter_list|)
value|isalpha((unsigned char)(c))
end_define

begin_define
define|#
directive|define
name|isSPACE_LC
parameter_list|(
name|c
parameter_list|)
value|isspace((unsigned char)(c))
end_define

begin_define
define|#
directive|define
name|isDIGIT_LC
parameter_list|(
name|c
parameter_list|)
value|isdigit((unsigned char)(c))
end_define

begin_define
define|#
directive|define
name|isUPPER_LC
parameter_list|(
name|c
parameter_list|)
value|isupper((unsigned char)(c))
end_define

begin_define
define|#
directive|define
name|isLOWER_LC
parameter_list|(
name|c
parameter_list|)
value|islower((unsigned char)(c))
end_define

begin_define
define|#
directive|define
name|isALNUMC_LC
parameter_list|(
name|c
parameter_list|)
value|isalnum((unsigned char)(c))
end_define

begin_define
define|#
directive|define
name|isCNTRL_LC
parameter_list|(
name|c
parameter_list|)
value|iscntrl((unsigned char)(c))
end_define

begin_define
define|#
directive|define
name|isGRAPH_LC
parameter_list|(
name|c
parameter_list|)
value|isgraph((unsigned char)(c))
end_define

begin_define
define|#
directive|define
name|isPRINT_LC
parameter_list|(
name|c
parameter_list|)
value|isprint((unsigned char)(c))
end_define

begin_define
define|#
directive|define
name|isPUNCT_LC
parameter_list|(
name|c
parameter_list|)
value|ispunct((unsigned char)(c))
end_define

begin_define
define|#
directive|define
name|toUPPER_LC
parameter_list|(
name|c
parameter_list|)
value|toupper((unsigned char)(c))
end_define

begin_define
define|#
directive|define
name|toLOWER_LC
parameter_list|(
name|c
parameter_list|)
value|tolower((unsigned char)(c))
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|isALNUM_LC
parameter_list|(
name|c
parameter_list|)
value|(isascii(c)&& (isalnum(c) || (c) == '_'))
end_define

begin_define
define|#
directive|define
name|isIDFIRST_LC
parameter_list|(
name|c
parameter_list|)
value|(isascii(c)&& (isalpha(c) || (c) == '_'))
end_define

begin_define
define|#
directive|define
name|isALPHA_LC
parameter_list|(
name|c
parameter_list|)
value|(isascii(c)&& isalpha(c))
end_define

begin_define
define|#
directive|define
name|isSPACE_LC
parameter_list|(
name|c
parameter_list|)
value|(isascii(c)&& isspace(c))
end_define

begin_define
define|#
directive|define
name|isDIGIT_LC
parameter_list|(
name|c
parameter_list|)
value|(isascii(c)&& isdigit(c))
end_define

begin_define
define|#
directive|define
name|isUPPER_LC
parameter_list|(
name|c
parameter_list|)
value|(isascii(c)&& isupper(c))
end_define

begin_define
define|#
directive|define
name|isLOWER_LC
parameter_list|(
name|c
parameter_list|)
value|(isascii(c)&& islower(c))
end_define

begin_define
define|#
directive|define
name|isALNUMC_LC
parameter_list|(
name|c
parameter_list|)
value|(isascii(c)&& isalnum(c))
end_define

begin_define
define|#
directive|define
name|isCNTRL_LC
parameter_list|(
name|c
parameter_list|)
value|(isascii(c)&& iscntrl(c))
end_define

begin_define
define|#
directive|define
name|isGRAPH_LC
parameter_list|(
name|c
parameter_list|)
value|(isascii(c)&& isgraph(c))
end_define

begin_define
define|#
directive|define
name|isPRINT_LC
parameter_list|(
name|c
parameter_list|)
value|(isascii(c)&& isprint(c))
end_define

begin_define
define|#
directive|define
name|isPUNCT_LC
parameter_list|(
name|c
parameter_list|)
value|(isascii(c)&& ispunct(c))
end_define

begin_define
define|#
directive|define
name|toUPPER_LC
parameter_list|(
name|c
parameter_list|)
value|toupper(c)
end_define

begin_define
define|#
directive|define
name|toLOWER_LC
parameter_list|(
name|c
parameter_list|)
value|tolower(c)
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
comment|/* USE_NEXT_CTYPE */
end_comment

begin_define
define|#
directive|define
name|isPSXSPC_LC
parameter_list|(
name|c
parameter_list|)
value|(isSPACE_LC(c) || (c) == '\v')
end_define

begin_define
define|#
directive|define
name|isBLANK_LC
parameter_list|(
name|c
parameter_list|)
value|isBLANK(c)
end_define

begin_comment
comment|/* could be wrong */
end_comment

begin_define
define|#
directive|define
name|isALNUM_uni
parameter_list|(
name|c
parameter_list|)
value|is_uni_alnum(c)
end_define

begin_define
define|#
directive|define
name|isIDFIRST_uni
parameter_list|(
name|c
parameter_list|)
value|is_uni_idfirst(c)
end_define

begin_define
define|#
directive|define
name|isALPHA_uni
parameter_list|(
name|c
parameter_list|)
value|is_uni_alpha(c)
end_define

begin_define
define|#
directive|define
name|isSPACE_uni
parameter_list|(
name|c
parameter_list|)
value|is_uni_space(c)
end_define

begin_define
define|#
directive|define
name|isDIGIT_uni
parameter_list|(
name|c
parameter_list|)
value|is_uni_digit(c)
end_define

begin_define
define|#
directive|define
name|isUPPER_uni
parameter_list|(
name|c
parameter_list|)
value|is_uni_upper(c)
end_define

begin_define
define|#
directive|define
name|isLOWER_uni
parameter_list|(
name|c
parameter_list|)
value|is_uni_lower(c)
end_define

begin_define
define|#
directive|define
name|isALNUMC_uni
parameter_list|(
name|c
parameter_list|)
value|is_uni_alnumc(c)
end_define

begin_define
define|#
directive|define
name|isASCII_uni
parameter_list|(
name|c
parameter_list|)
value|is_uni_ascii(c)
end_define

begin_define
define|#
directive|define
name|isCNTRL_uni
parameter_list|(
name|c
parameter_list|)
value|is_uni_cntrl(c)
end_define

begin_define
define|#
directive|define
name|isGRAPH_uni
parameter_list|(
name|c
parameter_list|)
value|is_uni_graph(c)
end_define

begin_define
define|#
directive|define
name|isPRINT_uni
parameter_list|(
name|c
parameter_list|)
value|is_uni_print(c)
end_define

begin_define
define|#
directive|define
name|isPUNCT_uni
parameter_list|(
name|c
parameter_list|)
value|is_uni_punct(c)
end_define

begin_define
define|#
directive|define
name|isXDIGIT_uni
parameter_list|(
name|c
parameter_list|)
value|is_uni_xdigit(c)
end_define

begin_define
define|#
directive|define
name|toUPPER_uni
parameter_list|(
name|c
parameter_list|)
value|to_uni_upper(c)
end_define

begin_define
define|#
directive|define
name|toTITLE_uni
parameter_list|(
name|c
parameter_list|)
value|to_uni_title(c)
end_define

begin_define
define|#
directive|define
name|toLOWER_uni
parameter_list|(
name|c
parameter_list|)
value|to_uni_lower(c)
end_define

begin_define
define|#
directive|define
name|isPSXSPC_uni
parameter_list|(
name|c
parameter_list|)
value|(isSPACE_uni(c) ||(c) == '\f')
end_define

begin_define
define|#
directive|define
name|isBLANK_uni
parameter_list|(
name|c
parameter_list|)
value|isBLANK(c)
end_define

begin_comment
comment|/* could be wrong */
end_comment

begin_define
define|#
directive|define
name|isALNUM_LC_uni
parameter_list|(
name|c
parameter_list|)
value|(c< 256 ? isALNUM_LC(c) : is_uni_alnum_lc(c))
end_define

begin_define
define|#
directive|define
name|isIDFIRST_LC_uni
parameter_list|(
name|c
parameter_list|)
value|(c< 256 ? isIDFIRST_LC(c) : is_uni_idfirst_lc(c))
end_define

begin_define
define|#
directive|define
name|isALPHA_LC_uni
parameter_list|(
name|c
parameter_list|)
value|(c< 256 ? isALPHA_LC(c) : is_uni_alpha_lc(c))
end_define

begin_define
define|#
directive|define
name|isSPACE_LC_uni
parameter_list|(
name|c
parameter_list|)
value|(c< 256 ? isSPACE_LC(c) : is_uni_space_lc(c))
end_define

begin_define
define|#
directive|define
name|isDIGIT_LC_uni
parameter_list|(
name|c
parameter_list|)
value|(c< 256 ? isDIGIT_LC(c) : is_uni_digit_lc(c))
end_define

begin_define
define|#
directive|define
name|isUPPER_LC_uni
parameter_list|(
name|c
parameter_list|)
value|(c< 256 ? isUPPER_LC(c) : is_uni_upper_lc(c))
end_define

begin_define
define|#
directive|define
name|isLOWER_LC_uni
parameter_list|(
name|c
parameter_list|)
value|(c< 256 ? isLOWER_LC(c) : is_uni_lower_lc(c))
end_define

begin_define
define|#
directive|define
name|isALNUMC_LC_uni
parameter_list|(
name|c
parameter_list|)
value|(c< 256 ? isALNUMC_LC(c) : is_uni_alnumc_lc(c))
end_define

begin_define
define|#
directive|define
name|isCNTRL_LC_uni
parameter_list|(
name|c
parameter_list|)
value|(c< 256 ? isCNTRL_LC(c) : is_uni_cntrl_lc(c))
end_define

begin_define
define|#
directive|define
name|isGRAPH_LC_uni
parameter_list|(
name|c
parameter_list|)
value|(c< 256 ? isGRAPH_LC(c) : is_uni_graph_lc(c))
end_define

begin_define
define|#
directive|define
name|isPRINT_LC_uni
parameter_list|(
name|c
parameter_list|)
value|(c< 256 ? isPRINT_LC(c) : is_uni_print_lc(c))
end_define

begin_define
define|#
directive|define
name|isPUNCT_LC_uni
parameter_list|(
name|c
parameter_list|)
value|(c< 256 ? isPUNCT_LC(c) : is_uni_punct_lc(c))
end_define

begin_define
define|#
directive|define
name|toUPPER_LC_uni
parameter_list|(
name|c
parameter_list|)
value|(c< 256 ? toUPPER_LC(c) : to_uni_upper_lc(c))
end_define

begin_define
define|#
directive|define
name|toTITLE_LC_uni
parameter_list|(
name|c
parameter_list|)
value|(c< 256 ? toUPPER_LC(c) : to_uni_title_lc(c))
end_define

begin_define
define|#
directive|define
name|toLOWER_LC_uni
parameter_list|(
name|c
parameter_list|)
value|(c< 256 ? toLOWER_LC(c) : to_uni_lower_lc(c))
end_define

begin_define
define|#
directive|define
name|isPSXSPC_LC_uni
parameter_list|(
name|c
parameter_list|)
value|(isSPACE_LC_uni(c) ||(c) == '\f')
end_define

begin_define
define|#
directive|define
name|isBLANK_LC_uni
parameter_list|(
name|c
parameter_list|)
value|isBLANK(c)
end_define

begin_comment
comment|/* could be wrong */
end_comment

begin_define
define|#
directive|define
name|isALNUM_utf8
parameter_list|(
name|p
parameter_list|)
value|is_utf8_alnum(p)
end_define

begin_define
define|#
directive|define
name|isIDFIRST_utf8
parameter_list|(
name|p
parameter_list|)
value|is_utf8_idfirst(p)
end_define

begin_define
define|#
directive|define
name|isALPHA_utf8
parameter_list|(
name|p
parameter_list|)
value|is_utf8_alpha(p)
end_define

begin_define
define|#
directive|define
name|isSPACE_utf8
parameter_list|(
name|p
parameter_list|)
value|is_utf8_space(p)
end_define

begin_define
define|#
directive|define
name|isDIGIT_utf8
parameter_list|(
name|p
parameter_list|)
value|is_utf8_digit(p)
end_define

begin_define
define|#
directive|define
name|isUPPER_utf8
parameter_list|(
name|p
parameter_list|)
value|is_utf8_upper(p)
end_define

begin_define
define|#
directive|define
name|isLOWER_utf8
parameter_list|(
name|p
parameter_list|)
value|is_utf8_lower(p)
end_define

begin_define
define|#
directive|define
name|isALNUMC_utf8
parameter_list|(
name|p
parameter_list|)
value|is_utf8_alnumc(p)
end_define

begin_define
define|#
directive|define
name|isASCII_utf8
parameter_list|(
name|p
parameter_list|)
value|is_utf8_ascii(p)
end_define

begin_define
define|#
directive|define
name|isCNTRL_utf8
parameter_list|(
name|p
parameter_list|)
value|is_utf8_cntrl(p)
end_define

begin_define
define|#
directive|define
name|isGRAPH_utf8
parameter_list|(
name|p
parameter_list|)
value|is_utf8_graph(p)
end_define

begin_define
define|#
directive|define
name|isPRINT_utf8
parameter_list|(
name|p
parameter_list|)
value|is_utf8_print(p)
end_define

begin_define
define|#
directive|define
name|isPUNCT_utf8
parameter_list|(
name|p
parameter_list|)
value|is_utf8_punct(p)
end_define

begin_define
define|#
directive|define
name|isXDIGIT_utf8
parameter_list|(
name|p
parameter_list|)
value|is_utf8_xdigit(p)
end_define

begin_define
define|#
directive|define
name|toUPPER_utf8
parameter_list|(
name|p
parameter_list|)
value|to_utf8_upper(p)
end_define

begin_define
define|#
directive|define
name|toTITLE_utf8
parameter_list|(
name|p
parameter_list|)
value|to_utf8_title(p)
end_define

begin_define
define|#
directive|define
name|toLOWER_utf8
parameter_list|(
name|p
parameter_list|)
value|to_utf8_lower(p)
end_define

begin_define
define|#
directive|define
name|isPSXSPC_utf8
parameter_list|(
name|c
parameter_list|)
value|(isSPACE_utf8(c) ||(c) == '\f')
end_define

begin_define
define|#
directive|define
name|isBLANK_utf8
parameter_list|(
name|c
parameter_list|)
value|isBLANK(c)
end_define

begin_comment
comment|/* could be wrong */
end_comment

begin_define
define|#
directive|define
name|isALNUM_LC_utf8
parameter_list|(
name|p
parameter_list|)
value|isALNUM_LC_uni(utf8_to_uv(p, UTF8_MAXLEN, 0, 0))
end_define

begin_define
define|#
directive|define
name|isIDFIRST_LC_utf8
parameter_list|(
name|p
parameter_list|)
value|isIDFIRST_LC_uni(utf8_to_uv(p, UTF8_MAXLEN, 0, 0))
end_define

begin_define
define|#
directive|define
name|isALPHA_LC_utf8
parameter_list|(
name|p
parameter_list|)
value|isALPHA_LC_uni(utf8_to_uv(p, UTF8_MAXLEN, 0, 0))
end_define

begin_define
define|#
directive|define
name|isSPACE_LC_utf8
parameter_list|(
name|p
parameter_list|)
value|isSPACE_LC_uni(utf8_to_uv(p, UTF8_MAXLEN, 0, 0))
end_define

begin_define
define|#
directive|define
name|isDIGIT_LC_utf8
parameter_list|(
name|p
parameter_list|)
value|isDIGIT_LC_uni(utf8_to_uv(p, UTF8_MAXLEN, 0, 0))
end_define

begin_define
define|#
directive|define
name|isUPPER_LC_utf8
parameter_list|(
name|p
parameter_list|)
value|isUPPER_LC_uni(utf8_to_uv(p, UTF8_MAXLEN, 0, 0))
end_define

begin_define
define|#
directive|define
name|isLOWER_LC_utf8
parameter_list|(
name|p
parameter_list|)
value|isLOWER_LC_uni(utf8_to_uv(p, UTF8_MAXLEN, 0, 0))
end_define

begin_define
define|#
directive|define
name|isALNUMC_LC_utf8
parameter_list|(
name|p
parameter_list|)
value|isALNUMC_LC_uni(utf8_to_uv(p, UTF8_MAXLEN, 0, 0))
end_define

begin_define
define|#
directive|define
name|isCNTRL_LC_utf8
parameter_list|(
name|p
parameter_list|)
value|isCNTRL_LC_uni(utf8_to_uv(p, UTF8_MAXLEN, 0, 0))
end_define

begin_define
define|#
directive|define
name|isGRAPH_LC_utf8
parameter_list|(
name|p
parameter_list|)
value|isGRAPH_LC_uni(utf8_to_uv(p, UTF8_MAXLEN, 0, 0))
end_define

begin_define
define|#
directive|define
name|isPRINT_LC_utf8
parameter_list|(
name|p
parameter_list|)
value|isPRINT_LC_uni(utf8_to_uv(p, UTF8_MAXLEN, 0, 0))
end_define

begin_define
define|#
directive|define
name|isPUNCT_LC_utf8
parameter_list|(
name|p
parameter_list|)
value|isPUNCT_LC_uni(utf8_to_uv(p, UTF8_MAXLEN, 0, 0))
end_define

begin_define
define|#
directive|define
name|toUPPER_LC_utf8
parameter_list|(
name|p
parameter_list|)
value|toUPPER_LC_uni(utf8_to_uv(p, UTF8_MAXLEN, 0, 0))
end_define

begin_define
define|#
directive|define
name|toTITLE_LC_utf8
parameter_list|(
name|p
parameter_list|)
value|toTITLE_LC_uni(utf8_to_uv(p, UTF8_MAXLEN, 0, 0))
end_define

begin_define
define|#
directive|define
name|toLOWER_LC_utf8
parameter_list|(
name|p
parameter_list|)
value|toLOWER_LC_uni(utf8_to_uv(p, UTF8_MAXLEN, 0, 0))
end_define

begin_define
define|#
directive|define
name|isPSXSPC_LC_utf8
parameter_list|(
name|c
parameter_list|)
value|(isSPACE_LC_utf8(c) ||(c) == '\f')
end_define

begin_define
define|#
directive|define
name|isBLANK_LC_utf8
parameter_list|(
name|c
parameter_list|)
value|isBLANK(c)
end_define

begin_comment
comment|/* could be wrong */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|EBCDIC
end_ifdef

begin_define
define|#
directive|define
name|toCTRL
parameter_list|(
name|c
parameter_list|)
value|Perl_ebcdic_control(c)
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* This conversion works both ways, strangely enough. */
end_comment

begin_define
define|#
directive|define
name|toCTRL
parameter_list|(
name|c
parameter_list|)
value|(toUPPER(c) ^ 64)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Line numbers are unsigned, 16 bits. */
end_comment

begin_typedef
typedef|typedef
name|U16
name|line_t
typedef|;
end_typedef

begin_ifdef
ifdef|#
directive|ifdef
name|lint
end_ifdef

begin_define
define|#
directive|define
name|NOLINE
value|((line_t)0)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|NOLINE
value|((line_t) 65535)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*    XXX LEAKTEST doesn't really work in perl5.  There are direct calls to    safemalloc() in the source, so LEAKTEST won't pick them up.    (The main "offenders" are extensions.)    Further, if you try LEAKTEST, you'll also end up calling    Safefree, which might call safexfree() on some things that weren't    malloced with safexmalloc.  The correct "fix" to this, if anyone    is interested, is to ensure that all calls go through the New and    Renew macros. 	--Andy Dougherty		August 1996 */
end_comment

begin_comment
comment|/* =for apidoc Am|SV*|NEWSV|int id|STRLEN len Creates a new SV.  A non-zero C<len> parameter indicates the number of bytes of preallocated string space the SV should have.  An extra byte for a tailing NUL is also reserved.  (SvPOK is not set for the SV even if string space is allocated.)  The reference count for the new SV is set to 1. C<id> is an integer id between 0 and 1299 (used to identify leaks).  =for apidoc Am|void|New|int id|void* ptr|int nitems|type The XSUB-writer's interface to the C C<malloc> function.  =for apidoc Am|void|Newc|int id|void* ptr|int nitems|type|cast The XSUB-writer's interface to the C C<malloc> function, with cast.  =for apidoc Am|void|Newz|int id|void* ptr|int nitems|type The XSUB-writer's interface to the C C<malloc> function.  The allocated memory is zeroed with C<memzero>.  =for apidoc Am|void|Renew|void* ptr|int nitems|type The XSUB-writer's interface to the C C<realloc> function.  =for apidoc Am|void|Renewc|void* ptr|int nitems|type|cast The XSUB-writer's interface to the C C<realloc> function, with cast.  =for apidoc Am|void|Safefree|void* ptr The XSUB-writer's interface to the C C<free> function.  =for apidoc Am|void|Move|void* src|void* dest|int nitems|type The XSUB-writer's interface to the C C<memmove> function.  The C<src> is the source, C<dest> is the destination, C<nitems> is the number of items, and C<type> is the type.  Can do overlapping moves.  See also C<Copy>.  =for apidoc Am|void|Copy|void* src|void* dest|int nitems|type The XSUB-writer's interface to the C C<memcpy> function.  The C<src> is the source, C<dest> is the destination, C<nitems> is the number of items, and C<type> is the type.  May fail on overlapping copies.  See also C<Move>.  =for apidoc Am|void|Zero|void* dest|int nitems|type  The XSUB-writer's interface to the C C<memzero> function.  The C<dest> is the destination, C<nitems> is the number of items, and C<type> is the type.  =for apidoc Am|void|StructCopy|type src|type dest|type This is an architecture-independent macro to copy one structure to another.  =cut */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|lint
end_ifndef

begin_define
define|#
directive|define
name|NEWSV
parameter_list|(
name|x
parameter_list|,
name|len
parameter_list|)
value|newSV(len)
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|LEAKTEST
end_ifndef

begin_define
define|#
directive|define
name|New
parameter_list|(
name|x
parameter_list|,
name|v
parameter_list|,
name|n
parameter_list|,
name|t
parameter_list|)
value|(v = (t*)safemalloc((MEM_SIZE)((n)*sizeof(t))))
end_define

begin_define
define|#
directive|define
name|Newc
parameter_list|(
name|x
parameter_list|,
name|v
parameter_list|,
name|n
parameter_list|,
name|t
parameter_list|,
name|c
parameter_list|)
value|(v = (c*)safemalloc((MEM_SIZE)((n)*sizeof(t))))
end_define

begin_define
define|#
directive|define
name|Newz
parameter_list|(
name|x
parameter_list|,
name|v
parameter_list|,
name|n
parameter_list|,
name|t
parameter_list|)
value|(v = (t*)safemalloc((MEM_SIZE)((n)*sizeof(t)))), \ 			memzero((char*)(v), (n)*sizeof(t))
end_define

begin_define
define|#
directive|define
name|Renew
parameter_list|(
name|v
parameter_list|,
name|n
parameter_list|,
name|t
parameter_list|)
define|\
value|(v = (t*)saferealloc((Malloc_t)(v),(MEM_SIZE)((n)*sizeof(t))))
end_define

begin_define
define|#
directive|define
name|Renewc
parameter_list|(
name|v
parameter_list|,
name|n
parameter_list|,
name|t
parameter_list|,
name|c
parameter_list|)
define|\
value|(v = (c*)saferealloc((Malloc_t)(v),(MEM_SIZE)((n)*sizeof(t))))
end_define

begin_define
define|#
directive|define
name|Safefree
parameter_list|(
name|d
parameter_list|)
value|safefree((Malloc_t)(d))
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* LEAKTEST */
end_comment

begin_define
define|#
directive|define
name|New
parameter_list|(
name|x
parameter_list|,
name|v
parameter_list|,
name|n
parameter_list|,
name|t
parameter_list|)
value|(v = (t*)safexmalloc((x),(MEM_SIZE)((n)*sizeof(t))))
end_define

begin_define
define|#
directive|define
name|Newc
parameter_list|(
name|x
parameter_list|,
name|v
parameter_list|,
name|n
parameter_list|,
name|t
parameter_list|,
name|c
parameter_list|)
value|(v = (c*)safexmalloc((x),(MEM_SIZE)((n)*sizeof(t))))
end_define

begin_define
define|#
directive|define
name|Newz
parameter_list|(
name|x
parameter_list|,
name|v
parameter_list|,
name|n
parameter_list|,
name|t
parameter_list|)
value|(v = (t*)safexmalloc((x),(MEM_SIZE)((n)*sizeof(t)))), \ 			 memzero((char*)(v), (n)*sizeof(t))
end_define

begin_define
define|#
directive|define
name|Renew
parameter_list|(
name|v
parameter_list|,
name|n
parameter_list|,
name|t
parameter_list|)
define|\
value|(v = (t*)safexrealloc((Malloc_t)(v),(MEM_SIZE)((n)*sizeof(t))))
end_define

begin_define
define|#
directive|define
name|Renewc
parameter_list|(
name|v
parameter_list|,
name|n
parameter_list|,
name|t
parameter_list|,
name|c
parameter_list|)
define|\
value|(v = (c*)safexrealloc((Malloc_t)(v),(MEM_SIZE)((n)*sizeof(t))))
end_define

begin_define
define|#
directive|define
name|Safefree
parameter_list|(
name|d
parameter_list|)
value|safexfree((Malloc_t)(d))
end_define

begin_define
define|#
directive|define
name|MAXXCOUNT
value|1400
end_define

begin_define
define|#
directive|define
name|MAXY_SIZE
value|80
end_define

begin_define
define|#
directive|define
name|MAXYCOUNT
value|16
end_define

begin_comment
comment|/* (MAXY_SIZE/4 + 1) */
end_comment

begin_decl_stmt
specifier|extern
name|long
name|xcount
index|[
name|MAXXCOUNT
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|long
name|lastxcount
index|[
name|MAXXCOUNT
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|long
name|xycount
index|[
name|MAXXCOUNT
index|]
index|[
name|MAXYCOUNT
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|long
name|lastxycount
index|[
name|MAXXCOUNT
index|]
index|[
name|MAXYCOUNT
index|]
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* LEAKTEST */
end_comment

begin_define
define|#
directive|define
name|Move
parameter_list|(
name|s
parameter_list|,
name|d
parameter_list|,
name|n
parameter_list|,
name|t
parameter_list|)
value|(void)memmove((char*)(d),(char*)(s), (n) * sizeof(t))
end_define

begin_define
define|#
directive|define
name|Copy
parameter_list|(
name|s
parameter_list|,
name|d
parameter_list|,
name|n
parameter_list|,
name|t
parameter_list|)
value|(void)memcpy((char*)(d),(char*)(s), (n) * sizeof(t))
end_define

begin_define
define|#
directive|define
name|Zero
parameter_list|(
name|d
parameter_list|,
name|n
parameter_list|,
name|t
parameter_list|)
value|(void)memzero((char*)(d), (n) * sizeof(t))
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* lint */
end_comment

begin_define
define|#
directive|define
name|New
parameter_list|(
name|x
parameter_list|,
name|v
parameter_list|,
name|n
parameter_list|,
name|s
parameter_list|)
value|(v = Null(s *))
end_define

begin_define
define|#
directive|define
name|Newc
parameter_list|(
name|x
parameter_list|,
name|v
parameter_list|,
name|n
parameter_list|,
name|s
parameter_list|,
name|c
parameter_list|)
value|(v = Null(s *))
end_define

begin_define
define|#
directive|define
name|Newz
parameter_list|(
name|x
parameter_list|,
name|v
parameter_list|,
name|n
parameter_list|,
name|s
parameter_list|)
value|(v = Null(s *))
end_define

begin_define
define|#
directive|define
name|Renew
parameter_list|(
name|v
parameter_list|,
name|n
parameter_list|,
name|s
parameter_list|)
value|(v = Null(s *))
end_define

begin_define
define|#
directive|define
name|Move
parameter_list|(
name|s
parameter_list|,
name|d
parameter_list|,
name|n
parameter_list|,
name|t
parameter_list|)
end_define

begin_define
define|#
directive|define
name|Copy
parameter_list|(
name|s
parameter_list|,
name|d
parameter_list|,
name|n
parameter_list|,
name|t
parameter_list|)
end_define

begin_define
define|#
directive|define
name|Zero
parameter_list|(
name|d
parameter_list|,
name|n
parameter_list|,
name|t
parameter_list|)
end_define

begin_define
define|#
directive|define
name|Safefree
parameter_list|(
name|d
parameter_list|)
value|(d) = (d)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* lint */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|USE_STRUCT_COPY
end_ifdef

begin_define
define|#
directive|define
name|StructCopy
parameter_list|(
name|s
parameter_list|,
name|d
parameter_list|,
name|t
parameter_list|)
value|(*((t*)(d)) = *((t*)(s)))
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|StructCopy
parameter_list|(
name|s
parameter_list|,
name|d
parameter_list|,
name|t
parameter_list|)
value|Copy(s,d,1,t)
end_define

begin_endif
endif|#
directive|endif
end_endif

end_unit

