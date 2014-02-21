begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Timing variables for measuring compiler performance.    Copyright (C) 2000, 2003, 2004, 2005 Free Software Foundation, Inc.    Contributed by Alex Samuel<samuel@codesourcery.com>     This file is part of GCC.     GCC is free software; you can redistribute it and/or modify it    under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2, or (at your option)    any later version.     GCC is distributed in the hope that it will be useful, but WITHOUT    ANY WARRANTY; without even the implied warranty of MERCHANTABILITY    or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public    License for more details.     You should have received a copy of the GNU General Public License    along with GCC; see the file COPYING.  If not, write to the Free    Software Foundation, 51 Franklin Street, Fifth Floor, Boston, MA    02110-1301, USA.  */
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
comment|/* Timing variables are used to measure elapsed time in various    portions of the compiler.  Each measures elapsed user, system, and    wall-clock time, as appropriate to and supported by the host    system.     Timing variables are defined using the DEFTIMEVAR macro in    timevar.def.  Each has an enumeral identifier, used when referring    to the timing variable in code, and a character string name.     Timing variables can be used in two ways:       - On the timing stack, using timevar_push and timevar_pop.        Timing variables may be pushed onto the stack; elapsed time is        attributed to the topmost timing variable on the stack.  When        another variable is pushed on, the previous topmost variable is        `paused' until the pushed variable is popped back off.       - As a standalone timer, using timevar_start and timevar_stop.        All time elapsed between the two calls is attributed to the        variable. */
end_comment

begin_comment
comment|/* This structure stores the various varieties of time that can be    measured.  Times are stored in seconds.  The time may be an    absolute time or a time difference; in the former case, the time    base is undefined, except that the difference between two times    produces a valid time difference.  */
end_comment

begin_struct
struct|struct
name|timevar_time_def
block|{
comment|/* User time in this process.  */
name|double
name|user
decl_stmt|;
comment|/* System time (if applicable for this host platform) in this      process.  */
name|double
name|sys
decl_stmt|;
comment|/* Wall clock time.  */
name|double
name|wall
decl_stmt|;
comment|/* Garbage collector memory.  */
name|unsigned
name|ggc_mem
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

begin_comment
comment|/* Execute the sequence: timevar_pop (TV), return (E);  */
end_comment

begin_define
define|#
directive|define
name|POP_TIMEVAR_AND_RETURN
parameter_list|(
name|TV
parameter_list|,
name|E
parameter_list|)
value|do { timevar_pop (TV); return (E); }while(0)
end_define

begin_define
define|#
directive|define
name|timevar_pop
parameter_list|(
name|TV
parameter_list|)
value|do { if (timevar_enable) timevar_pop_1 (TV); }while(0)
end_define

begin_define
define|#
directive|define
name|timevar_push
parameter_list|(
name|TV
parameter_list|)
value|do { if (timevar_enable) timevar_push_1 (TV); }while(0)
end_define

begin_function_decl
specifier|extern
name|void
name|timevar_init
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|timevar_push_1
parameter_list|(
name|timevar_id_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|timevar_pop_1
parameter_list|(
name|timevar_id_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|timevar_start
parameter_list|(
name|timevar_id_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|timevar_stop
parameter_list|(
name|timevar_id_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|timevar_print
parameter_list|(
name|FILE
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Provided for backward compatibility.  */
end_comment

begin_function_decl
specifier|extern
name|void
name|print_time
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
name|long
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
specifier|extern
name|bool
name|timevar_enable
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|size_t
name|timevar_ggc_mem_total
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

