begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// The -*- C++ -*- standard definitions header.
end_comment

begin_comment
comment|// This file is part of the GNU ANSI C++ Library.
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__STDDEF__
end_ifndef

begin_define
define|#
directive|define
name|__STDDEF__
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|__GNUG__
end_ifdef

begin_pragma
pragma|#
directive|pragma
name|interface
literal|"std/stddef.h"
end_pragma

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<_G_config.h>
end_include

begin_include
include|#
directive|include
file|<std/cstddef.h>
end_include

begin_extern
extern|extern
literal|"C++"
block|{
specifier|const
name|size_t
name|NPOS
init|=
call|(
name|size_t
call|)
argument_list|(
operator|-
literal|1
argument_list|)
decl_stmt|;
typedef|typedef
name|void
name|fvoid_t
parameter_list|()
function_decl|;
ifndef|#
directive|ifndef
name|_WINT_T
define|#
directive|define
name|_WINT_T
typedef|typedef
name|_G_wint_t
name|wint_t
typedef|;
endif|#
directive|endif
block|}
end_extern

begin_comment
comment|// extern "C++"
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

