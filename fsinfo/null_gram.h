begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* A Bison parser, made by GNU Bison 3.0.2.  */
end_comment

begin_comment
comment|/* Bison interface for Yacc-like parsers in C     Copyright (C) 1984, 1989-1990, 2000-2013 Free Software Foundation, Inc.     This program is free software: you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation, either version 3 of the License, or    (at your option) any later version.     This program is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.     You should have received a copy of the GNU General Public License    along with this program.  If not, see<http://www.gnu.org/licenses/>.  */
end_comment

begin_comment
comment|/* As a special exception, you may create a larger work that contains    part or all of the Bison parser skeleton and distribute that work    under terms of your choice, so long as that work isn't itself a    parser generator using the skeleton or a modified version thereof    as a parser skeleton.  Alternatively, if you modify or redistribute    the parser skeleton itself, you may (at your option) remove this    special exception, which will cause the skeleton and the resulting    Bison output files to be licensed under the GNU General Public    License without this special exception.     This special exception was added by the Free Software Foundation in    version 2.2 of Bison.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|YY_NULL_NULL_GRAM_H_INCLUDED
end_ifndef

begin_define
define|#
directive|define
name|YY_NULL_NULL_GRAM_H_INCLUDED
end_define

begin_comment
comment|/* Debug traces.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|YYDEBUG
end_ifndef

begin_define
define|#
directive|define
name|YYDEBUG
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|YYDEBUG
end_if

begin_decl_stmt
specifier|extern
name|int
name|null_debug
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Value type.  */
end_comment

begin_if
if|#
directive|if
operator|!
name|defined
name|YYSTYPE
operator|&&
operator|!
name|defined
name|YYSTYPE_IS_DECLARED
end_if

begin_typedef
typedef|typedef
name|int
name|YYSTYPE
typedef|;
end_typedef

begin_define
define|#
directive|define
name|YYSTYPE_IS_TRIVIAL
value|1
end_define

begin_define
define|#
directive|define
name|YYSTYPE_IS_DECLARED
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
specifier|extern
name|YYSTYPE
name|null_lval
decl_stmt|;
end_decl_stmt

begin_function_decl
name|int
name|null_parse
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !YY_NULL_NULL_GRAM_H_INCLUDED  */
end_comment

end_unit

