begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* **  IIGLOBALS.H -- Equel run-time library globals ** **	In this file are defined the global variables, **	and manifest constants used in the Equel run-time **	routines. All globals must start with "II". ** **	Version: **		@(#)IIglobals.h	7.2	10/27/81 */
end_comment

begin_include
include|#
directive|include
file|<pipes.h>
end_include

begin_include
include|#
directive|include
file|<proc.h>
end_include

begin_include
include|#
directive|include
file|<resp.h>
end_include

begin_include
include|#
directive|include
file|<pv.h>
end_include

begin_define
define|#
directive|define
name|opSHORT
value|1
end_define

begin_define
define|#
directive|define
name|opFLOAT
value|2
end_define

begin_define
define|#
directive|define
name|opSTRING
value|3
end_define

begin_define
define|#
directive|define
name|opDOUBLE
value|4
end_define

begin_define
define|#
directive|define
name|opCHAR
value|5
end_define

begin_define
define|#
directive|define
name|opLONG
value|6
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|PDP
end_ifdef

begin_define
define|#
directive|define
name|opINT
value|opSHORT
end_define

begin_else
else|#
directive|else
else|PDP
end_else

begin_define
define|#
directive|define
name|opINT
value|opLONG
end_define

begin_endif
endif|#
directive|endif
endif|PDP
end_endif

begin_define
define|#
directive|define
name|EQUEL
value|'&'
end_define

begin_define
define|#
directive|define
name|ERRDELIM
value|'~'
end_define

begin_decl_stmt
name|struct
name|resp
name|IIresp
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* response structure */
end_comment

begin_decl_stmt
name|char
modifier|*
name|IIproc_name
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* file name */
end_comment

begin_decl_stmt
name|int
name|IIline_no
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* line no */
end_comment

begin_decl_stmt
name|int
name|IIdebug
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* debug flag */
end_comment

begin_decl_stmt
name|int
name|IIingpid
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* process id of ingres */
end_comment

begin_decl_stmt
name|char
modifier|*
name|IIoptn
index|[
literal|9
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* ingres options */
end_comment

begin_decl_stmt
name|int
name|IIin_retrieve
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* set if inside a retrieve */
end_comment

begin_decl_stmt
name|int
name|IIndomains
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* number of doamins in this retrieve */
end_comment

begin_decl_stmt
name|int
name|IIdomains
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|IInxtdomain
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* index into source field of buffer */
end_comment

begin_decl_stmt
name|long
name|IItupcnt
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* # tuples which satified last  					 * update query  					 */
end_comment

begin_decl_stmt
name|int
name|IInewqry
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* set to indicate that IIwrites have 					 * already set buffers  					 */
end_comment

begin_decl_stmt
name|int
name|IIw_down
decl_stmt|,
name|IIr_down
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* pipe descriptors for  					 * parser communcation  					 */
end_comment

begin_decl_stmt
name|int
name|IIerrflag
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* error flag.  					 * Set in IIerror, cleared in IIsync  					 */
end_comment

begin_decl_stmt
specifier|extern
name|char
name|IIPathname
index|[]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* initialized by  					 * IIgetpath() [IIingres.c]  					 */
end_comment

begin_function_decl
name|int
function_decl|(
modifier|*
name|IIprint_err
function_decl|)
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* wether or not error messgs should 					 * be printed 					 */
end_comment

begin_function_decl
name|int
name|IIret_err
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* returns its integer arg for  					 * (*IIprint_err)() 					 */
end_comment

begin_function_decl
name|int
name|IIno_err
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* returns 0 for (*IIprint_err)() */
end_comment

begin_function_decl
name|int
function_decl|(
modifier|*
name|IIo_print
function_decl|)
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* a one value stack for  					 * temporarily turned off printing of 					 * errors. Done in [IIw_left.c&  					 * IIw_right.c]. 					 */
end_comment

begin_decl_stmt
name|char
modifier|*
name|IImainpr
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* "/usr/bin/ingres.c" usually,  					 * [ingres.c] 					 */
end_comment

begin_decl_stmt
name|int
name|IISyncs
index|[]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Interrupt expectance vector */
end_comment

begin_comment
comment|/* buffer structure of get(III) */
end_comment

begin_struct
struct|struct
name|iob
block|{
name|int
name|fildes
decl_stmt|;
name|int
name|nleft
decl_stmt|;
name|char
modifier|*
name|nextp
decl_stmt|;
name|char
name|buff
index|[
literal|512
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|retsym
block|{
name|char
name|type
decl_stmt|;
name|char
name|len
decl_stmt|;
name|char
modifier|*
name|addr
decl_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
name|struct
name|retsym
name|IIretsym
index|[
name|MAXDOM
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* retrieve table */
end_comment

begin_decl_stmt
name|struct
name|retsym
name|IIr_sym
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* type, length fields used 					 * by new equel in IIn_ret and IIn_get 					 */
end_comment

begin_decl_stmt
name|int
name|IIinput
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* File descriptor from which current input is read, 			 * is either IIr_down, or IIr_front 			 */
end_comment

begin_decl_stmt
name|pb_t
name|IIpb
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* the data pipe buffer */
end_comment

end_unit

