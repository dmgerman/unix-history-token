begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * $Id$  * From: $NetBSD: biosdisk_ll.h,v 1.2 1997/03/22 01:41:36 thorpej Exp $  */
end_comment

begin_comment
comment|/*  * Copyright (c) 1996  * 	Matthias Drochner.  All rights reserved.  * Copyright (c) 1996  * 	Perry E. Metzger.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgements:  *	This product includes software developed for the NetBSD Project  *	by Matthias Drochner.  *	This product includes software developed for the NetBSD Project  *	by Perry E. Metzger.  * 4. The names of the authors may not be used to endorse or promote products  *    derived from this software without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  */
end_comment

begin_comment
comment|/*  * shared by bootsector startup (bootsectmain) and biosdisk.c needs lowlevel  * parts from bios_disk.S  */
end_comment

begin_struct
struct|struct
name|biosdisk_ll
block|{
name|int
name|dev
decl_stmt|;
comment|/* BIOS device number */
name|int
name|spt
decl_stmt|,
name|spc
decl_stmt|;
comment|/* geometry */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|BIOSDISK_SECSIZE
value|512
end_define

begin_function_decl
specifier|extern
name|int
name|set_geometry
parameter_list|(
name|struct
name|biosdisk_ll
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|readsects
parameter_list|(
name|struct
name|biosdisk_ll
modifier|*
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|,
name|char
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

end_unit

