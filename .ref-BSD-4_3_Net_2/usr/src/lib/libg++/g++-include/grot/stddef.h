begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// This may look like C code, but it is really -*- C++ -*-
end_comment

begin_comment
comment|/*  Copyright (C) 1988 Free Software Foundation     written by Doug Lea (dl@rocky.oswego.edu)  This file is part of GNU CC.  GNU CC is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY.  No author or distributor accepts responsibility to anyone for the consequences of using it or for whether it serves any particular purpose or works at all, unless he says so in writing.  Refer to the GNU CC General Public License for full details.  Everyone is granted permission to copy, modify and redistribute GNU CC, but only under the conditions described in the GNU CC General Public License.   A copy of this license is supposed to have been given to you along with GNU CC so you can know your rights and responsibilities.  It should be in a file named COPYING.  Among other things, the copyright notice and this notice must be preserved on all copies.   */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_stddef_h
end_ifndef

begin_ifdef
ifdef|#
directive|ifdef
name|__GNUG__
end_ifdef

begin_pragma
pragma|#
directive|pragma
name|once
end_pragma

begin_pragma
pragma|#
directive|pragma
name|interface
end_pragma

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|_stddef_h
end_define

begin_comment
comment|// TRUE, FALSE, bool, are now in<bool.h>, for ANSI compatibility
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_SIZE_T
end_ifndef

begin_ifndef
ifndef|#
directive|ifndef
name|_SIZE_T_
end_ifndef

begin_typedef
typedef|typedef
name|unsigned
name|int
name|size_t
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|_PTRDIFF_T
end_ifndef

begin_ifndef
ifndef|#
directive|ifndef
name|_PTRDIFF_T_
end_ifndef

begin_typedef
typedef|typedef
name|long
name|int
name|ptrdiff_t
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|DGUX
end_ifdef

begin_typedef
typedef|typedef
name|int
name|wchar_t
typedef|;
end_typedef

begin_else
else|#
directive|else
end_else

begin_typedef
typedef|typedef
name|unsigned
name|short
name|wchar_t
typedef|;
end_typedef

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

begin_comment
comment|/* Offset of member MEMBER in a struct of type TYPE.  */
end_comment

begin_define
define|#
directive|define
name|offsetof
parameter_list|(
name|TYPE
parameter_list|,
name|MEMBER
parameter_list|)
value|((size_t)&((TYPE *)0)->MEMBER)
end_define

begin_endif
endif|#
directive|endif
end_endif

end_unit

