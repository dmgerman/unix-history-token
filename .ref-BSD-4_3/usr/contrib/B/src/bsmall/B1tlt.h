begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Copyright (c) Stichting Mathematisch Centrum, Amsterdam, 1984. */
end_comment

begin_comment
comment|/* $Header: B1tlt.h,v 1.1 84/06/28 00:48:39 timo Exp $ */
end_comment

begin_comment
comment|/************************************************************************/
end_comment

begin_comment
comment|/* Private definitions for small texts, lists and tables module         */
end_comment

begin_comment
comment|/* A text is modelled as a sequence of len characters.                  */
end_comment

begin_comment
comment|/*                                                                      */
end_comment

begin_comment
comment|/* A list is modelled as a sequence of len values,                      */
end_comment

begin_comment
comment|/*         each of which corresponds to a list entry.                   */
end_comment

begin_comment
comment|/*                                                                      */
end_comment

begin_comment
comment|/* A table is modelled as a sequence of len values,                     */
end_comment

begin_comment
comment|/*         each of which corresponds to a table entry;                  */
end_comment

begin_comment
comment|/*     table entries are modelled as a compound with two fields.        */
end_comment

begin_comment
comment|/************************************************************************/
end_comment

begin_define
define|#
directive|define
name|Cts
parameter_list|(
name|v
parameter_list|)
value|(*Ats(v))
end_define

begin_define
define|#
directive|define
name|Dts
parameter_list|(
name|v
parameter_list|)
value|(*(Ats(v)+1))
end_define

begin_define
define|#
directive|define
name|List_elem
parameter_list|(
name|l
parameter_list|,
name|i
parameter_list|)
value|(*(Ats(l)+i))
end_define

begin_comment
comment|/*counts from 0; takes no copy*/
end_comment

begin_define
define|#
directive|define
name|Key
parameter_list|(
name|t
parameter_list|,
name|i
parameter_list|)
value|(Ats(*(Ats(t)+i)))
end_define

begin_comment
comment|/*Ditto*/
end_comment

begin_define
define|#
directive|define
name|Assoc
parameter_list|(
name|t
parameter_list|,
name|i
parameter_list|)
value|(Ats(*(Ats(t)+i))+1)
end_define

begin_comment
comment|/*Ditto*/
end_comment

begin_function_decl
name|bool
name|found
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|value
name|list_elem
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|value
name|key_elem
parameter_list|()
function_decl|;
end_function_decl

end_unit

