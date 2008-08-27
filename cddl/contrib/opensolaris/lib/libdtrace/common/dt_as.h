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
name|_DT_AS_H
end_ifndef

begin_define
define|#
directive|define
name|_DT_AS_H
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

begin_include
include|#
directive|include
file|<sys/dtrace.h>
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
typedef|typedef
struct|struct
name|dt_irnode
block|{
name|uint_t
name|di_label
decl_stmt|;
comment|/* label number or DT_LBL_NONE */
name|dif_instr_t
name|di_instr
decl_stmt|;
comment|/* instruction opcode */
name|void
modifier|*
name|di_extern
decl_stmt|;
comment|/* opcode-specific external reference */
name|struct
name|dt_irnode
modifier|*
name|di_next
decl_stmt|;
comment|/* next instruction */
block|}
name|dt_irnode_t
typedef|;
define|#
directive|define
name|DT_LBL_NONE
value|0
comment|/* no label on this instruction */
typedef|typedef
struct|struct
name|dt_irlist
block|{
name|dt_irnode_t
modifier|*
name|dl_list
decl_stmt|;
comment|/* pointer to first node in list */
name|dt_irnode_t
modifier|*
name|dl_last
decl_stmt|;
comment|/* pointer to last node in list */
name|uint_t
name|dl_len
decl_stmt|;
comment|/* number of valid instructions */
name|uint_t
name|dl_label
decl_stmt|;
comment|/* next label number to assign */
block|}
name|dt_irlist_t
typedef|;
specifier|extern
name|void
name|dt_irlist_create
parameter_list|(
name|dt_irlist_t
modifier|*
parameter_list|)
function_decl|;
specifier|extern
name|void
name|dt_irlist_destroy
parameter_list|(
name|dt_irlist_t
modifier|*
parameter_list|)
function_decl|;
specifier|extern
name|void
name|dt_irlist_append
parameter_list|(
name|dt_irlist_t
modifier|*
parameter_list|,
name|dt_irnode_t
modifier|*
parameter_list|)
function_decl|;
specifier|extern
name|uint_t
name|dt_irlist_label
parameter_list|(
name|dt_irlist_t
modifier|*
parameter_list|)
function_decl|;
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
comment|/* _DT_AS_H */
end_comment

end_unit

