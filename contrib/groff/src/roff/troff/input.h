begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// -*- C++ -*-
end_comment

begin_comment
comment|/* Copyright (C) 2001 Free Software Foundation, Inc.      Written by James Clark (jjc@jclark.com)  This file is part of groff.  groff is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2, or (at your option) any later version.  groff is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with groff; see the file COPYING.  If not, write to the Free Software Foundation, 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA. */
end_comment

begin_comment
comment|/* special character codes */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|IS_EBCDIC_HOST
end_ifndef

begin_decl_stmt
specifier|const
name|int
name|ESCAPE_QUESTION
init|=
literal|015
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|const
name|int
name|BEGIN_TRAP
init|=
literal|016
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|const
name|int
name|END_TRAP
init|=
literal|017
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|const
name|int
name|PAGE_EJECTOR
init|=
literal|020
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|const
name|int
name|ESCAPE_NEWLINE
init|=
literal|021
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|const
name|int
name|ESCAPE_AMPERSAND
init|=
literal|022
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|const
name|int
name|ESCAPE_UNDERSCORE
init|=
literal|023
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|const
name|int
name|ESCAPE_BAR
init|=
literal|024
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|const
name|int
name|ESCAPE_CIRCUMFLEX
init|=
literal|025
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|const
name|int
name|ESCAPE_LEFT_BRACE
init|=
literal|026
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|const
name|int
name|ESCAPE_RIGHT_BRACE
init|=
literal|027
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|const
name|int
name|ESCAPE_LEFT_QUOTE
init|=
literal|030
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|const
name|int
name|ESCAPE_RIGHT_QUOTE
init|=
literal|031
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|const
name|int
name|ESCAPE_HYPHEN
init|=
literal|032
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|const
name|int
name|ESCAPE_BANG
init|=
literal|033
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|const
name|int
name|ESCAPE_c
init|=
literal|034
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|const
name|int
name|ESCAPE_e
init|=
literal|035
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|const
name|int
name|ESCAPE_PERCENT
init|=
literal|036
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|const
name|int
name|ESCAPE_SPACE
init|=
literal|037
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|const
name|int
name|TITLE_REQUEST
init|=
literal|0200
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|const
name|int
name|COPY_FILE_REQUEST
init|=
literal|0201
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|const
name|int
name|TRANSPARENT_FILE_REQUEST
init|=
literal|0202
decl_stmt|;
end_decl_stmt

begin_ifdef
ifdef|#
directive|ifdef
name|COLUMN
end_ifdef

begin_decl_stmt
specifier|const
name|int
name|VJUSTIFY_REQUEST
init|=
literal|0203
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* COLUMN */
end_comment

begin_decl_stmt
specifier|const
name|int
name|ESCAPE_E
init|=
literal|0204
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|const
name|int
name|LAST_PAGE_EJECTOR
init|=
literal|0205
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|const
name|int
name|ESCAPE_RIGHT_PARENTHESIS
init|=
literal|0206
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|const
name|int
name|ESCAPE_TILDE
init|=
literal|0207
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|const
name|int
name|ESCAPE_COLON
init|=
literal|0210
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|const
name|int
name|COMPATIBLE_SAVE
init|=
literal|0211
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|const
name|int
name|COMPATIBLE_RESTORE
init|=
literal|0212
decl_stmt|;
end_decl_stmt

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* IS_EBCDIC_HOST */
end_comment

begin_decl_stmt
specifier|const
name|int
name|ESCAPE_QUESTION
init|=
literal|010
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|const
name|int
name|BEGIN_TRAP
init|=
literal|011
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|const
name|int
name|END_TRAP
init|=
literal|013
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|const
name|int
name|PAGE_EJECTOR
init|=
literal|015
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|const
name|int
name|ESCAPE_NEWLINE
init|=
literal|016
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|const
name|int
name|ESCAPE_AMPERSAND
init|=
literal|017
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|const
name|int
name|ESCAPE_UNDERSCORE
init|=
literal|020
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|const
name|int
name|ESCAPE_BAR
init|=
literal|021
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|const
name|int
name|ESCAPE_CIRCUMFLEX
init|=
literal|022
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|const
name|int
name|ESCAPE_LEFT_BRACE
init|=
literal|023
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|const
name|int
name|ESCAPE_RIGHT_BRACE
init|=
literal|024
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|const
name|int
name|ESCAPE_LEFT_QUOTE
init|=
literal|027
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|const
name|int
name|ESCAPE_RIGHT_QUOTE
init|=
literal|030
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|const
name|int
name|ESCAPE_HYPHEN
init|=
literal|031
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|const
name|int
name|ESCAPE_BANG
init|=
literal|032
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|const
name|int
name|ESCAPE_c
init|=
literal|033
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|const
name|int
name|ESCAPE_e
init|=
literal|034
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|const
name|int
name|ESCAPE_PERCENT
init|=
literal|035
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|const
name|int
name|ESCAPE_SPACE
init|=
literal|036
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|const
name|int
name|TITLE_REQUEST
init|=
literal|060
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|const
name|int
name|COPY_FILE_REQUEST
init|=
literal|061
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|const
name|int
name|TRANSPARENT_FILE_REQUEST
init|=
literal|062
decl_stmt|;
end_decl_stmt

begin_ifdef
ifdef|#
directive|ifdef
name|COLUMN
end_ifdef

begin_decl_stmt
specifier|const
name|int
name|VJUSTIFY_REQUEST
init|=
literal|063
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* COLUMN */
end_comment

begin_decl_stmt
specifier|const
name|int
name|ESCAPE_E
init|=
literal|064
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|const
name|int
name|LAST_PAGE_EJECTOR
init|=
literal|065
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|const
name|int
name|ESCAPE_RIGHT_PARENTHESIS
init|=
literal|066
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|const
name|int
name|ESCAPE_TILDE
init|=
literal|067
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|const
name|int
name|ESCAPE_COLON
init|=
literal|070
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|const
name|int
name|COMPATIBLE_SAVE
init|=
literal|071
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|const
name|int
name|COMPATIBLE_RESTORE
init|=
literal|072
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* IS_EBCDIC_HOST */
end_comment

end_unit

