begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* SPU opcode list     Copyright 2006 Free Software Foundation, Inc.     This file is part of GDB, GAS, and the GNU binutils.     This program is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2 of the License, or    (at your option) any later version.     This program is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.     You should have received a copy of the GNU General Public License along    with this program; if not, write to the Free Software Foundation, Inc.,    51 Franklin Street - Fifth Floor, Boston, MA 02110-1301, USA.  */
end_comment

begin_include
include|#
directive|include
file|"opcode/spu.h"
end_include

begin_comment
comment|/* This file holds the Spu opcode table */
end_comment

begin_escape
end_escape

begin_comment
comment|/*    Example contents of spu-insn.h       id_tag	mode	mode	type	opcode	mnemonic	asmtype	    dependency		FPU	L/S?	branch?	instruction                    QUAD	WORD                                               (0,RC,RB,RA,RT)    latency  			              		    APUOP(M_LQD,	1,	0,	RI9,	0x1f8,	"lqd",		ASM_RI9IDX,	00012,		FXU,	1,	0)	Load Quadword d-form   */
end_comment

begin_decl_stmt
specifier|const
name|struct
name|spu_opcode
name|spu_opcodes
index|[]
init|=
block|{
define|#
directive|define
name|APUOP
parameter_list|(
name|TAG
parameter_list|,
name|MACFORMAT
parameter_list|,
name|OPCODE
parameter_list|,
name|MNEMONIC
parameter_list|,
name|ASMFORMAT
parameter_list|,
name|DEP
parameter_list|,
name|PIPE
parameter_list|)
define|\
value|{ MACFORMAT, OPCODE, MNEMONIC, ASMFORMAT },
define|#
directive|define
name|APUOPFB
parameter_list|(
name|TAG
parameter_list|,
name|MACFORMAT
parameter_list|,
name|OPCODE
parameter_list|,
name|FB
parameter_list|,
name|MNEMONIC
parameter_list|,
name|ASMFORMAT
parameter_list|,
name|DEP
parameter_list|,
name|PIPE
parameter_list|)
define|\
value|{ MACFORMAT, OPCODE, MNEMONIC, ASMFORMAT },
include|#
directive|include
file|"opcode/spu-insns.h"
undef|#
directive|undef
name|APUOP
undef|#
directive|undef
name|APUOPFB
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|const
name|int
name|spu_num_opcodes
init|=
sizeof|sizeof
argument_list|(
name|spu_opcodes
argument_list|)
operator|/
sizeof|sizeof
argument_list|(
name|spu_opcodes
index|[
literal|0
index|]
argument_list|)
decl_stmt|;
end_decl_stmt

end_unit

