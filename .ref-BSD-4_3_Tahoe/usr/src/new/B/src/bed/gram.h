begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Copyright (c) Stichting Mathematisch Centrum, Amsterdam, 1984. */
end_comment

begin_comment
comment|/* $Header: gram.h,v 2.0 84/06/18 15:46:55 guido Exp $ */
end_comment

begin_comment
comment|/*  * B editor -- Grammar symbols.  */
end_comment

begin_comment
comment|/*  * Values used in "tabl.c" but also publicly.  */
end_comment

begin_define
define|#
directive|define
name|Rootsymbol
value|00
end_define

begin_define
define|#
directive|define
name|Suggestion
value|97
end_define

begin_define
define|#
directive|define
name|Optional
value|98
end_define

begin_define
define|#
directive|define
name|Hole
value|99
end_define

begin_comment
comment|/*  * Ditto for "lexi.c".  */
end_comment

begin_define
define|#
directive|define
name|LEXICAL
value|100
end_define

begin_comment
comment|/*  * Routines defined in "gram.c".  */
end_comment

begin_function_decl
name|string
modifier|*
name|noderepr
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|node
name|gram
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|node
name|suggestion
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|node
name|variable
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|string
name|symname
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/*  * Macros for oft-used funtion.  */
end_comment

begin_define
define|#
directive|define
name|Fwidth
parameter_list|(
name|str
parameter_list|)
value|((str) ? fwidth(str) : 0)
end_define

begin_define
define|#
directive|define
name|Fw_zero
parameter_list|(
name|str
parameter_list|)
value|(!(str) || index("\b\t", (str)[0]))
end_define

begin_define
define|#
directive|define
name|Fw_positive
parameter_list|(
name|str
parameter_list|)
value|((str)&& (str)[0]>= ' ')
end_define

begin_define
define|#
directive|define
name|Fw_negative
parameter_list|(
name|str
parameter_list|)
value|((str)&& (str)[0] == '\n')
end_define

end_unit

