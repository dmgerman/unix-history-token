begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * CDDL HEADER START  *  * The contents of this file are subject to the terms of the  * Common Development and Distribution License (the "License").  * You may not use this file except in compliance with the License.  *  * You can obtain a copy of the license at usr/src/OPENSOLARIS.LICENSE  * or http://www.opensolaris.org/os/licensing.  * See the License for the specific language governing permissions  * and limitations under the License.  *  * When distributing Covered Code, include this CDDL HEADER in each  * file and include the License file at usr/src/OPENSOLARIS.LICENSE.  * If applicable, add the following below this CDDL HEADER, with the  * fields enclosed by brackets "[]" replaced with your own identifying  * information: Portions Copyright [yyyy] [name of copyright owner]  *  * CDDL HEADER END  */
end_comment

begin_comment
comment|/*  * Copyright 2006 Sun Microsystems, Inc.  All rights reserved.  * Use is subject to license terms.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_FASTTRAP_ISA_H
end_ifndef

begin_define
define|#
directive|define
name|_FASTTRAP_ISA_H
end_define

begin_pragma
pragma|#
directive|pragma
name|ident
literal|"%Z%%M%	%I%	%E% SMI"
end_pragma

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

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
define|#
directive|define
name|FASTTRAP_MAX_INSTR_SIZE
value|15
define|#
directive|define
name|FASTTRAP_INSTR
value|0xcc
define|#
directive|define
name|FASTTRAP_SUNWDTRACE_SIZE
value|64
typedef|typedef
name|uint8_t
name|fasttrap_instr_t
typedef|;
typedef|typedef
struct|struct
name|fasttrap_machtp
block|{
name|uint8_t
name|ftmt_instr
index|[
name|FASTTRAP_MAX_INSTR_SIZE
index|]
decl_stmt|;
comment|/* orig. instr. */
name|uint8_t
name|ftmt_size
decl_stmt|;
comment|/* instruction size */
ifdef|#
directive|ifdef
name|__amd64
name|uint8_t
name|ftmt_ripmode
decl_stmt|;
comment|/* %rip-relative handling mode */
name|uint8_t
name|ftmt_modrm
decl_stmt|;
comment|/* saved modrm byte */
endif|#
directive|endif
name|uint8_t
name|ftmt_type
decl_stmt|;
comment|/* emulation type */
name|uint8_t
name|ftmt_code
decl_stmt|;
comment|/* branch condition */
name|uint8_t
name|ftmt_base
decl_stmt|;
comment|/* branch base */
name|uint8_t
name|ftmt_index
decl_stmt|;
comment|/* branch index */
name|uint8_t
name|ftmt_scale
decl_stmt|;
comment|/* branch scale */
name|uint8_t
name|ftmt_segment
decl_stmt|;
comment|/* segment for memory accesses */
name|uintptr_t
name|ftmt_dest
decl_stmt|;
comment|/* destination of control flow */
block|}
name|fasttrap_machtp_t
typedef|;
define|#
directive|define
name|ftt_instr
value|ftt_mtp.ftmt_instr
ifdef|#
directive|ifdef
name|__amd64
define|#
directive|define
name|ftt_ripmode
value|ftt_mtp.ftmt_ripmode
define|#
directive|define
name|ftt_modrm
value|ftt_mtp.ftmt_modrm
endif|#
directive|endif
define|#
directive|define
name|ftt_size
value|ftt_mtp.ftmt_size
define|#
directive|define
name|ftt_type
value|ftt_mtp.ftmt_type
define|#
directive|define
name|ftt_code
value|ftt_mtp.ftmt_code
define|#
directive|define
name|ftt_base
value|ftt_mtp.ftmt_base
define|#
directive|define
name|ftt_index
value|ftt_mtp.ftmt_index
define|#
directive|define
name|ftt_scale
value|ftt_mtp.ftmt_scale
define|#
directive|define
name|ftt_segment
value|ftt_mtp.ftmt_segment
define|#
directive|define
name|ftt_dest
value|ftt_mtp.ftmt_dest
define|#
directive|define
name|FASTTRAP_T_COMMON
value|0x00
comment|/* common case -- no emulation */
define|#
directive|define
name|FASTTRAP_T_JCC
value|0x01
comment|/* near and far conditional jumps */
define|#
directive|define
name|FASTTRAP_T_LOOP
value|0x02
comment|/* loop instructions */
define|#
directive|define
name|FASTTRAP_T_JCXZ
value|0x03
comment|/* jump if %ecx/%rcx is zero */
define|#
directive|define
name|FASTTRAP_T_JMP
value|0x04
comment|/* relative jump */
define|#
directive|define
name|FASTTRAP_T_CALL
value|0x05
comment|/* near call (and link) */
define|#
directive|define
name|FASTTRAP_T_RET
value|0x06
comment|/* ret */
define|#
directive|define
name|FASTTRAP_T_RET16
value|0x07
comment|/* ret<imm16> */
comment|/*  * For performance rather than correctness.  */
define|#
directive|define
name|FASTTRAP_T_PUSHL_EBP
value|0x10
comment|/* pushl %ebp (for function entry) */
define|#
directive|define
name|FASTTRAP_T_NOP
value|0x11
comment|/* nop */
define|#
directive|define
name|FASTTRAP_RIP_1
value|0x1
define|#
directive|define
name|FASTTRAP_RIP_2
value|0x2
define|#
directive|define
name|FASTTRAP_RIP_X
value|0x4
comment|/*  * Segment values.  */
define|#
directive|define
name|FASTTRAP_SEG_NONE
value|0
define|#
directive|define
name|FASTTRAP_SEG_CS
value|1
define|#
directive|define
name|FASTTRAP_SEG_DS
value|2
define|#
directive|define
name|FASTTRAP_SEG_ES
value|3
define|#
directive|define
name|FASTTRAP_SEG_FS
value|4
define|#
directive|define
name|FASTTRAP_SEG_GS
value|5
define|#
directive|define
name|FASTTRAP_SEG_SS
value|6
define|#
directive|define
name|FASTTRAP_AFRAMES
value|3
define|#
directive|define
name|FASTTRAP_RETURN_AFRAMES
value|4
define|#
directive|define
name|FASTTRAP_ENTRY_AFRAMES
value|3
define|#
directive|define
name|FASTTRAP_OFFSET_AFRAMES
value|3
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
comment|/* _FASTTRAP_ISA_H */
end_comment

end_unit

