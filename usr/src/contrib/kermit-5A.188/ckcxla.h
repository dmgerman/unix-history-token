begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*   Author: Frank da Cruz (fdc@columbia.edu, FDCCU@CUVMA.BITNET),   Columbia University Center for Computing Activities.   First released January 1985.   Copyright (C) 1985, 1992, Trustees of Columbia University in the City of New   York.  Permission is granted to any individual or institution to use this   software as long as it is not sold for profit.  This copyright notice must be   retained.  This software may not be included in commercial products without   written permission of Columbia University. */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|CKCXLA_H
end_ifndef

begin_comment
comment|/* Guard against multiple inclusion */
end_comment

begin_define
define|#
directive|define
name|CKCXLA_H
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|NOCSETS
end_ifdef

begin_ifdef
ifdef|#
directive|ifdef
name|KANJI
end_ifdef

begin_undef
undef|#
directive|undef
name|KANJI
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* KANJI */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|CYRILLIC
end_ifdef

begin_undef
undef|#
directive|undef
name|CYRILLIC
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* CYRILLIC */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|LATIN2
end_ifdef

begin_undef
undef|#
directive|undef
name|LATIN2
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* LATIN2 */
end_comment

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* Rest of this file... */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|NOLATIN2
end_ifndef

begin_comment
comment|/* If they didn't say "no Latin-2" */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|LATIN2
end_ifndef

begin_comment
comment|/* Then if LATIN2 isn't already */
end_comment

begin_define
define|#
directive|define
name|LATIN2
end_define

begin_comment
comment|/* defined, define it. */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* LATIN2 */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* NOLATIN2 */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|NOCYRIL
end_ifndef

begin_comment
comment|/* If they didn't say "no Cyrillic" */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|CYRILLIC
end_ifndef

begin_comment
comment|/* Then if CYRILLIC isn't already */
end_comment

begin_define
define|#
directive|define
name|CYRILLIC
end_define

begin_comment
comment|/* defined, define it. */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* CYRILLIC */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* NOCYRIL */
end_comment

begin_comment
comment|/* File ckcxla.h -- Character-set-related definitions, system independent */
end_comment

begin_comment
comment|/* Codes for Kermit Transfer Syntax Level (obsolete) */
end_comment

begin_define
define|#
directive|define
name|TS_L0
value|0
end_define

begin_comment
comment|/* Level 0 (Transparent) */
end_comment

begin_define
define|#
directive|define
name|TS_L1
value|1
end_define

begin_comment
comment|/* Level 1 (one standard character set) */
end_comment

begin_define
define|#
directive|define
name|TS_L2
value|2
end_define

begin_comment
comment|/* Level 2 (multiple character sets in same file) */
end_comment

begin_define
define|#
directive|define
name|UNK
value|63
end_define

begin_comment
comment|/* Symbol to use for unknown character (63 = ?) */
end_comment

begin_comment
comment|/*   Codes for the base alphabet of a given character set.   These are assigned in roughly ISO 8859 order.   (Each is assumed to include ASCII/Roman.) */
end_comment

begin_define
define|#
directive|define
name|AL_UNIV
value|0
end_define

begin_comment
comment|/* Universal (like ISO 10646) */
end_comment

begin_define
define|#
directive|define
name|AL_ROMAN
value|1
end_define

begin_comment
comment|/* Roman (Latin) alphabet */
end_comment

begin_define
define|#
directive|define
name|AL_CYRIL
value|2
end_define

begin_comment
comment|/* Cyrillic alphabet */
end_comment

begin_define
define|#
directive|define
name|AL_ARABIC
value|3
end_define

begin_comment
comment|/* Arabic */
end_comment

begin_define
define|#
directive|define
name|AL_GREEK
value|4
end_define

begin_comment
comment|/* Greek */
end_comment

begin_define
define|#
directive|define
name|AL_HEBREW
value|5
end_define

begin_comment
comment|/* Hebrew */
end_comment

begin_define
define|#
directive|define
name|AL_KANA
value|6
end_define

begin_comment
comment|/* Japanese Katakana */
end_comment

begin_define
define|#
directive|define
name|AL_JAPAN
value|7
end_define

begin_comment
comment|/* Japanese Katakana+Kanji ideograms */
end_comment

begin_define
define|#
directive|define
name|AL_HAN
value|8
end_define

begin_comment
comment|/* Chinese/Japanese/Korean ideograms */
end_comment

begin_define
define|#
directive|define
name|AL_INDIA
value|9
end_define

begin_comment
comment|/* Indian scripts (ISCII) */
end_comment

begin_comment
comment|/* Add more here... */
end_comment

begin_define
define|#
directive|define
name|AL_UNK
value|999
end_define

begin_comment
comment|/* Unknown (transparent) */
end_comment

begin_comment
comment|/* Codes for languages */
end_comment

begin_comment
comment|/*   NOTE: It would perhaps be better to use ISO 639-1988 2-letter "Codes for    Representation of Names of Languages" here, shown in the comments below. */
end_comment

begin_define
define|#
directive|define
name|L_ASCII
value|0
end_define

begin_comment
comment|/* EN ASCII, English */
end_comment

begin_define
define|#
directive|define
name|L_USASCII
value|0
end_define

begin_comment
comment|/* EN ASCII, English */
end_comment

begin_define
define|#
directive|define
name|L_DUTCH
value|1
end_define

begin_comment
comment|/* NL Dutch */
end_comment

begin_define
define|#
directive|define
name|L_FINNISH
value|2
end_define

begin_comment
comment|/* FI Finnish */
end_comment

begin_define
define|#
directive|define
name|L_FRENCH
value|3
end_define

begin_comment
comment|/* FR French */
end_comment

begin_define
define|#
directive|define
name|L_GERMAN
value|4
end_define

begin_comment
comment|/* DE German */
end_comment

begin_define
define|#
directive|define
name|L_HUNGARIAN
value|5
end_define

begin_comment
comment|/* HU Hungarian */
end_comment

begin_define
define|#
directive|define
name|L_ITALIAN
value|6
end_define

begin_comment
comment|/* IT Italian */
end_comment

begin_define
define|#
directive|define
name|L_NORWEGIAN
value|7
end_define

begin_comment
comment|/* NO Norwegian */
end_comment

begin_define
define|#
directive|define
name|L_PORTUGUESE
value|8
end_define

begin_comment
comment|/* PT Portuguese */
end_comment

begin_define
define|#
directive|define
name|L_SPANISH
value|9
end_define

begin_comment
comment|/* ES Spanish */
end_comment

begin_define
define|#
directive|define
name|L_SWEDISH
value|10
end_define

begin_comment
comment|/* SV Swedish */
end_comment

begin_define
define|#
directive|define
name|L_SWISS
value|11
end_define

begin_comment
comment|/* RM Swiss (Rhaeto-Romance) */
end_comment

begin_define
define|#
directive|define
name|L_DANISH
value|12
end_define

begin_comment
comment|/* DA Danish */
end_comment

begin_define
define|#
directive|define
name|L_ICELANDIC
value|13
end_define

begin_comment
comment|/* IS Icelandic */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|CYRILLIC
end_ifdef

begin_comment
comment|/* RU Russian */
end_comment

begin_define
define|#
directive|define
name|L_RUSSIAN
value|14
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|KANJI
end_ifndef

begin_define
define|#
directive|define
name|MAXLANG
value|14
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* KANJI */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* CYRILLIC */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|KANJI
end_ifdef

begin_comment
comment|/* JA Japanese */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|CYRILLIC
end_ifndef

begin_define
define|#
directive|define
name|L_JAPANESE
value|14
end_define

begin_define
define|#
directive|define
name|MAXLANG
value|14
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|L_JAPANESE
value|15
end_define

begin_define
define|#
directive|define
name|MAXLANG
value|15
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* CYRILLIC */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* KANJI */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|MAXLANG
end_ifndef

begin_define
define|#
directive|define
name|MAXLANG
value|14
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* MAXLANG */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|COMMENT
end_ifdef

begin_comment
comment|/*   The ones below are not used yet.  This list needs to be expanded and   organized, and something must be done about the hard coded numbers, because   they will be wrong if CYRILLIC and/or KANJI are deselected.  But we can't do   "#define L_CHINESE L_JAPANESE + 1" because that causes recursion in the   preprocessor. */
end_comment

begin_define
define|#
directive|define
name|L_CHINESE
value|16
end_define

begin_comment
comment|/* ZH */
end_comment

begin_define
define|#
directive|define
name|L_KOREAN
value|17
end_define

begin_comment
comment|/* KO */
end_comment

begin_define
define|#
directive|define
name|L_ARABIC
value|18
end_define

begin_comment
comment|/* AR */
end_comment

begin_define
define|#
directive|define
name|L_HEBREW
value|19
end_define

begin_comment
comment|/* IW */
end_comment

begin_define
define|#
directive|define
name|L_GREEK
value|20
end_define

begin_comment
comment|/* EL */
end_comment

begin_define
define|#
directive|define
name|L_TURKISH
value|21
end_define

begin_comment
comment|/* TR */
end_comment

begin_comment
comment|/* etc... */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* COMMENT */
end_comment

begin_comment
comment|/*   File character-sets are defined in the system-specific ck?xla.h file,   except for the following one, which must be available to all versions: */
end_comment

begin_define
define|#
directive|define
name|FC_TRANSP
value|254
end_define

begin_comment
comment|/* Transparent */
end_comment

begin_comment
comment|/*   Designators for Kermit's transfer character sets.  These are all standard   sets, or based on them.  Symbols must be unique in the first 8 characters,   because some C preprocessors have this limit. */
end_comment

begin_comment
comment|/* LIST1 */
end_comment

begin_define
define|#
directive|define
name|TC_TRANSP
value|0
end_define

begin_comment
comment|/* Transparent, no character translation */
end_comment

begin_define
define|#
directive|define
name|TC_USASCII
value|1
end_define

begin_comment
comment|/* US 7-bit ASCII */
end_comment

begin_define
define|#
directive|define
name|TC_1LATIN
value|2
end_define

begin_comment
comment|/* ISO 8859-1, Latin-1 */
end_comment

begin_define
define|#
directive|define
name|TC_2LATIN
value|3
end_define

begin_comment
comment|/* ISO 8859-2, Latin-2 */
end_comment

begin_define
define|#
directive|define
name|TC_CYRILL
value|4
end_define

begin_comment
comment|/* ISO 8859-5, Latin/Cyrillic */
end_comment

begin_define
define|#
directive|define
name|TC_JEUC
value|5
end_define

begin_comment
comment|/* Japanese EUC */
end_comment

begin_define
define|#
directive|define
name|MAXTCSETS
value|5
end_define

begin_comment
comment|/* Highest Transfer Character Set Number */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|COMMENT
end_ifdef

begin_comment
comment|/*   Not used yet. */
end_comment

begin_define
define|#
directive|define
name|TC_3LATIN
value|6
end_define

begin_comment
comment|/* ISO 8859-3, Latin-3 */
end_comment

begin_define
define|#
directive|define
name|TC_4LATIN
value|7
end_define

begin_comment
comment|/* ISO 8859-4, Latin-4 */
end_comment

begin_define
define|#
directive|define
name|TC_5LATIN
value|8
end_define

begin_comment
comment|/* ISO 8859-9, Latin-5 */
end_comment

begin_define
define|#
directive|define
name|TC_ARABIC
value|9
end_define

begin_comment
comment|/* ISO-8859-6, Latin/Arabic */
end_comment

begin_define
define|#
directive|define
name|TC_GREEK
value|10
end_define

begin_comment
comment|/* ISO-8859-7, Latin/Greek */
end_comment

begin_define
define|#
directive|define
name|TC_HEBREW
value|11
end_define

begin_comment
comment|/* ISO-8859-8, Latin/Hebrew */
end_comment

begin_define
define|#
directive|define
name|TC_JIS208
value|12
end_define

begin_comment
comment|/* Japanese JIS X 0208 multibyte set */
end_comment

begin_define
define|#
directive|define
name|TC_CHINES
value|13
end_define

begin_comment
comment|/* Chinese Standard GB 2312-80 */
end_comment

begin_define
define|#
directive|define
name|TC_KOREAN
value|14
end_define

begin_comment
comment|/* Korean KS C 5601-1987 */
end_comment

begin_define
define|#
directive|define
name|TC_I10646
value|15
end_define

begin_comment
comment|/* ISO DIS 10646 (not defined yet) */
end_comment

begin_comment
comment|/* etc... */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* COMMENT */
end_comment

begin_comment
comment|/* Structure for character-set information */
end_comment

begin_struct
struct|struct
name|csinfo
block|{
name|char
modifier|*
name|name
decl_stmt|;
comment|/* Name of character set */
name|int
name|size
decl_stmt|;
comment|/* Size (128 or 256)     */
name|int
name|code
decl_stmt|;
comment|/* Like TC_1LATIN, etc.  */
name|char
modifier|*
name|designator
decl_stmt|;
comment|/* Designator, like I2/100 = Latin-1 */
name|int
name|alphabet
decl_stmt|;
comment|/* Base alphabet */
block|}
struct|;
end_struct

begin_comment
comment|/* Structure for language information */
end_comment

begin_struct
struct|struct
name|langinfo
block|{
name|int
name|id
decl_stmt|;
comment|/* Language ID code (L_whatever) */
name|int
name|fc
decl_stmt|;
comment|/* File character set to use */
name|int
name|tc
decl_stmt|;
comment|/* Transfer character set to use */
name|char
modifier|*
name|description
decl_stmt|;
comment|/* Description of language */
block|}
struct|;
end_struct

begin_comment
comment|/* Now take in the system-specific definitions */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|UNIX
end_ifdef

begin_include
include|#
directive|include
file|"ckuxla.h"
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* UNIX */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|OSK
end_ifdef

begin_comment
comment|/* OS-9 */
end_comment

begin_include
include|#
directive|include
file|"ckuxla.h"
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* OS-9 */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|VMS
end_ifdef

begin_comment
comment|/* VAX/VMS */
end_comment

begin_include
include|#
directive|include
file|"ckuxla.h"
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* VMS */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|GEMDOS
end_ifdef

begin_comment
comment|/* Atari ST */
end_comment

begin_include
include|#
directive|include
file|"ckuxla.h"
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* GEMDOS */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|MAC
end_ifdef

begin_comment
comment|/* Macintosh */
end_comment

begin_include
include|#
directive|include
file|"ckmxla.h"
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* MAC */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|OS2
end_ifdef

begin_comment
comment|/* OS/2 */
end_comment

begin_include
include|#
directive|include
file|"ckuxla.h"
end_include

begin_comment
comment|/* Uses big UNIX version */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* OS2 */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|AMIGA
end_ifdef

begin_comment
comment|/* Commodore Amiga */
end_comment

begin_include
include|#
directive|include
file|"ckuxla.h"
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* AMIGA */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|datageneral
end_ifdef

begin_comment
comment|/* Data General MV AOS/VS */
end_comment

begin_include
include|#
directive|include
file|"ckuxla.h"
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* datageneral */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* NOCSETS */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* CKCXLA_H */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|KANJI
end_ifdef

begin_macro
name|_PROTOTYP
argument_list|(
argument|int xkanjf
argument_list|,
argument|(void)
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_macro
name|_PROTOTYP
argument_list|(
argument|int xkanjz
argument_list|,
argument|(int (*)(char))
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_macro
name|_PROTOTYP
argument_list|(
argument|int xkanji
argument_list|,
argument|(int, int (*)(char))
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* KANJI */
end_comment

begin_comment
comment|/* End of ckcxla.h */
end_comment

end_unit

