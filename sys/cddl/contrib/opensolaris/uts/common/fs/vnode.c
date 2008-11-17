begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * CDDL HEADER START  *  * The contents of this file are subject to the terms of the  * Common Development and Distribution License (the "License").  * You may not use this file except in compliance with the License.  *  * You can obtain a copy of the license at usr/src/OPENSOLARIS.LICENSE  * or http://www.opensolaris.org/os/licensing.  * See the License for the specific language governing permissions  * and limitations under the License.  *  * When distributing Covered Code, include this CDDL HEADER in each  * file and include the License file at usr/src/OPENSOLARIS.LICENSE.  * If applicable, add the following below this CDDL HEADER, with the  * fields enclosed by brackets "[]" replaced with your own identifying  * information: Portions Copyright [yyyy] [name of copyright owner]  *  * CDDL HEADER END  */
end_comment

begin_comment
comment|/*  * Copyright 2008 Sun Microsystems, Inc.  All rights reserved.  * Use is subject to license terms.  */
end_comment

begin_comment
comment|/*	Copyright (c) 1983, 1984, 1985, 1986, 1987, 1988, 1989 AT&T	*/
end_comment

begin_comment
comment|/*	  All Rights Reserved  	*/
end_comment

begin_comment
comment|/*  * University Copyright- Copyright (c) 1982, 1986, 1988  * The Regents of the University of California  * All Rights Reserved  *  * University Acknowledgment- Portions of this document are derived from  * software developed by the University of California, Berkeley, and its  * contributors.  */
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
file|<sys/param.h>
end_include

begin_include
include|#
directive|include
file|<sys/vnode.h>
end_include

begin_comment
comment|/* Extensible attribute (xva) routines. */
end_comment

begin_comment
comment|/*  * Zero out the structure, set the size of the requested/returned bitmaps,  * set AT_XVATTR in the embedded vattr_t's va_mask, and set up the pointer  * to the returned attributes array.  */
end_comment

begin_function
name|void
name|xva_init
parameter_list|(
name|xvattr_t
modifier|*
name|xvap
parameter_list|)
block|{
name|bzero
argument_list|(
name|xvap
argument_list|,
sizeof|sizeof
argument_list|(
name|xvattr_t
argument_list|)
argument_list|)
expr_stmt|;
name|xvap
operator|->
name|xva_mapsize
operator|=
name|XVA_MAPSIZE
expr_stmt|;
name|xvap
operator|->
name|xva_magic
operator|=
name|XVA_MAGIC
expr_stmt|;
name|xvap
operator|->
name|xva_vattr
operator|.
name|va_mask
operator|=
name|AT_XVATTR
expr_stmt|;
name|xvap
operator|->
name|xva_rtnattrmapp
operator|=
operator|&
operator|(
name|xvap
operator|->
name|xva_rtnattrmap
operator|)
index|[
literal|0
index|]
expr_stmt|;
block|}
end_function

begin_comment
comment|/*  * If AT_XVATTR is set, returns a pointer to the embedded xoptattr_t  * structure.  Otherwise, returns NULL.  */
end_comment

begin_function
name|xoptattr_t
modifier|*
name|xva_getxoptattr
parameter_list|(
name|xvattr_t
modifier|*
name|xvap
parameter_list|)
block|{
name|xoptattr_t
modifier|*
name|xoap
init|=
name|NULL
decl_stmt|;
if|if
condition|(
name|xvap
operator|->
name|xva_vattr
operator|.
name|va_mask
operator|&
name|AT_XVATTR
condition|)
name|xoap
operator|=
operator|&
name|xvap
operator|->
name|xva_xoptattrs
expr_stmt|;
return|return
operator|(
name|xoap
operator|)
return|;
block|}
end_function

end_unit

