begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Names.h - names and types used by ascmagic in file(1).  * These tokens are here because they can appear anywhere in  * the first HOWMANY bytes, while tokens in /etc/magic must  * appear at fixed offsets into the file. Don't make HOWMANY  * too high unless you have a very fast CPU.  *  * Copyright (c) Ian F. Darwin, 1987.  * Written by Ian F. Darwin.  *  * See LEGAL.NOTICE  *  * $FreeBSD$  */
end_comment

begin_comment
comment|/* these types are used to index the table 'types': keep em in sync! */
end_comment

begin_define
define|#
directive|define
name|L_C
value|0
end_define

begin_comment
comment|/* first and foremost on UNIX */
end_comment

begin_define
define|#
directive|define
name|L_FORT
value|1
end_define

begin_comment
comment|/* the oldest one */
end_comment

begin_define
define|#
directive|define
name|L_MAKE
value|2
end_define

begin_comment
comment|/* Makefiles */
end_comment

begin_define
define|#
directive|define
name|L_PLI
value|3
end_define

begin_comment
comment|/* PL/1 */
end_comment

begin_define
define|#
directive|define
name|L_MACH
value|4
end_define

begin_comment
comment|/* some kinda assembler */
end_comment

begin_define
define|#
directive|define
name|L_ENG
value|5
end_define

begin_comment
comment|/* English */
end_comment

begin_define
define|#
directive|define
name|L_PAS
value|6
end_define

begin_comment
comment|/* Pascal */
end_comment

begin_define
define|#
directive|define
name|L_MAIL
value|7
end_define

begin_comment
comment|/* Electronic mail */
end_comment

begin_define
define|#
directive|define
name|L_NEWS
value|8
end_define

begin_comment
comment|/* Usenet Netnews */
end_comment

begin_decl_stmt
specifier|static
name|char
modifier|*
name|types
index|[]
init|=
block|{
literal|"c program text"
block|,
literal|"fortran program text"
block|,
literal|"make commands text"
block|,
literal|"pl/1 program text"
block|,
literal|"assembler program text"
block|,
literal|"English text"
block|,
literal|"pascal program text"
block|,
literal|"mail text"
block|,
literal|"news text"
block|,
literal|"can't happen error on names.h/types"
block|,
literal|0
block|}
decl_stmt|;
end_decl_stmt

begin_struct
specifier|static
struct|struct
name|names
block|{
name|char
modifier|*
name|name
decl_stmt|;
name|short
name|type
decl_stmt|;
block|}
name|names
index|[]
init|=
block|{
comment|/* These must be sorted by eye for optimal hit rate */
comment|/* Add to this list only after substantial meditation */
block|{
literal|"/*"
block|,
name|L_C
block|}
block|,
comment|/* must preced "The", "the", etc. */
block|{
literal|"#include"
block|,
name|L_C
block|}
block|,
block|{
literal|"char"
block|,
name|L_C
block|}
block|,
block|{
literal|"The"
block|,
name|L_ENG
block|}
block|,
block|{
literal|"the"
block|,
name|L_ENG
block|}
block|,
block|{
literal|"double"
block|,
name|L_C
block|}
block|,
block|{
literal|"extern"
block|,
name|L_C
block|}
block|,
block|{
literal|"float"
block|,
name|L_C
block|}
block|,
block|{
literal|"real"
block|,
name|L_C
block|}
block|,
block|{
literal|"struct"
block|,
name|L_C
block|}
block|,
block|{
literal|"union"
block|,
name|L_C
block|}
block|,
block|{
literal|"CFLAGS"
block|,
name|L_MAKE
block|}
block|,
block|{
literal|"LDFLAGS"
block|,
name|L_MAKE
block|}
block|,
block|{
literal|"all:"
block|,
name|L_MAKE
block|}
block|,
block|{
literal|".PRECIOUS"
block|,
name|L_MAKE
block|}
block|,
comment|/* Too many files of text have these words in them.  Find another way  * to recognize Fortrash.  */
ifdef|#
directive|ifdef
name|NOTDEF
block|{
literal|"subroutine"
block|,
name|L_FORT
block|}
block|,
block|{
literal|"function"
block|,
name|L_FORT
block|}
block|,
block|{
literal|"block"
block|,
name|L_FORT
block|}
block|,
block|{
literal|"common"
block|,
name|L_FORT
block|}
block|,
block|{
literal|"dimension"
block|,
name|L_FORT
block|}
block|,
block|{
literal|"integer"
block|,
name|L_FORT
block|}
block|,
block|{
literal|"data"
block|,
name|L_FORT
block|}
block|,
endif|#
directive|endif
comment|/*NOTDEF*/
block|{
literal|".ascii"
block|,
name|L_MACH
block|}
block|,
block|{
literal|".asciiz"
block|,
name|L_MACH
block|}
block|,
block|{
literal|".byte"
block|,
name|L_MACH
block|}
block|,
block|{
literal|".even"
block|,
name|L_MACH
block|}
block|,
block|{
literal|".globl"
block|,
name|L_MACH
block|}
block|,
block|{
literal|"clr"
block|,
name|L_MACH
block|}
block|,
block|{
literal|"(input,"
block|,
name|L_PAS
block|}
block|,
block|{
literal|"dcl"
block|,
name|L_PLI
block|}
block|,
block|{
literal|"Received:"
block|,
name|L_MAIL
block|}
block|,
block|{
literal|">From"
block|,
name|L_MAIL
block|}
block|,
block|{
literal|"Return-Path:"
block|,
name|L_MAIL
block|}
block|,
block|{
literal|"Cc:"
block|,
name|L_MAIL
block|}
block|,
block|{
literal|"Newsgroups:"
block|,
name|L_NEWS
block|}
block|,
block|{
literal|"Path:"
block|,
name|L_NEWS
block|}
block|,
block|{
literal|"Organization:"
block|,
name|L_NEWS
block|}
block|,
block|{
name|NULL
block|,
literal|0
block|}
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|NNAMES
value|((sizeof(names)/sizeof(struct names)) - 1)
end_define

end_unit

