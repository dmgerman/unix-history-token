begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* @(#)menu.c	1.2	%G%  *  * Copyright -C- 1982 Barry S. Roitblat  *  *   *      This file contains the routines for initializing and displaying  * the graphics menu.  */
end_comment

begin_include
include|#
directive|include
file|"gremlin.h"
end_include

begin_comment
comment|/* imports from graphics1.c */
end_comment

begin_extern
extern|extern GRchex(
end_extern

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

begin_comment
comment|/* hex conversion routine */
end_comment

begin_extern
extern|extern GRsetpos(
end_extern

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

begin_comment
comment|/* sets the current access position */
end_comment

begin_extern
extern|extern GRVector(
end_extern

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

begin_comment
comment|/* vector drawing primitive */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|GrXMax
decl_stmt|,
name|GrYMax
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* screen dimensions */
end_comment

begin_decl_stmt
specifier|extern
name|FILE
modifier|*
name|display
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* graphics display stream */
end_comment

begin_extern
extern|extern GRDisableTablet(
end_extern

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

begin_comment
comment|/* disable graphics tablet */
end_comment

begin_comment
comment|/*  imports from long.c */
end_comment

begin_extern
extern|extern LGCommand(
end_extern

begin_operator
unit|)
operator|,
end_operator

begin_expr_stmt
name|LGPoint
argument_list|()
operator|,
name|LGUndo
argument_list|()
operator|,
name|LGDeletePoint
argument_list|()
expr_stmt|;
end_expr_stmt

begin_comment
comment|/*  imports from short.c */
end_comment

begin_extern
extern|extern SHCommand(
end_extern

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

begin_comment
comment|/* imports from main.c */
end_comment

begin_decl_stmt
specifier|extern
name|float
name|PX
decl_stmt|,
name|PY
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* X and Y of last points specified */
end_comment

begin_define
define|#
directive|define
name|horiz
value|0
end_define

begin_define
define|#
directive|define
name|vert
value|1
end_define

begin_define
define|#
directive|define
name|menusize
value|32
end_define

begin_define
define|#
directive|define
name|menuspace
value|30
end_define

begin_define
define|#
directive|define
name|origin
value|10
end_define

begin_define
define|#
directive|define
name|margin
value|25
end_define

begin_define
define|#
directive|define
name|itemxsize
value|16
end_define

begin_define
define|#
directive|define
name|itemysize
value|16
end_define

begin_define
define|#
directive|define
name|fontsize
value|(itemxsize * itemysize/8)
end_define

begin_define
define|#
directive|define
name|itemlength
value|(itemxsize * itemysize/4 + 1)
end_define

begin_define
define|#
directive|define
name|maxchars
value|8
end_define

begin_define
define|#
directive|define
name|smask
value|1
end_define

begin_define
define|#
directive|define
name|columns
value|2
end_define

begin_define
define|#
directive|define
name|border
value|395
end_define

begin_comment
comment|/* bytewise definitions of menu symbols (special fonts), left to right,  * top to bottom.  See textcommand array for corresponding commands.  */
end_comment

begin_decl_stmt
specifier|static
name|char
name|menu
index|[
name|menusize
index|]
index|[
name|itemlength
index|]
init|=
block|{
comment|/* 1 */
literal|"07F00080008000800080008000800080008000800080008000800080008007F0"
block|,
comment|/* 2 */
literal|"08100810082008200840084008800F0008C00820081008100810082008C00F00"
block|,
comment|/* 3 */
literal|"0000000000000000000000000000FFFFFFFFFFFF000000000000000000000000"
block|,
comment|/* 4 */
literal|"0000000000000000000000000000E4E4E4E40000000000000000000000000000"
block|,
comment|/* 5 */
literal|"0000000000000000000000000000924992490000000000000000000000000000"
block|,
comment|/* 6 */
literal|"FFFF8001800187E18401840183018081804180218421842183C180018001FFFF"
block|,
comment|/* 7 */
literal|"FFFF80018001808180818081808180818081808182818181808180018001FFFF"
block|,
comment|/* 8 */
literal|"008001C002A0008000800080008000800080008000800080008002A001C00080"
block|,
comment|/* 9 */
literal|"00000000000000000000000020044002FFFF4002200400000000000000000000"
block|,
comment|/* 10 */
literal|"000080028002400440042008183007C0FFFF07C0183020084004400480028002"
block|,
comment|/* 11 */
literal|"20002000FFFC2704288430443044304428842704200427C424443FFF044407C4"
block|,
comment|/* 12 */
literal|"FFFF804080E0815080408080808081008600F800800080008000800080008000"
block|,
comment|/* 13 */
literal|"00FF008100810081008100810E8106FF0A00100020000000F00090009000F000"
block|,
comment|/* 14 */
literal|"FFFF8001A001900180018401820180018001804180218001800980058001FFFF"
block|,
comment|/* 15 */
literal|"000000000000000030001C000B800460021804600B801C003000000000000000"
block|,
comment|/* 16 */
literal|"00000000000000001C02220143018101808180C2804440380000000000000000"
block|,
comment|/* 17 */
literal|"03C004200010001000100010002003C004000800080008000800042003C00000"
block|,
comment|/* 18 */
literal|"0F0008C008200810081008100810082008C00F0008C008200820082008C00F00"
block|,
comment|/* 19 */
literal|"00000000000000000000000000000000FFFFFFFF000000000000000000000000"
block|,
comment|/* 20 */
literal|"00000000000000000000000000000000FFFF0000000000000000000000000000"
block|,
comment|/* 21 */
literal|"00000000000000000000000000000000F87C0000000000000000000000000000"
block|,
comment|/* 22 */
literal|"FFFF800180018041804180418041804187E1844184418441804180018001FFFF"
block|,
comment|/* 23 */
literal|"FFFF80018001838184418821802180418181804180218821844183818001FFFF"
block|,
comment|/* 24 */
literal|"80028002400440042008183007C001000280044008201EF00280028002800280"
block|,
comment|/* 25 */
literal|"000400023FFF2002200420002000200020002000200020002000A80070002000"
block|,
comment|/* 26 */
literal|"20042004FFFF2004200420042004200420042004200420042004FFFF20042004"
block|,
comment|/* 27 */
literal|"FFFF9C39A245C183C183C183A2459C3981C18221841184118411822181C1FFFF"
block|,
comment|/* 28 */
literal|"800140023FFC300C28142424224421842184224424242814300C3FFC40028001"
block|,
comment|/* 29 */
literal|"000000000000000F00090009F04F902097F0F02F00490009000F000000000000"
block|,
comment|/* 30 */
literal|"F00090009000F000080004000200014000C001C00000001E00120012001E0000"
block|,
comment|/* 31 */
literal|"000007C0183020084004400480028002810280028002400440042008183007C0"
block|,
comment|/* 32 */
literal|"02000100FF80018002400040002000200010001000082019400EFFFC40002000"
block|}
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* menu item color map  */
end_comment

begin_decl_stmt
specifier|static
name|int
name|mencolor
index|[
name|menusize
index|]
init|=
block|{
literal|4
block|,
literal|1
block|,
literal|3
block|,
literal|1
block|,
literal|1
block|,
literal|6
block|,
literal|6
block|,
literal|1
block|,
literal|1
block|,
literal|5
block|,
literal|5
block|,
literal|5
block|,
literal|5
block|,
literal|3
block|,
literal|3
block|,
literal|3
block|,
literal|6
block|,
literal|5
block|,
literal|2
block|,
literal|1
block|,
literal|1
block|,
literal|6
block|,
literal|6
block|,
literal|1
block|,
literal|1
block|,
literal|1
block|,
literal|5
block|,
literal|5
block|,
literal|5
block|,
literal|5
block|,
literal|3
block|,
literal|3
block|}
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* menu equivalent text commands */
end_comment

begin_decl_stmt
specifier|static
name|char
name|textcommand
index|[
name|menusize
index|]
index|[
name|maxchars
index|]
init|=
block|{
comment|/* 1 */
literal|":f,2"
block|,
comment|/* font,2 */
comment|/* 2 */
literal|":f,1"
block|,
comment|/* font,1 */
comment|/* 3 */
literal|":br,3"
block|,
comment|/* brush,3 */
comment|/* 4 */
literal|":br,2"
block|,
comment|/* brush,2 */
comment|/* 5 */
literal|":br,1"
block|,
comment|/* brush,1 */
comment|/* 6 */
literal|":buf,2"
block|,
comment|/* set buffer 2  */
comment|/* 7 */
literal|":buf,1"
block|,
comment|/* set buffer 1  */
comment|/* 8 */
literal|":vadj"
block|,
comment|/* vertical adjust */
comment|/* 9 */
literal|":hadj"
block|,
comment|/* horizontal adjust */
comment|/* 10 */
literal|":mi"
block|,
comment|/* mirror */
comment|/* 11 */
literal|"f"
block|,
comment|/* select area in current set */
comment|/* 12 */
literal|"r"
block|,
comment|/* rotate current set */
comment|/* 13 */
literal|"s"
block|,
comment|/* scale current set */
comment|/* 14 */
literal|"x"
block|,
comment|/* rectangle from 2 points */
comment|/* 15 */
literal|"w"
block|,
comment|/* arrow heads */
comment|/* 16 */
literal|"b"
block|,
comment|/* draw curve */
comment|/* 17 */
literal|":f,4"
block|,
comment|/* font,4 */
comment|/* 18 */
literal|":f,3"
block|,
comment|/* font,3 */
comment|/* 19 */
literal|":br,6"
block|,
comment|/* brush,6 */
comment|/* 20 */
literal|":br,5"
block|,
comment|/* brush,5 */
comment|/* 21 */
literal|":br,4"
block|,
comment|/* brush,4 */
comment|/* 22 */
literal|":buf,4"
block|,
comment|/* set buffer 4 */
comment|/* 23 */
literal|":buf,3"
block|,
comment|/* set buffer 3 */
comment|/* 24 */
literal|"g"
block|,
comment|/* gravity */
comment|/* 25 */
literal|"z"
block|,
comment|/* manhattan adjust */
comment|/* 26 */
literal|"q"
block|,
comment|/* grid */
comment|/* 27 */
literal|"d"
block|,
comment|/* define current set */
comment|/* 28 */
literal|"e"
block|,
comment|/* erase */
comment|/* 29 */
literal|"c"
block|,
comment|/* copy current set */
comment|/* 30 */
literal|"t"
block|,
comment|/* translate current set */
comment|/* 31 */
literal|"a"
block|,
comment|/* draw arc */
comment|/* 32 */
literal|"v"
block|,
comment|/* draw vector */
block|}
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  screen map for menu symbols  */
end_comment

begin_struct
struct|struct
name|bounds
block|{
name|int
name|lowx
decl_stmt|,
name|lowy
decl_stmt|,
name|hix
decl_stmt|,
name|hiy
decl_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
specifier|static
name|struct
name|bounds
name|area
index|[
name|menusize
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Following is a map of brushes and mode made available to the  * outside world for selection of these items for highlighting.  * The numbers indicate the items location in the menu.  */
end_comment

begin_decl_stmt
name|int
name|HiMen
index|[
literal|4
index|]
init|=
block|{
literal|6
block|,
literal|5
block|,
literal|22
block|,
literal|21
block|}
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* user symbols */
end_comment

begin_decl_stmt
name|int
name|HiFont
index|[
literal|4
index|]
init|=
block|{
literal|1
block|,
literal|0
block|,
literal|17
block|,
literal|16
block|}
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* fonts */
end_comment

begin_decl_stmt
name|int
name|HiBrush
index|[
literal|6
index|]
init|=
block|{
literal|4
block|,
literal|3
block|,
literal|2
block|,
literal|20
block|,
literal|19
block|,
literal|18
block|}
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* brushes */
end_comment

begin_decl_stmt
name|int
name|HiMode
index|[
literal|4
index|]
init|=
block|{
literal|8
block|,
literal|7
block|,
literal|24
block|,
literal|23
block|}
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* horz, vert, man, grav. */
end_comment

begin_decl_stmt
specifier|static
name|int
name|xorig
decl_stmt|,
name|yorig
decl_stmt|,
name|deltax
decl_stmt|,
name|deltay
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|POINT
name|bord1
decl_stmt|,
name|bord2
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* forward references within this file */
end_comment

begin_extern
extern|extern MNHighLt(
end_extern

begin_operator
unit|)
operator|,
end_operator

begin_expr_stmt
name|MNUnHighLt
argument_list|()
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* variables to save previous command */
end_comment

begin_decl_stmt
specifier|static
name|char
modifier|*
name|last
decl_stmt|;
end_decl_stmt

begin_expr_stmt
specifier|static
name|lastint
expr_stmt|;
end_expr_stmt

begin_macro
name|MNIcon
argument_list|()
end_macro

begin_comment
comment|/*  *     This routine initializatizes the menu symbols by defining to  * the AED each menu symbol as a special font.  The special fonts are  * defined by a series of bytes in the array menu which is initialized.  * they could also be read in from an external file.  */
end_comment

begin_block
block|{
name|int
name|i
decl_stmt|;
ifndef|#
directive|ifndef
name|FASTIO
name|char
name|s1
index|[
literal|3
index|]
decl_stmt|,
name|s2
index|[
literal|3
index|]
decl_stmt|,
name|s3
index|[
literal|3
index|]
decl_stmt|,
name|s4
index|[
literal|3
index|]
decl_stmt|;
else|#
directive|else
name|int
name|c
decl_stmt|,
name|k
decl_stmt|;
endif|#
directive|endif
comment|/* add code here to read in special fonts if  		   desired.                                  */
for|for
control|(
name|i
operator|=
literal|1
init|;
name|i
operator|<=
name|menusize
condition|;
operator|++
name|i
control|)
block|{
name|putc
argument_list|(
literal|'7'
argument_list|,
name|display
argument_list|)
expr_stmt|;
comment|/* define special font */
ifndef|#
directive|ifndef
name|FASTIO
name|GRchex
argument_list|(
name|i
argument_list|,
name|s1
argument_list|,
literal|2
argument_list|)
expr_stmt|;
name|GRchex
argument_list|(
name|itemxsize
argument_list|,
name|s2
argument_list|,
literal|2
argument_list|)
expr_stmt|;
name|GRchex
argument_list|(
name|itemysize
argument_list|,
name|s3
argument_list|,
literal|2
argument_list|)
expr_stmt|;
name|GRchex
argument_list|(
name|mencolor
index|[
name|i
operator|-
literal|1
index|]
argument_list|,
name|s4
argument_list|,
literal|2
argument_list|)
expr_stmt|;
name|fprintf
argument_list|(
name|display
argument_list|,
literal|"%s%s%s%s%s00"
argument_list|,
name|s1
argument_list|,
name|s2
argument_list|,
name|s3
argument_list|,
name|s4
argument_list|,
name|menu
index|[
name|i
operator|-
literal|1
index|]
argument_list|)
expr_stmt|;
else|#
directive|else
name|fprintf
argument_list|(
name|display
argument_list|,
literal|"%c%c%c%c"
argument_list|,
name|i
operator|&
literal|0377
argument_list|,
name|itemxsize
operator|&
literal|0377
argument_list|,
name|itemysize
operator|&
literal|0377
argument_list|,
name|mencolor
index|[
name|i
operator|-
literal|1
index|]
operator|&
literal|0377
argument_list|)
expr_stmt|;
for|for
control|(
name|k
operator|=
literal|0
init|;
name|k
operator|<
name|itemlength
operator|-
literal|1
condition|;
name|k
operator|+=
literal|2
control|)
block|{
operator|(
name|void
operator|)
name|sscanf
argument_list|(
operator|&
operator|(
name|menu
index|[
name|i
operator|-
literal|1
index|]
index|[
name|k
index|]
operator|)
argument_list|,
literal|"%2x"
argument_list|,
operator|&
name|c
argument_list|)
expr_stmt|;
name|putc
argument_list|(
name|c
operator|&
literal|0377
argument_list|,
name|display
argument_list|)
expr_stmt|;
block|}
empty_stmt|;
comment|/* end for k */
name|putc
argument_list|(
literal|'\0'
argument_list|,
name|display
argument_list|)
expr_stmt|;
endif|#
directive|endif
block|}
empty_stmt|;
comment|/* end for i */
operator|(
name|void
operator|)
name|fflush
argument_list|(
name|display
argument_list|)
expr_stmt|;
block|}
end_block

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
comment|/* end Icon */
end_comment

begin_macro
name|MNInitMenu
argument_list|(
argument|orientation
argument_list|)
end_macro

begin_decl_stmt
name|int
name|orientation
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* orientation of work space */
end_comment

begin_comment
comment|/*  *     This routine initializatizes the spacing and orientation of  * the menu so that elements can be properly displayed and selected.  */
end_comment

begin_block
block|{
name|int
name|xcum
decl_stmt|,
name|ycum
decl_stmt|,
name|i
decl_stmt|;
name|last
operator|=
name|textcommand
index|[
literal|0
index|]
expr_stmt|;
name|lastint
operator|=
literal|0
expr_stmt|;
if|if
condition|(
name|orientation
operator|==
name|horiz
condition|)
comment|/* set up spacing for menu display */
block|{
name|xorig
operator|=
name|GrXMax
operator|-
name|origin
operator|-
name|menuspace
expr_stmt|;
name|yorig
operator|=
name|GrYMax
operator|-
name|menuspace
expr_stmt|;
name|deltax
operator|=
operator|-
name|menuspace
expr_stmt|;
name|deltay
operator|=
literal|0
expr_stmt|;
name|bord1
operator|.
name|y
operator|=
name|bord2
operator|.
name|y
operator|=
name|border
expr_stmt|;
name|bord1
operator|.
name|x
operator|=
literal|0
expr_stmt|;
name|bord2
operator|.
name|x
operator|=
name|GrXMax
expr_stmt|;
block|}
else|else
block|{
name|xorig
operator|=
name|margin
expr_stmt|;
name|yorig
operator|=
name|origin
expr_stmt|;
name|deltax
operator|=
literal|0
expr_stmt|;
name|deltay
operator|=
name|menuspace
expr_stmt|;
name|bord1
operator|.
name|x
operator|=
name|bord2
operator|.
name|x
operator|=
name|GrXMax
operator|-
name|border
expr_stmt|;
name|bord1
operator|.
name|y
operator|=
literal|0
expr_stmt|;
name|bord2
operator|.
name|y
operator|=
name|GrYMax
expr_stmt|;
block|}
empty_stmt|;
name|xcum
operator|=
name|xorig
operator|-
operator|(
name|menuspace
operator|-
name|itemxsize
operator|)
operator|/
literal|2
expr_stmt|;
name|ycum
operator|=
name|yorig
operator|-
operator|(
name|menuspace
operator|-
name|itemysize
operator|)
operator|/
literal|2
expr_stmt|;
for|for
control|(
name|i
operator|=
literal|0
init|;
name|i
operator|<
name|menusize
condition|;
operator|++
name|i
control|)
comment|/* store boundaries for each menu item */
block|{
name|area
index|[
name|i
index|]
operator|.
name|lowx
operator|=
name|xcum
expr_stmt|;
name|area
index|[
name|i
index|]
operator|.
name|lowy
operator|=
name|ycum
expr_stmt|;
name|area
index|[
name|i
index|]
operator|.
name|hix
operator|=
name|xcum
operator|+
name|menuspace
expr_stmt|;
name|area
index|[
name|i
index|]
operator|.
name|hiy
operator|=
name|ycum
operator|+
name|menuspace
expr_stmt|;
name|xcum
operator|+=
name|deltax
expr_stmt|;
name|ycum
operator|+=
name|deltay
expr_stmt|;
if|if
condition|(
operator|(
operator|(
name|i
operator|+
literal|1
operator|)
operator|%
operator|(
name|menusize
operator|/
name|columns
operator|)
operator|)
operator|==
literal|0
condition|)
comment|/* end of row/col */
block|{
name|xcum
operator|=
name|xorig
operator|+
name|deltay
operator|-
operator|(
name|menuspace
operator|-
name|itemxsize
operator|)
operator|/
literal|2
expr_stmt|;
name|ycum
operator|=
name|yorig
operator|+
name|deltax
operator|-
operator|(
name|menuspace
operator|-
name|itemysize
operator|)
operator|/
literal|2
expr_stmt|;
block|}
comment|/* end if */
empty_stmt|;
block|}
comment|/* end for */
empty_stmt|;
block|}
end_block

begin_comment
comment|/* end initmenu */
end_comment

begin_macro
name|MNDisplayMenu
argument_list|()
end_macro

begin_comment
comment|/*  *      This routine displays the menu defined by initmenu  */
end_comment

begin_block
block|{
name|int
name|i
decl_stmt|;
ifndef|#
directive|ifndef
name|FASTIO
name|char
name|s1
index|[
literal|3
index|]
decl_stmt|,
name|s2
index|[
literal|3
index|]
decl_stmt|,
name|s3
index|[
literal|3
index|]
decl_stmt|;
endif|#
directive|endif
name|GRsetpos
argument_list|(
name|xorig
argument_list|,
name|yorig
argument_list|)
expr_stmt|;
name|putc
argument_list|(
literal|'8'
argument_list|,
name|display
argument_list|)
expr_stmt|;
comment|/* write special font */
for|for
control|(
name|i
operator|=
literal|1
init|;
name|i
operator|<=
name|menusize
condition|;
operator|++
name|i
control|)
block|{
ifndef|#
directive|ifndef
name|FASTIO
name|GRchex
argument_list|(
name|i
argument_list|,
name|s1
argument_list|,
literal|2
argument_list|)
expr_stmt|;
name|GRchex
argument_list|(
name|deltax
argument_list|,
name|s2
argument_list|,
literal|2
argument_list|)
expr_stmt|;
name|GRchex
argument_list|(
name|deltay
argument_list|,
name|s3
argument_list|,
literal|2
argument_list|)
expr_stmt|;
name|fprintf
argument_list|(
name|display
argument_list|,
literal|"%s%s%s"
argument_list|,
name|s1
argument_list|,
name|s2
argument_list|,
name|s3
argument_list|)
expr_stmt|;
else|#
directive|else
name|fprintf
argument_list|(
name|display
argument_list|,
literal|"%c%c%c"
argument_list|,
name|i
operator|&
literal|0377
argument_list|,
name|deltax
operator|&
literal|0377
argument_list|,
name|deltay
operator|&
literal|0377
argument_list|)
expr_stmt|;
endif|#
directive|endif
operator|(
name|void
operator|)
name|fflush
argument_list|(
name|display
argument_list|)
expr_stmt|;
if|if
condition|(
operator|(
name|i
operator|%
operator|(
name|menusize
operator|/
name|columns
operator|)
operator|)
operator|==
literal|0
condition|)
comment|/* new row/col */
block|{
ifndef|#
directive|ifndef
name|FASTIO
name|fputs
argument_list|(
literal|"00"
argument_list|,
name|display
argument_list|)
expr_stmt|;
else|#
directive|else
name|putc
argument_list|(
literal|'\00'
argument_list|,
name|display
argument_list|)
expr_stmt|;
endif|#
directive|endif
name|GRsetpos
argument_list|(
name|xorig
operator|+
name|deltay
argument_list|,
name|yorig
operator|+
name|deltax
argument_list|)
expr_stmt|;
comment|/* reposition */
name|putc
argument_list|(
literal|'8'
argument_list|,
name|display
argument_list|)
expr_stmt|;
block|}
comment|/* end if */
empty_stmt|;
block|}
comment|/* end for */
ifndef|#
directive|ifndef
name|FASTIO
name|fputs
argument_list|(
literal|"00"
argument_list|,
name|display
argument_list|)
expr_stmt|;
else|#
directive|else
name|putc
argument_list|(
literal|'\00'
argument_list|,
name|display
argument_list|)
expr_stmt|;
endif|#
directive|endif
name|GRsetwmask
argument_list|(
name|linemask
argument_list|)
expr_stmt|;
name|GRVector
argument_list|(
operator|&
name|bord1
argument_list|,
operator|&
name|bord2
argument_list|,
name|bordstyle
argument_list|)
expr_stmt|;
block|}
end_block

begin_comment
comment|/* end displaymenu */
end_comment

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_function
name|char
modifier|*
name|MNFindMenuItem
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
name|int
name|x
decl_stmt|,
name|y
decl_stmt|;
comment|/*  * returns a pointer to the text string equivalent of the selected  * menu item.  */
block|{
name|int
name|i
decl_stmt|;
for|for
control|(
name|i
operator|=
literal|0
init|;
name|i
operator|<
name|menusize
condition|;
operator|++
name|i
control|)
if|if
condition|(
name|x
operator|<
name|area
index|[
name|i
index|]
operator|.
name|hix
condition|)
if|if
condition|(
name|y
operator|<
name|area
index|[
name|i
index|]
operator|.
name|hiy
condition|)
if|if
condition|(
name|x
operator|>
name|area
index|[
name|i
index|]
operator|.
name|lowx
condition|)
if|if
condition|(
name|y
operator|>
name|area
index|[
name|i
index|]
operator|.
name|lowy
condition|)
block|{
name|last
operator|=
name|textcommand
index|[
name|i
index|]
expr_stmt|;
name|lastint
operator|=
name|i
expr_stmt|;
return|return
operator|(
name|textcommand
index|[
name|i
index|]
operator|)
return|;
block|}
comment|/* end, nested if */
empty_stmt|;
return|return
operator|(
name|last
operator|)
return|;
comment|/* cursor out of menu area */
block|}
end_function

begin_comment
comment|/* end findmenuitem */
end_comment

begin_macro
name|MNHighLt
argument_list|(
argument|sym
argument_list|,
argument|color
argument_list|)
end_macro

begin_decl_stmt
name|int
name|sym
decl_stmt|,
name|color
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  *      This routine highlights the specified menu item by drawing a   * box around it in the highlighting color.  */
end_comment

begin_block
block|{
name|POINT
name|p1
decl_stmt|,
name|p2
decl_stmt|,
name|p3
decl_stmt|,
name|p4
decl_stmt|;
name|GRsetwmask
argument_list|(
name|himask
argument_list|)
expr_stmt|;
name|p1
operator|.
name|x
operator|=
name|area
index|[
name|sym
index|]
operator|.
name|lowx
expr_stmt|;
name|p1
operator|.
name|y
operator|=
name|area
index|[
name|sym
index|]
operator|.
name|lowy
expr_stmt|;
name|p2
operator|.
name|x
operator|=
name|area
index|[
name|sym
index|]
operator|.
name|lowx
expr_stmt|;
name|p2
operator|.
name|y
operator|=
name|area
index|[
name|sym
index|]
operator|.
name|hiy
operator|-
literal|1
expr_stmt|;
name|p3
operator|.
name|x
operator|=
name|area
index|[
name|sym
index|]
operator|.
name|hix
operator|-
literal|1
expr_stmt|;
name|p3
operator|.
name|y
operator|=
name|area
index|[
name|sym
index|]
operator|.
name|hiy
operator|-
literal|1
expr_stmt|;
name|p4
operator|.
name|x
operator|=
name|area
index|[
name|sym
index|]
operator|.
name|hix
operator|-
literal|1
expr_stmt|;
name|p4
operator|.
name|y
operator|=
name|area
index|[
name|sym
index|]
operator|.
name|lowy
expr_stmt|;
name|GRVector
argument_list|(
operator|&
name|p1
argument_list|,
operator|&
name|p2
argument_list|,
name|color
argument_list|)
expr_stmt|;
name|GRVector
argument_list|(
operator|&
name|p2
argument_list|,
operator|&
name|p3
argument_list|,
name|color
argument_list|)
expr_stmt|;
name|GRVector
argument_list|(
operator|&
name|p3
argument_list|,
operator|&
name|p4
argument_list|,
name|color
argument_list|)
expr_stmt|;
name|GRVector
argument_list|(
operator|&
name|p4
argument_list|,
operator|&
name|p1
argument_list|,
name|color
argument_list|)
expr_stmt|;
block|}
end_block

begin_comment
comment|/* end MNHighLt */
end_comment

begin_macro
name|MNUnHighLt
argument_list|(
argument|sym
argument_list|)
end_macro

begin_decl_stmt
name|int
name|sym
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  *      This routine unhighlights the specified symbol by calling   * MNHighLt with the erase color specified.  */
end_comment

begin_block
block|{
name|MNHighLt
argument_list|(
name|sym
argument_list|,
name|eraseany
argument_list|)
expr_stmt|;
block|}
end_block

begin_macro
name|MNInterpretCursor
argument_list|(
argument|button
argument_list|,
argument|cx
argument_list|,
argument|cy
argument_list|)
end_macro

begin_decl_stmt
name|int
name|cx
decl_stmt|,
name|cy
decl_stmt|,
name|button
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*   *      This routine interprets the cursor button function and calls  * the appropriate command interpretation routines.  */
end_comment

begin_block
block|{
name|char
modifier|*
name|cmd
decl_stmt|;
name|PX
operator|=
name|cx
expr_stmt|;
name|PY
operator|=
name|cy
expr_stmt|;
if|if
condition|(
name|button
operator|==
literal|0
condition|)
block|{
name|cmd
operator|=
name|MNFindMenuItem
argument_list|(
name|cx
argument_list|,
name|cy
argument_list|)
expr_stmt|;
if|if
condition|(
operator|*
name|cmd
operator|==
literal|':'
condition|)
name|LGCommand
argument_list|(
operator|++
name|cmd
argument_list|)
expr_stmt|;
else|else
name|SHCommand
argument_list|(
name|cmd
argument_list|)
expr_stmt|;
block|}
if|if
condition|(
name|button
operator|==
literal|1
condition|)
name|LGDeletePoint
argument_list|(
operator|++
name|cmd
argument_list|)
expr_stmt|;
if|if
condition|(
name|button
operator|==
literal|2
condition|)
name|LGUndo
argument_list|(
operator|++
name|cmd
argument_list|)
expr_stmt|;
if|if
condition|(
name|button
operator|==
literal|3
condition|)
block|{
name|LGPoint
argument_list|(
operator|++
name|cmd
argument_list|)
expr_stmt|;
block|}
block|}
end_block

end_unit

