begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// This may look like C code, but it is really -*- C++ -*-
end_comment

begin_comment
comment|/*  Copyright (C) 1988 Free Software Foundation     written by Doug Lea (dl@rocky.oswego.edu)  This file is part of GNU CC.  GNU CC is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY.  No author or distributor accepts responsibility to anyone for the consequences of using it or for whether it serves any particular purpose or works at all, unless he says so in writing.  Refer to the GNU CC General Public License for full details.  Everyone is granted permission to copy, modify and redistribute GNU CC, but only under the conditions described in the GNU CC General Public License.   A copy of this license is supposed to have been given to you along with GNU CC so you can know your rights and responsibilities.  It should be in a file named COPYING.  Among other things, the copyright notice and this notice must be preserved on all copies.   */
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
name|once
end_pragma

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

