begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1983, 1989, 1993  *	The Regents of the University of California.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)ftp.h	8.1 (Berkeley) 6/2/93  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_ARPA_FTP_H_
end_ifndef

begin_define
define|#
directive|define
name|_ARPA_FTP_H_
end_define

begin_comment
comment|/* Definitions for FTP; see RFC-765. */
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

begin_ifdef
ifdef|#
directive|ifdef
name|FTP_NAMES
end_ifdef

begin_decl_stmt
name|char
modifier|*
name|typenames
index|[]
init|=
block|{
literal|"0"
block|,
literal|"ASCII"
block|,
literal|"EBCDIC"
block|,
literal|"Image"
block|,
literal|"Local"
block|}
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

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

begin_ifdef
ifdef|#
directive|ifdef
name|FTP_NAMES
end_ifdef

begin_decl_stmt
name|char
modifier|*
name|formnames
index|[]
init|=
block|{
literal|"0"
block|,
literal|"Nonprint"
block|,
literal|"Telnet"
block|,
literal|"Carriage-control"
block|}
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

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

begin_ifdef
ifdef|#
directive|ifdef
name|FTP_NAMES
end_ifdef

begin_decl_stmt
name|char
modifier|*
name|strunames
index|[]
init|=
block|{
literal|"0"
block|,
literal|"File"
block|,
literal|"Record"
block|,
literal|"Page"
block|}
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

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

begin_ifdef
ifdef|#
directive|ifdef
name|FTP_NAMES
end_ifdef

begin_decl_stmt
name|char
modifier|*
name|modenames
index|[]
init|=
block|{
literal|"0"
block|,
literal|"Stream"
block|,
literal|"Block"
block|,
literal|"Compressed"
block|}
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

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

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_FTP_H_ */
end_comment

end_unit

