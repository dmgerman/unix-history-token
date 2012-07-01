begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * CDDL HEADER START  *  * The contents of this file are subject to the terms of the  * Common Development and Distribution License (the "License").  * You may not use this file except in compliance with the License.  *  * You can obtain a copy of the license at usr/src/OPENSOLARIS.LICENSE  * or http://www.opensolaris.org/os/licensing.  * See the License for the specific language governing permissions  * and limitations under the License.  *  * When distributing Covered Code, include this CDDL HEADER in each  * file and include the License file at usr/src/OPENSOLARIS.LICENSE.  * If applicable, add the following below this CDDL HEADER, with the  * fields enclosed by brackets "[]" replaced with your own identifying  * information: Portions Copyright [yyyy] [name of copyright owner]  *  * CDDL HEADER END  */
end_comment

begin_comment
comment|/*  * Copyright 2007 Sun Microsystems, Inc.  All rights reserved.  * Use is subject to license terms.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_SYS_ACL_IMPL_H
end_ifndef

begin_define
define|#
directive|define
name|_SYS_ACL_IMPL_H
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
comment|/*  * acl flags  *  * ACL_AUTO_INHERIT, ACL_PROTECTED and ACL_DEFAULTED  * flags can also be stored in this field.  */
define|#
directive|define
name|ACL_IS_TRIVIAL
value|0x10000
define|#
directive|define
name|ACL_IS_DIR
value|0x20000
typedef|typedef
enum|enum
name|acl_type
block|{
name|ACLENT_T
init|=
literal|0
block|,
name|ACE_T
init|=
literal|1
block|}
name|acl_type_t
typedef|;
struct|struct
name|acl_info
block|{
name|acl_type_t
name|acl_type
decl_stmt|;
comment|/* style of acl */
name|int
name|acl_cnt
decl_stmt|;
comment|/* number of acl entries */
name|int
name|acl_entry_size
decl_stmt|;
comment|/* sizeof acl entry */
name|int
name|acl_flags
decl_stmt|;
comment|/* special flags about acl */
name|void
modifier|*
name|acl_aclp
decl_stmt|;
comment|/* the acl */
block|}
struct|;
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
comment|/* _SYS_ACL_IMPL_H */
end_comment

end_unit

