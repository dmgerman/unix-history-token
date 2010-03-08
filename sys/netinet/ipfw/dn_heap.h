begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1998-2010 Luigi Rizzo, Universita` di Pisa  * All rights reserved  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
end_comment

begin_comment
comment|/*  * Binary heap and hash tables, header file  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_IP_DN_HEAP_H
end_ifndef

begin_define
define|#
directive|define
name|_IP_DN_HEAP_H
end_define

begin_define
define|#
directive|define
name|DN_KEY_LT
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|((int64_t)((a)-(b))< 0)
end_define

begin_define
define|#
directive|define
name|DN_KEY_LEQ
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|((int64_t)((a)-(b))<= 0)
end_define

begin_comment
comment|/*  * This module implements a binary heap supporting random extraction.  *  * A heap entry contains an uint64_t key and a pointer to object.  * DN_KEY_LT(a,b) returns true if key 'a' is smaller than 'b'  *  * The heap is a struct dn_heap plus a dynamically allocated  * array of dn_heap_entry entries. 'size' represents the size of  * the array, 'elements' count entries in use. The topmost  * element has the smallest key.  * The heap supports ordered insert, and extract from the top.  * To extract an object from the middle of the heap, we the object  * must reserve an 'int32_t' to store the position of the object  * in the heap itself, and the location of this field must be  * passed as an argument to heap_init() -- use -1 if the feature  * is not used.  */
end_comment

begin_struct
struct|struct
name|dn_heap_entry
block|{
name|uint64_t
name|key
decl_stmt|;
comment|/* sorting key, smallest comes first */
name|void
modifier|*
name|object
decl_stmt|;
comment|/* object pointer */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|dn_heap
block|{
name|int
name|size
decl_stmt|;
comment|/* the size of the array */
name|int
name|elements
decl_stmt|;
comment|/* elements in use */
name|int
name|ofs
decl_stmt|;
comment|/* offset in the object of heap index */
name|struct
name|dn_heap_entry
modifier|*
name|p
decl_stmt|;
comment|/* array of "size" entries */
block|}
struct|;
end_struct

begin_enum
enum|enum
block|{
name|HEAP_SCAN_DEL
init|=
literal|1
block|,
name|HEAP_SCAN_END
init|=
literal|2
block|, }
enum|;
end_enum

begin_comment
comment|/*  * heap_init() reinitializes the heap setting the size and the offset  *	of the index for random extraction (use -1 if not used).  *	The 'elements' counter is set to 0.  *  * SET_HEAP_OFS() indicates where, in the object, is stored the index  *	for random extractions from the heap.  *  * heap_free() frees the memory associated to a heap.  *  * heap_insert() adds a key-pointer pair to the heap  *  * HEAP_TOP() returns a pointer to the top element of the heap,  *	but makes no checks on its existance (XXX should we change ?)  *  * heap_extract() removes the entry at the top, returing the pointer.  *	(the key should have been read before).  *  * heap_scan() invokes a callback on each entry of the heap.  *	The callback can return a combination of HEAP_SCAN_DEL and  *	HEAP_SCAN_END. HEAP_SCAN_DEL means the current element must  *	be removed, and HEAP_SCAN_END means to terminate the scan.  *	heap_scan() returns the number of elements removed.  *	Because the order is not guaranteed, we should use heap_scan()  *	only as a last resort mechanism.  */
end_comment

begin_define
define|#
directive|define
name|HEAP_TOP
parameter_list|(
name|h
parameter_list|)
value|((h)->p)
end_define

begin_define
define|#
directive|define
name|SET_HEAP_OFS
parameter_list|(
name|h
parameter_list|,
name|n
parameter_list|)
value|do { (h)->ofs = n; } while (0)
end_define

begin_function_decl
name|int
name|heap_init
parameter_list|(
name|struct
name|dn_heap
modifier|*
name|h
parameter_list|,
name|int
name|size
parameter_list|,
name|int
name|ofs
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|heap_insert
parameter_list|(
name|struct
name|dn_heap
modifier|*
name|h
parameter_list|,
name|uint64_t
name|key1
parameter_list|,
name|void
modifier|*
name|p
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|heap_extract
parameter_list|(
name|struct
name|dn_heap
modifier|*
name|h
parameter_list|,
name|void
modifier|*
name|obj
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|heap_free
parameter_list|(
name|struct
name|dn_heap
modifier|*
name|h
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|heap_scan
parameter_list|(
name|struct
name|dn_heap
modifier|*
parameter_list|,
name|int
function_decl|(
modifier|*
function_decl|)
parameter_list|(
name|void
modifier|*
parameter_list|,
name|uintptr_t
parameter_list|)
parameter_list|,
name|uintptr_t
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*------------------------------------------------------  * This module implements a generic hash table with support for  * running callbacks on the entire table. To avoid allocating  * memory during hash table operations, objects must reserve  * space for a link field. XXX if the heap is moderately full,  * an SLIST suffices, and we can tolerate the cost of a hash  * computation on each removal.  *  * dn_ht_init() initializes the table, setting the number of  *	buckets, the offset of the link field, the main callbacks.  *	Callbacks are:  *   *	hash(key, flags, arg) called to return a bucket index.  *	match(obj, key, flags, arg) called to determine if key  *		matches the current 'obj' in the heap  *	newh(key, flags, arg) optional, used to allocate a new  *		object during insertions.  *  * dn_ht_free() frees the heap or unlink elements.  *	DNHT_REMOVE unlink elements, 0 frees the heap.  *	You need two calls to do both.  *  * dn_ht_find() is the main lookup function, which can also be  *	used to insert or delete elements in the hash table.  *	The final 'arg' is passed to all callbacks.  *  * dn_ht_scan() is used to invoke a callback on all entries of  *	the heap, or possibly on just one bucket. The callback  *	is invoked with a pointer to the object, and must return  *	one of DNHT_SCAN_DEL or DNHT_SCAN_END to request the  *	removal of the object from the heap and the end of the  *	scan, respectively.  *  * dn_ht_scan_bucket() is similar to dn_ht_scan(), except that it scans  *	only the specific bucket of the table. The bucket is a in-out  *	parameter and return a valid bucket number if the original  *	is invalid.  *  * A combination of flags can be used to modify the operation  * of the dn_ht_find(), and of the callbacks:  *  * DNHT_KEY_IS_OBJ	means the key is the object pointer.  *	It is usally of interest for the hash and match functions.  *  * DNHT_MATCH_PTR	during a lookup, match pointers instead  *	of calling match(). Normally used when removing specific  *	entries. Does not imply KEY_IS_OBJ as the latter _is_ used  *	by the match function.  *  * DNHT_INSERT		insert the element if not found.  *	Calls new() to allocates a new object unless  *	DNHT_KEY_IS_OBJ is set.  *  * DNHT_UNIQUE		only insert if object not found.  *	XXX should it imply DNHT_INSERT ?  *  * DNHT_REMOVE		remove objects if we find them.  */
end_comment

begin_struct_decl
struct_decl|struct
name|dn_ht
struct_decl|;
end_struct_decl

begin_comment
comment|/* should be opaque */
end_comment

begin_function_decl
name|struct
name|dn_ht
modifier|*
name|dn_ht_init
parameter_list|(
name|struct
name|dn_ht
modifier|*
parameter_list|,
name|int
name|buckets
parameter_list|,
name|int
name|ofs
parameter_list|,
name|uint32_t
function_decl|(
modifier|*
name|hash
function_decl|)
parameter_list|(
name|uintptr_t
parameter_list|,
name|int
parameter_list|,
name|void
modifier|*
parameter_list|)
parameter_list|,
name|int
function_decl|(
modifier|*
name|match
function_decl|)
parameter_list|(
name|void
modifier|*
parameter_list|,
name|uintptr_t
parameter_list|,
name|int
parameter_list|,
name|void
modifier|*
parameter_list|)
parameter_list|,
name|void
modifier|*
function_decl|(
modifier|*
name|newh
function_decl|)
parameter_list|(
name|uintptr_t
parameter_list|,
name|int
parameter_list|,
name|void
modifier|*
parameter_list|)
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|dn_ht_free
parameter_list|(
name|struct
name|dn_ht
modifier|*
parameter_list|,
name|int
name|flags
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
modifier|*
name|dn_ht_find
parameter_list|(
name|struct
name|dn_ht
modifier|*
parameter_list|,
name|uintptr_t
parameter_list|,
name|int
parameter_list|,
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|dn_ht_scan
parameter_list|(
name|struct
name|dn_ht
modifier|*
parameter_list|,
name|int
function_decl|(
modifier|*
function_decl|)
parameter_list|(
name|void
modifier|*
parameter_list|,
name|void
modifier|*
parameter_list|)
parameter_list|,
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|dn_ht_scan_bucket
parameter_list|(
name|struct
name|dn_ht
modifier|*
parameter_list|,
name|int
modifier|*
parameter_list|,
name|int
function_decl|(
modifier|*
function_decl|)
parameter_list|(
name|void
modifier|*
parameter_list|,
name|void
modifier|*
parameter_list|)
parameter_list|,
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|dn_ht_entries
parameter_list|(
name|struct
name|dn_ht
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_enum
enum|enum
block|{
comment|/* flags values. 	 * first two are returned by the scan callback to indicate 	 * to delete the matching element or to end the scan 	 */
name|DNHT_SCAN_DEL
init|=
literal|0x0001
block|,
name|DNHT_SCAN_END
init|=
literal|0x0002
block|,
name|DNHT_KEY_IS_OBJ
init|=
literal|0x0004
block|,
comment|/* key is the obj pointer */
name|DNHT_MATCH_PTR
init|=
literal|0x0008
block|,
comment|/* match by pointer, not match() */
name|DNHT_INSERT
init|=
literal|0x0010
block|,
comment|/* insert if not found */
name|DNHT_UNIQUE
init|=
literal|0x0020
block|,
comment|/* report error if already there */
name|DNHT_REMOVE
init|=
literal|0x0040
block|,
comment|/* remove on find or dn_ht_free */
block|}
enum|;
end_enum

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _IP_DN_HEAP_H */
end_comment

end_unit

