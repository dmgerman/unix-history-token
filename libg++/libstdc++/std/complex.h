begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// Main header for the -*- C++ -*- complex number classes.
end_comment

begin_comment
comment|// This file is part of the GNU ANSI C++ Library.
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__COMPLEX__
end_ifndef

begin_define
define|#
directive|define
name|__COMPLEX__
end_define

begin_include
include|#
directive|include
file|<std/complext.h>
end_include

begin_extern
extern|extern
literal|"C++"
block|{
define|#
directive|define
name|__STD_COMPLEX
comment|// ANSI complex types
typedef|typedef
name|complex
operator|<
name|float
operator|>
name|float_complex
expr_stmt|;
typedef|typedef
name|complex
operator|<
name|double
operator|>
name|double_complex
expr_stmt|;
typedef|typedef
name|complex
operator|<
name|long
name|double
operator|>
name|long_double_complex
expr_stmt|;
block|}
end_extern

begin_endif
endif|#
directive|endif
end_endif

end_unit

