begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_empty
empty|#
end_empty

begin_comment
comment|/* gsi plotting output routines */
end_comment

begin_define
define|#
directive|define
name|DOWN
value|012
end_define

begin_define
define|#
directive|define
name|UP
value|013
end_define

begin_define
define|#
directive|define
name|LEFT
value|010
end_define

begin_define
define|#
directive|define
name|RIGHT
value|040
end_define

begin_define
define|#
directive|define
name|BEL
value|007
end_define

begin_define
define|#
directive|define
name|ESC
value|033
end_define

begin_define
define|#
directive|define
name|ACK
value|006
end_define

begin_define
define|#
directive|define
name|PLOTIN
value|063
end_define

begin_define
define|#
directive|define
name|PLOTOUT
value|064
end_define

begin_define
define|#
directive|define
name|CR
value|015
end_define

begin_define
define|#
directive|define
name|FF
value|014
end_define

begin_define
define|#
directive|define
name|VERTRESP
value|48
end_define

begin_define
define|#
directive|define
name|HORZRESP
value|60.
end_define

begin_define
define|#
directive|define
name|VERTRES
value|8.
end_define

begin_define
define|#
directive|define
name|HORZRES
value|6.
end_define

begin_comment
comment|/* down is line feed, up is reverse line feed,    left is backspace, right is space.  48 points per inch    vertically, 60 horizontally */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|xnow
decl_stmt|,
name|ynow
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|ITTY
index|[
literal|3
index|]
decl_stmt|,
name|PTTY
index|[
literal|3
index|]
decl_stmt|,
name|OUTF
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|float
name|HEIGHT
decl_stmt|,
name|WIDTH
decl_stmt|,
name|OFFSET
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|xscale
decl_stmt|,
name|xoffset
decl_stmt|,
name|yscale
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|float
name|botx
decl_stmt|,
name|boty
decl_stmt|,
name|obotx
decl_stmt|,
name|oboty
decl_stmt|,
name|scalex
decl_stmt|,
name|scaley
decl_stmt|;
end_decl_stmt

end_unit

