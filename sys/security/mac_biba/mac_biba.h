begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1999, 2000, 2001, 2002 Robert N. M. Watson  * Copyright (c) 2001, 2002 Networks Associates Technology, Inc.  * All rights reserved.  *  * This software was developed by Robert Watson for the TrustedBSD Project.  *  * This software was developed for the FreeBSD Project in part by NAI Labs,  * the Security Research Division of Network Associates, Inc. under  * DARPA/SPAWAR contract N66001-01-C-8035 ("CBOSS"), as part of the DARPA  * CHATS research program.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. The names of the authors may not be used to endorse or promote  *    products derived from this software without specific prior written  *    permission.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_comment
comment|/*  * Definitions for the TrustedBSD Biba integrity policy module.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_SYS_SECURITY_MAC_BIBA_H
end_ifndef

begin_define
define|#
directive|define
name|_SYS_SECURITY_MAC_BIBA_H
end_define

begin_define
define|#
directive|define
name|MAC_BIBA_EXTATTR_NAMESPACE
value|EXTATTR_NAMESPACE_SYSTEM
end_define

begin_define
define|#
directive|define
name|MAC_BIBA_EXTATTR_NAME
value|"mac_biba"
end_define

begin_define
define|#
directive|define
name|MAC_BIBA_FLAG_SINGLE
value|0x00000001
end_define

begin_comment
comment|/* mb_single initialized */
end_comment

begin_define
define|#
directive|define
name|MAC_BIBA_FLAG_RANGE
value|0x00000002
end_define

begin_comment
comment|/* mb_range* initialized */
end_comment

begin_define
define|#
directive|define
name|MAC_BIBA_FLAGS_BOTH
value|(MAC_BIBA_FLAG_SINGLE | MAC_BIBA_FLAG_RANGE)
end_define

begin_define
define|#
directive|define
name|MAC_BIBA_TYPE_UNDEF
value|0
end_define

begin_comment
comment|/* Undefined */
end_comment

begin_define
define|#
directive|define
name|MAC_BIBA_TYPE_GRADE
value|1
end_define

begin_comment
comment|/* Hierarchal grade with mb_grade. */
end_comment

begin_define
define|#
directive|define
name|MAC_BIBA_TYPE_LOW
value|2
end_define

begin_comment
comment|/* Dominated by any 					 * MAC_BIBA_TYPE_LABEL. */
end_comment

begin_define
define|#
directive|define
name|MAC_BIBA_TYPE_HIGH
value|3
end_define

begin_comment
comment|/* Dominates any 					 * MAC_BIBA_TYPE_LABEL. */
end_comment

begin_define
define|#
directive|define
name|MAC_BIBA_TYPE_EQUAL
value|4
end_define

begin_comment
comment|/* Equivilent to any 					 * MAC_BIBA_TYPE_LABEL. */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_SYS_SECURITY_MAC_BIBA_H */
end_comment

end_unit

