begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2010, Oracle America, Inc.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions are  * met:  *  *     * Redistributions of source code must retain the above copyright  *       notice, this list of conditions and the following disclaimer.  *     * Redistributions in binary form must reproduce the above  *       copyright notice, this list of conditions and the following  *       disclaimer in the documentation and/or other materials  *       provided with the distribution.  *     * Neither the name of the "Oracle America, Inc." nor the names of its  *       contributors may be used to endorse or promote products derived  *       from this software without specific prior written permission.  *  *   THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS  *   "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT  *   LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS  *   FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE  *   COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT,  *   INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  *   DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE  *   GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS  *   INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,  *   WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING  *   NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE  *   OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  */
end_comment

begin_comment
comment|/*  * Copyright (c) 1991, Sun Microsystems Inc.  */
end_comment

begin_comment
comment|/*  *	nis_tags.h  *  *	This file contains the tags and statistics definitions. It is  *	automatically included by nis.h  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_RPCSVC_NIS_TAGS_H
end_ifndef

begin_define
define|#
directive|define
name|_RPCSVC_NIS_TAGS_H
end_define

begin_comment
comment|/* $FreeBSD$ */
end_comment

begin_comment
comment|/* From: #pragma ident	"@(#)nis_tags.h	1.10	94/05/03 SMI" */
end_comment

begin_comment
comment|/* from file: zns_tags.h	1.7 Copyright (c) 1990 Sun Microsystems */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|__cplusplus
end_ifdef

begin_extern
extern|extern
literal|"C"
block|{
endif|#
directive|endif
ifndef|#
directive|ifndef
name|ORIGINAL_DECLS
define|#
directive|define
name|NIS_DIR
value|"data"
endif|#
directive|endif
comment|/* Lookup and List function flags */
define|#
directive|define
name|FOLLOW_LINKS
value|(1<<0)
comment|/* Follow link objects 			*/
define|#
directive|define
name|FOLLOW_PATH
value|(1<<1)
comment|/* Follow the path in a table 		*/
define|#
directive|define
name|HARD_LOOKUP
value|(1<<2)
comment|/* Block until successful 		*/
define|#
directive|define
name|ALL_RESULTS
value|(1<<3)
comment|/* Retrieve all results 		*/
define|#
directive|define
name|NO_CACHE
value|(1<<4)
comment|/* Do not return 'cached' results 	*/
define|#
directive|define
name|MASTER_ONLY
value|(1<<5)
comment|/* Get value only from master server	*/
define|#
directive|define
name|EXPAND_NAME
value|(1<<6)
comment|/* Expand partitially qualified names	*/
comment|/* Semantic modification for table operations flags */
define|#
directive|define
name|RETURN_RESULT
value|(1<<7)
comment|/* Return resulting object to client    */
define|#
directive|define
name|ADD_OVERWRITE
value|(1<<8)
comment|/* Allow overwrites on ADD		*/
define|#
directive|define
name|REM_MULTIPLE
value|(1<<9)
comment|/* Allow wildcard deletes		*/
define|#
directive|define
name|MOD_SAMEOBJ
value|(1<<10)
comment|/* Check modified object before write	*/
define|#
directive|define
name|ADD_RESERVED
value|(1<<11)
comment|/* Spare ADD semantic			*/
define|#
directive|define
name|REM_RESERVED
value|(1<<12)
comment|/* Spare REM semantic			*/
ifdef|#
directive|ifdef
name|ORIGINAL_DECLS
define|#
directive|define
name|MOD_RESERVED
value|(1<<13)
comment|/* Spare MOD semantic			*/
else|#
directive|else
define|#
directive|define
name|MOD_EXCLUSIVE
value|(1<<13)
comment|/* Modify no overwrite on modified keys	*/
endif|#
directive|endif
comment|/* Transport specific modifications to the operation */
define|#
directive|define
name|USE_DGRAM
value|(1<<16)
comment|/* Use a datagram transport 		*/
define|#
directive|define
name|NO_AUTHINFO
value|(1<<17)
comment|/* Don't bother attaching auth info	*/
comment|/*  * Declarations for "standard" NIS+ tags  * State variable tags have values	0 - 2047  * Statistic tags have values		2048 - 65535  * User Tags have values>2^16  */
define|#
directive|define
name|TAG_DEBUG
value|1
comment|/* set debug level 		*/
define|#
directive|define
name|TAG_STATS
value|2
comment|/* Enable/disable statistics 	*/
define|#
directive|define
name|TAG_GCACHE
value|3
comment|/* Flush the Group Cache	*/
ifndef|#
directive|ifndef
name|ORIGINAL_DECLS
define|#
directive|define
name|TAG_GCACHE_ALL
value|TAG_GCACHE
endif|#
directive|endif
define|#
directive|define
name|TAG_DCACHE
value|4
comment|/* Flush the directory cache	*/
ifndef|#
directive|ifndef
name|ORIGINAL_DECLS
define|#
directive|define
name|TAG_DCACHE_ONE
value|TAG_DCACHE
endif|#
directive|endif
define|#
directive|define
name|TAG_OCACHE
value|5
comment|/* Flush the Object Cache	*/
define|#
directive|define
name|TAG_SECURE
value|6
comment|/* Set the security level 	*/
ifndef|#
directive|ifndef
name|ORIGINAL_DECLS
define|#
directive|define
name|TAG_TCACHE_ONE
value|7
comment|/* Flush the table cache	*/
define|#
directive|define
name|TAG_DCACHE_ALL
value|8
comment|/* Flush entire directory cache */
define|#
directive|define
name|TAG_TCACHE_ALL
value|9
comment|/* Flush entire table cache	*/
define|#
directive|define
name|TAG_GCACHE_ONE
value|10
comment|/* Flush one group object	*/
define|#
directive|define
name|TAG_DCACHE_ONE_REFRESH
value|11
comment|/* Flush and refresh one DO	*/
endif|#
directive|endif
define|#
directive|define
name|TAG_OPSTATS
value|2048
comment|/* NIS+ operations statistics   */
define|#
directive|define
name|TAG_THREADS
value|2049
comment|/* Child process/thread status  */
define|#
directive|define
name|TAG_HEAP
value|2050
comment|/* Heap usage statistics	*/
define|#
directive|define
name|TAG_UPDATES
value|2051
comment|/* Updates to this service	*/
define|#
directive|define
name|TAG_VISIBLE
value|2052
comment|/* First update that isn't replicated */
define|#
directive|define
name|TAG_S_DCACHE
value|2053
comment|/* Directory cache statistics	*/
define|#
directive|define
name|TAG_S_OCACHE
value|2054
comment|/* Object cache statistics	*/
define|#
directive|define
name|TAG_S_GCACHE
value|2055
comment|/* Group cache statistics	*/
define|#
directive|define
name|TAG_S_STORAGE
value|2056
comment|/* Group cache statistics	*/
define|#
directive|define
name|TAG_UPTIME
value|2057
comment|/* Time that server has been up */
ifndef|#
directive|ifndef
name|ORIGINAL_DECLS
define|#
directive|define
name|TAG_DIRLIST
value|2058
comment|/* Dir served by this server	*/
define|#
directive|define
name|TAG_NISCOMPAT
value|2059
comment|/* Whether supports NIS compat mode */
define|#
directive|define
name|TAG_DNSFORWARDING
value|2060
comment|/* Whether DNS forwarding supported*/
define|#
directive|define
name|TAG_SECURITY_LEVEL
value|2061
comment|/* Security level of the server */
define|#
directive|define
name|TAG_ROOTSERVER
value|2062
comment|/* Whether root server		*/
endif|#
directive|endif
comment|/*  * Declarations for the Group object flags. Currently  * there are only 3.  */
define|#
directive|define
name|IMPMEM_GROUPS
value|1
comment|/* Implicit Membership allowed 	*/
define|#
directive|define
name|RECURS_GROUPS
value|2
comment|/* Recursive Groups allowed 	*/
define|#
directive|define
name|NEGMEM_GROUPS
value|4
comment|/* Negative Groups allowed	*/
ifdef|#
directive|ifdef
name|__cplusplus
block|}
end_extern

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _RPCSVC_NIS_TAGS_H */
end_comment

end_unit

