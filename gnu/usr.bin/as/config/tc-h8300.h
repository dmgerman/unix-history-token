begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* This file is tc-h8300.h     Copyright (C) 1987-1992 Free Software Foundation, Inc.     This file is part of GAS, the GNU Assembler.     GAS is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2, or (at your option)    any later version.     GAS is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.     You should have received a copy of the GNU General Public License    along with GAS; see the file COPYING.  If not, write to    the Free Software Foundation, 675 Mass Ave, Cambridge, MA 02139, USA.  */
end_comment

begin_define
define|#
directive|define
name|TC_H8300
end_define

begin_comment
comment|/* This macro translates between an internal fix and an coff reloc type */
end_comment

begin_define
define|#
directive|define
name|TC_COFF_FIX2RTYPE
parameter_list|(
name|fixP
parameter_list|)
value|abort();
end_define

begin_define
define|#
directive|define
name|BFD_ARCH
value|bfd_arch_h8300
end_define

begin_define
define|#
directive|define
name|COFF_MAGIC
value|0x8300
end_define

begin_define
define|#
directive|define
name|TC_COUNT_RELOC
parameter_list|(
name|x
parameter_list|)
value|(1)
end_define

begin_define
define|#
directive|define
name|TC_RELOC_MANGLE
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|,
name|c
parameter_list|)
value|tc_reloc_mangle(a,b,c)
end_define

begin_define
define|#
directive|define
name|DO_NOT_STRIP
value|1
end_define

begin_define
define|#
directive|define
name|DO_STRIP
value|0
end_define

begin_define
define|#
directive|define
name|LISTING_HEADER
value|"Hitachi H8/300 GAS "
end_define

begin_comment
comment|/* end of tc-h8300.h */
end_comment

end_unit

