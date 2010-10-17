begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* xtensa-dis.c.  Disassembly functions for Xtensa.    Copyright 2003 Free Software Foundation, Inc.    Contributed by Bob Wilson at Tensilica, Inc. (bwilson@tensilica.com)     This file is part of GDB, GAS, and the GNU binutils.     GDB, GAS, and the GNU binutils are free software; you can redistribute    them and/or modify them under the terms of the GNU General Public    License as published by the Free Software Foundation; either version 2,    or (at your option) any later version.     GDB, GAS, and the GNU binutils are distributed in the hope that they    will be useful, but WITHOUT ANY WARRANTY; without even the implied    warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See    the GNU General Public License for more details.     You should have received a copy of the GNU General Public License along    with this file; see the file COPYING.  If not, write to the Free    Software Foundation, 59 Temple Place - Suite 330, Boston, MA 02111-1307,    USA.  */
end_comment

begin_include
include|#
directive|include
file|<stdlib.h>
end_include

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|<string.h>
end_include

begin_include
include|#
directive|include
file|"xtensa-isa.h"
end_include

begin_include
include|#
directive|include
file|"ansidecl.h"
end_include

begin_include
include|#
directive|include
file|"sysdep.h"
end_include

begin_include
include|#
directive|include
file|"dis-asm.h"
end_include

begin_include
include|#
directive|include
file|<setjmp.h>
end_include

begin_ifndef
ifndef|#
directive|ifndef
name|MAX
end_ifndef

begin_define
define|#
directive|define
name|MAX
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|(a> b ? a : b)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
specifier|static
name|char
modifier|*
name|state_names
index|[
literal|256
index|]
init|=
block|{
literal|"lbeg"
block|,
comment|/* 0 */
literal|"lend"
block|,
comment|/* 1 */
literal|"lcount"
block|,
comment|/* 2 */
literal|"sar"
block|,
comment|/* 3 */
literal|"br"
block|,
comment|/* 4 */
literal|"reserved_5"
block|,
comment|/* 5 */
literal|"reserved_6"
block|,
comment|/* 6 */
literal|"reserved_7"
block|,
comment|/* 7 */
literal|"av"
block|,
comment|/* 8 */
literal|"avh"
block|,
comment|/* 9 */
literal|"bv"
block|,
comment|/* 10 */
literal|"sav"
block|,
comment|/* 11 */
literal|"scompare1"
block|,
comment|/* 12 */
literal|"reserved_13"
block|,
comment|/* 13 */
literal|"reserved_14"
block|,
comment|/* 14 */
literal|"reserved_15"
block|,
comment|/* 15 */
literal|"acclo"
block|,
comment|/* 16 */
literal|"acchi"
block|,
comment|/* 17 */
literal|"reserved_18"
block|,
comment|/* 18 */
literal|"reserved_19"
block|,
comment|/* 19 */
literal|"reserved_20"
block|,
comment|/* 20 */
literal|"reserved_21"
block|,
comment|/* 21 */
literal|"reserved_22"
block|,
comment|/* 22 */
literal|"reserved_23"
block|,
comment|/* 23 */
literal|"reserved_24"
block|,
comment|/* 24 */
literal|"reserved_25"
block|,
comment|/* 25 */
literal|"reserved_26"
block|,
comment|/* 26 */
literal|"reserved_27"
block|,
comment|/* 27 */
literal|"reserved_28"
block|,
comment|/* 28 */
literal|"reserved_29"
block|,
comment|/* 29 */
literal|"reserved_30"
block|,
comment|/* 30 */
literal|"reserved_31"
block|,
comment|/* 31 */
literal|"mr0"
block|,
comment|/* 32 */
literal|"mr1"
block|,
comment|/* 33 */
literal|"mr2"
block|,
comment|/* 34 */
literal|"mr3"
block|,
comment|/* 35 */
literal|"reserved_36"
block|,
comment|/* 36 */
literal|"reserved_37"
block|,
comment|/* 37 */
literal|"reserved_38"
block|,
comment|/* 38 */
literal|"reserved_39"
block|,
comment|/* 39 */
literal|"reserved_40"
block|,
comment|/* 40 */
literal|"reserved_41"
block|,
comment|/* 41 */
literal|"reserved_42"
block|,
comment|/* 42 */
literal|"reserved_43"
block|,
comment|/* 43 */
literal|"reserved_44"
block|,
comment|/* 44 */
literal|"reserved_45"
block|,
comment|/* 45 */
literal|"reserved_46"
block|,
comment|/* 46 */
literal|"reserved_47"
block|,
comment|/* 47 */
literal|"reserved_48"
block|,
comment|/* 48 */
literal|"reserved_49"
block|,
comment|/* 49 */
literal|"reserved_50"
block|,
comment|/* 50 */
literal|"reserved_51"
block|,
comment|/* 51 */
literal|"reserved_52"
block|,
comment|/* 52 */
literal|"reserved_53"
block|,
comment|/* 53 */
literal|"reserved_54"
block|,
comment|/* 54 */
literal|"reserved_55"
block|,
comment|/* 55 */
literal|"reserved_56"
block|,
comment|/* 56 */
literal|"reserved_57"
block|,
comment|/* 57 */
literal|"reserved_58"
block|,
comment|/* 58 */
literal|"reserved_59"
block|,
comment|/* 59 */
literal|"reserved_60"
block|,
comment|/* 60 */
literal|"reserved_61"
block|,
comment|/* 61 */
literal|"reserved_62"
block|,
comment|/* 62 */
literal|"reserved_63"
block|,
comment|/* 63 */
literal|"reserved_64"
block|,
comment|/* 64 */
literal|"reserved_65"
block|,
comment|/* 65 */
literal|"reserved_66"
block|,
comment|/* 66 */
literal|"reserved_67"
block|,
comment|/* 67 */
literal|"reserved_68"
block|,
comment|/* 68 */
literal|"reserved_69"
block|,
comment|/* 69 */
literal|"reserved_70"
block|,
comment|/* 70 */
literal|"reserved_71"
block|,
comment|/* 71 */
literal|"wb"
block|,
comment|/* 72 */
literal|"ws"
block|,
comment|/* 73 */
literal|"reserved_74"
block|,
comment|/* 74 */
literal|"reserved_75"
block|,
comment|/* 75 */
literal|"reserved_76"
block|,
comment|/* 76 */
literal|"reserved_77"
block|,
comment|/* 77 */
literal|"reserved_78"
block|,
comment|/* 78 */
literal|"reserved_79"
block|,
comment|/* 79 */
literal|"reserved_80"
block|,
comment|/* 80 */
literal|"reserved_81"
block|,
comment|/* 81 */
literal|"reserved_82"
block|,
comment|/* 82 */
literal|"ptevaddr"
block|,
comment|/* 83 */
literal|"reserved_84"
block|,
comment|/* 84 */
literal|"reserved_85"
block|,
comment|/* 85 */
literal|"reserved_86"
block|,
comment|/* 86 */
literal|"reserved_87"
block|,
comment|/* 87 */
literal|"reserved_88"
block|,
comment|/* 88 */
literal|"reserved_89"
block|,
comment|/* 89 */
literal|"rasid"
block|,
comment|/* 90 */
literal|"itlbcfg"
block|,
comment|/* 91 */
literal|"dtlbcfg"
block|,
comment|/* 92 */
literal|"reserved_93"
block|,
comment|/* 93 */
literal|"reserved_94"
block|,
comment|/* 94 */
literal|"reserved_95"
block|,
comment|/* 95 */
literal|"ibreakenable"
block|,
comment|/* 96 */
literal|"reserved_97"
block|,
comment|/* 97 */
literal|"cacheattr"
block|,
comment|/* 98 */
literal|"reserved_99"
block|,
comment|/* 99 */
literal|"reserved_100"
block|,
comment|/* 100 */
literal|"reserved_101"
block|,
comment|/* 101 */
literal|"reserved_102"
block|,
comment|/* 102 */
literal|"reserved_103"
block|,
comment|/* 103 */
literal|"ddr"
block|,
comment|/* 104 */
literal|"reserved_105"
block|,
comment|/* 105 */
literal|"reserved_106"
block|,
comment|/* 106 */
literal|"reserved_107"
block|,
comment|/* 107 */
literal|"reserved_108"
block|,
comment|/* 108 */
literal|"reserved_109"
block|,
comment|/* 109 */
literal|"reserved_110"
block|,
comment|/* 110 */
literal|"reserved_111"
block|,
comment|/* 111 */
literal|"reserved_112"
block|,
comment|/* 112 */
literal|"reserved_113"
block|,
comment|/* 113 */
literal|"reserved_114"
block|,
comment|/* 114 */
literal|"reserved_115"
block|,
comment|/* 115 */
literal|"reserved_116"
block|,
comment|/* 116 */
literal|"reserved_117"
block|,
comment|/* 117 */
literal|"reserved_118"
block|,
comment|/* 118 */
literal|"reserved_119"
block|,
comment|/* 119 */
literal|"reserved_120"
block|,
comment|/* 120 */
literal|"reserved_121"
block|,
comment|/* 121 */
literal|"reserved_122"
block|,
comment|/* 122 */
literal|"reserved_123"
block|,
comment|/* 123 */
literal|"reserved_124"
block|,
comment|/* 124 */
literal|"reserved_125"
block|,
comment|/* 125 */
literal|"reserved_126"
block|,
comment|/* 126 */
literal|"reserved_127"
block|,
comment|/* 127 */
literal|"ibreaka0"
block|,
comment|/* 128 */
literal|"ibreaka1"
block|,
comment|/* 129 */
literal|"ibreaka2"
block|,
comment|/* 130 */
literal|"ibreaka3"
block|,
comment|/* 131 */
literal|"ibreaka4"
block|,
comment|/* 132 */
literal|"ibreaka5"
block|,
comment|/* 133 */
literal|"ibreaka6"
block|,
comment|/* 134 */
literal|"ibreaka7"
block|,
comment|/* 135 */
literal|"ibreaka8"
block|,
comment|/* 136 */
literal|"ibreaka9"
block|,
comment|/* 137 */
literal|"ibreaka10"
block|,
comment|/* 138 */
literal|"ibreaka11"
block|,
comment|/* 139 */
literal|"ibreaka12"
block|,
comment|/* 140 */
literal|"ibreaka13"
block|,
comment|/* 141 */
literal|"ibreaka14"
block|,
comment|/* 142 */
literal|"ibreaka15"
block|,
comment|/* 143 */
literal|"dbreaka0"
block|,
comment|/* 144 */
literal|"dbreaka1"
block|,
comment|/* 145 */
literal|"dbreaka2"
block|,
comment|/* 146 */
literal|"dbreaka3"
block|,
comment|/* 147 */
literal|"dbreaka4"
block|,
comment|/* 148 */
literal|"dbreaka5"
block|,
comment|/* 149 */
literal|"dbreaka6"
block|,
comment|/* 150 */
literal|"dbreaka7"
block|,
comment|/* 151 */
literal|"dbreaka8"
block|,
comment|/* 152 */
literal|"dbreaka9"
block|,
comment|/* 153 */
literal|"dbreaka10"
block|,
comment|/* 154 */
literal|"dbreaka11"
block|,
comment|/* 155 */
literal|"dbreaka12"
block|,
comment|/* 156 */
literal|"dbreaka13"
block|,
comment|/* 157 */
literal|"dbreaka14"
block|,
comment|/* 158 */
literal|"dbreaka15"
block|,
comment|/* 159 */
literal|"dbreakc0"
block|,
comment|/* 160 */
literal|"dbreakc1"
block|,
comment|/* 161 */
literal|"dbreakc2"
block|,
comment|/* 162 */
literal|"dbreakc3"
block|,
comment|/* 163 */
literal|"dbreakc4"
block|,
comment|/* 164 */
literal|"dbreakc5"
block|,
comment|/* 165 */
literal|"dbreakc6"
block|,
comment|/* 166 */
literal|"dbreakc7"
block|,
comment|/* 167 */
literal|"dbreakc8"
block|,
comment|/* 168 */
literal|"dbreakc9"
block|,
comment|/* 169 */
literal|"dbreakc10"
block|,
comment|/* 170 */
literal|"dbreakc11"
block|,
comment|/* 171 */
literal|"dbreakc12"
block|,
comment|/* 172 */
literal|"dbreakc13"
block|,
comment|/* 173 */
literal|"dbreakc14"
block|,
comment|/* 174 */
literal|"dbreakc15"
block|,
comment|/* 175 */
literal|"reserved_176"
block|,
comment|/* 176 */
literal|"epc1"
block|,
comment|/* 177 */
literal|"epc2"
block|,
comment|/* 178 */
literal|"epc3"
block|,
comment|/* 179 */
literal|"epc4"
block|,
comment|/* 180 */
literal|"epc5"
block|,
comment|/* 181 */
literal|"epc6"
block|,
comment|/* 182 */
literal|"epc7"
block|,
comment|/* 183 */
literal|"epc8"
block|,
comment|/* 184 */
literal|"epc9"
block|,
comment|/* 185 */
literal|"epc10"
block|,
comment|/* 186 */
literal|"epc11"
block|,
comment|/* 187 */
literal|"epc12"
block|,
comment|/* 188 */
literal|"epc13"
block|,
comment|/* 189 */
literal|"epc14"
block|,
comment|/* 190 */
literal|"epc15"
block|,
comment|/* 191 */
literal|"depc"
block|,
comment|/* 192 */
literal|"reserved_193"
block|,
comment|/* 193 */
literal|"eps2"
block|,
comment|/* 194 */
literal|"eps3"
block|,
comment|/* 195 */
literal|"eps4"
block|,
comment|/* 196 */
literal|"eps5"
block|,
comment|/* 197 */
literal|"eps6"
block|,
comment|/* 198 */
literal|"eps7"
block|,
comment|/* 199 */
literal|"eps8"
block|,
comment|/* 200 */
literal|"eps9"
block|,
comment|/* 201 */
literal|"eps10"
block|,
comment|/* 202 */
literal|"eps11"
block|,
comment|/* 203 */
literal|"eps12"
block|,
comment|/* 204 */
literal|"eps13"
block|,
comment|/* 205 */
literal|"eps14"
block|,
comment|/* 206 */
literal|"eps15"
block|,
comment|/* 207 */
literal|"reserved_208"
block|,
comment|/* 208 */
literal|"excsave1"
block|,
comment|/* 209 */
literal|"excsave2"
block|,
comment|/* 210 */
literal|"excsave3"
block|,
comment|/* 211 */
literal|"excsave4"
block|,
comment|/* 212 */
literal|"excsave5"
block|,
comment|/* 213 */
literal|"excsave6"
block|,
comment|/* 214 */
literal|"excsave7"
block|,
comment|/* 215 */
literal|"excsave8"
block|,
comment|/* 216 */
literal|"excsave9"
block|,
comment|/* 217 */
literal|"excsave10"
block|,
comment|/* 218 */
literal|"excsave11"
block|,
comment|/* 219 */
literal|"excsave12"
block|,
comment|/* 220 */
literal|"excsave13"
block|,
comment|/* 221 */
literal|"excsave14"
block|,
comment|/* 222 */
literal|"excsave15"
block|,
comment|/* 223 */
literal|"cpenable"
block|,
comment|/* 224 */
literal|"reserved_225"
block|,
comment|/* 225 */
literal|"interrupt"
block|,
comment|/* 226 */
literal|"interrupt2"
block|,
comment|/* 227 */
literal|"intenable"
block|,
comment|/* 228 */
literal|"reserved_229"
block|,
comment|/* 229 */
literal|"ps"
block|,
comment|/* 230 */
literal|"reserved_231"
block|,
comment|/* 231 */
literal|"exccause"
block|,
comment|/* 232 */
literal|"debugcause"
block|,
comment|/* 233 */
literal|"ccount"
block|,
comment|/* 234 */
literal|"prid"
block|,
comment|/* 235 */
literal|"icount"
block|,
comment|/* 236 */
literal|"icountlvl"
block|,
comment|/* 237 */
literal|"excvaddr"
block|,
comment|/* 238 */
literal|"reserved_239"
block|,
comment|/* 239 */
literal|"ccompare0"
block|,
comment|/* 240 */
literal|"ccompare1"
block|,
comment|/* 241 */
literal|"ccompare2"
block|,
comment|/* 242 */
literal|"ccompare3"
block|,
comment|/* 243 */
literal|"misc0"
block|,
comment|/* 244 */
literal|"misc1"
block|,
comment|/* 245 */
literal|"misc2"
block|,
comment|/* 246 */
literal|"misc3"
block|,
comment|/* 247 */
literal|"reserved_248"
block|,
comment|/* 248 */
literal|"reserved_249"
block|,
comment|/* 249 */
literal|"reserved_250"
block|,
comment|/* 250 */
literal|"reserved_251"
block|,
comment|/* 251 */
literal|"reserved_252"
block|,
comment|/* 252 */
literal|"reserved_253"
block|,
comment|/* 253 */
literal|"reserved_254"
block|,
comment|/* 254 */
literal|"reserved_255"
block|,
comment|/* 255 */
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|show_raw_fields
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|int
name|fetch_data
name|PARAMS
argument_list|(
operator|(
expr|struct
name|disassemble_info
operator|*
name|info
operator|,
name|bfd_vma
name|memaddr
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|void
name|print_xtensa_operand
name|PARAMS
argument_list|(
operator|(
name|bfd_vma
operator|,
expr|struct
name|disassemble_info
operator|*
operator|,
name|xtensa_operand
operator|,
name|unsigned
name|operand_val
operator|,
name|int
name|print_sr_name
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_struct
struct|struct
name|dis_private
block|{
name|bfd_byte
modifier|*
name|byte_buf
decl_stmt|;
name|jmp_buf
name|bailout
decl_stmt|;
block|}
struct|;
end_struct

begin_function
specifier|static
name|int
name|fetch_data
parameter_list|(
name|info
parameter_list|,
name|memaddr
parameter_list|)
name|struct
name|disassemble_info
modifier|*
name|info
decl_stmt|;
name|bfd_vma
name|memaddr
decl_stmt|;
block|{
name|int
name|length
decl_stmt|,
name|status
init|=
literal|0
decl_stmt|;
name|struct
name|dis_private
modifier|*
name|priv
init|=
operator|(
expr|struct
name|dis_private
operator|*
operator|)
name|info
operator|->
name|private_data
decl_stmt|;
name|int
name|insn_size
init|=
name|xtensa_insn_maxlength
argument_list|(
name|xtensa_default_isa
argument_list|)
decl_stmt|;
comment|/* Read the maximum instruction size, padding with zeros if we go past      the end of the text section.  This code will automatically adjust      length when we hit the end of the buffer.  */
name|memset
argument_list|(
name|priv
operator|->
name|byte_buf
argument_list|,
literal|0
argument_list|,
name|insn_size
argument_list|)
expr_stmt|;
for|for
control|(
name|length
operator|=
name|insn_size
init|;
name|length
operator|>
literal|0
condition|;
name|length
operator|--
control|)
block|{
name|status
operator|=
call|(
modifier|*
name|info
operator|->
name|read_memory_func
call|)
argument_list|(
name|memaddr
argument_list|,
name|priv
operator|->
name|byte_buf
argument_list|,
name|length
argument_list|,
name|info
argument_list|)
expr_stmt|;
if|if
condition|(
name|status
operator|==
literal|0
condition|)
return|return
name|length
return|;
block|}
call|(
modifier|*
name|info
operator|->
name|memory_error_func
call|)
argument_list|(
name|status
argument_list|,
name|memaddr
argument_list|,
name|info
argument_list|)
expr_stmt|;
name|longjmp
argument_list|(
name|priv
operator|->
name|bailout
argument_list|,
literal|1
argument_list|)
expr_stmt|;
comment|/*NOTREACHED*/
block|}
end_function

begin_function
specifier|static
name|void
name|print_xtensa_operand
parameter_list|(
name|memaddr
parameter_list|,
name|info
parameter_list|,
name|opnd
parameter_list|,
name|operand_val
parameter_list|,
name|print_sr_name
parameter_list|)
name|bfd_vma
name|memaddr
decl_stmt|;
name|struct
name|disassemble_info
modifier|*
name|info
decl_stmt|;
name|xtensa_operand
name|opnd
decl_stmt|;
name|unsigned
name|operand_val
decl_stmt|;
name|int
name|print_sr_name
decl_stmt|;
block|{
name|char
modifier|*
name|kind
init|=
name|xtensa_operand_kind
argument_list|(
name|opnd
argument_list|)
decl_stmt|;
name|int
name|signed_operand_val
decl_stmt|;
if|if
condition|(
name|show_raw_fields
condition|)
block|{
if|if
condition|(
name|operand_val
operator|<
literal|0xa
condition|)
call|(
modifier|*
name|info
operator|->
name|fprintf_func
call|)
argument_list|(
name|info
operator|->
name|stream
argument_list|,
literal|"%u"
argument_list|,
name|operand_val
argument_list|)
expr_stmt|;
else|else
call|(
modifier|*
name|info
operator|->
name|fprintf_func
call|)
argument_list|(
name|info
operator|->
name|stream
argument_list|,
literal|"0x%x"
argument_list|,
name|operand_val
argument_list|)
expr_stmt|;
return|return;
block|}
name|operand_val
operator|=
name|xtensa_operand_decode
argument_list|(
name|opnd
argument_list|,
name|operand_val
argument_list|)
expr_stmt|;
name|signed_operand_val
operator|=
operator|(
name|int
operator|)
name|operand_val
expr_stmt|;
if|if
condition|(
name|xtensa_operand_isPCRelative
argument_list|(
name|opnd
argument_list|)
condition|)
block|{
name|operand_val
operator|=
name|xtensa_operand_undo_reloc
argument_list|(
name|opnd
argument_list|,
name|operand_val
argument_list|,
name|memaddr
argument_list|)
expr_stmt|;
name|info
operator|->
name|target
operator|=
name|operand_val
expr_stmt|;
call|(
modifier|*
name|info
operator|->
name|print_address_func
call|)
argument_list|(
name|info
operator|->
name|target
argument_list|,
name|info
argument_list|)
expr_stmt|;
block|}
elseif|else
if|if
condition|(
operator|!
name|strcmp
argument_list|(
name|kind
argument_list|,
literal|"i"
argument_list|)
condition|)
block|{
if|if
condition|(
name|print_sr_name
operator|&&
name|signed_operand_val
operator|>=
literal|0
operator|&&
name|signed_operand_val
operator|<=
literal|255
condition|)
call|(
modifier|*
name|info
operator|->
name|fprintf_func
call|)
argument_list|(
name|info
operator|->
name|stream
argument_list|,
literal|"%s"
argument_list|,
name|state_names
index|[
name|signed_operand_val
index|]
argument_list|)
expr_stmt|;
elseif|else
if|if
condition|(
operator|(
name|signed_operand_val
operator|>
operator|-
literal|256
operator|)
operator|&&
operator|(
name|signed_operand_val
operator|<
literal|256
operator|)
condition|)
call|(
modifier|*
name|info
operator|->
name|fprintf_func
call|)
argument_list|(
name|info
operator|->
name|stream
argument_list|,
literal|"%d"
argument_list|,
name|signed_operand_val
argument_list|)
expr_stmt|;
else|else
call|(
modifier|*
name|info
operator|->
name|fprintf_func
call|)
argument_list|(
name|info
operator|->
name|stream
argument_list|,
literal|"0x%x"
argument_list|,
name|signed_operand_val
argument_list|)
expr_stmt|;
block|}
else|else
call|(
modifier|*
name|info
operator|->
name|fprintf_func
call|)
argument_list|(
name|info
operator|->
name|stream
argument_list|,
literal|"%s%u"
argument_list|,
name|kind
argument_list|,
name|operand_val
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|/* Print the Xtensa instruction at address MEMADDR on info->stream.    Returns length of the instruction in bytes.  */
end_comment

begin_function
name|int
name|print_insn_xtensa
parameter_list|(
name|memaddr
parameter_list|,
name|info
parameter_list|)
name|bfd_vma
name|memaddr
decl_stmt|;
name|struct
name|disassemble_info
modifier|*
name|info
decl_stmt|;
block|{
name|unsigned
name|operand_val
decl_stmt|;
name|int
name|bytes_fetched
decl_stmt|,
name|size
decl_stmt|,
name|maxsize
decl_stmt|,
name|i
decl_stmt|,
name|noperands
decl_stmt|;
name|xtensa_isa
name|isa
decl_stmt|;
name|xtensa_opcode
name|opc
decl_stmt|;
name|char
modifier|*
name|op_name
decl_stmt|;
name|int
name|print_sr_name
decl_stmt|;
name|struct
name|dis_private
name|priv
decl_stmt|;
specifier|static
name|bfd_byte
modifier|*
name|byte_buf
init|=
name|NULL
decl_stmt|;
specifier|static
name|xtensa_insnbuf
name|insn_buffer
init|=
name|NULL
decl_stmt|;
if|if
condition|(
operator|!
name|xtensa_default_isa
condition|)
operator|(
name|void
operator|)
name|xtensa_isa_init
argument_list|()
expr_stmt|;
name|info
operator|->
name|target
operator|=
literal|0
expr_stmt|;
name|maxsize
operator|=
name|xtensa_insn_maxlength
argument_list|(
name|xtensa_default_isa
argument_list|)
expr_stmt|;
comment|/* Set bytes_per_line to control the amount of whitespace between the hex      values and the opcode.  For Xtensa, we always print one "chunk" and we      vary bytes_per_chunk to determine how many bytes to print.  (objdump      would apparently prefer that we set bytes_per_chunk to 1 and vary      bytes_per_line but that makes it hard to fit 64-bit instructions on      an 80-column screen.)  The value of bytes_per_line here is not exactly      right, because objdump adds an extra space for each chunk so that the      amount of whitespace depends on the chunk size.  Oh well, it's good      enough....  Note that we set the minimum size to 4 to accomodate      literal pools.  */
name|info
operator|->
name|bytes_per_line
operator|=
name|MAX
argument_list|(
name|maxsize
argument_list|,
literal|4
argument_list|)
expr_stmt|;
comment|/* Allocate buffers the first time through.  */
if|if
condition|(
operator|!
name|insn_buffer
condition|)
name|insn_buffer
operator|=
name|xtensa_insnbuf_alloc
argument_list|(
name|xtensa_default_isa
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|byte_buf
condition|)
name|byte_buf
operator|=
operator|(
name|bfd_byte
operator|*
operator|)
name|malloc
argument_list|(
name|MAX
argument_list|(
name|maxsize
argument_list|,
literal|4
argument_list|)
argument_list|)
expr_stmt|;
name|priv
operator|.
name|byte_buf
operator|=
name|byte_buf
expr_stmt|;
name|info
operator|->
name|private_data
operator|=
operator|(
name|PTR
operator|)
operator|&
name|priv
expr_stmt|;
if|if
condition|(
name|setjmp
argument_list|(
name|priv
operator|.
name|bailout
argument_list|)
operator|!=
literal|0
condition|)
comment|/* Error return.  */
return|return
operator|-
literal|1
return|;
comment|/* Don't set "isa" before the setjmp to keep the compiler from griping.  */
name|isa
operator|=
name|xtensa_default_isa
expr_stmt|;
comment|/* Fetch the maximum size instruction.  */
name|bytes_fetched
operator|=
name|fetch_data
argument_list|(
name|info
argument_list|,
name|memaddr
argument_list|)
expr_stmt|;
comment|/* Copy the bytes into the decode buffer.  */
name|memset
argument_list|(
name|insn_buffer
argument_list|,
literal|0
argument_list|,
operator|(
name|xtensa_insnbuf_size
argument_list|(
name|isa
argument_list|)
operator|*
sizeof|sizeof
argument_list|(
name|xtensa_insnbuf_word
argument_list|)
operator|)
argument_list|)
expr_stmt|;
name|xtensa_insnbuf_from_chars
argument_list|(
name|isa
argument_list|,
name|insn_buffer
argument_list|,
name|priv
operator|.
name|byte_buf
argument_list|)
expr_stmt|;
name|opc
operator|=
name|xtensa_decode_insn
argument_list|(
name|isa
argument_list|,
name|insn_buffer
argument_list|)
expr_stmt|;
if|if
condition|(
name|opc
operator|==
name|XTENSA_UNDEFINED
operator|||
operator|(
operator|(
name|size
operator|=
name|xtensa_insn_length
argument_list|(
name|isa
argument_list|,
name|opc
argument_list|)
operator|)
operator|>
name|bytes_fetched
operator|)
condition|)
block|{
call|(
modifier|*
name|info
operator|->
name|fprintf_func
call|)
argument_list|(
name|info
operator|->
name|stream
argument_list|,
literal|".byte %#02x"
argument_list|,
name|priv
operator|.
name|byte_buf
index|[
literal|0
index|]
argument_list|)
expr_stmt|;
return|return
literal|1
return|;
block|}
name|op_name
operator|=
operator|(
name|char
operator|*
operator|)
name|xtensa_opcode_name
argument_list|(
name|isa
argument_list|,
name|opc
argument_list|)
expr_stmt|;
call|(
modifier|*
name|info
operator|->
name|fprintf_func
call|)
argument_list|(
name|info
operator|->
name|stream
argument_list|,
literal|"%s"
argument_list|,
name|op_name
argument_list|)
expr_stmt|;
name|print_sr_name
operator|=
operator|(
operator|!
name|strcasecmp
argument_list|(
name|op_name
argument_list|,
literal|"wsr"
argument_list|)
operator|||
operator|!
name|strcasecmp
argument_list|(
name|op_name
argument_list|,
literal|"xsr"
argument_list|)
operator|||
operator|!
name|strcasecmp
argument_list|(
name|op_name
argument_list|,
literal|"rsr"
argument_list|)
operator|)
expr_stmt|;
comment|/* Print the operands (if any).  */
name|noperands
operator|=
name|xtensa_num_operands
argument_list|(
name|isa
argument_list|,
name|opc
argument_list|)
expr_stmt|;
if|if
condition|(
name|noperands
operator|>
literal|0
condition|)
block|{
name|int
name|first
init|=
literal|1
decl_stmt|;
call|(
modifier|*
name|info
operator|->
name|fprintf_func
call|)
argument_list|(
name|info
operator|->
name|stream
argument_list|,
literal|"\t"
argument_list|)
expr_stmt|;
for|for
control|(
name|i
operator|=
literal|0
init|;
name|i
operator|<
name|noperands
condition|;
name|i
operator|++
control|)
block|{
name|xtensa_operand
name|opnd
init|=
name|xtensa_get_operand
argument_list|(
name|isa
argument_list|,
name|opc
argument_list|,
name|i
argument_list|)
decl_stmt|;
if|if
condition|(
name|first
condition|)
name|first
operator|=
literal|0
expr_stmt|;
else|else
call|(
modifier|*
name|info
operator|->
name|fprintf_func
call|)
argument_list|(
name|info
operator|->
name|stream
argument_list|,
literal|", "
argument_list|)
expr_stmt|;
name|operand_val
operator|=
name|xtensa_operand_get_field
argument_list|(
name|opnd
argument_list|,
name|insn_buffer
argument_list|)
expr_stmt|;
name|print_xtensa_operand
argument_list|(
name|memaddr
argument_list|,
name|info
argument_list|,
name|opnd
argument_list|,
name|operand_val
argument_list|,
name|print_sr_name
argument_list|)
expr_stmt|;
block|}
block|}
name|info
operator|->
name|bytes_per_chunk
operator|=
name|size
expr_stmt|;
name|info
operator|->
name|display_endian
operator|=
name|info
operator|->
name|endian
expr_stmt|;
return|return
name|size
return|;
block|}
end_function

end_unit

