begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * CDDL HEADER START  *  * The contents of this file are subject to the terms of the  * Common Development and Distribution License, Version 1.0 only  * (the "License").  You may not use this file except in compliance  * with the License.  *  * You can obtain a copy of the license at usr/src/OPENSOLARIS.LICENSE  * or http://www.opensolaris.org/os/licensing.  * See the License for the specific language governing permissions  * and limitations under the License.  *  * When distributing Covered Code, include this CDDL HEADER in each  * file and include the License file at usr/src/OPENSOLARIS.LICENSE.  * If applicable, add the following below this CDDL HEADER, with the  * fields enclosed by brackets "[]" replaced with your own identifying  * information: Portions Copyright [yyyy] [name of copyright owner]  *  * CDDL HEADER END  */
end_comment

begin_comment
comment|/*  * Copyright 2005 Sun Microsystems, Inc.  All rights reserved.  * Use is subject to license terms.  */
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
comment|/*  * This is our reserved trap instruction: ta 0x38  */
define|#
directive|define
name|FASTTRAP_INSTR
value|0x91d02038
define|#
directive|define
name|FASTTRAP_SUNWDTRACE_SIZE
value|128
typedef|typedef
name|uint32_t
name|fasttrap_instr_t
typedef|;
typedef|typedef
struct|struct
name|fasttrap_machtp
block|{
name|fasttrap_instr_t
name|ftmt_instr
decl_stmt|;
comment|/* original instruction */
name|uintptr_t
name|ftmt_dest
decl_stmt|;
comment|/* destination of DCTI */
name|uint8_t
name|ftmt_type
decl_stmt|;
comment|/* emulation type */
name|uint8_t
name|ftmt_flags
decl_stmt|;
comment|/* emulation flags */
name|uint8_t
name|ftmt_cc
decl_stmt|;
comment|/* which cc to look at */
name|uint8_t
name|ftmt_code
decl_stmt|;
comment|/* branch condition */
block|}
name|fasttrap_machtp_t
typedef|;
define|#
directive|define
name|ftt_instr
value|ftt_mtp.ftmt_instr
define|#
directive|define
name|ftt_dest
value|ftt_mtp.ftmt_dest
define|#
directive|define
name|ftt_type
value|ftt_mtp.ftmt_type
define|#
directive|define
name|ftt_flags
value|ftt_mtp.ftmt_flags
define|#
directive|define
name|ftt_cc
value|ftt_mtp.ftmt_cc
define|#
directive|define
name|ftt_code
value|ftt_mtp.ftmt_code
define|#
directive|define
name|FASTTRAP_T_COMMON
value|0x00
comment|/* common case -- no emulation */
define|#
directive|define
name|FASTTRAP_T_CCR
value|0x01
comment|/* integer condition code branch */
define|#
directive|define
name|FASTTRAP_T_FCC
value|0x02
comment|/* floating-point branch */
define|#
directive|define
name|FASTTRAP_T_REG
value|0x03
comment|/* register predicated branch */
define|#
directive|define
name|FASTTRAP_T_ALWAYS
value|0x04
comment|/* branch always */
define|#
directive|define
name|FASTTRAP_T_CALL
value|0x05
comment|/* call instruction */
define|#
directive|define
name|FASTTRAP_T_JMPL
value|0x06
comment|/* jmpl instruction */
define|#
directive|define
name|FASTTRAP_T_RDPC
value|0x07
comment|/* rdpc instruction */
define|#
directive|define
name|FASTTRAP_T_RETURN
value|0x08
comment|/* return instruction */
comment|/*  * For performance rather than correctness.  */
define|#
directive|define
name|FASTTRAP_T_SAVE
value|0x10
comment|/* save instruction (func entry only) */
define|#
directive|define
name|FASTTRAP_T_RESTORE
value|0x11
comment|/* restore instruction */
define|#
directive|define
name|FASTTRAP_T_OR
value|0x12
comment|/* mov instruction */
define|#
directive|define
name|FASTTRAP_T_SETHI
value|0x13
comment|/* sethi instruction (includes nop) */
define|#
directive|define
name|FASTTRAP_F_ANNUL
value|0x01
comment|/* branch is annulled */
define|#
directive|define
name|FASTTRAP_F_RETMAYBE
value|0x02
comment|/* not definitely a return site */
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

