begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Timing variables for measuring compiler performance.    Copyright (C) 2000 Free Software Foundation, Inc.    Contributed by Alex Samuel<samuel@codesourcery.com>     This file is part of GCC.     GCC is free software; you can redistribute it and/or modify it    under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2, or (at your option)    any later version.     GCC is distributed in the hope that it will be useful, but WITHOUT    ANY WARRANTY; without even the implied warranty of MERCHANTABILITY    or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public    License for more details.     You should have received a copy of the GNU General Public License    along with GCC; see the file COPYING.  If not, write to the Free    Software Foundation, 59 Temple Place - Suite 330, Boston, MA    02111-1307, USA.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|GCC_TIMEVAR_H
end_ifndef

begin_define
define|#
directive|define
name|GCC_TIMEVAR_H
end_define

begin_comment
comment|/* Timing variables are used to measure elapsed time in various    portions of the compiler.  Each measures elapsed user, system, and    wall-clock time, as appropriate to and supported by the host    system.     Timing variables are defined using the DEFTIMEVAR macro in    timevar.def.  Each has an enumeral identifier, used when referring    to the timing variable in code, and a character string name.     Timing variables can be used in two ways:       - On the timing stack, using timevar_push and timevar_pop.        Timing variables may be pushed onto the stack; elapsed time is        attributed to the topmost timing variable on the stack.  When        another variable is pushed on, the previous topmost variable is        `paused' until the pushed variable is popped back off.       - As a standalone timer, using timevar_start and timevar_stop.        All time elapsed between the two calls is attributed to the        variable.   */
end_comment

begin_comment
comment|/* This structure stores the various varieties of time that can be    measured.  Times are stored in seconds.  The time may be an    absolute time or a time difference; in the former case, the time    base is undefined, except that the difference between two times    produces a valid time difference.  */
end_comment

begin_struct
struct|struct
name|timevar_time_def
block|{
comment|/* User time in this process.  */
name|float
name|user
decl_stmt|;
comment|/* System time (if applicable for this host platform) in this      process.  */
name|float
name|sys
decl_stmt|;
comment|/* Wall clock time.  */
name|float
name|wall
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* An enumeration of timing variable identifiers.  Constructed from    the contents of timevar.def.  */
end_comment

begin_define
define|#
directive|define
name|DEFTIMEVAR
parameter_list|(
name|identifier__
parameter_list|,
name|name__
parameter_list|)
define|\
value|identifier__,
end_define

begin_typedef
typedef|typedef
enum|enum
block|{
include|#
directive|include
file|"timevar.def"
name|TIMEVAR_LAST
block|}
name|timevar_id_t
typedef|;
end_typedef

begin_undef
undef|#
directive|undef
name|DEFTIMEVAR
end_undef

begin_decl_stmt
specifier|extern
name|void
name|init_timevar
name|PARAMS
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|timevar_push
name|PARAMS
argument_list|(
operator|(
name|timevar_id_t
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|timevar_pop
name|PARAMS
argument_list|(
operator|(
name|timevar_id_t
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|timevar_start
name|PARAMS
argument_list|(
operator|(
name|timevar_id_t
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|timevar_stop
name|PARAMS
argument_list|(
operator|(
name|timevar_id_t
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|timevar_get
name|PARAMS
argument_list|(
operator|(
name|timevar_id_t
operator|,
expr|struct
name|timevar_time_def
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|timevar_print
name|PARAMS
argument_list|(
operator|(
name|FILE
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Provided for backward compatibility.  */
end_comment

begin_decl_stmt
specifier|extern
name|long
name|get_run_time
name|PARAMS
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|print_time
name|PARAMS
argument_list|(
operator|(
specifier|const
name|char
operator|*
operator|,
name|long
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! GCC_TIMEVAR_H */
end_comment

end_unit

