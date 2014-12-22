begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2010 Kai Wang  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $Id: driver.h 3074 2014-06-23 03:08:53Z kaiwang27 $  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_DRIVER_H_
end_ifndef

begin_define
define|#
directive|define
name|_DRIVER_H_
end_define

begin_struct
struct|struct
name|dwarf_tp
block|{
specifier|const
name|char
modifier|*
name|tp_name
decl_stmt|;
name|void
function_decl|(
modifier|*
name|tp_func
function_decl|)
parameter_list|(
name|void
parameter_list|)
function_decl|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|TS_DWARF_INIT
parameter_list|(
name|D
parameter_list|,
name|FD
parameter_list|,
name|DE
parameter_list|)
value|do {					\ 	(D) = NULL;							\ 	if (((FD) = open(_cur_file, O_RDONLY))< 0) {			\ 		tet_printf("open %s failed; %s", _cur_file,		\ 		    strerror(errno));					\ 		result = TET_FAIL;					\ 		goto done;						\ 	}								\ 	if (dwarf_init((FD), DW_DLC_READ, NULL, NULL,&(D),&(DE)) !=	\ 	    DW_DLV_OK) {						\ 		tet_printf("dwarf_init failed: %s", dwarf_errmsg((DE)));\ 		result = TET_FAIL;					\ 		goto done;						\ 	}								\ 	} while (0)
end_define

begin_define
define|#
directive|define
name|TS_DWARF_FINISH
parameter_list|(
name|D
parameter_list|,
name|DE
parameter_list|)
value|do {					\ 	if (dwarf_finish((D),&(DE)) != DW_DLV_OK) {			\ 		tet_printf("dwarf_finish failed: %s",			\ 		    dwarf_errmsg((DE)));				\ 		result = TET_FAIL;					\ 	}								\ 	} while (0)
end_define

begin_define
define|#
directive|define
name|TS_DWARF_CU_FOREACH
parameter_list|(
name|D
parameter_list|,
name|N
parameter_list|,
name|DE
parameter_list|)
define|\
value|while (dwarf_next_cu_header((D), NULL, NULL, NULL, NULL,&(N),	\&(DE)) == DW_DLV_OK)
end_define

begin_define
define|#
directive|define
name|TS_DWARF_CU_FOREACH2
parameter_list|(
name|D
parameter_list|,
name|I
parameter_list|,
name|N
parameter_list|,
name|DE
parameter_list|)
define|\
value|while (dwarf_next_cu_header_c((D), (I), NULL, NULL, NULL, NULL,	\ 	    NULL, NULL, NULL, NULL,&(N),&(DE)) == DW_DLV_OK)
end_define

begin_define
define|#
directive|define
name|TS_DWARF_DIE_TRAVERSE
parameter_list|(
name|D
parameter_list|,
name|CB
parameter_list|)
define|\
value|_die_traverse((D), (CB))
end_define

begin_define
define|#
directive|define
name|TS_DWARF_DIE_TRAVERSE2
parameter_list|(
name|D
parameter_list|,
name|I
parameter_list|,
name|CB
parameter_list|)
define|\
value|_die_traverse2((D), (I), (CB))
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|TCGEN
end_ifndef

begin_define
define|#
directive|define
name|_TS_CHECK_VAR
parameter_list|(
name|X
parameter_list|,
name|S
parameter_list|)
value|do {						\ 	struct _drv_vc *_next_vc;					\ 	int skip = 0;							\ 	if (strcmp(_cur_vc->var, S)) {					\ 		tet_printf("VC var(%s) does not match %s, possibly"	\ 		    " caused by the skip of previous VCs, try finding"	\ 		    " the next var with maching name", _cur_vc->var,	\ 		    S);							\ 		_next_vc = _cur_vc;					\ 		do {							\ 			_next_vc = STAILQ_NEXT(_next_vc, next);		\ 			skip++;						\ 			if (!strcmp(_next_vc->var, S))			\ 				break;					\ 		} while (_next_vc != NULL);				\ 		if (_next_vc != NULL) {					\ 			tet_printf("skipped %d VC(s)\n", skip);		\ 			_cur_vc = _next_vc;				\ 		}							\ 	}								\ 	} while (0)
end_define

begin_define
define|#
directive|define
name|TS_CHECK_INT
parameter_list|(
name|X
parameter_list|)
value|do {						\ 	assert(_cur_vc != NULL);					\ 	_TS_CHECK_VAR(X,#X);						\ 	if (X != _cur_vc->v.i64) {					\ 		tet_printf("assertion %s(%jd) == %jd failed",		\ 		    _cur_vc->var, (intmax_t) (X),			\ 		    (intmax_t) _cur_vc->v.i64);				\ 		result = TET_FAIL;					\ 	}								\ 	_cur_vc = STAILQ_NEXT(_cur_vc, next);				\ 	} while (0)
end_define

begin_define
define|#
directive|define
name|TS_CHECK_UINT
parameter_list|(
name|X
parameter_list|)
value|do {						\ 	assert(_cur_vc != NULL);					\ 	_TS_CHECK_VAR(X,#X);						\ 	if (X != _cur_vc->v.u64) {					\ 		tet_printf("assertion %s(%ju) == %ju failed",		\ 		    _cur_vc->var, (uintmax_t) (X),			\ 		    (uintmax_t) _cur_vc->v.u64);			\ 		result = TET_FAIL;					\ 	}								\ 	_cur_vc = STAILQ_NEXT(_cur_vc, next);				\ 	} while (0)
end_define

begin_define
define|#
directive|define
name|TS_CHECK_STRING
parameter_list|(
name|X
parameter_list|)
value|do {						\ 	assert(_cur_vc != NULL);					\ 	_TS_CHECK_VAR(X,#X);						\ 	if (strcmp(X, _cur_vc->v.str)) {				\ 		tet_printf("assertion %s('%s') == '%s' failed",		\ 		    _cur_vc->var, (X), _cur_vc->v.str);			\ 		result = TET_FAIL;					\ 	}								\ 	_cur_vc = STAILQ_NEXT(_cur_vc, next);				\ 	} while (0)
end_define

begin_define
define|#
directive|define
name|TS_CHECK_BLOCK
parameter_list|(
name|B
parameter_list|,
name|S
parameter_list|)
value|do {					\ 	assert(_cur_vc != NULL);					\ 	_TS_CHECK_VAR(B,#B);						\ 	if ((S) != _cur_vc->v.b.len ||					\ 	    memcmp((B), _cur_vc->v.b.data, _cur_vc->v.b.len)) {		\ 		tet_printf("assertion block %s failed\n", _cur_vc->var);\ 		result = TET_FAIL;					\ 	}								\ 	_cur_vc = STAILQ_NEXT(_cur_vc, next);				\ 	} while (0)
end_define

begin_define
define|#
directive|define
name|TS_RESULT
parameter_list|(
name|X
parameter_list|)
value|tet_result(X)
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* !TCGEN */
end_comment

begin_define
define|#
directive|define
name|TS_CHECK_INT
parameter_list|(
name|X
parameter_list|)
value|do {						\ 	fprintf(_cur_fp, "<vc var='%s' type='int'>%jd</vc>\n", #X,	\ 	    (intmax_t) (X));						\ 	} while (0)
end_define

begin_define
define|#
directive|define
name|TS_CHECK_UINT
parameter_list|(
name|X
parameter_list|)
value|do {						\ 	fprintf(_cur_fp, "<vc var='%s' type='uint'>%ju</vc>\n", #X,	\ 	    (uintmax_t)(X));						\ 	} while (0)
end_define

begin_define
define|#
directive|define
name|TS_CHECK_STRING
parameter_list|(
name|X
parameter_list|)
value|do {						\ 	fprintf(_cur_fp, "<vc var='%s' type='str'>%s</vc>\n", #X,	\ 	    driver_string_encode(X));					\ 	} while (0)
end_define

begin_define
define|#
directive|define
name|TS_CHECK_BLOCK
parameter_list|(
name|B
parameter_list|,
name|S
parameter_list|)
value|do {					\ 	char *code;							\ 	int codesize;							\ 	size_t wsize;							\ 	fprintf(_cur_fp, "<vc var='%s' type='block'>", #B);		\ 	driver_base64_encode((char *) (B), (S),&code,&codesize);	\ 	wsize = fwrite(code, 1, (size_t) codesize, _cur_fp);		\ 	assert(wsize == (size_t) codesize);				\ 	fprintf(_cur_fp, "</vc>\n");					\ 	free(code);							\ 	} while (0)
end_define

begin_define
define|#
directive|define
name|TS_RESULT
parameter_list|(
name|X
parameter_list|)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !TCGEN */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_DRIVER_H_ */
end_comment

end_unit

