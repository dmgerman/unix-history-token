begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * @(#)gremlin.h	1.1	%G%  *  * Gremlin library routines header file -   * for use with /usr/local/lib/libgremlin.a  *  * Mark Opperman (opcode@monet.BERKELEY)  *  */
end_comment

begin_function_decl
specifier|extern
name|FILE
modifier|*
name|gr_open
parameter_list|()
function_decl|;
end_function_decl

begin_extern
extern|extern gr_close(
end_extern

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

begin_extern
extern|extern gr_vector(
end_extern

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

begin_extern
extern|extern gr_curve(
end_extern

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

begin_extern
extern|extern gr_arc(
end_extern

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

begin_extern
extern|extern gr_circle(
end_extern

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

begin_extern
extern|extern gr_polygon(
end_extern

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

begin_extern
extern|extern gr_text(
end_extern

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

begin_define
define|#
directive|define
name|GR_ERROR
value|-1
end_define

begin_define
define|#
directive|define
name|GR_OK
value|0
end_define

begin_define
define|#
directive|define
name|SUN_GREMLIN
value|0
end_define

begin_define
define|#
directive|define
name|AED_GREMLIN
value|1
end_define

begin_define
define|#
directive|define
name|HORZ_ORIENT
value|0
end_define

begin_define
define|#
directive|define
name|VERT_ORIENT
value|1
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
name|DOTTED
value|1
end_define

begin_define
define|#
directive|define
name|DOTDASHED
value|2
end_define

begin_define
define|#
directive|define
name|THICK
value|3
end_define

begin_define
define|#
directive|define
name|DASHED
value|4
end_define

begin_define
define|#
directive|define
name|NARROW
value|5
end_define

begin_define
define|#
directive|define
name|MEDIUM
value|6
end_define

end_unit

