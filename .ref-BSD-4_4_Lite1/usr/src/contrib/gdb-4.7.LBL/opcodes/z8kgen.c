begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* This file is part of GNU Binutils.  This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version.  This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with this program; if not, write to the Free Software Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.  */
end_comment

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_define
define|#
directive|define
name|BYTE_INFO_LEN
value|10
end_define

begin_comment
comment|/*#include "z8opcode.h"*/
end_comment

begin_struct
struct|struct
name|op
block|{
name|char
modifier|*
name|bits
decl_stmt|;
name|char
modifier|*
name|name
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
literal|"1011 0101 ssss dddd"
block|,
literal|"adc rd,rs"
block|,
literal|"1011 0100 ssss dddd"
block|,
literal|"adcb rbd,rbs"
block|,
literal|"0000 0001 ssN0 dddd"
block|,
literal|"add rd,@rs"
block|,
literal|"0100 0001 0000 dddd address"
block|,
literal|"add rd,address"
block|,
literal|"0100 0001 ssN0 dddd address"
block|,
literal|"add rd,address(rs)"
block|,
literal|"0000 0001 0000 dddd imm16"
block|,
literal|"add rd,imm16"
block|,
literal|"1000 0001 ssss dddd"
block|,
literal|"add rd,rs"
block|,
literal|"0000 0000 ssN0 dddd"
block|,
literal|"addb rbd,@rs"
block|,
literal|"0100 0000 0000 dddd address"
block|,
literal|"addb rbd,address"
block|,
literal|"0100 0000 ssN0 dddd address"
block|,
literal|"addb rbd,address(rs)"
block|,
literal|"0000 0000 0000 dddd imm8 imm8"
block|,
literal|"addb rbd,imm8"
block|,
literal|"1000 0000 ssss dddd"
block|,
literal|"addb rbd,rbs"
block|,
literal|"0001 0110 ssN0 dddd"
block|,
literal|"addl rrd,@rs"
block|,
literal|"0101 0110 0000 dddd address"
block|,
literal|"addl rrd,address"
block|,
literal|"0101 0110 ssN0 dddd address"
block|,
literal|"addl rrd,address(rs)"
block|,
literal|"0001 0110 0000 dddd imm32"
block|,
literal|"addl rrd,imm32"
block|,
literal|"1001 0110 ssss dddd"
block|,
literal|"addl rrd,rrs"
block|,
literal|"0000 0111 ssN0 dddd"
block|,
literal|"and rd,@rs"
block|,
literal|"0100 0111 0000 dddd address"
block|,
literal|"and rd,address"
block|,
literal|"0100 0111 ssN0 dddd address"
block|,
literal|"and rd,address(rs)"
block|,
literal|"0000 0111 0000 dddd imm16"
block|,
literal|"and rd,imm16"
block|,
literal|"1000 0111 ssss dddd"
block|,
literal|"and rd,rs"
block|,
literal|"0000 0110 ssN0 dddd"
block|,
literal|"andb rbd,@rs"
block|,
literal|"0100 0110 0000 dddd address"
block|,
literal|"andb rbd,address"
block|,
literal|"0100 0110 ssN0 dddd address"
block|,
literal|"andb rbd,address(rs)"
block|,
literal|"0000 0110 0000 dddd imm8 imm8"
block|,
literal|"andb rbd,imm8"
block|,
literal|"1000 0110 ssss dddd"
block|,
literal|"andb rbd,rbs"
block|,
literal|"0010 0111 ddN0 imm4"
block|,
literal|"bit @rd,imm4"
block|,
literal|"0110 0111 ddN0 imm4 address"
block|,
literal|"bit address(rd),imm4"
block|,
literal|"0110 0111 0000 imm4 address"
block|,
literal|"bit address,imm4"
block|,
literal|"1010 0111 dddd imm4"
block|,
literal|"bit rd,imm4"
block|,
literal|"0010 0111 0000 ssss 0000 dddd 0000 0000"
block|,
literal|"bit rd,rs"
block|,
literal|"0010 0110 ddN0 imm4"
block|,
literal|"bitb @rd,imm4"
block|,
literal|"0110 0110 ddN0 imm4 address"
block|,
literal|"bitb address(rd),imm4"
block|,
literal|"0110 0110 0000 imm4 address"
block|,
literal|"bitb address,imm4"
block|,
literal|"1010 0110 dddd imm4"
block|,
literal|"bitb rbd,imm4"
block|,
literal|"0010 0110 0000 ssss 0000 dddd 0000 0000"
block|,
literal|"bitb rbd,rs"
block|,
literal|"0001 1111 ddN0 0000"
block|,
literal|"call @rd"
block|,
literal|"0101 1111 0000 0000 address"
block|,
literal|"call address"
block|,
literal|"0101 1111 ddN0 0000 address"
block|,
literal|"call address(rd)"
block|,
literal|"1101 disp12"
block|,
literal|"calr disp12"
block|,
literal|"0000 1101 ddN0 1000"
block|,
literal|"clr @rd"
block|,
literal|"0100 1101 0000 1000 address"
block|,
literal|"clr address"
block|,
literal|"0100 1101 ddN0 1000 address"
block|,
literal|"clr address(rd)"
block|,
literal|"1000 1101 dddd 1000"
block|,
literal|"clr rd"
block|,
literal|"0000 1100 ddN0 1000"
block|,
literal|"clrb @rd"
block|,
literal|"0100 1100 0000 1000 address"
block|,
literal|"clrb address"
block|,
literal|"0100 1100 ddN0 1000 address"
block|,
literal|"clrb address(rd)"
block|,
literal|"1000 1100 dddd 1000"
block|,
literal|"clrb rbd"
block|,
literal|"1011 1011 ssN0 1010 0000 rrrr ddN0 cccc"
block|,
literal|"cpsd @rd,@rs,rr,cc"
block|,
literal|"1011 1010 ssN0 1010 0000 rrrr ddN0 cccc"
block|,
literal|"cpsdb @rd,@rs,rr,cc"
block|,
literal|"1011 1011 ssN0 1110 0000 rrrr ddN0 cccc"
block|,
literal|"cpsdr @rd,@rs,rr,cc"
block|,
literal|"1011 1010 ssN0 1110 0000 rrrr ddN0 cccc"
block|,
literal|"cpsdrb @rd,@rs,rr,cc"
block|,
literal|"1011 1011 ssN0 0010 0000 rrrr ddN0 cccc"
block|,
literal|"cpsi @rd,@rs,rr,cc"
block|,
literal|"1011 1010 ssN0 0010 0000 rrrr ddN0 cccc"
block|,
literal|"cpsib @rd,@rs,rr,cc"
block|,
literal|"1011 1011 ssN0 0110 0000 rrrr ddN0 cccc"
block|,
literal|"cpsir @rd,@rs,rr,cc"
block|,
literal|"1011 1010 ssN0 0110 0000 rrrr ddN0 cccc"
block|,
literal|"cpsirb @rd,@rs,rr,cc"
block|,
literal|"0000 1101 ddN0 0000"
block|,
literal|"com @rd"
block|,
literal|"0100 1101 0000 0000 address"
block|,
literal|"com address"
block|,
literal|"0100 1101 ddN0 0000 address"
block|,
literal|"com address(rd)"
block|,
literal|"1000 1101 dddd 0000"
block|,
literal|"com rd"
block|,
literal|"0000 1100 ddN0 0000"
block|,
literal|"comb @rd"
block|,
literal|"0100 1100 0000 0000 address"
block|,
literal|"comb address"
block|,
literal|"0100 1100 ddN0 0000 address"
block|,
literal|"comb address(rd)"
block|,
literal|"1000 1100 dddd 0000"
block|,
literal|"comb rbd"
block|,
literal|"1000 1101 imm4 0101"
block|,
literal|"comflg flags"
block|,
literal|"0000 1101 ddN0 0001 imm16"
block|,
literal|"cp @rd,imm16"
block|,
literal|"0100 1101 ddN0 0001 address imm16"
block|,
literal|"cp address(rd),imm16"
block|,
literal|"0100 1101 0000 0001 address imm16"
block|,
literal|"cp address,imm16"
block|,
literal|"0000 1011 ssN0 dddd"
block|,
literal|"cp rd,@rs"
block|,
literal|"0100 1011 0000 dddd address"
block|,
literal|"cp rd,address"
block|,
literal|"0100 1011 ssN0 dddd address"
block|,
literal|"cp rd,address(rs)"
block|,
literal|"0000 1011 0000 dddd imm16"
block|,
literal|"cp rd,imm16"
block|,
literal|"1000 1011 ssss dddd"
block|,
literal|"cp rd,rs"
block|,
literal|"0000 1100 ddN0 0001 imm8 imm8"
block|,
literal|"cpb @rd,imm8"
block|,
literal|"0100 1100 ddN0 0001 address imm8 imm8"
block|,
literal|"cpb address(rd),imm8"
block|,
literal|"0100 1100 0000 0001 address imm8 imm8"
block|,
literal|"cpb address,imm8"
block|,
literal|"0000 1010 ssN0 dddd"
block|,
literal|"cpb rbd,@rs"
block|,
literal|"0100 1010 0000 dddd address"
block|,
literal|"cpb rbd,address"
block|,
literal|"0100 1010 ssN0 dddd address"
block|,
literal|"cpb rbd,address(rs)"
block|,
literal|"0000 1010 0000 dddd imm8 imm8"
block|,
literal|"cpb rbd,imm8"
block|,
literal|"1000 1010 ssss dddd"
block|,
literal|"cpb rbd,rbs"
block|,
literal|"1011 1011 ssN0 1000 0000 rrrr dddd cccc"
block|,
literal|"cpd rd,@rs,rr,cc"
block|,
literal|"1011 1010 ssN0 1000 0000 rrrr dddd cccc"
block|,
literal|"cpdb rbd,@rs,rr,cc"
block|,
literal|"1011 1011 ssN0 1100 0000 rrrr dddd cccc"
block|,
literal|"cpdr rd,@rs,rr,cc"
block|,
literal|"1011 1010 ssN0 1100 0000 rrrr dddd cccc"
block|,
literal|"cpdrb rbd,@rs,rr,cc"
block|,
literal|"1011 1011 ssN0 0000 0000 rrrr dddd cccc"
block|,
literal|"cpi rbd,@rs,rr,cc"
block|,
literal|"1011 1010 ssN0 0000 0000 rrrr dddd cccc"
block|,
literal|"cpib rd,@rs,rr,cc"
block|,
literal|"1011 1011 ssN0 0100 0000 rrrr dddd cccc"
block|,
literal|"cpir rbd,@rs,rr,cc"
block|,
literal|"1011 1010 ssN0 0100 0000 rrrr dddd cccc"
block|,
literal|"cpirb rd,@rs,rr,cc"
block|,
literal|"0001 0000 ssN0 dddd"
block|,
literal|"cpl rrd,@rs"
block|,
literal|"0101 0000 0000 dddd address"
block|,
literal|"cpl rrd,address"
block|,
literal|"0101 0000 ssN0 dddd address"
block|,
literal|"cpl rrd,address(rs)"
block|,
literal|"0001 0000 0000 dddd imm32"
block|,
literal|"cpl rrd,imm32"
block|,
literal|"1001 0000 ssss dddd"
block|,
literal|"cpl rrd,rrs"
block|,
literal|"1011 0000 dddd 0000"
block|,
literal|"dab rbd"
block|,
literal|"1111 dddd 1disp7"
block|,
literal|"dbjnz rbd,disp7"
block|,
literal|"0010 1011 ddN0 imm4"
block|,
literal|"dec @rd,imm4"
block|,
literal|"0110 1011 ddN0 imm4 address"
block|,
literal|"dec address(rd),imm4"
block|,
literal|"0110 1011 0000 imm4 address"
block|,
literal|"dec address,imm4"
block|,
literal|"1010 1011 dddd imm4"
block|,
literal|"dec rd,imm4"
block|,
literal|"0010 1010 ddN0 imm4"
block|,
literal|"decb @rd,imm4"
block|,
literal|"0110 1010 ddN0 imm4 address"
block|,
literal|"decb address(rd),imm4"
block|,
literal|"0110 1010 0000 imm4 address"
block|,
literal|"decb address,imm4"
block|,
literal|"1010 1010 dddd imm4"
block|,
literal|"decb rbd,imm4"
block|,
literal|"0111 1100 0000 00ii"
block|,
literal|"di i2"
block|,
literal|"0001 1011 ssN0 dddd"
block|,
literal|"div rrd,@rs"
block|,
literal|"0101 1011 0000 dddd address"
block|,
literal|"div rrd,address"
block|,
literal|"0101 1011 ssN0 dddd address"
block|,
literal|"div rrd,address(rs)"
block|,
literal|"0001 1011 0000 dddd imm16"
block|,
literal|"div rrd,imm16"
block|,
literal|"1001 1011 ssss dddd"
block|,
literal|"div rrd,rs"
block|,
literal|"0001 1010 ssN0 dddd"
block|,
literal|"divl rqd,@rs"
block|,
literal|"0101 1010 0000 dddd address"
block|,
literal|"divl rqd,address"
block|,
literal|"0101 1010 ssN0 dddd address"
block|,
literal|"divl rqd,address(rs)"
block|,
literal|"0001 1010 0000 dddd imm32"
block|,
literal|"divl rqd,imm32"
block|,
literal|"1001 1010 ssss dddd"
block|,
literal|"divl rqd,rrs"
block|,
literal|"1111 dddd 0disp7"
block|,
literal|"djnz rd,disp7"
block|,
literal|"0111 1100 0000 01ii"
block|,
literal|"ei i2"
block|,
literal|"1010 1101 ssss dddd"
block|,
literal|"ex rbd,rbs"
block|,
literal|"0010 1101 ssN0 dddd"
block|,
literal|"ex rd,@rs"
block|,
literal|"0110 1101 0000 dddd address"
block|,
literal|"ex rd,address"
block|,
literal|"0110 1101 ssN0 dddd address"
block|,
literal|"ex rd,address(rs)"
block|,
literal|"0010 1100 ssN0 dddd"
block|,
literal|"exb rbd,@rs"
block|,
literal|"0110 1100 0000 dddd address"
block|,
literal|"exb rbd,address"
block|,
literal|"0110 1100 ssN0 dddd address"
block|,
literal|"exb rbd,address(rs)"
block|,
literal|"1010 1100 ssss dddd"
block|,
literal|"exb rbd,rbs"
block|,
literal|"1011 0001 dddd 1010"
block|,
literal|"exts rrd"
block|,
literal|"1011 0001 dddd 0000"
block|,
literal|"extsb rd"
block|,
literal|"1011 0001 dddd 0111"
block|,
literal|"extsl rqd"
block|,
literal|"0111 1010 0000 0000"
block|,
literal|"halt"
block|,
literal|"0011 1101 ssN0 dddd"
block|,
literal|"in rd,@rs"
block|,
literal|"0011 1101 dddd 0100 imm16"
block|,
literal|"in rd,imm16"
block|,
literal|"0011 1100 ssN0 dddd"
block|,
literal|"inb rbd,@rs"
block|,
literal|"0011 1100 dddd 0100 imm16"
block|,
literal|"inb rbd,imm16"
block|,
literal|"0010 1001 ddN0 imm4"
block|,
literal|"inc @rd,imm4"
block|,
literal|"0110 1001 ddN0 imm4 address"
block|,
literal|"inc address(rd),imm4"
block|,
literal|"0110 1001 0000 imm4 address"
block|,
literal|"inc address,imm4"
block|,
literal|"1010 1001 dddd imm4"
block|,
literal|"inc rd,imm4"
block|,
literal|"0010 1000 ddN0 imm4"
block|,
literal|"incb @rd,imm4"
block|,
literal|"0110 1000 ddN0 imm4 address"
block|,
literal|"incb address(rd),imm4"
block|,
literal|"0110 1000 0000 imm4 address"
block|,
literal|"incb address,imm4"
block|,
literal|"1010 1000 dddd imm4"
block|,
literal|"incb rbd,imm4"
block|,
literal|"0011 1011 ssN0 1000 0000 aaaa ddN0 1000"
block|,
literal|"ind @rd,@rs,ra"
block|,
literal|"0011 1010 ssN0 1000 0000 aaaa ddN0 1000"
block|,
literal|"indb @rd,@rs,rba"
block|,
literal|"0011 1100 ssN0 0000 0000 aaaa ddN0 1000"
block|,
literal|"inib @rd,@rs,ra"
block|,
literal|"0011 1100 ssN0 0000 0000 aaaa ddN0 0000"
block|,
literal|"inibr @rd,@rs,ra"
block|,
literal|"0111 1011 0000 0000"
block|,
literal|"iret"
block|,
literal|"0001 1110 ddN0 cccc"
block|,
literal|"jp cc,@rd"
block|,
literal|"0101 1110 0000 cccc address"
block|,
literal|"jp cc,address"
block|,
literal|"0101 1110 ddN0 cccc address"
block|,
literal|"jp cc,address(rd)"
block|,
literal|"1110 cccc disp8"
block|,
literal|"jr cc,disp8"
block|,
literal|"0000 1101 ddN0 0101 imm16"
block|,
literal|"ld @rd,imm16"
block|,
literal|"0010 1111 ddN0 ssss"
block|,
literal|"ld @rd,rs"
block|,
literal|"0100 1101 ddN0 0101 address imm16"
block|,
literal|"ld address(rd),imm16"
block|,
literal|"0110 1111 ddN0 ssss address"
block|,
literal|"ld address(rd),rs"
block|,
literal|"0100 1101 0000 0101 address imm16"
block|,
literal|"ld address,imm16"
block|,
literal|"0110 1111 0000 ssss address"
block|,
literal|"ld address,rs"
block|,
literal|"0011 0011 ddN0 ssss disp16"
block|,
literal|"ld rd(disp16),rs"
block|,
literal|"0111 0011 ddN0 ssss 0000 xxxx 0000 0000"
block|,
literal|"ld rd(rx),rs"
block|,
literal|"0010 0001 ssN0 dddd"
block|,
literal|"ld rd,@rs"
block|,
literal|"0110 0001 0000 dddd address"
block|,
literal|"ld rd,address"
block|,
literal|"0110 0001 ssN0 dddd address"
block|,
literal|"ld rd,address(rs)"
block|,
literal|"0010 0001 0000 dddd imm16"
block|,
literal|"ld rd,imm16"
block|,
literal|"1010 0001 ssss dddd"
block|,
literal|"ld rd,rs"
block|,
literal|"0011 0001 ssN0 dddd disp16"
block|,
literal|"ld rd,rs(disp16)"
block|,
literal|"0111 0001 ssN0 dddd 0000 xxxx 0000 0000"
block|,
literal|"ld rd,rs(rx)"
block|,
literal|"0111 0110 0000 dddd address"
block|,
literal|"lda rd,address"
block|,
literal|"0111 0110 ssN0 dddd address"
block|,
literal|"lda rd,address(rs)"
block|,
literal|"0011 0100 ssN0 dddd disp16"
block|,
literal|"lda rd,rs(disp16)"
block|,
literal|"0111 0100 ssN0 dddd 0000 xxxx 0000 0000"
block|,
literal|"lda rd,rs(rx)"
block|,
literal|"0011 0100 0000 dddd disp16"
block|,
literal|"ldar rd,disp16"
block|,
literal|"0000 1100 ddN0 0101 imm8 imm8"
block|,
literal|"ldb @rd,imm8"
block|,
literal|"0010 1110 ddN0 ssss"
block|,
literal|"ldb @rd,rbs"
block|,
literal|"0100 1100 ddN0 0101 address imm8 imm8"
block|,
literal|"ldb address(rd),imm8"
block|,
literal|"0100 1110 ddN0 ssss address"
block|,
literal|"ldb address(rd),rbs"
block|,
literal|"0100 1100 0000 0101 address imm8 imm8"
block|,
literal|"ldb address,imm8"
block|,
literal|"0110 1110 0000 ssss address"
block|,
literal|"ldb address,rbs"
block|,
literal|"0010 0000 ssN0 dddd"
block|,
literal|"ldb rbd,@rs"
block|,
literal|"0110 0000 0000 dddd address"
block|,
literal|"ldb rbd,address"
block|,
literal|"0110 0000 ssN0 dddd address"
block|,
literal|"ldb rbd,address(rs)"
block|,
literal|"1100 dddd imm8"
block|,
literal|"ldb rbd,imm8"
block|,
literal|"0010 0000 0000 dddd imm8 imm8"
block|,
literal|"ldb rbd,imm8"
block|,
literal|"1010 0000 ssss dddd"
block|,
literal|"ldb rbd,rbs"
block|,
literal|"0011 0000 ssN0 dddd disp16"
block|,
literal|"ldb rbd,rs(disp16)"
block|,
literal|"0111 0000 ssN0 dddd 0000 xxxx 0000 0000"
block|,
literal|"ldb rbd,rs(rx)"
block|,
literal|"0011 0010 ddN0 ssss disp16"
block|,
literal|"ldb rd(disp16),rbs"
block|,
literal|"0111 0010 ddN0 ssss 0000 xxxx 0000 0000"
block|,
literal|"ldb rd(rx),rbs"
block|,
literal|"0111 1101 ssss 1ccc"
block|,
literal|"ldctl ctrl,rs"
block|,
literal|"0111 1101 dddd 0ccc"
block|,
literal|"ldctl rd,ctrl"
block|,
literal|"0001 1101 ddN0 ssss"
block|,
literal|"ldl @rd,rrs"
block|,
literal|"0101 1101 ddN0 ssss address"
block|,
literal|"ldl address(rd),rrs"
block|,
literal|"0101 1101 0000 ssss address"
block|,
literal|"ldl address,rrs"
block|,
literal|"0011 0111 ddN0 ssss disp16"
block|,
literal|"ldl rd(disp16),rrs"
block|,
literal|"0111 0111 ddN0 ssss 0000 xxxx 0000 0000"
block|,
literal|"ldl rd(rx),rrs"
block|,
literal|"0001 0100 ssN0 dddd"
block|,
literal|"ldl rrd,@rs"
block|,
literal|"0101 0100 0000 dddd address"
block|,
literal|"ldl rrd,address"
block|,
literal|"0101 0100 ssN0 dddd address"
block|,
literal|"ldl rrd,address(rs)"
block|,
literal|"0001 0100 0000 dddd imm32"
block|,
literal|"ldl rrd,imm32"
block|,
literal|"1001 0100 ssss dddd"
block|,
literal|"ldl rrd,rrs"
block|,
literal|"0011 0101 ssN0 dddd disp16"
block|,
literal|"ldl rrd,rs(disp16)"
block|,
literal|"0111 0101 ssN0 dddd 0000 xxxx 0000 0000"
block|,
literal|"ldl rrd,rs(rx)"
block|,
literal|"0001 1100 ddN0 1001 0000 ssss 0000 nminus1"
block|,
literal|"ldm @rd,rs,n"
block|,
literal|"0101 1100 ddN0 1001 0000 ssN0 0000 nminus1 address"
block|,
literal|"ldm address(rd),rs,n"
block|,
literal|"0101 1100 0000 1001 0000 ssss 0000 nminus1 address"
block|,
literal|"ldm address,rs,n"
block|,
literal|"0001 1100 ssN0 0001 0000 dddd 0000 nminus1"
block|,
literal|"ldm rd,@rs,n"
block|,
literal|"0101 1100 ssN0 0001 0000 dddd 0000 nminus1 address"
block|,
literal|"ldm rd,address(rs),n"
block|,
literal|"0101 1100 0000 0001 0000 dddd 0000 nminus1 address"
block|,
literal|"ldm rd,address,n"
block|,
literal|"0011 1001 ssN0 0000"
block|,
literal|"ldps @rs"
block|,
literal|"1011 1101 dddd imm4"
block|,
literal|"ldk rd,imm4"
block|,
literal|"1011 1010 ssN0 0001 0000 rrrr ddN0 0000"
block|,
literal|"ldirb @rd,@rs,rr"
block|,
literal|"1011 1011 ssN0 0001 0000 rrrr ddN0 0000"
block|,
literal|"ldir @rd,@rs,rr"
block|,
literal|"0111 1001 0000 0000 address"
block|,
literal|"ldps address"
block|,
literal|"0111 1001 ssN0 0000 address"
block|,
literal|"ldps address(rs)"
block|,
literal|"0011 0011 0000 ssss disp16"
block|,
literal|"ldr disp16,rs"
block|,
literal|"0011 0001 0000 dddd disp16"
block|,
literal|"ldr rd,disp16"
block|,
literal|"0011 0010 0000 ssss disp16"
block|,
literal|"ldrb disp16,rbs"
block|,
literal|"0011 0000 0000 dddd disp16"
block|,
literal|"ldrb rbd,disp16"
block|,
literal|"0011 0111 0000 ssss disp16"
block|,
literal|"ldrl disp16,rrs"
block|,
literal|"0011 0101 0000 dddd disp16"
block|,
literal|"ldrl rrd,disp16"
block|,
literal|"0111 1011 0000 1010"
block|,
literal|"mbit"
block|,
literal|"0111 1011 dddd 1101"
block|,
literal|"mreq rd"
block|,
literal|"0111 1011 0000 1001"
block|,
literal|"mres"
block|,
literal|"0111 1011 0000 1000"
block|,
literal|"mset"
block|,
literal|"0001 1001 ssN0 dddd"
block|,
literal|"mult rrd,@rs"
block|,
literal|"0101 1001 0000 dddd address"
block|,
literal|"mult rrd,address"
block|,
literal|"0101 1001 ssN0 dddd address"
block|,
literal|"mult rrd,address(rs)"
block|,
literal|"0001 1001 0000 dddd imm16"
block|,
literal|"mult rrd,imm16"
block|,
literal|"1001 1001 ssss dddd"
block|,
literal|"mult rrd,rs"
block|,
literal|"0001 1000 ssN0 dddd"
block|,
literal|"multl rqd,@rs"
block|,
literal|"0101 1000 0000 dddd address"
block|,
literal|"multl rqd,address"
block|,
literal|"0101 1000 ssN0 dddd address"
block|,
literal|"multl rqd,address(rs)"
block|,
literal|"0001 1000 0000 dddd imm32"
block|,
literal|"multl rqd,imm32"
block|,
literal|"1001 1000 ssss dddd"
block|,
literal|"multl rqd,rrs"
block|,
literal|"0000 1101 ddN0 0010"
block|,
literal|"neg @rd"
block|,
literal|"0100 1101 0000 0010 address"
block|,
literal|"neg address"
block|,
literal|"0100 1101 ddN0 0010 address"
block|,
literal|"neg address(rd)"
block|,
literal|"1000 1101 dddd 0010"
block|,
literal|"neg rd"
block|,
literal|"0000 1100 ddN0 0010"
block|,
literal|"negb @rd"
block|,
literal|"0100 1100 0000 0010 address"
block|,
literal|"negb address"
block|,
literal|"0100 1100 ddN0 0010 address"
block|,
literal|"negb address(rd)"
block|,
literal|"1000 1100 dddd 0010"
block|,
literal|"negb rbd"
block|,
literal|"1000 1101 0000 0111"
block|,
literal|"nop"
block|,
literal|"0000 0101 ssN0 dddd"
block|,
literal|"or rd,@rs"
block|,
literal|"0100 0101 0000 dddd address"
block|,
literal|"or rd,address"
block|,
literal|"0100 0101 ssN0 dddd address"
block|,
literal|"or rd,address(rs)"
block|,
literal|"0000 0101 0000 dddd imm16"
block|,
literal|"or rd,imm16"
block|,
literal|"1000 0101 ssss dddd"
block|,
literal|"or rd,rs"
block|,
literal|"0000 0100 ssN0 dddd"
block|,
literal|"orb rbd,@rs"
block|,
literal|"0100 0100 0000 dddd address"
block|,
literal|"orb rbd,address"
block|,
literal|"0100 0100 ssN0 dddd address"
block|,
literal|"orb rbd,address(rs)"
block|,
literal|"0000 0100 0000 dddd imm8 imm8"
block|,
literal|"orb rbd,imm8"
block|,
literal|"1000 0100 ssss dddd"
block|,
literal|"orb rbd,rbs"
block|,
literal|"0011 1111 ddN0 ssss"
block|,
literal|"out @rd,rs"
block|,
literal|"0011 1011 ssss 0110 imm16"
block|,
literal|"out imm16,rs"
block|,
literal|"0011 1110 ddN0 ssss"
block|,
literal|"outb @rd,rbs"
block|,
literal|"0011 1010 ssss 0110 imm16"
block|,
literal|"outb imm16,rbs"
block|,
literal|"0011 1011 ssN0 1010 0000 aaaa ddN0 1000"
block|,
literal|"outd @rd,@rs,ra"
block|,
literal|"0011 1010 ssN0 1010 0000 aaaa ddN0 1000"
block|,
literal|"outdb @rd,@rs,rba"
block|,
literal|"0011 1100 ssN0 0010 0000 aaaa ddN0 1000"
block|,
literal|"outib @rd,@rs,ra"
block|,
literal|"0011 1100 ssN0 0010 0000 aaaa ddN0 0000"
block|,
literal|"outibr @rd,@rs,ra"
block|,
literal|"0001 0111 ssN0 ddN0"
block|,
literal|"pop @rd,@rs"
block|,
literal|"0101 0111 ssN0 ddN0 address"
block|,
literal|"pop address(rd),@rs"
block|,
literal|"0101 0111 ssN0 0000 address"
block|,
literal|"pop address,@rs"
block|,
literal|"1001 0111 ssN0 dddd"
block|,
literal|"pop rd,@rs"
block|,
literal|"0001 0101 ssN0 ddN0"
block|,
literal|"popl @rd,@rs"
block|,
literal|"0101 0101 ssN0 ddN0 address"
block|,
literal|"popl address(rd),@rs"
block|,
literal|"0101 0101 ssN0 0000 address"
block|,
literal|"popl address,@rs"
block|,
literal|"1001 0101 ssN0 dddd"
block|,
literal|"popl rrd,@rs"
block|,
literal|"0001 0011 ddN0 ssN0"
block|,
literal|"push @rd,@rs"
block|,
literal|"0101 0011 ddN0 0000 address"
block|,
literal|"push @rd,address"
block|,
literal|"0000 1101 ddN0 1001 imm16"
block|,
literal|"push @rd,imm16"
block|,
literal|"1001 0011 ddN0 ssss"
block|,
literal|"push @rd,rs"
block|,
literal|"0101 0011 ddN0 ssN0 address"
block|,
literal|"push @rd,address(rs)"
block|,
literal|"0001 0001 ddN0 ssN0"
block|,
literal|"pushl @rd,@rs"
block|,
literal|"0101 0001 ddN0 0000 address"
block|,
literal|"push @rd,address"
block|,
literal|"1001 0001 ddN0 ssss"
block|,
literal|"pushl @rd,rrs"
block|,
literal|"0101 0001 ddN0 ssN0 address"
block|,
literal|"pushl @rd,address(rs)"
block|,
literal|"0010 0011 ddN0 imm4"
block|,
literal|"res @rd,imm4"
block|,
literal|"0110 0011 ddN0 imm4 address"
block|,
literal|"res address(rd),imm4"
block|,
literal|"0110 0011 0000 imm4 address"
block|,
literal|"res address,imm4"
block|,
literal|"1010 0011 dddd imm4"
block|,
literal|"res rd,imm4"
block|,
literal|"0010 0011 0000 ssss 0000 dddd 0000 0000"
block|,
literal|"res rd,rs"
block|,
literal|"0010 0010 ddN0 imm4"
block|,
literal|"resb @rd,imm4"
block|,
literal|"0110 0010 ddN0 imm4 address"
block|,
literal|"resb address(rd),imm4"
block|,
literal|"0110 0010 0000 imm4 address"
block|,
literal|"resb address,imm4"
block|,
literal|"1010 0010 dddd imm4"
block|,
literal|"resb rbd,imm4"
block|,
literal|"0010 0010 0000 ssss 0000 dddd 0000 0000"
block|,
literal|"resb rbd,rs"
block|,
literal|"1000 1101 imm4 0011"
block|,
literal|"resflg imm4"
block|,
literal|"1001 1110 0000 cccc"
block|,
literal|"ret cc"
block|,
literal|"1011 0011 dddd 0000"
block|,
literal|"rl rd,1"
block|,
literal|"1011 0011 dddd 0010"
block|,
literal|"rl rd,2"
block|,
literal|"1011 0010 dddd 0000"
block|,
literal|"rlb rbd,1"
block|,
literal|"1011 0010 dddd 0010"
block|,
literal|"rlb rbd,2"
block|,
literal|"1011 0011 dddd 1000"
block|,
literal|"rlc rd,1"
block|,
literal|"1011 0011 dddd 1010"
block|,
literal|"rlc rd,2"
block|,
literal|"1011 0010 dddd 1000"
block|,
literal|"rlcb rbd,1"
block|,
literal|"1011 0010 dddd 1010"
block|,
literal|"rlcb rbd,2"
block|,
literal|"1011 1110 aaaa bbbb"
block|,
literal|"rldb rbb,rba"
block|,
literal|"1011 0011 dddd 0100"
block|,
literal|"rr rd,1"
block|,
literal|"1011 0011 dddd 0110"
block|,
literal|"rr rd,2"
block|,
literal|"1011 0010 dddd 0100"
block|,
literal|"rrb rbd,1"
block|,
literal|"1011 0010 dddd 0110"
block|,
literal|"rrb rbd,2"
block|,
literal|"1011 0011 dddd 1100"
block|,
literal|"rrc rd,1"
block|,
literal|"1011 0011 dddd 1110"
block|,
literal|"rrc rd,2"
block|,
literal|"1011 0010 dddd 1100"
block|,
literal|"rrcb rbd,1"
block|,
literal|"1011 0010 dddd 1110"
block|,
literal|"rrcb rbd,2"
block|,
literal|"1011 1100 aaaa bbbb"
block|,
literal|"rrdb rbb,rba"
block|,
literal|"1011 0111 ssss dddd"
block|,
literal|"sbc rd,rs"
block|,
literal|"1011 0110 ssss dddd"
block|,
literal|"sbcb rbd,rbs"
block|,
literal|"1011 0011 dddd 1011 0000 ssss 0000 0000"
block|,
literal|"sda rd,rs"
block|,
literal|"1011 0010 dddd 1011 0000 ssss 0000 0000"
block|,
literal|"sdab rbd,rs"
block|,
literal|"1011 0011 dddd 1111 0000 ssss 0000 0000"
block|,
literal|"sdal rrd,rs"
block|,
literal|"1011 0011 dddd 0011 0000 ssss 0000 0000"
block|,
literal|"sdl rd,rs"
block|,
literal|"1011 0010 dddd 0011 0000 ssss 0000 0000"
block|,
literal|"sdlb rbd,rs"
block|,
literal|"1011 0011 dddd 0111 0000 ssss 0000 0000"
block|,
literal|"sdll rrd,rs"
block|,
literal|"0010 0101 ddN0 imm4"
block|,
literal|"set @rd,imm4"
block|,
literal|"0110 0101 ddN0 imm4 address"
block|,
literal|"set address(rd),imm4"
block|,
literal|"0110 0101 0000 imm4 address"
block|,
literal|"set address,imm4"
block|,
literal|"1010 0101 dddd imm4"
block|,
literal|"set rd,imm4"
block|,
literal|"0010 0101 0000 ssss 0000 dddd 0000 0000"
block|,
literal|"set rd,rs"
block|,
literal|"0010 0100 ddN0 imm4"
block|,
literal|"setb @rd,imm4"
block|,
literal|"0110 0100 ddN0 imm4 address"
block|,
literal|"setb address(rd),imm4"
block|,
literal|"0110 0100 0000 imm4 address"
block|,
literal|"setb address,imm4"
block|,
literal|"1010 0100 dddd imm4"
block|,
literal|"setb rbd,imm4"
block|,
literal|"0010 0100 0000 ssss 0000 dddd 0000 0000"
block|,
literal|"setb rbd,rs"
block|,
literal|"1000 1101 imm4 0001"
block|,
literal|"setflg imm4"
block|,
literal|"0011 1100 dddd 0101 imm16"
block|,
literal|"sinb rbd,imm16"
block|,
literal|"0011 1101 dddd 0101 imm16"
block|,
literal|"sinb rd,imm16"
block|,
literal|"0011 1011 ssN0 1000 0001 aaaa ddN0 1000"
block|,
literal|"sind @rd,@rs,ra"
block|,
literal|"0011 1010 ssN0 1000 0001 aaaa ddN0 1000"
block|,
literal|"sindb @rd,@rs,rba"
block|,
literal|"0011 1100 ssN0 0001 0000 aaaa ddN0 1000"
block|,
literal|"sinib @rd,@rs,ra"
block|,
literal|"0011 1100 ssN0 0001 0000 aaaa ddN0 0000"
block|,
literal|"sinibr @rd,@rs,ra"
block|,
literal|"1011 0011 dddd 1001 imm16"
block|,
literal|"sla rd,imm16"
block|,
literal|"1011 0010 dddd 1001 imm16"
block|,
literal|"slab rbd,imm16"
block|,
literal|"1011 0011 dddd 1101 imm16"
block|,
literal|"slal rrd,imm16"
block|,
literal|"1011 0011 dddd 0001 imm16"
block|,
literal|"sll rd,imm16"
block|,
literal|"1011 0010 dddd 0001 imm16"
block|,
literal|"sllb rbd,imm16"
block|,
literal|"1011 0011 dddd 0101 imm16"
block|,
literal|"slll rrd,imm16"
block|,
literal|"0011 1011 ssss 0111 imm16"
block|,
literal|"sout imm16,rs"
block|,
literal|"0011 1010 ssss 0111 imm16"
block|,
literal|"soutb imm16,rbs"
block|,
literal|"0011 1011 ssN0 1011 0000 aaaa ddN0 1000"
block|,
literal|"soutd @rd,@rs,ra"
block|,
literal|"0011 1010 ssN0 1011 0000 aaaa ddN0 1000"
block|,
literal|"soutdb @rd,@rs,rba"
block|,
literal|"0011 1100 ssN0 0011 0000 aaaa ddN0 1000"
block|,
literal|"soutib @rd,@rs,ra"
block|,
literal|"0011 1100 ssN0 0011 0000 aaaa ddN0 0000"
block|,
literal|"soutibr @rd,@rs,ra"
block|,
literal|"1011 0011 dddd 1001 nim16"
block|,
literal|"sra rd,imm16"
block|,
literal|"1011 0010 dddd 1001 nim16"
block|,
literal|"srab rbd,imm16"
block|,
literal|"1011 0011 dddd 1101 nim16"
block|,
literal|"sral rrd,imm16"
block|,
literal|"1011 0011 dddd 0001 nim16"
block|,
literal|"srl rd,imm16"
block|,
literal|"1011 0010 dddd 0001 nim16"
block|,
literal|"srlb rbd,imm16"
block|,
literal|"1011 0011 dddd 0101 nim16"
block|,
literal|"srll rrd,imm16"
block|,
literal|"0000 0011 ssN0 dddd"
block|,
literal|"sub rd,@rs"
block|,
literal|"0100 0011 0000 dddd address"
block|,
literal|"sub rd,address"
block|,
literal|"0100 0011 ssN0 dddd address"
block|,
literal|"sub rd,address(rs)"
block|,
literal|"0000 0010 0000 dddd imm16"
block|,
literal|"sub rd,imm16"
block|,
literal|"1000 0011 ssss dddd"
block|,
literal|"sub rd,rs"
block|,
literal|"0000 0010 ssN0 dddd"
block|,
literal|"subb rbd,@rs"
block|,
literal|"0100 0010 0000 dddd address"
block|,
literal|"subb rbd,address"
block|,
literal|"0100 0010 ssN0 dddd address"
block|,
literal|"subb rbd,address(rs)"
block|,
literal|"0000 0010 0000 dddd imm8 imm8"
block|,
literal|"subb rbd,imm8"
block|,
literal|"1000 0010 ssss dddd"
block|,
literal|"subb rbd,rbs"
block|,
literal|"0001 0010 ssN0 dddd"
block|,
literal|"subl rrd,@rs"
block|,
literal|"0101 0010 0000 dddd address"
block|,
literal|"subl rrd,address"
block|,
literal|"0101 0010 ssN0 dddd address"
block|,
literal|"subl rrd,address(rs)"
block|,
literal|"0001 0010 0000 dddd imm32"
block|,
literal|"subl rrd,imm32"
block|,
literal|"1001 0010 ssss dddd"
block|,
literal|"subl rrd,rrs"
block|,
literal|"1010 1111 dddd cccc"
block|,
literal|"tcc cc,rd"
block|,
literal|"1010 1110 dddd cccc"
block|,
literal|"tccb cc,rbd"
block|,
literal|"0000 1101 ddN0 0100"
block|,
literal|"test @rd"
block|,
literal|"0100 1101 0000 0100 address"
block|,
literal|"test address"
block|,
literal|"0100 1101 ddN0 0100 address"
block|,
literal|"test address(rd)"
block|,
literal|"1000 1101 dddd 0100"
block|,
literal|"test rd"
block|,
literal|"0000 1100 ddN0 0100"
block|,
literal|"testb @rd"
block|,
literal|"0100 1100 0000 0100 address"
block|,
literal|"testb address"
block|,
literal|"0100 1100 ddN0 0100 address"
block|,
literal|"testb address(rd)"
block|,
literal|"1000 1100 dddd 0100"
block|,
literal|"testb rbd"
block|,
literal|"0001 1100 ddN0 1000"
block|,
literal|"testl @rd"
block|,
literal|"0101 1100 0000 1000 address"
block|,
literal|"testl address"
block|,
literal|"1001 1100 dddd 1000"
block|,
literal|"testl rrd"
block|,
literal|"1011 1000 ddN0 1000 0000 aaaa ssN0 0000"
block|,
literal|"trdb @rd,@rs,rba"
block|,
literal|"1011 1000 ddN0 1100 0000 aaaa ssN0 0000"
block|,
literal|"trdrb @rd,@rs,rba"
block|,
literal|"1011 1000 ddN0 0000 0000 rrrr ssN0 0000"
block|,
literal|"trib @rd,@rs,rbr"
block|,
literal|"1011 1000 ddN0 0100 0000 rrrr ssN0 0000"
block|,
literal|"trirb @rd,@rs,rbr"
block|,
literal|"1011 1000 aaN0 1110 0000 rrrr bbN0 1110"
block|,
literal|"trtdrb @ra,@rb,rbr"
block|,
literal|"1011 1000 aaN0 0010 0000 rrrr bbN0 0000"
block|,
literal|"trtib @ra,@rb,rr"
block|,
literal|"1011 1000 aaN0 0110 0000 rrrr bbN0 1110"
block|,
literal|"trtirb @ra,@rb,rbr"
block|,
literal|"1011 1000 aaN0 1010 0000 rrrr bbN0 0000"
block|,
literal|"trtrb @ra,@rb,rbr"
block|,
literal|"0000 1101 ddN0 0110"
block|,
literal|"tset @rd"
block|,
literal|"0100 1101 0000 0110 address"
block|,
literal|"tset address"
block|,
literal|"0100 1101 ddN0 0110 address"
block|,
literal|"tset address(rd)"
block|,
literal|"1000 1101 dddd 0110"
block|,
literal|"tset rd"
block|,
literal|"0000 1100 ddN0 0110"
block|,
literal|"tsetb @rd"
block|,
literal|"0100 1100 0000 0110 address"
block|,
literal|"tsetb address"
block|,
literal|"0100 1100 ddN0 0110 address"
block|,
literal|"tsetb address(rd)"
block|,
literal|"1000 1100 dddd 0110"
block|,
literal|"tsetb rbd"
block|,
literal|"0000 1001 ssN0 dddd"
block|,
literal|"xor rd,@rs"
block|,
literal|"0100 1001 0000 dddd address"
block|,
literal|"xor rd,address"
block|,
literal|"0100 1001 ssN0 dddd address"
block|,
literal|"xor rd,address(rs)"
block|,
literal|"0000 1001 0000 dddd imm16"
block|,
literal|"xor rd,imm16"
block|,
literal|"1000 1001 ssss dddd"
block|,
literal|"xor rd,rs"
block|,
literal|"0000 1000 ssN0 dddd"
block|,
literal|"xorb rbd,@rs"
block|,
literal|"0100 1000 0000 dddd address"
block|,
literal|"xorb rbd,address"
block|,
literal|"0100 1000 ssN0 dddd address"
block|,
literal|"xorb rbd,address(rs)"
block|,
literal|"0000 1000 0000 dddd imm8 imm8"
block|,
literal|"xorb rbd,imm8"
block|,
literal|"1000 1000 ssss dddd"
block|,
literal|"xorb rbd,rbs"
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

begin_macro
name|func
argument_list|(
argument|a
argument_list|,
argument|b
argument_list|)
end_macro

begin_decl_stmt
name|struct
name|op
modifier|*
name|a
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|op
modifier|*
name|b
decl_stmt|;
end_decl_stmt

begin_block
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
end_block

begin_macro
name|func1
argument_list|(
argument|a
argument_list|,
argument|b
argument_list|)
end_macro

begin_decl_stmt
name|struct
name|op
modifier|*
name|a
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|op
modifier|*
name|b
decl_stmt|;
end_decl_stmt

begin_block
block|{
return|return
name|strcmp
argument_list|(
operator|(
name|a
operator|)
operator|->
name|bits
argument_list|,
operator|(
name|b
operator|)
operator|->
name|bits
argument_list|)
return|;
block|}
end_block

begin_comment
comment|/* opcode    literal  0000 nnnn insert nnn into stream  operand  0001 nnnn  insert operand reg nnn into stream */
end_comment

begin_typedef
typedef|typedef
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
empty_stmt|;
end_typedef

begin_decl_stmt
name|struct
name|tok_struct
name|args
index|[]
init|=
block|{
block|{
literal|"address(rs)"
block|,
literal|"CLASS_X+(ARG_RS)"
block|,}
block|,
block|{
literal|"address(rd)"
block|,
literal|"CLASS_X+(ARG_RD)"
block|,}
block|,
block|{
literal|"rs(disp16)"
block|,
literal|"CLASS_BA+(ARG_RS)"
block|,}
block|,
block|{
literal|"rd(disp16)"
block|,
literal|"CLASS_BA+(ARG_RD)"
block|,}
block|,
block|{
literal|"address"
block|,
literal|"CLASS_DA"
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
literal|"imm32"
block|,
literal|"CLASS_IMM+(ARG_IMM32)"
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
literal|"CLASS_BIT+10"
block|,
literal|1
block|,
literal|"1011"
block|,
literal|"CLASS_BIT+11"
block|,
literal|1
block|,
literal|"1100"
block|,
literal|"CLASS_BIT+12"
block|,
literal|1
block|,
literal|"1101"
block|,
literal|"CLASS_BIT+13"
block|,
literal|1
block|,
literal|"1110"
block|,
literal|"CLASS_BIT+14"
block|,
literal|1
block|,
literal|"1111"
block|,
literal|"CLASS_BIT+15"
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
literal|"address"
block|,
literal|"CLASS_ADDRESS"
block|,
literal|4
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
literal|"nim16"
block|,
literal|"CLASS_IMM+(ARG_NIM16)"
block|,
literal|4
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
name|i
decl_stmt|;
name|int
name|found
decl_stmt|;
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

begin_macro
name|doreg
argument_list|(
argument|x
argument_list|)
end_macro

begin_decl_stmt
name|char
modifier|*
name|x
decl_stmt|;
end_decl_stmt

begin_block
block|{
name|printf
argument_list|(
literal|"REGH %c "
argument_list|,
name|x
index|[
literal|0
index|]
argument_list|)
expr_stmt|;
block|}
end_block

begin_function
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
name|int
name|nbytes
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
literal|"\",{"
argument_list|)
expr_stmt|;
comment|/* Scan the operands and make entires for them -remember indirect things */
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

begin_macro
name|sub
argument_list|(
argument|x
argument_list|,
argument|c
argument_list|)
end_macro

begin_decl_stmt
name|char
modifier|*
name|x
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
name|c
decl_stmt|;
end_decl_stmt

begin_block
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
end_block

begin_macro
name|internal
argument_list|()
end_macro

begin_block
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
name|malloc
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
name|name
condition|)
block|{
comment|/* If there are any @rs, sub the ssss into a ssn0,  (rs), (ssn0)  */
name|int
name|loop
init|=
literal|1
decl_stmt|;
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
name|printf
argument_list|(
literal|"\"%s\",\"%s\",\n"
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
end_block

begin_macro
name|gas
argument_list|()
end_macro

begin_block
block|{
name|int
name|c
init|=
name|count
argument_list|()
decl_stmt|;
name|int
name|i
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
name|malloc
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
literal|"   /* THIS FILE IS AUTOMAGICALLY GENERATED, DON'T EDIT IT */\n"
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"#define ARG_MASK 0x0f\n"
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
literal|"#define ARG_NIM16 0x09\n"
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"#define ARG_IMM2 0x0a\n"
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
literal|"#define CLASS_MASK 0xfff0\n"
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
if|#
directive|if
literal|0
block|for (i = 0; toks[i].token; i++)  printf("#define %s\t0x%x\n",toks[i].token,i*16);
endif|#
directive|endif
name|printf
argument_list|(
literal|"typedef struct {\n"
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"char *name;\n"
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"unsigned short arg_info[4];\n"
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"unsigned short byte_info[%d];\n"
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
name|name
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
literal|"{"
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
name|fail
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
if|if
condition|(
name|strcmp
argument_list|(
name|oldname
argument_list|,
name|new
operator|->
name|name
argument_list|)
condition|)
block|{
name|idx
operator|++
expr_stmt|;
name|oldname
operator|=
name|new
operator|->
name|name
expr_stmt|;
block|}
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
literal|"0,0};\n"
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"#endif\n"
argument_list|)
expr_stmt|;
block|}
end_block

begin_function
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
block|}
end_function

begin_macro
name|fail
argument_list|()
end_macro

begin_block
block|{ }
end_block

end_unit

