begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_ifndef
ifndef|#
directive|ifndef
name|HASH_H
end_ifndef

begin_define
define|#
directive|define
name|HASH_H
end_define

begin_comment
comment|/* hash.h */
end_comment

begin_comment
comment|/************************************************************************           Copyright 1988, 1991 by Carnegie Mellon University                            All Rights Reserved  Permission to use, copy, modify, and distribute this software and its documentation for any purpose and without fee is hereby granted, provided that the above copyright notice appear in all copies and that both that copyright notice and this permission notice appear in supporting documentation, and that the name of Carnegie Mellon University not be used in advertising or publicity pertaining to distribution of the software without specific, written prior permission.  CARNEGIE MELLON UNIVERSITY DISCLAIMS ALL WARRANTIES WITH REGARD TO THIS SOFTWARE, INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL CMU BE LIABLE FOR ANY SPECIAL, INDIRECT OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE. ************************************************************************/
end_comment

begin_comment
comment|/*  * Generalized hash table ADT  *  * Provides multiple, dynamically-allocated, variable-sized hash tables on  * various data and keys.  *  * This package attempts to follow some of the coding conventions suggested  * by Bob Sidebotham and the AFS Clean Code Committee.  */
end_comment

begin_comment
comment|/*  * The user must supply the following:  *  *	1.  A comparison function which is declared as:  *  *		int compare(data1, data2)  *		hash_datum *data1, *data2;  *  *	    This function must compare the desired fields of data1 and  *	    data2 and return TRUE (1) if the data should be considered  *	    equivalent (i.e. have the same key value) or FALSE (0)  *	    otherwise.  This function is called through a pointer passed to  *	    the various hashtable functions (thus pointers to different  *	    functions may be passed to effect different tests on different  *	    hash tables).  *  *	    Internally, all the functions of this package always call the  *	    compare function with the "key" parameter as the first parameter,  *	    and a full data element as the second parameter.  Thus, the key  *	    and element arguments to functions such as hash_Lookup() may  *	    actually be of different types and the programmer may provide a  *	    compare function which compares the two different object types  *	    as desired.  *  *	    Example:  *  *		int compare(key, element)  *		char *key;  *		struct some_complex_structure *element;  *		{  *		    return !strcmp(key, element->name);  *		}  *  *		key = "John C. Doe"  *		element =&some_complex_structure  *		hash_Lookup(table, hashcode, compare, key);  *  *	2.  A hash function yielding an unsigned integer value to be used  *	    as the hashcode (index into the hashtable).  Thus, the user  *	    may hash on whatever data is desired and may use several  *	    different hash functions for various different hash tables.  *	    The actual hash table index will be the passed hashcode modulo  *	    the hash table size.  *  *	    A generalized hash function, hash_HashFunction(), is included  *	    with this package to make things a little easier.  It is not  *	    guarenteed to use the best hash algorithm in existence. . . .  */
end_comment

begin_escape
end_escape

begin_comment
comment|/*  * Various hash table definitions  */
end_comment

begin_comment
comment|/*  * Define "hash_datum" as a universal data type  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|__STDC__
end_ifdef

begin_typedef
typedef|typedef
name|void
name|hash_datum
typedef|;
end_typedef

begin_else
else|#
directive|else
end_else

begin_typedef
typedef|typedef
name|char
name|hash_datum
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_typedef
typedef|typedef
name|struct
name|hash_memberstruct
name|hash_member
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|hash_tblstruct
name|hash_tbl
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|hash_tblstruct_hdr
name|hash_tblhdr
typedef|;
end_typedef

begin_struct
struct|struct
name|hash_memberstruct
block|{
name|hash_member
modifier|*
name|next
decl_stmt|;
name|hash_datum
modifier|*
name|data
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|hash_tblstruct_hdr
block|{
name|unsigned
name|size
decl_stmt|,
name|bucketnum
decl_stmt|;
name|hash_member
modifier|*
name|member
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|hash_tblstruct
block|{
name|unsigned
name|size
decl_stmt|,
name|bucketnum
decl_stmt|;
name|hash_member
modifier|*
name|member
decl_stmt|;
comment|/* Used for linear dump */
name|hash_member
modifier|*
name|table
index|[
literal|1
index|]
decl_stmt|;
comment|/* Dynamically extended */
block|}
struct|;
end_struct

begin_comment
comment|/* ANSI function prototypes or empty arg list? */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|__STDC__
end_ifdef

begin_define
define|#
directive|define
name|P
parameter_list|(
name|args
parameter_list|)
value|args
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|P
parameter_list|(
name|args
parameter_list|)
value|()
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_typedef
typedef|typedef
name|int
argument_list|(
argument|*hash_cmpfp
argument_list|)
name|P
argument_list|(
operator|(
name|hash_datum
operator|*
operator|,
name|hash_datum
operator|*
operator|)
argument_list|)
expr_stmt|;
end_typedef

begin_typedef
typedef|typedef
name|void
argument_list|(
argument|*hash_freefp
argument_list|)
name|P
argument_list|(
operator|(
name|hash_datum
operator|*
operator|)
argument_list|)
expr_stmt|;
end_typedef

begin_decl_stmt
specifier|extern
name|hash_tbl
modifier|*
name|hash_Init
name|P
argument_list|(
operator|(
name|u_int
name|tablesize
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|hash_Reset
name|P
argument_list|(
operator|(
name|hash_tbl
operator|*
name|tbl
operator|,
name|hash_freefp
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|unsigned
name|hash_HashFunction
name|P
argument_list|(
operator|(
name|u_char
operator|*
name|str
operator|,
name|u_int
name|len
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|hash_Exists
name|P
argument_list|(
operator|(
name|hash_tbl
operator|*
operator|,
name|u_int
name|code
operator|,
name|hash_cmpfp
operator|,
name|hash_datum
operator|*
name|key
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|hash_Insert
name|P
argument_list|(
operator|(
name|hash_tbl
operator|*
operator|,
name|u_int
name|code
operator|,
name|hash_cmpfp
operator|,
name|hash_datum
operator|*
name|key
operator|,
name|hash_datum
operator|*
name|element
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|hash_Delete
name|P
argument_list|(
operator|(
name|hash_tbl
operator|*
operator|,
name|u_int
name|code
operator|,
name|hash_cmpfp
operator|,
name|hash_datum
operator|*
name|key
operator|,
name|hash_freefp
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|hash_datum
modifier|*
name|hash_Lookup
name|P
argument_list|(
operator|(
name|hash_tbl
operator|*
operator|,
name|u_int
name|code
operator|,
name|hash_cmpfp
operator|,
name|hash_datum
operator|*
name|key
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|hash_datum
modifier|*
name|hash_FirstEntry
name|P
argument_list|(
operator|(
name|hash_tbl
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|hash_datum
modifier|*
name|hash_NextEntry
name|P
argument_list|(
operator|(
name|hash_tbl
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_undef
undef|#
directive|undef
name|P
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* HASH_H */
end_comment

end_unit

