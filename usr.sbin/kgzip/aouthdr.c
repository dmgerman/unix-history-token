begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2000 Robert Nordier  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in  *    the documentation and/or other materials provided with the  *    distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR(S) ``AS IS'' AND ANY EXPRESS  * OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED  * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR(S) BE LIABLE FOR ANY  * DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE  * GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS  * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER  * IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR  * OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN  * IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_include
include|#
directive|include
file|<stddef.h>
end_include

begin_include
include|#
directive|include
file|"aouthdr.h"
end_include

begin_define
define|#
directive|define
name|KGZ_FIX_NSIZE
value|0
end_define

begin_comment
comment|/* Run-time fixup */
end_comment

begin_decl_stmt
specifier|const
name|struct
name|kgz_aouthdr0
name|aouthdr0
init|=
block|{
comment|/* a.out header */
block|{
name|MID_I386
operator|<<
literal|020
operator||
name|OMAGIC
block|,
comment|/* a_midmag */
literal|0
block|,
comment|/* a_text */
sizeof|sizeof
argument_list|(
expr|struct
name|kgz_hdr
argument_list|)
operator|+
name|KGZ_FIX_NSIZE
block|,
comment|/* a_data */
literal|0
block|,
comment|/* a_bss */
sizeof|sizeof
argument_list|(
expr|struct
name|nlist
argument_list|)
operator|*
name|KGZ__STNUM
block|,
comment|/* a_syms */
literal|0
block|,
comment|/* a_entry */
literal|0
block|,
comment|/* a_trsize */
literal|0
comment|/* a_drsize */
block|}
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|const
name|struct
name|kgz_aouthdr1
name|aouthdr1
init|=
block|{
comment|/* Symbol table */
block|{
block|{
block|{
operator|(
name|char
operator|*
operator|)
name|offsetof
argument_list|(
argument|struct kgz__strtab
argument_list|,
argument|kgz
argument_list|)
comment|/* n_un */
block|}
block|,
name|N_DATA
operator||
name|N_EXT
block|,
comment|/* n_type */
name|AUX_OBJECT
block|,
comment|/* n_other */
literal|0
block|,
comment|/* n_desc */
literal|0
comment|/* n_value */
block|}
block|,
block|{
block|{
operator|(
name|char
operator|*
operator|)
name|offsetof
argument_list|(
argument|struct kgz__strtab
argument_list|,
argument|kgz_ndata
argument_list|)
comment|/* n_un */
block|}
block|,
name|N_DATA
operator||
name|N_EXT
block|,
comment|/* n_type */
name|AUX_OBJECT
block|,
comment|/* n_other */
literal|0
block|,
comment|/* n_desc */
expr|sizeof
operator|(
expr|struct
name|kgz_hdr
operator|)
comment|/* n_value */
block|}
block|}
block|,
comment|/* String table */
block|{
sizeof|sizeof
argument_list|(
expr|struct
name|kgz__strtab
argument_list|)
block|,
comment|/* length */
name|KGZ__STR_KGZ
block|,
comment|/* kgz */
name|KGZ__STR_KGZ_NDATA
comment|/* kgz_ndata */
block|}
block|}
decl_stmt|;
end_decl_stmt

end_unit

