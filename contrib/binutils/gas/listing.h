begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* This file is listing.h    Copyright (C) 1987, 88, 89, 90, 91, 92, 93, 94, 95, 1997    Free Software Foundation, Inc.     This file is part of GAS, the GNU Assembler.     GAS is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2, or (at your option)    any later version.     GAS is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.     You should have received a copy of the GNU General Public License    along with GAS; see the file COPYING.  If not, write to the Free    Software Foundation, 59 Temple Place - Suite 330, Boston, MA    02111-1307, USA.  */
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
name|LISTING_DEFAULT
value|(LISTING_LISTING | LISTING_HLL |  LISTING_SYMBOLS)
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
value|{ if (listing) listing_newline(input_line_pointer); }
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
name|LISTING_SKIP_COND
parameter_list|()
value|((listing& LISTING_NOCOND) != 0)
end_define

begin_decl_stmt
name|void
name|listing_eject
name|PARAMS
argument_list|(
operator|(
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|listing_error
name|PARAMS
argument_list|(
operator|(
specifier|const
name|char
operator|*
name|message
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|listing_file
name|PARAMS
argument_list|(
operator|(
specifier|const
name|char
operator|*
name|name
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|listing_flags
name|PARAMS
argument_list|(
operator|(
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|listing_list
name|PARAMS
argument_list|(
operator|(
name|int
name|on
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|listing_newline
name|PARAMS
argument_list|(
operator|(
name|char
operator|*
name|ps
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|listing_prev_line
name|PARAMS
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|listing_print
name|PARAMS
argument_list|(
operator|(
name|char
operator|*
name|name
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|listing_psize
name|PARAMS
argument_list|(
operator|(
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|listing_nopage
name|PARAMS
argument_list|(
operator|(
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|listing_source_file
name|PARAMS
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
name|void
name|listing_source_line
name|PARAMS
argument_list|(
operator|(
name|unsigned
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|listing_title
name|PARAMS
argument_list|(
operator|(
name|int
name|depth
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|listing_warning
name|PARAMS
argument_list|(
operator|(
specifier|const
name|char
operator|*
name|message
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|listing_width
name|PARAMS
argument_list|(
operator|(
name|unsigned
name|int
name|x
operator|)
argument_list|)
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

