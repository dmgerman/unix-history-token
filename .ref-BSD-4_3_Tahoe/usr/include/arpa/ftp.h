begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1983 Regents of the University of California.  * All rights reserved.  *  * Redistribution and use in source and binary forms are permitted  * provided that the above copyright notice and this paragraph are  * duplicated in all such forms and that any documentation,  * advertising materials, and other materials related to such  * distribution and use acknowledge that the software was developed  * by the University of California, Berkeley.  The name of the  * University may not be used to endorse or promote products derived  * from this software without specific prior written permission.  * THIS SOFTWARE IS PROVIDED ``AS IS'' AND WITHOUT ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, WITHOUT LIMITATION, THE IMPLIED  * WARRANTIES OF MERCHANTIBILITY AND FITNESS FOR A PARTICULAR PURPOSE.  *  *	@(#)ftp.h	5.3 (Berkeley) 6/27/88  */
end_comment

begin_comment
comment|/*  * Definitions for FTP  * See RFC-765  */
end_comment

begin_comment
comment|/*  * Reply codes.  */
end_comment

begin_define
define|#
directive|define
name|PRELIM
value|1
end_define

begin_comment
comment|/* positive preliminary */
end_comment

begin_define
define|#
directive|define
name|COMPLETE
value|2
end_define

begin_comment
comment|/* positive completion */
end_comment

begin_define
define|#
directive|define
name|CONTINUE
value|3
end_define

begin_comment
comment|/* positive intermediate */
end_comment

begin_define
define|#
directive|define
name|TRANSIENT
value|4
end_define

begin_comment
comment|/* transient negative completion */
end_comment

begin_define
define|#
directive|define
name|ERROR
value|5
end_define

begin_comment
comment|/* permanent negative completion */
end_comment

begin_comment
comment|/*  * Type codes  */
end_comment

begin_define
define|#
directive|define
name|TYPE_A
value|1
end_define

begin_comment
comment|/* ASCII */
end_comment

begin_define
define|#
directive|define
name|TYPE_E
value|2
end_define

begin_comment
comment|/* EBCDIC */
end_comment

begin_define
define|#
directive|define
name|TYPE_I
value|3
end_define

begin_comment
comment|/* image */
end_comment

begin_define
define|#
directive|define
name|TYPE_L
value|4
end_define

begin_comment
comment|/* local byte size */
end_comment

begin_comment
comment|/*  * Form codes  */
end_comment

begin_define
define|#
directive|define
name|FORM_N
value|1
end_define

begin_comment
comment|/* non-print */
end_comment

begin_define
define|#
directive|define
name|FORM_T
value|2
end_define

begin_comment
comment|/* telnet format effectors */
end_comment

begin_define
define|#
directive|define
name|FORM_C
value|3
end_define

begin_comment
comment|/* carriage control (ASA) */
end_comment

begin_comment
comment|/*  * Structure codes  */
end_comment

begin_define
define|#
directive|define
name|STRU_F
value|1
end_define

begin_comment
comment|/* file (no record structure) */
end_comment

begin_define
define|#
directive|define
name|STRU_R
value|2
end_define

begin_comment
comment|/* record structure */
end_comment

begin_define
define|#
directive|define
name|STRU_P
value|3
end_define

begin_comment
comment|/* page structure */
end_comment

begin_comment
comment|/*  * Mode types  */
end_comment

begin_define
define|#
directive|define
name|MODE_S
value|1
end_define

begin_comment
comment|/* stream */
end_comment

begin_define
define|#
directive|define
name|MODE_B
value|2
end_define

begin_comment
comment|/* block */
end_comment

begin_define
define|#
directive|define
name|MODE_C
value|3
end_define

begin_comment
comment|/* compressed */
end_comment

begin_comment
comment|/*  * Record Tokens  */
end_comment

begin_define
define|#
directive|define
name|REC_ESC
value|'\377'
end_define

begin_comment
comment|/* Record-mode Escape */
end_comment

begin_define
define|#
directive|define
name|REC_EOR
value|'\001'
end_define

begin_comment
comment|/* Record-mode End-of-Record */
end_comment

begin_define
define|#
directive|define
name|REC_EOF
value|'\002'
end_define

begin_comment
comment|/* Record-mode End-of-File */
end_comment

begin_comment
comment|/*  * Block Header  */
end_comment

begin_define
define|#
directive|define
name|BLK_EOR
value|0x80
end_define

begin_comment
comment|/* Block is End-of-Record */
end_comment

begin_define
define|#
directive|define
name|BLK_EOF
value|0x40
end_define

begin_comment
comment|/* Block is End-of-File */
end_comment

begin_define
define|#
directive|define
name|BLK_ERRORS
value|0x20
end_define

begin_comment
comment|/* Block is suspected of containing errors */
end_comment

begin_define
define|#
directive|define
name|BLK_RESTART
value|0x10
end_define

begin_comment
comment|/* Block is Restart Marker */
end_comment

begin_define
define|#
directive|define
name|BLK_BYTECOUNT
value|2
end_define

begin_comment
comment|/* Bytes in this block */
end_comment

end_unit

