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
name|CHECKED_PTR_OF
define|#
directive|define
name|CHECKED_PTR_OF
parameter_list|(
name|type
parameter_list|,
name|p
parameter_list|)
define|\
value|((void*) (1 ? p : (type*)0))
endif|#
directive|endif
comment|/* In C++ we get problems because an explicit cast is needed from (void *)  * we use CHECKED_STACK_OF to ensure the correct type is passed in the macros  * below.   */
define|#
directive|define
name|CHECKED_STACK_OF
parameter_list|(
name|type
parameter_list|,
name|p
parameter_list|)
define|\
value|((_STACK*) (1 ? p : (STACK_OF(type)*)0))
define|#
directive|define
name|CHECKED_SK_FREE_FUNC
parameter_list|(
name|type
parameter_list|,
name|p
parameter_list|)
define|\
value|((void (*)(void *)) ((1 ? p : (void (*)(type *))0)))
define|#
directive|define
name|CHECKED_SK_FREE_FUNC2
parameter_list|(
name|type
parameter_list|,
name|p
parameter_list|)
define|\
value|((void (*)(void *)) ((1 ? p : (void (*)(type))0)))
define|#
directive|define
name|CHECKED_SK_CMP_FUNC
parameter_list|(
name|type
parameter_list|,
name|p
parameter_list|)
define|\
value|((int (*)(const void *, const void *)) \ 	((1 ? p : (int (*)(const type * const *, const type * const *))0)))
define|#
directive|define
name|STACK_OF
parameter_list|(
name|type
parameter_list|)
value|struct stack_st_##type
define|#
directive|define
name|PREDECLARE_STACK_OF
parameter_list|(
name|type
parameter_list|)
value|STACK_OF(type);
define|#
directive|define
name|DECLARE_STACK_OF
parameter_list|(
name|type
parameter_list|)
define|\
value|STACK_OF(type) \     { \     _STACK stack; \     };
define|#
directive|define
name|DECLARE_SPECIAL_STACK_OF
parameter_list|(
name|type
parameter_list|,
name|type2
parameter_list|)
define|\
value|STACK_OF(type) \     { \     _STACK stack; \     };
define|#
directive|define
name|IMPLEMENT_STACK_OF
parameter_list|(
name|type
parameter_list|)
comment|/* nada (obsolete in new safestack approach)*/
comment|/* Strings are special: normally an lhash entry will point to a single  * (somewhat) mutable object. In the case of strings:  *  * a) Instead of a single char, there is an array of chars, NUL-terminated.  * b) The string may have be immutable.  *  * So, they need their own declarations. Especially important for  * type-checking tools, such as Deputy.  * o * In practice, however, it appears to be hard to have a const  * string. For now, I'm settling for dealing with the fact it is a  * string at all.  */
typedef|typedef
name|char
modifier|*
name|OPENSSL_STRING
typedef|;
typedef|typedef
specifier|const
name|char
modifier|*
name|OPENSSL_CSTRING
typedef|;
comment|/* Confusingly, LHASH_OF(STRING) deals with char ** throughout, but  * STACK_OF(STRING) is really more like STACK_OF(char), only, as  * mentioned above, instead of a single char each entry is a  * NUL-terminated array of chars. So, we have to implement STRING  * specially for STACK_OF. This is dealt with in the autogenerated  * macros below.  */
name|DECLARE_SPECIAL_STACK_OF
argument_list|(
argument|OPENSSL_STRING
argument_list|,
argument|char
argument_list|)
comment|/* Similarly, we sometimes use a block of characters, NOT  * nul-terminated. These should also be distinguished from "normal"  * stacks. */
typedef|typedef
name|void
modifier|*
name|OPENSSL_BLOCK
typedef|;
name|DECLARE_SPECIAL_STACK_OF
argument_list|(
argument|OPENSSL_BLOCK
argument_list|,
argument|void
argument_list|)
comment|/* SKM_sk_... stack macros are internal to safestack.h:  * never use them directly, use sk_<type>_... instead */
define|#
directive|define
name|SKM_sk_new
parameter_list|(
name|type
parameter_list|,
name|cmp
parameter_list|)
define|\
value|((STACK_OF(type) *)sk_new(CHECKED_SK_CMP_FUNC(type, cmp)))
define|#
directive|define
name|SKM_sk_new_null
parameter_list|(
name|type
parameter_list|)
define|\
value|((STACK_OF(type) *)sk_new_null())
define|#
directive|define
name|SKM_sk_free
parameter_list|(
name|type
parameter_list|,
name|st
parameter_list|)
define|\
value|sk_free(CHECKED_STACK_OF(type, st))
define|#
directive|define
name|SKM_sk_num
parameter_list|(
name|type
parameter_list|,
name|st
parameter_list|)
define|\
value|sk_num(CHECKED_STACK_OF(type, st))
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
value|((type *)sk_value(CHECKED_STACK_OF(type, st), i))
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
value|sk_set(CHECKED_STACK_OF(type, st), i, CHECKED_PTR_OF(type, val))
define|#
directive|define
name|SKM_sk_zero
parameter_list|(
name|type
parameter_list|,
name|st
parameter_list|)
define|\
value|sk_zero(CHECKED_STACK_OF(type, st))
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
value|sk_push(CHECKED_STACK_OF(type, st), CHECKED_PTR_OF(type, val))
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
value|sk_unshift(CHECKED_STACK_OF(type, st), CHECKED_PTR_OF(type, val))
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
value|sk_find(CHECKED_STACK_OF(type, st), CHECKED_PTR_OF(type, val))
define|#
directive|define
name|SKM_sk_find_ex
parameter_list|(
name|type
parameter_list|,
name|st
parameter_list|,
name|val
parameter_list|)
define|\
value|sk_find_ex(CHECKED_STACK_OF(type, st), \ 		   CHECKED_PTR_OF(type, val))
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
value|(type *)sk_delete(CHECKED_STACK_OF(type, st), i)
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
value|(type *)sk_delete_ptr(CHECKED_STACK_OF(type, st), CHECKED_PTR_OF(type, ptr))
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
value|sk_insert(CHECKED_STACK_OF(type, st), CHECKED_PTR_OF(type, val), i)
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
value|((int (*)(const type * const *,const type * const *)) \ 	sk_set_cmp_func(CHECKED_STACK_OF(type, st), CHECKED_SK_CMP_FUNC(type, cmp)))
define|#
directive|define
name|SKM_sk_dup
parameter_list|(
name|type
parameter_list|,
name|st
parameter_list|)
define|\
value|(STACK_OF(type) *)sk_dup(CHECKED_STACK_OF(type, st))
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
value|sk_pop_free(CHECKED_STACK_OF(type, st), CHECKED_SK_FREE_FUNC(type, free_func))
define|#
directive|define
name|SKM_sk_shift
parameter_list|(
name|type
parameter_list|,
name|st
parameter_list|)
define|\
value|(type *)sk_shift(CHECKED_STACK_OF(type, st))
define|#
directive|define
name|SKM_sk_pop
parameter_list|(
name|type
parameter_list|,
name|st
parameter_list|)
define|\
value|(type *)sk_pop(CHECKED_STACK_OF(type, st))
define|#
directive|define
name|SKM_sk_sort
parameter_list|(
name|type
parameter_list|,
name|st
parameter_list|)
define|\
value|sk_sort(CHECKED_STACK_OF(type, st))
define|#
directive|define
name|SKM_sk_is_sorted
parameter_list|(
name|type
parameter_list|,
name|st
parameter_list|)
define|\
value|sk_is_sorted(CHECKED_STACK_OF(type, st))
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
value|(STACK_OF(type) *)d2i_ASN1_SET( \ 				(STACK_OF(OPENSSL_BLOCK) **)CHECKED_PTR_OF(STACK_OF(type)*, st), \ 				pp, length, \ 				CHECKED_D2I_OF(type, d2i_func), \ 				CHECKED_SK_FREE_FUNC(type, free_func), \ 				ex_tag, ex_class)
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
value|i2d_ASN1_SET((STACK_OF(OPENSSL_BLOCK) *)CHECKED_STACK_OF(type, st), pp, \ 				CHECKED_I2D_OF(type, i2d_func), \ 				ex_tag, ex_class, is_set)
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
value|ASN1_seq_pack(CHECKED_PTR_OF(STACK_OF(type), st), \ 			CHECKED_I2D_OF(type, i2d_func), buf, len)
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
value|(STACK_OF(type) *)ASN1_seq_unpack(buf, len, CHECKED_D2I_OF(type, d2i_func), CHECKED_SK_FREE_FUNC(type, free_func))
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
value|(STACK_OF(type) *)PKCS12_decrypt_d2i(algor, \ 				CHECKED_D2I_OF(type, d2i_func), \ 				CHECKED_SK_FREE_FUNC(type, free_func), \ 				pass, passlen, oct, seq)
comment|/* This block of defines is updated by util/mkstack.pl, please do not touch! */
define|#
directive|define
name|sk_ACCESS_DESCRIPTION_new
parameter_list|(
name|cmp
parameter_list|)
value|SKM_sk_new(ACCESS_DESCRIPTION, (cmp))
define|#
directive|define
name|sk_ACCESS_DESCRIPTION_new_null
parameter_list|()
value|SKM_sk_new_null(ACCESS_DESCRIPTION)
define|#
directive|define
name|sk_ACCESS_DESCRIPTION_free
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_free(ACCESS_DESCRIPTION, (st))
define|#
directive|define
name|sk_ACCESS_DESCRIPTION_num
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_num(ACCESS_DESCRIPTION, (st))
define|#
directive|define
name|sk_ACCESS_DESCRIPTION_value
parameter_list|(
name|st
parameter_list|,
name|i
parameter_list|)
value|SKM_sk_value(ACCESS_DESCRIPTION, (st), (i))
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
define|#
directive|define
name|sk_ACCESS_DESCRIPTION_zero
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_zero(ACCESS_DESCRIPTION, (st))
define|#
directive|define
name|sk_ACCESS_DESCRIPTION_push
parameter_list|(
name|st
parameter_list|,
name|val
parameter_list|)
value|SKM_sk_push(ACCESS_DESCRIPTION, (st), (val))
define|#
directive|define
name|sk_ACCESS_DESCRIPTION_unshift
parameter_list|(
name|st
parameter_list|,
name|val
parameter_list|)
value|SKM_sk_unshift(ACCESS_DESCRIPTION, (st), (val))
define|#
directive|define
name|sk_ACCESS_DESCRIPTION_find
parameter_list|(
name|st
parameter_list|,
name|val
parameter_list|)
value|SKM_sk_find(ACCESS_DESCRIPTION, (st), (val))
define|#
directive|define
name|sk_ACCESS_DESCRIPTION_find_ex
parameter_list|(
name|st
parameter_list|,
name|val
parameter_list|)
value|SKM_sk_find_ex(ACCESS_DESCRIPTION, (st), (val))
define|#
directive|define
name|sk_ACCESS_DESCRIPTION_delete
parameter_list|(
name|st
parameter_list|,
name|i
parameter_list|)
value|SKM_sk_delete(ACCESS_DESCRIPTION, (st), (i))
define|#
directive|define
name|sk_ACCESS_DESCRIPTION_delete_ptr
parameter_list|(
name|st
parameter_list|,
name|ptr
parameter_list|)
value|SKM_sk_delete_ptr(ACCESS_DESCRIPTION, (st), (ptr))
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
define|#
directive|define
name|sk_ACCESS_DESCRIPTION_set_cmp_func
parameter_list|(
name|st
parameter_list|,
name|cmp
parameter_list|)
value|SKM_sk_set_cmp_func(ACCESS_DESCRIPTION, (st), (cmp))
define|#
directive|define
name|sk_ACCESS_DESCRIPTION_dup
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_dup(ACCESS_DESCRIPTION, st)
define|#
directive|define
name|sk_ACCESS_DESCRIPTION_pop_free
parameter_list|(
name|st
parameter_list|,
name|free_func
parameter_list|)
value|SKM_sk_pop_free(ACCESS_DESCRIPTION, (st), (free_func))
define|#
directive|define
name|sk_ACCESS_DESCRIPTION_shift
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_shift(ACCESS_DESCRIPTION, (st))
define|#
directive|define
name|sk_ACCESS_DESCRIPTION_pop
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_pop(ACCESS_DESCRIPTION, (st))
define|#
directive|define
name|sk_ACCESS_DESCRIPTION_sort
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_sort(ACCESS_DESCRIPTION, (st))
define|#
directive|define
name|sk_ACCESS_DESCRIPTION_is_sorted
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_is_sorted(ACCESS_DESCRIPTION, (st))
define|#
directive|define
name|sk_ASIdOrRange_new
parameter_list|(
name|cmp
parameter_list|)
value|SKM_sk_new(ASIdOrRange, (cmp))
define|#
directive|define
name|sk_ASIdOrRange_new_null
parameter_list|()
value|SKM_sk_new_null(ASIdOrRange)
define|#
directive|define
name|sk_ASIdOrRange_free
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_free(ASIdOrRange, (st))
define|#
directive|define
name|sk_ASIdOrRange_num
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_num(ASIdOrRange, (st))
define|#
directive|define
name|sk_ASIdOrRange_value
parameter_list|(
name|st
parameter_list|,
name|i
parameter_list|)
value|SKM_sk_value(ASIdOrRange, (st), (i))
define|#
directive|define
name|sk_ASIdOrRange_set
parameter_list|(
name|st
parameter_list|,
name|i
parameter_list|,
name|val
parameter_list|)
value|SKM_sk_set(ASIdOrRange, (st), (i), (val))
define|#
directive|define
name|sk_ASIdOrRange_zero
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_zero(ASIdOrRange, (st))
define|#
directive|define
name|sk_ASIdOrRange_push
parameter_list|(
name|st
parameter_list|,
name|val
parameter_list|)
value|SKM_sk_push(ASIdOrRange, (st), (val))
define|#
directive|define
name|sk_ASIdOrRange_unshift
parameter_list|(
name|st
parameter_list|,
name|val
parameter_list|)
value|SKM_sk_unshift(ASIdOrRange, (st), (val))
define|#
directive|define
name|sk_ASIdOrRange_find
parameter_list|(
name|st
parameter_list|,
name|val
parameter_list|)
value|SKM_sk_find(ASIdOrRange, (st), (val))
define|#
directive|define
name|sk_ASIdOrRange_find_ex
parameter_list|(
name|st
parameter_list|,
name|val
parameter_list|)
value|SKM_sk_find_ex(ASIdOrRange, (st), (val))
define|#
directive|define
name|sk_ASIdOrRange_delete
parameter_list|(
name|st
parameter_list|,
name|i
parameter_list|)
value|SKM_sk_delete(ASIdOrRange, (st), (i))
define|#
directive|define
name|sk_ASIdOrRange_delete_ptr
parameter_list|(
name|st
parameter_list|,
name|ptr
parameter_list|)
value|SKM_sk_delete_ptr(ASIdOrRange, (st), (ptr))
define|#
directive|define
name|sk_ASIdOrRange_insert
parameter_list|(
name|st
parameter_list|,
name|val
parameter_list|,
name|i
parameter_list|)
value|SKM_sk_insert(ASIdOrRange, (st), (val), (i))
define|#
directive|define
name|sk_ASIdOrRange_set_cmp_func
parameter_list|(
name|st
parameter_list|,
name|cmp
parameter_list|)
value|SKM_sk_set_cmp_func(ASIdOrRange, (st), (cmp))
define|#
directive|define
name|sk_ASIdOrRange_dup
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_dup(ASIdOrRange, st)
define|#
directive|define
name|sk_ASIdOrRange_pop_free
parameter_list|(
name|st
parameter_list|,
name|free_func
parameter_list|)
value|SKM_sk_pop_free(ASIdOrRange, (st), (free_func))
define|#
directive|define
name|sk_ASIdOrRange_shift
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_shift(ASIdOrRange, (st))
define|#
directive|define
name|sk_ASIdOrRange_pop
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_pop(ASIdOrRange, (st))
define|#
directive|define
name|sk_ASIdOrRange_sort
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_sort(ASIdOrRange, (st))
define|#
directive|define
name|sk_ASIdOrRange_is_sorted
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_is_sorted(ASIdOrRange, (st))
define|#
directive|define
name|sk_ASN1_GENERALSTRING_new
parameter_list|(
name|cmp
parameter_list|)
value|SKM_sk_new(ASN1_GENERALSTRING, (cmp))
define|#
directive|define
name|sk_ASN1_GENERALSTRING_new_null
parameter_list|()
value|SKM_sk_new_null(ASN1_GENERALSTRING)
define|#
directive|define
name|sk_ASN1_GENERALSTRING_free
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_free(ASN1_GENERALSTRING, (st))
define|#
directive|define
name|sk_ASN1_GENERALSTRING_num
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_num(ASN1_GENERALSTRING, (st))
define|#
directive|define
name|sk_ASN1_GENERALSTRING_value
parameter_list|(
name|st
parameter_list|,
name|i
parameter_list|)
value|SKM_sk_value(ASN1_GENERALSTRING, (st), (i))
define|#
directive|define
name|sk_ASN1_GENERALSTRING_set
parameter_list|(
name|st
parameter_list|,
name|i
parameter_list|,
name|val
parameter_list|)
value|SKM_sk_set(ASN1_GENERALSTRING, (st), (i), (val))
define|#
directive|define
name|sk_ASN1_GENERALSTRING_zero
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_zero(ASN1_GENERALSTRING, (st))
define|#
directive|define
name|sk_ASN1_GENERALSTRING_push
parameter_list|(
name|st
parameter_list|,
name|val
parameter_list|)
value|SKM_sk_push(ASN1_GENERALSTRING, (st), (val))
define|#
directive|define
name|sk_ASN1_GENERALSTRING_unshift
parameter_list|(
name|st
parameter_list|,
name|val
parameter_list|)
value|SKM_sk_unshift(ASN1_GENERALSTRING, (st), (val))
define|#
directive|define
name|sk_ASN1_GENERALSTRING_find
parameter_list|(
name|st
parameter_list|,
name|val
parameter_list|)
value|SKM_sk_find(ASN1_GENERALSTRING, (st), (val))
define|#
directive|define
name|sk_ASN1_GENERALSTRING_find_ex
parameter_list|(
name|st
parameter_list|,
name|val
parameter_list|)
value|SKM_sk_find_ex(ASN1_GENERALSTRING, (st), (val))
define|#
directive|define
name|sk_ASN1_GENERALSTRING_delete
parameter_list|(
name|st
parameter_list|,
name|i
parameter_list|)
value|SKM_sk_delete(ASN1_GENERALSTRING, (st), (i))
define|#
directive|define
name|sk_ASN1_GENERALSTRING_delete_ptr
parameter_list|(
name|st
parameter_list|,
name|ptr
parameter_list|)
value|SKM_sk_delete_ptr(ASN1_GENERALSTRING, (st), (ptr))
define|#
directive|define
name|sk_ASN1_GENERALSTRING_insert
parameter_list|(
name|st
parameter_list|,
name|val
parameter_list|,
name|i
parameter_list|)
value|SKM_sk_insert(ASN1_GENERALSTRING, (st), (val), (i))
define|#
directive|define
name|sk_ASN1_GENERALSTRING_set_cmp_func
parameter_list|(
name|st
parameter_list|,
name|cmp
parameter_list|)
value|SKM_sk_set_cmp_func(ASN1_GENERALSTRING, (st), (cmp))
define|#
directive|define
name|sk_ASN1_GENERALSTRING_dup
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_dup(ASN1_GENERALSTRING, st)
define|#
directive|define
name|sk_ASN1_GENERALSTRING_pop_free
parameter_list|(
name|st
parameter_list|,
name|free_func
parameter_list|)
value|SKM_sk_pop_free(ASN1_GENERALSTRING, (st), (free_func))
define|#
directive|define
name|sk_ASN1_GENERALSTRING_shift
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_shift(ASN1_GENERALSTRING, (st))
define|#
directive|define
name|sk_ASN1_GENERALSTRING_pop
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_pop(ASN1_GENERALSTRING, (st))
define|#
directive|define
name|sk_ASN1_GENERALSTRING_sort
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_sort(ASN1_GENERALSTRING, (st))
define|#
directive|define
name|sk_ASN1_GENERALSTRING_is_sorted
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_is_sorted(ASN1_GENERALSTRING, (st))
define|#
directive|define
name|sk_ASN1_INTEGER_new
parameter_list|(
name|cmp
parameter_list|)
value|SKM_sk_new(ASN1_INTEGER, (cmp))
define|#
directive|define
name|sk_ASN1_INTEGER_new_null
parameter_list|()
value|SKM_sk_new_null(ASN1_INTEGER)
define|#
directive|define
name|sk_ASN1_INTEGER_free
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_free(ASN1_INTEGER, (st))
define|#
directive|define
name|sk_ASN1_INTEGER_num
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_num(ASN1_INTEGER, (st))
define|#
directive|define
name|sk_ASN1_INTEGER_value
parameter_list|(
name|st
parameter_list|,
name|i
parameter_list|)
value|SKM_sk_value(ASN1_INTEGER, (st), (i))
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
define|#
directive|define
name|sk_ASN1_INTEGER_zero
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_zero(ASN1_INTEGER, (st))
define|#
directive|define
name|sk_ASN1_INTEGER_push
parameter_list|(
name|st
parameter_list|,
name|val
parameter_list|)
value|SKM_sk_push(ASN1_INTEGER, (st), (val))
define|#
directive|define
name|sk_ASN1_INTEGER_unshift
parameter_list|(
name|st
parameter_list|,
name|val
parameter_list|)
value|SKM_sk_unshift(ASN1_INTEGER, (st), (val))
define|#
directive|define
name|sk_ASN1_INTEGER_find
parameter_list|(
name|st
parameter_list|,
name|val
parameter_list|)
value|SKM_sk_find(ASN1_INTEGER, (st), (val))
define|#
directive|define
name|sk_ASN1_INTEGER_find_ex
parameter_list|(
name|st
parameter_list|,
name|val
parameter_list|)
value|SKM_sk_find_ex(ASN1_INTEGER, (st), (val))
define|#
directive|define
name|sk_ASN1_INTEGER_delete
parameter_list|(
name|st
parameter_list|,
name|i
parameter_list|)
value|SKM_sk_delete(ASN1_INTEGER, (st), (i))
define|#
directive|define
name|sk_ASN1_INTEGER_delete_ptr
parameter_list|(
name|st
parameter_list|,
name|ptr
parameter_list|)
value|SKM_sk_delete_ptr(ASN1_INTEGER, (st), (ptr))
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
define|#
directive|define
name|sk_ASN1_INTEGER_set_cmp_func
parameter_list|(
name|st
parameter_list|,
name|cmp
parameter_list|)
value|SKM_sk_set_cmp_func(ASN1_INTEGER, (st), (cmp))
define|#
directive|define
name|sk_ASN1_INTEGER_dup
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_dup(ASN1_INTEGER, st)
define|#
directive|define
name|sk_ASN1_INTEGER_pop_free
parameter_list|(
name|st
parameter_list|,
name|free_func
parameter_list|)
value|SKM_sk_pop_free(ASN1_INTEGER, (st), (free_func))
define|#
directive|define
name|sk_ASN1_INTEGER_shift
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_shift(ASN1_INTEGER, (st))
define|#
directive|define
name|sk_ASN1_INTEGER_pop
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_pop(ASN1_INTEGER, (st))
define|#
directive|define
name|sk_ASN1_INTEGER_sort
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_sort(ASN1_INTEGER, (st))
define|#
directive|define
name|sk_ASN1_INTEGER_is_sorted
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_is_sorted(ASN1_INTEGER, (st))
define|#
directive|define
name|sk_ASN1_OBJECT_new
parameter_list|(
name|cmp
parameter_list|)
value|SKM_sk_new(ASN1_OBJECT, (cmp))
define|#
directive|define
name|sk_ASN1_OBJECT_new_null
parameter_list|()
value|SKM_sk_new_null(ASN1_OBJECT)
define|#
directive|define
name|sk_ASN1_OBJECT_free
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_free(ASN1_OBJECT, (st))
define|#
directive|define
name|sk_ASN1_OBJECT_num
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_num(ASN1_OBJECT, (st))
define|#
directive|define
name|sk_ASN1_OBJECT_value
parameter_list|(
name|st
parameter_list|,
name|i
parameter_list|)
value|SKM_sk_value(ASN1_OBJECT, (st), (i))
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
define|#
directive|define
name|sk_ASN1_OBJECT_zero
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_zero(ASN1_OBJECT, (st))
define|#
directive|define
name|sk_ASN1_OBJECT_push
parameter_list|(
name|st
parameter_list|,
name|val
parameter_list|)
value|SKM_sk_push(ASN1_OBJECT, (st), (val))
define|#
directive|define
name|sk_ASN1_OBJECT_unshift
parameter_list|(
name|st
parameter_list|,
name|val
parameter_list|)
value|SKM_sk_unshift(ASN1_OBJECT, (st), (val))
define|#
directive|define
name|sk_ASN1_OBJECT_find
parameter_list|(
name|st
parameter_list|,
name|val
parameter_list|)
value|SKM_sk_find(ASN1_OBJECT, (st), (val))
define|#
directive|define
name|sk_ASN1_OBJECT_find_ex
parameter_list|(
name|st
parameter_list|,
name|val
parameter_list|)
value|SKM_sk_find_ex(ASN1_OBJECT, (st), (val))
define|#
directive|define
name|sk_ASN1_OBJECT_delete
parameter_list|(
name|st
parameter_list|,
name|i
parameter_list|)
value|SKM_sk_delete(ASN1_OBJECT, (st), (i))
define|#
directive|define
name|sk_ASN1_OBJECT_delete_ptr
parameter_list|(
name|st
parameter_list|,
name|ptr
parameter_list|)
value|SKM_sk_delete_ptr(ASN1_OBJECT, (st), (ptr))
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
define|#
directive|define
name|sk_ASN1_OBJECT_set_cmp_func
parameter_list|(
name|st
parameter_list|,
name|cmp
parameter_list|)
value|SKM_sk_set_cmp_func(ASN1_OBJECT, (st), (cmp))
define|#
directive|define
name|sk_ASN1_OBJECT_dup
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_dup(ASN1_OBJECT, st)
define|#
directive|define
name|sk_ASN1_OBJECT_pop_free
parameter_list|(
name|st
parameter_list|,
name|free_func
parameter_list|)
value|SKM_sk_pop_free(ASN1_OBJECT, (st), (free_func))
define|#
directive|define
name|sk_ASN1_OBJECT_shift
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_shift(ASN1_OBJECT, (st))
define|#
directive|define
name|sk_ASN1_OBJECT_pop
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_pop(ASN1_OBJECT, (st))
define|#
directive|define
name|sk_ASN1_OBJECT_sort
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_sort(ASN1_OBJECT, (st))
define|#
directive|define
name|sk_ASN1_OBJECT_is_sorted
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_is_sorted(ASN1_OBJECT, (st))
define|#
directive|define
name|sk_ASN1_STRING_TABLE_new
parameter_list|(
name|cmp
parameter_list|)
value|SKM_sk_new(ASN1_STRING_TABLE, (cmp))
define|#
directive|define
name|sk_ASN1_STRING_TABLE_new_null
parameter_list|()
value|SKM_sk_new_null(ASN1_STRING_TABLE)
define|#
directive|define
name|sk_ASN1_STRING_TABLE_free
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_free(ASN1_STRING_TABLE, (st))
define|#
directive|define
name|sk_ASN1_STRING_TABLE_num
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_num(ASN1_STRING_TABLE, (st))
define|#
directive|define
name|sk_ASN1_STRING_TABLE_value
parameter_list|(
name|st
parameter_list|,
name|i
parameter_list|)
value|SKM_sk_value(ASN1_STRING_TABLE, (st), (i))
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
define|#
directive|define
name|sk_ASN1_STRING_TABLE_zero
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_zero(ASN1_STRING_TABLE, (st))
define|#
directive|define
name|sk_ASN1_STRING_TABLE_push
parameter_list|(
name|st
parameter_list|,
name|val
parameter_list|)
value|SKM_sk_push(ASN1_STRING_TABLE, (st), (val))
define|#
directive|define
name|sk_ASN1_STRING_TABLE_unshift
parameter_list|(
name|st
parameter_list|,
name|val
parameter_list|)
value|SKM_sk_unshift(ASN1_STRING_TABLE, (st), (val))
define|#
directive|define
name|sk_ASN1_STRING_TABLE_find
parameter_list|(
name|st
parameter_list|,
name|val
parameter_list|)
value|SKM_sk_find(ASN1_STRING_TABLE, (st), (val))
define|#
directive|define
name|sk_ASN1_STRING_TABLE_find_ex
parameter_list|(
name|st
parameter_list|,
name|val
parameter_list|)
value|SKM_sk_find_ex(ASN1_STRING_TABLE, (st), (val))
define|#
directive|define
name|sk_ASN1_STRING_TABLE_delete
parameter_list|(
name|st
parameter_list|,
name|i
parameter_list|)
value|SKM_sk_delete(ASN1_STRING_TABLE, (st), (i))
define|#
directive|define
name|sk_ASN1_STRING_TABLE_delete_ptr
parameter_list|(
name|st
parameter_list|,
name|ptr
parameter_list|)
value|SKM_sk_delete_ptr(ASN1_STRING_TABLE, (st), (ptr))
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
define|#
directive|define
name|sk_ASN1_STRING_TABLE_set_cmp_func
parameter_list|(
name|st
parameter_list|,
name|cmp
parameter_list|)
value|SKM_sk_set_cmp_func(ASN1_STRING_TABLE, (st), (cmp))
define|#
directive|define
name|sk_ASN1_STRING_TABLE_dup
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_dup(ASN1_STRING_TABLE, st)
define|#
directive|define
name|sk_ASN1_STRING_TABLE_pop_free
parameter_list|(
name|st
parameter_list|,
name|free_func
parameter_list|)
value|SKM_sk_pop_free(ASN1_STRING_TABLE, (st), (free_func))
define|#
directive|define
name|sk_ASN1_STRING_TABLE_shift
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_shift(ASN1_STRING_TABLE, (st))
define|#
directive|define
name|sk_ASN1_STRING_TABLE_pop
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_pop(ASN1_STRING_TABLE, (st))
define|#
directive|define
name|sk_ASN1_STRING_TABLE_sort
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_sort(ASN1_STRING_TABLE, (st))
define|#
directive|define
name|sk_ASN1_STRING_TABLE_is_sorted
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_is_sorted(ASN1_STRING_TABLE, (st))
define|#
directive|define
name|sk_ASN1_TYPE_new
parameter_list|(
name|cmp
parameter_list|)
value|SKM_sk_new(ASN1_TYPE, (cmp))
define|#
directive|define
name|sk_ASN1_TYPE_new_null
parameter_list|()
value|SKM_sk_new_null(ASN1_TYPE)
define|#
directive|define
name|sk_ASN1_TYPE_free
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_free(ASN1_TYPE, (st))
define|#
directive|define
name|sk_ASN1_TYPE_num
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_num(ASN1_TYPE, (st))
define|#
directive|define
name|sk_ASN1_TYPE_value
parameter_list|(
name|st
parameter_list|,
name|i
parameter_list|)
value|SKM_sk_value(ASN1_TYPE, (st), (i))
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
define|#
directive|define
name|sk_ASN1_TYPE_zero
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_zero(ASN1_TYPE, (st))
define|#
directive|define
name|sk_ASN1_TYPE_push
parameter_list|(
name|st
parameter_list|,
name|val
parameter_list|)
value|SKM_sk_push(ASN1_TYPE, (st), (val))
define|#
directive|define
name|sk_ASN1_TYPE_unshift
parameter_list|(
name|st
parameter_list|,
name|val
parameter_list|)
value|SKM_sk_unshift(ASN1_TYPE, (st), (val))
define|#
directive|define
name|sk_ASN1_TYPE_find
parameter_list|(
name|st
parameter_list|,
name|val
parameter_list|)
value|SKM_sk_find(ASN1_TYPE, (st), (val))
define|#
directive|define
name|sk_ASN1_TYPE_find_ex
parameter_list|(
name|st
parameter_list|,
name|val
parameter_list|)
value|SKM_sk_find_ex(ASN1_TYPE, (st), (val))
define|#
directive|define
name|sk_ASN1_TYPE_delete
parameter_list|(
name|st
parameter_list|,
name|i
parameter_list|)
value|SKM_sk_delete(ASN1_TYPE, (st), (i))
define|#
directive|define
name|sk_ASN1_TYPE_delete_ptr
parameter_list|(
name|st
parameter_list|,
name|ptr
parameter_list|)
value|SKM_sk_delete_ptr(ASN1_TYPE, (st), (ptr))
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
define|#
directive|define
name|sk_ASN1_TYPE_set_cmp_func
parameter_list|(
name|st
parameter_list|,
name|cmp
parameter_list|)
value|SKM_sk_set_cmp_func(ASN1_TYPE, (st), (cmp))
define|#
directive|define
name|sk_ASN1_TYPE_dup
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_dup(ASN1_TYPE, st)
define|#
directive|define
name|sk_ASN1_TYPE_pop_free
parameter_list|(
name|st
parameter_list|,
name|free_func
parameter_list|)
value|SKM_sk_pop_free(ASN1_TYPE, (st), (free_func))
define|#
directive|define
name|sk_ASN1_TYPE_shift
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_shift(ASN1_TYPE, (st))
define|#
directive|define
name|sk_ASN1_TYPE_pop
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_pop(ASN1_TYPE, (st))
define|#
directive|define
name|sk_ASN1_TYPE_sort
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_sort(ASN1_TYPE, (st))
define|#
directive|define
name|sk_ASN1_TYPE_is_sorted
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_is_sorted(ASN1_TYPE, (st))
define|#
directive|define
name|sk_ASN1_UTF8STRING_new
parameter_list|(
name|cmp
parameter_list|)
value|SKM_sk_new(ASN1_UTF8STRING, (cmp))
define|#
directive|define
name|sk_ASN1_UTF8STRING_new_null
parameter_list|()
value|SKM_sk_new_null(ASN1_UTF8STRING)
define|#
directive|define
name|sk_ASN1_UTF8STRING_free
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_free(ASN1_UTF8STRING, (st))
define|#
directive|define
name|sk_ASN1_UTF8STRING_num
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_num(ASN1_UTF8STRING, (st))
define|#
directive|define
name|sk_ASN1_UTF8STRING_value
parameter_list|(
name|st
parameter_list|,
name|i
parameter_list|)
value|SKM_sk_value(ASN1_UTF8STRING, (st), (i))
define|#
directive|define
name|sk_ASN1_UTF8STRING_set
parameter_list|(
name|st
parameter_list|,
name|i
parameter_list|,
name|val
parameter_list|)
value|SKM_sk_set(ASN1_UTF8STRING, (st), (i), (val))
define|#
directive|define
name|sk_ASN1_UTF8STRING_zero
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_zero(ASN1_UTF8STRING, (st))
define|#
directive|define
name|sk_ASN1_UTF8STRING_push
parameter_list|(
name|st
parameter_list|,
name|val
parameter_list|)
value|SKM_sk_push(ASN1_UTF8STRING, (st), (val))
define|#
directive|define
name|sk_ASN1_UTF8STRING_unshift
parameter_list|(
name|st
parameter_list|,
name|val
parameter_list|)
value|SKM_sk_unshift(ASN1_UTF8STRING, (st), (val))
define|#
directive|define
name|sk_ASN1_UTF8STRING_find
parameter_list|(
name|st
parameter_list|,
name|val
parameter_list|)
value|SKM_sk_find(ASN1_UTF8STRING, (st), (val))
define|#
directive|define
name|sk_ASN1_UTF8STRING_find_ex
parameter_list|(
name|st
parameter_list|,
name|val
parameter_list|)
value|SKM_sk_find_ex(ASN1_UTF8STRING, (st), (val))
define|#
directive|define
name|sk_ASN1_UTF8STRING_delete
parameter_list|(
name|st
parameter_list|,
name|i
parameter_list|)
value|SKM_sk_delete(ASN1_UTF8STRING, (st), (i))
define|#
directive|define
name|sk_ASN1_UTF8STRING_delete_ptr
parameter_list|(
name|st
parameter_list|,
name|ptr
parameter_list|)
value|SKM_sk_delete_ptr(ASN1_UTF8STRING, (st), (ptr))
define|#
directive|define
name|sk_ASN1_UTF8STRING_insert
parameter_list|(
name|st
parameter_list|,
name|val
parameter_list|,
name|i
parameter_list|)
value|SKM_sk_insert(ASN1_UTF8STRING, (st), (val), (i))
define|#
directive|define
name|sk_ASN1_UTF8STRING_set_cmp_func
parameter_list|(
name|st
parameter_list|,
name|cmp
parameter_list|)
value|SKM_sk_set_cmp_func(ASN1_UTF8STRING, (st), (cmp))
define|#
directive|define
name|sk_ASN1_UTF8STRING_dup
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_dup(ASN1_UTF8STRING, st)
define|#
directive|define
name|sk_ASN1_UTF8STRING_pop_free
parameter_list|(
name|st
parameter_list|,
name|free_func
parameter_list|)
value|SKM_sk_pop_free(ASN1_UTF8STRING, (st), (free_func))
define|#
directive|define
name|sk_ASN1_UTF8STRING_shift
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_shift(ASN1_UTF8STRING, (st))
define|#
directive|define
name|sk_ASN1_UTF8STRING_pop
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_pop(ASN1_UTF8STRING, (st))
define|#
directive|define
name|sk_ASN1_UTF8STRING_sort
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_sort(ASN1_UTF8STRING, (st))
define|#
directive|define
name|sk_ASN1_UTF8STRING_is_sorted
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_is_sorted(ASN1_UTF8STRING, (st))
define|#
directive|define
name|sk_ASN1_VALUE_new
parameter_list|(
name|cmp
parameter_list|)
value|SKM_sk_new(ASN1_VALUE, (cmp))
define|#
directive|define
name|sk_ASN1_VALUE_new_null
parameter_list|()
value|SKM_sk_new_null(ASN1_VALUE)
define|#
directive|define
name|sk_ASN1_VALUE_free
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_free(ASN1_VALUE, (st))
define|#
directive|define
name|sk_ASN1_VALUE_num
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_num(ASN1_VALUE, (st))
define|#
directive|define
name|sk_ASN1_VALUE_value
parameter_list|(
name|st
parameter_list|,
name|i
parameter_list|)
value|SKM_sk_value(ASN1_VALUE, (st), (i))
define|#
directive|define
name|sk_ASN1_VALUE_set
parameter_list|(
name|st
parameter_list|,
name|i
parameter_list|,
name|val
parameter_list|)
value|SKM_sk_set(ASN1_VALUE, (st), (i), (val))
define|#
directive|define
name|sk_ASN1_VALUE_zero
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_zero(ASN1_VALUE, (st))
define|#
directive|define
name|sk_ASN1_VALUE_push
parameter_list|(
name|st
parameter_list|,
name|val
parameter_list|)
value|SKM_sk_push(ASN1_VALUE, (st), (val))
define|#
directive|define
name|sk_ASN1_VALUE_unshift
parameter_list|(
name|st
parameter_list|,
name|val
parameter_list|)
value|SKM_sk_unshift(ASN1_VALUE, (st), (val))
define|#
directive|define
name|sk_ASN1_VALUE_find
parameter_list|(
name|st
parameter_list|,
name|val
parameter_list|)
value|SKM_sk_find(ASN1_VALUE, (st), (val))
define|#
directive|define
name|sk_ASN1_VALUE_find_ex
parameter_list|(
name|st
parameter_list|,
name|val
parameter_list|)
value|SKM_sk_find_ex(ASN1_VALUE, (st), (val))
define|#
directive|define
name|sk_ASN1_VALUE_delete
parameter_list|(
name|st
parameter_list|,
name|i
parameter_list|)
value|SKM_sk_delete(ASN1_VALUE, (st), (i))
define|#
directive|define
name|sk_ASN1_VALUE_delete_ptr
parameter_list|(
name|st
parameter_list|,
name|ptr
parameter_list|)
value|SKM_sk_delete_ptr(ASN1_VALUE, (st), (ptr))
define|#
directive|define
name|sk_ASN1_VALUE_insert
parameter_list|(
name|st
parameter_list|,
name|val
parameter_list|,
name|i
parameter_list|)
value|SKM_sk_insert(ASN1_VALUE, (st), (val), (i))
define|#
directive|define
name|sk_ASN1_VALUE_set_cmp_func
parameter_list|(
name|st
parameter_list|,
name|cmp
parameter_list|)
value|SKM_sk_set_cmp_func(ASN1_VALUE, (st), (cmp))
define|#
directive|define
name|sk_ASN1_VALUE_dup
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_dup(ASN1_VALUE, st)
define|#
directive|define
name|sk_ASN1_VALUE_pop_free
parameter_list|(
name|st
parameter_list|,
name|free_func
parameter_list|)
value|SKM_sk_pop_free(ASN1_VALUE, (st), (free_func))
define|#
directive|define
name|sk_ASN1_VALUE_shift
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_shift(ASN1_VALUE, (st))
define|#
directive|define
name|sk_ASN1_VALUE_pop
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_pop(ASN1_VALUE, (st))
define|#
directive|define
name|sk_ASN1_VALUE_sort
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_sort(ASN1_VALUE, (st))
define|#
directive|define
name|sk_ASN1_VALUE_is_sorted
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_is_sorted(ASN1_VALUE, (st))
define|#
directive|define
name|sk_BIO_new
parameter_list|(
name|cmp
parameter_list|)
value|SKM_sk_new(BIO, (cmp))
define|#
directive|define
name|sk_BIO_new_null
parameter_list|()
value|SKM_sk_new_null(BIO)
define|#
directive|define
name|sk_BIO_free
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_free(BIO, (st))
define|#
directive|define
name|sk_BIO_num
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_num(BIO, (st))
define|#
directive|define
name|sk_BIO_value
parameter_list|(
name|st
parameter_list|,
name|i
parameter_list|)
value|SKM_sk_value(BIO, (st), (i))
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
define|#
directive|define
name|sk_BIO_zero
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_zero(BIO, (st))
define|#
directive|define
name|sk_BIO_push
parameter_list|(
name|st
parameter_list|,
name|val
parameter_list|)
value|SKM_sk_push(BIO, (st), (val))
define|#
directive|define
name|sk_BIO_unshift
parameter_list|(
name|st
parameter_list|,
name|val
parameter_list|)
value|SKM_sk_unshift(BIO, (st), (val))
define|#
directive|define
name|sk_BIO_find
parameter_list|(
name|st
parameter_list|,
name|val
parameter_list|)
value|SKM_sk_find(BIO, (st), (val))
define|#
directive|define
name|sk_BIO_find_ex
parameter_list|(
name|st
parameter_list|,
name|val
parameter_list|)
value|SKM_sk_find_ex(BIO, (st), (val))
define|#
directive|define
name|sk_BIO_delete
parameter_list|(
name|st
parameter_list|,
name|i
parameter_list|)
value|SKM_sk_delete(BIO, (st), (i))
define|#
directive|define
name|sk_BIO_delete_ptr
parameter_list|(
name|st
parameter_list|,
name|ptr
parameter_list|)
value|SKM_sk_delete_ptr(BIO, (st), (ptr))
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
define|#
directive|define
name|sk_BIO_set_cmp_func
parameter_list|(
name|st
parameter_list|,
name|cmp
parameter_list|)
value|SKM_sk_set_cmp_func(BIO, (st), (cmp))
define|#
directive|define
name|sk_BIO_dup
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_dup(BIO, st)
define|#
directive|define
name|sk_BIO_pop_free
parameter_list|(
name|st
parameter_list|,
name|free_func
parameter_list|)
value|SKM_sk_pop_free(BIO, (st), (free_func))
define|#
directive|define
name|sk_BIO_shift
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_shift(BIO, (st))
define|#
directive|define
name|sk_BIO_pop
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_pop(BIO, (st))
define|#
directive|define
name|sk_BIO_sort
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_sort(BIO, (st))
define|#
directive|define
name|sk_BIO_is_sorted
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_is_sorted(BIO, (st))
define|#
directive|define
name|sk_BY_DIR_ENTRY_new
parameter_list|(
name|cmp
parameter_list|)
value|SKM_sk_new(BY_DIR_ENTRY, (cmp))
define|#
directive|define
name|sk_BY_DIR_ENTRY_new_null
parameter_list|()
value|SKM_sk_new_null(BY_DIR_ENTRY)
define|#
directive|define
name|sk_BY_DIR_ENTRY_free
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_free(BY_DIR_ENTRY, (st))
define|#
directive|define
name|sk_BY_DIR_ENTRY_num
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_num(BY_DIR_ENTRY, (st))
define|#
directive|define
name|sk_BY_DIR_ENTRY_value
parameter_list|(
name|st
parameter_list|,
name|i
parameter_list|)
value|SKM_sk_value(BY_DIR_ENTRY, (st), (i))
define|#
directive|define
name|sk_BY_DIR_ENTRY_set
parameter_list|(
name|st
parameter_list|,
name|i
parameter_list|,
name|val
parameter_list|)
value|SKM_sk_set(BY_DIR_ENTRY, (st), (i), (val))
define|#
directive|define
name|sk_BY_DIR_ENTRY_zero
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_zero(BY_DIR_ENTRY, (st))
define|#
directive|define
name|sk_BY_DIR_ENTRY_push
parameter_list|(
name|st
parameter_list|,
name|val
parameter_list|)
value|SKM_sk_push(BY_DIR_ENTRY, (st), (val))
define|#
directive|define
name|sk_BY_DIR_ENTRY_unshift
parameter_list|(
name|st
parameter_list|,
name|val
parameter_list|)
value|SKM_sk_unshift(BY_DIR_ENTRY, (st), (val))
define|#
directive|define
name|sk_BY_DIR_ENTRY_find
parameter_list|(
name|st
parameter_list|,
name|val
parameter_list|)
value|SKM_sk_find(BY_DIR_ENTRY, (st), (val))
define|#
directive|define
name|sk_BY_DIR_ENTRY_find_ex
parameter_list|(
name|st
parameter_list|,
name|val
parameter_list|)
value|SKM_sk_find_ex(BY_DIR_ENTRY, (st), (val))
define|#
directive|define
name|sk_BY_DIR_ENTRY_delete
parameter_list|(
name|st
parameter_list|,
name|i
parameter_list|)
value|SKM_sk_delete(BY_DIR_ENTRY, (st), (i))
define|#
directive|define
name|sk_BY_DIR_ENTRY_delete_ptr
parameter_list|(
name|st
parameter_list|,
name|ptr
parameter_list|)
value|SKM_sk_delete_ptr(BY_DIR_ENTRY, (st), (ptr))
define|#
directive|define
name|sk_BY_DIR_ENTRY_insert
parameter_list|(
name|st
parameter_list|,
name|val
parameter_list|,
name|i
parameter_list|)
value|SKM_sk_insert(BY_DIR_ENTRY, (st), (val), (i))
define|#
directive|define
name|sk_BY_DIR_ENTRY_set_cmp_func
parameter_list|(
name|st
parameter_list|,
name|cmp
parameter_list|)
value|SKM_sk_set_cmp_func(BY_DIR_ENTRY, (st), (cmp))
define|#
directive|define
name|sk_BY_DIR_ENTRY_dup
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_dup(BY_DIR_ENTRY, st)
define|#
directive|define
name|sk_BY_DIR_ENTRY_pop_free
parameter_list|(
name|st
parameter_list|,
name|free_func
parameter_list|)
value|SKM_sk_pop_free(BY_DIR_ENTRY, (st), (free_func))
define|#
directive|define
name|sk_BY_DIR_ENTRY_shift
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_shift(BY_DIR_ENTRY, (st))
define|#
directive|define
name|sk_BY_DIR_ENTRY_pop
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_pop(BY_DIR_ENTRY, (st))
define|#
directive|define
name|sk_BY_DIR_ENTRY_sort
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_sort(BY_DIR_ENTRY, (st))
define|#
directive|define
name|sk_BY_DIR_ENTRY_is_sorted
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_is_sorted(BY_DIR_ENTRY, (st))
define|#
directive|define
name|sk_BY_DIR_HASH_new
parameter_list|(
name|cmp
parameter_list|)
value|SKM_sk_new(BY_DIR_HASH, (cmp))
define|#
directive|define
name|sk_BY_DIR_HASH_new_null
parameter_list|()
value|SKM_sk_new_null(BY_DIR_HASH)
define|#
directive|define
name|sk_BY_DIR_HASH_free
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_free(BY_DIR_HASH, (st))
define|#
directive|define
name|sk_BY_DIR_HASH_num
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_num(BY_DIR_HASH, (st))
define|#
directive|define
name|sk_BY_DIR_HASH_value
parameter_list|(
name|st
parameter_list|,
name|i
parameter_list|)
value|SKM_sk_value(BY_DIR_HASH, (st), (i))
define|#
directive|define
name|sk_BY_DIR_HASH_set
parameter_list|(
name|st
parameter_list|,
name|i
parameter_list|,
name|val
parameter_list|)
value|SKM_sk_set(BY_DIR_HASH, (st), (i), (val))
define|#
directive|define
name|sk_BY_DIR_HASH_zero
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_zero(BY_DIR_HASH, (st))
define|#
directive|define
name|sk_BY_DIR_HASH_push
parameter_list|(
name|st
parameter_list|,
name|val
parameter_list|)
value|SKM_sk_push(BY_DIR_HASH, (st), (val))
define|#
directive|define
name|sk_BY_DIR_HASH_unshift
parameter_list|(
name|st
parameter_list|,
name|val
parameter_list|)
value|SKM_sk_unshift(BY_DIR_HASH, (st), (val))
define|#
directive|define
name|sk_BY_DIR_HASH_find
parameter_list|(
name|st
parameter_list|,
name|val
parameter_list|)
value|SKM_sk_find(BY_DIR_HASH, (st), (val))
define|#
directive|define
name|sk_BY_DIR_HASH_find_ex
parameter_list|(
name|st
parameter_list|,
name|val
parameter_list|)
value|SKM_sk_find_ex(BY_DIR_HASH, (st), (val))
define|#
directive|define
name|sk_BY_DIR_HASH_delete
parameter_list|(
name|st
parameter_list|,
name|i
parameter_list|)
value|SKM_sk_delete(BY_DIR_HASH, (st), (i))
define|#
directive|define
name|sk_BY_DIR_HASH_delete_ptr
parameter_list|(
name|st
parameter_list|,
name|ptr
parameter_list|)
value|SKM_sk_delete_ptr(BY_DIR_HASH, (st), (ptr))
define|#
directive|define
name|sk_BY_DIR_HASH_insert
parameter_list|(
name|st
parameter_list|,
name|val
parameter_list|,
name|i
parameter_list|)
value|SKM_sk_insert(BY_DIR_HASH, (st), (val), (i))
define|#
directive|define
name|sk_BY_DIR_HASH_set_cmp_func
parameter_list|(
name|st
parameter_list|,
name|cmp
parameter_list|)
value|SKM_sk_set_cmp_func(BY_DIR_HASH, (st), (cmp))
define|#
directive|define
name|sk_BY_DIR_HASH_dup
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_dup(BY_DIR_HASH, st)
define|#
directive|define
name|sk_BY_DIR_HASH_pop_free
parameter_list|(
name|st
parameter_list|,
name|free_func
parameter_list|)
value|SKM_sk_pop_free(BY_DIR_HASH, (st), (free_func))
define|#
directive|define
name|sk_BY_DIR_HASH_shift
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_shift(BY_DIR_HASH, (st))
define|#
directive|define
name|sk_BY_DIR_HASH_pop
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_pop(BY_DIR_HASH, (st))
define|#
directive|define
name|sk_BY_DIR_HASH_sort
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_sort(BY_DIR_HASH, (st))
define|#
directive|define
name|sk_BY_DIR_HASH_is_sorted
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_is_sorted(BY_DIR_HASH, (st))
define|#
directive|define
name|sk_CMS_CertificateChoices_new
parameter_list|(
name|cmp
parameter_list|)
value|SKM_sk_new(CMS_CertificateChoices, (cmp))
define|#
directive|define
name|sk_CMS_CertificateChoices_new_null
parameter_list|()
value|SKM_sk_new_null(CMS_CertificateChoices)
define|#
directive|define
name|sk_CMS_CertificateChoices_free
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_free(CMS_CertificateChoices, (st))
define|#
directive|define
name|sk_CMS_CertificateChoices_num
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_num(CMS_CertificateChoices, (st))
define|#
directive|define
name|sk_CMS_CertificateChoices_value
parameter_list|(
name|st
parameter_list|,
name|i
parameter_list|)
value|SKM_sk_value(CMS_CertificateChoices, (st), (i))
define|#
directive|define
name|sk_CMS_CertificateChoices_set
parameter_list|(
name|st
parameter_list|,
name|i
parameter_list|,
name|val
parameter_list|)
value|SKM_sk_set(CMS_CertificateChoices, (st), (i), (val))
define|#
directive|define
name|sk_CMS_CertificateChoices_zero
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_zero(CMS_CertificateChoices, (st))
define|#
directive|define
name|sk_CMS_CertificateChoices_push
parameter_list|(
name|st
parameter_list|,
name|val
parameter_list|)
value|SKM_sk_push(CMS_CertificateChoices, (st), (val))
define|#
directive|define
name|sk_CMS_CertificateChoices_unshift
parameter_list|(
name|st
parameter_list|,
name|val
parameter_list|)
value|SKM_sk_unshift(CMS_CertificateChoices, (st), (val))
define|#
directive|define
name|sk_CMS_CertificateChoices_find
parameter_list|(
name|st
parameter_list|,
name|val
parameter_list|)
value|SKM_sk_find(CMS_CertificateChoices, (st), (val))
define|#
directive|define
name|sk_CMS_CertificateChoices_find_ex
parameter_list|(
name|st
parameter_list|,
name|val
parameter_list|)
value|SKM_sk_find_ex(CMS_CertificateChoices, (st), (val))
define|#
directive|define
name|sk_CMS_CertificateChoices_delete
parameter_list|(
name|st
parameter_list|,
name|i
parameter_list|)
value|SKM_sk_delete(CMS_CertificateChoices, (st), (i))
define|#
directive|define
name|sk_CMS_CertificateChoices_delete_ptr
parameter_list|(
name|st
parameter_list|,
name|ptr
parameter_list|)
value|SKM_sk_delete_ptr(CMS_CertificateChoices, (st), (ptr))
define|#
directive|define
name|sk_CMS_CertificateChoices_insert
parameter_list|(
name|st
parameter_list|,
name|val
parameter_list|,
name|i
parameter_list|)
value|SKM_sk_insert(CMS_CertificateChoices, (st), (val), (i))
define|#
directive|define
name|sk_CMS_CertificateChoices_set_cmp_func
parameter_list|(
name|st
parameter_list|,
name|cmp
parameter_list|)
value|SKM_sk_set_cmp_func(CMS_CertificateChoices, (st), (cmp))
define|#
directive|define
name|sk_CMS_CertificateChoices_dup
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_dup(CMS_CertificateChoices, st)
define|#
directive|define
name|sk_CMS_CertificateChoices_pop_free
parameter_list|(
name|st
parameter_list|,
name|free_func
parameter_list|)
value|SKM_sk_pop_free(CMS_CertificateChoices, (st), (free_func))
define|#
directive|define
name|sk_CMS_CertificateChoices_shift
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_shift(CMS_CertificateChoices, (st))
define|#
directive|define
name|sk_CMS_CertificateChoices_pop
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_pop(CMS_CertificateChoices, (st))
define|#
directive|define
name|sk_CMS_CertificateChoices_sort
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_sort(CMS_CertificateChoices, (st))
define|#
directive|define
name|sk_CMS_CertificateChoices_is_sorted
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_is_sorted(CMS_CertificateChoices, (st))
define|#
directive|define
name|sk_CMS_RecipientInfo_new
parameter_list|(
name|cmp
parameter_list|)
value|SKM_sk_new(CMS_RecipientInfo, (cmp))
define|#
directive|define
name|sk_CMS_RecipientInfo_new_null
parameter_list|()
value|SKM_sk_new_null(CMS_RecipientInfo)
define|#
directive|define
name|sk_CMS_RecipientInfo_free
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_free(CMS_RecipientInfo, (st))
define|#
directive|define
name|sk_CMS_RecipientInfo_num
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_num(CMS_RecipientInfo, (st))
define|#
directive|define
name|sk_CMS_RecipientInfo_value
parameter_list|(
name|st
parameter_list|,
name|i
parameter_list|)
value|SKM_sk_value(CMS_RecipientInfo, (st), (i))
define|#
directive|define
name|sk_CMS_RecipientInfo_set
parameter_list|(
name|st
parameter_list|,
name|i
parameter_list|,
name|val
parameter_list|)
value|SKM_sk_set(CMS_RecipientInfo, (st), (i), (val))
define|#
directive|define
name|sk_CMS_RecipientInfo_zero
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_zero(CMS_RecipientInfo, (st))
define|#
directive|define
name|sk_CMS_RecipientInfo_push
parameter_list|(
name|st
parameter_list|,
name|val
parameter_list|)
value|SKM_sk_push(CMS_RecipientInfo, (st), (val))
define|#
directive|define
name|sk_CMS_RecipientInfo_unshift
parameter_list|(
name|st
parameter_list|,
name|val
parameter_list|)
value|SKM_sk_unshift(CMS_RecipientInfo, (st), (val))
define|#
directive|define
name|sk_CMS_RecipientInfo_find
parameter_list|(
name|st
parameter_list|,
name|val
parameter_list|)
value|SKM_sk_find(CMS_RecipientInfo, (st), (val))
define|#
directive|define
name|sk_CMS_RecipientInfo_find_ex
parameter_list|(
name|st
parameter_list|,
name|val
parameter_list|)
value|SKM_sk_find_ex(CMS_RecipientInfo, (st), (val))
define|#
directive|define
name|sk_CMS_RecipientInfo_delete
parameter_list|(
name|st
parameter_list|,
name|i
parameter_list|)
value|SKM_sk_delete(CMS_RecipientInfo, (st), (i))
define|#
directive|define
name|sk_CMS_RecipientInfo_delete_ptr
parameter_list|(
name|st
parameter_list|,
name|ptr
parameter_list|)
value|SKM_sk_delete_ptr(CMS_RecipientInfo, (st), (ptr))
define|#
directive|define
name|sk_CMS_RecipientInfo_insert
parameter_list|(
name|st
parameter_list|,
name|val
parameter_list|,
name|i
parameter_list|)
value|SKM_sk_insert(CMS_RecipientInfo, (st), (val), (i))
define|#
directive|define
name|sk_CMS_RecipientInfo_set_cmp_func
parameter_list|(
name|st
parameter_list|,
name|cmp
parameter_list|)
value|SKM_sk_set_cmp_func(CMS_RecipientInfo, (st), (cmp))
define|#
directive|define
name|sk_CMS_RecipientInfo_dup
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_dup(CMS_RecipientInfo, st)
define|#
directive|define
name|sk_CMS_RecipientInfo_pop_free
parameter_list|(
name|st
parameter_list|,
name|free_func
parameter_list|)
value|SKM_sk_pop_free(CMS_RecipientInfo, (st), (free_func))
define|#
directive|define
name|sk_CMS_RecipientInfo_shift
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_shift(CMS_RecipientInfo, (st))
define|#
directive|define
name|sk_CMS_RecipientInfo_pop
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_pop(CMS_RecipientInfo, (st))
define|#
directive|define
name|sk_CMS_RecipientInfo_sort
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_sort(CMS_RecipientInfo, (st))
define|#
directive|define
name|sk_CMS_RecipientInfo_is_sorted
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_is_sorted(CMS_RecipientInfo, (st))
define|#
directive|define
name|sk_CMS_RevocationInfoChoice_new
parameter_list|(
name|cmp
parameter_list|)
value|SKM_sk_new(CMS_RevocationInfoChoice, (cmp))
define|#
directive|define
name|sk_CMS_RevocationInfoChoice_new_null
parameter_list|()
value|SKM_sk_new_null(CMS_RevocationInfoChoice)
define|#
directive|define
name|sk_CMS_RevocationInfoChoice_free
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_free(CMS_RevocationInfoChoice, (st))
define|#
directive|define
name|sk_CMS_RevocationInfoChoice_num
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_num(CMS_RevocationInfoChoice, (st))
define|#
directive|define
name|sk_CMS_RevocationInfoChoice_value
parameter_list|(
name|st
parameter_list|,
name|i
parameter_list|)
value|SKM_sk_value(CMS_RevocationInfoChoice, (st), (i))
define|#
directive|define
name|sk_CMS_RevocationInfoChoice_set
parameter_list|(
name|st
parameter_list|,
name|i
parameter_list|,
name|val
parameter_list|)
value|SKM_sk_set(CMS_RevocationInfoChoice, (st), (i), (val))
define|#
directive|define
name|sk_CMS_RevocationInfoChoice_zero
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_zero(CMS_RevocationInfoChoice, (st))
define|#
directive|define
name|sk_CMS_RevocationInfoChoice_push
parameter_list|(
name|st
parameter_list|,
name|val
parameter_list|)
value|SKM_sk_push(CMS_RevocationInfoChoice, (st), (val))
define|#
directive|define
name|sk_CMS_RevocationInfoChoice_unshift
parameter_list|(
name|st
parameter_list|,
name|val
parameter_list|)
value|SKM_sk_unshift(CMS_RevocationInfoChoice, (st), (val))
define|#
directive|define
name|sk_CMS_RevocationInfoChoice_find
parameter_list|(
name|st
parameter_list|,
name|val
parameter_list|)
value|SKM_sk_find(CMS_RevocationInfoChoice, (st), (val))
define|#
directive|define
name|sk_CMS_RevocationInfoChoice_find_ex
parameter_list|(
name|st
parameter_list|,
name|val
parameter_list|)
value|SKM_sk_find_ex(CMS_RevocationInfoChoice, (st), (val))
define|#
directive|define
name|sk_CMS_RevocationInfoChoice_delete
parameter_list|(
name|st
parameter_list|,
name|i
parameter_list|)
value|SKM_sk_delete(CMS_RevocationInfoChoice, (st), (i))
define|#
directive|define
name|sk_CMS_RevocationInfoChoice_delete_ptr
parameter_list|(
name|st
parameter_list|,
name|ptr
parameter_list|)
value|SKM_sk_delete_ptr(CMS_RevocationInfoChoice, (st), (ptr))
define|#
directive|define
name|sk_CMS_RevocationInfoChoice_insert
parameter_list|(
name|st
parameter_list|,
name|val
parameter_list|,
name|i
parameter_list|)
value|SKM_sk_insert(CMS_RevocationInfoChoice, (st), (val), (i))
define|#
directive|define
name|sk_CMS_RevocationInfoChoice_set_cmp_func
parameter_list|(
name|st
parameter_list|,
name|cmp
parameter_list|)
value|SKM_sk_set_cmp_func(CMS_RevocationInfoChoice, (st), (cmp))
define|#
directive|define
name|sk_CMS_RevocationInfoChoice_dup
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_dup(CMS_RevocationInfoChoice, st)
define|#
directive|define
name|sk_CMS_RevocationInfoChoice_pop_free
parameter_list|(
name|st
parameter_list|,
name|free_func
parameter_list|)
value|SKM_sk_pop_free(CMS_RevocationInfoChoice, (st), (free_func))
define|#
directive|define
name|sk_CMS_RevocationInfoChoice_shift
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_shift(CMS_RevocationInfoChoice, (st))
define|#
directive|define
name|sk_CMS_RevocationInfoChoice_pop
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_pop(CMS_RevocationInfoChoice, (st))
define|#
directive|define
name|sk_CMS_RevocationInfoChoice_sort
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_sort(CMS_RevocationInfoChoice, (st))
define|#
directive|define
name|sk_CMS_RevocationInfoChoice_is_sorted
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_is_sorted(CMS_RevocationInfoChoice, (st))
define|#
directive|define
name|sk_CMS_SignerInfo_new
parameter_list|(
name|cmp
parameter_list|)
value|SKM_sk_new(CMS_SignerInfo, (cmp))
define|#
directive|define
name|sk_CMS_SignerInfo_new_null
parameter_list|()
value|SKM_sk_new_null(CMS_SignerInfo)
define|#
directive|define
name|sk_CMS_SignerInfo_free
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_free(CMS_SignerInfo, (st))
define|#
directive|define
name|sk_CMS_SignerInfo_num
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_num(CMS_SignerInfo, (st))
define|#
directive|define
name|sk_CMS_SignerInfo_value
parameter_list|(
name|st
parameter_list|,
name|i
parameter_list|)
value|SKM_sk_value(CMS_SignerInfo, (st), (i))
define|#
directive|define
name|sk_CMS_SignerInfo_set
parameter_list|(
name|st
parameter_list|,
name|i
parameter_list|,
name|val
parameter_list|)
value|SKM_sk_set(CMS_SignerInfo, (st), (i), (val))
define|#
directive|define
name|sk_CMS_SignerInfo_zero
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_zero(CMS_SignerInfo, (st))
define|#
directive|define
name|sk_CMS_SignerInfo_push
parameter_list|(
name|st
parameter_list|,
name|val
parameter_list|)
value|SKM_sk_push(CMS_SignerInfo, (st), (val))
define|#
directive|define
name|sk_CMS_SignerInfo_unshift
parameter_list|(
name|st
parameter_list|,
name|val
parameter_list|)
value|SKM_sk_unshift(CMS_SignerInfo, (st), (val))
define|#
directive|define
name|sk_CMS_SignerInfo_find
parameter_list|(
name|st
parameter_list|,
name|val
parameter_list|)
value|SKM_sk_find(CMS_SignerInfo, (st), (val))
define|#
directive|define
name|sk_CMS_SignerInfo_find_ex
parameter_list|(
name|st
parameter_list|,
name|val
parameter_list|)
value|SKM_sk_find_ex(CMS_SignerInfo, (st), (val))
define|#
directive|define
name|sk_CMS_SignerInfo_delete
parameter_list|(
name|st
parameter_list|,
name|i
parameter_list|)
value|SKM_sk_delete(CMS_SignerInfo, (st), (i))
define|#
directive|define
name|sk_CMS_SignerInfo_delete_ptr
parameter_list|(
name|st
parameter_list|,
name|ptr
parameter_list|)
value|SKM_sk_delete_ptr(CMS_SignerInfo, (st), (ptr))
define|#
directive|define
name|sk_CMS_SignerInfo_insert
parameter_list|(
name|st
parameter_list|,
name|val
parameter_list|,
name|i
parameter_list|)
value|SKM_sk_insert(CMS_SignerInfo, (st), (val), (i))
define|#
directive|define
name|sk_CMS_SignerInfo_set_cmp_func
parameter_list|(
name|st
parameter_list|,
name|cmp
parameter_list|)
value|SKM_sk_set_cmp_func(CMS_SignerInfo, (st), (cmp))
define|#
directive|define
name|sk_CMS_SignerInfo_dup
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_dup(CMS_SignerInfo, st)
define|#
directive|define
name|sk_CMS_SignerInfo_pop_free
parameter_list|(
name|st
parameter_list|,
name|free_func
parameter_list|)
value|SKM_sk_pop_free(CMS_SignerInfo, (st), (free_func))
define|#
directive|define
name|sk_CMS_SignerInfo_shift
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_shift(CMS_SignerInfo, (st))
define|#
directive|define
name|sk_CMS_SignerInfo_pop
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_pop(CMS_SignerInfo, (st))
define|#
directive|define
name|sk_CMS_SignerInfo_sort
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_sort(CMS_SignerInfo, (st))
define|#
directive|define
name|sk_CMS_SignerInfo_is_sorted
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_is_sorted(CMS_SignerInfo, (st))
define|#
directive|define
name|sk_CONF_IMODULE_new
parameter_list|(
name|cmp
parameter_list|)
value|SKM_sk_new(CONF_IMODULE, (cmp))
define|#
directive|define
name|sk_CONF_IMODULE_new_null
parameter_list|()
value|SKM_sk_new_null(CONF_IMODULE)
define|#
directive|define
name|sk_CONF_IMODULE_free
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_free(CONF_IMODULE, (st))
define|#
directive|define
name|sk_CONF_IMODULE_num
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_num(CONF_IMODULE, (st))
define|#
directive|define
name|sk_CONF_IMODULE_value
parameter_list|(
name|st
parameter_list|,
name|i
parameter_list|)
value|SKM_sk_value(CONF_IMODULE, (st), (i))
define|#
directive|define
name|sk_CONF_IMODULE_set
parameter_list|(
name|st
parameter_list|,
name|i
parameter_list|,
name|val
parameter_list|)
value|SKM_sk_set(CONF_IMODULE, (st), (i), (val))
define|#
directive|define
name|sk_CONF_IMODULE_zero
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_zero(CONF_IMODULE, (st))
define|#
directive|define
name|sk_CONF_IMODULE_push
parameter_list|(
name|st
parameter_list|,
name|val
parameter_list|)
value|SKM_sk_push(CONF_IMODULE, (st), (val))
define|#
directive|define
name|sk_CONF_IMODULE_unshift
parameter_list|(
name|st
parameter_list|,
name|val
parameter_list|)
value|SKM_sk_unshift(CONF_IMODULE, (st), (val))
define|#
directive|define
name|sk_CONF_IMODULE_find
parameter_list|(
name|st
parameter_list|,
name|val
parameter_list|)
value|SKM_sk_find(CONF_IMODULE, (st), (val))
define|#
directive|define
name|sk_CONF_IMODULE_find_ex
parameter_list|(
name|st
parameter_list|,
name|val
parameter_list|)
value|SKM_sk_find_ex(CONF_IMODULE, (st), (val))
define|#
directive|define
name|sk_CONF_IMODULE_delete
parameter_list|(
name|st
parameter_list|,
name|i
parameter_list|)
value|SKM_sk_delete(CONF_IMODULE, (st), (i))
define|#
directive|define
name|sk_CONF_IMODULE_delete_ptr
parameter_list|(
name|st
parameter_list|,
name|ptr
parameter_list|)
value|SKM_sk_delete_ptr(CONF_IMODULE, (st), (ptr))
define|#
directive|define
name|sk_CONF_IMODULE_insert
parameter_list|(
name|st
parameter_list|,
name|val
parameter_list|,
name|i
parameter_list|)
value|SKM_sk_insert(CONF_IMODULE, (st), (val), (i))
define|#
directive|define
name|sk_CONF_IMODULE_set_cmp_func
parameter_list|(
name|st
parameter_list|,
name|cmp
parameter_list|)
value|SKM_sk_set_cmp_func(CONF_IMODULE, (st), (cmp))
define|#
directive|define
name|sk_CONF_IMODULE_dup
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_dup(CONF_IMODULE, st)
define|#
directive|define
name|sk_CONF_IMODULE_pop_free
parameter_list|(
name|st
parameter_list|,
name|free_func
parameter_list|)
value|SKM_sk_pop_free(CONF_IMODULE, (st), (free_func))
define|#
directive|define
name|sk_CONF_IMODULE_shift
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_shift(CONF_IMODULE, (st))
define|#
directive|define
name|sk_CONF_IMODULE_pop
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_pop(CONF_IMODULE, (st))
define|#
directive|define
name|sk_CONF_IMODULE_sort
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_sort(CONF_IMODULE, (st))
define|#
directive|define
name|sk_CONF_IMODULE_is_sorted
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_is_sorted(CONF_IMODULE, (st))
define|#
directive|define
name|sk_CONF_MODULE_new
parameter_list|(
name|cmp
parameter_list|)
value|SKM_sk_new(CONF_MODULE, (cmp))
define|#
directive|define
name|sk_CONF_MODULE_new_null
parameter_list|()
value|SKM_sk_new_null(CONF_MODULE)
define|#
directive|define
name|sk_CONF_MODULE_free
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_free(CONF_MODULE, (st))
define|#
directive|define
name|sk_CONF_MODULE_num
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_num(CONF_MODULE, (st))
define|#
directive|define
name|sk_CONF_MODULE_value
parameter_list|(
name|st
parameter_list|,
name|i
parameter_list|)
value|SKM_sk_value(CONF_MODULE, (st), (i))
define|#
directive|define
name|sk_CONF_MODULE_set
parameter_list|(
name|st
parameter_list|,
name|i
parameter_list|,
name|val
parameter_list|)
value|SKM_sk_set(CONF_MODULE, (st), (i), (val))
define|#
directive|define
name|sk_CONF_MODULE_zero
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_zero(CONF_MODULE, (st))
define|#
directive|define
name|sk_CONF_MODULE_push
parameter_list|(
name|st
parameter_list|,
name|val
parameter_list|)
value|SKM_sk_push(CONF_MODULE, (st), (val))
define|#
directive|define
name|sk_CONF_MODULE_unshift
parameter_list|(
name|st
parameter_list|,
name|val
parameter_list|)
value|SKM_sk_unshift(CONF_MODULE, (st), (val))
define|#
directive|define
name|sk_CONF_MODULE_find
parameter_list|(
name|st
parameter_list|,
name|val
parameter_list|)
value|SKM_sk_find(CONF_MODULE, (st), (val))
define|#
directive|define
name|sk_CONF_MODULE_find_ex
parameter_list|(
name|st
parameter_list|,
name|val
parameter_list|)
value|SKM_sk_find_ex(CONF_MODULE, (st), (val))
define|#
directive|define
name|sk_CONF_MODULE_delete
parameter_list|(
name|st
parameter_list|,
name|i
parameter_list|)
value|SKM_sk_delete(CONF_MODULE, (st), (i))
define|#
directive|define
name|sk_CONF_MODULE_delete_ptr
parameter_list|(
name|st
parameter_list|,
name|ptr
parameter_list|)
value|SKM_sk_delete_ptr(CONF_MODULE, (st), (ptr))
define|#
directive|define
name|sk_CONF_MODULE_insert
parameter_list|(
name|st
parameter_list|,
name|val
parameter_list|,
name|i
parameter_list|)
value|SKM_sk_insert(CONF_MODULE, (st), (val), (i))
define|#
directive|define
name|sk_CONF_MODULE_set_cmp_func
parameter_list|(
name|st
parameter_list|,
name|cmp
parameter_list|)
value|SKM_sk_set_cmp_func(CONF_MODULE, (st), (cmp))
define|#
directive|define
name|sk_CONF_MODULE_dup
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_dup(CONF_MODULE, st)
define|#
directive|define
name|sk_CONF_MODULE_pop_free
parameter_list|(
name|st
parameter_list|,
name|free_func
parameter_list|)
value|SKM_sk_pop_free(CONF_MODULE, (st), (free_func))
define|#
directive|define
name|sk_CONF_MODULE_shift
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_shift(CONF_MODULE, (st))
define|#
directive|define
name|sk_CONF_MODULE_pop
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_pop(CONF_MODULE, (st))
define|#
directive|define
name|sk_CONF_MODULE_sort
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_sort(CONF_MODULE, (st))
define|#
directive|define
name|sk_CONF_MODULE_is_sorted
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_is_sorted(CONF_MODULE, (st))
define|#
directive|define
name|sk_CONF_VALUE_new
parameter_list|(
name|cmp
parameter_list|)
value|SKM_sk_new(CONF_VALUE, (cmp))
define|#
directive|define
name|sk_CONF_VALUE_new_null
parameter_list|()
value|SKM_sk_new_null(CONF_VALUE)
define|#
directive|define
name|sk_CONF_VALUE_free
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_free(CONF_VALUE, (st))
define|#
directive|define
name|sk_CONF_VALUE_num
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_num(CONF_VALUE, (st))
define|#
directive|define
name|sk_CONF_VALUE_value
parameter_list|(
name|st
parameter_list|,
name|i
parameter_list|)
value|SKM_sk_value(CONF_VALUE, (st), (i))
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
define|#
directive|define
name|sk_CONF_VALUE_zero
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_zero(CONF_VALUE, (st))
define|#
directive|define
name|sk_CONF_VALUE_push
parameter_list|(
name|st
parameter_list|,
name|val
parameter_list|)
value|SKM_sk_push(CONF_VALUE, (st), (val))
define|#
directive|define
name|sk_CONF_VALUE_unshift
parameter_list|(
name|st
parameter_list|,
name|val
parameter_list|)
value|SKM_sk_unshift(CONF_VALUE, (st), (val))
define|#
directive|define
name|sk_CONF_VALUE_find
parameter_list|(
name|st
parameter_list|,
name|val
parameter_list|)
value|SKM_sk_find(CONF_VALUE, (st), (val))
define|#
directive|define
name|sk_CONF_VALUE_find_ex
parameter_list|(
name|st
parameter_list|,
name|val
parameter_list|)
value|SKM_sk_find_ex(CONF_VALUE, (st), (val))
define|#
directive|define
name|sk_CONF_VALUE_delete
parameter_list|(
name|st
parameter_list|,
name|i
parameter_list|)
value|SKM_sk_delete(CONF_VALUE, (st), (i))
define|#
directive|define
name|sk_CONF_VALUE_delete_ptr
parameter_list|(
name|st
parameter_list|,
name|ptr
parameter_list|)
value|SKM_sk_delete_ptr(CONF_VALUE, (st), (ptr))
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
define|#
directive|define
name|sk_CONF_VALUE_set_cmp_func
parameter_list|(
name|st
parameter_list|,
name|cmp
parameter_list|)
value|SKM_sk_set_cmp_func(CONF_VALUE, (st), (cmp))
define|#
directive|define
name|sk_CONF_VALUE_dup
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_dup(CONF_VALUE, st)
define|#
directive|define
name|sk_CONF_VALUE_pop_free
parameter_list|(
name|st
parameter_list|,
name|free_func
parameter_list|)
value|SKM_sk_pop_free(CONF_VALUE, (st), (free_func))
define|#
directive|define
name|sk_CONF_VALUE_shift
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_shift(CONF_VALUE, (st))
define|#
directive|define
name|sk_CONF_VALUE_pop
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_pop(CONF_VALUE, (st))
define|#
directive|define
name|sk_CONF_VALUE_sort
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_sort(CONF_VALUE, (st))
define|#
directive|define
name|sk_CONF_VALUE_is_sorted
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_is_sorted(CONF_VALUE, (st))
define|#
directive|define
name|sk_CRYPTO_EX_DATA_FUNCS_new
parameter_list|(
name|cmp
parameter_list|)
value|SKM_sk_new(CRYPTO_EX_DATA_FUNCS, (cmp))
define|#
directive|define
name|sk_CRYPTO_EX_DATA_FUNCS_new_null
parameter_list|()
value|SKM_sk_new_null(CRYPTO_EX_DATA_FUNCS)
define|#
directive|define
name|sk_CRYPTO_EX_DATA_FUNCS_free
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_free(CRYPTO_EX_DATA_FUNCS, (st))
define|#
directive|define
name|sk_CRYPTO_EX_DATA_FUNCS_num
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_num(CRYPTO_EX_DATA_FUNCS, (st))
define|#
directive|define
name|sk_CRYPTO_EX_DATA_FUNCS_value
parameter_list|(
name|st
parameter_list|,
name|i
parameter_list|)
value|SKM_sk_value(CRYPTO_EX_DATA_FUNCS, (st), (i))
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
define|#
directive|define
name|sk_CRYPTO_EX_DATA_FUNCS_zero
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_zero(CRYPTO_EX_DATA_FUNCS, (st))
define|#
directive|define
name|sk_CRYPTO_EX_DATA_FUNCS_push
parameter_list|(
name|st
parameter_list|,
name|val
parameter_list|)
value|SKM_sk_push(CRYPTO_EX_DATA_FUNCS, (st), (val))
define|#
directive|define
name|sk_CRYPTO_EX_DATA_FUNCS_unshift
parameter_list|(
name|st
parameter_list|,
name|val
parameter_list|)
value|SKM_sk_unshift(CRYPTO_EX_DATA_FUNCS, (st), (val))
define|#
directive|define
name|sk_CRYPTO_EX_DATA_FUNCS_find
parameter_list|(
name|st
parameter_list|,
name|val
parameter_list|)
value|SKM_sk_find(CRYPTO_EX_DATA_FUNCS, (st), (val))
define|#
directive|define
name|sk_CRYPTO_EX_DATA_FUNCS_find_ex
parameter_list|(
name|st
parameter_list|,
name|val
parameter_list|)
value|SKM_sk_find_ex(CRYPTO_EX_DATA_FUNCS, (st), (val))
define|#
directive|define
name|sk_CRYPTO_EX_DATA_FUNCS_delete
parameter_list|(
name|st
parameter_list|,
name|i
parameter_list|)
value|SKM_sk_delete(CRYPTO_EX_DATA_FUNCS, (st), (i))
define|#
directive|define
name|sk_CRYPTO_EX_DATA_FUNCS_delete_ptr
parameter_list|(
name|st
parameter_list|,
name|ptr
parameter_list|)
value|SKM_sk_delete_ptr(CRYPTO_EX_DATA_FUNCS, (st), (ptr))
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
define|#
directive|define
name|sk_CRYPTO_EX_DATA_FUNCS_set_cmp_func
parameter_list|(
name|st
parameter_list|,
name|cmp
parameter_list|)
value|SKM_sk_set_cmp_func(CRYPTO_EX_DATA_FUNCS, (st), (cmp))
define|#
directive|define
name|sk_CRYPTO_EX_DATA_FUNCS_dup
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_dup(CRYPTO_EX_DATA_FUNCS, st)
define|#
directive|define
name|sk_CRYPTO_EX_DATA_FUNCS_pop_free
parameter_list|(
name|st
parameter_list|,
name|free_func
parameter_list|)
value|SKM_sk_pop_free(CRYPTO_EX_DATA_FUNCS, (st), (free_func))
define|#
directive|define
name|sk_CRYPTO_EX_DATA_FUNCS_shift
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_shift(CRYPTO_EX_DATA_FUNCS, (st))
define|#
directive|define
name|sk_CRYPTO_EX_DATA_FUNCS_pop
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_pop(CRYPTO_EX_DATA_FUNCS, (st))
define|#
directive|define
name|sk_CRYPTO_EX_DATA_FUNCS_sort
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_sort(CRYPTO_EX_DATA_FUNCS, (st))
define|#
directive|define
name|sk_CRYPTO_EX_DATA_FUNCS_is_sorted
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_is_sorted(CRYPTO_EX_DATA_FUNCS, (st))
define|#
directive|define
name|sk_CRYPTO_dynlock_new
parameter_list|(
name|cmp
parameter_list|)
value|SKM_sk_new(CRYPTO_dynlock, (cmp))
define|#
directive|define
name|sk_CRYPTO_dynlock_new_null
parameter_list|()
value|SKM_sk_new_null(CRYPTO_dynlock)
define|#
directive|define
name|sk_CRYPTO_dynlock_free
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_free(CRYPTO_dynlock, (st))
define|#
directive|define
name|sk_CRYPTO_dynlock_num
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_num(CRYPTO_dynlock, (st))
define|#
directive|define
name|sk_CRYPTO_dynlock_value
parameter_list|(
name|st
parameter_list|,
name|i
parameter_list|)
value|SKM_sk_value(CRYPTO_dynlock, (st), (i))
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
define|#
directive|define
name|sk_CRYPTO_dynlock_zero
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_zero(CRYPTO_dynlock, (st))
define|#
directive|define
name|sk_CRYPTO_dynlock_push
parameter_list|(
name|st
parameter_list|,
name|val
parameter_list|)
value|SKM_sk_push(CRYPTO_dynlock, (st), (val))
define|#
directive|define
name|sk_CRYPTO_dynlock_unshift
parameter_list|(
name|st
parameter_list|,
name|val
parameter_list|)
value|SKM_sk_unshift(CRYPTO_dynlock, (st), (val))
define|#
directive|define
name|sk_CRYPTO_dynlock_find
parameter_list|(
name|st
parameter_list|,
name|val
parameter_list|)
value|SKM_sk_find(CRYPTO_dynlock, (st), (val))
define|#
directive|define
name|sk_CRYPTO_dynlock_find_ex
parameter_list|(
name|st
parameter_list|,
name|val
parameter_list|)
value|SKM_sk_find_ex(CRYPTO_dynlock, (st), (val))
define|#
directive|define
name|sk_CRYPTO_dynlock_delete
parameter_list|(
name|st
parameter_list|,
name|i
parameter_list|)
value|SKM_sk_delete(CRYPTO_dynlock, (st), (i))
define|#
directive|define
name|sk_CRYPTO_dynlock_delete_ptr
parameter_list|(
name|st
parameter_list|,
name|ptr
parameter_list|)
value|SKM_sk_delete_ptr(CRYPTO_dynlock, (st), (ptr))
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
define|#
directive|define
name|sk_CRYPTO_dynlock_set_cmp_func
parameter_list|(
name|st
parameter_list|,
name|cmp
parameter_list|)
value|SKM_sk_set_cmp_func(CRYPTO_dynlock, (st), (cmp))
define|#
directive|define
name|sk_CRYPTO_dynlock_dup
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_dup(CRYPTO_dynlock, st)
define|#
directive|define
name|sk_CRYPTO_dynlock_pop_free
parameter_list|(
name|st
parameter_list|,
name|free_func
parameter_list|)
value|SKM_sk_pop_free(CRYPTO_dynlock, (st), (free_func))
define|#
directive|define
name|sk_CRYPTO_dynlock_shift
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_shift(CRYPTO_dynlock, (st))
define|#
directive|define
name|sk_CRYPTO_dynlock_pop
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_pop(CRYPTO_dynlock, (st))
define|#
directive|define
name|sk_CRYPTO_dynlock_sort
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_sort(CRYPTO_dynlock, (st))
define|#
directive|define
name|sk_CRYPTO_dynlock_is_sorted
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_is_sorted(CRYPTO_dynlock, (st))
define|#
directive|define
name|sk_DIST_POINT_new
parameter_list|(
name|cmp
parameter_list|)
value|SKM_sk_new(DIST_POINT, (cmp))
define|#
directive|define
name|sk_DIST_POINT_new_null
parameter_list|()
value|SKM_sk_new_null(DIST_POINT)
define|#
directive|define
name|sk_DIST_POINT_free
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_free(DIST_POINT, (st))
define|#
directive|define
name|sk_DIST_POINT_num
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_num(DIST_POINT, (st))
define|#
directive|define
name|sk_DIST_POINT_value
parameter_list|(
name|st
parameter_list|,
name|i
parameter_list|)
value|SKM_sk_value(DIST_POINT, (st), (i))
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
define|#
directive|define
name|sk_DIST_POINT_zero
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_zero(DIST_POINT, (st))
define|#
directive|define
name|sk_DIST_POINT_push
parameter_list|(
name|st
parameter_list|,
name|val
parameter_list|)
value|SKM_sk_push(DIST_POINT, (st), (val))
define|#
directive|define
name|sk_DIST_POINT_unshift
parameter_list|(
name|st
parameter_list|,
name|val
parameter_list|)
value|SKM_sk_unshift(DIST_POINT, (st), (val))
define|#
directive|define
name|sk_DIST_POINT_find
parameter_list|(
name|st
parameter_list|,
name|val
parameter_list|)
value|SKM_sk_find(DIST_POINT, (st), (val))
define|#
directive|define
name|sk_DIST_POINT_find_ex
parameter_list|(
name|st
parameter_list|,
name|val
parameter_list|)
value|SKM_sk_find_ex(DIST_POINT, (st), (val))
define|#
directive|define
name|sk_DIST_POINT_delete
parameter_list|(
name|st
parameter_list|,
name|i
parameter_list|)
value|SKM_sk_delete(DIST_POINT, (st), (i))
define|#
directive|define
name|sk_DIST_POINT_delete_ptr
parameter_list|(
name|st
parameter_list|,
name|ptr
parameter_list|)
value|SKM_sk_delete_ptr(DIST_POINT, (st), (ptr))
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
define|#
directive|define
name|sk_DIST_POINT_set_cmp_func
parameter_list|(
name|st
parameter_list|,
name|cmp
parameter_list|)
value|SKM_sk_set_cmp_func(DIST_POINT, (st), (cmp))
define|#
directive|define
name|sk_DIST_POINT_dup
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_dup(DIST_POINT, st)
define|#
directive|define
name|sk_DIST_POINT_pop_free
parameter_list|(
name|st
parameter_list|,
name|free_func
parameter_list|)
value|SKM_sk_pop_free(DIST_POINT, (st), (free_func))
define|#
directive|define
name|sk_DIST_POINT_shift
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_shift(DIST_POINT, (st))
define|#
directive|define
name|sk_DIST_POINT_pop
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_pop(DIST_POINT, (st))
define|#
directive|define
name|sk_DIST_POINT_sort
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_sort(DIST_POINT, (st))
define|#
directive|define
name|sk_DIST_POINT_is_sorted
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_is_sorted(DIST_POINT, (st))
define|#
directive|define
name|sk_ENGINE_new
parameter_list|(
name|cmp
parameter_list|)
value|SKM_sk_new(ENGINE, (cmp))
define|#
directive|define
name|sk_ENGINE_new_null
parameter_list|()
value|SKM_sk_new_null(ENGINE)
define|#
directive|define
name|sk_ENGINE_free
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_free(ENGINE, (st))
define|#
directive|define
name|sk_ENGINE_num
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_num(ENGINE, (st))
define|#
directive|define
name|sk_ENGINE_value
parameter_list|(
name|st
parameter_list|,
name|i
parameter_list|)
value|SKM_sk_value(ENGINE, (st), (i))
define|#
directive|define
name|sk_ENGINE_set
parameter_list|(
name|st
parameter_list|,
name|i
parameter_list|,
name|val
parameter_list|)
value|SKM_sk_set(ENGINE, (st), (i), (val))
define|#
directive|define
name|sk_ENGINE_zero
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_zero(ENGINE, (st))
define|#
directive|define
name|sk_ENGINE_push
parameter_list|(
name|st
parameter_list|,
name|val
parameter_list|)
value|SKM_sk_push(ENGINE, (st), (val))
define|#
directive|define
name|sk_ENGINE_unshift
parameter_list|(
name|st
parameter_list|,
name|val
parameter_list|)
value|SKM_sk_unshift(ENGINE, (st), (val))
define|#
directive|define
name|sk_ENGINE_find
parameter_list|(
name|st
parameter_list|,
name|val
parameter_list|)
value|SKM_sk_find(ENGINE, (st), (val))
define|#
directive|define
name|sk_ENGINE_find_ex
parameter_list|(
name|st
parameter_list|,
name|val
parameter_list|)
value|SKM_sk_find_ex(ENGINE, (st), (val))
define|#
directive|define
name|sk_ENGINE_delete
parameter_list|(
name|st
parameter_list|,
name|i
parameter_list|)
value|SKM_sk_delete(ENGINE, (st), (i))
define|#
directive|define
name|sk_ENGINE_delete_ptr
parameter_list|(
name|st
parameter_list|,
name|ptr
parameter_list|)
value|SKM_sk_delete_ptr(ENGINE, (st), (ptr))
define|#
directive|define
name|sk_ENGINE_insert
parameter_list|(
name|st
parameter_list|,
name|val
parameter_list|,
name|i
parameter_list|)
value|SKM_sk_insert(ENGINE, (st), (val), (i))
define|#
directive|define
name|sk_ENGINE_set_cmp_func
parameter_list|(
name|st
parameter_list|,
name|cmp
parameter_list|)
value|SKM_sk_set_cmp_func(ENGINE, (st), (cmp))
define|#
directive|define
name|sk_ENGINE_dup
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_dup(ENGINE, st)
define|#
directive|define
name|sk_ENGINE_pop_free
parameter_list|(
name|st
parameter_list|,
name|free_func
parameter_list|)
value|SKM_sk_pop_free(ENGINE, (st), (free_func))
define|#
directive|define
name|sk_ENGINE_shift
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_shift(ENGINE, (st))
define|#
directive|define
name|sk_ENGINE_pop
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_pop(ENGINE, (st))
define|#
directive|define
name|sk_ENGINE_sort
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_sort(ENGINE, (st))
define|#
directive|define
name|sk_ENGINE_is_sorted
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_is_sorted(ENGINE, (st))
define|#
directive|define
name|sk_ENGINE_CLEANUP_ITEM_new
parameter_list|(
name|cmp
parameter_list|)
value|SKM_sk_new(ENGINE_CLEANUP_ITEM, (cmp))
define|#
directive|define
name|sk_ENGINE_CLEANUP_ITEM_new_null
parameter_list|()
value|SKM_sk_new_null(ENGINE_CLEANUP_ITEM)
define|#
directive|define
name|sk_ENGINE_CLEANUP_ITEM_free
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_free(ENGINE_CLEANUP_ITEM, (st))
define|#
directive|define
name|sk_ENGINE_CLEANUP_ITEM_num
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_num(ENGINE_CLEANUP_ITEM, (st))
define|#
directive|define
name|sk_ENGINE_CLEANUP_ITEM_value
parameter_list|(
name|st
parameter_list|,
name|i
parameter_list|)
value|SKM_sk_value(ENGINE_CLEANUP_ITEM, (st), (i))
define|#
directive|define
name|sk_ENGINE_CLEANUP_ITEM_set
parameter_list|(
name|st
parameter_list|,
name|i
parameter_list|,
name|val
parameter_list|)
value|SKM_sk_set(ENGINE_CLEANUP_ITEM, (st), (i), (val))
define|#
directive|define
name|sk_ENGINE_CLEANUP_ITEM_zero
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_zero(ENGINE_CLEANUP_ITEM, (st))
define|#
directive|define
name|sk_ENGINE_CLEANUP_ITEM_push
parameter_list|(
name|st
parameter_list|,
name|val
parameter_list|)
value|SKM_sk_push(ENGINE_CLEANUP_ITEM, (st), (val))
define|#
directive|define
name|sk_ENGINE_CLEANUP_ITEM_unshift
parameter_list|(
name|st
parameter_list|,
name|val
parameter_list|)
value|SKM_sk_unshift(ENGINE_CLEANUP_ITEM, (st), (val))
define|#
directive|define
name|sk_ENGINE_CLEANUP_ITEM_find
parameter_list|(
name|st
parameter_list|,
name|val
parameter_list|)
value|SKM_sk_find(ENGINE_CLEANUP_ITEM, (st), (val))
define|#
directive|define
name|sk_ENGINE_CLEANUP_ITEM_find_ex
parameter_list|(
name|st
parameter_list|,
name|val
parameter_list|)
value|SKM_sk_find_ex(ENGINE_CLEANUP_ITEM, (st), (val))
define|#
directive|define
name|sk_ENGINE_CLEANUP_ITEM_delete
parameter_list|(
name|st
parameter_list|,
name|i
parameter_list|)
value|SKM_sk_delete(ENGINE_CLEANUP_ITEM, (st), (i))
define|#
directive|define
name|sk_ENGINE_CLEANUP_ITEM_delete_ptr
parameter_list|(
name|st
parameter_list|,
name|ptr
parameter_list|)
value|SKM_sk_delete_ptr(ENGINE_CLEANUP_ITEM, (st), (ptr))
define|#
directive|define
name|sk_ENGINE_CLEANUP_ITEM_insert
parameter_list|(
name|st
parameter_list|,
name|val
parameter_list|,
name|i
parameter_list|)
value|SKM_sk_insert(ENGINE_CLEANUP_ITEM, (st), (val), (i))
define|#
directive|define
name|sk_ENGINE_CLEANUP_ITEM_set_cmp_func
parameter_list|(
name|st
parameter_list|,
name|cmp
parameter_list|)
value|SKM_sk_set_cmp_func(ENGINE_CLEANUP_ITEM, (st), (cmp))
define|#
directive|define
name|sk_ENGINE_CLEANUP_ITEM_dup
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_dup(ENGINE_CLEANUP_ITEM, st)
define|#
directive|define
name|sk_ENGINE_CLEANUP_ITEM_pop_free
parameter_list|(
name|st
parameter_list|,
name|free_func
parameter_list|)
value|SKM_sk_pop_free(ENGINE_CLEANUP_ITEM, (st), (free_func))
define|#
directive|define
name|sk_ENGINE_CLEANUP_ITEM_shift
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_shift(ENGINE_CLEANUP_ITEM, (st))
define|#
directive|define
name|sk_ENGINE_CLEANUP_ITEM_pop
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_pop(ENGINE_CLEANUP_ITEM, (st))
define|#
directive|define
name|sk_ENGINE_CLEANUP_ITEM_sort
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_sort(ENGINE_CLEANUP_ITEM, (st))
define|#
directive|define
name|sk_ENGINE_CLEANUP_ITEM_is_sorted
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_is_sorted(ENGINE_CLEANUP_ITEM, (st))
define|#
directive|define
name|sk_ESS_CERT_ID_new
parameter_list|(
name|cmp
parameter_list|)
value|SKM_sk_new(ESS_CERT_ID, (cmp))
define|#
directive|define
name|sk_ESS_CERT_ID_new_null
parameter_list|()
value|SKM_sk_new_null(ESS_CERT_ID)
define|#
directive|define
name|sk_ESS_CERT_ID_free
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_free(ESS_CERT_ID, (st))
define|#
directive|define
name|sk_ESS_CERT_ID_num
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_num(ESS_CERT_ID, (st))
define|#
directive|define
name|sk_ESS_CERT_ID_value
parameter_list|(
name|st
parameter_list|,
name|i
parameter_list|)
value|SKM_sk_value(ESS_CERT_ID, (st), (i))
define|#
directive|define
name|sk_ESS_CERT_ID_set
parameter_list|(
name|st
parameter_list|,
name|i
parameter_list|,
name|val
parameter_list|)
value|SKM_sk_set(ESS_CERT_ID, (st), (i), (val))
define|#
directive|define
name|sk_ESS_CERT_ID_zero
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_zero(ESS_CERT_ID, (st))
define|#
directive|define
name|sk_ESS_CERT_ID_push
parameter_list|(
name|st
parameter_list|,
name|val
parameter_list|)
value|SKM_sk_push(ESS_CERT_ID, (st), (val))
define|#
directive|define
name|sk_ESS_CERT_ID_unshift
parameter_list|(
name|st
parameter_list|,
name|val
parameter_list|)
value|SKM_sk_unshift(ESS_CERT_ID, (st), (val))
define|#
directive|define
name|sk_ESS_CERT_ID_find
parameter_list|(
name|st
parameter_list|,
name|val
parameter_list|)
value|SKM_sk_find(ESS_CERT_ID, (st), (val))
define|#
directive|define
name|sk_ESS_CERT_ID_find_ex
parameter_list|(
name|st
parameter_list|,
name|val
parameter_list|)
value|SKM_sk_find_ex(ESS_CERT_ID, (st), (val))
define|#
directive|define
name|sk_ESS_CERT_ID_delete
parameter_list|(
name|st
parameter_list|,
name|i
parameter_list|)
value|SKM_sk_delete(ESS_CERT_ID, (st), (i))
define|#
directive|define
name|sk_ESS_CERT_ID_delete_ptr
parameter_list|(
name|st
parameter_list|,
name|ptr
parameter_list|)
value|SKM_sk_delete_ptr(ESS_CERT_ID, (st), (ptr))
define|#
directive|define
name|sk_ESS_CERT_ID_insert
parameter_list|(
name|st
parameter_list|,
name|val
parameter_list|,
name|i
parameter_list|)
value|SKM_sk_insert(ESS_CERT_ID, (st), (val), (i))
define|#
directive|define
name|sk_ESS_CERT_ID_set_cmp_func
parameter_list|(
name|st
parameter_list|,
name|cmp
parameter_list|)
value|SKM_sk_set_cmp_func(ESS_CERT_ID, (st), (cmp))
define|#
directive|define
name|sk_ESS_CERT_ID_dup
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_dup(ESS_CERT_ID, st)
define|#
directive|define
name|sk_ESS_CERT_ID_pop_free
parameter_list|(
name|st
parameter_list|,
name|free_func
parameter_list|)
value|SKM_sk_pop_free(ESS_CERT_ID, (st), (free_func))
define|#
directive|define
name|sk_ESS_CERT_ID_shift
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_shift(ESS_CERT_ID, (st))
define|#
directive|define
name|sk_ESS_CERT_ID_pop
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_pop(ESS_CERT_ID, (st))
define|#
directive|define
name|sk_ESS_CERT_ID_sort
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_sort(ESS_CERT_ID, (st))
define|#
directive|define
name|sk_ESS_CERT_ID_is_sorted
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_is_sorted(ESS_CERT_ID, (st))
define|#
directive|define
name|sk_EVP_MD_new
parameter_list|(
name|cmp
parameter_list|)
value|SKM_sk_new(EVP_MD, (cmp))
define|#
directive|define
name|sk_EVP_MD_new_null
parameter_list|()
value|SKM_sk_new_null(EVP_MD)
define|#
directive|define
name|sk_EVP_MD_free
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_free(EVP_MD, (st))
define|#
directive|define
name|sk_EVP_MD_num
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_num(EVP_MD, (st))
define|#
directive|define
name|sk_EVP_MD_value
parameter_list|(
name|st
parameter_list|,
name|i
parameter_list|)
value|SKM_sk_value(EVP_MD, (st), (i))
define|#
directive|define
name|sk_EVP_MD_set
parameter_list|(
name|st
parameter_list|,
name|i
parameter_list|,
name|val
parameter_list|)
value|SKM_sk_set(EVP_MD, (st), (i), (val))
define|#
directive|define
name|sk_EVP_MD_zero
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_zero(EVP_MD, (st))
define|#
directive|define
name|sk_EVP_MD_push
parameter_list|(
name|st
parameter_list|,
name|val
parameter_list|)
value|SKM_sk_push(EVP_MD, (st), (val))
define|#
directive|define
name|sk_EVP_MD_unshift
parameter_list|(
name|st
parameter_list|,
name|val
parameter_list|)
value|SKM_sk_unshift(EVP_MD, (st), (val))
define|#
directive|define
name|sk_EVP_MD_find
parameter_list|(
name|st
parameter_list|,
name|val
parameter_list|)
value|SKM_sk_find(EVP_MD, (st), (val))
define|#
directive|define
name|sk_EVP_MD_find_ex
parameter_list|(
name|st
parameter_list|,
name|val
parameter_list|)
value|SKM_sk_find_ex(EVP_MD, (st), (val))
define|#
directive|define
name|sk_EVP_MD_delete
parameter_list|(
name|st
parameter_list|,
name|i
parameter_list|)
value|SKM_sk_delete(EVP_MD, (st), (i))
define|#
directive|define
name|sk_EVP_MD_delete_ptr
parameter_list|(
name|st
parameter_list|,
name|ptr
parameter_list|)
value|SKM_sk_delete_ptr(EVP_MD, (st), (ptr))
define|#
directive|define
name|sk_EVP_MD_insert
parameter_list|(
name|st
parameter_list|,
name|val
parameter_list|,
name|i
parameter_list|)
value|SKM_sk_insert(EVP_MD, (st), (val), (i))
define|#
directive|define
name|sk_EVP_MD_set_cmp_func
parameter_list|(
name|st
parameter_list|,
name|cmp
parameter_list|)
value|SKM_sk_set_cmp_func(EVP_MD, (st), (cmp))
define|#
directive|define
name|sk_EVP_MD_dup
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_dup(EVP_MD, st)
define|#
directive|define
name|sk_EVP_MD_pop_free
parameter_list|(
name|st
parameter_list|,
name|free_func
parameter_list|)
value|SKM_sk_pop_free(EVP_MD, (st), (free_func))
define|#
directive|define
name|sk_EVP_MD_shift
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_shift(EVP_MD, (st))
define|#
directive|define
name|sk_EVP_MD_pop
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_pop(EVP_MD, (st))
define|#
directive|define
name|sk_EVP_MD_sort
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_sort(EVP_MD, (st))
define|#
directive|define
name|sk_EVP_MD_is_sorted
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_is_sorted(EVP_MD, (st))
define|#
directive|define
name|sk_EVP_PBE_CTL_new
parameter_list|(
name|cmp
parameter_list|)
value|SKM_sk_new(EVP_PBE_CTL, (cmp))
define|#
directive|define
name|sk_EVP_PBE_CTL_new_null
parameter_list|()
value|SKM_sk_new_null(EVP_PBE_CTL)
define|#
directive|define
name|sk_EVP_PBE_CTL_free
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_free(EVP_PBE_CTL, (st))
define|#
directive|define
name|sk_EVP_PBE_CTL_num
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_num(EVP_PBE_CTL, (st))
define|#
directive|define
name|sk_EVP_PBE_CTL_value
parameter_list|(
name|st
parameter_list|,
name|i
parameter_list|)
value|SKM_sk_value(EVP_PBE_CTL, (st), (i))
define|#
directive|define
name|sk_EVP_PBE_CTL_set
parameter_list|(
name|st
parameter_list|,
name|i
parameter_list|,
name|val
parameter_list|)
value|SKM_sk_set(EVP_PBE_CTL, (st), (i), (val))
define|#
directive|define
name|sk_EVP_PBE_CTL_zero
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_zero(EVP_PBE_CTL, (st))
define|#
directive|define
name|sk_EVP_PBE_CTL_push
parameter_list|(
name|st
parameter_list|,
name|val
parameter_list|)
value|SKM_sk_push(EVP_PBE_CTL, (st), (val))
define|#
directive|define
name|sk_EVP_PBE_CTL_unshift
parameter_list|(
name|st
parameter_list|,
name|val
parameter_list|)
value|SKM_sk_unshift(EVP_PBE_CTL, (st), (val))
define|#
directive|define
name|sk_EVP_PBE_CTL_find
parameter_list|(
name|st
parameter_list|,
name|val
parameter_list|)
value|SKM_sk_find(EVP_PBE_CTL, (st), (val))
define|#
directive|define
name|sk_EVP_PBE_CTL_find_ex
parameter_list|(
name|st
parameter_list|,
name|val
parameter_list|)
value|SKM_sk_find_ex(EVP_PBE_CTL, (st), (val))
define|#
directive|define
name|sk_EVP_PBE_CTL_delete
parameter_list|(
name|st
parameter_list|,
name|i
parameter_list|)
value|SKM_sk_delete(EVP_PBE_CTL, (st), (i))
define|#
directive|define
name|sk_EVP_PBE_CTL_delete_ptr
parameter_list|(
name|st
parameter_list|,
name|ptr
parameter_list|)
value|SKM_sk_delete_ptr(EVP_PBE_CTL, (st), (ptr))
define|#
directive|define
name|sk_EVP_PBE_CTL_insert
parameter_list|(
name|st
parameter_list|,
name|val
parameter_list|,
name|i
parameter_list|)
value|SKM_sk_insert(EVP_PBE_CTL, (st), (val), (i))
define|#
directive|define
name|sk_EVP_PBE_CTL_set_cmp_func
parameter_list|(
name|st
parameter_list|,
name|cmp
parameter_list|)
value|SKM_sk_set_cmp_func(EVP_PBE_CTL, (st), (cmp))
define|#
directive|define
name|sk_EVP_PBE_CTL_dup
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_dup(EVP_PBE_CTL, st)
define|#
directive|define
name|sk_EVP_PBE_CTL_pop_free
parameter_list|(
name|st
parameter_list|,
name|free_func
parameter_list|)
value|SKM_sk_pop_free(EVP_PBE_CTL, (st), (free_func))
define|#
directive|define
name|sk_EVP_PBE_CTL_shift
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_shift(EVP_PBE_CTL, (st))
define|#
directive|define
name|sk_EVP_PBE_CTL_pop
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_pop(EVP_PBE_CTL, (st))
define|#
directive|define
name|sk_EVP_PBE_CTL_sort
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_sort(EVP_PBE_CTL, (st))
define|#
directive|define
name|sk_EVP_PBE_CTL_is_sorted
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_is_sorted(EVP_PBE_CTL, (st))
define|#
directive|define
name|sk_EVP_PKEY_ASN1_METHOD_new
parameter_list|(
name|cmp
parameter_list|)
value|SKM_sk_new(EVP_PKEY_ASN1_METHOD, (cmp))
define|#
directive|define
name|sk_EVP_PKEY_ASN1_METHOD_new_null
parameter_list|()
value|SKM_sk_new_null(EVP_PKEY_ASN1_METHOD)
define|#
directive|define
name|sk_EVP_PKEY_ASN1_METHOD_free
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_free(EVP_PKEY_ASN1_METHOD, (st))
define|#
directive|define
name|sk_EVP_PKEY_ASN1_METHOD_num
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_num(EVP_PKEY_ASN1_METHOD, (st))
define|#
directive|define
name|sk_EVP_PKEY_ASN1_METHOD_value
parameter_list|(
name|st
parameter_list|,
name|i
parameter_list|)
value|SKM_sk_value(EVP_PKEY_ASN1_METHOD, (st), (i))
define|#
directive|define
name|sk_EVP_PKEY_ASN1_METHOD_set
parameter_list|(
name|st
parameter_list|,
name|i
parameter_list|,
name|val
parameter_list|)
value|SKM_sk_set(EVP_PKEY_ASN1_METHOD, (st), (i), (val))
define|#
directive|define
name|sk_EVP_PKEY_ASN1_METHOD_zero
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_zero(EVP_PKEY_ASN1_METHOD, (st))
define|#
directive|define
name|sk_EVP_PKEY_ASN1_METHOD_push
parameter_list|(
name|st
parameter_list|,
name|val
parameter_list|)
value|SKM_sk_push(EVP_PKEY_ASN1_METHOD, (st), (val))
define|#
directive|define
name|sk_EVP_PKEY_ASN1_METHOD_unshift
parameter_list|(
name|st
parameter_list|,
name|val
parameter_list|)
value|SKM_sk_unshift(EVP_PKEY_ASN1_METHOD, (st), (val))
define|#
directive|define
name|sk_EVP_PKEY_ASN1_METHOD_find
parameter_list|(
name|st
parameter_list|,
name|val
parameter_list|)
value|SKM_sk_find(EVP_PKEY_ASN1_METHOD, (st), (val))
define|#
directive|define
name|sk_EVP_PKEY_ASN1_METHOD_find_ex
parameter_list|(
name|st
parameter_list|,
name|val
parameter_list|)
value|SKM_sk_find_ex(EVP_PKEY_ASN1_METHOD, (st), (val))
define|#
directive|define
name|sk_EVP_PKEY_ASN1_METHOD_delete
parameter_list|(
name|st
parameter_list|,
name|i
parameter_list|)
value|SKM_sk_delete(EVP_PKEY_ASN1_METHOD, (st), (i))
define|#
directive|define
name|sk_EVP_PKEY_ASN1_METHOD_delete_ptr
parameter_list|(
name|st
parameter_list|,
name|ptr
parameter_list|)
value|SKM_sk_delete_ptr(EVP_PKEY_ASN1_METHOD, (st), (ptr))
define|#
directive|define
name|sk_EVP_PKEY_ASN1_METHOD_insert
parameter_list|(
name|st
parameter_list|,
name|val
parameter_list|,
name|i
parameter_list|)
value|SKM_sk_insert(EVP_PKEY_ASN1_METHOD, (st), (val), (i))
define|#
directive|define
name|sk_EVP_PKEY_ASN1_METHOD_set_cmp_func
parameter_list|(
name|st
parameter_list|,
name|cmp
parameter_list|)
value|SKM_sk_set_cmp_func(EVP_PKEY_ASN1_METHOD, (st), (cmp))
define|#
directive|define
name|sk_EVP_PKEY_ASN1_METHOD_dup
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_dup(EVP_PKEY_ASN1_METHOD, st)
define|#
directive|define
name|sk_EVP_PKEY_ASN1_METHOD_pop_free
parameter_list|(
name|st
parameter_list|,
name|free_func
parameter_list|)
value|SKM_sk_pop_free(EVP_PKEY_ASN1_METHOD, (st), (free_func))
define|#
directive|define
name|sk_EVP_PKEY_ASN1_METHOD_shift
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_shift(EVP_PKEY_ASN1_METHOD, (st))
define|#
directive|define
name|sk_EVP_PKEY_ASN1_METHOD_pop
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_pop(EVP_PKEY_ASN1_METHOD, (st))
define|#
directive|define
name|sk_EVP_PKEY_ASN1_METHOD_sort
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_sort(EVP_PKEY_ASN1_METHOD, (st))
define|#
directive|define
name|sk_EVP_PKEY_ASN1_METHOD_is_sorted
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_is_sorted(EVP_PKEY_ASN1_METHOD, (st))
define|#
directive|define
name|sk_EVP_PKEY_METHOD_new
parameter_list|(
name|cmp
parameter_list|)
value|SKM_sk_new(EVP_PKEY_METHOD, (cmp))
define|#
directive|define
name|sk_EVP_PKEY_METHOD_new_null
parameter_list|()
value|SKM_sk_new_null(EVP_PKEY_METHOD)
define|#
directive|define
name|sk_EVP_PKEY_METHOD_free
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_free(EVP_PKEY_METHOD, (st))
define|#
directive|define
name|sk_EVP_PKEY_METHOD_num
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_num(EVP_PKEY_METHOD, (st))
define|#
directive|define
name|sk_EVP_PKEY_METHOD_value
parameter_list|(
name|st
parameter_list|,
name|i
parameter_list|)
value|SKM_sk_value(EVP_PKEY_METHOD, (st), (i))
define|#
directive|define
name|sk_EVP_PKEY_METHOD_set
parameter_list|(
name|st
parameter_list|,
name|i
parameter_list|,
name|val
parameter_list|)
value|SKM_sk_set(EVP_PKEY_METHOD, (st), (i), (val))
define|#
directive|define
name|sk_EVP_PKEY_METHOD_zero
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_zero(EVP_PKEY_METHOD, (st))
define|#
directive|define
name|sk_EVP_PKEY_METHOD_push
parameter_list|(
name|st
parameter_list|,
name|val
parameter_list|)
value|SKM_sk_push(EVP_PKEY_METHOD, (st), (val))
define|#
directive|define
name|sk_EVP_PKEY_METHOD_unshift
parameter_list|(
name|st
parameter_list|,
name|val
parameter_list|)
value|SKM_sk_unshift(EVP_PKEY_METHOD, (st), (val))
define|#
directive|define
name|sk_EVP_PKEY_METHOD_find
parameter_list|(
name|st
parameter_list|,
name|val
parameter_list|)
value|SKM_sk_find(EVP_PKEY_METHOD, (st), (val))
define|#
directive|define
name|sk_EVP_PKEY_METHOD_find_ex
parameter_list|(
name|st
parameter_list|,
name|val
parameter_list|)
value|SKM_sk_find_ex(EVP_PKEY_METHOD, (st), (val))
define|#
directive|define
name|sk_EVP_PKEY_METHOD_delete
parameter_list|(
name|st
parameter_list|,
name|i
parameter_list|)
value|SKM_sk_delete(EVP_PKEY_METHOD, (st), (i))
define|#
directive|define
name|sk_EVP_PKEY_METHOD_delete_ptr
parameter_list|(
name|st
parameter_list|,
name|ptr
parameter_list|)
value|SKM_sk_delete_ptr(EVP_PKEY_METHOD, (st), (ptr))
define|#
directive|define
name|sk_EVP_PKEY_METHOD_insert
parameter_list|(
name|st
parameter_list|,
name|val
parameter_list|,
name|i
parameter_list|)
value|SKM_sk_insert(EVP_PKEY_METHOD, (st), (val), (i))
define|#
directive|define
name|sk_EVP_PKEY_METHOD_set_cmp_func
parameter_list|(
name|st
parameter_list|,
name|cmp
parameter_list|)
value|SKM_sk_set_cmp_func(EVP_PKEY_METHOD, (st), (cmp))
define|#
directive|define
name|sk_EVP_PKEY_METHOD_dup
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_dup(EVP_PKEY_METHOD, st)
define|#
directive|define
name|sk_EVP_PKEY_METHOD_pop_free
parameter_list|(
name|st
parameter_list|,
name|free_func
parameter_list|)
value|SKM_sk_pop_free(EVP_PKEY_METHOD, (st), (free_func))
define|#
directive|define
name|sk_EVP_PKEY_METHOD_shift
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_shift(EVP_PKEY_METHOD, (st))
define|#
directive|define
name|sk_EVP_PKEY_METHOD_pop
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_pop(EVP_PKEY_METHOD, (st))
define|#
directive|define
name|sk_EVP_PKEY_METHOD_sort
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_sort(EVP_PKEY_METHOD, (st))
define|#
directive|define
name|sk_EVP_PKEY_METHOD_is_sorted
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_is_sorted(EVP_PKEY_METHOD, (st))
define|#
directive|define
name|sk_GENERAL_NAME_new
parameter_list|(
name|cmp
parameter_list|)
value|SKM_sk_new(GENERAL_NAME, (cmp))
define|#
directive|define
name|sk_GENERAL_NAME_new_null
parameter_list|()
value|SKM_sk_new_null(GENERAL_NAME)
define|#
directive|define
name|sk_GENERAL_NAME_free
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_free(GENERAL_NAME, (st))
define|#
directive|define
name|sk_GENERAL_NAME_num
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_num(GENERAL_NAME, (st))
define|#
directive|define
name|sk_GENERAL_NAME_value
parameter_list|(
name|st
parameter_list|,
name|i
parameter_list|)
value|SKM_sk_value(GENERAL_NAME, (st), (i))
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
define|#
directive|define
name|sk_GENERAL_NAME_zero
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_zero(GENERAL_NAME, (st))
define|#
directive|define
name|sk_GENERAL_NAME_push
parameter_list|(
name|st
parameter_list|,
name|val
parameter_list|)
value|SKM_sk_push(GENERAL_NAME, (st), (val))
define|#
directive|define
name|sk_GENERAL_NAME_unshift
parameter_list|(
name|st
parameter_list|,
name|val
parameter_list|)
value|SKM_sk_unshift(GENERAL_NAME, (st), (val))
define|#
directive|define
name|sk_GENERAL_NAME_find
parameter_list|(
name|st
parameter_list|,
name|val
parameter_list|)
value|SKM_sk_find(GENERAL_NAME, (st), (val))
define|#
directive|define
name|sk_GENERAL_NAME_find_ex
parameter_list|(
name|st
parameter_list|,
name|val
parameter_list|)
value|SKM_sk_find_ex(GENERAL_NAME, (st), (val))
define|#
directive|define
name|sk_GENERAL_NAME_delete
parameter_list|(
name|st
parameter_list|,
name|i
parameter_list|)
value|SKM_sk_delete(GENERAL_NAME, (st), (i))
define|#
directive|define
name|sk_GENERAL_NAME_delete_ptr
parameter_list|(
name|st
parameter_list|,
name|ptr
parameter_list|)
value|SKM_sk_delete_ptr(GENERAL_NAME, (st), (ptr))
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
define|#
directive|define
name|sk_GENERAL_NAME_set_cmp_func
parameter_list|(
name|st
parameter_list|,
name|cmp
parameter_list|)
value|SKM_sk_set_cmp_func(GENERAL_NAME, (st), (cmp))
define|#
directive|define
name|sk_GENERAL_NAME_dup
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_dup(GENERAL_NAME, st)
define|#
directive|define
name|sk_GENERAL_NAME_pop_free
parameter_list|(
name|st
parameter_list|,
name|free_func
parameter_list|)
value|SKM_sk_pop_free(GENERAL_NAME, (st), (free_func))
define|#
directive|define
name|sk_GENERAL_NAME_shift
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_shift(GENERAL_NAME, (st))
define|#
directive|define
name|sk_GENERAL_NAME_pop
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_pop(GENERAL_NAME, (st))
define|#
directive|define
name|sk_GENERAL_NAME_sort
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_sort(GENERAL_NAME, (st))
define|#
directive|define
name|sk_GENERAL_NAME_is_sorted
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_is_sorted(GENERAL_NAME, (st))
define|#
directive|define
name|sk_GENERAL_NAMES_new
parameter_list|(
name|cmp
parameter_list|)
value|SKM_sk_new(GENERAL_NAMES, (cmp))
define|#
directive|define
name|sk_GENERAL_NAMES_new_null
parameter_list|()
value|SKM_sk_new_null(GENERAL_NAMES)
define|#
directive|define
name|sk_GENERAL_NAMES_free
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_free(GENERAL_NAMES, (st))
define|#
directive|define
name|sk_GENERAL_NAMES_num
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_num(GENERAL_NAMES, (st))
define|#
directive|define
name|sk_GENERAL_NAMES_value
parameter_list|(
name|st
parameter_list|,
name|i
parameter_list|)
value|SKM_sk_value(GENERAL_NAMES, (st), (i))
define|#
directive|define
name|sk_GENERAL_NAMES_set
parameter_list|(
name|st
parameter_list|,
name|i
parameter_list|,
name|val
parameter_list|)
value|SKM_sk_set(GENERAL_NAMES, (st), (i), (val))
define|#
directive|define
name|sk_GENERAL_NAMES_zero
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_zero(GENERAL_NAMES, (st))
define|#
directive|define
name|sk_GENERAL_NAMES_push
parameter_list|(
name|st
parameter_list|,
name|val
parameter_list|)
value|SKM_sk_push(GENERAL_NAMES, (st), (val))
define|#
directive|define
name|sk_GENERAL_NAMES_unshift
parameter_list|(
name|st
parameter_list|,
name|val
parameter_list|)
value|SKM_sk_unshift(GENERAL_NAMES, (st), (val))
define|#
directive|define
name|sk_GENERAL_NAMES_find
parameter_list|(
name|st
parameter_list|,
name|val
parameter_list|)
value|SKM_sk_find(GENERAL_NAMES, (st), (val))
define|#
directive|define
name|sk_GENERAL_NAMES_find_ex
parameter_list|(
name|st
parameter_list|,
name|val
parameter_list|)
value|SKM_sk_find_ex(GENERAL_NAMES, (st), (val))
define|#
directive|define
name|sk_GENERAL_NAMES_delete
parameter_list|(
name|st
parameter_list|,
name|i
parameter_list|)
value|SKM_sk_delete(GENERAL_NAMES, (st), (i))
define|#
directive|define
name|sk_GENERAL_NAMES_delete_ptr
parameter_list|(
name|st
parameter_list|,
name|ptr
parameter_list|)
value|SKM_sk_delete_ptr(GENERAL_NAMES, (st), (ptr))
define|#
directive|define
name|sk_GENERAL_NAMES_insert
parameter_list|(
name|st
parameter_list|,
name|val
parameter_list|,
name|i
parameter_list|)
value|SKM_sk_insert(GENERAL_NAMES, (st), (val), (i))
define|#
directive|define
name|sk_GENERAL_NAMES_set_cmp_func
parameter_list|(
name|st
parameter_list|,
name|cmp
parameter_list|)
value|SKM_sk_set_cmp_func(GENERAL_NAMES, (st), (cmp))
define|#
directive|define
name|sk_GENERAL_NAMES_dup
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_dup(GENERAL_NAMES, st)
define|#
directive|define
name|sk_GENERAL_NAMES_pop_free
parameter_list|(
name|st
parameter_list|,
name|free_func
parameter_list|)
value|SKM_sk_pop_free(GENERAL_NAMES, (st), (free_func))
define|#
directive|define
name|sk_GENERAL_NAMES_shift
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_shift(GENERAL_NAMES, (st))
define|#
directive|define
name|sk_GENERAL_NAMES_pop
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_pop(GENERAL_NAMES, (st))
define|#
directive|define
name|sk_GENERAL_NAMES_sort
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_sort(GENERAL_NAMES, (st))
define|#
directive|define
name|sk_GENERAL_NAMES_is_sorted
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_is_sorted(GENERAL_NAMES, (st))
define|#
directive|define
name|sk_GENERAL_SUBTREE_new
parameter_list|(
name|cmp
parameter_list|)
value|SKM_sk_new(GENERAL_SUBTREE, (cmp))
define|#
directive|define
name|sk_GENERAL_SUBTREE_new_null
parameter_list|()
value|SKM_sk_new_null(GENERAL_SUBTREE)
define|#
directive|define
name|sk_GENERAL_SUBTREE_free
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_free(GENERAL_SUBTREE, (st))
define|#
directive|define
name|sk_GENERAL_SUBTREE_num
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_num(GENERAL_SUBTREE, (st))
define|#
directive|define
name|sk_GENERAL_SUBTREE_value
parameter_list|(
name|st
parameter_list|,
name|i
parameter_list|)
value|SKM_sk_value(GENERAL_SUBTREE, (st), (i))
define|#
directive|define
name|sk_GENERAL_SUBTREE_set
parameter_list|(
name|st
parameter_list|,
name|i
parameter_list|,
name|val
parameter_list|)
value|SKM_sk_set(GENERAL_SUBTREE, (st), (i), (val))
define|#
directive|define
name|sk_GENERAL_SUBTREE_zero
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_zero(GENERAL_SUBTREE, (st))
define|#
directive|define
name|sk_GENERAL_SUBTREE_push
parameter_list|(
name|st
parameter_list|,
name|val
parameter_list|)
value|SKM_sk_push(GENERAL_SUBTREE, (st), (val))
define|#
directive|define
name|sk_GENERAL_SUBTREE_unshift
parameter_list|(
name|st
parameter_list|,
name|val
parameter_list|)
value|SKM_sk_unshift(GENERAL_SUBTREE, (st), (val))
define|#
directive|define
name|sk_GENERAL_SUBTREE_find
parameter_list|(
name|st
parameter_list|,
name|val
parameter_list|)
value|SKM_sk_find(GENERAL_SUBTREE, (st), (val))
define|#
directive|define
name|sk_GENERAL_SUBTREE_find_ex
parameter_list|(
name|st
parameter_list|,
name|val
parameter_list|)
value|SKM_sk_find_ex(GENERAL_SUBTREE, (st), (val))
define|#
directive|define
name|sk_GENERAL_SUBTREE_delete
parameter_list|(
name|st
parameter_list|,
name|i
parameter_list|)
value|SKM_sk_delete(GENERAL_SUBTREE, (st), (i))
define|#
directive|define
name|sk_GENERAL_SUBTREE_delete_ptr
parameter_list|(
name|st
parameter_list|,
name|ptr
parameter_list|)
value|SKM_sk_delete_ptr(GENERAL_SUBTREE, (st), (ptr))
define|#
directive|define
name|sk_GENERAL_SUBTREE_insert
parameter_list|(
name|st
parameter_list|,
name|val
parameter_list|,
name|i
parameter_list|)
value|SKM_sk_insert(GENERAL_SUBTREE, (st), (val), (i))
define|#
directive|define
name|sk_GENERAL_SUBTREE_set_cmp_func
parameter_list|(
name|st
parameter_list|,
name|cmp
parameter_list|)
value|SKM_sk_set_cmp_func(GENERAL_SUBTREE, (st), (cmp))
define|#
directive|define
name|sk_GENERAL_SUBTREE_dup
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_dup(GENERAL_SUBTREE, st)
define|#
directive|define
name|sk_GENERAL_SUBTREE_pop_free
parameter_list|(
name|st
parameter_list|,
name|free_func
parameter_list|)
value|SKM_sk_pop_free(GENERAL_SUBTREE, (st), (free_func))
define|#
directive|define
name|sk_GENERAL_SUBTREE_shift
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_shift(GENERAL_SUBTREE, (st))
define|#
directive|define
name|sk_GENERAL_SUBTREE_pop
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_pop(GENERAL_SUBTREE, (st))
define|#
directive|define
name|sk_GENERAL_SUBTREE_sort
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_sort(GENERAL_SUBTREE, (st))
define|#
directive|define
name|sk_GENERAL_SUBTREE_is_sorted
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_is_sorted(GENERAL_SUBTREE, (st))
define|#
directive|define
name|sk_IPAddressFamily_new
parameter_list|(
name|cmp
parameter_list|)
value|SKM_sk_new(IPAddressFamily, (cmp))
define|#
directive|define
name|sk_IPAddressFamily_new_null
parameter_list|()
value|SKM_sk_new_null(IPAddressFamily)
define|#
directive|define
name|sk_IPAddressFamily_free
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_free(IPAddressFamily, (st))
define|#
directive|define
name|sk_IPAddressFamily_num
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_num(IPAddressFamily, (st))
define|#
directive|define
name|sk_IPAddressFamily_value
parameter_list|(
name|st
parameter_list|,
name|i
parameter_list|)
value|SKM_sk_value(IPAddressFamily, (st), (i))
define|#
directive|define
name|sk_IPAddressFamily_set
parameter_list|(
name|st
parameter_list|,
name|i
parameter_list|,
name|val
parameter_list|)
value|SKM_sk_set(IPAddressFamily, (st), (i), (val))
define|#
directive|define
name|sk_IPAddressFamily_zero
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_zero(IPAddressFamily, (st))
define|#
directive|define
name|sk_IPAddressFamily_push
parameter_list|(
name|st
parameter_list|,
name|val
parameter_list|)
value|SKM_sk_push(IPAddressFamily, (st), (val))
define|#
directive|define
name|sk_IPAddressFamily_unshift
parameter_list|(
name|st
parameter_list|,
name|val
parameter_list|)
value|SKM_sk_unshift(IPAddressFamily, (st), (val))
define|#
directive|define
name|sk_IPAddressFamily_find
parameter_list|(
name|st
parameter_list|,
name|val
parameter_list|)
value|SKM_sk_find(IPAddressFamily, (st), (val))
define|#
directive|define
name|sk_IPAddressFamily_find_ex
parameter_list|(
name|st
parameter_list|,
name|val
parameter_list|)
value|SKM_sk_find_ex(IPAddressFamily, (st), (val))
define|#
directive|define
name|sk_IPAddressFamily_delete
parameter_list|(
name|st
parameter_list|,
name|i
parameter_list|)
value|SKM_sk_delete(IPAddressFamily, (st), (i))
define|#
directive|define
name|sk_IPAddressFamily_delete_ptr
parameter_list|(
name|st
parameter_list|,
name|ptr
parameter_list|)
value|SKM_sk_delete_ptr(IPAddressFamily, (st), (ptr))
define|#
directive|define
name|sk_IPAddressFamily_insert
parameter_list|(
name|st
parameter_list|,
name|val
parameter_list|,
name|i
parameter_list|)
value|SKM_sk_insert(IPAddressFamily, (st), (val), (i))
define|#
directive|define
name|sk_IPAddressFamily_set_cmp_func
parameter_list|(
name|st
parameter_list|,
name|cmp
parameter_list|)
value|SKM_sk_set_cmp_func(IPAddressFamily, (st), (cmp))
define|#
directive|define
name|sk_IPAddressFamily_dup
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_dup(IPAddressFamily, st)
define|#
directive|define
name|sk_IPAddressFamily_pop_free
parameter_list|(
name|st
parameter_list|,
name|free_func
parameter_list|)
value|SKM_sk_pop_free(IPAddressFamily, (st), (free_func))
define|#
directive|define
name|sk_IPAddressFamily_shift
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_shift(IPAddressFamily, (st))
define|#
directive|define
name|sk_IPAddressFamily_pop
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_pop(IPAddressFamily, (st))
define|#
directive|define
name|sk_IPAddressFamily_sort
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_sort(IPAddressFamily, (st))
define|#
directive|define
name|sk_IPAddressFamily_is_sorted
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_is_sorted(IPAddressFamily, (st))
define|#
directive|define
name|sk_IPAddressOrRange_new
parameter_list|(
name|cmp
parameter_list|)
value|SKM_sk_new(IPAddressOrRange, (cmp))
define|#
directive|define
name|sk_IPAddressOrRange_new_null
parameter_list|()
value|SKM_sk_new_null(IPAddressOrRange)
define|#
directive|define
name|sk_IPAddressOrRange_free
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_free(IPAddressOrRange, (st))
define|#
directive|define
name|sk_IPAddressOrRange_num
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_num(IPAddressOrRange, (st))
define|#
directive|define
name|sk_IPAddressOrRange_value
parameter_list|(
name|st
parameter_list|,
name|i
parameter_list|)
value|SKM_sk_value(IPAddressOrRange, (st), (i))
define|#
directive|define
name|sk_IPAddressOrRange_set
parameter_list|(
name|st
parameter_list|,
name|i
parameter_list|,
name|val
parameter_list|)
value|SKM_sk_set(IPAddressOrRange, (st), (i), (val))
define|#
directive|define
name|sk_IPAddressOrRange_zero
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_zero(IPAddressOrRange, (st))
define|#
directive|define
name|sk_IPAddressOrRange_push
parameter_list|(
name|st
parameter_list|,
name|val
parameter_list|)
value|SKM_sk_push(IPAddressOrRange, (st), (val))
define|#
directive|define
name|sk_IPAddressOrRange_unshift
parameter_list|(
name|st
parameter_list|,
name|val
parameter_list|)
value|SKM_sk_unshift(IPAddressOrRange, (st), (val))
define|#
directive|define
name|sk_IPAddressOrRange_find
parameter_list|(
name|st
parameter_list|,
name|val
parameter_list|)
value|SKM_sk_find(IPAddressOrRange, (st), (val))
define|#
directive|define
name|sk_IPAddressOrRange_find_ex
parameter_list|(
name|st
parameter_list|,
name|val
parameter_list|)
value|SKM_sk_find_ex(IPAddressOrRange, (st), (val))
define|#
directive|define
name|sk_IPAddressOrRange_delete
parameter_list|(
name|st
parameter_list|,
name|i
parameter_list|)
value|SKM_sk_delete(IPAddressOrRange, (st), (i))
define|#
directive|define
name|sk_IPAddressOrRange_delete_ptr
parameter_list|(
name|st
parameter_list|,
name|ptr
parameter_list|)
value|SKM_sk_delete_ptr(IPAddressOrRange, (st), (ptr))
define|#
directive|define
name|sk_IPAddressOrRange_insert
parameter_list|(
name|st
parameter_list|,
name|val
parameter_list|,
name|i
parameter_list|)
value|SKM_sk_insert(IPAddressOrRange, (st), (val), (i))
define|#
directive|define
name|sk_IPAddressOrRange_set_cmp_func
parameter_list|(
name|st
parameter_list|,
name|cmp
parameter_list|)
value|SKM_sk_set_cmp_func(IPAddressOrRange, (st), (cmp))
define|#
directive|define
name|sk_IPAddressOrRange_dup
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_dup(IPAddressOrRange, st)
define|#
directive|define
name|sk_IPAddressOrRange_pop_free
parameter_list|(
name|st
parameter_list|,
name|free_func
parameter_list|)
value|SKM_sk_pop_free(IPAddressOrRange, (st), (free_func))
define|#
directive|define
name|sk_IPAddressOrRange_shift
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_shift(IPAddressOrRange, (st))
define|#
directive|define
name|sk_IPAddressOrRange_pop
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_pop(IPAddressOrRange, (st))
define|#
directive|define
name|sk_IPAddressOrRange_sort
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_sort(IPAddressOrRange, (st))
define|#
directive|define
name|sk_IPAddressOrRange_is_sorted
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_is_sorted(IPAddressOrRange, (st))
define|#
directive|define
name|sk_KRB5_APREQBODY_new
parameter_list|(
name|cmp
parameter_list|)
value|SKM_sk_new(KRB5_APREQBODY, (cmp))
define|#
directive|define
name|sk_KRB5_APREQBODY_new_null
parameter_list|()
value|SKM_sk_new_null(KRB5_APREQBODY)
define|#
directive|define
name|sk_KRB5_APREQBODY_free
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_free(KRB5_APREQBODY, (st))
define|#
directive|define
name|sk_KRB5_APREQBODY_num
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_num(KRB5_APREQBODY, (st))
define|#
directive|define
name|sk_KRB5_APREQBODY_value
parameter_list|(
name|st
parameter_list|,
name|i
parameter_list|)
value|SKM_sk_value(KRB5_APREQBODY, (st), (i))
define|#
directive|define
name|sk_KRB5_APREQBODY_set
parameter_list|(
name|st
parameter_list|,
name|i
parameter_list|,
name|val
parameter_list|)
value|SKM_sk_set(KRB5_APREQBODY, (st), (i), (val))
define|#
directive|define
name|sk_KRB5_APREQBODY_zero
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_zero(KRB5_APREQBODY, (st))
define|#
directive|define
name|sk_KRB5_APREQBODY_push
parameter_list|(
name|st
parameter_list|,
name|val
parameter_list|)
value|SKM_sk_push(KRB5_APREQBODY, (st), (val))
define|#
directive|define
name|sk_KRB5_APREQBODY_unshift
parameter_list|(
name|st
parameter_list|,
name|val
parameter_list|)
value|SKM_sk_unshift(KRB5_APREQBODY, (st), (val))
define|#
directive|define
name|sk_KRB5_APREQBODY_find
parameter_list|(
name|st
parameter_list|,
name|val
parameter_list|)
value|SKM_sk_find(KRB5_APREQBODY, (st), (val))
define|#
directive|define
name|sk_KRB5_APREQBODY_find_ex
parameter_list|(
name|st
parameter_list|,
name|val
parameter_list|)
value|SKM_sk_find_ex(KRB5_APREQBODY, (st), (val))
define|#
directive|define
name|sk_KRB5_APREQBODY_delete
parameter_list|(
name|st
parameter_list|,
name|i
parameter_list|)
value|SKM_sk_delete(KRB5_APREQBODY, (st), (i))
define|#
directive|define
name|sk_KRB5_APREQBODY_delete_ptr
parameter_list|(
name|st
parameter_list|,
name|ptr
parameter_list|)
value|SKM_sk_delete_ptr(KRB5_APREQBODY, (st), (ptr))
define|#
directive|define
name|sk_KRB5_APREQBODY_insert
parameter_list|(
name|st
parameter_list|,
name|val
parameter_list|,
name|i
parameter_list|)
value|SKM_sk_insert(KRB5_APREQBODY, (st), (val), (i))
define|#
directive|define
name|sk_KRB5_APREQBODY_set_cmp_func
parameter_list|(
name|st
parameter_list|,
name|cmp
parameter_list|)
value|SKM_sk_set_cmp_func(KRB5_APREQBODY, (st), (cmp))
define|#
directive|define
name|sk_KRB5_APREQBODY_dup
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_dup(KRB5_APREQBODY, st)
define|#
directive|define
name|sk_KRB5_APREQBODY_pop_free
parameter_list|(
name|st
parameter_list|,
name|free_func
parameter_list|)
value|SKM_sk_pop_free(KRB5_APREQBODY, (st), (free_func))
define|#
directive|define
name|sk_KRB5_APREQBODY_shift
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_shift(KRB5_APREQBODY, (st))
define|#
directive|define
name|sk_KRB5_APREQBODY_pop
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_pop(KRB5_APREQBODY, (st))
define|#
directive|define
name|sk_KRB5_APREQBODY_sort
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_sort(KRB5_APREQBODY, (st))
define|#
directive|define
name|sk_KRB5_APREQBODY_is_sorted
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_is_sorted(KRB5_APREQBODY, (st))
define|#
directive|define
name|sk_KRB5_AUTHDATA_new
parameter_list|(
name|cmp
parameter_list|)
value|SKM_sk_new(KRB5_AUTHDATA, (cmp))
define|#
directive|define
name|sk_KRB5_AUTHDATA_new_null
parameter_list|()
value|SKM_sk_new_null(KRB5_AUTHDATA)
define|#
directive|define
name|sk_KRB5_AUTHDATA_free
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_free(KRB5_AUTHDATA, (st))
define|#
directive|define
name|sk_KRB5_AUTHDATA_num
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_num(KRB5_AUTHDATA, (st))
define|#
directive|define
name|sk_KRB5_AUTHDATA_value
parameter_list|(
name|st
parameter_list|,
name|i
parameter_list|)
value|SKM_sk_value(KRB5_AUTHDATA, (st), (i))
define|#
directive|define
name|sk_KRB5_AUTHDATA_set
parameter_list|(
name|st
parameter_list|,
name|i
parameter_list|,
name|val
parameter_list|)
value|SKM_sk_set(KRB5_AUTHDATA, (st), (i), (val))
define|#
directive|define
name|sk_KRB5_AUTHDATA_zero
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_zero(KRB5_AUTHDATA, (st))
define|#
directive|define
name|sk_KRB5_AUTHDATA_push
parameter_list|(
name|st
parameter_list|,
name|val
parameter_list|)
value|SKM_sk_push(KRB5_AUTHDATA, (st), (val))
define|#
directive|define
name|sk_KRB5_AUTHDATA_unshift
parameter_list|(
name|st
parameter_list|,
name|val
parameter_list|)
value|SKM_sk_unshift(KRB5_AUTHDATA, (st), (val))
define|#
directive|define
name|sk_KRB5_AUTHDATA_find
parameter_list|(
name|st
parameter_list|,
name|val
parameter_list|)
value|SKM_sk_find(KRB5_AUTHDATA, (st), (val))
define|#
directive|define
name|sk_KRB5_AUTHDATA_find_ex
parameter_list|(
name|st
parameter_list|,
name|val
parameter_list|)
value|SKM_sk_find_ex(KRB5_AUTHDATA, (st), (val))
define|#
directive|define
name|sk_KRB5_AUTHDATA_delete
parameter_list|(
name|st
parameter_list|,
name|i
parameter_list|)
value|SKM_sk_delete(KRB5_AUTHDATA, (st), (i))
define|#
directive|define
name|sk_KRB5_AUTHDATA_delete_ptr
parameter_list|(
name|st
parameter_list|,
name|ptr
parameter_list|)
value|SKM_sk_delete_ptr(KRB5_AUTHDATA, (st), (ptr))
define|#
directive|define
name|sk_KRB5_AUTHDATA_insert
parameter_list|(
name|st
parameter_list|,
name|val
parameter_list|,
name|i
parameter_list|)
value|SKM_sk_insert(KRB5_AUTHDATA, (st), (val), (i))
define|#
directive|define
name|sk_KRB5_AUTHDATA_set_cmp_func
parameter_list|(
name|st
parameter_list|,
name|cmp
parameter_list|)
value|SKM_sk_set_cmp_func(KRB5_AUTHDATA, (st), (cmp))
define|#
directive|define
name|sk_KRB5_AUTHDATA_dup
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_dup(KRB5_AUTHDATA, st)
define|#
directive|define
name|sk_KRB5_AUTHDATA_pop_free
parameter_list|(
name|st
parameter_list|,
name|free_func
parameter_list|)
value|SKM_sk_pop_free(KRB5_AUTHDATA, (st), (free_func))
define|#
directive|define
name|sk_KRB5_AUTHDATA_shift
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_shift(KRB5_AUTHDATA, (st))
define|#
directive|define
name|sk_KRB5_AUTHDATA_pop
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_pop(KRB5_AUTHDATA, (st))
define|#
directive|define
name|sk_KRB5_AUTHDATA_sort
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_sort(KRB5_AUTHDATA, (st))
define|#
directive|define
name|sk_KRB5_AUTHDATA_is_sorted
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_is_sorted(KRB5_AUTHDATA, (st))
define|#
directive|define
name|sk_KRB5_AUTHENTBODY_new
parameter_list|(
name|cmp
parameter_list|)
value|SKM_sk_new(KRB5_AUTHENTBODY, (cmp))
define|#
directive|define
name|sk_KRB5_AUTHENTBODY_new_null
parameter_list|()
value|SKM_sk_new_null(KRB5_AUTHENTBODY)
define|#
directive|define
name|sk_KRB5_AUTHENTBODY_free
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_free(KRB5_AUTHENTBODY, (st))
define|#
directive|define
name|sk_KRB5_AUTHENTBODY_num
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_num(KRB5_AUTHENTBODY, (st))
define|#
directive|define
name|sk_KRB5_AUTHENTBODY_value
parameter_list|(
name|st
parameter_list|,
name|i
parameter_list|)
value|SKM_sk_value(KRB5_AUTHENTBODY, (st), (i))
define|#
directive|define
name|sk_KRB5_AUTHENTBODY_set
parameter_list|(
name|st
parameter_list|,
name|i
parameter_list|,
name|val
parameter_list|)
value|SKM_sk_set(KRB5_AUTHENTBODY, (st), (i), (val))
define|#
directive|define
name|sk_KRB5_AUTHENTBODY_zero
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_zero(KRB5_AUTHENTBODY, (st))
define|#
directive|define
name|sk_KRB5_AUTHENTBODY_push
parameter_list|(
name|st
parameter_list|,
name|val
parameter_list|)
value|SKM_sk_push(KRB5_AUTHENTBODY, (st), (val))
define|#
directive|define
name|sk_KRB5_AUTHENTBODY_unshift
parameter_list|(
name|st
parameter_list|,
name|val
parameter_list|)
value|SKM_sk_unshift(KRB5_AUTHENTBODY, (st), (val))
define|#
directive|define
name|sk_KRB5_AUTHENTBODY_find
parameter_list|(
name|st
parameter_list|,
name|val
parameter_list|)
value|SKM_sk_find(KRB5_AUTHENTBODY, (st), (val))
define|#
directive|define
name|sk_KRB5_AUTHENTBODY_find_ex
parameter_list|(
name|st
parameter_list|,
name|val
parameter_list|)
value|SKM_sk_find_ex(KRB5_AUTHENTBODY, (st), (val))
define|#
directive|define
name|sk_KRB5_AUTHENTBODY_delete
parameter_list|(
name|st
parameter_list|,
name|i
parameter_list|)
value|SKM_sk_delete(KRB5_AUTHENTBODY, (st), (i))
define|#
directive|define
name|sk_KRB5_AUTHENTBODY_delete_ptr
parameter_list|(
name|st
parameter_list|,
name|ptr
parameter_list|)
value|SKM_sk_delete_ptr(KRB5_AUTHENTBODY, (st), (ptr))
define|#
directive|define
name|sk_KRB5_AUTHENTBODY_insert
parameter_list|(
name|st
parameter_list|,
name|val
parameter_list|,
name|i
parameter_list|)
value|SKM_sk_insert(KRB5_AUTHENTBODY, (st), (val), (i))
define|#
directive|define
name|sk_KRB5_AUTHENTBODY_set_cmp_func
parameter_list|(
name|st
parameter_list|,
name|cmp
parameter_list|)
value|SKM_sk_set_cmp_func(KRB5_AUTHENTBODY, (st), (cmp))
define|#
directive|define
name|sk_KRB5_AUTHENTBODY_dup
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_dup(KRB5_AUTHENTBODY, st)
define|#
directive|define
name|sk_KRB5_AUTHENTBODY_pop_free
parameter_list|(
name|st
parameter_list|,
name|free_func
parameter_list|)
value|SKM_sk_pop_free(KRB5_AUTHENTBODY, (st), (free_func))
define|#
directive|define
name|sk_KRB5_AUTHENTBODY_shift
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_shift(KRB5_AUTHENTBODY, (st))
define|#
directive|define
name|sk_KRB5_AUTHENTBODY_pop
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_pop(KRB5_AUTHENTBODY, (st))
define|#
directive|define
name|sk_KRB5_AUTHENTBODY_sort
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_sort(KRB5_AUTHENTBODY, (st))
define|#
directive|define
name|sk_KRB5_AUTHENTBODY_is_sorted
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_is_sorted(KRB5_AUTHENTBODY, (st))
define|#
directive|define
name|sk_KRB5_CHECKSUM_new
parameter_list|(
name|cmp
parameter_list|)
value|SKM_sk_new(KRB5_CHECKSUM, (cmp))
define|#
directive|define
name|sk_KRB5_CHECKSUM_new_null
parameter_list|()
value|SKM_sk_new_null(KRB5_CHECKSUM)
define|#
directive|define
name|sk_KRB5_CHECKSUM_free
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_free(KRB5_CHECKSUM, (st))
define|#
directive|define
name|sk_KRB5_CHECKSUM_num
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_num(KRB5_CHECKSUM, (st))
define|#
directive|define
name|sk_KRB5_CHECKSUM_value
parameter_list|(
name|st
parameter_list|,
name|i
parameter_list|)
value|SKM_sk_value(KRB5_CHECKSUM, (st), (i))
define|#
directive|define
name|sk_KRB5_CHECKSUM_set
parameter_list|(
name|st
parameter_list|,
name|i
parameter_list|,
name|val
parameter_list|)
value|SKM_sk_set(KRB5_CHECKSUM, (st), (i), (val))
define|#
directive|define
name|sk_KRB5_CHECKSUM_zero
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_zero(KRB5_CHECKSUM, (st))
define|#
directive|define
name|sk_KRB5_CHECKSUM_push
parameter_list|(
name|st
parameter_list|,
name|val
parameter_list|)
value|SKM_sk_push(KRB5_CHECKSUM, (st), (val))
define|#
directive|define
name|sk_KRB5_CHECKSUM_unshift
parameter_list|(
name|st
parameter_list|,
name|val
parameter_list|)
value|SKM_sk_unshift(KRB5_CHECKSUM, (st), (val))
define|#
directive|define
name|sk_KRB5_CHECKSUM_find
parameter_list|(
name|st
parameter_list|,
name|val
parameter_list|)
value|SKM_sk_find(KRB5_CHECKSUM, (st), (val))
define|#
directive|define
name|sk_KRB5_CHECKSUM_find_ex
parameter_list|(
name|st
parameter_list|,
name|val
parameter_list|)
value|SKM_sk_find_ex(KRB5_CHECKSUM, (st), (val))
define|#
directive|define
name|sk_KRB5_CHECKSUM_delete
parameter_list|(
name|st
parameter_list|,
name|i
parameter_list|)
value|SKM_sk_delete(KRB5_CHECKSUM, (st), (i))
define|#
directive|define
name|sk_KRB5_CHECKSUM_delete_ptr
parameter_list|(
name|st
parameter_list|,
name|ptr
parameter_list|)
value|SKM_sk_delete_ptr(KRB5_CHECKSUM, (st), (ptr))
define|#
directive|define
name|sk_KRB5_CHECKSUM_insert
parameter_list|(
name|st
parameter_list|,
name|val
parameter_list|,
name|i
parameter_list|)
value|SKM_sk_insert(KRB5_CHECKSUM, (st), (val), (i))
define|#
directive|define
name|sk_KRB5_CHECKSUM_set_cmp_func
parameter_list|(
name|st
parameter_list|,
name|cmp
parameter_list|)
value|SKM_sk_set_cmp_func(KRB5_CHECKSUM, (st), (cmp))
define|#
directive|define
name|sk_KRB5_CHECKSUM_dup
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_dup(KRB5_CHECKSUM, st)
define|#
directive|define
name|sk_KRB5_CHECKSUM_pop_free
parameter_list|(
name|st
parameter_list|,
name|free_func
parameter_list|)
value|SKM_sk_pop_free(KRB5_CHECKSUM, (st), (free_func))
define|#
directive|define
name|sk_KRB5_CHECKSUM_shift
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_shift(KRB5_CHECKSUM, (st))
define|#
directive|define
name|sk_KRB5_CHECKSUM_pop
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_pop(KRB5_CHECKSUM, (st))
define|#
directive|define
name|sk_KRB5_CHECKSUM_sort
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_sort(KRB5_CHECKSUM, (st))
define|#
directive|define
name|sk_KRB5_CHECKSUM_is_sorted
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_is_sorted(KRB5_CHECKSUM, (st))
define|#
directive|define
name|sk_KRB5_ENCDATA_new
parameter_list|(
name|cmp
parameter_list|)
value|SKM_sk_new(KRB5_ENCDATA, (cmp))
define|#
directive|define
name|sk_KRB5_ENCDATA_new_null
parameter_list|()
value|SKM_sk_new_null(KRB5_ENCDATA)
define|#
directive|define
name|sk_KRB5_ENCDATA_free
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_free(KRB5_ENCDATA, (st))
define|#
directive|define
name|sk_KRB5_ENCDATA_num
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_num(KRB5_ENCDATA, (st))
define|#
directive|define
name|sk_KRB5_ENCDATA_value
parameter_list|(
name|st
parameter_list|,
name|i
parameter_list|)
value|SKM_sk_value(KRB5_ENCDATA, (st), (i))
define|#
directive|define
name|sk_KRB5_ENCDATA_set
parameter_list|(
name|st
parameter_list|,
name|i
parameter_list|,
name|val
parameter_list|)
value|SKM_sk_set(KRB5_ENCDATA, (st), (i), (val))
define|#
directive|define
name|sk_KRB5_ENCDATA_zero
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_zero(KRB5_ENCDATA, (st))
define|#
directive|define
name|sk_KRB5_ENCDATA_push
parameter_list|(
name|st
parameter_list|,
name|val
parameter_list|)
value|SKM_sk_push(KRB5_ENCDATA, (st), (val))
define|#
directive|define
name|sk_KRB5_ENCDATA_unshift
parameter_list|(
name|st
parameter_list|,
name|val
parameter_list|)
value|SKM_sk_unshift(KRB5_ENCDATA, (st), (val))
define|#
directive|define
name|sk_KRB5_ENCDATA_find
parameter_list|(
name|st
parameter_list|,
name|val
parameter_list|)
value|SKM_sk_find(KRB5_ENCDATA, (st), (val))
define|#
directive|define
name|sk_KRB5_ENCDATA_find_ex
parameter_list|(
name|st
parameter_list|,
name|val
parameter_list|)
value|SKM_sk_find_ex(KRB5_ENCDATA, (st), (val))
define|#
directive|define
name|sk_KRB5_ENCDATA_delete
parameter_list|(
name|st
parameter_list|,
name|i
parameter_list|)
value|SKM_sk_delete(KRB5_ENCDATA, (st), (i))
define|#
directive|define
name|sk_KRB5_ENCDATA_delete_ptr
parameter_list|(
name|st
parameter_list|,
name|ptr
parameter_list|)
value|SKM_sk_delete_ptr(KRB5_ENCDATA, (st), (ptr))
define|#
directive|define
name|sk_KRB5_ENCDATA_insert
parameter_list|(
name|st
parameter_list|,
name|val
parameter_list|,
name|i
parameter_list|)
value|SKM_sk_insert(KRB5_ENCDATA, (st), (val), (i))
define|#
directive|define
name|sk_KRB5_ENCDATA_set_cmp_func
parameter_list|(
name|st
parameter_list|,
name|cmp
parameter_list|)
value|SKM_sk_set_cmp_func(KRB5_ENCDATA, (st), (cmp))
define|#
directive|define
name|sk_KRB5_ENCDATA_dup
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_dup(KRB5_ENCDATA, st)
define|#
directive|define
name|sk_KRB5_ENCDATA_pop_free
parameter_list|(
name|st
parameter_list|,
name|free_func
parameter_list|)
value|SKM_sk_pop_free(KRB5_ENCDATA, (st), (free_func))
define|#
directive|define
name|sk_KRB5_ENCDATA_shift
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_shift(KRB5_ENCDATA, (st))
define|#
directive|define
name|sk_KRB5_ENCDATA_pop
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_pop(KRB5_ENCDATA, (st))
define|#
directive|define
name|sk_KRB5_ENCDATA_sort
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_sort(KRB5_ENCDATA, (st))
define|#
directive|define
name|sk_KRB5_ENCDATA_is_sorted
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_is_sorted(KRB5_ENCDATA, (st))
define|#
directive|define
name|sk_KRB5_ENCKEY_new
parameter_list|(
name|cmp
parameter_list|)
value|SKM_sk_new(KRB5_ENCKEY, (cmp))
define|#
directive|define
name|sk_KRB5_ENCKEY_new_null
parameter_list|()
value|SKM_sk_new_null(KRB5_ENCKEY)
define|#
directive|define
name|sk_KRB5_ENCKEY_free
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_free(KRB5_ENCKEY, (st))
define|#
directive|define
name|sk_KRB5_ENCKEY_num
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_num(KRB5_ENCKEY, (st))
define|#
directive|define
name|sk_KRB5_ENCKEY_value
parameter_list|(
name|st
parameter_list|,
name|i
parameter_list|)
value|SKM_sk_value(KRB5_ENCKEY, (st), (i))
define|#
directive|define
name|sk_KRB5_ENCKEY_set
parameter_list|(
name|st
parameter_list|,
name|i
parameter_list|,
name|val
parameter_list|)
value|SKM_sk_set(KRB5_ENCKEY, (st), (i), (val))
define|#
directive|define
name|sk_KRB5_ENCKEY_zero
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_zero(KRB5_ENCKEY, (st))
define|#
directive|define
name|sk_KRB5_ENCKEY_push
parameter_list|(
name|st
parameter_list|,
name|val
parameter_list|)
value|SKM_sk_push(KRB5_ENCKEY, (st), (val))
define|#
directive|define
name|sk_KRB5_ENCKEY_unshift
parameter_list|(
name|st
parameter_list|,
name|val
parameter_list|)
value|SKM_sk_unshift(KRB5_ENCKEY, (st), (val))
define|#
directive|define
name|sk_KRB5_ENCKEY_find
parameter_list|(
name|st
parameter_list|,
name|val
parameter_list|)
value|SKM_sk_find(KRB5_ENCKEY, (st), (val))
define|#
directive|define
name|sk_KRB5_ENCKEY_find_ex
parameter_list|(
name|st
parameter_list|,
name|val
parameter_list|)
value|SKM_sk_find_ex(KRB5_ENCKEY, (st), (val))
define|#
directive|define
name|sk_KRB5_ENCKEY_delete
parameter_list|(
name|st
parameter_list|,
name|i
parameter_list|)
value|SKM_sk_delete(KRB5_ENCKEY, (st), (i))
define|#
directive|define
name|sk_KRB5_ENCKEY_delete_ptr
parameter_list|(
name|st
parameter_list|,
name|ptr
parameter_list|)
value|SKM_sk_delete_ptr(KRB5_ENCKEY, (st), (ptr))
define|#
directive|define
name|sk_KRB5_ENCKEY_insert
parameter_list|(
name|st
parameter_list|,
name|val
parameter_list|,
name|i
parameter_list|)
value|SKM_sk_insert(KRB5_ENCKEY, (st), (val), (i))
define|#
directive|define
name|sk_KRB5_ENCKEY_set_cmp_func
parameter_list|(
name|st
parameter_list|,
name|cmp
parameter_list|)
value|SKM_sk_set_cmp_func(KRB5_ENCKEY, (st), (cmp))
define|#
directive|define
name|sk_KRB5_ENCKEY_dup
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_dup(KRB5_ENCKEY, st)
define|#
directive|define
name|sk_KRB5_ENCKEY_pop_free
parameter_list|(
name|st
parameter_list|,
name|free_func
parameter_list|)
value|SKM_sk_pop_free(KRB5_ENCKEY, (st), (free_func))
define|#
directive|define
name|sk_KRB5_ENCKEY_shift
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_shift(KRB5_ENCKEY, (st))
define|#
directive|define
name|sk_KRB5_ENCKEY_pop
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_pop(KRB5_ENCKEY, (st))
define|#
directive|define
name|sk_KRB5_ENCKEY_sort
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_sort(KRB5_ENCKEY, (st))
define|#
directive|define
name|sk_KRB5_ENCKEY_is_sorted
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_is_sorted(KRB5_ENCKEY, (st))
define|#
directive|define
name|sk_KRB5_PRINCNAME_new
parameter_list|(
name|cmp
parameter_list|)
value|SKM_sk_new(KRB5_PRINCNAME, (cmp))
define|#
directive|define
name|sk_KRB5_PRINCNAME_new_null
parameter_list|()
value|SKM_sk_new_null(KRB5_PRINCNAME)
define|#
directive|define
name|sk_KRB5_PRINCNAME_free
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_free(KRB5_PRINCNAME, (st))
define|#
directive|define
name|sk_KRB5_PRINCNAME_num
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_num(KRB5_PRINCNAME, (st))
define|#
directive|define
name|sk_KRB5_PRINCNAME_value
parameter_list|(
name|st
parameter_list|,
name|i
parameter_list|)
value|SKM_sk_value(KRB5_PRINCNAME, (st), (i))
define|#
directive|define
name|sk_KRB5_PRINCNAME_set
parameter_list|(
name|st
parameter_list|,
name|i
parameter_list|,
name|val
parameter_list|)
value|SKM_sk_set(KRB5_PRINCNAME, (st), (i), (val))
define|#
directive|define
name|sk_KRB5_PRINCNAME_zero
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_zero(KRB5_PRINCNAME, (st))
define|#
directive|define
name|sk_KRB5_PRINCNAME_push
parameter_list|(
name|st
parameter_list|,
name|val
parameter_list|)
value|SKM_sk_push(KRB5_PRINCNAME, (st), (val))
define|#
directive|define
name|sk_KRB5_PRINCNAME_unshift
parameter_list|(
name|st
parameter_list|,
name|val
parameter_list|)
value|SKM_sk_unshift(KRB5_PRINCNAME, (st), (val))
define|#
directive|define
name|sk_KRB5_PRINCNAME_find
parameter_list|(
name|st
parameter_list|,
name|val
parameter_list|)
value|SKM_sk_find(KRB5_PRINCNAME, (st), (val))
define|#
directive|define
name|sk_KRB5_PRINCNAME_find_ex
parameter_list|(
name|st
parameter_list|,
name|val
parameter_list|)
value|SKM_sk_find_ex(KRB5_PRINCNAME, (st), (val))
define|#
directive|define
name|sk_KRB5_PRINCNAME_delete
parameter_list|(
name|st
parameter_list|,
name|i
parameter_list|)
value|SKM_sk_delete(KRB5_PRINCNAME, (st), (i))
define|#
directive|define
name|sk_KRB5_PRINCNAME_delete_ptr
parameter_list|(
name|st
parameter_list|,
name|ptr
parameter_list|)
value|SKM_sk_delete_ptr(KRB5_PRINCNAME, (st), (ptr))
define|#
directive|define
name|sk_KRB5_PRINCNAME_insert
parameter_list|(
name|st
parameter_list|,
name|val
parameter_list|,
name|i
parameter_list|)
value|SKM_sk_insert(KRB5_PRINCNAME, (st), (val), (i))
define|#
directive|define
name|sk_KRB5_PRINCNAME_set_cmp_func
parameter_list|(
name|st
parameter_list|,
name|cmp
parameter_list|)
value|SKM_sk_set_cmp_func(KRB5_PRINCNAME, (st), (cmp))
define|#
directive|define
name|sk_KRB5_PRINCNAME_dup
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_dup(KRB5_PRINCNAME, st)
define|#
directive|define
name|sk_KRB5_PRINCNAME_pop_free
parameter_list|(
name|st
parameter_list|,
name|free_func
parameter_list|)
value|SKM_sk_pop_free(KRB5_PRINCNAME, (st), (free_func))
define|#
directive|define
name|sk_KRB5_PRINCNAME_shift
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_shift(KRB5_PRINCNAME, (st))
define|#
directive|define
name|sk_KRB5_PRINCNAME_pop
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_pop(KRB5_PRINCNAME, (st))
define|#
directive|define
name|sk_KRB5_PRINCNAME_sort
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_sort(KRB5_PRINCNAME, (st))
define|#
directive|define
name|sk_KRB5_PRINCNAME_is_sorted
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_is_sorted(KRB5_PRINCNAME, (st))
define|#
directive|define
name|sk_KRB5_TKTBODY_new
parameter_list|(
name|cmp
parameter_list|)
value|SKM_sk_new(KRB5_TKTBODY, (cmp))
define|#
directive|define
name|sk_KRB5_TKTBODY_new_null
parameter_list|()
value|SKM_sk_new_null(KRB5_TKTBODY)
define|#
directive|define
name|sk_KRB5_TKTBODY_free
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_free(KRB5_TKTBODY, (st))
define|#
directive|define
name|sk_KRB5_TKTBODY_num
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_num(KRB5_TKTBODY, (st))
define|#
directive|define
name|sk_KRB5_TKTBODY_value
parameter_list|(
name|st
parameter_list|,
name|i
parameter_list|)
value|SKM_sk_value(KRB5_TKTBODY, (st), (i))
define|#
directive|define
name|sk_KRB5_TKTBODY_set
parameter_list|(
name|st
parameter_list|,
name|i
parameter_list|,
name|val
parameter_list|)
value|SKM_sk_set(KRB5_TKTBODY, (st), (i), (val))
define|#
directive|define
name|sk_KRB5_TKTBODY_zero
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_zero(KRB5_TKTBODY, (st))
define|#
directive|define
name|sk_KRB5_TKTBODY_push
parameter_list|(
name|st
parameter_list|,
name|val
parameter_list|)
value|SKM_sk_push(KRB5_TKTBODY, (st), (val))
define|#
directive|define
name|sk_KRB5_TKTBODY_unshift
parameter_list|(
name|st
parameter_list|,
name|val
parameter_list|)
value|SKM_sk_unshift(KRB5_TKTBODY, (st), (val))
define|#
directive|define
name|sk_KRB5_TKTBODY_find
parameter_list|(
name|st
parameter_list|,
name|val
parameter_list|)
value|SKM_sk_find(KRB5_TKTBODY, (st), (val))
define|#
directive|define
name|sk_KRB5_TKTBODY_find_ex
parameter_list|(
name|st
parameter_list|,
name|val
parameter_list|)
value|SKM_sk_find_ex(KRB5_TKTBODY, (st), (val))
define|#
directive|define
name|sk_KRB5_TKTBODY_delete
parameter_list|(
name|st
parameter_list|,
name|i
parameter_list|)
value|SKM_sk_delete(KRB5_TKTBODY, (st), (i))
define|#
directive|define
name|sk_KRB5_TKTBODY_delete_ptr
parameter_list|(
name|st
parameter_list|,
name|ptr
parameter_list|)
value|SKM_sk_delete_ptr(KRB5_TKTBODY, (st), (ptr))
define|#
directive|define
name|sk_KRB5_TKTBODY_insert
parameter_list|(
name|st
parameter_list|,
name|val
parameter_list|,
name|i
parameter_list|)
value|SKM_sk_insert(KRB5_TKTBODY, (st), (val), (i))
define|#
directive|define
name|sk_KRB5_TKTBODY_set_cmp_func
parameter_list|(
name|st
parameter_list|,
name|cmp
parameter_list|)
value|SKM_sk_set_cmp_func(KRB5_TKTBODY, (st), (cmp))
define|#
directive|define
name|sk_KRB5_TKTBODY_dup
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_dup(KRB5_TKTBODY, st)
define|#
directive|define
name|sk_KRB5_TKTBODY_pop_free
parameter_list|(
name|st
parameter_list|,
name|free_func
parameter_list|)
value|SKM_sk_pop_free(KRB5_TKTBODY, (st), (free_func))
define|#
directive|define
name|sk_KRB5_TKTBODY_shift
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_shift(KRB5_TKTBODY, (st))
define|#
directive|define
name|sk_KRB5_TKTBODY_pop
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_pop(KRB5_TKTBODY, (st))
define|#
directive|define
name|sk_KRB5_TKTBODY_sort
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_sort(KRB5_TKTBODY, (st))
define|#
directive|define
name|sk_KRB5_TKTBODY_is_sorted
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_is_sorted(KRB5_TKTBODY, (st))
define|#
directive|define
name|sk_MEM_OBJECT_DATA_new
parameter_list|(
name|cmp
parameter_list|)
value|SKM_sk_new(MEM_OBJECT_DATA, (cmp))
define|#
directive|define
name|sk_MEM_OBJECT_DATA_new_null
parameter_list|()
value|SKM_sk_new_null(MEM_OBJECT_DATA)
define|#
directive|define
name|sk_MEM_OBJECT_DATA_free
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_free(MEM_OBJECT_DATA, (st))
define|#
directive|define
name|sk_MEM_OBJECT_DATA_num
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_num(MEM_OBJECT_DATA, (st))
define|#
directive|define
name|sk_MEM_OBJECT_DATA_value
parameter_list|(
name|st
parameter_list|,
name|i
parameter_list|)
value|SKM_sk_value(MEM_OBJECT_DATA, (st), (i))
define|#
directive|define
name|sk_MEM_OBJECT_DATA_set
parameter_list|(
name|st
parameter_list|,
name|i
parameter_list|,
name|val
parameter_list|)
value|SKM_sk_set(MEM_OBJECT_DATA, (st), (i), (val))
define|#
directive|define
name|sk_MEM_OBJECT_DATA_zero
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_zero(MEM_OBJECT_DATA, (st))
define|#
directive|define
name|sk_MEM_OBJECT_DATA_push
parameter_list|(
name|st
parameter_list|,
name|val
parameter_list|)
value|SKM_sk_push(MEM_OBJECT_DATA, (st), (val))
define|#
directive|define
name|sk_MEM_OBJECT_DATA_unshift
parameter_list|(
name|st
parameter_list|,
name|val
parameter_list|)
value|SKM_sk_unshift(MEM_OBJECT_DATA, (st), (val))
define|#
directive|define
name|sk_MEM_OBJECT_DATA_find
parameter_list|(
name|st
parameter_list|,
name|val
parameter_list|)
value|SKM_sk_find(MEM_OBJECT_DATA, (st), (val))
define|#
directive|define
name|sk_MEM_OBJECT_DATA_find_ex
parameter_list|(
name|st
parameter_list|,
name|val
parameter_list|)
value|SKM_sk_find_ex(MEM_OBJECT_DATA, (st), (val))
define|#
directive|define
name|sk_MEM_OBJECT_DATA_delete
parameter_list|(
name|st
parameter_list|,
name|i
parameter_list|)
value|SKM_sk_delete(MEM_OBJECT_DATA, (st), (i))
define|#
directive|define
name|sk_MEM_OBJECT_DATA_delete_ptr
parameter_list|(
name|st
parameter_list|,
name|ptr
parameter_list|)
value|SKM_sk_delete_ptr(MEM_OBJECT_DATA, (st), (ptr))
define|#
directive|define
name|sk_MEM_OBJECT_DATA_insert
parameter_list|(
name|st
parameter_list|,
name|val
parameter_list|,
name|i
parameter_list|)
value|SKM_sk_insert(MEM_OBJECT_DATA, (st), (val), (i))
define|#
directive|define
name|sk_MEM_OBJECT_DATA_set_cmp_func
parameter_list|(
name|st
parameter_list|,
name|cmp
parameter_list|)
value|SKM_sk_set_cmp_func(MEM_OBJECT_DATA, (st), (cmp))
define|#
directive|define
name|sk_MEM_OBJECT_DATA_dup
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_dup(MEM_OBJECT_DATA, st)
define|#
directive|define
name|sk_MEM_OBJECT_DATA_pop_free
parameter_list|(
name|st
parameter_list|,
name|free_func
parameter_list|)
value|SKM_sk_pop_free(MEM_OBJECT_DATA, (st), (free_func))
define|#
directive|define
name|sk_MEM_OBJECT_DATA_shift
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_shift(MEM_OBJECT_DATA, (st))
define|#
directive|define
name|sk_MEM_OBJECT_DATA_pop
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_pop(MEM_OBJECT_DATA, (st))
define|#
directive|define
name|sk_MEM_OBJECT_DATA_sort
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_sort(MEM_OBJECT_DATA, (st))
define|#
directive|define
name|sk_MEM_OBJECT_DATA_is_sorted
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_is_sorted(MEM_OBJECT_DATA, (st))
define|#
directive|define
name|sk_MIME_HEADER_new
parameter_list|(
name|cmp
parameter_list|)
value|SKM_sk_new(MIME_HEADER, (cmp))
define|#
directive|define
name|sk_MIME_HEADER_new_null
parameter_list|()
value|SKM_sk_new_null(MIME_HEADER)
define|#
directive|define
name|sk_MIME_HEADER_free
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_free(MIME_HEADER, (st))
define|#
directive|define
name|sk_MIME_HEADER_num
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_num(MIME_HEADER, (st))
define|#
directive|define
name|sk_MIME_HEADER_value
parameter_list|(
name|st
parameter_list|,
name|i
parameter_list|)
value|SKM_sk_value(MIME_HEADER, (st), (i))
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
define|#
directive|define
name|sk_MIME_HEADER_zero
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_zero(MIME_HEADER, (st))
define|#
directive|define
name|sk_MIME_HEADER_push
parameter_list|(
name|st
parameter_list|,
name|val
parameter_list|)
value|SKM_sk_push(MIME_HEADER, (st), (val))
define|#
directive|define
name|sk_MIME_HEADER_unshift
parameter_list|(
name|st
parameter_list|,
name|val
parameter_list|)
value|SKM_sk_unshift(MIME_HEADER, (st), (val))
define|#
directive|define
name|sk_MIME_HEADER_find
parameter_list|(
name|st
parameter_list|,
name|val
parameter_list|)
value|SKM_sk_find(MIME_HEADER, (st), (val))
define|#
directive|define
name|sk_MIME_HEADER_find_ex
parameter_list|(
name|st
parameter_list|,
name|val
parameter_list|)
value|SKM_sk_find_ex(MIME_HEADER, (st), (val))
define|#
directive|define
name|sk_MIME_HEADER_delete
parameter_list|(
name|st
parameter_list|,
name|i
parameter_list|)
value|SKM_sk_delete(MIME_HEADER, (st), (i))
define|#
directive|define
name|sk_MIME_HEADER_delete_ptr
parameter_list|(
name|st
parameter_list|,
name|ptr
parameter_list|)
value|SKM_sk_delete_ptr(MIME_HEADER, (st), (ptr))
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
define|#
directive|define
name|sk_MIME_HEADER_set_cmp_func
parameter_list|(
name|st
parameter_list|,
name|cmp
parameter_list|)
value|SKM_sk_set_cmp_func(MIME_HEADER, (st), (cmp))
define|#
directive|define
name|sk_MIME_HEADER_dup
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_dup(MIME_HEADER, st)
define|#
directive|define
name|sk_MIME_HEADER_pop_free
parameter_list|(
name|st
parameter_list|,
name|free_func
parameter_list|)
value|SKM_sk_pop_free(MIME_HEADER, (st), (free_func))
define|#
directive|define
name|sk_MIME_HEADER_shift
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_shift(MIME_HEADER, (st))
define|#
directive|define
name|sk_MIME_HEADER_pop
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_pop(MIME_HEADER, (st))
define|#
directive|define
name|sk_MIME_HEADER_sort
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_sort(MIME_HEADER, (st))
define|#
directive|define
name|sk_MIME_HEADER_is_sorted
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_is_sorted(MIME_HEADER, (st))
define|#
directive|define
name|sk_MIME_PARAM_new
parameter_list|(
name|cmp
parameter_list|)
value|SKM_sk_new(MIME_PARAM, (cmp))
define|#
directive|define
name|sk_MIME_PARAM_new_null
parameter_list|()
value|SKM_sk_new_null(MIME_PARAM)
define|#
directive|define
name|sk_MIME_PARAM_free
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_free(MIME_PARAM, (st))
define|#
directive|define
name|sk_MIME_PARAM_num
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_num(MIME_PARAM, (st))
define|#
directive|define
name|sk_MIME_PARAM_value
parameter_list|(
name|st
parameter_list|,
name|i
parameter_list|)
value|SKM_sk_value(MIME_PARAM, (st), (i))
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
define|#
directive|define
name|sk_MIME_PARAM_zero
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_zero(MIME_PARAM, (st))
define|#
directive|define
name|sk_MIME_PARAM_push
parameter_list|(
name|st
parameter_list|,
name|val
parameter_list|)
value|SKM_sk_push(MIME_PARAM, (st), (val))
define|#
directive|define
name|sk_MIME_PARAM_unshift
parameter_list|(
name|st
parameter_list|,
name|val
parameter_list|)
value|SKM_sk_unshift(MIME_PARAM, (st), (val))
define|#
directive|define
name|sk_MIME_PARAM_find
parameter_list|(
name|st
parameter_list|,
name|val
parameter_list|)
value|SKM_sk_find(MIME_PARAM, (st), (val))
define|#
directive|define
name|sk_MIME_PARAM_find_ex
parameter_list|(
name|st
parameter_list|,
name|val
parameter_list|)
value|SKM_sk_find_ex(MIME_PARAM, (st), (val))
define|#
directive|define
name|sk_MIME_PARAM_delete
parameter_list|(
name|st
parameter_list|,
name|i
parameter_list|)
value|SKM_sk_delete(MIME_PARAM, (st), (i))
define|#
directive|define
name|sk_MIME_PARAM_delete_ptr
parameter_list|(
name|st
parameter_list|,
name|ptr
parameter_list|)
value|SKM_sk_delete_ptr(MIME_PARAM, (st), (ptr))
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
define|#
directive|define
name|sk_MIME_PARAM_set_cmp_func
parameter_list|(
name|st
parameter_list|,
name|cmp
parameter_list|)
value|SKM_sk_set_cmp_func(MIME_PARAM, (st), (cmp))
define|#
directive|define
name|sk_MIME_PARAM_dup
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_dup(MIME_PARAM, st)
define|#
directive|define
name|sk_MIME_PARAM_pop_free
parameter_list|(
name|st
parameter_list|,
name|free_func
parameter_list|)
value|SKM_sk_pop_free(MIME_PARAM, (st), (free_func))
define|#
directive|define
name|sk_MIME_PARAM_shift
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_shift(MIME_PARAM, (st))
define|#
directive|define
name|sk_MIME_PARAM_pop
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_pop(MIME_PARAM, (st))
define|#
directive|define
name|sk_MIME_PARAM_sort
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_sort(MIME_PARAM, (st))
define|#
directive|define
name|sk_MIME_PARAM_is_sorted
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_is_sorted(MIME_PARAM, (st))
define|#
directive|define
name|sk_NAME_FUNCS_new
parameter_list|(
name|cmp
parameter_list|)
value|SKM_sk_new(NAME_FUNCS, (cmp))
define|#
directive|define
name|sk_NAME_FUNCS_new_null
parameter_list|()
value|SKM_sk_new_null(NAME_FUNCS)
define|#
directive|define
name|sk_NAME_FUNCS_free
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_free(NAME_FUNCS, (st))
define|#
directive|define
name|sk_NAME_FUNCS_num
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_num(NAME_FUNCS, (st))
define|#
directive|define
name|sk_NAME_FUNCS_value
parameter_list|(
name|st
parameter_list|,
name|i
parameter_list|)
value|SKM_sk_value(NAME_FUNCS, (st), (i))
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
define|#
directive|define
name|sk_NAME_FUNCS_zero
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_zero(NAME_FUNCS, (st))
define|#
directive|define
name|sk_NAME_FUNCS_push
parameter_list|(
name|st
parameter_list|,
name|val
parameter_list|)
value|SKM_sk_push(NAME_FUNCS, (st), (val))
define|#
directive|define
name|sk_NAME_FUNCS_unshift
parameter_list|(
name|st
parameter_list|,
name|val
parameter_list|)
value|SKM_sk_unshift(NAME_FUNCS, (st), (val))
define|#
directive|define
name|sk_NAME_FUNCS_find
parameter_list|(
name|st
parameter_list|,
name|val
parameter_list|)
value|SKM_sk_find(NAME_FUNCS, (st), (val))
define|#
directive|define
name|sk_NAME_FUNCS_find_ex
parameter_list|(
name|st
parameter_list|,
name|val
parameter_list|)
value|SKM_sk_find_ex(NAME_FUNCS, (st), (val))
define|#
directive|define
name|sk_NAME_FUNCS_delete
parameter_list|(
name|st
parameter_list|,
name|i
parameter_list|)
value|SKM_sk_delete(NAME_FUNCS, (st), (i))
define|#
directive|define
name|sk_NAME_FUNCS_delete_ptr
parameter_list|(
name|st
parameter_list|,
name|ptr
parameter_list|)
value|SKM_sk_delete_ptr(NAME_FUNCS, (st), (ptr))
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
define|#
directive|define
name|sk_NAME_FUNCS_set_cmp_func
parameter_list|(
name|st
parameter_list|,
name|cmp
parameter_list|)
value|SKM_sk_set_cmp_func(NAME_FUNCS, (st), (cmp))
define|#
directive|define
name|sk_NAME_FUNCS_dup
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_dup(NAME_FUNCS, st)
define|#
directive|define
name|sk_NAME_FUNCS_pop_free
parameter_list|(
name|st
parameter_list|,
name|free_func
parameter_list|)
value|SKM_sk_pop_free(NAME_FUNCS, (st), (free_func))
define|#
directive|define
name|sk_NAME_FUNCS_shift
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_shift(NAME_FUNCS, (st))
define|#
directive|define
name|sk_NAME_FUNCS_pop
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_pop(NAME_FUNCS, (st))
define|#
directive|define
name|sk_NAME_FUNCS_sort
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_sort(NAME_FUNCS, (st))
define|#
directive|define
name|sk_NAME_FUNCS_is_sorted
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_is_sorted(NAME_FUNCS, (st))
define|#
directive|define
name|sk_OCSP_CERTID_new
parameter_list|(
name|cmp
parameter_list|)
value|SKM_sk_new(OCSP_CERTID, (cmp))
define|#
directive|define
name|sk_OCSP_CERTID_new_null
parameter_list|()
value|SKM_sk_new_null(OCSP_CERTID)
define|#
directive|define
name|sk_OCSP_CERTID_free
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_free(OCSP_CERTID, (st))
define|#
directive|define
name|sk_OCSP_CERTID_num
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_num(OCSP_CERTID, (st))
define|#
directive|define
name|sk_OCSP_CERTID_value
parameter_list|(
name|st
parameter_list|,
name|i
parameter_list|)
value|SKM_sk_value(OCSP_CERTID, (st), (i))
define|#
directive|define
name|sk_OCSP_CERTID_set
parameter_list|(
name|st
parameter_list|,
name|i
parameter_list|,
name|val
parameter_list|)
value|SKM_sk_set(OCSP_CERTID, (st), (i), (val))
define|#
directive|define
name|sk_OCSP_CERTID_zero
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_zero(OCSP_CERTID, (st))
define|#
directive|define
name|sk_OCSP_CERTID_push
parameter_list|(
name|st
parameter_list|,
name|val
parameter_list|)
value|SKM_sk_push(OCSP_CERTID, (st), (val))
define|#
directive|define
name|sk_OCSP_CERTID_unshift
parameter_list|(
name|st
parameter_list|,
name|val
parameter_list|)
value|SKM_sk_unshift(OCSP_CERTID, (st), (val))
define|#
directive|define
name|sk_OCSP_CERTID_find
parameter_list|(
name|st
parameter_list|,
name|val
parameter_list|)
value|SKM_sk_find(OCSP_CERTID, (st), (val))
define|#
directive|define
name|sk_OCSP_CERTID_find_ex
parameter_list|(
name|st
parameter_list|,
name|val
parameter_list|)
value|SKM_sk_find_ex(OCSP_CERTID, (st), (val))
define|#
directive|define
name|sk_OCSP_CERTID_delete
parameter_list|(
name|st
parameter_list|,
name|i
parameter_list|)
value|SKM_sk_delete(OCSP_CERTID, (st), (i))
define|#
directive|define
name|sk_OCSP_CERTID_delete_ptr
parameter_list|(
name|st
parameter_list|,
name|ptr
parameter_list|)
value|SKM_sk_delete_ptr(OCSP_CERTID, (st), (ptr))
define|#
directive|define
name|sk_OCSP_CERTID_insert
parameter_list|(
name|st
parameter_list|,
name|val
parameter_list|,
name|i
parameter_list|)
value|SKM_sk_insert(OCSP_CERTID, (st), (val), (i))
define|#
directive|define
name|sk_OCSP_CERTID_set_cmp_func
parameter_list|(
name|st
parameter_list|,
name|cmp
parameter_list|)
value|SKM_sk_set_cmp_func(OCSP_CERTID, (st), (cmp))
define|#
directive|define
name|sk_OCSP_CERTID_dup
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_dup(OCSP_CERTID, st)
define|#
directive|define
name|sk_OCSP_CERTID_pop_free
parameter_list|(
name|st
parameter_list|,
name|free_func
parameter_list|)
value|SKM_sk_pop_free(OCSP_CERTID, (st), (free_func))
define|#
directive|define
name|sk_OCSP_CERTID_shift
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_shift(OCSP_CERTID, (st))
define|#
directive|define
name|sk_OCSP_CERTID_pop
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_pop(OCSP_CERTID, (st))
define|#
directive|define
name|sk_OCSP_CERTID_sort
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_sort(OCSP_CERTID, (st))
define|#
directive|define
name|sk_OCSP_CERTID_is_sorted
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_is_sorted(OCSP_CERTID, (st))
define|#
directive|define
name|sk_OCSP_ONEREQ_new
parameter_list|(
name|cmp
parameter_list|)
value|SKM_sk_new(OCSP_ONEREQ, (cmp))
define|#
directive|define
name|sk_OCSP_ONEREQ_new_null
parameter_list|()
value|SKM_sk_new_null(OCSP_ONEREQ)
define|#
directive|define
name|sk_OCSP_ONEREQ_free
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_free(OCSP_ONEREQ, (st))
define|#
directive|define
name|sk_OCSP_ONEREQ_num
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_num(OCSP_ONEREQ, (st))
define|#
directive|define
name|sk_OCSP_ONEREQ_value
parameter_list|(
name|st
parameter_list|,
name|i
parameter_list|)
value|SKM_sk_value(OCSP_ONEREQ, (st), (i))
define|#
directive|define
name|sk_OCSP_ONEREQ_set
parameter_list|(
name|st
parameter_list|,
name|i
parameter_list|,
name|val
parameter_list|)
value|SKM_sk_set(OCSP_ONEREQ, (st), (i), (val))
define|#
directive|define
name|sk_OCSP_ONEREQ_zero
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_zero(OCSP_ONEREQ, (st))
define|#
directive|define
name|sk_OCSP_ONEREQ_push
parameter_list|(
name|st
parameter_list|,
name|val
parameter_list|)
value|SKM_sk_push(OCSP_ONEREQ, (st), (val))
define|#
directive|define
name|sk_OCSP_ONEREQ_unshift
parameter_list|(
name|st
parameter_list|,
name|val
parameter_list|)
value|SKM_sk_unshift(OCSP_ONEREQ, (st), (val))
define|#
directive|define
name|sk_OCSP_ONEREQ_find
parameter_list|(
name|st
parameter_list|,
name|val
parameter_list|)
value|SKM_sk_find(OCSP_ONEREQ, (st), (val))
define|#
directive|define
name|sk_OCSP_ONEREQ_find_ex
parameter_list|(
name|st
parameter_list|,
name|val
parameter_list|)
value|SKM_sk_find_ex(OCSP_ONEREQ, (st), (val))
define|#
directive|define
name|sk_OCSP_ONEREQ_delete
parameter_list|(
name|st
parameter_list|,
name|i
parameter_list|)
value|SKM_sk_delete(OCSP_ONEREQ, (st), (i))
define|#
directive|define
name|sk_OCSP_ONEREQ_delete_ptr
parameter_list|(
name|st
parameter_list|,
name|ptr
parameter_list|)
value|SKM_sk_delete_ptr(OCSP_ONEREQ, (st), (ptr))
define|#
directive|define
name|sk_OCSP_ONEREQ_insert
parameter_list|(
name|st
parameter_list|,
name|val
parameter_list|,
name|i
parameter_list|)
value|SKM_sk_insert(OCSP_ONEREQ, (st), (val), (i))
define|#
directive|define
name|sk_OCSP_ONEREQ_set_cmp_func
parameter_list|(
name|st
parameter_list|,
name|cmp
parameter_list|)
value|SKM_sk_set_cmp_func(OCSP_ONEREQ, (st), (cmp))
define|#
directive|define
name|sk_OCSP_ONEREQ_dup
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_dup(OCSP_ONEREQ, st)
define|#
directive|define
name|sk_OCSP_ONEREQ_pop_free
parameter_list|(
name|st
parameter_list|,
name|free_func
parameter_list|)
value|SKM_sk_pop_free(OCSP_ONEREQ, (st), (free_func))
define|#
directive|define
name|sk_OCSP_ONEREQ_shift
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_shift(OCSP_ONEREQ, (st))
define|#
directive|define
name|sk_OCSP_ONEREQ_pop
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_pop(OCSP_ONEREQ, (st))
define|#
directive|define
name|sk_OCSP_ONEREQ_sort
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_sort(OCSP_ONEREQ, (st))
define|#
directive|define
name|sk_OCSP_ONEREQ_is_sorted
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_is_sorted(OCSP_ONEREQ, (st))
define|#
directive|define
name|sk_OCSP_RESPID_new
parameter_list|(
name|cmp
parameter_list|)
value|SKM_sk_new(OCSP_RESPID, (cmp))
define|#
directive|define
name|sk_OCSP_RESPID_new_null
parameter_list|()
value|SKM_sk_new_null(OCSP_RESPID)
define|#
directive|define
name|sk_OCSP_RESPID_free
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_free(OCSP_RESPID, (st))
define|#
directive|define
name|sk_OCSP_RESPID_num
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_num(OCSP_RESPID, (st))
define|#
directive|define
name|sk_OCSP_RESPID_value
parameter_list|(
name|st
parameter_list|,
name|i
parameter_list|)
value|SKM_sk_value(OCSP_RESPID, (st), (i))
define|#
directive|define
name|sk_OCSP_RESPID_set
parameter_list|(
name|st
parameter_list|,
name|i
parameter_list|,
name|val
parameter_list|)
value|SKM_sk_set(OCSP_RESPID, (st), (i), (val))
define|#
directive|define
name|sk_OCSP_RESPID_zero
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_zero(OCSP_RESPID, (st))
define|#
directive|define
name|sk_OCSP_RESPID_push
parameter_list|(
name|st
parameter_list|,
name|val
parameter_list|)
value|SKM_sk_push(OCSP_RESPID, (st), (val))
define|#
directive|define
name|sk_OCSP_RESPID_unshift
parameter_list|(
name|st
parameter_list|,
name|val
parameter_list|)
value|SKM_sk_unshift(OCSP_RESPID, (st), (val))
define|#
directive|define
name|sk_OCSP_RESPID_find
parameter_list|(
name|st
parameter_list|,
name|val
parameter_list|)
value|SKM_sk_find(OCSP_RESPID, (st), (val))
define|#
directive|define
name|sk_OCSP_RESPID_find_ex
parameter_list|(
name|st
parameter_list|,
name|val
parameter_list|)
value|SKM_sk_find_ex(OCSP_RESPID, (st), (val))
define|#
directive|define
name|sk_OCSP_RESPID_delete
parameter_list|(
name|st
parameter_list|,
name|i
parameter_list|)
value|SKM_sk_delete(OCSP_RESPID, (st), (i))
define|#
directive|define
name|sk_OCSP_RESPID_delete_ptr
parameter_list|(
name|st
parameter_list|,
name|ptr
parameter_list|)
value|SKM_sk_delete_ptr(OCSP_RESPID, (st), (ptr))
define|#
directive|define
name|sk_OCSP_RESPID_insert
parameter_list|(
name|st
parameter_list|,
name|val
parameter_list|,
name|i
parameter_list|)
value|SKM_sk_insert(OCSP_RESPID, (st), (val), (i))
define|#
directive|define
name|sk_OCSP_RESPID_set_cmp_func
parameter_list|(
name|st
parameter_list|,
name|cmp
parameter_list|)
value|SKM_sk_set_cmp_func(OCSP_RESPID, (st), (cmp))
define|#
directive|define
name|sk_OCSP_RESPID_dup
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_dup(OCSP_RESPID, st)
define|#
directive|define
name|sk_OCSP_RESPID_pop_free
parameter_list|(
name|st
parameter_list|,
name|free_func
parameter_list|)
value|SKM_sk_pop_free(OCSP_RESPID, (st), (free_func))
define|#
directive|define
name|sk_OCSP_RESPID_shift
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_shift(OCSP_RESPID, (st))
define|#
directive|define
name|sk_OCSP_RESPID_pop
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_pop(OCSP_RESPID, (st))
define|#
directive|define
name|sk_OCSP_RESPID_sort
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_sort(OCSP_RESPID, (st))
define|#
directive|define
name|sk_OCSP_RESPID_is_sorted
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_is_sorted(OCSP_RESPID, (st))
define|#
directive|define
name|sk_OCSP_SINGLERESP_new
parameter_list|(
name|cmp
parameter_list|)
value|SKM_sk_new(OCSP_SINGLERESP, (cmp))
define|#
directive|define
name|sk_OCSP_SINGLERESP_new_null
parameter_list|()
value|SKM_sk_new_null(OCSP_SINGLERESP)
define|#
directive|define
name|sk_OCSP_SINGLERESP_free
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_free(OCSP_SINGLERESP, (st))
define|#
directive|define
name|sk_OCSP_SINGLERESP_num
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_num(OCSP_SINGLERESP, (st))
define|#
directive|define
name|sk_OCSP_SINGLERESP_value
parameter_list|(
name|st
parameter_list|,
name|i
parameter_list|)
value|SKM_sk_value(OCSP_SINGLERESP, (st), (i))
define|#
directive|define
name|sk_OCSP_SINGLERESP_set
parameter_list|(
name|st
parameter_list|,
name|i
parameter_list|,
name|val
parameter_list|)
value|SKM_sk_set(OCSP_SINGLERESP, (st), (i), (val))
define|#
directive|define
name|sk_OCSP_SINGLERESP_zero
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_zero(OCSP_SINGLERESP, (st))
define|#
directive|define
name|sk_OCSP_SINGLERESP_push
parameter_list|(
name|st
parameter_list|,
name|val
parameter_list|)
value|SKM_sk_push(OCSP_SINGLERESP, (st), (val))
define|#
directive|define
name|sk_OCSP_SINGLERESP_unshift
parameter_list|(
name|st
parameter_list|,
name|val
parameter_list|)
value|SKM_sk_unshift(OCSP_SINGLERESP, (st), (val))
define|#
directive|define
name|sk_OCSP_SINGLERESP_find
parameter_list|(
name|st
parameter_list|,
name|val
parameter_list|)
value|SKM_sk_find(OCSP_SINGLERESP, (st), (val))
define|#
directive|define
name|sk_OCSP_SINGLERESP_find_ex
parameter_list|(
name|st
parameter_list|,
name|val
parameter_list|)
value|SKM_sk_find_ex(OCSP_SINGLERESP, (st), (val))
define|#
directive|define
name|sk_OCSP_SINGLERESP_delete
parameter_list|(
name|st
parameter_list|,
name|i
parameter_list|)
value|SKM_sk_delete(OCSP_SINGLERESP, (st), (i))
define|#
directive|define
name|sk_OCSP_SINGLERESP_delete_ptr
parameter_list|(
name|st
parameter_list|,
name|ptr
parameter_list|)
value|SKM_sk_delete_ptr(OCSP_SINGLERESP, (st), (ptr))
define|#
directive|define
name|sk_OCSP_SINGLERESP_insert
parameter_list|(
name|st
parameter_list|,
name|val
parameter_list|,
name|i
parameter_list|)
value|SKM_sk_insert(OCSP_SINGLERESP, (st), (val), (i))
define|#
directive|define
name|sk_OCSP_SINGLERESP_set_cmp_func
parameter_list|(
name|st
parameter_list|,
name|cmp
parameter_list|)
value|SKM_sk_set_cmp_func(OCSP_SINGLERESP, (st), (cmp))
define|#
directive|define
name|sk_OCSP_SINGLERESP_dup
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_dup(OCSP_SINGLERESP, st)
define|#
directive|define
name|sk_OCSP_SINGLERESP_pop_free
parameter_list|(
name|st
parameter_list|,
name|free_func
parameter_list|)
value|SKM_sk_pop_free(OCSP_SINGLERESP, (st), (free_func))
define|#
directive|define
name|sk_OCSP_SINGLERESP_shift
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_shift(OCSP_SINGLERESP, (st))
define|#
directive|define
name|sk_OCSP_SINGLERESP_pop
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_pop(OCSP_SINGLERESP, (st))
define|#
directive|define
name|sk_OCSP_SINGLERESP_sort
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_sort(OCSP_SINGLERESP, (st))
define|#
directive|define
name|sk_OCSP_SINGLERESP_is_sorted
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_is_sorted(OCSP_SINGLERESP, (st))
define|#
directive|define
name|sk_PKCS12_SAFEBAG_new
parameter_list|(
name|cmp
parameter_list|)
value|SKM_sk_new(PKCS12_SAFEBAG, (cmp))
define|#
directive|define
name|sk_PKCS12_SAFEBAG_new_null
parameter_list|()
value|SKM_sk_new_null(PKCS12_SAFEBAG)
define|#
directive|define
name|sk_PKCS12_SAFEBAG_free
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_free(PKCS12_SAFEBAG, (st))
define|#
directive|define
name|sk_PKCS12_SAFEBAG_num
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_num(PKCS12_SAFEBAG, (st))
define|#
directive|define
name|sk_PKCS12_SAFEBAG_value
parameter_list|(
name|st
parameter_list|,
name|i
parameter_list|)
value|SKM_sk_value(PKCS12_SAFEBAG, (st), (i))
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
define|#
directive|define
name|sk_PKCS12_SAFEBAG_zero
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_zero(PKCS12_SAFEBAG, (st))
define|#
directive|define
name|sk_PKCS12_SAFEBAG_push
parameter_list|(
name|st
parameter_list|,
name|val
parameter_list|)
value|SKM_sk_push(PKCS12_SAFEBAG, (st), (val))
define|#
directive|define
name|sk_PKCS12_SAFEBAG_unshift
parameter_list|(
name|st
parameter_list|,
name|val
parameter_list|)
value|SKM_sk_unshift(PKCS12_SAFEBAG, (st), (val))
define|#
directive|define
name|sk_PKCS12_SAFEBAG_find
parameter_list|(
name|st
parameter_list|,
name|val
parameter_list|)
value|SKM_sk_find(PKCS12_SAFEBAG, (st), (val))
define|#
directive|define
name|sk_PKCS12_SAFEBAG_find_ex
parameter_list|(
name|st
parameter_list|,
name|val
parameter_list|)
value|SKM_sk_find_ex(PKCS12_SAFEBAG, (st), (val))
define|#
directive|define
name|sk_PKCS12_SAFEBAG_delete
parameter_list|(
name|st
parameter_list|,
name|i
parameter_list|)
value|SKM_sk_delete(PKCS12_SAFEBAG, (st), (i))
define|#
directive|define
name|sk_PKCS12_SAFEBAG_delete_ptr
parameter_list|(
name|st
parameter_list|,
name|ptr
parameter_list|)
value|SKM_sk_delete_ptr(PKCS12_SAFEBAG, (st), (ptr))
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
define|#
directive|define
name|sk_PKCS12_SAFEBAG_set_cmp_func
parameter_list|(
name|st
parameter_list|,
name|cmp
parameter_list|)
value|SKM_sk_set_cmp_func(PKCS12_SAFEBAG, (st), (cmp))
define|#
directive|define
name|sk_PKCS12_SAFEBAG_dup
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_dup(PKCS12_SAFEBAG, st)
define|#
directive|define
name|sk_PKCS12_SAFEBAG_pop_free
parameter_list|(
name|st
parameter_list|,
name|free_func
parameter_list|)
value|SKM_sk_pop_free(PKCS12_SAFEBAG, (st), (free_func))
define|#
directive|define
name|sk_PKCS12_SAFEBAG_shift
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_shift(PKCS12_SAFEBAG, (st))
define|#
directive|define
name|sk_PKCS12_SAFEBAG_pop
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_pop(PKCS12_SAFEBAG, (st))
define|#
directive|define
name|sk_PKCS12_SAFEBAG_sort
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_sort(PKCS12_SAFEBAG, (st))
define|#
directive|define
name|sk_PKCS12_SAFEBAG_is_sorted
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_is_sorted(PKCS12_SAFEBAG, (st))
define|#
directive|define
name|sk_PKCS7_new
parameter_list|(
name|cmp
parameter_list|)
value|SKM_sk_new(PKCS7, (cmp))
define|#
directive|define
name|sk_PKCS7_new_null
parameter_list|()
value|SKM_sk_new_null(PKCS7)
define|#
directive|define
name|sk_PKCS7_free
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_free(PKCS7, (st))
define|#
directive|define
name|sk_PKCS7_num
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_num(PKCS7, (st))
define|#
directive|define
name|sk_PKCS7_value
parameter_list|(
name|st
parameter_list|,
name|i
parameter_list|)
value|SKM_sk_value(PKCS7, (st), (i))
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
define|#
directive|define
name|sk_PKCS7_zero
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_zero(PKCS7, (st))
define|#
directive|define
name|sk_PKCS7_push
parameter_list|(
name|st
parameter_list|,
name|val
parameter_list|)
value|SKM_sk_push(PKCS7, (st), (val))
define|#
directive|define
name|sk_PKCS7_unshift
parameter_list|(
name|st
parameter_list|,
name|val
parameter_list|)
value|SKM_sk_unshift(PKCS7, (st), (val))
define|#
directive|define
name|sk_PKCS7_find
parameter_list|(
name|st
parameter_list|,
name|val
parameter_list|)
value|SKM_sk_find(PKCS7, (st), (val))
define|#
directive|define
name|sk_PKCS7_find_ex
parameter_list|(
name|st
parameter_list|,
name|val
parameter_list|)
value|SKM_sk_find_ex(PKCS7, (st), (val))
define|#
directive|define
name|sk_PKCS7_delete
parameter_list|(
name|st
parameter_list|,
name|i
parameter_list|)
value|SKM_sk_delete(PKCS7, (st), (i))
define|#
directive|define
name|sk_PKCS7_delete_ptr
parameter_list|(
name|st
parameter_list|,
name|ptr
parameter_list|)
value|SKM_sk_delete_ptr(PKCS7, (st), (ptr))
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
define|#
directive|define
name|sk_PKCS7_set_cmp_func
parameter_list|(
name|st
parameter_list|,
name|cmp
parameter_list|)
value|SKM_sk_set_cmp_func(PKCS7, (st), (cmp))
define|#
directive|define
name|sk_PKCS7_dup
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_dup(PKCS7, st)
define|#
directive|define
name|sk_PKCS7_pop_free
parameter_list|(
name|st
parameter_list|,
name|free_func
parameter_list|)
value|SKM_sk_pop_free(PKCS7, (st), (free_func))
define|#
directive|define
name|sk_PKCS7_shift
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_shift(PKCS7, (st))
define|#
directive|define
name|sk_PKCS7_pop
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_pop(PKCS7, (st))
define|#
directive|define
name|sk_PKCS7_sort
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_sort(PKCS7, (st))
define|#
directive|define
name|sk_PKCS7_is_sorted
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_is_sorted(PKCS7, (st))
define|#
directive|define
name|sk_PKCS7_RECIP_INFO_new
parameter_list|(
name|cmp
parameter_list|)
value|SKM_sk_new(PKCS7_RECIP_INFO, (cmp))
define|#
directive|define
name|sk_PKCS7_RECIP_INFO_new_null
parameter_list|()
value|SKM_sk_new_null(PKCS7_RECIP_INFO)
define|#
directive|define
name|sk_PKCS7_RECIP_INFO_free
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_free(PKCS7_RECIP_INFO, (st))
define|#
directive|define
name|sk_PKCS7_RECIP_INFO_num
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_num(PKCS7_RECIP_INFO, (st))
define|#
directive|define
name|sk_PKCS7_RECIP_INFO_value
parameter_list|(
name|st
parameter_list|,
name|i
parameter_list|)
value|SKM_sk_value(PKCS7_RECIP_INFO, (st), (i))
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
define|#
directive|define
name|sk_PKCS7_RECIP_INFO_zero
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_zero(PKCS7_RECIP_INFO, (st))
define|#
directive|define
name|sk_PKCS7_RECIP_INFO_push
parameter_list|(
name|st
parameter_list|,
name|val
parameter_list|)
value|SKM_sk_push(PKCS7_RECIP_INFO, (st), (val))
define|#
directive|define
name|sk_PKCS7_RECIP_INFO_unshift
parameter_list|(
name|st
parameter_list|,
name|val
parameter_list|)
value|SKM_sk_unshift(PKCS7_RECIP_INFO, (st), (val))
define|#
directive|define
name|sk_PKCS7_RECIP_INFO_find
parameter_list|(
name|st
parameter_list|,
name|val
parameter_list|)
value|SKM_sk_find(PKCS7_RECIP_INFO, (st), (val))
define|#
directive|define
name|sk_PKCS7_RECIP_INFO_find_ex
parameter_list|(
name|st
parameter_list|,
name|val
parameter_list|)
value|SKM_sk_find_ex(PKCS7_RECIP_INFO, (st), (val))
define|#
directive|define
name|sk_PKCS7_RECIP_INFO_delete
parameter_list|(
name|st
parameter_list|,
name|i
parameter_list|)
value|SKM_sk_delete(PKCS7_RECIP_INFO, (st), (i))
define|#
directive|define
name|sk_PKCS7_RECIP_INFO_delete_ptr
parameter_list|(
name|st
parameter_list|,
name|ptr
parameter_list|)
value|SKM_sk_delete_ptr(PKCS7_RECIP_INFO, (st), (ptr))
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
define|#
directive|define
name|sk_PKCS7_RECIP_INFO_set_cmp_func
parameter_list|(
name|st
parameter_list|,
name|cmp
parameter_list|)
value|SKM_sk_set_cmp_func(PKCS7_RECIP_INFO, (st), (cmp))
define|#
directive|define
name|sk_PKCS7_RECIP_INFO_dup
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_dup(PKCS7_RECIP_INFO, st)
define|#
directive|define
name|sk_PKCS7_RECIP_INFO_pop_free
parameter_list|(
name|st
parameter_list|,
name|free_func
parameter_list|)
value|SKM_sk_pop_free(PKCS7_RECIP_INFO, (st), (free_func))
define|#
directive|define
name|sk_PKCS7_RECIP_INFO_shift
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_shift(PKCS7_RECIP_INFO, (st))
define|#
directive|define
name|sk_PKCS7_RECIP_INFO_pop
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_pop(PKCS7_RECIP_INFO, (st))
define|#
directive|define
name|sk_PKCS7_RECIP_INFO_sort
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_sort(PKCS7_RECIP_INFO, (st))
define|#
directive|define
name|sk_PKCS7_RECIP_INFO_is_sorted
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_is_sorted(PKCS7_RECIP_INFO, (st))
define|#
directive|define
name|sk_PKCS7_SIGNER_INFO_new
parameter_list|(
name|cmp
parameter_list|)
value|SKM_sk_new(PKCS7_SIGNER_INFO, (cmp))
define|#
directive|define
name|sk_PKCS7_SIGNER_INFO_new_null
parameter_list|()
value|SKM_sk_new_null(PKCS7_SIGNER_INFO)
define|#
directive|define
name|sk_PKCS7_SIGNER_INFO_free
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_free(PKCS7_SIGNER_INFO, (st))
define|#
directive|define
name|sk_PKCS7_SIGNER_INFO_num
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_num(PKCS7_SIGNER_INFO, (st))
define|#
directive|define
name|sk_PKCS7_SIGNER_INFO_value
parameter_list|(
name|st
parameter_list|,
name|i
parameter_list|)
value|SKM_sk_value(PKCS7_SIGNER_INFO, (st), (i))
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
define|#
directive|define
name|sk_PKCS7_SIGNER_INFO_zero
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_zero(PKCS7_SIGNER_INFO, (st))
define|#
directive|define
name|sk_PKCS7_SIGNER_INFO_push
parameter_list|(
name|st
parameter_list|,
name|val
parameter_list|)
value|SKM_sk_push(PKCS7_SIGNER_INFO, (st), (val))
define|#
directive|define
name|sk_PKCS7_SIGNER_INFO_unshift
parameter_list|(
name|st
parameter_list|,
name|val
parameter_list|)
value|SKM_sk_unshift(PKCS7_SIGNER_INFO, (st), (val))
define|#
directive|define
name|sk_PKCS7_SIGNER_INFO_find
parameter_list|(
name|st
parameter_list|,
name|val
parameter_list|)
value|SKM_sk_find(PKCS7_SIGNER_INFO, (st), (val))
define|#
directive|define
name|sk_PKCS7_SIGNER_INFO_find_ex
parameter_list|(
name|st
parameter_list|,
name|val
parameter_list|)
value|SKM_sk_find_ex(PKCS7_SIGNER_INFO, (st), (val))
define|#
directive|define
name|sk_PKCS7_SIGNER_INFO_delete
parameter_list|(
name|st
parameter_list|,
name|i
parameter_list|)
value|SKM_sk_delete(PKCS7_SIGNER_INFO, (st), (i))
define|#
directive|define
name|sk_PKCS7_SIGNER_INFO_delete_ptr
parameter_list|(
name|st
parameter_list|,
name|ptr
parameter_list|)
value|SKM_sk_delete_ptr(PKCS7_SIGNER_INFO, (st), (ptr))
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
define|#
directive|define
name|sk_PKCS7_SIGNER_INFO_set_cmp_func
parameter_list|(
name|st
parameter_list|,
name|cmp
parameter_list|)
value|SKM_sk_set_cmp_func(PKCS7_SIGNER_INFO, (st), (cmp))
define|#
directive|define
name|sk_PKCS7_SIGNER_INFO_dup
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_dup(PKCS7_SIGNER_INFO, st)
define|#
directive|define
name|sk_PKCS7_SIGNER_INFO_pop_free
parameter_list|(
name|st
parameter_list|,
name|free_func
parameter_list|)
value|SKM_sk_pop_free(PKCS7_SIGNER_INFO, (st), (free_func))
define|#
directive|define
name|sk_PKCS7_SIGNER_INFO_shift
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_shift(PKCS7_SIGNER_INFO, (st))
define|#
directive|define
name|sk_PKCS7_SIGNER_INFO_pop
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_pop(PKCS7_SIGNER_INFO, (st))
define|#
directive|define
name|sk_PKCS7_SIGNER_INFO_sort
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_sort(PKCS7_SIGNER_INFO, (st))
define|#
directive|define
name|sk_PKCS7_SIGNER_INFO_is_sorted
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_is_sorted(PKCS7_SIGNER_INFO, (st))
define|#
directive|define
name|sk_POLICYINFO_new
parameter_list|(
name|cmp
parameter_list|)
value|SKM_sk_new(POLICYINFO, (cmp))
define|#
directive|define
name|sk_POLICYINFO_new_null
parameter_list|()
value|SKM_sk_new_null(POLICYINFO)
define|#
directive|define
name|sk_POLICYINFO_free
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_free(POLICYINFO, (st))
define|#
directive|define
name|sk_POLICYINFO_num
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_num(POLICYINFO, (st))
define|#
directive|define
name|sk_POLICYINFO_value
parameter_list|(
name|st
parameter_list|,
name|i
parameter_list|)
value|SKM_sk_value(POLICYINFO, (st), (i))
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
define|#
directive|define
name|sk_POLICYINFO_zero
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_zero(POLICYINFO, (st))
define|#
directive|define
name|sk_POLICYINFO_push
parameter_list|(
name|st
parameter_list|,
name|val
parameter_list|)
value|SKM_sk_push(POLICYINFO, (st), (val))
define|#
directive|define
name|sk_POLICYINFO_unshift
parameter_list|(
name|st
parameter_list|,
name|val
parameter_list|)
value|SKM_sk_unshift(POLICYINFO, (st), (val))
define|#
directive|define
name|sk_POLICYINFO_find
parameter_list|(
name|st
parameter_list|,
name|val
parameter_list|)
value|SKM_sk_find(POLICYINFO, (st), (val))
define|#
directive|define
name|sk_POLICYINFO_find_ex
parameter_list|(
name|st
parameter_list|,
name|val
parameter_list|)
value|SKM_sk_find_ex(POLICYINFO, (st), (val))
define|#
directive|define
name|sk_POLICYINFO_delete
parameter_list|(
name|st
parameter_list|,
name|i
parameter_list|)
value|SKM_sk_delete(POLICYINFO, (st), (i))
define|#
directive|define
name|sk_POLICYINFO_delete_ptr
parameter_list|(
name|st
parameter_list|,
name|ptr
parameter_list|)
value|SKM_sk_delete_ptr(POLICYINFO, (st), (ptr))
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
define|#
directive|define
name|sk_POLICYINFO_set_cmp_func
parameter_list|(
name|st
parameter_list|,
name|cmp
parameter_list|)
value|SKM_sk_set_cmp_func(POLICYINFO, (st), (cmp))
define|#
directive|define
name|sk_POLICYINFO_dup
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_dup(POLICYINFO, st)
define|#
directive|define
name|sk_POLICYINFO_pop_free
parameter_list|(
name|st
parameter_list|,
name|free_func
parameter_list|)
value|SKM_sk_pop_free(POLICYINFO, (st), (free_func))
define|#
directive|define
name|sk_POLICYINFO_shift
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_shift(POLICYINFO, (st))
define|#
directive|define
name|sk_POLICYINFO_pop
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_pop(POLICYINFO, (st))
define|#
directive|define
name|sk_POLICYINFO_sort
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_sort(POLICYINFO, (st))
define|#
directive|define
name|sk_POLICYINFO_is_sorted
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_is_sorted(POLICYINFO, (st))
define|#
directive|define
name|sk_POLICYQUALINFO_new
parameter_list|(
name|cmp
parameter_list|)
value|SKM_sk_new(POLICYQUALINFO, (cmp))
define|#
directive|define
name|sk_POLICYQUALINFO_new_null
parameter_list|()
value|SKM_sk_new_null(POLICYQUALINFO)
define|#
directive|define
name|sk_POLICYQUALINFO_free
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_free(POLICYQUALINFO, (st))
define|#
directive|define
name|sk_POLICYQUALINFO_num
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_num(POLICYQUALINFO, (st))
define|#
directive|define
name|sk_POLICYQUALINFO_value
parameter_list|(
name|st
parameter_list|,
name|i
parameter_list|)
value|SKM_sk_value(POLICYQUALINFO, (st), (i))
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
define|#
directive|define
name|sk_POLICYQUALINFO_zero
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_zero(POLICYQUALINFO, (st))
define|#
directive|define
name|sk_POLICYQUALINFO_push
parameter_list|(
name|st
parameter_list|,
name|val
parameter_list|)
value|SKM_sk_push(POLICYQUALINFO, (st), (val))
define|#
directive|define
name|sk_POLICYQUALINFO_unshift
parameter_list|(
name|st
parameter_list|,
name|val
parameter_list|)
value|SKM_sk_unshift(POLICYQUALINFO, (st), (val))
define|#
directive|define
name|sk_POLICYQUALINFO_find
parameter_list|(
name|st
parameter_list|,
name|val
parameter_list|)
value|SKM_sk_find(POLICYQUALINFO, (st), (val))
define|#
directive|define
name|sk_POLICYQUALINFO_find_ex
parameter_list|(
name|st
parameter_list|,
name|val
parameter_list|)
value|SKM_sk_find_ex(POLICYQUALINFO, (st), (val))
define|#
directive|define
name|sk_POLICYQUALINFO_delete
parameter_list|(
name|st
parameter_list|,
name|i
parameter_list|)
value|SKM_sk_delete(POLICYQUALINFO, (st), (i))
define|#
directive|define
name|sk_POLICYQUALINFO_delete_ptr
parameter_list|(
name|st
parameter_list|,
name|ptr
parameter_list|)
value|SKM_sk_delete_ptr(POLICYQUALINFO, (st), (ptr))
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
define|#
directive|define
name|sk_POLICYQUALINFO_set_cmp_func
parameter_list|(
name|st
parameter_list|,
name|cmp
parameter_list|)
value|SKM_sk_set_cmp_func(POLICYQUALINFO, (st), (cmp))
define|#
directive|define
name|sk_POLICYQUALINFO_dup
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_dup(POLICYQUALINFO, st)
define|#
directive|define
name|sk_POLICYQUALINFO_pop_free
parameter_list|(
name|st
parameter_list|,
name|free_func
parameter_list|)
value|SKM_sk_pop_free(POLICYQUALINFO, (st), (free_func))
define|#
directive|define
name|sk_POLICYQUALINFO_shift
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_shift(POLICYQUALINFO, (st))
define|#
directive|define
name|sk_POLICYQUALINFO_pop
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_pop(POLICYQUALINFO, (st))
define|#
directive|define
name|sk_POLICYQUALINFO_sort
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_sort(POLICYQUALINFO, (st))
define|#
directive|define
name|sk_POLICYQUALINFO_is_sorted
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_is_sorted(POLICYQUALINFO, (st))
define|#
directive|define
name|sk_POLICY_MAPPING_new
parameter_list|(
name|cmp
parameter_list|)
value|SKM_sk_new(POLICY_MAPPING, (cmp))
define|#
directive|define
name|sk_POLICY_MAPPING_new_null
parameter_list|()
value|SKM_sk_new_null(POLICY_MAPPING)
define|#
directive|define
name|sk_POLICY_MAPPING_free
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_free(POLICY_MAPPING, (st))
define|#
directive|define
name|sk_POLICY_MAPPING_num
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_num(POLICY_MAPPING, (st))
define|#
directive|define
name|sk_POLICY_MAPPING_value
parameter_list|(
name|st
parameter_list|,
name|i
parameter_list|)
value|SKM_sk_value(POLICY_MAPPING, (st), (i))
define|#
directive|define
name|sk_POLICY_MAPPING_set
parameter_list|(
name|st
parameter_list|,
name|i
parameter_list|,
name|val
parameter_list|)
value|SKM_sk_set(POLICY_MAPPING, (st), (i), (val))
define|#
directive|define
name|sk_POLICY_MAPPING_zero
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_zero(POLICY_MAPPING, (st))
define|#
directive|define
name|sk_POLICY_MAPPING_push
parameter_list|(
name|st
parameter_list|,
name|val
parameter_list|)
value|SKM_sk_push(POLICY_MAPPING, (st), (val))
define|#
directive|define
name|sk_POLICY_MAPPING_unshift
parameter_list|(
name|st
parameter_list|,
name|val
parameter_list|)
value|SKM_sk_unshift(POLICY_MAPPING, (st), (val))
define|#
directive|define
name|sk_POLICY_MAPPING_find
parameter_list|(
name|st
parameter_list|,
name|val
parameter_list|)
value|SKM_sk_find(POLICY_MAPPING, (st), (val))
define|#
directive|define
name|sk_POLICY_MAPPING_find_ex
parameter_list|(
name|st
parameter_list|,
name|val
parameter_list|)
value|SKM_sk_find_ex(POLICY_MAPPING, (st), (val))
define|#
directive|define
name|sk_POLICY_MAPPING_delete
parameter_list|(
name|st
parameter_list|,
name|i
parameter_list|)
value|SKM_sk_delete(POLICY_MAPPING, (st), (i))
define|#
directive|define
name|sk_POLICY_MAPPING_delete_ptr
parameter_list|(
name|st
parameter_list|,
name|ptr
parameter_list|)
value|SKM_sk_delete_ptr(POLICY_MAPPING, (st), (ptr))
define|#
directive|define
name|sk_POLICY_MAPPING_insert
parameter_list|(
name|st
parameter_list|,
name|val
parameter_list|,
name|i
parameter_list|)
value|SKM_sk_insert(POLICY_MAPPING, (st), (val), (i))
define|#
directive|define
name|sk_POLICY_MAPPING_set_cmp_func
parameter_list|(
name|st
parameter_list|,
name|cmp
parameter_list|)
value|SKM_sk_set_cmp_func(POLICY_MAPPING, (st), (cmp))
define|#
directive|define
name|sk_POLICY_MAPPING_dup
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_dup(POLICY_MAPPING, st)
define|#
directive|define
name|sk_POLICY_MAPPING_pop_free
parameter_list|(
name|st
parameter_list|,
name|free_func
parameter_list|)
value|SKM_sk_pop_free(POLICY_MAPPING, (st), (free_func))
define|#
directive|define
name|sk_POLICY_MAPPING_shift
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_shift(POLICY_MAPPING, (st))
define|#
directive|define
name|sk_POLICY_MAPPING_pop
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_pop(POLICY_MAPPING, (st))
define|#
directive|define
name|sk_POLICY_MAPPING_sort
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_sort(POLICY_MAPPING, (st))
define|#
directive|define
name|sk_POLICY_MAPPING_is_sorted
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_is_sorted(POLICY_MAPPING, (st))
define|#
directive|define
name|sk_SRP_gN_new
parameter_list|(
name|cmp
parameter_list|)
value|SKM_sk_new(SRP_gN, (cmp))
define|#
directive|define
name|sk_SRP_gN_new_null
parameter_list|()
value|SKM_sk_new_null(SRP_gN)
define|#
directive|define
name|sk_SRP_gN_free
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_free(SRP_gN, (st))
define|#
directive|define
name|sk_SRP_gN_num
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_num(SRP_gN, (st))
define|#
directive|define
name|sk_SRP_gN_value
parameter_list|(
name|st
parameter_list|,
name|i
parameter_list|)
value|SKM_sk_value(SRP_gN, (st), (i))
define|#
directive|define
name|sk_SRP_gN_set
parameter_list|(
name|st
parameter_list|,
name|i
parameter_list|,
name|val
parameter_list|)
value|SKM_sk_set(SRP_gN, (st), (i), (val))
define|#
directive|define
name|sk_SRP_gN_zero
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_zero(SRP_gN, (st))
define|#
directive|define
name|sk_SRP_gN_push
parameter_list|(
name|st
parameter_list|,
name|val
parameter_list|)
value|SKM_sk_push(SRP_gN, (st), (val))
define|#
directive|define
name|sk_SRP_gN_unshift
parameter_list|(
name|st
parameter_list|,
name|val
parameter_list|)
value|SKM_sk_unshift(SRP_gN, (st), (val))
define|#
directive|define
name|sk_SRP_gN_find
parameter_list|(
name|st
parameter_list|,
name|val
parameter_list|)
value|SKM_sk_find(SRP_gN, (st), (val))
define|#
directive|define
name|sk_SRP_gN_find_ex
parameter_list|(
name|st
parameter_list|,
name|val
parameter_list|)
value|SKM_sk_find_ex(SRP_gN, (st), (val))
define|#
directive|define
name|sk_SRP_gN_delete
parameter_list|(
name|st
parameter_list|,
name|i
parameter_list|)
value|SKM_sk_delete(SRP_gN, (st), (i))
define|#
directive|define
name|sk_SRP_gN_delete_ptr
parameter_list|(
name|st
parameter_list|,
name|ptr
parameter_list|)
value|SKM_sk_delete_ptr(SRP_gN, (st), (ptr))
define|#
directive|define
name|sk_SRP_gN_insert
parameter_list|(
name|st
parameter_list|,
name|val
parameter_list|,
name|i
parameter_list|)
value|SKM_sk_insert(SRP_gN, (st), (val), (i))
define|#
directive|define
name|sk_SRP_gN_set_cmp_func
parameter_list|(
name|st
parameter_list|,
name|cmp
parameter_list|)
value|SKM_sk_set_cmp_func(SRP_gN, (st), (cmp))
define|#
directive|define
name|sk_SRP_gN_dup
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_dup(SRP_gN, st)
define|#
directive|define
name|sk_SRP_gN_pop_free
parameter_list|(
name|st
parameter_list|,
name|free_func
parameter_list|)
value|SKM_sk_pop_free(SRP_gN, (st), (free_func))
define|#
directive|define
name|sk_SRP_gN_shift
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_shift(SRP_gN, (st))
define|#
directive|define
name|sk_SRP_gN_pop
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_pop(SRP_gN, (st))
define|#
directive|define
name|sk_SRP_gN_sort
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_sort(SRP_gN, (st))
define|#
directive|define
name|sk_SRP_gN_is_sorted
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_is_sorted(SRP_gN, (st))
define|#
directive|define
name|sk_SRP_gN_cache_new
parameter_list|(
name|cmp
parameter_list|)
value|SKM_sk_new(SRP_gN_cache, (cmp))
define|#
directive|define
name|sk_SRP_gN_cache_new_null
parameter_list|()
value|SKM_sk_new_null(SRP_gN_cache)
define|#
directive|define
name|sk_SRP_gN_cache_free
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_free(SRP_gN_cache, (st))
define|#
directive|define
name|sk_SRP_gN_cache_num
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_num(SRP_gN_cache, (st))
define|#
directive|define
name|sk_SRP_gN_cache_value
parameter_list|(
name|st
parameter_list|,
name|i
parameter_list|)
value|SKM_sk_value(SRP_gN_cache, (st), (i))
define|#
directive|define
name|sk_SRP_gN_cache_set
parameter_list|(
name|st
parameter_list|,
name|i
parameter_list|,
name|val
parameter_list|)
value|SKM_sk_set(SRP_gN_cache, (st), (i), (val))
define|#
directive|define
name|sk_SRP_gN_cache_zero
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_zero(SRP_gN_cache, (st))
define|#
directive|define
name|sk_SRP_gN_cache_push
parameter_list|(
name|st
parameter_list|,
name|val
parameter_list|)
value|SKM_sk_push(SRP_gN_cache, (st), (val))
define|#
directive|define
name|sk_SRP_gN_cache_unshift
parameter_list|(
name|st
parameter_list|,
name|val
parameter_list|)
value|SKM_sk_unshift(SRP_gN_cache, (st), (val))
define|#
directive|define
name|sk_SRP_gN_cache_find
parameter_list|(
name|st
parameter_list|,
name|val
parameter_list|)
value|SKM_sk_find(SRP_gN_cache, (st), (val))
define|#
directive|define
name|sk_SRP_gN_cache_find_ex
parameter_list|(
name|st
parameter_list|,
name|val
parameter_list|)
value|SKM_sk_find_ex(SRP_gN_cache, (st), (val))
define|#
directive|define
name|sk_SRP_gN_cache_delete
parameter_list|(
name|st
parameter_list|,
name|i
parameter_list|)
value|SKM_sk_delete(SRP_gN_cache, (st), (i))
define|#
directive|define
name|sk_SRP_gN_cache_delete_ptr
parameter_list|(
name|st
parameter_list|,
name|ptr
parameter_list|)
value|SKM_sk_delete_ptr(SRP_gN_cache, (st), (ptr))
define|#
directive|define
name|sk_SRP_gN_cache_insert
parameter_list|(
name|st
parameter_list|,
name|val
parameter_list|,
name|i
parameter_list|)
value|SKM_sk_insert(SRP_gN_cache, (st), (val), (i))
define|#
directive|define
name|sk_SRP_gN_cache_set_cmp_func
parameter_list|(
name|st
parameter_list|,
name|cmp
parameter_list|)
value|SKM_sk_set_cmp_func(SRP_gN_cache, (st), (cmp))
define|#
directive|define
name|sk_SRP_gN_cache_dup
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_dup(SRP_gN_cache, st)
define|#
directive|define
name|sk_SRP_gN_cache_pop_free
parameter_list|(
name|st
parameter_list|,
name|free_func
parameter_list|)
value|SKM_sk_pop_free(SRP_gN_cache, (st), (free_func))
define|#
directive|define
name|sk_SRP_gN_cache_shift
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_shift(SRP_gN_cache, (st))
define|#
directive|define
name|sk_SRP_gN_cache_pop
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_pop(SRP_gN_cache, (st))
define|#
directive|define
name|sk_SRP_gN_cache_sort
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_sort(SRP_gN_cache, (st))
define|#
directive|define
name|sk_SRP_gN_cache_is_sorted
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_is_sorted(SRP_gN_cache, (st))
define|#
directive|define
name|sk_SRP_user_pwd_new
parameter_list|(
name|cmp
parameter_list|)
value|SKM_sk_new(SRP_user_pwd, (cmp))
define|#
directive|define
name|sk_SRP_user_pwd_new_null
parameter_list|()
value|SKM_sk_new_null(SRP_user_pwd)
define|#
directive|define
name|sk_SRP_user_pwd_free
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_free(SRP_user_pwd, (st))
define|#
directive|define
name|sk_SRP_user_pwd_num
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_num(SRP_user_pwd, (st))
define|#
directive|define
name|sk_SRP_user_pwd_value
parameter_list|(
name|st
parameter_list|,
name|i
parameter_list|)
value|SKM_sk_value(SRP_user_pwd, (st), (i))
define|#
directive|define
name|sk_SRP_user_pwd_set
parameter_list|(
name|st
parameter_list|,
name|i
parameter_list|,
name|val
parameter_list|)
value|SKM_sk_set(SRP_user_pwd, (st), (i), (val))
define|#
directive|define
name|sk_SRP_user_pwd_zero
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_zero(SRP_user_pwd, (st))
define|#
directive|define
name|sk_SRP_user_pwd_push
parameter_list|(
name|st
parameter_list|,
name|val
parameter_list|)
value|SKM_sk_push(SRP_user_pwd, (st), (val))
define|#
directive|define
name|sk_SRP_user_pwd_unshift
parameter_list|(
name|st
parameter_list|,
name|val
parameter_list|)
value|SKM_sk_unshift(SRP_user_pwd, (st), (val))
define|#
directive|define
name|sk_SRP_user_pwd_find
parameter_list|(
name|st
parameter_list|,
name|val
parameter_list|)
value|SKM_sk_find(SRP_user_pwd, (st), (val))
define|#
directive|define
name|sk_SRP_user_pwd_find_ex
parameter_list|(
name|st
parameter_list|,
name|val
parameter_list|)
value|SKM_sk_find_ex(SRP_user_pwd, (st), (val))
define|#
directive|define
name|sk_SRP_user_pwd_delete
parameter_list|(
name|st
parameter_list|,
name|i
parameter_list|)
value|SKM_sk_delete(SRP_user_pwd, (st), (i))
define|#
directive|define
name|sk_SRP_user_pwd_delete_ptr
parameter_list|(
name|st
parameter_list|,
name|ptr
parameter_list|)
value|SKM_sk_delete_ptr(SRP_user_pwd, (st), (ptr))
define|#
directive|define
name|sk_SRP_user_pwd_insert
parameter_list|(
name|st
parameter_list|,
name|val
parameter_list|,
name|i
parameter_list|)
value|SKM_sk_insert(SRP_user_pwd, (st), (val), (i))
define|#
directive|define
name|sk_SRP_user_pwd_set_cmp_func
parameter_list|(
name|st
parameter_list|,
name|cmp
parameter_list|)
value|SKM_sk_set_cmp_func(SRP_user_pwd, (st), (cmp))
define|#
directive|define
name|sk_SRP_user_pwd_dup
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_dup(SRP_user_pwd, st)
define|#
directive|define
name|sk_SRP_user_pwd_pop_free
parameter_list|(
name|st
parameter_list|,
name|free_func
parameter_list|)
value|SKM_sk_pop_free(SRP_user_pwd, (st), (free_func))
define|#
directive|define
name|sk_SRP_user_pwd_shift
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_shift(SRP_user_pwd, (st))
define|#
directive|define
name|sk_SRP_user_pwd_pop
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_pop(SRP_user_pwd, (st))
define|#
directive|define
name|sk_SRP_user_pwd_sort
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_sort(SRP_user_pwd, (st))
define|#
directive|define
name|sk_SRP_user_pwd_is_sorted
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_is_sorted(SRP_user_pwd, (st))
define|#
directive|define
name|sk_SRTP_PROTECTION_PROFILE_new
parameter_list|(
name|cmp
parameter_list|)
value|SKM_sk_new(SRTP_PROTECTION_PROFILE, (cmp))
define|#
directive|define
name|sk_SRTP_PROTECTION_PROFILE_new_null
parameter_list|()
value|SKM_sk_new_null(SRTP_PROTECTION_PROFILE)
define|#
directive|define
name|sk_SRTP_PROTECTION_PROFILE_free
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_free(SRTP_PROTECTION_PROFILE, (st))
define|#
directive|define
name|sk_SRTP_PROTECTION_PROFILE_num
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_num(SRTP_PROTECTION_PROFILE, (st))
define|#
directive|define
name|sk_SRTP_PROTECTION_PROFILE_value
parameter_list|(
name|st
parameter_list|,
name|i
parameter_list|)
value|SKM_sk_value(SRTP_PROTECTION_PROFILE, (st), (i))
define|#
directive|define
name|sk_SRTP_PROTECTION_PROFILE_set
parameter_list|(
name|st
parameter_list|,
name|i
parameter_list|,
name|val
parameter_list|)
value|SKM_sk_set(SRTP_PROTECTION_PROFILE, (st), (i), (val))
define|#
directive|define
name|sk_SRTP_PROTECTION_PROFILE_zero
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_zero(SRTP_PROTECTION_PROFILE, (st))
define|#
directive|define
name|sk_SRTP_PROTECTION_PROFILE_push
parameter_list|(
name|st
parameter_list|,
name|val
parameter_list|)
value|SKM_sk_push(SRTP_PROTECTION_PROFILE, (st), (val))
define|#
directive|define
name|sk_SRTP_PROTECTION_PROFILE_unshift
parameter_list|(
name|st
parameter_list|,
name|val
parameter_list|)
value|SKM_sk_unshift(SRTP_PROTECTION_PROFILE, (st), (val))
define|#
directive|define
name|sk_SRTP_PROTECTION_PROFILE_find
parameter_list|(
name|st
parameter_list|,
name|val
parameter_list|)
value|SKM_sk_find(SRTP_PROTECTION_PROFILE, (st), (val))
define|#
directive|define
name|sk_SRTP_PROTECTION_PROFILE_find_ex
parameter_list|(
name|st
parameter_list|,
name|val
parameter_list|)
value|SKM_sk_find_ex(SRTP_PROTECTION_PROFILE, (st), (val))
define|#
directive|define
name|sk_SRTP_PROTECTION_PROFILE_delete
parameter_list|(
name|st
parameter_list|,
name|i
parameter_list|)
value|SKM_sk_delete(SRTP_PROTECTION_PROFILE, (st), (i))
define|#
directive|define
name|sk_SRTP_PROTECTION_PROFILE_delete_ptr
parameter_list|(
name|st
parameter_list|,
name|ptr
parameter_list|)
value|SKM_sk_delete_ptr(SRTP_PROTECTION_PROFILE, (st), (ptr))
define|#
directive|define
name|sk_SRTP_PROTECTION_PROFILE_insert
parameter_list|(
name|st
parameter_list|,
name|val
parameter_list|,
name|i
parameter_list|)
value|SKM_sk_insert(SRTP_PROTECTION_PROFILE, (st), (val), (i))
define|#
directive|define
name|sk_SRTP_PROTECTION_PROFILE_set_cmp_func
parameter_list|(
name|st
parameter_list|,
name|cmp
parameter_list|)
value|SKM_sk_set_cmp_func(SRTP_PROTECTION_PROFILE, (st), (cmp))
define|#
directive|define
name|sk_SRTP_PROTECTION_PROFILE_dup
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_dup(SRTP_PROTECTION_PROFILE, st)
define|#
directive|define
name|sk_SRTP_PROTECTION_PROFILE_pop_free
parameter_list|(
name|st
parameter_list|,
name|free_func
parameter_list|)
value|SKM_sk_pop_free(SRTP_PROTECTION_PROFILE, (st), (free_func))
define|#
directive|define
name|sk_SRTP_PROTECTION_PROFILE_shift
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_shift(SRTP_PROTECTION_PROFILE, (st))
define|#
directive|define
name|sk_SRTP_PROTECTION_PROFILE_pop
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_pop(SRTP_PROTECTION_PROFILE, (st))
define|#
directive|define
name|sk_SRTP_PROTECTION_PROFILE_sort
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_sort(SRTP_PROTECTION_PROFILE, (st))
define|#
directive|define
name|sk_SRTP_PROTECTION_PROFILE_is_sorted
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_is_sorted(SRTP_PROTECTION_PROFILE, (st))
define|#
directive|define
name|sk_SSL_CIPHER_new
parameter_list|(
name|cmp
parameter_list|)
value|SKM_sk_new(SSL_CIPHER, (cmp))
define|#
directive|define
name|sk_SSL_CIPHER_new_null
parameter_list|()
value|SKM_sk_new_null(SSL_CIPHER)
define|#
directive|define
name|sk_SSL_CIPHER_free
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_free(SSL_CIPHER, (st))
define|#
directive|define
name|sk_SSL_CIPHER_num
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_num(SSL_CIPHER, (st))
define|#
directive|define
name|sk_SSL_CIPHER_value
parameter_list|(
name|st
parameter_list|,
name|i
parameter_list|)
value|SKM_sk_value(SSL_CIPHER, (st), (i))
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
define|#
directive|define
name|sk_SSL_CIPHER_zero
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_zero(SSL_CIPHER, (st))
define|#
directive|define
name|sk_SSL_CIPHER_push
parameter_list|(
name|st
parameter_list|,
name|val
parameter_list|)
value|SKM_sk_push(SSL_CIPHER, (st), (val))
define|#
directive|define
name|sk_SSL_CIPHER_unshift
parameter_list|(
name|st
parameter_list|,
name|val
parameter_list|)
value|SKM_sk_unshift(SSL_CIPHER, (st), (val))
define|#
directive|define
name|sk_SSL_CIPHER_find
parameter_list|(
name|st
parameter_list|,
name|val
parameter_list|)
value|SKM_sk_find(SSL_CIPHER, (st), (val))
define|#
directive|define
name|sk_SSL_CIPHER_find_ex
parameter_list|(
name|st
parameter_list|,
name|val
parameter_list|)
value|SKM_sk_find_ex(SSL_CIPHER, (st), (val))
define|#
directive|define
name|sk_SSL_CIPHER_delete
parameter_list|(
name|st
parameter_list|,
name|i
parameter_list|)
value|SKM_sk_delete(SSL_CIPHER, (st), (i))
define|#
directive|define
name|sk_SSL_CIPHER_delete_ptr
parameter_list|(
name|st
parameter_list|,
name|ptr
parameter_list|)
value|SKM_sk_delete_ptr(SSL_CIPHER, (st), (ptr))
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
define|#
directive|define
name|sk_SSL_CIPHER_set_cmp_func
parameter_list|(
name|st
parameter_list|,
name|cmp
parameter_list|)
value|SKM_sk_set_cmp_func(SSL_CIPHER, (st), (cmp))
define|#
directive|define
name|sk_SSL_CIPHER_dup
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_dup(SSL_CIPHER, st)
define|#
directive|define
name|sk_SSL_CIPHER_pop_free
parameter_list|(
name|st
parameter_list|,
name|free_func
parameter_list|)
value|SKM_sk_pop_free(SSL_CIPHER, (st), (free_func))
define|#
directive|define
name|sk_SSL_CIPHER_shift
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_shift(SSL_CIPHER, (st))
define|#
directive|define
name|sk_SSL_CIPHER_pop
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_pop(SSL_CIPHER, (st))
define|#
directive|define
name|sk_SSL_CIPHER_sort
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_sort(SSL_CIPHER, (st))
define|#
directive|define
name|sk_SSL_CIPHER_is_sorted
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_is_sorted(SSL_CIPHER, (st))
define|#
directive|define
name|sk_SSL_COMP_new
parameter_list|(
name|cmp
parameter_list|)
value|SKM_sk_new(SSL_COMP, (cmp))
define|#
directive|define
name|sk_SSL_COMP_new_null
parameter_list|()
value|SKM_sk_new_null(SSL_COMP)
define|#
directive|define
name|sk_SSL_COMP_free
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_free(SSL_COMP, (st))
define|#
directive|define
name|sk_SSL_COMP_num
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_num(SSL_COMP, (st))
define|#
directive|define
name|sk_SSL_COMP_value
parameter_list|(
name|st
parameter_list|,
name|i
parameter_list|)
value|SKM_sk_value(SSL_COMP, (st), (i))
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
define|#
directive|define
name|sk_SSL_COMP_zero
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_zero(SSL_COMP, (st))
define|#
directive|define
name|sk_SSL_COMP_push
parameter_list|(
name|st
parameter_list|,
name|val
parameter_list|)
value|SKM_sk_push(SSL_COMP, (st), (val))
define|#
directive|define
name|sk_SSL_COMP_unshift
parameter_list|(
name|st
parameter_list|,
name|val
parameter_list|)
value|SKM_sk_unshift(SSL_COMP, (st), (val))
define|#
directive|define
name|sk_SSL_COMP_find
parameter_list|(
name|st
parameter_list|,
name|val
parameter_list|)
value|SKM_sk_find(SSL_COMP, (st), (val))
define|#
directive|define
name|sk_SSL_COMP_find_ex
parameter_list|(
name|st
parameter_list|,
name|val
parameter_list|)
value|SKM_sk_find_ex(SSL_COMP, (st), (val))
define|#
directive|define
name|sk_SSL_COMP_delete
parameter_list|(
name|st
parameter_list|,
name|i
parameter_list|)
value|SKM_sk_delete(SSL_COMP, (st), (i))
define|#
directive|define
name|sk_SSL_COMP_delete_ptr
parameter_list|(
name|st
parameter_list|,
name|ptr
parameter_list|)
value|SKM_sk_delete_ptr(SSL_COMP, (st), (ptr))
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
define|#
directive|define
name|sk_SSL_COMP_set_cmp_func
parameter_list|(
name|st
parameter_list|,
name|cmp
parameter_list|)
value|SKM_sk_set_cmp_func(SSL_COMP, (st), (cmp))
define|#
directive|define
name|sk_SSL_COMP_dup
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_dup(SSL_COMP, st)
define|#
directive|define
name|sk_SSL_COMP_pop_free
parameter_list|(
name|st
parameter_list|,
name|free_func
parameter_list|)
value|SKM_sk_pop_free(SSL_COMP, (st), (free_func))
define|#
directive|define
name|sk_SSL_COMP_shift
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_shift(SSL_COMP, (st))
define|#
directive|define
name|sk_SSL_COMP_pop
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_pop(SSL_COMP, (st))
define|#
directive|define
name|sk_SSL_COMP_sort
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_sort(SSL_COMP, (st))
define|#
directive|define
name|sk_SSL_COMP_is_sorted
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_is_sorted(SSL_COMP, (st))
define|#
directive|define
name|sk_STACK_OF_X509_NAME_ENTRY_new
parameter_list|(
name|cmp
parameter_list|)
value|SKM_sk_new(STACK_OF_X509_NAME_ENTRY, (cmp))
define|#
directive|define
name|sk_STACK_OF_X509_NAME_ENTRY_new_null
parameter_list|()
value|SKM_sk_new_null(STACK_OF_X509_NAME_ENTRY)
define|#
directive|define
name|sk_STACK_OF_X509_NAME_ENTRY_free
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_free(STACK_OF_X509_NAME_ENTRY, (st))
define|#
directive|define
name|sk_STACK_OF_X509_NAME_ENTRY_num
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_num(STACK_OF_X509_NAME_ENTRY, (st))
define|#
directive|define
name|sk_STACK_OF_X509_NAME_ENTRY_value
parameter_list|(
name|st
parameter_list|,
name|i
parameter_list|)
value|SKM_sk_value(STACK_OF_X509_NAME_ENTRY, (st), (i))
define|#
directive|define
name|sk_STACK_OF_X509_NAME_ENTRY_set
parameter_list|(
name|st
parameter_list|,
name|i
parameter_list|,
name|val
parameter_list|)
value|SKM_sk_set(STACK_OF_X509_NAME_ENTRY, (st), (i), (val))
define|#
directive|define
name|sk_STACK_OF_X509_NAME_ENTRY_zero
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_zero(STACK_OF_X509_NAME_ENTRY, (st))
define|#
directive|define
name|sk_STACK_OF_X509_NAME_ENTRY_push
parameter_list|(
name|st
parameter_list|,
name|val
parameter_list|)
value|SKM_sk_push(STACK_OF_X509_NAME_ENTRY, (st), (val))
define|#
directive|define
name|sk_STACK_OF_X509_NAME_ENTRY_unshift
parameter_list|(
name|st
parameter_list|,
name|val
parameter_list|)
value|SKM_sk_unshift(STACK_OF_X509_NAME_ENTRY, (st), (val))
define|#
directive|define
name|sk_STACK_OF_X509_NAME_ENTRY_find
parameter_list|(
name|st
parameter_list|,
name|val
parameter_list|)
value|SKM_sk_find(STACK_OF_X509_NAME_ENTRY, (st), (val))
define|#
directive|define
name|sk_STACK_OF_X509_NAME_ENTRY_find_ex
parameter_list|(
name|st
parameter_list|,
name|val
parameter_list|)
value|SKM_sk_find_ex(STACK_OF_X509_NAME_ENTRY, (st), (val))
define|#
directive|define
name|sk_STACK_OF_X509_NAME_ENTRY_delete
parameter_list|(
name|st
parameter_list|,
name|i
parameter_list|)
value|SKM_sk_delete(STACK_OF_X509_NAME_ENTRY, (st), (i))
define|#
directive|define
name|sk_STACK_OF_X509_NAME_ENTRY_delete_ptr
parameter_list|(
name|st
parameter_list|,
name|ptr
parameter_list|)
value|SKM_sk_delete_ptr(STACK_OF_X509_NAME_ENTRY, (st), (ptr))
define|#
directive|define
name|sk_STACK_OF_X509_NAME_ENTRY_insert
parameter_list|(
name|st
parameter_list|,
name|val
parameter_list|,
name|i
parameter_list|)
value|SKM_sk_insert(STACK_OF_X509_NAME_ENTRY, (st), (val), (i))
define|#
directive|define
name|sk_STACK_OF_X509_NAME_ENTRY_set_cmp_func
parameter_list|(
name|st
parameter_list|,
name|cmp
parameter_list|)
value|SKM_sk_set_cmp_func(STACK_OF_X509_NAME_ENTRY, (st), (cmp))
define|#
directive|define
name|sk_STACK_OF_X509_NAME_ENTRY_dup
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_dup(STACK_OF_X509_NAME_ENTRY, st)
define|#
directive|define
name|sk_STACK_OF_X509_NAME_ENTRY_pop_free
parameter_list|(
name|st
parameter_list|,
name|free_func
parameter_list|)
value|SKM_sk_pop_free(STACK_OF_X509_NAME_ENTRY, (st), (free_func))
define|#
directive|define
name|sk_STACK_OF_X509_NAME_ENTRY_shift
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_shift(STACK_OF_X509_NAME_ENTRY, (st))
define|#
directive|define
name|sk_STACK_OF_X509_NAME_ENTRY_pop
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_pop(STACK_OF_X509_NAME_ENTRY, (st))
define|#
directive|define
name|sk_STACK_OF_X509_NAME_ENTRY_sort
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_sort(STACK_OF_X509_NAME_ENTRY, (st))
define|#
directive|define
name|sk_STACK_OF_X509_NAME_ENTRY_is_sorted
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_is_sorted(STACK_OF_X509_NAME_ENTRY, (st))
define|#
directive|define
name|sk_STORE_ATTR_INFO_new
parameter_list|(
name|cmp
parameter_list|)
value|SKM_sk_new(STORE_ATTR_INFO, (cmp))
define|#
directive|define
name|sk_STORE_ATTR_INFO_new_null
parameter_list|()
value|SKM_sk_new_null(STORE_ATTR_INFO)
define|#
directive|define
name|sk_STORE_ATTR_INFO_free
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_free(STORE_ATTR_INFO, (st))
define|#
directive|define
name|sk_STORE_ATTR_INFO_num
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_num(STORE_ATTR_INFO, (st))
define|#
directive|define
name|sk_STORE_ATTR_INFO_value
parameter_list|(
name|st
parameter_list|,
name|i
parameter_list|)
value|SKM_sk_value(STORE_ATTR_INFO, (st), (i))
define|#
directive|define
name|sk_STORE_ATTR_INFO_set
parameter_list|(
name|st
parameter_list|,
name|i
parameter_list|,
name|val
parameter_list|)
value|SKM_sk_set(STORE_ATTR_INFO, (st), (i), (val))
define|#
directive|define
name|sk_STORE_ATTR_INFO_zero
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_zero(STORE_ATTR_INFO, (st))
define|#
directive|define
name|sk_STORE_ATTR_INFO_push
parameter_list|(
name|st
parameter_list|,
name|val
parameter_list|)
value|SKM_sk_push(STORE_ATTR_INFO, (st), (val))
define|#
directive|define
name|sk_STORE_ATTR_INFO_unshift
parameter_list|(
name|st
parameter_list|,
name|val
parameter_list|)
value|SKM_sk_unshift(STORE_ATTR_INFO, (st), (val))
define|#
directive|define
name|sk_STORE_ATTR_INFO_find
parameter_list|(
name|st
parameter_list|,
name|val
parameter_list|)
value|SKM_sk_find(STORE_ATTR_INFO, (st), (val))
define|#
directive|define
name|sk_STORE_ATTR_INFO_find_ex
parameter_list|(
name|st
parameter_list|,
name|val
parameter_list|)
value|SKM_sk_find_ex(STORE_ATTR_INFO, (st), (val))
define|#
directive|define
name|sk_STORE_ATTR_INFO_delete
parameter_list|(
name|st
parameter_list|,
name|i
parameter_list|)
value|SKM_sk_delete(STORE_ATTR_INFO, (st), (i))
define|#
directive|define
name|sk_STORE_ATTR_INFO_delete_ptr
parameter_list|(
name|st
parameter_list|,
name|ptr
parameter_list|)
value|SKM_sk_delete_ptr(STORE_ATTR_INFO, (st), (ptr))
define|#
directive|define
name|sk_STORE_ATTR_INFO_insert
parameter_list|(
name|st
parameter_list|,
name|val
parameter_list|,
name|i
parameter_list|)
value|SKM_sk_insert(STORE_ATTR_INFO, (st), (val), (i))
define|#
directive|define
name|sk_STORE_ATTR_INFO_set_cmp_func
parameter_list|(
name|st
parameter_list|,
name|cmp
parameter_list|)
value|SKM_sk_set_cmp_func(STORE_ATTR_INFO, (st), (cmp))
define|#
directive|define
name|sk_STORE_ATTR_INFO_dup
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_dup(STORE_ATTR_INFO, st)
define|#
directive|define
name|sk_STORE_ATTR_INFO_pop_free
parameter_list|(
name|st
parameter_list|,
name|free_func
parameter_list|)
value|SKM_sk_pop_free(STORE_ATTR_INFO, (st), (free_func))
define|#
directive|define
name|sk_STORE_ATTR_INFO_shift
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_shift(STORE_ATTR_INFO, (st))
define|#
directive|define
name|sk_STORE_ATTR_INFO_pop
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_pop(STORE_ATTR_INFO, (st))
define|#
directive|define
name|sk_STORE_ATTR_INFO_sort
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_sort(STORE_ATTR_INFO, (st))
define|#
directive|define
name|sk_STORE_ATTR_INFO_is_sorted
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_is_sorted(STORE_ATTR_INFO, (st))
define|#
directive|define
name|sk_STORE_OBJECT_new
parameter_list|(
name|cmp
parameter_list|)
value|SKM_sk_new(STORE_OBJECT, (cmp))
define|#
directive|define
name|sk_STORE_OBJECT_new_null
parameter_list|()
value|SKM_sk_new_null(STORE_OBJECT)
define|#
directive|define
name|sk_STORE_OBJECT_free
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_free(STORE_OBJECT, (st))
define|#
directive|define
name|sk_STORE_OBJECT_num
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_num(STORE_OBJECT, (st))
define|#
directive|define
name|sk_STORE_OBJECT_value
parameter_list|(
name|st
parameter_list|,
name|i
parameter_list|)
value|SKM_sk_value(STORE_OBJECT, (st), (i))
define|#
directive|define
name|sk_STORE_OBJECT_set
parameter_list|(
name|st
parameter_list|,
name|i
parameter_list|,
name|val
parameter_list|)
value|SKM_sk_set(STORE_OBJECT, (st), (i), (val))
define|#
directive|define
name|sk_STORE_OBJECT_zero
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_zero(STORE_OBJECT, (st))
define|#
directive|define
name|sk_STORE_OBJECT_push
parameter_list|(
name|st
parameter_list|,
name|val
parameter_list|)
value|SKM_sk_push(STORE_OBJECT, (st), (val))
define|#
directive|define
name|sk_STORE_OBJECT_unshift
parameter_list|(
name|st
parameter_list|,
name|val
parameter_list|)
value|SKM_sk_unshift(STORE_OBJECT, (st), (val))
define|#
directive|define
name|sk_STORE_OBJECT_find
parameter_list|(
name|st
parameter_list|,
name|val
parameter_list|)
value|SKM_sk_find(STORE_OBJECT, (st), (val))
define|#
directive|define
name|sk_STORE_OBJECT_find_ex
parameter_list|(
name|st
parameter_list|,
name|val
parameter_list|)
value|SKM_sk_find_ex(STORE_OBJECT, (st), (val))
define|#
directive|define
name|sk_STORE_OBJECT_delete
parameter_list|(
name|st
parameter_list|,
name|i
parameter_list|)
value|SKM_sk_delete(STORE_OBJECT, (st), (i))
define|#
directive|define
name|sk_STORE_OBJECT_delete_ptr
parameter_list|(
name|st
parameter_list|,
name|ptr
parameter_list|)
value|SKM_sk_delete_ptr(STORE_OBJECT, (st), (ptr))
define|#
directive|define
name|sk_STORE_OBJECT_insert
parameter_list|(
name|st
parameter_list|,
name|val
parameter_list|,
name|i
parameter_list|)
value|SKM_sk_insert(STORE_OBJECT, (st), (val), (i))
define|#
directive|define
name|sk_STORE_OBJECT_set_cmp_func
parameter_list|(
name|st
parameter_list|,
name|cmp
parameter_list|)
value|SKM_sk_set_cmp_func(STORE_OBJECT, (st), (cmp))
define|#
directive|define
name|sk_STORE_OBJECT_dup
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_dup(STORE_OBJECT, st)
define|#
directive|define
name|sk_STORE_OBJECT_pop_free
parameter_list|(
name|st
parameter_list|,
name|free_func
parameter_list|)
value|SKM_sk_pop_free(STORE_OBJECT, (st), (free_func))
define|#
directive|define
name|sk_STORE_OBJECT_shift
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_shift(STORE_OBJECT, (st))
define|#
directive|define
name|sk_STORE_OBJECT_pop
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_pop(STORE_OBJECT, (st))
define|#
directive|define
name|sk_STORE_OBJECT_sort
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_sort(STORE_OBJECT, (st))
define|#
directive|define
name|sk_STORE_OBJECT_is_sorted
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_is_sorted(STORE_OBJECT, (st))
define|#
directive|define
name|sk_SXNETID_new
parameter_list|(
name|cmp
parameter_list|)
value|SKM_sk_new(SXNETID, (cmp))
define|#
directive|define
name|sk_SXNETID_new_null
parameter_list|()
value|SKM_sk_new_null(SXNETID)
define|#
directive|define
name|sk_SXNETID_free
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_free(SXNETID, (st))
define|#
directive|define
name|sk_SXNETID_num
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_num(SXNETID, (st))
define|#
directive|define
name|sk_SXNETID_value
parameter_list|(
name|st
parameter_list|,
name|i
parameter_list|)
value|SKM_sk_value(SXNETID, (st), (i))
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
define|#
directive|define
name|sk_SXNETID_zero
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_zero(SXNETID, (st))
define|#
directive|define
name|sk_SXNETID_push
parameter_list|(
name|st
parameter_list|,
name|val
parameter_list|)
value|SKM_sk_push(SXNETID, (st), (val))
define|#
directive|define
name|sk_SXNETID_unshift
parameter_list|(
name|st
parameter_list|,
name|val
parameter_list|)
value|SKM_sk_unshift(SXNETID, (st), (val))
define|#
directive|define
name|sk_SXNETID_find
parameter_list|(
name|st
parameter_list|,
name|val
parameter_list|)
value|SKM_sk_find(SXNETID, (st), (val))
define|#
directive|define
name|sk_SXNETID_find_ex
parameter_list|(
name|st
parameter_list|,
name|val
parameter_list|)
value|SKM_sk_find_ex(SXNETID, (st), (val))
define|#
directive|define
name|sk_SXNETID_delete
parameter_list|(
name|st
parameter_list|,
name|i
parameter_list|)
value|SKM_sk_delete(SXNETID, (st), (i))
define|#
directive|define
name|sk_SXNETID_delete_ptr
parameter_list|(
name|st
parameter_list|,
name|ptr
parameter_list|)
value|SKM_sk_delete_ptr(SXNETID, (st), (ptr))
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
define|#
directive|define
name|sk_SXNETID_set_cmp_func
parameter_list|(
name|st
parameter_list|,
name|cmp
parameter_list|)
value|SKM_sk_set_cmp_func(SXNETID, (st), (cmp))
define|#
directive|define
name|sk_SXNETID_dup
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_dup(SXNETID, st)
define|#
directive|define
name|sk_SXNETID_pop_free
parameter_list|(
name|st
parameter_list|,
name|free_func
parameter_list|)
value|SKM_sk_pop_free(SXNETID, (st), (free_func))
define|#
directive|define
name|sk_SXNETID_shift
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_shift(SXNETID, (st))
define|#
directive|define
name|sk_SXNETID_pop
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_pop(SXNETID, (st))
define|#
directive|define
name|sk_SXNETID_sort
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_sort(SXNETID, (st))
define|#
directive|define
name|sk_SXNETID_is_sorted
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_is_sorted(SXNETID, (st))
define|#
directive|define
name|sk_UI_STRING_new
parameter_list|(
name|cmp
parameter_list|)
value|SKM_sk_new(UI_STRING, (cmp))
define|#
directive|define
name|sk_UI_STRING_new_null
parameter_list|()
value|SKM_sk_new_null(UI_STRING)
define|#
directive|define
name|sk_UI_STRING_free
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_free(UI_STRING, (st))
define|#
directive|define
name|sk_UI_STRING_num
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_num(UI_STRING, (st))
define|#
directive|define
name|sk_UI_STRING_value
parameter_list|(
name|st
parameter_list|,
name|i
parameter_list|)
value|SKM_sk_value(UI_STRING, (st), (i))
define|#
directive|define
name|sk_UI_STRING_set
parameter_list|(
name|st
parameter_list|,
name|i
parameter_list|,
name|val
parameter_list|)
value|SKM_sk_set(UI_STRING, (st), (i), (val))
define|#
directive|define
name|sk_UI_STRING_zero
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_zero(UI_STRING, (st))
define|#
directive|define
name|sk_UI_STRING_push
parameter_list|(
name|st
parameter_list|,
name|val
parameter_list|)
value|SKM_sk_push(UI_STRING, (st), (val))
define|#
directive|define
name|sk_UI_STRING_unshift
parameter_list|(
name|st
parameter_list|,
name|val
parameter_list|)
value|SKM_sk_unshift(UI_STRING, (st), (val))
define|#
directive|define
name|sk_UI_STRING_find
parameter_list|(
name|st
parameter_list|,
name|val
parameter_list|)
value|SKM_sk_find(UI_STRING, (st), (val))
define|#
directive|define
name|sk_UI_STRING_find_ex
parameter_list|(
name|st
parameter_list|,
name|val
parameter_list|)
value|SKM_sk_find_ex(UI_STRING, (st), (val))
define|#
directive|define
name|sk_UI_STRING_delete
parameter_list|(
name|st
parameter_list|,
name|i
parameter_list|)
value|SKM_sk_delete(UI_STRING, (st), (i))
define|#
directive|define
name|sk_UI_STRING_delete_ptr
parameter_list|(
name|st
parameter_list|,
name|ptr
parameter_list|)
value|SKM_sk_delete_ptr(UI_STRING, (st), (ptr))
define|#
directive|define
name|sk_UI_STRING_insert
parameter_list|(
name|st
parameter_list|,
name|val
parameter_list|,
name|i
parameter_list|)
value|SKM_sk_insert(UI_STRING, (st), (val), (i))
define|#
directive|define
name|sk_UI_STRING_set_cmp_func
parameter_list|(
name|st
parameter_list|,
name|cmp
parameter_list|)
value|SKM_sk_set_cmp_func(UI_STRING, (st), (cmp))
define|#
directive|define
name|sk_UI_STRING_dup
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_dup(UI_STRING, st)
define|#
directive|define
name|sk_UI_STRING_pop_free
parameter_list|(
name|st
parameter_list|,
name|free_func
parameter_list|)
value|SKM_sk_pop_free(UI_STRING, (st), (free_func))
define|#
directive|define
name|sk_UI_STRING_shift
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_shift(UI_STRING, (st))
define|#
directive|define
name|sk_UI_STRING_pop
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_pop(UI_STRING, (st))
define|#
directive|define
name|sk_UI_STRING_sort
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_sort(UI_STRING, (st))
define|#
directive|define
name|sk_UI_STRING_is_sorted
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_is_sorted(UI_STRING, (st))
define|#
directive|define
name|sk_X509_new
parameter_list|(
name|cmp
parameter_list|)
value|SKM_sk_new(X509, (cmp))
define|#
directive|define
name|sk_X509_new_null
parameter_list|()
value|SKM_sk_new_null(X509)
define|#
directive|define
name|sk_X509_free
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_free(X509, (st))
define|#
directive|define
name|sk_X509_num
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_num(X509, (st))
define|#
directive|define
name|sk_X509_value
parameter_list|(
name|st
parameter_list|,
name|i
parameter_list|)
value|SKM_sk_value(X509, (st), (i))
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
define|#
directive|define
name|sk_X509_zero
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_zero(X509, (st))
define|#
directive|define
name|sk_X509_push
parameter_list|(
name|st
parameter_list|,
name|val
parameter_list|)
value|SKM_sk_push(X509, (st), (val))
define|#
directive|define
name|sk_X509_unshift
parameter_list|(
name|st
parameter_list|,
name|val
parameter_list|)
value|SKM_sk_unshift(X509, (st), (val))
define|#
directive|define
name|sk_X509_find
parameter_list|(
name|st
parameter_list|,
name|val
parameter_list|)
value|SKM_sk_find(X509, (st), (val))
define|#
directive|define
name|sk_X509_find_ex
parameter_list|(
name|st
parameter_list|,
name|val
parameter_list|)
value|SKM_sk_find_ex(X509, (st), (val))
define|#
directive|define
name|sk_X509_delete
parameter_list|(
name|st
parameter_list|,
name|i
parameter_list|)
value|SKM_sk_delete(X509, (st), (i))
define|#
directive|define
name|sk_X509_delete_ptr
parameter_list|(
name|st
parameter_list|,
name|ptr
parameter_list|)
value|SKM_sk_delete_ptr(X509, (st), (ptr))
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
define|#
directive|define
name|sk_X509_set_cmp_func
parameter_list|(
name|st
parameter_list|,
name|cmp
parameter_list|)
value|SKM_sk_set_cmp_func(X509, (st), (cmp))
define|#
directive|define
name|sk_X509_dup
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_dup(X509, st)
define|#
directive|define
name|sk_X509_pop_free
parameter_list|(
name|st
parameter_list|,
name|free_func
parameter_list|)
value|SKM_sk_pop_free(X509, (st), (free_func))
define|#
directive|define
name|sk_X509_shift
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_shift(X509, (st))
define|#
directive|define
name|sk_X509_pop
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_pop(X509, (st))
define|#
directive|define
name|sk_X509_sort
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_sort(X509, (st))
define|#
directive|define
name|sk_X509_is_sorted
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_is_sorted(X509, (st))
define|#
directive|define
name|sk_X509V3_EXT_METHOD_new
parameter_list|(
name|cmp
parameter_list|)
value|SKM_sk_new(X509V3_EXT_METHOD, (cmp))
define|#
directive|define
name|sk_X509V3_EXT_METHOD_new_null
parameter_list|()
value|SKM_sk_new_null(X509V3_EXT_METHOD)
define|#
directive|define
name|sk_X509V3_EXT_METHOD_free
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_free(X509V3_EXT_METHOD, (st))
define|#
directive|define
name|sk_X509V3_EXT_METHOD_num
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_num(X509V3_EXT_METHOD, (st))
define|#
directive|define
name|sk_X509V3_EXT_METHOD_value
parameter_list|(
name|st
parameter_list|,
name|i
parameter_list|)
value|SKM_sk_value(X509V3_EXT_METHOD, (st), (i))
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
define|#
directive|define
name|sk_X509V3_EXT_METHOD_zero
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_zero(X509V3_EXT_METHOD, (st))
define|#
directive|define
name|sk_X509V3_EXT_METHOD_push
parameter_list|(
name|st
parameter_list|,
name|val
parameter_list|)
value|SKM_sk_push(X509V3_EXT_METHOD, (st), (val))
define|#
directive|define
name|sk_X509V3_EXT_METHOD_unshift
parameter_list|(
name|st
parameter_list|,
name|val
parameter_list|)
value|SKM_sk_unshift(X509V3_EXT_METHOD, (st), (val))
define|#
directive|define
name|sk_X509V3_EXT_METHOD_find
parameter_list|(
name|st
parameter_list|,
name|val
parameter_list|)
value|SKM_sk_find(X509V3_EXT_METHOD, (st), (val))
define|#
directive|define
name|sk_X509V3_EXT_METHOD_find_ex
parameter_list|(
name|st
parameter_list|,
name|val
parameter_list|)
value|SKM_sk_find_ex(X509V3_EXT_METHOD, (st), (val))
define|#
directive|define
name|sk_X509V3_EXT_METHOD_delete
parameter_list|(
name|st
parameter_list|,
name|i
parameter_list|)
value|SKM_sk_delete(X509V3_EXT_METHOD, (st), (i))
define|#
directive|define
name|sk_X509V3_EXT_METHOD_delete_ptr
parameter_list|(
name|st
parameter_list|,
name|ptr
parameter_list|)
value|SKM_sk_delete_ptr(X509V3_EXT_METHOD, (st), (ptr))
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
define|#
directive|define
name|sk_X509V3_EXT_METHOD_set_cmp_func
parameter_list|(
name|st
parameter_list|,
name|cmp
parameter_list|)
value|SKM_sk_set_cmp_func(X509V3_EXT_METHOD, (st), (cmp))
define|#
directive|define
name|sk_X509V3_EXT_METHOD_dup
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_dup(X509V3_EXT_METHOD, st)
define|#
directive|define
name|sk_X509V3_EXT_METHOD_pop_free
parameter_list|(
name|st
parameter_list|,
name|free_func
parameter_list|)
value|SKM_sk_pop_free(X509V3_EXT_METHOD, (st), (free_func))
define|#
directive|define
name|sk_X509V3_EXT_METHOD_shift
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_shift(X509V3_EXT_METHOD, (st))
define|#
directive|define
name|sk_X509V3_EXT_METHOD_pop
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_pop(X509V3_EXT_METHOD, (st))
define|#
directive|define
name|sk_X509V3_EXT_METHOD_sort
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_sort(X509V3_EXT_METHOD, (st))
define|#
directive|define
name|sk_X509V3_EXT_METHOD_is_sorted
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_is_sorted(X509V3_EXT_METHOD, (st))
define|#
directive|define
name|sk_X509_ALGOR_new
parameter_list|(
name|cmp
parameter_list|)
value|SKM_sk_new(X509_ALGOR, (cmp))
define|#
directive|define
name|sk_X509_ALGOR_new_null
parameter_list|()
value|SKM_sk_new_null(X509_ALGOR)
define|#
directive|define
name|sk_X509_ALGOR_free
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_free(X509_ALGOR, (st))
define|#
directive|define
name|sk_X509_ALGOR_num
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_num(X509_ALGOR, (st))
define|#
directive|define
name|sk_X509_ALGOR_value
parameter_list|(
name|st
parameter_list|,
name|i
parameter_list|)
value|SKM_sk_value(X509_ALGOR, (st), (i))
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
define|#
directive|define
name|sk_X509_ALGOR_zero
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_zero(X509_ALGOR, (st))
define|#
directive|define
name|sk_X509_ALGOR_push
parameter_list|(
name|st
parameter_list|,
name|val
parameter_list|)
value|SKM_sk_push(X509_ALGOR, (st), (val))
define|#
directive|define
name|sk_X509_ALGOR_unshift
parameter_list|(
name|st
parameter_list|,
name|val
parameter_list|)
value|SKM_sk_unshift(X509_ALGOR, (st), (val))
define|#
directive|define
name|sk_X509_ALGOR_find
parameter_list|(
name|st
parameter_list|,
name|val
parameter_list|)
value|SKM_sk_find(X509_ALGOR, (st), (val))
define|#
directive|define
name|sk_X509_ALGOR_find_ex
parameter_list|(
name|st
parameter_list|,
name|val
parameter_list|)
value|SKM_sk_find_ex(X509_ALGOR, (st), (val))
define|#
directive|define
name|sk_X509_ALGOR_delete
parameter_list|(
name|st
parameter_list|,
name|i
parameter_list|)
value|SKM_sk_delete(X509_ALGOR, (st), (i))
define|#
directive|define
name|sk_X509_ALGOR_delete_ptr
parameter_list|(
name|st
parameter_list|,
name|ptr
parameter_list|)
value|SKM_sk_delete_ptr(X509_ALGOR, (st), (ptr))
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
define|#
directive|define
name|sk_X509_ALGOR_set_cmp_func
parameter_list|(
name|st
parameter_list|,
name|cmp
parameter_list|)
value|SKM_sk_set_cmp_func(X509_ALGOR, (st), (cmp))
define|#
directive|define
name|sk_X509_ALGOR_dup
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_dup(X509_ALGOR, st)
define|#
directive|define
name|sk_X509_ALGOR_pop_free
parameter_list|(
name|st
parameter_list|,
name|free_func
parameter_list|)
value|SKM_sk_pop_free(X509_ALGOR, (st), (free_func))
define|#
directive|define
name|sk_X509_ALGOR_shift
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_shift(X509_ALGOR, (st))
define|#
directive|define
name|sk_X509_ALGOR_pop
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_pop(X509_ALGOR, (st))
define|#
directive|define
name|sk_X509_ALGOR_sort
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_sort(X509_ALGOR, (st))
define|#
directive|define
name|sk_X509_ALGOR_is_sorted
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_is_sorted(X509_ALGOR, (st))
define|#
directive|define
name|sk_X509_ATTRIBUTE_new
parameter_list|(
name|cmp
parameter_list|)
value|SKM_sk_new(X509_ATTRIBUTE, (cmp))
define|#
directive|define
name|sk_X509_ATTRIBUTE_new_null
parameter_list|()
value|SKM_sk_new_null(X509_ATTRIBUTE)
define|#
directive|define
name|sk_X509_ATTRIBUTE_free
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_free(X509_ATTRIBUTE, (st))
define|#
directive|define
name|sk_X509_ATTRIBUTE_num
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_num(X509_ATTRIBUTE, (st))
define|#
directive|define
name|sk_X509_ATTRIBUTE_value
parameter_list|(
name|st
parameter_list|,
name|i
parameter_list|)
value|SKM_sk_value(X509_ATTRIBUTE, (st), (i))
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
define|#
directive|define
name|sk_X509_ATTRIBUTE_zero
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_zero(X509_ATTRIBUTE, (st))
define|#
directive|define
name|sk_X509_ATTRIBUTE_push
parameter_list|(
name|st
parameter_list|,
name|val
parameter_list|)
value|SKM_sk_push(X509_ATTRIBUTE, (st), (val))
define|#
directive|define
name|sk_X509_ATTRIBUTE_unshift
parameter_list|(
name|st
parameter_list|,
name|val
parameter_list|)
value|SKM_sk_unshift(X509_ATTRIBUTE, (st), (val))
define|#
directive|define
name|sk_X509_ATTRIBUTE_find
parameter_list|(
name|st
parameter_list|,
name|val
parameter_list|)
value|SKM_sk_find(X509_ATTRIBUTE, (st), (val))
define|#
directive|define
name|sk_X509_ATTRIBUTE_find_ex
parameter_list|(
name|st
parameter_list|,
name|val
parameter_list|)
value|SKM_sk_find_ex(X509_ATTRIBUTE, (st), (val))
define|#
directive|define
name|sk_X509_ATTRIBUTE_delete
parameter_list|(
name|st
parameter_list|,
name|i
parameter_list|)
value|SKM_sk_delete(X509_ATTRIBUTE, (st), (i))
define|#
directive|define
name|sk_X509_ATTRIBUTE_delete_ptr
parameter_list|(
name|st
parameter_list|,
name|ptr
parameter_list|)
value|SKM_sk_delete_ptr(X509_ATTRIBUTE, (st), (ptr))
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
define|#
directive|define
name|sk_X509_ATTRIBUTE_set_cmp_func
parameter_list|(
name|st
parameter_list|,
name|cmp
parameter_list|)
value|SKM_sk_set_cmp_func(X509_ATTRIBUTE, (st), (cmp))
define|#
directive|define
name|sk_X509_ATTRIBUTE_dup
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_dup(X509_ATTRIBUTE, st)
define|#
directive|define
name|sk_X509_ATTRIBUTE_pop_free
parameter_list|(
name|st
parameter_list|,
name|free_func
parameter_list|)
value|SKM_sk_pop_free(X509_ATTRIBUTE, (st), (free_func))
define|#
directive|define
name|sk_X509_ATTRIBUTE_shift
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_shift(X509_ATTRIBUTE, (st))
define|#
directive|define
name|sk_X509_ATTRIBUTE_pop
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_pop(X509_ATTRIBUTE, (st))
define|#
directive|define
name|sk_X509_ATTRIBUTE_sort
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_sort(X509_ATTRIBUTE, (st))
define|#
directive|define
name|sk_X509_ATTRIBUTE_is_sorted
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_is_sorted(X509_ATTRIBUTE, (st))
define|#
directive|define
name|sk_X509_CRL_new
parameter_list|(
name|cmp
parameter_list|)
value|SKM_sk_new(X509_CRL, (cmp))
define|#
directive|define
name|sk_X509_CRL_new_null
parameter_list|()
value|SKM_sk_new_null(X509_CRL)
define|#
directive|define
name|sk_X509_CRL_free
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_free(X509_CRL, (st))
define|#
directive|define
name|sk_X509_CRL_num
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_num(X509_CRL, (st))
define|#
directive|define
name|sk_X509_CRL_value
parameter_list|(
name|st
parameter_list|,
name|i
parameter_list|)
value|SKM_sk_value(X509_CRL, (st), (i))
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
define|#
directive|define
name|sk_X509_CRL_zero
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_zero(X509_CRL, (st))
define|#
directive|define
name|sk_X509_CRL_push
parameter_list|(
name|st
parameter_list|,
name|val
parameter_list|)
value|SKM_sk_push(X509_CRL, (st), (val))
define|#
directive|define
name|sk_X509_CRL_unshift
parameter_list|(
name|st
parameter_list|,
name|val
parameter_list|)
value|SKM_sk_unshift(X509_CRL, (st), (val))
define|#
directive|define
name|sk_X509_CRL_find
parameter_list|(
name|st
parameter_list|,
name|val
parameter_list|)
value|SKM_sk_find(X509_CRL, (st), (val))
define|#
directive|define
name|sk_X509_CRL_find_ex
parameter_list|(
name|st
parameter_list|,
name|val
parameter_list|)
value|SKM_sk_find_ex(X509_CRL, (st), (val))
define|#
directive|define
name|sk_X509_CRL_delete
parameter_list|(
name|st
parameter_list|,
name|i
parameter_list|)
value|SKM_sk_delete(X509_CRL, (st), (i))
define|#
directive|define
name|sk_X509_CRL_delete_ptr
parameter_list|(
name|st
parameter_list|,
name|ptr
parameter_list|)
value|SKM_sk_delete_ptr(X509_CRL, (st), (ptr))
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
define|#
directive|define
name|sk_X509_CRL_set_cmp_func
parameter_list|(
name|st
parameter_list|,
name|cmp
parameter_list|)
value|SKM_sk_set_cmp_func(X509_CRL, (st), (cmp))
define|#
directive|define
name|sk_X509_CRL_dup
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_dup(X509_CRL, st)
define|#
directive|define
name|sk_X509_CRL_pop_free
parameter_list|(
name|st
parameter_list|,
name|free_func
parameter_list|)
value|SKM_sk_pop_free(X509_CRL, (st), (free_func))
define|#
directive|define
name|sk_X509_CRL_shift
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_shift(X509_CRL, (st))
define|#
directive|define
name|sk_X509_CRL_pop
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_pop(X509_CRL, (st))
define|#
directive|define
name|sk_X509_CRL_sort
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_sort(X509_CRL, (st))
define|#
directive|define
name|sk_X509_CRL_is_sorted
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_is_sorted(X509_CRL, (st))
define|#
directive|define
name|sk_X509_EXTENSION_new
parameter_list|(
name|cmp
parameter_list|)
value|SKM_sk_new(X509_EXTENSION, (cmp))
define|#
directive|define
name|sk_X509_EXTENSION_new_null
parameter_list|()
value|SKM_sk_new_null(X509_EXTENSION)
define|#
directive|define
name|sk_X509_EXTENSION_free
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_free(X509_EXTENSION, (st))
define|#
directive|define
name|sk_X509_EXTENSION_num
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_num(X509_EXTENSION, (st))
define|#
directive|define
name|sk_X509_EXTENSION_value
parameter_list|(
name|st
parameter_list|,
name|i
parameter_list|)
value|SKM_sk_value(X509_EXTENSION, (st), (i))
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
define|#
directive|define
name|sk_X509_EXTENSION_zero
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_zero(X509_EXTENSION, (st))
define|#
directive|define
name|sk_X509_EXTENSION_push
parameter_list|(
name|st
parameter_list|,
name|val
parameter_list|)
value|SKM_sk_push(X509_EXTENSION, (st), (val))
define|#
directive|define
name|sk_X509_EXTENSION_unshift
parameter_list|(
name|st
parameter_list|,
name|val
parameter_list|)
value|SKM_sk_unshift(X509_EXTENSION, (st), (val))
define|#
directive|define
name|sk_X509_EXTENSION_find
parameter_list|(
name|st
parameter_list|,
name|val
parameter_list|)
value|SKM_sk_find(X509_EXTENSION, (st), (val))
define|#
directive|define
name|sk_X509_EXTENSION_find_ex
parameter_list|(
name|st
parameter_list|,
name|val
parameter_list|)
value|SKM_sk_find_ex(X509_EXTENSION, (st), (val))
define|#
directive|define
name|sk_X509_EXTENSION_delete
parameter_list|(
name|st
parameter_list|,
name|i
parameter_list|)
value|SKM_sk_delete(X509_EXTENSION, (st), (i))
define|#
directive|define
name|sk_X509_EXTENSION_delete_ptr
parameter_list|(
name|st
parameter_list|,
name|ptr
parameter_list|)
value|SKM_sk_delete_ptr(X509_EXTENSION, (st), (ptr))
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
define|#
directive|define
name|sk_X509_EXTENSION_set_cmp_func
parameter_list|(
name|st
parameter_list|,
name|cmp
parameter_list|)
value|SKM_sk_set_cmp_func(X509_EXTENSION, (st), (cmp))
define|#
directive|define
name|sk_X509_EXTENSION_dup
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_dup(X509_EXTENSION, st)
define|#
directive|define
name|sk_X509_EXTENSION_pop_free
parameter_list|(
name|st
parameter_list|,
name|free_func
parameter_list|)
value|SKM_sk_pop_free(X509_EXTENSION, (st), (free_func))
define|#
directive|define
name|sk_X509_EXTENSION_shift
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_shift(X509_EXTENSION, (st))
define|#
directive|define
name|sk_X509_EXTENSION_pop
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_pop(X509_EXTENSION, (st))
define|#
directive|define
name|sk_X509_EXTENSION_sort
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_sort(X509_EXTENSION, (st))
define|#
directive|define
name|sk_X509_EXTENSION_is_sorted
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_is_sorted(X509_EXTENSION, (st))
define|#
directive|define
name|sk_X509_INFO_new
parameter_list|(
name|cmp
parameter_list|)
value|SKM_sk_new(X509_INFO, (cmp))
define|#
directive|define
name|sk_X509_INFO_new_null
parameter_list|()
value|SKM_sk_new_null(X509_INFO)
define|#
directive|define
name|sk_X509_INFO_free
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_free(X509_INFO, (st))
define|#
directive|define
name|sk_X509_INFO_num
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_num(X509_INFO, (st))
define|#
directive|define
name|sk_X509_INFO_value
parameter_list|(
name|st
parameter_list|,
name|i
parameter_list|)
value|SKM_sk_value(X509_INFO, (st), (i))
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
define|#
directive|define
name|sk_X509_INFO_zero
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_zero(X509_INFO, (st))
define|#
directive|define
name|sk_X509_INFO_push
parameter_list|(
name|st
parameter_list|,
name|val
parameter_list|)
value|SKM_sk_push(X509_INFO, (st), (val))
define|#
directive|define
name|sk_X509_INFO_unshift
parameter_list|(
name|st
parameter_list|,
name|val
parameter_list|)
value|SKM_sk_unshift(X509_INFO, (st), (val))
define|#
directive|define
name|sk_X509_INFO_find
parameter_list|(
name|st
parameter_list|,
name|val
parameter_list|)
value|SKM_sk_find(X509_INFO, (st), (val))
define|#
directive|define
name|sk_X509_INFO_find_ex
parameter_list|(
name|st
parameter_list|,
name|val
parameter_list|)
value|SKM_sk_find_ex(X509_INFO, (st), (val))
define|#
directive|define
name|sk_X509_INFO_delete
parameter_list|(
name|st
parameter_list|,
name|i
parameter_list|)
value|SKM_sk_delete(X509_INFO, (st), (i))
define|#
directive|define
name|sk_X509_INFO_delete_ptr
parameter_list|(
name|st
parameter_list|,
name|ptr
parameter_list|)
value|SKM_sk_delete_ptr(X509_INFO, (st), (ptr))
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
define|#
directive|define
name|sk_X509_INFO_set_cmp_func
parameter_list|(
name|st
parameter_list|,
name|cmp
parameter_list|)
value|SKM_sk_set_cmp_func(X509_INFO, (st), (cmp))
define|#
directive|define
name|sk_X509_INFO_dup
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_dup(X509_INFO, st)
define|#
directive|define
name|sk_X509_INFO_pop_free
parameter_list|(
name|st
parameter_list|,
name|free_func
parameter_list|)
value|SKM_sk_pop_free(X509_INFO, (st), (free_func))
define|#
directive|define
name|sk_X509_INFO_shift
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_shift(X509_INFO, (st))
define|#
directive|define
name|sk_X509_INFO_pop
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_pop(X509_INFO, (st))
define|#
directive|define
name|sk_X509_INFO_sort
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_sort(X509_INFO, (st))
define|#
directive|define
name|sk_X509_INFO_is_sorted
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_is_sorted(X509_INFO, (st))
define|#
directive|define
name|sk_X509_LOOKUP_new
parameter_list|(
name|cmp
parameter_list|)
value|SKM_sk_new(X509_LOOKUP, (cmp))
define|#
directive|define
name|sk_X509_LOOKUP_new_null
parameter_list|()
value|SKM_sk_new_null(X509_LOOKUP)
define|#
directive|define
name|sk_X509_LOOKUP_free
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_free(X509_LOOKUP, (st))
define|#
directive|define
name|sk_X509_LOOKUP_num
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_num(X509_LOOKUP, (st))
define|#
directive|define
name|sk_X509_LOOKUP_value
parameter_list|(
name|st
parameter_list|,
name|i
parameter_list|)
value|SKM_sk_value(X509_LOOKUP, (st), (i))
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
define|#
directive|define
name|sk_X509_LOOKUP_zero
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_zero(X509_LOOKUP, (st))
define|#
directive|define
name|sk_X509_LOOKUP_push
parameter_list|(
name|st
parameter_list|,
name|val
parameter_list|)
value|SKM_sk_push(X509_LOOKUP, (st), (val))
define|#
directive|define
name|sk_X509_LOOKUP_unshift
parameter_list|(
name|st
parameter_list|,
name|val
parameter_list|)
value|SKM_sk_unshift(X509_LOOKUP, (st), (val))
define|#
directive|define
name|sk_X509_LOOKUP_find
parameter_list|(
name|st
parameter_list|,
name|val
parameter_list|)
value|SKM_sk_find(X509_LOOKUP, (st), (val))
define|#
directive|define
name|sk_X509_LOOKUP_find_ex
parameter_list|(
name|st
parameter_list|,
name|val
parameter_list|)
value|SKM_sk_find_ex(X509_LOOKUP, (st), (val))
define|#
directive|define
name|sk_X509_LOOKUP_delete
parameter_list|(
name|st
parameter_list|,
name|i
parameter_list|)
value|SKM_sk_delete(X509_LOOKUP, (st), (i))
define|#
directive|define
name|sk_X509_LOOKUP_delete_ptr
parameter_list|(
name|st
parameter_list|,
name|ptr
parameter_list|)
value|SKM_sk_delete_ptr(X509_LOOKUP, (st), (ptr))
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
define|#
directive|define
name|sk_X509_LOOKUP_set_cmp_func
parameter_list|(
name|st
parameter_list|,
name|cmp
parameter_list|)
value|SKM_sk_set_cmp_func(X509_LOOKUP, (st), (cmp))
define|#
directive|define
name|sk_X509_LOOKUP_dup
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_dup(X509_LOOKUP, st)
define|#
directive|define
name|sk_X509_LOOKUP_pop_free
parameter_list|(
name|st
parameter_list|,
name|free_func
parameter_list|)
value|SKM_sk_pop_free(X509_LOOKUP, (st), (free_func))
define|#
directive|define
name|sk_X509_LOOKUP_shift
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_shift(X509_LOOKUP, (st))
define|#
directive|define
name|sk_X509_LOOKUP_pop
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_pop(X509_LOOKUP, (st))
define|#
directive|define
name|sk_X509_LOOKUP_sort
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_sort(X509_LOOKUP, (st))
define|#
directive|define
name|sk_X509_LOOKUP_is_sorted
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_is_sorted(X509_LOOKUP, (st))
define|#
directive|define
name|sk_X509_NAME_new
parameter_list|(
name|cmp
parameter_list|)
value|SKM_sk_new(X509_NAME, (cmp))
define|#
directive|define
name|sk_X509_NAME_new_null
parameter_list|()
value|SKM_sk_new_null(X509_NAME)
define|#
directive|define
name|sk_X509_NAME_free
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_free(X509_NAME, (st))
define|#
directive|define
name|sk_X509_NAME_num
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_num(X509_NAME, (st))
define|#
directive|define
name|sk_X509_NAME_value
parameter_list|(
name|st
parameter_list|,
name|i
parameter_list|)
value|SKM_sk_value(X509_NAME, (st), (i))
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
define|#
directive|define
name|sk_X509_NAME_zero
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_zero(X509_NAME, (st))
define|#
directive|define
name|sk_X509_NAME_push
parameter_list|(
name|st
parameter_list|,
name|val
parameter_list|)
value|SKM_sk_push(X509_NAME, (st), (val))
define|#
directive|define
name|sk_X509_NAME_unshift
parameter_list|(
name|st
parameter_list|,
name|val
parameter_list|)
value|SKM_sk_unshift(X509_NAME, (st), (val))
define|#
directive|define
name|sk_X509_NAME_find
parameter_list|(
name|st
parameter_list|,
name|val
parameter_list|)
value|SKM_sk_find(X509_NAME, (st), (val))
define|#
directive|define
name|sk_X509_NAME_find_ex
parameter_list|(
name|st
parameter_list|,
name|val
parameter_list|)
value|SKM_sk_find_ex(X509_NAME, (st), (val))
define|#
directive|define
name|sk_X509_NAME_delete
parameter_list|(
name|st
parameter_list|,
name|i
parameter_list|)
value|SKM_sk_delete(X509_NAME, (st), (i))
define|#
directive|define
name|sk_X509_NAME_delete_ptr
parameter_list|(
name|st
parameter_list|,
name|ptr
parameter_list|)
value|SKM_sk_delete_ptr(X509_NAME, (st), (ptr))
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
define|#
directive|define
name|sk_X509_NAME_set_cmp_func
parameter_list|(
name|st
parameter_list|,
name|cmp
parameter_list|)
value|SKM_sk_set_cmp_func(X509_NAME, (st), (cmp))
define|#
directive|define
name|sk_X509_NAME_dup
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_dup(X509_NAME, st)
define|#
directive|define
name|sk_X509_NAME_pop_free
parameter_list|(
name|st
parameter_list|,
name|free_func
parameter_list|)
value|SKM_sk_pop_free(X509_NAME, (st), (free_func))
define|#
directive|define
name|sk_X509_NAME_shift
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_shift(X509_NAME, (st))
define|#
directive|define
name|sk_X509_NAME_pop
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_pop(X509_NAME, (st))
define|#
directive|define
name|sk_X509_NAME_sort
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_sort(X509_NAME, (st))
define|#
directive|define
name|sk_X509_NAME_is_sorted
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_is_sorted(X509_NAME, (st))
define|#
directive|define
name|sk_X509_NAME_ENTRY_new
parameter_list|(
name|cmp
parameter_list|)
value|SKM_sk_new(X509_NAME_ENTRY, (cmp))
define|#
directive|define
name|sk_X509_NAME_ENTRY_new_null
parameter_list|()
value|SKM_sk_new_null(X509_NAME_ENTRY)
define|#
directive|define
name|sk_X509_NAME_ENTRY_free
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_free(X509_NAME_ENTRY, (st))
define|#
directive|define
name|sk_X509_NAME_ENTRY_num
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_num(X509_NAME_ENTRY, (st))
define|#
directive|define
name|sk_X509_NAME_ENTRY_value
parameter_list|(
name|st
parameter_list|,
name|i
parameter_list|)
value|SKM_sk_value(X509_NAME_ENTRY, (st), (i))
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
define|#
directive|define
name|sk_X509_NAME_ENTRY_zero
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_zero(X509_NAME_ENTRY, (st))
define|#
directive|define
name|sk_X509_NAME_ENTRY_push
parameter_list|(
name|st
parameter_list|,
name|val
parameter_list|)
value|SKM_sk_push(X509_NAME_ENTRY, (st), (val))
define|#
directive|define
name|sk_X509_NAME_ENTRY_unshift
parameter_list|(
name|st
parameter_list|,
name|val
parameter_list|)
value|SKM_sk_unshift(X509_NAME_ENTRY, (st), (val))
define|#
directive|define
name|sk_X509_NAME_ENTRY_find
parameter_list|(
name|st
parameter_list|,
name|val
parameter_list|)
value|SKM_sk_find(X509_NAME_ENTRY, (st), (val))
define|#
directive|define
name|sk_X509_NAME_ENTRY_find_ex
parameter_list|(
name|st
parameter_list|,
name|val
parameter_list|)
value|SKM_sk_find_ex(X509_NAME_ENTRY, (st), (val))
define|#
directive|define
name|sk_X509_NAME_ENTRY_delete
parameter_list|(
name|st
parameter_list|,
name|i
parameter_list|)
value|SKM_sk_delete(X509_NAME_ENTRY, (st), (i))
define|#
directive|define
name|sk_X509_NAME_ENTRY_delete_ptr
parameter_list|(
name|st
parameter_list|,
name|ptr
parameter_list|)
value|SKM_sk_delete_ptr(X509_NAME_ENTRY, (st), (ptr))
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
define|#
directive|define
name|sk_X509_NAME_ENTRY_set_cmp_func
parameter_list|(
name|st
parameter_list|,
name|cmp
parameter_list|)
value|SKM_sk_set_cmp_func(X509_NAME_ENTRY, (st), (cmp))
define|#
directive|define
name|sk_X509_NAME_ENTRY_dup
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_dup(X509_NAME_ENTRY, st)
define|#
directive|define
name|sk_X509_NAME_ENTRY_pop_free
parameter_list|(
name|st
parameter_list|,
name|free_func
parameter_list|)
value|SKM_sk_pop_free(X509_NAME_ENTRY, (st), (free_func))
define|#
directive|define
name|sk_X509_NAME_ENTRY_shift
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_shift(X509_NAME_ENTRY, (st))
define|#
directive|define
name|sk_X509_NAME_ENTRY_pop
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_pop(X509_NAME_ENTRY, (st))
define|#
directive|define
name|sk_X509_NAME_ENTRY_sort
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_sort(X509_NAME_ENTRY, (st))
define|#
directive|define
name|sk_X509_NAME_ENTRY_is_sorted
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_is_sorted(X509_NAME_ENTRY, (st))
define|#
directive|define
name|sk_X509_OBJECT_new
parameter_list|(
name|cmp
parameter_list|)
value|SKM_sk_new(X509_OBJECT, (cmp))
define|#
directive|define
name|sk_X509_OBJECT_new_null
parameter_list|()
value|SKM_sk_new_null(X509_OBJECT)
define|#
directive|define
name|sk_X509_OBJECT_free
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_free(X509_OBJECT, (st))
define|#
directive|define
name|sk_X509_OBJECT_num
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_num(X509_OBJECT, (st))
define|#
directive|define
name|sk_X509_OBJECT_value
parameter_list|(
name|st
parameter_list|,
name|i
parameter_list|)
value|SKM_sk_value(X509_OBJECT, (st), (i))
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
define|#
directive|define
name|sk_X509_OBJECT_zero
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_zero(X509_OBJECT, (st))
define|#
directive|define
name|sk_X509_OBJECT_push
parameter_list|(
name|st
parameter_list|,
name|val
parameter_list|)
value|SKM_sk_push(X509_OBJECT, (st), (val))
define|#
directive|define
name|sk_X509_OBJECT_unshift
parameter_list|(
name|st
parameter_list|,
name|val
parameter_list|)
value|SKM_sk_unshift(X509_OBJECT, (st), (val))
define|#
directive|define
name|sk_X509_OBJECT_find
parameter_list|(
name|st
parameter_list|,
name|val
parameter_list|)
value|SKM_sk_find(X509_OBJECT, (st), (val))
define|#
directive|define
name|sk_X509_OBJECT_find_ex
parameter_list|(
name|st
parameter_list|,
name|val
parameter_list|)
value|SKM_sk_find_ex(X509_OBJECT, (st), (val))
define|#
directive|define
name|sk_X509_OBJECT_delete
parameter_list|(
name|st
parameter_list|,
name|i
parameter_list|)
value|SKM_sk_delete(X509_OBJECT, (st), (i))
define|#
directive|define
name|sk_X509_OBJECT_delete_ptr
parameter_list|(
name|st
parameter_list|,
name|ptr
parameter_list|)
value|SKM_sk_delete_ptr(X509_OBJECT, (st), (ptr))
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
define|#
directive|define
name|sk_X509_OBJECT_set_cmp_func
parameter_list|(
name|st
parameter_list|,
name|cmp
parameter_list|)
value|SKM_sk_set_cmp_func(X509_OBJECT, (st), (cmp))
define|#
directive|define
name|sk_X509_OBJECT_dup
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_dup(X509_OBJECT, st)
define|#
directive|define
name|sk_X509_OBJECT_pop_free
parameter_list|(
name|st
parameter_list|,
name|free_func
parameter_list|)
value|SKM_sk_pop_free(X509_OBJECT, (st), (free_func))
define|#
directive|define
name|sk_X509_OBJECT_shift
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_shift(X509_OBJECT, (st))
define|#
directive|define
name|sk_X509_OBJECT_pop
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_pop(X509_OBJECT, (st))
define|#
directive|define
name|sk_X509_OBJECT_sort
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_sort(X509_OBJECT, (st))
define|#
directive|define
name|sk_X509_OBJECT_is_sorted
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_is_sorted(X509_OBJECT, (st))
define|#
directive|define
name|sk_X509_POLICY_DATA_new
parameter_list|(
name|cmp
parameter_list|)
value|SKM_sk_new(X509_POLICY_DATA, (cmp))
define|#
directive|define
name|sk_X509_POLICY_DATA_new_null
parameter_list|()
value|SKM_sk_new_null(X509_POLICY_DATA)
define|#
directive|define
name|sk_X509_POLICY_DATA_free
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_free(X509_POLICY_DATA, (st))
define|#
directive|define
name|sk_X509_POLICY_DATA_num
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_num(X509_POLICY_DATA, (st))
define|#
directive|define
name|sk_X509_POLICY_DATA_value
parameter_list|(
name|st
parameter_list|,
name|i
parameter_list|)
value|SKM_sk_value(X509_POLICY_DATA, (st), (i))
define|#
directive|define
name|sk_X509_POLICY_DATA_set
parameter_list|(
name|st
parameter_list|,
name|i
parameter_list|,
name|val
parameter_list|)
value|SKM_sk_set(X509_POLICY_DATA, (st), (i), (val))
define|#
directive|define
name|sk_X509_POLICY_DATA_zero
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_zero(X509_POLICY_DATA, (st))
define|#
directive|define
name|sk_X509_POLICY_DATA_push
parameter_list|(
name|st
parameter_list|,
name|val
parameter_list|)
value|SKM_sk_push(X509_POLICY_DATA, (st), (val))
define|#
directive|define
name|sk_X509_POLICY_DATA_unshift
parameter_list|(
name|st
parameter_list|,
name|val
parameter_list|)
value|SKM_sk_unshift(X509_POLICY_DATA, (st), (val))
define|#
directive|define
name|sk_X509_POLICY_DATA_find
parameter_list|(
name|st
parameter_list|,
name|val
parameter_list|)
value|SKM_sk_find(X509_POLICY_DATA, (st), (val))
define|#
directive|define
name|sk_X509_POLICY_DATA_find_ex
parameter_list|(
name|st
parameter_list|,
name|val
parameter_list|)
value|SKM_sk_find_ex(X509_POLICY_DATA, (st), (val))
define|#
directive|define
name|sk_X509_POLICY_DATA_delete
parameter_list|(
name|st
parameter_list|,
name|i
parameter_list|)
value|SKM_sk_delete(X509_POLICY_DATA, (st), (i))
define|#
directive|define
name|sk_X509_POLICY_DATA_delete_ptr
parameter_list|(
name|st
parameter_list|,
name|ptr
parameter_list|)
value|SKM_sk_delete_ptr(X509_POLICY_DATA, (st), (ptr))
define|#
directive|define
name|sk_X509_POLICY_DATA_insert
parameter_list|(
name|st
parameter_list|,
name|val
parameter_list|,
name|i
parameter_list|)
value|SKM_sk_insert(X509_POLICY_DATA, (st), (val), (i))
define|#
directive|define
name|sk_X509_POLICY_DATA_set_cmp_func
parameter_list|(
name|st
parameter_list|,
name|cmp
parameter_list|)
value|SKM_sk_set_cmp_func(X509_POLICY_DATA, (st), (cmp))
define|#
directive|define
name|sk_X509_POLICY_DATA_dup
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_dup(X509_POLICY_DATA, st)
define|#
directive|define
name|sk_X509_POLICY_DATA_pop_free
parameter_list|(
name|st
parameter_list|,
name|free_func
parameter_list|)
value|SKM_sk_pop_free(X509_POLICY_DATA, (st), (free_func))
define|#
directive|define
name|sk_X509_POLICY_DATA_shift
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_shift(X509_POLICY_DATA, (st))
define|#
directive|define
name|sk_X509_POLICY_DATA_pop
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_pop(X509_POLICY_DATA, (st))
define|#
directive|define
name|sk_X509_POLICY_DATA_sort
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_sort(X509_POLICY_DATA, (st))
define|#
directive|define
name|sk_X509_POLICY_DATA_is_sorted
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_is_sorted(X509_POLICY_DATA, (st))
define|#
directive|define
name|sk_X509_POLICY_NODE_new
parameter_list|(
name|cmp
parameter_list|)
value|SKM_sk_new(X509_POLICY_NODE, (cmp))
define|#
directive|define
name|sk_X509_POLICY_NODE_new_null
parameter_list|()
value|SKM_sk_new_null(X509_POLICY_NODE)
define|#
directive|define
name|sk_X509_POLICY_NODE_free
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_free(X509_POLICY_NODE, (st))
define|#
directive|define
name|sk_X509_POLICY_NODE_num
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_num(X509_POLICY_NODE, (st))
define|#
directive|define
name|sk_X509_POLICY_NODE_value
parameter_list|(
name|st
parameter_list|,
name|i
parameter_list|)
value|SKM_sk_value(X509_POLICY_NODE, (st), (i))
define|#
directive|define
name|sk_X509_POLICY_NODE_set
parameter_list|(
name|st
parameter_list|,
name|i
parameter_list|,
name|val
parameter_list|)
value|SKM_sk_set(X509_POLICY_NODE, (st), (i), (val))
define|#
directive|define
name|sk_X509_POLICY_NODE_zero
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_zero(X509_POLICY_NODE, (st))
define|#
directive|define
name|sk_X509_POLICY_NODE_push
parameter_list|(
name|st
parameter_list|,
name|val
parameter_list|)
value|SKM_sk_push(X509_POLICY_NODE, (st), (val))
define|#
directive|define
name|sk_X509_POLICY_NODE_unshift
parameter_list|(
name|st
parameter_list|,
name|val
parameter_list|)
value|SKM_sk_unshift(X509_POLICY_NODE, (st), (val))
define|#
directive|define
name|sk_X509_POLICY_NODE_find
parameter_list|(
name|st
parameter_list|,
name|val
parameter_list|)
value|SKM_sk_find(X509_POLICY_NODE, (st), (val))
define|#
directive|define
name|sk_X509_POLICY_NODE_find_ex
parameter_list|(
name|st
parameter_list|,
name|val
parameter_list|)
value|SKM_sk_find_ex(X509_POLICY_NODE, (st), (val))
define|#
directive|define
name|sk_X509_POLICY_NODE_delete
parameter_list|(
name|st
parameter_list|,
name|i
parameter_list|)
value|SKM_sk_delete(X509_POLICY_NODE, (st), (i))
define|#
directive|define
name|sk_X509_POLICY_NODE_delete_ptr
parameter_list|(
name|st
parameter_list|,
name|ptr
parameter_list|)
value|SKM_sk_delete_ptr(X509_POLICY_NODE, (st), (ptr))
define|#
directive|define
name|sk_X509_POLICY_NODE_insert
parameter_list|(
name|st
parameter_list|,
name|val
parameter_list|,
name|i
parameter_list|)
value|SKM_sk_insert(X509_POLICY_NODE, (st), (val), (i))
define|#
directive|define
name|sk_X509_POLICY_NODE_set_cmp_func
parameter_list|(
name|st
parameter_list|,
name|cmp
parameter_list|)
value|SKM_sk_set_cmp_func(X509_POLICY_NODE, (st), (cmp))
define|#
directive|define
name|sk_X509_POLICY_NODE_dup
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_dup(X509_POLICY_NODE, st)
define|#
directive|define
name|sk_X509_POLICY_NODE_pop_free
parameter_list|(
name|st
parameter_list|,
name|free_func
parameter_list|)
value|SKM_sk_pop_free(X509_POLICY_NODE, (st), (free_func))
define|#
directive|define
name|sk_X509_POLICY_NODE_shift
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_shift(X509_POLICY_NODE, (st))
define|#
directive|define
name|sk_X509_POLICY_NODE_pop
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_pop(X509_POLICY_NODE, (st))
define|#
directive|define
name|sk_X509_POLICY_NODE_sort
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_sort(X509_POLICY_NODE, (st))
define|#
directive|define
name|sk_X509_POLICY_NODE_is_sorted
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_is_sorted(X509_POLICY_NODE, (st))
define|#
directive|define
name|sk_X509_PURPOSE_new
parameter_list|(
name|cmp
parameter_list|)
value|SKM_sk_new(X509_PURPOSE, (cmp))
define|#
directive|define
name|sk_X509_PURPOSE_new_null
parameter_list|()
value|SKM_sk_new_null(X509_PURPOSE)
define|#
directive|define
name|sk_X509_PURPOSE_free
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_free(X509_PURPOSE, (st))
define|#
directive|define
name|sk_X509_PURPOSE_num
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_num(X509_PURPOSE, (st))
define|#
directive|define
name|sk_X509_PURPOSE_value
parameter_list|(
name|st
parameter_list|,
name|i
parameter_list|)
value|SKM_sk_value(X509_PURPOSE, (st), (i))
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
define|#
directive|define
name|sk_X509_PURPOSE_zero
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_zero(X509_PURPOSE, (st))
define|#
directive|define
name|sk_X509_PURPOSE_push
parameter_list|(
name|st
parameter_list|,
name|val
parameter_list|)
value|SKM_sk_push(X509_PURPOSE, (st), (val))
define|#
directive|define
name|sk_X509_PURPOSE_unshift
parameter_list|(
name|st
parameter_list|,
name|val
parameter_list|)
value|SKM_sk_unshift(X509_PURPOSE, (st), (val))
define|#
directive|define
name|sk_X509_PURPOSE_find
parameter_list|(
name|st
parameter_list|,
name|val
parameter_list|)
value|SKM_sk_find(X509_PURPOSE, (st), (val))
define|#
directive|define
name|sk_X509_PURPOSE_find_ex
parameter_list|(
name|st
parameter_list|,
name|val
parameter_list|)
value|SKM_sk_find_ex(X509_PURPOSE, (st), (val))
define|#
directive|define
name|sk_X509_PURPOSE_delete
parameter_list|(
name|st
parameter_list|,
name|i
parameter_list|)
value|SKM_sk_delete(X509_PURPOSE, (st), (i))
define|#
directive|define
name|sk_X509_PURPOSE_delete_ptr
parameter_list|(
name|st
parameter_list|,
name|ptr
parameter_list|)
value|SKM_sk_delete_ptr(X509_PURPOSE, (st), (ptr))
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
define|#
directive|define
name|sk_X509_PURPOSE_set_cmp_func
parameter_list|(
name|st
parameter_list|,
name|cmp
parameter_list|)
value|SKM_sk_set_cmp_func(X509_PURPOSE, (st), (cmp))
define|#
directive|define
name|sk_X509_PURPOSE_dup
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_dup(X509_PURPOSE, st)
define|#
directive|define
name|sk_X509_PURPOSE_pop_free
parameter_list|(
name|st
parameter_list|,
name|free_func
parameter_list|)
value|SKM_sk_pop_free(X509_PURPOSE, (st), (free_func))
define|#
directive|define
name|sk_X509_PURPOSE_shift
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_shift(X509_PURPOSE, (st))
define|#
directive|define
name|sk_X509_PURPOSE_pop
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_pop(X509_PURPOSE, (st))
define|#
directive|define
name|sk_X509_PURPOSE_sort
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_sort(X509_PURPOSE, (st))
define|#
directive|define
name|sk_X509_PURPOSE_is_sorted
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_is_sorted(X509_PURPOSE, (st))
define|#
directive|define
name|sk_X509_REVOKED_new
parameter_list|(
name|cmp
parameter_list|)
value|SKM_sk_new(X509_REVOKED, (cmp))
define|#
directive|define
name|sk_X509_REVOKED_new_null
parameter_list|()
value|SKM_sk_new_null(X509_REVOKED)
define|#
directive|define
name|sk_X509_REVOKED_free
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_free(X509_REVOKED, (st))
define|#
directive|define
name|sk_X509_REVOKED_num
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_num(X509_REVOKED, (st))
define|#
directive|define
name|sk_X509_REVOKED_value
parameter_list|(
name|st
parameter_list|,
name|i
parameter_list|)
value|SKM_sk_value(X509_REVOKED, (st), (i))
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
define|#
directive|define
name|sk_X509_REVOKED_zero
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_zero(X509_REVOKED, (st))
define|#
directive|define
name|sk_X509_REVOKED_push
parameter_list|(
name|st
parameter_list|,
name|val
parameter_list|)
value|SKM_sk_push(X509_REVOKED, (st), (val))
define|#
directive|define
name|sk_X509_REVOKED_unshift
parameter_list|(
name|st
parameter_list|,
name|val
parameter_list|)
value|SKM_sk_unshift(X509_REVOKED, (st), (val))
define|#
directive|define
name|sk_X509_REVOKED_find
parameter_list|(
name|st
parameter_list|,
name|val
parameter_list|)
value|SKM_sk_find(X509_REVOKED, (st), (val))
define|#
directive|define
name|sk_X509_REVOKED_find_ex
parameter_list|(
name|st
parameter_list|,
name|val
parameter_list|)
value|SKM_sk_find_ex(X509_REVOKED, (st), (val))
define|#
directive|define
name|sk_X509_REVOKED_delete
parameter_list|(
name|st
parameter_list|,
name|i
parameter_list|)
value|SKM_sk_delete(X509_REVOKED, (st), (i))
define|#
directive|define
name|sk_X509_REVOKED_delete_ptr
parameter_list|(
name|st
parameter_list|,
name|ptr
parameter_list|)
value|SKM_sk_delete_ptr(X509_REVOKED, (st), (ptr))
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
define|#
directive|define
name|sk_X509_REVOKED_set_cmp_func
parameter_list|(
name|st
parameter_list|,
name|cmp
parameter_list|)
value|SKM_sk_set_cmp_func(X509_REVOKED, (st), (cmp))
define|#
directive|define
name|sk_X509_REVOKED_dup
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_dup(X509_REVOKED, st)
define|#
directive|define
name|sk_X509_REVOKED_pop_free
parameter_list|(
name|st
parameter_list|,
name|free_func
parameter_list|)
value|SKM_sk_pop_free(X509_REVOKED, (st), (free_func))
define|#
directive|define
name|sk_X509_REVOKED_shift
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_shift(X509_REVOKED, (st))
define|#
directive|define
name|sk_X509_REVOKED_pop
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_pop(X509_REVOKED, (st))
define|#
directive|define
name|sk_X509_REVOKED_sort
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_sort(X509_REVOKED, (st))
define|#
directive|define
name|sk_X509_REVOKED_is_sorted
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_is_sorted(X509_REVOKED, (st))
define|#
directive|define
name|sk_X509_TRUST_new
parameter_list|(
name|cmp
parameter_list|)
value|SKM_sk_new(X509_TRUST, (cmp))
define|#
directive|define
name|sk_X509_TRUST_new_null
parameter_list|()
value|SKM_sk_new_null(X509_TRUST)
define|#
directive|define
name|sk_X509_TRUST_free
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_free(X509_TRUST, (st))
define|#
directive|define
name|sk_X509_TRUST_num
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_num(X509_TRUST, (st))
define|#
directive|define
name|sk_X509_TRUST_value
parameter_list|(
name|st
parameter_list|,
name|i
parameter_list|)
value|SKM_sk_value(X509_TRUST, (st), (i))
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
define|#
directive|define
name|sk_X509_TRUST_zero
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_zero(X509_TRUST, (st))
define|#
directive|define
name|sk_X509_TRUST_push
parameter_list|(
name|st
parameter_list|,
name|val
parameter_list|)
value|SKM_sk_push(X509_TRUST, (st), (val))
define|#
directive|define
name|sk_X509_TRUST_unshift
parameter_list|(
name|st
parameter_list|,
name|val
parameter_list|)
value|SKM_sk_unshift(X509_TRUST, (st), (val))
define|#
directive|define
name|sk_X509_TRUST_find
parameter_list|(
name|st
parameter_list|,
name|val
parameter_list|)
value|SKM_sk_find(X509_TRUST, (st), (val))
define|#
directive|define
name|sk_X509_TRUST_find_ex
parameter_list|(
name|st
parameter_list|,
name|val
parameter_list|)
value|SKM_sk_find_ex(X509_TRUST, (st), (val))
define|#
directive|define
name|sk_X509_TRUST_delete
parameter_list|(
name|st
parameter_list|,
name|i
parameter_list|)
value|SKM_sk_delete(X509_TRUST, (st), (i))
define|#
directive|define
name|sk_X509_TRUST_delete_ptr
parameter_list|(
name|st
parameter_list|,
name|ptr
parameter_list|)
value|SKM_sk_delete_ptr(X509_TRUST, (st), (ptr))
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
define|#
directive|define
name|sk_X509_TRUST_set_cmp_func
parameter_list|(
name|st
parameter_list|,
name|cmp
parameter_list|)
value|SKM_sk_set_cmp_func(X509_TRUST, (st), (cmp))
define|#
directive|define
name|sk_X509_TRUST_dup
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_dup(X509_TRUST, st)
define|#
directive|define
name|sk_X509_TRUST_pop_free
parameter_list|(
name|st
parameter_list|,
name|free_func
parameter_list|)
value|SKM_sk_pop_free(X509_TRUST, (st), (free_func))
define|#
directive|define
name|sk_X509_TRUST_shift
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_shift(X509_TRUST, (st))
define|#
directive|define
name|sk_X509_TRUST_pop
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_pop(X509_TRUST, (st))
define|#
directive|define
name|sk_X509_TRUST_sort
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_sort(X509_TRUST, (st))
define|#
directive|define
name|sk_X509_TRUST_is_sorted
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_is_sorted(X509_TRUST, (st))
define|#
directive|define
name|sk_X509_VERIFY_PARAM_new
parameter_list|(
name|cmp
parameter_list|)
value|SKM_sk_new(X509_VERIFY_PARAM, (cmp))
define|#
directive|define
name|sk_X509_VERIFY_PARAM_new_null
parameter_list|()
value|SKM_sk_new_null(X509_VERIFY_PARAM)
define|#
directive|define
name|sk_X509_VERIFY_PARAM_free
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_free(X509_VERIFY_PARAM, (st))
define|#
directive|define
name|sk_X509_VERIFY_PARAM_num
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_num(X509_VERIFY_PARAM, (st))
define|#
directive|define
name|sk_X509_VERIFY_PARAM_value
parameter_list|(
name|st
parameter_list|,
name|i
parameter_list|)
value|SKM_sk_value(X509_VERIFY_PARAM, (st), (i))
define|#
directive|define
name|sk_X509_VERIFY_PARAM_set
parameter_list|(
name|st
parameter_list|,
name|i
parameter_list|,
name|val
parameter_list|)
value|SKM_sk_set(X509_VERIFY_PARAM, (st), (i), (val))
define|#
directive|define
name|sk_X509_VERIFY_PARAM_zero
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_zero(X509_VERIFY_PARAM, (st))
define|#
directive|define
name|sk_X509_VERIFY_PARAM_push
parameter_list|(
name|st
parameter_list|,
name|val
parameter_list|)
value|SKM_sk_push(X509_VERIFY_PARAM, (st), (val))
define|#
directive|define
name|sk_X509_VERIFY_PARAM_unshift
parameter_list|(
name|st
parameter_list|,
name|val
parameter_list|)
value|SKM_sk_unshift(X509_VERIFY_PARAM, (st), (val))
define|#
directive|define
name|sk_X509_VERIFY_PARAM_find
parameter_list|(
name|st
parameter_list|,
name|val
parameter_list|)
value|SKM_sk_find(X509_VERIFY_PARAM, (st), (val))
define|#
directive|define
name|sk_X509_VERIFY_PARAM_find_ex
parameter_list|(
name|st
parameter_list|,
name|val
parameter_list|)
value|SKM_sk_find_ex(X509_VERIFY_PARAM, (st), (val))
define|#
directive|define
name|sk_X509_VERIFY_PARAM_delete
parameter_list|(
name|st
parameter_list|,
name|i
parameter_list|)
value|SKM_sk_delete(X509_VERIFY_PARAM, (st), (i))
define|#
directive|define
name|sk_X509_VERIFY_PARAM_delete_ptr
parameter_list|(
name|st
parameter_list|,
name|ptr
parameter_list|)
value|SKM_sk_delete_ptr(X509_VERIFY_PARAM, (st), (ptr))
define|#
directive|define
name|sk_X509_VERIFY_PARAM_insert
parameter_list|(
name|st
parameter_list|,
name|val
parameter_list|,
name|i
parameter_list|)
value|SKM_sk_insert(X509_VERIFY_PARAM, (st), (val), (i))
define|#
directive|define
name|sk_X509_VERIFY_PARAM_set_cmp_func
parameter_list|(
name|st
parameter_list|,
name|cmp
parameter_list|)
value|SKM_sk_set_cmp_func(X509_VERIFY_PARAM, (st), (cmp))
define|#
directive|define
name|sk_X509_VERIFY_PARAM_dup
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_dup(X509_VERIFY_PARAM, st)
define|#
directive|define
name|sk_X509_VERIFY_PARAM_pop_free
parameter_list|(
name|st
parameter_list|,
name|free_func
parameter_list|)
value|SKM_sk_pop_free(X509_VERIFY_PARAM, (st), (free_func))
define|#
directive|define
name|sk_X509_VERIFY_PARAM_shift
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_shift(X509_VERIFY_PARAM, (st))
define|#
directive|define
name|sk_X509_VERIFY_PARAM_pop
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_pop(X509_VERIFY_PARAM, (st))
define|#
directive|define
name|sk_X509_VERIFY_PARAM_sort
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_sort(X509_VERIFY_PARAM, (st))
define|#
directive|define
name|sk_X509_VERIFY_PARAM_is_sorted
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_is_sorted(X509_VERIFY_PARAM, (st))
define|#
directive|define
name|sk_nid_triple_new
parameter_list|(
name|cmp
parameter_list|)
value|SKM_sk_new(nid_triple, (cmp))
define|#
directive|define
name|sk_nid_triple_new_null
parameter_list|()
value|SKM_sk_new_null(nid_triple)
define|#
directive|define
name|sk_nid_triple_free
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_free(nid_triple, (st))
define|#
directive|define
name|sk_nid_triple_num
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_num(nid_triple, (st))
define|#
directive|define
name|sk_nid_triple_value
parameter_list|(
name|st
parameter_list|,
name|i
parameter_list|)
value|SKM_sk_value(nid_triple, (st), (i))
define|#
directive|define
name|sk_nid_triple_set
parameter_list|(
name|st
parameter_list|,
name|i
parameter_list|,
name|val
parameter_list|)
value|SKM_sk_set(nid_triple, (st), (i), (val))
define|#
directive|define
name|sk_nid_triple_zero
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_zero(nid_triple, (st))
define|#
directive|define
name|sk_nid_triple_push
parameter_list|(
name|st
parameter_list|,
name|val
parameter_list|)
value|SKM_sk_push(nid_triple, (st), (val))
define|#
directive|define
name|sk_nid_triple_unshift
parameter_list|(
name|st
parameter_list|,
name|val
parameter_list|)
value|SKM_sk_unshift(nid_triple, (st), (val))
define|#
directive|define
name|sk_nid_triple_find
parameter_list|(
name|st
parameter_list|,
name|val
parameter_list|)
value|SKM_sk_find(nid_triple, (st), (val))
define|#
directive|define
name|sk_nid_triple_find_ex
parameter_list|(
name|st
parameter_list|,
name|val
parameter_list|)
value|SKM_sk_find_ex(nid_triple, (st), (val))
define|#
directive|define
name|sk_nid_triple_delete
parameter_list|(
name|st
parameter_list|,
name|i
parameter_list|)
value|SKM_sk_delete(nid_triple, (st), (i))
define|#
directive|define
name|sk_nid_triple_delete_ptr
parameter_list|(
name|st
parameter_list|,
name|ptr
parameter_list|)
value|SKM_sk_delete_ptr(nid_triple, (st), (ptr))
define|#
directive|define
name|sk_nid_triple_insert
parameter_list|(
name|st
parameter_list|,
name|val
parameter_list|,
name|i
parameter_list|)
value|SKM_sk_insert(nid_triple, (st), (val), (i))
define|#
directive|define
name|sk_nid_triple_set_cmp_func
parameter_list|(
name|st
parameter_list|,
name|cmp
parameter_list|)
value|SKM_sk_set_cmp_func(nid_triple, (st), (cmp))
define|#
directive|define
name|sk_nid_triple_dup
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_dup(nid_triple, st)
define|#
directive|define
name|sk_nid_triple_pop_free
parameter_list|(
name|st
parameter_list|,
name|free_func
parameter_list|)
value|SKM_sk_pop_free(nid_triple, (st), (free_func))
define|#
directive|define
name|sk_nid_triple_shift
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_shift(nid_triple, (st))
define|#
directive|define
name|sk_nid_triple_pop
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_pop(nid_triple, (st))
define|#
directive|define
name|sk_nid_triple_sort
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_sort(nid_triple, (st))
define|#
directive|define
name|sk_nid_triple_is_sorted
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_is_sorted(nid_triple, (st))
define|#
directive|define
name|sk_void_new
parameter_list|(
name|cmp
parameter_list|)
value|SKM_sk_new(void, (cmp))
define|#
directive|define
name|sk_void_new_null
parameter_list|()
value|SKM_sk_new_null(void)
define|#
directive|define
name|sk_void_free
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_free(void, (st))
define|#
directive|define
name|sk_void_num
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_num(void, (st))
define|#
directive|define
name|sk_void_value
parameter_list|(
name|st
parameter_list|,
name|i
parameter_list|)
value|SKM_sk_value(void, (st), (i))
define|#
directive|define
name|sk_void_set
parameter_list|(
name|st
parameter_list|,
name|i
parameter_list|,
name|val
parameter_list|)
value|SKM_sk_set(void, (st), (i), (val))
define|#
directive|define
name|sk_void_zero
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_zero(void, (st))
define|#
directive|define
name|sk_void_push
parameter_list|(
name|st
parameter_list|,
name|val
parameter_list|)
value|SKM_sk_push(void, (st), (val))
define|#
directive|define
name|sk_void_unshift
parameter_list|(
name|st
parameter_list|,
name|val
parameter_list|)
value|SKM_sk_unshift(void, (st), (val))
define|#
directive|define
name|sk_void_find
parameter_list|(
name|st
parameter_list|,
name|val
parameter_list|)
value|SKM_sk_find(void, (st), (val))
define|#
directive|define
name|sk_void_find_ex
parameter_list|(
name|st
parameter_list|,
name|val
parameter_list|)
value|SKM_sk_find_ex(void, (st), (val))
define|#
directive|define
name|sk_void_delete
parameter_list|(
name|st
parameter_list|,
name|i
parameter_list|)
value|SKM_sk_delete(void, (st), (i))
define|#
directive|define
name|sk_void_delete_ptr
parameter_list|(
name|st
parameter_list|,
name|ptr
parameter_list|)
value|SKM_sk_delete_ptr(void, (st), (ptr))
define|#
directive|define
name|sk_void_insert
parameter_list|(
name|st
parameter_list|,
name|val
parameter_list|,
name|i
parameter_list|)
value|SKM_sk_insert(void, (st), (val), (i))
define|#
directive|define
name|sk_void_set_cmp_func
parameter_list|(
name|st
parameter_list|,
name|cmp
parameter_list|)
value|SKM_sk_set_cmp_func(void, (st), (cmp))
define|#
directive|define
name|sk_void_dup
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_dup(void, st)
define|#
directive|define
name|sk_void_pop_free
parameter_list|(
name|st
parameter_list|,
name|free_func
parameter_list|)
value|SKM_sk_pop_free(void, (st), (free_func))
define|#
directive|define
name|sk_void_shift
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_shift(void, (st))
define|#
directive|define
name|sk_void_pop
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_pop(void, (st))
define|#
directive|define
name|sk_void_sort
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_sort(void, (st))
define|#
directive|define
name|sk_void_is_sorted
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_is_sorted(void, (st))
define|#
directive|define
name|sk_OPENSSL_STRING_new
parameter_list|(
name|cmp
parameter_list|)
value|((STACK_OF(OPENSSL_STRING) *)sk_new(CHECKED_SK_CMP_FUNC(char, cmp)))
define|#
directive|define
name|sk_OPENSSL_STRING_new_null
parameter_list|()
value|((STACK_OF(OPENSSL_STRING) *)sk_new_null())
define|#
directive|define
name|sk_OPENSSL_STRING_push
parameter_list|(
name|st
parameter_list|,
name|val
parameter_list|)
value|sk_push(CHECKED_STACK_OF(OPENSSL_STRING, st), CHECKED_PTR_OF(char, val))
define|#
directive|define
name|sk_OPENSSL_STRING_find
parameter_list|(
name|st
parameter_list|,
name|val
parameter_list|)
value|sk_find(CHECKED_STACK_OF(OPENSSL_STRING, st), CHECKED_PTR_OF(char, val))
define|#
directive|define
name|sk_OPENSSL_STRING_value
parameter_list|(
name|st
parameter_list|,
name|i
parameter_list|)
value|((OPENSSL_STRING)sk_value(CHECKED_STACK_OF(OPENSSL_STRING, st), i))
define|#
directive|define
name|sk_OPENSSL_STRING_num
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_num(OPENSSL_STRING, st)
define|#
directive|define
name|sk_OPENSSL_STRING_pop_free
parameter_list|(
name|st
parameter_list|,
name|free_func
parameter_list|)
value|sk_pop_free(CHECKED_STACK_OF(OPENSSL_STRING, st), CHECKED_SK_FREE_FUNC2(OPENSSL_STRING, free_func))
define|#
directive|define
name|sk_OPENSSL_STRING_insert
parameter_list|(
name|st
parameter_list|,
name|val
parameter_list|,
name|i
parameter_list|)
value|sk_insert(CHECKED_STACK_OF(OPENSSL_STRING, st), CHECKED_PTR_OF(char, val), i)
define|#
directive|define
name|sk_OPENSSL_STRING_free
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_free(OPENSSL_STRING, st)
define|#
directive|define
name|sk_OPENSSL_STRING_set
parameter_list|(
name|st
parameter_list|,
name|i
parameter_list|,
name|val
parameter_list|)
value|sk_set(CHECKED_STACK_OF(OPENSSL_STRING, st), i, CHECKED_PTR_OF(char, val))
define|#
directive|define
name|sk_OPENSSL_STRING_zero
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_zero(OPENSSL_STRING, (st))
define|#
directive|define
name|sk_OPENSSL_STRING_unshift
parameter_list|(
name|st
parameter_list|,
name|val
parameter_list|)
value|sk_unshift(CHECKED_STACK_OF(OPENSSL_STRING, st), CHECKED_PTR_OF(char, val))
define|#
directive|define
name|sk_OPENSSL_STRING_find_ex
parameter_list|(
name|st
parameter_list|,
name|val
parameter_list|)
value|sk_find_ex((_STACK *)CHECKED_CONST_PTR_OF(STACK_OF(OPENSSL_STRING), st), CHECKED_CONST_PTR_OF(char, val))
define|#
directive|define
name|sk_OPENSSL_STRING_delete
parameter_list|(
name|st
parameter_list|,
name|i
parameter_list|)
value|SKM_sk_delete(OPENSSL_STRING, (st), (i))
define|#
directive|define
name|sk_OPENSSL_STRING_delete_ptr
parameter_list|(
name|st
parameter_list|,
name|ptr
parameter_list|)
value|(OPENSSL_STRING *)sk_delete_ptr(CHECKED_STACK_OF(OPENSSL_STRING, st), CHECKED_PTR_OF(char, ptr))
define|#
directive|define
name|sk_OPENSSL_STRING_set_cmp_func
parameter_list|(
name|st
parameter_list|,
name|cmp
parameter_list|)
define|\
value|((int (*)(const char * const *,const char * const *)) \ 	sk_set_cmp_func(CHECKED_STACK_OF(OPENSSL_STRING, st), CHECKED_SK_CMP_FUNC(char, cmp)))
define|#
directive|define
name|sk_OPENSSL_STRING_dup
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_dup(OPENSSL_STRING, st)
define|#
directive|define
name|sk_OPENSSL_STRING_shift
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_shift(OPENSSL_STRING, (st))
define|#
directive|define
name|sk_OPENSSL_STRING_pop
parameter_list|(
name|st
parameter_list|)
value|(char *)sk_pop(CHECKED_STACK_OF(OPENSSL_STRING, st))
define|#
directive|define
name|sk_OPENSSL_STRING_sort
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_sort(OPENSSL_STRING, (st))
define|#
directive|define
name|sk_OPENSSL_STRING_is_sorted
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_is_sorted(OPENSSL_STRING, (st))
define|#
directive|define
name|sk_OPENSSL_BLOCK_new
parameter_list|(
name|cmp
parameter_list|)
value|((STACK_OF(OPENSSL_BLOCK) *)sk_new(CHECKED_SK_CMP_FUNC(void, cmp)))
define|#
directive|define
name|sk_OPENSSL_BLOCK_new_null
parameter_list|()
value|((STACK_OF(OPENSSL_BLOCK) *)sk_new_null())
define|#
directive|define
name|sk_OPENSSL_BLOCK_push
parameter_list|(
name|st
parameter_list|,
name|val
parameter_list|)
value|sk_push(CHECKED_STACK_OF(OPENSSL_BLOCK, st), CHECKED_PTR_OF(void, val))
define|#
directive|define
name|sk_OPENSSL_BLOCK_find
parameter_list|(
name|st
parameter_list|,
name|val
parameter_list|)
value|sk_find(CHECKED_STACK_OF(OPENSSL_BLOCK, st), CHECKED_PTR_OF(void, val))
define|#
directive|define
name|sk_OPENSSL_BLOCK_value
parameter_list|(
name|st
parameter_list|,
name|i
parameter_list|)
value|((OPENSSL_BLOCK)sk_value(CHECKED_STACK_OF(OPENSSL_BLOCK, st), i))
define|#
directive|define
name|sk_OPENSSL_BLOCK_num
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_num(OPENSSL_BLOCK, st)
define|#
directive|define
name|sk_OPENSSL_BLOCK_pop_free
parameter_list|(
name|st
parameter_list|,
name|free_func
parameter_list|)
value|sk_pop_free(CHECKED_STACK_OF(OPENSSL_BLOCK, st), CHECKED_SK_FREE_FUNC2(OPENSSL_BLOCK, free_func))
define|#
directive|define
name|sk_OPENSSL_BLOCK_insert
parameter_list|(
name|st
parameter_list|,
name|val
parameter_list|,
name|i
parameter_list|)
value|sk_insert(CHECKED_STACK_OF(OPENSSL_BLOCK, st), CHECKED_PTR_OF(void, val), i)
define|#
directive|define
name|sk_OPENSSL_BLOCK_free
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_free(OPENSSL_BLOCK, st)
define|#
directive|define
name|sk_OPENSSL_BLOCK_set
parameter_list|(
name|st
parameter_list|,
name|i
parameter_list|,
name|val
parameter_list|)
value|sk_set(CHECKED_STACK_OF(OPENSSL_BLOCK, st), i, CHECKED_PTR_OF(void, val))
define|#
directive|define
name|sk_OPENSSL_BLOCK_zero
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_zero(OPENSSL_BLOCK, (st))
define|#
directive|define
name|sk_OPENSSL_BLOCK_unshift
parameter_list|(
name|st
parameter_list|,
name|val
parameter_list|)
value|sk_unshift(CHECKED_STACK_OF(OPENSSL_BLOCK, st), CHECKED_PTR_OF(void, val))
define|#
directive|define
name|sk_OPENSSL_BLOCK_find_ex
parameter_list|(
name|st
parameter_list|,
name|val
parameter_list|)
value|sk_find_ex((_STACK *)CHECKED_CONST_PTR_OF(STACK_OF(OPENSSL_BLOCK), st), CHECKED_CONST_PTR_OF(void, val))
define|#
directive|define
name|sk_OPENSSL_BLOCK_delete
parameter_list|(
name|st
parameter_list|,
name|i
parameter_list|)
value|SKM_sk_delete(OPENSSL_BLOCK, (st), (i))
define|#
directive|define
name|sk_OPENSSL_BLOCK_delete_ptr
parameter_list|(
name|st
parameter_list|,
name|ptr
parameter_list|)
value|(OPENSSL_BLOCK *)sk_delete_ptr(CHECKED_STACK_OF(OPENSSL_BLOCK, st), CHECKED_PTR_OF(void, ptr))
define|#
directive|define
name|sk_OPENSSL_BLOCK_set_cmp_func
parameter_list|(
name|st
parameter_list|,
name|cmp
parameter_list|)
define|\
value|((int (*)(const void * const *,const void * const *)) \ 	sk_set_cmp_func(CHECKED_STACK_OF(OPENSSL_BLOCK, st), CHECKED_SK_CMP_FUNC(void, cmp)))
define|#
directive|define
name|sk_OPENSSL_BLOCK_dup
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_dup(OPENSSL_BLOCK, st)
define|#
directive|define
name|sk_OPENSSL_BLOCK_shift
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_shift(OPENSSL_BLOCK, (st))
define|#
directive|define
name|sk_OPENSSL_BLOCK_pop
parameter_list|(
name|st
parameter_list|)
value|(void *)sk_pop(CHECKED_STACK_OF(OPENSSL_BLOCK, st))
define|#
directive|define
name|sk_OPENSSL_BLOCK_sort
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_sort(OPENSSL_BLOCK, (st))
define|#
directive|define
name|sk_OPENSSL_BLOCK_is_sorted
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_is_sorted(OPENSSL_BLOCK, (st))
define|#
directive|define
name|sk_OPENSSL_PSTRING_new
parameter_list|(
name|cmp
parameter_list|)
value|((STACK_OF(OPENSSL_PSTRING) *)sk_new(CHECKED_SK_CMP_FUNC(OPENSSL_STRING, cmp)))
define|#
directive|define
name|sk_OPENSSL_PSTRING_new_null
parameter_list|()
value|((STACK_OF(OPENSSL_PSTRING) *)sk_new_null())
define|#
directive|define
name|sk_OPENSSL_PSTRING_push
parameter_list|(
name|st
parameter_list|,
name|val
parameter_list|)
value|sk_push(CHECKED_STACK_OF(OPENSSL_PSTRING, st), CHECKED_PTR_OF(OPENSSL_STRING, val))
define|#
directive|define
name|sk_OPENSSL_PSTRING_find
parameter_list|(
name|st
parameter_list|,
name|val
parameter_list|)
value|sk_find(CHECKED_STACK_OF(OPENSSL_PSTRING, st), CHECKED_PTR_OF(OPENSSL_STRING, val))
define|#
directive|define
name|sk_OPENSSL_PSTRING_value
parameter_list|(
name|st
parameter_list|,
name|i
parameter_list|)
value|((OPENSSL_PSTRING)sk_value(CHECKED_STACK_OF(OPENSSL_PSTRING, st), i))
define|#
directive|define
name|sk_OPENSSL_PSTRING_num
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_num(OPENSSL_PSTRING, st)
define|#
directive|define
name|sk_OPENSSL_PSTRING_pop_free
parameter_list|(
name|st
parameter_list|,
name|free_func
parameter_list|)
value|sk_pop_free(CHECKED_STACK_OF(OPENSSL_PSTRING, st), CHECKED_SK_FREE_FUNC2(OPENSSL_PSTRING, free_func))
define|#
directive|define
name|sk_OPENSSL_PSTRING_insert
parameter_list|(
name|st
parameter_list|,
name|val
parameter_list|,
name|i
parameter_list|)
value|sk_insert(CHECKED_STACK_OF(OPENSSL_PSTRING, st), CHECKED_PTR_OF(OPENSSL_STRING, val), i)
define|#
directive|define
name|sk_OPENSSL_PSTRING_free
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_free(OPENSSL_PSTRING, st)
define|#
directive|define
name|sk_OPENSSL_PSTRING_set
parameter_list|(
name|st
parameter_list|,
name|i
parameter_list|,
name|val
parameter_list|)
value|sk_set(CHECKED_STACK_OF(OPENSSL_PSTRING, st), i, CHECKED_PTR_OF(OPENSSL_STRING, val))
define|#
directive|define
name|sk_OPENSSL_PSTRING_zero
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_zero(OPENSSL_PSTRING, (st))
define|#
directive|define
name|sk_OPENSSL_PSTRING_unshift
parameter_list|(
name|st
parameter_list|,
name|val
parameter_list|)
value|sk_unshift(CHECKED_STACK_OF(OPENSSL_PSTRING, st), CHECKED_PTR_OF(OPENSSL_STRING, val))
define|#
directive|define
name|sk_OPENSSL_PSTRING_find_ex
parameter_list|(
name|st
parameter_list|,
name|val
parameter_list|)
value|sk_find_ex((_STACK *)CHECKED_CONST_PTR_OF(STACK_OF(OPENSSL_PSTRING), st), CHECKED_CONST_PTR_OF(OPENSSL_STRING, val))
define|#
directive|define
name|sk_OPENSSL_PSTRING_delete
parameter_list|(
name|st
parameter_list|,
name|i
parameter_list|)
value|SKM_sk_delete(OPENSSL_PSTRING, (st), (i))
define|#
directive|define
name|sk_OPENSSL_PSTRING_delete_ptr
parameter_list|(
name|st
parameter_list|,
name|ptr
parameter_list|)
value|(OPENSSL_PSTRING *)sk_delete_ptr(CHECKED_STACK_OF(OPENSSL_PSTRING, st), CHECKED_PTR_OF(OPENSSL_STRING, ptr))
define|#
directive|define
name|sk_OPENSSL_PSTRING_set_cmp_func
parameter_list|(
name|st
parameter_list|,
name|cmp
parameter_list|)
define|\
value|((int (*)(const OPENSSL_STRING * const *,const OPENSSL_STRING * const *)) \ 	sk_set_cmp_func(CHECKED_STACK_OF(OPENSSL_PSTRING, st), CHECKED_SK_CMP_FUNC(OPENSSL_STRING, cmp)))
define|#
directive|define
name|sk_OPENSSL_PSTRING_dup
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_dup(OPENSSL_PSTRING, st)
define|#
directive|define
name|sk_OPENSSL_PSTRING_shift
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_shift(OPENSSL_PSTRING, (st))
define|#
directive|define
name|sk_OPENSSL_PSTRING_pop
parameter_list|(
name|st
parameter_list|)
value|(OPENSSL_STRING *)sk_pop(CHECKED_STACK_OF(OPENSSL_PSTRING, st))
define|#
directive|define
name|sk_OPENSSL_PSTRING_sort
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_sort(OPENSSL_PSTRING, (st))
define|#
directive|define
name|sk_OPENSSL_PSTRING_is_sorted
parameter_list|(
name|st
parameter_list|)
value|SKM_sk_is_sorted(OPENSSL_PSTRING, (st))
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
define|#
directive|define
name|d2i_ASN1_SET_OF_ASN1_UTF8STRING
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
value|SKM_ASN1_SET_OF_d2i(ASN1_UTF8STRING, (st), (pp), (length), (d2i_func), (free_func), (ex_tag), (ex_class))
define|#
directive|define
name|i2d_ASN1_SET_OF_ASN1_UTF8STRING
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
value|SKM_ASN1_SET_OF_i2d(ASN1_UTF8STRING, (st), (pp), (i2d_func), (ex_tag), (ex_class), (is_set))
define|#
directive|define
name|ASN1_seq_pack_ASN1_UTF8STRING
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
value|SKM_ASN1_seq_pack(ASN1_UTF8STRING, (st), (i2d_func), (buf), (len))
define|#
directive|define
name|ASN1_seq_unpack_ASN1_UTF8STRING
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
value|SKM_ASN1_seq_unpack(ASN1_UTF8STRING, (buf), (len), (d2i_func), (free_func))
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
define|#
directive|define
name|d2i_ASN1_SET_OF_ESS_CERT_ID
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
value|SKM_ASN1_SET_OF_d2i(ESS_CERT_ID, (st), (pp), (length), (d2i_func), (free_func), (ex_tag), (ex_class))
define|#
directive|define
name|i2d_ASN1_SET_OF_ESS_CERT_ID
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
value|SKM_ASN1_SET_OF_i2d(ESS_CERT_ID, (st), (pp), (i2d_func), (ex_tag), (ex_class), (is_set))
define|#
directive|define
name|ASN1_seq_pack_ESS_CERT_ID
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
value|SKM_ASN1_seq_pack(ESS_CERT_ID, (st), (i2d_func), (buf), (len))
define|#
directive|define
name|ASN1_seq_unpack_ESS_CERT_ID
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
value|SKM_ASN1_seq_unpack(ESS_CERT_ID, (buf), (len), (d2i_func), (free_func))
define|#
directive|define
name|d2i_ASN1_SET_OF_EVP_MD
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
value|SKM_ASN1_SET_OF_d2i(EVP_MD, (st), (pp), (length), (d2i_func), (free_func), (ex_tag), (ex_class))
define|#
directive|define
name|i2d_ASN1_SET_OF_EVP_MD
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
value|SKM_ASN1_SET_OF_i2d(EVP_MD, (st), (pp), (i2d_func), (ex_tag), (ex_class), (is_set))
define|#
directive|define
name|ASN1_seq_pack_EVP_MD
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
value|SKM_ASN1_seq_pack(EVP_MD, (st), (i2d_func), (buf), (len))
define|#
directive|define
name|ASN1_seq_unpack_EVP_MD
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
value|SKM_ASN1_seq_unpack(EVP_MD, (buf), (len), (d2i_func), (free_func))
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
define|#
directive|define
name|d2i_ASN1_SET_OF_OCSP_ONEREQ
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
value|SKM_ASN1_SET_OF_d2i(OCSP_ONEREQ, (st), (pp), (length), (d2i_func), (free_func), (ex_tag), (ex_class))
define|#
directive|define
name|i2d_ASN1_SET_OF_OCSP_ONEREQ
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
value|SKM_ASN1_SET_OF_i2d(OCSP_ONEREQ, (st), (pp), (i2d_func), (ex_tag), (ex_class), (is_set))
define|#
directive|define
name|ASN1_seq_pack_OCSP_ONEREQ
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
value|SKM_ASN1_seq_pack(OCSP_ONEREQ, (st), (i2d_func), (buf), (len))
define|#
directive|define
name|ASN1_seq_unpack_OCSP_ONEREQ
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
value|SKM_ASN1_seq_unpack(OCSP_ONEREQ, (buf), (len), (d2i_func), (free_func))
define|#
directive|define
name|d2i_ASN1_SET_OF_OCSP_SINGLERESP
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
value|SKM_ASN1_SET_OF_d2i(OCSP_SINGLERESP, (st), (pp), (length), (d2i_func), (free_func), (ex_tag), (ex_class))
define|#
directive|define
name|i2d_ASN1_SET_OF_OCSP_SINGLERESP
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
value|SKM_ASN1_SET_OF_i2d(OCSP_SINGLERESP, (st), (pp), (i2d_func), (ex_tag), (ex_class), (is_set))
define|#
directive|define
name|ASN1_seq_pack_OCSP_SINGLERESP
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
value|SKM_ASN1_seq_pack(OCSP_SINGLERESP, (st), (i2d_func), (buf), (len))
define|#
directive|define
name|ASN1_seq_unpack_OCSP_SINGLERESP
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
value|SKM_ASN1_seq_unpack(OCSP_SINGLERESP, (buf), (len), (d2i_func), (free_func))
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
define|#
directive|define
name|lh_ADDED_OBJ_new
parameter_list|()
value|LHM_lh_new(ADDED_OBJ,added_obj)
define|#
directive|define
name|lh_ADDED_OBJ_insert
parameter_list|(
name|lh
parameter_list|,
name|inst
parameter_list|)
value|LHM_lh_insert(ADDED_OBJ,lh,inst)
define|#
directive|define
name|lh_ADDED_OBJ_retrieve
parameter_list|(
name|lh
parameter_list|,
name|inst
parameter_list|)
value|LHM_lh_retrieve(ADDED_OBJ,lh,inst)
define|#
directive|define
name|lh_ADDED_OBJ_delete
parameter_list|(
name|lh
parameter_list|,
name|inst
parameter_list|)
value|LHM_lh_delete(ADDED_OBJ,lh,inst)
define|#
directive|define
name|lh_ADDED_OBJ_doall
parameter_list|(
name|lh
parameter_list|,
name|fn
parameter_list|)
value|LHM_lh_doall(ADDED_OBJ,lh,fn)
define|#
directive|define
name|lh_ADDED_OBJ_doall_arg
parameter_list|(
name|lh
parameter_list|,
name|fn
parameter_list|,
name|arg_type
parameter_list|,
name|arg
parameter_list|)
define|\
value|LHM_lh_doall_arg(ADDED_OBJ,lh,fn,arg_type,arg)
define|#
directive|define
name|lh_ADDED_OBJ_error
parameter_list|(
name|lh
parameter_list|)
value|LHM_lh_error(ADDED_OBJ,lh)
define|#
directive|define
name|lh_ADDED_OBJ_num_items
parameter_list|(
name|lh
parameter_list|)
value|LHM_lh_num_items(ADDED_OBJ,lh)
define|#
directive|define
name|lh_ADDED_OBJ_down_load
parameter_list|(
name|lh
parameter_list|)
value|LHM_lh_down_load(ADDED_OBJ,lh)
define|#
directive|define
name|lh_ADDED_OBJ_node_stats_bio
parameter_list|(
name|lh
parameter_list|,
name|out
parameter_list|)
define|\
value|LHM_lh_node_stats_bio(ADDED_OBJ,lh,out)
define|#
directive|define
name|lh_ADDED_OBJ_node_usage_stats_bio
parameter_list|(
name|lh
parameter_list|,
name|out
parameter_list|)
define|\
value|LHM_lh_node_usage_stats_bio(ADDED_OBJ,lh,out)
define|#
directive|define
name|lh_ADDED_OBJ_stats_bio
parameter_list|(
name|lh
parameter_list|,
name|out
parameter_list|)
define|\
value|LHM_lh_stats_bio(ADDED_OBJ,lh,out)
define|#
directive|define
name|lh_ADDED_OBJ_free
parameter_list|(
name|lh
parameter_list|)
value|LHM_lh_free(ADDED_OBJ,lh)
define|#
directive|define
name|lh_APP_INFO_new
parameter_list|()
value|LHM_lh_new(APP_INFO,app_info)
define|#
directive|define
name|lh_APP_INFO_insert
parameter_list|(
name|lh
parameter_list|,
name|inst
parameter_list|)
value|LHM_lh_insert(APP_INFO,lh,inst)
define|#
directive|define
name|lh_APP_INFO_retrieve
parameter_list|(
name|lh
parameter_list|,
name|inst
parameter_list|)
value|LHM_lh_retrieve(APP_INFO,lh,inst)
define|#
directive|define
name|lh_APP_INFO_delete
parameter_list|(
name|lh
parameter_list|,
name|inst
parameter_list|)
value|LHM_lh_delete(APP_INFO,lh,inst)
define|#
directive|define
name|lh_APP_INFO_doall
parameter_list|(
name|lh
parameter_list|,
name|fn
parameter_list|)
value|LHM_lh_doall(APP_INFO,lh,fn)
define|#
directive|define
name|lh_APP_INFO_doall_arg
parameter_list|(
name|lh
parameter_list|,
name|fn
parameter_list|,
name|arg_type
parameter_list|,
name|arg
parameter_list|)
define|\
value|LHM_lh_doall_arg(APP_INFO,lh,fn,arg_type,arg)
define|#
directive|define
name|lh_APP_INFO_error
parameter_list|(
name|lh
parameter_list|)
value|LHM_lh_error(APP_INFO,lh)
define|#
directive|define
name|lh_APP_INFO_num_items
parameter_list|(
name|lh
parameter_list|)
value|LHM_lh_num_items(APP_INFO,lh)
define|#
directive|define
name|lh_APP_INFO_down_load
parameter_list|(
name|lh
parameter_list|)
value|LHM_lh_down_load(APP_INFO,lh)
define|#
directive|define
name|lh_APP_INFO_node_stats_bio
parameter_list|(
name|lh
parameter_list|,
name|out
parameter_list|)
define|\
value|LHM_lh_node_stats_bio(APP_INFO,lh,out)
define|#
directive|define
name|lh_APP_INFO_node_usage_stats_bio
parameter_list|(
name|lh
parameter_list|,
name|out
parameter_list|)
define|\
value|LHM_lh_node_usage_stats_bio(APP_INFO,lh,out)
define|#
directive|define
name|lh_APP_INFO_stats_bio
parameter_list|(
name|lh
parameter_list|,
name|out
parameter_list|)
define|\
value|LHM_lh_stats_bio(APP_INFO,lh,out)
define|#
directive|define
name|lh_APP_INFO_free
parameter_list|(
name|lh
parameter_list|)
value|LHM_lh_free(APP_INFO,lh)
define|#
directive|define
name|lh_CONF_VALUE_new
parameter_list|()
value|LHM_lh_new(CONF_VALUE,conf_value)
define|#
directive|define
name|lh_CONF_VALUE_insert
parameter_list|(
name|lh
parameter_list|,
name|inst
parameter_list|)
value|LHM_lh_insert(CONF_VALUE,lh,inst)
define|#
directive|define
name|lh_CONF_VALUE_retrieve
parameter_list|(
name|lh
parameter_list|,
name|inst
parameter_list|)
value|LHM_lh_retrieve(CONF_VALUE,lh,inst)
define|#
directive|define
name|lh_CONF_VALUE_delete
parameter_list|(
name|lh
parameter_list|,
name|inst
parameter_list|)
value|LHM_lh_delete(CONF_VALUE,lh,inst)
define|#
directive|define
name|lh_CONF_VALUE_doall
parameter_list|(
name|lh
parameter_list|,
name|fn
parameter_list|)
value|LHM_lh_doall(CONF_VALUE,lh,fn)
define|#
directive|define
name|lh_CONF_VALUE_doall_arg
parameter_list|(
name|lh
parameter_list|,
name|fn
parameter_list|,
name|arg_type
parameter_list|,
name|arg
parameter_list|)
define|\
value|LHM_lh_doall_arg(CONF_VALUE,lh,fn,arg_type,arg)
define|#
directive|define
name|lh_CONF_VALUE_error
parameter_list|(
name|lh
parameter_list|)
value|LHM_lh_error(CONF_VALUE,lh)
define|#
directive|define
name|lh_CONF_VALUE_num_items
parameter_list|(
name|lh
parameter_list|)
value|LHM_lh_num_items(CONF_VALUE,lh)
define|#
directive|define
name|lh_CONF_VALUE_down_load
parameter_list|(
name|lh
parameter_list|)
value|LHM_lh_down_load(CONF_VALUE,lh)
define|#
directive|define
name|lh_CONF_VALUE_node_stats_bio
parameter_list|(
name|lh
parameter_list|,
name|out
parameter_list|)
define|\
value|LHM_lh_node_stats_bio(CONF_VALUE,lh,out)
define|#
directive|define
name|lh_CONF_VALUE_node_usage_stats_bio
parameter_list|(
name|lh
parameter_list|,
name|out
parameter_list|)
define|\
value|LHM_lh_node_usage_stats_bio(CONF_VALUE,lh,out)
define|#
directive|define
name|lh_CONF_VALUE_stats_bio
parameter_list|(
name|lh
parameter_list|,
name|out
parameter_list|)
define|\
value|LHM_lh_stats_bio(CONF_VALUE,lh,out)
define|#
directive|define
name|lh_CONF_VALUE_free
parameter_list|(
name|lh
parameter_list|)
value|LHM_lh_free(CONF_VALUE,lh)
define|#
directive|define
name|lh_ENGINE_PILE_new
parameter_list|()
value|LHM_lh_new(ENGINE_PILE,engine_pile)
define|#
directive|define
name|lh_ENGINE_PILE_insert
parameter_list|(
name|lh
parameter_list|,
name|inst
parameter_list|)
value|LHM_lh_insert(ENGINE_PILE,lh,inst)
define|#
directive|define
name|lh_ENGINE_PILE_retrieve
parameter_list|(
name|lh
parameter_list|,
name|inst
parameter_list|)
value|LHM_lh_retrieve(ENGINE_PILE,lh,inst)
define|#
directive|define
name|lh_ENGINE_PILE_delete
parameter_list|(
name|lh
parameter_list|,
name|inst
parameter_list|)
value|LHM_lh_delete(ENGINE_PILE,lh,inst)
define|#
directive|define
name|lh_ENGINE_PILE_doall
parameter_list|(
name|lh
parameter_list|,
name|fn
parameter_list|)
value|LHM_lh_doall(ENGINE_PILE,lh,fn)
define|#
directive|define
name|lh_ENGINE_PILE_doall_arg
parameter_list|(
name|lh
parameter_list|,
name|fn
parameter_list|,
name|arg_type
parameter_list|,
name|arg
parameter_list|)
define|\
value|LHM_lh_doall_arg(ENGINE_PILE,lh,fn,arg_type,arg)
define|#
directive|define
name|lh_ENGINE_PILE_error
parameter_list|(
name|lh
parameter_list|)
value|LHM_lh_error(ENGINE_PILE,lh)
define|#
directive|define
name|lh_ENGINE_PILE_num_items
parameter_list|(
name|lh
parameter_list|)
value|LHM_lh_num_items(ENGINE_PILE,lh)
define|#
directive|define
name|lh_ENGINE_PILE_down_load
parameter_list|(
name|lh
parameter_list|)
value|LHM_lh_down_load(ENGINE_PILE,lh)
define|#
directive|define
name|lh_ENGINE_PILE_node_stats_bio
parameter_list|(
name|lh
parameter_list|,
name|out
parameter_list|)
define|\
value|LHM_lh_node_stats_bio(ENGINE_PILE,lh,out)
define|#
directive|define
name|lh_ENGINE_PILE_node_usage_stats_bio
parameter_list|(
name|lh
parameter_list|,
name|out
parameter_list|)
define|\
value|LHM_lh_node_usage_stats_bio(ENGINE_PILE,lh,out)
define|#
directive|define
name|lh_ENGINE_PILE_stats_bio
parameter_list|(
name|lh
parameter_list|,
name|out
parameter_list|)
define|\
value|LHM_lh_stats_bio(ENGINE_PILE,lh,out)
define|#
directive|define
name|lh_ENGINE_PILE_free
parameter_list|(
name|lh
parameter_list|)
value|LHM_lh_free(ENGINE_PILE,lh)
define|#
directive|define
name|lh_ERR_STATE_new
parameter_list|()
value|LHM_lh_new(ERR_STATE,err_state)
define|#
directive|define
name|lh_ERR_STATE_insert
parameter_list|(
name|lh
parameter_list|,
name|inst
parameter_list|)
value|LHM_lh_insert(ERR_STATE,lh,inst)
define|#
directive|define
name|lh_ERR_STATE_retrieve
parameter_list|(
name|lh
parameter_list|,
name|inst
parameter_list|)
value|LHM_lh_retrieve(ERR_STATE,lh,inst)
define|#
directive|define
name|lh_ERR_STATE_delete
parameter_list|(
name|lh
parameter_list|,
name|inst
parameter_list|)
value|LHM_lh_delete(ERR_STATE,lh,inst)
define|#
directive|define
name|lh_ERR_STATE_doall
parameter_list|(
name|lh
parameter_list|,
name|fn
parameter_list|)
value|LHM_lh_doall(ERR_STATE,lh,fn)
define|#
directive|define
name|lh_ERR_STATE_doall_arg
parameter_list|(
name|lh
parameter_list|,
name|fn
parameter_list|,
name|arg_type
parameter_list|,
name|arg
parameter_list|)
define|\
value|LHM_lh_doall_arg(ERR_STATE,lh,fn,arg_type,arg)
define|#
directive|define
name|lh_ERR_STATE_error
parameter_list|(
name|lh
parameter_list|)
value|LHM_lh_error(ERR_STATE,lh)
define|#
directive|define
name|lh_ERR_STATE_num_items
parameter_list|(
name|lh
parameter_list|)
value|LHM_lh_num_items(ERR_STATE,lh)
define|#
directive|define
name|lh_ERR_STATE_down_load
parameter_list|(
name|lh
parameter_list|)
value|LHM_lh_down_load(ERR_STATE,lh)
define|#
directive|define
name|lh_ERR_STATE_node_stats_bio
parameter_list|(
name|lh
parameter_list|,
name|out
parameter_list|)
define|\
value|LHM_lh_node_stats_bio(ERR_STATE,lh,out)
define|#
directive|define
name|lh_ERR_STATE_node_usage_stats_bio
parameter_list|(
name|lh
parameter_list|,
name|out
parameter_list|)
define|\
value|LHM_lh_node_usage_stats_bio(ERR_STATE,lh,out)
define|#
directive|define
name|lh_ERR_STATE_stats_bio
parameter_list|(
name|lh
parameter_list|,
name|out
parameter_list|)
define|\
value|LHM_lh_stats_bio(ERR_STATE,lh,out)
define|#
directive|define
name|lh_ERR_STATE_free
parameter_list|(
name|lh
parameter_list|)
value|LHM_lh_free(ERR_STATE,lh)
define|#
directive|define
name|lh_ERR_STRING_DATA_new
parameter_list|()
value|LHM_lh_new(ERR_STRING_DATA,err_string_data)
define|#
directive|define
name|lh_ERR_STRING_DATA_insert
parameter_list|(
name|lh
parameter_list|,
name|inst
parameter_list|)
value|LHM_lh_insert(ERR_STRING_DATA,lh,inst)
define|#
directive|define
name|lh_ERR_STRING_DATA_retrieve
parameter_list|(
name|lh
parameter_list|,
name|inst
parameter_list|)
value|LHM_lh_retrieve(ERR_STRING_DATA,lh,inst)
define|#
directive|define
name|lh_ERR_STRING_DATA_delete
parameter_list|(
name|lh
parameter_list|,
name|inst
parameter_list|)
value|LHM_lh_delete(ERR_STRING_DATA,lh,inst)
define|#
directive|define
name|lh_ERR_STRING_DATA_doall
parameter_list|(
name|lh
parameter_list|,
name|fn
parameter_list|)
value|LHM_lh_doall(ERR_STRING_DATA,lh,fn)
define|#
directive|define
name|lh_ERR_STRING_DATA_doall_arg
parameter_list|(
name|lh
parameter_list|,
name|fn
parameter_list|,
name|arg_type
parameter_list|,
name|arg
parameter_list|)
define|\
value|LHM_lh_doall_arg(ERR_STRING_DATA,lh,fn,arg_type,arg)
define|#
directive|define
name|lh_ERR_STRING_DATA_error
parameter_list|(
name|lh
parameter_list|)
value|LHM_lh_error(ERR_STRING_DATA,lh)
define|#
directive|define
name|lh_ERR_STRING_DATA_num_items
parameter_list|(
name|lh
parameter_list|)
value|LHM_lh_num_items(ERR_STRING_DATA,lh)
define|#
directive|define
name|lh_ERR_STRING_DATA_down_load
parameter_list|(
name|lh
parameter_list|)
value|LHM_lh_down_load(ERR_STRING_DATA,lh)
define|#
directive|define
name|lh_ERR_STRING_DATA_node_stats_bio
parameter_list|(
name|lh
parameter_list|,
name|out
parameter_list|)
define|\
value|LHM_lh_node_stats_bio(ERR_STRING_DATA,lh,out)
define|#
directive|define
name|lh_ERR_STRING_DATA_node_usage_stats_bio
parameter_list|(
name|lh
parameter_list|,
name|out
parameter_list|)
define|\
value|LHM_lh_node_usage_stats_bio(ERR_STRING_DATA,lh,out)
define|#
directive|define
name|lh_ERR_STRING_DATA_stats_bio
parameter_list|(
name|lh
parameter_list|,
name|out
parameter_list|)
define|\
value|LHM_lh_stats_bio(ERR_STRING_DATA,lh,out)
define|#
directive|define
name|lh_ERR_STRING_DATA_free
parameter_list|(
name|lh
parameter_list|)
value|LHM_lh_free(ERR_STRING_DATA,lh)
define|#
directive|define
name|lh_EX_CLASS_ITEM_new
parameter_list|()
value|LHM_lh_new(EX_CLASS_ITEM,ex_class_item)
define|#
directive|define
name|lh_EX_CLASS_ITEM_insert
parameter_list|(
name|lh
parameter_list|,
name|inst
parameter_list|)
value|LHM_lh_insert(EX_CLASS_ITEM,lh,inst)
define|#
directive|define
name|lh_EX_CLASS_ITEM_retrieve
parameter_list|(
name|lh
parameter_list|,
name|inst
parameter_list|)
value|LHM_lh_retrieve(EX_CLASS_ITEM,lh,inst)
define|#
directive|define
name|lh_EX_CLASS_ITEM_delete
parameter_list|(
name|lh
parameter_list|,
name|inst
parameter_list|)
value|LHM_lh_delete(EX_CLASS_ITEM,lh,inst)
define|#
directive|define
name|lh_EX_CLASS_ITEM_doall
parameter_list|(
name|lh
parameter_list|,
name|fn
parameter_list|)
value|LHM_lh_doall(EX_CLASS_ITEM,lh,fn)
define|#
directive|define
name|lh_EX_CLASS_ITEM_doall_arg
parameter_list|(
name|lh
parameter_list|,
name|fn
parameter_list|,
name|arg_type
parameter_list|,
name|arg
parameter_list|)
define|\
value|LHM_lh_doall_arg(EX_CLASS_ITEM,lh,fn,arg_type,arg)
define|#
directive|define
name|lh_EX_CLASS_ITEM_error
parameter_list|(
name|lh
parameter_list|)
value|LHM_lh_error(EX_CLASS_ITEM,lh)
define|#
directive|define
name|lh_EX_CLASS_ITEM_num_items
parameter_list|(
name|lh
parameter_list|)
value|LHM_lh_num_items(EX_CLASS_ITEM,lh)
define|#
directive|define
name|lh_EX_CLASS_ITEM_down_load
parameter_list|(
name|lh
parameter_list|)
value|LHM_lh_down_load(EX_CLASS_ITEM,lh)
define|#
directive|define
name|lh_EX_CLASS_ITEM_node_stats_bio
parameter_list|(
name|lh
parameter_list|,
name|out
parameter_list|)
define|\
value|LHM_lh_node_stats_bio(EX_CLASS_ITEM,lh,out)
define|#
directive|define
name|lh_EX_CLASS_ITEM_node_usage_stats_bio
parameter_list|(
name|lh
parameter_list|,
name|out
parameter_list|)
define|\
value|LHM_lh_node_usage_stats_bio(EX_CLASS_ITEM,lh,out)
define|#
directive|define
name|lh_EX_CLASS_ITEM_stats_bio
parameter_list|(
name|lh
parameter_list|,
name|out
parameter_list|)
define|\
value|LHM_lh_stats_bio(EX_CLASS_ITEM,lh,out)
define|#
directive|define
name|lh_EX_CLASS_ITEM_free
parameter_list|(
name|lh
parameter_list|)
value|LHM_lh_free(EX_CLASS_ITEM,lh)
define|#
directive|define
name|lh_FUNCTION_new
parameter_list|()
value|LHM_lh_new(FUNCTION,function)
define|#
directive|define
name|lh_FUNCTION_insert
parameter_list|(
name|lh
parameter_list|,
name|inst
parameter_list|)
value|LHM_lh_insert(FUNCTION,lh,inst)
define|#
directive|define
name|lh_FUNCTION_retrieve
parameter_list|(
name|lh
parameter_list|,
name|inst
parameter_list|)
value|LHM_lh_retrieve(FUNCTION,lh,inst)
define|#
directive|define
name|lh_FUNCTION_delete
parameter_list|(
name|lh
parameter_list|,
name|inst
parameter_list|)
value|LHM_lh_delete(FUNCTION,lh,inst)
define|#
directive|define
name|lh_FUNCTION_doall
parameter_list|(
name|lh
parameter_list|,
name|fn
parameter_list|)
value|LHM_lh_doall(FUNCTION,lh,fn)
define|#
directive|define
name|lh_FUNCTION_doall_arg
parameter_list|(
name|lh
parameter_list|,
name|fn
parameter_list|,
name|arg_type
parameter_list|,
name|arg
parameter_list|)
define|\
value|LHM_lh_doall_arg(FUNCTION,lh,fn,arg_type,arg)
define|#
directive|define
name|lh_FUNCTION_error
parameter_list|(
name|lh
parameter_list|)
value|LHM_lh_error(FUNCTION,lh)
define|#
directive|define
name|lh_FUNCTION_num_items
parameter_list|(
name|lh
parameter_list|)
value|LHM_lh_num_items(FUNCTION,lh)
define|#
directive|define
name|lh_FUNCTION_down_load
parameter_list|(
name|lh
parameter_list|)
value|LHM_lh_down_load(FUNCTION,lh)
define|#
directive|define
name|lh_FUNCTION_node_stats_bio
parameter_list|(
name|lh
parameter_list|,
name|out
parameter_list|)
define|\
value|LHM_lh_node_stats_bio(FUNCTION,lh,out)
define|#
directive|define
name|lh_FUNCTION_node_usage_stats_bio
parameter_list|(
name|lh
parameter_list|,
name|out
parameter_list|)
define|\
value|LHM_lh_node_usage_stats_bio(FUNCTION,lh,out)
define|#
directive|define
name|lh_FUNCTION_stats_bio
parameter_list|(
name|lh
parameter_list|,
name|out
parameter_list|)
define|\
value|LHM_lh_stats_bio(FUNCTION,lh,out)
define|#
directive|define
name|lh_FUNCTION_free
parameter_list|(
name|lh
parameter_list|)
value|LHM_lh_free(FUNCTION,lh)
define|#
directive|define
name|lh_MEM_new
parameter_list|()
value|LHM_lh_new(MEM,mem)
define|#
directive|define
name|lh_MEM_insert
parameter_list|(
name|lh
parameter_list|,
name|inst
parameter_list|)
value|LHM_lh_insert(MEM,lh,inst)
define|#
directive|define
name|lh_MEM_retrieve
parameter_list|(
name|lh
parameter_list|,
name|inst
parameter_list|)
value|LHM_lh_retrieve(MEM,lh,inst)
define|#
directive|define
name|lh_MEM_delete
parameter_list|(
name|lh
parameter_list|,
name|inst
parameter_list|)
value|LHM_lh_delete(MEM,lh,inst)
define|#
directive|define
name|lh_MEM_doall
parameter_list|(
name|lh
parameter_list|,
name|fn
parameter_list|)
value|LHM_lh_doall(MEM,lh,fn)
define|#
directive|define
name|lh_MEM_doall_arg
parameter_list|(
name|lh
parameter_list|,
name|fn
parameter_list|,
name|arg_type
parameter_list|,
name|arg
parameter_list|)
define|\
value|LHM_lh_doall_arg(MEM,lh,fn,arg_type,arg)
define|#
directive|define
name|lh_MEM_error
parameter_list|(
name|lh
parameter_list|)
value|LHM_lh_error(MEM,lh)
define|#
directive|define
name|lh_MEM_num_items
parameter_list|(
name|lh
parameter_list|)
value|LHM_lh_num_items(MEM,lh)
define|#
directive|define
name|lh_MEM_down_load
parameter_list|(
name|lh
parameter_list|)
value|LHM_lh_down_load(MEM,lh)
define|#
directive|define
name|lh_MEM_node_stats_bio
parameter_list|(
name|lh
parameter_list|,
name|out
parameter_list|)
define|\
value|LHM_lh_node_stats_bio(MEM,lh,out)
define|#
directive|define
name|lh_MEM_node_usage_stats_bio
parameter_list|(
name|lh
parameter_list|,
name|out
parameter_list|)
define|\
value|LHM_lh_node_usage_stats_bio(MEM,lh,out)
define|#
directive|define
name|lh_MEM_stats_bio
parameter_list|(
name|lh
parameter_list|,
name|out
parameter_list|)
define|\
value|LHM_lh_stats_bio(MEM,lh,out)
define|#
directive|define
name|lh_MEM_free
parameter_list|(
name|lh
parameter_list|)
value|LHM_lh_free(MEM,lh)
define|#
directive|define
name|lh_OBJ_NAME_new
parameter_list|()
value|LHM_lh_new(OBJ_NAME,obj_name)
define|#
directive|define
name|lh_OBJ_NAME_insert
parameter_list|(
name|lh
parameter_list|,
name|inst
parameter_list|)
value|LHM_lh_insert(OBJ_NAME,lh,inst)
define|#
directive|define
name|lh_OBJ_NAME_retrieve
parameter_list|(
name|lh
parameter_list|,
name|inst
parameter_list|)
value|LHM_lh_retrieve(OBJ_NAME,lh,inst)
define|#
directive|define
name|lh_OBJ_NAME_delete
parameter_list|(
name|lh
parameter_list|,
name|inst
parameter_list|)
value|LHM_lh_delete(OBJ_NAME,lh,inst)
define|#
directive|define
name|lh_OBJ_NAME_doall
parameter_list|(
name|lh
parameter_list|,
name|fn
parameter_list|)
value|LHM_lh_doall(OBJ_NAME,lh,fn)
define|#
directive|define
name|lh_OBJ_NAME_doall_arg
parameter_list|(
name|lh
parameter_list|,
name|fn
parameter_list|,
name|arg_type
parameter_list|,
name|arg
parameter_list|)
define|\
value|LHM_lh_doall_arg(OBJ_NAME,lh,fn,arg_type,arg)
define|#
directive|define
name|lh_OBJ_NAME_error
parameter_list|(
name|lh
parameter_list|)
value|LHM_lh_error(OBJ_NAME,lh)
define|#
directive|define
name|lh_OBJ_NAME_num_items
parameter_list|(
name|lh
parameter_list|)
value|LHM_lh_num_items(OBJ_NAME,lh)
define|#
directive|define
name|lh_OBJ_NAME_down_load
parameter_list|(
name|lh
parameter_list|)
value|LHM_lh_down_load(OBJ_NAME,lh)
define|#
directive|define
name|lh_OBJ_NAME_node_stats_bio
parameter_list|(
name|lh
parameter_list|,
name|out
parameter_list|)
define|\
value|LHM_lh_node_stats_bio(OBJ_NAME,lh,out)
define|#
directive|define
name|lh_OBJ_NAME_node_usage_stats_bio
parameter_list|(
name|lh
parameter_list|,
name|out
parameter_list|)
define|\
value|LHM_lh_node_usage_stats_bio(OBJ_NAME,lh,out)
define|#
directive|define
name|lh_OBJ_NAME_stats_bio
parameter_list|(
name|lh
parameter_list|,
name|out
parameter_list|)
define|\
value|LHM_lh_stats_bio(OBJ_NAME,lh,out)
define|#
directive|define
name|lh_OBJ_NAME_free
parameter_list|(
name|lh
parameter_list|)
value|LHM_lh_free(OBJ_NAME,lh)
define|#
directive|define
name|lh_OPENSSL_CSTRING_new
parameter_list|()
value|LHM_lh_new(OPENSSL_CSTRING,openssl_cstring)
define|#
directive|define
name|lh_OPENSSL_CSTRING_insert
parameter_list|(
name|lh
parameter_list|,
name|inst
parameter_list|)
value|LHM_lh_insert(OPENSSL_CSTRING,lh,inst)
define|#
directive|define
name|lh_OPENSSL_CSTRING_retrieve
parameter_list|(
name|lh
parameter_list|,
name|inst
parameter_list|)
value|LHM_lh_retrieve(OPENSSL_CSTRING,lh,inst)
define|#
directive|define
name|lh_OPENSSL_CSTRING_delete
parameter_list|(
name|lh
parameter_list|,
name|inst
parameter_list|)
value|LHM_lh_delete(OPENSSL_CSTRING,lh,inst)
define|#
directive|define
name|lh_OPENSSL_CSTRING_doall
parameter_list|(
name|lh
parameter_list|,
name|fn
parameter_list|)
value|LHM_lh_doall(OPENSSL_CSTRING,lh,fn)
define|#
directive|define
name|lh_OPENSSL_CSTRING_doall_arg
parameter_list|(
name|lh
parameter_list|,
name|fn
parameter_list|,
name|arg_type
parameter_list|,
name|arg
parameter_list|)
define|\
value|LHM_lh_doall_arg(OPENSSL_CSTRING,lh,fn,arg_type,arg)
define|#
directive|define
name|lh_OPENSSL_CSTRING_error
parameter_list|(
name|lh
parameter_list|)
value|LHM_lh_error(OPENSSL_CSTRING,lh)
define|#
directive|define
name|lh_OPENSSL_CSTRING_num_items
parameter_list|(
name|lh
parameter_list|)
value|LHM_lh_num_items(OPENSSL_CSTRING,lh)
define|#
directive|define
name|lh_OPENSSL_CSTRING_down_load
parameter_list|(
name|lh
parameter_list|)
value|LHM_lh_down_load(OPENSSL_CSTRING,lh)
define|#
directive|define
name|lh_OPENSSL_CSTRING_node_stats_bio
parameter_list|(
name|lh
parameter_list|,
name|out
parameter_list|)
define|\
value|LHM_lh_node_stats_bio(OPENSSL_CSTRING,lh,out)
define|#
directive|define
name|lh_OPENSSL_CSTRING_node_usage_stats_bio
parameter_list|(
name|lh
parameter_list|,
name|out
parameter_list|)
define|\
value|LHM_lh_node_usage_stats_bio(OPENSSL_CSTRING,lh,out)
define|#
directive|define
name|lh_OPENSSL_CSTRING_stats_bio
parameter_list|(
name|lh
parameter_list|,
name|out
parameter_list|)
define|\
value|LHM_lh_stats_bio(OPENSSL_CSTRING,lh,out)
define|#
directive|define
name|lh_OPENSSL_CSTRING_free
parameter_list|(
name|lh
parameter_list|)
value|LHM_lh_free(OPENSSL_CSTRING,lh)
define|#
directive|define
name|lh_OPENSSL_STRING_new
parameter_list|()
value|LHM_lh_new(OPENSSL_STRING,openssl_string)
define|#
directive|define
name|lh_OPENSSL_STRING_insert
parameter_list|(
name|lh
parameter_list|,
name|inst
parameter_list|)
value|LHM_lh_insert(OPENSSL_STRING,lh,inst)
define|#
directive|define
name|lh_OPENSSL_STRING_retrieve
parameter_list|(
name|lh
parameter_list|,
name|inst
parameter_list|)
value|LHM_lh_retrieve(OPENSSL_STRING,lh,inst)
define|#
directive|define
name|lh_OPENSSL_STRING_delete
parameter_list|(
name|lh
parameter_list|,
name|inst
parameter_list|)
value|LHM_lh_delete(OPENSSL_STRING,lh,inst)
define|#
directive|define
name|lh_OPENSSL_STRING_doall
parameter_list|(
name|lh
parameter_list|,
name|fn
parameter_list|)
value|LHM_lh_doall(OPENSSL_STRING,lh,fn)
define|#
directive|define
name|lh_OPENSSL_STRING_doall_arg
parameter_list|(
name|lh
parameter_list|,
name|fn
parameter_list|,
name|arg_type
parameter_list|,
name|arg
parameter_list|)
define|\
value|LHM_lh_doall_arg(OPENSSL_STRING,lh,fn,arg_type,arg)
define|#
directive|define
name|lh_OPENSSL_STRING_error
parameter_list|(
name|lh
parameter_list|)
value|LHM_lh_error(OPENSSL_STRING,lh)
define|#
directive|define
name|lh_OPENSSL_STRING_num_items
parameter_list|(
name|lh
parameter_list|)
value|LHM_lh_num_items(OPENSSL_STRING,lh)
define|#
directive|define
name|lh_OPENSSL_STRING_down_load
parameter_list|(
name|lh
parameter_list|)
value|LHM_lh_down_load(OPENSSL_STRING,lh)
define|#
directive|define
name|lh_OPENSSL_STRING_node_stats_bio
parameter_list|(
name|lh
parameter_list|,
name|out
parameter_list|)
define|\
value|LHM_lh_node_stats_bio(OPENSSL_STRING,lh,out)
define|#
directive|define
name|lh_OPENSSL_STRING_node_usage_stats_bio
parameter_list|(
name|lh
parameter_list|,
name|out
parameter_list|)
define|\
value|LHM_lh_node_usage_stats_bio(OPENSSL_STRING,lh,out)
define|#
directive|define
name|lh_OPENSSL_STRING_stats_bio
parameter_list|(
name|lh
parameter_list|,
name|out
parameter_list|)
define|\
value|LHM_lh_stats_bio(OPENSSL_STRING,lh,out)
define|#
directive|define
name|lh_OPENSSL_STRING_free
parameter_list|(
name|lh
parameter_list|)
value|LHM_lh_free(OPENSSL_STRING,lh)
define|#
directive|define
name|lh_SSL_SESSION_new
parameter_list|()
value|LHM_lh_new(SSL_SESSION,ssl_session)
define|#
directive|define
name|lh_SSL_SESSION_insert
parameter_list|(
name|lh
parameter_list|,
name|inst
parameter_list|)
value|LHM_lh_insert(SSL_SESSION,lh,inst)
define|#
directive|define
name|lh_SSL_SESSION_retrieve
parameter_list|(
name|lh
parameter_list|,
name|inst
parameter_list|)
value|LHM_lh_retrieve(SSL_SESSION,lh,inst)
define|#
directive|define
name|lh_SSL_SESSION_delete
parameter_list|(
name|lh
parameter_list|,
name|inst
parameter_list|)
value|LHM_lh_delete(SSL_SESSION,lh,inst)
define|#
directive|define
name|lh_SSL_SESSION_doall
parameter_list|(
name|lh
parameter_list|,
name|fn
parameter_list|)
value|LHM_lh_doall(SSL_SESSION,lh,fn)
define|#
directive|define
name|lh_SSL_SESSION_doall_arg
parameter_list|(
name|lh
parameter_list|,
name|fn
parameter_list|,
name|arg_type
parameter_list|,
name|arg
parameter_list|)
define|\
value|LHM_lh_doall_arg(SSL_SESSION,lh,fn,arg_type,arg)
define|#
directive|define
name|lh_SSL_SESSION_error
parameter_list|(
name|lh
parameter_list|)
value|LHM_lh_error(SSL_SESSION,lh)
define|#
directive|define
name|lh_SSL_SESSION_num_items
parameter_list|(
name|lh
parameter_list|)
value|LHM_lh_num_items(SSL_SESSION,lh)
define|#
directive|define
name|lh_SSL_SESSION_down_load
parameter_list|(
name|lh
parameter_list|)
value|LHM_lh_down_load(SSL_SESSION,lh)
define|#
directive|define
name|lh_SSL_SESSION_node_stats_bio
parameter_list|(
name|lh
parameter_list|,
name|out
parameter_list|)
define|\
value|LHM_lh_node_stats_bio(SSL_SESSION,lh,out)
define|#
directive|define
name|lh_SSL_SESSION_node_usage_stats_bio
parameter_list|(
name|lh
parameter_list|,
name|out
parameter_list|)
define|\
value|LHM_lh_node_usage_stats_bio(SSL_SESSION,lh,out)
define|#
directive|define
name|lh_SSL_SESSION_stats_bio
parameter_list|(
name|lh
parameter_list|,
name|out
parameter_list|)
define|\
value|LHM_lh_stats_bio(SSL_SESSION,lh,out)
define|#
directive|define
name|lh_SSL_SESSION_free
parameter_list|(
name|lh
parameter_list|)
value|LHM_lh_free(SSL_SESSION,lh)
comment|/* End of util/mkstack.pl block, you may now edit :-) */
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
comment|/* !defined HEADER_SAFESTACK_H */
end_comment

end_unit

