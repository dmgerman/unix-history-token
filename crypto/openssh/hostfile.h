begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$OpenBSD: hostfile.h,v 1.15 2005/03/01 10:40:26 djm Exp $	*/
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
block|,
name|HOST_FOUND
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
specifier|const
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
specifier|const
name|Key
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|lookup_key_in_hostfile_by_type
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
name|int
parameter_list|,
name|Key
modifier|*
parameter_list|,
name|int
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|HASH_MAGIC
value|"|1|"
end_define

begin_define
define|#
directive|define
name|HASH_DELIM
value|'|'
end_define

begin_function_decl
name|char
modifier|*
name|host_hash
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
name|u_int
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

end_unit

