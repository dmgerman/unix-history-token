begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1997, 1998 Martin Husemann<martin@rumolt.teuto.de>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. The name of the author may not be used to endorse or promote products  *    derived from this software withough specific prior written permission  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  */
end_comment

begin_comment
comment|/*  * vararray.h: basic collection macros for variable sized (growing) arrays:  *             macro version of popular C++ template classes,  *             not as elegant in use as the template version,  *             but has maximum runtime performance and can give  *             pointers to array contents (i.e. for ioctl's).  *             Works in C as well as in C++.  * CAVEAT:     in C++ only useable for aggregateable objects,  *             it does use memcpy instead of copy constructors!  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|VARARRAY_H
end_ifndef

begin_define
define|#
directive|define
name|VARARRAY_H
end_define

begin_comment
comment|/* declare a variable sized array, element type is t */
end_comment

begin_define
define|#
directive|define
name|VARA_DECL
parameter_list|(
name|t
parameter_list|)
value|struct { int used, allocated; t *data; }
end_define

begin_comment
comment|/* aggregate initializer for a variable array */
end_comment

begin_define
define|#
directive|define
name|VARA_INITIALIZER
value|{ 0, 0, NULL }
end_define

begin_comment
comment|/* free all allocated storage */
end_comment

begin_define
define|#
directive|define
name|VARA_FREE
parameter_list|(
name|a
parameter_list|)
value|{ if ((a).data != NULL) free((a).data);         \                         (a).allocated = 0; (a).used = 0; }
end_define

begin_comment
comment|/* number of elments currently in array*/
end_comment

begin_define
define|#
directive|define
name|VARA_NUM
parameter_list|(
name|a
parameter_list|)
value|((a).used)
end_define

begin_comment
comment|/* number of elements already allocated in array */
end_comment

begin_define
define|#
directive|define
name|VARA_ALLOCATED
parameter_list|(
name|a
parameter_list|)
value|((a).allocated)
end_define

begin_comment
comment|/* pointer to array data */
end_comment

begin_define
define|#
directive|define
name|VARA_PTR
parameter_list|(
name|a
parameter_list|)
value|((a).data)
end_define

begin_comment
comment|/* empty the array */
end_comment

begin_define
define|#
directive|define
name|VARA_EMPTY
parameter_list|(
name|a
parameter_list|)
value|{ (a).used = 0; }
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|__cplusplus
end_ifdef

begin_define
define|#
directive|define
name|VARA_NEW
parameter_list|(
name|t
parameter_list|,
name|c
parameter_list|)
value|new t[c]
end_define

begin_define
define|#
directive|define
name|VARA_DELETE
parameter_list|(
name|p
parameter_list|)
value|delete [] p
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|VARA_NEW
parameter_list|(
name|t
parameter_list|,
name|c
parameter_list|)
value|(t*)malloc(sizeof(t)*(c))
end_define

begin_define
define|#
directive|define
name|VARA_DELETE
parameter_list|(
name|p
parameter_list|)
value|free(p)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* add an element (not changing any data).  * a is the array, i the index,  * t the element type and n the initial allocation  */
end_comment

begin_define
define|#
directive|define
name|VARA_ADD_AT
parameter_list|(
name|a
parameter_list|,
name|i
parameter_list|,
name|t
parameter_list|,
name|n
parameter_list|)
define|\
value|{                                                                         \         if ((i)>= (a).allocated) {                                       \                 int new_alloc = (a).allocated ? (a).allocated*2 : (n);    \                 t *new_data;                                              \                 if (new_alloc<= (i)) new_alloc = (i)+1;                  \                 new_data = VARA_NEW(t, new_alloc);                        \                 if ((a).data) {                                           \                         memcpy(new_data, (a).data, (a).used*sizeof(t));   \                         VARA_DELETE((a).data);                            \                 }                                                         \                 (a).data = new_data;                                      \                 (a).allocated = new_alloc;                                \         }                                                                 \         if ((i)>= (a).used) {                                            \                 if (i> (a).used)                                         \                         memset(&((a).data[(a).used]), 0,                  \                                         sizeof(t)*((i)-(a).used+1));      \                 (a).used = (i)+1;                                         \         }                                                                 \ }
end_define

begin_comment
comment|/* return an l-value at index i */
end_comment

begin_define
define|#
directive|define
name|VARA_AT
parameter_list|(
name|a
parameter_list|,
name|i
parameter_list|)
value|((a).data[(i)])
end_define

begin_comment
comment|/* iterate through the array */
end_comment

begin_define
define|#
directive|define
name|VARA_FOREACH
parameter_list|(
name|a
parameter_list|,
name|i
parameter_list|)
value|for ((i) = 0; (i)< (a).used; (i)++)
end_define

begin_comment
comment|/* check for a valid index */
end_comment

begin_define
define|#
directive|define
name|VARA_VALID
parameter_list|(
name|a
parameter_list|,
name|i
parameter_list|)
value|((i)>= 0&& (i)< (a).used)
end_define

begin_comment
comment|/* remove one entry */
end_comment

begin_define
define|#
directive|define
name|VARA_REMOVEAT
parameter_list|(
name|a
parameter_list|,
name|i
parameter_list|)
define|\
value|{                                                                           \   if ((i)< ((a).used -1))                                                  \     memmove(&((a).data[(i)]),&((a).data[(i)+1]), sizeof((a).data[0]));     \   (a).used--;                                                               \ }
end_define

begin_comment
comment|/* free all storage allocated for the array */
end_comment

begin_define
define|#
directive|define
name|VARA_DESTROY
parameter_list|(
name|a
parameter_list|)
define|\
value|{                                                     \   if ((a).data) VARA_DELETE((a).data);                \   (a).allocated = 0;                                  \   (a).used = 0;                                       \   (a).data = NULL;                                    \ }
end_define

begin_endif
endif|#
directive|endif
end_endif

end_unit

