begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Copyright (c) Stichting Mathematisch Centrum, Amsterdam, 1984. */
end_comment

begin_comment
comment|/* $Header: b2scr.h,v 1.1 84/06/28 00:48:49 timo Exp $ */
end_comment

begin_comment
comment|/* bscr.h: screen */
end_comment

begin_decl_stmt
specifier|extern
name|bool
name|interactive
decl_stmt|,
name|read_interactive
decl_stmt|,
name|outeractive
decl_stmt|,
name|filtered
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|bool
name|Eof
decl_stmt|,
name|Eof0
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|FILE
modifier|*
name|ifile
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|value
name|iname
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|jmp_buf
name|reading
index|[]
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|MAX_NMB_ACT_READS
value|10
end_define

begin_decl_stmt
specifier|extern
name|intlet
name|active_reads
decl_stmt|;
end_decl_stmt

begin_function_decl
name|bool
name|is_intended
parameter_list|()
function_decl|;
end_function_decl

begin_decl_stmt
name|bool
name|at_nwl
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Procedure redirect(); */
end_comment

begin_comment
comment|/* Procedure newline(); */
end_comment

begin_comment
comment|/* Procedure line(); */
end_comment

begin_comment
comment|/* Procedure wri_space(); */
end_comment

begin_comment
comment|/* Procedure writ(); */
end_comment

begin_comment
comment|/* Procedure wri(); */
end_comment

begin_decl_stmt
specifier|extern
name|FILE
modifier|*
name|sv_ifile
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*TEMPORARY for syn*/
end_comment

begin_comment
comment|/* Procedure re_files(); */
end_comment

begin_comment
comment|/* Procedure vs_ifile(); */
end_comment

begin_comment
comment|/* Procedure initscr(); */
end_comment

begin_comment
comment|/* Procedure re_screen(); */
end_comment

begin_decl_stmt
specifier|extern
name|string
name|cmd_prompt
decl_stmt|,
name|eg_prompt
decl_stmt|,
name|raw_prompt
decl_stmt|,
name|qn_prompt
decl_stmt|;
end_decl_stmt

end_unit

