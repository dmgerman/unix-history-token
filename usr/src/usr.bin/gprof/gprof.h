begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* sccsid:  @(#)gprof.h	1.4 (Berkeley) %G% */
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
file|<pagsiz.h>
end_include

begin_include
include|#
directive|include
file|"monitor.h"
end_include

begin_comment
comment|/*      *	ticks per second      */
end_comment

begin_define
define|#
directive|define
name|HZ
value|60
end_define

begin_typedef
typedef|typedef
name|short
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
comment|/*      *	a raw arc,      *	    with pointers to the calling site and the called site      *	    and a count.      */
end_comment

begin_struct
struct|struct
name|rawarc
block|{
name|unsigned
name|long
name|raw_frompc
decl_stmt|;
name|unsigned
name|long
name|raw_selfpc
decl_stmt|;
name|long
name|raw_count
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * The symbol table;  * for each external in the specified file we gather  * its address, the number of calls and compute its share of cpu time.  */
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
comment|/*      *	flag which marks a nl entry as topologically ``busy''      */
end_comment

begin_define
define|#
directive|define
name|DFN_BUSY
value|-1
end_define

begin_comment
comment|/*       *	the number of cycles is estimated as this fraction of nnames      *	ncycles, the number of allocated cycle namelist entries,      *	not to be confused with cyclemax, the number of discovered cycles.      */
end_comment

begin_define
define|#
directive|define
name|CYCLEFRACTION
value|( 0.10 )
end_define

begin_decl_stmt
name|int
name|ncycles
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* maximum allocated cycle headers */
end_comment

begin_decl_stmt
name|int
name|cyclemax
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* number of cycles discovered */
end_comment

begin_comment
comment|/*  * The header on the gmon.out file.  * gmon.out consists of one of these headers,  * and then an array of ncnt samples  * representing the discretized program counter values.  *	this should be a struct phdr, but since everything is done  *	as UNITs, this is in UNITs too.  */
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
comment|/*  * Each discretized pc sample has  * a count of the number of samples in its range  */
end_comment

begin_decl_stmt
name|unsigned
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

begin_decl_stmt
name|int
name|zflg
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|cflag
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

begin_function_decl
name|int
name|timecmp
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|valcmp
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|totalcmp
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
name|arctype
modifier|*
name|arclookup
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|bool
name|dfn_busy
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
name|CALLSDEBUG
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
name|ANYDEBUG
value|512
end_define

end_unit

