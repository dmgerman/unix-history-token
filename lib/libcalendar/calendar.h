begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1997 Wolfgang Helbig  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	$Id: calendar.h,v 1.3.2.1 1998/01/12 05:11:19 obrien Exp $  */
end_comment

begin_struct
struct|struct
name|date
block|{
name|int
name|y
decl_stmt|;
comment|/* year */
name|int
name|m
decl_stmt|;
comment|/* month */
name|int
name|d
decl_stmt|;
comment|/* day */
block|}
struct|;
end_struct

begin_function_decl
name|struct
name|date
modifier|*
name|easterg
parameter_list|(
name|int
name|_year
parameter_list|,
name|struct
name|date
modifier|*
name|_dt
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|date
modifier|*
name|easterog
parameter_list|(
name|int
name|_year
parameter_list|,
name|struct
name|date
modifier|*
name|_dt
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|date
modifier|*
name|easteroj
parameter_list|(
name|int
name|_year
parameter_list|,
name|struct
name|date
modifier|*
name|_dt
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|date
modifier|*
name|gdate
parameter_list|(
name|int
name|_nd
parameter_list|,
name|struct
name|date
modifier|*
name|_dt
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|date
modifier|*
name|jdate
parameter_list|(
name|int
name|_nd
parameter_list|,
name|struct
name|date
modifier|*
name|_dt
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ndaysg
parameter_list|(
name|struct
name|date
modifier|*
name|_dt
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ndaysj
parameter_list|(
name|struct
name|date
modifier|*
name|_dt
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|week
parameter_list|(
name|int
name|_nd
parameter_list|,
name|int
modifier|*
name|_year
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|weekday
parameter_list|(
name|int
name|_nd
parameter_list|)
function_decl|;
end_function_decl

end_unit

