begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* TOOLS.H: Definitions for type declarations, printing, bit handling, etc. */
end_comment

begin_if
if|#
directive|if
name|CHAR_SIGNED
end_if

begin_typedef
typedef|typedef
name|unsigned
name|char
name|UNCH
typedef|;
end_typedef

begin_else
else|#
directive|else
end_else

begin_typedef
typedef|typedef
name|char
name|UNCH
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|CHAR_SIGNED
end_if

begin_define
define|#
directive|define
name|ustrcmp
parameter_list|(
name|s1
parameter_list|,
name|s2
parameter_list|)
value|strcmp((char *)(s1), (char *)(s2))
end_define

begin_define
define|#
directive|define
name|ustrcpy
parameter_list|(
name|s1
parameter_list|,
name|s2
parameter_list|)
value|strcpy((char *)(s1), (char *)(s2))
end_define

begin_define
define|#
directive|define
name|ustrchr
parameter_list|(
name|s
parameter_list|,
name|c
parameter_list|)
value|(UNCH *)strchr((char *)(s), c)
end_define

begin_define
define|#
directive|define
name|ustrncmp
parameter_list|(
name|s1
parameter_list|,
name|s2
parameter_list|,
name|n
parameter_list|)
value|strncmp((char *)(s1), (char *)(s2), n)
end_define

begin_define
define|#
directive|define
name|ustrncpy
parameter_list|(
name|s1
parameter_list|,
name|s2
parameter_list|,
name|n
parameter_list|)
value|strncpy((char *)(s1), (char *)(s2), n)
end_define

begin_define
define|#
directive|define
name|ustrlen
parameter_list|(
name|s1
parameter_list|)
value|strlen((char *)(s1))
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|ustrcmp
value|strcmp
end_define

begin_define
define|#
directive|define
name|ustrcpy
value|strcpy
end_define

begin_define
define|#
directive|define
name|ustrchr
value|strchr
end_define

begin_define
define|#
directive|define
name|ustrncmp
value|strncmp
end_define

begin_define
define|#
directive|define
name|ustrncpy
value|strncpy
end_define

begin_define
define|#
directive|define
name|ustrlen
value|strlen
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
literal|0
end_if

begin_endif
unit|int ustrcmp(UNCH *, UNCH *); UNCH *ustrchr(UNCH *, int); int ustrncmp(UNCH *, UNCH *, UNS); int ustrncpy(UNCH *, UNCH *, UNS); int ustrlen(UNCH *);
endif|#
directive|endif
end_endif

begin_typedef
typedef|typedef
name|unsigned
name|UNS
typedef|;
end_typedef

begin_ifdef
ifdef|#
directive|ifdef
name|USE_ISASCII
end_ifdef

begin_define
define|#
directive|define
name|ISASCII
parameter_list|(
name|c
parameter_list|)
value|isascii(c)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|ISASCII
parameter_list|(
name|c
parameter_list|)
value|(1)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|BSD_STRINGS
end_ifdef

begin_define
define|#
directive|define
name|MEMZERO
parameter_list|(
name|s
parameter_list|,
name|n
parameter_list|)
value|bzero(s, n)
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* not BSD_STRINGS */
end_comment

begin_define
define|#
directive|define
name|MEMZERO
parameter_list|(
name|s
parameter_list|,
name|n
parameter_list|)
value|memset(s, '\0', n)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* not BSD_STRINGS */
end_comment

begin_comment
comment|/* Macros for bit manipulation. */
end_comment

begin_define
define|#
directive|define
name|SET
parameter_list|(
name|word
parameter_list|,
name|bits
parameter_list|)
value|((word) |= (bits))
end_define

begin_comment
comment|/* Turn bits on */
end_comment

begin_define
define|#
directive|define
name|RESET
parameter_list|(
name|word
parameter_list|,
name|bits
parameter_list|)
value|((word)&= ~(bits))
end_define

begin_comment
comment|/* Turn bits off */
end_comment

begin_define
define|#
directive|define
name|GET
parameter_list|(
name|word
parameter_list|,
name|bits
parameter_list|)
value|((word)& (bits))
end_define

begin_comment
comment|/* 1=any bit on */
end_comment

begin_define
define|#
directive|define
name|BITOFF
parameter_list|(
name|word
parameter_list|,
name|bits
parameter_list|)
value|(GET(word, bits)==0)
end_define

begin_comment
comment|/* 1=no bits on */
end_comment

begin_define
define|#
directive|define
name|BITON
parameter_list|(
name|word
parameter_list|,
name|bits
parameter_list|)
value|((word)& (bits))
end_define

begin_comment
comment|/* 1=any bit on */
end_comment

begin_define
define|#
directive|define
name|ETDCDATA
value|(dumetd)
end_define

begin_comment
comment|/* Dummy etd pointer for #PCDATA. */
end_comment

begin_define
define|#
directive|define
name|ETDNULL
value|(dumetd + 1)
end_define

begin_comment
comment|/* Dummy etd pointer for null tag. */
end_comment

begin_define
define|#
directive|define
name|ETDNET
value|(dumetd + 2)
end_define

begin_comment
comment|/* Dummy etd pointer for NET delimiter. */
end_comment

begin_define
define|#
directive|define
name|BADPTR
parameter_list|(
name|p
parameter_list|)
define|\
value|((p) == NULL || (p) == ETDCDATA || (p) == ETDNULL || (p) == ETDNET)
end_define

begin_define
define|#
directive|define
name|PTRNUM
parameter_list|(
name|p
parameter_list|)
value|((p) == NULL ? 0 : ((p) - dumetd) + 1)
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|USE_PROTOTYPES
end_ifdef

begin_define
define|#
directive|define
name|P
parameter_list|(
name|parms
parameter_list|)
value|parms
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|P
parameter_list|(
name|parms
parameter_list|)
value|()
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* VP is used for prototypes of varargs functions.  You can't have a prototype if the function is defined using varargs.h rather than stdarg.h. */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|VARARGS
end_ifdef

begin_define
define|#
directive|define
name|VP
parameter_list|(
name|parms
parameter_list|)
value|()
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|VP
parameter_list|(
name|parms
parameter_list|)
value|P(parms)
end_define

begin_endif
endif|#
directive|endif
end_endif

end_unit

