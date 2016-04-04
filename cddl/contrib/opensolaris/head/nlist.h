begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * CDDL HEADER START  *  * The contents of this file are subject to the terms of the  * Common Development and Distribution License, Version 1.0 only  * (the "License").  You may not use this file except in compliance  * with the License.  *  * You can obtain a copy of the license at usr/src/OPENSOLARIS.LICENSE  * or http://www.opensolaris.org/os/licensing.  * See the License for the specific language governing permissions  * and limitations under the License.  *  * When distributing Covered Code, include this CDDL HEADER in each  * file and include the License file at usr/src/OPENSOLARIS.LICENSE.  * If applicable, add the following below this CDDL HEADER, with the  * fields enclosed by brackets "[]" replaced with your own identifying  * information: Portions Copyright [yyyy] [name of copyright owner]  *  * CDDL HEADER END  */
end_comment

begin_comment
comment|/*  * Copyright 2014 Garrett D'Amore<garrett@damore.org>  */
end_comment

begin_comment
comment|/*	Copyright (c) 1988 AT&T	*/
end_comment

begin_comment
comment|/*	  All Rights Reserved  	*/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_NLIST_H
end_ifndef

begin_define
define|#
directive|define
name|_NLIST_H
end_define

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
struct|struct
name|nlist
block|{
name|char
modifier|*
name|n_name
decl_stmt|;
comment|/* symbol name */
name|long
name|n_value
decl_stmt|;
comment|/* value of symbol */
name|short
name|n_scnum
decl_stmt|;
comment|/* section number */
name|unsigned
name|short
name|n_type
decl_stmt|;
comment|/* type and derived type */
name|char
name|n_sclass
decl_stmt|;
comment|/* storage class */
name|char
name|n_numaux
decl_stmt|;
comment|/* number of aux. entries */
block|}
struct|;
specifier|extern
name|int
name|nlist
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
name|struct
name|nlist
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
comment|/* _NLIST_H */
end_comment

end_unit

