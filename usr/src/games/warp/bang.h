begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $Header: bang.h,v 7.0 86/10/08 15:12:03 lwall Exp $ */
end_comment

begin_comment
comment|/* $Log:	bang.h,v $  * Revision 7.0  86/10/08  15:12:03  lwall  * Split into separate files.  Added amoebas and pirates.  *   */
end_comment

begin_decl_stmt
name|EXT
name|long
name|blast
index|[
name|YSIZE
index|]
index|[
name|XSIZE
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|EXT
name|bool
name|blasted
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|EXT
name|bool
name|xblasted
index|[
name|XSIZE
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|EXT
name|bool
name|yblasted
index|[
name|YSIZE
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|EXT
name|char
name|bangy
index|[
name|YSIZE
operator|*
name|XSIZE
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|EXT
name|char
name|bangx
index|[
name|YSIZE
operator|*
name|XSIZE
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|EXT
name|char
name|bangs
index|[
name|YSIZE
operator|*
name|XSIZE
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|EXT
name|long
name|bangm
index|[
name|YSIZE
operator|*
name|XSIZE
index|]
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|MAXBDIST
value|40
end_define

begin_decl_stmt
name|EXT
name|int
name|xx
index|[
name|MAXBDIST
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|EXT
name|int
name|yy
index|[
name|MAXBDIST
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|EXT
name|int
name|nxtbang
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|EXT
name|bool
name|banging
decl_stmt|;
end_decl_stmt

begin_function_decl
name|void
name|make_plink
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|make_blast
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|do_bangs
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|bang_init
parameter_list|()
function_decl|;
end_function_decl

end_unit

