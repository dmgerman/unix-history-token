begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1982, 1986 Regents of the University of California.  * All rights reserved.  The Berkeley software License Agreement  * specifies the terms and conditions for redistribution.  *  *	@(#)un.h	7.1 (Berkeley) 6/4/86  */
end_comment

begin_comment
comment|/*  * Definitions for UNIX IPC domain.  */
end_comment

begin_struct
struct|struct
name|sockaddr_un
block|{
name|short
name|sun_family
decl_stmt|;
comment|/* AF_UNIX */
name|char
name|sun_path
index|[
literal|108
index|]
decl_stmt|;
comment|/* path name (gag) */
block|}
struct|;
end_struct

begin_ifdef
ifdef|#
directive|ifdef
name|KERNEL
end_ifdef

begin_function_decl
name|int
name|unp_discard
parameter_list|()
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

end_unit

