begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1983, 1993  *	The Regents of the University of California.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)gprof.h	8.1 (Berkeley) 6/6/93  * $FreeBSD$  */
end_comment

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|<sys/stat.h>
end_include

begin_include
include|#
directive|include
file|<sys/gmon.h>
end_include

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_include
include|#
directive|include
file|<stdlib.h>
end_include

begin_if
if|#
directive|if
name|__ia64__
end_if

begin_include
include|#
directive|include
file|"ia64.h"
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|__alpha__
end_if

begin_include
include|#
directive|include
file|"alpha.h"
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|__sparc64__
end_if

begin_include
include|#
directive|include
file|"sparc64.h"
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|__powerpc__
end_if

begin_include
include|#
directive|include
file|"powerpc.h"
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|__i386__
end_if

begin_include
include|#
directive|include
file|"i386.h"
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|__arm__
end_if

begin_include
include|#
directive|include
file|"arm.h"
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*      * booleans      */
end_comment

begin_typedef
typedef|typedef
name|int
name|bool
typedef|;
end_typedef

begin_define
define|#
directive|define
name|FALSE
value|0
end_define

begin_define
define|#
directive|define
name|TRUE
value|1
end_define

begin_comment
comment|/*      *	Historical scale factor in profil(2)'s algorithm for converting      *	pc addresses to bucket numbers.  This now just complicates the      *	scaling and makes bucket:pc densities of more than 1/2 useless.      */
end_comment

begin_define
define|#
directive|define
name|HISTORICAL_SCALE_2
value|2
end_define

begin_comment
comment|/*      *	ticks per second      */
end_comment

begin_decl_stmt
name|long
name|hz
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|size_t
name|histcounter_size
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|histcounter_type
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|a_outname
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|A_OUTNAME
value|"a.out"
end_define

begin_decl_stmt
name|char
modifier|*
name|gmonname
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|GMONSUM
value|"gmon.sum"
end_define

begin_comment
comment|/*      *	a constructed arc,      *	    with pointers to the namelist entry of the parent and the child,      *	    a count of how many times this arc was traversed,      *	    and pointers to the next parent of this child and      *		the next child of this parent.      */
end_comment

begin_struct
struct|struct
name|arcstruct
block|{
name|struct
name|nl
modifier|*
name|arc_parentp
decl_stmt|;
comment|/* pointer to parent's nl entry */
name|struct
name|nl
modifier|*
name|arc_childp
decl_stmt|;
comment|/* pointer to child's nl entry */
name|long
name|arc_count
decl_stmt|;
comment|/* num calls from parent to child */
name|double
name|arc_time
decl_stmt|;
comment|/* time inherited along arc */
name|double
name|arc_childtime
decl_stmt|;
comment|/* childtime inherited along arc */
name|struct
name|arcstruct
modifier|*
name|arc_parentlist
decl_stmt|;
comment|/* parents-of-this-child list */
name|struct
name|arcstruct
modifier|*
name|arc_childlist
decl_stmt|;
comment|/* children-of-this-parent list */
name|struct
name|arcstruct
modifier|*
name|arc_next
decl_stmt|;
comment|/* list of arcs on cycle */
name|unsigned
name|short
name|arc_cyclecnt
decl_stmt|;
comment|/* num cycles involved in */
name|unsigned
name|short
name|arc_flags
decl_stmt|;
comment|/* see below */
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|arcstruct
name|arctype
typedef|;
end_typedef

begin_comment
comment|/*      * arc flags      */
end_comment

begin_define
define|#
directive|define
name|DEADARC
value|0x01
end_define

begin_comment
comment|/* time should not propagate across the arc */
end_comment

begin_define
define|#
directive|define
name|ONLIST
value|0x02
end_define

begin_comment
comment|/* arc is on list of arcs in cycles */
end_comment

begin_comment
comment|/*      * The symbol table;      * for each external in the specified file we gather      * its address, the number of calls and compute its share of CPU time.      */
end_comment

begin_struct
struct|struct
name|nl
block|{
specifier|const
name|char
modifier|*
name|name
decl_stmt|;
comment|/* the name */
name|unsigned
name|long
name|value
decl_stmt|;
comment|/* the pc entry point */
name|unsigned
name|long
name|svalue
decl_stmt|;
comment|/* entry point aligned to histograms */
name|double
name|time
decl_stmt|;
comment|/* ticks in this routine */
name|double
name|childtime
decl_stmt|;
comment|/* cumulative ticks in children */
name|long
name|ncall
decl_stmt|;
comment|/* how many times called */
name|long
name|npropcall
decl_stmt|;
comment|/* times called by live arcs */
name|long
name|selfcalls
decl_stmt|;
comment|/* how many calls to self */
name|double
name|propfraction
decl_stmt|;
comment|/* what % of time propagates */
name|double
name|propself
decl_stmt|;
comment|/* how much self time propagates */
name|double
name|propchild
decl_stmt|;
comment|/* how much child time propagates */
name|short
name|printflag
decl_stmt|;
comment|/* should this be printed? */
name|short
name|flags
decl_stmt|;
comment|/* see below */
name|int
name|index
decl_stmt|;
comment|/* index in the graph list */
name|int
name|toporder
decl_stmt|;
comment|/* graph call chain top-sort order */
name|int
name|cycleno
decl_stmt|;
comment|/* internal number of cycle on */
name|int
name|parentcnt
decl_stmt|;
comment|/* number of live parent arcs */
name|struct
name|nl
modifier|*
name|cyclehead
decl_stmt|;
comment|/* pointer to head of cycle */
name|struct
name|nl
modifier|*
name|cnext
decl_stmt|;
comment|/* pointer to next member of cycle */
name|arctype
modifier|*
name|parents
decl_stmt|;
comment|/* list of caller arcs */
name|arctype
modifier|*
name|children
decl_stmt|;
comment|/* list of callee arcs */
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|nl
name|nltype
typedef|;
end_typedef

begin_decl_stmt
name|nltype
modifier|*
name|nl
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* the whole namelist */
end_comment

begin_decl_stmt
name|nltype
modifier|*
name|npe
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* the virtual end of the namelist */
end_comment

begin_decl_stmt
name|int
name|nname
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* the number of function names */
end_comment

begin_define
define|#
directive|define
name|HASCYCLEXIT
value|0x08
end_define

begin_comment
comment|/* node has arc exiting from cycle */
end_comment

begin_define
define|#
directive|define
name|CYCLEHEAD
value|0x10
end_define

begin_comment
comment|/* node marked as head of a cycle */
end_comment

begin_define
define|#
directive|define
name|VISITED
value|0x20
end_define

begin_comment
comment|/* node visited during a cycle */
end_comment

begin_comment
comment|/*      * The cycle list.      * for each subcycle within an identified cycle, we gather      * its size and the list of included arcs.      */
end_comment

begin_struct
struct|struct
name|cl
block|{
name|int
name|size
decl_stmt|;
comment|/* length of cycle */
name|struct
name|cl
modifier|*
name|next
decl_stmt|;
comment|/* next member of list */
name|arctype
modifier|*
name|list
index|[
literal|1
index|]
decl_stmt|;
comment|/* list of arcs in cycle */
comment|/* actually longer */
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|cl
name|cltype
typedef|;
end_typedef

begin_decl_stmt
name|arctype
modifier|*
name|archead
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* the head of arcs in current cycle list */
end_comment

begin_decl_stmt
name|cltype
modifier|*
name|cyclehead
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* the head of the list */
end_comment

begin_decl_stmt
name|int
name|cyclecnt
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* the number of cycles found */
end_comment

begin_define
define|#
directive|define
name|CYCLEMAX
value|100
end_define

begin_comment
comment|/* maximum cycles before cutting one of them */
end_comment

begin_comment
comment|/*      *	flag which marks a nl entry as topologically ``busy''      *	flag which marks a nl entry as topologically ``not_numbered''      */
end_comment

begin_define
define|#
directive|define
name|DFN_BUSY
value|-1
end_define

begin_define
define|#
directive|define
name|DFN_NAN
value|0
end_define

begin_comment
comment|/*      *	namelist entries for cycle headers.      *	the number of discovered cycles.      */
end_comment

begin_decl_stmt
name|nltype
modifier|*
name|cyclenl
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* cycle header namelist */
end_comment

begin_decl_stmt
name|int
name|ncycle
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* number of cycles discovered */
end_comment

begin_comment
comment|/*      * The header on the gmon.out file.      * gmon.out consists of a struct phdr (defined in gmon.h)      * and then an array of ncnt samples representing the      * discretized program counter values.      *      *	Backward compatible old style header      */
end_comment

begin_struct
struct|struct
name|ophdr
block|{
name|u_short
modifier|*
name|lpc
decl_stmt|;
name|u_short
modifier|*
name|hpc
decl_stmt|;
name|int
name|ncnt
decl_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
name|int
name|debug
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*      * Each discretized pc sample has      * a count of the number of samples in its range      */
end_comment

begin_decl_stmt
name|double
modifier|*
name|samples
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|unsigned
name|long
name|s_lowpc
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* lowpc from the profile file */
end_comment

begin_decl_stmt
name|unsigned
name|long
name|s_highpc
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* highpc from the profile file */
end_comment

begin_decl_stmt
name|unsigned
name|long
name|lowpc
decl_stmt|,
name|highpc
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* range profiled, in historical units  */
end_comment

begin_decl_stmt
name|unsigned
name|sampbytes
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* number of bytes of samples */
end_comment

begin_decl_stmt
name|int
name|nsamples
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* number of samples */
end_comment

begin_decl_stmt
name|double
name|actime
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* accumulated time thus far for putprofline */
end_comment

begin_decl_stmt
name|double
name|totime
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* total time for all routines */
end_comment

begin_decl_stmt
name|double
name|printtime
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* total of time being printed */
end_comment

begin_decl_stmt
name|double
name|scale
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* scale factor converting samples to pc 				   values: each sample covers scale bytes */
end_comment

begin_decl_stmt
name|unsigned
name|char
modifier|*
name|textspace
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* text space of a.out in core */
end_comment

begin_decl_stmt
name|int
name|cyclethreshold
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* with -C, minimum cycle size to ignore */
end_comment

begin_comment
comment|/*      *	option flags, from a to z.      */
end_comment

begin_decl_stmt
name|bool
name|aflag
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* suppress static functions */
end_comment

begin_decl_stmt
name|bool
name|bflag
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* blurbs, too */
end_comment

begin_decl_stmt
name|bool
name|cflag
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* discovered call graph, too */
end_comment

begin_decl_stmt
name|bool
name|Cflag
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* find cut-set to eliminate cycles */
end_comment

begin_decl_stmt
name|bool
name|dflag
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* debugging options */
end_comment

begin_decl_stmt
name|bool
name|eflag
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* specific functions excluded */
end_comment

begin_decl_stmt
name|bool
name|Eflag
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* functions excluded with time */
end_comment

begin_decl_stmt
name|bool
name|fflag
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* specific functions requested */
end_comment

begin_decl_stmt
name|bool
name|Fflag
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* functions requested with time */
end_comment

begin_decl_stmt
name|bool
name|kflag
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* arcs to be deleted */
end_comment

begin_decl_stmt
name|bool
name|Kflag
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* use the running kernel for symbols */
end_comment

begin_decl_stmt
name|bool
name|sflag
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* sum multiple gmon.out files */
end_comment

begin_decl_stmt
name|bool
name|uflag
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* suppress symbols hidden from C */
end_comment

begin_decl_stmt
name|bool
name|zflag
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* zero time/called functions, too */
end_comment

begin_comment
comment|/*      *	structure for various string lists      */
end_comment

begin_struct
struct|struct
name|stringlist
block|{
name|struct
name|stringlist
modifier|*
name|next
decl_stmt|;
name|char
modifier|*
name|string
decl_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
name|struct
name|stringlist
modifier|*
name|elist
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|stringlist
modifier|*
name|Elist
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|stringlist
modifier|*
name|flist
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|stringlist
modifier|*
name|Flist
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|stringlist
modifier|*
name|kfromlist
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|stringlist
modifier|*
name|ktolist
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*      *	function declarations      */
end_comment

begin_function_decl
name|void
name|addarc
parameter_list|(
name|nltype
modifier|*
parameter_list|,
name|nltype
modifier|*
parameter_list|,
name|long
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|bool
name|addcycle
parameter_list|(
name|arctype
modifier|*
modifier|*
parameter_list|,
name|arctype
modifier|*
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|addlist
parameter_list|(
name|struct
name|stringlist
modifier|*
parameter_list|,
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|alignentries
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|aout_getnfile
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
name|char
modifier|*
modifier|*
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|arccmp
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|arctype
modifier|*
name|arclookup
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|asgnsamples
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|compresslist
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|bool
name|cycleanalyze
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|cyclelink
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|cycletime
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|bool
name|descend
parameter_list|(
name|nltype
modifier|*
parameter_list|,
name|arctype
modifier|*
modifier|*
parameter_list|,
name|arctype
modifier|*
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|dfn
parameter_list|(
name|nltype
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|bool
name|dfn_busy
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|dfn_findcycle
parameter_list|(
name|nltype
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|dfn_init
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|bool
name|dfn_numbered
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|dfn_post_visit
parameter_list|(
name|nltype
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|dfn_pre_visit
parameter_list|(
name|nltype
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|dfn_self_cycle
parameter_list|(
name|nltype
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|nltype
modifier|*
modifier|*
name|doarcs
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|doflags
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|dotime
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|dumpsum
parameter_list|(
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|elf_getnfile
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
name|char
modifier|*
modifier|*
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* 		findcalls(); */
end_comment

begin_function_decl
name|void
name|flatprofheader
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|flatprofline
parameter_list|(
name|nltype
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|getpfile
parameter_list|(
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* 		gprofheader(); 		gprofline(); */
end_comment

begin_function_decl
name|void
name|inheritflags
parameter_list|(
name|nltype
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|kernel_getnfile
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
name|char
modifier|*
modifier|*
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* 		main(); */
end_comment

begin_function_decl
name|unsigned
name|long
name|max
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|membercmp
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|unsigned
name|long
name|min
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|nltype
modifier|*
name|nllookup
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|bool
name|onlist
parameter_list|(
name|struct
name|stringlist
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|FILE
modifier|*
name|openpfile
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|long
name|operandlength
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|operandenum
name|operandmode
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|operandname
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|printblurb
parameter_list|(
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|printchildren
parameter_list|(
name|nltype
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|printcycle
parameter_list|(
name|nltype
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|printgprof
parameter_list|(
name|nltype
modifier|*
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|printindex
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|printmembers
parameter_list|(
name|nltype
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|printname
parameter_list|(
name|nltype
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|printparents
parameter_list|(
name|nltype
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|printprof
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|printsubcycle
parameter_list|(
name|cltype
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|readsamples
parameter_list|(
name|FILE
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|unsigned
name|long
name|reladdr
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|sortchildren
parameter_list|(
name|nltype
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|sortmembers
parameter_list|(
name|nltype
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|sortparents
parameter_list|(
name|nltype
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|tally
parameter_list|(
name|struct
name|rawarc
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|timepropagate
parameter_list|(
name|nltype
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|totalcmp
parameter_list|()
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|LESSTHAN
value|-1
end_define

begin_define
define|#
directive|define
name|EQUALTO
value|0
end_define

begin_define
define|#
directive|define
name|GREATERTHAN
value|1
end_define

begin_define
define|#
directive|define
name|DFNDEBUG
value|1
end_define

begin_define
define|#
directive|define
name|CYCLEDEBUG
value|2
end_define

begin_define
define|#
directive|define
name|ARCDEBUG
value|4
end_define

begin_define
define|#
directive|define
name|TALLYDEBUG
value|8
end_define

begin_define
define|#
directive|define
name|TIMEDEBUG
value|16
end_define

begin_define
define|#
directive|define
name|SAMPLEDEBUG
value|32
end_define

begin_define
define|#
directive|define
name|AOUTDEBUG
value|64
end_define

begin_define
define|#
directive|define
name|CALLDEBUG
value|128
end_define

begin_define
define|#
directive|define
name|LOOKUPDEBUG
value|256
end_define

begin_define
define|#
directive|define
name|PROPDEBUG
value|512
end_define

begin_define
define|#
directive|define
name|BREAKCYCLE
value|1024
end_define

begin_define
define|#
directive|define
name|SUBCYCLELIST
value|2048
end_define

begin_define
define|#
directive|define
name|ANYDEBUG
value|4096
end_define

end_unit

