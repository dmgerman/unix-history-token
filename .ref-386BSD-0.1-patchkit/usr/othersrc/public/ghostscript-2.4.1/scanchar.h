begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Copyright (C) 1990, 1991 Aladdin Enterprises.  All rights reserved.    Distributed by Free Software Foundation, Inc.  This file is part of Ghostscript.  Ghostscript is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY.  No author or distributor accepts responsibility to anyone for the consequences of using it or for whether it serves any particular purpose or works at all, unless he says so in writing.  Refer to the Ghostscript General Public License for full details.  Everyone is granted permission to copy, modify and redistribute Ghostscript, but only under the conditions described in the Ghostscript General Public License.  A copy of this license is supposed to have been given to you along with Ghostscript so you can know your rights and responsibilities.  It should be in a file named COPYING.  Among other things, the copyright notice and this notice must be preserved on all copies.  */
end_comment

begin_comment
comment|/* scanchar.h */
end_comment

begin_comment
comment|/* Character scanning table for Ghostscript */
end_comment

begin_comment
comment|/* An array for fast scanning of names, numbers, and hex strings. */
end_comment

begin_comment
comment|/*  Indexed by character code (including EOFC and ERRC), it contains: */
end_comment

begin_comment
comment|/*	0 - max_radix-1 for valid digits, */
end_comment

begin_comment
comment|/*	ctype_name for other characters valid in names, */
end_comment

begin_comment
comment|/*	ctype_btoken for characters introducing binary tokens */
end_comment

begin_comment
comment|/*	  (if the binary token feature is enabled), */
end_comment

begin_comment
comment|/*	ctype_space for whitespace characters, */
end_comment

begin_comment
comment|/*	ctype_eof for end-of-file, and */
end_comment

begin_comment
comment|/*	ctype_other for everything else. */
end_comment

begin_comment
comment|/* This table is initialized in iscan.c, used in iscan.c and stream.c. */
end_comment

begin_decl_stmt
specifier|extern
name|byte
name|scan_char_array
index|[
literal|258
index|]
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|scan_char_decoder
value|(&scan_char_array[2])
end_define

begin_comment
comment|/* account for EOFC/ERRC */
end_comment

begin_define
define|#
directive|define
name|min_radix
value|2
end_define

begin_define
define|#
directive|define
name|max_radix
value|36
end_define

begin_define
define|#
directive|define
name|ctype_name
value|100
end_define

begin_define
define|#
directive|define
name|ctype_btoken
value|101
end_define

begin_define
define|#
directive|define
name|ctype_space
value|102
end_define

begin_define
define|#
directive|define
name|ctype_other
value|103
end_define

begin_define
define|#
directive|define
name|ctype_eof
value|104
end_define

begin_comment
comment|/* Special characters with no \xxx representation */
end_comment

begin_define
define|#
directive|define
name|char_NULL
value|0
end_define

begin_define
define|#
directive|define
name|char_VT
value|013
end_define

begin_comment
comment|/* ^K, vertical tab */
end_comment

begin_define
define|#
directive|define
name|char_DOS_EOF
value|032
end_define

begin_comment
comment|/* ^Z */
end_comment

end_unit

