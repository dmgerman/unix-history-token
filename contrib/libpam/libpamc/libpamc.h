begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * $Id: libpamc.h,v 1.2 2000/11/19 23:54:03 agmorgan Exp $  *  * Copyright (c) Andrew G. Morgan<morgan@ftp.kernel.org>  *  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|LIBPAMC_H
end_ifndef

begin_define
define|#
directive|define
name|LIBPAMC_H
end_define

begin_include
include|#
directive|include
file|<security/pam_client.h>
end_include

begin_include
include|#
directive|include
file|<security/_pam_macros.h>
end_include

begin_include
include|#
directive|include
file|<sys/stat.h>
end_include

begin_include
include|#
directive|include
file|<unistd.h>
end_include

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|<dirent.h>
end_include

begin_include
include|#
directive|include
file|<sys/wait.h>
end_include

begin_include
include|#
directive|include
file|<stdlib.h>
end_include

begin_include
include|#
directive|include
file|<errno.h>
end_include

begin_include
include|#
directive|include
file|<ctype.h>
end_include

begin_define
define|#
directive|define
name|_PAMC_DEFAULT_TOP_FD
value|10
end_define

begin_struct
struct|struct
name|pamc_handle_s
block|{
name|struct
name|pamc_agent_s
modifier|*
name|current
decl_stmt|;
name|struct
name|pamc_agent_s
modifier|*
name|chain
decl_stmt|;
name|struct
name|pamc_blocked_s
modifier|*
name|blocked_agents
decl_stmt|;
name|int
name|max_path
decl_stmt|;
name|char
modifier|*
modifier|*
name|agent_paths
decl_stmt|;
name|int
name|combined_status
decl_stmt|;
name|int
name|highest_fd_to_close
decl_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
struct|struct
name|pamc_blocked_s
block|{
name|char
modifier|*
name|id
decl_stmt|;
comment|/*<NUL> terminated */
name|struct
name|pamc_blocked_s
modifier|*
name|next
decl_stmt|;
block|}
name|pamc_blocked_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|pamc_agent_s
block|{
name|char
modifier|*
name|id
decl_stmt|;
name|int
name|id_length
decl_stmt|;
name|struct
name|pamc_agent_s
modifier|*
name|next
decl_stmt|;
name|int
name|writer
decl_stmt|;
comment|/* write to agent */
name|int
name|reader
decl_stmt|;
comment|/* read from agent */
name|pid_t
name|pid
decl_stmt|;
comment|/* agent process id */
block|}
name|pamc_agent_t
typedef|;
end_typedef

begin_comment
comment|/* used to build a tree of unique, sorted agent ids */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|pamc_id_node
block|{
name|struct
name|pamc_id_node
modifier|*
name|left
decl_stmt|,
modifier|*
name|right
decl_stmt|;
name|int
name|child_count
decl_stmt|;
name|char
modifier|*
name|agent_id
decl_stmt|;
block|}
name|pamc_id_node_t
typedef|;
end_typedef

begin_comment
comment|/* internal function */
end_comment

begin_function_decl
name|int
name|__pamc_valid_agent_id
parameter_list|(
name|int
name|id_length
parameter_list|,
specifier|const
name|char
modifier|*
name|id
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|PAMC_SYSTEM_AGENT_PATH
value|"/lib/pamc:/usr/lib/pamc"
end_define

begin_define
define|#
directive|define
name|PAMC_SYSTEM_AGENT_SEPARATOR
value|':'
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* LIBPAMC_H */
end_comment

end_unit

