begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* "unixlib.h"	--  limited substitute for VAX C V3.x's<unixlib.h>,  * for use with VAX C V2.x and/or GNU C when building gawk.  */
end_comment

begin_comment
comment|/* declare the global environ[] array */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|VAXC
end_ifdef

begin_decl_stmt
specifier|extern
name|char
name|noshare
modifier|*
modifier|*
name|environ
decl_stmt|;
end_decl_stmt

begin_else
else|#
directive|else
end_else

begin_ifdef
ifdef|#
directive|ifdef
name|__GNUC__
end_ifdef

begin_define
define|#
directive|define
name|environ
value|$$PsectAttributes_NOSHR$$environ
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
specifier|extern
name|char
modifier|*
modifier|*
name|environ
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* miscellaneous Unix emulation routines available in VAXCRTL */
end_comment

begin_decl_stmt
name|char
modifier|*
name|getenv
argument_list|()
decl_stmt|,
modifier|*
name|getcwd
argument_list|()
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|ecvt
argument_list|()
decl_stmt|,
modifier|*
name|fcvt
argument_list|()
decl_stmt|,
modifier|*
name|gcvt
argument_list|()
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|getpid
argument_list|()
decl_stmt|,
name|getppid
argument_list|()
decl_stmt|;
end_decl_stmt

begin_function_decl
name|unsigned
name|getuid
parameter_list|()
function_decl|;
end_function_decl

begin_ifndef
ifndef|#
directive|ifndef
name|_stdlib_h
end_ifndef

begin_comment
comment|/* gcc's stdlib.h has these with conflicting types */
end_comment

begin_decl_stmt
name|unsigned
name|getgid
argument_list|()
decl_stmt|,
name|getegid
argument_list|()
decl_stmt|,
name|geteuid
argument_list|()
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
name|int
name|setgid
argument_list|()
decl_stmt|,
name|setuid
argument_list|()
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* no-ops */
end_comment

end_unit

