begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * This source code is a product of Sun Microsystems, Inc. and is provided  * for unrestricted use provided that this legend is included on all tape  * media and as a part of the software program in whole or part.  Users  * may copy or modify this source code without charge, but are not authorized  * to license or distribute it to anyone else except as part of a product or  * program developed by the user.  *  * THIS PROGRAM CONTAINS SOURCE CODE COPYRIGHTED BY SUN MICROSYSTEMS, INC.  * SUN MICROSYSTEMS, INC., MAKES NO REPRESENTATIONS ABOUT THE SUITABLITY  * OF SUCH SOURCE CODE FOR ANY PURPOSE.  IT IS PROVIDED "AS IS" WITHOUT  * EXPRESS OR IMPLIED WARRANTY OF ANY KIND.  SUN MICROSYSTEMS, INC. DISCLAIMS  * ALL WARRANTIES WITH REGARD TO SUCH SOURCE CODE, INCLUDING ALL IMPLIED  * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.  IN  * NO EVENT SHALL SUN MICROSYSTEMS, INC. BE LIABLE FOR ANY SPECIAL, INDIRECT,  * INCIDENTAL, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING  * FROM USE OF SUCH SOURCE CODE, REGARDLESS OF THE THEORY OF LIABILITY.  *   * This source code is provided with no support and without any obligation on  * the part of Sun Microsystems, Inc. to assist in its use, correction,   * modification or enhancement.  *  * SUN MICROSYSTEMS, INC. SHALL HAVE NO LIABILITY WITH RESPECT TO THE  * INFRINGEMENT OF COPYRIGHTS, TRADE SECRETS OR ANY PATENTS BY THIS  * SOURCE CODE OR ANY PART THEREOF.  *  * Sun Microsystems, Inc.  * 2550 Garcia Avenue  * Mountain View, California 94043  */
end_comment

begin_comment
comment|/* @(#)rtld.h 1.11 91/03/16 SMI */
end_comment

begin_comment
comment|/*  * Copyright (c) 1991 by Sun Microsystems, Inc.  */
end_comment

begin_comment
comment|/*  * Global definitions for run-time link editor.  */
end_comment

begin_comment
comment|/*  * General macros.  */
end_comment

begin_define
define|#
directive|define
name|PROUND
parameter_list|(
name|x
parameter_list|)
value|(((x) + PAGESIZE - 1)& ~(PAGESIZE - 1))
end_define

begin_comment
comment|/* round to page size */
end_comment

begin_define
define|#
directive|define
name|MAIN_BASE
value|PAGSIZ
end_define

begin_comment
comment|/* place where "main" is mapped */
end_comment

begin_define
define|#
directive|define
name|SROUND
parameter_list|(
name|x
parameter_list|)
value|((x + SEGSIZ - 1)&~ (SEGSIZ - 1))
end_define

begin_comment
comment|/* round to segment size */
end_comment

begin_define
define|#
directive|define
name|SIZE
parameter_list|(
name|x
parameter_list|)
value|(SROUND((x).a_text) + (x).a_data + (x).a_bss)
end_define

begin_comment
comment|/* address space "claim" */
end_comment

begin_define
define|#
directive|define
name|max
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|((a)< (b) ? (b) : (a))
end_define

begin_comment
comment|/*  * Code collapsing macros.  */
end_comment

begin_define
define|#
directive|define
name|LM2LP
parameter_list|(
name|lmp
parameter_list|)
value|((struct ld_private *)lmp->lm_lpd)
end_define

begin_comment
comment|/*  * Define our own versions of ctype macros to avoid hauling in the  * ctype_ array.  */
end_comment

begin_define
define|#
directive|define
name|isdigit
parameter_list|(
name|c
parameter_list|)
value|(((c)>= '0')&& ((c)<= '9'))
end_define

begin_define
define|#
directive|define
name|isspace
parameter_list|(
name|c
parameter_list|)
value|(((c) == ' ') || (((c)>= '\t')&& ((c)<= '\015')))
end_define

begin_comment
comment|/*  * State descriptor for object accessed via "dlopen".  */
end_comment

begin_define
define|#
directive|define
name|DL_MAGIC
value|0x580331
end_define

begin_comment
comment|/* unlikely quantity */
end_comment

begin_define
define|#
directive|define
name|DL_CIGAM
value|0x830504
end_define

begin_comment
comment|/* matching unlikely quantity */
end_comment

begin_struct
struct|struct
name|dl_object
block|{
name|long
name|dl_magic
decl_stmt|;
comment|/* DL_MAGIC */
name|struct
name|dl_object
modifier|*
name|dl_next
decl_stmt|;
comment|/* next dlopen object */
name|struct
name|dl_object
modifier|*
name|dl_dep
decl_stmt|;
comment|/* next dependent object */
name|struct
name|link_map
modifier|*
name|dl_lmp
decl_stmt|;
comment|/* point back to the link map */
name|long
name|dl_refcnt
decl_stmt|;
comment|/* reference count */
name|long
name|dl_cigam
decl_stmt|;
comment|/* DL_CIGAM */
block|}
struct|;
end_struct

begin_comment
comment|/*  * Loader link_map private data.  Generally a cache for relocated items  * fetched from the object's link_dynamic structure.  *  * N.B. lp_lobase is a hack to overcome a problem in version #2 __DYNAMIC  * programs.  For main programs, ld-generated data structures in the text  * segment are relocated against "0" rather than the actual text base  * address.    */
end_comment

begin_struct
struct|struct
name|ld_private
block|{
name|struct
name|jbind
modifier|*
name|lp_plt
decl_stmt|;
comment|/* procedure linkage table */
name|struct
name|relocation_info
modifier|*
name|lp_rp
decl_stmt|;
comment|/* relocation table */
name|struct
name|fshash
modifier|*
name|lp_hash
decl_stmt|;
comment|/* hash table */
name|struct
name|nlist
modifier|*
name|lp_symtab
decl_stmt|;
comment|/* symbol table */
name|char
modifier|*
name|lp_symstr
decl_stmt|;
comment|/* symbol strings */
name|caddr_t
name|lp_textbase
decl_stmt|;
comment|/* base address for text addressing */
name|struct
name|nlist
modifier|*
function_decl|(
modifier|*
name|lp_interp
function_decl|)
parameter_list|()
function_decl|;
comment|/* link map interpreter */
name|long
name|lp_refcnt
decl_stmt|;
comment|/* reference count of link map */
name|struct
name|dl_object
modifier|*
name|lp_dlp
decl_stmt|;
comment|/* pointer to a dlopen object */
name|struct
name|dl_object
modifier|*
name|lp_dlh
decl_stmt|;
comment|/* pointer to head of a dl chain */
name|caddr_t
name|lp_symbol_base
decl_stmt|;
comment|/* base address for symbols */
block|}
struct|;
end_struct

begin_comment
comment|/*  * macro off which to base text addressing -- use this to access  * link_object lists and addresses and other things which are sensitive  * to the "main program" bug.  */
end_comment

begin_define
define|#
directive|define
name|TEXTBASE
parameter_list|(
name|lmp
parameter_list|)
value|(LM2LP(lmp)->lp_textbase)
end_define

begin_comment
comment|/*  * General global declarations  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|stdout
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* file descriptor for results */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|stderr
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* file descriptor for errors */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|errno
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* system call error value */
end_comment

begin_decl_stmt
specifier|extern
name|char
modifier|*
modifier|*
name|environ
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* environment strings */
end_comment

begin_function_decl
specifier|extern
name|void
name|getreuid
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* system call jacket for r/euid */
end_comment

begin_function_decl
specifier|extern
name|void
name|getregid
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* ditto for r/egid */
end_comment

begin_function_decl
specifier|extern
name|char
modifier|*
name|rtmalloc
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* heap allocation */
end_comment

begin_function_decl
specifier|extern
name|char
modifier|*
name|getenv
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* access to environment variables */
end_comment

begin_function_decl
specifier|extern
name|caddr_t
name|mmap
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* memory mapping system call */
end_comment

begin_function_decl
specifier|extern
name|int
name|secure_objects
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* indicates setu/gid or not */
end_comment

begin_function_decl
specifier|extern
name|void
name|panic
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* fatal error handling */
end_comment

begin_comment
comment|/*  * Error code (strings).  */
end_comment

begin_decl_stmt
specifier|extern
name|char
name|DLE_none
index|[]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* no error */
end_comment

begin_decl_stmt
specifier|extern
name|char
name|DLE_mode_error
index|[]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* dlopen mode */
end_comment

begin_decl_stmt
specifier|extern
name|char
name|DLE_bad_handle
index|[]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* invalid dl object handle */
end_comment

begin_decl_stmt
specifier|extern
name|char
name|DLE_can_not_open
index|[]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* unable to map */
end_comment

begin_decl_stmt
specifier|extern
name|char
name|DLE_undefined
index|[]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* undefined symbol reference */
end_comment

begin_decl_stmt
specifier|extern
name|char
name|DLE_conflict
index|[]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* conflicting use of dependent .so */
end_comment

end_unit

