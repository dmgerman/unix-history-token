begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// Main header for the -*- C++ -*- string classes.
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__STRING__
end_ifndef

begin_define
define|#
directive|define
name|__STRING__
end_define

begin_include
include|#
directive|include
file|<std/bastring.h>
end_include

begin_extern
extern|extern
literal|"C++"
block|{
typedef|typedef
name|basic_string
operator|<
name|char
operator|,
name|string_char_traits
operator|<
name|char
operator|>
expr|>
name|string
expr_stmt|;
comment|// typedef basic_string<wchar_t, string_char_traits<wchar_t>> wstring;
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

