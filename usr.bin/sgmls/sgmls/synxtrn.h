begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* SYNXTRN.H: External declarations for concrete syntax constants. */
end_comment

begin_comment
comment|/* Short References */
end_comment

begin_define
define|#
directive|define
name|SRCT
value|32
end_define

begin_comment
comment|/* Number of short reference delimiters. */
end_comment

begin_define
define|#
directive|define
name|SRMAXLEN
value|3
end_define

begin_comment
comment|/* Maximum length of a SHORTREF delimiter. */
end_comment

begin_define
define|#
directive|define
name|SRNPRT
value|8
end_define

begin_comment
comment|/* Number of non-printable SHORTREF delimiters. */
end_comment

begin_struct
struct|struct
name|srdel
block|{
name|struct
name|map
name|dtb
index|[
name|SRCT
operator|+
literal|2
index|]
decl_stmt|;
comment|/* LEXCNM: Short reference delimiters. */
name|char
modifier|*
name|pdtb
index|[
name|SRNPRT
operator|+
literal|1
index|]
decl_stmt|;
comment|/* LEXCNM: Printable form of unprintable SRs. */
name|int
name|fce
decl_stmt|;
comment|/* LEXCNM: Index of first FCE in srdeltab. */
name|int
name|hyp2
decl_stmt|;
comment|/* LEXCNM: Index of "two hyphens" in srdeltab. */
name|int
name|data
decl_stmt|;
comment|/* LEXCNM: Index of first SR with data char. */
name|int
name|hyp
decl_stmt|;
comment|/* LEXCNM: Index of hyphen in srdeltab. */
name|int
name|prtmin
decl_stmt|;
comment|/* LEXCNM: Index of 1st printable SR. */
name|int
name|spc
decl_stmt|;
comment|/* LEXCNM: Index of space in srdeltab. */
name|int
name|lbr
decl_stmt|;
comment|/* LEXCNM: Index of left bracket in srdeltab. */
name|int
name|rbr
decl_stmt|;
comment|/* LEXCNM: Index of right bracket in srdeltab. */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|delim
block|{
name|UNCH
name|genre
decl_stmt|;
comment|/* LEXCON: Generated RE; cannot be markup. */
name|UNCH
name|lit
decl_stmt|;
comment|/* LEXMARK: Char used as LIT delimiter.*/
name|UNCH
name|lita
decl_stmt|;
comment|/* LEXMARK: Char used as LITA delimiter.*/
name|UNCH
name|mdc
decl_stmt|;
comment|/* LEXLMS: Char used as MDC delimiter.*/
name|UNCH
name|msc
decl_stmt|;
comment|/* LEXCON: Char used as MSC delimiter. */
name|UNCH
name|net
decl_stmt|;
comment|/* LEXCON: Char used as NET when enabled.*/
name|UNCH
name|pero
decl_stmt|;
comment|/* LEXMARK: Char used as PERO delimiter. */
name|UNCH
name|pic
decl_stmt|;
comment|/* LEXCON: Char used as PIC delimiter.*/
name|UNCH
name|tago
decl_stmt|;
comment|/* LEXCON: Char used as TAGO when enabled.*/
block|}
struct|;
end_struct

begin_struct
struct|struct
name|lexcode
block|{
name|UNCH
name|fce
decl_stmt|;
comment|/* LEXCNM: FRE character as entity reference. */
name|UNCH
name|fre
decl_stmt|;
comment|/* LEXCON: Free character not an entity ref. */
name|UNCH
name|litc
decl_stmt|;
comment|/* LEXLMS: Literal close delimiter enabled. */
name|UNCH
name|minlitc
decl_stmt|;
comment|/* LEXMIN: Literal close delimiter enabled. */
name|UNCH
name|msc
decl_stmt|;
comment|/* LEXLMS: Marked section close delim enabled. */
name|UNCH
name|net
decl_stmt|;
comment|/* LEXCON: Null end-tag delimiter enabled. */
name|UNCH
name|nonet
decl_stmt|;
comment|/* LEXCON: NET disabled; still used as ETI. */
name|UNCH
name|spcr
decl_stmt|;
comment|/* LEXCNM: Space in use as SHORTREF delimiter. */
name|UNCH
name|tago
decl_stmt|;
comment|/* LEXCON: Tag open delimiter enabled. */
name|UNCH
name|cde
decl_stmt|;
comment|/* LEXLMS: CDATA/SDATA delimiters. */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|lexical
block|{
name|struct
name|markup
name|m
decl_stmt|;
comment|/* Markup strings for text processor. */
name|struct
name|srdel
name|s
decl_stmt|;
comment|/* Short reference delimiters. */
name|struct
name|delim
name|d
decl_stmt|;
comment|/* General delimiter characters. */
name|struct
name|lexcode
name|l
decl_stmt|;
comment|/* Lexical table code assignments. */
block|}
struct|;
end_struct

begin_decl_stmt
specifier|extern
name|struct
name|lexical
name|lex
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Delimiter set constants. */
end_comment

begin_decl_stmt
specifier|extern
name|UNCH
name|lexcnm
index|[]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Lexical table: mixed content. */
end_comment

begin_decl_stmt
specifier|extern
name|UNCH
name|lexcon
index|[]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Lexical table for content (except mixed). */
end_comment

begin_decl_stmt
specifier|extern
name|UNCH
name|lexgrp
index|[]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Lexical table for groups. */
end_comment

begin_decl_stmt
specifier|extern
name|UNCH
name|lexlms
index|[]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Lexical table: literals and marked sections. */
end_comment

begin_decl_stmt
specifier|extern
name|UNCH
name|lexmin
index|[]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Lexical table: minimum data literal. */
end_comment

begin_decl_stmt
specifier|extern
name|UNCH
name|lexmark
index|[]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Lexical table for markup. */
end_comment

begin_decl_stmt
specifier|extern
name|UNCH
name|lexsd
index|[]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Lexical table for SGML declaration. */
end_comment

begin_decl_stmt
specifier|extern
name|UNCH
name|lextran
index|[]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Case translation table for SGML names. */
end_comment

begin_decl_stmt
specifier|extern
name|UNCH
name|lextoke
index|[]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Lexical table for tokenization. */
end_comment

begin_decl_stmt
specifier|extern
name|UNCH
modifier|*
name|lextabs
index|[]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* List of all lexical tables. */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|parse
name|pcbconc
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* PCB: character data. */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|parse
name|pcbcone
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* PCB: element content (no data allowed). */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|parse
name|pcbconm
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* PCB: mixed content (data allowed). */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|parse
name|pcbconr
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* PCB: replaceable character data. */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|parse
name|pcbetag
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* PCB: end-tags. */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|parse
name|pcbgrcm
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* PCB: content model group. */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|parse
name|pcbgrcs
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* PCB: content model suffix. */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|parse
name|pcbgrnm
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* PCB: name group. */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|parse
name|pcbgrnt
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* PCB: name token group. */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|parse
name|pcblitc
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* PCB: literal with CDATA. */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|parse
name|pcblitp
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* PCB: literal with CDATA, parm& char refs. */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|parse
name|pcblitr
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* PCB: attribute value with general refs. */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|parse
name|pcblitt
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* PCB: tokenized attribute value. */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|parse
name|pcblitv
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* PCB: literal with CDATA, function char trans.*/
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|parse
name|pcbmd
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* PCB: markup declaration. */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|parse
name|pcbmdc
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* PCB: comment declaration. */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|parse
name|pcbmdi
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* PCB: markup declaration (ignored). */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|parse
name|pcbmds
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* PCB: markup declaration subset. */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|parse
name|pcbmsc
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* PCB: marked section in CDATA mode. */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|parse
name|pcbmsi
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* PCB: marked section in IGNORE mode. */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|parse
name|pcbmsrc
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* PCB: marked section in RCDATA mode. */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|parse
name|pcbpro
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* PCB: prolog. */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|parse
name|pcbref
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* PCB: reference. */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|parse
name|pcbstag
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* PCB: start-tag. */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|parse
name|pcbval
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* PCB: attribute value. */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|parse
name|pcbeal
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* PCB: end of attribute list. */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|parse
name|pcbsd
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* PCB: SGML declaration. */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|pcbcnda
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* PCBCONM: data in buffer. */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|pcbcnet
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* PCBCONM: markup found or data buffer flushed.*/
end_comment

begin_decl_stmt
specifier|extern
name|int
name|pcbmdtk
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* PCBMD: token expected. */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|pcbstan
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* PCBSTAG: attribute name expected. */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|pcblittda
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* PCBLITT: data character found */
end_comment

begin_define
define|#
directive|define
name|KANY
value|0
end_define

begin_define
define|#
directive|define
name|KATTLIST
value|1
end_define

begin_define
define|#
directive|define
name|KCDATA
value|2
end_define

begin_define
define|#
directive|define
name|KCONREF
value|3
end_define

begin_define
define|#
directive|define
name|KCURRENT
value|4
end_define

begin_define
define|#
directive|define
name|KDEFAULT
value|5
end_define

begin_define
define|#
directive|define
name|KDOCTYPE
value|6
end_define

begin_define
define|#
directive|define
name|KELEMENT
value|7
end_define

begin_define
define|#
directive|define
name|KEMPTY
value|8
end_define

begin_define
define|#
directive|define
name|KENDTAG
value|9
end_define

begin_define
define|#
directive|define
name|KENTITIES
value|10
end_define

begin_define
define|#
directive|define
name|KENTITY
value|11
end_define

begin_define
define|#
directive|define
name|KFIXED
value|12
end_define

begin_define
define|#
directive|define
name|KID
value|13
end_define

begin_define
define|#
directive|define
name|KIDLINK
value|14
end_define

begin_define
define|#
directive|define
name|KIDREF
value|15
end_define

begin_define
define|#
directive|define
name|KIDREFS
value|16
end_define

begin_define
define|#
directive|define
name|KIGNORE
value|17
end_define

begin_define
define|#
directive|define
name|KIMPLIED
value|18
end_define

begin_define
define|#
directive|define
name|KINCLUDE
value|19
end_define

begin_define
define|#
directive|define
name|KINITIAL
value|20
end_define

begin_define
define|#
directive|define
name|KLINK
value|21
end_define

begin_define
define|#
directive|define
name|KLINKTYPE
value|22
end_define

begin_define
define|#
directive|define
name|KMD
value|23
end_define

begin_define
define|#
directive|define
name|KMS
value|24
end_define

begin_define
define|#
directive|define
name|KNAME
value|25
end_define

begin_define
define|#
directive|define
name|KNAMES
value|26
end_define

begin_define
define|#
directive|define
name|KNDATA
value|27
end_define

begin_define
define|#
directive|define
name|KNMTOKEN
value|28
end_define

begin_define
define|#
directive|define
name|KNMTOKENS
value|29
end_define

begin_define
define|#
directive|define
name|KNOTATION
value|30
end_define

begin_define
define|#
directive|define
name|KNUMBER
value|31
end_define

begin_define
define|#
directive|define
name|KNUMBERS
value|32
end_define

begin_define
define|#
directive|define
name|KNUTOKEN
value|33
end_define

begin_define
define|#
directive|define
name|KNUTOKENS
value|34
end_define

begin_define
define|#
directive|define
name|KO
value|35
end_define

begin_define
define|#
directive|define
name|KPCDATA
value|36
end_define

begin_define
define|#
directive|define
name|KPI
value|37
end_define

begin_define
define|#
directive|define
name|KPOSTLINK
value|38
end_define

begin_define
define|#
directive|define
name|KPUBLIC
value|39
end_define

begin_define
define|#
directive|define
name|KRCDATA
value|40
end_define

begin_define
define|#
directive|define
name|KRE
value|41
end_define

begin_define
define|#
directive|define
name|KREQUIRED
value|42
end_define

begin_define
define|#
directive|define
name|KRESTORE
value|43
end_define

begin_define
define|#
directive|define
name|KRS
value|44
end_define

begin_define
define|#
directive|define
name|KSDATA
value|45
end_define

begin_define
define|#
directive|define
name|KSHORTREF
value|46
end_define

begin_define
define|#
directive|define
name|KSIMPLE
value|47
end_define

begin_define
define|#
directive|define
name|KSPACE
value|48
end_define

begin_define
define|#
directive|define
name|KSTARTTAG
value|49
end_define

begin_define
define|#
directive|define
name|KSUBDOC
value|50
end_define

begin_define
define|#
directive|define
name|KSYSTEM
value|51
end_define

begin_define
define|#
directive|define
name|KTEMP
value|52
end_define

begin_define
define|#
directive|define
name|KUSELINK
value|53
end_define

begin_define
define|#
directive|define
name|KUSEMAP
value|54
end_define

begin_define
define|#
directive|define
name|NKEYS
value|(KUSEMAP+1)
end_define

begin_decl_stmt
specifier|extern
name|UNCH
name|key
index|[
name|NKEYS
index|]
index|[
name|REFNAMELEN
operator|+
literal|1
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Holds the SGML keyword (not alterable by concrete syntax). */
end_comment

begin_decl_stmt
specifier|extern
name|UNCH
name|sgmlkey
index|[]
decl_stmt|;
end_decl_stmt

end_unit

