begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1990 The Regents of the University of California.  * All rights reserved.  *  * Redistribution and use in source and binary forms are permitted  * provided that the above copyright notice and this paragraph are  * duplicated in all such forms and that any documentation,  * advertising materials, and other materials related to such  * distribution and use acknowledge that the software was developed  * by the University of California, Berkeley.  The name of the  * University may not be used to endorse or promote products derived  * from this software without specific prior written permission.  * THIS SOFTWARE IS PROVIDED ``AS IS'' AND WITHOUT ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, WITHOUT LIMITATION, THE IMPLIED  * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.  *  *	@(#)specdev.h	7.1 (Berkeley) %G%  */
end_comment

begin_comment
comment|/*  * This structure defines the information maintained about  * special devices. It is allocated in checkalias and freed  * in vgone.  */
end_comment

begin_struct
struct|struct
name|specinfo
block|{
name|struct
name|vnode
modifier|*
modifier|*
name|si_hashchain
decl_stmt|;
name|struct
name|vnode
modifier|*
name|si_specnext
decl_stmt|;
name|long
name|si_flags
decl_stmt|;
name|dev_t
name|si_rdev
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * Exported shorthand  */
end_comment

begin_define
define|#
directive|define
name|v_rdev
value|v_specinfo->si_rdev
end_define

begin_define
define|#
directive|define
name|v_hashchain
value|v_specinfo->si_hashchain
end_define

begin_define
define|#
directive|define
name|v_specnext
value|v_specinfo->si_specnext
end_define

begin_define
define|#
directive|define
name|v_specflags
value|v_specinfo->si_flags
end_define

begin_comment
comment|/*  * Flags for specinfo  */
end_comment

begin_define
define|#
directive|define
name|SI_MOUNTEDON
value|0x0001
end_define

begin_comment
comment|/* block special device is mounted on */
end_comment

begin_comment
comment|/*  * Special device management  */
end_comment

begin_define
define|#
directive|define
name|SPECHSZ
value|64
end_define

begin_if
if|#
directive|if
operator|(
operator|(
name|SPECHSZ
operator|&
operator|(
name|SPECHSZ
operator|-
literal|1
operator|)
operator|)
operator|==
literal|0
operator|)
end_if

begin_define
define|#
directive|define
name|SPECHASH
parameter_list|(
name|rdev
parameter_list|)
value|(((rdev>>5)+(rdev))&(SPECHSZ-1))
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|SPECHASH
parameter_list|(
name|rdev
parameter_list|)
value|(((unsigned)((rdev>>5)+(rdev)))%SPECHSZ)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
name|struct
name|vnode
modifier|*
name|speclisth
index|[
name|SPECHSZ
index|]
decl_stmt|;
end_decl_stmt

end_unit

