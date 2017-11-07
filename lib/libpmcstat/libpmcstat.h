begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2005-2007, Joseph Koshy  * Copyright (c) 2007 The FreeBSD Foundation  * All rights reserved.  *  * Portions of this software were developed by A. Joseph Koshy under  * sponsorship from the FreeBSD Foundation and Google, Inc.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_LIBPMCSTAT_H_
end_ifndef

begin_define
define|#
directive|define
name|_LIBPMCSTAT_H_
end_define

begin_include
include|#
directive|include
file|<sys/_cpuset.h>
end_include

begin_include
include|#
directive|include
file|<sys/queue.h>
end_include

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_include
include|#
directive|include
file|<gelf.h>
end_include

begin_define
define|#
directive|define
name|PMCSTAT_ALLOCATE
value|1
end_define

begin_define
define|#
directive|define
name|NSOCKPAIRFD
value|2
end_define

begin_define
define|#
directive|define
name|PARENTSOCKET
value|0
end_define

begin_define
define|#
directive|define
name|CHILDSOCKET
value|1
end_define

begin_define
define|#
directive|define
name|PMCSTAT_OPEN_FOR_READ
value|0
end_define

begin_define
define|#
directive|define
name|PMCSTAT_OPEN_FOR_WRITE
value|1
end_define

begin_define
define|#
directive|define
name|READPIPEFD
value|0
end_define

begin_define
define|#
directive|define
name|WRITEPIPEFD
value|1
end_define

begin_define
define|#
directive|define
name|NPIPEFD
value|2
end_define

begin_define
define|#
directive|define
name|PMCSTAT_NHASH
value|256
end_define

begin_define
define|#
directive|define
name|PMCSTAT_HASH_MASK
value|0xFF
end_define

begin_typedef
typedef|typedef
specifier|const
name|void
modifier|*
name|pmcstat_interned_string
typedef|;
end_typedef

begin_struct_decl
struct_decl|struct
name|pmc_plugins
struct_decl|;
end_struct_decl

begin_enum
enum|enum
name|pmcstat_state
block|{
name|PMCSTAT_FINISHED
init|=
literal|0
block|,
name|PMCSTAT_EXITING
init|=
literal|1
block|,
name|PMCSTAT_RUNNING
init|=
literal|2
block|}
enum|;
end_enum

begin_struct
struct|struct
name|pmcstat_ev
block|{
name|STAILQ_ENTRY
argument_list|(
argument|pmcstat_ev
argument_list|)
name|ev_next
expr_stmt|;
name|int
name|ev_count
decl_stmt|;
comment|/* associated count if in sampling mode */
name|uint32_t
name|ev_cpu
decl_stmt|;
comment|/* cpus for this event */
name|int
name|ev_cumulative
decl_stmt|;
comment|/* show cumulative counts */
name|int
name|ev_flags
decl_stmt|;
comment|/* PMC_F_* */
name|int
name|ev_fieldskip
decl_stmt|;
comment|/* #leading spaces */
name|int
name|ev_fieldwidth
decl_stmt|;
comment|/* print width */
name|enum
name|pmc_mode
name|ev_mode
decl_stmt|;
comment|/* desired mode */
name|char
modifier|*
name|ev_name
decl_stmt|;
comment|/* (derived) event name */
name|pmc_id_t
name|ev_pmcid
decl_stmt|;
comment|/* allocated ID */
name|pmc_value_t
name|ev_saved
decl_stmt|;
comment|/* for incremental counts */
name|char
modifier|*
name|ev_spec
decl_stmt|;
comment|/* event specification */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|pmcstat_target
block|{
name|SLIST_ENTRY
argument_list|(
argument|pmcstat_target
argument_list|)
name|pt_next
expr_stmt|;
name|pid_t
name|pt_pid
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|pmcstat_args
block|{
name|int
name|pa_flags
decl_stmt|;
comment|/* argument flags */
define|#
directive|define
name|FLAG_HAS_TARGET
value|0x00000001
comment|/* process target */
define|#
directive|define
name|FLAG_HAS_WAIT_INTERVAL
value|0x00000002
comment|/* -w secs */
define|#
directive|define
name|FLAG_HAS_OUTPUT_LOGFILE
value|0x00000004
comment|/* -O file or pipe */
define|#
directive|define
name|FLAG_HAS_COMMANDLINE
value|0x00000008
comment|/* command */
define|#
directive|define
name|FLAG_HAS_SAMPLING_PMCS
value|0x00000010
comment|/* -S or -P */
define|#
directive|define
name|FLAG_HAS_COUNTING_PMCS
value|0x00000020
comment|/* -s or -p */
define|#
directive|define
name|FLAG_HAS_PROCESS_PMCS
value|0x00000040
comment|/* -P or -p */
define|#
directive|define
name|FLAG_HAS_SYSTEM_PMCS
value|0x00000080
comment|/* -S or -s */
define|#
directive|define
name|FLAG_HAS_PIPE
value|0x00000100
comment|/* implicit log */
define|#
directive|define
name|FLAG_READ_LOGFILE
value|0x00000200
comment|/* -R file */
define|#
directive|define
name|FLAG_DO_GPROF
value|0x00000400
comment|/* -g */
define|#
directive|define
name|FLAG_HAS_SAMPLESDIR
value|0x00000800
comment|/* -D dir */
define|#
directive|define
name|FLAG_HAS_KERNELPATH
value|0x00001000
comment|/* -k kernel */
define|#
directive|define
name|FLAG_DO_PRINT
value|0x00002000
comment|/* -o */
define|#
directive|define
name|FLAG_DO_CALLGRAPHS
value|0x00004000
comment|/* -G or -F */
define|#
directive|define
name|FLAG_DO_ANNOTATE
value|0x00008000
comment|/* -m */
define|#
directive|define
name|FLAG_DO_TOP
value|0x00010000
comment|/* -T */
define|#
directive|define
name|FLAG_DO_ANALYSIS
value|0x00020000
comment|/* -g or -G or -m or -T */
define|#
directive|define
name|FLAGS_HAS_CPUMASK
value|0x00040000
comment|/* -c */
define|#
directive|define
name|FLAG_HAS_DURATION
value|0x00080000
comment|/* -l secs */
define|#
directive|define
name|FLAG_DO_WIDE_GPROF_HC
value|0x00100000
comment|/* -e */
name|int
name|pa_required
decl_stmt|;
comment|/* required features */
name|int
name|pa_pplugin
decl_stmt|;
comment|/* pre-processing plugin */
name|int
name|pa_plugin
decl_stmt|;
comment|/* analysis plugin */
name|int
name|pa_verbosity
decl_stmt|;
comment|/* verbosity level */
name|FILE
modifier|*
name|pa_printfile
decl_stmt|;
comment|/* where to send printed output */
name|int
name|pa_logfd
decl_stmt|;
comment|/* output log file */
name|char
modifier|*
name|pa_inputpath
decl_stmt|;
comment|/* path to input log */
name|char
modifier|*
name|pa_outputpath
decl_stmt|;
comment|/* path to output log */
name|void
modifier|*
name|pa_logparser
decl_stmt|;
comment|/* log file parser */
specifier|const
name|char
modifier|*
name|pa_fsroot
decl_stmt|;
comment|/* FS root where executables reside */
name|char
modifier|*
name|pa_kernel
decl_stmt|;
comment|/* pathname of the kernel */
specifier|const
name|char
modifier|*
name|pa_samplesdir
decl_stmt|;
comment|/* directory for profile files */
specifier|const
name|char
modifier|*
name|pa_mapfilename
decl_stmt|;
comment|/* mapfile name */
name|FILE
modifier|*
name|pa_graphfile
decl_stmt|;
comment|/* where to send the callgraph */
name|int
name|pa_graphdepth
decl_stmt|;
comment|/* print depth for callgraphs */
name|double
name|pa_interval
decl_stmt|;
comment|/* printing interval in seconds */
name|cpuset_t
name|pa_cpumask
decl_stmt|;
comment|/* filter for CPUs analysed */
name|int
name|pa_ctdumpinstr
decl_stmt|;
comment|/* dump instructions with calltree */
name|int
name|pa_topmode
decl_stmt|;
comment|/* delta or accumulative */
name|int
name|pa_toptty
decl_stmt|;
comment|/* output to tty or file */
name|int
name|pa_topcolor
decl_stmt|;
comment|/* terminal support color */
name|int
name|pa_mergepmc
decl_stmt|;
comment|/* merge PMC with same name */
name|double
name|pa_duration
decl_stmt|;
comment|/* time duration */
name|int
name|pa_argc
decl_stmt|;
name|char
modifier|*
modifier|*
name|pa_argv
decl_stmt|;
name|STAILQ_HEAD
argument_list|(
argument_list|,
argument|pmcstat_ev
argument_list|)
name|pa_events
expr_stmt|;
name|SLIST_HEAD
argument_list|(
argument_list|,
argument|pmcstat_target
argument_list|)
name|pa_targets
expr_stmt|;
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
comment|/*  * A simple implementation of interned strings.  Each interned string  * is assigned a unique address, so that subsequent string compares  * can be done by a simple pointer comparison instead of using  * strcmp().  This speeds up hash table lookups and saves memory if  * duplicate strings are the norm.  */
end_comment

begin_struct
struct|struct
name|pmcstat_string
block|{
name|LIST_ENTRY
argument_list|(
argument|pmcstat_string
argument_list|)
name|ps_next
expr_stmt|;
comment|/* hash link */
name|int
name|ps_len
decl_stmt|;
name|int
name|ps_hash
decl_stmt|;
name|char
modifier|*
name|ps_string
decl_stmt|;
block|}
struct|;
end_struct

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

begin_struct
struct|struct
name|pmc_plugins
block|{
specifier|const
name|char
modifier|*
name|pl_name
decl_stmt|;
comment|/* configure */
name|int
function_decl|(
modifier|*
name|pl_configure
function_decl|)
parameter_list|(
name|char
modifier|*
name|opt
parameter_list|)
function_decl|;
comment|/* init and shutdown */
name|int
function_decl|(
modifier|*
name|pl_init
function_decl|)
parameter_list|(
name|void
parameter_list|)
function_decl|;
name|void
function_decl|(
modifier|*
name|pl_shutdown
function_decl|)
parameter_list|(
name|FILE
modifier|*
name|mf
parameter_list|)
function_decl|;
comment|/* sample processing */
name|void
function_decl|(
modifier|*
name|pl_process
function_decl|)
parameter_list|(
name|struct
name|pmcstat_process
modifier|*
name|pp
parameter_list|,
name|struct
name|pmcstat_pmcrecord
modifier|*
name|pmcr
parameter_list|,
name|uint32_t
name|nsamples
parameter_list|,
name|uintfptr_t
modifier|*
name|cc
parameter_list|,
name|int
name|usermode
parameter_list|,
name|uint32_t
name|cpu
parameter_list|)
function_decl|;
comment|/* image */
name|void
function_decl|(
modifier|*
name|pl_initimage
function_decl|)
parameter_list|(
name|struct
name|pmcstat_image
modifier|*
name|pi
parameter_list|)
function_decl|;
name|void
function_decl|(
modifier|*
name|pl_shutdownimage
function_decl|)
parameter_list|(
name|struct
name|pmcstat_image
modifier|*
name|pi
parameter_list|)
function_decl|;
comment|/* pmc */
name|void
function_decl|(
modifier|*
name|pl_newpmc
function_decl|)
parameter_list|(
name|pmcstat_interned_string
name|ps
parameter_list|,
name|struct
name|pmcstat_pmcrecord
modifier|*
name|pr
parameter_list|)
function_decl|;
comment|/* top display */
name|void
function_decl|(
modifier|*
name|pl_topdisplay
function_decl|)
parameter_list|(
name|void
parameter_list|)
function_decl|;
comment|/* top keypress */
name|int
function_decl|(
modifier|*
name|pl_topkeypress
function_decl|)
parameter_list|(
name|int
name|c
parameter_list|,
name|void
modifier|*
name|w
parameter_list|)
function_decl|;
block|}
struct|;
end_struct

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

begin_function_decl
name|__BEGIN_DECLS
name|int
name|pmcstat_symbol_compare
parameter_list|(
specifier|const
name|void
modifier|*
name|a
parameter_list|,
specifier|const
name|void
modifier|*
name|b
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
name|void
name|pmcstat_image_add_symbols
parameter_list|(
name|struct
name|pmcstat_image
modifier|*
name|image
parameter_list|,
name|Elf
modifier|*
name|e
parameter_list|,
name|Elf_Scn
modifier|*
name|scn
parameter_list|,
name|GElf_Shdr
modifier|*
name|sh
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
name|int
name|pmcstat_string_compute_hash
parameter_list|(
specifier|const
name|char
modifier|*
name|s
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
name|void
name|pmcstat_image_get_elf_params
parameter_list|(
name|struct
name|pmcstat_image
modifier|*
name|image
parameter_list|,
name|struct
name|pmcstat_args
modifier|*
name|args
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|pmcstat_image
modifier|*
name|pmcstat_image_from_path
parameter_list|(
name|pmcstat_interned_string
name|internedpath
parameter_list|,
name|int
name|iskernelmodule
parameter_list|,
name|struct
name|pmcstat_args
modifier|*
name|args
parameter_list|,
name|struct
name|pmc_plugins
modifier|*
name|plugins
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|pmcstat_string_lookup_hash
parameter_list|(
name|pmcstat_interned_string
name|_is
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|pmcstat_process_elf_exec
parameter_list|(
name|struct
name|pmcstat_process
modifier|*
name|_pp
parameter_list|,
name|struct
name|pmcstat_image
modifier|*
name|_image
parameter_list|,
name|uintfptr_t
name|_entryaddr
parameter_list|,
name|struct
name|pmcstat_args
modifier|*
name|args
parameter_list|,
name|struct
name|pmc_plugins
modifier|*
name|plugins
parameter_list|,
name|struct
name|pmcstat_stats
modifier|*
name|pmcstat_stats
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|pmcstat_image_link
parameter_list|(
name|struct
name|pmcstat_process
modifier|*
name|_pp
parameter_list|,
name|struct
name|pmcstat_image
modifier|*
name|_i
parameter_list|,
name|uintfptr_t
name|_lpc
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|pmcstat_process_aout_exec
parameter_list|(
name|struct
name|pmcstat_process
modifier|*
name|_pp
parameter_list|,
name|struct
name|pmcstat_image
modifier|*
name|_image
parameter_list|,
name|uintfptr_t
name|_entryaddr
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|pmcstat_process_exec
parameter_list|(
name|struct
name|pmcstat_process
modifier|*
name|_pp
parameter_list|,
name|pmcstat_interned_string
name|_path
parameter_list|,
name|uintfptr_t
name|_entryaddr
parameter_list|,
name|struct
name|pmcstat_args
modifier|*
name|args
parameter_list|,
name|struct
name|pmc_plugins
modifier|*
name|plugins
parameter_list|,
name|struct
name|pmcstat_stats
modifier|*
name|pmcstat_stats
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
parameter_list|,
name|struct
name|pmcstat_args
modifier|*
name|args
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|pmcstat_image_get_aout_params
parameter_list|(
name|struct
name|pmcstat_image
modifier|*
name|_image
parameter_list|,
name|struct
name|pmcstat_args
modifier|*
name|args
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
name|void
name|pmcstat_initialize_logging
parameter_list|(
name|struct
name|pmcstat_process
modifier|*
modifier|*
name|pmcstat_kernproc
parameter_list|,
name|struct
name|pmcstat_args
modifier|*
name|args
parameter_list|,
name|struct
name|pmc_plugins
modifier|*
name|plugins
parameter_list|,
name|int
modifier|*
name|pmcstat_npmcs
parameter_list|,
name|int
modifier|*
name|pmcstat_mergepmc
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|pmcstat_shutdown_logging
parameter_list|(
name|struct
name|pmcstat_args
modifier|*
name|args
parameter_list|,
name|struct
name|pmc_plugins
modifier|*
name|plugins
parameter_list|,
name|struct
name|pmcstat_stats
modifier|*
name|pmcstat_stats
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|pmcstat_process
modifier|*
name|pmcstat_process_lookup
parameter_list|(
name|pid_t
name|_pid
parameter_list|,
name|int
name|_allocate
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|pmcstat_clone_event_descriptor
parameter_list|(
name|struct
name|pmcstat_ev
modifier|*
name|ev
parameter_list|,
specifier|const
name|cpuset_t
modifier|*
name|cpumask
parameter_list|,
name|struct
name|pmcstat_args
modifier|*
name|args
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|pmcstat_create_process
parameter_list|(
name|int
modifier|*
name|pmcstat_sockpair
parameter_list|,
name|struct
name|pmcstat_args
modifier|*
name|args
parameter_list|,
name|int
name|pmcstat_kq
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|pmcstat_start_process
parameter_list|(
name|int
modifier|*
name|pmcstat_sockpair
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|pmcstat_attach_pmcs
parameter_list|(
name|struct
name|pmcstat_args
modifier|*
name|args
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|pmcstat_symbol
modifier|*
name|pmcstat_symbol_search_by_name
parameter_list|(
name|struct
name|pmcstat_process
modifier|*
name|pp
parameter_list|,
specifier|const
name|char
modifier|*
name|pi_name
parameter_list|,
specifier|const
name|char
modifier|*
name|name
parameter_list|,
name|uintptr_t
modifier|*
parameter_list|,
name|uintptr_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|pmcstat_string_initialize
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|pmcstat_string_shutdown
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|pmcstat_analyze_log
parameter_list|(
name|struct
name|pmcstat_args
modifier|*
name|args
parameter_list|,
name|struct
name|pmc_plugins
modifier|*
name|plugins
parameter_list|,
name|struct
name|pmcstat_stats
modifier|*
name|pmcstat_stats
parameter_list|,
name|struct
name|pmcstat_process
modifier|*
name|pmcstat_kernproc
parameter_list|,
name|int
name|pmcstat_mergepmc
parameter_list|,
name|int
modifier|*
name|pmcstat_npmcs
parameter_list|,
name|int
modifier|*
name|ps_samples_period
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|pmcstat_open_log
parameter_list|(
specifier|const
name|char
modifier|*
name|_p
parameter_list|,
name|int
name|_mode
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|pmcstat_close_log
parameter_list|(
name|struct
name|pmcstat_args
modifier|*
name|args
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
comment|/* !_LIBPMCSTAT_H_ */
end_comment

end_unit

