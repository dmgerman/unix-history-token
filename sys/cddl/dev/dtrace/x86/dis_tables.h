begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * CDDL HEADER START  *  * The contents of this file are subject to the terms of the  * Common Development and Distribution License (the "License").  * You may not use this file except in compliance with the License.  *  * You can obtain a copy of the license at usr/src/OPENSOLARIS.LICENSE  * or http://www.opensolaris.org/os/licensing.  * See the License for the specific language governing permissions  * and limitations under the License.  *  * When distributing Covered Code, include this CDDL HEADER in each  * file and include the License file at usr/src/OPENSOLARIS.LICENSE.  * If applicable, add the following below this CDDL HEADER, with the  * fields enclosed by brackets "[]" replaced with your own identifying  * information: Portions Copyright [yyyy] [name of copyright owner]  *  * CDDL HEADER END  */
end_comment

begin_comment
comment|/*  * Copyright 2009 Sun Microsystems, Inc.  All rights reserved.  * Use is subject to license terms.  */
end_comment

begin_comment
comment|/*	Copyright (c) 1988 AT&T	*/
end_comment

begin_comment
comment|/*	  All Rights Reserved  	*/
end_comment

begin_comment
comment|/*  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_DIS_TABLES_H
end_ifndef

begin_define
define|#
directive|define
name|_DIS_TABLES_H
end_define

begin_comment
comment|/*  * Constants and prototypes for the IA32 disassembler backend.  See dis_tables.c  * for usage information and documentation.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|__cplusplus
end_ifdef

begin_extern
extern|extern
literal|"C"
block|{
endif|#
directive|endif
include|#
directive|include
file|<sys/types.h>
include|#
directive|include
file|<sys/param.h>
comment|/*  * values for cpu mode  */
define|#
directive|define
name|SIZE16
value|1
define|#
directive|define
name|SIZE32
value|2
define|#
directive|define
name|SIZE64
value|3
define|#
directive|define
name|OPLEN
value|256
define|#
directive|define
name|PFIXLEN
value|8
define|#
directive|define
name|NCPS
value|20
comment|/* number of chars per symbol	*/
comment|/*  * data structures that must be provided to dtrace_dis86()  */
typedef|typedef
struct|struct
name|d86opnd
block|{
name|char
name|d86_opnd
index|[
name|OPLEN
index|]
decl_stmt|;
comment|/* symbolic rep of operand */
name|char
name|d86_prefix
index|[
name|PFIXLEN
index|]
decl_stmt|;
comment|/* any prefix string or "" */
name|uint_t
name|d86_mode
decl_stmt|;
comment|/* mode for immediate */
name|uint_t
name|d86_value_size
decl_stmt|;
comment|/* size in bytes of d86_value */
name|uint64_t
name|d86_value
decl_stmt|;
comment|/* immediate value of opnd */
block|}
name|d86opnd_t
typedef|;
typedef|typedef
struct|struct
name|dis86
block|{
name|uint_t
name|d86_mode
decl_stmt|;
name|uint_t
name|d86_error
decl_stmt|;
name|uint_t
name|d86_len
decl_stmt|;
comment|/* instruction length */
name|int
name|d86_rmindex
decl_stmt|;
comment|/* index of modrm byte or -1 */
name|uint_t
name|d86_memsize
decl_stmt|;
comment|/* size of memory referenced */
name|char
name|d86_bytes
index|[
literal|16
index|]
decl_stmt|;
comment|/* bytes of instruction */
name|char
name|d86_mnem
index|[
name|OPLEN
index|]
decl_stmt|;
name|uint_t
name|d86_numopnds
decl_stmt|;
name|uint_t
name|d86_rex_prefix
decl_stmt|;
comment|/* value of REX prefix if !0 */
name|char
modifier|*
name|d86_seg_prefix
decl_stmt|;
comment|/* segment prefix, if any */
name|uint_t
name|d86_opnd_size
decl_stmt|;
name|uint_t
name|d86_addr_size
decl_stmt|;
name|uint_t
name|d86_got_modrm
decl_stmt|;
name|struct
name|d86opnd
name|d86_opnd
index|[
literal|4
index|]
decl_stmt|;
comment|/* up to 4 operands */
name|int
function_decl|(
modifier|*
name|d86_check_func
function_decl|)
parameter_list|(
name|void
modifier|*
parameter_list|)
function_decl|;
name|int
function_decl|(
modifier|*
name|d86_get_byte
function_decl|)
parameter_list|(
name|void
modifier|*
parameter_list|)
function_decl|;
ifdef|#
directive|ifdef
name|DIS_TEXT
name|int
function_decl|(
modifier|*
name|d86_sym_lookup
function_decl|)
parameter_list|(
name|void
modifier|*
parameter_list|,
name|uint64_t
parameter_list|,
name|char
modifier|*
parameter_list|,
name|size_t
parameter_list|)
function_decl|;
name|int
function_decl|(
modifier|*
name|d86_sprintf_func
function_decl|)
parameter_list|(
name|char
modifier|*
parameter_list|,
name|size_t
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
modifier|...
parameter_list|)
function_decl|;
name|int
name|d86_flags
decl_stmt|;
name|uint_t
name|d86_imm_bytes
decl_stmt|;
endif|#
directive|endif
name|void
modifier|*
name|d86_data
decl_stmt|;
block|}
name|dis86_t
typedef|;
specifier|extern
name|int
name|dtrace_disx86
parameter_list|(
name|dis86_t
modifier|*
name|x
parameter_list|,
name|uint_t
name|cpu_mode
parameter_list|)
function_decl|;
define|#
directive|define
name|DIS_F_OCTAL
value|0x1
comment|/* Print all numbers in octal */
define|#
directive|define
name|DIS_F_NOIMMSYM
value|0x2
comment|/* Don't print symbols for immediates (.o) */
ifdef|#
directive|ifdef
name|DIS_TEXT
specifier|extern
name|void
name|dtrace_disx86_str
parameter_list|(
name|dis86_t
modifier|*
name|x
parameter_list|,
name|uint_t
name|cpu_mode
parameter_list|,
name|uint64_t
name|pc
parameter_list|,
name|char
modifier|*
name|buf
parameter_list|,
name|size_t
name|len
parameter_list|)
function_decl|;
endif|#
directive|endif
ifdef|#
directive|ifdef
name|__cplusplus
block|}
end_extern

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _DIS_TABLES_H */
end_comment

end_unit

