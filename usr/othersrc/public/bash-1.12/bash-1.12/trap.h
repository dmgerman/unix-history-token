begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* trap.h -- data structures used in the trap mechanism. */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|NSIG
end_ifndef

begin_include
include|#
directive|include
file|<signal.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|NSIG
end_ifndef

begin_define
define|#
directive|define
name|NSIG
value|64
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|NO_SIG
value|-1
end_define

begin_define
define|#
directive|define
name|DEFAULT_SIG
value|SIG_DFL
end_define

begin_define
define|#
directive|define
name|IGNORE_SIG
value|SIG_IGN
end_define

begin_define
define|#
directive|define
name|signal_object_p
parameter_list|(
name|x
parameter_list|)
value|(decode_signal (x) != NO_SIG)
end_define

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|trap_list
index|[
name|NSIG
index|]
decl_stmt|;
end_decl_stmt

begin_function_decl
specifier|extern
name|char
modifier|*
name|signal_name
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|signal_decode
parameter_list|()
function_decl|;
end_function_decl

end_unit

