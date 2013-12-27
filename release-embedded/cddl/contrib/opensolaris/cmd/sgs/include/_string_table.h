begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * CDDL HEADER START  *  * The contents of this file are subject to the terms of the  * Common Development and Distribution License (the "License").  * You may not use this file except in compliance with the License.  *  * You can obtain a copy of the license at usr/src/OPENSOLARIS.LICENSE  * or http://www.opensolaris.org/os/licensing.  * See the License for the specific language governing permissions  * and limitations under the License.  *  * When distributing Covered Code, include this CDDL HEADER in each  * file and include the License file at usr/src/OPENSOLARIS.LICENSE.  * If applicable, add the following below this CDDL HEADER, with the  * fields enclosed by brackets "[]" replaced with your own identifying  * information: Portions Copyright [yyyy] [name of copyright owner]  *  * CDDL HEADER END  */
end_comment

begin_comment
comment|/*  * Copyright 2008 Sun Microsystems, Inc.  All rights reserved.  * Use is subject to license terms.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__STRING_TABLE_DOT_H
end_ifndef

begin_define
define|#
directive|define
name|__STRING_TABLE_DOT_H
end_define

begin_pragma
pragma|#
directive|pragma
name|ident
literal|"%Z%%M%	%I%	%E% SMI"
end_pragma

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|<sys/avl.h>
end_include

begin_include
include|#
directive|include
file|<string_table.h>
end_include

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
comment|/*  * A string is represented in a string table using two values: length, and  * value.  Grouping all the strings of a given length together allows for  * efficient matching of tail strings, as each input string value is hashed.  * Each string table uses a 2-level AVL tree of AVL trees to represent this  * organization.  *  * The outer (main) AVL tree contains LenNode structures.  The search key for  * nodes on this main tree is the string length.  Each such node represents  * all strings of a given length, and all strings of that length are found  * within.  *  * The strings within each LenNode are maintained using a secondary AVL tree  * of StrNode structures.  The search key for this inner tree is the string  * itself.  The strings are maintained in lexical order.  */
typedef|typedef
struct|struct
block|{
name|avl_node_t
name|sn_avlnode
decl_stmt|;
comment|/* AVL book-keeping */
specifier|const
name|char
modifier|*
name|sn_str
decl_stmt|;
comment|/* string */
name|size_t
name|sn_refcnt
decl_stmt|;
comment|/* reference count */
block|}
name|StrNode
typedef|;
typedef|typedef
struct|struct
block|{
name|avl_node_t
name|ln_avlnode
decl_stmt|;
comment|/* AVL book-keeping */
name|avl_tree_t
modifier|*
name|ln_strtree
decl_stmt|;
comment|/* AVL tree of associated strings */
name|size_t
name|ln_strlen
decl_stmt|;
comment|/* length of associated strings */
block|}
name|LenNode
typedef|;
comment|/*  * Define a master string data item.  Other strings may be suffixes of this  * string.  The final string table will consist of the master string values,  * laid end to end, with the other strings referencing their tails.  */
typedef|typedef
name|struct
name|str_master
name|Str_master
typedef|;
struct|struct
name|str_master
block|{
specifier|const
name|char
modifier|*
name|sm_str
decl_stmt|;
comment|/* pointer to master string */
name|Str_master
modifier|*
name|sm_next
decl_stmt|;
comment|/* used for tracking master strings */
name|size_t
name|sm_strlen
decl_stmt|;
comment|/* length of master string */
name|uint_t
name|sm_hashval
decl_stmt|;
comment|/* hashval of master string */
name|size_t
name|sm_stroff
decl_stmt|;
comment|/* offset into destination strtab */
block|}
struct|;
comment|/*  * Define a hash data item.  This item represents an individual string that has  * been input into the String hash table.  The string may either be a suffix of  * another string, or a master string.  */
typedef|typedef
name|struct
name|str_hash
name|Str_hash
typedef|;
struct|struct
name|str_hash
block|{
name|size_t
name|hi_strlen
decl_stmt|;
comment|/* string length */
name|size_t
name|hi_refcnt
decl_stmt|;
comment|/* number of references to str */
name|uint_t
name|hi_hashval
decl_stmt|;
comment|/* hash for string */
name|Str_master
modifier|*
name|hi_mstr
decl_stmt|;
comment|/* pointer to master string */
name|Str_hash
modifier|*
name|hi_next
decl_stmt|;
comment|/* next entry in hash bucket */
block|}
struct|;
comment|/*  * Controlling data structure for a String Table.  */
struct|struct
name|str_tbl
block|{
name|avl_tree_t
modifier|*
name|st_lentree
decl_stmt|;
comment|/* AVL tree of string lengths */
name|char
modifier|*
name|st_strbuf
decl_stmt|;
comment|/* string buffer */
name|Str_hash
modifier|*
modifier|*
name|st_hashbcks
decl_stmt|;
comment|/* hash buckets */
name|Str_master
modifier|*
name|st_mstrlist
decl_stmt|;
comment|/* list of all master strings */
name|size_t
name|st_fullstrsize
decl_stmt|;
comment|/* uncompressed table size */
name|size_t
name|st_nextoff
decl_stmt|;
comment|/* next available string */
name|size_t
name|st_strsize
decl_stmt|;
comment|/* compressed size */
name|size_t
name|st_strcnt
decl_stmt|;
comment|/* number of strings */
name|uint_t
name|st_hbckcnt
decl_stmt|;
comment|/* number of buckets in */
comment|/*    hashlist */
name|uint_t
name|st_flags
decl_stmt|;
block|}
struct|;
define|#
directive|define
name|FLG_STTAB_COMPRESS
value|0x01
comment|/* compressed string table */
define|#
directive|define
name|FLG_STTAB_COOKED
value|0x02
comment|/* offset has been assigned */
comment|/*  * Starting value for use with string hashing functions inside of string_table.c  */
define|#
directive|define
name|HASHSEED
value|5381
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
comment|/* __STRING_TABLE_DOT_H */
end_comment

end_unit

