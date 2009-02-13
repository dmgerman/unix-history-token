begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2006 Michael Bushkov<bushman@freebsd.org>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_include
include|#
directive|include
file|<sys/queue.h>
end_include

begin_define
define|#
directive|define
name|DECLARE_TEST_DATA
parameter_list|(
name|ent
parameter_list|)
define|\
value|struct ent##_entry {							\ 	struct ent data;						\ 	STAILQ_ENTRY(ent##_entry) entries;				\ };									\ 									\ struct ent##_test_data {						\ 	void (*clone_func)(struct ent *, struct ent const *);		\ 	void (*free_func)(struct ent *);				\ 									\ 	STAILQ_HEAD(ent_head, ent##_entry) snapshot_data;		\ };									\ 									\ void __##ent##_test_data_init(struct ent##_test_data *, 		\ 	void (*)(struct ent *, struct ent const *),			\ 	void (*freef)(struct ent *));		 			\ void __##ent##_test_data_destroy(struct ent##_test_data *);		\ 									\ void __##ent##_test_data_append(struct ent##_test_data *, struct ent *data);\ int __##ent##_test_data_foreach(struct ent##_test_data *,		\ 	int (*)(struct ent *, void *), void *);				\ int __##ent##_test_data_compare(struct ent##_test_data *,		\ 	struct ent##_test_data *, int (*)(struct ent *, struct ent *,	\ 	void *), void *);						\ struct ent *__##ent##_test_data_find(struct ent##_test_data *, struct ent *,\ 	int (*)(struct ent *, struct ent *, void *), void *);		\ void __##ent##_test_data_clear(struct ent##_test_data *);
end_define

begin_define
define|#
directive|define
name|TEST_DATA_INIT
parameter_list|(
name|ent
parameter_list|,
name|td
parameter_list|,
name|clonef
parameter_list|,
name|freef
parameter_list|)
define|\
value|__##ent##_test_data_init(td, clonef, freef)
end_define

begin_define
define|#
directive|define
name|TEST_DATA_DESTROY
parameter_list|(
name|ent
parameter_list|,
name|td
parameter_list|)
value|__##ent##_test_data_destroy(td)
end_define

begin_define
define|#
directive|define
name|TEST_DATA_APPEND
parameter_list|(
name|ent
parameter_list|,
name|td
parameter_list|,
name|d
parameter_list|)
value|__##ent##_test_data_append(td, d)
end_define

begin_define
define|#
directive|define
name|TEST_DATA_FOREACH
parameter_list|(
name|ent
parameter_list|,
name|td
parameter_list|,
name|f
parameter_list|,
name|mdata
parameter_list|)
define|\
value|__##ent##_test_data_foreach(td, f, mdata)
end_define

begin_define
define|#
directive|define
name|TEST_DATA_COMPARE
parameter_list|(
name|ent
parameter_list|,
name|td1
parameter_list|,
name|td2
parameter_list|,
name|fcmp
parameter_list|,
name|mdata
parameter_list|)
define|\
value|__##ent##_test_data_compare(td1, td2, fcmp, mdata);
end_define

begin_define
define|#
directive|define
name|TEST_DATA_FIND
parameter_list|(
name|ent
parameter_list|,
name|td
parameter_list|,
name|d
parameter_list|,
name|fcmp
parameter_list|,
name|mdata
parameter_list|)
define|\
value|__##ent##_test_data_find(td, d, fcmp, mdata)
end_define

begin_define
define|#
directive|define
name|TEST_DATA_CLEAR
parameter_list|(
name|ent
parameter_list|,
name|td
parameter_list|)
value|__##ent##_test_data_clear(td)
end_define

begin_define
define|#
directive|define
name|IMPLEMENT_TEST_DATA
parameter_list|(
name|ent
parameter_list|)
define|\
value|void									\ __##ent##_test_data_init(struct ent##_test_data *td,			\ 	void (*clonef)(struct ent *, struct ent const *),		\ 	void (*freef)(struct ent *))					\ {									\ 	assert(td != NULL);						\ 	assert(clonef != NULL);						\ 	assert(freef != NULL);						\ 									\ 	memset(td, 0, sizeof(*td));					\ 	td->clone_func = clonef;					\ 	td->free_func = freef;						\ 	STAILQ_INIT(&td->snapshot_data);				\ }									\ 									\ void 									\ __##ent##_test_data_destroy(struct ent##_test_data *td)			\ {									\ 	__##ent##_test_data_clear(td);					\ }									\ 									\ void 									\ __##ent##_test_data_append(struct ent##_test_data *td, struct ent *app_data)\ {									\ 	struct ent##_entry *e;						\ 									\ 	assert(td != NULL);						\ 	assert(app_data != NULL);					\ 									\ 	e = (struct ent##_entry *)malloc(sizeof(struct ent##_entry));	\ 	assert(e != NULL);						\ 	memset(e, 0, sizeof(struct ent##_entry));			\ 									\ 	td->clone_func(&e->data, app_data);				\ 	STAILQ_INSERT_TAIL(&td->snapshot_data, e, entries);		\ }									\ 									\ int									\ __##ent##_test_data_foreach(struct ent##_test_data *td,			\ 	int (*forf)(struct ent *, void *), void *mdata)			\ {									\ 	struct ent##_entry *e;						\ 	int rv;								\ 									\ 	assert(td != NULL);						\ 	assert(forf != NULL);						\ 									\ 	rv = 0;								\ 	STAILQ_FOREACH(e,&td->snapshot_data, entries) {		\ 		rv = forf(&e->data, mdata);				\ 		if (rv != 0)						\ 			break;						\ 	}								\ 									\ 	return (rv);							\ }									\ 									\ int									\ __##ent##_test_data_compare(struct ent##_test_data *td1, struct ent##_test_data *td2,\ 	int (*cmp_func)(struct ent *, struct ent *, void *), void *mdata)\ {									\ 	struct ent##_entry *e1, *e2;					\ 	int rv;								\ 									\ 	assert(td1 != NULL);						\ 	assert(td2 != NULL);						\ 	assert(cmp_func != NULL);					\ 									\ 	e1 = STAILQ_FIRST(&td1->snapshot_data);				\ 	e2 = STAILQ_FIRST(&td2->snapshot_data);				\ 									\ 	rv = 0;								\ 	do {								\ 		if ((e1 == NULL) || (e2 == NULL)) {			\ 			if (e1 == e2)					\ 				return (0);				\ 			else						\ 				return (-1);				\ 		}							\ 									\ 		rv = cmp_func(&e1->data,&e2->data, mdata);		\ 		e1 = STAILQ_NEXT(e1, entries);				\ 		e2 = STAILQ_NEXT(e2, entries);				\ 	} while (rv == 0);						\ 									\ 	return (rv);							\ }									\ 									\ struct ent *								\ __##ent##_test_data_find(struct ent##_test_data *td, struct ent *data,	\ 	int (*cmp)(struct ent *, struct ent *, void *), void *mdata)	\ {									\ 	struct ent##_entry *e;						\ 	struct ent *result;						\ 									\ 	assert(td != NULL);						\ 	assert(cmp != NULL);						\ 									\ 	result = NULL;							\ 	STAILQ_FOREACH(e,&td->snapshot_data, entries) {		\ 		if (cmp(&e->data, data, mdata) == 0) {			\ 			result =&e->data;				\ 			break;						\ 		}							\ 	}								\ 									\ 	return (result);						\ }									\ 									\ 									\ void									\ __##ent##_test_data_clear(struct ent##_test_data *td)			\ {									\ 	struct ent##_entry *e;						\ 	assert(td != NULL);						\ 									\ 	while (!STAILQ_EMPTY(&td->snapshot_data)) {			\ 		e = STAILQ_FIRST(&td->snapshot_data);			\ 		STAILQ_REMOVE_HEAD(&td->snapshot_data, entries);	\ 									\ 		td->free_func(&e->data);				\ 		free(e);						\ 	}								\ }
end_define

begin_expr_stmt
unit|\
operator|#
name|define
name|DECLARE_TEST_FILE_SNAPSHOT
argument_list|(
argument|ent
argument_list|)
expr|\ struct
name|ent
operator|#
operator|#
name|_snp_param
block|{						\
name|FILE
operator|*
name|fp
block|;							\
name|void
argument_list|(
operator|*
name|sdump_func
argument_list|)
argument_list|(
expr|struct
name|ent
operator|*
argument_list|,
name|char
operator|*
argument_list|,
name|size_t
argument_list|)
block|;		\ }
expr_stmt|;
end_expr_stmt

begin_expr_stmt
unit|\ 									\
name|int
name|__
operator|#
operator|#
name|ent
operator|#
operator|#
name|_snapshot_write_func
argument_list|(
expr|struct
name|ent
operator|*
argument_list|,
name|void
operator|*
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
unit|\
name|int
name|__
operator|#
operator|#
name|ent
operator|#
operator|#
name|_snapshot_write
argument_list|(
name|char
specifier|const
operator|*
argument_list|,
expr|struct
name|ent
operator|#
operator|#
name|_test_data
operator|*
argument_list|,	\
name|void
argument_list|(
operator|*
argument_list|)
argument_list|(
expr|struct
name|ent
operator|*
argument_list|,
name|char
operator|*
argument_list|,
name|size_t
argument_list|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
unit|\
name|int
name|__
operator|#
operator|#
name|ent
operator|#
operator|#
name|_snapshot_read
argument_list|(
name|char
specifier|const
operator|*
argument_list|,
expr|struct
name|ent
operator|#
operator|#
name|_test_data
operator|*
argument_list|,	\
name|int
argument_list|(
operator|*
argument_list|)
argument_list|(
expr|struct
name|ent
operator|*
argument_list|,
name|char
operator|*
argument_list|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_define
define|#
directive|define
name|TEST_SNAPSHOT_FILE_WRITE
parameter_list|(
name|ent
parameter_list|,
name|fname
parameter_list|,
name|td
parameter_list|,
name|f
parameter_list|)
define|\
value|__##ent##_snapshot_write(fname, td, f)
end_define

begin_define
define|#
directive|define
name|TEST_SNAPSHOT_FILE_READ
parameter_list|(
name|ent
parameter_list|,
name|fname
parameter_list|,
name|td
parameter_list|,
name|f
parameter_list|)
define|\
value|__##ent##_snapshot_read(fname, td, f)
end_define

begin_define
define|#
directive|define
name|IMPLEMENT_TEST_FILE_SNAPSHOT
parameter_list|(
name|ent
parameter_list|)
define|\
value|int									\ __##ent##_snapshot_write_func(struct ent *data, void *mdata)		\ {									\ 	char buffer[1024];						\ 	struct ent##_snp_param *param;					\ 									\ 	assert(data != NULL);						\ 									\ 	param = (struct ent##_snp_param *)mdata;			\ 	param->sdump_func(data, buffer, sizeof(buffer));		\ 	fputs(buffer, param->fp);					\ 	fputc('\n', param->fp);						\ 									\ 	return (0);							\ }									\ 									\ int									\ __##ent##_snapshot_write(char const *fname, struct ent##_test_data *td,	\ 	void (*sdump_func)(struct ent *, char *, size_t))		\ {									\ 	struct ent##_snp_param	param;					\ 									\ 	assert(fname != NULL);						\ 	assert(td != NULL);						\ 									\ 	param.fp = fopen(fname, "w");					\ 	if (param.fp == NULL)						\ 		return (-1);						\ 									\ 	param.sdump_func = sdump_func;					\ 	__##ent##_test_data_foreach(td, __##ent##_snapshot_write_func,&param);\ 	fclose(param.fp);						\ 									\ 	return (0);							\ }									\ 									\ int									\ __##ent##_snapshot_read(char const *fname, struct ent##_test_data *td,	\ 	int (*read_func)(struct ent *, char *))				\ {									\ 	char buffer[1024];						\ 	struct ent data;						\ 	char *s;							\ 	FILE *fi;							\ 	size_t len;							\ 	int rv;								\ 									\ 	assert(fname != NULL);						\ 	assert(td != NULL);						\ 									\ 	fi = fopen(fname, "r");						\ 	if (fi == NULL)							\ 		return (-1);						\ 									\ 	rv = 0;								\ 	memset(buffer, 0, sizeof(buffer));				\ 	while (!feof(fi)) {						\ 		s = fgets(buffer, sizeof(buffer), fi);			\ 		if (s != NULL&& s[0] != '#') {				\ 			len = strlen(s);				\ 			if (len == 0)					\ 				continue;				\ 			if (buffer[len - 1] == '\n')			\ 				buffer[len -1] = '\0';			\ 									\ 			rv = read_func(&data, s);			\ 			if (rv == 0) {					\ 				__##ent##_test_data_append(td,&data);	\ 				td->free_func(&data);			\ 			} else 						\ 				goto fin;				\ 		}							\ 	}								\ 									\ fin:									\ 	fclose(fi);							\ 	return (rv);							\ }
end_define

begin_define
define|#
directive|define
name|DECLARE_1PASS_TEST
parameter_list|(
name|ent
parameter_list|)
define|\
value|int __##ent##_1pass_test(struct ent##_test_data *, 			\ 	int (*)(struct ent *, void *),					\ 	void *);
end_define

begin_define
define|#
directive|define
name|DO_1PASS_TEST
parameter_list|(
name|ent
parameter_list|,
name|td
parameter_list|,
name|f
parameter_list|,
name|mdata
parameter_list|)
define|\
value|__##ent##_1pass_test(td, f, mdata)
end_define

begin_define
define|#
directive|define
name|IMPLEMENT_1PASS_TEST
parameter_list|(
name|ent
parameter_list|)
define|\
value|int									\ __##ent##_1pass_test(struct ent##_test_data *td, 			\ 	int (*tf)(struct ent *, void *),				\ 	void *mdata)							\ {									\ 	int rv;								\ 	rv = __##ent##_test_data_foreach(td, tf, mdata);		\ 									\ 	return (rv);							\ }
end_define

begin_define
define|#
directive|define
name|DECLARE_2PASS_TEST
parameter_list|(
name|ent
parameter_list|)
define|\
value|int __##ent##_2pass_test(struct ent##_test_data *, 			\ 	struct ent##_test_data *, 					\ 	int (*)(struct ent *, struct ent *, void *), void *);
end_define

begin_define
define|#
directive|define
name|DO_2PASS_TEST
parameter_list|(
name|ent
parameter_list|,
name|td1
parameter_list|,
name|td2
parameter_list|,
name|f
parameter_list|,
name|mdata
parameter_list|)
define|\
value|__##ent##_2pass_test(td1, td2, f, mdata)
end_define

begin_define
define|#
directive|define
name|IMPLEMENT_2PASS_TEST
parameter_list|(
name|ent
parameter_list|)
define|\
value|int									\ __##ent##_2pass_test(struct ent##_test_data *td1,			\ 	struct ent##_test_data *td2,					\ 	int (*cmp_func)(struct ent *, struct ent *, void *),		\ 	void *cmp_mdata)						\ {									\ 	int rv;								\ 									\ 	rv = __##ent##_test_data_compare(td1, td2, cmp_func, cmp_mdata);	\ 	return (rv);							\ }
end_define

end_unit

