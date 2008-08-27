begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * CDDL HEADER START  *  * The contents of this file are subject to the terms of the  * Common Development and Distribution License (the "License").  * You may not use this file except in compliance with the License.  *  * You can obtain a copy of the license at usr/src/OPENSOLARIS.LICENSE  * or http://www.opensolaris.org/os/licensing.  * See the License for the specific language governing permissions  * and limitations under the License.  *  * When distributing Covered Code, include this CDDL HEADER in each  * file and include the License file at usr/src/OPENSOLARIS.LICENSE.  * If applicable, add the following below this CDDL HEADER, with the  * fields enclosed by brackets "[]" replaced with your own identifying  * information: Portions Copyright [yyyy] [name of copyright owner]  *  * CDDL HEADER END  */
end_comment

begin_comment
comment|/*  * Copyright 2008 Sun Microsystems, Inc.  All rights reserved.  * Use is subject to license terms.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_STRING_TABLE_DOT_H
end_ifndef

begin_define
define|#
directive|define
name|_STRING_TABLE_DOT_H
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
comment|/*  * Exported, opaque string table handle.  */
typedef|typedef
name|struct
name|str_tbl
name|Str_tbl
typedef|;
comment|/*  * Exported string table functions.  */
specifier|extern
name|int
name|st_delstring
parameter_list|(
name|Str_tbl
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
specifier|extern
name|void
name|st_destroy
parameter_list|(
name|Str_tbl
modifier|*
parameter_list|)
function_decl|;
specifier|extern
name|size_t
name|st_getstrtab_sz
parameter_list|(
name|Str_tbl
modifier|*
parameter_list|)
function_decl|;
specifier|extern
specifier|const
name|char
modifier|*
name|st_getstrbuf
parameter_list|(
name|Str_tbl
modifier|*
parameter_list|)
function_decl|;
specifier|extern
name|int
name|st_insert
parameter_list|(
name|Str_tbl
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
specifier|extern
name|Str_tbl
modifier|*
name|st_new
parameter_list|(
name|uint_t
parameter_list|)
function_decl|;
specifier|extern
name|int
name|st_setstrbuf
parameter_list|(
name|Str_tbl
modifier|*
parameter_list|,
name|char
modifier|*
parameter_list|,
name|size_t
parameter_list|)
function_decl|;
specifier|extern
name|int
name|st_setstring
parameter_list|(
name|Str_tbl
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
name|size_t
modifier|*
parameter_list|)
function_decl|;
comment|/*  * Exported flags values for st_new().  */
define|#
directive|define
name|FLG_STNEW_COMPRESS
value|0x01
comment|/* compressed string table */
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
comment|/* _STRING_TABLE_DOT_H */
end_comment

end_unit

