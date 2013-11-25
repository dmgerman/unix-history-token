begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Licensed to the Apache Software Foundation (ASF) under one or more  * contributor license agreements.  See the NOTICE file distributed with  * this work for additional information regarding copyright ownership.  * The ASF licenses this file to You under the Apache License, Version 2.0  * (the "License"); you may not use this file except in compliance with  * the License.  You may obtain a copy of the License at  *  *     http://www.apache.org/licenses/LICENSE-2.0  *  * Unless required by applicable law or agreed to in writing, software  * distributed under the License is distributed on an "AS IS" BASIS,  * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.  * See the License for the specific language governing permissions and  * limitations under the License.  */
end_comment

begin_comment
comment|/**  * @file apr_buckets.h  * @brief APR-UTIL Buckets/Bucket Brigades  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|APR_BUCKETS_H
end_ifndef

begin_define
define|#
directive|define
name|APR_BUCKETS_H
end_define

begin_if
if|#
directive|if
name|defined
argument_list|(
name|APR_BUCKET_DEBUG
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|APR_RING_DEBUG
argument_list|)
end_if

begin_define
define|#
directive|define
name|APR_RING_DEBUG
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|"apu.h"
end_include

begin_include
include|#
directive|include
file|"apr_network_io.h"
end_include

begin_include
include|#
directive|include
file|"apr_file_io.h"
end_include

begin_include
include|#
directive|include
file|"apr_general.h"
end_include

begin_include
include|#
directive|include
file|"apr_mmap.h"
end_include

begin_include
include|#
directive|include
file|"apr_errno.h"
end_include

begin_include
include|#
directive|include
file|"apr_ring.h"
end_include

begin_include
include|#
directive|include
file|"apr.h"
end_include

begin_if
if|#
directive|if
name|APR_HAVE_SYS_UIO_H
end_if

begin_include
include|#
directive|include
file|<sys/uio.h>
end_include

begin_comment
comment|/* for struct iovec */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|APR_HAVE_STDARG_H
end_if

begin_include
include|#
directive|include
file|<stdarg.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

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
comment|/**  * @defgroup APR_Util_Bucket_Brigades Bucket Brigades  * @ingroup APR_Util  * @{   */
comment|/** default bucket buffer size - 8KB minus room for memory allocator headers */
define|#
directive|define
name|APR_BUCKET_BUFF_SIZE
value|8000
comment|/** Determines how a bucket or brigade should be read */
typedef|typedef
enum|enum
block|{
name|APR_BLOCK_READ
block|,
comment|/**< block until data becomes available */
name|APR_NONBLOCK_READ
comment|/**< return immediately if no data is available */
block|}
name|apr_read_type_e
typedef|;
comment|/**  * The one-sentence buzzword-laden overview: Bucket brigades represent  * a complex data stream that can be passed through a layered IO  * system without unnecessary copying. A longer overview follows...  *  * A bucket brigade is a doubly linked list (ring) of buckets, so we  * aren't limited to inserting at the front and removing at the end.  * Buckets are only passed around as members of a brigade, although  * singleton buckets can occur for short periods of time.  *  * Buckets are data stores of various types. They can refer to data in  * memory, or part of a file or mmap area, or the output of a process,  * etc. Buckets also have some type-dependent accessor functions:  * read, split, copy, setaside, and destroy.  *  * read returns the address and size of the data in the bucket. If the  * data isn't in memory then it is read in and the bucket changes type  * so that it can refer to the new location of the data. If all the  * data doesn't fit in the bucket then a new bucket is inserted into  * the brigade to hold the rest of it.  *  * split divides the data in a bucket into two regions. After a split  * the original bucket refers to the first part of the data and a new  * bucket inserted into the brigade after the original bucket refers  * to the second part of the data. Reference counts are maintained as  * necessary.  *  * setaside ensures that the data in the bucket has a long enough  * lifetime. Sometimes it is convenient to create a bucket referring  * to data on the stack in the expectation that it will be consumed  * (output to the network) before the stack is unwound. If that  * expectation turns out not to be valid, the setaside function is  * called to move the data somewhere safer.  *  * copy makes a duplicate of the bucket structure as long as it's  * possible to have multiple references to a single copy of the  * data itself.  Not all bucket types can be copied.  *  * destroy maintains the reference counts on the resources used by a  * bucket and frees them if necessary.  *  * Note: all of the above functions have wrapper macros (apr_bucket_read(),  * apr_bucket_destroy(), etc), and those macros should be used rather  * than using the function pointers directly.  *  * To write a bucket brigade, they are first made into an iovec, so that we  * don't write too little data at one time.  Currently we ignore compacting the  * buckets into as few buckets as possible, but if we really want good  * performance, then we need to compact the buckets before we convert to an  * iovec, or possibly while we are converting to an iovec.  */
comment|/*  * Forward declaration of the main types.  */
comment|/** @see apr_bucket_brigade */
typedef|typedef
name|struct
name|apr_bucket_brigade
name|apr_bucket_brigade
typedef|;
comment|/** @see apr_bucket */
typedef|typedef
name|struct
name|apr_bucket
name|apr_bucket
typedef|;
comment|/** @see apr_bucket_alloc_t */
typedef|typedef
name|struct
name|apr_bucket_alloc_t
name|apr_bucket_alloc_t
typedef|;
comment|/** @see apr_bucket_type_t */
typedef|typedef
name|struct
name|apr_bucket_type_t
name|apr_bucket_type_t
typedef|;
comment|/**  * Basic bucket type  */
struct|struct
name|apr_bucket_type_t
block|{
comment|/**      * The name of the bucket type      */
specifier|const
name|char
modifier|*
name|name
decl_stmt|;
comment|/**       * The number of functions this bucket understands.  Can not be less than      * five.      */
name|int
name|num_func
decl_stmt|;
comment|/**      * Whether the bucket contains metadata (ie, information that      * describes the regular contents of the brigade).  The metadata      * is not returned by apr_bucket_read() and is not indicated by      * the ->length of the apr_bucket itself.  In other words, an      * empty bucket is safe to arbitrarily remove if and only if it      * contains no metadata.  In this sense, "data" is just raw bytes      * that are the "content" of the brigade and "metadata" describes      * that data but is not a proper part of it.      */
enum|enum
block|{
comment|/** This bucket type represents actual data to send to the client. */
name|APR_BUCKET_DATA
init|=
literal|0
block|,
comment|/** This bucket type represents metadata. */
name|APR_BUCKET_METADATA
init|=
literal|1
block|}
name|is_metadata
enum|;
comment|/**      * Free the private data and any resources used by the bucket (if they      *  aren't shared with another bucket).  This function is required to be      *  implemented for all bucket types, though it might be a no-op on some      *  of them (namely ones that never allocate any private data structures).      * @param data The private data pointer from the bucket to be destroyed      */
name|void
function_decl|(
modifier|*
name|destroy
function_decl|)
parameter_list|(
name|void
modifier|*
name|data
parameter_list|)
function_decl|;
comment|/**      * Read the data from the bucket. This is required to be implemented      *  for all bucket types.      * @param b The bucket to read from      * @param str A place to store the data read.  Allocation should only be      *            done if absolutely necessary.       * @param len The amount of data read.      * @param block Should this read function block if there is more data that      *              cannot be read immediately.      */
name|apr_status_t
function_decl|(
modifier|*
name|read
function_decl|)
parameter_list|(
name|apr_bucket
modifier|*
name|b
parameter_list|,
specifier|const
name|char
modifier|*
modifier|*
name|str
parameter_list|,
name|apr_size_t
modifier|*
name|len
parameter_list|,
name|apr_read_type_e
name|block
parameter_list|)
function_decl|;
comment|/**      * Make it possible to set aside the data for at least as long as the      *  given pool. Buckets containing data that could potentially die before      *  this pool (e.g. the data resides on the stack, in a child pool of      *  the given pool, or in a disjoint pool) must somehow copy, shift, or      *  transform the data to have the proper lifetime.      * @param e The bucket to convert      * @remark Some bucket types contain data that will always outlive the      *         bucket itself. For example no data (EOS and FLUSH), or the data      *         resides in global, constant memory (IMMORTAL), or the data is on      *      the heap (HEAP). For these buckets, apr_bucket_setaside_noop can      *      be used.      */
name|apr_status_t
function_decl|(
modifier|*
name|setaside
function_decl|)
parameter_list|(
name|apr_bucket
modifier|*
name|e
parameter_list|,
name|apr_pool_t
modifier|*
name|pool
parameter_list|)
function_decl|;
comment|/**      * Split one bucket in two at the specified position by duplicating      *  the bucket structure (not the data) and modifying any necessary      *  start/end/offset information.  If it's not possible to do this      *  for the bucket type (perhaps the length of the data is indeterminate,      *  as with pipe and socket buckets), then APR_ENOTIMPL is returned.      * @param e The bucket to split      * @param point The offset of the first byte in the new bucket      */
name|apr_status_t
function_decl|(
modifier|*
name|split
function_decl|)
parameter_list|(
name|apr_bucket
modifier|*
name|e
parameter_list|,
name|apr_size_t
name|point
parameter_list|)
function_decl|;
comment|/**      * Copy the bucket structure (not the data), assuming that this is      *  possible for the bucket type. If it's not, APR_ENOTIMPL is returned.      * @param e The bucket to copy      * @param c Returns a pointer to the new bucket      */
name|apr_status_t
function_decl|(
modifier|*
name|copy
function_decl|)
parameter_list|(
name|apr_bucket
modifier|*
name|e
parameter_list|,
name|apr_bucket
modifier|*
modifier|*
name|c
parameter_list|)
function_decl|;
block|}
struct|;
comment|/**  * apr_bucket structures are allocated on the malloc() heap and  * their lifetime is controlled by the parent apr_bucket_brigade  * structure. Buckets can move from one brigade to another e.g. by  * calling APR_BRIGADE_CONCAT(). In general the data in a bucket has  * the same lifetime as the bucket and is freed when the bucket is  * destroyed; if the data is shared by more than one bucket (e.g.  * after a split) the data is freed when the last bucket goes away.  */
struct|struct
name|apr_bucket
block|{
comment|/** Links to the rest of the brigade */
name|APR_RING_ENTRY
argument_list|(
argument|apr_bucket
argument_list|)
name|link
expr_stmt|;
comment|/** The type of bucket.  */
specifier|const
name|apr_bucket_type_t
modifier|*
name|type
decl_stmt|;
comment|/** The length of the data in the bucket.  This could have been implemented      *  with a function, but this is an optimization, because the most      *  common thing to do will be to get the length.  If the length is unknown,      *  the value of this field will be (apr_size_t)(-1).      */
name|apr_size_t
name|length
decl_stmt|;
comment|/** The start of the data in the bucket relative to the private base      *  pointer.  The vast majority of bucket types allow a fixed block of      *  data to be referenced by multiple buckets, each bucket pointing to      *  a different segment of the data.  That segment starts at base+start      *  and ends at base+start+length.        *  If the length == (apr_size_t)(-1), then start == -1.      */
name|apr_off_t
name|start
decl_stmt|;
comment|/** type-dependent data hangs off this pointer */
name|void
modifier|*
name|data
decl_stmt|;
comment|/**      * Pointer to function used to free the bucket. This function should      * always be defined and it should be consistent with the memory      * function used to allocate the bucket. For example, if malloc() is       * used to allocate the bucket, this pointer should point to free().      * @param e Pointer to the bucket being freed      */
name|void
function_decl|(
modifier|*
name|free
function_decl|)
parameter_list|(
name|void
modifier|*
name|e
parameter_list|)
function_decl|;
comment|/** The freelist from which this bucket was allocated */
name|apr_bucket_alloc_t
modifier|*
name|list
decl_stmt|;
block|}
struct|;
comment|/** A list of buckets */
struct|struct
name|apr_bucket_brigade
block|{
comment|/** The pool to associate the brigade with.  The data is not allocated out      *  of the pool, but a cleanup is registered with this pool.  If the       *  brigade is destroyed by some mechanism other than pool destruction,      *  the destroying function is responsible for killing the cleanup.      */
name|apr_pool_t
modifier|*
name|p
decl_stmt|;
comment|/** The buckets in the brigade are on this list. */
comment|/*      * The apr_bucket_list structure doesn't actually need a name tag      * because it has no existence independent of struct apr_bucket_brigade;      * the ring macros are designed so that you can leave the name tag      * argument empty in this situation but apparently the Windows compiler      * doesn't like that.      */
name|APR_RING_HEAD
argument_list|(
argument|apr_bucket_list
argument_list|,
argument|apr_bucket
argument_list|)
name|list
expr_stmt|;
comment|/** The freelist from which this bucket was allocated */
name|apr_bucket_alloc_t
modifier|*
name|bucket_alloc
decl_stmt|;
block|}
struct|;
comment|/**  * Function called when a brigade should be flushed  */
typedef|typedef
name|apr_status_t
function_decl|(
modifier|*
name|apr_brigade_flush
function_decl|)
parameter_list|(
name|apr_bucket_brigade
modifier|*
name|bb
parameter_list|,
name|void
modifier|*
name|ctx
parameter_list|)
function_decl|;
comment|/*  * define APR_BUCKET_DEBUG if you want your brigades to be checked for  * validity at every possible instant.  this will slow your code down  * substantially but is a very useful debugging tool.  */
ifdef|#
directive|ifdef
name|APR_BUCKET_DEBUG
define|#
directive|define
name|APR_BRIGADE_CHECK_CONSISTENCY
parameter_list|(
name|b
parameter_list|)
define|\
value|APR_RING_CHECK_CONSISTENCY(&(b)->list, apr_bucket, link)
define|#
directive|define
name|APR_BUCKET_CHECK_CONSISTENCY
parameter_list|(
name|e
parameter_list|)
define|\
value|APR_RING_CHECK_ELEM_CONSISTENCY((e), apr_bucket, link)
else|#
directive|else
comment|/**  * checks the ring pointers in a bucket brigade for consistency.  an  * abort() will be triggered if any inconsistencies are found.  *   note: this is a no-op unless APR_BUCKET_DEBUG is defined.  * @param b The brigade  */
define|#
directive|define
name|APR_BRIGADE_CHECK_CONSISTENCY
parameter_list|(
name|b
parameter_list|)
comment|/**  * checks the brigade a bucket is in for ring consistency.  an  * abort() will be triggered if any inconsistencies are found.  *   note: this is a no-op unless APR_BUCKET_DEBUG is defined.  * @param e The bucket  */
define|#
directive|define
name|APR_BUCKET_CHECK_CONSISTENCY
parameter_list|(
name|e
parameter_list|)
endif|#
directive|endif
comment|/**  * Wrappers around the RING macros to reduce the verbosity of the code  * that handles bucket brigades.  */
comment|/**  * The magic pointer value that indicates the head of the brigade  * @remark This is used to find the beginning and end of the brigade, eg:  *<pre>  *      while (e != APR_BRIGADE_SENTINEL(b)) {  *          ...  *          e = APR_BUCKET_NEXT(e);  *      }  *</pre>  * @param  b The brigade  * @return The magic pointer value  */
define|#
directive|define
name|APR_BRIGADE_SENTINEL
parameter_list|(
name|b
parameter_list|)
value|APR_RING_SENTINEL(&(b)->list, apr_bucket, link)
comment|/**  * Determine if the bucket brigade is empty  * @param b The brigade to check  * @return true or false  */
define|#
directive|define
name|APR_BRIGADE_EMPTY
parameter_list|(
name|b
parameter_list|)
value|APR_RING_EMPTY(&(b)->list, apr_bucket, link)
comment|/**  * Return the first bucket in a brigade  * @param b The brigade to query  * @return The first bucket in the brigade  */
define|#
directive|define
name|APR_BRIGADE_FIRST
parameter_list|(
name|b
parameter_list|)
value|APR_RING_FIRST(&(b)->list)
comment|/**  * Return the last bucket in a brigade  * @param b The brigade to query  * @return The last bucket in the brigade  */
define|#
directive|define
name|APR_BRIGADE_LAST
parameter_list|(
name|b
parameter_list|)
value|APR_RING_LAST(&(b)->list)
comment|/**  * Insert a single bucket at the front of a brigade  * @param b The brigade to add to  * @param e The bucket to insert  */
define|#
directive|define
name|APR_BRIGADE_INSERT_HEAD
parameter_list|(
name|b
parameter_list|,
name|e
parameter_list|)
value|do {				\ 	apr_bucket *ap__b = (e);                                        \ 	APR_RING_INSERT_HEAD(&(b)->list, ap__b, apr_bucket, link);	\         APR_BRIGADE_CHECK_CONSISTENCY((b));				\     } while (0)
comment|/**  * Insert a single bucket at the end of a brigade  * @param b The brigade to add to  * @param e The bucket to insert  */
define|#
directive|define
name|APR_BRIGADE_INSERT_TAIL
parameter_list|(
name|b
parameter_list|,
name|e
parameter_list|)
value|do {				\ 	apr_bucket *ap__b = (e);					\ 	APR_RING_INSERT_TAIL(&(b)->list, ap__b, apr_bucket, link);	\         APR_BRIGADE_CHECK_CONSISTENCY((b));				\     } while (0)
comment|/**  * Concatenate brigade b onto the end of brigade a, leaving brigade b empty  * @param a The first brigade  * @param b The second brigade  */
define|#
directive|define
name|APR_BRIGADE_CONCAT
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|do {					\         APR_RING_CONCAT(&(a)->list,&(b)->list, apr_bucket, link);	\         APR_BRIGADE_CHECK_CONSISTENCY((a));				\     } while (0)
comment|/**  * Prepend brigade b onto the beginning of brigade a, leaving brigade b empty  * @param a The first brigade  * @param b The second brigade  */
define|#
directive|define
name|APR_BRIGADE_PREPEND
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|do {					\         APR_RING_PREPEND(&(a)->list,&(b)->list, apr_bucket, link);	\         APR_BRIGADE_CHECK_CONSISTENCY((a));				\     } while (0)
comment|/**  * Insert a single bucket before a specified bucket  * @param a The bucket to insert before  * @param b The bucket to insert  */
define|#
directive|define
name|APR_BUCKET_INSERT_BEFORE
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|do {				\ 	apr_bucket *ap__a = (a), *ap__b = (b);				\ 	APR_RING_INSERT_BEFORE(ap__a, ap__b, link);			\         APR_BUCKET_CHECK_CONSISTENCY(ap__a);				\     } while (0)
comment|/**  * Insert a single bucket after a specified bucket  * @param a The bucket to insert after  * @param b The bucket to insert  */
define|#
directive|define
name|APR_BUCKET_INSERT_AFTER
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|do {				\ 	apr_bucket *ap__a = (a), *ap__b = (b);				\ 	APR_RING_INSERT_AFTER(ap__a, ap__b, link);			\         APR_BUCKET_CHECK_CONSISTENCY(ap__a);				\     } while (0)
comment|/**  * Get the next bucket in the list  * @param e The current bucket  * @return The next bucket  */
define|#
directive|define
name|APR_BUCKET_NEXT
parameter_list|(
name|e
parameter_list|)
value|APR_RING_NEXT((e), link)
comment|/**  * Get the previous bucket in the list  * @param e The current bucket  * @return The previous bucket  */
define|#
directive|define
name|APR_BUCKET_PREV
parameter_list|(
name|e
parameter_list|)
value|APR_RING_PREV((e), link)
comment|/**  * Remove a bucket from its bucket brigade  * @param e The bucket to remove  */
define|#
directive|define
name|APR_BUCKET_REMOVE
parameter_list|(
name|e
parameter_list|)
value|APR_RING_REMOVE((e), link)
comment|/**  * Initialize a new bucket's prev/next pointers  * @param e The bucket to initialize  */
define|#
directive|define
name|APR_BUCKET_INIT
parameter_list|(
name|e
parameter_list|)
value|APR_RING_ELEM_INIT((e), link)
comment|/**  * Determine if a bucket contains metadata.  An empty bucket is  * safe to arbitrarily remove if and only if this is false.  * @param e The bucket to inspect  * @return true or false  */
define|#
directive|define
name|APR_BUCKET_IS_METADATA
parameter_list|(
name|e
parameter_list|)
value|((e)->type->is_metadata)
comment|/**  * Determine if a bucket is a FLUSH bucket  * @param e The bucket to inspect  * @return true or false  */
define|#
directive|define
name|APR_BUCKET_IS_FLUSH
parameter_list|(
name|e
parameter_list|)
value|((e)->type ==&apr_bucket_type_flush)
comment|/**  * Determine if a bucket is an EOS bucket  * @param e The bucket to inspect  * @return true or false  */
define|#
directive|define
name|APR_BUCKET_IS_EOS
parameter_list|(
name|e
parameter_list|)
value|((e)->type ==&apr_bucket_type_eos)
comment|/**  * Determine if a bucket is a FILE bucket  * @param e The bucket to inspect  * @return true or false  */
define|#
directive|define
name|APR_BUCKET_IS_FILE
parameter_list|(
name|e
parameter_list|)
value|((e)->type ==&apr_bucket_type_file)
comment|/**  * Determine if a bucket is a PIPE bucket  * @param e The bucket to inspect  * @return true or false  */
define|#
directive|define
name|APR_BUCKET_IS_PIPE
parameter_list|(
name|e
parameter_list|)
value|((e)->type ==&apr_bucket_type_pipe)
comment|/**  * Determine if a bucket is a SOCKET bucket  * @param e The bucket to inspect  * @return true or false  */
define|#
directive|define
name|APR_BUCKET_IS_SOCKET
parameter_list|(
name|e
parameter_list|)
value|((e)->type ==&apr_bucket_type_socket)
comment|/**  * Determine if a bucket is a HEAP bucket  * @param e The bucket to inspect  * @return true or false  */
define|#
directive|define
name|APR_BUCKET_IS_HEAP
parameter_list|(
name|e
parameter_list|)
value|((e)->type ==&apr_bucket_type_heap)
comment|/**  * Determine if a bucket is a TRANSIENT bucket  * @param e The bucket to inspect  * @return true or false  */
define|#
directive|define
name|APR_BUCKET_IS_TRANSIENT
parameter_list|(
name|e
parameter_list|)
value|((e)->type ==&apr_bucket_type_transient)
comment|/**  * Determine if a bucket is a IMMORTAL bucket  * @param e The bucket to inspect  * @return true or false  */
define|#
directive|define
name|APR_BUCKET_IS_IMMORTAL
parameter_list|(
name|e
parameter_list|)
value|((e)->type ==&apr_bucket_type_immortal)
if|#
directive|if
name|APR_HAS_MMAP
comment|/**  * Determine if a bucket is a MMAP bucket  * @param e The bucket to inspect  * @return true or false  */
define|#
directive|define
name|APR_BUCKET_IS_MMAP
parameter_list|(
name|e
parameter_list|)
value|((e)->type ==&apr_bucket_type_mmap)
endif|#
directive|endif
comment|/**  * Determine if a bucket is a POOL bucket  * @param e The bucket to inspect  * @return true or false  */
define|#
directive|define
name|APR_BUCKET_IS_POOL
parameter_list|(
name|e
parameter_list|)
value|((e)->type ==&apr_bucket_type_pool)
comment|/*  * General-purpose reference counting for the various bucket types.  *  * Any bucket type that keeps track of the resources it uses (i.e.  * most of them except for IMMORTAL, TRANSIENT, and EOS) needs to  * attach a reference count to the resource so that it can be freed  * when the last bucket that uses it goes away. Resource-sharing may  * occur because of bucket splits or buckets that refer to globally  * cached data. */
comment|/** @see apr_bucket_refcount */
typedef|typedef
name|struct
name|apr_bucket_refcount
name|apr_bucket_refcount
typedef|;
comment|/**  * The structure used to manage the shared resource must start with an  * apr_bucket_refcount which is updated by the general-purpose refcount  * code. A pointer to the bucket-type-dependent private data structure  * can be cast to a pointer to an apr_bucket_refcount and vice versa.  */
struct|struct
name|apr_bucket_refcount
block|{
comment|/** The number of references to this bucket */
name|int
name|refcount
decl_stmt|;
block|}
struct|;
comment|/*  *****  Reference-counted bucket types  *****  */
comment|/** @see apr_bucket_heap */
typedef|typedef
name|struct
name|apr_bucket_heap
name|apr_bucket_heap
typedef|;
comment|/**  * A bucket referring to data allocated off the heap.  */
struct|struct
name|apr_bucket_heap
block|{
comment|/** Number of buckets using this memory */
name|apr_bucket_refcount
name|refcount
decl_stmt|;
comment|/** The start of the data actually allocated.  This should never be      * modified, it is only used to free the bucket.      */
name|char
modifier|*
name|base
decl_stmt|;
comment|/** how much memory was allocated */
name|apr_size_t
name|alloc_len
decl_stmt|;
comment|/** function to use to delete the data */
name|void
function_decl|(
modifier|*
name|free_func
function_decl|)
parameter_list|(
name|void
modifier|*
name|data
parameter_list|)
function_decl|;
block|}
struct|;
comment|/** @see apr_bucket_pool */
typedef|typedef
name|struct
name|apr_bucket_pool
name|apr_bucket_pool
typedef|;
comment|/**  * A bucket referring to data allocated from a pool  */
struct|struct
name|apr_bucket_pool
block|{
comment|/** The pool bucket must be able to be easily morphed to a heap      * bucket if the pool gets cleaned up before all references are      * destroyed.  This apr_bucket_heap structure is populated automatically      * when the pool gets cleaned up, and subsequent calls to pool_read()      * will result in the apr_bucket in question being morphed into a      * regular heap bucket.  (To avoid having to do many extra refcount      * manipulations and b->data manipulations, the apr_bucket_pool      * struct actually *contains* the apr_bucket_heap struct that it      * will become as its first element; the two share their      * apr_bucket_refcount members.)      */
name|apr_bucket_heap
name|heap
decl_stmt|;
comment|/** The block of data actually allocated from the pool.      * Segments of this block are referenced by adjusting      * the start and length of the apr_bucket accordingly.      * This will be NULL after the pool gets cleaned up.      */
specifier|const
name|char
modifier|*
name|base
decl_stmt|;
comment|/** The pool the data was allocated from.  When the pool      * is cleaned up, this gets set to NULL as an indicator      * to pool_read() that the data is now on the heap and      * so it should morph the bucket into a regular heap      * bucket before continuing.      */
name|apr_pool_t
modifier|*
name|pool
decl_stmt|;
comment|/** The freelist this structure was allocated from, which is      * needed in the cleanup phase in order to allocate space on the heap      */
name|apr_bucket_alloc_t
modifier|*
name|list
decl_stmt|;
block|}
struct|;
if|#
directive|if
name|APR_HAS_MMAP
comment|/** @see apr_bucket_mmap */
typedef|typedef
name|struct
name|apr_bucket_mmap
name|apr_bucket_mmap
typedef|;
comment|/**  * A bucket referring to an mmap()ed file  */
struct|struct
name|apr_bucket_mmap
block|{
comment|/** Number of buckets using this memory */
name|apr_bucket_refcount
name|refcount
decl_stmt|;
comment|/** The mmap this sub_bucket refers to */
name|apr_mmap_t
modifier|*
name|mmap
decl_stmt|;
block|}
struct|;
endif|#
directive|endif
comment|/** @see apr_bucket_file */
typedef|typedef
name|struct
name|apr_bucket_file
name|apr_bucket_file
typedef|;
comment|/**  * A bucket referring to an file  */
struct|struct
name|apr_bucket_file
block|{
comment|/** Number of buckets using this memory */
name|apr_bucket_refcount
name|refcount
decl_stmt|;
comment|/** The file this bucket refers to */
name|apr_file_t
modifier|*
name|fd
decl_stmt|;
comment|/** The pool into which any needed structures should      *  be created while reading from this file bucket */
name|apr_pool_t
modifier|*
name|readpool
decl_stmt|;
if|#
directive|if
name|APR_HAS_MMAP
comment|/** Whether this bucket should be memory-mapped if      *  a caller tries to read from it */
name|int
name|can_mmap
decl_stmt|;
endif|#
directive|endif
comment|/* APR_HAS_MMAP */
block|}
struct|;
comment|/** @see apr_bucket_structs */
typedef|typedef
name|union
name|apr_bucket_structs
name|apr_bucket_structs
typedef|;
comment|/**  * A union of all bucket structures so we know what  * the max size is.  */
union|union
name|apr_bucket_structs
block|{
name|apr_bucket
name|b
decl_stmt|;
comment|/**< Bucket */
name|apr_bucket_heap
name|heap
decl_stmt|;
comment|/**< Heap */
name|apr_bucket_pool
name|pool
decl_stmt|;
comment|/**< Pool */
if|#
directive|if
name|APR_HAS_MMAP
name|apr_bucket_mmap
name|mmap
decl_stmt|;
comment|/**< MMap */
endif|#
directive|endif
name|apr_bucket_file
name|file
decl_stmt|;
comment|/**< File */
block|}
union|;
comment|/**  * The amount that apr_bucket_alloc() should allocate in the common case.  * Note: this is twice as big as apr_bucket_structs to allow breathing  * room for third-party bucket types.  */
define|#
directive|define
name|APR_BUCKET_ALLOC_SIZE
value|APR_ALIGN_DEFAULT(2*sizeof(apr_bucket_structs))
comment|/*  *****  Bucket Brigade Functions  *****  */
comment|/**  * Create a new bucket brigade.  The bucket brigade is originally empty.  * @param p The pool to associate with the brigade.  Data is not allocated out  *          of the pool, but a cleanup is registered.  * @param list The bucket allocator to use  * @return The empty bucket brigade  */
name|APU_DECLARE
argument_list|(
argument|apr_bucket_brigade *
argument_list|)
name|apr_brigade_create
argument_list|(
name|apr_pool_t
operator|*
name|p
argument_list|,
name|apr_bucket_alloc_t
operator|*
name|list
argument_list|)
expr_stmt|;
comment|/**  * destroy an entire bucket brigade.  This includes destroying all of the  * buckets within the bucket brigade's bucket list.   * @param b The bucket brigade to destroy  */
name|APU_DECLARE
argument_list|(
argument|apr_status_t
argument_list|)
name|apr_brigade_destroy
argument_list|(
name|apr_bucket_brigade
operator|*
name|b
argument_list|)
expr_stmt|;
comment|/**  * empty out an entire bucket brigade.  This includes destroying all of the  * buckets within the bucket brigade's bucket list.  This is similar to  * apr_brigade_destroy(), except that it does not deregister the brigade's  * pool cleanup function.  * @param data The bucket brigade to clean up  * @remark Generally, you should use apr_brigade_destroy().  This function  *         can be useful in situations where you have a single brigade that  *         you wish to reuse many times by destroying all of the buckets in  *         the brigade and putting new buckets into it later.  */
name|APU_DECLARE
argument_list|(
argument|apr_status_t
argument_list|)
name|apr_brigade_cleanup
argument_list|(
name|void
operator|*
name|data
argument_list|)
expr_stmt|;
comment|/**  * Move the buckets from the tail end of the existing brigade @a b into  * the brigade @a a. If @a a is NULL a new brigade is created. Buckets  * from @a e to the last bucket (inclusively) of brigade @a b are moved  * from @a b to the returned brigade @a a.  *  * @param b The brigade to split  * @param e The first bucket to move  * @param a The brigade which should be used for the result or NULL if  *          a new brigade should be created. The brigade @a a will be  *          cleared if it is not empty.  * @return The brigade supplied in @a a or a new one if @a a was NULL.  * @warning Note that this function allocates a new brigade if @a a is  * NULL so memory consumption should be carefully considered.  */
name|APU_DECLARE
argument_list|(
argument|apr_bucket_brigade *
argument_list|)
name|apr_brigade_split_ex
argument_list|(
name|apr_bucket_brigade
operator|*
name|b
argument_list|,
name|apr_bucket
operator|*
name|e
argument_list|,
name|apr_bucket_brigade
operator|*
name|a
argument_list|)
expr_stmt|;
comment|/**  * Create a new bucket brigade and move the buckets from the tail end  * of an existing brigade into the new brigade.  Buckets from   * @a e to the last bucket (inclusively) of brigade @a b  * are moved from @a b to the returned brigade.  * @param b The brigade to split   * @param e The first bucket to move  * @return The new brigade  * @warning Note that this function always allocates a new brigade  * so memory consumption should be carefully considered.  */
name|APU_DECLARE
argument_list|(
argument|apr_bucket_brigade *
argument_list|)
name|apr_brigade_split
argument_list|(
name|apr_bucket_brigade
operator|*
name|b
argument_list|,
name|apr_bucket
operator|*
name|e
argument_list|)
expr_stmt|;
comment|/**  * Partition a bucket brigade at a given offset (in bytes from the start of  * the brigade).  This is useful whenever a filter wants to use known ranges  * of bytes from the brigade; the ranges can even overlap.  * @param b The brigade to partition  * @param point The offset at which to partition the brigade  * @param after_point Returns a pointer to the first bucket after the partition  * @return APR_SUCCESS on success, APR_INCOMPLETE if the contents of the  * brigade were shorter than @a point, or an error code.  * @remark if APR_INCOMPLETE is returned, @a after_point will be set to  * the brigade sentinel.  */
name|APU_DECLARE
argument_list|(
argument|apr_status_t
argument_list|)
name|apr_brigade_partition
argument_list|(
argument|apr_bucket_brigade *b
argument_list|,
argument|apr_off_t point
argument_list|,
argument|apr_bucket **after_point
argument_list|)
empty_stmt|;
comment|/**  * Return the total length of the brigade.  * @param bb The brigade to compute the length of  * @param read_all Read unknown-length buckets to force a size  * @param length Returns the length of the brigade (up to the end, or up  *               to a bucket read error), or -1 if the brigade has buckets  *               of indeterminate length and read_all is 0.  */
name|APU_DECLARE
argument_list|(
argument|apr_status_t
argument_list|)
name|apr_brigade_length
argument_list|(
argument|apr_bucket_brigade *bb
argument_list|,
argument|int read_all
argument_list|,
argument|apr_off_t *length
argument_list|)
empty_stmt|;
comment|/**  * Take a bucket brigade and store the data in a flat char*  * @param bb The bucket brigade to create the char* from  * @param c The char* to write into  * @param len The maximum length of the char array. On return, it is the  *            actual length of the char array.  */
name|APU_DECLARE
argument_list|(
argument|apr_status_t
argument_list|)
name|apr_brigade_flatten
argument_list|(
name|apr_bucket_brigade
operator|*
name|bb
argument_list|,
name|char
operator|*
name|c
argument_list|,
name|apr_size_t
operator|*
name|len
argument_list|)
expr_stmt|;
comment|/**  * Creates a pool-allocated string representing a flat bucket brigade  * @param bb The bucket brigade to create the char array from  * @param c On return, the allocated char array  * @param len On return, the length of the char array.  * @param pool The pool to allocate the string from.  */
name|APU_DECLARE
argument_list|(
argument|apr_status_t
argument_list|)
name|apr_brigade_pflatten
argument_list|(
name|apr_bucket_brigade
operator|*
name|bb
argument_list|,
name|char
operator|*
operator|*
name|c
argument_list|,
name|apr_size_t
operator|*
name|len
argument_list|,
name|apr_pool_t
operator|*
name|pool
argument_list|)
expr_stmt|;
comment|/**  * Split a brigade to represent one LF line.  * @param bbOut The bucket brigade that will have the LF line appended to.  * @param bbIn The input bucket brigade to search for a LF-line.  * @param block The blocking mode to be used to split the line.  * @param maxbytes The maximum bytes to read.  If this many bytes are seen  *                 without a LF, the brigade will contain a partial line.  */
name|APU_DECLARE
argument_list|(
argument|apr_status_t
argument_list|)
name|apr_brigade_split_line
argument_list|(
argument|apr_bucket_brigade *bbOut
argument_list|,
argument|apr_bucket_brigade *bbIn
argument_list|,
argument|apr_read_type_e block
argument_list|,
argument|apr_off_t maxbytes
argument_list|)
empty_stmt|;
comment|/**  * Create an iovec of the elements in a bucket_brigade... return number   * of elements used.  This is useful for writing to a file or to the  * network efficiently.  * @param b The bucket brigade to create the iovec from  * @param vec The iovec to create  * @param nvec The number of elements in the iovec. On return, it is the  *             number of iovec elements actually filled out.  */
name|APU_DECLARE
argument_list|(
argument|apr_status_t
argument_list|)
name|apr_brigade_to_iovec
argument_list|(
name|apr_bucket_brigade
operator|*
name|b
argument_list|,
expr|struct
name|iovec
operator|*
name|vec
argument_list|,
name|int
operator|*
name|nvec
argument_list|)
expr_stmt|;
comment|/**  * This function writes a list of strings into a bucket brigade.   * @param b The bucket brigade to add to  * @param flush The flush function to use if the brigade is full  * @param ctx The structure to pass to the flush function  * @param va A list of strings to add  * @return APR_SUCCESS or error code.  */
name|APU_DECLARE
argument_list|(
argument|apr_status_t
argument_list|)
name|apr_brigade_vputstrs
argument_list|(
argument|apr_bucket_brigade *b
argument_list|,
argument|apr_brigade_flush flush
argument_list|,
argument|void *ctx
argument_list|,
argument|va_list va
argument_list|)
empty_stmt|;
comment|/**  * This function writes a string into a bucket brigade.  *  * The apr_brigade_write function attempts to be efficient with the  * handling of heap buckets. Regardless of the amount of data stored  * inside a heap bucket, heap buckets are a fixed size to promote their  * reuse.  *  * If an attempt is made to write a string to a brigade that already   * ends with a heap bucket, this function will attempt to pack the  * string into the remaining space in the previous heap bucket, before  * allocating a new heap bucket.  *  * This function always returns APR_SUCCESS, unless a flush function is  * passed, in which case the return value of the flush function will be  * returned if used.  * @param b The bucket brigade to add to  * @param flush The flush function to use if the brigade is full  * @param ctx The structure to pass to the flush function  * @param str The string to add  * @param nbyte The number of bytes to write  * @return APR_SUCCESS or error code  */
name|APU_DECLARE
argument_list|(
argument|apr_status_t
argument_list|)
name|apr_brigade_write
argument_list|(
argument|apr_bucket_brigade *b
argument_list|,
argument|apr_brigade_flush flush
argument_list|,
argument|void *ctx
argument_list|,
argument|const char *str
argument_list|,
argument|apr_size_t nbyte
argument_list|)
empty_stmt|;
comment|/**  * This function writes multiple strings into a bucket brigade.  * @param b The bucket brigade to add to  * @param flush The flush function to use if the brigade is full  * @param ctx The structure to pass to the flush function  * @param vec The strings to add (address plus length for each)  * @param nvec The number of entries in iovec  * @return APR_SUCCESS or error code  */
name|APU_DECLARE
argument_list|(
argument|apr_status_t
argument_list|)
name|apr_brigade_writev
argument_list|(
argument|apr_bucket_brigade *b
argument_list|,
argument|apr_brigade_flush flush
argument_list|,
argument|void *ctx
argument_list|,
argument|const struct iovec *vec
argument_list|,
argument|apr_size_t nvec
argument_list|)
empty_stmt|;
comment|/**  * This function writes a string into a bucket brigade.  * @param bb The bucket brigade to add to  * @param flush The flush function to use if the brigade is full  * @param ctx The structure to pass to the flush function  * @param str The string to add  * @return APR_SUCCESS or error code  */
name|APU_DECLARE
argument_list|(
argument|apr_status_t
argument_list|)
name|apr_brigade_puts
argument_list|(
argument|apr_bucket_brigade *bb
argument_list|,
argument|apr_brigade_flush flush
argument_list|,
argument|void *ctx
argument_list|,
argument|const char *str
argument_list|)
empty_stmt|;
comment|/**  * This function writes a character into a bucket brigade.  * @param b The bucket brigade to add to  * @param flush The flush function to use if the brigade is full  * @param ctx The structure to pass to the flush function  * @param c The character to add  * @return APR_SUCCESS or error code  */
name|APU_DECLARE
argument_list|(
argument|apr_status_t
argument_list|)
name|apr_brigade_putc
argument_list|(
argument|apr_bucket_brigade *b
argument_list|,
argument|apr_brigade_flush flush
argument_list|,
argument|void *ctx
argument_list|,
argument|const char c
argument_list|)
empty_stmt|;
comment|/**  * This function writes an unspecified number of strings into a bucket brigade.  * @param b The bucket brigade to add to  * @param flush The flush function to use if the brigade is full  * @param ctx The structure to pass to the flush function  * @param ... The strings to add  * @return APR_SUCCESS or error code  */
name|APU_DECLARE_NONSTD
argument_list|(
argument|apr_status_t
argument_list|)
name|apr_brigade_putstrs
argument_list|(
argument|apr_bucket_brigade *b
argument_list|,
argument|apr_brigade_flush flush
argument_list|,
argument|void *ctx
argument_list|,
argument|...
argument_list|)
empty_stmt|;
comment|/**  * Evaluate a printf and put the resulting string at the end   * of the bucket brigade.  * @param b The brigade to write to  * @param flush The flush function to use if the brigade is full  * @param ctx The structure to pass to the flush function  * @param fmt The format of the string to write  * @param ... The arguments to fill out the format  * @return APR_SUCCESS or error code  */
name|APU_DECLARE_NONSTD
argument_list|(
argument|apr_status_t
argument_list|)
name|apr_brigade_printf
argument_list|(
argument|apr_bucket_brigade *b
argument_list|,
argument|apr_brigade_flush flush
argument_list|,
argument|void *ctx
argument_list|,
argument|const char *fmt
argument_list|,
argument|...
argument_list|)
name|__attribute__
argument_list|(
operator|(
name|format
argument_list|(
name|printf
argument_list|,
literal|4
argument_list|,
literal|5
argument_list|)
operator|)
argument_list|)
expr_stmt|;
comment|/**  * Evaluate a printf and put the resulting string at the end   * of the bucket brigade.  * @param b The brigade to write to  * @param flush The flush function to use if the brigade is full  * @param ctx The structure to pass to the flush function  * @param fmt The format of the string to write  * @param va The arguments to fill out the format  * @return APR_SUCCESS or error code  */
name|APU_DECLARE
argument_list|(
argument|apr_status_t
argument_list|)
name|apr_brigade_vprintf
argument_list|(
argument|apr_bucket_brigade *b
argument_list|,
argument|apr_brigade_flush flush
argument_list|,
argument|void *ctx
argument_list|,
argument|const char *fmt
argument_list|,
argument|va_list va
argument_list|)
empty_stmt|;
comment|/**  * Utility function to insert a file (or a segment of a file) onto the  * end of the brigade.  The file is split into multiple buckets if it  * is larger than the maximum size which can be represented by a  * single bucket.  * @param bb the brigade to insert into  * @param f the file to insert  * @param start the offset of the start of the segment  * @param len the length of the segment of the file to insert  * @param p pool from which file buckets are allocated  * @return the last bucket inserted  */
name|APU_DECLARE
argument_list|(
argument|apr_bucket *
argument_list|)
name|apr_brigade_insert_file
argument_list|(
argument|apr_bucket_brigade *bb
argument_list|,
argument|apr_file_t *f
argument_list|,
argument|apr_off_t start
argument_list|,
argument|apr_off_t len
argument_list|,
argument|apr_pool_t *p
argument_list|)
empty_stmt|;
comment|/*  *****  Bucket freelist functions *****  */
comment|/**  * Create a bucket allocator.  * @param p This pool's underlying apr_allocator_t is used to allocate memory  *          for the bucket allocator.  When the pool is destroyed, the bucket  *          allocator's cleanup routine will free all memory that has been  *          allocated from it.  * @remark  The reason the allocator gets its memory from the pool's  *          apr_allocator_t rather than from the pool itself is because  *          the bucket allocator will free large memory blocks back to the  *          allocator when it's done with them, thereby preventing memory  *          footprint growth that would occur if we allocated from the pool.  * @warning The allocator must never be used by more than one thread at a time.  */
name|APU_DECLARE_NONSTD
argument_list|(
argument|apr_bucket_alloc_t *
argument_list|)
name|apr_bucket_alloc_create
argument_list|(
name|apr_pool_t
operator|*
name|p
argument_list|)
expr_stmt|;
comment|/**  * Create a bucket allocator.  * @param allocator This apr_allocator_t is used to allocate both the bucket  *          allocator and all memory handed out by the bucket allocator.  The  *          caller is responsible for destroying the bucket allocator and the  *          apr_allocator_t -- no automatic cleanups will happen.  * @warning The allocator must never be used by more than one thread at a time.  */
name|APU_DECLARE_NONSTD
argument_list|(
argument|apr_bucket_alloc_t *
argument_list|)
name|apr_bucket_alloc_create_ex
argument_list|(
name|apr_allocator_t
operator|*
name|allocator
argument_list|)
expr_stmt|;
comment|/**  * Destroy a bucket allocator.  * @param list The allocator to be destroyed  */
name|APU_DECLARE_NONSTD
argument_list|(
argument|void
argument_list|)
name|apr_bucket_alloc_destroy
argument_list|(
name|apr_bucket_alloc_t
operator|*
name|list
argument_list|)
expr_stmt|;
comment|/**  * Allocate memory for use by the buckets.  * @param size The amount to allocate.  * @param list The allocator from which to allocate the memory.  */
name|APU_DECLARE_NONSTD
argument_list|(
argument|void *
argument_list|)
name|apr_bucket_alloc
argument_list|(
argument|apr_size_t size
argument_list|,
argument|apr_bucket_alloc_t *list
argument_list|)
empty_stmt|;
comment|/**  * Free memory previously allocated with apr_bucket_alloc().  * @param block The block of memory to be freed.  */
name|APU_DECLARE_NONSTD
argument_list|(
argument|void
argument_list|)
name|apr_bucket_free
argument_list|(
name|void
operator|*
name|block
argument_list|)
expr_stmt|;
comment|/*  *****  Bucket Functions  *****  */
comment|/**  * Free the resources used by a bucket. If multiple buckets refer to  * the same resource it is freed when the last one goes away.  * @see apr_bucket_delete()  * @param e The bucket to destroy  */
define|#
directive|define
name|apr_bucket_destroy
parameter_list|(
name|e
parameter_list|)
value|do {					\         (e)->type->destroy((e)->data);					\         (e)->free(e);							\     } while (0)
comment|/**  * Delete a bucket by removing it from its brigade (if any) and then  * destroying it.  * @remark This mainly acts as an aid in avoiding code verbosity.  It is  * the preferred exact equivalent to:  *<pre>  *      APR_BUCKET_REMOVE(e);  *      apr_bucket_destroy(e);  *</pre>  * @param e The bucket to delete  */
define|#
directive|define
name|apr_bucket_delete
parameter_list|(
name|e
parameter_list|)
value|do {					\         APR_BUCKET_REMOVE(e);						\         apr_bucket_destroy(e);						\     } while (0)
comment|/**  * Read some data from the bucket.  *  * The apr_bucket_read function returns a convenient amount of data  * from the bucket provided, writing the address and length of the  * data to the pointers provided by the caller. The function tries  * as hard as possible to avoid a memory copy.  *  * Buckets are expected to be a member of a brigade at the time they  * are read.  *  * In typical application code, buckets are read in a loop, and after  * each bucket is read and processed, it is moved or deleted from the  * brigade and the next bucket read.  *  * The definition of "convenient" depends on the type of bucket that  * is being read, and is decided by APR. In the case of memory based  * buckets such as heap and immortal buckets, a pointer will be  * returned to the location of the buffer containing the complete  * contents of the bucket.  *  * Some buckets, such as the socket bucket, might have no concept  * of length. If an attempt is made to read such a bucket, the  * apr_bucket_read function will read a convenient amount of data  * from the socket. The socket bucket is magically morphed into a  * heap bucket containing the just-read data, and a new socket bucket  * is inserted just after this heap bucket.  *  * To understand why apr_bucket_read might do this, consider the loop  * described above to read and process buckets. The current bucket  * is magically morphed into a heap bucket and returned to the caller.  * The caller processes the data, and deletes the heap bucket, moving  * onto the next bucket, the new socket bucket. This process repeats,  * giving the illusion of a bucket brigade that contains potentially  * infinite amounts of data. It is up to the caller to decide at what  * point to stop reading buckets.  *  * Some buckets, such as the file bucket, might have a fixed size,  * but be significantly larger than is practical to store in RAM in  * one go. As with the socket bucket, if an attempt is made to read  * from a file bucket, the file bucket is magically morphed into a  * heap bucket containing a convenient amount of data read from the  * current offset in the file. During the read, the offset will be  * moved forward on the file, and a new file bucket will be inserted  * directly after the current bucket representing the remainder of the  * file. If the heap bucket was large enough to store the whole  * remainder of the file, no more file buckets are inserted, and the  * file bucket will disappear completely.  *  * The pattern for reading buckets described above does create the  * illusion that the code is willing to swallow buckets that might be  * too large for the system to handle in one go. This however is just  * an illusion: APR will always ensure that large (file) or infinite  * (socket) buckets are broken into convenient bite sized heap buckets  * before data is returned to the caller.  *  * There is a potential gotcha to watch for: if buckets are read in a  * loop, and aren't deleted after being processed, the potentially large  * bucket will slowly be converted into RAM resident heap buckets. If  * the file is larger than available RAM, an out of memory condition  * could be caused if the application is not careful to manage this.  *  * @param e The bucket to read from  * @param str The location to store a pointer to the data in  * @param len The location to store the amount of data read  * @param block Whether the read function blocks  */
define|#
directive|define
name|apr_bucket_read
parameter_list|(
name|e
parameter_list|,
name|str
parameter_list|,
name|len
parameter_list|,
name|block
parameter_list|)
value|(e)->type->read(e, str, len, block)
comment|/**  * Setaside data so that stack data is not destroyed on returning from  * the function  * @param e The bucket to setaside  * @param p The pool to setaside into  */
define|#
directive|define
name|apr_bucket_setaside
parameter_list|(
name|e
parameter_list|,
name|p
parameter_list|)
value|(e)->type->setaside(e,p)
comment|/**  * Split one bucket in two at the point provided.  *   * Once split, the original bucket becomes the first of the two new buckets.  *   * (It is assumed that the bucket is a member of a brigade when this  * function is called).  * @param e The bucket to split  * @param point The offset to split the bucket at  */
define|#
directive|define
name|apr_bucket_split
parameter_list|(
name|e
parameter_list|,
name|point
parameter_list|)
value|(e)->type->split(e, point)
comment|/**  * Copy a bucket.  * @param e The bucket to copy  * @param c Returns a pointer to the new bucket  */
define|#
directive|define
name|apr_bucket_copy
parameter_list|(
name|e
parameter_list|,
name|c
parameter_list|)
value|(e)->type->copy(e, c)
comment|/* Bucket type handling */
comment|/**  * This function simply returns APR_SUCCESS to denote that the bucket does  * not require anything to happen for its setaside() function. This is  * appropriate for buckets that have "immortal" data -- the data will live  * at least as long as the bucket.  * @param data The bucket to setaside  * @param pool The pool defining the desired lifetime of the bucket data  * @return APR_SUCCESS  */
name|APU_DECLARE_NONSTD
argument_list|(
argument|apr_status_t
argument_list|)
name|apr_bucket_setaside_noop
argument_list|(
name|apr_bucket
operator|*
name|data
argument_list|,
name|apr_pool_t
operator|*
name|pool
argument_list|)
expr_stmt|;
comment|/**  * A place holder function that signifies that the setaside function was not  * implemented for this bucket  * @param data The bucket to setaside  * @param pool The pool defining the desired lifetime of the bucket data  * @return APR_ENOTIMPL  */
name|APU_DECLARE_NONSTD
argument_list|(
argument|apr_status_t
argument_list|)
name|apr_bucket_setaside_notimpl
argument_list|(
name|apr_bucket
operator|*
name|data
argument_list|,
name|apr_pool_t
operator|*
name|pool
argument_list|)
expr_stmt|;
comment|/**  * A place holder function that signifies that the split function was not  * implemented for this bucket  * @param data The bucket to split  * @param point The location to split the bucket  * @return APR_ENOTIMPL  */
name|APU_DECLARE_NONSTD
argument_list|(
argument|apr_status_t
argument_list|)
name|apr_bucket_split_notimpl
argument_list|(
argument|apr_bucket *data
argument_list|,
argument|apr_size_t point
argument_list|)
empty_stmt|;
comment|/**  * A place holder function that signifies that the copy function was not  * implemented for this bucket  * @param e The bucket to copy  * @param c Returns a pointer to the new bucket  * @return APR_ENOTIMPL  */
name|APU_DECLARE_NONSTD
argument_list|(
argument|apr_status_t
argument_list|)
name|apr_bucket_copy_notimpl
argument_list|(
name|apr_bucket
operator|*
name|e
argument_list|,
name|apr_bucket
operator|*
operator|*
name|c
argument_list|)
expr_stmt|;
comment|/**  * A place holder function that signifies that this bucket does not need  * to do anything special to be destroyed.  That's only the case for buckets  * that either have no data (metadata buckets) or buckets whose data pointer  * points to something that's not a bucket-type-specific structure, as with  * simple buckets where data points to a string and pipe buckets where data  * points directly to the apr_file_t.  * @param data The bucket data to destroy  */
name|APU_DECLARE_NONSTD
argument_list|(
argument|void
argument_list|)
name|apr_bucket_destroy_noop
argument_list|(
name|void
operator|*
name|data
argument_list|)
expr_stmt|;
comment|/**  * There is no apr_bucket_destroy_notimpl, because destruction is required  * to be implemented (it could be a noop, but only if that makes sense for  * the bucket type)  */
comment|/* There is no apr_bucket_read_notimpl, because it is a required function  */
comment|/* All of the bucket types implemented by the core */
comment|/**  * The flush bucket type.  This signifies that all data should be flushed to  * the next filter.  The flush bucket should be sent with the other buckets.  */
name|APU_DECLARE_DATA
specifier|extern
specifier|const
name|apr_bucket_type_t
name|apr_bucket_type_flush
decl_stmt|;
comment|/**  * The EOS bucket type.  This signifies that there will be no more data, ever.  * All filters MUST send all data to the next filter when they receive a  * bucket of this type  */
name|APU_DECLARE_DATA
specifier|extern
specifier|const
name|apr_bucket_type_t
name|apr_bucket_type_eos
decl_stmt|;
comment|/**  * The FILE bucket type.  This bucket represents a file on disk  */
name|APU_DECLARE_DATA
specifier|extern
specifier|const
name|apr_bucket_type_t
name|apr_bucket_type_file
decl_stmt|;
comment|/**  * The HEAP bucket type.  This bucket represents a data allocated from the  * heap.  */
name|APU_DECLARE_DATA
specifier|extern
specifier|const
name|apr_bucket_type_t
name|apr_bucket_type_heap
decl_stmt|;
if|#
directive|if
name|APR_HAS_MMAP
comment|/**  * The MMAP bucket type.  This bucket represents an MMAP'ed file  */
name|APU_DECLARE_DATA
specifier|extern
specifier|const
name|apr_bucket_type_t
name|apr_bucket_type_mmap
decl_stmt|;
endif|#
directive|endif
comment|/**  * The POOL bucket type.  This bucket represents a data that was allocated  * from a pool.  IF this bucket is still available when the pool is cleared,  * the data is copied on to the heap.  */
name|APU_DECLARE_DATA
specifier|extern
specifier|const
name|apr_bucket_type_t
name|apr_bucket_type_pool
decl_stmt|;
comment|/**  * The PIPE bucket type.  This bucket represents a pipe to another program.  */
name|APU_DECLARE_DATA
specifier|extern
specifier|const
name|apr_bucket_type_t
name|apr_bucket_type_pipe
decl_stmt|;
comment|/**  * The IMMORTAL bucket type.  This bucket represents a segment of data that  * the creator is willing to take responsibility for.  The core will do  * nothing with the data in an immortal bucket  */
name|APU_DECLARE_DATA
specifier|extern
specifier|const
name|apr_bucket_type_t
name|apr_bucket_type_immortal
decl_stmt|;
comment|/**  * The TRANSIENT bucket type.  This bucket represents a data allocated off  * the stack.  When the setaside function is called, this data is copied on  * to the heap  */
name|APU_DECLARE_DATA
specifier|extern
specifier|const
name|apr_bucket_type_t
name|apr_bucket_type_transient
decl_stmt|;
comment|/**  * The SOCKET bucket type.  This bucket represents a socket to another machine  */
name|APU_DECLARE_DATA
specifier|extern
specifier|const
name|apr_bucket_type_t
name|apr_bucket_type_socket
decl_stmt|;
comment|/*  *****  Simple buckets  *****  */
comment|/**  * Split a simple bucket into two at the given point.  Most non-reference  * counting buckets that allow multiple references to the same block of  * data (eg transient and immortal) will use this as their split function  * without any additional type-specific handling.  * @param b The bucket to be split  * @param point The offset of the first byte in the new bucket  * @return APR_EINVAL if the point is not within the bucket;  *         APR_ENOMEM if allocation failed;  *         or APR_SUCCESS  */
name|APU_DECLARE_NONSTD
argument_list|(
argument|apr_status_t
argument_list|)
name|apr_bucket_simple_split
argument_list|(
argument|apr_bucket *b
argument_list|,
argument|apr_size_t point
argument_list|)
empty_stmt|;
comment|/**  * Copy a simple bucket.  Most non-reference-counting buckets that allow  * multiple references to the same block of data (eg transient and immortal)  * will use this as their copy function without any additional type-specific  * handling.  * @param a The bucket to copy  * @param b Returns a pointer to the new bucket  * @return APR_ENOMEM if allocation failed;  *         or APR_SUCCESS  */
name|APU_DECLARE_NONSTD
argument_list|(
argument|apr_status_t
argument_list|)
name|apr_bucket_simple_copy
argument_list|(
name|apr_bucket
operator|*
name|a
argument_list|,
name|apr_bucket
operator|*
operator|*
name|b
argument_list|)
expr_stmt|;
comment|/*  *****  Shared, reference-counted buckets  *****  */
comment|/**  * Initialize a bucket containing reference-counted data that may be  * shared. The caller must allocate the bucket if necessary and  * initialize its type-dependent fields, and allocate and initialize  * its own private data structure. This function should only be called  * by type-specific bucket creation functions.  * @param b The bucket to initialize  * @param data A pointer to the private data structure  *             with the reference count at the start  * @param start The start of the data in the bucket  *              relative to the private base pointer  * @param length The length of the data in the bucket  * @return The new bucket, or NULL if allocation failed  */
name|APU_DECLARE
argument_list|(
argument|apr_bucket *
argument_list|)
name|apr_bucket_shared_make
argument_list|(
argument|apr_bucket *b
argument_list|,
argument|void *data
argument_list|,
argument|apr_off_t start
argument_list|,
argument|apr_size_t length
argument_list|)
empty_stmt|;
comment|/**  * Decrement the refcount of the data in the bucket. This function  * should only be called by type-specific bucket destruction functions.  * @param data The private data pointer from the bucket to be destroyed  * @return TRUE or FALSE; TRUE if the reference count is now  *         zero, indicating that the shared resource itself can  *         be destroyed by the caller.  */
name|APU_DECLARE
argument_list|(
argument|int
argument_list|)
name|apr_bucket_shared_destroy
argument_list|(
name|void
operator|*
name|data
argument_list|)
expr_stmt|;
comment|/**  * Split a bucket into two at the given point, and adjust the refcount  * to the underlying data. Most reference-counting bucket types will  * be able to use this function as their split function without any  * additional type-specific handling.  * @param b The bucket to be split  * @param point The offset of the first byte in the new bucket  * @return APR_EINVAL if the point is not within the bucket;  *         APR_ENOMEM if allocation failed;  *         or APR_SUCCESS  */
name|APU_DECLARE_NONSTD
argument_list|(
argument|apr_status_t
argument_list|)
name|apr_bucket_shared_split
argument_list|(
argument|apr_bucket *b
argument_list|,
argument|apr_size_t point
argument_list|)
empty_stmt|;
comment|/**  * Copy a refcounted bucket, incrementing the reference count. Most  * reference-counting bucket types will be able to use this function  * as their copy function without any additional type-specific handling.  * @param a The bucket to copy  * @param b Returns a pointer to the new bucket  * @return APR_ENOMEM if allocation failed;            or APR_SUCCESS  */
name|APU_DECLARE_NONSTD
argument_list|(
argument|apr_status_t
argument_list|)
name|apr_bucket_shared_copy
argument_list|(
name|apr_bucket
operator|*
name|a
argument_list|,
name|apr_bucket
operator|*
operator|*
name|b
argument_list|)
expr_stmt|;
comment|/*  *****  Functions to Create Buckets of varying types  *****  */
comment|/*  * Each bucket type foo has two initialization functions:  * apr_bucket_foo_make which sets up some already-allocated memory as a  * bucket of type foo; and apr_bucket_foo_create which allocates memory  * for the bucket, calls apr_bucket_make_foo, and initializes the  * bucket's list pointers. The apr_bucket_foo_make functions are used  * inside the bucket code to change the type of buckets in place;  * other code should call apr_bucket_foo_create. All the initialization  * functions change nothing if they fail.  */
comment|/**  * Create an End of Stream bucket.  This indicates that there is no more data  * coming from down the filter stack.  All filters should flush at this point.  * @param list The freelist from which this bucket should be allocated  * @return The new bucket, or NULL if allocation failed  */
name|APU_DECLARE
argument_list|(
argument|apr_bucket *
argument_list|)
name|apr_bucket_eos_create
argument_list|(
name|apr_bucket_alloc_t
operator|*
name|list
argument_list|)
expr_stmt|;
comment|/**  * Make the bucket passed in an EOS bucket.  This indicates that there is no   * more data coming from down the filter stack.  All filters should flush at   * this point.  * @param b The bucket to make into an EOS bucket  * @return The new bucket, or NULL if allocation failed  */
name|APU_DECLARE
argument_list|(
argument|apr_bucket *
argument_list|)
name|apr_bucket_eos_make
argument_list|(
name|apr_bucket
operator|*
name|b
argument_list|)
expr_stmt|;
comment|/**  * Create a flush  bucket.  This indicates that filters should flush their  * data.  There is no guarantee that they will flush it, but this is the  * best we can do.  * @param list The freelist from which this bucket should be allocated  * @return The new bucket, or NULL if allocation failed  */
name|APU_DECLARE
argument_list|(
argument|apr_bucket *
argument_list|)
name|apr_bucket_flush_create
argument_list|(
name|apr_bucket_alloc_t
operator|*
name|list
argument_list|)
expr_stmt|;
comment|/**  * Make the bucket passed in a FLUSH  bucket.  This indicates that filters   * should flush their data.  There is no guarantee that they will flush it,   * but this is the best we can do.  * @param b The bucket to make into a FLUSH bucket  * @return The new bucket, or NULL if allocation failed  */
name|APU_DECLARE
argument_list|(
argument|apr_bucket *
argument_list|)
name|apr_bucket_flush_make
argument_list|(
name|apr_bucket
operator|*
name|b
argument_list|)
expr_stmt|;
comment|/**  * Create a bucket referring to long-lived data.  * @param buf The data to insert into the bucket  * @param nbyte The size of the data to insert.  * @param list The freelist from which this bucket should be allocated  * @return The new bucket, or NULL if allocation failed  */
name|APU_DECLARE
argument_list|(
argument|apr_bucket *
argument_list|)
name|apr_bucket_immortal_create
argument_list|(
argument|const char *buf
argument_list|,
argument|apr_size_t nbyte
argument_list|,
argument|apr_bucket_alloc_t *list
argument_list|)
empty_stmt|;
comment|/**  * Make the bucket passed in a bucket refer to long-lived data  * @param b The bucket to make into a IMMORTAL bucket  * @param buf The data to insert into the bucket  * @param nbyte The size of the data to insert.  * @return The new bucket, or NULL if allocation failed  */
name|APU_DECLARE
argument_list|(
argument|apr_bucket *
argument_list|)
name|apr_bucket_immortal_make
argument_list|(
argument|apr_bucket *b
argument_list|,
argument|const char *buf
argument_list|,
argument|apr_size_t nbyte
argument_list|)
empty_stmt|;
comment|/**  * Create a bucket referring to data on the stack.  * @param buf The data to insert into the bucket  * @param nbyte The size of the data to insert.  * @param list The freelist from which this bucket should be allocated  * @return The new bucket, or NULL if allocation failed  */
name|APU_DECLARE
argument_list|(
argument|apr_bucket *
argument_list|)
name|apr_bucket_transient_create
argument_list|(
argument|const char *buf
argument_list|,
argument|apr_size_t nbyte
argument_list|,
argument|apr_bucket_alloc_t *list
argument_list|)
empty_stmt|;
comment|/**  * Make the bucket passed in a bucket refer to stack data  * @param b The bucket to make into a TRANSIENT bucket  * @param buf The data to insert into the bucket  * @param nbyte The size of the data to insert.  * @return The new bucket, or NULL if allocation failed  */
name|APU_DECLARE
argument_list|(
argument|apr_bucket *
argument_list|)
name|apr_bucket_transient_make
argument_list|(
argument|apr_bucket *b
argument_list|,
argument|const char *buf
argument_list|,
argument|apr_size_t nbyte
argument_list|)
empty_stmt|;
comment|/**  * Create a bucket referring to memory on the heap. If the caller asks  * for the data to be copied, this function always allocates 4K of  * memory so that more data can be added to the bucket without  * requiring another allocation. Therefore not all the data may be put  * into the bucket. If copying is not requested then the bucket takes  * over responsibility for free()ing the memory.  * @param buf The buffer to insert into the bucket  * @param nbyte The size of the buffer to insert.  * @param free_func Function to use to free the data; NULL indicates that the  *                  bucket should make a copy of the data  * @param list The freelist from which this bucket should be allocated  * @return The new bucket, or NULL if allocation failed  */
name|APU_DECLARE
argument_list|(
argument|apr_bucket *
argument_list|)
name|apr_bucket_heap_create
argument_list|(
argument|const char *buf
argument_list|,
argument|apr_size_t nbyte
argument_list|,
argument|void (*free_func)(void *data)
argument_list|,
argument|apr_bucket_alloc_t *list
argument_list|)
empty_stmt|;
comment|/**  * Make the bucket passed in a bucket refer to heap data  * @param b The bucket to make into a HEAP bucket  * @param buf The buffer to insert into the bucket  * @param nbyte The size of the buffer to insert.  * @param free_func Function to use to free the data; NULL indicates that the  *                  bucket should make a copy of the data  * @return The new bucket, or NULL if allocation failed  */
name|APU_DECLARE
argument_list|(
argument|apr_bucket *
argument_list|)
name|apr_bucket_heap_make
argument_list|(
argument|apr_bucket *b
argument_list|,
argument|const char *buf
argument_list|,
argument|apr_size_t nbyte
argument_list|,
argument|void (*free_func)(void *data)
argument_list|)
empty_stmt|;
comment|/**  * Create a bucket referring to memory allocated from a pool.  *  * @param buf The buffer to insert into the bucket  * @param length The number of bytes referred to by this bucket  * @param pool The pool the memory was allocated from  * @param list The freelist from which this bucket should be allocated  * @return The new bucket, or NULL if allocation failed  */
name|APU_DECLARE
argument_list|(
argument|apr_bucket *
argument_list|)
name|apr_bucket_pool_create
argument_list|(
argument|const char *buf
argument_list|,
argument|apr_size_t length
argument_list|,
argument|apr_pool_t *pool
argument_list|,
argument|apr_bucket_alloc_t *list
argument_list|)
empty_stmt|;
comment|/**  * Make the bucket passed in a bucket refer to pool data  * @param b The bucket to make into a pool bucket  * @param buf The buffer to insert into the bucket  * @param length The number of bytes referred to by this bucket  * @param pool The pool the memory was allocated from  * @return The new bucket, or NULL if allocation failed  */
name|APU_DECLARE
argument_list|(
argument|apr_bucket *
argument_list|)
name|apr_bucket_pool_make
argument_list|(
argument|apr_bucket *b
argument_list|,
argument|const char *buf
argument_list|,
argument|apr_size_t length
argument_list|,
argument|apr_pool_t *pool
argument_list|)
empty_stmt|;
if|#
directive|if
name|APR_HAS_MMAP
comment|/**  * Create a bucket referring to mmap()ed memory.  * @param mm The mmap to insert into the bucket  * @param start The offset of the first byte in the mmap  *              that this bucket refers to  * @param length The number of bytes referred to by this bucket  * @param list The freelist from which this bucket should be allocated  * @return The new bucket, or NULL if allocation failed  */
name|APU_DECLARE
argument_list|(
argument|apr_bucket *
argument_list|)
name|apr_bucket_mmap_create
argument_list|(
argument|apr_mmap_t *mm
argument_list|,
argument|apr_off_t start
argument_list|,
argument|apr_size_t length
argument_list|,
argument|apr_bucket_alloc_t *list
argument_list|)
empty_stmt|;
comment|/**  * Make the bucket passed in a bucket refer to an MMAP'ed file  * @param b The bucket to make into a MMAP bucket  * @param mm The mmap to insert into the bucket  * @param start The offset of the first byte in the mmap  *              that this bucket refers to  * @param length The number of bytes referred to by this bucket  * @return The new bucket, or NULL if allocation failed  */
name|APU_DECLARE
argument_list|(
argument|apr_bucket *
argument_list|)
name|apr_bucket_mmap_make
argument_list|(
argument|apr_bucket *b
argument_list|,
argument|apr_mmap_t *mm
argument_list|,
argument|apr_off_t start
argument_list|,
argument|apr_size_t length
argument_list|)
empty_stmt|;
endif|#
directive|endif
comment|/**  * Create a bucket referring to a socket.  * @param thissock The socket to put in the bucket  * @param list The freelist from which this bucket should be allocated  * @return The new bucket, or NULL if allocation failed  */
name|APU_DECLARE
argument_list|(
argument|apr_bucket *
argument_list|)
name|apr_bucket_socket_create
argument_list|(
name|apr_socket_t
operator|*
name|thissock
argument_list|,
name|apr_bucket_alloc_t
operator|*
name|list
argument_list|)
expr_stmt|;
comment|/**  * Make the bucket passed in a bucket refer to a socket  * @param b The bucket to make into a SOCKET bucket  * @param thissock The socket to put in the bucket  * @return The new bucket, or NULL if allocation failed  */
name|APU_DECLARE
argument_list|(
argument|apr_bucket *
argument_list|)
name|apr_bucket_socket_make
argument_list|(
name|apr_bucket
operator|*
name|b
argument_list|,
name|apr_socket_t
operator|*
name|thissock
argument_list|)
expr_stmt|;
comment|/**  * Create a bucket referring to a pipe.  * @param thispipe The pipe to put in the bucket  * @param list The freelist from which this bucket should be allocated  * @return The new bucket, or NULL if allocation failed  */
name|APU_DECLARE
argument_list|(
argument|apr_bucket *
argument_list|)
name|apr_bucket_pipe_create
argument_list|(
name|apr_file_t
operator|*
name|thispipe
argument_list|,
name|apr_bucket_alloc_t
operator|*
name|list
argument_list|)
expr_stmt|;
comment|/**  * Make the bucket passed in a bucket refer to a pipe  * @param b The bucket to make into a PIPE bucket  * @param thispipe The pipe to put in the bucket  * @return The new bucket, or NULL if allocation failed  */
name|APU_DECLARE
argument_list|(
argument|apr_bucket *
argument_list|)
name|apr_bucket_pipe_make
argument_list|(
name|apr_bucket
operator|*
name|b
argument_list|,
name|apr_file_t
operator|*
name|thispipe
argument_list|)
expr_stmt|;
comment|/**  * Create a bucket referring to a file.  * @param fd The file to put in the bucket  * @param offset The offset where the data of interest begins in the file  * @param len The amount of data in the file we are interested in  * @param p The pool into which any needed structures should be created  *          while reading from this file bucket  * @param list The freelist from which this bucket should be allocated  * @return The new bucket, or NULL if allocation failed  * @remark If the file is truncated such that the segment of the file  * referenced by the bucket no longer exists, an attempt to read  * from the bucket will fail with APR_EOF.   * @remark apr_brigade_insert_file() should generally be used to  * insert files into brigades, since that function can correctly  * handle large file issues.  */
name|APU_DECLARE
argument_list|(
argument|apr_bucket *
argument_list|)
name|apr_bucket_file_create
argument_list|(
argument|apr_file_t *fd
argument_list|,
argument|apr_off_t offset
argument_list|,
argument|apr_size_t len
argument_list|,
argument|apr_pool_t *p
argument_list|,
argument|apr_bucket_alloc_t *list
argument_list|)
empty_stmt|;
comment|/**  * Make the bucket passed in a bucket refer to a file  * @param b The bucket to make into a FILE bucket  * @param fd The file to put in the bucket  * @param offset The offset where the data of interest begins in the file  * @param len The amount of data in the file we are interested in  * @param p The pool into which any needed structures should be created  *          while reading from this file bucket  * @return The new bucket, or NULL if allocation failed  */
name|APU_DECLARE
argument_list|(
argument|apr_bucket *
argument_list|)
name|apr_bucket_file_make
argument_list|(
argument|apr_bucket *b
argument_list|,
argument|apr_file_t *fd
argument_list|,
argument|apr_off_t offset
argument_list|,
argument|apr_size_t len
argument_list|,
argument|apr_pool_t *p
argument_list|)
empty_stmt|;
comment|/**  * Enable or disable memory-mapping for a FILE bucket (default is enabled)  * @param b The bucket  * @param enabled Whether memory-mapping should be enabled  * @return APR_SUCCESS normally, or an error code if the operation fails  */
name|APU_DECLARE
argument_list|(
argument|apr_status_t
argument_list|)
name|apr_bucket_file_enable_mmap
argument_list|(
argument|apr_bucket *b
argument_list|,
argument|int enabled
argument_list|)
empty_stmt|;
comment|/** @} */
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
comment|/* !APR_BUCKETS_H */
end_comment

end_unit

