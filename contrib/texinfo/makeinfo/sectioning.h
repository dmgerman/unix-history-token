begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* sectioning.h -- all related stuff @chapter, @section... @contents    $Id: sectioning.h,v 1.2 1999/03/09 22:48:15 karl Exp $     Copyright (C) 1999 Free Software Foundation, Inc.     This program is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2, or (at your option)    any later version.     This program is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.     You should have received a copy of the GNU General Public License    along with this program; if not, write to the Free Software    Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.     Written by Karl Heinz Marbaise<kama@hippo.fido.de>.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|SECTIONING_H
end_ifndef

begin_define
define|#
directive|define
name|SECTIONING_H
end_define

begin_comment
comment|/* Sectioning.  */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|cm_chapter
argument_list|()
decl_stmt|,
name|cm_unnumbered
argument_list|()
decl_stmt|,
name|cm_appendix
argument_list|()
decl_stmt|,
name|cm_top
argument_list|()
decl_stmt|,
name|cm_section
argument_list|()
decl_stmt|,
name|cm_unnumberedsec
argument_list|()
decl_stmt|,
name|cm_appendixsec
argument_list|()
decl_stmt|,
name|cm_subsection
argument_list|()
decl_stmt|,
name|cm_unnumberedsubsec
argument_list|()
decl_stmt|,
name|cm_appendixsubsec
argument_list|()
decl_stmt|,
name|cm_subsubsection
argument_list|()
decl_stmt|,
name|cm_unnumberedsubsubsec
argument_list|()
decl_stmt|,
name|cm_appendixsubsubsec
argument_list|()
decl_stmt|,
name|cm_heading
argument_list|()
decl_stmt|,
name|cm_chapheading
argument_list|()
decl_stmt|,
name|cm_subheading
argument_list|()
decl_stmt|,
name|cm_subsubheading
argument_list|()
decl_stmt|,
name|cm_majorheading
argument_list|()
decl_stmt|,
name|cm_raisesections
argument_list|()
decl_stmt|,
name|cm_lowersections
argument_list|()
decl_stmt|,
name|cm_ideprecated
argument_list|()
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|sectioning_underscore
argument_list|()
decl_stmt|,
name|insert_and_underscore
argument_list|()
decl_stmt|;
end_decl_stmt

begin_function_decl
specifier|extern
name|int
name|what_section
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* is needed in node.c */
end_comment

begin_function_decl
specifier|extern
name|int
name|set_top_section_level
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|sectioning_html
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|what_section
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* The argument of @settitle, used for HTML. */
end_comment

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|title
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Here is a structure which associates sectioning commands with    an integer that reflects the depth of the current section. */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|char
modifier|*
name|name
decl_stmt|;
name|int
name|level
decl_stmt|;
comment|/* I can't replace the levels with defines                 because it is changed during run */
name|int
name|num
decl_stmt|;
comment|/* ENUM_SECT_NO means no enumeration...               ENUM_SECT_YES means enumerated version               ENUM_SECT_APP appendix (Character enumerated                             at first position */
name|int
name|toc
decl_stmt|;
comment|/* TOC_NO means do not enter in toc;               TOC_YES means enter it in toc */
block|}
name|section_alist_type
typedef|;
end_typedef

begin_decl_stmt
specifier|extern
name|section_alist_type
name|section_alist
index|[]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* enumerate sections */
end_comment

begin_define
define|#
directive|define
name|ENUM_SECT_NO
value|0
end_define

begin_define
define|#
directive|define
name|ENUM_SECT_YES
value|1
end_define

begin_define
define|#
directive|define
name|ENUM_SECT_APP
value|2
end_define

begin_comment
comment|/* make entries into toc no/yes */
end_comment

begin_define
define|#
directive|define
name|TOC_NO
value|0
end_define

begin_define
define|#
directive|define
name|TOC_YES
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* not SECTIONING_H */
end_comment

end_unit

