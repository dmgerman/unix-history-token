begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Symmetry running either dynix 3.1 (bsd) or ptx (sysv).  */
end_comment

begin_define
define|#
directive|define
name|NBPG
value|4096
end_define

begin_define
define|#
directive|define
name|UPAGES
value|1
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|_SEQUENT_
end_ifdef

begin_comment
comment|/* ptx */
end_comment

begin_define
define|#
directive|define
name|HOST_TEXT_START_ADDR
value|0
end_define

begin_define
define|#
directive|define
name|HOST_STACK_END_ADDR
value|0x3fffe000
end_define

begin_define
define|#
directive|define
name|TRAD_CORE_USER_OFFSET
value|((UPAGES * NBPG) - sizeof (struct user))
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* dynix */
end_comment

begin_define
define|#
directive|define
name|HOST_TEXT_START_ADDR
value|0x1000
end_define

begin_define
define|#
directive|define
name|HOST_DATA_START_ADDR
value|(NBPG * u.u_tsize)
end_define

begin_define
define|#
directive|define
name|HOST_STACK_END_ADDR
value|0x3ffff000
end_define

begin_define
define|#
directive|define
name|TRAD_UNIX_CORE_FILE_FAILING_SIGNAL
parameter_list|(
name|core_bfd
parameter_list|)
define|\
value|((core_bfd)->tdata.trad_core_data->u.u_arg[0])
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|TRAD_CORE_DSIZE_INCLUDES_TSIZE
end_define

end_unit

