begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*    handy.h  *  *    Copyright (c) 1991-1999, Larry Wall  *  *    You may distribute under the terms of either the GNU General Public  *    License or the Artistic License, as specified in the README file.  *  */
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
comment|/* bool is built-in for g++-2.6.3, which might be used for an extension.    If the extension includes<_G_config.h> before this file then    _G_HAVE_BOOL will be properly set.  If, however, the extension includes    this file first, then you will have to manually set -DHAS_BOOL in     your command line to avoid a conflict. */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|_G_HAVE_BOOL
end_ifdef

begin_if
if|#
directive|if
name|_G_HAVE_BOOL
end_if

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

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* The NeXT dynamic loader headers will not build with the bool macro    So declare them now to clear confusion. */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|NeXT
end_ifdef

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
comment|/* NeXT */
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

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* XXX A note on the perl source internal type system.  The    original intent was that I32 be *exactly* 32 bits.     Currently, we only guarantee that I32 is *at least* 32 bits.    Specifically, if int is 64 bits, then so is I32.  (This is the case    for the Cray.)  This has the advantage of meshing nicely with    standard library calls (where we pass an I32 and the library is    expecting an int), but the disadvantage that an I32 is not 32 bits.    Andy Dougherty	August 1996     There is no guarantee that there is *any* integral type with    exactly 32 bits.  It is perfectly legal for a system to have    sizeof(short) == sizeof(int) == sizeof(long) == 8.     Similarly, there is no guarantee that I16 and U16 have exactly 16    bits.     For dealing with issues that may arise from various 32/64-bit     systems, we will ask Configure to check out     	SHORTSIZE == sizeof(short)    	INTSIZE == sizeof(int)    	LONGSIZE == sizeof(long) 	LONGLONGSIZE == sizeof(long long) (if HAS_LONG_LONG)    	PTRSIZE == sizeof(void *) 	DOUBLESIZE == sizeof(double) 	LONG_DOUBLESIZE == sizeof(long double) (if HAS_LONG_DOUBLE).     Most of these are currently unused, but they are mentioned here so     metaconfig will include the appropriate tests in Configure and     we can then start to consider how best to deal with long long     variables.    Andy Dougherty	April 1998 */
end_comment

begin_typedef
typedef|typedef
name|char
name|I8
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|unsigned
name|char
name|U8
typedef|;
end_typedef

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

begin_typedef
typedef|typedef
name|short
name|I16
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|unsigned
name|short
name|U16
typedef|;
end_typedef

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

begin_typedef
typedef|typedef
name|int
name|I32
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|unsigned
name|int
name|U32
typedef|;
end_typedef

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

begin_typedef
typedef|typedef
name|long
name|I32
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|unsigned
name|long
name|U32
typedef|;
end_typedef

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
name|isPRINT
parameter_list|(
name|c
parameter_list|)
value|isprint(c)
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
name|isPRINT
parameter_list|(
name|c
parameter_list|)
value|(((c)> 32&& (c)< 127) || isSPACE(c))
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
value|(NXIsAlpha((unsigned int)(c)) || NXIsDigit((unsigned int)(c)) || \ 	 (char)(c) == '_')
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
name|isPRINT_LC
parameter_list|(
name|c
parameter_list|)
value|NXIsPrint((unsigned int)(c))
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
define|\
value|(isalpha((unsigned char)(c)) || \ 	 isdigit((unsigned char)(c)) || (char)(c) == '_')
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
name|isPRINT_LC
parameter_list|(
name|c
parameter_list|)
value|isprint((unsigned char)(c))
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
define|\
value|(isascii(c)&& (isalpha(c) || isdigit(c) || (c) == '_'))
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
name|isPRINT_LC
parameter_list|(
name|c
parameter_list|)
value|(isascii(c)&& isprint(c))
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

begin_ifdef
ifdef|#
directive|ifdef
name|EBCDIC
end_ifdef

begin_decl_stmt
name|EXT
name|int
name|ebcdic_control
name|_
argument_list|(
operator|(
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|toCTRL
parameter_list|(
name|c
parameter_list|)
value|ebcdic_control(c)
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
comment|/* This looks obsolete (IZ):     XXX LEAKTEST doesn't really work in perl5.  There are direct calls to    safemalloc() in the source, so LEAKTEST won't pick them up.    Further, if you try LEAKTEST, you'll also end up calling    Safefree, which might call safexfree() on some things that weren't    malloced with safexmalloc.  The correct "fix" to this, if anyone    is interested, is to ensure that all calls go through the New and    Renew macros. 	--Andy Dougherty		August 1996 */
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

