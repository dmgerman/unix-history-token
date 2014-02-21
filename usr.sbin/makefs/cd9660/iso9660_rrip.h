begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$NetBSD: iso9660_rrip.h,v 1.5 2009/01/10 22:06:29 bjh21 Exp $	*/
end_comment

begin_comment
comment|/*  * Copyright (c) 2005 Daniel Watt, Walter Deignan, Ryan Gabrys, Alan  * Perez-Rathke and Ram Vedam.  All rights reserved.  *  * This code was written by Daniel Watt, Walter Deignan, Ryan Gabrys,  * Alan Perez-Rathke and Ram Vedam.  *  * Redistribution and use in source and binary forms, with or  * without modification, are permitted provided that the following  * conditions are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above  *    copyright notice, this list of conditions and the following  *    disclaimer in the documentation and/or other materials provided  *    with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY DANIEL WATT, WALTER DEIGNAN, RYAN  * GABRYS, ALAN PEREZ-RATHKE AND RAM VEDAM ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE  * DISCLAIMED.  IN NO EVENT SHALL DANIEL WATT, WALTER DEIGNAN, RYAN  * GABRYS, ALAN PEREZ-RATHKE AND RAM VEDAM BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF  * USE,DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND  * ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,  * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY  * OF SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__ISO9660_RRIP_H__
end_ifndef

begin_define
define|#
directive|define
name|__ISO9660_RRIP_H__
end_define

begin_comment
comment|/*  * This will hold all the functions needed to  * write an ISO 9660 image with Rock Ridge Extensions  */
end_comment

begin_comment
comment|/* For writing must use ISO_RRIP_EXTREF structure */
end_comment

begin_include
include|#
directive|include
file|"makefs.h"
end_include

begin_include
include|#
directive|include
file|<cd9660_rrip.h>
end_include

begin_include
include|#
directive|include
file|"cd9660.h"
end_include

begin_include
include|#
directive|include
file|<sys/queue.h>
end_include

begin_define
define|#
directive|define
name|PX_LENGTH
value|0x2C
end_define

begin_define
define|#
directive|define
name|PN_LENGTH
value|0x14
end_define

begin_define
define|#
directive|define
name|TF_CREATION
value|0x00
end_define

begin_define
define|#
directive|define
name|TF_MODIFY
value|0x01
end_define

begin_define
define|#
directive|define
name|TF_ACCESS
value|0x02
end_define

begin_define
define|#
directive|define
name|TF_ATTRIBUTES
value|0x04
end_define

begin_define
define|#
directive|define
name|TF_BACKUP
value|0x08
end_define

begin_define
define|#
directive|define
name|TF_EXPIRATION
value|0x10
end_define

begin_define
define|#
directive|define
name|TF_EFFECTIVE
value|0x20
end_define

begin_define
define|#
directive|define
name|TF_LONGFORM
value|0x40
end_define

begin_define
define|#
directive|define
name|NM_CONTINUE
value|0x80
end_define

begin_define
define|#
directive|define
name|NM_CURRENT
value|0x100
end_define

begin_define
define|#
directive|define
name|NM_PARENT
value|0x200
end_define

begin_define
define|#
directive|define
name|SUSP_LOC_ENTRY
value|0x01
end_define

begin_define
define|#
directive|define
name|SUSP_LOC_DOT
value|0x02
end_define

begin_define
define|#
directive|define
name|SUSP_LOC_DOTDOT
value|0x04
end_define

begin_define
define|#
directive|define
name|SUSP_TYPE_SUSP
value|1
end_define

begin_define
define|#
directive|define
name|SUSP_TYPE_RRIP
value|2
end_define

begin_define
define|#
directive|define
name|SUSP_ENTRY_SUSP_CE
value|1
end_define

begin_define
define|#
directive|define
name|SUSP_ENTRY_SUSP_PD
value|2
end_define

begin_define
define|#
directive|define
name|SUSP_ENTRY_SUSP_SP
value|3
end_define

begin_define
define|#
directive|define
name|SUSP_ENTRY_SUSP_ST
value|4
end_define

begin_define
define|#
directive|define
name|SUSP_ENTRY_SUSP_ER
value|5
end_define

begin_define
define|#
directive|define
name|SUSP_ENTRY_SUSP_ES
value|6
end_define

begin_define
define|#
directive|define
name|SUSP_ENTRY_RRIP_PX
value|1
end_define

begin_define
define|#
directive|define
name|SUSP_ENTRY_RRIP_PN
value|2
end_define

begin_define
define|#
directive|define
name|SUSP_ENTRY_RRIP_SL
value|3
end_define

begin_define
define|#
directive|define
name|SUSP_ENTRY_RRIP_NM
value|4
end_define

begin_define
define|#
directive|define
name|SUSP_ENTRY_RRIP_CL
value|5
end_define

begin_define
define|#
directive|define
name|SUSP_ENTRY_RRIP_PL
value|6
end_define

begin_define
define|#
directive|define
name|SUSP_ENTRY_RRIP_RE
value|7
end_define

begin_define
define|#
directive|define
name|SUSP_ENTRY_RRIP_TF
value|8
end_define

begin_define
define|#
directive|define
name|SUSP_ENTRY_RRIP_SF
value|9
end_define

begin_define
define|#
directive|define
name|SUSP_RRIP_ER_EXT_ID
value|"IEEE_P1282"
end_define

begin_define
define|#
directive|define
name|SUSP_RRIP_ER_EXT_DES
value|"THE IEEE P1282 PROTOCOL PROVIDES SUPPORT FOR POSIX FILE SYSTEM SEMANTICS."
end_define

begin_define
define|#
directive|define
name|SUSP_RRIP_ER_EXT_SRC
value|"PLEASE CONTACT THE IEEE STANDARDS DEPARTMENT, PISCATAWAY, NJ, USA FOR THE P1282 SPECIFICATION."
end_define

begin_define
define|#
directive|define
name|SL_FLAGS_NONE
value|0
end_define

begin_define
define|#
directive|define
name|SL_FLAGS_CONTINUE
value|1
end_define

begin_define
define|#
directive|define
name|SL_FLAGS_CURRENT
value|2
end_define

begin_define
define|#
directive|define
name|SL_FLAGS_PARENT
value|4
end_define

begin_define
define|#
directive|define
name|SL_FLAGS_ROOT
value|8
end_define

begin_typedef
typedef|typedef
struct|struct
block|{
name|ISO_SUSP_HEADER
name|h
decl_stmt|;
name|u_char
name|mode
index|[
name|ISODCL
argument_list|(
literal|5
argument_list|,
literal|12
argument_list|)
index|]
decl_stmt|;
name|u_char
name|links
index|[
name|ISODCL
argument_list|(
literal|13
argument_list|,
literal|20
argument_list|)
index|]
decl_stmt|;
name|u_char
name|uid
index|[
name|ISODCL
argument_list|(
literal|21
argument_list|,
literal|28
argument_list|)
index|]
decl_stmt|;
name|u_char
name|gid
index|[
name|ISODCL
argument_list|(
literal|29
argument_list|,
literal|36
argument_list|)
index|]
decl_stmt|;
name|u_char
name|serial
index|[
name|ISODCL
argument_list|(
literal|37
argument_list|,
literal|44
argument_list|)
index|]
decl_stmt|;
block|}
name|ISO_RRIP_PX
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|ISO_SUSP_HEADER
name|h
decl_stmt|;
name|u_char
name|high
index|[
name|ISODCL
argument_list|(
literal|5
argument_list|,
literal|12
argument_list|)
index|]
decl_stmt|;
name|u_char
name|low
index|[
name|ISODCL
argument_list|(
literal|13
argument_list|,
literal|20
argument_list|)
index|]
decl_stmt|;
block|}
name|ISO_RRIP_PN
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|ISO_SUSP_HEADER
name|h
decl_stmt|;
name|u_char
name|flags
index|[
name|ISODCL
argument_list|(
literal|4
argument_list|,
literal|4
argument_list|)
index|]
decl_stmt|;
name|u_char
name|component
index|[
name|ISODCL
argument_list|(
literal|4
argument_list|,
literal|256
argument_list|)
index|]
decl_stmt|;
name|u_int
name|nBytes
decl_stmt|;
block|}
name|ISO_RRIP_SL
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|ISO_SUSP_HEADER
name|h
decl_stmt|;
name|u_char
name|flags
index|[
name|ISODCL
argument_list|(
literal|4
argument_list|,
literal|4
argument_list|)
index|]
decl_stmt|;
name|u_char
name|timestamp
index|[
name|ISODCL
argument_list|(
literal|5
argument_list|,
literal|256
argument_list|)
index|]
decl_stmt|;
block|}
name|ISO_RRIP_TF
typedef|;
end_typedef

begin_define
define|#
directive|define
name|RRIP_NM_FLAGS_NONE
value|0x00
end_define

begin_define
define|#
directive|define
name|RRIP_NM_FLAGS_CONTINUE
value|0x01
end_define

begin_define
define|#
directive|define
name|RRIP_NM_FLAGS_CURRENT
value|0x02
end_define

begin_define
define|#
directive|define
name|RRIP_NM_FLAGS_PARENT
value|0x04
end_define

begin_typedef
typedef|typedef
struct|struct
block|{
name|ISO_SUSP_HEADER
name|h
decl_stmt|;
name|u_char
name|flags
index|[
name|ISODCL
argument_list|(
literal|4
argument_list|,
literal|4
argument_list|)
index|]
decl_stmt|;
name|u_char
name|altname
index|[
name|ISODCL
argument_list|(
literal|4
argument_list|,
literal|256
argument_list|)
index|]
decl_stmt|;
block|}
name|ISO_RRIP_NM
typedef|;
end_typedef

begin_comment
comment|/* Note that this is the same structure as cd9660_rrip.h : ISO_RRIP_CONT */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|ISO_SUSP_HEADER
name|h
decl_stmt|;
name|u_char
name|ca_sector
index|[
name|ISODCL
argument_list|(
literal|5
argument_list|,
literal|12
argument_list|)
index|]
decl_stmt|;
name|u_char
name|offset
index|[
name|ISODCL
argument_list|(
literal|13
argument_list|,
literal|20
argument_list|)
index|]
decl_stmt|;
name|u_char
name|length
index|[
name|ISODCL
argument_list|(
literal|21
argument_list|,
literal|28
argument_list|)
index|]
decl_stmt|;
block|}
name|ISO_SUSP_CE
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|ISO_SUSP_HEADER
name|h
decl_stmt|;
name|u_char
name|padding_area
index|[
name|ISODCL
argument_list|(
literal|4
argument_list|,
literal|256
argument_list|)
index|]
decl_stmt|;
block|}
name|ISO_SUSP_PD
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|ISO_SUSP_HEADER
name|h
decl_stmt|;
name|u_char
name|check
index|[
name|ISODCL
argument_list|(
literal|4
argument_list|,
literal|5
argument_list|)
index|]
decl_stmt|;
name|u_char
name|len_skp
index|[
name|ISODCL
argument_list|(
literal|6
argument_list|,
literal|6
argument_list|)
index|]
decl_stmt|;
block|}
name|ISO_SUSP_SP
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|ISO_SUSP_HEADER
name|h
decl_stmt|;
block|}
name|ISO_SUSP_ST
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|ISO_SUSP_HEADER
name|h
decl_stmt|;
name|u_char
name|len_id
index|[
name|ISODCL
argument_list|(
literal|4
argument_list|,
literal|4
argument_list|)
index|]
decl_stmt|;
name|u_char
name|len_des
index|[
name|ISODCL
argument_list|(
literal|5
argument_list|,
literal|5
argument_list|)
index|]
decl_stmt|;
name|u_char
name|len_src
index|[
name|ISODCL
argument_list|(
literal|6
argument_list|,
literal|6
argument_list|)
index|]
decl_stmt|;
name|u_char
name|ext_ver
index|[
name|ISODCL
argument_list|(
literal|7
argument_list|,
literal|7
argument_list|)
index|]
decl_stmt|;
name|u_char
name|ext_data
index|[
name|ISODCL
argument_list|(
literal|8
argument_list|,
literal|256
argument_list|)
index|]
decl_stmt|;
comment|/*	u_char ext_id		 [ISODCL ( 8, 256)]; 	u_char ext_des		 [ISODCL ( 257, 513)]; 	u_char ext_src		 [ISODCL ( 514, 770)];*/
block|}
name|ISO_SUSP_ER
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|ISO_SUSP_HEADER
name|h
decl_stmt|;
name|u_char
name|ext_seq
index|[
name|ISODCL
argument_list|(
literal|4
argument_list|,
literal|4
argument_list|)
index|]
decl_stmt|;
block|}
name|ISO_SUSP_ES
typedef|;
end_typedef

begin_typedef
typedef|typedef
union|union
block|{
name|ISO_RRIP_PX
name|PX
decl_stmt|;
name|ISO_RRIP_PN
name|PN
decl_stmt|;
name|ISO_RRIP_SL
name|SL
decl_stmt|;
name|ISO_RRIP_NM
name|NM
decl_stmt|;
name|ISO_RRIP_CLINK
name|CL
decl_stmt|;
name|ISO_RRIP_PLINK
name|PL
decl_stmt|;
name|ISO_RRIP_RELDIR
name|RE
decl_stmt|;
name|ISO_RRIP_TF
name|TF
decl_stmt|;
block|}
name|rrip_entry
typedef|;
end_typedef

begin_typedef
typedef|typedef
union|union
block|{
name|ISO_SUSP_CE
name|CE
decl_stmt|;
name|ISO_SUSP_PD
name|PD
decl_stmt|;
name|ISO_SUSP_SP
name|SP
decl_stmt|;
name|ISO_SUSP_ST
name|ST
decl_stmt|;
name|ISO_SUSP_ER
name|ER
decl_stmt|;
name|ISO_SUSP_ES
name|ES
decl_stmt|;
block|}
name|susp_entry
typedef|;
end_typedef

begin_typedef
typedef|typedef
union|union
block|{
name|susp_entry
name|su_entry
decl_stmt|;
name|rrip_entry
name|rr_entry
decl_stmt|;
block|}
name|SUSP_ENTRIES
typedef|;
end_typedef

begin_struct
struct|struct
name|ISO_SUSP_ATTRIBUTES
block|{
name|SUSP_ENTRIES
name|attr
decl_stmt|;
name|int
name|type
decl_stmt|;
name|char
name|type_of
index|[
literal|2
index|]
decl_stmt|;
name|char
name|last_in_suf
decl_stmt|;
comment|/* last entry in the System Use Field? */
comment|/* Dan's addons - will merge later. This allows use of a switch */
name|char
name|susp_type
decl_stmt|;
comment|/* SUSP or RRIP */
name|char
name|entry_type
decl_stmt|;
comment|/* Record type */
name|char
name|write_location
decl_stmt|;
name|TAILQ_ENTRY
argument_list|(
argument|ISO_SUSP_ATTRIBUTES
argument_list|)
name|rr_ll
expr_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|CD9660_SUSP_ENTRY_SIZE
parameter_list|(
name|entry
parameter_list|)
define|\
value|((int) ((entry)->attr.su_entry.SP.h.length[0]))
end_define

begin_comment
comment|/* Recursive function - move later to func pointer code*/
end_comment

begin_function_decl
name|int
name|cd9660_susp_finalize
parameter_list|(
name|cd9660node
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* These two operate on single nodes */
end_comment

begin_function_decl
name|int
name|cd9660_susp_finalize_node
parameter_list|(
name|cd9660node
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|cd9660_rrip_finalize_node
parameter_list|(
name|cd9660node
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* POSIX File attribute */
end_comment

begin_function_decl
name|int
name|cd9660node_rrip_px
parameter_list|(
name|struct
name|ISO_SUSP_ATTRIBUTES
modifier|*
parameter_list|,
name|fsnode
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Device number */
end_comment

begin_function_decl
name|int
name|cd9660node_rrip_pn
parameter_list|(
name|struct
name|ISO_SUSP_ATTRIBUTES
modifier|*
parameter_list|,
name|fsnode
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Symbolic link */
end_comment

begin_function_decl
name|int
name|cd9660node_rrip_SL
parameter_list|(
name|struct
name|ISO_SUSP_ATTRIBUTES
modifier|*
parameter_list|,
name|fsnode
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Alternate Name function */
end_comment

begin_function_decl
name|void
name|cd9660_rrip_NM
parameter_list|(
name|cd9660node
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|cd9660_rrip_add_NM
parameter_list|(
name|cd9660node
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Parent and child link function */
end_comment

begin_function_decl
name|int
name|cd9660_rrip_PL
parameter_list|(
name|struct
name|ISO_SUSP_ATTRIBUTES
modifier|*
parameter_list|,
name|cd9660node
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|cd9660_rrip_CL
parameter_list|(
name|struct
name|ISO_SUSP_ATTRIBUTES
modifier|*
parameter_list|,
name|cd9660node
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|cd9660_rrip_RE
parameter_list|(
name|struct
name|ISO_SUSP_ATTRIBUTES
modifier|*
parameter_list|,
name|cd9660node
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|cd9660node_rrip_tf
parameter_list|(
name|struct
name|ISO_SUSP_ATTRIBUTES
modifier|*
parameter_list|,
name|fsnode
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Relocation directory function. I'm not quite sure what  * sort of parameters are needed, but personally I don't think  * any parameters are needed except for the memory address where  * the information needs to be put in  */
end_comment

begin_function_decl
name|int
name|cd9660node_rrip_re
parameter_list|(
name|void
modifier|*
parameter_list|,
name|fsnode
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Don't know if this function is needed because it apparently is an  * optional feature that does not really need to be implemented but I  * thought I should add it anyway.  */
end_comment

begin_function_decl
name|int
name|cd9660_susp_ce
parameter_list|(
name|struct
name|ISO_SUSP_ATTRIBUTES
modifier|*
parameter_list|,
name|cd9660node
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|cd9660_susp_pd
parameter_list|(
name|struct
name|ISO_SUSP_ATTRIBUTES
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|cd9660_susp_sp
parameter_list|(
name|struct
name|ISO_SUSP_ATTRIBUTES
modifier|*
parameter_list|,
name|cd9660node
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|cd9660_susp_st
parameter_list|(
name|struct
name|ISO_SUSP_ATTRIBUTES
modifier|*
parameter_list|,
name|cd9660node
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|ISO_SUSP_ATTRIBUTES
modifier|*
name|cd9660_susp_ER
parameter_list|(
name|cd9660node
modifier|*
parameter_list|,
name|u_char
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|ISO_SUSP_ATTRIBUTES
modifier|*
name|cd9660_susp_ES
parameter_list|(
name|struct
name|ISO_SUSP_ATTRIBUTES
modifier|*
parameter_list|,
name|cd9660node
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Helper functions */
end_comment

begin_comment
comment|/* Common SUSP/RRIP functions */
end_comment

begin_function_decl
name|int
name|cd9660_susp_initialize
parameter_list|(
name|cd9660node
modifier|*
parameter_list|,
name|cd9660node
modifier|*
parameter_list|,
name|cd9660node
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|cd9660_susp_initialize_node
parameter_list|(
name|cd9660node
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|ISO_SUSP_ATTRIBUTES
modifier|*
name|cd9660node_susp_create_node
parameter_list|(
name|int
parameter_list|,
name|int
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|ISO_SUSP_ATTRIBUTES
modifier|*
name|cd9660node_susp_add_entry
parameter_list|(
name|cd9660node
modifier|*
parameter_list|,
name|struct
name|ISO_SUSP_ATTRIBUTES
modifier|*
parameter_list|,
name|struct
name|ISO_SUSP_ATTRIBUTES
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* RRIP specific functions */
end_comment

begin_function_decl
name|int
name|cd9660_rrip_initialize_node
parameter_list|(
name|cd9660node
modifier|*
parameter_list|,
name|cd9660node
modifier|*
parameter_list|,
name|cd9660node
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|cd9660_createSL
parameter_list|(
name|cd9660node
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Functions that probably can be removed */
end_comment

begin_comment
comment|/* int cd9660node_initialize_node(int, char *); */
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

