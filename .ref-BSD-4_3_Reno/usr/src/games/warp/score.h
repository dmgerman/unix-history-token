begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $Header: score.h,v 7.0 86/10/08 15:13:21 lwall Exp $ */
end_comment

begin_comment
comment|/* $Log:	score.h,v $  * Revision 7.0  86/10/08  15:13:21  lwall  * Split into separate files.  Added amoebas and pirates.  *   */
end_comment

begin_define
define|#
directive|define
name|ENTBOUNDARY
value|100000
end_define

begin_comment
comment|/*  point boundary across which a new E is 					awarded */
end_comment

begin_define
define|#
directive|define
name|BASEBOUNDARY
value|250000
end_define

begin_comment
comment|/*  point boundary across which a new B is 					awarded */
end_comment

begin_decl_stmt
name|EXT
name|int
name|oldstatus
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|EXT
name|int
name|oldetorp
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|EXT
name|int
name|oldbtorp
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|EXT
name|int
name|oldstrs
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|EXT
name|int
name|oldenemies
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|EXT
name|long
name|totalscore
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|EXT
name|long
name|lastscore
name|INIT
argument_list|(
literal|0
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|EXT
name|long
name|curscore
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|EXT
name|long
name|possiblescore
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|EXT
name|long
name|oldeenergy
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|EXT
name|long
name|oldbenergy
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|EXT
name|long
name|oldcurscore
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|EXT
name|char
name|savefilename
index|[
literal|40
index|]
decl_stmt|;
end_decl_stmt

begin_ifdef
ifdef|#
directive|ifdef
name|SCOREFULL
end_ifdef

begin_define
define|#
directive|define
name|COMPOFF
value|0
end_define

begin_define
define|#
directive|define
name|COMPNAME
value|longlognam
end_define

begin_define
define|#
directive|define
name|COMPLEN
value|24
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|COMPOFF
value|24
end_define

begin_define
define|#
directive|define
name|COMPNAME
value|longlognam
end_define

begin_define
define|#
directive|define
name|COMPLEN
value|8
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
name|EXT
name|char
name|longlognam
index|[
literal|128
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|EXT
name|char
name|c
name|INIT
argument_list|(
literal|' '
argument_list|)
decl_stmt|;
end_decl_stmt

begin_function_decl
name|void
name|score_init
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|wscore
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|display_status
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|wavescore
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|score
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|save_game
parameter_list|()
function_decl|;
end_function_decl

end_unit

