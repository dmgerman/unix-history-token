begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* tc-a29k.h -- Assemble for the AMD 29000.    Copyright (C) 1989, 1990, 1991, 1992 Free Software Foundation, Inc.     This file is part of GAS, the GNU Assembler.     GAS is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2, or (at your option)    any later version.     GAS is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.     You should have received a copy of the GNU General Public License    along with GAS; see the file COPYING.  If not, write to    the Free Software Foundation, 675 Mass Ave, Cambridge, MA 02139, USA.  */
end_comment

begin_define
define|#
directive|define
name|TC_A29K
end_define

begin_define
define|#
directive|define
name|NO_LISTING
end_define

begin_define
define|#
directive|define
name|tc_aout_pre_write_hook
parameter_list|(
name|x
parameter_list|)
value|{;}
end_define

begin_comment
comment|/* not used */
end_comment

begin_define
define|#
directive|define
name|tc_coff_symbol_emit_hook
parameter_list|(
name|a
parameter_list|)
value|{;}
end_define

begin_comment
comment|/* not used */
end_comment

begin_define
define|#
directive|define
name|tc_crawl_symbol_chain
parameter_list|(
name|a
parameter_list|)
value|{;}
end_define

begin_comment
comment|/* not used */
end_comment

begin_define
define|#
directive|define
name|tc_headers_hook
parameter_list|(
name|a
parameter_list|)
value|{;}
end_define

begin_comment
comment|/* not used */
end_comment

begin_define
define|#
directive|define
name|AOUT_MACHTYPE
value|101
end_define

begin_define
define|#
directive|define
name|TC_COFF_FIX2RTYPE
parameter_list|(
name|fix_ptr
parameter_list|)
value|tc_coff_fix2rtype(fix_ptr)
end_define

begin_define
define|#
directive|define
name|BFD_ARCH
value|bfd_arch_a29k
end_define

begin_define
define|#
directive|define
name|COFF_MAGIC
value|SIPFBOMAGIC
end_define

begin_comment
comment|/* Should the reloc be output ?    on the 29k, this is true only if there is a symbol attatched.    on the h8, this is allways true, since no fixup is done    */
end_comment

begin_define
define|#
directive|define
name|TC_COUNT_RELOC
parameter_list|(
name|x
parameter_list|)
value|(x->fx_addsy)
end_define

begin_comment
comment|/* end of tc-a29k.h */
end_comment

end_unit

