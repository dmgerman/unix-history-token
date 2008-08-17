begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  Copyright (C) 1996 N.M. Maclaren     Copyright (C) 1996 The University of Cambridge  This includes all of the 'safe' headers and definitions used across modules. No changes should be needed for any system that is even remotely like Unix. */
end_comment

begin_include
include|#
directive|include
file|<ctype.h>
end_include

begin_include
include|#
directive|include
file|<errno.h>
end_include

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_include
include|#
directive|include
file|<stdlib.h>
end_include

begin_include
include|#
directive|include
file|<string.h>
end_include

begin_include
include|#
directive|include
file|<time.h>
end_include

begin_define
define|#
directive|define
name|VERSION
value|"1.6"
end_define

begin_comment
comment|/* Just the version string */
end_comment

begin_define
define|#
directive|define
name|MAX_SOCKETS
value|10
end_define

begin_comment
comment|/* Maximum number of addresses */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|LOCKNAME
end_ifndef

begin_define
define|#
directive|define
name|LOCKNAME
value|"/etc/msntp.pid"
end_define

begin_comment
comment|/* Stores the pid */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|SAVENAME
end_ifndef

begin_define
define|#
directive|define
name|SAVENAME
value|"/etc/msntp.state"
end_define

begin_comment
comment|/* Stores the recovery state */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Defined in main.c */
end_comment

begin_define
define|#
directive|define
name|op_client
value|1
end_define

begin_comment
comment|/* Behave as a challenge client */
end_comment

begin_define
define|#
directive|define
name|op_server
value|2
end_define

begin_comment
comment|/* Behave as a response server */
end_comment

begin_define
define|#
directive|define
name|op_listen
value|3
end_define

begin_comment
comment|/* Behave as a listening client */
end_comment

begin_define
define|#
directive|define
name|op_broadcast
value|4
end_define

begin_comment
comment|/* Behave as a broadcast server */
end_comment

begin_decl_stmt
specifier|extern
specifier|const
name|char
modifier|*
name|argv0
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|verbose
decl_stmt|,
name|operation
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
specifier|const
name|char
modifier|*
name|lockname
decl_stmt|;
end_decl_stmt

begin_function_decl
specifier|extern
name|void
name|fatal
parameter_list|(
name|int
name|syserr
parameter_list|,
specifier|const
name|char
modifier|*
name|message
parameter_list|,
specifier|const
name|char
modifier|*
name|insert
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Defined in unix.c */
end_comment

begin_function_decl
specifier|extern
name|void
name|do_nothing
parameter_list|(
name|int
name|seconds
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|ftty
parameter_list|(
name|FILE
modifier|*
name|file
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|set_lock
parameter_list|(
name|int
name|lock
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|log_message
parameter_list|(
specifier|const
name|char
modifier|*
name|message
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Defined in internet.c */
end_comment

begin_comment
comment|/* extern void find_address (struct in_addr *address, int *port, char *hostname,     int timespan); */
end_comment

begin_define
define|#
directive|define
name|PREF_FAM_INET
value|1
end_define

begin_define
define|#
directive|define
name|PREF_FAM_INET6
value|2
end_define

begin_function_decl
specifier|extern
name|void
name|preferred_family
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Defined in socket.c */
end_comment

begin_function_decl
specifier|extern
name|void
name|open_socket
parameter_list|(
name|int
name|which
parameter_list|,
name|char
modifier|*
name|hostnames
parameter_list|,
name|int
name|timespan
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|write_socket
parameter_list|(
name|int
name|which
parameter_list|,
name|void
modifier|*
name|packet
parameter_list|,
name|int
name|length
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|read_socket
parameter_list|(
name|int
name|which
parameter_list|,
name|void
modifier|*
name|packet
parameter_list|,
name|int
name|length
parameter_list|,
name|int
name|waiting
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|flush_socket
parameter_list|(
name|int
name|which
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|close_socket
parameter_list|(
name|int
name|which
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Defined in timing.c */
end_comment

begin_function_decl
specifier|extern
name|double
name|current_time
parameter_list|(
name|double
name|offset
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|time_t
name|convert_time
parameter_list|(
name|double
name|value
parameter_list|,
name|int
modifier|*
name|millisecs
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|adjust_time
parameter_list|(
name|double
name|difference
parameter_list|,
name|int
name|immediate
parameter_list|,
name|double
name|ignore
parameter_list|)
function_decl|;
end_function_decl

end_unit

