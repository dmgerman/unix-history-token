begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Set up the global argc/argv info for use by getarg_, iargc_, and    g77's inlined intrinsic equivalents.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|KR_headers
end_ifndef

begin_undef
undef|#
directive|undef
name|VOID
end_undef

begin_include
include|#
directive|include
file|<stdlib.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|VOID
end_ifndef

begin_define
define|#
directive|define
name|VOID
value|void
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
name|int
name|f__xargc
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
modifier|*
name|f__xargv
decl_stmt|;
end_decl_stmt

begin_ifdef
ifdef|#
directive|ifdef
name|__cplusplus
end_ifdef

begin_endif
unit|}
endif|#
directive|endif
end_endif

begin_ifdef
unit|void
ifdef|#
directive|ifdef
name|KR_headers
end_ifdef

begin_macro
name|f_setarg
argument_list|(
argument|argc
argument_list|,
argument|argv
argument_list|)
end_macro

begin_decl_stmt
name|int
name|argc
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
modifier|*
name|argv
decl_stmt|;
end_decl_stmt

begin_else
else|#
directive|else
end_else

begin_macro
name|f_setarg
argument_list|(
argument|int argc
argument_list|,
argument|char **argv
argument_list|)
end_macro

begin_endif
endif|#
directive|endif
end_endif

begin_block
block|{
name|f__xargc
operator|=
name|argc
expr_stmt|;
name|f__xargv
operator|=
name|argv
expr_stmt|;
block|}
end_block

end_unit

