begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * @(#)gremlin.h	1.1	%G%  *  * Standard definitions used by the SUN Gremlin picture editor.  *  * Mark Opperman (opcode@monet.BERKELEY)  *  */
end_comment

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_include
include|#
directive|include
file|<math.h>
end_include

begin_define
define|#
directive|define
name|nullpt
value|-1
end_define

begin_define
define|#
directive|define
name|MAXPOINTS
value|200
end_define

begin_define
define|#
directive|define
name|pixmask
value|1
end_define

begin_define
define|#
directive|define
name|csetmask
value|2
end_define

begin_define
define|#
directive|define
name|scratchmask
value|4
end_define

begin_define
define|#
directive|define
name|BOTLEFT
value|0
end_define

begin_define
define|#
directive|define
name|BOTRIGHT
value|1
end_define

begin_define
define|#
directive|define
name|CENTCENT
value|2
end_define

begin_define
define|#
directive|define
name|VECTOR
value|3
end_define

begin_define
define|#
directive|define
name|ARC
value|4
end_define

begin_define
define|#
directive|define
name|CURVE
value|5
end_define

begin_define
define|#
directive|define
name|POLYGON
value|6
end_define

begin_define
define|#
directive|define
name|TOPLEFT
value|10
end_define

begin_define
define|#
directive|define
name|TOPCENT
value|11
end_define

begin_define
define|#
directive|define
name|TOPRIGHT
value|12
end_define

begin_define
define|#
directive|define
name|CENTLEFT
value|13
end_define

begin_define
define|#
directive|define
name|CENTRIGHT
value|14
end_define

begin_define
define|#
directive|define
name|BOTCENT
value|15
end_define

begin_define
define|#
directive|define
name|TEXT
parameter_list|(
name|t
parameter_list|)
value|( ((t)<= CENTCENT) || ((t)>= TOPLEFT) )
end_define

begin_comment
comment|/* WARNING * WARNING * WARNING * WARNING * WARNING * WARNING * WARNING   *    The above (TEXT) test is dependent on the relative values of the   *    constants and will have to change if these values change or if new  *    commands are added with value greater than BOTCENT  */
end_comment

begin_define
define|#
directive|define
name|RFONT
value|0
end_define

begin_define
define|#
directive|define
name|IFONT
value|1
end_define

begin_define
define|#
directive|define
name|BFONT
value|2
end_define

begin_define
define|#
directive|define
name|SFONT
value|3
end_define

begin_define
define|#
directive|define
name|NOADJ
value|0
end_define

begin_define
define|#
directive|define
name|HORZ
value|1
end_define

begin_define
define|#
directive|define
name|VERT
value|2
end_define

begin_define
define|#
directive|define
name|MAN
value|3
end_define

begin_define
define|#
directive|define
name|NUSER
value|4
end_define

begin_define
define|#
directive|define
name|NFONTS
value|4
end_define

begin_define
define|#
directive|define
name|NBRUSHES
value|6
end_define

begin_define
define|#
directive|define
name|NSIZES
value|4
end_define

begin_define
define|#
directive|define
name|NSTIPPLES
value|8
end_define

begin_define
define|#
directive|define
name|NJUSTS
value|9
end_define

begin_define
define|#
directive|define
name|JUSTMODES
value|17
end_define

begin_define
define|#
directive|define
name|ADD
value|1
end_define

begin_define
define|#
directive|define
name|DELETE
value|2
end_define

begin_define
define|#
directive|define
name|MOD
value|3
end_define

begin_define
define|#
directive|define
name|Delimiter
parameter_list|(
name|c
parameter_list|)
value|((c == '\0') || (c == ' ') || (c == '\t'))
end_define

begin_define
define|#
directive|define
name|MINMAX
parameter_list|(
name|min
parameter_list|,
name|max
parameter_list|,
name|val
parameter_list|)
value|if (val< min) \ 				    min = val; \ 				else if (val> max) \ 				    max = val;
end_define

begin_comment
comment|/* The following represents the maximum distance a point may be from another  * and still be affected by gravity.  The distance is represented as the  * square of the number of pixels (32) of the actual distance.    */
end_comment

begin_define
define|#
directive|define
name|MAXGDIST
value|1024
end_define

begin_comment
comment|/* 32 * 32 */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|point
block|{
name|float
name|x
decl_stmt|,
name|y
decl_stmt|;
name|struct
name|point
modifier|*
name|nextpt
decl_stmt|;
block|}
name|POINT
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|elmt
block|{
name|int
name|type
decl_stmt|,
name|brushf
decl_stmt|,
name|size
decl_stmt|,
name|textlength
decl_stmt|;
name|char
modifier|*
name|textpt
decl_stmt|;
name|POINT
modifier|*
name|ptlist
decl_stmt|;
name|struct
name|elmt
modifier|*
name|nextelt
decl_stmt|,
modifier|*
name|setnext
decl_stmt|;
block|}
name|ELT
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|unlt
block|{
name|int
name|action
decl_stmt|;
name|ELT
argument_list|*
operator|(
operator|*
name|dbase
operator|)
argument_list|,
operator|*
name|oldelt
argument_list|,
operator|*
name|newelt
argument_list|;
expr|struct
name|unlt
operator|*
name|nextun
argument_list|;
block|}
name|UNELT
typedef|;
end_typedef

begin_comment
comment|/*   * database macros  */
end_comment

begin_define
define|#
directive|define
name|DBInit
parameter_list|()
value|((ELT *) NULL)
end_define

begin_define
define|#
directive|define
name|DBNextElt
parameter_list|(
name|elt
parameter_list|)
value|((elt)->nextelt)
end_define

begin_define
define|#
directive|define
name|DBNextofSet
parameter_list|(
name|elt
parameter_list|)
value|((elt)->setnext)
end_define

begin_define
define|#
directive|define
name|DBNullelt
parameter_list|(
name|elt
parameter_list|)
value|((elt) == NULL)
end_define

begin_define
define|#
directive|define
name|PTInit
parameter_list|()
value|((POINT *) NULL)
end_define

begin_define
define|#
directive|define
name|PTNextPoint
parameter_list|(
name|pt
parameter_list|)
value|((pt)->nextpt)
end_define

begin_define
define|#
directive|define
name|Nullpoint
parameter_list|(
name|pt
parameter_list|)
value|((pt) == (POINT *) NULL)
end_define

begin_comment
comment|/* sun version parameters */
end_comment

begin_comment
comment|/* icon display parameters */
end_comment

begin_define
define|#
directive|define
name|ICON_SIZE
value|16
end_define

begin_define
define|#
directive|define
name|ICON_BORDER
value|8
end_define

begin_define
define|#
directive|define
name|MENU_TOP
value|0
end_define

begin_comment
comment|/* 17 */
end_comment

begin_define
define|#
directive|define
name|MENU_LEFT
value|0
end_define

begin_define
define|#
directive|define
name|MENU_RIGHT
value|104
end_define

begin_define
define|#
directive|define
name|MENU_BOTTOM
value|1000
end_define

begin_define
define|#
directive|define
name|MENU_COLUMNS
value|4
end_define

begin_define
define|#
directive|define
name|MENU_X
value|(ICON_SIZE + ICON_BORDER)
end_define

begin_define
define|#
directive|define
name|MENU_Y
value|(ICON_SIZE + ICON_BORDER)
end_define

begin_comment
comment|/* subwindow stuff */
end_comment

begin_define
define|#
directive|define
name|TEXTSW_HEIGHT
value|33
end_define

begin_define
define|#
directive|define
name|MENUSW_WIDTH
value|104
end_define

begin_define
define|#
directive|define
name|PIXSW_WIDTH
value|512
end_define

begin_define
define|#
directive|define
name|PIXSW_HEIGHT
value|512
end_define

begin_define
define|#
directive|define
name|stipple1_pr
value|white_pr
end_define

begin_define
define|#
directive|define
name|stipple2_pr
value|gray_pr
end_define

begin_define
define|#
directive|define
name|stipple3_pr
value|_50_pr
end_define

begin_define
define|#
directive|define
name|stipple4_pr
value|black_pr
end_define

begin_define
define|#
directive|define
name|is_stipple
parameter_list|(
name|pr
parameter_list|)
value|(((pr) ==&stipple1_pr) || ((pr) ==&stipple2_pr) || \ 			 ((pr) ==&stipple3_pr) || ((pr) ==&stipple4_pr) || \ 			 ((pr) ==&stipple5_pr) || ((pr) ==&stipple6_pr) || \ 			 ((pr) ==&stipple7_pr) || ((pr) ==&stipple8_pr))
end_define

begin_define
define|#
directive|define
name|winx_to_db
parameter_list|(
name|x
parameter_list|)
value|((float) ((x) + SUN_XORIGIN))
end_define

begin_define
define|#
directive|define
name|winy_to_db
parameter_list|(
name|y
parameter_list|)
value|((float) (SUN_YORIGIN - (y)))
end_define

begin_define
define|#
directive|define
name|dbx_to_win
parameter_list|(
name|x
parameter_list|)
value|(((int) (x)) - SUN_XORIGIN)
end_define

begin_define
define|#
directive|define
name|dby_to_win
parameter_list|(
name|y
parameter_list|)
value|(SUN_YORIGIN  - ((int) (y)))
end_define

begin_struct
struct|struct
name|_menu
block|{
name|int
name|menu_x
decl_stmt|;
comment|/* icon x coordinate */
name|int
name|menu_y
decl_stmt|;
comment|/* icon y coordinate */
name|struct
name|pixrect
modifier|*
name|menu_icon
decl_stmt|;
comment|/* icon pixrect pointer */
name|int
function_decl|(
modifier|*
name|menu_function
function_decl|)
parameter_list|()
function_decl|;
comment|/* left button function */
name|int
function_decl|(
modifier|*
name|menu_modify
function_decl|)
parameter_list|()
function_decl|;
comment|/* middle button function */
name|int
function_decl|(
modifier|*
name|menu_help
function_decl|)
parameter_list|()
function_decl|;
comment|/* right button function */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|TEXT_BASELINE
value|10
end_define

begin_define
define|#
directive|define
name|TEXT_BUFMAX
value|128
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|TRUE
end_ifndef

begin_define
define|#
directive|define
name|TRUE
value|(1)
end_define

begin_define
define|#
directive|define
name|FALSE
value|(0)
end_define

begin_endif
endif|#
directive|endif
end_endif

end_unit

