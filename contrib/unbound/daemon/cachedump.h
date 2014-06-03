begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * daemon/cachedump.h - dump the cache to text format.  *  * Copyright (c) 2008, NLnet Labs. All rights reserved.  *  * This software is open source.  *   * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  *   * Redistributions of source code must retain the above copyright notice,  * this list of conditions and the following disclaimer.  *   * Redistributions in binary form must reproduce the above copyright notice,  * this list of conditions and the following disclaimer in the documentation  * and/or other materials provided with the distribution.  *   * Neither the name of the NLNET LABS nor the names of its contributors may  * be used to endorse or promote products derived from this software without  * specific prior written permission.  *   * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS  * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT  * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR  * A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT  * HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,  * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED  * TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR  * PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF  * LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING  * NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS  * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  */
end_comment

begin_comment
comment|/**  * \file  *  * This file contains functions to read and write the cache(s)  * to text format.  *  * The format of the file is as follows:  * [RRset cache]  * [Message cache]  * EOF		-- fixed string "EOF" before end of the file.  *  * The RRset cache is:  * START_RRSET_CACHE  * [rrset]*  * END_RRSET_CACHE  *  * rrset is:  * ;rrset [nsec_apex] TTL rr_count rrsig_count trust security  * resource records, one per line, in zonefile format  * rrsig records, one per line, in zonefile format  * If the text conversion fails, BADRR is printed on the line.  *  * The Message cache is:  * START_MSG_CACHE  * [msg]*  * END_MSG_CACHE  *  * msg is:  * msg name class type flags qdcount ttl security an ns ar  * list of rrset references, one per line. If conversion fails, BADREF  * reference is:  * name class type flags  *  * Expired cache entries are not printed.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|DAEMON_DUMPCACHE_H
end_ifndef

begin_define
define|#
directive|define
name|DAEMON_DUMPCACHE_H
end_define

begin_struct_decl
struct_decl|struct
name|worker
struct_decl|;
end_struct_decl

begin_comment
comment|/**  * Dump cache(s) to text  * @param ssl: to print to  * @param worker: worker that is available (buffers, etc) and has   * 	ptrs to the caches.  * @return false on ssl print error.  */
end_comment

begin_function_decl
name|int
name|dump_cache
parameter_list|(
name|SSL
modifier|*
name|ssl
parameter_list|,
name|struct
name|worker
modifier|*
name|worker
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Load cache(s) from text   * @param ssl: to read from   * @param worker: worker that is available (buffers, etc) and has   * 	ptrs to the caches.  * @return false on ssl error.  */
end_comment

begin_function_decl
name|int
name|load_cache
parameter_list|(
name|SSL
modifier|*
name|ssl
parameter_list|,
name|struct
name|worker
modifier|*
name|worker
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Print the delegation used to lookup for this name.  * @param ssl: to read from   * @param worker: worker that is available (buffers, etc) and has   * 	ptrs to the caches.  * @param nm: name to lookup  * @param nmlen: length of name.  * @param nmlabs: labels in name.  * @return false on ssl error.  */
end_comment

begin_function_decl
name|int
name|print_deleg_lookup
parameter_list|(
name|SSL
modifier|*
name|ssl
parameter_list|,
name|struct
name|worker
modifier|*
name|worker
parameter_list|,
name|uint8_t
modifier|*
name|nm
parameter_list|,
name|size_t
name|nmlen
parameter_list|,
name|int
name|nmlabs
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* DAEMON_DUMPCACHE_H */
end_comment

end_unit

