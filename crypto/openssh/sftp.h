begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$OpenBSD: sftp.h,v 1.3 2001/03/07 10:11:23 djm Exp $	*/
end_comment

begin_comment
comment|/*  * Copyright (c) 2001 Markus Friedl.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  */
end_comment

begin_comment
comment|/*  * draft-ietf-secsh-filexfer-01.txt  */
end_comment

begin_comment
comment|/* version */
end_comment

begin_define
define|#
directive|define
name|SSH2_FILEXFER_VERSION
value|3
end_define

begin_comment
comment|/* client to server */
end_comment

begin_define
define|#
directive|define
name|SSH2_FXP_INIT
value|1
end_define

begin_define
define|#
directive|define
name|SSH2_FXP_OPEN
value|3
end_define

begin_define
define|#
directive|define
name|SSH2_FXP_CLOSE
value|4
end_define

begin_define
define|#
directive|define
name|SSH2_FXP_READ
value|5
end_define

begin_define
define|#
directive|define
name|SSH2_FXP_WRITE
value|6
end_define

begin_define
define|#
directive|define
name|SSH2_FXP_LSTAT
value|7
end_define

begin_define
define|#
directive|define
name|SSH2_FXP_FSTAT
value|8
end_define

begin_define
define|#
directive|define
name|SSH2_FXP_SETSTAT
value|9
end_define

begin_define
define|#
directive|define
name|SSH2_FXP_FSETSTAT
value|10
end_define

begin_define
define|#
directive|define
name|SSH2_FXP_OPENDIR
value|11
end_define

begin_define
define|#
directive|define
name|SSH2_FXP_READDIR
value|12
end_define

begin_define
define|#
directive|define
name|SSH2_FXP_REMOVE
value|13
end_define

begin_define
define|#
directive|define
name|SSH2_FXP_MKDIR
value|14
end_define

begin_define
define|#
directive|define
name|SSH2_FXP_RMDIR
value|15
end_define

begin_define
define|#
directive|define
name|SSH2_FXP_REALPATH
value|16
end_define

begin_define
define|#
directive|define
name|SSH2_FXP_STAT
value|17
end_define

begin_define
define|#
directive|define
name|SSH2_FXP_RENAME
value|18
end_define

begin_define
define|#
directive|define
name|SSH2_FXP_READLINK
value|19
end_define

begin_define
define|#
directive|define
name|SSH2_FXP_SYMLINK
value|20
end_define

begin_comment
comment|/* server to client */
end_comment

begin_define
define|#
directive|define
name|SSH2_FXP_VERSION
value|2
end_define

begin_define
define|#
directive|define
name|SSH2_FXP_STATUS
value|101
end_define

begin_define
define|#
directive|define
name|SSH2_FXP_HANDLE
value|102
end_define

begin_define
define|#
directive|define
name|SSH2_FXP_DATA
value|103
end_define

begin_define
define|#
directive|define
name|SSH2_FXP_NAME
value|104
end_define

begin_define
define|#
directive|define
name|SSH2_FXP_ATTRS
value|105
end_define

begin_define
define|#
directive|define
name|SSH2_FXP_EXTENDED
value|200
end_define

begin_define
define|#
directive|define
name|SSH2_FXP_EXTENDED_REPLY
value|201
end_define

begin_comment
comment|/* attributes */
end_comment

begin_define
define|#
directive|define
name|SSH2_FILEXFER_ATTR_SIZE
value|0x00000001
end_define

begin_define
define|#
directive|define
name|SSH2_FILEXFER_ATTR_UIDGID
value|0x00000002
end_define

begin_define
define|#
directive|define
name|SSH2_FILEXFER_ATTR_PERMISSIONS
value|0x00000004
end_define

begin_define
define|#
directive|define
name|SSH2_FILEXFER_ATTR_ACMODTIME
value|0x00000008
end_define

begin_define
define|#
directive|define
name|SSH2_FILEXFER_ATTR_EXTENDED
value|0x80000000
end_define

begin_comment
comment|/* portable open modes */
end_comment

begin_define
define|#
directive|define
name|SSH2_FXF_READ
value|0x00000001
end_define

begin_define
define|#
directive|define
name|SSH2_FXF_WRITE
value|0x00000002
end_define

begin_define
define|#
directive|define
name|SSH2_FXF_APPEND
value|0x00000004
end_define

begin_define
define|#
directive|define
name|SSH2_FXF_CREAT
value|0x00000008
end_define

begin_define
define|#
directive|define
name|SSH2_FXF_TRUNC
value|0x00000010
end_define

begin_define
define|#
directive|define
name|SSH2_FXF_EXCL
value|0x00000020
end_define

begin_comment
comment|/* status messages */
end_comment

begin_define
define|#
directive|define
name|SSH2_FX_OK
value|0
end_define

begin_define
define|#
directive|define
name|SSH2_FX_EOF
value|1
end_define

begin_define
define|#
directive|define
name|SSH2_FX_NO_SUCH_FILE
value|2
end_define

begin_define
define|#
directive|define
name|SSH2_FX_PERMISSION_DENIED
value|3
end_define

begin_define
define|#
directive|define
name|SSH2_FX_FAILURE
value|4
end_define

begin_define
define|#
directive|define
name|SSH2_FX_BAD_MESSAGE
value|5
end_define

begin_define
define|#
directive|define
name|SSH2_FX_NO_CONNECTION
value|6
end_define

begin_define
define|#
directive|define
name|SSH2_FX_CONNECTION_LOST
value|7
end_define

begin_define
define|#
directive|define
name|SSH2_FX_OP_UNSUPPORTED
value|8
end_define

begin_define
define|#
directive|define
name|SSH2_FX_MAX
value|8
end_define

end_unit

