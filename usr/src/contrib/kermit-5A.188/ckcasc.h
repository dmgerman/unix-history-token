begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*   File CKCASC.H   Mnemonics for ASCII control characters (and Space) for use with C-Kermit. */
end_comment

begin_comment
comment|/*   Author: Frank da Cruz (fdc@columbia.edu, FDCCU@CUVMA.BITNET),   Columbia University Center for Computing Activities.   First released January 1985.   Copyright (C) 1985, 1992, Trustees of Columbia University in the City of New   York.  Permission is granted to any individual or institution to use this   software as long as it is not sold for profit.  This copyright notice must be   retained.  This software may not be included in commercial products without   written permission of Columbia University. */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|CKCASC_H
end_ifndef

begin_define
define|#
directive|define
name|CKCASC_H
end_define

begin_define
define|#
directive|define
name|NUL
value|'\0'
end_define

begin_comment
comment|/* Null */
end_comment

begin_define
define|#
directive|define
name|SOH
value|001
end_define

begin_comment
comment|/* Start of header */
end_comment

begin_define
define|#
directive|define
name|STX
value|002
end_define

begin_comment
comment|/* Ctrl-B */
end_comment

begin_define
define|#
directive|define
name|ENQ
value|005
end_define

begin_comment
comment|/* ENQ */
end_comment

begin_define
define|#
directive|define
name|BEL
value|007
end_define

begin_comment
comment|/* Bell (Beep) */
end_comment

begin_define
define|#
directive|define
name|BS
value|010
end_define

begin_comment
comment|/* Backspace */
end_comment

begin_define
define|#
directive|define
name|HT
value|011
end_define

begin_comment
comment|/* Horizontal Tab */
end_comment

begin_define
define|#
directive|define
name|LF
value|012
end_define

begin_comment
comment|/* Linefeed */
end_comment

begin_define
define|#
directive|define
name|NL
value|'\n'
end_define

begin_comment
comment|/* Newline */
end_comment

begin_define
define|#
directive|define
name|FF
value|014
end_define

begin_comment
comment|/* Formfeed */
end_comment

begin_define
define|#
directive|define
name|CR
value|015
end_define

begin_comment
comment|/* Carriage Return */
end_comment

begin_define
define|#
directive|define
name|SO
value|016
end_define

begin_comment
comment|/* Shift Out */
end_comment

begin_define
define|#
directive|define
name|SI
value|017
end_define

begin_comment
comment|/* Shift In */
end_comment

begin_define
define|#
directive|define
name|DLE
value|020
end_define

begin_comment
comment|/* Datalink Escape */
end_comment

begin_define
define|#
directive|define
name|ESC
value|033
end_define

begin_comment
comment|/* Escape */
end_comment

begin_define
define|#
directive|define
name|XON
value|021
end_define

begin_comment
comment|/* XON */
end_comment

begin_define
define|#
directive|define
name|XOFF
value|023
end_define

begin_comment
comment|/* XOFF */
end_comment

begin_define
define|#
directive|define
name|SUB
value|032
end_define

begin_comment
comment|/* SUB */
end_comment

begin_define
define|#
directive|define
name|XGS
value|'\x1D'
end_define

begin_comment
comment|/* Group Separator,  Ctrl-Rightbracket */
end_comment

begin_define
define|#
directive|define
name|US
value|'\x1F'
end_define

begin_comment
comment|/* Unit Separator,   Ctrl-Underscore */
end_comment

begin_define
define|#
directive|define
name|XFS
value|'\x1C'
end_define

begin_comment
comment|/* Field Separator,  Ctrl-Backslash */
end_comment

begin_define
define|#
directive|define
name|XRS
value|036
end_define

begin_comment
comment|/* Record Separator, Ctrl-Circumflex */
end_comment

begin_define
define|#
directive|define
name|SYN
value|'\x16'
end_define

begin_comment
comment|/* SYN, Ctrl-V */
end_comment

begin_define
define|#
directive|define
name|CAN
value|030
end_define

begin_comment
comment|/* CAN, Ctrl-X */
end_comment

begin_define
define|#
directive|define
name|SP
value|040
end_define

begin_comment
comment|/* Space */
end_comment

begin_define
define|#
directive|define
name|DEL
value|0177
end_define

begin_comment
comment|/* Delete (Rubout) */
end_comment

begin_define
define|#
directive|define
name|RUB
value|0177
end_define

begin_comment
comment|/* Delete (Rubout) */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|COMMENT
end_ifdef

begin_comment
comment|/*   These aren't needed yet, so let's not cause any unnecessary conflicts. */
end_comment

begin_define
define|#
directive|define
name|CSI
value|0233
end_define

begin_comment
comment|/* 8-bit Control Sequence Introducer */
end_comment

begin_define
define|#
directive|define
name|SS2
value|0216
end_define

begin_comment
comment|/* 8-bit Single Shift 2 */
end_comment

begin_define
define|#
directive|define
name|SS3
value|0217
end_define

begin_comment
comment|/* 8-bit Single Shift 3 */
end_comment

begin_define
define|#
directive|define
name|DCS
value|0220
end_define

begin_comment
comment|/* 8-bit Device Control String Introducer */
end_comment

begin_define
define|#
directive|define
name|ST8
value|0234
end_define

begin_comment
comment|/* 8-bit String Terminator */
end_comment

begin_define
define|#
directive|define
name|OSC
value|0235
end_define

begin_comment
comment|/* 8-bit Operating System Command */
end_comment

begin_define
define|#
directive|define
name|PM8
value|0236
end_define

begin_comment
comment|/* 8-bit Privace Message */
end_comment

begin_define
define|#
directive|define
name|APC
value|0237
end_define

begin_comment
comment|/* 8-bit Application Program Command */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* COMMENT */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* CKCASC_H */
end_comment

end_unit

