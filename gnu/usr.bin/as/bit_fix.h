begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* write.h     Copyright (C) 1987, 1992 Free Software Foundation, Inc.     This file is part of GAS, the GNU Assembler.     GAS is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2, or (at your option)    any later version.     GAS is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.     You should have received a copy of the GNU General Public License    along with GAS; see the file COPYING.  If not, write to    the Free Software Foundation, 675 Mass Ave, Cambridge, MA 02139, USA.  */
end_comment

begin_comment
comment|/*  * $FreeBSD$  */
end_comment

begin_comment
comment|/* The bit_fix was implemented to support machines that need variables    to be inserted in bitfields other than 1, 2 and 4 bytes.    Furthermore it gives us a possibillity to mask in bits in the symbol    when it's fixed in the objectcode and check the symbols limits.     The or-mask is used to set the huffman bits in displacements for the    ns32k port.    The acbi, addqi, movqi, cmpqi instruction requires an assembler that    can handle bitfields. Ie handle an expression, evaluate it and insert    the result in an some bitfield. ( ex: 5 bits in a short field of a opcode)    */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__bit_fix_h__
end_ifndef

begin_define
define|#
directive|define
name|__bit_fix_h__
end_define

begin_struct
struct|struct
name|bit_fix
block|{
name|int
name|fx_bit_size
decl_stmt|;
comment|/* Length of bitfield */
name|int
name|fx_bit_offset
decl_stmt|;
comment|/* Bit offset to bitfield */
name|long
name|fx_bit_base
decl_stmt|;
comment|/* Where do we apply the bitfix. 				      If this is zero, default is assumed. */
name|long
name|fx_bit_base_adj
decl_stmt|;
comment|/* Adjustment of base */
name|long
name|fx_bit_max
decl_stmt|;
comment|/* Signextended max for bitfield */
name|long
name|fx_bit_min
decl_stmt|;
comment|/* Signextended min for bitfield */
name|long
name|fx_bit_add
decl_stmt|;
comment|/* Or mask, used for huffman prefix */
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|bit_fix
name|bit_fixS
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __bit_fix_h__ */
end_comment

begin_comment
comment|/* end of bit_fix.h */
end_comment

end_unit

