begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	config.h	1.10	82/10/25	*/
end_comment

begin_comment
comment|/*  * Config.  */
end_comment

begin_struct
struct|struct
name|file_list
block|{
name|char
modifier|*
name|f_fn
decl_stmt|;
comment|/* the name */
name|int
name|f_type
decl_stmt|;
comment|/* see below */
name|struct
name|file_list
modifier|*
name|f_next
decl_stmt|;
name|char
modifier|*
name|f_needs
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|DRIVER
value|1
end_define

begin_define
define|#
directive|define
name|NORMAL
value|2
end_define

begin_define
define|#
directive|define
name|INVISIBLE
value|3
end_define

begin_define
define|#
directive|define
name|PROFILING
value|4
end_define

begin_struct
struct|struct
name|idlst
block|{
name|char
modifier|*
name|id
decl_stmt|;
name|struct
name|idlst
modifier|*
name|id_next
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|device
block|{
name|int
name|d_type
decl_stmt|;
comment|/* CONTROLLER, DEVICE, UBA or MBA */
name|struct
name|device
modifier|*
name|d_conn
decl_stmt|;
comment|/* what it is connected to */
name|char
modifier|*
name|d_name
decl_stmt|;
comment|/* name of device (e.g. rk11) */
name|struct
name|idlst
modifier|*
name|d_vec
decl_stmt|;
comment|/* interrupt vectors */
name|int
name|d_pri
decl_stmt|;
comment|/* interrupt priority */
name|int
name|d_addr
decl_stmt|;
comment|/* address of csr */
name|int
name|d_unit
decl_stmt|;
comment|/* unit number */
name|int
name|d_drive
decl_stmt|;
comment|/* drive number */
name|int
name|d_slave
decl_stmt|;
comment|/* slave number */
define|#
directive|define
name|QUES
value|-1
comment|/* -1 means '?' */
define|#
directive|define
name|UNKNOWN
value|-2
comment|/* -2 means not set yet */
name|int
name|d_dk
decl_stmt|;
comment|/* if init 1 set to number for iostat */
name|int
name|d_flags
decl_stmt|;
comment|/* nlags for device init */
name|struct
name|device
modifier|*
name|d_next
decl_stmt|;
comment|/* Next one in list */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|TO_NEXUS
value|(struct device *)-1
end_define

begin_struct
struct|struct
name|config
block|{
name|char
modifier|*
name|c_dev
decl_stmt|;
name|char
modifier|*
name|s_sysname
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * Config has a global notion of which machine type is  * being used.  It uses the name of the machine in choosing  * files and directories.  Thus if the name of the machine is ``vax'',  * it will build from ``makefile.vax'' and use ``../vax/asm.sed''  * in the makerules, etc.  */
end_comment

begin_decl_stmt
name|int
name|machine
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|machinename
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|MACHINE_VAX
value|1
end_define

begin_define
define|#
directive|define
name|MACHINE_SUN
value|2
end_define

begin_comment
comment|/*  * For each machine, a set of CPU's may be specified as supported.  * These and the options (below) are put in the C flags in the makefile.  */
end_comment

begin_struct
struct|struct
name|cputype
block|{
name|char
modifier|*
name|cpu_name
decl_stmt|;
name|struct
name|cputype
modifier|*
name|cpu_next
decl_stmt|;
block|}
modifier|*
name|cputype
struct|;
end_struct

begin_comment
comment|/*  * A set of options may also be specified which are like CPU types,  * but which may also specify values for the options.  */
end_comment

begin_struct
struct|struct
name|opt
block|{
name|char
modifier|*
name|op_name
decl_stmt|;
name|char
modifier|*
name|op_value
decl_stmt|;
name|struct
name|opt
modifier|*
name|op_next
decl_stmt|;
block|}
modifier|*
name|opt
struct|;
end_struct

begin_decl_stmt
name|char
modifier|*
name|ident
decl_stmt|;
end_decl_stmt

begin_function_decl
name|char
modifier|*
name|ns
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|tc
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|qu
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|get_word
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|path
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|raise
parameter_list|()
function_decl|;
end_function_decl

begin_decl_stmt
name|int
name|do_trace
decl_stmt|;
end_decl_stmt

begin_function_decl
name|char
modifier|*
name|index
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|rindex
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|malloc
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|strcpy
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|strcat
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|sprintf
parameter_list|()
function_decl|;
end_function_decl

begin_if
if|#
directive|if
name|MACHINE_VAX
end_if

begin_decl_stmt
name|int
name|seen_mba
decl_stmt|,
name|seen_uba
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_function_decl
name|struct
name|device
modifier|*
name|connect
parameter_list|()
function_decl|;
end_function_decl

begin_decl_stmt
name|struct
name|device
modifier|*
name|dtab
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
name|errbuf
index|[
literal|80
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|yyline
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|file_list
modifier|*
name|ftab
decl_stmt|,
modifier|*
name|conf_list
decl_stmt|,
modifier|*
name|confp
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|PREFIX
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|timezone
decl_stmt|,
name|hadtz
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|dst
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|profiling
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|maxusers
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|eq
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|(!strcmp(a,b))
end_define

end_unit

