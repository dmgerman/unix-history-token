begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* LEXRF: Lexical tables for reference concrete syntax. */
end_comment

begin_include
include|#
directive|include
file|"config.h"
end_include

begin_include
include|#
directive|include
file|"entity.h"
end_include

begin_comment
comment|/* Templates for entity control blocks. */
end_comment

begin_include
include|#
directive|include
file|"synxtrn.h"
end_include

begin_comment
comment|/* Declarations for concrete syntax constants. */
end_comment

begin_include
include|#
directive|include
file|"action.h"
end_include

begin_comment
comment|/* Action names for all parsing. */
end_comment

begin_include
include|#
directive|include
file|"lexcode.h"
end_include

begin_decl_stmt
specifier|static
name|UNCH
name|SRTAB
index|[]
init|=
block|{
name|TABCHAR
block|,
literal|'\0'
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|UNCH
name|SRRE
index|[]
init|=
block|{
name|RECHAR
block|,
literal|'\0'
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|UNCH
name|SRRS
index|[]
init|=
block|{
name|RSCHAR
block|,
literal|'\0'
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|UNCH
name|SRRSB
index|[]
init|=
block|{
name|RSCHAR
block|,
literal|'B'
block|,
literal|'\0'
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|UNCH
name|SRRSRE
index|[]
init|=
block|{
name|RSCHAR
block|,
name|RECHAR
block|,
literal|'\0'
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|UNCH
name|SRRSBRE
index|[]
init|=
block|{
name|RSCHAR
block|,
literal|'B'
block|,
name|RECHAR
block|,
literal|'\0'
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|UNCH
name|SRBRE
index|[]
init|=
block|{
literal|'B'
block|,
name|RECHAR
block|,
literal|'\0'
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|lexical
name|lex
init|=
block|{
comment|/* Delimiter set constants for parser use. */
block|{
comment|/* Markup strings for text processor use. */
operator|(
name|UNCH
operator|*
operator|)
literal|"\4&#"
block|,
comment|/* LEXCON markup string: CRO        */
operator|(
name|UNCH
operator|*
operator|)
literal|"["
block|,
comment|/* LEXCON markup string: DSO        */
operator|(
name|UNCH
operator|*
operator|)
literal|"\3&"
block|,
comment|/* LEXCON markup string: ERO        */
operator|(
name|UNCH
operator|*
operator|)
literal|"\4</"
block|,
comment|/* LEXMARK markup string: end-tag   */
operator|(
name|UNCH
operator|*
operator|)
literal|"\3\""
block|,
comment|/* LEXMARK markup string: LIT       */
operator|(
name|UNCH
operator|*
operator|)
literal|"\3'"
block|,
comment|/* LEXMARK markup string: LITA      */
operator|(
name|UNCH
operator|*
operator|)
literal|"\3>"
block|,
comment|/* LEXCON markup string: MDC        */
operator|(
name|UNCH
operator|*
operator|)
literal|"\4<!"
block|,
comment|/* LEXCON markup string: MDO        */
operator|(
name|UNCH
operator|*
operator|)
literal|"\5]]>"
block|,
comment|/* LEXCON markup string: mse        */
operator|(
name|UNCH
operator|*
operator|)
literal|"\5<!["
block|,
comment|/* LEXCON markup string: mss        */
operator|(
name|UNCH
operator|*
operator|)
literal|"\13<![CDATA["
block|,
comment|/* LEXCON markup string: mss CDATA  */
operator|(
name|UNCH
operator|*
operator|)
literal|"\14<![RCDATA["
block|,
comment|/* LEXCON markup string: mss RCDATA */
operator|(
name|UNCH
operator|*
operator|)
literal|"\3>"
block|,
comment|/* LEXCON markup string: PIC        */
operator|(
name|UNCH
operator|*
operator|)
literal|"\4<?"
block|,
comment|/* LEXCON markup string: PIO        */
operator|(
name|UNCH
operator|*
operator|)
literal|"\3;"
block|,
comment|/* LEXGRP markup string: ref close. */
operator|(
name|UNCH
operator|*
operator|)
literal|"\3<"
block|,
comment|/* LEXMARK markup string: start-tag */
operator|(
name|UNCH
operator|*
operator|)
literal|"\3>"
block|,
comment|/* LEXMARK markup string: TAGC      */
operator|(
name|UNCH
operator|*
operator|)
literal|"\3="
block|,
comment|/* LEXMARK markup string: VI        */
literal|3
block|,
comment|/* LEXMARK: length of null end-tag. */
literal|2
comment|/* LEXMARK: length of null start-tag. */
block|}
block|,
block|{
comment|/* Short reference delimiters. */
block|{
comment|/* Short reference delimiter table. */
block|{
operator|(
name|UNCH
operator|*
operator|)
literal|""
block|,
name|SRCT
block|}
block|,
comment|/* Dummy entry to store SR count. */
block|{
name|SRTAB
block|,
literal|1
block|}
block|,
comment|/* TAB */
block|{
name|SRRE
block|,
literal|2
block|}
block|,
comment|/* RE */
block|{
name|SRRS
block|,
literal|3
block|}
block|,
comment|/* RS */
block|{
name|SRRSB
block|,
literal|4
block|}
block|,
comment|/* Leading blanks */
block|{
name|SRRSRE
block|,
literal|5
block|}
block|,
comment|/* Null record */
block|{
name|SRRSBRE
block|,
literal|6
block|}
block|,
comment|/* Blank record */
block|{
name|SRBRE
block|,
literal|7
block|}
block|,
comment|/* Trailing blanks */
block|{
operator|(
name|UNCH
operator|*
operator|)
literal|" "
block|,
literal|8
block|}
block|,
comment|/* Space */
block|{
operator|(
name|UNCH
operator|*
operator|)
literal|"BB"
block|,
literal|9
block|}
block|,
comment|/* Two or more blanks */
block|{
operator|(
name|UNCH
operator|*
operator|)
literal|"\""
block|,
literal|10
block|}
block|,
comment|/* Quotation mark (first data character) */
block|{
operator|(
name|UNCH
operator|*
operator|)
literal|"#"
block|,
literal|11
block|}
block|,
comment|/* Number sign */
block|{
operator|(
name|UNCH
operator|*
operator|)
literal|"%"
block|,
literal|12
block|}
block|,
comment|/* FCE CHARACTERS start here */
block|{
operator|(
name|UNCH
operator|*
operator|)
literal|"'"
block|,
literal|13
block|}
block|,
block|{
operator|(
name|UNCH
operator|*
operator|)
literal|"("
block|,
literal|14
block|}
block|,
block|{
operator|(
name|UNCH
operator|*
operator|)
literal|")"
block|,
literal|15
block|}
block|,
block|{
operator|(
name|UNCH
operator|*
operator|)
literal|"*"
block|,
literal|16
block|}
block|,
block|{
operator|(
name|UNCH
operator|*
operator|)
literal|"+"
block|,
literal|17
block|}
block|,
block|{
operator|(
name|UNCH
operator|*
operator|)
literal|","
block|,
literal|18
block|}
block|,
block|{
operator|(
name|UNCH
operator|*
operator|)
literal|"-"
block|,
literal|19
block|}
block|,
comment|/* Hyphen */
block|{
operator|(
name|UNCH
operator|*
operator|)
literal|"--"
block|,
literal|20
block|}
block|,
comment|/* Two hyphens */
block|{
operator|(
name|UNCH
operator|*
operator|)
literal|":"
block|,
literal|21
block|}
block|,
block|{
operator|(
name|UNCH
operator|*
operator|)
literal|";"
block|,
literal|22
block|}
block|,
block|{
operator|(
name|UNCH
operator|*
operator|)
literal|"="
block|,
literal|23
block|}
block|,
block|{
operator|(
name|UNCH
operator|*
operator|)
literal|"@"
block|,
literal|24
block|}
block|,
block|{
operator|(
name|UNCH
operator|*
operator|)
literal|"["
block|,
literal|25
block|}
block|,
block|{
operator|(
name|UNCH
operator|*
operator|)
literal|"]"
block|,
literal|26
block|}
block|,
block|{
operator|(
name|UNCH
operator|*
operator|)
literal|"^"
block|,
literal|27
block|}
block|,
block|{
operator|(
name|UNCH
operator|*
operator|)
literal|"_"
block|,
literal|28
block|}
block|,
comment|/* Low line */
block|{
operator|(
name|UNCH
operator|*
operator|)
literal|"{"
block|,
literal|29
block|}
block|,
block|{
operator|(
name|UNCH
operator|*
operator|)
literal|"|"
block|,
literal|30
block|}
block|,
block|{
operator|(
name|UNCH
operator|*
operator|)
literal|"}"
block|,
literal|31
block|}
block|,
block|{
operator|(
name|UNCH
operator|*
operator|)
literal|"~"
block|,
literal|32
block|}
block|,
block|{
literal|0
block|,
literal|0
block|}
block|}
block|,
block|{
comment|/* Printable form of unprintable SR delims.*/
literal|""
block|,
comment|/* Dummy entry to balance s.dtb. */
literal|"&#TAB;"
block|,
comment|/* TAB */
literal|"&#RE;"
block|,
comment|/* RE */
literal|"&#RS;"
block|,
comment|/* RS */
literal|"&#RS;B"
block|,
comment|/* Leading blanks */
literal|"&#RS;&#RE;"
block|,
comment|/* Null record */
literal|"&#RS;B&#RE;"
block|,
comment|/* Blank record */
literal|"B&#RE;"
block|,
comment|/* Trailing blanks */
literal|"&#SPACE;"
comment|/* Space */
block|}
block|,
literal|12
block|,
comment|/* LEXCNM: Index of first FCE in srdeltab. */
literal|20
block|,
comment|/*LEXCNM:Index of "two hyphens" in srdeltab*/
literal|10
block|,
comment|/* LEXCNM: Index of first SR with data char. */
literal|19
block|,
comment|/* LEXCNM: Index of hyphen in srdeltab. */
name|SRNPRT
operator|+
literal|1
block|,
comment|/* LEXCNM: Index of 1st printable SR. */
literal|8
block|,
comment|/* LEXCNM: Index of space in srdeltab. */
literal|25
block|,
comment|/* LEXCNM: Index of left bracket in srdeltab. */
literal|26
block|,
comment|/* LEXCNM: Index of right bracket in srdeltab. */
block|}
block|,
comment|/* End of short reference delimiters. */
block|{
comment|/* General delimiter characters. */
name|GENRECHAR
block|,
comment|/*LEXCNM:(BS)Generated RE; can't be markup.*/
literal|'"'
block|,
comment|/* LEXMARK: Char used as LIT delimiter.*/
literal|'\''
block|,
comment|/* LEXMARK: Char used as LITA delimiter.*/
literal|'>'
block|,
comment|/* LEXLMS: Char used as MDC delimiter.*/
literal|']'
block|,
comment|/* LEXLMS: Char used as MSC when enabled.*/
literal|'/'
block|,
comment|/* LEXCON: Char used as NET when enabled.*/
literal|'%'
block|,
comment|/* LEXMARK: Char used as PERO delimiter. */
literal|'>'
block|,
comment|/* LEXCON: Char used as PIC delimiter.*/
literal|'<'
comment|/* LEXCON: Char used as TAGO when enabled.*/
block|}
block|,
block|{
comment|/* Lexical table code assignments. */
name|FCE
block|,
comment|/* LEXCNM: FRE char as entity reference.*/
name|FRE
block|,
comment|/* LEXLMS: Free character not an entity ref.*/
name|LITC
block|,
comment|/* LEXLMS: Literal close delimiter enabled. */
name|MINLITC
block|,
comment|/* LEXMIN: Literal close delimiter enabled. */
name|MSC3
block|,
comment|/* LEXLMS: Marked section close delim enabled. */
name|NET
block|,
comment|/* LEXCON: Null end-tag delimiter enabled. */
name|ETI
block|,
comment|/* LEXCON: NET disabled; still used as ETI. */
name|SPCR
block|,
comment|/* LEXCNM: Space in use as SHORTREF delim. */
name|TGO2
block|,
comment|/* LEXCON: Tag open delimiter enabled. */
name|CDE
comment|/* LEXLMS: CDATA/SDATA delimiters. */
block|}
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|UNCH
modifier|*
name|lextabs
index|[]
init|=
block|{
name|lexcnm
block|,
name|lexcon
block|,
name|lexgrp
block|,
name|lexlms
block|,
name|lexmark
block|,
name|lexsd
block|,
name|lextoke
block|,
name|lexmin
block|,
literal|0
block|}
decl_stmt|;
end_decl_stmt

end_unit

