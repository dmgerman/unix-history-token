begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1999-2002 Robert N. M. Watson  * Copyright (c) 2001-2002 Networks Associates Technology, Inc.  * All rights reserved.  *  * This software was developed by Robert Watson for the TrustedBSD Project.  *  * This software was developed for the FreeBSD Project in part by NAI Labs,  * the Security Research Division of Network Associates, Inc. under  * DARPA/SPAWAR contract N66001-01-C-8035 ("CBOSS"), as part of the DARPA  * CHATS research program.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_comment
comment|/*  * Definitions for the TrustedBSD LOMAC integrity policy module.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_SYS_SECURITY_MAC_LOMAC_H
end_ifndef

begin_define
define|#
directive|define
name|_SYS_SECURITY_MAC_LOMAC_H
end_define

begin_define
define|#
directive|define
name|MAC_LOMAC_EXTATTR_NAMESPACE
value|EXTATTR_NAMESPACE_SYSTEM
end_define

begin_define
define|#
directive|define
name|MAC_LOMAC_EXTATTR_NAME
value|"mac_lomac"
end_define

begin_define
define|#
directive|define
name|MAC_LOMAC_LABEL_NAME
value|"lomac"
end_define

begin_define
define|#
directive|define
name|MAC_LOMAC_FLAG_SINGLE
value|0x00000001
end_define

begin_comment
comment|/* ml_single initialized */
end_comment

begin_define
define|#
directive|define
name|MAC_LOMAC_FLAG_RANGE
value|0x00000002
end_define

begin_comment
comment|/* ml_range* initialized */
end_comment

begin_define
define|#
directive|define
name|MAC_LOMAC_FLAG_AUX
value|0x00000004
end_define

begin_comment
comment|/* ml_auxsingle initialized */
end_comment

begin_define
define|#
directive|define
name|MAC_LOMAC_FLAGS_BOTH
value|(MAC_LOMAC_FLAG_SINGLE | MAC_LOMAC_FLAG_RANGE)
end_define

begin_define
define|#
directive|define
name|MAC_LOMAC_FLAG_UPDATE
value|0x00000008
end_define

begin_comment
comment|/* must demote this process */
end_comment

begin_define
define|#
directive|define
name|MAC_LOMAC_TYPE_UNDEF
value|0
end_define

begin_comment
comment|/* Undefined */
end_comment

begin_define
define|#
directive|define
name|MAC_LOMAC_TYPE_GRADE
value|1
end_define

begin_comment
comment|/* Hierarchal grade with mb_grade. */
end_comment

begin_define
define|#
directive|define
name|MAC_LOMAC_TYPE_LOW
value|2
end_define

begin_comment
comment|/* Dominated by any 					 * MAC_LOMAC_TYPE_LABEL. */
end_comment

begin_define
define|#
directive|define
name|MAC_LOMAC_TYPE_HIGH
value|3
end_define

begin_comment
comment|/* Dominates any 					 * MAC_LOMAC_TYPE_LABEL. */
end_comment

begin_define
define|#
directive|define
name|MAC_LOMAC_TYPE_EQUAL
value|4
end_define

begin_comment
comment|/* Equivilent to any 					 * MAC_LOMAC_TYPE_LABEL. */
end_comment

begin_comment
comment|/*  * Structures and constants associated with a LOMAC Integrity policy.  * mac_lomac represents a LOMAC label, with mb_type determining its properties,  * and mb_grade represents the hierarchal grade if valid for the current  * mb_type.  */
end_comment

begin_struct
struct|struct
name|mac_lomac_element
block|{
name|u_short
name|mle_type
decl_stmt|;
name|u_short
name|mle_grade
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * LOMAC labels start with two components: a single label, and a label  * range.  Depending on the context, one or both may be used; the ml_flags  * field permits the provider to indicate what fields are intended for  * use.  The auxiliary label works the same way, but is only valid on  * filesystem objects to provide inheritance semantics on directories  * and "non-demoting" execution on executable files.  */
end_comment

begin_struct
struct|struct
name|mac_lomac
block|{
name|int
name|ml_flags
decl_stmt|;
name|struct
name|mac_lomac_element
name|ml_single
decl_stmt|;
name|struct
name|mac_lomac_element
name|ml_rangelow
decl_stmt|,
name|ml_rangehigh
decl_stmt|;
name|struct
name|mac_lomac_element
name|ml_auxsingle
decl_stmt|;
block|}
struct|;
end_struct

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_SYS_SECURITY_MAC_LOMAC_H */
end_comment

end_unit

