begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  *	    Written by Toshiharu OHNO (tony-o@iij.ad.jp)  *  *   Copyright (C) 1993, Internet Initiative Japan, Inc. All rights reserverd.  *  * Redistribution and use in source and binary forms are permitted  * provided that the above copyright notice and this paragraph are  * duplicated in all such forms and that any documentation,  * advertising materials, and other materials related to such  * distribution and use acknowledge that the software was developed  * by the Internet Initiative Japan.  The name of the  * IIJ may not be used to endorse or promote products derived  * from this software without specific prior written permission.  * THIS SOFTWARE IS PROVIDED ``AS IS'' AND WITHOUT ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, WITHOUT LIMITATION, THE IMPLIED  * WARRANTIES OF MERCHANTIBILITY AND FITNESS FOR A PARTICULAR PURPOSE.  *  * $Id: timer.h,v 1.6 1998/05/21 21:48:49 brian Exp $  *  *	TODO:  */
end_comment

begin_define
define|#
directive|define
name|TICKUNIT
value|100000
end_define

begin_comment
comment|/* usec's per Unit */
end_comment

begin_define
define|#
directive|define
name|SECTICKS
value|(1000000/TICKUNIT)
end_define

begin_comment
comment|/* Units per second */
end_comment

begin_struct
struct|struct
name|pppTimer
block|{
name|int
name|state
decl_stmt|;
specifier|const
name|char
modifier|*
name|name
decl_stmt|;
name|u_long
name|rest
decl_stmt|;
comment|/* Ticks to expire */
name|u_long
name|load
decl_stmt|;
comment|/* Initial load value */
name|void
function_decl|(
modifier|*
name|func
function_decl|)
parameter_list|(
name|void
modifier|*
parameter_list|)
function_decl|;
comment|/* Function called when timer is expired */
name|void
modifier|*
name|arg
decl_stmt|;
comment|/* Argument passed to timeout function */
name|struct
name|pppTimer
modifier|*
name|next
decl_stmt|;
comment|/* Link to next timer */
name|struct
name|pppTimer
modifier|*
name|enext
decl_stmt|;
comment|/* Link to next expired timer */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|TIMER_STOPPED
value|0
end_define

begin_define
define|#
directive|define
name|TIMER_RUNNING
value|1
end_define

begin_define
define|#
directive|define
name|TIMER_EXPIRED
value|2
end_define

begin_struct_decl
struct_decl|struct
name|prompt
struct_decl|;
end_struct_decl

begin_function_decl
specifier|extern
name|void
name|timer_Start
parameter_list|(
name|struct
name|pppTimer
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|timer_Stop
parameter_list|(
name|struct
name|pppTimer
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|timer_InitService
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|timer_TermService
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|timer_Show
parameter_list|(
name|int
name|LogLevel
parameter_list|,
name|struct
name|prompt
modifier|*
parameter_list|)
function_decl|;
end_function_decl

end_unit

