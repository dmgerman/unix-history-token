begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* sgmlsasp.h */
end_comment

begin_include
include|#
directive|include
file|"config.h"
end_include

begin_include
include|#
directive|include
file|"std.h"
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|USE_PROTOTYPES
end_ifdef

begin_define
define|#
directive|define
name|P
parameter_list|(
name|parms
parameter_list|)
value|parms
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|P
parameter_list|(
name|parms
parameter_list|)
value|()
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|__GNUC__
end_ifdef

begin_define
define|#
directive|define
name|NO_RETURN
value|volatile
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|NO_RETURN
end_define

begin_comment
comment|/* as nothing */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|VARARGS
end_ifdef

begin_define
define|#
directive|define
name|VP
parameter_list|(
name|parms
parameter_list|)
value|()
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|VP
parameter_list|(
name|parms
parameter_list|)
value|P(parms)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
name|NO_RETURN
name|void
name|error
name|VP
argument_list|(
operator|(
name|char
operator|*
operator|,
operator|...
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|fold_general_names
decl_stmt|;
end_decl_stmt

end_unit

