begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * config.h	1.5	81/05/22  * Definitions that everybody needs to know  */
end_comment

begin_define
define|#
directive|define
name|eq
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|(strcmp(a,b) == 0)
end_define

begin_define
define|#
directive|define
name|TRUE
value|1
end_define

begin_define
define|#
directive|define
name|FALSE
value|0
end_define

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
name|TO_NEXUS
value|-1
end_define

begin_struct
struct|struct
name|file_list
block|{
name|char
modifier|*
name|f_fn
decl_stmt|;
name|int
name|f_type
decl_stmt|;
name|char
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

begin_typedef
typedef|typedef
name|char
name|bool
typedef|;
end_typedef

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
comment|/* What it is connected to */
name|char
modifier|*
name|d_name
decl_stmt|;
comment|/* Name of device (e.g. rk11) */
name|struct
name|idlist
modifier|*
name|d_vec
decl_stmt|;
comment|/* Interrupt vectors */
name|int
name|d_addr
decl_stmt|;
comment|/* Address of csr */
name|int
name|d_unit
decl_stmt|;
comment|/* Unit number */
name|int
name|d_drive
decl_stmt|;
comment|/* Drive number */
name|int
name|d_slave
decl_stmt|;
comment|/* Slave number */
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
name|bool
name|d_dk
decl_stmt|;
comment|/* if init 1 set to number for iostat */
name|int
name|d_flags
decl_stmt|;
comment|/* Flags for device init */
name|struct
name|device
modifier|*
name|d_next
decl_stmt|;
comment|/* Next one in list */
block|}
struct|;
end_struct

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

begin_struct
struct|struct
name|opt
block|{
name|char
modifier|*
name|op_name
decl_stmt|;
name|struct
name|cputype
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
decl_stmt|,
modifier|*
name|ns
argument_list|()
decl_stmt|,
modifier|*
name|malloc
argument_list|()
decl_stmt|,
modifier|*
name|tc
argument_list|()
decl_stmt|,
modifier|*
name|qu
argument_list|()
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|bool
name|do_trace
decl_stmt|,
name|seen_mba
decl_stmt|,
name|seen_uba
decl_stmt|;
end_decl_stmt

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
name|hz
decl_stmt|,
name|timezone
decl_stmt|,
name|hadtz
decl_stmt|,
name|maxusers
decl_stmt|,
name|dst
decl_stmt|;
end_decl_stmt

end_unit

