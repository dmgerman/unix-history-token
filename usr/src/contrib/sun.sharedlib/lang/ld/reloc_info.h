begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * This source code is a product of Sun Microsystems, Inc. and is provided  * for unrestricted use provided that this legend is included on all tape  * media and as a part of the software program in whole or part.  Users  * may copy or modify this source code without charge, but are not authorized  * to license or distribute it to anyone else except as part of a product or  * program developed by the user.  *  * THIS PROGRAM CONTAINS SOURCE CODE COPYRIGHTED BY SUN MICROSYSTEMS, INC.  * SUN MICROSYSTEMS, INC., MAKES NO REPRESENTATIONS ABOUT THE SUITABLITY  * OF SUCH SOURCE CODE FOR ANY PURPOSE.  IT IS PROVIDED "AS IS" WITHOUT  * EXPRESS OR IMPLIED WARRANTY OF ANY KIND.  SUN MICROSYSTEMS, INC. DISCLAIMS  * ALL WARRANTIES WITH REGARD TO SUCH SOURCE CODE, INCLUDING ALL IMPLIED  * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.  IN  * NO EVENT SHALL SUN MICROSYSTEMS, INC. BE LIABLE FOR ANY SPECIAL, INDIRECT,  * INCIDENTAL, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING  * FROM USE OF SUCH SOURCE CODE, REGARDLESS OF THE THEORY OF LIABILITY.  *   * This source code is provided with no support and without any obligation on  * the part of Sun Microsystems, Inc. to assist in its use, correction,   * modification or enhancement.  *  * SUN MICROSYSTEMS, INC. SHALL HAVE NO LIABILITY WITH RESPECT TO THE  * INFRINGEMENT OF COPYRIGHTS, TRADE SECRETS OR ANY PATENTS BY THIS  * SOURCE CODE OR ANY PART THEREOF.  *  * Sun Microsystems, Inc.  * 2550 Garcia Avenue  * Mountain View, California 94043  */
end_comment

begin_comment
comment|/*      @(#)reloc_info.h 1.4 69/12/31 SMI; 	*/
end_comment

begin_comment
comment|/* Copyright (c) 1991 by Sun Microsystems, Inc. */
end_comment

begin_comment
comment|/*<a.out.h> must be included before this file. */
end_comment

begin_comment
comment|/* This is so the common linker code can refer to either the 68k or  * SPARC relcation structure via the same name.  */
end_comment

begin_undef
undef|#
directive|undef
name|relocation_info
end_undef

begin_if
if|#
directive|if
operator|(
name|TARGET
operator|==
name|SUN2
operator|)
operator|||
operator|(
name|TARGET
operator|==
name|SUN3
operator|)
end_if

begin_define
define|#
directive|define
name|relocation_info
value|reloc_info_68k
end_define

begin_define
define|#
directive|define
name|MAX_GOT_SIZE
value|16384
end_define

begin_comment
comment|/* XXX Should this be here? */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
operator|(
name|TARGET
operator|==
name|SUN4
operator|)
end_if

begin_define
define|#
directive|define
name|relocation_info
value|reloc_info_sparc
end_define

begin_define
define|#
directive|define
name|MAX_GOT_SIZE
value|2048
end_define

begin_comment
comment|/* XXX Should this be here? */
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

