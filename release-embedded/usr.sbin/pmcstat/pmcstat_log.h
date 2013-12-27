begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2005-2007, Joseph Koshy  * Copyright (c) 2007 The FreeBSD Foundation  * Copyright (c) 2009, Fabien Thomas  * All rights reserved.  *  * Portions of this software were developed by A. Joseph Koshy under  * sponsorship from the FreeBSD Foundation and Google, Inc.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_PMCSTAT_LOG_H_
end_ifndef

begin_define
define|#
directive|define
name|_PMCSTAT_LOG_H_
end_define

begin_typedef
typedef|typedef
specifier|const
name|void
modifier|*
name|pmcstat_interned_string
typedef|;
end_typedef

begin_comment
comment|/*  * A 'pmcstat_process' structure models processes.  Each process is  * associated with a set of pmcstat_pcmap structures that map  * addresses inside it to executable objects.  This set is implemented  * as a list, kept sorted in ascending order of mapped addresses.  *  * 'pp_pid' holds the pid of the process.  When a process exits, the  * 'pp_isactive' field is set to zero, but the process structure is  * not immediately reclaimed because there may still be samples in the  * log for this process.  */
end_comment

begin_struct
struct|struct
name|pmcstat_process
block|{
name|LIST_ENTRY
argument_list|(
argument|pmcstat_process
argument_list|)
name|pp_next
expr_stmt|;
comment|/* hash-next */
name|pid_t
name|pp_pid
decl_stmt|;
comment|/* associated pid */
name|int
name|pp_isactive
decl_stmt|;
comment|/* whether active */
name|uintfptr_t
name|pp_entryaddr
decl_stmt|;
comment|/* entry address */
name|TAILQ_HEAD
argument_list|(
argument_list|,
argument|pmcstat_pcmap
argument_list|)
name|pp_map
expr_stmt|;
comment|/* address range map */
block|}
struct|;
end_struct

begin_extern
extern|extern LIST_HEAD(pmcstat_process_hash_list
operator|,
extern|pmcstat_process
end_extern

begin_expr_stmt
unit|)
name|pmcstat_process_hash
index|[
name|PMCSTAT_NHASH
index|]
expr_stmt|;
end_expr_stmt

begin_comment
comment|/*  * A 'pmcstat_image' structure describes an executable program on  * disk.  'pi_execpath' is a cookie representing the pathname of  * the executable.  'pi_start' and 'pi_end' are the least and greatest  * virtual addresses for the text segments in the executable.  * 'pi_gmonlist' contains a linked list of gmon.out files associated  * with this image.  */
end_comment

begin_enum
enum|enum
name|pmcstat_image_type
block|{
name|PMCSTAT_IMAGE_UNKNOWN
init|=
literal|0
block|,
comment|/* never looked at the image */
name|PMCSTAT_IMAGE_INDETERMINABLE
block|,
comment|/* can't tell what the image is */
name|PMCSTAT_IMAGE_ELF32
block|,
comment|/* ELF 32 bit object */
name|PMCSTAT_IMAGE_ELF64
block|,
comment|/* ELF 64 bit object */
name|PMCSTAT_IMAGE_AOUT
comment|/* AOUT object */
block|}
enum|;
end_enum

begin_struct
struct|struct
name|pmcstat_image
block|{
name|LIST_ENTRY
argument_list|(
argument|pmcstat_image
argument_list|)
name|pi_next
expr_stmt|;
comment|/* hash link */
name|TAILQ_ENTRY
argument_list|(
argument|pmcstat_image
argument_list|)
name|pi_lru
expr_stmt|;
comment|/* LRU list */
name|pmcstat_interned_string
name|pi_execpath
decl_stmt|;
comment|/* cookie */
name|pmcstat_interned_string
name|pi_samplename
decl_stmt|;
comment|/* sample path name */
name|pmcstat_interned_string
name|pi_fullpath
decl_stmt|;
comment|/* path to FS object */
name|pmcstat_interned_string
name|pi_name
decl_stmt|;
comment|/* display name */
name|enum
name|pmcstat_image_type
name|pi_type
decl_stmt|;
comment|/* executable type */
comment|/* 	 * Executables have pi_start and pi_end; these are zero 	 * for shared libraries. 	 */
name|uintfptr_t
name|pi_start
decl_stmt|;
comment|/* start address (inclusive) */
name|uintfptr_t
name|pi_end
decl_stmt|;
comment|/* end address (exclusive) */
name|uintfptr_t
name|pi_entry
decl_stmt|;
comment|/* entry address */
name|uintfptr_t
name|pi_vaddr
decl_stmt|;
comment|/* virtual address where loaded */
name|int
name|pi_isdynamic
decl_stmt|;
comment|/* whether a dynamic object */
name|int
name|pi_iskernelmodule
decl_stmt|;
name|pmcstat_interned_string
name|pi_dynlinkerpath
decl_stmt|;
comment|/* path in .interp */
comment|/* All symbols associated with this object. */
name|struct
name|pmcstat_symbol
modifier|*
name|pi_symbols
decl_stmt|;
name|size_t
name|pi_symcount
decl_stmt|;
comment|/* Handle to addr2line for this image. */
name|FILE
modifier|*
name|pi_addr2line
decl_stmt|;
comment|/* 	 * Plugins private data 	 */
comment|/* gprof: 	 * An image can be associated with one or more gmon.out files; 	 * one per PMC. 	 */
name|LIST_HEAD
argument_list|(
argument_list|,
argument|pmcstat_gmonfile
argument_list|)
name|pi_gmlist
expr_stmt|;
block|}
struct|;
end_struct

begin_extern
extern|extern LIST_HEAD(pmcstat_image_hash_list
operator|,
extern|pmcstat_image
end_extern

begin_expr_stmt
unit|)
name|pmcstat_image_hash
index|[
name|PMCSTAT_NHASH
index|]
expr_stmt|;
end_expr_stmt

begin_comment
comment|/*  * A 'pmcstat_pcmap' structure maps a virtual address range to an  * underlying 'pmcstat_image' descriptor.  */
end_comment

begin_struct
struct|struct
name|pmcstat_pcmap
block|{
name|TAILQ_ENTRY
argument_list|(
argument|pmcstat_pcmap
argument_list|)
name|ppm_next
expr_stmt|;
name|uintfptr_t
name|ppm_lowpc
decl_stmt|;
name|uintfptr_t
name|ppm_highpc
decl_stmt|;
name|struct
name|pmcstat_image
modifier|*
name|ppm_image
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * Each function symbol tracked by pmcstat(8).  */
end_comment

begin_struct
struct|struct
name|pmcstat_symbol
block|{
name|pmcstat_interned_string
name|ps_name
decl_stmt|;
name|uint64_t
name|ps_start
decl_stmt|;
name|uint64_t
name|ps_end
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * 'pmcstat_pmcrecord' is a mapping from PMC ids to human-readable  * names.  */
end_comment

begin_struct
struct|struct
name|pmcstat_pmcrecord
block|{
name|LIST_ENTRY
argument_list|(
argument|pmcstat_pmcrecord
argument_list|)
name|pr_next
expr_stmt|;
name|pmc_id_t
name|pr_pmcid
decl_stmt|;
name|int
name|pr_pmcin
decl_stmt|;
name|pmcstat_interned_string
name|pr_pmcname
decl_stmt|;
name|int
name|pr_samples
decl_stmt|;
name|int
name|pr_dubious_frames
decl_stmt|;
name|struct
name|pmcstat_pmcrecord
modifier|*
name|pr_merge
decl_stmt|;
block|}
struct|;
end_struct

begin_extern
extern|extern LIST_HEAD(pmcstat_pmcs
operator|,
extern|pmcstat_pmcrecord
end_extern

begin_expr_stmt
unit|)
name|pmcstat_pmcs
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* PMC list */
end_comment

begin_comment
comment|/*  * Misc. statistics  */
end_comment

begin_struct
struct|struct
name|pmcstat_stats
block|{
name|int
name|ps_exec_aout
decl_stmt|;
comment|/* # a.out executables seen */
name|int
name|ps_exec_elf
decl_stmt|;
comment|/* # elf executables seen */
name|int
name|ps_exec_errors
decl_stmt|;
comment|/* # errors processing executables */
name|int
name|ps_exec_indeterminable
decl_stmt|;
comment|/* # unknown executables seen */
name|int
name|ps_samples_total
decl_stmt|;
comment|/* total number of samples processed */
name|int
name|ps_samples_skipped
decl_stmt|;
comment|/* #samples filtered out for any reason */
name|int
name|ps_samples_unknown_offset
decl_stmt|;
comment|/* #samples of rank 0 not in a map */
name|int
name|ps_samples_indeterminable
decl_stmt|;
comment|/* #samples in indeterminable images */
name|int
name|ps_samples_unknown_function
decl_stmt|;
comment|/* #samples with unknown function at offset */
name|int
name|ps_callchain_dubious_frames
decl_stmt|;
comment|/* #dubious frame pointers seen */
block|}
struct|;
end_struct

begin_decl_stmt
specifier|extern
name|struct
name|pmcstat_stats
name|pmcstat_stats
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* statistics */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|pmcstat_process
modifier|*
name|pmcstat_kernproc
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* kernel 'process' */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|pmcstat_npmcs
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* PMC count. */
end_comment

begin_comment
comment|/*  * Top mode global options.  */
end_comment

begin_decl_stmt
specifier|extern
name|float
name|pmcstat_threshold
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Threshold to filter node. */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|pmcstat_pmcinfilter
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* PMC index displayed. */
end_comment

begin_comment
comment|/* Function prototypes */
end_comment

begin_function_decl
specifier|const
name|char
modifier|*
name|pmcstat_pmcid_to_name
parameter_list|(
name|pmc_id_t
name|_pmcid
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|const
name|char
modifier|*
name|pmcstat_pmcindex_to_name
parameter_list|(
name|int
name|pmcin
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|pmcstat_pmcrecord
modifier|*
name|pmcstat_pmcindex_to_pmcr
parameter_list|(
name|int
name|pmcin
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|pmcstat_pcmap
modifier|*
name|pmcstat_process_find_map
parameter_list|(
name|struct
name|pmcstat_process
modifier|*
name|_p
parameter_list|,
name|uintfptr_t
name|_pc
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|pmcstat_symbol
modifier|*
name|pmcstat_symbol_search
parameter_list|(
name|struct
name|pmcstat_image
modifier|*
name|image
parameter_list|,
name|uintfptr_t
name|addr
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|const
name|char
modifier|*
name|pmcstat_string_unintern
parameter_list|(
name|pmcstat_interned_string
name|_is
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|pmcstat_interned_string
name|pmcstat_string_intern
parameter_list|(
specifier|const
name|char
modifier|*
name|_s
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|pmcstat_image_determine_type
parameter_list|(
name|struct
name|pmcstat_image
modifier|*
name|_image
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|pmcstat_interned_string
name|pmcstat_string_lookup
parameter_list|(
specifier|const
name|char
modifier|*
name|_s
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|pmcstat_image_addr2line
parameter_list|(
name|struct
name|pmcstat_image
modifier|*
name|image
parameter_list|,
name|uintfptr_t
name|addr
parameter_list|,
name|char
modifier|*
name|sourcefile
parameter_list|,
name|size_t
name|sourcefile_len
parameter_list|,
name|unsigned
modifier|*
name|sourceline
parameter_list|,
name|char
modifier|*
name|funcname
parameter_list|,
name|size_t
name|funcname_len
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _PMCSTAT_LOG_H_ */
end_comment

end_unit

