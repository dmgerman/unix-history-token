begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* **  CTLMOD.H -- control module header file ** **	This header file defines all the internal data structures **	used by the control module. ** **	If something other than the control module or the initializer **	has to include this, something is wrong! ** **	Compilation Flags: **		xCM_DEBUG -- if set, certain code is compiled in that **			does consistancy checks on the data structures **			at opportune times. **		xMONITOR -- if set, turns on performance evaluation **			code. **		xCTR1, xCTR2, xCTR3 -- if set, turns on various levels **			of trace information.  These must be properly **			nested; if xCTR2 is set, xCTR1 *MUST* be set. ** **	Version: **		@(#)ctlmod.h	7.1	2/5/81 */
end_comment

begin_comment
comment|/* include some other files */
end_comment

begin_include
include|#
directive|include
file|"state.h"
end_include

begin_include
include|#
directive|include
file|"proc.h"
end_include

begin_include
include|#
directive|include
file|<pv.h>
end_include

begin_include
include|#
directive|include
file|"pipes.h"
end_include

begin_include
include|#
directive|include
file|<func.h>
end_include

begin_include
include|#
directive|include
file|<pmon.h>
end_include

begin_include
include|#
directive|include
file|<setjmp.h>
end_include

begin_comment
comment|/* basic constants */
end_comment

begin_include
include|#
directive|include
file|<useful.h>
end_include

begin_comment
comment|/* **  Trace Flag settings. */
end_comment

begin_include
include|#
directive|include
file|<trace.h>
end_include

begin_define
define|#
directive|define
name|xCTR1
value|1
end_define

begin_define
define|#
directive|define
name|xCTR2
value|1
end_define

begin_define
define|#
directive|define
name|xCTR3
value|1
end_define

begin_define
define|#
directive|define
name|xCM_DEBUG
value|1
end_define

begin_define
define|#
directive|define
name|xMONITOR
value|1
end_define

begin_comment
comment|/* **  STRUCT CM -- the configuration structure. */
end_comment

begin_struct
struct|struct
name|_cm_t
block|{
name|char
name|cm_myname
index|[
literal|12
index|]
decl_stmt|;
comment|/* my process name */
name|state_t
name|cm_state
index|[
name|CM_MAXST
index|]
decl_stmt|;
comment|/* the state descriptions */
name|proc_t
name|cm_proc
index|[
name|CM_MAXPROC
index|]
decl_stmt|;
comment|/* the process descriptions */
name|int
name|cm_myproc
decl_stmt|;
comment|/* my process id */
name|char
name|cm_input
decl_stmt|;
comment|/* the current input file */
name|char
name|cm_rinput
decl_stmt|;
comment|/* the reset input file */
block|}
struct|;
end_struct

begin_comment
comment|/* **  STRUCT CTX -- the context structure. ** **	There is one of these around for every currently known **	context.  There is a pipe block associated with the **	context, defined in call() or main(); only a pointer **	is kept here so that the pipe block can be more efficiently **	allocated off the stack. ** **	Some of the fields describe the NEXT block in the sequence. **	These are: ctx_size, ctx_link. ** **	Ctx_cmark is useful ONLY when this block is not currently **	active. ** **	Ctx_qt should be of type 'struct qthdr *'; it is 'char *' to **	avoid including qtree.h.  It points to the saved query **	tree header after the first qt is read in. ** **	Ctx_pv MUST be last. */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_ctx_t
block|{
name|char
modifier|*
name|ctx_name
decl_stmt|;
comment|/* the printname of this proc */
name|pb_t
modifier|*
name|ctx_ppb
decl_stmt|;
comment|/* the pb associated w/ this ctx */
name|short
modifier|*
name|ctx_tvect
decl_stmt|;
comment|/* the trace vect for this ctx */
name|int
function_decl|(
modifier|*
name|ctx_errfn
function_decl|)
parameter_list|()
function_decl|;
comment|/* the error handling function */
name|char
modifier|*
name|ctx_qt
decl_stmt|;
comment|/* pointer to saved Qt struct */
name|struct
name|fn_def
modifier|*
name|ctx_fn
decl_stmt|;
comment|/* pointer to fn descriptor */
name|char
modifier|*
name|ctx_glob
decl_stmt|;
comment|/* ptr to saved global area */
name|struct
name|_ctx_t
modifier|*
name|ctx_link
decl_stmt|;
comment|/* a link to the next ctx */
name|struct
name|monitor
modifier|*
name|ctx_mon
decl_stmt|;
comment|/* ptr to monitor struct */
name|short
name|ctx_size
decl_stmt|;
comment|/* the size of the next ctx */
name|bool
name|ctx_init
decl_stmt|;
comment|/* set if between initp& call */
name|bool
name|ctx_new
decl_stmt|;
comment|/* set if this is a new context */
name|char
name|ctx_resp
decl_stmt|;
comment|/* process to respond to */
name|int
name|ctx_cmark
decl_stmt|;
comment|/* the Qbuf context mark */
name|int
name|ctx_pmark
decl_stmt|;
comment|/* the Qbuf parameter mark */
name|jmp_buf
name|ctx_jbuf
decl_stmt|;
comment|/* longjmp point on fatal error */
name|long
name|ctx_ofiles
decl_stmt|;
comment|/* files that should be kept open */
name|int
name|ctx_pc
decl_stmt|;
comment|/* the parm count */
name|PARM
name|ctx_pv
index|[
name|PV_MAXPC
operator|+
literal|1
index|]
decl_stmt|;
comment|/* the parm vector */
block|}
name|ctx_t
typedef|;
end_typedef

begin_decl_stmt
specifier|extern
name|ctx_t
name|Ctx
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* the current context */
end_comment

begin_decl_stmt
specifier|extern
name|char
name|Qbuf
index|[]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* the free space buffer */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|QbufSize
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* the size of Qbuf */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|_cm_t
name|Cm
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* the system configuration */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|Syncs
index|[
name|CM_MAXPROC
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* the number of SYNCs expected */
end_comment

begin_comment
comment|/* **  ERROR NUMBERS */
end_comment

begin_define
define|#
directive|define
name|ERR_QBUF
value|100
end_define

begin_comment
comment|/* Qbuf overflow */
end_comment

end_unit

