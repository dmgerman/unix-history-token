begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Copyright (c) Stichting Mathematisch Centrum, Amsterdam, 1984. */
end_comment

begin_comment
comment|/* $Header: bobj.h,v 2.0 84/06/18 15:46:31 guido Exp $ */
end_comment

begin_comment
comment|/*  * B editor -- Interface to "B machine".  */
end_comment

begin_comment
comment|/*  * General values.  */
end_comment

begin_function_decl
name|value
name|grab_com
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|value
name|copy
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/*  * Operations on texts.  */
end_comment

begin_function_decl
name|value
name|mk_text
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|value
name|trim
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|value
name|concat
parameter_list|()
function_decl|;
end_function_decl

end_unit

