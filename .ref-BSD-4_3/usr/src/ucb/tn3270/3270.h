begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  *	Copyright 1984, 1985 by the Regents of the University of  *	California and by Gregory Glenn Minshall.  *  *	Permission to use, copy, modify, and distribute these  *	programs and their documentation for any purpose and  *	without fee is hereby granted, provided that this  *	copyright and permission appear on all copies and  *	supporting documentation, the name of the Regents of  *	the University of California not be used in advertising  *	or publicity pertaining to distribution of the programs  *	without specific prior permission, and notice be given in  *	supporting documentation that copying and distribution is  *	by permission of the Regents of the University of California  *	and by Gregory Glenn Minshall.  Neither the Regents of the  *	University of California nor Gregory Glenn Minshall make  *	representations about the suitability of this software  *	for any purpose.  It is provided "as is" without  *	express or implied warranty.  */
end_comment

begin_comment
comment|/* define orders given to 3270's */
end_comment

begin_define
define|#
directive|define
name|ORDER_SF
value|0x1d
end_define

begin_comment
comment|/* Start Field */
end_comment

begin_define
define|#
directive|define
name|ORDER_SBA
value|0x11
end_define

begin_comment
comment|/* Set Buffer Address (for output) */
end_comment

begin_define
define|#
directive|define
name|ORDER_IC
value|0x13
end_define

begin_comment
comment|/* Insert Cursor (at buffer address) */
end_comment

begin_define
define|#
directive|define
name|ORDER_PT
value|0x05
end_define

begin_comment
comment|/* Program Tab (absurdly complicated) */
end_comment

begin_define
define|#
directive|define
name|ORDER_RA
value|0x3c
end_define

begin_comment
comment|/* Repeat next character to some addr */
end_comment

begin_define
define|#
directive|define
name|ORDER_EUA
value|0x12
end_define

begin_comment
comment|/* Null out every unprotected field 					 * to some address. 					 */
end_comment

begin_define
define|#
directive|define
name|ORDER_YALE
value|0x2b
end_define

begin_comment
comment|/* This is a special YALE order, which 					 * introduces YALE extended orders 					 * (like setting tabs, etc.). 					 */
end_comment

begin_define
define|#
directive|define
name|ATTR_MASK
value|0xc0
end_define

begin_comment
comment|/* control bits */
end_comment

begin_define
define|#
directive|define
name|ATTR_PROT
value|0x20
end_define

begin_comment
comment|/* protected bit */
end_comment

begin_define
define|#
directive|define
name|ATTR_NUMERIC
value|0x10
end_define

begin_comment
comment|/* numeric field */
end_comment

begin_define
define|#
directive|define
name|ATTR_AUTO_SKIP_MASK
value|0x30
end_define

begin_comment
comment|/* mask to check auto skip */
end_comment

begin_define
define|#
directive|define
name|ATTR_AUTO_SKIP_VALUE
value|0x30
end_define

begin_comment
comment|/* value to have auto skip */
end_comment

begin_define
define|#
directive|define
name|ATTR_DSPD_MASK
value|0x0c
end_define

begin_comment
comment|/* highlighting, etc. */
end_comment

begin_define
define|#
directive|define
name|ATTR_DSPD_DNSPD
value|0x00
end_define

begin_comment
comment|/* display, no select */
end_comment

begin_define
define|#
directive|define
name|ATTR_DSPD_DSPD
value|0x04
end_define

begin_comment
comment|/* display, select */
end_comment

begin_define
define|#
directive|define
name|ATTR_DSPD_HIGH
value|0x08
end_define

begin_comment
comment|/* highlighted, select */
end_comment

begin_define
define|#
directive|define
name|ATTR_DSPD_NONDISPLAY
value|0x0c
end_define

begin_comment
comment|/* non-display, no select */
end_comment

begin_define
define|#
directive|define
name|ATTR_MDT
value|0x01
end_define

begin_comment
comment|/* modified data tag */
end_comment

begin_define
define|#
directive|define
name|CMD_ERASE_ALL_UNPROTECTED
value|0x0f
end_define

begin_define
define|#
directive|define
name|CMD_ERASE_WRITE
value|0x05
end_define

begin_define
define|#
directive|define
name|CMD_WRITE
value|0x01
end_define

begin_define
define|#
directive|define
name|CMD_READ_MODIFIED
value|0x06
end_define

begin_define
define|#
directive|define
name|CMD_READ_BUFFER
value|0x02
end_define

begin_define
define|#
directive|define
name|WCC_ALARM
value|0x04
end_define

begin_define
define|#
directive|define
name|WCC_RESTORE
value|0x02
end_define

begin_define
define|#
directive|define
name|WCC_RESET_MDT
value|0x01
end_define

begin_define
define|#
directive|define
name|AID_PA1
value|0x6c
end_define

begin_define
define|#
directive|define
name|AID_PA2
value|0x6e
end_define

begin_define
define|#
directive|define
name|AID_PA3
value|0x6b
end_define

begin_define
define|#
directive|define
name|AID_CLEAR
value|0x6d
end_define

begin_comment
comment|/* Special EBCDIC characters unique to a 3270 */
end_comment

begin_define
define|#
directive|define
name|EBCDIC_DUP
value|0x1c
end_define

begin_define
define|#
directive|define
name|EBCDIC_FM
value|0x1e
end_define

end_unit

