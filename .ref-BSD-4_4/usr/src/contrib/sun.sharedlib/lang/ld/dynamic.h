begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * This source code is a product of Sun Microsystems, Inc. and is provided  * for unrestricted use provided that this legend is included on all tape  * media and as a part of the software program in whole or part.  Users  * may copy or modify this source code without charge, but are not authorized  * to license or distribute it to anyone else except as part of a product or  * program developed by the user.  *  * THIS PROGRAM CONTAINS SOURCE CODE COPYRIGHTED BY SUN MICROSYSTEMS, INC.  * SUN MICROSYSTEMS, INC., MAKES NO REPRESENTATIONS ABOUT THE SUITABLITY  * OF SUCH SOURCE CODE FOR ANY PURPOSE.  IT IS PROVIDED "AS IS" WITHOUT  * EXPRESS OR IMPLIED WARRANTY OF ANY KIND.  SUN MICROSYSTEMS, INC. DISCLAIMS  * ALL WARRANTIES WITH REGARD TO SUCH SOURCE CODE, INCLUDING ALL IMPLIED  * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.  IN  * NO EVENT SHALL SUN MICROSYSTEMS, INC. BE LIABLE FOR ANY SPECIAL, INDIRECT,  * INCIDENTAL, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING  * FROM USE OF SUCH SOURCE CODE, REGARDLESS OF THE THEORY OF LIABILITY.  *   * This source code is provided with no support and without any obligation on  * the part of Sun Microsystems, Inc. to assist in its use, correction,   * modification or enhancement.  *  * SUN MICROSYSTEMS, INC. SHALL HAVE NO LIABILITY WITH RESPECT TO THE  * INFRINGEMENT OF COPYRIGHTS, TRADE SECRETS OR ANY PATENTS BY THIS  * SOURCE CODE OR ANY PART THEREOF.  *  * Sun Microsystems, Inc.  * 2550 Garcia Avenue  * Mountain View, California 94043  */
end_comment

begin_comment
comment|/*      @(#)dynamic.h 1.12 69/12/31 SMI;   */
end_comment

begin_comment
comment|/* Copyright (c) 1991 by Sun Microsystems, Inc. */
end_comment

begin_define
define|#
directive|define
name|LHSIZ
value|31
end_define

begin_define
define|#
directive|define
name|RTHS
value|126
end_define

begin_define
define|#
directive|define
name|MAXLIB
value|126
end_define

begin_struct
struct|struct
name|libentry
block|{
name|char
modifier|*
name|addr
decl_stmt|;
comment|/* address where lib is mapped to */
name|char
modifier|*
name|name
decl_stmt|;
comment|/* path name of library */
name|struct
name|libentry
modifier|*
name|next
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|dynamic
block|{
name|struct
name|libentry
modifier|*
name|lib_entry
decl_stmt|;
comment|/* ptr to list of libraries */
name|int
name|ds
decl_stmt|;
comment|/* size of data link table */
name|int
name|js
decl_stmt|;
comment|/* size of data jump table */
name|int
name|rs
decl_stmt|;
comment|/* size of relocation */
name|int
name|hs
decl_stmt|;
comment|/* size of symbol hash table */
name|int
name|ss
decl_stmt|;
comment|/* size of symbol */
name|int
name|sts
decl_stmt|;
comment|/* size of symbol strings */
name|int
name|ts
decl_stmt|;
comment|/* size of text aera */
name|int
name|lib
decl_stmt|;
comment|/* number of libraries */
name|int
name|libstr
decl_stmt|;
comment|/* lenght of libraries strings */
name|int
name|got_off
decl_stmt|;
comment|/* offset in GOT of 0'th entry */
block|}
struct|;
end_struct

begin_comment
comment|/*  * +++++ for sun2 we need to fix the problem where  * displacement (jb_un.jb.location) is greater than 64k  */
end_comment

begin_if
if|#
directive|if
name|TARGET
operator|==
name|SUN4
end_if

begin_struct
struct|struct
name|jbind
block|{
name|int
name|jb_inst
index|[
literal|3
index|]
decl_stmt|;
comment|/* need 4 instructions for jump slot */
block|}
struct|;
end_struct

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|TARGET
operator|==
name|SUN3
operator|||
name|TARGET
operator|==
name|SUN2
end_if

begin_struct
struct|struct
name|jbind
block|{
name|unsigned
name|short
name|code
decl_stmt|;
name|unsigned
name|short
name|cl_hi
decl_stmt|;
name|unsigned
name|short
name|cl_low
decl_stmt|;
name|short
name|reloc_index
decl_stmt|;
block|}
struct|;
end_struct

begin_endif
endif|#
directive|endif
end_endif

begin_struct
struct|struct
name|fshash
block|{
name|int
name|fssymbno
decl_stmt|;
comment|/* ordinal symbol number */
name|int
name|next
decl_stmt|;
comment|/* index to the hash array pointed by fs_hash */
block|}
struct|;
end_struct

begin_undef
undef|#
directive|undef
name|relocation_info
end_undef

begin_if
if|#
directive|if
name|TARGET
operator|==
name|SUN4
end_if

begin_define
define|#
directive|define
name|relocation_info
value|reloc_info_sparc
end_define

begin_define
define|#
directive|define
name|r_symbolnum
value|r_index
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* !sun4 , thus mc68000 */
end_comment

begin_define
define|#
directive|define
name|relocation_info
value|reloc_info_68k
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* mc68000 */
end_comment

begin_comment
comment|/*   * this structure is used to build the hash and the symbol tables for  * runtime linking.  */
end_comment

begin_struct
struct|struct
name|runtime
block|{
name|int
modifier|*
name|dt
decl_stmt|;
comment|/* pointer to data linkage table */
name|struct
name|jbind
modifier|*
name|jt
decl_stmt|;
comment|/* pointer to jump linkage table */
name|struct
name|relocation_info
modifier|*
name|rp
decl_stmt|;
comment|/* ptr to first runtime reloc entry */
name|int
name|rl
decl_stmt|;
comment|/* no of reloc needed for runtime */
name|struct
name|fshash
modifier|*
name|hp
decl_stmt|;
comment|/* first entry of hash table */
name|struct
name|nlist
modifier|*
name|sp
decl_stmt|;
comment|/* first entry of runtime symb table */
name|struct
name|fshash
modifier|*
name|hp_last
decl_stmt|;
comment|/* last entry of hash table */
name|struct
name|nlist
modifier|*
name|sp_last
decl_stmt|;
comment|/* last entry of symbol table */
name|char
modifier|*
name|fsstr
decl_stmt|;
comment|/* pointer to strings aera */
name|int
name|hp_ind
decl_stmt|;
comment|/* index to the next hash entry */
name|struct
name|nlist
modifier|*
name|spp
decl_stmt|;
comment|/* ptr to next available symbol entry */
name|int
modifier|*
name|dtp
decl_stmt|;
comment|/* ptr to next available data slot */
name|struct
name|jbind
modifier|*
name|jtp
decl_stmt|;
comment|/* ptr to next available jump slot */
name|int
name|dto
decl_stmt|;
comment|/* offset in bytes into data table */
name|int
name|jto
decl_stmt|;
comment|/* offset in bytes into jump table */
name|struct
name|relocation_info
modifier|*
name|rpp
decl_stmt|;
comment|/* ptr to next available reloc entry */
name|struct
name|dynamic
modifier|*
name|dp
decl_stmt|;
comment|/* ptr to dynamic structure */
name|int
name|fsoff
decl_stmt|;
comment|/* current offset to fast symbol aera */
name|int
name|fsalloc
decl_stmt|;
comment|/* space allocated for fast symbols */
name|char
modifier|*
name|searchpath
decl_stmt|;
comment|/* search pathname */
name|int
name|spthlen
decl_stmt|;
comment|/* search pathname string len */
name|int
name|us
decl_stmt|;
comment|/* number of undefined symbols */
name|char
modifier|*
name|libname
decl_stmt|;
comment|/* pointer to the shlib name list */
name|int
name|lko_i
decl_stmt|;
comment|/* index into lko array */
name|long
name|buckets
decl_stmt|;
comment|/* number of hash buckets needed */
name|struct
name|link_object
name|lko
index|[
name|MAXLIB
index|]
decl_stmt|;
comment|/* link object array */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|dslot
block|{
name|int
name|js
decl_stmt|;
comment|/* jump table slots */
name|int
name|ds
decl_stmt|;
comment|/* data table slots */
name|int
name|ss
decl_stmt|;
comment|/* static table slots */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|rl
block|{
name|int
name|rl_d
decl_stmt|;
comment|/* total no of reloc for data segment */
name|int
name|rl_de
decl_stmt|;
comment|/* no of reloc to external symb in data segment */
name|int
name|rl_t
decl_stmt|;
comment|/* total no of non pic reloc for text segment */
name|int
name|rl_te
decl_stmt|;
comment|/* no of non pic reloc to external in text segment */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|ssymbol
block|{
name|struct
name|ssymbol
modifier|*
name|ss_next
decl_stmt|;
comment|/* next symbol */
name|char
modifier|*
name|ssp
decl_stmt|;
comment|/* pointer to symbol */
name|int
name|ssflag
decl_stmt|;
comment|/* object or process symbol */
block|}
struct|;
end_struct

begin_if
if|#
directive|if
name|TARGET
operator|==
name|SUN4
end_if

begin_define
define|#
directive|define
name|SETHI
value|0x03000000
end_define

begin_comment
comment|/* sethi %hi(val),%g1 */
end_comment

begin_define
define|#
directive|define
name|SETHIG0
value|0x01000000
end_define

begin_comment
comment|/* sethi %hi(val),%g0 */
end_comment

begin_define
define|#
directive|define
name|ORIT
value|0x82106000
end_define

begin_comment
comment|/* or %g1,val,%g1 */
end_comment

begin_define
define|#
directive|define
name|JMPI
value|0x81c06000
end_define

begin_comment
comment|/* jmpl %g1 */
end_comment

begin_define
define|#
directive|define
name|NOP
value|0x01000000
end_define

begin_comment
comment|/* nop */
end_comment

begin_define
define|#
directive|define
name|BA
value|0x10800000
end_define

begin_comment
comment|/* branch always */
end_comment

begin_define
define|#
directive|define
name|TRAP
value|0x91d02001
end_define

begin_define
define|#
directive|define
name|SAVE
value|0x9de3bfa0
end_define

begin_comment
comment|/* save minimun frame */
end_comment

begin_define
define|#
directive|define
name|CALL
value|0x40000000
end_define

begin_comment
comment|/* call instuction */
end_comment

begin_define
define|#
directive|define
name|lalign
parameter_list|(
name|i
parameter_list|)
value|(i%(sizeof (double)) ? i + ((sizeof (double))-(i%(sizeof (double)))) : i)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|TARGET
operator|==
name|SUN3
operator|||
name|TARGET
operator|==
name|SUN2
end_if

begin_define
define|#
directive|define
name|lalign
parameter_list|(
name|i
parameter_list|)
value|(i%(sizeof (long)) ? i + ((sizeof (long))-(i%(sizeof (long)))) : i)
end_define

begin_define
define|#
directive|define
name|NOP
value|0x4e71
end_define

begin_define
define|#
directive|define
name|JSR
value|0x4eb9
end_define

begin_define
define|#
directive|define
name|JUMP
value|0x4ef9
end_define

begin_define
define|#
directive|define
name|TRAP
value|0x4e4f
end_define

begin_if
if|#
directive|if
name|TARGET
operator|==
name|SUN2
end_if

begin_define
define|#
directive|define
name|JBSR
value|0x6100
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|JBSR
value|0x61ff
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|D_NAME
value|"__DYNAMIC"
end_define

begin_define
define|#
directive|define
name|LDPATH
value|"LD_LIBRARY_PATH"
end_define

begin_define
define|#
directive|define
name|v1
value|ld_un.ld_1
end_define

begin_define
define|#
directive|define
name|v2
value|ld_un.ld_2
end_define

end_unit

