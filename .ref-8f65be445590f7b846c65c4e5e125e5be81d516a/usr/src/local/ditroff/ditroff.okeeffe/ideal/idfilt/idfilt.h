begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* idfilt.h	(CWI)	1.1	85/03/01 */
end_comment

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_decl_stmt
specifier|extern
name|FILE
modifier|*
name|infile
decl_stmt|;
end_decl_stmt

begin_function_decl
specifier|extern
name|void
name|idjusttext
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|idstart
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|idmaxx
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|idmaxy
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|idminx
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|idminy
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|idendbound
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|idwidth
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|idcolwid
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|idline
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|idcircle
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|idarc
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|idleft
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|idcenter
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|idright
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|idendE
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|idendF
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|idspline
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|idknot
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|idendspline
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|idyeserase
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|idnoerase
parameter_list|()
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|round
parameter_list|(
name|x
parameter_list|)
value|((int) ((x) + 0.5))
end_define

begin_define
define|#
directive|define
name|abs
parameter_list|(
name|x
parameter_list|)
value|((x)>0?(x):-(x))
end_define

begin_define
define|#
directive|define
name|boolean
value|int
end_define

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

begin_decl_stmt
specifier|extern
name|boolean
name|wanterase
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|boolean
name|wantquality
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|float
name|maxx
decl_stmt|,
name|maxy
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|float
name|minx
decl_stmt|,
name|miny
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|float
name|xscale
decl_stmt|,
name|yscale
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|float
name|width
decl_stmt|,
name|colwid
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|boolean
name|boundset
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|boolean
name|widset
decl_stmt|,
name|colset
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|boolean
name|minxset
decl_stmt|,
name|maxxset
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|boolean
name|minyset
decl_stmt|,
name|maxyset
decl_stmt|;
end_decl_stmt

end_unit

