begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1999-2002 Robert N. M. Watson  * Copyright (c) 2001-2002 Networks Associates Technology, Inc.  * All rights reserved.  *  * This software was developed by Robert Watson for the TrustedBSD Project.  *  * This software was developed for the FreeBSD Project in part by Network  * Associates Laboratories, the Security Research Division of Network  * Associates, Inc. under DARPA/SPAWAR contract N66001-01-C-8035 ("CBOSS"),  * as part of the DARPA CHATS research program.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
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
name|MAC_BIBA_LABEL_NAME
value|"biba"
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

begin_comment
comment|/*  * Structures and constants associated with a Biba Integrity policy.  * mac_biba represents a Biba label, with mb_type determining its properties,  * and mb_grade represents the hierarchal grade if valid for the current  * mb_type.  */
end_comment

begin_define
define|#
directive|define
name|MAC_BIBA_MAX_COMPARTMENTS
value|256
end_define

begin_struct
struct|struct
name|mac_biba_element
block|{
name|u_short
name|mbe_type
decl_stmt|;
name|u_short
name|mbe_grade
decl_stmt|;
name|u_char
name|mbe_compartments
index|[
name|MAC_BIBA_MAX_COMPARTMENTS
operator|>>
literal|3
index|]
expr_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * Biba labels consist of two components: a single label, and a label  * range.  Depending on the context, one or both may be used; the mb_flags  * field permits the provider to indicate what fields are intended for  * use.  */
end_comment

begin_struct
struct|struct
name|mac_biba
block|{
name|int
name|mb_flags
decl_stmt|;
name|struct
name|mac_biba_element
name|mb_single
decl_stmt|;
name|struct
name|mac_biba_element
name|mb_rangelow
decl_stmt|,
name|mb_rangehigh
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * Biba compartments bit test/set macros.  * The range is 1 to MAC_BIBA_MAX_COMPARTMENTS.  */
end_comment

begin_define
define|#
directive|define
name|MAC_BIBA_BIT_TEST
parameter_list|(
name|b
parameter_list|,
name|w
parameter_list|)
define|\
value|((w)[(((b) - 1)>> 3)]& (1<< (((b) - 1)& 7)))
end_define

begin_define
define|#
directive|define
name|MAC_BIBA_BIT_SET
parameter_list|(
name|b
parameter_list|,
name|w
parameter_list|)
define|\
value|((w)[(((b) - 1)>> 3)] |= (1<< (((b) - 1)& 7)))
end_define

begin_define
define|#
directive|define
name|MAC_BIBA_BIT_SET_EMPTY
parameter_list|(
name|set
parameter_list|)
value|biba_bit_set_empty(set)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_SYS_SECURITY_MAC_BIBA_H */
end_comment

end_unit

