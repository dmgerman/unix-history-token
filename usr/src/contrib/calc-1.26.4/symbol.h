begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1993 David I. Bell  * Permission is granted to use, distribute, or modify this source,  * provided that this copyright notice remains intact.  */
end_comment

begin_comment
comment|/*  * Symbol Declarations.  */
end_comment

begin_define
define|#
directive|define
name|SYM_UNDEFINED
value|0
end_define

begin_comment
comment|/* undefined symbol */
end_comment

begin_define
define|#
directive|define
name|SYM_PARAM
value|1
end_define

begin_comment
comment|/* paramater symbol */
end_comment

begin_define
define|#
directive|define
name|SYM_LOCAL
value|2
end_define

begin_comment
comment|/* local symbol */
end_comment

begin_define
define|#
directive|define
name|SYM_GLOBAL
value|3
end_define

begin_comment
comment|/* global symbol */
end_comment

begin_typedef
typedef|typedef
name|struct
name|global
name|GLOBAL
typedef|;
end_typedef

begin_struct
struct|struct
name|global
block|{
name|int
name|g_len
decl_stmt|;
comment|/* length of symbol name */
name|char
modifier|*
name|g_name
decl_stmt|;
comment|/* global symbol name */
name|VALUE
name|g_value
decl_stmt|;
comment|/* global symbol value */
name|GLOBAL
modifier|*
name|g_next
decl_stmt|;
comment|/* next symbol in hash chain */
block|}
struct|;
end_struct

begin_comment
comment|/*  * Routines to search for global symbols.  */
end_comment

begin_decl_stmt
specifier|extern
name|GLOBAL
modifier|*
name|addglobal
argument_list|()
decl_stmt|,
modifier|*
name|findglobal
argument_list|()
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * Routines to return names of variables.  */
end_comment

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|localname
argument_list|()
decl_stmt|,
modifier|*
name|globalname
argument_list|()
decl_stmt|,
modifier|*
name|paramname
argument_list|()
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * Other routines.  */
end_comment

begin_decl_stmt
specifier|extern
name|long
name|addlocal
argument_list|()
decl_stmt|,
name|findlocal
argument_list|()
decl_stmt|,
name|addparam
argument_list|()
decl_stmt|,
name|findparam
argument_list|()
decl_stmt|;
end_decl_stmt

begin_function_decl
specifier|extern
name|void
name|initlocals
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|initglobals
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|initfunctions
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|writeglobals
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|symboltype
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* return the type of a variable name */
end_comment

begin_function_decl
specifier|extern
name|void
name|showglobals
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* show the value of all global variables */
end_comment

begin_comment
comment|/* END CODE */
end_comment

end_unit

