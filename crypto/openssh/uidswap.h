begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $OpenBSD: uidswap.h,v 1.13 2006/08/03 03:34:42 deraadt Exp $ */
end_comment

begin_comment
comment|/*  * Author: Tatu Ylonen<ylo@cs.hut.fi>  * Copyright (c) 1995 Tatu Ylonen<ylo@cs.hut.fi>, Espoo, Finland  *                    All rights reserved  *  * As far as I am concerned, the code I have written for this software  * can be used freely for any purpose.  Any derived versions of this  * software must be clearly marked as such, and if the derived work is  * incompatible with the protocol description in the RFC file, it must be  * called by a name other than "ssh" or "Secure Shell".  */
end_comment

begin_function_decl
name|void
name|temporarily_use_uid
parameter_list|(
name|struct
name|passwd
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|restore_uid
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|permanently_set_uid
parameter_list|(
name|struct
name|passwd
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|permanently_drop_suid
parameter_list|(
name|uid_t
parameter_list|)
function_decl|;
end_function_decl

end_unit

