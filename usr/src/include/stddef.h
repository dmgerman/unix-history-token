begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1990 The Regents of the University of California.  * All rights reserved.  *  * %sccs.include.redist.c%  *  *	@(#)stddef.h	5.2 (Berkeley) %G%  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_STDDEF_H_
end_ifndef

begin_define
define|#
directive|define
name|_STDDEF_H_
end_define

begin_include
include|#
directive|include
file|<machine/machtypes.h>
end_include

begin_typedef
typedef|typedef
name|_PTRDIFF_T_
name|ptrdiff_t
typedef|;
end_typedef

begin_ifdef
ifdef|#
directive|ifdef
name|_SIZE_T_
end_ifdef

begin_typedef
typedef|typedef
name|_SIZE_T_
name|size_t
typedef|;
end_typedef

begin_undef
undef|#
directive|undef
name|_SIZE_T_
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|_WCHAR_T_
end_ifdef

begin_typedef
typedef|typedef
name|_WCHAR_T_
name|wchar_t
typedef|;
end_typedef

begin_undef
undef|#
directive|undef
name|_WCHAR_T_
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|NULL
end_ifndef

begin_define
define|#
directive|define
name|NULL
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|offsetof
parameter_list|(
name|type
parameter_list|,
name|member
parameter_list|)
value|((size_t)(&((type *)0)->member))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _STDDEF_H_ */
end_comment

end_unit

