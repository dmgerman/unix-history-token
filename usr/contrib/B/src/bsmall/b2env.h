begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Copyright (c) Stichting Mathematisch Centrum, Amsterdam, 1984. */
end_comment

begin_comment
comment|/* $Header: b2env.h,v 1.1 84/06/28 00:48:44 timo Exp $ */
end_comment

begin_comment
comment|/* environments and context */
end_comment

begin_comment
comment|/* Procedure sv_context(); */
end_comment

begin_comment
comment|/* Procedure set_context(); */
end_comment

begin_comment
comment|/* Procedure initenv(); */
end_comment

begin_comment
comment|/* Procedure re_env(); */
end_comment

begin_comment
comment|/* Procedure setprmnv(); */
end_comment

begin_comment
comment|/* Procedure extbnd_tags(); */
end_comment

begin_comment
comment|/* Procedure restore_env(); */
end_comment

begin_function_decl
name|value
modifier|*
name|lookup
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* Procedure e_replace(); */
end_comment

begin_comment
comment|/* Procedure e_delete(); */
end_comment

begin_function_decl
name|bool
name|in_env
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|value
modifier|*
name|envassoc
parameter_list|()
function_decl|;
end_function_decl

begin_decl_stmt
specifier|extern
name|env
name|curnv
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|value
modifier|*
name|bndtgs
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|literal
name|cntxt
decl_stmt|,
name|resexp
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|value
name|uname
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|literal
name|utype
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|intlet
name|cur_ilev
decl_stmt|,
name|lino
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|txptr
name|tx
decl_stmt|,
name|ceol
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|context
name|read_context
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|context
name|how_context
decl_stmt|;
end_decl_stmt

end_unit

