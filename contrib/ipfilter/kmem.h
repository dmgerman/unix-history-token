begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (C) 1993-1997 by Darren Reed.  *  * Redistribution and use in source and binary forms are permitted  * provided that this notice is preserved and due credit is given  * to the original author and the contributors.  * $Id: kmem.h,v 2.0.2.6 1997/09/28 07:12:02 darrenr Exp $  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__KMEM_H__
end_ifndef

begin_define
define|#
directive|define
name|__KMEM_H__
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|__P
end_ifndef

begin_ifdef
ifdef|#
directive|ifdef
name|__STDC__
end_ifdef

begin_define
define|#
directive|define
name|__P
parameter_list|(
name|x
parameter_list|)
value|x
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|__P
parameter_list|(
name|x
parameter_list|)
value|()
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
specifier|extern
name|int
name|openkmem
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|kmemcpy
name|__P
argument_list|(
operator|(
name|char
operator|*
operator|,
name|long
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|KMEM
value|"/dev/kmem"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __KMEM_H__ */
end_comment

end_unit

