begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1992 The Regents of the University of California.  * All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * Sony Corp. and Kazumasa Utashiro of Software Research Associates, Inc.  *  * %sccs.include.redist.c%  *  * from: $Hdr: sccparam.h,v 4.300 91/06/09 06:44:57 root Rel41 $ SONY  *  *	@(#)sccparam.h	7.1 (Berkeley) %G%  */
end_comment

begin_comment
comment|/*  *	SCC channel parameter  */
end_comment

begin_define
define|#
directive|define
name|BAUD_RATE
value|0x0000000f
end_define

begin_define
define|#
directive|define
name|RXE
value|0x00000010
end_define

begin_define
define|#
directive|define
name|TXE
value|0x00000020
end_define

begin_define
define|#
directive|define
name|CHAR_SIZE
value|0x000000c0
end_define

begin_define
define|#
directive|define
name|C5BIT
value|0x00000000
end_define

begin_define
define|#
directive|define
name|C7BIT
value|0x00000040
end_define

begin_define
define|#
directive|define
name|C6BIT
value|0x00000080
end_define

begin_define
define|#
directive|define
name|C8BIT
value|0x000000c0
end_define

begin_define
define|#
directive|define
name|PARITY
value|0x00000100
end_define

begin_define
define|#
directive|define
name|EVEN
value|0x00000200
end_define

begin_define
define|#
directive|define
name|ODD
value|0x00000000
end_define

begin_define
define|#
directive|define
name|STOPBIT
value|0x00000c00
end_define

begin_define
define|#
directive|define
name|STOP1
value|0x00000400
end_define

begin_define
define|#
directive|define
name|STOP1_5
value|0x00000800
end_define

begin_define
define|#
directive|define
name|STOP2
value|0x00000c00
end_define

begin_define
define|#
directive|define
name|RTS
value|0x00001000
end_define

begin_define
define|#
directive|define
name|DTR
value|0x00002000
end_define

begin_define
define|#
directive|define
name|XBREAK
value|0x00004000
end_define

begin_define
define|#
directive|define
name|NOCHECK
value|0x00008000
end_define

begin_define
define|#
directive|define
name|DCD
value|0x00010000
end_define

begin_define
define|#
directive|define
name|CTS
value|0x00020000
end_define

begin_define
define|#
directive|define
name|RI
value|0x00040000
end_define

begin_define
define|#
directive|define
name|DSR
value|0x00080000
end_define

begin_define
define|#
directive|define
name|RBREAK
value|0x00100000
end_define

begin_define
define|#
directive|define
name|SCC_PARITY_ERROR
value|0x00200000
end_define

begin_define
define|#
directive|define
name|OVERRUN_ERROR
value|0x00400000
end_define

begin_define
define|#
directive|define
name|FRAMING_ERROR
value|0x00800000
end_define

begin_define
define|#
directive|define
name|AUTO_ENABLE
value|0x01000000
end_define

begin_define
define|#
directive|define
name|EXTCLK_ENABLE
value|0x02000000
end_define

begin_define
define|#
directive|define
name|TERM_MODE
value|0x70000000
end_define

begin_define
define|#
directive|define
name|CJIS
value|0x10000000
end_define

begin_define
define|#
directive|define
name|CSJIS
value|0x20000000
end_define

begin_define
define|#
directive|define
name|CEUC
value|0x40000000
end_define

end_unit

