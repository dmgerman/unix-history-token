begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$OpenBSD: hostfile.h,v 1.10 2001/12/18 10:04:21 jakob Exp $	*/
end_comment

begin_comment
comment|/*  * Author: Tatu Ylonen<ylo@cs.hut.fi>  * Copyright (c) 1995 Tatu Ylonen<ylo@cs.hut.fi>, Espoo, Finland  *                    All rights reserved  *  * As far as I am concerned, the code I have written for this software  * can be used freely for any purpose.  Any derived versions of this  * software must be clearly marked as such, and if the derived work is  * incompatible with the protocol description in the RFC file, it must be  * called by a name other than "ssh" or "Secure Shell".  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|HOSTFILE_H
end_ifndef

begin_define
define|#
directive|define
name|HOSTFILE_H
end_define

begin_typedef
typedef|typedef
enum|enum
block|{
name|HOST_OK
block|,
name|HOST_NEW
block|,
name|HOST_CHANGED
block|}
name|HostStatus
typedef|;
end_typedef

begin_function_decl
name|int
name|hostfile_read_key
parameter_list|(
name|char
modifier|*
modifier|*
parameter_list|,
name|u_int
modifier|*
parameter_list|,
name|Key
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|HostStatus
name|check_host_in_hostfile
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
name|Key
modifier|*
parameter_list|,
name|Key
modifier|*
parameter_list|,
name|int
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|add_host_to_hostfile
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
name|Key
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

end_unit

