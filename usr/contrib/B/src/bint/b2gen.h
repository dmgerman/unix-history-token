begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Copyright (c) Stichting Mathematisch Centrum, Amsterdam, 1985. */
end_comment

begin_comment
comment|/*   $Header: b2gen.h,v 1.4 85/08/22 16:42:31 timo Exp $ */
end_comment

begin_define
define|#
directive|define
name|Is_node
parameter_list|(
name|t
parameter_list|)
value|((t) != NilTree&& Is_parsetree(t))
end_define

begin_decl_stmt
specifier|extern
name|int
name|nextvarnumber
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Counts local targets (including formals) */
end_comment

begin_decl_stmt
specifier|extern
name|value
name|formals
decl_stmt|,
name|locals
decl_stmt|,
name|globals
decl_stmt|,
name|mysteries
decl_stmt|,
name|refinements
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|string
name|gentab
index|[]
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|NTYPES
value|(FORMAL+1)
end_define

begin_struct
struct|struct
name|state
block|{
name|parsetree
name|h_last
decl_stmt|;
name|parsetree
modifier|*
name|h_wanthere
decl_stmt|;
name|parsetree
name|h_bpchain
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|f_expr
parameter_list|(
name|p
parameter_list|)
value|fix(p, 'v')
end_define

begin_comment
comment|/* "evaluate" */
end_comment

begin_define
define|#
directive|define
name|f_targ
parameter_list|(
name|p
parameter_list|)
value|fix(p, 'l')
end_define

begin_comment
comment|/* "locate" */
end_comment

begin_function_decl
name|value
name|copydef
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|bool
name|modify_tag
parameter_list|()
function_decl|;
end_function_decl

end_unit

