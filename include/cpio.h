begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2002 Mike Barcroft<mike@FreeBSD.org>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_CPIO_H_
end_ifndef

begin_define
define|#
directive|define
name|_CPIO_H_
end_define

begin_define
define|#
directive|define
name|C_ISSOCK
value|0140000
end_define

begin_comment
comment|/* Socket. */
end_comment

begin_define
define|#
directive|define
name|C_ISLNK
value|0120000
end_define

begin_comment
comment|/* Symbolic link. */
end_comment

begin_define
define|#
directive|define
name|C_ISCTG
value|0110000
end_define

begin_comment
comment|/* Reserved. */
end_comment

begin_define
define|#
directive|define
name|C_ISREG
value|0100000
end_define

begin_comment
comment|/* Regular file. */
end_comment

begin_define
define|#
directive|define
name|C_ISBLK
value|0060000
end_define

begin_comment
comment|/* Block special. */
end_comment

begin_define
define|#
directive|define
name|C_ISDIR
value|0040000
end_define

begin_comment
comment|/* Directory. */
end_comment

begin_define
define|#
directive|define
name|C_ISCHR
value|0020000
end_define

begin_comment
comment|/* Character special. */
end_comment

begin_define
define|#
directive|define
name|C_ISFIFO
value|0010000
end_define

begin_comment
comment|/* FIFO. */
end_comment

begin_define
define|#
directive|define
name|C_ISUID
value|0004000
end_define

begin_comment
comment|/* Set user ID. */
end_comment

begin_define
define|#
directive|define
name|C_ISGID
value|0002000
end_define

begin_comment
comment|/* Set group ID. */
end_comment

begin_define
define|#
directive|define
name|C_ISVTX
value|0001000
end_define

begin_comment
comment|/* On directories, restricted deletion flag. */
end_comment

begin_define
define|#
directive|define
name|C_IRUSR
value|0000400
end_define

begin_comment
comment|/* Read by owner. */
end_comment

begin_define
define|#
directive|define
name|C_IWUSR
value|0000200
end_define

begin_comment
comment|/* Write by owner. */
end_comment

begin_define
define|#
directive|define
name|C_IXUSR
value|0000100
end_define

begin_comment
comment|/* Execute by owner. */
end_comment

begin_define
define|#
directive|define
name|C_IRGRP
value|0000040
end_define

begin_comment
comment|/* Read by group. */
end_comment

begin_define
define|#
directive|define
name|C_IWGRP
value|0000020
end_define

begin_comment
comment|/* Write by group. */
end_comment

begin_define
define|#
directive|define
name|C_IXGRP
value|0000010
end_define

begin_comment
comment|/* Execute by group. */
end_comment

begin_define
define|#
directive|define
name|C_IROTH
value|0000004
end_define

begin_comment
comment|/* Read by others. */
end_comment

begin_define
define|#
directive|define
name|C_IWOTH
value|0000002
end_define

begin_comment
comment|/* Write by others. */
end_comment

begin_define
define|#
directive|define
name|C_IXOTH
value|0000001
end_define

begin_comment
comment|/* Execute by others. */
end_comment

begin_define
define|#
directive|define
name|MAGIC
value|"070707"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _CPIO_H_ */
end_comment

end_unit

