begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Copyright (c) Stichting Mathematisch Centrum, Amsterdam, 1984. */
end_comment

begin_comment
comment|/* $Header: b.h,v 2.2 85/08/22 15:59:55 timo Exp $ */
end_comment

begin_comment
comment|/*  * B editor -- Basics copied from B interpreter's run-time system.  */
end_comment

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_define
define|#
directive|define
name|Visible
end_define

begin_define
define|#
directive|define
name|Hidden
value|static
end_define

begin_define
define|#
directive|define
name|Procedure
end_define

begin_typedef
typedef|typedef
name|int
name|bool
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|short
name|intlet
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|char
modifier|*
name|string
typedef|;
end_typedef

begin_define
define|#
directive|define
name|No
value|0
end_define

begin_define
define|#
directive|define
name|Yes
value|1
end_define

begin_define
define|#
directive|define
name|Maxintlet
value|((1<<15)-1)
end_define

begin_comment
comment|/* MACHINE DEPENDENT */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|char
name|type
decl_stmt|;
name|char
name|_unused
decl_stmt|;
name|intlet
name|refcnt
decl_stmt|;
name|intlet
name|len
decl_stmt|;
name|string
modifier|*
name|cts
decl_stmt|;
block|}
typedef|*
name|value
typedef|;
end_typedef

begin_comment
comment|/* See also definitions in node.h and queu.h which must match the first    four fields of 'value'! */
end_comment

begin_define
define|#
directive|define
name|Refcnt
parameter_list|(
name|v
parameter_list|)
value|((v)->refcnt)
end_define

begin_define
define|#
directive|define
name|Type
parameter_list|(
name|v
parameter_list|)
value|((v)->type)
end_define

begin_define
define|#
directive|define
name|Length
parameter_list|(
name|v
parameter_list|)
value|((v)->len)
end_define

begin_define
define|#
directive|define
name|Str
parameter_list|(
name|v
parameter_list|)
value|((char*)(&(v)->cts))
end_define

begin_define
define|#
directive|define
name|Vnil
value|((value) NULL)
end_define

begin_comment
comment|/* Types: */
end_comment

begin_define
define|#
directive|define
name|Num
value|'0'
end_define

begin_define
define|#
directive|define
name|Tex
value|'"'
end_define

begin_define
define|#
directive|define
name|Com
value|','
end_define

begin_define
define|#
directive|define
name|Nod
value|'N'
end_define

begin_define
define|#
directive|define
name|Pat
value|'P'
end_define

begin_comment
comment|/*  * C library standard functions  */
end_comment

begin_function_decl
name|string
name|malloc
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|string
name|realloc
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|string
name|sprintf
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|string
name|strcpy
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|string
name|strncpy
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|string
name|index
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|string
name|rindex
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|string
name|getenv
parameter_list|()
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|Strequ
parameter_list|(
name|s
parameter_list|,
name|t
parameter_list|)
value|!strcmp(s, t)
end_define

begin_define
define|#
directive|define
name|Strnequ
parameter_list|(
name|s
parameter_list|,
name|t
parameter_list|,
name|n
parameter_list|)
value|!strncmp(s, t, n)
end_define

end_unit

