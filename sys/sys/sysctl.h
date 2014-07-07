begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1989, 1993  *	The Regents of the University of California.  All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * Mike Karels at Berkeley Software Design, Inc.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)sysctl.h	8.1 (Berkeley) 6/2/93  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_SYS_SYSCTL_H_
end_ifndef

begin_define
define|#
directive|define
name|_SYS_SYSCTL_H_
end_define

begin_include
include|#
directive|include
file|<sys/queue.h>
end_include

begin_struct_decl
struct_decl|struct
name|thread
struct_decl|;
end_struct_decl

begin_comment
comment|/*  * Definitions for sysctl call.  The sysctl call uses a hierarchical name  * for objects that can be examined or modified.  The name is expressed as  * a sequence of integers.  Like a file path name, the meaning of each  * component depends on its place in the hierarchy.  The top-level and kern  * identifiers are defined here, and other identifiers are defined in the  * respective subsystem header files.  */
end_comment

begin_define
define|#
directive|define
name|CTL_MAXNAME
value|24
end_define

begin_comment
comment|/* largest number of components supported */
end_comment

begin_comment
comment|/*  * Each subsystem defined by sysctl defines a list of variables  * for that subsystem. Each name is either a node with further  * levels defined below it, or it is a leaf of some particular  * type given below. Each sysctl level defines a set of name/type  * pairs to be used by sysctl(8) in manipulating the subsystem.  */
end_comment

begin_struct
struct|struct
name|ctlname
block|{
name|char
modifier|*
name|ctl_name
decl_stmt|;
comment|/* subsystem name */
name|int
name|ctl_type
decl_stmt|;
comment|/* type of name */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|CTLTYPE
value|0xf
end_define

begin_comment
comment|/* mask for the type */
end_comment

begin_define
define|#
directive|define
name|CTLTYPE_NODE
value|1
end_define

begin_comment
comment|/* name is a node */
end_comment

begin_define
define|#
directive|define
name|CTLTYPE_INT
value|2
end_define

begin_comment
comment|/* name describes an integer */
end_comment

begin_define
define|#
directive|define
name|CTLTYPE_STRING
value|3
end_define

begin_comment
comment|/* name describes a string */
end_comment

begin_define
define|#
directive|define
name|CTLTYPE_S64
value|4
end_define

begin_comment
comment|/* name describes a signed 64-bit number */
end_comment

begin_define
define|#
directive|define
name|CTLTYPE_OPAQUE
value|5
end_define

begin_comment
comment|/* name describes a structure */
end_comment

begin_define
define|#
directive|define
name|CTLTYPE_STRUCT
value|CTLTYPE_OPAQUE
end_define

begin_comment
comment|/* name describes a structure */
end_comment

begin_define
define|#
directive|define
name|CTLTYPE_UINT
value|6
end_define

begin_comment
comment|/* name describes an unsigned integer */
end_comment

begin_define
define|#
directive|define
name|CTLTYPE_LONG
value|7
end_define

begin_comment
comment|/* name describes a long */
end_comment

begin_define
define|#
directive|define
name|CTLTYPE_ULONG
value|8
end_define

begin_comment
comment|/* name describes an unsigned long */
end_comment

begin_define
define|#
directive|define
name|CTLTYPE_U64
value|9
end_define

begin_comment
comment|/* name describes an unsigned 64-bit number */
end_comment

begin_define
define|#
directive|define
name|CTLFLAG_RD
value|0x80000000
end_define

begin_comment
comment|/* Allow reads of variable */
end_comment

begin_define
define|#
directive|define
name|CTLFLAG_WR
value|0x40000000
end_define

begin_comment
comment|/* Allow writes to the variable */
end_comment

begin_define
define|#
directive|define
name|CTLFLAG_RW
value|(CTLFLAG_RD|CTLFLAG_WR)
end_define

begin_define
define|#
directive|define
name|CTLFLAG_ANYBODY
value|0x10000000
end_define

begin_comment
comment|/* All users can set this var */
end_comment

begin_define
define|#
directive|define
name|CTLFLAG_SECURE
value|0x08000000
end_define

begin_comment
comment|/* Permit set only if securelevel<=0 */
end_comment

begin_define
define|#
directive|define
name|CTLFLAG_PRISON
value|0x04000000
end_define

begin_comment
comment|/* Prisoned roots can fiddle */
end_comment

begin_define
define|#
directive|define
name|CTLFLAG_DYN
value|0x02000000
end_define

begin_comment
comment|/* Dynamic oid - can be freed */
end_comment

begin_define
define|#
directive|define
name|CTLFLAG_SKIP
value|0x01000000
end_define

begin_comment
comment|/* Skip this sysctl when listing */
end_comment

begin_define
define|#
directive|define
name|CTLMASK_SECURE
value|0x00F00000
end_define

begin_comment
comment|/* Secure level */
end_comment

begin_define
define|#
directive|define
name|CTLFLAG_TUN
value|0x00080000
end_define

begin_comment
comment|/* Default value is loaded from getenv() */
end_comment

begin_define
define|#
directive|define
name|CTLFLAG_RDTUN
value|(CTLFLAG_RD|CTLFLAG_TUN)
end_define

begin_define
define|#
directive|define
name|CTLFLAG_RWTUN
value|(CTLFLAG_RW|CTLFLAG_TUN)
end_define

begin_define
define|#
directive|define
name|CTLFLAG_MPSAFE
value|0x00040000
end_define

begin_comment
comment|/* Handler is MP safe */
end_comment

begin_define
define|#
directive|define
name|CTLFLAG_VNET
value|0x00020000
end_define

begin_comment
comment|/* Prisons with vnet can fiddle */
end_comment

begin_define
define|#
directive|define
name|CTLFLAG_DYING
value|0x00010000
end_define

begin_comment
comment|/* Oid is being removed */
end_comment

begin_define
define|#
directive|define
name|CTLFLAG_CAPRD
value|0x00008000
end_define

begin_comment
comment|/* Can be read in capability mode */
end_comment

begin_define
define|#
directive|define
name|CTLFLAG_CAPWR
value|0x00004000
end_define

begin_comment
comment|/* Can be written in capability mode */
end_comment

begin_define
define|#
directive|define
name|CTLFLAG_STATS
value|0x00002000
end_define

begin_comment
comment|/* Statistics, not a tuneable */
end_comment

begin_define
define|#
directive|define
name|CTLFLAG_NOFETCH
value|0x00001000
end_define

begin_comment
comment|/* Don't fetch tunable from getenv() */
end_comment

begin_define
define|#
directive|define
name|CTLFLAG_CAPRW
value|(CTLFLAG_CAPRD|CTLFLAG_CAPWR)
end_define

begin_comment
comment|/*  * Secure level.   Note that CTLFLAG_SECURE == CTLFLAG_SECURE1.  *  * Secure when the securelevel is raised to at least N.  */
end_comment

begin_define
define|#
directive|define
name|CTLSHIFT_SECURE
value|20
end_define

begin_define
define|#
directive|define
name|CTLFLAG_SECURE1
value|(CTLFLAG_SECURE | (0<< CTLSHIFT_SECURE))
end_define

begin_define
define|#
directive|define
name|CTLFLAG_SECURE2
value|(CTLFLAG_SECURE | (1<< CTLSHIFT_SECURE))
end_define

begin_define
define|#
directive|define
name|CTLFLAG_SECURE3
value|(CTLFLAG_SECURE | (2<< CTLSHIFT_SECURE))
end_define

begin_comment
comment|/*  * USE THIS instead of a hardwired number from the categories below  * to get dynamically assigned sysctl entries using the linker-set  * technology. This is the way nearly all new sysctl variables should  * be implemented.  * e.g. SYSCTL_INT(_parent, OID_AUTO, name, CTLFLAG_RW,&variable, 0, "");  */
end_comment

begin_define
define|#
directive|define
name|OID_AUTO
value|(-1)
end_define

begin_comment
comment|/*  * The starting number for dynamically-assigned entries.  WARNING!  * ALL static sysctl entries should have numbers LESS than this!  */
end_comment

begin_define
define|#
directive|define
name|CTL_AUTO_START
value|0x100
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_include
include|#
directive|include
file|<sys/linker_set.h>
end_include

begin_define
define|#
directive|define
name|SYSCTL_HANDLER_ARGS
value|struct sysctl_oid *oidp, void *arg1,	\ 	intptr_t arg2, struct sysctl_req *req
end_define

begin_comment
comment|/* definitions for sysctl_req 'lock' member */
end_comment

begin_define
define|#
directive|define
name|REQ_UNWIRED
value|1
end_define

begin_define
define|#
directive|define
name|REQ_WIRED
value|2
end_define

begin_comment
comment|/* definitions for sysctl_req 'flags' member */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__amd64__
argument_list|)
operator|||
name|defined
argument_list|(
name|__powerpc64__
argument_list|)
operator|||
expr|\
operator|(
name|defined
argument_list|(
name|__mips__
argument_list|)
operator|&&
name|defined
argument_list|(
name|__mips_n64
argument_list|)
operator|)
end_if

begin_define
define|#
directive|define
name|SCTL_MASK32
value|1
end_define

begin_comment
comment|/* 32 bit emulation */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * This describes the access space for a sysctl request.  This is needed  * so that we can use the interface from the kernel or from user-space.  */
end_comment

begin_struct
struct|struct
name|sysctl_req
block|{
name|struct
name|thread
modifier|*
name|td
decl_stmt|;
comment|/* used for access checking */
name|int
name|lock
decl_stmt|;
comment|/* wiring state */
name|void
modifier|*
name|oldptr
decl_stmt|;
name|size_t
name|oldlen
decl_stmt|;
name|size_t
name|oldidx
decl_stmt|;
name|int
function_decl|(
modifier|*
name|oldfunc
function_decl|)
parameter_list|(
name|struct
name|sysctl_req
modifier|*
parameter_list|,
specifier|const
name|void
modifier|*
parameter_list|,
name|size_t
parameter_list|)
function_decl|;
name|void
modifier|*
name|newptr
decl_stmt|;
name|size_t
name|newlen
decl_stmt|;
name|size_t
name|newidx
decl_stmt|;
name|int
function_decl|(
modifier|*
name|newfunc
function_decl|)
parameter_list|(
name|struct
name|sysctl_req
modifier|*
parameter_list|,
name|void
modifier|*
parameter_list|,
name|size_t
parameter_list|)
function_decl|;
name|size_t
name|validlen
decl_stmt|;
name|int
name|flags
decl_stmt|;
block|}
struct|;
end_struct

begin_expr_stmt
name|SLIST_HEAD
argument_list|(
name|sysctl_oid_list
argument_list|,
name|sysctl_oid
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/*  * This describes one "oid" in the MIB tree.  Potentially more nodes can  * be hidden behind it, expanded by the handler.  */
end_comment

begin_struct
struct|struct
name|sysctl_oid
block|{
name|struct
name|sysctl_oid_list
name|oid_children
decl_stmt|;
name|struct
name|sysctl_oid_list
modifier|*
name|oid_parent
decl_stmt|;
name|SLIST_ENTRY
argument_list|(
argument|sysctl_oid
argument_list|)
name|oid_link
expr_stmt|;
name|int
name|oid_number
decl_stmt|;
name|u_int
name|oid_kind
decl_stmt|;
name|void
modifier|*
name|oid_arg1
decl_stmt|;
name|intptr_t
name|oid_arg2
decl_stmt|;
specifier|const
name|char
modifier|*
name|oid_name
decl_stmt|;
name|int
function_decl|(
modifier|*
name|oid_handler
function_decl|)
parameter_list|(
name|SYSCTL_HANDLER_ARGS
parameter_list|)
function_decl|;
specifier|const
name|char
modifier|*
name|oid_fmt
decl_stmt|;
name|int
name|oid_refcnt
decl_stmt|;
name|u_int
name|oid_running
decl_stmt|;
specifier|const
name|char
modifier|*
name|oid_descr
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|SYSCTL_IN
parameter_list|(
name|r
parameter_list|,
name|p
parameter_list|,
name|l
parameter_list|)
value|(r->newfunc)(r, p, l)
end_define

begin_define
define|#
directive|define
name|SYSCTL_OUT
parameter_list|(
name|r
parameter_list|,
name|p
parameter_list|,
name|l
parameter_list|)
value|(r->oldfunc)(r, p, l)
end_define

begin_function_decl
name|int
name|sysctl_handle_int
parameter_list|(
name|SYSCTL_HANDLER_ARGS
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|sysctl_msec_to_ticks
parameter_list|(
name|SYSCTL_HANDLER_ARGS
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|sysctl_handle_long
parameter_list|(
name|SYSCTL_HANDLER_ARGS
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|sysctl_handle_64
parameter_list|(
name|SYSCTL_HANDLER_ARGS
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|sysctl_handle_string
parameter_list|(
name|SYSCTL_HANDLER_ARGS
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|sysctl_handle_opaque
parameter_list|(
name|SYSCTL_HANDLER_ARGS
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|sysctl_handle_counter_u64
parameter_list|(
name|SYSCTL_HANDLER_ARGS
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|sysctl_handle_uma_zone_max
parameter_list|(
name|SYSCTL_HANDLER_ARGS
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|sysctl_handle_uma_zone_cur
parameter_list|(
name|SYSCTL_HANDLER_ARGS
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|sysctl_dpcpu_int
parameter_list|(
name|SYSCTL_HANDLER_ARGS
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|sysctl_dpcpu_long
parameter_list|(
name|SYSCTL_HANDLER_ARGS
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|sysctl_dpcpu_quad
parameter_list|(
name|SYSCTL_HANDLER_ARGS
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * These functions are used to add/remove an oid from the mib.  */
end_comment

begin_function_decl
name|void
name|sysctl_register_oid
parameter_list|(
name|struct
name|sysctl_oid
modifier|*
name|oidp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|sysctl_unregister_oid
parameter_list|(
name|struct
name|sysctl_oid
modifier|*
name|oidp
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Declare a static oid to allow child oids to be added to it. */
end_comment

begin_define
define|#
directive|define
name|SYSCTL_DECL
parameter_list|(
name|name
parameter_list|)
define|\
value|extern struct sysctl_oid sysctl__##name
end_define

begin_comment
comment|/* Hide these in macros. */
end_comment

begin_define
define|#
directive|define
name|SYSCTL_CHILDREN
parameter_list|(
name|oid_ptr
parameter_list|)
value|(&(oid_ptr)->oid_children)
end_define

begin_define
define|#
directive|define
name|SYSCTL_PARENT
parameter_list|(
name|oid_ptr
parameter_list|)
define|\
value|(((oid_ptr)->oid_parent !=&sysctl__children) ?		\ 	__containerof((oid_ptr)->oid_parent, struct sysctl_oid,	\ 	oid_children) : (struct sysctl_oid *)NULL)
end_define

begin_define
define|#
directive|define
name|SYSCTL_STATIC_CHILDREN
parameter_list|(
name|oid_name
parameter_list|)
value|(&sysctl__##oid_name.oid_children)
end_define

begin_comment
comment|/* === Structs and macros related to context handling. === */
end_comment

begin_comment
comment|/* All dynamically created sysctls can be tracked in a context list. */
end_comment

begin_struct
struct|struct
name|sysctl_ctx_entry
block|{
name|struct
name|sysctl_oid
modifier|*
name|entry
decl_stmt|;
name|TAILQ_ENTRY
argument_list|(
argument|sysctl_ctx_entry
argument_list|)
name|link
expr_stmt|;
block|}
struct|;
end_struct

begin_expr_stmt
name|TAILQ_HEAD
argument_list|(
name|sysctl_ctx_list
argument_list|,
name|sysctl_ctx_entry
argument_list|)
expr_stmt|;
end_expr_stmt

begin_define
define|#
directive|define
name|SYSCTL_NODE_CHILDREN
parameter_list|(
name|parent
parameter_list|,
name|name
parameter_list|)
define|\
value|sysctl__##parent##_##name.oid_children
end_define

begin_comment
comment|/*  * These macros provide type safety for sysctls.  SYSCTL_ALLOWED_TYPES()  * defines a transparent union of the allowed types.  SYSCTL_ASSERT_TYPE()  * and SYSCTL_ADD_ASSERT_TYPE() use the transparent union to assert that  * the pointer matches the allowed types.  *  * The allow_0 member allows a literal 0 to be passed for ptr.  */
end_comment

begin_define
define|#
directive|define
name|SYSCTL_ALLOWED_TYPES
parameter_list|(
name|type
parameter_list|,
name|decls
parameter_list|)
define|\
value|union sysctl_##type {					\ 		long allow_0;					\ 		decls						\ 	} __attribute__((__transparent_union__));		\ 								\ 	static inline void *					\ 	__sysctl_assert_##type(union sysctl_##type ptr)		\ 	{							\ 		return (ptr.a);					\ 	}							\ 	struct __hack
end_define

begin_macro
name|SYSCTL_ALLOWED_TYPES
argument_list|(
argument|INT
argument_list|,
argument|int *a;
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_macro
name|SYSCTL_ALLOWED_TYPES
argument_list|(
argument|UINT
argument_list|,
argument|unsigned int *a;
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_macro
name|SYSCTL_ALLOWED_TYPES
argument_list|(
argument|LONG
argument_list|,
argument|long *a;
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_macro
name|SYSCTL_ALLOWED_TYPES
argument_list|(
argument|ULONG
argument_list|,
argument|unsigned long *a;
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_macro
name|SYSCTL_ALLOWED_TYPES
argument_list|(
argument|INT64
argument_list|,
argument|int64_t *a; long long *b;
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_macro
name|SYSCTL_ALLOWED_TYPES
argument_list|(
argument|UINT64
argument_list|,
argument|uint64_t *a; unsigned long long *b;
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_ifdef
ifdef|#
directive|ifdef
name|notyet
end_ifdef

begin_define
define|#
directive|define
name|SYSCTL_ADD_ASSERT_TYPE
parameter_list|(
name|type
parameter_list|,
name|ptr
parameter_list|)
define|\
value|__sysctl_assert_ ## type (ptr)
end_define

begin_define
define|#
directive|define
name|SYSCTL_ASSERT_TYPE
parameter_list|(
name|type
parameter_list|,
name|ptr
parameter_list|,
name|parent
parameter_list|,
name|name
parameter_list|)
define|\
value|_SYSCTL_ASSERT_TYPE(type, ptr, __LINE__, parent##_##name)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|SYSCTL_ADD_ASSERT_TYPE
parameter_list|(
name|type
parameter_list|,
name|ptr
parameter_list|)
value|ptr
end_define

begin_define
define|#
directive|define
name|SYSCTL_ASSERT_TYPE
parameter_list|(
name|type
parameter_list|,
name|ptr
parameter_list|,
name|parent
parameter_list|,
name|name
parameter_list|)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|_SYSCTL_ASSERT_TYPE
parameter_list|(
name|t
parameter_list|,
name|p
parameter_list|,
name|l
parameter_list|,
name|id
parameter_list|)
define|\
value|__SYSCTL_ASSERT_TYPE(t, p, l, id)
end_define

begin_define
define|#
directive|define
name|__SYSCTL_ASSERT_TYPE
parameter_list|(
name|type
parameter_list|,
name|ptr
parameter_list|,
name|line
parameter_list|,
name|id
parameter_list|)
define|\
value|static inline void						\ 	sysctl_assert_##line##_##id(void)				\ 	{								\ 		(void)__sysctl_assert_##type(ptr);			\ 	}								\ 	struct __hack
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|NO_SYSCTL_DESCR
end_ifndef

begin_define
define|#
directive|define
name|__DESCR
parameter_list|(
name|d
parameter_list|)
value|d
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|__DESCR
parameter_list|(
name|d
parameter_list|)
value|""
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* This macro is only for internal use */
end_comment

begin_define
define|#
directive|define
name|SYSCTL_OID_RAW
parameter_list|(
name|id
parameter_list|,
name|parent_child_head
parameter_list|,
name|nbr
parameter_list|,
name|name
parameter_list|,
name|kind
parameter_list|,
name|a1
parameter_list|,
name|a2
parameter_list|,
name|handler
parameter_list|,
name|fmt
parameter_list|,
name|descr
parameter_list|)
define|\
value|struct sysctl_oid id = {					\ 		.oid_parent = (parent_child_head),			\ 		.oid_children = SLIST_HEAD_INITIALIZER(&id.oid_children), \ 		.oid_number = (nbr),					\ 		.oid_kind = (kind),					\ 		.oid_arg1 = (a1),					\ 		.oid_arg2 = (a2),					\ 		.oid_name = (name),					\ 		.oid_handler = (handler),				\ 		.oid_fmt = (fmt),					\ 		.oid_descr = __DESCR(descr)				\ 	};								\ 	DATA_SET(sysctl_set, id)
end_define

begin_comment
comment|/* This constructs a static "raw" MIB oid. */
end_comment

begin_define
define|#
directive|define
name|SYSCTL_OID
parameter_list|(
name|parent
parameter_list|,
name|nbr
parameter_list|,
name|name
parameter_list|,
name|kind
parameter_list|,
name|a1
parameter_list|,
name|a2
parameter_list|,
name|handler
parameter_list|,
name|fmt
parameter_list|,
name|descr
parameter_list|)
define|\
value|static SYSCTL_OID_RAW(sysctl__##parent##_##name, \ 	SYSCTL_CHILDREN(&sysctl__##parent), \ 	nbr, #name, kind, a1, a2, handler, fmt, descr)
end_define

begin_comment
comment|/* This constructs a global "raw" MIB oid. */
end_comment

begin_define
define|#
directive|define
name|SYSCTL_OID_GLOBAL
parameter_list|(
name|parent
parameter_list|,
name|nbr
parameter_list|,
name|name
parameter_list|,
name|kind
parameter_list|,
name|a1
parameter_list|,
name|a2
parameter_list|,
name|handler
parameter_list|,
name|fmt
parameter_list|,
name|descr
parameter_list|)
define|\
value|SYSCTL_OID_RAW(sysctl__##parent##_##name, \ 	SYSCTL_CHILDREN(&sysctl__##parent),	\ 	nbr, #name, kind, a1, a2, handler, fmt, descr)
end_define

begin_define
define|#
directive|define
name|SYSCTL_ADD_OID
parameter_list|(
name|ctx
parameter_list|,
name|parent
parameter_list|,
name|nbr
parameter_list|,
name|name
parameter_list|,
name|kind
parameter_list|,
name|a1
parameter_list|,
name|a2
parameter_list|,
name|handler
parameter_list|,
name|fmt
parameter_list|,
name|descr
parameter_list|)
define|\
value|sysctl_add_oid(ctx, parent, nbr, name, kind, a1, a2, handler, fmt, __DESCR(descr))
end_define

begin_comment
comment|/* This constructs a root node from which other nodes can hang. */
end_comment

begin_define
define|#
directive|define
name|SYSCTL_ROOT_NODE
parameter_list|(
name|nbr
parameter_list|,
name|name
parameter_list|,
name|access
parameter_list|,
name|handler
parameter_list|,
name|descr
parameter_list|)
define|\
value|SYSCTL_OID_RAW(sysctl___##name,&sysctl__children,	\ 		nbr, #name, CTLTYPE_NODE|(access), NULL, 0,	\ 		handler, "N", descr)
end_define

begin_comment
comment|/* This constructs a node from which other oids can hang. */
end_comment

begin_define
define|#
directive|define
name|SYSCTL_NODE
parameter_list|(
name|parent
parameter_list|,
name|nbr
parameter_list|,
name|name
parameter_list|,
name|access
parameter_list|,
name|handler
parameter_list|,
name|descr
parameter_list|)
define|\
value|SYSCTL_OID_GLOBAL(parent, nbr, name, CTLTYPE_NODE|(access),	    \ 		NULL, 0, handler, "N", descr)
end_define

begin_define
define|#
directive|define
name|SYSCTL_ADD_NODE
parameter_list|(
name|ctx
parameter_list|,
name|parent
parameter_list|,
name|nbr
parameter_list|,
name|name
parameter_list|,
name|access
parameter_list|,
name|handler
parameter_list|,
name|descr
parameter_list|)
define|\
value|sysctl_add_oid(ctx, parent, nbr, name, CTLTYPE_NODE|(access),	    \ 	NULL, 0, handler, "N", __DESCR(descr))
end_define

begin_define
define|#
directive|define
name|SYSCTL_ADD_ROOT_NODE
parameter_list|(
name|ctx
parameter_list|,
name|nbr
parameter_list|,
name|name
parameter_list|,
name|access
parameter_list|,
name|handler
parameter_list|,
name|descr
parameter_list|)
define|\
value|sysctl_add_oid(ctx,&sysctl__children, nbr, name,		\         CTLTYPE_NODE|(access), NULL, 0, handler, "N", __DESCR(descr))
end_define

begin_comment
comment|/* Oid for a string.  len can be 0 to indicate '\0' termination. */
end_comment

begin_define
define|#
directive|define
name|SYSCTL_STRING
parameter_list|(
name|parent
parameter_list|,
name|nbr
parameter_list|,
name|name
parameter_list|,
name|access
parameter_list|,
name|arg
parameter_list|,
name|len
parameter_list|,
name|descr
parameter_list|)
define|\
value|SYSCTL_OID(parent, nbr, name, CTLTYPE_STRING|(access), \ 		arg, len, sysctl_handle_string, "A", descr)
end_define

begin_define
define|#
directive|define
name|SYSCTL_ADD_STRING
parameter_list|(
name|ctx
parameter_list|,
name|parent
parameter_list|,
name|nbr
parameter_list|,
name|name
parameter_list|,
name|access
parameter_list|,
name|arg
parameter_list|,
name|len
parameter_list|,
name|descr
parameter_list|)
define|\
value|sysctl_add_oid(ctx, parent, nbr, name, CTLTYPE_STRING|(access),	    \ 	arg, len, sysctl_handle_string, "A", __DESCR(descr))
end_define

begin_comment
comment|/* Oid for an int.  If ptr is NULL, val is returned. */
end_comment

begin_define
define|#
directive|define
name|SYSCTL_INT
parameter_list|(
name|parent
parameter_list|,
name|nbr
parameter_list|,
name|name
parameter_list|,
name|access
parameter_list|,
name|ptr
parameter_list|,
name|val
parameter_list|,
name|descr
parameter_list|)
define|\
value|SYSCTL_ASSERT_TYPE(INT, ptr, parent, name);			\ 	SYSCTL_OID(parent, nbr, name,					\ 	    CTLTYPE_INT | CTLFLAG_MPSAFE | (access),			\ 	    ptr, val, sysctl_handle_int, "I", descr)
end_define

begin_define
define|#
directive|define
name|SYSCTL_ADD_INT
parameter_list|(
name|ctx
parameter_list|,
name|parent
parameter_list|,
name|nbr
parameter_list|,
name|name
parameter_list|,
name|access
parameter_list|,
name|ptr
parameter_list|,
name|val
parameter_list|,
name|descr
parameter_list|)
define|\
value|sysctl_add_oid(ctx, parent, nbr, name,				\ 	    CTLTYPE_INT | CTLFLAG_MPSAFE | (access),			\ 	    SYSCTL_ADD_ASSERT_TYPE(INT, ptr), val,			\ 	    sysctl_handle_int, "I", __DESCR(descr))
end_define

begin_comment
comment|/* Oid for an unsigned int.  If ptr is NULL, val is returned. */
end_comment

begin_define
define|#
directive|define
name|SYSCTL_UINT
parameter_list|(
name|parent
parameter_list|,
name|nbr
parameter_list|,
name|name
parameter_list|,
name|access
parameter_list|,
name|ptr
parameter_list|,
name|val
parameter_list|,
name|descr
parameter_list|)
define|\
value|SYSCTL_ASSERT_TYPE(UINT, ptr, parent, name);			\ 	SYSCTL_OID(parent, nbr, name,					\ 	    CTLTYPE_UINT | CTLFLAG_MPSAFE | (access),			\ 	    ptr, val, sysctl_handle_int, "IU", descr)
end_define

begin_define
define|#
directive|define
name|SYSCTL_ADD_UINT
parameter_list|(
name|ctx
parameter_list|,
name|parent
parameter_list|,
name|nbr
parameter_list|,
name|name
parameter_list|,
name|access
parameter_list|,
name|ptr
parameter_list|,
name|val
parameter_list|,
name|descr
parameter_list|)
define|\
value|sysctl_add_oid(ctx, parent, nbr, name,				\ 	    CTLTYPE_UINT | CTLFLAG_MPSAFE | (access),			\ 	    SYSCTL_ADD_ASSERT_TYPE(UINT, ptr), val,			\ 	    sysctl_handle_int, "IU", __DESCR(descr))
end_define

begin_comment
comment|/* Oid for a long.  The pointer must be non NULL. */
end_comment

begin_define
define|#
directive|define
name|SYSCTL_LONG
parameter_list|(
name|parent
parameter_list|,
name|nbr
parameter_list|,
name|name
parameter_list|,
name|access
parameter_list|,
name|ptr
parameter_list|,
name|val
parameter_list|,
name|descr
parameter_list|)
define|\
value|SYSCTL_ASSERT_TYPE(LONG, ptr, parent, name);			\ 	SYSCTL_OID(parent, nbr, name,					\ 	    CTLTYPE_LONG | CTLFLAG_MPSAFE | (access),			\ 	    ptr, val, sysctl_handle_long, "L", descr)
end_define

begin_define
define|#
directive|define
name|SYSCTL_ADD_LONG
parameter_list|(
name|ctx
parameter_list|,
name|parent
parameter_list|,
name|nbr
parameter_list|,
name|name
parameter_list|,
name|access
parameter_list|,
name|ptr
parameter_list|,
name|descr
parameter_list|)
define|\
value|sysctl_add_oid(ctx, parent, nbr, name,				\ 	    CTLTYPE_LONG | CTLFLAG_MPSAFE | (access),			\ 	    SYSCTL_ADD_ASSERT_TYPE(LONG, ptr), 0,			\ 	    sysctl_handle_long,	"L", __DESCR(descr))
end_define

begin_comment
comment|/* Oid for an unsigned long.  The pointer must be non NULL. */
end_comment

begin_define
define|#
directive|define
name|SYSCTL_ULONG
parameter_list|(
name|parent
parameter_list|,
name|nbr
parameter_list|,
name|name
parameter_list|,
name|access
parameter_list|,
name|ptr
parameter_list|,
name|val
parameter_list|,
name|descr
parameter_list|)
define|\
value|SYSCTL_ASSERT_TYPE(ULONG, ptr, parent, name);			\ 	SYSCTL_OID(parent, nbr, name,					\ 	    CTLTYPE_ULONG | CTLFLAG_MPSAFE | (access),			\ 	    ptr, val, sysctl_handle_long, "LU", descr)
end_define

begin_define
define|#
directive|define
name|SYSCTL_ADD_ULONG
parameter_list|(
name|ctx
parameter_list|,
name|parent
parameter_list|,
name|nbr
parameter_list|,
name|name
parameter_list|,
name|access
parameter_list|,
name|ptr
parameter_list|,
name|descr
parameter_list|)
define|\
value|sysctl_add_oid(ctx, parent, nbr, name,				\ 	    CTLTYPE_ULONG | CTLFLAG_MPSAFE | (access),			\ 	    SYSCTL_ADD_ASSERT_TYPE(ULONG, ptr), 0,			\ 	    sysctl_handle_long, "LU", __DESCR(descr))
end_define

begin_comment
comment|/* Oid for a quad.  The pointer must be non NULL. */
end_comment

begin_define
define|#
directive|define
name|SYSCTL_QUAD
parameter_list|(
name|parent
parameter_list|,
name|nbr
parameter_list|,
name|name
parameter_list|,
name|access
parameter_list|,
name|ptr
parameter_list|,
name|val
parameter_list|,
name|descr
parameter_list|)
define|\
value|SYSCTL_ASSERT_TYPE(INT64, ptr, parent, name);			\ 	SYSCTL_OID(parent, nbr, name,					\ 	    CTLTYPE_S64 | CTLFLAG_MPSAFE | (access),			\ 	    ptr, val, sysctl_handle_64, "Q", descr)
end_define

begin_define
define|#
directive|define
name|SYSCTL_ADD_QUAD
parameter_list|(
name|ctx
parameter_list|,
name|parent
parameter_list|,
name|nbr
parameter_list|,
name|name
parameter_list|,
name|access
parameter_list|,
name|ptr
parameter_list|,
name|descr
parameter_list|)
define|\
value|sysctl_add_oid(ctx, parent, nbr, name,				\ 	    CTLTYPE_S64 | CTLFLAG_MPSAFE | (access),			\ 	    SYSCTL_ADD_ASSERT_TYPE(INT64, ptr), 0,			\ 	    sysctl_handle_64, "Q", __DESCR(descr))
end_define

begin_define
define|#
directive|define
name|SYSCTL_UQUAD
parameter_list|(
name|parent
parameter_list|,
name|nbr
parameter_list|,
name|name
parameter_list|,
name|access
parameter_list|,
name|ptr
parameter_list|,
name|val
parameter_list|,
name|descr
parameter_list|)
define|\
value|SYSCTL_ASSERT_TYPE(UINT64, ptr, parent, name);			\ 	SYSCTL_OID(parent, nbr, name,					\ 	    CTLTYPE_U64 | CTLFLAG_MPSAFE | (access),			\ 	    ptr, val, sysctl_handle_64, "QU", descr)
end_define

begin_define
define|#
directive|define
name|SYSCTL_ADD_UQUAD
parameter_list|(
name|ctx
parameter_list|,
name|parent
parameter_list|,
name|nbr
parameter_list|,
name|name
parameter_list|,
name|access
parameter_list|,
name|ptr
parameter_list|,
name|descr
parameter_list|)
define|\
value|sysctl_add_oid(ctx, parent, nbr, name,				\ 	    CTLTYPE_U64 | CTLFLAG_MPSAFE | (access),			\ 	    SYSCTL_ADD_ASSERT_TYPE(UINT64, ptr), 0,			\ 	    sysctl_handle_64, "QU", __DESCR(descr))
end_define

begin_comment
comment|/* Oid for a 64-bit unsigned counter(9).  The pointer must be non NULL. */
end_comment

begin_define
define|#
directive|define
name|SYSCTL_COUNTER_U64
parameter_list|(
name|parent
parameter_list|,
name|nbr
parameter_list|,
name|name
parameter_list|,
name|access
parameter_list|,
name|ptr
parameter_list|,
name|descr
parameter_list|)
define|\
value|SYSCTL_ASSERT_TYPE(UINT64, ptr, parent, name);			\ 	SYSCTL_OID(parent, nbr, name,					\ 	    CTLTYPE_U64 | CTLFLAG_MPSAFE | (access),			\ 	    ptr, 0, sysctl_handle_counter_u64, "QU", descr)
end_define

begin_define
define|#
directive|define
name|SYSCTL_ADD_COUNTER_U64
parameter_list|(
name|ctx
parameter_list|,
name|parent
parameter_list|,
name|nbr
parameter_list|,
name|name
parameter_list|,
name|access
parameter_list|,
name|ptr
parameter_list|,
name|descr
parameter_list|)
define|\
value|sysctl_add_oid(ctx, parent, nbr, name,				\ 	    CTLTYPE_U64 | CTLFLAG_MPSAFE | (access),			\ 	    SYSCTL_ADD_ASSERT_TYPE(UINT64, ptr), 0,			\ 	    sysctl_handle_counter_u64, "QU", __DESCR(descr))
end_define

begin_comment
comment|/* Oid for an opaque object.  Specified by a pointer and a length. */
end_comment

begin_define
define|#
directive|define
name|SYSCTL_OPAQUE
parameter_list|(
name|parent
parameter_list|,
name|nbr
parameter_list|,
name|name
parameter_list|,
name|access
parameter_list|,
name|ptr
parameter_list|,
name|len
parameter_list|,
name|fmt
parameter_list|,
name|descr
parameter_list|)
define|\
value|SYSCTL_OID(parent, nbr, name, CTLTYPE_OPAQUE|(access), \ 		ptr, len, sysctl_handle_opaque, fmt, descr)
end_define

begin_define
define|#
directive|define
name|SYSCTL_ADD_OPAQUE
parameter_list|(
name|ctx
parameter_list|,
name|parent
parameter_list|,
name|nbr
parameter_list|,
name|name
parameter_list|,
name|access
parameter_list|,
name|ptr
parameter_list|,
name|len
parameter_list|,
name|fmt
parameter_list|,
name|descr
parameter_list|)
define|\
value|sysctl_add_oid(ctx, parent, nbr, name, CTLTYPE_OPAQUE|(access),	    \ 	ptr, len, sysctl_handle_opaque, fmt, __DESCR(descr))
end_define

begin_comment
comment|/* Oid for a struct.  Specified by a pointer and a type. */
end_comment

begin_define
define|#
directive|define
name|SYSCTL_STRUCT
parameter_list|(
name|parent
parameter_list|,
name|nbr
parameter_list|,
name|name
parameter_list|,
name|access
parameter_list|,
name|ptr
parameter_list|,
name|type
parameter_list|,
name|descr
parameter_list|)
define|\
value|SYSCTL_OID(parent, nbr, name, CTLTYPE_OPAQUE|(access), \ 		ptr, sizeof(struct type), sysctl_handle_opaque, \ 		"S," #type, descr)
end_define

begin_define
define|#
directive|define
name|SYSCTL_ADD_STRUCT
parameter_list|(
name|ctx
parameter_list|,
name|parent
parameter_list|,
name|nbr
parameter_list|,
name|name
parameter_list|,
name|access
parameter_list|,
name|ptr
parameter_list|,
name|type
parameter_list|,
name|descr
parameter_list|)
define|\
value|sysctl_add_oid(ctx, parent, nbr, name, CTLTYPE_OPAQUE|(access),	    \ 	ptr, sizeof(struct type), sysctl_handle_opaque, "S," #type, __DESCR(descr))
end_define

begin_comment
comment|/* Oid for a procedure.  Specified by a pointer and an arg. */
end_comment

begin_define
define|#
directive|define
name|SYSCTL_PROC
parameter_list|(
name|parent
parameter_list|,
name|nbr
parameter_list|,
name|name
parameter_list|,
name|access
parameter_list|,
name|ptr
parameter_list|,
name|arg
parameter_list|,
name|handler
parameter_list|,
name|fmt
parameter_list|,
name|descr
parameter_list|)
define|\
value|CTASSERT(((access)& CTLTYPE) != 0);				\ 	SYSCTL_OID(parent, nbr, name, (access), \ 		ptr, arg, handler, fmt, descr)
end_define

begin_define
define|#
directive|define
name|SYSCTL_ADD_PROC
parameter_list|(
name|ctx
parameter_list|,
name|parent
parameter_list|,
name|nbr
parameter_list|,
name|name
parameter_list|,
name|access
parameter_list|,
name|ptr
parameter_list|,
name|arg
parameter_list|,
name|handler
parameter_list|,
name|fmt
parameter_list|,
name|descr
parameter_list|)
define|\
value|sysctl_add_oid(ctx, parent, nbr, name, (access),			    \ 	ptr, arg, handler, fmt, __DESCR(descr))
end_define

begin_comment
comment|/* Oid to handle limits on uma(9) zone specified by pointer. */
end_comment

begin_define
define|#
directive|define
name|SYSCTL_UMA_MAX
parameter_list|(
name|parent
parameter_list|,
name|nbr
parameter_list|,
name|name
parameter_list|,
name|access
parameter_list|,
name|ptr
parameter_list|,
name|descr
parameter_list|)
define|\
value|SYSCTL_ASSERT_TYPE(INT, ptr, parent, name);			\ 	SYSCTL_OID(parent, nbr, name,					\ 	    CTLTYPE_INT | CTLFLAG_MPSAFE | (access),			\ 	    ptr, 0, sysctl_handle_uma_zone_max, "I", descr)
end_define

begin_define
define|#
directive|define
name|SYSCTL_ADD_UMA_MAX
parameter_list|(
name|ctx
parameter_list|,
name|parent
parameter_list|,
name|nbr
parameter_list|,
name|name
parameter_list|,
name|access
parameter_list|,
name|ptr
parameter_list|,
name|descr
parameter_list|)
define|\
value|sysctl_add_oid(ctx, parent, nbr, name,				\ 	    CTLTYPE_INT | CTLFLAG_MPSAFE | (access),			\ 	    SYSCTL_ADD_ASSERT_TYPE(INT, ptr), 0,			\ 	    sysctl_handle_uma_zone_max, "I", __DESCR(descr))
end_define

begin_comment
comment|/* Oid to obtain current use of uma(9) zone specified by pointer. */
end_comment

begin_define
define|#
directive|define
name|SYSCTL_UMA_CUR
parameter_list|(
name|parent
parameter_list|,
name|nbr
parameter_list|,
name|name
parameter_list|,
name|access
parameter_list|,
name|ptr
parameter_list|,
name|descr
parameter_list|)
define|\
value|SYSCTL_ASSERT_TYPE(INT, ptr, parent, name);			\ 	SYSCTL_OID(parent, nbr, name,					\ 	    CTLTYPE_INT | CTLFLAG_MPSAFE | CTLFLAG_RD | (access),	\ 	    ptr, 0, sysctl_handle_uma_zone_cur, "I", descr)
end_define

begin_define
define|#
directive|define
name|SYSCTL_ADD_UMA_CUR
parameter_list|(
name|ctx
parameter_list|,
name|parent
parameter_list|,
name|nbr
parameter_list|,
name|name
parameter_list|,
name|access
parameter_list|,
name|ptr
parameter_list|,
name|descr
parameter_list|)
define|\
value|sysctl_add_oid(ctx, parent, nbr, name,				\ 	    CTLTYPE_INT | CTLFLAG_MPSAFE | CTLFLAG_RD | (access),	\ 	    SYSCTL_ADD_ASSERT_TYPE(INT, ptr), 0,			\ 	    sysctl_handle_uma_zone_cur, "I", __DESCR(descr))
end_define

begin_comment
comment|/*  * A macro to generate a read-only sysctl to indicate the presense of optional  * kernel features.  */
end_comment

begin_define
define|#
directive|define
name|FEATURE
parameter_list|(
name|name
parameter_list|,
name|desc
parameter_list|)
define|\
value|SYSCTL_INT(_kern_features, OID_AUTO, name, CTLFLAG_RD | CTLFLAG_CAPRD, \ 	    NULL, 1, desc)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _KERNEL */
end_comment

begin_comment
comment|/*  * Top-level identifiers  */
end_comment

begin_define
define|#
directive|define
name|CTL_UNSPEC
value|0
end_define

begin_comment
comment|/* unused */
end_comment

begin_define
define|#
directive|define
name|CTL_KERN
value|1
end_define

begin_comment
comment|/* "high kernel": proc, limits */
end_comment

begin_define
define|#
directive|define
name|CTL_VM
value|2
end_define

begin_comment
comment|/* virtual memory */
end_comment

begin_define
define|#
directive|define
name|CTL_VFS
value|3
end_define

begin_comment
comment|/* filesystem, mount type is next */
end_comment

begin_define
define|#
directive|define
name|CTL_NET
value|4
end_define

begin_comment
comment|/* network, see socket.h */
end_comment

begin_define
define|#
directive|define
name|CTL_DEBUG
value|5
end_define

begin_comment
comment|/* debugging parameters */
end_comment

begin_define
define|#
directive|define
name|CTL_HW
value|6
end_define

begin_comment
comment|/* generic cpu/io */
end_comment

begin_define
define|#
directive|define
name|CTL_MACHDEP
value|7
end_define

begin_comment
comment|/* machine dependent */
end_comment

begin_define
define|#
directive|define
name|CTL_USER
value|8
end_define

begin_comment
comment|/* user-level */
end_comment

begin_define
define|#
directive|define
name|CTL_P1003_1B
value|9
end_define

begin_comment
comment|/* POSIX 1003.1B */
end_comment

begin_comment
comment|/*  * CTL_KERN identifiers  */
end_comment

begin_define
define|#
directive|define
name|KERN_OSTYPE
value|1
end_define

begin_comment
comment|/* string: system version */
end_comment

begin_define
define|#
directive|define
name|KERN_OSRELEASE
value|2
end_define

begin_comment
comment|/* string: system release */
end_comment

begin_define
define|#
directive|define
name|KERN_OSREV
value|3
end_define

begin_comment
comment|/* int: system revision */
end_comment

begin_define
define|#
directive|define
name|KERN_VERSION
value|4
end_define

begin_comment
comment|/* string: compile time info */
end_comment

begin_define
define|#
directive|define
name|KERN_MAXVNODES
value|5
end_define

begin_comment
comment|/* int: max vnodes */
end_comment

begin_define
define|#
directive|define
name|KERN_MAXPROC
value|6
end_define

begin_comment
comment|/* int: max processes */
end_comment

begin_define
define|#
directive|define
name|KERN_MAXFILES
value|7
end_define

begin_comment
comment|/* int: max open files */
end_comment

begin_define
define|#
directive|define
name|KERN_ARGMAX
value|8
end_define

begin_comment
comment|/* int: max arguments to exec */
end_comment

begin_define
define|#
directive|define
name|KERN_SECURELVL
value|9
end_define

begin_comment
comment|/* int: system security level */
end_comment

begin_define
define|#
directive|define
name|KERN_HOSTNAME
value|10
end_define

begin_comment
comment|/* string: hostname */
end_comment

begin_define
define|#
directive|define
name|KERN_HOSTID
value|11
end_define

begin_comment
comment|/* int: host identifier */
end_comment

begin_define
define|#
directive|define
name|KERN_CLOCKRATE
value|12
end_define

begin_comment
comment|/* struct: struct clockrate */
end_comment

begin_define
define|#
directive|define
name|KERN_VNODE
value|13
end_define

begin_comment
comment|/* struct: vnode structures */
end_comment

begin_define
define|#
directive|define
name|KERN_PROC
value|14
end_define

begin_comment
comment|/* struct: process entries */
end_comment

begin_define
define|#
directive|define
name|KERN_FILE
value|15
end_define

begin_comment
comment|/* struct: file entries */
end_comment

begin_define
define|#
directive|define
name|KERN_PROF
value|16
end_define

begin_comment
comment|/* node: kernel profiling info */
end_comment

begin_define
define|#
directive|define
name|KERN_POSIX1
value|17
end_define

begin_comment
comment|/* int: POSIX.1 version */
end_comment

begin_define
define|#
directive|define
name|KERN_NGROUPS
value|18
end_define

begin_comment
comment|/* int: # of supplemental group ids */
end_comment

begin_define
define|#
directive|define
name|KERN_JOB_CONTROL
value|19
end_define

begin_comment
comment|/* int: is job control available */
end_comment

begin_define
define|#
directive|define
name|KERN_SAVED_IDS
value|20
end_define

begin_comment
comment|/* int: saved set-user/group-ID */
end_comment

begin_define
define|#
directive|define
name|KERN_BOOTTIME
value|21
end_define

begin_comment
comment|/* struct: time kernel was booted */
end_comment

begin_define
define|#
directive|define
name|KERN_NISDOMAINNAME
value|22
end_define

begin_comment
comment|/* string: YP domain name */
end_comment

begin_define
define|#
directive|define
name|KERN_UPDATEINTERVAL
value|23
end_define

begin_comment
comment|/* int: update process sleep time */
end_comment

begin_define
define|#
directive|define
name|KERN_OSRELDATE
value|24
end_define

begin_comment
comment|/* int: kernel release date */
end_comment

begin_define
define|#
directive|define
name|KERN_NTP_PLL
value|25
end_define

begin_comment
comment|/* node: NTP PLL control */
end_comment

begin_define
define|#
directive|define
name|KERN_BOOTFILE
value|26
end_define

begin_comment
comment|/* string: name of booted kernel */
end_comment

begin_define
define|#
directive|define
name|KERN_MAXFILESPERPROC
value|27
end_define

begin_comment
comment|/* int: max open files per proc */
end_comment

begin_define
define|#
directive|define
name|KERN_MAXPROCPERUID
value|28
end_define

begin_comment
comment|/* int: max processes per uid */
end_comment

begin_define
define|#
directive|define
name|KERN_DUMPDEV
value|29
end_define

begin_comment
comment|/* struct cdev *: device to dump on */
end_comment

begin_define
define|#
directive|define
name|KERN_IPC
value|30
end_define

begin_comment
comment|/* node: anything related to IPC */
end_comment

begin_define
define|#
directive|define
name|KERN_DUMMY
value|31
end_define

begin_comment
comment|/* unused */
end_comment

begin_define
define|#
directive|define
name|KERN_PS_STRINGS
value|32
end_define

begin_comment
comment|/* int: address of PS_STRINGS */
end_comment

begin_define
define|#
directive|define
name|KERN_USRSTACK
value|33
end_define

begin_comment
comment|/* int: address of USRSTACK */
end_comment

begin_define
define|#
directive|define
name|KERN_LOGSIGEXIT
value|34
end_define

begin_comment
comment|/* int: do we log sigexit procs? */
end_comment

begin_define
define|#
directive|define
name|KERN_IOV_MAX
value|35
end_define

begin_comment
comment|/* int: value of UIO_MAXIOV */
end_comment

begin_define
define|#
directive|define
name|KERN_HOSTUUID
value|36
end_define

begin_comment
comment|/* string: host UUID identifier */
end_comment

begin_define
define|#
directive|define
name|KERN_ARND
value|37
end_define

begin_comment
comment|/* int: from arc4rand() */
end_comment

begin_comment
comment|/*  * KERN_PROC subtypes  */
end_comment

begin_define
define|#
directive|define
name|KERN_PROC_ALL
value|0
end_define

begin_comment
comment|/* everything */
end_comment

begin_define
define|#
directive|define
name|KERN_PROC_PID
value|1
end_define

begin_comment
comment|/* by process id */
end_comment

begin_define
define|#
directive|define
name|KERN_PROC_PGRP
value|2
end_define

begin_comment
comment|/* by process group id */
end_comment

begin_define
define|#
directive|define
name|KERN_PROC_SESSION
value|3
end_define

begin_comment
comment|/* by session of pid */
end_comment

begin_define
define|#
directive|define
name|KERN_PROC_TTY
value|4
end_define

begin_comment
comment|/* by controlling tty */
end_comment

begin_define
define|#
directive|define
name|KERN_PROC_UID
value|5
end_define

begin_comment
comment|/* by effective uid */
end_comment

begin_define
define|#
directive|define
name|KERN_PROC_RUID
value|6
end_define

begin_comment
comment|/* by real uid */
end_comment

begin_define
define|#
directive|define
name|KERN_PROC_ARGS
value|7
end_define

begin_comment
comment|/* get/set arguments/proctitle */
end_comment

begin_define
define|#
directive|define
name|KERN_PROC_PROC
value|8
end_define

begin_comment
comment|/* only return procs */
end_comment

begin_define
define|#
directive|define
name|KERN_PROC_SV_NAME
value|9
end_define

begin_comment
comment|/* get syscall vector name */
end_comment

begin_define
define|#
directive|define
name|KERN_PROC_RGID
value|10
end_define

begin_comment
comment|/* by real group id */
end_comment

begin_define
define|#
directive|define
name|KERN_PROC_GID
value|11
end_define

begin_comment
comment|/* by effective group id */
end_comment

begin_define
define|#
directive|define
name|KERN_PROC_PATHNAME
value|12
end_define

begin_comment
comment|/* path to executable */
end_comment

begin_define
define|#
directive|define
name|KERN_PROC_OVMMAP
value|13
end_define

begin_comment
comment|/* Old VM map entries for process */
end_comment

begin_define
define|#
directive|define
name|KERN_PROC_OFILEDESC
value|14
end_define

begin_comment
comment|/* Old file descriptors for process */
end_comment

begin_define
define|#
directive|define
name|KERN_PROC_KSTACK
value|15
end_define

begin_comment
comment|/* Kernel stacks for process */
end_comment

begin_define
define|#
directive|define
name|KERN_PROC_INC_THREAD
value|0x10
end_define

begin_comment
comment|/* 					 * modifier for pid, pgrp, tty, 					 * uid, ruid, gid, rgid and proc 					 * This effectively uses 16-31 					 */
end_comment

begin_define
define|#
directive|define
name|KERN_PROC_VMMAP
value|32
end_define

begin_comment
comment|/* VM map entries for process */
end_comment

begin_define
define|#
directive|define
name|KERN_PROC_FILEDESC
value|33
end_define

begin_comment
comment|/* File descriptors for process */
end_comment

begin_define
define|#
directive|define
name|KERN_PROC_GROUPS
value|34
end_define

begin_comment
comment|/* process groups */
end_comment

begin_define
define|#
directive|define
name|KERN_PROC_ENV
value|35
end_define

begin_comment
comment|/* get environment */
end_comment

begin_define
define|#
directive|define
name|KERN_PROC_AUXV
value|36
end_define

begin_comment
comment|/* get ELF auxiliary vector */
end_comment

begin_define
define|#
directive|define
name|KERN_PROC_RLIMIT
value|37
end_define

begin_comment
comment|/* process resource limits */
end_comment

begin_define
define|#
directive|define
name|KERN_PROC_PS_STRINGS
value|38
end_define

begin_comment
comment|/* get ps_strings location */
end_comment

begin_define
define|#
directive|define
name|KERN_PROC_UMASK
value|39
end_define

begin_comment
comment|/* process umask */
end_comment

begin_define
define|#
directive|define
name|KERN_PROC_OSREL
value|40
end_define

begin_comment
comment|/* osreldate for process binary */
end_comment

begin_define
define|#
directive|define
name|KERN_PROC_SIGTRAMP
value|41
end_define

begin_comment
comment|/* signal trampoline location */
end_comment

begin_comment
comment|/*  * KERN_IPC identifiers  */
end_comment

begin_define
define|#
directive|define
name|KIPC_MAXSOCKBUF
value|1
end_define

begin_comment
comment|/* int: max size of a socket buffer */
end_comment

begin_define
define|#
directive|define
name|KIPC_SOCKBUF_WASTE
value|2
end_define

begin_comment
comment|/* int: wastage factor in sockbuf */
end_comment

begin_define
define|#
directive|define
name|KIPC_SOMAXCONN
value|3
end_define

begin_comment
comment|/* int: max length of connection q */
end_comment

begin_define
define|#
directive|define
name|KIPC_MAX_LINKHDR
value|4
end_define

begin_comment
comment|/* int: max length of link header */
end_comment

begin_define
define|#
directive|define
name|KIPC_MAX_PROTOHDR
value|5
end_define

begin_comment
comment|/* int: max length of network header */
end_comment

begin_define
define|#
directive|define
name|KIPC_MAX_HDR
value|6
end_define

begin_comment
comment|/* int: max total length of headers */
end_comment

begin_define
define|#
directive|define
name|KIPC_MAX_DATALEN
value|7
end_define

begin_comment
comment|/* int: max length of data? */
end_comment

begin_comment
comment|/*  * CTL_HW identifiers  */
end_comment

begin_define
define|#
directive|define
name|HW_MACHINE
value|1
end_define

begin_comment
comment|/* string: machine class */
end_comment

begin_define
define|#
directive|define
name|HW_MODEL
value|2
end_define

begin_comment
comment|/* string: specific machine model */
end_comment

begin_define
define|#
directive|define
name|HW_NCPU
value|3
end_define

begin_comment
comment|/* int: number of cpus */
end_comment

begin_define
define|#
directive|define
name|HW_BYTEORDER
value|4
end_define

begin_comment
comment|/* int: machine byte order */
end_comment

begin_define
define|#
directive|define
name|HW_PHYSMEM
value|5
end_define

begin_comment
comment|/* int: total memory */
end_comment

begin_define
define|#
directive|define
name|HW_USERMEM
value|6
end_define

begin_comment
comment|/* int: non-kernel memory */
end_comment

begin_define
define|#
directive|define
name|HW_PAGESIZE
value|7
end_define

begin_comment
comment|/* int: software page size */
end_comment

begin_define
define|#
directive|define
name|HW_DISKNAMES
value|8
end_define

begin_comment
comment|/* strings: disk drive names */
end_comment

begin_define
define|#
directive|define
name|HW_DISKSTATS
value|9
end_define

begin_comment
comment|/* struct: diskstats[] */
end_comment

begin_define
define|#
directive|define
name|HW_FLOATINGPT
value|10
end_define

begin_comment
comment|/* int: has HW floating point? */
end_comment

begin_define
define|#
directive|define
name|HW_MACHINE_ARCH
value|11
end_define

begin_comment
comment|/* string: machine architecture */
end_comment

begin_define
define|#
directive|define
name|HW_REALMEM
value|12
end_define

begin_comment
comment|/* int: 'real' memory */
end_comment

begin_comment
comment|/*  * CTL_USER definitions  */
end_comment

begin_define
define|#
directive|define
name|USER_CS_PATH
value|1
end_define

begin_comment
comment|/* string: _CS_PATH */
end_comment

begin_define
define|#
directive|define
name|USER_BC_BASE_MAX
value|2
end_define

begin_comment
comment|/* int: BC_BASE_MAX */
end_comment

begin_define
define|#
directive|define
name|USER_BC_DIM_MAX
value|3
end_define

begin_comment
comment|/* int: BC_DIM_MAX */
end_comment

begin_define
define|#
directive|define
name|USER_BC_SCALE_MAX
value|4
end_define

begin_comment
comment|/* int: BC_SCALE_MAX */
end_comment

begin_define
define|#
directive|define
name|USER_BC_STRING_MAX
value|5
end_define

begin_comment
comment|/* int: BC_STRING_MAX */
end_comment

begin_define
define|#
directive|define
name|USER_COLL_WEIGHTS_MAX
value|6
end_define

begin_comment
comment|/* int: COLL_WEIGHTS_MAX */
end_comment

begin_define
define|#
directive|define
name|USER_EXPR_NEST_MAX
value|7
end_define

begin_comment
comment|/* int: EXPR_NEST_MAX */
end_comment

begin_define
define|#
directive|define
name|USER_LINE_MAX
value|8
end_define

begin_comment
comment|/* int: LINE_MAX */
end_comment

begin_define
define|#
directive|define
name|USER_RE_DUP_MAX
value|9
end_define

begin_comment
comment|/* int: RE_DUP_MAX */
end_comment

begin_define
define|#
directive|define
name|USER_POSIX2_VERSION
value|10
end_define

begin_comment
comment|/* int: POSIX2_VERSION */
end_comment

begin_define
define|#
directive|define
name|USER_POSIX2_C_BIND
value|11
end_define

begin_comment
comment|/* int: POSIX2_C_BIND */
end_comment

begin_define
define|#
directive|define
name|USER_POSIX2_C_DEV
value|12
end_define

begin_comment
comment|/* int: POSIX2_C_DEV */
end_comment

begin_define
define|#
directive|define
name|USER_POSIX2_CHAR_TERM
value|13
end_define

begin_comment
comment|/* int: POSIX2_CHAR_TERM */
end_comment

begin_define
define|#
directive|define
name|USER_POSIX2_FORT_DEV
value|14
end_define

begin_comment
comment|/* int: POSIX2_FORT_DEV */
end_comment

begin_define
define|#
directive|define
name|USER_POSIX2_FORT_RUN
value|15
end_define

begin_comment
comment|/* int: POSIX2_FORT_RUN */
end_comment

begin_define
define|#
directive|define
name|USER_POSIX2_LOCALEDEF
value|16
end_define

begin_comment
comment|/* int: POSIX2_LOCALEDEF */
end_comment

begin_define
define|#
directive|define
name|USER_POSIX2_SW_DEV
value|17
end_define

begin_comment
comment|/* int: POSIX2_SW_DEV */
end_comment

begin_define
define|#
directive|define
name|USER_POSIX2_UPE
value|18
end_define

begin_comment
comment|/* int: POSIX2_UPE */
end_comment

begin_define
define|#
directive|define
name|USER_STREAM_MAX
value|19
end_define

begin_comment
comment|/* int: POSIX2_STREAM_MAX */
end_comment

begin_define
define|#
directive|define
name|USER_TZNAME_MAX
value|20
end_define

begin_comment
comment|/* int: POSIX2_TZNAME_MAX */
end_comment

begin_define
define|#
directive|define
name|CTL_P1003_1B_ASYNCHRONOUS_IO
value|1
end_define

begin_comment
comment|/* boolean */
end_comment

begin_define
define|#
directive|define
name|CTL_P1003_1B_MAPPED_FILES
value|2
end_define

begin_comment
comment|/* boolean */
end_comment

begin_define
define|#
directive|define
name|CTL_P1003_1B_MEMLOCK
value|3
end_define

begin_comment
comment|/* boolean */
end_comment

begin_define
define|#
directive|define
name|CTL_P1003_1B_MEMLOCK_RANGE
value|4
end_define

begin_comment
comment|/* boolean */
end_comment

begin_define
define|#
directive|define
name|CTL_P1003_1B_MEMORY_PROTECTION
value|5
end_define

begin_comment
comment|/* boolean */
end_comment

begin_define
define|#
directive|define
name|CTL_P1003_1B_MESSAGE_PASSING
value|6
end_define

begin_comment
comment|/* boolean */
end_comment

begin_define
define|#
directive|define
name|CTL_P1003_1B_PRIORITIZED_IO
value|7
end_define

begin_comment
comment|/* boolean */
end_comment

begin_define
define|#
directive|define
name|CTL_P1003_1B_PRIORITY_SCHEDULING
value|8
end_define

begin_comment
comment|/* boolean */
end_comment

begin_define
define|#
directive|define
name|CTL_P1003_1B_REALTIME_SIGNALS
value|9
end_define

begin_comment
comment|/* boolean */
end_comment

begin_define
define|#
directive|define
name|CTL_P1003_1B_SEMAPHORES
value|10
end_define

begin_comment
comment|/* boolean */
end_comment

begin_define
define|#
directive|define
name|CTL_P1003_1B_FSYNC
value|11
end_define

begin_comment
comment|/* boolean */
end_comment

begin_define
define|#
directive|define
name|CTL_P1003_1B_SHARED_MEMORY_OBJECTS
value|12
end_define

begin_comment
comment|/* boolean */
end_comment

begin_define
define|#
directive|define
name|CTL_P1003_1B_SYNCHRONIZED_IO
value|13
end_define

begin_comment
comment|/* boolean */
end_comment

begin_define
define|#
directive|define
name|CTL_P1003_1B_TIMERS
value|14
end_define

begin_comment
comment|/* boolean */
end_comment

begin_define
define|#
directive|define
name|CTL_P1003_1B_AIO_LISTIO_MAX
value|15
end_define

begin_comment
comment|/* int */
end_comment

begin_define
define|#
directive|define
name|CTL_P1003_1B_AIO_MAX
value|16
end_define

begin_comment
comment|/* int */
end_comment

begin_define
define|#
directive|define
name|CTL_P1003_1B_AIO_PRIO_DELTA_MAX
value|17
end_define

begin_comment
comment|/* int */
end_comment

begin_define
define|#
directive|define
name|CTL_P1003_1B_DELAYTIMER_MAX
value|18
end_define

begin_comment
comment|/* int */
end_comment

begin_define
define|#
directive|define
name|CTL_P1003_1B_MQ_OPEN_MAX
value|19
end_define

begin_comment
comment|/* int */
end_comment

begin_define
define|#
directive|define
name|CTL_P1003_1B_PAGESIZE
value|20
end_define

begin_comment
comment|/* int */
end_comment

begin_define
define|#
directive|define
name|CTL_P1003_1B_RTSIG_MAX
value|21
end_define

begin_comment
comment|/* int */
end_comment

begin_define
define|#
directive|define
name|CTL_P1003_1B_SEM_NSEMS_MAX
value|22
end_define

begin_comment
comment|/* int */
end_comment

begin_define
define|#
directive|define
name|CTL_P1003_1B_SEM_VALUE_MAX
value|23
end_define

begin_comment
comment|/* int */
end_comment

begin_define
define|#
directive|define
name|CTL_P1003_1B_SIGQUEUE_MAX
value|24
end_define

begin_comment
comment|/* int */
end_comment

begin_define
define|#
directive|define
name|CTL_P1003_1B_TIMER_MAX
value|25
end_define

begin_comment
comment|/* int */
end_comment

begin_define
define|#
directive|define
name|CTL_P1003_1B_MAXID
value|26
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_comment
comment|/*  * Declare some common oids.  */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|sysctl_oid_list
name|sysctl__children
decl_stmt|;
end_decl_stmt

begin_expr_stmt
name|SYSCTL_DECL
argument_list|(
name|_kern
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|SYSCTL_DECL
argument_list|(
name|_kern_features
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|SYSCTL_DECL
argument_list|(
name|_kern_ipc
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|SYSCTL_DECL
argument_list|(
name|_kern_proc
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|SYSCTL_DECL
argument_list|(
name|_kern_sched
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|SYSCTL_DECL
argument_list|(
name|_kern_sched_stats
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|SYSCTL_DECL
argument_list|(
name|_sysctl
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|SYSCTL_DECL
argument_list|(
name|_vm
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|SYSCTL_DECL
argument_list|(
name|_vm_stats
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|SYSCTL_DECL
argument_list|(
name|_vm_stats_misc
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|SYSCTL_DECL
argument_list|(
name|_vfs
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|SYSCTL_DECL
argument_list|(
name|_net
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|SYSCTL_DECL
argument_list|(
name|_debug
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|SYSCTL_DECL
argument_list|(
name|_debug_sizeof
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|SYSCTL_DECL
argument_list|(
name|_dev
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|SYSCTL_DECL
argument_list|(
name|_hw
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|SYSCTL_DECL
argument_list|(
name|_hw_bus
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|SYSCTL_DECL
argument_list|(
name|_hw_bus_devices
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|SYSCTL_DECL
argument_list|(
name|_hw_bus_info
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|SYSCTL_DECL
argument_list|(
name|_machdep
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|SYSCTL_DECL
argument_list|(
name|_user
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|SYSCTL_DECL
argument_list|(
name|_compat
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|SYSCTL_DECL
argument_list|(
name|_regression
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|SYSCTL_DECL
argument_list|(
name|_security
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|SYSCTL_DECL
argument_list|(
name|_security_bsd
argument_list|)
expr_stmt|;
end_expr_stmt

begin_decl_stmt
specifier|extern
name|char
name|machine
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
name|osrelease
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
name|ostype
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
name|kern_ident
index|[]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Dynamic oid handling */
end_comment

begin_function_decl
name|struct
name|sysctl_oid
modifier|*
name|sysctl_add_oid
parameter_list|(
name|struct
name|sysctl_ctx_list
modifier|*
name|clist
parameter_list|,
name|struct
name|sysctl_oid_list
modifier|*
name|parent
parameter_list|,
name|int
name|nbr
parameter_list|,
specifier|const
name|char
modifier|*
name|name
parameter_list|,
name|int
name|kind
parameter_list|,
name|void
modifier|*
name|arg1
parameter_list|,
name|intptr_t
name|arg2
parameter_list|,
name|int
function_decl|(
modifier|*
name|handler
function_decl|)
parameter_list|(
name|SYSCTL_HANDLER_ARGS
parameter_list|)
parameter_list|,
specifier|const
name|char
modifier|*
name|fmt
parameter_list|,
specifier|const
name|char
modifier|*
name|descr
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|sysctl_remove_name
parameter_list|(
name|struct
name|sysctl_oid
modifier|*
name|parent
parameter_list|,
specifier|const
name|char
modifier|*
name|name
parameter_list|,
name|int
name|del
parameter_list|,
name|int
name|recurse
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|sysctl_rename_oid
parameter_list|(
name|struct
name|sysctl_oid
modifier|*
name|oidp
parameter_list|,
specifier|const
name|char
modifier|*
name|name
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|sysctl_move_oid
parameter_list|(
name|struct
name|sysctl_oid
modifier|*
name|oidp
parameter_list|,
name|struct
name|sysctl_oid_list
modifier|*
name|parent
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|sysctl_remove_oid
parameter_list|(
name|struct
name|sysctl_oid
modifier|*
name|oidp
parameter_list|,
name|int
name|del
parameter_list|,
name|int
name|recurse
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|sysctl_ctx_init
parameter_list|(
name|struct
name|sysctl_ctx_list
modifier|*
name|clist
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|sysctl_ctx_free
parameter_list|(
name|struct
name|sysctl_ctx_list
modifier|*
name|clist
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|sysctl_ctx_entry
modifier|*
name|sysctl_ctx_entry_add
parameter_list|(
name|struct
name|sysctl_ctx_list
modifier|*
name|clist
parameter_list|,
name|struct
name|sysctl_oid
modifier|*
name|oidp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|sysctl_ctx_entry
modifier|*
name|sysctl_ctx_entry_find
parameter_list|(
name|struct
name|sysctl_ctx_list
modifier|*
name|clist
parameter_list|,
name|struct
name|sysctl_oid
modifier|*
name|oidp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|sysctl_ctx_entry_del
parameter_list|(
name|struct
name|sysctl_ctx_list
modifier|*
name|clist
parameter_list|,
name|struct
name|sysctl_oid
modifier|*
name|oidp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|kernel_sysctl
parameter_list|(
name|struct
name|thread
modifier|*
name|td
parameter_list|,
name|int
modifier|*
name|name
parameter_list|,
name|u_int
name|namelen
parameter_list|,
name|void
modifier|*
name|old
parameter_list|,
name|size_t
modifier|*
name|oldlenp
parameter_list|,
name|void
modifier|*
name|new
parameter_list|,
name|size_t
name|newlen
parameter_list|,
name|size_t
modifier|*
name|retval
parameter_list|,
name|int
name|flags
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|kernel_sysctlbyname
parameter_list|(
name|struct
name|thread
modifier|*
name|td
parameter_list|,
name|char
modifier|*
name|name
parameter_list|,
name|void
modifier|*
name|old
parameter_list|,
name|size_t
modifier|*
name|oldlenp
parameter_list|,
name|void
modifier|*
name|new
parameter_list|,
name|size_t
name|newlen
parameter_list|,
name|size_t
modifier|*
name|retval
parameter_list|,
name|int
name|flags
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|userland_sysctl
parameter_list|(
name|struct
name|thread
modifier|*
name|td
parameter_list|,
name|int
modifier|*
name|name
parameter_list|,
name|u_int
name|namelen
parameter_list|,
name|void
modifier|*
name|old
parameter_list|,
name|size_t
modifier|*
name|oldlenp
parameter_list|,
name|int
name|inkernel
parameter_list|,
name|void
modifier|*
name|new
parameter_list|,
name|size_t
name|newlen
parameter_list|,
name|size_t
modifier|*
name|retval
parameter_list|,
name|int
name|flags
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|sysctl_find_oid
parameter_list|(
name|int
modifier|*
name|name
parameter_list|,
name|u_int
name|namelen
parameter_list|,
name|struct
name|sysctl_oid
modifier|*
modifier|*
name|noid
parameter_list|,
name|int
modifier|*
name|nindx
parameter_list|,
name|struct
name|sysctl_req
modifier|*
name|req
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|sysctl_lock
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|sysctl_unlock
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|sysctl_wire_old_buffer
parameter_list|(
name|struct
name|sysctl_req
modifier|*
name|req
parameter_list|,
name|size_t
name|len
parameter_list|)
function_decl|;
end_function_decl

begin_struct_decl
struct_decl|struct
name|sbuf
struct_decl|;
end_struct_decl

begin_function_decl
name|struct
name|sbuf
modifier|*
name|sbuf_new_for_sysctl
parameter_list|(
name|struct
name|sbuf
modifier|*
parameter_list|,
name|char
modifier|*
parameter_list|,
name|int
parameter_list|,
name|struct
name|sysctl_req
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* !_KERNEL */
end_comment

begin_include
include|#
directive|include
file|<sys/cdefs.h>
end_include

begin_function_decl
name|__BEGIN_DECLS
name|int
name|sysctl
parameter_list|(
specifier|const
name|int
modifier|*
parameter_list|,
name|u_int
parameter_list|,
name|void
modifier|*
parameter_list|,
name|size_t
modifier|*
parameter_list|,
specifier|const
name|void
modifier|*
parameter_list|,
name|size_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|sysctlbyname
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
name|void
modifier|*
parameter_list|,
name|size_t
modifier|*
parameter_list|,
specifier|const
name|void
modifier|*
parameter_list|,
name|size_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|sysctlnametomib
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
name|int
modifier|*
parameter_list|,
name|size_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_macro
name|__END_DECLS
end_macro

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _KERNEL */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_SYS_SYSCTL_H_ */
end_comment

end_unit

