begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* @(#)s_lib_ver.c 5.1 93/09/24 */
end_comment

begin_comment
comment|/*  * ====================================================  * Copyright (C) 1993 by Sun Microsystems, Inc. All rights reserved.  *  * Developed at SunPro, a Sun Microsystems, Inc. business.  * Permission to use, copy, modify, and distribute this  * software is freely granted, provided that this notice  * is preserved.  * ====================================================  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|lint
end_ifndef

begin_decl_stmt
specifier|static
name|char
name|rcsid
index|[]
init|=
literal|"$FreeBSD$"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * MACRO for standards  */
end_comment

begin_include
include|#
directive|include
file|"math.h"
end_include

begin_include
include|#
directive|include
file|"math_private.h"
end_include

begin_comment
comment|/*  * define and initialize _LIB_VERSION  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|_POSIX_MODE
end_ifdef

begin_decl_stmt
name|_LIB_VERSION_TYPE
name|_LIB_VERSION
init|=
name|_POSIX_
decl_stmt|;
end_decl_stmt

begin_else
else|#
directive|else
end_else

begin_ifdef
ifdef|#
directive|ifdef
name|_XOPEN_MODE
end_ifdef

begin_decl_stmt
name|_LIB_VERSION_TYPE
name|_LIB_VERSION
init|=
name|_XOPEN_
decl_stmt|;
end_decl_stmt

begin_else
else|#
directive|else
end_else

begin_ifdef
ifdef|#
directive|ifdef
name|_SVID3_MODE
end_ifdef

begin_decl_stmt
name|_LIB_VERSION_TYPE
name|_LIB_VERSION
init|=
name|_SVID_
decl_stmt|;
end_decl_stmt

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* default _IEEE_MODE */
end_comment

begin_decl_stmt
name|_LIB_VERSION_TYPE
name|_LIB_VERSION
init|=
name|_IEEE_
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

end_unit

