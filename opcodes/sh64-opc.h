begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Declarations for SH64 opcodes.    Copyright (C) 2000, 2001 Free Software Foundation, Inc.  This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version.  This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with this program; if not, write to the Free Software Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_SH64_OPC_INCLUDED_H
end_ifndef

begin_define
define|#
directive|define
name|_SH64_OPC_INCLUDED_H
end_define

begin_typedef
typedef|typedef
enum|enum
block|{
comment|/* A placeholder.  */
name|OFFSET_NONE
init|=
literal|0
block|,
comment|/* Bit number for where to insert operand.  */
name|OFFSET_4
init|=
literal|4
block|,
name|OFFSET_9
init|=
literal|9
block|,
name|OFFSET_10
init|=
literal|10
block|,
name|OFFSET_20
init|=
literal|20
block|}
name|shmedia_nibble_type
typedef|;
end_typedef

begin_typedef
typedef|typedef
enum|enum
block|{
comment|/* First a placeholder.  */
name|A_NONE
init|=
literal|0
block|,
comment|/* Registers.  */
name|A_GREG_M
block|,
name|A_GREG_N
block|,
name|A_GREG_D
block|,
name|A_FREG_G
block|,
name|A_FREG_H
block|,
name|A_FREG_F
block|,
name|A_DREG_G
block|,
name|A_DREG_H
block|,
name|A_DREG_F
block|,
name|A_FVREG_G
block|,
name|A_FVREG_H
block|,
name|A_FVREG_F
block|,
name|A_FMREG_G
block|,
name|A_FMREG_H
block|,
name|A_FMREG_F
block|,
name|A_FPREG_G
block|,
name|A_FPREG_H
block|,
name|A_FPREG_F
block|,
name|A_TREG_A
block|,
name|A_TREG_B
block|,
name|A_CREG_K
block|,
name|A_CREG_J
block|,
comment|/* This one is only used in a shmedia_get_operand.  */
name|A_IMMM
block|,
comment|/* Copy of previous register.  */
name|A_REUSE_PREV
block|,
comment|/* Unsigned 5-bit operand.  */
name|A_IMMU5
block|,
comment|/* Signed 6-bit operand.  */
name|A_IMMS6
block|,
comment|/* Signed operand, 6 bits<< 5.  */
name|A_IMMS6BY32
block|,
comment|/* Unsigned 6-bit operand.  */
name|A_IMMU6
block|,
comment|/* Signed 10-bit operand.  */
name|A_IMMS10
block|,
comment|/* Signed operand, 10 bits<< 0.  */
name|A_IMMS10BY1
block|,
comment|/* Signed operand, 10 bits<< 1.  */
name|A_IMMS10BY2
block|,
comment|/* Signed operand, 10 bits<< 2.  */
name|A_IMMS10BY4
block|,
comment|/* Signed operand, 10 bits<< 3.  */
name|A_IMMS10BY8
block|,
comment|/* Signed 16-bit operand.  */
name|A_IMMS16
block|,
comment|/* Unsigned 16-bit operand.  */
name|A_IMMU16
block|,
comment|/* PC-relative signed operand, 16 bits<< 2, for PTA and PTB insns.  */
name|A_PCIMMS16BY4
block|,
comment|/* PC relative signed operand, 16 bits<< 2, for PT insns.  Also adjusts      the opcode to be PTA or PTB.  */
name|A_PCIMMS16BY4_PT
block|, }
name|shmedia_arg_type
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|char
modifier|*
name|name
decl_stmt|;
name|shmedia_arg_type
name|arg
index|[
literal|4
index|]
decl_stmt|;
name|shmedia_nibble_type
name|nibbles
index|[
literal|4
index|]
decl_stmt|;
name|unsigned
name|long
name|opcode_base
decl_stmt|;
block|}
name|shmedia_opcode_info
typedef|;
end_typedef

begin_decl_stmt
specifier|extern
specifier|const
name|shmedia_opcode_info
name|shmedia_table
index|[]
decl_stmt|;
end_decl_stmt

begin_typedef
typedef|typedef
struct|struct
block|{
name|int
name|cregno
decl_stmt|;
name|char
modifier|*
name|name
decl_stmt|;
block|}
name|shmedia_creg_info
typedef|;
end_typedef

begin_decl_stmt
specifier|extern
specifier|const
name|shmedia_creg_info
name|shmedia_creg_table
index|[]
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|SHMEDIA_LIKELY_BIT
value|0x00000200
end_define

begin_define
define|#
directive|define
name|SHMEDIA_PT_OPC
value|0xe8000000
end_define

begin_define
define|#
directive|define
name|SHMEDIA_PTB_BIT
value|0x04000000
end_define

begin_define
define|#
directive|define
name|SHMEDIA_PTA_OPC
value|0xe8000000
end_define

begin_define
define|#
directive|define
name|SHMEDIA_PTB_OPC
value|0xec000000
end_define

begin_comment
comment|/* Note that this is ptrel/u.  "Or" in SHMEDIA_LIKELY_BIT for ptrel/l.  */
end_comment

begin_define
define|#
directive|define
name|SHMEDIA_PTREL_OPC
value|0x6bf50000
end_define

begin_define
define|#
directive|define
name|SHMEDIA_MOVI_OPC
value|0xcc000000
end_define

begin_define
define|#
directive|define
name|SHMEDIA_SHORI_OPC
value|0xc8000000
end_define

begin_define
define|#
directive|define
name|SHMEDIA_ADDI_OPC
value|0xd0000000
end_define

begin_define
define|#
directive|define
name|SHMEDIA_ADD_OPC
value|0x00090000
end_define

begin_define
define|#
directive|define
name|SHMEDIA_NOP_OPC
value|0x6ff0fff0
end_define

begin_define
define|#
directive|define
name|SHMEDIA_TEMP_REG
value|25
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _SH64_OPC_INCLUDED_H */
end_comment

end_unit

