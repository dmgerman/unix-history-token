begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Copyright (c) Stichting Mathematisch Centrum, Amsterdam, 1985. */
end_comment

begin_comment
comment|/*   $Header: b1tlt.h,v 1.4 85/08/22 16:42:12 timo Exp $ */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|INTEGRATION
end_ifndef

begin_comment
comment|/* Private definitions for B texts, lists and tables */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|telita
block|{
name|HEADER
expr_stmt|;
name|btreeptr
name|root
decl_stmt|;
block|}
name|a_telita
operator|,
typedef|*
name|telita
typedef|;
end_typedef

begin_define
define|#
directive|define
name|Itemtype
parameter_list|(
name|v
parameter_list|)
value|(((telita) (v))->len)
end_define

begin_comment
comment|/* Itemtype */
end_comment

begin_define
define|#
directive|define
name|Root
parameter_list|(
name|v
parameter_list|)
value|(((telita) (v))->root)
end_define

begin_define
define|#
directive|define
name|Tltsize
parameter_list|(
name|v
parameter_list|)
value|(Root(v) EQ Bnil ? 0 : Size(Root(v)))
end_define

begin_define
define|#
directive|define
name|Character
parameter_list|(
name|v
parameter_list|)
value|((bool) (Type(v) EQ Tex&& Tltsize(v) EQ 1))
end_define

begin_function_decl
name|value
name|mkchar
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* char c */
end_comment

begin_else
else|#
directive|else
else|INTEGRATION
end_else

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

begin_endif
endif|#
directive|endif
endif|INTEGRATION
end_endif

end_unit

