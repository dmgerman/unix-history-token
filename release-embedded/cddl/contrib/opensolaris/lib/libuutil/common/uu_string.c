begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * CDDL HEADER START  *  * The contents of this file are subject to the terms of the  * Common Development and Distribution License (the "License").  * You may not use this file except in compliance with the License.  *  * You can obtain a copy of the license at usr/src/OPENSOLARIS.LICENSE  * or http://www.opensolaris.org/os/licensing.  * See the License for the specific language governing permissions  * and limitations under the License.  *  * When distributing Covered Code, include this CDDL HEADER in each  * file and include the License file at usr/src/OPENSOLARIS.LICENSE.  * If applicable, add the following below this CDDL HEADER, with the  * fields enclosed by brackets "[]" replaced with your own identifying  * information: Portions Copyright [yyyy] [name of copyright owner]  *  * CDDL HEADER END  */
end_comment

begin_comment
comment|/*  * Copyright (c) 2009, 2010, Oracle and/or its affiliates. All rights reserved.  */
end_comment

begin_comment
comment|/*  * String helper functions  */
end_comment

begin_include
include|#
directive|include
file|<string.h>
end_include

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_include
include|#
directive|include
file|<malloc.h>
end_include

begin_include
include|#
directive|include
file|<ctype.h>
end_include

begin_include
include|#
directive|include
file|"libuutil.h"
end_include

begin_comment
comment|/* Return true if strings are equal */
end_comment

begin_function
name|boolean_t
name|uu_streq
parameter_list|(
specifier|const
name|char
modifier|*
name|a
parameter_list|,
specifier|const
name|char
modifier|*
name|b
parameter_list|)
block|{
return|return
operator|(
name|strcmp
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
operator|==
literal|0
operator|)
return|;
block|}
end_function

begin_comment
comment|/* Return true if strings are equal, case-insensitively */
end_comment

begin_function
name|boolean_t
name|uu_strcaseeq
parameter_list|(
specifier|const
name|char
modifier|*
name|a
parameter_list|,
specifier|const
name|char
modifier|*
name|b
parameter_list|)
block|{
return|return
operator|(
name|strcasecmp
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
operator|==
literal|0
operator|)
return|;
block|}
end_function

begin_comment
comment|/* Return true if string a Begins With string b */
end_comment

begin_function
name|boolean_t
name|uu_strbw
parameter_list|(
specifier|const
name|char
modifier|*
name|a
parameter_list|,
specifier|const
name|char
modifier|*
name|b
parameter_list|)
block|{
return|return
operator|(
name|strncmp
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|strlen
argument_list|(
name|b
argument_list|)
argument_list|)
operator|==
literal|0
operator|)
return|;
block|}
end_function

end_unit

