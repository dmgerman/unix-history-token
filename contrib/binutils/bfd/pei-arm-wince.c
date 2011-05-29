begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* BFD back-end for ARM WINCE PE IMAGE COFF files.    Copyright 2006 Free Software Foundation, Inc.     This file is part of BFD, the Binary File Descriptor library.     This program is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2 of the License, or    (at your option) any later version.     This program is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.     You should have received a copy of the GNU General Public License    along with this program; if not, write to the Free Software    Foundation, Inc., 51 Franklin Street - Fifth Floor, Boston, MA 02110-1301, USA.  */
end_comment

begin_define
define|#
directive|define
name|TARGET_UNDERSCORE
value|0
end_define

begin_define
define|#
directive|define
name|USER_LABEL_PREFIX
value|""
end_define

begin_define
define|#
directive|define
name|TARGET_LITTLE_SYM
value|arm_wince_pei_little_vec
end_define

begin_define
define|#
directive|define
name|TARGET_LITTLE_NAME
value|"pei-arm-wince-little"
end_define

begin_define
define|#
directive|define
name|TARGET_BIG_SYM
value|arm_wince_pei_big_vec
end_define

begin_define
define|#
directive|define
name|TARGET_BIG_NAME
value|"pei-arm-wince-big"
end_define

begin_define
define|#
directive|define
name|LOCAL_LABEL_PREFIX
value|"."
end_define

begin_include
include|#
directive|include
file|"pei-arm.c"
end_include

end_unit

