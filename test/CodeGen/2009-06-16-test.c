begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_ifndef
ifndef|#
directive|ifndef
name|TEST
end_ifndef

begin_define
define|#
directive|define
name|TEST
end_define

begin_define
define|#
directive|define
name|INSIDE_RECURSION
end_define

begin_include
include|#
directive|include
file|"2009-06-16-test.c"
end_include

begin_undef
undef|#
directive|undef
name|INSIDE_RECURSION
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|INSIDE_RECURSION
end_ifndef

begin_decl_stmt
name|int
name|i
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_escape
end_escape

begin_ifdef
ifdef|#
directive|ifdef
name|INSIDE_RECURSION
end_ifdef

begin_decl_stmt
name|int
name|j
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

