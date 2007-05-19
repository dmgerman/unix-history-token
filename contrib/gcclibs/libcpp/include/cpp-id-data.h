begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Structures that hang off cpp_identifier, for PCH.    Copyright (C) 1986, 1987, 1989, 1992, 1993, 1994, 1995, 1996, 1997, 1998,    1999, 2000, 2001, 2002, 2003, 2004 Free Software Foundation, Inc.  This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2, or (at your option) any later version.  This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with this program; if not, write to the Free Software Foundation, 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301, USA.  */
end_comment

begin_include
include|#
directive|include
file|"cpplib.h"
end_include

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|HAVE_UCHAR
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|IN_GCC
argument_list|)
end_if

begin_typedef
typedef|typedef
name|unsigned
name|char
name|uchar
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|U
value|(const unsigned char *)
end_define

begin_comment
comment|/* Intended use: U"string" */
end_comment

begin_comment
comment|/* Chained list of answers to an assertion.  */
end_comment

begin_decl_stmt
name|struct
name|answer
name|GTY
argument_list|(
operator|(
operator|)
argument_list|)
block|{
name|struct
name|answer
modifier|*
name|next
decl_stmt|;
name|unsigned
name|int
name|count
decl_stmt|;
name|cpp_token
name|GTY
argument_list|(
operator|(
name|length
argument_list|(
literal|"%h.count"
argument_list|)
operator|)
argument_list|)
name|first
index|[
literal|1
index|]
decl_stmt|;
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
comment|/* Each macro definition is recorded in a cpp_macro structure.    Variadic macros cannot occur with traditional cpp.  */
end_comment

begin_decl_stmt
name|struct
name|cpp_macro
name|GTY
argument_list|(
operator|(
operator|)
argument_list|)
block|{
comment|/* Parameters, if any.  */
name|cpp_hashnode
modifier|*
modifier|*
name|GTY
argument_list|(
operator|(
name|nested_ptr
argument_list|(
expr|union
name|tree_node
argument_list|,
literal|"%h ? CPP_HASHNODE (GCC_IDENT_TO_HT_IDENT (%h)) : NULL"
argument_list|,
literal|"%h ? HT_IDENT_TO_GCC_IDENT (HT_NODE (%h)) : NULL"
argument_list|)
operator|,
name|length
argument_list|(
literal|"%h.paramc"
argument_list|)
operator|)
argument_list|)
name|params
decl_stmt|;
comment|/* Replacement tokens (ISO) or replacement text (traditional).  See      comment at top of cpptrad.c for how traditional function-like      macros are encoded.  */
union|union
name|cpp_macro_u
block|{
name|cpp_token
modifier|*
name|GTY
argument_list|(
operator|(
name|tag
argument_list|(
literal|"0"
argument_list|)
operator|,
name|length
argument_list|(
literal|"%0.count"
argument_list|)
operator|)
argument_list|)
name|tokens
decl_stmt|;
specifier|const
name|unsigned
name|char
modifier|*
name|GTY
argument_list|(
operator|(
name|tag
argument_list|(
literal|"1"
argument_list|)
operator|)
argument_list|)
name|text
decl_stmt|;
block|}
name|GTY
argument_list|(
operator|(
name|desc
argument_list|(
literal|"%1.traditional"
argument_list|)
operator|)
argument_list|)
name|exp
union|;
comment|/* Definition line number.  */
name|source_location
name|line
decl_stmt|;
comment|/* Number of tokens in expansion, or bytes for traditional macros.  */
name|unsigned
name|int
name|count
decl_stmt|;
comment|/* Number of parameters.  */
name|unsigned
name|short
name|paramc
decl_stmt|;
comment|/* If a function-like macro.  */
name|unsigned
name|int
name|fun_like
range|:
literal|1
decl_stmt|;
comment|/* If a variadic macro.  */
name|unsigned
name|int
name|variadic
range|:
literal|1
decl_stmt|;
comment|/* If macro defined in system header.  */
name|unsigned
name|int
name|syshdr
range|:
literal|1
decl_stmt|;
comment|/* Nonzero if it has been expanded or had its existence tested.  */
name|unsigned
name|int
name|used
range|:
literal|1
decl_stmt|;
comment|/* Indicate which field of 'exp' is in use.  */
name|unsigned
name|int
name|traditional
range|:
literal|1
decl_stmt|;
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

end_unit

