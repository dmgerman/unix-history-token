begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/******************************************************************************  *  * Copyright (C) 2002 Jason Evans<jasone@FreeBSD.org>.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice(s), this list of conditions and the following disclaimer  *    unmodified other than the allowable addition of one or more  *    copyright notices.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice(s), this list of conditions and the following disclaimer in  *    the documentation and/or other materials provided with the  *    distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDER(S) ``AS IS'' AND ANY  * EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR  * PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL THE COPYRIGHT HOLDER(S) BE  * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR  * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF  * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR  * BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,  * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE  * OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,  * EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  ******************************************************************************/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|QL_H_
end_ifndef

begin_define
define|#
directive|define
name|QL_H_
end_define

begin_include
include|#
directive|include
file|<sys/cdefs.h>
end_include

begin_expr_stmt
name|__FBSDID
argument_list|(
literal|"$FreeBSD$"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/*  * List definitions.  */
end_comment

begin_define
define|#
directive|define
name|ql_head
parameter_list|(
name|a_type
parameter_list|)
define|\
value|struct {								\ 	a_type *qlh_first;						\ }
end_define

begin_define
define|#
directive|define
name|ql_head_initializer
parameter_list|(
name|a_head
parameter_list|)
value|{NULL}
end_define

begin_define
define|#
directive|define
name|ql_elm
parameter_list|(
name|a_type
parameter_list|)
value|qr(a_type)
end_define

begin_comment
comment|/* List functions. */
end_comment

begin_define
define|#
directive|define
name|ql_new
parameter_list|(
name|a_head
parameter_list|)
value|do {						\ 	(a_head)->qlh_first = NULL;					\ } while (0)
end_define

begin_define
define|#
directive|define
name|ql_elm_new
parameter_list|(
name|a_elm
parameter_list|,
name|a_field
parameter_list|)
value|qr_new((a_elm), a_field)
end_define

begin_define
define|#
directive|define
name|ql_first
parameter_list|(
name|a_head
parameter_list|)
value|((a_head)->qlh_first)
end_define

begin_define
define|#
directive|define
name|ql_last
parameter_list|(
name|a_head
parameter_list|,
name|a_field
parameter_list|)
define|\
value|((ql_first(a_head) != NULL)					\ 	    ? qr_prev(ql_first(a_head), a_field) : NULL)
end_define

begin_define
define|#
directive|define
name|ql_next
parameter_list|(
name|a_head
parameter_list|,
name|a_elm
parameter_list|,
name|a_field
parameter_list|)
define|\
value|((ql_last(a_head, a_field) != (a_elm))				\ 	    ? qr_next((a_elm), a_field)	: NULL)
end_define

begin_define
define|#
directive|define
name|ql_prev
parameter_list|(
name|a_head
parameter_list|,
name|a_elm
parameter_list|,
name|a_field
parameter_list|)
define|\
value|((ql_first(a_head) != (a_elm)) ? qr_prev((a_elm), a_field)	\ 				       : NULL)
end_define

begin_define
define|#
directive|define
name|ql_before_insert
parameter_list|(
name|a_head
parameter_list|,
name|a_qlelm
parameter_list|,
name|a_elm
parameter_list|,
name|a_field
parameter_list|)
value|do {		\ 	qr_before_insert((a_qlelm), (a_elm), a_field);			\ 	if (ql_first(a_head) == (a_qlelm)) {				\ 		ql_first(a_head) = (a_elm);				\ 	}								\ } while (0)
end_define

begin_define
define|#
directive|define
name|ql_after_insert
parameter_list|(
name|a_qlelm
parameter_list|,
name|a_elm
parameter_list|,
name|a_field
parameter_list|)
define|\
value|qr_after_insert((a_qlelm), (a_elm), a_field)
end_define

begin_define
define|#
directive|define
name|ql_head_insert
parameter_list|(
name|a_head
parameter_list|,
name|a_elm
parameter_list|,
name|a_field
parameter_list|)
value|do {			\ 	if (ql_first(a_head) != NULL) {					\ 		qr_before_insert(ql_first(a_head), (a_elm), a_field);	\ 	}								\ 	ql_first(a_head) = (a_elm);					\ } while (0)
end_define

begin_define
define|#
directive|define
name|ql_tail_insert
parameter_list|(
name|a_head
parameter_list|,
name|a_elm
parameter_list|,
name|a_field
parameter_list|)
value|do {			\ 	if (ql_first(a_head) != NULL) {					\ 		qr_before_insert(ql_first(a_head), (a_elm), a_field);	\ 	}								\ 	ql_first(a_head) = qr_next((a_elm), a_field);			\ } while (0)
end_define

begin_define
define|#
directive|define
name|ql_remove
parameter_list|(
name|a_head
parameter_list|,
name|a_elm
parameter_list|,
name|a_field
parameter_list|)
value|do {				\ 	if (ql_first(a_head) == (a_elm)) {				\ 		ql_first(a_head) = qr_next(ql_first(a_head), a_field);	\ 	}								\ 	if (ql_first(a_head) != (a_elm)) {				\ 		qr_remove((a_elm), a_field);				\ 	} else {							\ 		ql_first(a_head) = NULL;				\ 	}								\ } while (0)
end_define

begin_define
define|#
directive|define
name|ql_head_remove
parameter_list|(
name|a_head
parameter_list|,
name|a_type
parameter_list|,
name|a_field
parameter_list|)
value|do {			\ 	a_type *t = ql_first(a_head);					\ 	ql_remove((a_head), t, a_field);				\ } while (0)
end_define

begin_define
define|#
directive|define
name|ql_tail_remove
parameter_list|(
name|a_head
parameter_list|,
name|a_type
parameter_list|,
name|a_field
parameter_list|)
value|do {			\ 	a_type *t = ql_last(a_head, a_field);				\ 	ql_remove((a_head), t, a_field);				\ } while (0)
end_define

begin_define
define|#
directive|define
name|ql_foreach
parameter_list|(
name|a_var
parameter_list|,
name|a_head
parameter_list|,
name|a_field
parameter_list|)
define|\
value|qr_foreach((a_var), ql_first(a_head), a_field)
end_define

begin_define
define|#
directive|define
name|ql_reverse_foreach
parameter_list|(
name|a_var
parameter_list|,
name|a_head
parameter_list|,
name|a_field
parameter_list|)
define|\
value|qr_reverse_foreach((a_var), ql_first(a_head), a_field)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* QL_H_ */
end_comment

end_unit

