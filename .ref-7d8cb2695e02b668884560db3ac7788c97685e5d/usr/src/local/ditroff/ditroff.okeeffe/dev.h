begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* 	dev.h: characteristics of a typesetter */
end_comment

begin_struct
struct|struct
name|dev
block|{
name|unsigned
name|short
name|filesize
decl_stmt|;
comment|/* number of bytes in file, */
comment|/* excluding dev part */
name|unsigned
name|short
name|res
decl_stmt|;
comment|/* basic resolution in goobies/inch */
name|unsigned
name|short
name|hor
decl_stmt|;
comment|/* goobies horizontally */
name|unsigned
name|short
name|vert
decl_stmt|;
name|unsigned
name|short
name|unitwidth
decl_stmt|;
comment|/* size at which widths are given, in effect */
name|unsigned
name|short
name|nfonts
decl_stmt|;
comment|/* number of fonts physically available */
name|unsigned
name|short
name|nsizes
decl_stmt|;
comment|/* number of sizes it has */
name|unsigned
name|short
name|sizescale
decl_stmt|;
comment|/* scaling for fractional point sizes */
name|unsigned
name|short
name|paperwidth
decl_stmt|;
comment|/* max line length in units */
name|unsigned
name|short
name|paperlength
decl_stmt|;
comment|/* max paper length in units */
name|unsigned
name|short
name|nchtab
decl_stmt|;
comment|/* number of funny names in chtab */
name|unsigned
name|short
name|lchname
decl_stmt|;
comment|/* length of chname table */
name|unsigned
name|short
name|spare1
decl_stmt|;
comment|/* #chars in largest ever font */
name|unsigned
name|short
name|spare2
decl_stmt|;
comment|/* in case of expansion */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|Font
block|{
comment|/* characteristics of a font */
name|unsigned
name|char
name|nwfont
decl_stmt|;
comment|/* number of width entries for this font */
name|unsigned
name|char
name|specfont
decl_stmt|;
comment|/* 1 == special font */
name|unsigned
name|char
name|ligfont
decl_stmt|;
comment|/* 1 == ligatures exist on this font */
name|unsigned
name|char
name|spare1
decl_stmt|;
comment|/* unused for now */
ifdef|#
directive|ifdef
name|0
name|unsigned
name|char
name|fonttab
decl_stmt|;
comment|/* 1 == use extra table for fontnumbers */
name|unsigned
name|char
name|slant
decl_stmt|;
comment|/* if set, slant font by slant degrees */
endif|#
directive|endif
name|unsigned
name|char
name|namefont
index|[
literal|10
index|]
decl_stmt|;
comment|/* name of this font (e.g., "R" */
name|unsigned
name|char
name|intname
index|[
literal|10
index|]
decl_stmt|;
comment|/* internal name (=number) on device, in ascii */
block|}
struct|;
end_struct

begin_comment
comment|/* ligatures, ORed into ligfont */
end_comment

begin_define
define|#
directive|define
name|LFF
value|01
end_define

begin_define
define|#
directive|define
name|LFI
value|02
end_define

begin_define
define|#
directive|define
name|LFL
value|04
end_define

begin_define
define|#
directive|define
name|LFFI
value|010
end_define

begin_define
define|#
directive|define
name|LFFL
value|020
end_define

begin_comment
comment|/*  * Notes by jaap:  *  * spare1 int struct dev is also known as biggestfont  *  * in Font structure is added:  *	fonttab: if set to 1, the Font.out has an extra  *		  table of shorts which gives the physical font  *		  on which the chracter lives. Allows mapping of  *		  "logial fonts" into variuos physical fonts on the  *		  device. Needed since the Harris f.i. has a weird font  *		  lay-out. Also makes fonts consisting of weird  *		  character combinations easier.  *	slant:	The font can must be slanted to force italics (function  *		of back-end, necessary for f.i. the Harris, which  *		doesn't has italics for the sans-serif fonts; these  *		italics have to be made by slanting)  */
end_comment

end_unit

