begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * CDDL HEADER START  *  * The contents of this file are subject to the terms of the  * Common Development and Distribution License, Version 1.0 only  * (the "License").  You may not use this file except in compliance  * with the License.  *  * You can obtain a copy of the license at usr/src/OPENSOLARIS.LICENSE  * or http://www.opensolaris.org/os/licensing.  * See the License for the specific language governing permissions  * and limitations under the License.  *  * When distributing Covered Code, include this CDDL HEADER in each  * file and include the License file at usr/src/OPENSOLARIS.LICENSE.  * If applicable, add the following below this CDDL HEADER, with the  * fields enclosed by brackets "[]" replaced with your own identifying  * information: Portions Copyright [yyyy] [name of copyright owner]  *  * CDDL HEADER END  */
end_comment

begin_comment
comment|/*  * Copyright 2005 Sun Microsystems, Inc.  All rights reserved.  * Use is subject to license terms.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_DT_PRINTF_H
end_ifndef

begin_define
define|#
directive|define
name|_DT_PRINTF_H
end_define

begin_pragma
pragma|#
directive|pragma
name|ident
literal|"%Z%%M%	%I%	%E% SMI"
end_pragma

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|<libctf.h>
end_include

begin_include
include|#
directive|include
file|<dtrace.h>
end_include

begin_include
include|#
directive|include
file|<stdio.h>
end_include

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
struct_decl|struct
name|dt_node
struct_decl|;
struct_decl|struct
name|dt_ident
struct_decl|;
struct_decl|struct
name|dt_pfconv
struct_decl|;
struct_decl|struct
name|dt_pfargv
struct_decl|;
struct_decl|struct
name|dt_pfargd
struct_decl|;
typedef|typedef
name|int
name|dt_pfcheck_f
parameter_list|(
name|struct
name|dt_pfargv
modifier|*
parameter_list|,
name|struct
name|dt_pfargd
modifier|*
parameter_list|,
name|struct
name|dt_node
modifier|*
parameter_list|)
function_decl|;
typedef|typedef
name|int
name|dt_pfprint_f
parameter_list|(
name|dtrace_hdl_t
modifier|*
parameter_list|,
name|FILE
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
specifier|const
name|struct
name|dt_pfargd
modifier|*
parameter_list|,
specifier|const
name|void
modifier|*
parameter_list|,
name|size_t
parameter_list|,
name|uint64_t
parameter_list|)
function_decl|;
typedef|typedef
struct|struct
name|dt_pfconv
block|{
specifier|const
name|char
modifier|*
name|pfc_name
decl_stmt|;
comment|/* string name of input conversion */
specifier|const
name|char
modifier|*
name|pfc_ofmt
decl_stmt|;
comment|/* string name of output conversion */
specifier|const
name|char
modifier|*
name|pfc_tstr
decl_stmt|;
comment|/* string name for conversion type */
name|dt_pfcheck_f
modifier|*
name|pfc_check
decl_stmt|;
comment|/* function to use for type checking */
name|dt_pfprint_f
modifier|*
name|pfc_print
decl_stmt|;
comment|/* function to use for formatting */
name|ctf_file_t
modifier|*
name|pfc_cctfp
decl_stmt|;
comment|/* CTF container for "C" defn of type */
name|ctf_id_t
name|pfc_ctype
decl_stmt|;
comment|/* CTF type ID for "C" defn of type */
name|ctf_file_t
modifier|*
name|pfc_dctfp
decl_stmt|;
comment|/* CTF container for "D" defn of type */
name|ctf_id_t
name|pfc_dtype
decl_stmt|;
comment|/* CTF type ID for "D" defn of type */
name|struct
name|dt_pfconv
modifier|*
name|pfc_next
decl_stmt|;
comment|/* next conversion in hash chain */
block|}
name|dt_pfconv_t
typedef|;
typedef|typedef
struct|struct
name|dt_pfdict
block|{
name|dt_pfconv_t
modifier|*
modifier|*
name|pdi_buckets
decl_stmt|;
comment|/* hash bucket array */
name|uint_t
name|pdi_nbuckets
decl_stmt|;
comment|/* size of hash bucket array */
block|}
name|dt_pfdict_t
typedef|;
typedef|typedef
struct|struct
name|dt_pfargd
block|{
specifier|const
name|char
modifier|*
name|pfd_prefix
decl_stmt|;
comment|/* prefix string pointer (or NULL) */
name|size_t
name|pfd_preflen
decl_stmt|;
comment|/* length of prefix in bytes */
name|char
name|pfd_fmt
index|[
literal|8
index|]
decl_stmt|;
comment|/* output format name to use */
name|uint_t
name|pfd_flags
decl_stmt|;
comment|/* format flags (see below) */
name|int
name|pfd_width
decl_stmt|;
comment|/* field width (or 0) */
name|int
name|pfd_dynwidth
decl_stmt|;
comment|/* dynamic field width (or 0) */
name|int
name|pfd_prec
decl_stmt|;
comment|/* field precision (or 0) */
specifier|const
name|dt_pfconv_t
modifier|*
name|pfd_conv
decl_stmt|;
comment|/* conversion specification */
specifier|const
name|dtrace_recdesc_t
modifier|*
name|pfd_rec
decl_stmt|;
comment|/* pointer to current record */
name|struct
name|dt_pfargd
modifier|*
name|pfd_next
decl_stmt|;
comment|/* pointer to next arg descriptor */
block|}
name|dt_pfargd_t
typedef|;
define|#
directive|define
name|DT_PFCONV_ALT
value|0x0001
comment|/* alternate print format (%#) */
define|#
directive|define
name|DT_PFCONV_ZPAD
value|0x0002
comment|/* zero-pad integer field (%0) */
define|#
directive|define
name|DT_PFCONV_LEFT
value|0x0004
comment|/* left-align field (%-) */
define|#
directive|define
name|DT_PFCONV_SPOS
value|0x0008
comment|/* sign positive values (%+) */
define|#
directive|define
name|DT_PFCONV_DYNWIDTH
value|0x0010
comment|/* dynamic width (%*.) */
define|#
directive|define
name|DT_PFCONV_DYNPREC
value|0x0020
comment|/* dynamic precision (%.*) */
define|#
directive|define
name|DT_PFCONV_GROUP
value|0x0040
comment|/* group thousands (%') */
define|#
directive|define
name|DT_PFCONV_SPACE
value|0x0080
comment|/* insert leading space (% ) */
define|#
directive|define
name|DT_PFCONV_AGG
value|0x0100
comment|/* use aggregation result (%@) */
define|#
directive|define
name|DT_PFCONV_SIGNED
value|0x0200
comment|/* arg is a signed integer */
typedef|typedef
struct|struct
name|dt_pfargv
block|{
name|dtrace_hdl_t
modifier|*
name|pfv_dtp
decl_stmt|;
comment|/* libdtrace client handle */
name|char
modifier|*
name|pfv_format
decl_stmt|;
comment|/* format string pointer */
name|dt_pfargd_t
modifier|*
name|pfv_argv
decl_stmt|;
comment|/* list of argument descriptors */
name|uint_t
name|pfv_argc
decl_stmt|;
comment|/* number of argument descriptors */
name|uint_t
name|pfv_flags
decl_stmt|;
comment|/* flags used for validation */
block|}
name|dt_pfargv_t
typedef|;
typedef|typedef
struct|struct
name|dt_pfwalk
block|{
specifier|const
name|dt_pfargv_t
modifier|*
name|pfw_argv
decl_stmt|;
comment|/* argument description list */
name|uint_t
name|pfw_aid
decl_stmt|;
comment|/* aggregation variable identifier */
name|FILE
modifier|*
name|pfw_fp
decl_stmt|;
comment|/* file pointer to use for output */
name|int
name|pfw_err
decl_stmt|;
comment|/* error status code */
block|}
name|dt_pfwalk_t
typedef|;
specifier|extern
name|int
name|dt_pfdict_create
parameter_list|(
name|dtrace_hdl_t
modifier|*
parameter_list|)
function_decl|;
specifier|extern
name|void
name|dt_pfdict_destroy
parameter_list|(
name|dtrace_hdl_t
modifier|*
parameter_list|)
function_decl|;
specifier|extern
name|dt_pfargv_t
modifier|*
name|dt_printf_create
parameter_list|(
name|dtrace_hdl_t
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
specifier|extern
name|void
name|dt_printf_destroy
parameter_list|(
name|dt_pfargv_t
modifier|*
parameter_list|)
function_decl|;
define|#
directive|define
name|DT_PRINTF_EXACTLEN
value|0x1
comment|/* do not permit extra arguments */
define|#
directive|define
name|DT_PRINTF_AGGREGATION
value|0x2
comment|/* enable aggregation conversion */
specifier|extern
name|void
name|dt_printf_validate
parameter_list|(
name|dt_pfargv_t
modifier|*
parameter_list|,
name|uint_t
parameter_list|,
name|struct
name|dt_ident
modifier|*
parameter_list|,
name|int
parameter_list|,
name|dtrace_actkind_t
parameter_list|,
name|struct
name|dt_node
modifier|*
parameter_list|)
function_decl|;
specifier|extern
name|void
name|dt_printa_validate
parameter_list|(
name|struct
name|dt_node
modifier|*
parameter_list|,
name|struct
name|dt_node
modifier|*
parameter_list|)
function_decl|;
specifier|extern
name|int
name|dt_print_stack
parameter_list|(
name|dtrace_hdl_t
modifier|*
parameter_list|,
name|FILE
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
name|caddr_t
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|)
function_decl|;
specifier|extern
name|int
name|dt_print_ustack
parameter_list|(
name|dtrace_hdl_t
modifier|*
parameter_list|,
name|FILE
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
name|caddr_t
parameter_list|,
name|uint64_t
parameter_list|)
function_decl|;
specifier|extern
name|int
name|dt_print_mod
parameter_list|(
name|dtrace_hdl_t
modifier|*
parameter_list|,
name|FILE
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
name|caddr_t
parameter_list|)
function_decl|;
specifier|extern
name|int
name|dt_print_umod
parameter_list|(
name|dtrace_hdl_t
modifier|*
parameter_list|,
name|FILE
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
name|caddr_t
parameter_list|)
function_decl|;
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
comment|/* _DT_PRINTF_H */
end_comment

end_unit

