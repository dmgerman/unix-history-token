begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * This source code is a product of Sun Microsystems, Inc. and is provided  * for unrestricted use provided that this legend is included on all tape  * media and as a part of the software program in whole or part.  Users  * may copy or modify this source code without charge, but are not authorized  * to license or distribute it to anyone else except as part of a product or  * program developed by the user.  *  * THIS PROGRAM CONTAINS SOURCE CODE COPYRIGHTED BY SUN MICROSYSTEMS, INC.  * SUN MICROSYSTEMS, INC., MAKES NO REPRESENTATIONS ABOUT THE SUITABLITY  * OF SUCH SOURCE CODE FOR ANY PURPOSE.  IT IS PROVIDED "AS IS" WITHOUT  * EXPRESS OR IMPLIED WARRANTY OF ANY KIND.  SUN MICROSYSTEMS, INC. DISCLAIMS  * ALL WARRANTIES WITH REGARD TO SUCH SOURCE CODE, INCLUDING ALL IMPLIED  * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.  IN  * NO EVENT SHALL SUN MICROSYSTEMS, INC. BE LIABLE FOR ANY SPECIAL, INDIRECT,  * INCIDENTAL, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING  * FROM USE OF SUCH SOURCE CODE, REGARDLESS OF THE THEORY OF LIABILITY.  *   * This source code is provided with no support and without any obligation on  * the part of Sun Microsystems, Inc. to assist in its use, correction,   * modification or enhancement.  *  * SUN MICROSYSTEMS, INC. SHALL HAVE NO LIABILITY WITH RESPECT TO THE  * INFRINGEMENT OF COPYRIGHTS, TRADE SECRETS OR ANY PATENTS BY THIS  * SOURCE CODE OR ANY PART THEREOF.  *  * Sun Microsystems, Inc.  * 2550 Garcia Avenue  * Mountain View, California 94043  */
end_comment

begin_comment
comment|/*	@(#)link.h 1.6 88/08/19 SMI	*/
end_comment

begin_comment
comment|/*  * Copyright (c) 1987, 1991 by Sun Microsystems, Inc.  */
end_comment

begin_comment
comment|/*  * Link editor public definitions.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_link_h
end_ifndef

begin_define
define|#
directive|define
name|_link_h
end_define

begin_comment
comment|/*  * Structure describing logical name and requirements on an object  * which is to be loaded dynamically.  */
end_comment

begin_struct
struct|struct
name|old_link_object
block|{
name|char
modifier|*
name|lo_name
decl_stmt|;
comment|/* name of object */
name|int
name|lo_library
range|:
literal|1
decl_stmt|,
comment|/* searched for by library rules */
name|lo_unused
range|:
literal|31
decl_stmt|;
name|short
name|lo_major
decl_stmt|;
comment|/* major version number */
name|short
name|lo_minor
decl_stmt|;
comment|/* minor version number */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|link_object
block|{
name|long
name|lo_name
decl_stmt|;
comment|/* name (often relative) */
name|int
name|lo_library
range|:
literal|1
decl_stmt|,
comment|/* searched for by library rules */
name|lo_unused
range|:
literal|31
decl_stmt|;
name|short
name|lo_major
decl_stmt|;
comment|/* major version number */
name|short
name|lo_minor
decl_stmt|;
comment|/* minor version number */
name|long
name|lo_next
decl_stmt|;
comment|/* next one (often relative) */
block|}
struct|;
end_struct

begin_comment
comment|/*  * Structure describing name and placement of dynamically loaded  * objects in a process' address space.  */
end_comment

begin_struct
struct|struct
name|link_map
block|{
name|caddr_t
name|lm_addr
decl_stmt|;
comment|/* address at which object mapped */
name|char
modifier|*
name|lm_name
decl_stmt|;
comment|/* full name of loaded object */
name|struct
name|link_map
modifier|*
name|lm_next
decl_stmt|;
comment|/* next object in map */
name|struct
name|link_object
modifier|*
name|lm_lop
decl_stmt|;
comment|/* link object that got us here */
name|caddr_t
name|lm_lob
decl_stmt|;
comment|/* base address for said link object */
name|int
name|lm_rwt
range|:
literal|1
decl_stmt|;
comment|/* text is read/write */
name|struct
name|link_dynamic
modifier|*
name|lm_ld
decl_stmt|;
comment|/* dynamic structure */
name|caddr_t
name|lm_lpd
decl_stmt|;
comment|/* loader private data */
block|}
struct|;
end_struct

begin_comment
comment|/*  * Version 1 of dynamic linking information.  With the exception of  * ld_loaded (determined at execution time) and ld_stab_hash (a special  * case of relocation handled at execution time), the values in this  * structure reflect offsets from the containing link_dynamic structure.  */
end_comment

begin_struct
struct|struct
name|link_dynamic_1
block|{
name|struct
name|link_map
modifier|*
name|ld_loaded
decl_stmt|;
comment|/* list of loaded objects */
name|long
name|ld_need
decl_stmt|;
comment|/* list of needed objects */
name|long
name|ld_rules
decl_stmt|;
comment|/* search rules for library objects */
name|long
name|ld_got
decl_stmt|;
comment|/* global offset table */
name|long
name|ld_plt
decl_stmt|;
comment|/* procedure linkage table */
name|long
name|ld_rel
decl_stmt|;
comment|/* relocation table */
name|long
name|ld_hash
decl_stmt|;
comment|/* symbol hash table */
name|long
name|ld_stab
decl_stmt|;
comment|/* symbol table itself */
name|long
function_decl|(
modifier|*
name|ld_stab_hash
function_decl|)
parameter_list|()
function_decl|;
comment|/* "pointer" to symbol hash function */
name|long
name|ld_buckets
decl_stmt|;
comment|/* number of hash buckets */
name|long
name|ld_symbols
decl_stmt|;
comment|/* symbol strings */
name|long
name|ld_symb_size
decl_stmt|;
comment|/* size of symbol strings */
name|long
name|ld_text
decl_stmt|;
comment|/* size of text area */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|link_dynamic_2
block|{
name|struct
name|link_map
modifier|*
name|ld_loaded
decl_stmt|;
comment|/* list of loaded objects */
name|long
name|ld_need
decl_stmt|;
comment|/* list of needed objects */
name|long
name|ld_rules
decl_stmt|;
comment|/* search rules for library objects */
name|long
name|ld_got
decl_stmt|;
comment|/* global offset table */
name|long
name|ld_plt
decl_stmt|;
comment|/* procedure linkage table */
name|long
name|ld_rel
decl_stmt|;
comment|/* relocation table */
name|long
name|ld_hash
decl_stmt|;
comment|/* symbol hash table */
name|long
name|ld_stab
decl_stmt|;
comment|/* symbol table itself */
name|long
function_decl|(
modifier|*
name|ld_stab_hash
function_decl|)
parameter_list|()
function_decl|;
comment|/* "pointer" to symbol hash function */
name|long
name|ld_buckets
decl_stmt|;
comment|/* number of hash buckets */
name|long
name|ld_symbols
decl_stmt|;
comment|/* symbol strings */
name|long
name|ld_symb_size
decl_stmt|;
comment|/* size of symbol strings */
name|long
name|ld_text
decl_stmt|;
comment|/* size of text area */
name|long
name|ld_plt_sz
decl_stmt|;
comment|/* size of procedure linkage table */
block|}
struct|;
end_struct

begin_comment
comment|/*  * Structure pointing to run time allocated common symbols and  * its string.  */
end_comment

begin_struct
struct|struct
name|rtc_symb
block|{
name|struct
name|nlist
modifier|*
name|rtc_sp
decl_stmt|;
comment|/* symbol for common */
name|struct
name|rtc_symb
modifier|*
name|rtc_next
decl_stmt|;
comment|/* next common */
block|}
struct|;
end_struct

begin_comment
comment|/*  * Debugger interface structure.  */
end_comment

begin_struct
struct|struct
name|ld_debug
block|{
name|int
name|ldd_version
decl_stmt|;
comment|/* version # of interface */
name|int
name|ldd_in_debugger
decl_stmt|;
comment|/* a debugger is running us */
name|int
name|ldd_sym_loaded
decl_stmt|;
comment|/* we loaded some symbols */
name|char
modifier|*
name|ldd_bp_addr
decl_stmt|;
comment|/* place for ld-generated bpt */
name|int
name|ldd_bp_inst
decl_stmt|;
comment|/* instruction which was there */
name|struct
name|rtc_symb
modifier|*
name|ldd_cp
decl_stmt|;
comment|/* commons we built */
block|}
struct|;
end_struct

begin_comment
comment|/*  * Structure associated with each object which may be or which requires  * execution-time link editing.  Used by the run-time linkage editor to  * identify needed objects and symbol definitions and references.  */
end_comment

begin_struct
struct|struct
name|old_link_dynamic
block|{
name|int
name|ld_version
decl_stmt|;
comment|/* version # of this structure */
union|union
block|{
name|struct
name|link_dynamic_1
name|ld_1
decl_stmt|;
block|}
name|ld_un
union|;
name|int
name|in_debugging
decl_stmt|;
name|int
name|sym_loaded
decl_stmt|;
name|char
modifier|*
name|bp_addr
decl_stmt|;
name|int
name|bp_inst
decl_stmt|;
name|struct
name|rtc_symb
modifier|*
name|cp
decl_stmt|;
comment|/* pointer to an array of runtime */
comment|/* allocated common symbols. */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|link_dynamic
block|{
name|int
name|ld_version
decl_stmt|;
comment|/* version # of this structure */
name|struct
name|ld_debug
modifier|*
name|ldd
decl_stmt|;
union|union
block|{
name|struct
name|link_dynamic_1
modifier|*
name|ld_1
decl_stmt|;
name|struct
name|link_dynamic_2
modifier|*
name|ld_2
decl_stmt|;
block|}
name|ld_un
union|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|v2
value|ld_un.ld_2
end_define

begin_define
define|#
directive|define
name|v1
value|ld_un.ld_1
end_define

begin_comment
comment|/*  * get size of relocations  */
end_comment

begin_define
define|#
directive|define
name|GETGOTSZ
parameter_list|(
name|x
parameter_list|)
value|(x->ld_version< 2 ? ((struct old_link_dynamic *) x)->v1.ld_plt - ((struct old_link_dynamic *) x)->v1.ld_got : (x)->v2->ld_plt - (x)->v2->ld_got)
end_define

begin_define
define|#
directive|define
name|GETPLTSZ
parameter_list|(
name|x
parameter_list|)
value|(x->ld_version< 2 ? ((struct old_link_dynamic *) x)->v1.ld_rel - ((struct old_link_dynamic *) x)->v1.ld_plt : (x)->v2->ld_rel - (x)->v2->ld_plt)
end_define

begin_define
define|#
directive|define
name|GETRELSZ
parameter_list|(
name|x
parameter_list|)
value|(x->ld_version< 2 ? ((struct old_link_dynamic *) x)->v1.ld_hash - ((struct old_link_dynamic *) x)->v1.ld_rel : (x)->v2->ld_hash - (x)->v2->ld_rel)
end_define

begin_define
define|#
directive|define
name|GETHASHSZ
parameter_list|(
name|x
parameter_list|)
value|(x->ld_version< 2 ? ((struct old_link_dynamic *) x)->v1.ld_stab - ((struct old_link_dynamic *) x)->v1.ld_hash : (x)->v2->ld_stab - (x)->v2->ld_hash)
end_define

begin_define
define|#
directive|define
name|GETSTABSZ
parameter_list|(
name|x
parameter_list|)
value|(x->ld_version< 2 ? ((struct old_link_dynamic *) x)->v1.ld_symbols - ((struct old_link_dynamic *) x)->v1.ld_stab : (x)->v2->ld_symbols - (x)->v2->ld_stab)
end_define

begin_undef
undef|#
directive|undef
name|v2
end_undef

begin_undef
undef|#
directive|undef
name|v1
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*!_link_h*/
end_comment

end_unit

