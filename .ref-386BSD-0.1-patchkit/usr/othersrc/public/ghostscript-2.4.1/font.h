begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Copyright (C) 1989, 1991 Aladdin Enterprises.  All rights reserved.    Distributed by Free Software Foundation, Inc.  This file is part of Ghostscript.  Ghostscript is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY.  No author or distributor accepts responsibility to anyone for the consequences of using it or for whether it serves any particular purpose or works at all, unless he says so in writing.  Refer to the Ghostscript General Public License for full details.  Everyone is granted permission to copy, modify and redistribute Ghostscript, but only under the conditions described in the Ghostscript General Public License.  A copy of this license is supposed to have been given to you along with Ghostscript so you can know your rights and responsibilities.  It should be in a file named COPYING.  Among other things, the copyright notice and this notice must be preserved on all copies.  */
end_comment

begin_comment
comment|/* font.h */
end_comment

begin_comment
comment|/* Internal font representation for Ghostscript */
end_comment

begin_comment
comment|/* The external definition of fonts is given in the PostScript manual, */
end_comment

begin_comment
comment|/* pp. 91-93. */
end_comment

begin_comment
comment|/* The structure given below is 'client data' from the viewpoint */
end_comment

begin_comment
comment|/* of the library.  t_fontID objects point directly to a gs_font.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|font_data_s
block|{
name|ref
name|dict
decl_stmt|;
comment|/* font dictionary object */
name|ref
name|BuildChar
decl_stmt|;
name|ref
name|Encoding
decl_stmt|;
name|ref
name|CharStrings
decl_stmt|;
name|ref
name|Subrs
decl_stmt|;
comment|/* from Private dictionary */
block|}
name|font_data
typedef|;
end_typedef

begin_comment
comment|/* The current font in the graphics state */
end_comment

begin_define
define|#
directive|define
name|ifont
value|(igs->font)
end_define

end_unit

