begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* This file is listing.h    Copyright (C) 1987-1992 Free Software Foundation, Inc.        This file is part of GAS, the GNU Assembler.        GAS is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2, or (at your option)    any later version.        GAS is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.        You should have received a copy of the GNU General Public License    along with GAS; see the file COPYING.  If not, write to    the Free Software Foundation, 675 Mass Ave, Cambridge, MA 02139, USA.  */
end_comment

begin_comment
comment|/*  * $Id: listing.h,v 1.1 1993/10/02 20:57:41 pk Exp $  */
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

begin_if
if|#
directive|if
name|__STDC__
operator|==
literal|1
end_if

begin_function_decl
name|void
name|listing_eject
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|listing_error
parameter_list|(
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
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|listing_list
parameter_list|(
name|unsigned
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
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|listing_source_file
parameter_list|(
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
name|unsigned
name|int
name|depth
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|listing_warning
parameter_list|(
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

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* not __STDC__ */
end_comment

begin_function_decl
name|void
name|listing_eject
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|listing_error
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|listing_file
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|listing_flags
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|listing_list
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|listing_newline
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|listing_print
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|listing_psize
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|listing_source_file
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|listing_source_line
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|listing_title
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|listing_warning
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|listing_width
parameter_list|()
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* not __STDC__ */
end_comment

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* NO_LISTING */
end_comment

begin_define
define|#
directive|define
name|LISTING_NEWLINE
parameter_list|()
value|{;}
end_define

begin_comment
comment|/* Dummy functions for when compiled without listing enabled */
end_comment

begin_define
define|#
directive|define
name|listing_flags
parameter_list|()
value|{;}
end_define

begin_define
define|#
directive|define
name|listing_list
parameter_list|()
value|{;}
end_define

begin_define
define|#
directive|define
name|listing_eject
parameter_list|()
value|{;}
end_define

begin_define
define|#
directive|define
name|listing_psize
parameter_list|()
value|{;}
end_define

begin_define
define|#
directive|define
name|listing_title
parameter_list|(
name|depth
parameter_list|)
value|{;}
end_define

begin_define
define|#
directive|define
name|listing_file
parameter_list|(
name|name
parameter_list|)
value|{;}
end_define

begin_define
define|#
directive|define
name|listing_newline
parameter_list|(
name|name
parameter_list|)
value|{;}
end_define

begin_define
define|#
directive|define
name|listing_source_line
parameter_list|(
name|n
parameter_list|)
value|{;}
end_define

begin_define
define|#
directive|define
name|listing_source_file
parameter_list|(
name|n
parameter_list|)
value|{;}
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* NO_LISTING */
end_comment

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

