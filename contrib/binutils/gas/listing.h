begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* This file is listing.h    Copyright 1987, 1988, 1989, 1990, 1991, 1992, 1993, 1995, 1997, 1998    Free Software Foundation, Inc.     This file is part of GAS, the GNU Assembler.     GAS is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2, or (at your option)    any later version.     GAS is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.     You should have received a copy of the GNU General Public License    along with GAS; see the file COPYING.  If not, write to the Free    Software Foundation, 59 Temple Place - Suite 330, Boston, MA    02111-1307, USA.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__listing_h__
end_ifndef

begin_define
define|#
directive|define
name|__listing_h__
end_define

begin_define
define|#
directive|define
name|LISTING_LISTING
value|1
end_define

begin_define
define|#
directive|define
name|LISTING_SYMBOLS
value|2
end_define

begin_define
define|#
directive|define
name|LISTING_NOFORM
value|4
end_define

begin_define
define|#
directive|define
name|LISTING_HLL
value|8
end_define

begin_define
define|#
directive|define
name|LISTING_NODEBUG
value|16
end_define

begin_define
define|#
directive|define
name|LISTING_NOCOND
value|32
end_define

begin_define
define|#
directive|define
name|LISTING_MACEXP
value|64
end_define

begin_define
define|#
directive|define
name|LISTING_DEFAULT
value|(LISTING_LISTING | LISTING_HLL | LISTING_SYMBOLS)
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|NO_LISTING
end_ifndef

begin_define
define|#
directive|define
name|LISTING_NEWLINE
parameter_list|()
value|{ if (listing) listing_newline(NULL); }
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|LISTING_NEWLINE
parameter_list|()
value|{;}
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|LISTING_EOF
parameter_list|()
value|LISTING_NEWLINE()
end_define

begin_define
define|#
directive|define
name|LISTING_SKIP_COND
parameter_list|()
value|((listing& LISTING_NOCOND) != 0)
end_define

begin_function_decl
name|void
name|listing_eject
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|listing_error
parameter_list|(
specifier|const
name|char
modifier|*
name|message
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|listing_file
parameter_list|(
specifier|const
name|char
modifier|*
name|name
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|listing_flags
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|listing_list
parameter_list|(
name|int
name|on
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|listing_newline
parameter_list|(
name|char
modifier|*
name|ps
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|listing_prev_line
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|listing_print
parameter_list|(
name|char
modifier|*
name|name
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|listing_psize
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|listing_nopage
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|listing_source_file
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|listing_source_line
parameter_list|(
name|unsigned
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|listing_title
parameter_list|(
name|int
name|depth
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|listing_warning
parameter_list|(
specifier|const
name|char
modifier|*
name|message
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|listing_width
parameter_list|(
name|unsigned
name|int
name|x
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
specifier|extern
name|int
name|listing_lhs_width
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|listing_lhs_width_second
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|listing_lhs_cont_lines
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|listing_rhs_width
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __listing_h__ */
end_comment

begin_comment
comment|/* end of listing.h */
end_comment

end_unit

