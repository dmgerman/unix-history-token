begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* This file is listing.h    Copyright (C) 1987, 1988, 1989, 1990, 1991, 1992 Free Software Foundation, Inc.     This file is part of GAS, the GNU Assembler.     GAS is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2, or (at your option)    any later version.     GAS is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.     You should have received a copy of the GNU General Public License    along with GAS; see the file COPYING.  If not, write to    the Free Software Foundation, 675 Mass Ave, Cambridge, MA 02139, USA.  */
end_comment

begin_comment
comment|/*  * $FreeBSD$  */
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

begin_comment
comment|/* This structure remembers which .s were used */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|file_info_struct
block|{
name|char
modifier|*
name|filename
decl_stmt|;
name|int
name|linenum
decl_stmt|;
name|FILE
modifier|*
name|file
decl_stmt|;
name|struct
name|file_info_struct
modifier|*
name|next
decl_stmt|;
name|int
name|end_pending
decl_stmt|;
block|}
name|file_info_type
typedef|;
end_typedef

begin_comment
comment|/* this structure rememebrs which line from which file goes into which    frag */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|list_info_struct
block|{
comment|/* Frag which this line of source is nearest to */
name|fragS
modifier|*
name|frag
decl_stmt|;
comment|/* The actual line in the source file */
name|unsigned
name|int
name|line
decl_stmt|;
comment|/* Pointer to the file info struct for the file which this line      belongs to */
name|file_info_type
modifier|*
name|file
decl_stmt|;
comment|/* Next in list */
name|struct
name|list_info_struct
modifier|*
name|next
decl_stmt|;
comment|/* Pointer to the file info struct for the high level language      source line that belongs here */
name|file_info_type
modifier|*
name|hll_file
decl_stmt|;
comment|/* High level language source line */
name|int
name|hll_line
decl_stmt|;
comment|/* Pointer to any error message associated with this line */
name|char
modifier|*
name|message
decl_stmt|;
enum|enum
block|{
name|EDICT_NONE
block|,
name|EDICT_SBTTL
block|,
name|EDICT_TITLE
block|,
name|EDICT_NOLIST
block|,
name|EDICT_LIST
block|,
name|EDICT_EJECT
block|}
name|edict
enum|;
name|char
modifier|*
name|edict_arg
decl_stmt|;
block|}
name|list_info_type
typedef|;
end_typedef

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

