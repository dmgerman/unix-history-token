begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * CDDL HEADER START  *  * The contents of this file are subject to the terms of the  * Common Development and Distribution License (the "License").  * You may not use this file except in compliance with the License.  *  * You can obtain a copy of the license at usr/src/OPENSOLARIS.LICENSE  * or http://www.opensolaris.org/os/licensing.  * See the License for the specific language governing permissions  * and limitations under the License.  *  * When distributing Covered Code, include this CDDL HEADER in each  * file and include the License file at usr/src/OPENSOLARIS.LICENSE.  * If applicable, add the following below this CDDL HEADER, with the  * fields enclosed by brackets "[]" replaced with your own identifying  * information: Portions Copyright [yyyy] [name of copyright owner]  *  * CDDL HEADER END  */
end_comment

begin_comment
comment|/*  *	Copyright (c) 1988 AT&T  *	  All Rights Reserved  *  *  * Copyright 2006 Sun Microsystems, Inc.  All rights reserved.  * Use is subject to license terms.  *  * Global include file for all sgs.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_SGS_H
end_ifndef

begin_define
define|#
directive|define
name|_SGS_H
end_define

begin_pragma
pragma|#
directive|pragma
name|ident
literal|"%Z%%M%	%I%	%E% SMI"
end_pragma

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
comment|/*<assert.h> keys off of NDEBUG */
ifdef|#
directive|ifdef
name|DEBUG
undef|#
directive|undef
name|NDEBUG
else|#
directive|else
define|#
directive|define
name|NDEBUG
endif|#
directive|endif
ifndef|#
directive|ifndef
name|_ASM
include|#
directive|include
file|<sys/types.h>
include|#
directive|include
file|<sys/machelf.h>
include|#
directive|include
file|<stdlib.h>
include|#
directive|include
file|<libelf.h>
include|#
directive|include
file|<assert.h>
include|#
directive|include
file|<alist.h>
endif|#
directive|endif
comment|/* _ASM */
comment|/*  * Software identification.  */
define|#
directive|define
name|SGS
value|""
define|#
directive|define
name|SGU_PKG
value|"Software Generation Utilities"
define|#
directive|define
name|SGU_REL
value|"(SGU) Solaris-ELF (4.0)"
ifndef|#
directive|ifndef
name|_ASM
specifier|extern
specifier|const
name|char
name|link_ver_string
index|[]
decl_stmt|;
comment|/* Linker version id  */
comment|/*   see libconv/{plat}/vernote.s */
comment|/*  * Macro to round to next double word boundary.  */
define|#
directive|define
name|S_DROUND
parameter_list|(
name|x
parameter_list|)
value|(((x) + sizeof (double) - 1)& ~(sizeof (double) - 1))
comment|/*  * General align and round macros.  */
define|#
directive|define
name|S_ALIGN
parameter_list|(
name|x
parameter_list|,
name|a
parameter_list|)
value|((x)& ~(((a) ? (a) : 1) - 1))
define|#
directive|define
name|S_ROUND
parameter_list|(
name|x
parameter_list|,
name|a
parameter_list|)
value|((x) + (((a) ? (a) : 1) - 1)& ~(((a) ? (a) : 1) - 1))
comment|/*  * Bit manipulation macros; generic bit mask and is `v' in the range  * supportable in `n' bits?  */
define|#
directive|define
name|S_MASK
parameter_list|(
name|n
parameter_list|)
value|((1<< (n)) -1)
define|#
directive|define
name|S_INRANGE
parameter_list|(
name|v
parameter_list|,
name|n
parameter_list|)
value|(((-(1<< (n)) - 1)< (v))&& ((v)< (1<< (n))))
comment|/*  * Yet another definition of the OFFSETOF macro, used with the AVL routines.  */
define|#
directive|define
name|SGSOFFSETOF
parameter_list|(
name|s
parameter_list|,
name|m
parameter_list|)
value|((size_t)(&(((s *)0)->m)))
comment|/*  * When casting between integer and pointer types, gcc will complain  * if the integer type used is not large enough to hold the pointer  * value without loss. Although a dubious practice in general, this  * is sometimes done by design. In those cases, the general solution  * is to introduce an intermediate cast to widen the integer value. The  * CAST_PTRINT macro does this, and its use documents the fact that  * the programmer is doing that sort of cast.  */
ifdef|#
directive|ifdef
name|__GNUC__
define|#
directive|define
name|CAST_PTRINT
parameter_list|(
name|cast
parameter_list|,
name|value
parameter_list|)
value|((cast)(uintptr_t)value)
else|#
directive|else
define|#
directive|define
name|CAST_PTRINT
parameter_list|(
name|cast
parameter_list|,
name|value
parameter_list|)
value|((cast)value)
endif|#
directive|endif
comment|/*  * General typedefs.  */
typedef|typedef
enum|enum
block|{
name|FALSE
init|=
literal|0
block|,
name|TRUE
init|=
literal|1
block|}
name|Boolean
typedef|;
comment|/*  * Types of errors (used by eprintf()), together with a generic error return  * value.  */
typedef|typedef
enum|enum
block|{
name|ERR_NONE
block|,
name|ERR_WARNING
block|,
name|ERR_FATAL
block|,
name|ERR_ELF
block|,
name|ERR_NUM
comment|/* Must be last */
block|}
name|Error
typedef|;
if|#
directive|if
name|defined
argument_list|(
name|_LP64
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|_ELF64
argument_list|)
define|#
directive|define
name|S_ERROR
value|(~(uint_t)0)
else|#
directive|else
define|#
directive|define
name|S_ERROR
value|(~(uintptr_t)0)
endif|#
directive|endif
comment|/*  * LIST_TRAVERSE() is used as the only "argument" of a "for" loop to  * traverse a linked list. The node pointer `node' is set to each node in  * turn and the corresponding data pointer is copied to `data'.  The macro  * is used as in  * 	for (LIST_TRAVERSE(List *list, Listnode *node, void *data)) {  *		process(data);  *	}  */
define|#
directive|define
name|LIST_TRAVERSE
parameter_list|(
name|L
parameter_list|,
name|N
parameter_list|,
name|D
parameter_list|)
define|\
value|(void) (((N) = (L)->head) != NULL&& ((D) = (N)->data) != NULL); \ 	(N) != NULL; \ 	(void) (((N) = (N)->next) != NULL&& ((D) = (N)->data) != NULL)
typedef|typedef
name|struct
name|listnode
name|Listnode
typedef|;
typedef|typedef
name|struct
name|list
name|List
typedef|;
struct|struct
name|listnode
block|{
comment|/* a node on a linked list */
name|void
modifier|*
name|data
decl_stmt|;
comment|/* the data item */
name|Listnode
modifier|*
name|next
decl_stmt|;
comment|/* the next element */
block|}
struct|;
struct|struct
name|list
block|{
comment|/* a linked list */
name|Listnode
modifier|*
name|head
decl_stmt|;
comment|/* the first element */
name|Listnode
modifier|*
name|tail
decl_stmt|;
comment|/* the last element */
block|}
struct|;
ifdef|#
directive|ifdef
name|_SYSCALL32
typedef|typedef
name|struct
name|listnode32
name|Listnode32
typedef|;
typedef|typedef
name|struct
name|list32
name|List32
typedef|;
struct|struct
name|listnode32
block|{
comment|/* a node on a linked list */
name|Elf32_Addr
name|data
decl_stmt|;
comment|/* the data item */
name|Elf32_Addr
name|next
decl_stmt|;
comment|/* the next element */
block|}
struct|;
struct|struct
name|list32
block|{
comment|/* a linked list */
name|Elf32_Addr
name|head
decl_stmt|;
comment|/* the first element */
name|Elf32_Addr
name|tail
decl_stmt|;
comment|/* the last element */
block|}
struct|;
endif|#
directive|endif
comment|/* _SYSCALL32 */
comment|/*  * Structure to maintain rejected files elf information.  Files that are not  * applicable to the present link-edit are rejected and a search for an  * appropriate file may be resumed.  The first rejected files information is  * retained so that a better error diagnostic can be given should an appropriate  * file not be located.  */
typedef|typedef
struct|struct
block|{
name|ushort_t
name|rej_type
decl_stmt|;
comment|/* SGS_REJ_ value */
name|ushort_t
name|rej_flag
decl_stmt|;
comment|/* additional information */
name|uint_t
name|rej_info
decl_stmt|;
comment|/* numeric and string information */
specifier|const
name|char
modifier|*
name|rej_str
decl_stmt|;
comment|/*	associated with error */
specifier|const
name|char
modifier|*
name|rej_name
decl_stmt|;
comment|/* object name - expanded library */
comment|/*	name and archive members */
block|}
name|Rej_desc
typedef|;
define|#
directive|define
name|SGS_REJ_NONE
value|0
define|#
directive|define
name|SGS_REJ_MACH
value|1
comment|/* wrong ELF machine type */
define|#
directive|define
name|SGS_REJ_CLASS
value|2
comment|/* wrong ELF class (32-bit/64-bit) */
define|#
directive|define
name|SGS_REJ_DATA
value|3
comment|/* wrong ELF data format (MSG/LSB) */
define|#
directive|define
name|SGS_REJ_TYPE
value|4
comment|/* bad ELF type */
define|#
directive|define
name|SGS_REJ_BADFLAG
value|5
comment|/* bad ELF flags value */
define|#
directive|define
name|SGS_REJ_MISFLAG
value|6
comment|/* mismatched ELF flags value */
define|#
directive|define
name|SGS_REJ_VERSION
value|7
comment|/* mismatched ELF/lib version */
define|#
directive|define
name|SGS_REJ_HAL
value|8
comment|/* HAL R1 extensions required */
define|#
directive|define
name|SGS_REJ_US3
value|9
comment|/* Sun UltraSPARC III extensions */
comment|/*	required */
define|#
directive|define
name|SGS_REJ_STR
value|10
comment|/* generic error - info is a string */
define|#
directive|define
name|SGS_REJ_UNKFILE
value|11
comment|/* unknown file type */
define|#
directive|define
name|SGS_REJ_HWCAP_1
value|12
comment|/* hardware capabilities mismatch */
comment|/*  * For those source files used both inside and outside of the  * libld source base (tools/common/string_table.c) we can  * automatically switch between the allocation models  * based off of the 'cc -DUSE_LIBLD_MALLOC' flag.  */
ifdef|#
directive|ifdef
name|USE_LIBLD_MALLOC
define|#
directive|define
name|calloc
parameter_list|(
name|x
parameter_list|,
name|a
parameter_list|)
value|libld_malloc(((size_t)x) * ((size_t)a))
define|#
directive|define
name|free
value|libld_free
define|#
directive|define
name|malloc
value|libld_malloc
define|#
directive|define
name|realloc
value|libld_realloc
define|#
directive|define
name|libld_calloc
parameter_list|(
name|x
parameter_list|,
name|a
parameter_list|)
value|libld_malloc(((size_t)x) * ((size_t)a))
specifier|extern
name|void
name|libld_free
parameter_list|(
name|void
modifier|*
parameter_list|)
function_decl|;
specifier|extern
name|void
modifier|*
name|libld_malloc
parameter_list|(
name|size_t
parameter_list|)
function_decl|;
specifier|extern
name|void
modifier|*
name|libld_realloc
parameter_list|(
name|void
modifier|*
parameter_list|,
name|size_t
parameter_list|)
function_decl|;
endif|#
directive|endif
comment|/*  * Data structures (defined in libld.h).  */
typedef|typedef
name|struct
name|ent_desc
name|Ent_desc
typedef|;
typedef|typedef
name|struct
name|group_desc
name|Group_desc
typedef|;
typedef|typedef
name|struct
name|ifl_desc
name|Ifl_desc
typedef|;
typedef|typedef
name|struct
name|is_desc
name|Is_desc
typedef|;
typedef|typedef
name|struct
name|isa_desc
name|Isa_desc
typedef|;
typedef|typedef
name|struct
name|isa_opt
name|Isa_opt
typedef|;
typedef|typedef
name|struct
name|mv_desc
name|Mv_desc
typedef|;
typedef|typedef
name|struct
name|ofl_desc
name|Ofl_desc
typedef|;
typedef|typedef
name|struct
name|os_desc
name|Os_desc
typedef|;
typedef|typedef
name|struct
name|rel_cache
name|Rel_cache
typedef|;
typedef|typedef
name|struct
name|sdf_desc
name|Sdf_desc
typedef|;
typedef|typedef
name|struct
name|sdv_desc
name|Sdv_desc
typedef|;
typedef|typedef
name|struct
name|sg_desc
name|Sg_desc
typedef|;
typedef|typedef
name|struct
name|sort_desc
name|Sort_desc
typedef|;
typedef|typedef
name|struct
name|sec_order
name|Sec_order
typedef|;
typedef|typedef
name|struct
name|sym_desc
name|Sym_desc
typedef|;
typedef|typedef
name|struct
name|sym_aux
name|Sym_aux
typedef|;
typedef|typedef
name|struct
name|sym_avlnode
name|Sym_avlnode
typedef|;
typedef|typedef
name|struct
name|uts_desc
name|Uts_desc
typedef|;
typedef|typedef
name|struct
name|ver_desc
name|Ver_desc
typedef|;
typedef|typedef
name|struct
name|ver_index
name|Ver_index
typedef|;
typedef|typedef
name|struct
name|audit_desc
name|Audit_desc
typedef|;
typedef|typedef
name|struct
name|audit_info
name|Audit_info
typedef|;
typedef|typedef
name|struct
name|audit_list
name|Audit_list
typedef|;
comment|/*  * Data structures defined in machrel.h.  */
typedef|typedef
name|struct
name|rel_desc
name|Rel_desc
typedef|;
comment|/*  * Data structures defined in rtld.h.  */
typedef|typedef
name|struct
name|lm_list
name|Lm_list
typedef|;
ifdef|#
directive|ifdef
name|_SYSCALL32
typedef|typedef
name|struct
name|lm_list32
name|Lm_list32
typedef|;
endif|#
directive|endif
comment|/* _SYSCALL32 */
comment|/*  * For the various utilities that include sgs.h  */
specifier|extern
name|int
name|assfail
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
specifier|extern
name|void
name|eprintf
parameter_list|(
name|Lm_list
modifier|*
parameter_list|,
name|Error
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
modifier|...
parameter_list|)
function_decl|;
specifier|extern
name|char
modifier|*
name|sgs_demangle
parameter_list|(
name|char
modifier|*
parameter_list|)
function_decl|;
specifier|extern
name|uint_t
name|sgs_str_hash
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
specifier|extern
name|uint_t
name|findprime
parameter_list|(
name|uint_t
parameter_list|)
function_decl|;
endif|#
directive|endif
comment|/* _ASM */
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
comment|/* _SGS_H */
end_comment

end_unit

