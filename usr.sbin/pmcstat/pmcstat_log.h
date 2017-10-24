begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2005-2007, Joseph Koshy  * Copyright (c) 2007 The FreeBSD Foundation  * Copyright (c) 2009, Fabien Thomas  * All rights reserved.  *  * Portions of this software were developed by A. Joseph Koshy under  * sponsorship from the FreeBSD Foundation and Google, Inc.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_PMCSTAT_LOG_H_
end_ifndef

begin_define
define|#
directive|define
name|_PMCSTAT_LOG_H_
end_define

begin_include
include|#
directive|include
file|<libpmcstat.h>
end_include

begin_decl_stmt
specifier|extern
name|struct
name|pmcstat_stats
name|pmcstat_stats
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* statistics */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|pmcstat_process
modifier|*
name|pmcstat_kernproc
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* kernel 'process' */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|pmcstat_npmcs
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* PMC count. */
end_comment

begin_comment
comment|/*  * Top mode global options.  */
end_comment

begin_decl_stmt
specifier|extern
name|float
name|pmcstat_threshold
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Threshold to filter node. */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|pmcstat_pmcinfilter
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* PMC index displayed. */
end_comment

begin_comment
comment|/* Function prototypes */
end_comment

begin_function_decl
specifier|const
name|char
modifier|*
name|pmcstat_pmcid_to_name
parameter_list|(
name|pmc_id_t
name|_pmcid
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|const
name|char
modifier|*
name|pmcstat_pmcindex_to_name
parameter_list|(
name|int
name|pmcin
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|pmcstat_pmcrecord
modifier|*
name|pmcstat_pmcindex_to_pmcr
parameter_list|(
name|int
name|pmcin
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|pmcstat_image_addr2line
parameter_list|(
name|struct
name|pmcstat_image
modifier|*
name|image
parameter_list|,
name|uintfptr_t
name|addr
parameter_list|,
name|char
modifier|*
name|sourcefile
parameter_list|,
name|size_t
name|sourcefile_len
parameter_list|,
name|unsigned
modifier|*
name|sourceline
parameter_list|,
name|char
modifier|*
name|funcname
parameter_list|,
name|size_t
name|funcname_len
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _PMCSTAT_LOG_H_ */
end_comment

end_unit

