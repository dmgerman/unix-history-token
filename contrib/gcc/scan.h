begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* scan.h - Utility declarations for scan-decls and fix-header programs.    Copyright (C) 1993, 1998, 1999 Free Software Foundation, Inc.  This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2, or (at your option) any later version.  This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with this program; if not, write to the Free Software Foundation, 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
end_comment

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_typedef
typedef|typedef
struct|struct
name|sstring
block|{
name|char
modifier|*
name|base
decl_stmt|;
name|char
modifier|*
name|ptr
decl_stmt|;
name|char
modifier|*
name|limit
decl_stmt|;
block|}
name|sstring
typedef|;
end_typedef

begin_define
define|#
directive|define
name|INIT_SSTRING
parameter_list|(
name|STR
parameter_list|)
value|((STR)->base = 0, (STR)->ptr = 0, (STR)->limit = 0)
end_define

begin_define
define|#
directive|define
name|FREE_SSTRING
parameter_list|(
name|STR
parameter_list|)
value|do { if ((STR)->base) free (STR)->base; } while(0)
end_define

begin_define
define|#
directive|define
name|SSTRING_PUT
parameter_list|(
name|STR
parameter_list|,
name|C
parameter_list|)
value|do {\   if ((STR)->limit<= (STR)->ptr) make_sstring_space (STR, 1); \   *(STR)->ptr++ = (C); } while (0)
end_define

begin_define
define|#
directive|define
name|SSTRING_LENGTH
parameter_list|(
name|STR
parameter_list|)
value|((STR)->ptr - (STR)->base)
end_define

begin_define
define|#
directive|define
name|MAKE_SSTRING_SPACE
parameter_list|(
name|STR
parameter_list|,
name|COUNT
parameter_list|)
define|\
value|if ((STR)->limit - (STR)->ptr< (COUNT)) make_sstring_space (STR, COUNT);
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|_PARAMS
end_ifndef

begin_if
if|#
directive|if
name|defined
argument_list|(
name|ANSI_PROTOTYPES
argument_list|)
operator|||
name|defined
argument_list|(
name|__cplusplus
argument_list|)
end_if

begin_define
define|#
directive|define
name|_PARAMS
parameter_list|(
name|args
parameter_list|)
value|args
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|_PARAMS
parameter_list|(
name|args
parameter_list|)
value|()
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_struct_decl
struct_decl|struct
name|partial_proto
struct_decl|;
end_struct_decl

begin_struct
struct|struct
name|fn_decl
block|{
specifier|const
name|char
modifier|*
name|fname
decl_stmt|;
specifier|const
name|char
modifier|*
name|rtype
decl_stmt|;
specifier|const
name|char
modifier|*
name|params
decl_stmt|;
name|struct
name|partial_proto
modifier|*
name|partial
decl_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
specifier|extern
name|int
name|lineno
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|sstring_append
name|_PARAMS
argument_list|(
operator|(
name|sstring
operator|*
operator|,
name|sstring
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|make_sstring_space
name|_PARAMS
argument_list|(
operator|(
name|sstring
operator|*
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|skip_spaces
name|_PARAMS
argument_list|(
operator|(
name|FILE
operator|*
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|scan_ident
name|_PARAMS
argument_list|(
operator|(
name|FILE
operator|*
operator|,
name|sstring
operator|*
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|scan_string
name|_PARAMS
argument_list|(
operator|(
name|FILE
operator|*
operator|,
name|sstring
operator|*
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|read_upto
name|_PARAMS
argument_list|(
operator|(
name|FILE
operator|*
operator|,
name|sstring
operator|*
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|unsigned
name|long
name|hash
name|_PARAMS
argument_list|(
operator|(
specifier|const
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|recognized_function
name|_PARAMS
argument_list|(
operator|(
name|char
operator|*
operator|,
name|int
operator|,
name|int
operator|,
name|char
operator|*
operator|,
name|int
operator|,
name|int
operator|,
name|char
operator|*
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|recognized_extern
name|_PARAMS
argument_list|(
operator|(
name|char
operator|*
operator|,
name|int
operator|,
name|char
operator|*
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* get_token is a simple C lexer. */
end_comment

begin_define
define|#
directive|define
name|IDENTIFIER_TOKEN
value|300
end_define

begin_define
define|#
directive|define
name|CHAR_TOKEN
value|301
end_define

begin_define
define|#
directive|define
name|STRING_TOKEN
value|302
end_define

begin_define
define|#
directive|define
name|INT_TOKEN
value|303
end_define

begin_decl_stmt
specifier|extern
name|int
name|get_token
name|_PARAMS
argument_list|(
operator|(
name|FILE
operator|*
operator|,
name|sstring
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Current file and line numer, taking #-directives into account */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|source_lineno
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|sstring
name|source_filename
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Current physical line number */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|lineno
decl_stmt|;
end_decl_stmt

end_unit

