begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1993 David I. Bell  * Permission is granted to use, distribute, or modify this source,  * provided that this copyright notice remains intact.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|SYMBOL_H
end_ifndef

begin_define
define|#
directive|define
name|SYMBOL_H
end_define

begin_include
include|#
directive|include
file|"zmath.h"
end_include

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
comment|/* parameter symbol */
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

begin_define
define|#
directive|define
name|SYM_STATIC
value|4
end_define

begin_comment
comment|/* static symbol */
end_comment

begin_define
define|#
directive|define
name|SCOPE_GLOBAL
value|0
end_define

begin_comment
comment|/* file scope level for global variables */
end_comment

begin_define
define|#
directive|define
name|SCOPE_STATIC
value|1
end_define

begin_comment
comment|/* lowest file scope for static variables */
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
name|short
name|g_filescope
decl_stmt|;
comment|/* file scope level of symbol (0 if global) */
name|short
name|g_funcscope
decl_stmt|;
comment|/* function scope level of symbol */
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
name|MATH_PROTO
argument_list|(
operator|(
name|char
operator|*
name|name
operator|,
name|BOOL
name|isstatic
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|GLOBAL
modifier|*
name|findglobal
name|MATH_PROTO
argument_list|(
operator|(
name|char
operator|*
name|name
operator|)
argument_list|)
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
name|MATH_PROTO
argument_list|(
operator|(
name|long
name|n
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|paramname
name|MATH_PROTO
argument_list|(
operator|(
name|long
name|n
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|globalname
name|MATH_PROTO
argument_list|(
operator|(
name|GLOBAL
operator|*
name|sp
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * Routines to handle entering and leaving of scope levels.  */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|resetscopes
name|MATH_PROTO
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|enterfilescope
name|MATH_PROTO
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|exitfilescope
name|MATH_PROTO
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|enterfuncscope
name|MATH_PROTO
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|exitfuncscope
name|MATH_PROTO
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * Other routines.  */
end_comment

begin_decl_stmt
specifier|extern
name|long
name|addlocal
name|MATH_PROTO
argument_list|(
operator|(
name|char
operator|*
name|name
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|long
name|findlocal
name|MATH_PROTO
argument_list|(
operator|(
name|char
operator|*
name|name
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|long
name|addparam
name|MATH_PROTO
argument_list|(
operator|(
name|char
operator|*
name|name
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|long
name|findparam
name|MATH_PROTO
argument_list|(
operator|(
name|char
operator|*
name|name
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|initlocals
name|MATH_PROTO
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|initglobals
name|MATH_PROTO
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|writeglobals
name|MATH_PROTO
argument_list|(
operator|(
name|char
operator|*
name|name
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|symboltype
name|MATH_PROTO
argument_list|(
operator|(
name|char
operator|*
name|name
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|showglobals
name|MATH_PROTO
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* END CODE */
end_comment

end_unit

