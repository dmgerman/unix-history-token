begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  *  Top - a top users display for Berkeley Unix  *  *  This file defines the locations on tne screen for various parts of the  *  display.  These definitions are used by the routines in "display.c" for  *  cursor addressing.  *  * $FreeBSD$  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|x_lastpid
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* 10 */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|y_lastpid
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* 0 */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|x_loadave
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* 33 */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|x_loadave_nompid
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* 15 */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|y_loadave
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* 0 */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|x_procstate
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* 0 */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|y_procstate
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* 1 */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|x_brkdn
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* 15 */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|y_brkdn
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* 1 */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|x_mem
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* 5 */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|y_mem
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* 3 */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|x_arc
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* 5 */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|y_arc
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* 4 */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|x_carc
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* 5 */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|y_carc
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* 5 */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|x_swap
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* 6 */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|y_swap
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* 4 */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|y_message
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* 5 */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|x_header
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* 0 */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|y_header
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* 6 */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|x_idlecursor
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* 0 */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|y_idlecursor
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* 5 */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|y_procs
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* 7 */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|y_cpustates
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* 2 */
end_comment

end_unit

