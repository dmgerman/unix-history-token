begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_include
include|#
directive|include
file|"curses.h"
end_include

begin_decl_stmt
name|bool
name|_echoit
init|=
name|TRUE
decl_stmt|,
comment|/* set if stty indicates ECHO		*/
name|_rawmode
init|=
name|FALSE
decl_stmt|,
comment|/* set if stty indicates RAW mode	*/
name|My_term
init|=
name|FALSE
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* set if user specifies terminal type	*/
end_comment

begin_decl_stmt
name|char
name|ttytype
index|[
literal|10
index|]
decl_stmt|,
comment|/* long name of tty			*/
modifier|*
name|Def_term
init|=
literal|"un"
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* default terminal type		*/
end_comment

begin_decl_stmt
name|int
name|_tty_ch
init|=
literal|1
decl_stmt|,
comment|/* file channel which is a tty		*/
name|LINES
decl_stmt|,
comment|/* number of lines allowed on screen	*/
name|COLS
decl_stmt|,
comment|/* number of columns allowed on screen	*/
name|_res_flg
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* sgtty flags for reseting later	*/
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|DEBUG
end_ifdef

begin_decl_stmt
name|FILE
modifier|*
name|outf
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* debug output file			*/
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
name|SGTTY
name|_tty
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* tty modes				*/
end_comment

end_unit

