begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$OpenBSD: uidswap.h,v 1.7 2001/04/06 21:00:17 markus Exp $	*/
end_comment

begin_comment
comment|/*  * Author: Tatu Ylonen<ylo@cs.hut.fi>  * Copyright (c) 1995 Tatu Ylonen<ylo@cs.hut.fi>, Espoo, Finland  *                    All rights reserved  *  * As far as I am concerned, the code I have written for this software  * can be used freely for any purpose.  Any derived versions of this  * software must be clearly marked as such, and if the derived work is  * incompatible with the protocol description in the RFC file, it must be  * called by a name other than "ssh" or "Secure Shell".  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|UIDSWAP_H
end_ifndef

begin_define
define|#
directive|define
name|UIDSWAP_H
end_define

begin_comment
comment|/*  * Temporarily changes to the given uid.  If the effective user id is not  * root, this does nothing.  This call cannot be nested.  */
end_comment

begin_function_decl
name|void
name|temporarily_use_uid
parameter_list|(
name|struct
name|passwd
modifier|*
name|pw
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Restores the original effective user id after temporarily_use_uid().  * This should only be called while temporarily_use_uid is effective.  */
end_comment

begin_function_decl
name|void
name|restore_uid
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Permanently sets all uids to the given uid.  This cannot be called while  * temporarily_use_uid is effective.  This must also clear any saved uids.  */
end_comment

begin_function_decl
name|void
name|permanently_set_uid
parameter_list|(
name|struct
name|passwd
modifier|*
name|pw
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* UIDSWAP_H */
end_comment

end_unit

