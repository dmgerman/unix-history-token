begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Names.h - names and types used by ascmagic in file(1).  * These tokens are here because they can appear anywhere in  * the first HOWMANY bytes, while tokens in /etc/magic must  * appear at fixed offsets into the file. Don't make HOWMANY  * too high unless you have a very fast CPU.  *  * Copyright (c) Ian F. Darwin, 1987.  * Written by Ian F. Darwin.  *  * See LEGAL.NOTICE  *  * $Id: names.h,v 1.18 2000/08/05 17:36:49 christos Exp $  */
end_comment

begin_comment
comment|/* 	modified by Chris Lowth - 9 April 2000 	to add mime type strings to the types table. */
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
name|L_CC
value|1
end_define

begin_comment
comment|/* Bjarne's postincrement */
end_comment

begin_define
define|#
directive|define
name|L_FORT
value|2
end_define

begin_comment
comment|/* the oldest one */
end_comment

begin_define
define|#
directive|define
name|L_MAKE
value|3
end_define

begin_comment
comment|/* Makefiles */
end_comment

begin_define
define|#
directive|define
name|L_PLI
value|4
end_define

begin_comment
comment|/* PL/1 */
end_comment

begin_define
define|#
directive|define
name|L_MACH
value|5
end_define

begin_comment
comment|/* some kinda assembler */
end_comment

begin_define
define|#
directive|define
name|L_ENG
value|6
end_define

begin_comment
comment|/* English */
end_comment

begin_define
define|#
directive|define
name|L_PAS
value|7
end_define

begin_comment
comment|/* Pascal */
end_comment

begin_define
define|#
directive|define
name|L_MAIL
value|8
end_define

begin_comment
comment|/* Electronic mail */
end_comment

begin_define
define|#
directive|define
name|L_NEWS
value|9
end_define

begin_comment
comment|/* Usenet Netnews */
end_comment

begin_define
define|#
directive|define
name|L_JAVA
value|10
end_define

begin_comment
comment|/* Java code */
end_comment

begin_define
define|#
directive|define
name|L_HTML
value|11
end_define

begin_comment
comment|/* HTML */
end_comment

begin_define
define|#
directive|define
name|L_BCPL
value|12
end_define

begin_comment
comment|/* BCPL */
end_comment

begin_define
define|#
directive|define
name|L_M4
value|13
end_define

begin_comment
comment|/* M4 */
end_comment

begin_struct
specifier|static
specifier|const
struct|struct
block|{
name|char
modifier|*
name|human
decl_stmt|;
name|char
modifier|*
name|mime
decl_stmt|;
block|}
name|types
index|[]
init|=
block|{
block|{
literal|"C program"
block|,
literal|"text/x-c"
block|, }
block|,
block|{
literal|"C++ program"
block|,
literal|"text/x-c++"
block|}
block|,
block|{
literal|"FORTRAN program"
block|,
literal|"text/x-fortran"
block|}
block|,
block|{
literal|"make commands"
block|,
literal|"text/x-makefile"
block|}
block|,
block|{
literal|"PL/1 program"
block|,
literal|"text/x-pl1"
block|}
block|,
block|{
literal|"assembler program"
block|,
literal|"text/x-asm"
block|}
block|,
block|{
literal|"English"
block|,
literal|"text/plain, English"
block|}
block|,
block|{
literal|"Pascal program"
block|,
literal|"text/x-pascal"
block|}
block|,
block|{
literal|"mail"
block|,
literal|"text/x-mail"
block|}
block|,
block|{
literal|"news"
block|,
literal|"text/x-news"
block|}
block|,
block|{
literal|"Java program"
block|,
literal|"text/x-java"
block|}
block|,
block|{
literal|"HTML document"
block|,
literal|"text/html"
block|, }
block|,
block|{
literal|"BCPL program"
block|,
literal|"text/x-bcpl"
block|}
block|,
block|{
literal|"M4 macro language pre-processor"
block|,
literal|"text/x-m4"
block|}
block|,
block|{
literal|"can't happen error on names.h/types"
block|,
literal|"error/x-error"
block|}
block|,
block|{
literal|0
block|,
literal|0
block|}
block|}
struct|;
end_struct

begin_comment
comment|/*  * XXX - how should we distinguish Java from C++?  * The trick used in a Debian snapshot, of having "extends" or "implements"  * as tags for Java, doesn't work very well, given that those keywords  * are often preceded by "class", which flags it as C++.  *  * Perhaps we need to be able to say  *  *	If "class" then  *  *		if "extends" or "implements" then  *			Java  *		else  *			C++  *	endif  *  * Or should we use other keywords, such as "package" or "import"?  * Unfortunately, Ada95 uses "package", and Modula-3 uses "import",  * although I infer from the language spec at  *  *	http://www.research.digital.com/SRC/m3defn/html/m3.html  *  * that Modula-3 uses "IMPORT" rather than "import", i.e. it must be  * in all caps.  *  * So, for now, we go with "import".  We must put it before the C++  * stuff, so that we don't misidentify Java as C++.  Not using "package"  * means we won't identify stuff that defines a package but imports  * nothing; hopefully, very little Java code imports nothing (one of the  * reasons for doing OO programming is to import as much as possible  * and write only what you need to, right?).  *  * Unfortunately, "import" may cause us to misidentify English text  * as Java, as it comes after "the" and "The".  Perhaps we need a fancier  * heuristic to identify Java?  */
end_comment

begin_struct
specifier|static
struct|struct
name|names
block|{
specifier|const
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
literal|"dnl"
block|,
name|L_M4
block|}
block|,
block|{
literal|"import"
block|,
name|L_JAVA
block|}
block|,
block|{
literal|"\"libhdr\""
block|,
name|L_BCPL
block|}
block|,
block|{
literal|"\"LIBHDR\""
block|,
name|L_BCPL
block|}
block|,
block|{
literal|"//"
block|,
name|L_CC
block|}
block|,
block|{
literal|"template"
block|,
name|L_CC
block|}
block|,
block|{
literal|"virtual"
block|,
name|L_CC
block|}
block|,
block|{
literal|"class"
block|,
name|L_CC
block|}
block|,
block|{
literal|"public:"
block|,
name|L_CC
block|}
block|,
block|{
literal|"private:"
block|,
name|L_CC
block|}
block|,
block|{
literal|"/*"
block|,
name|L_C
block|}
block|,
comment|/* must precede "The", "the", etc. */
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
literal|".text"
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
literal|"href="
block|,
name|L_HTML
block|}
block|,
block|{
literal|"HREF="
block|,
name|L_HTML
block|}
block|,
block|{
literal|"<body"
block|,
name|L_HTML
block|}
block|,
block|{
literal|"<BODY"
block|,
name|L_HTML
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

