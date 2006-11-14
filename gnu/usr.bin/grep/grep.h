begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* grep.h - interface to grep driver for searching subroutines.    Copyright (C) 1992, 1998, 2001 Free Software Foundation, Inc.     This program is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2, or (at your option)    any later version.     This program is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.     You should have received a copy of the GNU General Public License    along with this program; if not, write to the Free Software    Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA    02111-1307, USA.  */
end_comment

begin_comment
comment|/* $FreeBSD$ */
end_comment

begin_if
if|#
directive|if
name|__GNUC__
operator|<
literal|2
operator|||
operator|(
name|__GNUC__
operator|==
literal|2
operator|&&
name|__GNUC_MINOR__
operator|<
literal|6
operator|)
operator|||
name|__STRICT_ANSI__
end_if

begin_define
define|#
directive|define
name|__attribute__
parameter_list|(
name|x
parameter_list|)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Grep.c expects the matchers vector to be terminated    by an entry with a NULL compile, and to contain at least    an entry named "default". */
end_comment

begin_struct
specifier|extern
struct|struct
name|matcher
block|{
name|char
name|name
index|[
literal|8
index|]
decl_stmt|;
name|void
argument_list|(
argument|*compile
argument_list|)
name|PARAMS
argument_list|(
operator|(
name|char
specifier|const
operator|*
operator|,
name|size_t
operator|)
argument_list|)
expr_stmt|;
name|size_t
argument_list|(
argument|*execute
argument_list|)
name|PARAMS
argument_list|(
operator|(
name|char
specifier|const
operator|*
operator|,
name|size_t
operator|,
name|size_t
operator|*
operator|,
name|int
operator|)
argument_list|)
expr_stmt|;
block|}
decl|const
name|matchers
index|[]
struct|;
end_struct

begin_comment
comment|/* Exported from fgrepmat.c, egrepmat.c, grepmat.c.  */
end_comment

begin_decl_stmt
specifier|extern
name|char
specifier|const
modifier|*
name|matcher
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* The following flags are exported from grep for the matchers    to look at. */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|match_icase
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* -i */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|match_words
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* -w */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|match_lines
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* -x */
end_comment

begin_decl_stmt
specifier|extern
name|unsigned
name|char
name|eolbyte
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* -z */
end_comment

end_unit

