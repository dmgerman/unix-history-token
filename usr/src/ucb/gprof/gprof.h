begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1983 Regents of the University of California.  * All rights reserved.  *  * Redistribution and use in source and binary forms are permitted  * provided that the above copyright notice and this paragraph are  * duplicated in all such forms and that any documentation,  * advertising materials, and other materials related to such  * distribution and use acknowledge that the software was developed  * by the University of California, Berkeley.  The name of the  * University may not be used to endorse or promote products derived  * from this software without specific prior written permission.  * THIS SOFTWARE IS PROVIDED ``AS IS'' AND WITHOUT ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, WITHOUT LIMITATION, THE IMPLIED  * WARRANTIES OF MERCHANTIBILITY AND FITNESS FOR A PARTICULAR PURPOSE.  *  *	@(#)gprof.h	5.6 (Berkeley) 6/29/88  */
end_comment

begin_include
include|#
directive|include
file|<stdio.h>
end_include

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
file|<a.out.h>
end_include

begin_include
include|#
directive|include
file|"gcrt0.h"
end_include

begin_if
if|#
directive|if
name|vax
end_if

begin_include
include|#
directive|include
file|"vax.h"
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|sun
end_if

begin_include
include|#
directive|include
file|"sun.h"
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|tahoe
end_if

begin_include
include|#
directive|include
file|"tahoe.h"
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*      *	who am i, for error messages.      */
end_comment

begin_decl_stmt
name|char
modifier|*
name|whoami
decl_stmt|;
end_decl_stmt

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
comment|/*      *	ticks per second      */
end_comment

begin_decl_stmt
name|long
name|hz
decl_stmt|;
end_decl_stmt

begin_typedef
typedef|typedef
name|u_short
name|UNIT
typedef|;
end_typedef

begin_comment
comment|/* unit of profiling */
end_comment

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
name|GMONNAME
value|"gmon.out"
end_define

begin_define
define|#
directive|define
name|GMONSUM
value|"gmon.sum"
end_define

begin_comment
comment|/*      *	blurbs on the flat and graph profiles.      */
end_comment

begin_define
define|#
directive|define
name|FLAT_BLURB
value|"/usr/lib/gprof.flat"
end_define

begin_define
define|#
directive|define
name|CALLG_BLURB
value|"/usr/lib/gprof.callg"
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
comment|/* how calls from parent to child */
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
comment|/*      * The symbol table;      * for each external in the specified file we gather      * its address, the number of calls and compute its share of cpu time.      */
end_comment

begin_struct
struct|struct
name|nl
block|{
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
name|bool
name|printflag
decl_stmt|;
comment|/* should this be printed? */
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
comment|/*       *	namelist entries for cycle headers.      *	the number of discovered cycles.      */
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
comment|/*      * The header on the gmon.out file.      * gmon.out consists of one of these headers,      * and then an array of ncnt samples      * representing the discretized program counter values.      *	this should be a struct phdr, but since everything is done      *	as UNITs, this is in UNITs too.      */
end_comment

begin_struct
struct|struct
name|hdr
block|{
name|UNIT
modifier|*
name|lowpc
decl_stmt|;
name|UNIT
modifier|*
name|highpc
decl_stmt|;
name|int
name|ncnt
decl_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
name|struct
name|hdr
name|h
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|debug
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*      * Each discretized pc sample has      * a count of the number of samples in its range      */
end_comment

begin_decl_stmt
name|UNIT
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
name|lowpc
decl_stmt|,
name|highpc
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* range profiled, in UNIT's */
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
name|char
modifier|*
name|strtab
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* string table in core */
end_comment

begin_decl_stmt
name|off_t
name|ssiz
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* size of the string table */
end_comment

begin_decl_stmt
name|struct
name|exec
name|xbuf
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* exec header of a.out */
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
name|sflag
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* sum multiple gmon.out files */
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

begin_comment
comment|/* 		addarc(); */
end_comment

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

begin_comment
comment|/* 		asgnsamples(); 		printblurb(); 		cyclelink(); 		dfn(); */
end_comment

begin_function_decl
name|bool
name|dfn_busy
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* 		dfn_findcycle(); */
end_comment

begin_function_decl
name|bool
name|dfn_numbered
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* 		dfn_post_visit(); 		dfn_pre_visit(); 		dfn_self_cycle(); */
end_comment

begin_function_decl
name|nltype
modifier|*
modifier|*
name|doarcs
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* 		done(); 		findcalls(); 		flatprofheader(); 		flatprofline(); */
end_comment

begin_function_decl
name|bool
name|funcsymbol
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* 		getnfile(); 		getpfile(); 		getstrtab(); 		getsymtab(); 		gettextspace(); 		gprofheader(); 		gprofline(); 		main(); */
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

begin_comment
comment|/* 		printchildren(); 		printcycle(); 		printgprof(); 		printmembers(); 		printname(); 		printparents(); 		printprof(); 		readsamples(); */
end_comment

begin_function_decl
name|unsigned
name|long
name|reladdr
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* 		sortchildren(); 		sortmembers(); 		sortparents(); 		tally(); 		timecmp(); 		topcmp(); */
end_comment

begin_function_decl
name|int
name|totalcmp
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* 		valcmp(); */
end_comment

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
name|ANYDEBUG
value|1024
end_define

end_unit

