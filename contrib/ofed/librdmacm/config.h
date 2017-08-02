begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $FreeBSD$ */
end_comment

begin_define
define|#
directive|define
name|min
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|((a)> (b) ? (b) : (a))
end_define

begin_define
define|#
directive|define
name|VALGRIND_MAKE_MEM_DEFINED
parameter_list|(
modifier|...
parameter_list|)
value|0
end_define

begin_define
define|#
directive|define
name|s6_addr32
value|__u6_addr.__u6_addr32
end_define

begin_define
define|#
directive|define
name|STREAM_CLOEXEC
value|"e"
end_define

begin_define
define|#
directive|define
name|ENODATA
value|ECONNREFUSED
end_define

begin_define
define|#
directive|define
name|IBACM_PORT_FILE
value|"/var/run/ibacm.port"
end_define

end_unit

