begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $NetBSD: cfe_error.h,v 1.2 2003/02/07 17:38:48 cgd Exp $ */
end_comment

begin_comment
comment|/* from: SiByte Id: cfe_error.h,v 1.2 2002/07/09 19:37:52 cgd Exp $ */
end_comment

begin_comment
comment|/*-  * Copyright 2000, 2001, 2002  * Broadcom Corporation. All rights reserved.  *  * This software is furnished under license and may be used and copied only  * in accordance with the following terms and conditions.  Subject to these  * conditions, you may download, copy, install, use, modify and distribute  * modified or unmodified copies of this software in source and/or binary  * form. No title or ownership is transferred hereby.  *  * 1) Any source code used, modified or distributed must reproduce and  *    retain this copyright notice and list of conditions as they appear in  *    the source file.  *  * 2) No right is granted to use any trade name, trademark, or logo of  *    Broadcom Corporation.  The "Broadcom Corporation" name may not be  *    used to endorse or promote products derived from this software  *    without the prior written permission of Broadcom Corporation.  *  * 3) THIS SOFTWARE IS PROVIDED "AS-IS" AND ANY EXPRESS OR IMPLIED  *    WARRANTIES, INCLUDING BUT NOT LIMITED TO, ANY IMPLIED WARRANTIES OF  *    MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE, OR  *    NON-INFRINGEMENT ARE DISCLAIMED. IN NO EVENT SHALL BROADCOM BE LIABLE  *    FOR ANY DAMAGES WHATSOEVER, AND IN PARTICULAR, BROADCOM SHALL NOT BE  *    LIABLE FOR DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR  *    CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF  *    SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR  *    BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,  *    WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE  *    OR OTHERWISE), EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_comment
comment|/*  *********************************************************************     *       *  Broadcom Common Firmware Environment (CFE)     *       *  Error codes				File: cfe_error.h     *       *  CFE's global error code list is here.     *       *  Author:  Mitch Lichtenberg     *       ********************************************************************* */
end_comment

begin_define
define|#
directive|define
name|CFE_OK
value|0
end_define

begin_define
define|#
directive|define
name|CFE_ERR
value|-1
end_define

begin_comment
comment|/* generic error */
end_comment

begin_define
define|#
directive|define
name|CFE_ERR_INV_COMMAND
value|-2
end_define

begin_define
define|#
directive|define
name|CFE_ERR_EOF
value|-3
end_define

begin_define
define|#
directive|define
name|CFE_ERR_IOERR
value|-4
end_define

begin_define
define|#
directive|define
name|CFE_ERR_NOMEM
value|-5
end_define

begin_define
define|#
directive|define
name|CFE_ERR_DEVNOTFOUND
value|-6
end_define

begin_define
define|#
directive|define
name|CFE_ERR_DEVOPEN
value|-7
end_define

begin_define
define|#
directive|define
name|CFE_ERR_INV_PARAM
value|-8
end_define

begin_define
define|#
directive|define
name|CFE_ERR_ENVNOTFOUND
value|-9
end_define

begin_define
define|#
directive|define
name|CFE_ERR_ENVREADONLY
value|-10
end_define

begin_define
define|#
directive|define
name|CFE_ERR_NOTELF
value|-11
end_define

begin_define
define|#
directive|define
name|CFE_ERR_NOT32BIT
value|-12
end_define

begin_define
define|#
directive|define
name|CFE_ERR_WRONGENDIAN
value|-13
end_define

begin_define
define|#
directive|define
name|CFE_ERR_BADELFVERS
value|-14
end_define

begin_define
define|#
directive|define
name|CFE_ERR_NOTMIPS
value|-15
end_define

begin_define
define|#
directive|define
name|CFE_ERR_BADELFFMT
value|-16
end_define

begin_define
define|#
directive|define
name|CFE_ERR_BADADDR
value|-17
end_define

begin_define
define|#
directive|define
name|CFE_ERR_FILENOTFOUND
value|-18
end_define

begin_define
define|#
directive|define
name|CFE_ERR_UNSUPPORTED
value|-19
end_define

begin_define
define|#
directive|define
name|CFE_ERR_HOSTUNKNOWN
value|-20
end_define

begin_define
define|#
directive|define
name|CFE_ERR_TIMEOUT
value|-21
end_define

begin_define
define|#
directive|define
name|CFE_ERR_PROTOCOLERR
value|-22
end_define

begin_define
define|#
directive|define
name|CFE_ERR_NETDOWN
value|-23
end_define

begin_define
define|#
directive|define
name|CFE_ERR_NONAMESERVER
value|-24
end_define

begin_define
define|#
directive|define
name|CFE_ERR_NOHANDLES
value|-25
end_define

begin_define
define|#
directive|define
name|CFE_ERR_ALREADYBOUND
value|-26
end_define

begin_define
define|#
directive|define
name|CFE_ERR_CANNOTSET
value|-27
end_define

begin_define
define|#
directive|define
name|CFE_ERR_NOMORE
value|-28
end_define

begin_define
define|#
directive|define
name|CFE_ERR_BADFILESYS
value|-29
end_define

begin_define
define|#
directive|define
name|CFE_ERR_FSNOTAVAIL
value|-30
end_define

begin_define
define|#
directive|define
name|CFE_ERR_INVBOOTBLOCK
value|-31
end_define

begin_define
define|#
directive|define
name|CFE_ERR_WRONGDEVTYPE
value|-32
end_define

begin_define
define|#
directive|define
name|CFE_ERR_BBCHECKSUM
value|-33
end_define

begin_define
define|#
directive|define
name|CFE_ERR_BOOTPROGCHKSUM
value|-34
end_define

begin_define
define|#
directive|define
name|CFE_ERR_LDRNOTAVAIL
value|-35
end_define

begin_define
define|#
directive|define
name|CFE_ERR_NOTREADY
value|-36
end_define

begin_define
define|#
directive|define
name|CFE_ERR_GETMEM
value|-37
end_define

begin_define
define|#
directive|define
name|CFE_ERR_SETMEM
value|-38
end_define

begin_define
define|#
directive|define
name|CFE_ERR_NOTCONN
value|-39
end_define

begin_define
define|#
directive|define
name|CFE_ERR_ADDRINUSE
value|-40
end_define

end_unit

