begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// This may look like C code, but it is really -*- C++ -*-
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_Complex_h
end_ifndef

begin_define
define|#
directive|define
name|_Complex_h
end_define

begin_comment
comment|// Use the ANSI complex number template.
end_comment

begin_include
include|#
directive|include
file|<complex>
end_include

begin_typedef
typedef|typedef
name|complex
operator|<
name|double
operator|>
name|Complex
expr_stmt|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

end_unit

