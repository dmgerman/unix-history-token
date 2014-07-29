begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * util/timehist.h - make histogram of time values.  *  * Copyright (c) 2007, NLnet Labs. All rights reserved.  *  * This software is open source.  *   * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  *   * Redistributions of source code must retain the above copyright notice,  * this list of conditions and the following disclaimer.  *   * Redistributions in binary form must reproduce the above copyright notice,  * this list of conditions and the following disclaimer in the documentation  * and/or other materials provided with the distribution.  *   * Neither the name of the NLNET LABS nor the names of its contributors may  * be used to endorse or promote products derived from this software without  * specific prior written permission.  *   * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS  * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT  * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR  * A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT  * HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,  * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED  * TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR  * PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF  * LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING  * NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS  * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  */
end_comment

begin_comment
comment|/**  * \file  *  * This file contains functions to make a histogram of time values.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|UTIL_TIMEHIST_H
end_ifndef

begin_define
define|#
directive|define
name|UTIL_TIMEHIST_H
end_define

begin_comment
comment|/** Number of buckets in a histogram */
end_comment

begin_define
define|#
directive|define
name|NUM_BUCKETS_HIST
value|40
end_define

begin_comment
comment|/**  * Bucket of time history information  */
end_comment

begin_struct
struct|struct
name|th_buck
block|{
comment|/** lower bound */
name|struct
name|timeval
name|lower
decl_stmt|;
comment|/** upper bound */
name|struct
name|timeval
name|upper
decl_stmt|;
comment|/** number of items */
name|size_t
name|count
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/**  * Keep histogram of time values.  */
end_comment

begin_struct
struct|struct
name|timehist
block|{
comment|/** number of buckets */
name|size_t
name|num
decl_stmt|;
comment|/** bucket array */
name|struct
name|th_buck
modifier|*
name|buckets
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/**   * Setup a histogram, default  * @return histogram or NULL on malloc failure.  */
end_comment

begin_function_decl
name|struct
name|timehist
modifier|*
name|timehist_setup
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Delete histogram  * @param hist: to delete  */
end_comment

begin_function_decl
name|void
name|timehist_delete
parameter_list|(
name|struct
name|timehist
modifier|*
name|hist
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Clear histogram  * @param hist: to clear all data from  */
end_comment

begin_function_decl
name|void
name|timehist_clear
parameter_list|(
name|struct
name|timehist
modifier|*
name|hist
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Add time value to histogram.  * @param hist: histogram  * @param tv: time value  */
end_comment

begin_function_decl
name|void
name|timehist_insert
parameter_list|(
name|struct
name|timehist
modifier|*
name|hist
parameter_list|,
name|struct
name|timeval
modifier|*
name|tv
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Find time value for given quartile, such as 0.25, 0.50, 0.75.  * The looks up the value for the i-th element in the sorted list of time   * values, as approximated using the histogram.  * @param hist: histogram. Interpolated information is used from it.  * @param q: quartile, 0.50 results in the median. Must be>0 and<1.  * @return: the time in seconds for that percentage.  */
end_comment

begin_function_decl
name|double
name|timehist_quartile
parameter_list|(
name|struct
name|timehist
modifier|*
name|hist
parameter_list|,
name|double
name|q
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Printout histogram  * @param hist: histogram  */
end_comment

begin_function_decl
name|void
name|timehist_print
parameter_list|(
name|struct
name|timehist
modifier|*
name|hist
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Log histogram, print it to the logfile.  * @param hist: histogram  * @param name: the name of the value column  */
end_comment

begin_function_decl
name|void
name|timehist_log
parameter_list|(
name|struct
name|timehist
modifier|*
name|hist
parameter_list|,
specifier|const
name|char
modifier|*
name|name
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Export histogram to an array.  * @param hist: histogram  * @param array: the array to export to.  * @param sz: number of items in array.  */
end_comment

begin_function_decl
name|void
name|timehist_export
parameter_list|(
name|struct
name|timehist
modifier|*
name|hist
parameter_list|,
name|size_t
modifier|*
name|array
parameter_list|,
name|size_t
name|sz
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Import histogram from an array.  * @param hist: histogram  * @param array: the array to import from.  * @param sz: number of items in array.  */
end_comment

begin_function_decl
name|void
name|timehist_import
parameter_list|(
name|struct
name|timehist
modifier|*
name|hist
parameter_list|,
name|size_t
modifier|*
name|array
parameter_list|,
name|size_t
name|sz
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* UTIL_TIMEHIST_H */
end_comment

end_unit

