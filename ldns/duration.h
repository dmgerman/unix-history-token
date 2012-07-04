begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * $Id: duration.h 4341 2011-01-31 15:21:09Z matthijs $  *  * Copyright (c) 2009 NLNet Labs. All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED  * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY  * DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE  * GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS  * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER  * IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR  * OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN  * IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  */
end_comment

begin_comment
comment|/**  *  * This file is copied from the OpenDNSSEC source repository  * and only slightly adapted to make it fit.  */
end_comment

begin_comment
comment|/**  *  * Durations.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|LDNS_DURATION_H
end_ifndef

begin_define
define|#
directive|define
name|LDNS_DURATION_H
end_define

begin_include
include|#
directive|include
file|<stdint.h>
end_include

begin_include
include|#
directive|include
file|<time.h>
end_include

begin_comment
comment|/**  * Duration.  *  */
end_comment

begin_typedef
typedef|typedef
name|struct
name|ldns_duration_struct
name|ldns_duration_type
typedef|;
end_typedef

begin_struct
struct|struct
name|ldns_duration_struct
block|{
name|time_t
name|years
decl_stmt|;
name|time_t
name|months
decl_stmt|;
name|time_t
name|weeks
decl_stmt|;
name|time_t
name|days
decl_stmt|;
name|time_t
name|hours
decl_stmt|;
name|time_t
name|minutes
decl_stmt|;
name|time_t
name|seconds
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/**  * Create a new 'instant' duration.  * \return ldns_duration_type* created duration  *  */
end_comment

begin_function_decl
name|ldns_duration_type
modifier|*
name|ldns_duration_create
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Compare durations.  * \param[in] d1 one duration  * \param[in] d2 another duration  * \return int 0 if equal, -1 if d1< d2, 1 if d2< d1  *  */
end_comment

begin_function_decl
name|int
name|ldns_duration_compare
parameter_list|(
name|ldns_duration_type
modifier|*
name|d1
parameter_list|,
name|ldns_duration_type
modifier|*
name|d2
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Create a duration from string.  * \param[in] str string-format duration  * \return ldns_duration_type* created duration  *  */
end_comment

begin_function_decl
name|ldns_duration_type
modifier|*
name|ldns_duration_create_from_string
parameter_list|(
specifier|const
name|char
modifier|*
name|str
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Convert a duration to a string.  * \param[in] duration duration to be converted  * \return char* string-format duration  *  */
end_comment

begin_function_decl
name|char
modifier|*
name|ldns_duration2string
parameter_list|(
name|ldns_duration_type
modifier|*
name|duration
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Convert a duration to a time.  * \param[in] duration duration to be converted  * \return time_t time-format duration  *  */
end_comment

begin_function_decl
name|time_t
name|ldns_duration2time
parameter_list|(
name|ldns_duration_type
modifier|*
name|duration
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Clean up duration.  * \param[in] duration duration to be cleaned up  *  */
end_comment

begin_function_decl
name|void
name|ldns_duration_cleanup
parameter_list|(
name|ldns_duration_type
modifier|*
name|duration
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* LDNS_DURATION_H */
end_comment

end_unit

