begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (C) 1993-1997 by Darren Reed.  *  * Redistribution and use in source and binary forms are permitted  * provided that this notice is preserved and due credit is given  * to the original author and the contributors.  * $Id: ipt.h,v 2.0.2.7 1997/09/28 07:12:00 darrenr Exp $  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__IPT_H__
end_ifndef

begin_define
define|#
directive|define
name|__IPT_H__
end_define

begin_include
include|#
directive|include
file|<fcntl.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|__STDC__
end_ifdef

begin_include
include|#
directive|include
file|<stdarg.h>
end_include

begin_else
else|#
directive|else
end_else

begin_include
include|#
directive|include
file|<varargs.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_struct
struct|struct
name|ipread
block|{
name|int
argument_list|(
argument|*r_open
argument_list|)
name|__P
argument_list|(
operator|(
name|char
operator|*
operator|)
argument_list|)
expr_stmt|;
name|int
argument_list|(
argument|*r_close
argument_list|)
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
expr_stmt|;
name|int
argument_list|(
argument|*r_readip
argument_list|)
name|__P
argument_list|(
operator|(
name|char
operator|*
operator|,
name|int
operator|,
name|char
operator|*
operator|*
operator|,
name|int
operator|*
operator|)
argument_list|)
expr_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
specifier|extern
name|void
name|debug
name|__P
argument_list|(
operator|(
name|char
operator|*
operator|,
operator|...
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|verbose
name|__P
argument_list|(
operator|(
name|char
operator|*
operator|,
operator|...
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __IPT_H__ */
end_comment

end_unit

