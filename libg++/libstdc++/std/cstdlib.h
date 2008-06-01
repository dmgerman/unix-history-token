begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// The -*- C++ -*- standard library header.
end_comment

begin_comment
comment|// This file is part of the GNU ANSI C++ Library.
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__CSTDLIB__
end_ifndef

begin_define
define|#
directive|define
name|__CSTDLIB__
end_define

begin_include
include|#
directive|include
file|<stdlib.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|__GNUG__
end_ifdef

begin_pragma
pragma|#
directive|pragma
name|interface
literal|"std/cstdlib.h"
end_pragma

begin_endif
endif|#
directive|endif
end_endif

begin_extern
extern|extern
literal|"C++"
block|{
if|#
directive|if
name|_G_HAS_LABS
specifier|inline
name|long
name|abs
parameter_list|(
name|long
name|x
parameter_list|)
block|{
return|return
name|labs
argument_list|(
name|x
argument_list|)
return|;
block|}
else|#
directive|else
specifier|inline
name|long
name|abs
parameter_list|(
name|long
name|x
parameter_list|)
block|{
return|return
name|x
operator|>=
literal|0
condition|?
name|x
else|:
operator|-
name|x
return|;
block|}
endif|#
directive|endif
comment|//inline ldiv_t div(long x, long y)	{ return ldiv (x, y); }
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

