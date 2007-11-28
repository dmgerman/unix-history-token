begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * CDDL HEADER START  *  * The contents of this file are subject to the terms of the  * Common Development and Distribution License (the "License").  * You may not use this file except in compliance with the License.  *  * You can obtain a copy of the license at usr/src/OPENSOLARIS.LICENSE  * or http://www.opensolaris.org/os/licensing.  * See the License for the specific language governing permissions  * and limitations under the License.  *  * When distributing Covered Code, include this CDDL HEADER in each  * file and include the License file at usr/src/OPENSOLARIS.LICENSE.  * If applicable, add the following below this CDDL HEADER, with the  * fields enclosed by brackets "[]" replaced with your own identifying  * information: Portions Copyright [yyyy] [name of copyright owner]  *  * CDDL HEADER END  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_COMPAT_OPENSOLARIS_SYS_OBJFS_H
end_ifndef

begin_define
define|#
directive|define
name|_COMPAT_OPENSOLARIS_SYS_OBJFS_H
end_define

begin_comment
comment|/*  * Private data structure found in '.info' section  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|objfs_info
block|{
name|int
name|objfs_info_primary
decl_stmt|;
block|}
name|objfs_info_t
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _COMPAT_OPENSOLARIS_SYS_OBJFS_H */
end_comment

end_unit

