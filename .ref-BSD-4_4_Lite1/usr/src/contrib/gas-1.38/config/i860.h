begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* i860.h -- Header file for the I860    Copyright (C) 1989 Free Software Foundation, Inc.  This file is part of GAS, the GNU Assembler.  GAS is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 1, or (at your option) any later version.  GAS is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with GAS; see the file COPYING.  If not, write to the Free Software Foundation, 675 Mass Ave, Cambridge, MA 02139, USA.  */
end_comment

begin_enum
enum|enum
name|reloc_type
comment|/* NOTE: three bits max, see struct reloc_info_i860.r_type */
block|{
name|NO_RELOC
init|=
literal|0
block|,
name|BRADDR
block|,
name|LOW0
block|,
name|LOW1
block|,
name|LOW2
block|,
name|LOW3
block|,
name|LOW4
block|,
name|SPLIT0
block|,
name|SPLIT1
block|,
name|SPLIT2
block|,
name|RELOC_32
block|, }
enum|;
end_enum

begin_enum
enum|enum
name|highlow_type
comment|/* NOTE: two bits max, see reloc_info_i860.r_type */
block|{
name|NO_SPEC
init|=
literal|0
block|,
name|PAIR
block|,
name|HIGH
block|,
name|HIGHADJ
block|, }
enum|;
end_enum

begin_struct
struct|struct
name|reloc_info_i860
block|{
name|unsigned
name|long
name|int
name|r_address
decl_stmt|;
comment|/*  * Using bit fields here is a bad idea because the order is not portable. :-(  */
name|unsigned
name|int
name|r_symbolnum
range|:
literal|24
decl_stmt|;
name|unsigned
name|int
name|r_pcrel
range|:
literal|1
decl_stmt|;
name|unsigned
name|int
name|r_extern
range|:
literal|1
decl_stmt|;
comment|/* combining the two field simplifies the argument passing in "new_fix()" */
comment|/* and is compatible with the existing Sparc #ifdef's */
comment|/* r_type:  highlow_type - bits 5,4; reloc_type - bits 3-0 */
name|unsigned
name|int
name|r_type
range|:
literal|6
decl_stmt|;
name|long
name|int
name|r_addend
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|relocation_info
value|reloc_info_i860
end_define

end_unit

