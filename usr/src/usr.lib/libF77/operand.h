begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1980 Regents of the University of California.  * All rights reserved.  The Berkeley software License Agreement  * specifies the terms and conditions for redistribution.  *  *	@(#)operand.h	5.1 (Berkeley) 6/7/85  *  * operand.h  --  definitions useful to VAX operand decoding  */
end_comment

begin_define
define|#
directive|define
name|opmode
parameter_list|(
name|op
parameter_list|)
value|(op& 0xf0)
end_define

begin_define
define|#
directive|define
name|opregn
parameter_list|(
name|op
parameter_list|)
value|(op& 0xf)
end_define

begin_comment
comment|/*  * operand modes  */
end_comment

begin_define
define|#
directive|define
name|LITERAL0
value|0x00
end_define

begin_define
define|#
directive|define
name|LITERAL1
value|0x10
end_define

begin_define
define|#
directive|define
name|LITERAL2
value|0x20
end_define

begin_define
define|#
directive|define
name|LITERAL3
value|0x30
end_define

begin_define
define|#
directive|define
name|INDEXED
value|0x40
end_define

begin_define
define|#
directive|define
name|REGISTER
value|0x50
end_define

begin_define
define|#
directive|define
name|REGDEFERED
value|0x60
end_define

begin_define
define|#
directive|define
name|AUTODEC
value|0x70
end_define

begin_define
define|#
directive|define
name|AUTOINC
value|0x80
end_define

begin_define
define|#
directive|define
name|AUTOINCDEF
value|0x90
end_define

begin_define
define|#
directive|define
name|BYTEDISP
value|0xa0
end_define

begin_define
define|#
directive|define
name|BYTEDISPDEF
value|0xb0
end_define

begin_define
define|#
directive|define
name|WORDDISP
value|0xc0
end_define

begin_define
define|#
directive|define
name|WORDDISPDEF
value|0xd0
end_define

begin_define
define|#
directive|define
name|LONGDISP
value|0xe0
end_define

begin_define
define|#
directive|define
name|LONGDISPDEF
value|0xf0
end_define

begin_comment
comment|/*  * Modes where R is PC  */
end_comment

begin_define
define|#
directive|define
name|IMMEDIATE
value|0x8f
end_define

begin_define
define|#
directive|define
name|ABSOLUTE
value|0x9f
end_define

begin_define
define|#
directive|define
name|BYTEREL
value|0xaf
end_define

begin_define
define|#
directive|define
name|BYTERELDEF
value|0xbf
end_define

begin_define
define|#
directive|define
name|WORDREL
value|0xcf
end_define

begin_define
define|#
directive|define
name|WORDRELDEF
value|0xdf
end_define

begin_define
define|#
directive|define
name|LONGREL
value|0xef
end_define

begin_define
define|#
directive|define
name|LONGRELDEF
value|0xff
end_define

begin_comment
comment|/*  * register definitions  */
end_comment

begin_define
define|#
directive|define
name|R0
value|0
end_define

begin_define
define|#
directive|define
name|R1
value|1
end_define

begin_define
define|#
directive|define
name|R2
value|2
end_define

begin_define
define|#
directive|define
name|R3
value|3
end_define

begin_define
define|#
directive|define
name|R4
value|4
end_define

begin_define
define|#
directive|define
name|R5
value|5
end_define

begin_define
define|#
directive|define
name|R6
value|6
end_define

begin_define
define|#
directive|define
name|R7
value|7
end_define

begin_define
define|#
directive|define
name|R8
value|8
end_define

begin_define
define|#
directive|define
name|R9
value|9
end_define

begin_define
define|#
directive|define
name|R10
value|10
end_define

begin_define
define|#
directive|define
name|R11
value|11
end_define

begin_define
define|#
directive|define
name|AP
value|12
end_define

begin_define
define|#
directive|define
name|FP
value|13
end_define

begin_define
define|#
directive|define
name|SP
value|14
end_define

begin_define
define|#
directive|define
name|PC
value|15
end_define

end_unit

