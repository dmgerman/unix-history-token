begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Opcode table for the ARM.     Copyright 1994, 1995, 1996, 1997, 1998, 1999, 2000    Free Software Foundation, Inc.        This program is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2, or (at your option)    any later version.     This program is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.     You should have received a copy of the GNU General Public License    along with this program; if not, write to the Free Software    Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
end_comment

begin_struct
struct|struct
name|arm_opcode
block|{
name|unsigned
name|long
name|value
decl_stmt|,
name|mask
decl_stmt|;
comment|/* recognise instruction if (op&mask)==value */
name|char
modifier|*
name|assembler
decl_stmt|;
comment|/* how to disassemble this instruction */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|thumb_opcode
block|{
name|unsigned
name|short
name|value
decl_stmt|,
name|mask
decl_stmt|;
comment|/* recognise instruction if (op&mask)==value */
name|char
modifier|*
name|assembler
decl_stmt|;
comment|/* how to disassemble this instruction */
block|}
struct|;
end_struct

begin_comment
comment|/* format of the assembler string :        %%			%    %<bitfield>d		print the bitfield in decimal    %<bitfield>x		print the bitfield in hex    %<bitfield>X		print the bitfield as 1 hex digit without leading "0x"    %<bitfield>r		print as an ARM register    %<bitfield>f		print a floating point constant if>7 else a 			floating point register    %c			print condition code (always bits 28-31)    %P			print floating point precision in arithmetic insn    %Q			print floating point precision in ldf/stf insn    %R			print floating point rounding mode    %<bitnum>'c		print specified char iff bit is one    %<bitnum>`c		print specified char iff bit is zero    %<bitnum>?ab		print a if bit is one else print b    %p			print 'p' iff bits 12-15 are 15    %t			print 't' iff bit 21 set and bit 24 clear    %h                   print 'h' iff bit 5 set, else print 'b'    %o			print operand2 (immediate or register + shift)    %a			print address for ldr/str instruction    %s                   print address for ldr/str halfword/signextend instruction    %b			print branch destination    %B			print arm BLX(1) destination    %A			print address for ldc/stc/ldf/stf instruction    %m			print register mask for ldm/stm instruction    %C			print the PSR sub type.    %F			print the COUNT field of a LFM/SFM instruction. Thumb specific format options:    %D                   print Thumb register (bits 0..2 as high number if bit 7 set)    %S                   print Thumb register (bits 3..5 as high number if bit 6 set)    %<bitfield>I         print bitfield as a signed decimal    				(top bit of range being the sign bit)    %M                   print Thumb register mask    %N                   print Thumb register mask (with LR)    %O                   print Thumb register mask (with PC)    %T                   print Thumb condition code (always bits 8-11)    %<bitfield>B         print Thumb branch destination (signed displacement)    %<bitfield>W         print (bitfield * 4) as a decimal    %<bitfield>H         print (bitfield * 2) as a decimal    %<bitfield>a         print (bitfield * 4) as a pc-rel offset + decoded symbol */
end_comment

begin_comment
comment|/* Note: There is a partial ordering in this table - it must be searched from    the top to obtain a correct match. */
end_comment

begin_decl_stmt
specifier|static
name|struct
name|arm_opcode
name|arm_opcodes
index|[]
init|=
block|{
comment|/* ARM instructions.  */
block|{
literal|0xe1a00000
block|,
literal|0xffffffff
block|,
literal|"nop\t\t\t(mov r0,r0)"
block|}
block|,
block|{
literal|0x012FFF10
block|,
literal|0x0ffffff0
block|,
literal|"bx%c\t%0-3r"
block|}
block|,
block|{
literal|0x00000090
block|,
literal|0x0fe000f0
block|,
literal|"mul%c%20's\t%16-19r, %0-3r, %8-11r"
block|}
block|,
block|{
literal|0x00200090
block|,
literal|0x0fe000f0
block|,
literal|"mla%c%20's\t%16-19r, %0-3r, %8-11r, %12-15r"
block|}
block|,
block|{
literal|0x01000090
block|,
literal|0x0fb00ff0
block|,
literal|"swp%c%22'b\t%12-15r, %0-3r, [%16-19r]"
block|}
block|,
block|{
literal|0x00800090
block|,
literal|0x0fa000f0
block|,
literal|"%22?sumull%c%20's\t%12-15r, %16-19r, %0-3r, %8-11r"
block|}
block|,
block|{
literal|0x00a00090
block|,
literal|0x0fa000f0
block|,
literal|"%22?sumlal%c%20's\t%12-15r, %16-19r, %0-3r, %8-11r"
block|}
block|,
comment|/* XScale instructions.  */
block|{
literal|0x0e200010
block|,
literal|0x0fff0ff0
block|,
literal|"mia%c\tacc0, %0-3r, %12-15r"
block|}
block|,
block|{
literal|0x0e280010
block|,
literal|0x0fff0ff0
block|,
literal|"miaph%c\tacc0, %0-3r, %12-15r"
block|}
block|,
block|{
literal|0x0e2c0010
block|,
literal|0x0ffc0ff0
block|,
literal|"mia%17'T%17`B%16'T%16`B%c\tacc0, %0-3r, %12-15r"
block|}
block|,
block|{
literal|0x0c400000
block|,
literal|0x0ff00fff
block|,
literal|"mar%c\tacc0, %12-15r, %16-19r"
block|}
block|,
block|{
literal|0x0c500000
block|,
literal|0x0ff00fff
block|,
literal|"mra%c\t%12-15r, %16-19r, acc0"
block|}
block|,
block|{
literal|0xf450f000
block|,
literal|0xfc70f000
block|,
literal|"pld\t%a"
block|}
block|,
comment|/* V5 Instructions.  */
block|{
literal|0xe1200070
block|,
literal|0xfff000f0
block|,
literal|"bkpt\t0x%16-19X%12-15X%8-11X%0-3X"
block|}
block|,
block|{
literal|0xfa000000
block|,
literal|0xfe000000
block|,
literal|"blx\t%B"
block|}
block|,
block|{
literal|0x012fff30
block|,
literal|0x0ffffff0
block|,
literal|"blx%c\t%0-3r"
block|}
block|,
block|{
literal|0x016f0f10
block|,
literal|0x0fff0ff0
block|,
literal|"clz%c\t%12-15r, %0-3r"
block|}
block|,
block|{
literal|0xfc100000
block|,
literal|0xfe100000
block|,
literal|"ldc2%22'l\t%8-11d, cr%12-15d, %A"
block|}
block|,
block|{
literal|0xfc000000
block|,
literal|0xfe100000
block|,
literal|"stc2%22'l\t%8-11d, cr%12-15d, %A"
block|}
block|,
block|{
literal|0xfe000000
block|,
literal|0xff000010
block|,
literal|"cdp2\t%8-11d, %20-23d, cr%12-15d, cr%16-19d, cr%0-3d, {%5-7d}"
block|}
block|,
block|{
literal|0xfe000010
block|,
literal|0xff100010
block|,
literal|"mcr2\t%8-11d, %21-23d, %12-15r, cr%16-19d, cr%0-3d, {%5-7d}"
block|}
block|,
block|{
literal|0xfe100010
block|,
literal|0xff100010
block|,
literal|"mrc2\t%8-11d, %21-23d, %12-15r, cr%16-19d, cr%0-3d, {%5-7d}"
block|}
block|,
comment|/* V5E "El Segundo" Instructions.  */
block|{
literal|0x000000d0
block|,
literal|0x0e1000f0
block|,
literal|"ldr%cd\t%12-15r, %s"
block|}
block|,
block|{
literal|0x000000f0
block|,
literal|0x0e1000f0
block|,
literal|"str%cd\t%12-15r, %s"
block|}
block|,
block|{
literal|0x01000080
block|,
literal|0x0ff000f0
block|,
literal|"smlabb%c\t%16-19r, %0-3r, %8-11r, %12-15r"
block|}
block|,
block|{
literal|0x010000a0
block|,
literal|0x0ff000f0
block|,
literal|"smlatb%c\t%16-19r, %0-3r, %8-11r, %12-15r"
block|}
block|,
block|{
literal|0x010000c0
block|,
literal|0x0ff000f0
block|,
literal|"smlabt%c\t%16-19r, %0-3r, %8-11r, %12-15r"
block|}
block|,
block|{
literal|0x010000e0
block|,
literal|0x0ff000f0
block|,
literal|"smlatt%c\t%16-19r, %0-3r, %8-11r, %12-15r"
block|}
block|,
block|{
literal|0x01200080
block|,
literal|0x0ff000f0
block|,
literal|"smlawb%c\t%16-19r, %0-3r, %8-11r, %12-15r"
block|}
block|,
block|{
literal|0x012000c0
block|,
literal|0x0ff000f0
block|,
literal|"smlawt%c\t%16-19r, %0-3r, %8-11r, %12-15r"
block|}
block|,
block|{
literal|0x01400080
block|,
literal|0x0ff000f0
block|,
literal|"smlalbb%c\t%12-15r, %16-19r, %0-3r, %8-11r"
block|}
block|,
block|{
literal|0x014000a0
block|,
literal|0x0ff000f0
block|,
literal|"smlaltb%c\t%12-15r, %16-19r, %0-3r, %8-11r"
block|}
block|,
block|{
literal|0x014000c0
block|,
literal|0x0ff000f0
block|,
literal|"smlalbt%c\t%12-15r, %16-19r, %0-3r, %8-11r"
block|}
block|,
block|{
literal|0x014000e0
block|,
literal|0x0ff000f0
block|,
literal|"smlaltt%c\t%12-15r, %16-19r, %0-3r, %8-11r"
block|}
block|,
block|{
literal|0x01600080
block|,
literal|0x0ff0f0f0
block|,
literal|"smulbb%c\t%16-19r, %0-3r, %8-11r"
block|}
block|,
block|{
literal|0x016000a0
block|,
literal|0x0ff0f0f0
block|,
literal|"smultb%c\t%16-19r, %0-3r, %8-11r"
block|}
block|,
block|{
literal|0x016000c0
block|,
literal|0x0ff0f0f0
block|,
literal|"smulbt%c\t%16-19r, %0-3r, %8-11r"
block|}
block|,
block|{
literal|0x016000e0
block|,
literal|0x0ff0f0f0
block|,
literal|"smultt%c\t%16-19r, %0-3r, %8-11r"
block|}
block|,
block|{
literal|0x012000a0
block|,
literal|0x0ff0f0f0
block|,
literal|"smulwb%c\t%16-19r, %0-3r, %8-11r"
block|}
block|,
block|{
literal|0x012000e0
block|,
literal|0x0ff0f0f0
block|,
literal|"smulwt%c\t%16-19r, %0-3r, %8-11r"
block|}
block|,
block|{
literal|0x01000050
block|,
literal|0x0ff00ff0
block|,
literal|"qadd%c\t%12-15r, %0-3r, %16-19r"
block|}
block|,
block|{
literal|0x01400050
block|,
literal|0x0ff00ff0
block|,
literal|"qdadd%c\t%12-15r, %0-3r, %16-19r"
block|}
block|,
block|{
literal|0x01200050
block|,
literal|0x0ff00ff0
block|,
literal|"qsub%c\t%12-15r, %0-3r, %16-19r"
block|}
block|,
block|{
literal|0x01600050
block|,
literal|0x0ff00ff0
block|,
literal|"qdsub%c\t%12-15r, %0-3r, %16-19r"
block|}
block|,
block|{
literal|0x0c400000
block|,
literal|0x0ff00000
block|,
literal|"mcrr%c\t%8-11d, %4-7d, %12-15r, %16-19r, cr%0-3d"
block|}
block|,
block|{
literal|0x0c500000
block|,
literal|0x0ff00000
block|,
literal|"mrrc%c\t%8-11d, %4-7d, %12-15r, %16-19r, cr%0-3d"
block|}
block|,
comment|/* ARM Instructions.  */
block|{
literal|0x00000090
block|,
literal|0x0e100090
block|,
literal|"str%c%6's%h\t%12-15r, %s"
block|}
block|,
block|{
literal|0x00100090
block|,
literal|0x0e100090
block|,
literal|"ldr%c%6's%h\t%12-15r, %s"
block|}
block|,
block|{
literal|0x00000000
block|,
literal|0x0de00000
block|,
literal|"and%c%20's\t%12-15r, %16-19r, %o"
block|}
block|,
block|{
literal|0x00200000
block|,
literal|0x0de00000
block|,
literal|"eor%c%20's\t%12-15r, %16-19r, %o"
block|}
block|,
block|{
literal|0x00400000
block|,
literal|0x0de00000
block|,
literal|"sub%c%20's\t%12-15r, %16-19r, %o"
block|}
block|,
block|{
literal|0x00600000
block|,
literal|0x0de00000
block|,
literal|"rsb%c%20's\t%12-15r, %16-19r, %o"
block|}
block|,
block|{
literal|0x00800000
block|,
literal|0x0de00000
block|,
literal|"add%c%20's\t%12-15r, %16-19r, %o"
block|}
block|,
block|{
literal|0x00a00000
block|,
literal|0x0de00000
block|,
literal|"adc%c%20's\t%12-15r, %16-19r, %o"
block|}
block|,
block|{
literal|0x00c00000
block|,
literal|0x0de00000
block|,
literal|"sbc%c%20's\t%12-15r, %16-19r, %o"
block|}
block|,
block|{
literal|0x00e00000
block|,
literal|0x0de00000
block|,
literal|"rsc%c%20's\t%12-15r, %16-19r, %o"
block|}
block|,
block|{
literal|0x0120f000
block|,
literal|0x0db0f000
block|,
literal|"msr%c\t%22?SCPSR%C, %o"
block|}
block|,
block|{
literal|0x010f0000
block|,
literal|0x0fbf0fff
block|,
literal|"mrs%c\t%12-15r, %22?SCPSR"
block|}
block|,
block|{
literal|0x01000000
block|,
literal|0x0de00000
block|,
literal|"tst%c%p\t%16-19r, %o"
block|}
block|,
block|{
literal|0x01200000
block|,
literal|0x0de00000
block|,
literal|"teq%c%p\t%16-19r, %o"
block|}
block|,
block|{
literal|0x01400000
block|,
literal|0x0de00000
block|,
literal|"cmp%c%p\t%16-19r, %o"
block|}
block|,
block|{
literal|0x01600000
block|,
literal|0x0de00000
block|,
literal|"cmn%c%p\t%16-19r, %o"
block|}
block|,
block|{
literal|0x01800000
block|,
literal|0x0de00000
block|,
literal|"orr%c%20's\t%12-15r, %16-19r, %o"
block|}
block|,
block|{
literal|0x01a00000
block|,
literal|0x0de00000
block|,
literal|"mov%c%20's\t%12-15r, %o"
block|}
block|,
block|{
literal|0x01c00000
block|,
literal|0x0de00000
block|,
literal|"bic%c%20's\t%12-15r, %16-19r, %o"
block|}
block|,
block|{
literal|0x01e00000
block|,
literal|0x0de00000
block|,
literal|"mvn%c%20's\t%12-15r, %o"
block|}
block|,
block|{
literal|0x04000000
block|,
literal|0x0e100000
block|,
literal|"str%c%22'b%t\t%12-15r, %a"
block|}
block|,
block|{
literal|0x06000000
block|,
literal|0x0e100ff0
block|,
literal|"str%c%22'b%t\t%12-15r, %a"
block|}
block|,
block|{
literal|0x04000000
block|,
literal|0x0c100010
block|,
literal|"str%c%22'b%t\t%12-15r, %a"
block|}
block|,
block|{
literal|0x06000010
block|,
literal|0x0e000010
block|,
literal|"undefined"
block|}
block|,
block|{
literal|0x04100000
block|,
literal|0x0c100000
block|,
literal|"ldr%c%22'b%t\t%12-15r, %a"
block|}
block|,
block|{
literal|0x08000000
block|,
literal|0x0e100000
block|,
literal|"stm%c%23?id%24?ba\t%16-19r%21'!, %m%22'^"
block|}
block|,
block|{
literal|0x08100000
block|,
literal|0x0e100000
block|,
literal|"ldm%c%23?id%24?ba\t%16-19r%21'!, %m%22'^"
block|}
block|,
block|{
literal|0x0a000000
block|,
literal|0x0e000000
block|,
literal|"b%24'l%c\t%b"
block|}
block|,
block|{
literal|0x0f000000
block|,
literal|0x0f000000
block|,
literal|"swi%c\t%0-23x"
block|}
block|,
comment|/* Floating point coprocessor instructions */
block|{
literal|0x0e000100
block|,
literal|0x0ff08f10
block|,
literal|"adf%c%P%R\t%12-14f, %16-18f, %0-3f"
block|}
block|,
block|{
literal|0x0e100100
block|,
literal|0x0ff08f10
block|,
literal|"muf%c%P%R\t%12-14f, %16-18f, %0-3f"
block|}
block|,
block|{
literal|0x0e200100
block|,
literal|0x0ff08f10
block|,
literal|"suf%c%P%R\t%12-14f, %16-18f, %0-3f"
block|}
block|,
block|{
literal|0x0e300100
block|,
literal|0x0ff08f10
block|,
literal|"rsf%c%P%R\t%12-14f, %16-18f, %0-3f"
block|}
block|,
block|{
literal|0x0e400100
block|,
literal|0x0ff08f10
block|,
literal|"dvf%c%P%R\t%12-14f, %16-18f, %0-3f"
block|}
block|,
block|{
literal|0x0e500100
block|,
literal|0x0ff08f10
block|,
literal|"rdf%c%P%R\t%12-14f, %16-18f, %0-3f"
block|}
block|,
block|{
literal|0x0e600100
block|,
literal|0x0ff08f10
block|,
literal|"pow%c%P%R\t%12-14f, %16-18f, %0-3f"
block|}
block|,
block|{
literal|0x0e700100
block|,
literal|0x0ff08f10
block|,
literal|"rpw%c%P%R\t%12-14f, %16-18f, %0-3f"
block|}
block|,
block|{
literal|0x0e800100
block|,
literal|0x0ff08f10
block|,
literal|"rmf%c%P%R\t%12-14f, %16-18f, %0-3f"
block|}
block|,
block|{
literal|0x0e900100
block|,
literal|0x0ff08f10
block|,
literal|"fml%c%P%R\t%12-14f, %16-18f, %0-3f"
block|}
block|,
block|{
literal|0x0ea00100
block|,
literal|0x0ff08f10
block|,
literal|"fdv%c%P%R\t%12-14f, %16-18f, %0-3f"
block|}
block|,
block|{
literal|0x0eb00100
block|,
literal|0x0ff08f10
block|,
literal|"frd%c%P%R\t%12-14f, %16-18f, %0-3f"
block|}
block|,
block|{
literal|0x0ec00100
block|,
literal|0x0ff08f10
block|,
literal|"pol%c%P%R\t%12-14f, %16-18f, %0-3f"
block|}
block|,
block|{
literal|0x0e008100
block|,
literal|0x0ff08f10
block|,
literal|"mvf%c%P%R\t%12-14f, %0-3f"
block|}
block|,
block|{
literal|0x0e108100
block|,
literal|0x0ff08f10
block|,
literal|"mnf%c%P%R\t%12-14f, %0-3f"
block|}
block|,
block|{
literal|0x0e208100
block|,
literal|0x0ff08f10
block|,
literal|"abs%c%P%R\t%12-14f, %0-3f"
block|}
block|,
block|{
literal|0x0e308100
block|,
literal|0x0ff08f10
block|,
literal|"rnd%c%P%R\t%12-14f, %0-3f"
block|}
block|,
block|{
literal|0x0e408100
block|,
literal|0x0ff08f10
block|,
literal|"sqt%c%P%R\t%12-14f, %0-3f"
block|}
block|,
block|{
literal|0x0e508100
block|,
literal|0x0ff08f10
block|,
literal|"log%c%P%R\t%12-14f, %0-3f"
block|}
block|,
block|{
literal|0x0e608100
block|,
literal|0x0ff08f10
block|,
literal|"lgn%c%P%R\t%12-14f, %0-3f"
block|}
block|,
block|{
literal|0x0e708100
block|,
literal|0x0ff08f10
block|,
literal|"exp%c%P%R\t%12-14f, %0-3f"
block|}
block|,
block|{
literal|0x0e808100
block|,
literal|0x0ff08f10
block|,
literal|"sin%c%P%R\t%12-14f, %0-3f"
block|}
block|,
block|{
literal|0x0e908100
block|,
literal|0x0ff08f10
block|,
literal|"cos%c%P%R\t%12-14f, %0-3f"
block|}
block|,
block|{
literal|0x0ea08100
block|,
literal|0x0ff08f10
block|,
literal|"tan%c%P%R\t%12-14f, %0-3f"
block|}
block|,
block|{
literal|0x0eb08100
block|,
literal|0x0ff08f10
block|,
literal|"asn%c%P%R\t%12-14f, %0-3f"
block|}
block|,
block|{
literal|0x0ec08100
block|,
literal|0x0ff08f10
block|,
literal|"acs%c%P%R\t%12-14f, %0-3f"
block|}
block|,
block|{
literal|0x0ed08100
block|,
literal|0x0ff08f10
block|,
literal|"atn%c%P%R\t%12-14f, %0-3f"
block|}
block|,
block|{
literal|0x0ee08100
block|,
literal|0x0ff08f10
block|,
literal|"urd%c%P%R\t%12-14f, %0-3f"
block|}
block|,
block|{
literal|0x0ef08100
block|,
literal|0x0ff08f10
block|,
literal|"nrm%c%P%R\t%12-14f, %0-3f"
block|}
block|,
block|{
literal|0x0e000110
block|,
literal|0x0ff00f1f
block|,
literal|"flt%c%P%R\t%16-18f, %12-15r"
block|}
block|,
block|{
literal|0x0e100110
block|,
literal|0x0fff0f98
block|,
literal|"fix%c%R\t%12-15r, %0-2f"
block|}
block|,
block|{
literal|0x0e200110
block|,
literal|0x0fff0fff
block|,
literal|"wfs%c\t%12-15r"
block|}
block|,
block|{
literal|0x0e300110
block|,
literal|0x0fff0fff
block|,
literal|"rfs%c\t%12-15r"
block|}
block|,
block|{
literal|0x0e400110
block|,
literal|0x0fff0fff
block|,
literal|"wfc%c\t%12-15r"
block|}
block|,
block|{
literal|0x0e500110
block|,
literal|0x0fff0fff
block|,
literal|"rfc%c\t%12-15r"
block|}
block|,
block|{
literal|0x0e90f110
block|,
literal|0x0ff8fff0
block|,
literal|"cmf%c\t%16-18f, %0-3f"
block|}
block|,
block|{
literal|0x0eb0f110
block|,
literal|0x0ff8fff0
block|,
literal|"cnf%c\t%16-18f, %0-3f"
block|}
block|,
block|{
literal|0x0ed0f110
block|,
literal|0x0ff8fff0
block|,
literal|"cmfe%c\t%16-18f, %0-3f"
block|}
block|,
block|{
literal|0x0ef0f110
block|,
literal|0x0ff8fff0
block|,
literal|"cnfe%c\t%16-18f, %0-3f"
block|}
block|,
block|{
literal|0x0c000100
block|,
literal|0x0e100f00
block|,
literal|"stf%c%Q\t%12-14f, %A"
block|}
block|,
block|{
literal|0x0c100100
block|,
literal|0x0e100f00
block|,
literal|"ldf%c%Q\t%12-14f, %A"
block|}
block|,
block|{
literal|0x0c000200
block|,
literal|0x0e100f00
block|,
literal|"sfm%c\t%12-14f, %F, %A"
block|}
block|,
block|{
literal|0x0c100200
block|,
literal|0x0e100f00
block|,
literal|"lfm%c\t%12-14f, %F, %A"
block|}
block|,
comment|/* Generic coprocessor instructions */
block|{
literal|0x0e000000
block|,
literal|0x0f000010
block|,
literal|"cdp%c\t%8-11d, %20-23d, cr%12-15d, cr%16-19d, cr%0-3d, {%5-7d}"
block|}
block|,
block|{
literal|0x0e100010
block|,
literal|0x0f100010
block|,
literal|"mrc%c\t%8-11d, %21-23d, %12-15r, cr%16-19d, cr%0-3d, {%5-7d}"
block|}
block|,
block|{
literal|0x0e000010
block|,
literal|0x0f100010
block|,
literal|"mcr%c\t%8-11d, %21-23d, %12-15r, cr%16-19d, cr%0-3d, {%5-7d}"
block|}
block|,
block|{
literal|0x0c000000
block|,
literal|0x0e100000
block|,
literal|"stc%c%22'l\t%8-11d, cr%12-15d, %A"
block|}
block|,
block|{
literal|0x0c100000
block|,
literal|0x0e100000
block|,
literal|"ldc%c%22'l\t%8-11d, cr%12-15d, %A"
block|}
block|,
comment|/* The rest.  */
block|{
literal|0x00000000
block|,
literal|0x00000000
block|,
literal|"undefined instruction %0-31x"
block|}
block|,
block|{
literal|0x00000000
block|,
literal|0x00000000
block|,
literal|0
block|}
block|}
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|BDISP
parameter_list|(
name|x
parameter_list|)
value|((((x)& 0xffffff) ^ 0x800000) - 0x800000)
end_define

begin_comment
comment|/* 26 bit */
end_comment

begin_decl_stmt
specifier|static
name|struct
name|thumb_opcode
name|thumb_opcodes
index|[]
init|=
block|{
comment|/* Thumb instructions.  */
comment|/* ARM V5 ISA extends Thumb.  */
block|{
literal|0xbe00
block|,
literal|0xff00
block|,
literal|"bkpt\t%0-7x"
block|}
block|,
block|{
literal|0x4780
block|,
literal|0xff87
block|,
literal|"blx\t%3-6r"
block|}
block|,
comment|/* note: 4 bit register number.  */
comment|/* Note: this is BLX(2).  BLX(1) is done in arm-dis.c/print_insn_thumb()      as an extension of the special processing there for Thumb BL.      BL and BLX(1) involve 2 successive 16-bit instructions, which must      always appear together in the correct order.  So, the empty      string is put in this table, and the string interpreter takes<empty>      to mean it has a pair of BL-ish instructions.  */
block|{
literal|0x46C0
block|,
literal|0xFFFF
block|,
literal|"nop\t\t\t(mov r8, r8)"
block|}
block|,
comment|/* Format 5 instructions do not update the PSR.  */
block|{
literal|0x1C00
block|,
literal|0xFFC0
block|,
literal|"mov\t%0-2r, %3-5r\t\t(add %0-2r, %3-5r, #%6-8d)"
block|}
block|,
comment|/* Format 4.  */
block|{
literal|0x4000
block|,
literal|0xFFC0
block|,
literal|"and\t%0-2r, %3-5r"
block|}
block|,
block|{
literal|0x4040
block|,
literal|0xFFC0
block|,
literal|"eor\t%0-2r, %3-5r"
block|}
block|,
block|{
literal|0x4080
block|,
literal|0xFFC0
block|,
literal|"lsl\t%0-2r, %3-5r"
block|}
block|,
block|{
literal|0x40C0
block|,
literal|0xFFC0
block|,
literal|"lsr\t%0-2r, %3-5r"
block|}
block|,
block|{
literal|0x4100
block|,
literal|0xFFC0
block|,
literal|"asr\t%0-2r, %3-5r"
block|}
block|,
block|{
literal|0x4140
block|,
literal|0xFFC0
block|,
literal|"adc\t%0-2r, %3-5r"
block|}
block|,
block|{
literal|0x4180
block|,
literal|0xFFC0
block|,
literal|"sbc\t%0-2r, %3-5r"
block|}
block|,
block|{
literal|0x41C0
block|,
literal|0xFFC0
block|,
literal|"ror\t%0-2r, %3-5r"
block|}
block|,
block|{
literal|0x4200
block|,
literal|0xFFC0
block|,
literal|"tst\t%0-2r, %3-5r"
block|}
block|,
block|{
literal|0x4240
block|,
literal|0xFFC0
block|,
literal|"neg\t%0-2r, %3-5r"
block|}
block|,
block|{
literal|0x4280
block|,
literal|0xFFC0
block|,
literal|"cmp\t%0-2r, %3-5r"
block|}
block|,
block|{
literal|0x42C0
block|,
literal|0xFFC0
block|,
literal|"cmn\t%0-2r, %3-5r"
block|}
block|,
block|{
literal|0x4300
block|,
literal|0xFFC0
block|,
literal|"orr\t%0-2r, %3-5r"
block|}
block|,
block|{
literal|0x4340
block|,
literal|0xFFC0
block|,
literal|"mul\t%0-2r, %3-5r"
block|}
block|,
block|{
literal|0x4380
block|,
literal|0xFFC0
block|,
literal|"bic\t%0-2r, %3-5r"
block|}
block|,
block|{
literal|0x43C0
block|,
literal|0xFFC0
block|,
literal|"mvn\t%0-2r, %3-5r"
block|}
block|,
comment|/* format 13 */
block|{
literal|0xB000
block|,
literal|0xFF80
block|,
literal|"add\tsp, #%0-6W"
block|}
block|,
block|{
literal|0xB080
block|,
literal|0xFF80
block|,
literal|"sub\tsp, #%0-6W"
block|}
block|,
comment|/* format 5 */
block|{
literal|0x4700
block|,
literal|0xFF80
block|,
literal|"bx\t%S"
block|}
block|,
block|{
literal|0x4400
block|,
literal|0xFF00
block|,
literal|"add\t%D, %S"
block|}
block|,
block|{
literal|0x4500
block|,
literal|0xFF00
block|,
literal|"cmp\t%D, %S"
block|}
block|,
block|{
literal|0x4600
block|,
literal|0xFF00
block|,
literal|"mov\t%D, %S"
block|}
block|,
comment|/* format 14 */
block|{
literal|0xB400
block|,
literal|0xFE00
block|,
literal|"push\t%N"
block|}
block|,
block|{
literal|0xBC00
block|,
literal|0xFE00
block|,
literal|"pop\t%O"
block|}
block|,
comment|/* format 2 */
block|{
literal|0x1800
block|,
literal|0xFE00
block|,
literal|"add\t%0-2r, %3-5r, %6-8r"
block|}
block|,
block|{
literal|0x1A00
block|,
literal|0xFE00
block|,
literal|"sub\t%0-2r, %3-5r, %6-8r"
block|}
block|,
block|{
literal|0x1C00
block|,
literal|0xFE00
block|,
literal|"add\t%0-2r, %3-5r, #%6-8d"
block|}
block|,
block|{
literal|0x1E00
block|,
literal|0xFE00
block|,
literal|"sub\t%0-2r, %3-5r, #%6-8d"
block|}
block|,
comment|/* format 8 */
block|{
literal|0x5200
block|,
literal|0xFE00
block|,
literal|"strh\t%0-2r, [%3-5r, %6-8r]"
block|}
block|,
block|{
literal|0x5A00
block|,
literal|0xFE00
block|,
literal|"ldrh\t%0-2r, [%3-5r, %6-8r]"
block|}
block|,
block|{
literal|0x5600
block|,
literal|0xF600
block|,
literal|"ldrs%11?hb\t%0-2r, [%3-5r, %6-8r]"
block|}
block|,
comment|/* format 7 */
block|{
literal|0x5000
block|,
literal|0xFA00
block|,
literal|"str%10'b\t%0-2r, [%3-5r, %6-8r]"
block|}
block|,
block|{
literal|0x5800
block|,
literal|0xFA00
block|,
literal|"ldr%10'b\t%0-2r, [%3-5r, %6-8r]"
block|}
block|,
comment|/* format 1 */
block|{
literal|0x0000
block|,
literal|0xF800
block|,
literal|"lsl\t%0-2r, %3-5r, #%6-10d"
block|}
block|,
block|{
literal|0x0800
block|,
literal|0xF800
block|,
literal|"lsr\t%0-2r, %3-5r, #%6-10d"
block|}
block|,
block|{
literal|0x1000
block|,
literal|0xF800
block|,
literal|"asr\t%0-2r, %3-5r, #%6-10d"
block|}
block|,
comment|/* format 3 */
block|{
literal|0x2000
block|,
literal|0xF800
block|,
literal|"mov\t%8-10r, #%0-7d"
block|}
block|,
block|{
literal|0x2800
block|,
literal|0xF800
block|,
literal|"cmp\t%8-10r, #%0-7d"
block|}
block|,
block|{
literal|0x3000
block|,
literal|0xF800
block|,
literal|"add\t%8-10r, #%0-7d"
block|}
block|,
block|{
literal|0x3800
block|,
literal|0xF800
block|,
literal|"sub\t%8-10r, #%0-7d"
block|}
block|,
comment|/* format 6 */
block|{
literal|0x4800
block|,
literal|0xF800
block|,
literal|"ldr\t%8-10r, [pc, #%0-7W]\t(%0-7a)"
block|}
block|,
comment|/* TODO: Disassemble PC relative "LDR rD,=<symbolic>" */
comment|/* format 9 */
block|{
literal|0x6000
block|,
literal|0xF800
block|,
literal|"str\t%0-2r, [%3-5r, #%6-10W]"
block|}
block|,
block|{
literal|0x6800
block|,
literal|0xF800
block|,
literal|"ldr\t%0-2r, [%3-5r, #%6-10W]"
block|}
block|,
block|{
literal|0x7000
block|,
literal|0xF800
block|,
literal|"strb\t%0-2r, [%3-5r, #%6-10d]"
block|}
block|,
block|{
literal|0x7800
block|,
literal|0xF800
block|,
literal|"ldrb\t%0-2r, [%3-5r, #%6-10d]"
block|}
block|,
comment|/* format 10 */
block|{
literal|0x8000
block|,
literal|0xF800
block|,
literal|"strh\t%0-2r, [%3-5r, #%6-10H]"
block|}
block|,
block|{
literal|0x8800
block|,
literal|0xF800
block|,
literal|"ldrh\t%0-2r, [%3-5r, #%6-10H]"
block|}
block|,
comment|/* format 11 */
block|{
literal|0x9000
block|,
literal|0xF800
block|,
literal|"str\t%8-10r, [sp, #%0-7W]"
block|}
block|,
block|{
literal|0x9800
block|,
literal|0xF800
block|,
literal|"ldr\t%8-10r, [sp, #%0-7W]"
block|}
block|,
comment|/* format 12 */
block|{
literal|0xA000
block|,
literal|0xF800
block|,
literal|"add\t%8-10r, pc, #%0-7W\t(adr %8-10r,%0-7a)"
block|}
block|,
block|{
literal|0xA800
block|,
literal|0xF800
block|,
literal|"add\t%8-10r, sp, #%0-7W"
block|}
block|,
comment|/* format 15 */
block|{
literal|0xC000
block|,
literal|0xF800
block|,
literal|"stmia\t%8-10r!,%M"
block|}
block|,
block|{
literal|0xC800
block|,
literal|0xF800
block|,
literal|"ldmia\t%8-10r!,%M"
block|}
block|,
comment|/* format 18 */
block|{
literal|0xE000
block|,
literal|0xF800
block|,
literal|"b\t%0-10B"
block|}
block|,
block|{
literal|0xE800
block|,
literal|0xF800
block|,
literal|"undefined"
block|}
block|,
comment|/* format 19 */
block|{
literal|0xF000
block|,
literal|0xF800
block|,
literal|""
block|}
block|,
comment|/* special processing required in disassembler */
block|{
literal|0xF800
block|,
literal|0xF800
block|,
literal|"second half of BL instruction %0-15x"
block|}
block|,
comment|/* format 16 */
block|{
literal|0xD000
block|,
literal|0xFF00
block|,
literal|"beq\t%0-7B"
block|}
block|,
block|{
literal|0xD100
block|,
literal|0xFF00
block|,
literal|"bne\t%0-7B"
block|}
block|,
block|{
literal|0xD200
block|,
literal|0xFF00
block|,
literal|"bcs\t%0-7B"
block|}
block|,
block|{
literal|0xD300
block|,
literal|0xFF00
block|,
literal|"bcc\t%0-7B"
block|}
block|,
block|{
literal|0xD400
block|,
literal|0xFF00
block|,
literal|"bmi\t%0-7B"
block|}
block|,
block|{
literal|0xD500
block|,
literal|0xFF00
block|,
literal|"bpl\t%0-7B"
block|}
block|,
block|{
literal|0xD600
block|,
literal|0xFF00
block|,
literal|"bvs\t%0-7B"
block|}
block|,
block|{
literal|0xD700
block|,
literal|0xFF00
block|,
literal|"bvc\t%0-7B"
block|}
block|,
block|{
literal|0xD800
block|,
literal|0xFF00
block|,
literal|"bhi\t%0-7B"
block|}
block|,
block|{
literal|0xD900
block|,
literal|0xFF00
block|,
literal|"bls\t%0-7B"
block|}
block|,
block|{
literal|0xDA00
block|,
literal|0xFF00
block|,
literal|"bge\t%0-7B"
block|}
block|,
block|{
literal|0xDB00
block|,
literal|0xFF00
block|,
literal|"blt\t%0-7B"
block|}
block|,
block|{
literal|0xDC00
block|,
literal|0xFF00
block|,
literal|"bgt\t%0-7B"
block|}
block|,
block|{
literal|0xDD00
block|,
literal|0xFF00
block|,
literal|"ble\t%0-7B"
block|}
block|,
comment|/* format 17 */
block|{
literal|0xDE00
block|,
literal|0xFF00
block|,
literal|"bal\t%0-7B"
block|}
block|,
block|{
literal|0xDF00
block|,
literal|0xFF00
block|,
literal|"swi\t%0-7d"
block|}
block|,
comment|/* format 9 */
block|{
literal|0x6000
block|,
literal|0xF800
block|,
literal|"str\t%0-2r, [%3-5r, #%6-10W]"
block|}
block|,
block|{
literal|0x6800
block|,
literal|0xF800
block|,
literal|"ldr\t%0-2r, [%3-5r, #%6-10W]"
block|}
block|,
block|{
literal|0x7000
block|,
literal|0xF800
block|,
literal|"strb\t%0-2r, [%3-5r, #%6-10d]"
block|}
block|,
block|{
literal|0x7800
block|,
literal|0xF800
block|,
literal|"ldrb\t%0-2r, [%3-5r, #%6-10d]"
block|}
block|,
comment|/* the rest */
block|{
literal|0x0000
block|,
literal|0x0000
block|,
literal|"undefined instruction %0-15x"
block|}
block|,
block|{
literal|0x0000
block|,
literal|0x0000
block|,
literal|0
block|}
block|}
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|BDISP23
parameter_list|(
name|x
parameter_list|)
value|((((((x)& 0x07ff)<< 11) | (((x)& 0x07ff0000)>> 16)) \                      ^ 0x200000) - 0x200000)
end_define

begin_comment
comment|/* 23bit */
end_comment

end_unit

