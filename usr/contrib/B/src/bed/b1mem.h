begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Copyright (c) Stichting Mathematisch Centrum, Amsterdam, 1984. */
end_comment

begin_comment
comment|/*   $Header: b1mem.h,v 1.1 85/08/22 15:44:29 timo Exp $ */
end_comment

begin_comment
comment|/* bmem.h: B memory management */
end_comment

begin_typedef
typedef|typedef
name|char
modifier|*
name|ptr
typedef|;
end_typedef

begin_define
define|#
directive|define
name|Nil
value|((ptr) 0)
end_define

begin_define
define|#
directive|define
name|getmem
value|get_mem
end_define

begin_function_decl
name|ptr
name|getmem
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* Procedure regetmem(); */
end_comment

begin_comment
comment|/* Procedure freemem(); */
end_comment

begin_comment
comment|/* Procedure prgr(); */
end_comment

begin_comment
comment|/* Procedure initmem(); */
end_comment

begin_decl_stmt
specifier|extern
name|value
name|notel
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*TEMPORARY*/
end_comment

begin_decl_stmt
specifier|extern
name|bool
name|noting
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*TEMPORARY*/
end_comment

end_unit

