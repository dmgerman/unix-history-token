begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Macros to support INSN_ADDRESSES    Copyright (C) 2000 Free Software Foundation, Inc.  This file is part of GCC.  GCC is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2, or (at your option) any later version.  GCC is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with GCC; see the file COPYING.  If not, write to the Free Software Foundation, 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|GCC_INSN_ADDR_H
end_ifndef

begin_define
define|#
directive|define
name|GCC_INSN_ADDR_H
end_define

begin_include
include|#
directive|include
file|"varray.h"
end_include

begin_decl_stmt
specifier|extern
name|varray_type
name|insn_addresses_
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|insn_current_address
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|INSN_ADDRESSES_DEFN
parameter_list|()
value|varray_type insn_addresses_
end_define

begin_define
define|#
directive|define
name|INSN_ADDRESSES
parameter_list|(
name|id
parameter_list|)
value|VARRAY_INT (insn_addresses_, (id))
end_define

begin_define
define|#
directive|define
name|INSN_ADDRESSES_ALLOC
parameter_list|(
name|size
parameter_list|)
define|\
value|VARRAY_INT_INIT (insn_addresses_, (size), "insn_addresses")
end_define

begin_define
define|#
directive|define
name|INSN_ADDRESSES_FREE
parameter_list|()
value|VARRAY_FREE (insn_addresses_)
end_define

begin_define
define|#
directive|define
name|INSN_ADDRESSES_SET_P
parameter_list|()
value|(insn_addresses_ != 0)
end_define

begin_define
define|#
directive|define
name|INSN_ADDRESSES_SIZE
parameter_list|()
value|VARRAY_SIZE (insn_addresses_)
end_define

begin_define
define|#
directive|define
name|INSN_ADDRESSES_NEW
parameter_list|(
name|insn
parameter_list|,
name|addr
parameter_list|)
value|do \   {									\     unsigned insn_uid__ = INSN_UID ((insn));				\     int insn_addr__ = (addr);						\ 									\     if (INSN_ADDRESSES_SET_P ())					\       {									\ 	if (INSN_ADDRESSES_SIZE ()<= insn_uid__)			\ 	  VARRAY_GROW (insn_addresses_, insn_uid__ + 1);		\ 	INSN_ADDRESSES (insn_uid__) = insn_addr__;			\       }									\   }									\ while (0)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! GCC_INSN_ADDR_H */
end_comment

end_unit

