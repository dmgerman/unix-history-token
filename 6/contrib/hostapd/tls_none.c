begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * WPA Supplicant / SSL/TLS interface functions for no TLS case  * Copyright (c) 2004, Jouni Malinen<jkmaline@cc.hut.fi>  *  * This program is free software; you can redistribute it and/or modify  * it under the terms of the GNU General Public License version 2 as  * published by the Free Software Foundation.  *  * Alternatively, this software may be distributed under the terms of BSD  * license.  *  * See README and COPYING for more details.  */
end_comment

begin_include
include|#
directive|include
file|<stdlib.h>
end_include

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_include
include|#
directive|include
file|"common.h"
end_include

begin_include
include|#
directive|include
file|"tls.h"
end_include

begin_function
name|void
modifier|*
name|tls_init
parameter_list|(
specifier|const
name|struct
name|tls_config
modifier|*
name|conf
parameter_list|)
block|{
return|return
operator|(
name|void
operator|*
operator|)
literal|1
return|;
block|}
end_function

begin_function
name|void
name|tls_deinit
parameter_list|(
name|void
modifier|*
name|ssl_ctx
parameter_list|)
block|{ }
end_function

end_unit

