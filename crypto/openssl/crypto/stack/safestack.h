begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* ====================================================================  * Copyright (c) 1999 The OpenSSL Project.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  *  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.   *  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in  *    the documentation and/or other materials provided with the  *    distribution.  *  * 3. All advertising materials mentioning features or use of this  *    software must display the following acknowledgment:  *    "This product includes software developed by the OpenSSL Project  *    for use in the OpenSSL Toolkit. (http://www.openssl.org/)"  *  * 4. The names "OpenSSL Toolkit" and "OpenSSL Project" must not be used to  *    endorse or promote products derived from this software without  *    prior written permission. For written permission, please contact  *    openssl-core@openssl.org.  *  * 5. Products derived from this software may not be called "OpenSSL"  *    nor may "OpenSSL" appear in their names without prior written  *    permission of the OpenSSL Project.  *  * 6. Redistributions of any form whatsoever must retain the following  *    acknowledgment:  *    "This product includes software developed by the OpenSSL Project  *    for use in the OpenSSL Toolkit (http://www.openssl.org/)"  *  * THIS SOFTWARE IS PROVIDED BY THE OpenSSL PROJECT ``AS IS'' AND ANY  * EXPRESSED OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR  * PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL THE OpenSSL PROJECT OR  * ITS CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,  * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;  * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,  * STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)  * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED  * OF THE POSSIBILITY OF SUCH DAMAGE.  * ====================================================================  *  * This product includes cryptographic software written by Eric Young  * (eay@cryptsoft.com).  This product includes software written by Tim  * Hudson (tjh@cryptsoft.com).  *  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|HEADER_SAFESTACK_H
end_ifndef

begin_define
define|#
directive|define
name|HEADER_SAFESTACK_H
end_define

begin_include
include|#
directive|include
file|<openssl/stack.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|DEBUG_SAFESTACK
end_ifdef

begin_define
define|#
directive|define
name|STACK_OF
parameter_list|(
name|type
parameter_list|)
value|struct stack_st_##type
end_define

begin_define
define|#
directive|define
name|PREDECLARE_STACK_OF
parameter_list|(
name|type
parameter_list|)
value|STACK_OF(type);
end_define

begin_define
define|#
directive|define
name|DECLARE_STACK_OF
parameter_list|(
name|type
parameter_list|)
define|\
value|STACK_OF(type) \     { \     STACK stack; \     };
end_define

begin_define
define|#
directive|define
name|IMPLEMENT_STACK_OF
parameter_list|(
name|type
parameter_list|)
end_define

begin_comment
comment|/* nada (obsolete in new safestack approach)*/
end_comment

begin_comment
comment|/* SKM_sk_... stack macros are internal to safestack.h:  * never use them directly, use sk_<type>_... instead */
end_comment

begin_define
define|#
directive|define
name|SKM_sk_new
parameter_list|(
name|type
parameter_list|,
name|cmp
parameter_list|)
define|\
value|((STACK_OF(type) * (*)(int (*)(const type * const *, const type * const *)))sk_new)(cmp)
end_define

begin_define
define|#
directive|define
name|SKM_sk_new_null
parameter_list|(
name|type
parameter_list|)
define|\
value|((STACK_OF(type) * (*)(void))sk_new_null)()
end_define

begin_define
define|#
directive|define
name|SKM_sk_free
parameter_list|(
name|type
parameter_list|,
name|st
parameter_list|)
define|\
value|((void (*)(STACK_OF(type) *))sk_free)(st)
end_define

begin_define
define|#
directive|define
name|SKM_sk_num
parameter_list|(
name|type
parameter_list|,
name|st
parameter_list|)
define|\
value|((int (*)(const STACK_OF(type) *))sk_num)(st)
end_define

begin_define
define|#
directive|define
name|SKM_sk_value
parameter_list|(
name|type
parameter_list|,
name|st
parameter_list|,
name|i
parameter_list|)
define|\
value|((type * (*)(const STACK_OF(type) *, int))sk_value)(st, i)
end_define

begin_define
define|#
directive|define
name|SKM_sk_set
parameter_list|(
name|type
parameter_list|,
name|st
parameter_list|,
name|i
parameter_list|,
name|val
parameter_list|)
define|\
value|((type * (*)(STACK_OF(type) *, int, type *))sk_set)(st, i, val)
end_define

begin_define
define|#
directive|define
name|SKM_sk_zero
parameter_list|(
name|type
parameter_list|,
name|st
parameter_list|)
define|\
value|((void (*)(STACK_OF(type) *))sk_zero)(st)
end_define

begin_define
define|#
directive|define
name|SKM_sk_push
parameter_list|(
name|type
parameter_list|,
name|st
parameter_list|,
name|val
parameter_list|)
define|\
value|((int (*)(STACK_OF(type) *, type *))sk_push)(st, val)
end_define

begin_define
define|#
directive|define
name|SKM_sk_unshift
parameter_list|(
name|type
parameter_list|,
name|st
parameter_list|,
name|val
parameter_list|)
define|\
value|((int (*)(STACK_OF(type) *, type *))sk_unshift)(st, val)
end_define

begin_define
define|#
directive|define
name|SKM_sk_find
parameter_list|(
name|type
parameter_list|,
name|st
parameter_list|,
name|val
parameter_list|)
define|\
value|((int (*)(STACK_OF(type) *, type *))sk_find)(st, val)
end_define

begin_define
define|#
directive|define
name|SKM_sk_delete
parameter_list|(
name|type
parameter_list|,
name|st
parameter_list|,
name|i
parameter_list|)
define|\
value|((type * (*)(STACK_OF(type) *, int))sk_delete)(st, i)
end_define

begin_define
define|#
directive|define
name|SKM_sk_delete_ptr
parameter_list|(
name|type
parameter_list|,
name|st
parameter_list|,
name|ptr
parameter_list|)
define|\
value|((type * (*)(STACK_OF(type) *, type *))sk_delete_ptr)(st, ptr)
end_define

begin_define
define|#
directive|define
name|SKM_sk_insert
parameter_list|(
name|type
parameter_list|,
name|st
parameter_list|,
name|val
parameter_list|,
name|i
parameter_list|)
define|\
value|((int (*)(STACK_OF(type) *, type *, int))sk_insert)(st, val, i)
end_define

begin_define
define|#
directive|define
name|SKM_sk_set_cmp_func
parameter_list|(
name|type
parameter_list|,
name|st
parameter_list|,
name|cmp
parameter_list|)
define|\
value|((int (*(*)(STACK_OF(type) *, int (*)(const type * const *, const type * const *))) \ 	  (const type * const *, const type * const *))sk_set_cmp_func)\ 	(st, cmp)
end_define

begin_define
define|#
directive|define
name|SKM_sk_dup
parameter_list|(
name|type
parameter_list|,
name|st
parameter_list|)
define|\
value|((STACK_OF(type) *(*)(STACK_OF(type) *))sk_dup)(st)
end_define

begin_define
define|#
directive|define
name|SKM_sk_pop_free
parameter_list|(
name|type
parameter_list|,
name|st
parameter_list|,
name|free_func
parameter_list|)
define|\
value|((void (*)(STACK_OF(type) *, void (*)(type *)))sk_pop_free)\ 	(st, free_func)
end_define

begin_define
define|#
directive|define
name|SKM_sk_shift
parameter_list|(
name|type
parameter_list|,
name|st
parameter_list|)
define|\
value|((type * (*)(STACK_OF(type) *))sk_shift)(st)
end_define

begin_define
define|#
directive|define
name|SKM_sk_pop
parameter_list|(
name|type
parameter_list|,
name|st
parameter_list|)
define|\
value|((type * (*)(STACK_OF(type) *))sk_pop)(st)
end_define

begin_define
define|#
directive|define
name|SKM_sk_sort
parameter_list|(
name|type
parameter_list|,
name|st
parameter_list|)
define|\
value|((void (*)(STACK_OF(type) *))sk_sort)(st)
end_define

begin_define
define|#
directive|define
name|SKM_ASN1_SET_OF_d2i
parameter_list|(
name|type
parameter_list|,
name|st
parameter_list|,
name|pp
parameter_list|,
name|length
parameter_list|,
name|d2i_func
parameter_list|,
name|free_func
parameter_list|,
name|ex_tag
parameter_list|,
name|ex_class
parameter_list|)
define|\
value|((STACK_OF(type) * (*) (STACK_OF(type) **,unsigned char **, long , \                                        type *(*)(type **, unsigned char **,long), \                                        void (*)(type *), int ,int )) d2i_ASN1_SET) \ 						(st,pp,length, d2i_func, free_func, ex_tag,ex_class)
end_define

begin_define
define|#
directive|define
name|SKM_ASN1_SET_OF_i2d
parameter_list|(
name|type
parameter_list|,
name|st
parameter_list|,
name|pp
parameter_list|,
name|i2d_func
parameter_list|,
name|ex_tag
parameter_list|,
name|ex_class
parameter_list|,
name|is_set
parameter_list|)
define|\
value|((int (*)(STACK_OF(type) *,unsigned char **, \                            int (*)(type *,unsigned char **), int , int , int)) i2d_ASN1_SET) \ 						(st,pp,i2d_func,ex_tag,ex_class,is_set)
end_define

begin_define
define|#
directive|define
name|SKM_ASN1_seq_pack
parameter_list|(
name|type
parameter_list|,
name|st
parameter_list|,
name|i2d_func
parameter_list|,
name|buf
parameter_list|,
name|len
parameter_list|)
define|\
value|((unsigned char *(*)(STACK_OF(type) *, \                                     int (*)(type *,unsigned char **), unsigned char **,int *)) ASN1_seq_pack) \ 				(st, i2d_func, buf, len)
end_define

begin_define
define|#
directive|define
name|SKM_ASN1_seq_unpack
parameter_list|(
name|type
parameter_list|,
name|buf
parameter_list|,
name|len
parameter_list|,
name|d2i_func
parameter_list|,
name|free_func
parameter_list|)
define|\
value|((STACK_OF(type) * (*)(unsigned char *,int, \                                        type *(*)(type **,unsigned char **, long), \                                        void (*)(type *)))ASN1_seq_unpack) \ 					(buf,len,d2i_func, free_func)
end_define

begin_define
define|#
directive|define
name|SKM_PKCS12_decrypt_d2i
parameter_list|(
name|type
parameter_list|,
name|algor
parameter_list|,
name|d2i_func
parameter_list|,
name|free_func
parameter_list|,
name|pass
parameter_list|,
name|passlen
parameter_list|,
name|oct
parameter_list|,
name|seq
parameter_list|)
define|\
value|((STACK_OF(type) * (*)(X509_ALGOR *, \                                 type *(*)(type **, unsigned char **, long), void (*)(type *), \                                 const char *, int, \                                 ASN1_STRING *, int))PKCS12_decrypt_d2i) \ 				(algor,d2i_func,free_func,pass,passlen,oct,seq)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|STACK_OF
parameter_list|(
name|type
parameter_list|)
value|STACK
end_define

begin_define
define|#
directive|define
name|PREDECLARE_STACK_OF
parameter_list|(
name|type
parameter_list|)
end_define

begin_comment
comment|/* nada */
end_comment

begin_define
define|#
directive|define
name|DECLARE_STACK_OF
parameter_list|(
name|type
parameter_list|)
end_define

begin_comment
comment|/* nada */
end_comment

begin_define
define|#
directive|define
name|IMPLEMENT_STACK_OF
parameter_list|(
name|type
parameter_list|)
end_define

begin_comment
comment|/* nada */
end_comment

begin_define
define|#
directive|define
name|SKM_sk_new
parameter_list|(
name|type
parameter_list|,
name|cmp
parameter_list|)
define|\
value|sk_new((int (*)(const char * const *, const char * const *))(cmp))
end_define

begin_define
define|#
directive|define
name|SKM_sk_new_null
parameter_list|(
name|type
parameter_list|)
define|\
value|sk_new_null()
end_define

begin_define
define|#
directive|define
name|SKM_sk_free
parameter_list|(
name|type
parameter_list|,
name|st
parameter_list|)
define|\
value|sk_free(st)
end_define

begin_define
define|#
directive|define
name|SKM_sk_num
parameter_list|(
name|type
parameter_list|,
name|st
parameter_list|)
define|\
value|sk_num(st)
end_define

begin_define
define|#
directive|define
name|SKM_sk_value
parameter_list|(
name|type
parameter_list|,
name|st
parameter_list|,
name|i
parameter_list|)
define|\
value|((type *)sk_value(st, i))
end_define

begin_define
define|#
directive|define
name|SKM_sk_set
parameter_list|(
name|type
parameter_list|,
name|st
parameter_list|,
name|i
parameter_list|,
name|val
parameter_list|)
define|\
value|((type *)sk_set(st, i,(char *)val))
end_define

begin_define
define|#
directive|define
name|SKM_sk_zero
parameter_list|(
name|type
parameter_list|,
name|st
parameter_list|)
define|\
value|sk_zero(st)
end_define

begin_define
define|#
directive|define
name|SKM_sk_push
parameter_list|(
name|type
parameter_list|,
name|st
parameter_list|,
name|val
parameter_list|)
define|\
value|sk_push(st, (char *)val)
end_define

begin_define
define|#
directive|define
name|SKM_sk_unshift
parameter_list|(
name|type
parameter_list|,
name|st
parameter_list|,
name|val
parameter_list|)
define|\
value|sk_unshift(st, val)
end_define

begin_define
define|#
directive|define
name|SKM_sk_find
parameter_list|(
name|type
parameter_list|,
name|st
parameter_list|,
name|val
parameter_list|)
define|\
value|sk_find(st, (char *)val)
end_define

begin_define
define|#
directive|define
name|SKM_sk_delete
parameter_list|(
name|type
parameter_list|,
name|st
parameter_list|,
name|i
parameter_list|)
define|\
value|((type *)sk_delete(st, i))
end_define

begin_define
define|#
directive|define
name|SKM_sk_delete_ptr
parameter_list|(
name|type
parameter_list|,
name|st
parameter_list|,
name|ptr
parameter_list|)
define|\
value|((type *)sk_delete_ptr(st,(char *)ptr))
end_define

begin_define
define|#
directive|define
name|SKM_sk_insert
parameter_list|(
name|type
parameter_list|,
name|st
parameter_list|,
name|val
parameter_list|,
name|i
parameter_list|)
define|\
value|sk_insert(st, (char *)val, i)
end_define

begin_define
define|#
directive|define
name|SKM_sk_set_cmp_func
parameter_list|(
name|type
parameter_list|,
name|st
parameter_list|,
name|cmp
parameter_list|)
define|\
value|((int (*)(const type * const *,const type * const *)) \ 	sk_set_cmp_func(st, (int (*)(const char * const *, const char * const *))(cmp)))
end_define

begin_define
define|#
directive|define
name|SKM_sk_dup
parameter_list|(
name|type
parameter_list|,
name|st
parameter_list|)
define|\
value|sk_dup(st)
end_define

begin_define
define|#
directive|define
name|SKM_sk_pop_free
parameter_list|(
name|type
parameter_list|,
name|st
parameter_list|,
name|free_func
parameter_list|)
define|\
value|sk_pop_free(st, (void (*)(void *))free_func)
end_define

begin_define
define|#
directive|define
name|SKM_sk_shift
parameter_list|(
name|type
parameter_list|,
name|st
parameter_list|)
define|\
value|((type *)sk_shift(st))
end_define

begin_define
define|#
directive|define
name|SKM_sk_pop
parameter_list|(
name|type
parameter_list|,
name|st
parameter_list|)
define|\
value|((type *)sk_pop(st))
end_define

begin_define
define|#
directive|define
name|SKM_sk_sort
parameter_list|(
name|type
parameter_list|,
name|st
parameter_list|)
define|\
value|sk_sort(st)
end_define

begin_define
define|#
directive|define
name|SKM_ASN1_SET_OF_d2i
parameter_list|(
name|type
parameter_list|,
name|st
parameter_list|,
name|pp
parameter_list|,
name|length
parameter_list|,
name|d2i_func
parameter_list|,
name|free_func
parameter_list|,
name|ex_tag
parameter_list|,
name|ex_class
parameter_list|)
define|\
value|d2i_ASN1_SET(st,pp,length, (char *(*)())d2i_func, (void (*)(void *))free_func, ex_tag,ex_class)
end_define

begin_define
define|#
directive|define
name|SKM_ASN1_SET_OF_i2d
parameter_list|(
name|type
parameter_list|,
name|st
parameter_list|,
name|pp
parameter_list|,
name|i2d_func
parameter_list|,
name|ex_tag
parameter_list|,
name|ex_class
parameter_list|,
name|is_set
parameter_list|)
define|\
value|i2d_ASN1_SET(st,pp,i2d_func,ex_tag,ex_class,is_set)
end_define

begin_define
define|#
directive|define
name|SKM_ASN1_seq_pack
parameter_list|(
name|type
parameter_list|,
name|st
parameter_list|,
name|i2d_func
parameter_list|,
name|buf
parameter_list|,
name|len
parameter_list|)
define|\
value|ASN1_seq_pack(st, i2d_func, buf, len)
end_define

begin_define
define|#
directive|define
name|SKM_ASN1_seq_unpack
parameter_list|(
name|type
parameter_list|,
name|buf
parameter_list|,
name|len
parameter_list|,
name|d2i_func
parameter_list|,
name|free_func
parameter_list|)
define|\
value|ASN1_seq_unpack(buf,len,(char *(*)())d2i_func, (void(*)(void *))free_func)
end_define

begin_define
define|#
directive|define
name|SKM_PKCS12_decrypt_d2i
parameter_list|(
name|type
parameter_list|,
name|algor
parameter_list|,
name|d2i_func
parameter_list|,
name|free_func
parameter_list|,
name|pass
parameter_list|,
name|passlen
parameter_list|,
name|oct
parameter_list|,
name|seq
parameter_list|)
define|\
value|((STACK *)PKCS12_decrypt_d2i(algor,(char *(*)())d2i_func, (void(*)(void *))free_func,pass,passlen,oct,seq))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* This block of defines is updated by util/mkstack.pl, please do not touch! */
end_comment

begin_define
define|#
directive|define
name|sk_ACCESS_DESCRIPTION_new
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_new(ACCESS_DESCRIPTION, (st))
end_define

begin_define
define|#
directive|define
name|sk_ACCESS_DESCRIPTION_new_null
parameter_list|()
value|SKM_sk_new_null(ACCESS_DESCRIPTION)
end_define

begin_define
define|#
directive|define
name|sk_ACCESS_DESCRIPTION_free
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_free(ACCESS_DESCRIPTION, (st))
end_define

begin_define
define|#
directive|define
name|sk_ACCESS_DESCRIPTION_num
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_num(ACCESS_DESCRIPTION, (st))
end_define

begin_define
define|#
directive|define
name|sk_ACCESS_DESCRIPTION_value
parameter_list|(
name|st
parameter_list|,
name|i
parameter_list|)
value|SKM_sk_value(ACCESS_DESCRIPTION, (st), (i))
end_define

begin_define
define|#
directive|define
name|sk_ACCESS_DESCRIPTION_set
parameter_list|(
name|st
parameter_list|,
name|i
parameter_list|,
name|val
parameter_list|)
value|SKM_sk_set(ACCESS_DESCRIPTION, (st), (i), (val))
end_define

begin_define
define|#
directive|define
name|sk_ACCESS_DESCRIPTION_zero
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_zero(ACCESS_DESCRIPTION, (st))
end_define

begin_define
define|#
directive|define
name|sk_ACCESS_DESCRIPTION_push
parameter_list|(
name|st
parameter_list|,
name|val
parameter_list|)
value|SKM_sk_push(ACCESS_DESCRIPTION, (st), (val))
end_define

begin_define
define|#
directive|define
name|sk_ACCESS_DESCRIPTION_unshift
parameter_list|(
name|st
parameter_list|,
name|val
parameter_list|)
value|SKM_sk_unshift(ACCESS_DESCRIPTION, (st), (val))
end_define

begin_define
define|#
directive|define
name|sk_ACCESS_DESCRIPTION_find
parameter_list|(
name|st
parameter_list|,
name|val
parameter_list|)
value|SKM_sk_find(ACCESS_DESCRIPTION, (st), (val))
end_define

begin_define
define|#
directive|define
name|sk_ACCESS_DESCRIPTION_delete
parameter_list|(
name|st
parameter_list|,
name|i
parameter_list|)
value|SKM_sk_delete(ACCESS_DESCRIPTION, (st), (i))
end_define

begin_define
define|#
directive|define
name|sk_ACCESS_DESCRIPTION_delete_ptr
parameter_list|(
name|st
parameter_list|,
name|ptr
parameter_list|)
value|SKM_sk_delete_ptr(ACCESS_DESCRIPTION, (st), (ptr))
end_define

begin_define
define|#
directive|define
name|sk_ACCESS_DESCRIPTION_insert
parameter_list|(
name|st
parameter_list|,
name|val
parameter_list|,
name|i
parameter_list|)
value|SKM_sk_insert(ACCESS_DESCRIPTION, (st), (val), (i))
end_define

begin_define
define|#
directive|define
name|sk_ACCESS_DESCRIPTION_set_cmp_func
parameter_list|(
name|st
parameter_list|,
name|cmp
parameter_list|)
value|SKM_sk_set_cmp_func(ACCESS_DESCRIPTION, (st), (cmp))
end_define

begin_define
define|#
directive|define
name|sk_ACCESS_DESCRIPTION_dup
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_dup(ACCESS_DESCRIPTION, st)
end_define

begin_define
define|#
directive|define
name|sk_ACCESS_DESCRIPTION_pop_free
parameter_list|(
name|st
parameter_list|,
name|free_func
parameter_list|)
value|SKM_sk_pop_free(ACCESS_DESCRIPTION, (st), (free_func))
end_define

begin_define
define|#
directive|define
name|sk_ACCESS_DESCRIPTION_shift
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_shift(ACCESS_DESCRIPTION, (st))
end_define

begin_define
define|#
directive|define
name|sk_ACCESS_DESCRIPTION_pop
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_pop(ACCESS_DESCRIPTION, (st))
end_define

begin_define
define|#
directive|define
name|sk_ACCESS_DESCRIPTION_sort
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_sort(ACCESS_DESCRIPTION, (st))
end_define

begin_define
define|#
directive|define
name|sk_ASN1_INTEGER_new
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_new(ASN1_INTEGER, (st))
end_define

begin_define
define|#
directive|define
name|sk_ASN1_INTEGER_new_null
parameter_list|()
value|SKM_sk_new_null(ASN1_INTEGER)
end_define

begin_define
define|#
directive|define
name|sk_ASN1_INTEGER_free
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_free(ASN1_INTEGER, (st))
end_define

begin_define
define|#
directive|define
name|sk_ASN1_INTEGER_num
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_num(ASN1_INTEGER, (st))
end_define

begin_define
define|#
directive|define
name|sk_ASN1_INTEGER_value
parameter_list|(
name|st
parameter_list|,
name|i
parameter_list|)
value|SKM_sk_value(ASN1_INTEGER, (st), (i))
end_define

begin_define
define|#
directive|define
name|sk_ASN1_INTEGER_set
parameter_list|(
name|st
parameter_list|,
name|i
parameter_list|,
name|val
parameter_list|)
value|SKM_sk_set(ASN1_INTEGER, (st), (i), (val))
end_define

begin_define
define|#
directive|define
name|sk_ASN1_INTEGER_zero
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_zero(ASN1_INTEGER, (st))
end_define

begin_define
define|#
directive|define
name|sk_ASN1_INTEGER_push
parameter_list|(
name|st
parameter_list|,
name|val
parameter_list|)
value|SKM_sk_push(ASN1_INTEGER, (st), (val))
end_define

begin_define
define|#
directive|define
name|sk_ASN1_INTEGER_unshift
parameter_list|(
name|st
parameter_list|,
name|val
parameter_list|)
value|SKM_sk_unshift(ASN1_INTEGER, (st), (val))
end_define

begin_define
define|#
directive|define
name|sk_ASN1_INTEGER_find
parameter_list|(
name|st
parameter_list|,
name|val
parameter_list|)
value|SKM_sk_find(ASN1_INTEGER, (st), (val))
end_define

begin_define
define|#
directive|define
name|sk_ASN1_INTEGER_delete
parameter_list|(
name|st
parameter_list|,
name|i
parameter_list|)
value|SKM_sk_delete(ASN1_INTEGER, (st), (i))
end_define

begin_define
define|#
directive|define
name|sk_ASN1_INTEGER_delete_ptr
parameter_list|(
name|st
parameter_list|,
name|ptr
parameter_list|)
value|SKM_sk_delete_ptr(ASN1_INTEGER, (st), (ptr))
end_define

begin_define
define|#
directive|define
name|sk_ASN1_INTEGER_insert
parameter_list|(
name|st
parameter_list|,
name|val
parameter_list|,
name|i
parameter_list|)
value|SKM_sk_insert(ASN1_INTEGER, (st), (val), (i))
end_define

begin_define
define|#
directive|define
name|sk_ASN1_INTEGER_set_cmp_func
parameter_list|(
name|st
parameter_list|,
name|cmp
parameter_list|)
value|SKM_sk_set_cmp_func(ASN1_INTEGER, (st), (cmp))
end_define

begin_define
define|#
directive|define
name|sk_ASN1_INTEGER_dup
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_dup(ASN1_INTEGER, st)
end_define

begin_define
define|#
directive|define
name|sk_ASN1_INTEGER_pop_free
parameter_list|(
name|st
parameter_list|,
name|free_func
parameter_list|)
value|SKM_sk_pop_free(ASN1_INTEGER, (st), (free_func))
end_define

begin_define
define|#
directive|define
name|sk_ASN1_INTEGER_shift
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_shift(ASN1_INTEGER, (st))
end_define

begin_define
define|#
directive|define
name|sk_ASN1_INTEGER_pop
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_pop(ASN1_INTEGER, (st))
end_define

begin_define
define|#
directive|define
name|sk_ASN1_INTEGER_sort
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_sort(ASN1_INTEGER, (st))
end_define

begin_define
define|#
directive|define
name|sk_ASN1_OBJECT_new
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_new(ASN1_OBJECT, (st))
end_define

begin_define
define|#
directive|define
name|sk_ASN1_OBJECT_new_null
parameter_list|()
value|SKM_sk_new_null(ASN1_OBJECT)
end_define

begin_define
define|#
directive|define
name|sk_ASN1_OBJECT_free
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_free(ASN1_OBJECT, (st))
end_define

begin_define
define|#
directive|define
name|sk_ASN1_OBJECT_num
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_num(ASN1_OBJECT, (st))
end_define

begin_define
define|#
directive|define
name|sk_ASN1_OBJECT_value
parameter_list|(
name|st
parameter_list|,
name|i
parameter_list|)
value|SKM_sk_value(ASN1_OBJECT, (st), (i))
end_define

begin_define
define|#
directive|define
name|sk_ASN1_OBJECT_set
parameter_list|(
name|st
parameter_list|,
name|i
parameter_list|,
name|val
parameter_list|)
value|SKM_sk_set(ASN1_OBJECT, (st), (i), (val))
end_define

begin_define
define|#
directive|define
name|sk_ASN1_OBJECT_zero
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_zero(ASN1_OBJECT, (st))
end_define

begin_define
define|#
directive|define
name|sk_ASN1_OBJECT_push
parameter_list|(
name|st
parameter_list|,
name|val
parameter_list|)
value|SKM_sk_push(ASN1_OBJECT, (st), (val))
end_define

begin_define
define|#
directive|define
name|sk_ASN1_OBJECT_unshift
parameter_list|(
name|st
parameter_list|,
name|val
parameter_list|)
value|SKM_sk_unshift(ASN1_OBJECT, (st), (val))
end_define

begin_define
define|#
directive|define
name|sk_ASN1_OBJECT_find
parameter_list|(
name|st
parameter_list|,
name|val
parameter_list|)
value|SKM_sk_find(ASN1_OBJECT, (st), (val))
end_define

begin_define
define|#
directive|define
name|sk_ASN1_OBJECT_delete
parameter_list|(
name|st
parameter_list|,
name|i
parameter_list|)
value|SKM_sk_delete(ASN1_OBJECT, (st), (i))
end_define

begin_define
define|#
directive|define
name|sk_ASN1_OBJECT_delete_ptr
parameter_list|(
name|st
parameter_list|,
name|ptr
parameter_list|)
value|SKM_sk_delete_ptr(ASN1_OBJECT, (st), (ptr))
end_define

begin_define
define|#
directive|define
name|sk_ASN1_OBJECT_insert
parameter_list|(
name|st
parameter_list|,
name|val
parameter_list|,
name|i
parameter_list|)
value|SKM_sk_insert(ASN1_OBJECT, (st), (val), (i))
end_define

begin_define
define|#
directive|define
name|sk_ASN1_OBJECT_set_cmp_func
parameter_list|(
name|st
parameter_list|,
name|cmp
parameter_list|)
value|SKM_sk_set_cmp_func(ASN1_OBJECT, (st), (cmp))
end_define

begin_define
define|#
directive|define
name|sk_ASN1_OBJECT_dup
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_dup(ASN1_OBJECT, st)
end_define

begin_define
define|#
directive|define
name|sk_ASN1_OBJECT_pop_free
parameter_list|(
name|st
parameter_list|,
name|free_func
parameter_list|)
value|SKM_sk_pop_free(ASN1_OBJECT, (st), (free_func))
end_define

begin_define
define|#
directive|define
name|sk_ASN1_OBJECT_shift
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_shift(ASN1_OBJECT, (st))
end_define

begin_define
define|#
directive|define
name|sk_ASN1_OBJECT_pop
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_pop(ASN1_OBJECT, (st))
end_define

begin_define
define|#
directive|define
name|sk_ASN1_OBJECT_sort
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_sort(ASN1_OBJECT, (st))
end_define

begin_define
define|#
directive|define
name|sk_ASN1_STRING_TABLE_new
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_new(ASN1_STRING_TABLE, (st))
end_define

begin_define
define|#
directive|define
name|sk_ASN1_STRING_TABLE_new_null
parameter_list|()
value|SKM_sk_new_null(ASN1_STRING_TABLE)
end_define

begin_define
define|#
directive|define
name|sk_ASN1_STRING_TABLE_free
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_free(ASN1_STRING_TABLE, (st))
end_define

begin_define
define|#
directive|define
name|sk_ASN1_STRING_TABLE_num
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_num(ASN1_STRING_TABLE, (st))
end_define

begin_define
define|#
directive|define
name|sk_ASN1_STRING_TABLE_value
parameter_list|(
name|st
parameter_list|,
name|i
parameter_list|)
value|SKM_sk_value(ASN1_STRING_TABLE, (st), (i))
end_define

begin_define
define|#
directive|define
name|sk_ASN1_STRING_TABLE_set
parameter_list|(
name|st
parameter_list|,
name|i
parameter_list|,
name|val
parameter_list|)
value|SKM_sk_set(ASN1_STRING_TABLE, (st), (i), (val))
end_define

begin_define
define|#
directive|define
name|sk_ASN1_STRING_TABLE_zero
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_zero(ASN1_STRING_TABLE, (st))
end_define

begin_define
define|#
directive|define
name|sk_ASN1_STRING_TABLE_push
parameter_list|(
name|st
parameter_list|,
name|val
parameter_list|)
value|SKM_sk_push(ASN1_STRING_TABLE, (st), (val))
end_define

begin_define
define|#
directive|define
name|sk_ASN1_STRING_TABLE_unshift
parameter_list|(
name|st
parameter_list|,
name|val
parameter_list|)
value|SKM_sk_unshift(ASN1_STRING_TABLE, (st), (val))
end_define

begin_define
define|#
directive|define
name|sk_ASN1_STRING_TABLE_find
parameter_list|(
name|st
parameter_list|,
name|val
parameter_list|)
value|SKM_sk_find(ASN1_STRING_TABLE, (st), (val))
end_define

begin_define
define|#
directive|define
name|sk_ASN1_STRING_TABLE_delete
parameter_list|(
name|st
parameter_list|,
name|i
parameter_list|)
value|SKM_sk_delete(ASN1_STRING_TABLE, (st), (i))
end_define

begin_define
define|#
directive|define
name|sk_ASN1_STRING_TABLE_delete_ptr
parameter_list|(
name|st
parameter_list|,
name|ptr
parameter_list|)
value|SKM_sk_delete_ptr(ASN1_STRING_TABLE, (st), (ptr))
end_define

begin_define
define|#
directive|define
name|sk_ASN1_STRING_TABLE_insert
parameter_list|(
name|st
parameter_list|,
name|val
parameter_list|,
name|i
parameter_list|)
value|SKM_sk_insert(ASN1_STRING_TABLE, (st), (val), (i))
end_define

begin_define
define|#
directive|define
name|sk_ASN1_STRING_TABLE_set_cmp_func
parameter_list|(
name|st
parameter_list|,
name|cmp
parameter_list|)
value|SKM_sk_set_cmp_func(ASN1_STRING_TABLE, (st), (cmp))
end_define

begin_define
define|#
directive|define
name|sk_ASN1_STRING_TABLE_dup
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_dup(ASN1_STRING_TABLE, st)
end_define

begin_define
define|#
directive|define
name|sk_ASN1_STRING_TABLE_pop_free
parameter_list|(
name|st
parameter_list|,
name|free_func
parameter_list|)
value|SKM_sk_pop_free(ASN1_STRING_TABLE, (st), (free_func))
end_define

begin_define
define|#
directive|define
name|sk_ASN1_STRING_TABLE_shift
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_shift(ASN1_STRING_TABLE, (st))
end_define

begin_define
define|#
directive|define
name|sk_ASN1_STRING_TABLE_pop
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_pop(ASN1_STRING_TABLE, (st))
end_define

begin_define
define|#
directive|define
name|sk_ASN1_STRING_TABLE_sort
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_sort(ASN1_STRING_TABLE, (st))
end_define

begin_define
define|#
directive|define
name|sk_ASN1_TYPE_new
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_new(ASN1_TYPE, (st))
end_define

begin_define
define|#
directive|define
name|sk_ASN1_TYPE_new_null
parameter_list|()
value|SKM_sk_new_null(ASN1_TYPE)
end_define

begin_define
define|#
directive|define
name|sk_ASN1_TYPE_free
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_free(ASN1_TYPE, (st))
end_define

begin_define
define|#
directive|define
name|sk_ASN1_TYPE_num
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_num(ASN1_TYPE, (st))
end_define

begin_define
define|#
directive|define
name|sk_ASN1_TYPE_value
parameter_list|(
name|st
parameter_list|,
name|i
parameter_list|)
value|SKM_sk_value(ASN1_TYPE, (st), (i))
end_define

begin_define
define|#
directive|define
name|sk_ASN1_TYPE_set
parameter_list|(
name|st
parameter_list|,
name|i
parameter_list|,
name|val
parameter_list|)
value|SKM_sk_set(ASN1_TYPE, (st), (i), (val))
end_define

begin_define
define|#
directive|define
name|sk_ASN1_TYPE_zero
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_zero(ASN1_TYPE, (st))
end_define

begin_define
define|#
directive|define
name|sk_ASN1_TYPE_push
parameter_list|(
name|st
parameter_list|,
name|val
parameter_list|)
value|SKM_sk_push(ASN1_TYPE, (st), (val))
end_define

begin_define
define|#
directive|define
name|sk_ASN1_TYPE_unshift
parameter_list|(
name|st
parameter_list|,
name|val
parameter_list|)
value|SKM_sk_unshift(ASN1_TYPE, (st), (val))
end_define

begin_define
define|#
directive|define
name|sk_ASN1_TYPE_find
parameter_list|(
name|st
parameter_list|,
name|val
parameter_list|)
value|SKM_sk_find(ASN1_TYPE, (st), (val))
end_define

begin_define
define|#
directive|define
name|sk_ASN1_TYPE_delete
parameter_list|(
name|st
parameter_list|,
name|i
parameter_list|)
value|SKM_sk_delete(ASN1_TYPE, (st), (i))
end_define

begin_define
define|#
directive|define
name|sk_ASN1_TYPE_delete_ptr
parameter_list|(
name|st
parameter_list|,
name|ptr
parameter_list|)
value|SKM_sk_delete_ptr(ASN1_TYPE, (st), (ptr))
end_define

begin_define
define|#
directive|define
name|sk_ASN1_TYPE_insert
parameter_list|(
name|st
parameter_list|,
name|val
parameter_list|,
name|i
parameter_list|)
value|SKM_sk_insert(ASN1_TYPE, (st), (val), (i))
end_define

begin_define
define|#
directive|define
name|sk_ASN1_TYPE_set_cmp_func
parameter_list|(
name|st
parameter_list|,
name|cmp
parameter_list|)
value|SKM_sk_set_cmp_func(ASN1_TYPE, (st), (cmp))
end_define

begin_define
define|#
directive|define
name|sk_ASN1_TYPE_dup
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_dup(ASN1_TYPE, st)
end_define

begin_define
define|#
directive|define
name|sk_ASN1_TYPE_pop_free
parameter_list|(
name|st
parameter_list|,
name|free_func
parameter_list|)
value|SKM_sk_pop_free(ASN1_TYPE, (st), (free_func))
end_define

begin_define
define|#
directive|define
name|sk_ASN1_TYPE_shift
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_shift(ASN1_TYPE, (st))
end_define

begin_define
define|#
directive|define
name|sk_ASN1_TYPE_pop
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_pop(ASN1_TYPE, (st))
end_define

begin_define
define|#
directive|define
name|sk_ASN1_TYPE_sort
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_sort(ASN1_TYPE, (st))
end_define

begin_define
define|#
directive|define
name|sk_BIO_new
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_new(BIO, (st))
end_define

begin_define
define|#
directive|define
name|sk_BIO_new_null
parameter_list|()
value|SKM_sk_new_null(BIO)
end_define

begin_define
define|#
directive|define
name|sk_BIO_free
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_free(BIO, (st))
end_define

begin_define
define|#
directive|define
name|sk_BIO_num
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_num(BIO, (st))
end_define

begin_define
define|#
directive|define
name|sk_BIO_value
parameter_list|(
name|st
parameter_list|,
name|i
parameter_list|)
value|SKM_sk_value(BIO, (st), (i))
end_define

begin_define
define|#
directive|define
name|sk_BIO_set
parameter_list|(
name|st
parameter_list|,
name|i
parameter_list|,
name|val
parameter_list|)
value|SKM_sk_set(BIO, (st), (i), (val))
end_define

begin_define
define|#
directive|define
name|sk_BIO_zero
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_zero(BIO, (st))
end_define

begin_define
define|#
directive|define
name|sk_BIO_push
parameter_list|(
name|st
parameter_list|,
name|val
parameter_list|)
value|SKM_sk_push(BIO, (st), (val))
end_define

begin_define
define|#
directive|define
name|sk_BIO_unshift
parameter_list|(
name|st
parameter_list|,
name|val
parameter_list|)
value|SKM_sk_unshift(BIO, (st), (val))
end_define

begin_define
define|#
directive|define
name|sk_BIO_find
parameter_list|(
name|st
parameter_list|,
name|val
parameter_list|)
value|SKM_sk_find(BIO, (st), (val))
end_define

begin_define
define|#
directive|define
name|sk_BIO_delete
parameter_list|(
name|st
parameter_list|,
name|i
parameter_list|)
value|SKM_sk_delete(BIO, (st), (i))
end_define

begin_define
define|#
directive|define
name|sk_BIO_delete_ptr
parameter_list|(
name|st
parameter_list|,
name|ptr
parameter_list|)
value|SKM_sk_delete_ptr(BIO, (st), (ptr))
end_define

begin_define
define|#
directive|define
name|sk_BIO_insert
parameter_list|(
name|st
parameter_list|,
name|val
parameter_list|,
name|i
parameter_list|)
value|SKM_sk_insert(BIO, (st), (val), (i))
end_define

begin_define
define|#
directive|define
name|sk_BIO_set_cmp_func
parameter_list|(
name|st
parameter_list|,
name|cmp
parameter_list|)
value|SKM_sk_set_cmp_func(BIO, (st), (cmp))
end_define

begin_define
define|#
directive|define
name|sk_BIO_dup
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_dup(BIO, st)
end_define

begin_define
define|#
directive|define
name|sk_BIO_pop_free
parameter_list|(
name|st
parameter_list|,
name|free_func
parameter_list|)
value|SKM_sk_pop_free(BIO, (st), (free_func))
end_define

begin_define
define|#
directive|define
name|sk_BIO_shift
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_shift(BIO, (st))
end_define

begin_define
define|#
directive|define
name|sk_BIO_pop
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_pop(BIO, (st))
end_define

begin_define
define|#
directive|define
name|sk_BIO_sort
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_sort(BIO, (st))
end_define

begin_define
define|#
directive|define
name|sk_CONF_VALUE_new
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_new(CONF_VALUE, (st))
end_define

begin_define
define|#
directive|define
name|sk_CONF_VALUE_new_null
parameter_list|()
value|SKM_sk_new_null(CONF_VALUE)
end_define

begin_define
define|#
directive|define
name|sk_CONF_VALUE_free
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_free(CONF_VALUE, (st))
end_define

begin_define
define|#
directive|define
name|sk_CONF_VALUE_num
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_num(CONF_VALUE, (st))
end_define

begin_define
define|#
directive|define
name|sk_CONF_VALUE_value
parameter_list|(
name|st
parameter_list|,
name|i
parameter_list|)
value|SKM_sk_value(CONF_VALUE, (st), (i))
end_define

begin_define
define|#
directive|define
name|sk_CONF_VALUE_set
parameter_list|(
name|st
parameter_list|,
name|i
parameter_list|,
name|val
parameter_list|)
value|SKM_sk_set(CONF_VALUE, (st), (i), (val))
end_define

begin_define
define|#
directive|define
name|sk_CONF_VALUE_zero
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_zero(CONF_VALUE, (st))
end_define

begin_define
define|#
directive|define
name|sk_CONF_VALUE_push
parameter_list|(
name|st
parameter_list|,
name|val
parameter_list|)
value|SKM_sk_push(CONF_VALUE, (st), (val))
end_define

begin_define
define|#
directive|define
name|sk_CONF_VALUE_unshift
parameter_list|(
name|st
parameter_list|,
name|val
parameter_list|)
value|SKM_sk_unshift(CONF_VALUE, (st), (val))
end_define

begin_define
define|#
directive|define
name|sk_CONF_VALUE_find
parameter_list|(
name|st
parameter_list|,
name|val
parameter_list|)
value|SKM_sk_find(CONF_VALUE, (st), (val))
end_define

begin_define
define|#
directive|define
name|sk_CONF_VALUE_delete
parameter_list|(
name|st
parameter_list|,
name|i
parameter_list|)
value|SKM_sk_delete(CONF_VALUE, (st), (i))
end_define

begin_define
define|#
directive|define
name|sk_CONF_VALUE_delete_ptr
parameter_list|(
name|st
parameter_list|,
name|ptr
parameter_list|)
value|SKM_sk_delete_ptr(CONF_VALUE, (st), (ptr))
end_define

begin_define
define|#
directive|define
name|sk_CONF_VALUE_insert
parameter_list|(
name|st
parameter_list|,
name|val
parameter_list|,
name|i
parameter_list|)
value|SKM_sk_insert(CONF_VALUE, (st), (val), (i))
end_define

begin_define
define|#
directive|define
name|sk_CONF_VALUE_set_cmp_func
parameter_list|(
name|st
parameter_list|,
name|cmp
parameter_list|)
value|SKM_sk_set_cmp_func(CONF_VALUE, (st), (cmp))
end_define

begin_define
define|#
directive|define
name|sk_CONF_VALUE_dup
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_dup(CONF_VALUE, st)
end_define

begin_define
define|#
directive|define
name|sk_CONF_VALUE_pop_free
parameter_list|(
name|st
parameter_list|,
name|free_func
parameter_list|)
value|SKM_sk_pop_free(CONF_VALUE, (st), (free_func))
end_define

begin_define
define|#
directive|define
name|sk_CONF_VALUE_shift
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_shift(CONF_VALUE, (st))
end_define

begin_define
define|#
directive|define
name|sk_CONF_VALUE_pop
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_pop(CONF_VALUE, (st))
end_define

begin_define
define|#
directive|define
name|sk_CONF_VALUE_sort
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_sort(CONF_VALUE, (st))
end_define

begin_define
define|#
directive|define
name|sk_CRYPTO_EX_DATA_FUNCS_new
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_new(CRYPTO_EX_DATA_FUNCS, (st))
end_define

begin_define
define|#
directive|define
name|sk_CRYPTO_EX_DATA_FUNCS_new_null
parameter_list|()
value|SKM_sk_new_null(CRYPTO_EX_DATA_FUNCS)
end_define

begin_define
define|#
directive|define
name|sk_CRYPTO_EX_DATA_FUNCS_free
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_free(CRYPTO_EX_DATA_FUNCS, (st))
end_define

begin_define
define|#
directive|define
name|sk_CRYPTO_EX_DATA_FUNCS_num
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_num(CRYPTO_EX_DATA_FUNCS, (st))
end_define

begin_define
define|#
directive|define
name|sk_CRYPTO_EX_DATA_FUNCS_value
parameter_list|(
name|st
parameter_list|,
name|i
parameter_list|)
value|SKM_sk_value(CRYPTO_EX_DATA_FUNCS, (st), (i))
end_define

begin_define
define|#
directive|define
name|sk_CRYPTO_EX_DATA_FUNCS_set
parameter_list|(
name|st
parameter_list|,
name|i
parameter_list|,
name|val
parameter_list|)
value|SKM_sk_set(CRYPTO_EX_DATA_FUNCS, (st), (i), (val))
end_define

begin_define
define|#
directive|define
name|sk_CRYPTO_EX_DATA_FUNCS_zero
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_zero(CRYPTO_EX_DATA_FUNCS, (st))
end_define

begin_define
define|#
directive|define
name|sk_CRYPTO_EX_DATA_FUNCS_push
parameter_list|(
name|st
parameter_list|,
name|val
parameter_list|)
value|SKM_sk_push(CRYPTO_EX_DATA_FUNCS, (st), (val))
end_define

begin_define
define|#
directive|define
name|sk_CRYPTO_EX_DATA_FUNCS_unshift
parameter_list|(
name|st
parameter_list|,
name|val
parameter_list|)
value|SKM_sk_unshift(CRYPTO_EX_DATA_FUNCS, (st), (val))
end_define

begin_define
define|#
directive|define
name|sk_CRYPTO_EX_DATA_FUNCS_find
parameter_list|(
name|st
parameter_list|,
name|val
parameter_list|)
value|SKM_sk_find(CRYPTO_EX_DATA_FUNCS, (st), (val))
end_define

begin_define
define|#
directive|define
name|sk_CRYPTO_EX_DATA_FUNCS_delete
parameter_list|(
name|st
parameter_list|,
name|i
parameter_list|)
value|SKM_sk_delete(CRYPTO_EX_DATA_FUNCS, (st), (i))
end_define

begin_define
define|#
directive|define
name|sk_CRYPTO_EX_DATA_FUNCS_delete_ptr
parameter_list|(
name|st
parameter_list|,
name|ptr
parameter_list|)
value|SKM_sk_delete_ptr(CRYPTO_EX_DATA_FUNCS, (st), (ptr))
end_define

begin_define
define|#
directive|define
name|sk_CRYPTO_EX_DATA_FUNCS_insert
parameter_list|(
name|st
parameter_list|,
name|val
parameter_list|,
name|i
parameter_list|)
value|SKM_sk_insert(CRYPTO_EX_DATA_FUNCS, (st), (val), (i))
end_define

begin_define
define|#
directive|define
name|sk_CRYPTO_EX_DATA_FUNCS_set_cmp_func
parameter_list|(
name|st
parameter_list|,
name|cmp
parameter_list|)
value|SKM_sk_set_cmp_func(CRYPTO_EX_DATA_FUNCS, (st), (cmp))
end_define

begin_define
define|#
directive|define
name|sk_CRYPTO_EX_DATA_FUNCS_dup
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_dup(CRYPTO_EX_DATA_FUNCS, st)
end_define

begin_define
define|#
directive|define
name|sk_CRYPTO_EX_DATA_FUNCS_pop_free
parameter_list|(
name|st
parameter_list|,
name|free_func
parameter_list|)
value|SKM_sk_pop_free(CRYPTO_EX_DATA_FUNCS, (st), (free_func))
end_define

begin_define
define|#
directive|define
name|sk_CRYPTO_EX_DATA_FUNCS_shift
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_shift(CRYPTO_EX_DATA_FUNCS, (st))
end_define

begin_define
define|#
directive|define
name|sk_CRYPTO_EX_DATA_FUNCS_pop
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_pop(CRYPTO_EX_DATA_FUNCS, (st))
end_define

begin_define
define|#
directive|define
name|sk_CRYPTO_EX_DATA_FUNCS_sort
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_sort(CRYPTO_EX_DATA_FUNCS, (st))
end_define

begin_define
define|#
directive|define
name|sk_CRYPTO_dynlock_new
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_new(CRYPTO_dynlock, (st))
end_define

begin_define
define|#
directive|define
name|sk_CRYPTO_dynlock_new_null
parameter_list|()
value|SKM_sk_new_null(CRYPTO_dynlock)
end_define

begin_define
define|#
directive|define
name|sk_CRYPTO_dynlock_free
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_free(CRYPTO_dynlock, (st))
end_define

begin_define
define|#
directive|define
name|sk_CRYPTO_dynlock_num
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_num(CRYPTO_dynlock, (st))
end_define

begin_define
define|#
directive|define
name|sk_CRYPTO_dynlock_value
parameter_list|(
name|st
parameter_list|,
name|i
parameter_list|)
value|SKM_sk_value(CRYPTO_dynlock, (st), (i))
end_define

begin_define
define|#
directive|define
name|sk_CRYPTO_dynlock_set
parameter_list|(
name|st
parameter_list|,
name|i
parameter_list|,
name|val
parameter_list|)
value|SKM_sk_set(CRYPTO_dynlock, (st), (i), (val))
end_define

begin_define
define|#
directive|define
name|sk_CRYPTO_dynlock_zero
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_zero(CRYPTO_dynlock, (st))
end_define

begin_define
define|#
directive|define
name|sk_CRYPTO_dynlock_push
parameter_list|(
name|st
parameter_list|,
name|val
parameter_list|)
value|SKM_sk_push(CRYPTO_dynlock, (st), (val))
end_define

begin_define
define|#
directive|define
name|sk_CRYPTO_dynlock_unshift
parameter_list|(
name|st
parameter_list|,
name|val
parameter_list|)
value|SKM_sk_unshift(CRYPTO_dynlock, (st), (val))
end_define

begin_define
define|#
directive|define
name|sk_CRYPTO_dynlock_find
parameter_list|(
name|st
parameter_list|,
name|val
parameter_list|)
value|SKM_sk_find(CRYPTO_dynlock, (st), (val))
end_define

begin_define
define|#
directive|define
name|sk_CRYPTO_dynlock_delete
parameter_list|(
name|st
parameter_list|,
name|i
parameter_list|)
value|SKM_sk_delete(CRYPTO_dynlock, (st), (i))
end_define

begin_define
define|#
directive|define
name|sk_CRYPTO_dynlock_delete_ptr
parameter_list|(
name|st
parameter_list|,
name|ptr
parameter_list|)
value|SKM_sk_delete_ptr(CRYPTO_dynlock, (st), (ptr))
end_define

begin_define
define|#
directive|define
name|sk_CRYPTO_dynlock_insert
parameter_list|(
name|st
parameter_list|,
name|val
parameter_list|,
name|i
parameter_list|)
value|SKM_sk_insert(CRYPTO_dynlock, (st), (val), (i))
end_define

begin_define
define|#
directive|define
name|sk_CRYPTO_dynlock_set_cmp_func
parameter_list|(
name|st
parameter_list|,
name|cmp
parameter_list|)
value|SKM_sk_set_cmp_func(CRYPTO_dynlock, (st), (cmp))
end_define

begin_define
define|#
directive|define
name|sk_CRYPTO_dynlock_dup
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_dup(CRYPTO_dynlock, st)
end_define

begin_define
define|#
directive|define
name|sk_CRYPTO_dynlock_pop_free
parameter_list|(
name|st
parameter_list|,
name|free_func
parameter_list|)
value|SKM_sk_pop_free(CRYPTO_dynlock, (st), (free_func))
end_define

begin_define
define|#
directive|define
name|sk_CRYPTO_dynlock_shift
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_shift(CRYPTO_dynlock, (st))
end_define

begin_define
define|#
directive|define
name|sk_CRYPTO_dynlock_pop
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_pop(CRYPTO_dynlock, (st))
end_define

begin_define
define|#
directive|define
name|sk_CRYPTO_dynlock_sort
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_sort(CRYPTO_dynlock, (st))
end_define

begin_define
define|#
directive|define
name|sk_DIST_POINT_new
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_new(DIST_POINT, (st))
end_define

begin_define
define|#
directive|define
name|sk_DIST_POINT_new_null
parameter_list|()
value|SKM_sk_new_null(DIST_POINT)
end_define

begin_define
define|#
directive|define
name|sk_DIST_POINT_free
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_free(DIST_POINT, (st))
end_define

begin_define
define|#
directive|define
name|sk_DIST_POINT_num
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_num(DIST_POINT, (st))
end_define

begin_define
define|#
directive|define
name|sk_DIST_POINT_value
parameter_list|(
name|st
parameter_list|,
name|i
parameter_list|)
value|SKM_sk_value(DIST_POINT, (st), (i))
end_define

begin_define
define|#
directive|define
name|sk_DIST_POINT_set
parameter_list|(
name|st
parameter_list|,
name|i
parameter_list|,
name|val
parameter_list|)
value|SKM_sk_set(DIST_POINT, (st), (i), (val))
end_define

begin_define
define|#
directive|define
name|sk_DIST_POINT_zero
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_zero(DIST_POINT, (st))
end_define

begin_define
define|#
directive|define
name|sk_DIST_POINT_push
parameter_list|(
name|st
parameter_list|,
name|val
parameter_list|)
value|SKM_sk_push(DIST_POINT, (st), (val))
end_define

begin_define
define|#
directive|define
name|sk_DIST_POINT_unshift
parameter_list|(
name|st
parameter_list|,
name|val
parameter_list|)
value|SKM_sk_unshift(DIST_POINT, (st), (val))
end_define

begin_define
define|#
directive|define
name|sk_DIST_POINT_find
parameter_list|(
name|st
parameter_list|,
name|val
parameter_list|)
value|SKM_sk_find(DIST_POINT, (st), (val))
end_define

begin_define
define|#
directive|define
name|sk_DIST_POINT_delete
parameter_list|(
name|st
parameter_list|,
name|i
parameter_list|)
value|SKM_sk_delete(DIST_POINT, (st), (i))
end_define

begin_define
define|#
directive|define
name|sk_DIST_POINT_delete_ptr
parameter_list|(
name|st
parameter_list|,
name|ptr
parameter_list|)
value|SKM_sk_delete_ptr(DIST_POINT, (st), (ptr))
end_define

begin_define
define|#
directive|define
name|sk_DIST_POINT_insert
parameter_list|(
name|st
parameter_list|,
name|val
parameter_list|,
name|i
parameter_list|)
value|SKM_sk_insert(DIST_POINT, (st), (val), (i))
end_define

begin_define
define|#
directive|define
name|sk_DIST_POINT_set_cmp_func
parameter_list|(
name|st
parameter_list|,
name|cmp
parameter_list|)
value|SKM_sk_set_cmp_func(DIST_POINT, (st), (cmp))
end_define

begin_define
define|#
directive|define
name|sk_DIST_POINT_dup
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_dup(DIST_POINT, st)
end_define

begin_define
define|#
directive|define
name|sk_DIST_POINT_pop_free
parameter_list|(
name|st
parameter_list|,
name|free_func
parameter_list|)
value|SKM_sk_pop_free(DIST_POINT, (st), (free_func))
end_define

begin_define
define|#
directive|define
name|sk_DIST_POINT_shift
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_shift(DIST_POINT, (st))
end_define

begin_define
define|#
directive|define
name|sk_DIST_POINT_pop
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_pop(DIST_POINT, (st))
end_define

begin_define
define|#
directive|define
name|sk_DIST_POINT_sort
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_sort(DIST_POINT, (st))
end_define

begin_define
define|#
directive|define
name|sk_GENERAL_NAME_new
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_new(GENERAL_NAME, (st))
end_define

begin_define
define|#
directive|define
name|sk_GENERAL_NAME_new_null
parameter_list|()
value|SKM_sk_new_null(GENERAL_NAME)
end_define

begin_define
define|#
directive|define
name|sk_GENERAL_NAME_free
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_free(GENERAL_NAME, (st))
end_define

begin_define
define|#
directive|define
name|sk_GENERAL_NAME_num
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_num(GENERAL_NAME, (st))
end_define

begin_define
define|#
directive|define
name|sk_GENERAL_NAME_value
parameter_list|(
name|st
parameter_list|,
name|i
parameter_list|)
value|SKM_sk_value(GENERAL_NAME, (st), (i))
end_define

begin_define
define|#
directive|define
name|sk_GENERAL_NAME_set
parameter_list|(
name|st
parameter_list|,
name|i
parameter_list|,
name|val
parameter_list|)
value|SKM_sk_set(GENERAL_NAME, (st), (i), (val))
end_define

begin_define
define|#
directive|define
name|sk_GENERAL_NAME_zero
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_zero(GENERAL_NAME, (st))
end_define

begin_define
define|#
directive|define
name|sk_GENERAL_NAME_push
parameter_list|(
name|st
parameter_list|,
name|val
parameter_list|)
value|SKM_sk_push(GENERAL_NAME, (st), (val))
end_define

begin_define
define|#
directive|define
name|sk_GENERAL_NAME_unshift
parameter_list|(
name|st
parameter_list|,
name|val
parameter_list|)
value|SKM_sk_unshift(GENERAL_NAME, (st), (val))
end_define

begin_define
define|#
directive|define
name|sk_GENERAL_NAME_find
parameter_list|(
name|st
parameter_list|,
name|val
parameter_list|)
value|SKM_sk_find(GENERAL_NAME, (st), (val))
end_define

begin_define
define|#
directive|define
name|sk_GENERAL_NAME_delete
parameter_list|(
name|st
parameter_list|,
name|i
parameter_list|)
value|SKM_sk_delete(GENERAL_NAME, (st), (i))
end_define

begin_define
define|#
directive|define
name|sk_GENERAL_NAME_delete_ptr
parameter_list|(
name|st
parameter_list|,
name|ptr
parameter_list|)
value|SKM_sk_delete_ptr(GENERAL_NAME, (st), (ptr))
end_define

begin_define
define|#
directive|define
name|sk_GENERAL_NAME_insert
parameter_list|(
name|st
parameter_list|,
name|val
parameter_list|,
name|i
parameter_list|)
value|SKM_sk_insert(GENERAL_NAME, (st), (val), (i))
end_define

begin_define
define|#
directive|define
name|sk_GENERAL_NAME_set_cmp_func
parameter_list|(
name|st
parameter_list|,
name|cmp
parameter_list|)
value|SKM_sk_set_cmp_func(GENERAL_NAME, (st), (cmp))
end_define

begin_define
define|#
directive|define
name|sk_GENERAL_NAME_dup
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_dup(GENERAL_NAME, st)
end_define

begin_define
define|#
directive|define
name|sk_GENERAL_NAME_pop_free
parameter_list|(
name|st
parameter_list|,
name|free_func
parameter_list|)
value|SKM_sk_pop_free(GENERAL_NAME, (st), (free_func))
end_define

begin_define
define|#
directive|define
name|sk_GENERAL_NAME_shift
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_shift(GENERAL_NAME, (st))
end_define

begin_define
define|#
directive|define
name|sk_GENERAL_NAME_pop
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_pop(GENERAL_NAME, (st))
end_define

begin_define
define|#
directive|define
name|sk_GENERAL_NAME_sort
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_sort(GENERAL_NAME, (st))
end_define

begin_define
define|#
directive|define
name|sk_MIME_HEADER_new
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_new(MIME_HEADER, (st))
end_define

begin_define
define|#
directive|define
name|sk_MIME_HEADER_new_null
parameter_list|()
value|SKM_sk_new_null(MIME_HEADER)
end_define

begin_define
define|#
directive|define
name|sk_MIME_HEADER_free
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_free(MIME_HEADER, (st))
end_define

begin_define
define|#
directive|define
name|sk_MIME_HEADER_num
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_num(MIME_HEADER, (st))
end_define

begin_define
define|#
directive|define
name|sk_MIME_HEADER_value
parameter_list|(
name|st
parameter_list|,
name|i
parameter_list|)
value|SKM_sk_value(MIME_HEADER, (st), (i))
end_define

begin_define
define|#
directive|define
name|sk_MIME_HEADER_set
parameter_list|(
name|st
parameter_list|,
name|i
parameter_list|,
name|val
parameter_list|)
value|SKM_sk_set(MIME_HEADER, (st), (i), (val))
end_define

begin_define
define|#
directive|define
name|sk_MIME_HEADER_zero
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_zero(MIME_HEADER, (st))
end_define

begin_define
define|#
directive|define
name|sk_MIME_HEADER_push
parameter_list|(
name|st
parameter_list|,
name|val
parameter_list|)
value|SKM_sk_push(MIME_HEADER, (st), (val))
end_define

begin_define
define|#
directive|define
name|sk_MIME_HEADER_unshift
parameter_list|(
name|st
parameter_list|,
name|val
parameter_list|)
value|SKM_sk_unshift(MIME_HEADER, (st), (val))
end_define

begin_define
define|#
directive|define
name|sk_MIME_HEADER_find
parameter_list|(
name|st
parameter_list|,
name|val
parameter_list|)
value|SKM_sk_find(MIME_HEADER, (st), (val))
end_define

begin_define
define|#
directive|define
name|sk_MIME_HEADER_delete
parameter_list|(
name|st
parameter_list|,
name|i
parameter_list|)
value|SKM_sk_delete(MIME_HEADER, (st), (i))
end_define

begin_define
define|#
directive|define
name|sk_MIME_HEADER_delete_ptr
parameter_list|(
name|st
parameter_list|,
name|ptr
parameter_list|)
value|SKM_sk_delete_ptr(MIME_HEADER, (st), (ptr))
end_define

begin_define
define|#
directive|define
name|sk_MIME_HEADER_insert
parameter_list|(
name|st
parameter_list|,
name|val
parameter_list|,
name|i
parameter_list|)
value|SKM_sk_insert(MIME_HEADER, (st), (val), (i))
end_define

begin_define
define|#
directive|define
name|sk_MIME_HEADER_set_cmp_func
parameter_list|(
name|st
parameter_list|,
name|cmp
parameter_list|)
value|SKM_sk_set_cmp_func(MIME_HEADER, (st), (cmp))
end_define

begin_define
define|#
directive|define
name|sk_MIME_HEADER_dup
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_dup(MIME_HEADER, st)
end_define

begin_define
define|#
directive|define
name|sk_MIME_HEADER_pop_free
parameter_list|(
name|st
parameter_list|,
name|free_func
parameter_list|)
value|SKM_sk_pop_free(MIME_HEADER, (st), (free_func))
end_define

begin_define
define|#
directive|define
name|sk_MIME_HEADER_shift
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_shift(MIME_HEADER, (st))
end_define

begin_define
define|#
directive|define
name|sk_MIME_HEADER_pop
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_pop(MIME_HEADER, (st))
end_define

begin_define
define|#
directive|define
name|sk_MIME_HEADER_sort
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_sort(MIME_HEADER, (st))
end_define

begin_define
define|#
directive|define
name|sk_MIME_PARAM_new
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_new(MIME_PARAM, (st))
end_define

begin_define
define|#
directive|define
name|sk_MIME_PARAM_new_null
parameter_list|()
value|SKM_sk_new_null(MIME_PARAM)
end_define

begin_define
define|#
directive|define
name|sk_MIME_PARAM_free
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_free(MIME_PARAM, (st))
end_define

begin_define
define|#
directive|define
name|sk_MIME_PARAM_num
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_num(MIME_PARAM, (st))
end_define

begin_define
define|#
directive|define
name|sk_MIME_PARAM_value
parameter_list|(
name|st
parameter_list|,
name|i
parameter_list|)
value|SKM_sk_value(MIME_PARAM, (st), (i))
end_define

begin_define
define|#
directive|define
name|sk_MIME_PARAM_set
parameter_list|(
name|st
parameter_list|,
name|i
parameter_list|,
name|val
parameter_list|)
value|SKM_sk_set(MIME_PARAM, (st), (i), (val))
end_define

begin_define
define|#
directive|define
name|sk_MIME_PARAM_zero
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_zero(MIME_PARAM, (st))
end_define

begin_define
define|#
directive|define
name|sk_MIME_PARAM_push
parameter_list|(
name|st
parameter_list|,
name|val
parameter_list|)
value|SKM_sk_push(MIME_PARAM, (st), (val))
end_define

begin_define
define|#
directive|define
name|sk_MIME_PARAM_unshift
parameter_list|(
name|st
parameter_list|,
name|val
parameter_list|)
value|SKM_sk_unshift(MIME_PARAM, (st), (val))
end_define

begin_define
define|#
directive|define
name|sk_MIME_PARAM_find
parameter_list|(
name|st
parameter_list|,
name|val
parameter_list|)
value|SKM_sk_find(MIME_PARAM, (st), (val))
end_define

begin_define
define|#
directive|define
name|sk_MIME_PARAM_delete
parameter_list|(
name|st
parameter_list|,
name|i
parameter_list|)
value|SKM_sk_delete(MIME_PARAM, (st), (i))
end_define

begin_define
define|#
directive|define
name|sk_MIME_PARAM_delete_ptr
parameter_list|(
name|st
parameter_list|,
name|ptr
parameter_list|)
value|SKM_sk_delete_ptr(MIME_PARAM, (st), (ptr))
end_define

begin_define
define|#
directive|define
name|sk_MIME_PARAM_insert
parameter_list|(
name|st
parameter_list|,
name|val
parameter_list|,
name|i
parameter_list|)
value|SKM_sk_insert(MIME_PARAM, (st), (val), (i))
end_define

begin_define
define|#
directive|define
name|sk_MIME_PARAM_set_cmp_func
parameter_list|(
name|st
parameter_list|,
name|cmp
parameter_list|)
value|SKM_sk_set_cmp_func(MIME_PARAM, (st), (cmp))
end_define

begin_define
define|#
directive|define
name|sk_MIME_PARAM_dup
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_dup(MIME_PARAM, st)
end_define

begin_define
define|#
directive|define
name|sk_MIME_PARAM_pop_free
parameter_list|(
name|st
parameter_list|,
name|free_func
parameter_list|)
value|SKM_sk_pop_free(MIME_PARAM, (st), (free_func))
end_define

begin_define
define|#
directive|define
name|sk_MIME_PARAM_shift
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_shift(MIME_PARAM, (st))
end_define

begin_define
define|#
directive|define
name|sk_MIME_PARAM_pop
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_pop(MIME_PARAM, (st))
end_define

begin_define
define|#
directive|define
name|sk_MIME_PARAM_sort
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_sort(MIME_PARAM, (st))
end_define

begin_define
define|#
directive|define
name|sk_NAME_FUNCS_new
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_new(NAME_FUNCS, (st))
end_define

begin_define
define|#
directive|define
name|sk_NAME_FUNCS_new_null
parameter_list|()
value|SKM_sk_new_null(NAME_FUNCS)
end_define

begin_define
define|#
directive|define
name|sk_NAME_FUNCS_free
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_free(NAME_FUNCS, (st))
end_define

begin_define
define|#
directive|define
name|sk_NAME_FUNCS_num
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_num(NAME_FUNCS, (st))
end_define

begin_define
define|#
directive|define
name|sk_NAME_FUNCS_value
parameter_list|(
name|st
parameter_list|,
name|i
parameter_list|)
value|SKM_sk_value(NAME_FUNCS, (st), (i))
end_define

begin_define
define|#
directive|define
name|sk_NAME_FUNCS_set
parameter_list|(
name|st
parameter_list|,
name|i
parameter_list|,
name|val
parameter_list|)
value|SKM_sk_set(NAME_FUNCS, (st), (i), (val))
end_define

begin_define
define|#
directive|define
name|sk_NAME_FUNCS_zero
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_zero(NAME_FUNCS, (st))
end_define

begin_define
define|#
directive|define
name|sk_NAME_FUNCS_push
parameter_list|(
name|st
parameter_list|,
name|val
parameter_list|)
value|SKM_sk_push(NAME_FUNCS, (st), (val))
end_define

begin_define
define|#
directive|define
name|sk_NAME_FUNCS_unshift
parameter_list|(
name|st
parameter_list|,
name|val
parameter_list|)
value|SKM_sk_unshift(NAME_FUNCS, (st), (val))
end_define

begin_define
define|#
directive|define
name|sk_NAME_FUNCS_find
parameter_list|(
name|st
parameter_list|,
name|val
parameter_list|)
value|SKM_sk_find(NAME_FUNCS, (st), (val))
end_define

begin_define
define|#
directive|define
name|sk_NAME_FUNCS_delete
parameter_list|(
name|st
parameter_list|,
name|i
parameter_list|)
value|SKM_sk_delete(NAME_FUNCS, (st), (i))
end_define

begin_define
define|#
directive|define
name|sk_NAME_FUNCS_delete_ptr
parameter_list|(
name|st
parameter_list|,
name|ptr
parameter_list|)
value|SKM_sk_delete_ptr(NAME_FUNCS, (st), (ptr))
end_define

begin_define
define|#
directive|define
name|sk_NAME_FUNCS_insert
parameter_list|(
name|st
parameter_list|,
name|val
parameter_list|,
name|i
parameter_list|)
value|SKM_sk_insert(NAME_FUNCS, (st), (val), (i))
end_define

begin_define
define|#
directive|define
name|sk_NAME_FUNCS_set_cmp_func
parameter_list|(
name|st
parameter_list|,
name|cmp
parameter_list|)
value|SKM_sk_set_cmp_func(NAME_FUNCS, (st), (cmp))
end_define

begin_define
define|#
directive|define
name|sk_NAME_FUNCS_dup
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_dup(NAME_FUNCS, st)
end_define

begin_define
define|#
directive|define
name|sk_NAME_FUNCS_pop_free
parameter_list|(
name|st
parameter_list|,
name|free_func
parameter_list|)
value|SKM_sk_pop_free(NAME_FUNCS, (st), (free_func))
end_define

begin_define
define|#
directive|define
name|sk_NAME_FUNCS_shift
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_shift(NAME_FUNCS, (st))
end_define

begin_define
define|#
directive|define
name|sk_NAME_FUNCS_pop
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_pop(NAME_FUNCS, (st))
end_define

begin_define
define|#
directive|define
name|sk_NAME_FUNCS_sort
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_sort(NAME_FUNCS, (st))
end_define

begin_define
define|#
directive|define
name|sk_PKCS12_SAFEBAG_new
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_new(PKCS12_SAFEBAG, (st))
end_define

begin_define
define|#
directive|define
name|sk_PKCS12_SAFEBAG_new_null
parameter_list|()
value|SKM_sk_new_null(PKCS12_SAFEBAG)
end_define

begin_define
define|#
directive|define
name|sk_PKCS12_SAFEBAG_free
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_free(PKCS12_SAFEBAG, (st))
end_define

begin_define
define|#
directive|define
name|sk_PKCS12_SAFEBAG_num
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_num(PKCS12_SAFEBAG, (st))
end_define

begin_define
define|#
directive|define
name|sk_PKCS12_SAFEBAG_value
parameter_list|(
name|st
parameter_list|,
name|i
parameter_list|)
value|SKM_sk_value(PKCS12_SAFEBAG, (st), (i))
end_define

begin_define
define|#
directive|define
name|sk_PKCS12_SAFEBAG_set
parameter_list|(
name|st
parameter_list|,
name|i
parameter_list|,
name|val
parameter_list|)
value|SKM_sk_set(PKCS12_SAFEBAG, (st), (i), (val))
end_define

begin_define
define|#
directive|define
name|sk_PKCS12_SAFEBAG_zero
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_zero(PKCS12_SAFEBAG, (st))
end_define

begin_define
define|#
directive|define
name|sk_PKCS12_SAFEBAG_push
parameter_list|(
name|st
parameter_list|,
name|val
parameter_list|)
value|SKM_sk_push(PKCS12_SAFEBAG, (st), (val))
end_define

begin_define
define|#
directive|define
name|sk_PKCS12_SAFEBAG_unshift
parameter_list|(
name|st
parameter_list|,
name|val
parameter_list|)
value|SKM_sk_unshift(PKCS12_SAFEBAG, (st), (val))
end_define

begin_define
define|#
directive|define
name|sk_PKCS12_SAFEBAG_find
parameter_list|(
name|st
parameter_list|,
name|val
parameter_list|)
value|SKM_sk_find(PKCS12_SAFEBAG, (st), (val))
end_define

begin_define
define|#
directive|define
name|sk_PKCS12_SAFEBAG_delete
parameter_list|(
name|st
parameter_list|,
name|i
parameter_list|)
value|SKM_sk_delete(PKCS12_SAFEBAG, (st), (i))
end_define

begin_define
define|#
directive|define
name|sk_PKCS12_SAFEBAG_delete_ptr
parameter_list|(
name|st
parameter_list|,
name|ptr
parameter_list|)
value|SKM_sk_delete_ptr(PKCS12_SAFEBAG, (st), (ptr))
end_define

begin_define
define|#
directive|define
name|sk_PKCS12_SAFEBAG_insert
parameter_list|(
name|st
parameter_list|,
name|val
parameter_list|,
name|i
parameter_list|)
value|SKM_sk_insert(PKCS12_SAFEBAG, (st), (val), (i))
end_define

begin_define
define|#
directive|define
name|sk_PKCS12_SAFEBAG_set_cmp_func
parameter_list|(
name|st
parameter_list|,
name|cmp
parameter_list|)
value|SKM_sk_set_cmp_func(PKCS12_SAFEBAG, (st), (cmp))
end_define

begin_define
define|#
directive|define
name|sk_PKCS12_SAFEBAG_dup
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_dup(PKCS12_SAFEBAG, st)
end_define

begin_define
define|#
directive|define
name|sk_PKCS12_SAFEBAG_pop_free
parameter_list|(
name|st
parameter_list|,
name|free_func
parameter_list|)
value|SKM_sk_pop_free(PKCS12_SAFEBAG, (st), (free_func))
end_define

begin_define
define|#
directive|define
name|sk_PKCS12_SAFEBAG_shift
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_shift(PKCS12_SAFEBAG, (st))
end_define

begin_define
define|#
directive|define
name|sk_PKCS12_SAFEBAG_pop
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_pop(PKCS12_SAFEBAG, (st))
end_define

begin_define
define|#
directive|define
name|sk_PKCS12_SAFEBAG_sort
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_sort(PKCS12_SAFEBAG, (st))
end_define

begin_define
define|#
directive|define
name|sk_PKCS7_new
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_new(PKCS7, (st))
end_define

begin_define
define|#
directive|define
name|sk_PKCS7_new_null
parameter_list|()
value|SKM_sk_new_null(PKCS7)
end_define

begin_define
define|#
directive|define
name|sk_PKCS7_free
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_free(PKCS7, (st))
end_define

begin_define
define|#
directive|define
name|sk_PKCS7_num
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_num(PKCS7, (st))
end_define

begin_define
define|#
directive|define
name|sk_PKCS7_value
parameter_list|(
name|st
parameter_list|,
name|i
parameter_list|)
value|SKM_sk_value(PKCS7, (st), (i))
end_define

begin_define
define|#
directive|define
name|sk_PKCS7_set
parameter_list|(
name|st
parameter_list|,
name|i
parameter_list|,
name|val
parameter_list|)
value|SKM_sk_set(PKCS7, (st), (i), (val))
end_define

begin_define
define|#
directive|define
name|sk_PKCS7_zero
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_zero(PKCS7, (st))
end_define

begin_define
define|#
directive|define
name|sk_PKCS7_push
parameter_list|(
name|st
parameter_list|,
name|val
parameter_list|)
value|SKM_sk_push(PKCS7, (st), (val))
end_define

begin_define
define|#
directive|define
name|sk_PKCS7_unshift
parameter_list|(
name|st
parameter_list|,
name|val
parameter_list|)
value|SKM_sk_unshift(PKCS7, (st), (val))
end_define

begin_define
define|#
directive|define
name|sk_PKCS7_find
parameter_list|(
name|st
parameter_list|,
name|val
parameter_list|)
value|SKM_sk_find(PKCS7, (st), (val))
end_define

begin_define
define|#
directive|define
name|sk_PKCS7_delete
parameter_list|(
name|st
parameter_list|,
name|i
parameter_list|)
value|SKM_sk_delete(PKCS7, (st), (i))
end_define

begin_define
define|#
directive|define
name|sk_PKCS7_delete_ptr
parameter_list|(
name|st
parameter_list|,
name|ptr
parameter_list|)
value|SKM_sk_delete_ptr(PKCS7, (st), (ptr))
end_define

begin_define
define|#
directive|define
name|sk_PKCS7_insert
parameter_list|(
name|st
parameter_list|,
name|val
parameter_list|,
name|i
parameter_list|)
value|SKM_sk_insert(PKCS7, (st), (val), (i))
end_define

begin_define
define|#
directive|define
name|sk_PKCS7_set_cmp_func
parameter_list|(
name|st
parameter_list|,
name|cmp
parameter_list|)
value|SKM_sk_set_cmp_func(PKCS7, (st), (cmp))
end_define

begin_define
define|#
directive|define
name|sk_PKCS7_dup
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_dup(PKCS7, st)
end_define

begin_define
define|#
directive|define
name|sk_PKCS7_pop_free
parameter_list|(
name|st
parameter_list|,
name|free_func
parameter_list|)
value|SKM_sk_pop_free(PKCS7, (st), (free_func))
end_define

begin_define
define|#
directive|define
name|sk_PKCS7_shift
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_shift(PKCS7, (st))
end_define

begin_define
define|#
directive|define
name|sk_PKCS7_pop
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_pop(PKCS7, (st))
end_define

begin_define
define|#
directive|define
name|sk_PKCS7_sort
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_sort(PKCS7, (st))
end_define

begin_define
define|#
directive|define
name|sk_PKCS7_RECIP_INFO_new
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_new(PKCS7_RECIP_INFO, (st))
end_define

begin_define
define|#
directive|define
name|sk_PKCS7_RECIP_INFO_new_null
parameter_list|()
value|SKM_sk_new_null(PKCS7_RECIP_INFO)
end_define

begin_define
define|#
directive|define
name|sk_PKCS7_RECIP_INFO_free
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_free(PKCS7_RECIP_INFO, (st))
end_define

begin_define
define|#
directive|define
name|sk_PKCS7_RECIP_INFO_num
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_num(PKCS7_RECIP_INFO, (st))
end_define

begin_define
define|#
directive|define
name|sk_PKCS7_RECIP_INFO_value
parameter_list|(
name|st
parameter_list|,
name|i
parameter_list|)
value|SKM_sk_value(PKCS7_RECIP_INFO, (st), (i))
end_define

begin_define
define|#
directive|define
name|sk_PKCS7_RECIP_INFO_set
parameter_list|(
name|st
parameter_list|,
name|i
parameter_list|,
name|val
parameter_list|)
value|SKM_sk_set(PKCS7_RECIP_INFO, (st), (i), (val))
end_define

begin_define
define|#
directive|define
name|sk_PKCS7_RECIP_INFO_zero
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_zero(PKCS7_RECIP_INFO, (st))
end_define

begin_define
define|#
directive|define
name|sk_PKCS7_RECIP_INFO_push
parameter_list|(
name|st
parameter_list|,
name|val
parameter_list|)
value|SKM_sk_push(PKCS7_RECIP_INFO, (st), (val))
end_define

begin_define
define|#
directive|define
name|sk_PKCS7_RECIP_INFO_unshift
parameter_list|(
name|st
parameter_list|,
name|val
parameter_list|)
value|SKM_sk_unshift(PKCS7_RECIP_INFO, (st), (val))
end_define

begin_define
define|#
directive|define
name|sk_PKCS7_RECIP_INFO_find
parameter_list|(
name|st
parameter_list|,
name|val
parameter_list|)
value|SKM_sk_find(PKCS7_RECIP_INFO, (st), (val))
end_define

begin_define
define|#
directive|define
name|sk_PKCS7_RECIP_INFO_delete
parameter_list|(
name|st
parameter_list|,
name|i
parameter_list|)
value|SKM_sk_delete(PKCS7_RECIP_INFO, (st), (i))
end_define

begin_define
define|#
directive|define
name|sk_PKCS7_RECIP_INFO_delete_ptr
parameter_list|(
name|st
parameter_list|,
name|ptr
parameter_list|)
value|SKM_sk_delete_ptr(PKCS7_RECIP_INFO, (st), (ptr))
end_define

begin_define
define|#
directive|define
name|sk_PKCS7_RECIP_INFO_insert
parameter_list|(
name|st
parameter_list|,
name|val
parameter_list|,
name|i
parameter_list|)
value|SKM_sk_insert(PKCS7_RECIP_INFO, (st), (val), (i))
end_define

begin_define
define|#
directive|define
name|sk_PKCS7_RECIP_INFO_set_cmp_func
parameter_list|(
name|st
parameter_list|,
name|cmp
parameter_list|)
value|SKM_sk_set_cmp_func(PKCS7_RECIP_INFO, (st), (cmp))
end_define

begin_define
define|#
directive|define
name|sk_PKCS7_RECIP_INFO_dup
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_dup(PKCS7_RECIP_INFO, st)
end_define

begin_define
define|#
directive|define
name|sk_PKCS7_RECIP_INFO_pop_free
parameter_list|(
name|st
parameter_list|,
name|free_func
parameter_list|)
value|SKM_sk_pop_free(PKCS7_RECIP_INFO, (st), (free_func))
end_define

begin_define
define|#
directive|define
name|sk_PKCS7_RECIP_INFO_shift
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_shift(PKCS7_RECIP_INFO, (st))
end_define

begin_define
define|#
directive|define
name|sk_PKCS7_RECIP_INFO_pop
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_pop(PKCS7_RECIP_INFO, (st))
end_define

begin_define
define|#
directive|define
name|sk_PKCS7_RECIP_INFO_sort
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_sort(PKCS7_RECIP_INFO, (st))
end_define

begin_define
define|#
directive|define
name|sk_PKCS7_SIGNER_INFO_new
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_new(PKCS7_SIGNER_INFO, (st))
end_define

begin_define
define|#
directive|define
name|sk_PKCS7_SIGNER_INFO_new_null
parameter_list|()
value|SKM_sk_new_null(PKCS7_SIGNER_INFO)
end_define

begin_define
define|#
directive|define
name|sk_PKCS7_SIGNER_INFO_free
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_free(PKCS7_SIGNER_INFO, (st))
end_define

begin_define
define|#
directive|define
name|sk_PKCS7_SIGNER_INFO_num
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_num(PKCS7_SIGNER_INFO, (st))
end_define

begin_define
define|#
directive|define
name|sk_PKCS7_SIGNER_INFO_value
parameter_list|(
name|st
parameter_list|,
name|i
parameter_list|)
value|SKM_sk_value(PKCS7_SIGNER_INFO, (st), (i))
end_define

begin_define
define|#
directive|define
name|sk_PKCS7_SIGNER_INFO_set
parameter_list|(
name|st
parameter_list|,
name|i
parameter_list|,
name|val
parameter_list|)
value|SKM_sk_set(PKCS7_SIGNER_INFO, (st), (i), (val))
end_define

begin_define
define|#
directive|define
name|sk_PKCS7_SIGNER_INFO_zero
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_zero(PKCS7_SIGNER_INFO, (st))
end_define

begin_define
define|#
directive|define
name|sk_PKCS7_SIGNER_INFO_push
parameter_list|(
name|st
parameter_list|,
name|val
parameter_list|)
value|SKM_sk_push(PKCS7_SIGNER_INFO, (st), (val))
end_define

begin_define
define|#
directive|define
name|sk_PKCS7_SIGNER_INFO_unshift
parameter_list|(
name|st
parameter_list|,
name|val
parameter_list|)
value|SKM_sk_unshift(PKCS7_SIGNER_INFO, (st), (val))
end_define

begin_define
define|#
directive|define
name|sk_PKCS7_SIGNER_INFO_find
parameter_list|(
name|st
parameter_list|,
name|val
parameter_list|)
value|SKM_sk_find(PKCS7_SIGNER_INFO, (st), (val))
end_define

begin_define
define|#
directive|define
name|sk_PKCS7_SIGNER_INFO_delete
parameter_list|(
name|st
parameter_list|,
name|i
parameter_list|)
value|SKM_sk_delete(PKCS7_SIGNER_INFO, (st), (i))
end_define

begin_define
define|#
directive|define
name|sk_PKCS7_SIGNER_INFO_delete_ptr
parameter_list|(
name|st
parameter_list|,
name|ptr
parameter_list|)
value|SKM_sk_delete_ptr(PKCS7_SIGNER_INFO, (st), (ptr))
end_define

begin_define
define|#
directive|define
name|sk_PKCS7_SIGNER_INFO_insert
parameter_list|(
name|st
parameter_list|,
name|val
parameter_list|,
name|i
parameter_list|)
value|SKM_sk_insert(PKCS7_SIGNER_INFO, (st), (val), (i))
end_define

begin_define
define|#
directive|define
name|sk_PKCS7_SIGNER_INFO_set_cmp_func
parameter_list|(
name|st
parameter_list|,
name|cmp
parameter_list|)
value|SKM_sk_set_cmp_func(PKCS7_SIGNER_INFO, (st), (cmp))
end_define

begin_define
define|#
directive|define
name|sk_PKCS7_SIGNER_INFO_dup
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_dup(PKCS7_SIGNER_INFO, st)
end_define

begin_define
define|#
directive|define
name|sk_PKCS7_SIGNER_INFO_pop_free
parameter_list|(
name|st
parameter_list|,
name|free_func
parameter_list|)
value|SKM_sk_pop_free(PKCS7_SIGNER_INFO, (st), (free_func))
end_define

begin_define
define|#
directive|define
name|sk_PKCS7_SIGNER_INFO_shift
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_shift(PKCS7_SIGNER_INFO, (st))
end_define

begin_define
define|#
directive|define
name|sk_PKCS7_SIGNER_INFO_pop
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_pop(PKCS7_SIGNER_INFO, (st))
end_define

begin_define
define|#
directive|define
name|sk_PKCS7_SIGNER_INFO_sort
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_sort(PKCS7_SIGNER_INFO, (st))
end_define

begin_define
define|#
directive|define
name|sk_POLICYINFO_new
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_new(POLICYINFO, (st))
end_define

begin_define
define|#
directive|define
name|sk_POLICYINFO_new_null
parameter_list|()
value|SKM_sk_new_null(POLICYINFO)
end_define

begin_define
define|#
directive|define
name|sk_POLICYINFO_free
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_free(POLICYINFO, (st))
end_define

begin_define
define|#
directive|define
name|sk_POLICYINFO_num
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_num(POLICYINFO, (st))
end_define

begin_define
define|#
directive|define
name|sk_POLICYINFO_value
parameter_list|(
name|st
parameter_list|,
name|i
parameter_list|)
value|SKM_sk_value(POLICYINFO, (st), (i))
end_define

begin_define
define|#
directive|define
name|sk_POLICYINFO_set
parameter_list|(
name|st
parameter_list|,
name|i
parameter_list|,
name|val
parameter_list|)
value|SKM_sk_set(POLICYINFO, (st), (i), (val))
end_define

begin_define
define|#
directive|define
name|sk_POLICYINFO_zero
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_zero(POLICYINFO, (st))
end_define

begin_define
define|#
directive|define
name|sk_POLICYINFO_push
parameter_list|(
name|st
parameter_list|,
name|val
parameter_list|)
value|SKM_sk_push(POLICYINFO, (st), (val))
end_define

begin_define
define|#
directive|define
name|sk_POLICYINFO_unshift
parameter_list|(
name|st
parameter_list|,
name|val
parameter_list|)
value|SKM_sk_unshift(POLICYINFO, (st), (val))
end_define

begin_define
define|#
directive|define
name|sk_POLICYINFO_find
parameter_list|(
name|st
parameter_list|,
name|val
parameter_list|)
value|SKM_sk_find(POLICYINFO, (st), (val))
end_define

begin_define
define|#
directive|define
name|sk_POLICYINFO_delete
parameter_list|(
name|st
parameter_list|,
name|i
parameter_list|)
value|SKM_sk_delete(POLICYINFO, (st), (i))
end_define

begin_define
define|#
directive|define
name|sk_POLICYINFO_delete_ptr
parameter_list|(
name|st
parameter_list|,
name|ptr
parameter_list|)
value|SKM_sk_delete_ptr(POLICYINFO, (st), (ptr))
end_define

begin_define
define|#
directive|define
name|sk_POLICYINFO_insert
parameter_list|(
name|st
parameter_list|,
name|val
parameter_list|,
name|i
parameter_list|)
value|SKM_sk_insert(POLICYINFO, (st), (val), (i))
end_define

begin_define
define|#
directive|define
name|sk_POLICYINFO_set_cmp_func
parameter_list|(
name|st
parameter_list|,
name|cmp
parameter_list|)
value|SKM_sk_set_cmp_func(POLICYINFO, (st), (cmp))
end_define

begin_define
define|#
directive|define
name|sk_POLICYINFO_dup
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_dup(POLICYINFO, st)
end_define

begin_define
define|#
directive|define
name|sk_POLICYINFO_pop_free
parameter_list|(
name|st
parameter_list|,
name|free_func
parameter_list|)
value|SKM_sk_pop_free(POLICYINFO, (st), (free_func))
end_define

begin_define
define|#
directive|define
name|sk_POLICYINFO_shift
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_shift(POLICYINFO, (st))
end_define

begin_define
define|#
directive|define
name|sk_POLICYINFO_pop
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_pop(POLICYINFO, (st))
end_define

begin_define
define|#
directive|define
name|sk_POLICYINFO_sort
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_sort(POLICYINFO, (st))
end_define

begin_define
define|#
directive|define
name|sk_POLICYQUALINFO_new
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_new(POLICYQUALINFO, (st))
end_define

begin_define
define|#
directive|define
name|sk_POLICYQUALINFO_new_null
parameter_list|()
value|SKM_sk_new_null(POLICYQUALINFO)
end_define

begin_define
define|#
directive|define
name|sk_POLICYQUALINFO_free
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_free(POLICYQUALINFO, (st))
end_define

begin_define
define|#
directive|define
name|sk_POLICYQUALINFO_num
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_num(POLICYQUALINFO, (st))
end_define

begin_define
define|#
directive|define
name|sk_POLICYQUALINFO_value
parameter_list|(
name|st
parameter_list|,
name|i
parameter_list|)
value|SKM_sk_value(POLICYQUALINFO, (st), (i))
end_define

begin_define
define|#
directive|define
name|sk_POLICYQUALINFO_set
parameter_list|(
name|st
parameter_list|,
name|i
parameter_list|,
name|val
parameter_list|)
value|SKM_sk_set(POLICYQUALINFO, (st), (i), (val))
end_define

begin_define
define|#
directive|define
name|sk_POLICYQUALINFO_zero
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_zero(POLICYQUALINFO, (st))
end_define

begin_define
define|#
directive|define
name|sk_POLICYQUALINFO_push
parameter_list|(
name|st
parameter_list|,
name|val
parameter_list|)
value|SKM_sk_push(POLICYQUALINFO, (st), (val))
end_define

begin_define
define|#
directive|define
name|sk_POLICYQUALINFO_unshift
parameter_list|(
name|st
parameter_list|,
name|val
parameter_list|)
value|SKM_sk_unshift(POLICYQUALINFO, (st), (val))
end_define

begin_define
define|#
directive|define
name|sk_POLICYQUALINFO_find
parameter_list|(
name|st
parameter_list|,
name|val
parameter_list|)
value|SKM_sk_find(POLICYQUALINFO, (st), (val))
end_define

begin_define
define|#
directive|define
name|sk_POLICYQUALINFO_delete
parameter_list|(
name|st
parameter_list|,
name|i
parameter_list|)
value|SKM_sk_delete(POLICYQUALINFO, (st), (i))
end_define

begin_define
define|#
directive|define
name|sk_POLICYQUALINFO_delete_ptr
parameter_list|(
name|st
parameter_list|,
name|ptr
parameter_list|)
value|SKM_sk_delete_ptr(POLICYQUALINFO, (st), (ptr))
end_define

begin_define
define|#
directive|define
name|sk_POLICYQUALINFO_insert
parameter_list|(
name|st
parameter_list|,
name|val
parameter_list|,
name|i
parameter_list|)
value|SKM_sk_insert(POLICYQUALINFO, (st), (val), (i))
end_define

begin_define
define|#
directive|define
name|sk_POLICYQUALINFO_set_cmp_func
parameter_list|(
name|st
parameter_list|,
name|cmp
parameter_list|)
value|SKM_sk_set_cmp_func(POLICYQUALINFO, (st), (cmp))
end_define

begin_define
define|#
directive|define
name|sk_POLICYQUALINFO_dup
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_dup(POLICYQUALINFO, st)
end_define

begin_define
define|#
directive|define
name|sk_POLICYQUALINFO_pop_free
parameter_list|(
name|st
parameter_list|,
name|free_func
parameter_list|)
value|SKM_sk_pop_free(POLICYQUALINFO, (st), (free_func))
end_define

begin_define
define|#
directive|define
name|sk_POLICYQUALINFO_shift
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_shift(POLICYQUALINFO, (st))
end_define

begin_define
define|#
directive|define
name|sk_POLICYQUALINFO_pop
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_pop(POLICYQUALINFO, (st))
end_define

begin_define
define|#
directive|define
name|sk_POLICYQUALINFO_sort
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_sort(POLICYQUALINFO, (st))
end_define

begin_define
define|#
directive|define
name|sk_SSL_CIPHER_new
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_new(SSL_CIPHER, (st))
end_define

begin_define
define|#
directive|define
name|sk_SSL_CIPHER_new_null
parameter_list|()
value|SKM_sk_new_null(SSL_CIPHER)
end_define

begin_define
define|#
directive|define
name|sk_SSL_CIPHER_free
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_free(SSL_CIPHER, (st))
end_define

begin_define
define|#
directive|define
name|sk_SSL_CIPHER_num
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_num(SSL_CIPHER, (st))
end_define

begin_define
define|#
directive|define
name|sk_SSL_CIPHER_value
parameter_list|(
name|st
parameter_list|,
name|i
parameter_list|)
value|SKM_sk_value(SSL_CIPHER, (st), (i))
end_define

begin_define
define|#
directive|define
name|sk_SSL_CIPHER_set
parameter_list|(
name|st
parameter_list|,
name|i
parameter_list|,
name|val
parameter_list|)
value|SKM_sk_set(SSL_CIPHER, (st), (i), (val))
end_define

begin_define
define|#
directive|define
name|sk_SSL_CIPHER_zero
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_zero(SSL_CIPHER, (st))
end_define

begin_define
define|#
directive|define
name|sk_SSL_CIPHER_push
parameter_list|(
name|st
parameter_list|,
name|val
parameter_list|)
value|SKM_sk_push(SSL_CIPHER, (st), (val))
end_define

begin_define
define|#
directive|define
name|sk_SSL_CIPHER_unshift
parameter_list|(
name|st
parameter_list|,
name|val
parameter_list|)
value|SKM_sk_unshift(SSL_CIPHER, (st), (val))
end_define

begin_define
define|#
directive|define
name|sk_SSL_CIPHER_find
parameter_list|(
name|st
parameter_list|,
name|val
parameter_list|)
value|SKM_sk_find(SSL_CIPHER, (st), (val))
end_define

begin_define
define|#
directive|define
name|sk_SSL_CIPHER_delete
parameter_list|(
name|st
parameter_list|,
name|i
parameter_list|)
value|SKM_sk_delete(SSL_CIPHER, (st), (i))
end_define

begin_define
define|#
directive|define
name|sk_SSL_CIPHER_delete_ptr
parameter_list|(
name|st
parameter_list|,
name|ptr
parameter_list|)
value|SKM_sk_delete_ptr(SSL_CIPHER, (st), (ptr))
end_define

begin_define
define|#
directive|define
name|sk_SSL_CIPHER_insert
parameter_list|(
name|st
parameter_list|,
name|val
parameter_list|,
name|i
parameter_list|)
value|SKM_sk_insert(SSL_CIPHER, (st), (val), (i))
end_define

begin_define
define|#
directive|define
name|sk_SSL_CIPHER_set_cmp_func
parameter_list|(
name|st
parameter_list|,
name|cmp
parameter_list|)
value|SKM_sk_set_cmp_func(SSL_CIPHER, (st), (cmp))
end_define

begin_define
define|#
directive|define
name|sk_SSL_CIPHER_dup
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_dup(SSL_CIPHER, st)
end_define

begin_define
define|#
directive|define
name|sk_SSL_CIPHER_pop_free
parameter_list|(
name|st
parameter_list|,
name|free_func
parameter_list|)
value|SKM_sk_pop_free(SSL_CIPHER, (st), (free_func))
end_define

begin_define
define|#
directive|define
name|sk_SSL_CIPHER_shift
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_shift(SSL_CIPHER, (st))
end_define

begin_define
define|#
directive|define
name|sk_SSL_CIPHER_pop
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_pop(SSL_CIPHER, (st))
end_define

begin_define
define|#
directive|define
name|sk_SSL_CIPHER_sort
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_sort(SSL_CIPHER, (st))
end_define

begin_define
define|#
directive|define
name|sk_SSL_COMP_new
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_new(SSL_COMP, (st))
end_define

begin_define
define|#
directive|define
name|sk_SSL_COMP_new_null
parameter_list|()
value|SKM_sk_new_null(SSL_COMP)
end_define

begin_define
define|#
directive|define
name|sk_SSL_COMP_free
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_free(SSL_COMP, (st))
end_define

begin_define
define|#
directive|define
name|sk_SSL_COMP_num
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_num(SSL_COMP, (st))
end_define

begin_define
define|#
directive|define
name|sk_SSL_COMP_value
parameter_list|(
name|st
parameter_list|,
name|i
parameter_list|)
value|SKM_sk_value(SSL_COMP, (st), (i))
end_define

begin_define
define|#
directive|define
name|sk_SSL_COMP_set
parameter_list|(
name|st
parameter_list|,
name|i
parameter_list|,
name|val
parameter_list|)
value|SKM_sk_set(SSL_COMP, (st), (i), (val))
end_define

begin_define
define|#
directive|define
name|sk_SSL_COMP_zero
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_zero(SSL_COMP, (st))
end_define

begin_define
define|#
directive|define
name|sk_SSL_COMP_push
parameter_list|(
name|st
parameter_list|,
name|val
parameter_list|)
value|SKM_sk_push(SSL_COMP, (st), (val))
end_define

begin_define
define|#
directive|define
name|sk_SSL_COMP_unshift
parameter_list|(
name|st
parameter_list|,
name|val
parameter_list|)
value|SKM_sk_unshift(SSL_COMP, (st), (val))
end_define

begin_define
define|#
directive|define
name|sk_SSL_COMP_find
parameter_list|(
name|st
parameter_list|,
name|val
parameter_list|)
value|SKM_sk_find(SSL_COMP, (st), (val))
end_define

begin_define
define|#
directive|define
name|sk_SSL_COMP_delete
parameter_list|(
name|st
parameter_list|,
name|i
parameter_list|)
value|SKM_sk_delete(SSL_COMP, (st), (i))
end_define

begin_define
define|#
directive|define
name|sk_SSL_COMP_delete_ptr
parameter_list|(
name|st
parameter_list|,
name|ptr
parameter_list|)
value|SKM_sk_delete_ptr(SSL_COMP, (st), (ptr))
end_define

begin_define
define|#
directive|define
name|sk_SSL_COMP_insert
parameter_list|(
name|st
parameter_list|,
name|val
parameter_list|,
name|i
parameter_list|)
value|SKM_sk_insert(SSL_COMP, (st), (val), (i))
end_define

begin_define
define|#
directive|define
name|sk_SSL_COMP_set_cmp_func
parameter_list|(
name|st
parameter_list|,
name|cmp
parameter_list|)
value|SKM_sk_set_cmp_func(SSL_COMP, (st), (cmp))
end_define

begin_define
define|#
directive|define
name|sk_SSL_COMP_dup
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_dup(SSL_COMP, st)
end_define

begin_define
define|#
directive|define
name|sk_SSL_COMP_pop_free
parameter_list|(
name|st
parameter_list|,
name|free_func
parameter_list|)
value|SKM_sk_pop_free(SSL_COMP, (st), (free_func))
end_define

begin_define
define|#
directive|define
name|sk_SSL_COMP_shift
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_shift(SSL_COMP, (st))
end_define

begin_define
define|#
directive|define
name|sk_SSL_COMP_pop
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_pop(SSL_COMP, (st))
end_define

begin_define
define|#
directive|define
name|sk_SSL_COMP_sort
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_sort(SSL_COMP, (st))
end_define

begin_define
define|#
directive|define
name|sk_SXNETID_new
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_new(SXNETID, (st))
end_define

begin_define
define|#
directive|define
name|sk_SXNETID_new_null
parameter_list|()
value|SKM_sk_new_null(SXNETID)
end_define

begin_define
define|#
directive|define
name|sk_SXNETID_free
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_free(SXNETID, (st))
end_define

begin_define
define|#
directive|define
name|sk_SXNETID_num
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_num(SXNETID, (st))
end_define

begin_define
define|#
directive|define
name|sk_SXNETID_value
parameter_list|(
name|st
parameter_list|,
name|i
parameter_list|)
value|SKM_sk_value(SXNETID, (st), (i))
end_define

begin_define
define|#
directive|define
name|sk_SXNETID_set
parameter_list|(
name|st
parameter_list|,
name|i
parameter_list|,
name|val
parameter_list|)
value|SKM_sk_set(SXNETID, (st), (i), (val))
end_define

begin_define
define|#
directive|define
name|sk_SXNETID_zero
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_zero(SXNETID, (st))
end_define

begin_define
define|#
directive|define
name|sk_SXNETID_push
parameter_list|(
name|st
parameter_list|,
name|val
parameter_list|)
value|SKM_sk_push(SXNETID, (st), (val))
end_define

begin_define
define|#
directive|define
name|sk_SXNETID_unshift
parameter_list|(
name|st
parameter_list|,
name|val
parameter_list|)
value|SKM_sk_unshift(SXNETID, (st), (val))
end_define

begin_define
define|#
directive|define
name|sk_SXNETID_find
parameter_list|(
name|st
parameter_list|,
name|val
parameter_list|)
value|SKM_sk_find(SXNETID, (st), (val))
end_define

begin_define
define|#
directive|define
name|sk_SXNETID_delete
parameter_list|(
name|st
parameter_list|,
name|i
parameter_list|)
value|SKM_sk_delete(SXNETID, (st), (i))
end_define

begin_define
define|#
directive|define
name|sk_SXNETID_delete_ptr
parameter_list|(
name|st
parameter_list|,
name|ptr
parameter_list|)
value|SKM_sk_delete_ptr(SXNETID, (st), (ptr))
end_define

begin_define
define|#
directive|define
name|sk_SXNETID_insert
parameter_list|(
name|st
parameter_list|,
name|val
parameter_list|,
name|i
parameter_list|)
value|SKM_sk_insert(SXNETID, (st), (val), (i))
end_define

begin_define
define|#
directive|define
name|sk_SXNETID_set_cmp_func
parameter_list|(
name|st
parameter_list|,
name|cmp
parameter_list|)
value|SKM_sk_set_cmp_func(SXNETID, (st), (cmp))
end_define

begin_define
define|#
directive|define
name|sk_SXNETID_dup
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_dup(SXNETID, st)
end_define

begin_define
define|#
directive|define
name|sk_SXNETID_pop_free
parameter_list|(
name|st
parameter_list|,
name|free_func
parameter_list|)
value|SKM_sk_pop_free(SXNETID, (st), (free_func))
end_define

begin_define
define|#
directive|define
name|sk_SXNETID_shift
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_shift(SXNETID, (st))
end_define

begin_define
define|#
directive|define
name|sk_SXNETID_pop
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_pop(SXNETID, (st))
end_define

begin_define
define|#
directive|define
name|sk_SXNETID_sort
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_sort(SXNETID, (st))
end_define

begin_define
define|#
directive|define
name|sk_X509_new
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_new(X509, (st))
end_define

begin_define
define|#
directive|define
name|sk_X509_new_null
parameter_list|()
value|SKM_sk_new_null(X509)
end_define

begin_define
define|#
directive|define
name|sk_X509_free
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_free(X509, (st))
end_define

begin_define
define|#
directive|define
name|sk_X509_num
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_num(X509, (st))
end_define

begin_define
define|#
directive|define
name|sk_X509_value
parameter_list|(
name|st
parameter_list|,
name|i
parameter_list|)
value|SKM_sk_value(X509, (st), (i))
end_define

begin_define
define|#
directive|define
name|sk_X509_set
parameter_list|(
name|st
parameter_list|,
name|i
parameter_list|,
name|val
parameter_list|)
value|SKM_sk_set(X509, (st), (i), (val))
end_define

begin_define
define|#
directive|define
name|sk_X509_zero
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_zero(X509, (st))
end_define

begin_define
define|#
directive|define
name|sk_X509_push
parameter_list|(
name|st
parameter_list|,
name|val
parameter_list|)
value|SKM_sk_push(X509, (st), (val))
end_define

begin_define
define|#
directive|define
name|sk_X509_unshift
parameter_list|(
name|st
parameter_list|,
name|val
parameter_list|)
value|SKM_sk_unshift(X509, (st), (val))
end_define

begin_define
define|#
directive|define
name|sk_X509_find
parameter_list|(
name|st
parameter_list|,
name|val
parameter_list|)
value|SKM_sk_find(X509, (st), (val))
end_define

begin_define
define|#
directive|define
name|sk_X509_delete
parameter_list|(
name|st
parameter_list|,
name|i
parameter_list|)
value|SKM_sk_delete(X509, (st), (i))
end_define

begin_define
define|#
directive|define
name|sk_X509_delete_ptr
parameter_list|(
name|st
parameter_list|,
name|ptr
parameter_list|)
value|SKM_sk_delete_ptr(X509, (st), (ptr))
end_define

begin_define
define|#
directive|define
name|sk_X509_insert
parameter_list|(
name|st
parameter_list|,
name|val
parameter_list|,
name|i
parameter_list|)
value|SKM_sk_insert(X509, (st), (val), (i))
end_define

begin_define
define|#
directive|define
name|sk_X509_set_cmp_func
parameter_list|(
name|st
parameter_list|,
name|cmp
parameter_list|)
value|SKM_sk_set_cmp_func(X509, (st), (cmp))
end_define

begin_define
define|#
directive|define
name|sk_X509_dup
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_dup(X509, st)
end_define

begin_define
define|#
directive|define
name|sk_X509_pop_free
parameter_list|(
name|st
parameter_list|,
name|free_func
parameter_list|)
value|SKM_sk_pop_free(X509, (st), (free_func))
end_define

begin_define
define|#
directive|define
name|sk_X509_shift
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_shift(X509, (st))
end_define

begin_define
define|#
directive|define
name|sk_X509_pop
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_pop(X509, (st))
end_define

begin_define
define|#
directive|define
name|sk_X509_sort
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_sort(X509, (st))
end_define

begin_define
define|#
directive|define
name|sk_X509V3_EXT_METHOD_new
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_new(X509V3_EXT_METHOD, (st))
end_define

begin_define
define|#
directive|define
name|sk_X509V3_EXT_METHOD_new_null
parameter_list|()
value|SKM_sk_new_null(X509V3_EXT_METHOD)
end_define

begin_define
define|#
directive|define
name|sk_X509V3_EXT_METHOD_free
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_free(X509V3_EXT_METHOD, (st))
end_define

begin_define
define|#
directive|define
name|sk_X509V3_EXT_METHOD_num
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_num(X509V3_EXT_METHOD, (st))
end_define

begin_define
define|#
directive|define
name|sk_X509V3_EXT_METHOD_value
parameter_list|(
name|st
parameter_list|,
name|i
parameter_list|)
value|SKM_sk_value(X509V3_EXT_METHOD, (st), (i))
end_define

begin_define
define|#
directive|define
name|sk_X509V3_EXT_METHOD_set
parameter_list|(
name|st
parameter_list|,
name|i
parameter_list|,
name|val
parameter_list|)
value|SKM_sk_set(X509V3_EXT_METHOD, (st), (i), (val))
end_define

begin_define
define|#
directive|define
name|sk_X509V3_EXT_METHOD_zero
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_zero(X509V3_EXT_METHOD, (st))
end_define

begin_define
define|#
directive|define
name|sk_X509V3_EXT_METHOD_push
parameter_list|(
name|st
parameter_list|,
name|val
parameter_list|)
value|SKM_sk_push(X509V3_EXT_METHOD, (st), (val))
end_define

begin_define
define|#
directive|define
name|sk_X509V3_EXT_METHOD_unshift
parameter_list|(
name|st
parameter_list|,
name|val
parameter_list|)
value|SKM_sk_unshift(X509V3_EXT_METHOD, (st), (val))
end_define

begin_define
define|#
directive|define
name|sk_X509V3_EXT_METHOD_find
parameter_list|(
name|st
parameter_list|,
name|val
parameter_list|)
value|SKM_sk_find(X509V3_EXT_METHOD, (st), (val))
end_define

begin_define
define|#
directive|define
name|sk_X509V3_EXT_METHOD_delete
parameter_list|(
name|st
parameter_list|,
name|i
parameter_list|)
value|SKM_sk_delete(X509V3_EXT_METHOD, (st), (i))
end_define

begin_define
define|#
directive|define
name|sk_X509V3_EXT_METHOD_delete_ptr
parameter_list|(
name|st
parameter_list|,
name|ptr
parameter_list|)
value|SKM_sk_delete_ptr(X509V3_EXT_METHOD, (st), (ptr))
end_define

begin_define
define|#
directive|define
name|sk_X509V3_EXT_METHOD_insert
parameter_list|(
name|st
parameter_list|,
name|val
parameter_list|,
name|i
parameter_list|)
value|SKM_sk_insert(X509V3_EXT_METHOD, (st), (val), (i))
end_define

begin_define
define|#
directive|define
name|sk_X509V3_EXT_METHOD_set_cmp_func
parameter_list|(
name|st
parameter_list|,
name|cmp
parameter_list|)
value|SKM_sk_set_cmp_func(X509V3_EXT_METHOD, (st), (cmp))
end_define

begin_define
define|#
directive|define
name|sk_X509V3_EXT_METHOD_dup
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_dup(X509V3_EXT_METHOD, st)
end_define

begin_define
define|#
directive|define
name|sk_X509V3_EXT_METHOD_pop_free
parameter_list|(
name|st
parameter_list|,
name|free_func
parameter_list|)
value|SKM_sk_pop_free(X509V3_EXT_METHOD, (st), (free_func))
end_define

begin_define
define|#
directive|define
name|sk_X509V3_EXT_METHOD_shift
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_shift(X509V3_EXT_METHOD, (st))
end_define

begin_define
define|#
directive|define
name|sk_X509V3_EXT_METHOD_pop
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_pop(X509V3_EXT_METHOD, (st))
end_define

begin_define
define|#
directive|define
name|sk_X509V3_EXT_METHOD_sort
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_sort(X509V3_EXT_METHOD, (st))
end_define

begin_define
define|#
directive|define
name|sk_X509_ALGOR_new
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_new(X509_ALGOR, (st))
end_define

begin_define
define|#
directive|define
name|sk_X509_ALGOR_new_null
parameter_list|()
value|SKM_sk_new_null(X509_ALGOR)
end_define

begin_define
define|#
directive|define
name|sk_X509_ALGOR_free
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_free(X509_ALGOR, (st))
end_define

begin_define
define|#
directive|define
name|sk_X509_ALGOR_num
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_num(X509_ALGOR, (st))
end_define

begin_define
define|#
directive|define
name|sk_X509_ALGOR_value
parameter_list|(
name|st
parameter_list|,
name|i
parameter_list|)
value|SKM_sk_value(X509_ALGOR, (st), (i))
end_define

begin_define
define|#
directive|define
name|sk_X509_ALGOR_set
parameter_list|(
name|st
parameter_list|,
name|i
parameter_list|,
name|val
parameter_list|)
value|SKM_sk_set(X509_ALGOR, (st), (i), (val))
end_define

begin_define
define|#
directive|define
name|sk_X509_ALGOR_zero
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_zero(X509_ALGOR, (st))
end_define

begin_define
define|#
directive|define
name|sk_X509_ALGOR_push
parameter_list|(
name|st
parameter_list|,
name|val
parameter_list|)
value|SKM_sk_push(X509_ALGOR, (st), (val))
end_define

begin_define
define|#
directive|define
name|sk_X509_ALGOR_unshift
parameter_list|(
name|st
parameter_list|,
name|val
parameter_list|)
value|SKM_sk_unshift(X509_ALGOR, (st), (val))
end_define

begin_define
define|#
directive|define
name|sk_X509_ALGOR_find
parameter_list|(
name|st
parameter_list|,
name|val
parameter_list|)
value|SKM_sk_find(X509_ALGOR, (st), (val))
end_define

begin_define
define|#
directive|define
name|sk_X509_ALGOR_delete
parameter_list|(
name|st
parameter_list|,
name|i
parameter_list|)
value|SKM_sk_delete(X509_ALGOR, (st), (i))
end_define

begin_define
define|#
directive|define
name|sk_X509_ALGOR_delete_ptr
parameter_list|(
name|st
parameter_list|,
name|ptr
parameter_list|)
value|SKM_sk_delete_ptr(X509_ALGOR, (st), (ptr))
end_define

begin_define
define|#
directive|define
name|sk_X509_ALGOR_insert
parameter_list|(
name|st
parameter_list|,
name|val
parameter_list|,
name|i
parameter_list|)
value|SKM_sk_insert(X509_ALGOR, (st), (val), (i))
end_define

begin_define
define|#
directive|define
name|sk_X509_ALGOR_set_cmp_func
parameter_list|(
name|st
parameter_list|,
name|cmp
parameter_list|)
value|SKM_sk_set_cmp_func(X509_ALGOR, (st), (cmp))
end_define

begin_define
define|#
directive|define
name|sk_X509_ALGOR_dup
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_dup(X509_ALGOR, st)
end_define

begin_define
define|#
directive|define
name|sk_X509_ALGOR_pop_free
parameter_list|(
name|st
parameter_list|,
name|free_func
parameter_list|)
value|SKM_sk_pop_free(X509_ALGOR, (st), (free_func))
end_define

begin_define
define|#
directive|define
name|sk_X509_ALGOR_shift
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_shift(X509_ALGOR, (st))
end_define

begin_define
define|#
directive|define
name|sk_X509_ALGOR_pop
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_pop(X509_ALGOR, (st))
end_define

begin_define
define|#
directive|define
name|sk_X509_ALGOR_sort
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_sort(X509_ALGOR, (st))
end_define

begin_define
define|#
directive|define
name|sk_X509_ATTRIBUTE_new
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_new(X509_ATTRIBUTE, (st))
end_define

begin_define
define|#
directive|define
name|sk_X509_ATTRIBUTE_new_null
parameter_list|()
value|SKM_sk_new_null(X509_ATTRIBUTE)
end_define

begin_define
define|#
directive|define
name|sk_X509_ATTRIBUTE_free
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_free(X509_ATTRIBUTE, (st))
end_define

begin_define
define|#
directive|define
name|sk_X509_ATTRIBUTE_num
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_num(X509_ATTRIBUTE, (st))
end_define

begin_define
define|#
directive|define
name|sk_X509_ATTRIBUTE_value
parameter_list|(
name|st
parameter_list|,
name|i
parameter_list|)
value|SKM_sk_value(X509_ATTRIBUTE, (st), (i))
end_define

begin_define
define|#
directive|define
name|sk_X509_ATTRIBUTE_set
parameter_list|(
name|st
parameter_list|,
name|i
parameter_list|,
name|val
parameter_list|)
value|SKM_sk_set(X509_ATTRIBUTE, (st), (i), (val))
end_define

begin_define
define|#
directive|define
name|sk_X509_ATTRIBUTE_zero
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_zero(X509_ATTRIBUTE, (st))
end_define

begin_define
define|#
directive|define
name|sk_X509_ATTRIBUTE_push
parameter_list|(
name|st
parameter_list|,
name|val
parameter_list|)
value|SKM_sk_push(X509_ATTRIBUTE, (st), (val))
end_define

begin_define
define|#
directive|define
name|sk_X509_ATTRIBUTE_unshift
parameter_list|(
name|st
parameter_list|,
name|val
parameter_list|)
value|SKM_sk_unshift(X509_ATTRIBUTE, (st), (val))
end_define

begin_define
define|#
directive|define
name|sk_X509_ATTRIBUTE_find
parameter_list|(
name|st
parameter_list|,
name|val
parameter_list|)
value|SKM_sk_find(X509_ATTRIBUTE, (st), (val))
end_define

begin_define
define|#
directive|define
name|sk_X509_ATTRIBUTE_delete
parameter_list|(
name|st
parameter_list|,
name|i
parameter_list|)
value|SKM_sk_delete(X509_ATTRIBUTE, (st), (i))
end_define

begin_define
define|#
directive|define
name|sk_X509_ATTRIBUTE_delete_ptr
parameter_list|(
name|st
parameter_list|,
name|ptr
parameter_list|)
value|SKM_sk_delete_ptr(X509_ATTRIBUTE, (st), (ptr))
end_define

begin_define
define|#
directive|define
name|sk_X509_ATTRIBUTE_insert
parameter_list|(
name|st
parameter_list|,
name|val
parameter_list|,
name|i
parameter_list|)
value|SKM_sk_insert(X509_ATTRIBUTE, (st), (val), (i))
end_define

begin_define
define|#
directive|define
name|sk_X509_ATTRIBUTE_set_cmp_func
parameter_list|(
name|st
parameter_list|,
name|cmp
parameter_list|)
value|SKM_sk_set_cmp_func(X509_ATTRIBUTE, (st), (cmp))
end_define

begin_define
define|#
directive|define
name|sk_X509_ATTRIBUTE_dup
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_dup(X509_ATTRIBUTE, st)
end_define

begin_define
define|#
directive|define
name|sk_X509_ATTRIBUTE_pop_free
parameter_list|(
name|st
parameter_list|,
name|free_func
parameter_list|)
value|SKM_sk_pop_free(X509_ATTRIBUTE, (st), (free_func))
end_define

begin_define
define|#
directive|define
name|sk_X509_ATTRIBUTE_shift
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_shift(X509_ATTRIBUTE, (st))
end_define

begin_define
define|#
directive|define
name|sk_X509_ATTRIBUTE_pop
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_pop(X509_ATTRIBUTE, (st))
end_define

begin_define
define|#
directive|define
name|sk_X509_ATTRIBUTE_sort
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_sort(X509_ATTRIBUTE, (st))
end_define

begin_define
define|#
directive|define
name|sk_X509_CRL_new
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_new(X509_CRL, (st))
end_define

begin_define
define|#
directive|define
name|sk_X509_CRL_new_null
parameter_list|()
value|SKM_sk_new_null(X509_CRL)
end_define

begin_define
define|#
directive|define
name|sk_X509_CRL_free
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_free(X509_CRL, (st))
end_define

begin_define
define|#
directive|define
name|sk_X509_CRL_num
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_num(X509_CRL, (st))
end_define

begin_define
define|#
directive|define
name|sk_X509_CRL_value
parameter_list|(
name|st
parameter_list|,
name|i
parameter_list|)
value|SKM_sk_value(X509_CRL, (st), (i))
end_define

begin_define
define|#
directive|define
name|sk_X509_CRL_set
parameter_list|(
name|st
parameter_list|,
name|i
parameter_list|,
name|val
parameter_list|)
value|SKM_sk_set(X509_CRL, (st), (i), (val))
end_define

begin_define
define|#
directive|define
name|sk_X509_CRL_zero
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_zero(X509_CRL, (st))
end_define

begin_define
define|#
directive|define
name|sk_X509_CRL_push
parameter_list|(
name|st
parameter_list|,
name|val
parameter_list|)
value|SKM_sk_push(X509_CRL, (st), (val))
end_define

begin_define
define|#
directive|define
name|sk_X509_CRL_unshift
parameter_list|(
name|st
parameter_list|,
name|val
parameter_list|)
value|SKM_sk_unshift(X509_CRL, (st), (val))
end_define

begin_define
define|#
directive|define
name|sk_X509_CRL_find
parameter_list|(
name|st
parameter_list|,
name|val
parameter_list|)
value|SKM_sk_find(X509_CRL, (st), (val))
end_define

begin_define
define|#
directive|define
name|sk_X509_CRL_delete
parameter_list|(
name|st
parameter_list|,
name|i
parameter_list|)
value|SKM_sk_delete(X509_CRL, (st), (i))
end_define

begin_define
define|#
directive|define
name|sk_X509_CRL_delete_ptr
parameter_list|(
name|st
parameter_list|,
name|ptr
parameter_list|)
value|SKM_sk_delete_ptr(X509_CRL, (st), (ptr))
end_define

begin_define
define|#
directive|define
name|sk_X509_CRL_insert
parameter_list|(
name|st
parameter_list|,
name|val
parameter_list|,
name|i
parameter_list|)
value|SKM_sk_insert(X509_CRL, (st), (val), (i))
end_define

begin_define
define|#
directive|define
name|sk_X509_CRL_set_cmp_func
parameter_list|(
name|st
parameter_list|,
name|cmp
parameter_list|)
value|SKM_sk_set_cmp_func(X509_CRL, (st), (cmp))
end_define

begin_define
define|#
directive|define
name|sk_X509_CRL_dup
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_dup(X509_CRL, st)
end_define

begin_define
define|#
directive|define
name|sk_X509_CRL_pop_free
parameter_list|(
name|st
parameter_list|,
name|free_func
parameter_list|)
value|SKM_sk_pop_free(X509_CRL, (st), (free_func))
end_define

begin_define
define|#
directive|define
name|sk_X509_CRL_shift
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_shift(X509_CRL, (st))
end_define

begin_define
define|#
directive|define
name|sk_X509_CRL_pop
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_pop(X509_CRL, (st))
end_define

begin_define
define|#
directive|define
name|sk_X509_CRL_sort
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_sort(X509_CRL, (st))
end_define

begin_define
define|#
directive|define
name|sk_X509_EXTENSION_new
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_new(X509_EXTENSION, (st))
end_define

begin_define
define|#
directive|define
name|sk_X509_EXTENSION_new_null
parameter_list|()
value|SKM_sk_new_null(X509_EXTENSION)
end_define

begin_define
define|#
directive|define
name|sk_X509_EXTENSION_free
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_free(X509_EXTENSION, (st))
end_define

begin_define
define|#
directive|define
name|sk_X509_EXTENSION_num
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_num(X509_EXTENSION, (st))
end_define

begin_define
define|#
directive|define
name|sk_X509_EXTENSION_value
parameter_list|(
name|st
parameter_list|,
name|i
parameter_list|)
value|SKM_sk_value(X509_EXTENSION, (st), (i))
end_define

begin_define
define|#
directive|define
name|sk_X509_EXTENSION_set
parameter_list|(
name|st
parameter_list|,
name|i
parameter_list|,
name|val
parameter_list|)
value|SKM_sk_set(X509_EXTENSION, (st), (i), (val))
end_define

begin_define
define|#
directive|define
name|sk_X509_EXTENSION_zero
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_zero(X509_EXTENSION, (st))
end_define

begin_define
define|#
directive|define
name|sk_X509_EXTENSION_push
parameter_list|(
name|st
parameter_list|,
name|val
parameter_list|)
value|SKM_sk_push(X509_EXTENSION, (st), (val))
end_define

begin_define
define|#
directive|define
name|sk_X509_EXTENSION_unshift
parameter_list|(
name|st
parameter_list|,
name|val
parameter_list|)
value|SKM_sk_unshift(X509_EXTENSION, (st), (val))
end_define

begin_define
define|#
directive|define
name|sk_X509_EXTENSION_find
parameter_list|(
name|st
parameter_list|,
name|val
parameter_list|)
value|SKM_sk_find(X509_EXTENSION, (st), (val))
end_define

begin_define
define|#
directive|define
name|sk_X509_EXTENSION_delete
parameter_list|(
name|st
parameter_list|,
name|i
parameter_list|)
value|SKM_sk_delete(X509_EXTENSION, (st), (i))
end_define

begin_define
define|#
directive|define
name|sk_X509_EXTENSION_delete_ptr
parameter_list|(
name|st
parameter_list|,
name|ptr
parameter_list|)
value|SKM_sk_delete_ptr(X509_EXTENSION, (st), (ptr))
end_define

begin_define
define|#
directive|define
name|sk_X509_EXTENSION_insert
parameter_list|(
name|st
parameter_list|,
name|val
parameter_list|,
name|i
parameter_list|)
value|SKM_sk_insert(X509_EXTENSION, (st), (val), (i))
end_define

begin_define
define|#
directive|define
name|sk_X509_EXTENSION_set_cmp_func
parameter_list|(
name|st
parameter_list|,
name|cmp
parameter_list|)
value|SKM_sk_set_cmp_func(X509_EXTENSION, (st), (cmp))
end_define

begin_define
define|#
directive|define
name|sk_X509_EXTENSION_dup
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_dup(X509_EXTENSION, st)
end_define

begin_define
define|#
directive|define
name|sk_X509_EXTENSION_pop_free
parameter_list|(
name|st
parameter_list|,
name|free_func
parameter_list|)
value|SKM_sk_pop_free(X509_EXTENSION, (st), (free_func))
end_define

begin_define
define|#
directive|define
name|sk_X509_EXTENSION_shift
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_shift(X509_EXTENSION, (st))
end_define

begin_define
define|#
directive|define
name|sk_X509_EXTENSION_pop
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_pop(X509_EXTENSION, (st))
end_define

begin_define
define|#
directive|define
name|sk_X509_EXTENSION_sort
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_sort(X509_EXTENSION, (st))
end_define

begin_define
define|#
directive|define
name|sk_X509_INFO_new
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_new(X509_INFO, (st))
end_define

begin_define
define|#
directive|define
name|sk_X509_INFO_new_null
parameter_list|()
value|SKM_sk_new_null(X509_INFO)
end_define

begin_define
define|#
directive|define
name|sk_X509_INFO_free
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_free(X509_INFO, (st))
end_define

begin_define
define|#
directive|define
name|sk_X509_INFO_num
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_num(X509_INFO, (st))
end_define

begin_define
define|#
directive|define
name|sk_X509_INFO_value
parameter_list|(
name|st
parameter_list|,
name|i
parameter_list|)
value|SKM_sk_value(X509_INFO, (st), (i))
end_define

begin_define
define|#
directive|define
name|sk_X509_INFO_set
parameter_list|(
name|st
parameter_list|,
name|i
parameter_list|,
name|val
parameter_list|)
value|SKM_sk_set(X509_INFO, (st), (i), (val))
end_define

begin_define
define|#
directive|define
name|sk_X509_INFO_zero
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_zero(X509_INFO, (st))
end_define

begin_define
define|#
directive|define
name|sk_X509_INFO_push
parameter_list|(
name|st
parameter_list|,
name|val
parameter_list|)
value|SKM_sk_push(X509_INFO, (st), (val))
end_define

begin_define
define|#
directive|define
name|sk_X509_INFO_unshift
parameter_list|(
name|st
parameter_list|,
name|val
parameter_list|)
value|SKM_sk_unshift(X509_INFO, (st), (val))
end_define

begin_define
define|#
directive|define
name|sk_X509_INFO_find
parameter_list|(
name|st
parameter_list|,
name|val
parameter_list|)
value|SKM_sk_find(X509_INFO, (st), (val))
end_define

begin_define
define|#
directive|define
name|sk_X509_INFO_delete
parameter_list|(
name|st
parameter_list|,
name|i
parameter_list|)
value|SKM_sk_delete(X509_INFO, (st), (i))
end_define

begin_define
define|#
directive|define
name|sk_X509_INFO_delete_ptr
parameter_list|(
name|st
parameter_list|,
name|ptr
parameter_list|)
value|SKM_sk_delete_ptr(X509_INFO, (st), (ptr))
end_define

begin_define
define|#
directive|define
name|sk_X509_INFO_insert
parameter_list|(
name|st
parameter_list|,
name|val
parameter_list|,
name|i
parameter_list|)
value|SKM_sk_insert(X509_INFO, (st), (val), (i))
end_define

begin_define
define|#
directive|define
name|sk_X509_INFO_set_cmp_func
parameter_list|(
name|st
parameter_list|,
name|cmp
parameter_list|)
value|SKM_sk_set_cmp_func(X509_INFO, (st), (cmp))
end_define

begin_define
define|#
directive|define
name|sk_X509_INFO_dup
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_dup(X509_INFO, st)
end_define

begin_define
define|#
directive|define
name|sk_X509_INFO_pop_free
parameter_list|(
name|st
parameter_list|,
name|free_func
parameter_list|)
value|SKM_sk_pop_free(X509_INFO, (st), (free_func))
end_define

begin_define
define|#
directive|define
name|sk_X509_INFO_shift
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_shift(X509_INFO, (st))
end_define

begin_define
define|#
directive|define
name|sk_X509_INFO_pop
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_pop(X509_INFO, (st))
end_define

begin_define
define|#
directive|define
name|sk_X509_INFO_sort
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_sort(X509_INFO, (st))
end_define

begin_define
define|#
directive|define
name|sk_X509_LOOKUP_new
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_new(X509_LOOKUP, (st))
end_define

begin_define
define|#
directive|define
name|sk_X509_LOOKUP_new_null
parameter_list|()
value|SKM_sk_new_null(X509_LOOKUP)
end_define

begin_define
define|#
directive|define
name|sk_X509_LOOKUP_free
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_free(X509_LOOKUP, (st))
end_define

begin_define
define|#
directive|define
name|sk_X509_LOOKUP_num
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_num(X509_LOOKUP, (st))
end_define

begin_define
define|#
directive|define
name|sk_X509_LOOKUP_value
parameter_list|(
name|st
parameter_list|,
name|i
parameter_list|)
value|SKM_sk_value(X509_LOOKUP, (st), (i))
end_define

begin_define
define|#
directive|define
name|sk_X509_LOOKUP_set
parameter_list|(
name|st
parameter_list|,
name|i
parameter_list|,
name|val
parameter_list|)
value|SKM_sk_set(X509_LOOKUP, (st), (i), (val))
end_define

begin_define
define|#
directive|define
name|sk_X509_LOOKUP_zero
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_zero(X509_LOOKUP, (st))
end_define

begin_define
define|#
directive|define
name|sk_X509_LOOKUP_push
parameter_list|(
name|st
parameter_list|,
name|val
parameter_list|)
value|SKM_sk_push(X509_LOOKUP, (st), (val))
end_define

begin_define
define|#
directive|define
name|sk_X509_LOOKUP_unshift
parameter_list|(
name|st
parameter_list|,
name|val
parameter_list|)
value|SKM_sk_unshift(X509_LOOKUP, (st), (val))
end_define

begin_define
define|#
directive|define
name|sk_X509_LOOKUP_find
parameter_list|(
name|st
parameter_list|,
name|val
parameter_list|)
value|SKM_sk_find(X509_LOOKUP, (st), (val))
end_define

begin_define
define|#
directive|define
name|sk_X509_LOOKUP_delete
parameter_list|(
name|st
parameter_list|,
name|i
parameter_list|)
value|SKM_sk_delete(X509_LOOKUP, (st), (i))
end_define

begin_define
define|#
directive|define
name|sk_X509_LOOKUP_delete_ptr
parameter_list|(
name|st
parameter_list|,
name|ptr
parameter_list|)
value|SKM_sk_delete_ptr(X509_LOOKUP, (st), (ptr))
end_define

begin_define
define|#
directive|define
name|sk_X509_LOOKUP_insert
parameter_list|(
name|st
parameter_list|,
name|val
parameter_list|,
name|i
parameter_list|)
value|SKM_sk_insert(X509_LOOKUP, (st), (val), (i))
end_define

begin_define
define|#
directive|define
name|sk_X509_LOOKUP_set_cmp_func
parameter_list|(
name|st
parameter_list|,
name|cmp
parameter_list|)
value|SKM_sk_set_cmp_func(X509_LOOKUP, (st), (cmp))
end_define

begin_define
define|#
directive|define
name|sk_X509_LOOKUP_dup
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_dup(X509_LOOKUP, st)
end_define

begin_define
define|#
directive|define
name|sk_X509_LOOKUP_pop_free
parameter_list|(
name|st
parameter_list|,
name|free_func
parameter_list|)
value|SKM_sk_pop_free(X509_LOOKUP, (st), (free_func))
end_define

begin_define
define|#
directive|define
name|sk_X509_LOOKUP_shift
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_shift(X509_LOOKUP, (st))
end_define

begin_define
define|#
directive|define
name|sk_X509_LOOKUP_pop
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_pop(X509_LOOKUP, (st))
end_define

begin_define
define|#
directive|define
name|sk_X509_LOOKUP_sort
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_sort(X509_LOOKUP, (st))
end_define

begin_define
define|#
directive|define
name|sk_X509_NAME_new
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_new(X509_NAME, (st))
end_define

begin_define
define|#
directive|define
name|sk_X509_NAME_new_null
parameter_list|()
value|SKM_sk_new_null(X509_NAME)
end_define

begin_define
define|#
directive|define
name|sk_X509_NAME_free
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_free(X509_NAME, (st))
end_define

begin_define
define|#
directive|define
name|sk_X509_NAME_num
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_num(X509_NAME, (st))
end_define

begin_define
define|#
directive|define
name|sk_X509_NAME_value
parameter_list|(
name|st
parameter_list|,
name|i
parameter_list|)
value|SKM_sk_value(X509_NAME, (st), (i))
end_define

begin_define
define|#
directive|define
name|sk_X509_NAME_set
parameter_list|(
name|st
parameter_list|,
name|i
parameter_list|,
name|val
parameter_list|)
value|SKM_sk_set(X509_NAME, (st), (i), (val))
end_define

begin_define
define|#
directive|define
name|sk_X509_NAME_zero
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_zero(X509_NAME, (st))
end_define

begin_define
define|#
directive|define
name|sk_X509_NAME_push
parameter_list|(
name|st
parameter_list|,
name|val
parameter_list|)
value|SKM_sk_push(X509_NAME, (st), (val))
end_define

begin_define
define|#
directive|define
name|sk_X509_NAME_unshift
parameter_list|(
name|st
parameter_list|,
name|val
parameter_list|)
value|SKM_sk_unshift(X509_NAME, (st), (val))
end_define

begin_define
define|#
directive|define
name|sk_X509_NAME_find
parameter_list|(
name|st
parameter_list|,
name|val
parameter_list|)
value|SKM_sk_find(X509_NAME, (st), (val))
end_define

begin_define
define|#
directive|define
name|sk_X509_NAME_delete
parameter_list|(
name|st
parameter_list|,
name|i
parameter_list|)
value|SKM_sk_delete(X509_NAME, (st), (i))
end_define

begin_define
define|#
directive|define
name|sk_X509_NAME_delete_ptr
parameter_list|(
name|st
parameter_list|,
name|ptr
parameter_list|)
value|SKM_sk_delete_ptr(X509_NAME, (st), (ptr))
end_define

begin_define
define|#
directive|define
name|sk_X509_NAME_insert
parameter_list|(
name|st
parameter_list|,
name|val
parameter_list|,
name|i
parameter_list|)
value|SKM_sk_insert(X509_NAME, (st), (val), (i))
end_define

begin_define
define|#
directive|define
name|sk_X509_NAME_set_cmp_func
parameter_list|(
name|st
parameter_list|,
name|cmp
parameter_list|)
value|SKM_sk_set_cmp_func(X509_NAME, (st), (cmp))
end_define

begin_define
define|#
directive|define
name|sk_X509_NAME_dup
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_dup(X509_NAME, st)
end_define

begin_define
define|#
directive|define
name|sk_X509_NAME_pop_free
parameter_list|(
name|st
parameter_list|,
name|free_func
parameter_list|)
value|SKM_sk_pop_free(X509_NAME, (st), (free_func))
end_define

begin_define
define|#
directive|define
name|sk_X509_NAME_shift
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_shift(X509_NAME, (st))
end_define

begin_define
define|#
directive|define
name|sk_X509_NAME_pop
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_pop(X509_NAME, (st))
end_define

begin_define
define|#
directive|define
name|sk_X509_NAME_sort
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_sort(X509_NAME, (st))
end_define

begin_define
define|#
directive|define
name|sk_X509_NAME_ENTRY_new
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_new(X509_NAME_ENTRY, (st))
end_define

begin_define
define|#
directive|define
name|sk_X509_NAME_ENTRY_new_null
parameter_list|()
value|SKM_sk_new_null(X509_NAME_ENTRY)
end_define

begin_define
define|#
directive|define
name|sk_X509_NAME_ENTRY_free
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_free(X509_NAME_ENTRY, (st))
end_define

begin_define
define|#
directive|define
name|sk_X509_NAME_ENTRY_num
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_num(X509_NAME_ENTRY, (st))
end_define

begin_define
define|#
directive|define
name|sk_X509_NAME_ENTRY_value
parameter_list|(
name|st
parameter_list|,
name|i
parameter_list|)
value|SKM_sk_value(X509_NAME_ENTRY, (st), (i))
end_define

begin_define
define|#
directive|define
name|sk_X509_NAME_ENTRY_set
parameter_list|(
name|st
parameter_list|,
name|i
parameter_list|,
name|val
parameter_list|)
value|SKM_sk_set(X509_NAME_ENTRY, (st), (i), (val))
end_define

begin_define
define|#
directive|define
name|sk_X509_NAME_ENTRY_zero
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_zero(X509_NAME_ENTRY, (st))
end_define

begin_define
define|#
directive|define
name|sk_X509_NAME_ENTRY_push
parameter_list|(
name|st
parameter_list|,
name|val
parameter_list|)
value|SKM_sk_push(X509_NAME_ENTRY, (st), (val))
end_define

begin_define
define|#
directive|define
name|sk_X509_NAME_ENTRY_unshift
parameter_list|(
name|st
parameter_list|,
name|val
parameter_list|)
value|SKM_sk_unshift(X509_NAME_ENTRY, (st), (val))
end_define

begin_define
define|#
directive|define
name|sk_X509_NAME_ENTRY_find
parameter_list|(
name|st
parameter_list|,
name|val
parameter_list|)
value|SKM_sk_find(X509_NAME_ENTRY, (st), (val))
end_define

begin_define
define|#
directive|define
name|sk_X509_NAME_ENTRY_delete
parameter_list|(
name|st
parameter_list|,
name|i
parameter_list|)
value|SKM_sk_delete(X509_NAME_ENTRY, (st), (i))
end_define

begin_define
define|#
directive|define
name|sk_X509_NAME_ENTRY_delete_ptr
parameter_list|(
name|st
parameter_list|,
name|ptr
parameter_list|)
value|SKM_sk_delete_ptr(X509_NAME_ENTRY, (st), (ptr))
end_define

begin_define
define|#
directive|define
name|sk_X509_NAME_ENTRY_insert
parameter_list|(
name|st
parameter_list|,
name|val
parameter_list|,
name|i
parameter_list|)
value|SKM_sk_insert(X509_NAME_ENTRY, (st), (val), (i))
end_define

begin_define
define|#
directive|define
name|sk_X509_NAME_ENTRY_set_cmp_func
parameter_list|(
name|st
parameter_list|,
name|cmp
parameter_list|)
value|SKM_sk_set_cmp_func(X509_NAME_ENTRY, (st), (cmp))
end_define

begin_define
define|#
directive|define
name|sk_X509_NAME_ENTRY_dup
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_dup(X509_NAME_ENTRY, st)
end_define

begin_define
define|#
directive|define
name|sk_X509_NAME_ENTRY_pop_free
parameter_list|(
name|st
parameter_list|,
name|free_func
parameter_list|)
value|SKM_sk_pop_free(X509_NAME_ENTRY, (st), (free_func))
end_define

begin_define
define|#
directive|define
name|sk_X509_NAME_ENTRY_shift
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_shift(X509_NAME_ENTRY, (st))
end_define

begin_define
define|#
directive|define
name|sk_X509_NAME_ENTRY_pop
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_pop(X509_NAME_ENTRY, (st))
end_define

begin_define
define|#
directive|define
name|sk_X509_NAME_ENTRY_sort
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_sort(X509_NAME_ENTRY, (st))
end_define

begin_define
define|#
directive|define
name|sk_X509_OBJECT_new
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_new(X509_OBJECT, (st))
end_define

begin_define
define|#
directive|define
name|sk_X509_OBJECT_new_null
parameter_list|()
value|SKM_sk_new_null(X509_OBJECT)
end_define

begin_define
define|#
directive|define
name|sk_X509_OBJECT_free
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_free(X509_OBJECT, (st))
end_define

begin_define
define|#
directive|define
name|sk_X509_OBJECT_num
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_num(X509_OBJECT, (st))
end_define

begin_define
define|#
directive|define
name|sk_X509_OBJECT_value
parameter_list|(
name|st
parameter_list|,
name|i
parameter_list|)
value|SKM_sk_value(X509_OBJECT, (st), (i))
end_define

begin_define
define|#
directive|define
name|sk_X509_OBJECT_set
parameter_list|(
name|st
parameter_list|,
name|i
parameter_list|,
name|val
parameter_list|)
value|SKM_sk_set(X509_OBJECT, (st), (i), (val))
end_define

begin_define
define|#
directive|define
name|sk_X509_OBJECT_zero
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_zero(X509_OBJECT, (st))
end_define

begin_define
define|#
directive|define
name|sk_X509_OBJECT_push
parameter_list|(
name|st
parameter_list|,
name|val
parameter_list|)
value|SKM_sk_push(X509_OBJECT, (st), (val))
end_define

begin_define
define|#
directive|define
name|sk_X509_OBJECT_unshift
parameter_list|(
name|st
parameter_list|,
name|val
parameter_list|)
value|SKM_sk_unshift(X509_OBJECT, (st), (val))
end_define

begin_define
define|#
directive|define
name|sk_X509_OBJECT_find
parameter_list|(
name|st
parameter_list|,
name|val
parameter_list|)
value|SKM_sk_find(X509_OBJECT, (st), (val))
end_define

begin_define
define|#
directive|define
name|sk_X509_OBJECT_delete
parameter_list|(
name|st
parameter_list|,
name|i
parameter_list|)
value|SKM_sk_delete(X509_OBJECT, (st), (i))
end_define

begin_define
define|#
directive|define
name|sk_X509_OBJECT_delete_ptr
parameter_list|(
name|st
parameter_list|,
name|ptr
parameter_list|)
value|SKM_sk_delete_ptr(X509_OBJECT, (st), (ptr))
end_define

begin_define
define|#
directive|define
name|sk_X509_OBJECT_insert
parameter_list|(
name|st
parameter_list|,
name|val
parameter_list|,
name|i
parameter_list|)
value|SKM_sk_insert(X509_OBJECT, (st), (val), (i))
end_define

begin_define
define|#
directive|define
name|sk_X509_OBJECT_set_cmp_func
parameter_list|(
name|st
parameter_list|,
name|cmp
parameter_list|)
value|SKM_sk_set_cmp_func(X509_OBJECT, (st), (cmp))
end_define

begin_define
define|#
directive|define
name|sk_X509_OBJECT_dup
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_dup(X509_OBJECT, st)
end_define

begin_define
define|#
directive|define
name|sk_X509_OBJECT_pop_free
parameter_list|(
name|st
parameter_list|,
name|free_func
parameter_list|)
value|SKM_sk_pop_free(X509_OBJECT, (st), (free_func))
end_define

begin_define
define|#
directive|define
name|sk_X509_OBJECT_shift
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_shift(X509_OBJECT, (st))
end_define

begin_define
define|#
directive|define
name|sk_X509_OBJECT_pop
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_pop(X509_OBJECT, (st))
end_define

begin_define
define|#
directive|define
name|sk_X509_OBJECT_sort
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_sort(X509_OBJECT, (st))
end_define

begin_define
define|#
directive|define
name|sk_X509_PURPOSE_new
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_new(X509_PURPOSE, (st))
end_define

begin_define
define|#
directive|define
name|sk_X509_PURPOSE_new_null
parameter_list|()
value|SKM_sk_new_null(X509_PURPOSE)
end_define

begin_define
define|#
directive|define
name|sk_X509_PURPOSE_free
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_free(X509_PURPOSE, (st))
end_define

begin_define
define|#
directive|define
name|sk_X509_PURPOSE_num
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_num(X509_PURPOSE, (st))
end_define

begin_define
define|#
directive|define
name|sk_X509_PURPOSE_value
parameter_list|(
name|st
parameter_list|,
name|i
parameter_list|)
value|SKM_sk_value(X509_PURPOSE, (st), (i))
end_define

begin_define
define|#
directive|define
name|sk_X509_PURPOSE_set
parameter_list|(
name|st
parameter_list|,
name|i
parameter_list|,
name|val
parameter_list|)
value|SKM_sk_set(X509_PURPOSE, (st), (i), (val))
end_define

begin_define
define|#
directive|define
name|sk_X509_PURPOSE_zero
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_zero(X509_PURPOSE, (st))
end_define

begin_define
define|#
directive|define
name|sk_X509_PURPOSE_push
parameter_list|(
name|st
parameter_list|,
name|val
parameter_list|)
value|SKM_sk_push(X509_PURPOSE, (st), (val))
end_define

begin_define
define|#
directive|define
name|sk_X509_PURPOSE_unshift
parameter_list|(
name|st
parameter_list|,
name|val
parameter_list|)
value|SKM_sk_unshift(X509_PURPOSE, (st), (val))
end_define

begin_define
define|#
directive|define
name|sk_X509_PURPOSE_find
parameter_list|(
name|st
parameter_list|,
name|val
parameter_list|)
value|SKM_sk_find(X509_PURPOSE, (st), (val))
end_define

begin_define
define|#
directive|define
name|sk_X509_PURPOSE_delete
parameter_list|(
name|st
parameter_list|,
name|i
parameter_list|)
value|SKM_sk_delete(X509_PURPOSE, (st), (i))
end_define

begin_define
define|#
directive|define
name|sk_X509_PURPOSE_delete_ptr
parameter_list|(
name|st
parameter_list|,
name|ptr
parameter_list|)
value|SKM_sk_delete_ptr(X509_PURPOSE, (st), (ptr))
end_define

begin_define
define|#
directive|define
name|sk_X509_PURPOSE_insert
parameter_list|(
name|st
parameter_list|,
name|val
parameter_list|,
name|i
parameter_list|)
value|SKM_sk_insert(X509_PURPOSE, (st), (val), (i))
end_define

begin_define
define|#
directive|define
name|sk_X509_PURPOSE_set_cmp_func
parameter_list|(
name|st
parameter_list|,
name|cmp
parameter_list|)
value|SKM_sk_set_cmp_func(X509_PURPOSE, (st), (cmp))
end_define

begin_define
define|#
directive|define
name|sk_X509_PURPOSE_dup
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_dup(X509_PURPOSE, st)
end_define

begin_define
define|#
directive|define
name|sk_X509_PURPOSE_pop_free
parameter_list|(
name|st
parameter_list|,
name|free_func
parameter_list|)
value|SKM_sk_pop_free(X509_PURPOSE, (st), (free_func))
end_define

begin_define
define|#
directive|define
name|sk_X509_PURPOSE_shift
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_shift(X509_PURPOSE, (st))
end_define

begin_define
define|#
directive|define
name|sk_X509_PURPOSE_pop
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_pop(X509_PURPOSE, (st))
end_define

begin_define
define|#
directive|define
name|sk_X509_PURPOSE_sort
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_sort(X509_PURPOSE, (st))
end_define

begin_define
define|#
directive|define
name|sk_X509_REVOKED_new
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_new(X509_REVOKED, (st))
end_define

begin_define
define|#
directive|define
name|sk_X509_REVOKED_new_null
parameter_list|()
value|SKM_sk_new_null(X509_REVOKED)
end_define

begin_define
define|#
directive|define
name|sk_X509_REVOKED_free
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_free(X509_REVOKED, (st))
end_define

begin_define
define|#
directive|define
name|sk_X509_REVOKED_num
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_num(X509_REVOKED, (st))
end_define

begin_define
define|#
directive|define
name|sk_X509_REVOKED_value
parameter_list|(
name|st
parameter_list|,
name|i
parameter_list|)
value|SKM_sk_value(X509_REVOKED, (st), (i))
end_define

begin_define
define|#
directive|define
name|sk_X509_REVOKED_set
parameter_list|(
name|st
parameter_list|,
name|i
parameter_list|,
name|val
parameter_list|)
value|SKM_sk_set(X509_REVOKED, (st), (i), (val))
end_define

begin_define
define|#
directive|define
name|sk_X509_REVOKED_zero
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_zero(X509_REVOKED, (st))
end_define

begin_define
define|#
directive|define
name|sk_X509_REVOKED_push
parameter_list|(
name|st
parameter_list|,
name|val
parameter_list|)
value|SKM_sk_push(X509_REVOKED, (st), (val))
end_define

begin_define
define|#
directive|define
name|sk_X509_REVOKED_unshift
parameter_list|(
name|st
parameter_list|,
name|val
parameter_list|)
value|SKM_sk_unshift(X509_REVOKED, (st), (val))
end_define

begin_define
define|#
directive|define
name|sk_X509_REVOKED_find
parameter_list|(
name|st
parameter_list|,
name|val
parameter_list|)
value|SKM_sk_find(X509_REVOKED, (st), (val))
end_define

begin_define
define|#
directive|define
name|sk_X509_REVOKED_delete
parameter_list|(
name|st
parameter_list|,
name|i
parameter_list|)
value|SKM_sk_delete(X509_REVOKED, (st), (i))
end_define

begin_define
define|#
directive|define
name|sk_X509_REVOKED_delete_ptr
parameter_list|(
name|st
parameter_list|,
name|ptr
parameter_list|)
value|SKM_sk_delete_ptr(X509_REVOKED, (st), (ptr))
end_define

begin_define
define|#
directive|define
name|sk_X509_REVOKED_insert
parameter_list|(
name|st
parameter_list|,
name|val
parameter_list|,
name|i
parameter_list|)
value|SKM_sk_insert(X509_REVOKED, (st), (val), (i))
end_define

begin_define
define|#
directive|define
name|sk_X509_REVOKED_set_cmp_func
parameter_list|(
name|st
parameter_list|,
name|cmp
parameter_list|)
value|SKM_sk_set_cmp_func(X509_REVOKED, (st), (cmp))
end_define

begin_define
define|#
directive|define
name|sk_X509_REVOKED_dup
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_dup(X509_REVOKED, st)
end_define

begin_define
define|#
directive|define
name|sk_X509_REVOKED_pop_free
parameter_list|(
name|st
parameter_list|,
name|free_func
parameter_list|)
value|SKM_sk_pop_free(X509_REVOKED, (st), (free_func))
end_define

begin_define
define|#
directive|define
name|sk_X509_REVOKED_shift
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_shift(X509_REVOKED, (st))
end_define

begin_define
define|#
directive|define
name|sk_X509_REVOKED_pop
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_pop(X509_REVOKED, (st))
end_define

begin_define
define|#
directive|define
name|sk_X509_REVOKED_sort
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_sort(X509_REVOKED, (st))
end_define

begin_define
define|#
directive|define
name|sk_X509_TRUST_new
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_new(X509_TRUST, (st))
end_define

begin_define
define|#
directive|define
name|sk_X509_TRUST_new_null
parameter_list|()
value|SKM_sk_new_null(X509_TRUST)
end_define

begin_define
define|#
directive|define
name|sk_X509_TRUST_free
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_free(X509_TRUST, (st))
end_define

begin_define
define|#
directive|define
name|sk_X509_TRUST_num
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_num(X509_TRUST, (st))
end_define

begin_define
define|#
directive|define
name|sk_X509_TRUST_value
parameter_list|(
name|st
parameter_list|,
name|i
parameter_list|)
value|SKM_sk_value(X509_TRUST, (st), (i))
end_define

begin_define
define|#
directive|define
name|sk_X509_TRUST_set
parameter_list|(
name|st
parameter_list|,
name|i
parameter_list|,
name|val
parameter_list|)
value|SKM_sk_set(X509_TRUST, (st), (i), (val))
end_define

begin_define
define|#
directive|define
name|sk_X509_TRUST_zero
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_zero(X509_TRUST, (st))
end_define

begin_define
define|#
directive|define
name|sk_X509_TRUST_push
parameter_list|(
name|st
parameter_list|,
name|val
parameter_list|)
value|SKM_sk_push(X509_TRUST, (st), (val))
end_define

begin_define
define|#
directive|define
name|sk_X509_TRUST_unshift
parameter_list|(
name|st
parameter_list|,
name|val
parameter_list|)
value|SKM_sk_unshift(X509_TRUST, (st), (val))
end_define

begin_define
define|#
directive|define
name|sk_X509_TRUST_find
parameter_list|(
name|st
parameter_list|,
name|val
parameter_list|)
value|SKM_sk_find(X509_TRUST, (st), (val))
end_define

begin_define
define|#
directive|define
name|sk_X509_TRUST_delete
parameter_list|(
name|st
parameter_list|,
name|i
parameter_list|)
value|SKM_sk_delete(X509_TRUST, (st), (i))
end_define

begin_define
define|#
directive|define
name|sk_X509_TRUST_delete_ptr
parameter_list|(
name|st
parameter_list|,
name|ptr
parameter_list|)
value|SKM_sk_delete_ptr(X509_TRUST, (st), (ptr))
end_define

begin_define
define|#
directive|define
name|sk_X509_TRUST_insert
parameter_list|(
name|st
parameter_list|,
name|val
parameter_list|,
name|i
parameter_list|)
value|SKM_sk_insert(X509_TRUST, (st), (val), (i))
end_define

begin_define
define|#
directive|define
name|sk_X509_TRUST_set_cmp_func
parameter_list|(
name|st
parameter_list|,
name|cmp
parameter_list|)
value|SKM_sk_set_cmp_func(X509_TRUST, (st), (cmp))
end_define

begin_define
define|#
directive|define
name|sk_X509_TRUST_dup
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_dup(X509_TRUST, st)
end_define

begin_define
define|#
directive|define
name|sk_X509_TRUST_pop_free
parameter_list|(
name|st
parameter_list|,
name|free_func
parameter_list|)
value|SKM_sk_pop_free(X509_TRUST, (st), (free_func))
end_define

begin_define
define|#
directive|define
name|sk_X509_TRUST_shift
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_shift(X509_TRUST, (st))
end_define

begin_define
define|#
directive|define
name|sk_X509_TRUST_pop
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_pop(X509_TRUST, (st))
end_define

begin_define
define|#
directive|define
name|sk_X509_TRUST_sort
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_sort(X509_TRUST, (st))
end_define

begin_define
define|#
directive|define
name|d2i_ASN1_SET_OF_ACCESS_DESCRIPTION
parameter_list|(
name|st
parameter_list|,
name|pp
parameter_list|,
name|length
parameter_list|,
name|d2i_func
parameter_list|,
name|free_func
parameter_list|,
name|ex_tag
parameter_list|,
name|ex_class
parameter_list|)
define|\
value|SKM_ASN1_SET_OF_d2i(ACCESS_DESCRIPTION, (st), (pp), (length), (d2i_func), (free_func), (ex_tag), (ex_class))
end_define

begin_define
define|#
directive|define
name|i2d_ASN1_SET_OF_ACCESS_DESCRIPTION
parameter_list|(
name|st
parameter_list|,
name|pp
parameter_list|,
name|i2d_func
parameter_list|,
name|ex_tag
parameter_list|,
name|ex_class
parameter_list|,
name|is_set
parameter_list|)
define|\
value|SKM_ASN1_SET_OF_i2d(ACCESS_DESCRIPTION, (st), (pp), (i2d_func), (ex_tag), (ex_class), (is_set))
end_define

begin_define
define|#
directive|define
name|ASN1_seq_pack_ACCESS_DESCRIPTION
parameter_list|(
name|st
parameter_list|,
name|i2d_func
parameter_list|,
name|buf
parameter_list|,
name|len
parameter_list|)
define|\
value|SKM_ASN1_seq_pack(ACCESS_DESCRIPTION, (st), (i2d_func), (buf), (len))
end_define

begin_define
define|#
directive|define
name|ASN1_seq_unpack_ACCESS_DESCRIPTION
parameter_list|(
name|buf
parameter_list|,
name|len
parameter_list|,
name|d2i_func
parameter_list|,
name|free_func
parameter_list|)
define|\
value|SKM_ASN1_seq_unpack(ACCESS_DESCRIPTION, (buf), (len), (d2i_func), (free_func))
end_define

begin_define
define|#
directive|define
name|d2i_ASN1_SET_OF_ASN1_INTEGER
parameter_list|(
name|st
parameter_list|,
name|pp
parameter_list|,
name|length
parameter_list|,
name|d2i_func
parameter_list|,
name|free_func
parameter_list|,
name|ex_tag
parameter_list|,
name|ex_class
parameter_list|)
define|\
value|SKM_ASN1_SET_OF_d2i(ASN1_INTEGER, (st), (pp), (length), (d2i_func), (free_func), (ex_tag), (ex_class))
end_define

begin_define
define|#
directive|define
name|i2d_ASN1_SET_OF_ASN1_INTEGER
parameter_list|(
name|st
parameter_list|,
name|pp
parameter_list|,
name|i2d_func
parameter_list|,
name|ex_tag
parameter_list|,
name|ex_class
parameter_list|,
name|is_set
parameter_list|)
define|\
value|SKM_ASN1_SET_OF_i2d(ASN1_INTEGER, (st), (pp), (i2d_func), (ex_tag), (ex_class), (is_set))
end_define

begin_define
define|#
directive|define
name|ASN1_seq_pack_ASN1_INTEGER
parameter_list|(
name|st
parameter_list|,
name|i2d_func
parameter_list|,
name|buf
parameter_list|,
name|len
parameter_list|)
define|\
value|SKM_ASN1_seq_pack(ASN1_INTEGER, (st), (i2d_func), (buf), (len))
end_define

begin_define
define|#
directive|define
name|ASN1_seq_unpack_ASN1_INTEGER
parameter_list|(
name|buf
parameter_list|,
name|len
parameter_list|,
name|d2i_func
parameter_list|,
name|free_func
parameter_list|)
define|\
value|SKM_ASN1_seq_unpack(ASN1_INTEGER, (buf), (len), (d2i_func), (free_func))
end_define

begin_define
define|#
directive|define
name|d2i_ASN1_SET_OF_ASN1_OBJECT
parameter_list|(
name|st
parameter_list|,
name|pp
parameter_list|,
name|length
parameter_list|,
name|d2i_func
parameter_list|,
name|free_func
parameter_list|,
name|ex_tag
parameter_list|,
name|ex_class
parameter_list|)
define|\
value|SKM_ASN1_SET_OF_d2i(ASN1_OBJECT, (st), (pp), (length), (d2i_func), (free_func), (ex_tag), (ex_class))
end_define

begin_define
define|#
directive|define
name|i2d_ASN1_SET_OF_ASN1_OBJECT
parameter_list|(
name|st
parameter_list|,
name|pp
parameter_list|,
name|i2d_func
parameter_list|,
name|ex_tag
parameter_list|,
name|ex_class
parameter_list|,
name|is_set
parameter_list|)
define|\
value|SKM_ASN1_SET_OF_i2d(ASN1_OBJECT, (st), (pp), (i2d_func), (ex_tag), (ex_class), (is_set))
end_define

begin_define
define|#
directive|define
name|ASN1_seq_pack_ASN1_OBJECT
parameter_list|(
name|st
parameter_list|,
name|i2d_func
parameter_list|,
name|buf
parameter_list|,
name|len
parameter_list|)
define|\
value|SKM_ASN1_seq_pack(ASN1_OBJECT, (st), (i2d_func), (buf), (len))
end_define

begin_define
define|#
directive|define
name|ASN1_seq_unpack_ASN1_OBJECT
parameter_list|(
name|buf
parameter_list|,
name|len
parameter_list|,
name|d2i_func
parameter_list|,
name|free_func
parameter_list|)
define|\
value|SKM_ASN1_seq_unpack(ASN1_OBJECT, (buf), (len), (d2i_func), (free_func))
end_define

begin_define
define|#
directive|define
name|d2i_ASN1_SET_OF_ASN1_TYPE
parameter_list|(
name|st
parameter_list|,
name|pp
parameter_list|,
name|length
parameter_list|,
name|d2i_func
parameter_list|,
name|free_func
parameter_list|,
name|ex_tag
parameter_list|,
name|ex_class
parameter_list|)
define|\
value|SKM_ASN1_SET_OF_d2i(ASN1_TYPE, (st), (pp), (length), (d2i_func), (free_func), (ex_tag), (ex_class))
end_define

begin_define
define|#
directive|define
name|i2d_ASN1_SET_OF_ASN1_TYPE
parameter_list|(
name|st
parameter_list|,
name|pp
parameter_list|,
name|i2d_func
parameter_list|,
name|ex_tag
parameter_list|,
name|ex_class
parameter_list|,
name|is_set
parameter_list|)
define|\
value|SKM_ASN1_SET_OF_i2d(ASN1_TYPE, (st), (pp), (i2d_func), (ex_tag), (ex_class), (is_set))
end_define

begin_define
define|#
directive|define
name|ASN1_seq_pack_ASN1_TYPE
parameter_list|(
name|st
parameter_list|,
name|i2d_func
parameter_list|,
name|buf
parameter_list|,
name|len
parameter_list|)
define|\
value|SKM_ASN1_seq_pack(ASN1_TYPE, (st), (i2d_func), (buf), (len))
end_define

begin_define
define|#
directive|define
name|ASN1_seq_unpack_ASN1_TYPE
parameter_list|(
name|buf
parameter_list|,
name|len
parameter_list|,
name|d2i_func
parameter_list|,
name|free_func
parameter_list|)
define|\
value|SKM_ASN1_seq_unpack(ASN1_TYPE, (buf), (len), (d2i_func), (free_func))
end_define

begin_define
define|#
directive|define
name|d2i_ASN1_SET_OF_DIST_POINT
parameter_list|(
name|st
parameter_list|,
name|pp
parameter_list|,
name|length
parameter_list|,
name|d2i_func
parameter_list|,
name|free_func
parameter_list|,
name|ex_tag
parameter_list|,
name|ex_class
parameter_list|)
define|\
value|SKM_ASN1_SET_OF_d2i(DIST_POINT, (st), (pp), (length), (d2i_func), (free_func), (ex_tag), (ex_class))
end_define

begin_define
define|#
directive|define
name|i2d_ASN1_SET_OF_DIST_POINT
parameter_list|(
name|st
parameter_list|,
name|pp
parameter_list|,
name|i2d_func
parameter_list|,
name|ex_tag
parameter_list|,
name|ex_class
parameter_list|,
name|is_set
parameter_list|)
define|\
value|SKM_ASN1_SET_OF_i2d(DIST_POINT, (st), (pp), (i2d_func), (ex_tag), (ex_class), (is_set))
end_define

begin_define
define|#
directive|define
name|ASN1_seq_pack_DIST_POINT
parameter_list|(
name|st
parameter_list|,
name|i2d_func
parameter_list|,
name|buf
parameter_list|,
name|len
parameter_list|)
define|\
value|SKM_ASN1_seq_pack(DIST_POINT, (st), (i2d_func), (buf), (len))
end_define

begin_define
define|#
directive|define
name|ASN1_seq_unpack_DIST_POINT
parameter_list|(
name|buf
parameter_list|,
name|len
parameter_list|,
name|d2i_func
parameter_list|,
name|free_func
parameter_list|)
define|\
value|SKM_ASN1_seq_unpack(DIST_POINT, (buf), (len), (d2i_func), (free_func))
end_define

begin_define
define|#
directive|define
name|d2i_ASN1_SET_OF_GENERAL_NAME
parameter_list|(
name|st
parameter_list|,
name|pp
parameter_list|,
name|length
parameter_list|,
name|d2i_func
parameter_list|,
name|free_func
parameter_list|,
name|ex_tag
parameter_list|,
name|ex_class
parameter_list|)
define|\
value|SKM_ASN1_SET_OF_d2i(GENERAL_NAME, (st), (pp), (length), (d2i_func), (free_func), (ex_tag), (ex_class))
end_define

begin_define
define|#
directive|define
name|i2d_ASN1_SET_OF_GENERAL_NAME
parameter_list|(
name|st
parameter_list|,
name|pp
parameter_list|,
name|i2d_func
parameter_list|,
name|ex_tag
parameter_list|,
name|ex_class
parameter_list|,
name|is_set
parameter_list|)
define|\
value|SKM_ASN1_SET_OF_i2d(GENERAL_NAME, (st), (pp), (i2d_func), (ex_tag), (ex_class), (is_set))
end_define

begin_define
define|#
directive|define
name|ASN1_seq_pack_GENERAL_NAME
parameter_list|(
name|st
parameter_list|,
name|i2d_func
parameter_list|,
name|buf
parameter_list|,
name|len
parameter_list|)
define|\
value|SKM_ASN1_seq_pack(GENERAL_NAME, (st), (i2d_func), (buf), (len))
end_define

begin_define
define|#
directive|define
name|ASN1_seq_unpack_GENERAL_NAME
parameter_list|(
name|buf
parameter_list|,
name|len
parameter_list|,
name|d2i_func
parameter_list|,
name|free_func
parameter_list|)
define|\
value|SKM_ASN1_seq_unpack(GENERAL_NAME, (buf), (len), (d2i_func), (free_func))
end_define

begin_define
define|#
directive|define
name|d2i_ASN1_SET_OF_PKCS12_SAFEBAG
parameter_list|(
name|st
parameter_list|,
name|pp
parameter_list|,
name|length
parameter_list|,
name|d2i_func
parameter_list|,
name|free_func
parameter_list|,
name|ex_tag
parameter_list|,
name|ex_class
parameter_list|)
define|\
value|SKM_ASN1_SET_OF_d2i(PKCS12_SAFEBAG, (st), (pp), (length), (d2i_func), (free_func), (ex_tag), (ex_class))
end_define

begin_define
define|#
directive|define
name|i2d_ASN1_SET_OF_PKCS12_SAFEBAG
parameter_list|(
name|st
parameter_list|,
name|pp
parameter_list|,
name|i2d_func
parameter_list|,
name|ex_tag
parameter_list|,
name|ex_class
parameter_list|,
name|is_set
parameter_list|)
define|\
value|SKM_ASN1_SET_OF_i2d(PKCS12_SAFEBAG, (st), (pp), (i2d_func), (ex_tag), (ex_class), (is_set))
end_define

begin_define
define|#
directive|define
name|ASN1_seq_pack_PKCS12_SAFEBAG
parameter_list|(
name|st
parameter_list|,
name|i2d_func
parameter_list|,
name|buf
parameter_list|,
name|len
parameter_list|)
define|\
value|SKM_ASN1_seq_pack(PKCS12_SAFEBAG, (st), (i2d_func), (buf), (len))
end_define

begin_define
define|#
directive|define
name|ASN1_seq_unpack_PKCS12_SAFEBAG
parameter_list|(
name|buf
parameter_list|,
name|len
parameter_list|,
name|d2i_func
parameter_list|,
name|free_func
parameter_list|)
define|\
value|SKM_ASN1_seq_unpack(PKCS12_SAFEBAG, (buf), (len), (d2i_func), (free_func))
end_define

begin_define
define|#
directive|define
name|d2i_ASN1_SET_OF_PKCS7
parameter_list|(
name|st
parameter_list|,
name|pp
parameter_list|,
name|length
parameter_list|,
name|d2i_func
parameter_list|,
name|free_func
parameter_list|,
name|ex_tag
parameter_list|,
name|ex_class
parameter_list|)
define|\
value|SKM_ASN1_SET_OF_d2i(PKCS7, (st), (pp), (length), (d2i_func), (free_func), (ex_tag), (ex_class))
end_define

begin_define
define|#
directive|define
name|i2d_ASN1_SET_OF_PKCS7
parameter_list|(
name|st
parameter_list|,
name|pp
parameter_list|,
name|i2d_func
parameter_list|,
name|ex_tag
parameter_list|,
name|ex_class
parameter_list|,
name|is_set
parameter_list|)
define|\
value|SKM_ASN1_SET_OF_i2d(PKCS7, (st), (pp), (i2d_func), (ex_tag), (ex_class), (is_set))
end_define

begin_define
define|#
directive|define
name|ASN1_seq_pack_PKCS7
parameter_list|(
name|st
parameter_list|,
name|i2d_func
parameter_list|,
name|buf
parameter_list|,
name|len
parameter_list|)
define|\
value|SKM_ASN1_seq_pack(PKCS7, (st), (i2d_func), (buf), (len))
end_define

begin_define
define|#
directive|define
name|ASN1_seq_unpack_PKCS7
parameter_list|(
name|buf
parameter_list|,
name|len
parameter_list|,
name|d2i_func
parameter_list|,
name|free_func
parameter_list|)
define|\
value|SKM_ASN1_seq_unpack(PKCS7, (buf), (len), (d2i_func), (free_func))
end_define

begin_define
define|#
directive|define
name|d2i_ASN1_SET_OF_PKCS7_RECIP_INFO
parameter_list|(
name|st
parameter_list|,
name|pp
parameter_list|,
name|length
parameter_list|,
name|d2i_func
parameter_list|,
name|free_func
parameter_list|,
name|ex_tag
parameter_list|,
name|ex_class
parameter_list|)
define|\
value|SKM_ASN1_SET_OF_d2i(PKCS7_RECIP_INFO, (st), (pp), (length), (d2i_func), (free_func), (ex_tag), (ex_class))
end_define

begin_define
define|#
directive|define
name|i2d_ASN1_SET_OF_PKCS7_RECIP_INFO
parameter_list|(
name|st
parameter_list|,
name|pp
parameter_list|,
name|i2d_func
parameter_list|,
name|ex_tag
parameter_list|,
name|ex_class
parameter_list|,
name|is_set
parameter_list|)
define|\
value|SKM_ASN1_SET_OF_i2d(PKCS7_RECIP_INFO, (st), (pp), (i2d_func), (ex_tag), (ex_class), (is_set))
end_define

begin_define
define|#
directive|define
name|ASN1_seq_pack_PKCS7_RECIP_INFO
parameter_list|(
name|st
parameter_list|,
name|i2d_func
parameter_list|,
name|buf
parameter_list|,
name|len
parameter_list|)
define|\
value|SKM_ASN1_seq_pack(PKCS7_RECIP_INFO, (st), (i2d_func), (buf), (len))
end_define

begin_define
define|#
directive|define
name|ASN1_seq_unpack_PKCS7_RECIP_INFO
parameter_list|(
name|buf
parameter_list|,
name|len
parameter_list|,
name|d2i_func
parameter_list|,
name|free_func
parameter_list|)
define|\
value|SKM_ASN1_seq_unpack(PKCS7_RECIP_INFO, (buf), (len), (d2i_func), (free_func))
end_define

begin_define
define|#
directive|define
name|d2i_ASN1_SET_OF_PKCS7_SIGNER_INFO
parameter_list|(
name|st
parameter_list|,
name|pp
parameter_list|,
name|length
parameter_list|,
name|d2i_func
parameter_list|,
name|free_func
parameter_list|,
name|ex_tag
parameter_list|,
name|ex_class
parameter_list|)
define|\
value|SKM_ASN1_SET_OF_d2i(PKCS7_SIGNER_INFO, (st), (pp), (length), (d2i_func), (free_func), (ex_tag), (ex_class))
end_define

begin_define
define|#
directive|define
name|i2d_ASN1_SET_OF_PKCS7_SIGNER_INFO
parameter_list|(
name|st
parameter_list|,
name|pp
parameter_list|,
name|i2d_func
parameter_list|,
name|ex_tag
parameter_list|,
name|ex_class
parameter_list|,
name|is_set
parameter_list|)
define|\
value|SKM_ASN1_SET_OF_i2d(PKCS7_SIGNER_INFO, (st), (pp), (i2d_func), (ex_tag), (ex_class), (is_set))
end_define

begin_define
define|#
directive|define
name|ASN1_seq_pack_PKCS7_SIGNER_INFO
parameter_list|(
name|st
parameter_list|,
name|i2d_func
parameter_list|,
name|buf
parameter_list|,
name|len
parameter_list|)
define|\
value|SKM_ASN1_seq_pack(PKCS7_SIGNER_INFO, (st), (i2d_func), (buf), (len))
end_define

begin_define
define|#
directive|define
name|ASN1_seq_unpack_PKCS7_SIGNER_INFO
parameter_list|(
name|buf
parameter_list|,
name|len
parameter_list|,
name|d2i_func
parameter_list|,
name|free_func
parameter_list|)
define|\
value|SKM_ASN1_seq_unpack(PKCS7_SIGNER_INFO, (buf), (len), (d2i_func), (free_func))
end_define

begin_define
define|#
directive|define
name|d2i_ASN1_SET_OF_POLICYINFO
parameter_list|(
name|st
parameter_list|,
name|pp
parameter_list|,
name|length
parameter_list|,
name|d2i_func
parameter_list|,
name|free_func
parameter_list|,
name|ex_tag
parameter_list|,
name|ex_class
parameter_list|)
define|\
value|SKM_ASN1_SET_OF_d2i(POLICYINFO, (st), (pp), (length), (d2i_func), (free_func), (ex_tag), (ex_class))
end_define

begin_define
define|#
directive|define
name|i2d_ASN1_SET_OF_POLICYINFO
parameter_list|(
name|st
parameter_list|,
name|pp
parameter_list|,
name|i2d_func
parameter_list|,
name|ex_tag
parameter_list|,
name|ex_class
parameter_list|,
name|is_set
parameter_list|)
define|\
value|SKM_ASN1_SET_OF_i2d(POLICYINFO, (st), (pp), (i2d_func), (ex_tag), (ex_class), (is_set))
end_define

begin_define
define|#
directive|define
name|ASN1_seq_pack_POLICYINFO
parameter_list|(
name|st
parameter_list|,
name|i2d_func
parameter_list|,
name|buf
parameter_list|,
name|len
parameter_list|)
define|\
value|SKM_ASN1_seq_pack(POLICYINFO, (st), (i2d_func), (buf), (len))
end_define

begin_define
define|#
directive|define
name|ASN1_seq_unpack_POLICYINFO
parameter_list|(
name|buf
parameter_list|,
name|len
parameter_list|,
name|d2i_func
parameter_list|,
name|free_func
parameter_list|)
define|\
value|SKM_ASN1_seq_unpack(POLICYINFO, (buf), (len), (d2i_func), (free_func))
end_define

begin_define
define|#
directive|define
name|d2i_ASN1_SET_OF_POLICYQUALINFO
parameter_list|(
name|st
parameter_list|,
name|pp
parameter_list|,
name|length
parameter_list|,
name|d2i_func
parameter_list|,
name|free_func
parameter_list|,
name|ex_tag
parameter_list|,
name|ex_class
parameter_list|)
define|\
value|SKM_ASN1_SET_OF_d2i(POLICYQUALINFO, (st), (pp), (length), (d2i_func), (free_func), (ex_tag), (ex_class))
end_define

begin_define
define|#
directive|define
name|i2d_ASN1_SET_OF_POLICYQUALINFO
parameter_list|(
name|st
parameter_list|,
name|pp
parameter_list|,
name|i2d_func
parameter_list|,
name|ex_tag
parameter_list|,
name|ex_class
parameter_list|,
name|is_set
parameter_list|)
define|\
value|SKM_ASN1_SET_OF_i2d(POLICYQUALINFO, (st), (pp), (i2d_func), (ex_tag), (ex_class), (is_set))
end_define

begin_define
define|#
directive|define
name|ASN1_seq_pack_POLICYQUALINFO
parameter_list|(
name|st
parameter_list|,
name|i2d_func
parameter_list|,
name|buf
parameter_list|,
name|len
parameter_list|)
define|\
value|SKM_ASN1_seq_pack(POLICYQUALINFO, (st), (i2d_func), (buf), (len))
end_define

begin_define
define|#
directive|define
name|ASN1_seq_unpack_POLICYQUALINFO
parameter_list|(
name|buf
parameter_list|,
name|len
parameter_list|,
name|d2i_func
parameter_list|,
name|free_func
parameter_list|)
define|\
value|SKM_ASN1_seq_unpack(POLICYQUALINFO, (buf), (len), (d2i_func), (free_func))
end_define

begin_define
define|#
directive|define
name|d2i_ASN1_SET_OF_SXNETID
parameter_list|(
name|st
parameter_list|,
name|pp
parameter_list|,
name|length
parameter_list|,
name|d2i_func
parameter_list|,
name|free_func
parameter_list|,
name|ex_tag
parameter_list|,
name|ex_class
parameter_list|)
define|\
value|SKM_ASN1_SET_OF_d2i(SXNETID, (st), (pp), (length), (d2i_func), (free_func), (ex_tag), (ex_class))
end_define

begin_define
define|#
directive|define
name|i2d_ASN1_SET_OF_SXNETID
parameter_list|(
name|st
parameter_list|,
name|pp
parameter_list|,
name|i2d_func
parameter_list|,
name|ex_tag
parameter_list|,
name|ex_class
parameter_list|,
name|is_set
parameter_list|)
define|\
value|SKM_ASN1_SET_OF_i2d(SXNETID, (st), (pp), (i2d_func), (ex_tag), (ex_class), (is_set))
end_define

begin_define
define|#
directive|define
name|ASN1_seq_pack_SXNETID
parameter_list|(
name|st
parameter_list|,
name|i2d_func
parameter_list|,
name|buf
parameter_list|,
name|len
parameter_list|)
define|\
value|SKM_ASN1_seq_pack(SXNETID, (st), (i2d_func), (buf), (len))
end_define

begin_define
define|#
directive|define
name|ASN1_seq_unpack_SXNETID
parameter_list|(
name|buf
parameter_list|,
name|len
parameter_list|,
name|d2i_func
parameter_list|,
name|free_func
parameter_list|)
define|\
value|SKM_ASN1_seq_unpack(SXNETID, (buf), (len), (d2i_func), (free_func))
end_define

begin_define
define|#
directive|define
name|d2i_ASN1_SET_OF_X509
parameter_list|(
name|st
parameter_list|,
name|pp
parameter_list|,
name|length
parameter_list|,
name|d2i_func
parameter_list|,
name|free_func
parameter_list|,
name|ex_tag
parameter_list|,
name|ex_class
parameter_list|)
define|\
value|SKM_ASN1_SET_OF_d2i(X509, (st), (pp), (length), (d2i_func), (free_func), (ex_tag), (ex_class))
end_define

begin_define
define|#
directive|define
name|i2d_ASN1_SET_OF_X509
parameter_list|(
name|st
parameter_list|,
name|pp
parameter_list|,
name|i2d_func
parameter_list|,
name|ex_tag
parameter_list|,
name|ex_class
parameter_list|,
name|is_set
parameter_list|)
define|\
value|SKM_ASN1_SET_OF_i2d(X509, (st), (pp), (i2d_func), (ex_tag), (ex_class), (is_set))
end_define

begin_define
define|#
directive|define
name|ASN1_seq_pack_X509
parameter_list|(
name|st
parameter_list|,
name|i2d_func
parameter_list|,
name|buf
parameter_list|,
name|len
parameter_list|)
define|\
value|SKM_ASN1_seq_pack(X509, (st), (i2d_func), (buf), (len))
end_define

begin_define
define|#
directive|define
name|ASN1_seq_unpack_X509
parameter_list|(
name|buf
parameter_list|,
name|len
parameter_list|,
name|d2i_func
parameter_list|,
name|free_func
parameter_list|)
define|\
value|SKM_ASN1_seq_unpack(X509, (buf), (len), (d2i_func), (free_func))
end_define

begin_define
define|#
directive|define
name|d2i_ASN1_SET_OF_X509_ALGOR
parameter_list|(
name|st
parameter_list|,
name|pp
parameter_list|,
name|length
parameter_list|,
name|d2i_func
parameter_list|,
name|free_func
parameter_list|,
name|ex_tag
parameter_list|,
name|ex_class
parameter_list|)
define|\
value|SKM_ASN1_SET_OF_d2i(X509_ALGOR, (st), (pp), (length), (d2i_func), (free_func), (ex_tag), (ex_class))
end_define

begin_define
define|#
directive|define
name|i2d_ASN1_SET_OF_X509_ALGOR
parameter_list|(
name|st
parameter_list|,
name|pp
parameter_list|,
name|i2d_func
parameter_list|,
name|ex_tag
parameter_list|,
name|ex_class
parameter_list|,
name|is_set
parameter_list|)
define|\
value|SKM_ASN1_SET_OF_i2d(X509_ALGOR, (st), (pp), (i2d_func), (ex_tag), (ex_class), (is_set))
end_define

begin_define
define|#
directive|define
name|ASN1_seq_pack_X509_ALGOR
parameter_list|(
name|st
parameter_list|,
name|i2d_func
parameter_list|,
name|buf
parameter_list|,
name|len
parameter_list|)
define|\
value|SKM_ASN1_seq_pack(X509_ALGOR, (st), (i2d_func), (buf), (len))
end_define

begin_define
define|#
directive|define
name|ASN1_seq_unpack_X509_ALGOR
parameter_list|(
name|buf
parameter_list|,
name|len
parameter_list|,
name|d2i_func
parameter_list|,
name|free_func
parameter_list|)
define|\
value|SKM_ASN1_seq_unpack(X509_ALGOR, (buf), (len), (d2i_func), (free_func))
end_define

begin_define
define|#
directive|define
name|d2i_ASN1_SET_OF_X509_ATTRIBUTE
parameter_list|(
name|st
parameter_list|,
name|pp
parameter_list|,
name|length
parameter_list|,
name|d2i_func
parameter_list|,
name|free_func
parameter_list|,
name|ex_tag
parameter_list|,
name|ex_class
parameter_list|)
define|\
value|SKM_ASN1_SET_OF_d2i(X509_ATTRIBUTE, (st), (pp), (length), (d2i_func), (free_func), (ex_tag), (ex_class))
end_define

begin_define
define|#
directive|define
name|i2d_ASN1_SET_OF_X509_ATTRIBUTE
parameter_list|(
name|st
parameter_list|,
name|pp
parameter_list|,
name|i2d_func
parameter_list|,
name|ex_tag
parameter_list|,
name|ex_class
parameter_list|,
name|is_set
parameter_list|)
define|\
value|SKM_ASN1_SET_OF_i2d(X509_ATTRIBUTE, (st), (pp), (i2d_func), (ex_tag), (ex_class), (is_set))
end_define

begin_define
define|#
directive|define
name|ASN1_seq_pack_X509_ATTRIBUTE
parameter_list|(
name|st
parameter_list|,
name|i2d_func
parameter_list|,
name|buf
parameter_list|,
name|len
parameter_list|)
define|\
value|SKM_ASN1_seq_pack(X509_ATTRIBUTE, (st), (i2d_func), (buf), (len))
end_define

begin_define
define|#
directive|define
name|ASN1_seq_unpack_X509_ATTRIBUTE
parameter_list|(
name|buf
parameter_list|,
name|len
parameter_list|,
name|d2i_func
parameter_list|,
name|free_func
parameter_list|)
define|\
value|SKM_ASN1_seq_unpack(X509_ATTRIBUTE, (buf), (len), (d2i_func), (free_func))
end_define

begin_define
define|#
directive|define
name|d2i_ASN1_SET_OF_X509_CRL
parameter_list|(
name|st
parameter_list|,
name|pp
parameter_list|,
name|length
parameter_list|,
name|d2i_func
parameter_list|,
name|free_func
parameter_list|,
name|ex_tag
parameter_list|,
name|ex_class
parameter_list|)
define|\
value|SKM_ASN1_SET_OF_d2i(X509_CRL, (st), (pp), (length), (d2i_func), (free_func), (ex_tag), (ex_class))
end_define

begin_define
define|#
directive|define
name|i2d_ASN1_SET_OF_X509_CRL
parameter_list|(
name|st
parameter_list|,
name|pp
parameter_list|,
name|i2d_func
parameter_list|,
name|ex_tag
parameter_list|,
name|ex_class
parameter_list|,
name|is_set
parameter_list|)
define|\
value|SKM_ASN1_SET_OF_i2d(X509_CRL, (st), (pp), (i2d_func), (ex_tag), (ex_class), (is_set))
end_define

begin_define
define|#
directive|define
name|ASN1_seq_pack_X509_CRL
parameter_list|(
name|st
parameter_list|,
name|i2d_func
parameter_list|,
name|buf
parameter_list|,
name|len
parameter_list|)
define|\
value|SKM_ASN1_seq_pack(X509_CRL, (st), (i2d_func), (buf), (len))
end_define

begin_define
define|#
directive|define
name|ASN1_seq_unpack_X509_CRL
parameter_list|(
name|buf
parameter_list|,
name|len
parameter_list|,
name|d2i_func
parameter_list|,
name|free_func
parameter_list|)
define|\
value|SKM_ASN1_seq_unpack(X509_CRL, (buf), (len), (d2i_func), (free_func))
end_define

begin_define
define|#
directive|define
name|d2i_ASN1_SET_OF_X509_EXTENSION
parameter_list|(
name|st
parameter_list|,
name|pp
parameter_list|,
name|length
parameter_list|,
name|d2i_func
parameter_list|,
name|free_func
parameter_list|,
name|ex_tag
parameter_list|,
name|ex_class
parameter_list|)
define|\
value|SKM_ASN1_SET_OF_d2i(X509_EXTENSION, (st), (pp), (length), (d2i_func), (free_func), (ex_tag), (ex_class))
end_define

begin_define
define|#
directive|define
name|i2d_ASN1_SET_OF_X509_EXTENSION
parameter_list|(
name|st
parameter_list|,
name|pp
parameter_list|,
name|i2d_func
parameter_list|,
name|ex_tag
parameter_list|,
name|ex_class
parameter_list|,
name|is_set
parameter_list|)
define|\
value|SKM_ASN1_SET_OF_i2d(X509_EXTENSION, (st), (pp), (i2d_func), (ex_tag), (ex_class), (is_set))
end_define

begin_define
define|#
directive|define
name|ASN1_seq_pack_X509_EXTENSION
parameter_list|(
name|st
parameter_list|,
name|i2d_func
parameter_list|,
name|buf
parameter_list|,
name|len
parameter_list|)
define|\
value|SKM_ASN1_seq_pack(X509_EXTENSION, (st), (i2d_func), (buf), (len))
end_define

begin_define
define|#
directive|define
name|ASN1_seq_unpack_X509_EXTENSION
parameter_list|(
name|buf
parameter_list|,
name|len
parameter_list|,
name|d2i_func
parameter_list|,
name|free_func
parameter_list|)
define|\
value|SKM_ASN1_seq_unpack(X509_EXTENSION, (buf), (len), (d2i_func), (free_func))
end_define

begin_define
define|#
directive|define
name|d2i_ASN1_SET_OF_X509_NAME_ENTRY
parameter_list|(
name|st
parameter_list|,
name|pp
parameter_list|,
name|length
parameter_list|,
name|d2i_func
parameter_list|,
name|free_func
parameter_list|,
name|ex_tag
parameter_list|,
name|ex_class
parameter_list|)
define|\
value|SKM_ASN1_SET_OF_d2i(X509_NAME_ENTRY, (st), (pp), (length), (d2i_func), (free_func), (ex_tag), (ex_class))
end_define

begin_define
define|#
directive|define
name|i2d_ASN1_SET_OF_X509_NAME_ENTRY
parameter_list|(
name|st
parameter_list|,
name|pp
parameter_list|,
name|i2d_func
parameter_list|,
name|ex_tag
parameter_list|,
name|ex_class
parameter_list|,
name|is_set
parameter_list|)
define|\
value|SKM_ASN1_SET_OF_i2d(X509_NAME_ENTRY, (st), (pp), (i2d_func), (ex_tag), (ex_class), (is_set))
end_define

begin_define
define|#
directive|define
name|ASN1_seq_pack_X509_NAME_ENTRY
parameter_list|(
name|st
parameter_list|,
name|i2d_func
parameter_list|,
name|buf
parameter_list|,
name|len
parameter_list|)
define|\
value|SKM_ASN1_seq_pack(X509_NAME_ENTRY, (st), (i2d_func), (buf), (len))
end_define

begin_define
define|#
directive|define
name|ASN1_seq_unpack_X509_NAME_ENTRY
parameter_list|(
name|buf
parameter_list|,
name|len
parameter_list|,
name|d2i_func
parameter_list|,
name|free_func
parameter_list|)
define|\
value|SKM_ASN1_seq_unpack(X509_NAME_ENTRY, (buf), (len), (d2i_func), (free_func))
end_define

begin_define
define|#
directive|define
name|d2i_ASN1_SET_OF_X509_REVOKED
parameter_list|(
name|st
parameter_list|,
name|pp
parameter_list|,
name|length
parameter_list|,
name|d2i_func
parameter_list|,
name|free_func
parameter_list|,
name|ex_tag
parameter_list|,
name|ex_class
parameter_list|)
define|\
value|SKM_ASN1_SET_OF_d2i(X509_REVOKED, (st), (pp), (length), (d2i_func), (free_func), (ex_tag), (ex_class))
end_define

begin_define
define|#
directive|define
name|i2d_ASN1_SET_OF_X509_REVOKED
parameter_list|(
name|st
parameter_list|,
name|pp
parameter_list|,
name|i2d_func
parameter_list|,
name|ex_tag
parameter_list|,
name|ex_class
parameter_list|,
name|is_set
parameter_list|)
define|\
value|SKM_ASN1_SET_OF_i2d(X509_REVOKED, (st), (pp), (i2d_func), (ex_tag), (ex_class), (is_set))
end_define

begin_define
define|#
directive|define
name|ASN1_seq_pack_X509_REVOKED
parameter_list|(
name|st
parameter_list|,
name|i2d_func
parameter_list|,
name|buf
parameter_list|,
name|len
parameter_list|)
define|\
value|SKM_ASN1_seq_pack(X509_REVOKED, (st), (i2d_func), (buf), (len))
end_define

begin_define
define|#
directive|define
name|ASN1_seq_unpack_X509_REVOKED
parameter_list|(
name|buf
parameter_list|,
name|len
parameter_list|,
name|d2i_func
parameter_list|,
name|free_func
parameter_list|)
define|\
value|SKM_ASN1_seq_unpack(X509_REVOKED, (buf), (len), (d2i_func), (free_func))
end_define

begin_define
define|#
directive|define
name|PKCS12_decrypt_d2i_PKCS12_SAFEBAG
parameter_list|(
name|algor
parameter_list|,
name|d2i_func
parameter_list|,
name|free_func
parameter_list|,
name|pass
parameter_list|,
name|passlen
parameter_list|,
name|oct
parameter_list|,
name|seq
parameter_list|)
define|\
value|SKM_PKCS12_decrypt_d2i(PKCS12_SAFEBAG, (algor), (d2i_func), (free_func), (pass), (passlen), (oct), (seq))
end_define

begin_define
define|#
directive|define
name|PKCS12_decrypt_d2i_PKCS7
parameter_list|(
name|algor
parameter_list|,
name|d2i_func
parameter_list|,
name|free_func
parameter_list|,
name|pass
parameter_list|,
name|passlen
parameter_list|,
name|oct
parameter_list|,
name|seq
parameter_list|)
define|\
value|SKM_PKCS12_decrypt_d2i(PKCS7, (algor), (d2i_func), (free_func), (pass), (passlen), (oct), (seq))
end_define

begin_comment
comment|/* End of util/mkstack.pl block, you may now edit :-) */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !defined HEADER_SAFESTACK_H */
end_comment

end_unit

