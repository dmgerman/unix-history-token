begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2005 Michael Bushkov<bushman@rsu.ru>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__CACHELIB_HASHTABLE_H__
end_ifndef

begin_define
define|#
directive|define
name|__CACHELIB_HASHTABLE_H__
end_define

begin_include
include|#
directive|include
file|<search.h>
end_include

begin_include
include|#
directive|include
file|<string.h>
end_include

begin_define
define|#
directive|define
name|HASHTABLE_INITIAL_ENTRIES_CAPACITY
value|8
end_define

begin_typedef
typedef|typedef
name|int
name|hashtable_index_t
typedef|;
end_typedef

begin_comment
comment|/*  * This file contains queue.h-like macro definitions for hash tables.  * Hash table is organized as an array of the specified size of the user  * defined (with HASTABLE_ENTRY_HEAD) structures. Each hash table  * entry (user defined structure) stores its elements in the sorted array.  * You can place elements into the hash table, retrieve elements with  * specified key, traverse through all elements, and delete them.  * New elements are placed into the hash table by using the compare and  * hashing functions, provided by the user.  */
end_comment

begin_comment
comment|/*  * Defines the hash table entry structure, that uses specified type of  * elements.  */
end_comment

begin_define
define|#
directive|define
name|HASHTABLE_ENTRY_HEAD
parameter_list|(
name|name
parameter_list|,
name|type
parameter_list|)
value|struct name {			\ 	type	*values;						\ 	size_t capacity;						\ 	size_t size;							\ }
end_define

begin_comment
comment|/*  * Defines the hash table structure, which uses the specified type of entries.  * The only restriction for entries is that is that they should have the field,  * defined with HASHTABLE_ENTRY_HEAD macro.  */
end_comment

begin_define
define|#
directive|define
name|HASHTABLE_HEAD
parameter_list|(
name|name
parameter_list|,
name|entry
parameter_list|)
value|struct name {			\ 	struct entry	*entries;					\ 	size_t		entries_size;					\ }
end_define

begin_define
define|#
directive|define
name|HASHTABLE_ENTRIES_COUNT
parameter_list|(
name|table
parameter_list|)
value|((table)->entries_size)
end_define

begin_comment
comment|/*  * Unlike most of queue.h data types, hash tables can not be initialized  * statically - so there is no HASHTABLE_HEAD_INITIALIZED macro.  */
end_comment

begin_define
define|#
directive|define
name|HASHTABLE_INIT
parameter_list|(
name|table
parameter_list|,
name|type
parameter_list|,
name|field
parameter_list|,
name|_entries_size
parameter_list|)
define|\
value|do {								\ 		hashtable_index_t var;					\ 		(table)->entries = (void *)malloc(			\ 			sizeof(*(table)->entries) * (_entries_size));	\ 		memset((table)->entries, 0, 				\ 			sizeof(*(table)->entries) * (_entries_size));	\ 		(table)->entries_size = (_entries_size);		\ 		for (var = 0; var< HASHTABLE_ENTRIES_COUNT(table); ++var) {\ 			(table)->entries[var].field.capacity = 		\ 				HASHTABLE_INITIAL_ENTRIES_CAPACITY;	\ 			(table)->entries[var].field.size = 0;		\ 			(table)->entries[var].field.values = (type *)malloc(\ 				sizeof(type) * 				\ 		    		HASHTABLE_INITIAL_ENTRIES_CAPACITY);	\ 			assert((table)->entries[var].field.values != NULL);\ 		}							\ 	} while (0)
end_define

begin_comment
comment|/*  * All initialized hashtables should be destroyed with this macro.  */
end_comment

begin_define
define|#
directive|define
name|HASHTABLE_DESTROY
parameter_list|(
name|table
parameter_list|,
name|field
parameter_list|)
define|\
value|do {								\ 		hashtable_index_t var;					\ 		for (var = 0; var< HASHTABLE_ENTRIES_COUNT(table); ++var) {\ 			free((table)->entries[var].field.values);	\ 		}							\ 	} while (0)
end_define

begin_define
define|#
directive|define
name|HASHTABLE_GET_ENTRY
parameter_list|(
name|table
parameter_list|,
name|hash
parameter_list|)
value|(&((table)->entries[hash]))
end_define

begin_comment
comment|/*  * Traverses through all hash table entries  */
end_comment

begin_define
define|#
directive|define
name|HASHTABLE_FOREACH
parameter_list|(
name|table
parameter_list|,
name|var
parameter_list|)
define|\
value|for ((var) =&((table)->entries[0]);				\ 		(var)<&((table)->entries[HASHTABLE_ENTRIES_COUNT(table)]);\ 		++(var))
end_define

begin_comment
comment|/*  * Traverses through all elements of the specified hash table entry  */
end_comment

begin_define
define|#
directive|define
name|HASHTABLE_ENTRY_FOREACH
parameter_list|(
name|entry
parameter_list|,
name|field
parameter_list|,
name|var
parameter_list|)
define|\
value|for ((var) =&((entry)->field.values[0]);			\ 		(var)<&((entry)->field.values[(entry)->field.size]);	\ 		++(var))
end_define

begin_define
define|#
directive|define
name|HASHTABLE_ENTRY_CLEAR
parameter_list|(
name|entry
parameter_list|,
name|field
parameter_list|)
define|\
value|((entry)->field.size = 0)
end_define

begin_define
define|#
directive|define
name|HASHTABLE_ENTRY_SIZE
parameter_list|(
name|entry
parameter_list|,
name|field
parameter_list|)
define|\
value|((entry)->field.size)
end_define

begin_define
define|#
directive|define
name|HASHTABLE_ENTRY_CAPACITY
parameter_list|(
name|entry
parameter_list|,
name|field
parameter_list|)
define|\
value|((entry)->field.capacity)
end_define

begin_define
define|#
directive|define
name|HASHTABLE_ENTRY_CAPACITY_INCREASE
parameter_list|(
name|entry
parameter_list|,
name|field
parameter_list|,
name|type
parameter_list|)
define|\
value|(entry)->field.capacity *= 2;					\ 	(entry)->field.values = (type *)realloc((entry)->field.values, 	\ 		(entry)->field.capacity * sizeof(type));
end_define

begin_define
define|#
directive|define
name|HASHTABLE_ENTRY_CAPACITY_DECREASE
parameter_list|(
name|entry
parameter_list|,
name|field
parameter_list|,
name|type
parameter_list|)
define|\
value|(entry)->field.capacity /= 2;					\ 	(entry)->field.values = (type *)realloc((entry)->field.values, 	\ 		(entry)->field.capacity * sizeof(type));
end_define

begin_comment
comment|/*  * Generates prototypes for the hash table functions  */
end_comment

begin_define
define|#
directive|define
name|HASHTABLE_PROTOTYPE
parameter_list|(
name|name
parameter_list|,
name|entry_
parameter_list|,
name|type
parameter_list|)
define|\
value|hashtable_index_t name##_CALCULATE_HASH(struct name *, type *);		\ void name##_ENTRY_STORE(struct entry_*, type *);			\ type *name##_ENTRY_FIND(struct entry_*, type *);			\ type *name##_ENTRY_FIND_SPECIAL(struct entry_ *, type *,		\ 	int (*) (const void *, const void *));				\ void name##_ENTRY_REMOVE(struct entry_*, type *);
end_define

begin_comment
comment|/*  * Generates implementations of the hash table functions  */
end_comment

begin_define
define|#
directive|define
name|HASHTABLE_GENERATE
parameter_list|(
name|name
parameter_list|,
name|entry_
parameter_list|,
name|type
parameter_list|,
name|field
parameter_list|,
name|HASH
parameter_list|,
name|CMP
parameter_list|)
define|\
value|hashtable_index_t name##_CALCULATE_HASH(struct name *table, type *data)	\ {									\ 									\ 	return HASH(data, table->entries_size);				\ }									\ 									\ void name##_ENTRY_STORE(struct entry_ *the_entry, type *data)		\ {									\ 									\ 	if (the_entry->field.size == the_entry->field.capacity)		\ 		HASHTABLE_ENTRY_CAPACITY_INCREASE(the_entry, field, type);\ 									\ 	memcpy(&(the_entry->field.values[the_entry->field.size++]),	\ 		data,							\ 		sizeof(type));						\ 	qsort(the_entry->field.values, the_entry->field.size, 		\ 		sizeof(type), CMP);					\ }									\ 									\ type *name##_ENTRY_FIND(struct entry_ *the_entry, type *key)		\ {									\ 									\ 	return ((type *)bsearch(key, the_entry->field.values,	 	\ 		the_entry->field.size, sizeof(type), CMP));		\ }									\ 									\ type *name##_ENTRY_FIND_SPECIAL(struct entry_ *the_entry, type *key,	\ 	int (*compar) (const void *, const void *))			\ {									\ 	return ((type *)bsearch(key, the_entry->field.values,	 	\ 		the_entry->field.size, sizeof(type), compar));		\ }									\ 									\ void name##_ENTRY_REMOVE(struct entry_ *the_entry, type *del_elm)	\ {									\ 									\ 	memmove(del_elm, del_elm + 1, 					\ 		(&the_entry->field.values[--the_entry->field.size] - del_elm) *\ 		sizeof(type));						\ }
end_define

begin_comment
comment|/*  * Macro definitions below wrap the functions, generaed with  * HASHTABLE_GENERATE macro. You should use them and avoid using generated  * functions directly.  */
end_comment

begin_define
define|#
directive|define
name|HASHTABLE_CALCULATE_HASH
parameter_list|(
name|name
parameter_list|,
name|table
parameter_list|,
name|data
parameter_list|)
define|\
value|(name##_CALCULATE_HASH((table), data))
end_define

begin_define
define|#
directive|define
name|HASHTABLE_ENTRY_STORE
parameter_list|(
name|name
parameter_list|,
name|entry
parameter_list|,
name|data
parameter_list|)
define|\
value|name##_ENTRY_STORE((entry), data)
end_define

begin_define
define|#
directive|define
name|HASHTABLE_ENTRY_FIND
parameter_list|(
name|name
parameter_list|,
name|entry
parameter_list|,
name|key
parameter_list|)
define|\
value|(name##_ENTRY_FIND((entry), (key)))
end_define

begin_define
define|#
directive|define
name|HASHTABLE_ENTRY_FIND_SPECIAL
parameter_list|(
name|name
parameter_list|,
name|entry
parameter_list|,
name|key
parameter_list|,
name|cmp
parameter_list|)
define|\
value|(name##_ENTRY_FIND_SPECIAL((entry), (key), (cmp)))
end_define

begin_define
define|#
directive|define
name|HASHTABLE_ENTRY_REMOVE
parameter_list|(
name|name
parameter_list|,
name|entry
parameter_list|,
name|del_elm
parameter_list|)
define|\
value|name##_ENTRY_REMOVE((entry), (del_elm))
end_define

begin_endif
endif|#
directive|endif
end_endif

end_unit

