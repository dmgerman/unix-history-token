begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * This source code is a product of Sun Microsystems, Inc. and is provided  * for unrestricted use provided that this legend is included on all tape  * media and as a part of the software program in whole or part.  Users  * may copy or modify this source code without charge, but are not authorized  * to license or distribute it to anyone else except as part of a product or  * program developed by the user.  *  * THIS PROGRAM CONTAINS SOURCE CODE COPYRIGHTED BY SUN MICROSYSTEMS, INC.  * SUN MICROSYSTEMS, INC., MAKES NO REPRESENTATIONS ABOUT THE SUITABLITY  * OF SUCH SOURCE CODE FOR ANY PURPOSE.  IT IS PROVIDED "AS IS" WITHOUT  * EXPRESS OR IMPLIED WARRANTY OF ANY KIND.  SUN MICROSYSTEMS, INC. DISCLAIMS  * ALL WARRANTIES WITH REGARD TO SUCH SOURCE CODE, INCLUDING ALL IMPLIED  * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.  IN  * NO EVENT SHALL SUN MICROSYSTEMS, INC. BE LIABLE FOR ANY SPECIAL, INDIRECT,  * INCIDENTAL, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING  * FROM USE OF SUCH SOURCE CODE, REGARDLESS OF THE THEORY OF LIABILITY.  *   * This source code is provided with no support and without any obligation on  * the part of Sun Microsystems, Inc. to assist in its use, correction,   * modification or enhancement.  *  * SUN MICROSYSTEMS, INC. SHALL HAVE NO LIABILITY WITH RESPECT TO THE  * INFRINGEMENT OF COPYRIGHTS, TRADE SECRETS OR ANY PATENTS BY THIS  * SOURCE CODE OR ANY PART THEREOF.  *  * Sun Microsystems, Inc.  * 2550 Garcia Avenue  * Mountain View, California 94043  */
end_comment

begin_comment
comment|/* @(#)errors.c 1.2 91/03/16 SMI */
end_comment

begin_comment
comment|/*  * Copyright (c) 1989, 1991 Sun Microsystems, Inc.  */
end_comment

begin_decl_stmt
name|char
name|DLE_none
index|[]
init|=
literal|"ld.so: no error"
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
name|DLE_mode_error
index|[]
init|=
literal|"ld.so: invalid dlopen mode"
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
name|DLE_bad_handle
index|[]
init|=
literal|"ld.so: invalid object"
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
name|DLE_can_not_open
index|[]
init|=
literal|"ld.so: object could not be mapped"
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
name|DLE_undefined
index|[]
init|=
literal|"ld.so: undefined symbol"
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
name|DLE_conflict
index|[]
init|=
literal|"ld.so: conflicting usage of dlopen'ed dependents"
decl_stmt|;
end_decl_stmt

end_unit

