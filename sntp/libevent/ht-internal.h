begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Copyright 2002 Christopher Clark */
end_comment

begin_comment
comment|/* Copyright 2005-2012 Nick Mathewson */
end_comment

begin_comment
comment|/* Copyright 2009-2012 Niels Provos and Nick Mathewson */
end_comment

begin_comment
comment|/* See license at end. */
end_comment

begin_comment
comment|/* Based on ideas by Christopher Clark and interfaces from Niels Provos. */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|HT_INTERNAL_H_INCLUDED_
end_ifndef

begin_define
define|#
directive|define
name|HT_INTERNAL_H_INCLUDED_
end_define

begin_define
define|#
directive|define
name|HT_HEAD
parameter_list|(
name|name
parameter_list|,
name|type
parameter_list|)
define|\
value|struct name {                                                         \
comment|/* The hash table itself. */
value|\     struct type **hth_table;                                            \
comment|/* How long is the hash table? */
value|\     unsigned hth_table_length;                                          \
comment|/* How many elements does the table contain? */
value|\     unsigned hth_n_entries;                                             \
comment|/* How many elements will we allow in the table before resizing it? */
value|\     unsigned hth_load_limit;                                            \
comment|/* Position of hth_table_length in the primes table. */
value|\     int hth_prime_idx;                                                  \   }
end_define

begin_define
define|#
directive|define
name|HT_INITIALIZER
parameter_list|()
define|\
value|{ NULL, 0, 0, 0, -1 }
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|HT_NO_CACHE_HASH_VALUES
end_ifdef

begin_define
define|#
directive|define
name|HT_ENTRY
parameter_list|(
name|type
parameter_list|)
define|\
value|struct {                                      \     struct type *hte_next;                      \   }
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|HT_ENTRY
parameter_list|(
name|type
parameter_list|)
define|\
value|struct {                                      \     struct type *hte_next;                      \     unsigned hte_hash;                          \   }
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|HT_EMPTY
parameter_list|(
name|head
parameter_list|)
define|\
value|((head)->hth_n_entries == 0)
end_define

begin_comment
comment|/* How many elements in 'head'? */
end_comment

begin_define
define|#
directive|define
name|HT_SIZE
parameter_list|(
name|head
parameter_list|)
define|\
value|((head)->hth_n_entries)
end_define

begin_comment
comment|/* Return memory usage for a hashtable (not counting the entries themselves) */
end_comment

begin_define
define|#
directive|define
name|HT_MEM_USAGE
parameter_list|(
name|head
parameter_list|)
define|\
value|(sizeof(*head) + (head)->hth_table_length * sizeof(void*))
end_define

begin_define
define|#
directive|define
name|HT_FIND
parameter_list|(
name|name
parameter_list|,
name|head
parameter_list|,
name|elm
parameter_list|)
value|name##_HT_FIND((head), (elm))
end_define

begin_define
define|#
directive|define
name|HT_INSERT
parameter_list|(
name|name
parameter_list|,
name|head
parameter_list|,
name|elm
parameter_list|)
value|name##_HT_INSERT((head), (elm))
end_define

begin_define
define|#
directive|define
name|HT_REPLACE
parameter_list|(
name|name
parameter_list|,
name|head
parameter_list|,
name|elm
parameter_list|)
value|name##_HT_REPLACE((head), (elm))
end_define

begin_define
define|#
directive|define
name|HT_REMOVE
parameter_list|(
name|name
parameter_list|,
name|head
parameter_list|,
name|elm
parameter_list|)
value|name##_HT_REMOVE((head), (elm))
end_define

begin_define
define|#
directive|define
name|HT_START
parameter_list|(
name|name
parameter_list|,
name|head
parameter_list|)
value|name##_HT_START(head)
end_define

begin_define
define|#
directive|define
name|HT_NEXT
parameter_list|(
name|name
parameter_list|,
name|head
parameter_list|,
name|elm
parameter_list|)
value|name##_HT_NEXT((head), (elm))
end_define

begin_define
define|#
directive|define
name|HT_NEXT_RMV
parameter_list|(
name|name
parameter_list|,
name|head
parameter_list|,
name|elm
parameter_list|)
value|name##_HT_NEXT_RMV((head), (elm))
end_define

begin_define
define|#
directive|define
name|HT_CLEAR
parameter_list|(
name|name
parameter_list|,
name|head
parameter_list|)
value|name##_HT_CLEAR(head)
end_define

begin_define
define|#
directive|define
name|HT_INIT
parameter_list|(
name|name
parameter_list|,
name|head
parameter_list|)
value|name##_HT_INIT(head)
end_define

begin_comment
comment|/* Helper: */
end_comment

begin_function
specifier|static
specifier|inline
name|unsigned
name|ht_improve_hash_
parameter_list|(
name|unsigned
name|h
parameter_list|)
block|{
comment|/* Aim to protect against poor hash functions by adding logic here    * - logic taken from java 1.4 hashtable source */
name|h
operator|+=
operator|~
operator|(
name|h
operator|<<
literal|9
operator|)
expr_stmt|;
name|h
operator|^=
operator|(
operator|(
name|h
operator|>>
literal|14
operator|)
operator||
operator|(
name|h
operator|<<
literal|18
operator|)
operator|)
expr_stmt|;
comment|/*>>> */
name|h
operator|+=
operator|(
name|h
operator|<<
literal|4
operator|)
expr_stmt|;
name|h
operator|^=
operator|(
operator|(
name|h
operator|>>
literal|10
operator|)
operator||
operator|(
name|h
operator|<<
literal|22
operator|)
operator|)
expr_stmt|;
comment|/*>>> */
return|return
name|h
return|;
block|}
end_function

begin_if
if|#
directive|if
literal|0
end_if

begin_comment
comment|/** Basic string hash function, from Java standard String.hashCode(). */
end_comment

begin_comment
unit|static inline unsigned ht_string_hash_(const char *s) {   unsigned h = 0;   int m = 1;   while (*s) {     h += ((signed char)*s++)*m;     m = (m<<5)-1;
comment|/* m *= 31 */
end_comment

begin_endif
unit|}   return h; }
endif|#
directive|endif
end_endif

begin_comment
comment|/** Basic string hash function, from Python's str.__hash__() */
end_comment

begin_function
specifier|static
specifier|inline
name|unsigned
name|ht_string_hash_
parameter_list|(
specifier|const
name|char
modifier|*
name|s
parameter_list|)
block|{
name|unsigned
name|h
decl_stmt|;
specifier|const
name|unsigned
name|char
modifier|*
name|cp
init|=
operator|(
specifier|const
name|unsigned
name|char
operator|*
operator|)
name|s
decl_stmt|;
name|h
operator|=
operator|*
name|cp
operator|<<
literal|7
expr_stmt|;
while|while
condition|(
operator|*
name|cp
condition|)
block|{
name|h
operator|=
operator|(
literal|1000003
operator|*
name|h
operator|)
operator|^
operator|*
name|cp
operator|++
expr_stmt|;
block|}
comment|/* This conversion truncates the length of the string, but that's ok. */
name|h
operator|^=
call|(
name|unsigned
call|)
argument_list|(
name|cp
operator|-
operator|(
specifier|const
name|unsigned
name|char
operator|*
operator|)
name|s
argument_list|)
expr_stmt|;
return|return
name|h
return|;
block|}
end_function

begin_ifndef
ifndef|#
directive|ifndef
name|HT_NO_CACHE_HASH_VALUES
end_ifndef

begin_define
define|#
directive|define
name|HT_SET_HASH_
parameter_list|(
name|elm
parameter_list|,
name|field
parameter_list|,
name|hashfn
parameter_list|)
define|\
value|do { (elm)->field.hte_hash = hashfn(elm); } while (0)
end_define

begin_define
define|#
directive|define
name|HT_SET_HASHVAL_
parameter_list|(
name|elm
parameter_list|,
name|field
parameter_list|,
name|val
parameter_list|)
define|\
value|do { (elm)->field.hte_hash = (val); } while (0)
end_define

begin_define
define|#
directive|define
name|HT_ELT_HASH_
parameter_list|(
name|elm
parameter_list|,
name|field
parameter_list|,
name|hashfn
parameter_list|)
define|\
value|((elm)->field.hte_hash)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|HT_SET_HASH_
parameter_list|(
name|elm
parameter_list|,
name|field
parameter_list|,
name|hashfn
parameter_list|)
define|\
value|((void)0)
end_define

begin_define
define|#
directive|define
name|HT_ELT_HASH_
parameter_list|(
name|elm
parameter_list|,
name|field
parameter_list|,
name|hashfn
parameter_list|)
define|\
value|(hashfn(elm))
end_define

begin_define
define|#
directive|define
name|HT_SET_HASHVAL_
parameter_list|(
name|elm
parameter_list|,
name|field
parameter_list|,
name|val
parameter_list|)
define|\
value|((void)0)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Helper: alias for the bucket containing 'elm'. */
end_comment

begin_define
define|#
directive|define
name|HT_BUCKET_
parameter_list|(
name|head
parameter_list|,
name|field
parameter_list|,
name|elm
parameter_list|,
name|hashfn
parameter_list|)
define|\
value|((head)->hth_table[HT_ELT_HASH_(elm,field,hashfn) % head->hth_table_length])
end_define

begin_define
define|#
directive|define
name|HT_FOREACH
parameter_list|(
name|x
parameter_list|,
name|name
parameter_list|,
name|head
parameter_list|)
define|\
value|for ((x) = HT_START(name, head);                \        (x) != NULL;                               \        (x) = HT_NEXT(name, head, x))
end_define

begin_define
define|#
directive|define
name|HT_PROTOTYPE
parameter_list|(
name|name
parameter_list|,
name|type
parameter_list|,
name|field
parameter_list|,
name|hashfn
parameter_list|,
name|eqfn
parameter_list|)
define|\
value|int name##_HT_GROW(struct name *ht, unsigned min_capacity);           \   void name##_HT_CLEAR(struct name *ht);                                \   int name##_HT_REP_IS_BAD_(const struct name *ht);			\   static inline void                                                    \   name##_HT_INIT(struct name *head) {                                   \     head->hth_table_length = 0;                                         \     head->hth_table = NULL;                                             \     head->hth_n_entries = 0;                                            \     head->hth_load_limit = 0;                                           \     head->hth_prime_idx = -1;                                           \   }                                                                     \
comment|/* Helper: returns a pointer to the right location in the table       \    * 'head' to find or insert the element 'elm'. */
value|\   static inline struct type **                                          \   name##_HT_FIND_P_(struct name *head, struct type *elm)		\   {                                                                     \     struct type **p;                                                    \     if (!head->hth_table)                                               \       return NULL;                                                      \     p =&HT_BUCKET_(head, field, elm, hashfn);				\     while (*p) {                                                        \       if (eqfn(*p, elm))                                                \         return p;                                                       \       p =&(*p)->field.hte_next;                                        \     }                                                                   \     return p;                                                           \   }                                                                     \
comment|/* Return a pointer to the element in the table 'head' matching 'elm', \    * or NULL if no such element exists */
value|\   static inline struct type *                                           \   name##_HT_FIND(const struct name *head, struct type *elm)             \   {                                                                     \     struct type **p;                                                    \     struct name *h = (struct name *) head;                              \     HT_SET_HASH_(elm, field, hashfn);                                   \     p = name##_HT_FIND_P_(h, elm);					\     return p ? *p : NULL;                                               \   }                                                                     \
comment|/* Insert the element 'elm' into the table 'head'.  Do not call this  \    * function if the table might already contain a matching element. */
value|\   static inline void                                                    \   name##_HT_INSERT(struct name *head, struct type *elm)                 \   {                                                                     \     struct type **p;                                                    \     if (!head->hth_table || head->hth_n_entries>= head->hth_load_limit) \       name##_HT_GROW(head, head->hth_n_entries+1);                      \     ++head->hth_n_entries;                                              \     HT_SET_HASH_(elm, field, hashfn);                                   \     p =&HT_BUCKET_(head, field, elm, hashfn);				\     elm->field.hte_next = *p;                                           \     *p = elm;                                                           \   }                                                                     \
comment|/* Insert the element 'elm' into the table 'head'. If there already   \    * a matching element in the table, replace that element and return   \    * it. */
value|\   static inline struct type *                                           \   name##_HT_REPLACE(struct name *head, struct type *elm)                \   {                                                                     \     struct type **p, *r;                                                \     if (!head->hth_table || head->hth_n_entries>= head->hth_load_limit) \       name##_HT_GROW(head, head->hth_n_entries+1);                      \     HT_SET_HASH_(elm, field, hashfn);                                   \     p = name##_HT_FIND_P_(head, elm);					\     r = *p;                                                             \     *p = elm;                                                           \     if (r&& (r!=elm)) {                                                \       elm->field.hte_next = r->field.hte_next;                          \       r->field.hte_next = NULL;                                         \       return r;                                                         \     } else {                                                            \       ++head->hth_n_entries;                                            \       return NULL;                                                      \     }                                                                   \   }                                                                     \
comment|/* Remove any element matching 'elm' from the table 'head'.  If such  \    * an element is found, return it; otherwise return NULL. */
value|\   static inline struct type *                                           \   name##_HT_REMOVE(struct name *head, struct type *elm)                 \   {                                                                     \     struct type **p, *r;                                                \     HT_SET_HASH_(elm, field, hashfn);                                   \     p = name##_HT_FIND_P_(head,elm);					\     if (!p || !*p)                                                      \       return NULL;                                                      \     r = *p;                                                             \     *p = r->field.hte_next;                                             \     r->field.hte_next = NULL;                                           \     --head->hth_n_entries;                                              \     return r;                                                           \   }                                                                     \
comment|/* Invoke the function 'fn' on every element of the table 'head',     \    * using 'data' as its second argument.  If the function returns      \    * nonzero, remove the most recently examined element before invoking \    * the function again. */
value|\   static inline void                                                    \   name##_HT_FOREACH_FN(struct name *head,                               \                        int (*fn)(struct type *, void *),                \                        void *data)                                      \   {                                                                     \     unsigned idx;                                                       \     struct type **p, **nextp, *next;                                    \     if (!head->hth_table)                                               \       return;                                                           \     for (idx=0; idx< head->hth_table_length; ++idx) {                  \       p =&head->hth_table[idx];                                        \       while (*p) {                                                      \         nextp =&(*p)->field.hte_next;                                  \         next = *nextp;                                                  \         if (fn(*p, data)) {                                             \           --head->hth_n_entries;                                        \           *p = next;                                                    \         } else {                                                        \           p = nextp;                                                    \         }                                                               \       }                                                                 \     }                                                                   \   }                                                                     \
comment|/* Return a pointer to the first element in the table 'head', under   \    * an arbitrary order.  This order is stable under remove operations, \    * but not under others. If the table is empty, return NULL. */
value|\   static inline struct type **                                          \   name##_HT_START(struct name *head)                                    \   {                                                                     \     unsigned b = 0;                                                     \     while (b< head->hth_table_length) {                                \       if (head->hth_table[b])                                           \         return&head->hth_table[b];                                     \       ++b;                                                              \     }                                                                   \     return NULL;                                                        \   }                                                                     \
comment|/* Return the next element in 'head' after 'elm', under the arbitrary \    * order used by HT_START.  If there are no more elements, return     \    * NULL.  If 'elm' is to be removed from the table, you must call     \    * this function for the next value before you remove it.             \    */
value|\   static inline struct type **                                          \   name##_HT_NEXT(struct name *head, struct type **elm)                  \   {                                                                     \     if ((*elm)->field.hte_next) {                                       \       return&(*elm)->field.hte_next;                                   \     } else {                                                            \       unsigned b = (HT_ELT_HASH_(*elm, field, hashfn) % head->hth_table_length)+1; \       while (b< head->hth_table_length) {                              \         if (head->hth_table[b])                                         \           return&head->hth_table[b];                                   \         ++b;                                                            \       }                                                                 \       return NULL;                                                      \     }                                                                   \   }                                                                     \   static inline struct type **                                          \   name##_HT_NEXT_RMV(struct name *head, struct type **elm)              \   {                                                                     \     unsigned h = HT_ELT_HASH_(*elm, field, hashfn);		        \     *elm = (*elm)->field.hte_next;                                      \     --head->hth_n_entries;                                              \     if (*elm) {                                                         \       return elm;                                                       \     } else {                                                            \       unsigned b = (h % head->hth_table_length)+1;                      \       while (b< head->hth_table_length) {                              \         if (head->hth_table[b])                                         \           return&head->hth_table[b];                                   \         ++b;                                                            \       }                                                                 \       return NULL;                                                      \     }                                                                   \   }
end_define

begin_define
define|#
directive|define
name|HT_GENERATE
parameter_list|(
name|name
parameter_list|,
name|type
parameter_list|,
name|field
parameter_list|,
name|hashfn
parameter_list|,
name|eqfn
parameter_list|,
name|load
parameter_list|,
name|mallocfn
parameter_list|,    \
name|reallocfn
parameter_list|,
name|freefn
parameter_list|)
define|\
value|static unsigned name##_PRIMES[] = {                                   \     53, 97, 193, 389,                                                   \     769, 1543, 3079, 6151,                                              \     12289, 24593, 49157, 98317,                                         \     196613, 393241, 786433, 1572869,                                    \     3145739, 6291469, 12582917, 25165843,                               \     50331653, 100663319, 201326611, 402653189,                          \     805306457, 1610612741                                               \   };                                                                    \   static unsigned name##_N_PRIMES =                                     \     (unsigned)(sizeof(name##_PRIMES)/sizeof(name##_PRIMES[0]));         \
comment|/* Expand the internal table of 'head' until it is large enough to    \    * hold 'size' elements.  Return 0 on success, -1 on allocation       \    * failure. */
value|\   int                                                                   \   name##_HT_GROW(struct name *head, unsigned size)                      \   {                                                                     \     unsigned new_len, new_load_limit;                                   \     int prime_idx;                                                      \     struct type **new_table;                                            \     if (head->hth_prime_idx == (int)name##_N_PRIMES - 1)                \       return 0;                                                         \     if (head->hth_load_limit> size)                                    \       return 0;                                                         \     prime_idx = head->hth_prime_idx;                                    \     do {                                                                \       new_len = name##_PRIMES[++prime_idx];                             \       new_load_limit = (unsigned)(load*new_len);                        \     } while (new_load_limit<= size&&                                  \              prime_idx< (int)name##_N_PRIMES);                         \     if ((new_table = mallocfn(new_len*sizeof(struct type*)))) {         \       unsigned b;                                                       \       memset(new_table, 0, new_len*sizeof(struct type*));               \       for (b = 0; b< head->hth_table_length; ++b) {                    \         struct type *elm, *next;                                        \         unsigned b2;                                                    \         elm = head->hth_table[b];                                       \         while (elm) {                                                   \           next = elm->field.hte_next;                                   \           b2 = HT_ELT_HASH_(elm, field, hashfn) % new_len;              \           elm->field.hte_next = new_table[b2];                          \           new_table[b2] = elm;                                          \           elm = next;                                                   \         }                                                               \       }                                                                 \       if (head->hth_table)                                              \         freefn(head->hth_table);                                        \       head->hth_table = new_table;                                      \     } else {                                                            \       unsigned b, b2;                                                   \       new_table = reallocfn(head->hth_table, new_len*sizeof(struct type*)); \       if (!new_table) return -1;                                        \       memset(new_table + head->hth_table_length, 0,                     \              (new_len - head->hth_table_length)*sizeof(struct type*));  \       for (b=0; b< head->hth_table_length; ++b) {                      \         struct type *e, **pE;                                           \         for (pE =&new_table[b], e = *pE; e != NULL; e = *pE) {         \           b2 = HT_ELT_HASH_(e, field, hashfn) % new_len;                \           if (b2 == b) {                                                \             pE =&e->field.hte_next;                                    \           } else {                                                      \             *pE = e->field.hte_next;                                    \             e->field.hte_next = new_table[b2];                          \             new_table[b2] = e;                                          \           }                                                             \         }                                                               \       }                                                                 \       head->hth_table = new_table;                                      \     }                                                                   \     head->hth_table_length = new_len;                                   \     head->hth_prime_idx = prime_idx;                                    \     head->hth_load_limit = new_load_limit;                              \     return 0;                                                           \   }                                                                     \
comment|/* Free all storage held by 'head'.  Does not free 'head' itself, or  \    * individual elements. */
value|\   void                                                                  \   name##_HT_CLEAR(struct name *head)                                    \   {                                                                     \     if (head->hth_table)                                                \       freefn(head->hth_table);                                          \     head->hth_table_length = 0;                                         \     name##_HT_INIT(head);                                               \   }                                                                     \
comment|/* Debugging helper: return false iff the representation of 'head' is \    * internally consistent. */
value|\   int                                                                   \   name##_HT_REP_IS_BAD_(const struct name *head)			\   {                                                                     \     unsigned n, i;                                                      \     struct type *elm;                                                   \     if (!head->hth_table_length) {                                      \       if (!head->hth_table&& !head->hth_n_entries&&                   \           !head->hth_load_limit&& head->hth_prime_idx == -1)           \         return 0;                                                       \       else                                                              \         return 1;                                                       \     }                                                                   \     if (!head->hth_table || head->hth_prime_idx< 0 ||                  \         !head->hth_load_limit)                                          \       return 2;                                                         \     if (head->hth_n_entries> head->hth_load_limit)                     \       return 3;                                                         \     if (head->hth_table_length != name##_PRIMES[head->hth_prime_idx])   \       return 4;                                                         \     if (head->hth_load_limit != (unsigned)(load*head->hth_table_length)) \       return 5;                                                         \     for (n = i = 0; i< head->hth_table_length; ++i) {                  \       for (elm = head->hth_table[i]; elm; elm = elm->field.hte_next) {  \         if (HT_ELT_HASH_(elm, field, hashfn) != hashfn(elm))	        \           return 1000 + i;                                              \         if ((HT_ELT_HASH_(elm, field, hashfn) % head->hth_table_length) != i) \           return 10000 + i;                                             \         ++n;                                                            \       }                                                                 \     }                                                                   \     if (n != head->hth_n_entries)                                       \       return 6;                                                         \     return 0;                                                           \   }
end_define

begin_comment
comment|/** Implements an over-optimized "find and insert if absent" block;  * not meant for direct usage by typical code, or usage outside the critical  * path.*/
end_comment

begin_define
define|#
directive|define
name|HT_FIND_OR_INSERT_
parameter_list|(
name|name
parameter_list|,
name|field
parameter_list|,
name|hashfn
parameter_list|,
name|head
parameter_list|,
name|eltype
parameter_list|,
name|elm
parameter_list|,
name|var
parameter_list|,
name|y
parameter_list|,
name|n
parameter_list|)
define|\
value|{                                                                     \     struct name *var##_head_ = head;                                    \     struct eltype **var;                                                \     if (!var##_head_->hth_table ||                                      \         var##_head_->hth_n_entries>= var##_head_->hth_load_limit)      \       name##_HT_GROW(var##_head_, var##_head_->hth_n_entries+1);        \     HT_SET_HASH_((elm), field, hashfn);                                 \     var = name##_HT_FIND_P_(var##_head_, (elm));                        \     if (*var) {                                                         \       y;                                                                \     } else {                                                            \       n;                                                                \     }                                                                   \   }
end_define

begin_define
define|#
directive|define
name|HT_FOI_INSERT_
parameter_list|(
name|field
parameter_list|,
name|head
parameter_list|,
name|elm
parameter_list|,
name|newent
parameter_list|,
name|var
parameter_list|)
define|\
value|{                                                         \     HT_SET_HASHVAL_(newent, field, (elm)->field.hte_hash);  \     newent->field.hte_next = NULL;                          \     *var = newent;                                          \     ++((head)->hth_n_entries);                              \   }
end_define

begin_comment
comment|/*  * Copyright 2005, Nick Mathewson.  Implementation logic is adapted from code  * by Christopher Clark, retrofit to allow drop-in memory management, and to  * use the same interface as Niels Provos's tree.h.  This is probably still  * a derived work, so the original license below still applies.  *  * Copyright (c) 2002, Christopher Clark  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  *  * * Redistributions of source code must retain the above copyright  * notice, this list of conditions and the following disclaimer.  *  * * Redistributions in binary form must reproduce the above copyright  * notice, this list of conditions and the following disclaimer in the  * documentation and/or other materials provided with the distribution.  *  * * Neither the name of the original author; nor the names of any contributors  * may be used to endorse or promote products derived from this software  * without specific prior written permission.  *  *  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS  * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT  * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR  * A PARTICULAR PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL THE COPYRIGHT OWNER  * OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,  * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,  * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR  * PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF  * LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING  * NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS  * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE. */
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

