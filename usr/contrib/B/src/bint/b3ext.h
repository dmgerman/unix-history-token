begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Copyright (c) Stichting Mathematisch Centrum, Amsterdam, 1985. */
end_comment

begin_comment
comment|/*   $Header: b3ext.h,v 1.4 85/08/22 16:43:52 timo Exp $ */
end_comment

begin_define
define|#
directive|define
name|MAXEARGS
value|10
end_define

begin_typedef
typedef|typedef
struct|struct
name|ext
block|{
name|string
name|e_name
decl_stmt|;
name|string
name|e_args
index|[
name|MAXEARGS
index|]
decl_stmt|;
name|int
function_decl|(
modifier|*
name|e_exec
function_decl|)
parameter_list|()
function_decl|;
comment|/* should be void, but portability... */
block|}
name|ext
typedef|;
end_typedef

begin_decl_stmt
specifier|extern
name|ext
name|extensions
index|[]
decl_stmt|;
end_decl_stmt

end_unit

