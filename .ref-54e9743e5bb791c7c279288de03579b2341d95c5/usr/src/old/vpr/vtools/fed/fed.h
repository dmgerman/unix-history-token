begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	fed.h	4.1	83/03/09	*/
end_comment

begin_comment
comment|/*  * fed.h: global definitions for font editor.  */
end_comment

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_include
include|#
directive|include
file|<ctype.h>
end_include

begin_include
include|#
directive|include
file|<vfont.h>
end_include

begin_include
include|#
directive|include
file|<signal.h>
end_include

begin_include
include|#
directive|include
file|<setjmp.h>
end_include

begin_comment
comment|/* current windows - what's on the screen */
end_comment

begin_define
define|#
directive|define
name|SCRHI
value|360
end_define

begin_comment
comment|/* number of pixels on the screen */
end_comment

begin_define
define|#
directive|define
name|SCRWID
value|720
end_define

begin_comment
comment|/* width in pixels of the screen */
end_comment

begin_define
define|#
directive|define
name|NROW
value|3
end_define

begin_comment
comment|/* number of rows of glyphs on the screen */
end_comment

begin_define
define|#
directive|define
name|NCOL
value|7
end_define

begin_comment
comment|/* number of cols of glyphs in a row */
end_comment

begin_define
define|#
directive|define
name|NWIND
value|(NROW*NCOL)
end_define

begin_comment
comment|/* number of windows */
end_comment

begin_define
define|#
directive|define
name|GLCOL
value|100
end_define

begin_comment
comment|/* width of a glyph window */
end_comment

begin_define
define|#
directive|define
name|GLROW
value|100
end_define

begin_comment
comment|/* height of a glyph window */
end_comment

begin_define
define|#
directive|define
name|GLPAD
value|3
end_define

begin_comment
comment|/* number of pixels between windows */
end_comment

begin_define
define|#
directive|define
name|WINDSIZE
value|(((GLCOL+7)>>3)*GLROW)
end_define

begin_comment
comment|/* size in bytes of a window */
end_comment

begin_define
define|#
directive|define
name|BASELINE
value|22
end_define

begin_comment
comment|/* number of pixels below baseline in window */
end_comment

begin_define
define|#
directive|define
name|SLOPE
value|(3.5)
end_define

begin_comment
comment|/* Amount to slant italic vertical line */
end_comment

begin_comment
comment|/* equal to about 15.94 degrees */
end_comment

begin_comment
comment|/* for 5 degree caligraphy slant use 11.43 */
end_comment

begin_define
define|#
directive|define
name|ESC
value|'\033'
end_define

begin_comment
comment|/* The ASCII escape character */
end_comment

begin_define
define|#
directive|define
name|abs
parameter_list|(
name|x
parameter_list|)
value|((x)<  0  ? (-(x)) : (x))
end_define

begin_define
define|#
directive|define
name|max
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
value|((x)> (y) ?   (x)  : (y))
end_define

begin_define
define|#
directive|define
name|min
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
value|((x)< (y) ?   (x)  : (y))
end_define

begin_typedef
typedef|typedef
name|char
modifier|*
name|bitmat
typedef|;
end_typedef

begin_decl_stmt
name|int
name|changes
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* nonzero if changes since last write */
end_comment

begin_decl_stmt
name|char
name|curchar
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* current character being edited */
end_comment

begin_decl_stmt
name|int
name|curcurs
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* 1 if cursor is on now */
end_comment

begin_decl_stmt
name|int
name|currb
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* 1 if rubber band lie is on now */
end_comment

begin_decl_stmt
name|int
name|curs_r
decl_stmt|,
name|curs_c
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* position in current window of graphics cursor */
end_comment

begin_decl_stmt
name|int
name|curwind
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* current open window number */
end_comment

begin_decl_stmt
name|int
name|curzoom
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* 1 to 9 - current zoom level of screen */
end_comment

begin_decl_stmt
name|int
name|editing
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* in file I/O command, true if editing font */
end_comment

begin_decl_stmt
name|jmp_buf
name|env
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|long
name|fbase
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* first loc in font file of bits */
end_comment

begin_decl_stmt
name|FILE
modifier|*
name|fontdes
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* open for reading, current font */
end_comment

begin_decl_stmt
name|char
name|fontfile
index|[
literal|100
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* name of the font file */
end_comment

begin_decl_stmt
name|int
name|hpensize
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* size of heavy pen in pixels diameter of dot */
end_comment

begin_decl_stmt
name|char
name|msgbuf
index|[
literal|100
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* scratch space to sprintf into for messages */
end_comment

begin_decl_stmt
name|int
name|nextwind
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* the next free window to grab */
end_comment

begin_decl_stmt
name|int
name|oldzoom
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* the value of curzoom before a message */
end_comment

begin_decl_stmt
name|int
name|pen_r
decl_stmt|,
name|pen_c
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* row/col in current glyph of logical pen */
end_comment

begin_decl_stmt
name|int
name|pencolor
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* 0=erase, 1=draw */
end_comment

begin_decl_stmt
name|int
name|penweight
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* 0=fine, 1=heavy */
end_comment

begin_decl_stmt
name|int
name|pointsize
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* point size of current font */
end_comment

begin_decl_stmt
name|int
name|QUIET
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* true if -q flag */
end_comment

begin_decl_stmt
name|char
name|stoutbuf
index|[
name|BUFSIZ
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* for speed */
end_comment

begin_decl_stmt
name|FILE
modifier|*
name|trace
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* for debugging output */
end_comment

begin_decl_stmt
name|char
name|tracebuf
index|[
name|BUFSIZ
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* for speed */
end_comment

begin_decl_stmt
name|int
name|und_p_r
decl_stmt|,
name|und_p_c
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* pen_r, pen_c for undo */
end_comment

begin_decl_stmt
name|int
name|und_c_r
decl_stmt|,
name|und_c_c
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* curs_r, curs_c for undo */
end_comment

begin_decl_stmt
name|struct
name|header
name|FontHeader
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|dispatch
name|disptable
index|[
literal|256
index|]
decl_stmt|;
end_decl_stmt

begin_struct
struct|struct
name|cwind
block|{
name|bitmat
name|val
decl_stmt|;
comment|/* what we are making it into */
name|bitmat
name|onscreen
decl_stmt|;
comment|/* what's currently on the screen */
name|bitmat
name|undval
decl_stmt|;
comment|/* the previous version */
name|char
name|used
decl_stmt|;
comment|/* the character using this window */
block|}
name|wind
index|[
name|NROW
operator|*
name|NCOL
index|]
struct|;
end_struct

begin_struct
struct|struct
name|cht
block|{
name|int
name|wherewind
decl_stmt|;
comment|/*>=0: window # on screen, -1: in file, -2: use whereat */
name|bitmat
name|whereat
decl_stmt|;
comment|/* where it can be found */
name|int
name|nrow
decl_stmt|,
name|ncol
decl_stmt|;
comment|/* size of char */
name|int
name|rcent
decl_stmt|,
name|ccent
decl_stmt|;
comment|/* bit location of lower left corner of main part of char */
block|}
name|cht
index|[
literal|256
index|]
struct|;
end_struct

begin_struct
struct|struct
name|place
block|{
name|int
name|c
decl_stmt|,
name|r
decl_stmt|;
block|}
name|base
index|[
name|NROW
operator|*
name|NCOL
index|]
struct|;
end_struct

begin_comment
comment|/* lower left corner of each window */
end_comment

begin_decl_stmt
name|char
name|penmat
index|[
literal|10
index|]
index|[
literal|10
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* 0 or 1 as the pen is.  5,5 is center */
end_comment

begin_decl_stmt
name|float
name|sqrtmat
index|[
literal|10
index|]
index|[
literal|10
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* table of sqrt(i**2+j**2) for speed */
end_comment

begin_function_decl
name|char
modifier|*
name|rdchar
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|char
name|esccmd
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|bitmat
name|newmat
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|bitmat
name|findbits
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|onsig
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|onintr
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|float
name|sqrt
parameter_list|()
function_decl|;
end_function_decl

begin_decl_stmt
name|int
name|matcnt
index|[
literal|10
index|]
decl_stmt|;
end_decl_stmt

end_unit

