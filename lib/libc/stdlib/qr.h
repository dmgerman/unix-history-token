begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/******************************************************************************  *  * Copyright (C) 2002 Jason Evans<jasone@FreeBSD.org>.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice(s), this list of conditions and the following disclaimer  *    unmodified other than the allowable addition of one or more  *    copyright notices.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice(s), this list of conditions and the following disclaimer in  *    the documentation and/or other materials provided with the  *    distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDER(S) ``AS IS'' AND ANY  * EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR  * PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL THE COPYRIGHT HOLDER(S) BE  * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR  * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF  * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR  * BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,  * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE  * OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,  * EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  ******************************************************************************/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|QR_H_
end_ifndef

begin_define
define|#
directive|define
name|QR_H_
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
comment|/* Ring definitions. */
end_comment

begin_define
define|#
directive|define
name|qr
parameter_list|(
name|a_type
parameter_list|)
define|\
value|struct {								\ 	a_type	*qre_next;						\ 	a_type	*qre_prev;						\ }
end_define

begin_comment
comment|/* Ring functions. */
end_comment

begin_define
define|#
directive|define
name|qr_new
parameter_list|(
name|a_qr
parameter_list|,
name|a_field
parameter_list|)
value|do {					\ 	(a_qr)->a_field.qre_next = (a_qr);				\ 	(a_qr)->a_field.qre_prev = (a_qr);				\ } while (0)
end_define

begin_define
define|#
directive|define
name|qr_next
parameter_list|(
name|a_qr
parameter_list|,
name|a_field
parameter_list|)
value|((a_qr)->a_field.qre_next)
end_define

begin_define
define|#
directive|define
name|qr_prev
parameter_list|(
name|a_qr
parameter_list|,
name|a_field
parameter_list|)
value|((a_qr)->a_field.qre_prev)
end_define

begin_define
define|#
directive|define
name|qr_before_insert
parameter_list|(
name|a_qrelm
parameter_list|,
name|a_qr
parameter_list|,
name|a_field
parameter_list|)
value|do {			\ 	(a_qr)->a_field.qre_prev = (a_qrelm)->a_field.qre_prev;		\ 	(a_qr)->a_field.qre_next = (a_qrelm);				\ 	(a_qr)->a_field.qre_prev->a_field.qre_next = (a_qr);		\ 	(a_qrelm)->a_field.qre_prev = (a_qr);				\ } while (0)
end_define

begin_define
define|#
directive|define
name|qr_after_insert
parameter_list|(
name|a_qrelm
parameter_list|,
name|a_qr
parameter_list|,
name|a_field
parameter_list|)
define|\
value|do									\     {									\ 	(a_qr)->a_field.qre_next = (a_qrelm)->a_field.qre_next;		\ 	(a_qr)->a_field.qre_prev = (a_qrelm);				\ 	(a_qr)->a_field.qre_next->a_field.qre_prev = (a_qr);		\ 	(a_qrelm)->a_field.qre_next = (a_qr);				\     } while (0)
end_define

begin_define
define|#
directive|define
name|qr_meld
parameter_list|(
name|a_qr_a
parameter_list|,
name|a_qr_b
parameter_list|,
name|a_field
parameter_list|)
value|do {				\ 	void *t;							\ 	(a_qr_a)->a_field.qre_prev->a_field.qre_next = (a_qr_b);	\ 	(a_qr_b)->a_field.qre_prev->a_field.qre_next = (a_qr_a);	\ 	t = (a_qr_a)->a_field.qre_prev;					\ 	(a_qr_a)->a_field.qre_prev = (a_qr_b)->a_field.qre_prev;	\ 	(a_qr_b)->a_field.qre_prev = t;					\ } while (0)
end_define

begin_comment
comment|/* qr_meld() and qr_split() are functionally equivalent, so there's no need to  * have two copies of the code. */
end_comment

begin_define
define|#
directive|define
name|qr_split
parameter_list|(
name|a_qr_a
parameter_list|,
name|a_qr_b
parameter_list|,
name|a_field
parameter_list|)
define|\
value|qr_meld((a_qr_a), (a_qr_b), a_field)
end_define

begin_define
define|#
directive|define
name|qr_remove
parameter_list|(
name|a_qr
parameter_list|,
name|a_field
parameter_list|)
value|do {					\ 	(a_qr)->a_field.qre_prev->a_field.qre_next			\ 	    = (a_qr)->a_field.qre_next;					\ 	(a_qr)->a_field.qre_next->a_field.qre_prev			\ 	    = (a_qr)->a_field.qre_prev;					\ 	(a_qr)->a_field.qre_next = (a_qr);				\ 	(a_qr)->a_field.qre_prev = (a_qr);				\ } while (0)
end_define

begin_define
define|#
directive|define
name|qr_foreach
parameter_list|(
name|var
parameter_list|,
name|a_qr
parameter_list|,
name|a_field
parameter_list|)
define|\
value|for ((var) = (a_qr);						\ 	    (var) != NULL;						\ 	    (var) = (((var)->a_field.qre_next != (a_qr))		\ 	    ? (var)->a_field.qre_next : NULL))
end_define

begin_define
define|#
directive|define
name|qr_reverse_foreach
parameter_list|(
name|var
parameter_list|,
name|a_qr
parameter_list|,
name|a_field
parameter_list|)
define|\
value|for ((var) = ((a_qr) != NULL) ? qr_prev(a_qr, a_field) : NULL;	\ 	    (var) != NULL;						\ 	    (var) = (((var) != (a_qr))					\ 	    ? (var)->a_field.qre_prev : NULL))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* QR_H_ */
end_comment

end_unit

