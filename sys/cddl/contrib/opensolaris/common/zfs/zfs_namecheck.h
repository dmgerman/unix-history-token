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
name|_ZFS_NAMECHECK_H
end_ifndef

begin_define
define|#
directive|define
name|_ZFS_NAMECHECK_H
end_define

begin_pragma
pragma|#
directive|pragma
name|ident
literal|"%Z%%M%	%I%	%E% SMI"
end_pragma

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
enum|enum
block|{
name|NAME_ERR_LEADING_SLASH
block|,
comment|/* name begins with leading slash */
name|NAME_ERR_EMPTY_COMPONENT
block|,
comment|/* name contains an empty component */
name|NAME_ERR_TRAILING_SLASH
block|,
comment|/* name ends with a slash */
name|NAME_ERR_INVALCHAR
block|,
comment|/* invalid character found */
name|NAME_ERR_MULTIPLE_AT
block|,
comment|/* multiple '@' characters found */
name|NAME_ERR_NOLETTER
block|,
comment|/* pool doesn't begin with a letter */
name|NAME_ERR_RESERVED
block|,
comment|/* entire name is reserved */
name|NAME_ERR_DISKLIKE
block|,
comment|/* reserved disk name (c[0-9].*) */
name|NAME_ERR_TOOLONG
block|,
comment|/* name is too long */
block|}
name|namecheck_err_t
typedef|;
name|int
name|pool_namecheck
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
name|namecheck_err_t
modifier|*
parameter_list|,
name|char
modifier|*
parameter_list|)
function_decl|;
name|int
name|dataset_namecheck
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
name|namecheck_err_t
modifier|*
parameter_list|,
name|char
modifier|*
parameter_list|)
function_decl|;
name|int
name|dataset_name_hidden
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
name|int
name|snapshot_namecheck
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
name|namecheck_err_t
modifier|*
parameter_list|,
name|char
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
comment|/* _ZFS_NAMECHECK_H */
end_comment

end_unit

