begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*   Copyright 2001 Free Software Foundation, Inc.    This file is part of GNU Binutils.    This program is free software; you can redistribute it and/or modify   it under the terms of the GNU General Public License as published by   the Free Software Foundation; either version 2 of the License, or   (at your option) any later version.    This program is distributed in the hope that it will be useful,   but WITHOUT ANY WARRANTY; without even the implied warranty of   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the   GNU General Public License for more details.    You should have received a copy of the GNU General Public License   along with this program; if not, write to the Free Software   Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
end_comment

begin_comment
comment|/* This program generates z8k-opc.h */
end_comment

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_include
include|#
directive|include
file|"sysdep.h"
end_include

begin_define
define|#
directive|define
name|BYTE_INFO_LEN
value|10
end_define

begin_struct
struct|struct
name|op
block|{
name|char
modifier|*
name|flags
decl_stmt|;
name|int
name|cycles
decl_stmt|;
name|char
name|type
decl_stmt|;
name|char
modifier|*
name|bits
decl_stmt|;
name|char
modifier|*
name|name
decl_stmt|;
name|char
modifier|*
name|flavor
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|iswhite
parameter_list|(
name|x
parameter_list|)
value|((x) == ' ' || (x) == '\t')
end_define

begin_decl_stmt
name|struct
name|op
name|opt
index|[]
init|=
block|{
literal|"------"
block|,
literal|10
block|,
literal|8
block|,
literal|"0000 1110 imm8"
block|,
literal|"ext0e imm8"
block|,
literal|0
block|,
literal|"------"
block|,
literal|10
block|,
literal|8
block|,
literal|"0000 1111 imm8"
block|,
literal|"ext0f imm8"
block|,
literal|0
block|,
literal|"------"
block|,
literal|10
block|,
literal|8
block|,
literal|"1000 1110 imm8"
block|,
literal|"ext8e imm8"
block|,
literal|0
block|,
literal|"------"
block|,
literal|10
block|,
literal|8
block|,
literal|"1000 1111 imm8"
block|,
literal|"ext8f imm8"
block|,
literal|0
block|,
literal|"------"
block|,
literal|10
block|,
literal|8
block|,
literal|"0011 0110 imm8"
block|,
literal|"rsvd36"
block|,
literal|0
block|,
literal|"------"
block|,
literal|10
block|,
literal|8
block|,
literal|"0011 1000 imm8"
block|,
literal|"rsvd38"
block|,
literal|0
block|,
literal|"------"
block|,
literal|10
block|,
literal|8
block|,
literal|"0111 1000 imm8"
block|,
literal|"rsvd78"
block|,
literal|0
block|,
literal|"------"
block|,
literal|10
block|,
literal|8
block|,
literal|"0111 1110 imm8"
block|,
literal|"rsvd7e"
block|,
literal|0
block|,
literal|"------"
block|,
literal|10
block|,
literal|8
block|,
literal|"1001 1101 imm8"
block|,
literal|"rsvd9d"
block|,
literal|0
block|,
literal|"------"
block|,
literal|10
block|,
literal|8
block|,
literal|"1001 1111 imm8"
block|,
literal|"rsvd9f"
block|,
literal|0
block|,
literal|"------"
block|,
literal|10
block|,
literal|8
block|,
literal|"1011 1001 imm8"
block|,
literal|"rsvdb9"
block|,
literal|0
block|,
literal|"------"
block|,
literal|10
block|,
literal|8
block|,
literal|"1011 1111 imm8"
block|,
literal|"rsvdbf"
block|,
literal|0
block|,
literal|"---V--"
block|,
literal|11
block|,
literal|16
block|,
literal|"1011 1011 ssN0 1001 0000 rrrr ddN0 1000"
block|,
literal|"ldd @rd,@rs,rr"
block|,
literal|0
block|,
literal|"---V--"
block|,
literal|11
block|,
literal|16
block|,
literal|"1011 1011 ssN0 1001 0000 rrrr ddN0 0000"
block|,
literal|"lddr @rd,@rs,rr"
block|,
literal|0
block|,
literal|"---V--"
block|,
literal|11
block|,
literal|8
block|,
literal|"1011 1010 ssN0 1001 0000 rrrr ddN0 0000"
block|,
literal|"lddrb @rd,@rs,rr"
block|,
literal|0
block|,
literal|"---V--"
block|,
literal|11
block|,
literal|16
block|,
literal|"1011 1011 ssN0 0001 0000 rrrr ddN0 0000"
block|,
literal|"ldir @rd,@rs,rr"
block|,
literal|0
block|,
literal|"CZSV--"
block|,
literal|11
block|,
literal|16
block|,
literal|"1011 1011 ssN0 0000 0000 rrrr dddd cccc"
block|,
literal|"cpi rd,@rs,rr,cc"
block|,
literal|0
block|,
literal|"CZSV--"
block|,
literal|11
block|,
literal|16
block|,
literal|"1011 1011 ssN0 0100 0000 rrrr dddd cccc"
block|,
literal|"cpir rd,@rs,rr,cc"
block|,
literal|0
block|,
literal|"CZSV--"
block|,
literal|11
block|,
literal|16
block|,
literal|"1011 1011 ssN0 1100 0000 rrrr dddd cccc"
block|,
literal|"cpdr rd,@rs,rr,cc"
block|,
literal|0
block|,
literal|"---V--"
block|,
literal|11
block|,
literal|16
block|,
literal|"1011 1011 ssN0 0001 0000 rrrr ddN0 1000"
block|,
literal|"ldi @rd,@rs,rr"
block|,
literal|0
block|,
literal|"CZSV--"
block|,
literal|11
block|,
literal|16
block|,
literal|"1011 1011 ssN0 1000 0000 rrrr dddd cccc"
block|,
literal|"cpd rd,@rs,rr,cc"
block|,
literal|0
block|,
literal|"---V--"
block|,
literal|11
block|,
literal|8
block|,
literal|"1011 1010 ssN0 0001 0000 rrrr ddN0 0000"
block|,
literal|"ldirb @rd,@rs,rr"
block|,
literal|0
block|,
literal|"---V--"
block|,
literal|11
block|,
literal|8
block|,
literal|"1011 1010 ssN0 1001 0000 rrrr ddN0 1000"
block|,
literal|"lddb @rd,@rs,rr"
block|,
literal|0
block|,
literal|"---V--"
block|,
literal|11
block|,
literal|8
block|,
literal|"1011 1010 ssN0 0001 0000 rrrr ddN0 1000"
block|,
literal|"ldib @rd,@rs,rr"
block|,
literal|0
block|,
literal|"CZSV--"
block|,
literal|11
block|,
literal|8
block|,
literal|"1011 1010 ssN0 1000 0000 rrrr dddd cccc"
block|,
literal|"cpdb rbd,@rs,rr,cc"
block|,
literal|0
block|,
literal|"CZSV--"
block|,
literal|11
block|,
literal|8
block|,
literal|"1011 1010 ssN0 1100 0000 rrrr dddd cccc"
block|,
literal|"cpdrb rbd,@rs,rr,cc"
block|,
literal|0
block|,
literal|"CZSV--"
block|,
literal|11
block|,
literal|8
block|,
literal|"1011 1010 ssN0 0000 0000 rrrr dddd cccc"
block|,
literal|"cpib rbd,@rs,rr,cc"
block|,
literal|0
block|,
literal|"CZSV--"
block|,
literal|11
block|,
literal|8
block|,
literal|"1011 1010 ssN0 0100 0000 rrrr dddd cccc"
block|,
literal|"cpirb rbd,@rs,rr,cc"
block|,
literal|0
block|,
literal|"CZSV--"
block|,
literal|11
block|,
literal|16
block|,
literal|"1011 1011 ssN0 1010 0000 rrrr ddN0 cccc"
block|,
literal|"cpsd @rd,@rs,rr,cc"
block|,
literal|0
block|,
literal|"CZSV--"
block|,
literal|11
block|,
literal|8
block|,
literal|"1011 1010 ssN0 1010 0000 rrrr ddN0 cccc"
block|,
literal|"cpsdb @rd,@rs,rr,cc"
block|,
literal|0
block|,
literal|"CZSV--"
block|,
literal|11
block|,
literal|16
block|,
literal|"1011 1011 ssN0 1110 0000 rrrr ddN0 cccc"
block|,
literal|"cpsdr @rd,@rs,rr,cc"
block|,
literal|0
block|,
literal|"CZSV--"
block|,
literal|11
block|,
literal|8
block|,
literal|"1011 1010 ssN0 1110 0000 rrrr ddN0 cccc"
block|,
literal|"cpsdrb @rd,@rs,rr,cc"
block|,
literal|0
block|,
literal|"CZSV--"
block|,
literal|11
block|,
literal|16
block|,
literal|"1011 1011 ssN0 0010 0000 rrrr ddN0 cccc"
block|,
literal|"cpsi @rd,@rs,rr,cc"
block|,
literal|0
block|,
literal|"CZSV--"
block|,
literal|11
block|,
literal|8
block|,
literal|"1011 1010 ssN0 0010 0000 rrrr ddN0 cccc"
block|,
literal|"cpsib @rd,@rs,rr,cc"
block|,
literal|0
block|,
literal|"CZSV--"
block|,
literal|11
block|,
literal|16
block|,
literal|"1011 1011 ssN0 0110 0000 rrrr ddN0 cccc"
block|,
literal|"cpsir @rd,@rs,rr,cc"
block|,
literal|0
block|,
literal|"CZSV--"
block|,
literal|11
block|,
literal|8
block|,
literal|"1011 1010 ssN0 0110 0000 rrrr ddN0 cccc"
block|,
literal|"cpsirb @rd,@rs,rr,cc"
block|,
literal|0
block|,
literal|"------"
block|,
literal|2
block|,
literal|8
block|,
literal|"0011 0110 0000 0000"
block|,
literal|"bpt"
block|,
literal|0
block|,
literal|"CZSV--"
block|,
literal|5
block|,
literal|16
block|,
literal|"1011 0101 ssss dddd"
block|,
literal|"adc rd,rs"
block|,
literal|0
block|,
literal|"CZSVDH"
block|,
literal|5
block|,
literal|8
block|,
literal|"1011 0100 ssss dddd"
block|,
literal|"adcb rbd,rbs"
block|,
literal|0
block|,
literal|"CZSV--"
block|,
literal|7
block|,
literal|16
block|,
literal|"0000 0001 ssN0 dddd"
block|,
literal|"add rd,@rs"
block|,
literal|0
block|,
literal|"CZSV--"
block|,
literal|9
block|,
literal|16
block|,
literal|"0100 0001 0000 dddd address_src"
block|,
literal|"add rd,address_src"
block|,
literal|0
block|,
literal|"CZSV--"
block|,
literal|10
block|,
literal|16
block|,
literal|"0100 0001 ssN0 dddd address_src"
block|,
literal|"add rd,address_src(rs)"
block|,
literal|0
block|,
literal|"CZSV--"
block|,
literal|7
block|,
literal|16
block|,
literal|"0000 0001 0000 dddd imm16"
block|,
literal|"add rd,imm16"
block|,
literal|0
block|,
literal|"CZSV--"
block|,
literal|4
block|,
literal|16
block|,
literal|"1000 0001 ssss dddd"
block|,
literal|"add rd,rs"
block|,
literal|0
block|,
literal|"CZSVDH"
block|,
literal|7
block|,
literal|8
block|,
literal|"0000 0000 ssN0 dddd"
block|,
literal|"addb rbd,@rs"
block|,
literal|0
block|,
literal|"CZSVDH"
block|,
literal|9
block|,
literal|8
block|,
literal|"0100 0000 0000 dddd address_src"
block|,
literal|"addb rbd,address_src"
block|,
literal|0
block|,
literal|"CZSVDH"
block|,
literal|10
block|,
literal|8
block|,
literal|"0100 0000 ssN0 dddd address_src"
block|,
literal|"addb rbd,address_src(rs)"
block|,
literal|0
block|,
literal|"CZSVDH"
block|,
literal|7
block|,
literal|8
block|,
literal|"0000 0000 0000 dddd imm8 imm8"
block|,
literal|"addb rbd,imm8"
block|,
literal|0
block|,
literal|"CZSVDH"
block|,
literal|4
block|,
literal|8
block|,
literal|"1000 0000 ssss dddd"
block|,
literal|"addb rbd,rbs"
block|,
literal|0
block|,
literal|"CZSV--"
block|,
literal|14
block|,
literal|32
block|,
literal|"0001 0110 ssN0 dddd"
block|,
literal|"addl rrd,@rs"
block|,
literal|0
block|,
literal|"CZSV--"
block|,
literal|15
block|,
literal|32
block|,
literal|"0101 0110 0000 dddd address_src"
block|,
literal|"addl rrd,address_src"
block|,
literal|0
block|,
literal|"CZSV--"
block|,
literal|16
block|,
literal|32
block|,
literal|"0101 0110 ssN0 dddd address_src"
block|,
literal|"addl rrd,address_src(rs)"
block|,
literal|0
block|,
literal|"CZSV--"
block|,
literal|14
block|,
literal|32
block|,
literal|"0001 0110 0000 dddd imm32"
block|,
literal|"addl rrd,imm32"
block|,
literal|0
block|,
literal|"CZSV--"
block|,
literal|8
block|,
literal|32
block|,
literal|"1001 0110 ssss dddd"
block|,
literal|"addl rrd,rrs"
block|,
literal|0
block|,
literal|"-ZS---"
block|,
literal|7
block|,
literal|16
block|,
literal|"0000 0111 ssN0 dddd"
block|,
literal|"and rd,@rs"
block|,
literal|0
block|,
literal|"-ZS---"
block|,
literal|9
block|,
literal|16
block|,
literal|"0100 0111 0000 dddd address_src"
block|,
literal|"and rd,address_src"
block|,
literal|0
block|,
literal|"-ZS---"
block|,
literal|10
block|,
literal|16
block|,
literal|"0100 0111 ssN0 dddd address_src"
block|,
literal|"and rd,address_src(rs)"
block|,
literal|0
block|,
literal|"-ZS---"
block|,
literal|7
block|,
literal|16
block|,
literal|"0000 0111 0000 dddd imm16"
block|,
literal|"and rd,imm16"
block|,
literal|0
block|,
literal|"-ZS---"
block|,
literal|4
block|,
literal|16
block|,
literal|"1000 0111 ssss dddd"
block|,
literal|"and rd,rs"
block|,
literal|0
block|,
literal|"-ZSP--"
block|,
literal|7
block|,
literal|8
block|,
literal|"0000 0110 ssN0 dddd"
block|,
literal|"andb rbd,@rs"
block|,
literal|0
block|,
literal|"-ZSP--"
block|,
literal|9
block|,
literal|8
block|,
literal|"0100 0110 0000 dddd address_src"
block|,
literal|"andb rbd,address_src"
block|,
literal|0
block|,
literal|"-ZSP--"
block|,
literal|10
block|,
literal|8
block|,
literal|"0100 0110 ssN0 dddd address_src"
block|,
literal|"andb rbd,address_src(rs)"
block|,
literal|0
block|,
literal|"-ZSP--"
block|,
literal|7
block|,
literal|8
block|,
literal|"0000 0110 0000 dddd imm8 imm8"
block|,
literal|"andb rbd,imm8"
block|,
literal|0
block|,
literal|"-ZSP--"
block|,
literal|4
block|,
literal|8
block|,
literal|"1000 0110 ssss dddd"
block|,
literal|"andb rbd,rbs"
block|,
literal|0
block|,
literal|"-Z----"
block|,
literal|8
block|,
literal|16
block|,
literal|"0010 0111 ddN0 imm4"
block|,
literal|"bit @rd,imm4"
block|,
literal|0
block|,
literal|"-Z----"
block|,
literal|11
block|,
literal|16
block|,
literal|"0110 0111 ddN0 imm4 address_dst"
block|,
literal|"bit address_dst(rd),imm4"
block|,
literal|0
block|,
literal|"-Z----"
block|,
literal|10
block|,
literal|16
block|,
literal|"0110 0111 0000 imm4 address_dst"
block|,
literal|"bit address_dst,imm4"
block|,
literal|0
block|,
literal|"-Z----"
block|,
literal|4
block|,
literal|16
block|,
literal|"1010 0111 dddd imm4"
block|,
literal|"bit rd,imm4"
block|,
literal|0
block|,
literal|"-Z----"
block|,
literal|10
block|,
literal|16
block|,
literal|"0010 0111 0000 ssss 0000 dddd 0000 0000"
block|,
literal|"bit rd,rs"
block|,
literal|0
block|,
literal|"-Z----"
block|,
literal|8
block|,
literal|8
block|,
literal|"0010 0110 ddN0 imm4"
block|,
literal|"bitb @rd,imm4"
block|,
literal|0
block|,
literal|"-Z----"
block|,
literal|11
block|,
literal|8
block|,
literal|"0110 0110 ddN0 imm4 address_dst"
block|,
literal|"bitb address_dst(rd),imm4"
block|,
literal|0
block|,
literal|"-Z----"
block|,
literal|10
block|,
literal|8
block|,
literal|"0110 0110 0000 imm4 address_dst"
block|,
literal|"bitb address_dst,imm4"
block|,
literal|0
block|,
literal|"-Z----"
block|,
literal|4
block|,
literal|8
block|,
literal|"1010 0110 dddd imm4"
block|,
literal|"bitb rbd,imm4"
block|,
literal|0
block|,
literal|"-Z----"
block|,
literal|10
block|,
literal|8
block|,
literal|"0010 0110 0000 ssss 0000 dddd 0000 0000"
block|,
literal|"bitb rbd,rs"
block|,
literal|0
block|,
literal|"------"
block|,
literal|10
block|,
literal|32
block|,
literal|"0001 1111 ddN0 0000"
block|,
literal|"call @rd"
block|,
literal|0
block|,
literal|"------"
block|,
literal|12
block|,
literal|32
block|,
literal|"0101 1111 0000 0000 address_dst"
block|,
literal|"call address_dst"
block|,
literal|0
block|,
literal|"------"
block|,
literal|13
block|,
literal|32
block|,
literal|"0101 1111 ddN0 0000 address_dst"
block|,
literal|"call address_dst(rd)"
block|,
literal|0
block|,
literal|"------"
block|,
literal|10
block|,
literal|16
block|,
literal|"1101 disp12"
block|,
literal|"calr disp12"
block|,
literal|0
block|,
literal|"------"
block|,
literal|8
block|,
literal|16
block|,
literal|"0000 1101 ddN0 1000"
block|,
literal|"clr @rd"
block|,
literal|0
block|,
literal|"------"
block|,
literal|11
block|,
literal|16
block|,
literal|"0100 1101 0000 1000 address_dst"
block|,
literal|"clr address_dst"
block|,
literal|0
block|,
literal|"------"
block|,
literal|12
block|,
literal|16
block|,
literal|"0100 1101 ddN0 1000 address_dst"
block|,
literal|"clr address_dst(rd)"
block|,
literal|0
block|,
literal|"------"
block|,
literal|7
block|,
literal|16
block|,
literal|"1000 1101 dddd 1000"
block|,
literal|"clr rd"
block|,
literal|0
block|,
literal|"------"
block|,
literal|8
block|,
literal|8
block|,
literal|"0000 1100 ddN0 1000"
block|,
literal|"clrb @rd"
block|,
literal|0
block|,
literal|"------"
block|,
literal|11
block|,
literal|8
block|,
literal|"0100 1100 0000 1000 address_dst"
block|,
literal|"clrb address_dst"
block|,
literal|0
block|,
literal|"------"
block|,
literal|12
block|,
literal|8
block|,
literal|"0100 1100 ddN0 1000 address_dst"
block|,
literal|"clrb address_dst(rd)"
block|,
literal|0
block|,
literal|"------"
block|,
literal|7
block|,
literal|8
block|,
literal|"1000 1100 dddd 1000"
block|,
literal|"clrb rbd"
block|,
literal|0
block|,
literal|"-ZS---"
block|,
literal|12
block|,
literal|16
block|,
literal|"0000 1101 ddN0 0000"
block|,
literal|"com @rd"
block|,
literal|0
block|,
literal|"-ZS---"
block|,
literal|15
block|,
literal|16
block|,
literal|"0100 1101 0000 0000 address_dst"
block|,
literal|"com address_dst"
block|,
literal|0
block|,
literal|"-ZS---"
block|,
literal|16
block|,
literal|16
block|,
literal|"0100 1101 ddN0 0000 address_dst"
block|,
literal|"com address_dst(rd)"
block|,
literal|0
block|,
literal|"-ZS---"
block|,
literal|7
block|,
literal|16
block|,
literal|"1000 1101 dddd 0000"
block|,
literal|"com rd"
block|,
literal|0
block|,
literal|"-ZSP--"
block|,
literal|12
block|,
literal|8
block|,
literal|"0000 1100 ddN0 0000"
block|,
literal|"comb @rd"
block|,
literal|0
block|,
literal|"-ZSP--"
block|,
literal|15
block|,
literal|8
block|,
literal|"0100 1100 0000 0000 address_dst"
block|,
literal|"comb address_dst"
block|,
literal|0
block|,
literal|"-ZSP--"
block|,
literal|16
block|,
literal|8
block|,
literal|"0100 1100 ddN0 0000 address_dst"
block|,
literal|"comb address_dst(rd)"
block|,
literal|0
block|,
literal|"-ZSP--"
block|,
literal|7
block|,
literal|8
block|,
literal|"1000 1100 dddd 0000"
block|,
literal|"comb rbd"
block|,
literal|0
block|,
literal|"CZSP--"
block|,
literal|7
block|,
literal|16
block|,
literal|"1000 1101 flags 0101"
block|,
literal|"comflg flags"
block|,
literal|0
block|,
literal|"CZSV--"
block|,
literal|11
block|,
literal|16
block|,
literal|"0000 1101 ddN0 0001 imm16"
block|,
literal|"cp @rd,imm16"
block|,
literal|0
block|,
literal|"CZSV--"
block|,
literal|15
block|,
literal|16
block|,
literal|"0100 1101 ddN0 0001 address_dst imm16"
block|,
literal|"cp address_dst(rd),imm16"
block|,
literal|0
block|,
literal|"CZSV--"
block|,
literal|14
block|,
literal|16
block|,
literal|"0100 1101 0000 0001 address_dst imm16"
block|,
literal|"cp address_dst,imm16"
block|,
literal|0
block|,
literal|"CZSV--"
block|,
literal|7
block|,
literal|16
block|,
literal|"0000 1011 ssN0 dddd"
block|,
literal|"cp rd,@rs"
block|,
literal|0
block|,
literal|"CZSV--"
block|,
literal|9
block|,
literal|16
block|,
literal|"0100 1011 0000 dddd address_src"
block|,
literal|"cp rd,address_src"
block|,
literal|0
block|,
literal|"CZSV--"
block|,
literal|10
block|,
literal|16
block|,
literal|"0100 1011 ssN0 dddd address_src"
block|,
literal|"cp rd,address_src(rs)"
block|,
literal|0
block|,
literal|"CZSV--"
block|,
literal|7
block|,
literal|16
block|,
literal|"0000 1011 0000 dddd imm16"
block|,
literal|"cp rd,imm16"
block|,
literal|0
block|,
literal|"CZSV--"
block|,
literal|4
block|,
literal|16
block|,
literal|"1000 1011 ssss dddd"
block|,
literal|"cp rd,rs"
block|,
literal|0
block|,
literal|"CZSV--"
block|,
literal|11
block|,
literal|8
block|,
literal|"0000 1100 ddN0 0001 imm8 imm8"
block|,
literal|"cpb @rd,imm8"
block|,
literal|0
block|,
literal|"CZSV--"
block|,
literal|15
block|,
literal|8
block|,
literal|"0100 1100 ddN0 0001 address_dst imm8 imm8"
block|,
literal|"cpb address_dst(rd),imm8"
block|,
literal|0
block|,
literal|"CZSV--"
block|,
literal|14
block|,
literal|8
block|,
literal|"0100 1100 0000 0001 address_dst imm8 imm8"
block|,
literal|"cpb address_dst,imm8"
block|,
literal|0
block|,
literal|"CZSV--"
block|,
literal|7
block|,
literal|8
block|,
literal|"0000 1010 ssN0 dddd"
block|,
literal|"cpb rbd,@rs"
block|,
literal|0
block|,
literal|"CZSV--"
block|,
literal|9
block|,
literal|8
block|,
literal|"0100 1010 0000 dddd address_src"
block|,
literal|"cpb rbd,address_src"
block|,
literal|0
block|,
literal|"CZSV--"
block|,
literal|10
block|,
literal|8
block|,
literal|"0100 1010 ssN0 dddd address_src"
block|,
literal|"cpb rbd,address_src(rs)"
block|,
literal|0
block|,
literal|"CZSV--"
block|,
literal|7
block|,
literal|8
block|,
literal|"0000 1010 0000 dddd imm8 imm8"
block|,
literal|"cpb rbd,imm8"
block|,
literal|0
block|,
literal|"CZSV--"
block|,
literal|4
block|,
literal|8
block|,
literal|"1000 1010 ssss dddd"
block|,
literal|"cpb rbd,rbs"
block|,
literal|0
block|,
literal|"CZSV--"
block|,
literal|14
block|,
literal|32
block|,
literal|"0001 0000 ssN0 dddd"
block|,
literal|"cpl rrd,@rs"
block|,
literal|0
block|,
literal|"CZSV--"
block|,
literal|15
block|,
literal|32
block|,
literal|"0101 0000 0000 dddd address_src"
block|,
literal|"cpl rrd,address_src"
block|,
literal|0
block|,
literal|"CZSV--"
block|,
literal|16
block|,
literal|32
block|,
literal|"0101 0000 ssN0 dddd address_src"
block|,
literal|"cpl rrd,address_src(rs)"
block|,
literal|0
block|,
literal|"CZSV--"
block|,
literal|14
block|,
literal|32
block|,
literal|"0001 0000 0000 dddd imm32"
block|,
literal|"cpl rrd,imm32"
block|,
literal|0
block|,
literal|"CZSV--"
block|,
literal|8
block|,
literal|32
block|,
literal|"1001 0000 ssss dddd"
block|,
literal|"cpl rrd,rrs"
block|,
literal|0
block|,
literal|"CZS---"
block|,
literal|5
block|,
literal|8
block|,
literal|"1011 0000 dddd 0000"
block|,
literal|"dab rbd"
block|,
literal|0
block|,
literal|"------"
block|,
literal|11
block|,
literal|16
block|,
literal|"1111 dddd 0disp7"
block|,
literal|"dbjnz rbd,disp7"
block|,
literal|0
block|,
literal|"-ZSV--"
block|,
literal|11
block|,
literal|16
block|,
literal|"0010 1011 ddN0 imm4m1"
block|,
literal|"dec @rd,imm4m1"
block|,
literal|0
block|,
literal|"-ZSV--"
block|,
literal|14
block|,
literal|16
block|,
literal|"0110 1011 ddN0 imm4m1 address_dst"
block|,
literal|"dec address_dst(rd),imm4m1"
block|,
literal|0
block|,
literal|"-ZSV--"
block|,
literal|13
block|,
literal|16
block|,
literal|"0110 1011 0000 imm4m1 address_dst"
block|,
literal|"dec address_dst,imm4m1"
block|,
literal|0
block|,
literal|"-ZSV--"
block|,
literal|4
block|,
literal|16
block|,
literal|"1010 1011 dddd imm4m1"
block|,
literal|"dec rd,imm4m1"
block|,
literal|0
block|,
literal|"-ZSV--"
block|,
literal|11
block|,
literal|8
block|,
literal|"0010 1010 ddN0 imm4m1"
block|,
literal|"decb @rd,imm4m1"
block|,
literal|0
block|,
literal|"-ZSV--"
block|,
literal|14
block|,
literal|8
block|,
literal|"0110 1010 ddN0 imm4m1 address_dst"
block|,
literal|"decb address_dst(rd),imm4m1"
block|,
literal|0
block|,
literal|"-ZSV--"
block|,
literal|13
block|,
literal|8
block|,
literal|"0110 1010 0000 imm4m1 address_dst"
block|,
literal|"decb address_dst,imm4m1"
block|,
literal|0
block|,
literal|"-ZSV--"
block|,
literal|4
block|,
literal|8
block|,
literal|"1010 1010 dddd imm4m1"
block|,
literal|"decb rbd,imm4m1"
block|,
literal|0
block|,
literal|"------"
block|,
literal|7
block|,
literal|16
block|,
literal|"0111 1100 0000 00ii"
block|,
literal|"di i2"
block|,
literal|0
block|,
literal|"CZSV--"
block|,
literal|107
block|,
literal|16
block|,
literal|"0001 1011 ssN0 dddd"
block|,
literal|"div rrd,@rs"
block|,
literal|0
block|,
literal|"CZSV--"
block|,
literal|107
block|,
literal|16
block|,
literal|"0101 1011 0000 dddd address_src"
block|,
literal|"div rrd,address_src"
block|,
literal|0
block|,
literal|"CZSV--"
block|,
literal|107
block|,
literal|16
block|,
literal|"0101 1011 ssN0 dddd address_src"
block|,
literal|"div rrd,address_src(rs)"
block|,
literal|0
block|,
literal|"CZSV--"
block|,
literal|107
block|,
literal|16
block|,
literal|"0001 1011 0000 dddd imm16"
block|,
literal|"div rrd,imm16"
block|,
literal|0
block|,
literal|"CZSV--"
block|,
literal|107
block|,
literal|16
block|,
literal|"1001 1011 ssss dddd"
block|,
literal|"div rrd,rs"
block|,
literal|0
block|,
literal|"CZSV--"
block|,
literal|744
block|,
literal|32
block|,
literal|"0001 1010 ssN0 dddd"
block|,
literal|"divl rqd,@rs"
block|,
literal|0
block|,
literal|"CZSV--"
block|,
literal|745
block|,
literal|32
block|,
literal|"0101 1010 0000 dddd address_src"
block|,
literal|"divl rqd,address_src"
block|,
literal|0
block|,
literal|"CZSV--"
block|,
literal|746
block|,
literal|32
block|,
literal|"0101 1010 ssN0 dddd address_src"
block|,
literal|"divl rqd,address_src(rs)"
block|,
literal|0
block|,
literal|"CZSV--"
block|,
literal|744
block|,
literal|32
block|,
literal|"0001 1010 0000 dddd imm32"
block|,
literal|"divl rqd,imm32"
block|,
literal|0
block|,
literal|"CZSV--"
block|,
literal|744
block|,
literal|32
block|,
literal|"1001 1010 ssss dddd"
block|,
literal|"divl rqd,rrs"
block|,
literal|0
block|,
literal|"------"
block|,
literal|11
block|,
literal|16
block|,
literal|"1111 dddd 1disp7"
block|,
literal|"djnz rd,disp7"
block|,
literal|0
block|,
literal|"------"
block|,
literal|7
block|,
literal|16
block|,
literal|"0111 1100 0000 01ii"
block|,
literal|"ei i2"
block|,
literal|0
block|,
literal|"------"
block|,
literal|6
block|,
literal|16
block|,
literal|"1010 1101 ssss dddd"
block|,
literal|"ex rd,rs"
block|,
literal|0
block|,
literal|"------"
block|,
literal|12
block|,
literal|16
block|,
literal|"0010 1101 ssN0 dddd"
block|,
literal|"ex rd,@rs"
block|,
literal|0
block|,
literal|"------"
block|,
literal|15
block|,
literal|16
block|,
literal|"0110 1101 0000 dddd address_src"
block|,
literal|"ex rd,address_src"
block|,
literal|0
block|,
literal|"------"
block|,
literal|16
block|,
literal|16
block|,
literal|"0110 1101 ssN0 dddd address_src"
block|,
literal|"ex rd,address_src(rs)"
block|,
literal|0
block|,
literal|"------"
block|,
literal|12
block|,
literal|8
block|,
literal|"0010 1100 ssN0 dddd"
block|,
literal|"exb rbd,@rs"
block|,
literal|0
block|,
literal|"------"
block|,
literal|15
block|,
literal|8
block|,
literal|"0110 1100 0000 dddd address_src"
block|,
literal|"exb rbd,address_src"
block|,
literal|0
block|,
literal|"------"
block|,
literal|16
block|,
literal|8
block|,
literal|"0110 1100 ssN0 dddd address_src"
block|,
literal|"exb rbd,address_src(rs)"
block|,
literal|0
block|,
literal|"------"
block|,
literal|6
block|,
literal|8
block|,
literal|"1010 1100 ssss dddd"
block|,
literal|"exb rbd,rbs"
block|,
literal|0
block|,
literal|"------"
block|,
literal|11
block|,
literal|16
block|,
literal|"1011 0001 dddd 1010"
block|,
literal|"exts rrd"
block|,
literal|0
block|,
literal|"------"
block|,
literal|11
block|,
literal|8
block|,
literal|"1011 0001 dddd 0000"
block|,
literal|"extsb rd"
block|,
literal|0
block|,
literal|"------"
block|,
literal|11
block|,
literal|32
block|,
literal|"1011 0001 dddd 0111"
block|,
literal|"extsl rqd"
block|,
literal|0
block|,
literal|"------"
block|,
literal|8
block|,
literal|16
block|,
literal|"0111 1010 0000 0000"
block|,
literal|"halt"
block|,
literal|0
block|,
literal|"------"
block|,
literal|10
block|,
literal|16
block|,
literal|"0011 1101 ssN0 dddd"
block|,
literal|"in rd,@rs"
block|,
literal|0
block|,
literal|"------"
block|,
literal|12
block|,
literal|16
block|,
literal|"0011 1101 dddd 0100 imm16"
block|,
literal|"in rd,imm16"
block|,
literal|0
block|,
literal|"------"
block|,
literal|12
block|,
literal|8
block|,
literal|"0011 1100 ssN0 dddd"
block|,
literal|"inb rbd,@rs"
block|,
literal|0
block|,
literal|"------"
block|,
literal|10
block|,
literal|8
block|,
literal|"0011 1010 dddd 0100 imm16"
block|,
literal|"inb rbd,imm16"
block|,
literal|0
block|,
literal|"-ZSV--"
block|,
literal|11
block|,
literal|16
block|,
literal|"0010 1001 ddN0 imm4m1"
block|,
literal|"inc @rd,imm4m1"
block|,
literal|0
block|,
literal|"-ZSV--"
block|,
literal|14
block|,
literal|16
block|,
literal|"0110 1001 ddN0 imm4m1 address_dst"
block|,
literal|"inc address_dst(rd),imm4m1"
block|,
literal|0
block|,
literal|"-ZSV--"
block|,
literal|13
block|,
literal|16
block|,
literal|"0110 1001 0000 imm4m1 address_dst"
block|,
literal|"inc address_dst,imm4m1"
block|,
literal|0
block|,
literal|"-ZSV--"
block|,
literal|4
block|,
literal|16
block|,
literal|"1010 1001 dddd imm4m1"
block|,
literal|"inc rd,imm4m1"
block|,
literal|0
block|,
literal|"-ZSV--"
block|,
literal|11
block|,
literal|8
block|,
literal|"0010 1000 ddN0 imm4m1"
block|,
literal|"incb @rd,imm4m1"
block|,
literal|0
block|,
literal|"-ZSV--"
block|,
literal|14
block|,
literal|8
block|,
literal|"0110 1000 ddN0 imm4m1 address_dst"
block|,
literal|"incb address_dst(rd),imm4m1"
block|,
literal|0
block|,
literal|"-ZSV--"
block|,
literal|13
block|,
literal|8
block|,
literal|"0110 1000 0000 imm4m1 address_dst"
block|,
literal|"incb address_dst,imm4m1"
block|,
literal|0
block|,
literal|"-ZSV--"
block|,
literal|4
block|,
literal|8
block|,
literal|"1010 1000 dddd imm4m1"
block|,
literal|"incb rbd,imm4m1"
block|,
literal|0
block|,
literal|"---V--"
block|,
literal|21
block|,
literal|16
block|,
literal|"0011 1011 ssN0 1000 0000 aaaa ddN0 1000"
block|,
literal|"ind @rd,@rs,ra"
block|,
literal|0
block|,
literal|"---V--"
block|,
literal|21
block|,
literal|8
block|,
literal|"0011 1010 ssN0 1000 0000 aaaa ddN0 1000"
block|,
literal|"indb @rd,@rs,rba"
block|,
literal|0
block|,
literal|"---V--"
block|,
literal|21
block|,
literal|8
block|,
literal|"0011 1010 ssN0 0000 0000 aaaa ddN0 1000"
block|,
literal|"inib @rd,@rs,ra"
block|,
literal|0
block|,
literal|"---V--"
block|,
literal|21
block|,
literal|16
block|,
literal|"0011 1010 ssN0 0000 0000 aaaa ddN0 0000"
block|,
literal|"inibr @rd,@rs,ra"
block|,
literal|0
block|,
literal|"CZSVDH"
block|,
literal|13
block|,
literal|16
block|,
literal|"0111 1011 0000 0000"
block|,
literal|"iret"
block|,
literal|0
block|,
literal|"------"
block|,
literal|10
block|,
literal|16
block|,
literal|"0001 1110 ddN0 cccc"
block|,
literal|"jp cc,@rd"
block|,
literal|0
block|,
literal|"------"
block|,
literal|7
block|,
literal|16
block|,
literal|"0101 1110 0000 cccc address_dst"
block|,
literal|"jp cc,address_dst"
block|,
literal|0
block|,
literal|"------"
block|,
literal|8
block|,
literal|16
block|,
literal|"0101 1110 ddN0 cccc address_dst"
block|,
literal|"jp cc,address_dst(rd)"
block|,
literal|0
block|,
literal|"------"
block|,
literal|6
block|,
literal|16
block|,
literal|"1110 cccc disp8"
block|,
literal|"jr cc,disp8"
block|,
literal|0
block|,
literal|"------"
block|,
literal|7
block|,
literal|16
block|,
literal|"0000 1101 ddN0 0101 imm16"
block|,
literal|"ld @rd,imm16"
block|,
literal|0
block|,
literal|"------"
block|,
literal|8
block|,
literal|16
block|,
literal|"0010 1111 ddN0 ssss"
block|,
literal|"ld @rd,rs"
block|,
literal|0
block|,
literal|"------"
block|,
literal|15
block|,
literal|16
block|,
literal|"0100 1101 ddN0 0101 address_dst imm16"
block|,
literal|"ld address_dst(rd),imm16"
block|,
literal|0
block|,
literal|"------"
block|,
literal|12
block|,
literal|16
block|,
literal|"0110 1111 ddN0 ssss address_dst"
block|,
literal|"ld address_dst(rd),rs"
block|,
literal|0
block|,
literal|"------"
block|,
literal|14
block|,
literal|16
block|,
literal|"0100 1101 0000 0101 address_dst imm16"
block|,
literal|"ld address_dst,imm16"
block|,
literal|0
block|,
literal|"------"
block|,
literal|11
block|,
literal|16
block|,
literal|"0110 1111 0000 ssss address_dst"
block|,
literal|"ld address_dst,rs"
block|,
literal|0
block|,
literal|"------"
block|,
literal|14
block|,
literal|16
block|,
literal|"0011 0011 ddN0 ssss imm16"
block|,
literal|"ld rd(imm16),rs"
block|,
literal|0
block|,
literal|"------"
block|,
literal|14
block|,
literal|16
block|,
literal|"0111 0011 ddN0 ssss 0000 xxxx 0000 0000"
block|,
literal|"ld rd(rx),rs"
block|,
literal|0
block|,
literal|"------"
block|,
literal|7
block|,
literal|16
block|,
literal|"0010 0001 ssN0 dddd"
block|,
literal|"ld rd,@rs"
block|,
literal|0
block|,
literal|"------"
block|,
literal|9
block|,
literal|16
block|,
literal|"0110 0001 0000 dddd address_src"
block|,
literal|"ld rd,address_src"
block|,
literal|0
block|,
literal|"------"
block|,
literal|10
block|,
literal|16
block|,
literal|"0110 0001 ssN0 dddd address_src"
block|,
literal|"ld rd,address_src(rs)"
block|,
literal|0
block|,
literal|"------"
block|,
literal|7
block|,
literal|16
block|,
literal|"0010 0001 0000 dddd imm16"
block|,
literal|"ld rd,imm16"
block|,
literal|0
block|,
literal|"------"
block|,
literal|3
block|,
literal|16
block|,
literal|"1010 0001 ssss dddd"
block|,
literal|"ld rd,rs"
block|,
literal|0
block|,
literal|"------"
block|,
literal|14
block|,
literal|16
block|,
literal|"0011 0001 ssN0 dddd imm16"
block|,
literal|"ld rd,rs(imm16)"
block|,
literal|0
block|,
literal|"------"
block|,
literal|14
block|,
literal|16
block|,
literal|"0111 0001 ssN0 dddd 0000 xxxx 0000 0000"
block|,
literal|"ld rd,rs(rx)"
block|,
literal|0
block|,
literal|"------"
block|,
literal|7
block|,
literal|8
block|,
literal|"0000 1100 ddN0 0101 imm8 imm8"
block|,
literal|"ldb @rd,imm8"
block|,
literal|0
block|,
literal|"------"
block|,
literal|8
block|,
literal|8
block|,
literal|"0010 1110 ddN0 ssss"
block|,
literal|"ldb @rd,rbs"
block|,
literal|0
block|,
literal|"------"
block|,
literal|15
block|,
literal|8
block|,
literal|"0100 1100 ddN0 0101 address_dst imm8 imm8"
block|,
literal|"ldb address_dst(rd),imm8"
block|,
literal|0
block|,
literal|"------"
block|,
literal|12
block|,
literal|8
block|,
literal|"0110 1110 ddN0 ssss address_dst"
block|,
literal|"ldb address_dst(rd),rbs"
block|,
literal|0
block|,
literal|"------"
block|,
literal|14
block|,
literal|8
block|,
literal|"0100 1100 0000 0101 address_dst imm8 imm8"
block|,
literal|"ldb address_dst,imm8"
block|,
literal|0
block|,
literal|"------"
block|,
literal|11
block|,
literal|8
block|,
literal|"0110 1110 0000 ssss address_dst"
block|,
literal|"ldb address_dst,rbs"
block|,
literal|0
block|,
literal|"------"
block|,
literal|14
block|,
literal|8
block|,
literal|"0011 0010 ddN0 ssss imm16"
block|,
literal|"ldb rd(imm16),rbs"
block|,
literal|0
block|,
literal|"------"
block|,
literal|14
block|,
literal|8
block|,
literal|"0111 0010 ddN0 ssss 0000 xxxx 0000 0000"
block|,
literal|"ldb rd(rx),rbs"
block|,
literal|0
block|,
literal|"------"
block|,
literal|7
block|,
literal|8
block|,
literal|"0010 0000 ssN0 dddd"
block|,
literal|"ldb rbd,@rs"
block|,
literal|0
block|,
literal|"------"
block|,
literal|9
block|,
literal|8
block|,
literal|"0110 0000 0000 dddd address_src"
block|,
literal|"ldb rbd,address_src"
block|,
literal|0
block|,
literal|"------"
block|,
literal|10
block|,
literal|8
block|,
literal|"0110 0000 ssN0 dddd address_src"
block|,
literal|"ldb rbd,address_src(rs)"
block|,
literal|0
block|,
literal|"------"
block|,
literal|5
block|,
literal|8
block|,
literal|"1100 dddd imm8"
block|,
literal|"ldb rbd,imm8"
block|,
literal|0
block|,
literal|"------"
block|,
literal|3
block|,
literal|8
block|,
literal|"1010 0000 ssss dddd"
block|,
literal|"ldb rbd,rbs"
block|,
literal|0
block|,
literal|"------"
block|,
literal|14
block|,
literal|8
block|,
literal|"0011 0000 ssN0 dddd imm16"
block|,
literal|"ldb rbd,rs(imm16)"
block|,
literal|0
block|,
literal|"------"
block|,
literal|14
block|,
literal|8
block|,
literal|"0111 0000 ssN0 dddd 0000 xxxx 0000 0000"
block|,
literal|"ldb rbd,rs(rx)"
block|,
literal|0
block|,
literal|"------"
block|,
literal|11
block|,
literal|32
block|,
literal|"0001 1101 ddN0 ssss"
block|,
literal|"ldl @rd,rrs"
block|,
literal|0
block|,
literal|"------"
block|,
literal|14
block|,
literal|32
block|,
literal|"0101 1101 ddN0 ssss address_dst"
block|,
literal|"ldl address_dst(rd),rrs"
block|,
literal|0
block|,
literal|"------"
block|,
literal|15
block|,
literal|32
block|,
literal|"0101 1101 0000 ssss address_dst"
block|,
literal|"ldl address_dst,rrs"
block|,
literal|0
block|,
literal|"------"
block|,
literal|17
block|,
literal|32
block|,
literal|"0011 0111 ddN0 ssss imm16"
block|,
literal|"ldl rd(imm16),rrs"
block|,
literal|0
block|,
literal|"------"
block|,
literal|17
block|,
literal|32
block|,
literal|"0111 0111 ddN0 ssss 0000 xxxx 0000 0000"
block|,
literal|"ldl rd(rx),rrs"
block|,
literal|0
block|,
literal|"------"
block|,
literal|11
block|,
literal|32
block|,
literal|"0001 0100 ssN0 dddd"
block|,
literal|"ldl rrd,@rs"
block|,
literal|0
block|,
literal|"------"
block|,
literal|12
block|,
literal|32
block|,
literal|"0101 0100 0000 dddd address_src"
block|,
literal|"ldl rrd,address_src"
block|,
literal|0
block|,
literal|"------"
block|,
literal|13
block|,
literal|32
block|,
literal|"0101 0100 ssN0 dddd address_src"
block|,
literal|"ldl rrd,address_src(rs)"
block|,
literal|0
block|,
literal|"------"
block|,
literal|11
block|,
literal|32
block|,
literal|"0001 0100 0000 dddd imm32"
block|,
literal|"ldl rrd,imm32"
block|,
literal|0
block|,
literal|"------"
block|,
literal|5
block|,
literal|32
block|,
literal|"1001 0100 ssss dddd"
block|,
literal|"ldl rrd,rrs"
block|,
literal|0
block|,
literal|"------"
block|,
literal|17
block|,
literal|32
block|,
literal|"0011 0101 ssN0 dddd imm16"
block|,
literal|"ldl rrd,rs(imm16)"
block|,
literal|0
block|,
literal|"------"
block|,
literal|17
block|,
literal|32
block|,
literal|"0111 0101 ssN0 dddd 0000 xxxx 0000 0000"
block|,
literal|"ldl rrd,rs(rx)"
block|,
literal|0
block|,
literal|"------"
block|,
literal|12
block|,
literal|16
block|,
literal|"0111 0110 0000 dddd address_src"
block|,
literal|"lda prd,address_src"
block|,
literal|0
block|,
literal|"------"
block|,
literal|13
block|,
literal|16
block|,
literal|"0111 0110 ssN0 dddd address_src"
block|,
literal|"lda prd,address_src(rs)"
block|,
literal|0
block|,
literal|"------"
block|,
literal|15
block|,
literal|16
block|,
literal|"0011 0100 ssN0 dddd imm16"
block|,
literal|"lda prd,rs(imm16)"
block|,
literal|0
block|,
literal|"------"
block|,
literal|15
block|,
literal|16
block|,
literal|"0111 0100 ssN0 dddd 0000 xxxx 0000 0000"
block|,
literal|"lda prd,rs(rx)"
block|,
literal|0
block|,
literal|"------"
block|,
literal|15
block|,
literal|16
block|,
literal|"0011 0100 0000 dddd disp16"
block|,
literal|"ldar prd,disp16"
block|,
literal|0
block|,
literal|"------"
block|,
literal|7
block|,
literal|32
block|,
literal|"0111 1101 ssss 1ccc"
block|,
literal|"ldctl ctrl,rs"
block|,
literal|0
block|,
literal|"------"
block|,
literal|7
block|,
literal|32
block|,
literal|"0111 1101 dddd 0ccc"
block|,
literal|"ldctl rd,ctrl"
block|,
literal|0
block|,
literal|"------"
block|,
literal|5
block|,
literal|16
block|,
literal|"1011 1101 dddd imm4"
block|,
literal|"ldk rd,imm4"
block|,
literal|0
block|,
literal|"------"
block|,
literal|11
block|,
literal|16
block|,
literal|"0001 1100 ddN0 1001 0000 ssss 0000 nminus1"
block|,
literal|"ldm @rd,rs,n"
block|,
literal|0
block|,
literal|"------"
block|,
literal|15
block|,
literal|16
block|,
literal|"0101 1100 ddN0 1001 0000 ssss 0000 nminus1 address_dst"
block|,
literal|"ldm address_dst(rd),rs,n"
block|,
literal|0
block|,
literal|"------"
block|,
literal|14
block|,
literal|16
block|,
literal|"0101 1100 0000 1001 0000 ssss 0000 nminus1 address_dst"
block|,
literal|"ldm address_dst,rs,n"
block|,
literal|0
block|,
literal|"------"
block|,
literal|11
block|,
literal|16
block|,
literal|"0001 1100 ssN0 0001 0000 dddd 0000 nminus1"
block|,
literal|"ldm rd,@rs,n"
block|,
literal|0
block|,
literal|"------"
block|,
literal|15
block|,
literal|16
block|,
literal|"0101 1100 ssN0 0001 0000 dddd 0000 nminus1 address_src"
block|,
literal|"ldm rd,address_src(rs),n"
block|,
literal|0
block|,
literal|"------"
block|,
literal|14
block|,
literal|16
block|,
literal|"0101 1100 0000 0001 0000 dddd 0000 nminus1 address_src"
block|,
literal|"ldm rd,address_src,n"
block|,
literal|0
block|,
literal|"CZSVDH"
block|,
literal|12
block|,
literal|16
block|,
literal|"0011 1001 ssN0 0000"
block|,
literal|"ldps @rs"
block|,
literal|0
block|,
literal|"CZSVDH"
block|,
literal|16
block|,
literal|16
block|,
literal|"0111 1001 0000 0000 address_src"
block|,
literal|"ldps address_src"
block|,
literal|0
block|,
literal|"CZSVDH"
block|,
literal|17
block|,
literal|16
block|,
literal|"0111 1001 ssN0 0000 address_src"
block|,
literal|"ldps address_src(rs)"
block|,
literal|0
block|,
literal|"------"
block|,
literal|14
block|,
literal|16
block|,
literal|"0011 0011 0000 ssss disp16"
block|,
literal|"ldr disp16,rs"
block|,
literal|0
block|,
literal|"------"
block|,
literal|14
block|,
literal|16
block|,
literal|"0011 0001 0000 dddd disp16"
block|,
literal|"ldr rd,disp16"
block|,
literal|0
block|,
literal|"------"
block|,
literal|14
block|,
literal|8
block|,
literal|"0011 0010 0000 ssss disp16"
block|,
literal|"ldrb disp16,rbs"
block|,
literal|0
block|,
literal|"------"
block|,
literal|14
block|,
literal|8
block|,
literal|"0011 0000 0000 dddd disp16"
block|,
literal|"ldrb rbd,disp16"
block|,
literal|0
block|,
literal|"------"
block|,
literal|17
block|,
literal|32
block|,
literal|"0011 0111 0000 ssss disp16"
block|,
literal|"ldrl disp16,rrs"
block|,
literal|0
block|,
literal|"------"
block|,
literal|17
block|,
literal|32
block|,
literal|"0011 0101 0000 dddd disp16"
block|,
literal|"ldrl rrd,disp16"
block|,
literal|0
block|,
literal|"CZS---"
block|,
literal|7
block|,
literal|16
block|,
literal|"0111 1011 0000 1010"
block|,
literal|"mbit"
block|,
literal|0
block|,
literal|"-ZS---"
block|,
literal|12
block|,
literal|16
block|,
literal|"0111 1011 dddd 1101"
block|,
literal|"mreq rd"
block|,
literal|0
block|,
literal|"------"
block|,
literal|5
block|,
literal|16
block|,
literal|"0111 1011 0000 1001"
block|,
literal|"mres"
block|,
literal|0
block|,
literal|"------"
block|,
literal|5
block|,
literal|16
block|,
literal|"0111 1011 0000 1000"
block|,
literal|"mset"
block|,
literal|0
block|,
literal|"CZSV--"
block|,
literal|70
block|,
literal|16
block|,
literal|"0001 1001 ssN0 dddd"
block|,
literal|"mult rrd,@rs"
block|,
literal|0
block|,
literal|"CZSV--"
block|,
literal|70
block|,
literal|16
block|,
literal|"0101 1001 0000 dddd address_src"
block|,
literal|"mult rrd,address_src"
block|,
literal|0
block|,
literal|"CZSV--"
block|,
literal|70
block|,
literal|16
block|,
literal|"0101 1001 ssN0 dddd address_src"
block|,
literal|"mult rrd,address_src(rs)"
block|,
literal|0
block|,
literal|"CZSV--"
block|,
literal|70
block|,
literal|16
block|,
literal|"0001 1001 0000 dddd imm16"
block|,
literal|"mult rrd,imm16"
block|,
literal|0
block|,
literal|"CZSV--"
block|,
literal|70
block|,
literal|16
block|,
literal|"1001 1001 ssss dddd"
block|,
literal|"mult rrd,rs"
block|,
literal|0
block|,
literal|"CZSV--"
block|,
literal|282
block|,
literal|32
block|,
literal|"0001 1000 ssN0 dddd"
block|,
literal|"multl rqd,@rs"
block|,
literal|0
block|,
literal|"CZSV--"
block|,
literal|282
block|,
literal|32
block|,
literal|"0101 1000 0000 dddd address_src"
block|,
literal|"multl rqd,address_src"
block|,
literal|0
block|,
literal|"CZSV--"
block|,
literal|282
block|,
literal|32
block|,
literal|"0101 1000 ssN0 dddd address_src"
block|,
literal|"multl rqd,address_src(rs)"
block|,
literal|0
block|,
literal|"CZSV--"
block|,
literal|282
block|,
literal|32
block|,
literal|"0001 1000 0000 dddd imm32"
block|,
literal|"multl rqd,imm32"
block|,
literal|0
block|,
literal|"CZSV--"
block|,
literal|282
block|,
literal|32
block|,
literal|"1001 1000 ssss dddd"
block|,
literal|"multl rqd,rrs"
block|,
literal|0
block|,
literal|"CZSV--"
block|,
literal|12
block|,
literal|16
block|,
literal|"0000 1101 ddN0 0010"
block|,
literal|"neg @rd"
block|,
literal|0
block|,
literal|"CZSV--"
block|,
literal|15
block|,
literal|16
block|,
literal|"0100 1101 0000 0010 address_dst"
block|,
literal|"neg address_dst"
block|,
literal|0
block|,
literal|"CZSV--"
block|,
literal|16
block|,
literal|16
block|,
literal|"0100 1101 ddN0 0010 address_dst"
block|,
literal|"neg address_dst(rd)"
block|,
literal|0
block|,
literal|"CZSV--"
block|,
literal|7
block|,
literal|16
block|,
literal|"1000 1101 dddd 0010"
block|,
literal|"neg rd"
block|,
literal|0
block|,
literal|"CZSV--"
block|,
literal|12
block|,
literal|8
block|,
literal|"0000 1100 ddN0 0010"
block|,
literal|"negb @rd"
block|,
literal|0
block|,
literal|"CZSV--"
block|,
literal|15
block|,
literal|8
block|,
literal|"0100 1100 0000 0010 address_dst"
block|,
literal|"negb address_dst"
block|,
literal|0
block|,
literal|"CZSV--"
block|,
literal|16
block|,
literal|8
block|,
literal|"0100 1100 ddN0 0010 address_dst"
block|,
literal|"negb address_dst(rd)"
block|,
literal|0
block|,
literal|"CZSV--"
block|,
literal|7
block|,
literal|8
block|,
literal|"1000 1100 dddd 0010"
block|,
literal|"negb rbd"
block|,
literal|0
block|,
literal|"------"
block|,
literal|7
block|,
literal|16
block|,
literal|"1000 1101 0000 0111"
block|,
literal|"nop"
block|,
literal|0
block|,
literal|"CZS---"
block|,
literal|7
block|,
literal|16
block|,
literal|"0000 0101 ssN0 dddd"
block|,
literal|"or rd,@rs"
block|,
literal|0
block|,
literal|"CZS---"
block|,
literal|9
block|,
literal|16
block|,
literal|"0100 0101 0000 dddd address_src"
block|,
literal|"or rd,address_src"
block|,
literal|0
block|,
literal|"CZS---"
block|,
literal|10
block|,
literal|16
block|,
literal|"0100 0101 ssN0 dddd address_src"
block|,
literal|"or rd,address_src(rs)"
block|,
literal|0
block|,
literal|"CZS---"
block|,
literal|7
block|,
literal|16
block|,
literal|"0000 0101 0000 dddd imm16"
block|,
literal|"or rd,imm16"
block|,
literal|0
block|,
literal|"CZS---"
block|,
literal|4
block|,
literal|16
block|,
literal|"1000 0101 ssss dddd"
block|,
literal|"or rd,rs"
block|,
literal|0
block|,
literal|"CZSP--"
block|,
literal|7
block|,
literal|8
block|,
literal|"0000 0100 ssN0 dddd"
block|,
literal|"orb rbd,@rs"
block|,
literal|0
block|,
literal|"CZSP--"
block|,
literal|9
block|,
literal|8
block|,
literal|"0100 0100 0000 dddd address_src"
block|,
literal|"orb rbd,address_src"
block|,
literal|0
block|,
literal|"CZSP--"
block|,
literal|10
block|,
literal|8
block|,
literal|"0100 0100 ssN0 dddd address_src"
block|,
literal|"orb rbd,address_src(rs)"
block|,
literal|0
block|,
literal|"CZSP--"
block|,
literal|7
block|,
literal|8
block|,
literal|"0000 0100 0000 dddd imm8 imm8"
block|,
literal|"orb rbd,imm8"
block|,
literal|0
block|,
literal|"CZSP--"
block|,
literal|4
block|,
literal|8
block|,
literal|"1000 0100 ssss dddd"
block|,
literal|"orb rbd,rbs"
block|,
literal|0
block|,
literal|"---V--"
block|,
literal|0
block|,
literal|16
block|,
literal|"0011 1111 ddN0 ssss"
block|,
literal|"out @rd,rs"
block|,
literal|0
block|,
literal|"---V--"
block|,
literal|0
block|,
literal|16
block|,
literal|"0011 1011 ssss 0110 imm16"
block|,
literal|"out imm16,rs"
block|,
literal|0
block|,
literal|"---V--"
block|,
literal|0
block|,
literal|8
block|,
literal|"0011 1110 ddN0 ssss"
block|,
literal|"outb @rd,rbs"
block|,
literal|0
block|,
literal|"---V--"
block|,
literal|0
block|,
literal|8
block|,
literal|"0011 1010 ssss 0110 imm16"
block|,
literal|"outb imm16,rbs"
block|,
literal|0
block|,
literal|"---V--"
block|,
literal|0
block|,
literal|16
block|,
literal|"0011 1011 ssN0 1010 0000 aaaa ddN0 1000"
block|,
literal|"outd @rd,@rs,ra"
block|,
literal|0
block|,
literal|"---V--"
block|,
literal|0
block|,
literal|16
block|,
literal|"0011 1010 ssN0 1010 0000 aaaa ddN0 1000"
block|,
literal|"outdb @rd,@rs,rba"
block|,
literal|0
block|,
literal|"---V--"
block|,
literal|0
block|,
literal|16
block|,
literal|"0011 1011 ssN0 0010 0000 aaaa ddN0 1000"
block|,
literal|"outi @rd,@rs,ra"
block|,
literal|0
block|,
literal|"---V--"
block|,
literal|0
block|,
literal|16
block|,
literal|"0011 1010 ssN0 0010 0000 aaaa ddN0 1000"
block|,
literal|"outib @rd,@rs,ra"
block|,
literal|0
block|,
literal|"---V--"
block|,
literal|0
block|,
literal|16
block|,
literal|"0011 1010 ssN0 0010 0000 aaaa ddN0 0000"
block|,
literal|"outibr @rd,@rs,ra"
block|,
literal|0
block|,
literal|"------"
block|,
literal|12
block|,
literal|16
block|,
literal|"0001 0111 ssN0 ddN0"
block|,
literal|"pop @rd,@rs"
block|,
literal|0
block|,
literal|"------"
block|,
literal|16
block|,
literal|16
block|,
literal|"0101 0111 ssN0 ddN0 address_dst"
block|,
literal|"pop address_dst(rd),@rs"
block|,
literal|0
block|,
literal|"------"
block|,
literal|16
block|,
literal|16
block|,
literal|"0101 0111 ssN0 0000 address_dst"
block|,
literal|"pop address_dst,@rs"
block|,
literal|0
block|,
literal|"------"
block|,
literal|8
block|,
literal|16
block|,
literal|"1001 0111 ssN0 dddd"
block|,
literal|"pop rd,@rs"
block|,
literal|0
block|,
literal|"------"
block|,
literal|19
block|,
literal|32
block|,
literal|"0001 0101 ssN0 ddN0"
block|,
literal|"popl @rd,@rs"
block|,
literal|0
block|,
literal|"------"
block|,
literal|23
block|,
literal|32
block|,
literal|"0101 0101 ssN0 ddN0 address_dst"
block|,
literal|"popl address_dst(rd),@rs"
block|,
literal|0
block|,
literal|"------"
block|,
literal|23
block|,
literal|32
block|,
literal|"0101 0101 ssN0 0000 address_dst"
block|,
literal|"popl address_dst,@rs"
block|,
literal|0
block|,
literal|"------"
block|,
literal|12
block|,
literal|32
block|,
literal|"1001 0101 ssN0 dddd"
block|,
literal|"popl rrd,@rs"
block|,
literal|0
block|,
literal|"------"
block|,
literal|13
block|,
literal|16
block|,
literal|"0001 0011 ddN0 ssN0"
block|,
literal|"push @rd,@rs"
block|,
literal|0
block|,
literal|"------"
block|,
literal|14
block|,
literal|16
block|,
literal|"0101 0011 ddN0 0000 address_src"
block|,
literal|"push @rd,address_src"
block|,
literal|0
block|,
literal|"------"
block|,
literal|14
block|,
literal|16
block|,
literal|"0101 0011 ddN0 ssN0 address_src"
block|,
literal|"push @rd,address_src(rs)"
block|,
literal|0
block|,
literal|"------"
block|,
literal|12
block|,
literal|16
block|,
literal|"0000 1101 ddN0 1001 imm16"
block|,
literal|"push @rd,imm16"
block|,
literal|0
block|,
literal|"------"
block|,
literal|9
block|,
literal|16
block|,
literal|"1001 0011 ddN0 ssss"
block|,
literal|"push @rd,rs"
block|,
literal|0
block|,
literal|"------"
block|,
literal|20
block|,
literal|32
block|,
literal|"0001 0001 ddN0 ssN0"
block|,
literal|"pushl @rd,@rs"
block|,
literal|0
block|,
literal|"------"
block|,
literal|21
block|,
literal|32
block|,
literal|"0101 0001 ddN0 ssN0 address_src"
block|,
literal|"pushl @rd,address_src(rs)"
block|,
literal|0
block|,
literal|"------"
block|,
literal|21
block|,
literal|32
block|,
literal|"0101 0001 ddN0 0000 address_src"
block|,
literal|"pushl @rd,address_src"
block|,
literal|0
block|,
literal|"------"
block|,
literal|12
block|,
literal|32
block|,
literal|"1001 0001 ddN0 ssss"
block|,
literal|"pushl @rd,rrs"
block|,
literal|0
block|,
literal|"------"
block|,
literal|11
block|,
literal|16
block|,
literal|"0010 0011 ddN0 imm4"
block|,
literal|"res @rd,imm4"
block|,
literal|0
block|,
literal|"------"
block|,
literal|14
block|,
literal|16
block|,
literal|"0110 0011 ddN0 imm4 address_dst"
block|,
literal|"res address_dst(rd),imm4"
block|,
literal|0
block|,
literal|"------"
block|,
literal|13
block|,
literal|16
block|,
literal|"0110 0011 0000 imm4 address_dst"
block|,
literal|"res address_dst,imm4"
block|,
literal|0
block|,
literal|"------"
block|,
literal|4
block|,
literal|16
block|,
literal|"1010 0011 dddd imm4"
block|,
literal|"res rd,imm4"
block|,
literal|0
block|,
literal|"------"
block|,
literal|10
block|,
literal|16
block|,
literal|"0010 0011 0000 ssss 0000 dddd 0000 0000"
block|,
literal|"res rd,rs"
block|,
literal|0
block|,
literal|"------"
block|,
literal|11
block|,
literal|8
block|,
literal|"0010 0010 ddN0 imm4"
block|,
literal|"resb @rd,imm4"
block|,
literal|0
block|,
literal|"------"
block|,
literal|14
block|,
literal|8
block|,
literal|"0110 0010 ddN0 imm4 address_dst"
block|,
literal|"resb address_dst(rd),imm4"
block|,
literal|0
block|,
literal|"------"
block|,
literal|13
block|,
literal|8
block|,
literal|"0110 0010 0000 imm4 address_dst"
block|,
literal|"resb address_dst,imm4"
block|,
literal|0
block|,
literal|"------"
block|,
literal|4
block|,
literal|8
block|,
literal|"1010 0010 dddd imm4"
block|,
literal|"resb rbd,imm4"
block|,
literal|0
block|,
literal|"------"
block|,
literal|10
block|,
literal|8
block|,
literal|"0010 0010 0000 ssss 0000 dddd 0000 0000"
block|,
literal|"resb rbd,rs"
block|,
literal|0
block|,
literal|"CZSV--"
block|,
literal|7
block|,
literal|16
block|,
literal|"1000 1101 flags 0011"
block|,
literal|"resflg flags"
block|,
literal|0
block|,
literal|"------"
block|,
literal|10
block|,
literal|16
block|,
literal|"1001 1110 0000 cccc"
block|,
literal|"ret cc"
block|,
literal|0
block|,
literal|"CZSV--"
block|,
literal|6
block|,
literal|16
block|,
literal|"1011 0011 dddd 00I0"
block|,
literal|"rl rd,imm1or2"
block|,
literal|0
block|,
literal|"CZSV--"
block|,
literal|6
block|,
literal|8
block|,
literal|"1011 0010 dddd 00I0"
block|,
literal|"rlb rbd,imm1or2"
block|,
literal|0
block|,
literal|"CZSV--"
block|,
literal|6
block|,
literal|16
block|,
literal|"1011 0011 dddd 10I0"
block|,
literal|"rlc rd,imm1or2"
block|,
literal|0
block|,
literal|"-Z----"
block|,
literal|9
block|,
literal|8
block|,
literal|"1011 0010 dddd 10I0"
block|,
literal|"rlcb rbd,imm1or2"
block|,
literal|0
block|,
literal|"-Z----"
block|,
literal|9
block|,
literal|8
block|,
literal|"1011 1110 aaaa bbbb"
block|,
literal|"rldb rbb,rba"
block|,
literal|0
block|,
literal|"CZSV--"
block|,
literal|6
block|,
literal|16
block|,
literal|"1011 0011 dddd 01I0"
block|,
literal|"rr rd,imm1or2"
block|,
literal|0
block|,
literal|"CZSV--"
block|,
literal|6
block|,
literal|8
block|,
literal|"1011 0010 dddd 01I0"
block|,
literal|"rrb rbd,imm1or2"
block|,
literal|0
block|,
literal|"CZSV--"
block|,
literal|6
block|,
literal|16
block|,
literal|"1011 0011 dddd 11I0"
block|,
literal|"rrc rd,imm1or2"
block|,
literal|0
block|,
literal|"-Z----"
block|,
literal|9
block|,
literal|8
block|,
literal|"1011 0010 dddd 11I0"
block|,
literal|"rrcb rbd,imm1or2"
block|,
literal|0
block|,
literal|"-Z----"
block|,
literal|9
block|,
literal|8
block|,
literal|"1011 1100 aaaa bbbb"
block|,
literal|"rrdb rbb,rba"
block|,
literal|0
block|,
literal|"CZSV--"
block|,
literal|5
block|,
literal|16
block|,
literal|"1011 0111 ssss dddd"
block|,
literal|"sbc rd,rs"
block|,
literal|0
block|,
literal|"CZSVDH"
block|,
literal|5
block|,
literal|8
block|,
literal|"1011 0110 ssss dddd"
block|,
literal|"sbcb rbd,rbs"
block|,
literal|0
block|,
literal|"CZSVDH"
block|,
literal|33
block|,
literal|8
block|,
literal|"0111 1111 imm8"
block|,
literal|"sc imm8"
block|,
literal|0
block|,
literal|"CZSV--"
block|,
literal|15
block|,
literal|16
block|,
literal|"1011 0011 dddd 1011 0000 ssss 0000 0000"
block|,
literal|"sda rd,rs"
block|,
literal|0
block|,
literal|"CZSV--"
block|,
literal|15
block|,
literal|8
block|,
literal|"1011 0010 dddd 1011 0000 ssss 0000 0000"
block|,
literal|"sdab rbd,rs"
block|,
literal|0
block|,
literal|"CZSV--"
block|,
literal|15
block|,
literal|32
block|,
literal|"1011 0011 dddd 1111 0000 ssss 0000 0000"
block|,
literal|"sdal rrd,rs"
block|,
literal|0
block|,
literal|"CZS---"
block|,
literal|15
block|,
literal|16
block|,
literal|"1011 0011 dddd 0011 0000 ssss 0000 0000"
block|,
literal|"sdl rd,rs"
block|,
literal|0
block|,
literal|"CZS---"
block|,
literal|15
block|,
literal|8
block|,
literal|"1011 0010 dddd 0011 0000 ssss 0000 0000"
block|,
literal|"sdlb rbd,rs"
block|,
literal|0
block|,
literal|"CZS---"
block|,
literal|15
block|,
literal|32
block|,
literal|"1011 0011 dddd 0111 0000 ssss 0000 0000"
block|,
literal|"sdll rrd,rs"
block|,
literal|0
block|,
literal|"------"
block|,
literal|11
block|,
literal|16
block|,
literal|"0010 0101 ddN0 imm4"
block|,
literal|"set @rd,imm4"
block|,
literal|0
block|,
literal|"------"
block|,
literal|14
block|,
literal|16
block|,
literal|"0110 0101 ddN0 imm4 address_dst"
block|,
literal|"set address_dst(rd),imm4"
block|,
literal|0
block|,
literal|"------"
block|,
literal|13
block|,
literal|16
block|,
literal|"0110 0101 0000 imm4 address_dst"
block|,
literal|"set address_dst,imm4"
block|,
literal|0
block|,
literal|"------"
block|,
literal|4
block|,
literal|16
block|,
literal|"1010 0101 dddd imm4"
block|,
literal|"set rd,imm4"
block|,
literal|0
block|,
literal|"------"
block|,
literal|10
block|,
literal|16
block|,
literal|"0010 0101 0000 ssss 0000 dddd 0000 0000"
block|,
literal|"set rd,rs"
block|,
literal|0
block|,
literal|"------"
block|,
literal|11
block|,
literal|8
block|,
literal|"0010 0100 ddN0 imm4"
block|,
literal|"setb @rd,imm4"
block|,
literal|0
block|,
literal|"------"
block|,
literal|14
block|,
literal|8
block|,
literal|"0110 0100 ddN0 imm4 address_dst"
block|,
literal|"setb address_dst(rd),imm4"
block|,
literal|0
block|,
literal|"------"
block|,
literal|13
block|,
literal|8
block|,
literal|"0110 0100 0000 imm4 address_dst"
block|,
literal|"setb address_dst,imm4"
block|,
literal|0
block|,
literal|"------"
block|,
literal|4
block|,
literal|8
block|,
literal|"1010 0100 dddd imm4"
block|,
literal|"setb rbd,imm4"
block|,
literal|0
block|,
literal|"------"
block|,
literal|10
block|,
literal|8
block|,
literal|"0010 0100 0000 ssss 0000 dddd 0000 0000"
block|,
literal|"setb rbd,rs"
block|,
literal|0
block|,
literal|"CZSV--"
block|,
literal|7
block|,
literal|16
block|,
literal|"1000 1101 flags 0001"
block|,
literal|"setflg flags"
block|,
literal|0
block|,
literal|"------"
block|,
literal|0
block|,
literal|8
block|,
literal|"0011 1010 dddd 0101 imm16"
block|,
literal|"sinb rbd,imm16"
block|,
literal|0
block|,
literal|"------"
block|,
literal|0
block|,
literal|8
block|,
literal|"0011 1011 dddd 0101 imm16"
block|,
literal|"sin rd,imm16"
block|,
literal|0
block|,
literal|"------"
block|,
literal|0
block|,
literal|16
block|,
literal|"0011 1011 ssN0 1000 0001 aaaa ddN0 1000"
block|,
literal|"sind @rd,@rs,ra"
block|,
literal|0
block|,
literal|"------"
block|,
literal|0
block|,
literal|8
block|,
literal|"0011 1010 ssN0 1000 0001 aaaa ddN0 1000"
block|,
literal|"sindb @rd,@rs,rba"
block|,
literal|0
block|,
literal|"------"
block|,
literal|0
block|,
literal|8
block|,
literal|"0011 1010 ssN0 0001 0000 aaaa ddN0 1000"
block|,
literal|"sinib @rd,@rs,ra"
block|,
literal|0
block|,
literal|"------"
block|,
literal|0
block|,
literal|16
block|,
literal|"0011 1010 ssN0 0001 0000 aaaa ddN0 0000"
block|,
literal|"sinibr @rd,@rs,ra"
block|,
literal|0
block|,
literal|"CZSV--"
block|,
literal|13
block|,
literal|16
block|,
literal|"1011 0011 dddd 1001 0000 0000 imm8"
block|,
literal|"sla rd,imm8"
block|,
literal|0
block|,
literal|"CZSV--"
block|,
literal|13
block|,
literal|8
block|,
literal|"1011 0010 dddd 1001  0000 0000 imm8"
block|,
literal|"slab rbd,imm8"
block|,
literal|0
block|,
literal|"CZSV--"
block|,
literal|13
block|,
literal|32
block|,
literal|"1011 0011 dddd 1101 0000 0000 imm8"
block|,
literal|"slal rrd,imm8"
block|,
literal|0
block|,
literal|"CZS---"
block|,
literal|13
block|,
literal|16
block|,
literal|"1011 0011 dddd 0001 0000 0000 imm8"
block|,
literal|"sll rd,imm8"
block|,
literal|0
block|,
literal|"CZS---"
block|,
literal|13
block|,
literal|8
block|,
literal|"1011 0010 dddd 0001  0000 0000 imm8"
block|,
literal|"sllb rbd,imm8"
block|,
literal|0
block|,
literal|"CZS---"
block|,
literal|13
block|,
literal|32
block|,
literal|"1011 0011 dddd 0101 0000 0000 imm8"
block|,
literal|"slll rrd,imm8"
block|,
literal|0
block|,
literal|"------"
block|,
literal|0
block|,
literal|16
block|,
literal|"0011 1011 ssss 0111 imm16"
block|,
literal|"sout imm16,rs"
block|,
literal|0
block|,
literal|"------"
block|,
literal|0
block|,
literal|8
block|,
literal|"0011 1010 ssss 0111 imm16"
block|,
literal|"soutb imm16,rbs"
block|,
literal|0
block|,
literal|"------"
block|,
literal|0
block|,
literal|16
block|,
literal|"0011 1011 ssN0 1011 0000 aaaa ddN0 1000"
block|,
literal|"soutd @rd,@rs,ra"
block|,
literal|0
block|,
literal|"------"
block|,
literal|0
block|,
literal|8
block|,
literal|"0011 1010 ssN0 1011 0000 aaaa ddN0 1000"
block|,
literal|"soutdb @rd,@rs,rba"
block|,
literal|0
block|,
literal|"------"
block|,
literal|0
block|,
literal|8
block|,
literal|"0011 1010 ssN0 0011 0000 aaaa ddN0 1000"
block|,
literal|"soutib @rd,@rs,ra"
block|,
literal|0
block|,
literal|"------"
block|,
literal|0
block|,
literal|16
block|,
literal|"0011 1010 ssN0 0011 0000 aaaa ddN0 0000"
block|,
literal|"soutibr @rd,@rs,ra"
block|,
literal|0
block|,
literal|"CZSV--"
block|,
literal|13
block|,
literal|16
block|,
literal|"1011 0011 dddd 1001 1111 1111 nim8"
block|,
literal|"sra rd,imm8"
block|,
literal|0
block|,
literal|"CZSV--"
block|,
literal|13
block|,
literal|8
block|,
literal|"1011 0010 dddd 1001 0000 0000 nim8"
block|,
literal|"srab rbd,imm8"
block|,
literal|0
block|,
literal|"CZSV--"
block|,
literal|13
block|,
literal|32
block|,
literal|"1011 0011 dddd 1101 1111 1111 nim8"
block|,
literal|"sral rrd,imm8"
block|,
literal|0
block|,
literal|"CZSV--"
block|,
literal|13
block|,
literal|16
block|,
literal|"1011 0011 dddd 0001 1111 1111 nim8"
block|,
literal|"srl rd,imm8"
block|,
literal|0
block|,
literal|"CZSV--"
block|,
literal|13
block|,
literal|8
block|,
literal|"1011 0010 dddd 0001 0000 0000 nim8"
block|,
literal|"srlb rbd,imm8"
block|,
literal|0
block|,
literal|"CZSV--"
block|,
literal|13
block|,
literal|32
block|,
literal|"1011 0011 dddd 0101 1111 1111 nim8"
block|,
literal|"srll rrd,imm8"
block|,
literal|0
block|,
literal|"CZSV--"
block|,
literal|7
block|,
literal|16
block|,
literal|"0000 0011 ssN0 dddd"
block|,
literal|"sub rd,@rs"
block|,
literal|0
block|,
literal|"CZSV--"
block|,
literal|9
block|,
literal|16
block|,
literal|"0100 0011 0000 dddd address_src"
block|,
literal|"sub rd,address_src"
block|,
literal|0
block|,
literal|"CZSV--"
block|,
literal|10
block|,
literal|16
block|,
literal|"0100 0011 ssN0 dddd address_src"
block|,
literal|"sub rd,address_src(rs)"
block|,
literal|0
block|,
literal|"CZSV--"
block|,
literal|7
block|,
literal|16
block|,
literal|"0000 0011 0000 dddd imm16"
block|,
literal|"sub rd,imm16"
block|,
literal|0
block|,
literal|"CZSV--"
block|,
literal|4
block|,
literal|16
block|,
literal|"1000 0011 ssss dddd"
block|,
literal|"sub rd,rs"
block|,
literal|0
block|,
literal|"CZSVDH"
block|,
literal|7
block|,
literal|8
block|,
literal|"0000 0010 ssN0 dddd"
block|,
literal|"subb rbd,@rs"
block|,
literal|0
block|,
literal|"CZSVDH"
block|,
literal|9
block|,
literal|8
block|,
literal|"0100 0010 0000 dddd address_src"
block|,
literal|"subb rbd,address_src"
block|,
literal|0
block|,
literal|"CZSVDH"
block|,
literal|10
block|,
literal|8
block|,
literal|"0100 0010 ssN0 dddd address_src"
block|,
literal|"subb rbd,address_src(rs)"
block|,
literal|0
block|,
literal|"CZSVDH"
block|,
literal|7
block|,
literal|8
block|,
literal|"0000 0010 0000 dddd imm8 imm8"
block|,
literal|"subb rbd,imm8"
block|,
literal|0
block|,
literal|"CZSVDH"
block|,
literal|4
block|,
literal|8
block|,
literal|"1000 0010 ssss dddd"
block|,
literal|"subb rbd,rbs"
block|,
literal|0
block|,
literal|"CZSV--"
block|,
literal|14
block|,
literal|32
block|,
literal|"0001 0010 ssN0 dddd"
block|,
literal|"subl rrd,@rs"
block|,
literal|0
block|,
literal|"CZSV--"
block|,
literal|15
block|,
literal|32
block|,
literal|"0101 0010 0000 dddd address_src"
block|,
literal|"subl rrd,address_src"
block|,
literal|0
block|,
literal|"CZSV--"
block|,
literal|16
block|,
literal|32
block|,
literal|"0101 0010 ssN0 dddd address_src"
block|,
literal|"subl rrd,address_src(rs)"
block|,
literal|0
block|,
literal|"CZSV--"
block|,
literal|14
block|,
literal|32
block|,
literal|"0001 0010 0000 dddd imm32"
block|,
literal|"subl rrd,imm32"
block|,
literal|0
block|,
literal|"CZSV--"
block|,
literal|8
block|,
literal|32
block|,
literal|"1001 0010 ssss dddd"
block|,
literal|"subl rrd,rrs"
block|,
literal|0
block|,
literal|"------"
block|,
literal|5
block|,
literal|16
block|,
literal|"1010 1111 dddd cccc"
block|,
literal|"tcc cc,rd"
block|,
literal|0
block|,
literal|"------"
block|,
literal|5
block|,
literal|8
block|,
literal|"1010 1110 dddd cccc"
block|,
literal|"tccb cc,rbd"
block|,
literal|0
block|,
literal|"-ZS---"
block|,
literal|8
block|,
literal|16
block|,
literal|"0000 1101 ddN0 0100"
block|,
literal|"test @rd"
block|,
literal|0
block|,
literal|"------"
block|,
literal|11
block|,
literal|16
block|,
literal|"0100 1101 0000 0100 address_dst"
block|,
literal|"test address_dst"
block|,
literal|0
block|,
literal|"------"
block|,
literal|12
block|,
literal|16
block|,
literal|"0100 1101 ddN0 0100 address_dst"
block|,
literal|"test address_dst(rd)"
block|,
literal|0
block|,
literal|"------"
block|,
literal|7
block|,
literal|16
block|,
literal|"1000 1101 dddd 0100"
block|,
literal|"test rd"
block|,
literal|0
block|,
literal|"-ZSP--"
block|,
literal|8
block|,
literal|8
block|,
literal|"0000 1100 ddN0 0100"
block|,
literal|"testb @rd"
block|,
literal|0
block|,
literal|"-ZSP--"
block|,
literal|11
block|,
literal|8
block|,
literal|"0100 1100 0000 0100 address_dst"
block|,
literal|"testb address_dst"
block|,
literal|0
block|,
literal|"-ZSP--"
block|,
literal|12
block|,
literal|8
block|,
literal|"0100 1100 ddN0 0100 address_dst"
block|,
literal|"testb address_dst(rd)"
block|,
literal|0
block|,
literal|"-ZSP--"
block|,
literal|7
block|,
literal|8
block|,
literal|"1000 1100 dddd 0100"
block|,
literal|"testb rbd"
block|,
literal|0
block|,
literal|"-ZS---"
block|,
literal|13
block|,
literal|32
block|,
literal|"0001 1100 ddN0 1000"
block|,
literal|"testl @rd"
block|,
literal|0
block|,
literal|"-ZS---"
block|,
literal|16
block|,
literal|32
block|,
literal|"0101 1100 0000 1000 address_dst"
block|,
literal|"testl address_dst"
block|,
literal|0
block|,
literal|"-ZS---"
block|,
literal|17
block|,
literal|32
block|,
literal|"0101 1100 ddN0 1000 address_dst"
block|,
literal|"testl address_dst(rd)"
block|,
literal|0
block|,
literal|"-ZS---"
block|,
literal|13
block|,
literal|32
block|,
literal|"1001 1100 dddd 1000"
block|,
literal|"testl rrd"
block|,
literal|0
block|,
literal|"-ZSV--"
block|,
literal|25
block|,
literal|8
block|,
literal|"1011 1000 ddN0 1000 0000 aaaa ssN0 0000"
block|,
literal|"trdb @rd,@rs,rba"
block|,
literal|0
block|,
literal|"-ZSV--"
block|,
literal|25
block|,
literal|8
block|,
literal|"1011 1000 ddN0 1100 0000 aaaa ssN0 0000"
block|,
literal|"trdrb @rd,@rs,rba"
block|,
literal|0
block|,
literal|"-ZSV--"
block|,
literal|25
block|,
literal|8
block|,
literal|"1011 1000 ddN0 0000 0000 rrrr ssN0 0000"
block|,
literal|"trib @rd,@rs,rbr"
block|,
literal|0
block|,
literal|"-ZSV--"
block|,
literal|25
block|,
literal|8
block|,
literal|"1011 1000 ddN0 0100 0000 rrrr ssN0 0000"
block|,
literal|"trirb @rd,@rs,rbr"
block|,
literal|0
block|,
literal|"-ZSV--"
block|,
literal|25
block|,
literal|8
block|,
literal|"1011 1000 aaN0 1010 0000 rrrr bbN0 0000"
block|,
literal|"trtdb @ra,@rb,rbr"
block|,
literal|0
block|,
literal|"-ZSV--"
block|,
literal|25
block|,
literal|8
block|,
literal|"1011 1000 aaN0 1110 0000 rrrr bbN0 1110"
block|,
literal|"trtdrb @ra,@rb,rbr"
block|,
literal|0
block|,
literal|"-ZSV--"
block|,
literal|25
block|,
literal|8
block|,
literal|"1011 1000 aaN0 0010 0000 rrrr bbN0 0000"
block|,
literal|"trtib @ra,@rb,rbr"
block|,
literal|0
block|,
literal|"-ZSV--"
block|,
literal|25
block|,
literal|8
block|,
literal|"1011 1000 aaN0 0110 0000 rrrr bbN0 1110"
block|,
literal|"trtirb @ra,@rb,rbr"
block|,
literal|0
block|,
literal|"-ZSV--"
block|,
literal|25
block|,
literal|8
block|,
literal|"1011 1000 aaN0 1010 0000 rrrr bbN0 0000"
block|,
literal|"trtrb @ra,@rb,rbr"
block|,
literal|0
block|,
literal|"--S---"
block|,
literal|11
block|,
literal|16
block|,
literal|"0000 1101 ddN0 0110"
block|,
literal|"tset @rd"
block|,
literal|0
block|,
literal|"--S---"
block|,
literal|14
block|,
literal|16
block|,
literal|"0100 1101 0000 0110 address_dst"
block|,
literal|"tset address_dst"
block|,
literal|0
block|,
literal|"--S---"
block|,
literal|15
block|,
literal|16
block|,
literal|"0100 1101 ddN0 0110 address_dst"
block|,
literal|"tset address_dst(rd)"
block|,
literal|0
block|,
literal|"--S---"
block|,
literal|7
block|,
literal|16
block|,
literal|"1000 1101 dddd 0110"
block|,
literal|"tset rd"
block|,
literal|0
block|,
literal|"--S---"
block|,
literal|11
block|,
literal|8
block|,
literal|"0000 1100 ddN0 0110"
block|,
literal|"tsetb @rd"
block|,
literal|0
block|,
literal|"--S---"
block|,
literal|14
block|,
literal|8
block|,
literal|"0100 1100 0000 0110 address_dst"
block|,
literal|"tsetb address_dst"
block|,
literal|0
block|,
literal|"--S---"
block|,
literal|15
block|,
literal|8
block|,
literal|"0100 1100 ddN0 0110 address_dst"
block|,
literal|"tsetb address_dst(rd)"
block|,
literal|0
block|,
literal|"--S---"
block|,
literal|7
block|,
literal|8
block|,
literal|"1000 1100 dddd 0110"
block|,
literal|"tsetb rbd"
block|,
literal|0
block|,
literal|"-ZS---"
block|,
literal|7
block|,
literal|16
block|,
literal|"0000 1001 ssN0 dddd"
block|,
literal|"xor rd,@rs"
block|,
literal|0
block|,
literal|"-ZS---"
block|,
literal|9
block|,
literal|16
block|,
literal|"0100 1001 0000 dddd address_src"
block|,
literal|"xor rd,address_src"
block|,
literal|0
block|,
literal|"-ZS---"
block|,
literal|10
block|,
literal|16
block|,
literal|"0100 1001 ssN0 dddd address_src"
block|,
literal|"xor rd,address_src(rs)"
block|,
literal|0
block|,
literal|"-ZS---"
block|,
literal|7
block|,
literal|16
block|,
literal|"0000 1001 0000 dddd imm16"
block|,
literal|"xor rd,imm16"
block|,
literal|0
block|,
literal|"-ZS---"
block|,
literal|4
block|,
literal|16
block|,
literal|"1000 1001 ssss dddd"
block|,
literal|"xor rd,rs"
block|,
literal|0
block|,
literal|"-ZSP--"
block|,
literal|7
block|,
literal|8
block|,
literal|"0000 1000 ssN0 dddd"
block|,
literal|"xorb rbd,@rs"
block|,
literal|0
block|,
literal|"-ZSP--"
block|,
literal|9
block|,
literal|8
block|,
literal|"0100 1000 0000 dddd address_src"
block|,
literal|"xorb rbd,address_src"
block|,
literal|0
block|,
literal|"-ZSP--"
block|,
literal|10
block|,
literal|8
block|,
literal|"0100 1000 ssN0 dddd address_src"
block|,
literal|"xorb rbd,address_src(rs)"
block|,
literal|0
block|,
literal|"-ZSP--"
block|,
literal|7
block|,
literal|8
block|,
literal|"0000 1000 0000 dddd imm8 imm8"
block|,
literal|"xorb rbd,imm8"
block|,
literal|0
block|,
literal|"-ZSP--"
block|,
literal|4
block|,
literal|8
block|,
literal|"1000 1000 ssss dddd"
block|,
literal|"xorb rbd,rbs"
block|,
literal|0
block|,
literal|"------"
block|,
literal|7
block|,
literal|32
block|,
literal|"1000 1100 dddd 0001"
block|,
literal|"ldctlb rbd,ctrl"
block|,
literal|0
block|,
literal|"CZSVDH"
block|,
literal|7
block|,
literal|32
block|,
literal|"1000 1100 ssss 1001"
block|,
literal|"ldctlb ctrl,rbs"
block|,
literal|0
block|,
literal|"*"
block|,
literal|4
block|,
literal|8
block|,
literal|"1000 1000 ssss dddd"
block|,
literal|"xorb rbd,rbs"
block|,
literal|0
block|,
literal|"*"
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|}
decl_stmt|;
end_decl_stmt

begin_function
name|int
name|count
parameter_list|()
block|{
name|struct
name|op
modifier|*
name|p
init|=
name|opt
decl_stmt|;
name|int
name|r
init|=
literal|0
decl_stmt|;
while|while
condition|(
name|p
operator|->
name|name
condition|)
block|{
name|r
operator|++
expr_stmt|;
name|p
operator|++
expr_stmt|;
block|}
return|return
name|r
return|;
block|}
end_function

begin_function
specifier|static
name|int
name|func
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
name|struct
name|op
modifier|*
name|a
decl_stmt|;
name|struct
name|op
modifier|*
name|b
decl_stmt|;
block|{
return|return
name|strcmp
argument_list|(
operator|(
name|a
operator|)
operator|->
name|name
argument_list|,
operator|(
name|b
operator|)
operator|->
name|name
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/* opcode   literal  0000 nnnn insert nnn into stream  operand  0001 nnnn  insert operand reg nnn into stream */
end_comment

begin_struct
struct|struct
name|tok_struct
block|{
name|char
modifier|*
name|match
decl_stmt|;
name|char
modifier|*
name|token
decl_stmt|;
name|int
name|length
decl_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
name|struct
name|tok_struct
name|args
index|[]
init|=
block|{
block|{
literal|"address_src(rs)"
block|,
literal|"CLASS_X+(ARG_RS)"
block|,}
block|,
block|{
literal|"address_dst(rd)"
block|,
literal|"CLASS_X+(ARG_RD)"
block|,}
block|,
block|{
literal|"rs(imm16)"
block|,
literal|"CLASS_BA+(ARG_RS)"
block|,}
block|,
block|{
literal|"rd(imm16)"
block|,
literal|"CLASS_BA+(ARG_RD)"
block|,}
block|,
block|{
literal|"prd"
block|,
literal|"CLASS_PR+(ARG_RD)"
block|,}
block|,
block|{
literal|"address_src"
block|,
literal|"CLASS_DA+(ARG_SRC)"
block|,}
block|,
block|{
literal|"address_dst"
block|,
literal|"CLASS_DA+(ARG_DST)"
block|,}
block|,
block|{
literal|"rd(rx)"
block|,
literal|"CLASS_BX+(ARG_RD)"
block|,}
block|,
block|{
literal|"rs(rx)"
block|,
literal|"CLASS_BX+(ARG_RS)"
block|,}
block|,
block|{
literal|"disp16"
block|,
literal|"CLASS_DISP"
block|,}
block|,
block|{
literal|"disp12"
block|,
literal|"CLASS_DISP"
block|,}
block|,
block|{
literal|"disp7"
block|,
literal|"CLASS_DISP"
block|,}
block|,
block|{
literal|"disp8"
block|,
literal|"CLASS_DISP"
block|,}
block|,
block|{
literal|"flags"
block|,
literal|"CLASS_FLAGS"
block|,}
block|,
block|{
literal|"imm16"
block|,
literal|"CLASS_IMM+(ARG_IMM16)"
block|,}
block|,
block|{
literal|"imm1or2"
block|,
literal|"CLASS_IMM+(ARG_IMM1OR2)"
block|,}
block|,
block|{
literal|"imm32"
block|,
literal|"CLASS_IMM+(ARG_IMM32)"
block|,}
block|,
block|{
literal|"imm4m1"
block|,
literal|"CLASS_IMM +(ARG_IMM4M1)"
block|,}
block|,
block|{
literal|"imm4"
block|,
literal|"CLASS_IMM +(ARG_IMM4)"
block|,}
block|,
block|{
literal|"n"
block|,
literal|"CLASS_IMM + (ARG_IMMN)"
block|,}
block|,
block|{
literal|"ctrl"
block|,
literal|"CLASS_CTRL"
block|,}
block|,
block|{
literal|"rba"
block|,
literal|"CLASS_REG_BYTE+(ARG_RA)"
block|,}
block|,
block|{
literal|"rbb"
block|,
literal|"CLASS_REG_BYTE+(ARG_RB)"
block|,}
block|,
block|{
literal|"rbd"
block|,
literal|"CLASS_REG_BYTE+(ARG_RD)"
block|,}
block|,
block|{
literal|"rbs"
block|,
literal|"CLASS_REG_BYTE+(ARG_RS)"
block|,}
block|,
block|{
literal|"rbr"
block|,
literal|"CLASS_REG_BYTE+(ARG_RR)"
block|,}
block|,
block|{
literal|"rrd"
block|,
literal|"CLASS_REG_LONG+(ARG_RD)"
block|,}
block|,
block|{
literal|"rrs"
block|,
literal|"CLASS_REG_LONG+(ARG_RS)"
block|,}
block|,
block|{
literal|"rqd"
block|,
literal|"CLASS_REG_QUAD+(ARG_RD)"
block|,}
block|,
block|{
literal|"rd"
block|,
literal|"CLASS_REG_WORD+(ARG_RD)"
block|,}
block|,
block|{
literal|"rs"
block|,
literal|"CLASS_REG_WORD+(ARG_RS)"
block|,}
block|,
block|{
literal|"@rd"
block|,
literal|"CLASS_IR+(ARG_RD)"
block|,}
block|,
block|{
literal|"@ra"
block|,
literal|"CLASS_IR+(ARG_RA)"
block|,}
block|,
block|{
literal|"@rb"
block|,
literal|"CLASS_IR+(ARG_RB)"
block|,}
block|,
block|{
literal|"@rs"
block|,
literal|"CLASS_IR+(ARG_RS)"
block|,}
block|,
block|{
literal|"imm8"
block|,
literal|"CLASS_IMM+(ARG_IMM8)"
block|,}
block|,
block|{
literal|"i2"
block|,
literal|"CLASS_IMM+(ARG_IMM2)"
block|,}
block|,
block|{
literal|"cc"
block|,
literal|"CLASS_CC"
block|,}
block|,
block|{
literal|"rr"
block|,
literal|"CLASS_REG_WORD+(ARG_RR)"
block|,}
block|,
block|{
literal|"ra"
block|,
literal|"CLASS_REG_WORD+(ARG_RA)"
block|,}
block|,
block|{
literal|"rs"
block|,
literal|"CLASS_REG_WORD+(ARG_RS)"
block|,}
block|,
block|{
literal|"1"
block|,
literal|"CLASS_IMM+(ARG_IMM_1)"
block|,}
block|,
block|{
literal|"2"
block|,
literal|"CLASS_IMM+(ARG_IMM_2)"
block|,}
block|,
literal|0
block|,
literal|0
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|tok_struct
name|toks
index|[]
init|=
block|{
literal|"0000"
block|,
literal|"CLASS_BIT+0"
block|,
literal|1
block|,
literal|"0001"
block|,
literal|"CLASS_BIT+1"
block|,
literal|1
block|,
literal|"0010"
block|,
literal|"CLASS_BIT+2"
block|,
literal|1
block|,
literal|"0011"
block|,
literal|"CLASS_BIT+3"
block|,
literal|1
block|,
literal|"0100"
block|,
literal|"CLASS_BIT+4"
block|,
literal|1
block|,
literal|"0101"
block|,
literal|"CLASS_BIT+5"
block|,
literal|1
block|,
literal|"0110"
block|,
literal|"CLASS_BIT+6"
block|,
literal|1
block|,
literal|"0111"
block|,
literal|"CLASS_BIT+7"
block|,
literal|1
block|,
literal|"1000"
block|,
literal|"CLASS_BIT+8"
block|,
literal|1
block|,
literal|"1001"
block|,
literal|"CLASS_BIT+9"
block|,
literal|1
block|,
literal|"1010"
block|,
literal|"CLASS_BIT+0xa"
block|,
literal|1
block|,
literal|"1011"
block|,
literal|"CLASS_BIT+0xb"
block|,
literal|1
block|,
literal|"1100"
block|,
literal|"CLASS_BIT+0xc"
block|,
literal|1
block|,
literal|"1101"
block|,
literal|"CLASS_BIT+0xd"
block|,
literal|1
block|,
literal|"1110"
block|,
literal|"CLASS_BIT+0xe"
block|,
literal|1
block|,
literal|"1111"
block|,
literal|"CLASS_BIT+0xf"
block|,
literal|1
block|,
literal|"00I0"
block|,
literal|"CLASS_BIT_1OR2+0"
block|,
literal|1
block|,
literal|"00I0"
block|,
literal|"CLASS_BIT_1OR2+1"
block|,
literal|1
block|,
literal|"00I0"
block|,
literal|"CLASS_BIT_1OR2+2"
block|,
literal|1
block|,
literal|"00I0"
block|,
literal|"CLASS_BIT_1OR2+3"
block|,
literal|1
block|,
literal|"01I0"
block|,
literal|"CLASS_BIT_1OR2+4"
block|,
literal|1
block|,
literal|"01I0"
block|,
literal|"CLASS_BIT_1OR2+5"
block|,
literal|1
block|,
literal|"01I0"
block|,
literal|"CLASS_BIT_1OR2+6"
block|,
literal|1
block|,
literal|"01I0"
block|,
literal|"CLASS_BIT_1OR2+7"
block|,
literal|1
block|,
literal|"10I0"
block|,
literal|"CLASS_BIT_1OR2+8"
block|,
literal|1
block|,
literal|"10I0"
block|,
literal|"CLASS_BIT_1OR2+9"
block|,
literal|1
block|,
literal|"10I0"
block|,
literal|"CLASS_BIT_1OR2+0xa"
block|,
literal|1
block|,
literal|"10I0"
block|,
literal|"CLASS_BIT_1OR2+0xb"
block|,
literal|1
block|,
literal|"11I0"
block|,
literal|"CLASS_BIT_1OR2+0xc"
block|,
literal|1
block|,
literal|"11I0"
block|,
literal|"CLASS_BIT_1OR2+0xd"
block|,
literal|1
block|,
literal|"11I0"
block|,
literal|"CLASS_BIT_1OR2+0xe"
block|,
literal|1
block|,
literal|"11I0"
block|,
literal|"CLASS_BIT_1OR2+0xf"
block|,
literal|1
block|,
literal|"ssss"
block|,
literal|"CLASS_REG+(ARG_RS)"
block|,
literal|1
block|,
literal|"dddd"
block|,
literal|"CLASS_REG+(ARG_RD)"
block|,
literal|1
block|,
literal|"aaaa"
block|,
literal|"CLASS_REG+(ARG_RA)"
block|,
literal|1
block|,
literal|"bbbb"
block|,
literal|"CLASS_REG+(ARG_RB)"
block|,
literal|1
block|,
literal|"rrrr"
block|,
literal|"CLASS_REG+(ARG_RR)"
block|,
literal|1
block|,
literal|"ssN0"
block|,
literal|"CLASS_REGN0+(ARG_RS)"
block|,
literal|1
block|,
literal|"ddN0"
block|,
literal|"CLASS_REGN0+(ARG_RD)"
block|,
literal|1
block|,
literal|"aaN0"
block|,
literal|"CLASS_REGN0+(ARG_RA)"
block|,
literal|1
block|,
literal|"bbN0"
block|,
literal|"CLASS_REGN0+(ARG_RB)"
block|,
literal|1
block|,
literal|"rrN0"
block|,
literal|"CLASS_REGN0+(ARG_RR)"
block|,
literal|1
block|,
literal|"cccc"
block|,
literal|"CLASS_CC"
block|,
literal|1
block|,
literal|"nnnn"
block|,
literal|"CLASS_IMM+(ARG_IMMN)"
block|,
literal|1
block|,
literal|"xxxx"
block|,
literal|"CLASS_REG+(ARG_RX)"
block|,
literal|1
block|,
literal|"xxN0"
block|,
literal|"CLASS_REGN0+(ARG_RX)"
block|,
literal|1
block|,
literal|"nminus1"
block|,
literal|"CLASS_IMM+(ARG_IMMNMINUS1)"
block|,
literal|1
block|,
literal|"disp16"
block|,
literal|"CLASS_DISP+(ARG_DISP16)"
block|,
literal|4
block|,
literal|"disp12"
block|,
literal|"CLASS_DISP+(ARG_DISP12)"
block|,
literal|3
block|,
literal|"flags"
block|,
literal|"CLASS_FLAGS"
block|,
literal|1
block|,
literal|"address_dst"
block|,
literal|"CLASS_ADDRESS+(ARG_DST)"
block|,
literal|4
block|,
literal|"address_src"
block|,
literal|"CLASS_ADDRESS+(ARG_SRC)"
block|,
literal|4
block|,
literal|"imm4m1"
block|,
literal|"CLASS_IMM+(ARG_IMM4M1)"
block|,
literal|1
block|,
literal|"imm4"
block|,
literal|"CLASS_IMM+(ARG_IMM4)"
block|,
literal|1
block|,
literal|"imm8"
block|,
literal|"CLASS_IMM+(ARG_IMM8)"
block|,
literal|2
block|,
literal|"imm16"
block|,
literal|"CLASS_IMM+(ARG_IMM16)"
block|,
literal|4
block|,
literal|"imm32"
block|,
literal|"CLASS_IMM+(ARG_IMM32)"
block|,
literal|8
block|,
literal|"nim8"
block|,
literal|"CLASS_IMM+(ARG_NIM8)"
block|,
literal|2
block|,
literal|"0ccc"
block|,
literal|"CLASS_0CCC"
block|,
literal|1
block|,
literal|"1ccc"
block|,
literal|"CLASS_1CCC"
block|,
literal|1
block|,
literal|"disp8"
block|,
literal|"CLASS_DISP8"
block|,
literal|2
block|,
literal|"0disp7"
block|,
literal|"CLASS_0DISP7"
block|,
literal|2
block|,
literal|"1disp7"
block|,
literal|"CLASS_1DISP7"
block|,
literal|2
block|,
literal|"01ii"
block|,
literal|"CLASS_01II"
block|,
literal|1
block|,
literal|"00ii"
block|,
literal|"CLASS_00II"
block|,
literal|1
block|,
literal|0
block|,
literal|0
block|}
decl_stmt|;
end_decl_stmt

begin_function
name|char
modifier|*
name|translate
parameter_list|(
name|table
parameter_list|,
name|x
parameter_list|,
name|length
parameter_list|)
name|struct
name|tok_struct
modifier|*
name|table
decl_stmt|;
name|char
modifier|*
name|x
decl_stmt|;
name|int
modifier|*
name|length
decl_stmt|;
block|{
name|int
name|found
decl_stmt|;
name|found
operator|=
literal|0
expr_stmt|;
while|while
condition|(
name|table
operator|->
name|match
condition|)
block|{
name|int
name|l
init|=
name|strlen
argument_list|(
name|table
operator|->
name|match
argument_list|)
decl_stmt|;
if|if
condition|(
name|strncmp
argument_list|(
name|table
operator|->
name|match
argument_list|,
name|x
argument_list|,
name|l
argument_list|)
operator|==
literal|0
condition|)
block|{
comment|/* Got a hit */
name|printf
argument_list|(
literal|"%s"
argument_list|,
name|table
operator|->
name|token
argument_list|)
expr_stmt|;
operator|*
name|length
operator|+=
name|table
operator|->
name|length
expr_stmt|;
return|return
name|x
operator|+
name|l
return|;
block|}
name|table
operator|++
expr_stmt|;
block|}
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"Can't find %s\n"
argument_list|,
name|x
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"**** Can't find %s\n"
argument_list|,
name|x
argument_list|)
expr_stmt|;
while|while
condition|(
operator|*
name|x
condition|)
name|x
operator|++
expr_stmt|;
return|return
name|x
return|;
block|}
end_function

begin_function
name|void
name|chewbits
parameter_list|(
name|bits
parameter_list|,
name|length
parameter_list|)
name|char
modifier|*
name|bits
decl_stmt|;
name|int
modifier|*
name|length
decl_stmt|;
block|{
name|int
name|n
init|=
literal|0
decl_stmt|;
operator|*
name|length
operator|=
literal|0
expr_stmt|;
name|printf
argument_list|(
literal|"{"
argument_list|)
expr_stmt|;
while|while
condition|(
operator|*
name|bits
condition|)
block|{
while|while
condition|(
operator|*
name|bits
operator|==
literal|' '
condition|)
block|{
name|bits
operator|++
expr_stmt|;
block|}
name|bits
operator|=
name|translate
argument_list|(
name|toks
argument_list|,
name|bits
argument_list|,
name|length
argument_list|)
expr_stmt|;
name|n
operator|++
expr_stmt|;
name|printf
argument_list|(
literal|","
argument_list|)
expr_stmt|;
block|}
while|while
condition|(
name|n
operator|<
name|BYTE_INFO_LEN
operator|-
literal|1
condition|)
block|{
name|printf
argument_list|(
literal|"0,"
argument_list|)
expr_stmt|;
name|n
operator|++
expr_stmt|;
block|}
name|printf
argument_list|(
literal|"}"
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
specifier|static
name|int
name|chewname
parameter_list|(
name|name
parameter_list|)
name|char
modifier|*
name|name
decl_stmt|;
block|{
name|char
modifier|*
name|n
decl_stmt|;
name|int
name|nargs
init|=
literal|0
decl_stmt|;
name|n
operator|=
name|name
expr_stmt|;
name|printf
argument_list|(
literal|"\""
argument_list|)
expr_stmt|;
while|while
condition|(
operator|*
name|n
operator|&&
operator|!
name|iswhite
argument_list|(
operator|*
name|n
argument_list|)
condition|)
block|{
name|printf
argument_list|(
literal|"%c"
argument_list|,
operator|*
name|n
argument_list|)
expr_stmt|;
name|n
operator|++
expr_stmt|;
block|}
name|printf
argument_list|(
literal|"\","
argument_list|)
expr_stmt|;
comment|/* Scan the operands and make entires for 				   them -remember indirect things */
name|n
operator|=
name|name
expr_stmt|;
name|printf
argument_list|(
literal|"OPC_"
argument_list|)
expr_stmt|;
while|while
condition|(
operator|*
name|n
operator|&&
operator|!
name|iswhite
argument_list|(
operator|*
name|n
argument_list|)
condition|)
block|{
name|printf
argument_list|(
literal|"%c"
argument_list|,
operator|*
name|n
argument_list|)
expr_stmt|;
name|n
operator|++
expr_stmt|;
block|}
name|printf
argument_list|(
literal|",0,{"
argument_list|)
expr_stmt|;
while|while
condition|(
operator|*
name|n
condition|)
block|{
name|int
name|d
decl_stmt|;
while|while
condition|(
operator|*
name|n
operator|==
literal|','
operator|||
name|iswhite
argument_list|(
operator|*
name|n
argument_list|)
condition|)
name|n
operator|++
expr_stmt|;
name|nargs
operator|++
expr_stmt|;
name|n
operator|=
name|translate
argument_list|(
name|args
argument_list|,
name|n
argument_list|,
operator|&
name|d
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|","
argument_list|)
expr_stmt|;
block|}
if|if
condition|(
name|nargs
operator|==
literal|0
condition|)
block|{
name|printf
argument_list|(
literal|"0"
argument_list|)
expr_stmt|;
block|}
name|printf
argument_list|(
literal|"},"
argument_list|)
expr_stmt|;
return|return
name|nargs
return|;
block|}
end_function

begin_function
specifier|static
name|void
name|sub
parameter_list|(
name|x
parameter_list|,
name|c
parameter_list|)
name|char
modifier|*
name|x
decl_stmt|;
name|char
name|c
decl_stmt|;
block|{
while|while
condition|(
operator|*
name|x
condition|)
block|{
if|if
condition|(
name|x
index|[
literal|0
index|]
operator|==
name|c
operator|&&
name|x
index|[
literal|1
index|]
operator|==
name|c
operator|&&
name|x
index|[
literal|2
index|]
operator|==
name|c
operator|&&
name|x
index|[
literal|3
index|]
operator|==
name|c
condition|)
block|{
name|x
index|[
literal|2
index|]
operator|=
literal|'N'
expr_stmt|;
name|x
index|[
literal|3
index|]
operator|=
literal|'0'
expr_stmt|;
block|}
name|x
operator|++
expr_stmt|;
block|}
block|}
end_function

begin_if
if|#
directive|if
literal|0
end_if

begin_define
define|#
directive|define
name|D
parameter_list|(
name|x
parameter_list|)
value|((x) == '1' || (x) =='0')
end_define

begin_define
define|#
directive|define
name|M
parameter_list|(
name|y
parameter_list|)
value|(strncmp(y,x,4)==0)
end_define

begin_endif
unit|printmangled (x)      char *x; {   return;   while (*x)     {       if (D (x[0])&& D (x[1])&& D (x[2])&& D (x[3])) 	{ 	  printf ("XXXX"); 	}       else if (M ("ssss")) 	{ 	  printf ("ssss"); 	}       else if (M ("dddd")) 	{ 	  printf ("dddd"); 	}       else 	printf ("____");        x += 4;        if (x[0] == ' ') 	{ 	  printf ("_"); 	  x++; 	}     }  }
endif|#
directive|endif
end_endif

begin_comment
comment|/*#define WORK_TYPE*/
end_comment

begin_function
name|void
name|print_type
parameter_list|(
name|n
parameter_list|)
name|struct
name|op
modifier|*
name|n
decl_stmt|;
block|{
ifdef|#
directive|ifdef
name|WORK_TYPE
while|while
condition|(
operator|*
name|s
operator|&&
operator|!
name|iswhite
argument_list|(
operator|*
name|s
argument_list|)
condition|)
block|{
name|l
operator|=
operator|*
name|s
expr_stmt|;
name|s
operator|++
expr_stmt|;
block|}
switch|switch
condition|(
name|l
condition|)
block|{
case|case
literal|'l'
case|:
name|printf
argument_list|(
literal|"32,"
argument_list|)
expr_stmt|;
break|break;
case|case
literal|'b'
case|:
name|printf
argument_list|(
literal|"8,"
argument_list|)
expr_stmt|;
break|break;
default|default:
name|printf
argument_list|(
literal|"16,"
argument_list|)
expr_stmt|;
break|break;
block|}
else|#
directive|else
name|printf
argument_list|(
literal|"%2d,"
argument_list|,
name|n
operator|->
name|type
argument_list|)
expr_stmt|;
endif|#
directive|endif
block|}
end_function

begin_function
name|void
name|internal
parameter_list|()
block|{
name|int
name|c
init|=
name|count
argument_list|()
decl_stmt|;
name|struct
name|op
modifier|*
name|new
init|=
operator|(
expr|struct
name|op
operator|*
operator|)
name|xmalloc
argument_list|(
sizeof|sizeof
argument_list|(
expr|struct
name|op
argument_list|)
operator|*
name|c
argument_list|)
decl_stmt|;
name|struct
name|op
modifier|*
name|p
init|=
name|opt
decl_stmt|;
name|memcpy
argument_list|(
name|new
argument_list|,
name|p
argument_list|,
name|c
operator|*
sizeof|sizeof
argument_list|(
expr|struct
name|op
argument_list|)
argument_list|)
expr_stmt|;
comment|/* sort all names in table alphabetically */
name|qsort
argument_list|(
name|new
argument_list|,
name|c
argument_list|,
sizeof|sizeof
argument_list|(
expr|struct
name|op
argument_list|)
argument_list|,
name|func
argument_list|)
expr_stmt|;
name|p
operator|=
name|new
expr_stmt|;
while|while
condition|(
name|p
operator|->
name|flags
index|[
literal|0
index|]
operator|!=
literal|'*'
condition|)
block|{
comment|/* If there are any @rs, sub the ssss into a ssn0,        (rs), (ssn0)        */
name|int
name|loop
init|=
literal|1
decl_stmt|;
name|printf
argument_list|(
literal|"\"%s\",%2d, "
argument_list|,
name|p
operator|->
name|flags
argument_list|,
name|p
operator|->
name|cycles
argument_list|)
expr_stmt|;
while|while
condition|(
name|loop
condition|)
block|{
name|char
modifier|*
name|s
init|=
name|p
operator|->
name|name
decl_stmt|;
name|loop
operator|=
literal|0
expr_stmt|;
while|while
condition|(
operator|*
name|s
condition|)
block|{
if|if
condition|(
name|s
index|[
literal|0
index|]
operator|==
literal|'@'
condition|)
block|{
name|char
name|c
decl_stmt|;
comment|/* skip the r and sub the string */
name|s
operator|++
expr_stmt|;
name|c
operator|=
name|s
index|[
literal|1
index|]
expr_stmt|;
name|sub
argument_list|(
name|p
operator|->
name|bits
argument_list|,
name|c
argument_list|)
expr_stmt|;
block|}
if|if
condition|(
name|s
index|[
literal|0
index|]
operator|==
literal|'('
operator|&&
name|s
index|[
literal|3
index|]
operator|==
literal|')'
condition|)
block|{
name|sub
argument_list|(
name|p
operator|->
name|bits
argument_list|,
name|s
index|[
literal|2
index|]
argument_list|)
expr_stmt|;
block|}
if|if
condition|(
name|s
index|[
literal|0
index|]
operator|==
literal|'('
condition|)
block|{
name|sub
argument_list|(
name|p
operator|->
name|bits
argument_list|,
name|s
index|[
operator|-
literal|1
index|]
argument_list|)
expr_stmt|;
block|}
name|s
operator|++
expr_stmt|;
block|}
block|}
name|print_type
argument_list|(
name|p
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"\"%s\",\"%s\",0,\n"
argument_list|,
name|p
operator|->
name|bits
argument_list|,
name|p
operator|->
name|name
argument_list|)
expr_stmt|;
name|p
operator|++
expr_stmt|;
block|}
block|}
end_function

begin_function
specifier|static
name|void
name|gas
parameter_list|()
block|{
name|int
name|c
init|=
name|count
argument_list|()
decl_stmt|;
name|struct
name|op
modifier|*
name|p
init|=
name|opt
decl_stmt|;
name|int
name|idx
init|=
literal|0
decl_stmt|;
name|char
modifier|*
name|oldname
init|=
literal|""
decl_stmt|;
name|struct
name|op
modifier|*
name|new
init|=
operator|(
expr|struct
name|op
operator|*
operator|)
name|xmalloc
argument_list|(
sizeof|sizeof
argument_list|(
expr|struct
name|op
argument_list|)
operator|*
name|c
argument_list|)
decl_stmt|;
name|memcpy
argument_list|(
name|new
argument_list|,
name|p
argument_list|,
name|c
operator|*
sizeof|sizeof
argument_list|(
expr|struct
name|op
argument_list|)
argument_list|)
expr_stmt|;
comment|/* sort all names in table alphabetically */
name|qsort
argument_list|(
name|new
argument_list|,
name|c
argument_list|,
sizeof|sizeof
argument_list|(
expr|struct
name|op
argument_list|)
argument_list|,
name|func
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"			/* THIS FILE IS AUTOMAGICALLY GENERATED, DON'T EDIT IT */\n"
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"#define ARG_MASK 0x0f\n"
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"#define ARG_SRC 0x01\n"
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"#define ARG_DST 0x02\n"
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"#define ARG_RS 0x01\n"
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"#define ARG_RD 0x02\n"
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"#define ARG_RA 0x03\n"
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"#define ARG_RB 0x04\n"
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"#define ARG_RR 0x05\n"
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"#define ARG_RX 0x06\n"
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"#define ARG_IMM4 0x01\n"
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"#define ARG_IMM8 0x02\n"
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"#define ARG_IMM16 0x03\n"
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"#define ARG_IMM32 0x04\n"
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"#define ARG_IMMN 0x05\n"
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"#define ARG_IMMNMINUS1 0x05\n"
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"#define ARG_IMM_1 0x06\n"
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"#define ARG_IMM_2 0x07\n"
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"#define ARG_DISP16 0x08\n"
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"#define ARG_NIM8 0x09\n"
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"#define ARG_IMM2 0x0a\n"
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"#define ARG_IMM1OR2 0x0b\n"
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"#define ARG_DISP12 0x0b\n"
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"#define ARG_DISP8 0x0c\n"
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"#define ARG_IMM4M1 0x0d\n"
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"#define CLASS_MASK 0x1fff0\n"
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"#define CLASS_X 0x10\n"
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"#define CLASS_BA 0x20\n"
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"#define CLASS_DA 0x30\n"
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"#define CLASS_BX 0x40\n"
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"#define CLASS_DISP 0x50\n"
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"#define CLASS_IMM 0x60\n"
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"#define CLASS_CC 0x70\n"
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"#define CLASS_CTRL 0x80\n"
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"#define CLASS_ADDRESS 0xd0\n"
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"#define CLASS_0CCC 0xe0\n"
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"#define CLASS_1CCC 0xf0\n"
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"#define CLASS_0DISP7 0x100\n"
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"#define CLASS_1DISP7 0x200\n"
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"#define CLASS_01II 0x300\n"
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"#define CLASS_00II 0x400\n"
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"#define CLASS_BIT 0x500\n"
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"#define CLASS_FLAGS 0x600\n"
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"#define CLASS_IR 0x700\n"
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"#define CLASS_DISP8 0x800\n"
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"#define CLASS_BIT_1OR2 0x900\n"
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"#define CLASS_REG 0x7000\n"
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"#define CLASS_REG_BYTE 0x2000\n"
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"#define CLASS_REG_WORD 0x3000\n"
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"#define CLASS_REG_QUAD 0x4000\n"
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"#define CLASS_REG_LONG 0x5000\n"
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"#define CLASS_REGN0 0x8000\n"
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"#define CLASS_PR 0x10000\n"
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"#define OPC_adc 0\n"
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"#define OPC_adcb 1\n"
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"#define OPC_add 2\n"
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"#define OPC_addb 3\n"
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"#define OPC_addl 4\n"
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"#define OPC_and 5\n"
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"#define OPC_andb 6\n"
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"#define OPC_bit 7\n"
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"#define OPC_bitb 8\n"
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"#define OPC_call 9\n"
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"#define OPC_calr 10\n"
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"#define OPC_clr 11\n"
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"#define OPC_clrb 12\n"
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"#define OPC_com 13\n"
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"#define OPC_comb 14\n"
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"#define OPC_comflg 15\n"
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"#define OPC_cp 16\n"
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"#define OPC_cpb 17\n"
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"#define OPC_cpd 18\n"
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"#define OPC_cpdb 19\n"
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"#define OPC_cpdr 20\n"
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"#define OPC_cpdrb 21\n"
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"#define OPC_cpi 22\n"
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"#define OPC_cpib 23\n"
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"#define OPC_cpir 24\n"
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"#define OPC_cpirb 25\n"
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"#define OPC_cpl 26\n"
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"#define OPC_cpsd 27\n"
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"#define OPC_cpsdb 28\n"
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"#define OPC_cpsdr 29\n"
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"#define OPC_cpsdrb 30\n"
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"#define OPC_cpsi 31\n"
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"#define OPC_cpsib 32\n"
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"#define OPC_cpsir 33\n"
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"#define OPC_cpsirb 34\n"
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"#define OPC_dab 35\n"
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"#define OPC_dbjnz 36\n"
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"#define OPC_dec 37\n"
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"#define OPC_decb 38\n"
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"#define OPC_di 39\n"
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"#define OPC_div 40\n"
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"#define OPC_divl 41\n"
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"#define OPC_djnz 42\n"
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"#define OPC_ei 43\n"
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"#define OPC_ex 44\n"
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"#define OPC_exb 45\n"
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"#define OPC_exts 46\n"
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"#define OPC_extsb 47\n"
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"#define OPC_extsl 48\n"
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"#define OPC_halt 49\n"
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"#define OPC_in 50\n"
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"#define OPC_inb 51\n"
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"#define OPC_inc 52\n"
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"#define OPC_incb 53\n"
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"#define OPC_ind 54\n"
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"#define OPC_indb 55\n"
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"#define OPC_inib 56\n"
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"#define OPC_inibr 57\n"
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"#define OPC_iret 58\n"
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"#define OPC_jp 59\n"
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"#define OPC_jr 60\n"
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"#define OPC_ld 61\n"
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"#define OPC_lda 62\n"
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"#define OPC_ldar 63\n"
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"#define OPC_ldb 64\n"
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"#define OPC_ldctl 65\n"
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"#define OPC_ldir 66\n"
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"#define OPC_ldirb 67\n"
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"#define OPC_ldk 68\n"
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"#define OPC_ldl 69\n"
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"#define OPC_ldm 70\n"
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"#define OPC_ldps 71\n"
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"#define OPC_ldr 72\n"
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"#define OPC_ldrb 73\n"
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"#define OPC_ldrl 74\n"
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"#define OPC_mbit 75\n"
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"#define OPC_mreq 76\n"
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"#define OPC_mres 77\n"
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"#define OPC_mset 78\n"
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"#define OPC_mult 79\n"
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"#define OPC_multl 80\n"
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"#define OPC_neg 81\n"
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"#define OPC_negb 82\n"
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"#define OPC_nop 83\n"
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"#define OPC_or 84\n"
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"#define OPC_orb 85\n"
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"#define OPC_out 86\n"
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"#define OPC_outb 87\n"
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"#define OPC_outd 88\n"
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"#define OPC_outdb 89\n"
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"#define OPC_outib 90\n"
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"#define OPC_outibr 91\n"
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"#define OPC_pop 92\n"
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"#define OPC_popl 93\n"
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"#define OPC_push 94\n"
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"#define OPC_pushl 95\n"
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"#define OPC_res 96\n"
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"#define OPC_resb 97\n"
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"#define OPC_resflg 98\n"
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"#define OPC_ret 99\n"
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"#define OPC_rl 100\n"
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"#define OPC_rlb 101\n"
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"#define OPC_rlc 102\n"
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"#define OPC_rlcb 103\n"
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"#define OPC_rldb 104\n"
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"#define OPC_rr 105\n"
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"#define OPC_rrb 106\n"
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"#define OPC_rrc 107\n"
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"#define OPC_rrcb 108\n"
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"#define OPC_rrdb 109\n"
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"#define OPC_sbc 110\n"
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"#define OPC_sbcb 111\n"
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"#define OPC_sda 112\n"
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"#define OPC_sdab 113\n"
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"#define OPC_sdal 114\n"
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"#define OPC_sdl 115\n"
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"#define OPC_sdlb 116\n"
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"#define OPC_sdll 117\n"
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"#define OPC_set 118\n"
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"#define OPC_setb 119\n"
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"#define OPC_setflg 120\n"
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"#define OPC_sinb 121\n"
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"#define OPC_sind 122\n"
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"#define OPC_sindb 123\n"
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"#define OPC_sinib 124\n"
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"#define OPC_sinibr 125\n"
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"#define OPC_sla 126\n"
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"#define OPC_slab 127\n"
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"#define OPC_slal 128\n"
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"#define OPC_sll 129\n"
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"#define OPC_sllb 130\n"
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"#define OPC_slll 131\n"
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"#define OPC_sout 132\n"
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"#define OPC_soutb 133\n"
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"#define OPC_soutd 134\n"
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"#define OPC_soutdb 135\n"
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"#define OPC_soutib 136\n"
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"#define OPC_soutibr 137\n"
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"#define OPC_sra 138\n"
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"#define OPC_srab 139\n"
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"#define OPC_sral 140\n"
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"#define OPC_srl 141\n"
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"#define OPC_srlb 142\n"
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"#define OPC_srll 143\n"
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"#define OPC_sub 144\n"
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"#define OPC_subb 145\n"
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"#define OPC_subl 146\n"
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"#define OPC_tcc 147\n"
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"#define OPC_tccb 148\n"
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"#define OPC_test 149\n"
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"#define OPC_testb 150\n"
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"#define OPC_testl 151\n"
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"#define OPC_trdb 152\n"
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"#define OPC_trdrb 153\n"
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"#define OPC_trib 154\n"
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"#define OPC_trirb 155\n"
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"#define OPC_trtdrb 156\n"
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"#define OPC_trtib 157\n"
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"#define OPC_trtirb 158\n"
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"#define OPC_trtrb 159\n"
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"#define OPC_tset 160\n"
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"#define OPC_tsetb 161\n"
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"#define OPC_xor 162\n"
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"#define OPC_xorb 163\n"
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"#define OPC_ldd  164 \n"
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"#define OPC_lddb  165 \n"
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"#define OPC_lddr  166 \n"
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"#define OPC_lddrb 167  \n"
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"#define OPC_ldi  168 \n"
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"#define OPC_ldib 169  \n"
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"#define OPC_sc   170\n"
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"#define OPC_bpt   171\n"
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"#define OPC_ext0e 172\n"
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"#define OPC_ext0f 172\n"
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"#define OPC_ext8e 172\n"
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"#define OPC_ext8f 172\n"
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"#define OPC_rsvd36 172\n"
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"#define OPC_rsvd38 172\n"
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"#define OPC_rsvd78 172\n"
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"#define OPC_rsvd7e 172\n"
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"#define OPC_rsvd9d 172\n"
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"#define OPC_rsvd9f 172\n"
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"#define OPC_rsvdb9 172\n"
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"#define OPC_rsvdbf 172\n"
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"#define OPC_outi 173\n"
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"#define OPC_ldctlb 174\n"
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"#define OPC_sin 175\n"
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"#define OPC_trtdb 176\n"
argument_list|)
expr_stmt|;
if|#
directive|if
literal|0
block|for (i = 0; toks[i].token; i++)     printf ("#define %s\t0x%x\n", toks[i].token, i * 16);
endif|#
directive|endif
name|printf
argument_list|(
literal|"typedef struct {\n"
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"#ifdef NICENAMES\n"
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"char *nicename;\n"
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"int type;\n"
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"int cycles;\n"
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"int flags;\n"
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"#endif\n"
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"char *name;\n"
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"unsigned char opcode;\n"
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"void (*func) PARAMS ((void));\n"
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"unsigned int arg_info[4];\n"
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"unsigned int byte_info[%d];\n"
argument_list|,
name|BYTE_INFO_LEN
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"int noperands;\n"
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"int length;\n"
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"int idx;\n"
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"} opcode_entry_type;\n"
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"#ifdef DEFINE_TABLE\n"
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"opcode_entry_type z8k_table[] = {\n"
argument_list|)
expr_stmt|;
while|while
condition|(
name|new
operator|->
name|flags
operator|&&
name|new
operator|->
name|flags
index|[
literal|0
index|]
condition|)
block|{
name|int
name|nargs
decl_stmt|;
name|int
name|length
decl_stmt|;
name|printf
argument_list|(
literal|"\n\n/* %s *** %s */\n"
argument_list|,
name|new
operator|->
name|bits
argument_list|,
name|new
operator|->
name|name
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"{\n"
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"#ifdef NICENAMES\n"
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"\"%s\",%d,%d,\n"
argument_list|,
name|new
operator|->
name|name
argument_list|,
name|new
operator|->
name|type
argument_list|,
name|new
operator|->
name|cycles
argument_list|)
expr_stmt|;
block|{
name|int
name|answer
init|=
literal|0
decl_stmt|;
name|char
modifier|*
name|p
init|=
name|new
operator|->
name|flags
decl_stmt|;
while|while
condition|(
operator|*
name|p
condition|)
block|{
name|answer
operator|<<=
literal|1
expr_stmt|;
if|if
condition|(
operator|*
name|p
operator|!=
literal|'-'
condition|)
name|answer
operator||=
literal|1
expr_stmt|;
name|p
operator|++
expr_stmt|;
block|}
name|printf
argument_list|(
literal|"0x%02x,\n"
argument_list|,
name|answer
argument_list|)
expr_stmt|;
block|}
name|printf
argument_list|(
literal|"#endif\n"
argument_list|)
expr_stmt|;
name|nargs
operator|=
name|chewname
argument_list|(
name|new
operator|->
name|name
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"\n\t"
argument_list|)
expr_stmt|;
name|chewbits
argument_list|(
name|new
operator|->
name|bits
argument_list|,
operator|&
name|length
argument_list|)
expr_stmt|;
name|length
operator|/=
literal|2
expr_stmt|;
if|if
condition|(
name|length
operator|&
literal|1
condition|)
name|abort
argument_list|()
expr_stmt|;
name|printf
argument_list|(
literal|",%d,%d,%d"
argument_list|,
name|nargs
argument_list|,
name|length
argument_list|,
name|idx
argument_list|)
expr_stmt|;
name|idx
operator|++
expr_stmt|;
name|oldname
operator|=
name|new
operator|->
name|name
expr_stmt|;
name|printf
argument_list|(
literal|"},\n"
argument_list|)
expr_stmt|;
name|new
operator|++
expr_stmt|;
block|}
name|printf
argument_list|(
literal|"\n/* end marker */\n"
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"{\n#ifdef NICENAMES\nNULL,0,0,\n0,\n#endif\n"
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"NULL,0,0,{0,0,0,0},{0,0,0,0,0,0,0,0,0,0},0,0,0}\n};\n"
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"#endif\n"
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
name|int
name|main
parameter_list|(
name|ac
parameter_list|,
name|av
parameter_list|)
name|int
name|ac
decl_stmt|;
name|char
modifier|*
modifier|*
name|av
decl_stmt|;
block|{
name|struct
name|op
modifier|*
name|p
init|=
name|opt
decl_stmt|;
if|if
condition|(
name|ac
operator|==
literal|2
operator|&&
name|strcmp
argument_list|(
name|av
index|[
literal|1
index|]
argument_list|,
literal|"-t"
argument_list|)
operator|==
literal|0
condition|)
block|{
name|internal
argument_list|()
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|ac
operator|==
literal|2
operator|&&
name|strcmp
argument_list|(
name|av
index|[
literal|1
index|]
argument_list|,
literal|"-h"
argument_list|)
operator|==
literal|0
condition|)
block|{
while|while
condition|(
name|p
operator|->
name|name
condition|)
block|{
name|printf
argument_list|(
literal|"%-25s\t%s\n"
argument_list|,
name|p
operator|->
name|name
argument_list|,
name|p
operator|->
name|bits
argument_list|)
expr_stmt|;
name|p
operator|++
expr_stmt|;
block|}
block|}
elseif|else
if|if
condition|(
name|ac
operator|==
literal|2
operator|&&
name|strcmp
argument_list|(
name|av
index|[
literal|1
index|]
argument_list|,
literal|"-a"
argument_list|)
operator|==
literal|0
condition|)
block|{
name|gas
argument_list|()
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|ac
operator|==
literal|2
operator|&&
name|strcmp
argument_list|(
name|av
index|[
literal|1
index|]
argument_list|,
literal|"-d"
argument_list|)
operator|==
literal|0
condition|)
block|{
comment|/*dis();*/
block|}
else|else
block|{
name|printf
argument_list|(
literal|"Usage: %s -t\n"
argument_list|,
name|av
index|[
literal|0
index|]
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"-t : generate new z8.c internal table\n"
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"-a : generate new table for gas\n"
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"-d : generate new table for disassemble\n"
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"-h : generate new table for humans\n"
argument_list|)
expr_stmt|;
block|}
return|return
literal|0
return|;
block|}
end_function

end_unit

