begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * (C)opyright 1993,1994,1995 by Darren Reed.  *  * Redistribution and use in source and binary forms are permitted  * provided that this notice is preserved and due credit is given  * to the original author and the contributors.  * $Id: ipt.h,v 2.0.1.1 1997/01/09 15:14:44 darrenr Exp $  */
end_comment

begin_include
include|#
directive|include
file|<fcntl.h>
end_include

begin_struct
struct|struct
name|ipread
block|{
name|int
function_decl|(
modifier|*
name|r_open
function_decl|)
parameter_list|()
function_decl|;
name|int
function_decl|(
modifier|*
name|r_close
function_decl|)
parameter_list|()
function_decl|;
name|int
function_decl|(
modifier|*
name|r_readip
function_decl|)
parameter_list|()
function_decl|;
block|}
struct|;
end_struct

end_unit

