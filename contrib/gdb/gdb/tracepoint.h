begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Data structures associated with tracepoints in GDB.    Copyright (C) 1997 Free Software Foundation, Inc.  This file is part of GDB.  This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version.  This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with this program; if not, write to the Free Software Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
end_comment

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|TRACEPOINT_H
argument_list|)
end_if

begin_define
define|#
directive|define
name|TRACEPOINT_H
value|1
end_define

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|BREAKPOINT_H
argument_list|)
end_if

begin_enum
enum|enum
name|enable
block|{
name|disabled
block|,
name|enabled
block|}
enum|;
end_enum

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* The data structure for an action: */
end_comment

begin_struct
struct|struct
name|action_line
block|{
name|struct
name|action_line
modifier|*
name|next
decl_stmt|;
name|char
modifier|*
name|action
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* The data structure for a tracepoint: */
end_comment

begin_struct
struct|struct
name|tracepoint
block|{
name|struct
name|tracepoint
modifier|*
name|next
decl_stmt|;
name|enum
name|enable
name|enabled
decl_stmt|;
if|#
directive|if
literal|0
comment|/* Type of tracepoint (MVS FIXME: needed?). */
block|enum tptype type;
comment|/* What to do with this tracepoint after we hit it MVS FIXME: needed?). */
block|enum tpdisp disposition;
endif|#
directive|endif
comment|/* Number assigned to distinguish tracepoints.  */
name|int
name|number
decl_stmt|;
comment|/* Address to trace at, or NULL if not an instruction tracepoint (MVS ?). */
name|CORE_ADDR
name|address
decl_stmt|;
comment|/* Line number of this address.  Only matters if address is non-NULL.  */
name|int
name|line_number
decl_stmt|;
comment|/* Source file name of this address.  Only matters if address is non-NULL. */
name|char
modifier|*
name|source_file
decl_stmt|;
comment|/* Number of times this tracepoint should single-step       and collect additional data */
name|long
name|step_count
decl_stmt|;
comment|/* Number of times this tracepoint should be hit before disabling/ending. */
name|int
name|pass_count
decl_stmt|;
comment|/* Chain of action lines to execute when this tracepoint is hit. */
name|struct
name|action_line
modifier|*
name|actions
decl_stmt|;
comment|/* Conditional (MVS ?).  */
name|struct
name|expression
modifier|*
name|cond
decl_stmt|;
comment|/* String we used to set the tracepoint (malloc'd).  Only matters if      address is non-NULL.  */
name|char
modifier|*
name|addr_string
decl_stmt|;
comment|/* Language we used to set the tracepoint.  */
name|enum
name|language
name|language
decl_stmt|;
comment|/* Input radix we used to set the tracepoint.  */
name|int
name|input_radix
decl_stmt|;
comment|/* Count of the number of times this tracepoint was taken, dumped      with the info, but not used for anything else.  Useful for      seeing how many times you hit a tracepoint prior to the program      aborting, so you can back up to just before the abort.  */
name|int
name|hit_count
decl_stmt|;
comment|/* Thread number for thread-specific tracepoint, or -1 if don't care */
name|int
name|thread
decl_stmt|;
comment|/* BFD section, in case of overlays:       no, I don't know if tracepoints are really gonna work with overlays.  */
name|asection
modifier|*
name|section
decl_stmt|;
block|}
struct|;
end_struct

begin_enum
enum|enum
name|actionline_type
block|{
name|BADLINE
init|=
operator|-
literal|1
block|,
name|GENERIC
init|=
literal|0
block|,
name|END
init|=
literal|1
block|,
name|STEPPING
init|=
literal|2
block|}
enum|;
end_enum

begin_comment
comment|/* The tracepont chain of all tracepoints */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|tracepoint
modifier|*
name|tracepoint_chain
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|unsigned
name|long
name|trace_running_p
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* A hook used to notify the UI of tracepoint operations */
end_comment

begin_macro
name|void
argument_list|(
argument|*create_tracepoint_hook
argument_list|)
end_macro

begin_expr_stmt
name|PARAMS
argument_list|(
operator|(
expr|struct
name|tracepoint
operator|*
operator|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_macro
name|void
argument_list|(
argument|*delete_tracepoint_hook
argument_list|)
end_macro

begin_expr_stmt
name|PARAMS
argument_list|(
operator|(
expr|struct
name|tracepoint
operator|*
operator|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_macro
name|void
argument_list|(
argument|*modify_tracepoint_hook
argument_list|)
end_macro

begin_expr_stmt
name|PARAMS
argument_list|(
operator|(
expr|struct
name|tracepoint
operator|*
operator|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_macro
name|void
argument_list|(
argument|*trace_find_hook
argument_list|)
end_macro

begin_expr_stmt
name|PARAMS
argument_list|(
operator|(
name|char
operator|*
name|arg
operator|,
name|int
name|from_tty
operator|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_macro
name|void
argument_list|(
argument|*trace_start_stop_hook
argument_list|)
end_macro

begin_expr_stmt
name|PARAMS
argument_list|(
operator|(
name|int
name|start
operator|,
name|int
name|from_tty
operator|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_decl_stmt
name|struct
name|tracepoint
modifier|*
name|get_tracepoint_by_number
name|PARAMS
argument_list|(
operator|(
name|char
operator|*
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|get_traceframe_number
name|PARAMS
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|free_actions
name|PARAMS
argument_list|(
operator|(
expr|struct
name|tracepoint
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|enum
name|actionline_type
name|validate_actionline
name|PARAMS
argument_list|(
operator|(
name|char
operator|*
operator|*
operator|,
expr|struct
name|tracepoint
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Walk the following statement or block through all tracepoints.    ALL_TRACEPOINTS_SAFE does so even if the statment deletes the current    breakpoint.  */
end_comment

begin_define
define|#
directive|define
name|ALL_TRACEPOINTS
parameter_list|(
name|t
parameter_list|)
value|for (t = tracepoint_chain; t; t = t->next)
end_define

begin_define
define|#
directive|define
name|ALL_TRACEPOINTS_SAFE
parameter_list|(
name|t
parameter_list|,
name|tmp
parameter_list|)
define|\
value|for (t = tracepoint_chain;	\ 	     t ? (tmp = t->next, 1) : 0;\ 	     t = tmp)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* TRACEPOINT_H */
end_comment

end_unit

