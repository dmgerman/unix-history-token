begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// -*- C++ -*-
end_comment

begin_comment
comment|/* Copyright (C) 2001 Free Software Foundation, Inc.      Written by Gaius Mulley (gaius@glam.ac.uk).  This file is part of groff.  groff is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2, or (at your option) any later version.  groff is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with groff; see the file COPYING.  If not, write to the Free Software Foundation, 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA. */
end_comment

begin_comment
comment|/*  *  defines the image tags issued by the pre-processors (tbl, pic, eqn)  *  and later detected by pre-html.cc  */
end_comment

begin_define
define|#
directive|define
name|HTML_IMAGE_INLINE_BEGIN
value|"\\O[HTML-IMAGE-INLINE-BEGIN]"
end_define

begin_define
define|#
directive|define
name|HTML_IMAGE_INLINE_END
value|"\\O[HTML-IMAGE-INLINE-END]"
end_define

begin_define
define|#
directive|define
name|HTML_IMAGE_CENTERED
value|".HTML-IMAGE"
end_define

begin_define
define|#
directive|define
name|HTML_IMAGE_RIGHT
value|".HTML-IMAGE-RIGHT"
end_define

begin_define
define|#
directive|define
name|HTML_IMAGE_LEFT
value|".HTML-IMAGE-LEFT"
end_define

begin_define
define|#
directive|define
name|HTML_IMAGE_END
value|".HTML-IMAGE-END"
end_define

end_unit

