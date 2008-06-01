begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// This may look like C code, but it is really -*- C++ -*-
end_comment

begin_comment
comment|/*  Copyright (C) 1988 Free Software Foundation     written by Doug Lea (dl@rocky.oswego.edu)  This file is part of the GNU C++ Library.  This library is free software; you can redistribute it and/or modify it under the terms of the GNU Library General Public License as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version.  This library is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU Library General Public License for more details. You should have received a copy of the GNU Library General Public License along with this library; if not, write to the Free Software Foundation, 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA. */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_Regex_h
end_ifndef

begin_ifdef
ifdef|#
directive|ifdef
name|__GNUG__
end_ifdef

begin_pragma
pragma|#
directive|pragma
name|interface
end_pragma

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|_Regex_h
value|1
end_define

begin_undef
undef|#
directive|undef
name|OK
end_undef

begin_if
if|#
directive|if
name|defined
argument_list|(
name|SHORT_NAMES
argument_list|)
operator|||
name|defined
argument_list|(
name|VMS
argument_list|)
end_if

begin_define
define|#
directive|define
name|re_compile_pattern
value|recmppat
end_define

begin_define
define|#
directive|define
name|re_pattern_buffer
value|repatbuf
end_define

begin_define
define|#
directive|define
name|re_registers
value|reregs
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_struct_decl
struct_decl|struct
name|re_pattern_buffer
struct_decl|;
end_struct_decl

begin_comment
comment|// defined elsewhere
end_comment

begin_struct_decl
struct_decl|struct
name|re_registers
struct_decl|;
end_struct_decl

begin_decl_stmt
name|class
name|Regex
block|{
name|private
label|:
name|Regex
argument_list|(
argument|const Regex&
argument_list|)
block|{}
comment|// no X(X&)
name|void
name|operator
init|=
operator|(
specifier|const
name|Regex
operator|&
operator|)
block|{}
comment|// no assignment
name|protected
operator|:
name|re_pattern_buffer
operator|*
name|buf
decl_stmt|;
name|re_registers
modifier|*
name|reg
decl_stmt|;
name|public
label|:
name|Regex
argument_list|(
argument|const char* t
argument_list|,
argument|int fast =
literal|0
argument_list|,
argument|int bufsize =
literal|40
argument_list|,
argument|const char* transtable =
literal|0
argument_list|)
empty_stmt|;
operator|~
name|Regex
argument_list|()
expr_stmt|;
name|int
name|match
argument_list|(
specifier|const
name|char
operator|*
name|s
argument_list|,
name|int
name|len
argument_list|,
name|int
name|pos
operator|=
literal|0
argument_list|)
decl|const
decl_stmt|;
name|int
name|search
argument_list|(
specifier|const
name|char
operator|*
name|s
argument_list|,
name|int
name|len
argument_list|,
name|int
operator|&
name|matchlen
argument_list|,
name|int
name|startpos
operator|=
literal|0
argument_list|)
decl|const
decl_stmt|;
name|int
name|match_info
argument_list|(
name|int
operator|&
name|start
argument_list|,
name|int
operator|&
name|length
argument_list|,
name|int
name|nth
operator|=
literal|0
argument_list|)
decl|const
decl_stmt|;
name|int
name|OK
argument_list|()
specifier|const
expr_stmt|;
comment|// representation invariant
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
comment|// some built in regular expressions
end_comment

begin_decl_stmt
specifier|extern
specifier|const
name|Regex
name|RXwhite
decl_stmt|;
end_decl_stmt

begin_comment
comment|// = "[ \n\t\r\v\f]+"
end_comment

begin_decl_stmt
specifier|extern
specifier|const
name|Regex
name|RXint
decl_stmt|;
end_decl_stmt

begin_comment
comment|// = "-?[0-9]+"
end_comment

begin_decl_stmt
specifier|extern
specifier|const
name|Regex
name|RXdouble
decl_stmt|;
end_decl_stmt

begin_comment
comment|// = "-?\\(\\([0-9]+\\.[0-9]*\\)\\|
end_comment

begin_comment
comment|//    \\([0-9]+\\)\\|\\(\\.[0-9]+\\)\\)
end_comment

begin_comment
comment|//    \\([eE][---+]?[0-9]+\\)?"
end_comment

begin_decl_stmt
specifier|extern
specifier|const
name|Regex
name|RXalpha
decl_stmt|;
end_decl_stmt

begin_comment
comment|// = "[A-Za-z]+"
end_comment

begin_decl_stmt
specifier|extern
specifier|const
name|Regex
name|RXlowercase
decl_stmt|;
end_decl_stmt

begin_comment
comment|// = "[a-z]+"
end_comment

begin_decl_stmt
specifier|extern
specifier|const
name|Regex
name|RXuppercase
decl_stmt|;
end_decl_stmt

begin_comment
comment|// = "[A-Z]+"
end_comment

begin_decl_stmt
specifier|extern
specifier|const
name|Regex
name|RXalphanum
decl_stmt|;
end_decl_stmt

begin_comment
comment|// = "[0-9A-Za-z]+"
end_comment

begin_decl_stmt
specifier|extern
specifier|const
name|Regex
name|RXidentifier
decl_stmt|;
end_decl_stmt

begin_comment
comment|// = "[A-Za-z_][A-Za-z0-9_]*"
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

