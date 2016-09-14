begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2005-2008 Poul-Henning Kamp  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_define
define|#
directive|define
name|ALLOC_OBJ
parameter_list|(
name|to
parameter_list|,
name|type_magic
parameter_list|)
define|\
value|do {								\ 		(to) = calloc(1, sizeof *(to));				\ 		if ((to) != NULL)					\ 			(to)->magic = (type_magic);			\ 	} while (0)
end_define

begin_define
define|#
directive|define
name|FREE_OBJ
parameter_list|(
name|to
parameter_list|)
define|\
value|do {								\ 		(to)->magic = (0);					\ 		free(to);						\ 	} while (0)
end_define

begin_define
define|#
directive|define
name|VALID_OBJ
parameter_list|(
name|ptr
parameter_list|,
name|type_magic
parameter_list|)
define|\
value|((ptr) != NULL&& (ptr)->magic == (type_magic))
end_define

begin_define
define|#
directive|define
name|CHECK_OBJ
parameter_list|(
name|ptr
parameter_list|,
name|type_magic
parameter_list|)
define|\
value|do {								\ 		assert((ptr)->magic == type_magic);			\ 	} while (0)
end_define

begin_define
define|#
directive|define
name|CHECK_OBJ_NOTNULL
parameter_list|(
name|ptr
parameter_list|,
name|type_magic
parameter_list|)
define|\
value|do {								\ 		assert((ptr) != NULL);					\ 		assert((ptr)->magic == type_magic);			\ 	} while (0)
end_define

begin_define
define|#
directive|define
name|CHECK_OBJ_ORNULL
parameter_list|(
name|ptr
parameter_list|,
name|type_magic
parameter_list|)
define|\
value|do {								\ 		if ((ptr) != NULL)					\ 			assert((ptr)->magic == type_magic);		\ 	} while (0)
end_define

begin_define
define|#
directive|define
name|CAST_OBJ
parameter_list|(
name|to
parameter_list|,
name|from
parameter_list|,
name|type_magic
parameter_list|)
define|\
value|do {								\ 		(to) = (from);						\ 		if ((to) != NULL)					\ 			CHECK_OBJ((to), (type_magic));			\ 	} while (0)
end_define

begin_define
define|#
directive|define
name|CAST_OBJ_NOTNULL
parameter_list|(
name|to
parameter_list|,
name|from
parameter_list|,
name|type_magic
parameter_list|)
define|\
value|do {								\ 		(to) = (from);						\ 		assert((to) != NULL);					\ 		CHECK_OBJ((to), (type_magic));				\ 	} while (0)
end_define

end_unit

