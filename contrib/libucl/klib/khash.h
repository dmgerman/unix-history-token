begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* The MIT License     Copyright (c) 2008, 2009, 2011 by Attractive Chaos<attractor@live.co.uk>     Permission is hereby granted, free of charge, to any person obtaining    a copy of this software and associated documentation files (the    "Software"), to deal in the Software without restriction, including    without limitation the rights to use, copy, modify, merge, publish,    distribute, sublicense, and/or sell copies of the Software, and to    permit persons to whom the Software is furnished to do so, subject to    the following conditions:     The above copyright notice and this permission notice shall be    included in all copies or substantial portions of the Software.     THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,    EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF    MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND    NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS    BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN    ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN    CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE    SOFTWARE. */
end_comment

begin_comment
comment|/*   An example:  #include "khash.h" KHASH_MAP_INIT_INT(32, char) int main() { 	int ret, is_missing; 	khiter_t k; 	khash_t(32) *h = kh_init(32); 	k = kh_put(32, h, 5,&ret); 	kh_value(h, k) = 10; 	k = kh_get(32, h, 10); 	is_missing = (k == kh_end(h)); 	k = kh_get(32, h, 5); 	kh_del(32, h, k); 	for (k = kh_begin(h); k != kh_end(h); ++k) 		if (kh_exist(h, k)) kh_value(h, k) = 1; 	kh_destroy(32, h); 	return 0; } */
end_comment

begin_comment
comment|/*   2013-05-02 (0.2.8):  	* Use quadratic probing. When the capacity is power of 2, stepping function 	  i*(i+1)/2 guarantees to traverse each bucket. It is better than double 	  hashing on cache performance and is more robust than linear probing.  	  In theory, double hashing should be more robust than quadratic probing. 	  However, my implementation is probably not for large hash tables, because 	  the second hash function is closely tied to the first hash function, 	  which reduce the effectiveness of double hashing.  	Reference: http://research.cs.vt.edu/AVresearch/hashing/quadratic.php    2011-12-29 (0.2.7):      * Minor code clean up; no actual effect.    2011-09-16 (0.2.6):  	* The capacity is a power of 2. This seems to dramatically improve the 	  speed for simple keys. Thank Zilong Tan for the suggestion. Reference:  	   - http://code.google.com/p/ulib/ 	   - http://nothings.org/computer/judy/  	* Allow to optionally use linear probing which usually has better 	  performance for random input. Double hashing is still the default as it 	  is more robust to certain non-random input.  	* Added Wang's integer hash function (not used by default). This hash 	  function is more robust to certain non-random input.    2011-02-14 (0.2.5):      * Allow to declare global functions.    2009-09-26 (0.2.4):      * Improve portability    2008-09-19 (0.2.3):  	* Corrected the example 	* Improved interfaces    2008-09-11 (0.2.2):  	* Improved speed a little in kh_put()    2008-09-10 (0.2.1):  	* Added kh_clear() 	* Fixed a compiling error    2008-09-02 (0.2.0):  	* Changed to token concatenation which increases flexibility.    2008-08-31 (0.1.2):  	* Fixed a bug in kh_get(), which has not been tested previously.    2008-08-31 (0.1.1):  	* Added destructor */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__AC_KHASH_H
end_ifndef

begin_define
define|#
directive|define
name|__AC_KHASH_H
end_define

begin_comment
comment|/*!   @header    Generic hash table library.  */
end_comment

begin_define
define|#
directive|define
name|AC_VERSION_KHASH_H
value|"0.2.8"
end_define

begin_include
include|#
directive|include
file|<stdlib.h>
end_include

begin_include
include|#
directive|include
file|<string.h>
end_include

begin_include
include|#
directive|include
file|<limits.h>
end_include

begin_comment
comment|/* compiler specific configuration */
end_comment

begin_if
if|#
directive|if
name|UINT_MAX
operator|==
literal|0xffffffffu
end_if

begin_typedef
typedef|typedef
name|unsigned
name|int
name|khint32_t
typedef|;
end_typedef

begin_elif
elif|#
directive|elif
name|ULONG_MAX
operator|==
literal|0xffffffffu
end_elif

begin_typedef
typedef|typedef
name|unsigned
name|long
name|khint32_t
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|ULONG_MAX
operator|==
name|ULLONG_MAX
end_if

begin_typedef
typedef|typedef
name|unsigned
name|long
name|khint64_t
typedef|;
end_typedef

begin_else
else|#
directive|else
end_else

begin_typedef
typedef|typedef
name|unsigned
name|long
name|long
name|khint64_t
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|kh_inline
end_ifndef

begin_ifdef
ifdef|#
directive|ifdef
name|_MSC_VER
end_ifdef

begin_define
define|#
directive|define
name|kh_inline
value|__inline
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|kh_inline
value|inline
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* kh_inline */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|kh_unused
end_ifndef

begin_ifdef
ifdef|#
directive|ifdef
name|__GNUC__
end_ifdef

begin_define
define|#
directive|define
name|kh_unused
parameter_list|(
name|x
parameter_list|)
value|__attribute__((__unused__)) x
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|kh_unused
parameter_list|(
name|x
parameter_list|)
value|x
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_typedef
typedef|typedef
name|khint32_t
name|khint_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|khint_t
name|khiter_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|__ac_isempty
parameter_list|(
name|flag
parameter_list|,
name|i
parameter_list|)
value|((flag[i>>4]>>((i&0xfU)<<1))&2)
end_define

begin_define
define|#
directive|define
name|__ac_isdel
parameter_list|(
name|flag
parameter_list|,
name|i
parameter_list|)
value|((flag[i>>4]>>((i&0xfU)<<1))&1)
end_define

begin_define
define|#
directive|define
name|__ac_iseither
parameter_list|(
name|flag
parameter_list|,
name|i
parameter_list|)
value|((flag[i>>4]>>((i&0xfU)<<1))&3)
end_define

begin_define
define|#
directive|define
name|__ac_set_isdel_false
parameter_list|(
name|flag
parameter_list|,
name|i
parameter_list|)
value|(flag[i>>4]&=~(1ul<<((i&0xfU)<<1)))
end_define

begin_define
define|#
directive|define
name|__ac_set_isempty_false
parameter_list|(
name|flag
parameter_list|,
name|i
parameter_list|)
value|(flag[i>>4]&=~(2ul<<((i&0xfU)<<1)))
end_define

begin_define
define|#
directive|define
name|__ac_set_isboth_false
parameter_list|(
name|flag
parameter_list|,
name|i
parameter_list|)
value|(flag[i>>4]&=~(3ul<<((i&0xfU)<<1)))
end_define

begin_define
define|#
directive|define
name|__ac_set_isdel_true
parameter_list|(
name|flag
parameter_list|,
name|i
parameter_list|)
value|(flag[i>>4]|=1ul<<((i&0xfU)<<1))
end_define

begin_define
define|#
directive|define
name|__ac_fsize
parameter_list|(
name|m
parameter_list|)
value|((m)< 16? 1 : (m)>>4)
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|kroundup32
end_ifndef

begin_define
define|#
directive|define
name|kroundup32
parameter_list|(
name|x
parameter_list|)
value|(--(x), (x)|=(x)>>1, (x)|=(x)>>2, (x)|=(x)>>4, (x)|=(x)>>8, (x)|=(x)>>16, ++(x))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|kcalloc
end_ifndef

begin_define
define|#
directive|define
name|kcalloc
parameter_list|(
name|N
parameter_list|,
name|Z
parameter_list|)
value|calloc(N,Z)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|kmalloc
end_ifndef

begin_define
define|#
directive|define
name|kmalloc
parameter_list|(
name|Z
parameter_list|)
value|malloc(Z)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|krealloc
end_ifndef

begin_define
define|#
directive|define
name|krealloc
parameter_list|(
name|P
parameter_list|,
name|Z
parameter_list|)
value|realloc(P,Z)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|kfree
end_ifndef

begin_define
define|#
directive|define
name|kfree
parameter_list|(
name|P
parameter_list|)
value|free(P)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
specifier|static
specifier|const
name|double
name|__ac_HASH_UPPER
init|=
literal|0.77
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|__KHASH_TYPE
parameter_list|(
name|name
parameter_list|,
name|khkey_t
parameter_list|,
name|khval_t
parameter_list|)
define|\
value|typedef struct kh_##name##_s { \ 		khint_t n_buckets, size, n_occupied, upper_bound; \ 		khint32_t *flags; \ 		khkey_t *keys; \ 		khval_t *vals; \ 	} kh_##name##_t;
end_define

begin_define
define|#
directive|define
name|__KHASH_PROTOTYPES
parameter_list|(
name|name
parameter_list|,
name|khkey_t
parameter_list|,
name|khval_t
parameter_list|)
define|\
value|extern kh_##name##_t * kh_init_##name(void);							\ 	extern void kh_destroy_##name(kh_##name##_t *h);						\ 	extern void kh_clear_##name(kh_##name##_t *h);							\ 	extern khint_t kh_get_##name(const kh_##name##_t *h, khkey_t key); 		\ 	extern int kh_resize_##name(kh_##name##_t *h, khint_t new_n_buckets); 	\ 	extern khint_t kh_put_##name(kh_##name##_t *h, khkey_t key, int *ret); 	\ 	extern void kh_del_##name(kh_##name##_t *h, khint_t x);
end_define

begin_define
define|#
directive|define
name|__KHASH_IMPL
parameter_list|(
name|name
parameter_list|,
name|SCOPE
parameter_list|,
name|khkey_t
parameter_list|,
name|khval_t
parameter_list|,
name|kh_is_map
parameter_list|,
name|__hash_func
parameter_list|,
name|__hash_equal
parameter_list|)
define|\
value|SCOPE kh_##name##_t *kh_init_##name(void) {							\ 		return (kh_##name##_t*)kcalloc(1, sizeof(kh_##name##_t));		\ 	}																	\ 	SCOPE void kh_destroy_##name(kh_##name##_t *h)						\ 	{																	\ 		if (h) {														\ 			kfree((void *)h->keys); kfree(h->flags);					\ 			kfree((void *)h->vals);										\ 			kfree(h);													\ 		}																\ 	}																	\ 	SCOPE void kh_unused(kh_clear_##name)(kh_##name##_t *h)				\ 	{																	\ 		if (h&& h->flags) {											\ 			memset(h->flags, 0xaa, __ac_fsize(h->n_buckets) * sizeof(khint32_t)); \ 			h->size = h->n_occupied = 0;								\ 		}																\ 	}																	\ 	SCOPE khint_t kh_get_##name(const kh_##name##_t *h, khkey_t key) 	\ 	{																	\ 		if (h->n_buckets) {												\ 			khint_t k, i, last, mask, step = 0; \ 			mask = h->n_buckets - 1;									\ 			k = __hash_func(key); i = k& mask;							\ 			last = i; \ 			while (!__ac_isempty(h->flags, i)&& (__ac_isdel(h->flags, i) || !__hash_equal(h->keys[i], key))) { \ 				i = (i + (++step))& mask; \ 				if (i == last) return h->n_buckets;						\ 			}															\ 			return __ac_iseither(h->flags, i)? h->n_buckets : i;		\ 		} else return 0;												\ 	}																	\ 	SCOPE int kh_resize_##name(kh_##name##_t *h, khint_t new_n_buckets) \ 	{
comment|/* This function uses 0.25*n_buckets bytes of working space instead of [sizeof(key_t+val_t)+.25]*n_buckets. */
value|\ 		khint32_t *new_flags = 0;										\ 		khint_t j = 1;													\ 		{																\ 			kroundup32(new_n_buckets); 									\ 			if (new_n_buckets< 4) new_n_buckets = 4;					\ 			if (h->size>= (khint_t)(new_n_buckets * __ac_HASH_UPPER + 0.5)) j = 0;
comment|/* requested size is too small */
value|\ 			else {
comment|/* hash table size to be changed (shrink or expand); rehash */
value|\ 				new_flags = (khint32_t*)kmalloc(__ac_fsize(new_n_buckets) * sizeof(khint32_t));	\ 				if (!new_flags) return -1;								\ 				memset(new_flags, 0xaa, __ac_fsize(new_n_buckets) * sizeof(khint32_t)); \ 				if (h->n_buckets< new_n_buckets) {
comment|/* expand */
value|\ 					khkey_t *new_keys = (khkey_t*)krealloc((void *)h->keys, new_n_buckets * sizeof(khkey_t)); \ 					if (!new_keys) { kfree(new_flags); return -1; }		\ 					h->keys = new_keys;									\ 					if (kh_is_map) {									\ 						khval_t *new_vals = (khval_t*)krealloc((void *)h->vals, new_n_buckets * sizeof(khval_t)); \ 						if (!new_vals) { kfree(new_flags); return -1; }	\ 						h->vals = new_vals;								\ 					}													\ 				}
comment|/* otherwise shrink */
value|\ 			}															\ 		}																\ 		if (j) {
comment|/* rehashing is needed */
value|\ 			for (j = 0; j != h->n_buckets; ++j) {						\ 				if (__ac_iseither(h->flags, j) == 0) {					\ 					khkey_t key = h->keys[j];							\ 					khval_t val;										\ 					khint_t new_mask;									\ 					new_mask = new_n_buckets - 1; 						\ 					if (kh_is_map) val = h->vals[j];					\ 					__ac_set_isdel_true(h->flags, j);					\ 					while (1) {
comment|/* kick-out process; sort of like in Cuckoo hashing */
value|\ 						khint_t k, i, step = 0; \ 						k = __hash_func(key);							\ 						i = k& new_mask;								\ 						while (!__ac_isempty(new_flags, i)) i = (i + (++step))& new_mask; \ 						__ac_set_isempty_false(new_flags, i);			\ 						if (i< h->n_buckets&& __ac_iseither(h->flags, i) == 0) {
comment|/* kick out the existing element */
value|\ 							{ khkey_t tmp = h->keys[i]; h->keys[i] = key; key = tmp; } \ 							if (kh_is_map) { khval_t tmp = h->vals[i]; h->vals[i] = val; val = tmp; } \ 							__ac_set_isdel_true(h->flags, i);
comment|/* mark it as deleted in the old hash table */
value|\ 						} else {
comment|/* write the element and jump out of the loop */
value|\ 							h->keys[i] = key;							\ 							if (kh_is_map) h->vals[i] = val;			\ 							break;										\ 						}												\ 					}													\ 				}														\ 			}															\ 			if (h->n_buckets> new_n_buckets) {
comment|/* shrink the hash table */
value|\ 				h->keys = (khkey_t*)krealloc((void *)h->keys, new_n_buckets * sizeof(khkey_t)); \ 				if (kh_is_map) h->vals = (khval_t*)krealloc((void *)h->vals, new_n_buckets * sizeof(khval_t)); \ 			}															\ 			kfree(h->flags);
comment|/* free the working space */
value|\ 			h->flags = new_flags;										\ 			h->n_buckets = new_n_buckets;								\ 			h->n_occupied = h->size;									\ 			h->upper_bound = (khint_t)(h->n_buckets * __ac_HASH_UPPER + 0.5); \ 		}																\ 		return 0;														\ 	}																	\ 	SCOPE khint_t kh_put_##name(kh_##name##_t *h, khkey_t key, int *ret) \ 	{																	\ 		khint_t x;														\ 		if (h->n_occupied>= h->upper_bound) {
comment|/* update the hash table */
value|\ 			if (h->n_buckets> (h->size<<1)) {							\ 				if (kh_resize_##name(h, h->n_buckets - 1)< 0) {
comment|/* clear "deleted" elements */
value|\ 					*ret = -1; return h->n_buckets;						\ 				}														\ 			} else if (kh_resize_##name(h, h->n_buckets + 1)< 0) {
comment|/* expand the hash table */
value|\ 				*ret = -1; return h->n_buckets;							\ 			}															\ 		}
comment|/* TODO: to implement automatically shrinking; resize() already support shrinking */
value|\ 		{																\ 			khint_t k, i, site, last, mask = h->n_buckets - 1, step = 0; \ 			x = site = h->n_buckets; k = __hash_func(key); i = k& mask; \ 			if (__ac_isempty(h->flags, i)) x = i;
comment|/* for speed up */
value|\ 			else {														\ 				last = i; \ 				while (!__ac_isempty(h->flags, i)&& (__ac_isdel(h->flags, i) || !__hash_equal(h->keys[i], key))) { \ 					if (__ac_isdel(h->flags, i)) site = i;				\ 					i = (i + (++step))& mask; \ 					if (i == last) { x = site; break; }					\ 				}														\ 				if (x == h->n_buckets) {								\ 					if (__ac_isempty(h->flags, i)&& site != h->n_buckets) x = site; \ 					else x = i;											\ 				}														\ 			}															\ 		}																\ 		if (__ac_isempty(h->flags, x)) {
comment|/* not present at all */
value|\ 			h->keys[x] = key;											\ 			__ac_set_isboth_false(h->flags, x);							\ 			++h->size; ++h->n_occupied;									\ 			*ret = 1;													\ 		} else if (__ac_isdel(h->flags, x)) {
comment|/* deleted */
value|\ 			h->keys[x] = key;											\ 			__ac_set_isboth_false(h->flags, x);							\ 			++h->size;													\ 			*ret = 2;													\ 		} else *ret = 0;
comment|/* Don't touch h->keys[x] if present and not deleted */
value|\ 		return x;														\ 	}																	\ 	SCOPE void kh_del_##name(kh_##name##_t *h, khint_t x)				\ 	{																	\ 		if (x != h->n_buckets&& !__ac_iseither(h->flags, x)) {			\ 			__ac_set_isdel_true(h->flags, x);							\ 			--h->size;													\ 		}																\ 	}
end_define

begin_define
define|#
directive|define
name|KHASH_DECLARE
parameter_list|(
name|name
parameter_list|,
name|khkey_t
parameter_list|,
name|khval_t
parameter_list|)
define|\
value|__KHASH_TYPE(name, khkey_t, khval_t) 								\ 	__KHASH_PROTOTYPES(name, khkey_t, khval_t)
end_define

begin_define
define|#
directive|define
name|KHASH_INIT2
parameter_list|(
name|name
parameter_list|,
name|SCOPE
parameter_list|,
name|khkey_t
parameter_list|,
name|khval_t
parameter_list|,
name|kh_is_map
parameter_list|,
name|__hash_func
parameter_list|,
name|__hash_equal
parameter_list|)
define|\
value|__KHASH_TYPE(name, khkey_t, khval_t) 								\ 	__KHASH_IMPL(name, SCOPE, khkey_t, khval_t, kh_is_map, __hash_func, __hash_equal)
end_define

begin_define
define|#
directive|define
name|KHASH_INIT
parameter_list|(
name|name
parameter_list|,
name|khkey_t
parameter_list|,
name|khval_t
parameter_list|,
name|kh_is_map
parameter_list|,
name|__hash_func
parameter_list|,
name|__hash_equal
parameter_list|)
define|\
value|KHASH_INIT2(name, static kh_inline, khkey_t, khval_t, kh_is_map, __hash_func, __hash_equal)
end_define

begin_comment
comment|/* --- BEGIN OF HASH FUNCTIONS --- */
end_comment

begin_comment
comment|/*! @function   @abstract     Integer hash function   @param  key   The integer [khint32_t]   @return       The hash value [khint_t]  */
end_comment

begin_define
define|#
directive|define
name|kh_int_hash_func
parameter_list|(
name|key
parameter_list|)
value|(khint32_t)(key)
end_define

begin_comment
comment|/*! @function   @abstract     Integer comparison function  */
end_comment

begin_define
define|#
directive|define
name|kh_int_hash_equal
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|((a) == (b))
end_define

begin_comment
comment|/*! @function   @abstract     64-bit integer hash function   @param  key   The integer [khint64_t]   @return       The hash value [khint_t]  */
end_comment

begin_define
define|#
directive|define
name|kh_int64_hash_func
parameter_list|(
name|key
parameter_list|)
value|(khint32_t)((key)>>33^(key)^(key)<<11)
end_define

begin_comment
comment|/*! @function   @abstract     64-bit integer comparison function  */
end_comment

begin_define
define|#
directive|define
name|kh_int64_hash_equal
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|((a) == (b))
end_define

begin_comment
comment|/*! @function   @abstract     const char* hash function   @param  s     Pointer to a null terminated string   @return       The hash value  */
end_comment

begin_function
specifier|static
name|kh_inline
name|khint_t
name|__ac_X31_hash_string
parameter_list|(
specifier|const
name|char
modifier|*
name|s
parameter_list|)
block|{
name|khint_t
name|h
init|=
operator|(
name|khint_t
operator|)
operator|*
name|s
decl_stmt|;
if|if
condition|(
name|h
condition|)
for|for
control|(
operator|++
name|s
init|;
operator|*
name|s
condition|;
operator|++
name|s
control|)
name|h
operator|=
operator|(
name|h
operator|<<
literal|5
operator|)
operator|-
name|h
operator|+
operator|(
name|khint_t
operator|)
operator|*
name|s
expr_stmt|;
return|return
name|h
return|;
block|}
end_function

begin_comment
comment|/*! @function   @abstract     Another interface to const char* hash function   @param  key   Pointer to a null terminated string [const char*]   @return       The hash value [khint_t]  */
end_comment

begin_define
define|#
directive|define
name|kh_str_hash_func
parameter_list|(
name|key
parameter_list|)
value|__ac_X31_hash_string(key)
end_define

begin_comment
comment|/*! @function   @abstract     Const char* comparison function  */
end_comment

begin_define
define|#
directive|define
name|kh_str_hash_equal
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|(strcmp(a, b) == 0)
end_define

begin_function
specifier|static
name|kh_inline
name|khint_t
name|__ac_Wang_hash
parameter_list|(
name|khint_t
name|key
parameter_list|)
block|{
name|key
operator|+=
operator|~
operator|(
name|key
operator|<<
literal|15
operator|)
expr_stmt|;
name|key
operator|^=
operator|(
name|key
operator|>>
literal|10
operator|)
expr_stmt|;
name|key
operator|+=
operator|(
name|key
operator|<<
literal|3
operator|)
expr_stmt|;
name|key
operator|^=
operator|(
name|key
operator|>>
literal|6
operator|)
expr_stmt|;
name|key
operator|+=
operator|~
operator|(
name|key
operator|<<
literal|11
operator|)
expr_stmt|;
name|key
operator|^=
operator|(
name|key
operator|>>
literal|16
operator|)
expr_stmt|;
return|return
name|key
return|;
block|}
end_function

begin_define
define|#
directive|define
name|kh_int_hash_func2
parameter_list|(
name|k
parameter_list|)
value|__ac_Wang_hash((khint_t)key)
end_define

begin_comment
comment|/* --- END OF HASH FUNCTIONS --- */
end_comment

begin_comment
comment|/* Other convenient macros... */
end_comment

begin_comment
comment|/*!   @abstract Type of the hash table.   @param  name  Name of the hash table [symbol]  */
end_comment

begin_define
define|#
directive|define
name|khash_t
parameter_list|(
name|name
parameter_list|)
value|kh_##name##_t
end_define

begin_comment
comment|/*! @function   @abstract     Initiate a hash table.   @param  name  Name of the hash table [symbol]   @return       Pointer to the hash table [khash_t(name)*]  */
end_comment

begin_define
define|#
directive|define
name|kh_init
parameter_list|(
name|name
parameter_list|)
value|kh_init_##name()
end_define

begin_comment
comment|/*! @function   @abstract     Destroy a hash table.   @param  name  Name of the hash table [symbol]   @param  h     Pointer to the hash table [khash_t(name)*]  */
end_comment

begin_define
define|#
directive|define
name|kh_destroy
parameter_list|(
name|name
parameter_list|,
name|h
parameter_list|)
value|kh_destroy_##name(h)
end_define

begin_comment
comment|/*! @function   @abstract     Reset a hash table without deallocating memory.   @param  name  Name of the hash table [symbol]   @param  h     Pointer to the hash table [khash_t(name)*]  */
end_comment

begin_define
define|#
directive|define
name|kh_clear
parameter_list|(
name|name
parameter_list|,
name|h
parameter_list|)
value|kh_clear_##name(h)
end_define

begin_comment
comment|/*! @function   @abstract     Resize a hash table.   @param  name  Name of the hash table [symbol]   @param  h     Pointer to the hash table [khash_t(name)*]   @param  s     New size [khint_t]  */
end_comment

begin_define
define|#
directive|define
name|kh_resize
parameter_list|(
name|name
parameter_list|,
name|h
parameter_list|,
name|s
parameter_list|)
value|kh_resize_##name(h, s)
end_define

begin_comment
comment|/*! @function   @abstract     Insert a key to the hash table.   @param  name  Name of the hash table [symbol]   @param  h     Pointer to the hash table [khash_t(name)*]   @param  k     Key [type of keys]   @param  r     Extra return code: -1 if the operation failed;                 0 if the key is present in the hash table;                 1 if the bucket is empty (never used); 2 if the element in 				the bucket has been deleted [int*]   @return       Iterator to the inserted element [khint_t]  */
end_comment

begin_define
define|#
directive|define
name|kh_put
parameter_list|(
name|name
parameter_list|,
name|h
parameter_list|,
name|k
parameter_list|,
name|r
parameter_list|)
value|kh_put_##name(h, k, r)
end_define

begin_comment
comment|/*! @function   @abstract     Retrieve a key from the hash table.   @param  name  Name of the hash table [symbol]   @param  h     Pointer to the hash table [khash_t(name)*]   @param  k     Key [type of keys]   @return       Iterator to the found element, or kh_end(h) if the element is absent [khint_t]  */
end_comment

begin_define
define|#
directive|define
name|kh_get
parameter_list|(
name|name
parameter_list|,
name|h
parameter_list|,
name|k
parameter_list|)
value|kh_get_##name(h, k)
end_define

begin_comment
comment|/*! @function   @abstract     Remove a key from the hash table.   @param  name  Name of the hash table [symbol]   @param  h     Pointer to the hash table [khash_t(name)*]   @param  k     Iterator to the element to be deleted [khint_t]  */
end_comment

begin_define
define|#
directive|define
name|kh_del
parameter_list|(
name|name
parameter_list|,
name|h
parameter_list|,
name|k
parameter_list|)
value|kh_del_##name(h, k)
end_define

begin_comment
comment|/*! @function   @abstract     Test whether a bucket contains data.   @param  h     Pointer to the hash table [khash_t(name)*]   @param  x     Iterator to the bucket [khint_t]   @return       1 if containing data; 0 otherwise [int]  */
end_comment

begin_define
define|#
directive|define
name|kh_exist
parameter_list|(
name|h
parameter_list|,
name|x
parameter_list|)
value|(!__ac_iseither((h)->flags, (x)))
end_define

begin_comment
comment|/*! @function   @abstract     Get key given an iterator   @param  h     Pointer to the hash table [khash_t(name)*]   @param  x     Iterator to the bucket [khint_t]   @return       Key [type of keys]  */
end_comment

begin_define
define|#
directive|define
name|kh_key
parameter_list|(
name|h
parameter_list|,
name|x
parameter_list|)
value|((h)->keys[x])
end_define

begin_comment
comment|/*! @function   @abstract     Get value given an iterator   @param  h     Pointer to the hash table [khash_t(name)*]   @param  x     Iterator to the bucket [khint_t]   @return       Value [type of values]   @discussion   For hash sets, calling this results in segfault.  */
end_comment

begin_define
define|#
directive|define
name|kh_val
parameter_list|(
name|h
parameter_list|,
name|x
parameter_list|)
value|((h)->vals[x])
end_define

begin_comment
comment|/*! @function   @abstract     Alias of kh_val()  */
end_comment

begin_define
define|#
directive|define
name|kh_value
parameter_list|(
name|h
parameter_list|,
name|x
parameter_list|)
value|((h)->vals[x])
end_define

begin_comment
comment|/*! @function   @abstract     Get the start iterator   @param  h     Pointer to the hash table [khash_t(name)*]   @return       The start iterator [khint_t]  */
end_comment

begin_define
define|#
directive|define
name|kh_begin
parameter_list|(
name|h
parameter_list|)
value|(khint_t)(0)
end_define

begin_comment
comment|/*! @function   @abstract     Get the end iterator   @param  h     Pointer to the hash table [khash_t(name)*]   @return       The end iterator [khint_t]  */
end_comment

begin_define
define|#
directive|define
name|kh_end
parameter_list|(
name|h
parameter_list|)
value|((h)->n_buckets)
end_define

begin_comment
comment|/*! @function   @abstract     Get the number of elements in the hash table   @param  h     Pointer to the hash table [khash_t(name)*]   @return       Number of elements in the hash table [khint_t]  */
end_comment

begin_define
define|#
directive|define
name|kh_size
parameter_list|(
name|h
parameter_list|)
value|((h)->size)
end_define

begin_comment
comment|/*! @function   @abstract     Get the number of buckets in the hash table   @param  h     Pointer to the hash table [khash_t(name)*]   @return       Number of buckets in the hash table [khint_t]  */
end_comment

begin_define
define|#
directive|define
name|kh_n_buckets
parameter_list|(
name|h
parameter_list|)
value|((h)->n_buckets)
end_define

begin_comment
comment|/*! @function   @abstract     Iterate over the entries in the hash table   @param  h     Pointer to the hash table [khash_t(name)*]   @param  kvar  Variable to which key will be assigned   @param  vvar  Variable to which value will be assigned   @param  code  Block of code to execute  */
end_comment

begin_define
define|#
directive|define
name|kh_foreach
parameter_list|(
name|h
parameter_list|,
name|kvar
parameter_list|,
name|vvar
parameter_list|,
name|code
parameter_list|)
value|{ khint_t __i;		\ 	for (__i = kh_begin(h); __i != kh_end(h); ++__i) {		\ 		if (!kh_exist(h,__i)) continue;						\ 		(kvar) = kh_key(h,__i);								\ 		(vvar) = kh_val(h,__i);								\ 		code;												\ 	} }
end_define

begin_comment
comment|/*! @function   @abstract     Iterate over the values in the hash table   @param  h     Pointer to the hash table [khash_t(name)*]   @param  vvar  Variable to which value will be assigned   @param  code  Block of code to execute  */
end_comment

begin_define
define|#
directive|define
name|kh_foreach_value
parameter_list|(
name|h
parameter_list|,
name|vvar
parameter_list|,
name|code
parameter_list|)
value|{ khint_t __i;		\ 	for (__i = kh_begin(h); __i != kh_end(h); ++__i) {		\ 		if (!kh_exist(h,__i)) continue;						\ 		(vvar) = kh_val(h,__i);								\ 		code;												\ 	} }
end_define

begin_comment
comment|/* More conenient interfaces */
end_comment

begin_comment
comment|/*! @function   @abstract     Instantiate a hash set containing integer keys   @param  name  Name of the hash table [symbol]  */
end_comment

begin_define
define|#
directive|define
name|KHASH_SET_INIT_INT
parameter_list|(
name|name
parameter_list|)
define|\
value|KHASH_INIT(name, khint32_t, char, 0, kh_int_hash_func, kh_int_hash_equal)
end_define

begin_comment
comment|/*! @function   @abstract     Instantiate a hash map containing integer keys   @param  name  Name of the hash table [symbol]   @param  khval_t  Type of values [type]  */
end_comment

begin_define
define|#
directive|define
name|KHASH_MAP_INIT_INT
parameter_list|(
name|name
parameter_list|,
name|khval_t
parameter_list|)
define|\
value|KHASH_INIT(name, khint32_t, khval_t, 1, kh_int_hash_func, kh_int_hash_equal)
end_define

begin_comment
comment|/*! @function   @abstract     Instantiate a hash map containing 64-bit integer keys   @param  name  Name of the hash table [symbol]  */
end_comment

begin_define
define|#
directive|define
name|KHASH_SET_INIT_INT64
parameter_list|(
name|name
parameter_list|)
define|\
value|KHASH_INIT(name, khint64_t, char, 0, kh_int64_hash_func, kh_int64_hash_equal)
end_define

begin_comment
comment|/*! @function   @abstract     Instantiate a hash map containing 64-bit integer keys   @param  name  Name of the hash table [symbol]   @param  khval_t  Type of values [type]  */
end_comment

begin_define
define|#
directive|define
name|KHASH_MAP_INIT_INT64
parameter_list|(
name|name
parameter_list|,
name|khval_t
parameter_list|)
define|\
value|KHASH_INIT(name, khint64_t, khval_t, 1, kh_int64_hash_func, kh_int64_hash_equal)
end_define

begin_typedef
typedef|typedef
specifier|const
name|char
modifier|*
name|kh_cstr_t
typedef|;
end_typedef

begin_comment
comment|/*! @function   @abstract     Instantiate a hash map containing const char* keys   @param  name  Name of the hash table [symbol]  */
end_comment

begin_define
define|#
directive|define
name|KHASH_SET_INIT_STR
parameter_list|(
name|name
parameter_list|)
define|\
value|KHASH_INIT(name, kh_cstr_t, char, 0, kh_str_hash_func, kh_str_hash_equal)
end_define

begin_comment
comment|/*! @function   @abstract     Instantiate a hash map containing const char* keys   @param  name  Name of the hash table [symbol]   @param  khval_t  Type of values [type]  */
end_comment

begin_define
define|#
directive|define
name|KHASH_MAP_INIT_STR
parameter_list|(
name|name
parameter_list|,
name|khval_t
parameter_list|)
define|\
value|KHASH_INIT(name, kh_cstr_t, khval_t, 1, kh_str_hash_func, kh_str_hash_equal)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __AC_KHASH_H */
end_comment

end_unit

