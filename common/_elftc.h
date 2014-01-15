begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2009 Joseph Koshy  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $Id: _elftc.h 2922 2013-03-17 22:53:15Z kaiwang27 $  */
end_comment

begin_comment
comment|/**  ** Miscellanous definitions needed by multiple components.  **/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_ELFTC_H
end_ifndef

begin_define
define|#
directive|define
name|_ELFTC_H
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|NULL
end_ifndef

begin_define
define|#
directive|define
name|NULL
value|((void *) 0)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|offsetof
end_ifndef

begin_define
define|#
directive|define
name|offsetof
parameter_list|(
name|T
parameter_list|,
name|M
parameter_list|)
value|((int)&((T*) 0) -> M)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* --QUEUE-MACROS-- [[ */
end_comment

begin_comment
comment|/*  * Supply macros missing from<sys/queue.h>  */
end_comment

begin_comment
comment|/*  * Copyright (c) 1991, 1993  *	The Regents of the University of California.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|SLIST_FOREACH_SAFE
end_ifndef

begin_define
define|#
directive|define
name|SLIST_FOREACH_SAFE
parameter_list|(
name|var
parameter_list|,
name|head
parameter_list|,
name|field
parameter_list|,
name|tvar
parameter_list|)
define|\
value|for ((var) = SLIST_FIRST((head));				\ 	    (var)&& ((tvar) = SLIST_NEXT((var), field), 1);		\ 	    (var) = (tvar))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|STAILQ_CONCAT
end_ifndef

begin_define
define|#
directive|define
name|STAILQ_CONCAT
parameter_list|(
name|head1
parameter_list|,
name|head2
parameter_list|)
value|do {			\ 	if (!STAILQ_EMPTY((head2))) {				\ 		*(head1)->stqh_last = (head2)->stqh_first;	\ 		(head1)->stqh_last = (head2)->stqh_last;	\ 		STAILQ_INIT((head2));				\ 	}							\ } while (
comment|/*CONSTCOND*/
value|0)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|STAILQ_EMPTY
end_ifndef

begin_define
define|#
directive|define
name|STAILQ_EMPTY
parameter_list|(
name|head
parameter_list|)
value|((head)->stqh_first == NULL)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|STAILQ_ENTRY
end_ifndef

begin_define
define|#
directive|define
name|STAILQ_ENTRY
parameter_list|(
name|type
parameter_list|)
define|\
value|struct {							\ 	struct type *stqe_next;
comment|/* next element */
value|\ }
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|STAILQ_FIRST
end_ifndef

begin_define
define|#
directive|define
name|STAILQ_FIRST
parameter_list|(
name|head
parameter_list|)
value|((head)->stqh_first)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|STAILQ_HEAD
end_ifndef

begin_define
define|#
directive|define
name|STAILQ_HEAD
parameter_list|(
name|name
parameter_list|,
name|type
parameter_list|)
define|\
value|struct name {							\ 	struct type *stqh_first;
comment|/* first element */
value|\ 	struct type **stqh_last;
comment|/* addr of last next element */
value|\ }
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|STAILQ_HEAD_INITIALIZER
end_ifndef

begin_define
define|#
directive|define
name|STAILQ_HEAD_INITIALIZER
parameter_list|(
name|head
parameter_list|)
define|\
value|{ NULL,&(head).stqh_first }
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|STAILQ_FOREACH
end_ifndef

begin_define
define|#
directive|define
name|STAILQ_FOREACH
parameter_list|(
name|var
parameter_list|,
name|head
parameter_list|,
name|field
parameter_list|)
define|\
value|for ((var) = ((head)->stqh_first);			\ 		(var);						\ 		(var) = ((var)->field.stqe_next))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|STAILQ_FOREACH_SAFE
end_ifndef

begin_define
define|#
directive|define
name|STAILQ_FOREACH_SAFE
parameter_list|(
name|var
parameter_list|,
name|head
parameter_list|,
name|field
parameter_list|,
name|tvar
parameter_list|)
define|\
value|for ((var) = STAILQ_FIRST((head));			\ 	    (var)&& ((tvar) = STAILQ_NEXT((var), field), 1);	\ 	    (var) = (tvar))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|STAILQ_INIT
end_ifndef

begin_define
define|#
directive|define
name|STAILQ_INIT
parameter_list|(
name|head
parameter_list|)
value|do {					\ 	(head)->stqh_first = NULL;				\ 	(head)->stqh_last =&(head)->stqh_first;		\ } while (
comment|/*CONSTCOND*/
value|0)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|STAILQ_INSERT_HEAD
end_ifndef

begin_define
define|#
directive|define
name|STAILQ_INSERT_HEAD
parameter_list|(
name|head
parameter_list|,
name|elm
parameter_list|,
name|field
parameter_list|)
value|do {			\ 	if (((elm)->field.stqe_next = (head)->stqh_first) == NULL)	\ 		(head)->stqh_last =&(elm)->field.stqe_next;		\ 	(head)->stqh_first = (elm);					\ } while (
comment|/*CONSTCOND*/
value|0)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|STAILQ_INSERT_TAIL
end_ifndef

begin_define
define|#
directive|define
name|STAILQ_INSERT_TAIL
parameter_list|(
name|head
parameter_list|,
name|elm
parameter_list|,
name|field
parameter_list|)
value|do {			\ 	(elm)->field.stqe_next = NULL;					\ 	*(head)->stqh_last = (elm);					\ 	(head)->stqh_last =&(elm)->field.stqe_next;			\ } while (
comment|/*CONSTCOND*/
value|0)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|STAILQ_INSERT_AFTER
end_ifndef

begin_define
define|#
directive|define
name|STAILQ_INSERT_AFTER
parameter_list|(
name|head
parameter_list|,
name|listelm
parameter_list|,
name|elm
parameter_list|,
name|field
parameter_list|)
value|do {		\ 	if (((elm)->field.stqe_next = (listelm)->field.stqe_next) == NULL)\ 		(head)->stqh_last =&(elm)->field.stqe_next;		\ 	(listelm)->field.stqe_next = (elm);				\ } while (
comment|/*CONSTCOND*/
value|0)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|STAILQ_LAST
end_ifndef

begin_define
define|#
directive|define
name|STAILQ_LAST
parameter_list|(
name|head
parameter_list|,
name|type
parameter_list|,
name|field
parameter_list|)
define|\
value|(STAILQ_EMPTY((head)) ?					\ 	    NULL : ((struct type *)(void *)				\ 	    ((char *)((head)->stqh_last) - offsetof(struct type, field))))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|STAILQ_NEXT
end_ifndef

begin_define
define|#
directive|define
name|STAILQ_NEXT
parameter_list|(
name|elm
parameter_list|,
name|field
parameter_list|)
value|((elm)->field.stqe_next)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|STAILQ_REMOVE
end_ifndef

begin_define
define|#
directive|define
name|STAILQ_REMOVE
parameter_list|(
name|head
parameter_list|,
name|elm
parameter_list|,
name|type
parameter_list|,
name|field
parameter_list|)
value|do {			\ 	if ((head)->stqh_first == (elm)) {				\ 		STAILQ_REMOVE_HEAD((head), field);			\ 	} else {							\ 		struct type *curelm = (head)->stqh_first;		\ 		while (curelm->field.stqe_next != (elm))		\ 			curelm = curelm->field.stqe_next;		\ 		if ((curelm->field.stqe_next =				\ 			curelm->field.stqe_next->field.stqe_next) == NULL) \ 			    (head)->stqh_last =&(curelm)->field.stqe_next; \ 	}								\ } while (
comment|/*CONSTCOND*/
value|0)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|STAILQ_REMOVE_HEAD
end_ifndef

begin_define
define|#
directive|define
name|STAILQ_REMOVE_HEAD
parameter_list|(
name|head
parameter_list|,
name|field
parameter_list|)
value|do {				\ 	if (((head)->stqh_first = (head)->stqh_first->field.stqe_next) == \ 	    NULL)							\ 		(head)->stqh_last =&(head)->stqh_first;		\ } while (
comment|/*CONSTCOND*/
value|0)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * The STAILQ_SORT macro is adapted from Simon Tatham's O(n*log(n))  * mergesort algorithm.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|STAILQ_SORT
end_ifndef

begin_define
define|#
directive|define
name|STAILQ_SORT
parameter_list|(
name|head
parameter_list|,
name|type
parameter_list|,
name|field
parameter_list|,
name|cmp
parameter_list|)
value|do {			\ 	STAILQ_HEAD(, type) _la, _lb;					\ 	struct type *_p, *_q, *_e;					\ 	int _i, _sz, _nmerges, _psz, _qsz;				\ 									\ 	_sz = 1;							\ 	do {								\ 		_nmerges = 0;						\ 		STAILQ_INIT(&_lb);					\ 		while (!STAILQ_EMPTY((head))) {				\ 			_nmerges++;					\ 			STAILQ_INIT(&_la);				\ 			_psz = 0;					\ 			for (_i = 0; _i< _sz&& !STAILQ_EMPTY((head));	\ 			     _i++) {					\ 				_e = STAILQ_FIRST((head));		\ 				if (_e == NULL)				\ 					break;				\ 				_psz++;					\ 				STAILQ_REMOVE_HEAD((head), field);	\ 				STAILQ_INSERT_TAIL(&_la, _e, field);	\ 			}						\ 			_p = STAILQ_FIRST(&_la);			\ 			_qsz = _sz;					\ 			_q = STAILQ_FIRST((head));			\ 			while (_psz> 0 || (_qsz> 0&& _q != NULL)) {	\ 				if (_psz == 0) {			\ 					_e = _q;			\ 					_q = STAILQ_NEXT(_q, field);	\ 					STAILQ_REMOVE_HEAD((head),	\ 					    field);			\ 					_qsz--;				\ 				} else if (_qsz == 0 || _q == NULL) {	\ 					_e = _p;			\ 					_p = STAILQ_NEXT(_p, field);	\ 					STAILQ_REMOVE_HEAD(&_la, field);\ 					_psz--;				\ 				} else if (cmp(_p, _q)<= 0) {		\ 					_e = _p;			\ 					_p = STAILQ_NEXT(_p, field);	\ 					STAILQ_REMOVE_HEAD(&_la, field);\ 					_psz--;				\ 				} else {				\ 					_e = _q;			\ 					_q = STAILQ_NEXT(_q, field);	\ 					STAILQ_REMOVE_HEAD((head),	\ 					    field);			\ 					_qsz--;				\ 				}					\ 				STAILQ_INSERT_TAIL(&_lb, _e, field);	\ 			}						\ 		}							\ 		(head)->stqh_first = _lb.stqh_first;			\ 		(head)->stqh_last = _lb.stqh_last;			\ 		_sz *= 2;						\ 	} while (_nmerges> 1);						\ } while (
comment|/*CONSTCOND*/
value|0)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|TAILQ_FOREACH_SAFE
end_ifndef

begin_define
define|#
directive|define
name|TAILQ_FOREACH_SAFE
parameter_list|(
name|var
parameter_list|,
name|head
parameter_list|,
name|field
parameter_list|,
name|tvar
parameter_list|)
define|\
value|for ((var) = TAILQ_FIRST((head));                               \ 	    (var)&& ((tvar) = TAILQ_NEXT((var), field), 1);            \ 	    (var) = (tvar))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ]] --QUEUE-MACROS-- */
end_comment

begin_comment
comment|/*  * VCS Ids.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|ELFTC_VCSID
end_ifndef

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__DragonFly__
argument_list|)
end_if

begin_define
define|#
directive|define
name|ELFTC_VCSID
parameter_list|(
name|ID
parameter_list|)
value|__RCSID(ID)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__FreeBSD__
argument_list|)
end_if

begin_define
define|#
directive|define
name|ELFTC_VCSID
parameter_list|(
name|ID
parameter_list|)
value|__FBSDID(ID)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__linux__
argument_list|)
operator|||
name|defined
argument_list|(
name|__GNU__
argument_list|)
operator|||
name|defined
argument_list|(
name|__GLIBC__
argument_list|)
end_if

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__GNUC__
argument_list|)
end_if

begin_define
define|#
directive|define
name|ELFTC_VCSID
parameter_list|(
name|ID
parameter_list|)
value|__asm__(".ident\t\"" ID "\"")
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|ELFTC_VCSID
parameter_list|(
name|ID
parameter_list|)
end_define

begin_comment
comment|/**/
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__minix
argument_list|)
end_if

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__GNUC__
argument_list|)
end_if

begin_define
define|#
directive|define
name|ELFTC_VCSID
parameter_list|(
name|ID
parameter_list|)
value|__asm__(".ident\t\"" ID "\"")
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|ELFTC_VCSID
parameter_list|(
name|ID
parameter_list|)
end_define

begin_comment
comment|/**/
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __GNU__ */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__NetBSD__
argument_list|)
end_if

begin_define
define|#
directive|define
name|ELFTC_VCSID
parameter_list|(
name|ID
parameter_list|)
value|__RCSID(ID)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__OpenBSD__
argument_list|)
end_if

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__GNUC__
argument_list|)
end_if

begin_define
define|#
directive|define
name|ELFTC_VCSID
parameter_list|(
name|ID
parameter_list|)
value|__asm__(".ident\t\"" ID "\"")
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|ELFTC_VCSID
parameter_list|(
name|ID
parameter_list|)
end_define

begin_comment
comment|/**/
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __GNUC__ */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ELFTC_VCSID */
end_comment

begin_comment
comment|/*  * Provide an equivalent for getprogname(3).  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|ELFTC_GETPROGNAME
end_ifndef

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__DragonFly__
argument_list|)
operator|||
name|defined
argument_list|(
name|__FreeBSD__
argument_list|)
operator|||
name|defined
argument_list|(
name|__minix
argument_list|)
operator|||
expr|\
name|defined
argument_list|(
name|__NetBSD__
argument_list|)
end_if

begin_include
include|#
directive|include
file|<stdlib.h>
end_include

begin_define
define|#
directive|define
name|ELFTC_GETPROGNAME
parameter_list|()
value|getprogname()
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __DragonFly__ || __FreeBSD__ || __minix || __NetBSD__ */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__GLIBC__
argument_list|)
end_if

begin_comment
comment|/*  * GLIBC based systems have a global 'char *' pointer referencing  * the executable's name.  */
end_comment

begin_decl_stmt
specifier|extern
specifier|const
name|char
modifier|*
name|program_invocation_short_name
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|ELFTC_GETPROGNAME
parameter_list|()
value|program_invocation_short_name
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __GLIBC__ */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__OpenBSD__
argument_list|)
end_if

begin_decl_stmt
specifier|extern
specifier|const
name|char
modifier|*
name|__progname
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|ELFTC_GETPROGNAME
parameter_list|()
value|__progname
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __OpenBSD__ */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ELFTC_GETPROGNAME */
end_comment

begin_comment
comment|/**  ** Per-OS configuration.  **/
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__DragonFly__
argument_list|)
end_if

begin_include
include|#
directive|include
file|<osreldate.h>
end_include

begin_include
include|#
directive|include
file|<sys/endian.h>
end_include

begin_define
define|#
directive|define
name|ELFTC_BYTE_ORDER
value|_BYTE_ORDER
end_define

begin_define
define|#
directive|define
name|ELFTC_BYTE_ORDER_LITTLE_ENDIAN
value|_LITTLE_ENDIAN
end_define

begin_define
define|#
directive|define
name|ELFTC_BYTE_ORDER_BIG_ENDIAN
value|_BIG_ENDIAN
end_define

begin_define
define|#
directive|define
name|ELFTC_HAVE_MMAP
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__GLIBC__
argument_list|)
end_if

begin_include
include|#
directive|include
file|<endian.h>
end_include

begin_define
define|#
directive|define
name|ELFTC_BYTE_ORDER
value|__BYTE_ORDER
end_define

begin_define
define|#
directive|define
name|ELFTC_BYTE_ORDER_LITTLE_ENDIAN
value|__LITTLE_ENDIAN
end_define

begin_define
define|#
directive|define
name|ELFTC_BYTE_ORDER_BIG_ENDIAN
value|__BIG_ENDIAN
end_define

begin_define
define|#
directive|define
name|ELFTC_HAVE_MMAP
value|1
end_define

begin_comment
comment|/*  * Debian GNU/Linux and Debian GNU/kFreeBSD do not have strmode(3).  */
end_comment

begin_define
define|#
directive|define
name|ELFTC_HAVE_STRMODE
value|0
end_define

begin_comment
comment|/* Whether we need to supply {be,le}32dec. */
end_comment

begin_define
define|#
directive|define
name|ELFTC_NEED_BYTEORDER_EXTENSIONS
value|1
end_define

begin_define
define|#
directive|define
name|roundup2
value|roundup
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __GLIBC__ */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__FreeBSD__
argument_list|)
end_if

begin_include
include|#
directive|include
file|<osreldate.h>
end_include

begin_include
include|#
directive|include
file|<sys/endian.h>
end_include

begin_define
define|#
directive|define
name|ELFTC_BYTE_ORDER
value|_BYTE_ORDER
end_define

begin_define
define|#
directive|define
name|ELFTC_BYTE_ORDER_LITTLE_ENDIAN
value|_LITTLE_ENDIAN
end_define

begin_define
define|#
directive|define
name|ELFTC_BYTE_ORDER_BIG_ENDIAN
value|_BIG_ENDIAN
end_define

begin_define
define|#
directive|define
name|ELFTC_HAVE_MMAP
value|1
end_define

begin_define
define|#
directive|define
name|ELFTC_HAVE_STRMODE
value|1
end_define

begin_if
if|#
directive|if
name|__FreeBSD_version
operator|<=
literal|900000
end_if

begin_define
define|#
directive|define
name|ELFTC_BROKEN_YY_NO_INPUT
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __FreeBSD__ */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__minix
argument_list|)
end_if

begin_define
define|#
directive|define
name|ELFTC_HAVE_MMAP
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __minix */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__NetBSD__
argument_list|)
end_if

begin_include
include|#
directive|include
file|<sys/param.h>
end_include

begin_include
include|#
directive|include
file|<sys/endian.h>
end_include

begin_define
define|#
directive|define
name|ELFTC_BYTE_ORDER
value|_BYTE_ORDER
end_define

begin_define
define|#
directive|define
name|ELFTC_BYTE_ORDER_LITTLE_ENDIAN
value|_LITTLE_ENDIAN
end_define

begin_define
define|#
directive|define
name|ELFTC_BYTE_ORDER_BIG_ENDIAN
value|_BIG_ENDIAN
end_define

begin_define
define|#
directive|define
name|ELFTC_HAVE_MMAP
value|1
end_define

begin_define
define|#
directive|define
name|ELFTC_HAVE_STRMODE
value|1
end_define

begin_if
if|#
directive|if
name|__NetBSD_Version__
operator|<=
literal|599002100
end_if

begin_comment
comment|/* from src/doc/CHANGES: flex(1): Import flex-2.5.35 [christos 20091025] */
end_comment

begin_comment
comment|/* and 5.99.21 was from Wed Oct 21 21:28:36 2009 UTC */
end_comment

begin_define
define|#
directive|define
name|ELFTC_BROKEN_YY_NO_INPUT
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __NetBSD __ */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__OpenBSD__
argument_list|)
end_if

begin_include
include|#
directive|include
file|<sys/param.h>
end_include

begin_include
include|#
directive|include
file|<sys/endian.h>
end_include

begin_define
define|#
directive|define
name|ELFTC_BYTE_ORDER
value|_BYTE_ORDER
end_define

begin_define
define|#
directive|define
name|ELFTC_BYTE_ORDER_LITTLE_ENDIAN
value|_LITTLE_ENDIAN
end_define

begin_define
define|#
directive|define
name|ELFTC_BYTE_ORDER_BIG_ENDIAN
value|_BIG_ENDIAN
end_define

begin_define
define|#
directive|define
name|ELFTC_HAVE_MMAP
value|1
end_define

begin_define
define|#
directive|define
name|ELFTC_HAVE_STRMODE
value|1
end_define

begin_define
define|#
directive|define
name|ELFTC_NEED_BYTEORDER_EXTENSIONS
value|1
end_define

begin_define
define|#
directive|define
name|roundup2
value|roundup
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __OpenBSD__ */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _ELFTC_H */
end_comment

end_unit

