begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$OpenBSD: hostfile.h,v 1.7 2001/02/08 19:30:51 itojun Exp $	*/
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

begin_function_decl
name|int
name|auth_rsa_read_key
parameter_list|(
name|char
modifier|*
modifier|*
name|cpp
parameter_list|,
name|u_int
modifier|*
name|bitsp
parameter_list|,
name|BIGNUM
modifier|*
name|e
parameter_list|,
name|BIGNUM
modifier|*
name|n
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Checks whether the given host is already in the list of our known hosts.  * Returns HOST_OK if the host is known and has the specified key, HOST_NEW  * if the host is not known, and HOST_CHANGED if the host is known but used  * to have a different host key.  The host must be in all lowercase.  */
end_comment

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
name|HostStatus
name|check_host_in_hostfile
parameter_list|(
specifier|const
name|char
modifier|*
name|filename
parameter_list|,
specifier|const
name|char
modifier|*
name|host
parameter_list|,
name|Key
modifier|*
name|key
parameter_list|,
name|Key
modifier|*
name|found
parameter_list|,
name|int
modifier|*
name|line
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Appends an entry to the host file.  Returns false if the entry could not  * be appended.  */
end_comment

begin_function_decl
name|int
name|add_host_to_hostfile
parameter_list|(
specifier|const
name|char
modifier|*
name|filename
parameter_list|,
specifier|const
name|char
modifier|*
name|host
parameter_list|,
name|Key
modifier|*
name|key
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

end_unit

