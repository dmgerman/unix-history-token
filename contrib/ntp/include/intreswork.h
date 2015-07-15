begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * intreswork.h -- declarations private to ntp_intres.c, ntp_worker.c.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|INTRESWORK_H
end_ifndef

begin_define
define|#
directive|define
name|INTRESWORK_H
end_define

begin_include
include|#
directive|include
file|"ntp_worker.h"
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|WORKER
end_ifdef

begin_function_decl
specifier|extern
name|int
name|blocking_getaddrinfo
parameter_list|(
name|blocking_child
modifier|*
parameter_list|,
name|blocking_pipe_header
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|blocking_getnameinfo
parameter_list|(
name|blocking_child
modifier|*
parameter_list|,
name|blocking_pipe_header
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_ifdef
ifdef|#
directive|ifdef
name|TEST_BLOCKING_WORKER
end_ifdef

begin_function_decl
specifier|extern
name|void
name|gai_test_callback
parameter_list|(
name|int
name|rescode
parameter_list|,
name|int
name|gai_errno
parameter_list|,
name|void
modifier|*
name|context
parameter_list|,
specifier|const
name|char
modifier|*
name|name
parameter_list|,
specifier|const
name|char
modifier|*
name|service
parameter_list|,
specifier|const
name|struct
name|addrinfo
modifier|*
name|hints
parameter_list|,
specifier|const
name|struct
name|addrinfo
modifier|*
name|ai_res
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|gni_test_callback
parameter_list|(
name|int
name|rescode
parameter_list|,
name|int
name|gni_errno
parameter_list|,
name|sockaddr_u
modifier|*
name|psau
parameter_list|,
name|int
name|flags
parameter_list|,
specifier|const
name|char
modifier|*
name|host
parameter_list|,
specifier|const
name|char
modifier|*
name|service
parameter_list|,
name|void
modifier|*
name|context
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* TEST_BLOCKING_WORKER */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* WORKER */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* INTRESWORK_H */
end_comment

end_unit

