begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1994  *	The Regents of the University of California.  All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * Chuck Karish of Mindcraft, Inc.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)tar.h	8.2 (Berkeley) 1/4/94  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_TAR_H
end_ifndef

begin_define
define|#
directive|define
name|_TAR_H
end_define

begin_define
define|#
directive|define
name|TMAGIC
value|"ustar"
end_define

begin_comment
comment|/* ustar and a null */
end_comment

begin_define
define|#
directive|define
name|TMAGLEN
value|6
end_define

begin_define
define|#
directive|define
name|TVERSION
value|"00"
end_define

begin_comment
comment|/* 00 and no null */
end_comment

begin_define
define|#
directive|define
name|TVERSLEN
value|2
end_define

begin_comment
comment|/* Values used in typeflag field */
end_comment

begin_define
define|#
directive|define
name|REGTYPE
value|'0'
end_define

begin_comment
comment|/* Regular file */
end_comment

begin_define
define|#
directive|define
name|AREGTYPE
value|'\0'
end_define

begin_comment
comment|/* Regular file */
end_comment

begin_define
define|#
directive|define
name|LNKTYPE
value|'1'
end_define

begin_comment
comment|/* Link */
end_comment

begin_define
define|#
directive|define
name|SYMTYPE
value|'2'
end_define

begin_comment
comment|/* Reserved */
end_comment

begin_define
define|#
directive|define
name|CHRTYPE
value|'3'
end_define

begin_comment
comment|/* Character special */
end_comment

begin_define
define|#
directive|define
name|BLKTYPE
value|'4'
end_define

begin_comment
comment|/* Block special */
end_comment

begin_define
define|#
directive|define
name|DIRTYPE
value|'5'
end_define

begin_comment
comment|/* Directory */
end_comment

begin_define
define|#
directive|define
name|FIFOTYPE
value|'6'
end_define

begin_comment
comment|/* FIFO special */
end_comment

begin_define
define|#
directive|define
name|CONTTYPE
value|'7'
end_define

begin_comment
comment|/* Reserved */
end_comment

begin_comment
comment|/* Bits used in the mode field - values in octal */
end_comment

begin_define
define|#
directive|define
name|TSUID
value|04000
end_define

begin_comment
comment|/* Set UID on execution */
end_comment

begin_define
define|#
directive|define
name|TSGID
value|02000
end_define

begin_comment
comment|/* Set GID on execution */
end_comment

begin_define
define|#
directive|define
name|TSVTX
value|01000
end_define

begin_comment
comment|/* Reserved */
end_comment

begin_comment
comment|/* File permissions */
end_comment

begin_define
define|#
directive|define
name|TUREAD
value|00400
end_define

begin_comment
comment|/* Read by owner */
end_comment

begin_define
define|#
directive|define
name|TUWRITE
value|00200
end_define

begin_comment
comment|/* Write by owner */
end_comment

begin_define
define|#
directive|define
name|TUEXEC
value|00100
end_define

begin_comment
comment|/* Execute/Search by owner */
end_comment

begin_define
define|#
directive|define
name|TGREAD
value|00040
end_define

begin_comment
comment|/* Read by group */
end_comment

begin_define
define|#
directive|define
name|TGWRITE
value|00020
end_define

begin_comment
comment|/* Write by group */
end_comment

begin_define
define|#
directive|define
name|TGEXEC
value|00010
end_define

begin_comment
comment|/* Execute/Search by group */
end_comment

begin_define
define|#
directive|define
name|TOREAD
value|00004
end_define

begin_comment
comment|/* Read by other */
end_comment

begin_define
define|#
directive|define
name|TOWRITE
value|00002
end_define

begin_comment
comment|/* Write by other */
end_comment

begin_define
define|#
directive|define
name|TOEXEC
value|00001
end_define

begin_comment
comment|/* Execute/Search by other */
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

