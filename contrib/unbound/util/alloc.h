begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * util/alloc.h - memory allocation service.   *  * Copyright (c) 2007, NLnet Labs. All rights reserved.  *  * This software is open source.  *   * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  *   * Redistributions of source code must retain the above copyright notice,  * this list of conditions and the following disclaimer.  *   * Redistributions in binary form must reproduce the above copyright notice,  * this list of conditions and the following disclaimer in the documentation  * and/or other materials provided with the distribution.  *   * Neither the name of the NLNET LABS nor the names of its contributors may  * be used to endorse or promote products derived from this software without  * specific prior written permission.  *   * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS  * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT  * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR  * A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT  * HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,  * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED  * TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR  * PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF  * LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING  * NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS  * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  */
end_comment

begin_comment
comment|/**  * \file  *  * This file contains memory allocation functions.  *  * The reasons for this service are:  *	o Avoid locking costs of getting global lock to call malloc().  *	o The packed rrset type needs to be kept on special freelists,  *	  so that they are reused for other packet rrset allocations.  *  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|UTIL_ALLOC_H
end_ifndef

begin_define
define|#
directive|define
name|UTIL_ALLOC_H
end_define

begin_include
include|#
directive|include
file|"util/locks.h"
end_include

begin_struct_decl
struct_decl|struct
name|ub_packed_rrset_key
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|regional
struct_decl|;
end_struct_decl

begin_comment
comment|/** The special type, packed rrset. Not allowed to be used for other memory */
end_comment

begin_typedef
typedef|typedef
name|struct
name|ub_packed_rrset_key
name|alloc_special_t
typedef|;
end_typedef

begin_comment
comment|/** clean the special type. Pass pointer. */
end_comment

begin_define
define|#
directive|define
name|alloc_special_clean
parameter_list|(
name|x
parameter_list|)
value|(x)->id = 0;
end_define

begin_comment
comment|/** access next pointer. (in available spot). Pass pointer. */
end_comment

begin_define
define|#
directive|define
name|alloc_special_next
parameter_list|(
name|x
parameter_list|)
value|((alloc_special_t*)((x)->entry.overflow_next))
end_define

begin_comment
comment|/** set next pointer. (in available spot). Pass pointers. */
end_comment

begin_define
define|#
directive|define
name|alloc_set_special_next
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
define|\
value|((x)->entry.overflow_next) = (struct lruhash_entry*)(y);
end_define

begin_comment
comment|/** how many blocks to cache locally. */
end_comment

begin_define
define|#
directive|define
name|ALLOC_SPECIAL_MAX
value|10
end_define

begin_comment
comment|/**  * Structure that provides allocation. Use one per thread.  * The one on top has a NULL super pointer.  */
end_comment

begin_struct
struct|struct
name|alloc_cache
block|{
comment|/** lock, only used for the super. */
name|lock_quick_t
name|lock
decl_stmt|;
comment|/** global allocator above this one. NULL for none (malloc/free) */
name|struct
name|alloc_cache
modifier|*
name|super
decl_stmt|;
comment|/** singly linked lists of special type. These are free for use. */
name|alloc_special_t
modifier|*
name|quar
decl_stmt|;
comment|/** number of items in quarantine. */
name|size_t
name|num_quar
decl_stmt|;
comment|/** thread number for id creation */
name|int
name|thread_num
decl_stmt|;
comment|/** next id number to pass out */
name|uint64_t
name|next_id
decl_stmt|;
comment|/** last id number possible */
name|uint64_t
name|last_id
decl_stmt|;
comment|/** what function to call to cleanup when last id is reached */
name|void
function_decl|(
modifier|*
name|cleanup
function_decl|)
parameter_list|(
name|void
modifier|*
parameter_list|)
function_decl|;
comment|/** user arg for cleanup */
name|void
modifier|*
name|cleanup_arg
decl_stmt|;
comment|/** how many regional blocks to keep back max */
name|size_t
name|max_reg_blocks
decl_stmt|;
comment|/** how many regional blocks are kept now */
name|size_t
name|num_reg_blocks
decl_stmt|;
comment|/** linked list of regional blocks, using regional->next */
name|struct
name|regional
modifier|*
name|reg_list
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/**  * Init alloc (zeroes the struct).  * @param alloc: this parameter is allocated by the caller.  * @param super: super to use (init that before with super_init).  *    Pass this argument NULL to init the toplevel alloc structure.  * @param thread_num: thread number for id creation of special type.  */
end_comment

begin_function_decl
name|void
name|alloc_init
parameter_list|(
name|struct
name|alloc_cache
modifier|*
name|alloc
parameter_list|,
name|struct
name|alloc_cache
modifier|*
name|super
parameter_list|,
name|int
name|thread_num
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Free the alloc. Pushes all the cached items into the super structure.  * Or deletes them if alloc->super is NULL.  * Does not free the alloc struct itself (it was also allocated by caller).  * @param alloc: is almost zeroed on exit (except some stats).  */
end_comment

begin_function_decl
name|void
name|alloc_clear
parameter_list|(
name|struct
name|alloc_cache
modifier|*
name|alloc
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Get a new special_t element.  * @param alloc: where to alloc it.  * @return: memory block. Will not return NULL (instead fatal_exit).  *    The block is zeroed.  */
end_comment

begin_function_decl
name|alloc_special_t
modifier|*
name|alloc_special_obtain
parameter_list|(
name|struct
name|alloc_cache
modifier|*
name|alloc
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Return special_t back to pool.  * The block is cleaned up (zeroed) which also invalidates the ID inside.  * @param alloc: where to alloc it.  * @param mem: block to free.  */
end_comment

begin_function_decl
name|void
name|alloc_special_release
parameter_list|(
name|struct
name|alloc_cache
modifier|*
name|alloc
parameter_list|,
name|alloc_special_t
modifier|*
name|mem
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Set ID number of special type to a fresh new ID number.  * In case of ID number overflow, the rrset cache has to be cleared.  * @param alloc: the alloc cache  * @return: fresh id is returned.  */
end_comment

begin_function_decl
name|uint64_t
name|alloc_get_id
parameter_list|(
name|struct
name|alloc_cache
modifier|*
name|alloc
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Get memory size of alloc cache, alloc structure including special types.  * @param alloc: on what alloc.  * @return size in bytes.  */
end_comment

begin_function_decl
name|size_t
name|alloc_get_mem
parameter_list|(
name|struct
name|alloc_cache
modifier|*
name|alloc
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Print debug information (statistics).  * @param alloc: on what alloc.  */
end_comment

begin_function_decl
name|void
name|alloc_stats
parameter_list|(
name|struct
name|alloc_cache
modifier|*
name|alloc
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Get a new regional for query states  * @param alloc: where to alloc it.  * @return regional for use or NULL on alloc failure.  */
end_comment

begin_function_decl
name|struct
name|regional
modifier|*
name|alloc_reg_obtain
parameter_list|(
name|struct
name|alloc_cache
modifier|*
name|alloc
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Put regional for query states back into alloc cache.  * @param alloc: where to alloc it.  * @param r: regional to put back.  */
end_comment

begin_function_decl
name|void
name|alloc_reg_release
parameter_list|(
name|struct
name|alloc_cache
modifier|*
name|alloc
parameter_list|,
name|struct
name|regional
modifier|*
name|r
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Set cleanup on ID overflow callback function. This should remove all  * RRset ID references from the program. Clear the caches.  * @param alloc: the alloc  * @param cleanup: the callback function, called as cleanup(arg).  * @param arg: user argument to callback function.  */
end_comment

begin_function_decl
name|void
name|alloc_set_id_cleanup
parameter_list|(
name|struct
name|alloc_cache
modifier|*
name|alloc
parameter_list|,
name|void
function_decl|(
modifier|*
name|cleanup
function_decl|)
parameter_list|(
name|void
modifier|*
parameter_list|)
parameter_list|,
name|void
modifier|*
name|arg
parameter_list|)
function_decl|;
end_function_decl

begin_ifdef
ifdef|#
directive|ifdef
name|UNBOUND_ALLOC_LITE
end_ifdef

begin_include
include|#
directive|include
file|<ldns/ldns.h>
end_include

begin_include
include|#
directive|include
file|<ldns/packet.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_OPENSSL_SSL_H
end_ifdef

begin_include
include|#
directive|include
file|<openssl/ssl.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|malloc
parameter_list|(
name|s
parameter_list|)
value|unbound_stat_malloc_lite(s, __FILE__, __LINE__, __func__)
end_define

begin_define
define|#
directive|define
name|calloc
parameter_list|(
name|n
parameter_list|,
name|s
parameter_list|)
value|unbound_stat_calloc_lite(n, s, __FILE__, __LINE__, __func__)
end_define

begin_define
define|#
directive|define
name|free
parameter_list|(
name|p
parameter_list|)
value|unbound_stat_free_lite(p, __FILE__, __LINE__, __func__)
end_define

begin_define
define|#
directive|define
name|realloc
parameter_list|(
name|p
parameter_list|,
name|s
parameter_list|)
value|unbound_stat_realloc_lite(p, s, __FILE__, __LINE__, __func__)
end_define

begin_function_decl
name|void
modifier|*
name|unbound_stat_malloc_lite
parameter_list|(
name|size_t
name|size
parameter_list|,
specifier|const
name|char
modifier|*
name|file
parameter_list|,
name|int
name|line
parameter_list|,
specifier|const
name|char
modifier|*
name|func
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
modifier|*
name|unbound_stat_calloc_lite
parameter_list|(
name|size_t
name|nmemb
parameter_list|,
name|size_t
name|size
parameter_list|,
specifier|const
name|char
modifier|*
name|file
parameter_list|,
name|int
name|line
parameter_list|,
specifier|const
name|char
modifier|*
name|func
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|unbound_stat_free_lite
parameter_list|(
name|void
modifier|*
name|ptr
parameter_list|,
specifier|const
name|char
modifier|*
name|file
parameter_list|,
name|int
name|line
parameter_list|,
specifier|const
name|char
modifier|*
name|func
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
modifier|*
name|unbound_stat_realloc_lite
parameter_list|(
name|void
modifier|*
name|ptr
parameter_list|,
name|size_t
name|size
parameter_list|,
specifier|const
name|char
modifier|*
name|file
parameter_list|,
name|int
name|line
parameter_list|,
specifier|const
name|char
modifier|*
name|func
parameter_list|)
function_decl|;
end_function_decl

begin_ifdef
ifdef|#
directive|ifdef
name|strdup
end_ifdef

begin_undef
undef|#
directive|undef
name|strdup
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|strdup
parameter_list|(
name|s
parameter_list|)
value|unbound_strdup_lite(s, __FILE__, __LINE__, __func__)
end_define

begin_function_decl
name|char
modifier|*
name|unbound_strdup_lite
parameter_list|(
specifier|const
name|char
modifier|*
name|s
parameter_list|,
specifier|const
name|char
modifier|*
name|file
parameter_list|,
name|int
name|line
parameter_list|,
specifier|const
name|char
modifier|*
name|func
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|unbound_lite_wrapstr
parameter_list|(
name|char
modifier|*
name|s
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|sldns_rr2str
parameter_list|(
name|rr
parameter_list|)
value|unbound_lite_wrapstr(sldns_rr2str(rr))
end_define

begin_define
define|#
directive|define
name|sldns_rdf2str
parameter_list|(
name|rdf
parameter_list|)
value|unbound_lite_wrapstr(sldns_rdf2str(rdf))
end_define

begin_define
define|#
directive|define
name|sldns_rr_type2str
parameter_list|(
name|t
parameter_list|)
value|unbound_lite_wrapstr(sldns_rr_type2str(t))
end_define

begin_define
define|#
directive|define
name|sldns_rr_class2str
parameter_list|(
name|c
parameter_list|)
value|unbound_lite_wrapstr(sldns_rr_class2str(c))
end_define

begin_define
define|#
directive|define
name|sldns_rr_list2str
parameter_list|(
name|r
parameter_list|)
value|unbound_lite_wrapstr(sldns_rr_list2str(r))
end_define

begin_define
define|#
directive|define
name|sldns_pkt2str
parameter_list|(
name|p
parameter_list|)
value|unbound_lite_wrapstr(sldns_pkt2str(p))
end_define

begin_define
define|#
directive|define
name|sldns_pkt_rcode2str
parameter_list|(
name|r
parameter_list|)
value|unbound_lite_wrapstr(sldns_pkt_rcode2str(r))
end_define

begin_define
define|#
directive|define
name|sldns_pkt2wire
parameter_list|(
name|a
parameter_list|,
name|r
parameter_list|,
name|s
parameter_list|)
value|unbound_lite_pkt2wire(a, r, s)
end_define

begin_function_decl
name|sldns_status
name|unbound_lite_pkt2wire
parameter_list|(
name|uint8_t
modifier|*
modifier|*
name|dest
parameter_list|,
specifier|const
name|sldns_pkt
modifier|*
name|p
parameter_list|,
name|size_t
modifier|*
name|size
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|i2d_DSA_SIG
parameter_list|(
name|d
parameter_list|,
name|s
parameter_list|)
value|unbound_lite_i2d_DSA_SIG(d, s)
end_define

begin_function_decl
name|int
name|unbound_lite_i2d_DSA_SIG
parameter_list|(
name|DSA_SIG
modifier|*
name|dsasig
parameter_list|,
name|unsigned
name|char
modifier|*
modifier|*
name|sig
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* UNBOUND_ALLOC_LITE */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* UTIL_ALLOC_H */
end_comment

end_unit

