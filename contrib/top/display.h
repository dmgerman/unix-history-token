begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* constants needed for display.c */
end_comment

begin_comment
comment|/* "type" argument for new_message function */
end_comment

begin_define
define|#
directive|define
name|MT_standout
value|1
end_define

begin_define
define|#
directive|define
name|MT_delayed
value|2
end_define

begin_include
include|#
directive|include
file|"machine.h"
end_include

begin_function_decl
name|int
name|display_updatecpus
parameter_list|(
name|struct
name|statics
modifier|*
name|statics
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|clear_message
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|display_resize
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|i_header
parameter_list|(
name|char
modifier|*
name|text
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|printable
parameter_list|(
name|char
modifier|*
name|string
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|cpustates_tag
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|display_header
parameter_list|(
name|int
name|t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|display_init
parameter_list|(
name|struct
name|statics
modifier|*
name|statics
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|i_arc
parameter_list|(
name|int
modifier|*
name|stats
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|i_carc
parameter_list|(
name|int
modifier|*
name|stats
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|i_cpustates
parameter_list|(
name|int
modifier|*
name|states
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|i_loadave
parameter_list|(
name|int
name|mpid
parameter_list|,
name|double
modifier|*
name|avenrun
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|i_memory
parameter_list|(
name|int
modifier|*
name|stats
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|i_message
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|i_process
parameter_list|(
name|int
name|line
parameter_list|,
name|char
modifier|*
name|thisline
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|i_procstates
parameter_list|(
name|int
name|total
parameter_list|,
name|int
modifier|*
name|brkdn
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|i_swap
parameter_list|(
name|int
modifier|*
name|stats
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|i_timeofday
parameter_list|(
name|time_t
modifier|*
name|tod
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|i_uptime
parameter_list|(
name|struct
name|timeval
modifier|*
name|bt
parameter_list|,
name|time_t
modifier|*
name|tod
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|new_message
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|readline
parameter_list|(
name|char
modifier|*
name|buffer
parameter_list|,
name|int
name|size
parameter_list|,
name|int
name|numeric
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|trim_header
parameter_list|(
name|char
modifier|*
name|text
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|u_arc
parameter_list|(
name|int
modifier|*
name|stats
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|u_carc
parameter_list|(
name|int
modifier|*
name|stats
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|u_cpustates
parameter_list|(
name|int
modifier|*
name|states
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|u_endscreen
parameter_list|(
name|int
name|hi
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|u_header
parameter_list|(
name|char
modifier|*
name|text
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|u_loadave
parameter_list|(
name|int
name|mpid
parameter_list|,
name|double
modifier|*
name|avenrun
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|u_memory
parameter_list|(
name|int
modifier|*
name|stats
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|u_message
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|u_process
parameter_list|(
name|int
name|line
parameter_list|,
name|char
modifier|*
name|newline
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|u_procstates
parameter_list|(
name|int
name|total
parameter_list|,
name|int
modifier|*
name|brkdn
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|u_swap
parameter_list|(
name|int
modifier|*
name|stats
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|z_cpustates
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

end_unit

