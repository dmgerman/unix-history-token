begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	gprint.h	1.2	83/03/02  *  * This file contains standard definitions used by the gprint program.  */
end_comment

begin_define
define|#
directive|define
name|poffset
value|( (device == 'V') ? 10 : 117 )
end_define

begin_define
define|#
directive|define
name|Ymax
value|483
end_define

begin_define
define|#
directive|define
name|Xmax
value|511
end_define

begin_define
define|#
directive|define
name|xorn
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
value|Orientation ? (y) : (x)
end_define

begin_define
define|#
directive|define
name|yorn
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
value|Orientation ? (Ymax - ((x) - poffset)) : (y)
end_define

begin_define
define|#
directive|define
name|mapx
parameter_list|(
name|x
parameter_list|)
value|((DevRange*(((x) * scale)-botx)/del)+centx)
end_define

begin_define
define|#
directive|define
name|mapy
parameter_list|(
name|y
parameter_list|)
value|((DevRange*(del-((y) * scale)+boty)/del)-centy)
end_define

begin_define
define|#
directive|define
name|STYLES
value|6
end_define

begin_define
define|#
directive|define
name|SIZES
value|4
end_define

begin_define
define|#
directive|define
name|FONTS
value|4
end_define

begin_define
define|#
directive|define
name|SOLID
value|-1
end_define

begin_define
define|#
directive|define
name|DOTTED
value|004
end_define

begin_comment
comment|/* 014 */
end_comment

begin_define
define|#
directive|define
name|DASHED
value|020
end_define

begin_comment
comment|/* 034 */
end_comment

begin_define
define|#
directive|define
name|DOTDASHED
value|024
end_define

begin_comment
comment|/* 054 */
end_comment

begin_define
define|#
directive|define
name|LONGDASHED
value|074
end_define

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
name|TRUE
value|1
end_define

begin_define
define|#
directive|define
name|FALSE
value|0
end_define

begin_define
define|#
directive|define
name|nullelt
value|-1
end_define

begin_define
define|#
directive|define
name|nullpt
value|-1
end_define

begin_define
define|#
directive|define
name|nullun
value|NULL
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
value|( (t<= CENTCENT) || (t>= TOPLEFT) )
end_define

begin_comment
comment|/* WARNING * WARNING * WARNING * WARNING * WARNING * WARNING * WARNING   *    The above (TEXT) test is dependent on the relative values of the   *    constants and will have to change if these values change or if new  *    commands are added with value greater than BOTCENT  */
end_comment

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
name|NJUSTS
value|9
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

begin_typedef
typedef|typedef
struct|struct
block|{
name|int
name|tx_x
decl_stmt|;
comment|/* First column of field */
name|int
name|tx_y
decl_stmt|;
comment|/* Row containing field */
name|int
name|tx_size
decl_stmt|;
comment|/* Size of field in characters */
block|}
name|TXFIELD
typedef|;
end_typedef

end_unit

