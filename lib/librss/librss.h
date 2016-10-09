begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2016 Adrian Chadd<adrian@FreeBSD.org>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__LIBRSS_H__
end_ifndef

begin_define
define|#
directive|define
name|__LIBRSS_H__
end_define

begin_struct
struct|struct
name|rss_config
block|{
name|int
name|rss_ncpus
decl_stmt|;
name|int
name|rss_nbuckets
decl_stmt|;
name|int
name|rss_basecpu
decl_stmt|;
name|int
modifier|*
name|rss_bucket_map
decl_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
enum|enum
block|{
name|RSS_BUCKET_TYPE_NONE
init|=
literal|0
block|,
name|RSS_BUCKET_TYPE_KERNEL_ALL
init|=
literal|1
block|,
name|RSS_BUCKET_TYPE_KERNEL_TX
init|=
literal|2
block|,
name|RSS_BUCKET_TYPE_KERNEL_RX
init|=
literal|3
block|,
name|RSS_BUCKET_TYPE_MAX
init|=
literal|3
block|, }
name|rss_bucket_type_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|void
name|rss_bucket_rebalance_cb_t
parameter_list|(
name|void
modifier|*
name|arg
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/*  * Enable/disable whether to allow for multiple bind()s to the  * given PCB entry.  *  * This must be done before bind().  */
end_comment

begin_function_decl
specifier|extern
name|int
name|rss_sock_set_bindmulti
parameter_list|(
name|int
name|fd
parameter_list|,
name|int
name|af
parameter_list|,
name|int
name|val
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Set the RSS bucket for the given file descriptor.  *  * This must be done before bind().  */
end_comment

begin_function_decl
specifier|extern
name|int
name|rss_sock_set_rss_bucket
parameter_list|(
name|int
name|fd
parameter_list|,
name|int
name|af
parameter_list|,
name|int
name|rss_bucket
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Enable or disable receiving RSS/flowid information on  * received UDP frames.  */
end_comment

begin_function_decl
specifier|extern
name|int
name|rss_sock_set_recvrss
parameter_list|(
name|int
name|fd
parameter_list|,
name|int
name|af
parameter_list|,
name|int
name|val
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Fetch RSS configuration information.  */
end_comment

begin_function_decl
specifier|extern
name|struct
name|rss_config
modifier|*
name|rss_config_get
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Free an RSS configuration structure.  */
end_comment

begin_function_decl
specifier|extern
name|void
name|rss_config_free
parameter_list|(
name|struct
name|rss_config
modifier|*
name|rc
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Return how many RSS buckets there are.  */
end_comment

begin_function_decl
specifier|extern
name|int
name|rss_config_get_bucket_count
parameter_list|(
name|struct
name|rss_config
modifier|*
name|rc
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Fetch the cpuset configuration for the given RSS bucket and  * type.  */
end_comment

begin_function_decl
specifier|extern
name|int
name|rss_get_bucket_cpuset
parameter_list|(
name|struct
name|rss_config
modifier|*
name|rc
parameter_list|,
name|rss_bucket_type_t
name|btype
parameter_list|,
name|int
name|bucket
parameter_list|,
name|cpuset_t
modifier|*
name|cs
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Set a callback for bucket rebalancing.  *  * This will occur in a separate thread context rather than  * a signal handler.  */
end_comment

begin_function_decl
specifier|extern
name|int
name|rss_set_bucket_rebalance_cb
parameter_list|(
name|rss_bucket_rebalance_cb_t
modifier|*
name|cb
parameter_list|,
name|void
modifier|*
name|cbdata
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __LIBRSS_H__ */
end_comment

end_unit

