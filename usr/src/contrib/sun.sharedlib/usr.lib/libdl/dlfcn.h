begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * This source code is a product of Sun Microsystems, Inc. and is provided  * for unrestricted use provided that this legend is included on all tape  * media and as a part of the software program in whole or part.  Users  * may copy or modify this source code without charge, but are not authorized  * to license or distribute it to anyone else except as part of a product or  * program developed by the user.  *  * THIS PROGRAM CONTAINS SOURCE CODE COPYRIGHTED BY SUN MICROSYSTEMS, INC.  * SUN MICROSYSTEMS, INC., MAKES NO REPRESENTATIONS ABOUT THE SUITABLITY  * OF SUCH SOURCE CODE FOR ANY PURPOSE.  IT IS PROVIDED "AS IS" WITHOUT  * EXPRESS OR IMPLIED WARRANTY OF ANY KIND.  SUN MICROSYSTEMS, INC. DISCLAIMS  * ALL WARRANTIES WITH REGARD TO SUCH SOURCE CODE, INCLUDING ALL IMPLIED  * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.  IN  * NO EVENT SHALL SUN MICROSYSTEMS, INC. BE LIABLE FOR ANY SPECIAL, INDIRECT,  * INCIDENTAL, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING  * FROM USE OF SUCH SOURCE CODE, REGARDLESS OF THE THEORY OF LIABILITY.  *   * This source code is provided with no support and without any obligation on  * the part of Sun Microsystems, Inc. to assist in its use, correction,   * modification or enhancement.  *  * SUN MICROSYSTEMS, INC. SHALL HAVE NO LIABILITY WITH RESPECT TO THE  * INFRINGEMENT OF COPYRIGHTS, TRADE SECRETS OR ANY PATENTS BY THIS  * SOURCE CODE OR ANY PART THEREOF.  *  * Sun Microsystems, Inc.  * 2550 Garcia Avenue  * Mountain View, California 94043  */
end_comment

begin_comment
comment|/* @(#)dlfcn.h 1.1 89/09/04 SMI */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_dlfcn_h
end_ifndef

begin_define
define|#
directive|define
name|_dlfcn_h
end_define

begin_comment
comment|/*  * Copyright (c) 1989, 1991 Sun Microsystems, Inc.  */
end_comment

begin_comment
comment|/*  * Interface description for the contents of libdl -- simple programmer's  * interfaces to the dynamic linker.  */
end_comment

begin_comment
comment|/*  * Manifest constants  */
end_comment

begin_define
define|#
directive|define
name|RTLD_LAZY
value|1
end_define

begin_comment
comment|/* deferred binding of procedures */
end_comment

begin_comment
comment|/*  * Function declarations  */
end_comment

begin_function_decl
specifier|extern
name|void
modifier|*
name|dlopen
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* open and map a shared object */
end_comment

begin_function_decl
specifier|extern
name|void
modifier|*
name|dlsym
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* obtain address of symbol */
end_comment

begin_function_decl
specifier|extern
name|int
name|dlclose
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* remove a shared object */
end_comment

begin_function_decl
specifier|extern
name|char
modifier|*
name|dlerror
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* string representing last error */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_dlfcn_h */
end_comment

end_unit

