begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * CDDL HEADER START  *  * The contents of this file are subject to the terms of the  * Common Development and Distribution License, Version 1.0 only  * (the "License").  You may not use this file except in compliance  * with the License.  *  * You can obtain a copy of the license at usr/src/OPENSOLARIS.LICENSE  * or http://www.opensolaris.org/os/licensing.  * See the License for the specific language governing permissions  * and limitations under the License.  *  * When distributing Covered Code, include this CDDL HEADER in each  * file and include the License file at usr/src/OPENSOLARIS.LICENSE.  * If applicable, add the following below this CDDL HEADER, with the  * fields enclosed by brackets "[]" replaced with your own identifying  * information: Portions Copyright [yyyy] [name of copyright owner]  *  * CDDL HEADER END  */
end_comment

begin_comment
comment|/*  * Copyright 2004 Sun Microsystems, Inc.  All rights reserved.  * Use is subject to license terms.  */
end_comment

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
file|<string.h>
end_include

begin_include
include|#
directive|include
file|"symbol.h"
end_include

begin_function
name|int
name|ignore_symbol
parameter_list|(
name|GElf_Sym
modifier|*
name|sym
parameter_list|,
specifier|const
name|char
modifier|*
name|name
parameter_list|)
block|{
name|uchar_t
name|type
init|=
name|GELF_ST_TYPE
argument_list|(
name|sym
operator|->
name|st_info
argument_list|)
decl_stmt|;
comment|/* 	 * As an optimization, we do not output function or data object 	 * records for undefined or anonymous symbols. 	 */
if|if
condition|(
name|sym
operator|->
name|st_shndx
operator|==
name|SHN_UNDEF
operator|||
name|sym
operator|->
name|st_name
operator|==
literal|0
condition|)
return|return
operator|(
literal|1
operator|)
return|;
comment|/* 	 * _START_ and _END_ are added to the symbol table by the 	 * linker, and will never have associated type information. 	 */
if|if
condition|(
name|strcmp
argument_list|(
name|name
argument_list|,
literal|"_START_"
argument_list|)
operator|==
literal|0
operator|||
name|strcmp
argument_list|(
name|name
argument_list|,
literal|"_END_"
argument_list|)
operator|==
literal|0
condition|)
return|return
operator|(
literal|1
operator|)
return|;
comment|/* 	 * Do not output records for absolute-valued object symbols 	 * that have value zero.  The compiler insists on generating 	 * things like this for __fsr_init_value settings, etc. 	 */
if|if
condition|(
name|type
operator|==
name|STT_OBJECT
operator|&&
name|sym
operator|->
name|st_shndx
operator|==
name|SHN_ABS
operator|&&
name|sym
operator|->
name|st_value
operator|==
literal|0
condition|)
return|return
operator|(
literal|1
operator|)
return|;
return|return
operator|(
literal|0
operator|)
return|;
block|}
end_function

end_unit

