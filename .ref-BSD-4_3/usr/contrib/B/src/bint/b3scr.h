begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Copyright (c) Stichting Mathematisch Centrum, Amsterdam, 1985. */
end_comment

begin_comment
comment|/*   $Header: b3scr.h,v 1.4 85/08/22 16:44:19 timo Exp $ */
end_comment

begin_comment
comment|/* screen */
end_comment

begin_decl_stmt
specifier|extern
name|bool
name|interactive
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|bool
name|rd_interactive
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
name|bool
name|filtered
decl_stmt|;
end_decl_stmt

begin_ifndef
ifndef|#
directive|ifndef
name|INTEGRATION
end_ifndef

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

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|INTEGRATION
end_ifdef

begin_decl_stmt
specifier|extern
name|literal
name|unit_prompt
decl_stmt|,
name|tar_prompt
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
specifier|extern
name|FILE
modifier|*
name|ifile
decl_stmt|;
end_decl_stmt

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

begin_decl_stmt
specifier|extern
name|bool
name|outeractive
decl_stmt|,
name|Eof
decl_stmt|,
name|at_nwl
decl_stmt|;
end_decl_stmt

begin_function_decl
name|bool
name|is_intended
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|txptr
name|getline
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* Procedure redirect(); */
end_comment

begin_comment
comment|/* Procedure newline(); */
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

end_unit

