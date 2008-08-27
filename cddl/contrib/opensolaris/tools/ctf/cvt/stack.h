begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * CDDL HEADER START  *  * The contents of this file are subject to the terms of the  * Common Development and Distribution License, Version 1.0 only  * (the "License").  You may not use this file except in compliance  * with the License.  *  * You can obtain a copy of the license at usr/src/OPENSOLARIS.LICENSE  * or http://www.opensolaris.org/os/licensing.  * See the License for the specific language governing permissions  * and limitations under the License.  *  * When distributing Covered Code, include this CDDL HEADER in each  * file and include the License file at usr/src/OPENSOLARIS.LICENSE.  * If applicable, add the following below this CDDL HEADER, with the  * fields enclosed by brackets "[]" replaced with your own identifying  * information: Portions Copyright [yyyy] [name of copyright owner]  *  * CDDL HEADER END  */
end_comment

begin_comment
comment|/*  * Copyright (c) 2001 by Sun Microsystems, Inc.  * All rights reserved.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_STACK_H
end_ifndef

begin_define
define|#
directive|define
name|_STACK_H
end_define

begin_pragma
pragma|#
directive|pragma
name|ident
literal|"%Z%%M%	%I%	%E% SMI"
end_pragma

begin_comment
comment|/*  * Routines for manipulating stacks  */
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
typedef|typedef
name|struct
name|stk
name|stk_t
typedef|;
name|stk_t
modifier|*
name|stack_new
parameter_list|(
name|void
function_decl|(
modifier|*
function_decl|)
parameter_list|(
name|void
modifier|*
parameter_list|)
parameter_list|)
function_decl|;
name|void
name|stack_free
parameter_list|(
name|stk_t
modifier|*
parameter_list|)
function_decl|;
name|void
modifier|*
name|stack_pop
parameter_list|(
name|stk_t
modifier|*
parameter_list|)
function_decl|;
name|void
modifier|*
name|stack_peek
parameter_list|(
name|stk_t
modifier|*
parameter_list|)
function_decl|;
name|void
name|stack_push
parameter_list|(
name|stk_t
modifier|*
parameter_list|,
name|void
modifier|*
parameter_list|)
function_decl|;
name|int
name|stack_level
parameter_list|(
name|stk_t
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
comment|/* _STACK_H */
end_comment

end_unit

