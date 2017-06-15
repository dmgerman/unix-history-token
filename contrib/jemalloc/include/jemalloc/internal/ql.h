begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_ifndef
ifndef|#
directive|ifndef
name|JEMALLOC_INTERNAL_QL_H
end_ifndef

begin_define
define|#
directive|define
name|JEMALLOC_INTERNAL_QL_H
end_define

begin_include
include|#
directive|include
file|"jemalloc/internal/qr.h"
end_include

begin_comment
comment|/* List definitions. */
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
comment|/* JEMALLOC_INTERNAL_QL_H */
end_comment

end_unit

