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
name|short
name|res
decl_stmt|;
comment|/* basic resolution in goobies/inch */
name|short
name|hor
decl_stmt|;
comment|/* goobies horizontally */
name|short
name|vert
decl_stmt|;
name|short
name|unitwidth
decl_stmt|;
comment|/* size at which widths are given, in effect */
name|short
name|nfonts
decl_stmt|;
comment|/* number of fonts physically available */
name|short
name|nsizes
decl_stmt|;
comment|/* number of sizes it has */
name|short
name|sizescale
decl_stmt|;
comment|/* scaling for fractional point sizes */
name|short
name|paperwidth
decl_stmt|;
comment|/* max line length in units */
name|short
name|paperlength
decl_stmt|;
comment|/* max paper length in units */
name|short
name|nchtab
decl_stmt|;
comment|/* number of funny names in chtab */
name|short
name|lchname
decl_stmt|;
comment|/* length of chname table */
name|short
name|nstips
decl_stmt|;
comment|/* in case of expansion */
name|short
name|spare1
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|font
block|{
comment|/* characteristics of a font */
name|char
name|nwfont
decl_stmt|;
comment|/* number of width entries for this font */
name|char
name|specfont
decl_stmt|;
comment|/* 1 == special font */
name|char
name|ligfont
decl_stmt|;
comment|/* 1 == ligatures exist on this font */
name|char
name|spare1
decl_stmt|;
comment|/* unused for now */
name|char
name|namefont
index|[
literal|10
index|]
decl_stmt|;
comment|/* name of this font (e.g., "R" */
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

end_unit

